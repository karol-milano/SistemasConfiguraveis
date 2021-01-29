@@ -1,4 +1,5 @@
 /* Find and resolve or report look-ahead conflicts for bison,
+
    Copyright (C) 1984, 1989, 1992, 2000, 2001, 2002
    Free Software Foundation, Inc.
 
@@ -20,17 +21,19 @@
    02111-1307, USA.  */
 
 #include "system.h"
-#include "bitset.h"
+
+#include <bitset.h>
+
+#include "LR0.h"
 #include "complain.h"
-#include "getargs.h"
-#include "symtab.h"
+#include "conflicts.h"
 #include "files.h"
+#include "getargs.h"
 #include "gram.h"
-#include "state.h"
 #include "lalr.h"
-#include "conflicts.h"
 #include "reader.h"
-#include "LR0.h"
+#include "state.h"
+#include "symtab.h"
 
 /* -1 stands for not specified. */
 int expected_conflicts = -1;
@@ -42,7 +45,7 @@ static bitset lookaheadset;
 
 
 
-enum conflict_resolution_e
+enum conflict_resolution
   {
     shift_resolution,
     reduce_resolution,
@@ -58,8 +61,8 @@ enum conflict_resolution_e
 `----------------------------------------------------------------*/
 
 static inline void
-log_resolution (rule_t *rule, symbol_number_t token,
-		enum conflict_resolution_e resolution)
+log_resolution (rule *r, symbol_number token,
+		enum conflict_resolution resolution)
 {
   if (report_flag & report_solved_conflicts)
     {
@@ -71,7 +74,7 @@ log_resolution (rule_t *rule, symbol_number_t token,
 	  obstack_fgrow2 (&solved_conflicts_obstack,
 			  _("\
     Conflict between rule %d and token %s resolved as shift"),
-			  rule->number,
+			  r->number,
 			  symbols[token]->tag);
 	  break;
 	case reduce_resolution:
@@ -79,14 +82,14 @@ log_resolution (rule_t *rule, symbol_number_t token,
 	  obstack_fgrow2 (&solved_conflicts_obstack,
 			  _("\
     Conflict between rule %d and token %s resolved as reduce"),
-			  rule->number,
+			  r->number,
 			  symbols[token]->tag);
 	  break;
 	case nonassoc_resolution:
 	  obstack_fgrow2 (&solved_conflicts_obstack,
 			  _("\
     Conflict between rule %d and token %s resolved as an error"),
-			  rule->number,
+			  r->number,
 			  symbols[token]->tag);
 	  break;
 	}
@@ -97,7 +100,7 @@ log_resolution (rule_t *rule, symbol_number_t token,
 	case shift_resolution:
 	  obstack_fgrow2 (&solved_conflicts_obstack,
 			  " (%s < %s)",
-			  rule->prec->tag,
+			  r->prec->tag,
 			  symbols[token]->tag);
 	  break;
 
@@ -105,7 +108,7 @@ log_resolution (rule_t *rule, symbol_number_t token,
 	  obstack_fgrow2 (&solved_conflicts_obstack,
 			  " (%s < %s)",
 			  symbols[token]->tag,
-			  rule->prec->tag);
+			  r->prec->tag);
 	  break;
 
 	case left_resolution:
@@ -137,16 +140,16 @@ log_resolution (rule_t *rule, symbol_number_t token,
 `------------------------------------------------------------------*/
 
 static void
-flush_shift (state_t *state, int token)
+flush_shift (state *s, int token)
 {
-  transitions_t *transitions = state->transitions;
+  transitions *trans = s->transitions;
   int i;
 
   bitset_reset (lookaheadset, token);
-  for (i = 0; i < transitions->num; i++)
-    if (!TRANSITION_IS_DISABLED (transitions, i)
-	&& TRANSITION_SYMBOL (transitions, i) == token)
-      TRANSITION_DISABLE (transitions, i);
+  for (i = 0; i < trans->num; i++)
+    if (!TRANSITION_IS_DISABLED (trans, i)
+	&& TRANSITION_SYMBOL (trans, i) == token)
+      TRANSITION_DISABLE (trans, i);
 }
 
 
@@ -171,17 +174,16 @@ flush_reduce (bitset lookaheads, int token)
 |                                                                   |
 | LOOKAHEAD is the number of the lookahead bitset to consider.      |
 |                                                                   |
-| ERRS can be used to store discovered explicit errors.             |
+| ERRORS can be used to store discovered explicit errors.           |
 `------------------------------------------------------------------*/
 
 static void
-resolve_sr_conflict (state_t *state, int ruleno,
-		     symbol_t **errs)
+resolve_sr_conflict (state *s, int ruleno, symbol **errors)
 {
-  symbol_number_t i;
-  reductions_t *reds = state->reductions;
+  symbol_number i;
+  reductions *reds = s->reductions;
   /* Find the rule to reduce by to get precedence of reduction.  */
-  rule_t *redrule = reds->rules[ruleno];
+  rule *redrule = reds->rules[ruleno];
   int redprec = redrule->prec->prec;
   bitset lookaheads = reds->lookaheads[ruleno];
   int nerrs = 0;
@@ -197,7 +199,7 @@ resolve_sr_conflict (state_t *state, int ruleno,
 	if (symbols[i]->prec < redprec)
 	  {
 	    log_resolution (redrule, i, reduce_resolution);
-	    flush_shift (state, i);
+	    flush_shift (s, i);
 	  }
 	else if (symbols[i]->prec > redprec)
 	  {
@@ -219,15 +221,15 @@ resolve_sr_conflict (state_t *state, int ruleno,
 
 	    case left_assoc:
 	      log_resolution (redrule, i, left_resolution);
-	      flush_shift (state, i);
+	      flush_shift (s, i);
 	      break;
 
 	    case non_assoc:
 	      log_resolution (redrule, i, nonassoc_resolution);
-	      flush_shift (state, i);
+	      flush_shift (s, i);
 	      flush_reduce (lookaheads, i);
 	      /* Record an explicit error for this token.  */
-	      errs[nerrs++] = symbols[i];
+	      errors[nerrs++] = symbols[i];
 	      break;
 
 	    case undef_assoc:
@@ -237,37 +239,37 @@ resolve_sr_conflict (state_t *state, int ruleno,
 
   /* Some tokens have been explicitly made errors.  Allocate a
      permanent errs structure for this state, to record them.  */
-  state_errs_set (state, nerrs, errs);
+  state_errs_set (s, nerrs, errors);
 
   if (obstack_object_size (&solved_conflicts_obstack))
     {
       obstack_1grow (&solved_conflicts_obstack, '\0');
-      state->solved_conflicts = obstack_finish (&solved_conflicts_obstack);
+      s->solved_conflicts = obstack_finish (&solved_conflicts_obstack);
     }
 }
 
 
 /*-------------------------------------------------------------------.
-| Solve the S/R conflicts of STATE using the                         |
+| Solve the S/R conflicts of state S using the                       |
 | precedence/associativity, and flag it inconsistent if it still has |
-| conflicts.  ERRS can be used as storage to compute the list of     |
-| lookaheads on which this STATE raises a syntax error (%nonassoc).  |
+| conflicts.  ERRORS can be used as storage to compute the list of   |
+| lookaheads on which S raises a syntax error (%nonassoc).           |
 `-------------------------------------------------------------------*/
 
 static void
-set_conflicts (state_t *state, symbol_t **errs)
+set_conflicts (state *s, symbol **errors)
 {
   int i;
-  transitions_t *transitions = state->transitions;
-  reductions_t *reds = state->reductions;
+  transitions *trans = s->transitions;
+  reductions *reds = s->reductions;
 
-  if (state->consistent)
+  if (s->consistent)
     return;
 
   bitset_zero (lookaheadset);
 
-  FOR_EACH_SHIFT (transitions, i)
-    bitset_set (lookaheadset, TRANSITION_SYMBOL (transitions, i));
+  FOR_EACH_SHIFT (trans, i)
+    bitset_set (lookaheadset, TRANSITION_SYMBOL (trans, i));
 
   /* Loop over all rules which require lookahead in this state.  First
      check for shift-reduce conflict, and try to resolve using
@@ -276,7 +278,7 @@ set_conflicts (state_t *state, symbol_t **errs)
     if (reds->rules[i]->prec && reds->rules[i]->prec->prec
 	&& !bitset_disjoint_p (reds->lookaheads[i], lookaheadset))
       {
-	resolve_sr_conflict (state, i, errs);
+	resolve_sr_conflict (s, i, errors);
 	break;
       }
 
@@ -285,7 +287,7 @@ set_conflicts (state_t *state, symbol_t **errs)
   for (i = 0; i < reds->num; ++i)
     {
       if (!bitset_disjoint_p (reds->lookaheads[i], lookaheadset))
-	conflicts[state->number] = 1;
+	conflicts[s->number] = 1;
 
       bitset_or (lookaheadset, lookaheadset, reds->lookaheads[i]);
     }
@@ -300,9 +302,9 @@ set_conflicts (state_t *state, symbol_t **errs)
 void
 conflicts_solve (void)
 {
-  state_number_t i;
+  state_number i;
   /* List of lookaheads on which we explicitly raise a syntax error.  */
-  symbol_t **errs = XMALLOC (symbol_t *, ntokens + 1);
+  symbol **errors = XMALLOC (symbol *, ntokens + 1);
 
   conflicts = XCALLOC (char, nstates);
   shiftset = bitset_create (ntokens, BITSET_FIXED);
@@ -311,7 +313,7 @@ conflicts_solve (void)
 
   for (i = 0; i < nstates; i++)
     {
-      set_conflicts (states[i], errs);
+      set_conflicts (states[i], errors);
 
       /* For uniformity of the code, make sure all the states have a valid
 	 `errs' member.  */
@@ -319,7 +321,7 @@ conflicts_solve (void)
 	states[i]->errs = errs_new (0, 0);
     }
 
-  free (errs);
+  free (errors);
 }
 
 
@@ -328,21 +330,21 @@ conflicts_solve (void)
 `---------------------------------------------*/
 
 static int
-count_sr_conflicts (state_t *state)
+count_sr_conflicts (state *s)
 {
   int i;
   int src_count = 0;
-  transitions_t *transitions = state->transitions;
-  reductions_t *reds = state->reductions;
+  transitions *trans = s->transitions;
+  reductions *reds = s->reductions;
 
-  if (!transitions)
+  if (!trans)
     return 0;
 
   bitset_zero (lookaheadset);
   bitset_zero (shiftset);
 
-  FOR_EACH_SHIFT (transitions, i)
-    bitset_set (shiftset, TRANSITION_SYMBOL (transitions, i));
+  FOR_EACH_SHIFT (trans, i)
+    bitset_set (shiftset, TRANSITION_SYMBOL (trans, i));
 
   for (i = 0; i < reds->num; ++i)
     bitset_or (lookaheadset, lookaheadset, reds->lookaheads[i]);
@@ -363,10 +365,10 @@ count_sr_conflicts (state_t *state)
 +`----------------------------------------------------------------*/
 
 static int
-count_rr_conflicts (state_t *state, int one_per_token)
+count_rr_conflicts (state *s, int one_per_token)
 {
   int i;
-  reductions_t *reds = state->reductions;
+  reductions *reds = s->reductions;
   int rrc_count = 0;
 
   for (i = 0; i < ntokens; i++)
@@ -450,10 +452,10 @@ void
 conflicts_output (FILE *out)
 {
   bool printed_sth = false;
-  state_number_t i;
+  state_number i;
   for (i = 0; i < nstates; i++)
     {
-      state_t *s = states[i];
+      state *s = states[i];
       if (conflicts[i])
 	{
 	  fprintf (out, _("State %d contains "), i);
@@ -477,7 +479,7 @@ conflicts_output (FILE *out)
 int
 conflicts_total_count (void)
 {
-  state_number_t i;
+  state_number i;
   int count;
 
   /* Conflicts by state.  */
@@ -509,7 +511,7 @@ conflicts_print (void)
 
   /* Conflicts by state.  */
   {
-    state_number_t i;
+    state_number i;
 
     for (i = 0; i < nstates; i++)
       if (conflicts[i])
