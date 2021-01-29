@@ -93,9 +93,9 @@ print_core (FILE *out, state_t *state)
 	    sp++;
 
 	  rule = -(*sp);
-	  fprintf (out, "    %s  ->  ", escape (symbols[rule_table[rule].lhs]->tag));
+	  fprintf (out, "    %s  ->  ", escape (symbols[rules[rule].lhs]->tag));
 
-	  for (sp = ritem + rule_table[rule].rhs; sp < sp1; sp++)
+	  for (sp = ritem + rules[rule].rhs; sp < sp1; sp++)
 	    fprintf (out, "%s ", escape (symbols[*sp]->tag));
 
 	  fputc ('.', out);
@@ -188,7 +188,7 @@ print_reductions (FILE *out, state_t *state)
   if (state->consistent)
     {
       int rule = redp->rules[0];
-      int symbol = rule_table[rule].lhs;
+      int symbol = rules[rule].lhs;
       fprintf (out, _("    $default\treduce using rule %d (%s)\n\n"),
 	       rule - 1, escape (symbols[symbol]->tag));
       return;
@@ -223,10 +223,10 @@ print_reductions (FILE *out, state_t *state)
 	if (BITISSET (lookaheadset, i))
 	  fprintf (out, _("    %-4s\t[reduce using rule %d (%s)]\n"),
 		   escape (symbols[i]->tag), default_rule - 1,
-		   escape2 (symbols[rule_table[default_rule].lhs]->tag));
+		   escape2 (symbols[rules[default_rule].lhs]->tag));
 
       fprintf (out, _("    $default\treduce using rule %d (%s)\n\n"),
-	       default_rule - 1, escape (symbols[rule_table[default_rule].lhs]->tag));
+	       default_rule - 1, escape (symbols[rules[default_rule].lhs]->tag));
     }
   else if (state->nlookaheads >= 1)
     {
@@ -282,7 +282,7 @@ print_reductions (FILE *out, state_t *state)
 				 _("    %-4s\treduce using rule %d (%s)\n"),
 				 escape (symbols[i]->tag),
 				 LAruleno[state->lookaheadsp + j] - 1,
-				 escape2 (symbols[rule_table[LAruleno[state->lookaheadsp + j]].lhs]->tag));
+				 escape2 (symbols[rules[LAruleno[state->lookaheadsp + j]].lhs]->tag));
 		      else
 			defaulted = 1;
 
@@ -295,13 +295,13 @@ print_reductions (FILE *out, state_t *state)
 				 _("    %-4s\treduce using rule %d (%s)\n"),
 				 escape (symbols[i]->tag),
 				 LAruleno[default_LA] - 1,
-				 escape2 (symbols[rule_table[LAruleno[default_LA]].lhs]->tag));
+				 escape2 (symbols[rules[LAruleno[default_LA]].lhs]->tag));
 		      defaulted = 0;
 		      fprintf (out,
 			       _("    %-4s\t[reduce using rule %d (%s)]\n"),
 			       escape (symbols[i]->tag),
 			       LAruleno[state->lookaheadsp + j] - 1,
-			       escape2 (symbols[rule_table[LAruleno[state->lookaheadsp + j]].lhs]->tag));
+			       escape2 (symbols[rules[LAruleno[state->lookaheadsp + j]].lhs]->tag));
 		    }
 		}
 	    }
@@ -310,7 +310,7 @@ print_reductions (FILE *out, state_t *state)
       if (default_LA >= 0)
 	fprintf (out, _("    $default\treduce using rule %d (%s)\n"),
 		 default_rule - 1,
-		 escape (symbols[rule_table[default_rule].lhs]->tag));
+		 escape (symbols[rules[default_rule].lhs]->tag));
     }
 }
 
@@ -374,11 +374,11 @@ print_grammar (FILE *out)
   fprintf (out, "  %s\n", _("Number, Line, Rule"));
   for (i = 1; i <= nrules; i++)
     /* Don't print rules disabled in reduce_grammar_tables.  */
-    if (rule_table[i].useful)
+    if (rules[i].useful)
       {
 	fprintf (out, _("  %3d %3d %s ->"),
-		 i - 1, rule_table[i].line, escape (symbols[rule_table[i].lhs]->tag));
-	rule = &ritem[rule_table[i].rhs];
+		 i - 1, rules[i].line, escape (symbols[rules[i].lhs]->tag));
+	rule = &ritem[rules[i].rhs];
 	if (*rule >= 0)
 	  while (*rule >= 0)
 	    fprintf (out, " %s", escape (symbols[*rule++]->tag));
@@ -401,7 +401,7 @@ print_grammar (FILE *out)
 	sprintf (buffer, " (%d)", i);
 
 	for (j = 1; j <= nrules; j++)
-	  for (rule = &ritem[rule_table[j].rhs]; *rule >= 0; rule++)
+	  for (rule = &ritem[rules[j].rhs]; *rule >= 0; rule++)
 	    if (*rule == token_translations[i])
 	      {
 		END_TEST (65);
@@ -420,9 +420,9 @@ print_grammar (FILE *out)
 
       for (j = 1; j <= nrules; j++)
 	{
-	  if (rule_table[j].lhs == i)
+	  if (rules[j].lhs == i)
 	    left_count++;
-	  for (rule = &ritem[rule_table[j].rhs]; *rule >= 0; rule++)
+	  for (rule = &ritem[rules[j].rhs]; *rule >= 0; rule++)
 	    if (*rule == i)
 	      {
 		right_count++;
@@ -444,7 +444,7 @@ print_grammar (FILE *out)
 	  for (j = 1; j <= nrules; j++)
 	    {
 	      END_TEST (65);
-	      if (rule_table[j].lhs == i)
+	      if (rules[j].lhs == i)
 		sprintf (buffer + strlen (buffer), " %d", j - 1);
 	    }
 	}
@@ -457,7 +457,7 @@ print_grammar (FILE *out)
 	  sprintf (buffer + strlen (buffer), _(" on right:"));
 	  for (j = 1; j <= nrules; j++)
 	    {
-	      for (rule = &ritem[rule_table[j].rhs]; *rule >= 0; rule++)
+	      for (rule = &ritem[rules[j].rhs]; *rule >= 0; rule++)
 		if (*rule == i)
 		  {
 		    END_TEST (65);
