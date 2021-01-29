@@ -380,8 +380,8 @@ action_row (state_t *state)
 	for (j = 0; j < ntokens; j++)
 	  /* and record this rule as the rule to use if that
 	     token follows.  */
-	  if (bitset_test (LA[state->lookaheadsp + i], j))
-	    actrow[j] = -LArule[state->lookaheadsp + i]->number;
+	  if (bitset_test (state->lookaheads[i], j))
+	    actrow[j] = -state->lookaheads_rule[i]->number;
     }
 
   /* Now see which tokens are allowed for shifts in this state.  For
@@ -428,7 +428,7 @@ action_row (state_t *state)
 	  for (i = 0; i < state->nlookaheads; i++)
 	    {
 	      int count = 0;
-	      int rule = -LArule[state->lookaheadsp + i]->number;
+	      int rule = -state->lookaheads_rule[i]->number;
 	      int j;
 
 	      for (j = 0; j < ntokens; j++)
