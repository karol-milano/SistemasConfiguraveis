@@ -20,6 +20,7 @@
 
 
 #include "system.h"
+#include "quotearg.h"
 #include "files.h"
 #include "gram.h"
 #include "LR0.h"
@@ -43,6 +44,19 @@ print_token (int extnum, int token)
 }
 #endif
 
+static inline const char *
+escape (const char *s)
+{
+  return quotearg_n_style (1, escape_quoting_style, s);
+}
+
+/* Be cautious not to use twice the same slot in a single expression. */
+static inline const char *
+escape2 (const char *s)
+{
+  return quotearg_n_style (2, escape_quoting_style, s);
+}
+
 
 /*--------------------------------.
 | Report information on a state.  |
@@ -78,15 +92,15 @@ print_core (FILE *out, state_t *state)
 	    sp++;
 
 	  rule = -(*sp);
-	  fprintf (out, "    %s  ->  ", tags[rule_table[rule].lhs]);
+	  fprintf (out, "    %s  ->  ", escape (tags[rule_table[rule].lhs]));
 
 	  for (sp = ritem + rule_table[rule].rhs; sp < sp1; sp++)
-	    fprintf (out, "%s ", tags[*sp]);
+	    fprintf (out, "%s ", escape (tags[*sp]));
 
 	  fputc ('.', out);
 
 	  for (/* Nothing */; *sp > 0; ++sp)
-	    fprintf (out, " %s", tags[*sp]);
+	    fprintf (out, " %s", escape (tags[*sp]));
 
 	  fprintf (out, _("   (rule %d)"), rule);
 	  fputc ('\n', out);
@@ -110,7 +124,7 @@ print_shifts (FILE *out, state_t *state)
 	int symbol = state_table[state1]->accessing_symbol;
 	fprintf (out,
 		 _("    %-4s\tshift, and go to state %d\n"),
-		 tags[symbol], state1);
+		 escape (tags[symbol]), state1);
       }
 
   if (i > 0)
@@ -127,7 +141,7 @@ print_errs (FILE *out, state_t *state)
   for (i = 0; i < errp->nerrs; ++i)
     if (errp->errs[i])
       fprintf (out, _("    %-4s\terror (nonassociative)\n"),
-	       tags[errp->errs[i]]);
+	       escape (tags[errp->errs[i]]));
 
   if (i > 0)
     fputc ('\n', out);
@@ -151,7 +165,7 @@ print_gotos (FILE *out, state_t *state)
 	    int state1 = shiftp->shifts[i];
 	    int symbol = state_table[state1]->accessing_symbol;
 	    fprintf (out, _("    %-4s\tgo to state %d\n"),
-		     tags[symbol], state1);
+		     escape (tags[symbol]), state1);
 	  }
 
       fputc ('\n', out);
@@ -175,7 +189,7 @@ print_reductions (FILE *out, state_t *state)
       int rule = redp->rules[0];
       int symbol = rule_table[rule].lhs;
       fprintf (out, _("    $default\treduce using rule %d (%s)\n\n"),
-	       rule, tags[symbol]);
+	       rule, escape (tags[symbol]));
       return;
     }
 
@@ -207,11 +221,11 @@ print_reductions (FILE *out, state_t *state)
       for (i = 0; i < ntokens; i++)
 	if (BITISSET (lookaheadset, i))
 	  fprintf (out, _("    %-4s\t[reduce using rule %d (%s)]\n"),
-		   tags[i], default_rule,
-		   tags[rule_table[default_rule].lhs]);
+		   escape (tags[i]), default_rule,
+		   escape2 (tags[rule_table[default_rule].lhs]));
 
       fprintf (out, _("    $default\treduce using rule %d (%s)\n\n"),
-	       default_rule, tags[rule_table[default_rule].lhs]);
+	       default_rule, escape (tags[rule_table[default_rule].lhs]));
     }
   else if (state->nlookaheads >= 1)
     {
@@ -265,9 +279,9 @@ print_reductions (FILE *out, state_t *state)
 		      if (state->lookaheadsp + j != default_LA)
 			fprintf (out,
 				 _("    %-4s\treduce using rule %d (%s)\n"),
-				 tags[i],
+				 escape (tags[i]),
 				 LAruleno[state->lookaheadsp + j],
-				 tags[rule_table[LAruleno[state->lookaheadsp + j]].lhs]);
+				 escape2 (tags[rule_table[LAruleno[state->lookaheadsp + j]].lhs]));
 		      else
 			defaulted = 1;
 
@@ -278,15 +292,15 @@ print_reductions (FILE *out, state_t *state)
 		      if (defaulted)
 			fprintf (out,
 				 _("    %-4s\treduce using rule %d (%s)\n"),
-				 tags[i],
+				 escape (tags[i]),
 				 LAruleno[default_LA],
-				 tags[rule_table[LAruleno[default_LA]].lhs]);
+				 escape2 (tags[rule_table[LAruleno[default_LA]].lhs]));
 		      defaulted = 0;
 		      fprintf (out,
 			       _("    %-4s\t[reduce using rule %d (%s)]\n"),
-			       tags[i],
+			       escape (tags[i]),
 			       LAruleno[state->lookaheadsp + j],
-			       tags[rule_table[LAruleno[state->lookaheadsp + j]].lhs]);
+			       escape2 (tags[rule_table[LAruleno[state->lookaheadsp + j]].lhs]));
 		    }
 		}
 	    }
@@ -294,7 +308,7 @@ print_reductions (FILE *out, state_t *state)
 
       if (default_LA >= 0)
 	fprintf (out, _("    $default\treduce using rule %d (%s)\n"),
-		 default_rule, tags[rule_table[default_rule].lhs]);
+		 default_rule, escape (tags[rule_table[default_rule].lhs]));
     }
 }
 
@@ -361,11 +375,11 @@ print_grammar (FILE *out)
     if (rule_table[i].useful)
       {
 	fprintf (out, _("  %3d %3d %s ->"),
-		 i, rule_table[i].line, tags[rule_table[i].lhs]);
+		 i, rule_table[i].line, escape (tags[rule_table[i].lhs]));
 	rule = &ritem[rule_table[i].rhs];
 	if (*rule > 0)
 	  while (*rule > 0)
-	    fprintf (out, " %s", tags[*rule++]);
+	    fprintf (out, " %s", escape (tags[*rule++]));
 	else
 	  fprintf (out, " /* %s */", _("empty"));
 	fputc ('\n', out);
@@ -375,14 +389,14 @@ print_grammar (FILE *out)
 
   /* TERMINAL (type #) : rule #s terminal is on RHS */
   fprintf (out, "%s\n\n", _("Terminals, with rules where they appear"));
-  fprintf (out, "%s (-1)\n", tags[0]);
+  fprintf (out, "%s (-1)\n", escape (tags[0]));
 
   for (i = 0; i <= max_user_token_number; i++)
     if (token_translations[i] != 2)
       {
 	buffer[0] = 0;
-	column = strlen (tags[token_translations[i]]);
-	fputs (tags[token_translations[i]], out);
+	column = strlen (escape (tags[token_translations[i]]));
+	fputs (escape (tags[token_translations[i]]), out);
 	END_TEST (50);
 	sprintf (buffer, " (%d)", i);
 
@@ -417,8 +431,8 @@ print_grammar (FILE *out)
 	}
 
       buffer[0] = 0;
-      fputs (tags[i], out);
-      column = strlen (tags[i]);
+      fputs (escape (tags[i]), out);
+      column = strlen (escape (tags[i]));
       sprintf (buffer, " (%d)", i);
       END_TEST (0);
 
