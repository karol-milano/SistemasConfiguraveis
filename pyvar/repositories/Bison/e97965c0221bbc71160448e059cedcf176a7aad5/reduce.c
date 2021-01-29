@@ -285,13 +285,12 @@ reduce_grammar_tables (void)
 static void
 nonterminals_reduce (void)
 {
-  symbol_number i, n;
-
   /* Map the nonterminals to their new index: useful first, useless
      afterwards.  Kept for later report.  */
 
   symbol_number *nontermmap = xnmalloc (nvars, sizeof *nontermmap);
-  n = ntokens;
+  symbol_number n = ntokens;
+  symbol_number i;
   for (i = ntokens; i < nsyms; i++)
     if (bitset_test (V, i))
       nontermmap[i - ntokens] = n++;
