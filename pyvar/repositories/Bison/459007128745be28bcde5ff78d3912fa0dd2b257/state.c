@@ -385,8 +385,7 @@ state_hash_free (void)
 void
 state_hash_insert (state *s)
 {
-  if (!hash_insert (state_table, s))
-    xalloc_die ();
+  hash_xinsert (state_table, s);
 }
 
 
