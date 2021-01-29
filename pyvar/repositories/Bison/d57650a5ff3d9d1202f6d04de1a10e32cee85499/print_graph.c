@@ -135,7 +135,7 @@ print_actions (state_t *state, const char *node_name)
   for (i = 0; i < shiftp->nshifts; i++)
     if (!SHIFT_IS_DISABLED (shiftp, i))
       {
-	int state1 = shiftp->shifts[i];
+	state_number_t state1 = shiftp->shifts[i];
 	symbol_number_t symbol = states[state1]->accessing_symbol;
 
 	new_edge (&edge);
@@ -194,7 +194,7 @@ print_state (state_t *state)
 void
 print_graph (void)
 {
-  size_t i;
+  state_number_t i;
 
   /* Output file.  */
   fgraph = xfopen (spec_graph_file, "w");
