@@ -86,28 +86,23 @@ print_core (struct obstack *oout, state_t *state)
 	obstack_fgrow1 (oout, " %s", symbols[*sp]->tag);
 
       /* Experimental feature: display the lookaheads. */
-      if ((report_flag & report_lookaheads)
-	  && state->nlookaheads)
+      if (report_flag & report_lookaheads)
 	{
-	  int j, k;
-	  bitset_iterator biter;
-	  int nlookaheads = 0;
+	  /* Find the reduction we are handling.  */
+	  reductions_t *reds = state->reductions;
+	  int redno = state_reduction_find (state, &rules[rule]);
 
-	  /* Look for lookaheads corresponding to this rule. */
-	  for (j = 0; j < state->nlookaheads; ++j)
-	    BITSET_FOR_EACH (biter, state->lookaheads[j], k, 0)
-	      if (state->lookaheads_rule[j]->number == rule)
-		nlookaheads++;
-
-	  if (nlookaheads)
+	  /* Print them if there are.  */
+	  if (reds->lookaheads && redno != -1)
 	    {
-	      obstack_sgrow (oout, "  [");
-	      for (j = 0; j < state->nlookaheads; ++j)
-		BITSET_FOR_EACH (biter, state->lookaheads[j], k, 0)
-		  if (state->lookaheads_rule[j]->number == rule)
-		    obstack_fgrow2 (oout, "%s%s",
-				    symbols[k]->tag,
-				    --nlookaheads ? ", " : "");
+	      bitset_iterator biter;
+	      int k;
+	      int not_first = 0;
+	      obstack_sgrow (oout, "[");
+	      BITSET_FOR_EACH (biter, reds->lookaheads[redno], k, 0)
+		obstack_fgrow2 (oout, "%s%s",
+				not_first++ ? ", " : "",
+				symbols[k]->tag);
 	      obstack_sgrow (oout, "]");
 	    }
 	}
