@@ -326,7 +326,6 @@ action_row (state_t *state)
   int i;
   int default_rule = 0;
   reductions *redp = state->reductions;
-  int nreds = redp ? redp->nreds : 0;
   shifts *shiftp = state->shifts;
   errs *errp = state->errs;
   /* set nonzero to inhibit having any default reduction */
@@ -335,7 +334,7 @@ action_row (state_t *state)
   for (i = 0; i < ntokens; i++)
     actrow[i] = 0;
 
-  if (nreds >= 1)
+  if (redp->nreds >= 1)
     {
       int j;
       /* loop over all the rules available here which require
@@ -384,7 +383,7 @@ action_row (state_t *state)
   /* Now find the most common reduction and make it the default action
      for this state.  */
 
-  if (nreds >= 1 && !nodefault)
+  if (redp->nreds >= 1 && !nodefault)
     {
       if (state->consistent)
 	default_rule = redp->rules[0];
