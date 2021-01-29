@@ -159,9 +159,9 @@ shortest_path_from_start (state_item_number target, symbol_number next_sym)
   bitset il = bitset_create (nsyms, BITSET_FIXED);
   bitset_set (il, 0);
   lssi *init = new_lssi (0, NULL, il, true);
-  gl_list_t queue = gl_list_create (GL_LINKED_LIST, NULL, NULL,
-                                    NULL,
-                                    true, 1, (const void **) &init);
+  gl_list_t queue = gl_list_create_empty (GL_LINKED_LIST, NULL, NULL,
+                                          NULL, true);
+  append_lssi (init, visited, queue);
   // breadth-first search
   bool finished = false;
   lssi *n;
@@ -234,6 +234,8 @@ shortest_path_from_start (state_item_number target, symbol_number next_sym)
             bitset_free (lookahead);
         }
     }
+
+  bitset_free (eligible);
   if (!finished)
     {
       gl_list_free (queue);
