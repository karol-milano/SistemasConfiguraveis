@@ -337,10 +337,10 @@ static YYLTYPE yyloc_default][]b4_yyloc_default;])[
 /* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
    as returned by yylex, with out-of-bounds checking.  */
 ]b4_api_token_raw_if(dnl
-[[#define YYTRANSLATE(YYX) YY_CAST (yysymbol_type_t, YYX)]],
+[[#define YYTRANSLATE(YYX) YY_CAST (yysymbol_kind_t, YYX)]],
 [[#define YYTRANSLATE(YYX)                                \
   (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
-   ? YY_CAST (yysymbol_type_t, yytranslate[YYX])        \
+   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
    : YYSYMBOL_YYUNDEF)
 
 /* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
@@ -594,16 +594,16 @@ yyMemoryExhausted (yyGLRStack* yystackp)
 }
 
 /** Accessing symbol of state YYSTATE.  */
-static inline yysymbol_type_t
+static inline yysymbol_kind_t
 yy_accessing_symbol (yy_state_t yystate)
 {
-  return YY_CAST (yysymbol_type_t, yystos[yystate]);
+  return YY_CAST (yysymbol_kind_t, yystos[yystate]);
 }
 
 #if ]b4_parse_error_case([simple], [b4_api_PREFIX[DEBUG || ]b4_token_table_flag], [[1]])[
 /* The user-facing name of the symbol whose (internal) number is
    YYSYMBOL.  No bounds checking.  */
-static const char *yysymbol_name (yysymbol_type_t yysymbol) YY_ATTRIBUTE_UNUSED;
+static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;
 
 ]b4_parse_error_bmatch([simple\|verbose],
 [[/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
@@ -614,12 +614,12 @@ static const char *const yytname[] =
 };
 
 static const char *
-yysymbol_name (yysymbol_type_t yysymbol)
+yysymbol_name (yysymbol_kind_t yysymbol)
 {
   return yytname[yysymbol];
 }]],
 [[static const char *
-yysymbol_name (yysymbol_type_t yysymbol)
+yysymbol_name (yysymbol_kind_t yysymbol)
 {
   static const char *const yy_sname[] =
   {
@@ -805,10 +805,10 @@ yyfillin (yyGLRStackItem *yyvsp, int yylow0, int yylow1)
 ]m4_define([b4_yygetToken_call],
            [[yygetToken (&yychar][]b4_pure_if([, yystackp])[]b4_user_args[)]])[
 /** If yychar is empty, fetch the next token.  */
-static inline yysymbol_type_t
+static inline yysymbol_kind_t
 yygetToken (int *yycharp][]b4_pure_if([, yyGLRStack* yystackp])[]b4_user_formals[)
 {
-  yysymbol_type_t yytoken;
+  yysymbol_kind_t yytoken;
 ]b4_parse_param_use()dnl
 [  if (*yycharp == YYEMPTY)
     {
@@ -994,10 +994,10 @@ yydestroyGLRState (char const *yymsg, yyGLRState *yys]b4_user_formals[)
 }
 
 /** Left-hand-side symbol for rule #YYRULE.  */
-static inline yysymbol_type_t
+static inline yysymbol_kind_t
 yylhsNonterm (yyRuleNum yyrule)
 {
-  return YY_CAST (yysymbol_type_t, yyr1[yyrule]);
+  return YY_CAST (yysymbol_kind_t, yyr1[yyrule]);
 }
 
 #define yypact_value_is_default(Yyn) \
@@ -1030,7 +1030,7 @@ yydefaultAction (yy_state_t yystate)
  *  of conflicting reductions.
  */
 static inline int
-yygetLRActions (yy_state_t yystate, yysymbol_type_t yytoken, const short** yyconflicts)
+yygetLRActions (yy_state_t yystate, yysymbol_kind_t yytoken, const short** yyconflicts)
 {
   int yyindex = yypact[yystate] + yytoken;
   if (yyisDefaultedState (yystate)
@@ -1056,7 +1056,7 @@ yygetLRActions (yy_state_t yystate, yysymbol_type_t yytoken, const short** yycon
  * \param yysym     the nonterminal to push on the stack
  */
 static inline yy_state_t
-yyLRgotoState (yy_state_t yystate, yysymbol_type_t yysym)
+yyLRgotoState (yy_state_t yystate, yysymbol_kind_t yysym)
 {
   int yyr = yypgoto[yysym - YYNTOKENS] + yystate;
   if (0 <= yyr && yyr <= YYLAST && yycheck[yyr] == yystate)
@@ -2027,7 +2027,7 @@ yyprocessOneStack (yyGLRStack* yystackp, ptrdiff_t yyk,
         }
       else
         {
-          yysymbol_type_t yytoken = ]b4_yygetToken_call[;
+          yysymbol_kind_t yytoken = ]b4_yygetToken_call[;
           const short* yyconflicts;
           const int yyaction = yygetLRActions (yystate, yytoken, &yyconflicts);
           yystackp->yytops.yylookaheadNeeds[yyk] = yytrue;
@@ -2090,7 +2090,7 @@ yyprocessOneStack (yyGLRStack* yystackp, ptrdiff_t yyk,
    be less than YYNTOKENS).  */
 static int
 yyexpected_tokens (const yyGLRStack* yystackp,
-                   yysymbol_type_t yyarg[], int yyargn)
+                   yysymbol_kind_t yyarg[], int yyargn)
 {
   /* Actual size of YYARG. */
   int yycount = 0;
@@ -2114,7 +2114,7 @@ yyexpected_tokens (const yyGLRStack* yystackp,
             else if (yycount == yyargn)
               return 0;
             else
-              yyarg[yycount++] = YY_CAST (yysymbol_type_t, yyx);
+              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
           }
     }
   return yycount;
@@ -2128,14 +2128,14 @@ static int
 yyreport_syntax_error (const yyGLRStack* yystackp]b4_user_formals[);
 
 /* The token type of the lookahead of this context.  */
-static yysymbol_type_t
+static yysymbol_kind_t
 yypcontext_token (const yyGLRStack *yystackp) YY_ATTRIBUTE_UNUSED;
 
-static yysymbol_type_t
+static yysymbol_kind_t
 yypcontext_token (const yyGLRStack *yystackp)
 {
   YYUSE (yystackp);
-  yysymbol_type_t yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
+  yysymbol_kind_t yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
   return yytoken;
 }
 
@@ -2152,9 +2152,9 @@ yypcontext_location (const yyGLRStack *yystackp)
          [detailed\|verbose],
 [[static int
 yy_syntax_error_arguments (const yyGLRStack* yystackp,
-                           yysymbol_type_t yyarg[], int yyargn)
+                           yysymbol_kind_t yyarg[], int yyargn)
 {
-  yysymbol_type_t yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
+  yysymbol_kind_t yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
   /* Actual size of YYARG. */
   int yycount = 0;
   /* There are many possibilities here to consider:
@@ -2219,7 +2219,7 @@ yyreportSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
   const char *yyformat = YY_NULLPTR;
   /* Arguments of yyformat: reported tokens (one for the "unexpected",
      one per "expected"). */
-  yysymbol_type_t yyarg[YYARGS_MAX];
+  yysymbol_kind_t yyarg[YYARGS_MAX];
   /* Cumulated lengths of YYARG.  */
   ptrdiff_t yysize = 0;
 
@@ -2307,7 +2307,7 @@ yyrecoverSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
        reductions.  Skip tokens until we can proceed.  */
     while (yytrue)
       {
-        yysymbol_type_t yytoken;
+        yysymbol_kind_t yytoken;
         int yyj;
         if (yychar == YYEOF)
           yyFail (yystackp][]b4_lpure_args[, YY_NULLPTR);
@@ -2465,7 +2465,7 @@ b4_dollar_popdef])[]dnl
             }
           else
             {
-              yysymbol_type_t yytoken = ]b4_yygetToken_call;[
+              yysymbol_kind_t yytoken = ]b4_yygetToken_call;[
               const short* yyconflicts;
               int yyaction = yygetLRActions (yystate, yytoken, &yyconflicts);
               if (*yyconflicts != 0)
@@ -2495,7 +2495,7 @@ b4_dollar_popdef])[]dnl
 
       while (yytrue)
         {
-          yysymbol_type_t yytoken_to_shift;
+          yysymbol_kind_t yytoken_to_shift;
           ptrdiff_t yys;
 
           for (yys = 0; yys < yystack.yytops.yysize; yys += 1)
