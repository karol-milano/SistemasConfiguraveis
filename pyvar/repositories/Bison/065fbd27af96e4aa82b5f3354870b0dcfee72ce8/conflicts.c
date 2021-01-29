@@ -38,13 +38,13 @@ static unsigned *lookaheadset = NULL;
 
 
 static inline void
-log_resolution (int state, int LAno, int token, char *resolution)
+log_resolution (state_t *state, int LAno, int token, char *resolution)
 {
   if (verbose_flag)
     obstack_fgrow4 (&output_obstack,
 		    _("\
 Conflict in state %d between rule %d and token %s resolved as %s.\n"),
-		    state, LAruleno[LAno], tags[token], resolution);
+		    state->number, LAruleno[LAno], tags[token], resolution);
 }
 
 
@@ -55,9 +55,9 @@ Conflict in state %d between rule %d and token %s resolved as %s.\n"),
 `------------------------------------------------------------------*/
 
 static void
-flush_shift (int state, int token)
+flush_shift (state_t *state, int token)
 {
-  shifts *shiftp = state_table[state]->shifts;
+  shifts *shiftp = state->shifts;
   int i;
 
   RESETBIT (lookaheadset, token);
@@ -88,7 +88,7 @@ flush_reduce (int lookahead, int token)
 `------------------------------------------------------------------*/
 
 static void
-resolve_sr_conflict (int state, int lookahead)
+resolve_sr_conflict (state_t *state, int lookahead)
 {
   int i;
   /* find the rule to reduce by to get precedence of reduction  */
@@ -146,25 +146,25 @@ resolve_sr_conflict (int state, int lookahead)
   /* Some tokens have been explicitly made errors.  Allocate a
      permanent errs structure for this state, to record them.  */
   i = (char *) errtokens - (char *) errp;
-  state_table[state]->errs = ERRS_ALLOC (i + 1);
-  memcpy (state_table[state]->errs, errp, i);
+  state->errs = ERRS_ALLOC (i + 1);
+  memcpy (state->errs, errp, i);
   free (errp);
 }
 
 
 static void
-set_conflicts (int state)
+set_conflicts (state_t *state)
 {
   int i, j;
   shifts *shiftp;
 
-  if (state_table[state]->consistent)
+  if (state->consistent)
     return;
 
   for (i = 0; i < tokensetsize; i++)
     lookaheadset[i] = 0;
 
-  shiftp = state_table[state]->shifts;
+  shiftp = state->shifts;
   for (i = 0; i < shiftp->nshifts && SHIFT_IS_SHIFT (shiftp, i); i++)
     if (!SHIFT_IS_DISABLED (shiftp, i))
       SETBIT (lookaheadset, SHIFT_SYMBOL (shiftp, i));
@@ -172,30 +172,26 @@ set_conflicts (int state)
   /* Loop over all rules which require lookahead in this state.  First
      check for shift-reduce conflict, and try to resolve using
      precedence */
-  for (i = state_table[state]->lookaheadsp;
-       i < state_table[state + 1]->lookaheadsp;
-       ++i)
-    if (rule_table[LAruleno[i]].prec)
+  for (i = 0; i < state->nlookaheads; ++i)
+    if (rule_table[LAruleno[state->lookaheadsp + i]].prec)
       for (j = 0; j < tokensetsize; ++j)
-	if (LA (i)[j] & lookaheadset[j])
+	if (LA (state->lookaheadsp + i)[j] & lookaheadset[j])
 	  {
-	    resolve_sr_conflict (state, i);
+	    resolve_sr_conflict (state, state->lookaheadsp + i);
 	    break;
 	  }
 
 
   /* Loop over all rules which require lookahead in this state.  Check
      for conflicts not resolved above.  */
-  for (i = state_table[state]->lookaheadsp;
-       i < state_table[state + 1]->lookaheadsp;
-       ++i)
+  for (i = 0; i < state->nlookaheads; ++i)
     {
       for (j = 0; j < tokensetsize; ++j)
-	if (LA (i)[j] & lookaheadset[j])
-	  conflicts[state] = 1;
+	if (LA (state->lookaheadsp + i)[j] & lookaheadset[j])
+	  conflicts[state->number] = 1;
 
       for (j = 0; j < tokensetsize; ++j)
-	lookaheadset[j] |= LA (i)[j];
+	lookaheadset[j] |= LA (state->lookaheadsp + i)[j];
     }
 }
 
@@ -209,7 +205,7 @@ solve_conflicts (void)
   lookaheadset = XCALLOC (unsigned, tokensetsize);
 
   for (i = 0; i < nstates; i++)
-    set_conflicts (i);
+    set_conflicts (state_table[i]);
 }
 
 
@@ -218,11 +214,11 @@ solve_conflicts (void)
 `---------------------------------------------*/
 
 static int
-count_sr_conflicts (int state)
+count_sr_conflicts (state_t *state)
 {
   int i, k;
   int src_count = 0;
-  shifts *shiftp = state_table[state]->shifts;
+  shifts *shiftp = state->shifts;
 
   if (!shiftp)
     return 0;
@@ -237,11 +233,9 @@ count_sr_conflicts (int state)
     if (!SHIFT_IS_DISABLED (shiftp, i))
       SETBIT (shiftset, SHIFT_SYMBOL (shiftp, i));
 
-  for (i = state_table[state]->lookaheadsp;
-       i < state_table[state + 1]->lookaheadsp;
-       ++i)
+  for (i = 0; i < state->nlookaheads; ++i)
     for (k = 0; k < tokensetsize; ++k)
-      lookaheadset[k] |= LA (i)[k];
+      lookaheadset[k] |= LA (state->lookaheadsp + i)[k];
 
   for (k = 0; k < tokensetsize; ++k)
     lookaheadset[k] &= shiftset[k];
@@ -259,23 +253,20 @@ count_sr_conflicts (int state)
 `----------------------------------------------*/
 
 static int
-count_rr_conflicts (int state)
+count_rr_conflicts (state_t *state)
 {
   int i;
   int rrc_count = 0;
 
-  int m = state_table[state]->lookaheadsp;
-  int n = state_table[state + 1]->lookaheadsp;
-
-  if (n - m < 2)
+  if (state->nlookaheads < 2)
     return 0;
 
   for (i = 0; i < ntokens; i++)
     {
       int count = 0;
       int j;
-      for (j = m; j < n; j++)
-	if (BITISSET (LA (m), j))
+      for (j = 0; j < state->nlookaheads; ++j)
+	if (BITISSET (LA (state->lookaheadsp), state->lookaheadsp + j))
 	  count++;
 
       if (count >= 2)
@@ -337,8 +328,8 @@ conflicts_output (FILE *out)
     if (conflicts[i])
       {
 	fprintf (out, _("State %d contains "), i);
-	fputs (conflict_report (count_sr_conflicts (i),
-				count_rr_conflicts (i)), out);
+	fputs (conflict_report (count_sr_conflicts (state_table[i]),
+				count_rr_conflicts (state_table[i])), out);
 	printed_sth = TRUE;
       }
   if (printed_sth)
@@ -367,8 +358,8 @@ conflicts_print (void)
   for (i = 0; i < nstates; i++)
     if (conflicts[i])
       {
-	src_total += count_sr_conflicts (i);
-	rrc_total += count_rr_conflicts (i);
+	src_total += count_sr_conflicts (state_table[i]);
+	rrc_total += count_rr_conflicts (state_table[i]);
       }
 
   src_ok = src_total == (expected_conflicts == -1 ? 0 : expected_conflicts);
@@ -410,13 +401,11 @@ conflicts_print (void)
 
 
 void
-print_reductions (FILE *out, int state)
+print_reductions (FILE *out, state_t *state)
 {
   int i;
-  int m = state_table[state]->lookaheadsp;
-  int n = state_table[state + 1]->lookaheadsp;
-  shifts *shiftp = state_table[state]->shifts;
-  errs *errp = state_table[state]->errs;
+  shifts *shiftp = state->shifts;
+  errs *errp = state->errs;
   int nodefault = 0;
 
   for (i = 0; i < tokensetsize; i++)
@@ -437,13 +426,13 @@ print_reductions (FILE *out, int state)
       if (errp->errs[i])
 	SETBIT (shiftset, errp->errs[i]);
 
-  if (n - m == 1 && !nodefault)
+  if (state->nlookaheads == 1 && !nodefault)
     {
       int k;
-      int default_rule = LAruleno[m];
+      int default_rule = LAruleno[state->lookaheadsp];
 
       for (k = 0; k < tokensetsize; ++k)
-	lookaheadset[k] = LA (m)[k] & shiftset[k];
+	lookaheadset[k] = LA (state->lookaheadsp)[k] & shiftset[k];
 
       for (i = 0; i < ntokens; i++)
 	if (BITISSET (lookaheadset, i))
@@ -454,20 +443,20 @@ print_reductions (FILE *out, int state)
       fprintf (out, _("    $default\treduce using rule %d (%s)\n\n"),
 	       default_rule, tags[rule_table[default_rule].lhs]);
     }
-  else if (n - m >= 1)
+  else if (state->nlookaheads >= 1)
     {
       int cmax = 0;
       int default_LA = -1;
       int default_rule = 0;
 
       if (!nodefault)
-	for (i = m; i < n; i++)
+	for (i = 0; i < state->nlookaheads; ++i)
 	  {
 	    int count = 0;
 	    int j, k;
 
 	    for (k = 0; k < tokensetsize; ++k)
-	      lookaheadset[k] = LA (i)[k] & ~shiftset[k];
+	      lookaheadset[k] = LA (state->lookaheadsp + i)[k] & ~shiftset[k];
 
 	    for (j = 0; j < ntokens; j++)
 	      if (BITISSET (lookaheadset, j))
@@ -476,8 +465,8 @@ print_reductions (FILE *out, int state)
 	    if (count > cmax)
 	      {
 		cmax = count;
-		default_LA = i;
-		default_rule = LAruleno[i];
+		default_LA = state->lookaheadsp + i;
+		default_rule = LAruleno[state->lookaheadsp + i];
 	      }
 
 	    for (k = 0; k < tokensetsize; ++k)
@@ -497,18 +486,18 @@ print_reductions (FILE *out, int state)
 	  int defaulted = 0;
 	  int count = BITISSET (shiftset, i);
 
-	  for (j = m; j < n; j++)
+	  for (j = 0; j < state->nlookaheads; ++j)
 	    {
-	      if (BITISSET (LA (j), i))
+	      if (BITISSET (LA (state->lookaheadsp + j), i))
 		{
 		  if (count == 0)
 		    {
-		      if (j != default_LA)
+		      if (state->lookaheadsp + j != default_LA)
 			fprintf (out,
 				 _("    %-4s\treduce using rule %d (%s)\n"),
 				 tags[i],
-				 LAruleno[j],
-				 tags[rule_table[LAruleno[j]].lhs]);
+				 LAruleno[state->lookaheadsp + j],
+				 tags[rule_table[LAruleno[state->lookaheadsp + j]].lhs]);
 		      else
 			defaulted = 1;
 
@@ -526,8 +515,8 @@ print_reductions (FILE *out, int state)
 		      fprintf (out,
 			       _("    %-4s\t[reduce using rule %d (%s)]\n"),
 			       tags[i],
-			       LAruleno[j],
-			       tags[rule_table[LAruleno[j]].lhs]);
+			       LAruleno[state->lookaheadsp + j],
+			       tags[rule_table[LAruleno[state->lookaheadsp + j]].lhs]);
 		    }
 		}
 	    }
