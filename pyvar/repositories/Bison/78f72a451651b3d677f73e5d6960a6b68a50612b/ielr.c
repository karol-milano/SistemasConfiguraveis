@@ -1025,7 +1025,7 @@ ielr_split_states (bitsetv follow_kernel_items, bitsetv always_follows,
               {
                 rule *this_rule = node->state->reductions->rules[r];
                 bitset lookahead_set =
-                  node->state->reductions->lookahead_tokens[r];
+                  node->state->reductions->lookaheads[r];
                 if (item_number_is_rule_number (*this_rule->rhs))
                   ielr_compute_goto_follow_set (follow_kernel_items,
                                                 always_follows, node,
