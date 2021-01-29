@@ -1985,7 +1985,8 @@ yyprocessOneStack (yyGLRStack* yystackp, ptrdiff_t yyk,
   while (yystackp->yytops.yystates[yyk] != YY_NULLPTR)
     {
       yyStateNum yystate = yystackp->yytops.yystates[yyk]->yylrState;
-      YY_DPRINTF ((stderr, "Stack %ld Entering state %d\n", yyk, yystate));
+      YY_DPRINTF ((stderr, "Stack %ld Entering state %d\n",
+                   YY_CAST (long, yyk), yystate));
 
       YY_ASSERT (yystate != YYFINAL);
 
