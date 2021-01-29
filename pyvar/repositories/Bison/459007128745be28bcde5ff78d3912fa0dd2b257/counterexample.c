@@ -680,8 +680,7 @@ ssb_append (search_state *ss)
       search_state_free (ss);
       return;
     }
-  if (!hash_insert (visited, ss))
-    xalloc_die ();
+  hash_xinsert (visited, ss);
   // if states are only referenced by the visited set,
   // their contents should be freed as we only need
   // the metadata necessary to compute a hash.
