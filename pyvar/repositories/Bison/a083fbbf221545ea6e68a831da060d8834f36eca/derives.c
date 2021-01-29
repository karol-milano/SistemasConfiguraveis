@@ -99,11 +99,11 @@ print_derives()
 
   extern char **tags;
 
-  printf("\n\n\nDERIVES\n\n");
+  printf(_("\n\n\nDERIVES\n\n"));
 
   for (i = ntokens; i < nsyms; i++)
     {
-      printf("%s derives", tags[i]);
+      printf(_("%s derives"), tags[i]);
       for (sp = derives[i]; *sp > 0; sp++)
 	{
 	  printf("  %d", *sp);
