@@ -389,7 +389,7 @@ reduce_print (void)
 			       nuseless_productions),
 	     nuseless_productions);
 
-  fprintf (stderr, "%s: %s: ", infile, _("warning"));
+  fprintf (stderr, "%s: %s: ", grammar_file, _("warning"));
 
   if (nuseless_nonterminals > 0)
     fprintf (stderr, ngettext ("%d useless nonterminal",
@@ -449,7 +449,7 @@ reduce_grammar (void)
 
       fprintf (stderr, "reduced %s defines %d terminals, %d nonterminals\
 , and %d productions.\n",
-	       infile, ntokens, nvars, nrules);
+	       grammar_file, ntokens, nvars, nrules);
     }
 }
 
