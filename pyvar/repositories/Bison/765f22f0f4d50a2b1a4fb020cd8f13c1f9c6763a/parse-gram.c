@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 2.1a.  */
+/* A Bison parser, made by GNU Bison 2.1b.  */
 
 /* Skeleton parser for Yacc-like parsing with Bison,
    Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006 Free Software Foundation, Inc.
@@ -37,7 +37,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "2.1a"
+#define YYBISON_VERSION "2.1b"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -432,8 +432,13 @@ YYID (i)
 #  ifndef YYSTACK_ALLOC_MAXIMUM
 #   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
 #  endif
-#  ifdef __cplusplus
-extern "C" {
+#  if (defined __cplusplus && ! defined _STDLIB_H \
+       && ! ((defined YYMALLOC || defined malloc) \
+	     && (defined YYFREE || defined free)))
+#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
+#   ifndef _STDLIB_H
+#    define _STDLIB_H 1
+#   endif
 #  endif
 #  ifndef YYMALLOC
 #   define YYMALLOC malloc
@@ -449,9 +454,6 @@ void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
 void free (void *); /* INFRINGES ON USER NAME SPACE */
 #   endif
 #  endif
-#  ifdef __cplusplus
-}
-#  endif
 # endif
 #endif /* ! defined yyoverflow || YYERROR_VERBOSE */
 
@@ -962,84 +964,84 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
   switch (yytype)
     {
       case 3: /* "\"string\"" */
-#line 181 "parse-gram.y"
+#line 180 "parse-gram.y"
 	{ fprintf (stderr, "\"%s\"", (yyvaluep->chars)); };
-#line 968 "parse-gram.c"
+#line 970 "parse-gram.c"
 	break;
       case 4: /* "\"integer\"" */
 #line 193 "parse-gram.y"
 	{ fprintf (stderr, "%d", (yyvaluep->integer)); };
-#line 973 "parse-gram.c"
+#line 975 "parse-gram.c"
 	break;
       case 8: /* "\"%destructor {...}\"" */
-#line 183 "parse-gram.y"
+#line 182 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 978 "parse-gram.c"
+#line 980 "parse-gram.c"
 	break;
       case 9: /* "\"%printer {...}\"" */
-#line 187 "parse-gram.y"
+#line 182 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 983 "parse-gram.c"
+#line 985 "parse-gram.c"
 	break;
       case 10: /* "\"%union {...}\"" */
-#line 188 "parse-gram.y"
+#line 182 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 988 "parse-gram.c"
+#line 990 "parse-gram.c"
 	break;
       case 26: /* "\"%initial-action {...}\"" */
-#line 184 "parse-gram.y"
+#line 182 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 993 "parse-gram.c"
+#line 995 "parse-gram.c"
 	break;
       case 27: /* "\"%lex-param {...}\"" */
-#line 185 "parse-gram.y"
+#line 182 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 998 "parse-gram.c"
+#line 1000 "parse-gram.c"
 	break;
       case 34: /* "\"%parse-param {...}\"" */
-#line 186 "parse-gram.y"
+#line 182 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1003 "parse-gram.c"
+#line 1005 "parse-gram.c"
 	break;
       case 42: /* "\"type\"" */
 #line 191 "parse-gram.y"
 	{ fprintf (stderr, "<%s>", (yyvaluep->uniqstr)); };
-#line 1008 "parse-gram.c"
+#line 1010 "parse-gram.c"
 	break;
       case 46: /* "\"identifier\"" */
 #line 195 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
-#line 1013 "parse-gram.c"
+#line 1015 "parse-gram.c"
 	break;
       case 47: /* "\"identifier:\"" */
 #line 197 "parse-gram.y"
 	{ fprintf (stderr, "%s:", (yyvaluep->symbol)->tag); };
-#line 1018 "parse-gram.c"
+#line 1020 "parse-gram.c"
 	break;
       case 49: /* "\"%{...%}\"" */
-#line 189 "parse-gram.y"
+#line 182 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1023 "parse-gram.c"
+#line 1025 "parse-gram.c"
 	break;
       case 50: /* "\"epilogue\"" */
-#line 189 "parse-gram.y"
+#line 182 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1028 "parse-gram.c"
+#line 1030 "parse-gram.c"
 	break;
       case 72: /* "symbol" */
 #line 195 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
-#line 1033 "parse-gram.c"
+#line 1035 "parse-gram.c"
 	break;
       case 75: /* "string_as_id" */
 #line 195 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
-#line 1038 "parse-gram.c"
+#line 1040 "parse-gram.c"
 	break;
       case 76: /* "string_content" */
-#line 181 "parse-gram.y"
+#line 180 "parse-gram.y"
 	{ fprintf (stderr, "\"%s\"", (yyvaluep->chars)); };
-#line 1043 "parse-gram.c"
+#line 1045 "parse-gram.c"
 	break;
       default:
 	break;
@@ -1558,8 +1560,8 @@ YYLTYPE yylloc;
   yylloc.start.line   = yylloc.end.line   = 1;
   yylloc.start.column = yylloc.end.column = 0;
 }
-/* Line 1081 of yacc.c.  */
-#line 1563 "parse-gram.c"
+/* Line 1083 of yacc.c.  */
+#line 1565 "parse-gram.c"
   yylsp[0] = yylloc;
   goto yysetstate;
 
@@ -2144,8 +2146,8 @@ yyreduce:
     break;
 
 
-/* Line 1270 of yacc.c.  */
-#line 2149 "parse-gram.c"
+/* Line 1272 of yacc.c.  */
+#line 2151 "parse-gram.c"
       default: break;
     }
   YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);
