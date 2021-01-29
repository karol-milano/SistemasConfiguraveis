@@ -250,9 +250,9 @@ flush_shift (state *s, int token)
 `--------------------------------------------------------------------*/
 
 static void
-flush_reduce (bitset lookahead_tokens, int token)
+flush_reduce (bitset lookaheads, int token)
 {
-  bitset_reset (lookahead_tokens, token);
+  bitset_reset (lookaheads, token);
 }
 
 
@@ -275,10 +275,10 @@ resolve_sr_conflict (state *s, int ruleno, symbol **errors, int *nerrs)
   /* Find the rule to reduce by to get precedence of reduction.  */
   rule *redrule = reds->rules[ruleno];
   int redprec = redrule->prec->prec;
-  bitset lookahead_tokens = reds->lookahead_tokens[ruleno];
+  bitset lookaheads = reds->lookaheads[ruleno];
 
   for (symbol_number i = 0; i < ntokens; ++i)
-    if (bitset_test (lookahead_tokens, i)
+    if (bitset_test (lookaheads, i)
         && bitset_test (lookahead_set, i)
         && symbols[i]->content->prec)
       {
@@ -295,7 +295,7 @@ resolve_sr_conflict (state *s, int ruleno, symbol **errors, int *nerrs)
           {
             register_precedence (i, redrule->prec->number);
             log_resolution (redrule, i, shift_resolution);
-            flush_reduce (lookahead_tokens, i);
+            flush_reduce (lookaheads, i);
           }
         else
           /* Matching precedence levels.
@@ -316,7 +316,7 @@ resolve_sr_conflict (state *s, int ruleno, symbol **errors, int *nerrs)
             case right_assoc:
               register_assoc (i, redrule->prec->number);
               log_resolution (redrule, i, right_resolution);
-              flush_reduce (lookahead_tokens, i);
+              flush_reduce (lookaheads, i);
               break;
 
             case left_assoc:
@@ -329,7 +329,7 @@ resolve_sr_conflict (state *s, int ruleno, symbol **errors, int *nerrs)
               register_assoc (i, redrule->prec->number);
               log_resolution (redrule, i, nonassoc_resolution);
               flush_shift (s, i);
-              flush_reduce (lookahead_tokens, i);
+              flush_reduce (lookaheads, i);
               /* Record an explicit error for this token.  */
               errors[(*nerrs)++] = symbols[i];
               break;
@@ -369,7 +369,7 @@ set_conflicts (state *s, symbol **errors)
   for (int i = 0; i < reds->num; ++i)
     if (reds->rules[i]->prec
         && reds->rules[i]->prec->prec
-        && !bitset_disjoint_p (reds->lookahead_tokens[i], lookahead_set))
+        && !bitset_disjoint_p (reds->lookaheads[i], lookahead_set))
       resolve_sr_conflict (s, i, errors, &nerrs);
 
   if (nerrs)
@@ -385,13 +385,13 @@ set_conflicts (state *s, symbol **errors)
   /* Loop over all rules which require lookahead in this state.  Check
      for conflicts not resolved above.
 
-     reds->lookahead_tokens can be NULL if the LR type is LR(0).  */
-  if (reds->lookahead_tokens)
+     reds->lookaheads can be NULL if the LR type is LR(0).  */
+  if (reds->lookaheads)
     for (int i = 0; i < reds->num; ++i)
       {
-        if (!bitset_disjoint_p (reds->lookahead_tokens[i], lookahead_set))
+        if (!bitset_disjoint_p (reds->lookaheads[i], lookahead_set))
           conflicts[s->number] = true;
-        bitset_or (lookahead_set, lookahead_set, reds->lookahead_tokens[i]);
+        bitset_or (lookahead_set, lookahead_set, reds->lookaheads[i]);
       }
 }
 
@@ -460,7 +460,7 @@ count_state_sr_conflicts (const state *s)
   }
 
   for (int i = 0; i < reds->num; ++i)
-    bitset_or (lookahead_set, lookahead_set, reds->lookahead_tokens[i]);
+    bitset_or (lookahead_set, lookahead_set, reds->lookaheads[i]);
 
   bitset_and (lookahead_set, lookahead_set, shift_set);
 
@@ -499,7 +499,7 @@ count_state_rr_conflicts (const state *s)
     {
       int count = 0;
       for (int j = 0; j < reds->num; ++j)
-        count += bitset_test (reds->lookahead_tokens[j], i);
+        count += bitset_test (reds->lookaheads[j], i);
       if (2 <= count)
         res += count-1;
     }
@@ -534,7 +534,7 @@ count_rule_state_sr_conflicts (rule *r, state *s)
   for (int i = 0; i < reds->num; ++i)
     if (reds->rules[i] == r)
       {
-        bitset lookaheads = reds->lookahead_tokens[i];
+        bitset lookaheads = reds->lookaheads[i];
         int j;
         FOR_EACH_SHIFT (trans, j)
           res += bitset_test (lookaheads, TRANSITION_SYMBOL (trans, j));
@@ -576,8 +576,8 @@ count_rule_state_rr_conflicts (rule *r, state *s)
         if (reds->rules[j] != r)
           {
             bitset_and (lookaheads,
-                        reds->lookahead_tokens[i],
-                        reds->lookahead_tokens[j]);
+                        reds->lookaheads[i],
+                        reds->lookaheads[j]);
             res += bitset_count (lookaheads);
           }
   bitset_free (lookaheads);
