@@ -219,18 +219,17 @@ typedef struct YYLTYPE
 /* Line __line__ of yacc.c.  */
 b4_syncline([@oline@], [@ofile@])[
 
-#if ! defined (YYSIZE_T) && defined (__SIZE_TYPE__)
-# define YYSIZE_T __SIZE_TYPE__
-#endif
-#if ! defined (YYSIZE_T) && defined (size_t)
-# define YYSIZE_T size_t
-#endif
-#if ! defined (YYSIZE_T) && (defined (__STDC__) || defined (__cplusplus))
-# include <stddef.h> /* INFRINGES ON USER NAME SPACE */
-# define YYSIZE_T size_t
-#endif
-#if ! defined (YYSIZE_T)
-# define YYSIZE_T unsigned int
+#ifndef YYSIZE_T
+# if defined (__SIZE_TYPE__)
+#  define YYSIZE_T __SIZE_TYPE__
+# elif defined (size_t)
+#  define YYSIZE_T size_t
+# elif ! defined (YYSIZE_T) && (defined (__STDC__) || defined (__cplusplus))
+#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
+#  define YYSIZE_T size_t
+# else
+#  define YYSIZE_T unsigned int
+# endif
 #endif
 
 #define YYSIZE_MAXIMUM ((YYSIZE_T) -1)
@@ -255,11 +254,20 @@ b4_syncline([@oline@], [@ofile@])[
 #  if YYSTACK_USE_ALLOCA
 #   ifdef __GNUC__
 #    define YYSTACK_ALLOC __builtin_alloca
+#   elif defined __BUILTIN_VA_ARG_INCR
+#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
+#   elif defined _AIX
+#    define YYSTACK_ALLOC __alloca
+#   elif defined _MSC_VER
+#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
+#    define alloca _alloca
 #   else
 #    define YYSTACK_ALLOC alloca
-#    if defined (__STDC__) || defined (__cplusplus)
+#    if ! defined (_STDLIB_H) && (defined (__STDC__) || defined (__cplusplus))
 #     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
-#     define YYINCLUDED_STDLIB_H
+#     ifndef _STDLIB_H
+#      define _STDLIB_H 1
+#     endif
 #    endif
 #   endif
 #  endif
@@ -286,14 +294,14 @@ extern "C" {
 #  endif
 #  ifndef YYMALLOC
 #   define YYMALLOC malloc
-#   if (! defined (malloc) && ! defined (YYINCLUDED_STDLIB_H) \
+#   if (! defined (malloc) && ! defined (_STDLIB_H) \
 	&& (defined (__STDC__) || defined (__cplusplus)))
 void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
 #   endif
 #  endif
 #  ifndef YYFREE
 #   define YYFREE free
-#   if (! defined (free) && ! defined (YYINCLUDED_STDLIB_H) \
+#   if (! defined (free) && ! defined (_STDLIB_H) \
 	&& (defined (__STDC__) || defined (__cplusplus)))
 void free (void *); /* INFRINGES ON USER NAME SPACE */
 #   endif
