@@ -2624,7 +2624,11 @@ yypdumpstack (yyGLRStack* yystackp)
 ]
 
 b4_epilogue
-b4_defines_if(
+dnl
+dnl glr.cc produces its own header.
+dnl
+m4_if(b4_skeleton, ["glr.c"],
+[b4_defines_if(
 [@output @output_header_name@
 b4_copyright([Skeleton interface for Bison GLR parsers in C],
   [2002, 2003, 2004, 2005, 2006])
@@ -2636,4 +2640,4 @@ extern YYSTYPE b4_prefix[]lval;
 b4_locations_if([b4_pure_if([],
 [extern YYLTYPE b4_prefix[]lloc;])
 ])
-])
+])])
