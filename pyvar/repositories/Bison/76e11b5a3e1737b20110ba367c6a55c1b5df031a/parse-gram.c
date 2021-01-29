@@ -1592,7 +1592,7 @@ typedef struct
   YYPTRDIFF_T *yyes_capacity;
   yysymbol_type_t yytoken;
   YYLTYPE *yylloc;
-} yyparse_context_t;
+} yypcontext_t;
 
 /* Put in YYARG at most YYARGN of the expected tokens given the
    current YYCTX, and return the number of tokens stored in YYARG.  If
@@ -1601,7 +1601,7 @@ typedef struct
    Return 0 if there are more than YYARGN expected tokens, yet fill
    YYARG up to YYARGN. */
 static int
-yyexpected_tokens (const yyparse_context_t *yyctx,
+yyexpected_tokens (const yypcontext_t *yyctx,
                    yysymbol_type_t yyarg[], int yyargn)
 {
   /* Actual size of YYARG. */
@@ -1635,27 +1635,27 @@ yyexpected_tokens (const yyparse_context_t *yyctx,
 
 /* The token type of the lookahead of this context.  */
 static yysymbol_type_t
-yyparse_context_token (const yyparse_context_t *yyctx) YY_ATTRIBUTE_UNUSED;
+yypcontext_token (const yypcontext_t *yyctx) YY_ATTRIBUTE_UNUSED;
 
 static yysymbol_type_t
-yyparse_context_token (const yyparse_context_t *yyctx)
+yypcontext_token (const yypcontext_t *yyctx)
 {
   return yyctx->yytoken;
 }
 
 /* The location of the lookahead of this context.  */
 static YYLTYPE *
-yyparse_context_location (const yyparse_context_t *yyctx) YY_ATTRIBUTE_UNUSED;
+yypcontext_location (const yypcontext_t *yyctx) YY_ATTRIBUTE_UNUSED;
 
 static YYLTYPE *
-yyparse_context_location (const yyparse_context_t *yyctx)
+yypcontext_location (const yypcontext_t *yyctx)
 {
   return yyctx->yylloc;
 }
 
 /* User defined function to report a syntax error.  */
 static int
-yyreport_syntax_error (const yyparse_context_t *yyctx);
+yyreport_syntax_error (const yypcontext_t *yyctx);
 
 /*-----------------------------------------------.
 | Release the memory associated to this symbol.  |
@@ -2630,7 +2630,7 @@ yyerrlab:
     {
       ++yynerrs;
       {
-        yyparse_context_t yyctx
+        yypcontext_t yyctx
           = {yyssp, yyesa, &yyes, &yyes_capacity, yytoken, &yylloc};
         if (yychar != YYEMPTY)
           YY_LAC_ESTABLISH;
@@ -2798,7 +2798,7 @@ yyreturn:
 
 
 int
-yyreport_syntax_error (const yyparse_context_t *ctx)
+yyreport_syntax_error (const yypcontext_t *ctx)
 {
   int res = 0;
   /* Arguments of format: reported tokens (one for the "unexpected",
@@ -2806,7 +2806,7 @@ yyreport_syntax_error (const yyparse_context_t *ctx)
   enum { ARGS_MAX = 5 };
   const char *argv[ARGS_MAX];
   int argc = 0;
-  yysymbol_type_t unexpected = yyparse_context_token (ctx);
+  yysymbol_type_t unexpected = yypcontext_token (ctx);
   if (unexpected != YYSYMBOL_YYEMPTY)
     {
       argv[argc++] = yysymbol_name (unexpected);
@@ -2818,7 +2818,7 @@ yyreport_syntax_error (const yyparse_context_t *ctx)
         for (int i = 0; i < nexpected; ++i)
           argv[argc++] = yysymbol_name (expected[i]);
     }
-  syntax_error (*yyparse_context_location (ctx), argc, argv);
+  syntax_error (*yypcontext_location (ctx), argc, argv);
   return res;
 }
 
