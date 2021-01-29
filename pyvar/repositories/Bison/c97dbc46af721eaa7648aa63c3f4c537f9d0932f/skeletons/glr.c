@@ -1967,18 +1967,24 @@ yyresolveStack (yyGLRStack* yystackp]b4_user_formals[)
   return yyok;
 }
 
+/** Called when returning to deterministic operation to clean up the extra
+ * stacks. */
 static void
 yycompressStack (yyGLRStack* yystackp)
 {
-  yyGLRState* yyp, *yyq, *yyr;
+  /* yyr is the state after the split point.  */
+  yyGLRState *yyr;
 
   if (yystackp->yytops.yysize != 1 || yystackp->yysplitPoint == YY_NULLPTR)
     return;
 
-  for (yyp = yystackp->yytops.yystates[0], yyq = yyp->yypred, yyr = YY_NULLPTR;
-       yyp != yystackp->yysplitPoint;
-       yyr = yyp, yyp = yyq, yyq = yyp->yypred)
-    yyp->yypred = yyr;
+  {
+    yyGLRState *yyp, *yyq;
+    for (yyp = yystackp->yytops.yystates[0], yyq = yyp->yypred, yyr = YY_NULLPTR;
+         yyp != yystackp->yysplitPoint;
+         yyr = yyp, yyp = yyq, yyq = yyp->yypred)
+      yyp->yypred = yyr;
+  }
 
   yystackp->yyspaceLeft += yystackp->yynextFree - yystackp->yyitems;
   yystackp->yynextFree = YY_REINTERPRET_CAST (yyGLRStackItem*, yystackp->yysplitPoint) + 1;
