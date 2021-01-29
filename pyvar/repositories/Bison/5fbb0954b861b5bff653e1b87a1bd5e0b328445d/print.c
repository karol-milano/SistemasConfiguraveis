@@ -124,7 +124,7 @@ print_shifts (FILE *out, state_t *state)
     if (!SHIFT_IS_DISABLED (shiftp, i))
       {
 	int state1 = shiftp->shifts[i];
-	int symbol = states[state1]->accessing_symbol;
+	token_number_t symbol = states[state1]->accessing_symbol;
 	fprintf (out,
 		 _("    %-4s\tshift, and go to state %d\n"),
 		 escape (symbols[symbol]->tag), state1);
@@ -166,7 +166,7 @@ print_gotos (FILE *out, state_t *state)
 	if (!SHIFT_IS_DISABLED (shiftp, i))
 	  {
 	    int state1 = shiftp->shifts[i];
-	    int symbol = states[state1]->accessing_symbol;
+	    token_number_t symbol = states[state1]->accessing_symbol;
 	    fprintf (out, _("    %-4s\tgo to state %d\n"),
 		     escape (symbols[symbol]->tag), state1);
 	  }
@@ -190,7 +190,7 @@ print_reductions (FILE *out, state_t *state)
   if (state->consistent)
     {
       int rule = redp->rules[0];
-      int symbol = rules[rule].lhs->number;
+      token_number_t symbol = rules[rule].lhs->number;
       fprintf (out, _("    $default\treduce using rule %d (%s)\n\n"),
 	       rule - 1, escape (symbols[symbol]->tag));
       return;
@@ -360,7 +360,8 @@ do {						\
 static void
 print_grammar (FILE *out)
 {
-  int i, j;
+  token_number_t i;
+  int j;
   item_number_t *rule;
   char buffer[90];
   int column = 0;
@@ -368,11 +369,11 @@ print_grammar (FILE *out)
   /* rule # : LHS -> RHS */
   fprintf (out, "%s\n\n", _("Grammar"));
   fprintf (out, "  %s\n", _("Number, Line, Rule"));
-  for (i = 1; i < nrules + 1; i++)
+  for (j = 1; j < nrules + 1; j++)
     {
       fprintf (out, _("  %3d %3d %s ->"),
-	       i - 1, rules[i].line, escape (rules[i].lhs->tag));
-      rule = rules[i].rhs;
+	       j - 1, rules[j].line, escape (rules[j].lhs->tag));
+      rule = rules[j].rhs;
       if (*rule >= 0)
 	while (*rule >= 0)
 	  fprintf (out, " %s", escape (symbols[*rule++]->tag));
@@ -396,7 +397,7 @@ print_grammar (FILE *out)
 
 	for (j = 1; j < nrules + 1; j++)
 	  for (rule = rules[j].rhs; *rule >= 0; rule++)
-	    if (*rule == token_translations[i])
+	    if (item_number_as_token_number (*rule) == token_translations[i])
 	      {
 		END_TEST (65);
 		sprintf (buffer + strlen (buffer), " %d", j - 1);
@@ -417,7 +418,7 @@ print_grammar (FILE *out)
 	  if (rules[j].lhs->number == i)
 	    left_count++;
 	  for (rule = rules[j].rhs; *rule >= 0; rule++)
-	    if (*rule == i)
+	    if (item_number_as_token_number (*rule) == i)
 	      {
 		right_count++;
 		break;
@@ -452,7 +453,7 @@ print_grammar (FILE *out)
 	  for (j = 1; j < nrules + 1; j++)
 	    {
 	      for (rule = rules[j].rhs; *rule >= 0; rule++)
-		if (*rule == i)
+		if (item_number_as_token_number (*rule) == i)
 		  {
 		    END_TEST (65);
 		    sprintf (buffer + strlen (buffer), " %d", j - 1);
