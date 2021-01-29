@@ -447,41 +447,34 @@ action_row (state_t *state)
       for (i = state->nlookaheads - 1; i >= 0; --i)
 	/* and find each token which the rule finds acceptable
 	   to come next */
-	for (j = 0; j < ntokens; j++)
+	BITSET_EXECUTE (state->lookaheads[i], 0, j,
+	{
 	  /* and record this rule as the rule to use if that
 	     token follows.  */
-	  if (bitset_test (state->lookaheads[i], j))
-	    {
-	      if (actrow[j] != 0)
-		conflicted = conflrow[j] = 1;
-	      actrow[j] = -state->lookaheads_rule[i]->number;
-	    }
+	  if (actrow[j] != 0)
+	    conflicted = conflrow[j] = 1;
+	  actrow[j] = -state->lookaheads_rule[i]->number;
+	});
     }
 
   /* Now see which tokens are allowed for shifts in this state.  For
      them, record the shift as the thing to do.  So shift is preferred
      to reduce.  */
-  for (i = 0; i < shiftp->nshifts; i++)
-    {
-      symbol_number_t symbol;
-      state_number_t shift_state = shiftp->shifts[i];
-      if (!shift_state)
-	continue;
-
-      symbol = states[shift_state]->accessing_symbol;
-
-      if (ISVAR (symbol))
-	break;
+  for (i = 0; i < shiftp->nshifts && SHIFT_IS_SHIFT (shiftp, i); i++)
+    if (!SHIFT_IS_DISABLED (shiftp, i))
+      {
+	symbol_number_t symbol = SHIFT_SYMBOL (shiftp, i);
+	state_number_t shift_state = shiftp->shifts[i];
 
-      if (actrow[symbol] != 0)
-	conflicted = conflrow[symbol] = 1;
-      actrow[symbol] = state_number_as_int (shift_state);
+	if (actrow[symbol] != 0)
+	  conflicted = conflrow[symbol] = 1;
+	actrow[symbol] = state_number_as_int (shift_state);
 
-      /* Do not use any default reduction if there is a shift for
-	 error */
-      if (symbol == errtoken->number)
-	nodefault = 1;
-    }
+	/* Do not use any default reduction if there is a shift for
+	   error */
+	if (symbol == errtoken->number)
+	  nodefault = 1;
+      }
 
   /* See which tokens are an explicit error in this state (due to
      %nonassoc).  For them, record SHRT_MIN as the action.  */
