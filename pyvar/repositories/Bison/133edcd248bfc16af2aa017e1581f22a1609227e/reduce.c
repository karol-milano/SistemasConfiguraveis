@@ -52,8 +52,8 @@ static bitset V;
    'useless', but no warning should be issued).  */
 static bitset V1;
 
-unsigned nuseless_productions;
-unsigned nuseless_nonterminals;
+int nuseless_productions;
+int nuseless_nonterminals;
 
 #define bitset_swap(Lhs, Rhs)                   \
   do {                                          \
@@ -195,10 +195,10 @@ inaccessable_symbols (void)
   bitset_free (P);
   P = Pp;
 
-  unsigned nuseful_productions = bitset_count (P);
+  int nuseful_productions = bitset_count (P);
   nuseless_productions = nrules - nuseful_productions;
 
-  unsigned nuseful_nonterminals = 0;
+  int nuseful_nonterminals = 0;
   for (symbol_number i = ntokens; i < nsyms; ++i)
     nuseful_nonterminals += bitset_test (V, i);
   nuseless_nonterminals = nvars - nuseful_nonterminals;
