@@ -907,8 +907,8 @@ yyuserAction (yyRuleNum yyrule, int yyrhslen, yyGLRStackItem* yyvsp,
   const yybool yynormal YY_ATTRIBUTE_UNUSED = yystackp->yysplitPoint == YY_NULLPTR;
   int yylow = 1;
 ]b4_parse_param_use([yyvalp], [yylocp])dnl
-[  YYUSE (yyk);
-  YYUSE (yyrhslen);
+[  YY_USE (yyk);
+  YY_USE (yyrhslen);
 # undef yyerrok
 # define yyerrok (yystackp->yyerrState = 0)
 # undef YYACCEPT
@@ -975,8 +975,8 @@ yyuserAction (yyRuleNum yyrule, int yyrhslen, yyGLRStackItem* yyvsp,
 static void
 yyuserMerge (int yyn, YYSTYPE* yy0, YYSTYPE* yy1)
 {
-  YYUSE (yy0);
-  YYUSE (yy1);
+  YY_USE (yy0);
+  YY_USE (yy1);
 
   switch (yyn)
     {
@@ -1814,8 +1814,8 @@ static YYRESULTTAG
 yyreportAmbiguity (yySemanticOption* yyx0,
                    yySemanticOption* yyx1]b4_pure_formals[)
 {
-  YYUSE (yyx0);
-  YYUSE (yyx1);
+  YY_USE (yyx0);
+  YY_USE (yyx1);
 
 #if ]b4_api_PREFIX[DEBUG
   YY_FPRINTF ((stderr, "Ambiguity detected.\n"));
@@ -2165,7 +2165,7 @@ yypcontext_token (const yyGLRStack *yystackp) YY_ATTRIBUTE_UNUSED;
 static yysymbol_kind_t
 yypcontext_token (const yyGLRStack *yystackp)
 {
-  YYUSE (yystackp);
+  YY_USE (yystackp);
   yysymbol_kind_t yytoken = yychar == ]b4_symbol(empty, id)[ ? ]b4_symbol(empty, kind)[ : YYTRANSLATE (yychar);
   return yytoken;
 }
@@ -2177,7 +2177,7 @@ yypcontext_location (const yyGLRStack *yystackp) YY_ATTRIBUTE_UNUSED;
 static YYLTYPE *
 yypcontext_location (const yyGLRStack *yystackp)
 {
-  YYUSE (yystackp);
+  YY_USE (yystackp);
   return &yylloc;
 }]])],
          [detailed\|verbose],
