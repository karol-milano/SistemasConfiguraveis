@@ -492,10 +492,10 @@ example_from_path (bool shift_reduce,
 {
   derivation *deriv1 =
     complete_diverging_example (next_sym, shortest_path, NULL);
-  gl_list_t path_2 = shift_reduce ? nonunifying_shift_path (shortest_path,
-                                                            &state_items
-                                                            [itm2]) :
-    shortest_path_from_start (itm2, next_sym);
+  gl_list_t path_2
+    = shift_reduce
+    ? nonunifying_shift_path (shortest_path, &state_items [itm2])
+    : shortest_path_from_start (itm2, next_sym);
   derivation *deriv2 = complete_diverging_example (next_sym, path_2, NULL);
   gl_list_free (path_2);
   return new_counterexample (deriv1, deriv2, false, true);
@@ -883,20 +883,26 @@ has_common_prefix (const item_number *itm1, const item_number *itm2)
 }
 
 /*
- * Calculate the start and end locations of an item in ritem.
+ * The start and end locations of an item in ritem.
  */
-static void
-item_rule_bounds (const item_number *item, const item_number **start,
-                  const item_number **end)
+static const item_number *
+item_rule_start (const item_number *item)
+{
+  const item_number *res = NULL;
+  for (res = item;
+       ritem < res && item_number_is_symbol_number (*(res - 1));
+       --res)
+    continue;
+  return res;
+}
+
+static const item_number *
+item_rule_end (const item_number *item)
 {
-  const item_number *s, *e;
-  for (s = item;
-       s > ritem && item_number_is_symbol_number (*(s - 1));
-       --s);
-  *start = s;
-
-  for (e = item; item_number_is_symbol_number (*e); ++e);
-  *end = e;
+  const item_number *res = NULL;
+  for (res = item; item_number_is_symbol_number (*res); ++res)
+    continue;
+  return res;
 }
 
 /*
@@ -944,14 +950,14 @@ generate_next_states (search_state *ss, state_item *conflict1,
   // One of the states requires a reduction
   else
     {
-      const item_number *rhs1, *rhe1;
-      item_rule_bounds (si1->item, &rhs1, &rhe1);
+      const item_number *rhs1 = item_rule_start (si1->item);
+      const item_number *rhe1 = item_rule_end (si1->item);
       int len1 = rhe1 - rhs1;
       int size1 = parse_state_length (ps1);
       bool ready1 = si1reduce && len1 < size1;
 
-      const item_number *rhs2, *rhe2;
-      item_rule_bounds (si2->item, &rhs2, &rhe2);
+      const item_number *rhs2 = item_rule_start (si2->item);
+      const item_number *rhe2 = item_rule_end (si2->item);
       int len2 = rhe2 - rhs2;
       int size2 = parse_state_length (ps2);
       bool ready2 = si2reduce && len2 < size2;
@@ -961,7 +967,7 @@ generate_next_states (search_state *ss, state_item *conflict1,
         {
           gl_list_t reduced1 = reduction_step (ss, conflict1->item, 0, len1);
           gl_list_iterator_t iter = gl_list_iterator (reduced1);
-          search_state *red1;
+          search_state *red1 = NULL;
           if (ready2)
             {
               gl_list_add_last (reduced1, ss);
@@ -1174,12 +1180,10 @@ counterexample_report (state_item_number itm1, state_item_number itm2,
         bitset_set (rpp_set, si->state->number);
     }
   time_t t = time (NULL);
-  counterexample *cex = difftime (t,
-                                  cumulative_time) <
-    CUMULATIVE_TIME_LIMIT ? unifying_example (itm1, itm2, shift_reduce,
-                                              shortest_path,
-                                              next_sym) :
-    example_from_path (shift_reduce, itm2, shortest_path, next_sym);
+  counterexample *cex
+    = difftime (t, cumulative_time) < CUMULATIVE_TIME_LIMIT
+    ? unifying_example (itm1, itm2, shift_reduce, shortest_path, next_sym)
+    : example_from_path (shift_reduce, itm2, shortest_path, next_sym);
 
   gl_list_free (shortest_path);
   print_counterexample (cex);
