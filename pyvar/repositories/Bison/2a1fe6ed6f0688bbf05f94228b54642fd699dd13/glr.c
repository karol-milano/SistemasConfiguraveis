@@ -693,7 +693,7 @@ yydefaultAction (yyStateNum yystate)
   return yydefact[yystate];
 }
 
-/** Set *ACTION to the action to take in STATE on seeing TOKEN.
+/** Set *YYACTION to the action to take in YYSTATE on seeing YYTOKEN.
  *  Result R means
  *    R < 0:  Reduce on rule -R.
  *    R = 0:  Error.
@@ -1069,13 +1069,25 @@ yyglrReduce (yyGLRStack* yystack, size_t yyk, yyRuleNum yyrule,
       YYSTYPE yysval;
       YYLTYPE yyloc;
 
+#if YYDEBUG
+      if (yydebug)
+	{
+	  int yyi;
+	  YYDPRINTF ((stderr, "Reducing stack %d by rule %d (line %d),",
+		      yyk, yyrule - 1, yyrline[yyrule]));
+	  /* Print the symbols being reduced, and their result.  */
+	  for (yyi = yyprhs[yyrule]; yyrhs[yyi] >= 0; yyi++)
+	    YYFPRINTF (stderr, "%s ", yytokenName (yyrhs[yyi]));
+	  YYFPRINTF (stderr, " -> %s\n", yytokenName (yyr1[yyrule]));
+	}
+#endif
       YYCHK (yydoAction (yystack, yyk, yyrule, &yysval, &yyloc));
       yyglrShift (yystack, yyk,
 		  yyLRgotoState (yystack->yytops.yystates[yyk]->yylrState,
 				 yylhsNonterm (yyrule)),
 		yyposn, yysval, &yyloc);
-      YYDPRINTF ((stderr, "Reduced stack %d by rule #%d. Now in state %d.\n",
-		  yyk, yyrule-1, yystack->yytops.yystates[yyk]->yylrState));
+      YYDPRINTF ((stderr, "Stack %d entering state %d\n",
+		  yyk, yystack->yytops.yystates[yyk]->yylrState));
     }
   else
     {
@@ -1454,9 +1466,11 @@ yyprocessOneStack (yyGLRStack* yystack, int yyk,
 	{
 	  if (*yytokenp == YYEMPTY)
 	    {
+	      YYDPRINTF ((stderr, "Reading a token: "));
 	      yychar = YYLEX;
 	      *yytokenp = YYTRANSLATE(yychar);
-	      YYDPRINTF ((stderr, "Read token %s\n", yytokenName (*yytokenp)));
+	      YYDPRINTF ((stderr, "Next token is %s\n",
+			  yytokenName (*yytokenp)));
 	    }
 	  yygetLRActions (yystate, *yytokenp, &yyaction, &yyconflicts);
 
@@ -1473,7 +1487,7 @@ yyprocessOneStack (yyGLRStack* yystack, int yyk,
 
 	  if (yyisShiftAction (yyaction))
 	    {
-	      YYDPRINTF ((stderr, "Shifted token %s on stack %d, ",
+	      YYDPRINTF ((stderr, "Shifting token %s on stack %d, ",
 			  yytokenName (*yytokenp), yyk));
 	      yyglrShift (yystack, yyk, yyaction, yyposn+1, *yylvalp, yyllocp);
 	      YYDPRINTF ((stderr, "which is now in state #%d\n",
@@ -1559,21 +1573,22 @@ yyrecoverParseError (yyGLRStack* yystack, YYSTYPE* yylvalp, YYLTYPE* yyllocp)
   if (yystack->yyerrState == 0)
     yystack->yyerrState = 3;
   else if (yystack->yyerrState == 3)
-    {
-      /* We just shifted the error token and (perhaps) took some
-	 reductions. Skip tokens until we can proceed. */
-      do {
+    /* We just shifted the error token and (perhaps) took some
+       reductions.  Skip tokens until we can proceed.  */
+    while (yytrue)
+      {
 	if (*yytokenp == YYEOF)
 	  yyFail (yystack, NULL);
 	if (*yytokenp != YYEMPTY)
 	  YYDPRINTF ((stderr, "Discarding token %s\n",
 		      yytokenName (*yytokenp)));
+	YYDPRINTF ((stderr, "Reading a token: "));
 	yychar = YYLEX;
 	*yytokenp = YYTRANSLATE (yychar);
-	YYDPRINTF ((stderr, "Read token %s\n", yytokenName (*yytokenp)));
+	YYDPRINTF ((stderr, "Next token is %s\n", yytokenName (*yytokenp)));
 	yyj = yypact[yystack->yytops.yystates[0]->yylrState];
 	if (yyj == YYPACT_NINF)
-	  /* Something's not right; we shouldn't be here */
+	  /* Something's not right; we shouldn't be here.  */
 	  yyFail (yystack, NULL);
 	yyj += *yytokenp;
 	if (yyj < 0 || yyj > YYLAST || yycheck[yyj] != *yytokenp)
@@ -1583,10 +1598,9 @@ yyrecoverParseError (yyGLRStack* yystack, YYSTYPE* yylvalp, YYLTYPE* yyllocp)
 	  }
 	else if (yytable[yyj] != 0 && yytable[yyj] != YYTABLE_NINF)
 	  return;
-      } while (yytrue);
-    }
+      }
 
-  /* Reduce to one stack */
+  /* Reduce to one stack.  */
   for (yyk = 0; yyk < yystack->yytops.yysize; yyk += 1)
     if (yystack->yytops.yystates[yyk] != NULL)
       break;
@@ -1652,6 +1666,8 @@ yyparse (YYPARSE_PARAM_ARG)
   yyinitGLRStack (&yystack, YYINITDEPTH);
   yystack.yytokenp = &yytoken;
 
+  YYDPRINTF ((stderr, "Starting parse\n"));
+
   if (setjmp (yystack.yyexception_buffer) != 0)
     goto yyDone;
 
@@ -1689,9 +1705,10 @@ yyparse (YYPARSE_PARAM_ARG)
 	    {
 	      if (yytoken == YYEMPTY)
 		{
+		  YYDPRINTF ((stderr, "Reading a token: "));
 		  yychar = YYLEX;
 		  yytoken = YYTRANSLATE (yychar);
-		  YYDPRINTF ((stderr, "Read token %s\n",
+		  YYDPRINTF ((stderr, "Next token is %s\n",
 			      yytokenName (yytoken)));
 		}
 	      yygetLRActions (yystate, yytoken, &yyaction, &yyconflicts);
@@ -1699,7 +1716,7 @@ yyparse (YYPARSE_PARAM_ARG)
 		break;
 	      if (yyisShiftAction (yyaction))
 		{
-		  YYDPRINTF ((stderr, "Shifted token %s. ",
+		  YYDPRINTF ((stderr, "Shifting token %s, ",
 			      yytokenName (yytoken)));
 		  if (yytoken != YYEOF)
 		    yytoken = YYEMPTY;
@@ -1707,7 +1724,7 @@ yyparse (YYPARSE_PARAM_ARG)
 		  yyglrShift (&yystack, 0, yyaction, yyposn, yylval, yyllocp);
 		  if (yystack.yyerrState > 0)
 		    yystack.yyerrState -= 1;
-		  YYDPRINTF ((stderr, "Now in state #%d\n",
+		  YYDPRINTF ((stderr, "Entering state %d\n",
 			      yystack.yytops.yystates[0]->yylrState));
 		}
 	      else if (yyisErrorAction (yyaction))
