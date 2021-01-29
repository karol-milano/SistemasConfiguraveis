@@ -150,7 +150,7 @@ init_state_items (void)
             ++rule_search_idx;
           if (rule_search_idx < red->num && r == red->rules[rule_search_idx])
             {
-              bitsetv lookahead = red->lookahead_tokens;
+              bitsetv lookahead = red->lookaheads;
               if (lookahead)
                 si->lookahead = lookahead[rule_search_idx];
             }
@@ -163,7 +163,7 @@ init_state_items (void)
           state_item_set (sidx, s, off);
           if (item_number_is_rule_number (ritem[off]))
             {
-              bitsetv lookahead = red->lookahead_tokens;
+              bitsetv lookahead = red->lookaheads;
               if (lookahead)
                 state_items[sidx].lookahead = lookahead[rule_search_idx];
               ++rule_search_idx;
