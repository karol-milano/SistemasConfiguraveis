@@ -254,7 +254,7 @@ shortest_path_from_start (state_item_number target, symbol_number next_sym)
       gl_list_iterator_t it = gl_list_iterator (res);
       const void *sip;
       while (gl_list_iterator_next (&it, &sip, NULL))
-        print_state_item ((state_item *) sip, stdout);
+        print_state_item ((state_item *) sip, stdout, "");
     }
   return res;
 }
