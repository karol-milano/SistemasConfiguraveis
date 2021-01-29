@@ -313,14 +313,14 @@ m4_define([b4_declare_yyparse],
 # Declaration that might either go into the header (if --defines)
 # or open coded in the parser body.
 m4_define([b4_shared_declarations],
-[b4_cpp_guard_open([b4_spec_header_file])[
+[b4_cpp_guard_open([b4_spec_mapped_header_file])[
 ]b4_declare_yydebug[
 ]b4_percent_code_get([[requires]])[
 ]b4_token_enums_defines[
 ]b4_declare_yylstype[
 ]b4_declare_yyparse[
 ]b4_percent_code_get([[provides]])[
-]b4_cpp_guard_close([b4_spec_header_file])[]dnl
+]b4_cpp_guard_close([b4_spec_mapped_header_file])[]dnl
 ])
 
 
