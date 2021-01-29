@@ -298,6 +298,15 @@ m4_define([b4_shared_declarations],
 ## Output files.  ##
 ## -------------- ##
 
+
+b4_defines_if([[
+]b4_output_begin([b4_spec_defines_file])[
+]b4_copyright([Bison interface for Yacc-like parsers in C])[
+]b4_disclaimer[
+]b4_shared_declarations[
+]b4_output_end[
+]])# b4_defines_if
+
 b4_output_begin([b4_parser_file_name])[
 ]b4_copyright([Bison implementation for Yacc-like parsers in C])[
 /* C LALR(1) parser skeleton written by Richard Stallman, by
@@ -1926,11 +1935,3 @@ yypushreturn:]])[
 }
 ]b4_epilogue[]dnl
 b4_output_end
-
-b4_defines_if([[
-]b4_output_begin([b4_spec_defines_file])[
-]b4_copyright([Bison interface for Yacc-like parsers in C])[
-]b4_disclaimer[
-]b4_shared_declarations[
-]b4_output_end[
-]])# b4_defines_if
