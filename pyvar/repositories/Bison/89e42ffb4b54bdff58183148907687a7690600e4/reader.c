@@ -406,8 +406,8 @@ grammar_midrule_action (void)
      action.  Create the MIDRULE.  */
   location dummy_loc = current_rule->action_props.location;
   symbol *dummy = dummy_symbol_get (dummy_loc);
-  symbol_type_set(dummy,
-                  current_rule->action_props.type, current_rule->action_props.location);
+  symbol_type_set (dummy,
+                   current_rule->action_props.type, current_rule->action_props.location);
   symbol_list *midrule = symbol_list_sym_new (dummy, dummy_loc);
 
   /* Remember named_ref of previous action. */
