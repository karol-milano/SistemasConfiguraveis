@@ -23,9 +23,6 @@
 m4_if(b4_skeleton, ["glr.c"],
       [m4_include(b4_skeletonsdir/[c.m4])])
 
-m4_define([b4_glr_cc_if],
-          [m4_if(b4_skeleton, ["glr.cc"], [$1], [$2])])
-
 
 ## ---------------- ##
 ## Default values.  ##
@@ -231,8 +228,7 @@ b4_copyright([Skeleton implementation for Bison GLR parsers in C],
 #define yyparse ]b4_prefix[parse
 #define yylex   ]b4_prefix[lex
 #define yyerror ]b4_prefix[error
-#define yydebug ]b4_prefix[debug
-]]b4_pure_if([], [[
+#define yydebug ]b4_prefix[debug]]b4_pure_if([], [[
 #define yylval  ]b4_prefix[lval
 #define yychar  ]b4_prefix[char
 #define yynerrs ]b4_prefix[nerrs]b4_locations_if([[
