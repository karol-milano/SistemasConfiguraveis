@@ -40,17 +40,16 @@ print_derives (void)
   int i;
   short *sp;
 
-  fputs ("\n\n\nDERIVES\n\n", stderr);
+  fputs ("DERIVES\n", stderr);
 
   for (i = ntokens; i < nsyms; i++)
     {
-      fprintf (stderr, "%s derives", tags[i]);
+      fprintf (stderr, "\t%s derives\n", tags[i]);
       for (sp = derives[i]; *sp > 0; sp++)
-	fprintf (stderr, "  %d", *sp);
-      putc ('\n', stderr);
+	fprintf (stderr, "\t\t%d (%s)\n", *sp, tags[*sp]);
     }
 
-  putc ('\n', stderr);
+  fputs ("\n\n", stderr);
 }
 
 
