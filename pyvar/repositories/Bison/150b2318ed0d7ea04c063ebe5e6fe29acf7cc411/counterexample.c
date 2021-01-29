@@ -701,7 +701,8 @@ production_step (search_state *ss, int parser_state)
 {
   const state_item *other_si = parse_state_tail (ss->states[1 - parser_state]);
   symbol_number other_sym = item_number_as_symbol_number (*other_si->item);
-  gl_list_t prods = simulate_production (ss->states[parser_state], other_sym);
+  parse_state_list prods =
+    simulate_production (ss->states[parser_state], other_sym);
   int complexity = ss->complexity + PRODUCTION_COST;
 
   gl_list_iterator_t it = gl_list_iterator (prods);
@@ -751,7 +752,8 @@ reduction_step (search_state *ss, const item_number *conflict_item,
     }
 
   // FIXME: search_state *new_root = copy_search_state (ss);
-  gl_list_t reduced = simulate_reduction (ps, rule_len, symbol_set);
+  parse_state_list reduced =
+    simulate_reduction (ps, rule_len, symbol_set);
   gl_list_iterator_t it = gl_list_iterator (reduced);
   parse_state *reduced_ps;
   while (gl_list_iterator_next (&it, (const void **) &reduced_ps, NULL))
@@ -787,7 +789,7 @@ search_state_prepend (search_state *ss, symbol_number sym, bitset guide)
   if (prod1 != SI_PRODUCTION (si2src))
     {
       int prod_state = prod1 ? 0 : 1;
-      gl_list_t prev = parser_prepend (ss->states[prod_state]);
+      parse_state_list prev = parser_prepend (ss->states[prod_state]);
       gl_list_iterator_t iter = gl_list_iterator (prev);
       parse_state *ps = NULL;
       while (gl_list_iterator_next (&iter, (const void **)&ps, NULL))
@@ -813,8 +815,8 @@ search_state_prepend (search_state *ss, symbol_number sym, bitset guide)
   int complexity_cost = prod1 ? PRODUCTION_COST : UNSHIFT_COST;
   complexity_cost *= 2;
 
-  gl_list_t prev1 = parser_prepend (ss->states[0]);
-  gl_list_t prev2 = parser_prepend (ss->states[1]);
+  parse_state_list prev1 = parser_prepend (ss->states[0]);
+  parse_state_list prev2 = parser_prepend (ss->states[1]);
 
   // loop through each pair of possible prepend states and append search
   // states for each pair where the parser states correspond to the same
@@ -915,8 +917,8 @@ generate_next_states (search_state *ss, state_item *conflict1,
       if (*si1->item == *si2->item)
         {
           int complexity = ss->complexity + 2 * SHIFT_COST;
-          gl_list_t trans1 = simulate_transition (ps1);
-          gl_list_t trans2 = simulate_transition (ps2);
+          parse_state_list trans1 = simulate_transition (ps1);
+          parse_state_list trans2 = simulate_transition (ps2);
           gl_list_iterator_t it1 = gl_list_iterator (trans1);
           parse_state *tps1;
           while (gl_list_iterator_next (&it1, (const void **) &tps1, NULL))
