@@ -1030,7 +1030,7 @@ ielr_split_states (bitsetv follow_kernel_items, bitsetv always_follows,
         if (!node->state->consistent)
           {
             size_t i = 0;
-            item_number *itemset = node->state->items;
+            item_index *itemset = node->state->items;
             for (size_t r = 0; r < node->state->reductions->num; ++r)
               {
                 rule *this_rule = node->state->reductions->rules[r];
