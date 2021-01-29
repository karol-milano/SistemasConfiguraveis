@@ -89,26 +89,27 @@
      PERCENT_LEX_PARAM = 281,
      PERCENT_LOCATIONS = 282,
      PERCENT_NAME_PREFIX = 283,
-     PERCENT_NO_LINES = 284,
-     PERCENT_NONDETERMINISTIC_PARSER = 285,
-     PERCENT_OUTPUT = 286,
-     PERCENT_PARSE_PARAM = 287,
-     PERCENT_PURE_PARSER = 288,
-     PERCENT_SKELETON = 289,
-     PERCENT_START = 290,
-     PERCENT_TOKEN_TABLE = 291,
-     PERCENT_VERBOSE = 292,
-     PERCENT_YACC = 293,
-     TYPE = 294,
-     EQUAL = 295,
-     SEMICOLON = 296,
-     PIPE = 297,
-     ID = 298,
-     ID_COLON = 299,
-     PERCENT_PERCENT = 300,
-     PROLOGUE = 301,
-     EPILOGUE = 302,
-     BRACED_CODE = 303
+     PERCENT_NO_DEFAULT_PREC = 284,
+     PERCENT_NO_LINES = 285,
+     PERCENT_NONDETERMINISTIC_PARSER = 286,
+     PERCENT_OUTPUT = 287,
+     PERCENT_PARSE_PARAM = 288,
+     PERCENT_PURE_PARSER = 289,
+     PERCENT_SKELETON = 290,
+     PERCENT_START = 291,
+     PERCENT_TOKEN_TABLE = 292,
+     PERCENT_VERBOSE = 293,
+     PERCENT_YACC = 294,
+     TYPE = 295,
+     EQUAL = 296,
+     SEMICOLON = 297,
+     PIPE = 298,
+     ID = 299,
+     ID_COLON = 300,
+     PERCENT_PERCENT = 301,
+     PROLOGUE = 302,
+     EPILOGUE = 303,
+     BRACED_CODE = 304
    };
 #endif
 #define GRAM_EOF 0
@@ -138,26 +139,27 @@
 #define PERCENT_LEX_PARAM 281
 #define PERCENT_LOCATIONS 282
 #define PERCENT_NAME_PREFIX 283
-#define PERCENT_NO_LINES 284
-#define PERCENT_NONDETERMINISTIC_PARSER 285
-#define PERCENT_OUTPUT 286
-#define PERCENT_PARSE_PARAM 287
-#define PERCENT_PURE_PARSER 288
-#define PERCENT_SKELETON 289
-#define PERCENT_START 290
-#define PERCENT_TOKEN_TABLE 291
-#define PERCENT_VERBOSE 292
-#define PERCENT_YACC 293
-#define TYPE 294
-#define EQUAL 295
-#define SEMICOLON 296
-#define PIPE 297
-#define ID 298
-#define ID_COLON 299
-#define PERCENT_PERCENT 300
-#define PROLOGUE 301
-#define EPILOGUE 302
-#define BRACED_CODE 303
+#define PERCENT_NO_DEFAULT_PREC 284
+#define PERCENT_NO_LINES 285
+#define PERCENT_NONDETERMINISTIC_PARSER 286
+#define PERCENT_OUTPUT 287
+#define PERCENT_PARSE_PARAM 288
+#define PERCENT_PURE_PARSER 289
+#define PERCENT_SKELETON 290
+#define PERCENT_START 291
+#define PERCENT_TOKEN_TABLE 292
+#define PERCENT_VERBOSE 293
+#define PERCENT_YACC 294
+#define TYPE 295
+#define EQUAL 296
+#define SEMICOLON 297
+#define PIPE 298
+#define ID 299
+#define ID_COLON 300
+#define PERCENT_PERCENT 301
+#define PROLOGUE 302
+#define EPILOGUE 303
+#define BRACED_CODE 304
 
 
 
@@ -225,7 +227,7 @@ typedef union YYSTYPE {
   uniqstr uniqstr;
 } YYSTYPE;
 /* Line 191 of yacc.c.  */
-#line 229 "parse-gram.c"
+#line 231 "parse-gram.c"
 # define yystype YYSTYPE /* obsolescent; will be withdrawn */
 # define YYSTYPE_IS_DECLARED 1
 # define YYSTYPE_IS_TRIVIAL 1
@@ -249,7 +251,7 @@ typedef struct YYLTYPE
 
 
 /* Line 214 of yacc.c.  */
-#line 253 "parse-gram.c"
+#line 255 "parse-gram.c"
 
 #if ! defined (yyoverflow) || YYERROR_VERBOSE
 
@@ -357,20 +359,20 @@ union yyalloc
 /* YYFINAL -- State number of the termination state. */
 #define YYFINAL  3
 /* YYLAST -- Last index in YYTABLE.  */
-#define YYLAST   153
+#define YYLAST   156
 
 /* YYNTOKENS -- Number of terminals. */
-#define YYNTOKENS  49
+#define YYNTOKENS  50
 /* YYNNTS -- Number of nonterminals. */
 #define YYNNTS  25
 /* YYNRULES -- Number of rules. */
-#define YYNRULES  77
+#define YYNRULES  78
 /* YYNRULES -- Number of states. */
 #define YYNSTATES  106
 
 /* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
 #define YYUNDEFTOK  2
-#define YYMAXUTOK   303
+#define YYMAXUTOK   304
 
 #define YYTRANSLATE(YYX) 						\
   ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)
@@ -408,7 +410,7 @@ static const unsigned char yytranslate[] =
       15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
       25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
       35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
-      45,    46,    47,    48
+      45,    46,    47,    48,    49
 };
 
 #if YYDEBUG
@@ -419,49 +421,49 @@ static const unsigned char yyprhs[] =
        0,     0,     3,     8,     9,    12,    14,    16,    18,    22,
       24,    26,    29,    33,    35,    37,    39,    41,    45,    47,
       49,    53,    55,    57,    60,    62,    64,    66,    68,    70,
-      72,    75,    77,    80,    83,    86,    87,    91,    92,    96,
-     100,   104,   106,   108,   110,   111,   113,   115,   118,   120,
-     122,   125,   128,   132,   134,   137,   139,   142,   144,   147,
-     150,   151,   155,   157,   161,   164,   165,   168,   171,   175,
-     179,   183,   185,   187,   189,   191,   193,   194
+      72,    75,    77,    80,    83,    85,    87,    88,    92,    93,
+      97,   101,   105,   107,   109,   111,   112,   114,   116,   119,
+     121,   123,   126,   129,   133,   135,   138,   140,   143,   145,
+     148,   151,   152,   156,   158,   162,   165,   166,   169,   172,
+     176,   180,   184,   186,   188,   190,   192,   194,   195
 };
 
 /* YYRHS -- A `-1'-separated list of the rules' RHS. */
 static const yysigned_char yyrhs[] =
 {
-      50,     0,    -1,    51,    45,    63,    73,    -1,    -1,    51,
-      52,    -1,    53,    -1,    46,    -1,    17,    -1,    19,    72,
-      72,    -1,    20,    -1,    21,    -1,    22,     4,    -1,    23,
-      40,    72,    -1,    24,    -1,    25,    -1,    26,    -1,    27,
-      -1,    28,    40,    72,    -1,    29,    -1,    30,    -1,    31,
-      40,    72,    -1,    32,    -1,    33,    -1,    34,    72,    -1,
-      36,    -1,    37,    -1,    38,    -1,    41,    -1,    57,    -1,
-      54,    -1,    35,    69,    -1,    10,    -1,     8,    60,    -1,
-       9,    60,    -1,    18,     4,    -1,    -1,     6,    55,    62,
-      -1,    -1,     5,    56,    62,    -1,     7,    39,    60,    -1,
-      58,    59,    60,    -1,    11,    -1,    12,    -1,    13,    -1,
-      -1,    39,    -1,    69,    -1,    60,    69,    -1,    39,    -1,
-      43,    -1,    43,     4,    -1,    43,    71,    -1,    43,     4,
-      71,    -1,    61,    -1,    62,    61,    -1,    64,    -1,    63,
-      64,    -1,    65,    -1,    53,    41,    -1,     1,    41,    -1,
-      -1,    44,    66,    67,    -1,    68,    -1,    67,    42,    68,
-      -1,    67,    41,    -1,    -1,    68,    69,    -1,    68,    70,
-      -1,    68,    14,    69,    -1,    68,    15,     4,    -1,    68,
-      16,    39,    -1,    43,    -1,    71,    -1,    48,    -1,     3,
-      -1,     3,    -1,    -1,    45,    47,    -1
+      51,     0,    -1,    52,    46,    64,    74,    -1,    -1,    52,
+      53,    -1,    54,    -1,    47,    -1,    17,    -1,    19,    73,
+      73,    -1,    20,    -1,    21,    -1,    22,     4,    -1,    23,
+      41,    73,    -1,    24,    -1,    25,    -1,    26,    -1,    27,
+      -1,    28,    41,    73,    -1,    30,    -1,    31,    -1,    32,
+      41,    73,    -1,    33,    -1,    34,    -1,    35,    73,    -1,
+      37,    -1,    38,    -1,    39,    -1,    42,    -1,    58,    -1,
+      55,    -1,    36,    70,    -1,    10,    -1,     8,    61,    -1,
+       9,    61,    -1,    18,    -1,    29,    -1,    -1,     6,    56,
+      63,    -1,    -1,     5,    57,    63,    -1,     7,    40,    61,
+      -1,    59,    60,    61,    -1,    11,    -1,    12,    -1,    13,
+      -1,    -1,    40,    -1,    70,    -1,    61,    70,    -1,    40,
+      -1,    44,    -1,    44,     4,    -1,    44,    72,    -1,    44,
+       4,    72,    -1,    62,    -1,    63,    62,    -1,    65,    -1,
+      64,    65,    -1,    66,    -1,    54,    42,    -1,     1,    42,
+      -1,    -1,    45,    67,    68,    -1,    69,    -1,    68,    43,
+      69,    -1,    68,    42,    -1,    -1,    69,    70,    -1,    69,
+      71,    -1,    69,    14,    70,    -1,    69,    15,     4,    -1,
+      69,    16,    40,    -1,    44,    -1,    72,    -1,    49,    -1,
+       3,    -1,     3,    -1,    -1,    46,    48,    -1
 };
 
 /* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
 static const unsigned short yyrline[] =
 {
-       0,   171,   171,   179,   181,   185,   186,   187,   188,   189,
-     190,   191,   192,   193,   198,   202,   203,   204,   205,   206,
-     207,   208,   209,   210,   211,   212,   213,   214,   218,   219,
-     220,   224,   230,   237,   244,   254,   254,   259,   259,   264,
-     274,   289,   290,   291,   295,   296,   302,   303,   308,   312,
-     317,   323,   329,   340,   341,   350,   351,   357,   358,   363,
-     370,   370,   374,   375,   376,   381,   382,   384,   386,   388,
-     390,   395,   396,   400,   406,   415,   422,   424
+       0,   172,   172,   180,   182,   186,   187,   188,   189,   190,
+     191,   192,   193,   194,   199,   203,   204,   205,   206,   207,
+     208,   209,   210,   211,   212,   213,   214,   215,   219,   220,
+     221,   225,   231,   238,   245,   249,   256,   256,   261,   261,
+     266,   276,   291,   292,   293,   297,   298,   304,   305,   310,
+     314,   319,   325,   331,   342,   343,   352,   353,   359,   360,
+     365,   372,   372,   376,   377,   378,   383,   384,   386,   388,
+     390,   392,   397,   398,   402,   408,   417,   424,   426
 };
 #endif
 
@@ -477,17 +479,17 @@ static const char *const yytname[] =
   "\"%default-prec\"", "\"%define\"", "\"%defines\"", "\"%error-verbose\"",
   "\"%expect\"", "\"%file-prefix\"", "\"%glr-parser\"",
   "\"%initial-action {...}\"", "\"%lex-param {...}\"", "\"%locations\"",
-  "\"%name-prefix\"", "\"%no-lines\"", "\"%nondeterministic-parser\"",
-  "\"%output\"", "\"%parse-param {...}\"", "\"%pure-parser\"",
-  "\"%skeleton\"", "\"%start\"", "\"%token-table\"", "\"%verbose\"",
-  "\"%yacc\"", "\"type\"", "\"=\"", "\";\"", "\"|\"", "\"identifier\"",
-  "\"identifier:\"", "\"%%\"", "\"%{...%}\"", "\"epilogue\"", "\"{...}\"",
-  "$accept", "input", "declarations", "declaration", "grammar_declaration",
-  "symbol_declaration", "@1", "@2", "precedence_declaration",
-  "precedence_declarator", "type.opt", "symbols.1", "symbol_def",
-  "symbol_defs.1", "grammar", "rules_or_grammar_declaration", "rules",
-  "@3", "rhses.1", "rhs", "symbol", "action", "string_as_id",
-  "string_content", "epilogue.opt", 0
+  "\"%name-prefix\"", "\"%no-default-prec\"", "\"%no-lines\"",
+  "\"%nondeterministic-parser\"", "\"%output\"", "\"%parse-param {...}\"",
+  "\"%pure-parser\"", "\"%skeleton\"", "\"%start\"", "\"%token-table\"",
+  "\"%verbose\"", "\"%yacc\"", "\"type\"", "\"=\"", "\";\"", "\"|\"",
+  "\"identifier\"", "\"identifier:\"", "\"%%\"", "\"%{...%}\"",
+  "\"epilogue\"", "\"{...}\"", "$accept", "input", "declarations",
+  "declaration", "grammar_declaration", "symbol_declaration", "@1", "@2",
+  "precedence_declaration", "precedence_declarator", "type.opt",
+  "symbols.1", "symbol_def", "symbol_defs.1", "grammar",
+  "rules_or_grammar_declaration", "rules", "@3", "rhses.1", "rhs",
+  "symbol", "action", "string_as_id", "string_content", "epilogue.opt", 0
 };
 #endif
 
@@ -500,21 +502,21 @@ static const unsigned short yytoknum[] =
      265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
      275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
      285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
-     295,   296,   297,   298,   299,   300,   301,   302,   303
+     295,   296,   297,   298,   299,   300,   301,   302,   303,   304
 };
 # endif
 
 /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
 static const unsigned char yyr1[] =
 {
-       0,    49,    50,    51,    51,    52,    52,    52,    52,    52,
-      52,    52,    52,    52,    52,    52,    52,    52,    52,    52,
-      52,    52,    52,    52,    52,    52,    52,    52,    53,    53,
-      53,    53,    53,    53,    53,    55,    54,    56,    54,    54,
-      57,    58,    58,    58,    59,    59,    60,    60,    61,    61,
-      61,    61,    61,    62,    62,    63,    63,    64,    64,    64,
-      66,    65,    67,    67,    67,    68,    68,    68,    68,    68,
-      68,    69,    69,    70,    71,    72,    73,    73
+       0,    50,    51,    52,    52,    53,    53,    53,    53,    53,
+      53,    53,    53,    53,    53,    53,    53,    53,    53,    53,
+      53,    53,    53,    53,    53,    53,    53,    53,    54,    54,
+      54,    54,    54,    54,    54,    54,    56,    55,    57,    55,
+      55,    58,    59,    59,    59,    60,    60,    61,    61,    62,
+      62,    62,    62,    62,    63,    63,    64,    64,    65,    65,
+      65,    67,    66,    68,    68,    68,    69,    69,    69,    69,
+      69,    69,    70,    70,    71,    72,    73,    74,    74
 };
 
 /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
@@ -523,11 +525,11 @@ static const unsigned char yyr2[] =
        0,     2,     4,     0,     2,     1,     1,     1,     3,     1,
        1,     2,     3,     1,     1,     1,     1,     3,     1,     1,
        3,     1,     1,     2,     1,     1,     1,     1,     1,     1,
-       2,     1,     2,     2,     2,     0,     3,     0,     3,     3,
-       3,     1,     1,     1,     0,     1,     1,     2,     1,     1,
-       2,     2,     3,     1,     2,     1,     2,     1,     2,     2,
-       0,     3,     1,     3,     2,     0,     2,     2,     3,     3,
-       3,     1,     1,     1,     1,     1,     0,     2
+       2,     1,     2,     2,     1,     1,     0,     3,     0,     3,
+       3,     3,     1,     1,     1,     0,     1,     1,     2,     1,
+       1,     2,     2,     3,     1,     2,     1,     2,     1,     2,
+       2,     0,     3,     1,     3,     2,     0,     2,     2,     3,
+       3,     3,     1,     1,     1,     1,     1,     0,     2
 };
 
 /* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
@@ -535,113 +537,113 @@ static const unsigned char yyr2[] =
    means the default is an error.  */
 static const unsigned char yydefact[] =
 {
-       3,     0,     0,     1,    37,    35,     0,     0,     0,    31,
-      41,    42,    43,     7,     0,     0,     9,    10,     0,     0,
-      13,    14,    15,    16,     0,    18,    19,     0,    21,    22,
-       0,     0,    24,    25,    26,    27,     0,     6,     4,     5,
-      29,    28,    44,     0,     0,     0,    74,    71,    32,    46,
-      72,    33,    34,    75,     0,    11,     0,     0,     0,    23,
-      30,     0,    60,     0,     0,    55,    57,    45,     0,    48,
-      49,    53,    38,    36,    39,    47,     8,    12,    17,    20,
-      59,    65,    58,     0,    56,     2,    40,    50,    51,    54,
-      61,    62,    77,    52,    64,    65,     0,     0,     0,    73,
-      66,    67,    63,    68,    69,    70
+       3,     0,     0,     1,    38,    36,     0,     0,     0,    31,
+      42,    43,    44,     7,    34,     0,     9,    10,     0,     0,
+      13,    14,    15,    16,     0,    35,    18,    19,     0,    21,
+      22,     0,     0,    24,    25,    26,    27,     0,     6,     4,
+       5,    29,    28,    45,     0,     0,     0,    75,    72,    32,
+      47,    73,    33,    76,     0,    11,     0,     0,     0,    23,
+      30,     0,    61,     0,     0,    56,    58,    46,     0,    49,
+      50,    54,    39,    37,    40,    48,     8,    12,    17,    20,
+      60,    66,    59,     0,    57,     2,    41,    51,    52,    55,
+      62,    63,    78,    53,    65,    66,     0,     0,     0,    74,
+      67,    68,    64,    69,    70,    71
 };
 
 /* YYDEFGOTO[NTERM-NUM]. */
 static const yysigned_char yydefgoto[] =
 {
-      -1,     1,     2,    38,    63,    40,    44,    43,    41,    42,
-      68,    48,    71,    72,    64,    65,    66,    81,    90,    91,
-      49,   101,    50,    54,    85
+      -1,     1,     2,    39,    63,    41,    45,    44,    42,    43,
+      68,    49,    71,    72,    64,    65,    66,    81,    90,    91,
+      50,   101,    51,    54,    85
 };
 
 /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
    STATE-NUM.  */
-#define YYPACT_NINF -63
+#define YYPACT_NINF -67
 static const yysigned_char yypact[] =
 {
-     -63,    12,   107,   -63,   -63,   -63,   -18,     1,     1,   -63,
-     -63,   -63,   -63,   -63,    28,    31,   -63,   -63,    33,    -5,
-     -63,   -63,   -63,   -63,     0,   -63,   -63,     5,   -63,   -63,
-      31,     1,   -63,   -63,   -63,   -63,    67,   -63,   -63,   -63,
-     -63,   -63,    13,   -36,   -36,     1,   -63,   -63,     1,   -63,
-     -63,     1,   -63,   -63,    31,   -63,    31,    31,    31,   -63,
-     -63,    -2,   -63,    10,    18,   -63,   -63,   -63,     1,   -63,
-       2,   -63,   -36,   -36,     1,   -63,   -63,   -63,   -63,   -63,
-     -63,   -63,   -63,    -6,   -63,   -63,     1,    51,   -63,   -63,
-     -33,    -1,   -63,   -63,   -63,   -63,     1,    52,    19,   -63,
-     -63,   -63,    -1,   -63,   -63,   -63
+     -67,     8,   109,   -67,   -67,   -67,   -30,     0,     0,   -67,
+     -67,   -67,   -67,   -67,   -67,    13,   -67,   -67,    20,   -16,
+     -67,   -67,   -67,   -67,   -15,   -67,   -67,   -67,    -5,   -67,
+     -67,    13,     0,   -67,   -67,   -67,   -67,    68,   -67,   -67,
+     -67,   -67,   -67,    -3,   -35,   -35,     0,   -67,   -67,     0,
+     -67,   -67,     0,   -67,    13,   -67,    13,    13,    13,   -67,
+     -67,    -4,   -67,     4,    22,   -67,   -67,   -67,     0,   -67,
+       3,   -67,   -35,   -35,     0,   -67,   -67,   -67,   -67,   -67,
+     -67,   -67,   -67,     1,   -67,   -67,     0,    38,   -67,   -67,
+     -31,    -1,   -67,   -67,   -67,   -67,     0,    41,     7,   -67,
+     -67,   -67,    -1,   -67,   -67,   -67
 };
 
 /* YYPGOTO[NTERM-NUM].  */
 static const yysigned_char yypgoto[] =
 {
-     -63,   -63,   -63,   -63,    55,   -63,   -63,   -63,   -63,   -63,
-     -63,    -7,   -62,    15,   -63,     3,   -63,   -63,   -63,   -29,
-     -31,   -63,   -54,    -8,   -63
+     -67,   -67,   -67,   -67,    48,   -67,   -67,   -67,   -67,   -67,
+     -67,    -7,   -54,    10,   -67,   -12,   -67,   -67,   -67,   -42,
+     -32,   -67,   -66,    31,   -67
 };
 
 /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
    positive, shift that token.  If negative, reduce the rule which
    number is the opposite.  If zero, do what YYDEFACT says.
    If YYTABLE_NINF, syntax error.  */
-#define YYTABLE_NINF -77
+#define YYTABLE_NINF -78
 static const yysigned_char yytable[] =
 {
-      60,    51,    46,    69,    46,    46,    87,    70,    94,    95,
-      89,    89,     3,    96,    97,    98,    88,    75,   -76,    61,
-      75,    45,    59,     4,     5,     6,     7,     8,     9,    10,
-      11,    12,    52,    93,    53,    56,    14,    55,    74,    80,
-      57,    92,    47,    75,    47,    58,    76,    99,    77,    78,
-      79,    82,    67,    31,    46,    75,   104,    39,   105,    73,
-     100,    86,    62,    83,     0,   103,   102,    84,    61,     0,
-       0,   100,     4,     5,     6,     7,     8,     9,    10,    11,
-      12,     0,     0,     0,     0,    14,     0,     0,     0,     0,
-       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
-       0,     0,    31,     0,     0,     0,     0,     0,     0,     0,
-       0,    62,     4,     5,     6,     7,     8,     9,    10,    11,
-      12,     0,     0,     0,    13,    14,    15,    16,    17,    18,
-      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
-      29,    30,    31,    32,    33,    34,     0,     0,    35,     0,
-       0,     0,    36,    37
+      60,    52,    47,    47,    88,    69,    47,    87,     3,    70,
+      46,    94,    95,    96,    97,    98,    53,    75,    89,    89,
+      75,    93,   -77,    61,    55,    56,    57,     4,     5,     6,
+       7,     8,     9,    10,    11,    12,    58,    67,    80,    74,
+      14,    47,    75,    48,    48,   104,    82,   105,    99,    92,
+      40,    25,    84,   102,    75,    73,     0,     0,    32,   100,
+       0,    86,    59,     0,   103,     0,     0,    62,    83,    61,
+     100,     0,     0,     4,     5,     6,     7,     8,     9,    10,
+      11,    12,     0,     0,     0,    76,    14,    77,    78,    79,
+       0,     0,     0,     0,     0,     0,     0,    25,     0,     0,
+       0,     0,     0,     0,    32,     0,     0,     0,     0,     0,
+       0,     0,     0,    62,     4,     5,     6,     7,     8,     9,
+      10,    11,    12,     0,     0,     0,    13,    14,    15,    16,
+      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
+      27,    28,    29,    30,    31,    32,    33,    34,    35,     0,
+       0,    36,     0,     0,     0,    37,    38
 };
 
 static const yysigned_char yycheck[] =
 {
-      31,     8,     3,    39,     3,     3,     4,    43,    41,    42,
-      72,    73,     0,    14,    15,    16,    70,    48,     0,     1,
-      51,    39,    30,     5,     6,     7,     8,     9,    10,    11,
-      12,    13,     4,    87,     3,    40,    18,     4,    45,    41,
-      40,    47,    43,    74,    43,    40,    54,    48,    56,    57,
-      58,    41,    39,    35,     3,    86,     4,     2,    39,    44,
-      91,    68,    44,    45,    -1,    96,    95,    64,     1,    -1,
-      -1,   102,     5,     6,     7,     8,     9,    10,    11,    12,
-      13,    -1,    -1,    -1,    -1,    18,    -1,    -1,    -1,    -1,
-      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
-      -1,    -1,    35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
-      -1,    44,     5,     6,     7,     8,     9,    10,    11,    12,
-      13,    -1,    -1,    -1,    17,    18,    19,    20,    21,    22,
-      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
-      33,    34,    35,    36,    37,    38,    -1,    -1,    41,    -1,
-      -1,    -1,    45,    46
+      32,     8,     3,     3,    70,    40,     3,     4,     0,    44,
+      40,    42,    43,    14,    15,    16,     3,    49,    72,    73,
+      52,    87,     0,     1,     4,    41,    41,     5,     6,     7,
+       8,     9,    10,    11,    12,    13,    41,    40,    42,    46,
+      18,     3,    74,    44,    44,     4,    42,    40,    49,    48,
+       2,    29,    64,    95,    86,    45,    -1,    -1,    36,    91,
+      -1,    68,    31,    -1,    96,    -1,    -1,    45,    46,     1,
+     102,    -1,    -1,     5,     6,     7,     8,     9,    10,    11,
+      12,    13,    -1,    -1,    -1,    54,    18,    56,    57,    58,
+      -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,    -1,    -1,
+      -1,    -1,    -1,    -1,    36,    -1,    -1,    -1,    -1,    -1,
+      -1,    -1,    -1,    45,     5,     6,     7,     8,     9,    10,
+      11,    12,    13,    -1,    -1,    -1,    17,    18,    19,    20,
+      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
+      31,    32,    33,    34,    35,    36,    37,    38,    39,    -1,
+      -1,    42,    -1,    -1,    -1,    46,    47
 };
 
 /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
    symbol of state STATE-NUM.  */
 static const unsigned char yystos[] =
 {
-       0,    50,    51,     0,     5,     6,     7,     8,     9,    10,
+       0,    51,    52,     0,     5,     6,     7,     8,     9,    10,
       11,    12,    13,    17,    18,    19,    20,    21,    22,    23,
       24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
-      34,    35,    36,    37,    38,    41,    45,    46,    52,    53,
-      54,    57,    58,    56,    55,    39,     3,    43,    60,    69,
-      71,    60,     4,     3,    72,     4,    40,    40,    40,    72,
-      69,     1,    44,    53,    63,    64,    65,    39,    59,    39,
-      43,    61,    62,    62,    60,    69,    72,    72,    72,    72,
-      41,    66,    41,    45,    64,    73,    60,     4,    71,    61,
-      67,    68,    47,    71,    41,    42,    14,    15,    16,    48,
-      69,    70,    68,    69,     4,    39
+      34,    35,    36,    37,    38,    39,    42,    46,    47,    53,
+      54,    55,    58,    59,    57,    56,    40,     3,    44,    61,
+      70,    72,    61,     3,    73,     4,    41,    41,    41,    73,
+      70,     1,    45,    54,    64,    65,    66,    40,    60,    40,
+      44,    62,    63,    63,    61,    70,    73,    73,    73,    73,
+      42,    67,    42,    46,    65,    74,    61,     4,    72,    62,
+      68,    69,    48,    72,    42,    43,    14,    15,    16,    49,
+      70,    71,    69,    70,     4,    40
 };
 
 #if ! defined (YYSIZE_T) && defined (__SIZE_TYPE__)
@@ -1087,7 +1089,7 @@ YYLTYPE yylloc;
   (*yylsp).start.column = (*yylsp).end.column = 0;
 }
 /* Line 818 of yacc.c.  */
-#line 1091 "parse-gram.c"
+#line 1093 "parse-gram.c"
   goto yysetstate;
 
 /*------------------------------------------------------------.
@@ -1275,42 +1277,42 @@ yyreduce:
   switch (yyn)
     {
         case 6:
-#line 186 "parse-gram.y"
+#line 187 "parse-gram.y"
     { prologue_augment (yyvsp[0].chars, yylsp[0]); }
     break;
 
   case 7:
-#line 187 "parse-gram.y"
+#line 188 "parse-gram.y"
     { debug_flag = true; }
     break;
 
   case 8:
-#line 188 "parse-gram.y"
+#line 189 "parse-gram.y"
     { muscle_insert (yyvsp[-1].chars, yyvsp[0].chars); }
     break;
 
   case 9:
-#line 189 "parse-gram.y"
+#line 190 "parse-gram.y"
     { defines_flag = true; }
     break;
 
   case 10:
-#line 190 "parse-gram.y"
+#line 191 "parse-gram.y"
     { error_verbose = true; }
     break;
 
   case 11:
-#line 191 "parse-gram.y"
+#line 192 "parse-gram.y"
     { expected_conflicts = yyvsp[0].integer; }
     break;
 
   case 12:
-#line 192 "parse-gram.y"
+#line 193 "parse-gram.y"
     { spec_file_prefix = yyvsp[0].chars; }
     break;
 
   case 13:
-#line 194 "parse-gram.y"
+#line 195 "parse-gram.y"
     {
     nondeterministic_parser = true;
     glr_parser = true;
@@ -1318,81 +1320,81 @@ yyreduce:
     break;
 
   case 14:
-#line 199 "parse-gram.y"
+#line 200 "parse-gram.y"
     {
     muscle_code_grow ("initial_action", yyvsp[0].chars, yylsp[0]);
   }
     break;
 
   case 15:
-#line 202 "parse-gram.y"
+#line 203 "parse-gram.y"
     { add_param ("lex_param", yyvsp[0].chars, yylsp[0]); }
     break;
 
   case 16:
-#line 203 "parse-gram.y"
+#line 204 "parse-gram.y"
     { locations_flag = true; }
     break;
 
   case 17:
-#line 204 "parse-gram.y"
+#line 205 "parse-gram.y"
     { spec_name_prefix = yyvsp[0].chars; }
     break;
 
   case 18:
-#line 205 "parse-gram.y"
+#line 206 "parse-gram.y"
     { no_lines_flag = true; }
     break;
 
   case 19:
-#line 206 "parse-gram.y"
+#line 207 "parse-gram.y"
     { nondeterministic_parser = true; }
     break;
 
   case 20:
-#line 207 "parse-gram.y"
+#line 208 "parse-gram.y"
     { spec_outfile = yyvsp[0].chars; }
     break;
 
   case 21:
-#line 208 "parse-gram.y"
+#line 209 "parse-gram.y"
     { add_param ("parse_param", yyvsp[0].chars, yylsp[0]); }
     break;
 
   case 22:
-#line 209 "parse-gram.y"
+#line 210 "parse-gram.y"
     { pure_parser = true; }
     break;
 
   case 23:
-#line 210 "parse-gram.y"
+#line 211 "parse-gram.y"
     { skeleton = yyvsp[0].chars; }
     break;
 
   case 24:
-#line 211 "parse-gram.y"
+#line 212 "parse-gram.y"
     { token_table_flag = true; }
     break;
 
   case 25:
-#line 212 "parse-gram.y"
+#line 213 "parse-gram.y"
     { report_flag = report_states; }
     break;
 
   case 26:
-#line 213 "parse-gram.y"
+#line 214 "parse-gram.y"
     { yacc_flag = true; }
     break;
 
   case 30:
-#line 221 "parse-gram.y"
+#line 222 "parse-gram.y"
     {
       grammar_start_symbol_set (yyvsp[0].symbol, yylsp[0]);
     }
     break;
 
   case 31:
-#line 225 "parse-gram.y"
+#line 226 "parse-gram.y"
     {
       typed = true;
       MUSCLE_INSERT_INT ("stype_line", yylsp[0].start.line);
@@ -1401,7 +1403,7 @@ yyreduce:
     break;
 
   case 32:
-#line 231 "parse-gram.y"
+#line 232 "parse-gram.y"
     {
       symbol_list *list;
       for (list = yyvsp[0].list; list; list = list->next)
@@ -1411,7 +1413,7 @@ yyreduce:
     break;
 
   case 33:
-#line 238 "parse-gram.y"
+#line 239 "parse-gram.y"
     {
       symbol_list *list;
       for (list = yyvsp[0].list; list; list = list->next)
@@ -1421,43 +1423,47 @@ yyreduce:
     break;
 
   case 34:
-#line 245 "parse-gram.y"
+#line 246 "parse-gram.y"
     {
-      if (0 <= yyvsp[0].integer && yyvsp[0].integer <= 1)
-	default_prec = yyvsp[0].integer;
-      else
-	complain_at (yylsp[-1], _("invalid value for `%default-prec'"));
+      default_prec = true;
     }
     break;
 
   case 35:
-#line 254 "parse-gram.y"
-    { current_class = nterm_sym; }
+#line 250 "parse-gram.y"
+    {
+      default_prec = false;
+    }
     break;
 
   case 36:
-#line 255 "parse-gram.y"
+#line 256 "parse-gram.y"
+    { current_class = nterm_sym; }
+    break;
+
+  case 37:
+#line 257 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
     break;
 
-  case 37:
-#line 259 "parse-gram.y"
+  case 38:
+#line 261 "parse-gram.y"
     { current_class = token_sym; }
     break;
 
-  case 38:
-#line 260 "parse-gram.y"
+  case 39:
+#line 262 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
     break;
 
-  case 39:
-#line 265 "parse-gram.y"
+  case 40:
+#line 267 "parse-gram.y"
     {
       symbol_list *list;
       for (list = yyvsp[0].list; list; list = list->next)
@@ -1466,8 +1472,8 @@ yyreduce:
     }
     break;
 
-  case 40:
-#line 275 "parse-gram.y"
+  case 41:
+#line 277 "parse-gram.y"
     {
       symbol_list *list;
       ++current_prec;
@@ -1481,58 +1487,58 @@ yyreduce:
     }
     break;
 
-  case 41:
-#line 289 "parse-gram.y"
+  case 42:
+#line 291 "parse-gram.y"
     { yyval.assoc = left_assoc; }
     break;
 
-  case 42:
-#line 290 "parse-gram.y"
+  case 43:
+#line 292 "parse-gram.y"
     { yyval.assoc = right_assoc; }
     break;
 
-  case 43:
-#line 291 "parse-gram.y"
+  case 44:
+#line 293 "parse-gram.y"
     { yyval.assoc = non_assoc; }
     break;
 
-  case 44:
-#line 295 "parse-gram.y"
+  case 45:
+#line 297 "parse-gram.y"
     { current_type = NULL; }
     break;
 
-  case 45:
-#line 296 "parse-gram.y"
+  case 46:
+#line 298 "parse-gram.y"
     { current_type = yyvsp[0].uniqstr; }
     break;
 
-  case 46:
-#line 302 "parse-gram.y"
+  case 47:
+#line 304 "parse-gram.y"
     { yyval.list = symbol_list_new (yyvsp[0].symbol, yylsp[0]); }
     break;
 
-  case 47:
-#line 303 "parse-gram.y"
+  case 48:
+#line 305 "parse-gram.y"
     { yyval.list = symbol_list_prepend (yyvsp[-1].list, yyvsp[0].symbol, yylsp[0]); }
     break;
 
-  case 48:
-#line 309 "parse-gram.y"
+  case 49:
+#line 311 "parse-gram.y"
     {
        current_type = yyvsp[0].uniqstr;
      }
     break;
 
-  case 49:
-#line 313 "parse-gram.y"
+  case 50:
+#line 315 "parse-gram.y"
     {
        symbol_class_set (yyvsp[0].symbol, current_class, yylsp[0]);
        symbol_type_set (yyvsp[0].symbol, current_type, yylsp[0]);
      }
     break;
 
-  case 50:
-#line 318 "parse-gram.y"
+  case 51:
+#line 320 "parse-gram.y"
     {
       symbol_class_set (yyvsp[-1].symbol, current_class, yylsp[-1]);
       symbol_type_set (yyvsp[-1].symbol, current_type, yylsp[-1]);
@@ -1540,8 +1546,8 @@ yyreduce:
     }
     break;
 
-  case 51:
-#line 324 "parse-gram.y"
+  case 52:
+#line 326 "parse-gram.y"
     {
       symbol_class_set (yyvsp[-1].symbol, current_class, yylsp[-1]);
       symbol_type_set (yyvsp[-1].symbol, current_type, yylsp[-1]);
@@ -1549,8 +1555,8 @@ yyreduce:
     }
     break;
 
-  case 52:
-#line 330 "parse-gram.y"
+  case 53:
+#line 332 "parse-gram.y"
     {
       symbol_class_set (yyvsp[-2].symbol, current_class, yylsp[-2]);
       symbol_type_set (yyvsp[-2].symbol, current_type, yylsp[-2]);
@@ -1559,99 +1565,99 @@ yyreduce:
     }
     break;
 
-  case 58:
-#line 359 "parse-gram.y"
+  case 59:
+#line 361 "parse-gram.y"
     {
       if (yacc_flag)
 	complain_at (yyloc, _("POSIX forbids declarations in the grammar"));
     }
     break;
 
-  case 59:
-#line 364 "parse-gram.y"
+  case 60:
+#line 366 "parse-gram.y"
     {
       yyerrok;
     }
     break;
 
-  case 60:
-#line 370 "parse-gram.y"
+  case 61:
+#line 372 "parse-gram.y"
     { current_lhs = yyvsp[0].symbol; current_lhs_location = yylsp[0]; }
     break;
 
-  case 62:
-#line 374 "parse-gram.y"
-    { grammar_rule_end (yylsp[0]); }
-    break;
-
   case 63:
-#line 375 "parse-gram.y"
+#line 376 "parse-gram.y"
     { grammar_rule_end (yylsp[0]); }
     break;
 
-  case 65:
-#line 381 "parse-gram.y"
-    { grammar_rule_begin (current_lhs, current_lhs_location); }
+  case 64:
+#line 377 "parse-gram.y"
+    { grammar_rule_end (yylsp[0]); }
     break;
 
   case 66:
 #line 383 "parse-gram.y"
-    { grammar_current_rule_symbol_append (yyvsp[0].symbol, yylsp[0]); }
+    { grammar_rule_begin (current_lhs, current_lhs_location); }
     break;
 
   case 67:
 #line 385 "parse-gram.y"
-    { grammar_current_rule_action_append (yyvsp[0].chars, yylsp[0]); }
+    { grammar_current_rule_symbol_append (yyvsp[0].symbol, yylsp[0]); }
     break;
 
   case 68:
 #line 387 "parse-gram.y"
-    { grammar_current_rule_prec_set (yyvsp[0].symbol, yylsp[0]); }
+    { grammar_current_rule_action_append (yyvsp[0].chars, yylsp[0]); }
     break;
 
   case 69:
 #line 389 "parse-gram.y"
-    { grammar_current_rule_dprec_set (yyvsp[0].integer, yylsp[0]); }
+    { grammar_current_rule_prec_set (yyvsp[0].symbol, yylsp[0]); }
     break;
 
   case 70:
 #line 391 "parse-gram.y"
-    { grammar_current_rule_merge_set (yyvsp[0].uniqstr, yylsp[0]); }
+    { grammar_current_rule_dprec_set (yyvsp[0].integer, yylsp[0]); }
     break;
 
   case 71:
-#line 395 "parse-gram.y"
-    { yyval.symbol = yyvsp[0].symbol; }
+#line 393 "parse-gram.y"
+    { grammar_current_rule_merge_set (yyvsp[0].uniqstr, yylsp[0]); }
     break;
 
   case 72:
-#line 396 "parse-gram.y"
+#line 397 "parse-gram.y"
     { yyval.symbol = yyvsp[0].symbol; }
     break;
 
   case 73:
-#line 401 "parse-gram.y"
-    { yyval.chars = yyvsp[0].chars; }
+#line 398 "parse-gram.y"
+    { yyval.symbol = yyvsp[0].symbol; }
     break;
 
   case 74:
-#line 407 "parse-gram.y"
+#line 403 "parse-gram.y"
+    { yyval.chars = yyvsp[0].chars; }
+    break;
+
+  case 75:
+#line 409 "parse-gram.y"
     {
       yyval.symbol = symbol_get (yyvsp[0].chars, yylsp[0]);
       symbol_class_set (yyval.symbol, token_sym, yylsp[0]);
     }
     break;
 
-  case 75:
-#line 416 "parse-gram.y"
+  case 76:
+#line 418 "parse-gram.y"
     {
       yyval.chars = yyvsp[0].chars + 1;
       yyval.chars[strlen (yyval.chars) - 1] = '\0';
     }
     break;
 
-  case 77:
-#line 425 "parse-gram.y"
+  case 78:
+#line 427 "parse-gram.y"
     {
       muscle_code_grow ("epilogue", yyvsp[0].chars, yylsp[0]);
       scanner_last_string_free ();
@@ -1662,7 +1668,7 @@ yyreduce:
     }
 
 /* Line 1010 of yacc.c.  */
-#line 1666 "parse-gram.c"
+#line 1672 "parse-gram.c"
 
   yyvsp -= yylen;
   yyssp -= yylen;
@@ -1891,7 +1897,7 @@ yyreturn:
 }
 
 
-#line 431 "parse-gram.y"
+#line 433 "parse-gram.y"
 
 
 
