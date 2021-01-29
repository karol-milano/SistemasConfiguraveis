@@ -59,7 +59,7 @@ print_closure (const char *title, item_number_t *array, size_t size)
       item_number_t *rp;
       fprintf (stderr, "  %2d: .", array[i]);
       for (rp = &ritem[array[i]]; *rp >= 0; ++rp)
-	fprintf (stderr, " %s", symbol_tag_get (symbols[*rp]));
+	fprintf (stderr, " %s", symbols[*rp]->tag);
       fprintf (stderr, "  (rule %d)\n", -*rp - 1);
     }
   fputs ("\n\n", stderr);
@@ -74,11 +74,11 @@ print_firsts (void)
   fprintf (stderr, "FIRSTS\n");
   for (i = ntokens; i < nsyms; i++)
     {
-      fprintf (stderr, "\t%s firsts\n", symbol_tag_get (symbols[i]));
+      fprintf (stderr, "\t%s firsts\n", symbols[i]->tag);
       BITSET_EXECUTE (FIRSTS (i), 0, j,
       {
 	fprintf (stderr, "\t\t%s\n",
-		 symbol_tag_get (symbols[j + ntokens]));
+		 symbols[j + ntokens]->tag);
       });
     }
   fprintf (stderr, "\n\n");
@@ -94,13 +94,13 @@ print_fderives (void)
   fprintf (stderr, "FDERIVES\n");
   for (i = ntokens; i < nsyms; i++)
     {
-      fprintf (stderr, "\t%s derives\n", symbol_tag_get (symbols[i]));
+      fprintf (stderr, "\t%s derives\n", symbols[i]->tag);
       BITSET_EXECUTE (FDERIVES (i), 0, r,
       {
 	item_number_t *rhsp = NULL;
 	fprintf (stderr, "\t\t%d:", r - 1);
 	for (rhsp = rules[r].rhs; *rhsp >= 0; ++rhsp)
-	  fprintf (stderr, " %s", symbol_tag_get (symbols[*rhsp]));
+	  fprintf (stderr, " %s", symbols[*rhsp]->tag);
 	fputc ('\n', stderr);
       });
     }
