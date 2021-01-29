@@ -47,19 +47,6 @@ print_token (int extnum, int token)
 }
 #endif
 
-static inline const char *
-escape (const char *s)
-{
-  return quotearg_n_style (1, escape_quoting_style, s);
-}
-
-/* Be cautious not to use twice the same slot in a single expression. */
-static inline const char *
-escape2 (const char *s)
-{
-  return quotearg_n_style (2, escape_quoting_style, s);
-}
-
 
 /*--------------------------------.
 | Report information on a state.  |
@@ -94,15 +81,15 @@ print_core (FILE *out, state_t *state)
 	    sp++;
 
 	  rule = -(*sp);
-	  fprintf (out, "    %s  ->  ", escape (rules[rule].lhs->tag));
+	  fprintf (out, "    %s  ->  ", symbol_tag_get (rules[rule].lhs));
 
 	  for (sp = rules[rule].rhs; sp < sp1; sp++)
-	    fprintf (out, "%s ", escape (symbols[*sp]->tag));
+	    fprintf (out, "%s ", symbol_tag_get (symbols[*sp]));
 
 	  fputc ('.', out);
 
 	  for (/* Nothing */; *sp >= 0; ++sp)
-	    fprintf (out, " %s", escape (symbols[*sp]->tag));
+	    fprintf (out, " %s", symbol_tag_get (symbols[*sp]));
 
 	  /* Display the lookaheads?  */
 	  if (report_flag & report_lookaheads)
@@ -123,8 +110,7 @@ print_core (FILE *out, state_t *state)
 		      if (bitset_test (LA[state->lookaheadsp + j], k)
 			  && LArule[state->lookaheadsp + j]->number == rule)
 			fprintf (out, "%s%s",
-				 quotearg_style (escape_quoting_style,
-						 symbols[k]->tag),
+				 symbol_tag_get (symbols[k]),
 				 --nlookaheads ? ", " : "");
 		  fprintf (out, "]");
 		}
@@ -152,7 +138,7 @@ print_shifts (FILE *out, state_t *state)
 	symbol_number_t symbol = states[state1]->accessing_symbol;
 	fprintf (out,
 		 _("    %-4s\tshift, and go to state %d\n"),
-		 escape (symbols[symbol]->tag), state1);
+		 symbol_tag_get (symbols[symbol]), state1);
       }
 
   if (i > 0)
@@ -169,7 +155,7 @@ print_errs (FILE *out, state_t *state)
   for (i = 0; i < errp->nerrs; ++i)
     if (errp->errs[i])
       fprintf (out, _("    %-4s\terror (nonassociative)\n"),
-	       escape (symbols[errp->errs[i]]->tag));
+	       symbol_tag_get (symbols[errp->errs[i]]));
 
   if (i > 0)
     fputc ('\n', out);
@@ -193,7 +179,7 @@ print_gotos (FILE *out, state_t *state)
 	    int state1 = shiftp->shifts[i];
 	    symbol_number_t symbol = states[state1]->accessing_symbol;
 	    fprintf (out, _("    %-4s\tgo to state %d\n"),
-		     escape (symbols[symbol]->tag), state1);
+		     symbol_tag_get (symbols[symbol]), state1);
 	  }
 
       fputc ('\n', out);
@@ -217,7 +203,7 @@ print_reductions (FILE *out, state_t *state)
       int rule = redp->rules[0];
       symbol_number_t symbol = rules[rule].lhs->number;
       fprintf (out, _("    $default\treduce using rule %d (%s)\n\n"),
-	       rule - 1, escape (symbols[symbol]->tag));
+	       rule - 1, symbol_tag_get (symbols[symbol]));
       return;
     }
 
@@ -246,13 +232,13 @@ print_reductions (FILE *out, state_t *state)
       for (i = 0; i < ntokens; i++)
 	if (bitset_test (lookaheadset, i))
 	  fprintf (out, _("    %-4s\t[reduce using rule %d (%s)]\n"),
-		   escape (symbols[i]->tag),
+		   symbol_tag_get (symbols[i]),
 		   default_rule->number - 1,
-		   escape2 (default_rule->lhs->tag));
+		   symbol_tag_get_n (default_rule->lhs, 1));
 
       fprintf (out, _("    $default\treduce using rule %d (%s)\n\n"),
 	       default_rule->number - 1,
-	       escape (default_rule->lhs->tag));
+	       symbol_tag_get (default_rule->lhs));
     }
   else if (state->nlookaheads >= 1)
     {
@@ -302,9 +288,9 @@ print_reductions (FILE *out, state_t *state)
 		    if (state->lookaheadsp + j != default_LA)
 		      fprintf (out,
 			       _("    %-4s\treduce using rule %d (%s)\n"),
-			       escape (symbols[i]->tag),
+			       symbol_tag_get (symbols[i]),
 			       LArule[state->lookaheadsp + j]->number - 1,
-			       escape2 (LArule[state->lookaheadsp + j]->lhs->tag));
+			       symbol_tag_get_n (LArule[state->lookaheadsp + j]->lhs, 1));
 		    else
 		      defaulted = 1;
 
@@ -315,15 +301,15 @@ print_reductions (FILE *out, state_t *state)
 		    if (defaulted)
 		      fprintf (out,
 			       _("    %-4s\treduce using rule %d (%s)\n"),
-			       escape (symbols[i]->tag),
+			       symbol_tag_get (symbols[i]),
 			       LArule[default_LA]->number - 1,
-			       escape2 (LArule[default_LA]->lhs->tag));
+			       symbol_tag_get_n (LArule[default_LA]->lhs, 1));
 		    defaulted = 0;
 		    fprintf (out,
 			     _("    %-4s\t[reduce using rule %d (%s)]\n"),
-			     escape (symbols[i]->tag),
+			     symbol_tag_get (symbols[i]),
 			     LArule[state->lookaheadsp + j]->number - 1,
-			     escape2 (LArule[state->lookaheadsp + j]->lhs->tag));
+			     symbol_tag_get_n (LArule[state->lookaheadsp + j]->lhs, 1));
 		  }
 	      }
 	}
@@ -331,7 +317,7 @@ print_reductions (FILE *out, state_t *state)
       if (default_LA >= 0)
 	fprintf (out, _("    $default\treduce using rule %d (%s)\n"),
 		 default_rule->number - 1,
-		 escape (default_rule->lhs->tag));
+		 symbol_tag_get (default_rule->lhs));
     }
 }
 
@@ -389,47 +375,31 @@ static void
 print_grammar (FILE *out)
 {
   symbol_number_t i;
-  int j;
   item_number_t *rule;
   char buffer[90];
   int column = 0;
 
-  /* rule # : LHS -> RHS */
-  fprintf (out, "%s\n\n", _("Grammar"));
-  fprintf (out, "  %s\n", _("Number, Line, Rule"));
-  for (j = 1; j < nrules + 1; j++)
-    {
-      fprintf (out, "  %3d %3d %s ->",
-	       j - 1, rules[j].location.first_line,
-	       escape (rules[j].lhs->tag));
-      rule = rules[j].rhs;
-      if (*rule >= 0)
-	while (*rule >= 0)
-	  fprintf (out, " %s", escape (symbols[*rule++]->tag));
-      else
-	fprintf (out, " /* %s */", _("empty"));
-      fputc ('\n', out);
-    }
-  fputs ("\n\n", out);
-
+  grammar_rules_print (out);
 
   /* TERMINAL (type #) : rule #s terminal is on RHS */
   fprintf (out, "%s\n\n", _("Terminals, with rules where they appear"));
   for (i = 0; i < max_user_token_number + 1; i++)
     if (token_translations[i] != undeftoken->number)
       {
+	const char *tag = symbol_tag_get (symbols[token_translations[i]]);
+	int r;
 	buffer[0] = 0;
-	column = strlen (escape (symbols[token_translations[i]]->tag));
-	fputs (escape (symbols[token_translations[i]]->tag), out);
+	column = strlen (tag);
+	fputs (tag, out);
 	END_TEST (50);
 	sprintf (buffer, " (%d)", i);
 
-	for (j = 1; j < nrules + 1; j++)
-	  for (rule = rules[j].rhs; *rule >= 0; rule++)
+	for (r = 1; r < nrules + 1; r++)
+	  for (rule = rules[r].rhs; *rule >= 0; rule++)
 	    if (item_number_as_symbol_number (*rule) == token_translations[i])
 	      {
 		END_TEST (65);
-		sprintf (buffer + strlen (buffer), " %d", j - 1);
+		sprintf (buffer + strlen (buffer), " %d", r - 1);
 		break;
 	      }
 	fprintf (out, "%s\n", buffer);
@@ -441,12 +411,14 @@ print_grammar (FILE *out)
   for (i = ntokens; i < nsyms; i++)
     {
       int left_count = 0, right_count = 0;
+      int r;
+      const char *tag = symbol_tag_get (symbols[i]);
 
-      for (j = 1; j < nrules + 1; j++)
+      for (r = 1; r < nrules + 1; r++)
 	{
-	  if (rules[j].lhs->number == i)
+	  if (rules[r].lhs->number == i)
 	    left_count++;
-	  for (rule = rules[j].rhs; *rule >= 0; rule++)
+	  for (rule = rules[r].rhs; *rule >= 0; rule++)
 	    if (item_number_as_symbol_number (*rule) == i)
 	      {
 		right_count++;
@@ -455,8 +427,8 @@ print_grammar (FILE *out)
 	}
 
       buffer[0] = 0;
-      fputs (escape (symbols[i]->tag), out);
-      column = strlen (escape (symbols[i]->tag));
+      fputs (tag, out);
+      column = strlen (tag);
       sprintf (buffer, " (%d)", i);
       END_TEST (0);
 
@@ -465,11 +437,11 @@ print_grammar (FILE *out)
 	  END_TEST (50);
 	  sprintf (buffer + strlen (buffer), _(" on left:"));
 
-	  for (j = 1; j < nrules + 1; j++)
+	  for (r = 1; r < nrules + 1; r++)
 	    {
 	      END_TEST (65);
-	      if (rules[j].lhs->number == i)
-		sprintf (buffer + strlen (buffer), " %d", j - 1);
+	      if (rules[r].lhs->number == i)
+		sprintf (buffer + strlen (buffer), " %d", r - 1);
 	    }
 	}
 
@@ -479,13 +451,13 @@ print_grammar (FILE *out)
 	    sprintf (buffer + strlen (buffer), ",");
 	  END_TEST (50);
 	  sprintf (buffer + strlen (buffer), _(" on right:"));
-	  for (j = 1; j < nrules + 1; j++)
+	  for (r = 1; r < nrules + 1; r++)
 	    {
-	      for (rule = rules[j].rhs; *rule >= 0; rule++)
+	      for (rule = rules[r].rhs; *rule >= 0; rule++)
 		if (item_number_as_symbol_number (*rule) == i)
 		  {
 		    END_TEST (65);
-		    sprintf (buffer + strlen (buffer), " %d", j - 1);
+		    sprintf (buffer + strlen (buffer), " %d", r - 1);
 		    break;
 		  }
 	    }
