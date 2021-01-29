@@ -103,7 +103,6 @@ useless_nonterminals (void)
      set of all productions which have a RHS all in N.  */
 
   Np = bitset_create (nvars, BITSET_FIXED);
-  bitset_zero (Np);
 
 
   /* The set being computed is a set of nonterminals which can derive
@@ -175,9 +174,7 @@ inaccessable_symbols (void)
      user can know.  */
 
   Vp = bitset_create (nsyms, BITSET_FIXED);
-  bitset_zero (Vp);
   Pp = bitset_create (nrules + 1, BITSET_FIXED);
-  bitset_zero (Pp);
 
   /* If the start symbol isn't useful, then nothing will be useful. */
   if (bitset_test (N, start_symbol - ntokens))
@@ -495,13 +492,9 @@ reduce_grammar (void)
   /* Allocate the global sets used to compute the reduced grammar */
 
   N = bitset_create (nvars, BITSET_FIXED);
-  bitset_zero (N);
   P =  bitset_create (nrules + 1, BITSET_FIXED);
-  bitset_zero (P);
   V = bitset_create (nsyms, BITSET_FIXED);
-  bitset_zero (V);
   V1 = bitset_create (nsyms, BITSET_FIXED);
-  bitset_zero (V1);
 
   useless_nonterminals ();
   inaccessable_symbols ();
