@@ -46,7 +46,9 @@ log_resolution (state_t *state, int LAno, int token, const char *resolution)
     obstack_fgrow4 (&output_obstack,
 		    _("\
 Conflict in state %d between rule %d and token %s resolved as %s.\n"),
-		    state->number, LAruleno[LAno], symbols[token]->tag,
+		    state->number,
+		    LArule[LAno]->number,
+		    symbols[token]->tag,
 		    resolution);
 }
 
@@ -95,7 +97,7 @@ resolve_sr_conflict (state_t *state, int lookahead)
 {
   int i;
   /* find the rule to reduce by to get precedence of reduction  */
-  int redprec = rules[LAruleno[lookahead]].prec;
+  int redprec = LArule[lookahead]->prec;
   errs *errp = errs_new (ntokens + 1);
   errp->nerrs = 0;
 
@@ -172,7 +174,7 @@ set_conflicts (state_t *state)
      check for shift-reduce conflict, and try to resolve using
      precedence */
   for (i = 0; i < state->nlookaheads; ++i)
-    if (rules[LAruleno[state->lookaheadsp + i]].prec
+    if (LArule[state->lookaheadsp + i]->prec
 	&& !bitset_disjoint_p (LA[state->lookaheadsp + i], lookaheadset))
       {
 	resolve_sr_conflict (state, state->lookaheadsp + i);
