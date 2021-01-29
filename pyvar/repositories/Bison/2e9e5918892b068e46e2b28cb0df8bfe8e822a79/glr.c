@@ -2,7 +2,7 @@
 
 # GLR skeleton for Bison
 
-# Copyright (C) 2002-2015 Free Software Foundation, Inc.
+# Copyright (C) 2002-2015, 2018 Free Software Foundation, Inc.
 
 # This program is free software: you can redistribute it and/or modify
 # it under the terms of the GNU General Public License as published by
@@ -198,7 +198,7 @@ m4_if(b4_skeleton, ["glr.c"],
 [b4_defines_if(
 [b4_output_begin([b4_spec_defines_file])
 b4_copyright([Skeleton interface for Bison GLR parsers in C],
-             [2002-2015])[
+             [2002-2015, 2018])[
 
 ]b4_cpp_guard_open([b4_spec_defines_file])[
 ]b4_shared_declarations[
@@ -213,7 +213,7 @@ b4_copyright([Skeleton interface for Bison GLR parsers in C],
 
 b4_output_begin([b4_parser_file_name])
 b4_copyright([Skeleton implementation for Bison GLR parsers in C],
-             [2002-2015])[
+             [2002-2015, 2018])[
 
 /* C GLR parser skeleton written by Paul Hilfinger.  */
 
