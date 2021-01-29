@@ -266,6 +266,7 @@ symbol_should_be_used (symbol_list const *s, bool *midrule_warning)
 static void
 grammar_rule_check_and_complete (symbol_list *r)
 {
+  const symbol *lhs = r->content.sym;
   /* Type check.
 
      If there is an action, then there is nothing we can do: the user
@@ -273,13 +274,13 @@ grammar_rule_check_and_complete (symbol_list *r)
 
      Don't worry about the default action if $$ is untyped, since $$'s
      value can't be used.  */
-  if (!r->action_props.code && r->content.sym->content->type_name)
+  if (!r->action_props.code && lhs->content->type_name)
     {
       symbol *first_rhs = r->next->content.sym;
       /* If $$ is being set in default way, report if any type mismatch.  */
       if (first_rhs)
         {
-          char const *lhs_type = r->content.sym->content->type_name;
+          char const *lhs_type = lhs->content->type_name;
           char const *rhs_type =
             first_rhs->content->type_name ? first_rhs->content->type_name : "";
           if (!UNIQSTR_EQ (lhs_type, rhs_type))
@@ -311,25 +312,29 @@ grammar_rule_check_and_complete (symbol_list *r)
                   _("empty rule for typed nonterminal, and no action"));
     }
 
-  /* Check that symbol values that should be used are in fact used.  */
-  {
-    int n = 0;
-    for (symbol_list const *l = r; l && l->content.sym; l = l->next, ++n)
-      {
-        bool midrule_warning = false;
-        if (!l->action_props.is_value_used
-            && symbol_should_be_used (l, &midrule_warning)
-            /* The default action, $$ = $1, 'uses' both.  */
-            && (r->action_props.code || (n != 0 && n != 1)))
-          {
-            warnings warn_flag = midrule_warning ? Wmidrule_values : Wother;
-            if (n)
-              complain (&l->sym_loc, warn_flag, _("unused value: $%d"), n);
-            else
-              complain (&l->rhs_loc, warn_flag, _("unset value: $$"));
-          }
-      }
-  }
+  /* Check that symbol values that should be used are in fact used.
+     Don't check the generated start rules.  It has no action, so some
+     rhs symbols may appear unused, but the parsing algorithm ensures
+     that %destructor's are invoked appropriately.  */
+  if (lhs != acceptsymbol)
+    {
+      int n = 0;
+      for (symbol_list const *l = r; l && l->content.sym; l = l->next, ++n)
+        {
+          bool midrule_warning = false;
+          if (!l->action_props.is_value_used
+              && symbol_should_be_used (l, &midrule_warning)
+              /* The default action, $$ = $1, 'uses' both.  */
+              && (r->action_props.code || (n != 0 && n != 1)))
+            {
+              warnings warn_flag = midrule_warning ? Wmidrule_values : Wother;
+              if (n)
+                complain (&l->sym_loc, warn_flag, _("unused value: $%d"), n);
+              else
+                complain (&l->rhs_loc, warn_flag, _("unset value: $$"));
+            }
+        }
+    }
 
   /* Check that %empty => empty rule.  */
   if (r->percent_empty_loc.start.file
@@ -624,11 +629,7 @@ packgram (void)
                   ->action_props.is_value_used)))
         lhs->content.sym->tag += 1;
 
-      /* Don't check the generated rule 0.  It has no action, so some rhs
-         symbols may appear unused, but the parsing algorithm ensures that
-         %destructor's are invoked appropriately.  */
-      if (lhs != grammar)
-        grammar_rule_check_and_complete (lhs);
+      grammar_rule_check_and_complete (lhs);
 
       rules[ruleno].code = ruleno;
       rules[ruleno].number = ruleno;
