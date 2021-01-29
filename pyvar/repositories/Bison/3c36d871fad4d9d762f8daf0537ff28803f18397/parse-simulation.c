@@ -421,7 +421,9 @@ nullable_closure (parse_state *ps, state_item *si, parse_state_list state_list)
       state_item *nsi = &state_items[sin];
       current_ps = copy_parse_state (false, current_ps);
       ps_si_append (current_ps, nsi);
-      ps_derivs_append (current_ps, derivation_new (sp, derivation_list_new ()));
+      ps_derivs_append (current_ps,
+                        derivation_new (sp, derivation_list_new (),
+                                        state_item_rule (nsi)));
       parse_state_list_append (state_list, current_ps);
     }
 }
@@ -516,7 +518,7 @@ simulate_reduction (parse_state *ps, int rule_len, bitset symbol_set)
   state_item *si = (state_item *) ps->state_items.tail_elt;
   const rule *r = item_rule (si->item);
   symbol_number lhs = r->lhs->number;
-  derivation *deriv = derivation_new (lhs, popped_derivs);
+  derivation *deriv = derivation_new (lhs, popped_derivs, state_item_rule (si));
   --new_root->depth;
   ps_derivs_append (new_root, deriv);
 
