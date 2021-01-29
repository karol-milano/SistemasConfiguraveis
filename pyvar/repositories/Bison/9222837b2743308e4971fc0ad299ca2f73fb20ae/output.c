@@ -294,7 +294,7 @@ prepare_tokens (void)
 static void
 prepare_rules (void)
 {
-  int r;
+  rule_number_t r;
   unsigned int i = 0;
   item_number_t *rhs = XMALLOC (item_number_t, nritems);
   unsigned int *prhs = XMALLOC (unsigned int, nrules + 1);
@@ -306,7 +306,7 @@ prepare_rules (void)
 
   for (r = 1; r < nrules + 1; ++r)
     {
-      item_number_t *rhsp;
+      item_number_t *rhsp = NULL;
       /* Index of rule R in RHS. */
       prhs[r] = i;
       /* RHS of the rule R. */
@@ -428,7 +428,7 @@ static int
 action_row (state_t *state)
 {
   int i;
-  int default_rule = 0;
+  rule_number_t default_rule = 0;
   reductions_t *redp = state->reductions;
   shifts_t *shiftp = state->shifts;
   errs_t *errp = state->errs;
@@ -504,8 +504,8 @@ action_row (state_t *state)
 	  for (i = 0; i < state->nlookaheads; i++)
 	    {
 	      int count = 0;
-	      int rule = -state->lookaheads_rule[i]->number;
-	      int j;
+	      rule_number_t rule = -state->lookaheads_rule[i]->number;
+	      symbol_number_t j;
 
 	      for (j = 0; j < ntokens; j++)
 		if (actrow[j] == rule)
@@ -638,21 +638,21 @@ token_actions (void)
 void
 actions_output (FILE *out)
 {
-  int rule;
+  rule_number_t r;
 
   fputs ("m4_define([b4_actions], \n[[", out);
-  for (rule = 1; rule < nrules + 1; ++rule)
-    if (rules[rule].action)
+  for (r = 1; r < nrules + 1; ++r)
+    if (rules[r].action)
       {
-	fprintf (out, "  case %d:\n", rule);
+	fprintf (out, "  case %d:\n", r);
 
 	if (!no_lines_flag)
 	  fprintf (out, muscle_find ("linef"),
-		   rules[rule].action_location.first_line,
+		   rules[r].action_location.first_line,
 		   quotearg_style (c_quoting_style,
 				   muscle_find ("filename")));
 	fprintf (out, "    %s\n    break;\n\n",
-		 rules[rule].action);
+		 rules[r].action);
       }
   fputs ("]])\n\n", out);
 }
