@@ -74,12 +74,13 @@ print_firsts (void)
   fprintf (stderr, "FIRSTS\n");
   for (i = ntokens; i < nsyms; i++)
     {
+      bitset_iterator iter;
       fprintf (stderr, "\t%s firsts\n", symbols[i]->tag);
-      BITSET_EXECUTE (FIRSTS (i), 0, j,
-      {
-	fprintf (stderr, "\t\t%s\n",
-		 symbols[j + ntokens]->tag);
-      });
+      BITSET_FOR_EACH (iter, FIRSTS (i), j, 0)
+	{
+	  fprintf (stderr, "\t\t%s\n",
+		   symbols[j + ntokens]->tag);
+	}
     }
   fprintf (stderr, "\n\n");
 }
@@ -94,15 +95,16 @@ print_fderives (void)
   fprintf (stderr, "FDERIVES\n");
   for (i = ntokens; i < nsyms; i++)
     {
+      bitset_iterator iter;
       fprintf (stderr, "\t%s derives\n", symbols[i]->tag);
-      BITSET_EXECUTE (FDERIVES (i), 0, r,
-      {
-	item_number_t *rhsp = NULL;
-	fprintf (stderr, "\t\t%d:", r - 1);
-	for (rhsp = rules[r].rhs; *rhsp >= 0; ++rhsp)
-	  fprintf (stderr, " %s", symbols[*rhsp]->tag);
-	fputc ('\n', stderr);
-      });
+      BITSET_FOR_EACH (iter, FDERIVES (i), r, 0)
+	{
+	  item_number_t *rhsp = NULL;
+	  fprintf (stderr, "\t\t%d:", r - 1);
+	  for (rhsp = rules[r].rhs; *rhsp >= 0; ++rhsp)
+	    fprintf (stderr, " %s", symbols[*rhsp]->tag);
+	  fputc ('\n', stderr);
+	}
     }
   fprintf (stderr, "\n\n");
 }
@@ -198,6 +200,8 @@ closure (item_number_t *core, int n)
   /* A bit index over RULESET. */
   rule_number_t ruleno;
 
+  bitset_iterator iter;
+
   if (trace_flag)
     print_closure ("input", core, n);
 
@@ -209,18 +213,18 @@ closure (item_number_t *core, int n)
 
   nritemset = 0;
   c = 0;
-  BITSET_EXECUTE (ruleset, 0, ruleno,
-  {
-    item_number_t itemno = rules[ruleno].rhs - ritem;
-    while (c < n && core[c] < itemno)
-      {
-	itemset[nritemset] = core[c];
-	nritemset++;
-	c++;
-      }
-    itemset[nritemset] = itemno;
-    nritemset++;
-  });
+  BITSET_FOR_EACH (iter, ruleset, ruleno, 0)
+    {
+      item_number_t itemno = rules[ruleno].rhs - ritem;
+      while (c < n && core[c] < itemno)
+	{
+	  itemset[nritemset] = core[c];
+	  nritemset++;
+	  c++;
+	}
+      itemset[nritemset] = itemno;
+      nritemset++;
+    };
 
   while (c < n)
     {
