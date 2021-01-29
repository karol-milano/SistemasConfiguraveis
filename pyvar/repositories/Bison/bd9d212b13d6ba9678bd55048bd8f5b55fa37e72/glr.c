@@ -142,7 +142,7 @@ m4_define([b4_rhs_location],
 # We do want M4 expansion after # for CPP macros.
 m4_changecom()
 m4_divert(0)dnl
-@output @output_parser_name@
+@output b4_parser_file_name
 b4_copyright([Skeleton implementation for Bison GLR parsers in C],
   [2002, 2003, 2004, 2005, 2006])
 [
@@ -207,7 +207,7 @@ typedef struct YYLTYPE
 ]b4_user_provides])[]dnl
 ])
 
-b4_defines_if([#include @output_header_name@],
+b4_defines_if([[#include "@basename(]b4_spec_defines_file[@)"]],
 	      [b4_shared_declarations])[
 
 /* Enabling traces.  */
@@ -2629,7 +2629,7 @@ dnl glr.cc produces its own header.
 dnl
 m4_if(b4_skeleton, ["glr.c"],
 [b4_defines_if(
-[@output @output_header_name@
+[@output b4_spec_defines_file
 b4_copyright([Skeleton interface for Bison GLR parsers in C],
   [2002, 2003, 2004, 2005, 2006])
 
