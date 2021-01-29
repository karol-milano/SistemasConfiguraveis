@@ -160,7 +160,7 @@ b4_copyright([Skeleton implementation for Bison's Yacc-like parsers in C],dnl '
    USER NAME SPACE" below.  */
 
 ]b4_identification
-b4_get_percent_code([[top]])[]dnl
+b4_percent_code_get([[top]])[]dnl
 m4_if(b4_prefix, [yy], [],
 [[/* Substitute the variable and function names.  */
 ]b4_pull_if([[#define yyparse         ]b4_prefix[parse
@@ -198,7 +198,7 @@ m4_if(b4_prefix, [yy], [],
 # define YYTOKEN_TABLE ]b4_token_table[
 #endif
 
-]b4_get_percent_code([[requires]])[]dnl
+]b4_percent_code_get([[requires]])[]dnl
 
 b4_token_enums_defines(b4_tokens)[
 
@@ -250,11 +250,11 @@ b4_c_function_decl([[yypstate_delete]], [[void]],
                    [[[yypstate *yyps]], [[yyps]]])[
 #endif
 ]])
-b4_get_percent_code([[provides]])[]dnl
+b4_percent_code_get([[provides]])[]dnl
 
 [/* Copy the second part of user declarations.  */
 ]b4_user_post_prologue
-b4_get_percent_code[]dnl
+b4_percent_code_get[]dnl
 
 [#ifdef short
 # undef short
@@ -1656,7 +1656,7 @@ b4_defines_if(
 b4_copyright([Skeleton interface for Bison's Yacc-like parsers in C],dnl '
   [1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006])
 
-b4_get_percent_code([[requires]])[]dnl
+b4_percent_code_get([[requires]])[]dnl
 
 b4_token_enums_defines(b4_tokens)
 
@@ -1714,6 +1714,6 @@ b4_c_function_decl([b4_prefix[pstate_delete]], [[void]],
                    [[b4_prefix[pstate *yyps]], [[yyps]]])[
 #endif
 ]])
-b4_get_percent_code([[provides]])[]dnl
+b4_percent_code_get([[provides]])[]dnl
 ])dnl b4_defines_if
 m4_divert_pop(0)
