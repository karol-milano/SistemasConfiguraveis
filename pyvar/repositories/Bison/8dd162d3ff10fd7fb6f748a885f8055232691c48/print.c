@@ -1,6 +1,6 @@
 /* Print information on generated parser, for bison,
 
-   Copyright (C) 1984, 1986, 1989, 2000, 2001, 2002, 2003
+   Copyright (C) 1984, 1986, 1989, 2000, 2001, 2002, 2003, 2004
    Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
@@ -39,8 +39,8 @@
 #include "state.h"
 #include "symtab.h"
 
-static bitset shiftset;
-static bitset lookaheadset;
+static bitset shift_set;
+static bitset look_ahead_set;
 
 #if 0
 static void
@@ -111,9 +111,9 @@ print_core (FILE *out, state *s)
       for (/* Nothing */; *sp >= 0; ++sp)
 	fprintf (out, " %s", symbols[*sp]->tag);
 
-      /* Display the lookaheads?  */
-      if (report_flag & report_lookaheads)
-	state_rule_lookaheads_print (s, &rules[r], out);
+      /* Display the look-ahead tokens?  */
+      if (report_flag & report_look_ahead_tokens)
+	state_rule_look_ahead_tokens_print (s, &rules[r], out);
 
       fputc ('\n', out);
     }
@@ -132,7 +132,7 @@ print_transitions (state *s, FILE *out, bool display_transitions_p)
   size_t width = 0;
   int i;
 
-  /* Compute the width of the lookaheads column.  */
+  /* Compute the width of the look-ahead token column.  */
   for (i = 0; i < trans->num; i++)
     if (!TRANSITION_IS_DISABLED (trans, i)
 	&& TRANSITION_IS_SHIFT (trans, i) == display_transitions_p)
@@ -148,7 +148,7 @@ print_transitions (state *s, FILE *out, bool display_transitions_p)
   fputc ('\n', out);
   width += 2;
 
-  /* Report lookaheads and shifts.  */
+  /* Report look-ahead tokens and shifts.  */
   for (i = 0; i < trans->num; i++)
     if (!TRANSITION_IS_DISABLED (trans, i)
 	&& TRANSITION_IS_SHIFT (trans, i) == display_transitions_p)
@@ -180,7 +180,7 @@ print_errs (FILE *out, state *s)
   size_t width = 0;
   int i;
 
-  /* Compute the width of the lookaheads column.  */
+  /* Compute the width of the look-ahead token column.  */
   for (i = 0; i < errp->num; ++i)
     if (errp->symbols[i])
       max_length (&width, errp->symbols[i]->tag);
@@ -192,7 +192,7 @@ print_errs (FILE *out, state *s)
   fputc ('\n', out);
   width += 2;
 
-  /* Report lookaheads and errors.  */
+  /* Report look-ahead tokens and errors.  */
   for (i = 0; i < errp->num; ++i)
     if (errp->symbols[i])
       {
@@ -218,13 +218,13 @@ state_default_rule (state *s)
   int cmax = 0;
   int i;
 
-  /* No need for a lookahead.  */
+  /* No need for a look-ahead.  */
   if (s->consistent)
     return reds->rules[0];
 
-  /* 1. Each reduction is possibly masked by the lookaheads on which
+  /* 1. Each reduction is possibly masked by the look-ahead tokens on which
      we shift (S/R conflicts)...  */
-  bitset_zero (shiftset);
+  bitset_zero (shift_set);
   {
     transitions *trans = s->transitions;
     FOR_EACH_SHIFT (trans, i)
@@ -233,27 +233,27 @@ state_default_rule (state *s)
 	     default rule.  */
 	if (TRANSITION_IS_ERROR (trans, i))
 	  return NULL;
-	bitset_set (shiftset, TRANSITION_SYMBOL (trans, i));
+	bitset_set (shift_set, TRANSITION_SYMBOL (trans, i));
       }
   }
 
-  /* 2. Each reduction is possibly masked by the lookaheads on which
+  /* 2. Each reduction is possibly masked by the look-ahead tokens on which
      we raise an error (due to %nonassoc).  */
   {
     errs *errp = s->errs;
     for (i = 0; i < errp->num; i++)
       if (errp->symbols[i])
-	bitset_set (shiftset, errp->symbols[i]->number);
+	bitset_set (shift_set, errp->symbols[i]->number);
   }
 
   for (i = 0; i < reds->num; ++i)
     {
       int count = 0;
 
-      /* How many non-masked lookaheads are there for this reduction?
-	 */
-      bitset_andn (lookaheadset, reds->lookaheads[i], shiftset);
-      count = bitset_count (lookaheadset);
+      /* How many non-masked look-ahead tokens are there for this
+	 reduction?  */
+      bitset_andn (look_ahead_set, reds->look_ahead_tokens[i], shift_set);
+      count = bitset_count (look_ahead_set);
 
       if (count > cmax)
 	{
@@ -264,27 +264,27 @@ state_default_rule (state *s)
       /* 3. And finally, each reduction is possibly masked by previous
 	 reductions (in R/R conflicts, we keep the first reductions).
 	 */
-      bitset_or (shiftset, shiftset, reds->lookaheads[i]);
+      bitset_or (shift_set, shift_set, reds->look_ahead_tokens[i]);
     }
 
   return default_rule;
 }
 
 
-/*--------------------------------------------------------------------.
-| Report a reduction of RULE on LOOKAHEADS (which can be `default').  |
-| If not ENABLED, the rule is masked by a shift or a reduce (S/R and  |
-| R/R conflicts).                                                     |
-`--------------------------------------------------------------------*/
+/*--------------------------------------------------------------------------.
+| Report a reduction of RULE on LOOK_AHEAD_TOKEN (which can be `default').  |
+| If not ENABLED, the rule is masked by a shift or a reduce (S/R and        |
+| R/R conflicts).                                                           |
+`--------------------------------------------------------------------------*/
 
 static void
 print_reduction (FILE *out, size_t width,
-		 const char *lookahead,
+		 const char *look_ahead_token,
 		 rule *r, bool enabled)
 {
   int j;
-  fprintf (out, "    %s", lookahead);
-  for (j = width - strlen (lookahead); j > 0; --j)
+  fprintf (out, "    %s", look_ahead_token);
+  for (j = width - strlen (look_ahead_token); j > 0; --j)
     fputc (' ', out);
   if (!enabled)
     fputc ('[', out);
@@ -316,21 +316,21 @@ print_reductions (FILE *out, state *s)
 
   default_rule = state_default_rule (s);
 
-  bitset_zero (shiftset);
+  bitset_zero (shift_set);
   FOR_EACH_SHIFT (trans, i)
-    bitset_set (shiftset, TRANSITION_SYMBOL (trans, i));
+    bitset_set (shift_set, TRANSITION_SYMBOL (trans, i));
 
-  /* Compute the width of the lookaheads column.  */
+  /* Compute the width of the look-ahead token column.  */
   if (default_rule)
     width = strlen (_("$default"));
 
-  if (reds->lookaheads)
+  if (reds->look_ahead_tokens)
     for (i = 0; i < ntokens; i++)
       {
-	bool count = bitset_test (shiftset, i);
+	bool count = bitset_test (shift_set, i);
 
 	for (j = 0; j < reds->num; ++j)
-	  if (bitset_test (reds->lookaheads[j], i))
+	  if (bitset_test (reds->look_ahead_tokens[j], i))
 	    {
 	      if (! count)
 		{
@@ -352,15 +352,15 @@ print_reductions (FILE *out, state *s)
   fputc ('\n', out);
   width += 2;
 
-  /* Report lookaheads (or $default) and reductions.  */
-  if (reds->lookaheads)
+  /* Report look-ahead tokens (or $default) and reductions.  */
+  if (reds->look_ahead_tokens)
     for (i = 0; i < ntokens; i++)
       {
 	bool defaulted = false;
-	bool count = bitset_test (shiftset, i);
+	bool count = bitset_test (shift_set, i);
 
 	for (j = 0; j < reds->num; ++j)
-	  if (bitset_test (reds->lookaheads[j], i))
+	  if (bitset_test (reds->look_ahead_tokens[j], i))
 	    {
 	      if (! count)
 		{
@@ -562,12 +562,12 @@ print_results (void)
   if (report_flag & report_itemsets)
     new_closure (nritems);
   /* Storage for print_reductions.  */
-  shiftset =  bitset_create (ntokens, BITSET_FIXED);
-  lookaheadset = bitset_create (ntokens, BITSET_FIXED);
+  shift_set =  bitset_create (ntokens, BITSET_FIXED);
+  look_ahead_set = bitset_create (ntokens, BITSET_FIXED);
   for (i = 0; i < nstates; i++)
     print_state (out, states[i]);
-  bitset_free (shiftset);
-  bitset_free (lookaheadset);
+  bitset_free (shift_set);
+  bitset_free (look_ahead_set);
   if (report_flag & report_itemsets)
     free_closure ();
 
