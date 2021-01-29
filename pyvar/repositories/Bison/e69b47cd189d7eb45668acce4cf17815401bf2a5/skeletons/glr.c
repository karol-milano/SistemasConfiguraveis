@@ -1506,7 +1506,8 @@ yysplitStack (yyGLRStack* yystackp, ptrdiff_t yyk)
     {
       yyGLRState** yynewStates = YY_NULLPTR;
       yybool* yynewLookaheadNeeds;
-      ptrdiff_t half_max_capacity = YYSIZEMAX / (2 * sizeof yynewStates[0]);
+      ptrdiff_t state_size = sizeof yynewStates[0];
+      ptrdiff_t half_max_capacity = YYSIZEMAX / 2 / state_size;
 
       if (half_max_capacity < yystackp->yytops.yycapacity)
         yyMemoryExhausted (yystackp);
