@@ -310,7 +310,7 @@ static const short yydefact[] =
   ]b4_defact[
 };
 
-/* YYPGOTO[NTERM-NUM]. */
+/* YYPDEFGOTO[NTERM-NUM]. */
 static const short yydefgoto[] =
 {
   ]b4_defgoto[
@@ -318,7 +318,8 @@ static const short yydefgoto[] =
 
 /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
    STATE-NUM.  */
-static const short yypact[] =
+#define YYPACT_NINF ]b4_pact_ninf[
+static const ]b4_sint_type(b4_pact_max)[ yypact[] =
 {
   ]b4_pact[
 };
@@ -332,7 +333,8 @@ static const short yypgoto[] =
 /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
    positive, shift that token.  If negative, reduce the rule which
    number is the opposite.  If zero, do what YYDEFACT says.  */
-static const short yytable[] =
+#define YYTABLE_NINF ]b4_table_ninf[
+static const ]b4_sint_type(b4_table_max)[ yytable[] =
 {
   ]b4_table[
 };
@@ -389,10 +391,10 @@ int yyparse (void);
 #define YYRHSLOC(yyRhs,YYK) (yyRhs[YYK].yystate.yyloc)
 
 #ifndef YYLLOC_DEFAULT
-# define YYLLOC_DEFAULT(yyCurrent, yyRhs, YYN)           \
-  yyCurrent.yyfirst_line   = YYRHSLOC(yyRhs,1).yyfirst_line;      \
-  yyCurrent.yyfirst_column = YYRHSLOC(yyRhs,1).yyfirst_column;    \
-  yyCurrent.yylast_line    = YYRHSLOC(yyRhs,YYN).yylast_line;       \
+# define YYLLOC_DEFAULT(yyCurrent, yyRhs, YYN)			\
+  yyCurrent.yyfirst_line   = YYRHSLOC(yyRhs,1).yyfirst_line;	\
+  yyCurrent.yyfirst_column = YYRHSLOC(yyRhs,1).yyfirst_column;	\
+  yyCurrent.yylast_line    = YYRHSLOC(yyRhs,YYN).yylast_line;	\
   yyCurrent.yylast_column  = YYRHSLOC(yyRhs,YYN).yylast_column;
 #endif
 
@@ -676,7 +678,7 @@ yylhsNonterm (yyRuleNum yyrule)
 static inline bool
 yyisDefaultedState (yyStateNum yystate)
 {
-  return yypact[yystate] == YYFLAG;
+  return yypact[yystate] == YYPACT_NINF;
 }
 
 /** The default reduction for STATE, assuming it has one. */
@@ -731,7 +733,7 @@ yyisShiftAction (int yyaction)
 static inline bool
 yyisErrorAction (int yyaction)
 {
-  return yyaction == 0 || yyaction == YYFLAG;
+  return yyaction == 0 || yyaction == YYPACT_NINF;
 }
 
 				/* GLRStates */
@@ -1497,7 +1499,7 @@ yyreportParseError (yyGLRStack* yystack, YYSTYPE* yylvalp, YYLTYPE* yyllocp)
       char* yyp;
       char* yymsg;
       yyn = yypact[yystack->yytops.yystates[0]->yylrState];
-      if (yyn > YYFLAG && yyn < YYLAST)
+      if (YYPACT_NINF < yyn && yyn < YYLAST)
 	{
 	  yycount = 0;
 	  /* Start YYX at -YYN if negative to avoid negative indexes in
@@ -1563,7 +1565,7 @@ yyrecoverParseError (yyGLRStack* yystack, YYSTYPE* yylvalp, YYLTYPE* yyllocp)
 	*yytokenp = YYTRANSLATE (yychar);
 	YYDPRINTF ((stderr, "Read token %s\n", yytokenName (*yytokenp)));
 	yyj = yypact[yystack->yytops.yystates[0]->yylrState];
-	if (yyj == YYFLAG)
+	if (yyj == YYPACT_NINF)
 	  /* Something's not right; we shouldn't be here */
 	  yyFail (yystack, NULL);
 	yyj += *yytokenp;
@@ -1572,7 +1574,7 @@ yyrecoverParseError (yyGLRStack* yystack, YYSTYPE* yylvalp, YYLTYPE* yyllocp)
 	    if (yydefact[yystack->yytops.yystates[0]->yylrState] != 0)
 	      return;
 	  }
-	else if (yytable[yyj] != 0 && yytable[yyj] != YYFLAG)
+	else if (yytable[yyj] != 0 && yytable[yyj] != YYTABLE_NINF)
 	  return;
       } while (yytrue);
     }
@@ -1592,7 +1594,7 @@ yyrecoverParseError (yyGLRStack* yystack, YYSTYPE* yylvalp, YYLTYPE* yyllocp)
   while (yystack->yytops.yystates[0] != NULL)
     {
       yyj = yypact[yystack->yytops.yystates[0]->yylrState] + YYTERROR;
-      if (yyj != YYFLAG + YYTERROR && yyj >= 0 && yyj <= YYLAST &&
+      if (yyj != YYPACT_NINF + YYTERROR && yyj >= 0 && yyj <= YYLAST &&
 	  yycheck[yyj] == YYTERROR && yyisShiftAction (yytable[yyj]))
 	{
 	  yyglrShift (yystack, 0, yytable[yyj],
