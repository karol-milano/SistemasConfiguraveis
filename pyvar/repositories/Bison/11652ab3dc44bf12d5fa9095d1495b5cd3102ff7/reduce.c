@@ -215,7 +215,7 @@ inaccessable_symbols (void)
   nuseless_nonterminals = nvars - nuseful_nonterminals;
 
   /* A token that was used in %prec should not be warned about.  */
-  for (i = 1; i < nrules; i++)
+  for (i = 1; i < nrules + 1; i++)
     if (rules[i].precsym != 0)
       bitset_set (V1, rules[i].precsym);
 }
