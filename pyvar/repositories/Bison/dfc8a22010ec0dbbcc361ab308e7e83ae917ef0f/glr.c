@@ -1200,8 +1200,7 @@ yyglrReduce (yyGLRStack* yystack, size_t yyk, yyRuleNum yyrule,
       yyupdateSplit (yystack, yys);
       yynewLRState = yyLRgotoState (yys->yylrState, yylhsNonterm (yyrule));
       YYDPRINTF ((stderr,
-		  "Reduced stack %lu by rule #%d; action deferred. "
-		  "Now in state %d.\n",
+		  "Reduced stack %lu by rule #%d; action deferred. Now in state %d.\n",
 		  (unsigned long int) yyk, yyrule - 1, yynewLRState));
       for (yyi = 0; yyi < yystack->yytops.yysize; yyi += 1)
 	if (yyi != yyk && yystack->yytops.yystates[yyi] != NULL)
