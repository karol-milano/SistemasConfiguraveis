@@ -326,14 +326,12 @@ m4_define([b4_shared_declarations],
 ]b4_cpp_guard_close([b4_spec_defines_file])[]dnl
 ])
 
+
 ## -------------- ##
 ## Output files.  ##
 ## -------------- ##
 
-# We do want M4 expansion after # for CPP macros.
-m4_changecom()
-m4_divert_push(0)dnl
-@output(b4_parser_file_name@)@
+b4_output_begin([b4_parser_file_name])
 b4_copyright([Bison implementation for Yacc-like parsers in C],
              [1984, 1989-1990, 2000-2012])[
 
@@ -2052,11 +2050,13 @@ yypushreturn:]])[
 
 
 ]b4_epilogue[]dnl
+b4_output_end()
+
 b4_defines_if(
-[@output(b4_spec_defines_file@)@
-b4_copyright([Bison interface for Yacc-like parsers in C],
-             [1984, 1989-1990, 2000-2012])[
+[b4_output_begin([b4_spec_defines_file])[
+]b4_copyright([Bison interface for Yacc-like parsers in C],
+              [1984, 1989-1990, 2000-2012])[
 
 ]b4_shared_declarations[
-]])dnl b4_defines_if
-m4_divert_pop(0)
+]b4_output_end()
+])
