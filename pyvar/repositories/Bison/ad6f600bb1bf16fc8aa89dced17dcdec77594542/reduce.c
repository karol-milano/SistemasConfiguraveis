@@ -160,9 +160,9 @@ inaccessable_symbols (void)
   bitset Pp = bitset_create (nrules, BITSET_FIXED);
 
   /* If the start symbol isn't useful, then nothing will be useful. */
-  if (bitset_test (N, accept->content->number - ntokens))
+  if (bitset_test (N, acceptsymbol->content->number - ntokens))
     {
-      bitset_set (V, accept->content->number);
+      bitset_set (V, acceptsymbol->content->number);
 
       while (1)
         {
@@ -301,7 +301,7 @@ nonterminals_reduce (void)
       for (item_number *rhsp = rules[r].rhs; 0 <= *rhsp; ++rhsp)
         if (ISVAR (*rhsp))
           *rhsp = symbol_number_as_item_number (nterm_map[*rhsp - ntokens]);
-    accept->content->number = nterm_map[accept->content->number - ntokens];
+    acceptsymbol->content->number = nterm_map[acceptsymbol->content->number - ntokens];
   }
 
   nsyms -= nuseless_nonterminals;
@@ -381,7 +381,7 @@ reduce_grammar (void)
     {
       reduce_print ();
 
-      if (!bitset_test (N, accept->content->number - ntokens))
+      if (!bitset_test (N, acceptsymbol->content->number - ntokens))
         complain (&startsymbol_loc, fatal,
                   _("start symbol %s does not derive any sentence"),
                   startsymbol->tag);
