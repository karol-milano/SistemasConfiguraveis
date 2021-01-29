@@ -62,7 +62,7 @@ print_closure (char const *title, item_number *array, size_t size)
       item_number *rp;
       fprintf (stderr, "  %2d: .", array[i]);
       for (rp = &ritem[array[i]]; *rp >= 0; ++rp)
-	fprintf (stderr, " %s", symbols[*rp]->tag);
+        fprintf (stderr, " %s", symbols[*rp]->tag);
       fprintf (stderr, "  (rule %d)\n", -*rp - 1);
     }
   fputs ("\n\n", stderr);
@@ -80,10 +80,10 @@ print_firsts (void)
       bitset_iterator iter;
       fprintf (stderr, "\t%s firsts\n", symbols[i]->tag);
       BITSET_FOR_EACH (iter, FIRSTS (i), j, 0)
-	{
-	  fprintf (stderr, "\t\t%s\n",
-		   symbols[j + ntokens]->tag);
-	}
+        {
+          fprintf (stderr, "\t\t%s\n",
+                   symbols[j + ntokens]->tag);
+        }
     }
   fprintf (stderr, "\n\n");
 }
@@ -101,10 +101,10 @@ print_fderives (void)
       bitset_iterator iter;
       fprintf (stderr, "\t%s derives\n", symbols[i]->tag);
       BITSET_FOR_EACH (iter, FDERIVES (i), r, 0)
-	{
-	  fprintf (stderr, "\t\t%3d ", r);
-	  rule_rhs_print (&rules[r], stderr);
-	}
+        {
+          fprintf (stderr, "\t\t%3d ", r);
+          rule_rhs_print (&rules[r], stderr);
+        }
     }
   fprintf (stderr, "\n\n");
 }
@@ -130,9 +130,9 @@ set_firsts (void)
   for (i = ntokens; i < nsyms; i++)
     for (j = 0; derives[i - ntokens][j]; ++j)
       {
-	item_number sym = derives[i - ntokens][j]->rhs[0];
-	if (ISVAR (sym))
-	  bitset_set (FIRSTS (i), sym - ntokens);
+        item_number sym = derives[i - ntokens][j]->rhs[0];
+        if (ISVAR (sym))
+          bitset_set (FIRSTS (i), sym - ntokens);
       }
 
   if (trace_flag & trace_sets)
@@ -168,8 +168,8 @@ set_fderives (void)
   for (i = ntokens; i < nsyms; ++i)
     for (j = ntokens; j < nsyms; ++j)
       if (bitset_test (FIRSTS (i), j - ntokens))
-	for (k = 0; derives[j - ntokens][k]; ++k)
-	  bitset_set (FDERIVES (i), derives[j - ntokens][k]->number);
+        for (k = 0; derives[j - ntokens][k]; ++k)
+          bitset_set (FDERIVES (i), derives[j - ntokens][k]->number);
 
   if (trace_flag & trace_sets)
     print_fderives ();
@@ -219,11 +219,11 @@ closure (item_number *core, size_t n)
     {
       item_number itemno = rules[ruleno].rhs - ritem;
       while (c < n && core[c] < itemno)
-	{
-	  itemset[nitemset] = core[c];
-	  nitemset++;
-	  c++;
-	}
+        {
+          itemset[nitemset] = core[c];
+          nitemset++;
+          c++;
+        }
       itemset[nitemset] = itemno;
       nitemset++;
     };
