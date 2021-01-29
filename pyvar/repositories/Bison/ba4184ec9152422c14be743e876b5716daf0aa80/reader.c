@@ -191,19 +191,19 @@ grammar_symbol_append (symbol *sym, location loc)
 }
 
 static void
-assign_named_ref (symbol_list *p, named_ref *named_ref)
+assign_named_ref (symbol_list *p, named_ref *name)
 {
   symbol *sym = p->content.sym;
 
-  if (named_ref->id == sym->tag)
+  if (name->id == sym->tag)
     {
-      warn_at (named_ref->loc,
+      warn_at (name->loc,
 	       _("duplicated symbol name for %s ignored"),
 	       quote (sym->tag));
-      named_ref_free (named_ref);
+      named_ref_free (name);
     }
   else
-    p->named_ref = named_ref;
+    p->named_ref = name;
 }
 
 
@@ -220,7 +220,7 @@ static symbol_list *previous_rule_end = NULL;
 
 void
 grammar_current_rule_begin (symbol *lhs, location loc,
-			    named_ref *lhs_named_ref)
+			    named_ref *lhs_name)
 {
   symbol_list* p;
 
@@ -229,8 +229,8 @@ grammar_current_rule_begin (symbol *lhs, location loc,
   previous_rule_end = grammar_end;
 
   p = grammar_symbol_append (lhs, loc);
-  if (lhs_named_ref)
-    assign_named_ref(p, lhs_named_ref);
+  if (lhs_name)
+    assign_named_ref(p, lhs_name);
 
   current_rule = grammar_end;
 
@@ -356,7 +356,7 @@ grammar_midrule_action (void)
   symbol_list *midrule = symbol_list_sym_new (dummy, dummy_location);
 
   /* Remember named_ref of previous action. */
-  named_ref *named_ref = current_rule->action_props.named_ref;
+  named_ref *action_name = current_rule->action_props.named_ref;
 
   /* Make a new rule, whose body is empty, before the current one, so
      that the action just read can belong to it.  */
@@ -383,7 +383,8 @@ grammar_midrule_action (void)
 
   /* Insert the dummy nonterminal replacing the midrule action into
      the current rule.  Bind it to its dedicated rule.  */
-  grammar_current_rule_symbol_append (dummy, dummy_location, named_ref);
+  grammar_current_rule_symbol_append (dummy, dummy_location,
+                                      action_name);
   grammar_end->midrule = midrule;
   midrule->midrule_parent_rule = current_rule;
   midrule->midrule_parent_rhs_index = symbol_list_length (current_rule->next);
@@ -433,28 +434,28 @@ grammar_current_rule_merge_set (uniqstr name, location loc)
 
 void
 grammar_current_rule_symbol_append (symbol *sym, location loc,
-				    named_ref *named_ref)
+				    named_ref *name)
 {
   symbol_list *p;
   if (current_rule->action_props.code)
     grammar_midrule_action ();
   p = grammar_symbol_append (sym, loc);
-  if (named_ref)
-    assign_named_ref(p, named_ref);
+  if (name)
+    assign_named_ref(p, name);
 }
 
 /* Attach an ACTION to the current rule.  */
 
 void
 grammar_current_rule_action_append (const char *action, location loc,
-				    named_ref *named_ref)
+				    named_ref *name)
 {
   if (current_rule->action_props.code)
     grammar_midrule_action ();
   /* After all symbol declarations have been parsed, packgram invokes
      code_props_translate_code.  */
   code_props_rule_action_init (&current_rule->action_props, action, loc,
-                               current_rule, named_ref);
+                               current_rule, name);
 }
 
 
