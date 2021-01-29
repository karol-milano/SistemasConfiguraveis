@@ -1367,18 +1367,17 @@ static int
 yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                 const yyparse_context_t *yyctx)
 {
-  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
+  enum { YYARGS_MAX = 5 };
   /* Internationalized format string. */
   const char *yyformat = YY_NULLPTR;
   /* Arguments of yyformat: reported tokens (one for the "unexpected",
      one per "expected"). */
-  int yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
+  int yyarg[YYARGS_MAX];
   /* Cumulated lengths of YYARG.  */
   YYPTRDIFF_T yysize = 0;
 
   /* Actual size of YYARG. */
-  int yycount
-    = yysyntax_error_arguments (yyctx, yyarg, YYERROR_VERBOSE_ARGS_MAXIMUM);
+  int yycount = yysyntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
   if (yycount == -2)
     return 2;
 
