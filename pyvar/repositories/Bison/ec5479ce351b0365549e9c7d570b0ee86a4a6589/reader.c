@@ -259,7 +259,7 @@ grammar_current_rule_begin (symbol *lhs, location loc)
 static bool
 symbol_should_be_used (symbol_list const *s)
 {
-  return (s->sym->destructor
+  return (symbol_destructor_get (s->sym)
 	  || (s->midrule && s->midrule->used));
 }
 
