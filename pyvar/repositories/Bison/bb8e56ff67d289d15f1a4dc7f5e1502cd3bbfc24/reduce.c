@@ -299,9 +299,9 @@ nonterminals_reduce (void)
       {
         nontermmap[i - ntokens] = n++;
         if (symbols[i]->status != used)
-          complain_at (symbols[i]->location, Wother,
-                       _("nonterminal useless in grammar: %s"),
-                       symbols[i]->tag);
+          complain (&symbols[i]->location, Wother,
+                    _("nonterminal useless in grammar: %s"),
+                    symbols[i]->tag);
       }
 
 
@@ -383,14 +383,14 @@ static void
 reduce_print (void)
 {
   if (nuseless_nonterminals > 0)
-    complain (Wother, ngettext ("%d nonterminal useless in grammar",
-                                "%d nonterminals useless in grammar",
-                                nuseless_nonterminals),
+    complain (NULL, Wother, ngettext ("%d nonterminal useless in grammar",
+                                      "%d nonterminals useless in grammar",
+                                      nuseless_nonterminals),
               nuseless_nonterminals);
   if (nuseless_productions > 0)
-    complain (Wother, ngettext ("%d rule useless in grammar",
-                                "%d rules useless in grammar",
-                                nuseless_productions),
+    complain (NULL, Wother, ngettext ("%d rule useless in grammar",
+                                      "%d rules useless in grammar",
+                                      nuseless_productions),
               nuseless_productions);
 }
 
@@ -416,9 +416,9 @@ reduce_grammar (void)
   reduce_print ();
 
   if (!bitset_test (N, accept->number - ntokens))
-    complain_at (startsymbol_location, fatal,
-                 _("start symbol %s does not derive any sentence"),
-                 startsymbol->tag);
+    complain (&startsymbol_location, fatal,
+              _("start symbol %s does not derive any sentence"),
+              startsymbol->tag);
 
   /* First reduce the nonterminals, as they renumber themselves in the
      whole grammar.  If you change the order, nonterms would be
