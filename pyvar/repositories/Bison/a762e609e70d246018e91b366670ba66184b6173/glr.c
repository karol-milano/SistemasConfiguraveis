@@ -241,7 +241,7 @@ static YYLTYPE yyloc_default;
   ((unsigned)(YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)
 
 /* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
-static const ]b4_uint_type(b4_translate_max)[ yytranslate[] =
+static const ]b4_int_type_for([b4_translate])[ yytranslate[] =
 {
   ]b4_translate[
 };
@@ -249,19 +249,19 @@ static const ]b4_uint_type(b4_translate_max)[ yytranslate[] =
 #if YYDEBUG
 /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
    YYRHS.  */
-static const ]b4_uint_type(b4_prhs_max)[ yyprhs[] =
+static const ]b4_int_type_for([b4_prhs])[ yyprhs[] =
 {
   ]b4_prhs[
 };
 
 /* YYRHS -- A `-1'-separated list of the rules' RHS. */
-static const ]b4_sint_type(b4_rhs_max)[ yyrhs[] =
+static const ]b4_int_type_for([b4_rhs])[ yyrhs[] =
 {
   ]b4_rhs[
 };
 
 /* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
-static const ]b4_uint_type(b4_rline_max)[ yyrline[] =
+static const ]b4_int_type_for([b4_rline])[ yyrline[] =
 {
   ]b4_rline[
 };
@@ -279,25 +279,25 @@ static const char *const yytname[] =
 #endif
 
 /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
-static const ]b4_uint_type(b4_r1_max)[ yyr1[] =
+static const ]b4_int_type_for([b4_r1])[ yyr1[] =
 {
   ]b4_r1[
 };
 
 /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
-static const ]b4_uint_type(b4_r2_max)[ yyr2[] =
+static const ]b4_int_type_for([b4_r2])[ yyr2[] =
 {
   ]b4_r2[
 };
 
 /* YYDPREC[RULE-NUM] -- Dynamic precedence of rule #RULE-NUM (0 if none). */
-static const short yydprec[] =
+static const ]b4_int_type_for([b4_dprec])[ yydprec[] =
 {
   ]b4_dprec[
 };
 
 /* YYMERGER[RULE-NUM] -- Index of merging function for rule #RULE-NUM. */
-static const short yymerger[] =
+static const ]b4_int_type_for([b4_merger])[ yymerger[] =
 {
   ]b4_merger[
 };
@@ -305,13 +305,13 @@ static const short yymerger[] =
 /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
    doesn't specify something else to do.  Zero means the default is an
    error.  */
-static const short yydefact[] =
+static const ]b4_int_type_for([b4_defact])[ yydefact[] =
 {
   ]b4_defact[
 };
 
 /* YYPDEFGOTO[NTERM-NUM]. */
-static const short yydefgoto[] =
+static const ]b4_int_type_for([b4_defgoto])[ yydefgoto[] =
 {
   ]b4_defgoto[
 };
@@ -319,13 +319,13 @@ static const short yydefgoto[] =
 /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
    STATE-NUM.  */
 #define YYPACT_NINF ]b4_pact_ninf[
-static const ]b4_sint_type(b4_pact_max)[ yypact[] =
+static const ]b4_int_type_for([b4_pact])[ yypact[] =
 {
   ]b4_pact[
 };
 
 /* YYPGOTO[NTERM-NUM].  */
-static const short yypgoto[] =
+static const ]b4_int_type_for([b4_pgoto])[ yypgoto[] =
 {
   ]b4_pgoto[
 };
@@ -334,7 +334,7 @@ static const short yypgoto[] =
    positive, shift that token.  If negative, reduce the rule which
    number is the opposite.  If zero, do what YYDEFACT says.  */
 #define YYTABLE_NINF ]b4_table_ninf[
-static const ]b4_sint_type(b4_table_max)[ yytable[] =
+static const ]b4_int_type_for([b4_table])[ yytable[] =
 {
   ]b4_table[
 };
@@ -343,19 +343,22 @@ static const ]b4_sint_type(b4_table_max)[ yytable[] =
    of conflicting reductions corresponding to action entry for state
    STATE-NUM in yytable.  0 means no conflicts.  The list in yyconfl
    is terminated by a rule number of 0. */
-static const short yyconflp[] =
+static const ]b4_int_type_for([b4_conflict_list_heads])[ yyconflp[] =
 {
   ]b4_conflict_list_heads[
 };
 
 /* YYCONFL[I] -- lists of conflicting rule numbers, each terminated
    by 0, pointed into by YYCONFLP. */
-static const short yyconfl[] =
+]dnl Do not use b4_int_type_for here, since there are places where
+dnl pointers onto yyconfl are taken, which type is "short *".
+dnl We probably ought to introduce a type for confl.
+[static const short yyconfl[] =
 {
   ]b4_conflicting_rules[
 };
 
-static const short yycheck[] =
+static const ]b4_int_type_for([b4_check])[ yycheck[] =
 {
   ]b4_check[
 };
