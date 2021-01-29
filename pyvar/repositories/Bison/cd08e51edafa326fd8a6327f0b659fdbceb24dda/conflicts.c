@@ -175,14 +175,15 @@ flush_reduce (bitset lookaheads, int token)
 `------------------------------------------------------------------*/
 
 static void
-resolve_sr_conflict (state_t *state, int lookahead,
+resolve_sr_conflict (state_t *state, int ruleno,
 		     symbol_t **errs)
 {
   symbol_number_t i;
+  reductions_t *reds = state->reductions;
   /* Find the rule to reduce by to get precedence of reduction.  */
-  rule_t *redrule = state->lookaheads_rule[lookahead];
+  rule_t *redrule = reds->rules[ruleno];
   int redprec = redrule->prec->prec;
-  bitset lookaheads = state->lookaheads[lookahead];
+  bitset lookaheads = reds->lookaheads[ruleno];
   int nerrs = 0;
 
   for (i = 0; i < ntokens; i++)
@@ -259,6 +260,7 @@ set_conflicts (state_t *state, symbol_t **errs)
 {
   int i;
   transitions_t *transitions = state->transitions;
+  reductions_t *reds = state->reductions;
 
   if (state->consistent)
     return;
@@ -271,10 +273,9 @@ set_conflicts (state_t *state, symbol_t **errs)
   /* Loop over all rules which require lookahead in this state.  First
      check for shift-reduce conflict, and try to resolve using
      precedence.  */
-  for (i = 0; i < state->nlookaheads; ++i)
-    if (state->lookaheads_rule[i]->prec
-	&& state->lookaheads_rule[i]->prec->prec
-	&& !bitset_disjoint_p (state->lookaheads[i], lookaheadset))
+  for (i = 0; i < reds->num; ++i)
+    if (reds->rules[i]->prec && reds->rules[i]->prec->prec
+	&& !bitset_disjoint_p (reds->lookaheads[i], lookaheadset))
       {
 	resolve_sr_conflict (state, i, errs);
 	break;
@@ -282,12 +283,12 @@ set_conflicts (state_t *state, symbol_t **errs)
 
   /* Loop over all rules which require lookahead in this state.  Check
      for conflicts not resolved above.  */
-  for (i = 0; i < state->nlookaheads; ++i)
+  for (i = 0; i < reds->num; ++i)
     {
-      if (!bitset_disjoint_p (state->lookaheads[i], lookaheadset))
+      if (!bitset_disjoint_p (reds->lookaheads[i], lookaheadset))
 	conflicts[state->number] = 1;
 
-      bitset_or (lookaheadset, lookaheadset, state->lookaheads[i]);
+      bitset_or (lookaheadset, lookaheadset, reds->lookaheads[i]);
     }
 }
 
@@ -333,6 +334,7 @@ count_sr_conflicts (state_t *state)
   int i;
   int src_count = 0;
   transitions_t *transitions = state->transitions;
+  reductions_t *reds = state->reductions;
 
   if (!transitions)
     return 0;
@@ -343,8 +345,8 @@ count_sr_conflicts (state_t *state)
   FOR_EACH_SHIFT (transitions, i)
     bitset_set (shiftset, TRANSITION_SYMBOL (transitions, i));
 
-  for (i = 0; i < state->nlookaheads; ++i)
-    bitset_or (lookaheadset, lookaheadset, state->lookaheads[i]);
+  for (i = 0; i < reds->num; ++i)
+    bitset_or (lookaheadset, lookaheadset, reds->lookaheads[i]);
 
   bitset_and (lookaheadset, lookaheadset, shiftset);
 
@@ -365,17 +367,15 @@ static int
 count_rr_conflicts (state_t *state, int one_per_token)
 {
   int i;
+  reductions_t *reds = state->reductions;
   int rrc_count = 0;
 
-  if (state->nlookaheads < 2)
-    return 0;
-
   for (i = 0; i < ntokens; i++)
     {
       int count = 0;
       int j;
-      for (j = 0; j < state->nlookaheads; ++j)
-	if (bitset_test (state->lookaheads[j], i))
+      for (j = 0; j < reds->num; ++j)
+	if (bitset_test (reds->lookaheads[j], i))
 	  count++;
 
       if (count >= 2)
@@ -456,9 +456,10 @@ conflicts_output (FILE *out)
   for (i = 0; i < nstates; i++)
     {
       state_t *s = states[i];
+      reductions_t *reds = s->reductions;
       int j;
-      for (j = 0; j < s->reductions->num; ++j)
-	used_rules[s->reductions->rules[j]->number] = TRUE;
+      for (j = 0; j < reds->num; ++j)
+	used_rules[reds->rules[j]->number] = TRUE;
       if (conflicts[i])
 	{
 	  fprintf (out, _("State %d contains "), i);
