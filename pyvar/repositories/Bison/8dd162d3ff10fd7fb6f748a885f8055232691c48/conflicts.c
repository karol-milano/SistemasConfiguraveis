@@ -41,8 +41,8 @@ int expected_rr_conflicts = -1;
 static char *conflicts = NULL;
 struct obstack solved_conflicts_obstack;
 
-static bitset shiftset;
-static bitset lookaheadset;
+static bitset shift_set;
+static bitset look_ahead_set;
 
 
 
@@ -146,7 +146,7 @@ flush_shift (state *s, int token)
   transitions *trans = s->transitions;
   int i;
 
-  bitset_reset (lookaheadset, token);
+  bitset_reset (look_ahead_set, token);
   for (i = 0; i < trans->num; i++)
     if (!TRANSITION_IS_DISABLED (trans, i)
 	&& TRANSITION_SYMBOL (trans, i) == token)
@@ -154,16 +154,16 @@ flush_shift (state *s, int token)
 }
 
 
-/*-------------------------------------------------------------------.
-| Turn off the reduce recorded for the specified token for the       |
-| specified lookahead.  Used when we resolve a shift-reduce conflict |
-| in favor of the shift.                                             |
-`-------------------------------------------------------------------*/
+/*--------------------------------------------------------------------.
+| Turn off the reduce recorded for the specified token for the        |
+| specified look-ahead.  Used when we resolve a shift-reduce conflict |
+| in favor of the shift.                                              |
+`--------------------------------------------------------------------*/
 
 static void
-flush_reduce (bitset lookaheads, int token)
+flush_reduce (bitset look_ahead_tokens, int token)
 {
-  bitset_reset (lookaheads, token);
+  bitset_reset (look_ahead_tokens, token);
 }
 
 
@@ -173,7 +173,7 @@ flush_reduce (bitset lookaheads, int token)
 | rule has a precedence.  A conflict is resolved by modifying the   |
 | shift or reduce tables so that there is no longer a conflict.     |
 |                                                                   |
-| LOOKAHEAD is the number of the lookahead bitset to consider.      |
+| RULENO is the number of the look-ahead bitset to consider.      |
 |                                                                   |
 | ERRORS can be used to store discovered explicit errors.           |
 `------------------------------------------------------------------*/
@@ -186,12 +186,12 @@ resolve_sr_conflict (state *s, int ruleno, symbol **errors)
   /* Find the rule to reduce by to get precedence of reduction.  */
   rule *redrule = reds->rules[ruleno];
   int redprec = redrule->prec->prec;
-  bitset lookaheads = reds->lookaheads[ruleno];
+  bitset look_ahead_tokens = reds->look_ahead_tokens[ruleno];
   int nerrs = 0;
 
   for (i = 0; i < ntokens; i++)
-    if (bitset_test (lookaheads, i)
-	&& bitset_test (lookaheadset, i)
+    if (bitset_test (look_ahead_tokens, i)
+	&& bitset_test (look_ahead_set, i)
 	&& symbols[i]->prec)
       {
 	/* Shift-reduce conflict occurs for token number i
@@ -205,7 +205,7 @@ resolve_sr_conflict (state *s, int ruleno, symbol **errors)
 	else if (symbols[i]->prec > redprec)
 	  {
 	    log_resolution (redrule, i, shift_resolution);
-	    flush_reduce (lookaheads, i);
+	    flush_reduce (look_ahead_tokens, i);
 	  }
 	else
 	  /* Matching precedence levels.
@@ -217,7 +217,7 @@ resolve_sr_conflict (state *s, int ruleno, symbol **errors)
 	    {
 	    case right_assoc:
 	      log_resolution (redrule, i, right_resolution);
-	      flush_reduce (lookaheads, i);
+	      flush_reduce (look_ahead_tokens, i);
 	      break;
 
 	    case left_assoc:
@@ -228,7 +228,7 @@ resolve_sr_conflict (state *s, int ruleno, symbol **errors)
 	    case non_assoc:
 	      log_resolution (redrule, i, nonassoc_resolution);
 	      flush_shift (s, i);
-	      flush_reduce (lookaheads, i);
+	      flush_reduce (look_ahead_tokens, i);
 	      /* Record an explicit error for this token.  */
 	      errors[nerrs++] = symbols[i];
 	      break;
@@ -257,7 +257,7 @@ resolve_sr_conflict (state *s, int ruleno, symbol **errors)
 | Solve the S/R conflicts of state S using the                       |
 | precedence/associativity, and flag it inconsistent if it still has |
 | conflicts.  ERRORS can be used as storage to compute the list of   |
-| lookaheads on which S raises a syntax error (%nonassoc).           |
+| look-ahead tokens on which S raises a syntax error (%nonassoc).    |
 `-------------------------------------------------------------------*/
 
 static void
@@ -270,27 +270,27 @@ set_conflicts (state *s, symbol **errors)
   if (s->consistent)
     return;
 
-  bitset_zero (lookaheadset);
+  bitset_zero (look_ahead_set);
 
   FOR_EACH_SHIFT (trans, i)
-    bitset_set (lookaheadset, TRANSITION_SYMBOL (trans, i));
+    bitset_set (look_ahead_set, TRANSITION_SYMBOL (trans, i));
 
-  /* Loop over all rules which require lookahead in this state.  First
+  /* Loop over all rules which require look-ahead in this state.  First
      check for shift-reduce conflict, and try to resolve using
      precedence.  */
   for (i = 0; i < reds->num; ++i)
     if (reds->rules[i]->prec && reds->rules[i]->prec->prec
-	&& !bitset_disjoint_p (reds->lookaheads[i], lookaheadset))
+	&& !bitset_disjoint_p (reds->look_ahead_tokens[i], look_ahead_set))
       resolve_sr_conflict (s, i, errors);
 
-  /* Loop over all rules which require lookahead in this state.  Check
+  /* Loop over all rules which require look-ahead in this state.  Check
      for conflicts not resolved above.  */
   for (i = 0; i < reds->num; ++i)
     {
-      if (!bitset_disjoint_p (reds->lookaheads[i], lookaheadset))
+      if (!bitset_disjoint_p (reds->look_ahead_tokens[i], look_ahead_set))
 	conflicts[s->number] = 1;
 
-      bitset_or (lookaheadset, lookaheadset, reds->lookaheads[i]);
+      bitset_or (look_ahead_set, look_ahead_set, reds->look_ahead_tokens[i]);
     }
 }
 
@@ -304,12 +304,12 @@ void
 conflicts_solve (void)
 {
   state_number i;
-  /* List of lookaheads on which we explicitly raise a syntax error.  */
+  /* List of look-ahead tokens on which we explicitly raise a syntax error.  */
   symbol **errors = MALLOC (errors, ntokens + 1);
 
   CALLOC (conflicts, nstates);
-  shiftset = bitset_create (ntokens, BITSET_FIXED);
-  lookaheadset = bitset_create (ntokens, BITSET_FIXED);
+  shift_set = bitset_create (ntokens, BITSET_FIXED);
+  look_ahead_set = bitset_create (ntokens, BITSET_FIXED);
   obstack_init (&solved_conflicts_obstack);
 
   for (i = 0; i < nstates; i++)
@@ -341,18 +341,18 @@ count_sr_conflicts (state *s)
   if (!trans)
     return 0;
 
-  bitset_zero (lookaheadset);
-  bitset_zero (shiftset);
+  bitset_zero (look_ahead_set);
+  bitset_zero (shift_set);
 
   FOR_EACH_SHIFT (trans, i)
-    bitset_set (shiftset, TRANSITION_SYMBOL (trans, i));
+    bitset_set (shift_set, TRANSITION_SYMBOL (trans, i));
 
   for (i = 0; i < reds->num; ++i)
-    bitset_or (lookaheadset, lookaheadset, reds->lookaheads[i]);
+    bitset_or (look_ahead_set, look_ahead_set, reds->look_ahead_tokens[i]);
 
-  bitset_and (lookaheadset, lookaheadset, shiftset);
+  bitset_and (look_ahead_set, look_ahead_set, shift_set);
 
-  src_count = bitset_count (lookaheadset);
+  src_count = bitset_count (look_ahead_set);
 
   return src_count;
 }
@@ -377,7 +377,7 @@ count_rr_conflicts (state *s, bool one_per_token)
       int count = 0;
       int j;
       for (j = 0; j < reds->num; ++j)
-	if (bitset_test (reds->lookaheads[j], i))
+	if (bitset_test (reds->look_ahead_tokens[j], i))
 	  count++;
 
       if (count >= 2)
@@ -432,7 +432,7 @@ conflicts_output (FILE *out)
 /*--------------------------------------------------------.
 | Total the number of S/R and R/R conflicts.  Unlike the  |
 | code in conflicts_output, however, count EACH pair of   |
-| reductions for the same state and lookahead as one      |
+| reductions for the same state and look-ahead as one     |
 | conflict.						  |
 `--------------------------------------------------------*/
 
@@ -523,7 +523,7 @@ void
 conflicts_free (void)
 {
   XFREE (conflicts);
-  bitset_free (shiftset);
-  bitset_free (lookaheadset);
+  bitset_free (shift_set);
+  bitset_free (look_ahead_set);
   obstack_free (&solved_conflicts_obstack, NULL);
 }
