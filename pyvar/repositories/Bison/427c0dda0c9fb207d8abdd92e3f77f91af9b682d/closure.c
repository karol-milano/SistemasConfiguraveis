@@ -53,14 +53,14 @@ static void
 print_closure (const char *title, item_number_t *array, size_t size)
 {
   size_t i;
-  fprintf (stderr, _("Closure: %s\n"), title);
+  fprintf (stderr, "Closure: %s\n", title);
   for (i = 0; i < size; ++i)
     {
       item_number_t *rp;
       fprintf (stderr, "  %2d: .", array[i]);
       for (rp = &ritem[array[i]]; *rp >= 0; ++rp)
 	fprintf (stderr, " %s", symbols[*rp]->tag);
-      fprintf (stderr, _("  (rule %d)\n"), -*rp - 1);
+      fprintf (stderr, "  (rule %d)\n", -*rp - 1);
     }
   fputs ("\n\n", stderr);
 }
@@ -133,10 +133,10 @@ set_firsts (void)
       }
 
   if (trace_flag & trace_sets)
-    bitsetv_matrix_dump (stderr, _("RTC: Firsts Input"), firsts);
+    bitsetv_matrix_dump (stderr, "RTC: Firsts Input", firsts);
   bitsetv_reflexive_transitive_closure (firsts);
   if (trace_flag & trace_sets)
-    bitsetv_matrix_dump (stderr, _("RTC: Firsts Output"), firsts);
+    bitsetv_matrix_dump (stderr, "RTC: Firsts Output", firsts);
 
   if (trace_flag & trace_sets)
     print_firsts ();
@@ -200,7 +200,7 @@ closure (item_number_t *core, int n)
   bitset_iterator iter;
 
   if (trace_flag & trace_sets)
-    print_closure (_("input"), core, n);
+    print_closure ("input", core, n);
 
   bitset_zero (ruleset);
 
@@ -231,7 +231,7 @@ closure (item_number_t *core, int n)
     }
 
   if (trace_flag & trace_sets)
-    print_closure (_("output"), itemset, nritemset);
+    print_closure ("output", itemset, nritemset);
 }
 
 
