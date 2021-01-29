@@ -86,15 +86,7 @@ macro_init (void)
   macro_insert ("maxtok", "0");
   macro_insert ("ntbase", "0");
   macro_insert ("verbose", "0");
-
-  /* Variable prefix names.  */
-  macro_insert ("yyparse", "yyparse");
-  macro_insert ("yylex", "yylex");
-  macro_insert ("yyerror", "yyerror");
-  macro_insert ("yylval", "yylval");
-  macro_insert ("yychar", "yychar");
-  macro_insert ("yydebug", "yydebug");
-  macro_insert ("yynerrs", "yynerrs");
+  macro_insert ("prefix", "yy");
 
   /* No parser macros.  */
   macro_insert ("nnts", "0");
