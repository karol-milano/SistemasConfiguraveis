@@ -1014,9 +1014,7 @@ yylhsNonterm (yyRuleNum yyrule)
 }
 
 #define yyis_pact_ninf(yystate) \
-  ]m4_if(m4_eval(b4_pact_ninf < b4_pact_min), [1],
-	 [0],
-	 [((yystate) == YYPACT_NINF)])[
+  ]b4_table_value_equals([[pact]], [[yystate]], [b4_pact_ninf])[
 
 /** True iff LR state STATE has only a default reduction (regardless
  *  of token).  */
@@ -1034,9 +1032,7 @@ yydefaultAction (yyStateNum yystate)
 }
 
 #define yyis_table_ninf(yytable_value) \
-  ]m4_if(m4_eval(b4_table_ninf < b4_table_min), [1],
-	 [YYID (0)],
-	 [((yytable_value) == YYTABLE_NINF)])[
+  ]b4_table_value_equals([[table]], [[yytable_value]], [b4_table_ninf])[
 
 /** Set *YYACTION to the action to take in YYSTATE on seeing YYTOKEN.
  *  Result R means
@@ -2119,7 +2115,8 @@ yyreportSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
 	  char const *yyprefix = yyexpecting;
 
 	  /* Start YYX at -YYN if negative to avoid negative indexes in
-	     YYCHECK.  */
+	     YYCHECK.  In other words, skip the first -YYN actions for this
+	     state because they are default actions.  */
 	  int yyxbegin = yyn < 0 ? -yyn : 0;
 
 	  /* Stay within bounds of both yycheck and yytname.  */
