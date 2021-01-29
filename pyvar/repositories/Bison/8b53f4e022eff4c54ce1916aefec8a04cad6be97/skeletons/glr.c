@@ -1510,41 +1510,42 @@ yysplitStack (yyGLRStack* yystackp, ptrdiff_t yyk)
       YYASSERT (yyk == 0);
       yystackp->yysplitPoint = yystackp->yytops.yystates[yyk];
     }
-  if (yystackp->yytops.yysize >= yystackp->yytops.yycapacity)
+  if (yystackp->yytops.yycapacity <= yystackp->yytops.yysize)
     {
-      yyGLRState** yynewStates = YY_NULLPTR;
-      yybool* yynewLookaheadNeeds;
-      ptrdiff_t state_size = sizeof yynewStates[0];
+      ptrdiff_t state_size = sizeof yystackp->yytops.yystates[0];
       ptrdiff_t half_max_capacity = YYSIZEMAX / 2 / state_size;
-
       if (half_max_capacity < yystackp->yytops.yycapacity)
         yyMemoryExhausted (yystackp);
       yystackp->yytops.yycapacity *= 2;
 
-      yynewStates
-        = YY_CAST (yyGLRState**,
-                   YYREALLOC (yystackp->yytops.yystates,
-                              (YY_CAST (size_t, yystackp->yytops.yycapacity)
-                               * sizeof yynewStates[0])));
-      if (yynewStates == YY_NULLPTR)
-        yyMemoryExhausted (yystackp);
-      yystackp->yytops.yystates = yynewStates;
-
-      yynewLookaheadNeeds
-        = YY_CAST (yybool*,
-                   YYREALLOC (yystackp->yytops.yylookaheadNeeds,
-                              (YY_CAST (size_t, yystackp->yytops.yycapacity)
-                               * sizeof yynewLookaheadNeeds[0])));
-      if (yynewLookaheadNeeds == YY_NULLPTR)
-        yyMemoryExhausted (yystackp);
-      yystackp->yytops.yylookaheadNeeds = yynewLookaheadNeeds;
+      {
+        yyGLRState** yynewStates
+          = YY_CAST (yyGLRState**,
+                     YYREALLOC (yystackp->yytops.yystates,
+                                (YY_CAST (size_t, yystackp->yytops.yycapacity)
+                                 * sizeof yynewStates[0])));
+        if (yynewStates == YY_NULLPTR)
+          yyMemoryExhausted (yystackp);
+        yystackp->yytops.yystates = yynewStates;
+      }
+
+      {
+        yybool* yynewLookaheadNeeds
+          = YY_CAST (yybool*,
+                     YYREALLOC (yystackp->yytops.yylookaheadNeeds,
+                                (YY_CAST (size_t, yystackp->yytops.yycapacity)
+                                 * sizeof yynewLookaheadNeeds[0])));
+        if (yynewLookaheadNeeds == YY_NULLPTR)
+          yyMemoryExhausted (yystackp);
+        yystackp->yytops.yylookaheadNeeds = yynewLookaheadNeeds;
+      }
     }
   yystackp->yytops.yystates[yystackp->yytops.yysize]
     = yystackp->yytops.yystates[yyk];
   yystackp->yytops.yylookaheadNeeds[yystackp->yytops.yysize]
     = yystackp->yytops.yylookaheadNeeds[yyk];
   yystackp->yytops.yysize += 1;
-  return yystackp->yytops.yysize-1;
+  return yystackp->yytops.yysize - 1;
 }
 
 /** True iff YYY0 and YYY1 represent identical options at the top level.
@@ -1578,7 +1579,7 @@ yymergeOptionSets (yySemanticOption* yyy0, yySemanticOption* yyy1)
   int yyn;
   for (yys0 = yyy0->yystate, yys1 = yyy1->yystate,
        yyn = yyrhsLength (yyy0->yyrule);
-       yyn > 0;
+       0 < yyn;
        yys0 = yys0->yypred, yys1 = yys1->yypred, yyn -= 1)
     {
       if (yys0 == yys1)
