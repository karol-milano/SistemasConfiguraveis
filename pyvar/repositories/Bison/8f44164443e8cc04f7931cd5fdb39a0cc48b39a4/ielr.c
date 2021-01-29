@@ -418,14 +418,7 @@ ielr_item_has_lookahead (state *s, symbol_number lhs, size_t item,
           /* If the LHS symbol of this item isn't known (because this is a
              top-level invocation), go get it.  */
           if (!lhs)
-            {
-              int i;
-              for (i = s->items[item];
-                   !item_number_is_rule_number (ritem[i]);
-                   ++i)
-                continue;
-              lhs = rules[item_number_as_rule_number (ritem[i])].lhs->number;
-            }
+            lhs = item_rule (&ritem[s->items[item]])->lhs->number;
           /* If this kernel item is next to the beginning of the RHS, then
              check all predecessors' goto follows for the LHS.  */
           if (item_number_is_rule_number (ritem[s->items[item] - 2]))
@@ -633,17 +626,10 @@ ielr_compute_lookaheads (bitsetv follow_kernel_items, bitsetv always_follows,
           && !bitset_empty_p (lookahead_filter[t_item]))
         {
           if (item_number_is_rule_number (ritem[t->items[t_item] - 2]))
-            {
-              int rule_item;
-              for (rule_item = t->items[t_item];
-                   !item_number_is_rule_number (ritem[rule_item]);
-                   ++rule_item)
-                ;
-              ielr_compute_goto_follow_set (
-                follow_kernel_items, always_follows, s,
-                rules[item_number_as_rule_number (ritem[rule_item])].lhs,
-                lookaheads[t_item]);
-            }
+            ielr_compute_goto_follow_set (
+              follow_kernel_items, always_follows, s,
+              item_rule (&ritem[t->items[t_item]])->lhs,
+              lookaheads[t_item]);
           else if (s->lookaheads)
             {
               /* We don't have to start the s item search at the beginning
