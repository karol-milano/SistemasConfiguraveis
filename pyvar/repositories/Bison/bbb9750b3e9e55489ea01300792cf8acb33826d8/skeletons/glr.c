@@ -341,7 +341,7 @@ static YYLTYPE yyloc_default][]b4_yyloc_default;])[
 [[#define YYTRANSLATE(YYX)                                \
   (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
    ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
-   : YYSYMBOL_YYUNDEF)
+   : ]b4_symbol_prefix[YYUNDEF)
 
 /* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
    as returned by yylex.  */
@@ -836,7 +836,7 @@ yygetToken (int *yycharp][]b4_pure_if([, yyGLRStack* yystackp])[]b4_user_formals
   if (*yycharp <= YYEOF)
     {
       *yycharp = YYEOF;
-      yytoken = YYSYMBOL_YYEOF;
+      yytoken = ]b4_symbol_prefix[YYEOF;
       YY_DPRINTF ((stderr, "Now at end of input.\n"));
     }
   else
@@ -2106,7 +2106,7 @@ yyexpected_tokens (const yyGLRStack* yystackp,
       int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
       int yyx;
       for (yyx = yyxbegin; yyx < yyxend; ++yyx)
-        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYERROR
+        if (yycheck[yyx + yyn] == yyx && yyx != ]b4_symbol_prefix[YYERROR
             && !yytable_value_is_error (yytable[yyx + yyn]))
           {
             if (!yyarg)
@@ -2135,7 +2135,7 @@ static yysymbol_kind_t
 yypcontext_token (const yyGLRStack *yystackp)
 {
   YYUSE (yystackp);
-  yysymbol_kind_t yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
+  yysymbol_kind_t yytoken = yychar == YYEMPTY ? ]b4_symbol_prefix[YYEMPTY : YYTRANSLATE (yychar);
   return yytoken;
 }
 
@@ -2154,7 +2154,7 @@ yypcontext_location (const yyGLRStack *yystackp)
 yy_syntax_error_arguments (const yyGLRStack* yystackp,
                            yysymbol_kind_t yyarg[], int yyargn)
 {
-  yysymbol_kind_t yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
+  yysymbol_kind_t yytoken = yychar == YYEMPTY ? ]b4_symbol_prefix[YYEMPTY : YYTRANSLATE (yychar);
   /* Actual size of YYARG. */
   int yycount = 0;
   /* There are many possibilities here to consider:
@@ -2185,7 +2185,7 @@ yy_syntax_error_arguments (const yyGLRStack* yystackp,
        one exception: it will still contain any token that will not be
        accepted due to an error action in a later state.]])[
   */
-  if (yytoken != YYSYMBOL_YYEMPTY)
+  if (yytoken != ]b4_symbol_prefix[YYEMPTY)
     {
       int yyn;
       if (yyarg)
@@ -2363,8 +2363,8 @@ yyrecoverSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
       int yyj = yypact[yys->yylrState];
       if (! yypact_value_is_default (yyj))
         {
-          yyj += YYSYMBOL_YYERROR;
-          if (0 <= yyj && yyj <= YYLAST && yycheck[yyj] == YYSYMBOL_YYERROR
+          yyj += ]b4_symbol_prefix[YYERROR;
+          if (0 <= yyj && yyj <= YYLAST && yycheck[yyj] == ]b4_symbol_prefix[YYERROR
               && yyisShiftAction (yytable[yyj]))
             {
               /* Shift the error token.  */
