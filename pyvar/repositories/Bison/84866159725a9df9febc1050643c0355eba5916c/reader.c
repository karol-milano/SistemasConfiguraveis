@@ -210,6 +210,20 @@ grammar_current_rule_begin (symbol *lhs, location loc)
 }
 
 
+/*-----------------------------------------------------------------.
+| A symbol is typed if it has a declared %type, or if it is a      |
+| mid-rule symbol (i.e., the generated LHS replacing a mid-rule    |
+| action) that was assigned to, as in `exp: { $$ = 1; } { $$ = $1; |
+| }'.                                                              |
+`-----------------------------------------------------------------*/
+
+static bool
+symbol_typed_p (const symbol_list *s)
+{
+  return (s->sym->type_name
+	  || s->mid_rule && s->mid_rule->used);
+}
+
 /*----------------------------------------------------------------.
 | Check that the rule R is properly defined.  For instance, there |
 | should be no type clash on the default action.                  |
@@ -251,7 +265,7 @@ grammar_rule_check (const symbol_list *r)
     int n = 0;
     for (; l && l->sym; l = l->next, ++n)
       if (! (l->used
-	     || !l->sym->type_name
+	     || !symbol_typed_p (l)
 	     /* The default action, $$ = $1, `uses' both.  */
 	     || (!r->action && (n == 0 || n == 1))))
 	{
@@ -318,14 +332,16 @@ grammar_midrule_action (void)
     grammar = midrule;
 
   /* End the dummy's rule.  */
-  previous_rule_end = symbol_list_new (NULL, dummy_location);
-  previous_rule_end->next = current_rule;
+  midrule->next = symbol_list_new (NULL, dummy_location);
+  grammar_rule_check (midrule);
+  midrule->next->next = current_rule;
 
-  midrule->next = previous_rule_end;
+  previous_rule_end = midrule->next;
 
   /* Insert the dummy nonterminal replacing the midrule action into
-     the current rule.  */
+     the current rule.  Bind it to its dedicated rule.  */
   grammar_current_rule_symbol_append (dummy, dummy_location);
+  grammar_end->mid_rule = midrule;
 }
 
 /* Set the precedence symbol of the current rule to PRECSYM. */
