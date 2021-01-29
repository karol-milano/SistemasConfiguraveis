@@ -259,13 +259,14 @@ reduce_grammar_tables (void)
 | Remove useless nonterminals.  |
 `------------------------------*/
 
+symbol_number *nterm_map = NULL;
+
 static void
 nonterminals_reduce (void)
 {
+  nterm_map = xnmalloc (nvars, sizeof *nterm_map);
   /* Map the nonterminals to their new index: useful first, useless
      afterwards.  Kept for later report.  */
-
-  symbol_number *nterm_map = xnmalloc (nvars, sizeof *nterm_map);
   {
     symbol_number n = ntokens;
     for (symbol_number i = ntokens; i < nsyms; ++i)
@@ -306,8 +307,6 @@ nonterminals_reduce (void)
 
   nsyms -= nuseless_nonterminals;
   nvars -= nuseless_nonterminals;
-
-  free (nterm_map);
 }
 
 
@@ -433,4 +432,6 @@ reduce_free (void)
   bitset_free (V);
   bitset_free (V1);
   bitset_free (P);
+  free (nterm_map);
+  nterm_map = NULL;
 }
