@@ -230,7 +230,7 @@ ielr_compute_follow_kernel_items (bitset ritem_sees_lookahead_set,
   for (goto_number i = 0; i < ngotos; ++i)
     {
       size_t nitems = states[from_state[i]]->nitems;
-      item_number *items = states[from_state[i]]->items;
+      item_index *items = states[from_state[i]]->items;
       for (size_t j = 0; j < nitems; ++j)
         /* If this item has this goto and if all subsequent symbols in this
            RHS (if any) are nullable nonterminals, then record this item as
