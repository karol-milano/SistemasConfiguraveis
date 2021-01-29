@@ -111,7 +111,7 @@ m4_define([b4_lhs_value],
 # Expansion of $<TYPE>NUM, where the current rule has RULE-LENGTH
 # symbols on RHS.
 m4_define([b4_rhs_value],
-[yyvsp@{YYFILL (m4_eval([$2 - $1]))@}.yystate.yysemantics.yysval[]m4_ifval([$3], [.$3])])
+[((yyGLRStackItem const *)yyvsp)@{YYFILL (m4_eval([$2 - $1]))@}.yystate.yysemantics.yysval[]m4_ifval([$3], [.$3])])
 
 
 
@@ -131,7 +131,7 @@ m4_define([b4_lhs_location],
 # Expansion of @NUM, where the current rule has RULE-LENGTH symbols
 # on RHS.
 m4_define([b4_rhs_location],
-[yyvsp@{YYFILL (m4_eval([$2 - $1]))@}.yystate.yyloc])
+[((yyGLRStackItem const *)yyvsp)@{YYFILL (m4_eval([$2 - $1]))@}.yystate.yyloc])
 
 # We do want M4 expansion after # for CPP macros.
 m4_changecom()
