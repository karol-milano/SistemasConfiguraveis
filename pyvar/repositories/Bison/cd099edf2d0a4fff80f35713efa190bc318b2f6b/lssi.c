@@ -82,8 +82,10 @@ lssi_comparator (lssi *s1, lssi *s2)
   return false;
 }
 
+typedef gl_list_t lssi_list;
+
 static inline bool
-append_lssi (lssi *sn, Hash_table *visited, gl_list_t queue)
+append_lssi (lssi *sn, Hash_table *visited, lssi_list queue)
 {
   if (hash_lookup (visited, sn))
     {
@@ -121,7 +123,7 @@ static bitset
 eligible_state_items (state_item *target)
 {
   bitset result = bitset_create (nstate_items, BITSET_FIXED);
-  gl_list_t queue =
+  state_item_list queue =
     gl_list_create (GL_LINKED_LIST, NULL, NULL, NULL, true, 1,
                     (const void **) &target);
   while (gl_list_size (queue) > 0)
@@ -147,7 +149,7 @@ eligible_state_items (state_item *target)
  * this conflict. If optimized is true, only consider parser states
  * that can reach the conflict state.
  */
-gl_list_t
+state_item_list
 shortest_path_from_start (state_item_number target, symbol_number next_sym)
 {
   bitset eligible = eligible_state_items (&state_items[target]);
@@ -159,7 +161,7 @@ shortest_path_from_start (state_item_number target, symbol_number next_sym)
   bitset il = bitset_create (nsyms, BITSET_FIXED);
   bitset_set (il, 0);
   lssi *init = new_lssi (0, NULL, il, true);
-  gl_list_t queue = gl_list_create_empty (GL_LINKED_LIST, NULL, NULL,
+  lssi_list queue = gl_list_create_empty (GL_LINKED_LIST, NULL, NULL,
                                           NULL, true);
   append_lssi (init, visited, queue);
   // breadth-first search
@@ -240,7 +242,7 @@ shortest_path_from_start (state_item_number target, symbol_number next_sym)
       fputs ("Cannot find shortest path to conflict state.", stderr);
       abort ();
     }
-  gl_list_t res =
+  state_item_list res =
     gl_list_create_empty (GL_LINKED_LIST, NULL, NULL, NULL, true);
   for (lssi *sn = n; sn != NULL; sn = sn->parent)
     gl_list_add_first (res, &state_items[sn->si]);
@@ -306,10 +308,10 @@ intersect (bitset ts, bitset syms)
  * Compute a list of state_items that have a production to n with respect
  * to its lookahead
  */
-gl_list_t
+state_item_list
 lssi_reverse_production (const state_item *si, bitset lookahead)
 {
-  gl_list_t result =
+  state_item_list result =
     gl_list_create_empty (GL_LINKED_LIST, NULL, NULL, NULL, true);
   if (SI_TRANSITION (si))
     return result;
