@@ -1318,11 +1318,10 @@ yyglrReduce (yyGLRStack* yystackp, size_t yyk, yyRuleNum yyrule,
 
   if (yyforceEval || yystackp->yysplitPoint == YY_NULL)
     {
-      YYRESULTTAG yyflag;
-      YYSTYPE yysval;]b4_locations_if([
-      YYLTYPE yyloc;])[
+      YYSTYPE yysval;]b4_locations_if([[
+      YYLTYPE yyloc;]])[
 
-      yyflag = yydoAction (yystackp, yyk, yyrule, &yysval]b4_locuser_args([&yyloc])[);
+      YYRESULTTAG yyflag = yydoAction (yystackp, yyk, yyrule, &yysval]b4_locuser_args([&yyloc])[);
       if (yyflag == yyerr && yystackp->yysplitPoint != YY_NULL)
         {
           YYDPRINTF ((stderr, "Parse on stack %lu rejected by rule #%d.\n",
