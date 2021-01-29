@@ -284,18 +284,17 @@ typedef struct YYLTYPE
 /* Line 219 of yacc.c.  */
 #line 286 "parse-gram.c"
 
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
@@ -320,11 +319,20 @@ typedef struct YYLTYPE
 #  if YYSTACK_USE_ALLOCA
 #   ifdef __GNUC__
 #    define YYSTACK_ALLOC __builtin_alloca
+#   elif defined (__BUILTIN_VA_ARG_INCR)
+#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
+#   elif defined (_AIX)
+#    define YYSTACK_ALLOC __alloca
+#   elif defined (_MSC_VER)
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
@@ -351,14 +359,14 @@ extern "C" {
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
@@ -1174,92 +1182,92 @@ yysymprint (yyoutput, yytype, yyvaluep, yylocationp)
       case 3: /* "\"string\"" */
 #line 165 "parse-gram.y"
         { fprintf (stderr, "\"%s\"", (yyvaluep->chars)); };
-#line 1178 "parse-gram.c"
+#line 1186 "parse-gram.c"
         break;
       case 4: /* "\"integer\"" */
 #line 178 "parse-gram.y"
         { fprintf (stderr, "%d", (yyvaluep->integer)); };
-#line 1183 "parse-gram.c"
+#line 1191 "parse-gram.c"
         break;
       case 8: /* "\"%destructor {...}\"" */
 #line 167 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1188 "parse-gram.c"
+#line 1196 "parse-gram.c"
         break;
       case 9: /* "\"%printer {...}\"" */
 #line 171 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1193 "parse-gram.c"
+#line 1201 "parse-gram.c"
         break;
       case 10: /* "\"%union {...}\"" */
 #line 172 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1198 "parse-gram.c"
+#line 1206 "parse-gram.c"
         break;
       case 26: /* "\"%initial-action {...}\"" */
 #line 168 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1203 "parse-gram.c"
+#line 1211 "parse-gram.c"
         break;
       case 27: /* "\"%lex-param {...}\"" */
 #line 169 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1208 "parse-gram.c"
+#line 1216 "parse-gram.c"
         break;
       case 34: /* "\"%parse-param {...}\"" */
 #line 170 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1213 "parse-gram.c"
+#line 1221 "parse-gram.c"
         break;
       case 41: /* "\"type\"" */
 #line 176 "parse-gram.y"
         { fprintf (stderr, "<%s>", (yyvaluep->uniqstr)); };
-#line 1218 "parse-gram.c"
+#line 1226 "parse-gram.c"
         break;
       case 45: /* "\"identifier\"" */
 #line 180 "parse-gram.y"
         { fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
-#line 1223 "parse-gram.c"
+#line 1231 "parse-gram.c"
         break;
       case 46: /* "\"identifier:\"" */
 #line 182 "parse-gram.y"
         { fprintf (stderr, "%s:", (yyvaluep->symbol)->tag); };
-#line 1228 "parse-gram.c"
+#line 1236 "parse-gram.c"
         break;
       case 48: /* "\"%{...%}\"" */
 #line 174 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1233 "parse-gram.c"
+#line 1241 "parse-gram.c"
         break;
       case 49: /* "\"epilogue\"" */
 #line 174 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1238 "parse-gram.c"
+#line 1246 "parse-gram.c"
         break;
       case 50: /* "\"{...}\"" */
 #line 173 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1243 "parse-gram.c"
+#line 1251 "parse-gram.c"
         break;
       case 71: /* "symbol" */
 #line 180 "parse-gram.y"
         { fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
-#line 1248 "parse-gram.c"
+#line 1256 "parse-gram.c"
         break;
       case 72: /* "action" */
 #line 173 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1253 "parse-gram.c"
+#line 1261 "parse-gram.c"
         break;
       case 73: /* "string_as_id" */
 #line 180 "parse-gram.y"
         { fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
-#line 1258 "parse-gram.c"
+#line 1266 "parse-gram.c"
         break;
       case 74: /* "string_content" */
 #line 165 "parse-gram.y"
         { fprintf (stderr, "\"%s\"", (yyvaluep->chars)); };
-#line 1263 "parse-gram.c"
+#line 1271 "parse-gram.c"
         break;
       default:
         break;
@@ -1438,8 +1446,8 @@ YYLTYPE yylloc;
   yylloc.start.line   = yylloc.end.line   = 1;
   yylloc.start.column = yylloc.end.column = 0;
 }
-/* Line 1044 of yacc.c.  */
-#line 1443 "parse-gram.c"
+/* Line 1052 of yacc.c.  */
+#line 1451 "parse-gram.c"
   yylsp[0] = yylloc;
   goto yysetstate;
 
@@ -2021,8 +2029,8 @@ yyreduce:
       default: break;
     }
 
-/* Line 1240 of yacc.c.  */
-#line 2026 "parse-gram.c"
+/* Line 1248 of yacc.c.  */
+#line 2034 "parse-gram.c"
 
   yyvsp -= yylen;
   yyssp -= yylen;
