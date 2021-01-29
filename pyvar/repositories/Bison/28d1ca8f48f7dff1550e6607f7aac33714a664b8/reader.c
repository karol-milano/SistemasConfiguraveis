@@ -232,12 +232,8 @@ grammar_current_rule_begin (symbol *lhs, location loc,
     assign_named_ref (current_rule, named_ref_copy (lhs_name));
 
   /* Mark the rule's lhs as a nonterminal if not already so.  */
-  if (lhs->content->class == unknown_sym)
-    {
-      lhs->content->class = nterm_sym;
-      lhs->content->number = nvars;
-      ++nvars;
-    }
+  if (lhs->content->class == unknown_sym || lhs->content->class == pct_type_sym)
+    symbol_class_set (lhs, nterm_sym, empty_loc, false);
   else if (lhs->content->class == token_sym)
     complain (&loc, complaint, _("rule given for %s, which is a token"),
               lhs->tag);
