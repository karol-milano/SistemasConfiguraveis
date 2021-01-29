@@ -74,7 +74,7 @@
 /* Copy the first part of user declarations.  */
 
 /* Line 164 of yacc.c  */
-#line 1 "../../src/parse-gram.y"
+#line 1 "parse-gram.y"
 /* Bison Grammar Parser                             -*- C -*-
 
    Copyright (C) 2002, 2003, 2004, 2005, 2006 Free Software Foundation, Inc.
@@ -153,7 +153,7 @@ static int current_prec = 0;
 
 
 /* Line 164 of yacc.c  */
-#line 157 "../../src/parse-gram.c"
+#line 157 "parse-gram.c"
 
 /* Enabling traces.  */
 #ifndef YYDEBUG
@@ -196,46 +196,47 @@ static int current_prec = 0;
      PERCENT_DPREC = 270,
      PERCENT_MERGE = 271,
      PERCENT_CODE = 272,
-     PERCENT_DEBUG = 273,
-     PERCENT_DEFAULT_PREC = 274,
-     PERCENT_DEFINE = 275,
-     PERCENT_DEFINES = 276,
-     PERCENT_ERROR_VERBOSE = 277,
-     PERCENT_EXPECT = 278,
-     PERCENT_EXPECT_RR = 279,
-     PERCENT_FILE_PREFIX = 280,
-     PERCENT_GLR_PARSER = 281,
-     PERCENT_INITIAL_ACTION = 282,
-     PERCENT_LEX_PARAM = 283,
-     PERCENT_LOCATIONS = 284,
-     PERCENT_NAME_PREFIX = 285,
-     PERCENT_NO_DEFAULT_PREC = 286,
-     PERCENT_NO_LINES = 287,
-     PERCENT_NONDETERMINISTIC_PARSER = 288,
-     PERCENT_OUTPUT = 289,
-     PERCENT_PARSE_PARAM = 290,
-     PERCENT_PROVIDES = 291,
-     PERCENT_PURE_PARSER = 292,
-     PERCENT_PUSH_PARSER = 293,
-     PERCENT_REQUIRE = 294,
-     PERCENT_REQUIRES = 295,
-     PERCENT_SKELETON = 296,
-     PERCENT_START = 297,
-     PERCENT_TOKEN_TABLE = 298,
-     PERCENT_VERBOSE = 299,
-     PERCENT_YACC = 300,
-     BRACED_CODE = 301,
-     CHAR = 302,
-     EPILOGUE = 303,
-     EQUAL = 304,
-     ID = 305,
-     ID_COLON = 306,
-     PERCENT_PERCENT = 307,
-     PIPE = 308,
-     PROLOGUE = 309,
-     SEMICOLON = 310,
-     TYPE = 311,
-     PERCENT_UNION = 312
+     PERCENT_CODE_TOP = 273,
+     PERCENT_DEBUG = 274,
+     PERCENT_DEFAULT_PREC = 275,
+     PERCENT_DEFINE = 276,
+     PERCENT_DEFINES = 277,
+     PERCENT_ERROR_VERBOSE = 278,
+     PERCENT_EXPECT = 279,
+     PERCENT_EXPECT_RR = 280,
+     PERCENT_FILE_PREFIX = 281,
+     PERCENT_GLR_PARSER = 282,
+     PERCENT_INITIAL_ACTION = 283,
+     PERCENT_LEX_PARAM = 284,
+     PERCENT_LOCATIONS = 285,
+     PERCENT_NAME_PREFIX = 286,
+     PERCENT_NO_DEFAULT_PREC = 287,
+     PERCENT_NO_LINES = 288,
+     PERCENT_NONDETERMINISTIC_PARSER = 289,
+     PERCENT_OUTPUT = 290,
+     PERCENT_PARSE_PARAM = 291,
+     PERCENT_PROVIDES = 292,
+     PERCENT_PURE_PARSER = 293,
+     PERCENT_PUSH_PARSER = 294,
+     PERCENT_REQUIRE = 295,
+     PERCENT_REQUIRES = 296,
+     PERCENT_SKELETON = 297,
+     PERCENT_START = 298,
+     PERCENT_TOKEN_TABLE = 299,
+     PERCENT_VERBOSE = 300,
+     PERCENT_YACC = 301,
+     BRACED_CODE = 302,
+     CHAR = 303,
+     EPILOGUE = 304,
+     EQUAL = 305,
+     ID = 306,
+     ID_COLON = 307,
+     PERCENT_PERCENT = 308,
+     PIPE = 309,
+     PROLOGUE = 310,
+     SEMICOLON = 311,
+     TYPE = 312,
+     PERCENT_UNION = 313
    };
 #endif
 /* Tokens.  */
@@ -255,46 +256,47 @@ static int current_prec = 0;
 #define PERCENT_DPREC 270
 #define PERCENT_MERGE 271
 #define PERCENT_CODE 272
-#define PERCENT_DEBUG 273
-#define PERCENT_DEFAULT_PREC 274
-#define PERCENT_DEFINE 275
-#define PERCENT_DEFINES 276
-#define PERCENT_ERROR_VERBOSE 277
-#define PERCENT_EXPECT 278
-#define PERCENT_EXPECT_RR 279
-#define PERCENT_FILE_PREFIX 280
-#define PERCENT_GLR_PARSER 281
-#define PERCENT_INITIAL_ACTION 282
-#define PERCENT_LEX_PARAM 283
-#define PERCENT_LOCATIONS 284
-#define PERCENT_NAME_PREFIX 285
-#define PERCENT_NO_DEFAULT_PREC 286
-#define PERCENT_NO_LINES 287
-#define PERCENT_NONDETERMINISTIC_PARSER 288
-#define PERCENT_OUTPUT 289
-#define PERCENT_PARSE_PARAM 290
-#define PERCENT_PROVIDES 291
-#define PERCENT_PURE_PARSER 292
-#define PERCENT_PUSH_PARSER 293
-#define PERCENT_REQUIRE 294
-#define PERCENT_REQUIRES 295
-#define PERCENT_SKELETON 296
-#define PERCENT_START 297
-#define PERCENT_TOKEN_TABLE 298
-#define PERCENT_VERBOSE 299
-#define PERCENT_YACC 300
-#define BRACED_CODE 301
-#define CHAR 302
-#define EPILOGUE 303
-#define EQUAL 304
-#define ID 305
-#define ID_COLON 306
-#define PERCENT_PERCENT 307
-#define PIPE 308
-#define PROLOGUE 309
-#define SEMICOLON 310
-#define TYPE 311
-#define PERCENT_UNION 312
+#define PERCENT_CODE_TOP 273
+#define PERCENT_DEBUG 274
+#define PERCENT_DEFAULT_PREC 275
+#define PERCENT_DEFINE 276
+#define PERCENT_DEFINES 277
+#define PERCENT_ERROR_VERBOSE 278
+#define PERCENT_EXPECT 279
+#define PERCENT_EXPECT_RR 280
+#define PERCENT_FILE_PREFIX 281
+#define PERCENT_GLR_PARSER 282
+#define PERCENT_INITIAL_ACTION 283
+#define PERCENT_LEX_PARAM 284
+#define PERCENT_LOCATIONS 285
+#define PERCENT_NAME_PREFIX 286
+#define PERCENT_NO_DEFAULT_PREC 287
+#define PERCENT_NO_LINES 288
+#define PERCENT_NONDETERMINISTIC_PARSER 289
+#define PERCENT_OUTPUT 290
+#define PERCENT_PARSE_PARAM 291
+#define PERCENT_PROVIDES 292
+#define PERCENT_PURE_PARSER 293
+#define PERCENT_PUSH_PARSER 294
+#define PERCENT_REQUIRE 295
+#define PERCENT_REQUIRES 296
+#define PERCENT_SKELETON 297
+#define PERCENT_START 298
+#define PERCENT_TOKEN_TABLE 299
+#define PERCENT_VERBOSE 300
+#define PERCENT_YACC 301
+#define BRACED_CODE 302
+#define CHAR 303
+#define EPILOGUE 304
+#define EQUAL 305
+#define ID 306
+#define ID_COLON 307
+#define PERCENT_PERCENT 308
+#define PIPE 309
+#define PROLOGUE 310
+#define SEMICOLON 311
+#define TYPE 312
+#define PERCENT_UNION 313
 
 
 
@@ -303,7 +305,7 @@ static int current_prec = 0;
 typedef union YYSTYPE
 {
 /* Line 198 of yacc.c  */
-#line 98 "../../src/parse-gram.y"
+#line 98 "parse-gram.y"
 
   symbol *symbol;
   symbol_list *list;
@@ -315,7 +317,7 @@ typedef union YYSTYPE
 }
 
 /* Line 198 of yacc.c  */
-#line 319 "../../src/parse-gram.c"
+#line 321 "parse-gram.c"
 	YYSTYPE;
 # define YYSTYPE_IS_TRIVIAL 1
 # define yystype YYSTYPE /* obsolescent; will be withdrawn */
@@ -340,7 +342,7 @@ typedef struct YYLTYPE
 
 
 /* Line 221 of yacc.c  */
-#line 344 "../../src/parse-gram.c"
+#line 346 "parse-gram.c"
 
 #ifdef short
 # undef short
@@ -557,20 +559,20 @@ union yyalloc
 /* YYFINAL -- State number of the termination state.  */
 #define YYFINAL  3
 /* YYLAST -- Last index in YYTABLE.  */
-#define YYLAST   184
+#define YYLAST   187
 
 /* YYNTOKENS -- Number of terminals.  */
-#define YYNTOKENS  58
+#define YYNTOKENS  59
 /* YYNNTS -- Number of nonterminals.  */
 #define YYNNTS  31
 /* YYNRULES -- Number of rules.  */
-#define YYNRULES  97
+#define YYNRULES  98
 /* YYNRULES -- Number of states.  */
-#define YYNSTATES  135
+#define YYNSTATES  137
 
 /* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
 #define YYUNDEFTOK  2
-#define YYMAXUTOK   312
+#define YYMAXUTOK   313
 
 #define YYTRANSLATE(YYX)						\
   ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)
@@ -609,7 +611,7 @@ static const yytype_uint8 yytranslate[] =
       25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
       35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
       45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
-      55,    56,    57
+      55,    56,    57,    58
 };
 
 #if YYDEBUG
@@ -617,61 +619,61 @@ static const yytype_uint8 yytranslate[] =
    YYRHS.  */
 static const yytype_uint8 yyprhs[] =
 {
-       0,     0,     3,     8,     9,    12,    14,    16,    19,    21,
-      25,    27,    29,    32,    35,    39,    41,    44,    47,    49,
-      53,    55,    57,    61,    64,    67,    69,    71,    74,    77,
-      80,    82,    84,    86,    88,    90,    92,    95,    99,   103,
-     105,   107,   108,   110,   114,   115,   119,   120,   124,   128,
-     132,   134,   136,   138,   139,   141,   143,   146,   148,   151,
-     153,   155,   157,   159,   161,   164,   167,   171,   173,   176,
-     178,   181,   183,   186,   189,   190,   194,   196,   200,   203,
-     204,   207,   210,   214,   218,   222,   224,   226,   227,   229,
-     231,   233,   235,   237,   239,   241,   243,   244
+       0,     0,     3,     8,     9,    12,    14,    16,    18,    22,
+      24,    26,    29,    32,    36,    38,    41,    44,    46,    50,
+      52,    54,    58,    61,    63,    65,    68,    71,    73,    75,
+      77,    79,    81,    83,    86,    90,    94,    96,    98,   101,
+     104,   107,   110,   111,   113,   117,   118,   122,   123,   127,
+     131,   135,   137,   139,   141,   142,   144,   146,   149,   151,
+     154,   156,   158,   160,   162,   164,   167,   170,   174,   176,
+     179,   181,   184,   186,   189,   192,   193,   197,   199,   203,
+     206,   207,   210,   213,   217,   221,   225,   227,   229,   230,
+     232,   234,   236,   238,   240,   242,   244,   246,   247
 };
 
 /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
 static const yytype_int8 yyrhs[] =
 {
-      59,     0,    -1,    60,    52,    75,    88,    -1,    -1,    60,
-      61,    -1,    62,    -1,    54,    -1,    17,    83,    -1,    18,
-      -1,    20,     3,    82,    -1,    21,    -1,    22,    -1,    23,
-       4,    -1,    24,     4,    -1,    25,    49,     3,    -1,    26,
-      -1,    27,    46,    -1,    28,    46,    -1,    29,    -1,    30,
-      49,     3,    -1,    32,    -1,    33,    -1,    34,    49,     3,
-      -1,    35,    46,    -1,    36,    83,    -1,    37,    -1,    38,
-      -1,    39,     3,    -1,    40,    83,    -1,    41,     3,    -1,
-      43,    -1,    44,    -1,    45,    -1,    55,    -1,    67,    -1,
-      64,    -1,    42,    86,    -1,     8,    46,    71,    -1,     9,
-      46,    71,    -1,    19,    -1,    31,    -1,    -1,    50,    -1,
-      57,    63,    46,    -1,    -1,     6,    65,    74,    -1,    -1,
-       5,    66,    74,    -1,     7,    56,    70,    -1,    68,    69,
-      70,    -1,    11,    -1,    12,    -1,    13,    -1,    -1,    56,
-      -1,    86,    -1,    70,    86,    -1,    72,    -1,    71,    72,
-      -1,    86,    -1,    56,    -1,    10,    -1,    56,    -1,    84,
-      -1,    84,     4,    -1,    84,    87,    -1,    84,     4,    87,
-      -1,    73,    -1,    74,    73,    -1,    76,    -1,    75,    76,
-      -1,    77,    -1,    62,    55,    -1,     1,    55,    -1,    -1,
-      85,    78,    79,    -1,    80,    -1,    79,    53,    80,    -1,
-      79,    55,    -1,    -1,    80,    86,    -1,    80,    46,    -1,
-      80,    14,    86,    -1,    80,    15,     4,    -1,    80,    16,
-      56,    -1,     3,    -1,    83,    -1,    -1,    81,    -1,    46,
-      -1,    50,    -1,    47,    -1,    51,    -1,    84,    -1,    87,
-      -1,     3,    -1,    -1,    52,    48,    -1
+      60,     0,    -1,    61,    53,    76,    89,    -1,    -1,    61,
+      62,    -1,    63,    -1,    55,    -1,    19,    -1,    21,     3,
+      83,    -1,    22,    -1,    23,    -1,    24,     4,    -1,    25,
+       4,    -1,    26,    50,     3,    -1,    27,    -1,    28,    47,
+      -1,    29,    47,    -1,    30,    -1,    31,    50,     3,    -1,
+      33,    -1,    34,    -1,    35,    50,     3,    -1,    36,    47,
+      -1,    38,    -1,    39,    -1,    40,     3,    -1,    42,     3,
+      -1,    44,    -1,    45,    -1,    46,    -1,    56,    -1,    68,
+      -1,    65,    -1,    43,    87,    -1,     8,    47,    72,    -1,
+       9,    47,    72,    -1,    20,    -1,    32,    -1,    17,    84,
+      -1,    18,    84,    -1,    37,    84,    -1,    41,    84,    -1,
+      -1,    51,    -1,    58,    64,    47,    -1,    -1,     6,    66,
+      75,    -1,    -1,     5,    67,    75,    -1,     7,    57,    71,
+      -1,    69,    70,    71,    -1,    11,    -1,    12,    -1,    13,
+      -1,    -1,    57,    -1,    87,    -1,    71,    87,    -1,    73,
+      -1,    72,    73,    -1,    87,    -1,    57,    -1,    10,    -1,
+      57,    -1,    85,    -1,    85,     4,    -1,    85,    88,    -1,
+      85,     4,    88,    -1,    74,    -1,    75,    74,    -1,    77,
+      -1,    76,    77,    -1,    78,    -1,    63,    56,    -1,     1,
+      56,    -1,    -1,    86,    79,    80,    -1,    81,    -1,    80,
+      54,    81,    -1,    80,    56,    -1,    -1,    81,    87,    -1,
+      81,    47,    -1,    81,    14,    87,    -1,    81,    15,     4,
+      -1,    81,    16,    57,    -1,     3,    -1,    84,    -1,    -1,
+      82,    -1,    47,    -1,    51,    -1,    48,    -1,    52,    -1,
+      85,    -1,    88,    -1,     3,    -1,    -1,    53,    49,    -1
 };
 
 /* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
 static const yytype_uint16 yyrline[] =
 {
-       0,   208,   208,   216,   218,   222,   223,   224,   225,   226,
-     227,   228,   229,   230,   231,   232,   237,   241,   242,   243,
-     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
-     254,   255,   256,   257,   261,   262,   263,   267,   275,   283,
-     287,   301,   302,   306,   334,   334,   339,   339,   344,   355,
-     370,   371,   372,   376,   377,   382,   384,   389,   390,   394,
-     395,   396,   401,   406,   411,   417,   423,   434,   435,   444,
-     445,   451,   452,   453,   460,   460,   464,   465,   466,   471,
-     472,   474,   476,   478,   480,   490,   491,   497,   501,   506,
-     522,   524,   533,   538,   539,   544,   551,   553
+       0,   209,   209,   217,   219,   223,   224,   225,   226,   227,
+     228,   229,   230,   231,   232,   237,   241,   242,   243,   244,
+     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
+     255,   259,   260,   261,   265,   273,   281,   285,   289,   290,
+     291,   292,   303,   304,   308,   336,   336,   341,   341,   346,
+     357,   372,   373,   374,   378,   379,   384,   386,   391,   392,
+     396,   397,   398,   403,   408,   413,   419,   425,   436,   437,
+     446,   447,   453,   454,   455,   462,   462,   466,   467,   468,
+     473,   474,   476,   478,   480,   482,   492,   493,   499,   503,
+     508,   524,   526,   535,   540,   541,   546,   553,   555
 };
 #endif
 
@@ -684,8 +686,8 @@ static const char *const yytname[] =
   "\"%token\"", "\"%nterm\"", "\"%type\"", "\"%destructor\"",
   "\"%printer\"", "\"%symbol-default\"", "\"%left\"", "\"%right\"",
   "\"%nonassoc\"", "\"%prec\"", "\"%dprec\"", "\"%merge\"", "\"%code\"",
-  "\"%debug\"", "\"%default-prec\"", "\"%define\"", "\"%defines\"",
-  "\"%error-verbose\"", "\"%expect\"", "\"%expect-rr\"",
+  "\"%code-top\"", "\"%debug\"", "\"%default-prec\"", "\"%define\"",
+  "\"%defines\"", "\"%error-verbose\"", "\"%expect\"", "\"%expect-rr\"",
   "\"%file-prefix\"", "\"%glr-parser\"", "\"%initial-action\"",
   "\"%lex-param\"", "\"%locations\"", "\"%name-prefix\"",
   "\"%no-default-prec\"", "\"%no-lines\"", "\"%nondeterministic-parser\"",
@@ -715,38 +717,38 @@ static const yytype_uint16 yytoknum[] =
      275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
      285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
      295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
-     305,   306,   307,   308,   309,   310,   311,   312
+     305,   306,   307,   308,   309,   310,   311,   312,   313
 };
 # endif
 
 /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
 static const yytype_uint8 yyr1[] =
 {
-       0,    58,    59,    60,    60,    61,    61,    61,    61,    61,
-      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
-      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
-      61,    61,    61,    61,    62,    62,    62,    62,    62,    62,
-      62,    63,    63,    62,    65,    64,    66,    64,    64,    67,
-      68,    68,    68,    69,    69,    70,    70,    71,    71,    72,
-      72,    72,    73,    73,    73,    73,    73,    74,    74,    75,
-      75,    76,    76,    76,    78,    77,    79,    79,    79,    80,
-      80,    80,    80,    80,    80,    81,    81,    82,    82,    83,
-      84,    84,    85,    86,    86,    87,    88,    88
+       0,    59,    60,    61,    61,    62,    62,    62,    62,    62,
+      62,    62,    62,    62,    62,    62,    62,    62,    62,    62,
+      62,    62,    62,    62,    62,    62,    62,    62,    62,    62,
+      62,    63,    63,    63,    63,    63,    63,    63,    63,    63,
+      63,    63,    64,    64,    63,    66,    65,    67,    65,    65,
+      68,    69,    69,    69,    70,    70,    71,    71,    72,    72,
+      73,    73,    73,    74,    74,    74,    74,    74,    75,    75,
+      76,    76,    77,    77,    77,    79,    78,    80,    80,    80,
+      81,    81,    81,    81,    81,    81,    82,    82,    83,    83,
+      84,    85,    85,    86,    87,    87,    88,    89,    89
 };
 
 /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
 static const yytype_uint8 yyr2[] =
 {
-       0,     2,     4,     0,     2,     1,     1,     2,     1,     3,
-       1,     1,     2,     2,     3,     1,     2,     2,     1,     3,
-       1,     1,     3,     2,     2,     1,     1,     2,     2,     2,
-       1,     1,     1,     1,     1,     1,     2,     3,     3,     1,
-       1,     0,     1,     3,     0,     3,     0,     3,     3,     3,
-       1,     1,     1,     0,     1,     1,     2,     1,     2,     1,
-       1,     1,     1,     1,     2,     2,     3,     1,     2,     1,
-       2,     1,     2,     2,     0,     3,     1,     3,     2,     0,
-       2,     2,     3,     3,     3,     1,     1,     0,     1,     1,
-       1,     1,     1,     1,     1,     1,     0,     2
+       0,     2,     4,     0,     2,     1,     1,     1,     3,     1,
+       1,     2,     2,     3,     1,     2,     2,     1,     3,     1,
+       1,     3,     2,     1,     1,     2,     2,     1,     1,     1,
+       1,     1,     1,     2,     3,     3,     1,     1,     2,     2,
+       2,     2,     0,     1,     3,     0,     3,     0,     3,     3,
+       3,     1,     1,     1,     0,     1,     1,     2,     1,     2,
+       1,     1,     1,     1,     1,     2,     2,     3,     1,     2,
+       1,     2,     1,     2,     2,     0,     3,     1,     3,     2,
+       0,     2,     2,     3,     3,     3,     1,     1,     0,     1,
+       1,     1,     1,     1,     1,     1,     1,     0,     2
 };
 
 /* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
@@ -754,130 +756,130 @@ static const yytype_uint8 yyr2[] =
    means the default is an error.  */
 static const yytype_uint8 yydefact[] =
 {
-       3,     0,     0,     1,    46,    44,     0,     0,     0,    50,
-      51,    52,     0,     8,    39,     0,    10,    11,     0,     0,
-       0,    15,     0,     0,    18,     0,    40,    20,    21,     0,
-       0,     0,    25,    26,     0,     0,     0,     0,    30,    31,
-      32,     0,     6,    33,    41,     4,     5,    35,    34,    53,
-       0,     0,     0,     0,     0,    89,     7,    87,    12,    13,
-       0,    16,    17,     0,     0,    23,    24,    27,    28,    29,
-      95,    91,    90,    93,    36,    94,     0,    92,     0,     0,
-      69,    71,    74,    42,     0,    54,     0,    62,    67,    47,
-      63,    45,    48,    55,    61,    60,    37,    57,    59,    38,
-      85,    88,     9,    86,    14,    19,    22,    73,    72,     0,
-      70,     2,    79,    43,    49,    68,    64,    65,    56,    58,
-      97,    75,    76,    66,    79,    78,     0,     0,     0,    81,
-      80,    77,    82,    83,    84
+       3,     0,     0,     1,    47,    45,     0,     0,     0,    51,
+      52,    53,     0,     0,     7,    36,     0,     9,    10,     0,
+       0,     0,    14,     0,     0,    17,     0,    37,    19,    20,
+       0,     0,     0,    23,    24,     0,     0,     0,     0,    27,
+      28,    29,     0,     6,    30,    42,     4,     5,    32,    31,
+      54,     0,     0,     0,     0,     0,    90,    38,    39,    88,
+      11,    12,     0,    15,    16,     0,     0,    22,    40,    25,
+      41,    26,    96,    92,    91,    94,    33,    95,     0,    93,
+       0,     0,    70,    72,    75,    43,     0,    55,     0,    63,
+      68,    48,    64,    46,    49,    56,    62,    61,    34,    58,
+      60,    35,    86,    89,     8,    87,    13,    18,    21,    74,
+      73,     0,    71,     2,    80,    44,    50,    69,    65,    66,
+      57,    59,    98,    76,    77,    67,    80,    79,     0,     0,
+       0,    82,    81,    78,    83,    84,    85
 };
 
 /* YYDEFGOTO[NTERM-NUM].  */
 static const yytype_int8 yydefgoto[] =
 {
-      -1,     1,     2,    45,    78,    84,    47,    51,    50,    48,
-      49,    86,    92,    96,    97,    88,    89,    79,    80,    81,
-     112,   121,   122,   101,   102,    56,    73,    82,    98,    75,
-     111
+      -1,     1,     2,    46,    80,    86,    48,    52,    51,    49,
+      50,    88,    94,    98,    99,    90,    91,    81,    82,    83,
+     114,   123,   124,   103,   104,    57,    75,    84,   100,    77,
+     113
 };
 
 /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
    STATE-NUM.  */
-#define YYPACT_NINF -75
+#define YYPACT_NINF -82
 static const yytype_int16 yypact[] =
 {
-     -75,     5,    90,   -75,   -75,   -75,   -52,   -25,   -19,   -75,
-     -75,   -75,   -13,   -75,   -75,    42,   -75,   -75,    47,    52,
-      15,   -75,    19,    21,   -75,    20,   -75,   -75,   -75,    22,
-      24,   -13,   -75,   -75,    69,   -13,    70,     0,   -75,   -75,
-     -75,    17,   -75,   -75,    26,   -75,   -75,   -75,   -75,    27,
-      10,    10,     0,    28,    28,   -75,   -75,     8,   -75,   -75,
-      77,   -75,   -75,    79,    83,   -75,   -75,   -75,   -75,   -75,
-     -75,   -75,   -75,   -75,   -75,   -75,    32,   -75,    33,     1,
-     -75,   -75,   -75,   -75,    44,   -75,     0,   -75,   -75,    10,
-      59,    10,     0,   -75,   -75,   -75,    28,   -75,   -75,    28,
-     -75,   -75,   -75,   -75,   -75,   -75,   -75,   -75,   -75,    43,
-     -75,   -75,   -75,   -75,     0,   -75,    89,   -75,   -75,   -75,
-     -75,   -36,   134,   -75,   -75,   -75,     0,    96,    37,   -75,
-     -75,   134,   -75,   -75,   -75
+     -82,     4,    91,   -82,   -82,   -82,   -52,   -31,   -24,   -82,
+     -82,   -82,    -8,    -8,   -82,   -82,    49,   -82,   -82,    53,
+      54,    12,   -82,    16,    26,   -82,    30,   -82,   -82,   -82,
+      32,    36,    -8,   -82,   -82,    81,    -8,    82,     0,   -82,
+     -82,   -82,    23,   -82,   -82,    37,   -82,   -82,   -82,   -82,
+      34,    19,    19,     0,    17,    17,   -82,   -82,   -82,    14,
+     -82,   -82,    84,   -82,   -82,    86,    90,   -82,   -82,   -82,
+     -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,    38,   -82,
+      45,     1,   -82,   -82,   -82,   -82,    58,   -82,     0,   -82,
+     -82,    19,    43,    19,     0,   -82,   -82,   -82,    17,   -82,
+     -82,    17,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,
+     -82,    57,   -82,   -82,   -82,   -82,     0,   -82,   104,   -82,
+     -82,   -82,   -82,    15,   136,   -82,   -82,   -82,     0,    88,
+      85,   -82,   -82,   136,   -82,   -82,   -82
 };
 
 /* YYPGOTO[NTERM-NUM].  */
-static const yytype_int8 yypgoto[] =
+static const yytype_int16 yypgoto[] =
 {
-     -75,   -75,   -75,   -75,   102,   -75,   -75,   -75,   -75,   -75,
-     -75,   -75,    50,    51,   -62,   -45,    55,   -75,    60,   -75,
-     -75,   -75,    14,   -75,   -75,     4,   -10,   -75,   -37,   -74,
-     -75
+     -82,   -82,   -82,   -82,   141,   -82,   -82,   -82,   -82,   -82,
+     -82,   -82,    50,    93,   -76,   -14,   101,   -82,    64,   -82,
+     -82,   -82,    28,   -82,   -82,    13,    89,   -82,   -38,   -81,
+     -82
 };
 
 /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
    positive, shift that token.  If negative, reduce the rule which
    number is the opposite.  If zero, do what YYDEFACT says.
    If YYTABLE_NINF, syntax error.  */
-#define YYTABLE_NINF -97
+#define YYTABLE_NINF -98
 static const yytype_int16 yytable[] =
 {
-      74,   -96,    76,    70,    52,     3,     4,     5,     6,     7,
-       8,   100,     9,    10,    11,    93,   117,   124,    76,   125,
-      14,    53,     4,     5,     6,     7,     8,    54,     9,    10,
-      11,    70,    26,    55,   119,    66,    14,   119,    94,    68,
-      90,    90,   123,    37,   115,    57,   115,    71,    26,    93,
-      72,    58,    77,   109,    55,   118,    59,    71,    44,    37,
-      72,   103,    70,   116,    60,    61,    87,    62,    77,    63,
-      65,    64,    67,    69,    44,    71,    83,   118,    72,    90,
-     104,    90,   105,    85,    95,   130,   106,   107,   108,   132,
-     113,   120,    70,   134,   130,     4,     5,     6,     7,     8,
-     133,     9,    10,    11,    46,    99,    91,    12,    13,    14,
-      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
-      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
-      35,    36,    37,    38,    39,    40,   114,    70,   131,   110,
-       0,     0,    41,     0,    42,    43,     0,    44,   126,   127,
-     128,     0,     0,     0,     0,     0,     0,     0,     0,     0,
+      76,   -97,    78,    72,     3,    53,     4,     5,     6,     7,
+       8,   119,     9,    10,    11,    95,    54,   102,    12,    13,
+      72,    15,   121,    55,    78,   121,    58,    96,     4,     5,
+       6,     7,     8,    27,     9,    10,    11,   125,    32,    56,
+      12,    13,    36,    15,    38,    68,    72,   118,    73,    70,
+      95,    74,    59,    79,   111,    27,   120,    60,    61,    45,
+      32,    56,    62,    63,    36,    73,    38,    73,    74,   126,
+      74,   127,   105,    64,    97,    79,    89,   117,   120,   117,
+      65,    45,    66,    67,    69,    71,   132,   106,    85,   107,
+     134,    87,   135,   108,   109,   132,     4,     5,     6,     7,
+       8,   110,     9,    10,    11,   115,   122,    72,    12,    13,
+      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
+      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
+      34,    35,    36,    37,    38,    39,    40,    41,   116,    72,
+      92,    92,   136,    47,    42,   112,    43,    44,   101,    45,
+     128,   129,   130,    93,   133,     0,     0,     0,     0,     0,
        0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
        0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
-     129,    71,     0,     0,    72
+      92,     0,    92,   131,    73,     0,     0,    74
 };
 
 static const yytype_int16 yycheck[] =
 {
-      37,     0,     1,     3,    56,     0,     5,     6,     7,     8,
-       9,     3,    11,    12,    13,    52,    90,    53,     1,    55,
-      19,    46,     5,     6,     7,     8,     9,    46,    11,    12,
-      13,     3,    31,    46,    96,    31,    19,    99,    10,    35,
-      50,    51,   116,    42,    89,     3,    91,    47,    31,    86,
-      50,     4,    51,    52,    46,    92,     4,    47,    57,    42,
-      50,    57,     3,     4,    49,    46,    56,    46,    51,    49,
-      46,    49,     3,     3,    57,    47,    50,   114,    50,    89,
-       3,    91,     3,    56,    56,   122,     3,    55,    55,   126,
-      46,    48,     3,    56,   131,     5,     6,     7,     8,     9,
-       4,    11,    12,    13,     2,    54,    51,    17,    18,    19,
-      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
-      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
-      40,    41,    42,    43,    44,    45,    86,     3,   124,    79,
-      -1,    -1,    52,    -1,    54,    55,    -1,    57,    14,    15,
-      16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
+      38,     0,     1,     3,     0,    57,     5,     6,     7,     8,
+       9,    92,    11,    12,    13,    53,    47,     3,    17,    18,
+       3,    20,    98,    47,     1,   101,    13,    10,     5,     6,
+       7,     8,     9,    32,    11,    12,    13,   118,    37,    47,
+      17,    18,    41,    20,    43,    32,     3,     4,    48,    36,
+      88,    51,     3,    52,    53,    32,    94,     4,     4,    58,
+      37,    47,    50,    47,    41,    48,    43,    48,    51,    54,
+      51,    56,    59,    47,    57,    52,    57,    91,   116,    93,
+      50,    58,    50,    47,     3,     3,   124,     3,    51,     3,
+     128,    57,     4,     3,    56,   133,     5,     6,     7,     8,
+       9,    56,    11,    12,    13,    47,    49,     3,    17,    18,
+      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
+      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
+      39,    40,    41,    42,    43,    44,    45,    46,    88,     3,
+      51,    52,    57,     2,    53,    81,    55,    56,    55,    58,
+      14,    15,    16,    52,   126,    -1,    -1,    -1,    -1,    -1,
       -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
-      46,    47,    -1,    -1,    50
+      91,    -1,    93,    47,    48,    -1,    -1,    51
 };
 
 /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
    symbol of state STATE-NUM.  */
 static const yytype_uint8 yystos[] =
 {
-       0,    59,    60,     0,     5,     6,     7,     8,     9,    11,
+       0,    60,    61,     0,     5,     6,     7,     8,     9,    11,
       12,    13,    17,    18,    19,    20,    21,    22,    23,    24,
       25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
       35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
-      45,    52,    54,    55,    57,    61,    62,    64,    67,    68,
-      66,    65,    56,    46,    46,    46,    83,     3,     4,     4,
-      49,    46,    46,    49,    49,    46,    83,     3,    83,     3,
-       3,    47,    50,    84,    86,    87,     1,    51,    62,    75,
-      76,    77,    85,    50,    63,    56,    69,    56,    73,    74,
-      84,    74,    70,    86,    10,    56,    71,    72,    86,    71,
-       3,    81,    82,    83,     3,     3,     3,    55,    55,    52,
-      76,    88,    78,    46,    70,    73,     4,    87,    86,    72,
-      48,    79,    80,    87,    53,    55,    14,    15,    16,    46,
-      86,    80,    86,     4,    56
+      45,    46,    53,    55,    56,    58,    62,    63,    65,    68,
+      69,    67,    66,    57,    47,    47,    47,    84,    84,     3,
+       4,     4,    50,    47,    47,    50,    50,    47,    84,     3,
+      84,     3,     3,    48,    51,    85,    87,    88,     1,    52,
+      63,    76,    77,    78,    86,    51,    64,    57,    70,    57,
+      74,    75,    85,    75,    71,    87,    10,    57,    72,    73,
+      87,    72,     3,    82,    83,    84,     3,     3,     3,    56,
+      56,    53,    77,    89,    79,    47,    71,    74,     4,    88,
+      87,    73,    49,    80,    81,    88,    54,    56,    14,    15,
+      16,    47,    87,    81,    87,     4,    57
 };
 
 #define yyerrok		(yyerrstatus = 0)
@@ -1028,146 +1030,146 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
       case 3: /* "\"string\"" */
 
 /* Line 670 of yacc.c  */
-#line 186 "../../src/parse-gram.y"
+#line 187 "parse-gram.y"
 	{ fputs (quotearg_style (c_quoting_style, (yyvaluep->chars)), stderr); };
 
 /* Line 670 of yacc.c  */
-#line 1036 "../../src/parse-gram.c"
+#line 1038 "parse-gram.c"
 	break;
       case 4: /* "\"integer\"" */
 
 /* Line 670 of yacc.c  */
-#line 197 "../../src/parse-gram.y"
+#line 198 "parse-gram.y"
 	{ fprintf (stderr, "%d", (yyvaluep->integer)); };
 
 /* Line 670 of yacc.c  */
-#line 1045 "../../src/parse-gram.c"
+#line 1047 "parse-gram.c"
 	break;
-      case 46: /* "\"{...}\"" */
+      case 47: /* "\"{...}\"" */
 
 /* Line 670 of yacc.c  */
-#line 188 "../../src/parse-gram.y"
+#line 189 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
 /* Line 670 of yacc.c  */
-#line 1054 "../../src/parse-gram.c"
+#line 1056 "parse-gram.c"
 	break;
-      case 47: /* "\"char\"" */
+      case 48: /* "\"char\"" */
 
 /* Line 670 of yacc.c  */
-#line 181 "../../src/parse-gram.y"
+#line 182 "parse-gram.y"
 	{ fputs (char_name ((yyvaluep->character)), stderr); };
 
 /* Line 670 of yacc.c  */
-#line 1063 "../../src/parse-gram.c"
+#line 1065 "parse-gram.c"
 	break;
-      case 48: /* "\"epilogue\"" */
+      case 49: /* "\"epilogue\"" */
 
 /* Line 670 of yacc.c  */
-#line 188 "../../src/parse-gram.y"
+#line 189 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
 /* Line 670 of yacc.c  */
-#line 1072 "../../src/parse-gram.c"
+#line 1074 "parse-gram.c"
 	break;
-      case 50: /* "\"identifier\"" */
+      case 51: /* "\"identifier\"" */
 
 /* Line 670 of yacc.c  */
-#line 193 "../../src/parse-gram.y"
+#line 194 "parse-gram.y"
 	{ fputs ((yyvaluep->uniqstr), stderr); };
 
 /* Line 670 of yacc.c  */
-#line 1081 "../../src/parse-gram.c"
+#line 1083 "parse-gram.c"
 	break;
-      case 51: /* "\"identifier:\"" */
+      case 52: /* "\"identifier:\"" */
 
 /* Line 670 of yacc.c  */
-#line 194 "../../src/parse-gram.y"
+#line 195 "parse-gram.y"
 	{ fprintf (stderr, "%s:", (yyvaluep->uniqstr)); };
 
 /* Line 670 of yacc.c  */
-#line 1090 "../../src/parse-gram.c"
+#line 1092 "parse-gram.c"
 	break;
-      case 54: /* "\"%{...%}\"" */
+      case 55: /* "\"%{...%}\"" */
 
 /* Line 670 of yacc.c  */
-#line 188 "../../src/parse-gram.y"
+#line 189 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
 /* Line 670 of yacc.c  */
-#line 1099 "../../src/parse-gram.c"
+#line 1101 "parse-gram.c"
 	break;
-      case 56: /* "\"type\"" */
+      case 57: /* "\"type\"" */
 
 /* Line 670 of yacc.c  */
-#line 192 "../../src/parse-gram.y"
+#line 193 "parse-gram.y"
 	{ fprintf (stderr, "<%s>", (yyvaluep->uniqstr)); };
 
 /* Line 670 of yacc.c  */
-#line 1108 "../../src/parse-gram.c"
+#line 1110 "parse-gram.c"
 	break;
-      case 81: /* "content" */
+      case 82: /* "content" */
 
 /* Line 670 of yacc.c  */
-#line 188 "../../src/parse-gram.y"
+#line 189 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
 /* Line 670 of yacc.c  */
-#line 1117 "../../src/parse-gram.c"
+#line 1119 "parse-gram.c"
 	break;
-      case 82: /* "content.opt" */
+      case 83: /* "content.opt" */
 
 /* Line 670 of yacc.c  */
-#line 188 "../../src/parse-gram.y"
+#line 189 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
 /* Line 670 of yacc.c  */
-#line 1126 "../../src/parse-gram.c"
+#line 1128 "parse-gram.c"
 	break;
-      case 83: /* "braceless" */
+      case 84: /* "braceless" */
 
 /* Line 670 of yacc.c  */
-#line 188 "../../src/parse-gram.y"
+#line 189 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
 /* Line 670 of yacc.c  */
-#line 1135 "../../src/parse-gram.c"
+#line 1137 "parse-gram.c"
 	break;
-      case 84: /* "id" */
+      case 85: /* "id" */
 
 /* Line 670 of yacc.c  */
-#line 200 "../../src/parse-gram.y"
+#line 201 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
 /* Line 670 of yacc.c  */
-#line 1144 "../../src/parse-gram.c"
+#line 1146 "parse-gram.c"
 	break;
-      case 85: /* "id_colon" */
+      case 86: /* "id_colon" */
 
 /* Line 670 of yacc.c  */
-#line 201 "../../src/parse-gram.y"
+#line 202 "parse-gram.y"
 	{ fprintf (stderr, "%s:", (yyvaluep->symbol)->tag); };
 
 /* Line 670 of yacc.c  */
-#line 1153 "../../src/parse-gram.c"
+#line 1155 "parse-gram.c"
 	break;
-      case 86: /* "symbol" */
+      case 87: /* "symbol" */
 
 /* Line 670 of yacc.c  */
-#line 200 "../../src/parse-gram.y"
+#line 201 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
 /* Line 670 of yacc.c  */
-#line 1162 "../../src/parse-gram.c"
+#line 1164 "parse-gram.c"
 	break;
-      case 87: /* "string_as_id" */
+      case 88: /* "string_as_id" */
 
 /* Line 670 of yacc.c  */
-#line 200 "../../src/parse-gram.y"
+#line 201 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
 /* Line 670 of yacc.c  */
-#line 1171 "../../src/parse-gram.c"
+#line 1173 "parse-gram.c"
 	break;
       default:
 	break;
@@ -1682,7 +1684,7 @@ YYLTYPE yylloc;
   /* User initialization code.  */
   
 /* Line 1082 of yacc.c  */
-#line 89 "../../src/parse-gram.y"
+#line 89 "parse-gram.y"
 {
   /* Bison's grammar can initial empty locations, hence a default
      location is needed. */
@@ -1691,7 +1693,7 @@ YYLTYPE yylloc;
 }
 
 /* Line 1082 of yacc.c  */
-#line 1695 "../../src/parse-gram.c"
+#line 1697 "parse-gram.c"
   yylsp[0] = yylloc;
   goto yysetstate;
 
@@ -1877,210 +1879,189 @@ yyreduce:
         case 6:
 
 /* Line 1269 of yacc.c  */
-#line 223 "../../src/parse-gram.y"
+#line 224 "parse-gram.y"
     { prologue_augment (translate_code ((yyvsp[(1) - (1)].chars), (yylsp[(1) - (1)])), (yylsp[(1) - (1)]), union_seen); }
     break;
 
   case 7:
 
 /* Line 1269 of yacc.c  */
-#line 224 "../../src/parse-gram.y"
-    { prologue_augment ((yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)]), true); }
-    break;
-
-  case 8:
-
-/* Line 1269 of yacc.c  */
-#line 225 "../../src/parse-gram.y"
+#line 225 "parse-gram.y"
     { debug_flag = true; }
     break;
 
-  case 9:
+  case 8:
 
 /* Line 1269 of yacc.c  */
-#line 226 "../../src/parse-gram.y"
+#line 226 "parse-gram.y"
     { muscle_insert ((yyvsp[(2) - (3)].chars), (yyvsp[(3) - (3)].chars)); }
     break;
 
-  case 10:
+  case 9:
 
 /* Line 1269 of yacc.c  */
-#line 227 "../../src/parse-gram.y"
+#line 227 "parse-gram.y"
     { defines_flag = true; }
     break;
 
-  case 11:
+  case 10:
 
 /* Line 1269 of yacc.c  */
-#line 228 "../../src/parse-gram.y"
+#line 228 "parse-gram.y"
     { error_verbose = true; }
     break;
 
-  case 12:
+  case 11:
 
 /* Line 1269 of yacc.c  */
-#line 229 "../../src/parse-gram.y"
+#line 229 "parse-gram.y"
     { expected_sr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
-  case 13:
+  case 12:
 
 /* Line 1269 of yacc.c  */
-#line 230 "../../src/parse-gram.y"
+#line 230 "parse-gram.y"
     { expected_rr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
-  case 14:
+  case 13:
 
 /* Line 1269 of yacc.c  */
-#line 231 "../../src/parse-gram.y"
+#line 231 "parse-gram.y"
     { spec_file_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
-  case 15:
+  case 14:
 
 /* Line 1269 of yacc.c  */
-#line 233 "../../src/parse-gram.y"
+#line 233 "parse-gram.y"
     {
       nondeterministic_parser = true;
       glr_parser = true;
     }
     break;
 
-  case 16:
+  case 15:
 
 /* Line 1269 of yacc.c  */
-#line 238 "../../src/parse-gram.y"
+#line 238 "parse-gram.y"
     {
       muscle_code_grow ("initial_action", translate_symbol_action ((yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])), (yylsp[(2) - (2)]));
     }
     break;
 
-  case 17:
+  case 16:
 
 /* Line 1269 of yacc.c  */
-#line 241 "../../src/parse-gram.y"
+#line 241 "parse-gram.y"
     { add_param ("lex_param", (yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])); }
     break;
 
-  case 18:
+  case 17:
 
 /* Line 1269 of yacc.c  */
-#line 242 "../../src/parse-gram.y"
+#line 242 "parse-gram.y"
     { locations_flag = true; }
     break;
 
-  case 19:
+  case 18:
 
 /* Line 1269 of yacc.c  */
-#line 243 "../../src/parse-gram.y"
+#line 243 "parse-gram.y"
     { spec_name_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
-  case 20:
+  case 19:
 
 /* Line 1269 of yacc.c  */
-#line 244 "../../src/parse-gram.y"
+#line 244 "parse-gram.y"
     { no_lines_flag = true; }
     break;
 
-  case 21:
+  case 20:
 
 /* Line 1269 of yacc.c  */
-#line 245 "../../src/parse-gram.y"
+#line 245 "parse-gram.y"
     { nondeterministic_parser = true; }
     break;
 
-  case 22:
+  case 21:
 
 /* Line 1269 of yacc.c  */
-#line 246 "../../src/parse-gram.y"
+#line 246 "parse-gram.y"
     { spec_outfile = (yyvsp[(3) - (3)].chars); }
     break;
 
-  case 23:
+  case 22:
 
 /* Line 1269 of yacc.c  */
-#line 247 "../../src/parse-gram.y"
+#line 247 "parse-gram.y"
     { add_param ("parse_param", (yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])); }
     break;
 
-  case 24:
-
-/* Line 1269 of yacc.c  */
-#line 248 "../../src/parse-gram.y"
-    { muscle_code_grow ("provides", (yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])); }
-    break;
-
-  case 25:
+  case 23:
 
 /* Line 1269 of yacc.c  */
-#line 249 "../../src/parse-gram.y"
+#line 248 "parse-gram.y"
     { pure_parser = true; }
     break;
 
-  case 26:
+  case 24:
 
 /* Line 1269 of yacc.c  */
-#line 250 "../../src/parse-gram.y"
+#line 249 "parse-gram.y"
     { push_parser = true; }
     break;
 
-  case 27:
+  case 25:
 
 /* Line 1269 of yacc.c  */
-#line 251 "../../src/parse-gram.y"
+#line 250 "parse-gram.y"
     { version_check (&(yylsp[(2) - (2)]), (yyvsp[(2) - (2)].chars)); }
     break;
 
-  case 28:
-
-/* Line 1269 of yacc.c  */
-#line 252 "../../src/parse-gram.y"
-    { muscle_code_grow ("requires", (yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])); }
-    break;
-
-  case 29:
+  case 26:
 
 /* Line 1269 of yacc.c  */
-#line 253 "../../src/parse-gram.y"
+#line 251 "parse-gram.y"
     { skeleton = (yyvsp[(2) - (2)].chars); }
     break;
 
-  case 30:
+  case 27:
 
 /* Line 1269 of yacc.c  */
-#line 254 "../../src/parse-gram.y"
+#line 252 "parse-gram.y"
     { token_table_flag = true; }
     break;
 
-  case 31:
+  case 28:
 
 /* Line 1269 of yacc.c  */
-#line 255 "../../src/parse-gram.y"
+#line 253 "parse-gram.y"
     { report_flag = report_states; }
     break;
 
-  case 32:
+  case 29:
 
 /* Line 1269 of yacc.c  */
-#line 256 "../../src/parse-gram.y"
+#line 254 "parse-gram.y"
     { yacc_flag = true; }
     break;
 
-  case 36:
+  case 33:
 
 /* Line 1269 of yacc.c  */
-#line 264 "../../src/parse-gram.y"
+#line 262 "parse-gram.y"
     {
       grammar_start_symbol_set ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]));
     }
     break;
 
-  case 37:
+  case 34:
 
 /* Line 1269 of yacc.c  */
-#line 268 "../../src/parse-gram.y"
+#line 266 "parse-gram.y"
     {
       symbol_list *list;
       const char *action = translate_symbol_action ((yyvsp[(2) - (3)].chars), (yylsp[(2) - (3)]));
@@ -2090,10 +2071,10 @@ yyreduce:
     }
     break;
 
-  case 38:
+  case 35:
 
 /* Line 1269 of yacc.c  */
-#line 276 "../../src/parse-gram.y"
+#line 274 "parse-gram.y"
     {
       symbol_list *list;
       const char *action = translate_symbol_action ((yyvsp[(2) - (3)].chars), (yylsp[(2) - (3)]));
@@ -2103,42 +2084,70 @@ yyreduce:
     }
     break;
 
-  case 39:
+  case 36:
 
 /* Line 1269 of yacc.c  */
-#line 284 "../../src/parse-gram.y"
+#line 282 "parse-gram.y"
     {
       default_prec = true;
     }
     break;
 
-  case 40:
+  case 37:
 
 /* Line 1269 of yacc.c  */
-#line 288 "../../src/parse-gram.y"
+#line 286 "parse-gram.y"
     {
       default_prec = false;
     }
     break;
 
+  case 38:
+
+/* Line 1269 of yacc.c  */
+#line 289 "parse-gram.y"
+    { prologue_augment ((yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)]), true); }
+    break;
+
+  case 39:
+
+/* Line 1269 of yacc.c  */
+#line 290 "parse-gram.y"
+    { prologue_augment ((yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)]), false); }
+    break;
+
+  case 40:
+
+/* Line 1269 of yacc.c  */
+#line 291 "parse-gram.y"
+    { muscle_code_grow ("provides", (yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])); }
+    break;
+
   case 41:
 
 /* Line 1269 of yacc.c  */
-#line 301 "../../src/parse-gram.y"
-    {}
+#line 292 "parse-gram.y"
+    { muscle_code_grow ("requires", (yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])); }
     break;
 
   case 42:
 
 /* Line 1269 of yacc.c  */
-#line 302 "../../src/parse-gram.y"
-    { muscle_code_grow ("union_name", (yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
+#line 303 "parse-gram.y"
+    {}
     break;
 
   case 43:
 
 /* Line 1269 of yacc.c  */
-#line 307 "../../src/parse-gram.y"
+#line 304 "parse-gram.y"
+    { muscle_code_grow ("union_name", (yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
+    break;
+
+  case 44:
+
+/* Line 1269 of yacc.c  */
+#line 309 "parse-gram.y"
     {
       char const *body = (yyvsp[(3) - (3)].chars);
 
@@ -2162,44 +2171,44 @@ yyreduce:
     }
     break;
 
-  case 44:
+  case 45:
 
 /* Line 1269 of yacc.c  */
-#line 334 "../../src/parse-gram.y"
+#line 336 "parse-gram.y"
     { current_class = nterm_sym; }
     break;
 
-  case 45:
+  case 46:
 
 /* Line 1269 of yacc.c  */
-#line 335 "../../src/parse-gram.y"
+#line 337 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
     break;
 
-  case 46:
+  case 47:
 
 /* Line 1269 of yacc.c  */
-#line 339 "../../src/parse-gram.y"
+#line 341 "parse-gram.y"
     { current_class = token_sym; }
     break;
 
-  case 47:
+  case 48:
 
 /* Line 1269 of yacc.c  */
-#line 340 "../../src/parse-gram.y"
+#line 342 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
     break;
 
-  case 48:
+  case 49:
 
 /* Line 1269 of yacc.c  */
-#line 345 "../../src/parse-gram.y"
+#line 347 "parse-gram.y"
     {
       symbol_list *list;
       tag_seen = true;
@@ -2209,10 +2218,10 @@ yyreduce:
     }
     break;
 
-  case 49:
+  case 50:
 
 /* Line 1269 of yacc.c  */
-#line 356 "../../src/parse-gram.y"
+#line 358 "parse-gram.y"
     {
       symbol_list *list;
       ++current_prec;
@@ -2226,114 +2235,114 @@ yyreduce:
     }
     break;
 
-  case 50:
+  case 51:
 
 /* Line 1269 of yacc.c  */
-#line 370 "../../src/parse-gram.y"
+#line 372 "parse-gram.y"
     { (yyval.assoc) = left_assoc; }
     break;
 
-  case 51:
+  case 52:
 
 /* Line 1269 of yacc.c  */
-#line 371 "../../src/parse-gram.y"
+#line 373 "parse-gram.y"
     { (yyval.assoc) = right_assoc; }
     break;
 
-  case 52:
+  case 53:
 
 /* Line 1269 of yacc.c  */
-#line 372 "../../src/parse-gram.y"
+#line 374 "parse-gram.y"
     { (yyval.assoc) = non_assoc; }
     break;
 
-  case 53:
+  case 54:
 
 /* Line 1269 of yacc.c  */
-#line 376 "../../src/parse-gram.y"
+#line 378 "parse-gram.y"
     { current_type = NULL; }
     break;
 
-  case 54:
+  case 55:
 
 /* Line 1269 of yacc.c  */
-#line 377 "../../src/parse-gram.y"
+#line 379 "parse-gram.y"
     { current_type = (yyvsp[(1) - (1)].uniqstr); tag_seen = true; }
     break;
 
-  case 55:
+  case 56:
 
 /* Line 1269 of yacc.c  */
-#line 383 "../../src/parse-gram.y"
+#line 385 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
-  case 56:
+  case 57:
 
 /* Line 1269 of yacc.c  */
-#line 385 "../../src/parse-gram.y"
+#line 387 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), symbol_list_sym_new ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]))); }
     break;
 
-  case 57:
+  case 58:
 
 /* Line 1269 of yacc.c  */
-#line 389 "../../src/parse-gram.y"
+#line 391 "parse-gram.y"
     { (yyval.list) = (yyvsp[(1) - (1)].list); }
     break;
 
-  case 58:
+  case 59:
 
 /* Line 1269 of yacc.c  */
-#line 390 "../../src/parse-gram.y"
+#line 392 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), (yyvsp[(2) - (2)].list)); }
     break;
 
-  case 59:
+  case 60:
 
 /* Line 1269 of yacc.c  */
-#line 394 "../../src/parse-gram.y"
+#line 396 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
-  case 60:
+  case 61:
 
 /* Line 1269 of yacc.c  */
-#line 395 "../../src/parse-gram.y"
+#line 397 "parse-gram.y"
     { (yyval.list) = symbol_list_type_new ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
-  case 61:
+  case 62:
 
 /* Line 1269 of yacc.c  */
-#line 396 "../../src/parse-gram.y"
+#line 398 "parse-gram.y"
     { (yyval.list) = symbol_list_default_new ((yylsp[(1) - (1)])); }
     break;
 
-  case 62:
+  case 63:
 
 /* Line 1269 of yacc.c  */
-#line 402 "../../src/parse-gram.y"
+#line 404 "parse-gram.y"
     {
        current_type = (yyvsp[(1) - (1)].uniqstr);
        tag_seen = true;
      }
     break;
 
-  case 63:
+  case 64:
 
 /* Line 1269 of yacc.c  */
-#line 407 "../../src/parse-gram.y"
+#line 409 "parse-gram.y"
     {
        symbol_class_set ((yyvsp[(1) - (1)].symbol), current_class, (yylsp[(1) - (1)]), true);
        symbol_type_set ((yyvsp[(1) - (1)].symbol), current_type, (yylsp[(1) - (1)]));
      }
     break;
 
-  case 64:
+  case 65:
 
 /* Line 1269 of yacc.c  */
-#line 412 "../../src/parse-gram.y"
+#line 414 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
       symbol_type_set ((yyvsp[(1) - (2)].symbol), current_type, (yylsp[(1) - (2)]));
@@ -2341,10 +2350,10 @@ yyreduce:
     }
     break;
 
-  case 65:
+  case 66:
 
 /* Line 1269 of yacc.c  */
-#line 418 "../../src/parse-gram.y"
+#line 420 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
       symbol_type_set ((yyvsp[(1) - (2)].symbol), current_type, (yylsp[(1) - (2)]));
@@ -2352,10 +2361,10 @@ yyreduce:
     }
     break;
 
-  case 66:
+  case 67:
 
 /* Line 1269 of yacc.c  */
-#line 424 "../../src/parse-gram.y"
+#line 426 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (3)].symbol), current_class, (yylsp[(1) - (3)]), true);
       symbol_type_set ((yyvsp[(1) - (3)].symbol), current_type, (yylsp[(1) - (3)]));
@@ -2364,109 +2373,109 @@ yyreduce:
     }
     break;
 
-  case 73:
+  case 74:
 
 /* Line 1269 of yacc.c  */
-#line 454 "../../src/parse-gram.y"
+#line 456 "parse-gram.y"
     {
       yyerrok;
     }
     break;
 
-  case 74:
+  case 75:
 
 /* Line 1269 of yacc.c  */
-#line 460 "../../src/parse-gram.y"
+#line 462 "parse-gram.y"
     { current_lhs = (yyvsp[(1) - (1)].symbol); current_lhs_location = (yylsp[(1) - (1)]); }
     break;
 
-  case 76:
+  case 77:
 
 /* Line 1269 of yacc.c  */
-#line 464 "../../src/parse-gram.y"
+#line 466 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(1) - (1)])); }
     break;
 
-  case 77:
+  case 78:
 
 /* Line 1269 of yacc.c  */
-#line 465 "../../src/parse-gram.y"
+#line 467 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(3) - (3)])); }
     break;
 
-  case 79:
+  case 80:
 
 /* Line 1269 of yacc.c  */
-#line 471 "../../src/parse-gram.y"
+#line 473 "parse-gram.y"
     { grammar_current_rule_begin (current_lhs, current_lhs_location); }
     break;
 
-  case 80:
+  case 81:
 
 /* Line 1269 of yacc.c  */
-#line 473 "../../src/parse-gram.y"
+#line 475 "parse-gram.y"
     { grammar_current_rule_symbol_append ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)])); }
     break;
 
-  case 81:
+  case 82:
 
 /* Line 1269 of yacc.c  */
-#line 475 "../../src/parse-gram.y"
+#line 477 "parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])); }
     break;
 
-  case 82:
+  case 83:
 
 /* Line 1269 of yacc.c  */
-#line 477 "../../src/parse-gram.y"
+#line 479 "parse-gram.y"
     { grammar_current_rule_prec_set ((yyvsp[(3) - (3)].symbol), (yylsp[(3) - (3)])); }
     break;
 
-  case 83:
+  case 84:
 
 /* Line 1269 of yacc.c  */
-#line 479 "../../src/parse-gram.y"
+#line 481 "parse-gram.y"
     { grammar_current_rule_dprec_set ((yyvsp[(3) - (3)].integer), (yylsp[(3) - (3)])); }
     break;
 
-  case 84:
+  case 85:
 
 /* Line 1269 of yacc.c  */
-#line 481 "../../src/parse-gram.y"
+#line 483 "parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[(3) - (3)].uniqstr), (yylsp[(3) - (3)])); }
     break;
 
-  case 87:
+  case 88:
 
 /* Line 1269 of yacc.c  */
-#line 497 "../../src/parse-gram.y"
+#line 499 "parse-gram.y"
     {
       static char one[] = "1";
       (yyval.chars) = one;
     }
     break;
 
-  case 89:
+  case 90:
 
 /* Line 1269 of yacc.c  */
-#line 507 "../../src/parse-gram.y"
+#line 509 "parse-gram.y"
     {
       (yyvsp[(1) - (1)].chars)[strlen ((yyvsp[(1) - (1)].chars)) - 1] = '\n';
       (yyval.chars) = translate_code ((yyvsp[(1) - (1)].chars) + 1, (yylsp[(1) - (1)]));
     }
     break;
 
-  case 90:
+  case 91:
 
 /* Line 1269 of yacc.c  */
-#line 523 "../../src/parse-gram.y"
+#line 525 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
-  case 91:
+  case 92:
 
 /* Line 1269 of yacc.c  */
-#line 525 "../../src/parse-gram.y"
+#line 527 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[(1) - (1)].character)), (yylsp[(1) - (1)]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[(1) - (1)]), false);
@@ -2474,27 +2483,27 @@ yyreduce:
     }
     break;
 
-  case 92:
+  case 93:
 
 /* Line 1269 of yacc.c  */
-#line 533 "../../src/parse-gram.y"
+#line 535 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
-  case 95:
+  case 96:
 
 /* Line 1269 of yacc.c  */
-#line 545 "../../src/parse-gram.y"
+#line 547 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[(1) - (1)].chars)), (yylsp[(1) - (1)]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[(1) - (1)]), false);
     }
     break;
 
-  case 97:
+  case 98:
 
 /* Line 1269 of yacc.c  */
-#line 554 "../../src/parse-gram.y"
+#line 556 "parse-gram.y"
     {
       muscle_code_grow ("epilogue", translate_code ((yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])), (yylsp[(2) - (2)]));
       gram_scanner_last_string_free ();
@@ -2504,7 +2513,7 @@ yyreduce:
 
 
 /* Line 1269 of yacc.c  */
-#line 2508 "../../src/parse-gram.c"
+#line 2517 "parse-gram.c"
       default: break;
     }
   YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);
@@ -2723,7 +2732,7 @@ yyreturn:
 
 
 /* Line 1486 of yacc.c  */
-#line 560 "../../src/parse-gram.y"
+#line 562 "parse-gram.y"
 
 
 
