@@ -430,7 +430,7 @@ action_row (state_t *state)
   int i;
   rule_number_t default_rule = 0;
   reductions_t *redp = state->reductions;
-  transitions_t *transitions = state->shifts;
+  transitions_t *transitions = state->transitions;
   errs_t *errp = state->errs;
   /* set nonzero to inhibit having any default reduction */
   int nodefault = 0;
