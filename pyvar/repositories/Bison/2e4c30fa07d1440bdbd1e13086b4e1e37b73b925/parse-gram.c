@@ -291,25 +291,13 @@ typedef struct YYLTYPE
 /* Line 220 of yacc.c.  */
 #line 293 "parse-gram.c"
 
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
+# elif ! defined (YYSIZE_T) && (defined (__STDC__) || defined (__C99__FUNC__) \
+     || defined (__cplusplus) || defined (_MSC_VER))
 #  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
 #  define YYSIZE_T size_t
 # else
@@ -342,7 +330,8 @@ typedef struct YYLTYPE
 #ifndef lint
 # define YYID(n) (n)
 #else
-#if defined (__STDC__) || defined (__C99__FUNC__) || defined (__cplusplus)
+#if (defined (__STDC__) || defined (__C99__FUNC__) \
+     || defined (__cplusplus) || defined (_MSC_VER))
 static int
 YYID (int i)
 #else
@@ -372,7 +361,8 @@ YYID (i)
 #    define alloca _alloca
 #   else
 #    define YYSTACK_ALLOC alloca
-#    if ! defined (_ALLOCA_H) && ! defined (_STDLIB_H) && YYMODERN_C
+#    if ! defined (_ALLOCA_H) && ! defined (_STDLIB_H) && (defined (__STDC__) || defined (__C99__FUNC__) \
+     || defined (__cplusplus) || defined (_MSC_VER))
 #     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
 #     ifndef _STDLIB_H
 #      define _STDLIB_H 1
@@ -403,13 +393,15 @@ extern "C" {
 #  endif
 #  ifndef YYMALLOC
 #   define YYMALLOC malloc
-#   if ! defined (malloc) && ! defined (_STDLIB_H) && YYMODERN_C
+#   if ! defined (malloc) && ! defined (_STDLIB_H) && (defined (__STDC__) || defined (__C99__FUNC__) \
+     || defined (__cplusplus) || defined (_MSC_VER))
 void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
 #   endif
 #  endif
 #  ifndef YYFREE
 #   define YYFREE free
-#   if ! defined (free) && ! defined (_STDLIB_H)  && YYMODERN_C
+#   if ! defined (free) && ! defined (_STDLIB_H) && (defined (__STDC__) || defined (__C99__FUNC__) \
+     || defined (__cplusplus) || defined (_MSC_VER))
 void free (void *); /* INFRINGES ON USER NAME SPACE */
 #   endif
 #  endif
@@ -478,7 +470,8 @@ union yyalloc
 
 #endif
 
-#if YYMODERN_C
+#if (defined (__STDC__) || defined (__C99__FUNC__) \
+     || defined (__cplusplus) || defined (_MSC_VER))
    typedef signed char yysigned_char;
 #else
    typedef short int yysigned_char;
@@ -904,7 +897,8 @@ do {									  \
 `--------------------------------*/
 
 /*ARGSUSED*/
-#if defined (__STDC__) || defined (__C99__FUNC__) || defined (__cplusplus)
+#if (defined (__STDC__) || defined (__C99__FUNC__) \
+     || defined (__cplusplus) || defined (_MSC_VER))
 static void
 yy_symbol_value_print (FILE *yyoutput, int yytype, const YYSTYPE * const yyvaluep, const YYLTYPE * const yylocationp)
 #else
@@ -927,92 +921,92 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
       case 3: /* "\"string\"" */
 #line 169 "parse-gram.y"
         { fprintf (stderr, "\"%s\"", (yyvaluep->chars)); };
-#line 931 "parse-gram.c"
+#line 925 "parse-gram.c"
         break;
       case 4: /* "\"integer\"" */
 #line 182 "parse-gram.y"
         { fprintf (stderr, "%d", (yyvaluep->integer)); };
-#line 936 "parse-gram.c"
+#line 930 "parse-gram.c"
         break;
       case 8: /* "\"%destructor {...}\"" */
 #line 171 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 941 "parse-gram.c"
+#line 935 "parse-gram.c"
         break;
       case 9: /* "\"%printer {...}\"" */
 #line 175 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 946 "parse-gram.c"
+#line 940 "parse-gram.c"
         break;
       case 10: /* "\"%union {...}\"" */
 #line 176 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 951 "parse-gram.c"
+#line 945 "parse-gram.c"
         break;
       case 26: /* "\"%initial-action {...}\"" */
 #line 172 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 956 "parse-gram.c"
+#line 950 "parse-gram.c"
         break;
       case 27: /* "\"%lex-param {...}\"" */
 #line 173 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 961 "parse-gram.c"
+#line 955 "parse-gram.c"
         break;
       case 34: /* "\"%parse-param {...}\"" */
 #line 174 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 966 "parse-gram.c"
+#line 960 "parse-gram.c"
         break;
       case 42: /* "\"type\"" */
 #line 180 "parse-gram.y"
         { fprintf (stderr, "<%s>", (yyvaluep->uniqstr)); };
-#line 971 "parse-gram.c"
+#line 965 "parse-gram.c"
         break;
       case 46: /* "\"identifier\"" */
 #line 184 "parse-gram.y"
         { fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
-#line 976 "parse-gram.c"
+#line 970 "parse-gram.c"
         break;
       case 47: /* "\"identifier:\"" */
 #line 186 "parse-gram.y"
         { fprintf (stderr, "%s:", (yyvaluep->symbol)->tag); };
-#line 981 "parse-gram.c"
+#line 975 "parse-gram.c"
         break;
       case 49: /* "\"%{...%}\"" */
 #line 178 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 986 "parse-gram.c"
+#line 980 "parse-gram.c"
         break;
       case 50: /* "\"epilogue\"" */
 #line 178 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 991 "parse-gram.c"
+#line 985 "parse-gram.c"
         break;
       case 51: /* "\"{...}\"" */
 #line 177 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 996 "parse-gram.c"
+#line 990 "parse-gram.c"
         break;
       case 72: /* "symbol" */
 #line 184 "parse-gram.y"
         { fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
-#line 1001 "parse-gram.c"
+#line 995 "parse-gram.c"
         break;
       case 73: /* "action" */
 #line 177 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1006 "parse-gram.c"
+#line 1000 "parse-gram.c"
         break;
       case 74: /* "string_as_id" */
 #line 184 "parse-gram.y"
         { fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
-#line 1011 "parse-gram.c"
+#line 1005 "parse-gram.c"
         break;
       case 75: /* "string_content" */
 #line 169 "parse-gram.y"
         { fprintf (stderr, "\"%s\"", (yyvaluep->chars)); };
-#line 1016 "parse-gram.c"
+#line 1010 "parse-gram.c"
         break;
       default:
         break;
@@ -1024,7 +1018,8 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 | Print this symbol on YYOUTPUT.  |
 `--------------------------------*/
 
-#if defined (__STDC__) || defined (__C99__FUNC__) || defined (__cplusplus)
+#if (defined (__STDC__) || defined (__C99__FUNC__) \
+     || defined (__cplusplus) || defined (_MSC_VER))
 static void
 yy_symbol_print (FILE *yyoutput, int yytype, const YYSTYPE * const yyvaluep, const YYLTYPE * const yylocationp)
 #else
@@ -1052,7 +1047,8 @@ yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp)
 | TOP (included).                                                   |
 `------------------------------------------------------------------*/
 
-#if defined (__STDC__) || defined (__C99__FUNC__) || defined (__cplusplus)
+#if (defined (__STDC__) || defined (__C99__FUNC__) \
+     || defined (__cplusplus) || defined (_MSC_VER))
 static void
 yy_stack_print (short int *bottom, short int *top)
 #else
@@ -1079,7 +1075,8 @@ do {								\
 | Report that the YYRULE is going to be reduced.  |
 `------------------------------------------------*/
 
-#if defined (__STDC__) || defined (__C99__FUNC__) || defined (__cplusplus)
+#if (defined (__STDC__) || defined (__C99__FUNC__) \
+     || defined (__cplusplus) || defined (_MSC_VER))
 static void
 yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
 #else
@@ -1149,13 +1146,15 @@ int yydebug;
 #   define yystrlen strlen
 #  else
 /* Return the length of YYSTR.  */
+#if (defined (__STDC__) || defined (__C99__FUNC__) \
+     || defined (__cplusplus) || defined (_MSC_VER))
 static YYSIZE_T
-#   if YYMODERN_C
 yystrlen (const char *yystr)
-#   else
+#else
+static YYSIZE_T
 yystrlen (yystr)
-     const char *yystr;
-#   endif
+    const char *yystr;
+#endif
 {
   YYSIZE_T yylen;
   for (yylen = 0; yystr[yylen]; yylen++)
@@ -1171,14 +1170,16 @@ yystrlen (yystr)
 #  else
 /* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
    YYDEST.  */
+#if (defined (__STDC__) || defined (__C99__FUNC__) \
+     || defined (__cplusplus) || defined (_MSC_VER))
 static char *
-#   if YYMODERN_C
 yystpcpy (char *yydest, const char *yysrc)
-#   else
+#else
+static char *
 yystpcpy (yydest, yysrc)
-     char *yydest;
-     const char *yysrc;
-#   endif
+    char *yydest;
+    const char *yysrc;
+#endif
 {
   char *yyd = yydest;
   const char *yys = yysrc;
@@ -1354,7 +1355,8 @@ yysyntax_error (char *yyresult, int yystate, int yychar)
 `-----------------------------------------------*/
 
 /*ARGSUSED*/
-#if defined (__STDC__) || defined (__C99__FUNC__) || defined (__cplusplus)
+#if (defined (__STDC__) || defined (__C99__FUNC__) \
+     || defined (__cplusplus) || defined (_MSC_VER))
 static void
 yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
 #else
@@ -1385,11 +1387,11 @@ yydestruct (yymsg, yytype, yyvaluep, yylocationp)
 /* Prevent warnings from -Wmissing-prototypes.  */
 
 #ifdef YYPARSE_PARAM
-# if YYMODERN_C
+#if defined (__STDC__) || defined (__cplusplus)
 int yyparse (void *YYPARSE_PARAM);
-# else
+#else
 int yyparse ();
-# endif
+#endif
 #else /* ! YYPARSE_PARAM */
 #if defined (__STDC__) || defined (__cplusplus)
 int yyparse (void);
@@ -1408,14 +1410,18 @@ int yyparse ();
 `----------*/
 
 #ifdef YYPARSE_PARAM
-# if YYMODERN_C
-int yyparse (void *YYPARSE_PARAM)
-# else
-int yyparse (YYPARSE_PARAM)
-  void *YYPARSE_PARAM;
-# endif
+#if (defined (__STDC__) || defined (__C99__FUNC__) \
+     || defined (__cplusplus) || defined (_MSC_VER))
+int
+yyparse (void *YYPARSE_PARAM)
+#else
+int
+yyparse (YYPARSE_PARAM)
+    void *YYPARSE_PARAM;
+#endif
 #else /* ! YYPARSE_PARAM */
-#if defined (__STDC__) || defined (__C99__FUNC__) || defined (__cplusplus)
+#if (defined (__STDC__) || defined (__C99__FUNC__) \
+     || defined (__cplusplus) || defined (_MSC_VER))
 int
 yyparse (void)
 #else
@@ -1519,8 +1525,8 @@ YYLTYPE yylloc;
   yylloc.start.line   = yylloc.end.line   = 1;
   yylloc.start.column = yylloc.end.column = 0;
 }
-/* Line 1088 of yacc.c.  */
-#line 1524 "parse-gram.c"
+/* Line 1056 of yacc.c.  */
+#line 1530 "parse-gram.c"
   yylsp[0] = yylloc;
   goto yysetstate;
 
@@ -2107,8 +2113,8 @@ yyreduce:
     break;
 
 
-/* Line 1277 of yacc.c.  */
-#line 2112 "parse-gram.c"
+/* Line 1245 of yacc.c.  */
+#line 2118 "parse-gram.c"
       default: break;
     }
   YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);
