@@ -103,10 +103,10 @@ print_core (FILE *out, state_t *state)
       previous_lhs = rules[rule].lhs;
 
       for (sp = rules[rule].rhs; sp < sp1; sp++)
-	fprintf (out, " %s", symbol_tag_get (symbols[*sp]));
+	fprintf (out, " %s", symbols[*sp]->tag);
       fputs (" .", out);
       for (/* Nothing */; *sp >= 0; ++sp)
-	fprintf (out, " %s", symbol_tag_get (symbols[*sp]));
+	fprintf (out, " %s", symbols[*sp]->tag);
 
       /* Display the lookaheads?  */
       if (report_flag & report_lookaheads)
@@ -135,7 +135,7 @@ print_transitions (state_t *state, FILE *out, bool display_transitions_p)
 	&& TRANSITION_IS_SHIFT (transitions, i) == display_transitions_p)
       {
 	symbol_t *symbol = symbols[TRANSITION_SYMBOL (transitions, i)];
-	max_length (&width, symbol_tag_get (symbol));
+	max_length (&width, symbol->tag);
       }
 
   /* Nothing to report. */
@@ -151,7 +151,7 @@ print_transitions (state_t *state, FILE *out, bool display_transitions_p)
 	&& TRANSITION_IS_SHIFT (transitions, i) == display_transitions_p)
       {
 	symbol_t *symbol = symbols[TRANSITION_SYMBOL (transitions, i)];
-	const char *tag = symbol_tag_get (symbol);
+	const char *tag = symbol->tag;
 	state_number_t state1 = transitions->states[i];
 	int j;
 
@@ -180,7 +180,7 @@ print_errs (FILE *out, state_t *state)
   /* Compute the width of the lookaheads column.  */
   for (i = 0; i < errp->num; ++i)
     if (errp->symbols[i])
-      max_length (&width, symbol_tag_get (symbols[errp->symbols[i]]));
+      max_length (&width, symbols[errp->symbols[i]]->tag);
 
   /* Nothing to report. */
   if (!width)
@@ -193,7 +193,7 @@ print_errs (FILE *out, state_t *state)
   for (i = 0; i < errp->num; ++i)
     if (errp->symbols[i])
       {
-	const char *tag = symbol_tag_get (symbols[errp->symbols[i]]);
+	const char *tag = symbols[errp->symbols[i]]->tag;
 	int j;
 	fprintf (out, "    %s", tag);
 	for (j = width - strlen (tag); j > 0; --j)
@@ -288,7 +288,7 @@ print_reduction (FILE *out, size_t width,
   if (!enabled)
     fputc ('[', out);
   fprintf (out, _("reduce using rule %d (%s)"),
-	   rule->number - 1, symbol_tag_get (rule->lhs));
+	   rule->number - 1, rule->lhs->tag);
   if (!enabled)
     fputc (']', out);
   fputc ('\n', out);
@@ -331,12 +331,12 @@ print_reductions (FILE *out, state_t *state)
 	    if (count == 0)
 	      {
 		if (state->lookaheads_rule[j] != default_rule)
-		  max_length (&width, symbol_tag_get (symbols[i]));
+		  max_length (&width, symbols[i]->tag);
 		count++;
 	      }
 	    else
 	      {
-		max_length (&width, symbol_tag_get (symbols[i]));
+		max_length (&width, symbols[i]->tag);
 	      }
 	  }
     }
@@ -361,7 +361,7 @@ print_reductions (FILE *out, state_t *state)
 	      {
 		if (state->lookaheads_rule[j] != default_rule)
 		  print_reduction (out, width,
-				   symbol_tag_get (symbols[i]),
+				   symbols[i]->tag,
 				   state->lookaheads_rule[j], TRUE);
 		else
 		  defaulted = 1;
@@ -371,11 +371,11 @@ print_reductions (FILE *out, state_t *state)
 	      {
 		if (defaulted)
 		  print_reduction (out, width,
-				   symbol_tag_get (symbols[i]),
+				   symbols[i]->tag,
 				   default_rule, TRUE);
 		defaulted = 0;
 		print_reduction (out, width,
-				 symbol_tag_get (symbols[i]),
+				 symbols[i]->tag,
 				 state->lookaheads_rule[j], FALSE);
 	      }
 	  }
@@ -463,7 +463,7 @@ print_grammar (FILE *out)
   for (i = 0; i < max_user_token_number + 1; i++)
     if (token_translations[i] != undeftoken->number)
       {
-	const char *tag = symbol_tag_get (symbols[token_translations[i]]);
+	const char *tag = symbols[token_translations[i]]->tag;
 	rule_number_t r;
 	item_number_t *rhsp;
 
@@ -491,7 +491,7 @@ print_grammar (FILE *out)
     {
       int left_count = 0, right_count = 0;
       rule_number_t r;
-      const char *tag = symbol_tag_get (symbols[i]);
+      const char *tag = symbols[i]->tag;
 
       for (r = 1; r < nrules + 1; r++)
 	{
