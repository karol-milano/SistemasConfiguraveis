@@ -429,9 +429,9 @@ action_row (state_t *state)
 {
   int i;
   int default_rule = 0;
-  reductions *redp = state->reductions;
+  reductions_t *redp = state->reductions;
   shifts_t *shiftp = state->shifts;
-  errs *errp = state->errs;
+  errs_t *errp = state->errs;
   /* set nonzero to inhibit having any default reduction */
   int nodefault = 0;
   int conflicted = 0;
