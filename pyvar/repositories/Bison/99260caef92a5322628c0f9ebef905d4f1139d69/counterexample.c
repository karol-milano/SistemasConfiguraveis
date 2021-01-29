@@ -196,7 +196,7 @@ expand_to_conflict (state_item_number start, symbol_number conflict_sym)
           // add each production to the search
           bitset_iterator biter;
           state_item_number sin;
-          bitset sib = si_prods_lookup (node->si);
+          bitset sib = silast->prods;
           BITSET_FOR_EACH (biter, sib, sin, 0)
             {
               // ignore productions already in the path
@@ -208,7 +208,7 @@ expand_to_conflict (state_item_number start, symbol_number conflict_sym)
           // for nullable nonterminals, add its goto to the search
           if (nullable[sym - ntokens])
             {
-              si_bfs_node *next = si_bfs_new (si_trans[node->si], node);
+              si_bfs_node *next = si_bfs_new (silast->trans, node);
               gl_list_add_last (queue, next);
             }
         }
@@ -304,7 +304,8 @@ complete_diverging_example (symbol_number conflict_sym,
       // go through each symbol after the dot in the current rule, and
       // add each symbol to its derivation.
       for (state_item_number nsi = si - state_items;
-           !item_number_is_rule_number (*i); ++i, nsi = si_trans[nsi])
+           !item_number_is_rule_number (*i);
+           ++i, nsi = state_items[nsi].trans)
         {
           // if the item is a reduction, we could skip to the wrong rule
           // by starting at i + 1, so this continue is necessary
@@ -433,7 +434,7 @@ nonunifying_shift_path (gl_list_t reduce_path, state_item *shift_conflict)
           // if the current state-item is a production item,
           // its reverse production items get added to the queue.
           // Otherwise, look for a reverse transition to the target state.
-          bitset rsi = si_revs[sis->si];
+          bitset rsi = search_si->revs;
           bitset_iterator biter;
           state_item_number sin;
           BITSET_FOR_EACH (biter, rsi, sin, 0)
