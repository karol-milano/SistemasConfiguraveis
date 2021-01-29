@@ -139,13 +139,13 @@ log_resolution (rule_t *rule, int token,
 static void
 flush_shift (state_t *state, int token)
 {
-  shifts_t *shiftp = state->shifts;
+  transitions_t *transitions = state->shifts;
   int i;
 
   bitset_reset (lookaheadset, token);
-  for (i = 0; i < shiftp->nshifts; i++)
-    if (!SHIFT_IS_DISABLED (shiftp, i) && SHIFT_SYMBOL (shiftp, i) == token)
-      SHIFT_DISABLE (shiftp, i);
+  for (i = 0; i < transitions->num; i++)
+    if (!TRANSITION_IS_DISABLED (transitions, i) && TRANSITION_SYMBOL (transitions, i) == token)
+      TRANSITION_DISABLE (transitions, i);
 }
 
 
@@ -249,17 +249,17 @@ static void
 set_conflicts (state_t *state)
 {
   int i;
-  shifts_t *shiftp;
+  transitions_t *transitions;
 
   if (state->consistent)
     return;
 
   bitset_zero (lookaheadset);
 
-  shiftp = state->shifts;
-  for (i = 0; i < shiftp->nshifts && SHIFT_IS_SHIFT (shiftp, i); i++)
-    if (!SHIFT_IS_DISABLED (shiftp, i))
-      bitset_set (lookaheadset, SHIFT_SYMBOL (shiftp, i));
+  transitions = state->shifts;
+  for (i = 0; i < transitions->num && TRANSITION_IS_SHIFT (transitions, i); i++)
+    if (!TRANSITION_IS_DISABLED (transitions, i))
+      bitset_set (lookaheadset, TRANSITION_SYMBOL (transitions, i));
 
   /* Loop over all rules which require lookahead in this state.  First
      check for shift-reduce conflict, and try to resolve using
@@ -308,17 +308,17 @@ count_sr_conflicts (state_t *state)
 {
   int i;
   int src_count = 0;
-  shifts_t *shiftp = state->shifts;
+  transitions_t *transitions = state->shifts;
 
-  if (!shiftp)
+  if (!transitions)
     return 0;
 
   bitset_zero (lookaheadset);
   bitset_zero (shiftset);
 
-  for (i = 0; i < shiftp->nshifts && SHIFT_IS_SHIFT (shiftp, i); i++)
-    if (!SHIFT_IS_DISABLED (shiftp, i))
-      bitset_set (shiftset, SHIFT_SYMBOL (shiftp, i));
+  for (i = 0; i < transitions->num && TRANSITION_IS_SHIFT (transitions, i); i++)
+    if (!TRANSITION_IS_DISABLED (transitions, i))
+      bitset_set (shiftset, TRANSITION_SYMBOL (transitions, i));
 
   for (i = 0; i < state->nlookaheads; ++i)
     bitset_or (lookaheadset, lookaheadset, state->lookaheads[i]);
