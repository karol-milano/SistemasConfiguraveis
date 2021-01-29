@@ -91,7 +91,7 @@ print_fderives (void)
   for (i = ntokens; i < nsyms; i++)
     {
       fprintf (stderr, "\t%s derives\n", symbols[i]->tag);
-      for (j = 0; j <= nrules; j++)
+      for (j = 0; j < nrules + 1; j++)
 	if (bitset_test (FDERIVES (i), j))
 	  {
 	    short *rhsp;
