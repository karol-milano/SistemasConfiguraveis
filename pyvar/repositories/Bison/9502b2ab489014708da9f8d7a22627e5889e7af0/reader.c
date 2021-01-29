@@ -522,18 +522,27 @@ grammar_current_rule_symbol_append (symbol *sym, location loc,
     sym->content->status = needed;
 }
 
-/* Attach an ACTION to the current rule.  */
-
 void
 grammar_current_rule_action_append (const char *action, location loc,
-                                    named_ref *name, bool is_predicate)
+                                    named_ref *name)
 {
   if (current_rule->action_props.code)
     grammar_midrule_action ();
   /* After all symbol declarations have been parsed, packgram invokes
      code_props_translate_code.  */
   code_props_rule_action_init (&current_rule->action_props, action, loc,
-                               current_rule, name, is_predicate);
+                               current_rule, name,
+                               /* is_predicate */ false);
+}
+
+void
+grammar_current_rule_predicate_append (const char *pred, location loc)
+{
+  if (current_rule->action_props.code)
+    grammar_midrule_action ();
+  code_props_rule_action_init (&current_rule->action_props, pred, loc,
+                               current_rule, NULL,
+                               /* is_predicate */ true);
 }
 
 
