@@ -112,11 +112,11 @@ m4_define([b4_locuser_args],
 ## ----------------- ##
 
 
-# b4_lhs_value([TYPE])
-# --------------------
-# Expansion of $<TYPE>$.
+# b4_lhs_value(SYMBOL-NUM, [TYPE])
+# --------------------------------
+# Expansion of $$ or $<TYPE>$, for symbol SYMBOL-NUM.
 m4_define([b4_lhs_value],
-[b4_symbol_value([(*yyvalp)], [$1])])
+[b4_symbol_value([(*yyvalp)], [$1], [$2])])
 
 
 # b4_rhs_data(RULE-LENGTH, POS)
@@ -127,12 +127,12 @@ m4_define([b4_rhs_data],
 [((yyGLRStackItem const *)yyvsp)@{YYFILL (b4_subtract([$2], [$1]))@}.yystate])
 
 
-# b4_rhs_value(RULE-LENGTH, NUM, [TYPE])
-# --------------------------------------
-# Expansion of $<TYPE>NUM, where the current rule has RULE-LENGTH
+# b4_rhs_value(RULE-LENGTH, POS, SYMBOL-NUM, [TYPE])
+# --------------------------------------------------
+# Expansion of $<TYPE>POS, where the current rule has RULE-LENGTH
 # symbols on RHS.
 m4_define([b4_rhs_value],
-[b4_symbol_value([b4_rhs_data([$1], [$2]).yysemantics.yysval], [$3])])
+[b4_symbol_value([b4_rhs_data([$1], [$2]).yysemantics.yysval], [$3], [$4])])
 
 
 
@@ -2265,7 +2265,7 @@ yyrecoverSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
   yylval = yyval_default;]b4_locations_if([
   yylloc = yyloc_default;])[
 ]m4_ifdef([b4_initial_action], [
-b4_dollar_pushdef([yylval], [], [yylloc])dnl
+b4_dollar_pushdef([yylval], [], [], [yylloc])dnl
   b4_user_initial_action
 b4_dollar_popdef])[]dnl
 [
