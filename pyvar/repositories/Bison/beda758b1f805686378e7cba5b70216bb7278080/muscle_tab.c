@@ -1,5 +1,5 @@
 /* Macro table manager for Bison,
-   Copyright 2001 Free Software Foundation, Inc.
+   Copyright (C) 2001, 2002 Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -24,31 +24,31 @@
 #include "muscle_tab.h"
 #include "getargs.h"
 
-struct hash_table muscle_table;
+/* Initial capacity of muscles hash table.  */
+#define HT_INITIAL_CAPACITY 257
 
-static unsigned long
-mhash1 (const void *item)
-{
-  return_STRING_HASH_1 (((const muscle_entry_t *) item)->key);
-}
+struct hash_table *muscle_table = NULL;
 
-static unsigned long
-mhash2 (const void *item)
+static bool
+hash_compare_muscles (void const *x, void const *y)
 {
-  return_STRING_HASH_2 (((const muscle_entry_t *) item)->key);
+  const muscle_entry_t *m1 = x;
+  const muscle_entry_t *m2 = y;
+  return strcmp (m1->key, m2->key) ? FALSE : TRUE;
 }
 
-static int
-mcmp (const void *x, const void *y)
+static unsigned int
+hash_muscle (const void *x, unsigned int tablesize)
 {
-  return strcmp (((const muscle_entry_t*) x)->key,
-		 ((const muscle_entry_t *) y)->key);
+  const muscle_entry_t *m = x;
+  return hash_string (m->key, tablesize);
 }
 
 void
 muscle_init (void)
 {
-  hash_init (&muscle_table, MTABSIZE, &mhash1, &mhash2, &mcmp);
+  muscle_table = hash_initialize (HT_INITIAL_CAPACITY, NULL, hash_muscle,
+				  hash_compare_muscles, NULL);
 
   /* Version and input file.  */
   muscle_insert ("version", VERSION);
@@ -72,16 +72,23 @@ muscle_init (void)
 void
 muscle_insert (const char *key, const char *value)
 {
-  muscle_entry_t *pair = XMALLOC (muscle_entry_t, 1);
-  pair->key = key;
-  pair->value = value;
-  hash_insert (&muscle_table, pair);
+  muscle_entry_t pair = { key, NULL };
+  muscle_entry_t *entry = hash_lookup (muscle_table, &pair);
+
+  if (!entry)
+    {
+      /* First insertion in the hash. */
+      entry = XMALLOC (muscle_entry_t, 1);
+      entry->key = key;
+      hash_insert (muscle_table, entry);
+    }
+  entry->value = value;
 }
 
 const char*
 muscle_find (const char *key)
 {
-  muscle_entry_t pair = { key, 0 };
-  muscle_entry_t *result = hash_find_item (&muscle_table, &pair);
-  return result ? result->value : 0;
+  muscle_entry_t pair = { key, NULL };
+  muscle_entry_t *result = hash_lookup (muscle_table, &pair);
+  return result ? result->value : NULL;
 }
