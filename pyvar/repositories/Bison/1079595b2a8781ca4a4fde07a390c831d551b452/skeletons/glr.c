@@ -2198,18 +2198,18 @@ yyreportSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
 [[  {
   yybool yysize_overflow = yyfalse;
   char* yymsg = YY_NULLPTR;
-  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
+  enum { YYARGS_MAX = 5 };
   /* Internationalized format string. */
   const char *yyformat = YY_NULLPTR;
   /* Arguments of yyformat: reported tokens (one for the "unexpected",
      one per "expected"). */
-  yySymbol yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
+  yySymbol yyarg[YYARGS_MAX];
   /* Cumulated lengths of YYARG.  */
   ptrdiff_t yysize = 0;
 
   /* Actual size of YYARG. */
   int yycount
-    = yysyntax_error_arguments (yystackp, yyarg, YYERROR_VERBOSE_ARGS_MAXIMUM);
+    = yysyntax_error_arguments (yystackp, yyarg, YYARGS_MAX);
   if (yycount == -2)
     yyMemoryExhausted (yystackp);
 
