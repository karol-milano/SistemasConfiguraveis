@@ -181,9 +181,9 @@ b4_locations_if([#define yylloc b4_prefix[]lloc])])[
 # define YYTOKEN_TABLE ]b4_token_table[
 #endif
 
-]m4_ifdef([b4_before_definitions],
-[[/* Copy the %before-definitions blocks.  */
-]b4_before_definitions])[]dnl
+]m4_ifdef([b4_start_header],
+[[/* Copy the %start-header blocks.  */
+]b4_start_header])[]dnl
 
 b4_token_enums_defines(b4_tokens)[
 
@@ -213,9 +213,9 @@ typedef struct YYLTYPE
 # define YYLTYPE_IS_TRIVIAL 1
 #endif])
 
-m4_ifdef([b4_after_definitions],
-[[/* Copy the %after-definitions blocks.  */
-]b4_after_definitions])[]dnl
+m4_ifdef([b4_end_header],
+[[/* Copy the %end-header blocks.  */
+]b4_end_header])[]dnl
 
 [/* Copy the second part of user declarations.  */
 ]b4_post_prologue
@@ -1498,9 +1498,9 @@ b4_defines_if(
 b4_copyright([Skeleton interface for Bison's Yacc-like parsers in C],dnl '
   [1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006])
 
-m4_ifdef([b4_before_definitions],
-[[/* Copy the %before-definitions blocks.  */
-]b4_before_definitions])[]dnl
+m4_ifdef([b4_start_header],
+[[/* Copy the %start-header blocks.  */
+]b4_start_header])[]dnl
 
 b4_token_enums_defines(b4_tokens)
 
@@ -1538,7 +1538,7 @@ typedef struct YYLTYPE
 	   [extern YYLTYPE b4_prefix[]lloc;])
 )dnl b4_locations_if
 
-m4_ifdef([b4_after_definitions],
-[[/* Copy the %after-definitions blocks.  */
-]b4_after_definitions])[]dnl
+m4_ifdef([b4_end_header],
+[[/* Copy the %end-header blocks.  */
+]b4_end_header])[]dnl
 ])dnl b4_defines_if
