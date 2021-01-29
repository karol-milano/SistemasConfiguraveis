@@ -457,6 +457,6 @@ lalr (void)
   compute_FOLLOWS ();
   compute_lookaheads ();
 
-  if (trace_flag)
+  if (trace_flag & trace_sets)
     lookaheads_print (stderr);
 }
