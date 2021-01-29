@@ -643,15 +643,15 @@ static const ]b4_int_type_for([b4_toknum])[ yytoknum[] =
 };
 # endif
 
-#define YYPACT_NINF ]b4_pact_ninf[
+#define YYPACT_NINF (]b4_pact_ninf[)
 
 #define yypact_value_is_default(Yyn) \
-  ]b4_table_value_equals([[pact]], [[Yyn]], [b4_pact_ninf])[
+  ]b4_table_value_equals([[pact]], [[Yyn]], [b4_pact_ninf], [YYPACT_NINF])[
 
-#define YYTABLE_NINF ]b4_table_ninf[
+#define YYTABLE_NINF (]b4_table_ninf[)
 
-#define yytable_value_is_error(Yytable_value) \
-  ]b4_table_value_equals([[table]], [[Yytable_value]], [b4_table_ninf])[
+#define yytable_value_is_error(Yyn) \
+  ]b4_table_value_equals([[table]], [[Yyn]], [b4_table_ninf], [YYTABLE_NINF])[
 
 ]b4_parser_tables_define[
 
