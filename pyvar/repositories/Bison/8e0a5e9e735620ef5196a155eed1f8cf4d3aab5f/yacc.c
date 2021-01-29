@@ -24,6 +24,7 @@ m4_divert(-1)                                                -*- C -*-
 b4_use_push_for_pull_if([m4_include(b4_pkgdatadir/[push.c])m4_exit])
 
 m4_include(b4_pkgdatadir/[c.m4])
+b4_check_percent_code_qualifiers([[requires]], [[provides]], [[top]])
 
 ## ---------------- ##
 ## Default values.  ##
@@ -152,6 +153,9 @@ b4_copyright([Skeleton implementation for Bison's Yacc-like parsers in C],dnl '
    USER NAME SPACE" below.  */
 
 ]b4_identification
+m4_ifdef([b4_percent_code_top],
+[[/* Copy the %code "top" blocks.  */
+]b4_user_code([b4_percent_code_top])])[]dnl
 m4_if(b4_prefix, [yy], [],
 [/* Substitute the variable and function names.  */
 #define yyparse b4_prefix[]parse
@@ -184,9 +188,9 @@ b4_locations_if([#define yylloc b4_prefix[]lloc])])[
 # define YYTOKEN_TABLE ]b4_token_table[
 #endif
 
-]m4_ifdef([b4_requires],
-[[/* Copy the %requires blocks.  */
-]b4_user_requires])[]dnl
+]m4_ifdef([b4_percent_code_requires],
+[[/* Copy the %code "requires" blocks.  */
+]b4_user_code([b4_percent_code_requires])])[]dnl
 
 b4_token_enums_defines(b4_tokens)[
 
@@ -216,14 +220,18 @@ typedef struct YYLTYPE
 # define YYLTYPE_IS_TRIVIAL 1
 #endif])
 
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
 
@@ -1492,9 +1500,9 @@ b4_defines_if(
 b4_copyright([Skeleton interface for Bison's Yacc-like parsers in C],dnl '
   [1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006])
 
-m4_ifdef([b4_requires],
-[[/* Copy the %requires blocks.  */
-]b4_user_requires])[]dnl
+m4_ifdef([b4_percent_code_requires],
+[[/* Copy the %code "requires" blocks.  */
+]b4_user_code([b4_percent_code_requires])])[]dnl
 
 b4_token_enums_defines(b4_tokens)
 
@@ -1532,7 +1540,7 @@ typedef struct YYLTYPE
 	   [extern YYLTYPE b4_prefix[]lloc;])
 )dnl b4_locations_if
 
-m4_ifdef([b4_provides],
-[[/* Copy the %provides blocks.  */
-]b4_user_provides])[]
+m4_ifdef([b4_percent_code_provides],
+[[/* Copy the %code "provides" blocks.  */
+]b4_user_code([b4_percent_code_provides])])[]
 ])dnl b4_defines_if
