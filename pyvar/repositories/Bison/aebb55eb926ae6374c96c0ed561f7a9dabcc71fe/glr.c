@@ -868,9 +868,8 @@ static void yyfillin (yyGLRStackItem *, int, int) __attribute__ ((__unused__));
 static void
 yyfillin (yyGLRStackItem *yyvsp, int yylow0, int yylow1)
 {
-  yyGLRState* s;
   int i;
-  s = yyvsp[yylow0].yystate.yypred;
+  yyGLRState *s = yyvsp[yylow0].yystate.yypred;
   for (i = yylow0-1; i >= yylow1; i -= 1)
     {
       YYASSERT (s->yyresolved);
@@ -1198,9 +1197,9 @@ yyexpandGLRStack (yyGLRStack* yystackp)
 {
   yyGLRStackItem* yynewItems;
   yyGLRStackItem* yyp0, *yyp1;
-  size_t yysize, yynewSize;
+  size_t yynewSize;
   size_t yyn;
-  yysize = yystackp->yynextFree - yystackp->yyitems;
+  size_t yysize = yystackp->yynextFree - yystackp->yyitems;
   if (YYMAXDEPTH - YYHEADROOM < yysize)
     yyMemoryExhausted (yystackp);
   yynewSize = 2*yysize;
@@ -1223,7 +1222,7 @@ yyexpandGLRStack (yyGLRStack* yystackp)
               YYRELOC (yyp0, yyp1, yys0->yypred, yystate);
           if (! yys0->yyresolved && yys0->yysemantics.yyfirstVal != YY_NULL)
             yys1->yysemantics.yyfirstVal =
-              YYRELOC(yyp0, yyp1, yys0->yysemantics.yyfirstVal, yyoption);
+              YYRELOC (yyp0, yyp1, yys0->yysemantics.yyfirstVal, yyoption);
         }
       else
         {
@@ -1509,8 +1508,8 @@ yyglrReduce (yyGLRStack* yystackp, size_t yyk, yyRuleNum yyrule,
       for (yyi = 0; yyi < yystackp->yytops.yysize; yyi += 1)
         if (yyi != yyk && yystackp->yytops.yystates[yyi] != YY_NULL)
           {
-            yyGLRState* yyp, *yysplit = yystackp->yysplitPoint;
-            yyp = yystackp->yytops.yystates[yyi];
+            yyGLRState *yysplit = yystackp->yysplitPoint;
+            yyGLRState *yyp = yystackp->yytops.yystates[yyi];
             while (yyp != yys && yyp != yysplit && yyp->yyposn >= yyposn)
               {
                 if (yyp->yylrState == yynewLRState && yyp->yypred == yys)
@@ -1623,10 +1622,8 @@ yymergeOptionSets (yySemanticOption* yyy0, yySemanticOption* yyy1)
         }
       else
         {
-          yySemanticOption** yyz0p;
-          yySemanticOption* yyz1;
-          yyz0p = &yys0->yysemantics.yyfirstVal;
-          yyz1 = yys1->yysemantics.yyfirstVal;
+          yySemanticOption** yyz0p = &yys0->yysemantics.yyfirstVal;
+          yySemanticOption* yyz1 = yys1->yysemantics.yyfirstVal;
           while (YYID (yytrue))
             {
               if (yyz1 == *yyz0p || yyz1 == YY_NULL)
@@ -1707,14 +1704,9 @@ yyresolveAction (yySemanticOption* yyopt, yyGLRStack* yystackp,
                  YYSTYPE* yyvalp]b4_locuser_formals[)
 {
   yyGLRStackItem yyrhsVals[YYMAXRHS + YYMAXLEFT + 1];
-  int yynrhs;
-  int yychar_current;
-  YYSTYPE yylval_current;]b4_locations_if([
-  YYLTYPE yylloc_current;])[
-  YYRESULTTAG yyflag;
-
-  yynrhs = yyrhsLength (yyopt->yyrule);
-  yyflag = yyresolveStates (yyopt->yystate, yynrhs, yystackp]b4_user_args[);
+  int yynrhs = yyrhsLength (yyopt->yyrule);
+  YYRESULTTAG yyflag =
+    yyresolveStates (yyopt->yystate, yynrhs, yystackp]b4_user_args[);
   if (yyflag != yyok)
     {
       yyGLRState *yys;
@@ -1727,18 +1719,20 @@ yyresolveAction (yySemanticOption* yyopt, yyGLRStack* yystackp,
   if (yynrhs == 0)
     /* Set default location.  */
     yyrhsVals[YYMAXRHS + YYMAXLEFT - 1].yystate.yyloc = yyopt->yystate->yyloc;]])[
-  yychar_current = yychar;
-  yylval_current = yylval;]b4_locations_if([
-  yylloc_current = yylloc;])[
-  yychar = yyopt->yyrawchar;
-  yylval = yyopt->yyval;]b4_locations_if([
-  yylloc = yyopt->yyloc;])[
-  yyflag = yyuserAction (yyopt->yyrule, yynrhs,
-                         yyrhsVals + YYMAXRHS + YYMAXLEFT - 1,
-                         yystackp, yyvalp]b4_locuser_args[);
-  yychar = yychar_current;
-  yylval = yylval_current;]b4_locations_if([
-  yylloc = yylloc_current;])[
+  {
+    int yychar_current = yychar;
+    YYSTYPE yylval_current = yylval;]b4_locations_if([
+    YYLTYPE yylloc_current = yylloc;])[
+    yychar = yyopt->yyrawchar;
+    yylval = yyopt->yyval;]b4_locations_if([
+    yylloc = yyopt->yyloc;])[
+    yyflag = yyuserAction (yyopt->yyrule, yynrhs,
+                           yyrhsVals + YYMAXRHS + YYMAXLEFT - 1,
+                           yystackp, yyvalp]b4_locuser_args[);
+    yychar = yychar_current;
+    yylval = yylval_current;]b4_locations_if([
+    yylloc = yylloc_current;])[
+  }
   return yyflag;
 }
 
@@ -1822,13 +1816,9 @@ yyresolveLocations (yyGLRState* yys1, int yyn1,
       yyresolveLocations (yys1->yypred, yyn1 - 1, yystackp]b4_user_args[);
       if (!yys1->yyresolved)
         {
-          yySemanticOption *yyoption;
           yyGLRStackItem yyrhsloc[1 + YYMAXRHS];
           int yynrhs;
-          int yychar_current;
-          YYSTYPE yylval_current;
-          YYLTYPE yylloc_current;
-          yyoption = yys1->yysemantics.yyfirstVal;
+          yySemanticOption *yyoption = yys1->yysemantics.yyfirstVal;
           YYASSERT (yyoption != YY_NULL);
           yynrhs = yyrhsLength (yyoption->yyrule);
           if (yynrhs > 0)
@@ -1854,16 +1844,18 @@ yyresolveLocations (yyGLRState* yys1, int yyn1,
               yyGLRState *yyprevious = yyoption->yystate;
               yyrhsloc[0].yystate.yyloc = yyprevious->yyloc;
             }
-          yychar_current = yychar;
-          yylval_current = yylval;
-          yylloc_current = yylloc;
-          yychar = yyoption->yyrawchar;
-          yylval = yyoption->yyval;
-          yylloc = yyoption->yyloc;
-          YYLLOC_DEFAULT ((yys1->yyloc), yyrhsloc, yynrhs);
-          yychar = yychar_current;
-          yylval = yylval_current;
-          yylloc = yylloc_current;
+          {
+            int yychar_current = yychar;
+            YYSTYPE yylval_current = yylval;
+            YYLTYPE yylloc_current = yylloc;
+            yychar = yyoption->yyrawchar;
+            yylval = yyoption->yyval;
+            yylloc = yyoption->yyloc;
+            YYLLOC_DEFAULT ((yys1->yyloc), yyrhsloc, yynrhs);
+            yychar = yychar_current;
+            yylval = yylval_current;
+            yylloc = yylloc_current;
+          }
         }
     }
 }]])[
