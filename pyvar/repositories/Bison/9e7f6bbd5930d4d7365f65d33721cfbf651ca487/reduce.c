@@ -383,9 +383,9 @@ nonterminals_reduce (void)
 	rule_table[i].precsym = nontermmap[rule_table[i].precsym];
     }
 
-  for (r = ritem; *r; r++)
-    if (ISVAR (*r))
-      *r = nontermmap[*r];
+  for (i = 0; i < nritems; ++i)
+    if (ISVAR (ritem[i]))
+      ritem[i] = nontermmap[ritem[i]];
 
   start_symbol = nontermmap[start_symbol];
 
