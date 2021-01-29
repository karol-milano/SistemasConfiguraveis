@@ -180,7 +180,7 @@ grammar_symbol_append (symbol *sym, location loc)
 /* The rule currently being defined, and the previous rule.
    CURRENT_RULE points to the first LHS of the current rule, while
    PREVIOUS_RULE_END points to the *end* of the previous rule (NULL).  */
-symbol_list *current_rule = NULL;
+static symbol_list *current_rule = NULL;
 static symbol_list *previous_rule_end = NULL;
 
 
@@ -405,8 +405,9 @@ grammar_current_rule_action_append (const char *action, location loc)
 {
   if (current_rule->action)
     grammar_midrule_action ();
-  current_rule->action = translate_rule_action (current_rule, action, loc);
+  current_rule->action = action;
   current_rule->action_location = loc;
+  current_rule->action = translate_rule_action (current_rule);
 }
 
 
