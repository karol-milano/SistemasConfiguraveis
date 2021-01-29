@@ -359,13 +359,11 @@ state_hasher (void const *s, size_t tablesize)
 void
 state_hash_new (void)
 {
-  state_table = hash_initialize (HT_INITIAL_CAPACITY,
-                                 NULL,
-                                 state_hasher,
-                                 state_comparator,
-                                 NULL);
-  if (!state_table)
-    xalloc_die ();
+  state_table = hash_xinitialize (HT_INITIAL_CAPACITY,
+                                  NULL,
+                                  state_hasher,
+                                  state_comparator,
+                                  NULL);
 }
 
 
