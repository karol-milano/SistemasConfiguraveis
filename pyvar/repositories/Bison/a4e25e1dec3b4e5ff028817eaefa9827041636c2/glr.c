@@ -153,7 +153,7 @@ b4_copyright([Skeleton implementation for Bison GLR parsers in C],
 
 ]b4_identification
 
-b4_get_percent_code([[top]])[]dnl
+b4_percent_code_get([[top]])[]dnl
 m4_if(b4_prefix, [yy], [],
 [/* Substitute the variable and function names.  */
 #define yyparse b4_prefix[]parse
@@ -173,7 +173,7 @@ dnl # ----------------------
 dnl # Declaration that might either go into the header (if --defines)
 dnl # or open coded in the parser body.
 m4_define([b4_shared_declarations],
-[b4_get_percent_code([[requires]])[]dnl
+[b4_percent_code_get([[requires]])[]dnl
 
 b4_token_enums(b4_tokens)
 
@@ -205,7 +205,7 @@ typedef struct YYLTYPE
 # define YYLTYPE_IS_TRIVIAL 1
 #endif
 
-]b4_get_percent_code([[provides]])[]dnl
+]b4_percent_code_get([[provides]])[]dnl
 ])
 
 b4_defines_if([[#include "@basename(]b4_spec_defines_file[@)"]],
@@ -238,7 +238,7 @@ static YYSTYPE yyval_default;
 
 /* Copy the second part of user declarations.  */
 ]b4_user_post_prologue
-b4_get_percent_code[]dnl
+b4_percent_code_get[]dnl
 
 [#include <stdio.h>
 #include <stdlib.h>
