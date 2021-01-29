@@ -299,9 +299,8 @@ m4_define([b4_shared_declarations],
 ## Output files.  ##
 ## -------------- ##
 
-b4_output_begin([b4_parser_file_name])
-b4_copyright([Bison implementation for Yacc-like parsers in C])[
-
+b4_output_begin([b4_parser_file_name])[
+]b4_copyright([Bison implementation for Yacc-like parsers in C])[
 /* C LALR(1) parser skeleton written by Richard Stallman, by
    simplifying the original so-called "semantic" parser.  */
 
@@ -312,8 +311,9 @@ b4_copyright([Bison implementation for Yacc-like parsers in C])[
    define necessary library symbols; they are noted "INFRINGES ON
    USER NAME SPACE" below.  */
 
-]b4_identification
-b4_percent_code_get([[top]])[]dnl
+]b4_disclaimer[
+]b4_identification[
+]b4_percent_code_get([[top]])[]dnl
 m4_if(b4_api_prefix, [yy], [],
 [[/* Substitute the type names.  */
 #define YYSTYPE         ]b4_api_PREFIX[STYPE]b4_locations_if([[
@@ -1906,10 +1906,10 @@ yypushreturn:]])[
 ]b4_epilogue[]dnl
 b4_output_end
 
-b4_defines_if(
-[b4_output_begin([b4_spec_defines_file])[
+b4_defines_if([[
+]b4_output_begin([b4_spec_defines_file])[
 ]b4_copyright([Bison interface for Yacc-like parsers in C])[
-
+]b4_disclaimer[
 ]b4_shared_declarations[
-]b4_output_end
-])# b4_defines_if
+]b4_output_end[
+]])# b4_defines_if
