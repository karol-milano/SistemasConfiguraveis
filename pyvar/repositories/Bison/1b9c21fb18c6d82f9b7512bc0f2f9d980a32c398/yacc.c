@@ -220,25 +220,12 @@ typedef struct YYLTYPE
 /* Line __line__ of yacc.c.  */
 b4_syncline([@oline@], [@ofile@])[
 
-/* Define YYMODERN_C if this compiler supports C89 or better.  If
-   __STDC__ is defined, the compiler is modern.  IBM xlc 7.0 when run
-   as 'cc' doesn't define __STDC__ (or __STDC_VERSION__) for pedantic
-   reasons, but it defines __C99__FUNC__ so check that as well.
-   Consider a C++ compiler to be modern if it defines __cplusplus.  */
-#ifndef YYMODERN_C
-# if defined (__STDC__) || defined (__C99__FUNC__) || defined (__cplusplus)
-#  define YYMODERN_C 1
-# else
-#  define YYMODERN_C 0
-# endif
-#endif
-
 #ifndef YYSIZE_T
 # if defined (__SIZE_TYPE__)
 #  define YYSIZE_T __SIZE_TYPE__
 # elif defined (size_t)
 #  define YYSIZE_T size_t
-# elif ! defined (YYSIZE_T) && YYMODERN_C
+# elif ! defined (YYSIZE_T) && ]b4_c_modern[
 #  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
 #  define YYSIZE_T size_t
 # else
@@ -294,7 +281,7 @@ b4_syncline([@oline@], [@ofile@])[
 #    define alloca _alloca
 #   else
 #    define YYSTACK_ALLOC alloca
-#    if ! defined (_ALLOCA_H) && ! defined (_STDLIB_H) && YYMODERN_C
+#    if ! defined (_ALLOCA_H) && ! defined (_STDLIB_H) && ]b4_c_modern[
 #     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
 #     ifndef _STDLIB_H
 #      define _STDLIB_H 1
@@ -325,13 +312,13 @@ extern "C" {
 #  endif
 #  ifndef YYMALLOC
 #   define YYMALLOC malloc
-#   if ! defined (malloc) && ! defined (_STDLIB_H) && YYMODERN_C
+#   if ! defined (malloc) && ! defined (_STDLIB_H) && ]b4_c_modern[
 void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
 #   endif
 #  endif
 #  ifndef YYFREE
 #   define YYFREE free
-#   if ! defined (free) && ! defined (_STDLIB_H)  && YYMODERN_C
+#   if ! defined (free) && ! defined (_STDLIB_H) && ]b4_c_modern[
 void free (void *); /* INFRINGES ON USER NAME SPACE */
 #   endif
 #  endif
@@ -405,7 +392,7 @@ union yyalloc
 
 #endif
 
-#if YYMODERN_C
+#if ]b4_c_modern[
    typedef signed char yysigned_char;
 #else
    typedef short int yysigned_char;
@@ -747,13 +734,8 @@ int yydebug;
 #   define yystrlen strlen
 #  else
 /* Return the length of YYSTR.  */
-static YYSIZE_T
-#   if YYMODERN_C
-yystrlen (const char *yystr)
-#   else
-yystrlen (yystr)
-     const char *yystr;
-#   endif
+]b4_c_function_def([yystrlen], [static YYSIZE_T],
+   [[const char *yystr], [yystr]])[
 {
   YYSIZE_T yylen;
   for (yylen = 0; yystr[yylen]; yylen++)
@@ -769,14 +751,8 @@ yystrlen (yystr)
 #  else
 /* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
    YYDEST.  */
-static char *
-#   if YYMODERN_C
-yystpcpy (char *yydest, const char *yysrc)
-#   else
-yystpcpy (yydest, yysrc)
-     char *yydest;
-     const char *yysrc;
-#   endif
+]b4_c_function_def([yystpcpy], [static char *],
+   [[char *yydest], [yydest]], [[const char *yysrc], [yysrc]])[
 {
   char *yyd = yydest;
   const char *yys = yysrc;
@@ -953,11 +929,8 @@ yysyntax_error (char *yyresult, int yystate, int yychar)
 /* Prevent warnings from -Wmissing-prototypes.  */
 
 #ifdef YYPARSE_PARAM
-# if YYMODERN_C
-int yyparse (void *YYPARSE_PARAM);
-# else
-int yyparse ();
-# endif
+]b4_c_function_decl([yyparse], [int],
+   [[void *YYPARSE_PARAM], [YYPARSE_PARAM]])[
 #else /* ! YYPARSE_PARAM */
 ]b4_c_function_decl([yyparse], [int], b4_parse_param)[
 #endif /* ! YYPARSE_PARAM */
@@ -991,12 +964,7 @@ b4_pure_if([],
 `----------*/
 
 #ifdef YYPARSE_PARAM
-# if YYMODERN_C
-int yyparse (void *YYPARSE_PARAM)
-# else
-int yyparse (YYPARSE_PARAM)
-  void *YYPARSE_PARAM;
-# endif
+b4_c_function_def([yyparse], [int], [[void *YYPARSE_PARAM], [YYPARSE_PARAM]])
 #else /* ! YYPARSE_PARAM */
 b4_c_function_def([yyparse], [int], b4_parse_param)
 #endif
