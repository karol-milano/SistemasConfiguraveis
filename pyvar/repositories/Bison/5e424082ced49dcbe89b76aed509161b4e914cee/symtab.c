@@ -115,7 +115,8 @@ symbol_user_token_number_set (symbol_t *symbol, int user_token_number)
 {
   assert (symbol->class == token_sym);
 
-  if (symbol->user_token_number != USER_NUMBER_UNDEFINED)
+  if (symbol->user_token_number != USER_NUMBER_UNDEFINED
+      && symbol->user_token_number != user_token_number)
     complain (_("redefining user token number of %s"), symbol->tag);
 
   symbol->user_token_number = user_token_number;
