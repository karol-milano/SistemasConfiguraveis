@@ -36,7 +36,7 @@
 #include "getargs.h"
 
 /* All the decorated states, indexed by the state number.  */
-state_t **state_table = NULL;
+state_t **states = NULL;
 
 int tokensetsize;
 short *LAruleno;
@@ -150,9 +150,9 @@ initialize_LA (void)
 
   np = LAruleno;
   for (i = 0; i < nstates; i++)
-    if (!state_table[i]->consistent)
-      for (j = 0; j < state_table[i]->reductions->nreds; j++)
-	*np++ = state_table[i]->reductions->rules[j];
+    if (!states[i]->consistent)
+      for (j = 0; j < states[i]->reductions->nreds; j++)
+	*np++ = states[i]->reductions->rules[j];
 }
 
 
@@ -168,7 +168,7 @@ set_goto_map (void)
   ngotos = 0;
   for (state = 0; state < nstates; ++state)
     {
-      shifts *sp = state_table[state]->shifts;
+      shifts *sp = states[state]->shifts;
       for (i = sp->nshifts - 1; i >= 0 && SHIFT_IS_GOTO (sp, i); --i)
 	{
 	  if (ngotos == MAXSHORT)
@@ -199,7 +199,7 @@ set_goto_map (void)
 
   for (state = 0; state < nstates; ++state)
     {
-      shifts *sp = state_table[state]->shifts;
+      shifts *sp = states[state]->shifts;
       for (i = sp->nshifts - 1; i >= 0 && SHIFT_IS_GOTO (sp, i); --i)
 	{
 	  int k = temp_map[SHIFT_SYMBOL (sp, i)]++;
@@ -260,7 +260,7 @@ initialize_F (void)
   for (i = 0; i < ngotos; i++)
     {
       int stateno = to_state[i];
-      shifts *sp = state_table[stateno]->shifts;
+      shifts *sp = states[stateno]->shifts;
 
       int j;
       for (j = 0; j < sp->nshifts && SHIFT_IS_SHIFT (sp, j); j++)
@@ -409,7 +409,7 @@ build_relations (void)
   for (i = 0; i < ngotos; i++)
     {
       int nedges = 0;
-      int symbol1 = state_table[to_state[i]]->accessing_symbol;
+      int symbol1 = states[to_state[i]]->accessing_symbol;
       short *rulep;
 
       for (rulep = derives[symbol1]; *rulep > 0; rulep++)
@@ -417,7 +417,7 @@ build_relations (void)
 	  int done;
 	  int length = 1;
 	  short *rp;
-	  state_t *state = state_table[from_state[i]];
+	  state_t *state = states[from_state[i]];
 	  states1[0] = state->number;
 
 	  for (rp = &ritem[rules[*rulep].rhs]; *rp >= 0; rp++)
@@ -426,7 +426,7 @@ build_relations (void)
 	      int j;
 	      for (j = 0; j < sp->nshifts; j++)
 		{
-		  state = state_table[sp->shifts[j]];
+		  state = states[sp->shifts[j]];
 		  if (state->accessing_symbol == *rp)
 		    break;
 		}
@@ -522,8 +522,8 @@ initialize_lookaheads (void)
     {
       int k;
       int nlookaheads = 0;
-      reductions *rp = state_table[i]->reductions;
-      shifts *sp = state_table[i]->shifts;
+      reductions *rp = states[i]->reductions;
+      shifts *sp = states[i]->shifts;
 
       /* We need a lookahead either to distinguish different
 	 reductions (i.e., there are two or more), or to distinguish a
@@ -533,17 +533,17 @@ initialize_lookaheads (void)
 	  || (rp->nreds == 1 && sp->nshifts && SHIFT_IS_SHIFT (sp, 0)))
 	nlookaheads += rp->nreds;
       else
-	state_table[i]->consistent = 1;
+	states[i]->consistent = 1;
 
       for (k = 0; k < sp->nshifts; k++)
 	if (SHIFT_IS_ERROR (sp, k))
 	  {
-	    state_table[i]->consistent = 0;
+	    states[i]->consistent = 0;
 	    break;
 	  }
 
-      state_table[i]->nlookaheads = nlookaheads;
-      state_table[i]->lookaheadsp = nLA;
+      states[i]->nlookaheads = nlookaheads;
+      states[i]->lookaheadsp = nLA;
       nLA += nlookaheads;
     }
 }
@@ -561,14 +561,14 @@ lookaheads_print (FILE *out)
   for (i = 0; i < nstates; ++i)
     {
       fprintf (out, "State %d: %d lookaheads\n",
-	       i, state_table[i]->nlookaheads);
+	       i, states[i]->nlookaheads);
 
-      for (j = 0; j < state_table[i]->nlookaheads; ++j)
+      for (j = 0; j < states[i]->nlookaheads; ++j)
 	for (k = 0; k < ntokens; ++k)
-	  if (BITISSET (LA (state_table[i]->lookaheadsp + j), j))
+	  if (BITISSET (LA (states[i]->lookaheadsp + j), j))
 	    fprintf (out, "   on %d (%s) -> rule %d\n",
 		     k, symbols[k]->tag,
-		     -LAruleno[state_table[i]->lookaheadsp + j] - 1);
+		     -LAruleno[states[i]->lookaheadsp + j] - 1);
     }
   fprintf (out, "Lookaheads: END\n");
 }
