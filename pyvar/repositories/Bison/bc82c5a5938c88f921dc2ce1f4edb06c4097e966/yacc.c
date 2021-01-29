@@ -93,7 +93,7 @@ m4_define([b4_int_type],
 # --------------------
 # Expansion of $<TYPE>$.
 m4_define([b4_lhs_value],
-[yyval[]m4_ifval([$1], [.$1])])
+[(yyval[]m4_ifval([$1], [.$1]))])
 
 
 # b4_rhs_value(RULE-LENGTH, NUM, [TYPE])
@@ -101,7 +101,7 @@ m4_define([b4_lhs_value],
 # Expansion of $<TYPE>NUM, where the current rule has RULE-LENGTH
 # symbols on RHS.
 m4_define([b4_rhs_value],
-[yyvsp@{m4_eval([$2 - $1])@}m4_ifval([$3], [.$3])])
+[(yyvsp@{m4_eval([$2 - $1])@}m4_ifval([$3], [.$3]))])
 
 
 
@@ -113,7 +113,7 @@ m4_define([b4_rhs_value],
 # -----------------
 # Expansion of @$.
 m4_define([b4_lhs_location],
-[yyloc])
+[(yyloc)])
 
 
 # b4_rhs_location(RULE-LENGTH, NUM)
@@ -121,7 +121,7 @@ m4_define([b4_lhs_location],
 # Expansion of @NUM, where the current rule has RULE-LENGTH symbols
 # on RHS.
 m4_define([b4_rhs_location],
-[yylsp@{m4_eval([$2 - $1])@}])
+[(yylsp@{m4_eval([$2 - $1])@})])
 
 
 
