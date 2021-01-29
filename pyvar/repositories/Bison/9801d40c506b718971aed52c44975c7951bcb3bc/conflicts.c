@@ -52,8 +52,13 @@ enum conflict_resolution_e
   };
 
 
+/*----------------------------------------------------------------.
+| Explain how an SR conflict between TOKEN and RULE was resolved: |
+| RESOLUTION.                                                     |
+`----------------------------------------------------------------*/
+
 static inline void
-log_resolution (int lookahead, int token,
+log_resolution (rule_t *rule, int token,
 		enum conflict_resolution_e resolution)
 {
   if (report_flag & report_solved_conflicts)
@@ -66,7 +71,7 @@ log_resolution (int lookahead, int token,
 	  obstack_fgrow2 (&solved_conflicts_obstack,
 			  _("\
     Conflict between rule %d and token %s resolved as shift"),
-			  LArule[lookahead]->number,
+			  rule->number,
 			  symbols[token]->tag);
 	  break;
 	case reduce_resolution:
@@ -74,14 +79,14 @@ log_resolution (int lookahead, int token,
 	  obstack_fgrow2 (&solved_conflicts_obstack,
 			  _("\
     Conflict between rule %d and token %s resolved as reduce"),
-			  LArule[lookahead]->number,
+			  rule->number,
 			  symbols[token]->tag);
 	  break;
 	case nonassoc_resolution:
 	  obstack_fgrow2 (&solved_conflicts_obstack,
 			  _("\
     Conflict between rule %d and token %s resolved as an error"),
-			  LArule[lookahead]->number,
+			  rule->number,
 			  symbols[token]->tag);
 	  break;
 	}
@@ -92,7 +97,7 @@ log_resolution (int lookahead, int token,
 	case shift_resolution:
 	  obstack_fgrow2 (&solved_conflicts_obstack,
 			  " (%s < %s)",
-			  LArule[lookahead]->prec->tag,
+			  rule->prec->tag,
 			  symbols[token]->tag);
 	  break;
 
@@ -100,7 +105,7 @@ log_resolution (int lookahead, int token,
 	  obstack_fgrow2 (&solved_conflicts_obstack,
 			  " (%s < %s)",
 			  symbols[token]->tag,
-			  LArule[lookahead]->prec->tag);
+			  rule->prec->tag);
 	  break;
 
 	case left_resolution:
@@ -151,9 +156,9 @@ flush_shift (state_t *state, int token)
 `-------------------------------------------------------------------*/
 
 static void
-flush_reduce (int lookahead, int token)
+flush_reduce (bitset lookaheads, int token)
 {
-  bitset_reset (LA[lookahead], token);
+  bitset_reset (lookaheads, token);
 }
 
 
@@ -162,19 +167,23 @@ flush_reduce (int lookahead, int token)
 | precedence declarations.  It has already been checked that the    |
 | rule has a precedence.  A conflict is resolved by modifying the   |
 | shift or reduce tables so that there is no longer a conflict.     |
+|                                                                   |
+| LOOKAHEAD is the number of the lookahead bitset to consider.      |
 `------------------------------------------------------------------*/
 
 static void
 resolve_sr_conflict (state_t *state, int lookahead)
 {
   int i;
-  /* find the rule to reduce by to get precedence of reduction  */
-  int redprec = LArule[lookahead]->prec->prec;
+  /* Find the rule to reduce by to get precedence of reduction.  */
+  rule_t *redrule = state->lookaheads_rule[lookahead];
+  int redprec = redrule->prec->prec;
+  bitset lookaheads = state->lookaheads[lookahead];
   errs *errp = errs_new (ntokens + 1);
   errp->nerrs = 0;
 
   for (i = 0; i < ntokens; i++)
-    if (bitset_test (LA[lookahead], i)
+    if (bitset_test (lookaheads, i)
 	&& bitset_test (lookaheadset, i)
 	&& symbols[i]->prec)
       {
@@ -183,13 +192,13 @@ resolve_sr_conflict (state_t *state, int lookahead)
 	   The precedence of shifting is that of token i.  */
 	if (symbols[i]->prec < redprec)
 	  {
-	    log_resolution (lookahead, i, reduce_resolution);
+	    log_resolution (redrule, i, reduce_resolution);
 	    flush_shift (state, i);
 	  }
 	else if (symbols[i]->prec > redprec)
 	  {
-	    log_resolution (lookahead, i, shift_resolution);
-	    flush_reduce (lookahead, i);
+	    log_resolution (redrule, i, shift_resolution);
+	    flush_reduce (lookaheads, i);
 	  }
 	else
 	  /* Matching precedence levels.
@@ -200,19 +209,19 @@ resolve_sr_conflict (state_t *state, int lookahead)
 	  switch (symbols[i]->assoc)
 	    {
 	    case right_assoc:
-	      log_resolution (lookahead, i, right_resolution);
-	      flush_reduce (lookahead, i);
+	      log_resolution (redrule, i, right_resolution);
+	      flush_reduce (lookaheads, i);
 	      break;
 
 	    case left_assoc:
-	      log_resolution (lookahead, i, left_resolution);
+	      log_resolution (redrule, i, left_resolution);
 	      flush_shift (state, i);
 	      break;
 
 	    case non_assoc:
-	      log_resolution (lookahead, i, nonassoc_resolution);
+	      log_resolution (redrule, i, nonassoc_resolution);
 	      flush_shift (state, i);
-	      flush_reduce (lookahead, i);
+	      flush_reduce (lookaheads, i);
 	      /* Record an explicit error for this token.  */
 	      errp->errs[errp->nerrs++] = i;
 	      break;
@@ -254,13 +263,13 @@ set_conflicts (state_t *state)
 
   /* Loop over all rules which require lookahead in this state.  First
      check for shift-reduce conflict, and try to resolve using
-     precedence */
+     precedence.  */
   for (i = 0; i < state->nlookaheads; ++i)
     if (state->lookaheads_rule[i]->prec
 	&& state->lookaheads_rule[i]->prec->prec
 	&& !bitset_disjoint_p (state->lookaheads[i], lookaheadset))
       {
-	resolve_sr_conflict (state, (state->lookaheads - LA) + i);
+	resolve_sr_conflict (state, i);
 	break;
       }
 
