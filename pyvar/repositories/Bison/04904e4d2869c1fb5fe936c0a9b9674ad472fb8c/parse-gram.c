@@ -105,7 +105,7 @@ enum yysymbol_type_t
 {
   YYSYMBOL_YYEMPTY = -2,
   YYSYMBOL_YYEOF = 0,
-  YYSYMBOL_error = 1,
+  YYSYMBOL_YYERROR = 1,
   YYSYMBOL_YYUNDEF = 2,
   YYSYMBOL_STRING = 3,
   YYSYMBOL_TSTRING = 4,
@@ -1594,7 +1594,7 @@ yyexpected_tokens (const yyparse_context_t *yyctx,
 
   int yyx;
   for (yyx = 0; yyx < YYNTOKENS; ++yyx)
-    if (yyx != YYSYMBOL_error && yyx != YYSYMBOL_YYUNDEF)
+    if (yyx != YYSYMBOL_YYERROR && yyx != YYSYMBOL_YYUNDEF)
       switch (yy_lac (yyctx->yyesa, yyctx->yyes, yyctx->yyes_capacity, yyctx->yyssp, yyx))
         {
         case YYNOMEM:
@@ -2676,8 +2676,8 @@ yyerrlab1:
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
