@@ -197,8 +197,24 @@ static YYLTYPE yyloc_default;
 #  define yyfalse 0
 #endif
 
-#if ! defined (yy__GNUC__)
-#  define inline
+/*-----------------.
+| GCC extensions.  |
+`-----------------*/
+
+#ifndef __attribute__
+/* This feature is available in gcc versions 2.5 and later.  */
+# if !defined (__GNUC__) || __GNUC__ < 2 || \
+(__GNUC__ == 2 && __GNUC_MINOR__ < 5) || __STRICT_ANSI__
+#  define __attribute__(Spec) /* empty */
+# endif
+#endif
+
+#ifndef ATTRIBUTE_UNUSED
+# define ATTRIBUTE_UNUSED __attribute__ ((__unused__))
+#endif
+
+#if ! defined (__GNUC__)
+# define inline
 #endif
 
 /* YYFINAL -- State number of the termination state. */
@@ -259,7 +275,7 @@ static const char *const yytname[] =
   ]b4_tname[
 };
 
-#define yytname_size (sizeof (yytname) / sizeof (yytname[0]))
+#define yytname_size ((int) (sizeof (yytname) / sizeof (yytname[0])))
 #endif
 
 /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
@@ -428,7 +444,8 @@ do {						\
    multiple parsers can coexist.  */
 int yydebug;
 #else /* !YYDEBUG */
-# define YYDPRINTF(Args)
+  /* Avoid empty `if' bodies.  */
+# define YYDPRINTF(Args)  {}
 #endif /* !YYDEBUG */
 
 /* YYINITDEPTH -- initial size of the parser's stacks.  */
@@ -569,6 +586,9 @@ static YYRESULTTAG
 yyuserAction (yyRuleNum yyn, int yyrhslen, yyGLRStackItem* yyvsp,
 	      YYSTYPE* yyvalp, YYLTYPE* yylocp, yyGLRStack* yystack)
 {
+  /* Avoid `unused' warnings in there are no $n. */
+  (void) yystack;
+
   if (yyrhslen == 0)
     {
       *yyvalp = yyval_default;
@@ -624,6 +644,10 @@ static YYSTYPE
 yyuserMerge (int yyn, YYSTYPE* yy0, YYSTYPE* yy1)
 {
   YYSTYPE yyval = *yy0;
+  /* `Use' the arguments. */
+  (void) yy0;
+  (void) yy1;
+
   switch (yyn)
     {
       b4_mergers
@@ -720,8 +744,9 @@ yyhasResolvedValue (yyGLRState* yystate)
   return yystate->yyresolved;
 }
 
-void yyaddDeferredAction (yyGLRStack* yystack, yyGLRState* yystate,
-			  yyGLRState* yyrhs, yyRuleNum yyrule)
+static void
+yyaddDeferredAction (yyGLRStack* yystack, yyGLRState* yystate,
+		     yyGLRState* yyrhs, yyRuleNum yyrule)
 {
   yySemanticOption* yynewItem;
   yynewItem = &yystack->yynextFree->yyoption;
@@ -882,13 +907,13 @@ yyundeleteLastStack (yyGLRStack* yystack)
 static inline void
 yyremoveDeletes (yyGLRStack* yystack)
 {
-  int yyi, yyj;
+  size_t yyi, yyj;
   yyi = yyj = 0;
   while (yyj < yystack->yytops.yysize)
     {
       if (yystack->yytops.yystates[yyi] == NULL)
 	{
-	  if (YYDEBUG && yyi == yyj)
+	  if (yyi == yyj)
 	    YYDPRINTF ((stderr, "Removing dead stacks.\n"));
 	  yystack->yytops.yysize -= 1;
 	}
@@ -1022,9 +1047,10 @@ yydoAction (yyGLRStack* yystack, int yyk, yyRuleNum yyrule,
  *  added to the options for the existing state's semantic value.
  */
 static inline YYRESULTTAG
-yyglrReduce (yyGLRStack* yystack, int yyk, yyRuleNum yyrule, bool yyforceEval)
+yyglrReduce (yyGLRStack* yystack, size_t yyk, yyRuleNum yyrule,
+             bool yyforceEval)
 {
-  int yyposn = yystack->yytops.yystates[yyk]->yyposn;
+  size_t yyposn = yystack->yytops.yystates[yyk]->yyposn;
 
   if (yyforceEval || yystack->yysplitPoint == NULL)
     {
@@ -1041,7 +1067,8 @@ yyglrReduce (yyGLRStack* yystack, int yyk, yyRuleNum yyrule, bool yyforceEval)
     }
   else
     {
-      int yyi, yyn;
+      size_t yyi;
+      int yyn;
       yyGLRState* yys, *yys0 = yystack->yytops.yystates[yyk];
       yyStateNum yynewLRState;
 
@@ -1153,23 +1180,23 @@ yymergeOptionSets (yySemanticOption* yyy0, yySemanticOption* yyy1)
  *  parsing state; return 0 if no combination is possible,
  *  1 if user-mergeable, 2 if Y0 is preferred, 3 if Y1 is preferred. */
 static int
-yypreference (yySemanticOption* yyy0, yySemanticOption* yyy1)
+yypreference (yySemanticOption* y0, yySemanticOption* y1)
 {
-  yyRuleNum yyr0 = yyy0->yyrule, yyr1 = yyy1->yyrule;
-  int yyp0 = yydprec[yyr0], yyp1 = yydprec[yyr1];
+  yyRuleNum r0 = y0->yyrule, r1 = y1->yyrule;
+  int p0 = yydprec[r0], p1 = yydprec[r1];
 
-  if (yyp0 == yyp1)
+  if (p0 == p1)
     {
-      if (yymerger[yyr0] == 0 || yymerger[yyr0] != yymerger[yyr1])
+      if (yymerger[r0] == 0 || yymerger[r0] != yymerger[r1])
 	return 0;
       else
 	return 1;
     }
-  if (yyp0 == 0 || yyp1 == 0)
+  if (p0 == 0 || p1 == 0)
     return 0;
-  if (yyp0 < yyp1)
+  if (p0 < p1)
     return 3;
-  if (yyp0 > yyp1)
+  if (p0 > p1)
     return 2;
   return 0;
 }
@@ -1269,6 +1296,10 @@ static void
 yyreportAmbiguity (yySemanticOption* yyx0, yySemanticOption* yyx1,
 		   yyGLRStack* yystack)
 {
+  /* `Unused' warnings.  */
+  (void) yyx0;
+  (void) yyx1;
+
 #if YYDEBUG
   YYFPRINTF (stderr, "Ambiguity detected.\n");
   YYFPRINTF (stderr, "Option 1,\n");
@@ -1453,13 +1484,16 @@ yyprocessOneStack (yyGLRStack* yystack, int yyk,
 static void
 yyreportParseError (yyGLRStack* yystack, YYSTYPE* yylvalp, YYLTYPE* yyllocp)
 {
-  yySymbol* const yytokenp = yystack->yytokenp;
+  /* `Unused' warnings. */
+  (void) yylvalp;
+  (void) yyllocp;
 
   if (yystack->yyerrState == 0)
     {
 #if YYERROR_VERBOSE
+      yySymbol* const yytokenp = yystack->yytokenp;
       int yyn, yyx, yycount, yysize;
-      char* yyprefix;
+      const char* yyprefix;
       char* yyp;
       char* yymsg;
       yyn = yypact[yystack->yytops.yystates[0]->yylrState];
@@ -1510,7 +1544,8 @@ static void
 yyrecoverParseError (yyGLRStack* yystack, YYSTYPE* yylvalp, YYLTYPE* yyllocp)
 {
   yySymbol* const yytokenp = yystack->yytokenp;
-  int yyk, yyj;
+  size_t yyk;
+  int yyj;
 
   if (yystack->yyerrState == 0)
     yystack->yyerrState = 3;
@@ -1717,11 +1752,14 @@ yyparse (YYPARSE_PARAM_ARG)
 }
 
 /* DEBUGGING ONLY */
+static void yypstack (yyGLRStack* yystack, int yyk) ATTRIBUTE_UNUSED;
+static void yypdumpstack (yyGLRStack* yystack) ATTRIBUTE_UNUSED;
 
-void
+static void
 yypstates (yyGLRState* yyst)
 {
-  void yy_yypstack (yyGLRState* yys)
+  static void
+  yy_yypstack (yyGLRState* yys)
     {
       if (yys->yypred == NULL)
 	fprintf (stderr, "%d@%d", yys->yylrState, yys->yyposn);
@@ -1739,7 +1777,7 @@ yypstates (yyGLRState* yyst)
   fprintf (stderr, "\n");
 }
 
-void
+static void
 yypstack (yyGLRStack* yystack, int yyk)
 {
   yypstates (yystack->yytops.yystates[yyk]);
@@ -1749,11 +1787,11 @@ yypstack (yyGLRStack* yystack, int yyk)
     ((YYX) == NULL ? -1 : (yyGLRStackItem*) (YYX) - yystack->yyitems)
 
 
-void
+static void
 yypdumpstack (yyGLRStack* yystack)
 {
   yyGLRStackItem* yyp;
-  int yyi;
+  size_t yyi;
   for (yyp = yystack->yyitems; yyp < yystack->yynextFree; yyp += 1)
     {
       fprintf (stderr, "%3d. ", yyp - yystack->yyitems);
