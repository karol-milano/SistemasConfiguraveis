@@ -221,10 +221,9 @@ static void
 flush_shift (state *s, int token)
 {
   transitions *trans = s->transitions;
-  int i;
 
   bitset_reset (lookahead_set, token);
-  for (i = 0; i < trans->num; i++)
+  for (int i = 0; i < trans->num; ++i)
     if (!TRANSITION_IS_DISABLED (trans, i)
         && TRANSITION_SYMBOL (trans, i) == token)
       TRANSITION_DISABLE (trans, i);
@@ -259,14 +258,13 @@ flush_reduce (bitset lookahead_tokens, int token)
 static void
 resolve_sr_conflict (state *s, int ruleno, symbol **errors, int *nerrs)
 {
-  symbol_number i;
   reductions *reds = s->reductions;
   /* Find the rule to reduce by to get precedence of reduction.  */
   rule *redrule = reds->rules[ruleno];
   int redprec = redrule->prec->prec;
   bitset lookahead_tokens = reds->lookahead_tokens[ruleno];
 
-  for (i = 0; i < ntokens; i++)
+  for (symbol_number i = 0; i < ntokens; ++i)
     if (bitset_test (lookahead_tokens, i)
         && bitset_test (lookahead_set, i)
         && symbols[i]->content->prec)
@@ -337,33 +335,34 @@ resolve_sr_conflict (state *s, int ruleno, symbol **errors, int *nerrs)
 static void
 set_conflicts (state *s, symbol **errors)
 {
-  int i;
-  transitions *trans = s->transitions;
-  reductions *reds = s->reductions;
-  int nerrs = 0;
-
   if (s->consistent)
     return;
 
+  reductions *reds = s->reductions;
+  int nerrs = 0;
+
   bitset_zero (lookahead_set);
 
-  FOR_EACH_SHIFT (trans, i)
-    bitset_set (lookahead_set, TRANSITION_SYMBOL (trans, i));
+  {
+    transitions *trans = s->transitions;
+    int i;
+    FOR_EACH_SHIFT (trans, i)
+      bitset_set (lookahead_set, TRANSITION_SYMBOL (trans, i));
+  }
 
   /* Loop over all rules which require lookahead in this state.  First
      check for shift-reduce conflict, and try to resolve using
      precedence.  */
-  for (i = 0; i < reds->num; ++i)
+  for (int i = 0; i < reds->num; ++i)
     if (reds->rules[i]->prec && reds->rules[i]->prec->prec
         && !bitset_disjoint_p (reds->lookahead_tokens[i], lookahead_set))
       resolve_sr_conflict (s, i, errors, &nerrs);
 
   if (nerrs)
-    {
-      /* Some tokens have been explicitly made errors.  Allocate a
-         permanent errs structure for this state, to record them.  */
-      state_errs_set (s, nerrs, errors);
-    }
+    /* Some tokens have been explicitly made errors.  Allocate a
+       permanent errs structure for this state, to record them.  */
+    state_errs_set (s, nerrs, errors);
+
   if (obstack_object_size (&solved_conflicts_obstack))
     s->solved_conflicts = obstack_finish0 (&solved_conflicts_obstack);
   if (obstack_object_size (&solved_conflicts_xml_obstack))
@@ -371,7 +370,7 @@ set_conflicts (state *s, symbol **errors)
 
   /* Loop over all rules which require lookahead in this state.  Check
      for conflicts not resolved above.  */
-  for (i = 0; i < reds->num; ++i)
+  for (int i = 0; i < reds->num; ++i)
     {
       if (!bitset_disjoint_p (reds->lookahead_tokens[i], lookahead_set))
         conflicts[s->number] = 1;
@@ -388,7 +387,6 @@ set_conflicts (state *s, symbol **errors)
 void
 conflicts_solve (void)
 {
-  state_number i;
   /* List of lookahead tokens on which we explicitly raise a syntax error.  */
   symbol **errors = xnmalloc (ntokens + 1, sizeof *errors);
 
@@ -398,7 +396,7 @@ conflicts_solve (void)
   obstack_init (&solved_conflicts_obstack);
   obstack_init (&solved_conflicts_xml_obstack);
 
-  for (i = 0; i < nstates; i++)
+  for (state_number i = 0; i < nstates; ++i)
     {
       set_conflicts (states[i], errors);
 
@@ -416,8 +414,7 @@ void
 conflicts_update_state_numbers (state_number old_to_new[],
                                 state_number nstates_old)
 {
-  state_number i;
-  for (i = 0; i < nstates_old; ++i)
+  for (state_number i = 0; i < nstates_old; ++i)
     if (old_to_new[i] != nstates_old)
       conflicts[old_to_new[i]] = conflicts[i];
 }
@@ -430,7 +427,6 @@ conflicts_update_state_numbers (state_number old_to_new[],
 static size_t
 count_state_sr_conflicts (state *s)
 {
-  int i;
   transitions *trans = s->transitions;
   reductions *reds = s->reductions;
 
@@ -440,10 +436,13 @@ count_state_sr_conflicts (state *s)
   bitset_zero (lookahead_set);
   bitset_zero (shift_set);
 
-  FOR_EACH_SHIFT (trans, i)
-    bitset_set (shift_set, TRANSITION_SYMBOL (trans, i));
+  {
+    int i;
+    FOR_EACH_SHIFT (trans, i)
+      bitset_set (shift_set, TRANSITION_SYMBOL (trans, i));
+  }
 
-  for (i = 0; i < reds->num; ++i)
+  for (int i = 0; i < reds->num; ++i)
     bitset_or (lookahead_set, lookahead_set, reds->lookahead_tokens[i]);
 
   bitset_and (lookahead_set, lookahead_set, shift_set);
@@ -459,10 +458,8 @@ static size_t
 count_sr_conflicts (void)
 {
   size_t res = 0;
-  state_number i;
-
   /* Conflicts by state.  */
-  for (i = 0; i < nstates; i++)
+  for (state_number i = 0; i < nstates; ++i)
     if (conflicts[i])
       res += count_state_sr_conflicts (states[i]);
   return res;
@@ -480,15 +477,13 @@ count_sr_conflicts (void)
 static size_t
 count_state_rr_conflicts (state *s, bool one_per_token)
 {
-  int i;
   reductions *reds = s->reductions;
   size_t res = 0;
 
-  for (i = 0; i < ntokens; i++)
+  for (symbol_number i = 0; i < ntokens; ++i)
     {
       int count = 0;
-      int j;
-      for (j = 0; j < reds->num; ++j)
+      for (int j = 0; j < reds->num; ++j)
         count += bitset_test (reds->lookahead_tokens[j], i);
       if (count >= 2)
         res += one_per_token ? 1 : count-1;
@@ -501,10 +496,8 @@ static size_t
 count_rr_conflicts (bool one_per_token)
 {
   size_t res = 0;
-  state_number i;
-
   /* Conflicts by state.  */
-  for (i = 0; i < nstates; i++)
+  for (state_number i = 0; i < nstates; ++i)
     if (conflicts[i])
       res += count_state_rr_conflicts (states[i], one_per_token);
   return res;
@@ -519,8 +512,7 @@ void
 conflicts_output (FILE *out)
 {
   bool printed_sth = false;
-  state_number i;
-  for (i = 0; i < nstates; i++)
+  for (state_number i = 0; i < nstates; ++i)
     {
       state *s = states[i];
       if (conflicts[i])
