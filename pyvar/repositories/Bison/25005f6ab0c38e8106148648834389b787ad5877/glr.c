@@ -192,10 +192,12 @@ b4_syncline([@oline@], [@ofile@])],
 #if ! defined (YYLTYPE) && ! defined (YYLTYPE_IS_DECLARED)
 typedef struct YYLTYPE
 {
+]b4_location_if([
   int first_line;
   int first_column;
   int last_line;
   int last_column;
+])[
 } YYLTYPE;
 # define YYLTYPE_IS_DECLARED 1
 # define YYLTYPE_IS_TRIVIAL 1
@@ -254,6 +256,9 @@ b4_syncline([@oline@], [@ofile@])
 #define YYNSTATES  ]b4_states_number[
 /* YYMAXRHS -- Maximum number of symbols on right-hand side of rule. */
 #define YYMAXRHS ]b4_r2_max[
+/* YYMAXLEFT -- Maximum number of symbols to the left of a handle
+   accessed by $0, $-1, etc., in any rule. */
+#define YYMAXLEFT ]b4_max_left_semantic_context[
 
 /* YYTRANSLATE(X) -- Bison symbol number corresponding to X.  */
 #define YYUNDEFTOK  ]b4_undef_token_number[
@@ -402,15 +407,22 @@ static const ]b4_int_type_for([b4_stos])[ yystos[] =
 /* YYLLOC_DEFAULT -- Compute the default location (before the actions
    are run).  */
 
-#define YYRHSLOC(yyRhs,YYK) (yyRhs[YYK].yystate.yyloc)
+]b4_location_if([[
+#define YYRHSLOC(yyRhs,YYK) ((yyRhs)[YYK].yystate.yyloc)
 
 #ifndef YYLLOC_DEFAULT
 # define YYLLOC_DEFAULT(yyCurrent, yyRhs, YYN)			\
-  yyCurrent.first_line   = YYRHSLOC(yyRhs,1).first_line;	\
-  yyCurrent.first_column = YYRHSLOC(yyRhs,1).first_column;	\
-  yyCurrent.last_line    = YYRHSLOC(yyRhs,YYN).last_line;	\
-  yyCurrent.last_column  = YYRHSLOC(yyRhs,YYN).last_column;
+  (yyCurrent).first_line   = YYRHSLOC(yyRhs,1).first_line;	\
+  (yyCurrent).first_column = YYRHSLOC(yyRhs,1).first_column;	\
+  (yyCurrent).last_line    = YYRHSLOC(yyRhs,YYN).last_line;	\
+  (yyCurrent).last_column  = YYRHSLOC(yyRhs,YYN).last_column;
+#endif
+]],[
+#ifndef YYLLOC_DEFAULT
+# define YYLLOC_DEFAULT(yyCurrent, yyRhs, YYN) 
 #endif
+])[
+
 
 /* YYLEX -- calling `yylex' with the right arguments.  */
 #define YYLEX ]b4_c_function_call([yylex], [int], b4_lex_param)[
@@ -663,16 +675,6 @@ yyuserAction (yyRuleNum yyn, int yyrhslen, yyGLRStackItem* yyvsp,
   yybool yynormal ATTRIBUTE_UNUSED = (yystack->yysplitPoint == NULL);
   int yylow;
 
-  if (yyrhslen == 0)
-    {
-      *yyvalp = yyval_default;
-      *yylocp = yyloc_default;
-    }
-  else
-    {
-      *yyvalp = yyvsp[1-yyrhslen].yystate.yysemantics.yysval;
-      *yylocp = yyvsp[1-yyrhslen].yystate.yyloc;
-    }
 # undef yyerrok
 # define yyerrok (yystack->yyerrState = 0)
 # undef YYACCEPT
@@ -680,7 +682,7 @@ yyuserAction (yyRuleNum yyn, int yyrhslen, yyGLRStackItem* yyvsp,
 # undef YYABORT
 # define YYABORT return yyabort
 # undef YYERROR
-# define YYERROR return yyerr
+# define YYERROR do { yystack->yyerrState = 0; return yyerr; } while (0)
 # undef YYRECOVERING
 # define YYRECOVERING (yystack->yyerrState != 0)
 # undef yyclearin
@@ -694,14 +696,25 @@ yyuserAction (yyRuleNum yyn, int yyrhslen, yyGLRStackItem* yyvsp,
     YYERROR;								     \
   } while (0)
 
+  yylow = 1;
+  if (yyrhslen == 0)
+    {
+      *yyvalp = yyval_default;
+      *yylocp = yyloc_default;
+    }
+  else
+    {
+      *yyvalp = yyvsp[YYFILL (1-yyrhslen)].yystate.yysemantics.yysval;
+      YYLLOC_DEFAULT (*yylocp, yyvsp - yyrhslen, yyrhslen);
+    }
+
 ]
-   yylow = 1;
-   switch (yyn)
-     {
-       b4_actions
-     }
+  switch (yyn)
+    {
+      b4_actions
+    }
 
-   return yyok;
+  return yyok;
 # undef yyerrok
 # undef YYABORT
 # undef YYACCEPT
@@ -1080,16 +1093,6 @@ yydoAction (yyGLRStack* yystack, int yyk, yyRuleNum yyrule,
       yystack->yynextFree -= yynrhs;
       yystack->yyspaceLeft += yynrhs;
       yystack->yytops.yystates[0] = & yystack->yynextFree[-1].yystate;
-      if (yynrhs == 0)
-	{
-	  *yyvalp = yyval_default;
-	  *yylocp = yyloc_default;
-	}
-      else
-	{
-	  *yyvalp = rhs[1-yynrhs].yystate.yysemantics.yysval;
-	  *yylocp = rhs[1-yynrhs].yystate.yyloc;
-	}
       return yyuserAction (yyrule, yynrhs, rhs,
 			   yyvalp, yylocp, yystack]b4_user_args[);
     }
@@ -1097,8 +1100,9 @@ yydoAction (yyGLRStack* yystack, int yyk, yyRuleNum yyrule,
     {
       int yyi;
       yyGLRState* yys;
-      yyGLRStackItem yyrhsVals[YYMAXRHS+1];
-      yys = yyrhsVals[YYMAXRHS].yystate.yypred = yystack->yytops.yystates[yyk];
+      yyGLRStackItem yyrhsVals[YYMAXRHS + YYMAXLEFT + 1];
+      yys = yyrhsVals[YYMAXRHS + YYMAXLEFT].yystate.yypred 
+	= yystack->yytops.yystates[yyk];
       for (yyi = 0; yyi < yynrhs; yyi += 1)
 	{
 	  yys = yys->yypred;
@@ -1107,17 +1111,7 @@ yydoAction (yyGLRStack* yystack, int yyk, yyRuleNum yyrule,
 	}
       yyupdateSplit (yystack, yys);
       yystack->yytops.yystates[yyk] = yys;
-      if (yynrhs == 0)
-	{
-	  *yyvalp = yyval_default;
-	  *yylocp = yyloc_default;
-	}
-      else
-	{
-	  *yyvalp = yyrhsVals[1].yystate.yysemantics.yysval;
-	  *yylocp = yyrhsVals[1].yystate.yyloc;
-	}
-      return yyuserAction (yyrule, yynrhs, yyrhsVals + YYMAXRHS - 1,
+      return yyuserAction (yyrule, yynrhs, yyrhsVals + YYMAXRHS + YYMAXLEFT - 1,
 			   yyvalp, yylocp, yystack]b4_user_args[);
     }
 }
@@ -1348,13 +1342,14 @@ static YYRESULTTAG
 yyresolveAction (yySemanticOption* yyopt, yyGLRStack* yystack,
 	         YYSTYPE* yyvalp, YYLTYPE* yylocp]b4_user_formals[)
 {
-  yyGLRStackItem yyrhsVals[YYMAXRHS+1];
+  yyGLRStackItem yyrhsVals[YYMAXRHS + YYMAXLEFT + 1];
   int yynrhs;
 
   yynrhs = yyrhsLength (yyopt->yyrule);
   YYCHK (yyresolveStates (yyopt->yystate, yynrhs, yystack]b4_user_args[));
-  yyrhsVals[YYMAXRHS].yystate.yypred = yyopt->yystate;
-  return yyuserAction (yyopt->yyrule, yynrhs, yyrhsVals + YYMAXRHS - 1,
+  yyrhsVals[YYMAXRHS + YYMAXLEFT].yystate.yypred = yyopt->yystate;
+  return yyuserAction (yyopt->yyrule, yynrhs, 
+		       yyrhsVals + YYMAXRHS + YYMAXLEFT - 1,
 		       yyvalp, yylocp, yystack]b4_user_args[);
 }
 
@@ -1687,17 +1682,14 @@ yyrecoverSyntaxError (yyGLRStack* yystack,
   size_t yyk;
   int yyj;
 
-  if (yystack->yyerrState == 0)
-    yystack->yyerrState = 3;
-  else if (yystack->yyerrState == 3)
+  if (yystack->yyerrState == 3)
     /* We just shifted the error token and (perhaps) took some
        reductions.  Skip tokens until we can proceed.  */
     while (yytrue)
       {
 	if (*yytokenp == YYEOF)
 	  {
-	    /* Now pop stack until we find a state that shifts the
-	       error token.  */
+	    /* Now pop stack until empty and fail. */
 	    while (yystack->yytops.yystates[0] != NULL)
 	      {
 		yyGLRState *yys = yystack->yytops.yystates[0];
@@ -1723,8 +1715,7 @@ yyrecoverSyntaxError (yyGLRStack* yystack,
 	YYDSYMPRINTF ("Next token is", *yytokenp, yylvalp, yyllocp);
 	yyj = yypact[yystack->yytops.yystates[0]->yylrState];
 	if (yyis_pact_ninf (yyj))
-	  /* Something's not right; we shouldn't be here.  */
-	  yyFail (yystack][]b4_lpure_args[, NULL);
+	  return;
 	yyj += *yytokenp;
 	if (yyj < 0 || YYLAST < yyj || yycheck[yyj] != *yytokenp)
 	  {
@@ -1747,6 +1738,7 @@ yyrecoverSyntaxError (yyGLRStack* yystack,
   yycompressStack (yystack);
 
   /* Now pop stack until we find a state that shifts the error token. */
+  yystack->yyerrState = 3;
   while (yystack->yytops.yystates[0] != NULL)
     {
       yyGLRState *yys = yystack->yytops.yystates[0];
@@ -2016,20 +2008,21 @@ b4_syncline([@oline@], [@ofile@])],
 b4_pure_if([],
 [extern YYSTYPE b4_prefix[]lval;])
 
-b4_location_if(
-[#if ! defined (YYLTYPE) && ! defined (YYLTYPE_IS_DECLARED)
+#if ! defined (YYLTYPE) && ! defined (YYLTYPE_IS_DECLARED)
 typedef struct YYLTYPE
 {
+b4_location_if([
   int first_line;
   int first_column;
   int last_line;
   int last_column;
+])
 } YYLTYPE;
 # define YYLTYPE_IS_DECLARED 1
 # define YYLTYPE_IS_TRIVIAL 1
 #endif
 
-m4_if(b4_pure, [0],
+b4_location_if([m4_if(b4_pure, [0],
 [extern YYLTYPE b4_prefix[]lloc;])
 ])
 ])
