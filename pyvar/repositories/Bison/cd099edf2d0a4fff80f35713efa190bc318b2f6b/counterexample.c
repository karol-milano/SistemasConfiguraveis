@@ -175,6 +175,8 @@ si_bfs_free (si_bfs_node *n)
     }
 }
 
+typedef gl_list_t si_bfs_node_list;
+
 /**
  * start is a state_item such that conflict_sym is an element of FIRSTS of the
  * nonterminal after the dot in start. Because of this, we should be able to
@@ -188,9 +190,10 @@ expand_to_conflict (state_item_number start, symbol_number conflict_sym)
 {
   si_bfs_node *init = si_bfs_new (start, NULL);
 
-  gl_list_t queue = gl_list_create (GL_LINKED_LIST, NULL, NULL,
-                                    (gl_listelement_dispose_fn) si_bfs_free,
-                                    true, 1, (const void **) &init);
+  si_bfs_node_list queue
+    = gl_list_create (GL_LINKED_LIST, NULL, NULL,
+                      (gl_listelement_dispose_fn) si_bfs_free,
+                      true, 1, (const void **) &init);
   si_bfs_node *node = NULL;
   // breadth-first search for a path of productions to the conflict symbol
   while (gl_list_size (queue) > 0)
@@ -274,7 +277,7 @@ expand_to_conflict (state_item_number start, symbol_number conflict_sym)
  */
 static derivation *
 complete_diverging_example (symbol_number conflict_sym,
-                            gl_list_t path, derivation_list derivs)
+                            state_item_list path, derivation_list derivs)
 {
   // The idea is to transfer each pending symbol on the productions
   // associated with the given StateItems to the resulting derivation.
@@ -395,15 +398,15 @@ complete_diverging_example (symbol_number conflict_sym,
 /* Iterate backwards through the shifts of the path in the reduce
    conflict, and find a path of shifts from the shift conflict that
    goes through the same states. */
-static gl_list_t
-nonunifying_shift_path (gl_list_t reduce_path, state_item *shift_conflict)
+static state_item_list
+nonunifying_shift_path (state_item_list reduce_path, state_item *shift_conflict)
 {
   gl_list_node_t tmp = gl_list_add_last (reduce_path, NULL);
   gl_list_node_t next_node = gl_list_previous_node (reduce_path, tmp);
   gl_list_node_t node = gl_list_previous_node (reduce_path, next_node);
   gl_list_remove_node (reduce_path, tmp);
   state_item *si = shift_conflict;
-  gl_list_t result =
+  state_item_list result =
     gl_list_create_empty (GL_LINKED_LIST, NULL, NULL, NULL, true);
   // FIXME: bool paths_merged;
   for (; node != NULL; next_node = node,
@@ -425,10 +428,10 @@ nonunifying_shift_path (gl_list_t reduce_path, state_item *shift_conflict)
 
       // bfs to find a shift to the right state
       si_bfs_node *init = si_bfs_new (si - state_items, NULL);
-      gl_list_t queue =
-        gl_list_create (GL_LINKED_LIST, NULL, NULL,
-                        (gl_listelement_dispose_fn) si_bfs_free,
-                        true, 1, (const void **) &init);
+      si_bfs_node_list queue
+        = gl_list_create (GL_LINKED_LIST, NULL, NULL,
+                          (gl_listelement_dispose_fn) si_bfs_free,
+                          true, 1, (const void **) &init);
       si_bfs_node *sis = NULL;
       state_item *prevsi = NULL;
       while (gl_list_size (queue) > 0)
@@ -493,11 +496,11 @@ nonunifying_shift_path (gl_list_t reduce_path, state_item *shift_conflict)
 static counterexample *
 example_from_path (bool shift_reduce,
                    state_item_number itm2,
-                   gl_list_t shortest_path, symbol_number next_sym)
+                   state_item_list shortest_path, symbol_number next_sym)
 {
   derivation *deriv1 =
     complete_diverging_example (next_sym, shortest_path, NULL);
-  gl_list_t path_2
+  state_item_list path_2
     = shift_reduce
     ? nonunifying_shift_path (shortest_path, &state_items [itm2])
     : shortest_path_from_start (itm2, next_sym);
@@ -583,6 +586,8 @@ search_state_print (search_state *ss)
   putc ('\n', stderr);
 }
 
+typedef gl_list_t search_state_list;
+
 static inline bool
 search_state_list_next (gl_list_iterator_t *it, search_state **ss)
 {
@@ -619,7 +624,7 @@ complete_diverging_examples (search_state *ss,
   derivation *new_derivs[2];
   for (int i = 0; i < 2; ++i)
     {
-      gl_list_t sitems;
+      state_item_list sitems;
       derivation_list derivs;
       parse_state_lists (ss->states[i], &sitems, &derivs);
       new_derivs[i] = complete_diverging_example (next_sym, sitems, derivs);
@@ -635,7 +640,7 @@ complete_diverging_examples (search_state *ss,
  */
 typedef struct
 {
-  gl_list_t states;
+  search_state_list states;
   int complexity;
 } search_state_bundle;
 
@@ -664,6 +669,8 @@ ssb_equals (const search_state_bundle *s1, const search_state_bundle *s2)
   return s1->complexity == s2->complexity;
 }
 
+typedef gl_list_t ssb_list;
+
 static size_t
 visited_hasher (const search_state *ss, size_t max)
 {
@@ -679,7 +686,7 @@ visited_comparator (const search_state *ss1, const search_state *ss2)
 }
 
 /* Priority queue for search states with minimal complexity. */
-static gl_list_t ssb_queue;
+static ssb_list ssb_queue;
 static Hash_table *visited;
 /* The set of parser states on the shortest lookahead-sensitive path. */
 static bitset scp_set = NULL;
@@ -756,12 +763,12 @@ reduction_cost (const parse_state *ps)
   return SHIFT_COST * shifts + PRODUCTION_COST * productions;
 }
 
-static gl_list_t
+static search_state_list
 reduction_step (search_state *ss, const item_number *conflict_item,
                 int parser_state, int rule_len)
 {
   (void) conflict_item; // FIXME: Unused
-  gl_list_t result =
+  search_state_list result =
     gl_list_create_empty (GL_LINKED_LIST, NULL, NULL, NULL, 1);
 
   parse_state *ps = ss->states[parser_state];
@@ -988,14 +995,14 @@ generate_next_states (search_state *ss, state_item *conflict1,
       // prepended further, reduce.
       if (ready1 && ready2)
         {
-          gl_list_t reduced1 = reduction_step (ss, conflict1->item, 0, len1);
+          search_state_list reduced1 = reduction_step (ss, conflict1->item, 0, len1);
           gl_list_add_last (reduced1, ss);
           search_state *red1 = NULL;
           for (gl_list_iterator_t iter = gl_list_iterator (reduced1);
                search_state_list_next (&iter, &red1);
                )
             {
-              gl_list_t reduced2 =
+              search_state_list reduced2 =
                 reduction_step (red1, conflict2->item, 1, len2);
               search_state *red2 = NULL;
               for (gl_list_iterator_t iter2 = gl_list_iterator (reduced2);
@@ -1011,7 +1018,7 @@ generate_next_states (search_state *ss, state_item *conflict1,
         }
       else if (ready1)
         {
-          gl_list_t reduced1 = reduction_step (ss, conflict1->item, 0, len1);
+          search_state_list reduced1 = reduction_step (ss, conflict1->item, 0, len1);
           search_state *red1 = NULL;
           for (gl_list_iterator_t iter = gl_list_iterator (reduced1);
                search_state_list_next (&iter, &red1);
@@ -1021,7 +1028,7 @@ generate_next_states (search_state *ss, state_item *conflict1,
         }
       else if (ready2)
         {
-          gl_list_t reduced2 = reduction_step (ss, conflict2->item, 1, len2);
+          search_state_list reduced2 = reduction_step (ss, conflict2->item, 1, len2);
           search_state *red2 = NULL;
           for (gl_list_iterator_t iter2 = gl_list_iterator (reduced2);
                search_state_list_next (&iter2, &red2);
@@ -1055,7 +1062,7 @@ static counterexample *
 unifying_example (state_item_number itm1,
                   state_item_number itm2,
                   bool shift_reduce,
-                  gl_list_t reduce_path, symbol_number next_sym)
+                  state_item_list reduce_path, symbol_number next_sym)
 {
   state_item *conflict1 = &state_items[itm1];
   state_item *conflict2 = &state_items[itm2];
@@ -1190,7 +1197,7 @@ counterexample_report (state_item_number itm1, state_item_number itm2,
 {
   // Compute the shortest lookahead-sensitive path and associated sets of
   // parser states.
-  gl_list_t shortest_path = shortest_path_from_start (itm1, next_sym);
+  state_item_list shortest_path = shortest_path_from_start (itm1, next_sym);
   bool reduce_prod_reached = false;
   const rule *reduce_rule = item_rule (state_items[itm1].item);
 
@@ -1226,7 +1233,8 @@ counterexample_report_shift_reduce (state_item_number itm1, state_item_number it
 {
   fputs (prefix, out);
   fprintf (out, _("Shift/reduce conflict on token %s:\n"), symbols[next_sym]->tag);
-  if (*prefix)
+  // In the report, print the items.
+  if (*prefix || trace_flag & trace_cex)
     {
       print_state_item (&state_items[itm1], out, prefix);
       print_state_item (&state_items[itm2], out, prefix);
@@ -1254,7 +1262,8 @@ counterexample_report_reduce_reduce (state_item_number itm1, state_item_number i
       }
     fputs (_(":\n"), out);
   }
-  if (*prefix)
+  // In the report, print the items.
+  if (*prefix || trace_flag & trace_cex)
     {
       print_state_item (&state_items[itm1], out, prefix);
       print_state_item (&state_items[itm2], out, prefix);
