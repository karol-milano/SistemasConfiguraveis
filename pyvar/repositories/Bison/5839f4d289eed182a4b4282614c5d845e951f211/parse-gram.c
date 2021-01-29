@@ -1597,8 +1597,8 @@ typedef struct
    Return 0 if there are more than YYARGN expected tokens, yet fill
    YYARG up to YYARGN. */
 static int
-yyexpected_tokens (const yypcontext_t *yyctx,
-                   yysymbol_kind_t yyarg[], int yyargn)
+yypcontext_expected_tokens (const yypcontext_t *yyctx,
+                            yysymbol_kind_t yyarg[], int yyargn)
 {
   /* Actual size of YYARG. */
   int yycount = 0;
@@ -2807,7 +2807,7 @@ yyreport_syntax_error (const yypcontext_t *ctx)
     {
       argv[argc++] = yysymbol_name (unexpected);
       yysymbol_kind_t expected[ARGS_MAX - 1];
-      int nexpected = yyexpected_tokens (ctx, expected, ARGS_MAX - 1);
+      int nexpected = yypcontext_expected_tokens (ctx, expected, ARGS_MAX - 1);
       if (nexpected < 0)
         res = nexpected;
       else
