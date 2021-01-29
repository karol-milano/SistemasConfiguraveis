@@ -576,32 +576,18 @@ packgram (void)
 
   for (symbol_list *p = grammar; p; p = p->next)
     {
-      symbol *ruleprec = p->ruleprec;
-      record_merge_function_type (p->merger, p->content.sym->content->type_name,
-                                  p->merger_declaration_location);
-      rules[ruleno].user_number = ruleno;
-      rules[ruleno].number = ruleno;
-      rules[ruleno].lhs = p->content.sym->content;
-      rules[ruleno].rhs = ritem + itemno;
-      rules[ruleno].prec = NULL;
-      rules[ruleno].dprec = p->dprec;
-      rules[ruleno].merger = p->merger;
-      rules[ruleno].precsym = NULL;
-      rules[ruleno].location = p->location;
-      rules[ruleno].useful = true;
-      rules[ruleno].action = p->action_props.code;
-      rules[ruleno].action_location = p->action_props.location;
-      rules[ruleno].is_predicate = p->action_props.is_predicate;
-
+      symbol_list *lhs = p;
+      record_merge_function_type (lhs->merger, lhs->content.sym->content->type_name,
+                                  lhs->merger_declaration_location);
       /* If the midrule's $$ is set or its $n is used, remove the '$' from the
          symbol name so that it's a user-defined symbol so that the default
          %destructor and %printer apply.  */
-      if (p->midrule_parent_rule
-          && (p->action_props.is_value_used
-              || (symbol_list_n_get (p->midrule_parent_rule,
-                                     p->midrule_parent_rhs_index)
+      if (lhs->midrule_parent_rule
+          && (lhs->action_props.is_value_used
+              || (symbol_list_n_get (lhs->midrule_parent_rule,
+                                     lhs->midrule_parent_rhs_index)
                   ->action_props.is_value_used)))
-        p->content.sym->tag += 1;
+        lhs->content.sym->tag += 1;
 
       /* Don't check the generated rule 0.  It has no action, so some rhs
          symbols may appear unused, but the parsing algorithm ensures that
@@ -609,6 +595,21 @@ packgram (void)
       if (p != grammar)
         grammar_rule_check (p);
 
+      rules[ruleno].user_number = ruleno;
+      rules[ruleno].number = ruleno;
+      rules[ruleno].lhs = lhs->content.sym->content;
+      rules[ruleno].rhs = ritem + itemno;
+      rules[ruleno].prec = NULL;
+      rules[ruleno].dprec = lhs->dprec;
+      rules[ruleno].merger = lhs->merger;
+      rules[ruleno].precsym = NULL;
+      rules[ruleno].location = lhs->location;
+      rules[ruleno].useful = true;
+      rules[ruleno].action = lhs->action_props.code;
+      rules[ruleno].action_location = lhs->action_props.location;
+      rules[ruleno].is_predicate = lhs->action_props.is_predicate;
+
+      /* Traverse the rhs.  */
       {
         size_t rule_length = 0;
         for (p = p->next; p->content.sym; p = p->next)
@@ -633,11 +634,12 @@ packgram (void)
 
       /* If this rule has a %prec,
          the specified symbol's precedence replaces the default.  */
-      if (ruleprec)
+      if (lhs->ruleprec)
         {
-          rules[ruleno].precsym = ruleprec->content;
-          rules[ruleno].prec = ruleprec->content;
+          rules[ruleno].precsym = lhs->ruleprec->content;
+          rules[ruleno].prec = lhs->ruleprec->content;
         }
+
       /* An item ends by the rule number (negated).  */
       ritem[itemno++] = rule_number_as_item_number (ruleno);
       aver (itemno < ITEM_NUMBER_MAX);
