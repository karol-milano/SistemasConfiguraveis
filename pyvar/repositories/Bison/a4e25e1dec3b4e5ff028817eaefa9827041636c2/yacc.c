@@ -152,7 +152,7 @@ b4_copyright([Skeleton implementation for Bison's Yacc-like parsers in C],dnl '
    USER NAME SPACE" below.  */
 
 ]b4_identification
-b4_get_percent_code([[top]])[]dnl
+b4_percent_code_get([[top]])[]dnl
 m4_if(b4_prefix, [yy], [],
 [/* Substitute the variable and function names.  */
 #define yyparse b4_prefix[]parse
@@ -185,7 +185,7 @@ b4_locations_if([#define yylloc b4_prefix[]lloc])])[
 # define YYTOKEN_TABLE ]b4_token_table[
 #endif
 
-]b4_get_percent_code([[requires]])[]dnl
+]b4_percent_code_get([[requires]])[]dnl
 
 b4_token_enums_defines(b4_tokens)[
 
@@ -216,11 +216,11 @@ typedef struct YYLTYPE
 # define YYLTYPE_IS_TRIVIAL 1
 #endif])
 
-b4_get_percent_code([[provides]])[]dnl
+b4_percent_code_get([[provides]])[]dnl
 
 [/* Copy the second part of user declarations.  */
 ]b4_user_post_prologue
-b4_get_percent_code[]dnl
+b4_percent_code_get[]dnl
 
 [#ifdef short
 # undef short
@@ -1491,7 +1491,7 @@ b4_defines_if(
 b4_copyright([Skeleton interface for Bison's Yacc-like parsers in C],dnl '
   [1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006])
 
-b4_get_percent_code([[requires]])[]dnl
+b4_percent_code_get([[requires]])[]dnl
 
 b4_token_enums_defines(b4_tokens)
 
@@ -1530,7 +1530,7 @@ typedef struct YYLTYPE
 	   [extern YYLTYPE b4_prefix[]lloc;])
 )dnl b4_locations_if
 
-b4_get_percent_code([[provides]])
+b4_percent_code_get([[provides]])
 ])dnl b4_defines_if
 m4_divert_pop(0)
 
