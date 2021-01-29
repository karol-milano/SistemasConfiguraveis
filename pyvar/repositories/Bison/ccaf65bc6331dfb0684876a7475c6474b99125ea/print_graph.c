@@ -127,19 +127,19 @@ print_actions (state_t *state, const char *node_name)
 {
   int i;
 
-  shifts_t     *shiftp = state->shifts;
+  transitions_t     *transitions = state->shifts;
   reductions_t *redp = state->reductions;
 
   static char buff[10];
   edge_t edge;
 
-  if (!shiftp->nshifts && !redp)
+  if (!transitions->num && !redp)
     return;
 
-  for (i = 0; i < shiftp->nshifts; i++)
-    if (!SHIFT_IS_DISABLED (shiftp, i))
+  for (i = 0; i < transitions->num; i++)
+    if (!TRANSITION_IS_DISABLED (transitions, i))
       {
-	state_number_t state1 = shiftp->shifts[i];
+	state_number_t state1 = transitions->states[i];
 	symbol_number_t symbol = states[state1]->accessing_symbol;
 
 	new_edge (&edge);
@@ -152,10 +152,10 @@ print_actions (state_t *state, const char *node_name)
 	sprintf (buff, "%d", state1);
 	edge.targetname = buff;
 	/* Shifts are blue, gotos are green, and error is red. */
-	if (SHIFT_IS_ERROR (shiftp, i))
+	if (TRANSITION_IS_ERROR (transitions, i))
 	  edge.color = red;
 	else
-	  edge.color = SHIFT_IS_SHIFT(shiftp, i) ? blue : green;
+	  edge.color = TRANSITION_IS_SHIFT(transitions, i) ? blue : green;
 	edge.label = symbol_tag_get (symbols[symbol]);
 	output_edge (&edge, fgraph);
 	close_edge (fgraph);
