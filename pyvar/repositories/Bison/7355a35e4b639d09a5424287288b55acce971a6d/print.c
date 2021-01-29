@@ -510,14 +510,14 @@ print_results (void)
   /* If the whole state item sets, not only the kernels, are wanted,
      'closure' will be run, which needs memory allocation/deallocation.   */
   if (report_flag & report_itemsets)
-    new_closure (nritems);
+    closure_new (nritems);
   /* Storage for print_reductions.  */
   no_reduce_set = bitset_create (ntokens, BITSET_FIXED);
   for (state_number i = 0; i < nstates; i++)
     print_state (out, states[i]);
   bitset_free (no_reduce_set);
   if (report_flag & report_itemsets)
-    free_closure ();
+    closure_free ();
 
   xfclose (out);
 }
