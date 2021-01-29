@@ -537,9 +537,9 @@ static const ]b4_int_type_for([b4_stos])[ yystos[] =
 ]b4_pure_if(
 [
 #undef yynerrs
-#define yynerrs (yystack->yyerrcnt)
+#define yynerrs (yystackp->yyerrcnt)
 #undef yychar
-#define yychar (yystack->yyrawchar)],
+#define yychar (yystackp->yyrawchar)],
 [YYSTYPE yylval;
 
 YYLTYPE yylloc;
@@ -725,10 +725,10 @@ typedef short int yySymbol;
 typedef short int yyItemNum;
 
 typedef struct yyGLRState yyGLRState;
+typedef struct yyGLRStateSet yyGLRStateSet;
 typedef struct yySemanticOption yySemanticOption;
 typedef union yyGLRStackItem yyGLRStackItem;
 typedef struct yyGLRStack yyGLRStack;
-typedef struct yyGLRStateSet yyGLRStateSet;
 
 struct yyGLRState {
   /** Type tag: always true. */
@@ -798,25 +798,25 @@ struct yyGLRStack {
 };
 
 #if YYSTACKEXPANDABLE
-static void yyexpandGLRStack (yyGLRStack* yystack);
+static void yyexpandGLRStack (yyGLRStack* yystackp);
 #endif
 
-static void yyFail (yyGLRStack* yystack]b4_pure_formals[, const char* yymsg)
+static void yyFail (yyGLRStack* yystackp]b4_pure_formals[, const char* yymsg)
   __attribute__ ((__noreturn__));
 static void
-yyFail (yyGLRStack* yystack]b4_pure_formals[, const char* yymsg)
+yyFail (yyGLRStack* yystackp]b4_pure_formals[, const char* yymsg)
 {
   if (yymsg != NULL)
     yyerror (]b4_yyerror_args[yymsg);
-  YYLONGJMP (yystack->yyexception_buffer, 1);
+  YYLONGJMP (yystackp->yyexception_buffer, 1);
 }
 
-static void yyMemoryExhausted (yyGLRStack* yystack)
+static void yyMemoryExhausted (yyGLRStack* yystackp)
   __attribute__ ((__noreturn__));
 static void
-yyMemoryExhausted (yyGLRStack* yystack)
+yyMemoryExhausted (yyGLRStack* yystackp)
 {
-  YYLONGJMP (yystack->yyexception_buffer, 2);
+  YYLONGJMP (yystackp->yyexception_buffer, 2);
 }
 
 #if YYDEBUG || YYERROR_VERBOSE
@@ -876,15 +876,15 @@ yyfill (yyGLRStackItem *yyvsp, int *yylow, int yylow1, yybool yynormal)
 yyuserAction (yyRuleNum yyn, int yyrhslen, yyGLRStackItem* yyvsp,
 	      YYSTYPE* yyvalp,
 	      YYLTYPE* YYOPTIONAL_LOC (yylocp),
-	      yyGLRStack* yystack
+	      yyGLRStack* yystackp
 	      ]b4_user_formals[)
 {
   yybool yynormal __attribute__ ((__unused__)) =
-    (yystack->yysplitPoint == NULL);
+    (yystackp->yysplitPoint == NULL);
   int yylow;
 ]b4_parse_param_use[]dnl
 [# undef yyerrok
-# define yyerrok (yystack->yyerrState = 0)
+# define yyerrok (yystackp->yyerrState = 0)
 # undef YYACCEPT
 # define YYACCEPT return yyaccept
 # undef YYABORT
@@ -892,9 +892,9 @@ yyuserAction (yyRuleNum yyn, int yyrhslen, yyGLRStackItem* yyvsp,
 # undef YYERROR
 # define YYERROR return yyerrok, yyerr
 # undef YYRECOVERING
-# define YYRECOVERING (yystack->yyerrState != 0)
+# define YYRECOVERING (yystackp->yyerrState != 0)
 # undef yyclearin
-# define yyclearin (yychar = *(yystack->yytokenp) = YYEMPTY)
+# define yyclearin (yychar = *(yystackp->yytokenp) = YYEMPTY)
 # undef YYFILL
 # define YYFILL(N) yyfill (yyvsp, &yylow, N, yynormal)
 # undef YYBACKUP
@@ -908,7 +908,7 @@ yyuserAction (yyRuleNum yyn, int yyrhslen, yyGLRStackItem* yyvsp,
   else
     *yyvalp = yyvsp[YYFILL (1-yyrhslen)].yystate.yysemantics.yysval;
   YYLLOC_DEFAULT (*yylocp, yyvsp - yyrhslen, yyrhslen);
-]b4_location_if([[  yystack->yyerror_range[1].yystate.yyloc = *yylocp;
+]b4_location_if([[  yystackp->yyerror_range[1].yystate.yyloc = *yylocp;
 ]])
   switch (yyn)
     {
@@ -1013,7 +1013,7 @@ yydefaultAction (yyStateNum yystate)
 
 #define yyis_table_ninf(yytable_value) \
   ]m4_if(m4_eval(b4_table_ninf < b4_table_min), [1],
-	 [0],
+	 [YYID (0)],
 	 [((yytable_value) == YYTABLE_NINF)])[
 
 /** Set *YYACTION to the action to take in YYSTATE on seeing YYTOKEN.
@@ -1076,27 +1076,27 @@ yyisErrorAction (int yyaction)
  * headroom.  */
 
 static inline yyGLRStackItem*
-yynewGLRStackItem (yyGLRStack* yystack, yybool yyisState)
+yynewGLRStackItem (yyGLRStack* yystackp, yybool yyisState)
 {
-  yyGLRStackItem* yynewItem = yystack->yynextFree;
-  yystack->yyspaceLeft -= 1;
-  yystack->yynextFree += 1;
+  yyGLRStackItem* yynewItem = yystackp->yynextFree;
+  yystackp->yyspaceLeft -= 1;
+  yystackp->yynextFree += 1;
   yynewItem->yystate.yyisState = yyisState;
   return yynewItem;
 }
 
 static void
-yyaddDeferredAction (yyGLRStack* yystack, yyGLRState* yystate,
+yyaddDeferredAction (yyGLRStack* yystackp, yyGLRState* yystate,
 		     yyGLRState* rhs, yyRuleNum yyrule)
 {
   yySemanticOption* yynewOption =
-    &yynewGLRStackItem (yystack, yyfalse)->yyoption;
+    &yynewGLRStackItem (yystackp, yyfalse)->yyoption;
   yynewOption->yystate = rhs;
   yynewOption->yyrule = yyrule;
   yynewOption->yynext = yystate->yysemantics.yyfirstVal;
   yystate->yysemantics.yyfirstVal = yynewOption;
 
-  YY_RESERVE_GLRSTACK (yystack);
+  YY_RESERVE_GLRSTACK (yystackp);
 }
 
 				/* GLRStacks */
@@ -1122,19 +1122,19 @@ static void yyfreeStateSet (yyGLRStateSet* yyset)
 /** Initialize STACK to a single empty stack, with total maximum
  *  capacity for all stacks of SIZE. */
 static yybool
-yyinitGLRStack (yyGLRStack* yystack, size_t yysize)
+yyinitGLRStack (yyGLRStack* yystackp, size_t yysize)
 {
-  yystack->yyerrState = 0;
+  yystackp->yyerrState = 0;
   yynerrs = 0;
-  yystack->yyspaceLeft = yysize;
-  yystack->yyitems =
-    (yyGLRStackItem*) YYMALLOC (yysize * sizeof yystack->yynextFree[0]);
-  if (!yystack->yyitems)
+  yystackp->yyspaceLeft = yysize;
+  yystackp->yyitems =
+    (yyGLRStackItem*) YYMALLOC (yysize * sizeof yystackp->yynextFree[0]);
+  if (!yystackp->yyitems)
     return yyfalse;
-  yystack->yynextFree = yystack->yyitems;
-  yystack->yysplitPoint = NULL;
-  yystack->yylastDeleted = NULL;
-  return yyinitStateSet (&yystack->yytops);
+  yystackp->yynextFree = yystackp->yyitems;
+  yystackp->yysplitPoint = NULL;
+  yystackp->yylastDeleted = NULL;
+  return yyinitStateSet (&yystackp->yytops);
 }
 
 
@@ -1148,22 +1148,22 @@ yyinitGLRStack (yyGLRStack* yystack, size_t yysize)
     allocation, so that we can avoid having external pointers exist
     across an allocation. */
 static void
-yyexpandGLRStack (yyGLRStack* yystack)
+yyexpandGLRStack (yyGLRStack* yystackp)
 {
   yyGLRStackItem* yynewItems;
   yyGLRStackItem* yyp0, *yyp1;
   size_t yysize, yynewSize;
   size_t yyn;
-  yysize = yystack->yynextFree - yystack->yyitems;
+  yysize = yystackp->yynextFree - yystackp->yyitems;
   if (YYMAXDEPTH <= yysize)
-    yyMemoryExhausted (yystack);
+    yyMemoryExhausted (yystackp);
   yynewSize = 2*yysize;
   if (YYMAXDEPTH < yynewSize)
     yynewSize = YYMAXDEPTH;
   yynewItems = (yyGLRStackItem*) YYMALLOC (yynewSize * sizeof yynewItems[0]);
   if (! yynewItems)
-    yyMemoryExhausted (yystack);
-  for (yyp0 = yystack->yyitems, yyp1 = yynewItems, yyn = yysize;
+    yyMemoryExhausted (yystackp);
+  for (yyp0 = yystackp->yyitems, yyp1 = yynewItems, yyn = yysize;
        0 < yyn;
        yyn -= 1, yyp0 += 1, yyp1 += 1)
     {
@@ -1189,80 +1189,80 @@ yyexpandGLRStack (yyGLRStack* yystack)
 	    yyv1->yynext = YYRELOC (yyp0, yyp1, yyv0->yynext, yyoption);
 	}
     }
-  if (yystack->yysplitPoint != NULL)
-    yystack->yysplitPoint = YYRELOC (yystack->yyitems, yynewItems,
-				 yystack->yysplitPoint, yystate);
-
-  for (yyn = 0; yyn < yystack->yytops.yysize; yyn += 1)
-    if (yystack->yytops.yystates[yyn] != NULL)
-      yystack->yytops.yystates[yyn] =
-	YYRELOC (yystack->yyitems, yynewItems,
-		 yystack->yytops.yystates[yyn], yystate);
-  YYFREE (yystack->yyitems);
-  yystack->yyitems = yynewItems;
-  yystack->yynextFree = yynewItems + yysize;
-  yystack->yyspaceLeft = yynewSize - yysize;
+  if (yystackp->yysplitPoint != NULL)
+    yystackp->yysplitPoint = YYRELOC (yystackp->yyitems, yynewItems,
+				 yystackp->yysplitPoint, yystate);
+
+  for (yyn = 0; yyn < yystackp->yytops.yysize; yyn += 1)
+    if (yystackp->yytops.yystates[yyn] != NULL)
+      yystackp->yytops.yystates[yyn] =
+	YYRELOC (yystackp->yyitems, yynewItems,
+		 yystackp->yytops.yystates[yyn], yystate);
+  YYFREE (yystackp->yyitems);
+  yystackp->yyitems = yynewItems;
+  yystackp->yynextFree = yynewItems + yysize;
+  yystackp->yyspaceLeft = yynewSize - yysize;
 }
 #endif
 
 static void
-yyfreeGLRStack (yyGLRStack* yystack)
+yyfreeGLRStack (yyGLRStack* yystackp)
 {
-  YYFREE (yystack->yyitems);
-  yyfreeStateSet (&yystack->yytops);
+  YYFREE (yystackp->yyitems);
+  yyfreeStateSet (&yystackp->yytops);
 }
 
 /** Assuming that S is a GLRState somewhere on STACK, update the
  *  splitpoint of STACK, if needed, so that it is at least as deep as
  *  S. */
 static inline void
-yyupdateSplit (yyGLRStack* yystack, yyGLRState* yys)
+yyupdateSplit (yyGLRStack* yystackp, yyGLRState* yys)
 {
-  if (yystack->yysplitPoint != NULL && yystack->yysplitPoint > yys)
-    yystack->yysplitPoint = yys;
+  if (yystackp->yysplitPoint != NULL && yystackp->yysplitPoint > yys)
+    yystackp->yysplitPoint = yys;
 }
 
 /** Invalidate stack #K in STACK. */
 static inline void
-yymarkStackDeleted (yyGLRStack* yystack, size_t yyk)
+yymarkStackDeleted (yyGLRStack* yystackp, size_t yyk)
 {
-  if (yystack->yytops.yystates[yyk] != NULL)
-    yystack->yylastDeleted = yystack->yytops.yystates[yyk];
-  yystack->yytops.yystates[yyk] = NULL;
+  if (yystackp->yytops.yystates[yyk] != NULL)
+    yystackp->yylastDeleted = yystackp->yytops.yystates[yyk];
+  yystackp->yytops.yystates[yyk] = NULL;
 }
 
 /** Undelete the last stack that was marked as deleted.  Can only be
     done once after a deletion, and only when all other stacks have
     been deleted. */
 static void
-yyundeleteLastStack (yyGLRStack* yystack)
+yyundeleteLastStack (yyGLRStack* yystackp)
 {
-  if (yystack->yylastDeleted == NULL || yystack->yytops.yysize != 0)
+  if (yystackp->yylastDeleted == NULL || yystackp->yytops.yysize != 0)
     return;
-  yystack->yytops.yystates[0] = yystack->yylastDeleted;
-  yystack->yytops.yysize = 1;
+  yystackp->yytops.yystates[0] = yystackp->yylastDeleted;
+  yystackp->yytops.yysize = 1;
   YYDPRINTF ((stderr, "Restoring last deleted stack as stack #0.\n"));
-  yystack->yylastDeleted = NULL;
+  yystackp->yylastDeleted = NULL;
 }
 
 static inline void
-yyremoveDeletes (yyGLRStack* yystack)
+yyremoveDeletes (yyGLRStack* yystackp)
 {
   size_t yyi, yyj;
   yyi = yyj = 0;
-  while (yyj < yystack->yytops.yysize)
+  while (yyj < yystackp->yytops.yysize)
     {
-      if (yystack->yytops.yystates[yyi] == NULL)
+      if (yystackp->yytops.yystates[yyi] == NULL)
 	{
 	  if (yyi == yyj)
 	    {
 	      YYDPRINTF ((stderr, "Removing dead stacks.\n"));
 	    }
-	  yystack->yytops.yysize -= 1;
+	  yystackp->yytops.yysize -= 1;
 	}
       else
 	{
-	  yystack->yytops.yystates[yyj] = yystack->yytops.yystates[yyi];
+	  yystackp->yytops.yystates[yyj] = yystackp->yytops.yystates[yyi];
 	  if (yyj != yyi)
 	    {
 	      YYDPRINTF ((stderr, "Rename stack %lu -> %lu.\n",
@@ -1277,41 +1277,41 @@ yyremoveDeletes (yyGLRStack* yystack)
 /** Shift to a new state on stack #K of STACK, corresponding to LR state
  * LRSTATE, at input position POSN, with (resolved) semantic value SVAL. */
 static inline void
-yyglrShift (yyGLRStack* yystack, size_t yyk, yyStateNum yylrState,
+yyglrShift (yyGLRStack* yystackp, size_t yyk, yyStateNum yylrState,
 	    size_t yyposn,
-	    YYSTYPE yysval, YYLTYPE* yylocp)
+	    YYSTYPE* yyvalp, YYLTYPE* yylocp)
 {
-  yyGLRState* yynewState = &yynewGLRStackItem (yystack, yytrue)->yystate;
+  yyGLRState* yynewState = &yynewGLRStackItem (yystackp, yytrue)->yystate;
 
   yynewState->yylrState = yylrState;
   yynewState->yyposn = yyposn;
   yynewState->yyresolved = yytrue;
-  yynewState->yypred = yystack->yytops.yystates[yyk];
-  yynewState->yysemantics.yysval = yysval;
+  yynewState->yypred = yystackp->yytops.yystates[yyk];
+  yynewState->yysemantics.yysval = *yyvalp;
   yynewState->yyloc = *yylocp;
-  yystack->yytops.yystates[yyk] = yynewState;
+  yystackp->yytops.yystates[yyk] = yynewState;
 
-  YY_RESERVE_GLRSTACK (yystack);
+  YY_RESERVE_GLRSTACK (yystackp);
 }
 
 /** Shift stack #K of YYSTACK, to a new state corresponding to LR
  *  state YYLRSTATE, at input position YYPOSN, with the (unresolved)
  *  semantic value of YYRHS under the action for YYRULE. */
 static inline void
-yyglrShiftDefer (yyGLRStack* yystack, size_t yyk, yyStateNum yylrState,
+yyglrShiftDefer (yyGLRStack* yystackp, size_t yyk, yyStateNum yylrState,
 		 size_t yyposn, yyGLRState* rhs, yyRuleNum yyrule)
 {
-  yyGLRState* yynewState = &yynewGLRStackItem (yystack, yytrue)->yystate;
+  yyGLRState* yynewState = &yynewGLRStackItem (yystackp, yytrue)->yystate;
 
   yynewState->yylrState = yylrState;
   yynewState->yyposn = yyposn;
   yynewState->yyresolved = yyfalse;
-  yynewState->yypred = yystack->yytops.yystates[yyk];
+  yynewState->yypred = yystackp->yytops.yystates[yyk];
   yynewState->yysemantics.yyfirstVal = NULL;
-  yystack->yytops.yystates[yyk] = yynewState;
+  yystackp->yytops.yystates[yyk] = yynewState;
 
   /* Invokes YY_RESERVE_GLRSTACK. */
-  yyaddDeferredAction (yystack, yynewState, rhs, yyrule);
+  yyaddDeferredAction (yystackp, yynewState, rhs, yyrule);
 }
 
 /** Pop the symbols consumed by reduction #RULE from the top of stack
@@ -1321,21 +1321,21 @@ yyglrShiftDefer (yyGLRStack* yystack, size_t yyk, yyStateNum yylrState,
  *  and *LOCP to the computed location (if any).  Return value is as
  *  for userAction. */
 static inline YYRESULTTAG
-yydoAction (yyGLRStack* yystack, size_t yyk, yyRuleNum yyrule,
+yydoAction (yyGLRStack* yystackp, size_t yyk, yyRuleNum yyrule,
 	    YYSTYPE* yyvalp, YYLTYPE* yylocp]b4_user_formals[)
 {
   int yynrhs = yyrhsLength (yyrule);
 
-  if (yystack->yysplitPoint == NULL)
+  if (yystackp->yysplitPoint == NULL)
     {
       /* Standard special case: single stack. */
-      yyGLRStackItem* rhs = (yyGLRStackItem*) yystack->yytops.yystates[yyk];
+      yyGLRStackItem* rhs = (yyGLRStackItem*) yystackp->yytops.yystates[yyk];
       YYASSERT (yyk == 0);
-      yystack->yynextFree -= yynrhs;
-      yystack->yyspaceLeft += yynrhs;
-      yystack->yytops.yystates[0] = & yystack->yynextFree[-1].yystate;
+      yystackp->yynextFree -= yynrhs;
+      yystackp->yyspaceLeft += yynrhs;
+      yystackp->yytops.yystates[0] = & yystackp->yynextFree[-1].yystate;
       return yyuserAction (yyrule, yynrhs, rhs,
-			   yyvalp, yylocp, yystack]b4_user_args[);
+			   yyvalp, yylocp, yystackp]b4_user_args[);
     }
   else
     {
@@ -1347,7 +1347,7 @@ yydoAction (yyGLRStack* yystack, size_t yyk, yyRuleNum yyrule,
       yyGLRState* yys;
       yyGLRStackItem yyrhsVals[YYMAXRHS + YYMAXLEFT + 1];
       yys = yyrhsVals[YYMAXRHS + YYMAXLEFT].yystate.yypred
-	= yystack->yytops.yystates[yyk];]b4_location_if([[
+	= yystackp->yytops.yystates[yyk];]b4_location_if([[
       if (yynrhs == 0)
 	/* Set default location. */
 	yyrhsVals[YYMAXRHS + YYMAXLEFT - 1].yystate.yyloc = yys->yyloc;]])[
@@ -1356,10 +1356,10 @@ yydoAction (yyGLRStack* yystack, size_t yyk, yyRuleNum yyrule,
 	  yys = yys->yypred;
 	  YYASSERT (yys);
 	}
-      yyupdateSplit (yystack, yys);
-      yystack->yytops.yystates[yyk] = yys;
+      yyupdateSplit (yystackp, yys);
+      yystackp->yytops.yystates[yyk] = yys;
       return yyuserAction (yyrule, yynrhs, yyrhsVals + YYMAXRHS + YYMAXLEFT - 1,
-			   yyvalp, yylocp, yystack]b4_user_args[);
+			   yyvalp, yylocp, yystackp]b4_user_args[);
     }
 }
 
@@ -1377,13 +1377,13 @@ do {					\
 `----------------------------------------------------------*/
 
 /*ARGSUSED*/ static inline void
-yy_reduce_print (yyGLRStack* yystack, size_t yyk, yyRuleNum yyrule,
+yy_reduce_print (yyGLRStack* yystackp, size_t yyk, yyRuleNum yyrule,
 		 YYSTYPE* yyvalp, YYLTYPE* yylocp]b4_user_formals[)
 {
   int yynrhs = yyrhsLength (yyrule);
   yybool yynormal __attribute__ ((__unused__)) =
-    (yystack->yysplitPoint == NULL);
-  yyGLRStackItem* yyvsp = (yyGLRStackItem*) yystack->yytops.yystates[yyk];
+    (yystackp->yysplitPoint == NULL);
+  yyGLRStackItem* yyvsp = (yyGLRStackItem*) yystackp->yytops.yystates[yyk];
   int yylow = 1;
   int yyi;
   YYUSE (yyvalp);
@@ -1417,53 +1417,54 @@ yy_reduce_print (yyGLRStack* yystack, size_t yyk, yyRuleNum yyrule,
  *  added to the options for the existing state's semantic value.
  */
 static inline YYRESULTTAG
-yyglrReduce (yyGLRStack* yystack, size_t yyk, yyRuleNum yyrule,
+yyglrReduce (yyGLRStack* yystackp, size_t yyk, yyRuleNum yyrule,
 	     yybool yyforceEval]b4_user_formals[)
 {
-  size_t yyposn = yystack->yytops.yystates[yyk]->yyposn;
+  size_t yyposn = yystackp->yytops.yystates[yyk]->yyposn;
 
-  if (yyforceEval || yystack->yysplitPoint == NULL)
+  if (yyforceEval || yystackp->yysplitPoint == NULL)
     {
       YYSTYPE yysval;
       YYLTYPE yyloc;
 
-      YY_REDUCE_PRINT ((yystack, yyk, yyrule, &yysval, &yyloc]b4_user_args[));
-      YYCHK (yydoAction (yystack, yyk, yyrule, &yysval, &yyloc]b4_user_args[));
+      YY_REDUCE_PRINT ((yystackp, yyk, yyrule, &yysval, &yyloc]b4_user_args[));
+      YYCHK (yydoAction (yystackp, yyk, yyrule, &yysval,
+			 &yyloc]b4_user_args[));
       YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyrule], &yysval, &yyloc);
-      yyglrShift (yystack, yyk,
-		  yyLRgotoState (yystack->yytops.yystates[yyk]->yylrState,
+      yyglrShift (yystackp, yyk,
+		  yyLRgotoState (yystackp->yytops.yystates[yyk]->yylrState,
 				 yylhsNonterm (yyrule)),
-		  yyposn, yysval, &yyloc);
+		  yyposn, &yysval, &yyloc);
     }
   else
     {
       size_t yyi;
       int yyn;
-      yyGLRState* yys, *yys0 = yystack->yytops.yystates[yyk];
+      yyGLRState* yys, *yys0 = yystackp->yytops.yystates[yyk];
       yyStateNum yynewLRState;
 
-      for (yys = yystack->yytops.yystates[yyk], yyn = yyrhsLength (yyrule);
+      for (yys = yystackp->yytops.yystates[yyk], yyn = yyrhsLength (yyrule);
 	   0 < yyn; yyn -= 1)
 	{
 	  yys = yys->yypred;
 	  YYASSERT (yys);
 	}
-      yyupdateSplit (yystack, yys);
+      yyupdateSplit (yystackp, yys);
       yynewLRState = yyLRgotoState (yys->yylrState, yylhsNonterm (yyrule));
       YYDPRINTF ((stderr,
 		  "Reduced stack %lu by rule #%d; action deferred. Now in state %d.\n",
 		  (unsigned long int) yyk, yyrule - 1, yynewLRState));
-      for (yyi = 0; yyi < yystack->yytops.yysize; yyi += 1)
-	if (yyi != yyk && yystack->yytops.yystates[yyi] != NULL)
+      for (yyi = 0; yyi < yystackp->yytops.yysize; yyi += 1)
+	if (yyi != yyk && yystackp->yytops.yystates[yyi] != NULL)
 	  {
-	    yyGLRState* yyp, *yysplit = yystack->yysplitPoint;
-	    yyp = yystack->yytops.yystates[yyi];
+	    yyGLRState* yyp, *yysplit = yystackp->yysplitPoint;
+	    yyp = yystackp->yytops.yystates[yyi];
 	    while (yyp != yys && yyp != yysplit && yyp->yyposn >= yyposn)
 	      {
 		if (yyp->yylrState == yynewLRState && yyp->yypred == yys)
 		  {
-		    yyaddDeferredAction (yystack, yyp, yys0, yyrule);
-		    yymarkStackDeleted (yystack, yyk);
+		    yyaddDeferredAction (yystackp, yyp, yys0, yyrule);
+		    yymarkStackDeleted (yystackp, yyk);
 		    YYDPRINTF ((stderr, "Merging stack %lu into stack %lu.\n",
 				(unsigned long int) yyk,
 				(unsigned long int) yyi));
@@ -1472,36 +1473,36 @@ yyglrReduce (yyGLRStack* yystack, size_t yyk, yyRuleNum yyrule,
 		yyp = yyp->yypred;
 	      }
 	  }
-      yystack->yytops.yystates[yyk] = yys;
-      yyglrShiftDefer (yystack, yyk, yynewLRState, yyposn, yys0, yyrule);
+      yystackp->yytops.yystates[yyk] = yys;
+      yyglrShiftDefer (yystackp, yyk, yynewLRState, yyposn, yys0, yyrule);
     }
   return yyok;
 }
 
 static size_t
-yysplitStack (yyGLRStack* yystack, size_t yyk)
+yysplitStack (yyGLRStack* yystackp, size_t yyk)
 {
-  if (yystack->yysplitPoint == NULL)
+  if (yystackp->yysplitPoint == NULL)
     {
       YYASSERT (yyk == 0);
-      yystack->yysplitPoint = yystack->yytops.yystates[yyk];
+      yystackp->yysplitPoint = yystackp->yytops.yystates[yyk];
     }
-  if (yystack->yytops.yysize >= yystack->yytops.yycapacity)
+  if (yystackp->yytops.yysize >= yystackp->yytops.yycapacity)
     {
       yyGLRState** yynewStates;
-      if (! ((yystack->yytops.yycapacity
+      if (! ((yystackp->yytops.yycapacity
 	      <= (YYSIZEMAX / (2 * sizeof yynewStates[0])))
 	     && (yynewStates =
-		 (yyGLRState**) YYREALLOC (yystack->yytops.yystates,
-					   ((yystack->yytops.yycapacity *= 2)
+		 (yyGLRState**) YYREALLOC (yystackp->yytops.yystates,
+					   ((yystackp->yytops.yycapacity *= 2)
 					    * sizeof yynewStates[0])))))
-	yyMemoryExhausted (yystack);
-      yystack->yytops.yystates = yynewStates;
+	yyMemoryExhausted (yystackp);
+      yystackp->yytops.yystates = yynewStates;
     }
-  yystack->yytops.yystates[yystack->yytops.yysize]
-    = yystack->yytops.yystates[yyk];
-  yystack->yytops.yysize += 1;
-  return yystack->yytops.yysize-1;
+  yystackp->yytops.yystates[yystackp->yytops.yysize]
+    = yystackp->yytops.yystates[yyk];
+  yystackp->yytops.yysize += 1;
+  return yystackp->yytops.yysize-1;
 }
 
 /** True iff Y0 and Y1 represent identical options at the top level.
@@ -1556,7 +1557,7 @@ yymergeOptionSets (yySemanticOption* yyy0, yySemanticOption* yyy1)
 	  yySemanticOption* yyz1;
 	  yyz0p = &yys0->yysemantics.yyfirstVal;
 	  yyz1 = yys1->yysemantics.yyfirstVal;
-	  while (yytrue)
+	  while (YYID (yytrue))
 	    {
 	      if (yyz1 == *yyz0p || yyz1 == NULL)
 		break;
@@ -1605,22 +1606,23 @@ yypreference (yySemanticOption* y0, yySemanticOption* y1)
 }
 
 static YYRESULTTAG yyresolveValue (yySemanticOption* yyoptionList,
-				   yyGLRStack* yystack, YYSTYPE* yyvalp,
+				   yyGLRStack* yystackp, YYSTYPE* yyvalp,
 				   YYLTYPE* yylocp]b4_user_formals[);
 
 static YYRESULTTAG
-yyresolveStates (yyGLRState* yys, int yyn, yyGLRStack* yystack]b4_user_formals[)
+yyresolveStates (yyGLRState* yys, int yyn,
+		 yyGLRStack* yystackp]b4_user_formals[)
 {
   YYRESULTTAG yyflag;
   if (0 < yyn)
     {
       YYASSERT (yys->yypred);
-      yyflag = yyresolveStates (yys->yypred, yyn-1, yystack]b4_user_args[);
+      yyflag = yyresolveStates (yys->yypred, yyn-1, yystackp]b4_user_args[);
       if (yyflag != yyok)
 	return yyflag;
       if (! yys->yyresolved)
 	{
-	  yyflag = yyresolveValue (yys->yysemantics.yyfirstVal, yystack,
+	  yyflag = yyresolveValue (yys->yysemantics.yyfirstVal, yystackp,
 				   &yys->yysemantics.yysval, &yys->yyloc
 				  ]b4_user_args[);
 	  if (yyflag != yyok)
@@ -1632,21 +1634,21 @@ yyresolveStates (yyGLRState* yys, int yyn, yyGLRStack* yystack]b4_user_formals[)
 }
 
 static YYRESULTTAG
-yyresolveAction (yySemanticOption* yyopt, yyGLRStack* yystack,
+yyresolveAction (yySemanticOption* yyopt, yyGLRStack* yystackp,
 		 YYSTYPE* yyvalp, YYLTYPE* yylocp]b4_user_formals[)
 {
   yyGLRStackItem yyrhsVals[YYMAXRHS + YYMAXLEFT + 1];
   int yynrhs;
 
   yynrhs = yyrhsLength (yyopt->yyrule);
-  YYCHK (yyresolveStates (yyopt->yystate, yynrhs, yystack]b4_user_args[));
+  YYCHK (yyresolveStates (yyopt->yystate, yynrhs, yystackp]b4_user_args[));
   yyrhsVals[YYMAXRHS + YYMAXLEFT].yystate.yypred = yyopt->yystate;]b4_location_if([[
   if (yynrhs == 0)
     /* Set default location. */
     yyrhsVals[YYMAXRHS + YYMAXLEFT - 1].yystate.yyloc = yyopt->yystate->yyloc;]])[
   return yyuserAction (yyopt->yyrule, yynrhs,
 		       yyrhsVals + YYMAXRHS + YYMAXLEFT - 1,
-		       yyvalp, yylocp, yystack]b4_user_args[);
+		       yyvalp, yylocp, yystackp]b4_user_args[);
 }
 
 #if YYDEBUG
@@ -1698,11 +1700,11 @@ yyreportTree (yySemanticOption* yyx, int yyindent)
 #endif
 
 static void yyreportAmbiguity (yySemanticOption* yyx0, yySemanticOption* yyx1,
-			       yyGLRStack* yystack]b4_pure_formals[)
+			       yyGLRStack* yystackp]b4_pure_formals[)
   __attribute__ ((__noreturn__));
 static void
 yyreportAmbiguity (yySemanticOption* yyx0, yySemanticOption* yyx1,
-		   yyGLRStack* yystack]b4_pure_formals[)
+		   yyGLRStack* yystackp]b4_pure_formals[)
 {
   YYUSE (yyx0);
   YYUSE (yyx1);
@@ -1715,14 +1717,14 @@ yyreportAmbiguity (yySemanticOption* yyx0, yySemanticOption* yyx1,
   yyreportTree (yyx1, 2);
   YYFPRINTF (stderr, "\n");
 #endif
-  yyFail (yystack][]b4_pure_args[, YY_("syntax is ambiguous"));
+  yyFail (yystackp][]b4_pure_args[, YY_("syntax is ambiguous"));
 }
 
 
 /** Resolve the ambiguity represented by OPTIONLIST, perform the indicated
  *  actions, and return the result. */
 static YYRESULTTAG
-yyresolveValue (yySemanticOption* yyoptionList, yyGLRStack* yystack,
+yyresolveValue (yySemanticOption* yyoptionList, yyGLRStack* yystackp,
 		YYSTYPE* yyvalp, YYLTYPE* yylocp]b4_user_formals[)
 {
   yySemanticOption* yybest;
@@ -1745,7 +1747,7 @@ yyresolveValue (yySemanticOption* yyoptionList, yyGLRStack* yystack,
 	  switch (yypreference (yybest, yyp))
 	    {
 	    case 0:
-	      yyreportAmbiguity (yybest, yyp, yystack]b4_pure_args[);
+	      yyreportAmbiguity (yybest, yyp, yystackp]b4_pure_args[);
 	      break;
 	    case 1:
 	      yymerge = yytrue;
@@ -1770,84 +1772,85 @@ yyresolveValue (yySemanticOption* yyoptionList, yyGLRStack* yystack,
     {
       yySemanticOption* yyp;
       int yyprec = yydprec[yybest->yyrule];
-      YYCHK (yyresolveAction (yybest, yystack, yyvalp, yylocp]b4_user_args[));
+      YYCHK (yyresolveAction (yybest, yystackp, yyvalp, yylocp]b4_user_args[));
       for (yyp = yybest->yynext; yyp != NULL; yyp = yyp->yynext)
 	{
 	  if (yyprec == yydprec[yyp->yyrule])
 	    {
 	      YYSTYPE yyval1;
 	      YYLTYPE yydummy;
-	      YYCHK (yyresolveAction (yyp, yystack, &yyval1, &yydummy]b4_user_args[));
+	      YYCHK (yyresolveAction (yyp, yystackp, &yyval1,
+				      &yydummy]b4_user_args[));
 	      yyuserMerge (yymerger[yyp->yyrule], yyvalp, &yyval1);
 	    }
 	}
       return yyok;
     }
   else
-    return yyresolveAction (yybest, yystack, yyvalp, yylocp]b4_user_args[);
+    return yyresolveAction (yybest, yystackp, yyvalp, yylocp]b4_user_args[);
 }
 
 static YYRESULTTAG
-yyresolveStack (yyGLRStack* yystack]b4_user_formals[)
+yyresolveStack (yyGLRStack* yystackp]b4_user_formals[)
 {
-  if (yystack->yysplitPoint != NULL)
+  if (yystackp->yysplitPoint != NULL)
     {
       yyGLRState* yys;
       int yyn;
 
-      for (yyn = 0, yys = yystack->yytops.yystates[0];
-	   yys != yystack->yysplitPoint;
+      for (yyn = 0, yys = yystackp->yytops.yystates[0];
+	   yys != yystackp->yysplitPoint;
 	   yys = yys->yypred, yyn += 1)
 	continue;
-      YYCHK (yyresolveStates (yystack->yytops.yystates[0], yyn, yystack
+      YYCHK (yyresolveStates (yystackp->yytops.yystates[0], yyn, yystackp
 			     ]b4_user_args[));
     }
   return yyok;
 }
 
 static void
-yycompressStack (yyGLRStack* yystack)
+yycompressStack (yyGLRStack* yystackp)
 {
   yyGLRState* yyp, *yyq, *yyr;
 
-  if (yystack->yytops.yysize != 1 || yystack->yysplitPoint == NULL)
+  if (yystackp->yytops.yysize != 1 || yystackp->yysplitPoint == NULL)
     return;
 
-  for (yyp = yystack->yytops.yystates[0], yyq = yyp->yypred, yyr = NULL;
-       yyp != yystack->yysplitPoint;
+  for (yyp = yystackp->yytops.yystates[0], yyq = yyp->yypred, yyr = NULL;
+       yyp != yystackp->yysplitPoint;
        yyr = yyp, yyp = yyq, yyq = yyp->yypred)
     yyp->yypred = yyr;
 
-  yystack->yyspaceLeft += yystack->yynextFree - yystack->yyitems;
-  yystack->yynextFree = ((yyGLRStackItem*) yystack->yysplitPoint) + 1;
-  yystack->yyspaceLeft -= yystack->yynextFree - yystack->yyitems;
-  yystack->yysplitPoint = NULL;
-  yystack->yylastDeleted = NULL;
+  yystackp->yyspaceLeft += yystackp->yynextFree - yystackp->yyitems;
+  yystackp->yynextFree = ((yyGLRStackItem*) yystackp->yysplitPoint) + 1;
+  yystackp->yyspaceLeft -= yystackp->yynextFree - yystackp->yyitems;
+  yystackp->yysplitPoint = NULL;
+  yystackp->yylastDeleted = NULL;
 
   while (yyr != NULL)
     {
-      yystack->yynextFree->yystate = *yyr;
+      yystackp->yynextFree->yystate = *yyr;
       yyr = yyr->yypred;
-      yystack->yynextFree->yystate.yypred = & yystack->yynextFree[-1].yystate;
-      yystack->yytops.yystates[0] = &yystack->yynextFree->yystate;
-      yystack->yynextFree += 1;
-      yystack->yyspaceLeft -= 1;
+      yystackp->yynextFree->yystate.yypred = &yystackp->yynextFree[-1].yystate;
+      yystackp->yytops.yystates[0] = &yystackp->yynextFree->yystate;
+      yystackp->yynextFree += 1;
+      yystackp->yyspaceLeft -= 1;
     }
 }
 
 static YYRESULTTAG
-yyprocessOneStack (yyGLRStack* yystack, size_t yyk,
+yyprocessOneStack (yyGLRStack* yystackp, size_t yyk,
 		   size_t yyposn, YYSTYPE* yylvalp, YYLTYPE* yyllocp
 		  ]b4_pure_formals[)
 {
   int yyaction;
   const short int* yyconflicts;
   yyRuleNum yyrule;
-  yySymbol* const yytokenp = yystack->yytokenp;
+  yySymbol* const yytokenp = yystackp->yytokenp;
 
-  while (yystack->yytops.yystates[yyk] != NULL)
+  while (yystackp->yytops.yystates[yyk] != NULL)
     {
-      yyStateNum yystate = yystack->yytops.yystates[yyk]->yylrState;
+      yyStateNum yystate = yystackp->yytops.yystates[yyk]->yylrState;
       YYDPRINTF ((stderr, "Stack %lu Entering state %d\n",
 		  (unsigned long int) yyk, yystate));
 
@@ -1860,10 +1863,10 @@ yyprocessOneStack (yyGLRStack* yystack, size_t yyk,
 	    {
 	      YYDPRINTF ((stderr, "Stack %lu dies.\n",
 			  (unsigned long int) yyk));
-	      yymarkStackDeleted (yystack, yyk);
+	      yymarkStackDeleted (yystackp, yyk);
 	      return yyok;
 	    }
-	  YYCHK (yyglrReduce (yystack, yyk, yyrule, yyfalse]b4_user_args[));
+	  YYCHK (yyglrReduce (yystackp, yyk, yyrule, yyfalse]b4_user_args[));
 	}
       else
 	{
@@ -1878,13 +1881,13 @@ yyprocessOneStack (yyGLRStack* yystack, size_t yyk,
 
 	  while (*yyconflicts != 0)
 	    {
-	      size_t yynewStack = yysplitStack (yystack, yyk);
+	      size_t yynewStack = yysplitStack (yystackp, yyk);
 	      YYDPRINTF ((stderr, "Splitting off stack %lu from %lu.\n",
 			  (unsigned long int) yynewStack,
 			  (unsigned long int) yyk));
-	      YYCHK (yyglrReduce (yystack, yynewStack,
+	      YYCHK (yyglrReduce (yystackp, yynewStack,
 				  *yyconflicts, yyfalse]b4_user_args[));
-	      YYCHK (yyprocessOneStack (yystack, yynewStack, yyposn,
+	      YYCHK (yyprocessOneStack (yystackp, yynewStack, yyposn,
 					yylvalp, yyllocp]b4_pure_args[));
 	      yyconflicts += 1;
 	    }
@@ -1895,29 +1898,29 @@ yyprocessOneStack (yyGLRStack* yystack, size_t yyk,
 	    {
 	      YYDPRINTF ((stderr, "Stack %lu dies.\n",
 			  (unsigned long int) yyk));
-	      yymarkStackDeleted (yystack, yyk);
+	      yymarkStackDeleted (yystackp, yyk);
 	      break;
 	    }
 	  else
-	    YYCHK (yyglrReduce (yystack, yyk, -yyaction, yyfalse]b4_user_args[));
+	    YYCHK (yyglrReduce (yystackp, yyk, -yyaction, yyfalse]b4_user_args[));
 	}
     }
   return yyok;
 }
 
-static void
-yyreportSyntaxError (yyGLRStack* yystack,
+/*ARGSUSED*/ static void
+yyreportSyntaxError (yyGLRStack* yystackp,
 		     YYSTYPE* yylvalp, YYLTYPE* yyllocp]b4_user_formals[)
 {
   YYUSE (yylvalp);
   YYUSE (yyllocp);
 
-  if (yystack->yyerrState == 0)
+  if (yystackp->yyerrState == 0)
     {
 #if YYERROR_VERBOSE
-      yySymbol* const yytokenp = yystack->yytokenp;
+      yySymbol* const yytokenp = yystackp->yytokenp;
       int yyn;
-      yyn = yypact[yystack->yytops.yystates[0]->yylrState];
+      yyn = yypact[yystackp->yytops.yystates[0]->yylrState];
       if (YYPACT_NINF < yyn && yyn < YYLAST)
 	{
 	  size_t yysize0 = yytnamerr (NULL, yytokenName (*yytokenp));
@@ -2000,7 +2003,7 @@ yyreportSyntaxError (yyGLRStack* yystack,
 	  else
 	    {
 	      yyerror (]b4_lyyerror_args[YY_("syntax error"));
-	      yyMemoryExhausted (yystack);
+	      yyMemoryExhausted (yystackp);
 	    }
 	}
       else
@@ -2014,27 +2017,27 @@ yyreportSyntaxError (yyGLRStack* yystack,
    YYLVALP, and YYLLOCP point to the syntactic category, semantic
    value, and location of the look-ahead.  */
 /*ARGSUSED*/ static void
-yyrecoverSyntaxError (yyGLRStack* yystack,
+yyrecoverSyntaxError (yyGLRStack* yystackp,
 		      YYSTYPE* yylvalp,
 		      YYLTYPE* YYOPTIONAL_LOC (yyllocp)
 		      ]b4_user_formals[)
 {
-  yySymbol* const yytokenp = yystack->yytokenp;
+  yySymbol* const yytokenp = yystackp->yytokenp;
   size_t yyk;
   int yyj;
 
-  if (yystack->yyerrState == 3)
+  if (yystackp->yyerrState == 3)
     /* We just shifted the error token and (perhaps) took some
        reductions.  Skip tokens until we can proceed.  */
-    while (yytrue)
+    while (YYID (yytrue))
       {
 	if (*yytokenp == YYEOF)
-	  yyFail (yystack][]b4_lpure_args[, NULL);
+	  yyFail (yystackp][]b4_lpure_args[, NULL);
 	if (*yytokenp != YYEMPTY)
 	  {]b4_location_if([[
 	    /* We throw away the lookahead, but the error range
 	       of the shifted error token must take it into account. */
-	    yyGLRState *yys = yystack->yytops.yystates[0];
+	    yyGLRState *yys = yystackp->yytops.yystates[0];
 	    yyGLRStackItem yyerror_range[3];
 	    yyerror_range[1].yystate.yyloc = yys->yyloc;
 	    yyerror_range[2].yystate.yyloc = *yyllocp;
@@ -2046,13 +2049,13 @@ yyrecoverSyntaxError (yyGLRStack* yystack,
 	yychar = YYLEX;
 	*yytokenp = YYTRANSLATE (yychar);
 	YY_SYMBOL_PRINT ("Next token is", *yytokenp, yylvalp, yyllocp);
-	yyj = yypact[yystack->yytops.yystates[0]->yylrState];
+	yyj = yypact[yystackp->yytops.yystates[0]->yylrState];
 	if (yyis_pact_ninf (yyj))
 	  return;
 	yyj += *yytokenp;
 	if (yyj < 0 || YYLAST < yyj || yycheck[yyj] != *yytokenp)
 	  {
-	    if (yydefact[yystack->yytops.yystates[0]->yylrState] != 0)
+	    if (yydefact[yystackp->yytops.yystates[0]->yylrState] != 0)
 	      return;
 	  }
 	else if (yytable[yyj] != 0 && ! yyis_table_ninf (yytable[yyj]))
@@ -2060,21 +2063,21 @@ yyrecoverSyntaxError (yyGLRStack* yystack,
       }
 
   /* Reduce to one stack.  */
-  for (yyk = 0; yyk < yystack->yytops.yysize; yyk += 1)
-    if (yystack->yytops.yystates[yyk] != NULL)
+  for (yyk = 0; yyk < yystackp->yytops.yysize; yyk += 1)
+    if (yystackp->yytops.yystates[yyk] != NULL)
       break;
-  if (yyk >= yystack->yytops.yysize)
-    yyFail (yystack][]b4_lpure_args[, NULL);
-  for (yyk += 1; yyk < yystack->yytops.yysize; yyk += 1)
-    yymarkStackDeleted (yystack, yyk);
-  yyremoveDeletes (yystack);
-  yycompressStack (yystack);
+  if (yyk >= yystackp->yytops.yysize)
+    yyFail (yystackp][]b4_lpure_args[, NULL);
+  for (yyk += 1; yyk < yystackp->yytops.yysize; yyk += 1)
+    yymarkStackDeleted (yystackp, yyk);
+  yyremoveDeletes (yystackp);
+  yycompressStack (yystackp);
 
   /* Now pop stack until we find a state that shifts the error token. */
-  yystack->yyerrState = 3;
-  while (yystack->yytops.yystates[0] != NULL)
+  yystackp->yyerrState = 3;
+  while (yystackp->yytops.yystates[0] != NULL)
     {
-      yyGLRState *yys = yystack->yytops.yystates[0];
+      yyGLRState *yys = yystackp->yytops.yystates[0];
       yyj = yypact[yys->yylrState];
       if (! yyis_pact_ninf (yyj))
 	{
@@ -2084,24 +2087,24 @@ yyrecoverSyntaxError (yyGLRStack* yystack,
 	    {
 	      /* Shift the error token having adjusted its location.  */
 	      YYLTYPE yyerrloc;]b4_location_if([[
-	      yystack->yyerror_range[2].yystate.yyloc = *yyllocp;
-	      YYLLOC_DEFAULT (yyerrloc, yystack->yyerror_range, 2);]])[
+	      yystackp->yyerror_range[2].yystate.yyloc = *yyllocp;
+	      YYLLOC_DEFAULT (yyerrloc, yystackp->yyerror_range, 2);]])[
 	      YY_SYMBOL_PRINT ("Shifting", yystos[yytable[yyj]],
 			       yylvalp, &yyerrloc);
-	      yyglrShift (yystack, 0, yytable[yyj],
-			  yys->yyposn, *yylvalp, &yyerrloc);
-	      yys = yystack->yytops.yystates[0];
+	      yyglrShift (yystackp, 0, yytable[yyj],
+			  yys->yyposn, yylvalp, &yyerrloc);
+	      yys = yystackp->yytops.yystates[0];
 	      break;
 	    }
 	}
-]b4_location_if([[      yystack->yyerror_range[1].yystate.yyloc = yys->yyloc;]])[
+]b4_location_if([[      yystackp->yyerror_range[1].yystate.yyloc = yys->yyloc;]])[
       yydestroyGLRState ("Error: popping", yys]b4_user_args[);
-      yystack->yytops.yystates[0] = yys->yypred;
-      yystack->yynextFree -= 1;
-      yystack->yyspaceLeft += 1;
+      yystackp->yytops.yystates[0] = yys->yypred;
+      yystackp->yynextFree -= 1;
+      yystackp->yyspaceLeft += 1;
     }
-  if (yystack->yytops.yystates[0] == NULL)
-    yyFail (yystack][]b4_lpure_args[, NULL);
+  if (yystackp->yytops.yystates[0] == NULL)
+    yyFail (yystackp][]b4_lpure_args[, NULL);
 }
 
 #define YYCHK1(YYE)							     \
@@ -2172,16 +2175,16 @@ b4_syncline([@oline@], [@ofile@])])dnl
     default: goto yybuglab;
     }
   yystack.yytokenp = &yytoken;
-  yyglrShift (&yystack, 0, 0, 0, yylval, &yylloc);
+  yyglrShift (&yystack, 0, 0, 0, &yylval, &yylloc);
   yyposn = 0;
 
-  while (yytrue)
+  while (YYID (yytrue))
     {
       /* For efficiency, we have two loops, the first of which is
 	 specialized to deterministic operation (single stack, no
 	 potential ambiguity).  */
       /* Standard mode */
-      while (yytrue)
+      while (YYID (yytrue))
 	{
 	  yyRuleNum yyrule;
 	  int yyaction;
@@ -2220,7 +2223,7 @@ b4_syncline([@oline@], [@ofile@])])dnl
 		  if (yytoken != YYEOF)
 		    yytoken = YYEMPTY;
 		  yyposn += 1;
-		  yyglrShift (&yystack, 0, yyaction, yyposn, yylval, yyllocp);
+		  yyglrShift (&yystack, 0, yyaction, yyposn, yylvalp, yyllocp);
 		  if (0 < yystack.yyerrState)
 		    yystack.yyerrState -= 1;
 		}
@@ -2235,7 +2238,7 @@ b4_syncline([@oline@], [@ofile@])])dnl
 	    }
 	}
 
-      while (yytrue)
+      while (YYID (yytrue))
 	{
 	  yySymbol yytoken_to_shift;
 	  size_t yys;
@@ -2285,7 +2288,7 @@ b4_syncline([@oline@], [@ofile@])])dnl
 	      YYDPRINTF ((stderr, "On stack %lu, ", (unsigned long int) yys));
 	      YY_SYMBOL_PRINT ("shifting", yytoken_to_shift, yylvalp, yyllocp);
 	      yyglrShift (&yystack, yys, yyaction, yyposn,
-			  *yylvalp, yyllocp);
+			  yylvalp, yyllocp);
 	      YYDPRINTF ((stderr, "Stack %lu now in state #%d\n",
 			  (unsigned long int) yys,
 			  yystack.yytops.yystates[yys]->yylrState));
@@ -2370,9 +2373,9 @@ b4_syncline([@oline@], [@ofile@])])dnl
 
 /* DEBUGGING ONLY */
 #ifdef YYDEBUG
-static void yypstack (yyGLRStack* yystack, size_t yyk)
+static void yypstack (yyGLRStack* yystackp, size_t yyk)
   __attribute__ ((__unused__));
-static void yypdumpstack (yyGLRStack* yystack) __attribute__ ((__unused__));
+static void yypdumpstack (yyGLRStack* yystackp) __attribute__ ((__unused__));
 
 static void
 yy_yypstack (yyGLRState* yys)
@@ -2396,23 +2399,23 @@ yypstates (yyGLRState* yyst)
 }
 
 static void
-yypstack (yyGLRStack* yystack, size_t yyk)
+yypstack (yyGLRStack* yystackp, size_t yyk)
 {
-  yypstates (yystack->yytops.yystates[yyk]);
+  yypstates (yystackp->yytops.yystates[yyk]);
 }
 
 #define YYINDEX(YYX)							     \
-    ((YYX) == NULL ? -1 : (yyGLRStackItem*) (YYX) - yystack->yyitems)
+    ((YYX) == NULL ? -1 : (yyGLRStackItem*) (YYX) - yystackp->yyitems)
 
 
 static void
-yypdumpstack (yyGLRStack* yystack)
+yypdumpstack (yyGLRStack* yystackp)
 {
   yyGLRStackItem* yyp;
   size_t yyi;
-  for (yyp = yystack->yyitems; yyp < yystack->yynextFree; yyp += 1)
+  for (yyp = yystackp->yyitems; yyp < yystackp->yynextFree; yyp += 1)
     {
-      fprintf (stderr, "%3lu. ", (unsigned long int) (yyp - yystack->yyitems));
+      fprintf (stderr, "%3lu. ", (unsigned long int) (yyp - yystackp->yyitems));
       if (*(yybool *) yyp)
 	{
 	  fprintf (stderr, "Res: %d, LR State: %d, posn: %lu, pred: %ld",
@@ -2433,9 +2436,9 @@ yypdumpstack (yyGLRStack* yystack)
       fprintf (stderr, "\n");
     }
   fprintf (stderr, "Tops:");
-  for (yyi = 0; yyi < yystack->yytops.yysize; yyi += 1)
+  for (yyi = 0; yyi < yystackp->yytops.yysize; yyi += 1)
     fprintf (stderr, "%lu: %ld; ", (unsigned long int) yyi,
-	     (long int) YYINDEX (yystack->yytops.yystates[yyi]));
+	     (long int) YYINDEX (yystackp->yytops.yystates[yyi]));
   fprintf (stderr, "\n");
 }
 #endif
