@@ -413,15 +413,16 @@ ielr_item_has_lookahead (state *s, symbol_number lhs, size_t item,
          didn't change this test to an aver just in case the usage of this
          function evolves to need those two cases.  In both cases, the current
          implementation returns the right result.  */
-      aver (s->items[item] != 1);
-      const bool is_successor_of_initial_item = s->items[item] <= 1;
+      const rule *r = item_rule (&ritem[s->items[item]]);
+      const bool is_successor_of_initial_item
+        = rule_is_initial (r) && &ritem[s->items[item]] == r->rhs + 1;
       aver (!is_successor_of_initial_item);
       if (!is_successor_of_initial_item)
         {
           /* If the LHS symbol of this item isn't known (because this is a
              top-level invocation), go get it.  */
           if (!lhs)
-            lhs = item_rule (&ritem[s->items[item]])->lhs->number;
+            lhs = r->lhs->number;
           /* If this kernel item is next to the beginning of the RHS, then
              check all predecessors' goto follows for the LHS.  */
           if (item_number_is_rule_number (ritem[s->items[item] - 2]))
@@ -625,7 +626,9 @@ ielr_compute_lookaheads (bitsetv follow_kernel_items, bitsetv always_follows,
          a special case to avoid the - 2 below, but the next successor can be
          handled fine without special casing it.  */
       aver (t->items[t_item] != 0);
-      const bool is_successor_of_initial_item = t->items[t_item] <= 1;
+      const rule *r = item_rule (&ritem[t->items[t_item]]);
+      const bool is_successor_of_initial_item
+        = rule_is_accepting (r) && &ritem[t->items[t_item]] == r->rhs + 1;
       if (!is_successor_of_initial_item
           && !bitset_empty_p (lookahead_filter[t_item]))
         {
@@ -633,7 +636,7 @@ ielr_compute_lookaheads (bitsetv follow_kernel_items, bitsetv always_follows,
           if (item_number_is_rule_number (ritem[t->items[t_item] - 2]))
             ielr_compute_goto_follow_set (
               follow_kernel_items, always_follows, s,
-              item_rule (&ritem[t->items[t_item]])->lhs,
+              r->lhs,
               lookaheads[t_item]);
           else if (s->lookaheads)
             {
