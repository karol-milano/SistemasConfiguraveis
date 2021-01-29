@@ -589,7 +589,7 @@ static const ]b4_int_type_for([b4_translate])[ yytranslate[] =
   ]b4_translate[
 };
 
-#if YYDEBUG
+#if ]b4_api_PREFIX[DEBUG
 /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
    YYRHS.  */
 static const ]b4_int_type_for([b4_prhs])[ yyprhs[] =
@@ -610,7 +610,7 @@ static const ]b4_int_type_for([b4_rline])[ yyrline[] =
 };
 #endif
 
-#if YYDEBUG || YYERROR_VERBOSE || ]b4_token_table_flag[
+#if ]b4_api_PREFIX[DEBUG || YYERROR_VERBOSE || ]b4_token_table_flag[
 /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
    First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
 static const char *const yytname[] =
@@ -803,7 +803,7 @@ while (YYID (0))
 #endif
 
 /* Enable debugging if requested.  */
-#if YYDEBUG
+#if ]b4_api_PREFIX[DEBUG
 
 # ifndef YYFPRINTF
 #  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
@@ -890,12 +890,12 @@ do {					\
 /* Nonzero means print parse trace.  It is left uninitialized so that
    multiple parsers can coexist.  */
 int yydebug;
-#else /* !YYDEBUG */
+#else /* !]b4_api_PREFIX[DEBUG */
 # define YYDPRINTF(Args)
 # define YY_SYMBOL_PRINT(Title, Type, Value, Location)
 # define YY_STACK_PRINT(Bottom, Top)
 # define YY_REDUCE_PRINT(Rule)
-#endif /* !YYDEBUG */
+#endif /* !]b4_api_PREFIX[DEBUG */
 
 
 /* YYINITDEPTH -- initial size of the parser's stacks.  */
@@ -926,7 +926,7 @@ int yydebug;
    required.  Return 1 if memory is exhausted.  */
 static int
 yy_lac_stack_realloc (YYSIZE_T *yycapacity, YYSIZE_T yyadd,
-#if YYDEBUG
+#if ]b4_api_PREFIX[DEBUG
                       char const *yydebug_prefix,
                       char const *yydebug_suffix,
 #endif
@@ -1032,7 +1032,7 @@ do {                                                             \
    the parser stacks to try to find a new initial context in which the
    current lookahead is syntactically acceptable.  If it fails to find
    such a context, it discards the lookahead.  */
-#if YYDEBUG
+#if ]b4_api_PREFIX[DEBUG
 # define YY_LAC_DISCARD(Event)                                           \
 do {                                                                     \
   if (yy_lac_established)                                                \
@@ -1135,7 +1135,7 @@ yy_lac (yytype_int16 *yyesa, yytype_int16 **yyes,
         else
           {
             if (yy_lac_stack_realloc (yyes_capacity, 1,
-#if YYDEBUG
+#if ]b4_api_PREFIX[DEBUG
                                       " (", ")",
 #endif
                                       yyes, yyesa, &yyesp, yyes_prev))
@@ -1342,7 +1342,7 @@ yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                 yysize = yysize1;
               }
         }]b4_lac_if([[
-# if YYDEBUG
+# if ]b4_api_PREFIX[DEBUG
       else if (yydebug)
         YYFPRINTF (stderr, "No expected tokens.\n");
 # endif]])[
