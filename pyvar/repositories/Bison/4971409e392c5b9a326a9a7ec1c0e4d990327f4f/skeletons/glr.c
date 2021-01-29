@@ -967,8 +967,8 @@ yylhsNonterm (yyRuleNum yyrule)
   return yyr1[yyrule];
 }
 
-#define yypact_value_is_default(Yystate) \
-  ]b4_table_value_equals([[pact]], [[Yystate]], [b4_pact_ninf])[
+#define yypact_value_is_default(Yyn) \
+  ]b4_table_value_equals([[pact]], [[Yyn]], [b4_pact_ninf])[
 
 /** True iff LR state YYSTATE has only a default reduction (regardless
  *  of token).  */
