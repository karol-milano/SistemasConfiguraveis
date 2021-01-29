@@ -424,7 +424,7 @@ ielr_item_has_lookahead (state *s, symbol_number lhs, size_t item,
           if (item_number_is_rule_number (ritem[s->items[item] - 2]))
             {
               state **predecessor;
-              aver (lhs != accept->number);
+              aver (lhs != accept->content->number);
               for (predecessor = predecessors[s->number];
                    *predecessor;
                    ++predecessor)
@@ -580,7 +580,7 @@ typedef struct state_list {
 static void
 ielr_compute_goto_follow_set (bitsetv follow_kernel_items,
                               bitsetv always_follows, state_list *s,
-                              symbol *n, bitset follow_set)
+                              sym_content *n, bitset follow_set)
 {
   goto_number n_goto = map_goto (s->lr0Isocore->state->number, n->number);
   bitset_copy (follow_set, always_follows[n_goto]);
