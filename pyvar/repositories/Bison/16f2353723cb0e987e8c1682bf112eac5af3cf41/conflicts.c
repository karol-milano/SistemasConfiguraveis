@@ -625,6 +625,15 @@ conflicts_total_count (void)
   return count_sr_conflicts () + count_rr_conflicts ();
 }
 
+static state_item_number
+find_state_item_number (const rule *r, state_number sn)
+{
+  for (int i = state_item_map[sn]; i < state_item_map[sn + 1]; ++i)
+    if (item_number_as_rule_number (*state_items[i].item) == r->number)
+      return i;
+  abort ();
+}
+
 static void
 report_state_counterexamples (const state *s)
 {
@@ -633,19 +642,8 @@ report_state_counterexamples (const state *s)
   for (int i = 0; i < reds->num; ++i)
     {
       rule *r1 = reds->rules[i];
-      state_item_number c1;
-      for (int j = state_item_map[sn];
-           j < state_item_map[sn + 1]; ++j)
-        {
-          if (item_number_as_rule_number (*state_items[j].item) == r1->number)
-            {
-              c1 = j;
-              break;
-            }
-        }
-
-      for (int j = state_item_map[sn];
-           j < state_item_map[sn + 1]; ++j)
+      const state_item_number c1 = find_state_item_number (r1, sn);
+      for (int j = state_item_map[sn]; j < state_item_map[sn + 1]; ++j)
         {
           if (SI_DISABLED (j))
             continue;
