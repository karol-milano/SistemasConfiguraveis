@@ -526,67 +526,11 @@ static const ]b4_int_type_for([b4_toknum])[ yytoknum[] =
 };
 # endif
 
-/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
-static const ]b4_int_type_for([b4_r1])[ yyr1[] =
-{
-  ]b4_r1[
-};
-
-/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
-static const ]b4_int_type_for([b4_r2])[ yyr2[] =
-{
-  ]b4_r2[
-};
-
-/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
-   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
-   means the default is an error.  */
-static const ]b4_int_type_for([b4_defact])[ yydefact[] =
-{
-  ]b4_defact[
-};
-
-/* YYDEFGOTO[NTERM-NUM].  */
-static const ]b4_int_type_for([b4_defgoto])[ yydefgoto[] =
-{
-  ]b4_defgoto[
-};
-
-/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
-   STATE-NUM.  */
 #define YYPACT_NINF ]b4_pact_ninf[
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
 
-/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
-   positive, shift that token.  If negative, reduce the rule which
-   number is the opposite.  If zero, do what YYDEFACT says.
-   If YYTABLE_NINF, syntax error.  */
 #define YYTABLE_NINF ]b4_table_ninf[
-static const ]b4_int_type_for([b4_table])[ yytable[] =
-{
-  ]b4_table[
-};
-
-static const ]b4_int_type_for([b4_check])[ yycheck[] =
-{
-  ]b4_check[
-};
 
-/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
-   symbol of state STATE-NUM.  */
-static const ]b4_int_type_for([b4_stos])[ yystos[] =
-{
-  ]b4_stos[
-};
+]b4_tables_define[
 
 #define yyerrok		(yyerrstatus = 0)
 #define yyclearin	(yychar = YYEMPTY)
