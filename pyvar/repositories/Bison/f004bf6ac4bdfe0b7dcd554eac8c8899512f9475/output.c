@@ -348,8 +348,8 @@ action_row (int state)
 	{
 	  /* loop over all the rules available here which require
 	     lookahead */
-	  m = lookaheads[state];
-	  n = lookaheads[state + 1];
+	  m = state_table[state].lookaheads;
+	  n = state_table[state + 1].lookaheads;
 
 	  for (i = n - 1; i >= m; i--)
 	    {
@@ -928,7 +928,6 @@ output_actions (void)
   token_actions ();
   free_shifts ();
   free_reductions ();
-  XFREE (lookaheads);
   XFREE (LA);
   XFREE (LAruleno);
 
