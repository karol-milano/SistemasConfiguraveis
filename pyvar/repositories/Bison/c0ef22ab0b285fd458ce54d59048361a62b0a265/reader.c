@@ -516,7 +516,7 @@ grammar_current_rule_symbol_append (symbol *sym, location loc,
     grammar_midrule_action ();
   p = grammar_symbol_append (sym, loc);
   if (name)
-    assign_named_ref(p, name);
+    assign_named_ref (p, name);
   if (sym->status == undeclared || sym->status == used)
     sym->status = needed;
 }
