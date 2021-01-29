@@ -137,17 +137,17 @@ print_actions (state_t *state, const char *node_name)
   for (i = 0; i < transitions->num; i++)
     if (!TRANSITION_IS_DISABLED (transitions, i))
       {
-	state_number_t state1 = transitions->states[i];
-	symbol_number_t symbol = states[state1]->accessing_symbol;
+	state_t *state1 = transitions->states[i];
+	symbol_number_t symbol = state1->accessing_symbol;
 
 	new_edge (&edge);
 
-	if (state->number > state1)
+	if (state->number > state1->number)
 	  edge.type = back_edge;
 	open_edge (&edge, fgraph);
 	/* The edge source is the current node.  */
 	edge.sourcename = node_name;
-	sprintf (buff, "%d", state1);
+	sprintf (buff, "%d", state1->number);
 	edge.targetname = buff;
 	/* Shifts are blue, gotos are green, and error is red. */
 	if (TRANSITION_IS_ERROR (transitions, i))
