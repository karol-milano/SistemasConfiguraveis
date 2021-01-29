@@ -379,7 +379,8 @@ state_hash_free (void)
 void
 state_hash_insert (state *s)
 {
-  hash_insert (state_table, s);
+  if (!hash_insert (state_table, s))
+    xalloc_die ();
 }
 
 
