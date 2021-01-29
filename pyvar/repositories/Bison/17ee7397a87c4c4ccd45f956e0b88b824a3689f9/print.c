@@ -21,20 +21,22 @@
 
 
 #include "system.h"
-#include "quotearg.h"
-#include "files.h"
-#include "symtab.h"
-#include "gram.h"
+
+#include <bitset.h>
+#include <quotearg.h>
+
 #include "LR0.h"
-#include "lalr.h"
+#include "closure.h"
 #include "conflicts.h"
+#include "files.h"
 #include "getargs.h"
-#include "state.h"
-#include "reader.h"
+#include "gram.h"
+#include "lalr.h"
 #include "print.h"
+#include "reader.h"
 #include "reduce.h"
-#include "closure.h"
-#include "bitset.h"
+#include "state.h"
+#include "symtab.h"
 
 static bitset shiftset;
 static bitset lookaheadset;
@@ -66,12 +68,12 @@ max_length (size_t *width, const char *str)
 `--------------------------------*/
 
 static void
-print_core (FILE *out, state_t *state)
+print_core (FILE *out, state *s)
 {
   int i;
-  item_number_t *sitems = state->items;
-  int snritems   = state->nitems;
-  symbol_t *previous_lhs = NULL;
+  item_number *sitems = s->items;
+  int snritems = s->nitems;
+  symbol *previous_lhs = NULL;
 
   /* Output all the items of a state, not only its kernel.  */
   if (report_flag & report_itemsets)
@@ -88,21 +90,21 @@ print_core (FILE *out, state_t *state)
 
   for (i = 0; i < snritems; i++)
     {
-      item_number_t *sp;
-      item_number_t *sp1;
-      int rule;
+      item_number *sp;
+      item_number *sp1;
+      int r;
 
       sp1 = sp = ritem + sitems[i];
 
       while (*sp >= 0)
 	sp++;
 
-      rule = item_number_as_rule_number (*sp);
+      r = item_number_as_rule_number (*sp);
 
-      rule_lhs_print (&rules[rule], previous_lhs, out);
-      previous_lhs = rules[rule].lhs;
+      rule_lhs_print (&rules[r], previous_lhs, out);
+      previous_lhs = rules[r].lhs;
 
-      for (sp = rules[rule].rhs; sp < sp1; sp++)
+      for (sp = rules[r].rhs; sp < sp1; sp++)
 	fprintf (out, " %s", symbols[*sp]->tag);
       fputs (" .", out);
       for (/* Nothing */; *sp >= 0; ++sp)
@@ -110,32 +112,32 @@ print_core (FILE *out, state_t *state)
 
       /* Display the lookaheads?  */
       if (report_flag & report_lookaheads)
-	state_rule_lookaheads_print (state, &rules[rule], out);
+	state_rule_lookaheads_print (s, &rules[r], out);
 
       fputc ('\n', out);
     }
 }
 
 
-/*----------------------------------------------------------------.
-| Report the shifts iff DISPLAY_SHIFTS_P or the gotos of STATE on |
-| OUT.                                                            |
-`----------------------------------------------------------------*/
+/*------------------------------------------------------------.
+| Report the shifts iff DISPLAY_SHIFTS_P or the gotos of S on |
+| OUT.                                                        |
+`------------------------------------------------------------*/
 
 static void
-print_transitions (state_t *state, FILE *out, bool display_transitions_p)
+print_transitions (state *s, FILE *out, bool display_transitions_p)
 {
-  transitions_t *transitions = state->transitions;
+  transitions *trans = s->transitions;
   size_t width = 0;
   int i;
 
   /* Compute the width of the lookaheads column.  */
-  for (i = 0; i < transitions->num; i++)
-    if (!TRANSITION_IS_DISABLED (transitions, i)
-	&& TRANSITION_IS_SHIFT (transitions, i) == display_transitions_p)
+  for (i = 0; i < trans->num; i++)
+    if (!TRANSITION_IS_DISABLED (trans, i)
+	&& TRANSITION_IS_SHIFT (trans, i) == display_transitions_p)
       {
-	symbol_t *symbol = symbols[TRANSITION_SYMBOL (transitions, i)];
-	max_length (&width, symbol->tag);
+	symbol *sym = symbols[TRANSITION_SYMBOL (trans, i)];
+	max_length (&width, sym->tag);
       }
 
   /* Nothing to report. */
@@ -146,34 +148,34 @@ print_transitions (state_t *state, FILE *out, bool display_transitions_p)
   width += 2;
 
   /* Report lookaheads and shifts.  */
-  for (i = 0; i < transitions->num; i++)
-    if (!TRANSITION_IS_DISABLED (transitions, i)
-	&& TRANSITION_IS_SHIFT (transitions, i) == display_transitions_p)
+  for (i = 0; i < trans->num; i++)
+    if (!TRANSITION_IS_DISABLED (trans, i)
+	&& TRANSITION_IS_SHIFT (trans, i) == display_transitions_p)
       {
-	symbol_t *symbol = symbols[TRANSITION_SYMBOL (transitions, i)];
-	const char *tag = symbol->tag;
-	state_t *state1 = transitions->states[i];
+	symbol *sym = symbols[TRANSITION_SYMBOL (trans, i)];
+	const char *tag = sym->tag;
+	state *s1 = trans->states[i];
 	int j;
 
 	fprintf (out, "    %s", tag);
 	for (j = width - strlen (tag); j > 0; --j)
 	  fputc (' ', out);
 	if (display_transitions_p)
-	  fprintf (out, _("shift, and go to state %d\n"), state1->number);
+	  fprintf (out, _("shift, and go to state %d\n"), s1->number);
 	else
-	  fprintf (out, _("go to state %d\n"), state1->number);
+	  fprintf (out, _("go to state %d\n"), s1->number);
       }
 }
 
 
-/*------------------------------------------------------------.
-| Report the explicit errors of STATE raised from %nonassoc.  |
-`------------------------------------------------------------*/
+/*--------------------------------------------------------.
+| Report the explicit errors of S raised from %nonassoc.  |
+`--------------------------------------------------------*/
 
 static void
-print_errs (FILE *out, state_t *state)
+print_errs (FILE *out, state *s)
 {
-  errs_t *errp = state->errs;
+  errs *errp = s->errs;
   size_t width = 0;
   int i;
 
@@ -203,66 +205,65 @@ print_errs (FILE *out, state_t *state)
 }
 
 
-/*----------------------------------------------------------.
-| Return the default rule of this STATE if it has one, NULL |
-| otherwise.                                                |
-`----------------------------------------------------------*/
+/*-------------------------------------------------------------.
+| Return the default rule of S if it has one, NULL otherwise.  |
+`-------------------------------------------------------------*/
 
-static rule_t *
-state_default_rule (state_t *state)
+static rule *
+state_default_rule (state *s)
 {
-  reductions_t *redp = state->reductions;
-  rule_t *default_rule = NULL;
+  reductions *reds = s->reductions;
+  rule *default_rule = NULL;
   int cmax = 0;
   int i;
 
   /* No need for a lookahead.  */
-  if (state->consistent)
-    return redp->rules[0];
+  if (s->consistent)
+    return reds->rules[0];
 
   /* 1. Each reduction is possibly masked by the lookaheads on which
      we shift (S/R conflicts)...  */
   bitset_zero (shiftset);
   {
-    transitions_t *transitions = state->transitions;
-    FOR_EACH_SHIFT (transitions, i)
+    transitions *trans = s->transitions;
+    FOR_EACH_SHIFT (trans, i)
       {
 	/* If this state has a shift for the error token, don't use a
 	     default rule.  */
-	if (TRANSITION_IS_ERROR (transitions, i))
+	if (TRANSITION_IS_ERROR (trans, i))
 	  return NULL;
-	bitset_set (shiftset, TRANSITION_SYMBOL (transitions, i));
+	bitset_set (shiftset, TRANSITION_SYMBOL (trans, i));
       }
   }
 
   /* 2. Each reduction is possibly masked by the lookaheads on which
      we raise an error (due to %nonassoc).  */
   {
-    errs_t *errp = state->errs;
+    errs *errp = s->errs;
     for (i = 0; i < errp->num; i++)
       if (errp->symbols[i])
 	bitset_set (shiftset, errp->symbols[i]->number);
   }
 
-  for (i = 0; i < redp->num; ++i)
+  for (i = 0; i < reds->num; ++i)
     {
       int count = 0;
 
       /* How many non-masked lookaheads are there for this reduction?
 	 */
-      bitset_andn (lookaheadset, redp->lookaheads[i], shiftset);
+      bitset_andn (lookaheadset, reds->lookaheads[i], shiftset);
       count = bitset_count (lookaheadset);
 
       if (count > cmax)
 	{
 	  cmax = count;
-	  default_rule = redp->rules[i];
+	  default_rule = reds->rules[i];
 	}
 
       /* 3. And finally, each reduction is possibly masked by previous
 	 reductions (in R/R conflicts, we keep the first reductions).
 	 */
-      bitset_or (shiftset, shiftset, redp->lookaheads[i]);
+      bitset_or (shiftset, shiftset, reds->lookaheads[i]);
     }
 
   return default_rule;
@@ -278,7 +279,7 @@ state_default_rule (state_t *state)
 static void
 print_reduction (FILE *out, size_t width,
 		 const char *lookahead,
-		 rule_t *rule, bool enabled)
+		 rule *r, bool enabled)
 {
   int j;
   fprintf (out, "    %s", lookahead);
@@ -286,9 +287,8 @@ print_reduction (FILE *out, size_t width,
     fputc (' ', out);
   if (!enabled)
     fputc ('[', out);
-  if (rule->number)
-    fprintf (out, _("reduce using rule %d (%s)"),
-	     rule->number, rule->lhs->tag);
+  if (r->number)
+    fprintf (out, _("reduce using rule %d (%s)"), r->number, r->lhs->tag);
   else
     fprintf (out, _("accept"));
   if (!enabled)
@@ -297,43 +297,43 @@ print_reduction (FILE *out, size_t width,
 }
 
 
-/*----------------------------------------------------.
-| Report on OUT the reduction actions of this STATE.  |
-`----------------------------------------------------*/
+/*-------------------------------------------.
+| Report on OUT the reduction actions of S.  |
+`-------------------------------------------*/
 
 static void
-print_reductions (FILE *out, state_t *state)
+print_reductions (FILE *out, state *s)
 {
-  transitions_t *transitions = state->transitions;
-  reductions_t *redp = state->reductions;
-  rule_t *default_rule = NULL;
+  transitions *trans = s->transitions;
+  reductions *reds = s->reductions;
+  rule *default_rule = NULL;
   size_t width = 0;
   int i, j;
 
-  if (redp->num == 0)
+  if (reds->num == 0)
     return;
 
-  default_rule = state_default_rule (state);
+  default_rule = state_default_rule (s);
 
   bitset_zero (shiftset);
-  FOR_EACH_SHIFT (transitions, i)
-    bitset_set (shiftset, TRANSITION_SYMBOL (transitions, i));
+  FOR_EACH_SHIFT (trans, i)
+    bitset_set (shiftset, TRANSITION_SYMBOL (trans, i));
 
   /* Compute the width of the lookaheads column.  */
   if (default_rule)
     width = strlen (_("$default"));
 
-  if (redp->lookaheads)
+  if (reds->lookaheads)
     for (i = 0; i < ntokens; i++)
       {
 	int count = bitset_test (shiftset, i);
 
-	for (j = 0; j < redp->num; ++j)
-	  if (bitset_test (redp->lookaheads[j], i))
+	for (j = 0; j < reds->num; ++j)
+	  if (bitset_test (reds->lookaheads[j], i))
 	    {
 	      if (count == 0)
 		{
-		  if (redp->rules[j] != default_rule)
+		  if (reds->rules[j] != default_rule)
 		    max_length (&width, symbols[i]->tag);
 		  count++;
 		}
@@ -352,21 +352,21 @@ print_reductions (FILE *out, state_t *state)
   width += 2;
 
   /* Report lookaheads (or $default) and reductions.  */
-  if (redp->lookaheads)
+  if (reds->lookaheads)
     for (i = 0; i < ntokens; i++)
       {
 	int defaulted = 0;
 	int count = bitset_test (shiftset, i);
 
-	for (j = 0; j < redp->num; ++j)
-	  if (bitset_test (redp->lookaheads[j], i))
+	for (j = 0; j < reds->num; ++j)
+	  if (bitset_test (reds->lookaheads[j], i))
 	    {
 	      if (count == 0)
 		{
-		  if (redp->rules[j] != default_rule)
+		  if (reds->rules[j] != default_rule)
 		    print_reduction (out, width,
 				     symbols[i]->tag,
-				     redp->rules[j], true);
+				     reds->rules[j], true);
 		  else
 		    defaulted = 1;
 		  count++;
@@ -380,7 +380,7 @@ print_reductions (FILE *out, state_t *state)
 		  defaulted = 0;
 		  print_reduction (out, width,
 				   symbols[i]->tag,
-				   redp->rules[j], false);
+				   reds->rules[j], false);
 		}
 	    }
       }
@@ -393,38 +393,37 @@ print_reductions (FILE *out, state_t *state)
 
 /*--------------------------------------------------------------.
 | Report on OUT all the actions (shifts, gotos, reductions, and |
-| explicit erros from %nonassoc) of STATE.                      |
+| explicit erros from %nonassoc) of S.                          |
 `--------------------------------------------------------------*/
 
 static void
-print_actions (FILE *out, state_t *state)
+print_actions (FILE *out, state *s)
 {
   /* Print shifts.  */
-  print_transitions (state, out, true);
-  print_errs (out, state);
-  print_reductions (out, state);
+  print_transitions (s, out, true);
+  print_errs (out, s);
+  print_reductions (out, s);
   /* Print gotos.  */
-  print_transitions (state, out, false);
+  print_transitions (s, out, false);
 }
 
 
-/*--------------------------------------.
-| Report all the data on STATE on OUT.  |
-`--------------------------------------*/
+/*----------------------------------.
+| Report all the data on S on OUT.  |
+`----------------------------------*/
 
 static void
-print_state (FILE *out, state_t *state)
+print_state (FILE *out, state *s)
 {
   fputs ("\n\n", out);
-  fprintf (out, _("state %d"), state->number);
+  fprintf (out, _("state %d"), s->number);
   fputc ('\n', out);
-  print_core (out, state);
-  print_actions (out, state);
-  if ((report_flag & report_solved_conflicts)
-      && state->solved_conflicts)
+  print_core (out, s);
+  print_actions (out, s);
+  if ((report_flag & report_solved_conflicts) && s->solved_conflicts)
     {
       fputc ('\n', out);
-      fputs (state->solved_conflicts, out);
+      fputs (s->solved_conflicts, out);
     }
 }
 
@@ -446,7 +445,7 @@ do {						\
 static void
 print_grammar (FILE *out)
 {
-  symbol_number_t i;
+  symbol_number i;
   char buffer[90];
   int column = 0;
 
@@ -458,8 +457,8 @@ print_grammar (FILE *out)
     if (token_translations[i] != undeftoken->number)
       {
 	const char *tag = symbols[token_translations[i]]->tag;
-	rule_number_t r;
-	item_number_t *rhsp;
+	rule_number r;
+	item_number *rhsp;
 
 	buffer[0] = 0;
 	column = strlen (tag);
@@ -484,12 +483,12 @@ print_grammar (FILE *out)
   for (i = ntokens; i < nsyms; i++)
     {
       int left_count = 0, right_count = 0;
-      rule_number_t r;
+      rule_number r;
       const char *tag = symbols[i]->tag;
 
       for (r = 0; r < nrules; r++)
 	{
-	  item_number_t *rhsp;
+	  item_number *rhsp;
 	  if (rules[r].lhs->number == i)
 	    left_count++;
 	  for (rhsp = rules[r].rhs; *rhsp >= 0; rhsp++)
@@ -527,7 +526,7 @@ print_grammar (FILE *out)
 	  sprintf (buffer + strlen (buffer), _(" on right:"));
 	  for (r = 0; r < nrules; r++)
 	    {
-	      item_number_t *rhsp;
+	      item_number *rhsp;
 	      for (rhsp = rules[r].rhs; *rhsp >= 0; rhsp++)
 		if (item_number_as_symbol_number (*rhsp) == i)
 		  {
@@ -544,7 +543,7 @@ print_grammar (FILE *out)
 void
 print_results (void)
 {
-  state_number_t i;
+  state_number i;
 
   /* We used to use just .out if SPEC_NAME_PREFIX (-p) was used, but
      that conflicts with Posix.  */
