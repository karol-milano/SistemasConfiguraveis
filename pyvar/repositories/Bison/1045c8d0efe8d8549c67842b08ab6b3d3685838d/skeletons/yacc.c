@@ -1198,6 +1198,10 @@ yyexpected_tokens (const yyparse_context_t *yyctx,
   return yypstate_expected_tokens (yyctx->yyps, yyarg, yyargn);
 }]])[
 
+static int
+yysyntax_error_arguments (const yyparse_context_t *yyctx,
+                          int yyarg[], int yyargn) YY_ATTRIBUTE_UNUSED;
+
 static int
 yysyntax_error_arguments (const yyparse_context_t *yyctx,
                           int yyarg[], int yyargn)
@@ -1251,7 +1255,17 @@ yysyntax_error_arguments (const yyparse_context_t *yyctx,
 
 ]b4_parse_error_case(
          [custom],
-[b4_locations_if([[/*  The location of this context.  */
+[[/* The token type of the lookahead of this context.  */
+static int
+yyparse_context_token (const yyparse_context_t *yyctx) YY_ATTRIBUTE_UNUSED;
+
+static int
+yyparse_context_token (const yyparse_context_t *yyctx)
+{
+  return yyctx->yytoken;
+}
+
+]b4_locations_if([[/* The location of the lookahead of this context.  */
 static YYLTYPE *
 yyparse_context_location (const yyparse_context_t *yyctx) YY_ATTRIBUTE_UNUSED;
 
