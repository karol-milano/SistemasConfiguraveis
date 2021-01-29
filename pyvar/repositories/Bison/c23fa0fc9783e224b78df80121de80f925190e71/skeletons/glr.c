@@ -1385,11 +1385,10 @@ yydoAction (yyGLRStack* yystackp, size_t yyk, yyRuleNum yyrule,
     }
   else
     {
-      int yyi;
-      yyGLRState* yys;
       yyGLRStackItem yyrhsVals[YYMAXRHS + YYMAXLEFT + 1];
-      yys = yyrhsVals[YYMAXRHS + YYMAXLEFT].yystate.yypred
-        = yystackp->yytops.yystates[yyk];]b4_locations_if([[
+      yyGLRState* yys = yyrhsVals[YYMAXRHS + YYMAXLEFT].yystate.yypred
+        = yystackp->yytops.yystates[yyk];
+      int yyi;]b4_locations_if([[
       if (yynrhs == 0)
         /* Set default location.  */
         yyrhsVals[YYMAXRHS + YYMAXLEFT - 1].yystate.yyloc = yys->yyloc;]])[
