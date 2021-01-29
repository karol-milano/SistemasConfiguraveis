@@ -2132,7 +2132,7 @@ static yysymbol_kind_t
 yypcontext_token (const yyGLRStack *yystackp)
 {
   YYUSE (yystackp);
-  yysymbol_kind_t yytoken = yychar == ]b4_symbol(-2, id)[ ? ]b4_symbol_prefix[YYEMPTY : YYTRANSLATE (yychar);
+  yysymbol_kind_t yytoken = yychar == ]b4_symbol(-2, id)[ ? ]b4_symbol(-2, kind)[ : YYTRANSLATE (yychar);
   return yytoken;
 }
 
@@ -2151,7 +2151,7 @@ yypcontext_location (const yyGLRStack *yystackp)
 yy_syntax_error_arguments (const yyGLRStack* yystackp,
                            yysymbol_kind_t yyarg[], int yyargn)
 {
-  yysymbol_kind_t yytoken = yychar == ]b4_symbol(-2, id)[ ? ]b4_symbol_prefix[YYEMPTY : YYTRANSLATE (yychar);
+  yysymbol_kind_t yytoken = yychar == ]b4_symbol(-2, id)[ ? ]b4_symbol(-2, kind)[ : YYTRANSLATE (yychar);
   /* Actual size of YYARG. */
   int yycount = 0;
   /* There are many possibilities here to consider:
@@ -2182,7 +2182,7 @@ yy_syntax_error_arguments (const yyGLRStack* yystackp,
        one exception: it will still contain any token that will not be
        accepted due to an error action in a later state.]])[
   */
-  if (yytoken != ]b4_symbol_prefix[YYEMPTY)
+  if (yytoken != ]b4_symbol(-2, kind)[)
     {
       int yyn;
       if (yyarg)
