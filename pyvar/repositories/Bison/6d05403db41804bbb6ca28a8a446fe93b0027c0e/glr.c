@@ -1803,43 +1803,43 @@ yyreportAmbiguity (yySemanticOption* yyx0,
   return yyabort;
 }
 
-/** Starting at and including state S, resolve the location for each of the
- *  previous N states that is unresolved.  The first semantic option of a state
+/** Starting at and including state S1, resolve the location for each of the
+ *  previous N1 states that is unresolved.  The first semantic option of a state
  *  is always chosen.  */
 static void
-yyresolveLocations (yyGLRState* yys, int yyn,
+yyresolveLocations (yyGLRState* yys1, int yyn1,
 		    yyGLRStack *yystackp]b4_user_formals[)
 {
-  if (0 < yyn)
+  if (0 < yyn1)
     {
-      yyresolveLocations (yys->yypred, yyn-1, yystackp]b4_user_args[);
-      if (!yys->yyresolved)
+      yyresolveLocations (yys1->yypred, yyn1 - 1, yystackp]b4_user_args[);
+      if (!yys1->yyresolved)
 	{
 	  yySemanticOption *yyoption;
-	  yyGLRStackItem yyrhs[1 + YYMAXRHS];
+	  yyGLRStackItem yyrhsloc[1 + YYMAXRHS];
 	  int yynrhs;
 	  int yychar_current;
 	  YYSTYPE yylval_current;
 	  YYLTYPE yylloc_current;
-	  yyoption = yys->yysemantics.yyfirstVal;
+	  yyoption = yys1->yysemantics.yyfirstVal;
 	  YYASSERT (yyoption != NULL);
 	  yynrhs = yyrhsLength (yyoption->yyrule);
 	  if (yynrhs > 0)
 	    {
 	      yyGLRState *yys;
-	      int yyi;
+	      int yyn;
 	      yyresolveLocations (yyoption->yystate, yynrhs,
 				  yystackp]b4_user_args[);
-	      for (yys = yyoption->yystate, yyi = yynrhs;
-		   yyi >= 1;
-		   yys = yys->yypred, yyi -= 1)
-		yyrhs[yyi].yystate.yyloc = yys->yyloc;
+	      for (yys = yyoption->yystate, yyn = yynrhs;
+		   yyn > 0;
+		   yys = yys->yypred, yyn -= 1)
+		yyrhsloc[yyn].yystate.yyloc = yys->yyloc;
 	    }
 	  else
 	    {
 	      yyGLRState *yyprevious = yyoption->yystate;
 	      YYASSERT (yyprevious->yyresolved);
-	      yyrhs[0].yystate.yyloc = yyprevious->yyloc;
+	      yyrhsloc[0].yystate.yyloc = yyprevious->yyloc;
 	    }
 	  yychar_current = yychar;
 	  yylval_current = yylval;
@@ -1847,7 +1847,7 @@ yyresolveLocations (yyGLRState* yys, int yyn,
 	  yychar = yyoption->yyrawchar;
 	  yylval = yyoption->yyval;
 	  yylloc = yyoption->yyloc;
-	  YYLLOC_DEFAULT ((yys->yyloc), yyrhs, yynrhs);
+	  YYLLOC_DEFAULT ((yys1->yyloc), yyrhsloc, yynrhs);
 	  yychar = yychar_current;
 	  yylval = yylval_current;
 	  yylloc = yylloc_current;
