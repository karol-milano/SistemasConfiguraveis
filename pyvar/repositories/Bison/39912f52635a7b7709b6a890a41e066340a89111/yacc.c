@@ -319,6 +319,7 @@ b4_location_if(
 
 /* YYFINAL -- State number of the termination state. */
 #define YYFINAL  b4_final_state_number
+/* YYLAST -- Last index in YYTABLE.  */
 #define YYLAST   b4_last
 
 /* YYNTOKENS -- Number of terminals. */
@@ -811,7 +812,7 @@ yyparse (YYPARSE_PARAM_ARG)
  yysetstate:
   *yyssp = yystate;
 
-  if (yyssp >= yyss + yystacksize - 1)
+  if (yyss + yystacksize - 1 <= yyssp)
     {
       /* Get the current used size of the three stacks, in elements.  */
       YYSIZE_T yysize = yyssp - yyss + 1;
@@ -843,10 +844,10 @@ yyparse (YYPARSE_PARAM_ARG)
       goto yyoverflowlab;
 # else
       /* Extend the stack our own way.  */
-      if (yystacksize >= YYMAXDEPTH)
+      if (YYMAXDEPTH <= yystacksize)
 	goto yyoverflowlab;
       yystacksize *= 2;
-      if (yystacksize > YYMAXDEPTH)
+      if (YYMAXDEPTH < yystacksize)
 	yystacksize = YYMAXDEPTH;
 
       {
@@ -872,7 +873,7 @@ yyparse (YYPARSE_PARAM_ARG)
       YYDPRINTF ((stderr, "Stack size increased to %lu\n",
 		  (unsigned long int) yystacksize));
 
-      if (yyssp >= yyss + yystacksize - 1)
+      if (yyss + yystacksize - 1 <= yyssp)
 	YYABORT;
     }
 
@@ -1005,7 +1006,7 @@ yyreduce:
 		 yyn - 1, yyrline[yyn]);
 
       /* Print the symbols being reduced, and their result.  */
-      for (yyi = yyprhs[yyn]; yyrhs[yyi] >= 0; yyi++)
+      for (yyi = yyprhs[yyn]; 0 <= yyrhs[yyi]; yyi++)
 	YYFPRINTF (stderr, "%s ", yytname[yyrhs[yyi]]);
       YYFPRINTF (stderr, " -> %s\n", yytname[yyr1[yyn]]);
     }
@@ -1126,7 +1127,7 @@ yyerrlab1:
 	  /* Pop the error token.  */
           YYPOPSTACK;
 	  /* Pop the rest of the stack.  */
-	  while (yyssp > yyss)
+	  while (yyss < yyssp)
 	    {
 	      YYDPRINTF ((stderr, "Error: popping "));
 	      YYDSYMPRINT ((stderr,
