@@ -72,7 +72,7 @@ print_core (FILE *out, state *s)
   size_t i;
   item_number *sitems = s->items;
   size_t snritems = s->nitems;
-  symbol *previous_lhs = NULL;
+  sym_content *previous_lhs = NULL;
 
   /* Output all the items of a state, not only its kernel.  */
   if (report_flag & report_itemsets)
@@ -223,7 +223,8 @@ print_reduction (FILE *out, size_t width,
   if (!enabled)
     fputc ('[', out);
   if (r->number)
-    fprintf (out, _("reduce using rule %d (%s)"), r->number, r->lhs->tag);
+    fprintf (out, _("reduce using rule %d (%s)"), r->number,
+             r->lhs->symbol->tag);
   else
     fprintf (out, _("accept"));
   if (!enabled)
@@ -257,7 +258,7 @@ print_reductions (FILE *out, state *s)
     bitset_set (no_reduce_set, TRANSITION_SYMBOL (trans, i));
   for (i = 0; i < s->errs->num; ++i)
     if (s->errs->symbols[i])
-      bitset_set (no_reduce_set, s->errs->symbols[i]->number);
+      bitset_set (no_reduce_set, s->errs->symbols[i]->content->number);
 
   /* Compute the width of the lookahead token column.  */
   if (default_reduction)
@@ -408,7 +409,7 @@ print_grammar (FILE *out)
   /* TERMINAL (type #) : rule #s terminal is on RHS */
   fprintf (out, "%s\n\n", _("Terminals, with rules where they appear"));
   for (i = 0; i < max_user_token_number + 1; i++)
-    if (token_translations[i] != undeftoken->number)
+    if (token_translations[i] != undeftoken->content->number)
       {
         const char *tag = symbols[token_translations[i]]->tag;
         rule_number r;
