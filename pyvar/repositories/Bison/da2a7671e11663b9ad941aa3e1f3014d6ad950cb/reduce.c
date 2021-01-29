@@ -247,7 +247,7 @@ reduce_grammar_tables (void)
   {
     int useful = 0;
     int useless = nrules - nuseless_productions;
-    rule *rules_sorted = MALLOC (rules_sorted, nrules);
+    rule *rules_sorted = xnmalloc (nrules, sizeof *rules_sorted);
     rule_number r;
     for (r = 0; r < nrules; ++r)
       rules_sorted[rules[r].useful ? useful++ : useless++] = rules[r];
@@ -291,7 +291,7 @@ nonterminals_reduce (void)
   /* Map the nonterminals to their new index: useful first, useless
      afterwards.  Kept for later report.  */
 
-  symbol_number *nontermmap = CALLOC (nontermmap, nvars);
+  symbol_number *nontermmap = xnmalloc (nvars, sizeof *nontermmap);
   n = ntokens;
   for (i = ntokens; i < nsyms; i++)
     if (bitset_test (V, i))
@@ -307,7 +307,7 @@ nonterminals_reduce (void)
 
   /* Shuffle elements of tables indexed by symbol number.  */
   {
-    symbol **symbols_sorted = MALLOC (symbols_sorted, nvars);
+    symbol **symbols_sorted = xnmalloc (nvars, sizeof *symbols_sorted);
 
     for (i = ntokens; i < nsyms; i++)
       symbols[i]->number = nontermmap[i - ntokens];
