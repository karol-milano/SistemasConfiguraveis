@@ -148,7 +148,7 @@ m4_define([b4_rhs_location],
 # We do want M4 expansion after # for CPP macros.
 m4_changecom()
 m4_divert_push(0)dnl
-@output(b4_parser_file_name@)
+@output(b4_parser_file_name@)@
 b4_copyright([Skeleton implementation for Bison GLR parsers in C],
   [2002, 2003, 2004, 2005, 2006])
 [
@@ -2637,7 +2637,7 @@ dnl glr.cc produces its own header.
 dnl
 m4_if(b4_skeleton, ["glr.c"],
 [b4_defines_if(
-[@output(b4_spec_defines_file@)
+[@output(b4_spec_defines_file@)@
 b4_copyright([Skeleton interface for Bison GLR parsers in C],
   [2002, 2003, 2004, 2005, 2006])
 
