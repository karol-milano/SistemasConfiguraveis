@@ -68,9 +68,9 @@ print_core (FILE *out, int state)
 	sp++;
 
       rule = -(*sp);
-      fprintf (out, "    %s  ->  ", tags[rlhs[rule]]);
+      fprintf (out, "    %s  ->  ", tags[rule_table[rule].lhs]);
 
-      for (sp = ritem + rrhs[rule]; sp < sp1; sp++)
+      for (sp = ritem + rule_table[rule].rhs; sp < sp1; sp++)
 	{
 	  fprintf (out, "%s ", tags[*sp]);
 	}
@@ -168,7 +168,7 @@ print_actions (FILE *out, int state)
   if (state_table[state].consistent && redp)
     {
       rule = redp->rules[0];
-      symbol = rlhs[rule];
+      symbol = rule_table[rule].lhs;
       fprintf (out, _("    $default\treduce using rule %d (%s)\n\n"),
 	       rule, tags[symbol]);
     }
@@ -230,10 +230,10 @@ print_grammar (FILE *out)
   fprintf (out, "\n%s\n\n", _("Grammar"));
   for (i = 1; i <= nrules; i++)
     /* Don't print rules disabled in reduce_grammar_tables.  */
-    if (rlhs[i] >= 0)
+    if (rule_table[i].lhs >= 0)
       {
-	fprintf (out, _("rule %-4d %s ->"), i, tags[rlhs[i]]);
-	rule = &ritem[rrhs[i]];
+	fprintf (out, _("rule %-4d %s ->"), i, tags[rule_table[i].lhs]);
+	rule = &ritem[rule_table[i].rhs];
 	if (*rule > 0)
 	  while (*rule > 0)
 	    fprintf (out, " %s", tags[*rule++]);
@@ -256,7 +256,7 @@ print_grammar (FILE *out)
 	sprintf (buffer, " (%d)", i);
 
 	for (j = 1; j <= nrules; j++)
-	  for (rule = &ritem[rrhs[j]]; *rule > 0; rule++)
+	  for (rule = &ritem[rule_table[j].rhs]; *rule > 0; rule++)
 	    if (*rule == token_translations[i])
 	      {
 		END_TEST (65);
@@ -274,9 +274,9 @@ print_grammar (FILE *out)
 
       for (j = 1; j <= nrules; j++)
 	{
-	  if (rlhs[j] == i)
+	  if (rule_table[j].lhs == i)
 	    left_count++;
-	  for (rule = &ritem[rrhs[j]]; *rule > 0; rule++)
+	  for (rule = &ritem[rule_table[j].rhs]; *rule > 0; rule++)
 	    if (*rule == i)
 	      {
 		right_count++;
@@ -298,7 +298,7 @@ print_grammar (FILE *out)
 	  for (j = 1; j <= nrules; j++)
 	    {
 	      END_TEST (65);
-	      if (rlhs[j] == i)
+	      if (rule_table[j].lhs == i)
 		sprintf (buffer + strlen (buffer), " %d", j);
 	    }
 	}
@@ -311,7 +311,7 @@ print_grammar (FILE *out)
 	  sprintf (buffer + strlen (buffer), _(" on right:"));
 	  for (j = 1; j <= nrules; j++)
 	    {
-	      for (rule = &ritem[rrhs[j]]; *rule > 0; rule++)
+	      for (rule = &ritem[rule_table[j].rhs]; *rule > 0; rule++)
 		if (*rule == i)
 		  {
 		    END_TEST (65);
