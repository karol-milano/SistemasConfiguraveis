@@ -22,6 +22,7 @@
 #include "system.h"
 #include "quotearg.h"
 #include "files.h"
+#include "symtab.h"
 #include "gram.h"
 #include "LR0.h"
 #include "lalr.h"
@@ -92,15 +93,15 @@ print_core (FILE *out, state_t *state)
 	    sp++;
 
 	  rule = -(*sp);
-	  fprintf (out, "    %s  ->  ", escape (tags[rule_table[rule].lhs]));
+	  fprintf (out, "    %s  ->  ", escape (symbols[rule_table[rule].lhs]->tag));
 
 	  for (sp = ritem + rule_table[rule].rhs; sp < sp1; sp++)
-	    fprintf (out, "%s ", escape (tags[*sp]));
+	    fprintf (out, "%s ", escape (symbols[*sp]->tag));
 
 	  fputc ('.', out);
 
 	  for (/* Nothing */; *sp >= 0; ++sp)
-	    fprintf (out, " %s", escape (tags[*sp]));
+	    fprintf (out, " %s", escape (symbols[*sp]->tag));
 
 	  fprintf (out, _("   (rule %d)"), rule - 1);
 	  fputc ('\n', out);
@@ -124,7 +125,7 @@ print_shifts (FILE *out, state_t *state)
 	int symbol = state_table[state1]->accessing_symbol;
 	fprintf (out,
 		 _("    %-4s\tshift, and go to state %d\n"),
-		 escape (tags[symbol]), state1);
+		 escape (symbols[symbol]->tag), state1);
       }
 
   if (i > 0)
@@ -141,7 +142,7 @@ print_errs (FILE *out, state_t *state)
   for (i = 0; i < errp->nerrs; ++i)
     if (errp->errs[i])
       fprintf (out, _("    %-4s\terror (nonassociative)\n"),
-	       escape (tags[errp->errs[i]]));
+	       escape (symbols[errp->errs[i]]->tag));
 
   if (i > 0)
     fputc ('\n', out);
@@ -165,7 +166,7 @@ print_gotos (FILE *out, state_t *state)
 	    int state1 = shiftp->shifts[i];
 	    int symbol = state_table[state1]->accessing_symbol;
 	    fprintf (out, _("    %-4s\tgo to state %d\n"),
-		     escape (tags[symbol]), state1);
+		     escape (symbols[symbol]->tag), state1);
 	  }
 
       fputc ('\n', out);
@@ -189,7 +190,7 @@ print_reductions (FILE *out, state_t *state)
       int rule = redp->rules[0];
       int symbol = rule_table[rule].lhs;
       fprintf (out, _("    $default\treduce using rule %d (%s)\n\n"),
-	       rule - 1, escape (tags[symbol]));
+	       rule - 1, escape (symbols[symbol]->tag));
       return;
     }
 
@@ -221,11 +222,11 @@ print_reductions (FILE *out, state_t *state)
       for (i = 0; i < ntokens; i++)
 	if (BITISSET (lookaheadset, i))
 	  fprintf (out, _("    %-4s\t[reduce using rule %d (%s)]\n"),
-		   escape (tags[i]), default_rule - 1,
-		   escape2 (tags[rule_table[default_rule].lhs]));
+		   escape (symbols[i]->tag), default_rule - 1,
+		   escape2 (symbols[rule_table[default_rule].lhs]->tag));
 
       fprintf (out, _("    $default\treduce using rule %d (%s)\n\n"),
-	       default_rule - 1, escape (tags[rule_table[default_rule].lhs]));
+	       default_rule - 1, escape (symbols[rule_table[default_rule].lhs]->tag));
     }
   else if (state->nlookaheads >= 1)
     {
@@ -279,9 +280,9 @@ print_reductions (FILE *out, state_t *state)
 		      if (state->lookaheadsp + j != default_LA)
 			fprintf (out,
 				 _("    %-4s\treduce using rule %d (%s)\n"),
-				 escape (tags[i]),
+				 escape (symbols[i]->tag),
 				 LAruleno[state->lookaheadsp + j] - 1,
-				 escape2 (tags[rule_table[LAruleno[state->lookaheadsp + j]].lhs]));
+				 escape2 (symbols[rule_table[LAruleno[state->lookaheadsp + j]].lhs]->tag));
 		      else
 			defaulted = 1;
 
@@ -292,15 +293,15 @@ print_reductions (FILE *out, state_t *state)
 		      if (defaulted)
 			fprintf (out,
 				 _("    %-4s\treduce using rule %d (%s)\n"),
-				 escape (tags[i]),
+				 escape (symbols[i]->tag),
 				 LAruleno[default_LA] - 1,
-				 escape2 (tags[rule_table[LAruleno[default_LA]].lhs]));
+				 escape2 (symbols[rule_table[LAruleno[default_LA]].lhs]->tag));
 		      defaulted = 0;
 		      fprintf (out,
 			       _("    %-4s\t[reduce using rule %d (%s)]\n"),
-			       escape (tags[i]),
+			       escape (symbols[i]->tag),
 			       LAruleno[state->lookaheadsp + j] - 1,
-			       escape2 (tags[rule_table[LAruleno[state->lookaheadsp + j]].lhs]));
+			       escape2 (symbols[rule_table[LAruleno[state->lookaheadsp + j]].lhs]->tag));
 		    }
 		}
 	    }
@@ -309,7 +310,7 @@ print_reductions (FILE *out, state_t *state)
       if (default_LA >= 0)
 	fprintf (out, _("    $default\treduce using rule %d (%s)\n"),
 		 default_rule - 1,
-		 escape (tags[rule_table[default_rule].lhs]));
+		 escape (symbols[rule_table[default_rule].lhs]->tag));
     }
 }
 
@@ -376,11 +377,11 @@ print_grammar (FILE *out)
     if (rule_table[i].useful)
       {
 	fprintf (out, _("  %3d %3d %s ->"),
-		 i - 1, rule_table[i].line, escape (tags[rule_table[i].lhs]));
+		 i - 1, rule_table[i].line, escape (symbols[rule_table[i].lhs]->tag));
 	rule = &ritem[rule_table[i].rhs];
 	if (*rule >= 0)
 	  while (*rule >= 0)
-	    fprintf (out, " %s", escape (tags[*rule++]));
+	    fprintf (out, " %s", escape (symbols[*rule++]->tag));
 	else
 	  fprintf (out, " /* %s */", _("empty"));
 	fputc ('\n', out);
@@ -394,8 +395,8 @@ print_grammar (FILE *out)
     if (token_translations[i] != 2)
       {
 	buffer[0] = 0;
-	column = strlen (escape (tags[token_translations[i]]));
-	fputs (escape (tags[token_translations[i]]), out);
+	column = strlen (escape (symbols[token_translations[i]]->tag));
+	fputs (escape (symbols[token_translations[i]]->tag), out);
 	END_TEST (50);
 	sprintf (buffer, " (%d)", i);
 
@@ -430,8 +431,8 @@ print_grammar (FILE *out)
 	}
 
       buffer[0] = 0;
-      fputs (escape (tags[i]), out);
-      column = strlen (escape (tags[i]));
+      fputs (escape (symbols[i]->tag), out);
+      column = strlen (escape (symbols[i]->tag));
       sprintf (buffer, " (%d)", i);
       END_TEST (0);
 
