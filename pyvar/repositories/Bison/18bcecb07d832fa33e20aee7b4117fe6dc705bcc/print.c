@@ -365,7 +365,7 @@ print_grammar (FILE *out)
   /* rule # : LHS -> RHS */
   fprintf (out, "%s\n\n", _("Grammar"));
   fprintf (out, "  %s\n", _("Number, Line, Rule"));
-  for (i = 1; i <= nrules; i++)
+  for (i = 1; i < nrules + 1; i++)
     /* Don't print rules disabled in reduce_grammar_tables.  */
     if (rules[i].useful)
       {
@@ -384,7 +384,7 @@ print_grammar (FILE *out)
 
   /* TERMINAL (type #) : rule #s terminal is on RHS */
   fprintf (out, "%s\n\n", _("Terminals, with rules where they appear"));
-  for (i = 0; i <= max_user_token_number; i++)
+  for (i = 0; i < max_user_token_number + 1; i++)
     if (token_translations[i] != 2)
       {
 	buffer[0] = 0;
@@ -393,7 +393,7 @@ print_grammar (FILE *out)
 	END_TEST (50);
 	sprintf (buffer, " (%d)", i);
 
-	for (j = 1; j <= nrules; j++)
+	for (j = 1; j < nrules + 1; j++)
 	  for (rule = rules[j].rhs; *rule >= 0; rule++)
 	    if (*rule == token_translations[i])
 	      {
@@ -407,11 +407,11 @@ print_grammar (FILE *out)
 
 
   fprintf (out, "%s\n\n", _("Nonterminals, with rules where they appear"));
-  for (i = ntokens; i <= nsyms - 1; i++)
+  for (i = ntokens; i < nsyms; i++)
     {
       int left_count = 0, right_count = 0;
 
-      for (j = 1; j <= nrules; j++)
+      for (j = 1; j < nrules + 1; j++)
 	{
 	  if (rules[j].lhs == i)
 	    left_count++;
@@ -434,7 +434,7 @@ print_grammar (FILE *out)
 	  END_TEST (50);
 	  sprintf (buffer + strlen (buffer), _(" on left:"));
 
-	  for (j = 1; j <= nrules; j++)
+	  for (j = 1; j < nrules + 1; j++)
 	    {
 	      END_TEST (65);
 	      if (rules[j].lhs == i)
@@ -448,7 +448,7 @@ print_grammar (FILE *out)
 	    sprintf (buffer + strlen (buffer), ",");
 	  END_TEST (50);
 	  sprintf (buffer + strlen (buffer), _(" on right:"));
-	  for (j = 1; j <= nrules; j++)
+	  for (j = 1; j < nrules + 1; j++)
 	    {
 	      for (rule = rules[j].rhs; *rule >= 0; rule++)
 		if (*rule == i)
