@@ -124,7 +124,7 @@ m4_define([b4_rhs_data],
 # --------------------------------------------------
 # Expansion of $$ or $<TYPE>$, for symbol SYMBOL-NUM.
 m4_define([b4_rhs_value],
-[b4_symbol_value([b4_rhs_data([$1], [$2]).yysemantics.yysval], [$3], [$4])])
+[b4_symbol_value([b4_rhs_data([$1], [$2]).yysemantics.yyval], [$3], [$4])])
 
 
 
@@ -502,7 +502,7 @@ struct yyGLRState
 {
   /** Type tag: always true.  */
   yybool yyisState;
-  /** Type tag for yysemantics.  If true, yysval applies, otherwise
+  /** Type tag for yysemantics.  If true, yyval applies, otherwise
    *  yyfirstVal applies.  */
   yybool yyresolved;
   /** Number of corresponding LALR(1) machine state.  */
@@ -517,7 +517,7 @@ struct yyGLRState
      *  yynext.  */
     yySemanticOption* yyfirstVal;
     /** Semantic value for this state.  */
-    YYSTYPE yysval;
+    YYSTYPE yyval;
   } yysemantics;]b4_locations_if([[
   /** Source location for this state.  */
   YYLTYPE yyloc;]])[
@@ -796,9 +796,9 @@ yyfillin (yyGLRStackItem *yyvsp, int yylow0, int yylow1)
 #endif
       yyvsp[i].yystate.yyresolved = s->yyresolved;
       if (s->yyresolved)
-        yyvsp[i].yystate.yysemantics.yysval = s->yysemantics.yysval;
+        yyvsp[i].yystate.yysemantics.yyval = s->yysemantics.yyval;
       else
-        /* The effect of using yysval or yyloc (in an immediate rule) is
+        /* The effect of using yyval or yyloc (in an immediate rule) is
          * undefined.  */
         yyvsp[i].yystate.yysemantics.yyfirstVal = YY_NULLPTR;]b4_locations_if([[
       yyvsp[i].yystate.yyloc = s->yyloc;]])[
@@ -904,7 +904,7 @@ yyuserAction (yyRuleNum yyn, int yyrhslen, yyGLRStackItem* yyvsp,
   if (yyrhslen == 0)
     *yyvalp = yyval_default;
   else
-    *yyvalp = yyvsp[YYFILL (1-yyrhslen)].yystate.yysemantics.yysval;]b4_locations_if([[
+    *yyvalp = yyvsp[YYFILL (1-yyrhslen)].yystate.yysemantics.yyval;]b4_locations_if([[
   /* Default location. */
   YYLLOC_DEFAULT ((*yylocp), (yyvsp - yyrhslen), yyrhslen);
   yystackp->yyerror_range[1].yystate.yyloc = *yylocp;
@@ -970,7 +970,7 @@ yydestroyGLRState (char const *yymsg, yyGLRState *yys]b4_user_formals[)
 {
   if (yys->yyresolved)
     yydestruct (yymsg, yy_accessing_symbol (yys->yylrState),
-                &yys->yysemantics.yysval]b4_locuser_args([&yys->yyloc])[);
+                &yys->yysemantics.yyval]b4_locuser_args([&yys->yyloc])[);
   else
     {
 #if ]b4_api_PREFIX[DEBUG
@@ -1345,7 +1345,7 @@ yyglrShift (yyGLRStack* yystackp, YYPTRDIFF_T yyk, yy_state_t yylrState,
   yynewState->yyposn = yyposn;
   yynewState->yyresolved = yytrue;
   yynewState->yypred = yystackp->yytops.yystates[yyk];
-  yynewState->yysemantics.yysval = *yyvalp;]b4_locations_if([
+  yynewState->yysemantics.yyval = *yyvalp;]b4_locations_if([
   yynewState->yyloc = *yylocp;])[
   yystackp->yytops.yystates[yyk] = yynewState;
 
@@ -1403,7 +1403,7 @@ yy_reduce_print (yybool yynormal, yyGLRStackItem* yyvsp, YYPTRDIFF_T yyk,
       YY_FPRINTF ((stderr, "   $%d = ", yyi + 1));
       yy_symbol_print (stderr,
                        yy_accessing_symbol (yyvsp[yyi - yynrhs + 1].yystate.yylrState),
-                       &yyvsp[yyi - yynrhs + 1].yystate.yysemantics.yysval]b4_locations_if([,
+                       &yyvsp[yyi - yynrhs + 1].yystate.yysemantics.yyval]b4_locations_if([,
                        &]b4_rhs_location(yynrhs, yyi + 1))[]dnl
                        b4_user_args[);
       if (!yyvsp[yyi - yynrhs + 1].yystate.yyresolved)
@@ -1479,21 +1479,21 @@ yyglrReduce (yyGLRStack* yystackp, YYPTRDIFF_T yyk, yyRuleNum yyrule,
 
   if (yyforceEval || yystackp->yysplitPoint == YY_NULLPTR)
     {
-      YYSTYPE yysval;]b4_locations_if([[
+      YYSTYPE yyval;]b4_locations_if([[
       YYLTYPE yyloc;]])[
 
-      YYRESULTTAG yyflag = yydoAction (yystackp, yyk, yyrule, &yysval]b4_locuser_args([&yyloc])[);
+      YYRESULTTAG yyflag = yydoAction (yystackp, yyk, yyrule, &yyval]b4_locuser_args([&yyloc])[);
       if (yyflag == yyerr && yystackp->yysplitPoint != YY_NULLPTR)
         YY_DPRINTF ((stderr,
                      "Parse on stack %ld rejected by rule %d (line %d).\n",
                      YY_CAST (long, yyk), yyrule - 1, yyrline[yyrule]));
       if (yyflag != yyok)
         return yyflag;
-      YY_SYMBOL_PRINT ("-> $$ =", yylhsNonterm (yyrule), &yysval, &yyloc);
+      YY_SYMBOL_PRINT ("-> $$ =", yylhsNonterm (yyrule), &yyval, &yyloc);
       yyglrShift (yystackp, yyk,
                   yyLRgotoState (yystackp->yytops.yystates[yyk]->yylrState,
                                  yylhsNonterm (yyrule)),
-                  yyposn, &yysval]b4_locations_if([, &yyloc])[);
+                  yyposn, &yyval]b4_locations_if([, &yyloc])[);
     }
   else
     {
@@ -1624,12 +1624,12 @@ yymergeOptionSets (yySemanticOption* yyy0, yySemanticOption* yyy1)
       else if (yys0->yyresolved)
         {
           yys1->yyresolved = yytrue;
-          yys1->yysemantics.yysval = yys0->yysemantics.yysval;
+          yys1->yysemantics.yyval = yys0->yysemantics.yyval;
         }
       else if (yys1->yyresolved)
         {
           yys0->yyresolved = yytrue;
-          yys0->yysemantics.yysval = yys1->yysemantics.yysval;
+          yys0->yysemantics.yyval = yys1->yysemantics.yyval;
         }
       else
         {
@@ -1875,7 +1875,7 @@ yyresolveValue (yyGLRState* yys, yyGLRStack* yystackp]b4_user_formals[)
   yySemanticOption* yybest = yyoptionList;
   yySemanticOption** yypp;
   yybool yymerge = yyfalse;
-  YYSTYPE yysval;
+  YYSTYPE yyval;
   YYRESULTTAG yyflag;]b4_locations_if([
   YYLTYPE *yylocp = &yys->yyloc;])[
 
@@ -1919,33 +1919,33 @@ yyresolveValue (yyGLRState* yys, yyGLRStack* yystackp]b4_user_formals[)
     {
       yySemanticOption* yyp;
       int yyprec = yydprec[yybest->yyrule];
-      yyflag = yyresolveAction (yybest, yystackp, &yysval]b4_locuser_args[);
+      yyflag = yyresolveAction (yybest, yystackp, &yyval]b4_locuser_args[);
       if (yyflag == yyok)
         for (yyp = yybest->yynext; yyp != YY_NULLPTR; yyp = yyp->yynext)
           {
             if (yyprec == yydprec[yyp->yyrule])
               {
-                YYSTYPE yysval_other;]b4_locations_if([
+                YYSTYPE yyval_other;]b4_locations_if([
                 YYLTYPE yydummy;])[
-                yyflag = yyresolveAction (yyp, yystackp, &yysval_other]b4_locuser_args([&yydummy])[);
+                yyflag = yyresolveAction (yyp, yystackp, &yyval_other]b4_locuser_args([&yydummy])[);
                 if (yyflag != yyok)
                   {
                     yydestruct ("Cleanup: discarding incompletely merged value for",
                                 yy_accessing_symbol (yys->yylrState),
-                                &yysval]b4_locuser_args[);
+                                &yyval]b4_locuser_args[);
                     break;
                   }
-                yyuserMerge (yymerger[yyp->yyrule], &yysval, &yysval_other);
+                yyuserMerge (yymerger[yyp->yyrule], &yyval, &yyval_other);
               }
           }
     }
   else
-    yyflag = yyresolveAction (yybest, yystackp, &yysval]b4_locuser_args([yylocp])[);
+    yyflag = yyresolveAction (yybest, yystackp, &yyval]b4_locuser_args([yylocp])[);
 
   if (yyflag == yyok)
     {
       yys->yyresolved = yytrue;
-      yys->yysemantics.yysval = yysval;
+      yys->yysemantics.yyval = yyval;
     }
   else
     yys->yysemantics.yyfirstVal = YY_NULLPTR;
