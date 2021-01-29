@@ -106,7 +106,7 @@ enum yysymbol_kind_t
 {
   YYSYMBOL_YYEMPTY = -2,
   YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
-  YYSYMBOL_YYERRCODE = 1,                  /* error  */
+  YYSYMBOL_YYerror = 1,                    /* error  */
   YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
   YYSYMBOL_STRING = 3,                     /* "string"  */
   YYSYMBOL_TSTRING = 4,                    /* "translatable string"  */
@@ -1612,7 +1612,7 @@ yypcontext_expected_tokens (const yypcontext_t *yyctx,
   for (yyx = 0; yyx < YYNTOKENS; ++yyx)
     {
       yysymbol_kind_t yysym = YY_CAST (yysymbol_kind_t, yyx);
-      if (yysym != YYSYMBOL_YYERRCODE && yysym != YYSYMBOL_YYUNDEF)
+      if (yysym != YYSYMBOL_YYerror && yysym != YYSYMBOL_YYUNDEF)
         switch (yy_lac (yyctx->yyesa, yyctx->yyes, yyctx->yyes_capacity, yyctx->yyssp, yysym))
           {
           case YYENOMEM:
@@ -1960,14 +1960,14 @@ yybackup:
       yytoken = YYSYMBOL_YYEOF;
       YYDPRINTF ((stderr, "Now at end of input.\n"));
     }
-  else if (yychar == GRAM_ERRCODE)
+  else if (yychar == GRAM_error)
     {
       /* The scanner already issued an error message, process directly
          to error recovery.  But do not keep the error token as
          lookahead, it is too special and may lead us to an endless
          loop in error recovery. */
       yychar = GRAM_UNDEF;
-      yytoken = YYSYMBOL_YYERRCODE;
+      yytoken = YYSYMBOL_YYerror;
       yyerror_range[1] = yylloc;
       goto yyerrlab1;
     }
@@ -2705,8 +2705,8 @@ yyerrlab1:
       yyn = yypact[yystate];
       if (!yypact_value_is_default (yyn))
         {
-          yyn += YYSYMBOL_YYERRCODE;
-          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYERRCODE)
+          yyn += YYSYMBOL_YYerror;
+          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
             {
               yyn = yytable[yyn];
               if (0 < yyn)
