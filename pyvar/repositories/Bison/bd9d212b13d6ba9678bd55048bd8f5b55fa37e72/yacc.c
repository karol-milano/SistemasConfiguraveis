@@ -134,7 +134,7 @@ m4_define([b4_rhs_location],
 # We do want M4 expansion after # for CPP macros.
 m4_changecom()
 m4_divert(0)dnl
-@output @output_parser_name@
+@output b4_parser_file_name
 b4_copyright([Skeleton implementation for Bison's Yacc-like parsers in C],dnl '
   [1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006])[
 
@@ -1485,7 +1485,7 @@ yyreturn:
 
 b4_epilogue
 b4_defines_if(
-[@output @output_header_name@
+[@output b4_spec_defines_file
 b4_copyright([Skeleton interface for Bison's Yacc-like parsers in C],dnl '
   [1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006])
 
