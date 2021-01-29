@@ -375,8 +375,8 @@ static const char *const yytname[] =
 };
 #endif
 
-#define YYPACT_NINF ]b4_pact_ninf[
-#define YYTABLE_NINF ]b4_table_ninf[
+#define YYPACT_NINF (]b4_pact_ninf[)
+#define YYTABLE_NINF (]b4_table_ninf[)
 
 ]b4_parser_tables_define[
 
@@ -968,7 +968,7 @@ yylhsNonterm (yyRuleNum yyrule)
 }
 
 #define yypact_value_is_default(Yyn) \
-  ]b4_table_value_equals([[pact]], [[Yyn]], [b4_pact_ninf])[
+  ]b4_table_value_equals([[pact]], [[Yyn]], [b4_pact_ninf], [YYPACT_NINF])[
 
 /** True iff LR state YYSTATE has only a default reduction (regardless
  *  of token).  */
@@ -985,8 +985,8 @@ yydefaultAction (yyStateNum yystate)
   return yydefact[yystate];
 }
 
-#define yytable_value_is_error(Yytable_value) \
-  ]b4_table_value_equals([[table]], [[Yytable_value]], [b4_table_ninf])[
+#define yytable_value_is_error(Yyn) \
+  ]b4_table_value_equals([[table]], [[Yyn]], [b4_table_ninf], [YYTABLE_NINF])[
 
 /** The action to take in YYSTATE on seeing YYTOKEN.
  *  Result R means
