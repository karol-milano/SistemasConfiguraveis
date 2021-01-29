@@ -1,4 +1,4 @@
-/* Find and resolve or report look-ahead conflicts for bison,
+/* Find and resolve or report lookahead conflicts for bison,
 
    Copyright (C) 1984, 1989, 1992, 2000, 2001, 2002, 2003, 2004, 2005, 2006
    Free Software Foundation, Inc.
@@ -43,7 +43,7 @@ static char *conflicts;
 static struct obstack solved_conflicts_obstack;
 
 static bitset shift_set;
-static bitset look_ahead_set;
+static bitset lookahead_set;
 
 
 
@@ -147,7 +147,7 @@ flush_shift (state *s, int token)
   transitions *trans = s->transitions;
   int i;
 
-  bitset_reset (look_ahead_set, token);
+  bitset_reset (lookahead_set, token);
   for (i = 0; i < trans->num; i++)
     if (!TRANSITION_IS_DISABLED (trans, i)
 	&& TRANSITION_SYMBOL (trans, i) == token)
@@ -157,14 +157,14 @@ flush_shift (state *s, int token)
 
 /*--------------------------------------------------------------------.
 | Turn off the reduce recorded for the specified token for the        |
-| specified look-ahead.  Used when we resolve a shift-reduce conflict |
+| specified lookahead.  Used when we resolve a shift-reduce conflict  |
 | in favor of the shift.                                              |
 `--------------------------------------------------------------------*/
 
 static void
-flush_reduce (bitset look_ahead_tokens, int token)
+flush_reduce (bitset lookahead_tokens, int token)
 {
-  bitset_reset (look_ahead_tokens, token);
+  bitset_reset (lookahead_tokens, token);
 }
 
 
@@ -174,7 +174,7 @@ flush_reduce (bitset look_ahead_tokens, int token)
 | rule has a precedence.  A conflict is resolved by modifying the   |
 | shift or reduce tables so that there is no longer a conflict.     |
 |                                                                   |
-| RULENO is the number of the look-ahead bitset to consider.      |
+| RULENO is the number of the lookahead bitset to consider.         |
 |                                                                   |
 | ERRORS can be used to store discovered explicit errors.           |
 `------------------------------------------------------------------*/
@@ -187,12 +187,12 @@ resolve_sr_conflict (state *s, int ruleno, symbol **errors)
   /* Find the rule to reduce by to get precedence of reduction.  */
   rule *redrule = reds->rules[ruleno];
   int redprec = redrule->prec->prec;
-  bitset look_ahead_tokens = reds->look_ahead_tokens[ruleno];
+  bitset lookahead_tokens = reds->lookahead_tokens[ruleno];
   int nerrs = 0;
 
   for (i = 0; i < ntokens; i++)
-    if (bitset_test (look_ahead_tokens, i)
-	&& bitset_test (look_ahead_set, i)
+    if (bitset_test (lookahead_tokens, i)
+	&& bitset_test (lookahead_set, i)
 	&& symbols[i]->prec)
       {
 	/* Shift-reduce conflict occurs for token number i
@@ -206,7 +206,7 @@ resolve_sr_conflict (state *s, int ruleno, symbol **errors)
 	else if (symbols[i]->prec > redprec)
 	  {
 	    log_resolution (redrule, i, shift_resolution);
-	    flush_reduce (look_ahead_tokens, i);
+	    flush_reduce (lookahead_tokens, i);
 	  }
 	else
 	  /* Matching precedence levels.
@@ -221,7 +221,7 @@ resolve_sr_conflict (state *s, int ruleno, symbol **errors)
 
 	    case right_assoc:
 	      log_resolution (redrule, i, right_resolution);
-	      flush_reduce (look_ahead_tokens, i);
+	      flush_reduce (lookahead_tokens, i);
 	      break;
 
 	    case left_assoc:
@@ -232,7 +232,7 @@ resolve_sr_conflict (state *s, int ruleno, symbol **errors)
 	    case non_assoc:
 	      log_resolution (redrule, i, nonassoc_resolution);
 	      flush_shift (s, i);
-	      flush_reduce (look_ahead_tokens, i);
+	      flush_reduce (lookahead_tokens, i);
 	      /* Record an explicit error for this token.  */
 	      errors[nerrs++] = symbols[i];
 	      break;
@@ -258,7 +258,7 @@ resolve_sr_conflict (state *s, int ruleno, symbol **errors)
 | Solve the S/R conflicts of state S using the                       |
 | precedence/associativity, and flag it inconsistent if it still has |
 | conflicts.  ERRORS can be used as storage to compute the list of   |
-| look-ahead tokens on which S raises a syntax error (%nonassoc).    |
+| lookahead tokens on which S raises a syntax error (%nonassoc).     |
 `-------------------------------------------------------------------*/
 
 static void
@@ -271,27 +271,27 @@ set_conflicts (state *s, symbol **errors)
   if (s->consistent)
     return;
 
-  bitset_zero (look_ahead_set);
+  bitset_zero (lookahead_set);
 
   FOR_EACH_SHIFT (trans, i)
-    bitset_set (look_ahead_set, TRANSITION_SYMBOL (trans, i));
+    bitset_set (lookahead_set, TRANSITION_SYMBOL (trans, i));
 
-  /* Loop over all rules which require look-ahead in this state.  First
+  /* Loop over all rules which require lookahead in this state.  First
      check for shift-reduce conflict, and try to resolve using
      precedence.  */
   for (i = 0; i < reds->num; ++i)
     if (reds->rules[i]->prec && reds->rules[i]->prec->prec
-	&& !bitset_disjoint_p (reds->look_ahead_tokens[i], look_ahead_set))
+	&& !bitset_disjoint_p (reds->lookahead_tokens[i], lookahead_set))
       resolve_sr_conflict (s, i, errors);
 
-  /* Loop over all rules which require look-ahead in this state.  Check
+  /* Loop over all rules which require lookahead in this state.  Check
      for conflicts not resolved above.  */
   for (i = 0; i < reds->num; ++i)
     {
-      if (!bitset_disjoint_p (reds->look_ahead_tokens[i], look_ahead_set))
+      if (!bitset_disjoint_p (reds->lookahead_tokens[i], lookahead_set))
 	conflicts[s->number] = 1;
 
-      bitset_or (look_ahead_set, look_ahead_set, reds->look_ahead_tokens[i]);
+      bitset_or (lookahead_set, lookahead_set, reds->lookahead_tokens[i]);
     }
 }
 
@@ -305,12 +305,12 @@ void
 conflicts_solve (void)
 {
   state_number i;
-  /* List of look-ahead tokens on which we explicitly raise a syntax error.  */
+  /* List of lookahead tokens on which we explicitly raise a syntax error.  */
   symbol **errors = xnmalloc (ntokens + 1, sizeof *errors);
 
   conflicts = xcalloc (nstates, sizeof *conflicts);
   shift_set = bitset_create (ntokens, BITSET_FIXED);
-  look_ahead_set = bitset_create (ntokens, BITSET_FIXED);
+  lookahead_set = bitset_create (ntokens, BITSET_FIXED);
   obstack_init (&solved_conflicts_obstack);
 
   for (i = 0; i < nstates; i++)
@@ -342,18 +342,18 @@ count_sr_conflicts (state *s)
   if (!trans)
     return 0;
 
-  bitset_zero (look_ahead_set);
+  bitset_zero (lookahead_set);
   bitset_zero (shift_set);
 
   FOR_EACH_SHIFT (trans, i)
     bitset_set (shift_set, TRANSITION_SYMBOL (trans, i));
 
   for (i = 0; i < reds->num; ++i)
-    bitset_or (look_ahead_set, look_ahead_set, reds->look_ahead_tokens[i]);
+    bitset_or (lookahead_set, lookahead_set, reds->lookahead_tokens[i]);
 
-  bitset_and (look_ahead_set, look_ahead_set, shift_set);
+  bitset_and (lookahead_set, lookahead_set, shift_set);
 
-  src_count = bitset_count (look_ahead_set);
+  src_count = bitset_count (lookahead_set);
 
   return src_count;
 }
@@ -378,7 +378,7 @@ count_rr_conflicts (state *s, bool one_per_token)
       int count = 0;
       int j;
       for (j = 0; j < reds->num; ++j)
-	if (bitset_test (reds->look_ahead_tokens[j], i))
+	if (bitset_test (reds->lookahead_tokens[j], i))
 	  count++;
 
       if (count >= 2)
@@ -433,7 +433,7 @@ conflicts_output (FILE *out)
 /*--------------------------------------------------------.
 | Total the number of S/R and R/R conflicts.  Unlike the  |
 | code in conflicts_output, however, count EACH pair of   |
-| reductions for the same state and look-ahead as one     |
+| reductions for the same state and lookahead as one      |
 | conflict.						  |
 `--------------------------------------------------------*/
 
@@ -530,6 +530,6 @@ conflicts_free (void)
 {
   free (conflicts);
   bitset_free (shift_set);
-  bitset_free (look_ahead_set);
+  bitset_free (lookahead_set);
   obstack_free (&solved_conflicts_obstack, NULL);
 }
