@@ -2067,8 +2067,6 @@ b4_copyright([Bison interface for Yacc-like parsers in C],
 
 ]b4_cpp_guard_open([b4_spec_defines_file])[
 ]b4_shared_declarations[
-]b4_pure_if([], [[extern YYSTYPE ]b4_prefix[lval;
-]b4_locations_if([[extern YYLTYPE ]b4_prefix[lloc;]])])[
 ]b4_cpp_guard_close([b4_spec_defines_file])[
 ]])dnl b4_defines_if
 m4_divert_pop(0)
