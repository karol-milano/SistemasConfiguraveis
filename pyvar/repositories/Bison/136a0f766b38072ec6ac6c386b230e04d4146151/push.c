@@ -168,7 +168,7 @@ b4_push_if([
 #define yylloc_set b4_prefix[]lloc_set])])[
 
 /* Copy the first part of user declarations.  */
-]b4_pre_prologue[
+]b4_user_pre_prologue[
 
 /* Enabling traces.  */
 #ifndef YYDEBUG
@@ -188,9 +188,9 @@ b4_push_if([
 # define YYTOKEN_TABLE ]b4_token_table[
 #endif
 
-]m4_ifdef([b4_start_header],
-[[/* Copy the %start-header blocks.  */
-]b4_start_header])[]dnl
+]m4_ifdef([b4_requires],
+[[/* Copy the %requires blocks.  */
+]b4_user_requires])[]dnl
 
 b4_token_enums_defines(b4_tokens)[
 
@@ -220,9 +220,9 @@ typedef struct YYLTYPE
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
@@ -1710,9 +1710,9 @@ b4_defines_if(
 b4_copyright([Skeleton interface for Bison's Yacc-like parsers in C],dnl '
   [1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006])
 
-m4_ifdef([b4_start_header],
-[[/* Copy the %start-header blocks.  */
-]b4_start_header])[]dnl
+m4_ifdef([b4_requires],
+[[/* Copy the %requires blocks.  */
+]b4_user_requires])[]dnl
 
 b4_token_enums_defines(b4_tokens)
 
@@ -1752,7 +1752,7 @@ enum { YYPUSH_MORE = 4 };])[
 	   [extern YYLTYPE b4_prefix[]lloc;])
 )dnl b4_locations_if
 
-m4_ifdef([b4_end_header],
-[[/* Copy the %end-header blocks.  */
-]b4_end_header])[]dnl
+m4_ifdef([b4_provides],
+[[/* Copy the %provides blocks.  */
+]b4_user_provides])[]dnl
 ])dnl b4_defines_if
