@@ -25,6 +25,7 @@
 
 #include "complain.h"
 #include "conflicts.h"
+#include "counterexample.h"
 #include "files.h"
 #include "getargs.h"
 #include "gram.h"
@@ -624,6 +625,72 @@ conflicts_total_count (void)
   return count_sr_conflicts () + count_rr_conflicts ();
 }
 
+static void
+report_state_counterexamples (const state *s)
+{
+  const state_number sn = s->number;
+  const reductions *reds = s->reductions;
+  for (int i = 0; i < reds->num; ++i)
+    {
+      rule *r1 = reds->rules[i];
+      state_item_number c1;
+      for (int j = state_item_map[sn];
+           j < state_item_map[sn + 1]; ++j)
+        {
+          if (item_number_as_rule_number (*state_items[j].item) == r1->number)
+            {
+              c1 = j;
+              break;
+            }
+        }
+
+      for (int j = state_item_map[sn];
+           j < state_item_map[sn + 1]; ++j)
+        {
+          if (SI_DISABLED (j))
+            continue;
+          state_item *si = state_items + j;
+          item_number conf = *si->item;
+          if (item_number_is_symbol_number (conf) &&
+              bitset_test (reds->lookahead_tokens[i], conf))
+            {
+              counterexample_report_shift_reduce (c1, j, conf);
+              break;
+            }
+        }
+      for (int j = i+1; j < reds->num; ++j)
+        {
+          bitset conf = bitset_create (ntokens, BITSET_FIXED);
+          bitset_intersection (conf,
+                               reds->lookahead_tokens[i],
+                               reds->lookahead_tokens[j]);
+          if (!bitset_empty_p (conf))
+            {
+              rule *r2 = reds->rules[j];
+              for (int k = state_item_map[sn];
+                   k < state_item_map[sn + 1]; ++k)
+                {
+                  state_item *si = state_items + k;
+                  const rule *r = item_rule (si->item);
+                  if (r == r2)
+                    {
+                      counterexample_report_reduce_reduce (c1, k, conf);
+                      break;
+                    }
+                }
+            }
+        }
+    }
+}
+
+static void
+report_counterexamples (void)
+{
+  for (state_number sn = 0; sn < nstates; ++sn)
+    if (conflicts[sn])
+      report_state_counterexamples (states[sn]);
+}
+
 /*------------------------------.
 | Reporting per-rule conflicts. |
 `------------------------------*/
@@ -653,6 +720,8 @@ rule_conflicts_print (void)
                       r->user_number, rr, expected_rr);
         }
     }
+  if (warning_is_enabled (Wcounterexample))
+    report_counterexamples ();
 }
 
 /*---------------------------------.
