@@ -492,9 +492,7 @@ print_results (void)
     new_closure (nritems);
   /* Storage for print_reductions.  */
   shiftset =  bitset_create (ntokens, BITSET_FIXED);
-  bitset_zero (shiftset);
   lookaheadset = bitset_create (ntokens, BITSET_FIXED);
-  bitset_zero (lookaheadset);
   for (i = 0; i < nstates; i++)
     print_state (out, states[i]);
   bitset_free (shiftset);
