@@ -184,7 +184,7 @@ closure_new (unsigned n)
 void
 closure (item_number const *core, size_t n)
 {
-  if (trace_flag & trace_sets)
+  if (trace_flag & trace_closure)
     closure_print ("input", core, n);
 
   bitset_zero (ruleset);
@@ -221,7 +221,7 @@ closure (item_number const *core, size_t n)
       c++;
     }
 
-  if (trace_flag & trace_sets)
+  if (trace_flag & trace_closure)
     closure_print ("output", itemset, nitemset);
 }
 
