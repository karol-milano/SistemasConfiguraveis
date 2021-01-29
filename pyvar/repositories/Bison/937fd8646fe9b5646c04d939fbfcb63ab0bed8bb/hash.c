@@ -1,5 +1,5 @@
 /* hash - hashing table processing.
-   Copyright (C) 1998, 1999, 2000, 2001 Free Software Foundation, Inc.
+   Copyright (C) 1998, 1999, 2000, 2001, 2002 Free Software Foundation, Inc.
    Written by Jim Meyering, 1992.
 
    This program is free software; you can redistribute it and/or modify
@@ -33,7 +33,6 @@
 typedef enum {false = 0, true = 1} bool;
 #endif
 #include <stdio.h>
-#include <assert.h>
 
 #ifndef HAVE_DECL_FREE
 "this configure-time declaration test was not run"
@@ -263,7 +262,8 @@ hash_lookup (const Hash_table *table, const void *entry)
     = table->bucket + table->hasher (entry, table->n_buckets);
   struct hash_entry *cursor;
 
-  assert (bucket < table->bucket_limit);
+  if (table->bucket_limit <= bucket)
+    abort ();
 
   if (bucket->data == NULL)
     return NULL;
@@ -292,12 +292,11 @@ hash_get_first (const Hash_table *table)
   if (table->n_entries == 0)
     return NULL;
 
-  for (bucket = table->bucket; bucket < table->bucket_limit; bucket++)
-    if (bucket->data)
+  for (bucket = table->bucket; ; bucket++)
+    if (table->bucket_limit <= bucket)
+      abort ();
+    else if (bucket->data)
       return bucket->data;
-
-  assert (0);
-  return NULL;
 }
 
 /* Return the user data for the entry following ENTRY, where ENTRY has been
@@ -311,7 +310,8 @@ hash_get_next (const Hash_table *table, const void *entry)
     = table->bucket + table->hasher (entry, table->n_buckets);
   struct hash_entry *cursor;
 
-  assert (bucket < table->bucket_limit);
+  if (table->bucket_limit <= bucket)
+    abort ();
 
   /* Find next entry in the same bucket.  */
   for (cursor = bucket; cursor; cursor = cursor->next)
@@ -754,7 +754,9 @@ hash_find_entry (Hash_table *table, const void *entry,
     = table->bucket + table->hasher (entry, table->n_buckets);
   struct hash_entry *cursor;
 
-  assert (bucket < table->bucket_limit);
+  if (table->bucket_limit <= bucket)
+    abort ();
+
   *bucket_head = bucket;
 
   /* Test for empty bucket.  */
@@ -848,7 +850,9 @@ hash_rehash (Hash_table *table, unsigned candidate)
 	    = (new_table->bucket
 	       + new_table->hasher (data, new_table->n_buckets));
 
-	  assert (new_bucket < new_table->bucket_limit);
+	  if (new_table->bucket_limit <= new_bucket)
+	    abort ();
+
 	  next = cursor->next;
 
 	  if (new_bucket->data)
@@ -912,7 +916,9 @@ hash_insert (Hash_table *table, const void *entry)
   void *data;
   struct hash_entry *bucket;
 
-  assert (entry);		/* cannot insert a NULL entry */
+  /* The caller cannot insert a NULL entry.  */
+  if (! entry)
+    abort ();
 
   /* If there's a matching entry already in the table, return that.  */
   if ((data = hash_find_entry (table, entry, &bucket, false)) != NULL)
