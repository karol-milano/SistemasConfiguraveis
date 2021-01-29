@@ -246,13 +246,6 @@ b4_percent_code_get[]dnl
 # endif
 #endif
 
-/* Suppress unused-variable warnings by "using" E.  */
-#if ! defined lint || defined __GNUC__
-# define YYUSE(E) ((void) (E))
-#else
-# define YYUSE(E) /* empty */
-#endif
-
 /* Identity function, used to suppress warnings about constant conditions.  */
 #ifndef lint
 # define YYID(N) (N)
@@ -291,17 +284,7 @@ b4_percent_code_get[]dnl
 # define YYLONGJMP(Env, Val) (longjmp (Env, Val), YYASSERT (0))
 #endif
 
-/*-----------------.
-| GCC extensions.  |
-`-----------------*/
-
-#ifndef __attribute__
-/* This feature is available in gcc versions 2.5 and later.  */
-# if (! defined __GNUC__ || __GNUC__ < 2 \
-      || (__GNUC__ == 2 && __GNUC_MINOR__ < 5))
-#  define __attribute__(Spec) /* empty */
-# endif
-#endif
+]b4_attribute_define[
 
 #ifndef YYASSERT
 # define YYASSERT(Condition) ((void) ((Condition) || (abort (), 0)))
