@@ -383,9 +383,16 @@ static const ]b4_int_type_for([b4_check])[ yycheck[] =
 
 
 /* Prevent warning if -Wmissing-prototypes.  */
-]b4_c_ansi_function_decl([yyparse], [int], b4_parse_param)[
+]b4_c_ansi_function_decl([yyparse], [int], b4_parse_param)
 
-/* Error token number */
+m4_ifset([b4_parse_param],
+[#define YY_USER_FORMALS , b4_c_ansi_formals(b4_parse_param)
+#define YY_USER_ARGS    , b4_c_args(b4_parse_param)],
+[#define YY_USER_FORMALS
+#define YY_USER_ARGS])
+
+
+[/* Error token number */
 #define YYTERROR 1
 
 /* YYLLOC_DEFAULT -- Compute the default location (before the actions
@@ -581,7 +588,8 @@ yytokenName (yySymbol yytoken)
  *  yyerr for YYERROR, yyabort for YYABORT. */
 static YYRESULTTAG
 yyuserAction (yyRuleNum yyn, int yyrhslen, yyGLRStackItem* yyvsp,
-	      YYSTYPE* yyvalp, YYLTYPE* yylocp, yyGLRStack* yystack)
+	      YYSTYPE* yyvalp, YYLTYPE* yylocp, yyGLRStack* yystack
+	      YY_USER_FORMALS)
 {
   /* Avoid `unused' warnings in there are no $n. */
   (void) yystack;
@@ -983,7 +991,7 @@ yyglrShiftDefer (yyGLRStack* yystack, int yyk, yyStateNum yylrState,
  *  for userAction. */
 static inline int
 yydoAction (yyGLRStack* yystack, int yyk, yyRuleNum yyrule,
- 	    YYSTYPE* yyvalp, YYLTYPE* yylocp)
+ 	    YYSTYPE* yyvalp, YYLTYPE* yylocp YY_USER_FORMALS)
 {
   int yynrhs = yyrhsLength (yyrule);
 
@@ -1005,7 +1013,8 @@ yydoAction (yyGLRStack* yystack, int yyk, yyRuleNum yyrule,
 	  *yyvalp = rhs[1-yynrhs].yystate.yysemantics.yysval;
 	  *yylocp = rhs[1-yynrhs].yystate.yyloc;
 	}
-      return yyuserAction (yyrule, yynrhs, rhs, yyvalp, yylocp, yystack);
+      return yyuserAction (yyrule, yynrhs, rhs,
+			   yyvalp, yylocp, yystack YY_USER_ARGS);
     }
   else
     {
@@ -1033,10 +1042,36 @@ yydoAction (yyGLRStack* yystack, int yyk, yyRuleNum yyrule,
 	  *yylocp = yyrhsVals[0].yystate.yyloc;
 	}
       return yyuserAction (yyrule, yynrhs, yyrhsVals + (yynrhs-1),
-			   yyvalp, yylocp, yystack);
+			   yyvalp, yylocp, yystack YY_USER_ARGS);
     }
 }
 
+#if !YYDEBUG
+# define YY_REDUCE_PRINT(K, Rule)
+#else
+# define YY_REDUCE_PRINT(K, Rule)	\
+do {					\
+  if (yydebug)				\
+    yy_reduce_print (K, Rule);		\
+} while (0)
+
+/*----------------------------------------------------------.
+| Report that the RULE is going to be reduced on stack #K.  |
+`----------------------------------------------------------*/
+
+static inline void
+yy_reduce_print (size_t yyk, yyRuleNum yyrule)
+{
+  int yyi;
+  YYDPRINTF ((stderr, "Reducing stack %d by rule %d (line %d),",
+	      yyk, yyrule - 1, yyrline[yyrule]));
+  /* Print the symbols being reduced, and their result.  */
+  for (yyi = yyprhs[yyrule]; 0 <= yyrhs[yyi]; yyi++)
+    YYFPRINTF (stderr, "%s ", yytokenName (yyrhs[yyi]));
+  YYFPRINTF (stderr, " -> %s\n", yytokenName (yyr1[yyrule]));
+}
+#endif
+
 /** Pop items off stack #K of STACK according to grammar rule RULE,
  *  and push back on the resulting nonterminal symbol.  Perform the
  *  semantic action associated with RULE and store its value with the
@@ -1050,7 +1085,7 @@ yydoAction (yyGLRStack* yystack, int yyk, yyRuleNum yyrule,
  */
 static inline YYRESULTTAG
 yyglrReduce (yyGLRStack* yystack, size_t yyk, yyRuleNum yyrule,
-             bool yyforceEval)
+             bool yyforceEval YY_USER_FORMALS)
 {
   size_t yyposn = yystack->yytops.yystates[yyk]->yyposn;
 
@@ -1059,19 +1094,8 @@ yyglrReduce (yyGLRStack* yystack, size_t yyk, yyRuleNum yyrule,
       YYSTYPE yysval;
       YYLTYPE yyloc;
 
-#if YYDEBUG
-      if (yydebug)
-	{
-	  int yyi;
-	  YYDPRINTF ((stderr, "Reducing stack %d by rule %d (line %d),",
-		      yyk, yyrule - 1, yyrline[yyrule]));
-	  /* Print the symbols being reduced, and their result.  */
-	  for (yyi = yyprhs[yyrule]; 0 <= yyrhs[yyi]; yyi++)
-	    YYFPRINTF (stderr, "%s ", yytokenName (yyrhs[yyi]));
-	  YYFPRINTF (stderr, " -> %s\n", yytokenName (yyr1[yyrule]));
-	}
-#endif
-      YYCHK (yydoAction (yystack, yyk, yyrule, &yysval, &yyloc));
+      YY_REDUCE_PRINT (yyk, yyrule);
+      YYCHK (yydoAction (yystack, yyk, yyrule, &yysval, &yyloc YY_USER_ARGS));
       yyglrShift (yystack, yyk,
 		  yyLRgotoState (yystack->yytops.yystates[yyk]->yylrState,
 				 yylhsNonterm (yyrule)),
@@ -1217,22 +1241,23 @@ yypreference (yySemanticOption* y0, yySemanticOption* y1)
 
 static YYRESULTTAG yyresolveValue (yySemanticOption* yyoptionList,
 				   yyGLRStack* yystack, YYSTYPE* yyvalp,
-				   YYLTYPE* yylocp);
+				   YYLTYPE* yylocp YY_USER_FORMALS);
 
 static YYRESULTTAG
-yyresolveStates (yyGLRState* yys, int yyn, yyGLRStack* yystack)
+yyresolveStates (yyGLRState* yys, int yyn, yyGLRStack* yystack YY_USER_FORMALS)
 {
   YYRESULTTAG yyflag;
   if (0 < yyn)
     {
       assert (yys->yypred != NULL);
-      yyflag = yyresolveStates (yys->yypred, yyn-1, yystack);
+      yyflag = yyresolveStates (yys->yypred, yyn-1, yystack YY_USER_ARGS);
       if (yyflag != yyok)
 	return yyflag;
       if (! yys->yyresolved)
 	{
 	  yyflag = yyresolveValue (yys->yysemantics.yyfirstVal, yystack,
-			       &yys->yysemantics.yysval, &yys->yyloc);
+				   &yys->yysemantics.yysval, &yys->yyloc
+				   YY_USER_ARGS);
 	  if (yyflag != yyok)
 	    return yyflag;
 	  yys->yyresolved = yytrue;
@@ -1243,14 +1268,14 @@ yyresolveStates (yyGLRState* yys, int yyn, yyGLRStack* yystack)
 
 static YYRESULTTAG
 yyresolveAction (yySemanticOption* yyopt, yyGLRStack* yystack,
-	         YYSTYPE* yyvalp, YYLTYPE* yylocp)
+	         YYSTYPE* yyvalp, YYLTYPE* yylocp YY_USER_FORMALS)
 {
   yyGLRStackItem yyrhsVals[YYMAXRHS];
   int yynrhs, yyi;
   yyGLRState* yys;
 
   yynrhs = yyrhsLength (yyopt->yyrule);
-  YYCHK (yyresolveStates (yyopt->yystate, yynrhs, yystack));
+  YYCHK (yyresolveStates (yyopt->yystate, yynrhs, yystack YY_USER_ARGS));
   for (yyi = yynrhs-1, yys = yyopt->yystate; 0 <= yyi;
        yyi -= 1, yys = yys->yypred)
     {
@@ -1260,7 +1285,7 @@ yyresolveAction (yySemanticOption* yyopt, yyGLRStack* yystack,
       yyrhsVals[yyi].yystate.yyloc = yys->yyloc;
     }
   return yyuserAction (yyopt->yyrule, yynrhs, yyrhsVals + (yynrhs-1),
-		       yyvalp, yylocp, yystack);
+		       yyvalp, yylocp, yystack YY_USER_ARGS);
 }
 
 #if YYDEBUG
@@ -1275,7 +1300,8 @@ static yyGLRState YYLEFTMOST_STATE =
     }
   };
 
-static void yyreportTree (yySemanticOption* yyx, int yyindent)
+static void
+yyreportTree (yySemanticOption* yyx, int yyindent)
 {
   int yynrhs = yyrhsLength (yyx->yyrule);
   int yyi;
@@ -1339,7 +1365,7 @@ yyreportAmbiguity (yySemanticOption* yyx0, yySemanticOption* yyx1,
  *  actions, and return the result. */
 static YYRESULTTAG
 yyresolveValue (yySemanticOption* yyoptionList, yyGLRStack* yystack,
-		YYSTYPE* yyvalp, YYLTYPE* yylocp)
+		YYSTYPE* yyvalp, YYLTYPE* yylocp YY_USER_FORMALS)
 {
   yySemanticOption* yybest;
   yySemanticOption* yyp;
@@ -1372,25 +1398,25 @@ yyresolveValue (yySemanticOption* yyoptionList, yyGLRStack* yystack,
   if (yymerge)
     {
       int yyprec = yydprec[yybest->yyrule];
-      YYCHK (yyresolveAction (yybest, yystack, yyvalp, yylocp));
+      YYCHK (yyresolveAction (yybest, yystack, yyvalp, yylocp YY_USER_ARGS));
       for (yyp = yybest->yynext; yyp != NULL; yyp = yyp->yynext)
 	{
 	  if (yyprec == yydprec[yyp->yyrule])
 	    {
 	      YYSTYPE yyval1;
 	      YYLTYPE yydummy;
-	      YYCHK (yyresolveAction (yyp, yystack, &yyval1, &yydummy));
+	      YYCHK (yyresolveAction (yyp, yystack, &yyval1, &yydummy YY_USER_ARGS));
 	      *yyvalp = yyuserMerge (yymerger[yyp->yyrule], yyvalp, &yyval1);
 	    }
 	}
       return yyok;
     }
   else
-    return yyresolveAction (yybest, yystack, yyvalp, yylocp);
+    return yyresolveAction (yybest, yystack, yyvalp, yylocp YY_USER_ARGS);
 }
 
 static YYRESULTTAG
-yyresolveStack (yyGLRStack* yystack)
+yyresolveStack (yyGLRStack* yystack YY_USER_FORMALS)
 {
   if (yystack->yysplitPoint != NULL)
     {
@@ -1401,7 +1427,8 @@ yyresolveStack (yyGLRStack* yystack)
 	   yys != yystack->yysplitPoint;
 	   yys = yys->yypred, yyn += 1)
 	;
-      YYCHK (yyresolveStates (yystack->yytops.yystates[0], yyn, yystack));
+      YYCHK (yyresolveStates (yystack->yytops.yystates[0], yyn, yystack
+			      YY_USER_ARGS));
     }
   return yyok;
 }
@@ -1438,7 +1465,8 @@ yycompressStack (yyGLRStack* yystack)
 
 static YYRESULTTAG
 yyprocessOneStack (yyGLRStack* yystack, int yyk,
-	           size_t yyposn, YYSTYPE* yylvalp, YYLTYPE* yyllocp)
+	           size_t yyposn, YYSTYPE* yylvalp, YYLTYPE* yyllocp
+		   YY_USER_FORMALS)
 {
   int yyaction;
   const short* yyconflicts;
@@ -1459,7 +1487,7 @@ yyprocessOneStack (yyGLRStack* yystack, int yyk,
 	      yymarkStackDeleted (yystack, yyk);
 	      return yyok;
 	    }
-	  YYCHK (yyglrReduce (yystack, yyk, yyrule, yyfalse));
+	  YYCHK (yyglrReduce (yystack, yyk, yyrule, yyfalse YY_USER_ARGS));
 	}
       else
 	{
@@ -1478,9 +1506,10 @@ yyprocessOneStack (yyGLRStack* yystack, int yyk,
 	      int yynewStack = yysplitStack (yystack, yyk);
 	      YYDPRINTF ((stderr, "Splitting off stack %d from %d.\n",
 			  yynewStack, yyk));
-	      YYCHK (yyglrReduce (yystack, yynewStack, *yyconflicts, yyfalse));
+	      YYCHK (yyglrReduce (yystack, yynewStack,
+				  *yyconflicts, yyfalse YY_USER_ARGS));
 	      YYCHK (yyprocessOneStack (yystack, yynewStack, yyposn,
-					yylvalp, yyllocp));
+					yylvalp, yyllocp YY_USER_ARGS));
 	      yyconflicts += 1;
 	    }
 
@@ -1500,7 +1529,7 @@ yyprocessOneStack (yyGLRStack* yystack, int yyk,
 	      break;
 	    }
 	  else
-	    YYCHK (yyglrReduce (yystack, yyk, -yyaction, yyfalse));
+	    YYCHK (yyglrReduce (yystack, yyk, -yyaction, yyfalse YY_USER_ARGS));
 	}
     }
   return yyok;
@@ -1704,7 +1733,7 @@ yyrecoverParseError (yyGLRStack* yystack, YYSTYPE* yylvalp, YYLTYPE* yyllocp)
 		  yyreportParseError (&yystack, yylvalp, yyllocp);
 		  goto yyuser_error;
 		}
-	      YYCHK1 (yyglrReduce (&yystack, 0, yyrule, yytrue));
+	      YYCHK1 (yyglrReduce (&yystack, 0, yyrule, yytrue YY_USER_ARGS));
 	    }
 	  else
 	    {
@@ -1738,7 +1767,7 @@ yyrecoverParseError (yyGLRStack* yystack, YYSTYPE* yylvalp, YYLTYPE* yyllocp)
 		  goto yyuser_error;
 		}
 	      else
-		YYCHK1 (yyglrReduce (&yystack, 0, -yyaction, yytrue));
+		YYCHK1 (yyglrReduce (&yystack, 0, -yyaction, yytrue YY_USER_ARGS));
 	    }
 	}
 
@@ -1748,7 +1777,7 @@ yyrecoverParseError (yyGLRStack* yystack, YYSTYPE* yylvalp, YYLTYPE* yyllocp)
 	  int yyn = yystack.yytops.yysize;
 	  for (yys = 0; yys < yyn; yys += 1)
 	    YYCHK1 (yyprocessOneStack (&yystack, yys, yyposn,
-				       yylvalp, yyllocp));
+				       yylvalp, yyllocp YY_USER_ARGS));
 	  yytoken = YYEMPTY;
 	  yyposn += 1;
 	  yyremoveDeletes (&yystack);
@@ -1757,14 +1786,14 @@ yyrecoverParseError (yyGLRStack* yystack, YYSTYPE* yylvalp, YYLTYPE* yyllocp)
 	      yyundeleteLastStack (&yystack);
 	      if (yystack.yytops.yysize == 0)
 		yyFail (&yystack, "parse error");
-	      YYCHK1 (yyresolveStack (&yystack));
+	      YYCHK1 (yyresolveStack (&yystack YY_USER_ARGS));
 	      YYDPRINTF ((stderr, "Returning to deterministic operation.\n"));
 	      yyreportParseError (&yystack, yylvalp, yyllocp);
 	      goto yyuser_error;
 	    }
 	  else if (yystack.yytops.yysize == 1)
 	    {
-	      YYCHK1 (yyresolveStack (&yystack));
+	      YYCHK1 (yyresolveStack (&yystack YY_USER_ARGS));
 	      YYDPRINTF ((stderr, "Returning to deterministic operation.\n"));
 	      yycompressStack (&yystack);
 	      break;
@@ -1850,7 +1879,6 @@ yypdumpstack (yyGLRStack* yystack)
 	     (long) YYINDEX (yystack->yytops.yystates[yyi]));
   fprintf (stderr, "\n");
 }
-
 ]
 
 b4_epilogue
