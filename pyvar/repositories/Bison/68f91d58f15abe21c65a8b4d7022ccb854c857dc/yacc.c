@@ -2,7 +2,7 @@
 
 # Yacc compatible skeleton for Bison
 
-# Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation,
+# Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation,
 # Inc.
 
 # This program is free software: you can redistribute it and/or modify
@@ -333,7 +333,7 @@ m4_define([b4_shared_declarations],
 
 b4_output_begin([b4_parser_file_name])
 b4_copyright([Bison implementation for Yacc-like parsers in C],
-             [1984, 1989-1990, 2000-2012])[
+             [1984, 1989-1990, 2000-2013])[
 
 /* C LALR(1) parser skeleton written by Richard Stallman, by
    simplifying the original so-called "semantic" parser.  */
@@ -2053,7 +2053,7 @@ b4_output_end()
 b4_defines_if(
 [b4_output_begin([b4_spec_defines_file])[
 ]b4_copyright([Bison interface for Yacc-like parsers in C],
-              [1984, 1989-1990, 2000-2012])[
+              [1984, 1989-1990, 2000-2013])[
 
 ]b4_shared_declarations[
 ]b4_output_end()
