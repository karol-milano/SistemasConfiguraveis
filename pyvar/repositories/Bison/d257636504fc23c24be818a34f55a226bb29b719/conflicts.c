@@ -58,7 +58,7 @@ enum conflict_resolution_e
 `----------------------------------------------------------------*/
 
 static inline void
-log_resolution (rule_t *rule, int token,
+log_resolution (rule_t *rule, symbol_number_t token,
 		enum conflict_resolution_e resolution)
 {
   if (report_flag & report_solved_conflicts)
@@ -144,7 +144,8 @@ flush_shift (state_t *state, int token)
 
   bitset_reset (lookaheadset, token);
   for (i = 0; i < transitions->num; i++)
-    if (!TRANSITION_IS_DISABLED (transitions, i) && TRANSITION_SYMBOL (transitions, i) == token)
+    if (!TRANSITION_IS_DISABLED (transitions, i)
+	&& TRANSITION_SYMBOL (transitions, i) == token)
       TRANSITION_DISABLE (transitions, i);
 }
 
@@ -174,13 +175,13 @@ flush_reduce (bitset lookaheads, int token)
 static void
 resolve_sr_conflict (state_t *state, int lookahead)
 {
-  int i;
+  symbol_number_t i;
   /* Find the rule to reduce by to get precedence of reduction.  */
   rule_t *redrule = state->lookaheads_rule[lookahead];
   int redprec = redrule->prec->prec;
   bitset lookaheads = state->lookaheads[lookahead];
   errs_t *errp = errs_new (ntokens + 1);
-  errp->nerrs = 0;
+  errp->num = 0;
 
   for (i = 0; i < ntokens; i++)
     if (bitset_test (lookaheads, i)
@@ -223,7 +224,7 @@ resolve_sr_conflict (state_t *state, int lookahead)
 	      flush_shift (state, i);
 	      flush_reduce (lookaheads, i);
 	      /* Record an explicit error for this token.  */
-	      errp->errs[errp->nerrs++] = i;
+	      errp->symbols[errp->num++] = i;
 	      break;
 
 	    case undef_assoc:
