@@ -2151,8 +2151,8 @@ yypcontext_location (const yyGLRStack *yystackp)
 }]])],
          [detailed\|verbose],
 [[static int
-yysyntax_error_arguments (const yyGLRStack* yystackp,
-                          yysymbol_type_t yyarg[], int yyargn)
+yy_syntax_error_arguments (const yyGLRStack* yystackp,
+                           yysymbol_type_t yyarg[], int yyargn)
 {
   yysymbol_type_t yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
   /* Actual size of YYARG. */
@@ -2225,7 +2225,7 @@ yyreportSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
 
   /* Actual size of YYARG. */
   int yycount
-    = yysyntax_error_arguments (yystackp, yyarg, YYARGS_MAX);
+    = yy_syntax_error_arguments (yystackp, yyarg, YYARGS_MAX);
   if (yycount == YYNOMEM)
     yyMemoryExhausted (yystackp);
 
