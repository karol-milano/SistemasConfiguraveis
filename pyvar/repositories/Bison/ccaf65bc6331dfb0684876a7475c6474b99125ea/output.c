@@ -430,7 +430,7 @@ action_row (state_t *state)
   int i;
   rule_number_t default_rule = 0;
   reductions_t *redp = state->reductions;
-  shifts_t *shiftp = state->shifts;
+  transitions_t *transitions = state->shifts;
   errs_t *errp = state->errs;
   /* set nonzero to inhibit having any default reduction */
   int nodefault = 0;
@@ -460,11 +460,11 @@ action_row (state_t *state)
   /* Now see which tokens are allowed for shifts in this state.  For
      them, record the shift as the thing to do.  So shift is preferred
      to reduce.  */
-  for (i = 0; i < shiftp->nshifts && SHIFT_IS_SHIFT (shiftp, i); i++)
-    if (!SHIFT_IS_DISABLED (shiftp, i))
+  for (i = 0; i < transitions->num && TRANSITION_IS_SHIFT (transitions, i); i++)
+    if (!TRANSITION_IS_DISABLED (transitions, i))
       {
-	symbol_number_t symbol = SHIFT_SYMBOL (shiftp, i);
-	state_number_t shift_state = shiftp->shifts[i];
+	symbol_number_t symbol = TRANSITION_SYMBOL (transitions, i);
+	state_number_t shift_state = transitions->states[i];
 
 	if (actrow[symbol] != 0)
 	  conflicted = conflrow[symbol] = 1;
