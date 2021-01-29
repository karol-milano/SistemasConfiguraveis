@@ -176,7 +176,7 @@ m4_define([b4_rhs_location],
 m4_define([b4_shared_declarations],
 [b4_declare_yydebug[
 ]b4_percent_code_get([[requires]])[
-]b4_token_enums(b4_tokens)[
+]b4_token_enums[
 ]b4_declare_yylstype[
 ]b4_c_ansi_function_decl(b4_prefix[parse], [int], b4_parse_param)[
 ]b4_percent_code_get([[provides]])[]dnl
