@@ -495,7 +495,7 @@ symbol_user_token_number_set (symbol *sym, int user_token_number, location loc)
     {
       *user_token_numberp = user_token_number;
       /* User defined $end token? */
-      if (user_token_number == 0)
+      if (user_token_number == 0 && !endtoken)
         {
           endtoken = sym->content->symbol;
           /* It is always mapped to 0, so it was already counted in
