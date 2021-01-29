@@ -94,7 +94,7 @@ resolve_sr_conflict (state_t *state, int lookahead)
 {
   int i;
   /* find the rule to reduce by to get precedence of reduction  */
-  int redprec = rule_table[LAruleno[lookahead]].prec;
+  int redprec = rules[LAruleno[lookahead]].prec;
   errs *errp = errs_new (ntokens + 1);
   errp->nerrs = 0;
 
@@ -172,7 +172,7 @@ set_conflicts (state_t *state)
      check for shift-reduce conflict, and try to resolve using
      precedence */
   for (i = 0; i < state->nlookaheads; ++i)
-    if (rule_table[LAruleno[state->lookaheadsp + i]].prec)
+    if (rules[LAruleno[state->lookaheadsp + i]].prec)
       for (j = 0; j < tokensetsize; ++j)
 	if (LA (state->lookaheadsp + i)[j] & lookaheadset[j])
 	  {
