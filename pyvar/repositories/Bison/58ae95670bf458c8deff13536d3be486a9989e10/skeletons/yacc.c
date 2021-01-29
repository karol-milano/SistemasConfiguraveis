@@ -284,14 +284,14 @@ m4_define([b4_declare_yyparse],
 # Declaration that might either go into the header (if --defines)
 # or open coded in the parser body.
 m4_define([b4_shared_declarations],
-[b4_cpp_guard_open([b4_spec_defines_file])[
+[b4_cpp_guard_open([b4_spec_header_file])[
 ]b4_declare_yydebug[
 ]b4_percent_code_get([[requires]])[
 ]b4_token_enums_defines[
 ]b4_declare_yylstype[
 ]b4_declare_yyparse[
 ]b4_percent_code_get([[provides]])[
-]b4_cpp_guard_close([b4_spec_defines_file])[]dnl
+]b4_cpp_guard_close([b4_spec_header_file])[]dnl
 ])
 
 
@@ -300,15 +300,15 @@ m4_define([b4_shared_declarations],
 # Run IF-TRUE if we generate an output file and api.header.include
 # is defined.
 m4_define([b4_header_include_if],
-[m4_ifval(m4_quote(b4_spec_defines_file),
+[m4_ifval(m4_quote(b4_spec_header_file),
           [b4_percent_define_ifdef([[api.header.include]],
                                    [$1],
                                    [$2])],
           [$2])])
 
-m4_if(b4_spec_defines_file, [[y.tab.h]],
+m4_if(b4_spec_header_file, [[y.tab.h]],
       [b4_percent_define_default([[api.header.include]],
-                                 [["@basename(]b4_spec_defines_file[@)"]])])
+                                 [["@basename(]b4_spec_header_file[@)"]])])
 
 
 
@@ -319,7 +319,7 @@ m4_if(b4_spec_defines_file, [[y.tab.h]],
 
 
 b4_defines_if([[
-]b4_output_begin([b4_spec_defines_file])[
+]b4_output_begin([b4_spec_header_file])[
 ]b4_copyright([Bison interface for Yacc-like parsers in C])[
 ]b4_disclaimer[
 ]b4_shared_declarations[
