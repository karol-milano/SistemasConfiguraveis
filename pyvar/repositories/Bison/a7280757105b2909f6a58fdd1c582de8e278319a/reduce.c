@@ -163,9 +163,9 @@ inaccessable_symbols (void)
   Pp = bitset_create (nrules, BITSET_FIXED);
 
   /* If the start symbol isn't useful, then nothing will be useful. */
-  if (bitset_test (N, accept->number - ntokens))
+  if (bitset_test (N, accept->content->number - ntokens))
     {
-      bitset_set (V, accept->number);
+      bitset_set (V, accept->content->number);
 
       while (1)
         {
@@ -196,9 +196,9 @@ inaccessable_symbols (void)
   V = Vp;
 
   /* Tokens 0, 1, and 2 are internal to Bison.  Consider them useful. */
-  bitset_set (V, endtoken->number);             /* end-of-input token */
-  bitset_set (V, errtoken->number);             /* error token */
-  bitset_set (V, undeftoken->number);           /* some undefined token */
+  bitset_set (V, endtoken->content->number);   /* end-of-input token */
+  bitset_set (V, errtoken->content->number);   /* error token */
+  bitset_set (V, undeftoken->content->number); /* some undefined token */
 
   bitset_free (P);
   P = Pp;
@@ -298,7 +298,7 @@ nonterminals_reduce (void)
     if (!bitset_test (V, i))
       {
         nontermmap[i - ntokens] = n++;
-        if (symbols[i]->status != used)
+        if (symbols[i]->content->status != used)
           complain (&symbols[i]->location, Wother,
                     _("nonterminal useless in grammar: %s"),
                     symbols[i]->tag);
@@ -310,7 +310,7 @@ nonterminals_reduce (void)
     symbol **symbols_sorted = xnmalloc (nvars, sizeof *symbols_sorted);
 
     for (i = ntokens; i < nsyms; i++)
-      symbols[i]->number = nontermmap[i - ntokens];
+      symbols[i]->content->number = nontermmap[i - ntokens];
     for (i = ntokens; i < nsyms; i++)
       symbols_sorted[nontermmap[i - ntokens] - ntokens] = symbols[i];
     for (i = ntokens; i < nsyms; i++)
@@ -328,7 +328,7 @@ nonterminals_reduce (void)
             *rhsp =  symbol_number_as_item_number (nontermmap[*rhsp
                                                               - ntokens]);
       }
-    accept->number = nontermmap[accept->number - ntokens];
+    accept->content->number = nontermmap[accept->content->number - ntokens];
   }
 
   nsyms -= nuseless_nonterminals;
@@ -415,7 +415,7 @@ reduce_grammar (void)
 
   reduce_print ();
 
-  if (!bitset_test (N, accept->number - ntokens))
+  if (!bitset_test (N, accept->content->number - ntokens))
     complain (&startsymbol_location, fatal,
               _("start symbol %s does not derive any sentence"),
               startsymbol->tag);
