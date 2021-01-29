@@ -377,7 +377,8 @@ grammar_midrule_action (void)
   code_props_rule_action_init (&midrule->action_props,
                                current_rule->action_props.code,
                                current_rule->action_props.location,
-                               midrule, 0);
+                               midrule, 0,
+			       current_rule->action_props.is_predicate);
   code_props_none_init (&current_rule->action_props);
 
   if (previous_rule_end)
@@ -468,14 +469,14 @@ grammar_current_rule_symbol_append (symbol *sym, location loc,
 
 void
 grammar_current_rule_action_append (const char *action, location loc,
-				    named_ref *name)
+				    named_ref *name, bool is_predicate)
 {
   if (current_rule->action_props.code)
     grammar_midrule_action ();
   /* After all symbol declarations have been parsed, packgram invokes
      code_props_translate_code.  */
   code_props_rule_action_init (&current_rule->action_props, action, loc,
-                               current_rule, name);
+                               current_rule, name, is_predicate);
 }
 
 
@@ -516,6 +517,7 @@ packgram (void)
       rules[ruleno].useful = true;
       rules[ruleno].action = p->action_props.code;
       rules[ruleno].action_location = p->action_props.location;
+      rules[ruleno].is_predicate = p->action_props.is_predicate;
 
       /* If the midrule's $$ is set or its $n is used, remove the `$' from the
 	 symbol name so that it's a user-defined symbol so that the default
