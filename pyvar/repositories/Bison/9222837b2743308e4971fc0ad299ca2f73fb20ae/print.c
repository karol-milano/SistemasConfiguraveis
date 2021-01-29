@@ -354,7 +354,6 @@ static void
 print_grammar (FILE *out)
 {
   symbol_number_t i;
-  item_number_t *rule;
   char buffer[90];
   int column = 0;
 
@@ -366,7 +365,9 @@ print_grammar (FILE *out)
     if (token_translations[i] != undeftoken->number)
       {
 	const char *tag = symbol_tag_get (symbols[token_translations[i]]);
-	int r;
+	rule_number_t r;
+	item_number_t *rhsp;
+
 	buffer[0] = 0;
 	column = strlen (tag);
 	fputs (tag, out);
@@ -374,8 +375,8 @@ print_grammar (FILE *out)
 	sprintf (buffer, " (%d)", i);
 
 	for (r = 1; r < nrules + 1; r++)
-	  for (rule = rules[r].rhs; *rule >= 0; rule++)
-	    if (item_number_as_symbol_number (*rule) == token_translations[i])
+	  for (rhsp = rules[r].rhs; *rhsp >= 0; rhsp++)
+	    if (item_number_as_symbol_number (*rhsp) == token_translations[i])
 	      {
 		END_TEST (65);
 		sprintf (buffer + strlen (buffer), " %d", r - 1);
@@ -390,15 +391,16 @@ print_grammar (FILE *out)
   for (i = ntokens; i < nsyms; i++)
     {
       int left_count = 0, right_count = 0;
-      int r;
+      rule_number_t r;
       const char *tag = symbol_tag_get (symbols[i]);
 
       for (r = 1; r < nrules + 1; r++)
 	{
+	  item_number_t *rhsp;
 	  if (rules[r].lhs->number == i)
 	    left_count++;
-	  for (rule = rules[r].rhs; *rule >= 0; rule++)
-	    if (item_number_as_symbol_number (*rule) == i)
+	  for (rhsp = rules[r].rhs; *rhsp >= 0; rhsp++)
+	    if (item_number_as_symbol_number (*rhsp) == i)
 	      {
 		right_count++;
 		break;
@@ -432,8 +434,9 @@ print_grammar (FILE *out)
 	  sprintf (buffer + strlen (buffer), _(" on right:"));
 	  for (r = 1; r < nrules + 1; r++)
 	    {
-	      for (rule = rules[r].rhs; *rule >= 0; rule++)
-		if (item_number_as_symbol_number (*rule) == i)
+	      item_number_t *rhsp;
+	      for (rhsp = rules[r].rhs; *rhsp >= 0; rhsp++)
+		if (item_number_as_symbol_number (*rhsp) == i)
 		  {
 		    END_TEST (65);
 		    sprintf (buffer + strlen (buffer), " %d", r - 1);
