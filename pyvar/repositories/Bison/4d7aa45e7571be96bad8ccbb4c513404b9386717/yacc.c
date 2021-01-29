@@ -219,12 +219,23 @@ typedef struct YYLTYPE
 /* Line __line__ of yacc.c.  */
 b4_syncline([@oline@], [@ofile@])[
 
+/* Define YYMODERN_C if this compiler supports C89 or better.  Some
+   modern compilers (e.g., IBM xlc 7.0) don't define __STDC__ for
+   pedantic reasons, but they define __STDC_VERSION__ so check that
+   as well.  Consider a C++ compiler to be modern if it defines
+   __cplusplus.  */
+#if defined (__STDC__) || defined (__STDC_VERSION__) || defined (__cplusplus)
+# define YYMODERN_C 1
+#else
+# define YYMODERN_C 0
+#endif
+
 #ifndef YYSIZE_T
 # if defined (__SIZE_TYPE__)
 #  define YYSIZE_T __SIZE_TYPE__
 # elif defined (size_t)
 #  define YYSIZE_T size_t
-# elif ! defined (YYSIZE_T) && (defined (__STDC__) || defined (__cplusplus))
+# elif ! defined (YYSIZE_T) && YYMODERN_C
 #  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
 #  define YYSIZE_T size_t
 # else
@@ -266,8 +277,7 @@ b4_syncline([@oline@], [@ofile@])[
 #    define alloca _alloca
 #   else
 #    define YYSTACK_ALLOC alloca
-#    if (! defined (_ALLOCA_H) && ! defined (_STDLIB_H) \
-	 && (defined (__STDC__) || defined (__cplusplus)))
+#    if ! defined (_ALLOCA_H) && ! defined (_STDLIB_H) && YYMODERN_C
 #     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
 #     ifndef _STDLIB_H
 #      define _STDLIB_H 1
@@ -298,15 +308,13 @@ extern "C" {
 #  endif
 #  ifndef YYMALLOC
 #   define YYMALLOC malloc
-#   if (! defined (malloc) && ! defined (_STDLIB_H) \
-	&& (defined (__STDC__) || defined (__cplusplus)))
+#   if ! defined (malloc) && ! defined (_STDLIB_H) && YYMODERN_C
 void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
 #   endif
 #  endif
 #  ifndef YYFREE
 #   define YYFREE free
-#   if (! defined (free) && ! defined (_STDLIB_H) \
-	&& (defined (__STDC__) || defined (__cplusplus)))
+#   if ! defined (free) && ! defined (_STDLIB_H)  && YYMODERN_C
 void free (void *); /* INFRINGES ON USER NAME SPACE */
 #   endif
 #  endif
@@ -380,7 +388,7 @@ union yyalloc
 
 #endif
 
-#if defined (__STDC__) || defined (__cplusplus)
+#if YYMODERN_C
    typedef signed char yysigned_char;
 #else
    typedef short int yysigned_char;
@@ -711,7 +719,7 @@ int yydebug;
 #  else
 /* Return the length of YYSTR.  */
 static YYSIZE_T
-#   if defined (__STDC__) || defined (__cplusplus)
+#   if YYMODERN_C
 yystrlen (const char *yystr)
 #   else
 yystrlen (yystr)
@@ -735,7 +743,7 @@ yystrlen (yystr)
 /* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
    YYDEST.  */
 static char *
-#   if defined (__STDC__) || defined (__cplusplus)
+#   if YYMODERN_C
 yystpcpy (char *yydest, const char *yysrc)
 #   else
 yystpcpy (yydest, yysrc)
@@ -921,7 +929,7 @@ yysyntax_error (char *yyresult, int yystate, int yychar)
 /* Prevent warnings from -Wmissing-prototypes.  */
 
 #ifdef YYPARSE_PARAM
-# if defined (__STDC__) || defined (__cplusplus)
+# if YYMODERN_C
 int yyparse (void *YYPARSE_PARAM);
 # else
 int yyparse ();
@@ -959,7 +967,7 @@ b4_pure_if([],
 `----------*/
 
 #ifdef YYPARSE_PARAM
-# if defined (__STDC__) || defined (__cplusplus)
+# if YYMODERN_C
 int yyparse (void *YYPARSE_PARAM)
 # else
 int yyparse (YYPARSE_PARAM)
