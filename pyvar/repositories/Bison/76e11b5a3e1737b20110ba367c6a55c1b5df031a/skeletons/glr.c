@@ -2123,16 +2123,16 @@ yyexpected_tokens (const yyGLRStack* yystackp,
 ]b4_parse_error_bmatch(
          [custom],
 [[/* User defined function to report a syntax error.  */
-typedef yyGLRStack yyparse_context_t;
+typedef yyGLRStack yypcontext_t;
 static int
 yyreport_syntax_error (const yyGLRStack* yystackp]b4_user_formals[);
 
 /* The token type of the lookahead of this context.  */
 static yysymbol_type_t
-yyparse_context_token (const yyGLRStack *yystackp) YY_ATTRIBUTE_UNUSED;
+yypcontext_token (const yyGLRStack *yystackp) YY_ATTRIBUTE_UNUSED;
 
 static yysymbol_type_t
-yyparse_context_token (const yyGLRStack *yystackp)
+yypcontext_token (const yyGLRStack *yystackp)
 {
   YYUSE (yystackp);
   yysymbol_type_t yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
@@ -2141,10 +2141,10 @@ yyparse_context_token (const yyGLRStack *yystackp)
 
 ]b4_locations_if([[/* The location of the lookahead of this context.  */
 static YYLTYPE *
-yyparse_context_location (const yyGLRStack *yystackp) YY_ATTRIBUTE_UNUSED;
+yypcontext_location (const yyGLRStack *yystackp) YY_ATTRIBUTE_UNUSED;
 
 static YYLTYPE *
-yyparse_context_location (const yyGLRStack *yystackp)
+yypcontext_location (const yyGLRStack *yystackp)
 {
   YYUSE (yystackp);
   return &yylloc;
