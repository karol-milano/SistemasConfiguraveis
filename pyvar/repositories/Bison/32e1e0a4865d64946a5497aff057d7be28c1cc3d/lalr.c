@@ -163,7 +163,7 @@ set_goto_map (void)
   ngotos = 0;
   for (state = 0; state < nstates; ++state)
     {
-      shifts *sp = states[state]->shifts;
+      shifts_t *sp = states[state]->shifts;
       int i;
       for (i = sp->nshifts - 1; i >= 0 && SHIFT_IS_GOTO (sp, i); --i)
 	{
@@ -196,7 +196,7 @@ set_goto_map (void)
 
   for (state = 0; state < nstates; ++state)
     {
-      shifts *sp = states[state]->shifts;
+      shifts_t *sp = states[state]->shifts;
       int i;
       for (i = sp->nshifts - 1; i >= 0 && SHIFT_IS_GOTO (sp, i); --i)
 	{
@@ -258,7 +258,7 @@ initialize_F (void)
   for (i = 0; i < ngotos; i++)
     {
       state_number_t stateno = to_state[i];
-      shifts *sp = states[stateno]->shifts;
+      shifts_t *sp = states[stateno]->shifts;
 
       int j;
       for (j = 0; j < sp->nshifts && SHIFT_IS_SHIFT (sp, j); j++)
@@ -420,7 +420,7 @@ build_relations (void)
 
 	  for (rp = rules[*rulep].rhs; *rp >= 0; rp++)
 	    {
-	      shifts *sp = state->shifts;
+	      shifts_t *sp = state->shifts;
 	      int j;
 	      for (j = 0; j < sp->nshifts; j++)
 		{
@@ -522,7 +522,7 @@ states_lookaheads_count (void)
       int k;
       int nlookaheads = 0;
       reductions *rp = states[i]->reductions;
-      shifts *sp = states[i]->shifts;
+      shifts_t *sp = states[i]->shifts;
 
       /* We need a lookahead either to distinguish different
 	 reductions (i.e., there are two or more), or to distinguish a
