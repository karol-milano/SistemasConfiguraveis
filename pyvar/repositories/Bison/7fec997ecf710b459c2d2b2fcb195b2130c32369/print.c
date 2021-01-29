@@ -507,17 +507,11 @@ print_results (void)
   print_terminal_symbols (out);
   print_nonterminal_symbols (out);
 
-  /* If the whole state item sets, not only the kernels, are wanted,
-     'closure' will be run, which needs memory allocation/deallocation.   */
-  if (report_flag & report_itemsets)
-    closure_new (nritems);
   /* Storage for print_reductions.  */
   no_reduce_set = bitset_create (ntokens, BITSET_FIXED);
   for (state_number i = 0; i < nstates; i++)
     print_state (out, states[i]);
   bitset_free (no_reduce_set);
-  if (report_flag & report_itemsets)
-    closure_free ();
 
   xfclose (out);
 }
