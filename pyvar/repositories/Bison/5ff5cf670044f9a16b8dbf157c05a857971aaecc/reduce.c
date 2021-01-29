@@ -384,13 +384,13 @@ reduce_print (void)
 {
   if (nuseless_nonterminals > 0)
     complain (Wother, ngettext ("%d nonterminal useless in grammar",
-                                        "%d nonterminals useless in grammar",
-                                        nuseless_nonterminals),
+                                "%d nonterminals useless in grammar",
+                                nuseless_nonterminals),
               nuseless_nonterminals);
   if (nuseless_productions > 0)
     complain (Wother, ngettext ("%d rule useless in grammar",
-                                        "%d rules useless in grammar",
-                                        nuseless_productions),
+                                "%d rules useless in grammar",
+                                nuseless_productions),
               nuseless_productions);
 }
 
@@ -432,8 +432,8 @@ reduce_grammar (void)
     {
       grammar_dump (stderr, "Reduced Grammar");
 
-      fprintf (stderr, "reduced %s defines %d terminals, %d nonterminals\
-, and %d productions.\n",
+      fprintf (stderr, "reduced %s defines %d terminals, %d nonterminals"
+               ", and %d productions.\n",
                grammar_file, ntokens, nvars, nrules);
     }
 }
