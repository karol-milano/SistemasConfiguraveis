@@ -288,7 +288,8 @@ expand_to_conflict (state_item_number start, symbol_number conflict_sym)
             derivation_list_append (result, derivation_new_leaf (*i));
           symbol_number lhs =
             rules[item_number_as_rule_number (*i)].lhs->number;
-          derivation *deriv = derivation_new (lhs, result);
+          derivation *deriv = derivation_new (lhs, result,
+                                              state_item_rule (si));
           result = derivation_list_new ();
           derivation_list_append (result, deriv);
         }
@@ -422,7 +423,7 @@ complete_diverging_example (symbol_number conflict_sym,
             derivation_list_prepend (result, derivation_new_leaf (*i));
         }
       // completing the derivation
-      derivation *new_deriv = derivation_new (r->lhs->number, result);
+      derivation *new_deriv = derivation_new (r->lhs->number, result, r);
       result = derivation_list_new ();
       derivation_list_append (result, new_deriv);
     }
