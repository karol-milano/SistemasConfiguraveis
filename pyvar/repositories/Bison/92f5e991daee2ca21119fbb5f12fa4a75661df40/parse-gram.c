@@ -78,36 +78,37 @@
      PERCENT_DPREC = 270,
      PERCENT_MERGE = 271,
      PERCENT_DEBUG = 272,
-     PERCENT_DEFINE = 273,
-     PERCENT_DEFINES = 274,
-     PERCENT_ERROR_VERBOSE = 275,
-     PERCENT_EXPECT = 276,
-     PERCENT_FILE_PREFIX = 277,
-     PERCENT_GLR_PARSER = 278,
-     PERCENT_INITIAL_ACTION = 279,
-     PERCENT_LEX_PARAM = 280,
-     PERCENT_LOCATIONS = 281,
-     PERCENT_NAME_PREFIX = 282,
-     PERCENT_NO_LINES = 283,
-     PERCENT_NONDETERMINISTIC_PARSER = 284,
-     PERCENT_OUTPUT = 285,
-     PERCENT_PARSE_PARAM = 286,
-     PERCENT_PURE_PARSER = 287,
-     PERCENT_SKELETON = 288,
-     PERCENT_START = 289,
-     PERCENT_TOKEN_TABLE = 290,
-     PERCENT_VERBOSE = 291,
-     PERCENT_YACC = 292,
-     TYPE = 293,
-     EQUAL = 294,
-     SEMICOLON = 295,
-     PIPE = 296,
-     ID = 297,
-     ID_COLON = 298,
-     PERCENT_PERCENT = 299,
-     PROLOGUE = 300,
-     EPILOGUE = 301,
-     BRACED_CODE = 302
+     PERCENT_DEFAULT_PREC = 273,
+     PERCENT_DEFINE = 274,
+     PERCENT_DEFINES = 275,
+     PERCENT_ERROR_VERBOSE = 276,
+     PERCENT_EXPECT = 277,
+     PERCENT_FILE_PREFIX = 278,
+     PERCENT_GLR_PARSER = 279,
+     PERCENT_INITIAL_ACTION = 280,
+     PERCENT_LEX_PARAM = 281,
+     PERCENT_LOCATIONS = 282,
+     PERCENT_NAME_PREFIX = 283,
+     PERCENT_NO_LINES = 284,
+     PERCENT_NONDETERMINISTIC_PARSER = 285,
+     PERCENT_OUTPUT = 286,
+     PERCENT_PARSE_PARAM = 287,
+     PERCENT_PURE_PARSER = 288,
+     PERCENT_SKELETON = 289,
+     PERCENT_START = 290,
+     PERCENT_TOKEN_TABLE = 291,
+     PERCENT_VERBOSE = 292,
+     PERCENT_YACC = 293,
+     TYPE = 294,
+     EQUAL = 295,
+     SEMICOLON = 296,
+     PIPE = 297,
+     ID = 298,
+     ID_COLON = 299,
+     PERCENT_PERCENT = 300,
+     PROLOGUE = 301,
+     EPILOGUE = 302,
+     BRACED_CODE = 303
    };
 #endif
 #define GRAM_EOF 0
@@ -126,36 +127,37 @@
 #define PERCENT_DPREC 270
 #define PERCENT_MERGE 271
 #define PERCENT_DEBUG 272
-#define PERCENT_DEFINE 273
-#define PERCENT_DEFINES 274
-#define PERCENT_ERROR_VERBOSE 275
-#define PERCENT_EXPECT 276
-#define PERCENT_FILE_PREFIX 277
-#define PERCENT_GLR_PARSER 278
-#define PERCENT_INITIAL_ACTION 279
-#define PERCENT_LEX_PARAM 280
-#define PERCENT_LOCATIONS 281
-#define PERCENT_NAME_PREFIX 282
-#define PERCENT_NO_LINES 283
-#define PERCENT_NONDETERMINISTIC_PARSER 284
-#define PERCENT_OUTPUT 285
-#define PERCENT_PARSE_PARAM 286
-#define PERCENT_PURE_PARSER 287
-#define PERCENT_SKELETON 288
-#define PERCENT_START 289
-#define PERCENT_TOKEN_TABLE 290
-#define PERCENT_VERBOSE 291
-#define PERCENT_YACC 292
-#define TYPE 293
-#define EQUAL 294
-#define SEMICOLON 295
-#define PIPE 296
-#define ID 297
-#define ID_COLON 298
-#define PERCENT_PERCENT 299
-#define PROLOGUE 300
-#define EPILOGUE 301
-#define BRACED_CODE 302
+#define PERCENT_DEFAULT_PREC 273
+#define PERCENT_DEFINE 274
+#define PERCENT_DEFINES 275
+#define PERCENT_ERROR_VERBOSE 276
+#define PERCENT_EXPECT 277
+#define PERCENT_FILE_PREFIX 278
+#define PERCENT_GLR_PARSER 279
+#define PERCENT_INITIAL_ACTION 280
+#define PERCENT_LEX_PARAM 281
+#define PERCENT_LOCATIONS 282
+#define PERCENT_NAME_PREFIX 283
+#define PERCENT_NO_LINES 284
+#define PERCENT_NONDETERMINISTIC_PARSER 285
+#define PERCENT_OUTPUT 286
+#define PERCENT_PARSE_PARAM 287
+#define PERCENT_PURE_PARSER 288
+#define PERCENT_SKELETON 289
+#define PERCENT_START 290
+#define PERCENT_TOKEN_TABLE 291
+#define PERCENT_VERBOSE 292
+#define PERCENT_YACC 293
+#define TYPE 294
+#define EQUAL 295
+#define SEMICOLON 296
+#define PIPE 297
+#define ID 298
+#define ID_COLON 299
+#define PERCENT_PERCENT 300
+#define PROLOGUE 301
+#define EPILOGUE 302
+#define BRACED_CODE 303
 
 
 
@@ -223,7 +225,7 @@ typedef union YYSTYPE {
   uniqstr uniqstr;
 } YYSTYPE;
 /* Line 191 of yacc.c.  */
-#line 227 "parse-gram.c"
+#line 229 "parse-gram.c"
 # define yystype YYSTYPE /* obsolescent; will be withdrawn */
 # define YYSTYPE_IS_DECLARED 1
 # define YYSTYPE_IS_TRIVIAL 1
@@ -247,7 +249,7 @@ typedef struct YYLTYPE
 
 
 /* Line 214 of yacc.c.  */
-#line 251 "parse-gram.c"
+#line 253 "parse-gram.c"
 
 #if ! defined (yyoverflow) || YYERROR_VERBOSE
 
@@ -355,20 +357,20 @@ union yyalloc
 /* YYFINAL -- State number of the termination state. */
 #define YYFINAL  3
 /* YYLAST -- Last index in YYTABLE.  */
-#define YYLAST   150
+#define YYLAST   153
 
 /* YYNTOKENS -- Number of terminals. */
-#define YYNTOKENS  48
+#define YYNTOKENS  49
 /* YYNNTS -- Number of nonterminals. */
 #define YYNNTS  25
 /* YYNRULES -- Number of rules. */
-#define YYNRULES  76
+#define YYNRULES  77
 /* YYNRULES -- Number of states. */
-#define YYNSTATES  104
+#define YYNSTATES  106
 
 /* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
 #define YYUNDEFTOK  2
-#define YYMAXUTOK   302
+#define YYMAXUTOK   303
 
 #define YYTRANSLATE(YYX) 						\
   ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)
@@ -406,7 +408,7 @@ static const unsigned char yytranslate[] =
       15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
       25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
       35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
-      45,    46,    47
+      45,    46,    47,    48
 };
 
 #if YYDEBUG
@@ -417,49 +419,49 @@ static const unsigned char yyprhs[] =
        0,     0,     3,     8,     9,    12,    14,    16,    18,    22,
       24,    26,    29,    33,    35,    37,    39,    41,    45,    47,
       49,    53,    55,    57,    60,    62,    64,    66,    68,    70,
-      72,    75,    77,    80,    83,    84,    88,    89,    93,    97,
-     101,   103,   105,   107,   108,   110,   112,   115,   117,   119,
-     122,   125,   129,   131,   134,   136,   139,   141,   144,   147,
-     148,   152,   154,   158,   161,   162,   165,   168,   172,   176,
-     180,   182,   184,   186,   188,   190,   191
+      72,    75,    77,    80,    83,    86,    87,    91,    92,    96,
+     100,   104,   106,   108,   110,   111,   113,   115,   118,   120,
+     122,   125,   128,   132,   134,   137,   139,   142,   144,   147,
+     150,   151,   155,   157,   161,   164,   165,   168,   171,   175,
+     179,   183,   185,   187,   189,   191,   193,   194
 };
 
 /* YYRHS -- A `-1'-separated list of the rules' RHS. */
 static const yysigned_char yyrhs[] =
 {
-      49,     0,    -1,    50,    44,    62,    72,    -1,    -1,    50,
-      51,    -1,    52,    -1,    45,    -1,    17,    -1,    18,    71,
-      71,    -1,    19,    -1,    20,    -1,    21,     4,    -1,    22,
-      39,    71,    -1,    23,    -1,    24,    -1,    25,    -1,    26,
-      -1,    27,    39,    71,    -1,    28,    -1,    29,    -1,    30,
-      39,    71,    -1,    31,    -1,    32,    -1,    33,    71,    -1,
-      35,    -1,    36,    -1,    37,    -1,    40,    -1,    56,    -1,
-      53,    -1,    34,    68,    -1,    10,    -1,     8,    59,    -1,
-       9,    59,    -1,    -1,     6,    54,    61,    -1,    -1,     5,
-      55,    61,    -1,     7,    38,    59,    -1,    57,    58,    59,
-      -1,    11,    -1,    12,    -1,    13,    -1,    -1,    38,    -1,
-      68,    -1,    59,    68,    -1,    38,    -1,    42,    -1,    42,
-       4,    -1,    42,    70,    -1,    42,     4,    70,    -1,    60,
-      -1,    61,    60,    -1,    63,    -1,    62,    63,    -1,    64,
-      -1,    52,    40,    -1,     1,    40,    -1,    -1,    43,    65,
-      66,    -1,    67,    -1,    66,    41,    67,    -1,    66,    40,
-      -1,    -1,    67,    68,    -1,    67,    69,    -1,    67,    14,
-      68,    -1,    67,    15,     4,    -1,    67,    16,    38,    -1,
-      42,    -1,    70,    -1,    47,    -1,     3,    -1,     3,    -1,
-      -1,    44,    46,    -1
+      50,     0,    -1,    51,    45,    63,    73,    -1,    -1,    51,
+      52,    -1,    53,    -1,    46,    -1,    17,    -1,    19,    72,
+      72,    -1,    20,    -1,    21,    -1,    22,     4,    -1,    23,
+      40,    72,    -1,    24,    -1,    25,    -1,    26,    -1,    27,
+      -1,    28,    40,    72,    -1,    29,    -1,    30,    -1,    31,
+      40,    72,    -1,    32,    -1,    33,    -1,    34,    72,    -1,
+      36,    -1,    37,    -1,    38,    -1,    41,    -1,    57,    -1,
+      54,    -1,    35,    69,    -1,    10,    -1,     8,    60,    -1,
+       9,    60,    -1,    18,     4,    -1,    -1,     6,    55,    62,
+      -1,    -1,     5,    56,    62,    -1,     7,    39,    60,    -1,
+      58,    59,    60,    -1,    11,    -1,    12,    -1,    13,    -1,
+      -1,    39,    -1,    69,    -1,    60,    69,    -1,    39,    -1,
+      43,    -1,    43,     4,    -1,    43,    71,    -1,    43,     4,
+      71,    -1,    61,    -1,    62,    61,    -1,    64,    -1,    63,
+      64,    -1,    65,    -1,    53,    41,    -1,     1,    41,    -1,
+      -1,    44,    66,    67,    -1,    68,    -1,    67,    42,    68,
+      -1,    67,    41,    -1,    -1,    68,    69,    -1,    68,    70,
+      -1,    68,    14,    69,    -1,    68,    15,     4,    -1,    68,
+      16,    39,    -1,    43,    -1,    71,    -1,    48,    -1,     3,
+      -1,     3,    -1,    -1,    45,    47,    -1
 };
 
 /* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
 static const unsigned short yyrline[] =
 {
-       0,   170,   170,   178,   180,   184,   185,   186,   187,   188,
-     189,   190,   191,   192,   197,   201,   202,   203,   204,   205,
-     206,   207,   208,   209,   210,   211,   212,   213,   217,   218,
-     219,   223,   229,   236,   246,   246,   251,   251,   256,   266,
-     281,   282,   283,   287,   288,   294,   295,   300,   304,   309,
-     315,   321,   332,   333,   342,   343,   349,   350,   355,   362,
-     362,   366,   367,   368,   373,   374,   376,   378,   380,   382,
-     387,   388,   392,   398,   407,   414,   416
+       0,   171,   171,   179,   181,   185,   186,   187,   188,   189,
+     190,   191,   192,   193,   198,   202,   203,   204,   205,   206,
+     207,   208,   209,   210,   211,   212,   213,   214,   218,   219,
+     220,   224,   230,   237,   244,   254,   254,   259,   259,   264,
+     274,   289,   290,   291,   295,   296,   302,   303,   308,   312,
+     317,   323,   329,   340,   341,   350,   351,   357,   358,   363,
+     370,   370,   374,   375,   376,   381,   382,   384,   386,   388,
+     390,   395,   396,   400,   406,   415,   422,   424
 };
 #endif
 
@@ -472,13 +474,13 @@ static const char *const yytname[] =
   "\"%token\"", "\"%nterm\"", "\"%type\"", "\"%destructor {...}\"",
   "\"%printer {...}\"", "\"%union {...}\"", "\"%left\"", "\"%right\"",
   "\"%nonassoc\"", "\"%prec\"", "\"%dprec\"", "\"%merge\"", "\"%debug\"",
-  "\"%define\"", "\"%defines\"", "\"%error-verbose\"", "\"%expect\"",
-  "\"%file-prefix\"", "\"%glr-parser\"", "\"%initial-action {...}\"",
-  "\"%lex-param {...}\"", "\"%locations\"", "\"%name-prefix\"",
-  "\"%no-lines\"", "\"%nondeterministic-parser\"", "\"%output\"",
-  "\"%parse-param {...}\"", "\"%pure-parser\"", "\"%skeleton\"",
-  "\"%start\"", "\"%token-table\"", "\"%verbose\"", "\"%yacc\"",
-  "\"type\"", "\"=\"", "\";\"", "\"|\"", "\"identifier\"",
+  "\"%default-prec\"", "\"%define\"", "\"%defines\"", "\"%error-verbose\"",
+  "\"%expect\"", "\"%file-prefix\"", "\"%glr-parser\"",
+  "\"%initial-action {...}\"", "\"%lex-param {...}\"", "\"%locations\"",
+  "\"%name-prefix\"", "\"%no-lines\"", "\"%nondeterministic-parser\"",
+  "\"%output\"", "\"%parse-param {...}\"", "\"%pure-parser\"",
+  "\"%skeleton\"", "\"%start\"", "\"%token-table\"", "\"%verbose\"",
+  "\"%yacc\"", "\"type\"", "\"=\"", "\";\"", "\"|\"", "\"identifier\"",
   "\"identifier:\"", "\"%%\"", "\"%{...%}\"", "\"epilogue\"", "\"{...}\"",
   "$accept", "input", "declarations", "declaration", "grammar_declaration",
   "symbol_declaration", "@1", "@2", "precedence_declaration",
@@ -498,21 +500,21 @@ static const unsigned short yytoknum[] =
      265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
      275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
      285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
-     295,   296,   297,   298,   299,   300,   301,   302
+     295,   296,   297,   298,   299,   300,   301,   302,   303
 };
 # endif
 
 /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
 static const unsigned char yyr1[] =
 {
-       0,    48,    49,    50,    50,    51,    51,    51,    51,    51,
-      51,    51,    51,    51,    51,    51,    51,    51,    51,    51,
-      51,    51,    51,    51,    51,    51,    51,    51,    52,    52,
-      52,    52,    52,    52,    54,    53,    55,    53,    53,    56,
-      57,    57,    57,    58,    58,    59,    59,    60,    60,    60,
-      60,    60,    61,    61,    62,    62,    63,    63,    63,    65,
-      64,    66,    66,    66,    67,    67,    67,    67,    67,    67,
-      68,    68,    69,    70,    71,    72,    72
+       0,    49,    50,    51,    51,    52,    52,    52,    52,    52,
+      52,    52,    52,    52,    52,    52,    52,    52,    52,    52,
+      52,    52,    52,    52,    52,    52,    52,    52,    53,    53,
+      53,    53,    53,    53,    53,    55,    54,    56,    54,    54,
+      57,    58,    58,    58,    59,    59,    60,    60,    61,    61,
+      61,    61,    61,    62,    62,    63,    63,    64,    64,    64,
+      66,    65,    67,    67,    67,    68,    68,    68,    68,    68,
+      68,    69,    69,    70,    71,    72,    73,    73
 };
 
 /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
@@ -521,11 +523,11 @@ static const unsigned char yyr2[] =
        0,     2,     4,     0,     2,     1,     1,     1,     3,     1,
        1,     2,     3,     1,     1,     1,     1,     3,     1,     1,
        3,     1,     1,     2,     1,     1,     1,     1,     1,     1,
-       2,     1,     2,     2,     0,     3,     0,     3,     3,     3,
-       1,     1,     1,     0,     1,     1,     2,     1,     1,     2,
-       2,     3,     1,     2,     1,     2,     1,     2,     2,     0,
-       3,     1,     3,     2,     0,     2,     2,     3,     3,     3,
-       1,     1,     1,     1,     1,     0,     2
+       2,     1,     2,     2,     2,     0,     3,     0,     3,     3,
+       3,     1,     1,     1,     0,     1,     1,     2,     1,     1,
+       2,     2,     3,     1,     2,     1,     2,     1,     2,     2,
+       0,     3,     1,     3,     2,     0,     2,     2,     3,     3,
+       3,     1,     1,     1,     1,     1,     0,     2
 };
 
 /* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
@@ -533,113 +535,113 @@ static const unsigned char yyr2[] =
    means the default is an error.  */
 static const unsigned char yydefact[] =
 {
-       3,     0,     0,     1,    36,    34,     0,     0,     0,    31,
-      40,    41,    42,     7,     0,     9,    10,     0,     0,    13,
-      14,    15,    16,     0,    18,    19,     0,    21,    22,     0,
-       0,    24,    25,    26,    27,     0,     6,     4,     5,    29,
-      28,    43,     0,     0,     0,    73,    70,    32,    45,    71,
-      33,    74,     0,    11,     0,     0,     0,    23,    30,     0,
-      59,     0,     0,    54,    56,    44,     0,    47,    48,    52,
-      37,    35,    38,    46,     8,    12,    17,    20,    58,    64,
-      57,     0,    55,     2,    39,    49,    50,    53,    60,    61,
-      76,    51,    63,    64,     0,     0,     0,    72,    65,    66,
-      62,    67,    68,    69
+       3,     0,     0,     1,    37,    35,     0,     0,     0,    31,
+      41,    42,    43,     7,     0,     0,     9,    10,     0,     0,
+      13,    14,    15,    16,     0,    18,    19,     0,    21,    22,
+       0,     0,    24,    25,    26,    27,     0,     6,     4,     5,
+      29,    28,    44,     0,     0,     0,    74,    71,    32,    46,
+      72,    33,    34,    75,     0,    11,     0,     0,     0,    23,
+      30,     0,    60,     0,     0,    55,    57,    45,     0,    48,
+      49,    53,    38,    36,    39,    47,     8,    12,    17,    20,
+      59,    65,    58,     0,    56,     2,    40,    50,    51,    54,
+      61,    62,    77,    52,    64,    65,     0,     0,     0,    73,
+      66,    67,    63,    68,    69,    70
 };
 
 /* YYDEFGOTO[NTERM-NUM]. */
 static const yysigned_char yydefgoto[] =
 {
-      -1,     1,     2,    37,    61,    39,    43,    42,    40,    41,
-      66,    47,    69,    70,    62,    63,    64,    79,    88,    89,
-      48,    99,    49,    52,    83
+      -1,     1,     2,    38,    63,    40,    44,    43,    41,    42,
+      68,    48,    71,    72,    64,    65,    66,    81,    90,    91,
+      49,   101,    50,    54,    85
 };
 
 /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
    STATE-NUM.  */
-#define YYPACT_NINF -64
+#define YYPACT_NINF -63
 static const yysigned_char yypact[] =
 {
-     -64,    21,   105,   -64,   -64,   -64,   -14,    -2,    -2,   -64,
-     -64,   -64,   -64,   -64,    25,   -64,   -64,    30,    -3,   -64,
-     -64,   -64,   -64,     0,   -64,   -64,     2,   -64,   -64,    25,
-      -2,   -64,   -64,   -64,   -64,    66,   -64,   -64,   -64,   -64,
-     -64,     5,   -19,   -19,    -2,   -64,   -64,    -2,   -64,   -64,
-      -2,   -64,    25,   -64,    25,    25,    25,   -64,   -64,    -5,
-     -64,     4,     3,   -64,   -64,   -64,    -2,   -64,    23,   -64,
-     -19,   -19,    -2,   -64,   -64,   -64,   -64,   -64,   -64,   -64,
-     -64,    -1,   -64,   -64,    -2,    46,   -64,   -64,   -34,    15,
-     -64,   -64,   -64,   -64,    -2,    49,    17,   -64,   -64,   -64,
-      15,   -64,   -64,   -64
+     -63,    12,   107,   -63,   -63,   -63,   -18,     1,     1,   -63,
+     -63,   -63,   -63,   -63,    28,    31,   -63,   -63,    33,    -5,
+     -63,   -63,   -63,   -63,     0,   -63,   -63,     5,   -63,   -63,
+      31,     1,   -63,   -63,   -63,   -63,    67,   -63,   -63,   -63,
+     -63,   -63,    13,   -36,   -36,     1,   -63,   -63,     1,   -63,
+     -63,     1,   -63,   -63,    31,   -63,    31,    31,    31,   -63,
+     -63,    -2,   -63,    10,    18,   -63,   -63,   -63,     1,   -63,
+       2,   -63,   -36,   -36,     1,   -63,   -63,   -63,   -63,   -63,
+     -63,   -63,   -63,    -6,   -63,   -63,     1,    51,   -63,   -63,
+     -33,    -1,   -63,   -63,   -63,   -63,     1,    52,    19,   -63,
+     -63,   -63,    -1,   -63,   -63,   -63
 };
 
 /* YYPGOTO[NTERM-NUM].  */
 static const yysigned_char yypgoto[] =
 {
-     -64,   -64,   -64,   -64,    54,   -64,   -64,   -64,   -64,   -64,
-     -64,    -6,   -38,    18,   -64,     1,   -64,   -64,   -64,   -35,
-     -30,   -64,   -63,    -4,   -64
+     -63,   -63,   -63,   -63,    55,   -63,   -63,   -63,   -63,   -63,
+     -63,    -7,   -62,    15,   -63,     3,   -63,   -63,   -63,   -29,
+     -31,   -63,   -54,    -8,   -63
 };
 
 /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
    positive, shift that token.  If negative, reduce the rule which
    number is the opposite.  If zero, do what YYDEFACT says.
    If YYTABLE_NINF, syntax error.  */
-#define YYTABLE_NINF -76
+#define YYTABLE_NINF -77
 static const yysigned_char yytable[] =
 {
-      58,    45,    50,   -75,    59,    86,    92,    93,     4,     5,
-       6,     7,     8,     9,    10,    11,    12,    73,    45,    67,
-      73,     3,    91,    68,    44,    57,    45,    85,    51,    94,
-      95,    96,    87,    87,    53,    78,    54,    30,    72,    55,
-      46,    56,    73,    65,    80,    90,    60,    81,    74,    45,
-      75,    76,    77,   102,    73,   103,    38,    46,   100,    98,
-      84,    71,    97,    82,   101,     0,     0,    59,     0,     0,
-      98,     4,     5,     6,     7,     8,     9,    10,    11,    12,
+      60,    51,    46,    69,    46,    46,    87,    70,    94,    95,
+      89,    89,     3,    96,    97,    98,    88,    75,   -76,    61,
+      75,    45,    59,     4,     5,     6,     7,     8,     9,    10,
+      11,    12,    52,    93,    53,    56,    14,    55,    74,    80,
+      57,    92,    47,    75,    47,    58,    76,    99,    77,    78,
+      79,    82,    67,    31,    46,    75,   104,    39,   105,    73,
+     100,    86,    62,    83,     0,   103,   102,    84,    61,     0,
+       0,   100,     4,     5,     6,     7,     8,     9,    10,    11,
+      12,     0,     0,     0,     0,    14,     0,     0,     0,     0,
        0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
-       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
-      30,     0,     0,     0,     0,     0,     0,     0,     0,    60,
-       4,     5,     6,     7,     8,     9,    10,    11,    12,     0,
-       0,     0,    13,    14,    15,    16,    17,    18,    19,    20,
-      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
-      31,    32,    33,     0,     0,    34,     0,     0,     0,    35,
-      36
+       0,     0,    31,     0,     0,     0,     0,     0,     0,     0,
+       0,    62,     4,     5,     6,     7,     8,     9,    10,    11,
+      12,     0,     0,     0,    13,    14,    15,    16,    17,    18,
+      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
+      29,    30,    31,    32,    33,    34,     0,     0,    35,     0,
+       0,     0,    36,    37
 };
 
 static const yysigned_char yycheck[] =
 {
-      30,     3,     8,     0,     1,    68,    40,    41,     5,     6,
-       7,     8,     9,    10,    11,    12,    13,    47,     3,    38,
-      50,     0,    85,    42,    38,    29,     3,     4,     3,    14,
-      15,    16,    70,    71,     4,    40,    39,    34,    44,    39,
-      42,    39,    72,    38,    40,    46,    43,    44,    52,     3,
-      54,    55,    56,     4,    84,    38,     2,    42,    93,    89,
-      66,    43,    47,    62,    94,    -1,    -1,     1,    -1,    -1,
-     100,     5,     6,     7,     8,     9,    10,    11,    12,    13,
-      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
+      31,     8,     3,    39,     3,     3,     4,    43,    41,    42,
+      72,    73,     0,    14,    15,    16,    70,    48,     0,     1,
+      51,    39,    30,     5,     6,     7,     8,     9,    10,    11,
+      12,    13,     4,    87,     3,    40,    18,     4,    45,    41,
+      40,    47,    43,    74,    43,    40,    54,    48,    56,    57,
+      58,    41,    39,    35,     3,    86,     4,     2,    39,    44,
+      91,    68,    44,    45,    -1,    96,    95,    64,     1,    -1,
+      -1,   102,     5,     6,     7,     8,     9,    10,    11,    12,
+      13,    -1,    -1,    -1,    -1,    18,    -1,    -1,    -1,    -1,
       -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
-      34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,
-       5,     6,     7,     8,     9,    10,    11,    12,    13,    -1,
-      -1,    -1,    17,    18,    19,    20,    21,    22,    23,    24,
-      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
-      35,    36,    37,    -1,    -1,    40,    -1,    -1,    -1,    44,
-      45
+      -1,    -1,    35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
+      -1,    44,     5,     6,     7,     8,     9,    10,    11,    12,
+      13,    -1,    -1,    -1,    17,    18,    19,    20,    21,    22,
+      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
+      33,    34,    35,    36,    37,    38,    -1,    -1,    41,    -1,
+      -1,    -1,    45,    46
 };
 
 /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
    symbol of state STATE-NUM.  */
 static const unsigned char yystos[] =
 {
-       0,    49,    50,     0,     5,     6,     7,     8,     9,    10,
+       0,    50,    51,     0,     5,     6,     7,     8,     9,    10,
       11,    12,    13,    17,    18,    19,    20,    21,    22,    23,
       24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
-      34,    35,    36,    37,    40,    44,    45,    51,    52,    53,
-      56,    57,    55,    54,    38,     3,    42,    59,    68,    70,
-      59,     3,    71,     4,    39,    39,    39,    71,    68,     1,
-      43,    52,    62,    63,    64,    38,    58,    38,    42,    60,
-      61,    61,    59,    68,    71,    71,    71,    71,    40,    65,
-      40,    44,    63,    72,    59,     4,    70,    60,    66,    67,
-      46,    70,    40,    41,    14,    15,    16,    47,    68,    69,
-      67,    68,     4,    38
+      34,    35,    36,    37,    38,    41,    45,    46,    52,    53,
+      54,    57,    58,    56,    55,    39,     3,    43,    60,    69,
+      71,    60,     4,     3,    72,     4,    40,    40,    40,    72,
+      69,     1,    44,    53,    63,    64,    65,    39,    59,    39,
+      43,    61,    62,    62,    60,    69,    72,    72,    72,    72,
+      41,    66,    41,    45,    64,    73,    60,     4,    71,    61,
+      67,    68,    47,    71,    41,    42,    14,    15,    16,    48,
+      69,    70,    68,    69,     4,    39
 };
 
 #if ! defined (YYSIZE_T) && defined (__SIZE_TYPE__)
@@ -1085,7 +1087,7 @@ YYLTYPE yylloc;
   (*yylsp).start.column = (*yylsp).end.column = 0;
 }
 /* Line 818 of yacc.c.  */
-#line 1089 "parse-gram.c"
+#line 1091 "parse-gram.c"
   goto yysetstate;
 
 /*------------------------------------------------------------.
@@ -1273,42 +1275,42 @@ yyreduce:
   switch (yyn)
     {
         case 6:
-#line 185 "parse-gram.y"
+#line 186 "parse-gram.y"
     { prologue_augment (yyvsp[0].chars, yylsp[0]); }
     break;
 
   case 7:
-#line 186 "parse-gram.y"
+#line 187 "parse-gram.y"
     { debug_flag = true; }
     break;
 
   case 8:
-#line 187 "parse-gram.y"
+#line 188 "parse-gram.y"
     { muscle_insert (yyvsp[-1].chars, yyvsp[0].chars); }
     break;
 
   case 9:
-#line 188 "parse-gram.y"
+#line 189 "parse-gram.y"
     { defines_flag = true; }
     break;
 
   case 10:
-#line 189 "parse-gram.y"
+#line 190 "parse-gram.y"
     { error_verbose = true; }
     break;
 
   case 11:
-#line 190 "parse-gram.y"
+#line 191 "parse-gram.y"
     { expected_conflicts = yyvsp[0].integer; }
     break;
 
   case 12:
-#line 191 "parse-gram.y"
+#line 192 "parse-gram.y"
     { spec_file_prefix = yyvsp[0].chars; }
     break;
 
   case 13:
-#line 193 "parse-gram.y"
+#line 194 "parse-gram.y"
     {
     nondeterministic_parser = true;
     glr_parser = true;
@@ -1316,81 +1318,81 @@ yyreduce:
     break;
 
   case 14:
-#line 198 "parse-gram.y"
+#line 199 "parse-gram.y"
     {
     muscle_code_grow ("initial_action", yyvsp[0].chars, yylsp[0]);
   }
     break;
 
   case 15:
-#line 201 "parse-gram.y"
+#line 202 "parse-gram.y"
     { add_param ("lex_param", yyvsp[0].chars, yylsp[0]); }
     break;
 
   case 16:
-#line 202 "parse-gram.y"
+#line 203 "parse-gram.y"
     { locations_flag = true; }
     break;
 
   case 17:
-#line 203 "parse-gram.y"
+#line 204 "parse-gram.y"
     { spec_name_prefix = yyvsp[0].chars; }
     break;
 
   case 18:
-#line 204 "parse-gram.y"
+#line 205 "parse-gram.y"
     { no_lines_flag = true; }
     break;
 
   case 19:
-#line 205 "parse-gram.y"
+#line 206 "parse-gram.y"
     { nondeterministic_parser = true; }
     break;
 
   case 20:
-#line 206 "parse-gram.y"
+#line 207 "parse-gram.y"
     { spec_outfile = yyvsp[0].chars; }
     break;
 
   case 21:
-#line 207 "parse-gram.y"
+#line 208 "parse-gram.y"
     { add_param ("parse_param", yyvsp[0].chars, yylsp[0]); }
     break;
 
   case 22:
-#line 208 "parse-gram.y"
+#line 209 "parse-gram.y"
     { pure_parser = true; }
     break;
 
   case 23:
-#line 209 "parse-gram.y"
+#line 210 "parse-gram.y"
     { skeleton = yyvsp[0].chars; }
     break;
 
   case 24:
-#line 210 "parse-gram.y"
+#line 211 "parse-gram.y"
     { token_table_flag = true; }
     break;
 
   case 25:
-#line 211 "parse-gram.y"
+#line 212 "parse-gram.y"
     { report_flag = report_states; }
     break;
 
   case 26:
-#line 212 "parse-gram.y"
+#line 213 "parse-gram.y"
     { yacc_flag = true; }
     break;
 
   case 30:
-#line 220 "parse-gram.y"
+#line 221 "parse-gram.y"
     {
       grammar_start_symbol_set (yyvsp[0].symbol, yylsp[0]);
     }
     break;
 
   case 31:
-#line 224 "parse-gram.y"
+#line 225 "parse-gram.y"
     {
       typed = true;
       MUSCLE_INSERT_INT ("stype_line", yylsp[0].start.line);
@@ -1399,7 +1401,7 @@ yyreduce:
     break;
 
   case 32:
-#line 230 "parse-gram.y"
+#line 231 "parse-gram.y"
     {
       symbol_list *list;
       for (list = yyvsp[0].list; list; list = list->next)
@@ -1409,7 +1411,7 @@ yyreduce:
     break;
 
   case 33:
-#line 237 "parse-gram.y"
+#line 238 "parse-gram.y"
     {
       symbol_list *list;
       for (list = yyvsp[0].list; list; list = list->next)
@@ -1419,33 +1421,43 @@ yyreduce:
     break;
 
   case 34:
-#line 246 "parse-gram.y"
-    { current_class = nterm_sym; }
+#line 245 "parse-gram.y"
+    {
+      if (0 <= yyvsp[0].integer && yyvsp[0].integer <= 1)
+	default_prec = yyvsp[0].integer;
+      else
+	complain_at (yylsp[-1], _("invalid value for `%default-prec'"));
+    }
     break;
 
   case 35:
-#line 247 "parse-gram.y"
+#line 254 "parse-gram.y"
+    { current_class = nterm_sym; }
+    break;
+
+  case 36:
+#line 255 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
     break;
 
-  case 36:
-#line 251 "parse-gram.y"
+  case 37:
+#line 259 "parse-gram.y"
     { current_class = token_sym; }
     break;
 
-  case 37:
-#line 252 "parse-gram.y"
+  case 38:
+#line 260 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
     break;
 
-  case 38:
-#line 257 "parse-gram.y"
+  case 39:
+#line 265 "parse-gram.y"
     {
       symbol_list *list;
       for (list = yyvsp[0].list; list; list = list->next)
@@ -1454,8 +1466,8 @@ yyreduce:
     }
     break;
 
-  case 39:
-#line 267 "parse-gram.y"
+  case 40:
+#line 275 "parse-gram.y"
     {
       symbol_list *list;
       ++current_prec;
@@ -1469,58 +1481,58 @@ yyreduce:
     }
     break;
 
-  case 40:
-#line 281 "parse-gram.y"
+  case 41:
+#line 289 "parse-gram.y"
     { yyval.assoc = left_assoc; }
     break;
 
-  case 41:
-#line 282 "parse-gram.y"
+  case 42:
+#line 290 "parse-gram.y"
     { yyval.assoc = right_assoc; }
     break;
 
-  case 42:
-#line 283 "parse-gram.y"
+  case 43:
+#line 291 "parse-gram.y"
     { yyval.assoc = non_assoc; }
     break;
 
-  case 43:
-#line 287 "parse-gram.y"
+  case 44:
+#line 295 "parse-gram.y"
     { current_type = NULL; }
     break;
 
-  case 44:
-#line 288 "parse-gram.y"
+  case 45:
+#line 296 "parse-gram.y"
     { current_type = yyvsp[0].uniqstr; }
     break;
 
-  case 45:
-#line 294 "parse-gram.y"
+  case 46:
+#line 302 "parse-gram.y"
     { yyval.list = symbol_list_new (yyvsp[0].symbol, yylsp[0]); }
     break;
 
-  case 46:
-#line 295 "parse-gram.y"
+  case 47:
+#line 303 "parse-gram.y"
     { yyval.list = symbol_list_prepend (yyvsp[-1].list, yyvsp[0].symbol, yylsp[0]); }
     break;
 
-  case 47:
-#line 301 "parse-gram.y"
+  case 48:
+#line 309 "parse-gram.y"
     {
        current_type = yyvsp[0].uniqstr;
      }
     break;
 
-  case 48:
-#line 305 "parse-gram.y"
+  case 49:
+#line 313 "parse-gram.y"
     {
        symbol_class_set (yyvsp[0].symbol, current_class, yylsp[0]);
        symbol_type_set (yyvsp[0].symbol, current_type, yylsp[0]);
      }
     break;
 
-  case 49:
-#line 310 "parse-gram.y"
+  case 50:
+#line 318 "parse-gram.y"
     {
       symbol_class_set (yyvsp[-1].symbol, current_class, yylsp[-1]);
       symbol_type_set (yyvsp[-1].symbol, current_type, yylsp[-1]);
@@ -1528,8 +1540,8 @@ yyreduce:
     }
     break;
 
-  case 50:
-#line 316 "parse-gram.y"
+  case 51:
+#line 324 "parse-gram.y"
     {
       symbol_class_set (yyvsp[-1].symbol, current_class, yylsp[-1]);
       symbol_type_set (yyvsp[-1].symbol, current_type, yylsp[-1]);
@@ -1537,8 +1549,8 @@ yyreduce:
     }
     break;
 
-  case 51:
-#line 322 "parse-gram.y"
+  case 52:
+#line 330 "parse-gram.y"
     {
       symbol_class_set (yyvsp[-2].symbol, current_class, yylsp[-2]);
       symbol_type_set (yyvsp[-2].symbol, current_type, yylsp[-2]);
@@ -1547,99 +1559,99 @@ yyreduce:
     }
     break;
 
-  case 57:
-#line 351 "parse-gram.y"
+  case 58:
+#line 359 "parse-gram.y"
     {
       if (yacc_flag)
 	complain_at (yyloc, _("POSIX forbids declarations in the grammar"));
     }
     break;
 
-  case 58:
-#line 356 "parse-gram.y"
+  case 59:
+#line 364 "parse-gram.y"
     {
       yyerrok;
     }
     break;
 
-  case 59:
-#line 362 "parse-gram.y"
+  case 60:
+#line 370 "parse-gram.y"
     { current_lhs = yyvsp[0].symbol; current_lhs_location = yylsp[0]; }
     break;
 
-  case 61:
-#line 366 "parse-gram.y"
+  case 62:
+#line 374 "parse-gram.y"
     { grammar_rule_end (yylsp[0]); }
     break;
 
-  case 62:
-#line 367 "parse-gram.y"
+  case 63:
+#line 375 "parse-gram.y"
     { grammar_rule_end (yylsp[0]); }
     break;
 
-  case 64:
-#line 373 "parse-gram.y"
+  case 65:
+#line 381 "parse-gram.y"
     { grammar_rule_begin (current_lhs, current_lhs_location); }
     break;
 
-  case 65:
-#line 375 "parse-gram.y"
+  case 66:
+#line 383 "parse-gram.y"
     { grammar_current_rule_symbol_append (yyvsp[0].symbol, yylsp[0]); }
     break;
 
-  case 66:
-#line 377 "parse-gram.y"
+  case 67:
+#line 385 "parse-gram.y"
     { grammar_current_rule_action_append (yyvsp[0].chars, yylsp[0]); }
     break;
 
-  case 67:
-#line 379 "parse-gram.y"
+  case 68:
+#line 387 "parse-gram.y"
     { grammar_current_rule_prec_set (yyvsp[0].symbol, yylsp[0]); }
     break;
 
-  case 68:
-#line 381 "parse-gram.y"
+  case 69:
+#line 389 "parse-gram.y"
     { grammar_current_rule_dprec_set (yyvsp[0].integer, yylsp[0]); }
     break;
 
-  case 69:
-#line 383 "parse-gram.y"
+  case 70:
+#line 391 "parse-gram.y"
     { grammar_current_rule_merge_set (yyvsp[0].uniqstr, yylsp[0]); }
     break;
 
-  case 70:
-#line 387 "parse-gram.y"
+  case 71:
+#line 395 "parse-gram.y"
     { yyval.symbol = yyvsp[0].symbol; }
     break;
 
-  case 71:
-#line 388 "parse-gram.y"
+  case 72:
+#line 396 "parse-gram.y"
     { yyval.symbol = yyvsp[0].symbol; }
     break;
 
-  case 72:
-#line 393 "parse-gram.y"
+  case 73:
+#line 401 "parse-gram.y"
     { yyval.chars = yyvsp[0].chars; }
     break;
 
-  case 73:
-#line 399 "parse-gram.y"
+  case 74:
+#line 407 "parse-gram.y"
     {
       yyval.symbol = symbol_get (yyvsp[0].chars, yylsp[0]);
       symbol_class_set (yyval.symbol, token_sym, yylsp[0]);
     }
     break;
 
-  case 74:
-#line 408 "parse-gram.y"
+  case 75:
+#line 416 "parse-gram.y"
     {
       yyval.chars = yyvsp[0].chars + 1;
       yyval.chars[strlen (yyval.chars) - 1] = '\0';
     }
     break;
 
-  case 76:
-#line 417 "parse-gram.y"
+  case 77:
+#line 425 "parse-gram.y"
     {
       muscle_code_grow ("epilogue", yyvsp[0].chars, yylsp[0]);
       scanner_last_string_free ();
@@ -1650,7 +1662,7 @@ yyreduce:
     }
 
 /* Line 1010 of yacc.c.  */
-#line 1654 "parse-gram.c"
+#line 1666 "parse-gram.c"
 
   yyvsp -= yylen;
   yyssp -= yylen;
@@ -1879,7 +1891,7 @@ yyreturn:
 }
 
 
-#line 423 "parse-gram.y"
+#line 431 "parse-gram.y"
 
 
 
