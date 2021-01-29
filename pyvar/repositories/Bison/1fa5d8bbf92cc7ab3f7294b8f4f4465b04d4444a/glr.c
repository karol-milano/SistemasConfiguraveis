@@ -109,7 +109,15 @@ m4_define([b4_pure_formals],
 # --------------------
 # Expansion of $<TYPE>$.
 m4_define([b4_lhs_value],
-[((*yyvalp)[]m4_ifval([$1], [.$1]))])
+[b4_symbol_value([(*yyvalp)], [$1])])
+
+
+# b4_rhs_data(RULE-LENGTH, NUM)
+# -----------------------------
+# Expand to the semantic stack place that contains value and location
+# of symbol number NUM in a rule of length RULE-LENGTH.
+m4_define([b4_rhs_data],
+[((yyGLRStackItem const *)yyvsp)@{YYFILL (($2) - ($1))@}.yystate])
 
 
 # b4_rhs_value(RULE-LENGTH, NUM, [TYPE])
@@ -117,7 +125,7 @@ m4_define([b4_lhs_value],
 # Expansion of $<TYPE>NUM, where the current rule has RULE-LENGTH
 # symbols on RHS.
 m4_define([b4_rhs_value],
-[(((yyGLRStackItem const *)yyvsp)@{YYFILL (($2) - ($1))@}.yystate.yysemantics.yysval[]m4_ifval([$3], [.$3]))])
+[b4_symbol_value([b4_rhs_data([$1], [$2]).yysemantics.yysval], [$3])])
 
 
 
@@ -137,7 +145,7 @@ m4_define([b4_lhs_location],
 # Expansion of @NUM, where the current rule has RULE-LENGTH symbols
 # on RHS.
 m4_define([b4_rhs_location],
-[(((yyGLRStackItem const *)yyvsp)@{YYFILL (($2) - ($1))@}.yystate.yyloc)])
+[(b4_rhs_data([$1], [$2]).yyloc)])
 
 
 
