@@ -278,12 +278,12 @@ reduce_grammar_tables (void)
 static void
 nonterminals_reduce (void)
 {
-  token_number_t i, n;
+  symbol_number_t i, n;
 
   /* Map the nonterminals to their new index: useful first, useless
      afterwards.  Kept for later report.  */
 
-  token_number_t *nontermmap = XCALLOC (token_number_t, nvars) - ntokens;
+  symbol_number_t *nontermmap = XCALLOC (symbol_number_t, nvars) - ntokens;
   n = ntokens;
   for (i = ntokens; i < nsyms; i++)
     if (bitset_test (V, i))
@@ -313,7 +313,7 @@ nonterminals_reduce (void)
 	item_number_t *rhsp;
 	for (rhsp = rules[r].rhs; *rhsp >= 0; ++rhsp)
 	  if (ISVAR (*rhsp))
-	    *rhsp =  token_number_as_item_number (nontermmap[*rhsp]);
+	    *rhsp =  symbol_number_as_item_number (nontermmap[*rhsp]);
       }
     start_symbol = nontermmap[start_symbol];
   }
