@@ -239,6 +239,7 @@ static void
 conflict_row (state_t *state)
 {
   int i, j;
+  reductions_t *reds = state->reductions;
 
   if (! glr_parser)
     return;
@@ -250,14 +251,13 @@ conflict_row (state_t *state)
 
 	/* Find all reductions for token J, and record all that do not
 	   match ACTROW[J].  */
-	for (i = 0; i < state->nlookaheads; i += 1)
-	  if (bitset_test (state->lookaheads[i], j)
+	for (i = 0; i < reds->num; i += 1)
+	  if (bitset_test (reds->lookaheads[i], j)
 	      && (actrow[j]
-		  != rule_number_as_item_number (state->lookaheads_rule[i]->number)))
+		  != rule_number_as_item_number (reds->rules[i]->number)))
 	    {
 	      assert (conflict_list_free > 0);
-	      conflict_list[conflict_list_cnt]
-		= state->lookaheads_rule[i]->number + 1;
+	      conflict_list[conflict_list_cnt] = reds->rules[i]->number + 1;
 	      conflict_list_cnt += 1;
 	      conflict_list_free -= 1;
 	    }
@@ -304,22 +304,23 @@ action_row (state_t *state)
   for (i = 0; i < ntokens; i++)
     actrow[i] = conflrow[i] = 0;
 
-  if (redp->num >= 1)
+  if (redp->lookaheads)
     {
       int j;
       bitset_iterator biter;
       /* loop over all the rules available here which require
-	 lookahead */
-      for (i = state->nlookaheads - 1; i >= 0; --i)
+	 lookahead (in reverse order to give precedence to the first
+	 rule) */
+      for (i = redp->num - 1; i >= 0; --i)
 	/* and find each token which the rule finds acceptable
 	   to come next */
-	BITSET_FOR_EACH (biter, state->lookaheads[i], j, 0)
+	BITSET_FOR_EACH (biter, redp->lookaheads[i], j, 0)
 	{
 	  /* and record this rule as the rule to use if that
 	     token follows.  */
 	  if (actrow[j] != 0)
 	    conflicted = conflrow[j] = 1;
-	  actrow[j] = rule_number_as_item_number (state->lookaheads_rule[i]->number);
+	  actrow[j] = rule_number_as_item_number (redp->rules[i]->number);
 	}
     }
 
@@ -359,10 +360,10 @@ action_row (state_t *state)
       else
 	{
 	  int max = 0;
-	  for (i = 0; i < state->nlookaheads; i++)
+	  for (i = 0; i < redp->num; i++)
 	    {
 	      int count = 0;
-	      rule_t *rule = state->lookaheads_rule[i];
+	      rule_t *rule = redp->rules[i];
 	      symbol_number_t j;
 
 	      for (j = 0; j < ntokens; j++)
