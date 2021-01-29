@@ -213,7 +213,7 @@ state_rule_lookaheads_print (state_t *state, rule_t *rule, FILE *out)
 	{
 	  if (state->lookaheads_rule[j]->number == rule->number)
 	    fprintf (out, "%s%s",
-		     symbol_tag_get (symbols[k]),
+		     symbols[k]->tag,
 		     --nlookaheads ? ", " : "");
 	});
       fprintf (out, "]");
