@@ -28,9 +28,6 @@ m4_include([c.m4])
 m4_define_default([b4_stack_depth_max], [10000])
 m4_define_default([b4_stack_depth_init],  [200])
 
-# Location type.
-m4_define_default([b4_location_type], [yyltype])
-
 
 
 ## ------------------------ ##
@@ -183,26 +180,26 @@ b4_pre_prologue[
 # define YYERROR_VERBOSE ]b4_error_verbose[
 #endif
 
-#ifndef YYSTYPE
+#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
 ]m4_ifdef([b4_stype],
 [b4_syncline([b4_stype_line], [b4_filename])
-typedef union b4_stype yystype;
+typedef union m4_bregexp(b4_stype, [^{], [YYSTYPE ])b4_stype YYSTYPE;
 /* Line __line__ of glr.c.  */
 b4_syncline([@oline@], [@ofile@])],
-[typedef int yystype;])[
-# define YYSTYPE yystype
+[typedef int YYSTYPE;])[
+# define YYSTYPE_IS_DECLARED 1
 # define YYSTYPE_IS_TRIVIAL 1
 #endif
 
-#ifndef YYLTYPE
-typedef struct yyltype
+#if ! defined (YYLTYPE) && ! defined (YYLTYPE_IS_DECLARED)
+typedef struct YYLTYPE
 {
   int first_line;
   int first_column;
   int last_line;
   int last_column;
-} yyltype;
-# define YYLTYPE ]b4_location_type[
+} YYLTYPE;
+# define YYLTYPE_IS_DECLARED 1
 # define YYLTYPE_IS_TRIVIAL 1
 #endif
 
@@ -513,8 +510,9 @@ int yydebug;
    properly redirected to new data. */
 #define YYHEADROOM 2
 
-#if ! defined (YYSTACKEXPANDABLE) \
-    && (! defined (__cplusplus) || (YYLTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL))
+#if (! defined (YYSTACKEXPANDABLE) \
+     && (! defined (__cplusplus) \
+	 || (]b4_location_if([YYLTYPE_IS_TRIVIAL && ])[YYSTYPE_IS_TRIVIAL)))
 #define YYSTACKEXPANDABLE 1
 #else
 #define YYSTACKEXPANDABLE 0
@@ -1955,14 +1953,14 @@ b4_copyright([Skeleton parser for GLR parsing with Bison], [2002])
 
 b4_token_defines(b4_tokens)
 
-#ifndef YYSTYPE
+#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
 m4_ifdef([b4_stype],
 [b4_syncline([b4_stype_line], [b4_filename])
-typedef union b4_stype yystype;
+typedef union m4_bregexp(b4_stype, [^{], [YYSTYPE ])b4_stype YYSTYPE;
 /* Line __line__ of glr.c.  */
 b4_syncline([@oline@], [@ofile@])],
-[typedef int yystype;])
-# define YYSTYPE yystype
+[typedef int YYSTYPE;])
+# define YYSTYPE_IS_DECLARED 1
 # define YYSTYPE_IS_TRIVIAL 1
 #endif
 
@@ -1970,15 +1968,16 @@ b4_pure_if([],
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
+# define YYLTYPE_IS_DECLARED 1
+# define YYLTYPE_IS_TRIVIAL 1
 #endif
 
 m4_if(b4_pure, [0],
