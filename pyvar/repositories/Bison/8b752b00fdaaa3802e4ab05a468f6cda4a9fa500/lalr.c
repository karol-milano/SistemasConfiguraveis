@@ -94,7 +94,7 @@ set_goto_map (void)
   ngotos = 0;
   for (state = 0; state < nstates; ++state)
     {
-      transitions_t *sp = states[state]->shifts;
+      transitions_t *sp = states[state]->transitions;
       int i;
       for (i = sp->num - 1; i >= 0 && TRANSITION_IS_GOTO (sp, i); --i)
 	{
@@ -127,7 +127,7 @@ set_goto_map (void)
 
   for (state = 0; state < nstates; ++state)
     {
-      transitions_t *sp = states[state]->shifts;
+      transitions_t *sp = states[state]->transitions;
       int i;
       for (i = sp->num - 1; i >= 0 && TRANSITION_IS_GOTO (sp, i); --i)
 	{
@@ -189,7 +189,7 @@ initialize_F (void)
   for (i = 0; i < ngotos; i++)
     {
       state_number_t stateno = to_state[i];
-      transitions_t *sp = states[stateno]->shifts;
+      transitions_t *sp = states[stateno]->transitions;
 
       int j;
       for (j = 0; j < sp->num && TRANSITION_IS_SHIFT (sp, j); j++)
@@ -266,8 +266,8 @@ build_relations (void)
 
 	  for (rp = rules[*rulep].rhs; *rp >= 0; rp++)
 	    {
-	      state = transitions_to (state->shifts,
-				 item_number_as_symbol_number (*rp));
+	      state = transitions_to (state->transitions,
+				      item_number_as_symbol_number (*rp));
 	      states1[length++] = state->number;
 	    }
 
@@ -360,7 +360,7 @@ states_lookaheads_count (void)
       int k;
       int nlookaheads = 0;
       reductions_t *rp = states[i]->reductions;
-      transitions_t *sp = states[i]->shifts;
+      transitions_t *sp = states[i]->transitions;
 
       /* We need a lookahead either to distinguish different
 	 reductions (i.e., there are two or more), or to distinguish a
