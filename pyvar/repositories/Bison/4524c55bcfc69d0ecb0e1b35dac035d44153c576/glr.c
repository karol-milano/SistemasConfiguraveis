@@ -158,7 +158,7 @@ m4_changecom()
 m4_divert_push(0)dnl
 @output(b4_parser_file_name@)@
 b4_copyright([Skeleton implementation for Bison GLR parsers in C],
-  [2002, 2003, 2004, 2005, 2006])
+             [2002, 2003, 2004, 2005, 2006])
 [
 /* C GLR parser skeleton written by Paul Hilfinger.  */
 
@@ -2575,9 +2575,7 @@ yypdumpstack (yyGLRStack* yystackp)
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
@@ -2585,7 +2583,7 @@ m4_if(b4_skeleton, ["glr.c"],
 [b4_defines_if(
 [@output(b4_spec_defines_file@)@
 b4_copyright([Skeleton interface for Bison GLR parsers in C],
-  [2002, 2003, 2004, 2005, 2006])
+             [2002, 2003, 2004, 2005, 2006])
 
 b4_shared_declarations
 
@@ -2595,5 +2593,5 @@ b4_pure_if([],
 b4_locations_if([b4_pure_if([],
 [extern YYLTYPE ]b4_prefix[lloc;])
 ])
-])])
+])])[]dnl
 m4_divert_pop(0)
