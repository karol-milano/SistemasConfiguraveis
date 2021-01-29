@@ -119,7 +119,7 @@ static int max (int a, int b)
 }
 
 static void
-print_counterexample (const counterexample *cex, FILE *out, const char *prefix)
+counterexample_print (const counterexample *cex, FILE *out, const char *prefix)
 {
   const bool flat = getenv ("YYFLAT");
   const char *example1_label
@@ -526,7 +526,7 @@ nonunifying_shift_path (state_item_list reduce_path, state_item *shift_conflict)
       for (gl_list_iterator_t it = gl_list_iterator (result);
            state_item_list_next (&it, &sip);
            )
-        print_state_item (sip, stderr, "");
+        state_item_print (sip, stderr, "");
     }
   return result;
 }
@@ -1267,7 +1267,7 @@ counterexample_report (state_item_number itm1, state_item_number itm2,
     : example_from_path (shift_reduce, itm2, shortest_path, next_sym);
 
   gl_list_free (shortest_path);
-  print_counterexample (cex, out, prefix);
+  counterexample_print (cex, out, prefix);
   free_counterexample (cex);
 }
 
@@ -1290,8 +1290,8 @@ counterexample_report_shift_reduce (state_item_number itm1, state_item_number it
   // In the report, print the items.
   if (out != stderr || trace_flag & trace_cex)
     {
-      print_state_item (&state_items[itm1], out, prefix);
-      print_state_item (&state_items[itm2], out, prefix);
+      state_item_print (&state_items[itm1], out, prefix);
+      state_item_print (&state_items[itm2], out, prefix);
     }
   counterexample_report (itm1, itm2, next_sym, true, out, prefix);
 }
@@ -1334,8 +1334,8 @@ counterexample_report_reduce_reduce (state_item_number itm1, state_item_number i
   // In the report, print the items.
   if (out != stderr || trace_flag & trace_cex)
     {
-      print_state_item (&state_items[itm1], out, prefix);
-      print_state_item (&state_items[itm2], out, prefix);
+      state_item_print (&state_items[itm1], out, prefix);
+      state_item_print (&state_items[itm2], out, prefix);
     }
   counterexample_report (itm1, itm2, bitset_first (conflict_syms),
                          false, out, prefix);
