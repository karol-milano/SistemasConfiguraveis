@@ -672,7 +672,7 @@ static void yyexpandGLRStack (yyGLRStack* yystackp);
 static _Noreturn void
 yyFail (yyGLRStack* yystackp]b4_pure_formals[, const char* yymsg)
 {
-  if (yymsg != YY_NULL)
+  if (yymsg != YY_NULLPTR)
     yyerror (]b4_yyerror_args[yymsg);
   YYLONGJMP (yystackp->yyexception_buffer, 1);
 }
@@ -715,7 +715,7 @@ yyfillin (yyGLRStackItem *yyvsp, int yylow0, int yylow1)
       else
         /* The effect of using yysval or yyloc (in an immediate rule) is
          * undefined.  */
-        yyvsp[i].yystate.yysemantics.yyfirstVal = YY_NULL;]b4_locations_if([[
+        yyvsp[i].yystate.yysemantics.yyfirstVal = YY_NULLPTR;]b4_locations_if([[
       yyvsp[i].yystate.yyloc = s->yyloc;]])[
       s = yyvsp[i].yystate.yypred = s->yypred;
     }
@@ -747,7 +747,7 @@ yyuserAction (yyRuleNum yyn, size_t yyrhslen, yyGLRStackItem* yyvsp,
               yyGLRStack* yystackp,
               YYSTYPE* yyvalp]b4_locuser_formals[)
 {
-  yybool yynormal YY_ATTRIBUTE_UNUSED = (yystackp->yysplitPoint == YY_NULL);
+  yybool yynormal YY_ATTRIBUTE_UNUSED = (yystackp->yysplitPoint == YY_NULLPTR);
   int yylow;
 ]b4_parse_param_use([yyvalp], [yylocp])dnl
 [  YYUSE (yyrhslen);
@@ -834,7 +834,7 @@ yydestroyGLRState (char const *yymsg, yyGLRState *yys]b4_user_formals[)
             YYFPRINTF (stderr, "%s unresolved", yymsg);
           else
             YYFPRINTF (stderr, "%s incomplete", yymsg);
-          YY_SYMBOL_PRINT ("", yystos[yys->yylrState], YY_NULL, &yys->yyloc);
+          YY_SYMBOL_PRINT ("", yystos[yys->yylrState], YY_NULLPTR, &yys->yyloc);
         }
 #endif
 
@@ -987,7 +987,7 @@ yyinitStateSet (yyGLRStateSet* yyset)
   yyset->yystates = (yyGLRState**) YYMALLOC (16 * sizeof yyset->yystates[0]);
   if (! yyset->yystates)
     return yyfalse;
-  yyset->yystates[0] = YY_NULL;
+  yyset->yystates[0] = YY_NULLPTR;
   yyset->yylookaheadNeeds =
     (yybool*) YYMALLOC (16 * sizeof yyset->yylookaheadNeeds[0]);
   if (! yyset->yylookaheadNeeds)
@@ -1017,8 +1017,8 @@ yyinitGLRStack (yyGLRStack* yystackp, size_t yysize)
   if (!yystackp->yyitems)
     return yyfalse;
   yystackp->yynextFree = yystackp->yyitems;
-  yystackp->yysplitPoint = YY_NULL;
-  yystackp->yylastDeleted = YY_NULL;
+  yystackp->yysplitPoint = YY_NULLPTR;
+  yystackp->yylastDeleted = YY_NULLPTR;
   return yyinitStateSet (&yystackp->yytops);
 }
 
@@ -1057,10 +1057,10 @@ yyexpandGLRStack (yyGLRStack* yystackp)
         {
           yyGLRState* yys0 = &yyp0->yystate;
           yyGLRState* yys1 = &yyp1->yystate;
-          if (yys0->yypred != YY_NULL)
+          if (yys0->yypred != YY_NULLPTR)
             yys1->yypred =
               YYRELOC (yyp0, yyp1, yys0->yypred, yystate);
-          if (! yys0->yyresolved && yys0->yysemantics.yyfirstVal != YY_NULL)
+          if (! yys0->yyresolved && yys0->yysemantics.yyfirstVal != YY_NULLPTR)
             yys1->yysemantics.yyfirstVal =
               YYRELOC (yyp0, yyp1, yys0->yysemantics.yyfirstVal, yyoption);
         }
@@ -1068,18 +1068,18 @@ yyexpandGLRStack (yyGLRStack* yystackp)
         {
           yySemanticOption* yyv0 = &yyp0->yyoption;
           yySemanticOption* yyv1 = &yyp1->yyoption;
-          if (yyv0->yystate != YY_NULL)
+          if (yyv0->yystate != YY_NULLPTR)
             yyv1->yystate = YYRELOC (yyp0, yyp1, yyv0->yystate, yystate);
-          if (yyv0->yynext != YY_NULL)
+          if (yyv0->yynext != YY_NULLPTR)
             yyv1->yynext = YYRELOC (yyp0, yyp1, yyv0->yynext, yyoption);
         }
     }
-  if (yystackp->yysplitPoint != YY_NULL)
+  if (yystackp->yysplitPoint != YY_NULLPTR)
     yystackp->yysplitPoint = YYRELOC (yystackp->yyitems, yynewItems,
                                       yystackp->yysplitPoint, yystate);
 
   for (yyn = 0; yyn < yystackp->yytops.yysize; yyn += 1)
-    if (yystackp->yytops.yystates[yyn] != YY_NULL)
+    if (yystackp->yytops.yystates[yyn] != YY_NULLPTR)
       yystackp->yytops.yystates[yyn] =
         YYRELOC (yystackp->yyitems, yynewItems,
                  yystackp->yytops.yystates[yyn], yystate);
@@ -1103,7 +1103,7 @@ yyfreeGLRStack (yyGLRStack* yystackp)
 static inline void
 yyupdateSplit (yyGLRStack* yystackp, yyGLRState* yys)
 {
-  if (yystackp->yysplitPoint != YY_NULL && yystackp->yysplitPoint > yys)
+  if (yystackp->yysplitPoint != YY_NULLPTR && yystackp->yysplitPoint > yys)
     yystackp->yysplitPoint = yys;
 }
 
@@ -1111,9 +1111,9 @@ yyupdateSplit (yyGLRStack* yystackp, yyGLRState* yys)
 static inline void
 yymarkStackDeleted (yyGLRStack* yystackp, size_t yyk)
 {
-  if (yystackp->yytops.yystates[yyk] != YY_NULL)
+  if (yystackp->yytops.yystates[yyk] != YY_NULLPTR)
     yystackp->yylastDeleted = yystackp->yytops.yystates[yyk];
-  yystackp->yytops.yystates[yyk] = YY_NULL;
+  yystackp->yytops.yystates[yyk] = YY_NULLPTR;
 }
 
 /** Undelete the last stack in *YYSTACKP that was marked as deleted.  Can
@@ -1122,12 +1122,12 @@ yymarkStackDeleted (yyGLRStack* yystackp, size_t yyk)
 static void
 yyundeleteLastStack (yyGLRStack* yystackp)
 {
-  if (yystackp->yylastDeleted == YY_NULL || yystackp->yytops.yysize != 0)
+  if (yystackp->yylastDeleted == YY_NULLPTR || yystackp->yytops.yysize != 0)
     return;
   yystackp->yytops.yystates[0] = yystackp->yylastDeleted;
   yystackp->yytops.yysize = 1;
   YYDPRINTF ((stderr, "Restoring last deleted stack as stack #0.\n"));
-  yystackp->yylastDeleted = YY_NULL;
+  yystackp->yylastDeleted = YY_NULLPTR;
 }
 
 static inline void
@@ -1137,7 +1137,7 @@ yyremoveDeletes (yyGLRStack* yystackp)
   yyi = yyj = 0;
   while (yyj < yystackp->yytops.yysize)
     {
-      if (yystackp->yytops.yystates[yyi] == YY_NULL)
+      if (yystackp->yytops.yystates[yyi] == YY_NULLPTR)
         {
           if (yyi == yyj)
             {
@@ -1201,7 +1201,7 @@ yyglrShiftDefer (yyGLRStack* yystackp, size_t yyk, yyStateNum yylrState,
   yynewState->yyposn = yyposn;
   yynewState->yyresolved = yyfalse;
   yynewState->yypred = yystackp->yytops.yystates[yyk];
-  yynewState->yysemantics.yyfirstVal = YY_NULL;
+  yynewState->yysemantics.yyfirstVal = YY_NULLPTR;
   yystackp->yytops.yystates[yyk] = yynewState;
 
   /* Invokes YY_RESERVE_GLRSTACK.  */
@@ -1261,7 +1261,7 @@ yydoAction (yyGLRStack* yystackp, size_t yyk, yyRuleNum yyrule,
 {
   int yynrhs = yyrhsLength (yyrule);
 
-  if (yystackp->yysplitPoint == YY_NULL)
+  if (yystackp->yysplitPoint == YY_NULLPTR)
     {
       /* Standard special case: single stack.  */
       yyGLRStackItem* yyrhs = (yyGLRStackItem*) yystackp->yytops.yystates[yyk];
@@ -1313,13 +1313,13 @@ yyglrReduce (yyGLRStack* yystackp, size_t yyk, yyRuleNum yyrule,
 {
   size_t yyposn = yystackp->yytops.yystates[yyk]->yyposn;
 
-  if (yyforceEval || yystackp->yysplitPoint == YY_NULL)
+  if (yyforceEval || yystackp->yysplitPoint == YY_NULLPTR)
     {
       YYSTYPE yysval;]b4_locations_if([[
       YYLTYPE yyloc;]])[
 
       YYRESULTTAG yyflag = yydoAction (yystackp, yyk, yyrule, &yysval]b4_locuser_args([&yyloc])[);
-      if (yyflag == yyerr && yystackp->yysplitPoint != YY_NULL)
+      if (yyflag == yyerr && yystackp->yysplitPoint != YY_NULLPTR)
         {
           YYDPRINTF ((stderr, "Parse on stack %lu rejected by rule #%d.\n",
                      (unsigned long int) yyk, yyrule - 1));
@@ -1352,7 +1352,7 @@ yyglrReduce (yyGLRStack* yystackp, size_t yyk, yyRuleNum yyrule,
                   "Now in state %d.\n",
                   (unsigned long int) yyk, yyrule - 1, yynewLRState));
       for (yyi = 0; yyi < yystackp->yytops.yysize; yyi += 1)
-        if (yyi != yyk && yystackp->yytops.yystates[yyi] != YY_NULL)
+        if (yyi != yyk && yystackp->yytops.yystates[yyi] != YY_NULLPTR)
           {
             yyGLRState *yysplit = yystackp->yysplitPoint;
             yyGLRState *yyp = yystackp->yytops.yystates[yyi];
@@ -1379,7 +1379,7 @@ yyglrReduce (yyGLRStack* yystackp, size_t yyk, yyRuleNum yyrule,
 static size_t
 yysplitStack (yyGLRStack* yystackp, size_t yyk)
 {
-  if (yystackp->yysplitPoint == YY_NULL)
+  if (yystackp->yysplitPoint == YY_NULLPTR)
     {
       YYASSERT (yyk == 0);
       yystackp->yysplitPoint = yystackp->yytops.yystates[yyk];
@@ -1389,7 +1389,7 @@ yysplitStack (yyGLRStack* yystackp, size_t yyk)
       yyGLRState** yynewStates;
       yybool* yynewLookaheadNeeds;
 
-      yynewStates = YY_NULL;
+      yynewStates = YY_NULLPTR;
 
       if (yystackp->yytops.yycapacity
           > (YYSIZEMAX / (2 * sizeof yynewStates[0])))
@@ -1400,7 +1400,7 @@ yysplitStack (yyGLRStack* yystackp, size_t yyk)
         (yyGLRState**) YYREALLOC (yystackp->yytops.yystates,
                                   (yystackp->yytops.yycapacity
                                    * sizeof yynewStates[0]));
-      if (yynewStates == YY_NULL)
+      if (yynewStates == YY_NULLPTR)
         yyMemoryExhausted (yystackp);
       yystackp->yytops.yystates = yynewStates;
 
@@ -1408,7 +1408,7 @@ yysplitStack (yyGLRStack* yystackp, size_t yyk)
         (yybool*) YYREALLOC (yystackp->yytops.yylookaheadNeeds,
                              (yystackp->yytops.yycapacity
                               * sizeof yynewLookaheadNeeds[0]));
-      if (yynewLookaheadNeeds == YY_NULL)
+      if (yynewLookaheadNeeds == YY_NULLPTR)
         yyMemoryExhausted (yystackp);
       yystackp->yytops.yylookaheadNeeds = yynewLookaheadNeeds;
     }
@@ -1472,9 +1472,9 @@ yymergeOptionSets (yySemanticOption* yyy0, yySemanticOption* yyy1)
           yySemanticOption* yyz1 = yys1->yysemantics.yyfirstVal;
           while (yytrue)
             {
-              if (yyz1 == *yyz0p || yyz1 == YY_NULL)
+              if (yyz1 == *yyz0p || yyz1 == YY_NULLPTR)
                 break;
-              else if (*yyz0p == YY_NULL)
+              else if (*yyz0p == YY_NULLPTR)
                 {
                   *yyz0p = yyz1;
                   break;
@@ -1595,7 +1595,7 @@ yyreportTree (yySemanticOption* yyx, int yyindent)
 
   for (yyi = yynrhs, yys = yyx->yystate; 0 < yyi; yyi -= 1, yys = yys->yypred)
     yystates[yyi] = yys;
-  if (yys == YY_NULL)
+  if (yys == YY_NULLPTR)
     {
       yyleftmost_state.yyposn = 0;
       yystates[0] = &yyleftmost_state;
@@ -1666,7 +1666,7 @@ yyresolveLocations (yyGLRState* yys1, int yyn1,
           yyGLRStackItem yyrhsloc[1 + YYMAXRHS];
           int yynrhs;
           yySemanticOption *yyoption = yys1->yysemantics.yyfirstVal;
-          YYASSERT (yyoption != YY_NULL);
+          YYASSERT (yyoption != YY_NULLPTR);
           yynrhs = yyrhsLength (yyoption->yyrule);
           if (yynrhs > 0)
             {
@@ -1725,7 +1725,7 @@ yyresolveValue (yyGLRState* yys, yyGLRStack* yystackp]b4_user_formals[)
   YYRESULTTAG yyflag;]b4_locations_if([
   YYLTYPE *yylocp = &yys->yyloc;])[
 
-  for (yypp = &yyoptionList->yynext; *yypp != YY_NULL; )
+  for (yypp = &yyoptionList->yynext; *yypp != YY_NULLPTR; )
     {
       yySemanticOption* yyp = *yypp;
 
@@ -1767,7 +1767,7 @@ yyresolveValue (yyGLRState* yys, yyGLRStack* yystackp]b4_user_formals[)
       int yyprec = yydprec[yybest->yyrule];
       yyflag = yyresolveAction (yybest, yystackp, &yysval]b4_locuser_args[);
       if (yyflag == yyok)
-        for (yyp = yybest->yynext; yyp != YY_NULL; yyp = yyp->yynext)
+        for (yyp = yybest->yynext; yyp != YY_NULLPTR; yyp = yyp->yynext)
           {
             if (yyprec == yydprec[yyp->yyrule])
               {
@@ -1794,14 +1794,14 @@ yyresolveValue (yyGLRState* yys, yyGLRStack* yystackp]b4_user_formals[)
       yys->yysemantics.yysval = yysval;
     }
   else
-    yys->yysemantics.yyfirstVal = YY_NULL;
+    yys->yysemantics.yyfirstVal = YY_NULLPTR;
   return yyflag;
 }
 
 static YYRESULTTAG
 yyresolveStack (yyGLRStack* yystackp]b4_user_formals[)
 {
-  if (yystackp->yysplitPoint != YY_NULL)
+  if (yystackp->yysplitPoint != YY_NULLPTR)
     {
       yyGLRState* yys;
       int yyn;
@@ -1821,10 +1821,10 @@ yycompressStack (yyGLRStack* yystackp)
 {
   yyGLRState* yyp, *yyq, *yyr;
 
-  if (yystackp->yytops.yysize != 1 || yystackp->yysplitPoint == YY_NULL)
+  if (yystackp->yytops.yysize != 1 || yystackp->yysplitPoint == YY_NULLPTR)
     return;
 
-  for (yyp = yystackp->yytops.yystates[0], yyq = yyp->yypred, yyr = YY_NULL;
+  for (yyp = yystackp->yytops.yystates[0], yyq = yyp->yypred, yyr = YY_NULLPTR;
        yyp != yystackp->yysplitPoint;
        yyr = yyp, yyp = yyq, yyq = yyp->yypred)
     yyp->yypred = yyr;
@@ -1832,10 +1832,10 @@ yycompressStack (yyGLRStack* yystackp)
   yystackp->yyspaceLeft += yystackp->yynextFree - yystackp->yyitems;
   yystackp->yynextFree = ((yyGLRStackItem*) yystackp->yysplitPoint) + 1;
   yystackp->yyspaceLeft -= yystackp->yynextFree - yystackp->yyitems;
-  yystackp->yysplitPoint = YY_NULL;
-  yystackp->yylastDeleted = YY_NULL;
+  yystackp->yysplitPoint = YY_NULLPTR;
+  yystackp->yylastDeleted = YY_NULLPTR;
 
-  while (yyr != YY_NULL)
+  while (yyr != YY_NULLPTR)
     {
       yystackp->yynextFree->yystate = *yyr;
       yyr = yyr->yypred;
@@ -1850,7 +1850,7 @@ static YYRESULTTAG
 yyprocessOneStack (yyGLRStack* yystackp, size_t yyk,
                    size_t yyposn]b4_pure_formals[)
 {
-  while (yystackp->yytops.yystates[yyk] != YY_NULL)
+  while (yystackp->yytops.yystates[yyk] != YY_NULLPTR)
     {
       yyStateNum yystate = yystackp->yytops.yystates[yyk]->yylrState;
       YYDPRINTF ((stderr, "Stack %lu Entering state %d\n",
@@ -1972,13 +1972,13 @@ yyreportSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
 #else
   {
   yySymbol yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);
-  size_t yysize0 = yytnamerr (YY_NULL, yytokenName (yytoken));
+  size_t yysize0 = yytnamerr (YY_NULLPTR, yytokenName (yytoken));
   size_t yysize = yysize0;
   yybool yysize_overflow = yyfalse;
-  char* yymsg = YY_NULL;
+  char* yymsg = YY_NULLPTR;
   enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
   /* Internationalized format string. */
-  const char *yyformat = YY_NULL;
+  const char *yyformat = YY_NULLPTR;
   /* Arguments of yyformat. */
   char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
   /* Number of reported tokens (one for the "unexpected", one per
@@ -2034,7 +2034,7 @@ yyreportSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
                   }
                 yyarg[yycount++] = yytokenName (yyx);
                 {
-                  size_t yysz = yysize + yytnamerr (YY_NULL, yytokenName (yyx));
+                  size_t yysz = yysize + yytnamerr (YY_NULLPTR, yytokenName (yyx));
                   yysize_overflow |= yysz < yysize;
                   yysize = yysz;
                 }
@@ -2112,7 +2112,7 @@ yyrecoverSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
       {
         yySymbol yytoken;
         if (yychar == YYEOF)
-          yyFail (yystackp][]b4_lpure_args[, YY_NULL);
+          yyFail (yystackp][]b4_lpure_args[, YY_NULLPTR);
         if (yychar != YYEMPTY)
           {]b4_locations_if([[
             /* We throw away the lookahead, but the error range
@@ -2153,10 +2153,10 @@ yyrecoverSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
 
   /* Reduce to one stack.  */
   for (yyk = 0; yyk < yystackp->yytops.yysize; yyk += 1)
-    if (yystackp->yytops.yystates[yyk] != YY_NULL)
+    if (yystackp->yytops.yystates[yyk] != YY_NULLPTR)
       break;
   if (yyk >= yystackp->yytops.yysize)
-    yyFail (yystackp][]b4_lpure_args[, YY_NULL);
+    yyFail (yystackp][]b4_lpure_args[, YY_NULLPTR);
   for (yyk += 1; yyk < yystackp->yytops.yysize; yyk += 1)
     yymarkStackDeleted (yystackp, yyk);
   yyremoveDeletes (yystackp);
@@ -2164,7 +2164,7 @@ yyrecoverSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
 
   /* Now pop stack until we find a state that shifts the error token.  */
   yystackp->yyerrState = 3;
-  while (yystackp->yytops.yystates[0] != YY_NULL)
+  while (yystackp->yytops.yystates[0] != YY_NULLPTR)
     {
       yyGLRState *yys = yystackp->yytops.yystates[0];
       yyj = yypact[yys->yylrState];
@@ -2188,14 +2188,14 @@ yyrecoverSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
             }
         }]b4_locations_if([[
       yystackp->yyerror_range[1].yystate.yyloc = yys->yyloc;]])[
-      if (yys->yypred != YY_NULL)
+      if (yys->yypred != YY_NULLPTR)
         yydestroyGLRState ("Error: popping", yys]b4_user_args[);
       yystackp->yytops.yystates[0] = yys->yypred;
       yystackp->yynextFree -= 1;
       yystackp->yyspaceLeft += 1;
     }
-  if (yystackp->yytops.yystates[0] == YY_NULL)
-    yyFail (yystackp][]b4_lpure_args[, YY_NULL);
+  if (yystackp->yytops.yystates[0] == YY_NULLPTR)
+    yyFail (yystackp][]b4_lpure_args[, YY_NULLPTR);
 }
 
 #define YYCHK1(YYE)                                                          \
@@ -2438,7 +2438,7 @@ b4_dollar_popdef])[]dnl
                   {
                     yyGLRState *yys = yystates[yyk];
 ]b4_locations_if([[                 yystack.yyerror_range[1].yystate.yyloc = yys->yyloc;]]
-)[                  if (yys->yypred != YY_NULL)
+)[                  if (yys->yypred != YY_NULLPTR)
                       yydestroyGLRState ("Cleanup: popping", yys]b4_user_args[);
                     yystates[yyk] = yys->yypred;
                     yystack.yynextFree -= 1;
@@ -2470,7 +2470,7 @@ yy_yypstack (yyGLRState* yys)
 static void
 yypstates (yyGLRState* yyst)
 {
-  if (yyst == YY_NULL)
+  if (yyst == YY_NULLPTR)
     YYFPRINTF (stderr, "<null>");
   else
     yy_yypstack (yyst);
@@ -2484,7 +2484,7 @@ yypstack (yyGLRStack* yystackp, size_t yyk)
 }
 
 #define YYINDEX(YYX)                                                         \
-    ((YYX) == YY_NULL ? -1 : (yyGLRStackItem*) (YYX) - yystackp->yyitems)
+    ((YYX) == YY_NULLPTR ? -1 : (yyGLRStackItem*) (YYX) - yystackp->yyitems)
 
 
 static void
