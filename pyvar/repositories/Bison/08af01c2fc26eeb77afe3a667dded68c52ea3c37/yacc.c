@@ -1,4 +1,4 @@
-m4_divert(-1)                                                -*- C -*-
+                                                             -*- C -*-
 
 # Yacc compatible skeleton for Bison
 
@@ -137,8 +137,8 @@ m4_define([b4_rhs_location],
 
 # We do want M4 expansion after # for CPP macros.
 m4_changecom()
-m4_divert(0)dnl
-@output b4_parser_file_name
+m4_divert_push(0)dnl
+@output(b4_parser_file_name@)
 b4_copyright([Skeleton implementation for Bison's Yacc-like parsers in C],dnl '
   [1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006])[
 
@@ -1496,7 +1496,7 @@ yyreturn:
 
 b4_epilogue
 b4_defines_if(
-[@output b4_spec_defines_file
+[@output(b4_spec_defines_file@)
 b4_copyright([Skeleton interface for Bison's Yacc-like parsers in C],dnl '
   [1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006])
 
@@ -1544,3 +1544,4 @@ m4_ifdef([b4_percent_code_provides],
 [[/* Copy the %code "provides" blocks.  */
 ]b4_user_code([b4_percent_code_provides])])[]
 ])dnl b4_defines_if
+m4_divert_pop(0)
