@@ -2127,7 +2127,7 @@ typedef yyGLRStack yypcontext_t;
 static int
 yyreport_syntax_error (const yyGLRStack* yystackp]b4_user_formals[);
 
-/* The token type of the lookahead of this context.  */
+/* The kind of the lookahead of this context.  */
 static yysymbol_kind_t
 yypcontext_token (const yyGLRStack *yystackp) YY_ATTRIBUTE_UNUSED;
 
