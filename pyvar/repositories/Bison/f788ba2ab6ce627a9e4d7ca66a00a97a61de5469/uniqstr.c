@@ -162,6 +162,8 @@ uniqstrs_new (void)
                                     hash_uniqstr,
                                     hash_compare_uniqstr,
                                     free);
+  if (!uniqstrs_table)
+    xalloc_die ();
 }
 
 
