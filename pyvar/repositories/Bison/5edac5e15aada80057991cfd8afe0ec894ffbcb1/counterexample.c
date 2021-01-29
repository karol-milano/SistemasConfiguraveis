@@ -100,10 +100,8 @@ free_counterexample (counterexample *cex)
 }
 
 static void
-print_counterexample (counterexample *cex)
+print_counterexample (counterexample *cex, FILE *out)
 {
-  FILE *out = stderr;
-
   fprintf (out, "%-20s ", cex->unifying ? _("Example") : _("First example"));
   derivation_print_leaves (cex->d1, out);
   fprintf (out, "%-20s ", _("First derivation"));
@@ -1175,7 +1173,8 @@ counterexample_free (void)
  */
 static void
 counterexample_report (state_item_number itm1, state_item_number itm2,
-                       symbol_number next_sym, bool shift_reduce)
+                       symbol_number next_sym, bool shift_reduce,
+                       FILE *out)
 {
   // Compute the shortest lookahead-sensitive path and associated sets of
   // parser states.
@@ -1204,26 +1203,24 @@ counterexample_report (state_item_number itm1, state_item_number itm2,
     : example_from_path (shift_reduce, itm2, shortest_path, next_sym);
 
   gl_list_free (shortest_path);
-  print_counterexample (cex);
+  print_counterexample (cex, out);
   free_counterexample (cex);
 }
 
-void
+static void
 counterexample_report_shift_reduce (state_item_number itm1, state_item_number itm2,
-                                    symbol_number next_sym)
+                                    symbol_number next_sym, FILE *out)
 {
-  FILE *out = stderr;
   fprintf (out, _("Shift/reduce conflict on token %s:\n"), symbols[next_sym]->tag);
   print_state_item (&state_items[itm1], out);
   print_state_item (&state_items[itm2], out);
-  counterexample_report (itm1, itm2, next_sym, true);
+  counterexample_report (itm1, itm2, next_sym, true, out);
 }
 
-void
+static void
 counterexample_report_reduce_reduce (state_item_number itm1, state_item_number itm2,
-                                     bitset conflict_syms)
+                                     bitset conflict_syms, FILE *out)
 {
-  FILE *out = stderr;
   {
     fputs (ngettext ("Reduce/reduce conflict on token",
                      "Reduce/reduce conflict on tokens",
@@ -1240,5 +1237,65 @@ counterexample_report_reduce_reduce (state_item_number itm1, state_item_number i
   }
   print_state_item (&state_items[itm1], out);
   print_state_item (&state_items[itm2], out);
-  counterexample_report (itm1, itm2, bitset_first (conflict_syms), false);
+  counterexample_report (itm1, itm2, bitset_first (conflict_syms), false, out);
+}
+
+static state_item_number
+find_state_item_number (const rule *r, state_number sn)
+{
+  for (int i = state_item_map[sn]; i < state_item_map[sn + 1]; ++i)
+    if (!SI_DISABLED (i)
+        && item_number_as_rule_number (*state_items[i].item) == r->number)
+      return i;
+  abort ();
+}
+
+void
+counterexample_report_state (const state *s, FILE *out)
+{
+  const state_number sn = s->number;
+  const reductions *reds = s->reductions;
+  for (int i = 0; i < reds->num; ++i)
+    {
+      rule *r1 = reds->rules[i];
+      const state_item_number c1 = find_state_item_number (r1, sn);
+      for (int j = state_item_map[sn]; j < state_item_map[sn + 1]; ++j)
+        {
+          if (SI_DISABLED (j))
+            continue;
+          state_item *si = state_items + j;
+          item_number conf = *si->item;
+          if (item_number_is_symbol_number (conf)
+              && bitset_test (reds->lookahead_tokens[i], conf))
+            {
+              counterexample_report_shift_reduce (c1, j, conf, out);
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
+                  if (SI_DISABLED (k))
+                    continue;
+                  state_item *si = state_items + k;
+                  const rule *r = item_rule (si->item);
+                  if (r == r2)
+                    {
+                      counterexample_report_reduce_reduce (c1, k, conf, out);
+                      break;
+                    }
+                }
+            }
+          bitset_free (conf);
+        }
+    }
 }
