@@ -1,10 +1,12 @@
                                                              -*- C -*-
-
 # Yacc compatible skeleton for Bison
 
 # Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006,
 # 2007, 2008 Free Software Foundation, Inc.
 
+m4_pushdef([b4_copyright_years],
+[1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006, 2007, 2008])
+
 # This program is free software: you can redistribute it and/or modify
 # it under the terms of the GNU General Public License as published by
 # the Free Software Foundation, either version 3 of the License, or
@@ -154,8 +156,8 @@ m4_define([b4_rhs_location],
 m4_changecom()
 m4_divert_push(0)dnl
 @output(b4_parser_file_name@)@
-b4_copyright([Skeleton implementation for Bison's Yacc-like parsers in C],dnl '
-  [1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006])[
+b4_copyright([Implementation for Bison's Yacc-like parsers in C])dnl'
+[
 
 /* C LALR(1) parser skeleton written by Richard Stallman, by
    simplifying the original so-called "semantic" parser.  */
@@ -1675,8 +1677,7 @@ yypushreturn:
 ]b4_epilogue
 b4_defines_if(
 [@output(b4_spec_defines_file@)@
-b4_copyright([Skeleton interface for Bison's Yacc-like parsers in C],dnl '
-  [1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006])
+b4_copyright([Interface for Bison's Yacc-like parsers in C])dnl'
 
 b4_percent_code_get([[requires]])[]dnl
 
@@ -1739,3 +1740,4 @@ b4_c_function_decl([b4_prefix[pstate_delete]], [[void]],
 b4_percent_code_get([[provides]])[]dnl
 ])dnl b4_defines_if
 m4_divert_pop(0)
+m4_popdef([b4_copyright_years])
