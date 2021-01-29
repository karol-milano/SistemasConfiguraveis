@@ -93,13 +93,27 @@ m4_define([b4_lpure_args],
 [b4_pure_if([b4_locations_if([, &yylloc])])[]b4_user_args])
 
 
+
 # b4_pure_formals
 # ---------------
-# Arguments passed to yyerror: user formals plus yylocp.
+# Arguments passed to yyerror: user formals plus yylocp with leading comma.
 m4_define([b4_pure_formals],
 [b4_pure_if([b4_locations_if([, YYLTYPE *yylocp])])[]b4_user_formals])
 
 
+# b4_locuser_formals(LOC = yylocp)
+# --------------------------------
+m4_define([b4_locuser_formals],
+[b4_locations_if([, YYLTYPE *m4_default([$1], [yylocp])])[]b4_user_formals])
+
+
+# b4_locuser_args(LOC = yylocp)
+# -----------------------------
+m4_define([b4_locuser_args],
+[b4_locations_if([, m4_default([$1], [yylocp])])[]b4_user_args])
+
+
+
 ## ----------------- ##
 ## Semantic Values.  ##
 ## ----------------- ##
@@ -582,15 +596,14 @@ do {						\
 
 ]b4_yy_symbol_print_generate([b4_c_ansi_function_def])[
 
-# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			    \
-do {									    \
-  if (yydebug)								    \
-    {									    \
-      YYFPRINTF (stderr, "%s ", Title);					    \
-      yy_symbol_print (stderr, Type,					    \
-		       Value]b4_locations_if([, Location])[]b4_user_args[);  \
-      YYFPRINTF (stderr, "\n");						    \
-    }									    \
+# define YY_SYMBOL_PRINT(Title, Type, Value, Location)          \
+do {                                                            \
+  if (yydebug)                                                  \
+    {                                                           \
+      YYFPRINTF (stderr, "%s ", Title);                         \
+      yy_symbol_print (stderr, Type, Value]b4_locuser_args([Location])[);        \
+      YYFPRINTF (stderr, "\n");                                 \
+    }                                                           \
 } while (YYID (0))
 
 /* Nonzero means print parse trace.  It is left uninitialized so that
@@ -896,10 +909,8 @@ yyfill (yyGLRStackItem *yyvsp, int *yylow, int yylow1, yybool yynormal)
  *  yyerr for YYERROR, yyabort for YYABORT.  */
 /*ARGSUSED*/ static YYRESULTTAG
 yyuserAction (yyRuleNum yyn, int yyrhslen, yyGLRStackItem* yyvsp,
-	      YYSTYPE* yyvalp,
-	      YYLTYPE* YYOPTIONAL_LOC (yylocp),
-	      yyGLRStack* yystackp
-	      ]b4_user_formals[)
+	      yyGLRStack* yystackp,
+	      YYSTYPE* yyvalp]b4_locuser_formals[)
 {
   yybool yynormal __attribute__ ((__unused__)) =
     (yystackp->yysplitPoint == YY_NULL);
@@ -928,9 +939,9 @@ yyuserAction (yyRuleNum yyn, int yyrhslen, yyGLRStackItem* yyvsp,
   if (yyrhslen == 0)
     *yyvalp = yyval_default;
   else
-    *yyvalp = yyvsp[YYFILL (1-yyrhslen)].yystate.yysemantics.yysval;
+    *yyvalp = yyvsp[YYFILL (1-yyrhslen)].yystate.yysemantics.yysval;]b4_locations_if([[
   YYLLOC_DEFAULT ((*yylocp), (yyvsp - yyrhslen), yyrhslen);
-]b4_locations_if([[  yystackp->yyerror_range[1].yystate.yyloc = *yylocp;
+  yystackp->yyerror_range[1].yystate.yyloc = *yylocp;
 ]])[
   switch (yyn)
     {
@@ -978,7 +989,7 @@ yydestroyGLRState (char const *yymsg, yyGLRState *yys]b4_user_formals[)
 {
   if (yys->yyresolved)
     yydestruct (yymsg, yystos[yys->yylrState],
-		&yys->yysemantics.yysval]b4_locations_if([, &yys->yyloc])[]b4_user_args[);
+		&yys->yysemantics.yysval]b4_locuser_args([&yys->yyloc])[);
   else
     {
 #if YYDEBUG
@@ -989,7 +1000,7 @@ yydestroyGLRState (char const *yymsg, yyGLRState *yys]b4_user_formals[)
 	  else
 	    YYFPRINTF (stderr, "%s incomplete ", yymsg);
 	  yy_symbol_print (stderr, yystos[yys->yylrState],
-			   YY_NULL]b4_locations_if([, &yys->yyloc])[]b4_user_args[);
+			   YY_NULL]b4_locuser_args([&yys->yyloc])[);
 	  YYFPRINTF (stderr, "\n");
 	}
 #endif
@@ -1120,8 +1131,8 @@ yyaddDeferredAction (yyGLRStack* yystackp, size_t yyk, yyGLRState* yystate,
   if (yystackp->yytops.yylookaheadNeeds[yyk])
     {
       yynewOption->yyrawchar = yychar;
-      yynewOption->yyval = yylval;
-      yynewOption->yyloc = yylloc;
+      yynewOption->yyval = yylval;]b4_locations_if([
+      yynewOption->yyloc = yylloc;])[
     }
   else
     yynewOption->yyrawchar = YYEMPTY;
@@ -1326,7 +1337,7 @@ yyremoveDeletes (yyGLRStack* yystackp)
 static inline void
 yyglrShift (yyGLRStack* yystackp, size_t yyk, yyStateNum yylrState,
 	    size_t yyposn,
-	    YYSTYPE* yyvalp, YYLTYPE* yylocp)
+	    YYSTYPE* yyvalp]b4_locations_if([, YYLTYPE* yylocp])[)
 {
   yyGLRState* yynewState = &yynewGLRStackItem (yystackp, yytrue)->yystate;
 
@@ -1334,8 +1345,8 @@ yyglrShift (yyGLRStack* yystackp, size_t yyk, yyStateNum yylrState,
   yynewState->yyposn = yyposn;
   yynewState->yyresolved = yytrue;
   yynewState->yypred = yystackp->yytops.yystates[yyk];
-  yynewState->yysemantics.yysval = *yyvalp;
-  yynewState->yyloc = *yylocp;
+  yynewState->yysemantics.yysval = *yyvalp;]b4_locations_if([
+  yynewState->yyloc = *yylocp;])[
   yystackp->yytops.yystates[yyk] = yynewState;
 
   YY_RESERVE_GLRSTACK (yystackp);
@@ -1369,7 +1380,7 @@ yyglrShiftDefer (yyGLRStack* yystackp, size_t yyk, yyStateNum yylrState,
  *  for userAction.  */
 static inline YYRESULTTAG
 yydoAction (yyGLRStack* yystackp, size_t yyk, yyRuleNum yyrule,
-	    YYSTYPE* yyvalp, YYLTYPE* yylocp]b4_user_formals[)
+	    YYSTYPE* yyvalp]b4_locuser_formals[)
 {
   int yynrhs = yyrhsLength (yyrule);
 
@@ -1381,8 +1392,8 @@ yydoAction (yyGLRStack* yystackp, size_t yyk, yyRuleNum yyrule,
       yystackp->yynextFree -= yynrhs;
       yystackp->yyspaceLeft += yynrhs;
       yystackp->yytops.yystates[0] = & yystackp->yynextFree[-1].yystate;
-      return yyuserAction (yyrule, yynrhs, rhs,
-			   yyvalp, yylocp, yystackp]b4_user_args[);
+      return yyuserAction (yyrule, yynrhs, rhs, yystackp,
+			   yyvalp]b4_locuser_args[);
     }
   else
     {
@@ -1406,7 +1417,7 @@ yydoAction (yyGLRStack* yystackp, size_t yyk, yyRuleNum yyrule,
       yyupdateSplit (yystackp, yys);
       yystackp->yytops.yystates[yyk] = yys;
       return yyuserAction (yyrule, yynrhs, yyrhsVals + YYMAXRHS + YYMAXLEFT - 1,
-			   yyvalp, yylocp, yystackp]b4_user_args[);
+			   yystackp, yyvalp]b4_locuser_args[);
     }
 }
 
@@ -1425,7 +1436,7 @@ do {					\
 
 /*ARGSUSED*/ static inline void
 yy_reduce_print (yyGLRStack* yystackp, size_t yyk, yyRuleNum yyrule,
-		 YYSTYPE* yyvalp, YYLTYPE* yylocp]b4_user_formals[)
+		 YYSTYPE* yyvalp]b4_locuser_formals[)
 {
   int yynrhs = yyrhsLength (yyrule);
   yybool yynormal __attribute__ ((__unused__)) =
@@ -1433,8 +1444,8 @@ yy_reduce_print (yyGLRStack* yystackp, size_t yyk, yyRuleNum yyrule,
   yyGLRStackItem* yyvsp = (yyGLRStackItem*) yystackp->yytops.yystates[yyk];
   int yylow = 1;
   int yyi;
-  YYUSE (yyvalp);
-  YYUSE (yylocp);
+  YYUSE (yyvalp);]b4_locations_if([
+  YYUSE (yylocp);])[
 ]b4_parse_param_use[]dnl
 [  YYFPRINTF (stderr, "Reducing stack %lu by rule %d (line %lu):\n",
 	     (unsigned long int) yyk, yyrule - 1,
@@ -1471,17 +1482,16 @@ yyglrReduce (yyGLRStack* yystackp, size_t yyk, yyRuleNum yyrule,
 
   if (yyforceEval || yystackp->yysplitPoint == YY_NULL)
     {
-      YYSTYPE yysval;
-      YYLTYPE yyloc;
+      YYSTYPE yysval;]b4_locations_if([
+      YYLTYPE yyloc;])[
 
-      YY_REDUCE_PRINT ((yystackp, yyk, yyrule, &yysval, &yyloc]b4_user_args[));
-      YYCHK (yydoAction (yystackp, yyk, yyrule, &yysval,
-			 &yyloc]b4_user_args[));
+      YY_REDUCE_PRINT ((yystackp, yyk, yyrule, &yysval]b4_locuser_args([&yyloc])[));
+      YYCHK (yydoAction (yystackp, yyk, yyrule, &yysval]b4_locuser_args([&yyloc])[));
       YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyrule], &yysval, &yyloc);
       yyglrShift (yystackp, yyk,
 		  yyLRgotoState (yystackp->yytops.yystates[yyk]->yylrState,
 				 yylhsNonterm (yyrule)),
-		  yyposn, &yysval, &yyloc);
+		  yyposn, &yysval]b4_locations_if([, &yyloc])[);
     }
   else
     {
@@ -1699,13 +1709,13 @@ yyresolveStates (yyGLRState* yys, int yyn,
  *  semantic values if invoked).  */
 static YYRESULTTAG
 yyresolveAction (yySemanticOption* yyopt, yyGLRStack* yystackp,
-		 YYSTYPE* yyvalp, YYLTYPE* yylocp]b4_user_formals[)
+		 YYSTYPE* yyvalp]b4_locuser_formals[)
 {
   yyGLRStackItem yyrhsVals[YYMAXRHS + YYMAXLEFT + 1];
   int yynrhs;
   int yychar_current;
-  YYSTYPE yylval_current;
-  YYLTYPE yylloc_current;
+  YYSTYPE yylval_current;]b4_locations_if([
+  YYLTYPE yylloc_current;])[
   YYRESULTTAG yyflag;
 
   yynrhs = yyrhsLength (yyopt->yyrule);
@@ -1723,17 +1733,17 @@ yyresolveAction (yySemanticOption* yyopt, yyGLRStack* yystackp,
     /* Set default location.  */
     yyrhsVals[YYMAXRHS + YYMAXLEFT - 1].yystate.yyloc = yyopt->yystate->yyloc;]])[
   yychar_current = yychar;
-  yylval_current = yylval;
-  yylloc_current = yylloc;
+  yylval_current = yylval;]b4_locations_if([
+  yylloc_current = yylloc;])[
   yychar = yyopt->yyrawchar;
-  yylval = yyopt->yyval;
-  yylloc = yyopt->yyloc;
+  yylval = yyopt->yyval;]b4_locations_if([
+  yylloc = yyopt->yyloc;])[
   yyflag = yyuserAction (yyopt->yyrule, yynrhs,
-			   yyrhsVals + YYMAXRHS + YYMAXLEFT - 1,
-			   yyvalp, yylocp, yystackp]b4_user_args[);
+			 yyrhsVals + YYMAXRHS + YYMAXLEFT - 1,
+			 yystackp, yyvalp]b4_locuser_args[);
   yychar = yychar_current;
-  yylval = yylval_current;
-  yylloc = yylloc_current;
+  yylval = yylval_current;]b4_locations_if([
+  yylloc = yylloc_current;])[
   return yyflag;
 }
 
@@ -1873,15 +1883,13 @@ static YYRESULTTAG
 yyresolveValue (yyGLRState* yys, yyGLRStack* yystackp]b4_user_formals[)
 {
   yySemanticOption* yyoptionList = yys->yysemantics.yyfirstVal;
-  yySemanticOption* yybest;
+  yySemanticOption* yybest = yyoptionList;
   yySemanticOption** yypp;
-  yybool yymerge;
+  yybool yymerge = yyfalse;
   YYSTYPE yysval;
-  YYRESULTTAG yyflag;
-  YYLTYPE *yylocp = &yys->yyloc;
+  YYRESULTTAG yyflag;]b4_locations_if([
+  YYLTYPE *yylocp = &yys->yyloc;])[
 
-  yybest = yyoptionList;
-  yymerge = yyfalse;
   for (yypp = &yyoptionList->yynext; *yypp != YY_NULL; )
     {
       yySemanticOption* yyp = *yypp;
@@ -1922,22 +1930,20 @@ yyresolveValue (yyGLRState* yys, yyGLRStack* yystackp]b4_user_formals[)
     {
       yySemanticOption* yyp;
       int yyprec = yydprec[yybest->yyrule];
-      yyflag = yyresolveAction (yybest, yystackp, &yysval,
-				yylocp]b4_user_args[);
+      yyflag = yyresolveAction (yybest, yystackp, &yysval]b4_locuser_args[);
       if (yyflag == yyok)
 	for (yyp = yybest->yynext; yyp != YY_NULL; yyp = yyp->yynext)
 	  {
 	    if (yyprec == yydprec[yyp->yyrule])
 	      {
-		YYSTYPE yysval_other;
-		YYLTYPE yydummy;
-		yyflag = yyresolveAction (yyp, yystackp, &yysval_other,
-					  &yydummy]b4_user_args[);
+		YYSTYPE yysval_other;]b4_locations_if([
+                YYLTYPE yydummy;])[
+                yyflag = yyresolveAction (yyp, yystackp, &yysval_other]b4_locuser_args([&yydummy])[);
 		if (yyflag != yyok)
 		  {
 		    yydestruct ("Cleanup: discarding incompletely merged value for",
 				yystos[yys->yylrState],
-				&yysval]b4_locations_if([, yylocp])[]b4_user_args[);
+				&yysval]b4_locuser_args[);
 		    break;
 		  }
 		yyuserMerge (yymerger[yyp->yyrule], &yysval, &yysval_other);
@@ -1945,7 +1951,7 @@ yyresolveValue (yyGLRState* yys, yyGLRStack* yystackp]b4_user_formals[)
 	  }
     }
   else
-    yyflag = yyresolveAction (yybest, yystackp, &yysval, yylocp]b4_user_args[);
+    yyflag = yyresolveAction (yybest, yystackp, &yysval]b4_locuser_args([yylocp])[);
 
   if (yyflag == yyok)
     {
@@ -2243,7 +2249,7 @@ yyrecoverSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
 	    YYLLOC_DEFAULT ((yys->yyloc), yyerror_range, 2);]])[
 	    yytoken = YYTRANSLATE (yychar);
 	    yydestruct ("Error: discarding",
-			yytoken, &yylval]b4_locations_if([, &yylloc])[]b4_user_args[);
+			yytoken, &yylval]b4_locuser_args([&yylloc])[);
 	  }
 	YYDPRINTF ((stderr, "Reading a token: "));
 	yychar = YYLEX;
@@ -2293,19 +2299,20 @@ yyrecoverSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
 	  if (0 <= yyj && yyj <= YYLAST && yycheck[yyj] == YYTERROR
 	      && yyisShiftAction (yytable[yyj]))
 	    {
-	      /* Shift the error token having adjusted its location.  */
-	      YYLTYPE yyerrloc;]b4_locations_if([[
+	      /* Shift the error token.  */]b4_locations_if([[
+	      /* First adjust its location.*/
+              YYLTYPE yyerrloc;
 	      yystackp->yyerror_range[2].yystate.yyloc = yylloc;
 	      YYLLOC_DEFAULT (yyerrloc, (yystackp->yyerror_range), 2);]])[
 	      YY_SYMBOL_PRINT ("Shifting", yystos[yytable[yyj]],
 			       &yylval, &yyerrloc);
 	      yyglrShift (yystackp, 0, yytable[yyj],
-			  yys->yyposn, &yylval, &yyerrloc);
+			  yys->yyposn, &yylval]b4_locations_if([, &yyerrloc])[);
 	      yys = yystackp->yytops.yystates[0];
 	      break;
 	    }
-	}
-]b4_locations_if([[      yystackp->yyerror_range[1].yystate.yyloc = yys->yyloc;]])[
+	}]b4_locations_if([[
+      yystackp->yyerror_range[1].yystate.yyloc = yys->yyloc;]])[
       if (yys->yypred != YY_NULL)
 	yydestroyGLRState ("Error: popping", yys]b4_user_args[);
       yystackp->yytops.yystates[0] = yys->yypred;
@@ -2371,7 +2378,7 @@ m4_popdef([b4_at_dollar])])dnl
     case 2: goto yyexhaustedlab;
     default: goto yybuglab;
     }
-  yyglrShift (&yystack, 0, 0, 0, &yylval, &yylloc);
+  yyglrShift (&yystack, 0, 0, 0, &yylval]b4_locations_if([, &yylloc])[);
   yyposn = 0;
 
   while (YYID (yytrue))
@@ -2429,7 +2436,7 @@ m4_popdef([b4_at_dollar])])dnl
 		  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
 		  yychar = YYEMPTY;
 		  yyposn += 1;
-		  yyglrShift (&yystack, 0, yyaction, yyposn, &yylval, &yylloc);
+		  yyglrShift (&yystack, 0, yyaction, yyposn, &yylval]b4_locations_if([, &yylloc])[);
 		  if (0 < yystack.yyerrState)
 		    yystack.yyerrState -= 1;
 		}
@@ -2505,7 +2512,7 @@ m4_popdef([b4_at_dollar])])dnl
 	      YYDPRINTF ((stderr, "On stack %lu, ", (unsigned long int) yys));
 	      YY_SYMBOL_PRINT ("shifting", yytoken_to_shift, &yylval, &yylloc);
 	      yyglrShift (&yystack, yys, yyaction, yyposn,
-			  &yylval, &yylloc);
+			  &yylval]b4_locations_if([, &yylloc])[);
 	      YYDPRINTF ((stderr, "Stack %lu now in state #%d\n",
 			  (unsigned long int) yys,
 			  yystack.yytops.yystates[yys]->yylrState));
@@ -2545,8 +2552,7 @@ m4_popdef([b4_at_dollar])])dnl
  yyreturn:
   if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
-		YYTRANSLATE (yychar),
-		&yylval]b4_locations_if([, &yylloc])[]b4_user_args[);
+		YYTRANSLATE (yychar), &yylval]b4_locuser_args([&yylloc])[);
 
   /* If the stack is well-formed, pop the stack until it is empty,
      destroying its entries as we go.  But free the stack regardless
