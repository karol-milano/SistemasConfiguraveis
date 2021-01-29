@@ -442,7 +442,7 @@ static const ]b4_int_type_for([b4_pgoto])[ yypgoto[] =
 
 /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
    positive, shift that token.  If negative, reduce the rule which
-   number is the opposite.  If zero or YYTABLE_NINF, syntax error.  */
+   number is the opposite.  If YYTABLE_NINF, syntax error.  */
 #define YYTABLE_NINF ]b4_table_ninf[
 static const ]b4_int_type_for([b4_table])[ yytable[] =
 {
@@ -1031,8 +1031,7 @@ yydefaultAction (yyStateNum yystate)
 }
 
 #define yytable_value_is_error(yytable_value) \
-  (]b4_table_value_equals([[table]], [[yytable_value]], [b4_table_ninf])[ \
-   || ]b4_table_value_equals([[table]], [[yytable_value]], [[0]])[)
+  ]b4_table_value_equals([[table]], [[yytable_value]], [b4_table_ninf])[
 
 /** Set *YYACTION to the action to take in YYSTATE on seeing YYTOKEN.
  *  Result R means
