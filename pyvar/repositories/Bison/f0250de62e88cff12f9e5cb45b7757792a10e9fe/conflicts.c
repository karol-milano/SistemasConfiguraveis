@@ -203,9 +203,7 @@ solve_conflicts (void)
 
   conflicts = XCALLOC (char, nstates);
   shiftset = bitset_create (ntokens, BITSET_FIXED);
-  bitset_zero (shiftset);
   lookaheadset = bitset_create (ntokens, BITSET_FIXED);
-  bitset_zero (lookaheadset);
 
   for (i = 0; i < nstates; i++)
     set_conflicts (states[i]);
