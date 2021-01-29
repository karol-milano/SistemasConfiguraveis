@@ -1,7 +1,7 @@
 m4_divert(-1)                                                       -*- C -*-
 
 # GLR skeleton for Bison
-# Copyright (C) 2002 Free Software Foundation, Inc.
+# Copyright (C) 2002, 2003 Free Software Foundation, Inc.
 
 # This program is free software; you can redistribute it and/or modify
 # it under the terms of the GNU General Public License as published by
@@ -138,7 +138,7 @@ m4_define([b4_rhs_location],
 m4_changecom()
 m4_divert(0)dnl
 @output @output_parser_name@
-b4_copyright([Skeleton parser for GLR parsing with Bison], [2002])
+b4_copyright([Skeleton parser for GLR parsing with Bison], [2002, 2003])
 [
 /* This is the parser code for GLR (Generalized LR) parser. */
 
@@ -1950,7 +1950,7 @@ yypdumpstack (yyGLRStack* yystack)
 b4_epilogue
 m4_if(b4_defines_flag, 0, [],
 [@output @output_header_name@
-b4_copyright([Skeleton parser for GLR parsing with Bison], [2002])
+b4_copyright([Skeleton parser for GLR parsing with Bison], [2002, 2003])
 
 b4_token_defines(b4_tokens)
 
