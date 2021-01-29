@@ -196,7 +196,7 @@ expand_to_conflict (state_item_number start, symbol_number conflict_sym)
   while (gl_list_size (queue) > 0)
     {
       node = (si_bfs_node *) gl_list_get_at (queue, 0);
-      state_item *silast = state_items + node->si;
+      state_item *silast = &state_items[node->si];
       symbol_number sym = item_number_as_symbol_number (*silast->item);
       if (sym == conflict_sym)
         break;
@@ -238,7 +238,7 @@ expand_to_conflict (state_item_number start, symbol_number conflict_sym)
 
   for (si_bfs_node *n = node; n != NULL; n = n->parent)
     {
-      state_item *si = state_items + n->si;
+      state_item *si = &state_items[n->si];
       item_number *pos = si->item;
       if (SI_PRODUCTION (si))
         {
@@ -438,7 +438,7 @@ nonunifying_shift_path (gl_list_t reduce_path, state_item *shift_conflict)
           if (sis->si == 0)
             break;
 
-          state_item *search_si = state_items + sis->si;
+          state_item *search_si = &state_items[sis->si];
           // if the current state-item is a production item,
           // its reverse production items get added to the queue.
           // Otherwise, look for a reverse transition to the target state.
@@ -447,7 +447,7 @@ nonunifying_shift_path (gl_list_t reduce_path, state_item *shift_conflict)
           state_item_number sin;
           BITSET_FOR_EACH (biter, rsi, sin, 0)
             {
-              prevsi = state_items + sin;
+              prevsi = &state_items[sin];
               if (SI_TRANSITION (search_si))
                 {
                   if (prevsi->state == refsi->state)
@@ -465,9 +465,9 @@ nonunifying_shift_path (gl_list_t reduce_path, state_item *shift_conflict)
       // prepend path to shift we found
       if (sis)
         {
-          gl_list_node_t ln = gl_list_add_first (result, state_items + sis->si);
+          gl_list_node_t ln = gl_list_add_first (result, &state_items[sis->si]);
           for (si_bfs_node *n = sis->parent; n; n = n->parent)
-            ln = gl_list_add_after (result, ln, state_items + n->si);
+            ln = gl_list_add_after (result, ln, &state_items[n->si]);
 
         }
       si = prevsi;
@@ -1057,8 +1057,8 @@ unifying_example (state_item_number itm1,
                   bool shift_reduce,
                   gl_list_t reduce_path, symbol_number next_sym)
 {
-  state_item *conflict1 = state_items + itm1;
-  state_item *conflict2 = state_items + itm2;
+  state_item *conflict1 = &state_items[itm1];
+  state_item *conflict2 = &state_items[itm2];
   search_state *initial = initial_search_state (conflict1, conflict2);
   ssb_queue = gl_list_create_empty (GL_RBTREEHASH_LIST,
                                     (gl_listelement_equals_fn) ssb_equals,
