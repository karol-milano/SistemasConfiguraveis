@@ -497,11 +497,11 @@ action_row (state_t *state)
 	  for (i = 0; i < state->nlookaheads; i++)
 	    {
 	      int count = 0;
-	      rule_number_t rule = -state->lookaheads_rule[i]->number;
+	      rule_number_t rule = state->lookaheads_rule[i]->number;
 	      symbol_number_t j;
 
 	      for (j = 0; j < ntokens; j++)
-		if (actrow[j] == rule)
+		if (actrow[j] == -rule)
 		  count++;
 
 	      if (count > max)
@@ -521,10 +521,10 @@ action_row (state_t *state)
 	    {
 	      int j;
 	      for (j = 0; j < ntokens; j++)
-		if (actrow[j] == default_rule && ! (glr_parser && conflrow[j]))
+		if (actrow[j] == -default_rule
+		    && ! (glr_parser && conflrow[j]))
 		  actrow[j] = 0;
 	    }
-	  default_rule = -default_rule;
 	}
     }
 
