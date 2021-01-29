@@ -68,7 +68,8 @@ static state_t **state_hash = NULL;
 static void
 allocate_itemsets (void)
 {
-  int i;
+  int i, r;
+  short *rhsp;
 
   /* Count the number of occurrences of all the symbols in RITEMS.
      Note that useless productions (hence useless nonterminals) are
@@ -77,11 +78,11 @@ allocate_itemsets (void)
   int count = 0;
   short *symbol_count = XCALLOC (short, nsyms + nuseless_nonterminals);
 
-  for (i = 0; i < nritems; ++i)
-    if (ritem[i] >= 0)
+  for (r = 1; r < nrules + 1; ++r)
+    for (rhsp = rules[r].rhs; *rhsp >= 0; ++rhsp)
       {
 	count++;
-	symbol_count[ritem[i]]++;
+	symbol_count[*rhsp]++;
       }
 
   /* See comments before new_itemsets.  All the vectors of items
