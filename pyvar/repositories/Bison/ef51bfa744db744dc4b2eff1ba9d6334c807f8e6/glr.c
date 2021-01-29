@@ -171,6 +171,8 @@ m4_if(b4_prefix, [yy], [],
 /* Copy the first part of user declarations.  */
 ]b4_user_pre_prologue
 
+b4_null_define
+
 dnl # b4_shared_declarations
 dnl # ----------------------
 dnl # Declaration that might either go into the header (if --defines)
@@ -310,8 +312,7 @@ b4_percent_code_get[]dnl
 #ifndef __attribute__
 /* This feature is available in gcc versions 2.5 and later.  */
 # if (! defined __GNUC__ || __GNUC__ < 2 \
-      || (__GNUC__ == 2 && __GNUC_MINOR__ < 5) \
-      || (defined __STRICT_ANSI__ && __STRICT_ANSI__))
+      || (__GNUC__ == 2 && __GNUC_MINOR__ < 5))
 #  define __attribute__(Spec) /* empty */
 # endif
 #endif
@@ -827,7 +828,7 @@ static void yyFail (yyGLRStack* yystackp]b4_pure_formals[, const char* yymsg)
 static void
 yyFail (yyGLRStack* yystackp]b4_pure_formals[, const char* yymsg)
 {
-  if (yymsg != NULL)
+  if (yymsg != YY_NULL)
     yyerror (]b4_yyerror_args[yymsg);
   YYLONGJMP (yystackp->yyexception_buffer, 1);
 }
@@ -901,7 +902,7 @@ yyuserAction (yyRuleNum yyn, int yyrhslen, yyGLRStackItem* yyvsp,
 	      ]b4_user_formals[)
 {
   yybool yynormal __attribute__ ((__unused__)) =
-    (yystackp->yysplitPoint == NULL);
+    (yystackp->yysplitPoint == YY_NULL);
   int yylow;
 ]b4_parse_param_use[]dnl
 [# undef yyerrok
@@ -988,7 +989,7 @@ yydestroyGLRState (char const *yymsg, yyGLRState *yys]b4_user_formals[)
 	  else
 	    YYFPRINTF (stderr, "%s incomplete ", yymsg);
 	  yy_symbol_print (stderr, yystos[yys->yylrState],
-			   NULL]b4_locations_if([, &yys->yyloc])[]b4_user_args[);
+			   YY_NULL]b4_locations_if([, &yys->yyloc])[]b4_user_args[);
 	  YYFPRINTF (stderr, "\n");
 	}
 #endif
@@ -1141,7 +1142,7 @@ yyinitStateSet (yyGLRStateSet* yyset)
   yyset->yystates = (yyGLRState**) YYMALLOC (16 * sizeof yyset->yystates[0]);
   if (! yyset->yystates)
     return yyfalse;
-  yyset->yystates[0] = NULL;
+  yyset->yystates[0] = YY_NULL;
   yyset->yylookaheadNeeds =
     (yybool*) YYMALLOC (16 * sizeof yyset->yylookaheadNeeds[0]);
   if (! yyset->yylookaheadNeeds)
@@ -1171,8 +1172,8 @@ yyinitGLRStack (yyGLRStack* yystackp, size_t yysize)
   if (!yystackp->yyitems)
     return yyfalse;
   yystackp->yynextFree = yystackp->yyitems;
-  yystackp->yysplitPoint = NULL;
-  yystackp->yylastDeleted = NULL;
+  yystackp->yysplitPoint = YY_NULL;
+  yystackp->yylastDeleted = YY_NULL;
   return yyinitStateSet (&yystackp->yytops);
 }
 
@@ -1211,10 +1212,10 @@ yyexpandGLRStack (yyGLRStack* yystackp)
 	{
 	  yyGLRState* yys0 = &yyp0->yystate;
 	  yyGLRState* yys1 = &yyp1->yystate;
-	  if (yys0->yypred != NULL)
+	  if (yys0->yypred != YY_NULL)
 	    yys1->yypred =
 	      YYRELOC (yyp0, yyp1, yys0->yypred, yystate);
-	  if (! yys0->yyresolved && yys0->yysemantics.yyfirstVal != NULL)
+	  if (! yys0->yyresolved && yys0->yysemantics.yyfirstVal != YY_NULL)
 	    yys1->yysemantics.yyfirstVal =
 	      YYRELOC(yyp0, yyp1, yys0->yysemantics.yyfirstVal, yyoption);
 	}
@@ -1222,18 +1223,18 @@ yyexpandGLRStack (yyGLRStack* yystackp)
 	{
 	  yySemanticOption* yyv0 = &yyp0->yyoption;
 	  yySemanticOption* yyv1 = &yyp1->yyoption;
-	  if (yyv0->yystate != NULL)
+	  if (yyv0->yystate != YY_NULL)
 	    yyv1->yystate = YYRELOC (yyp0, yyp1, yyv0->yystate, yystate);
-	  if (yyv0->yynext != NULL)
+	  if (yyv0->yynext != YY_NULL)
 	    yyv1->yynext = YYRELOC (yyp0, yyp1, yyv0->yynext, yyoption);
 	}
     }
-  if (yystackp->yysplitPoint != NULL)
+  if (yystackp->yysplitPoint != YY_NULL)
     yystackp->yysplitPoint = YYRELOC (yystackp->yyitems, yynewItems,
 				 yystackp->yysplitPoint, yystate);
 
   for (yyn = 0; yyn < yystackp->yytops.yysize; yyn += 1)
-    if (yystackp->yytops.yystates[yyn] != NULL)
+    if (yystackp->yytops.yystates[yyn] != YY_NULL)
       yystackp->yytops.yystates[yyn] =
 	YYRELOC (yystackp->yyitems, yynewItems,
 		 yystackp->yytops.yystates[yyn], yystate);
@@ -1257,7 +1258,7 @@ yyfreeGLRStack (yyGLRStack* yystackp)
 static inline void
 yyupdateSplit (yyGLRStack* yystackp, yyGLRState* yys)
 {
-  if (yystackp->yysplitPoint != NULL && yystackp->yysplitPoint > yys)
+  if (yystackp->yysplitPoint != YY_NULL && yystackp->yysplitPoint > yys)
     yystackp->yysplitPoint = yys;
 }
 
@@ -1265,9 +1266,9 @@ yyupdateSplit (yyGLRStack* yystackp, yyGLRState* yys)
 static inline void
 yymarkStackDeleted (yyGLRStack* yystackp, size_t yyk)
 {
-  if (yystackp->yytops.yystates[yyk] != NULL)
+  if (yystackp->yytops.yystates[yyk] != YY_NULL)
     yystackp->yylastDeleted = yystackp->yytops.yystates[yyk];
-  yystackp->yytops.yystates[yyk] = NULL;
+  yystackp->yytops.yystates[yyk] = YY_NULL;
 }
 
 /** Undelete the last stack that was marked as deleted.  Can only be
@@ -1276,12 +1277,12 @@ yymarkStackDeleted (yyGLRStack* yystackp, size_t yyk)
 static void
 yyundeleteLastStack (yyGLRStack* yystackp)
 {
-  if (yystackp->yylastDeleted == NULL || yystackp->yytops.yysize != 0)
+  if (yystackp->yylastDeleted == YY_NULL || yystackp->yytops.yysize != 0)
     return;
   yystackp->yytops.yystates[0] = yystackp->yylastDeleted;
   yystackp->yytops.yysize = 1;
   YYDPRINTF ((stderr, "Restoring last deleted stack as stack #0.\n"));
-  yystackp->yylastDeleted = NULL;
+  yystackp->yylastDeleted = YY_NULL;
 }
 
 static inline void
@@ -1291,7 +1292,7 @@ yyremoveDeletes (yyGLRStack* yystackp)
   yyi = yyj = 0;
   while (yyj < yystackp->yytops.yysize)
     {
-      if (yystackp->yytops.yystates[yyi] == NULL)
+      if (yystackp->yytops.yystates[yyi] == YY_NULL)
 	{
 	  if (yyi == yyj)
 	    {
@@ -1353,7 +1354,7 @@ yyglrShiftDefer (yyGLRStack* yystackp, size_t yyk, yyStateNum yylrState,
   yynewState->yyposn = yyposn;
   yynewState->yyresolved = yyfalse;
   yynewState->yypred = yystackp->yytops.yystates[yyk];
-  yynewState->yysemantics.yyfirstVal = NULL;
+  yynewState->yysemantics.yyfirstVal = YY_NULL;
   yystackp->yytops.yystates[yyk] = yynewState;
 
   /* Invokes YY_RESERVE_GLRSTACK.  */
@@ -1372,7 +1373,7 @@ yydoAction (yyGLRStack* yystackp, size_t yyk, yyRuleNum yyrule,
 {
   int yynrhs = yyrhsLength (yyrule);
 
-  if (yystackp->yysplitPoint == NULL)
+  if (yystackp->yysplitPoint == YY_NULL)
     {
       /* Standard special case: single stack.  */
       yyGLRStackItem* rhs = (yyGLRStackItem*) yystackp->yytops.yystates[yyk];
@@ -1428,7 +1429,7 @@ yy_reduce_print (yyGLRStack* yystackp, size_t yyk, yyRuleNum yyrule,
 {
   int yynrhs = yyrhsLength (yyrule);
   yybool yynormal __attribute__ ((__unused__)) =
-    (yystackp->yysplitPoint == NULL);
+    (yystackp->yysplitPoint == YY_NULL);
   yyGLRStackItem* yyvsp = (yyGLRStackItem*) yystackp->yytops.yystates[yyk];
   int yylow = 1;
   int yyi;
@@ -1468,7 +1469,7 @@ yyglrReduce (yyGLRStack* yystackp, size_t yyk, yyRuleNum yyrule,
 {
   size_t yyposn = yystackp->yytops.yystates[yyk]->yyposn;
 
-  if (yyforceEval || yystackp->yysplitPoint == NULL)
+  if (yyforceEval || yystackp->yysplitPoint == YY_NULL)
     {
       YYSTYPE yysval;
       YYLTYPE yyloc;
@@ -1501,7 +1502,7 @@ yyglrReduce (yyGLRStack* yystackp, size_t yyk, yyRuleNum yyrule,
 		  "Reduced stack %lu by rule #%d; action deferred.  Now in state %d.\n",
 		  (unsigned long int) yyk, yyrule - 1, yynewLRState));
       for (yyi = 0; yyi < yystackp->yytops.yysize; yyi += 1)
-	if (yyi != yyk && yystackp->yytops.yystates[yyi] != NULL)
+	if (yyi != yyk && yystackp->yytops.yystates[yyi] != YY_NULL)
 	  {
 	    yyGLRState* yyp, *yysplit = yystackp->yysplitPoint;
 	    yyp = yystackp->yytops.yystates[yyi];
@@ -1528,7 +1529,7 @@ yyglrReduce (yyGLRStack* yystackp, size_t yyk, yyRuleNum yyrule,
 static size_t
 yysplitStack (yyGLRStack* yystackp, size_t yyk)
 {
-  if (yystackp->yysplitPoint == NULL)
+  if (yystackp->yysplitPoint == YY_NULL)
     {
       YYASSERT (yyk == 0);
       yystackp->yysplitPoint = yystackp->yytops.yystates[yyk];
@@ -1538,7 +1539,7 @@ yysplitStack (yyGLRStack* yystackp, size_t yyk)
       yyGLRState** yynewStates;
       yybool* yynewLookaheadNeeds;
 
-      yynewStates = NULL;
+      yynewStates = YY_NULL;
 
       if (yystackp->yytops.yycapacity
 	  > (YYSIZEMAX / (2 * sizeof yynewStates[0])))
@@ -1549,7 +1550,7 @@ yysplitStack (yyGLRStack* yystackp, size_t yyk)
 	(yyGLRState**) YYREALLOC (yystackp->yytops.yystates,
 				  (yystackp->yytops.yycapacity
 				   * sizeof yynewStates[0]));
-      if (yynewStates == NULL)
+      if (yynewStates == YY_NULL)
 	yyMemoryExhausted (yystackp);
       yystackp->yytops.yystates = yynewStates;
 
@@ -1557,7 +1558,7 @@ yysplitStack (yyGLRStack* yystackp, size_t yyk)
 	(yybool*) YYREALLOC (yystackp->yytops.yylookaheadNeeds,
 			     (yystackp->yytops.yycapacity
 			      * sizeof yynewLookaheadNeeds[0]));
-      if (yynewLookaheadNeeds == NULL)
+      if (yynewLookaheadNeeds == YY_NULL)
 	yyMemoryExhausted (yystackp);
       yystackp->yytops.yylookaheadNeeds = yynewLookaheadNeeds;
     }
@@ -1623,9 +1624,9 @@ yymergeOptionSets (yySemanticOption* yyy0, yySemanticOption* yyy1)
 	  yyz1 = yys1->yysemantics.yyfirstVal;
 	  while (YYID (yytrue))
 	    {
-	      if (yyz1 == *yyz0p || yyz1 == NULL)
+	      if (yyz1 == *yyz0p || yyz1 == YY_NULL)
 		break;
-	      else if (*yyz0p == NULL)
+	      else if (*yyz0p == YY_NULL)
 		{
 		  *yyz0p = yyz1;
 		  break;
@@ -1748,7 +1749,7 @@ yyreportTree (yySemanticOption* yyx, int yyindent)
 
   for (yyi = yynrhs, yys = yyx->yystate; 0 < yyi; yyi -= 1, yys = yys->yypred)
     yystates[yyi] = yys;
-  if (yys == NULL)
+  if (yys == YY_NULL)
     {
       yyleftmost_state.yyposn = 0;
       yystates[0] = &yyleftmost_state;
@@ -1823,7 +1824,7 @@ yyresolveLocations (yyGLRState* yys1, int yyn1,
 	  YYSTYPE yylval_current;
 	  YYLTYPE yylloc_current;
 	  yyoption = yys1->yysemantics.yyfirstVal;
-	  YYASSERT (yyoption != NULL);
+	  YYASSERT (yyoption != YY_NULL);
 	  yynrhs = yyrhsLength (yyoption->yyrule);
 	  if (yynrhs > 0)
 	    {
@@ -1881,7 +1882,7 @@ yyresolveValue (yyGLRState* yys, yyGLRStack* yystackp]b4_user_formals[)
 
   yybest = yyoptionList;
   yymerge = yyfalse;
-  for (yypp = &yyoptionList->yynext; *yypp != NULL; )
+  for (yypp = &yyoptionList->yynext; *yypp != YY_NULL; )
     {
       yySemanticOption* yyp = *yypp;
 
@@ -1924,7 +1925,7 @@ yyresolveValue (yyGLRState* yys, yyGLRStack* yystackp]b4_user_formals[)
       yyflag = yyresolveAction (yybest, yystackp, &yysval,
 				yylocp]b4_user_args[);
       if (yyflag == yyok)
-	for (yyp = yybest->yynext; yyp != NULL; yyp = yyp->yynext)
+	for (yyp = yybest->yynext; yyp != YY_NULL; yyp = yyp->yynext)
 	  {
 	    if (yyprec == yydprec[yyp->yyrule])
 	      {
@@ -1952,14 +1953,14 @@ yyresolveValue (yyGLRState* yys, yyGLRStack* yystackp]b4_user_formals[)
       yys->yysemantics.yysval = yysval;
     }
   else
-    yys->yysemantics.yyfirstVal = NULL;
+    yys->yysemantics.yyfirstVal = YY_NULL;
   return yyflag;
 }
 
 static YYRESULTTAG
 yyresolveStack (yyGLRStack* yystackp]b4_user_formals[)
 {
-  if (yystackp->yysplitPoint != NULL)
+  if (yystackp->yysplitPoint != YY_NULL)
     {
       yyGLRState* yys;
       int yyn;
@@ -1979,10 +1980,10 @@ yycompressStack (yyGLRStack* yystackp)
 {
   yyGLRState* yyp, *yyq, *yyr;
 
-  if (yystackp->yytops.yysize != 1 || yystackp->yysplitPoint == NULL)
+  if (yystackp->yytops.yysize != 1 || yystackp->yysplitPoint == YY_NULL)
     return;
 
-  for (yyp = yystackp->yytops.yystates[0], yyq = yyp->yypred, yyr = NULL;
+  for (yyp = yystackp->yytops.yystates[0], yyq = yyp->yypred, yyr = YY_NULL;
        yyp != yystackp->yysplitPoint;
        yyr = yyp, yyp = yyq, yyq = yyp->yypred)
     yyp->yypred = yyr;
@@ -1990,10 +1991,10 @@ yycompressStack (yyGLRStack* yystackp)
   yystackp->yyspaceLeft += yystackp->yynextFree - yystackp->yyitems;
   yystackp->yynextFree = ((yyGLRStackItem*) yystackp->yysplitPoint) + 1;
   yystackp->yyspaceLeft -= yystackp->yynextFree - yystackp->yyitems;
-  yystackp->yysplitPoint = NULL;
-  yystackp->yylastDeleted = NULL;
+  yystackp->yysplitPoint = YY_NULL;
+  yystackp->yylastDeleted = YY_NULL;
 
-  while (yyr != NULL)
+  while (yyr != YY_NULL)
     {
       yystackp->yynextFree->yystate = *yyr;
       yyr = yyr->yypred;
@@ -2012,7 +2013,7 @@ yyprocessOneStack (yyGLRStack* yystackp, size_t yyk,
   const short int* yyconflicts;
   yyRuleNum yyrule;
 
-  while (yystackp->yytops.yystates[yyk] != NULL)
+  while (yystackp->yytops.yystates[yyk] != YY_NULL)
     {
       yyStateNum yystate = yystackp->yytops.yystates[yyk]->yylrState;
       YYDPRINTF ((stderr, "Stack %lu Entering state %d\n",
@@ -2094,14 +2095,14 @@ yyreportSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
   yyerror (]b4_lyyerror_args[YY_("syntax error"));
 #else
   yySymbol yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);
-  size_t yysize0 = yytnamerr (NULL, yytokenName (yytoken));
+  size_t yysize0 = yytnamerr (YY_NULL, yytokenName (yytoken));
   size_t yysize = yysize0;
   size_t yysize1;
   yybool yysize_overflow = yyfalse;
-  char* yymsg = NULL;
+  char* yymsg = YY_NULL;
   enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
   /* Internationalized format string. */
-  const char *yyformat = 0;
+  const char *yyformat = YY_NULL;
   /* Arguments of yyformat. */
   char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
   /* Number of reported tokens (one for the "unexpected", one per
@@ -2156,7 +2157,7 @@ yyreportSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
                     break;
                   }
                 yyarg[yycount++] = yytokenName (yyx);
-                yysize1 = yysize + yytnamerr (NULL, yytokenName (yyx));
+                yysize1 = yysize + yytnamerr (YY_NULL, yytokenName (yyx));
                 yysize_overflow |= yysize1 < yysize;
                 yysize = yysize1;
               }
@@ -2230,7 +2231,7 @@ yyrecoverSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
       {
 	yySymbol yytoken;
 	if (yychar == YYEOF)
-	  yyFail (yystackp][]b4_lpure_args[, NULL);
+	  yyFail (yystackp][]b4_lpure_args[, YY_NULL);
 	if (yychar != YYEMPTY)
 	  {]b4_locations_if([[
 	    /* We throw away the lookahead, but the error range
@@ -2271,10 +2272,10 @@ yyrecoverSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
 
   /* Reduce to one stack.  */
   for (yyk = 0; yyk < yystackp->yytops.yysize; yyk += 1)
-    if (yystackp->yytops.yystates[yyk] != NULL)
+    if (yystackp->yytops.yystates[yyk] != YY_NULL)
       break;
   if (yyk >= yystackp->yytops.yysize)
-    yyFail (yystackp][]b4_lpure_args[, NULL);
+    yyFail (yystackp][]b4_lpure_args[, YY_NULL);
   for (yyk += 1; yyk < yystackp->yytops.yysize; yyk += 1)
     yymarkStackDeleted (yystackp, yyk);
   yyremoveDeletes (yystackp);
@@ -2282,7 +2283,7 @@ yyrecoverSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
 
   /* Now pop stack until we find a state that shifts the error token.  */
   yystackp->yyerrState = 3;
-  while (yystackp->yytops.yystates[0] != NULL)
+  while (yystackp->yytops.yystates[0] != YY_NULL)
     {
       yyGLRState *yys = yystackp->yytops.yystates[0];
       yyj = yypact[yys->yylrState];
@@ -2305,14 +2306,14 @@ yyrecoverSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
 	    }
 	}
 ]b4_locations_if([[      yystackp->yyerror_range[1].yystate.yyloc = yys->yyloc;]])[
-      if (yys->yypred != NULL)
+      if (yys->yypred != YY_NULL)
 	yydestroyGLRState ("Error: popping", yys]b4_user_args[);
       yystackp->yytops.yystates[0] = yys->yypred;
       yystackp->yynextFree -= 1;
       yystackp->yyspaceLeft += 1;
     }
-  if (yystackp->yytops.yystates[0] == NULL)
-    yyFail (yystackp][]b4_lpure_args[, NULL);
+  if (yystackp->yytops.yystates[0] == YY_NULL)
+    yyFail (yystackp][]b4_lpure_args[, YY_NULL);
 }
 
 #define YYCHK1(YYE)							     \
@@ -2564,7 +2565,7 @@ m4_popdef([b4_at_dollar])])dnl
 		  {
 		    yyGLRState *yys = yystates[yyk];
 ]b4_locations_if([[		    yystack.yyerror_range[1].yystate.yyloc = yys->yyloc;]]
-)[		    if (yys->yypred != NULL)
+)[		    if (yys->yypred != YY_NULL)
 		      yydestroyGLRState ("Cleanup: popping", yys]b4_user_args[);
 		    yystates[yyk] = yys->yypred;
 		    yystack.yynextFree -= 1;
@@ -2601,7 +2602,7 @@ yy_yypstack (yyGLRState* yys)
 static void
 yypstates (yyGLRState* yyst)
 {
-  if (yyst == NULL)
+  if (yyst == YY_NULL)
     YYFPRINTF (stderr, "<null>");
   else
     yy_yypstack (yyst);
@@ -2615,7 +2616,7 @@ yypstack (yyGLRStack* yystackp, size_t yyk)
 }
 
 #define YYINDEX(YYX)							     \
-    ((YYX) == NULL ? -1 : (yyGLRStackItem*) (YYX) - yystackp->yyitems)
+    ((YYX) == YY_NULL ? -1 : (yyGLRStackItem*) (YYX) - yystackp->yyitems)
 
 
 static void
