@@ -430,7 +430,7 @@ action_row (state_t *state)
   int i;
   int default_rule = 0;
   reductions *redp = state->reductions;
-  shifts *shiftp = state->shifts;
+  shifts_t *shiftp = state->shifts;
   errs *errp = state->errs;
   /* set nonzero to inhibit having any default reduction */
   int nodefault = 0;
