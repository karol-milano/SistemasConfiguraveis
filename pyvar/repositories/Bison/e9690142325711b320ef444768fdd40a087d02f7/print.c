@@ -97,7 +97,7 @@ print_core (FILE *out, state *s)
       sp1 = sp = ritem + sitems[i];
 
       while (*sp >= 0)
-	sp++;
+        sp++;
 
       r = item_number_as_rule_number (*sp);
 
@@ -105,15 +105,15 @@ print_core (FILE *out, state *s)
       previous_lhs = rules[r].lhs;
 
       for (sp = rules[r].rhs; sp < sp1; sp++)
-	fprintf (out, " %s", symbols[*sp]->tag);
+        fprintf (out, " %s", symbols[*sp]->tag);
       fputs (" .", out);
       for (/* Nothing */; *sp >= 0; ++sp)
-	fprintf (out, " %s", symbols[*sp]->tag);
+        fprintf (out, " %s", symbols[*sp]->tag);
 
       /* Display the lookahead tokens?  */
       if (report_flag & report_lookahead_tokens
           && item_number_is_rule_number (*sp1))
-	state_rule_lookahead_tokens_print (s, &rules[r], out);
+        state_rule_lookahead_tokens_print (s, &rules[r], out);
 
       fputc ('\n', out);
     }
@@ -135,10 +135,10 @@ print_transitions (state *s, FILE *out, bool display_transitions_p)
   /* Compute the width of the lookahead token column.  */
   for (i = 0; i < trans->num; i++)
     if (!TRANSITION_IS_DISABLED (trans, i)
-	&& TRANSITION_IS_SHIFT (trans, i) == display_transitions_p)
+        && TRANSITION_IS_SHIFT (trans, i) == display_transitions_p)
       {
-	symbol *sym = symbols[TRANSITION_SYMBOL (trans, i)];
-	max_length (&width, sym->tag);
+        symbol *sym = symbols[TRANSITION_SYMBOL (trans, i)];
+        max_length (&width, sym->tag);
       }
 
   /* Nothing to report. */
@@ -151,20 +151,20 @@ print_transitions (state *s, FILE *out, bool display_transitions_p)
   /* Report lookahead tokens and shifts.  */
   for (i = 0; i < trans->num; i++)
     if (!TRANSITION_IS_DISABLED (trans, i)
-	&& TRANSITION_IS_SHIFT (trans, i) == display_transitions_p)
+        && TRANSITION_IS_SHIFT (trans, i) == display_transitions_p)
       {
-	symbol *sym = symbols[TRANSITION_SYMBOL (trans, i)];
-	const char *tag = sym->tag;
-	state *s1 = trans->states[i];
-	int j;
-
-	fprintf (out, "    %s", tag);
-	for (j = width - strlen (tag); j > 0; --j)
-	  fputc (' ', out);
-	if (display_transitions_p)
-	  fprintf (out, _("shift, and go to state %d\n"), s1->number);
-	else
-	  fprintf (out, _("go to state %d\n"), s1->number);
+        symbol *sym = symbols[TRANSITION_SYMBOL (trans, i)];
+        const char *tag = sym->tag;
+        state *s1 = trans->states[i];
+        int j;
+
+        fprintf (out, "    %s", tag);
+        for (j = width - strlen (tag); j > 0; --j)
+          fputc (' ', out);
+        if (display_transitions_p)
+          fprintf (out, _("shift, and go to state %d\n"), s1->number);
+        else
+          fprintf (out, _("go to state %d\n"), s1->number);
       }
 }
 
@@ -196,12 +196,12 @@ print_errs (FILE *out, state *s)
   for (i = 0; i < errp->num; ++i)
     if (errp->symbols[i])
       {
-	const char *tag = errp->symbols[i]->tag;
-	int j;
-	fprintf (out, "    %s", tag);
-	for (j = width - strlen (tag); j > 0; --j)
-	  fputc (' ', out);
-	fputs (_("error (nonassociative)\n"), out);
+        const char *tag = errp->symbols[i]->tag;
+        int j;
+        fprintf (out, "    %s", tag);
+        for (j = width - strlen (tag); j > 0; --j)
+          fputc (' ', out);
+        fputs (_("error (nonassociative)\n"), out);
       }
 }
 
@@ -214,8 +214,8 @@ print_errs (FILE *out, state *s)
 
 static void
 print_reduction (FILE *out, size_t width,
-		 const char *lookahead_token,
-		 rule *r, bool enabled)
+                 const char *lookahead_token,
+                 rule *r, bool enabled)
 {
   int j;
   fprintf (out, "    %s", lookahead_token);
@@ -267,22 +267,22 @@ print_reductions (FILE *out, state *s)
   if (reds->lookahead_tokens)
     for (i = 0; i < ntokens; i++)
       {
-	bool count = bitset_test (no_reduce_set, i);
-
-	for (j = 0; j < reds->num; ++j)
-	  if (bitset_test (reds->lookahead_tokens[j], i))
-	    {
-	      if (! count)
-		{
-		  if (reds->rules[j] != default_reduction)
-		    max_length (&width, symbols[i]->tag);
-		  count = true;
-		}
-	      else
-		{
-		  max_length (&width, symbols[i]->tag);
-		}
-	    }
+        bool count = bitset_test (no_reduce_set, i);
+
+        for (j = 0; j < reds->num; ++j)
+          if (bitset_test (reds->lookahead_tokens[j], i))
+            {
+              if (! count)
+                {
+                  if (reds->rules[j] != default_reduction)
+                    max_length (&width, symbols[i]->tag);
+                  count = true;
+                }
+              else
+                {
+                  max_length (&width, symbols[i]->tag);
+                }
+            }
       }
 
   /* Nothing to report. */
@@ -296,40 +296,40 @@ print_reductions (FILE *out, state *s)
   if (reds->lookahead_tokens)
     for (i = 0; i < ntokens; i++)
       {
-	bool defaulted = false;
-	bool count = bitset_test (no_reduce_set, i);
+        bool defaulted = false;
+        bool count = bitset_test (no_reduce_set, i);
         if (count)
           default_reduction_only = false;
 
-	for (j = 0; j < reds->num; ++j)
-	  if (bitset_test (reds->lookahead_tokens[j], i))
-	    {
-	      if (! count)
-		{
-		  if (reds->rules[j] != default_reduction)
+        for (j = 0; j < reds->num; ++j)
+          if (bitset_test (reds->lookahead_tokens[j], i))
+            {
+              if (! count)
+                {
+                  if (reds->rules[j] != default_reduction)
                     {
                       default_reduction_only = false;
                       print_reduction (out, width,
                                        symbols[i]->tag,
                                        reds->rules[j], true);
                     }
-		  else
-		    defaulted = true;
-		  count = true;
-		}
-	      else
-		{
+                  else
+                    defaulted = true;
+                  count = true;
+                }
+              else
+                {
                   default_reduction_only = false;
-		  if (defaulted)
-		    print_reduction (out, width,
-				     symbols[i]->tag,
-				     default_reduction, true);
-		  defaulted = false;
-		  print_reduction (out, width,
-				   symbols[i]->tag,
-				   reds->rules[j], false);
-		}
-	    }
+                  if (defaulted)
+                    print_reduction (out, width,
+                                     symbols[i]->tag,
+                                     default_reduction, true);
+                  defaulted = false;
+                  print_reduction (out, width,
+                                   symbols[i]->tag,
+                                   reds->rules[j], false);
+                }
+            }
       }
 
   if (default_reduction)
@@ -411,25 +411,25 @@ print_grammar (FILE *out)
   for (i = 0; i < max_user_token_number + 1; i++)
     if (token_translations[i] != undeftoken->number)
       {
-	const char *tag = symbols[token_translations[i]]->tag;
-	rule_number r;
-	item_number *rhsp;
-
-	buffer[0] = 0;
-	column = strlen (tag);
-	fputs (tag, out);
-	END_TEST (65);
-	sprintf (buffer, " (%d)", i);
-
-	for (r = 0; r < nrules; r++)
-	  for (rhsp = rules[r].rhs; *rhsp >= 0; rhsp++)
-	    if (item_number_as_symbol_number (*rhsp) == token_translations[i])
-	      {
-		END_TEST (65);
-		sprintf (buffer + strlen (buffer), " %d", r);
-		break;
-	      }
-	fprintf (out, "%s\n", buffer);
+        const char *tag = symbols[token_translations[i]]->tag;
+        rule_number r;
+        item_number *rhsp;
+
+        buffer[0] = 0;
+        column = strlen (tag);
+        fputs (tag, out);
+        END_TEST (65);
+        sprintf (buffer, " (%d)", i);
+
+        for (r = 0; r < nrules; r++)
+          for (rhsp = rules[r].rhs; *rhsp >= 0; rhsp++)
+            if (item_number_as_symbol_number (*rhsp) == token_translations[i])
+              {
+                END_TEST (65);
+                sprintf (buffer + strlen (buffer), " %d", r);
+                break;
+              }
+        fprintf (out, "%s\n", buffer);
       }
   fputs ("\n\n", out);
 
@@ -442,17 +442,17 @@ print_grammar (FILE *out)
       const char *tag = symbols[i]->tag;
 
       for (r = 0; r < nrules; r++)
-	{
-	  item_number *rhsp;
-	  if (rules[r].lhs->number == i)
-	    left_count++;
-	  for (rhsp = rules[r].rhs; *rhsp >= 0; rhsp++)
-	    if (item_number_as_symbol_number (*rhsp) == i)
-	      {
-		right_count++;
-		break;
-	      }
-	}
+        {
+          item_number *rhsp;
+          if (rules[r].lhs->number == i)
+            left_count++;
+          for (rhsp = rules[r].rhs; *rhsp >= 0; rhsp++)
+            if (item_number_as_symbol_number (*rhsp) == i)
+              {
+                right_count++;
+                break;
+              }
+        }
 
       buffer[0] = 0;
       fputs (tag, out);
@@ -461,38 +461,38 @@ print_grammar (FILE *out)
       END_TEST (0);
 
       if (left_count > 0)
-	{
-	  END_TEST (65);
-	  sprintf (buffer + strlen (buffer), _(" on left:"));
-
-	  for (r = 0; r < nrules; r++)
-	    {
-	      if (rules[r].lhs->number == i)
-		{
-		  END_TEST (65);
-		  sprintf (buffer + strlen (buffer), " %d", r);
-		}
-	    }
-	}
+        {
+          END_TEST (65);
+          sprintf (buffer + strlen (buffer), _(" on left:"));
+
+          for (r = 0; r < nrules; r++)
+            {
+              if (rules[r].lhs->number == i)
+                {
+                  END_TEST (65);
+                  sprintf (buffer + strlen (buffer), " %d", r);
+                }
+            }
+        }
 
       if (right_count > 0)
-	{
-	  if (left_count > 0)
-	    sprintf (buffer + strlen (buffer), ",");
-	  END_TEST (65);
-	  sprintf (buffer + strlen (buffer), _(" on right:"));
-	  for (r = 0; r < nrules; r++)
-	    {
-	      item_number *rhsp;
-	      for (rhsp = rules[r].rhs; *rhsp >= 0; rhsp++)
-		if (item_number_as_symbol_number (*rhsp) == i)
-		  {
-		    END_TEST (65);
-		    sprintf (buffer + strlen (buffer), " %d", r);
-		    break;
-		  }
-	    }
-	}
+        {
+          if (left_count > 0)
+            sprintf (buffer + strlen (buffer), ",");
+          END_TEST (65);
+          sprintf (buffer + strlen (buffer), _(" on right:"));
+          for (r = 0; r < nrules; r++)
+            {
+              item_number *rhsp;
+              for (rhsp = rules[r].rhs; *rhsp >= 0; rhsp++)
+                if (item_number_as_symbol_number (*rhsp) == i)
+                  {
+                    END_TEST (65);
+                    sprintf (buffer + strlen (buffer), " %d", r);
+                    break;
+                  }
+            }
+        }
       fprintf (out, "%s\n", buffer);
     }
 }
@@ -508,7 +508,7 @@ print_results (void)
 
   reduce_output (out);
   grammar_rules_partial_print (out,
-			       _("Rules useless in parser due to conflicts"),
+                               _("Rules useless in parser due to conflicts"),
                                  rule_useless_in_parser_p);
   conflicts_output (out);
 
