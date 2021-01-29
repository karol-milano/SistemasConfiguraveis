@@ -279,14 +279,21 @@ typedef struct YYLTYPE
 /* Line 214 of yacc.c.  */
 #line 281 "parse-gram.c"
 
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
 
@@ -296,6 +303,10 @@ typedef struct YYLTYPE
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
@@ -311,17 +322,25 @@ typedef struct YYLTYPE
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
 
@@ -684,22 +703,6 @@ static const unsigned char yystos[] =
       16,    50,    71,    72,    70,    71,     4,    41
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
@@ -1162,8 +1165,8 @@ YYLTYPE yylloc;
   yylloc.start.line   = yylloc.end.line   = 1;
   yylloc.start.column = yylloc.end.column = 0;
 }
-/* Line 860 of yacc.c.  */
-#line 1167 "parse-gram.c"
+/* Line 863 of yacc.c.  */
+#line 1170 "parse-gram.c"
   yyvsp[0] = yylval;
     yylsp[0] = yylloc;
 
@@ -1747,8 +1750,8 @@ yyreduce:
       default: break;
     }
 
-/* Line 1056 of yacc.c.  */
-#line 1752 "parse-gram.c"
+/* Line 1059 of yacc.c.  */
+#line 1755 "parse-gram.c"
 
   yyvsp -= yylen;
   yyssp -= yylen;
