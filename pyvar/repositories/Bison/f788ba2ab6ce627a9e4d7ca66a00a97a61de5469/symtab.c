@@ -778,11 +778,15 @@ symbols_new (void)
                                   hash_symbol_hasher,
                                   hash_symbol_comparator,
                                   symbol_free);
+  if (!symbol_table)
+    xalloc_die ();
   semantic_type_table = hash_initialize (HT_INITIAL_CAPACITY,
                                          NULL,
                                          hash_semantic_type_hasher,
                                          hash_semantic_type_comparator,
                                          free);
+  if (!semantic_type_table)
+    xalloc_die ();
 }
 
 
