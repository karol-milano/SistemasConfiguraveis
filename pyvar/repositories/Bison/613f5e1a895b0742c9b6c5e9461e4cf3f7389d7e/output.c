@@ -442,19 +442,20 @@ action_row (state_t *state)
   if (redp->num >= 1)
     {
       int j;
+      bitset_iterator biter;
       /* loop over all the rules available here which require
 	 lookahead */
       for (i = state->nlookaheads - 1; i >= 0; --i)
 	/* and find each token which the rule finds acceptable
 	   to come next */
-	BITSET_EXECUTE (state->lookaheads[i], 0, j,
+	BITSET_FOR_EACH (biter, state->lookaheads[i], j, 0)
 	{
 	  /* and record this rule as the rule to use if that
 	     token follows.  */
 	  if (actrow[j] != 0)
 	    conflicted = conflrow[j] = 1;
 	  actrow[j] = -state->lookaheads_rule[i]->number;
-	});
+	}
     }
 
   /* Now see which tokens are allowed for shifts in this state.  For
