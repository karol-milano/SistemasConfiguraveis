@@ -165,9 +165,9 @@ inaccessable_symbols (void)
   Pp = bitset_create (nrules + 1, BITSET_FIXED);
 
   /* If the start symbol isn't useful, then nothing will be useful. */
-  if (bitset_test (N, start_symbol - ntokens))
+  if (bitset_test (N, axiom->number - ntokens))
     {
-      bitset_set (V, start_symbol);
+      bitset_set (V, axiom->number);
 
       while (1)
 	{
@@ -315,7 +315,7 @@ nonterminals_reduce (void)
 	  if (ISVAR (*rhsp))
 	    *rhsp =  symbol_number_as_item_number (nontermmap[*rhsp]);
       }
-    start_symbol = nontermmap[start_symbol];
+    axiom->number = nontermmap[axiom->number];
   }
 
   nsyms -= nuseless_nonterminals;
@@ -435,9 +435,9 @@ reduce_grammar (void)
 
   reduce_print ();
 
-  if (!bitset_test (N, start_symbol - ntokens))
+  if (!bitset_test (N, axiom->number - ntokens))
     fatal (_("Start symbol %s does not derive any sentence"),
-	   quotearg_style (escape_quoting_style, symbols[start_symbol]->tag));
+	   quotearg_style (escape_quoting_style, symbols[axiom->number]->tag));
 
   /* First reduce the nonterminals, as they renumber themselves in the
      whole grammar.  If you change the order, nonterms would be
