@@ -139,7 +139,7 @@ log_resolution (rule_t *rule, symbol_number_t token,
 static void
 flush_shift (state_t *state, int token)
 {
-  transitions_t *transitions = state->shifts;
+  transitions_t *transitions = state->transitions;
   int i;
 
   bitset_reset (lookaheadset, token);
@@ -170,18 +170,20 @@ flush_reduce (bitset lookaheads, int token)
 | shift or reduce tables so that there is no longer a conflict.     |
 |                                                                   |
 | LOOKAHEAD is the number of the lookahead bitset to consider.      |
+|                                                                   |
+| ERRS can be used to store discovered explicit errors.             |
 `------------------------------------------------------------------*/
 
 static void
-resolve_sr_conflict (state_t *state, int lookahead)
+resolve_sr_conflict (state_t *state, int lookahead,
+		     symbol_number_t *errs)
 {
   symbol_number_t i;
   /* Find the rule to reduce by to get precedence of reduction.  */
   rule_t *redrule = state->lookaheads_rule[lookahead];
   int redprec = redrule->prec->prec;
   bitset lookaheads = state->lookaheads[lookahead];
-  errs_t *errp = errs_new (ntokens + 1);
-  errp->num = 0;
+  int nerrs = 0;
 
   for (i = 0; i < ntokens; i++)
     if (bitset_test (lookaheads, i)
@@ -224,7 +226,7 @@ resolve_sr_conflict (state_t *state, int lookahead)
 	      flush_shift (state, i);
 	      flush_reduce (lookaheads, i);
 	      /* Record an explicit error for this token.  */
-	      errp->symbols[errp->num++] = i;
+	      errs[nerrs++] = i;
 	      break;
 
 	    case undef_assoc:
@@ -235,8 +237,7 @@ resolve_sr_conflict (state_t *state, int lookahead)
 
   /* Some tokens have been explicitly made errors.  Allocate a
      permanent errs structure for this state, to record them.  */
-  state->errs = errs_dup (errp);
-  free (errp);
+  state_errs_set (state, nerrs, errs);
 
   if (obstack_object_size (&solved_conflicts_obstack))
     {
@@ -246,18 +247,24 @@ resolve_sr_conflict (state_t *state, int lookahead)
 }
 
 
+/*-------------------------------------------------------------------.
+| Solve the S/R conflicts of STATE using the                         |
+| precedence/associativity, and flag it inconsistent if it still has |
+| conflicts.  ERRS can be used as storage to compute the list of     |
+| lookaheads on which this STATE raises a parse error (%nonassoc).   |
+`-------------------------------------------------------------------*/
+
 static void
-set_conflicts (state_t *state)
+set_conflicts (state_t *state, symbol_number_t *errs)
 {
   int i;
-  transitions_t *transitions;
+  transitions_t *transitions = state->transitions;
 
   if (state->consistent)
     return;
 
   bitset_zero (lookaheadset);
 
-  transitions = state->shifts;
   for (i = 0; i < transitions->num && TRANSITION_IS_SHIFT (transitions, i); i++)
     if (!TRANSITION_IS_DISABLED (transitions, i))
       bitset_set (lookaheadset, TRANSITION_SYMBOL (transitions, i));
@@ -270,7 +277,7 @@ set_conflicts (state_t *state)
 	&& state->lookaheads_rule[i]->prec->prec
 	&& !bitset_disjoint_p (state->lookaheads[i], lookaheadset))
       {
-	resolve_sr_conflict (state, i);
+	resolve_sr_conflict (state, i, errs);
 	break;
       }
 
@@ -285,10 +292,18 @@ set_conflicts (state_t *state)
     }
 }
 
+
+/*----------------------------------------------------------------.
+| Solve all the S/R conflicts using the precedence/associativity, |
+| and flag as inconsistent the states that still have conflicts.  |
+`----------------------------------------------------------------*/
+
 void
 conflicts_solve (void)
 {
   state_number_t i;
+  /* List of lookaheads on which we explicitly raise a parse error.  */
+  symbol_number_t *errs = XMALLOC (symbol_number_t, ntokens + 1);
 
   conflicts = XCALLOC (char, nstates);
   shiftset = bitset_create (ntokens, BITSET_FIXED);
@@ -296,7 +311,16 @@ conflicts_solve (void)
   obstack_init (&solved_conflicts_obstack);
 
   for (i = 0; i < nstates; i++)
-    set_conflicts (states[i]);
+    {
+      set_conflicts (states[i], errs);
+
+      /* For uniformity of the code, make sure all the states have a valid
+	 `errs' member.  */
+      if (!states[i]->errs)
+	states[i]->errs = errs_new (0, 0);
+    }
+
+  free (errs);
 }
 
 
@@ -309,7 +333,7 @@ count_sr_conflicts (state_t *state)
 {
   int i;
   int src_count = 0;
-  transitions_t *transitions = state->shifts;
+  transitions_t *transitions = state->transitions;
 
   if (!transitions)
     return 0;
