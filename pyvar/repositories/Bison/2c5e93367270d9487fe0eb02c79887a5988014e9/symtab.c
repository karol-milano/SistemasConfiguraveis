@@ -462,9 +462,7 @@ symbol_class_set (symbol *sym, symbol_class class, location loc, bool declaring)
 void
 symbol_user_token_number_set (symbol *sym, int user_token_number, location loc)
 {
-  int *user_token_numberp;
-
-  user_token_numberp = &sym->content->user_token_number;
+  int *user_token_numberp = &sym->content->user_token_number;
   if (*user_token_numberp != USER_NUMBER_UNDEFINED
       && *user_token_numberp != user_token_number)
     complain (&loc, complaint, _("redefining user token number of %s"),
