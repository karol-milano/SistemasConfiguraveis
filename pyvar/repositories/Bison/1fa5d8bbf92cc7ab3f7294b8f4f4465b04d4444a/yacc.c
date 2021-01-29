@@ -114,7 +114,7 @@ m4_define([b4_int_type],
 # --------------------
 # Expansion of $<TYPE>$.
 m4_define([b4_lhs_value],
-[(yyval[]m4_ifval([$1], [.$1]))])
+[b4_symbol_value(yyval, [$1])])
 
 
 # b4_rhs_value(RULE-LENGTH, NUM, [TYPE])
@@ -122,7 +122,7 @@ m4_define([b4_lhs_value],
 # Expansion of $<TYPE>NUM, where the current rule has RULE-LENGTH
 # symbols on RHS.
 m4_define([b4_rhs_value],
-[(yyvsp@{($2) - ($1)@}m4_ifval([$3], [.$3]))])
+[b4_symbol_value([yyvsp@{($2) - ($1)@}], [$3])])
 
 
 
