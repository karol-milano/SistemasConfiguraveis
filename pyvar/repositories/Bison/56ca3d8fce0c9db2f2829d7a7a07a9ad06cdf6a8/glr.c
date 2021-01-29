@@ -163,7 +163,8 @@ m4_define([b4_rhs_location],
 # Declaration that might either go into the header (if --defines)
 # or open coded in the parser body.
 m4_define([b4_shared_declarations],
-[b4_percent_code_get([[requires]])[
+[b4_declare_yydebug[
+]b4_percent_code_get([[requires]])[
 ]b4_token_enums(b4_tokens)[
 ]b4_declare_yylstype[
 ]b4_c_ansi_function_decl(b4_prefix[parse], [int], b4_parse_param)[
@@ -206,11 +207,6 @@ m4_if(b4_prefix, [yy], [],
 ]b4_defines_if([[#include "@basename(]b4_spec_defines_file[@)"]],
                [b4_shared_declarations])[
 
-/* Enabling traces.  */
-#ifndef YYDEBUG
-# define YYDEBUG ]b4_debug_flag[
-#endif
-
 /* Enabling verbose error messages.  */
 #ifdef YYERROR_VERBOSE
 # undef YYERROR_VERBOSE
