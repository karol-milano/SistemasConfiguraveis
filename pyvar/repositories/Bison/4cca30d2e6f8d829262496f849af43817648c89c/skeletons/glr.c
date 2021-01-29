@@ -46,16 +46,6 @@ m4_ifndef([b4_pure_flag],
  m4_define([b4_pure_flag],
            [b4_percent_define_flag_if([[api.pure]], [[1]], [[0]])])])
 
-# b4_user_formals
-# ---------------
-# The possible parse-params formal arguments preceded by a comma.
-#
-# This is not shared with yacc.c in c.m4 because  GLR relies on ISO C
-# formal argument declarations.
-m4_define([b4_user_formals],
-[m4_ifset([b4_parse_param], [, b4_formals(b4_parse_param)])])
-
-
 # b4_yyerror_args
 # ---------------
 # Optional effective arguments passed to yyerror: user args plus yylloc, and
