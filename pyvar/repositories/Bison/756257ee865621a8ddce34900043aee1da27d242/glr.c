@@ -2635,8 +2635,6 @@ b4_copyright([Skeleton interface for Bison GLR parsers in C],
 
 ]b4_cpp_guard_open([b4_spec_defines_file])[
 ]b4_shared_declarations[
-]b4_pure_if([], [[extern YYSTYPE ]b4_prefix[lval;
-]b4_locations_if([[extern YYLTYPE ]b4_prefix[lloc;]])])[
 ]b4_cpp_guard_close([b4_spec_defines_file])[
 ]])])
 m4_divert_pop(0)
