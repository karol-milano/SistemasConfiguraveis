@@ -349,7 +349,7 @@ static const ]b4_int_type_for([b4_translate])[ yytranslate[] =
   ]b4_translate[
 };
 
-#if YYDEBUG
+#if ]b4_api_PREFIX[DEBUG
 /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
    YYRHS.  */
 static const ]b4_int_type_for([b4_prhs])[ yyprhs[] =
@@ -370,7 +370,7 @@ static const ]b4_int_type_for([b4_rline])[ yyrline[] =
 };
 #endif
 
-#if YYDEBUG || YYERROR_VERBOSE || ]b4_token_table_flag[
+#if ]b4_api_PREFIX[DEBUG || YYERROR_VERBOSE || ]b4_token_table_flag[
 /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
    First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
 static const char *const yytname[] =
@@ -553,7 +553,7 @@ typedef enum { yyok, yyaccept, yyabort, yyerr } YYRESULTTAG;
    do { YYRESULTTAG yyflag = YYE; if (yyflag != yyok) return yyflag; }       \
    while (YYID (0))
 
-#if YYDEBUG
+#if ]b4_api_PREFIX[DEBUG
 
 # ifndef YYFPRINTF
 #  define YYFPRINTF fprintf
@@ -581,12 +581,12 @@ do {                                                            \
    multiple parsers can coexist.  */
 int yydebug;
 
-#else /* !YYDEBUG */
+#else /* !]b4_api_PREFIX[DEBUG */
 
 # define YYDPRINTF(Args)
 # define YY_SYMBOL_PRINT(Title, Type, Value, Location)
 
-#endif /* !YYDEBUG */
+#endif /* !]b4_api_PREFIX[DEBUG */
 
 /* YYINITDEPTH -- initial size of the parser's stacks.  */
 #ifndef YYINITDEPTH
@@ -825,7 +825,7 @@ yyMemoryExhausted (yyGLRStack* yystackp)
   YYLONGJMP (yystackp->yyexception_buffer, 2);
 }
 
-#if YYDEBUG || YYERROR_VERBOSE
+#if ]b4_api_PREFIX[DEBUG || YYERROR_VERBOSE
 /** A printable representation of TOKEN.  */
 static inline const char*
 yytokenName (yySymbol yytoken)
@@ -962,7 +962,7 @@ yydestroyGLRState (char const *yymsg, yyGLRState *yys]b4_user_formals[)
                 &yys->yysemantics.yysval]b4_locuser_args([&yys->yyloc])[);
   else
     {
-#if YYDEBUG
+#if ]b4_api_PREFIX[DEBUG
       if (yydebug)
         {
           if (yys->yysemantics.yyfirstVal)
@@ -1391,7 +1391,7 @@ yydoAction (yyGLRStack* yystackp, size_t yyk, yyRuleNum yyrule,
     }
 }
 
-#if !YYDEBUG
+#if !]b4_api_PREFIX[DEBUG
 # define YY_REDUCE_PRINT(Args)
 #else
 # define YY_REDUCE_PRINT(Args)          \
@@ -1712,7 +1712,7 @@ yyresolveAction (yySemanticOption* yyopt, yyGLRStack* yystackp,
   return yyflag;
 }
 
-#if YYDEBUG
+#if ]b4_api_PREFIX[DEBUG
 static void
 yyreportTree (yySemanticOption* yyx, int yyindent)
 {
@@ -1767,7 +1767,7 @@ yyreportAmbiguity (yySemanticOption* yyx0,
   YYUSE (yyx0);
   YYUSE (yyx1);
 
-#if YYDEBUG
+#if ]b4_api_PREFIX[DEBUG
   YYFPRINTF (stderr, "Ambiguity detected.\n");
   YYFPRINTF (stderr, "Option 1,\n");
   yyreportTree (yyx0, 2);
@@ -2551,7 +2551,7 @@ m4_popdef([b4_at_dollar])])dnl
 }
 
 /* DEBUGGING ONLY */
-#if YYDEBUG
+#if ]b4_api_PREFIX[DEBUG
 static void yypstack (yyGLRStack* yystackp, size_t yyk)
   __attribute__ ((__unused__));
 static void yypdumpstack (yyGLRStack* yystackp) __attribute__ ((__unused__));
