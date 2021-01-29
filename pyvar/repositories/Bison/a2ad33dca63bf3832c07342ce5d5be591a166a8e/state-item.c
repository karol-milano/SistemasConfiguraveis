@@ -144,7 +144,7 @@ init_state_items (void)
       for (int j = 0; j < s->nitems; ++j)
         {
           state_item_set (sidx, s, s->items[j]);
-          state_item *si = state_items + sidx;
+          state_item *si = &state_items[sidx];
           const rule *r = item_rule (si->item);
           if (rule_search_idx < red->num && red->rules[rule_search_idx] < r)
             ++rule_search_idx;
@@ -222,16 +222,14 @@ init_trans (void)
           // find the item in the destination state that corresponds
           // to the transition of item
           for (int k = 0; k < dst->nitems; ++k)
-            {
-              if (item + 1 == ritem + dst->items[k])
-                {
-                  state_item_number dstSI =
-                    state_item_index_lookup (dst->number, k);
+            if (item + 1 == ritem + dst->items[k])
+              {
+                state_item_number dstSI =
+                  state_item_index_lookup (dst->number, k);
 
-                  state_items[j].trans = dstSI;
-                  bitset_set (state_items[dstSI].revs, j);
-                  break;
-                }
+                state_items[j].trans = dstSI;
+                bitset_set (state_items[dstSI].revs, j);
+                break;
             }
         }
       hash_free (transition_set);
@@ -253,7 +251,7 @@ init_prods (void)
       for (int j = state_item_map[i] + s->nitems;
            j < state_item_map[i + 1]; ++j)
         {
-          state_item *src = state_items + j;
+          state_item *src = &state_items[j];
           item_number *item = src->item;
           symbol_number lhs = item_rule (item)->lhs->number;
           bitset itms = hash_pair_lookup (closure_map, lhs);
@@ -268,7 +266,7 @@ init_prods (void)
       // try to create a production edge.
       for (int j = state_item_map[i]; j < state_item_map[i + 1]; ++j)
         {
-          state_item *src = state_items + j;
+          state_item *src = &state_items[j];
           item_number item = *(src->item);
           // Skip reduce items and items with terminals after the dot
           if (item_number_is_rule_number (item) || ISTOKEN (item))
@@ -301,7 +299,7 @@ gen_lookaheads (void)
 {
   for (state_item_number i = 0; i < nstate_items; ++i)
     {
-      state_item *si = state_items + i;
+      state_item *si = &state_items[i];
       if (item_number_is_symbol_number (*(si->item)) || !si->lookahead)
         continue;
 
@@ -339,7 +337,7 @@ init_firsts (void)
   firsts = bitsetv_create (nnterms, nsyms, BITSET_FIXED);
   for (rule_number i = 0; i < nrules; ++i)
     {
-      rule *r = rules + i;
+      rule *r = &rules[i];
       item_number *n = r->rhs;
       // Iterate through nullable nonterminals to try to find a terminal.
       while (item_number_is_symbol_number (*n) && ISVAR (*n)
@@ -357,7 +355,7 @@ init_firsts (void)
       change = false;
       for (rule_number i = 0; i < nrules; ++i)
         {
-          rule *r = rules + i;
+          rule *r = &rules[i];
           symbol_number lhs = r->lhs->number;
           bitset f_lhs = FIRSTS (lhs);
           for (item_number *n = r->rhs;
@@ -401,7 +399,7 @@ prune_forward (const state_item *si)
       state_item *dsi = (state_item *) gl_list_get_at (queue, 0);
       gl_list_remove_at (queue, 0);
       if (dsi->trans >= 0)
-        gl_list_add_last (queue, state_items + dsi->trans);
+        gl_list_add_last (queue, &state_items[dsi->trans]);
 
       if (dsi->prods)
         {
@@ -409,7 +407,7 @@ prune_forward (const state_item *si)
           state_item_number sin;
           BITSET_FOR_EACH (biter, dsi->prods, sin, 0)
             {
-              const state_item *prod = state_items + sin;
+              const state_item *prod = &state_items[sin];
               bitset_reset (prod->revs, dsi - state_items);
               if (bitset_empty_p (prod->revs))
                 gl_list_add_last (queue, prod);
@@ -441,7 +439,7 @@ prune_backward (const state_item *si)
         {
           if (SI_DISABLED (sin))
             continue;
-          state_item *rev = state_items + sin;
+          state_item *rev = &state_items[sin];
           if (rev->prods)
             {
               bitset_reset (rev->prods, dsi - state_items);
@@ -466,7 +464,7 @@ prune_disabled_paths (void)
 {
   for (int i = nstate_items - 1; i >= 0; --i)
     {
-      state_item *si = state_items + i;
+      state_item *si = &state_items[i];
       if (si->trans == -1 && item_number_is_symbol_number (*si->item))
         {
           prune_forward (si);
@@ -496,7 +494,7 @@ state_items_report (void)
       printf ("State %d:\n", i);
       for (int j = state_item_map[i]; j < state_item_map[i + 1]; ++j)
         {
-          state_item *si = state_items + j;
+          state_item *si = &state_items[j];
           item_print (si->item, NULL, stdout);
           if (SI_DISABLED (j))
             {
@@ -508,7 +506,7 @@ state_items_report (void)
           if (si->trans >= 0)
             {
               fputs ("    -> ", stdout);
-              print_state_item (state_items + si->trans, stdout, "");
+              print_state_item (&state_items[si->trans], stdout, "");
             }
 
           bitset sets[2] = { si->prods, si->revs };
@@ -523,7 +521,7 @@ state_items_report (void)
                   BITSET_FOR_EACH (biter, b, sin, 0)
                     {
                       fputs (txt[seti], stdout);
-                      print_state_item (state_items + sin, stdout, "");
+                      print_state_item (&state_items[sin], stdout, "");
                     }
                 }
             }
@@ -565,7 +563,7 @@ state_items_free (void)
   for (int i = 0; i < nstate_items; ++i)
     if (!SI_DISABLED (i))
       {
-        state_item *si = state_items + i;
+        state_item *si = &state_items[i];
         if (si->prods)
           bitset_free (si->prods);
         bitset_free (si->revs);
