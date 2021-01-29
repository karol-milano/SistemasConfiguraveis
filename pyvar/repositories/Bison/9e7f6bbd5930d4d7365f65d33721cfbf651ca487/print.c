@@ -495,7 +495,7 @@ print_results (void)
      only its kernel.  Requires to run closure, which need memory
      allocation/deallocation.  */
   if (trace_flag)
-    new_closure (nitems);
+    new_closure (nritems);
   /* Storage for print_reductions.  */
   shiftset = XCALLOC (unsigned, tokensetsize);
   lookaheadset = XCALLOC (unsigned, tokensetsize);
