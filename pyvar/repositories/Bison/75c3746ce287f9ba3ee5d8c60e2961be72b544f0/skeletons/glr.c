@@ -151,7 +151,7 @@ m4_define([b4_rhs_location],
 
 # b4_shared_declarations
 # ----------------------
-# Declaration that might either go into the header (if --defines)
+# Declaration that might either go into the header (if --header)
 # or open coded in the parser body.  glr.cc has its own definition.
 m4_if(b4_skeleton, ["glr.c"],
 [m4_define([b4_shared_declarations],
@@ -185,7 +185,7 @@ int ]b4_prefix[parse (]m4_ifset([b4_parse_param], [b4_formals(b4_parse_param)],
 
 # glr.cc produces its own header.
 b4_glr_cc_if([],
-[b4_defines_if(
+[b4_header_if(
 [b4_output_begin([b4_spec_header_file])
 b4_copyright([Skeleton interface for Bison GLR parsers in C],
              [2002-2015, 2018-2020])[
@@ -228,7 +228,7 @@ b4_copyright([Skeleton implementation for Bison GLR parsers in C],
 ]b4_cast_define[
 ]b4_null_define[
 
-]b4_defines_if([[#include "@basename(]b4_spec_header_file[@)"]],
+]b4_header_if([[#include "@basename(]b4_spec_header_file[@)"]],
                [b4_shared_declarations])[
 
 ]b4_glr_cc_if([b4_glr_cc_setup],
