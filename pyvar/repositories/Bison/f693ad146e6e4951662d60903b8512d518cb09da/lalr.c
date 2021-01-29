@@ -36,7 +36,7 @@
 /* All the decorated states, indexed by the state number.  Warning:
    there is a state_TABLE in LR0.c, but it is different and static.
    */
-state_t *state_table = NULL;
+state_t **state_table = NULL;
 
 int tokensetsize;
 short *LAruleno;
@@ -142,36 +142,33 @@ set_state_table (void)
   /* NSTATES + 1 because lookahead for the pseudo state number NSTATES
      might be used (see conflicts.c).  It is too opaque for me to
      provide a probably less hacky implementation. --akim */
-  state_table = XCALLOC (state_t, nstates + 1);
+  state_table = XCALLOC (state_t *, nstates + 1);
 
   {
-    core *sp;
+    state_t *sp;
     for (sp = first_state; sp; sp = sp->next)
-      {
-	state_table[sp->number].state = sp;
-	state_table[sp->number].accessing_symbol = sp->accessing_symbol;
-      }
+      state_table[sp->number] = sp;
   }
 
   {
     shifts *sp;
     for (sp = first_shift; sp; sp = sp->next)
-      state_table[sp->number].shifts = sp;
+      state_table[sp->number]->shifts = sp;
   }
 
   {
     reductions *rp;
     for (rp = first_reduction; rp; rp = rp->next)
-      state_table[rp->number].reductions = rp;
+      state_table[rp->number]->reductions = rp;
   }
 
-  /* Pessimization, but simplification of the code: make sense all the
+  /* Pessimization, but simplification of the code: make sure all the
      states have a shifts, even if reduced to 0 shifts.  */
   {
     int i;
     for (i = 0; i < nstates; i++)
-      if (!state_table[i].shifts)
-	state_table[i].shifts = shifts_new (0);
+      if (!state_table[i]->shifts)
+	state_table[i]->shifts = shifts_new (0);
   }
 
   /* Initializing the lookaheads members.  Please note that it must be
@@ -183,25 +180,28 @@ set_state_table (void)
     for (i = 0; i < nstates; i++)
       {
 	int k;
-	reductions *rp = state_table[i].reductions;
-	shifts *sp = state_table[i].shifts;
+	reductions *rp = state_table[i]->reductions;
+	shifts *sp = state_table[i]->shifts;
 
-	state_table[i].lookaheads = count;
+	state_table[i]->lookaheads = count;
 
 	if (rp
 	    && (rp->nreds > 1 || (sp->nshifts && SHIFT_IS_SHIFT (sp, 0))))
 	  count += rp->nreds;
 	else
-	  state_table[i].consistent = 1;
+	  state_table[i]->consistent = 1;
 
 	for (k = 0; k < sp->nshifts; k++)
 	  if (SHIFT_IS_ERROR (sp, k))
 	    {
-	      state_table[i].consistent = 0;
+	      state_table[i]->consistent = 0;
 	      break;
 	    }
       }
-     state_table[nstates].lookaheads = count;
+
+    /* Seems to be needed by conflicts.c. */
+    state_table[nstates] = STATE_ALLOC (0);
+    state_table[nstates]->lookaheads = count;
   }
 }
 
@@ -214,7 +214,7 @@ initialize_LA (void)
   short *np;
   reductions *rp;
 
-  size_t nLA = state_table[nstates].lookaheads;
+  size_t nLA = state_table[nstates]->lookaheads;
   if (!nLA)
     nLA = 1;
 
@@ -224,8 +224,8 @@ initialize_LA (void)
 
   np = LAruleno;
   for (i = 0; i < nstates; i++)
-    if (!state_table[i].consistent)
-      if ((rp = state_table[i].reductions))
+    if (!state_table[i]->consistent)
+      if ((rp = state_table[i]->reductions))
 	for (j = 0; j < rp->nreds; j++)
 	  *np++ = rp->rules[j];
 }
@@ -249,7 +249,7 @@ set_goto_map (void)
   for (sp = first_shift; sp; sp = sp->next)
     for (i = sp->nshifts - 1; i >= 0 && SHIFT_IS_GOTO (sp, i); --i)
       {
-	symbol = state_table[sp->shifts[i]].accessing_symbol;
+	symbol = state_table[sp->shifts[i]]->accessing_symbol;
 
 	if (ngotos == MAXSHORT)
 	  fatal (_("too many gotos (max %d)"), MAXSHORT);
@@ -280,7 +280,7 @@ set_goto_map (void)
       for (i = sp->nshifts - 1; i >= 0 && SHIFT_IS_GOTO (sp, i); --i)
 	{
 	  state2 = sp->shifts[i];
-	  symbol = state_table[state2].accessing_symbol;
+	  symbol = state_table[state2]->accessing_symbol;
 
 	  k = temp_map[symbol]++;
 	  from_state[k] = state1;
@@ -340,18 +340,18 @@ initialize_F (void)
   for (i = 0; i < ngotos; i++)
     {
       int stateno = to_state[i];
-      shifts *sp = state_table[stateno].shifts;
+      shifts *sp = state_table[stateno]->shifts;
 
       int j;
       for (j = 0; j < sp->nshifts && SHIFT_IS_SHIFT (sp, j); j++)
 	{
-	  int symbol = state_table[sp->shifts[j]].accessing_symbol;
+	  int symbol = state_table[sp->shifts[j]]->accessing_symbol;
 	  SETBIT (F (i), symbol);
 	}
 
       for (; j < sp->nshifts; j++)
 	{
-	  int symbol = state_table[sp->shifts[j]].accessing_symbol;
+	  int symbol = state_table[sp->shifts[j]]->accessing_symbol;
 	  if (nullable[symbol])
 	    edge[nedges++] = map_goto (stateno, symbol);
 	}
@@ -383,8 +383,8 @@ add_lookback_edge (int stateno, int ruleno, int gotono)
   int found;
   shorts *sp;
 
-  i = state_table[stateno].lookaheads;
-  k = state_table[stateno + 1].lookaheads;
+  i = state_table[stateno]->lookaheads;
+  k = state_table[stateno + 1]->lookaheads;
   found = 0;
   while (!found && i < k)
     {
@@ -502,7 +502,7 @@ build_relations (void)
     {
       int nedges = 0;
       int state1 = from_state[i];
-      int symbol1 = state_table[to_state[i]].accessing_symbol;
+      int symbol1 = state_table[to_state[i]]->accessing_symbol;
       short *rulep;
 
       for (rulep = derives[symbol1]; *rulep > 0; rulep++)
@@ -515,19 +515,19 @@ build_relations (void)
 
 	  for (rp = ritem + rule_table[*rulep].rhs; *rp > 0; rp++)
 	    {
-	      shifts *sp = state_table[stateno].shifts;
+	      shifts *sp = state_table[stateno]->shifts;
 	      int j;
 	      for (j = 0; j < sp->nshifts; j++)
 		{
 		  stateno = sp->shifts[j];
-		  if (state_table[stateno].accessing_symbol == *rp)
+		  if (state_table[stateno]->accessing_symbol == *rp)
 		    break;
 		}
 
 	      states[length++] = stateno;
 	    }
 
-	  if (!state_table[stateno].consistent)
+	  if (!state_table[stateno]->consistent)
 	    add_lookback_edge (stateno, *rulep, i);
 
 	  length--;
@@ -585,7 +585,7 @@ compute_lookaheads (void)
   int i;
   shorts *sp;
 
-  for (i = 0; i < state_table[nstates].lookaheads; i++)
+  for (i = 0; i < state_table[nstates]->lookaheads; i++)
     for (sp = lookback[i]; sp; sp = sp->next)
       {
 	int size = LA (i + 1) - LA (i);
@@ -595,7 +595,7 @@ compute_lookaheads (void)
       }
 
   /* Free LOOKBACK. */
-  for (i = 0; i < state_table[nstates].lookaheads; i++)
+  for (i = 0; i < state_table[nstates]->lookaheads; i++)
     LIST_FREE (shorts, lookback[i]);
 
   XFREE (lookback);
