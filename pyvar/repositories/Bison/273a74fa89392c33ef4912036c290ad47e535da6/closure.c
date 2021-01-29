@@ -132,13 +132,13 @@ set_firsts (void)
 	  bitset_set (FIRSTS (i), symbol - ntokens);
       }
 
-  if (trace_flag)
+  if (trace_flag & trace_sets)
     bitsetv_matrix_dump (stderr, "RTC: Firsts Input", firsts);
   bitsetv_reflexive_transitive_closure (firsts);
-  if (trace_flag)
+  if (trace_flag & trace_sets)
     bitsetv_matrix_dump (stderr, "RTC: Firsts Output", firsts);
 
-  if (trace_flag)
+  if (trace_flag & trace_sets)
     print_firsts ();
 }
 
@@ -168,7 +168,7 @@ set_fderives (void)
 	for (k = 0; derives[j][k] >= 0; ++k)
 	  bitset_set (FDERIVES (i), derives[j][k]);
 
-  if (trace_flag)
+  if (trace_flag & trace_sets)
     print_fderives ();
 
   bitsetv_free (firsts);
@@ -199,7 +199,7 @@ closure (item_number_t *core, int n)
 
   bitset_iterator iter;
 
-  if (trace_flag)
+  if (trace_flag & trace_sets)
     print_closure ("input", core, n);
 
   bitset_zero (ruleset);
@@ -230,7 +230,7 @@ closure (item_number_t *core, int n)
       c++;
     }
 
-  if (trace_flag)
+  if (trace_flag & trace_sets)
     print_closure ("output", itemset, nritemset);
 }
 
