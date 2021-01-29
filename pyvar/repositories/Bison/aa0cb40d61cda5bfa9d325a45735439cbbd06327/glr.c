@@ -972,8 +972,7 @@ yydefaultAction (yyStateNum yystate)
 }
 
 #define yytable_value_is_error(yytable_value) \
-  (]b4_table_value_equals([[table]], [[yytable_value]], [b4_table_ninf])[ \
-   || ]b4_table_value_equals([[table]], [[yytable_value]], [[0]])[)
+  ]b4_table_value_equals([[table]], [[yytable_value]], [b4_table_ninf])[
 
 /** Set *YYACTION to the action to take in YYSTATE on seeing YYTOKEN.
  *  Result R means
