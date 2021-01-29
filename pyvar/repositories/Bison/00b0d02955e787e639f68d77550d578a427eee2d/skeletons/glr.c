@@ -2116,6 +2116,10 @@ yyexpected_tokens (const yyGLRStack* yystackp,
   return yycount;
 }
 
+static int
+yysyntax_error_arguments (const yyGLRStack* yystackp,
+                          int yyarg[], int yyargn) YY_ATTRIBUTE_UNUSED;
+
 static int
 yysyntax_error_arguments (const yyGLRStack* yystackp,
                           int yyarg[], int yyargn)
@@ -2172,7 +2176,19 @@ typedef yyGLRStack yyparse_context_t;
 static int
 yyreport_syntax_error (const yyGLRStack* yystackp]b4_user_formals[);
 
-]b4_locations_if([[/*  The location of this context.  */
+/* The token type of the lookahead of this context.  */
+static int
+yyparse_context_token (const yyGLRStack *yystackp) YY_ATTRIBUTE_UNUSED;
+
+static int
+yyparse_context_token (const yyGLRStack *yystackp)
+{
+  YYUSE (yystackp);
+  yySymbol yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);
+  return yytoken;
+}
+
+]b4_locations_if([[/* The location of the lookahead of this context.  */
 static YYLTYPE *
 yyparse_context_location (const yyGLRStack *yystackp) YY_ATTRIBUTE_UNUSED;
 
