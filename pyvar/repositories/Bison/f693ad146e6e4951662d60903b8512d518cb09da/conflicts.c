@@ -56,7 +56,7 @@ Conflict in state %d between rule %d and token %s resolved as %s.\n"),
 static void
 flush_shift (int state, int token)
 {
-  shifts *shiftp = state_table[state].shifts;
+  shifts *shiftp = state_table[state]->shifts;
   int i;
 
   for (i = 0; i < shiftp->nshifts; i++)
@@ -147,8 +147,8 @@ resolve_sr_conflict (int state, int lookaheadnum)
   /* Some tokens have been explicitly made errors.  Allocate a
      permanent errs structure for this state, to record them.  */
   i = (char *) errtokens - (char *) errp;
-  state_table[state].errs = ERRS_ALLOC (i + 1);
-  memcpy (state_table[state].errs, errp, i);
+  state_table[state]->errs = ERRS_ALLOC (i + 1);
+  memcpy (state_table[state]->errs, errp, i);
   free (errp);
 }
 
@@ -159,13 +159,13 @@ set_conflicts (int state)
   int i, j;
   shifts *shiftp;
 
-  if (state_table[state].consistent)
+  if (state_table[state]->consistent)
     return;
 
   for (i = 0; i < tokensetsize; i++)
     lookaheadset[i] = 0;
 
-  shiftp = state_table[state].shifts;
+  shiftp = state_table[state]->shifts;
   for (i = 0; i < shiftp->nshifts && SHIFT_IS_SHIFT (shiftp, i); i++)
     if (!SHIFT_IS_DISABLED (shiftp, i))
       SETBIT (lookaheadset, SHIFT_SYMBOL (shiftp, i));
@@ -173,8 +173,8 @@ set_conflicts (int state)
   /* Loop over all rules which require lookahead in this state.  First
      check for shift-reduce conflict, and try to resolve using
      precedence */
-  for (i = state_table[state].lookaheads;
-       i < state_table[state + 1].lookaheads;
+  for (i = state_table[state]->lookaheads;
+       i < state_table[state + 1]->lookaheads;
        ++i)
     if (rule_table[LAruleno[i]].prec)
       for (j = 0; j < tokensetsize; ++j)
@@ -187,8 +187,8 @@ set_conflicts (int state)
 
   /* Loop over all rules which require lookahead in this state.  Check
      for conflicts not resolved above.  */
-  for (i = state_table[state].lookaheads;
-       i < state_table[state + 1].lookaheads;
+  for (i = state_table[state]->lookaheads;
+       i < state_table[state + 1]->lookaheads;
        ++i)
     {
       for (j = 0; j < tokensetsize; ++j)
@@ -223,7 +223,7 @@ count_sr_conflicts (int state)
 {
   int i, k;
   int src_count = 0;
-  shifts *shiftp = state_table[state].shifts;
+  shifts *shiftp = state_table[state]->shifts;
 
   if (!shiftp)
     return 0;
@@ -238,8 +238,8 @@ count_sr_conflicts (int state)
     if (!SHIFT_IS_DISABLED (shiftp, i))
       SETBIT (shiftset, SHIFT_SYMBOL (shiftp, i));
 
-  for (i = state_table[state].lookaheads;
-       i < state_table[state + 1].lookaheads;
+  for (i = state_table[state]->lookaheads;
+       i < state_table[state + 1]->lookaheads;
        ++i)
     for (k = 0; k < tokensetsize; ++k)
       lookaheadset[k] |= LA (i)[k];
@@ -265,8 +265,8 @@ count_rr_conflicts (int state)
   int i;
   int rrc_count = 0;
 
-  int m = state_table[state].lookaheads;
-  int n = state_table[state + 1].lookaheads;
+  int m = state_table[state]->lookaheads;
+  int n = state_table[state + 1]->lookaheads;
 
   if (n - m < 2)
     return 0;
@@ -424,7 +424,7 @@ print_reductions (FILE *out, int state)
   for (i = 0; i < tokensetsize; i++)
     shiftset[i] = 0;
 
-  shiftp = state_table[state].shifts;
+  shiftp = state_table[state]->shifts;
   for (i = 0; i < shiftp->nshifts && SHIFT_IS_SHIFT (shiftp, i); i++)
     if (!SHIFT_IS_DISABLED (shiftp, i))
       {
@@ -435,14 +435,14 @@ print_reductions (FILE *out, int state)
 	SETBIT (shiftset, SHIFT_SYMBOL (shiftp, i));
       }
 
-  errp = state_table[state].errs;
+  errp = state_table[state]->errs;
   if (errp)
     for (i = 0; i < errp->nerrs; i++)
       if (errp->errs[i])
 	SETBIT (shiftset, errp->errs[i]);
 
-  m = state_table[state].lookaheads;
-  n = state_table[state + 1].lookaheads;
+  m = state_table[state]->lookaheads;
+  n = state_table[state + 1]->lookaheads;
 
   if (n - m == 1 && !nodefault)
     {
