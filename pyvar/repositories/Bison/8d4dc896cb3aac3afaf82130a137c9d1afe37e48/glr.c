@@ -178,6 +178,39 @@ m4_if(b4_skeleton, ["glr.c"],
 ## Output files.  ##
 ## -------------- ##
 
+# Unfortunately the order of generation between the header and the
+# implementation file matters (for glr.c) because of the current
+# implementation of api.value.type=union.  In that case we still use a
+# union for YYSTYPE, but we generate the contents of this union when
+# setting up YYSTYPE.  This is needed for other aspects, such as
+# defining yy_symbol_value_print, since we need to now the name of the
+# members of this union.
+#
+# To avoid this issue, just generate the header before the
+# implementation file.  But we should also make them more independant.
+
+# ----------------- #
+# The header file.  #
+# ----------------- #
+
+# glr.cc produces its own header.
+m4_if(b4_skeleton, ["glr.c"],
+[b4_defines_if(
+[b4_output_begin([b4_spec_defines_file])
+b4_copyright([Skeleton interface for Bison GLR parsers in C],
+             [2002-2014])[
+
+]b4_cpp_guard_open([b4_spec_defines_file])[
+]b4_shared_declarations[
+]b4_cpp_guard_close([b4_spec_defines_file])[
+]b4_output_end()
+])])
+
+
+# ------------------------- #
+# The implementation file.  #
+# ------------------------- #
+
 b4_output_begin([b4_parser_file_name])
 b4_copyright([Skeleton implementation for Bison GLR parsers in C],
              [2002-2014])[
@@ -2550,16 +2583,3 @@ m4_if(b4_prefix, [yy], [],
 
 ]b4_epilogue[]dnl
 b4_output_end()
-
-# glr.cc produces its own header.
-m4_if(b4_skeleton, ["glr.c"],
-[b4_defines_if(
-[b4_output_begin([b4_spec_defines_file])
-b4_copyright([Skeleton interface for Bison GLR parsers in C],
-             [2002-2014])[
-
-]b4_cpp_guard_open([b4_spec_defines_file])[
-]b4_shared_declarations[
-]b4_cpp_guard_close([b4_spec_defines_file])[
-]b4_output_end()
-])])
