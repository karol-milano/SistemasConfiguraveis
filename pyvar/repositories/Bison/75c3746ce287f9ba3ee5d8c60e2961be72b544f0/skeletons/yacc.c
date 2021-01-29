@@ -293,7 +293,7 @@ m4_define([b4_declare_yyparse],
 
 # b4_shared_declarations
 # ----------------------
-# Declaration that might either go into the header (if --defines)
+# Declaration that might either go into the header (if --header)
 # or open coded in the parser body.
 m4_define([b4_shared_declarations],
 [b4_cpp_guard_open([b4_spec_mapped_header_file])[
@@ -330,13 +330,13 @@ m4_if(b4_spec_header_file, [y.tab.h], [],
 ## -------------- ##
 
 
-b4_defines_if([[
+b4_header_if([[
 ]b4_output_begin([b4_spec_header_file])[
 ]b4_copyright([Bison interface for Yacc-like parsers in C])[
 ]b4_disclaimer[
 ]b4_shared_declarations[
 ]b4_output_end[
-]])# b4_defines_if
+]])# b4_header_if
 
 b4_output_begin([b4_parser_file_name])[
 ]b4_copyright([Bison implementation for Yacc-like parsers in C])[
