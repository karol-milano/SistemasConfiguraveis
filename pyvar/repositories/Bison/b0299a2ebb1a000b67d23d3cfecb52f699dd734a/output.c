@@ -348,7 +348,7 @@ action_row (state_t *state)
 	  /* and record this rule as the rule to use if that
 	     token follows.  */
 	  if (bitset_test (LA[state->lookaheadsp + i], j))
-	    actrow[j] = -LAruleno[state->lookaheadsp + i];
+	    actrow[j] = -LArule[state->lookaheadsp + i]->number;
     }
 
   /* Now see which tokens are allowed for shifts in this state.  For
@@ -395,7 +395,7 @@ action_row (state_t *state)
 	  for (i = 0; i < state->nlookaheads; i++)
 	    {
 	      int count = 0;
-	      int rule = -LAruleno[state->lookaheadsp + i];
+	      int rule = -LArule[state->lookaheadsp + i]->number;
 	      int j;
 
 	      for (j = 0; j < ntokens; j++)
@@ -918,7 +918,7 @@ output_actions (void)
 
   token_actions ();
   bitsetv_free (LA);
-  XFREE (LAruleno);
+  free (LArule);
 
   goto_actions ();
   XFREE (goto_map + ntokens);
