@@ -355,7 +355,7 @@ action_row (int state)
 
   default_rule = 0;
   nreds = 0;
-  redp = state_table[state].reduction_table;
+  redp = state_table[state].reductions;
 
   if (redp)
     {
@@ -382,7 +382,7 @@ action_row (int state)
   /* Now see which tokens are allowed for shifts in this state.  For
      them, record the shift as the thing to do.  So shift is preferred
      to reduce.  */
-  shiftp = state_table[state].shift_table;
+  shiftp = state_table[state].shifts;
   for (i = 0; i < shiftp->nshifts; i++)
     {
       shift_state = shiftp->shifts[i];
@@ -404,7 +404,7 @@ action_row (int state)
 
   /* See which tokens are an explicit error in this state (due to
      %nonassoc).  For them, record MINSHORT as the action.  */
-  errp = err_table[state];
+  errp = state_table[state].errs;
 
   if (errp)
     {
