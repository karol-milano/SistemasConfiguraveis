@@ -80,12 +80,12 @@ counterexample *
 new_counterexample (const derivation *d1, const derivation *d2,
                     bool u, bool t)
 {
-  counterexample *ret = xmalloc (sizeof (counterexample));
-  ret->d1 = d1;
-  ret->d2 = d2;
-  ret->unifying = u;
-  ret->timeout = t;
-  return ret;
+  counterexample *res = xmalloc (sizeof (counterexample));
+  res->d1 = d1;
+  res->d2 = d2;
+  res->unifying = u;
+  res->timeout = t;
+  return res;
 }
 
 void
@@ -127,13 +127,13 @@ typedef struct si_bfs_node
 si_bfs_node *
 si_bfs_new (state_item_number si, si_bfs_node *parent)
 {
-  si_bfs_node *ret = xcalloc (1, sizeof (si_bfs_node));
-  ret->si = si;
-  ret->parent = parent;
-  ret->reference_count = 1;
+  si_bfs_node *res = xcalloc (1, sizeof (si_bfs_node));
+  res->si = si;
+  res->parent = parent;
+  res->reference_count = 1;
   if (parent)
     ++parent->reference_count;
-  return ret;
+  return res;
 }
 
 static bool
@@ -230,7 +230,7 @@ expand_to_conflict (state_item_number start, symbol_number conflict_sym)
       item_number *pos = si->item;
       if (SI_PRODUCTION (si))
         {
-          item_number *i;
+          item_number *i = NULL;
           for (i = pos + 1; !item_number_is_rule_number (*i); ++i)
             gl_list_add_last (result, derivation_new (*i, NULL));
           symbol_number lhs =
@@ -333,7 +333,7 @@ complete_diverging_example (symbol_number conflict_sym,
               gl_list_t next_derivs = expand_to_conflict (nsi,
                                                           conflict_sym);
               gl_list_iterator_t it = gl_list_iterator (next_derivs);
-              derivation *d;
+              derivation *d = NULL;
               while (gl_list_iterator_next (&it, (const void **) &d, NULL))
                 gl_list_add_last (result, d);
               i += gl_list_size (next_derivs) - 1;
@@ -382,9 +382,9 @@ complete_diverging_example (symbol_number conflict_sym,
         gl_list_create (GL_LINKED_LIST, NULL, NULL, NULL, true, 1,
                         (const void **) &new_deriv);
     }
-  derivation *ret = (derivation *) gl_list_get_at (result, 0);
+  derivation *res = (derivation *) gl_list_get_at (result, 0);
   gl_list_free (result);
-  return ret;
+  return res;
 }
 
 /* iterates backwards through the shifts of the path in the
@@ -473,7 +473,7 @@ nonunifying_shift_path (gl_list_t reduce_path, state_item *shift_conflict)
     {
       fputs ("SHIFT ITEM PATH:\n", stderr);
       gl_list_iterator_t it = gl_list_iterator (result);
-      state_item *sip;
+      state_item *sip = NULL;
       while (gl_list_iterator_next (&it, (const void **) &sip, NULL))
         print_state_item (sip, stderr);
     }
@@ -520,35 +520,35 @@ typedef struct
 static search_state *
 initial_search_state (state_item *conflict1, state_item *conflict2)
 {
-  search_state *ret = xmalloc (sizeof (search_state));
-  ret->states[0] = new_parse_state (conflict1);
-  ret->states[1] = new_parse_state (conflict2);
-  parse_state_retain (ret->states[0]);
-  parse_state_retain (ret->states[1]);
-  ret->complexity = 0;
-  return ret;
+  search_state *res = xmalloc (sizeof (search_state));
+  res->states[0] = new_parse_state (conflict1);
+  res->states[1] = new_parse_state (conflict2);
+  parse_state_retain (res->states[0]);
+  parse_state_retain (res->states[1]);
+  res->complexity = 0;
+  return res;
 }
 
 static search_state *
 new_search_state (parse_state *ps1, parse_state *ps2, int complexity)
 {
-  search_state *ret = xmalloc (sizeof (search_state));
-  ret->states[0] = ps1;
-  ret->states[1] = ps2;
-  parse_state_retain (ret->states[0]);
-  parse_state_retain (ret->states[1]);
-  ret->complexity = complexity;
-  return ret;
+  search_state *res = xmalloc (sizeof (search_state));
+  res->states[0] = ps1;
+  res->states[1] = ps2;
+  parse_state_retain (res->states[0]);
+  parse_state_retain (res->states[1]);
+  res->complexity = complexity;
+  return res;
 }
 
 static search_state *
 copy_search_state (search_state *parent)
 {
-  search_state *copy = xmalloc (sizeof (search_state));
-  memcpy (copy, parent, sizeof (search_state));
-  parse_state_retain (copy->states[0]);
-  parse_state_retain (copy->states[1]);
-  return copy;
+  search_state *res = xmalloc (sizeof (search_state));
+  memcpy (res, parent, sizeof (search_state));
+  parse_state_retain (res->states[0]);
+  parse_state_retain (res->states[1]);
+  return res;
 }
 
 static void
@@ -721,7 +721,7 @@ production_step (search_state *ss, int parser_state)
   int complexity = ss->complexity + PRODUCTION_COST;
 
   gl_list_iterator_t it = gl_list_iterator (prods);
-  parse_state *ps;
+  parse_state *ps = NULL;
   while (gl_list_iterator_next (&it, (const void **) &ps, NULL))
     {
       search_state *copy = copy_search_state (ss);
@@ -801,7 +801,7 @@ search_state_prepend (search_state *ss, symbol_number sym, bitset guide)
       int prod_state = prod1 ? 0 : 1;
       gl_list_t prev = parser_prepend (ss->states[prod_state]);
       gl_list_iterator_t iter = gl_list_iterator (prev);
-      parse_state *ps;
+      parse_state *ps = NULL;
       while (gl_list_iterator_next (&iter, (const void **)&ps, NULL))
         {
           const state_item *psi = parse_state_head (ps);
@@ -1006,11 +1006,10 @@ generate_next_states (search_state *ss, state_item *conflict1,
        * rule, so we must prepend */
       else
         {
-          symbol_number sym;
-          if (si1reduce && !ready1)
-            sym = *(rhe1 - size1);
-          else
-            sym = *(rhe2 - size2);
+          const symbol_number sym
+            = si1reduce && !ready1
+            ? *(rhe1 - size1)
+            : *(rhe2 - size2);
           search_state_prepend (ss, sym,
                                 parse_state_depth (ss->states[0]) >= 0
                                 ? rpp_set : scp_set);
@@ -1051,7 +1050,7 @@ unifying_example (state_item_number itm1,
     {
       const search_state_bundle *ssb = gl_list_get_at (ssb_queue, 0);
       gl_list_iterator_t it = gl_list_iterator (ssb->states);
-      search_state *ss;
+      search_state *ss = NULL;
       while (gl_list_iterator_next (&it, (const void **) &ss, NULL))
         {
           if (trace_flag & trace_cex)
@@ -1170,7 +1169,7 @@ counterexample_report (state_item_number itm1, state_item_number itm2,
   bitset_zero (scp_set);
   bitset_zero (rpp_set);
   gl_list_iterator_t it = gl_list_iterator (shortest_path);
-  state_item *si;
+  state_item *si = NULL;
   while (gl_list_iterator_next (&it, (const void **) &si, NULL))
     {
       bitset_set (scp_set, si->state->number);
