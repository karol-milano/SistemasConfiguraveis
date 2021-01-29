@@ -364,6 +364,8 @@ state_hash_new (void)
                                  state_hasher,
                                  state_comparator,
                                  NULL);
+  if (!state_table)
+    xalloc_die ();
 }
 
 
