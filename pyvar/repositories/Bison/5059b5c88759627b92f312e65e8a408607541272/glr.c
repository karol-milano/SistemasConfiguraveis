@@ -138,6 +138,12 @@ m4_define([b4_lhs_location],
 m4_define([b4_rhs_location],
 [(((yyGLRStackItem const *)yyvsp)@{YYFILL ($2 - $1)@}.yystate.yyloc)])
 
+
+
+## -------------- ##
+## Output files.  ##
+## -------------- ##
+
 # We do want M4 expansion after # for CPP macros.
 m4_changecom()
 m4_divert(0)dnl
@@ -148,6 +154,7 @@ b4_copyright([Skeleton parser for GLR parsing with Bison],
 /* This is the parser code for GLR (Generalized LR) parser. */
 
 ]b4_identification
+
 m4_if(b4_prefix[], [yy], [],
 [/* Substitute the variable and function names.  */
 #define yyparse b4_prefix[]parse
@@ -157,30 +164,17 @@ m4_if(b4_prefix[], [yy], [],
 #define yychar  b4_prefix[]char
 #define yydebug b4_prefix[]debug
 #define yynerrs b4_prefix[]nerrs
-#define yylloc b4_prefix[]lloc])
+#define yylloc  b4_prefix[]lloc])
 
-b4_token_enums(b4_tokens)
+dnl # b4_shared_declarations
+dnl # ----------------------
+dnl # Declaration that might either go into the header (if --defines)
+dnl # or open coded in the parser body.
+m4_define([b4_shared_declarations],
+[b4_token_enums(b4_tokens)[
 
 /* Copy the first part of user declarations.  */
-b4_pre_prologue[
-
-/* Enabling traces.  */
-#ifndef YYDEBUG
-# define YYDEBUG ]b4_debug[
-#endif
-
-/* Enabling verbose error messages.  */
-#ifdef YYERROR_VERBOSE
-# undef YYERROR_VERBOSE
-# define YYERROR_VERBOSE 1
-#else
-# define YYERROR_VERBOSE ]b4_error_verbose[
-#endif
-
-/* Enabling the token table.  */
-#ifndef YYTOKEN_TABLE
-# define YYTOKEN_TABLE ]b4_token_table[
-#endif
+]b4_pre_prologue[
 
 #if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
 ]m4_ifdef([b4_stype],
@@ -208,6 +202,29 @@ typedef struct YYLTYPE
 # define YYLTYPE_IS_DECLARED 1
 # define YYLTYPE_IS_TRIVIAL 1
 #endif
+]])
+
+m4_if(b4_defines_flag, 0,
+      [b4_shared_declarations],
+      [#include @output_header_name@])[
+
+/* Enabling traces.  */
+#ifndef YYDEBUG
+# define YYDEBUG ]b4_debug[
+#endif
+
+/* Enabling verbose error messages.  */
+#ifdef YYERROR_VERBOSE
+# undef YYERROR_VERBOSE
+# define YYERROR_VERBOSE 1
+#else
+# define YYERROR_VERBOSE ]b4_error_verbose[
+#endif
+
+/* Enabling the token table.  */
+#ifndef YYTOKEN_TABLE
+# define YYTOKEN_TABLE ]b4_token_table[
+#endif
 
 /* Default (constant) value used for initialization for null
    right-hand sides.  Unlike the standard yacc.c template,
@@ -2365,39 +2382,11 @@ b4_epilogue
 m4_if(b4_defines_flag, 0, [],
 [@output @output_header_name@
 b4_copyright([Skeleton parser for GLR parsing with Bison],
-  [2002, 2003, 2004, 2005])
+             [2002, 2003, 2004, 2005])
 
-b4_token_enums(b4_tokens)
+b4_shared_declarations
 
-#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
-m4_ifdef([b4_stype],
-[b4_syncline([b4_stype_line], [b4_file_name])
-typedef union m4_bregexp(b4_stype, [^{], [YYSTYPE ])b4_stype YYSTYPE;
-/* Line __line__ of glr.c.  */
-b4_syncline([@oline@], [@ofile@])],
-[typedef int YYSTYPE;])
-# define YYSTYPE_IS_DECLARED 1
-# define YYSTYPE_IS_TRIVIAL 1
-#endif
-
-b4_pure_if([],
-[extern YYSTYPE b4_prefix[]lval;])
-
-#if ! defined (YYLTYPE) && ! defined (YYLTYPE_IS_DECLARED)
-typedef struct YYLTYPE
-{
-b4_location_if([
-  int first_line;
-  int first_column;
-  int last_line;
-  int last_column;
-],[
-  char yydummy;
-])
-} YYLTYPE;
-# define YYLTYPE_IS_DECLARED 1
-# define YYLTYPE_IS_TRIVIAL 1
-#endif
+extern YYSTYPE b4_prefix[]lval;
 
 b4_location_if([b4_pure_if([],
 [extern YYLTYPE b4_prefix[]lloc;])
