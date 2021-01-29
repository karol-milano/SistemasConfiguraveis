@@ -2114,13 +2114,39 @@ yyexpected_tokens (const yyGLRStack* yystackp,
           }
     }
   return yycount;
-}
+}]])[
 
+]b4_parse_error_bmatch(
+         [custom],
+[[/* User defined function to report a syntax error.  */
+typedef yyGLRStack yyparse_context_t;
 static int
-yysyntax_error_arguments (const yyGLRStack* yystackp,
-                          int yyarg[], int yyargn) YY_ATTRIBUTE_UNUSED;
+yyreport_syntax_error (const yyGLRStack* yystackp]b4_user_formals[);
+
+/* The token type of the lookahead of this context.  */
+static int
+yyparse_context_token (const yyGLRStack *yystackp) YY_ATTRIBUTE_UNUSED;
 
 static int
+yyparse_context_token (const yyGLRStack *yystackp)
+{
+  YYUSE (yystackp);
+  yySymbol yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);
+  return yytoken;
+}
+
+]b4_locations_if([[/* The location of the lookahead of this context.  */
+static YYLTYPE *
+yyparse_context_location (const yyGLRStack *yystackp) YY_ATTRIBUTE_UNUSED;
+
+static YYLTYPE *
+yyparse_context_location (const yyGLRStack *yystackp)
+{
+  YYUSE (yystackp);
+  return &yylloc;
+}]])],
+         [detailed\|verbose],
+[[static int
 yysyntax_error_arguments (const yyGLRStack* yystackp,
                           int yyarg[], int yyargn)
 {
@@ -2169,36 +2195,6 @@ yysyntax_error_arguments (const yyGLRStack* yystackp,
 }
 ]])[
 
-]b4_parse_error_case(
-         [custom],
-[[/* User defined function to report a syntax error.  */
-typedef yyGLRStack yyparse_context_t;
-static int
-yyreport_syntax_error (const yyGLRStack* yystackp]b4_user_formals[);
-
-/* The token type of the lookahead of this context.  */
-static int
-yyparse_context_token (const yyGLRStack *yystackp) YY_ATTRIBUTE_UNUSED;
-
-static int
-yyparse_context_token (const yyGLRStack *yystackp)
-{
-  YYUSE (yystackp);
-  yySymbol yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);
-  return yytoken;
-}
-
-]b4_locations_if([[/* The location of the lookahead of this context.  */
-static YYLTYPE *
-yyparse_context_location (const yyGLRStack *yystackp) YY_ATTRIBUTE_UNUSED;
-
-static YYLTYPE *
-yyparse_context_location (const yyGLRStack *yystackp)
-{
-  YYUSE (yystackp);
-  return &yylloc;
-}]])])[
-
 
 static void
 yyreportSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
