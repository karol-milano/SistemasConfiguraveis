@@ -78,13 +78,13 @@ grammar_start_symbol_set (symbol *sym, location loc)
 static int
 get_merge_function (uniqstr name)
 {
+  if (! glr_parser)
+    return 0;
+
   merger_list *syms;
   merger_list head;
   int n;
 
-  if (! glr_parser)
-    return 0;
-
   head.next = merge_functions;
   for (syms = &head, n = 1; syms->next; syms = syms->next, n += 1)
     if (UNIQSTR_EQ (name, syms->next->name))
@@ -111,12 +111,12 @@ get_merge_function (uniqstr name)
 static void
 record_merge_function_type (int merger, uniqstr type, location declaration_loc)
 {
-  int merger_find;
-  merger_list *merge_function;
-
   if (merger <= 0)
     return;
 
+  int merger_find;
+  merger_list *merge_function;
+
   if (type == NULL)
     type = uniqstr_new ("");
 
@@ -227,13 +227,11 @@ void
 grammar_current_rule_begin (symbol *lhs, location loc,
                             named_ref *lhs_name)
 {
-  symbol_list* p;
-
   /* Start a new rule and record its lhs.  */
   ++nrules;
   previous_rule_end = grammar_end;
 
-  p = grammar_symbol_append (lhs, loc);
+  symbol_list *p = grammar_symbol_append (lhs, loc);
   if (lhs_name)
     assign_named_ref (p, named_ref_copy (lhs_name));
 
@@ -314,9 +312,8 @@ grammar_rule_check (const symbol_list *r)
 
   /* Check that symbol values that should be used are in fact used.  */
   {
-    symbol_list const *l = r;
     int n = 0;
-    for (; l && l->content.sym; l = l->next, ++n)
+    for (symbol_list const *l = r; l && l->content.sym; l = l->next, ++n)
       {
         bool midrule_warning = false;
         if (!l->action_props.is_value_used
@@ -512,10 +509,9 @@ void
 grammar_current_rule_symbol_append (symbol *sym, location loc,
                                     named_ref *name)
 {
-  symbol_list *p;
   if (current_rule->action_props.code)
     grammar_midrule_action ();
-  p = grammar_symbol_append (sym, loc);
+  symbol_list *p = grammar_symbol_append (sym, loc);
   if (name)
     assign_named_ref (p, name);
   if (sym->content->status == undeclared || sym->content->status == used)
@@ -556,7 +552,6 @@ packgram (void)
 {
   unsigned int itemno = 0;
   rule_number ruleno = 0;
-  symbol_list *p;
 
   ritem = xnmalloc (nritems + 1, sizeof *ritem);
 
@@ -565,7 +560,7 @@ packgram (void)
 
   rules = xnmalloc (nrules, sizeof *rules);
 
-  for (p = grammar; p; p = p->next)
+  for (symbol_list *p = grammar; p; p = p->next)
     {
       symbol *ruleprec = p->ruleprec;
       record_merge_function_type (p->merger, p->content.sym->content->type_name,
@@ -751,7 +746,7 @@ check_and_convert_grammar (void)
           for (node = node->next;
                node != NULL && node->content.sym != NULL;
                node = node->next)
-            ;
+            continue;
         }
       aver (node != NULL);
       grammar_start_symbol_set (node->content.sym,
@@ -792,11 +787,8 @@ check_and_convert_grammar (void)
      rule.  For the same reason, all the 'used' flags must be set before
      checking whether to remove '$' from any midrule symbol name (also in
      packgram).  */
-  {
-    symbol_list *sym;
-    for (sym = grammar; sym; sym = sym->next)
-      code_props_translate_code (&sym->action_props);
-  }
+  for (symbol_list *sym = grammar; sym; sym = sym->next)
+    code_props_translate_code (&sym->action_props);
 
   /* Convert the grammar into the format described in gram.h.  */
   packgram ();
