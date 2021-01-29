@@ -1,4 +1,4 @@
-m4_divert(-1)                                                       -*- C -*-
+                                                                    -*- C -*-
 
 # GLR skeleton for Bison
 # Copyright (C) 2002, 2003, 2004, 2005, 2006 Free Software Foundation, Inc.
@@ -23,7 +23,7 @@ m4_include(b4_pkgdatadir/[c.m4])
 b4_check_percent_code_qualifiers([[requires]], [[provides]], [[top]])
 
 b4_push_if([
-m4_fatal([Non-deterministic push parsers are not yet supported])])
+b4_complain([[non-deterministic push parsers are not yet supported]])])
 
 ## ---------------- ##
 ## Default values.  ##
@@ -145,8 +145,8 @@ m4_define([b4_rhs_location],
 
 # We do want M4 expansion after # for CPP macros.
 m4_changecom()
-m4_divert(0)dnl
-@output b4_parser_file_name
+m4_divert_push(0)dnl
+@output(b4_parser_file_name@)
 b4_copyright([Skeleton implementation for Bison GLR parsers in C],
   [2002, 2003, 2004, 2005, 2006])
 [
@@ -2640,7 +2640,7 @@ dnl glr.cc produces its own header.
 dnl
 m4_if(b4_skeleton, ["glr.c"],
 [b4_defines_if(
-[@output b4_spec_defines_file
+[@output(b4_spec_defines_file@)
 b4_copyright([Skeleton interface for Bison GLR parsers in C],
   [2002, 2003, 2004, 2005, 2006])
 
@@ -2652,3 +2652,4 @@ b4_locations_if([b4_pure_if([],
 [extern YYLTYPE b4_prefix[]lloc;])
 ])
 ])])
+m4_divert_pop(0)
