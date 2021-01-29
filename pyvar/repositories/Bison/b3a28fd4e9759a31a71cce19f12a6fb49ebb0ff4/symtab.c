@@ -836,9 +836,8 @@ symbols_token_translations_init (void)
   token_translations = xnmalloc (max_user_token_number + 1,
 				 sizeof *token_translations);
 
-  /* Initialize all entries for literal tokens to 2, the internal
-     token number for $undefined, which represents all invalid inputs.
-     */
+  /* Initialize all entries for literal tokens to the internal token
+     number for $undefined, which represents all invalid inputs.  */
   for (i = 0; i < max_user_token_number + 1; i++)
     token_translations[i] = undeftoken->number;
   symbols_do (symbol_translation_processor, NULL);
