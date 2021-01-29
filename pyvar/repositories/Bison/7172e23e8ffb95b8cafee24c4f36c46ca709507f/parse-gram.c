@@ -218,27 +218,28 @@ static int current_prec = 0;
      PERCENT_PROVIDES = 292,
      PERCENT_PURE_PARSER = 293,
      PERCENT_PUSH_PARSER = 294,
-     PERCENT_REQUIRE = 295,
-     PERCENT_REQUIRES = 296,
-     PERCENT_SKELETON = 297,
-     PERCENT_START = 298,
-     PERCENT_TOKEN_TABLE = 299,
-     PERCENT_VERBOSE = 300,
-     PERCENT_YACC = 301,
-     BRACED_CODE = 302,
-     CHAR = 303,
-     EPILOGUE = 304,
-     EQUAL = 305,
-     ID = 306,
-     ID_COLON = 307,
-     PERCENT_PERCENT = 308,
-     PIPE = 309,
-     PROLOGUE = 310,
-     SEMICOLON = 311,
-     TYPE = 312,
-     TYPE_TAG_ANY = 313,
-     TYPE_TAG_NONE = 314,
-     PERCENT_UNION = 315
+     PERCENT_PUSH_PULL_PARSER = 295,
+     PERCENT_REQUIRE = 296,
+     PERCENT_REQUIRES = 297,
+     PERCENT_SKELETON = 298,
+     PERCENT_START = 299,
+     PERCENT_TOKEN_TABLE = 300,
+     PERCENT_VERBOSE = 301,
+     PERCENT_YACC = 302,
+     BRACED_CODE = 303,
+     CHAR = 304,
+     EPILOGUE = 305,
+     EQUAL = 306,
+     ID = 307,
+     ID_COLON = 308,
+     PERCENT_PERCENT = 309,
+     PIPE = 310,
+     PROLOGUE = 311,
+     SEMICOLON = 312,
+     TYPE = 313,
+     TYPE_TAG_ANY = 314,
+     TYPE_TAG_NONE = 315,
+     PERCENT_UNION = 316
    };
 #endif
 /* Tokens.  */
@@ -280,27 +281,28 @@ static int current_prec = 0;
 #define PERCENT_PROVIDES 292
 #define PERCENT_PURE_PARSER 293
 #define PERCENT_PUSH_PARSER 294
-#define PERCENT_REQUIRE 295
-#define PERCENT_REQUIRES 296
-#define PERCENT_SKELETON 297
-#define PERCENT_START 298
-#define PERCENT_TOKEN_TABLE 299
-#define PERCENT_VERBOSE 300
-#define PERCENT_YACC 301
-#define BRACED_CODE 302
-#define CHAR 303
-#define EPILOGUE 304
-#define EQUAL 305
-#define ID 306
-#define ID_COLON 307
-#define PERCENT_PERCENT 308
-#define PIPE 309
-#define PROLOGUE 310
-#define SEMICOLON 311
-#define TYPE 312
-#define TYPE_TAG_ANY 313
-#define TYPE_TAG_NONE 314
-#define PERCENT_UNION 315
+#define PERCENT_PUSH_PULL_PARSER 295
+#define PERCENT_REQUIRE 296
+#define PERCENT_REQUIRES 297
+#define PERCENT_SKELETON 298
+#define PERCENT_START 299
+#define PERCENT_TOKEN_TABLE 300
+#define PERCENT_VERBOSE 301
+#define PERCENT_YACC 302
+#define BRACED_CODE 303
+#define CHAR 304
+#define EPILOGUE 305
+#define EQUAL 306
+#define ID 307
+#define ID_COLON 308
+#define PERCENT_PERCENT 309
+#define PIPE 310
+#define PROLOGUE 311
+#define SEMICOLON 312
+#define TYPE 313
+#define TYPE_TAG_ANY 314
+#define TYPE_TAG_NONE 315
+#define PERCENT_UNION 316
 
 
 
@@ -322,7 +324,7 @@ typedef union YYSTYPE
 }
 
 /* Line 198 of yacc.c  */
-#line 326 "parse-gram.c"
+#line 328 "parse-gram.c"
 	YYSTYPE;
 # define YYSTYPE_IS_TRIVIAL 1
 # define yystype YYSTYPE /* obsolescent; will be withdrawn */
@@ -347,7 +349,7 @@ typedef struct YYLTYPE
 
 
 /* Line 221 of yacc.c  */
-#line 351 "parse-gram.c"
+#line 353 "parse-gram.c"
 
 #ifdef short
 # undef short
@@ -564,20 +566,20 @@ union yyalloc
 /* YYFINAL -- State number of the termination state.  */
 #define YYFINAL  3
 /* YYLAST -- Last index in YYTABLE.  */
-#define YYLAST   187
+#define YYLAST   224
 
 /* YYNTOKENS -- Number of terminals.  */
-#define YYNTOKENS  61
+#define YYNTOKENS  62
 /* YYNNTS -- Number of nonterminals.  */
 #define YYNNTS  31
 /* YYNRULES -- Number of rules.  */
-#define YYNRULES  104
+#define YYNRULES  105
 /* YYNRULES -- Number of states.  */
-#define YYNSTATES  144
+#define YYNSTATES  145
 
 /* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
 #define YYUNDEFTOK  2
-#define YYMAXUTOK   315
+#define YYMAXUTOK   316
 
 #define YYTRANSLATE(YYX)						\
   ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)
@@ -616,7 +618,7 @@ static const yytype_uint8 yytranslate[] =
       25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
       35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
       45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
-      55,    56,    57,    58,    59,    60
+      55,    56,    57,    58,    59,    60,    61
 };
 
 #if YYDEBUG
@@ -627,62 +629,62 @@ static const yytype_uint16 yyprhs[] =
        0,     0,     3,     8,     9,    12,    14,    16,    18,    22,
       24,    27,    29,    32,    35,    38,    42,    44,    47,    50,
       53,    55,    58,    62,    64,    66,    69,    73,    76,    78,
-      80,    83,    86,    88,    90,    92,    94,    96,    98,   101,
-     105,   109,   111,   113,   116,   119,   122,   125,   126,   128,
-     132,   133,   137,   138,   142,   146,   150,   152,   154,   156,
-     157,   159,   161,   164,   166,   169,   171,   173,   175,   177,
-     179,   181,   184,   187,   191,   193,   196,   198,   201,   203,
-     206,   209,   210,   214,   216,   220,   223,   224,   227,   230,
-     234,   238,   242,   244,   246,   247,   249,   251,   253,   255,
-     257,   259,   261,   263,   264
+      80,    82,    85,    88,    90,    92,    94,    96,    98,   100,
+     103,   107,   111,   113,   115,   118,   121,   124,   127,   128,
+     130,   134,   135,   139,   140,   144,   148,   152,   154,   156,
+     158,   159,   161,   163,   166,   168,   171,   173,   175,   177,
+     179,   181,   183,   186,   189,   193,   195,   198,   200,   203,
+     205,   208,   211,   212,   216,   218,   222,   225,   226,   229,
+     232,   236,   240,   244,   246,   248,   249,   251,   253,   255,
+     257,   259,   261,   263,   265,   266
 };
 
 /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
 static const yytype_int8 yyrhs[] =
 {
-      62,     0,    -1,    63,    53,    78,    91,    -1,    -1,    63,
-      64,    -1,    65,    -1,    55,    -1,    18,    -1,    20,     3,
-      85,    -1,    21,    -1,    21,     3,    -1,    22,    -1,    23,
-       4,    -1,    24,     4,    -1,    25,     3,    -1,    25,    50,
-       3,    -1,    26,    -1,    27,    47,    -1,    28,     3,    -1,
-      29,    47,    -1,    30,    -1,    31,     3,    -1,    31,    50,
+      63,     0,    -1,    64,    54,    79,    92,    -1,    -1,    64,
+      65,    -1,    66,    -1,    56,    -1,    18,    -1,    20,     3,
+      86,    -1,    21,    -1,    21,     3,    -1,    22,    -1,    23,
+       4,    -1,    24,     4,    -1,    25,     3,    -1,    25,    51,
+       3,    -1,    26,    -1,    27,    48,    -1,    28,     3,    -1,
+      29,    48,    -1,    30,    -1,    31,     3,    -1,    31,    51,
        3,    -1,    33,    -1,    34,    -1,    35,     3,    -1,    35,
-      50,     3,    -1,    36,    47,    -1,    38,    -1,    39,    -1,
-      40,     3,    -1,    42,     3,    -1,    44,    -1,    45,    -1,
-      46,    -1,    56,    -1,    70,    -1,    67,    -1,    43,    89,
-      -1,     8,    47,    74,    -1,     9,    47,    74,    -1,    19,
-      -1,    32,    -1,    16,    86,    -1,    17,    86,    -1,    37,
-      86,    -1,    41,    86,    -1,    -1,    51,    -1,    60,    66,
-      47,    -1,    -1,     6,    68,    77,    -1,    -1,     5,    69,
-      77,    -1,     7,    57,    73,    -1,    71,    72,    73,    -1,
-      10,    -1,    11,    -1,    12,    -1,    -1,    57,    -1,    89,
-      -1,    73,    89,    -1,    75,    -1,    74,    75,    -1,    89,
-      -1,    57,    -1,    58,    -1,    59,    -1,    57,    -1,    87,
-      -1,    87,     4,    -1,    87,    90,    -1,    87,     4,    90,
-      -1,    76,    -1,    77,    76,    -1,    79,    -1,    78,    79,
-      -1,    80,    -1,    65,    56,    -1,     1,    56,    -1,    -1,
-      88,    81,    82,    -1,    83,    -1,    82,    54,    83,    -1,
-      82,    56,    -1,    -1,    83,    89,    -1,    83,    47,    -1,
-      83,    13,    89,    -1,    83,    14,     4,    -1,    83,    15,
-      57,    -1,     3,    -1,    86,    -1,    -1,    84,    -1,    47,
-      -1,    51,    -1,    48,    -1,    52,    -1,    87,    -1,    90,
-      -1,     3,    -1,    -1,    53,    49,    -1
+      51,     3,    -1,    36,    48,    -1,    38,    -1,    39,    -1,
+      40,    -1,    41,     3,    -1,    43,     3,    -1,    45,    -1,
+      46,    -1,    47,    -1,    57,    -1,    71,    -1,    68,    -1,
+      44,    90,    -1,     8,    48,    75,    -1,     9,    48,    75,
+      -1,    19,    -1,    32,    -1,    16,    87,    -1,    17,    87,
+      -1,    37,    87,    -1,    42,    87,    -1,    -1,    52,    -1,
+      61,    67,    48,    -1,    -1,     6,    69,    78,    -1,    -1,
+       5,    70,    78,    -1,     7,    58,    74,    -1,    72,    73,
+      74,    -1,    10,    -1,    11,    -1,    12,    -1,    -1,    58,
+      -1,    90,    -1,    74,    90,    -1,    76,    -1,    75,    76,
+      -1,    90,    -1,    58,    -1,    59,    -1,    60,    -1,    58,
+      -1,    88,    -1,    88,     4,    -1,    88,    91,    -1,    88,
+       4,    91,    -1,    77,    -1,    78,    77,    -1,    80,    -1,
+      79,    80,    -1,    81,    -1,    66,    57,    -1,     1,    57,
+      -1,    -1,    89,    82,    83,    -1,    84,    -1,    83,    55,
+      84,    -1,    83,    57,    -1,    -1,    84,    90,    -1,    84,
+      48,    -1,    84,    13,    90,    -1,    84,    14,     4,    -1,
+      84,    15,    58,    -1,     3,    -1,    87,    -1,    -1,    85,
+      -1,    48,    -1,    52,    -1,    49,    -1,    53,    -1,    88,
+      -1,    91,    -1,     3,    -1,    -1,    54,    50,    -1
 };
 
 /* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
 static const yytype_uint16 yyrline[] =
 {
-       0,   211,   211,   219,   221,   225,   226,   227,   228,   229,
-     230,   235,   236,   237,   238,   239,   240,   245,   249,   250,
-     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
-     261,   262,   263,   264,   265,   266,   270,   271,   272,   276,
-     284,   292,   296,   300,   301,   302,   303,   314,   315,   319,
-     347,   347,   352,   352,   357,   368,   383,   384,   385,   389,
-     390,   395,   397,   402,   403,   407,   408,   409,   410,   415,
-     420,   425,   431,   437,   448,   449,   458,   459,   465,   466,
-     467,   474,   474,   478,   479,   480,   485,   486,   488,   490,
-     492,   494,   504,   505,   511,   515,   520,   536,   538,   547,
-     552,   553,   558,   565,   567
+       0,   213,   213,   221,   223,   227,   228,   229,   230,   231,
+     232,   237,   238,   239,   240,   241,   242,   247,   251,   252,
+     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
+     263,   264,   265,   266,   267,   268,   269,   273,   274,   275,
+     279,   287,   295,   299,   303,   304,   305,   306,   317,   318,
+     322,   350,   350,   355,   355,   360,   371,   386,   387,   388,
+     392,   393,   398,   400,   405,   406,   410,   411,   412,   413,
+     418,   423,   428,   434,   440,   451,   452,   461,   462,   468,
+     469,   470,   477,   477,   481,   482,   483,   488,   489,   491,
+     493,   495,   497,   507,   508,   514,   518,   523,   539,   541,
+     550,   555,   556,   561,   568,   570
 };
 #endif
 
@@ -701,13 +703,13 @@ static const char *const yytname[] =
   "\"%locations\"", "\"%name-prefix\"", "\"%no-default-prec\"",
   "\"%no-lines\"", "\"%nondeterministic-parser\"", "\"%output\"",
   "\"%parse-param\"", "\"%provides\"", "\"%pure-parser\"",
-  "\"%push-parser\"", "\"%require\"", "\"%requires\"", "\"%skeleton\"",
-  "\"%start\"", "\"%token-table\"", "\"%verbose\"", "\"%yacc\"",
-  "\"{...}\"", "\"char\"", "\"epilogue\"", "\"=\"", "\"identifier\"",
-  "\"identifier:\"", "\"%%\"", "\"|\"", "\"%{...%}\"", "\";\"", "\"type\"",
-  "\"<*>\"", "\"<>\"", "\"%union\"", "$accept", "input",
-  "prologue_declarations", "prologue_declaration", "grammar_declaration",
-  "union_name", "symbol_declaration", "$@1", "$@2",
+  "\"%push-parser\"", "\"%push-pull-parser\"", "\"%require\"",
+  "\"%requires\"", "\"%skeleton\"", "\"%start\"", "\"%token-table\"",
+  "\"%verbose\"", "\"%yacc\"", "\"{...}\"", "\"char\"", "\"epilogue\"",
+  "\"=\"", "\"identifier\"", "\"identifier:\"", "\"%%\"", "\"|\"",
+  "\"%{...%}\"", "\";\"", "\"type\"", "\"<*>\"", "\"<>\"", "\"%union\"",
+  "$accept", "input", "prologue_declarations", "prologue_declaration",
+  "grammar_declaration", "union_name", "symbol_declaration", "$@1", "$@2",
   "precedence_declaration", "precedence_declarator", "type.opt",
   "symbols.1", "generic_symlist", "generic_symlist_item", "symbol_def",
   "symbol_defs.1", "grammar", "rules_or_grammar_declaration", "rules",
@@ -727,24 +729,24 @@ static const yytype_uint16 yytoknum[] =
      285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
      295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
      305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
-     315
+     315,   316
 };
 # endif
 
 /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
 static const yytype_uint8 yyr1[] =
 {
-       0,    61,    62,    63,    63,    64,    64,    64,    64,    64,
-      64,    64,    64,    64,    64,    64,    64,    64,    64,    64,
-      64,    64,    64,    64,    64,    64,    64,    64,    64,    64,
-      64,    64,    64,    64,    64,    64,    65,    65,    65,    65,
-      65,    65,    65,    65,    65,    65,    65,    66,    66,    65,
-      68,    67,    69,    67,    67,    70,    71,    71,    71,    72,
-      72,    73,    73,    74,    74,    75,    75,    75,    75,    76,
-      76,    76,    76,    76,    77,    77,    78,    78,    79,    79,
-      79,    81,    80,    82,    82,    82,    83,    83,    83,    83,
-      83,    83,    84,    84,    85,    85,    86,    87,    87,    88,
-      89,    89,    90,    91,    91
+       0,    62,    63,    64,    64,    65,    65,    65,    65,    65,
+      65,    65,    65,    65,    65,    65,    65,    65,    65,    65,
+      65,    65,    65,    65,    65,    65,    65,    65,    65,    65,
+      65,    65,    65,    65,    65,    65,    65,    66,    66,    66,
+      66,    66,    66,    66,    66,    66,    66,    66,    67,    67,
+      66,    69,    68,    70,    68,    68,    71,    72,    72,    72,
+      73,    73,    74,    74,    75,    75,    76,    76,    76,    76,
+      77,    77,    77,    77,    77,    78,    78,    79,    79,    80,
+      80,    80,    82,    81,    83,    83,    83,    84,    84,    84,
+      84,    84,    84,    85,    85,    86,    86,    87,    88,    88,
+      89,    90,    90,    91,    92,    92
 };
 
 /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
@@ -753,14 +755,14 @@ static const yytype_uint8 yyr2[] =
        0,     2,     4,     0,     2,     1,     1,     1,     3,     1,
        2,     1,     2,     2,     2,     3,     1,     2,     2,     2,
        1,     2,     3,     1,     1,     2,     3,     2,     1,     1,
-       2,     2,     1,     1,     1,     1,     1,     1,     2,     3,
-       3,     1,     1,     2,     2,     2,     2,     0,     1,     3,
-       0,     3,     0,     3,     3,     3,     1,     1,     1,     0,
-       1,     1,     2,     1,     2,     1,     1,     1,     1,     1,
-       1,     2,     2,     3,     1,     2,     1,     2,     1,     2,
-       2,     0,     3,     1,     3,     2,     0,     2,     2,     3,
-       3,     3,     1,     1,     0,     1,     1,     1,     1,     1,
-       1,     1,     1,     0,     2
+       1,     2,     2,     1,     1,     1,     1,     1,     1,     2,
+       3,     3,     1,     1,     2,     2,     2,     2,     0,     1,
+       3,     0,     3,     0,     3,     3,     3,     1,     1,     1,
+       0,     1,     1,     2,     1,     2,     1,     1,     1,     1,
+       1,     1,     2,     2,     3,     1,     2,     1,     2,     1,
+       2,     2,     0,     3,     1,     3,     2,     0,     2,     2,
+       3,     3,     3,     1,     1,     0,     1,     1,     1,     1,
+       1,     1,     1,     1,     0,     2
 };
 
 /* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
@@ -768,133 +770,141 @@ static const yytype_uint8 yyr2[] =
    means the default is an error.  */
 static const yytype_uint8 yydefact[] =
 {
-       3,     0,     0,     1,    52,    50,     0,     0,     0,    56,
-      57,    58,     0,     0,     7,    41,     0,     9,    11,     0,
-       0,     0,    16,     0,     0,     0,    20,     0,    42,    23,
-      24,     0,     0,     0,    28,    29,     0,     0,     0,     0,
-      32,    33,    34,     0,     6,    35,    47,     4,     5,    37,
-      36,    59,     0,     0,     0,     0,     0,    96,    43,    44,
-      94,    10,    12,    13,    14,     0,    17,    18,    19,    21,
-       0,    25,     0,    27,    45,    30,    46,    31,   102,    98,
-      97,   100,    38,   101,     0,    99,     0,     0,    76,    78,
-      81,    48,     0,    60,     0,    69,    74,    53,    70,    51,
-      54,    61,    66,    67,    68,    39,    63,    65,    40,    92,
-      95,     8,    93,    15,    22,    26,    80,    79,     0,    77,
-       2,    86,    49,    55,    75,    71,    72,    62,    64,   104,
-      82,    83,    73,    86,    85,     0,     0,     0,    88,    87,
-      84,    89,    90,    91
+       3,     0,     0,     1,    53,    51,     0,     0,     0,    57,
+      58,    59,     0,     0,     7,    42,     0,     9,    11,     0,
+       0,     0,    16,     0,     0,     0,    20,     0,    43,    23,
+      24,     0,     0,     0,    28,    29,    30,     0,     0,     0,
+       0,    33,    34,    35,     0,     6,    36,    48,     4,     5,
+      38,    37,    60,     0,     0,     0,     0,     0,    97,    44,
+      45,    95,    10,    12,    13,    14,     0,    17,    18,    19,
+      21,     0,    25,     0,    27,    46,    31,    47,    32,   103,
+      99,    98,   101,    39,   102,     0,   100,     0,     0,    77,
+      79,    82,    49,     0,    61,     0,    70,    75,    54,    71,
+      52,    55,    62,    67,    68,    69,    40,    64,    66,    41,
+      93,    96,     8,    94,    15,    22,    26,    81,    80,     0,
+      78,     2,    87,    50,    56,    76,    72,    73,    63,    65,
+     105,    83,    84,    74,    87,    86,     0,     0,     0,    89,
+      88,    85,    90,    91,    92
 };
 
 /* YYDEFGOTO[NTERM-NUM].  */
 static const yytype_int16 yydefgoto[] =
 {
-      -1,     1,     2,    47,    86,    92,    49,    53,    52,    50,
-      51,    94,   100,   105,   106,    96,    97,    87,    88,    89,
-     121,   130,   131,   110,   111,    58,    81,    90,   107,    83,
-     120
+      -1,     1,     2,    48,    87,    93,    50,    54,    53,    51,
+      52,    95,   101,   106,   107,    97,    98,    88,    89,    90,
+     122,   131,   132,   111,   112,    59,    82,    91,   108,    84,
+     121
 };
 
 /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
    STATE-NUM.  */
-#define YYPACT_NINF -95
-static const yytype_int8 yypact[] =
+#define YYPACT_NINF -100
+static const yytype_int16 yypact[] =
 {
-     -95,     3,   127,   -95,   -95,   -95,   -24,    -7,    -6,   -95,
-     -95,   -95,    -3,    -3,   -95,   -95,    42,    56,   -95,    70,
-      87,    10,   -95,    28,    90,    47,   -95,    35,   -95,   -95,
-     -95,    36,    48,    -3,   -95,   -95,    94,    -3,    95,    -2,
-     -95,   -95,   -95,    71,   -95,   -95,    49,   -95,   -95,   -95,
-     -95,    45,   -43,   -43,    -2,    -1,    -1,   -95,   -95,   -95,
-      21,   -95,   -95,   -95,   -95,    96,   -95,   -95,   -95,   -95,
-     101,   -95,   102,   -95,   -95,   -95,   -95,   -95,   -95,   -95,
-     -95,   -95,   -95,   -95,    50,   -95,    51,    11,   -95,   -95,
-     -95,   -95,    62,   -95,    -2,   -95,   -95,   -43,     6,   -43,
-      -2,   -95,   -95,   -95,   -95,    -1,   -95,   -95,    -1,   -95,
-     -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,    61,   -95,
-     -95,   -95,   -95,    -2,   -95,   108,   -95,   -95,   -95,   -95,
-     -22,    22,   -95,   -95,   -95,    -2,   109,    58,   -95,   -95,
-      22,   -95,   -95,   -95
+    -100,     3,   127,  -100,  -100,  -100,   -50,   -22,   -11,  -100,
+    -100,  -100,    -3,    -3,  -100,  -100,    37,    43,  -100,    56,
+      59,     1,  -100,    19,    65,    21,  -100,    11,  -100,  -100,
+    -100,    13,    22,    -3,  -100,  -100,  -100,    71,    -3,    85,
+      -2,  -100,  -100,  -100,    70,  -100,  -100,    38,  -100,  -100,
+    -100,  -100,    33,   -17,   -17,    -2,    -1,    -1,  -100,  -100,
+    -100,    24,  -100,  -100,  -100,  -100,    90,  -100,  -100,  -100,
+    -100,    91,  -100,    92,  -100,  -100,  -100,  -100,  -100,  -100,
+    -100,  -100,  -100,  -100,  -100,    40,  -100,    41,    12,  -100,
+    -100,  -100,  -100,    51,  -100,    -2,  -100,  -100,   -17,    39,
+     -17,    -2,  -100,  -100,  -100,  -100,    -1,  -100,  -100,    -1,
+    -100,  -100,  -100,  -100,  -100,  -100,  -100,  -100,  -100,    50,
+    -100,  -100,  -100,  -100,    -2,  -100,   100,  -100,  -100,  -100,
+    -100,   -46,   172,  -100,  -100,  -100,    -2,   101,    46,  -100,
+    -100,   172,  -100,  -100,  -100
 };
 
 /* YYPGOTO[NTERM-NUM].  */
 static const yytype_int8 yypgoto[] =
 {
-     -95,   -95,   -95,   -95,   114,   -95,   -95,   -95,   -95,   -95,
-     -95,   -95,    23,    63,   -79,   -32,    65,   -95,    33,   -95,
-     -95,   -95,   -12,   -95,   -95,    29,   -46,   -95,   -39,   -94,
-     -95
+    -100,  -100,  -100,  -100,   104,  -100,  -100,  -100,  -100,  -100,
+    -100,  -100,    14,    53,   -99,   -64,    54,  -100,    23,  -100,
+    -100,  -100,   -21,  -100,  -100,    -8,   -15,  -100,   -40,   -93,
+    -100
 };
 
 /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
    positive, shift that token.  If negative, reduce the rule which
    number is the opposite.  If zero, do what YYDEFACT says.
    If YYTABLE_NINF, syntax error.  */
-#define YYTABLE_NINF -104
+#define YYTABLE_NINF -105
 static const yytype_int16 yytable[] =
 {
-      82,    78,    78,     3,   126,    79,    98,    98,    80,    78,
-     125,  -103,    84,    64,    95,   101,     4,     5,     6,     7,
-       8,     9,    10,    11,   109,    78,   128,    12,    13,   128,
-      15,   132,   133,    54,   134,   135,   136,   137,    69,    71,
-      55,    56,    59,    28,    57,    60,    79,    79,    33,    80,
-      80,    98,    37,    98,    39,   101,   102,   103,   104,    61,
-      65,   127,    74,    85,   118,   124,    76,   124,    57,   138,
-      79,    46,    84,    80,    62,    66,     4,     5,     6,     7,
-       8,     9,    10,    11,   127,    70,    72,    12,    13,   112,
-      15,    63,   139,    67,    68,    73,   141,    75,    77,   113,
-      91,   139,    93,    28,   114,   115,   116,   117,    33,   122,
-     129,    78,    37,   142,    39,   143,    48,   123,    99,   108,
-     119,   140,     0,    85,     0,     0,     0,     0,     0,     0,
-       0,    46,     4,     5,     6,     7,     8,     9,    10,    11,
+      83,    79,    79,     3,    65,    60,   127,   129,    55,   134,
+     129,   135,  -104,    85,    70,   102,    72,     4,     5,     6,
+       7,     8,     9,    10,    11,    75,    56,   110,    12,    13,
+      77,    15,    80,   133,   125,    81,   125,    57,    99,    99,
+      61,    96,    79,   126,    28,    58,    62,    80,    80,    33,
+      81,    81,    66,   113,    38,   102,    40,   103,   104,   105,
+      63,   128,    71,    64,    73,    86,   119,    67,    68,    69,
+      74,    85,    58,    47,    76,     4,     5,     6,     7,     8,
+       9,    10,    11,    99,   128,    99,    12,    13,    78,    15,
+      92,    94,   140,   114,   115,   116,   142,   117,   118,   123,
+     130,   140,    28,    79,   144,   143,    49,    33,   100,   124,
+     109,   120,    38,   141,    40,     0,     0,     0,     0,     0,
+       0,     0,     0,    86,     0,     0,     0,     0,     0,     0,
+       0,    47,     4,     5,     6,     7,     8,     9,    10,    11,
        0,     0,     0,    12,    13,    14,    15,    16,    17,    18,
       19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
       29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
-      39,    40,    41,    42,     0,     0,     0,     0,     0,     0,
-      43,     0,    44,    45,     0,     0,     0,    46
+      39,    40,    41,    42,    43,    79,     0,     0,     0,     0,
+       0,    44,     0,    45,    46,   136,   137,   138,    47,     0,
+       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
+       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
+       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
+     139,    80,     0,     0,    81
 };
 
 static const yytype_int16 yycheck[] =
 {
-      39,     3,     3,     0,    98,    48,    52,    53,    51,     3,
-       4,     0,     1,     3,    57,    54,     5,     6,     7,     8,
-       9,    10,    11,    12,     3,     3,   105,    16,    17,   108,
-      19,   125,    54,    57,    56,    13,    14,    15,     3,     3,
-      47,    47,    13,    32,    47,     3,    48,    48,    37,    51,
-      51,    97,    41,    99,    43,    94,    57,    58,    59,     3,
-      50,   100,    33,    52,    53,    97,    37,    99,    47,    47,
-      48,    60,     1,    51,     4,    47,     5,     6,     7,     8,
-       9,    10,    11,    12,   123,    50,    50,    16,    17,    60,
-      19,     4,   131,     3,    47,    47,   135,     3,     3,     3,
-      51,   140,    57,    32,     3,     3,    56,    56,    37,    47,
-      49,     3,    41,     4,    43,    57,     2,    94,    53,    56,
-      87,   133,    -1,    52,    -1,    -1,    -1,    -1,    -1,    -1,
-      -1,    60,     5,     6,     7,     8,     9,    10,    11,    12,
+      40,     3,     3,     0,     3,    13,    99,   106,    58,    55,
+     109,    57,     0,     1,     3,    55,     3,     5,     6,     7,
+       8,     9,    10,    11,    12,    33,    48,     3,    16,    17,
+      38,    19,    49,   126,    98,    52,   100,    48,    53,    54,
+       3,    58,     3,     4,    32,    48,     3,    49,    49,    37,
+      52,    52,    51,    61,    42,    95,    44,    58,    59,    60,
+       4,   101,    51,     4,    51,    53,    54,    48,     3,    48,
+      48,     1,    48,    61,     3,     5,     6,     7,     8,     9,
+      10,    11,    12,    98,   124,   100,    16,    17,     3,    19,
+      52,    58,   132,     3,     3,     3,   136,    57,    57,    48,
+      50,   141,    32,     3,    58,     4,     2,    37,    54,    95,
+      57,    88,    42,   134,    44,    -1,    -1,    -1,    -1,    -1,
+      -1,    -1,    -1,    53,    -1,    -1,    -1,    -1,    -1,    -1,
+      -1,    61,     5,     6,     7,     8,     9,    10,    11,    12,
       -1,    -1,    -1,    16,    17,    18,    19,    20,    21,    22,
       23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
       33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
-      43,    44,    45,    46,    -1,    -1,    -1,    -1,    -1,    -1,
-      53,    -1,    55,    56,    -1,    -1,    -1,    60
+      43,    44,    45,    46,    47,     3,    -1,    -1,    -1,    -1,
+      -1,    54,    -1,    56,    57,    13,    14,    15,    61,    -1,
+      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
+      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
+      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
+      48,    49,    -1,    -1,    52
 };
 
 /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
    symbol of state STATE-NUM.  */
 static const yytype_uint8 yystos[] =
 {
-       0,    62,    63,     0,     5,     6,     7,     8,     9,    10,
+       0,    63,    64,     0,     5,     6,     7,     8,     9,    10,
       11,    12,    16,    17,    18,    19,    20,    21,    22,    23,
       24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
       34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
-      44,    45,    46,    53,    55,    56,    60,    64,    65,    67,
-      70,    71,    69,    68,    57,    47,    47,    47,    86,    86,
-       3,     3,     4,     4,     3,    50,    47,     3,    47,     3,
-      50,     3,    50,    47,    86,     3,    86,     3,     3,    48,
-      51,    87,    89,    90,     1,    52,    65,    78,    79,    80,
-      88,    51,    66,    57,    72,    57,    76,    77,    87,    77,
-      73,    89,    57,    58,    59,    74,    75,    89,    74,     3,
-      84,    85,    86,     3,     3,     3,    56,    56,    53,    79,
-      91,    81,    47,    73,    76,     4,    90,    89,    75,    49,
-      82,    83,    90,    54,    56,    13,    14,    15,    47,    89,
-      83,    89,     4,    57
+      44,    45,    46,    47,    54,    56,    57,    61,    65,    66,
+      68,    71,    72,    70,    69,    58,    48,    48,    48,    87,
+      87,     3,     3,     4,     4,     3,    51,    48,     3,    48,
+       3,    51,     3,    51,    48,    87,     3,    87,     3,     3,
+      49,    52,    88,    90,    91,     1,    53,    66,    79,    80,
+      81,    89,    52,    67,    58,    73,    58,    77,    78,    88,
+      78,    74,    90,    58,    59,    60,    75,    76,    90,    75,
+       3,    85,    86,    87,     3,     3,     3,    57,    57,    54,
+      80,    92,    82,    48,    74,    77,     4,    91,    90,    76,
+      50,    83,    84,    91,    55,    57,    13,    14,    15,    48,
+      90,    84,    90,     4,    58
 };
 
 #define yyerrok		(yyerrstatus = 0)
@@ -1045,146 +1055,146 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
       case 3: /* "\"string\"" */
 
 /* Line 670 of yacc.c  */
-#line 189 "parse-gram.y"
+#line 191 "parse-gram.y"
 	{ fputs (quotearg_style (c_quoting_style, (yyvaluep->chars)), stderr); };
 
 /* Line 670 of yacc.c  */
-#line 1053 "parse-gram.c"
+#line 1063 "parse-gram.c"
 	break;
       case 4: /* "\"integer\"" */
 
 /* Line 670 of yacc.c  */
-#line 200 "parse-gram.y"
+#line 202 "parse-gram.y"
 	{ fprintf (stderr, "%d", (yyvaluep->integer)); };
 
 /* Line 670 of yacc.c  */
-#line 1062 "parse-gram.c"
+#line 1072 "parse-gram.c"
 	break;
-      case 47: /* "\"{...}\"" */
+      case 48: /* "\"{...}\"" */
 
 /* Line 670 of yacc.c  */
-#line 191 "parse-gram.y"
+#line 193 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->code)); };
 
 /* Line 670 of yacc.c  */
-#line 1071 "parse-gram.c"
+#line 1081 "parse-gram.c"
 	break;
-      case 48: /* "\"char\"" */
+      case 49: /* "\"char\"" */
 
 /* Line 670 of yacc.c  */
-#line 183 "parse-gram.y"
+#line 185 "parse-gram.y"
 	{ fputs (char_name ((yyvaluep->character)), stderr); };
 
 /* Line 670 of yacc.c  */
-#line 1080 "parse-gram.c"
+#line 1090 "parse-gram.c"
 	break;
-      case 49: /* "\"epilogue\"" */
+      case 50: /* "\"epilogue\"" */
 
 /* Line 670 of yacc.c  */
-#line 191 "parse-gram.y"
+#line 193 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
 /* Line 670 of yacc.c  */
-#line 1089 "parse-gram.c"
+#line 1099 "parse-gram.c"
 	break;
-      case 51: /* "\"identifier\"" */
+      case 52: /* "\"identifier\"" */
 
 /* Line 670 of yacc.c  */
-#line 196 "parse-gram.y"
+#line 198 "parse-gram.y"
 	{ fputs ((yyvaluep->uniqstr), stderr); };
 
 /* Line 670 of yacc.c  */
-#line 1098 "parse-gram.c"
+#line 1108 "parse-gram.c"
 	break;
-      case 52: /* "\"identifier:\"" */
+      case 53: /* "\"identifier:\"" */
 
 /* Line 670 of yacc.c  */
-#line 197 "parse-gram.y"
+#line 199 "parse-gram.y"
 	{ fprintf (stderr, "%s:", (yyvaluep->uniqstr)); };
 
 /* Line 670 of yacc.c  */
-#line 1107 "parse-gram.c"
+#line 1117 "parse-gram.c"
 	break;
-      case 55: /* "\"%{...%}\"" */
+      case 56: /* "\"%{...%}\"" */
 
 /* Line 670 of yacc.c  */
-#line 191 "parse-gram.y"
+#line 193 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
 /* Line 670 of yacc.c  */
-#line 1116 "parse-gram.c"
+#line 1126 "parse-gram.c"
 	break;
-      case 57: /* "\"type\"" */
+      case 58: /* "\"type\"" */
 
 /* Line 670 of yacc.c  */
-#line 195 "parse-gram.y"
+#line 197 "parse-gram.y"
 	{ fprintf (stderr, "<%s>", (yyvaluep->uniqstr)); };
 
 /* Line 670 of yacc.c  */
-#line 1125 "parse-gram.c"
+#line 1135 "parse-gram.c"
 	break;
-      case 84: /* "content" */
+      case 85: /* "content" */
 
 /* Line 670 of yacc.c  */
-#line 191 "parse-gram.y"
+#line 193 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
 /* Line 670 of yacc.c  */
-#line 1134 "parse-gram.c"
+#line 1144 "parse-gram.c"
 	break;
-      case 85: /* "content.opt" */
+      case 86: /* "content.opt" */
 
 /* Line 670 of yacc.c  */
-#line 191 "parse-gram.y"
+#line 193 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
 /* Line 670 of yacc.c  */
-#line 1143 "parse-gram.c"
+#line 1153 "parse-gram.c"
 	break;
-      case 86: /* "braceless" */
+      case 87: /* "braceless" */
 
 /* Line 670 of yacc.c  */
-#line 191 "parse-gram.y"
+#line 193 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
 /* Line 670 of yacc.c  */
-#line 1152 "parse-gram.c"
+#line 1162 "parse-gram.c"
 	break;
-      case 87: /* "id" */
+      case 88: /* "id" */
 
 /* Line 670 of yacc.c  */
-#line 203 "parse-gram.y"
+#line 205 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
 /* Line 670 of yacc.c  */
-#line 1161 "parse-gram.c"
+#line 1171 "parse-gram.c"
 	break;
-      case 88: /* "id_colon" */
+      case 89: /* "id_colon" */
 
 /* Line 670 of yacc.c  */
-#line 204 "parse-gram.y"
+#line 206 "parse-gram.y"
 	{ fprintf (stderr, "%s:", (yyvaluep->symbol)->tag); };
 
 /* Line 670 of yacc.c  */
-#line 1170 "parse-gram.c"
+#line 1180 "parse-gram.c"
 	break;
-      case 89: /* "symbol" */
+      case 90: /* "symbol" */
 
 /* Line 670 of yacc.c  */
-#line 203 "parse-gram.y"
+#line 205 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
 /* Line 670 of yacc.c  */
-#line 1179 "parse-gram.c"
+#line 1189 "parse-gram.c"
 	break;
-      case 90: /* "string_as_id" */
+      case 91: /* "string_as_id" */
 
 /* Line 670 of yacc.c  */
-#line 203 "parse-gram.y"
+#line 205 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
 /* Line 670 of yacc.c  */
-#line 1188 "parse-gram.c"
+#line 1198 "parse-gram.c"
 	break;
       default:
 	break;
@@ -1708,7 +1718,7 @@ YYLTYPE yylloc;
 }
 
 /* Line 1082 of yacc.c  */
-#line 1712 "parse-gram.c"
+#line 1722 "parse-gram.c"
   yylsp[0] = yylloc;
   goto yysetstate;
 
@@ -1894,35 +1904,35 @@ yyreduce:
         case 6:
 
 /* Line 1269 of yacc.c  */
-#line 226 "parse-gram.y"
+#line 228 "parse-gram.y"
     { prologue_augment (translate_code ((yyvsp[(1) - (1)].chars), (yylsp[(1) - (1)])), (yylsp[(1) - (1)]), union_seen); }
     break;
 
   case 7:
 
 /* Line 1269 of yacc.c  */
-#line 227 "parse-gram.y"
+#line 229 "parse-gram.y"
     { debug_flag = true; }
     break;
 
   case 8:
 
 /* Line 1269 of yacc.c  */
-#line 228 "parse-gram.y"
+#line 230 "parse-gram.y"
     { muscle_insert ((yyvsp[(2) - (3)].chars), (yyvsp[(3) - (3)].chars)); }
     break;
 
   case 9:
 
 /* Line 1269 of yacc.c  */
-#line 229 "parse-gram.y"
+#line 231 "parse-gram.y"
     { defines_flag = true; }
     break;
 
   case 10:
 
 /* Line 1269 of yacc.c  */
-#line 231 "parse-gram.y"
+#line 233 "parse-gram.y"
     {
       defines_flag = true;
       spec_defines_file = xstrdup ((yyvsp[(2) - (2)].chars));
@@ -1932,42 +1942,42 @@ yyreduce:
   case 11:
 
 /* Line 1269 of yacc.c  */
-#line 235 "parse-gram.y"
+#line 237 "parse-gram.y"
     { error_verbose = true; }
     break;
 
   case 12:
 
 /* Line 1269 of yacc.c  */
-#line 236 "parse-gram.y"
+#line 238 "parse-gram.y"
     { expected_sr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 13:
 
 /* Line 1269 of yacc.c  */
-#line 237 "parse-gram.y"
+#line 239 "parse-gram.y"
     { expected_rr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 14:
 
 /* Line 1269 of yacc.c  */
-#line 238 "parse-gram.y"
+#line 240 "parse-gram.y"
     { spec_file_prefix = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 15:
 
 /* Line 1269 of yacc.c  */
-#line 239 "parse-gram.y"
+#line 241 "parse-gram.y"
     { spec_file_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 16:
 
 /* Line 1269 of yacc.c  */
-#line 241 "parse-gram.y"
+#line 243 "parse-gram.y"
     {
       nondeterministic_parser = true;
       glr_parser = true;
@@ -1977,7 +1987,7 @@ yyreduce:
   case 17:
 
 /* Line 1269 of yacc.c  */
-#line 246 "parse-gram.y"
+#line 248 "parse-gram.y"
     {
       muscle_code_grow ("initial_action", translate_symbol_action ((yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])), (yylsp[(2) - (2)]));
     }
@@ -1986,135 +1996,142 @@ yyreduce:
   case 18:
 
 /* Line 1269 of yacc.c  */
-#line 249 "parse-gram.y"
+#line 251 "parse-gram.y"
     { language_argmatch ((yyvsp[(2) - (2)].chars), 1, &(yylsp[(1) - (2)])); }
     break;
 
   case 19:
 
 /* Line 1269 of yacc.c  */
-#line 250 "parse-gram.y"
+#line 252 "parse-gram.y"
     { add_param ("lex_param", (yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
     break;
 
   case 20:
 
 /* Line 1269 of yacc.c  */
-#line 251 "parse-gram.y"
+#line 253 "parse-gram.y"
     { locations_flag = true; }
     break;
 
   case 21:
 
 /* Line 1269 of yacc.c  */
-#line 252 "parse-gram.y"
+#line 254 "parse-gram.y"
     { spec_name_prefix = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 22:
 
 /* Line 1269 of yacc.c  */
-#line 253 "parse-gram.y"
+#line 255 "parse-gram.y"
     { spec_name_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 23:
 
 /* Line 1269 of yacc.c  */
-#line 254 "parse-gram.y"
+#line 256 "parse-gram.y"
     { no_lines_flag = true; }
     break;
 
   case 24:
 
 /* Line 1269 of yacc.c  */
-#line 255 "parse-gram.y"
+#line 257 "parse-gram.y"
     { nondeterministic_parser = true; }
     break;
 
   case 25:
 
 /* Line 1269 of yacc.c  */
-#line 256 "parse-gram.y"
+#line 258 "parse-gram.y"
     { spec_outfile = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 26:
 
 /* Line 1269 of yacc.c  */
-#line 257 "parse-gram.y"
+#line 259 "parse-gram.y"
     { spec_outfile = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 27:
 
 /* Line 1269 of yacc.c  */
-#line 258 "parse-gram.y"
+#line 260 "parse-gram.y"
     { add_param ("parse_param", (yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
     break;
 
   case 28:
 
 /* Line 1269 of yacc.c  */
-#line 259 "parse-gram.y"
+#line 261 "parse-gram.y"
     { pure_parser = true; }
     break;
 
   case 29:
 
 /* Line 1269 of yacc.c  */
-#line 260 "parse-gram.y"
-    { push_parser = true; }
+#line 262 "parse-gram.y"
+    { push_parser = true; pull_parser = false; }
     break;
 
   case 30:
 
 /* Line 1269 of yacc.c  */
-#line 261 "parse-gram.y"
-    { version_check (&(yylsp[(2) - (2)]), (yyvsp[(2) - (2)].chars)); }
+#line 263 "parse-gram.y"
+    { push_parser = true; pull_parser = true; }
     break;
 
   case 31:
 
 /* Line 1269 of yacc.c  */
-#line 262 "parse-gram.y"
-    { skeleton_arg ((yyvsp[(2) - (2)].chars), 1, &(yylsp[(1) - (2)])); }
+#line 264 "parse-gram.y"
+    { version_check (&(yylsp[(2) - (2)]), (yyvsp[(2) - (2)].chars)); }
     break;
 
   case 32:
 
 /* Line 1269 of yacc.c  */
-#line 263 "parse-gram.y"
-    { token_table_flag = true; }
+#line 265 "parse-gram.y"
+    { skeleton_arg ((yyvsp[(2) - (2)].chars), 1, &(yylsp[(1) - (2)])); }
     break;
 
   case 33:
 
 /* Line 1269 of yacc.c  */
-#line 264 "parse-gram.y"
-    { report_flag = report_states; }
+#line 266 "parse-gram.y"
+    { token_table_flag = true; }
     break;
 
   case 34:
 
 /* Line 1269 of yacc.c  */
-#line 265 "parse-gram.y"
+#line 267 "parse-gram.y"
+    { report_flag = report_states; }
+    break;
+
+  case 35:
+
+/* Line 1269 of yacc.c  */
+#line 268 "parse-gram.y"
     { yacc_flag = true; }
     break;
 
-  case 38:
+  case 39:
 
 /* Line 1269 of yacc.c  */
-#line 273 "parse-gram.y"
+#line 276 "parse-gram.y"
     {
       grammar_start_symbol_set ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]));
     }
     break;
 
-  case 39:
+  case 40:
 
 /* Line 1269 of yacc.c  */
-#line 277 "parse-gram.y"
+#line 280 "parse-gram.y"
     {
       symbol_list *list;
       const char *action = translate_symbol_action ((yyvsp[(2) - (3)].code), (yylsp[(2) - (3)]));
@@ -2124,10 +2141,10 @@ yyreduce:
     }
     break;
 
-  case 40:
+  case 41:
 
 /* Line 1269 of yacc.c  */
-#line 285 "parse-gram.y"
+#line 288 "parse-gram.y"
     {
       symbol_list *list;
       const char *action = translate_symbol_action ((yyvsp[(2) - (3)].code), (yylsp[(2) - (3)]));
@@ -2137,70 +2154,70 @@ yyreduce:
     }
     break;
 
-  case 41:
+  case 42:
 
 /* Line 1269 of yacc.c  */
-#line 293 "parse-gram.y"
+#line 296 "parse-gram.y"
     {
       default_prec = true;
     }
     break;
 
-  case 42:
+  case 43:
 
 /* Line 1269 of yacc.c  */
-#line 297 "parse-gram.y"
+#line 300 "parse-gram.y"
     {
       default_prec = false;
     }
     break;
 
-  case 43:
+  case 44:
 
 /* Line 1269 of yacc.c  */
-#line 300 "parse-gram.y"
+#line 303 "parse-gram.y"
     { prologue_augment ((yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)]), true); }
     break;
 
-  case 44:
+  case 45:
 
 /* Line 1269 of yacc.c  */
-#line 301 "parse-gram.y"
+#line 304 "parse-gram.y"
     { prologue_augment ((yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)]), false); }
     break;
 
-  case 45:
+  case 46:
 
 /* Line 1269 of yacc.c  */
-#line 302 "parse-gram.y"
+#line 305 "parse-gram.y"
     { muscle_code_grow ("provides", (yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])); }
     break;
 
-  case 46:
+  case 47:
 
 /* Line 1269 of yacc.c  */
-#line 303 "parse-gram.y"
+#line 306 "parse-gram.y"
     { muscle_code_grow ("requires", (yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])); }
     break;
 
-  case 47:
+  case 48:
 
 /* Line 1269 of yacc.c  */
-#line 314 "parse-gram.y"
+#line 317 "parse-gram.y"
     {}
     break;
 
-  case 48:
+  case 49:
 
 /* Line 1269 of yacc.c  */
-#line 315 "parse-gram.y"
+#line 318 "parse-gram.y"
     { muscle_code_grow ("union_name", (yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
-  case 49:
+  case 50:
 
 /* Line 1269 of yacc.c  */
-#line 320 "parse-gram.y"
+#line 323 "parse-gram.y"
     {
       char const *body = (yyvsp[(3) - (3)].code);
 
@@ -2224,44 +2241,44 @@ yyreduce:
     }
     break;
 
-  case 50:
+  case 51:
 
 /* Line 1269 of yacc.c  */
-#line 347 "parse-gram.y"
+#line 350 "parse-gram.y"
     { current_class = nterm_sym; }
     break;
 
-  case 51:
+  case 52:
 
 /* Line 1269 of yacc.c  */
-#line 348 "parse-gram.y"
+#line 351 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
     break;
 
-  case 52:
+  case 53:
 
 /* Line 1269 of yacc.c  */
-#line 352 "parse-gram.y"
+#line 355 "parse-gram.y"
     { current_class = token_sym; }
     break;
 
-  case 53:
+  case 54:
 
 /* Line 1269 of yacc.c  */
-#line 353 "parse-gram.y"
+#line 356 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
     break;
 
-  case 54:
+  case 55:
 
 /* Line 1269 of yacc.c  */
-#line 358 "parse-gram.y"
+#line 361 "parse-gram.y"
     {
       symbol_list *list;
       tag_seen = true;
@@ -2271,10 +2288,10 @@ yyreduce:
     }
     break;
 
-  case 55:
+  case 56:
 
 /* Line 1269 of yacc.c  */
-#line 369 "parse-gram.y"
+#line 372 "parse-gram.y"
     {
       symbol_list *list;
       ++current_prec;
@@ -2288,121 +2305,121 @@ yyreduce:
     }
     break;
 
-  case 56:
+  case 57:
 
 /* Line 1269 of yacc.c  */
-#line 383 "parse-gram.y"
+#line 386 "parse-gram.y"
     { (yyval.assoc) = left_assoc; }
     break;
 
-  case 57:
+  case 58:
 
 /* Line 1269 of yacc.c  */
-#line 384 "parse-gram.y"
+#line 387 "parse-gram.y"
     { (yyval.assoc) = right_assoc; }
     break;
 
-  case 58:
+  case 59:
 
 /* Line 1269 of yacc.c  */
-#line 385 "parse-gram.y"
+#line 388 "parse-gram.y"
     { (yyval.assoc) = non_assoc; }
     break;
 
-  case 59:
+  case 60:
 
 /* Line 1269 of yacc.c  */
-#line 389 "parse-gram.y"
+#line 392 "parse-gram.y"
     { current_type = NULL; }
     break;
 
-  case 60:
+  case 61:
 
 /* Line 1269 of yacc.c  */
-#line 390 "parse-gram.y"
+#line 393 "parse-gram.y"
     { current_type = (yyvsp[(1) - (1)].uniqstr); tag_seen = true; }
     break;
 
-  case 61:
+  case 62:
 
 /* Line 1269 of yacc.c  */
-#line 396 "parse-gram.y"
+#line 399 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
-  case 62:
+  case 63:
 
 /* Line 1269 of yacc.c  */
-#line 398 "parse-gram.y"
+#line 401 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), symbol_list_sym_new ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]))); }
     break;
 
-  case 63:
+  case 64:
 
 /* Line 1269 of yacc.c  */
-#line 402 "parse-gram.y"
+#line 405 "parse-gram.y"
     { (yyval.list) = (yyvsp[(1) - (1)].list); }
     break;
 
-  case 64:
+  case 65:
 
 /* Line 1269 of yacc.c  */
-#line 403 "parse-gram.y"
+#line 406 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), (yyvsp[(2) - (2)].list)); }
     break;
 
-  case 65:
+  case 66:
 
 /* Line 1269 of yacc.c  */
-#line 407 "parse-gram.y"
+#line 410 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
-  case 66:
+  case 67:
 
 /* Line 1269 of yacc.c  */
-#line 408 "parse-gram.y"
+#line 411 "parse-gram.y"
     { (yyval.list) = symbol_list_type_new ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
-  case 67:
+  case 68:
 
 /* Line 1269 of yacc.c  */
-#line 409 "parse-gram.y"
+#line 412 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagged_new ((yylsp[(1) - (1)])); }
     break;
 
-  case 68:
+  case 69:
 
 /* Line 1269 of yacc.c  */
-#line 410 "parse-gram.y"
+#line 413 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagless_new ((yylsp[(1) - (1)])); }
     break;
 
-  case 69:
+  case 70:
 
 /* Line 1269 of yacc.c  */
-#line 416 "parse-gram.y"
+#line 419 "parse-gram.y"
     {
        current_type = (yyvsp[(1) - (1)].uniqstr);
        tag_seen = true;
      }
     break;
 
-  case 70:
+  case 71:
 
 /* Line 1269 of yacc.c  */
-#line 421 "parse-gram.y"
+#line 424 "parse-gram.y"
     {
        symbol_class_set ((yyvsp[(1) - (1)].symbol), current_class, (yylsp[(1) - (1)]), true);
        symbol_type_set ((yyvsp[(1) - (1)].symbol), current_type, (yylsp[(1) - (1)]));
      }
     break;
 
-  case 71:
+  case 72:
 
 /* Line 1269 of yacc.c  */
-#line 426 "parse-gram.y"
+#line 429 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
       symbol_type_set ((yyvsp[(1) - (2)].symbol), current_type, (yylsp[(1) - (2)]));
@@ -2410,10 +2427,10 @@ yyreduce:
     }
     break;
 
-  case 72:
+  case 73:
 
 /* Line 1269 of yacc.c  */
-#line 432 "parse-gram.y"
+#line 435 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
       symbol_type_set ((yyvsp[(1) - (2)].symbol), current_type, (yylsp[(1) - (2)]));
@@ -2421,10 +2438,10 @@ yyreduce:
     }
     break;
 
-  case 73:
+  case 74:
 
 /* Line 1269 of yacc.c  */
-#line 438 "parse-gram.y"
+#line 441 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (3)].symbol), current_class, (yylsp[(1) - (3)]), true);
       symbol_type_set ((yyvsp[(1) - (3)].symbol), current_type, (yylsp[(1) - (3)]));
@@ -2433,109 +2450,109 @@ yyreduce:
     }
     break;
 
-  case 80:
+  case 81:
 
 /* Line 1269 of yacc.c  */
-#line 468 "parse-gram.y"
+#line 471 "parse-gram.y"
     {
       yyerrok;
     }
     break;
 
-  case 81:
+  case 82:
 
 /* Line 1269 of yacc.c  */
-#line 474 "parse-gram.y"
+#line 477 "parse-gram.y"
     { current_lhs = (yyvsp[(1) - (1)].symbol); current_lhs_location = (yylsp[(1) - (1)]); }
     break;
 
-  case 83:
+  case 84:
 
 /* Line 1269 of yacc.c  */
-#line 478 "parse-gram.y"
+#line 481 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(1) - (1)])); }
     break;
 
-  case 84:
+  case 85:
 
 /* Line 1269 of yacc.c  */
-#line 479 "parse-gram.y"
+#line 482 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(3) - (3)])); }
     break;
 
-  case 86:
+  case 87:
 
 /* Line 1269 of yacc.c  */
-#line 485 "parse-gram.y"
+#line 488 "parse-gram.y"
     { grammar_current_rule_begin (current_lhs, current_lhs_location); }
     break;
 
-  case 87:
+  case 88:
 
 /* Line 1269 of yacc.c  */
-#line 487 "parse-gram.y"
+#line 490 "parse-gram.y"
     { grammar_current_rule_symbol_append ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)])); }
     break;
 
-  case 88:
+  case 89:
 
 /* Line 1269 of yacc.c  */
-#line 489 "parse-gram.y"
+#line 492 "parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
     break;
 
-  case 89:
+  case 90:
 
 /* Line 1269 of yacc.c  */
-#line 491 "parse-gram.y"
+#line 494 "parse-gram.y"
     { grammar_current_rule_prec_set ((yyvsp[(3) - (3)].symbol), (yylsp[(3) - (3)])); }
     break;
 
-  case 90:
+  case 91:
 
 /* Line 1269 of yacc.c  */
-#line 493 "parse-gram.y"
+#line 496 "parse-gram.y"
     { grammar_current_rule_dprec_set ((yyvsp[(3) - (3)].integer), (yylsp[(3) - (3)])); }
     break;
 
-  case 91:
+  case 92:
 
 /* Line 1269 of yacc.c  */
-#line 495 "parse-gram.y"
+#line 498 "parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[(3) - (3)].uniqstr), (yylsp[(3) - (3)])); }
     break;
 
-  case 94:
+  case 95:
 
 /* Line 1269 of yacc.c  */
-#line 511 "parse-gram.y"
+#line 514 "parse-gram.y"
     {
       static char one[] = "1";
       (yyval.chars) = one;
     }
     break;
 
-  case 96:
+  case 97:
 
 /* Line 1269 of yacc.c  */
-#line 521 "parse-gram.y"
+#line 524 "parse-gram.y"
     {
       (yyvsp[(1) - (1)].code)[strlen ((yyvsp[(1) - (1)].code)) - 1] = '\n';
       (yyval.chars) = translate_code ((yyvsp[(1) - (1)].code) + 1, (yylsp[(1) - (1)]));
     }
     break;
 
-  case 97:
+  case 98:
 
 /* Line 1269 of yacc.c  */
-#line 537 "parse-gram.y"
+#line 540 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
-  case 98:
+  case 99:
 
 /* Line 1269 of yacc.c  */
-#line 539 "parse-gram.y"
+#line 542 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[(1) - (1)].character)), (yylsp[(1) - (1)]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[(1) - (1)]), false);
@@ -2543,27 +2560,27 @@ yyreduce:
     }
     break;
 
-  case 99:
+  case 100:
 
 /* Line 1269 of yacc.c  */
-#line 547 "parse-gram.y"
+#line 550 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
-  case 102:
+  case 103:
 
 /* Line 1269 of yacc.c  */
-#line 559 "parse-gram.y"
+#line 562 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[(1) - (1)].chars)), (yylsp[(1) - (1)]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[(1) - (1)]), false);
     }
     break;
 
-  case 104:
+  case 105:
 
 /* Line 1269 of yacc.c  */
-#line 568 "parse-gram.y"
+#line 571 "parse-gram.y"
     {
       muscle_code_grow ("epilogue", translate_code ((yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])), (yylsp[(2) - (2)]));
       gram_scanner_last_string_free ();
@@ -2573,7 +2590,7 @@ yyreduce:
 
 
 /* Line 1269 of yacc.c  */
-#line 2577 "parse-gram.c"
+#line 2594 "parse-gram.c"
       default: break;
     }
   YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);
@@ -2792,7 +2809,7 @@ yyreturn:
 
 
 /* Line 1486 of yacc.c  */
-#line 574 "parse-gram.y"
+#line 577 "parse-gram.y"
 
 
 
