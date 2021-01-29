@@ -781,7 +781,8 @@ yyuserAction (yyRuleNum yyn, int yyrhslen, yyGLRStackItem* yyvsp,
   else
     *yyvalp = yyvsp[YYFILL (1-yyrhslen)].yystate.yysemantics.yysval;
   YYLLOC_DEFAULT (*yylocp, yyvsp - yyrhslen, yyrhslen);
-]
+]b4_location_if([[  yystack->yyerror_range[1].yystate.yyloc = *yylocp;
+]])
   switch (yyn)
     {
       b4_actions
