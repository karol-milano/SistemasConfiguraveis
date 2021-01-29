@@ -76,17 +76,29 @@ typedef struct
 {
   derivation *d1;
   derivation *d2;
+  bool shift_reduce;
   bool unifying;
   bool timeout;
 } counterexample;
 
 static counterexample *
 new_counterexample (derivation *d1, derivation *d2,
+                    bool shift_reduce,
                     bool u, bool t)
 {
   counterexample *res = xmalloc (sizeof *res);
-  res->d1 = d1;
-  res->d2 = d2;
+  res->shift_reduce = shift_reduce;
+  if (shift_reduce)
+    {
+      // Display the shift first.
+      res->d1 = d2;
+      res->d2 = d1;
+    }
+  else
+    {
+      res->d1 = d1;
+      res->d2 = d2;
+    }
   res->unifying = u;
   res->timeout = t;
   return res;
@@ -107,7 +119,7 @@ print_counterexample (counterexample *cex, FILE *out, const char *prefix)
            prefix, cex->unifying ? _("Example") : _("First example"));
   derivation_print_leaves (cex->d1, out, prefix);
   fprintf (out, "  %s%-20s ",
-           prefix, _("First derivation"));
+           prefix, cex->shift_reduce ? _("Shift derivation") : _("First derivation"));
   derivation_print (cex->d1, out, prefix);
 
   // If we output to the terminal (via stderr) and we have color
@@ -120,7 +132,7 @@ print_counterexample (counterexample *cex, FILE *out, const char *prefix)
       derivation_print_leaves (cex->d2, out, prefix);
     }
   fprintf (out, "  %s%-20s ",
-           prefix, _("Second derivation"));
+           prefix, cex->shift_reduce ? _("Reduce derivation") : _("Second derivation"));
   derivation_print (cex->d2, out, prefix);
 
   fputc ('\n', out);
@@ -506,7 +518,7 @@ example_from_path (bool shift_reduce,
     : shortest_path_from_start (itm2, next_sym);
   derivation *deriv2 = complete_diverging_example (next_sym, path_2, NULL);
   gl_list_free (path_2);
-  return new_counterexample (deriv1, deriv2, false, true);
+  return new_counterexample (deriv1, deriv2, shift_reduce, false, true);
 }
 
 /*
@@ -619,7 +631,8 @@ ss_set_parse_state (search_state *ss, int idx, parse_state *ps)
  */
 static counterexample *
 complete_diverging_examples (search_state *ss,
-                             symbol_number next_sym)
+                             symbol_number next_sym,
+                             bool shift_reduce)
 {
   derivation *new_derivs[2];
   for (int i = 0; i < 2; ++i)
@@ -630,7 +643,8 @@ complete_diverging_examples (search_state *ss,
       new_derivs[i] = complete_diverging_example (next_sym, sitems, derivs);
       gl_list_free (sitems);
     }
-  return new_counterexample (new_derivs[0], new_derivs[1], false, true);
+  return new_counterexample (new_derivs[0], new_derivs[1],
+                             shift_reduce, false, true);
 }
 
 /*
@@ -1111,7 +1125,7 @@ unifying_example (state_item_number itm1,
                     {
                       // Once we have two derivations for the same symbol,
                       // we've found a unifying counterexample.
-                      cex = new_counterexample (d1, d2, true, false);
+                      cex = new_counterexample (d1, d2, shift_reduce, true, false);
                       derivation_retain (d1);
                       derivation_retain (d2);
                       goto cex_search_end;
@@ -1149,7 +1163,7 @@ cex_search_end:;
       // If a search state from Stage 3 is available, use it
       // to construct a more compact nonunifying counterexample.
       if (stage3result)
-        cex = complete_diverging_examples (stage3result, next_sym);
+        cex = complete_diverging_examples (stage3result, next_sym, shift_reduce);
       // Otherwise, construct a nonunifying counterexample that
       // begins from the start state using the shortest
       // lookahead-sensitive path to the reduce item.
@@ -1226,6 +1240,8 @@ counterexample_report (state_item_number itm1, state_item_number itm2,
   free_counterexample (cex);
 }
 
+
+// ITM1 denotes a shift, ITM2 a reduce.
 static void
 counterexample_report_shift_reduce (state_item_number itm1, state_item_number itm2,
                                     symbol_number next_sym,
