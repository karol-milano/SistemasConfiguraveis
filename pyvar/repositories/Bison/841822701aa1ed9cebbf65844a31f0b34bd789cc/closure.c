@@ -64,20 +64,14 @@ print_closure (int n)
 static void
 print_firsts (void)
 {
-  int i;
-  int j;
-  unsigned *rowp;
+  int i, j;
 
   fprintf (stderr, "FIRSTS\n");
-
   for (i = ntokens; i < nsyms; i++)
     {
       fprintf (stderr, "\t%s firsts\n", tags[i]);
-
-      rowp = FIRSTS (i - ntokens);
-
       for (j = 0; j < nvars; j++)
-	if (BITISSET (rowp, j))
+	if (BITISSET (FIRSTS (i - ntokens), j))
 	  fprintf (stderr, "\t\t%d (%s)\n", j + ntokens, tags[j + ntokens]);
     }
   fprintf (stderr, "\n\n");
@@ -89,17 +83,14 @@ print_fderives (void)
 {
   int i;
   int j;
-  unsigned *rp;
 
   fprintf (stderr, "FDERIVES\n");
 
   for (i = ntokens; i < nsyms; i++)
     {
       fprintf (stderr, "\t%s derives\n", tags[i]);
-      rp = FDERIVES (i);
-
       for (j = 0; j <= nrules; j++)
-	if (BITISSET (rp, j))
+	if (BITISSET (FDERIVES (i), j))
 	  {
 	    short *rhsp;
 	    fprintf (stderr, "\t\t%d:", j);
