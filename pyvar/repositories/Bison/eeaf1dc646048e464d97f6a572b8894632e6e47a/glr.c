@@ -829,7 +829,7 @@ yyfillin (yyGLRStackItem *yyvsp, int yylow0, int yylow1)
       else
         /* The effect of using yysval or yyloc (in an immediate rule) is
          * undefined.  */
-        yyvsp[i].yystate.yysemantics.yyfirstVal = NULL;
+        yyvsp[i].yystate.yysemantics.yyfirstVal = YY_NULL;
       yyvsp[i].yystate.yyloc = s->yyloc;
       s = yyvsp[i].yystate.yypred = s->yypred;
     }
@@ -1434,7 +1434,7 @@ yyglrReduce (yyGLRStack* yystackp, size_t yyk, yyRuleNum yyrule,
       YYLTYPE yyloc;])[
 
       yyflag = yydoAction (yystackp, yyk, yyrule, &yysval]b4_locuser_args([&yyloc])[);
-      if (yyflag == yyerr && yystackp->yysplitPoint != NULL)
+      if (yyflag == yyerr && yystackp->yysplitPoint != YY_NULL)
         {
           YYDPRINTF ((stderr, "Parse on stack %lu rejected by rule #%d.\n",
                      (unsigned long int) yyk, yyrule - 1));
