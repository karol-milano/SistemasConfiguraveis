@@ -323,16 +323,14 @@ output_rule_data (void)
 `------------------------------------------------------------------*/
 
 static int
-action_row (int state)
+action_row (state_t *state)
 {
   int i;
-  int m = 0;
-  int n = 0;
   int default_rule = 0;
-  reductions *redp = state_table[state]->reductions;
+  reductions *redp = state->reductions;
   int nreds = redp ? redp->nreds : 0;
-  shifts *shiftp = state_table[state]->shifts;
-  errs *errp = state_table[state]->errs;
+  shifts *shiftp = state->shifts;
+  errs *errp = state->errs;
   /* set nonzero to inhibit having any default reduction */
   int nodefault = 0;
 
@@ -344,17 +342,14 @@ action_row (int state)
       int j;
       /* loop over all the rules available here which require
 	 lookahead */
-      m = state_table[state]->lookaheadsp;
-      n = state_table[state + 1]->lookaheadsp;
-
-      for (i = n - 1; i >= m; i--)
+      for (i = state->nlookaheads - 1; i >= 0; --i)
 	/* and find each token which the rule finds acceptable
 	   to come next */
 	for (j = 0; j < ntokens; j++)
 	  /* and record this rule as the rule to use if that
 	     token follows.  */
-	  if (BITISSET (LA (i), j))
-	    actrow[j] = -LAruleno[i];
+	  if (BITISSET (LA (state->lookaheadsp + i), j))
+	    actrow[j] = -LAruleno[state->lookaheadsp + i];
     }
 
   /* Now see which tokens are allowed for shifts in this state.  For
@@ -394,15 +389,15 @@ action_row (int state)
 
   if (nreds >= 1 && !nodefault)
     {
-      if (state_table[state]->consistent)
+      if (state->consistent)
 	default_rule = redp->rules[0];
       else
 	{
 	  int max = 0;
-	  for (i = m; i < n; i++)
+	  for (i = 0; i < state->nlookaheads; i++)
 	    {
 	      int count = 0;
-	      int rule = -LAruleno[i];
+	      int rule = -LAruleno[state->lookaheadsp + i];
 	      int j;
 
 	      for (j = 0; j < ntokens; j++)
@@ -492,7 +487,7 @@ token_actions (void)
   actrow = XCALLOC (short, ntokens);
   for (i = 0; i < nstates; ++i)
     {
-      yydefact[i] = action_row (i);
+      yydefact[i] = action_row (state_table[i]);
       save_row (i);
     }
 
