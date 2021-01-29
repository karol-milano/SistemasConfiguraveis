@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 2.0a.  */
+/* A Bison parser, made by GNU Bison 2.0b.  */
 
 /* Skeleton parser for Yacc-like parsing with Bison,
    Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005 Free Software Foundation, Inc.
@@ -217,12 +217,12 @@ static void gram_error (location const *, char const *);
 
 static void add_param (char const *, char *, location);
 
-symbol_class current_class = unknown_sym;
-uniqstr current_type = 0;
+static symbol_class current_class = unknown_sym;
+static uniqstr current_type = 0;
 symbol *current_lhs;
 location current_lhs_location;
 assoc current_assoc;
-int current_prec = 0;
+static int current_prec = 0;
 
 
 /* Enabling traces.  */
@@ -238,6 +238,11 @@ int current_prec = 0;
 # define YYERROR_VERBOSE 1
 #endif
 
+/* Enabling the token table.  */
+#ifndef YYTOKEN_TABLE
+# define YYTOKEN_TABLE 0
+#endif
+
 #if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
 #line 79 "parse-gram.y"
 typedef union YYSTYPE {
@@ -248,8 +253,8 @@ typedef union YYSTYPE {
   assoc assoc;
   uniqstr uniqstr;
 } YYSTYPE;
-/* Line 191 of yacc.c.  */
-#line 253 "parse-gram.c"
+/* Line 196 of yacc.c.  */
+#line 258 "parse-gram.c"
 # define yystype YYSTYPE /* obsolescent; will be withdrawn */
 # define YYSTYPE_IS_DECLARED 1
 # define YYSTYPE_IS_TRIVIAL 1
@@ -272,8 +277,8 @@ typedef struct YYLTYPE
 /* Copy the second part of user declarations.  */
 
 
-/* Line 214 of yacc.c.  */
-#line 277 "parse-gram.c"
+/* Line 219 of yacc.c.  */
+#line 282 "parse-gram.c"
 
 #if ! defined (YYSIZE_T) && defined (__SIZE_TYPE__)
 # define YYSIZE_T __SIZE_TYPE__
@@ -441,7 +446,7 @@ union yyalloc
 #define YYUNDEFTOK  2
 #define YYMAXUTOK   305
 
-#define YYTRANSLATE(YYX) 						\
+#define YYTRANSLATE(YYX)						\
   ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)
 
 /* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
@@ -535,7 +540,7 @@ static const unsigned short int yyrline[] =
 };
 #endif
 
-#if YYDEBUG || YYERROR_VERBOSE
+#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
 /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
    First, the terminals, then, starting at YYNTOKENS, nonterminals. */
 static const char *const yytname[] =
@@ -744,7 +749,7 @@ do								\
       goto yybackup;						\
     }								\
   else								\
-    { 								\
+    {								\
       yyerror (YY_("syntax error: cannot back up")); \
       YYERROR;							\
     }								\
@@ -824,7 +829,7 @@ do {								\
   if (yydebug)							\
     {								\
       YYFPRINTF (stderr, "%s ", Title);				\
-      yysymprint (stderr, 					\
+      yysymprint (stderr,					\
                   Type, Value, Location);	\
       YYFPRINTF (stderr, "\n");					\
     }								\
@@ -1057,92 +1062,92 @@ yysymprint (yyoutput, yytype, yyvaluep, yylocationp)
       case 3: /* "\"string\"" */
 #line 165 "parse-gram.y"
         { fprintf (stderr, "\"%s\"", (yyvaluep->chars)); };
-#line 1061 "parse-gram.c"
+#line 1066 "parse-gram.c"
         break;
       case 4: /* "\"integer\"" */
 #line 178 "parse-gram.y"
         { fprintf (stderr, "%d", (yyvaluep->integer)); };
-#line 1066 "parse-gram.c"
+#line 1071 "parse-gram.c"
         break;
       case 8: /* "\"%destructor {...}\"" */
 #line 167 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1071 "parse-gram.c"
+#line 1076 "parse-gram.c"
         break;
       case 9: /* "\"%printer {...}\"" */
 #line 171 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1076 "parse-gram.c"
+#line 1081 "parse-gram.c"
         break;
       case 10: /* "\"%union {...}\"" */
 #line 172 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1081 "parse-gram.c"
+#line 1086 "parse-gram.c"
         break;
       case 26: /* "\"%initial-action {...}\"" */
 #line 168 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1086 "parse-gram.c"
+#line 1091 "parse-gram.c"
         break;
       case 27: /* "\"%lex-param {...}\"" */
 #line 169 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1091 "parse-gram.c"
+#line 1096 "parse-gram.c"
         break;
       case 34: /* "\"%parse-param {...}\"" */
 #line 170 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1096 "parse-gram.c"
+#line 1101 "parse-gram.c"
         break;
       case 41: /* "\"type\"" */
 #line 176 "parse-gram.y"
         { fprintf (stderr, "<%s>", (yyvaluep->uniqstr)); };
-#line 1101 "parse-gram.c"
+#line 1106 "parse-gram.c"
         break;
       case 45: /* "\"identifier\"" */
 #line 180 "parse-gram.y"
         { fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
-#line 1106 "parse-gram.c"
+#line 1111 "parse-gram.c"
         break;
       case 46: /* "\"identifier:\"" */
 #line 182 "parse-gram.y"
         { fprintf (stderr, "%s:", (yyvaluep->symbol)->tag); };
-#line 1111 "parse-gram.c"
+#line 1116 "parse-gram.c"
         break;
       case 48: /* "\"%{...%}\"" */
 #line 174 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1116 "parse-gram.c"
+#line 1121 "parse-gram.c"
         break;
       case 49: /* "\"epilogue\"" */
 #line 174 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1121 "parse-gram.c"
+#line 1126 "parse-gram.c"
         break;
       case 50: /* "\"{...}\"" */
 #line 173 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1126 "parse-gram.c"
+#line 1131 "parse-gram.c"
         break;
       case 71: /* "symbol" */
 #line 180 "parse-gram.y"
         { fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
-#line 1131 "parse-gram.c"
+#line 1136 "parse-gram.c"
         break;
       case 72: /* "action" */
 #line 173 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1136 "parse-gram.c"
+#line 1141 "parse-gram.c"
         break;
       case 73: /* "string_as_id" */
 #line 180 "parse-gram.y"
         { fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
-#line 1141 "parse-gram.c"
+#line 1146 "parse-gram.c"
         break;
       case 74: /* "string_content" */
 #line 165 "parse-gram.y"
         { fprintf (stderr, "\"%s\"", (yyvaluep->chars)); };
-#line 1146 "parse-gram.c"
+#line 1151 "parse-gram.c"
         break;
       default:
         break;
@@ -1223,7 +1228,7 @@ yyparse (void)
 #else
 int
 yyparse ()
-
+    ;
 #endif
 #endif
 {
@@ -1315,8 +1320,8 @@ YYLTYPE yylloc;
   yylloc.start.line   = yylloc.end.line   = 1;
   yylloc.start.column = yylloc.end.column = 0;
 }
-/* Line 925 of yacc.c.  */
-#line 1320 "parse-gram.c"
+/* Line 930 of yacc.c.  */
+#line 1325 "parse-gram.c"
   yylsp[0] = yylloc;
   goto yysetstate;
 
@@ -1898,8 +1903,8 @@ yyreduce:
       default: break;
     }
 
-/* Line 1121 of yacc.c.  */
-#line 1903 "parse-gram.c"
+/* Line 1126 of yacc.c.  */
+#line 1908 "parse-gram.c"
 
   yyvsp -= yylen;
   yyssp -= yylen;
