@@ -90,26 +90,24 @@ print_core (struct obstack *oout, state_t *state)
 	  && state->nlookaheads)
 	{
 	  int j, k;
+	  bitset_iterator biter;
 	  int nlookaheads = 0;
+
 	  /* Look for lookaheads corresponding to this rule. */
 	  for (j = 0; j < state->nlookaheads; ++j)
-	    BITSET_EXECUTE (state->lookaheads[j], 0, k,
-	    {
+	    BITSET_FOR_EACH (biter, state->lookaheads[j], k, 0)
 	      if (state->lookaheads_rule[j]->number == rule)
 		nlookaheads++;
-	    });
 
 	  if (nlookaheads)
 	    {
 	      obstack_sgrow (oout, "  [");
 	      for (j = 0; j < state->nlookaheads; ++j)
-		BITSET_EXECUTE (state->lookaheads[j], 0, k,
-		{
+		BITSET_FOR_EACH (biter, state->lookaheads[j], k, 0)
 		  if (state->lookaheads_rule[j]->number == rule)
 		    obstack_fgrow2 (oout, "%s%s",
 				    symbols[k]->tag,
 				    --nlookaheads ? ", " : "");
-		});
 	      obstack_sgrow (oout, "]");
 	    }
 	}
