@@ -227,6 +227,8 @@ m4_define([b4_declare_parser_state_variables], [b4_pure_if([[
 
 # b4_declare_yyparse_push_
 # ------------------------
+# Declaration of yyparse (and dependencies) when using the push parser
+# (including in pull mode).
 m4_define([b4_declare_yyparse_push_],
 [[typedef struct ]b4_prefix[pstate ]b4_prefix[pstate;
 enum { YYPUSH_MORE = 4 };
@@ -272,12 +274,14 @@ m4_define([b4_declare_yyparse],
 # Declaration that might either go into the header (if --defines)
 # or open coded in the parser body.
 m4_define([b4_shared_declarations],
-[b4_declare_yydebug[
+[b4_cpp_guard_open([b4_spec_defines_file])[
+]b4_declare_yydebug[
 ]b4_percent_code_get([[requires]])[
 ]b4_token_enums_defines(b4_tokens)[
 ]b4_declare_yylstype[
 ]b4_declare_yyparse[
-]b4_percent_code_get([[provides]])[]dnl
+]b4_percent_code_get([[provides]])[
+]b4_cpp_guard_close([b4_spec_defines_file])[]dnl
 ])
 
 ## -------------- ##
@@ -337,8 +341,9 @@ m4_if(b4_prefix, [yy], [],
 # define YYTOKEN_TABLE ]b4_token_table[
 #endif
 
-]b4_defines_if([[#include "@basename(]b4_spec_defines_file[@)"]],
-               [b4_shared_declarations])[
+/* In a future release of Bison, this section will be replaced
+   by #include "@basename(]b4_spec_defines_file[@)".  */
+]b4_shared_declarations[
 
 /* Copy the second part of user declarations.  */
 ]b4_user_post_prologue
@@ -2065,8 +2070,6 @@ b4_defines_if(
 b4_copyright([Bison interface for Yacc-like parsers in C],
              [1984, 1989-1990, 2000-2012])[
 
-]b4_cpp_guard_open([b4_spec_defines_file])[
 ]b4_shared_declarations[
-]b4_cpp_guard_close([b4_spec_defines_file])[
 ]])dnl b4_defines_if
 m4_divert_pop(0)
