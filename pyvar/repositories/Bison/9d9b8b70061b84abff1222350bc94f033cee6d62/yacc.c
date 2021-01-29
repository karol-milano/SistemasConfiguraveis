@@ -305,7 +305,7 @@ b4_syncline([@oline@], [@ofile@])[
 # endif
 
 # ifdef YYSTACK_ALLOC
-   /* Pacify GCC's `empty if-body' warning. */
+   /* Pacify GCC's `empty if-body' warning.  */
 #  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
 #  ifndef YYSTACK_ALLOC_MAXIMUM
     /* The OS might guarantee only one guard page at the bottom of the stack,
@@ -411,18 +411,18 @@ union yyalloc
    typedef short int yysigned_char;
 #endif
 
-/* YYFINAL -- State number of the termination state. */
+/* YYFINAL -- State number of the termination state.  */
 #define YYFINAL  ]b4_final_state_number[
 /* YYLAST -- Last index in YYTABLE.  */
 #define YYLAST   ]b4_last[
 
-/* YYNTOKENS -- Number of terminals. */
+/* YYNTOKENS -- Number of terminals.  */
 #define YYNTOKENS  ]b4_tokens_number[
-/* YYNNTS -- Number of nonterminals. */
+/* YYNNTS -- Number of nonterminals.  */
 #define YYNNTS  ]b4_nterms_number[
-/* YYNRULES -- Number of rules. */
+/* YYNRULES -- Number of rules.  */
 #define YYNRULES  ]b4_rules_number[
-/* YYNRULES -- Number of states. */
+/* YYNRULES -- Number of states.  */
 #define YYNSTATES  ]b4_states_number[
 
 /* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
@@ -446,7 +446,7 @@ static const ]b4_int_type_for([b4_prhs])[ yyprhs[] =
   ]b4_prhs[
 };
 
-/* YYRHS -- A `-1'-separated list of the rules' RHS. */
+/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
 static const ]b4_int_type_for([b4_rhs])[ yyrhs[] =
 {
   ]b4_rhs[
@@ -461,7 +461,7 @@ static const ]b4_int_type_for([b4_rline])[ yyrline[] =
 
 #if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
 /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
-   First, the terminals, then, starting at YYNTOKENS, nonterminals. */
+   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
 static const char *const yytname[] =
 {
   ]b4_tname[
@@ -497,7 +497,7 @@ static const ]b4_int_type_for([b4_defact])[ yydefact[] =
   ]b4_defact[
 };
 
-/* YYDEFGOTO[NTERM-NUM]. */
+/* YYDEFGOTO[NTERM-NUM].  */
 static const ]b4_int_type_for([b4_defgoto])[ yydefgoto[] =
 {
   ]b4_defgoto[
@@ -666,7 +666,7 @@ do {									  \
                    [[short int *top],    [top]])[
 {
   YYFPRINTF (stderr, "Stack now");
-  for (/* Nothing. */; bottom <= top; ++bottom)
+  for (; bottom <= top; ++bottom)
     YYFPRINTF (stderr, " %d", *bottom);
   YYFPRINTF (stderr, "\n");
 }
@@ -1039,7 +1039,7 @@ b4_c_function_def([yyparse], [int], b4_parse_param)
   YYLTYPE yylsa[YYINITDEPTH];
   YYLTYPE *yyls = yylsa;
   YYLTYPE *yylsp;
-  /* The locations where the error started and ended. */
+  /* The locations where the error started and ended.  */
   YYLTYPE yyerror_range[2];]])[
 
 #define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N)]b4_location_if([, yylsp -= (N)])[)
@@ -1052,7 +1052,7 @@ b4_c_function_def([yyparse], [int], b4_parse_param)
 ]b4_location_if([  YYLTYPE yyloc;])[
 
   /* The number of symbols on the RHS of the reduced rule.
-     Keep to zero when no symbol should be popped off. */
+     Keep to zero when no symbol should be popped.  */
   int yylen = 0;
 
   YYDPRINTF ((stderr, "Starting parse\n"));
@@ -1079,7 +1079,7 @@ b4_c_function_def([yyparse], [int], b4_parse_param)
 m4_ifdef([b4_initial_action], [
 m4_pushdef([b4_at_dollar],     [m4_define([b4_at_dollar_used])yylloc])dnl
 m4_pushdef([b4_dollar_dollar], [m4_define([b4_dollar_dollar_used])yylval])dnl
-  /* User initialization code. */
+  /* User initialization code.  */
 b4_initial_action
 m4_popdef([b4_dollar_dollar])dnl
 m4_popdef([b4_at_dollar])dnl
@@ -1097,8 +1097,7 @@ m4_ifdef([b4_at_dollar_used], [[  yylsp[0] = yylloc;
 `------------------------------------------------------------*/
  yynewstate:
   /* In all cases, when you get here, the value and location stacks
-     have just been pushed. so pushing a state here evens the stacks.
-     */
+     have just been pushed.  So pushing a state here evens the stacks.  */
   yyssp++;
 
  yysetstate:
@@ -1111,7 +1110,7 @@ m4_ifdef([b4_at_dollar_used], [[  yylsp[0] = yylloc;
 
 #ifdef yyoverflow
       {
-	/* Give user a chance to reallocate the stack. Use copies of
+	/* Give user a chance to reallocate the stack.  Use copies of
 	   these so that the &'s don't force the real ones into
 	   memory.  */
 	YYSTYPE *yyvs1 = yyvs;
@@ -1269,7 +1268,7 @@ yyreduce:
   yyval = yyvsp[1-yylen];
 
 ]b4_location_if(
-[[  /* Default location. */
+[[  /* Default location.  */
   YYLLOC_DEFAULT (yyloc, yylsp - yylen, yylen);]])[
   YY_REDUCE_PRINT (yyn);
   switch (yyn)
@@ -1387,7 +1386,7 @@ yyerrorlab:
 
 ]b4_location_if([[  yyerror_range[0] = yylsp[1-yylen];
 ]])[  /* Do not reclaim the symbols of the rule which action triggered
-     this YYERROR. */
+     this YYERROR.  */
   YYPOPSTACK (yylen);
   yylen = 0;
   YY_STACK_PRINT (yyss, yyssp);
@@ -1434,11 +1433,11 @@ yyerrlab1:
 ]b4_location_if([[
   yyerror_range[1] = yylloc;
   /* Using YYLLOC is tempting, but would change the location of
-     the look-ahead.  YYLOC is available though. */
+     the look-ahead.  YYLOC is available though.  */
   YYLLOC_DEFAULT (yyloc, yyerror_range - 1, 2);
   *++yylsp = yyloc;]])[
 
-  /* Shift the error token. */
+  /* Shift the error token.  */
   YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);
 
   yystate = yyn;
@@ -1474,7 +1473,7 @@ yyreturn:
      yydestruct ("Cleanup: discarding lookahead",
 		 yytoken, &yylval]b4_location_if([, &yylloc])[]b4_user_args[);
   /* Do not reclaim the symbols of the rule which action triggered
-     this YYABORT or YYACCEPT. */
+     this YYABORT or YYACCEPT.  */
   YYPOPSTACK (yylen);
   YY_STACK_PRINT (yyss, yyssp);
   while (yyssp != yyss)
