@@ -1803,6 +1803,57 @@ yyreportAmbiguity (yySemanticOption* yyx0,
   return yyabort;
 }
 
+/** Starting at and including state S, resolve the location for each of the
+ *  previous N states that is unresolved.  The first semantic option of a state
+ *  is always chosen.  */
+static void
+yyresolveLocations (yyGLRState* yys, int yyn,
+		    yyGLRStack *yystackp]b4_user_formals[)
+{
+  if (0 < yyn)
+    {
+      yyresolveLocations (yys->yypred, yyn-1, yystackp]b4_user_args[);
+      if (!yys->yyresolved)
+	{
+	  yySemanticOption *yyoption;
+	  yyGLRStackItem yyrhs[1 + YYMAXRHS];
+	  int yynrhs;
+	  int yychar_current;
+	  YYSTYPE yylval_current;
+	  YYLTYPE yylloc_current;
+	  yyoption = yys->yysemantics.yyfirstVal;
+	  YYASSERT (yyoption != NULL);
+	  yynrhs = yyrhsLength (yyoption->yyrule);
+	  if (yynrhs > 0)
+	    {
+	      yyGLRState *yys;
+	      int yyi;
+	      yyresolveLocations (yyoption->yystate, yynrhs,
+				  yystackp]b4_user_args[);
+	      for (yys = yyoption->yystate, yyi = yynrhs;
+		   yyi >= 1;
+		   yys = yys->yypred, yyi -= 1)
+		yyrhs[yyi].yystate.yyloc = yys->yyloc;
+	    }
+	  else
+	    {
+	      yyGLRState *yyprevious = yyoption->yystate;
+	      YYASSERT (yyprevious->yyresolved);
+	      yyrhs[0].yystate.yyloc = yyprevious->yyloc;
+	    }
+	  yychar_current = yychar;
+	  yylval_current = yylval;
+	  yylloc_current = yylloc;
+	  yychar = yyoption->yyrawchar;
+	  yylval = yyoption->yyval;
+	  yylloc = yyoption->yyloc;
+	  YYLLOC_DEFAULT ((yys->yyloc), yyrhs, yynrhs);
+	  yychar = yychar_current;
+	  yylval = yylval_current;
+	  yylloc = yylloc_current;
+	}
+    }
+}
 
 /** Resolve the ambiguity represented in state S, perform the indicated
  *  actions, and set the semantic value of S.  If result != yyok, the chain of
@@ -1837,6 +1888,7 @@ yyresolveValue (yyGLRState* yys, yyGLRStack* yystackp]b4_user_formals[)
 	  switch (yypreference (yybest, yyp))
 	    {
 	    case 0:
+	      yyresolveLocations (yys, 1, yystackp]b4_user_args[);
 	      return yyreportAmbiguity (yybest, yyp]b4_pure_args[);
 	      break;
 	    case 1:
