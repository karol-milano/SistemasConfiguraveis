@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 2.0c.  */
+/* A Bison parser, made by GNU Bison 2.1.  */
 
 /* Skeleton parser for Yacc-like parsing with Bison,
    Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005 Free Software Foundation, Inc.
@@ -36,6 +36,9 @@
 /* Identify Bison output.  */
 #define YYBISON 1
 
+/* Bison version.  */
+#define YYBISON_VERSION "2.1"
+
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
 
@@ -112,6 +115,7 @@
      BRACED_CODE = 305
    };
 #endif
+/* Tokens.  */
 #define GRAM_EOF 0
 #define STRING 258
 #define INT 259
@@ -254,7 +258,7 @@ typedef union YYSTYPE {
   uniqstr uniqstr;
 } YYSTYPE;
 /* Line 196 of yacc.c.  */
-#line 258 "parse-gram.c"
+#line 262 "parse-gram.c"
 # define yystype YYSTYPE /* obsolescent; will be withdrawn */
 # define YYSTYPE_IS_DECLARED 1
 # define YYSTYPE_IS_TRIVIAL 1
@@ -278,7 +282,7 @@ typedef struct YYLTYPE
 
 
 /* Line 219 of yacc.c.  */
-#line 282 "parse-gram.c"
+#line 286 "parse-gram.c"
 
 #if ! defined (YYSIZE_T) && defined (__SIZE_TYPE__)
 # define YYSIZE_T __SIZE_TYPE__
@@ -1062,92 +1066,92 @@ yysymprint (yyoutput, yytype, yyvaluep, yylocationp)
       case 3: /* "\"string\"" */
 #line 165 "parse-gram.y"
         { fprintf (stderr, "\"%s\"", (yyvaluep->chars)); };
-#line 1066 "parse-gram.c"
+#line 1070 "parse-gram.c"
         break;
       case 4: /* "\"integer\"" */
 #line 178 "parse-gram.y"
         { fprintf (stderr, "%d", (yyvaluep->integer)); };
-#line 1071 "parse-gram.c"
+#line 1075 "parse-gram.c"
         break;
       case 8: /* "\"%destructor {...}\"" */
 #line 167 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1076 "parse-gram.c"
+#line 1080 "parse-gram.c"
         break;
       case 9: /* "\"%printer {...}\"" */
 #line 171 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1081 "parse-gram.c"
+#line 1085 "parse-gram.c"
         break;
       case 10: /* "\"%union {...}\"" */
 #line 172 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1086 "parse-gram.c"
+#line 1090 "parse-gram.c"
         break;
       case 26: /* "\"%initial-action {...}\"" */
 #line 168 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1091 "parse-gram.c"
+#line 1095 "parse-gram.c"
         break;
       case 27: /* "\"%lex-param {...}\"" */
 #line 169 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1096 "parse-gram.c"
+#line 1100 "parse-gram.c"
         break;
       case 34: /* "\"%parse-param {...}\"" */
 #line 170 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1101 "parse-gram.c"
+#line 1105 "parse-gram.c"
         break;
       case 41: /* "\"type\"" */
 #line 176 "parse-gram.y"
         { fprintf (stderr, "<%s>", (yyvaluep->uniqstr)); };
-#line 1106 "parse-gram.c"
+#line 1110 "parse-gram.c"
         break;
       case 45: /* "\"identifier\"" */
 #line 180 "parse-gram.y"
         { fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
-#line 1111 "parse-gram.c"
+#line 1115 "parse-gram.c"
         break;
       case 46: /* "\"identifier:\"" */
 #line 182 "parse-gram.y"
         { fprintf (stderr, "%s:", (yyvaluep->symbol)->tag); };
-#line 1116 "parse-gram.c"
+#line 1120 "parse-gram.c"
         break;
       case 48: /* "\"%{...%}\"" */
 #line 174 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1121 "parse-gram.c"
+#line 1125 "parse-gram.c"
         break;
       case 49: /* "\"epilogue\"" */
 #line 174 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1126 "parse-gram.c"
+#line 1130 "parse-gram.c"
         break;
       case 50: /* "\"{...}\"" */
 #line 173 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1131 "parse-gram.c"
+#line 1135 "parse-gram.c"
         break;
       case 71: /* "symbol" */
 #line 180 "parse-gram.y"
         { fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
-#line 1136 "parse-gram.c"
+#line 1140 "parse-gram.c"
         break;
       case 72: /* "action" */
 #line 173 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1141 "parse-gram.c"
+#line 1145 "parse-gram.c"
         break;
       case 73: /* "string_as_id" */
 #line 180 "parse-gram.y"
         { fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
-#line 1146 "parse-gram.c"
+#line 1150 "parse-gram.c"
         break;
       case 74: /* "string_content" */
 #line 165 "parse-gram.y"
         { fprintf (stderr, "\"%s\"", (yyvaluep->chars)); };
-#line 1151 "parse-gram.c"
+#line 1155 "parse-gram.c"
         break;
       default:
         break;
@@ -1321,7 +1325,7 @@ YYLTYPE yylloc;
   yylloc.start.column = yylloc.end.column = 0;
 }
 /* Line 930 of yacc.c.  */
-#line 1325 "parse-gram.c"
+#line 1329 "parse-gram.c"
   yylsp[0] = yylloc;
   goto yysetstate;
 
@@ -1904,7 +1908,7 @@ yyreduce:
     }
 
 /* Line 1126 of yacc.c.  */
-#line 1908 "parse-gram.c"
+#line 1912 "parse-gram.c"
 
   yyvsp -= yylen;
   yyssp -= yylen;
