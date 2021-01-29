@@ -230,6 +230,7 @@ b4_copyright([Skeleton implementation for Bison GLR parsers in C],
 
 ]b4_defines_if([[#include "@basename(]b4_spec_header_file[@)"]],
                [b4_shared_declarations])[
+]b4_declare_symbol_enum[
 
 /* Default (constant) value used for initialization for null
    right-hand sides.  Unlike the standard yacc.c template, here we set
@@ -332,16 +333,15 @@ static YYLTYPE yyloc_default][]b4_yyloc_default;])[
 /* YYFAULTYTOK -- Token number (for yychar) that denotes a
    syntax_error thrown from the scanner.  */
 #define YYFAULTYTOK (YYMAXUTOK + 1)]])[
-/* YYUNDEFTOK -- Symbol number (for yytoken) that denotes an unknown
-   token.  */
-#define YYUNDEFTOK  ]b4_undef_token_number[
 
 /* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
    as returned by yylex, with out-of-bounds checking.  */
 ]b4_api_token_raw_if(dnl
-[[#define YYTRANSLATE(YYX) (YYX)]],
-[[#define YYTRANSLATE(YYX)                         \
-  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)
+[[#define YYTRANSLATE(YYX) YY_CAST (yysymbol_type_t, YYX)]],
+[[#define YYTRANSLATE(YYX)                                \
+  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
+   ? YY_CAST (yysymbol_type_t, yytranslate[YYX])        \
+   : YYSYMBOL_YYUNDEF)
 
 /* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
    as returned by yylex.  */
@@ -401,9 +401,6 @@ dnl We probably ought to introduce a type for confl.
   ]b4_conflicting_rules[
 };
 
-/* Error token number */
-#define YYTERROR 1
-
 ]b4_locations_if([[
 ]b4_yylloc_default_define[
 # define YYRHSLOC(Rhs, K) ((Rhs)[K].yystate.yyloc)
@@ -492,7 +489,7 @@ typedef int yy_state_t;
 typedef int yyRuleNum;
 
 /** Grammar symbol. */
-typedef int yySymbol;
+typedef yysymbol_type_t yySymbol;
 
 /** Item references. */
 typedef short yyItemNum;
@@ -599,6 +596,13 @@ yyMemoryExhausted (yyGLRStack* yystackp)
   YYLONGJMP (yystackp->yyexception_buffer, 2);
 }
 
+/** Accessing symbol of state YYSTATE.  */
+static inline yySymbol
+yy_accessing_symbol (yy_state_t yystate)
+{
+  return YY_CAST (yySymbol, yystos[yystate]);
+}
+
 #if ]b4_parse_error_case([simple], [b4_api_PREFIX[DEBUG || ]b4_token_table_flag], [[1]])[
 /* The user-facing name of the symbol whose (internal) number is
    YYSYMBOL.  No bounds checking.  */
@@ -824,9 +828,9 @@ yygetToken (int *yycharp][]b4_pure_if([, yyGLRStack* yystackp])[]b4_user_formals
           YY_DPRINTF ((stderr, "Caught exception: %s\n", yyexc.what()));]b4_locations_if([
           yylloc = yyexc.location;])[
           yyerror (]b4_lyyerror_args[yyexc.what ());
-          // Map errors caught in the scanner to the undefined token
-          // (YYUNDEFTOK), so that error handling is started.
-          // However, record this with this special value of yychar.
+          // Map errors caught in the scanner to the undefined token,
+          // so that error handling is started.  However, record this
+          // with this special value of yychar.
           *yycharp = YYFAULTYTOK;
         }
 #endif // YY_EXCEPTIONS]], [[
@@ -834,7 +838,8 @@ yygetToken (int *yycharp][]b4_pure_if([, yyGLRStack* yystackp])[]b4_user_formals
     }
   if (*yycharp <= YYEOF)
     {
-      *yycharp = yytoken = YYEOF;
+      *yycharp = YYEOF;
+      yytoken = YYSYMBOL_YYEOF;
       YY_DPRINTF ((stderr, "Now at end of input.\n"));
     }
   else
@@ -963,7 +968,7 @@ static void
 yydestroyGLRState (char const *yymsg, yyGLRState *yys]b4_user_formals[)
 {
   if (yys->yyresolved)
-    yydestruct (yymsg, yystos[yys->yylrState],
+    yydestruct (yymsg, yy_accessing_symbol (yys->yylrState),
                 &yys->yysemantics.yysval]b4_locuser_args([&yys->yyloc])[);
   else
     {
@@ -974,7 +979,7 @@ yydestroyGLRState (char const *yymsg, yyGLRState *yys]b4_user_formals[)
             YY_FPRINTF ((stderr, "%s unresolved", yymsg));
           else
             YY_FPRINTF ((stderr, "%s incomplete", yymsg));
-          YY_SYMBOL_PRINT ("", yystos[yys->yylrState], YY_NULLPTR, &yys->yyloc);
+          YY_SYMBOL_PRINT ("", yy_accessing_symbol (yys->yylrState), YY_NULLPTR, &yys->yyloc);
         }
 #endif
 
@@ -995,7 +1000,7 @@ yydestroyGLRState (char const *yymsg, yyGLRState *yys]b4_user_formals[)
 static inline yySymbol
 yylhsNonterm (yyRuleNum yyrule)
 {
-  return yyr1[yyrule];
+  return YY_CAST (yySymbol, yyr1[yyrule]);
 }
 
 #define yypact_value_is_default(Yyn) \
@@ -1390,7 +1395,7 @@ yy_reduce_print (yybool yynormal, yyGLRStackItem* yyvsp, ptrdiff_t yyk,
     {
       YY_FPRINTF ((stderr, "   $%d = ", yyi + 1));
       yy_symbol_print (stderr,
-                       yystos[yyvsp[yyi - yynrhs + 1].yystate.yylrState],
+                       yy_accessing_symbol (yyvsp[yyi - yynrhs + 1].yystate.yylrState),
                        &yyvsp[yyi - yynrhs + 1].yystate.yysemantics.yysval]b4_locations_if([,
                        &]b4_rhs_location(yynrhs, yyi + 1))[]dnl
                        b4_user_args[);
@@ -1771,10 +1776,10 @@ yyreportTree (yySemanticOption* yyx, int yyindent)
         {
           if (yystates[yyi-1]->yyposn+1 > yystates[yyi]->yyposn)
             YY_FPRINTF ((stderr, "%*s%s <empty>\n", yyindent+2, "",
-                         yysymbol_name (yystos[yystates[yyi]->yylrState])));
+                         yysymbol_name (yy_accessing_symbol (yystates[yyi]->yylrState))));
           else
             YY_FPRINTF ((stderr, "%*s%s <tokens %ld .. %ld>\n", yyindent+2, "",
-                         yysymbol_name (yystos[yystates[yyi]->yylrState]),
+                         yysymbol_name (yy_accessing_symbol (yystates[yyi]->yylrState)),
                          YY_CAST (long, yystates[yyi-1]->yyposn + 1),
                          YY_CAST (long, yystates[yyi]->yyposn)));
         }
@@ -1919,7 +1924,7 @@ yyresolveValue (yyGLRState* yys, yyGLRStack* yystackp]b4_user_formals[)
                 if (yyflag != yyok)
                   {
                     yydestruct ("Cleanup: discarding incompletely merged value for",
-                                yystos[yys->yylrState],
+                                yy_accessing_symbol (yys->yylrState),
                                 &yysval]b4_locuser_args[);
                     break;
                   }
@@ -2088,7 +2093,7 @@ yyprocessOneStack (yyGLRStack* yystackp, ptrdiff_t yyk,
    be less than YYNTOKENS).  */
 static int
 yyexpected_tokens (const yyGLRStack* yystackp,
-                   int yyarg[], int yyargn)
+                   yySymbol yyarg[], int yyargn)
 {
   /* Actual size of YYARG. */
   int yycount = 0;
@@ -2104,7 +2109,7 @@ yyexpected_tokens (const yyGLRStack* yystackp,
       int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
       int yyx;
       for (yyx = yyxbegin; yyx < yyxend; ++yyx)
-        if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
+        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYERROR
             && !yytable_value_is_error (yytable[yyx + yyn]))
           {
             if (!yyarg)
@@ -2112,7 +2117,7 @@ yyexpected_tokens (const yyGLRStack* yystackp,
             else if (yycount == yyargn)
               return 0;
             else
-              yyarg[yycount++] = yyx;
+              yyarg[yycount++] = YY_CAST (yySymbol, yyx);
           }
     }
   return yycount;
@@ -2133,7 +2138,7 @@ static int
 yyparse_context_token (const yyGLRStack *yystackp)
 {
   YYUSE (yystackp);
-  yySymbol yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);
+  yySymbol yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
   return yytoken;
 }
 
@@ -2150,9 +2155,9 @@ yyparse_context_location (const yyGLRStack *yystackp)
          [detailed\|verbose],
 [[static int
 yysyntax_error_arguments (const yyGLRStack* yystackp,
-                          int yyarg[], int yyargn)
+                          yySymbol yyarg[], int yyargn)
 {
-  yySymbol yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);
+  yySymbol yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
   /* Actual size of YYARG. */
   int yycount = 0;
   /* There are many possibilities here to consider:
@@ -2183,7 +2188,7 @@ yysyntax_error_arguments (const yyGLRStack* yystackp,
        one exception: it will still contain any token that will not be
        accepted due to an error action in a later state.]])[
   */
-  if (yytoken != YYEMPTY)
+  if (yytoken != YYSYMBOL_YYEMPTY)
     {
       int yyn;
       yyarg[yycount++] = yytoken;
@@ -2359,8 +2364,8 @@ yyrecoverSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
       int yyj = yypact[yys->yylrState];
       if (! yypact_value_is_default (yyj))
         {
-          yyj += YYTERROR;
-          if (0 <= yyj && yyj <= YYLAST && yycheck[yyj] == YYTERROR
+          yyj += YYSYMBOL_YYERROR;
+          if (0 <= yyj && yyj <= YYLAST && yycheck[yyj] == YYSYMBOL_YYERROR
               && yyisShiftAction (yytable[yyj]))
             {
               /* Shift the error token.  */
@@ -2369,7 +2374,7 @@ yyrecoverSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
               YYLTYPE yyerrloc;
               yystackp->yyerror_range[2].yystate.yyloc = yylloc;
               YYLLOC_DEFAULT (yyerrloc, (yystackp->yyerror_range), 2);]])[
-              YY_SYMBOL_PRINT ("Shifting", yystos[yyaction],
+              YY_SYMBOL_PRINT ("Shifting", yy_accessing_symbol (yyaction),
                                &yylval, &yyerrloc);
               yyglrShift (yystackp, 0, yyaction,
                           yys->yyposn, &yylval]b4_locations_if([, &yyerrloc])[);
