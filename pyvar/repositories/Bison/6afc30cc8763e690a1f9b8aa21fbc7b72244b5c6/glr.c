@@ -21,13 +21,6 @@
 
 m4_include(b4_pkgdatadir/[c.m4])
 
-# glr.cc checks %define variables also.
-m4_if(b4_skeleton, [["glr.c"]], [b4_check_percent_define_variables])
-
-b4_check_percent_code_qualifiers([[requires]],
-                                 [[provides]],
-                                 [[top]])
-
 b4_push_if([
 b4_complain([[non-deterministic push parsers are not yet supported]])])
 
@@ -160,9 +153,7 @@ b4_copyright([Skeleton implementation for Bison GLR parsers in C],
 
 ]b4_identification
 
-m4_ifdef([b4_percent_code_top],
-[[/* Copy the %code "top" blocks.  */
-]b4_user_code([b4_percent_code_top])])[]dnl
+b4_get_percent_code([[top]])[]dnl
 m4_if(b4_prefix, [yy], [],
 [/* Substitute the variable and function names.  */
 #define yyparse b4_prefix[]parse
@@ -182,9 +173,7 @@ dnl # ----------------------
 dnl # Declaration that might either go into the header (if --defines)
 dnl # or open coded in the parser body.
 m4_define([b4_shared_declarations],
-[m4_ifdef([b4_percent_code_requires],
-[[/* Copy the %code "requires" blocks.  */
-]b4_user_code([b4_percent_code_requires])])[]dnl
+[b4_get_percent_code([[requires]])[]dnl
 
 b4_token_enums(b4_tokens)
 
@@ -215,9 +204,7 @@ typedef struct YYLTYPE
 # define YYLTYPE_IS_TRIVIAL 1
 #endif
 
-]m4_ifdef([b4_percent_code_provides],
-[[/* Copy the %code "provides" blocks.  */
-]b4_user_code([b4_percent_code_provides])])[]dnl
+]b4_get_percent_code([[provides]])[]dnl
 ])
 
 b4_defines_if([[#include "@basename(]b4_spec_defines_file[@)"]],
@@ -250,10 +237,7 @@ static YYSTYPE yyval_default;
 
 /* Copy the second part of user declarations.  */
 ]b4_user_post_prologue
-m4_ifdef([b4_percent_code],
-[[/* Copy the unqualified %code blocks.  */
-]b4_user_code([b4_percent_code])
-])[]dnl
+b4_get_percent_code[]dnl
 
 [#include <stdio.h>
 #include <stdlib.h>
