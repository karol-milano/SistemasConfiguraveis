@@ -257,7 +257,7 @@ grammar_current_rule_begin (symbol *lhs, location loc,
 static bool
 symbol_should_be_used (symbol_list const *s, bool *midrule_warning)
 {
-  if (symbol_destructor_get (s->content.sym)->code)
+  if (symbol_code_props_get (s->content.sym, destructor)->code)
     return true;
   if ((s->midrule && s->midrule->action_props.is_value_used)
       || (s->midrule_parent_rule
