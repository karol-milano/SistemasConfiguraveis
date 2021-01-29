@@ -299,9 +299,9 @@ nonterminals_reduce (void)
       {
         nontermmap[i - ntokens] = n++;
         if (symbols[i]->status != used)
-          warn_at (symbols[i]->location,
-                   _("nonterminal useless in grammar: %s"),
-                   symbols[i]->tag);
+          complain_at (symbols[i]->location, Wother,
+                       _("nonterminal useless in grammar: %s"),
+                       symbols[i]->tag);
       }
 
 
@@ -383,15 +383,15 @@ static void
 reduce_print (void)
 {
   if (nuseless_nonterminals > 0)
-    warn (ngettext ("%d nonterminal useless in grammar",
-                    "%d nonterminals useless in grammar",
-                    nuseless_nonterminals),
-          nuseless_nonterminals);
+    complain (Wother, ngettext ("%d nonterminal useless in grammar",
+                                        "%d nonterminals useless in grammar",
+                                        nuseless_nonterminals),
+              nuseless_nonterminals);
   if (nuseless_productions > 0)
-    warn (ngettext ("%d rule useless in grammar",
-                    "%d rules useless in grammar",
-                    nuseless_productions),
-          nuseless_productions);
+    complain (Wother, ngettext ("%d rule useless in grammar",
+                                        "%d rules useless in grammar",
+                                        nuseless_productions),
+              nuseless_productions);
 }
 
 void
@@ -416,9 +416,9 @@ reduce_grammar (void)
   reduce_print ();
 
   if (!bitset_test (N, accept->number - ntokens))
-    fatal_at (startsymbol_location,
-              _("start symbol %s does not derive any sentence"),
-              startsymbol->tag);
+    complain_at (startsymbol_location, fatal,
+                 _("start symbol %s does not derive any sentence"),
+                 startsymbol->tag);
 
   /* First reduce the nonterminals, as they renumber themselves in the
      whole grammar.  If you change the order, nonterms would be
