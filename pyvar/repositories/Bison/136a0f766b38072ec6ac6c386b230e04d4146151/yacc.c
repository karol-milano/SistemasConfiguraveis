@@ -161,7 +161,7 @@ m4_if(b4_prefix, [yy], [],
 b4_locations_if([#define yylloc b4_prefix[]lloc])])[
 
 /* Copy the first part of user declarations.  */
-]b4_pre_prologue[
+]b4_user_pre_prologue[
 
 /* Enabling traces.  */
 #ifndef YYDEBUG
@@ -181,9 +181,9 @@ b4_locations_if([#define yylloc b4_prefix[]lloc])])[
 # define YYTOKEN_TABLE ]b4_token_table[
 #endif
 
-]m4_ifdef([b4_start_header],
-[[/* Copy the %start-header blocks.  */
-]b4_start_header])[]dnl
+]m4_ifdef([b4_requires],
+[[/* Copy the %requires blocks.  */
+]b4_user_requires])[]dnl
 
 b4_token_enums_defines(b4_tokens)[
 
@@ -213,9 +213,9 @@ typedef struct YYLTYPE
 # define YYLTYPE_IS_TRIVIAL 1
 #endif])
 
-m4_ifdef([b4_end_header],
-[[/* Copy the %end-header blocks.  */
-]b4_end_header])[]dnl
+m4_ifdef([b4_provides],
+[[/* Copy the %provides blocks.  */
+]b4_user_provides])[]dnl
 
 [/* Copy the second part of user declarations.  */
 ]b4_user_post_prologue[
@@ -1489,9 +1489,9 @@ b4_defines_if(
 b4_copyright([Skeleton interface for Bison's Yacc-like parsers in C],dnl '
   [1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006])
 
-m4_ifdef([b4_start_header],
-[[/* Copy the %start-header blocks.  */
-]b4_start_header])[]dnl
+m4_ifdef([b4_requires],
+[[/* Copy the %requires blocks.  */
+]b4_user_requires])[]dnl
 
 b4_token_enums_defines(b4_tokens)
 
@@ -1529,7 +1529,7 @@ typedef struct YYLTYPE
 	   [extern YYLTYPE b4_prefix[]lloc;])
 )dnl b4_locations_if
 
-m4_ifdef([b4_end_header],
-[[/* Copy the %end-header blocks.  */
-]b4_end_header])[]dnl
+m4_ifdef([b4_provides],
+[[/* Copy the %provides blocks.  */
+]b4_user_provides])[]dnl
 ])dnl b4_defines_if
