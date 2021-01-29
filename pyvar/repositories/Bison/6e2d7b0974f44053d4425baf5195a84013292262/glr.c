@@ -187,17 +187,17 @@ b4_copyright([Skeleton implementation for Bison GLR parsers in C],
 
 ]b4_identification
 
-b4_percent_code_get([[top]])[]dnl
-m4_if(b4_prefix, [yy], [],
-[/* Substitute the variable and function names.  */
-#define yyparse b4_prefix[]parse
-#define yylex   b4_prefix[]lex
-#define yyerror b4_prefix[]error
-#define yylval  b4_prefix[]lval
-#define yychar  b4_prefix[]char
-#define yydebug b4_prefix[]debug
-#define yynerrs b4_prefix[]nerrs
-#define yylloc  b4_prefix[]lloc])[
+b4_percent_code_get([[top]])[
+]m4_if(b4_prefix, [yy], [],
+[[/* Substitute the variable and function names.  */
+#define yyparse ]b4_prefix[parse
+#define yylex   ]b4_prefix[lex
+#define yyerror ]b4_prefix[error
+#define yylval  ]b4_prefix[lval
+#define yychar  ]b4_prefix[char
+#define yydebug ]b4_prefix[debug
+#define yynerrs ]b4_prefix[nerrs]b4_locations_if([[
+#define yylloc  ]b4_prefix[lloc]])])[
 
 /* Copy the first part of user declarations.  */
 ]b4_user_pre_prologue[
