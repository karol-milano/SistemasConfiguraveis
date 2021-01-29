@@ -72,9 +72,8 @@ print_core (FILE *out, state_t *state)
   item_number_t *sitems = state->items;
   int snritems   = state->nitems;
 
-  /* New experimental feature: if TRACE_FLAGS output all the items of
-     a state, not only its kernel.  */
-  if (trace_flag)
+  /* Output all the items of a state, not only its kernel.  */
+  if (report_flag & report_itemsets)
     {
       closure (sitems, snritems);
       sitems = itemset;
@@ -105,8 +104,8 @@ print_core (FILE *out, state_t *state)
 	  for (/* Nothing */; *sp >= 0; ++sp)
 	    fprintf (out, " %s", escape (symbols[*sp]->tag));
 
-	  /* Experimental feature: display the lookaheads. */
-	  if (trace_flag && state->nlookaheads)
+	  /* Display the lookaheads?  */
+	  if (report_flag & report_lookaheads)
 	    {
 	      int j, k;
 	      int nlookaheads = 0;
@@ -513,10 +512,9 @@ print_results (void)
 
   print_grammar (out);
 
-  /* New experimental feature: output all the items of a state, not
-     only its kernel.  Requires to run closure, which need memory
-     allocation/deallocation.  */
-  if (trace_flag)
+  /* If the whole state item sets, not only the kernels, are wanted,
+     `closure' will be run, which needs memory allocation/deallocation.   */
+  if (report_flag & report_itemsets)
     new_closure (nritems);
   /* Storage for print_reductions.  */
   shiftset =  bitset_create (ntokens, BITSET_FIXED);
@@ -525,7 +523,7 @@ print_results (void)
     print_state (out, states[i]);
   bitset_free (shiftset);
   bitset_free (lookaheadset);
-  if (trace_flag)
+  if (report_flag & report_itemsets)
     free_closure ();
 
   xfclose (out);
