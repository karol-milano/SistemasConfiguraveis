@@ -2188,7 +2188,9 @@ yy_syntax_error_arguments (const yyGLRStack* yystackp,
   if (yytoken != YYSYMBOL_YYEMPTY)
     {
       int yyn;
-      yyarg[yycount++] = yytoken;
+      if (yyarg)
+        yyarg[yycount] = yytoken;
+      ++yycount;
       yyn = yyexpected_tokens (yystackp, yyarg ? yyarg + 1 : yyarg, yyargn - 1);
       if (yyn == YYNOMEM)
         return YYNOMEM;
