@@ -28,10 +28,10 @@
 | Create a new symbol, named TAG.  |
 `---------------------------------*/
 
-static bucket *
-bucket_new (const char *tag)
+static symbol_t *
+symbol_new (const char *tag)
 {
-  bucket *res = XMALLOC (bucket, 1);
+  symbol_t *res = XMALLOC (symbol_t, 1);
 
   res->tag = xstrdup (tag);
   res->type_name = NULL;
@@ -56,7 +56,7 @@ bucket_new (const char *tag)
 `------------*/
 
 static void
-bucket_free (bucket *this)
+symbol_free (symbol_t *this)
 {
 #if 0
   /* This causes crashes because one string can appear more
@@ -70,39 +70,39 @@ bucket_free (bucket *this)
 
 
 /*----------------------.
-| A bucket hash table.  |
+| A symbol_t hash table.  |
 `----------------------*/
 
-/* Initial capacity of buckets hash table.  */
+/* Initial capacity of symbols hash table.  */
 #define HT_INITIAL_CAPACITY 257
 
-static struct hash_table *bucket_table = NULL;
+static struct hash_table *symbol_table = NULL;
 
 static bool
-hash_compare_bucket (const bucket *m1, const bucket *m2)
+hash_compare_symbol_t (const symbol_t *m1, const symbol_t *m2)
 {
   return strcmp (m1->tag, m2->tag) ? FALSE : TRUE;
 }
 
 static unsigned int
-hash_bucket (const bucket *m, unsigned int tablesize)
+hash_symbol_t (const symbol_t *m, unsigned int tablesize)
 {
   return hash_string (m->tag, tablesize);
 }
 
 
 /*-------------------------------.
-| Create the bucket hash table.  |
+| Create the symbol_t hash table.  |
 `-------------------------------*/
 
 void
-buckets_new (void)
+symbols_new (void)
 {
-  bucket_table = hash_initialize (HT_INITIAL_CAPACITY,
+  symbol_table = hash_initialize (HT_INITIAL_CAPACITY,
 				  NULL,
-				  (Hash_hasher) hash_bucket,
-				  (Hash_comparator) hash_compare_bucket,
-				  (Hash_data_freer) bucket_free);
+				  (Hash_hasher) hash_symbol_t,
+				  (Hash_comparator) hash_compare_symbol_t,
+				  (Hash_data_freer) symbol_free);
 }
 
 
@@ -111,45 +111,45 @@ buckets_new (void)
 | yet, create it.                                                 |
 `----------------------------------------------------------------*/
 
-bucket *
+symbol_t *
 getsym (const char *key)
 {
-  bucket probe;
-  bucket *entry;
+  symbol_t probe;
+  symbol_t *entry;
 
   (const char *) probe.tag = key;
-  entry = hash_lookup (bucket_table, &probe);
+  entry = hash_lookup (symbol_table, &probe);
 
   if (!entry)
     {
       /* First insertion in the hash. */
-      entry = bucket_new (key);
-      hash_insert (bucket_table, entry);
+      entry = symbol_new (key);
+      hash_insert (symbol_table, entry);
     }
   return entry;
 }
 
 
 /*-------------------.
-| Free the buckets.  |
+| Free the symbols.  |
 `-------------------*/
 
 void
-buckets_free (void)
+symbols_free (void)
 {
-  hash_free (bucket_table);
+  hash_free (symbol_table);
 }
 
 
 /*---------------------------------------------------------------.
-| Look for undefined buckets, report an error, and consider them |
+| Look for undefined symbols, report an error, and consider them |
 | terminals.                                                     |
 `---------------------------------------------------------------*/
 
 void
-buckets_do (bucket_processor processor, void *processor_data)
+symbols_do (symbol_processor processor, void *processor_data)
 {
-  hash_do_for_each (bucket_table,
+  hash_do_for_each (symbol_table,
 		    (Hash_processor) processor,
 		    processor_data);
 }
