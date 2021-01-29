@@ -1323,8 +1323,8 @@ yytnamerr (char *yyres, const char *yystr)
 ]])[
 
 static int
-yysyntax_error_arguments (const yypcontext_t *yyctx,
-                          yysymbol_type_t yyarg[], int yyargn)
+yy_syntax_error_arguments (const yypcontext_t *yyctx,
+                           yysymbol_type_t yyarg[], int yyargn)
 {
   /* Actual size of YYARG. */
   int yycount = 0;
@@ -1396,7 +1396,7 @@ yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
   YYPTRDIFF_T yysize = 0;
 
   /* Actual size of YYARG. */
-  int yycount = yysyntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
+  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
   if (yycount == YYNOMEM)
     return YYNOMEM;
 
