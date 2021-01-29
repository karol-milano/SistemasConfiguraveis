@@ -494,15 +494,15 @@ conflict_row (state_t *state)
 | that has any such conflicts.                                      |
 `------------------------------------------------------------------*/
 
-static rule_number_t
+static rule_t *
 action_row (state_t *state)
 {
   int i;
-  rule_number_t default_rule = -1;
+  rule_t *default_rule = NULL;
   reductions_t *redp = state->reductions;
   transitions_t *transitions = state->transitions;
   errs_t *errp = state->errs;
-  /* set nonzero to inhibit having any default reduction */
+  /* Set to nonzero to inhibit having any default reduction.  */
   int nodefault = 0;
   int conflicted = 0;
 
@@ -531,28 +531,27 @@ action_row (state_t *state)
   /* Now see which tokens are allowed for shifts in this state.  For
      them, record the shift as the thing to do.  So shift is preferred
      to reduce.  */
-  for (i = 0; i < transitions->num && TRANSITION_IS_SHIFT (transitions, i); i++)
-    if (!TRANSITION_IS_DISABLED (transitions, i))
-      {
-	symbol_number_t symbol = TRANSITION_SYMBOL (transitions, i);
-	state_number_t shift_state = transitions->states[i];
+  FOR_EACH_SHIFT (transitions, i)
+    {
+      symbol_number_t symbol = TRANSITION_SYMBOL (transitions, i);
+      state_t *shift_state = transitions->states[i];
 
-	if (actrow[symbol] != 0)
-	  conflicted = conflrow[symbol] = 1;
-	actrow[symbol] = state_number_as_int (shift_state);
+      if (actrow[symbol] != 0)
+	conflicted = conflrow[symbol] = 1;
+      actrow[symbol] = state_number_as_int (shift_state->number);
 
-	/* Do not use any default reduction if there is a shift for
-	   error */
-	if (symbol == errtoken->number)
-	  nodefault = 1;
-      }
+      /* Do not use any default reduction if there is a shift for
+	 error */
+      if (symbol == errtoken->number)
+	nodefault = 1;
+    }
 
   /* See which tokens are an explicit error in this state (due to
      %nonassoc).  For them, record ACTION_MIN as the action.  */
   for (i = 0; i < errp->num; i++)
     {
-      symbol_number_t symbol = errp->symbols[i];
-      actrow[symbol] = ACTION_MIN;
+      symbol_t *symbol = errp->symbols[i];
+      actrow[symbol->number] = ACTION_MIN;
     }
 
   /* Now find the most common reduction and make it the default action
@@ -568,11 +567,11 @@ action_row (state_t *state)
 	  for (i = 0; i < state->nlookaheads; i++)
 	    {
 	      int count = 0;
-	      rule_number_t rule = state->lookaheads_rule[i]->number;
+	      rule_t *rule = state->lookaheads_rule[i];
 	      symbol_number_t j;
 
 	      for (j = 0; j < ntokens; j++)
-		if (actrow[j] == rule_number_as_item_number (rule))
+		if (actrow[j] == rule_number_as_item_number (rule->number))
 		  count++;
 
 	      if (count > max)
@@ -592,7 +591,7 @@ action_row (state_t *state)
 	    {
 	      int j;
 	      for (j = 0; j < ntokens; j++)
-		if (actrow[j] == rule_number_as_item_number (default_rule)
+		if (actrow[j] == rule_number_as_item_number (default_rule->number)
 		    && ! (glr_parser && conflrow[j]))
 		  actrow[j] = 0;
 	    }
@@ -602,7 +601,7 @@ action_row (state_t *state)
   /* If have no default rule, the default is an error.
      So replace any action which says "error" with "use default".  */
 
-  if (default_rule == -1)
+  if (!default_rule)
     for (i = 0; i < ntokens; i++)
       if (actrow[i] == ACTION_MIN)
 	actrow[i] = 0;
@@ -690,7 +689,8 @@ token_actions (void)
 
   for (i = 0; i < nstates; ++i)
     {
-      yydefact[i] = action_row (states[i]) + 1;
+      rule_t *default_rule = action_row (states[i]);
+      yydefact[i] = default_rule ? default_rule->number + 1 : 0;
       save_row (i);
     }
 
