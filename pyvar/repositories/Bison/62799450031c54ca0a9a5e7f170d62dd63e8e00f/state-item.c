@@ -150,7 +150,7 @@ init_state_items (void)
           state_item_set (sidx, s, s->items[j]);
           state_item *si = state_items + sidx;
           const rule *r = item_rule (si->item);
-          if (red->rules[rule_search_idx] < r)
+          if (rule_search_idx < red->num && red->rules[rule_search_idx] < r)
             ++rule_search_idx;
           if (rule_search_idx < red->num && r == red->rules[rule_search_idx])
             {
