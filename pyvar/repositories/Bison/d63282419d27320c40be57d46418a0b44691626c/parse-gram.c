@@ -83,33 +83,34 @@
      PERCENT_DEFINES = 275,
      PERCENT_ERROR_VERBOSE = 276,
      PERCENT_EXPECT = 277,
-     PERCENT_FILE_PREFIX = 278,
-     PERCENT_GLR_PARSER = 279,
-     PERCENT_INITIAL_ACTION = 280,
-     PERCENT_LEX_PARAM = 281,
-     PERCENT_LOCATIONS = 282,
-     PERCENT_NAME_PREFIX = 283,
-     PERCENT_NO_DEFAULT_PREC = 284,
-     PERCENT_NO_LINES = 285,
-     PERCENT_NONDETERMINISTIC_PARSER = 286,
-     PERCENT_OUTPUT = 287,
-     PERCENT_PARSE_PARAM = 288,
-     PERCENT_PURE_PARSER = 289,
-     PERCENT_SKELETON = 290,
-     PERCENT_START = 291,
-     PERCENT_TOKEN_TABLE = 292,
-     PERCENT_VERBOSE = 293,
-     PERCENT_YACC = 294,
-     TYPE = 295,
-     EQUAL = 296,
-     SEMICOLON = 297,
-     PIPE = 298,
-     ID = 299,
-     ID_COLON = 300,
-     PERCENT_PERCENT = 301,
-     PROLOGUE = 302,
-     EPILOGUE = 303,
-     BRACED_CODE = 304
+     PERCENT_EXPECT_RR = 278,
+     PERCENT_FILE_PREFIX = 279,
+     PERCENT_GLR_PARSER = 280,
+     PERCENT_INITIAL_ACTION = 281,
+     PERCENT_LEX_PARAM = 282,
+     PERCENT_LOCATIONS = 283,
+     PERCENT_NAME_PREFIX = 284,
+     PERCENT_NO_DEFAULT_PREC = 285,
+     PERCENT_NO_LINES = 286,
+     PERCENT_NONDETERMINISTIC_PARSER = 287,
+     PERCENT_OUTPUT = 288,
+     PERCENT_PARSE_PARAM = 289,
+     PERCENT_PURE_PARSER = 290,
+     PERCENT_SKELETON = 291,
+     PERCENT_START = 292,
+     PERCENT_TOKEN_TABLE = 293,
+     PERCENT_VERBOSE = 294,
+     PERCENT_YACC = 295,
+     TYPE = 296,
+     EQUAL = 297,
+     SEMICOLON = 298,
+     PIPE = 299,
+     ID = 300,
+     ID_COLON = 301,
+     PERCENT_PERCENT = 302,
+     PROLOGUE = 303,
+     EPILOGUE = 304,
+     BRACED_CODE = 305
    };
 #endif
 #define GRAM_EOF 0
@@ -133,39 +134,40 @@
 #define PERCENT_DEFINES 275
 #define PERCENT_ERROR_VERBOSE 276
 #define PERCENT_EXPECT 277
-#define PERCENT_FILE_PREFIX 278
-#define PERCENT_GLR_PARSER 279
-#define PERCENT_INITIAL_ACTION 280
-#define PERCENT_LEX_PARAM 281
-#define PERCENT_LOCATIONS 282
-#define PERCENT_NAME_PREFIX 283
-#define PERCENT_NO_DEFAULT_PREC 284
-#define PERCENT_NO_LINES 285
-#define PERCENT_NONDETERMINISTIC_PARSER 286
-#define PERCENT_OUTPUT 287
-#define PERCENT_PARSE_PARAM 288
-#define PERCENT_PURE_PARSER 289
-#define PERCENT_SKELETON 290
-#define PERCENT_START 291
-#define PERCENT_TOKEN_TABLE 292
-#define PERCENT_VERBOSE 293
-#define PERCENT_YACC 294
-#define TYPE 295
-#define EQUAL 296
-#define SEMICOLON 297
-#define PIPE 298
-#define ID 299
-#define ID_COLON 300
-#define PERCENT_PERCENT 301
-#define PROLOGUE 302
-#define EPILOGUE 303
-#define BRACED_CODE 304
+#define PERCENT_EXPECT_RR 278
+#define PERCENT_FILE_PREFIX 279
+#define PERCENT_GLR_PARSER 280
+#define PERCENT_INITIAL_ACTION 281
+#define PERCENT_LEX_PARAM 282
+#define PERCENT_LOCATIONS 283
+#define PERCENT_NAME_PREFIX 284
+#define PERCENT_NO_DEFAULT_PREC 285
+#define PERCENT_NO_LINES 286
+#define PERCENT_NONDETERMINISTIC_PARSER 287
+#define PERCENT_OUTPUT 288
+#define PERCENT_PARSE_PARAM 289
+#define PERCENT_PURE_PARSER 290
+#define PERCENT_SKELETON 291
+#define PERCENT_START 292
+#define PERCENT_TOKEN_TABLE 293
+#define PERCENT_VERBOSE 294
+#define PERCENT_YACC 295
+#define TYPE 296
+#define EQUAL 297
+#define SEMICOLON 298
+#define PIPE 299
+#define ID 300
+#define ID_COLON 301
+#define PERCENT_PERCENT 302
+#define PROLOGUE 303
+#define EPILOGUE 304
+#define BRACED_CODE 305
 
 
 
 
 /* Copy the first part of user declarations.  */
-#line 32 "parse-gram.y"
+#line 32 "../../src/parse-gram.y"
 
 #include "system.h"
 
@@ -217,7 +219,7 @@ int current_prec = 0;
 #endif
 
 #if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
-#line 80 "parse-gram.y"
+#line 80 "../../src/parse-gram.y"
 typedef union YYSTYPE {
   symbol *symbol;
   symbol_list *list;
@@ -227,7 +229,7 @@ typedef union YYSTYPE {
   uniqstr uniqstr;
 } YYSTYPE;
 /* Line 191 of yacc.c.  */
-#line 231 "parse-gram.c"
+#line 233 "../../src/parse-gram.c"
 # define yystype YYSTYPE /* obsolescent; will be withdrawn */
 # define YYSTYPE_IS_DECLARED 1
 # define YYSTYPE_IS_TRIVIAL 1
@@ -251,7 +253,7 @@ typedef struct YYLTYPE
 
 
 /* Line 214 of yacc.c.  */
-#line 255 "parse-gram.c"
+#line 257 "../../src/parse-gram.c"
 
 #if ! defined (yyoverflow) || YYERROR_VERBOSE
 
@@ -359,20 +361,20 @@ union yyalloc
 /* YYFINAL -- State number of the termination state. */
 #define YYFINAL  3
 /* YYLAST -- Last index in YYTABLE.  */
-#define YYLAST   156
+#define YYLAST   158
 
 /* YYNTOKENS -- Number of terminals. */
-#define YYNTOKENS  50
+#define YYNTOKENS  51
 /* YYNNTS -- Number of nonterminals. */
 #define YYNNTS  25
 /* YYNRULES -- Number of rules. */
-#define YYNRULES  78
+#define YYNRULES  79
 /* YYNRULES -- Number of states. */
-#define YYNSTATES  106
+#define YYNSTATES  108
 
 /* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
 #define YYUNDEFTOK  2
-#define YYMAXUTOK   304
+#define YYMAXUTOK   305
 
 #define YYTRANSLATE(YYX) 						\
   ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)
@@ -410,7 +412,7 @@ static const unsigned char yytranslate[] =
       15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
       25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
       35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
-      45,    46,    47,    48,    49
+      45,    46,    47,    48,    49,    50
 };
 
 #if YYDEBUG
@@ -419,51 +421,52 @@ static const unsigned char yytranslate[] =
 static const unsigned char yyprhs[] =
 {
        0,     0,     3,     8,     9,    12,    14,    16,    18,    22,
-      24,    26,    29,    33,    35,    37,    39,    41,    45,    47,
-      49,    53,    55,    57,    60,    62,    64,    66,    68,    70,
-      72,    75,    77,    80,    83,    85,    87,    88,    92,    93,
-      97,   101,   105,   107,   109,   111,   112,   114,   116,   119,
-     121,   123,   126,   129,   133,   135,   138,   140,   143,   145,
-     148,   151,   152,   156,   158,   162,   165,   166,   169,   172,
-     176,   180,   184,   186,   188,   190,   192,   194,   195
+      24,    26,    29,    32,    36,    38,    40,    42,    44,    48,
+      50,    52,    56,    58,    60,    63,    65,    67,    69,    71,
+      73,    75,    78,    80,    83,    86,    88,    90,    91,    95,
+      96,   100,   104,   108,   110,   112,   114,   115,   117,   119,
+     122,   124,   126,   129,   132,   136,   138,   141,   143,   146,
+     148,   151,   154,   155,   159,   161,   165,   168,   169,   172,
+     175,   179,   183,   187,   189,   191,   193,   195,   197,   198
 };
 
 /* YYRHS -- A `-1'-separated list of the rules' RHS. */
 static const yysigned_char yyrhs[] =
 {
-      51,     0,    -1,    52,    46,    64,    74,    -1,    -1,    52,
-      53,    -1,    54,    -1,    47,    -1,    17,    -1,    19,    73,
-      73,    -1,    20,    -1,    21,    -1,    22,     4,    -1,    23,
-      41,    73,    -1,    24,    -1,    25,    -1,    26,    -1,    27,
-      -1,    28,    41,    73,    -1,    30,    -1,    31,    -1,    32,
-      41,    73,    -1,    33,    -1,    34,    -1,    35,    73,    -1,
-      37,    -1,    38,    -1,    39,    -1,    42,    -1,    58,    -1,
-      55,    -1,    36,    70,    -1,    10,    -1,     8,    61,    -1,
-       9,    61,    -1,    18,    -1,    29,    -1,    -1,     6,    56,
-      63,    -1,    -1,     5,    57,    63,    -1,     7,    40,    61,
-      -1,    59,    60,    61,    -1,    11,    -1,    12,    -1,    13,
-      -1,    -1,    40,    -1,    70,    -1,    61,    70,    -1,    40,
-      -1,    44,    -1,    44,     4,    -1,    44,    72,    -1,    44,
-       4,    72,    -1,    62,    -1,    63,    62,    -1,    65,    -1,
-      64,    65,    -1,    66,    -1,    54,    42,    -1,     1,    42,
-      -1,    -1,    45,    67,    68,    -1,    69,    -1,    68,    43,
-      69,    -1,    68,    42,    -1,    -1,    69,    70,    -1,    69,
-      71,    -1,    69,    14,    70,    -1,    69,    15,     4,    -1,
-      69,    16,    40,    -1,    44,    -1,    72,    -1,    49,    -1,
-       3,    -1,     3,    -1,    -1,    46,    48,    -1
+      52,     0,    -1,    53,    47,    65,    75,    -1,    -1,    53,
+      54,    -1,    55,    -1,    48,    -1,    17,    -1,    19,    74,
+      74,    -1,    20,    -1,    21,    -1,    22,     4,    -1,    23,
+       4,    -1,    24,    42,    74,    -1,    25,    -1,    26,    -1,
+      27,    -1,    28,    -1,    29,    42,    74,    -1,    31,    -1,
+      32,    -1,    33,    42,    74,    -1,    34,    -1,    35,    -1,
+      36,    74,    -1,    38,    -1,    39,    -1,    40,    -1,    43,
+      -1,    59,    -1,    56,    -1,    37,    71,    -1,    10,    -1,
+       8,    62,    -1,     9,    62,    -1,    18,    -1,    30,    -1,
+      -1,     6,    57,    64,    -1,    -1,     5,    58,    64,    -1,
+       7,    41,    62,    -1,    60,    61,    62,    -1,    11,    -1,
+      12,    -1,    13,    -1,    -1,    41,    -1,    71,    -1,    62,
+      71,    -1,    41,    -1,    45,    -1,    45,     4,    -1,    45,
+      73,    -1,    45,     4,    73,    -1,    63,    -1,    64,    63,
+      -1,    66,    -1,    65,    66,    -1,    67,    -1,    55,    43,
+      -1,     1,    43,    -1,    -1,    46,    68,    69,    -1,    70,
+      -1,    69,    44,    70,    -1,    69,    43,    -1,    -1,    70,
+      71,    -1,    70,    72,    -1,    70,    14,    71,    -1,    70,
+      15,     4,    -1,    70,    16,    41,    -1,    45,    -1,    73,
+      -1,    50,    -1,     3,    -1,     3,    -1,    -1,    47,    49,
+      -1
 };
 
 /* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
 static const unsigned short yyrline[] =
 {
-       0,   172,   172,   180,   182,   186,   187,   188,   189,   190,
-     191,   192,   193,   194,   199,   203,   204,   205,   206,   207,
-     208,   209,   210,   211,   212,   213,   214,   215,   219,   220,
-     221,   225,   231,   238,   245,   249,   256,   256,   261,   261,
-     266,   276,   291,   292,   293,   297,   298,   304,   305,   310,
-     314,   319,   325,   331,   342,   343,   352,   353,   359,   360,
-     365,   372,   372,   376,   377,   378,   383,   384,   386,   388,
-     390,   392,   397,   398,   402,   408,   417,   424,   426
+       0,   173,   173,   181,   183,   187,   188,   189,   190,   191,
+     192,   193,   194,   195,   196,   201,   205,   206,   207,   208,
+     209,   210,   211,   212,   213,   214,   215,   216,   217,   221,
+     222,   223,   227,   233,   240,   247,   251,   258,   258,   263,
+     263,   268,   278,   293,   294,   295,   299,   300,   306,   307,
+     312,   316,   321,   327,   333,   344,   345,   354,   355,   361,
+     362,   367,   374,   374,   378,   379,   380,   385,   386,   388,
+     390,   392,   394,   399,   400,   404,   410,   419,   426,   428
 };
 #endif
 
@@ -477,7 +480,7 @@ static const char *const yytname[] =
   "\"%printer {...}\"", "\"%union {...}\"", "\"%left\"", "\"%right\"",
   "\"%nonassoc\"", "\"%prec\"", "\"%dprec\"", "\"%merge\"", "\"%debug\"",
   "\"%default-prec\"", "\"%define\"", "\"%defines\"", "\"%error-verbose\"",
-  "\"%expect\"", "\"%file-prefix\"", "\"%glr-parser\"",
+  "\"%expect\"", "\"%expect-rr\"", "\"%file-prefix\"", "\"%glr-parser\"",
   "\"%initial-action {...}\"", "\"%lex-param {...}\"", "\"%locations\"",
   "\"%name-prefix\"", "\"%no-default-prec\"", "\"%no-lines\"",
   "\"%nondeterministic-parser\"", "\"%output\"", "\"%parse-param {...}\"",
@@ -502,34 +505,35 @@ static const unsigned short yytoknum[] =
      265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
      275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
      285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
-     295,   296,   297,   298,   299,   300,   301,   302,   303,   304
+     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
+     305
 };
 # endif
 
 /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
 static const unsigned char yyr1[] =
 {
-       0,    50,    51,    52,    52,    53,    53,    53,    53,    53,
-      53,    53,    53,    53,    53,    53,    53,    53,    53,    53,
-      53,    53,    53,    53,    53,    53,    53,    53,    54,    54,
-      54,    54,    54,    54,    54,    54,    56,    55,    57,    55,
-      55,    58,    59,    59,    59,    60,    60,    61,    61,    62,
-      62,    62,    62,    62,    63,    63,    64,    64,    65,    65,
-      65,    67,    66,    68,    68,    68,    69,    69,    69,    69,
-      69,    69,    70,    70,    71,    72,    73,    74,    74
+       0,    51,    52,    53,    53,    54,    54,    54,    54,    54,
+      54,    54,    54,    54,    54,    54,    54,    54,    54,    54,
+      54,    54,    54,    54,    54,    54,    54,    54,    54,    55,
+      55,    55,    55,    55,    55,    55,    55,    57,    56,    58,
+      56,    56,    59,    60,    60,    60,    61,    61,    62,    62,
+      63,    63,    63,    63,    63,    64,    64,    65,    65,    66,
+      66,    66,    68,    67,    69,    69,    69,    70,    70,    70,
+      70,    70,    70,    71,    71,    72,    73,    74,    75,    75
 };
 
 /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
 static const unsigned char yyr2[] =
 {
        0,     2,     4,     0,     2,     1,     1,     1,     3,     1,
-       1,     2,     3,     1,     1,     1,     1,     3,     1,     1,
-       3,     1,     1,     2,     1,     1,     1,     1,     1,     1,
-       2,     1,     2,     2,     1,     1,     0,     3,     0,     3,
-       3,     3,     1,     1,     1,     0,     1,     1,     2,     1,
-       1,     2,     2,     3,     1,     2,     1,     2,     1,     2,
-       2,     0,     3,     1,     3,     2,     0,     2,     2,     3,
-       3,     3,     1,     1,     1,     1,     1,     0,     2
+       1,     2,     2,     3,     1,     1,     1,     1,     3,     1,
+       1,     3,     1,     1,     2,     1,     1,     1,     1,     1,
+       1,     2,     1,     2,     2,     1,     1,     0,     3,     0,
+       3,     3,     3,     1,     1,     1,     0,     1,     1,     2,
+       1,     1,     2,     2,     3,     1,     2,     1,     2,     1,
+       2,     2,     0,     3,     1,     3,     2,     0,     2,     2,
+       3,     3,     3,     1,     1,     1,     1,     1,     0,     2
 };
 
 /* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
@@ -537,25 +541,25 @@ static const unsigned char yyr2[] =
    means the default is an error.  */
 static const unsigned char yydefact[] =
 {
-       3,     0,     0,     1,    38,    36,     0,     0,     0,    31,
-      42,    43,    44,     7,    34,     0,     9,    10,     0,     0,
-      13,    14,    15,    16,     0,    35,    18,    19,     0,    21,
-      22,     0,     0,    24,    25,    26,    27,     0,     6,     4,
-       5,    29,    28,    45,     0,     0,     0,    75,    72,    32,
-      47,    73,    33,    76,     0,    11,     0,     0,     0,    23,
-      30,     0,    61,     0,     0,    56,    58,    46,     0,    49,
-      50,    54,    39,    37,    40,    48,     8,    12,    17,    20,
-      60,    66,    59,     0,    57,     2,    41,    51,    52,    55,
-      62,    63,    78,    53,    65,    66,     0,     0,     0,    74,
-      67,    68,    64,    69,    70,    71
+       3,     0,     0,     1,    39,    37,     0,     0,     0,    32,
+      43,    44,    45,     7,    35,     0,     9,    10,     0,     0,
+       0,    14,    15,    16,    17,     0,    36,    19,    20,     0,
+      22,    23,     0,     0,    25,    26,    27,    28,     0,     6,
+       4,     5,    30,    29,    46,     0,     0,     0,    76,    73,
+      33,    48,    74,    34,    77,     0,    11,    12,     0,     0,
+       0,    24,    31,     0,    62,     0,     0,    57,    59,    47,
+       0,    50,    51,    55,    40,    38,    41,    49,     8,    13,
+      18,    21,    61,    67,    60,     0,    58,     2,    42,    52,
+      53,    56,    63,    64,    79,    54,    66,    67,     0,     0,
+       0,    75,    68,    69,    65,    70,    71,    72
 };
 
 /* YYDEFGOTO[NTERM-NUM]. */
 static const yysigned_char yydefgoto[] =
 {
-      -1,     1,     2,    39,    63,    41,    45,    44,    42,    43,
-      68,    49,    71,    72,    64,    65,    66,    81,    90,    91,
-      50,   101,    51,    54,    85
+      -1,     1,     2,    40,    65,    42,    46,    45,    43,    44,
+      70,    50,    73,    74,    66,    67,    68,    83,    92,    93,
+      51,   103,    52,    55,    87
 };
 
 /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
@@ -563,87 +567,87 @@ static const yysigned_char yydefgoto[] =
 #define YYPACT_NINF -67
 static const yysigned_char yypact[] =
 {
-     -67,     8,   109,   -67,   -67,   -67,   -30,     0,     0,   -67,
-     -67,   -67,   -67,   -67,   -67,    13,   -67,   -67,    20,   -16,
-     -67,   -67,   -67,   -67,   -15,   -67,   -67,   -67,    -5,   -67,
-     -67,    13,     0,   -67,   -67,   -67,   -67,    68,   -67,   -67,
-     -67,   -67,   -67,    -3,   -35,   -35,     0,   -67,   -67,     0,
-     -67,   -67,     0,   -67,    13,   -67,    13,    13,    13,   -67,
-     -67,    -4,   -67,     4,    22,   -67,   -67,   -67,     0,   -67,
-       3,   -67,   -35,   -35,     0,   -67,   -67,   -67,   -67,   -67,
-     -67,   -67,   -67,     1,   -67,   -67,     0,    38,   -67,   -67,
-     -31,    -1,   -67,   -67,   -67,   -67,     0,    41,     7,   -67,
-     -67,   -67,    -1,   -67,   -67,   -67
+     -67,     5,   110,   -67,   -67,   -67,   -34,     0,     0,   -67,
+     -67,   -67,   -67,   -67,   -67,    13,   -67,   -67,    20,    31,
+     -17,   -67,   -67,   -67,   -67,    -6,   -67,   -67,   -67,    -5,
+     -67,   -67,    13,     0,   -67,   -67,   -67,   -67,    68,   -67,
+     -67,   -67,   -67,   -67,    -3,   -37,   -37,     0,   -67,   -67,
+       0,   -67,   -67,     0,   -67,    13,   -67,   -67,    13,    13,
+      13,   -67,   -67,    -2,   -67,     3,    21,   -67,   -67,   -67,
+       0,   -67,     6,   -67,   -37,   -37,     0,   -67,   -67,   -67,
+     -67,   -67,   -67,   -67,   -67,     1,   -67,   -67,     0,    39,
+     -67,   -67,   -32,    -1,   -67,   -67,   -67,   -67,     0,    43,
+       7,   -67,   -67,   -67,    -1,   -67,   -67,   -67
 };
 
 /* YYPGOTO[NTERM-NUM].  */
 static const yysigned_char yypgoto[] =
 {
-     -67,   -67,   -67,   -67,    48,   -67,   -67,   -67,   -67,   -67,
-     -67,    -7,   -54,    10,   -67,   -12,   -67,   -67,   -67,   -42,
-     -32,   -67,   -66,    31,   -67
+     -67,   -67,   -67,   -67,    50,   -67,   -67,   -67,   -67,   -67,
+     -67,    -7,   -56,     8,   -67,   -13,   -67,   -67,   -67,   -41,
+     -33,   -67,   -66,    29,   -67
 };
 
 /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
    positive, shift that token.  If negative, reduce the rule which
    number is the opposite.  If zero, do what YYDEFACT says.
    If YYTABLE_NINF, syntax error.  */
-#define YYTABLE_NINF -78
+#define YYTABLE_NINF -79
 static const yysigned_char yytable[] =
 {
-      60,    52,    47,    47,    88,    69,    47,    87,     3,    70,
-      46,    94,    95,    96,    97,    98,    53,    75,    89,    89,
-      75,    93,   -77,    61,    55,    56,    57,     4,     5,     6,
-       7,     8,     9,    10,    11,    12,    58,    67,    80,    74,
-      14,    47,    75,    48,    48,   104,    82,   105,    99,    92,
-      40,    25,    84,   102,    75,    73,     0,     0,    32,   100,
-       0,    86,    59,     0,   103,     0,     0,    62,    83,    61,
-     100,     0,     0,     4,     5,     6,     7,     8,     9,    10,
-      11,    12,     0,     0,     0,    76,    14,    77,    78,    79,
-       0,     0,     0,     0,     0,     0,     0,    25,     0,     0,
-       0,     0,     0,     0,    32,     0,     0,     0,     0,     0,
-       0,     0,     0,    62,     4,     5,     6,     7,     8,     9,
-      10,    11,    12,     0,     0,     0,    13,    14,    15,    16,
-      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
-      27,    28,    29,    30,    31,    32,    33,    34,    35,     0,
-       0,    36,     0,     0,     0,    37,    38
+      62,    53,    48,    48,    71,     3,    90,    47,    72,    48,
+      89,    96,    97,    98,    99,   100,    54,    77,    91,    91,
+      77,   -78,    63,    95,    56,    58,     4,     5,     6,     7,
+       8,     9,    10,    11,    12,    57,    59,    60,    69,    14,
+      76,    82,    48,    77,    49,    49,    84,   106,   107,   101,
+      94,    26,    41,    86,    75,    77,   104,     0,    33,     0,
+     102,    61,     0,    88,     0,   105,     0,    64,    85,    63,
+       0,   102,     0,     4,     5,     6,     7,     8,     9,    10,
+      11,    12,     0,     0,    78,     0,    14,    79,    80,    81,
+       0,     0,     0,     0,     0,     0,     0,     0,    26,     0,
+       0,     0,     0,     0,     0,    33,     0,     0,     0,     0,
+       0,     0,     0,     0,    64,     4,     5,     6,     7,     8,
+       9,    10,    11,    12,     0,     0,     0,    13,    14,    15,
+      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
+      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
+      36,     0,     0,    37,     0,     0,     0,    38,    39
 };
 
 static const yysigned_char yycheck[] =
 {
-      32,     8,     3,     3,    70,    40,     3,     4,     0,    44,
-      40,    42,    43,    14,    15,    16,     3,    49,    72,    73,
-      52,    87,     0,     1,     4,    41,    41,     5,     6,     7,
-       8,     9,    10,    11,    12,    13,    41,    40,    42,    46,
-      18,     3,    74,    44,    44,     4,    42,    40,    49,    48,
-       2,    29,    64,    95,    86,    45,    -1,    -1,    36,    91,
-      -1,    68,    31,    -1,    96,    -1,    -1,    45,    46,     1,
-     102,    -1,    -1,     5,     6,     7,     8,     9,    10,    11,
-      12,    13,    -1,    -1,    -1,    54,    18,    56,    57,    58,
-      -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,    -1,    -1,
-      -1,    -1,    -1,    -1,    36,    -1,    -1,    -1,    -1,    -1,
-      -1,    -1,    -1,    45,     5,     6,     7,     8,     9,    10,
-      11,    12,    13,    -1,    -1,    -1,    17,    18,    19,    20,
-      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
-      31,    32,    33,    34,    35,    36,    37,    38,    39,    -1,
-      -1,    42,    -1,    -1,    -1,    46,    47
+      33,     8,     3,     3,    41,     0,    72,    41,    45,     3,
+       4,    43,    44,    14,    15,    16,     3,    50,    74,    75,
+      53,     0,     1,    89,     4,    42,     5,     6,     7,     8,
+       9,    10,    11,    12,    13,     4,    42,    42,    41,    18,
+      47,    43,     3,    76,    45,    45,    43,     4,    41,    50,
+      49,    30,     2,    66,    46,    88,    97,    -1,    37,    -1,
+      93,    32,    -1,    70,    -1,    98,    -1,    46,    47,     1,
+      -1,   104,    -1,     5,     6,     7,     8,     9,    10,    11,
+      12,    13,    -1,    -1,    55,    -1,    18,    58,    59,    60,
+      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,
+      -1,    -1,    -1,    -1,    -1,    37,    -1,    -1,    -1,    -1,
+      -1,    -1,    -1,    -1,    46,     5,     6,     7,     8,     9,
+      10,    11,    12,    13,    -1,    -1,    -1,    17,    18,    19,
+      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
+      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
+      40,    -1,    -1,    43,    -1,    -1,    -1,    47,    48
 };
 
 /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
    symbol of state STATE-NUM.  */
 static const unsigned char yystos[] =
 {
-       0,    51,    52,     0,     5,     6,     7,     8,     9,    10,
+       0,    52,    53,     0,     5,     6,     7,     8,     9,    10,
       11,    12,    13,    17,    18,    19,    20,    21,    22,    23,
       24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
-      34,    35,    36,    37,    38,    39,    42,    46,    47,    53,
-      54,    55,    58,    59,    57,    56,    40,     3,    44,    61,
-      70,    72,    61,     3,    73,     4,    41,    41,    41,    73,
-      70,     1,    45,    54,    64,    65,    66,    40,    60,    40,
-      44,    62,    63,    63,    61,    70,    73,    73,    73,    73,
-      42,    67,    42,    46,    65,    74,    61,     4,    72,    62,
-      68,    69,    48,    72,    42,    43,    14,    15,    16,    49,
-      70,    71,    69,    70,     4,    40
+      34,    35,    36,    37,    38,    39,    40,    43,    47,    48,
+      54,    55,    56,    59,    60,    58,    57,    41,     3,    45,
+      62,    71,    73,    62,     3,    74,     4,     4,    42,    42,
+      42,    74,    71,     1,    46,    55,    65,    66,    67,    41,
+      61,    41,    45,    63,    64,    64,    62,    71,    74,    74,
+      74,    74,    43,    68,    43,    47,    66,    75,    62,     4,
+      73,    63,    69,    70,    49,    73,    43,    44,    14,    15,
+      16,    50,    71,    72,    70,    71,     4,    41
 };
 
 #if ! defined (YYSIZE_T) && defined (__SIZE_TYPE__)
@@ -1080,7 +1084,7 @@ YYLTYPE yylloc;
   yylsp = yyls;
 
   /* User initialization code. */
-  #line 70 "parse-gram.y"
+  #line 70 "../../src/parse-gram.y"
 {
   /* Bison's grammar can initial empty locations, hence a default
      location is needed. */
@@ -1089,7 +1093,7 @@ YYLTYPE yylloc;
   (*yylsp).start.column = (*yylsp).end.column = 0;
 }
 /* Line 818 of yacc.c.  */
-#line 1093 "parse-gram.c"
+#line 1097 "../../src/parse-gram.c"
   goto yysetstate;
 
 /*------------------------------------------------------------.
@@ -1277,124 +1281,129 @@ yyreduce:
   switch (yyn)
     {
         case 6:
-#line 187 "parse-gram.y"
+#line 188 "../../src/parse-gram.y"
     { prologue_augment (yyvsp[0].chars, yylsp[0]); }
     break;
 
   case 7:
-#line 188 "parse-gram.y"
+#line 189 "../../src/parse-gram.y"
     { debug_flag = true; }
     break;
 
   case 8:
-#line 189 "parse-gram.y"
+#line 190 "../../src/parse-gram.y"
     { muscle_insert (yyvsp[-1].chars, yyvsp[0].chars); }
     break;
 
   case 9:
-#line 190 "parse-gram.y"
+#line 191 "../../src/parse-gram.y"
     { defines_flag = true; }
     break;
 
   case 10:
-#line 191 "parse-gram.y"
+#line 192 "../../src/parse-gram.y"
     { error_verbose = true; }
     break;
 
   case 11:
-#line 192 "parse-gram.y"
-    { expected_conflicts = yyvsp[0].integer; }
+#line 193 "../../src/parse-gram.y"
+    { expected_sr_conflicts = yyvsp[0].integer; }
     break;
 
   case 12:
-#line 193 "parse-gram.y"
-    { spec_file_prefix = yyvsp[0].chars; }
+#line 194 "../../src/parse-gram.y"
+    { expected_rr_conflicts = yyvsp[0].integer; }
     break;
 
   case 13:
-#line 195 "parse-gram.y"
+#line 195 "../../src/parse-gram.y"
+    { spec_file_prefix = yyvsp[0].chars; }
+    break;
+
+  case 14:
+#line 197 "../../src/parse-gram.y"
     {
     nondeterministic_parser = true;
     glr_parser = true;
   }
     break;
 
-  case 14:
-#line 200 "parse-gram.y"
+  case 15:
+#line 202 "../../src/parse-gram.y"
     {
     muscle_code_grow ("initial_action", yyvsp[0].chars, yylsp[0]);
   }
     break;
 
-  case 15:
-#line 203 "parse-gram.y"
+  case 16:
+#line 205 "../../src/parse-gram.y"
     { add_param ("lex_param", yyvsp[0].chars, yylsp[0]); }
     break;
 
-  case 16:
-#line 204 "parse-gram.y"
+  case 17:
+#line 206 "../../src/parse-gram.y"
     { locations_flag = true; }
     break;
 
-  case 17:
-#line 205 "parse-gram.y"
+  case 18:
+#line 207 "../../src/parse-gram.y"
     { spec_name_prefix = yyvsp[0].chars; }
     break;
 
-  case 18:
-#line 206 "parse-gram.y"
+  case 19:
+#line 208 "../../src/parse-gram.y"
     { no_lines_flag = true; }
     break;
 
-  case 19:
-#line 207 "parse-gram.y"
+  case 20:
+#line 209 "../../src/parse-gram.y"
     { nondeterministic_parser = true; }
     break;
 
-  case 20:
-#line 208 "parse-gram.y"
+  case 21:
+#line 210 "../../src/parse-gram.y"
     { spec_outfile = yyvsp[0].chars; }
     break;
 
-  case 21:
-#line 209 "parse-gram.y"
+  case 22:
+#line 211 "../../src/parse-gram.y"
     { add_param ("parse_param", yyvsp[0].chars, yylsp[0]); }
     break;
 
-  case 22:
-#line 210 "parse-gram.y"
+  case 23:
+#line 212 "../../src/parse-gram.y"
     { pure_parser = true; }
     break;
 
-  case 23:
-#line 211 "parse-gram.y"
+  case 24:
+#line 213 "../../src/parse-gram.y"
     { skeleton = yyvsp[0].chars; }
     break;
 
-  case 24:
-#line 212 "parse-gram.y"
+  case 25:
+#line 214 "../../src/parse-gram.y"
     { token_table_flag = true; }
     break;
 
-  case 25:
-#line 213 "parse-gram.y"
+  case 26:
+#line 215 "../../src/parse-gram.y"
     { report_flag = report_states; }
     break;
 
-  case 26:
-#line 214 "parse-gram.y"
+  case 27:
+#line 216 "../../src/parse-gram.y"
     { yacc_flag = true; }
     break;
 
-  case 30:
-#line 222 "parse-gram.y"
+  case 31:
+#line 224 "../../src/parse-gram.y"
     {
       grammar_start_symbol_set (yyvsp[0].symbol, yylsp[0]);
     }
     break;
 
-  case 31:
-#line 226 "parse-gram.y"
+  case 32:
+#line 228 "../../src/parse-gram.y"
     {
       typed = true;
       MUSCLE_INSERT_INT ("stype_line", yylsp[0].start.line);
@@ -1402,8 +1411,8 @@ yyreduce:
     }
     break;
 
-  case 32:
-#line 232 "parse-gram.y"
+  case 33:
+#line 234 "../../src/parse-gram.y"
     {
       symbol_list *list;
       for (list = yyvsp[0].list; list; list = list->next)
@@ -1412,8 +1421,8 @@ yyreduce:
     }
     break;
 
-  case 33:
-#line 239 "parse-gram.y"
+  case 34:
+#line 241 "../../src/parse-gram.y"
     {
       symbol_list *list;
       for (list = yyvsp[0].list; list; list = list->next)
@@ -1422,48 +1431,48 @@ yyreduce:
     }
     break;
 
-  case 34:
-#line 246 "parse-gram.y"
+  case 35:
+#line 248 "../../src/parse-gram.y"
     {
       default_prec = true;
     }
     break;
 
-  case 35:
-#line 250 "parse-gram.y"
+  case 36:
+#line 252 "../../src/parse-gram.y"
     {
       default_prec = false;
     }
     break;
 
-  case 36:
-#line 256 "parse-gram.y"
+  case 37:
+#line 258 "../../src/parse-gram.y"
     { current_class = nterm_sym; }
     break;
 
-  case 37:
-#line 257 "parse-gram.y"
+  case 38:
+#line 259 "../../src/parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
     break;
 
-  case 38:
-#line 261 "parse-gram.y"
+  case 39:
+#line 263 "../../src/parse-gram.y"
     { current_class = token_sym; }
     break;
 
-  case 39:
-#line 262 "parse-gram.y"
+  case 40:
+#line 264 "../../src/parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
     break;
 
-  case 40:
-#line 267 "parse-gram.y"
+  case 41:
+#line 269 "../../src/parse-gram.y"
     {
       symbol_list *list;
       for (list = yyvsp[0].list; list; list = list->next)
@@ -1472,8 +1481,8 @@ yyreduce:
     }
     break;
 
-  case 41:
-#line 277 "parse-gram.y"
+  case 42:
+#line 279 "../../src/parse-gram.y"
     {
       symbol_list *list;
       ++current_prec;
@@ -1487,58 +1496,58 @@ yyreduce:
     }
     break;
 
-  case 42:
-#line 291 "parse-gram.y"
+  case 43:
+#line 293 "../../src/parse-gram.y"
     { yyval.assoc = left_assoc; }
     break;
 
-  case 43:
-#line 292 "parse-gram.y"
+  case 44:
+#line 294 "../../src/parse-gram.y"
     { yyval.assoc = right_assoc; }
     break;
 
-  case 44:
-#line 293 "parse-gram.y"
+  case 45:
+#line 295 "../../src/parse-gram.y"
     { yyval.assoc = non_assoc; }
     break;
 
-  case 45:
-#line 297 "parse-gram.y"
+  case 46:
+#line 299 "../../src/parse-gram.y"
     { current_type = NULL; }
     break;
 
-  case 46:
-#line 298 "parse-gram.y"
+  case 47:
+#line 300 "../../src/parse-gram.y"
     { current_type = yyvsp[0].uniqstr; }
     break;
 
-  case 47:
-#line 304 "parse-gram.y"
+  case 48:
+#line 306 "../../src/parse-gram.y"
     { yyval.list = symbol_list_new (yyvsp[0].symbol, yylsp[0]); }
     break;
 
-  case 48:
-#line 305 "parse-gram.y"
+  case 49:
+#line 307 "../../src/parse-gram.y"
     { yyval.list = symbol_list_prepend (yyvsp[-1].list, yyvsp[0].symbol, yylsp[0]); }
     break;
 
-  case 49:
-#line 311 "parse-gram.y"
+  case 50:
+#line 313 "../../src/parse-gram.y"
     {
        current_type = yyvsp[0].uniqstr;
      }
     break;
 
-  case 50:
-#line 315 "parse-gram.y"
+  case 51:
+#line 317 "../../src/parse-gram.y"
     {
        symbol_class_set (yyvsp[0].symbol, current_class, yylsp[0]);
        symbol_type_set (yyvsp[0].symbol, current_type, yylsp[0]);
      }
     break;
 
-  case 51:
-#line 320 "parse-gram.y"
+  case 52:
+#line 322 "../../src/parse-gram.y"
     {
       symbol_class_set (yyvsp[-1].symbol, current_class, yylsp[-1]);
       symbol_type_set (yyvsp[-1].symbol, current_type, yylsp[-1]);
@@ -1546,8 +1555,8 @@ yyreduce:
     }
     break;
 
-  case 52:
-#line 326 "parse-gram.y"
+  case 53:
+#line 328 "../../src/parse-gram.y"
     {
       symbol_class_set (yyvsp[-1].symbol, current_class, yylsp[-1]);
       symbol_type_set (yyvsp[-1].symbol, current_type, yylsp[-1]);
@@ -1555,8 +1564,8 @@ yyreduce:
     }
     break;
 
-  case 53:
-#line 332 "parse-gram.y"
+  case 54:
+#line 334 "../../src/parse-gram.y"
     {
       symbol_class_set (yyvsp[-2].symbol, current_class, yylsp[-2]);
       symbol_type_set (yyvsp[-2].symbol, current_type, yylsp[-2]);
@@ -1565,99 +1574,99 @@ yyreduce:
     }
     break;
 
-  case 59:
-#line 361 "parse-gram.y"
+  case 60:
+#line 363 "../../src/parse-gram.y"
     {
       if (yacc_flag)
 	complain_at (yyloc, _("POSIX forbids declarations in the grammar"));
     }
     break;
 
-  case 60:
-#line 366 "parse-gram.y"
+  case 61:
+#line 368 "../../src/parse-gram.y"
     {
       yyerrok;
     }
     break;
 
-  case 61:
-#line 372 "parse-gram.y"
+  case 62:
+#line 374 "../../src/parse-gram.y"
     { current_lhs = yyvsp[0].symbol; current_lhs_location = yylsp[0]; }
     break;
 
-  case 63:
-#line 376 "parse-gram.y"
+  case 64:
+#line 378 "../../src/parse-gram.y"
     { grammar_rule_end (yylsp[0]); }
     break;
 
-  case 64:
-#line 377 "parse-gram.y"
+  case 65:
+#line 379 "../../src/parse-gram.y"
     { grammar_rule_end (yylsp[0]); }
     break;
 
-  case 66:
-#line 383 "parse-gram.y"
+  case 67:
+#line 385 "../../src/parse-gram.y"
     { grammar_rule_begin (current_lhs, current_lhs_location); }
     break;
 
-  case 67:
-#line 385 "parse-gram.y"
+  case 68:
+#line 387 "../../src/parse-gram.y"
     { grammar_current_rule_symbol_append (yyvsp[0].symbol, yylsp[0]); }
     break;
 
-  case 68:
-#line 387 "parse-gram.y"
+  case 69:
+#line 389 "../../src/parse-gram.y"
     { grammar_current_rule_action_append (yyvsp[0].chars, yylsp[0]); }
     break;
 
-  case 69:
-#line 389 "parse-gram.y"
+  case 70:
+#line 391 "../../src/parse-gram.y"
     { grammar_current_rule_prec_set (yyvsp[0].symbol, yylsp[0]); }
     break;
 
-  case 70:
-#line 391 "parse-gram.y"
+  case 71:
+#line 393 "../../src/parse-gram.y"
     { grammar_current_rule_dprec_set (yyvsp[0].integer, yylsp[0]); }
     break;
 
-  case 71:
-#line 393 "parse-gram.y"
+  case 72:
+#line 395 "../../src/parse-gram.y"
     { grammar_current_rule_merge_set (yyvsp[0].uniqstr, yylsp[0]); }
     break;
 
-  case 72:
-#line 397 "parse-gram.y"
+  case 73:
+#line 399 "../../src/parse-gram.y"
     { yyval.symbol = yyvsp[0].symbol; }
     break;
 
-  case 73:
-#line 398 "parse-gram.y"
+  case 74:
+#line 400 "../../src/parse-gram.y"
     { yyval.symbol = yyvsp[0].symbol; }
     break;
 
-  case 74:
-#line 403 "parse-gram.y"
+  case 75:
+#line 405 "../../src/parse-gram.y"
     { yyval.chars = yyvsp[0].chars; }
     break;
 
-  case 75:
-#line 409 "parse-gram.y"
+  case 76:
+#line 411 "../../src/parse-gram.y"
     {
       yyval.symbol = symbol_get (yyvsp[0].chars, yylsp[0]);
       symbol_class_set (yyval.symbol, token_sym, yylsp[0]);
     }
     break;
 
-  case 76:
-#line 418 "parse-gram.y"
+  case 77:
+#line 420 "../../src/parse-gram.y"
     {
       yyval.chars = yyvsp[0].chars + 1;
       yyval.chars[strlen (yyval.chars) - 1] = '\0';
     }
     break;
 
-  case 78:
-#line 427 "parse-gram.y"
+  case 79:
+#line 429 "../../src/parse-gram.y"
     {
       muscle_code_grow ("epilogue", yyvsp[0].chars, yylsp[0]);
       scanner_last_string_free ();
@@ -1668,7 +1677,7 @@ yyreduce:
     }
 
 /* Line 1010 of yacc.c.  */
-#line 1672 "parse-gram.c"
+#line 1681 "../../src/parse-gram.c"
 
   yyvsp -= yylen;
   yyssp -= yylen;
@@ -1897,7 +1906,7 @@ yyreturn:
 }
 
 
-#line 433 "parse-gram.y"
+#line 435 "../../src/parse-gram.y"
 
 
 
