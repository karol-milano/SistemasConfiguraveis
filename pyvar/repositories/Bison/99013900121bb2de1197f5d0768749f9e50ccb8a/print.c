@@ -96,7 +96,7 @@ print_core (FILE *out, state_t *state)
 	  rule = -(*sp);
 	  fprintf (out, "    %s  ->  ", escape (symbols[rules[rule].lhs]->tag));
 
-	  for (sp = ritem + rules[rule].rhs; sp < sp1; sp++)
+	  for (sp = rules[rule].rhs; sp < sp1; sp++)
 	    fprintf (out, "%s ", escape (symbols[*sp]->tag));
 
 	  fputc ('.', out);
@@ -371,7 +371,7 @@ print_grammar (FILE *out)
       {
 	fprintf (out, _("  %3d %3d %s ->"),
 		 i - 1, rules[i].line, escape (symbols[rules[i].lhs]->tag));
-	rule = &ritem[rules[i].rhs];
+	rule = rules[i].rhs;
 	if (*rule >= 0)
 	  while (*rule >= 0)
 	    fprintf (out, " %s", escape (symbols[*rule++]->tag));
@@ -394,7 +394,7 @@ print_grammar (FILE *out)
 	sprintf (buffer, " (%d)", i);
 
 	for (j = 1; j <= nrules; j++)
-	  for (rule = &ritem[rules[j].rhs]; *rule >= 0; rule++)
+	  for (rule = rules[j].rhs; *rule >= 0; rule++)
 	    if (*rule == token_translations[i])
 	      {
 		END_TEST (65);
@@ -415,7 +415,7 @@ print_grammar (FILE *out)
 	{
 	  if (rules[j].lhs == i)
 	    left_count++;
-	  for (rule = &ritem[rules[j].rhs]; *rule >= 0; rule++)
+	  for (rule = rules[j].rhs; *rule >= 0; rule++)
 	    if (*rule == i)
 	      {
 		right_count++;
@@ -450,7 +450,7 @@ print_grammar (FILE *out)
 	  sprintf (buffer + strlen (buffer), _(" on right:"));
 	  for (j = 1; j <= nrules; j++)
 	    {
-	      for (rule = &ritem[rules[j].rhs]; *rule >= 0; rule++)
+	      for (rule = rules[j].rhs; *rule >= 0; rule++)
 		if (*rule == i)
 		  {
 		    END_TEST (65);
