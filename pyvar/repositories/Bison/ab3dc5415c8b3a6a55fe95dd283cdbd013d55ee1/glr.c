@@ -293,6 +293,7 @@ static YYLTYPE yyloc_default][]b4_yyloc_default;])[
 # define yytrue true
 # define yyfalse false
 #else
+  /* When we move to stdbool, get rid of the various casts to yybool.  */
   typedef unsigned char yybool;
 # define yytrue 1
 # define yyfalse 0
@@ -783,7 +784,7 @@ yyuserAction (yyRuleNum yyn, int yyrhslen, yyGLRStackItem* yyvsp,
               yyGLRStack* yystackp,
               YYSTYPE* yyvalp]b4_locuser_formals[)
 {
-  yybool yynormal YY_ATTRIBUTE_UNUSED = (yystackp->yysplitPoint == YY_NULLPTR);
+  yybool yynormal YY_ATTRIBUTE_UNUSED = (yybool) (yystackp->yysplitPoint == YY_NULLPTR);
   int yylow;
 ]b4_parse_param_use([yyvalp], [yylocp])dnl
 [  YYUSE (yyrhslen);
@@ -903,7 +904,7 @@ yylhsNonterm (yyRuleNum yyrule)
 static inline yybool
 yyisDefaultedState (yyStateNum yystate)
 {
-  return yypact_value_is_default (yypact[yystate]);
+  return (yybool) yypact_value_is_default (yypact[yystate]);
 }
 
 /** The default reduction for YYSTATE, assuming it has one.  */
@@ -929,7 +930,7 @@ yygetLRActions (yyStateNum yystate, int yytoken,
                 int* yyaction, const short** yyconflicts)
 {
   int yyindex = yypact[yystate] + yytoken;
-  if (yypact_value_is_default (yypact[yystate])
+  if (yyisDefaultedState (yystate)
       || yyindex < 0 || YYLAST < yyindex || yycheck[yyindex] != yytoken)
     {
       *yyaction = -yydefact[yystate];
@@ -964,13 +965,13 @@ yyLRgotoState (yyStateNum yystate, yySymbol yysym)
 static inline yybool
 yyisShiftAction (int yyaction)
 {
-  return 0 < yyaction;
+  return (yybool) (0 < yyaction);
 }
 
 static inline yybool
 yyisErrorAction (int yyaction)
 {
-  return yyaction == 0;
+  return (yybool) (yyaction == 0);
 }
 
                                 /* GLRStates */
@@ -2354,7 +2355,7 @@ b4_dollar_popdef])[]dnl
           size_t yys;
 
           for (yys = 0; yys < yystack.yytops.yysize; yys += 1)
-            yystackp->yytops.yylookaheadNeeds[yys] = yychar != YYEMPTY;
+            yystackp->yytops.yylookaheadNeeds[yys] = (yybool) (yychar != YYEMPTY);
 
           /* yyprocessOneStack returns one of three things:
 
