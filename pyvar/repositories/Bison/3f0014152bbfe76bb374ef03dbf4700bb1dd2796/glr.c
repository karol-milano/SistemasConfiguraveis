@@ -803,7 +803,6 @@ struct yyGLRStack {
   YYSTYPE yyval;
   YYLTYPE yyloc;
 ])[
-  yySymbol* yytokenp;
   YYJMP_BUF yyexception_buffer;
   yyGLRStackItem* yyitems;
   yyGLRStackItem* yynextFree;
@@ -910,7 +909,7 @@ yyuserAction (yyRuleNum yyn, int yyrhslen, yyGLRStackItem* yyvsp,
 # undef YYRECOVERING
 # define YYRECOVERING (yystackp->yyerrState != 0)
 # undef yyclearin
-# define yyclearin (yychar = *(yystackp->yytokenp) = YYEMPTY)
+# define yyclearin (yychar = YYEMPTY)
 # undef YYFILL
 # define YYFILL(N) yyfill (yyvsp, &yylow, N, yynormal)
 # undef YYBACKUP
@@ -1929,7 +1928,6 @@ yyprocessOneStack (yyGLRStack* yystackp, size_t yyk,
   int yyaction;
   const short int* yyconflicts;
   yyRuleNum yyrule;
-  yySymbol* const yytokenp = yystackp->yytokenp;
 
   while (yystackp->yytops.yystates[yyk] != NULL)
     {
@@ -1953,15 +1951,18 @@ yyprocessOneStack (yyGLRStack* yystackp, size_t yyk,
 	}
       else
 	{
+	  yySymbol yytoken;
 	  yystackp->yytops.yylookaheadNeeds[yyk] = yytrue;
-	  if (*yytokenp == YYEMPTY)
+	  if (yychar == YYEMPTY)
 	    {
 	      YYDPRINTF ((stderr, "Reading a token: "));
 	      yychar = YYLEX;
-	      *yytokenp = YYTRANSLATE (yychar);
-	      YY_SYMBOL_PRINT ("Next token is", *yytokenp, &yylval, &yylloc);
+	      yytoken = YYTRANSLATE (yychar);
+	      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
 	    }
-	  yygetLRActions (yystate, *yytokenp, &yyaction, &yyconflicts);
+	  else
+	    yytoken = YYTRANSLATE (yychar);
+	  yygetLRActions (yystate, yytoken, &yyaction, &yyconflicts);
 
 	  while (*yyconflicts != 0)
 	    {
@@ -1999,12 +2000,12 @@ yyreportSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
   if (yystackp->yyerrState == 0)
     {
 #if YYERROR_VERBOSE
-      yySymbol* const yytokenp = yystackp->yytokenp;
       int yyn;
       yyn = yypact[yystackp->yytops.yystates[0]->yylrState];
       if (YYPACT_NINF < yyn && yyn < YYLAST)
 	{
-	  size_t yysize0 = yytnamerr (NULL, yytokenName (*yytokenp));
+	  yySymbol yytoken = YYTRANSLATE (yychar);
+	  size_t yysize0 = yytnamerr (NULL, yytokenName (yytoken));
 	  size_t yysize = yysize0;
 	  size_t yysize1;
 	  yybool yysize_overflow = yyfalse;
@@ -2032,7 +2033,7 @@ yyreportSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
 	  int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
 	  int yycount = 1;
 
-	  yyarg[0] = yytokenName (*yytokenp);
+	  yyarg[0] = yytokenName (yytoken);
 	  yyfmt = yystpcpy (yyformat, yyunexpected);
 
 	  for (yyx = yyxbegin; yyx < yyxend; ++yyx)
@@ -2100,7 +2101,6 @@ yyreportSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
 /*ARGSUSED*/ static void
 yyrecoverSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
 {
-  yySymbol* const yytokenp = yystackp->yytokenp;
   size_t yyk;
   int yyj;
 
@@ -2109,9 +2109,10 @@ yyrecoverSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
        reductions.  Skip tokens until we can proceed.  */
     while (YYID (yytrue))
       {
-	if (*yytokenp == YYEOF)
+	yySymbol yytoken;
+	if (yychar == YYEOF)
 	  yyFail (yystackp][]b4_lpure_args[, NULL);
-	if (*yytokenp != YYEMPTY)
+	if (yychar != YYEMPTY)
 	  {]b4_location_if([[
 	    /* We throw away the lookahead, but the error range
 	       of the shifted error token must take it into account.  */
@@ -2120,18 +2121,19 @@ yyrecoverSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
 	    yyerror_range[1].yystate.yyloc = yys->yyloc;
 	    yyerror_range[2].yystate.yyloc = yylloc;
 	    YYLLOC_DEFAULT ((yys->yyloc), yyerror_range, 2);]])[
+	    yytoken = YYTRANSLATE (yychar);
 	    yydestruct ("Error: discarding",
-			*yytokenp, &yylval]b4_location_if([, &yylloc])[]b4_user_args[);
+			yytoken, &yylval]b4_location_if([, &yylloc])[]b4_user_args[);
 	  }
 	YYDPRINTF ((stderr, "Reading a token: "));
 	yychar = YYLEX;
-	*yytokenp = YYTRANSLATE (yychar);
-	YY_SYMBOL_PRINT ("Next token is", *yytokenp, &yylval, &yylloc);
+	yytoken = YYTRANSLATE (yychar);
+	YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
 	yyj = yypact[yystackp->yytops.yystates[0]->yylrState];
 	if (yyis_pact_ninf (yyj))
 	  return;
-	yyj += *yytokenp;
-	if (yyj < 0 || YYLAST < yyj || yycheck[yyj] != *yytokenp)
+	yyj += yytoken;
+	if (yyj < 0 || YYLAST < yyj || yycheck[yyj] != yytoken)
 	  {
 	    if (yydefact[yystackp->yytops.yystates[0]->yylrState] != 0)
 	      return;
@@ -2209,7 +2211,6 @@ yyrecoverSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
 ]b4_c_ansi_function_def([yyparse], [int], b4_parse_param)[
 {
   int yyresult;
-  yySymbol yytoken;
   yyGLRStack yystack;
   yyGLRStack* const yystackp = &yystack;
   size_t yyposn;
@@ -2217,7 +2218,6 @@ yyrecoverSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
   YYDPRINTF ((stderr, "Starting parse\n"));
 
   yychar = YYEMPTY;
-  yytoken = YYEMPTY;
   yylval = yyval_default;
 ]b4_location_if([
 #if YYLTYPE_IS_TRIVIAL
@@ -2244,7 +2244,6 @@ b4_syncline([@oline@], [@ofile@])])dnl
     case 2: goto yyexhaustedlab;
     default: goto yybuglab;
     }
-  yystack.yytokenp = &yytoken;
   yyglrShift (&yystack, 0, 0, 0, &yylval, &yylloc);
   yyposn = 0;
 
@@ -2277,24 +2276,24 @@ b4_syncline([@oline@], [@ofile@])])dnl
 	    }
 	  else
 	    {
-	      if (yytoken == YYEMPTY)
+	      yySymbol yytoken;
+	      if (yychar == YYEMPTY)
 		{
 		  YYDPRINTF ((stderr, "Reading a token: "));
 		  yychar = YYLEX;
 		  yytoken = YYTRANSLATE (yychar);
 		  YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
 		}
+	      else
+		yytoken = YYTRANSLATE (yychar);
 	      yygetLRActions (yystate, yytoken, &yyaction, &yyconflicts);
 	      if (*yyconflicts != 0)
 		break;
 	      if (yyisShiftAction (yyaction))
 		{
 		  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
-		  if (yytoken != YYEOF)
-		    {
-		      yychar = YYEMPTY;
-		      yytoken = YYEMPTY;
-		    }
+		  if (yychar != YYEOF)
+		    yychar = YYEMPTY;
 		  yyposn += 1;
 		  yyglrShift (&yystack, 0, yyaction, yyposn, &yylval, &yylloc);
 		  if (0 < yystack.yyerrState)
@@ -2346,12 +2345,11 @@ b4_syncline([@oline@], [@ofile@])])dnl
 
 	  /* If any yyglrShift call fails, it will fail after shifting.  Thus,
 	     a copy of yylval will already be on stack 0 in the event of a
-	     failure in the following loop.  Thus, yytoken is set to YYEMPTY
+	     failure in the following loop.  Thus, yychar is set to YYEMPTY
 	     before the loop to make sure the user destructor for yylval isn't
 	     called twice.  */
-	  yytoken_to_shift = yytoken;
+	  yytoken_to_shift = YYTRANSLATE (yychar);
 	  yychar = YYEMPTY;
-	  yytoken = YYEMPTY;
 	  yyposn += 1;
 	  for (yys = 0; yys < yyn; yys += 1)
 	    {
@@ -2412,9 +2410,10 @@ b4_syncline([@oline@], [@ofile@])])dnl
   goto yyreturn;
 
  yyreturn:
-  if (yytoken != YYEOF && yytoken != YYEMPTY)
+  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
-		yytoken, &yylval]b4_location_if([, &yylloc])[]b4_user_args[);
+		YYTRANSLATE (yychar),
+		&yylval]b4_location_if([, &yylloc])[]b4_user_args[);
 
   /* If the stack is well-formed, pop the stack until it is empty,
      destroying its entries as we go.  But free the stack regardless
