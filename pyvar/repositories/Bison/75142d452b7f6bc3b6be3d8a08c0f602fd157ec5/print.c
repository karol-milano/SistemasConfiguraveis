@@ -88,7 +88,7 @@ print_core (FILE *out, state_t *state)
 
 	  sp1 = sp = ritem + sitems[i];
 
-	  while (*sp > 0)
+	  while (*sp >= 0)
 	    sp++;
 
 	  rule = -(*sp);
@@ -99,7 +99,7 @@ print_core (FILE *out, state_t *state)
 
 	  fputc ('.', out);
 
-	  for (/* Nothing */; *sp > 0; ++sp)
+	  for (/* Nothing */; *sp >= 0; ++sp)
 	    fprintf (out, " %s", escape (tags[*sp]));
 
 	  fprintf (out, _("   (rule %d)"), rule);
@@ -377,8 +377,8 @@ print_grammar (FILE *out)
 	fprintf (out, _("  %3d %3d %s ->"),
 		 i, rule_table[i].line, escape (tags[rule_table[i].lhs]));
 	rule = &ritem[rule_table[i].rhs];
-	if (*rule > 0)
-	  while (*rule > 0)
+	if (*rule >= 0)
+	  while (*rule >= 0)
 	    fprintf (out, " %s", escape (tags[*rule++]));
 	else
 	  fprintf (out, " /* %s */", _("empty"));
@@ -399,7 +399,7 @@ print_grammar (FILE *out)
 	sprintf (buffer, " (%d)", i);
 
 	for (j = 1; j <= nrules; j++)
-	  for (rule = &ritem[rule_table[j].rhs]; *rule > 0; rule++)
+	  for (rule = &ritem[rule_table[j].rhs]; *rule >= 0; rule++)
 	    if (*rule == token_translations[i])
 	      {
 		END_TEST (65);
@@ -420,7 +420,7 @@ print_grammar (FILE *out)
 	{
 	  if (rule_table[j].lhs == i)
 	    left_count++;
-	  for (rule = &ritem[rule_table[j].rhs]; *rule > 0; rule++)
+	  for (rule = &ritem[rule_table[j].rhs]; *rule >= 0; rule++)
 	    if (*rule == i)
 	      {
 		right_count++;
@@ -455,7 +455,7 @@ print_grammar (FILE *out)
 	  sprintf (buffer + strlen (buffer), _(" on right:"));
 	  for (j = 1; j <= nrules; j++)
 	    {
-	      for (rule = &ritem[rule_table[j].rhs]; *rule > 0; rule++)
+	      for (rule = &ritem[rule_table[j].rhs]; *rule >= 0; rule++)
 		if (*rule == i)
 		  {
 		    END_TEST (65);
