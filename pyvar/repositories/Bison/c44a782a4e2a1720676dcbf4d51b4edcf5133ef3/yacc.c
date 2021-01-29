@@ -128,19 +128,19 @@ m4_define([b4_int_type],
 ## ----------------- ##
 
 
-# b4_lhs_value([TYPE])
-# --------------------
-# Expansion of $<TYPE>$.
+# b4_lhs_value(SYMBOL-NUM, [TYPE])
+# --------------------------------
+# Expansion of $$ or $<TYPE>$, for symbol SYMBOL-NUM.
 m4_define([b4_lhs_value],
-[b4_symbol_value(yyval, [$1])])
+[b4_symbol_value(yyval, [$1], [$2])])
 
 
-# b4_rhs_value(RULE-LENGTH, NUM, [TYPE])
-# --------------------------------------
-# Expansion of $<TYPE>NUM, where the current rule has RULE-LENGTH
+# b4_rhs_value(RULE-LENGTH, POS, SYMBOL-NUM, [TYPE])
+# --------------------------------------------------
+# Expansion of $<TYPE>POS, where the current rule has RULE-LENGTH
 # symbols on RHS.
 m4_define([b4_rhs_value],
-          [b4_symbol_value([yyvsp@{b4_subtract([$2], [$1])@}], [$3])])
+[b4_symbol_value([yyvsp@{b4_subtract([$2], [$1])@}], [$3], [$4])])
 
 
 ## ----------- ##
@@ -1426,7 +1426,7 @@ b4_function_define([[yyparse]], [[int]], b4_parse_param)[
   yynerrs = 0;
   yychar = YYEMPTY; /* Cause a token to be read.  */
 ]m4_ifdef([b4_initial_action], [
-b4_dollar_pushdef([m4_define([b4_dollar_dollar_used])yylval], [],
+b4_dollar_pushdef([m4_define([b4_dollar_dollar_used])yylval], [], [],
                   [b4_push_if([b4_pure_if([*])yypushed_loc], [yylloc])])dnl
 b4_user_initial_action
 b4_dollar_popdef[]dnl
