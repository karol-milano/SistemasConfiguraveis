@@ -344,8 +344,8 @@ action_row (int state)
       int j;
       /* loop over all the rules available here which require
 	 lookahead */
-      m = state_table[state]->lookaheads;
-      n = state_table[state + 1]->lookaheads;
+      m = state_table[state]->lookaheadsp;
+      n = state_table[state + 1]->lookaheadsp;
 
       for (i = n - 1; i >= m; i--)
 	/* and find each token which the rule finds acceptable
