@@ -600,7 +600,7 @@ yytnamerr (char *yyres, const char *yystr)
   if (! yyres)
     return strlen (yystr);
 
-  return yystpcpy (yyres, yystr) - yyres;
+  return (size_t) (yystpcpy (yyres, yystr) - yyres);
 }
 # endif
 
@@ -779,7 +779,7 @@ yyfill (yyGLRStackItem *yyvsp, int *yylow, int yylow1, yybool yynormal)
  *  (@@$).  Returns yyok for normal return, yyaccept for YYACCEPT,
  *  yyerr for YYERROR, yyabort for YYABORT.  */
 static YYRESULTTAG
-yyuserAction (yyRuleNum yyn, size_t yyrhslen, yyGLRStackItem* yyvsp,
+yyuserAction (yyRuleNum yyn, int yyrhslen, yyGLRStackItem* yyvsp,
               yyGLRStack* yystackp,
               YYSTYPE* yyvalp]b4_locuser_formals[)
 {
@@ -800,7 +800,7 @@ yyuserAction (yyRuleNum yyn, size_t yyrhslen, yyGLRStackItem* yyvsp,
 # undef yyclearin
 # define yyclearin (yychar = YYEMPTY)
 # undef YYFILL
-# define YYFILL(N) yyfill (yyvsp, &yylow, N, yynormal)
+# define YYFILL(N) yyfill (yyvsp, &yylow, (N), yynormal)
 # undef YYBACKUP
 # define YYBACKUP(Token, Value)                                              \
   return yyerror (]b4_yyerror_args[YY_("syntax error: cannot back up")),     \
@@ -1080,7 +1080,7 @@ yyexpandGLRStack (yyGLRStack* yystackp)
   yyGLRStackItem* yyp0, *yyp1;
   size_t yynewSize;
   size_t yyn;
-  size_t yysize = yystackp->yynextFree - yystackp->yyitems;
+  size_t yysize = (size_t) (yystackp->yynextFree - yystackp->yyitems);
   if (YYMAXDEPTH - YYHEADROOM < yysize)
     yyMemoryExhausted (yystackp);
   yynewSize = 2*yysize;
@@ -1263,7 +1263,7 @@ do {                                    \
 `----------------------------------------------------------------------*/
 
 static inline void
-yy_reduce_print (int yynormal, yyGLRStackItem* yyvsp, size_t yyk,
+yy_reduce_print (yybool yynormal, yyGLRStackItem* yyvsp, size_t yyk,
                  yyRuleNum yyrule]b4_user_formals[)
 {
   int yynrhs = yyrhsLength (yyrule);]b4_locations_if([
@@ -1280,8 +1280,8 @@ yy_reduce_print (int yynormal, yyGLRStackItem* yyvsp, size_t yyk,
       YYFPRINTF (stderr, "   $%d = ", yyi + 1);
       yy_symbol_print (stderr,
                        yystos[yyvsp[yyi - yynrhs + 1].yystate.yylrState],
-                       &yyvsp[yyi - yynrhs + 1].yystate.yysemantics.yysval
-                       ]b4_locations_if([, &]b4_rhs_location(yynrhs, yyi + 1))[]dnl
+                       &yyvsp[yyi - yynrhs + 1].yystate.yysemantics.yysval]b4_locations_if([,
+                       &]b4_rhs_location(yynrhs, yyi + 1))[]dnl
                        b4_user_args[);
       if (!yyvsp[yyi - yynrhs + 1].yystate.yyresolved)
         YYFPRINTF (stderr, " (unresolved)");
@@ -1308,9 +1308,9 @@ yydoAction (yyGLRStack* yystackp, size_t yyk, yyRuleNum yyrule,
       yyGLRStackItem* yyrhs = (yyGLRStackItem*) yystackp->yytops.yystates[yyk];
       YYASSERT (yyk == 0);
       yystackp->yynextFree -= yynrhs;
-      yystackp->yyspaceLeft += yynrhs;
+      yystackp->yyspaceLeft += (size_t) yynrhs;
       yystackp->yytops.yystates[0] = & yystackp->yynextFree[-1].yystate;
-      YY_REDUCE_PRINT ((1, yyrhs, yyk, yyrule]b4_user_args[));
+      YY_REDUCE_PRINT ((yytrue, yyrhs, yyk, yyrule]b4_user_args[));
       return yyuserAction (yyrule, yynrhs, yyrhs, yystackp,
                            yyvalp]b4_locuser_args[);
     }
@@ -1331,7 +1331,7 @@ yydoAction (yyGLRStack* yystackp, size_t yyk, yyRuleNum yyrule,
         }
       yyupdateSplit (yystackp, yys);
       yystackp->yytops.yystates[yyk] = yys;
-      YY_REDUCE_PRINT ((0, yyrhsVals + YYMAXRHS + YYMAXLEFT - 1, yyk, yyrule]b4_user_args[));
+      YY_REDUCE_PRINT ((yyfalse, yyrhsVals + YYMAXRHS + YYMAXLEFT - 1, yyk, yyrule]b4_user_args[));
       return yyuserAction (yyrule, yynrhs, yyrhsVals + YYMAXRHS + YYMAXLEFT - 1,
                            yystackp, yyvalp]b4_locuser_args[);
     }
@@ -1427,11 +1427,9 @@ yysplitStack (yyGLRStack* yystackp, size_t yyk)
     }
   if (yystackp->yytops.yysize >= yystackp->yytops.yycapacity)
     {
-      yyGLRState** yynewStates;
+      yyGLRState** yynewStates = YY_NULLPTR;
       yybool* yynewLookaheadNeeds;
 
-      yynewStates = YY_NULLPTR;
-
       if (yystackp->yytops.yycapacity
           > (YYSIZEMAX / (2 * sizeof yynewStates[0])))
         yyMemoryExhausted (yystackp);
@@ -1859,9 +1857,9 @@ yycompressStack (yyGLRStack* yystackp)
        yyr = yyp, yyp = yyq, yyq = yyp->yypred)
     yyp->yypred = yyr;
 
-  yystackp->yyspaceLeft += yystackp->yynextFree - yystackp->yyitems;
+  yystackp->yyspaceLeft += (size_t) (yystackp->yynextFree - yystackp->yyitems);
   yystackp->yynextFree = ((yyGLRStackItem*) yystackp->yysplitPoint) + 1;
-  yystackp->yyspaceLeft -= yystackp->yynextFree - yystackp->yyitems;
+  yystackp->yyspaceLeft -= (size_t) (yystackp->yynextFree - yystackp->yyitems);
   yystackp->yysplitPoint = YY_NULLPTR;
   yystackp->yylastDeleted = YY_NULLPTR;
 
@@ -2065,7 +2063,8 @@ yyreportSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
                 yyarg[yycount++] = yytokenName (yyx);
                 {
                   size_t yysz = yysize + yytnamerr (YY_NULLPTR, yytokenName (yyx));
-                  yysize_overflow |= yysz < yysize;
+                  if (yysz < yysize)
+                    yysize_overflow = yytrue;
                   yysize = yysz;
                 }
               }
@@ -2090,7 +2089,8 @@ yyreportSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
 
   {
     size_t yysz = yysize + strlen (yyformat);
-    yysize_overflow |= yysz < yysize;
+    if (yysz < yysize)
+      yysize_overflow = yytrue;
     yysize = yysz;
   }
 
