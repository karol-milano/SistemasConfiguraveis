@@ -626,72 +626,12 @@ conflicts_total_count (void)
   return count_sr_conflicts () + count_rr_conflicts ();
 }
 
-static state_item_number
-find_state_item_number (const rule *r, state_number sn)
-{
-  for (int i = state_item_map[sn]; i < state_item_map[sn + 1]; ++i)
-    if (!SI_DISABLED (i)
-        && item_number_as_rule_number (*state_items[i].item) == r->number)
-      return i;
-  abort ();
-}
-
-static void
-report_state_counterexamples (const state *s)
-{
-  const state_number sn = s->number;
-  const reductions *reds = s->reductions;
-  for (int i = 0; i < reds->num; ++i)
-    {
-      rule *r1 = reds->rules[i];
-      const state_item_number c1 = find_state_item_number (r1, sn);
-      for (int j = state_item_map[sn]; j < state_item_map[sn + 1]; ++j)
-        {
-          if (SI_DISABLED (j))
-            continue;
-          state_item *si = state_items + j;
-          item_number conf = *si->item;
-          if (item_number_is_symbol_number (conf)
-              && bitset_test (reds->lookahead_tokens[i], conf))
-            {
-              counterexample_report_shift_reduce (c1, j, conf);
-              break;
-            }
-        }
-      for (int j = i+1; j < reds->num; ++j)
-        {
-          bitset conf = bitset_create (ntokens, BITSET_FIXED);
-          bitset_intersection (conf,
-                               reds->lookahead_tokens[i],
-                               reds->lookahead_tokens[j]);
-          if (!bitset_empty_p (conf))
-            {
-              rule *r2 = reds->rules[j];
-              for (int k = state_item_map[sn];
-                   k < state_item_map[sn + 1]; ++k)
-                {
-                  if (SI_DISABLED (k))
-                    continue;
-                  state_item *si = state_items + k;
-                  const rule *r = item_rule (si->item);
-                  if (r == r2)
-                    {
-                      counterexample_report_reduce_reduce (c1, k, conf);
-                      break;
-                    }
-                }
-            }
-          bitset_free (conf);
-        }
-    }
-}
-
 static void
 report_counterexamples (void)
 {
   for (state_number sn = 0; sn < nstates; ++sn)
     if (conflicts[sn])
-      report_state_counterexamples (states[sn]);
+      counterexample_report_state (states[sn], stderr);
 }
 
 /*------------------------------------------------.
