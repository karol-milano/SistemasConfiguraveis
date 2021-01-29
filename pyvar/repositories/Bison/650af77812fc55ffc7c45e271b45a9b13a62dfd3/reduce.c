@@ -442,10 +442,11 @@ reduce_token_unused_in_grammar (symbol_number i)
 }
 
 bool
-reduce_nonterminal_useless_in_grammar (symbol_number i)
+reduce_nonterminal_useless_in_grammar (const sym_content *sym)
 {
-  aver (ntokens <= i && i < nsyms + nuseless_nonterminals);
-  return nsyms <= i;
+  symbol_number n = sym->number;
+  aver (ntokens <= n && n < nsyms + nuseless_nonterminals);
+  return nsyms <= n;
 }
 
 /*-----------------------------------------------------------.
