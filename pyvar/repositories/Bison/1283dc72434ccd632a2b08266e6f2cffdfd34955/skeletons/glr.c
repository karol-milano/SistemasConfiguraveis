@@ -900,14 +900,15 @@ yyfill (yyGLRStackItem *yyvsp, int *yylow, int yylow1, yybool yynormal)
  *  (@@$).  Returns yyok for normal return, yyaccept for YYACCEPT,
  *  yyerr for YYERROR, yyabort for YYABORT.  */
 static YYRESULTTAG
-yyuserAction (yyRuleNum yyn, int yyrhslen, yyGLRStackItem* yyvsp,
-              yyGLRStack* yystackp,
+yyuserAction (yyRuleNum yyrule, int yyrhslen, yyGLRStackItem* yyvsp,
+              yyGLRStack* yystackp, YYPTRDIFF_T yyk,
               YYSTYPE* yyvalp]b4_locuser_formals[)
 {
-  yybool yynormal YY_ATTRIBUTE_UNUSED = yystackp->yysplitPoint == YY_NULLPTR;
+  const yybool yynormal YY_ATTRIBUTE_UNUSED = yystackp->yysplitPoint == YY_NULLPTR;
   int yylow = 1;
 ]b4_parse_param_use([yyvalp], [yylocp])dnl
-[  YYUSE (yyrhslen);
+[  YYUSE (yyk);
+  YYUSE (yyrhslen);
 # undef yyerrok
 # define yyerrok (yystackp->yyerrState = 0)
 # undef YYACCEPT
@@ -933,14 +934,17 @@ yyuserAction (yyRuleNum yyn, int yyrhslen, yyGLRStackItem* yyvsp,
     *yyvalp = yyvsp[YYFILL (1-yyrhslen)].yystate.yysemantics.yyval;]b4_locations_if([[
   /* Default location. */
   YYLLOC_DEFAULT ((*yylocp), (yyvsp - yyrhslen), yyrhslen);
-  yystackp->yyerror_range[1].yystate.yyloc = *yylocp;
-]])[]b4_glr_cc_if([[
+  yystackp->yyerror_range[1].yystate.yyloc = *yylocp;]])[
+  /* If yyk == -1, we are running a deferred action on a temporary
+     stack.  In that case, YY_REDUCE_PRINT must not play with YYFILL,
+     so pretend the stack is "normal". */
+  YY_REDUCE_PRINT ((yynormal || yyk == -1, yyvsp, yyk, yyrule]b4_user_args[));]b4_glr_cc_if([[
 #if YY_EXCEPTIONS
   typedef ]b4_namespace_ref[::]b4_parser_class[::syntax_error syntax_error;
   try
   {
 #endif // YY_EXCEPTIONS]])[
-  switch (yyn)
+  switch (yyrule)
     {
 ]b4_user_actions[
       default: break;
@@ -955,6 +959,7 @@ yyuserAction (yyRuleNum yyn, int yyrhslen, yyGLRStackItem* yyvsp,
       YYERROR;
     }
 #endif // YY_EXCEPTIONS]])[
+  YY_SYMBOL_PRINT ("-> $$ =", yylhsNonterm (yyrule), yyvalp, yylocp);
 
   return yyok;
 # undef yyerrok
@@ -1446,8 +1451,7 @@ yydoAction (yyGLRStack* yystackp, YYPTRDIFF_T yyk, yyRuleNum yyrule,
       yystackp->yynextFree -= yynrhs;
       yystackp->yyspaceLeft += yynrhs;
       yystackp->yytops.yystates[0] = & yystackp->yynextFree[-1].yystate;
-      YY_REDUCE_PRINT ((yytrue, yyrhs, yyk, yyrule]b4_user_args[));
-      return yyuserAction (yyrule, yynrhs, yyrhs, yystackp,
+      return yyuserAction (yyrule, yynrhs, yyrhs, yystackp, yyk,
                            yyvalp]b4_locuser_args[);
     }
   else
@@ -1466,9 +1470,8 @@ yydoAction (yyGLRStack* yystackp, YYPTRDIFF_T yyk, yyRuleNum yyrule,
         }
       yyupdateSplit (yystackp, yys);
       yystackp->yytops.yystates[yyk] = yys;
-      YY_REDUCE_PRINT ((yyfalse, yyrhsVals + YYMAXRHS + YYMAXLEFT - 1, yyk, yyrule]b4_user_args[));
       return yyuserAction (yyrule, yynrhs, yyrhsVals + YYMAXRHS + YYMAXLEFT - 1,
-                           yystackp, yyvalp]b4_locuser_args[);
+                           yystackp, yyk, yyvalp]b4_locuser_args[);
     }
 }
 
@@ -1501,7 +1504,6 @@ yyglrReduce (yyGLRStack* yystackp, YYPTRDIFF_T yyk, yyRuleNum yyrule,
                      YY_CAST (long, yyk), yyrule - 1, yyrline[yyrule]));
       if (yyflag != yyok)
         return yyflag;
-      YY_SYMBOL_PRINT ("-> $$ =", yylhsNonterm (yyrule), &yyval, &yyloc);
       yyglrShift (yystackp, yyk,
                   yyLRgotoState (yystackp->yytops.yystates[yyk]->yylrState,
                                  yylhsNonterm (yyrule)),
@@ -1752,7 +1754,7 @@ yyresolveAction (yySemanticOption* yyopt, yyGLRStack* yystackp,
     yylloc = yyopt->yyloc;])[
     yyflag = yyuserAction (yyopt->yyrule, yynrhs,
                            yyrhsVals + YYMAXRHS + YYMAXLEFT - 1,
-                           yystackp, yyvalp]b4_locuser_args[);
+                           yystackp, -1, yyvalp]b4_locuser_args[);
     yychar = yychar_current;
     yylval = yylval_current;]b4_locations_if([
     yylloc = yylloc_current;])[
