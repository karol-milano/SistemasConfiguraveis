@@ -40,7 +40,9 @@ print_derives (void)
   int i;
   short *sp;
 
-  printf (_("\n\n\nDERIVES\n\n"));
+  fputs ("\n\n\n", stdout);
+  printf (_("DERIVES"));
+  fputs ("\n\n", stdout);
 
   for (i = ntokens; i < nsyms; i++)
     {
