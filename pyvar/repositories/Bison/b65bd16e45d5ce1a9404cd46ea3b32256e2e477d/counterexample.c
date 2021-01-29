@@ -1279,21 +1279,17 @@ counterexample_report_state (const state *s, FILE *out, const char *prefix)
   const reductions *reds = s->reductions;
   for (int i = 0; i < reds->num; ++i)
     {
-      rule *r1 = reds->rules[i];
+      const rule *r1 = reds->rules[i];
       const state_item_number c1 = find_state_item_number (r1, sn);
       for (int j = state_item_map[sn]; j < state_item_map[sn + 1]; ++j)
-        {
-          if (SI_DISABLED (j))
-            continue;
-          state_item *si = state_items + j;
-          item_number conf = *si->item;
-          if (item_number_is_symbol_number (conf)
+        if (!SI_DISABLED (j))
+          {
+            state_item *si = state_items + j;
+            item_number conf = *si->item;
+            if (item_number_is_symbol_number (conf)
               && bitset_test (reds->lookahead_tokens[i], conf))
-            {
               counterexample_report_shift_reduce (c1, j, conf, out, prefix);
-              break;
-            }
-        }
+          }
       for (int j = i+1; j < reds->num; ++j)
         {
           bitset conf = bitset_create (ntokens, BITSET_FIXED);
@@ -1302,20 +1298,18 @@ counterexample_report_state (const state *s, FILE *out, const char *prefix)
                                reds->lookahead_tokens[j]);
           if (!bitset_empty_p (conf))
             {
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
-                      counterexample_report_reduce_reduce (c1, k, conf, out, prefix);
-                      break;
-                    }
-                }
+              const rule *r2 = reds->rules[j];
+              for (int k = state_item_map[sn]; k < state_item_map[sn + 1]; ++k)
+                if (!SI_DISABLED (k))
+                  {
+                    state_item *si = state_items + k;
+                    const rule *r = item_rule (si->item);
+                    if (r == r2)
+                      {
+                        counterexample_report_reduce_reduce (c1, k, conf, out, prefix);
+                        break;
+                      }
+                  }
             }
           bitset_free (conf);
         }
