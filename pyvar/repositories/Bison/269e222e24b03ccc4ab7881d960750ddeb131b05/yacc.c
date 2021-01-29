@@ -156,8 +156,7 @@ m4_define([b4_rhs_location],
 m4_changecom()
 m4_divert_push(0)dnl
 @output(b4_parser_file_name@)@
-b4_copyright([Implementation for Bison's Yacc-like parsers in C])dnl'
-[
+b4_copyright([Implementation for Bison's Yacc-like parsers in C])[
 
 /* C LALR(1) parser skeleton written by Richard Stallman, by
    simplifying the original so-called "semantic" parser.  */
@@ -1599,7 +1598,7 @@ yypushreturn:
 ]b4_epilogue[]dnl
 b4_defines_if(
 [@output(b4_spec_defines_file@)@
-b4_copyright([Interface for Bison's Yacc-like parsers in C])dnl'
+b4_copyright([Interface for Bison's Yacc-like parsers in C])dnl
 
 b4_percent_code_get([[requires]])[]dnl
 
