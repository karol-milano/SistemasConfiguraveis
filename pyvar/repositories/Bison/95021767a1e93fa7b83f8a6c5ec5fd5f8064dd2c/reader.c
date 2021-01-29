@@ -253,7 +253,7 @@ grammar_current_rule_begin (symbol *lhs, location loc)
 static bool
 symbol_should_be_used (symbol_list const *s)
 {
-  if (symbol_destructor_get (s->content.sym))
+  if (symbol_destructor_get (s->content.sym)->code)
     return true;
   if (warnings_flag & warnings_midrule_values)
     return ((s->midrule && s->midrule->action_props.is_value_used)
