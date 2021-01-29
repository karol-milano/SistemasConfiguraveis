@@ -20,6 +20,7 @@ m4_divert(-1)                                                       -*- C -*-
 
 
 m4_include(b4_pkgdatadir/[c.m4])
+b4_check_percent_code_qualifiers([[requires]], [[provides]], [[top]])
 
 b4_push_if([
 m4_fatal([Non-deterministic push parsers are not yet supported])])
@@ -153,6 +154,9 @@ b4_copyright([Skeleton implementation for Bison GLR parsers in C],
 
 ]b4_identification
 
+m4_ifdef([b4_percent_code_top],
+[[/* Copy the %code "top" blocks.  */
+]b4_user_code([b4_percent_code_top])])[]dnl
 m4_if(b4_prefix, [yy], [],
 [/* Substitute the variable and function names.  */
 #define yyparse b4_prefix[]parse
@@ -172,9 +176,9 @@ dnl # ----------------------
 dnl # Declaration that might either go into the header (if --defines)
 dnl # or open coded in the parser body.
 m4_define([b4_shared_declarations],
-[m4_ifdef([b4_requires],
-[[/* Copy the %requires blocks.  */
-]b4_user_requires])[]dnl
+[m4_ifdef([b4_percent_code_requires],
+[[/* Copy the %code "requires" blocks.  */
+]b4_user_code([b4_percent_code_requires])])[]dnl
 
 b4_token_enums(b4_tokens)
 
@@ -205,9 +209,9 @@ typedef struct YYLTYPE
 # define YYLTYPE_IS_TRIVIAL 1
 #endif
 
-]m4_ifdef([b4_provides],
-[[/* Copy the %provides blocks.  */
-]b4_user_provides])[]dnl
+]m4_ifdef([b4_percent_code_provides],
+[[/* Copy the %code "provides" blocks.  */
+]b4_user_code([b4_percent_code_provides])])[]dnl
 ])
 
 b4_defines_if([[#include "@basename(]b4_spec_defines_file[@)"]],
@@ -239,9 +243,13 @@ b4_defines_if([[#include "@basename(]b4_spec_defines_file[@)"]],
 static YYSTYPE yyval_default;
 
 /* Copy the second part of user declarations.  */
-]b4_user_post_prologue[
+]b4_user_post_prologue
+m4_ifdef([b4_percent_code],
+[[/* Copy the unqualified %code blocks.  */
+]b4_user_code([b4_percent_code])
+])[]dnl
 
-#include <stdio.h>
+[#include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 
