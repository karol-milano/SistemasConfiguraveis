@@ -152,16 +152,16 @@ print_transitions (state_t *state, FILE *out, bool display_transitions_p)
       {
 	symbol_t *symbol = symbols[TRANSITION_SYMBOL (transitions, i)];
 	const char *tag = symbol->tag;
-	state_number_t state1 = transitions->states[i];
+	state_t *state1 = transitions->states[i];
 	int j;
 
 	fprintf (out, "    %s", tag);
 	for (j = width - strlen (tag); j > 0; --j)
 	  fputc (' ', out);
 	if (display_transitions_p)
-	  fprintf (out, _("shift, and go to state %d\n"), state1);
+	  fprintf (out, _("shift, and go to state %d\n"), state1->number);
 	else
-	  fprintf (out, _("go to state %d\n"), state1);
+	  fprintf (out, _("go to state %d\n"), state1->number);
       }
 }
 
@@ -180,7 +180,7 @@ print_errs (FILE *out, state_t *state)
   /* Compute the width of the lookaheads column.  */
   for (i = 0; i < errp->num; ++i)
     if (errp->symbols[i])
-      max_length (&width, symbols[errp->symbols[i]]->tag);
+      max_length (&width, errp->symbols[i]->tag);
 
   /* Nothing to report. */
   if (!width)
@@ -193,7 +193,7 @@ print_errs (FILE *out, state_t *state)
   for (i = 0; i < errp->num; ++i)
     if (errp->symbols[i])
       {
-	const char *tag = symbols[errp->symbols[i]]->tag;
+	const char *tag = errp->symbols[i]->tag;
 	int j;
 	fprintf (out, "    %s", tag);
 	for (j = width - strlen (tag); j > 0; --j)
@@ -218,22 +218,21 @@ state_default_rule (state_t *state)
 
   /* No need for a lookahead.  */
   if (state->consistent)
-    return &rules[redp->rules[0]];
+    return redp->rules[0];
 
   /* 1. Each reduction is possibly masked by the lookaheads on which
      we shift (S/R conflicts)...  */
   bitset_zero (shiftset);
   {
     transitions_t *transitions = state->transitions;
-    for (i = 0; i < transitions->num && TRANSITION_IS_SHIFT (transitions, i); i++)
-      if (!TRANSITION_IS_DISABLED (transitions, i))
-	{
-	  /* If this state has a shift for the error token, don't use a
+    FOR_EACH_SHIFT (transitions, i)
+      {
+	/* If this state has a shift for the error token, don't use a
 	     default rule.  */
-	  if (TRANSITION_IS_ERROR (transitions, i))
-	    return NULL;
-	  bitset_set (shiftset, TRANSITION_SYMBOL (transitions, i));
-	}
+	if (TRANSITION_IS_ERROR (transitions, i))
+	  return NULL;
+	bitset_set (shiftset, TRANSITION_SYMBOL (transitions, i));
+      }
   }
 
   /* 2. Each reduction is possibly masked by the lookaheads on which
@@ -242,7 +241,7 @@ state_default_rule (state_t *state)
     errs_t *errp = state->errs;
     for (i = 0; i < errp->num; i++)
       if (errp->symbols[i])
-	bitset_set (shiftset, errp->symbols[i]);
+	bitset_set (shiftset, errp->symbols[i]->number);
   }
 
   for (i = 0; i < state->nlookaheads; ++i)
@@ -314,9 +313,8 @@ print_reductions (FILE *out, state_t *state)
   default_rule = state_default_rule (state);
 
   bitset_zero (shiftset);
-  for (i = 0; i < transitions->num && TRANSITION_IS_SHIFT (transitions, i); i++)
-    if (!TRANSITION_IS_DISABLED (transitions, i))
-      bitset_set (shiftset, TRANSITION_SYMBOL (transitions, i));
+  FOR_EACH_SHIFT (transitions, i)
+    bitset_set (shiftset, TRANSITION_SYMBOL (transitions, i));
 
   /* Compute the width of the lookaheads column.  */
   if (default_rule)
