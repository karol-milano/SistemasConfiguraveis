@@ -323,7 +323,7 @@ b4_location_if(
   ((unsigned)(X) <= YYMAXUTOK ? yytranslate[[X]] : YYUNDEFTOK)
 
 /* YYTRANSLATE[[YYLEX]] -- Bison symbol number corresponding to YYLEX.  */
-static const b4_uint_type(b4_translate_max) yytranslate[[]] =
+static const b4_int_type_for([b4_translate]) yytranslate[[]] =
 {
   b4_translate
 };
@@ -331,19 +331,19 @@ static const b4_uint_type(b4_translate_max) yytranslate[[]] =
 #if YYDEBUG
 /* YYPRHS[[YYN]] -- Index of the first RHS symbol of rule number YYN in
    YYRHS.  */
-static const b4_uint_type(b4_prhs_max) yyprhs[[]] =
+static const b4_int_type_for([b4_prhs]) yyprhs[[]] =
 {
   b4_prhs
 };
 
 /* YYRHS -- A `-1'-separated list of the rules' RHS. */
-static const b4_sint_type(b4_rhs_max) yyrhs[[]] =
+static const b4_int_type_for([b4_rhs]) yyrhs[[]] =
 {
   b4_rhs
 };
 
 /* YYRLINE[[YYN]] -- source line where rule number YYN was defined.  */
-static const b4_uint_type(b4_rline_max) yyrline[[]] =
+static const b4_int_type_for([b4_rline]) yyrline[[]] =
 {
   b4_rline
 };
@@ -360,19 +360,19 @@ static const char *const yytname[[]] =
 
 /* YYTOKNUM[[YYLEX-NUM]] -- Internal token number corresponding to
    token YYLEX-NUM.  */
-static const short yytoknum[[]] =
+static const b4_int_type_for([b4_toknum]) yytoknum[[]] =
 {
   b4_toknum
 };
 
 /* YYR1[[YYN]] -- Symbol number of symbol that rule YYN derives.  */
-static const b4_uint_type(b4_r1_max) yyr1[[]] =
+static const b4_int_type_for([b4_r1]) yyr1[[]] =
 {
   b4_r1
 };
 
 /* YYR2[[YYN]] -- Number of symbols composing right hand side of rule YYN.  */
-static const b4_uint_type(b4_r2_max) yyr2[[]] =
+static const b4_int_type_for([b4_r2]) yyr2[[]] =
 {
   b4_r2
 };
@@ -380,13 +380,13 @@ static const b4_uint_type(b4_r2_max) yyr2[[]] =
 /* YYDEFACT[[STATE-NAME]] -- Default rule to reduce with in state
    STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
    means the default is an error.  */
-static const short yydefact[[]] =
+static const b4_int_type_for([b4_defact]) yydefact[[]] =
 {
   b4_defact
 };
 
 /* YYDEFGOTO[[NTERM-NUM]]. */
-static const short yydefgoto[[]] =
+static const b4_int_type_for([b4_defgoto]) yydefgoto[[]] =
 {
   b4_defgoto
 };
@@ -394,13 +394,13 @@ static const short yydefgoto[[]] =
 /* YYPACT[[STATE-NUM]] -- Index in YYTABLE of the portion describing
    STATE-NUM.  */
 #define YYPACT_NINF b4_pact_ninf
-static const b4_sint_type(b4_pact_max) yypact[[]] =
+static const b4_int_type_for([b4_pact]) yypact[[]] =
 {
   b4_pact
 };
 
 /* YYPGOTO[[NTERM-NUM]].  */
-static const short yypgoto[[]] =
+static const b4_int_type_for([b4_pgoto]) yypgoto[[]] =
 {
   b4_pgoto
 };
@@ -409,19 +409,19 @@ static const short yypgoto[[]] =
    positive, shift that token.  If negative, reduce the rule which
    number is the opposite.  If zero, do what YYDEFACT says.  */
 #define YYTABLE_NINF b4_table_ninf
-static const b4_sint_type(b4_table_max) yytable[[]] =
+static const b4_int_type_for([b4_table]) yytable[[]] =
 {
   b4_table
 };
 
-static const short yycheck[[]] =
+static const b4_int_type_for([b4_check]) yycheck[[]] =
 {
   b4_check
 };
 
 /* YYSTOS[[STATE-NUM]] -- The (internal number of the) accessing
    symbol of state STATE-NUM.  */
-static const b4_uint_type(b4_stos_max) yystos[[]] =
+static const b4_int_type_for([b4_stos]) yystos[[]] =
 {
   b4_stos
 };
