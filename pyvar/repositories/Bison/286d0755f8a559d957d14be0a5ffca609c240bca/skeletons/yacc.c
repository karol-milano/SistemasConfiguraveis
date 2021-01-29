@@ -1154,7 +1154,7 @@ yypcontext_expected_tokens (const yypcontext_t *yyctx,
   for (yyx = 0; yyx < YYNTOKENS; ++yyx)
     {
       yysymbol_kind_t yysym = YY_CAST (yysymbol_kind_t, yyx);
-      if (yysym != ]b4_symbol_prefix[YYERROR && yysym != ]b4_symbol_prefix[YYUNDEF)
+      if (yysym != ]b4_symbol(1, kind)[ && yysym != ]b4_symbol_prefix[YYUNDEF)
         switch (yy_lac (]b4_push_if([[yyps->yyesa, &yyps->yyes, &yyps->yyes_capacity, yyps->yyssp, yysym]],
                                     [[yyctx->yyesa, yyctx->yyes, yyctx->yyes_capacity, yyctx->yyssp, yysym]])[))
           {
@@ -1183,7 +1183,7 @@ yypcontext_expected_tokens (const yypcontext_t *yyctx,
       int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
       int yyx;
       for (yyx = yyxbegin; yyx < yyxend; ++yyx)
-        if (yycheck[yyx + yyn] == yyx && yyx != ]b4_symbol_prefix[YYERROR
+        if (yycheck[yyx + yyn] == yyx && yyx != ]b4_symbol(1, kind)[
             && !yytable_value_is_error (yytable[yyx + yyn]))
           {
             if (!yyarg)
@@ -2009,8 +2009,8 @@ yyerrlab1:
       yyn = yypact[yystate];
       if (!yypact_value_is_default (yyn))
         {
-          yyn += ]b4_symbol_prefix[YYERROR;
-          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == ]b4_symbol_prefix[YYERROR)
+          yyn += ]b4_symbol(1, kind)[;
+          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == ]b4_symbol(1, kind)[)
             {
               yyn = yytable[yyn];
               if (0 < yyn)
