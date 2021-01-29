@@ -123,18 +123,18 @@ print_core (FILE *out, state_t *state)
 `----------------------------------------------------------------*/
 
 static void
-print_transitions (state_t *state, FILE *out, bool display_shifts_p)
+print_transitions (state_t *state, FILE *out, bool display_transitions_p)
 {
-  shifts_t *shiftp = state->shifts;
+  transitions_t *transitions = state->shifts;
   size_t width = 0;
   int i;
 
   /* Compute the width of the lookaheads column.  */
-  for (i = 0; i < shiftp->nshifts; i++)
-    if (!SHIFT_IS_DISABLED (shiftp, i)
-	&& SHIFT_IS_SHIFT (shiftp, i) == display_shifts_p)
+  for (i = 0; i < transitions->num; i++)
+    if (!TRANSITION_IS_DISABLED (transitions, i)
+	&& TRANSITION_IS_SHIFT (transitions, i) == display_transitions_p)
       {
-	symbol_t *symbol = symbols[SHIFT_SYMBOL (shiftp, i)];
+	symbol_t *symbol = symbols[TRANSITION_SYMBOL (transitions, i)];
 	max_length (&width, symbol_tag_get (symbol));
       }
 
@@ -146,19 +146,19 @@ print_transitions (state_t *state, FILE *out, bool display_shifts_p)
   width += 2;
 
   /* Report lookaheads and shifts.  */
-  for (i = 0; i < shiftp->nshifts; i++)
-    if (!SHIFT_IS_DISABLED (shiftp, i)
-	&& SHIFT_IS_SHIFT (shiftp, i) == display_shifts_p)
+  for (i = 0; i < transitions->num; i++)
+    if (!TRANSITION_IS_DISABLED (transitions, i)
+	&& TRANSITION_IS_SHIFT (transitions, i) == display_transitions_p)
       {
-	symbol_t *symbol = symbols[SHIFT_SYMBOL (shiftp, i)];
+	symbol_t *symbol = symbols[TRANSITION_SYMBOL (transitions, i)];
 	const char *tag = symbol_tag_get (symbol);
-	state_number_t state1 = shiftp->shifts[i];
+	state_number_t state1 = transitions->states[i];
 	int j;
 
 	fprintf (out, "    %s", tag);
 	for (j = width - strlen (tag); j > 0; --j)
 	  fputc (' ', out);
-	if (display_shifts_p)
+	if (display_transitions_p)
 	  fprintf (out, _("shift, and go to state %d\n"), state1);
 	else
 	  fprintf (out, _("go to state %d\n"), state1);
@@ -224,15 +224,15 @@ state_default_rule (state_t *state)
      we shift (S/R conflicts)...  */
   bitset_zero (shiftset);
   {
-    shifts_t *shiftp = state->shifts;
-    for (i = 0; i < shiftp->nshifts && SHIFT_IS_SHIFT (shiftp, i); i++)
-      if (!SHIFT_IS_DISABLED (shiftp, i))
+    transitions_t *transitions = state->shifts;
+    for (i = 0; i < transitions->num && TRANSITION_IS_SHIFT (transitions, i); i++)
+      if (!TRANSITION_IS_DISABLED (transitions, i))
 	{
 	  /* If this state has a shift for the error token, don't use a
 	     default rule.  */
-	  if (SHIFT_IS_ERROR (shiftp, i))
+	  if (TRANSITION_IS_ERROR (transitions, i))
 	    return NULL;
-	  bitset_set (shiftset, SHIFT_SYMBOL (shiftp, i));
+	  bitset_set (shiftset, TRANSITION_SYMBOL (transitions, i));
 	}
   }
 
@@ -302,7 +302,7 @@ print_reduction (FILE *out, size_t width,
 static void
 print_reductions (FILE *out, state_t *state)
 {
-  shifts_t *shiftp = state->shifts;
+  transitions_t *transitions = state->shifts;
   reductions_t *redp = state->reductions;
   rule_t *default_rule = NULL;
   size_t width = 0;
@@ -314,9 +314,9 @@ print_reductions (FILE *out, state_t *state)
   default_rule = state_default_rule (state);
 
   bitset_zero (shiftset);
-  for (i = 0; i < shiftp->nshifts && SHIFT_IS_SHIFT (shiftp, i); i++)
-    if (!SHIFT_IS_DISABLED (shiftp, i))
-      bitset_set (shiftset, SHIFT_SYMBOL (shiftp, i));
+  for (i = 0; i < transitions->num && TRANSITION_IS_SHIFT (transitions, i); i++)
+    if (!TRANSITION_IS_DISABLED (transitions, i))
+      bitset_set (shiftset, TRANSITION_SYMBOL (transitions, i));
 
   /* Compute the width of the lookaheads column.  */
   if (default_rule)
@@ -396,9 +396,9 @@ static void
 print_actions (FILE *out, state_t *state)
 {
   reductions_t *redp = state->reductions;
-  shifts_t *shiftp = state->shifts;
+  transitions_t *transitions = state->shifts;
 
-  if (shiftp->nshifts == 0 && redp->nreds == 0)
+  if (transitions->num == 0 && redp->nreds == 0)
     {
       fputc ('\n', out);
       if (state->number == final_state->number)
