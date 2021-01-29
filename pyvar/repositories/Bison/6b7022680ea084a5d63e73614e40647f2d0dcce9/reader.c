@@ -300,7 +300,7 @@ grammar_current_rule_end (location loc)
 | rule.                                                              |
 `-------------------------------------------------------------------*/
 
-static void
+void
 grammar_midrule_action (void)
 {
   /* Since the action was written out with this rule's number, we must
@@ -394,14 +394,13 @@ grammar_current_rule_symbol_append (symbol *sym, location loc)
   grammar_symbol_append (sym, loc);
 }
 
-/* Attach an ACTION to the current rule.  If needed, move the previous
-   action as a mid-rule action.  */
+/* Attach an ACTION to the current rule.  */
 
 void
 grammar_current_rule_action_append (const char *action, location loc)
 {
-  if (current_rule->action)
-    grammar_midrule_action ();
+  /* There's no need to invoke grammar_midrule_action here, since the
+     scanner already did it if necessary.  */
   current_rule->action = action;
   current_rule->action_location = loc;
 }
