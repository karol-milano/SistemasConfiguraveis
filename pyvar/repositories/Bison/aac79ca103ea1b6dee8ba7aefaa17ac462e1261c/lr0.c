@@ -392,10 +392,14 @@ generate_states (void)
   allocate_storage ();
   closure_new (nritems);
 
-  /* Create the initial state.  The 0 at the lhs is the index of the
-     item of this initial rule.  */
-  item_index initial_core = 0;
-  state_list_append (0, 1, &initial_core);
+  /* Create the initial state, whose accessing symbol (by convention)
+     is 0, aka $end.  */
+  {
+    /* The items of its core.  */
+    kernel_size[0] = 1;
+    kernel_base[0][0] = 0;
+    state_list_append (0, kernel_size[0], kernel_base[0]);
+  }
 
   /* States are queued when they are created; process them all.  */
   for (state_list *list = first_state; list; list = list->next)
