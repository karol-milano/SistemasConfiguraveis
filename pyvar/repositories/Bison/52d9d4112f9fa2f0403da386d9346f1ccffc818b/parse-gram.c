@@ -289,12 +289,23 @@ typedef struct YYLTYPE
 /* Line 219 of yacc.c.  */
 #line 291 "parse-gram.c"
 
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
@@ -336,8 +347,7 @@ typedef struct YYLTYPE
 #    define alloca _alloca
 #   else
 #    define YYSTACK_ALLOC alloca
-#    if (! defined (_ALLOCA_H) && ! defined (_STDLIB_H) \
-	 && (defined (__STDC__) || defined (__cplusplus)))
+#    if ! defined (_ALLOCA_H) && ! defined (_STDLIB_H) && YYMODERN_C
 #     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
 #     ifndef _STDLIB_H
 #      define _STDLIB_H 1
@@ -368,15 +378,13 @@ extern "C" {
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
@@ -445,7 +453,7 @@ union yyalloc
 
 #endif
 
-#if defined (__STDC__) || defined (__cplusplus)
+#if YYMODERN_C
    typedef signed char yysigned_char;
 #else
    typedef short int yysigned_char;
@@ -870,7 +878,7 @@ do {								\
 | TOP (included).                                                   |
 `------------------------------------------------------------------*/
 
-#if defined (__STDC__) || defined (__cplusplus)
+#if defined (__STDC__) || defined (__STDC_VERSION__) || defined (__cplusplus)
 static void
 yy_stack_print (short int *bottom, short int *top)
 #else
@@ -897,7 +905,7 @@ do {								\
 | Report that the YYRULE is going to be reduced.  |
 `------------------------------------------------*/
 
-#if defined (__STDC__) || defined (__cplusplus)
+#if defined (__STDC__) || defined (__STDC_VERSION__) || defined (__cplusplus)
 static void
 yy_reduce_print (int yyrule)
 #else
@@ -959,7 +967,7 @@ int yydebug;
 #  else
 /* Return the length of YYSTR.  */
 static YYSIZE_T
-#   if defined (__STDC__) || defined (__cplusplus)
+#   if YYMODERN_C
 yystrlen (const char *yystr)
 #   else
 yystrlen (yystr)
@@ -983,7 +991,7 @@ yystrlen (yystr)
 /* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
    YYDEST.  */
 static char *
-#   if defined (__STDC__) || defined (__cplusplus)
+#   if YYMODERN_C
 yystpcpy (char *yydest, const char *yysrc)
 #   else
 yystpcpy (yydest, yysrc)
@@ -1165,7 +1173,7 @@ yysyntax_error (char *yyresult, int yystate, int yychar)
 | Print this symbol on YYOUTPUT.  |
 `--------------------------------*/
 
-#if defined (__STDC__) || defined (__cplusplus)
+#if defined (__STDC__) || defined (__STDC_VERSION__) || defined (__cplusplus)
 static void
 yysymprint (FILE *yyoutput, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
 #else
@@ -1197,92 +1205,92 @@ yysymprint (yyoutput, yytype, yyvaluep, yylocationp)
       case 3: /* "\"string\"" */
 #line 169 "parse-gram.y"
         { fprintf (stderr, "\"%s\"", (yyvaluep->chars)); };
-#line 1201 "parse-gram.c"
+#line 1209 "parse-gram.c"
         break;
       case 4: /* "\"integer\"" */
 #line 182 "parse-gram.y"
         { fprintf (stderr, "%d", (yyvaluep->integer)); };
-#line 1206 "parse-gram.c"
+#line 1214 "parse-gram.c"
         break;
       case 8: /* "\"%destructor {...}\"" */
 #line 171 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1211 "parse-gram.c"
+#line 1219 "parse-gram.c"
         break;
       case 9: /* "\"%printer {...}\"" */
 #line 175 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1216 "parse-gram.c"
+#line 1224 "parse-gram.c"
         break;
       case 10: /* "\"%union {...}\"" */
 #line 176 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1221 "parse-gram.c"
+#line 1229 "parse-gram.c"
         break;
       case 26: /* "\"%initial-action {...}\"" */
 #line 172 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1226 "parse-gram.c"
+#line 1234 "parse-gram.c"
         break;
       case 27: /* "\"%lex-param {...}\"" */
 #line 173 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1231 "parse-gram.c"
+#line 1239 "parse-gram.c"
         break;
       case 34: /* "\"%parse-param {...}\"" */
 #line 174 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1236 "parse-gram.c"
+#line 1244 "parse-gram.c"
         break;
       case 42: /* "\"type\"" */
 #line 180 "parse-gram.y"
         { fprintf (stderr, "<%s>", (yyvaluep->uniqstr)); };
-#line 1241 "parse-gram.c"
+#line 1249 "parse-gram.c"
         break;
       case 46: /* "\"identifier\"" */
 #line 184 "parse-gram.y"
         { fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
-#line 1246 "parse-gram.c"
+#line 1254 "parse-gram.c"
         break;
       case 47: /* "\"identifier:\"" */
 #line 186 "parse-gram.y"
         { fprintf (stderr, "%s:", (yyvaluep->symbol)->tag); };
-#line 1251 "parse-gram.c"
+#line 1259 "parse-gram.c"
         break;
       case 49: /* "\"%{...%}\"" */
 #line 178 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1256 "parse-gram.c"
+#line 1264 "parse-gram.c"
         break;
       case 50: /* "\"epilogue\"" */
 #line 178 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1261 "parse-gram.c"
+#line 1269 "parse-gram.c"
         break;
       case 51: /* "\"{...}\"" */
 #line 177 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1266 "parse-gram.c"
+#line 1274 "parse-gram.c"
         break;
       case 72: /* "symbol" */
 #line 184 "parse-gram.y"
         { fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
-#line 1271 "parse-gram.c"
+#line 1279 "parse-gram.c"
         break;
       case 73: /* "action" */
 #line 177 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1276 "parse-gram.c"
+#line 1284 "parse-gram.c"
         break;
       case 74: /* "string_as_id" */
 #line 184 "parse-gram.y"
         { fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
-#line 1281 "parse-gram.c"
+#line 1289 "parse-gram.c"
         break;
       case 75: /* "string_content" */
 #line 169 "parse-gram.y"
         { fprintf (stderr, "\"%s\"", (yyvaluep->chars)); };
-#line 1286 "parse-gram.c"
+#line 1294 "parse-gram.c"
         break;
       default:
         break;
@@ -1295,7 +1303,7 @@ yysymprint (yyoutput, yytype, yyvaluep, yylocationp)
 | Release the memory associated to this symbol.  |
 `-----------------------------------------------*/
 
-#if defined (__STDC__) || defined (__cplusplus)
+#if defined (__STDC__) || defined (__STDC_VERSION__) || defined (__cplusplus)
 static void
 yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
 #else
@@ -1326,7 +1334,7 @@ yydestruct (yymsg, yytype, yyvaluep, yylocationp)
 /* Prevent warnings from -Wmissing-prototypes.  */
 
 #ifdef YYPARSE_PARAM
-# if defined (__STDC__) || defined (__cplusplus)
+# if YYMODERN_C
 int yyparse (void *YYPARSE_PARAM);
 # else
 int yyparse ();
@@ -1349,14 +1357,14 @@ int yyparse ();
 `----------*/
 
 #ifdef YYPARSE_PARAM
-# if defined (__STDC__) || defined (__cplusplus)
+# if YYMODERN_C
 int yyparse (void *YYPARSE_PARAM)
 # else
 int yyparse (YYPARSE_PARAM)
   void *YYPARSE_PARAM;
 # endif
 #else /* ! YYPARSE_PARAM */
-#if defined (__STDC__) || defined (__cplusplus)
+#if defined (__STDC__) || defined (__STDC_VERSION__) || defined (__cplusplus)
 int
 yyparse (void)
 #else
@@ -1460,8 +1468,8 @@ YYLTYPE yylloc;
   yylloc.start.line   = yylloc.end.line   = 1;
   yylloc.start.column = yylloc.end.column = 0;
 }
-/* Line 1056 of yacc.c.  */
-#line 1465 "parse-gram.c"
+/* Line 1064 of yacc.c.  */
+#line 1473 "parse-gram.c"
   yylsp[0] = yylloc;
   goto yysetstate;
 
@@ -2053,8 +2061,8 @@ yyreduce:
       default: break;
     }
 
-/* Line 1252 of yacc.c.  */
-#line 2058 "parse-gram.c"
+/* Line 1260 of yacc.c.  */
+#line 2066 "parse-gram.c"
 
   yyvsp -= yylen;
   yyssp -= yylen;
