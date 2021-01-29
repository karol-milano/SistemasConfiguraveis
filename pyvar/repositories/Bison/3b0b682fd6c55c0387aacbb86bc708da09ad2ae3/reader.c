@@ -470,6 +470,8 @@ grammar_current_rule_symbol_append (symbol *sym, location loc,
   p = grammar_symbol_append (sym, loc);
   if (name)
     assign_named_ref(p, name);
+  if (sym->status == undeclared || sym->status == used)
+    sym->status = needed;
 }
 
 /* Attach an ACTION to the current rule.  */
