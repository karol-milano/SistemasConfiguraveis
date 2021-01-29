@@ -117,7 +117,7 @@ m4_define([b4_lhs_value],
 # Expand to the semantic stack place that contains value and location
 # of symbol number NUM in a rule of length RULE-LENGTH.
 m4_define([b4_rhs_data],
-[((yyGLRStackItem const *)yyvsp)@{YYFILL (($2) - ($1))@}.yystate])
+[((yyGLRStackItem const *)yyvsp)@{YYFILL (b4_subtract([$2], [$1]))@}.yystate])
 
 
 # b4_rhs_value(RULE-LENGTH, NUM, [TYPE])
