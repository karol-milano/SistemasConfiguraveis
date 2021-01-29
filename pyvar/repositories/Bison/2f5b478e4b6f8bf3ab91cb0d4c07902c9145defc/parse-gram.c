@@ -150,7 +150,7 @@ static int current_prec = 0;
 #define YYTYPE_UINT8 uint_fast8_t
 
 /* Line 191 of yacc.c  */
-#line 154 "../bison/src/parse-gram.c"
+#line 154 "/Users/akim/src/kernel/bison/src/parse-gram.c"
 
 /* Enabling traces.  */
 #ifndef YYDEBUG
@@ -196,41 +196,42 @@ static int current_prec = 0;
      PERCENT_DEFAULT_PREC = 273,
      PERCENT_DEFINE = 274,
      PERCENT_DEFINES = 275,
-     PERCENT_EXPECT = 276,
-     PERCENT_EXPECT_RR = 277,
-     PERCENT_FLAG = 278,
-     PERCENT_FILE_PREFIX = 279,
-     PERCENT_GLR_PARSER = 280,
-     PERCENT_INITIAL_ACTION = 281,
-     PERCENT_LANGUAGE = 282,
-     PERCENT_LEX_PARAM = 283,
-     PERCENT_NAME_PREFIX = 284,
-     PERCENT_NO_DEFAULT_PREC = 285,
-     PERCENT_NO_LINES = 286,
-     PERCENT_NONDETERMINISTIC_PARSER = 287,
-     PERCENT_OUTPUT = 288,
-     PERCENT_PARSE_PARAM = 289,
-     PERCENT_REQUIRE = 290,
-     PERCENT_SKELETON = 291,
-     PERCENT_START = 292,
-     PERCENT_TOKEN_TABLE = 293,
-     PERCENT_VERBOSE = 294,
-     PERCENT_YACC = 295,
-     BRACED_CODE = 296,
-     CHAR = 297,
-     EPILOGUE = 298,
-     EQUAL = 299,
-     ID = 300,
-     ID_COLON = 301,
-     PERCENT_PERCENT = 302,
-     PIPE = 303,
-     PROLOGUE = 304,
-     SEMICOLON = 305,
-     TAG = 306,
-     TAG_ANY = 307,
-     TAG_NONE = 308,
-     BRACKETED_ID = 309,
-     PERCENT_UNION = 310
+     PERCENT_ERROR_VERBOSE = 276,
+     PERCENT_EXPECT = 277,
+     PERCENT_EXPECT_RR = 278,
+     PERCENT_FLAG = 279,
+     PERCENT_FILE_PREFIX = 280,
+     PERCENT_GLR_PARSER = 281,
+     PERCENT_INITIAL_ACTION = 282,
+     PERCENT_LANGUAGE = 283,
+     PERCENT_LEX_PARAM = 284,
+     PERCENT_NAME_PREFIX = 285,
+     PERCENT_NO_DEFAULT_PREC = 286,
+     PERCENT_NO_LINES = 287,
+     PERCENT_NONDETERMINISTIC_PARSER = 288,
+     PERCENT_OUTPUT = 289,
+     PERCENT_PARSE_PARAM = 290,
+     PERCENT_REQUIRE = 291,
+     PERCENT_SKELETON = 292,
+     PERCENT_START = 293,
+     PERCENT_TOKEN_TABLE = 294,
+     PERCENT_VERBOSE = 295,
+     PERCENT_YACC = 296,
+     BRACED_CODE = 297,
+     CHAR = 298,
+     EPILOGUE = 299,
+     EQUAL = 300,
+     ID = 301,
+     ID_COLON = 302,
+     PERCENT_PERCENT = 303,
+     PIPE = 304,
+     PROLOGUE = 305,
+     SEMICOLON = 306,
+     TAG = 307,
+     TAG_ANY = 308,
+     TAG_NONE = 309,
+     BRACKETED_ID = 310,
+     PERCENT_UNION = 311
    };
 #endif
 /* Tokens.  */
@@ -253,41 +254,42 @@ static int current_prec = 0;
 #define PERCENT_DEFAULT_PREC 273
 #define PERCENT_DEFINE 274
 #define PERCENT_DEFINES 275
-#define PERCENT_EXPECT 276
-#define PERCENT_EXPECT_RR 277
-#define PERCENT_FLAG 278
-#define PERCENT_FILE_PREFIX 279
-#define PERCENT_GLR_PARSER 280
-#define PERCENT_INITIAL_ACTION 281
-#define PERCENT_LANGUAGE 282
-#define PERCENT_LEX_PARAM 283
-#define PERCENT_NAME_PREFIX 284
-#define PERCENT_NO_DEFAULT_PREC 285
-#define PERCENT_NO_LINES 286
-#define PERCENT_NONDETERMINISTIC_PARSER 287
-#define PERCENT_OUTPUT 288
-#define PERCENT_PARSE_PARAM 289
-#define PERCENT_REQUIRE 290
-#define PERCENT_SKELETON 291
-#define PERCENT_START 292
-#define PERCENT_TOKEN_TABLE 293
-#define PERCENT_VERBOSE 294
-#define PERCENT_YACC 295
-#define BRACED_CODE 296
-#define CHAR 297
-#define EPILOGUE 298
-#define EQUAL 299
-#define ID 300
-#define ID_COLON 301
-#define PERCENT_PERCENT 302
-#define PIPE 303
-#define PROLOGUE 304
-#define SEMICOLON 305
-#define TAG 306
-#define TAG_ANY 307
-#define TAG_NONE 308
-#define BRACKETED_ID 309
-#define PERCENT_UNION 310
+#define PERCENT_ERROR_VERBOSE 276
+#define PERCENT_EXPECT 277
+#define PERCENT_EXPECT_RR 278
+#define PERCENT_FLAG 279
+#define PERCENT_FILE_PREFIX 280
+#define PERCENT_GLR_PARSER 281
+#define PERCENT_INITIAL_ACTION 282
+#define PERCENT_LANGUAGE 283
+#define PERCENT_LEX_PARAM 284
+#define PERCENT_NAME_PREFIX 285
+#define PERCENT_NO_DEFAULT_PREC 286
+#define PERCENT_NO_LINES 287
+#define PERCENT_NONDETERMINISTIC_PARSER 288
+#define PERCENT_OUTPUT 289
+#define PERCENT_PARSE_PARAM 290
+#define PERCENT_REQUIRE 291
+#define PERCENT_SKELETON 292
+#define PERCENT_START 293
+#define PERCENT_TOKEN_TABLE 294
+#define PERCENT_VERBOSE 295
+#define PERCENT_YACC 296
+#define BRACED_CODE 297
+#define CHAR 298
+#define EPILOGUE 299
+#define EQUAL 300
+#define ID 301
+#define ID_COLON 302
+#define PERCENT_PERCENT 303
+#define PIPE 304
+#define PROLOGUE 305
+#define SEMICOLON 306
+#define TAG 307
+#define TAG_ANY 308
+#define TAG_NONE 309
+#define BRACKETED_ID 310
+#define PERCENT_UNION 311
 
 
 
@@ -310,7 +312,7 @@ typedef union YYSTYPE
 
 
 /* Line 216 of yacc.c  */
-#line 314 "../bison/src/parse-gram.c"
+#line 316 "/Users/akim/src/kernel/bison/src/parse-gram.c"
 } YYSTYPE;
 # define YYSTYPE_IS_TRIVIAL 1
 # define yystype YYSTYPE /* obsolescent; will be withdrawn */
@@ -334,7 +336,7 @@ typedef struct YYLTYPE
 /* Copy the second part of user declarations.  */
 
 /* Line 266 of yacc.c  */
-#line 338 "../bison/src/parse-gram.c"
+#line 340 "/Users/akim/src/kernel/bison/src/parse-gram.c"
 
 #ifdef short
 # undef short
@@ -554,18 +556,18 @@ union yyalloc
 #define YYLAST   160
 
 /* YYNTOKENS -- Number of terminals.  */
-#define YYNTOKENS  56
+#define YYNTOKENS  57
 /* YYNNTS -- Number of nonterminals.  */
 #define YYNNTS  34
 /* YYNRULES -- Number of rules.  */
-#define YYNRULES  105
+#define YYNRULES  106
 /* YYNSTATES -- Number of states.  */
-#define YYNSTATES  145
+#define YYNSTATES  146
 
 /* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
    by yylex, with out-of-bounds checking.  */
 #define YYUNDEFTOK  2
-#define YYMAXUTOK   310
+#define YYMAXUTOK   311
 
 #define YYTRANSLATE(YYX)						\
   ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)
@@ -605,24 +607,24 @@ static const yytype_uint8 yytranslate[] =
       25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
       35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
       45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
-      55
+      55,    56
 };
 
 #if YYDEBUG
   /* YYRLINEYYN -- Source line where rule number YYN was defined.    */
 static const yytype_uint16 yyrline[] =
 {
-       0,   206,   206,   214,   216,   220,   221,   231,   235,   240,
-     241,   246,   247,   248,   249,   250,   255,   264,   265,   266,
-     267,   268,   269,   270,   271,   272,   273,   274,   298,   299,
-     300,   301,   305,   306,   307,   311,   318,   325,   329,   333,
-     340,   355,   356,   360,   372,   372,   377,   377,   382,   393,
-     408,   409,   410,   411,   415,   416,   421,   423,   428,   429,
-     434,   436,   441,   442,   446,   447,   448,   449,   454,   459,
-     464,   470,   476,   487,   488,   497,   498,   504,   505,   506,
-     513,   513,   518,   519,   520,   525,   527,   529,   531,   533,
-     535,   541,   543,   555,   556,   561,   562,   571,   591,   593,
-     602,   607,   608,   613,   620,   622
+       0,   207,   207,   215,   217,   221,   222,   232,   236,   241,
+     242,   247,   252,   253,   254,   255,   256,   261,   270,   271,
+     272,   273,   274,   275,   276,   277,   278,   279,   280,   304,
+     305,   306,   307,   311,   312,   313,   317,   324,   331,   335,
+     339,   346,   361,   362,   366,   378,   378,   383,   383,   388,
+     399,   414,   415,   416,   417,   421,   422,   427,   429,   434,
+     435,   440,   442,   447,   448,   452,   453,   454,   455,   460,
+     465,   470,   476,   482,   493,   494,   503,   504,   510,   511,
+     512,   519,   519,   524,   525,   526,   531,   533,   535,   537,
+     539,   541,   547,   549,   561,   562,   567,   568,   577,   597,
+     599,   608,   613,   614,   619,   626,   628
 };
 #endif
 
@@ -635,16 +637,16 @@ static const char *const yytname[] =
   "\"%token\"", "\"%nterm\"", "\"%type\"", "\"%destructor\"",
   "\"%printer\"", "\"%left\"", "\"%right\"", "\"%nonassoc\"",
   "\"%precedence\"", "\"%prec\"", "\"%dprec\"", "\"%merge\"", "\"%code\"",
-  "\"%default-prec\"", "\"%define\"", "\"%defines\"", "\"%expect\"",
-  "\"%expect-rr\"", "\"%<flag>\"", "\"%file-prefix\"", "\"%glr-parser\"",
-  "\"%initial-action\"", "\"%language\"", "\"%lex-param\"",
-  "\"%name-prefix\"", "\"%no-default-prec\"", "\"%no-lines\"",
-  "\"%nondeterministic-parser\"", "\"%output\"", "\"%parse-param\"",
-  "\"%require\"", "\"%skeleton\"", "\"%start\"", "\"%token-table\"",
-  "\"%verbose\"", "\"%yacc\"", "\"{...}\"", "\"char\"", "\"epilogue\"",
-  "\"=\"", "\"identifier\"", "\"identifier:\"", "\"%%\"", "\"|\"",
-  "\"%{...%}\"", "\";\"", "\"<tag>\"", "\"<*>\"", "\"<>\"", "\"[id]\"",
-  "\"%union\"", "$accept", "input", "prologue_declarations",
+  "\"%default-prec\"", "\"%define\"", "\"%defines\"", "\"%error-verbose\"",
+  "\"%expect\"", "\"%expect-rr\"", "\"%<flag>\"", "\"%file-prefix\"",
+  "\"%glr-parser\"", "\"%initial-action\"", "\"%language\"",
+  "\"%lex-param\"", "\"%name-prefix\"", "\"%no-default-prec\"",
+  "\"%no-lines\"", "\"%nondeterministic-parser\"", "\"%output\"",
+  "\"%parse-param\"", "\"%require\"", "\"%skeleton\"", "\"%start\"",
+  "\"%token-table\"", "\"%verbose\"", "\"%yacc\"", "\"{...}\"", "\"char\"",
+  "\"epilogue\"", "\"=\"", "\"identifier\"", "\"identifier:\"", "\"%%\"",
+  "\"|\"", "\"%{...%}\"", "\";\"", "\"<tag>\"", "\"<*>\"", "\"<>\"",
+  "\"[id]\"", "\"%union\"", "$accept", "input", "prologue_declarations",
   "prologue_declaration", "grammar_declaration", "union_name",
   "symbol_declaration", "$@1", "$@2", "precedence_declaration",
   "precedence_declarator", "tag.opt", "symbols.prec", "symbol.prec",
@@ -665,33 +667,33 @@ static const yytype_uint16 yytoknum[] =
      275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
      285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
      295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
-     305,   306,   307,   308,   309,   310
+     305,   306,   307,   308,   309,   310,   311
 };
 # endif
 
-#define YYPACT_NINF -56
+#define YYPACT_NINF -53
 
-#define YYTABLE_NINF -105
+#define YYTABLE_NINF -106
 
   /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
      STATE-NUM.    */
 static const yytype_int16 yypact[] =
 {
-     -56,    40,   102,   -56,   -56,   -56,    30,    19,    26,   -56,
-     -56,   -56,   -56,    -2,   -56,    13,    80,    84,    85,   -56,
-      29,   -56,    51,    90,    54,    32,   -56,   -56,   -56,    33,
-      55,    94,    96,     0,   -56,   -56,   -56,    16,   -56,   -56,
-      57,   -56,   -56,   -56,   -56,    52,    -1,    -1,     0,    27,
-      27,   -56,    59,   -56,   -56,   -56,   101,   -56,   -56,   -56,
-     -56,   113,   -56,   -56,   -56,   -56,   114,   -56,   115,   -56,
-     -56,   -56,   -56,   -56,   -56,   -56,   -56,   -56,    93,   -56,
-      95,     1,   -56,   -56,    92,   -56,    59,   -56,     0,   -56,
-     -56,    -1,    71,    -1,     0,   -56,   -56,   -56,   -56,    27,
-     -56,   -56,    27,   -56,   -56,   -56,   -56,   -56,   -56,   -56,
-     -56,    62,   -56,   -56,   -56,   -56,   -56,     0,   -56,   140,
-     -56,   144,   -56,   -56,   -56,   -56,   -56,   -56,   -56,   -56,
-       9,    49,   -56,   -56,     0,   146,    97,    92,    92,    49,
-     -56,   -56,   -56,   -56,   -56
+     -53,     5,   102,   -53,   -53,   -53,   -10,     8,    27,   -53,
+     -53,   -53,   -53,    18,   -53,    32,    55,   -53,    70,    77,
+     -53,    17,   -53,    43,    91,    53,    41,   -53,   -53,   -53,
+      42,    54,    94,    96,     0,   -53,   -53,   -53,    16,   -53,
+     -53,    56,   -53,   -53,   -53,   -53,    48,    30,    30,     0,
+      13,    13,   -53,    61,   -53,   -53,   -53,   101,   -53,   -53,
+     -53,   -53,   113,   -53,   -53,   -53,   -53,   114,   -53,   115,
+     -53,   -53,   -53,   -53,   -53,   -53,   -53,   -53,   -53,    93,
+     -53,    95,     1,   -53,   -53,    50,   -53,    61,   -53,     0,
+     -53,   -53,    30,    33,    30,     0,   -53,   -53,   -53,   -53,
+      13,   -53,   -53,    13,   -53,   -53,   -53,   -53,   -53,   -53,
+     -53,   -53,   103,   -53,   -53,   -53,   -53,   -53,     0,   -53,
+     141,   -53,   145,   -53,   -53,   -53,   -53,   -53,   -53,   -53,
+     -53,    39,    37,   -53,   -53,     0,   147,    97,    50,    50,
+      37,   -53,   -53,   -53,   -53,   -53
 };
 
   /* YYDEFACT[S] -- default reduction number in state S.  Performed when
@@ -699,39 +701,39 @@ static const yytype_int16 yypact[] =
      is an error.    */
 static const yytype_uint8 yydefact[] =
 {
-       3,     0,     0,     1,    46,    44,     0,     0,     0,    50,
-      51,    52,    53,     0,    37,     0,     9,     0,     0,     7,
-       0,    15,     0,     0,     0,     0,    38,    21,    22,     0,
-       0,     0,     0,     0,    28,    29,    30,     0,     6,    31,
-      41,     4,     5,    33,    32,    54,     0,     0,     0,     0,
-       0,    97,     0,    39,    94,    93,    95,    10,    11,    12,
-      13,     0,    16,    17,    18,    19,     0,    23,     0,    25,
-      26,    27,   103,    99,    98,   101,    34,   102,     0,   100,
-       0,     0,    75,    77,    91,    42,     0,    55,     0,    68,
-      73,    47,    69,    45,    48,    60,    65,    66,    67,    35,
-      62,    64,    36,    40,    96,     8,    14,    20,    24,    79,
-      78,     0,    76,     2,    92,    80,    43,    49,    56,    58,
-      74,    70,    71,    61,    63,   105,    85,    57,    59,    72,
-      81,    82,    85,    84,     0,     0,     0,    91,    91,    83,
-      88,    89,    90,    87,    86
+       3,     0,     0,     1,    47,    45,     0,     0,     0,    51,
+      52,    53,    54,     0,    38,     0,     9,    11,     0,     0,
+       7,     0,    16,     0,     0,     0,     0,    39,    22,    23,
+       0,     0,     0,     0,     0,    29,    30,    31,     0,     6,
+      32,    42,     4,     5,    34,    33,    55,     0,     0,     0,
+       0,     0,    98,     0,    40,    95,    94,    96,    10,    12,
+      13,    14,     0,    17,    18,    19,    20,     0,    24,     0,
+      26,    27,    28,   104,   100,    99,   102,    35,   103,     0,
+     101,     0,     0,    76,    78,    92,    43,     0,    56,     0,
+      69,    74,    48,    70,    46,    49,    61,    66,    67,    68,
+      36,    63,    65,    37,    41,    97,     8,    15,    21,    25,
+      80,    79,     0,    77,     2,    93,    81,    44,    50,    57,
+      59,    75,    71,    72,    62,    64,   106,    86,    58,    60,
+      73,    82,    83,    86,    85,     0,     0,     0,    92,    92,
+      84,    89,    90,    91,    88,    87
 };
 
   /* YYPGOTO[NTERM-NUM].    */
 static const yytype_int16 yypgoto[] =
 {
-     -56,   -56,   -56,   -56,   151,   -56,   -56,   -56,   -56,   -56,
-     -56,   -56,   -56,    37,   -56,   105,   -17,   -23,   109,   -56,
-      77,   -56,   -56,   -56,    28,   -51,   -56,   -56,   -32,   -42,
-     -56,   -33,   -55,   -56
+     -53,   -53,   -53,   -53,   152,   -53,   -53,   -53,   -53,   -53,
+     -53,   -53,   -53,    38,   -53,   104,   -32,    -3,   109,   -53,
+      78,   -53,   -53,   -53,    26,   -46,   -53,   -53,   -49,   -17,
+     -53,   -34,   -52,   -53
 };
 
   /* YYDEFGOTO[NTERM-NUM].    */
 static const yytype_int16 yydefgoto[] =
 {
-      -1,     1,     2,    41,    80,    86,    43,    47,    46,    44,
-      45,    88,   117,   118,    94,    99,   100,    90,    91,    81,
-      82,    83,   126,   130,   131,   115,    56,   105,    53,    75,
-      84,   101,    77,   113
+      -1,     1,     2,    42,    81,    87,    44,    48,    47,    45,
+      46,    89,   118,   119,    95,   100,   101,    91,    92,    82,
+      83,    84,   127,   131,   132,   116,    57,   106,    54,    76,
+      85,   102,    78,   114
 };
 
   /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
@@ -740,97 +742,97 @@ static const yytype_int16 yydefgoto[] =
      If YYTABLE_NINF, syntax error.    */
 static const yytype_int16 yytable[] =
 {
-      76,  -104,    78,    72,    92,    92,     4,     5,     6,     7,
-       8,     9,    10,    11,    12,    95,    54,    78,    13,    14,
-     103,     4,     5,     6,     7,     8,     9,    10,    11,    12,
-      72,    26,    60,    13,    14,    65,    67,   122,    33,    51,
-       3,    73,    73,    52,    74,    74,    26,    79,   111,    92,
-      89,    92,    72,    33,   116,   119,    40,   132,    55,   133,
-      49,   123,    79,   134,   135,   136,   129,    50,   120,    73,
-     120,    40,    74,    61,    72,   121,    66,    68,    96,    97,
-      98,    48,   124,    57,   119,   124,   143,   144,    58,    59,
-     137,    73,    62,    63,    74,    64,    69,    70,   138,    71,
-      51,   140,    85,    87,   104,   125,   138,     4,     5,     6,
-       7,     8,     9,    10,    11,    12,   106,   107,   108,    13,
+      77,  -105,    79,    73,   104,     3,     4,     5,     6,     7,
+       8,     9,    10,    11,    12,    96,    73,    79,    13,    14,
+      61,     4,     5,     6,     7,     8,     9,    10,    11,    12,
+      93,    93,    27,    13,    14,    55,    73,   122,   117,    34,
+      73,   123,    49,    74,    66,    68,    75,    27,    80,   112,
+      50,   135,   136,   137,    34,   120,    74,    41,    58,    75,
+      52,   124,    62,    80,    53,    97,    98,    99,   125,    51,
+     130,   125,    41,    74,    59,    93,    75,    93,    56,   138,
+      74,    60,    90,    75,   120,    63,    67,    69,   133,   121,
+     134,   121,   144,   145,    64,    65,    70,    71,   139,    72,
+      88,   141,    86,    52,   105,   115,   139,     4,     5,     6,
+       7,     8,     9,    10,    11,    12,   107,   108,   109,    13,
       14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
       24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
-      34,    35,    36,   109,   128,   110,   114,    72,   142,    37,
-     141,    38,    39,    42,   127,   102,    93,    40,   112,     0,
-     139
+      34,    35,    36,    37,   110,   129,   111,   126,    73,   143,
+      38,   142,    39,    40,    43,   103,   128,    94,    41,   140,
+     113
 };
 
-static const yytype_int16 yycheck[] =
+static const yytype_uint8 yycheck[] =
 {
-      33,     0,     1,     3,    46,    47,     5,     6,     7,     8,
-       9,    10,    11,    12,    13,    48,     3,     1,    17,    18,
-      52,     5,     6,     7,     8,     9,    10,    11,    12,    13,
-       3,    30,     3,    17,    18,     3,     3,    92,    37,    41,
-       0,    42,    42,    45,    45,    45,    30,    46,    47,    91,
-      51,    93,     3,    37,    86,    88,    55,    48,    45,    50,
-      41,    94,    46,    14,    15,    16,   121,    41,    91,    42,
-      93,    55,    45,    44,     3,     4,    44,    44,    51,    52,
-      53,    51,    99,     3,   117,   102,   137,   138,     4,     4,
-      41,    42,    41,     3,    45,    41,    41,     3,   131,     3,
-      41,   134,    45,    51,     3,    43,   139,     5,     6,     7,
+      34,     0,     1,     3,    53,     0,     5,     6,     7,     8,
+       9,    10,    11,    12,    13,    49,     3,     1,    17,    18,
+       3,     5,     6,     7,     8,     9,    10,    11,    12,    13,
+      47,    48,    31,    17,    18,     3,     3,     4,    87,    38,
+       3,    93,    52,    43,     3,     3,    46,    31,    47,    48,
+      42,    14,    15,    16,    38,    89,    43,    56,     3,    46,
+      42,    95,    45,    47,    46,    52,    53,    54,   100,    42,
+     122,   103,    56,    43,     4,    92,    46,    94,    46,    42,
+      43,     4,    52,    46,   118,    42,    45,    45,    49,    92,
+      51,    94,   138,   139,     3,    42,    42,     3,   132,     3,
+      52,   135,    46,    42,     3,    55,   140,     5,     6,     7,
        8,     9,    10,    11,    12,    13,     3,     3,     3,    17,
       18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
       28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
-      38,    39,    40,    50,     4,    50,    54,     3,    51,    47,
-       4,    49,    50,     2,   117,    50,    47,    55,    81,    -1,
-     132
+      38,    39,    40,    41,    51,     4,    51,    44,     3,    52,
+      48,     4,    50,    51,     2,    51,   118,    48,    56,   133,
+      82
 };
 
   /* STOS_[STATE-NUM] -- The (internal number of the) accessing
      symbol of state STATE-NUM.    */
 static const yytype_uint8 yystos[] =
 {
-       0,    57,    58,     0,     5,     6,     7,     8,     9,    10,
+       0,    58,    59,     0,     5,     6,     7,     8,     9,    10,
       11,    12,    13,    17,    18,    19,    20,    21,    22,    23,
       24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
-      34,    35,    36,    37,    38,    39,    40,    47,    49,    50,
-      55,    59,    60,    62,    65,    66,    64,    63,    51,    41,
-      41,    41,    45,    84,     3,    45,    82,     3,     4,     4,
-       3,    44,    41,     3,    41,     3,    44,     3,    44,    41,
-       3,     3,     3,    42,    45,    85,    87,    88,     1,    46,
-      60,    75,    76,    77,    86,    45,    61,    51,    67,    51,
-      73,    74,    85,    74,    70,    87,    51,    52,    53,    71,
-      72,    87,    71,    84,     3,    83,     3,     3,     3,    50,
-      50,    47,    76,    89,    54,    81,    84,    68,    69,    87,
-      73,     4,    88,    87,    72,    43,    78,    69,     4,    88,
-      79,    80,    48,    50,    14,    15,    16,    41,    87,    80,
-      87,     4,    51,    81,    81
+      34,    35,    36,    37,    38,    39,    40,    41,    48,    50,
+      51,    56,    60,    61,    63,    66,    67,    65,    64,    52,
+      42,    42,    42,    46,    85,     3,    46,    83,     3,     4,
+       4,     3,    45,    42,     3,    42,     3,    45,     3,    45,
+      42,     3,     3,     3,    43,    46,    86,    88,    89,     1,
+      47,    61,    76,    77,    78,    87,    46,    62,    52,    68,
+      52,    74,    75,    86,    75,    71,    88,    52,    53,    54,
+      72,    73,    88,    72,    85,     3,    84,     3,     3,     3,
+      51,    51,    48,    77,    90,    55,    82,    85,    69,    70,
+      88,    74,     4,    89,    88,    73,    44,    79,    70,     4,
+      89,    80,    81,    49,    51,    14,    15,    16,    42,    88,
+      81,    88,     4,    52,    82,    82
 };
 
   /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.    */
 static const yytype_uint8 yyr1[] =
 {
-       0,    56,    57,    58,    58,    59,    59,    59,    59,    59,
-      59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
-      59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
-      59,    59,    60,    60,    60,    60,    60,    60,    60,    60,
-      60,    61,    61,    60,    63,    62,    64,    62,    62,    65,
-      66,    66,    66,    66,    67,    67,    68,    68,    69,    69,
-      70,    70,    71,    71,    72,    72,    72,    72,    73,    73,
-      73,    73,    73,    74,    74,    75,    75,    76,    76,    76,
-      78,    77,    79,    79,    79,    80,    80,    80,    80,    80,
-      80,    81,    81,    82,    82,    83,    83,    84,    85,    85,
-      86,    87,    87,    88,    89,    89
+       0,    57,    58,    59,    59,    60,    60,    60,    60,    60,
+      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
+      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
+      60,    60,    60,    61,    61,    61,    61,    61,    61,    61,
+      61,    61,    62,    62,    61,    64,    63,    65,    63,    63,
+      66,    67,    67,    67,    67,    68,    68,    69,    69,    70,
+      70,    71,    71,    72,    72,    73,    73,    73,    73,    74,
+      74,    74,    74,    74,    75,    75,    76,    76,    77,    77,
+      77,    79,    78,    80,    80,    80,    81,    81,    81,    81,
+      81,    81,    82,    82,    83,    83,    84,    84,    85,    86,
+      86,    87,    88,    88,    89,    90,    90
 };
 
   /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.    */
 static const yytype_uint8 yyr2[] =
 {
        0,     2,     4,     0,     2,     1,     1,     1,     3,     1,
-       2,     2,     2,     2,     3,     1,     2,     2,     2,     2,
-       3,     1,     1,     2,     3,     2,     2,     2,     1,     1,
-       1,     1,     1,     1,     2,     3,     3,     1,     1,     2,
-       3,     0,     1,     3,     0,     3,     0,     3,     3,     3,
-       1,     1,     1,     1,     0,     1,     1,     2,     1,     2,
-       1,     2,     1,     2,     1,     1,     1,     1,     1,     1,
-       2,     2,     3,     1,     2,     1,     2,     1,     2,     2,
-       0,     4,     1,     3,     2,     0,     3,     3,     3,     3,
-       3,     0,     1,     1,     1,     0,     1,     1,     1,     1,
-       1,     1,     1,     1,     0,     2
+       2,     1,     2,     2,     2,     3,     1,     2,     2,     2,
+       2,     3,     1,     1,     2,     3,     2,     2,     2,     1,
+       1,     1,     1,     1,     1,     2,     3,     3,     1,     1,
+       2,     3,     0,     1,     3,     0,     3,     0,     3,     3,
+       3,     1,     1,     1,     1,     0,     1,     1,     2,     1,
+       2,     1,     2,     1,     2,     1,     1,     1,     1,     1,
+       1,     2,     2,     3,     1,     2,     1,     2,     1,     2,
+       2,     0,     4,     1,     3,     2,     0,     3,     3,     3,
+       3,     3,     0,     1,     1,     1,     0,     1,     1,     1,
+       1,     1,     1,     1,     1,     0,     2
 };
 
 
@@ -982,154 +984,154 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
             case 3: // "string"
 
 /* Line 647 of yacc.c  */
-#line 182 "parse-gram.y"
+#line 183 "parse-gram.y"
         { fputs (quotearg_style (c_quoting_style, ((*yyvaluep).chars)), stderr); }
 /* Line 647 of yacc.c  */
-#line 989 "../bison/src/parse-gram.c"
+#line 991 "/Users/akim/src/kernel/bison/src/parse-gram.c"
         break;
 
             case 4: // "integer"
 
 /* Line 647 of yacc.c  */
-#line 195 "parse-gram.y"
+#line 196 "parse-gram.y"
         { fprintf (stderr, "%d", ((*yyvaluep).integer)); }
 /* Line 647 of yacc.c  */
-#line 998 "../bison/src/parse-gram.c"
+#line 1000 "/Users/akim/src/kernel/bison/src/parse-gram.c"
         break;
 
-            case 23: // "%<flag>"
+            case 24: // "%<flag>"
 
 /* Line 647 of yacc.c  */
-#line 191 "parse-gram.y"
+#line 192 "parse-gram.y"
         { fprintf (stderr, "%%%s", ((*yyvaluep).uniqstr)); }
 /* Line 647 of yacc.c  */
-#line 1007 "../bison/src/parse-gram.c"
+#line 1009 "/Users/akim/src/kernel/bison/src/parse-gram.c"
         break;
 
-            case 41: // "{...}"
+            case 42: // "{...}"
 
 /* Line 647 of yacc.c  */
-#line 184 "parse-gram.y"
+#line 185 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).code)); }
 /* Line 647 of yacc.c  */
-#line 1016 "../bison/src/parse-gram.c"
+#line 1018 "/Users/akim/src/kernel/bison/src/parse-gram.c"
         break;
 
-            case 42: // "char"
+            case 43: // "char"
 
 /* Line 647 of yacc.c  */
-#line 176 "parse-gram.y"
+#line 177 "parse-gram.y"
         { fputs (char_name (((*yyvaluep).character)), stderr); }
 /* Line 647 of yacc.c  */
-#line 1025 "../bison/src/parse-gram.c"
+#line 1027 "/Users/akim/src/kernel/bison/src/parse-gram.c"
         break;
 
-            case 43: // "epilogue"
+            case 44: // "epilogue"
 
 /* Line 647 of yacc.c  */
-#line 184 "parse-gram.y"
+#line 185 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); }
 /* Line 647 of yacc.c  */
-#line 1034 "../bison/src/parse-gram.c"
+#line 1036 "/Users/akim/src/kernel/bison/src/parse-gram.c"
         break;
 
-            case 45: // "identifier"
+            case 46: // "identifier"
 
 /* Line 647 of yacc.c  */
-#line 189 "parse-gram.y"
+#line 190 "parse-gram.y"
         { fputs (((*yyvaluep).uniqstr), stderr); }
 /* Line 647 of yacc.c  */
-#line 1043 "../bison/src/parse-gram.c"
+#line 1045 "/Users/akim/src/kernel/bison/src/parse-gram.c"
         break;
 
-            case 46: // "identifier:"
+            case 47: // "identifier:"
 
 /* Line 647 of yacc.c  */
-#line 190 "parse-gram.y"
+#line 191 "parse-gram.y"
         { fprintf (stderr, "%s:", ((*yyvaluep).uniqstr)); }
 /* Line 647 of yacc.c  */
-#line 1052 "../bison/src/parse-gram.c"
+#line 1054 "/Users/akim/src/kernel/bison/src/parse-gram.c"
         break;
 
-            case 49: // "%{...%}"
+            case 50: // "%{...%}"
 
 /* Line 647 of yacc.c  */
-#line 184 "parse-gram.y"
+#line 185 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); }
 /* Line 647 of yacc.c  */
-#line 1061 "../bison/src/parse-gram.c"
+#line 1063 "/Users/akim/src/kernel/bison/src/parse-gram.c"
         break;
 
-            case 51: // "<tag>"
+            case 52: // "<tag>"
 
 /* Line 647 of yacc.c  */
-#line 192 "parse-gram.y"
+#line 193 "parse-gram.y"
         { fprintf (stderr, "<%s>", ((*yyvaluep).uniqstr)); }
 /* Line 647 of yacc.c  */
-#line 1070 "../bison/src/parse-gram.c"
+#line 1072 "/Users/akim/src/kernel/bison/src/parse-gram.c"
         break;
 
-            case 82: // variable
+            case 83: // variable
 
 /* Line 647 of yacc.c  */
-#line 189 "parse-gram.y"
+#line 190 "parse-gram.y"
         { fputs (((*yyvaluep).uniqstr), stderr); }
 /* Line 647 of yacc.c  */
-#line 1079 "../bison/src/parse-gram.c"
+#line 1081 "/Users/akim/src/kernel/bison/src/parse-gram.c"
         break;
 
-            case 83: // content.opt
+            case 84: // content.opt
 
 /* Line 647 of yacc.c  */
-#line 184 "parse-gram.y"
+#line 185 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); }
 /* Line 647 of yacc.c  */
-#line 1088 "../bison/src/parse-gram.c"
+#line 1090 "/Users/akim/src/kernel/bison/src/parse-gram.c"
         break;
 
-            case 84: // braceless
+            case 85: // braceless
 
 /* Line 647 of yacc.c  */
-#line 184 "parse-gram.y"
+#line 185 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); }
 /* Line 647 of yacc.c  */
-#line 1097 "../bison/src/parse-gram.c"
+#line 1099 "/Users/akim/src/kernel/bison/src/parse-gram.c"
         break;
 
-            case 85: // id
+            case 86: // id
 
 /* Line 647 of yacc.c  */
-#line 198 "parse-gram.y"
+#line 199 "parse-gram.y"
         { fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); }
 /* Line 647 of yacc.c  */
-#line 1106 "../bison/src/parse-gram.c"
+#line 1108 "/Users/akim/src/kernel/bison/src/parse-gram.c"
         break;
 
-            case 86: // id_colon
+            case 87: // id_colon
 
 /* Line 647 of yacc.c  */
-#line 199 "parse-gram.y"
+#line 200 "parse-gram.y"
         { fprintf (stderr, "%s:", ((*yyvaluep).symbol)->tag); }
 /* Line 647 of yacc.c  */
-#line 1115 "../bison/src/parse-gram.c"
+#line 1117 "/Users/akim/src/kernel/bison/src/parse-gram.c"
         break;
 
-            case 87: // symbol
+            case 88: // symbol
 
 /* Line 647 of yacc.c  */
-#line 198 "parse-gram.y"
+#line 199 "parse-gram.y"
         { fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); }
 /* Line 647 of yacc.c  */
-#line 1124 "../bison/src/parse-gram.c"
+#line 1126 "/Users/akim/src/kernel/bison/src/parse-gram.c"
         break;
 
-            case 88: // string_as_id
+            case 89: // string_as_id
 
 /* Line 647 of yacc.c  */
-#line 198 "parse-gram.y"
+#line 199 "parse-gram.y"
         { fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); }
 /* Line 647 of yacc.c  */
-#line 1133 "../bison/src/parse-gram.c"
+#line 1135 "/Users/akim/src/kernel/bison/src/parse-gram.c"
         break;
 
       default:
@@ -1651,7 +1653,7 @@ YYLTYPE yylloc;
   boundary_set (&yylloc.end, current_file, 1, 1);
 }
 /* Line 1167 of yacc.c  */
-#line 1655 "../bison/src/parse-gram.c"
+#line 1657 "/Users/akim/src/kernel/bison/src/parse-gram.c"
   yylsp[0] = yylloc;
 
   goto yysetstate;
@@ -1838,7 +1840,7 @@ yyreduce:
     {
         case 6:
 /* Line 1380 of yacc.c  */
-#line 222 "parse-gram.y"
+#line 223 "parse-gram.y"
     {
       code_props plain_code;
       code_props_plain_init (&plain_code, (yyvsp[0].chars), (yylsp[0]));
@@ -1849,95 +1851,106 @@ yyreduce:
       code_scanner_last_string_free ();
     }
 /* Line 1380 of yacc.c  */
-#line 1853 "../bison/src/parse-gram.c"
+#line 1855 "/Users/akim/src/kernel/bison/src/parse-gram.c"
     break;
 
   case 7:
 /* Line 1380 of yacc.c  */
-#line 232 "parse-gram.y"
+#line 233 "parse-gram.y"
     {
       muscle_percent_define_ensure ((yyvsp[0].uniqstr), (yylsp[0]), true);
     }
 /* Line 1380 of yacc.c  */
-#line 1863 "../bison/src/parse-gram.c"
+#line 1865 "/Users/akim/src/kernel/bison/src/parse-gram.c"
     break;
 
   case 8:
 /* Line 1380 of yacc.c  */
-#line 236 "parse-gram.y"
+#line 237 "parse-gram.y"
     {
       muscle_percent_define_insert ((yyvsp[-1].uniqstr), (yylsp[-1]), (yyvsp[0].chars),
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
     }
 /* Line 1380 of yacc.c  */
-#line 1874 "../bison/src/parse-gram.c"
+#line 1876 "/Users/akim/src/kernel/bison/src/parse-gram.c"
     break;
 
   case 9:
 /* Line 1380 of yacc.c  */
-#line 240 "parse-gram.y"
+#line 241 "parse-gram.y"
     { defines_flag = true; }
 /* Line 1380 of yacc.c  */
-#line 1882 "../bison/src/parse-gram.c"
+#line 1884 "/Users/akim/src/kernel/bison/src/parse-gram.c"
     break;
 
   case 10:
 /* Line 1380 of yacc.c  */
-#line 242 "parse-gram.y"
+#line 243 "parse-gram.y"
     {
       defines_flag = true;
       spec_defines_file = xstrdup ((yyvsp[0].chars));
     }
 /* Line 1380 of yacc.c  */
-#line 1893 "../bison/src/parse-gram.c"
+#line 1895 "/Users/akim/src/kernel/bison/src/parse-gram.c"
     break;
 
   case 11:
 /* Line 1380 of yacc.c  */
-#line 246 "parse-gram.y"
-    { expected_sr_conflicts = (yyvsp[0].integer); }
+#line 248 "parse-gram.y"
+    {
+      muscle_percent_define_insert ("parse.error", (yylsp[0]), "verbose",
+                                    MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
+    }
 /* Line 1380 of yacc.c  */
-#line 1901 "../bison/src/parse-gram.c"
+#line 1906 "/Users/akim/src/kernel/bison/src/parse-gram.c"
     break;
 
   case 12:
 /* Line 1380 of yacc.c  */
-#line 247 "parse-gram.y"
-    { expected_rr_conflicts = (yyvsp[0].integer); }
+#line 252 "parse-gram.y"
+    { expected_sr_conflicts = (yyvsp[0].integer); }
 /* Line 1380 of yacc.c  */
-#line 1909 "../bison/src/parse-gram.c"
+#line 1914 "/Users/akim/src/kernel/bison/src/parse-gram.c"
     break;
 
   case 13:
 /* Line 1380 of yacc.c  */
-#line 248 "parse-gram.y"
-    { spec_file_prefix = (yyvsp[0].chars); }
+#line 253 "parse-gram.y"
+    { expected_rr_conflicts = (yyvsp[0].integer); }
 /* Line 1380 of yacc.c  */
-#line 1917 "../bison/src/parse-gram.c"
+#line 1922 "/Users/akim/src/kernel/bison/src/parse-gram.c"
     break;
 
   case 14:
 /* Line 1380 of yacc.c  */
-#line 249 "parse-gram.y"
+#line 254 "parse-gram.y"
     { spec_file_prefix = (yyvsp[0].chars); }
 /* Line 1380 of yacc.c  */
-#line 1925 "../bison/src/parse-gram.c"
+#line 1930 "/Users/akim/src/kernel/bison/src/parse-gram.c"
     break;
 
   case 15:
 /* Line 1380 of yacc.c  */
-#line 251 "parse-gram.y"
+#line 255 "parse-gram.y"
+    { spec_file_prefix = (yyvsp[0].chars); }
+/* Line 1380 of yacc.c  */
+#line 1938 "/Users/akim/src/kernel/bison/src/parse-gram.c"
+    break;
+
+  case 16:
+/* Line 1380 of yacc.c  */
+#line 257 "parse-gram.y"
     {
       nondeterministic_parser = true;
       glr_parser = true;
     }
 /* Line 1380 of yacc.c  */
-#line 1936 "../bison/src/parse-gram.c"
+#line 1949 "/Users/akim/src/kernel/bison/src/parse-gram.c"
     break;
 
-  case 16:
+  case 17:
 /* Line 1380 of yacc.c  */
-#line 256 "parse-gram.y"
+#line 262 "parse-gram.y"
     {
       code_props action;
       code_props_symbol_action_init (&action, (yyvsp[0].code), (yylsp[0]));
@@ -1947,92 +1960,92 @@ yyreduce:
       code_scanner_last_string_free ();
     }
 /* Line 1380 of yacc.c  */
-#line 1951 "../bison/src/parse-gram.c"
+#line 1964 "/Users/akim/src/kernel/bison/src/parse-gram.c"
     break;
 
-  case 17:
+  case 18:
 /* Line 1380 of yacc.c  */
-#line 264 "parse-gram.y"
+#line 270 "parse-gram.y"
     { language_argmatch ((yyvsp[0].chars), grammar_prio, (yylsp[-1])); }
 /* Line 1380 of yacc.c  */
-#line 1959 "../bison/src/parse-gram.c"
+#line 1972 "/Users/akim/src/kernel/bison/src/parse-gram.c"
     break;
 
-  case 18:
+  case 19:
 /* Line 1380 of yacc.c  */
-#line 265 "parse-gram.y"
+#line 271 "parse-gram.y"
     { add_param ("lex_param", (yyvsp[0].code), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 1967 "../bison/src/parse-gram.c"
+#line 1980 "/Users/akim/src/kernel/bison/src/parse-gram.c"
     break;
 
-  case 19:
+  case 20:
 /* Line 1380 of yacc.c  */
-#line 266 "parse-gram.y"
+#line 272 "parse-gram.y"
     { spec_name_prefix = (yyvsp[0].chars); }
 /* Line 1380 of yacc.c  */
-#line 1975 "../bison/src/parse-gram.c"
+#line 1988 "/Users/akim/src/kernel/bison/src/parse-gram.c"
     break;
 
-  case 20:
+  case 21:
 /* Line 1380 of yacc.c  */
-#line 267 "parse-gram.y"
+#line 273 "parse-gram.y"
     { spec_name_prefix = (yyvsp[0].chars); }
 /* Line 1380 of yacc.c  */
-#line 1983 "../bison/src/parse-gram.c"
+#line 1996 "/Users/akim/src/kernel/bison/src/parse-gram.c"
     break;
 
-  case 21:
+  case 22:
 /* Line 1380 of yacc.c  */
-#line 268 "parse-gram.y"
+#line 274 "parse-gram.y"
     { no_lines_flag = true; }
 /* Line 1380 of yacc.c  */
-#line 1991 "../bison/src/parse-gram.c"
+#line 2004 "/Users/akim/src/kernel/bison/src/parse-gram.c"
     break;
 
-  case 22:
+  case 23:
 /* Line 1380 of yacc.c  */
-#line 269 "parse-gram.y"
+#line 275 "parse-gram.y"
     { nondeterministic_parser = true; }
 /* Line 1380 of yacc.c  */
-#line 1999 "../bison/src/parse-gram.c"
+#line 2012 "/Users/akim/src/kernel/bison/src/parse-gram.c"
     break;
 
-  case 23:
+  case 24:
 /* Line 1380 of yacc.c  */
-#line 270 "parse-gram.y"
+#line 276 "parse-gram.y"
     { spec_outfile = (yyvsp[0].chars); }
 /* Line 1380 of yacc.c  */
-#line 2007 "../bison/src/parse-gram.c"
+#line 2020 "/Users/akim/src/kernel/bison/src/parse-gram.c"
     break;
 
-  case 24:
+  case 25:
 /* Line 1380 of yacc.c  */
-#line 271 "parse-gram.y"
+#line 277 "parse-gram.y"
     { spec_outfile = (yyvsp[0].chars); }
 /* Line 1380 of yacc.c  */
-#line 2015 "../bison/src/parse-gram.c"
+#line 2028 "/Users/akim/src/kernel/bison/src/parse-gram.c"
     break;
 
-  case 25:
+  case 26:
 /* Line 1380 of yacc.c  */
-#line 272 "parse-gram.y"
+#line 278 "parse-gram.y"
     { add_param ("parse_param", (yyvsp[0].code), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2023 "../bison/src/parse-gram.c"
+#line 2036 "/Users/akim/src/kernel/bison/src/parse-gram.c"
     break;
 
-  case 26:
+  case 27:
 /* Line 1380 of yacc.c  */
-#line 273 "parse-gram.y"
+#line 279 "parse-gram.y"
     { version_check (&(yylsp[0]), (yyvsp[0].chars)); }
 /* Line 1380 of yacc.c  */
-#line 2031 "../bison/src/parse-gram.c"
+#line 2044 "/Users/akim/src/kernel/bison/src/parse-gram.c"
     break;
 
-  case 27:
+  case 28:
 /* Line 1380 of yacc.c  */
-#line 275 "parse-gram.y"
+#line 281 "parse-gram.y"
     {
       char const *skeleton_user = (yyvsp[0].chars);
       if (strchr (skeleton_user, '/'))
@@ -2057,46 +2070,46 @@ yyreduce:
       skeleton_arg (skeleton_user, grammar_prio, (yylsp[-1]));
     }
 /* Line 1380 of yacc.c  */
-#line 2061 "../bison/src/parse-gram.c"
+#line 2074 "/Users/akim/src/kernel/bison/src/parse-gram.c"
     break;
 
-  case 28:
+  case 29:
 /* Line 1380 of yacc.c  */
-#line 298 "parse-gram.y"
+#line 304 "parse-gram.y"
     { token_table_flag = true; }
 /* Line 1380 of yacc.c  */
-#line 2069 "../bison/src/parse-gram.c"
+#line 2082 "/Users/akim/src/kernel/bison/src/parse-gram.c"
     break;
 
-  case 29:
+  case 30:
 /* Line 1380 of yacc.c  */
-#line 299 "parse-gram.y"
+#line 305 "parse-gram.y"
     { report_flag |= report_states; }
 /* Line 1380 of yacc.c  */
-#line 2077 "../bison/src/parse-gram.c"
+#line 2090 "/Users/akim/src/kernel/bison/src/parse-gram.c"
     break;
 
-  case 30:
+  case 31:
 /* Line 1380 of yacc.c  */
-#line 300 "parse-gram.y"
+#line 306 "parse-gram.y"
     { yacc_flag = true; }
 /* Line 1380 of yacc.c  */
-#line 2085 "../bison/src/parse-gram.c"
+#line 2098 "/Users/akim/src/kernel/bison/src/parse-gram.c"
     break;
 
-  case 34:
+  case 35:
 /* Line 1380 of yacc.c  */
-#line 308 "parse-gram.y"
+#line 314 "parse-gram.y"
     {
       grammar_start_symbol_set ((yyvsp[0].symbol), (yylsp[0]));
     }
 /* Line 1380 of yacc.c  */
-#line 2095 "../bison/src/parse-gram.c"
+#line 2108 "/Users/akim/src/kernel/bison/src/parse-gram.c"
     break;
 
-  case 35:
+  case 36:
 /* Line 1380 of yacc.c  */
-#line 312 "parse-gram.y"
+#line 318 "parse-gram.y"
     {
       symbol_list *list;
       for (list = (yyvsp[0].list); list; list = list->next)
@@ -2104,12 +2117,12 @@ yyreduce:
       symbol_list_free ((yyvsp[0].list));
     }
 /* Line 1380 of yacc.c  */
-#line 2108 "../bison/src/parse-gram.c"
+#line 2121 "/Users/akim/src/kernel/bison/src/parse-gram.c"
     break;
 
-  case 36:
+  case 37:
 /* Line 1380 of yacc.c  */
-#line 319 "parse-gram.y"
+#line 325 "parse-gram.y"
     {
       symbol_list *list;
       for (list = (yyvsp[0].list); list; list = list->next)
@@ -2117,32 +2130,32 @@ yyreduce:
       symbol_list_free ((yyvsp[0].list));
     }
 /* Line 1380 of yacc.c  */
-#line 2121 "../bison/src/parse-gram.c"
+#line 2134 "/Users/akim/src/kernel/bison/src/parse-gram.c"
     break;
 
-  case 37:
+  case 38:
 /* Line 1380 of yacc.c  */
-#line 326 "parse-gram.y"
+#line 332 "parse-gram.y"
     {
       default_prec = true;
     }
 /* Line 1380 of yacc.c  */
-#line 2131 "../bison/src/parse-gram.c"
+#line 2144 "/Users/akim/src/kernel/bison/src/parse-gram.c"
     break;
 
-  case 38:
+  case 39:
 /* Line 1380 of yacc.c  */
-#line 330 "parse-gram.y"
+#line 336 "parse-gram.y"
     {
       default_prec = false;
     }
 /* Line 1380 of yacc.c  */
-#line 2141 "../bison/src/parse-gram.c"
+#line 2154 "/Users/akim/src/kernel/bison/src/parse-gram.c"
     break;
 
-  case 39:
+  case 40:
 /* Line 1380 of yacc.c  */
-#line 334 "parse-gram.y"
+#line 340 "parse-gram.y"
     {
       /* Do not invoke muscle_percent_code_grow here since it invokes
          muscle_user_name_list_grow.  */
@@ -2150,89 +2163,89 @@ yyreduce:
       code_scanner_last_string_free ();
     }
 /* Line 1380 of yacc.c  */
-#line 2154 "../bison/src/parse-gram.c"
+#line 2167 "/Users/akim/src/kernel/bison/src/parse-gram.c"
     break;
 
-  case 40:
+  case 41:
 /* Line 1380 of yacc.c  */
-#line 341 "parse-gram.y"
+#line 347 "parse-gram.y"
     {
       muscle_percent_code_grow ((yyvsp[-1].uniqstr), (yylsp[-1]), (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
 /* Line 1380 of yacc.c  */
-#line 2165 "../bison/src/parse-gram.c"
+#line 2178 "/Users/akim/src/kernel/bison/src/parse-gram.c"
     break;
 
-  case 41:
+  case 42:
 /* Line 1380 of yacc.c  */
-#line 355 "parse-gram.y"
+#line 361 "parse-gram.y"
     {}
 /* Line 1380 of yacc.c  */
-#line 2173 "../bison/src/parse-gram.c"
+#line 2186 "/Users/akim/src/kernel/bison/src/parse-gram.c"
     break;
 
-  case 42:
+  case 43:
 /* Line 1380 of yacc.c  */
-#line 356 "parse-gram.y"
+#line 362 "parse-gram.y"
     { muscle_code_grow ("union_name", (yyvsp[0].uniqstr), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2181 "../bison/src/parse-gram.c"
+#line 2194 "/Users/akim/src/kernel/bison/src/parse-gram.c"
     break;
 
-  case 43:
+  case 44:
 /* Line 1380 of yacc.c  */
-#line 361 "parse-gram.y"
+#line 367 "parse-gram.y"
     {
       union_seen = true;
       muscle_code_grow ("stype", (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
 /* Line 1380 of yacc.c  */
-#line 2193 "../bison/src/parse-gram.c"
+#line 2206 "/Users/akim/src/kernel/bison/src/parse-gram.c"
     break;
 
-  case 44:
+  case 45:
 /* Line 1380 of yacc.c  */
-#line 372 "parse-gram.y"
+#line 378 "parse-gram.y"
     { current_class = nterm_sym; }
 /* Line 1380 of yacc.c  */
-#line 2201 "../bison/src/parse-gram.c"
+#line 2214 "/Users/akim/src/kernel/bison/src/parse-gram.c"
     break;
 
-  case 45:
+  case 46:
 /* Line 1380 of yacc.c  */
-#line 373 "parse-gram.y"
+#line 379 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
 /* Line 1380 of yacc.c  */
-#line 2212 "../bison/src/parse-gram.c"
+#line 2225 "/Users/akim/src/kernel/bison/src/parse-gram.c"
     break;
 
-  case 46:
+  case 47:
 /* Line 1380 of yacc.c  */
-#line 377 "parse-gram.y"
+#line 383 "parse-gram.y"
     { current_class = token_sym; }
 /* Line 1380 of yacc.c  */
-#line 2220 "../bison/src/parse-gram.c"
+#line 2233 "/Users/akim/src/kernel/bison/src/parse-gram.c"
     break;
 
-  case 47:
+  case 48:
 /* Line 1380 of yacc.c  */
-#line 378 "parse-gram.y"
+#line 384 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
 /* Line 1380 of yacc.c  */
-#line 2231 "../bison/src/parse-gram.c"
+#line 2244 "/Users/akim/src/kernel/bison/src/parse-gram.c"
     break;
 
-  case 48:
+  case 49:
 /* Line 1380 of yacc.c  */
-#line 383 "parse-gram.y"
+#line 389 "parse-gram.y"
     {
       symbol_list *list;
       tag_seen = true;
@@ -2241,12 +2254,12 @@ yyreduce:
       symbol_list_free ((yyvsp[0].list));
     }
 /* Line 1380 of yacc.c  */
-#line 2245 "../bison/src/parse-gram.c"
+#line 2258 "/Users/akim/src/kernel/bison/src/parse-gram.c"
     break;
 
-  case 49:
+  case 50:
 /* Line 1380 of yacc.c  */
-#line 394 "parse-gram.y"
+#line 400 "parse-gram.y"
     {
       symbol_list *list;
       ++current_prec;
@@ -2259,202 +2272,202 @@ yyreduce:
       current_type = NULL;
     }
 /* Line 1380 of yacc.c  */
-#line 2263 "../bison/src/parse-gram.c"
+#line 2276 "/Users/akim/src/kernel/bison/src/parse-gram.c"
     break;
 
-  case 50:
+  case 51:
 /* Line 1380 of yacc.c  */
-#line 408 "parse-gram.y"
+#line 414 "parse-gram.y"
     { (yyval.assoc) = left_assoc; }
 /* Line 1380 of yacc.c  */
-#line 2271 "../bison/src/parse-gram.c"
+#line 2284 "/Users/akim/src/kernel/bison/src/parse-gram.c"
     break;
 
-  case 51:
+  case 52:
 /* Line 1380 of yacc.c  */
-#line 409 "parse-gram.y"
+#line 415 "parse-gram.y"
     { (yyval.assoc) = right_assoc; }
 /* Line 1380 of yacc.c  */
-#line 2279 "../bison/src/parse-gram.c"
+#line 2292 "/Users/akim/src/kernel/bison/src/parse-gram.c"
     break;
 
-  case 52:
+  case 53:
 /* Line 1380 of yacc.c  */
-#line 410 "parse-gram.y"
+#line 416 "parse-gram.y"
     { (yyval.assoc) = non_assoc; }
 /* Line 1380 of yacc.c  */
-#line 2287 "../bison/src/parse-gram.c"
+#line 2300 "/Users/akim/src/kernel/bison/src/parse-gram.c"
     break;
 
-  case 53:
+  case 54:
 /* Line 1380 of yacc.c  */
-#line 411 "parse-gram.y"
+#line 417 "parse-gram.y"
     { (yyval.assoc) = precedence_assoc; }
 /* Line 1380 of yacc.c  */
-#line 2295 "../bison/src/parse-gram.c"
+#line 2308 "/Users/akim/src/kernel/bison/src/parse-gram.c"
     break;
 
-  case 54:
+  case 55:
 /* Line 1380 of yacc.c  */
-#line 415 "parse-gram.y"
+#line 421 "parse-gram.y"
     { current_type = NULL; }
 /* Line 1380 of yacc.c  */
-#line 2303 "../bison/src/parse-gram.c"
+#line 2316 "/Users/akim/src/kernel/bison/src/parse-gram.c"
     break;
 
-  case 55:
+  case 56:
 /* Line 1380 of yacc.c  */
-#line 416 "parse-gram.y"
+#line 422 "parse-gram.y"
     { current_type = (yyvsp[0].uniqstr); tag_seen = true; }
 /* Line 1380 of yacc.c  */
-#line 2311 "../bison/src/parse-gram.c"
+#line 2324 "/Users/akim/src/kernel/bison/src/parse-gram.c"
     break;
 
-  case 56:
+  case 57:
 /* Line 1380 of yacc.c  */
-#line 422 "parse-gram.y"
+#line 428 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2319 "../bison/src/parse-gram.c"
+#line 2332 "/Users/akim/src/kernel/bison/src/parse-gram.c"
     break;
 
-  case 57:
+  case 58:
 /* Line 1380 of yacc.c  */
-#line 424 "parse-gram.y"
+#line 430 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
 /* Line 1380 of yacc.c  */
-#line 2327 "../bison/src/parse-gram.c"
+#line 2340 "/Users/akim/src/kernel/bison/src/parse-gram.c"
     break;
 
-  case 58:
+  case 59:
 /* Line 1380 of yacc.c  */
-#line 428 "parse-gram.y"
+#line 434 "parse-gram.y"
     { (yyval.symbol) = (yyvsp[0].symbol); }
 /* Line 1380 of yacc.c  */
-#line 2335 "../bison/src/parse-gram.c"
+#line 2348 "/Users/akim/src/kernel/bison/src/parse-gram.c"
     break;
 
-  case 59:
+  case 60:
 /* Line 1380 of yacc.c  */
-#line 429 "parse-gram.y"
+#line 435 "parse-gram.y"
     { (yyval.symbol) = (yyvsp[-1].symbol); symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2343 "../bison/src/parse-gram.c"
+#line 2356 "/Users/akim/src/kernel/bison/src/parse-gram.c"
     break;
 
-  case 60:
+  case 61:
 /* Line 1380 of yacc.c  */
-#line 435 "parse-gram.y"
+#line 441 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2351 "../bison/src/parse-gram.c"
+#line 2364 "/Users/akim/src/kernel/bison/src/parse-gram.c"
     break;
 
-  case 61:
+  case 62:
 /* Line 1380 of yacc.c  */
-#line 437 "parse-gram.y"
+#line 443 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
 /* Line 1380 of yacc.c  */
-#line 2359 "../bison/src/parse-gram.c"
+#line 2372 "/Users/akim/src/kernel/bison/src/parse-gram.c"
     break;
 
-  case 62:
+  case 63:
 /* Line 1380 of yacc.c  */
-#line 441 "parse-gram.y"
+#line 447 "parse-gram.y"
     { (yyval.list) = (yyvsp[0].list); }
 /* Line 1380 of yacc.c  */
-#line 2367 "../bison/src/parse-gram.c"
+#line 2380 "/Users/akim/src/kernel/bison/src/parse-gram.c"
     break;
 
-  case 63:
+  case 64:
 /* Line 1380 of yacc.c  */
-#line 442 "parse-gram.y"
+#line 448 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), (yyvsp[0].list)); }
 /* Line 1380 of yacc.c  */
-#line 2375 "../bison/src/parse-gram.c"
+#line 2388 "/Users/akim/src/kernel/bison/src/parse-gram.c"
     break;
 
-  case 64:
+  case 65:
 /* Line 1380 of yacc.c  */
-#line 446 "parse-gram.y"
+#line 452 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2383 "../bison/src/parse-gram.c"
+#line 2396 "/Users/akim/src/kernel/bison/src/parse-gram.c"
     break;
 
-  case 65:
+  case 66:
 /* Line 1380 of yacc.c  */
-#line 447 "parse-gram.y"
+#line 453 "parse-gram.y"
     { (yyval.list) = symbol_list_type_new ((yyvsp[0].uniqstr), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2391 "../bison/src/parse-gram.c"
+#line 2404 "/Users/akim/src/kernel/bison/src/parse-gram.c"
     break;
 
-  case 66:
+  case 67:
 /* Line 1380 of yacc.c  */
-#line 448 "parse-gram.y"
+#line 454 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagged_new ((yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2399 "../bison/src/parse-gram.c"
+#line 2412 "/Users/akim/src/kernel/bison/src/parse-gram.c"
     break;
 
-  case 67:
+  case 68:
 /* Line 1380 of yacc.c  */
-#line 449 "parse-gram.y"
+#line 455 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagless_new ((yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2407 "../bison/src/parse-gram.c"
+#line 2420 "/Users/akim/src/kernel/bison/src/parse-gram.c"
     break;
 
-  case 68:
+  case 69:
 /* Line 1380 of yacc.c  */
-#line 455 "parse-gram.y"
+#line 461 "parse-gram.y"
     {
        current_type = (yyvsp[0].uniqstr);
        tag_seen = true;
      }
 /* Line 1380 of yacc.c  */
-#line 2418 "../bison/src/parse-gram.c"
+#line 2431 "/Users/akim/src/kernel/bison/src/parse-gram.c"
     break;
 
-  case 69:
+  case 70:
 /* Line 1380 of yacc.c  */
-#line 460 "parse-gram.y"
+#line 466 "parse-gram.y"
     {
        symbol_class_set ((yyvsp[0].symbol), current_class, (yylsp[0]), true);
        symbol_type_set ((yyvsp[0].symbol), current_type, (yylsp[0]));
      }
 /* Line 1380 of yacc.c  */
-#line 2429 "../bison/src/parse-gram.c"
+#line 2442 "/Users/akim/src/kernel/bison/src/parse-gram.c"
     break;
 
-  case 70:
+  case 71:
 /* Line 1380 of yacc.c  */
-#line 465 "parse-gram.y"
+#line 471 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[-1].symbol), current_class, (yylsp[-1]), true);
       symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
       symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0]));
     }
 /* Line 1380 of yacc.c  */
-#line 2441 "../bison/src/parse-gram.c"
+#line 2454 "/Users/akim/src/kernel/bison/src/parse-gram.c"
     break;
 
-  case 71:
+  case 72:
 /* Line 1380 of yacc.c  */
-#line 471 "parse-gram.y"
+#line 477 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[-1].symbol), current_class, (yylsp[-1]), true);
       symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
       symbol_make_alias ((yyvsp[-1].symbol), (yyvsp[0].symbol), (yyloc));
     }
 /* Line 1380 of yacc.c  */
-#line 2453 "../bison/src/parse-gram.c"
+#line 2466 "/Users/akim/src/kernel/bison/src/parse-gram.c"
     break;
 
-  case 72:
+  case 73:
 /* Line 1380 of yacc.c  */
-#line 477 "parse-gram.y"
+#line 483 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[-2].symbol), current_class, (yylsp[-2]), true);
       symbol_type_set ((yyvsp[-2].symbol), current_type, (yylsp[-2]));
@@ -2462,128 +2475,128 @@ yyreduce:
       symbol_make_alias ((yyvsp[-2].symbol), (yyvsp[0].symbol), (yyloc));
     }
 /* Line 1380 of yacc.c  */
-#line 2466 "../bison/src/parse-gram.c"
+#line 2479 "/Users/akim/src/kernel/bison/src/parse-gram.c"
     break;
 
-  case 79:
+  case 80:
 /* Line 1380 of yacc.c  */
-#line 507 "parse-gram.y"
+#line 513 "parse-gram.y"
     {
       yyerrok;
     }
 /* Line 1380 of yacc.c  */
-#line 2476 "../bison/src/parse-gram.c"
+#line 2489 "/Users/akim/src/kernel/bison/src/parse-gram.c"
     break;
 
-  case 80:
+  case 81:
 /* Line 1380 of yacc.c  */
-#line 513 "parse-gram.y"
+#line 519 "parse-gram.y"
     { current_lhs = (yyvsp[-1].symbol); current_lhs_location = (yylsp[-1]);
     current_lhs_named_ref = (yyvsp[0].named_ref); }
 /* Line 1380 of yacc.c  */
-#line 2485 "../bison/src/parse-gram.c"
+#line 2498 "/Users/akim/src/kernel/bison/src/parse-gram.c"
     break;
 
-  case 82:
+  case 83:
 /* Line 1380 of yacc.c  */
-#line 518 "parse-gram.y"
+#line 524 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2493 "../bison/src/parse-gram.c"
+#line 2506 "/Users/akim/src/kernel/bison/src/parse-gram.c"
     break;
 
-  case 83:
+  case 84:
 /* Line 1380 of yacc.c  */
-#line 519 "parse-gram.y"
+#line 525 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2501 "../bison/src/parse-gram.c"
+#line 2514 "/Users/akim/src/kernel/bison/src/parse-gram.c"
     break;
 
-  case 85:
+  case 86:
 /* Line 1380 of yacc.c  */
-#line 525 "parse-gram.y"
+#line 531 "parse-gram.y"
     { grammar_current_rule_begin (current_lhs, current_lhs_location,
 				  current_lhs_named_ref); }
 /* Line 1380 of yacc.c  */
-#line 2510 "../bison/src/parse-gram.c"
+#line 2523 "/Users/akim/src/kernel/bison/src/parse-gram.c"
     break;
 
-  case 86:
+  case 87:
 /* Line 1380 of yacc.c  */
-#line 528 "parse-gram.y"
+#line 534 "parse-gram.y"
     { grammar_current_rule_symbol_append ((yyvsp[-1].symbol), (yylsp[-1]), (yyvsp[0].named_ref)); }
 /* Line 1380 of yacc.c  */
-#line 2518 "../bison/src/parse-gram.c"
+#line 2531 "/Users/akim/src/kernel/bison/src/parse-gram.c"
     break;
 
-  case 87:
+  case 88:
 /* Line 1380 of yacc.c  */
-#line 530 "parse-gram.y"
+#line 536 "parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[-1].code), (yylsp[-1]), (yyvsp[0].named_ref)); }
 /* Line 1380 of yacc.c  */
-#line 2526 "../bison/src/parse-gram.c"
+#line 2539 "/Users/akim/src/kernel/bison/src/parse-gram.c"
     break;
 
-  case 88:
+  case 89:
 /* Line 1380 of yacc.c  */
-#line 532 "parse-gram.y"
+#line 538 "parse-gram.y"
     { grammar_current_rule_prec_set ((yyvsp[0].symbol), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2534 "../bison/src/parse-gram.c"
+#line 2547 "/Users/akim/src/kernel/bison/src/parse-gram.c"
     break;
 
-  case 89:
+  case 90:
 /* Line 1380 of yacc.c  */
-#line 534 "parse-gram.y"
+#line 540 "parse-gram.y"
     { grammar_current_rule_dprec_set ((yyvsp[0].integer), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2542 "../bison/src/parse-gram.c"
+#line 2555 "/Users/akim/src/kernel/bison/src/parse-gram.c"
     break;
 
-  case 90:
+  case 91:
 /* Line 1380 of yacc.c  */
-#line 536 "parse-gram.y"
+#line 542 "parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[0].uniqstr), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2550 "../bison/src/parse-gram.c"
+#line 2563 "/Users/akim/src/kernel/bison/src/parse-gram.c"
     break;
 
-  case 91:
+  case 92:
 /* Line 1380 of yacc.c  */
-#line 541 "parse-gram.y"
+#line 547 "parse-gram.y"
     { (yyval.named_ref) = 0; }
 /* Line 1380 of yacc.c  */
-#line 2558 "../bison/src/parse-gram.c"
+#line 2571 "/Users/akim/src/kernel/bison/src/parse-gram.c"
     break;
 
-  case 92:
+  case 93:
 /* Line 1380 of yacc.c  */
-#line 544 "parse-gram.y"
+#line 550 "parse-gram.y"
     { (yyval.named_ref) = named_ref_new((yyvsp[0].uniqstr), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2566 "../bison/src/parse-gram.c"
+#line 2579 "/Users/akim/src/kernel/bison/src/parse-gram.c"
     break;
 
-  case 94:
+  case 95:
 /* Line 1380 of yacc.c  */
-#line 556 "parse-gram.y"
+#line 562 "parse-gram.y"
     { (yyval.uniqstr) = uniqstr_new ((yyvsp[0].chars)); }
 /* Line 1380 of yacc.c  */
-#line 2574 "../bison/src/parse-gram.c"
+#line 2587 "/Users/akim/src/kernel/bison/src/parse-gram.c"
     break;
 
-  case 95:
+  case 96:
 /* Line 1380 of yacc.c  */
-#line 561 "parse-gram.y"
+#line 567 "parse-gram.y"
     { (yyval.chars) = ""; }
 /* Line 1380 of yacc.c  */
-#line 2582 "../bison/src/parse-gram.c"
+#line 2595 "/Users/akim/src/kernel/bison/src/parse-gram.c"
     break;
 
-  case 97:
+  case 98:
 /* Line 1380 of yacc.c  */
-#line 572 "parse-gram.y"
+#line 578 "parse-gram.y"
     {
       code_props plain_code;
       (yyvsp[0].code)[strlen ((yyvsp[0].code)) - 1] = '\n';
@@ -2593,51 +2606,51 @@ yyreduce:
       (yyval.chars) = plain_code.code;
     }
 /* Line 1380 of yacc.c  */
-#line 2597 "../bison/src/parse-gram.c"
+#line 2610 "/Users/akim/src/kernel/bison/src/parse-gram.c"
     break;
 
-  case 98:
+  case 99:
 /* Line 1380 of yacc.c  */
-#line 592 "parse-gram.y"
+#line 598 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2605 "../bison/src/parse-gram.c"
+#line 2618 "/Users/akim/src/kernel/bison/src/parse-gram.c"
     break;
 
-  case 99:
+  case 100:
 /* Line 1380 of yacc.c  */
-#line 594 "parse-gram.y"
+#line 600 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[0].character)), (yylsp[0]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
       symbol_user_token_number_set ((yyval.symbol), (yyvsp[0].character), (yylsp[0]));
     }
 /* Line 1380 of yacc.c  */
-#line 2617 "../bison/src/parse-gram.c"
+#line 2630 "/Users/akim/src/kernel/bison/src/parse-gram.c"
     break;
 
-  case 100:
+  case 101:
 /* Line 1380 of yacc.c  */
-#line 602 "parse-gram.y"
+#line 608 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2625 "../bison/src/parse-gram.c"
+#line 2638 "/Users/akim/src/kernel/bison/src/parse-gram.c"
     break;
 
-  case 103:
+  case 104:
 /* Line 1380 of yacc.c  */
-#line 614 "parse-gram.y"
+#line 620 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[0].chars)), (yylsp[0]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
     }
 /* Line 1380 of yacc.c  */
-#line 2636 "../bison/src/parse-gram.c"
+#line 2649 "/Users/akim/src/kernel/bison/src/parse-gram.c"
     break;
 
-  case 105:
+  case 106:
 /* Line 1380 of yacc.c  */
-#line 623 "parse-gram.y"
+#line 629 "parse-gram.y"
     {
       code_props plain_code;
       code_props_plain_init (&plain_code, (yyvsp[0].chars), (yylsp[0]));
@@ -2647,12 +2660,12 @@ yyreduce:
       code_scanner_last_string_free ();
     }
 /* Line 1380 of yacc.c  */
-#line 2651 "../bison/src/parse-gram.c"
+#line 2664 "/Users/akim/src/kernel/bison/src/parse-gram.c"
     break;
 
 
 /* Line 1380 of yacc.c  */
-#line 2656 "../bison/src/parse-gram.c"
+#line 2669 "/Users/akim/src/kernel/bison/src/parse-gram.c"
       default: break;
     }
   YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);
@@ -2869,7 +2882,7 @@ yyreturn:
 }
 
 /* Line 1599 of yacc.c  */
-#line 633 "parse-gram.y"
+#line 639 "parse-gram.y"
 
 
 
