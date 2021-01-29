@@ -321,7 +321,7 @@ grammar_rule_check (const symbol_list *r)
         bool midrule_warning = false;
         if (!l->action_props.is_value_used
             && symbol_should_be_used (l, &midrule_warning)
-            /* The default action, $$ = $1, `uses' both.  */
+            /* The default action, $$ = $1, 'uses' both.  */
             && (r->action_props.code || (n != 0 && n != 1)))
           {
             warnings warn_flag = midrule_warning ? Wmidrule_values : Wother;
@@ -562,7 +562,7 @@ packgram (void)
       rules[ruleno].action_location = p->action_props.location;
       rules[ruleno].is_predicate = p->action_props.is_predicate;
 
-      /* If the midrule's $$ is set or its $n is used, remove the `$' from the
+      /* If the midrule's $$ is set or its $n is used, remove the '$' from the
          symbol name so that it's a user-defined symbol so that the default
          %destructor and %printer apply.  */
       if (p->midrule_parent_rule
@@ -764,11 +764,11 @@ check_and_convert_grammar (void)
      action type checking.
 
      Before invoking grammar_rule_check (in packgram below) on any rule, make
-     sure all actions have already been scanned in order to set `used' flags.
+     sure all actions have already been scanned in order to set 'used' flags.
      Otherwise, checking that a midrule's $$ should be set will not always work
      properly because the check must forward-reference the midrule's parent
-     rule.  For the same reason, all the `used' flags must be set before
-     checking whether to remove `$' from any midrule symbol name (also in
+     rule.  For the same reason, all the 'used' flags must be set before
+     checking whether to remove '$' from any midrule symbol name (also in
      packgram).  */
   {
     symbol_list *sym;
