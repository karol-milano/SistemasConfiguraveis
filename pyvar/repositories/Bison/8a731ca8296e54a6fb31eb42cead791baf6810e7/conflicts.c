@@ -179,7 +179,7 @@ resolve_sr_conflict (state_t *state, int lookahead)
   rule_t *redrule = state->lookaheads_rule[lookahead];
   int redprec = redrule->prec->prec;
   bitset lookaheads = state->lookaheads[lookahead];
-  errs *errp = errs_new (ntokens + 1);
+  errs_t *errp = errs_new (ntokens + 1);
   errp->nerrs = 0;
 
   for (i = 0; i < ntokens; i++)
