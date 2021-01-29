@@ -226,11 +226,9 @@ grammar_current_rule_begin (symbol *lhs, location loc,
   ++nrules;
   previous_rule_end = grammar_end;
 
-  symbol_list *p = grammar_symbol_append (lhs, loc);
+  current_rule = grammar_symbol_append (lhs, loc);
   if (lhs_name)
-    assign_named_ref (p, named_ref_copy (lhs_name));
-
-  current_rule = grammar_end;
+    assign_named_ref (current_rule, named_ref_copy (lhs_name));
 
   /* Mark the rule's lhs as a nonterminal if not already so.  */
   if (lhs->content->class == unknown_sym)
@@ -293,7 +291,7 @@ grammar_rule_check_and_complete (symbol_list *r)
       if (first_rhs)
         {
           char const *lhs_type = r->content.sym->content->type_name;
-          const char *rhs_type =
+          char const *rhs_type =
             first_rhs->content->type_name ? first_rhs->content->type_name : "";
           if (!UNIQSTR_EQ (lhs_type, rhs_type))
             complain (&r->location, Wother,
@@ -629,8 +627,8 @@ packgram (void)
       /* Don't check the generated rule 0.  It has no action, so some rhs
          symbols may appear unused, but the parsing algorithm ensures that
          %destructor's are invoked appropriately.  */
-      if (p != grammar)
-        grammar_rule_check_and_complete (p);
+      if (lhs != grammar)
+        grammar_rule_check_and_complete (lhs);
 
       rules[ruleno].user_number = ruleno;
       rules[ruleno].number = ruleno;
@@ -645,13 +643,13 @@ packgram (void)
       rules[ruleno].action = lhs->action_props.code;
       rules[ruleno].action_location = lhs->action_props.location;
       rules[ruleno].is_predicate = lhs->action_props.is_predicate;
-      rules[ruleno].expected_sr_conflicts = p->expected_sr_conflicts;
-      rules[ruleno].expected_rr_conflicts = p->expected_rr_conflicts;
+      rules[ruleno].expected_sr_conflicts = lhs->expected_sr_conflicts;
+      rules[ruleno].expected_rr_conflicts = lhs->expected_rr_conflicts;
 
       /* Traverse the rhs.  */
       {
         size_t rule_length = 0;
-        for (p = p->next; p->content.sym; p = p->next)
+        for (p = lhs->next; p->content.sym; p = p->next)
           {
             ++rule_length;
 
