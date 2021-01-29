@@ -124,7 +124,7 @@ m4_define([b4_lhs_value],
 # Expansion of $<TYPE>NUM, where the current rule has RULE-LENGTH
 # symbols on RHS.
 m4_define([b4_rhs_value],
-[b4_symbol_value([yyvsp@{($2) - ($1)@}], [$3])])
+          [b4_symbol_value([yyvsp@{b4_subtract([$2], [$1])@}], [$3])])
 
 
 
@@ -144,7 +144,7 @@ m4_define([b4_lhs_location],
 # Expansion of @NUM, where the current rule has RULE-LENGTH symbols
 # on RHS.
 m4_define([b4_rhs_location],
-[(yylsp@{($2) - ($1)@})])
+          [(yylsp@{b4_subtract([$2], [$1])@})])
 
 
 
