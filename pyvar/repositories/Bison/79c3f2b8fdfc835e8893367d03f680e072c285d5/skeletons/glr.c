@@ -159,7 +159,7 @@ m4_if(b4_skeleton, ["glr.c"],
 ]b4_percent_code_get([[requires]])[
 ]b4_token_enums[
 ]b4_declare_yylstype[
-]b4_function_declare(b4_prefix[parse], [int], b4_parse_param)[
+int ]b4_prefix[parse (]m4_ifset([b4_parse_param], [b4_formals(b4_parse_param)], [void])[);
 ]b4_percent_code_get([[provides]])[]dnl
 ])
 ])
@@ -2394,7 +2394,8 @@ yyrecoverSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
 | yyparse.  |
 `----------*/
 
-]b4_function_define([yyparse], [int], b4_parse_param)[
+int
+yyparse (]m4_ifset([b4_parse_param], [b4_formals(b4_parse_param)], [void])[)
 {
   int yyresult;
   yyGLRStack yystack;
