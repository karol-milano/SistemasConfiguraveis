@@ -93,28 +93,7 @@ print_core (FILE *out, state_t *state)
 
 	  /* Display the lookaheads?  */
 	  if (report_flag & report_lookaheads)
-	    {
-	      int j, k;
-	      int nlookaheads = 0;
-	      /* Look for lookaheads corresponding to this rule. */
-	      for (j = 0; j < state->nlookaheads; ++j)
-		for (k = 0; k < ntokens; ++k)
-		  if (bitset_test (state->lookaheads[j], k)
-		      && state->lookaheads_rule[j]->number == rule)
-		    nlookaheads++;
-	      if (nlookaheads)
-		{
-		  fprintf (out, "  [");
-		  for (j = 0; j < state->nlookaheads; ++j)
-		    for (k = 0; k < ntokens; ++k)
-		      if (bitset_test (state->lookaheads[j], k)
-			  && state->lookaheads_rule[j]->number == rule)
-			fprintf (out, "%s%s",
-				 symbol_tag_get (symbols[k]),
-				 --nlookaheads ? ", " : "");
-		  fprintf (out, "]");
-		}
-	    }
+	    state_rule_lookaheads_print (state, &rules[rule], out);
 
 	  fprintf (out, _("   (rule %d)"), rule - 1);
 	  fputc ('\n', out);
