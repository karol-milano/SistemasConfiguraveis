@@ -33,6 +33,7 @@ b4_use_push_for_pull_if([
   ])])
 
 m4_include(b4_pkgdatadir/[c.m4])
+b4_check_percent_code_qualifiers([[requires]], [[provides]], [[top]])
 
 ## ---------------- ##
 ## Default values.  ##
@@ -160,6 +161,9 @@ b4_copyright([Skeleton implementation for Bison's Yacc-like parsers in C],dnl '
    USER NAME SPACE" below.  */
 
 ]b4_identification
+m4_ifdef([b4_percent_code_top],
+[[/* Copy the %code "top" blocks.  */
+]b4_user_code([b4_percent_code_top])])[]dnl
 m4_if(b4_prefix, [yy], [],
 [[/* Substitute the variable and function names.  */
 ]b4_pull_if([[#define yyparse         ]b4_prefix[parse
@@ -197,9 +201,9 @@ m4_if(b4_prefix, [yy], [],
 # define YYTOKEN_TABLE ]b4_token_table[
 #endif
 
-]m4_ifdef([b4_requires],
-[[/* Copy the %requires blocks.  */
-]b4_user_requires])[]dnl
+]m4_ifdef([b4_percent_code_requires],
+[[/* Copy the %code "requires" blocks.  */
+]b4_user_code([b4_percent_code_requires])])[]dnl
 
 b4_token_enums_defines(b4_tokens)[
 
@@ -250,14 +254,18 @@ b4_c_function_decl([[yypstate_delete]], [[void]],
                    [[[yypstate *yyps]], [[yyps]]])[
 #endif
 ]])
-m4_ifdef([b4_provides],
-[[/* Copy the %provides blocks.  */
-]b4_user_provides])[]dnl
+m4_ifdef([b4_percent_code_provides],
+[[/* Copy the %code "provides" blocks.  */
+]b4_user_code([b4_percent_code_provides])])[]dnl
 
 [/* Copy the second part of user declarations.  */
-]b4_user_post_prologue[
+]b4_user_post_prologue
+m4_ifdef([b4_percent_code],
+[[/* Copy the unqualified %code blocks.  */
+]b4_user_code([b4_percent_code])
+])[]dnl
 
-#ifdef short
+[#ifdef short
 # undef short
 #endif
 
@@ -1655,9 +1663,9 @@ b4_defines_if(
 b4_copyright([Skeleton interface for Bison's Yacc-like parsers in C],dnl '
   [1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006])
 
-m4_ifdef([b4_requires],
-[[/* Copy the %requires blocks.  */
-]b4_user_requires])[]dnl
+m4_ifdef([b4_percent_code_requires],
+[[/* Copy the %code "requires" blocks.  */
+]b4_user_code([b4_percent_code_requires])])[]dnl
 
 b4_token_enums_defines(b4_tokens)
 
@@ -1714,7 +1722,7 @@ b4_c_function_decl([b4_prefix[pstate_delete]], [[void]],
                    [[b4_prefix[pstate *yyps]], [[yyps]]])[
 #endif
 ]])
-m4_ifdef([b4_provides],
-[[/* Copy the %provides blocks.  */
-]b4_user_provides])[]
+m4_ifdef([b4_percent_code_provides],
+[[/* Copy the %code "provides" blocks.  */
+]b4_user_code([b4_percent_code_provides])])[]
 ])dnl b4_defines_if
