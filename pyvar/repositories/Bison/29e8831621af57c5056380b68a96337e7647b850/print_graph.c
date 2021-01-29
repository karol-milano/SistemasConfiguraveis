@@ -114,7 +114,7 @@ print_actions (state_t *state, const char *node_name)
     if (!SHIFT_IS_DISABLED (shiftp, i))
       {
 	int state1 = shiftp->shifts[i];
-	int symbol = state_table[state1]->accessing_symbol;
+	int symbol = states[state1]->accessing_symbol;
 
 	new_edge (&edge);
 
@@ -202,7 +202,7 @@ print_graph (void)
   /* Output nodes and edges. */
   new_closure (nritems);
   for (i = 0; i < nstates; i++)
-    print_state (state_table[i]);
+    print_state (states[i]);
   free_closure ();
 
   /* Close graph. */
