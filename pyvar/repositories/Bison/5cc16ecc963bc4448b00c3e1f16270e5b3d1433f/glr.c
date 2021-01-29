@@ -197,6 +197,8 @@ typedef struct YYLTYPE
   int first_column;
   int last_line;
   int last_column;
+],[
+  char yydummy;
 ])[
 } YYLTYPE;
 # define YYLTYPE_IS_DECLARED 1
@@ -264,7 +266,7 @@ b4_syncline([@oline@], [@ofile@])
 #define YYUNDEFTOK  ]b4_undef_token_number[
 #define YYMAXUTOK   ]b4_user_token_number_max[
 
-#define YYTRANSLATE(YYX) 						\
+#define YYTRANSLATE(YYX)						\
   ((YYX <= 0) ? YYEOF :							\
    (unsigned)(YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)
 
@@ -419,7 +421,7 @@ static const ]b4_int_type_for([b4_stos])[ yystos[] =
 #endif
 ]],[
 #ifndef YYLLOC_DEFAULT
-# define YYLLOC_DEFAULT(yyCurrent, yyRhs, YYN) 
+# define YYLLOC_DEFAULT(yyCurrent, yyRhs, YYN)
 #endif
 ])[
 
@@ -446,7 +448,7 @@ static const int YYEMPTY = -2;
 typedef enum { yyok, yyaccept, yyabort, yyerr } YYRESULTTAG;
 
 #define YYCHK(YYE)							     \
-   do { YYRESULTTAG yyflag = YYE; if (yyflag != yyok) return yyflag; } 	     \
+   do { YYRESULTTAG yyflag = YYE; if (yyflag != yyok) return yyflag; }	     \
    while (0)
 
 #if YYDEBUG
@@ -474,7 +476,7 @@ do {								\
   if (yydebug)							\
     {								\
       YYFPRINTF (stderr, "%s ", Title);				\
-      yysymprint (stderr, 					\
+      yysymprint (stderr,					\
                   Token, Value]b4_location_if([, Location])[);	\
       YYFPRINTF (stderr, "\n");					\
     }								\
@@ -682,7 +684,7 @@ yyuserAction (yyRuleNum yyn, int yyrhslen, yyGLRStackItem* yyvsp,
 # undef YYABORT
 # define YYABORT return yyabort
 # undef YYERROR
-# define YYERROR do { yystack->yyerrState = 0; return yyerr; } while (0)
+# define YYERROR return yyerrok, yyerr
 # undef YYRECOVERING
 # define YYRECOVERING (yystack->yyerrState != 0)
 # undef yyclearin
@@ -691,10 +693,8 @@ yyuserAction (yyRuleNum yyn, int yyrhslen, yyGLRStackItem* yyvsp,
 # define YYFILL(N) yyfill (yyvsp, &yylow, N, yynormal)
 # undef YYBACKUP
 # define YYBACKUP(Token, Value)						     \
-  do {									     \
-    yyerror (]b4_yyerror_args["syntax error: cannot back up");		     \
-    YYERROR;								     \
-  } while (0)
+  return yyerror (]b4_yyerror_args["syntax error: cannot back up"),	     \
+	 yyerrok, yyerr
 
   yylow = 1;
   if (yyrhslen == 0)
@@ -1080,7 +1080,7 @@ yyglrShiftDefer (yyGLRStack* yystack, int yyk, yyStateNum yylrState,
  *  for userAction. */
 static inline YYRESULTTAG
 yydoAction (yyGLRStack* yystack, int yyk, yyRuleNum yyrule,
- 	    YYSTYPE* yyvalp, YYLTYPE* yylocp]b4_user_formals[)
+	    YYSTYPE* yyvalp, YYLTYPE* yylocp]b4_user_formals[)
 {
   int yynrhs = yyrhsLength (yyrule);
 
@@ -1101,7 +1101,7 @@ yydoAction (yyGLRStack* yystack, int yyk, yyRuleNum yyrule,
       int yyi;
       yyGLRState* yys;
       yyGLRStackItem yyrhsVals[YYMAXRHS + YYMAXLEFT + 1];
-      yys = yyrhsVals[YYMAXRHS + YYMAXLEFT].yystate.yypred 
+      yys = yyrhsVals[YYMAXRHS + YYMAXLEFT].yystate.yypred
 	= yystack->yytops.yystates[yyk];
       for (yyi = 0; yyi < yynrhs; yyi += 1)
 	{
@@ -1348,7 +1348,7 @@ yyresolveAction (yySemanticOption* yyopt, yyGLRStack* yystack,
   yynrhs = yyrhsLength (yyopt->yyrule);
   YYCHK (yyresolveStates (yyopt->yystate, yynrhs, yystack]b4_user_args[));
   yyrhsVals[YYMAXRHS + YYMAXLEFT].yystate.yypred = yyopt->yystate;
-  return yyuserAction (yyopt->yyrule, yynrhs, 
+  return yyuserAction (yyopt->yyrule, yynrhs,
 		       yyrhsVals + YYMAXRHS + YYMAXLEFT - 1,
 		       yyvalp, yylocp, yystack]b4_user_args[);
 }
@@ -1756,10 +1756,10 @@ yyrecoverSyntaxError (yyGLRStack* yystack,
 	    }
 	}
       YYDSYMPRINTF ("Error: popping",
- 		    yystos[yys->yylrState],
- 		    &yys->yysemantics.yysval, &yys->yyloc);
+		    yystos[yys->yylrState],
+		    &yys->yysemantics.yysval, &yys->yyloc);
       yydestruct (yystos[yys->yylrState],
- 	          &yys->yysemantics.yysval]b4_location_if([, &yys->yyloc])[);
+	          &yys->yysemantics.yysval]b4_location_if([, &yys->yyloc])[);
       yystack->yytops.yystates[0] = yys->yypred;
       yystack->yynextFree -= 1;
       yystack->yyspaceLeft += 1;
@@ -1948,7 +1948,7 @@ yypstack (yyGLRStack* yystack, int yyk)
   yypstates (yystack->yytops.yystates[yyk]);
 }
 
-#define YYINDEX(YYX) 							     \
+#define YYINDEX(YYX)							     \
     ((YYX) == NULL ? -1 : (yyGLRStackItem*) (YYX) - yystack->yyitems)
 
 
@@ -2016,6 +2016,8 @@ b4_location_if([
   int first_column;
   int last_line;
   int last_column;
+],[
+  char yydummy;
 ])
 } YYLTYPE;
 # define YYLTYPE_IS_DECLARED 1
