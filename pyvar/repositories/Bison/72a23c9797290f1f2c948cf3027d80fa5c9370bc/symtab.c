@@ -1,5 +1,5 @@
 /* Symbol table manager for Bison,
-   Copyright 1984, 1989, 2000, 2001, 2002 Free Software Foundation, Inc.
+   Copyright (C) 1984, 1989, 2000, 2001, 2002 Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -20,39 +20,19 @@
 
 
 #include "system.h"
+#include "hash.h"
 #include "symtab.h"
 #include "gram.h"
 
-
-bucket *firstsymbol;
-static bucket *lastsymbol;
-static bucket **symtab;
-
-static int
-hash (const char *key)
-{
-  const char *cp;
-  int k;
-
-  cp = key;
-  k = 0;
-  while (*cp)
-    k = ((k << 1) ^ (*cp++)) & 0x3fff;
-
-  return k % TABSIZE;
-}
-
-/*--------------------------------------------------------------.
-| Create a new symbol, named TAG, which hash value is HASHVAL.  |
-`--------------------------------------------------------------*/
+/*---------------------------------.
+| Create a new symbol, named TAG.  |
+`---------------------------------*/
 
 static bucket *
-bucket_new (const char *tag, int hashval)
+bucket_new (const char *tag)
 {
   bucket *res = XMALLOC (bucket, 1);
 
-  res->link = symtab[hashval];
-  res->next = NULL;
   res->tag = xstrdup (tag);
   res->type_name = NULL;
   res->number = -1;
@@ -62,19 +42,67 @@ bucket_new (const char *tag, int hashval)
   res->alias = NULL;
   res->class = unknown_sym;
 
+  if (getenv ("DEBUG"))
+    fprintf (stderr, "Creating: nsyms = %d, ntokens = %d: %s\n",
+	     nsyms, ntokens, tag);
   nsyms++;
 
   return res;
 }
 
 
-void
-tabinit (void)
+/*------------.
+| Free THIS.  |
+`------------*/
+
+static void
+bucket_free (bucket *this)
 {
-  symtab = XCALLOC (bucket *, TABSIZE);
+#if 0
+  /* This causes crashes because one string can appear more
+     than once.  */
+  XFREE (this->type_name);
+#endif
+  XFREE (this->tag);
+  XFREE (this);
+}
+
+
+
+/*----------------------.
+| A bucket hash table.  |
+`----------------------*/
 
-  firstsymbol = NULL;
-  lastsymbol = NULL;
+/* Initial capacity of buckets hash table.  */
+#define HT_INITIAL_CAPACITY 257
+
+static struct hash_table *bucket_table = NULL;
+
+static bool
+hash_compare_bucket (const bucket *m1, const bucket *m2)
+{
+  return strcmp (m1->tag, m2->tag) ? FALSE : TRUE;
+}
+
+static unsigned int
+hash_bucket (const bucket *m, unsigned int tablesize)
+{
+  return hash_string (m->tag, tablesize);
+}
+
+
+/*-------------------------------.
+| Create the bucket hash table.  |
+`-------------------------------*/
+
+void
+buckets_new (void)
+{
+  bucket_table = hash_initialize (HT_INITIAL_CAPACITY,
+				  NULL,
+				  (Hash_hasher) hash_bucket,
+				  (Hash_comparator) hash_compare_bucket,
+				  (Hash_data_freer) bucket_free);
 }
 
 
@@ -86,66 +114,42 @@ tabinit (void)
 bucket *
 getsym (const char *key)
 {
-  int hashval;
-  bucket *bp;
-  int found;
+  bucket probe;
+  bucket *entry;
 
-  hashval = hash (key);
-  bp = symtab[hashval];
+  (const char *) probe.tag = key;
+  entry = hash_lookup (bucket_table, &probe);
 
-  found = 0;
-  while (bp != NULL && found == 0)
+  if (!entry)
     {
-      if (strcmp (key, bp->tag) == 0)
-	found = 1;
-      else
-	bp = bp->link;
+      /* First insertion in the hash. */
+      entry = bucket_new (key);
+      hash_insert (bucket_table, entry);
     }
+  return entry;
+}
 
-  if (found == 0)
-    {
-      bp = bucket_new (key, hashval);
-
-      if (firstsymbol == NULL)
-	{
-	  firstsymbol = bp;
-	  lastsymbol = bp;
-	}
-      else
-	{
-	  lastsymbol->next = bp;
-	  lastsymbol = bp;
-	}
-
-      symtab[hashval] = bp;
-    }
 
-  return bp;
+/*-------------------.
+| Free the buckets.  |
+`-------------------*/
+
+void
+buckets_free (void)
+{
+  hash_free (bucket_table);
 }
 
 
+/*---------------------------------------------------------------.
+| Look for undefined buckets, report an error, and consider them |
+| terminals.                                                     |
+`---------------------------------------------------------------*/
+
 void
-free_symtab (void)
+buckets_do (bucket_processor processor, void *processor_data)
 {
-  int i;
-  bucket *bp, *bptmp;		/* JF don't use ptr after free */
-
-  for (i = 0; i < TABSIZE; i++)
-    {
-      bp = symtab[i];
-      while (bp)
-	{
-	  bptmp = bp->link;
-#if 0
-	  /* This causes crashes because one string can appear more
-	     than once.  */
-	  if (bp->type_name)
-	    XFREE (bp->type_name);
-#endif
-	  XFREE (bp->tag);
-	  XFREE (bp);
-	  bp = bptmp;
-	}
-    }
-  XFREE (symtab);
+  hash_do_for_each (bucket_table,
+		    (Hash_processor) processor,
+		    processor_data);
 }
