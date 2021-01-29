@@ -531,8 +531,7 @@ static const ]b4_int_type_for([b4_toknum])[ yytoknum[] =
 #define YYTABLE_NINF ]b4_table_ninf[
 
 #define yytable_value_is_error(yytable_value) \
-  (]b4_table_value_equals([[table]], [[yytable_value]], [b4_table_ninf])[ \
-  || ]b4_table_value_equals([[table]], [[yytable_value]], [[0]])[)
+  ]b4_table_value_equals([[table]], [[yytable_value]], [b4_table_ninf])[
 
 ]b4_parser_tables_define[
 
