@@ -635,7 +635,7 @@ union yyalloc
 [[#define YYTRANSLATE(YYX)                                \
   (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
    ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
-   : YYSYMBOL_YYUNDEF)
+   : ]b4_symbol_prefix[YYUNDEF)
 
 /* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
    as returned by yylex.  */
@@ -1024,7 +1024,7 @@ yy_lac (yy_state_t *yyesa, yy_state_t **yyes,
   yy_state_t *yyesp = yyes_prev;
   /* Reduce until we encounter a shift and thereby accept the token.  */
   YYDPRINTF ((stderr, "LAC: checking lookahead %s:", yysymbol_name (yytoken)));
-  if (yytoken == YYSYMBOL_YYUNDEF)
+  if (yytoken == ]b4_symbol_prefix[YYUNDEF)
     {
       YYDPRINTF ((stderr, " Always Err\n"));
       return 1;
@@ -1154,7 +1154,7 @@ yyexpected_tokens (const yypcontext_t *yyctx,
   for (yyx = 0; yyx < YYNTOKENS; ++yyx)
     {
       yysymbol_kind_t yysym = YY_CAST (yysymbol_kind_t, yyx);
-      if (yysym != YYSYMBOL_YYERROR && yysym != YYSYMBOL_YYUNDEF)
+      if (yysym != ]b4_symbol_prefix[YYERROR && yysym != ]b4_symbol_prefix[YYUNDEF)
         switch (yy_lac (]b4_push_if([[yyps->yyesa, &yyps->yyes, &yyps->yyes_capacity, yyps->yyssp, yysym]],
                                     [[yyctx->yyesa, yyctx->yyes, yyctx->yyes_capacity, yyctx->yyssp, yysym]])[))
           {
@@ -1183,7 +1183,7 @@ yyexpected_tokens (const yypcontext_t *yyctx,
       int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
       int yyx;
       for (yyx = yyxbegin; yyx < yyxend; ++yyx)
-        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYERROR
+        if (yycheck[yyx + yyn] == yyx && yyx != ]b4_symbol_prefix[YYERROR
             && !yytable_value_is_error (yytable[yyx + yyn]))
           {
             if (!yyarg)
@@ -1356,7 +1356,7 @@ yy_syntax_error_arguments (const yypcontext_t *yyctx,
        one exception: it will still contain any token that will not be
        accepted due to an error action in a later state.]])[
   */
-  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
+  if (yyctx->yytoken != ]b4_symbol_prefix[YYEMPTY)
     {
       int yyn;]b4_lac_if([[
       YYDPRINTF ((stderr, "Constructing syntax error message\n"));]])[
@@ -1586,7 +1586,7 @@ yyparse (]m4_ifset([b4_parse_param], [b4_formals(b4_parse_param)], [void])[)]])[
   /* The return value of yyparse.  */
   int yyresult;
   /* Lookahead token as an internal (translated) token number.  */
-  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
+  yysymbol_kind_t yytoken = ]b4_symbol_prefix[YYEMPTY;
   /* The variables used to return semantic value and location from the
      action routines.  */
   YYSTYPE yyval;]b4_locations_if([[
@@ -1766,7 +1766,7 @@ yyread_pushed_token:]])[
   if (yychar <= YYEOF)
     {
       yychar = YYEOF;
-      yytoken = YYSYMBOL_YYEOF;
+      yytoken = ]b4_symbol_prefix[YYEOF;
       YYDPRINTF ((stderr, "Now at end of input.\n"));
     }
   else
@@ -1899,7 +1899,7 @@ yyreduce:
 yyerrlab:
   /* Make sure we have latest lookahead translation.  See comments at
      user semantic actions for why this is necessary.  */
-  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
+  yytoken = yychar == YYEMPTY ? ]b4_symbol_prefix[YYEMPTY : YYTRANSLATE (yychar);
 
   /* If not already recovering from an error, report this error.  */
   if (!yyerrstatus)
@@ -2008,8 +2008,8 @@ yyerrlab1:
       yyn = yypact[yystate];
       if (!yypact_value_is_default (yyn))
         {
-          yyn += YYSYMBOL_YYERROR;
-          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYERROR)
+          yyn += ]b4_symbol_prefix[YYERROR;
+          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == ]b4_symbol_prefix[YYERROR)
             {
               yyn = yytable[yyn];
               if (0 < yyn)
