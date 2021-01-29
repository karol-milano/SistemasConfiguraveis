@@ -160,8 +160,6 @@ m4_if(b4_prefix, [yy], [],
 #define yynerrs b4_prefix[]nerrs
 b4_locations_if([#define yylloc b4_prefix[]lloc])])[
 
-]b4_token_enums_defines(b4_tokens)[
-
 /* Copy the first part of user declarations.  */
 ]b4_pre_prologue[
 
@@ -183,9 +181,15 @@ b4_locations_if([#define yylloc b4_prefix[]lloc])])[
 # define YYTOKEN_TABLE ]b4_token_table[
 #endif
 
+]m4_ifdef([b4_before_definitions],
+[[/* Copy the %before-definitions blocks.  */
+]b4_before_definitions])[]dnl
+
+b4_token_enums_defines(b4_tokens)[
+
 #if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
 ]m4_ifdef([b4_stype],
-[typedef union b4_union_name
+[[typedef union ]b4_union_name
 b4_stype
 /* Line __line__ of yacc.c.  */
 b4_syncline([@oline@], [@ofile@])
@@ -207,14 +211,17 @@ typedef struct YYLTYPE
 # define yyltype YYLTYPE /* obsolescent; will be withdrawn */
 # define YYLTYPE_IS_DECLARED 1
 # define YYLTYPE_IS_TRIVIAL 1
-#endif
-])[
+#endif])
 
-/* Copy the second part of user declarations.  */
+m4_ifdef([b4_after_definitions],
+[[/* Copy the %after-definitions blocks.  */
+]b4_after_definitions])[]dnl
+
+[/* Copy the second part of user declarations.  */
 ]b4_post_prologue
 
-/* Line __line__ of yacc.c.  */
-b4_syncline([@oline@], [@ofile@])[
+[/* Line __line__ of yacc.c.  */
+]b4_syncline([@oline@], [@ofile@])[
 
 #ifdef short
 # undef short
@@ -1491,22 +1498,26 @@ b4_defines_if(
 b4_copyright([Skeleton interface for Bison's Yacc-like parsers in C],dnl '
   [1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006])
 
+m4_ifdef([b4_before_definitions],
+[[/* Copy the %before-definitions blocks.  */
+]b4_before_definitions])[]dnl
+
 b4_token_enums_defines(b4_tokens)
 
-#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
-m4_ifdef([b4_stype],
-[typedef union b4_union_name
+[#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
+]m4_ifdef([b4_stype],
+[[typedef union ]b4_union_name
 b4_stype
 /* Line __line__ of yacc.c.  */
 b4_syncline([@oline@], [@ofile@])
 	YYSTYPE;],
-[typedef int YYSTYPE;])
+[typedef int YYSTYPE;])[
 # define yystype YYSTYPE /* obsolescent; will be withdrawn */
 # define YYSTYPE_IS_DECLARED 1
 # define YYSTYPE_IS_TRIVIAL 1
 #endif
 
-b4_pure_if([],
+]b4_pure_if([],
 [extern YYSTYPE b4_prefix[]lval;])
 
 b4_locations_if(
@@ -1523,7 +1534,11 @@ typedef struct YYLTYPE
 # define YYLTYPE_IS_TRIVIAL 1
 #endif
 
-b4_pure_if([],
+]b4_pure_if([],
 	   [extern YYLTYPE b4_prefix[]lloc;])
-])dnl b4_locations_if
+)dnl b4_locations_if
+
+m4_ifdef([b4_after_definitions],
+[[/* Copy the %after-definitions blocks.  */
+]b4_after_definitions])[]dnl
 ])dnl b4_defines_if
