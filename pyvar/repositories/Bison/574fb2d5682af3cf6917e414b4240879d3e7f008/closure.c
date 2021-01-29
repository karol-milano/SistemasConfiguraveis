@@ -69,16 +69,17 @@ print_closure (const char *title, item_number_t *array, size_t size)
 static void
 print_firsts (void)
 {
-  int i, j;
+  symbol_number_t i, j;
 
   fprintf (stderr, "FIRSTS\n");
   for (i = ntokens; i < nsyms; i++)
     {
       fprintf (stderr, "\t%s firsts\n", symbol_tag_get (symbols[i]));
-      for (j = 0; j < nvars; j++)
-	if (bitset_test (FIRSTS (i), j))
-	  fprintf (stderr, "\t\t%s\n",
-		   symbol_tag_get (symbols[j + ntokens]));
+      BITSET_EXECUTE (FIRSTS (i), 0, j,
+      {
+	fprintf (stderr, "\t\t%s\n",
+		 symbol_tag_get (symbols[j + ntokens]));
+      });
     }
   fprintf (stderr, "\n\n");
 }
@@ -94,15 +95,14 @@ print_fderives (void)
   for (i = ntokens; i < nsyms; i++)
     {
       fprintf (stderr, "\t%s derives\n", symbol_tag_get (symbols[i]));
-      for (r = 0; r < nrules + 1; r++)
-	if (bitset_test (FDERIVES (i), r))
-	  {
-	    item_number_t *rhsp = NULL;
-	    fprintf (stderr, "\t\t%d:", r - 1);
-	    for (rhsp = rules[r].rhs; *rhsp >= 0; ++rhsp)
-	      fprintf (stderr, " %s", symbol_tag_get (symbols[*rhsp]));
-	    fputc ('\n', stderr);
-	  }
+      BITSET_EXECUTE (FDERIVES (i), 0, r,
+      {
+	item_number_t *rhsp = NULL;
+	fprintf (stderr, "\t\t%d:", r - 1);
+	for (rhsp = rules[r].rhs; *rhsp >= 0; ++rhsp)
+	  fprintf (stderr, " %s", symbol_tag_get (symbols[*rhsp]));
+	fputc ('\n', stderr);
+      });
     }
   fprintf (stderr, "\n\n");
 }
@@ -209,19 +209,18 @@ closure (item_number_t *core, int n)
 
   nritemset = 0;
   c = 0;
-  for (ruleno = 0; ruleno < nrules + 1; ++ruleno)
-    if (bitset_test (ruleset, ruleno))
+  BITSET_EXECUTE (ruleset, 0, ruleno,
+  {
+    item_number_t itemno = rules[ruleno].rhs - ritem;
+    while (c < n && core[c] < itemno)
       {
-	item_number_t itemno = rules[ruleno].rhs - ritem;
-	while (c < n && core[c] < itemno)
-	  {
-	    itemset[nritemset] = core[c];
-	    nritemset++;
-	    c++;
-	  }
-	itemset[nritemset] = itemno;
+	itemset[nritemset] = core[c];
 	nritemset++;
+	c++;
       }
+    itemset[nritemset] = itemno;
+    nritemset++;
+  });
 
   while (c < n)
     {
