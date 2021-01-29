@@ -275,7 +275,8 @@ nonterminals_reduce (void)
       if (!bitset_test (V, i))
         {
           nterm_map[i - ntokens] = n++;
-          if (symbols[i]->content->status != used)
+          if (symbols[i]->content->status != used
+              && symbols[i] != acceptsymbol)
             complain (&symbols[i]->location, Wother,
                       _("nonterminal useless in grammar: %s"),
                       symbols[i]->tag);
@@ -381,10 +382,18 @@ reduce_grammar (void)
     {
       reduce_print ();
 
-      if (!bitset_test (N, acceptsymbol->content->number - ntokens))
-        complain (&startsymbol_loc, fatal,
-                  _("start symbol %s does not derive any sentence"),
-                  startsymbol->tag);
+      // Check that start symbols have non-empty languages.
+      bool failure = false;
+      for (symbol_list *list = start_symbols; list; list = list->next)
+        if (!bitset_test (N, list->content.sym->content->number - ntokens))
+          {
+            failure = true;
+            complain (&list->sym_loc, complaint,
+                      _("start symbol %s does not derive any sentence"),
+                      list->content.sym->tag);
+          }
+      if (failure)
+        exit (EXIT_FAILURE);
 
       /* First reduce the nonterminals, as they renumber themselves in the
          whole grammar.  If you change the order, nonterms would be
