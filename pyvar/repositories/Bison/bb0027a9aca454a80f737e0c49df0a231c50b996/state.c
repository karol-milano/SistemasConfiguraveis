@@ -223,7 +223,7 @@ state_rule_lookaheads_print (state_t *state, rule_t *rule, FILE *out)
   /* Count the number of lookaheads corresponding to this rule.  */
   for (j = 0; j < state->nlookaheads; ++j)
     BITSET_FOR_EACH (biter, state->lookaheads[j], k, 0)
-      if (state->lookaheads_rule[j]->number == rule->number)
+      if (state->lookaheads_rule[j] == rule)
 	nlookaheads++;
 
   /* Print them if there are.  */
@@ -232,7 +232,7 @@ state_rule_lookaheads_print (state_t *state, rule_t *rule, FILE *out)
       fprintf (out, "  [");
       for (j = 0; j < state->nlookaheads; ++j)
 	BITSET_FOR_EACH (biter, state->lookaheads[j], k, 0)
-	  if (state->lookaheads_rule[j]->number == rule->number)
+	  if (state->lookaheads_rule[j] == rule)
 	    fprintf (out, "%s%s",
 		     symbols[k]->tag,
 		     --nlookaheads ? ", " : "");
