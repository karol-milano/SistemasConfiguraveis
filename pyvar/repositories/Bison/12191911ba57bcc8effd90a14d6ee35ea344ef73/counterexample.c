@@ -1274,7 +1274,7 @@ counterexample_report_reduce_reduce (state_item_number itm1, state_item_number i
 static state_item_number
 find_state_item_number (const rule *r, state_number sn)
 {
-  for (int i = state_item_map[sn]; i < state_item_map[sn + 1]; ++i)
+  for (state_item_number i = state_item_map[sn]; i < state_item_map[sn + 1]; ++i)
     if (!SI_DISABLED (i)
         && item_number_as_rule_number (*state_items[i].item) == r->number)
       return i;
@@ -1290,13 +1290,13 @@ counterexample_report_state (const state *s, FILE *out, const char *prefix)
     {
       const rule *r1 = reds->rules[i];
       const state_item_number c1 = find_state_item_number (r1, sn);
-      for (int j = state_item_map[sn]; j < state_item_map[sn + 1]; ++j)
-        if (!SI_DISABLED (j))
+      for (state_item_number c2 = state_item_map[sn]; c2 < state_item_map[sn + 1]; ++c2)
+        if (!SI_DISABLED (c2))
           {
-            item_number conf = *state_items[j].item;
+            item_number conf = *state_items[c2].item;
             if (item_number_is_symbol_number (conf)
                 && bitset_test (reds->lookahead_tokens[i], conf))
-              counterexample_report_shift_reduce (c1, j, conf, out, prefix);
+              counterexample_report_shift_reduce (c1, c2, conf, out, prefix);
           }
       for (int j = i+1; j < reds->num; ++j)
         {
@@ -1306,11 +1306,11 @@ counterexample_report_state (const state *s, FILE *out, const char *prefix)
                                reds->lookahead_tokens[i],
                                reds->lookahead_tokens[j]);
           if (!bitset_empty_p (conf))
-            for (int k = state_item_map[sn]; k < state_item_map[sn + 1]; ++k)
-              if (!SI_DISABLED (k)
-                  && item_rule (state_items[k].item) == r2)
+            for (state_item_number c2 = state_item_map[sn]; c2 < state_item_map[sn + 1]; ++c2)
+              if (!SI_DISABLED (c2)
+                  && item_rule (state_items[c2].item) == r2)
                 {
-                  counterexample_report_reduce_reduce (c1, k, conf, out, prefix);
+                  counterexample_report_reduce_reduce (c1, c2, conf, out, prefix);
                   break;
                 }
           bitset_free (conf);
