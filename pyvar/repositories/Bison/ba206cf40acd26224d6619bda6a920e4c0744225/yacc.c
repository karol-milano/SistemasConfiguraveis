@@ -501,11 +501,8 @@ static const ]b4_int_type_for([b4_translate])[ yytranslate[] =
 };
 
 #if YYDEBUG
-/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
-static const ]b4_int_type_for([b4_rline])[ yyrline[] =
-{
-  ]b4_rline[
-};
+]b4_integral_parser_table_define([rline], [b4_rline],
+     [YYRLINE[YYN] -- Source line where rule number YYN was defined.])[
 #endif
 
 #if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
@@ -530,7 +527,7 @@ static const ]b4_int_type_for([b4_toknum])[ yytoknum[] =
 
 #define YYTABLE_NINF ]b4_table_ninf[
 
-]b4_tables_define[
+]b4_parser_tables_define[
 
 #define yyerrok		(yyerrstatus = 0)
 #define yyclearin	(yychar = YYEMPTY)
