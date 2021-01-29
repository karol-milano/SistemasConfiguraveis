@@ -1209,7 +1209,7 @@ yyexpected_tokens (const yypcontext_t *yyctx,
 
 ]b4_parse_error_bmatch(
          [custom],
-[[/* The token type of the lookahead of this context.  */
+[[/* The kind of the lookahead of this context.  */
 static yysymbol_kind_t
 yypcontext_token (const yypcontext_t *yyctx) YY_ATTRIBUTE_UNUSED;
 
