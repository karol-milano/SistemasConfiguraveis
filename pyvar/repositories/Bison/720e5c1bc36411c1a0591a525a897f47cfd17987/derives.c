@@ -38,15 +38,21 @@ static void
 print_derives (void)
 {
   int i;
-  short *sp;
 
   fputs ("DERIVES\n", stderr);
 
   for (i = ntokens; i < nsyms; i++)
     {
+      short *sp;
       fprintf (stderr, "\t%s derives\n", tags[i]);
       for (sp = derives[i]; *sp > 0; sp++)
-	fprintf (stderr, "\t\t%d (%s)\n", *sp, tags[*sp]);
+	{
+	  short *rhsp;
+	  fprintf (stderr, "\t\t%d:", *sp);
+	  for (rhsp = ritem + rule_table[*sp].rhs; *rhsp > 0; ++rhsp)
+	    fprintf (stderr, " %s", tags[*rhsp]);
+	  fputc ('\n', stderr);
+	}
     }
 
   fputs ("\n\n", stderr);
