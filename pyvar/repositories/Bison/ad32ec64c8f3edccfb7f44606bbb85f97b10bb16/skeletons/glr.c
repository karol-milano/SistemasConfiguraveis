@@ -1104,9 +1104,9 @@ yyinitStateSet (yyGLRStateSet* yyset)
   yyset->yysize = 1;
   yyset->yycapacity = 16;
   yyset->yystates
-    = YY_CAST(yyGLRState**,
-              YYMALLOC (YY_CAST (size_t, yyset->yycapacity)
-                        * sizeof yyset->yystates[0]));
+    = YY_CAST (yyGLRState**,
+               YYMALLOC (YY_CAST (size_t, yyset->yycapacity)
+                         * sizeof yyset->yystates[0]));
   if (! yyset->yystates)
     return yyfalse;
   yyset->yystates[0] = YY_NULLPTR;
@@ -1483,7 +1483,8 @@ yyglrReduce (yyGLRStack* yystackp, ptrdiff_t yyk, yyRuleNum yyrule,
       YYDPRINTF ((stderr,
                   "Reduced stack %ld by rule %d (line %d); action deferred.  "
                   "Now in state %d.\n",
-                  YY_CAST(long, yyk), yyrule - 1, yyrline[yyrule - 1], yynewLRState));
+                  YY_CAST (long, yyk), yyrule - 1, yyrline[yyrule - 1],
+                  yynewLRState));
       for (yyi = 0; yyi < yystackp->yytops.yysize; yyi += 1)
         if (yyi != yyk && yystackp->yytops.yystates[yyi] != YY_NULLPTR)
           {
