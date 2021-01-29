@@ -361,7 +361,8 @@ set_conflicts (state *s, symbol **errors)
      check for shift-reduce conflict, and try to resolve using
      precedence.  */
   for (int i = 0; i < reds->num; ++i)
-    if (reds->rules[i]->prec && reds->rules[i]->prec->prec
+    if (reds->rules[i]->prec
+        && reds->rules[i]->prec->prec
         && !bitset_disjoint_p (reds->lookahead_tokens[i], lookahead_set))
       resolve_sr_conflict (s, i, errors, &nerrs);
 
@@ -629,7 +630,8 @@ static state_item_number
 find_state_item_number (const rule *r, state_number sn)
 {
   for (int i = state_item_map[sn]; i < state_item_map[sn + 1]; ++i)
-    if (item_number_as_rule_number (*state_items[i].item) == r->number)
+    if (!SI_DISABLED (i)
+        && item_number_as_rule_number (*state_items[i].item) == r->number)
       return i;
   abort ();
 }
@@ -649,8 +651,8 @@ report_state_counterexamples (const state *s)
             continue;
           state_item *si = state_items + j;
           item_number conf = *si->item;
-          if (item_number_is_symbol_number (conf) &&
-              bitset_test (reds->lookahead_tokens[i], conf))
+          if (item_number_is_symbol_number (conf)
+              && bitset_test (reds->lookahead_tokens[i], conf))
             {
               counterexample_report_shift_reduce (c1, j, conf);
               break;
@@ -668,6 +670,8 @@ report_state_counterexamples (const state *s)
               for (int k = state_item_map[sn];
                    k < state_item_map[sn + 1]; ++k)
                 {
+                  if (SI_DISABLED (k))
+                    continue;
                   state_item *si = state_items + k;
                   const rule *r = item_rule (si->item);
                   if (r == r2)
