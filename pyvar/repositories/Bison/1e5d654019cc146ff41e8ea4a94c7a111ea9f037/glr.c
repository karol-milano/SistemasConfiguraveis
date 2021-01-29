@@ -852,8 +852,8 @@ yyuserAction (yyRuleNum yyn, int yyrhslen, yyGLRStackItem* yyvsp,
   yybool yynormal __attribute__ ((__unused__)) =
     (yystackp->yysplitPoint == NULL);
   int yylow;
-]b4_parse_param_use([yyvalp], [yylocp])[
-# undef yyerrok
+]b4_parse_param_use([yyvalp], [yylocp])dnl
+[# undef yyerrok
 # define yyerrok (yystackp->yyerrState = 0)
 # undef YYACCEPT
 # define YYACCEPT return yyaccept
