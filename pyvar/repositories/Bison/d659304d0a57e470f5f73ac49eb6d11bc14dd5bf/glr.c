@@ -1612,7 +1612,7 @@ yypreference (yySemanticOption* y0, yySemanticOption* y1)
   return 0;
 }
 
-static YYRESULTTAG yyresolveValue (yySemanticOption* yyoptionList,
+static YYRESULTTAG yyresolveValue (yyGLRState* yys,
 				   yyGLRStack* yystackp, YYSTYPE* yyvalp,
 				   YYLTYPE* yylocp]b4_user_formals[);
 
@@ -1620,20 +1620,21 @@ static YYRESULTTAG
 yyresolveStates (yyGLRState* yys, int yyn,
 		 yyGLRStack* yystackp]b4_user_formals[)
 {
-  YYRESULTTAG yyflag;
   if (0 < yyn)
     {
       YYASSERT (yys->yypred);
-      yyflag = yyresolveStates (yys->yypred, yyn-1, yystackp]b4_user_args[);
-      if (yyflag != yyok)
-	return yyflag;
+      YYCHK (yyresolveStates (yys->yypred, yyn-1, yystackp]b4_user_args[));
       if (! yys->yyresolved)
 	{
-	  yyflag = yyresolveValue (yys->yysemantics.yyfirstVal, yystackp,
-				   &yys->yysemantics.yysval, &yys->yyloc
-				  ]b4_user_args[);
+	  YYSTYPE yysval;
+	  YYRESULTTAG yyflag = yyresolveValue (yys, yystackp, &yysval,
+					       &yys->yyloc]b4_user_args[);
 	  if (yyflag != yyok)
-	    return yyflag;
+	    {
+	      yys->yysemantics.yyfirstVal = NULL;
+	      return yyflag;
+	    }
+	  yys->yysemantics.yysval = yysval;
 	  yys->yyresolved = yytrue;
 	}
     }
@@ -1728,12 +1729,13 @@ yyreportAmbiguity (yySemanticOption* yyx0, yySemanticOption* yyx1,
 }
 
 
-/** Resolve the ambiguity represented by OPTIONLIST, perform the indicated
+/** Resolve the ambiguity represented in state S, perform the indicated
  *  actions, and return the result.  */
 static YYRESULTTAG
-yyresolveValue (yySemanticOption* yyoptionList, yyGLRStack* yystackp,
-		YYSTYPE* yyvalp, YYLTYPE* yylocp]b4_user_formals[)
+yyresolveValue (yyGLRState* yys, yyGLRStack* yystackp, YYSTYPE* yyvalp,
+		YYLTYPE* yylocp]b4_user_formals[)
 {
+  yySemanticOption* yyoptionList = yys->yysemantics.yyfirstVal;
   yySemanticOption* yybest;
   yySemanticOption** yypp;
   yybool yymerge;
@@ -1786,8 +1788,15 @@ yyresolveValue (yySemanticOption* yyoptionList, yyGLRStack* yystackp,
 	    {
 	      YYSTYPE yyval1;
 	      YYLTYPE yydummy;
-	      YYCHK (yyresolveAction (yyp, yystackp, &yyval1,
-				      &yydummy]b4_user_args[));
+	      YYRESULTTAG yyflag = yyresolveAction (yyp, yystackp, &yyval1,
+						    &yydummy]b4_user_args[);
+	      if (yyflag != yyok)
+		{
+		  yydestruct ("Cleanup: discarding merged value",
+			      yystos[yys->yylrState],
+			      yyvalp]b4_location_if([, yylocp])[]b4_user_args[);
+		  return yyflag;
+		}
 	      yyuserMerge (yymerger[yyp->yyrule], yyvalp, &yyval1);
 	    }
 	}
