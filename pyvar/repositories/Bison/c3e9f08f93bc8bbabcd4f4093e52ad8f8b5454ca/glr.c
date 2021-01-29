@@ -166,6 +166,7 @@ m4_define([b4_shared_declarations],
 [b4_percent_code_get([[requires]])[
 ]b4_token_enums(b4_tokens)[
 ]b4_declare_yylstype[
+]b4_c_ansi_function_decl(b4_prefix[parse], [int], b4_parse_param)[
 ]b4_percent_code_get([[provides]])[]dnl
 ])
 
@@ -472,9 +473,6 @@ static const ]b4_int_type_for([b4_stos])[ yystos[] =
 };
 
 
-/* Prevent warning if -Wmissing-prototypes.  */
-]b4_c_ansi_function_decl([yyparse], [int], b4_parse_param)[
-
 /* Error token number */
 #define YYTERROR 1
 
@@ -2637,15 +2635,12 @@ m4_if(b4_skeleton, ["glr.c"],
 [b4_defines_if(
 [@output(b4_spec_defines_file@)@
 b4_copyright([Skeleton interface for Bison GLR parsers in C],
-             [2002-2012])
-
-b4_shared_declarations
-
-b4_pure_if([],
-[[extern YYSTYPE ]b4_prefix[lval;]])
-
-b4_locations_if([b4_pure_if([],
-[extern YYLTYPE ]b4_prefix[lloc;])
-])
-])])
+             [2002-2012])[
+
+]b4_cpp_guard_open([b4_spec_defines_file])[
+]b4_shared_declarations[
+]b4_pure_if([], [[extern YYSTYPE ]b4_prefix[lval;
+]b4_locations_if([[extern YYLTYPE ]b4_prefix[lloc;]])])[
+]b4_cpp_guard_close([b4_spec_defines_file])[
+]])])
 m4_divert_pop(0)
