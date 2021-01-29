@@ -132,7 +132,7 @@ eligible_state_items (state_item *target)
         continue;
       bitset_set (result, si - state_items);
       // search all reverse edges.
-      bitset rsi = si_revs[si - state_items];
+      bitset rsi = si->revs;
       bitset_iterator biter;
       state_item_number sin;
       BITSET_FOR_EACH (biter, rsi, sin, 0)
@@ -175,13 +175,13 @@ shortest_path_from_start (state_item_number target, symbol_number next_sym)
           finished = true;
           break;
         }
+      state_item *si = state_items + last;
       // Transitions don't change follow_L
-      if (si_trans[last] >= 0)
+      if (si->trans >= 0)
         {
-          state_item_number nextSI = si_trans[last];
-          if (bitset_test (eligible, nextSI))
+          if (bitset_test (eligible, si->trans))
             {
-              lssi *next = new_lssi (nextSI, n, n->lookahead, false);
+              lssi *next = new_lssi (si->trans, n, n->lookahead, false);
               append_lssi (next, visited, queue);
             }
         }
@@ -192,13 +192,11 @@ shortest_path_from_start (state_item_number target, symbol_number next_sym)
       // if the symbol is not nullable, follow_L is its FIRSTS set
       // if the symbol is nullable, follow_L is its FIRSTS set unioned with
       // this logic applied to the next symbol in the rule
-      bitset p = si_prods_lookup (last);
-      if (p)
+      if (si->prods)
         {
-          state_item si = state_items[last];
           // Compute follow_L as above
           bitset lookahead = bitset_create (nsyms, BITSET_FIXED);
-          item_number *pos = si.item + 1;
+          item_number *pos = si->item + 1;
           for (; !item_number_is_rule_number (*pos); ++pos)
             {
               item_number it = *pos;
@@ -221,7 +219,7 @@ shortest_path_from_start (state_item_number target, symbol_number next_sym)
           // Try all possible production steps within this parser state.
           bitset_iterator biter;
           state_item_number nextSI;
-          BITSET_FOR_EACH (biter, p, nextSI, 0)
+          BITSET_FOR_EACH (biter, si->prods, nextSI, 0)
             {
               if (!bitset_test (eligible, nextSI))
                 continue;
@@ -320,7 +318,7 @@ lssi_reverse_production (const state_item *si, bitset lookahead)
   // compatible with the lookahead.
   bitset_iterator biter;
   state_item_number sin;
-  BITSET_FOR_EACH (biter, si_revs[si - state_items], sin, 0)
+  BITSET_FOR_EACH (biter, si->revs, sin, 0)
   {
     state_item *prevsi = state_items + sin;
     if (!production_allowed (prevsi, si))
