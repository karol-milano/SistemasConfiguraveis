@@ -100,17 +100,21 @@ free_counterexample (counterexample *cex)
 }
 
 static void
-print_counterexample (counterexample *cex, FILE *out)
+print_counterexample (counterexample *cex, FILE *out, const char *prefix)
 {
-  fprintf (out, "  %-20s ", cex->unifying ? _("Example") : _("First example"));
-  derivation_print_leaves (cex->d1, out);
-  fprintf (out, "  %-20s ", _("First derivation"));
-  derivation_print (cex->d1, out);
-
-  fprintf (out, "  %-20s ", cex->unifying ? _("Example") : _("Second example"));
-  derivation_print_leaves (cex->d2, out);
-  fprintf (out, "  %-20s ", _("Second derivation"));
-  derivation_print (cex->d2, out);
+  fprintf (out, "  %s%-20s ",
+           prefix, cex->unifying ? _("Example") : _("First example"));
+  derivation_print_leaves (cex->d1, out, prefix);
+  fprintf (out, "  %s%-20s ",
+           prefix, _("First derivation"));
+  derivation_print (cex->d1, out, prefix);
+
+  fprintf (out, "  %s%-20s ",
+           prefix, cex->unifying ? _("Example") : _("Second example"));
+  derivation_print_leaves (cex->d2, out, prefix);
+  fprintf (out, "  %s%-20s ",
+           prefix, _("Second derivation"));
+  derivation_print (cex->d2, out, prefix);
 
   fputc ('\n', out);
 }
@@ -469,7 +473,7 @@ nonunifying_shift_path (gl_list_t reduce_path, state_item *shift_conflict)
       for (gl_list_iterator_t it = gl_list_iterator (result);
            state_item_list_next (&it, &sip);
            )
-        print_state_item (sip, stderr);
+        print_state_item (sip, stderr, "");
     }
   return result;
 }
@@ -1175,7 +1179,7 @@ counterexample_free (void)
 static void
 counterexample_report (state_item_number itm1, state_item_number itm2,
                        symbol_number next_sym, bool shift_reduce,
-                       FILE *out)
+                       FILE *out, const char *prefix)
 {
   // Compute the shortest lookahead-sensitive path and associated sets of
   // parser states.
@@ -1204,23 +1208,32 @@ counterexample_report (state_item_number itm1, state_item_number itm2,
     : example_from_path (shift_reduce, itm2, shortest_path, next_sym);
 
   gl_list_free (shortest_path);
-  print_counterexample (cex, out);
+  print_counterexample (cex, out, prefix);
   free_counterexample (cex);
 }
 
 static void
 counterexample_report_shift_reduce (state_item_number itm1, state_item_number itm2,
-                                    symbol_number next_sym, FILE *out)
+                                    symbol_number next_sym,
+                                    FILE *out, const char *prefix)
 {
+  fputs (prefix, out);
   fprintf (out, _("Shift/reduce conflict on token %s:\n"), symbols[next_sym]->tag);
-  counterexample_report (itm1, itm2, next_sym, true, out);
+  if (*prefix)
+    {
+      print_state_item (&state_items[itm1], out, prefix);
+      print_state_item (&state_items[itm2], out, prefix);
+    }
+  counterexample_report (itm1, itm2, next_sym, true, out, prefix);
 }
 
 static void
 counterexample_report_reduce_reduce (state_item_number itm1, state_item_number itm2,
-                                     bitset conflict_syms, FILE *out)
+                                     bitset conflict_syms,
+                                     FILE *out, const char *prefix)
 {
   {
+    fputs (prefix, out);
     fputs (ngettext ("Reduce/reduce conflict on token",
                      "Reduce/reduce conflict on tokens",
                      bitset_count (conflict_syms)), out);
@@ -1234,7 +1247,12 @@ counterexample_report_reduce_reduce (state_item_number itm1, state_item_number i
       }
     fputs (_(":\n"), out);
   }
-  counterexample_report (itm1, itm2, bitset_first (conflict_syms), false, out);
+  if (*prefix)
+    {
+      print_state_item (&state_items[itm1], out, prefix);
+      print_state_item (&state_items[itm2], out, prefix);
+    }
+  counterexample_report (itm1, itm2, bitset_first (conflict_syms), false, out, prefix);
 }
 
 static state_item_number
@@ -1248,7 +1266,7 @@ find_state_item_number (const rule *r, state_number sn)
 }
 
 void
-counterexample_report_state (const state *s, FILE *out)
+counterexample_report_state (const state *s, FILE *out, const char *prefix)
 {
   const state_number sn = s->number;
   const reductions *reds = s->reductions;
@@ -1265,7 +1283,7 @@ counterexample_report_state (const state *s, FILE *out)
           if (item_number_is_symbol_number (conf)
               && bitset_test (reds->lookahead_tokens[i], conf))
             {
-              counterexample_report_shift_reduce (c1, j, conf, out);
+              counterexample_report_shift_reduce (c1, j, conf, out, prefix);
               break;
             }
         }
@@ -1287,7 +1305,7 @@ counterexample_report_state (const state *s, FILE *out)
                   const rule *r = item_rule (si->item);
                   if (r == r2)
                     {
-                      counterexample_report_reduce_reduce (c1, k, conf, out);
+                      counterexample_report_reduce_reduce (c1, k, conf, out, prefix);
                       break;
                     }
                 }
