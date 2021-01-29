@@ -528,6 +528,9 @@ grammar_current_rule_action_append (const char *action, location loc,
 {
   if (current_rule->action_props.code)
     grammar_midrule_action ();
+  if (type)
+    complain (&loc, Wyacc,
+              _("POSIX Yacc does not support typed midrule actions"));
   /* After all symbol declarations have been parsed, packgram invokes
      code_props_translate_code.  */
   code_props_rule_action_init (&current_rule->action_props, action, loc,
