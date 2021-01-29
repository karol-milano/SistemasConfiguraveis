@@ -306,11 +306,17 @@ nonterminals_reduce (void)
     free (symbols_sorted + ntokens);
   }
 
-  for (i = 0; i < nritems; ++i)
-    if (ISVAR (ritem[i]))
-      ritem[i] = token_number_as_item_number (nontermmap[ritem[i]]);
-
-  start_symbol = nontermmap[start_symbol];
+  {
+    int r;
+    for (r = 1; r < nrules + 1; ++r)
+      {
+	item_number_t *rhsp;
+	for (rhsp = rules[r].rhs; *rhsp >= 0; ++rhsp)
+	  if (ISVAR (*rhsp))
+	    *rhsp =  token_number_as_item_number (nontermmap[*rhsp]);
+      }
+    start_symbol = nontermmap[start_symbol];
+  }
 
   nsyms -= nuseless_nonterminals;
   nvars -= nuseless_nonterminals;
