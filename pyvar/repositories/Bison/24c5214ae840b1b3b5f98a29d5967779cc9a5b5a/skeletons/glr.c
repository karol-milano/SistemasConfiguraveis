@@ -846,8 +846,7 @@ yyuserAction (yyRuleNum yyn, int yyrhslen, yyGLRStackItem* yyvsp,
               yyGLRStack* yystackp,
               YYSTYPE* yyvalp]b4_locuser_formals[)
 {
-  yybool yynormal YY_ATTRIBUTE_UNUSED
-    = YY_CAST (yybool, yystackp->yysplitPoint == YY_NULLPTR);
+  yybool yynormal YY_ATTRIBUTE_UNUSED = yystackp->yysplitPoint == YY_NULLPTR;
   int yylow;
 ]b4_parse_param_use([yyvalp], [yylocp])dnl
 [  YYUSE (yyrhslen);
@@ -982,7 +981,7 @@ yylhsNonterm (yyRuleNum yyrule)
 static inline yybool
 yyisDefaultedState (yyStateNum yystate)
 {
-  return YY_CAST (yybool, yypact_value_is_default (yypact[yystate]));
+  return yypact_value_is_default (yypact[yystate]);
 }
 
 /** The default reduction for YYSTATE, assuming it has one.  */
@@ -1042,13 +1041,13 @@ yyLRgotoState (yyStateNum yystate, yySymbol yysym)
 static inline yybool
 yyisShiftAction (int yyaction)
 {
-  return YY_CAST (yybool, 0 < yyaction);
+  return 0 < yyaction;
 }
 
 static inline yybool
 yyisErrorAction (int yyaction)
 {
-  return YY_CAST (yybool, yyaction == 0);
+  return yyaction == 0;
 }
 
                                 /* GLRStates */
@@ -2406,7 +2405,7 @@ b4_dollar_popdef])[]dnl
           ptrdiff_t yys;
 
           for (yys = 0; yys < yystack.yytops.yysize; yys += 1)
-            yystackp->yytops.yylookaheadNeeds[yys] = YY_CAST (yybool, yychar != YYEMPTY);
+            yystackp->yytops.yylookaheadNeeds[yys] = yychar != YYEMPTY;
 
           /* yyprocessOneStack returns one of three things:
 
