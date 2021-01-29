@@ -39,9 +39,9 @@ int nsyms = 0;
 int ntokens = 1;
 int nvars = 0;
 
-token_number_t *token_translations = NULL;
+symbol_number_t *token_translations = NULL;
 
-token_number_t start_symbol = 0;
+symbol_number_t start_symbol = 0;
 
 int max_user_token_number = 256;
 
