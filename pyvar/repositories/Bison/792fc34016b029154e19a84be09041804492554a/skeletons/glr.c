@@ -2180,6 +2180,25 @@ yysyntax_error_arguments (const yyGLRStack* yystackp,
 }
 ]])[
 
+]m4_case(b4_percent_define_get([[parse.error]]),
+         [custom],
+[[/* User defined function to report a syntax error.  */
+typedef yyGLRStack yyparse_context_t;
+static int
+yyreport_syntax_error (const yyGLRStack* yystackp]b4_user_formals[);
+
+]b4_locations_if([[/*  The location of this context.  */
+static YYLTYPE *
+yyparse_context_location (const yyGLRStack *yystackp) YY_ATTRIBUTE_UNUSED;
+
+static YYLTYPE *
+yyparse_context_location (const yyGLRStack *yystackp)
+{
+  YYUSE (yystackp);
+  return &yylloc;
+}]])])[
+
+
 static void
 yyreportSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
 {
