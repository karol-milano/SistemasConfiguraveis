@@ -1259,7 +1259,7 @@ case 34:
 YY_RULE_SETUP
 #line 156 "scan-gram.l"
 {
-    yylval->symbol = getsym (yytext);
+    yylval->symbol = getsym (yytext, *yylloc);
     return ID;
   }
 	YY_BREAK
@@ -1450,7 +1450,7 @@ YY_RULE_SETUP
     assert (yy_top_state () == INITIAL);
     {
       YY_OBS_FINISH;
-      yylval->symbol = getsym (last_string);
+      yylval->symbol = getsym (last_string, *yylloc);
       symbol_class_set (yylval->symbol, token_sym);
       symbol_user_token_number_set (yylval->symbol, last_string[1]);
       YY_OBS_FREE;
