@@ -488,9 +488,6 @@ typedef int yy_state_t;
 /** Rule numbers. */
 typedef int yyRuleNum;
 
-/** Grammar symbol. */
-typedef yysymbol_type_t yySymbol;
-
 /** Item references. */
 typedef short yyItemNum;
 
@@ -597,16 +594,16 @@ yyMemoryExhausted (yyGLRStack* yystackp)
 }
 
 /** Accessing symbol of state YYSTATE.  */
-static inline yySymbol
+static inline yysymbol_type_t
 yy_accessing_symbol (yy_state_t yystate)
 {
-  return YY_CAST (yySymbol, yystos[yystate]);
+  return YY_CAST (yysymbol_type_t, yystos[yystate]);
 }
 
 #if ]b4_parse_error_case([simple], [b4_api_PREFIX[DEBUG || ]b4_token_table_flag], [[1]])[
 /* The user-facing name of the symbol whose (internal) number is
    YYSYMBOL.  No bounds checking.  */
-static const char *yysymbol_name (yySymbol yysymbol) YY_ATTRIBUTE_UNUSED;
+static const char *yysymbol_name (yysymbol_type_t yysymbol) YY_ATTRIBUTE_UNUSED;
 
 ]b4_parse_error_bmatch([simple\|verbose],
 [[/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
@@ -617,12 +614,12 @@ static const char *const yytname[] =
 };
 
 static const char *
-yysymbol_name (yySymbol yysymbol)
+yysymbol_name (yysymbol_type_t yysymbol)
 {
   return yytname[yysymbol];
 }]],
 [[static const char *
-yysymbol_name (yySymbol yysymbol)
+yysymbol_name (yysymbol_type_t yysymbol)
 {
   static const char *const yy_sname[] =
   {
@@ -808,10 +805,10 @@ yyfillin (yyGLRStackItem *yyvsp, int yylow0, int yylow1)
 ]m4_define([b4_yygetToken_call],
            [[yygetToken (&yychar][]b4_pure_if([, yystackp])[]b4_user_args[)]])[
 /** If yychar is empty, fetch the next token.  */
-static inline yySymbol
+static inline yysymbol_type_t
 yygetToken (int *yycharp][]b4_pure_if([, yyGLRStack* yystackp])[]b4_user_formals[)
 {
-  yySymbol yytoken;
+  yysymbol_type_t yytoken;
 ]b4_parse_param_use()dnl
 [  if (*yycharp == YYEMPTY)
     {
@@ -997,10 +994,10 @@ yydestroyGLRState (char const *yymsg, yyGLRState *yys]b4_user_formals[)
 }
 
 /** Left-hand-side symbol for rule #YYRULE.  */
-static inline yySymbol
+static inline yysymbol_type_t
 yylhsNonterm (yyRuleNum yyrule)
 {
-  return YY_CAST (yySymbol, yyr1[yyrule]);
+  return YY_CAST (yysymbol_type_t, yyr1[yyrule]);
 }
 
 #define yypact_value_is_default(Yyn) \
@@ -1033,7 +1030,7 @@ yydefaultAction (yy_state_t yystate)
  *  of conflicting reductions.
  */
 static inline int
-yygetLRActions (yy_state_t yystate, yySymbol yytoken, const short** yyconflicts)
+yygetLRActions (yy_state_t yystate, yysymbol_type_t yytoken, const short** yyconflicts)
 {
   int yyindex = yypact[yystate] + yytoken;
   if (yyisDefaultedState (yystate)
@@ -1059,7 +1056,7 @@ yygetLRActions (yy_state_t yystate, yySymbol yytoken, const short** yyconflicts)
  * \param yysym     the nonterminal to push on the stack
  */
 static inline yy_state_t
-yyLRgotoState (yy_state_t yystate, yySymbol yysym)
+yyLRgotoState (yy_state_t yystate, yysymbol_type_t yysym)
 {
   int yyr = yypgoto[yysym - YYNTOKENS] + yystate;
   if (0 <= yyr && yyr <= YYLAST && yycheck[yyr] == yystate)
@@ -2030,7 +2027,7 @@ yyprocessOneStack (yyGLRStack* yystackp, ptrdiff_t yyk,
         }
       else
         {
-          yySymbol yytoken = ]b4_yygetToken_call[;
+          yysymbol_type_t yytoken = ]b4_yygetToken_call[;
           const short* yyconflicts;
           const int yyaction = yygetLRActions (yystate, yytoken, &yyconflicts);
           yystackp->yytops.yylookaheadNeeds[yyk] = yytrue;
@@ -2093,7 +2090,7 @@ yyprocessOneStack (yyGLRStack* yystackp, ptrdiff_t yyk,
    be less than YYNTOKENS).  */
 static int
 yyexpected_tokens (const yyGLRStack* yystackp,
-                   yySymbol yyarg[], int yyargn)
+                   yysymbol_type_t yyarg[], int yyargn)
 {
   /* Actual size of YYARG. */
   int yycount = 0;
@@ -2117,7 +2114,7 @@ yyexpected_tokens (const yyGLRStack* yystackp,
             else if (yycount == yyargn)
               return 0;
             else
-              yyarg[yycount++] = YY_CAST (yySymbol, yyx);
+              yyarg[yycount++] = YY_CAST (yysymbol_type_t, yyx);
           }
     }
   return yycount;
@@ -2131,14 +2128,14 @@ static int
 yyreport_syntax_error (const yyGLRStack* yystackp]b4_user_formals[);
 
 /* The token type of the lookahead of this context.  */
-static yySymbol
+static yysymbol_type_t
 yyparse_context_token (const yyGLRStack *yystackp) YY_ATTRIBUTE_UNUSED;
 
-static yySymbol
+static yysymbol_type_t
 yyparse_context_token (const yyGLRStack *yystackp)
 {
   YYUSE (yystackp);
-  yySymbol yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
+  yysymbol_type_t yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
   return yytoken;
 }
 
@@ -2155,9 +2152,9 @@ yyparse_context_location (const yyGLRStack *yystackp)
          [detailed\|verbose],
 [[static int
 yysyntax_error_arguments (const yyGLRStack* yystackp,
-                          yySymbol yyarg[], int yyargn)
+                          yysymbol_type_t yyarg[], int yyargn)
 {
-  yySymbol yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
+  yysymbol_type_t yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
   /* Actual size of YYARG. */
   int yycount = 0;
   /* There are many possibilities here to consider:
@@ -2222,7 +2219,7 @@ yyreportSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
   const char *yyformat = YY_NULLPTR;
   /* Arguments of yyformat: reported tokens (one for the "unexpected",
      one per "expected"). */
-  yySymbol yyarg[YYARGS_MAX];
+  yysymbol_type_t yyarg[YYARGS_MAX];
   /* Cumulated lengths of YYARG.  */
   ptrdiff_t yysize = 0;
 
@@ -2310,7 +2307,7 @@ yyrecoverSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
        reductions.  Skip tokens until we can proceed.  */
     while (yytrue)
       {
-        yySymbol yytoken;
+        yysymbol_type_t yytoken;
         int yyj;
         if (yychar == YYEOF)
           yyFail (yystackp][]b4_lpure_args[, YY_NULLPTR);
@@ -2468,7 +2465,7 @@ b4_dollar_popdef])[]dnl
             }
           else
             {
-              yySymbol yytoken = ]b4_yygetToken_call;[
+              yysymbol_type_t yytoken = ]b4_yygetToken_call;[
               const short* yyconflicts;
               int yyaction = yygetLRActions (yystate, yytoken, &yyconflicts);
               if (*yyconflicts != 0)
@@ -2498,7 +2495,7 @@ b4_dollar_popdef])[]dnl
 
       while (yytrue)
         {
-          yySymbol yytoken_to_shift;
+          yysymbol_type_t yytoken_to_shift;
           ptrdiff_t yys;
 
           for (yys = 0; yys < yystack.yytops.yysize; yys += 1)
