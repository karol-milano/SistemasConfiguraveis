@@ -272,7 +272,8 @@ m4_define([b4_declare_yyparse],
 # Declaration that might either go into the header (if --defines)
 # or open coded in the parser body.
 m4_define([b4_shared_declarations],
-[b4_percent_code_get([[requires]])[
+[b4_declare_yydebug[
+]b4_percent_code_get([[requires]])[
 ]b4_token_enums_defines(b4_tokens)[
 ]b4_declare_yylstype[
 ]b4_declare_yyparse[
@@ -323,11 +324,6 @@ m4_if(b4_prefix, [yy], [],
 
 ]b4_null_define[
 
-/* Enabling traces.  */
-#ifndef YYDEBUG
-# define YYDEBUG ]b4_debug_flag[
-#endif
-
 /* Enabling verbose error messages.  */
 #ifdef YYERROR_VERBOSE
 # undef YYERROR_VERBOSE
