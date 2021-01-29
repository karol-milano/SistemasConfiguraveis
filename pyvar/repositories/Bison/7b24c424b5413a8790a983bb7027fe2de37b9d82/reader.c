@@ -368,7 +368,7 @@ grammar_current_rule_end (location loc)
 
 
 /*-------------------------------------------------------------------.
-| The previous action turns out the be a mid-rule action.  Attach it |
+| The previous action turns out to be a mid-rule action.  Attach it  |
 | to the current rule, i.e., create a dummy symbol, attach it this   |
 | mid-rule action, and append this dummy nonterminal to the current  |
 | rule.                                                              |
@@ -385,6 +385,8 @@ grammar_midrule_action (void)
      action.  Create the MIDRULE.  */
   location dummy_location = current_rule->action_props.location;
   symbol *dummy = dummy_symbol_get (dummy_location);
+  symbol_type_set(dummy,
+                  current_rule->action_props.type, current_rule->action_props.location);
   symbol_list *midrule = symbol_list_sym_new (dummy, dummy_location);
 
   /* Remember named_ref of previous action. */
@@ -399,7 +401,9 @@ grammar_midrule_action (void)
   code_props_rule_action_init (&midrule->action_props,
                                current_rule->action_props.code,
                                current_rule->action_props.location,
-                               midrule, 0,
+                               midrule,
+                               /* name_ref */ NULL,
+                               /* type */ NULL,
                                current_rule->action_props.is_predicate);
   code_props_none_init (&current_rule->action_props);
 
@@ -520,14 +524,15 @@ grammar_current_rule_symbol_append (symbol *sym, location loc,
 
 void
 grammar_current_rule_action_append (const char *action, location loc,
-                                    named_ref *name)
+                                    named_ref *name, uniqstr type)
 {
   if (current_rule->action_props.code)
     grammar_midrule_action ();
   /* After all symbol declarations have been parsed, packgram invokes
      code_props_translate_code.  */
   code_props_rule_action_init (&current_rule->action_props, action, loc,
-                               current_rule, name,
+                               current_rule,
+                               name, type,
                                /* is_predicate */ false);
 }
 
@@ -537,7 +542,8 @@ grammar_current_rule_predicate_append (const char *pred, location loc)
   if (current_rule->action_props.code)
     grammar_midrule_action ();
   code_props_rule_action_init (&current_rule->action_props, pred, loc,
-                               current_rule, NULL,
+                               current_rule,
+                               NULL, NULL,
                                /* is_predicate */ true);
 }
 
