@@ -408,8 +408,8 @@ nullable_closure (parse_state *ps, state_item *si, parse_state_list state_list)
 {
   parse_state *current_ps = ps;
   state_item_number prev_sin = si - state_items;
-  for (state_item_number sin = si_trans[prev_sin];
-       sin != -1; prev_sin = sin, sin = si_trans[sin])
+  for (state_item_number sin = si->trans; sin != -1;
+       prev_sin = sin, sin = state_items[sin].trans)
     {
       state_item *psi = state_items + prev_sin;
       symbol_number sp = item_number_as_symbol_number (*psi->item);
@@ -432,7 +432,7 @@ simulate_transition (parse_state *ps)
   // Transition on the same next symbol, taking nullable
   // symbols into account.
   gl_list_t result = parse_state_list_new ();
-  state_item_number si_next = si_trans[si - state_items];
+  state_item_number si_next = si->trans;
   // check for disabled transition, shouldn't happen
   // as any state_items that lead to these should be
   // disabled.
@@ -471,12 +471,11 @@ simulate_production (parse_state *ps, symbol_number compat_sym)
 {
   gl_list_t result = parse_state_list_new ();
   const state_item *si = parse_state_tail (ps);
-  bitset prod = si_prods_lookup (si - state_items);
-  if (prod)
+  if (si->prods)
     {
       bitset_iterator biter;
       state_item_number sin;
-      BITSET_FOR_EACH (biter, prod, sin, 0)
+      BITSET_FOR_EACH (biter, si->prods, sin, 0)
         {
           // Take production step only if lhs is not nullable and
           // if first rhs symbol is compatible with compat_sym
@@ -523,7 +522,7 @@ simulate_reduction (parse_state *ps, int rule_len, bitset symbol_set)
   if (s_size != rule_len + 1)
     {
       state_item *tail = (state_item *) new_root->state_items.tail_elt;
-      ps_si_append (new_root, state_items + si_trans[tail - state_items]);
+      ps_si_append (new_root, state_items + tail->trans);
       parse_state_list_append (result, new_root);
     }
   else
@@ -553,7 +552,7 @@ simulate_reduction (parse_state *ps, int rule_len, bitset symbol_set)
               copy = copy_parse_state (false, copy);
               struct si_chunk *sis = &copy->state_items;
               const state_item *tail = sis->tail_elt;
-              ps_si_append (copy, state_items + si_trans[tail - state_items]);
+              ps_si_append (copy, state_items + tail->trans);
               parse_state_list_append (result, copy);
               nullable_closure (copy, (state_item *) sis->tail_elt, result);
             }
@@ -568,12 +567,11 @@ parser_prepend (parse_state *ps)
 {
   gl_list_t result = parse_state_list_new ();
   const state_item *head = ps->state_items.head_elt;
-  bitset prev = si_revs[head - state_items];
   symbol_number prepend_sym =
     item_number_as_symbol_number (*(head->item - 1));
   bitset_iterator biter;
   state_item_number sin;
-  BITSET_FOR_EACH (biter, prev, sin, 0)
+  BITSET_FOR_EACH (biter, head->revs, sin, 0)
   {
     parse_state *copy = copy_parse_state (true, ps);
     ps_si_prepend (copy, state_items + sin);
