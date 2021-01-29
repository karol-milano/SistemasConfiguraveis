@@ -771,7 +771,8 @@ yyuserAction (yyRuleNum yyn, size_t yyrhslen, yyGLRStackItem* yyvsp,
     (yystackp->yysplitPoint == YY_NULL);
   int yylow;
 ]b4_parse_param_use([yyvalp], [yylocp])dnl
-[# undef yyerrok
+[  YYUSE (yyrhslen);
+# undef yyerrok
 # define yyerrok (yystackp->yyerrState = 0)
 # undef YYACCEPT
 # define YYACCEPT return yyaccept
