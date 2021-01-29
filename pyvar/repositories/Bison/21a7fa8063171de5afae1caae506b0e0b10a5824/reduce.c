@@ -378,23 +378,23 @@ reduce_grammar (void)
   inaccessable_symbols ();
 
   /* Did we reduce something? */
-  if (!nuseless_nonterminals && !nuseless_productions)
-    return;
-
-  reduce_print ();
-
-  if (!bitset_test (N, accept->content->number - ntokens))
-    complain (&startsymbol_location, fatal,
-              _("start symbol %s does not derive any sentence"),
-              startsymbol->tag);
-
-  /* First reduce the nonterminals, as they renumber themselves in the
-     whole grammar.  If you change the order, nonterms would be
-     renumbered only in the reduced grammar.  */
-  if (nuseless_nonterminals)
-    nonterminals_reduce ();
-  if (nuseless_productions)
-    reduce_grammar_tables ();
+  if (nuseless_nonterminals || nuseless_productions)
+    {
+      reduce_print ();
+
+      if (!bitset_test (N, accept->content->number - ntokens))
+        complain (&startsymbol_location, fatal,
+                  _("start symbol %s does not derive any sentence"),
+                  startsymbol->tag);
+
+      /* First reduce the nonterminals, as they renumber themselves in the
+         whole grammar.  If you change the order, nonterms would be
+         renumbered only in the reduced grammar.  */
+      if (nuseless_nonterminals)
+        nonterminals_reduce ();
+      if (nuseless_productions)
+        reduce_grammar_tables ();
+    }
 
   if (trace_flag & trace_grammar)
     {
