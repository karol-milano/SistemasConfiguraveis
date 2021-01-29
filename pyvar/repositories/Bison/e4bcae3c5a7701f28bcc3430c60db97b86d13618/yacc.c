@@ -578,7 +578,7 @@ static const ]b4_int_type_for([b4_pgoto])[ yypgoto[] =
 
 /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
    positive, shift that token.  If negative, reduce the rule which
-   number is the opposite.  If zero or YYTABLE_NINF, syntax error.  */
+   number is the opposite.  If YYTABLE_NINF, syntax error.  */
 #define YYTABLE_NINF ]b4_table_ninf[
 static const ]b4_int_type_for([b4_table])[ yytable[] =
 {
@@ -589,8 +589,7 @@ static const ]b4_int_type_for([b4_table])[ yytable[] =
   ]b4_table_value_equals([[pact]], [[yystate]], [b4_pact_ninf])[
 
 #define yytable_value_is_error(yytable_value) \
-  (]b4_table_value_equals([[table]], [[yytable_value]], [b4_table_ninf])[ \
-  || ]b4_table_value_equals([[table]], [[yytable_value]], [[0]])[)
+  ]b4_table_value_equals([[table]], [[yytable_value]], [b4_table_ninf])[
 
 static const ]b4_int_type_for([b4_check])[ yycheck[] =
 {
