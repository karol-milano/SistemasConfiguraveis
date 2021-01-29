@@ -383,17 +383,10 @@ static const char *const yytname[] =
 };
 #endif
 
-/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
-static const ]b4_int_type_for([b4_r1])[ yyr1[] =
-{
-  ]b4_r1[
-};
+#define YYPACT_NINF ]b4_pact_ninf[
+#define YYTABLE_NINF ]b4_table_ninf[
 
-/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
-static const ]b4_int_type_for([b4_r2])[ yyr2[] =
-{
-  ]b4_r2[
-};
+]b4_parser_tables_define[
 
 /* YYDPREC[RULE-NUM] -- Dynamic precedence of rule #RULE-NUM (0 if none).  */
 static const ]b4_int_type_for([b4_dprec])[ yydprec[] =
@@ -407,44 +400,6 @@ static const ]b4_int_type_for([b4_merger])[ yymerger[] =
   ]b4_merger[
 };
 
-/* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
-   doesn't specify something else to do.  Zero means the default is an
-   error.  */
-static const ]b4_int_type_for([b4_defact])[ yydefact[] =
-{
-  ]b4_defact[
-};
-
-/* YYPDEFGOTO[NTERM-NUM].  */
-static const ]b4_int_type_for([b4_defgoto])[ yydefgoto[] =
-{
-  ]b4_defgoto[
-};
-
-/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
-   STATE-NUM.  */
-#define YYPACT_NINF ]b4_pact_ninf[
-static const ]b4_int_type_for([b4_pact])[ yypact[] =
-{
-  ]b4_pact[
-};
-
-/* YYPGOTO[NTERM-NUM].  */
-static const ]b4_int_type_for([b4_pgoto])[ yypgoto[] =
-{
-  ]b4_pgoto[
-};
-
-/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
-   positive, shift that token.  If negative, reduce the rule which
-   number is the opposite.  If zero, do what YYDEFACT says.
-   If YYTABLE_NINF, syntax error.  */
-#define YYTABLE_NINF ]b4_table_ninf[
-static const ]b4_int_type_for([b4_table])[ yytable[] =
-{
-  ]b4_table[
-};
-
 /* YYCONFLP[YYPACT[STATE-NUM]] -- Pointer into YYCONFL of start of
    list of conflicting reductions corresponding to action entry for
    state STATE-NUM in yytable.  0 means no conflicts.  The list in
@@ -463,19 +418,6 @@ dnl We probably ought to introduce a type for confl.
 {
   ]b4_conflicting_rules[
 };
-
-static const ]b4_int_type_for([b4_check])[ yycheck[] =
-{
-  ]b4_check[
-};
-
-/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
-   symbol of state STATE-NUM.  */
-static const ]b4_int_type_for([b4_stos])[ yystos[] =
-{
-  ]b4_stos[
-};
-
 
 /* Prevent warning if -Wmissing-prototypes.  */
 ]b4_c_ansi_function_decl([yyparse], [int], b4_parse_param)[
