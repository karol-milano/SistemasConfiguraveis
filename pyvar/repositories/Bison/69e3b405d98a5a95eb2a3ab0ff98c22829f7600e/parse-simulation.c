@@ -426,7 +426,7 @@ nullable_closure (parse_state *ps, state_item *si, parse_state_list state_list)
       state_item *nsi = state_items + sin;
       current_ps = copy_parse_state (false, current_ps);
       ps_si_append (current_ps, nsi);
-      ps_derivs_append (current_ps, derivation_new_leaf (sp));
+      ps_derivs_append (current_ps, derivation_new (sp, derivation_list_new ()));
       parse_state_list_append (state_list, current_ps);
     }
 }
