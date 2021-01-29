@@ -77,12 +77,9 @@ print_firsts (void)
   for (i = ntokens; i < nsyms; i++)
     {
       bitset_iterator iter;
-      fprintf (stderr, "\t%s firsts\n", symbols[i]->tag);
+      fprintf (stderr, "  %s firsts\n", symbols[i]->tag);
       BITSET_FOR_EACH (iter, FIRSTS (i), j, 0)
-        {
-          fprintf (stderr, "\t\t%s\n",
-                   symbols[j + ntokens]->tag);
-        }
+        fprintf (stderr, "    %s\n", symbols[j + ntokens]->tag);
     }
   fprintf (stderr, "\n\n");
 }
@@ -98,10 +95,10 @@ print_fderives (void)
   for (i = ntokens; i < nsyms; i++)
     {
       bitset_iterator iter;
-      fprintf (stderr, "\t%s derives\n", symbols[i]->tag);
+      fprintf (stderr, "  %s derives\n", symbols[i]->tag);
       BITSET_FOR_EACH (iter, FDERIVES (i), r, 0)
         {
-          fprintf (stderr, "\t\t%3d ", r);
+          fprintf (stderr, "    %3d ", r);
           rule_rhs_print (&rules[r], stderr);
           fprintf (stderr, "\n");
         }
