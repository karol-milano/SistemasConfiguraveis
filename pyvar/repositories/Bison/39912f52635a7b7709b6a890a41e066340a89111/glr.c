@@ -231,6 +231,7 @@ static YYLTYPE yyloc_default;
 
 /* YYFINAL -- State number of the termination state. */
 #define YYFINAL  ]b4_final_state_number[
+/* YYLAST -- Last index in YYTABLE.  */
 #define YYLAST   ]b4_last[
 
 /* YYNTOKENS -- Number of terminals. */
@@ -739,7 +740,7 @@ yyLRgotoState (yyStateNum yystate, yySymbol yylhs)
 static inline bool
 yyisShiftAction (int yyaction)
 {
-  return yyaction > 0;
+  return 0 < yyaction;
 }
 
 static inline bool
@@ -825,14 +826,14 @@ yyexpandGLRStack (yyGLRStack* yystack)
   size_t yysize, yynewSize;
   size_t yyn;
   yysize = yystack->yynextFree - yystack->yyitems;
-  if (yysize >= YYMAXDEPTH)
+  if (YYMAXDEPTH <= yysize)
     yyFail (yystack, "parsing stack overflow (%d items)", yysize);
   yynewSize = 2*yysize;
-  if (yynewSize > YYMAXDEPTH)
+  if (YYMAXDEPTH < yynewSize)
     yynewSize = YYMAXDEPTH;
   yyinitGLRStack (&yynewStack, yynewSize);
   for (yyp0 = yystack->yyitems, yyp1 = yynewStack.yyitems, yyn = yysize;
-       yyn > 0;
+       0 < yyn;
        yyn -= 1, yyp0 += 1, yyp1 += 1)
     {
       *yyp1 = *yyp0;
@@ -1024,7 +1025,7 @@ yydoAction (yyGLRStack* yystack, int yyk, yyRuleNum yyrule,
       int yyi;
       yyGLRState* yys;
       yyGLRStackItem yyrhsVals[YYMAXRHS];
-      for (yyi = yynrhs-1, yys = yystack->yytops.yystates[yyk]; yyi >= 0;
+      for (yyi = yynrhs-1, yys = yystack->yytops.yystates[yyk]; 0 <= yyi;
 	   yyi -= 1, yys = yys->yypred)
 	{
 	  assert (yys->yypred != NULL);
@@ -1078,7 +1079,7 @@ yyglrReduce (yyGLRStack* yystack, size_t yyk, yyRuleNum yyrule,
 	  YYDPRINTF ((stderr, "Reducing stack %d by rule %d (line %d),",
 		      yyk, yyrule - 1, yyrline[yyrule]));
 	  /* Print the symbols being reduced, and their result.  */
-	  for (yyi = yyprhs[yyrule]; yyrhs[yyi] >= 0; yyi++)
+	  for (yyi = yyprhs[yyrule]; 0 <= yyrhs[yyi]; yyi++)
 	    YYFPRINTF (stderr, "%s ", yytokenName (yyrhs[yyi]));
 	  YYFPRINTF (stderr, " -> %s\n", yytokenName (yyr1[yyrule]));
 	}
@@ -1099,7 +1100,7 @@ yyglrReduce (yyGLRStack* yystack, size_t yyk, yyRuleNum yyrule,
       yyStateNum yynewLRState;
 
       for (yys = yystack->yytops.yystates[yyk], yyn = yyrhsLength (yyrule);
-	   yyn > 0; yyn -= 1)
+	   0 < yyn; yyn -= 1)
 	{
 	  yys = yys->yypred;
 	  assert (yys != NULL);
@@ -1222,7 +1223,7 @@ yypreference (yySemanticOption* y0, yySemanticOption* y1)
     return 0;
   if (p0 < p1)
     return 3;
-  if (p0 > p1)
+  if (p1 < p0)
     return 2;
   return 0;
 }
@@ -1235,7 +1236,7 @@ static YYRESULTTAG
 yyresolveStates (yyGLRState* yys, int yyn, yyGLRStack* yystack)
 {
   YYRESULTTAG yyflag;
-  if (yyn > 0)
+  if (0 < yyn)
     {
       assert (yys->yypred != NULL);
       yyflag = yyresolveStates (yys->yypred, yyn-1, yystack);
@@ -1263,7 +1264,7 @@ yyresolveAction (yySemanticOption* yyopt, yyGLRStack* yystack,
 
   yynrhs = yyrhsLength (yyopt->yyrule);
   YYCHK (yyresolveStates (yyopt->yystate, yynrhs, yystack));
-  for (yyi = yynrhs-1, yys = yyopt->yystate; yyi >= 0;
+  for (yyi = yynrhs-1, yys = yyopt->yystate; 0 <= yyi;
        yyi -= 1, yys = yys->yypred)
     {
       assert (yys->yypred != NULL);
@@ -1294,14 +1295,14 @@ static void yyreportTree (yySemanticOption* yyx, int yyindent)
   yyGLRState* yys;
   yyGLRState* yystates[YYMAXRHS];
 
-  for (yyi = yynrhs, yys = yyx->yystate; yyi > 0; yyi -= 1, yys = yys->yypred)
+  for (yyi = yynrhs, yys = yyx->yystate; 0 < yyi; yyi -= 1, yys = yys->yypred)
     yystates[yyi] = yys;
   if (yys == NULL)
     yystates[0] = &YYLEFTMOST_STATE;
   else
     yystates[0] = yys;
 
-  if (yys->yyposn+1 > yyx->yystate->yyposn)
+  if (yyx->yystate->yyposn < yys->yyposn + 1)
     YYFPRINTF (stderr, "%*s%s -> <Rule %d, empty>\n",
 	       yyindent, "", yytokenName (yylhsNonterm (yyx->yyrule)),
 	       yyx->yyrule);
@@ -1735,7 +1736,7 @@ yyparse (YYPARSE_PARAM_ARG)
 		    yytoken = YYEMPTY;
 		  yyposn += 1;
 		  yyglrShift (&yystack, 0, yyaction, yyposn, yylval, yyllocp);
-		  if (yystack.yyerrState > 0)
+		  if (0 < yystack.yyerrState)
 		    yystack.yyerrState -= 1;
 		  YYDPRINTF ((stderr, "Entering state %d\n",
 			      yystack.yytops.yystates[0]->yylrState));
