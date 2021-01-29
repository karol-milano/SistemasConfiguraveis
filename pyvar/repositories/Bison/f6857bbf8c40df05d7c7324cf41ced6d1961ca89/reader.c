@@ -1,7 +1,7 @@
 /* Input parser for Bison
 
    Copyright (C) 1984, 1986, 1989, 1992, 1998, 2000, 2001, 2002, 2003,
-   2005, 2006 Free Software Foundation, Inc.
+   2005, 2006, 2007 Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -256,10 +256,11 @@ symbol_should_be_used (symbol_list const *s)
   if (symbol_destructor_get (s->content.sym))
     return true;
   if (warnings_flag & warnings_midrule_values)
-    return ((s->midrule && s->midrule->used)
+    return ((s->midrule && s->midrule->action_props.is_value_used)
 	    || (s->midrule_parent_rule
 		&& symbol_list_n_get (s->midrule_parent_rule,
-				      s->midrule_parent_rhs_index)->used));
+				      s->midrule_parent_rhs_index)
+                     ->action_props.is_value_used));
   return false;
 }
 
@@ -278,7 +279,7 @@ grammar_rule_check (const symbol_list *r)
 
      Don't worry about the default action if $$ is untyped, since $$'s
      value can't be used.  */
-  if (!r->action && r->content.sym->type_name)
+  if (!r->action_props.code && r->content.sym->type_name)
     {
       symbol *first_rhs = r->next->content.sym;
       /* If $$ is being set in default way, report if any type mismatch.  */
@@ -303,10 +304,10 @@ grammar_rule_check (const symbol_list *r)
     symbol_list const *l = r;
     int n = 0;
     for (; l && l->content.sym; l = l->next, ++n)
-      if (! (l->used
+      if (! (l->action_props.is_value_used
 	     || !symbol_should_be_used (l)
 	     /* The default action, $$ = $1, `uses' both.  */
-	     || (!r->action && (n == 0 || n == 1))))
+	     || (!r->action_props.code && (n == 0 || n == 1))))
 	{
 	  if (n)
 	    warn_at (r->location, _("unused value: $%d"), n);
@@ -346,7 +347,7 @@ grammar_midrule_action (void)
 
   /* Make a DUMMY nonterminal, whose location is that of the midrule
      action.  Create the MIDRULE.  */
-  location dummy_location = current_rule->action_location;
+  location dummy_location = current_rule->action_props.location;
   symbol *dummy = dummy_symbol_get (dummy_location);
   symbol_list *midrule = symbol_list_sym_new (dummy, dummy_location);
 
@@ -356,12 +357,11 @@ grammar_midrule_action (void)
   ++nritems;
   /* Attach its location and actions to that of the DUMMY.  */
   midrule->location = dummy_location;
-  midrule->action = current_rule->action;
-  midrule->action_location = dummy_location;
-  current_rule->action = NULL;
-  /* The action has not been translated yet, so $$ use hasn't been
-     detected yet.  */
-  midrule->used = false;
+  code_props_rule_action_init (&midrule->action_props,
+                               current_rule->action_props.code,
+                               current_rule->action_props.location,
+                               midrule);
+  code_props_none_init (&current_rule->action_props);
 
   if (previous_rule_end)
     previous_rule_end->next = midrule;
@@ -427,7 +427,7 @@ grammar_current_rule_merge_set (uniqstr name, location loc)
 void
 grammar_current_rule_symbol_append (symbol *sym, location loc)
 {
-  if (current_rule->action)
+  if (current_rule->action_props.code)
     grammar_midrule_action ();
   grammar_symbol_append (sym, loc);
 }
@@ -437,12 +437,12 @@ grammar_current_rule_symbol_append (symbol *sym, location loc)
 void
 grammar_current_rule_action_append (const char *action, location loc)
 {
-  if (current_rule->action)
+  if (current_rule->action_props.code)
     grammar_midrule_action ();
   /* After all symbol declarations have been parsed, packgram invokes
-     translate_rule_action.  */
-  current_rule->action = action;
-  current_rule->action_location = loc;
+     code_props_translate_code.  */
+  code_props_rule_action_init (&current_rule->action_props, action, loc,
+                               current_rule);
 }
 
 
@@ -473,8 +473,7 @@ packgram (void)
      `$' from any midrule symbol name.  */
   while (p)
     {
-      if (p->action)
-        p->action = translate_rule_action (p);
+      code_props_translate_code (&p->action_props);
       if (p)
 	p = p->next;
     }
@@ -496,16 +495,17 @@ packgram (void)
       rules[ruleno].precsym = NULL;
       rules[ruleno].location = p->location;
       rules[ruleno].useful = true;
-      rules[ruleno].action = p->action;
-      rules[ruleno].action_location = p->action_location;
+      rules[ruleno].action = p->action_props.code;
+      rules[ruleno].action_location = p->action_props.location;
 
       /* If the midrule's $$ is set or its $n is used, remove the `$' from the
 	 symbol name so that it's a user-defined symbol so that the default
 	 %destructor and %printer apply.  */
       if (p->midrule_parent_rule
-          && (p->used
+          && (p->action_props.is_value_used
 	      || symbol_list_n_get (p->midrule_parent_rule,
-				    p->midrule_parent_rhs_index)->used))
+				    p->midrule_parent_rhs_index)
+                   ->action_props.is_value_used))
 	p->content.sym->tag += 1;
 
       /* Don't check the generated rule 0.  It has no action, so some rhs
