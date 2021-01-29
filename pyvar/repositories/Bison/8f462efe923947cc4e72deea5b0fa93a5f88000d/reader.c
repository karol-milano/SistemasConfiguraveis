@@ -231,7 +231,7 @@ grammar_current_rule_begin (symbol *lhs, location loc,
 
   p = grammar_symbol_append (lhs, loc);
   if (lhs_name)
-    assign_named_ref(p, lhs_name);
+    assign_named_ref (p, named_ref_copy (lhs_name));
 
   current_rule = grammar_end;
 
