@@ -156,22 +156,22 @@ set_state_table (void)
   {
     shifts *sp;
     for (sp = first_shift; sp; sp = sp->next)
-      state_table[sp->number].shift_table = sp;
+      state_table[sp->number].shifts = sp;
   }
 
   {
     reductions *rp;
     for (rp = first_reduction; rp; rp = rp->next)
-      state_table[rp->number].reduction_table = rp;
+      state_table[rp->number].reductions = rp;
   }
 
   /* Pessimization, but simplification of the code: make sense all the
-     states have a shift_table, even if reduced to 0 shifts.  */
+     states have a shifts, even if reduced to 0 shifts.  */
   {
     int i;
     for (i = 0; i < nstates; i++)
-      if (!state_table[i].shift_table)
-	state_table[i].shift_table = shifts_new (0);
+      if (!state_table[i].shifts)
+	state_table[i].shifts = shifts_new (0);
   }
 
   /* Initializing the lookaheads members.  Please note that it must be
@@ -183,8 +183,8 @@ set_state_table (void)
     for (i = 0; i < nstates; i++)
       {
 	int k;
-	reductions *rp = state_table[i].reduction_table;
-	shifts *sp = state_table[i].shift_table;
+	reductions *rp = state_table[i].reductions;
+	shifts *sp = state_table[i].shifts;
 
 	state_table[i].lookaheads = count;
 
@@ -225,7 +225,7 @@ initialize_LA (void)
   np = LAruleno;
   for (i = 0; i < nstates; i++)
     if (!state_table[i].consistent)
-      if ((rp = state_table[i].reduction_table))
+      if ((rp = state_table[i].reductions))
 	for (j = 0; j < rp->nreds; j++)
 	  *np++ = rp->rules[j];
 }
@@ -340,13 +340,13 @@ initialize_F (void)
   for (i = 0; i < ngotos; i++)
     {
       int stateno = to_state[i];
-      shifts *sp = state_table[stateno].shift_table;
+      shifts *sp = state_table[stateno].shifts;
 
       int j;
       for (j = 0; j < sp->nshifts && SHIFT_IS_SHIFT (sp, j); j++)
 	{
 	  int symbol = state_table[sp->shifts[j]].accessing_symbol;
-	  SETBIT (F + i * tokensetsize, symbol);
+	  SETBIT (F (i), symbol);
 	}
 
       for (; j < sp->nshifts; j++)
@@ -515,7 +515,7 @@ build_relations (void)
 
 	  for (rp = ritem + rule_table[*rulep].rhs; *rp > 0; rp++)
 	    {
-	      shifts *sp = state_table[stateno].shift_table;
+	      shifts *sp = state_table[stateno].shifts;
 	      int j;
 	      for (j = 0; j < sp->nshifts; j++)
 		{
