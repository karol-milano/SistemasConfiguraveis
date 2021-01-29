@@ -149,7 +149,7 @@ print_shifts (FILE *out, state_t *state)
     if (!SHIFT_IS_DISABLED (shiftp, i))
       {
 	int state1 = shiftp->shifts[i];
-	token_number_t symbol = states[state1]->accessing_symbol;
+	symbol_number_t symbol = states[state1]->accessing_symbol;
 	fprintf (out,
 		 _("    %-4s\tshift, and go to state %d\n"),
 		 escape (symbols[symbol]->tag), state1);
@@ -191,7 +191,7 @@ print_gotos (FILE *out, state_t *state)
 	if (!SHIFT_IS_DISABLED (shiftp, i))
 	  {
 	    int state1 = shiftp->shifts[i];
-	    token_number_t symbol = states[state1]->accessing_symbol;
+	    symbol_number_t symbol = states[state1]->accessing_symbol;
 	    fprintf (out, _("    %-4s\tgo to state %d\n"),
 		     escape (symbols[symbol]->tag), state1);
 	  }
@@ -215,7 +215,7 @@ print_reductions (FILE *out, state_t *state)
   if (state->consistent)
     {
       int rule = redp->rules[0];
-      token_number_t symbol = rules[rule].lhs->number;
+      symbol_number_t symbol = rules[rule].lhs->number;
       fprintf (out, _("    $default\treduce using rule %d (%s)\n\n"),
 	       rule - 1, escape (symbols[symbol]->tag));
       return;
@@ -385,7 +385,7 @@ do {						\
 static void
 print_grammar (FILE *out)
 {
-  token_number_t i;
+  symbol_number_t i;
   int j;
   item_number_t *rule;
   char buffer[90];
@@ -422,7 +422,7 @@ print_grammar (FILE *out)
 
 	for (j = 1; j < nrules + 1; j++)
 	  for (rule = rules[j].rhs; *rule >= 0; rule++)
-	    if (item_number_as_token_number (*rule) == token_translations[i])
+	    if (item_number_as_symbol_number (*rule) == token_translations[i])
 	      {
 		END_TEST (65);
 		sprintf (buffer + strlen (buffer), " %d", j - 1);
@@ -443,7 +443,7 @@ print_grammar (FILE *out)
 	  if (rules[j].lhs->number == i)
 	    left_count++;
 	  for (rule = rules[j].rhs; *rule >= 0; rule++)
-	    if (item_number_as_token_number (*rule) == i)
+	    if (item_number_as_symbol_number (*rule) == i)
 	      {
 		right_count++;
 		break;
@@ -478,7 +478,7 @@ print_grammar (FILE *out)
 	  for (j = 1; j < nrules + 1; j++)
 	    {
 	      for (rule = rules[j].rhs; *rule >= 0; rule++)
-		if (item_number_as_token_number (*rule) == i)
+		if (item_number_as_symbol_number (*rule) == i)
 		  {
 		    END_TEST (65);
 		    sprintf (buffer + strlen (buffer), " %d", j - 1);
