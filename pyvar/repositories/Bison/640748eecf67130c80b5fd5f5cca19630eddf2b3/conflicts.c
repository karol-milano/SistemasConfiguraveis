@@ -176,7 +176,7 @@ flush_reduce (bitset lookaheads, int token)
 
 static void
 resolve_sr_conflict (state_t *state, int lookahead,
-		     symbol_number_t *errs)
+		     symbol_t **errs)
 {
   symbol_number_t i;
   /* Find the rule to reduce by to get precedence of reduction.  */
@@ -226,7 +226,7 @@ resolve_sr_conflict (state_t *state, int lookahead,
 	      flush_shift (state, i);
 	      flush_reduce (lookaheads, i);
 	      /* Record an explicit error for this token.  */
-	      errs[nerrs++] = i;
+	      errs[nerrs++] = symbols[i];
 	      break;
 
 	    case undef_assoc:
@@ -255,7 +255,7 @@ resolve_sr_conflict (state_t *state, int lookahead,
 `-------------------------------------------------------------------*/
 
 static void
-set_conflicts (state_t *state, symbol_number_t *errs)
+set_conflicts (state_t *state, symbol_t **errs)
 {
   int i;
   transitions_t *transitions = state->transitions;
@@ -265,9 +265,8 @@ set_conflicts (state_t *state, symbol_number_t *errs)
 
   bitset_zero (lookaheadset);
 
-  for (i = 0; i < transitions->num && TRANSITION_IS_SHIFT (transitions, i); i++)
-    if (!TRANSITION_IS_DISABLED (transitions, i))
-      bitset_set (lookaheadset, TRANSITION_SYMBOL (transitions, i));
+  FOR_EACH_SHIFT (transitions, i)
+    bitset_set (lookaheadset, TRANSITION_SYMBOL (transitions, i));
 
   /* Loop over all rules which require lookahead in this state.  First
      check for shift-reduce conflict, and try to resolve using
@@ -303,7 +302,7 @@ conflicts_solve (void)
 {
   state_number_t i;
   /* List of lookaheads on which we explicitly raise a parse error.  */
-  symbol_number_t *errs = XMALLOC (symbol_number_t, ntokens + 1);
+  symbol_t **errs = XMALLOC (symbol_t *, ntokens + 1);
 
   conflicts = XCALLOC (char, nstates);
   shiftset = bitset_create (ntokens, BITSET_FIXED);
@@ -341,9 +340,8 @@ count_sr_conflicts (state_t *state)
   bitset_zero (lookaheadset);
   bitset_zero (shiftset);
 
-  for (i = 0; i < transitions->num && TRANSITION_IS_SHIFT (transitions, i); i++)
-    if (!TRANSITION_IS_DISABLED (transitions, i))
-      bitset_set (shiftset, TRANSITION_SYMBOL (transitions, i));
+  FOR_EACH_SHIFT (transitions, i)
+    bitset_set (shiftset, TRANSITION_SYMBOL (transitions, i));
 
   for (i = 0; i < state->nlookaheads; ++i)
     bitset_or (lookaheadset, lookaheadset, state->lookaheads[i]);
@@ -434,17 +432,41 @@ void
 conflicts_output (FILE *out)
 {
   bool printed_sth = FALSE;
+  bool *used_rules = XCALLOC (bool, nrules);
   state_number_t i;
   for (i = 0; i < nstates; i++)
-    if (conflicts[i])
-      {
-	fprintf (out, _("State %d contains "), i);
-	fputs (conflict_report (count_sr_conflicts (states[i]),
-				count_rr_conflicts (states[i], TRUE)), out);
-	printed_sth = TRUE;
-      }
+    {
+      state_t *s = states[i];
+      int j;
+      for (j = 0; j < s->reductions->num; ++j)
+	used_rules[s->reductions->rules[j]->number] = TRUE;
+      if (conflicts[i])
+	{
+	  fprintf (out, _("State %d contains "), i);
+	  fputs (conflict_report (count_sr_conflicts (s),
+				  count_rr_conflicts (s, TRUE)), out);
+	  printed_sth = TRUE;
+	}
+    }
   if (printed_sth)
     fputs ("\n\n", out);
+
+  for (i = 0; i < nstates; i++)
+    {
+      state_t *s = states[i];
+      reductions_t *r = s->reductions;
+      int j;
+      for (j = 0; j < r->num; ++j)
+	if (!used_rules[r->rules[j]->number])
+	  {
+	    LOCATION_PRINT (stderr, r->rules[j]->location);
+	    fprintf (stderr, ": %s: %s: ",
+		     _("warning"),
+		     _("rule never reduced because of conflicts"));
+	    rule_print (r->rules[j], stderr);
+	  }
+    }
+  free (used_rules);
 }
 
 /*--------------------------------------------------------.
