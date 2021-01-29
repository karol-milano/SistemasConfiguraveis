@@ -179,13 +179,10 @@ m4_define([b4_shared_declarations],
 ## Output files.  ##
 ## -------------- ##
 
-# We do want M4 expansion after # for CPP macros.
-m4_changecom()
-m4_divert_push(0)dnl
-@output(b4_parser_file_name@)@
+b4_output_begin([b4_parser_file_name])
 b4_copyright([Skeleton implementation for Bison GLR parsers in C],
-             [2002-2012])
-[
+             [2002-2012])[
+
 /* C GLR parser skeleton written by Paul Hilfinger.  */
 
 ]b4_identification
@@ -2571,17 +2568,17 @@ yypdumpstack (yyGLRStack* yystackp)
 }
 #endif
 ]b4_epilogue[]dnl
-dnl
-dnl glr.cc produces its own header.
-dnl
+b4_output_end()
+
+# glr.cc produces its own header.
 m4_if(b4_skeleton, ["glr.c"],
 [b4_defines_if(
-[@output(b4_spec_defines_file@)@
+[b4_output_begin([b4_spec_defines_file])
 b4_copyright([Skeleton interface for Bison GLR parsers in C],
              [2002-2012])[
 
 ]b4_cpp_guard_open([b4_spec_defines_file])[
 ]b4_shared_declarations[
 ]b4_cpp_guard_close([b4_spec_defines_file])[
-]])])dnl
-m4_divert_pop(0)
+]b4_output_end()
+])])
