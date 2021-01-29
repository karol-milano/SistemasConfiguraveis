@@ -265,16 +265,16 @@ nonterminals_reduce (void)
   /* Map the nonterminals to their new index: useful first, useless
      afterwards.  Kept for later report.  */
 
-  symbol_number *nontermmap = xnmalloc (nvars, sizeof *nontermmap);
+  symbol_number *nterm_map = xnmalloc (nvars, sizeof *nterm_map);
   {
     symbol_number n = ntokens;
     for (symbol_number i = ntokens; i < nsyms; ++i)
       if (bitset_test (V, i))
-        nontermmap[i - ntokens] = n++;
+        nterm_map[i - ntokens] = n++;
     for (symbol_number i = ntokens; i < nsyms; ++i)
       if (!bitset_test (V, i))
         {
-          nontermmap[i - ntokens] = n++;
+          nterm_map[i - ntokens] = n++;
           if (symbols[i]->content->status != used)
             complain (&symbols[i]->location, Wother,
                       _("nonterminal useless in grammar: %s"),
@@ -282,32 +282,32 @@ nonterminals_reduce (void)
         }
   }
 
-
   /* Shuffle elements of tables indexed by symbol number.  */
   {
     symbol **symbols_sorted = xnmalloc (nvars, sizeof *symbols_sorted);
     for (symbol_number i = ntokens; i < nsyms; ++i)
-      symbols[i]->content->number = nontermmap[i - ntokens];
+      symbols[i]->content->number = nterm_map[i - ntokens];
     for (symbol_number i = ntokens; i < nsyms; ++i)
-      symbols_sorted[nontermmap[i - ntokens] - ntokens] = symbols[i];
+      symbols_sorted[nterm_map[i - ntokens] - ntokens] = symbols[i];
     for (symbol_number i = ntokens; i < nsyms; ++i)
       symbols[i] = symbols_sorted[i - ntokens];
     free (symbols_sorted);
   }
 
+  /* Renumber non terminal numbers in the RHS of the rules.  LHS are
+     pointers to the symbol structure, they don't need renumbering. */
   {
     for (rule_number r = 0; r < nrules; ++r)
       for (item_number *rhsp = rules[r].rhs; 0 <= *rhsp; ++rhsp)
         if (ISVAR (*rhsp))
-          *rhsp =  symbol_number_as_item_number (nontermmap[*rhsp
-                                                            - ntokens]);
-    accept->content->number = nontermmap[accept->content->number - ntokens];
+          *rhsp = symbol_number_as_item_number (nterm_map[*rhsp - ntokens]);
+    accept->content->number = nterm_map[accept->content->number - ntokens];
   }
 
   nsyms -= nuseless_nonterminals;
   nvars -= nuseless_nonterminals;
 
-  free (nontermmap);
+  free (nterm_map);
 }
 
 
