@@ -413,7 +413,10 @@ ielr_item_has_lookahead (state *s, symbol_number lhs, size_t item,
          didn't change this test to an aver just in case the usage of this
          function evolves to need those two cases.  In both cases, the current
          implementation returns the right result.  */
-      if (s->items[item] > 1)
+      aver (s->items[item] != 1);
+      const bool is_successor_of_initial_item = s->items[item] <= 1;
+      aver (!is_successor_of_initial_item);
+      if (!is_successor_of_initial_item)
         {
           /* If the LHS symbol of this item isn't known (because this is a
              top-level invocation), go get it.  */
@@ -622,9 +625,11 @@ ielr_compute_lookaheads (bitsetv follow_kernel_items, bitsetv always_follows,
          a special case to avoid the - 2 below, but the next successor can be
          handled fine without special casing it.  */
       aver (t->items[t_item] != 0);
-      if (t->items[t_item] > 1
+      const bool is_successor_of_initial_item = t->items[t_item] <= 1;
+      if (!is_successor_of_initial_item
           && !bitset_empty_p (lookahead_filter[t_item]))
         {
+          /* Is this kernel item next to the beginning of the RHS?  */
           if (item_number_is_rule_number (ritem[t->items[t_item] - 2]))
             ielr_compute_goto_follow_set (
               follow_kernel_items, always_follows, s,
