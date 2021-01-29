@@ -1442,8 +1442,9 @@ yyglrReduce (yyGLRStack* yystackp, ptrdiff_t yyk, yyRuleNum yyrule,
       YYRESULTTAG yyflag = yydoAction (yystackp, yyk, yyrule, &yysval]b4_locuser_args([&yyloc])[);
       if (yyflag == yyerr && yystackp->yysplitPoint != YY_NULLPTR)
         {
-          YYDPRINTF ((stderr, "Parse on stack %ld rejected by rule #%d.\n",
-                     (long) yyk, yyrule - 1));
+          YYDPRINTF ((stderr,
+                      "Parse on stack %ld rejected by rule %d (line %d).\n",
+                      (long) yyk, yyrule - 1, yyrline[yyrule - 1]));
         }
       if (yyflag != yyok)
         return yyflag;
@@ -1469,9 +1470,9 @@ yyglrReduce (yyGLRStack* yystackp, ptrdiff_t yyk, yyRuleNum yyrule,
       yyupdateSplit (yystackp, yys);
       yynewLRState = yyLRgotoState (yys->yylrState, yylhsNonterm (yyrule));
       YYDPRINTF ((stderr,
-                  "Reduced stack %ld by rule #%d; action deferred.  "
+                  "Reduced stack %ld by rule %d (line %d); action deferred.  "
                   "Now in state %d.\n",
-                  (long) yyk, yyrule - 1, yynewLRState));
+                  (long) yyk, yyrule - 1, yyrline[yyrule - 1], yynewLRState));
       for (yyi = 0; yyi < yystackp->yytops.yysize; yyi += 1)
         if (yyi != yyk && yystackp->yytops.yystates[yyi] != YY_NULLPTR)
           {
