@@ -364,7 +364,7 @@ complete_diverging_example (symbol_number conflict_sym,
               lookahead_required = false;
             }
         }
-      rule_number r = item_number_as_rule_number (*i);
+      const rule *r = &rules[item_number_as_rule_number (*i)];
       // add derivations for symbols before dot
       for (i = item - 1; !item_number_is_rule_number (*i) && i >= ritem; i--)
         {
@@ -381,7 +381,7 @@ complete_diverging_example (symbol_number conflict_sym,
             derivation_list_prepend (result, derivation_new_leaf (*i));
         }
       // completing the derivation
-      derivation *new_deriv = derivation_new (rules[r].lhs->number, result);
+      derivation *new_deriv = derivation_new (r->lhs->number, result);
       result = derivation_list_new ();
       derivation_list_append (result, new_deriv);
     }
