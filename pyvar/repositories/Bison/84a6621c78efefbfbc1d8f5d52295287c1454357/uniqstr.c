@@ -157,13 +157,11 @@ hash_uniqstr (void const *m, size_t tablesize)
 void
 uniqstrs_new (void)
 {
-  uniqstrs_table = hash_initialize (HT_INITIAL_CAPACITY,
-                                    NULL,
-                                    hash_uniqstr,
-                                    hash_compare_uniqstr,
-                                    free);
-  if (!uniqstrs_table)
-    xalloc_die ();
+  uniqstrs_table = hash_xinitialize (HT_INITIAL_CAPACITY,
+                                     NULL,
+                                     hash_uniqstr,
+                                     hash_compare_uniqstr,
+                                     free);
 }
 
 
