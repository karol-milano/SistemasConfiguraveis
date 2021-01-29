@@ -278,12 +278,12 @@ reduce_grammar_tables (void)
 static void
 nonterminals_reduce (void)
 {
-  int i, n;
+  token_number_t i, n;
 
   /* Map the nonterminals to their new index: useful first, useless
      afterwards.  Kept for later report.  */
 
-  short *nontermmap = XCALLOC (short, nvars) - ntokens;
+  token_number_t *nontermmap = XCALLOC (token_number_t, nvars) - ntokens;
   n = ntokens;
   for (i = ntokens; i < nsyms; i++)
     if (bitset_test (V, i))
@@ -308,7 +308,7 @@ nonterminals_reduce (void)
 
   for (i = 0; i < nritems; ++i)
     if (ISVAR (ritem[i]))
-      ritem[i] = nontermmap[ritem[i]];
+      ritem[i] = token_number_as_item_number (nontermmap[ritem[i]]);
 
   start_symbol = nontermmap[start_symbol];
 
