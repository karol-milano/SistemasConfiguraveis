@@ -40,7 +40,7 @@
 #include "symtab.h"
 
 static bitset shift_set;
-static bitset look_ahead_set;
+static bitset lookahead_set;
 
 #if 0
 static void
@@ -111,9 +111,9 @@ print_core (FILE *out, state *s)
       for (/* Nothing */; *sp >= 0; ++sp)
 	fprintf (out, " %s", symbols[*sp]->tag);
 
-      /* Display the look-ahead tokens?  */
-      if (report_flag & report_look_ahead_tokens)
-	state_rule_look_ahead_tokens_print (s, &rules[r], out);
+      /* Display the lookahead tokens?  */
+      if (report_flag & report_lookahead_tokens)
+	state_rule_lookahead_tokens_print (s, &rules[r], out);
 
       fputc ('\n', out);
     }
@@ -132,7 +132,7 @@ print_transitions (state *s, FILE *out, bool display_transitions_p)
   size_t width = 0;
   int i;
 
-  /* Compute the width of the look-ahead token column.  */
+  /* Compute the width of the lookahead token column.  */
   for (i = 0; i < trans->num; i++)
     if (!TRANSITION_IS_DISABLED (trans, i)
 	&& TRANSITION_IS_SHIFT (trans, i) == display_transitions_p)
@@ -148,7 +148,7 @@ print_transitions (state *s, FILE *out, bool display_transitions_p)
   fputc ('\n', out);
   width += 2;
 
-  /* Report look-ahead tokens and shifts.  */
+  /* Report lookahead tokens and shifts.  */
   for (i = 0; i < trans->num; i++)
     if (!TRANSITION_IS_DISABLED (trans, i)
 	&& TRANSITION_IS_SHIFT (trans, i) == display_transitions_p)
@@ -180,7 +180,7 @@ print_errs (FILE *out, state *s)
   size_t width = 0;
   int i;
 
-  /* Compute the width of the look-ahead token column.  */
+  /* Compute the width of the lookahead token column.  */
   for (i = 0; i < errp->num; ++i)
     if (errp->symbols[i])
       max_length (&width, errp->symbols[i]->tag);
@@ -192,7 +192,7 @@ print_errs (FILE *out, state *s)
   fputc ('\n', out);
   width += 2;
 
-  /* Report look-ahead tokens and errors.  */
+  /* Report lookahead tokens and errors.  */
   for (i = 0; i < errp->num; ++i)
     if (errp->symbols[i])
       {
@@ -218,11 +218,11 @@ state_default_rule (state *s)
   int cmax = 0;
   int i;
 
-  /* No need for a look-ahead.  */
+  /* No need for a lookahead.  */
   if (s->consistent)
     return reds->rules[0];
 
-  /* 1. Each reduction is possibly masked by the look-ahead tokens on which
+  /* 1. Each reduction is possibly masked by the lookahead tokens on which
      we shift (S/R conflicts)...  */
   bitset_zero (shift_set);
   {
@@ -237,7 +237,7 @@ state_default_rule (state *s)
       }
   }
 
-  /* 2. Each reduction is possibly masked by the look-ahead tokens on which
+  /* 2. Each reduction is possibly masked by the lookahead tokens on which
      we raise an error (due to %nonassoc).  */
   {
     errs *errp = s->errs;
@@ -250,10 +250,10 @@ state_default_rule (state *s)
     {
       int count = 0;
 
-      /* How many non-masked look-ahead tokens are there for this
+      /* How many non-masked lookahead tokens are there for this
 	 reduction?  */
-      bitset_andn (look_ahead_set, reds->look_ahead_tokens[i], shift_set);
-      count = bitset_count (look_ahead_set);
+      bitset_andn (lookahead_set, reds->lookahead_tokens[i], shift_set);
+      count = bitset_count (lookahead_set);
 
       if (count > cmax)
 	{
@@ -264,27 +264,27 @@ state_default_rule (state *s)
       /* 3. And finally, each reduction is possibly masked by previous
 	 reductions (in R/R conflicts, we keep the first reductions).
 	 */
-      bitset_or (shift_set, shift_set, reds->look_ahead_tokens[i]);
+      bitset_or (shift_set, shift_set, reds->lookahead_tokens[i]);
     }
 
   return default_rule;
 }
 
 
-/*--------------------------------------------------------------------------.
-| Report a reduction of RULE on LOOK_AHEAD_TOKEN (which can be `default').  |
-| If not ENABLED, the rule is masked by a shift or a reduce (S/R and        |
-| R/R conflicts).                                                           |
-`--------------------------------------------------------------------------*/
+/*-------------------------------------------------------------------------.
+| Report a reduction of RULE on LOOKAHEAD_TOKEN (which can be `default').  |
+| If not ENABLED, the rule is masked by a shift or a reduce (S/R and       |
+| R/R conflicts).                                                          |
+`-------------------------------------------------------------------------*/
 
 static void
 print_reduction (FILE *out, size_t width,
-		 const char *look_ahead_token,
+		 const char *lookahead_token,
 		 rule *r, bool enabled)
 {
   int j;
-  fprintf (out, "    %s", look_ahead_token);
-  for (j = width - strlen (look_ahead_token); j > 0; --j)
+  fprintf (out, "    %s", lookahead_token);
+  for (j = width - strlen (lookahead_token); j > 0; --j)
     fputc (' ', out);
   if (!enabled)
     fputc ('[', out);
@@ -320,17 +320,17 @@ print_reductions (FILE *out, state *s)
   FOR_EACH_SHIFT (trans, i)
     bitset_set (shift_set, TRANSITION_SYMBOL (trans, i));
 
-  /* Compute the width of the look-ahead token column.  */
+  /* Compute the width of the lookahead token column.  */
   if (default_rule)
     width = strlen (_("$default"));
 
-  if (reds->look_ahead_tokens)
+  if (reds->lookahead_tokens)
     for (i = 0; i < ntokens; i++)
       {
 	bool count = bitset_test (shift_set, i);
 
 	for (j = 0; j < reds->num; ++j)
-	  if (bitset_test (reds->look_ahead_tokens[j], i))
+	  if (bitset_test (reds->lookahead_tokens[j], i))
 	    {
 	      if (! count)
 		{
@@ -352,15 +352,15 @@ print_reductions (FILE *out, state *s)
   fputc ('\n', out);
   width += 2;
 
-  /* Report look-ahead tokens (or $default) and reductions.  */
-  if (reds->look_ahead_tokens)
+  /* Report lookahead tokens (or $default) and reductions.  */
+  if (reds->lookahead_tokens)
     for (i = 0; i < ntokens; i++)
       {
 	bool defaulted = false;
 	bool count = bitset_test (shift_set, i);
 
 	for (j = 0; j < reds->num; ++j)
-	  if (bitset_test (reds->look_ahead_tokens[j], i))
+	  if (bitset_test (reds->lookahead_tokens[j], i))
 	    {
 	      if (! count)
 		{
@@ -563,11 +563,11 @@ print_results (void)
     new_closure (nritems);
   /* Storage for print_reductions.  */
   shift_set =  bitset_create (ntokens, BITSET_FIXED);
-  look_ahead_set = bitset_create (ntokens, BITSET_FIXED);
+  lookahead_set = bitset_create (ntokens, BITSET_FIXED);
   for (i = 0; i < nstates; i++)
     print_state (out, states[i]);
   bitset_free (shift_set);
-  bitset_free (look_ahead_set);
+  bitset_free (lookahead_set);
   if (report_flag & report_itemsets)
     free_closure ();
 
