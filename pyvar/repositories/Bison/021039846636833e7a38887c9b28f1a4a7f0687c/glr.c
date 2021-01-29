@@ -906,7 +906,7 @@ yyuserAction (yyRuleNum yyn, int yyrhslen, yyGLRStackItem* yyvsp,
 # undef YYERROR
 # define YYERROR return yyerrok, yyerr
 # undef YYRECOVERING
-# define YYRECOVERING (yystackp->yyerrState != 0)
+# define YYRECOVERING() (yystackp->yyerrState != 0)
 # undef yyclearin
 # define yyclearin (yychar = YYEMPTY)
 # undef YYFILL
