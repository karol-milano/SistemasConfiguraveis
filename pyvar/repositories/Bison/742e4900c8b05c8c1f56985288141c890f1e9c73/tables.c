@@ -198,7 +198,7 @@ conflict_row (state *s)
 	/* Find all reductions for token J, and record all that do not
 	   match ACTROW[J].  */
 	for (i = 0; i < reds->num; i += 1)
-	  if (bitset_test (reds->look_ahead_tokens[i], j)
+	  if (bitset_test (reds->lookahead_tokens[i], j)
 	      && (actrow[j]
 		  != rule_number_as_item_number (reds->rules[i]->number)))
 	    {
@@ -219,7 +219,7 @@ conflict_row (state *s)
 
 /*------------------------------------------------------------------.
 | Decide what to do for each type of token if seen as the           |
-| look-ahead in specified state.  The value returned is used as the |
+| lookahead in specified state.  The value returned is used as the  |
 | default action (yydefact) for the state.  In addition, ACTROW is  |
 | filled with what to do for each kind of token, index by symbol    |
 | number, with zero meaning do the default action.  The value       |
@@ -227,7 +227,7 @@ conflict_row (state *s)
 | situation is an error.  The parser recognizes this value	    |
 | specially.							    |
 |                                                                   |
-| This is where conflicts are resolved.  The loop over look-ahead   |
+| This is where conflicts are resolved.  The loop over lookahead    |
 | rules considered lower-numbered rules last, and the last rule     |
 | considered that likes a token gets to handle it.                  |
 |                                                                   |
@@ -252,17 +252,17 @@ action_row (state *s)
   for (i = 0; i < ntokens; i++)
     actrow[i] = conflrow[i] = 0;
 
-  if (reds->look_ahead_tokens)
+  if (reds->lookahead_tokens)
     {
       int j;
       bitset_iterator biter;
       /* loop over all the rules available here which require
-	 look-ahead (in reverse order to give precedence to the first
+	 lookahead (in reverse order to give precedence to the first
 	 rule) */
       for (i = reds->num - 1; i >= 0; --i)
 	/* and find each token which the rule finds acceptable
 	   to come next */
-	BITSET_FOR_EACH (biter, reds->look_ahead_tokens[i], j, 0)
+	BITSET_FOR_EACH (biter, reds->lookahead_tokens[i], j, 0)
 	{
 	  /* and record this rule as the rule to use if that
 	     token follows.  */
@@ -410,7 +410,7 @@ save_row (state_number s)
 
 /*------------------------------------------------------------------.
 | Figure out the actions for the specified state, indexed by        |
-| look-ahead token type.                                            |
+| lookahead token type.                                             |
 |                                                                   |
 | The YYDEFACT table is output now.  The detailed info is saved for |
 | putting into YYTABLE later.                                       |
