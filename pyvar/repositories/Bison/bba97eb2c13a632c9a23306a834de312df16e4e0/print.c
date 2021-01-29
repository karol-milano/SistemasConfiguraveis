@@ -94,7 +94,7 @@ print_core (FILE *out, state_t *state)
 	    sp++;
 
 	  rule = -(*sp);
-	  fprintf (out, "    %s  ->  ", escape (symbols[rules[rule].lhs]->tag));
+	  fprintf (out, "    %s  ->  ", escape (rules[rule].lhs->tag));
 
 	  for (sp = rules[rule].rhs; sp < sp1; sp++)
 	    fprintf (out, "%s ", escape (symbols[*sp]->tag));
@@ -189,7 +189,7 @@ print_reductions (FILE *out, state_t *state)
   if (state->consistent)
     {
       int rule = redp->rules[0];
-      int symbol = rules[rule].lhs;
+      int symbol = rules[rule].lhs->number;
       fprintf (out, _("    $default\treduce using rule %d (%s)\n\n"),
 	       rule - 1, escape (symbols[symbol]->tag));
       return;
@@ -221,10 +221,10 @@ print_reductions (FILE *out, state_t *state)
 	if (bitset_test (lookaheadset, i))
 	  fprintf (out, _("    %-4s\t[reduce using rule %d (%s)]\n"),
 		   escape (symbols[i]->tag), default_rule - 1,
-		   escape2 (symbols[rules[default_rule].lhs]->tag));
+		   escape2 (rules[default_rule].lhs->tag));
 
       fprintf (out, _("    $default\treduce using rule %d (%s)\n\n"),
-	       default_rule - 1, escape (symbols[rules[default_rule].lhs]->tag));
+	       default_rule - 1, escape (rules[default_rule].lhs->tag));
     }
   else if (state->nlookaheads >= 1)
     {
@@ -276,7 +276,7 @@ print_reductions (FILE *out, state_t *state)
 			       _("    %-4s\treduce using rule %d (%s)\n"),
 			       escape (symbols[i]->tag),
 			       LAruleno[state->lookaheadsp + j] - 1,
-			       escape2 (symbols[rules[LAruleno[state->lookaheadsp + j]].lhs]->tag));
+			       escape2 (rules[LAruleno[state->lookaheadsp + j]].lhs->tag));
 		    else
 		      defaulted = 1;
 
@@ -289,13 +289,13 @@ print_reductions (FILE *out, state_t *state)
 			       _("    %-4s\treduce using rule %d (%s)\n"),
 			       escape (symbols[i]->tag),
 			       LAruleno[default_LA] - 1,
-			       escape2 (symbols[rules[LAruleno[default_LA]].lhs]->tag));
+			       escape2 (rules[LAruleno[default_LA]].lhs->tag));
 		    defaulted = 0;
 		    fprintf (out,
 			     _("    %-4s\t[reduce using rule %d (%s)]\n"),
 			     escape (symbols[i]->tag),
 			     LAruleno[state->lookaheadsp + j] - 1,
-			     escape2 (symbols[rules[LAruleno[state->lookaheadsp + j]].lhs]->tag));
+			     escape2 (rules[LAruleno[state->lookaheadsp + j]].lhs->tag));
 		  }
 	      }
 	}
@@ -303,7 +303,7 @@ print_reductions (FILE *out, state_t *state)
       if (default_LA >= 0)
 	fprintf (out, _("    $default\treduce using rule %d (%s)\n"),
 		 default_rule - 1,
-		 escape (symbols[rules[default_rule].lhs]->tag));
+		 escape (rules[default_rule].lhs->tag));
     }
 }
 
@@ -368,7 +368,7 @@ print_grammar (FILE *out)
   for (i = 1; i < nrules + 1; i++)
     {
       fprintf (out, _("  %3d %3d %s ->"),
-	       i - 1, rules[i].line, escape (symbols[rules[i].lhs]->tag));
+	       i - 1, rules[i].line, escape (rules[i].lhs->tag));
       rule = rules[i].rhs;
       if (*rule >= 0)
 	while (*rule >= 0)
@@ -411,7 +411,7 @@ print_grammar (FILE *out)
 
       for (j = 1; j < nrules + 1; j++)
 	{
-	  if (rules[j].lhs == i)
+	  if (rules[j].lhs->number == i)
 	    left_count++;
 	  for (rule = rules[j].rhs; *rule >= 0; rule++)
 	    if (*rule == i)
@@ -435,7 +435,7 @@ print_grammar (FILE *out)
 	  for (j = 1; j < nrules + 1; j++)
 	    {
 	      END_TEST (65);
-	      if (rules[j].lhs == i)
+	      if (rules[j].lhs->number == i)
 		sprintf (buffer + strlen (buffer), " %d", j - 1);
 	    }
 	}
