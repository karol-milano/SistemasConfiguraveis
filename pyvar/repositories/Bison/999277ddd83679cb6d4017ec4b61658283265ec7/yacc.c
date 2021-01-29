@@ -130,15 +130,14 @@ m4_define([b4_int_type],
 
 # b4_lhs_value(SYMBOL-NUM, [TYPE])
 # --------------------------------
-# Expansion of $$ or $<TYPE>$, for symbol SYMBOL-NUM.
+# See README.
 m4_define([b4_lhs_value],
 [b4_symbol_value(yyval, [$1], [$2])])
 
 
-# b4_rhs_value(RULE-LENGTH, POS, SYMBOL-NUM, [TYPE])
-# --------------------------------------------------
-# Expansion of $<TYPE>POS, where the current rule has RULE-LENGTH
-# symbols on RHS.
+# b4_rhs_value(RULE-LENGTH, POS, [SYMBOL-NUM], [TYPE])
+# ----------------------------------------------------
+# See README.
 m4_define([b4_rhs_value],
 [b4_symbol_value([yyvsp@{b4_subtract([$2], [$1])@}], [$3], [$4])])
 
