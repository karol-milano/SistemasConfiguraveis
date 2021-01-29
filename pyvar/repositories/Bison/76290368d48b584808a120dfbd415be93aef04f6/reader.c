@@ -253,13 +253,21 @@ grammar_current_rule_begin (symbol *lhs, location loc)
 static bool
 symbol_should_be_used (symbol_list const *s)
 {
-  if (symbol_destructor_get (s->content.sym))
+  if (code_props_code_get (symbol_destructor_get (s->content.sym)))
     return true;
   if (warnings_flag & warnings_midrule_values)
-    return ((s->midrule && s->midrule->used)
-	    || (s->midrule_parent_rule
-		&& symbol_list_n_get (s->midrule_parent_rule,
-				      s->midrule_parent_rhs_index)->used));
+    {
+      if (s->midrule && code_props_is_value_used (s->midrule->action_props))
+        return true;
+      if (s->midrule_parent_rule)
+        {
+          symbol_list *rhs_node =
+            symbol_list_n_get (s->midrule_parent_rule,
+                               s->midrule_parent_rhs_index);
+          if (code_props_is_value_used (rhs_node->action_props))
+            return true;
+        }
+    }
   return false;
 }
 
@@ -278,7 +286,7 @@ grammar_rule_check (const symbol_list *r)
 
      Don't worry about the default action if $$ is untyped, since $$'s
      value can't be used.  */
-  if (!r->action && r->content.sym->type_name)
+  if (!code_props_code_get (r->action_props) && r->content.sym->type_name)
     {
       symbol *first_rhs = r->next->content.sym;
       /* If $$ is being set in default way, report if any type mismatch.  */
@@ -303,10 +311,11 @@ grammar_rule_check (const symbol_list *r)
     symbol_list const *l = r;
     int n = 0;
     for (; l && l->content.sym; l = l->next, ++n)
-      if (! (l->used
+      if (! (code_props_is_value_used (l->action_props)
 	     || !symbol_should_be_used (l)
 	     /* The default action, $$ = $1, `uses' both.  */
-	     || (!r->action && (n == 0 || n == 1))))
+	     || (!code_props_code_get (r->action_props)
+                 && (n == 0 || n == 1))))
 	{
 	  if (n)
 	    warn_at (r->location, _("unused value: $%d"), n);
@@ -346,7 +355,8 @@ grammar_midrule_action (void)
 
   /* Make a DUMMY nonterminal, whose location is that of the midrule
      action.  Create the MIDRULE.  */
-  location dummy_location = current_rule->action_location;
+  location dummy_location =
+    code_props_location_get (current_rule->action_props);
   symbol *dummy = dummy_symbol_get (dummy_location);
   symbol_list *midrule = symbol_list_sym_new (dummy, dummy_location);
 
@@ -356,12 +366,12 @@ grammar_midrule_action (void)
   ++nritems;
   /* Attach its location and actions to that of the DUMMY.  */
   midrule->location = dummy_location;
-  midrule->action = current_rule->action;
-  midrule->action_location = dummy_location;
-  current_rule->action = NULL;
-  /* The action has not been translated yet, so $$ use hasn't been
-     detected yet.  */
-  midrule->used = false;
+  code_props_rule_action_init (
+    &midrule->action_props,
+    code_props_code_get (current_rule->action_props),
+    code_props_location_get (current_rule->action_props),
+    midrule);
+  code_props_none_init (&current_rule->action_props);
 
   if (previous_rule_end)
     previous_rule_end->next = midrule;
@@ -426,7 +436,7 @@ grammar_current_rule_merge_set (uniqstr name, location loc)
 void
 grammar_current_rule_symbol_append (symbol *sym, location loc)
 {
-  if (current_rule->action)
+  if (code_props_code_get (current_rule->action_props))
     grammar_midrule_action ();
   grammar_symbol_append (sym, loc);
 }
@@ -436,12 +446,12 @@ grammar_current_rule_symbol_append (symbol *sym, location loc)
 void
 grammar_current_rule_action_append (const char *action, location loc)
 {
-  if (current_rule->action)
+  if (code_props_code_get (current_rule->action_props))
     grammar_midrule_action ();
   /* After all symbol declarations have been parsed, packgram invokes
-     translate_rule_action.  */
-  current_rule->action = action;
-  current_rule->action_location = loc;
+     code_props_translate_code.  */
+  code_props_rule_action_init (&current_rule->action_props, action, loc,
+                               current_rule);
 }
 
 
@@ -472,8 +482,7 @@ packgram (void)
      `$' from any midrule symbol name.  */
   while (p)
     {
-      if (p->action)
-        p->action = translate_rule_action (p);
+      code_props_translate_code (&p->action_props);
       if (p)
 	p = p->next;
     }
@@ -495,16 +504,20 @@ packgram (void)
       rules[ruleno].precsym = NULL;
       rules[ruleno].location = p->location;
       rules[ruleno].useful = true;
-      rules[ruleno].action = p->action;
-      rules[ruleno].action_location = p->action_location;
+      rules[ruleno].action = code_props_code_get (p->action_props);
+      if (rules[ruleno].action)
+        rules[ruleno].action_location =
+          code_props_location_get (p->action_props);
 
       /* If the midrule's $$ is set or its $n is used, remove the `$' from the
 	 symbol name so that it's a user-defined symbol so that the default
 	 %destructor and %printer apply.  */
       if (p->midrule_parent_rule
-          && (p->used
-	      || symbol_list_n_get (p->midrule_parent_rule,
-				    p->midrule_parent_rhs_index)->used))
+          && (code_props_is_value_used (p->action_props)
+	      || code_props_is_value_used (
+		   symbol_list_n_get (
+		     p->midrule_parent_rule,
+		     p->midrule_parent_rhs_index)->action_props)))
 	p->content.sym->tag += 1;
 
       /* Don't check the generated rule 0.  It has no action, so some rhs
