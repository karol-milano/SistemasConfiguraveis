@@ -2088,8 +2088,8 @@ yyprocessOneStack (yyGLRStack* yystackp, ptrdiff_t yyk,
    YYARG is null, return the number of expected tokens (guaranteed to
    be less than YYNTOKENS).  */
 static int
-yyexpected_tokens (const yyGLRStack* yystackp,
-                   yysymbol_kind_t yyarg[], int yyargn)
+yypcontext_expected_tokens (const yyGLRStack* yystackp,
+                            yysymbol_kind_t yyarg[], int yyargn)
 {
   /* Actual size of YYARG. */
   int yycount = 0;
@@ -2190,7 +2190,8 @@ yy_syntax_error_arguments (const yyGLRStack* yystackp,
       if (yyarg)
         yyarg[yycount] = yytoken;
       ++yycount;
-      yyn = yyexpected_tokens (yystackp, yyarg ? yyarg + 1 : yyarg, yyargn - 1);
+      yyn = yypcontext_expected_tokens (yystackp,
+                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
       if (yyn == YYENOMEM)
         return YYENOMEM;
       else
