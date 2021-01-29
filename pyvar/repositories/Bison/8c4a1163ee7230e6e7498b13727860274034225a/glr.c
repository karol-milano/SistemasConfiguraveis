@@ -203,7 +203,7 @@ b4_copyright([Skeleton interface for Bison GLR parsers in C],
 ]b4_cpp_guard_open([b4_spec_defines_file])[
 ]b4_shared_declarations[
 ]b4_cpp_guard_close([b4_spec_defines_file])[
-]b4_output_end()
+]b4_output_end
 ])])
 
 
@@ -2579,4 +2579,4 @@ m4_if(b4_prefix, [yy], [],
 #define yylloc  ]b4_prefix[lloc]])])[
 
 ]b4_epilogue[]dnl
-b4_output_end()
+b4_output_end
