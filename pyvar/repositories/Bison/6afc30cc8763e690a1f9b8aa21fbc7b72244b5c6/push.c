@@ -34,12 +34,6 @@ b4_use_push_for_pull_if([
 
 m4_include(b4_pkgdatadir/[c.m4])
 
-b4_check_percent_define_variables
-
-b4_check_percent_code_qualifiers([[requires]],
-                                 [[provides]],
-                                 [[top]])
-
 ## ---------------- ##
 ## Default values.  ##
 ## ---------------- ##
@@ -166,9 +160,7 @@ b4_copyright([Skeleton implementation for Bison's Yacc-like parsers in C],dnl '
    USER NAME SPACE" below.  */
 
 ]b4_identification
-m4_ifdef([b4_percent_code_top],
-[[/* Copy the %code "top" blocks.  */
-]b4_user_code([b4_percent_code_top])])[]dnl
+b4_get_percent_code([[top]])[]dnl
 m4_if(b4_prefix, [yy], [],
 [[/* Substitute the variable and function names.  */
 ]b4_pull_if([[#define yyparse         ]b4_prefix[parse
@@ -206,9 +198,7 @@ m4_if(b4_prefix, [yy], [],
 # define YYTOKEN_TABLE ]b4_token_table[
 #endif
 
-]m4_ifdef([b4_percent_code_requires],
-[[/* Copy the %code "requires" blocks.  */
-]b4_user_code([b4_percent_code_requires])])[]dnl
+]b4_get_percent_code([[requires]])[]dnl
 
 b4_token_enums_defines(b4_tokens)[
 
@@ -259,16 +249,11 @@ b4_c_function_decl([[yypstate_delete]], [[void]],
                    [[[yypstate *yyps]], [[yyps]]])[
 #endif
 ]])
-m4_ifdef([b4_percent_code_provides],
-[[/* Copy the %code "provides" blocks.  */
-]b4_user_code([b4_percent_code_provides])])[]dnl
+b4_get_percent_code([[provides]])[]dnl
 
 [/* Copy the second part of user declarations.  */
 ]b4_user_post_prologue
-m4_ifdef([b4_percent_code],
-[[/* Copy the unqualified %code blocks.  */
-]b4_user_code([b4_percent_code])
-])[]dnl
+b4_get_percent_code[]dnl
 
 [#ifdef short
 # undef short
@@ -1668,9 +1653,7 @@ b4_defines_if(
 b4_copyright([Skeleton interface for Bison's Yacc-like parsers in C],dnl '
   [1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006])
 
-m4_ifdef([b4_percent_code_requires],
-[[/* Copy the %code "requires" blocks.  */
-]b4_user_code([b4_percent_code_requires])])[]dnl
+b4_get_percent_code([[requires]])[]dnl
 
 b4_token_enums_defines(b4_tokens)
 
@@ -1727,8 +1710,6 @@ b4_c_function_decl([b4_prefix[pstate_delete]], [[void]],
                    [[b4_prefix[pstate *yyps]], [[yyps]]])[
 #endif
 ]])
-m4_ifdef([b4_percent_code_provides],
-[[/* Copy the %code "provides" blocks.  */
-]b4_user_code([b4_percent_code_provides])])[]
+b4_get_percent_code([[provides]])[]dnl
 ])dnl b4_defines_if
 m4_divert_pop(0)
