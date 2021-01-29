@@ -307,7 +307,7 @@ nonterminals_reduce (void)
 	LOCATION_PRINT (stderr, symbols[i]->location);
 	fprintf (stderr, ": %s: %s: %s\n",
 		 _("warning"), _("useless nonterminal"),
-		 symbol_tag_get (symbols[i]));
+		 symbols[i]->tag);
       }
 
 
@@ -355,7 +355,7 @@ reduce_output (FILE *out)
       int i;
       fprintf (out, "%s\n\n", _("Useless nonterminals:"));
       for (i = 0; i < nuseless_nonterminals; ++i)
-	fprintf (out, "   %s\n", symbol_tag_get (symbols[nsyms + i]));
+	fprintf (out, "   %s\n", symbols[nsyms + i]->tag);
       fputs ("\n\n", out);
     }
 
@@ -368,7 +368,7 @@ reduce_output (FILE *out)
 	  if (!b)
 	    fprintf (out, "%s\n\n", _("Terminals which are not used:"));
 	  b = TRUE;
-	  fprintf (out, "   %s\n", symbol_tag_get (symbols[i]));
+	  fprintf (out, "   %s\n", symbols[i]->tag);
 	}
     if (b)
       fputs ("\n\n", out);
@@ -440,7 +440,7 @@ reduce_grammar (void)
 
   if (!bitset_test (N, axiom->number - ntokens))
     fatal (_("Start symbol %s does not derive any sentence"),
-	   symbol_tag_get (symbols[axiom->number]));
+	   symbols[axiom->number]->tag);
 
   /* First reduce the nonterminals, as they renumber themselves in the
      whole grammar.  If you change the order, nonterms would be
