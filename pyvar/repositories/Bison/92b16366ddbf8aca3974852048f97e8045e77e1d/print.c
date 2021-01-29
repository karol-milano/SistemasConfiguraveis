@@ -98,9 +98,9 @@ print_actions (FILE *out, int state)
 {
   int i;
 
-  shifts   *shiftp = state_table[state].shift_table;
-  reductions *redp = state_table[state].reduction_table;
-  errs       *errp = err_table[state];
+  shifts   *shiftp = state_table[state].shifts;
+  reductions *redp = state_table[state].reductions;
+  errs       *errp = state_table[state].errs;
 
   if (!shiftp->nshifts && !redp)
     {
