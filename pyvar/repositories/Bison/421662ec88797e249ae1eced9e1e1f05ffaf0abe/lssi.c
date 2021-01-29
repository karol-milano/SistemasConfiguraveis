@@ -238,7 +238,7 @@ shortest_path_from_start (state_item_number target, symbol_number next_sym)
     {
       gl_list_free (queue);
       fputs ("Cannot find shortest path to conflict state.", stderr);
-      exit (1);
+      abort ();
     }
   gl_list_t res =
     gl_list_create_empty (GL_LINKED_LIST, NULL, NULL, NULL, true);
