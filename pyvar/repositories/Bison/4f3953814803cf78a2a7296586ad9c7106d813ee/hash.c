@@ -262,7 +262,7 @@ hash_lookup (const Hash_table *table, const void *entry)
     = table->bucket + table->hasher (entry, table->n_buckets);
   struct hash_entry *cursor;
 
-  if (table->bucket_limit <= bucket)
+  if (! (bucket < table->bucket_limit))
     abort ();
 
   if (bucket->data == NULL)
@@ -293,7 +293,7 @@ hash_get_first (const Hash_table *table)
     return NULL;
 
   for (bucket = table->bucket; ; bucket++)
-    if (table->bucket_limit <= bucket)
+    if (! (bucket < table->bucket_limit))
       abort ();
     else if (bucket->data)
       return bucket->data;
@@ -310,7 +310,7 @@ hash_get_next (const Hash_table *table, const void *entry)
     = table->bucket + table->hasher (entry, table->n_buckets);
   struct hash_entry *cursor;
 
-  if (table->bucket_limit <= bucket)
+  if (! (bucket < table->bucket_limit))
     abort ();
 
   /* Find next entry in the same bucket.  */
@@ -754,7 +754,7 @@ hash_find_entry (Hash_table *table, const void *entry,
     = table->bucket + table->hasher (entry, table->n_buckets);
   struct hash_entry *cursor;
 
-  if (table->bucket_limit <= bucket)
+  if (! (bucket < table->bucket_limit))
     abort ();
 
   *bucket_head = bucket;
@@ -850,7 +850,7 @@ hash_rehash (Hash_table *table, unsigned candidate)
 	    = (new_table->bucket
 	       + new_table->hasher (data, new_table->n_buckets));
 
-	  if (new_table->bucket_limit <= new_bucket)
+	  if (! (new_bucket < new_table->bucket_limit))
 	    abort ();
 
 	  next = cursor->next;
