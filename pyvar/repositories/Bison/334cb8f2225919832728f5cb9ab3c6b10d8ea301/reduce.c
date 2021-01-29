@@ -295,7 +295,7 @@ nonterminals_reduce (void)
     free (symbols_sorted);
   }
 
-  /* Renumber non terminal numbers in the RHS of the rules.  LHS are
+  /* Update nonterminal numbers in the RHS of the rules.  LHS are
      pointers to the symbol structure, they don't need renumbering. */
   {
     for (rule_number r = 0; r < nrules; ++r)
