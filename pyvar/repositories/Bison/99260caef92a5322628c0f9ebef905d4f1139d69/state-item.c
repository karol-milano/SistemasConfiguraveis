@@ -35,10 +35,6 @@ size_t nstate_items;
 state_item_number *state_item_map;
 state_item *state_items;
 
-state_item_number *si_trans;
-bitsetv si_revs;
-Hash_table *si_prods;
-
 // hash functions for index -> bitset hash maps
 typedef struct
 {
@@ -96,14 +92,6 @@ hash_pair_insert (Hash_table *tab, int key, bitset val)
   assert (res == hp);
 }
 
-static void
-hash_pair_remove (Hash_table *tab, int key)
-{
-  hash_pair probe;
-  probe.key = key;
-  hash_delete (tab, &probe);
-}
-
 /* A state_item from a state's id and the offset of the item within
    the state. */
 state_item *
@@ -118,7 +106,9 @@ state_item_set (state_item_number sidx, const state *s, item_number off)
   state_items[sidx].state = s;
   state_items[sidx].item = &ritem[off];
   state_items[sidx].lookahead = NULL;
-  si_trans[sidx] = -1;
+  state_items[sidx].trans = -1;
+  state_items[sidx].prods = NULL;
+  state_items[sidx].revs = bitset_create (nstate_items, BITSET_SPARSE);
 }
 
 /**
@@ -144,8 +134,6 @@ init_state_items (void)
     }
   state_item_map = xnmalloc (nstates + 1, sizeof (state_item_number));
   state_items = xnmalloc (nstate_items, sizeof (state_item));
-  si_trans = xnmalloc (nstate_items, sizeof (state_item_number));
-  si_revs = bitsetv_create (nstate_items, nstate_items, BITSET_SPARSE);
   state_item_number sidx = 0;
   for (int i = 0; i < nstates; ++i)
     {
@@ -240,8 +228,8 @@ init_trans (void)
                   state_item_number dstSI =
                     state_item_index_lookup (dst->number, k);
 
-                  si_trans[j] = dstSI;
-                  bitset_set (si_revs[dstSI], j);
+                  state_items[j].trans = dstSI;
+                  bitset_set (state_items[dstSI].revs, j);
                   break;
                 }
             }
@@ -250,16 +238,9 @@ init_trans (void)
     }
 }
 
-bitset
-si_prods_lookup (state_item_number si)
-{
-  return hash_pair_lookup (si_prods, si);
-}
-
 static void
 init_prods (void)
 {
-  si_prods = hash_pair_table_create (nstate_items);
   for (int i = 0; i < nstates; ++i)
     {
       state *s = states[i];
@@ -299,13 +280,13 @@ init_prods (void)
               bitset copy = bitset_create (nstate_items, BITSET_SPARSE);
               bitset_copy (copy, lb);
               // update prods.
-              hash_pair_insert (si_prods, j, copy);
+              state_items[j].prods = copy;
 
               // update revs.
               bitset_iterator biter;
               state_item_number prod;
               BITSET_FOR_EACH (biter, copy, prod, 0)
-                bitset_set (si_revs[prod], j);
+                bitset_set (state_items[prod].revs, j);
             }
         }
       hash_free (closure_map);
@@ -340,7 +321,7 @@ gen_lookaheads (void)
           prev->lookahead = lookahead;
           if (SI_TRANSITION (prev))
             {
-              bitset rsi = si_revs[prev - state_items];
+              bitset rsi = state_items[prev - state_items].revs;
               bitset_iterator biter;
               state_item_number sin;
               BITSET_FOR_EACH (biter, rsi, sin, 0)
@@ -400,8 +381,11 @@ init_firsts (void)
 static inline void
 disable_state_item (state_item_number sin)
 {
-  si_trans[sin] = -2;
-  hash_pair_remove (si_prods, sin);
+  state_item *si = state_items + sin;
+  si->trans = -2;
+  bitset_free (si->revs);
+  if (si->prods)
+    bitset_free (si->prods);
 }
 
 /*
@@ -414,10 +398,10 @@ prune_disabled_paths (void)
   for (int i = nstate_items - 1; i >= 0; --i)
     {
       state_item *si = state_items + i;
-      if (si_trans[i] == -1 && item_number_is_symbol_number (*si->item))
+      if (si->trans == -1 && item_number_is_symbol_number (*si->item))
         {
           // disable the transitions out of i
-          for (state_item_number j = si_trans[i]; j != -1; j = si_trans[j])
+          for (state_item_number j = si->trans; j != -1; j = state_items[j].trans)
             disable_state_item (j);
 
           gl_list_t queue =
@@ -432,9 +416,8 @@ prune_disabled_paths (void)
               const state_item *prev = gl_list_get_at (queue, 0);
               gl_list_remove_at (queue, 0);
               state_item_number prev_num = prev - state_items;
-              disable_state_item (prev_num);
 
-              bitset rsi = si_revs[prev_num];
+              bitset rsi = prev->revs;
               bitset_iterator biter;
               state_item_number sin;
               BITSET_FOR_EACH (biter, rsi, sin, 0)
@@ -443,11 +426,12 @@ prune_disabled_paths (void)
                   gl_list_add_first (queue, &state_items[sin]);
                 else
                   {
-                    bitset p = si_prods_lookup (sin);
+                    bitset p = state_items[sin].prods;
                     if (p)
                       bitset_reset (p, prev_num);
                   }
               }
+              disable_state_item (prev_num);
             }
           gl_list_free (queue);
         }
@@ -463,7 +447,7 @@ print_state_item (const state_item *si, FILE *out)
 }
 
 /**
- * Report set counts and the state_item graph if trace is enabled
+ * Report the state_item graph
  */
 static void
 state_items_report (void)
@@ -474,15 +458,16 @@ state_items_report (void)
       printf ("State %d:\n", i);
       for (int j = state_item_map[i]; j < state_item_map[i + 1]; ++j)
         {
-          item_print (state_items[j].item, NULL, stdout);
+          state_item *si = state_items + j;
+          item_print (si->item, NULL, stdout);
           puts ("");
-          if (si_trans[j] >= 0)
+          if (si->trans >= 0)
             {
               fputs ("    -> ", stdout);
-              print_state_item (state_items + si_trans[j], stdout);
+              print_state_item (state_items + si->trans, stdout);
             }
 
-          bitset sets[2] = { si_prods_lookup (j), si_revs[j] };
+          bitset sets[2] = { si->prods, si->revs };
           const char *txt[2] = { "    => ", "    <- " };
           for (int seti = 0; seti < 2; ++seti)
             {
@@ -533,9 +518,14 @@ state_items_init (void)
 void
 state_items_free (void)
 {
-  hash_free (si_prods);
-  bitsetv_free (si_revs);
-  free (si_trans);
+  for (int i = 0; i < nstate_items; ++i)
+    if (!SI_DISABLED(i))
+      {
+        state_item *si = state_items + i;
+        if (si->prods)
+          bitset_free (si->prods);
+        bitset_free (si->revs);
+      }
   free (state_items);
   bitsetv_free (firsts);
 }
