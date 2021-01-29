@@ -61,7 +61,6 @@ max_length (size_t *width, const char *str)
 static void
 print_core (FILE *out, state *s)
 {
-  size_t i;
   item_number *sitems = s->items;
   size_t snritems = s->nitems;
   sym_content *previous_lhs = NULL;
@@ -79,18 +78,15 @@ print_core (FILE *out, state *s)
 
   fputc ('\n', out);
 
-  for (i = 0; i < snritems; i++)
+  for (size_t i = 0; i < snritems; i++)
     {
-      item_number *sp;
-      item_number *sp1;
-      rule_number r;
-
-      sp1 = sp = ritem + sitems[i];
+      item_number *sp1 = ritem + sitems[i];
 
+      item_number *sp = sp1;
       while (*sp >= 0)
         sp++;
 
-      r = item_number_as_rule_number (*sp);
+      rule_number r = item_number_as_rule_number (*sp);
 
       rule_lhs_print (&rules[r], previous_lhs, out);
       previous_lhs = rules[r].lhs;
@@ -124,10 +120,9 @@ print_transitions (state *s, FILE *out, bool display_transitions_p)
 {
   transitions *trans = s->transitions;
   size_t width = 0;
-  int i;
 
   /* Compute the width of the lookahead token column.  */
-  for (i = 0; i < trans->num; i++)
+  for (int i = 0; i < trans->num; i++)
     if (!TRANSITION_IS_DISABLED (trans, i)
         && TRANSITION_IS_SHIFT (trans, i) == display_transitions_p)
       {
@@ -143,17 +138,16 @@ print_transitions (state *s, FILE *out, bool display_transitions_p)
   width += 2;
 
   /* Report lookahead tokens and shifts.  */
-  for (i = 0; i < trans->num; i++)
+  for (int i = 0; i < trans->num; i++)
     if (!TRANSITION_IS_DISABLED (trans, i)
         && TRANSITION_IS_SHIFT (trans, i) == display_transitions_p)
       {
         symbol *sym = symbols[TRANSITION_SYMBOL (trans, i)];
         const char *tag = sym->tag;
         state *s1 = trans->states[i];
-        int j;
 
         fprintf (out, "    %s", tag);
-        for (j = width - strlen (tag); j > 0; --j)
+        for (int j = width - strlen (tag); j > 0; --j)
           fputc (' ', out);
         if (display_transitions_p)
           fprintf (out, _("shift, and go to state %d\n"), s1->number);
@@ -172,10 +166,9 @@ print_errs (FILE *out, state *s)
 {
   errs *errp = s->errs;
   size_t width = 0;
-  int i;
 
   /* Compute the width of the lookahead token column.  */
-  for (i = 0; i < errp->num; ++i)
+  for (int i = 0; i < errp->num; ++i)
     if (errp->symbols[i])
       max_length (&width, errp->symbols[i]->tag);
 
@@ -187,13 +180,12 @@ print_errs (FILE *out, state *s)
   width += 2;
 
   /* Report lookahead tokens and errors.  */
-  for (i = 0; i < errp->num; ++i)
+  for (int i = 0; i < errp->num; ++i)
     if (errp->symbols[i])
       {
         const char *tag = errp->symbols[i]->tag;
-        int j;
         fprintf (out, "    %s", tag);
-        for (j = width - strlen (tag); j > 0; --j)
+        for (int j = width - strlen (tag); j > 0; --j)
           fputc (' ', out);
         fputs (_("error (nonassociative)\n"), out);
       }
@@ -211,9 +203,8 @@ print_reduction (FILE *out, size_t width,
                  const char *lookahead_token,
                  rule *r, bool enabled)
 {
-  int j;
   fprintf (out, "    %s", lookahead_token);
-  for (j = width - strlen (lookahead_token); j > 0; --j)
+  for (int j = width - strlen (lookahead_token); j > 0; --j)
     fputc (' ', out);
   if (!enabled)
     fputc ('[', out);
@@ -235,36 +226,37 @@ print_reduction (FILE *out, size_t width,
 static void
 print_reductions (FILE *out, state *s)
 {
-  transitions *trans = s->transitions;
   reductions *reds = s->reductions;
-  rule *default_reduction = NULL;
-  size_t width = 0;
-  int i, j;
-  bool default_reduction_only = true;
-
   if (reds->num == 0)
     return;
 
+  rule *default_reduction = NULL;
   if (yydefact[s->number] != 0)
     default_reduction = &rules[yydefact[s->number] - 1];
 
+  transitions *trans = s->transitions;
+
   bitset_zero (no_reduce_set);
-  FOR_EACH_SHIFT (trans, i)
-    bitset_set (no_reduce_set, TRANSITION_SYMBOL (trans, i));
-  for (i = 0; i < s->errs->num; ++i)
+  {
+    int i;
+    FOR_EACH_SHIFT (trans, i)
+      bitset_set (no_reduce_set, TRANSITION_SYMBOL (trans, i));
+  }
+  for (int i = 0; i < s->errs->num; ++i)
     if (s->errs->symbols[i])
       bitset_set (no_reduce_set, s->errs->symbols[i]->content->number);
 
   /* Compute the width of the lookahead token column.  */
+  size_t width = 0;
   if (default_reduction)
     width = strlen (_("$default"));
 
   if (reds->lookahead_tokens)
-    for (i = 0; i < ntokens; i++)
+    for (int i = 0; i < ntokens; i++)
       {
         bool count = bitset_test (no_reduce_set, i);
 
-        for (j = 0; j < reds->num; ++j)
+        for (int j = 0; j < reds->num; ++j)
           if (bitset_test (reds->lookahead_tokens[j], i))
             {
               if (! count)
@@ -274,9 +266,7 @@ print_reductions (FILE *out, state *s)
                   count = true;
                 }
               else
-                {
-                  max_length (&width, symbols[i]->tag);
-                }
+                max_length (&width, symbols[i]->tag);
             }
       }
 
@@ -287,16 +277,18 @@ print_reductions (FILE *out, state *s)
   fputc ('\n', out);
   width += 2;
 
+  bool default_reduction_only = true;
+
   /* Report lookahead tokens (or $default) and reductions.  */
   if (reds->lookahead_tokens)
-    for (i = 0; i < ntokens; i++)
+    for (int i = 0; i < ntokens; i++)
       {
         bool defaulted = false;
         bool count = bitset_test (no_reduce_set, i);
         if (count)
           default_reduction_only = false;
 
-        for (j = 0; j < reds->num; ++j)
+        for (int j = 0; j < reds->num; ++j)
           if (bitset_test (reds->lookahead_tokens[j], i))
             {
               if (! count)
@@ -396,18 +388,14 @@ print_state (FILE *out, state *s)
 static void
 print_terminal_symbols (FILE *out)
 {
-  symbol_number i;
-
   /* TERMINAL (type #) : rule #s terminal is on RHS */
   fprintf (out, "%s\n\n", _("Terminals, with rules where they appear"));
-  for (i = 0; i < max_user_token_number + 1; i++)
+  for (symbol_number i = 0; i < max_user_token_number + 1; i++)
     if (token_translations[i] != undeftoken->content->number)
       {
         const char *tag = symbols[token_translations[i]]->tag;
         int column = strlen (tag);
         char buffer[90];
-        rule_number r;
-        item_number *rhsp;
 
         buffer[0] = 0;
         fputs (tag, out);
@@ -420,8 +408,8 @@ print_terminal_symbols (FILE *out)
           }
         sprintf (buffer, " (%d)", i);
 
-        for (r = 0; r < nrules; r++)
-          for (rhsp = rules[r].rhs; *rhsp >= 0; rhsp++)
+        for (rule_number r = 0; r < nrules; r++)
+          for (item_number *rhsp = rules[r].rhs; *rhsp >= 0; rhsp++)
             if (item_number_as_symbol_number (*rhsp) == token_translations[i])
               {
                 END_TEST (65);
@@ -437,24 +425,18 @@ print_terminal_symbols (FILE *out)
 static void
 print_nonterminal_symbols (FILE *out)
 {
-  symbol_number i;
-
   fprintf (out, "%s\n\n", _("Nonterminals, with rules where they appear"));
-  for (i = ntokens; i < nsyms; i++)
+  for (symbol_number i = ntokens; i < nsyms; i++)
     {
       const char *tag = symbols[i]->tag;
       int column = strlen (tag);
       int left_count = 0, right_count = 0;
-      rule_number r;
-      char buffer[90];
-      buffer[0] = 0;
 
-      for (r = 0; r < nrules; r++)
+      for (rule_number r = 0; r < nrules; r++)
         {
-          item_number *rhsp;
           if (rules[r].lhs->number == i)
             left_count++;
-          for (rhsp = rules[r].rhs; *rhsp >= 0; rhsp++)
+          for (item_number *rhsp = rules[r].rhs; *rhsp >= 0; rhsp++)
             if (item_number_as_symbol_number (*rhsp) == i)
               {
                 right_count++;
@@ -466,6 +448,8 @@ print_nonterminal_symbols (FILE *out)
       if (symbols[i]->content->type_name)
         column += fprintf (out, " <%s>",
                            symbols[i]->content->type_name);
+      char buffer[90];
+      buffer[0] = 0;
       sprintf (buffer, " (%d)", i);
       END_TEST (0);
 
@@ -474,7 +458,7 @@ print_nonterminal_symbols (FILE *out)
           END_TEST (65);
           sprintf (buffer + strlen (buffer), _(" on left:"));
 
-          for (r = 0; r < nrules; r++)
+          for (rule_number r = 0; r < nrules; r++)
             {
               if (rules[r].lhs->number == i)
                 {
@@ -490,7 +474,7 @@ print_nonterminal_symbols (FILE *out)
             sprintf (buffer + strlen (buffer), ",");
           END_TEST (65);
           sprintf (buffer + strlen (buffer), _(" on right:"));
-          for (r = 0; r < nrules; r++)
+          for (rule_number r = 0; r < nrules; r++)
             {
               item_number *rhsp;
               for (rhsp = rules[r].rhs; *rhsp >= 0; rhsp++)
@@ -528,12 +512,9 @@ print_results (void)
   if (report_flag & report_itemsets)
     new_closure (nritems);
   /* Storage for print_reductions.  */
-  no_reduce_set =  bitset_create (ntokens, BITSET_FIXED);
-  {
-    state_number i;
-    for (i = 0; i < nstates; i++)
-      print_state (out, states[i]);
-  }
+  no_reduce_set = bitset_create (ntokens, BITSET_FIXED);
+  for (state_number i = 0; i < nstates; i++)
+    print_state (out, states[i]);
   bitset_free (no_reduce_set);
   if (report_flag & report_itemsets)
     free_closure ();
