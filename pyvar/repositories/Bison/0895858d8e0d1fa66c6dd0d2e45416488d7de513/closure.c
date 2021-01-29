@@ -104,21 +104,21 @@ print_fderives (void)
   fprintf (stderr, "\n\n");
 }
 
-/*------------------------------------------------------------------.
-| Set FIRSTS to be an NVARS array of NVARS bitsets indicating which |
-| items can represent the beginning of the input corresponding to   |
-| which other items.                                                |
-|                                                                   |
-| For example, if some rule expands symbol 5 into the sequence of   |
-| symbols 8 3 20, the symbol 8 can be the beginning of the data for |
-| symbol 5, so the bit [8 - ntokens] in first[5 - ntokens] (= FIRST |
-| (5)) is set.                                                      |
-`------------------------------------------------------------------*/
+/*-------------------------------------------------------------------.
+| Set FIRSTS to be an NNTERMS array of NNTERMS bitsets indicating    |
+| which items can represent the beginning of the input corresponding |
+| to which other items.                                              |
+|                                                                    |
+| For example, if some rule expands symbol 5 into the sequence of    |
+| symbols 8 3 20, the symbol 8 can be the beginning of the data for  |
+| symbol 5, so the bit [8 - ntokens] in first[5 - ntokens] (= FIRST  |
+| (5)) is set.                                                       |
+`-------------------------------------------------------------------*/
 
 static void
 set_firsts (void)
 {
-  firsts = bitsetv_create (nvars, nvars, BITSET_FIXED);
+  firsts = bitsetv_create (nnterms, nnterms, BITSET_FIXED);
 
   for (symbol_number i = ntokens; i < nsyms; ++i)
     for (symbol_number j = 0; derives[i - ntokens][j]; ++j)
@@ -139,8 +139,8 @@ set_firsts (void)
 }
 
 /*-------------------------------------------------------------------.
-| Set FDERIVES to an NVARS by NRULES matrix of bits indicating which |
-| rules can help derive the beginning of the data for each           |
+| Set FDERIVES to an NNTERMS by NRULES matrix of bits indicating     |
+| which rules can help derive the beginning of the data for each     |
 | nonterminal.                                                       |
 |                                                                    |
 | For example, if symbol 5 can be derived as the sequence of symbols |
@@ -151,7 +151,7 @@ set_firsts (void)
 static void
 set_fderives (void)
 {
-  fderives = bitsetv_create (nvars, nrules, BITSET_FIXED);
+  fderives = bitsetv_create (nnterms, nrules, BITSET_FIXED);
 
   set_firsts ();
 
