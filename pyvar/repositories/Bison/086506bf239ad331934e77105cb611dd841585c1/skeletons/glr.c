@@ -1482,7 +1482,7 @@ yyglrReduce (yyGLRStack* yystackp, ptrdiff_t yyk, yyRuleNum yyrule,
                      YY_CAST (long, yyk), yyrule - 1, yyrline[yyrule - 1]));
       if (yyflag != yyok)
         return yyflag;
-      YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyrule], &yysval, &yyloc);
+      YY_SYMBOL_PRINT ("-> $$ =", yylhsNonterm (yyrule), &yysval, &yyloc);
       yyglrShift (yystackp, yyk,
                   yyLRgotoState (yystackp->yytops.yystates[yyk]->yylrState,
                                  yylhsNonterm (yyrule)),
@@ -2131,10 +2131,10 @@ static int
 yyreport_syntax_error (const yyGLRStack* yystackp]b4_user_formals[);
 
 /* The token type of the lookahead of this context.  */
-static int
+static yySymbol
 yyparse_context_token (const yyGLRStack *yystackp) YY_ATTRIBUTE_UNUSED;
 
-static int
+static yySymbol
 yyparse_context_token (const yyGLRStack *yystackp)
 {
   YYUSE (yystackp);
