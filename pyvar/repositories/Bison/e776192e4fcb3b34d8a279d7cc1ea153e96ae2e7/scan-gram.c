@@ -1469,8 +1469,8 @@ YY_RULE_SETUP
     {
       YY_OBS_FINISH;
       yylval->symbol = getsym (last_string, *yylloc);
-      symbol_class_set (yylval->symbol, token_sym);
-      symbol_user_token_number_set (yylval->symbol, last_string[1]);
+      symbol_class_set (yylval->symbol, token_sym, *yylloc);
+      symbol_user_token_number_set (yylval->symbol, last_string[1], *yylloc);
       YY_OBS_FREE;
       yy_pop_state ();
       return ID;
