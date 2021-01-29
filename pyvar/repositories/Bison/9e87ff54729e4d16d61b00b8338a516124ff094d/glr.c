@@ -1080,7 +1080,7 @@ yyexpandGLRStack (yyGLRStack* yystackp)
     }
   if (yystackp->yysplitPoint != YY_NULL)
     yystackp->yysplitPoint = YYRELOC (yystackp->yyitems, yynewItems,
-                                 yystackp->yysplitPoint, yystate);
+                                      yystackp->yysplitPoint, yystate);
 
   for (yyn = 0; yyn < yystackp->yytops.yysize; yyn += 1)
     if (yystackp->yytops.yystates[yyn] != YY_NULL)
