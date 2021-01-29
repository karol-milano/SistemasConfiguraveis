@@ -1284,8 +1284,7 @@ counterexample_report_state (const state *s, FILE *out, const char *prefix)
       for (int j = state_item_map[sn]; j < state_item_map[sn + 1]; ++j)
         if (!SI_DISABLED (j))
           {
-            state_item *si = state_items + j;
-            item_number conf = *si->item;
+            item_number conf = *state_items[j].item;
             if (item_number_is_symbol_number (conf)
               && bitset_test (reds->lookahead_tokens[i], conf))
               counterexample_report_shift_reduce (c1, j, conf, out, prefix);
@@ -1293,24 +1292,18 @@ counterexample_report_state (const state *s, FILE *out, const char *prefix)
       for (int j = i+1; j < reds->num; ++j)
         {
           bitset conf = bitset_create (ntokens, BITSET_FIXED);
+          const rule *r2 = reds->rules[j];
           bitset_intersection (conf,
                                reds->lookahead_tokens[i],
                                reds->lookahead_tokens[j]);
           if (!bitset_empty_p (conf))
-            {
-              const rule *r2 = reds->rules[j];
-              for (int k = state_item_map[sn]; k < state_item_map[sn + 1]; ++k)
-                if (!SI_DISABLED (k))
-                  {
-                    state_item *si = state_items + k;
-                    const rule *r = item_rule (si->item);
-                    if (r == r2)
-                      {
-                        counterexample_report_reduce_reduce (c1, k, conf, out, prefix);
-                        break;
-                      }
-                  }
-            }
+            for (int k = state_item_map[sn]; k < state_item_map[sn + 1]; ++k)
+              if (!SI_DISABLED (k)
+                  && item_rule (state_items[k].item) == r2)
+                {
+                  counterexample_report_reduce_reduce (c1, k, conf, out, prefix);
+                  break;
+                }
           bitset_free (conf);
         }
     }
