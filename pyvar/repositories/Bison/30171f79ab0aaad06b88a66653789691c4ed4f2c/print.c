@@ -102,7 +102,7 @@ print_core (FILE *out, state_t *state)
 	  for (/* Nothing */; *sp >= 0; ++sp)
 	    fprintf (out, " %s", escape (tags[*sp]));
 
-	  fprintf (out, _("   (rule %d)"), rule);
+	  fprintf (out, _("   (rule %d)"), rule - 1);
 	  fputc ('\n', out);
 	}
 
@@ -189,7 +189,7 @@ print_reductions (FILE *out, state_t *state)
       int rule = redp->rules[0];
       int symbol = rule_table[rule].lhs;
       fprintf (out, _("    $default\treduce using rule %d (%s)\n\n"),
-	       rule, escape (tags[symbol]));
+	       rule - 1, escape (tags[symbol]));
       return;
     }
 
@@ -221,11 +221,11 @@ print_reductions (FILE *out, state_t *state)
       for (i = 0; i < ntokens; i++)
 	if (BITISSET (lookaheadset, i))
 	  fprintf (out, _("    %-4s\t[reduce using rule %d (%s)]\n"),
-		   escape (tags[i]), default_rule,
+		   escape (tags[i]), default_rule - 1,
 		   escape2 (tags[rule_table[default_rule].lhs]));
 
       fprintf (out, _("    $default\treduce using rule %d (%s)\n\n"),
-	       default_rule, escape (tags[rule_table[default_rule].lhs]));
+	       default_rule - 1, escape (tags[rule_table[default_rule].lhs]));
     }
   else if (state->nlookaheads >= 1)
     {
@@ -280,7 +280,7 @@ print_reductions (FILE *out, state_t *state)
 			fprintf (out,
 				 _("    %-4s\treduce using rule %d (%s)\n"),
 				 escape (tags[i]),
-				 LAruleno[state->lookaheadsp + j],
+				 LAruleno[state->lookaheadsp + j] - 1,
 				 escape2 (tags[rule_table[LAruleno[state->lookaheadsp + j]].lhs]));
 		      else
 			defaulted = 1;
@@ -293,13 +293,13 @@ print_reductions (FILE *out, state_t *state)
 			fprintf (out,
 				 _("    %-4s\treduce using rule %d (%s)\n"),
 				 escape (tags[i]),
-				 LAruleno[default_LA],
+				 LAruleno[default_LA] - 1,
 				 escape2 (tags[rule_table[LAruleno[default_LA]].lhs]));
 		      defaulted = 0;
 		      fprintf (out,
 			       _("    %-4s\t[reduce using rule %d (%s)]\n"),
 			       escape (tags[i]),
-			       LAruleno[state->lookaheadsp + j],
+			       LAruleno[state->lookaheadsp + j] - 1,
 			       escape2 (tags[rule_table[LAruleno[state->lookaheadsp + j]].lhs]));
 		    }
 		}
@@ -308,7 +308,8 @@ print_reductions (FILE *out, state_t *state)
 
       if (default_LA >= 0)
 	fprintf (out, _("    $default\treduce using rule %d (%s)\n"),
-		 default_rule, escape (tags[rule_table[default_rule].lhs]));
+		 default_rule - 1,
+		 escape (tags[rule_table[default_rule].lhs]));
     }
 }
 
@@ -322,9 +323,9 @@ print_actions (FILE *out, state_t *state)
   if (shiftp->nshifts == 0 && redp->nreds == 0)
     {
       if (final_state == state->number)
-	fprintf (out, _("    $default\taccept\n"));
+       fprintf (out, _("    $default\taccept\n"));
       else
-	fprintf (out, _("    NO ACTIONS\n"));
+       fprintf (out, _("    NO ACTIONS\n"));
       return;
     }
 
@@ -375,7 +376,7 @@ print_grammar (FILE *out)
     if (rule_table[i].useful)
       {
 	fprintf (out, _("  %3d %3d %s ->"),
-		 i, rule_table[i].line, escape (tags[rule_table[i].lhs]));
+		 i - 1, rule_table[i].line, escape (tags[rule_table[i].lhs]));
 	rule = &ritem[rule_table[i].rhs];
 	if (*rule >= 0)
 	  while (*rule >= 0)
@@ -403,7 +404,7 @@ print_grammar (FILE *out)
 	    if (*rule == token_translations[i])
 	      {
 		END_TEST (65);
-		sprintf (buffer + strlen (buffer), " %d", j);
+		sprintf (buffer + strlen (buffer), " %d", j - 1);
 		break;
 	      }
 	fprintf (out, "%s\n", buffer);
@@ -443,7 +444,7 @@ print_grammar (FILE *out)
 	    {
 	      END_TEST (65);
 	      if (rule_table[j].lhs == i)
-		sprintf (buffer + strlen (buffer), " %d", j);
+		sprintf (buffer + strlen (buffer), " %d", j - 1);
 	    }
 	}
 
@@ -459,7 +460,7 @@ print_grammar (FILE *out)
 		if (*rule == i)
 		  {
 		    END_TEST (65);
-		    sprintf (buffer + strlen (buffer), " %d", j);
+		    sprintf (buffer + strlen (buffer), " %d", j - 1);
 		    break;
 		  }
 	    }
