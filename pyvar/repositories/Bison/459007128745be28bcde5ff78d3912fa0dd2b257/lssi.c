@@ -91,8 +91,7 @@ append_lssi (lssi *sn, Hash_table *visited, gl_list_t queue)
       lssi_free (sn);
       return false;
     }
-  if (!hash_insert (visited, sn))
-    xalloc_die ();
+  hash_xinsert (visited, sn);
   gl_list_add_last (queue, sn);
   return true;
 }
