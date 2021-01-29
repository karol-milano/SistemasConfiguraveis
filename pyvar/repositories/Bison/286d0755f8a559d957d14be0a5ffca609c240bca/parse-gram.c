@@ -106,7 +106,7 @@ enum yysymbol_kind_t
 {
   YYSYMBOL_YYEMPTY = -2,
   YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
-  YYSYMBOL_YYERROR = 1,                    /* error  */
+  YYSYMBOL_YYERRCODE = 1,                  /* error  */
   YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
   YYSYMBOL_STRING = 3,                     /* "string"  */
   YYSYMBOL_TSTRING = 4,                    /* "translatable string"  */
@@ -1612,7 +1612,7 @@ yypcontext_expected_tokens (const yypcontext_t *yyctx,
   for (yyx = 0; yyx < YYNTOKENS; ++yyx)
     {
       yysymbol_kind_t yysym = YY_CAST (yysymbol_kind_t, yyx);
-      if (yysym != YYSYMBOL_YYERROR && yysym != YYSYMBOL_YYUNDEF)
+      if (yysym != YYSYMBOL_YYERRCODE && yysym != YYSYMBOL_YYUNDEF)
         switch (yy_lac (yyctx->yyesa, yyctx->yyes, yyctx->yyes_capacity, yyctx->yyssp, yysym))
           {
           case YYENOMEM:
@@ -2695,8 +2695,8 @@ yyerrlab1:
       yyn = yypact[yystate];
       if (!yypact_value_is_default (yyn))
         {
-          yyn += YYSYMBOL_YYERROR;
-          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYERROR)
+          yyn += YYSYMBOL_YYERRCODE;
+          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYERRCODE)
             {
               yyn = yytable[yyn];
               if (0 < yyn)
