@@ -403,6 +403,8 @@ grammar_current_rule_symbol_append (symbol *sym, location loc)
 void
 grammar_current_rule_action_append (const char *action, location loc)
 {
+  if (current_rule->action)
+    grammar_midrule_action ();
   current_rule->action = translate_rule_action (current_rule, action, loc);
   current_rule->action_location = loc;
 }
