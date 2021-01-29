@@ -1483,7 +1483,7 @@ yyglrReduce (yyGLRStack* yystackp, YYPTRDIFF_T yyk, yyRuleNum yyrule,
       if (yyflag == yyerr && yystackp->yysplitPoint != YY_NULLPTR)
         YY_DPRINTF ((stderr,
                      "Parse on stack %ld rejected by rule %d (line %d).\n",
-                     YY_CAST (long, yyk), yyrule - 1, yyrline[yyrule - 1]));
+                     YY_CAST (long, yyk), yyrule - 1, yyrline[yyrule]));
       if (yyflag != yyok)
         return yyflag;
       YY_SYMBOL_PRINT ("-> $$ =", yylhsNonterm (yyrule), &yysval, &yyloc);
@@ -1510,7 +1510,7 @@ yyglrReduce (yyGLRStack* yystackp, YYPTRDIFF_T yyk, yyRuleNum yyrule,
       YY_DPRINTF ((stderr,
                    "Reduced stack %ld by rule %d (line %d); action deferred.  "
                    "Now in state %d.\n",
-                   YY_CAST (long, yyk), yyrule - 1, yyrline[yyrule - 1],
+                   YY_CAST (long, yyk), yyrule - 1, yyrline[yyrule],
                    yynewLRState));
       for (yyi = 0; yyi < yystackp->yytops.yysize; yyi += 1)
         if (yyi != yyk && yystackp->yytops.yystates[yyi] != YY_NULLPTR)
