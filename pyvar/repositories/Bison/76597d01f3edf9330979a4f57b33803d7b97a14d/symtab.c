@@ -1010,8 +1010,10 @@ symbols_token_translations_init (void)
       sym_content *this = symbols[i]->content;
       if (this->user_token_number == USER_NUMBER_UNDEFINED)
         {
+          IGNORE_TYPE_LIMITS_BEGIN
           if (INT_ADD_WRAPV (max_user_token_number, 1, &max_user_token_number))
             complain (NULL, fatal, _("token number too large"));
+          IGNORE_TYPE_LIMITS_END
           this->user_token_number = max_user_token_number;
         }
       if (this->user_token_number > max_user_token_number)
