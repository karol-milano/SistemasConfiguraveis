@@ -94,15 +94,15 @@ set_goto_map (void)
   ngotos = 0;
   for (state = 0; state < nstates; ++state)
     {
-      shifts_t *sp = states[state]->shifts;
+      transitions_t *sp = states[state]->shifts;
       int i;
-      for (i = sp->nshifts - 1; i >= 0 && SHIFT_IS_GOTO (sp, i); --i)
+      for (i = sp->num - 1; i >= 0 && TRANSITION_IS_GOTO (sp, i); --i)
 	{
 	  if (ngotos == SHRT_MAX)
 	    fatal (_("too many gotos (max %d)"), SHRT_MAX);
 
 	  ngotos++;
-	  goto_map[SHIFT_SYMBOL (sp, i)]++;
+	  goto_map[TRANSITION_SYMBOL (sp, i)]++;
 	}
     }
 
@@ -127,13 +127,13 @@ set_goto_map (void)
 
   for (state = 0; state < nstates; ++state)
     {
-      shifts_t *sp = states[state]->shifts;
+      transitions_t *sp = states[state]->shifts;
       int i;
-      for (i = sp->nshifts - 1; i >= 0 && SHIFT_IS_GOTO (sp, i); --i)
+      for (i = sp->num - 1; i >= 0 && TRANSITION_IS_GOTO (sp, i); --i)
 	{
-	  int k = temp_map[SHIFT_SYMBOL (sp, i)]++;
+	  int k = temp_map[TRANSITION_SYMBOL (sp, i)]++;
 	  from_state[k] = state;
-	  to_state[k] = sp->shifts[i];
+	  to_state[k] = sp->states[i];
 	}
     }
 
@@ -189,15 +189,15 @@ initialize_F (void)
   for (i = 0; i < ngotos; i++)
     {
       state_number_t stateno = to_state[i];
-      shifts_t *sp = states[stateno]->shifts;
+      transitions_t *sp = states[stateno]->shifts;
 
       int j;
-      for (j = 0; j < sp->nshifts && SHIFT_IS_SHIFT (sp, j); j++)
-	bitset_set (F[i], SHIFT_SYMBOL (sp, j));
+      for (j = 0; j < sp->num && TRANSITION_IS_SHIFT (sp, j); j++)
+	bitset_set (F[i], TRANSITION_SYMBOL (sp, j));
 
-      for (; j < sp->nshifts; j++)
+      for (; j < sp->num; j++)
 	{
-	  symbol_number_t symbol = SHIFT_SYMBOL (sp, j);
+	  symbol_number_t symbol = TRANSITION_SYMBOL (sp, j);
 	  if (nullable[symbol])
 	    edge[nedges++] = map_goto (stateno, symbol);
 	}
@@ -266,7 +266,7 @@ build_relations (void)
 
 	  for (rp = rules[*rulep].rhs; *rp >= 0; rp++)
 	    {
-	      state = shifts_to (state->shifts,
+	      state = transitions_to (state->shifts,
 				 item_number_as_symbol_number (*rp));
 	      states1[length++] = state->number;
 	    }
@@ -360,20 +360,20 @@ states_lookaheads_count (void)
       int k;
       int nlookaheads = 0;
       reductions_t *rp = states[i]->reductions;
-      shifts_t *sp = states[i]->shifts;
+      transitions_t *sp = states[i]->shifts;
 
       /* We need a lookahead either to distinguish different
 	 reductions (i.e., there are two or more), or to distinguish a
 	 reduction from a shift.  Otherwise, it is straightforward,
 	 and the state is `consistent'.  */
       if (rp->nreds > 1
-	  || (rp->nreds == 1 && sp->nshifts && SHIFT_IS_SHIFT (sp, 0)))
+	  || (rp->nreds == 1 && sp->num && TRANSITION_IS_SHIFT (sp, 0)))
 	nlookaheads += rp->nreds;
       else
 	states[i]->consistent = 1;
 
-      for (k = 0; k < sp->nshifts; k++)
-	if (SHIFT_IS_ERROR (sp, k))
+      for (k = 0; k < sp->num; k++)
+	if (TRANSITION_IS_ERROR (sp, k))
 	  {
 	    states[i]->consistent = 0;
 	    break;
