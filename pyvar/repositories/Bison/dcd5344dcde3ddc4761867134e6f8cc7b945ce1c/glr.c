@@ -2599,9 +2599,7 @@ yypdumpstack (yyGLRStack* yystackp)
   YYFPRINTF (stderr, "\n");
 }
 #endif
-]
-
-b4_epilogue
+]b4_epilogue[]dnl
 dnl
 dnl glr.cc produces its own header.
 dnl
@@ -2614,5 +2612,5 @@ b4_copyright([Skeleton interface for Bison GLR parsers in C],
 ]b4_cpp_guard_open([b4_spec_defines_file])[
 ]b4_shared_declarations[
 ]b4_cpp_guard_close([b4_spec_defines_file])[
-]])])
+]])])dnl
 m4_divert_pop(0)
