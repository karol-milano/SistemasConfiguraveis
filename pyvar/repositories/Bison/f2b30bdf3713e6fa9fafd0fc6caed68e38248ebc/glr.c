@@ -953,7 +953,7 @@ yylhsNonterm (yyRuleNum yyrule)
   return yyr1[yyrule];
 }
 
-#define yyis_pact_ninf(yystate) \
+#define yypact_value_is_default(yystate) \
   ]b4_table_value_equals([[pact]], [[yystate]], [b4_pact_ninf])[
 
 /** True iff LR state STATE has only a default reduction (regardless
@@ -961,7 +961,7 @@ yylhsNonterm (yyRuleNum yyrule)
 static inline yybool
 yyisDefaultedState (yyStateNum yystate)
 {
-  return yyis_pact_ninf (yypact[yystate]);
+  return yypact_value_is_default (yypact[yystate]);
 }
 
 /** The default reduction for STATE, assuming it has one.  */
@@ -971,8 +971,9 @@ yydefaultAction (yyStateNum yystate)
   return yydefact[yystate];
 }
 
-#define yyis_table_ninf(yytable_value) \
-  ]b4_table_value_equals([[table]], [[yytable_value]], [b4_table_ninf])[
+#define yytable_value_is_error(yytable_value) \
+  (]b4_table_value_equals([[table]], [[yytable_value]], [b4_table_ninf])[ \
+   || ]b4_table_value_equals([[table]], [[yytable_value]], [[0]])[)
 
 /** Set *YYACTION to the action to take in YYSTATE on seeing YYTOKEN.
  *  Result R means
@@ -987,12 +988,13 @@ yygetLRActions (yyStateNum yystate, int yytoken,
 		int* yyaction, const short int** yyconflicts)
 {
   int yyindex = yypact[yystate] + yytoken;
-  if (yyindex < 0 || YYLAST < yyindex || yycheck[yyindex] != yytoken)
+  if (yypact_value_is_default (yypact[yystate])
+      || yyindex < 0 || YYLAST < yyindex || yycheck[yyindex] != yytoken)
     {
       *yyaction = -yydefact[yystate];
       *yyconflicts = yyconfl;
     }
-  else if (! yyis_table_ninf (yytable[yyindex]))
+  else if (! yytable_value_is_error (yytable[yyindex]))
     {
       *yyaction = yytable[yyindex];
       *yyconflicts = yyconfl + yyconflp[yyindex];
@@ -2061,7 +2063,7 @@ yyreportSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
 
 	  for (yyx = yyxbegin; yyx < yyxend; ++yyx)
 	    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
-		&& !yyis_table_ninf (yytable[yyx + yyn]))
+		&& !yytable_value_is_error (yytable[yyx + yyn]))
 	      {
 		if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
 		  {
@@ -2172,7 +2174,7 @@ yyrecoverSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
 	    YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
 	  }
 	yyj = yypact[yystackp->yytops.yystates[0]->yylrState];
-	if (yyis_pact_ninf (yyj))
+	if (yypact_value_is_default (yyj))
 	  return;
 	yyj += yytoken;
 	if (yyj < 0 || YYLAST < yyj || yycheck[yyj] != yytoken)
@@ -2180,7 +2182,7 @@ yyrecoverSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
 	    if (yydefact[yystackp->yytops.yystates[0]->yylrState] != 0)
 	      return;
 	  }
-	else if (yytable[yyj] != 0 && ! yyis_table_ninf (yytable[yyj]))
+	else if (! yytable_value_is_error (yytable[yyj]))
 	  return;
       }
 
@@ -2201,7 +2203,7 @@ yyrecoverSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
     {
       yyGLRState *yys = yystackp->yytops.yystates[0];
       yyj = yypact[yys->yylrState];
-      if (! yyis_pact_ninf (yyj))
+      if (! yypact_value_is_default (yyj))
 	{
 	  yyj += YYTERROR;
 	  if (0 <= yyj && yyj <= YYLAST && yycheck[yyj] == YYTERROR
