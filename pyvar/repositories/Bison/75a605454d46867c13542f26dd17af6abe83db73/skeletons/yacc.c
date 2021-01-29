@@ -1147,7 +1147,7 @@ yyexpected_tokens (const yyparse_context_t *yyctx,
 ]b4_lac_if([[
   int yyx;
   for (yyx = 0; yyx < YYNTOKENS; ++yyx)
-    if (yyx != YYSYMBOL_error && yyx != YYSYMBOL_YYUNDEF)
+    if (yyx != YYSYMBOL_YYERROR && yyx != YYSYMBOL_YYUNDEF)
       switch (yy_lac (]b4_push_if([[yyps->yyesa, &yyps->yyes, &yyps->yyes_capacity, yyps->yyssp, yyx]],
                                   [[yyctx->yyesa, yyctx->yyes, yyctx->yyes_capacity, yyctx->yyssp, yyx]])[))
         {
@@ -1175,7 +1175,7 @@ yyexpected_tokens (const yyparse_context_t *yyctx,
       int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
       int yyx;
       for (yyx = yyxbegin; yyx < yyxend; ++yyx)
-        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_error
+        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYERROR
             && !yytable_value_is_error (yytable[yyx + yyn]))
           {
             if (!yyarg)
@@ -1998,8 +1998,8 @@ yyerrlab1:
       yyn = yypact[yystate];
       if (!yypact_value_is_default (yyn))
         {
-          yyn += YYSYMBOL_error;
-          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_error)
+          yyn += YYSYMBOL_YYERROR;
+          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYERROR)
             {
               yyn = yytable[yyn];
               if (0 < yyn)
