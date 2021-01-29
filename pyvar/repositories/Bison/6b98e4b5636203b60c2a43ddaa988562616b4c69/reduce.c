@@ -227,11 +227,19 @@ inaccessable_symbols (void)
 static void
 reduce_grammar_tables (void)
 {
-  /* Flag useless productions.  */
+  /* Report and flag useless productions.  */
   {
-    int pn;
-    for (pn = 1; pn < nrules + 1; pn++)
-      rules[pn].useful = bitset_test (P, pn);
+    int r;
+    for (r = 1; r < nrules + 1; r++)
+      {
+	rules[r].useful = bitset_test (P, r);
+	if (!rules[r].useful)
+	  {
+	    LOCATION_PRINT (stderr, rules[r].location);
+	    fprintf (stderr, ": %s: %s: ", _("warning"), _("useless rule"));
+	    rule_print (&rules[r], stderr);
+	  }
+      }
   }
 
   /* Map the nonterminals to their new index: useful first, useless
@@ -290,7 +298,13 @@ nonterminals_reduce (void)
       nontermmap[i] = n++;
   for (i = ntokens; i < nsyms; i++)
     if (!bitset_test (V, i))
-      nontermmap[i] = n++;
+      {
+	nontermmap[i] = n++;
+	LOCATION_PRINT (stderr, symbols[i]->location);
+	fprintf (stderr, ": %s: %s: %s\n",
+		 _("warning"), _("useless nonterminal"),
+		 symbol_tag_get (symbols[i]));
+      }
 
 
   /* Shuffle elements of tables indexed by symbol number.  */
@@ -337,8 +351,7 @@ reduce_output (FILE *out)
       int i;
       fprintf (out, "%s\n\n", _("Useless nonterminals:"));
       for (i = 0; i < nuseless_nonterminals; ++i)
-	fprintf (out, "   %s\n", quotearg_style (escape_quoting_style,
-						 symbols[nsyms + i]->tag));
+	fprintf (out, "   %s\n", symbol_tag_get (symbols[nsyms + i]));
       fputs ("\n\n", out);
     }
 
@@ -351,8 +364,7 @@ reduce_output (FILE *out)
 	  if (!b)
 	    fprintf (out, "%s\n\n", _("Terminals which are not used:"));
 	  b = TRUE;
-	  fprintf (out, "   %s\n", quotearg_style (escape_quoting_style,
-						   symbols[i]->tag));
+	  fprintf (out, "   %s\n", symbol_tag_get (symbols[i]));
 	}
     if (b)
       fputs ("\n\n", out);
@@ -366,11 +378,9 @@ reduce_output (FILE *out)
 	{
 	  item_number_t *r;
 	  fprintf (out, "#%-4d  ", rules[i].user_number - 1);
-	  fprintf (out, "%s:", quotearg_style (escape_quoting_style,
-					       rules[i].lhs->tag));
+	  fprintf (out, "%s:", symbol_tag_get (rules[i].lhs));
 	  for (r = rules[i].rhs; *r >= 0; r++)
-	    fprintf (out, " %s", quotearg_style (escape_quoting_style,
-						 symbols[*r]->tag));
+	    fprintf (out, " %s", symbol_tag_get (symbols[*r]));
 	  fputs (";\n", out);
 	}
       fputs ("\n\n", out);
@@ -394,7 +404,7 @@ reduce_print (void)
 			       nuseless_productions),
 	     nuseless_productions);
 
-  fprintf (stderr, _("%s contains "), infile);
+  fprintf (stderr, "%s: %s: ", infile, _("warning"));
 
   if (nuseless_nonterminals > 0)
     fprintf (stderr, ngettext ("%d useless nonterminal",
@@ -437,7 +447,7 @@ reduce_grammar (void)
 
   if (!bitset_test (N, axiom->number - ntokens))
     fatal (_("Start symbol %s does not derive any sentence"),
-	   quotearg_style (escape_quoting_style, symbols[axiom->number]->tag));
+	   symbol_tag_get (symbols[axiom->number]));
 
   /* First reduce the nonterminals, as they renumber themselves in the
      whole grammar.  If you change the order, nonterms would be
