@@ -93,16 +93,16 @@ print_core (struct obstack *oout, state_t *state)
 	  /* Look for lookaheads corresponding to this rule. */
 	  for (j = 0; j < state->nlookaheads; ++j)
 	    for (k = 0; k < ntokens; ++k)
-	      if (bitset_test (LA[state->lookaheadsp + j], k)
-		  && LArule[state->lookaheadsp + j]->number == rule)
+	      if (bitset_test (state->lookaheads[j], k)
+		  && state->lookaheads_rule[j]->number == rule)
 		nlookaheads++;
 	  if (nlookaheads)
 	    {
 	      obstack_sgrow (oout, "  [");
 	      for (j = 0; j < state->nlookaheads; ++j)
 		for (k = 0; k < ntokens; ++k)
-		  if (bitset_test (LA[state->lookaheadsp + j], k)
-		      && LArule[state->lookaheadsp + j]->number == rule)
+		  if (bitset_test (state->lookaheads[j], k)
+		      && state->lookaheads_rule[j]->number == rule)
 		    obstack_fgrow2 (oout, "%s%s",
 				    symbol_tag_get (symbols[k]),
 				    --nlookaheads ? ", " : "");
