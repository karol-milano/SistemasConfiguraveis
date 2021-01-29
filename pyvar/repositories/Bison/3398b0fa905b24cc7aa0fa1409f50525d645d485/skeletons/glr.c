@@ -125,7 +125,7 @@ m4_define([b4_lhs_value],
 # -----------------------------
 # See README.
 m4_define([b4_rhs_data],
-[((yyGLRStackItem const *)yyvsp)@{YYFILL (b4_subtract([$2], [$1]))@}.yystate])
+[YY_CAST (yyGLRStackItem const *, yyvsp)@{YYFILL (b4_subtract([$2], [$1]))@}.yystate])
 
 
 # b4_rhs_value(RULE-LENGTH, POS, SYMBOL-NUM, [TYPE])
@@ -235,7 +235,7 @@ b4_copyright([Skeleton implementation for Bison GLR parsers in C],
 #define yylloc  ]b4_prefix[lloc]])]))[
 
 ]b4_user_pre_prologue[
-
+]b4_cast_define[
 ]b4_null_define[
 
 ]b4_defines_if([[#include "@basename(]b4_spec_header_file[@)"]],
@@ -289,7 +289,8 @@ static YYLTYPE yyloc_default][]b4_yyloc_default;])[
 # define YYREALLOC realloc
 #endif
 
-#define YYSIZEMAX (PTRDIFF_MAX < SIZE_MAX ? PTRDIFF_MAX : (ptrdiff_t) SIZE_MAX)
+#define YYSIZEMAX \
+  (PTRDIFF_MAX < SIZE_MAX ? PTRDIFF_MAX : YY_CAST (ptrdiff_t, SIZE_MAX))
 
 #ifdef __cplusplus
   typedef bool yybool;
@@ -617,7 +618,7 @@ yytnamerr (char *yyres, const char *yystr)
   if (yyres)
     return yystpcpy (yyres, yystr) - yyres;
   else
-    return (ptrdiff_t) strlen (yystr);
+    return YY_CAST (ptrdiff_t, strlen (yystr));
 }
 # endif
 
@@ -845,7 +846,8 @@ yyuserAction (yyRuleNum yyn, int yyrhslen, yyGLRStackItem* yyvsp,
               yyGLRStack* yystackp,
               YYSTYPE* yyvalp]b4_locuser_formals[)
 {
-  yybool yynormal YY_ATTRIBUTE_UNUSED = (yybool) (yystackp->yysplitPoint == YY_NULLPTR);
+  yybool yynormal YY_ATTRIBUTE_UNUSED
+    = YY_CAST (yybool, yystackp->yysplitPoint == YY_NULLPTR);
   int yylow;
 ]b4_parse_param_use([yyvalp], [yylocp])dnl
 [  YYUSE (yyrhslen);
@@ -980,7 +982,7 @@ yylhsNonterm (yyRuleNum yyrule)
 static inline yybool
 yyisDefaultedState (yyStateNum yystate)
 {
-  return (yybool) yypact_value_is_default (yypact[yystate]);
+  return YY_CAST (yybool, yypact_value_is_default (yypact[yystate]));
 }
 
 /** The default reduction for YYSTATE, assuming it has one.  */
@@ -1040,13 +1042,13 @@ yyLRgotoState (yyStateNum yystate, yySymbol yysym)
 static inline yybool
 yyisShiftAction (int yyaction)
 {
-  return (yybool) (0 < yyaction);
+  return YY_CAST (yybool, 0 < yyaction);
 }
 
 static inline yybool
 yyisErrorAction (int yyaction)
 {
-  return (yybool) (yyaction == 0);
+  return YY_CAST (yybool, yyaction == 0);
 }
 
                                 /* GLRStates */
@@ -1102,21 +1104,24 @@ yyinitStateSet (yyGLRStateSet* yyset)
   yyset->yysize = 1;
   yyset->yycapacity = 16;
   yyset->yystates
-    = (yyGLRState**) YYMALLOC ((size_t) yyset->yycapacity
-                               * sizeof yyset->yystates[0]);
+    = YY_CAST(yyGLRState**,
+              YYMALLOC (YY_CAST (size_t, yyset->yycapacity)
+                        * sizeof yyset->yystates[0]));
   if (! yyset->yystates)
     return yyfalse;
   yyset->yystates[0] = YY_NULLPTR;
   yyset->yylookaheadNeeds
-    = (yybool*) YYMALLOC ((size_t) yyset->yycapacity
-                          * sizeof yyset->yylookaheadNeeds[0]);
+    = YY_CAST (yybool*,
+               YYMALLOC (YY_CAST (size_t, yyset->yycapacity)
+                         * sizeof yyset->yylookaheadNeeds[0]));
   if (! yyset->yylookaheadNeeds)
     {
       YYFREE (yyset->yystates);
       return yyfalse;
     }
   memset (yyset->yylookaheadNeeds,
-          0, (size_t) yyset->yycapacity * sizeof yyset->yylookaheadNeeds[0]);
+          0,
+          YY_CAST (size_t, yyset->yycapacity) * sizeof yyset->yylookaheadNeeds[0]);
   return yytrue;
 }
 
@@ -1134,9 +1139,10 @@ yyinitGLRStack (yyGLRStack* yystackp, ptrdiff_t yysize)
   yystackp->yyerrState = 0;
   yynerrs = 0;
   yystackp->yyspaceLeft = yysize;
-  yystackp->yyitems =
-    (yyGLRStackItem*) YYMALLOC ((size_t) yysize
-                                * sizeof yystackp->yynextFree[0]);
+  yystackp->yyitems
+    = YY_CAST (yyGLRStackItem*,
+               YYMALLOC (YY_CAST (size_t, yysize)
+                         * sizeof yystackp->yynextFree[0]));
   if (!yystackp->yyitems)
     return yyfalse;
   yystackp->yynextFree = yystackp->yyitems;
@@ -1147,8 +1153,9 @@ yyinitGLRStack (yyGLRStack* yystackp, ptrdiff_t yysize)
 
 
 #if YYSTACKEXPANDABLE
-# define YYRELOC(YYFROMITEMS,YYTOITEMS,YYX,YYTYPE) \
-  &((YYTOITEMS) - ((YYFROMITEMS) - (yyGLRStackItem*) (YYX)))->YYTYPE
+# define YYRELOC(YYFROMITEMS, YYTOITEMS, YYX, YYTYPE)                   \
+  &((YYTOITEMS)                                                         \
+    - ((YYFROMITEMS) - YY_REINTERPRET_CAST (yyGLRStackItem*, (YYX))))->YYTYPE
 
 /** If *YYSTACKP is expandable, extend it.  WARNING: Pointers into the
     stack from outside should be considered invalid after this call.
@@ -1168,8 +1175,10 @@ yyexpandGLRStack (yyGLRStack* yystackp)
   yynewSize = 2*yysize;
   if (YYMAXDEPTH < yynewSize)
     yynewSize = YYMAXDEPTH;
-  yynewItems = (yyGLRStackItem*) YYMALLOC ((size_t) yynewSize
-                                           * sizeof yynewItems[0]);
+  yynewItems
+    = YY_CAST (yyGLRStackItem*,
+               YYMALLOC (YY_CAST (size_t, yynewSize)
+                         * sizeof yynewItems[0]));
   if (! yynewItems)
     yyMemoryExhausted (yystackp);
   for (yyp0 = yystackp->yyitems, yyp1 = yynewItems, yyn = yysize;
@@ -1177,7 +1186,7 @@ yyexpandGLRStack (yyGLRStack* yystackp)
        yyn -= 1, yyp0 += 1, yyp1 += 1)
     {
       *yyp1 = *yyp0;
-      if (*(yybool *) yyp0)
+      if (*YY_REINTERPRET_CAST (yybool *, yyp0))
         {
           yyGLRState* yys0 = &yyp0->yystate;
           yyGLRState* yys1 = &yyp1->yystate;
@@ -1282,7 +1291,7 @@ yyremoveDeletes (yyGLRStack* yystackp)
           if (yyj != yyi)
             {
               YYDPRINTF ((stderr, "Rename stack %ld -> %ld.\n",
-                          (long) yyi, (long) yyj));
+                          YY_CAST (long, yyi), YY_CAST (long, yyj)));
             }
           yyj += 1;
         }
@@ -1353,7 +1362,7 @@ yy_reduce_print (yybool yynormal, yyGLRStackItem* yyvsp, ptrdiff_t yyk,
   int yylow = 1;])[
   int yyi;
   YYFPRINTF (stderr, "Reducing stack %ld by rule %d (line %d):\n",
-             (long) yyk, yyrule - 1, yyrline[yyrule]);
+             YY_CAST (long, yyk), yyrule - 1, yyrline[yyrule]);
   if (! yynormal)
     yyfillin (yyvsp, 1, -yynrhs);
   /* The symbols being reduced.  */
@@ -1387,7 +1396,8 @@ yydoAction (yyGLRStack* yystackp, ptrdiff_t yyk, yyRuleNum yyrule,
   if (yystackp->yysplitPoint == YY_NULLPTR)
     {
       /* Standard special case: single stack.  */
-      yyGLRStackItem* yyrhs = (yyGLRStackItem*) yystackp->yytops.yystates[yyk];
+      yyGLRStackItem* yyrhs
+        = YY_REINTERPRET_CAST (yyGLRStackItem*, yystackp->yytops.yystates[yyk]);
       YYASSERT (yyk == 0);
       yystackp->yynextFree -= yynrhs;
       yystackp->yyspaceLeft += yynrhs;
@@ -1445,7 +1455,7 @@ yyglrReduce (yyGLRStack* yystackp, ptrdiff_t yyk, yyRuleNum yyrule,
         {
           YYDPRINTF ((stderr,
                       "Parse on stack %ld rejected by rule %d (line %d).\n",
-                      (long) yyk, yyrule - 1, yyrline[yyrule - 1]));
+                      YY_CAST (long, yyk), yyrule - 1, yyrline[yyrule - 1]));
         }
       if (yyflag != yyok)
         return yyflag;
@@ -1473,7 +1483,7 @@ yyglrReduce (yyGLRStack* yystackp, ptrdiff_t yyk, yyRuleNum yyrule,
       YYDPRINTF ((stderr,
                   "Reduced stack %ld by rule %d (line %d); action deferred.  "
                   "Now in state %d.\n",
-                  (long) yyk, yyrule - 1, yyrline[yyrule - 1], yynewLRState));
+                  YY_CAST(long, yyk), yyrule - 1, yyrline[yyrule - 1], yynewLRState));
       for (yyi = 0; yyi < yystackp->yytops.yysize; yyi += 1)
         if (yyi != yyk && yystackp->yytops.yystates[yyi] != YY_NULLPTR)
           {
@@ -1486,7 +1496,7 @@ yyglrReduce (yyGLRStack* yystackp, ptrdiff_t yyk, yyRuleNum yyrule,
                     yyaddDeferredAction (yystackp, yyk, yyp, yys0, yyrule);
                     yymarkStackDeleted (yystackp, yyk);
                     YYDPRINTF ((stderr, "Merging stack %ld into stack %ld.\n",
-                                (long) yyk, (long) yyi));
+                                YY_CAST (long, yyk), YY_CAST (long, yyi)));
                     return yyok;
                   }
                 yyp = yyp->yypred;
@@ -1517,18 +1527,20 @@ yysplitStack (yyGLRStack* yystackp, ptrdiff_t yyk)
         yyMemoryExhausted (yystackp);
       yystackp->yytops.yycapacity *= 2;
 
-      yynewStates =
-        (yyGLRState**) YYREALLOC (yystackp->yytops.yystates,
-                                  ((size_t) yystackp->yytops.yycapacity
-                                   * sizeof yynewStates[0]));
+      yynewStates
+        = YY_CAST (yyGLRState**,
+                   YYREALLOC (yystackp->yytops.yystates,
+                              (YY_CAST (size_t, yystackp->yytops.yycapacity)
+                               * sizeof yynewStates[0])));
       if (yynewStates == YY_NULLPTR)
         yyMemoryExhausted (yystackp);
       yystackp->yytops.yystates = yynewStates;
 
-      yynewLookaheadNeeds =
-        (yybool*) YYREALLOC (yystackp->yytops.yylookaheadNeeds,
-                             ((size_t) yystackp->yytops.yycapacity
-                              * sizeof yynewLookaheadNeeds[0]));
+      yynewLookaheadNeeds
+        = YY_CAST (yybool*,
+                   YYREALLOC (yystackp->yytops.yylookaheadNeeds,
+                              (YY_CAST (size_t, yystackp->yytops.yycapacity)
+                               * sizeof yynewLookaheadNeeds[0])));
       if (yynewLookaheadNeeds == YY_NULLPTR)
         yyMemoryExhausted (yystackp);
       yystackp->yytops.yylookaheadNeeds = yynewLookaheadNeeds;
@@ -1731,8 +1743,8 @@ yyreportTree (yySemanticOption* yyx, int yyindent)
   else
     YYFPRINTF (stderr, "%*s%s -> <Rule %d, tokens %ld .. %ld>\n",
                yyindent, "", yytokenName (yylhsNonterm (yyx->yyrule)),
-               yyx->yyrule - 1, (long) (yys->yyposn + 1),
-               (long) yyx->yystate->yyposn);
+               yyx->yyrule - 1, YY_CAST (long, yys->yyposn + 1),
+               YY_CAST (long, yyx->yystate->yyposn));
   for (yyi = 1; yyi <= yynrhs; yyi += 1)
     {
       if (yystates[yyi]->yyresolved)
@@ -1743,8 +1755,8 @@ yyreportTree (yySemanticOption* yyx, int yyindent)
           else
             YYFPRINTF (stderr, "%*s%s <tokens %ld .. %ld>\n", yyindent+2, "",
                        yytokenName (yystos[yystates[yyi]->yylrState]),
-                       (long) (yystates[yyi-1]->yyposn + 1),
-                       (long) yystates[yyi]->yyposn);
+                       YY_CAST (long, yystates[yyi-1]->yyposn + 1),
+                       YY_CAST (long, yystates[yyi]->yyposn));
         }
       else
         yyreportTree (yystates[yyi]->yysemantics.yyfirstVal, yyindent+2);
@@ -1940,7 +1952,7 @@ yycompressStack (yyGLRStack* yystackp)
     yyp->yypred = yyr;
 
   yystackp->yyspaceLeft += yystackp->yynextFree - yystackp->yyitems;
-  yystackp->yynextFree = ((yyGLRStackItem*) yystackp->yysplitPoint) + 1;
+  yystackp->yynextFree = YY_REINTERPRET_CAST (yyGLRStackItem*, yystackp->yysplitPoint) + 1;
   yystackp->yyspaceLeft -= yystackp->yynextFree - yystackp->yyitems;
   yystackp->yysplitPoint = YY_NULLPTR;
   yystackp->yylastDeleted = YY_NULLPTR;
@@ -1973,7 +1985,7 @@ yyprocessOneStack (yyGLRStack* yystackp, ptrdiff_t yyk,
           yyRuleNum yyrule = yydefaultAction (yystate);
           if (yyrule == 0)
             {
-              YYDPRINTF ((stderr, "Stack %ld dies.\n", (long) yyk));
+              YYDPRINTF ((stderr, "Stack %ld dies.\n", YY_CAST (long, yyk)));
               yymarkStackDeleted (yystackp, yyk);
               return yyok;
             }
@@ -1983,7 +1995,7 @@ yyprocessOneStack (yyGLRStack* yystackp, ptrdiff_t yyk,
               YYDPRINTF ((stderr,
                           "Stack %ld dies "
                           "(predicate failure or explicit user error).\n",
-                          (long) yyk));
+                          YY_CAST (long, yyk)));
               yymarkStackDeleted (yystackp, yyk);
               return yyok;
             }
@@ -2002,7 +2014,7 @@ yyprocessOneStack (yyGLRStack* yystackp, ptrdiff_t yyk,
               YYRESULTTAG yyflag;
               ptrdiff_t yynewStack = yysplitStack (yystackp, yyk);
               YYDPRINTF ((stderr, "Splitting off stack %ld from %ld.\n",
-                          (long) yynewStack, (long) yyk));
+                          YY_CAST (long, yynewStack), YY_CAST (long, yyk)));
               yyflag = yyglrReduce (yystackp, yynewStack,
                                     *yyconflicts,
                                     yyimmediate[*yyconflicts]]b4_user_args[);
@@ -2011,7 +2023,7 @@ yyprocessOneStack (yyGLRStack* yystackp, ptrdiff_t yyk,
                                           yyposn]b4_pure_args[));
               else if (yyflag == yyerr)
                 {
-                  YYDPRINTF ((stderr, "Stack %ld dies.\n", (long) yynewStack));
+                  YYDPRINTF ((stderr, "Stack %ld dies.\n", YY_CAST (long, yynewStack)));
                   yymarkStackDeleted (yystackp, yynewStack);
                 }
               else
@@ -2023,7 +2035,7 @@ yyprocessOneStack (yyGLRStack* yystackp, ptrdiff_t yyk,
             break;
           else if (yyisErrorAction (yyaction))
             {
-              YYDPRINTF ((stderr, "Stack %ld dies.\n", (long) yyk));
+              YYDPRINTF ((stderr, "Stack %ld dies.\n", YY_CAST (long, yyk)));
               yymarkStackDeleted (yystackp, yyk);
               break;
             }
@@ -2036,7 +2048,7 @@ yyprocessOneStack (yyGLRStack* yystackp, ptrdiff_t yyk,
                   YYDPRINTF ((stderr,
                               "Stack %ld dies "
                               "(predicate failure or explicit user error).\n",
-                              (long) yyk));
+                              YY_CAST (long, yyk)));
                   yymarkStackDeleted (yystackp, yyk);
                   break;
                 }
@@ -2147,7 +2159,7 @@ yyreportSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
     }
 
   {
-    ptrdiff_t yysz = (ptrdiff_t) strlen (yyformat);
+    ptrdiff_t yysz = YY_CAST (ptrdiff_t, strlen (yyformat));
     if (YYSIZEMAX - yysize < yysz)
       yysize_overflow = yytrue;
     else
@@ -2155,7 +2167,7 @@ yyreportSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
   }
 
   if (!yysize_overflow)
-    yymsg = (char *) YYMALLOC ((size_t) yysize);
+    yymsg = YY_CAST (char *, YYMALLOC (YY_CAST (size_t, yysize)));
 
   if (yymsg)
     {
@@ -2389,7 +2401,7 @@ b4_dollar_popdef])[]dnl
           ptrdiff_t yys;
 
           for (yys = 0; yys < yystack.yytops.yysize; yys += 1)
-            yystackp->yytops.yylookaheadNeeds[yys] = (yybool) (yychar != YYEMPTY);
+            yystackp->yytops.yylookaheadNeeds[yys] = YY_CAST (yybool, yychar != YYEMPTY);
 
           /* yyprocessOneStack returns one of three things:
 
@@ -2440,12 +2452,12 @@ b4_dollar_popdef])[]dnl
               int yyaction = yygetLRActions (yystate, yytoken_to_shift,
                               &yyconflicts);
               /* Note that yyconflicts were handled by yyprocessOneStack.  */
-              YYDPRINTF ((stderr, "On stack %ld, ", (long) yys));
+              YYDPRINTF ((stderr, "On stack %ld, ", YY_CAST (long, yys)));
               YY_SYMBOL_PRINT ("shifting", yytoken_to_shift, &yylval, &yylloc);
               yyglrShift (&yystack, yys, yyaction, yyposn,
                           &yylval]b4_locations_if([, &yylloc])[);
               YYDPRINTF ((stderr, "Stack %ld now in state #%d\n",
-                          (long) yys,
+                          YY_CAST (long, yys),
                           yystack.yytops.yystates[yys]->yylrState));
             }
 
@@ -2527,7 +2539,7 @@ yy_yypstack (yyGLRState* yys)
       yy_yypstack (yys->yypred);
       YYFPRINTF (stderr, " -> ");
     }
-  YYFPRINTF (stderr, "%d@@%ld", yys->yylrState, (long) yys->yyposn);
+  YYFPRINTF (stderr, "%d@@%ld", yys->yylrState, YY_CAST (long, yys->yyposn));
 }
 
 static void
@@ -2546,31 +2558,31 @@ yypstack (yyGLRStack* yystackp, ptrdiff_t yyk)
   yypstates (yystackp->yytops.yystates[yyk]);
 }
 
-#define YYINDEX(YYX)                                                         \
-    ((YYX) == YY_NULLPTR ? -1 : (yyGLRStackItem*) (YYX) - yystackp->yyitems)
-
-
 static void
 yypdumpstack (yyGLRStack* yystackp)
 {
+#define YYINDEX(YYX)                                                    \
+  YY_CAST (long,                                                        \
+           ((YYX)                                                       \
+            ? YY_REINTERPRET_CAST (yyGLRStackItem*, (YYX)) - yystackp->yyitems \
+            : -1))
+
   yyGLRStackItem* yyp;
-  ptrdiff_t yyi;
   for (yyp = yystackp->yyitems; yyp < yystackp->yynextFree; yyp += 1)
     {
       YYFPRINTF (stderr, "%3ld. ",
-                 (long) (yyp - yystackp->yyitems));
-      if (*(yybool *) yyp)
+                 YY_CAST (long, yyp - yystackp->yyitems));
+      if (*YY_REINTERPRET_CAST (yybool *, yyp))
         {
           YYASSERT (yyp->yystate.yyisState);
           YYASSERT (yyp->yyoption.yyisState);
           YYFPRINTF (stderr, "Res: %d, LR State: %d, posn: %ld, pred: %ld",
                      yyp->yystate.yyresolved, yyp->yystate.yylrState,
-                     (long) yyp->yystate.yyposn,
-                     (long) YYINDEX (yyp->yystate.yypred));
+                     YY_CAST (long, yyp->yystate.yyposn),
+                     YYINDEX (yyp->yystate.yypred));
           if (! yyp->yystate.yyresolved)
             YYFPRINTF (stderr, ", firstVal: %ld",
-                       (long) YYINDEX (yyp->yystate
-                                             .yysemantics.yyfirstVal));
+                       YYINDEX (yyp->yystate.yysemantics.yyfirstVal));
         }
       else
         {
@@ -2578,16 +2590,21 @@ yypdumpstack (yyGLRStack* yystackp)
           YYASSERT (!yyp->yyoption.yyisState);
           YYFPRINTF (stderr, "Option. rule: %d, state: %ld, next: %ld",
                      yyp->yyoption.yyrule - 1,
-                     (long) YYINDEX (yyp->yyoption.yystate),
-                     (long) YYINDEX (yyp->yyoption.yynext));
+                     YYINDEX (yyp->yyoption.yystate),
+                     YYINDEX (yyp->yyoption.yynext));
         }
       YYFPRINTF (stderr, "\n");
     }
+
   YYFPRINTF (stderr, "Tops:");
-  for (yyi = 0; yyi < yystackp->yytops.yysize; yyi += 1)
-    YYFPRINTF (stderr, "%ld: %ld; ", (long) yyi,
-               (long) YYINDEX (yystackp->yytops.yystates[yyi]));
-  YYFPRINTF (stderr, "\n");
+  {
+    ptrdiff_t yyi;
+    for (yyi = 0; yyi < yystackp->yytops.yysize; yyi += 1)
+      YYFPRINTF (stderr, "%ld: %ld; ", YY_CAST (long, yyi),
+                 YYINDEX (yystackp->yytops.yystates[yyi]));
+    YYFPRINTF (stderr, "\n");
+  }
+#undef YYINDEX
 }
 #endif
 
