@@ -1360,7 +1360,9 @@ yy_syntax_error_arguments (const yypcontext_t *yyctx,
     {
       int yyn;]b4_lac_if([[
       YYDPRINTF ((stderr, "Constructing syntax error message\n"));]])[
-      yyarg[yycount++] = yyctx->yytoken;
+      if (yyarg)
+        yyarg[yycount] = yyctx->yytoken;
+      ++yycount;
       yyn = yyexpected_tokens (yyctx, yyarg ? yyarg + 1 : yyarg, yyargn - 1);
       if (yyn == YYNOMEM)
         return YYNOMEM;]b4_lac_if([[
