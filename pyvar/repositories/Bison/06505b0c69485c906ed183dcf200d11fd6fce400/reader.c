@@ -267,9 +267,9 @@ symbol_should_be_used (symbol_list const *s, bool *midrule_warning)
     return true;
   if ((s->midrule && s->midrule->action_props.is_value_used)
       || (s->midrule_parent_rule
-          && symbol_list_n_get (s->midrule_parent_rule,
-                                s->midrule_parent_rhs_index)
-               ->action_props.is_value_used))
+          && (symbol_list_n_get (s->midrule_parent_rule,
+                                 s->midrule_parent_rhs_index)
+              ->action_props.is_value_used)))
     {
       *midrule_warning = true;
       return true;
@@ -507,7 +507,7 @@ packgram (void)
 {
   unsigned int itemno = 0;
   rule_number ruleno = 0;
-  symbol_list *p = grammar;
+  symbol_list *p;
 
   ritem = xnmalloc (nritems + 1, sizeof *ritem);
 
@@ -516,9 +516,8 @@ packgram (void)
 
   rules = xnmalloc (nrules, sizeof *rules);
 
-  while (p)
+  for (p = grammar; p; p = p->next)
     {
-      int rule_length = 0;
       symbol *ruleprec = p->ruleprec;
       record_merge_function_type (p->merger, p->content.sym->type_name,
                                   p->merger_declaration_location);
@@ -541,9 +540,9 @@ packgram (void)
          %destructor and %printer apply.  */
       if (p->midrule_parent_rule
           && (p->action_props.is_value_used
-              || symbol_list_n_get (p->midrule_parent_rule,
-                                    p->midrule_parent_rhs_index)
-                   ->action_props.is_value_used))
+              || (symbol_list_n_get (p->midrule_parent_rule,
+                                     p->midrule_parent_rhs_index)
+                  ->action_props.is_value_used)))
         p->content.sym->tag += 1;
 
       /* Don't check the generated rule 0.  It has no action, so some rhs
@@ -552,24 +551,27 @@ packgram (void)
       if (p != grammar)
         grammar_rule_check (p);
 
-      for (p = p->next; p && p->content.sym; p = p->next)
-        {
-          ++rule_length;
-
-          /* Don't allow rule_length == INT_MAX, since that might
-             cause confusion with strtol if INT_MAX == LONG_MAX.  */
-          if (rule_length == INT_MAX)
-            complain (&rules[ruleno].location, fatal, _("rule is too long"));
-
-          /* item_number = symbol_number.
-             But the former needs to contain more: negative rule numbers. */
-          ritem[itemno++] =
-            symbol_number_as_item_number (p->content.sym->number);
-          /* A rule gets by default the precedence and associativity
-             of its last token.  */
-          if (p->content.sym->class == token_sym && default_prec)
-            rules[ruleno].prec = p->content.sym;
-        }
+      {
+        size_t rule_length = 0;
+        for (p = p->next; p->content.sym; p = p->next)
+          {
+            ++rule_length;
+
+            /* Don't allow rule_length == INT_MAX, since that might
+               cause confusion with strtol if INT_MAX == LONG_MAX.  */
+            if (rule_length == INT_MAX)
+              complain (&rules[ruleno].location, fatal, _("rule is too long"));
+
+            /* item_number = symbol_number.
+               But the former needs to contain more: negative rule numbers. */
+            ritem[itemno++] =
+              symbol_number_as_item_number (p->content.sym->number);
+            /* A rule gets by default the precedence and associativity
+               of its last token.  */
+            if (p->content.sym->class == token_sym && default_prec)
+              rules[ruleno].prec = p->content.sym;
+          }
+      }
 
       /* If this rule has a %prec,
          the specified symbol's precedence replaces the default.  */
@@ -583,9 +585,6 @@ packgram (void)
       aver (itemno < ITEM_NUMBER_MAX);
       ++ruleno;
       aver (ruleno < RULE_NUMBER_MAX);
-
-      if (p)
-        p = p->next;
     }
 
   aver (itemno == nritems);
