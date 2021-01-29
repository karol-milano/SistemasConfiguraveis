@@ -48,6 +48,19 @@ print_token (int extnum, int token)
 #endif
 
 
+
+/*---------------------------------------.
+| *WIDTH := max (*WIDTH, strlen (STR)).  |
+`---------------------------------------*/
+
+static void
+max_length (size_t *width, const char *str)
+{
+  size_t len = strlen (str);
+  if (len > *width)
+    *width = len;
+}
+
 /*--------------------------------.
 | Report information on a state.  |
 `--------------------------------*/
@@ -71,6 +84,8 @@ print_core (FILE *out, state_t *state)
   if (!snritems)
     return;
 
+  fputc ('\n', out);
+
   for (i = 0; i < snritems; i++)
     {
       item_number_t *sp;
@@ -99,70 +114,92 @@ print_core (FILE *out, state_t *state)
 
       fputc ('\n', out);
     }
-
-  fputc ('\n', out);
 }
 
 
+/*----------------------------------------------------------------.
+| Report the shifts iff DISPLAY_SHIFTS_P or the gotos of STATE on |
+| OUT.                                                            |
+`----------------------------------------------------------------*/
+
 static void
-print_shifts (FILE *out, state_t *state)
+print_transitions (state_t *state, FILE *out, bool display_shifts_p)
 {
-  int i;
   shifts_t *shiftp = state->shifts;
+  size_t width = 0;
+  int i;
 
-  for (i = 0; i < shiftp->nshifts && SHIFT_IS_SHIFT (shiftp, i); i++)
-    if (!SHIFT_IS_DISABLED (shiftp, i))
+  /* Compute the width of the lookaheads column.  */
+  for (i = 0; i < shiftp->nshifts; i++)
+    if (!SHIFT_IS_DISABLED (shiftp, i)
+	&& SHIFT_IS_SHIFT (shiftp, i) == display_shifts_p)
       {
-	state_number_t state1 = shiftp->shifts[i];
-	symbol_number_t symbol = states[state1]->accessing_symbol;
-	fprintf (out,
-		 _("    %-4s\tshift, and go to state %d\n"),
-		 symbol_tag_get (symbols[symbol]), state1);
+	symbol_t *symbol = symbols[SHIFT_SYMBOL (shiftp, i)];
+	max_length (&width, symbol_tag_get (symbol));
       }
 
-  if (i > 0)
-    fputc ('\n', out);
+  /* Nothing to report. */
+  if (!width)
+    return;
+
+  fputc ('\n', out);
+  width += 2;
+
+  /* Report lookaheads and shifts.  */
+  for (i = 0; i < shiftp->nshifts; i++)
+    if (!SHIFT_IS_DISABLED (shiftp, i)
+	&& SHIFT_IS_SHIFT (shiftp, i) == display_shifts_p)
+      {
+	symbol_t *symbol = symbols[SHIFT_SYMBOL (shiftp, i)];
+	const char *tag = symbol_tag_get (symbol);
+	state_number_t state1 = shiftp->shifts[i];
+	int j;
+
+	fprintf (out, "    %s", tag);
+	for (j = width - strlen (tag); j > 0; --j)
+	  fputc (' ', out);
+	if (display_shifts_p)
+	  fprintf (out, _("shift, and go to state %d\n"), state1);
+	else
+	  fprintf (out, _("go to state %d\n"), state1);
+      }
 }
 
 
+/*------------------------------------------------------------.
+| Report the explicit errors of STATE raised from %nonassoc.  |
+`------------------------------------------------------------*/
+
 static void
 print_errs (FILE *out, state_t *state)
 {
   errs_t *errp = state->errs;
+  size_t width = 0;
   int i;
 
+  /* Compute the width of the lookaheads column.  */
   for (i = 0; i < errp->nerrs; ++i)
     if (errp->errs[i])
-      fprintf (out, _("    %-4s\terror (nonassociative)\n"),
-	       symbol_tag_get (symbols[errp->errs[i]]));
-
-  if (i > 0)
-    fputc ('\n', out);
-}
-
-
-static void
-print_gotos (FILE *out, state_t *state)
-{
-  int i;
-  shifts_t *shiftp = state->shifts;
+      max_length (&width, symbol_tag_get (symbols[errp->errs[i]]));
 
-  for (i = 0; i < shiftp->nshifts && SHIFT_IS_SHIFT (shiftp, i); i++)
-    /* Skip token shifts.  */;
+  /* Nothing to report. */
+  if (!width)
+    return;
 
-  if (i < shiftp->nshifts)
-    {
-      for (; i < shiftp->nshifts; i++)
-	if (!SHIFT_IS_DISABLED (shiftp, i))
-	  {
-	    state_number_t state1 = shiftp->shifts[i];
-	    symbol_number_t symbol = states[state1]->accessing_symbol;
-	    fprintf (out, _("    %-4s\tgo to state %d\n"),
-		     symbol_tag_get (symbols[symbol]), state1);
-	  }
+  fputc ('\n', out);
+  width += 2;
 
-      fputc ('\n', out);
-    }
+  /* Report lookaheads and errors.  */
+  for (i = 0; i < errp->nerrs; ++i)
+    if (errp->errs[i])
+      {
+	const char *tag = symbol_tag_get (symbols[errp->errs[i]]);
+	int j;
+	fprintf (out, "    %s", tag);
+	for (j = width - strlen (tag); j > 0; --j)
+	  fputc (' ', out);
+	fputs (_("error (nonassociative)\n"), out);
+      }
 }
 
 
@@ -172,7 +209,7 @@ print_gotos (FILE *out, state_t *state)
 `----------------------------------------------------------*/
 
 static rule_t *
-state_default_rule_compute (state_t *state)
+state_default_rule (state_t *state)
 {
   reductions_t *redp = state->reductions;
   rule_t *default_rule = NULL;
@@ -233,6 +270,31 @@ state_default_rule_compute (state_t *state)
 }
 
 
+/*--------------------------------------------------------------------.
+| Report a reduction of RULE on LOOKAHEADS (which can be `default').  |
+| If not ENABLED, the rule is masked by a shift or a reduce (S/R and  |
+| R/R conflicts).                                                     |
+`--------------------------------------------------------------------*/
+
+static void
+print_reduction (FILE *out, size_t width,
+		 const char *lookahead,
+		 rule_t *rule, bool enabled)
+{
+  int j;
+  fprintf (out, "    %s", lookahead);
+  for (j = width - strlen (lookahead); j > 0; --j)
+    fputc (' ', out);
+  if (!enabled)
+    fputc ('[', out);
+  fprintf (out, _("reduce using rule %d (%s)"),
+	   rule->number - 1, symbol_tag_get (rule->lhs));
+  if (!enabled)
+    fputc (']', out);
+  fputc ('\n', out);
+}
+
+
 /*----------------------------------------------------.
 | Report on OUT the reduction actions of this STATE.  |
 `----------------------------------------------------*/
@@ -240,24 +302,55 @@ state_default_rule_compute (state_t *state)
 static void
 print_reductions (FILE *out, state_t *state)
 {
-  int i;
   shifts_t *shiftp = state->shifts;
   reductions_t *redp = state->reductions;
   rule_t *default_rule = NULL;
+  size_t width = 0;
+  int i, j;
 
   if (redp->nreds == 0)
     return;
 
-  default_rule = state_default_rule_compute (state);
+  default_rule = state_default_rule (state);
 
   bitset_zero (shiftset);
   for (i = 0; i < shiftp->nshifts && SHIFT_IS_SHIFT (shiftp, i); i++)
     if (!SHIFT_IS_DISABLED (shiftp, i))
       bitset_set (shiftset, SHIFT_SYMBOL (shiftp, i));
 
+  /* Compute the width of the lookaheads column.  */
+  if (default_rule)
+    width = strlen (_("$default"));
+  for (i = 0; i < ntokens; i++)
+    {
+      int count = bitset_test (shiftset, i);
+
+      for (j = 0; j < state->nlookaheads; ++j)
+	if (bitset_test (state->lookaheads[j], i))
+	  {
+	    if (count == 0)
+	      {
+		if (state->lookaheads_rule[j] != default_rule)
+		  max_length (&width, symbol_tag_get (symbols[i]));
+		count++;
+	      }
+	    else
+	      {
+		max_length (&width, symbol_tag_get (symbols[i]));
+	      }
+	  }
+    }
+
+  /* Nothing to report. */
+  if (!width)
+    return;
+
+  fputc ('\n', out);
+  width += 2;
+
+  /* Report lookaheads (or $default) and reductions.  */
   for (i = 0; i < ntokens; i++)
     {
-      int j;
       int defaulted = 0;
       int count = bitset_test (shiftset, i);
 
@@ -267,11 +360,9 @@ print_reductions (FILE *out, state_t *state)
 	    if (count == 0)
 	      {
 		if (state->lookaheads_rule[j] != default_rule)
-		  fprintf (out,
-			   _("    %-4s\treduce using rule %d (%s)\n"),
-			   symbol_tag_get (symbols[i]),
-			   state->lookaheads_rule[j]->number - 1,
-			   symbol_tag_get_n (state->lookaheads_rule[j]->lhs, 1));
+		  print_reduction (out, width,
+				   symbol_tag_get (symbols[i]),
+				   state->lookaheads_rule[j], TRUE);
 		else
 		  defaulted = 1;
 		count++;
@@ -279,26 +370,20 @@ print_reductions (FILE *out, state_t *state)
 	    else
 	      {
 		if (defaulted)
-		  fprintf (out,
-			   _("    %-4s\treduce using rule %d (%s)\n"),
-			   symbol_tag_get (symbols[i]),
-			   default_rule->number - 1,
-			   symbol_tag_get_n (default_rule->lhs, 1));
+		  print_reduction (out, width,
+				   symbol_tag_get (symbols[i]),
+				   default_rule, TRUE);
 		defaulted = 0;
-		fprintf (out,
-			 _("    %-4s\t[reduce using rule %d (%s)]\n"),
-			 symbol_tag_get (symbols[i]),
-			 state->lookaheads_rule[j]->number - 1,
-			 symbol_tag_get_n (state->lookaheads_rule[j]->lhs, 1));
+		print_reduction (out, width,
+				 symbol_tag_get (symbols[i]),
+				 state->lookaheads_rule[j], FALSE);
 	      }
 	  }
     }
 
   if (default_rule)
-    fprintf (out, _("    $default\treduce using rule %d (%s)\n"),
-	     default_rule->number - 1,
-	     symbol_tag_get (default_rule->lhs));
-  fputc ('\n', out);
+    print_reduction (out, width,
+		     _("$default"), default_rule, TRUE);
 }
 
 
@@ -315,6 +400,7 @@ print_actions (FILE *out, state_t *state)
 
   if (shiftp->nshifts == 0 && redp->nreds == 0)
     {
+      fputc ('\n', out);
       if (state->number == final_state->number)
 	fprintf (out, _("    $default\taccept\n"));
       else
@@ -322,24 +408,30 @@ print_actions (FILE *out, state_t *state)
       return;
     }
 
-  print_shifts (out, state);
+  /* Print shifts.  */
+  print_transitions (state, out, TRUE);
   print_errs (out, state);
   print_reductions (out, state);
-  print_gotos (out, state);
+  /* Print gotos.  */
+  print_transitions (state, out, FALSE);
 }
 
 
+/*--------------------------------------.
+| Report all the data on STATE on OUT.  |
+`--------------------------------------*/
+
 static void
 print_state (FILE *out, state_t *state)
 {
-  fprintf (out, _("state %d"), state->number);
   fputs ("\n\n", out);
+  fprintf (out, _("state %d"), state->number);
+  fputc ('\n', out);
   print_core (out, state);
   print_actions (out, state);
   if ((report_flag & report_solved_conflicts)
       && state->solved_conflicts)
     fputs (state->solved_conflicts, out);
-  fputs ("\n\n", out);
 }
 
 /*-----------------------------------------.
@@ -453,7 +545,6 @@ print_grammar (FILE *out)
 	}
       fprintf (out, "%s\n", buffer);
     }
-  fputs ("\n\n", out);
 }
 
 void
