@@ -30,9 +30,6 @@ m4_include([c.m4])
 m4_define_default([b4_stack_depth_max], [10000])
 m4_define_default([b4_stack_depth_init],  [200])
 
-# Location type.
-m4_define_default([b4_location_type], [yyltype])
-
 
 ## ------------------------ ##
 ## Pure/impure interfaces.  ##
@@ -186,26 +183,28 @@ b4_location_if([#define yylloc b4_prefix[]lloc])])[
 # define YYERROR_VERBOSE ]b4_error_verbose[
 #endif
 
-#ifndef YYSTYPE
+#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
 ]m4_ifdef([b4_stype],
 [b4_syncline([b4_stype_line], [b4_filename])
-typedef union b4_stype yystype;
+typedef union m4_bregexp(b4_stype, [^{], [YYSTYPE ])b4_stype YYSTYPE;
 /* Line __line__ of yacc.c.  */
 b4_syncline([@oline@], [@ofile@])],
-[typedef int yystype;])[
-# define YYSTYPE yystype
+[typedef int YYSTYPE;])[
+# define yystype YYSTYPE /* obsolescent; will be withdrawn */
+# define YYSTYPE_IS_DECLARED 1
 # define YYSTYPE_IS_TRIVIAL 1
 #endif
 
-]b4_location_if([#ifndef YYLTYPE
-typedef struct yyltype
+]b4_location_if([#if ! defined (YYLTYPE) && ! defined (YYLTYPE_IS_DECLARED)
+typedef struct YYLTYPE
 {
   int first_line;
   int first_column;
   int last_line;
   int last_column;
-} yyltype;
-# define YYLTYPE ]b4_location_type[
+} YYLTYPE;
+# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
+# define YYLTYPE_IS_DECLARED 1
 # define YYLTYPE_IS_TRIVIAL 1
 #endif
 ])[
@@ -1194,14 +1193,15 @@ b4_copyright([Skeleton parser for Yacc-like parsing with Bison],
 
 b4_token_defines(b4_tokens)
 
-#ifndef YYSTYPE
+#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
 m4_ifdef([b4_stype],
 [b4_syncline([b4_stype_line], [b4_filename])
-typedef union b4_stype yystype;
+typedef union m4_bregexp(b4_stype, [^{], [YYSTYPE ])b4_stype YYSTYPE;
 /* Line __line__ of yacc.c.  */
 b4_syncline([@oline@], [@ofile@])],
-[typedef int yystype;])
-# define YYSTYPE yystype
+[typedef int YYSTYPE;])
+# define yystype YYSTYPE /* obsolescent; will be withdrawn */
+# define YYSTYPE_IS_DECLARED 1
 # define YYSTYPE_IS_TRIVIAL 1
 #endif
 
@@ -1209,15 +1209,17 @@ b4_pure_if([],
 [extern YYSTYPE b4_prefix[]lval;])
 
 b4_location_if(
-[#ifndef YYLTYPE
-typedef struct yyltype
+[#if ! defined (YYLTYPE) && ! defined (YYLTYPE_IS_DECLARED)
+typedef struct YYLTYPE
 {
   int first_line;
   int first_column;
   int last_line;
   int last_column;
-} yyltype;
-# define YYLTYPE yyltype
+} YYLTYPE;
+# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
+# define YYLTYPE_IS_DECLARED 1
+# define YYLTYPE_IS_TRIVIAL 1
 #endif
 
 m4_if(b4_pure, [0],
