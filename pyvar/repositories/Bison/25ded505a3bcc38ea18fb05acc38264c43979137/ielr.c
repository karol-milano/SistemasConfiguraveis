@@ -649,7 +649,7 @@ ielr_compute_lookaheads (bitsetv follow_kernel_items, bitsetv always_follows,
       aver (t->items[t_item] != 0);
       const rule *r = item_rule (&ritem[t->items[t_item]]);
       const bool is_successor_of_initial_item
-        = rule_is_accepting (r) && &ritem[t->items[t_item]] == r->rhs + 1;
+        = rule_is_initial (r) && &ritem[t->items[t_item]] == r->rhs + 1;
       if (!is_successor_of_initial_item
           && !bitset_empty_p (lookahead_filter[t_item]))
         {
