@@ -158,13 +158,10 @@ si_bfs_free (si_bfs_node *n)
 {
   if (n == NULL)
     return;
+  --n->reference_count;
   if (n->reference_count == 0)
     {
-      if (n->parent)
-        {
-          --n->parent->reference_count;
-          si_bfs_free (n->parent);
-        }
+      si_bfs_free (n->parent);
       free (n);
     }
 }
