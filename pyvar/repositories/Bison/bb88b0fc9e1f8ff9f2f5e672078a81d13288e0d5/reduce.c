@@ -487,10 +487,13 @@ reduce_grammar (void)
     fatal (_("Start symbol %s does not derive any sentence"),
 	   quotearg_style (escape_quoting_style, symbols[start_symbol]->tag));
 
-  if (nuseless_productions > 0)
-    reduce_grammar_tables ();
+  /* First reduce the nonterminals, as they renumber themselves in the
+     whole grammar.  If you change the order, nonterms would be
+     renumbered only in the reduced grammar.  */
   if (nuseless_nonterminals > 0)
     nonterminals_reduce ();
+  if (nuseless_productions > 0)
+    reduce_grammar_tables ();
 
   if (trace_flag)
     {
