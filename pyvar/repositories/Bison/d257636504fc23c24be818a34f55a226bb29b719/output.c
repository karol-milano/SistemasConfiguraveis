@@ -439,7 +439,7 @@ action_row (state_t *state)
   for (i = 0; i < ntokens; i++)
     actrow[i] = conflrow[i] = 0;
 
-  if (redp->nreds >= 1)
+  if (redp->num >= 1)
     {
       int j;
       /* loop over all the rules available here which require
@@ -478,16 +478,16 @@ action_row (state_t *state)
 
   /* See which tokens are an explicit error in this state (due to
      %nonassoc).  For them, record SHRT_MIN as the action.  */
-  for (i = 0; i < errp->nerrs; i++)
+  for (i = 0; i < errp->num; i++)
     {
-      int symbol = errp->errs[i];
+      symbol_number_t symbol = errp->symbols[i];
       actrow[symbol] = SHRT_MIN;
     }
 
   /* Now find the most common reduction and make it the default action
      for this state.  */
 
-  if (redp->nreds >= 1 && !nodefault)
+  if (redp->num >= 1 && !nodefault)
     {
       if (state->consistent)
 	default_rule = redp->rules[0];
