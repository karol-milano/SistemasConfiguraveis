@@ -59,8 +59,7 @@ print_closure (const char *title, item_number_t *array, size_t size)
       item_number_t *rp;
       fprintf (stderr, "  %2d: .", array[i]);
       for (rp = &ritem[array[i]]; *rp >= 0; ++rp)
-	fprintf (stderr, " %s",
-		 quotearg_style (escape_quoting_style, symbols[*rp]->tag));
+	fprintf (stderr, " %s", symbol_tag_get (symbols[*rp]));
       fprintf (stderr, "  (rule %d)\n", -*rp - 1);
     }
   fputs ("\n\n", stderr);
@@ -75,13 +74,11 @@ print_firsts (void)
   fprintf (stderr, "FIRSTS\n");
   for (i = ntokens; i < nsyms; i++)
     {
-      fprintf (stderr, "\t%s firsts\n",
-	       quotearg_style (escape_quoting_style, symbols[i]->tag));
+      fprintf (stderr, "\t%s firsts\n", symbol_tag_get (symbols[i]));
       for (j = 0; j < nvars; j++)
 	if (bitset_test (FIRSTS (i), j))
 	  fprintf (stderr, "\t\t%s\n",
-		   quotearg_style (escape_quoting_style,
-				   symbols[j + ntokens]->tag));
+		   symbol_tag_get (symbols[j + ntokens]));
     }
   fprintf (stderr, "\n\n");
 }
@@ -95,17 +92,14 @@ print_fderives (void)
   fprintf (stderr, "FDERIVES\n");
   for (i = ntokens; i < nsyms; i++)
     {
-      fprintf (stderr, "\t%s derives\n",
-	       quotearg_style (escape_quoting_style, symbols[i]->tag));
+      fprintf (stderr, "\t%s derives\n", symbol_tag_get (symbols[i]));
       for (j = 0; j < nrules + 1; j++)
 	if (bitset_test (FDERIVES (i), j))
 	  {
 	    item_number_t *rhsp;
 	    fprintf (stderr, "\t\t%d:", j - 1);
 	    for (rhsp = rules[j].rhs; *rhsp >= 0; ++rhsp)
-	      fprintf (stderr, " %s",
-		       quotearg_style (escape_quoting_style,
-				       symbols[*rhsp]->tag));
+	      fprintf (stderr, " %s", symbol_tag_get (symbols[*rhsp]));
 	    fputc ('\n', stderr);
 	  }
     }
