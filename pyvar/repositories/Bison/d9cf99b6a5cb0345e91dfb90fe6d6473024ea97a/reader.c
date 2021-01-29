@@ -267,6 +267,8 @@ static void
 grammar_rule_check_and_complete (symbol_list *r)
 {
   const symbol *lhs = r->content.sym;
+  const symbol *first_rhs = r->next->content.sym;
+
   /* Type check.
 
      If there is an action, then there is nothing we can do: the user
@@ -276,7 +278,6 @@ grammar_rule_check_and_complete (symbol_list *r)
      value can't be used.  */
   if (!r->action_props.code && lhs->content->type_name)
     {
-      symbol *first_rhs = r->next->content.sym;
       /* If $$ is being set in default way, report if any type mismatch.  */
       if (first_rhs)
         {
@@ -312,6 +313,29 @@ grammar_rule_check_and_complete (symbol_list *r)
                   _("empty rule for typed nonterminal, and no action"));
     }
 
+  /* For each start symbol, build the action of its start rule.  Use
+     the same obstack as the one used by scan-code, which is in charge
+     of actions. */
+  const bool multistart = start_symbols && start_symbols->next;
+  if (multistart && lhs == acceptsymbol)
+    {
+      const symbol *start = r->next->next->content.sym;
+      if (start->content->type_name)
+        obstack_printf (obstack_for_actions,
+                        "{ ]b4_accept([orig %d])[; }",
+                        start->content->number);
+      else
+        obstack_printf (obstack_for_actions,
+                        "{ ]b4_accept[; }");
+      code_props_rule_action_init (&r->action_props,
+                                   obstack_finish0 (obstack_for_actions),
+                                   r->rhs_loc, r,
+                                   /* name */ NULL,
+                                   /* type */ NULL,
+                                   /* is_predicate */ false);
+    }
+
+
   /* Check that symbol values that should be used are in fact used.
      Don't check the generated start rules.  It has no action, so some
      rhs symbols may appear unused, but the parsing algorithm ensures
@@ -772,6 +796,11 @@ create_start_rule (symbol *swtok, symbol *start)
   symbol_list *p = initial_rule;
   if (swtok)
     {
+      // Cannot create the action now, as the symbols have not yet
+      // been assigned their number (by symbol_pack), which we need to
+      // know the type name.  So the action is created in
+      // grammar_rule_check_and_complete, which is run after
+      // symbol_pack.
       p->next = symbol_list_sym_new (swtok, empty_loc);
       p = p->next;
     }
