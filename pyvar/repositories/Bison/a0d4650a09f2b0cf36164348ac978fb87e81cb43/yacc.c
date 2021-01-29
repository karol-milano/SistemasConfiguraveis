@@ -153,7 +153,7 @@ m4_define([b4_rhs_location],
 # We do want M4 expansion after # for CPP macros.
 m4_changecom()
 m4_divert_push(0)dnl
-@output(b4_parser_file_name@)
+@output(b4_parser_file_name@)@
 b4_copyright([Skeleton implementation for Bison's Yacc-like parsers in C],dnl '
   [1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006])[
 
@@ -1674,7 +1674,7 @@ yypushreturn:
 
 ]b4_epilogue
 b4_defines_if(
-[@output(b4_spec_defines_file@)
+[@output(b4_spec_defines_file@)@
 b4_copyright([Skeleton interface for Bison's Yacc-like parsers in C],dnl '
   [1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006])
 
