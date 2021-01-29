@@ -645,8 +645,8 @@ static const ]b4_int_type_for([b4_toknum])[ yytoknum[] =
 
 #define YYPACT_NINF ]b4_pact_ninf[
 
-#define yypact_value_is_default(Yystate) \
-  ]b4_table_value_equals([[pact]], [[Yystate]], [b4_pact_ninf])[
+#define yypact_value_is_default(Yyn) \
+  ]b4_table_value_equals([[pact]], [[Yyn]], [b4_pact_ninf])[
 
 #define YYTABLE_NINF ]b4_table_ninf[
 
