@@ -119,10 +119,10 @@ m4_define([b4_lhs_value],
 [b4_symbol_value([(*yyvalp)], [$1])])
 
 
-# b4_rhs_data(RULE-LENGTH, NUM)
+# b4_rhs_data(RULE-LENGTH, POS)
 # -----------------------------
 # Expand to the semantic stack place that contains value and location
-# of symbol number NUM in a rule of length RULE-LENGTH.
+# of symbol number POS in a rule of length RULE-LENGTH.
 m4_define([b4_rhs_data],
 [((yyGLRStackItem const *)yyvsp)@{YYFILL (b4_subtract([$2], [$1]))@}.yystate])
 
