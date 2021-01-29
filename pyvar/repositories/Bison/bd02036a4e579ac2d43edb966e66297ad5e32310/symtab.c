@@ -42,9 +42,6 @@ symbol_new (const char *tag)
   res->alias = NULL;
   res->class = unknown_sym;
 
-  if (getenv ("DEBUG"))
-    fprintf (stderr, "Creating: nsyms = %d, ntokens = %d: %s\n",
-	     nsyms, ntokens, tag);
   nsyms++;
 
   return res;
