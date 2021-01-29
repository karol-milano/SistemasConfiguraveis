@@ -418,12 +418,12 @@ nullable_closure (parse_state *ps, state_item *si, parse_state_list state_list)
   for (state_item_number sin = si->trans; sin != -1;
        prev_sin = sin, sin = state_items[sin].trans)
     {
-      state_item *psi = state_items + prev_sin;
+      state_item *psi = &state_items[prev_sin];
       symbol_number sp = item_number_as_symbol_number (*psi->item);
       if (ISTOKEN (sp) || !nullable[sp - ntokens])
         break;
 
-      state_item *nsi = state_items + sin;
+      state_item *nsi = &state_items[sin];
       current_ps = copy_parse_state (false, current_ps);
       ps_si_append (current_ps, nsi);
       ps_derivs_append (current_ps, derivation_new (sp, derivation_list_new ()));
@@ -446,11 +446,11 @@ simulate_transition (parse_state *ps)
   if (si_next < 0)
     return result;
   parse_state *next_ps = copy_parse_state (false, ps);
-  ps_si_append (next_ps, state_items + si_next);
+  ps_si_append (next_ps, &state_items[si_next]);
   ps_derivs_append (next_ps, derivation_new_leaf (sym));
   parse_state_list_append (result, next_ps);
 
-  nullable_closure (next_ps, state_items + si_next, result);
+  nullable_closure (next_ps, &state_items[si_next], result);
   return result;
 }
 
@@ -486,7 +486,7 @@ simulate_production (parse_state *ps, symbol_number compat_sym)
         {
           // Take production step only if lhs is not nullable and
           // if first rhs symbol is compatible with compat_sym
-          state_item *next = state_items + sin;
+          state_item *next = &state_items[sin];
           item_number *itm1 = next->item;
           if (!compatible (*itm1, compat_sym) || !production_allowed (si, next))
             continue;
@@ -529,7 +529,7 @@ simulate_reduction (parse_state *ps, int rule_len, bitset symbol_set)
   if (s_size != rule_len + 1)
     {
       state_item *tail = (state_item *) new_root->state_items.tail_elt;
-      ps_si_append (new_root, state_items + tail->trans);
+      ps_si_append (new_root, &state_items[tail->trans]);
       parse_state_list_append (result, new_root);
     }
   else
@@ -560,7 +560,7 @@ simulate_reduction (parse_state *ps, int rule_len, bitset symbol_set)
               copy = copy_parse_state (false, copy);
               struct si_chunk *sis = &copy->state_items;
               const state_item *tail = sis->tail_elt;
-              ps_si_append (copy, state_items + tail->trans);
+              ps_si_append (copy, &state_items[tail->trans]);
               parse_state_list_append (result, copy);
               nullable_closure (copy, (state_item *) sis->tail_elt, result);
             }
@@ -582,7 +582,7 @@ parser_prepend (parse_state *ps)
   BITSET_FOR_EACH (biter, head->revs, sin, 0)
   {
     parse_state *copy = copy_parse_state (true, ps);
-    ps_si_prepend (copy, state_items + sin);
+    ps_si_prepend (copy, &state_items[sin]);
     if (SI_TRANSITION (head))
       ps_derivs_prepend (copy, derivation_new_leaf (prepend_sym));
     parse_state_list_append (res, copy);
