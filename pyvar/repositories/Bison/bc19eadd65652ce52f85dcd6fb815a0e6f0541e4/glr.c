@@ -763,7 +763,7 @@ yyfill (yyGLRStackItem *yyvsp, int *yylow, int yylow1, yybool yynormal)
  *  (@@$).  Returns yyok for normal return, yyaccept for YYACCEPT,
  *  yyerr for YYERROR, yyabort for YYABORT.  */
 static YYRESULTTAG
-yyuserAction (yyRuleNum yyn, int yyrhslen, yyGLRStackItem* yyvsp,
+yyuserAction (yyRuleNum yyn, size_t yyrhslen, yyGLRStackItem* yyvsp,
               yyGLRStack* yystackp,
               YYSTYPE* yyvalp]b4_locuser_formals[)
 {
