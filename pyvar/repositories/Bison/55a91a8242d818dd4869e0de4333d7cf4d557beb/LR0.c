@@ -183,8 +183,7 @@ new_itemsets (state *s)
   if (trace_flag & trace_automaton)
     fprintf (stderr, "Entering new_itemsets, state = %d\n", s->number);
 
-  for (i = 0; i < nsyms; i++)
-    kernel_size[i] = 0;
+  memset (kernel_size, 0, nsyms * sizeof *kernel_size);
 
   nshifts = 0;
 
