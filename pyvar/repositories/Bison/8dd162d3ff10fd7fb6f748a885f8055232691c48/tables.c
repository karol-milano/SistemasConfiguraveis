@@ -194,7 +194,7 @@ conflict_row (state *s)
 	/* Find all reductions for token J, and record all that do not
 	   match ACTROW[J].  */
 	for (i = 0; i < reds->num; i += 1)
-	  if (bitset_test (reds->lookaheads[i], j)
+	  if (bitset_test (reds->look_ahead_tokens[i], j)
 	      && (actrow[j]
 		  != rule_number_as_item_number (reds->rules[i]->number)))
 	    {
@@ -215,8 +215,8 @@ conflict_row (state *s)
 
 
 /*------------------------------------------------------------------.
-| Decide what to do for each type of token if seen as the lookahead |
-| token in specified state.  The value returned is used as the      |
+| Decide what to do for each type of token if seen as the           |
+| look-ahead in specified state.  The value returned is used as the |
 | default action (yydefact) for the state.  In addition, ACTROW is  |
 | filled with what to do for each kind of token, index by symbol    |
 | number, with zero meaning do the default action.  The value       |
@@ -224,7 +224,7 @@ conflict_row (state *s)
 | situation is an error.  The parser recognizes this value	    |
 | specially.							    |
 |                                                                   |
-| This is where conflicts are resolved.  The loop over lookahead    |
+| This is where conflicts are resolved.  The loop over look-ahead   |
 | rules considered lower-numbered rules last, and the last rule     |
 | considered that likes a token gets to handle it.                  |
 |                                                                   |
@@ -249,17 +249,17 @@ action_row (state *s)
   for (i = 0; i < ntokens; i++)
     actrow[i] = conflrow[i] = 0;
 
-  if (reds->lookaheads)
+  if (reds->look_ahead_tokens)
     {
       int j;
       bitset_iterator biter;
       /* loop over all the rules available here which require
-	 lookahead (in reverse order to give precedence to the first
+	 look-ahead (in reverse order to give precedence to the first
 	 rule) */
       for (i = reds->num - 1; i >= 0; --i)
 	/* and find each token which the rule finds acceptable
 	   to come next */
-	BITSET_FOR_EACH (biter, reds->lookaheads[i], j, 0)
+	BITSET_FOR_EACH (biter, reds->look_ahead_tokens[i], j, 0)
 	{
 	  /* and record this rule as the rule to use if that
 	     token follows.  */
@@ -406,7 +406,7 @@ save_row (state_number s)
 
 /*------------------------------------------------------------------.
 | Figure out the actions for the specified state, indexed by        |
-| lookahead token type.                                             |
+| look-ahead token type.                                            |
 |                                                                   |
 | The YYDEFACT table is output now.  The detailed info is saved for |
 | putting into YYTABLE later.                                       |
