@@ -214,14 +214,21 @@ typedef struct YYLTYPE
 /* Line __line__ of yacc.c.  */
 b4_syncline([@oline@], [@ofile@])[
 
-#if ! defined (yyoverflow) || YYERROR_VERBOSE
+#if ! defined (YYSIZE_T) && defined (__SIZE_TYPE__)
+# define YYSIZE_T __SIZE_TYPE__
+#endif
+#if ! defined (YYSIZE_T) && defined (size_t)
+# define YYSIZE_T size_t
+#endif
+#if ! defined (YYSIZE_T) && (defined (__STDC__) || defined (__cplusplus))
+# include <stddef.h> /* INFRINGES ON USER NAME SPACE */
+# define YYSIZE_T size_t
+#endif
+#if ! defined (YYSIZE_T)
+# define YYSIZE_T unsigned int
+#endif
 
-# ifndef YYFREE
-#  define YYFREE free
-# endif
-# ifndef YYMALLOC
-#  define YYMALLOC malloc
-# endif
+#if ! defined (yyoverflow) || YYERROR_VERBOSE
 
 /* The parser invokes alloca or malloc; define the necessary symbols.  */
 
@@ -231,6 +238,10 @@ b4_syncline([@oline@], [@ofile@])[
 #    define YYSTACK_ALLOC __builtin_alloca
 #   else
 #    define YYSTACK_ALLOC alloca
+#    if defined (__STDC__) || defined (__cplusplus)
+#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
+#     define YYINCLUDED_STDLIB_H
+#    endif
 #   endif
 #  endif
 # endif
@@ -246,17 +257,25 @@ b4_syncline([@oline@], [@ofile@])[
 #   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2005 */
 #  endif
 # else
-#  if defined (__STDC__) || defined (__cplusplus)
-#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
-#   define YYSIZE_T size_t
-#  else
-#   define YYSIZE_T unsigned long int
-#  endif
 #  define YYSTACK_ALLOC YYMALLOC
 #  define YYSTACK_FREE YYFREE
 #  ifndef YYSTACK_ALLOC_MAXIMUM
 #   define YYSTACK_ALLOC_MAXIMUM ((YYSIZE_T) -1)
 #  endif
+#  ifndef YYMALLOC
+#   define YYMALLOC malloc
+#   if (! defined (malloc) && ! defined (YYINCLUDED_STDLIB_H) \
+	&& (defined (__STDC__) || defined (__cplusplus)))
+void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
+#   endif
+#  endif
+#  ifndef YYFREE
+#   define YYFREE free
+#   if (! defined (free) && ! defined (YYINCLUDED_STDLIB_H) \
+	&& (defined (__STDC__) || defined (__cplusplus)))
+void free (void *); /* INFRINGES ON USER NAME SPACE */
+#   endif
+#  endif
 # endif
 #endif /* ! defined (yyoverflow) || YYERROR_VERBOSE */
 
@@ -463,22 +482,6 @@ static const ]b4_int_type_for([b4_stos])[ yystos[] =
   ]b4_stos[
 };
 
-#if ! defined (YYSIZE_T) && defined (__SIZE_TYPE__)
-# define YYSIZE_T __SIZE_TYPE__
-#endif
-#if ! defined (YYSIZE_T) && defined (size_t)
-# define YYSIZE_T size_t
-#endif
-#if ! defined (YYSIZE_T)
-# if defined (__STDC__) || defined (__cplusplus)
-#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
-#  define YYSIZE_T size_t
-# endif
-#endif
-#if ! defined (YYSIZE_T)
-# define YYSIZE_T unsigned int
-#endif
-
 #define yyerrok		(yyerrstatus = 0)
 #define yyclearin	(yychar = YYEMPTY)
 #define YYEMPTY		(-2)
