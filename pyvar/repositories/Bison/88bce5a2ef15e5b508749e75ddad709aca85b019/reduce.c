@@ -161,9 +161,9 @@ inaccessable_symbols (void)
   Pp = bitset_create (nrules, BITSET_FIXED);
 
   /* If the start symbol isn't useful, then nothing will be useful. */
-  if (bitset_test (N, axiom->number - ntokens))
+  if (bitset_test (N, accept->number - ntokens))
     {
-      bitset_set (V, axiom->number);
+      bitset_set (V, accept->number);
 
       while (1)
 	{
@@ -194,7 +194,7 @@ inaccessable_symbols (void)
   V = Vp;
 
   /* Tokens 0, 1, and 2 are internal to Bison.  Consider them useful. */
-  bitset_set (V, eoftoken->number);		/* end-of-input token */
+  bitset_set (V, endtoken->number);		/* end-of-input token */
   bitset_set (V, errtoken->number);		/* error token */
   bitset_set (V, undeftoken->number);		/* some undefined token */
 
@@ -333,7 +333,7 @@ nonterminals_reduce (void)
 	  if (ISVAR (*rhsp))
 	    *rhsp =  symbol_number_as_item_number (nontermmap[*rhsp]);
       }
-    axiom->number = nontermmap[axiom->number];
+    accept->number = nontermmap[accept->number];
   }
 
   nsyms -= nuseless_nonterminals;
@@ -438,7 +438,7 @@ reduce_grammar (void)
 
   reduce_print ();
 
-  if (!bitset_test (N, axiom->number - ntokens))
+  if (!bitset_test (N, accept->number - ntokens))
     fatal_at (startsymbol_location,
 	      _("start symbol %s does not derive any sentence"),
 	      startsymbol->tag);
