@@ -1190,7 +1190,7 @@ yyexpandGLRStack (yyGLRStack* yystackp)
   size_t yysize, yynewSize;
   size_t yyn;
   yysize = yystackp->yynextFree - yystackp->yyitems;
-  if (YYMAXDEPTH <= yysize)
+  if (YYMAXDEPTH - YYHEADROOM < yysize)
     yyMemoryExhausted (yystackp);
   yynewSize = 2*yysize;
   if (YYMAXDEPTH < yynewSize)
