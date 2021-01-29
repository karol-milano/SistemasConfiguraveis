@@ -171,7 +171,7 @@ m4_define([b4_shared_declarations],
 /* Copy the first part of user declarations.  */
 ]b4_pre_prologue[
 
-#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
+#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
 ]m4_ifdef([b4_stype],
 [typedef union m4_bregexp(b4_stype, [^{], [YYSTYPE ])
 b4_stype
@@ -183,7 +183,7 @@ b4_syncline([@oline@], [@ofile@])
 # define YYSTYPE_IS_TRIVIAL 1
 #endif
 
-#if ! defined (YYLTYPE) && ! defined (YYLTYPE_IS_DECLARED)
+#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
 typedef struct YYLTYPE
 {
 ]b4_location_if([
@@ -253,7 +253,7 @@ b4_syncline([@oline@], [@ofile@])
 #endif
 
 /* Suppress unused-variable warnings by "using" E.  */
-#if !defined (lint) || defined (__GNUC__)
+#if ! defined lint || defined __GNUC__
 # define YYUSE(e) ((void) (e))
 #else
 # define YYUSE(e) /* empty */
@@ -302,7 +302,7 @@ b4_syncline([@oline@], [@ofile@])
 
 #ifndef __attribute__
 /* This feature is available in gcc versions 2.5 and later.  */
-# if (!defined (__GNUC__) || __GNUC__ < 2 \
+# if (! defined __GNUC__ || __GNUC__ < 2 \
       || (__GNUC__ == 2 && __GNUC_MINOR__ < 5) || __STRICT_ANSI__)
 #  define __attribute__(Spec) /* empty */
 # endif
@@ -563,9 +563,9 @@ typedef enum { yyok, yyaccept, yyabort, yyerr } YYRESULTTAG;
 
 #if YYDEBUG
 
-#if ! defined (YYFPRINTF)
+# ifndef YYFPRINTF
 #  define YYFPRINTF fprintf
-#endif
+# endif
 
 # define YYDPRINTF(Args)			\
 do {						\
@@ -621,9 +621,9 @@ int yydebug;
 #define YYHEADROOM 2
 
 #ifndef YYSTACKEXPANDABLE
-# if (! defined (__cplusplus) \
-      || (]b4_location_if([[defined (YYLTYPE_IS_TRIVIAL) && YYLTYPE_IS_TRIVIAL \
-	  && ]])[defined (YYSTYPE_IS_TRIVIAL) && YYSTYPE_IS_TRIVIAL))
+# if (! defined __cplusplus \
+      || (]b4_location_if([[defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
+	  && ]])[defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL))
 #  define YYSTACKEXPANDABLE 1
 # else
 #  define YYSTACKEXPANDABLE 0
@@ -648,7 +648,7 @@ int yydebug;
 #if YYERROR_VERBOSE
 
 # ifndef yystpcpy
-#  if defined (__GLIBC__) && defined (_STRING_H) && defined (_GNU_SOURCE)
+#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
 #   define yystpcpy stpcpy
 #  else
 /* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
