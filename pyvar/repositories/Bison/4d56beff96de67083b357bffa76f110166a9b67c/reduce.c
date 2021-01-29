@@ -426,7 +426,7 @@ reduce_grammar (void)
   useless_nonterminals ();
   inaccessable_symbols ();
 
-  reduced = (bool) (nuseless_nonterminals + nuseless_productions > 0);
+  reduced = (nuseless_nonterminals + nuseless_productions > 0);
   if (!reduced)
     return;
 
