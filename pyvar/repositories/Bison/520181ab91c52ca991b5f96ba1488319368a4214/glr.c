@@ -979,7 +979,10 @@ yydestroyGLRState (char const *yymsg, yyGLRState *yys]b4_user_formals[)
 #if YYDEBUG
       if (yydebug)
 	{
-	  YYFPRINTF (stderr, "%s unresolved ", yymsg);
+	  if (yys->yysemantics.yyfirstVal)
+	    YYFPRINTF (stderr, "%s unresolved ", yymsg);
+	  else
+	    YYFPRINTF (stderr, "%s incomplete ", yymsg);
 	  yy_symbol_print (stderr, yystos[yys->yylrState],
 			   NULL]b4_location_if([, &yys->yyloc])[]b4_user_args[);
 	  YYFPRINTF (stderr, "\n");
@@ -1666,9 +1669,14 @@ yypreference (yySemanticOption* y0, yySemanticOption* y1)
 }
 
 static YYRESULTTAG yyresolveValue (yyGLRState* yys,
-				   yyGLRStack* yystackp, YYSTYPE* yyvalp,
-				   YYLTYPE* yylocp]b4_user_formals[);
+				   yyGLRStack* yystackp]b4_user_formals[);
+
 
+/** Resolve the previous N states starting at and including state S.  If result
+ *  != yyok, some states may have been left unresolved possibly with empty
+ *  semantic option chains.  Regardless of whether result = yyok, each state
+ *  has been left with consistent data so that yydestroyGLRState can be invoked
+ *  if necessary.  */
 static YYRESULTTAG
 yyresolveStates (yyGLRState* yys, int yyn,
 		 yyGLRStack* yystackp]b4_user_formals[)
@@ -1678,22 +1686,15 @@ yyresolveStates (yyGLRState* yys, int yyn,
       YYASSERT (yys->yypred);
       YYCHK (yyresolveStates (yys->yypred, yyn-1, yystackp]b4_user_args[));
       if (! yys->yyresolved)
-	{
-	  YYSTYPE yysval;
-	  YYRESULTTAG yyflag = yyresolveValue (yys, yystackp, &yysval,
-					       &yys->yyloc]b4_user_args[);
-	  if (yyflag != yyok)
-	    {
-	      yys->yysemantics.yyfirstVal = NULL;
-	      return yyflag;
-	    }
-	  yys->yysemantics.yysval = yysval;
-	  yys->yyresolved = yytrue;
-	}
+	YYCHK (yyresolveValue (yys, yystackp]b4_user_args[));
     }
   return yyok;
 }
 
+/** Resolve the states for the RHS of OPT, perform its user action, and return
+ *  the semantic value and location.  Regardless of whether result = yyok, all
+ *  RHS states have been destroyed (assuming the user action destroys all RHS
+ *  semantic values if invoked).  */
 static YYRESULTTAG
 yyresolveAction (yySemanticOption* yyopt, yyGLRStack* yystackp,
 		 YYSTYPE* yyvalp, YYLTYPE* yylocp]b4_user_formals[)
@@ -1703,10 +1704,18 @@ yyresolveAction (yySemanticOption* yyopt, yyGLRStack* yystackp,
   int yychar_current;
   YYSTYPE yylval_current;
   YYLTYPE yylloc_current;
-  YYRESULTTAG yyresult;
+  YYRESULTTAG yyflag;
 
   yynrhs = yyrhsLength (yyopt->yyrule);
-  YYCHK (yyresolveStates (yyopt->yystate, yynrhs, yystackp]b4_user_args[));
+  yyflag = yyresolveStates (yyopt->yystate, yynrhs, yystackp]b4_user_args[);
+  if (yyflag != yyok)
+    {
+      yyGLRState *yys;
+      for (yys = yyopt->yystate; yynrhs > 0; yys = yys->yypred, yynrhs -= 1)
+	yydestroyGLRState ("Cleanup: popping", yys]b4_user_args[);
+      return yyflag;
+    }
+
   yyrhsVals[YYMAXRHS + YYMAXLEFT].yystate.yypred = yyopt->yystate;]b4_location_if([[
   if (yynrhs == 0)
     /* Set default location.  */
@@ -1717,13 +1726,13 @@ yyresolveAction (yySemanticOption* yyopt, yyGLRStack* yystackp,
   yychar = yyopt->yyrawchar;
   yylval = yyopt->yyval;
   yylloc = yyopt->yyloc;
-  yyresult = yyuserAction (yyopt->yyrule, yynrhs,
+  yyflag = yyuserAction (yyopt->yyrule, yynrhs,
 			   yyrhsVals + YYMAXRHS + YYMAXLEFT - 1,
 			   yyvalp, yylocp, yystackp]b4_user_args[);
   yychar = yychar_current;
   yylval = yylval_current;
   yylloc = yylloc_current;
-  return yyresult;
+  return yyflag;
 }
 
 #if YYDEBUG
@@ -1797,15 +1806,21 @@ yyreportAmbiguity (yySemanticOption* yyx0, yySemanticOption* yyx1,
 
 
 /** Resolve the ambiguity represented in state S, perform the indicated
- *  actions, and return the result.  */
+ *  actions, and set the semantic value of S.  If result != yyok, the chain of
+ *  semantic options in S has been cleared instead or it has been left
+ *  unmodified except that redundant options may have been removed.  Regardless
+ *  of whether result = yyok, S has been left with consistent data so that
+ *  yydestroyGLRState can be invoked if necessary.  */
 static YYRESULTTAG
-yyresolveValue (yyGLRState* yys, yyGLRStack* yystackp, YYSTYPE* yyvalp,
-		YYLTYPE* yylocp]b4_user_formals[)
+yyresolveValue (yyGLRState* yys, yyGLRStack* yystackp]b4_user_formals[)
 {
   yySemanticOption* yyoptionList = yys->yysemantics.yyfirstVal;
   yySemanticOption* yybest;
   yySemanticOption** yypp;
   yybool yymerge;
+  YYSTYPE yysval;
+  YYRESULTTAG yyflag;
+  YYLTYPE *yylocp = &yys->yyloc;
 
   yybest = yyoptionList;
   yymerge = yyfalse;
@@ -1848,29 +1863,39 @@ yyresolveValue (yyGLRState* yys, yyGLRStack* yystackp, YYSTYPE* yyvalp,
     {
       yySemanticOption* yyp;
       int yyprec = yydprec[yybest->yyrule];
-      YYCHK (yyresolveAction (yybest, yystackp, yyvalp, yylocp]b4_user_args[));
-      for (yyp = yybest->yynext; yyp != NULL; yyp = yyp->yynext)
-	{
-	  if (yyprec == yydprec[yyp->yyrule])
-	    {
-	      YYSTYPE yyval1;
-	      YYLTYPE yydummy;
-	      YYRESULTTAG yyflag = yyresolveAction (yyp, yystackp, &yyval1,
-						    &yydummy]b4_user_args[);
-	      if (yyflag != yyok)
-		{
-		  yydestruct ("Cleanup: discarding merged value",
-			      yystos[yys->yylrState],
-			      yyvalp]b4_location_if([, yylocp])[]b4_user_args[);
-		  return yyflag;
-		}
-	      yyuserMerge (yymerger[yyp->yyrule], yyvalp, &yyval1);
-	    }
-	}
-      return yyok;
+      yyflag = yyresolveAction (yybest, yystackp, &yysval,
+				yylocp]b4_user_args[);
+      if (yyflag == yyok)
+	for (yyp = yybest->yynext; yyp != NULL; yyp = yyp->yynext)
+	  {
+	    if (yyprec == yydprec[yyp->yyrule])
+	      {
+		YYSTYPE yysval_other;
+		YYLTYPE yydummy;
+		yyflag = yyresolveAction (yyp, yystackp, &yysval_other,
+					  &yydummy]b4_user_args[);
+		if (yyflag != yyok)
+		  {
+		    yydestruct ("Cleanup: discarding incompletely merged value for",
+				yystos[yys->yylrState],
+				&yysval]b4_location_if([, yylocp])[]b4_user_args[);
+		    break;
+		  }
+		yyuserMerge (yymerger[yyp->yyrule], &yysval, &yysval_other);
+	      }
+	  }
+    }
+  else
+    yyflag = yyresolveAction (yybest, yystackp, &yysval, yylocp]b4_user_args[);
+
+  if (yyflag == yyok)
+    {
+      yys->yyresolved = yytrue;
+      yys->yysemantics.yysval = yysval;
     }
   else
-    return yyresolveAction (yybest, yystackp, yyvalp, yylocp]b4_user_args[);
+    yys->yysemantics.yyfirstVal = NULL;
+  return yyflag;
 }
 
 static YYRESULTTAG
