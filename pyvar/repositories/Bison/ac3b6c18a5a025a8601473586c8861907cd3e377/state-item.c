@@ -94,9 +94,8 @@ hash_pair_remove (Hash_table *tab, int key)
   hash_delete (tab, hp);
 }
 
-/* return a state_item from a state's id and the offset of the item
-  within the state.
- */
+/* A state_item from a state's id and the offset of the item within
+   the state. */
 state_item *
 state_item_lookup (state_number s, state_item_number off)
 {
@@ -104,12 +103,11 @@ state_item_lookup (state_number s, state_item_number off)
 }
 
 static inline void
-state_item_set (state_item_number sidx, state *s, item_number off)
+state_item_set (state_item_number sidx, const state *s, item_number off)
 {
-  state_item *si = state_items + sidx;
-  si->state = s;
-  si->item = &ritem[off];
-  si->lookahead = NULL;
+  state_items[sidx].state = s;
+  state_items[sidx].item = &ritem[off];
+  state_items[sidx].lookahead = NULL;
   si_trans[sidx] = -1;
 }
 
@@ -123,11 +121,11 @@ init_state_items (void)
   bitsetv production_items = bitsetv_create (nstates, nritems, BITSET_SPARSE);
   for (int i = 0; i < nstates; ++i)
     {
-      state *s = states[i];
+      const state *s = states[i];
       nstate_items += s->nitems;
       closure (s->items, s->nitems);
       for (size_t j = 0; j < nitemset; ++j)
-        if (itemset[j] > 0
+        if (0 < itemset[j]
             && item_number_is_rule_number (ritem[itemset[j] - 1]))
           {
             bitset_set (production_items[i], itemset[j]);
@@ -143,8 +141,8 @@ init_state_items (void)
     {
       state_item_map[i] = sidx;
       int rule_search_idx = 0;
-      state *s = states[i];
-      reductions *red = s->reductions;
+      const state *s = states[i];
+      const reductions *red = s->reductions;
       for (int j = 0; j < s->nitems; ++j)
         {
           state_item_set (sidx, s, s->items[j]);
