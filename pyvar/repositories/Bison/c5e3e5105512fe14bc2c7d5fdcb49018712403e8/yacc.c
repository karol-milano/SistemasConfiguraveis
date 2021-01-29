@@ -340,108 +340,108 @@ union yyalloc
 /* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
 static const ]b4_int_type_for([b4_translate])[ yytranslate[] =
 {
-  ]b4_translate
+  ]b4_translate[
 };
 
 #if YYDEBUG
-/* YYPRHS[[YYN]] -- Index of the first RHS symbol of rule number YYN in
+/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
    YYRHS.  */
-static const b4_int_type_for([b4_prhs]) yyprhs[[]] =
+static const ]b4_int_type_for([b4_prhs])[ yyprhs[] =
 {
-  b4_prhs
+  ]b4_prhs[
 };
 
 /* YYRHS -- A `-1'-separated list of the rules' RHS. */
-static const b4_int_type_for([b4_rhs]) yyrhs[[]] =
+static const ]b4_int_type_for([b4_rhs])[ yyrhs[] =
 {
-  b4_rhs
+  ]b4_rhs[
 };
 
-/* YYRLINE[[YYN]] -- source line where rule number YYN was defined.  */
-static const b4_int_type_for([b4_rline]) yyrline[[]] =
+/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
+static const ]b4_int_type_for([b4_rline])[ yyrline[] =
 {
-  b4_rline
+  ]b4_rline[
 };
 #endif
 
 #if YYDEBUG || YYERROR_VERBOSE
-/* YYTNME[[SYMBOL-NUM]] -- String name of the symbol SYMBOL-NUM.
+/* YYTNME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
    First, the terminals, then, starting at YYNTOKENS, nonterminals. */
-static const char *const yytname[[]] =
+static const char *const yytname[] =
 {
-  b4_tname
+  ]b4_tname[
 };
 #endif
 
 # ifdef YYPRINT
-/* YYTOKNUM[[YYLEX-NUM]] -- Internal token number corresponding to
+/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
    token YYLEX-NUM.  */
-static const b4_int_type_for([b4_toknum]) yytoknum[[]] =
+static const ]b4_int_type_for([b4_toknum])[ yytoknum[] =
 {
-  b4_toknum
+  ]b4_toknum[
 };
 # endif
 
-/* YYR1[[YYN]] -- Symbol number of symbol that rule YYN derives.  */
-static const b4_int_type_for([b4_r1]) yyr1[[]] =
+/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
+static const ]b4_int_type_for([b4_r1])[ yyr1[] =
 {
-  b4_r1
+  ]b4_r1[
 };
 
-/* YYR2[[YYN]] -- Number of symbols composing right hand side of rule YYN.  */
-static const b4_int_type_for([b4_r2]) yyr2[[]] =
+/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
+static const ]b4_int_type_for([b4_r2])[ yyr2[] =
 {
-  b4_r2
+  ]b4_r2[
 };
 
-/* YYDEFACT[[STATE-NAME]] -- Default rule to reduce with in state
+/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
    STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
    means the default is an error.  */
-static const b4_int_type_for([b4_defact]) yydefact[[]] =
+static const ]b4_int_type_for([b4_defact])[ yydefact[] =
 {
-  b4_defact
+  ]b4_defact[
 };
 
-/* YYDEFGOTO[[NTERM-NUM]]. */
-static const b4_int_type_for([b4_defgoto]) yydefgoto[[]] =
+/* YYDEFGOTO[NTERM-NUM]. */
+static const ]b4_int_type_for([b4_defgoto])[ yydefgoto[] =
 {
-  b4_defgoto
+  ]b4_defgoto[
 };
 
-/* YYPACT[[STATE-NUM]] -- Index in YYTABLE of the portion describing
+/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
    STATE-NUM.  */
-#define YYPACT_NINF b4_pact_ninf
-static const b4_int_type_for([b4_pact]) yypact[[]] =
+#define YYPACT_NINF ]b4_pact_ninf[
+static const ]b4_int_type_for([b4_pact])[ yypact[] =
 {
-  b4_pact
+  ]b4_pact[
 };
 
-/* YYPGOTO[[NTERM-NUM]].  */
-static const b4_int_type_for([b4_pgoto]) yypgoto[[]] =
+/* YYPGOTO[NTERM-NUM].  */
+static const ]b4_int_type_for([b4_pgoto])[ yypgoto[] =
 {
-  b4_pgoto
+  ]b4_pgoto[
 };
 
-/* YYTABLE[[YYPACT[STATE-NUM]]].  What to do in state STATE-NUM.  If
+/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
    positive, shift that token.  If negative, reduce the rule which
    number is the opposite.  If zero, do what YYDEFACT says.
    If YYTABLE_NINF, syntax error.  */
-#define YYTABLE_NINF b4_table_ninf
-static const b4_int_type_for([b4_table]) yytable[[]] =
+#define YYTABLE_NINF ]b4_table_ninf[
+static const ]b4_int_type_for([b4_table])[ yytable[] =
 {
-  b4_table
+  ]b4_table[
 };
 
-static const b4_int_type_for([b4_check]) yycheck[[]] =
+static const ]b4_int_type_for([b4_check])[ yycheck[] =
 {
-  b4_check
+  ]b4_check[
 };
 
-/* YYSTOS[[STATE-NUM]] -- The (internal number of the) accessing
+/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
    symbol of state STATE-NUM.  */
-static const b4_int_type_for([b4_stos]) yystos[[]] =
+static const ]b4_int_type_for([b4_stos])[ yystos[] =
 {
-  b4_stos[
+  ]b4_stos[
 };
 
 #if ! defined (YYSIZE_T) && defined (__SIZE_TYPE__)
@@ -529,11 +529,13 @@ do {						\
   if (yydebug)					\
     YYFPRINTF Args;				\
 } while (0)
+
 # define YYDSYMPRINT(Args)			\
 do {						\
   if (yydebug)					\
     yysymprint Args;				\
 } while (0)
+
 # define YYDSYMPRINTF(Title, Token, Value, Location)		\
 do {								\
   if (yydebug)							\
@@ -633,7 +635,7 @@ yystpcpy (yydest, yysrc)
 
 #if YYDEBUG
 ]b4_yysymprint_generate([b4_c_function_def])[
-#endif /* YYDEBUG. */
+#endif /* ! YYDEBUG */
 ]b4_yydestruct_generate([b4_c_function_def])
 
 
@@ -647,7 +649,7 @@ int yyparse ();
 # endif
 #else /* ! YYPARSE_PARAM */
 b4_c_function_decl([yyparse], [int], b4_parse_param)
-#endif
+#endif /* ! YYPARSE_PARAM */
 
 
 m4_divert_push([KILL])# ======================== M4 code.
