@@ -1,5 +1,6 @@
 /* Print information on generated parser, for bison,
-   Copyright 1984, 1986, 1989, 2000, 2001, 2002 Free Software Foundation, Inc.
+   Copyright (C) 1984, 1986, 1989, 2000, 2001, 2002
+   Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -213,24 +214,26 @@ print_reductions (FILE *out, state_t *state)
 
   if (state->nlookaheads == 1 && !nodefault)
     {
-      int default_rule = LAruleno[state->lookaheadsp];
+      rule_t *default_rule = LArule[state->lookaheadsp];
 
       bitset_and (lookaheadset, LA[state->lookaheadsp], shiftset);
 
       for (i = 0; i < ntokens; i++)
 	if (bitset_test (lookaheadset, i))
 	  fprintf (out, _("    %-4s\t[reduce using rule %d (%s)]\n"),
-		   escape (symbols[i]->tag), default_rule - 1,
-		   escape2 (rules[default_rule].lhs->tag));
+		   escape (symbols[i]->tag),
+		   default_rule->number - 1,
+		   escape2 (default_rule->lhs->tag));
 
       fprintf (out, _("    $default\treduce using rule %d (%s)\n\n"),
-	       default_rule - 1, escape (rules[default_rule].lhs->tag));
+	       default_rule->number - 1,
+	       escape (default_rule->lhs->tag));
     }
   else if (state->nlookaheads >= 1)
     {
       int cmax = 0;
       int default_LA = -1;
-      int default_rule = 0;
+      rule_t *default_rule = NULL;
 
       if (!nodefault)
 	for (i = 0; i < state->nlookaheads; ++i)
@@ -248,7 +251,7 @@ print_reductions (FILE *out, state_t *state)
 	      {
 		cmax = count;
 		default_LA = state->lookaheadsp + i;
-		default_rule = LAruleno[state->lookaheadsp + i];
+		default_rule = LArule[state->lookaheadsp + i];
 	      }
 
 	    bitset_or (shiftset, shiftset, lookaheadset);
@@ -275,8 +278,8 @@ print_reductions (FILE *out, state_t *state)
 		      fprintf (out,
 			       _("    %-4s\treduce using rule %d (%s)\n"),
 			       escape (symbols[i]->tag),
-			       LAruleno[state->lookaheadsp + j] - 1,
-			       escape2 (rules[LAruleno[state->lookaheadsp + j]].lhs->tag));
+			       LArule[state->lookaheadsp + j]->number - 1,
+			       escape2 (LArule[state->lookaheadsp + j]->lhs->tag));
 		    else
 		      defaulted = 1;
 
@@ -288,22 +291,22 @@ print_reductions (FILE *out, state_t *state)
 		      fprintf (out,
 			       _("    %-4s\treduce using rule %d (%s)\n"),
 			       escape (symbols[i]->tag),
-			       LAruleno[default_LA] - 1,
-			       escape2 (rules[LAruleno[default_LA]].lhs->tag));
+			       LArule[default_LA]->number - 1,
+			       escape2 (LArule[default_LA]->lhs->tag));
 		    defaulted = 0;
 		    fprintf (out,
 			     _("    %-4s\t[reduce using rule %d (%s)]\n"),
 			     escape (symbols[i]->tag),
-			     LAruleno[state->lookaheadsp + j] - 1,
-			     escape2 (rules[LAruleno[state->lookaheadsp + j]].lhs->tag));
+			     LArule[state->lookaheadsp + j]->number - 1,
+			     escape2 (LArule[state->lookaheadsp + j]->lhs->tag));
 		  }
 	      }
 	}
 
       if (default_LA >= 0)
 	fprintf (out, _("    $default\treduce using rule %d (%s)\n"),
-		 default_rule - 1,
-		 escape (rules[default_rule].lhs->tag));
+		 default_rule->number - 1,
+		 escape (default_rule->lhs->tag));
     }
 }
 
