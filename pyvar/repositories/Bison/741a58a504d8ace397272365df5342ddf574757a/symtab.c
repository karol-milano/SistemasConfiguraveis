@@ -779,20 +779,16 @@ hash_semantic_type_hasher (void const *m, size_t tablesize)
 void
 symbols_new (void)
 {
-  symbol_table = hash_initialize (HT_INITIAL_CAPACITY,
-                                  NULL,
-                                  hash_symbol_hasher,
-                                  hash_symbol_comparator,
-                                  symbol_free);
-  if (!symbol_table)
-    xalloc_die ();
-  semantic_type_table = hash_initialize (HT_INITIAL_CAPACITY,
-                                         NULL,
-                                         hash_semantic_type_hasher,
-                                         hash_semantic_type_comparator,
-                                         free);
-  if (!semantic_type_table)
-    xalloc_die ();
+  symbol_table = hash_xinitialize (HT_INITIAL_CAPACITY,
+                                   NULL,
+                                   hash_symbol_hasher,
+                                   hash_symbol_comparator,
+                                   symbol_free);
+  semantic_type_table = hash_xinitialize (HT_INITIAL_CAPACITY,
+                                          NULL,
+                                          hash_semantic_type_hasher,
+                                          hash_semantic_type_comparator,
+                                          free);
 }
 
 
