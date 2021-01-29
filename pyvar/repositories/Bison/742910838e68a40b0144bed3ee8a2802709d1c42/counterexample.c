@@ -334,9 +334,9 @@ complete_diverging_example (symbol_number conflict_sym,
               lookahead_required = false;
               derivation_list next_derivs =
                 expand_to_conflict (nsi, conflict_sym);
-              gl_list_iterator_t it = gl_list_iterator (next_derivs);
               derivation *d = NULL;
-              while (gl_list_iterator_next (&it, (const void **) &d, NULL))
+              for (gl_list_iterator_t it = gl_list_iterator (next_derivs);
+                   derivation_list_next (&it, &d);)
                 derivation_list_append (result, d);
               i += gl_list_size (next_derivs) - 1;
               derivation_list_free (next_derivs);
@@ -469,9 +469,10 @@ nonunifying_shift_path (gl_list_t reduce_path, state_item *shift_conflict)
   if (trace_flag & trace_cex)
     {
       fputs ("SHIFT ITEM PATH:\n", stderr);
-      gl_list_iterator_t it = gl_list_iterator (result);
       state_item *sip = NULL;
-      while (gl_list_iterator_next (&it, (const void **) &sip, NULL))
+      for (gl_list_iterator_t it = gl_list_iterator (result);
+           state_item_list_next (&it, &sip);
+           )
         print_state_item (sip, stderr);
     }
   return result;
@@ -574,6 +575,18 @@ search_state_print (search_state *ss)
   putc ('\n', stderr);
 }
 
+static inline bool
+search_state_list_next (gl_list_iterator_t *it, search_state **ss)
+{
+  const void *p = NULL;
+  bool res = gl_list_iterator_next (it, &p, NULL);
+  if (res)
+    *ss = (search_state*) p;
+  else
+    gl_list_iterator_free (it);
+  return res;
+}
+
 /*
  * When a search state is copied, this is used to
  * directly set one of the parse states
@@ -712,9 +725,10 @@ production_step (search_state *ss, int parser_state)
     simulate_production (ss->states[parser_state], other_sym);
   int complexity = ss->complexity + PRODUCTION_COST;
 
-  gl_list_iterator_t it = gl_list_iterator (prods);
   parse_state *ps = NULL;
-  while (gl_list_iterator_next (&it, (const void **) &ps, NULL))
+  for (gl_list_iterator_t it = gl_list_iterator (prods);
+       parse_state_list_next (&it, &ps);
+       )
     {
       search_state *copy = copy_search_state (ss);
       ss_set_parse_state (copy, parser_state, ps);
@@ -761,9 +775,10 @@ reduction_step (search_state *ss, const item_number *conflict_item,
   // FIXME: search_state *new_root = copy_search_state (ss);
   parse_state_list reduced =
     simulate_reduction (ps, rule_len, symbol_set);
-  gl_list_iterator_t it = gl_list_iterator (reduced);
-  parse_state *reduced_ps;
-  while (gl_list_iterator_next (&it, (const void **) &reduced_ps, NULL))
+  parse_state *reduced_ps = NULL;
+  for (gl_list_iterator_t it = gl_list_iterator (reduced);
+       parse_state_list_next (&it, &reduced_ps);
+       )
     {
       search_state *copy = copy_search_state (ss);
       ss_set_parse_state (copy, parser_state, reduced_ps);
@@ -797,9 +812,10 @@ search_state_prepend (search_state *ss, symbol_number sym, bitset guide)
     {
       int prod_state = prod1 ? 0 : 1;
       parse_state_list prev = parser_prepend (ss->states[prod_state]);
-      gl_list_iterator_t iter = gl_list_iterator (prev);
       parse_state *ps = NULL;
-      while (gl_list_iterator_next (&iter, (const void **)&ps, NULL))
+      for (gl_list_iterator_t iter = gl_list_iterator (prev);
+           parse_state_list_next (&iter, &ps);
+           )
         {
           const state_item *psi = parse_state_head (ps);
           bool guided = bitset_test (guide, psi->state->number);
@@ -828,18 +844,20 @@ search_state_prepend (search_state *ss, symbol_number sym, bitset guide)
   // loop through each pair of possible prepend states and append search
   // states for each pair where the parser states correspond to the same
   // parsed input.
-  gl_list_iterator_t iter1 = gl_list_iterator (prev1);
-  parse_state *ps1;
-  while (gl_list_iterator_next (&iter1, (const void **)&ps1, NULL))
+  parse_state *ps1 = NULL;
+  for (gl_list_iterator_t iter1 = gl_list_iterator (prev1);
+       parse_state_list_next (&iter1, &ps1);
+       )
     {
       const state_item *psi1 = parse_state_head (ps1);
       bool guided1 = bitset_test (guide, psi1->state->number);
       if (!guided1 && !EXTENDED_SEARCH)
         continue;
 
-      gl_list_iterator_t iter2 = gl_list_iterator (prev2);
-      parse_state *ps2;
-      while (gl_list_iterator_next (&iter2, (const void **)&ps2, NULL))
+      parse_state *ps2 = NULL;
+      for (gl_list_iterator_t iter2 = gl_list_iterator (prev2);
+           parse_state_list_next (&iter2, &ps2);
+           )
         {
           const state_item *psi2 = parse_state_head (ps2);
 
@@ -926,16 +944,15 @@ generate_next_states (search_state *ss, state_item *conflict1,
           int complexity = ss->complexity + 2 * SHIFT_COST;
           parse_state_list trans1 = simulate_transition (ps1);
           parse_state_list trans2 = simulate_transition (ps2);
-          gl_list_iterator_t it1 = gl_list_iterator (trans1);
-          parse_state *tps1;
-          while (gl_list_iterator_next (&it1, (const void **) &tps1, NULL))
-            {
-              gl_list_iterator_t it2 = gl_list_iterator (trans2);
-              parse_state *tps2;
-              while (gl_list_iterator_next
-                     (&it2, (const void **) &tps2, NULL))
-                ssb_append (new_search_state (tps1, tps2, complexity));
-            }
+          parse_state *tps1 = NULL;
+          parse_state *tps2 = NULL;
+          for (gl_list_iterator_t it1 = gl_list_iterator (trans1);
+               parse_state_list_next (&it1, &tps1);
+               )
+            for (gl_list_iterator_t it2 = gl_list_iterator (trans2);
+                 parse_state_list_next (&it2, &tps2);
+                 )
+              ssb_append (new_search_state (tps1, tps2, complexity));
           gl_list_free (trans1);
           gl_list_free (trans2);
         }
@@ -958,43 +975,48 @@ generate_next_states (search_state *ss, state_item *conflict1,
       int len2 = rhe2 - rhs2;
       int size2 = parse_state_length (ps2);
       bool ready2 = si2reduce && len2 < size2;
-      // If there is a path ready for reduction
-      // without being prepended further, reduce.
-      if (ready1)
+      // If there is a path ready for reduction without being
+      // prepended further, reduce.
+      if (ready1 && ready2)
         {
           gl_list_t reduced1 = reduction_step (ss, conflict1->item, 0, len1);
-          gl_list_iterator_t iter = gl_list_iterator (reduced1);
+          gl_list_add_last (reduced1, ss);
           search_state *red1 = NULL;
-          if (ready2)
+          for (gl_list_iterator_t iter = gl_list_iterator (reduced1);
+               search_state_list_next (&iter, &red1);
+               )
             {
-              gl_list_add_last (reduced1, ss);
-              while (gl_list_iterator_next
-                     (&iter, (const void **) &red1, NULL))
-                {
-                  gl_list_t reduced2 =
-                    reduction_step (red1, conflict2->item, 1, len2);
-                  gl_list_iterator_t iter2 = gl_list_iterator (reduced2);
-                  search_state *red2;
-                  while (gl_list_iterator_next
-                         (&iter2, (const void **) &red2, NULL))
-                    ssb_append (red2);
-                  // avoid duplicates
-                  if (red1 != ss)
-                    ssb_append (red1);
-                  gl_list_free (reduced2);
-                }
+              gl_list_t reduced2 =
+                reduction_step (red1, conflict2->item, 1, len2);
+              search_state *red2 = NULL;
+              for (gl_list_iterator_t iter2 = gl_list_iterator (reduced2);
+                   search_state_list_next (&iter2, &red2);
+                   )
+                ssb_append (red2);
+              // Avoid duplicates.
+              if (red1 != ss)
+                ssb_append (red1);
+              gl_list_free (reduced2);
             }
-          else
-            while (gl_list_iterator_next (&iter, (const void **) &red1, NULL))
-              ssb_append (red1);
+          gl_list_free (reduced1);
+        }
+      else if (ready1)
+        {
+          gl_list_t reduced1 = reduction_step (ss, conflict1->item, 0, len1);
+          search_state *red1 = NULL;
+          for (gl_list_iterator_t iter = gl_list_iterator (reduced1);
+               search_state_list_next (&iter, &red1);
+               )
+            ssb_append (red1);
           gl_list_free (reduced1);
         }
       else if (ready2)
         {
           gl_list_t reduced2 = reduction_step (ss, conflict2->item, 1, len2);
-          gl_list_iterator_t iter2 = gl_list_iterator (reduced2);
-          search_state *red2;
-          while (gl_list_iterator_next (&iter2, (const void **) &red2, NULL))
+          search_state *red2 = NULL;
+          for (gl_list_iterator_t iter2 = gl_list_iterator (reduced2);
+               search_state_list_next (&iter2, &red2);
+               )
             ssb_append (red2);
           gl_list_free (reduced2);
         }
@@ -1046,9 +1068,11 @@ unifying_example (state_item_number itm1,
   while (gl_list_size (ssb_queue) > 0)
     {
       const search_state_bundle *ssb = gl_list_get_at (ssb_queue, 0);
-      gl_list_iterator_t it = gl_list_iterator (ssb->states);
+
       search_state *ss = NULL;
-      while (gl_list_iterator_next (&it, (const void **) &ss, NULL))
+      for (gl_list_iterator_t it = gl_list_iterator (ssb->states);
+           search_state_list_next (&it, &ss);
+           )
         {
           if (trace_flag & trace_cex)
             search_state_print (ss);
@@ -1157,19 +1181,21 @@ counterexample_report (state_item_number itm1, state_item_number itm2,
   // Compute the shortest lookahead-sensitive path and associated sets of
   // parser states.
   gl_list_t shortest_path = shortest_path_from_start (itm1, next_sym);
-  bool reduceProdReached = false;
+  bool reduce_prod_reached = false;
   const rule *reduce_rule = item_rule (state_items[itm1].item);
 
   bitset_zero (scp_set);
   bitset_zero (rpp_set);
-  gl_list_iterator_t it = gl_list_iterator (shortest_path);
+
   state_item *si = NULL;
-  while (gl_list_iterator_next (&it, (const void **) &si, NULL))
+  for (gl_list_iterator_t it = gl_list_iterator (shortest_path);
+       state_item_list_next (&it, &si);
+       )
     {
       bitset_set (scp_set, si->state->number);
-      reduceProdReached = reduceProdReached
+      reduce_prod_reached = reduce_prod_reached
                           || item_rule (si->item) == reduce_rule;
-      if (reduceProdReached)
+      if (reduce_prod_reached)
         bitset_set (rpp_set, si->state->number);
     }
   time_t t = time (NULL);
