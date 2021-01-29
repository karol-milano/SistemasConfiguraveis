@@ -159,19 +159,23 @@ m4_if(b4_prefix, [yy], [],
 #define yychar  b4_prefix[]char
 #define yydebug b4_prefix[]debug
 #define yynerrs b4_prefix[]nerrs
-#define yylloc  b4_prefix[]lloc])
+#define yylloc  b4_prefix[]lloc])[
+
+/* Copy the first part of user declarations.  */
+]b4_pre_prologue
 
 dnl # b4_shared_declarations
 dnl # ----------------------
 dnl # Declaration that might either go into the header (if --defines)
 dnl # or open coded in the parser body.
 m4_define([b4_shared_declarations],
-[b4_token_enums(b4_tokens)[
+[m4_ifdef([b4_before_definitions],
+[[/* Copy the %before-definitions blocks.  */
+]b4_before_definitions])[]dnl
 
-/* Copy the first part of user declarations.  */
-]b4_pre_prologue[
+b4_token_enums(b4_tokens)
 
-#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
+[#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
 ]m4_ifdef([b4_stype],
 [typedef union b4_union_name
 b4_stype
@@ -198,7 +202,11 @@ typedef struct YYLTYPE
 # define YYLTYPE_IS_DECLARED 1
 # define YYLTYPE_IS_TRIVIAL 1
 #endif
-]])
+
+]m4_ifdef([b4_after_definitions],
+[[/* Copy the %after-definitions blocks.  */
+]b4_after_definitions])[]dnl
+])
 
 b4_defines_if([#include @output_header_name@],
 	      [b4_shared_declarations])[
