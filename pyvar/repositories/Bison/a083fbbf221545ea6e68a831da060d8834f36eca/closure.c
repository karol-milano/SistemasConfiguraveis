@@ -311,11 +311,11 @@ print_firsts()
   register int j;
   register unsigned *rowp;
 
-  printf("\n\n\nFIRSTS\n\n");
+  printf(_("\n\n\nFIRSTS\n\n"));
 
   for (i = ntokens; i < nsyms; i++)
     {
-      printf("\n\n%s firsts\n\n", tags[i]);
+      printf(_("\n\n%s firsts\n\n"), tags[i]);
 
       rowp = firsts + ((i - ntokens) * varsetsize);
 
@@ -333,11 +333,11 @@ print_fderives()
   register int j;
   register unsigned *rp;
 
-  printf("\n\n\nFDERIVES\n");
+  printf(_("\n\n\nFDERIVES\n"));
 
   for (i = ntokens; i < nsyms; i++)
     {
-      printf("\n\n%s derives\n\n", tags[i]);
+      printf(_("\n\n%s derives\n\n"), tags[i]);
       rp = fderives + i * rulesetsize;
 
       for (j = 0; j <= nrules; j++)
