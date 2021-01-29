@@ -199,7 +199,6 @@ m4_if(b4_skeleton, ["glr.c"],
 [b4_output_begin([b4_spec_defines_file])
 b4_copyright([Skeleton interface for Bison GLR parsers in C],
              [2002-2015, 2018])[
-
 ]b4_cpp_guard_open([b4_spec_defines_file])[
 ]b4_shared_declarations[
 ]b4_cpp_guard_close([b4_spec_defines_file])[
@@ -214,9 +213,9 @@ b4_copyright([Skeleton interface for Bison GLR parsers in C],
 b4_output_begin([b4_parser_file_name])
 b4_copyright([Skeleton implementation for Bison GLR parsers in C],
              [2002-2015, 2018])[
-
 /* C GLR parser skeleton written by Paul Hilfinger.  */
 
+]b4_disclaimer[
 ]b4_identification[
 
 ]b4_percent_code_get([[top]])[
