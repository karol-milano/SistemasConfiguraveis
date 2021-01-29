@@ -265,7 +265,7 @@ count_rr_conflicts (state_t *state)
       int count = 0;
       int j;
       for (j = 0; j < state->nlookaheads; ++j)
-	if (BITISSET (LA (state->lookaheadsp), state->lookaheadsp + j))
+	if (BITISSET (LA (state->lookaheadsp + j), i))
 	  count++;
 
       if (count >= 2)
