@@ -36,8 +36,10 @@ m4_define_default([b4_stack_depth_init],  [200])
 
 # b4_user_formals
 # ---------------
-# This is specific to GLR because it relies on ISO C formal argument
-# declarations.
+# The possible parse-params formal arguments preceded by a comma.
+#
+# This is not shared with yacc.c in c.m4 because  GLR relies on ISO C
+# formal argument declarations.
 m4_define([b4_user_formals],
 [m4_ifset([b4_parse_param], [, b4_c_ansi_formals(b4_parse_param)])])
 
@@ -54,7 +56,8 @@ m4_ifdef([b4_lex_param], [, ]b4_lex_param)))
 
 # b4_yyerror_args
 # ---------------
-# Arguments passed to yyerror: user args plus yylloc.
+# Optional effective arguments passed to yyerror: user args plus yylloc, and
+# a trailing comma.
 m4_define([b4_yyerror_args],
 [b4_pure_if([b4_location_if([yylocp, ])])dnl
 m4_ifset([b4_parse_param], [b4_c_args(b4_parse_param), ])])
@@ -70,18 +73,11 @@ m4_ifset([b4_parse_param], [b4_c_args(b4_parse_param), ])])
 
 # b4_pure_args
 # ------------
-# Arguments needed by yyerror: user args plus yylloc.
+# Same as b4_yyerror_args, but with a leading comma.
 m4_define([b4_pure_args],
 [b4_pure_if([b4_location_if([, yylocp])])[]b4_user_args])
 
 
-# b4_pure_formals
-# ---------------
-# Arguments passed to yyerror: user formals plus yyllocp.
-m4_define([b4_pure_formals],
-[b4_pure_if([b4_location_if([, YYLTYPE *yylocp])])[]b4_user_formals])
-
-
 # b4_lpure_args
 # -------------
 # Same as above, but on the look-ahead, hence yyllocp instead of yylocp.
@@ -89,6 +85,13 @@ m4_define([b4_lpure_args],
 [b4_pure_if([b4_location_if([, yyllocp])])[]b4_user_args])
 
 
+# b4_pure_formals
+# ---------------
+# Arguments passed to yyerror: user formals plus yyllocp.
+m4_define([b4_pure_formals],
+[b4_pure_if([b4_location_if([, YYLTYPE *yylocp])])[]b4_user_formals])
+
+
 # b4_lpure_formals
 # ----------------
 # Same as above, but on the look-ahead, hence yyllocp instead of yylocp.
