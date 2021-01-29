@@ -93,7 +93,7 @@ useless_nonterminals (void)
   /* N is set as built.  Np is set being built this iteration. P is
      set of all productions which have a RHS all in N.  */
 
-  bitset Np = bitset_create (nvars, BITSET_FIXED);
+  bitset Np = bitset_create (nnterms, BITSET_FIXED);
 
   /* The set being computed is a set of nonterminals which can derive
      the empty string or strings consisting of all terminals. At each
@@ -201,7 +201,7 @@ inaccessable_symbols (void)
   int nuseful_nonterminals = 0;
   for (symbol_number i = ntokens; i < nsyms; ++i)
     nuseful_nonterminals += bitset_test (V, i);
-  nuseless_nonterminals = nvars - nuseful_nonterminals;
+  nuseless_nonterminals = nnterms - nuseful_nonterminals;
 
   /* A token that was used in %prec should not be warned about.  */
   for (rule_number r = 0; r < nrules; ++r)
@@ -263,7 +263,7 @@ symbol_number *nterm_map = NULL;
 static void
 nonterminals_reduce (void)
 {
-  nterm_map = xnmalloc (nvars, sizeof *nterm_map);
+  nterm_map = xnmalloc (nnterms, sizeof *nterm_map);
   /* Map the nonterminals to their new index: useful first, useless
      afterwards.  Kept for later report.  */
   {
@@ -284,7 +284,7 @@ nonterminals_reduce (void)
 
   /* Shuffle elements of tables indexed by symbol number.  */
   {
-    symbol **symbols_sorted = xnmalloc (nvars, sizeof *symbols_sorted);
+    symbol **symbols_sorted = xnmalloc (nnterms, sizeof *symbols_sorted);
     for (symbol_number i = ntokens; i < nsyms; ++i)
       symbols[i]->content->number = nterm_map[i - ntokens];
     for (symbol_number i = ntokens; i < nsyms; ++i)
@@ -305,7 +305,7 @@ nonterminals_reduce (void)
   }
 
   nsyms -= nuseless_nonterminals;
-  nvars -= nuseless_nonterminals;
+  nnterms -= nuseless_nonterminals;
 }
 
 
@@ -368,7 +368,7 @@ reduce_grammar (void)
 {
   /* Allocate the global sets used to compute the reduced grammar */
 
-  N = bitset_create (nvars, BITSET_FIXED);
+  N = bitset_create (nnterms, BITSET_FIXED);
   P =  bitset_create (nrules, BITSET_FIXED);
   V = bitset_create (nsyms, BITSET_FIXED);
   V1 = bitset_create (nsyms, BITSET_FIXED);
@@ -401,7 +401,7 @@ reduce_grammar (void)
 
       fprintf (stderr, "reduced %s defines %d terminals, %d nonterminals"
                ", and %d productions.\n",
-               grammar_file, ntokens, nvars, nrules);
+               grammar_file, ntokens, nnterms, nrules);
     }
 }
 
