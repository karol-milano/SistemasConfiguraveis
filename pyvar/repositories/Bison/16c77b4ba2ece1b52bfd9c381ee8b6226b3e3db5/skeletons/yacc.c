@@ -1192,13 +1192,16 @@ yysyntax_error_arguments (const yyparse_context_t *yyctx,
 ]m4_case(b4_percent_define_get([[parse.error]]),
          [custom],
 [b4_locations_if([[/*  The location of this context.  */
+static YYLTYPE *
+yyparse_context_location (const yyparse_context_t *yyctx) YY_ATTRIBUTE_UNUSED;
+
 static YYLTYPE *
 yyparse_context_location (const yyparse_context_t *yyctx)
 {
   return yyctx->yylloc;
 }]])[
 
-/* User defined funtion to report a syntax error.  */
+/* User defined function to report a syntax error.  */
 ]b4_function_declare([yyreport_syntax_error], [static int],
                      [[[const yyparse_context_t *yyctx]], [[yyctx]]],
                      b4_parse_param)],
