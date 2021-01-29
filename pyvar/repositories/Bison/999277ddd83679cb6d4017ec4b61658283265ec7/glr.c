@@ -114,23 +114,21 @@ m4_define([b4_locuser_args],
 
 # b4_lhs_value(SYMBOL-NUM, [TYPE])
 # --------------------------------
-# Expansion of $$ or $<TYPE>$, for symbol SYMBOL-NUM.
+# See README.
 m4_define([b4_lhs_value],
 [b4_symbol_value([(*yyvalp)], [$1], [$2])])
 
 
 # b4_rhs_data(RULE-LENGTH, POS)
 # -----------------------------
-# Expand to the semantic stack place that contains value and location
-# of symbol number POS in a rule of length RULE-LENGTH.
+# See README.
 m4_define([b4_rhs_data],
 [((yyGLRStackItem const *)yyvsp)@{YYFILL (b4_subtract([$2], [$1]))@}.yystate])
 
 
 # b4_rhs_value(RULE-LENGTH, POS, SYMBOL-NUM, [TYPE])
 # --------------------------------------------------
-# Expansion of $<TYPE>POS, where the current rule has RULE-LENGTH
-# symbols on RHS.
+# Expansion of $$ or $<TYPE>$, for symbol SYMBOL-NUM.
 m4_define([b4_rhs_value],
 [b4_symbol_value([b4_rhs_data([$1], [$2]).yysemantics.yysval], [$3], [$4])])
 
