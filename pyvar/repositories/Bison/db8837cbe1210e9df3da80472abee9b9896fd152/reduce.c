@@ -299,7 +299,7 @@ nonterminals_reduce (void)
 
   /* Shuffle elements of tables indexed by symbol number.  */
   {
-    bucket **symbols_sorted = XMALLOC (bucket *, nvars) - ntokens;
+    symbol_t **symbols_sorted = XMALLOC (symbol_t *, nvars) - ntokens;
 
     for (i = ntokens; i < nsyms; i++)
       symbols[i]->number = nontermmap[i];
