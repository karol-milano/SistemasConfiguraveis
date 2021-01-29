@@ -195,27 +195,24 @@ void
 state_rule_lookaheads_print (state_t *state, rule_t *rule, FILE *out)
 {
   int j, k;
+  bitset_iterator biter;
   int nlookaheads = 0;
   /* Count the number of lookaheads corresponding to this rule.  */
   for (j = 0; j < state->nlookaheads; ++j)
-    BITSET_EXECUTE (state->lookaheads[j], 0, k,
-    {
+    BITSET_FOR_EACH (biter, state->lookaheads[j], k, 0)
       if (state->lookaheads_rule[j]->number == rule->number)
 	nlookaheads++;
-    });
 
   /* Print them if there are.  */
   if (nlookaheads)
     {
       fprintf (out, "  [");
       for (j = 0; j < state->nlookaheads; ++j)
-	BITSET_EXECUTE (state->lookaheads[j], 0, k,
-	{
+	BITSET_FOR_EACH (biter, state->lookaheads[j], k, 0)
 	  if (state->lookaheads_rule[j]->number == rule->number)
 	    fprintf (out, "%s%s",
 		     symbols[k]->tag,
 		     --nlookaheads ? ", " : "");
-	});
       fprintf (out, "]");
     }
 }
