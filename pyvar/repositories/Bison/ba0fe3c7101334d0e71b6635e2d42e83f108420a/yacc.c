@@ -219,15 +219,17 @@ typedef struct YYLTYPE
 /* Line __line__ of yacc.c.  */
 b4_syncline([@oline@], [@ofile@])[
 
-/* Define YYMODERN_C if this compiler supports C89 or better.  Some
-   modern compilers (e.g., IBM xlc 7.0) don't define __STDC__ for
-   pedantic reasons, but they define __STDC_VERSION__ so check that
-   as well.  Consider a C++ compiler to be modern if it defines
-   __cplusplus.  */
-#if defined (__STDC__) || defined (__STDC_VERSION__) || defined (__cplusplus)
-# define YYMODERN_C 1
-#else
-# define YYMODERN_C 0
+/* Define YYMODERN_C if this compiler supports C89 or better.  If
+   __STDC__ is defined, the compiler is modern.  IBM xlc 7.0 when run
+   as 'cc' doesn't define __STDC__ (or __STDC_VERSION__) for pedantic
+   reasons, but it defines __C99__FUNC__ so check that as well.
+   Consider a C++ compiler to be modern if it defines __cplusplus.  */
+#ifndef YYMODERN_C
+# if defined (__STDC__) || defined (__C99__FUNC__) || defined (__cplusplus)
+#  define YYMODERN_C 1
+# else
+#  define YYMODERN_C 0
+# endif
 #endif
 
 #ifndef YYSIZE_T
