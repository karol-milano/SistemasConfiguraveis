@@ -561,7 +561,7 @@ token_definitions_output (FILE *out)
   int first = 1;
   for (i = 0; i < ntokens; ++i)
     {
-      bucket *symbol = symbols[i];
+      symbol_t *symbol = symbols[i];
       int number = symbol->user_token_number;
 
       if (number == SALIAS)
