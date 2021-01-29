@@ -196,12 +196,12 @@ m4_if(b4_skeleton, ["glr.c"],
 # glr.cc produces its own header.
 b4_glr_cc_if([],
 [b4_defines_if(
-[b4_output_begin([b4_spec_defines_file])
+[b4_output_begin([b4_spec_header_file])
 b4_copyright([Skeleton interface for Bison GLR parsers in C],
              [2002-2015, 2018-2019])[
-]b4_cpp_guard_open([b4_spec_defines_file])[
+]b4_cpp_guard_open([b4_spec_header_file])[
 ]b4_shared_declarations[
-]b4_cpp_guard_close([b4_spec_defines_file])[
+]b4_cpp_guard_close([b4_spec_header_file])[
 ]b4_output_end
 ])])
 
@@ -238,7 +238,7 @@ b4_copyright([Skeleton implementation for Bison GLR parsers in C],
 
 ]b4_null_define[
 
-]b4_defines_if([[#include "@basename(]b4_spec_defines_file[@)"]],
+]b4_defines_if([[#include "@basename(]b4_spec_header_file[@)"]],
                [b4_shared_declarations])[
 
 /* Enabling verbose error messages.  */
