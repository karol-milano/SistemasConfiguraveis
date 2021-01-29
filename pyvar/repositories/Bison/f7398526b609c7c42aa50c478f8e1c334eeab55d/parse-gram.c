@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 2.4.58-9380c.  */
+/* A Bison parser, made by GNU Bison 2.4.79-c85be.  */
 
 /* Implementation for Bison's Yacc-like parsers in C
    
@@ -45,7 +45,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "2.4.58-9380c"
+#define YYBISON_VERSION "2.4.79-c85be"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -150,7 +150,7 @@ static int current_prec = 0;
 
 
 /* Line 191 of yacc.c  */
-#line 154 "parse-gram.c"
+#line 154 "../../../src/parse-gram.c"
 
 /* Enabling traces.  */
 #ifndef YYDEBUG
@@ -188,50 +188,51 @@ static int current_prec = 0;
      PERCENT_LEFT = 265,
      PERCENT_RIGHT = 266,
      PERCENT_NONASSOC = 267,
-     PERCENT_PREC = 268,
-     PERCENT_DPREC = 269,
-     PERCENT_MERGE = 270,
-     PERCENT_CODE = 271,
-     PERCENT_DEBUG = 272,
-     PERCENT_DEFAULT_PREC = 273,
-     PERCENT_DEFINE = 274,
-     PERCENT_DEFINES = 275,
-     PERCENT_ERROR_VERBOSE = 276,
-     PERCENT_EXPECT = 277,
-     PERCENT_EXPECT_RR = 278,
-     PERCENT_FILE_PREFIX = 279,
-     PERCENT_GLR_PARSER = 280,
-     PERCENT_INITIAL_ACTION = 281,
-     PERCENT_LANGUAGE = 282,
-     PERCENT_LEX_PARAM = 283,
-     PERCENT_LOCATIONS = 284,
-     PERCENT_NAME_PREFIX = 285,
-     PERCENT_NO_DEFAULT_PREC = 286,
-     PERCENT_NO_LINES = 287,
-     PERCENT_NONDETERMINISTIC_PARSER = 288,
-     PERCENT_OUTPUT = 289,
-     PERCENT_PARSE_PARAM = 290,
-     PERCENT_PURE_PARSER = 291,
-     PERCENT_REQUIRE = 292,
-     PERCENT_SKELETON = 293,
-     PERCENT_START = 294,
-     PERCENT_TOKEN_TABLE = 295,
-     PERCENT_VERBOSE = 296,
-     PERCENT_YACC = 297,
-     BRACED_CODE = 298,
-     CHAR = 299,
-     EPILOGUE = 300,
-     EQUAL = 301,
-     ID = 302,
-     ID_COLON = 303,
-     PERCENT_PERCENT = 304,
-     PIPE = 305,
-     PROLOGUE = 306,
-     SEMICOLON = 307,
-     TYPE = 308,
-     TYPE_TAG_ANY = 309,
-     TYPE_TAG_NONE = 310,
-     PERCENT_UNION = 311
+     PERCENT_PRECEDENCE = 268,
+     PERCENT_PREC = 269,
+     PERCENT_DPREC = 270,
+     PERCENT_MERGE = 271,
+     PERCENT_CODE = 272,
+     PERCENT_DEBUG = 273,
+     PERCENT_DEFAULT_PREC = 274,
+     PERCENT_DEFINE = 275,
+     PERCENT_DEFINES = 276,
+     PERCENT_ERROR_VERBOSE = 277,
+     PERCENT_EXPECT = 278,
+     PERCENT_EXPECT_RR = 279,
+     PERCENT_FILE_PREFIX = 280,
+     PERCENT_GLR_PARSER = 281,
+     PERCENT_INITIAL_ACTION = 282,
+     PERCENT_LANGUAGE = 283,
+     PERCENT_LEX_PARAM = 284,
+     PERCENT_LOCATIONS = 285,
+     PERCENT_NAME_PREFIX = 286,
+     PERCENT_NO_DEFAULT_PREC = 287,
+     PERCENT_NO_LINES = 288,
+     PERCENT_NONDETERMINISTIC_PARSER = 289,
+     PERCENT_OUTPUT = 290,
+     PERCENT_PARSE_PARAM = 291,
+     PERCENT_PURE_PARSER = 292,
+     PERCENT_REQUIRE = 293,
+     PERCENT_SKELETON = 294,
+     PERCENT_START = 295,
+     PERCENT_TOKEN_TABLE = 296,
+     PERCENT_VERBOSE = 297,
+     PERCENT_YACC = 298,
+     BRACED_CODE = 299,
+     CHAR = 300,
+     EPILOGUE = 301,
+     EQUAL = 302,
+     ID = 303,
+     ID_COLON = 304,
+     PERCENT_PERCENT = 305,
+     PIPE = 306,
+     PROLOGUE = 307,
+     SEMICOLON = 308,
+     TYPE = 309,
+     TYPE_TAG_ANY = 310,
+     TYPE_TAG_NONE = 311,
+     PERCENT_UNION = 312
    };
 #endif
 /* Tokens.  */
@@ -246,50 +247,51 @@ static int current_prec = 0;
 #define PERCENT_LEFT 265
 #define PERCENT_RIGHT 266
 #define PERCENT_NONASSOC 267
-#define PERCENT_PREC 268
-#define PERCENT_DPREC 269
-#define PERCENT_MERGE 270
-#define PERCENT_CODE 271
-#define PERCENT_DEBUG 272
-#define PERCENT_DEFAULT_PREC 273
-#define PERCENT_DEFINE 274
-#define PERCENT_DEFINES 275
-#define PERCENT_ERROR_VERBOSE 276
-#define PERCENT_EXPECT 277
-#define PERCENT_EXPECT_RR 278
-#define PERCENT_FILE_PREFIX 279
-#define PERCENT_GLR_PARSER 280
-#define PERCENT_INITIAL_ACTION 281
-#define PERCENT_LANGUAGE 282
-#define PERCENT_LEX_PARAM 283
-#define PERCENT_LOCATIONS 284
-#define PERCENT_NAME_PREFIX 285
-#define PERCENT_NO_DEFAULT_PREC 286
-#define PERCENT_NO_LINES 287
-#define PERCENT_NONDETERMINISTIC_PARSER 288
-#define PERCENT_OUTPUT 289
-#define PERCENT_PARSE_PARAM 290
-#define PERCENT_PURE_PARSER 291
-#define PERCENT_REQUIRE 292
-#define PERCENT_SKELETON 293
-#define PERCENT_START 294
-#define PERCENT_TOKEN_TABLE 295
-#define PERCENT_VERBOSE 296
-#define PERCENT_YACC 297
-#define BRACED_CODE 298
-#define CHAR 299
-#define EPILOGUE 300
-#define EQUAL 301
-#define ID 302
-#define ID_COLON 303
-#define PERCENT_PERCENT 304
-#define PIPE 305
-#define PROLOGUE 306
-#define SEMICOLON 307
-#define TYPE 308
-#define TYPE_TAG_ANY 309
-#define TYPE_TAG_NONE 310
-#define PERCENT_UNION 311
+#define PERCENT_PRECEDENCE 268
+#define PERCENT_PREC 269
+#define PERCENT_DPREC 270
+#define PERCENT_MERGE 271
+#define PERCENT_CODE 272
+#define PERCENT_DEBUG 273
+#define PERCENT_DEFAULT_PREC 274
+#define PERCENT_DEFINE 275
+#define PERCENT_DEFINES 276
+#define PERCENT_ERROR_VERBOSE 277
+#define PERCENT_EXPECT 278
+#define PERCENT_EXPECT_RR 279
+#define PERCENT_FILE_PREFIX 280
+#define PERCENT_GLR_PARSER 281
+#define PERCENT_INITIAL_ACTION 282
+#define PERCENT_LANGUAGE 283
+#define PERCENT_LEX_PARAM 284
+#define PERCENT_LOCATIONS 285
+#define PERCENT_NAME_PREFIX 286
+#define PERCENT_NO_DEFAULT_PREC 287
+#define PERCENT_NO_LINES 288
+#define PERCENT_NONDETERMINISTIC_PARSER 289
+#define PERCENT_OUTPUT 290
+#define PERCENT_PARSE_PARAM 291
+#define PERCENT_PURE_PARSER 292
+#define PERCENT_REQUIRE 293
+#define PERCENT_SKELETON 294
+#define PERCENT_START 295
+#define PERCENT_TOKEN_TABLE 296
+#define PERCENT_VERBOSE 297
+#define PERCENT_YACC 298
+#define BRACED_CODE 299
+#define CHAR 300
+#define EPILOGUE 301
+#define EQUAL 302
+#define ID 303
+#define ID_COLON 304
+#define PERCENT_PERCENT 305
+#define PIPE 306
+#define PROLOGUE 307
+#define SEMICOLON 308
+#define TYPE 309
+#define TYPE_TAG_ANY 310
+#define TYPE_TAG_NONE 311
+#define PERCENT_UNION 312
 
 
 
@@ -298,7 +300,7 @@ static int current_prec = 0;
 typedef union YYSTYPE
 {
 
-/* Line 224 of yacc.c  */
+/* Line 216 of yacc.c  */
 #line 92 "parse-gram.y"
 
   symbol *symbol;
@@ -312,8 +314,8 @@ typedef union YYSTYPE
 
 
 
-/* Line 224 of yacc.c  */
-#line 317 "parse-gram.c"
+/* Line 216 of yacc.c  */
+#line 319 "../../../src/parse-gram.c"
 } YYSTYPE;
 # define YYSTYPE_IS_TRIVIAL 1
 # define yystype YYSTYPE /* obsolescent; will be withdrawn */
@@ -338,7 +340,7 @@ typedef struct YYLTYPE
 
 
 /* Line 266 of yacc.c  */
-#line 342 "parse-gram.c"
+#line 344 "../../../src/parse-gram.c"
 
 #ifdef short
 # undef short
@@ -555,20 +557,20 @@ union yyalloc
 /* YYFINAL -- State number of the termination state.  */
 #define YYFINAL  3
 /* YYLAST -- Last index in YYTABLE.  */
-#define YYLAST   156
+#define YYLAST   203
 
 /* YYNTOKENS -- Number of terminals.  */
-#define YYNTOKENS  57
+#define YYNTOKENS  58
 /* YYNNTS -- Number of nonterminals.  */
 #define YYNNTS  33
 /* YYNRULES -- Number of rules.  */
-#define YYNRULES  105
+#define YYNRULES  106
 /* YYNRULES -- Number of states.  */
-#define YYNSTATES  143
+#define YYNSTATES  144
 
 /* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
 #define YYUNDEFTOK  2
-#define YYMAXUTOK   311
+#define YYMAXUTOK   312
 
 #define YYTRANSLATE(YYX)						\
   ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)
@@ -607,7 +609,7 @@ static const yytype_uint8 yytranslate[] =
       25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
       35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
       45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
-      55,    56
+      55,    56,    57
 };
 
 #if YYDEBUG
@@ -620,60 +622,61 @@ static const yytype_uint16 yyprhs[] =
       53,    55,    58,    62,    64,    66,    69,    73,    76,    78,
       81,    84,    86,    88,    90,    92,    94,    96,    99,   103,
      107,   109,   111,   114,   118,   119,   121,   125,   126,   130,
-     131,   135,   139,   143,   145,   147,   149,   150,   152,   154,
-     157,   159,   162,   164,   167,   169,   172,   174,   176,   178,
-     180,   182,   184,   187,   190,   194,   196,   199,   201,   204,
-     206,   209,   212,   213,   217,   219,   223,   226,   227,   230,
-     233,   237,   241,   245,   247,   249,   250,   252,   254,   256,
-     258,   260,   262,   264,   266,   267
+     131,   135,   139,   143,   145,   147,   149,   151,   152,   154,
+     156,   159,   161,   164,   166,   169,   171,   174,   176,   178,
+     180,   182,   184,   186,   189,   192,   196,   198,   201,   203,
+     206,   208,   211,   214,   215,   219,   221,   225,   228,   229,
+     232,   235,   239,   243,   247,   249,   251,   252,   254,   256,
+     258,   260,   262,   264,   266,   268,   269
 };
 
 /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
 static const yytype_int8 yyrhs[] =
 {
-      58,     0,    -1,    59,    49,    76,    89,    -1,    -1,    59,
-      60,    -1,    61,    -1,    51,    -1,    17,    -1,    19,    82,
-      83,    -1,    20,    -1,    20,     3,    -1,    21,    -1,    22,
-       4,    -1,    23,     4,    -1,    24,     3,    -1,    24,    46,
-       3,    -1,    25,    -1,    26,    43,    -1,    27,     3,    -1,
-      28,    43,    -1,    29,    -1,    30,     3,    -1,    30,    46,
-       3,    -1,    32,    -1,    33,    -1,    34,     3,    -1,    34,
-      46,     3,    -1,    35,    43,    -1,    36,    -1,    37,     3,
-      -1,    38,     3,    -1,    40,    -1,    41,    -1,    42,    -1,
-      52,    -1,    66,    -1,    63,    -1,    39,    87,    -1,     8,
-      43,    72,    -1,     9,    43,    72,    -1,    18,    -1,    31,
-      -1,    16,    84,    -1,    16,    47,    84,    -1,    -1,    47,
-      -1,    56,    62,    84,    -1,    -1,     6,    64,    75,    -1,
-      -1,     5,    65,    75,    -1,     7,    53,    71,    -1,    67,
-      68,    69,    -1,    10,    -1,    11,    -1,    12,    -1,    -1,
-      53,    -1,    70,    -1,    69,    70,    -1,    87,    -1,    87,
-       4,    -1,    87,    -1,    71,    87,    -1,    73,    -1,    72,
-      73,    -1,    87,    -1,    53,    -1,    54,    -1,    55,    -1,
-      53,    -1,    85,    -1,    85,     4,    -1,    85,    88,    -1,
-      85,     4,    88,    -1,    74,    -1,    75,    74,    -1,    77,
-      -1,    76,    77,    -1,    78,    -1,    61,    52,    -1,     1,
-      52,    -1,    -1,    86,    79,    80,    -1,    81,    -1,    80,
-      50,    81,    -1,    80,    52,    -1,    -1,    81,    87,    -1,
-      81,    43,    -1,    81,    13,    87,    -1,    81,    14,     4,
-      -1,    81,    15,    53,    -1,    47,    -1,     3,    -1,    -1,
-       3,    -1,    43,    -1,    47,    -1,    44,    -1,    48,    -1,
-      85,    -1,    88,    -1,     3,    -1,    -1,    49,    45,    -1
+      59,     0,    -1,    60,    50,    77,    90,    -1,    -1,    60,
+      61,    -1,    62,    -1,    52,    -1,    18,    -1,    20,    83,
+      84,    -1,    21,    -1,    21,     3,    -1,    22,    -1,    23,
+       4,    -1,    24,     4,    -1,    25,     3,    -1,    25,    47,
+       3,    -1,    26,    -1,    27,    44,    -1,    28,     3,    -1,
+      29,    44,    -1,    30,    -1,    31,     3,    -1,    31,    47,
+       3,    -1,    33,    -1,    34,    -1,    35,     3,    -1,    35,
+      47,     3,    -1,    36,    44,    -1,    37,    -1,    38,     3,
+      -1,    39,     3,    -1,    41,    -1,    42,    -1,    43,    -1,
+      53,    -1,    67,    -1,    64,    -1,    40,    88,    -1,     8,
+      44,    73,    -1,     9,    44,    73,    -1,    19,    -1,    32,
+      -1,    17,    85,    -1,    17,    48,    85,    -1,    -1,    48,
+      -1,    57,    63,    85,    -1,    -1,     6,    65,    76,    -1,
+      -1,     5,    66,    76,    -1,     7,    54,    72,    -1,    68,
+      69,    70,    -1,    10,    -1,    11,    -1,    12,    -1,    13,
+      -1,    -1,    54,    -1,    71,    -1,    70,    71,    -1,    88,
+      -1,    88,     4,    -1,    88,    -1,    72,    88,    -1,    74,
+      -1,    73,    74,    -1,    88,    -1,    54,    -1,    55,    -1,
+      56,    -1,    54,    -1,    86,    -1,    86,     4,    -1,    86,
+      89,    -1,    86,     4,    89,    -1,    75,    -1,    76,    75,
+      -1,    78,    -1,    77,    78,    -1,    79,    -1,    62,    53,
+      -1,     1,    53,    -1,    -1,    87,    80,    81,    -1,    82,
+      -1,    81,    51,    82,    -1,    81,    53,    -1,    -1,    82,
+      88,    -1,    82,    44,    -1,    82,    14,    88,    -1,    82,
+      15,     4,    -1,    82,    16,    54,    -1,    48,    -1,     3,
+      -1,    -1,     3,    -1,    44,    -1,    48,    -1,    45,    -1,
+      49,    -1,    86,    -1,    89,    -1,     3,    -1,    -1,    50,
+      46,    -1
 };
 
 /* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
 static const yytype_uint16 yyrline[] =
 {
-       0,   202,   202,   210,   212,   216,   217,   227,   228,   232,
-     233,   238,   239,   240,   241,   242,   243,   248,   257,   258,
-     259,   260,   261,   262,   263,   264,   265,   266,   267,   280,
-     281,   305,   306,   307,   308,   312,   313,   314,   318,   325,
-     332,   336,   340,   347,   362,   363,   367,   379,   379,   384,
-     384,   389,   400,   415,   416,   417,   421,   422,   427,   429,
-     434,   435,   440,   442,   447,   448,   452,   453,   454,   455,
-     460,   465,   470,   476,   482,   493,   494,   503,   504,   510,
-     511,   512,   519,   519,   523,   524,   525,   530,   531,   533,
-     535,   537,   539,   549,   550,   556,   559,   568,   588,   590,
-     599,   604,   605,   610,   617,   619
+       0,   203,   203,   211,   213,   217,   218,   228,   229,   233,
+     234,   239,   240,   241,   242,   243,   244,   249,   258,   259,
+     260,   261,   262,   263,   264,   265,   266,   267,   268,   281,
+     282,   306,   307,   308,   309,   313,   314,   315,   319,   326,
+     333,   337,   341,   348,   363,   364,   368,   380,   380,   385,
+     385,   390,   401,   416,   417,   418,   419,   423,   424,   429,
+     431,   436,   437,   442,   444,   449,   450,   454,   455,   456,
+     457,   462,   467,   472,   478,   484,   495,   496,   505,   506,
+     512,   513,   514,   521,   521,   525,   526,   527,   532,   533,
+     535,   537,   539,   541,   551,   552,   558,   561,   570,   590,
+     592,   601,   606,   607,   612,   619,   621
 };
 #endif
 
@@ -684,20 +687,20 @@ static const char *const yytname[] =
 {
   "\"end of file\"", "error", "$undefined", "\"string\"", "\"integer\"",
   "\"%token\"", "\"%nterm\"", "\"%type\"", "\"%destructor\"",
-  "\"%printer\"", "\"%left\"", "\"%right\"", "\"%nonassoc\"", "\"%prec\"",
-  "\"%dprec\"", "\"%merge\"", "\"%code\"", "\"%debug\"",
-  "\"%default-prec\"", "\"%define\"", "\"%defines\"", "\"%error-verbose\"",
-  "\"%expect\"", "\"%expect-rr\"", "\"%file-prefix\"", "\"%glr-parser\"",
-  "\"%initial-action\"", "\"%language\"", "\"%lex-param\"",
-  "\"%locations\"", "\"%name-prefix\"", "\"%no-default-prec\"",
-  "\"%no-lines\"", "\"%nondeterministic-parser\"", "\"%output\"",
-  "\"%parse-param\"", "\"%pure-parser\"", "\"%require\"", "\"%skeleton\"",
-  "\"%start\"", "\"%token-table\"", "\"%verbose\"", "\"%yacc\"",
-  "\"{...}\"", "\"char\"", "\"epilogue\"", "\"=\"", "\"identifier\"",
-  "\"identifier:\"", "\"%%\"", "\"|\"", "\"%{...%}\"", "\";\"", "\"type\"",
-  "\"<*>\"", "\"<>\"", "\"%union\"", "$accept", "input",
-  "prologue_declarations", "prologue_declaration", "grammar_declaration",
-  "union_name", "symbol_declaration", "$@1", "$@2",
+  "\"%printer\"", "\"%left\"", "\"%right\"", "\"%nonassoc\"",
+  "\"%precedence\"", "\"%prec\"", "\"%dprec\"", "\"%merge\"", "\"%code\"",
+  "\"%debug\"", "\"%default-prec\"", "\"%define\"", "\"%defines\"",
+  "\"%error-verbose\"", "\"%expect\"", "\"%expect-rr\"",
+  "\"%file-prefix\"", "\"%glr-parser\"", "\"%initial-action\"",
+  "\"%language\"", "\"%lex-param\"", "\"%locations\"", "\"%name-prefix\"",
+  "\"%no-default-prec\"", "\"%no-lines\"", "\"%nondeterministic-parser\"",
+  "\"%output\"", "\"%parse-param\"", "\"%pure-parser\"", "\"%require\"",
+  "\"%skeleton\"", "\"%start\"", "\"%token-table\"", "\"%verbose\"",
+  "\"%yacc\"", "\"{...}\"", "\"char\"", "\"epilogue\"", "\"=\"",
+  "\"identifier\"", "\"identifier:\"", "\"%%\"", "\"|\"", "\"%{...%}\"",
+  "\";\"", "\"type\"", "\"<*>\"", "\"<>\"", "\"%union\"", "$accept",
+  "input", "prologue_declarations", "prologue_declaration",
+  "grammar_declaration", "union_name", "symbol_declaration", "$@1", "$@2",
   "precedence_declaration", "precedence_declarator", "type.opt",
   "symbols.prec", "symbol.prec", "symbols.1", "generic_symlist",
   "generic_symlist_item", "symbol_def", "symbol_defs.1", "grammar",
@@ -717,24 +720,24 @@ static const yytype_uint16 yytoknum[] =
      275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
      285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
      295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
-     305,   306,   307,   308,   309,   310,   311
+     305,   306,   307,   308,   309,   310,   311,   312
 };
 # endif
 
 /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
 static const yytype_uint8 yyr1[] =
 {
-       0,    57,    58,    59,    59,    60,    60,    60,    60,    60,
-      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
-      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
-      60,    60,    60,    60,    60,    61,    61,    61,    61,    61,
-      61,    61,    61,    61,    62,    62,    61,    64,    63,    65,
-      63,    63,    66,    67,    67,    67,    68,    68,    69,    69,
-      70,    70,    71,    71,    72,    72,    73,    73,    73,    73,
-      74,    74,    74,    74,    74,    75,    75,    76,    76,    77,
-      77,    77,    79,    78,    80,    80,    80,    81,    81,    81,
-      81,    81,    81,    82,    82,    83,    83,    84,    85,    85,
-      86,    87,    87,    88,    89,    89
+       0,    58,    59,    60,    60,    61,    61,    61,    61,    61,
+      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
+      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
+      61,    61,    61,    61,    61,    62,    62,    62,    62,    62,
+      62,    62,    62,    62,    63,    63,    62,    65,    64,    66,
+      64,    64,    67,    68,    68,    68,    68,    69,    69,    70,
+      70,    71,    71,    72,    72,    73,    73,    74,    74,    74,
+      74,    75,    75,    75,    75,    75,    76,    76,    77,    77,
+      78,    78,    78,    80,    79,    81,    81,    81,    82,    82,
+      82,    82,    82,    82,    83,    83,    84,    84,    85,    86,
+      86,    87,    88,    88,    89,    90,    90
 };
 
 /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
@@ -745,12 +748,12 @@ static const yytype_uint8 yyr2[] =
        1,     2,     3,     1,     1,     2,     3,     2,     1,     2,
        2,     1,     1,     1,     1,     1,     1,     2,     3,     3,
        1,     1,     2,     3,     0,     1,     3,     0,     3,     0,
-       3,     3,     3,     1,     1,     1,     0,     1,     1,     2,
-       1,     2,     1,     2,     1,     2,     1,     1,     1,     1,
-       1,     1,     2,     2,     3,     1,     2,     1,     2,     1,
-       2,     2,     0,     3,     1,     3,     2,     0,     2,     2,
-       3,     3,     3,     1,     1,     0,     1,     1,     1,     1,
-       1,     1,     1,     1,     0,     2
+       3,     3,     3,     1,     1,     1,     1,     0,     1,     1,
+       2,     1,     2,     1,     2,     1,     2,     1,     1,     1,
+       1,     1,     1,     2,     2,     3,     1,     2,     1,     2,
+       1,     2,     2,     0,     3,     1,     3,     2,     0,     2,
+       2,     3,     3,     3,     1,     1,     0,     1,     1,     1,
+       1,     1,     1,     1,     1,     0,     2
 };
 
 /* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
@@ -759,126 +762,136 @@ static const yytype_uint8 yyr2[] =
 static const yytype_uint8 yydefact[] =
 {
        3,     0,     0,     1,    49,    47,     0,     0,     0,    53,
-      54,    55,     0,     7,    40,     0,     9,    11,     0,     0,
-       0,    16,     0,     0,     0,    20,     0,    41,    23,    24,
-       0,     0,    28,     0,     0,     0,    31,    32,    33,     0,
-       6,    34,    44,     4,     5,    36,    35,    56,     0,     0,
-       0,     0,     0,    97,     0,    42,    94,    93,    95,    10,
-      12,    13,    14,     0,    17,    18,    19,    21,     0,    25,
-       0,    27,    29,    30,   103,    99,    98,   101,    37,   102,
-       0,   100,     0,     0,    77,    79,    82,    45,     0,    57,
-       0,    70,    75,    50,    71,    48,    51,    62,    67,    68,
-      69,    38,    64,    66,    39,    43,    96,     8,    15,    22,
-      26,    81,    80,     0,    78,     2,    87,    46,    52,    58,
-      60,    76,    72,    73,    63,    65,   105,    83,    84,    59,
-      61,    74,    87,    86,     0,     0,     0,    89,    88,    85,
-      90,    91,    92
+      54,    55,    56,     0,     7,    40,     0,     9,    11,     0,
+       0,     0,    16,     0,     0,     0,    20,     0,    41,    23,
+      24,     0,     0,    28,     0,     0,     0,    31,    32,    33,
+       0,     6,    34,    44,     4,     5,    36,    35,    57,     0,
+       0,     0,     0,     0,    98,     0,    42,    95,    94,    96,
+      10,    12,    13,    14,     0,    17,    18,    19,    21,     0,
+      25,     0,    27,    29,    30,   104,   100,    99,   102,    37,
+     103,     0,   101,     0,     0,    78,    80,    83,    45,     0,
+      58,     0,    71,    76,    50,    72,    48,    51,    63,    68,
+      69,    70,    38,    65,    67,    39,    43,    97,     8,    15,
+      22,    26,    82,    81,     0,    79,     2,    88,    46,    52,
+      59,    61,    77,    73,    74,    64,    66,   106,    84,    85,
+      60,    62,    75,    88,    87,     0,     0,     0,    90,    89,
+      86,    91,    92,    93
 };
 
 /* YYDEFGOTO[NTERM-NUM].  */
 static const yytype_int16 yydefgoto[] =
 {
-      -1,     1,     2,    43,    82,    88,    45,    49,    48,    46,
-      47,    90,   118,   119,    96,   101,   102,    92,    93,    83,
-      84,    85,   116,   127,   128,    58,   107,    55,    77,    86,
-     103,    79,   115
+      -1,     1,     2,    44,    83,    89,    46,    50,    49,    47,
+      48,    91,   119,   120,    97,   102,   103,    93,    94,    84,
+      85,    86,   117,   128,   129,    59,   108,    56,    78,    87,
+     104,    80,   116
 };
 
 /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
    STATE-NUM.  */
-#define YYPACT_NINF -60
+#define YYPACT_NINF -81
 static const yytype_int16 yypact[] =
 {
-     -60,    18,   100,   -60,   -60,   -60,   -16,    24,    27,   -60,
-     -60,   -60,    -8,   -60,   -60,    11,    70,   -60,    71,    80,
-       2,   -60,    46,    87,    48,   -60,    31,   -60,   -60,   -60,
-      40,    49,   -60,    91,    92,     0,   -60,   -60,   -60,    15,
-     -60,   -60,    50,   -60,   -60,   -60,   -60,    43,    12,    12,
-       0,    25,    25,   -60,    55,   -60,   -60,   -60,    97,   -60,
-     -60,   -60,   -60,    98,   -60,   -60,   -60,   -60,    99,   -60,
-     110,   -60,   -60,   -60,   -60,   -60,   -60,   -60,   -60,   -60,
-      51,   -60,    62,     1,   -60,   -60,   -60,   -60,    55,   -60,
-       0,   -60,   -60,    12,    84,    12,     0,   -60,   -60,   -60,
-     -60,    25,   -60,   -60,    25,   -60,   -60,   -60,   -60,   -60,
-     -60,   -60,   -60,   101,   -60,   -60,   -60,   -60,     0,   -60,
-     111,   -60,   140,   -60,   -60,   -60,   -60,    10,    38,   -60,
-     -60,   -60,   -60,   -60,     0,   141,    94,   -60,   -60,    38,
-     -60,   -60,   -60
+     -81,    23,   111,   -81,   -81,   -81,   -28,   -12,    -8,   -81,
+     -81,   -81,   -81,   -13,   -81,   -81,    14,    43,   -81,    48,
+      49,     2,   -81,    10,    53,    34,   -81,    13,   -81,   -81,
+     -81,    26,    36,   -81,    54,    78,     0,   -81,   -81,   -81,
+      58,   -81,   -81,    41,   -81,   -81,   -81,   -81,    28,   -24,
+     -24,     0,    31,    31,   -81,    44,   -81,   -81,   -81,    81,
+     -81,   -81,   -81,   -81,    88,   -81,   -81,   -81,   -81,    89,
+     -81,    91,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,
+     -81,    42,   -81,    47,     1,   -81,   -81,   -81,   -81,    44,
+     -81,     0,   -81,   -81,   -24,    40,   -24,     0,   -81,   -81,
+     -81,   -81,    31,   -81,   -81,    31,   -81,   -81,   -81,   -81,
+     -81,   -81,   -81,   -81,    50,   -81,   -81,   -81,   -81,     0,
+     -81,    93,   -81,    98,   -81,   -81,   -81,   -81,   -14,   155,
+     -81,   -81,   -81,   -81,   -81,     0,    99,    51,   -81,   -81,
+     155,   -81,   -81,   -81
 };
 
 /* YYPGOTO[NTERM-NUM].  */
-static const yytype_int16 yypgoto[] =
+static const yytype_int8 yypgoto[] =
 {
-     -60,   -60,   -60,   -60,   142,   -60,   -60,   -60,   -60,   -60,
-     -60,   -60,   -60,    30,   -60,   102,   -59,   -27,   104,   -60,
-      67,   -60,   -60,   -60,    23,   -60,   -60,   -50,   -19,   -60,
-     -35,   -58,   -60
+     -81,   -81,   -81,   -81,   100,   -81,   -81,   -81,   -81,   -81,
+     -81,   -81,   -81,   -11,   -81,    56,   -80,   -54,    60,   -81,
+      22,   -81,   -81,   -81,   -21,   -81,   -81,   -51,   -22,   -81,
+     -36,   -76,   -81
 };
 
 /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
    positive, shift that token.  If negative, reduce the rule which
    number is the opposite.  If zero, do what YYDEFACT says.
    If YYTABLE_NINF, syntax error.  */
-#define YYTABLE_NINF -105
+#define YYTABLE_NINF -106
 static const yytype_int16 yytable[] =
 {
-      78,  -104,    80,    74,   105,    62,     4,     5,     6,     7,
-       8,     9,    10,    11,    56,    97,    80,    12,     3,    14,
-       4,     5,     6,     7,     8,     9,    10,    11,    74,    94,
-      94,    12,    27,    14,    67,    53,   123,    50,   117,    54,
-      35,    74,   125,    69,    75,   125,    27,    76,    63,    81,
-     113,   134,   135,   136,    35,   120,    75,    42,    57,    76,
-     132,   124,   133,    81,   131,    91,   121,    51,   121,    75,
-      52,    42,    76,    59,    94,    60,    94,    68,    98,    99,
-     100,   137,    75,   120,    61,    76,    70,    74,   122,    64,
-      65,    66,    71,   138,    72,    73,    89,    87,    53,   140,
-     106,   108,   109,   111,   138,     4,     5,     6,     7,     8,
-       9,    10,    11,   110,   112,   130,    12,    13,    14,    15,
-      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
-      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
-      36,    37,    38,    74,    44,   141,   126,   142,   129,    39,
-     114,    40,    41,    95,   104,   139,    42
+      79,  -105,    81,    75,   106,    63,     4,     5,     6,     7,
+       8,     9,    10,    11,    12,    98,    68,    57,    13,   124,
+      15,    76,   126,     3,    77,   126,    51,    95,    95,    70,
+      92,    54,    52,    28,    75,    55,    53,   133,   118,   134,
+     122,    36,   122,    75,   123,    76,    60,   132,    77,    64,
+      82,   114,    61,    62,    65,   121,    66,    73,    43,    81,
+      69,   125,    58,     4,     5,     6,     7,     8,     9,    10,
+      11,    12,    95,    71,    95,    13,    76,    15,    67,    77,
+      72,    74,    90,   121,   107,    99,   100,   101,    54,    88,
+      28,   109,   110,   139,   111,   112,   127,   131,    36,   141,
+     113,    75,    45,   142,   139,   143,   115,    82,   130,   105,
+      96,     0,   140,     0,     0,    43,     4,     5,     6,     7,
+       8,     9,    10,    11,    12,     0,     0,     0,    13,    14,
+      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
+      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
+      35,    36,    37,    38,    39,     0,     0,     0,    75,     0,
+       0,    40,     0,    41,    42,     0,     0,     0,    43,   135,
+     136,   137,     0,     0,     0,     0,     0,     0,     0,     0,
+       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
+       0,     0,     0,     0,     0,     0,     0,     0,     0,   138,
+      76,     0,     0,    77
 };
 
-static const yytype_uint8 yycheck[] =
+static const yytype_int16 yycheck[] =
 {
-      35,     0,     1,     3,    54,     3,     5,     6,     7,     8,
-       9,    10,    11,    12,     3,    50,     1,    16,     0,    18,
-       5,     6,     7,     8,     9,    10,    11,    12,     3,    48,
-      49,    16,    31,    18,     3,    43,    94,    53,    88,    47,
-      39,     3,   101,     3,    44,   104,    31,    47,    46,    48,
-      49,    13,    14,    15,    39,    90,    44,    56,    47,    47,
-      50,    96,    52,    48,   122,    53,    93,    43,    95,    44,
-      43,    56,    47,     3,    93,     4,    95,    46,    53,    54,
-      55,    43,    44,   118,     4,    47,    46,     3,     4,    43,
-       3,    43,    43,   128,     3,     3,    53,    47,    43,   134,
-       3,     3,     3,    52,   139,     5,     6,     7,     8,     9,
-      10,    11,    12,     3,    52,     4,    16,    17,    18,    19,
-      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
-      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
-      40,    41,    42,     3,     2,     4,    45,    53,   118,    49,
-      83,    51,    52,    49,    52,   132,    56
+      36,     0,     1,     3,    55,     3,     5,     6,     7,     8,
+       9,    10,    11,    12,    13,    51,     3,     3,    17,    95,
+      19,    45,   102,     0,    48,   105,    54,    49,    50,     3,
+      54,    44,    44,    32,     3,    48,    44,    51,    89,    53,
+      94,    40,    96,     3,     4,    45,     3,   123,    48,    47,
+      49,    50,     4,     4,    44,    91,     3,     3,    57,     1,
+      47,    97,    48,     5,     6,     7,     8,     9,    10,    11,
+      12,    13,    94,    47,    96,    17,    45,    19,    44,    48,
+      44,     3,    54,   119,     3,    54,    55,    56,    44,    48,
+      32,     3,     3,   129,     3,    53,    46,     4,    40,   135,
+      53,     3,     2,     4,   140,    54,    84,    49,   119,    53,
+      50,    -1,   133,    -1,    -1,    57,     5,     6,     7,     8,
+       9,    10,    11,    12,    13,    -1,    -1,    -1,    17,    18,
+      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
+      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
+      39,    40,    41,    42,    43,    -1,    -1,    -1,     3,    -1,
+      -1,    50,    -1,    52,    53,    -1,    -1,    -1,    57,    14,
+      15,    16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
+      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
+      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,
+      45,    -1,    -1,    48
 };
 
 /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
    symbol of state STATE-NUM.  */
 static const yytype_uint8 yystos[] =
 {
-       0,    58,    59,     0,     5,     6,     7,     8,     9,    10,
-      11,    12,    16,    17,    18,    19,    20,    21,    22,    23,
+       0,    59,    60,     0,     5,     6,     7,     8,     9,    10,
+      11,    12,    13,    17,    18,    19,    20,    21,    22,    23,
       24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
-      34,    35,    36,    37,    38,    39,    40,    41,    42,    49,
-      51,    52,    56,    60,    61,    63,    66,    67,    65,    64,
-      53,    43,    43,    43,    47,    84,     3,    47,    82,     3,
-       4,     4,     3,    46,    43,     3,    43,     3,    46,     3,
-      46,    43,     3,     3,     3,    44,    47,    85,    87,    88,
-       1,    48,    61,    76,    77,    78,    86,    47,    62,    53,
-      68,    53,    74,    75,    85,    75,    71,    87,    53,    54,
-      55,    72,    73,    87,    72,    84,     3,    83,     3,     3,
-       3,    52,    52,    49,    77,    89,    79,    84,    69,    70,
-      87,    74,     4,    88,    87,    73,    45,    80,    81,    70,
-       4,    88,    50,    52,    13,    14,    15,    43,    87,    81,
-      87,     4,    53
+      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
+      50,    52,    53,    57,    61,    62,    64,    67,    68,    66,
+      65,    54,    44,    44,    44,    48,    85,     3,    48,    83,
+       3,     4,     4,     3,    47,    44,     3,    44,     3,    47,
+       3,    47,    44,     3,     3,     3,    45,    48,    86,    88,
+      89,     1,    49,    62,    77,    78,    79,    87,    48,    63,
+      54,    69,    54,    75,    76,    86,    76,    72,    88,    54,
+      55,    56,    73,    74,    88,    73,    85,     3,    84,     3,
+       3,     3,    53,    53,    50,    78,    90,    80,    85,    70,
+      71,    88,    75,     4,    89,    88,    74,    46,    81,    82,
+      71,     4,    89,    51,    53,    14,    15,    16,    44,    88,
+      82,    88,     4,    54
 };
 
 #define yyerrok		(yyerrstatus = 0)
@@ -1029,146 +1042,146 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
       case 3: /* "\"string\"" */
 
 /* Line 717 of yacc.c  */
-#line 180 "parse-gram.y"
+#line 181 "parse-gram.y"
 	{ fputs (quotearg_style (c_quoting_style, ((*yyvaluep).chars)), stderr); };
 
 /* Line 717 of yacc.c  */
-#line 1037 "parse-gram.c"
+#line 1050 "../../../src/parse-gram.c"
 	break;
       case 4: /* "\"integer\"" */
 
 /* Line 717 of yacc.c  */
-#line 191 "parse-gram.y"
+#line 192 "parse-gram.y"
 	{ fprintf (stderr, "%d", ((*yyvaluep).integer)); };
 
 /* Line 717 of yacc.c  */
-#line 1046 "parse-gram.c"
+#line 1059 "../../../src/parse-gram.c"
 	break;
-      case 43: /* "\"{...}\"" */
+      case 44: /* "\"{...}\"" */
 
 /* Line 717 of yacc.c  */
-#line 182 "parse-gram.y"
+#line 183 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", ((*yyvaluep).code)); };
 
 /* Line 717 of yacc.c  */
-#line 1055 "parse-gram.c"
+#line 1068 "../../../src/parse-gram.c"
 	break;
-      case 44: /* "\"char\"" */
+      case 45: /* "\"char\"" */
 
 /* Line 717 of yacc.c  */
-#line 174 "parse-gram.y"
+#line 175 "parse-gram.y"
 	{ fputs (char_name (((*yyvaluep).character)), stderr); };
 
 /* Line 717 of yacc.c  */
-#line 1064 "parse-gram.c"
+#line 1077 "../../../src/parse-gram.c"
 	break;
-      case 45: /* "\"epilogue\"" */
+      case 46: /* "\"epilogue\"" */
 
 /* Line 717 of yacc.c  */
-#line 182 "parse-gram.y"
+#line 183 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); };
 
 /* Line 717 of yacc.c  */
-#line 1073 "parse-gram.c"
+#line 1086 "../../../src/parse-gram.c"
 	break;
-      case 47: /* "\"identifier\"" */
+      case 48: /* "\"identifier\"" */
 
 /* Line 717 of yacc.c  */
-#line 187 "parse-gram.y"
+#line 188 "parse-gram.y"
 	{ fputs (((*yyvaluep).uniqstr), stderr); };
 
 /* Line 717 of yacc.c  */
-#line 1082 "parse-gram.c"
+#line 1095 "../../../src/parse-gram.c"
 	break;
-      case 48: /* "\"identifier:\"" */
+      case 49: /* "\"identifier:\"" */
 
 /* Line 717 of yacc.c  */
-#line 188 "parse-gram.y"
+#line 189 "parse-gram.y"
 	{ fprintf (stderr, "%s:", ((*yyvaluep).uniqstr)); };
 
 /* Line 717 of yacc.c  */
-#line 1091 "parse-gram.c"
+#line 1104 "../../../src/parse-gram.c"
 	break;
-      case 51: /* "\"%{...%}\"" */
+      case 52: /* "\"%{...%}\"" */
 
 /* Line 717 of yacc.c  */
-#line 182 "parse-gram.y"
+#line 183 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); };
 
 /* Line 717 of yacc.c  */
-#line 1100 "parse-gram.c"
+#line 1113 "../../../src/parse-gram.c"
 	break;
-      case 53: /* "\"type\"" */
+      case 54: /* "\"type\"" */
 
 /* Line 717 of yacc.c  */
-#line 186 "parse-gram.y"
+#line 187 "parse-gram.y"
 	{ fprintf (stderr, "<%s>", ((*yyvaluep).uniqstr)); };
 
 /* Line 717 of yacc.c  */
-#line 1109 "parse-gram.c"
+#line 1122 "../../../src/parse-gram.c"
 	break;
-      case 82: /* "variable" */
+      case 83: /* "variable" */
 
 /* Line 717 of yacc.c  */
-#line 187 "parse-gram.y"
+#line 188 "parse-gram.y"
 	{ fputs (((*yyvaluep).uniqstr), stderr); };
 
 /* Line 717 of yacc.c  */
-#line 1118 "parse-gram.c"
+#line 1131 "../../../src/parse-gram.c"
 	break;
-      case 83: /* "content.opt" */
+      case 84: /* "content.opt" */
 
 /* Line 717 of yacc.c  */
-#line 182 "parse-gram.y"
+#line 183 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); };
 
 /* Line 717 of yacc.c  */
-#line 1127 "parse-gram.c"
+#line 1140 "../../../src/parse-gram.c"
 	break;
-      case 84: /* "braceless" */
+      case 85: /* "braceless" */
 
 /* Line 717 of yacc.c  */
-#line 182 "parse-gram.y"
+#line 183 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); };
 
 /* Line 717 of yacc.c  */
-#line 1136 "parse-gram.c"
+#line 1149 "../../../src/parse-gram.c"
 	break;
-      case 85: /* "id" */
+      case 86: /* "id" */
 
 /* Line 717 of yacc.c  */
-#line 194 "parse-gram.y"
+#line 195 "parse-gram.y"
 	{ fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); };
 
 /* Line 717 of yacc.c  */
-#line 1145 "parse-gram.c"
+#line 1158 "../../../src/parse-gram.c"
 	break;
-      case 86: /* "id_colon" */
+      case 87: /* "id_colon" */
 
 /* Line 717 of yacc.c  */
-#line 195 "parse-gram.y"
+#line 196 "parse-gram.y"
 	{ fprintf (stderr, "%s:", ((*yyvaluep).symbol)->tag); };
 
 /* Line 717 of yacc.c  */
-#line 1154 "parse-gram.c"
+#line 1167 "../../../src/parse-gram.c"
 	break;
-      case 87: /* "symbol" */
+      case 88: /* "symbol" */
 
 /* Line 717 of yacc.c  */
-#line 194 "parse-gram.y"
+#line 195 "parse-gram.y"
 	{ fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); };
 
 /* Line 717 of yacc.c  */
-#line 1163 "parse-gram.c"
+#line 1176 "../../../src/parse-gram.c"
 	break;
-      case 88: /* "string_as_id" */
+      case 89: /* "string_as_id" */
 
 /* Line 717 of yacc.c  */
-#line 194 "parse-gram.y"
+#line 195 "parse-gram.y"
 	{ fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); };
 
 /* Line 717 of yacc.c  */
-#line 1172 "parse-gram.c"
+#line 1185 "../../../src/parse-gram.c"
 	break;
       default:
 	break;
@@ -1687,7 +1700,7 @@ YYLTYPE yylloc;
 
 /* User initialization code.  */
 
-/* Line 1250 of yacc.c  */
+/* Line 1244 of yacc.c  */
 #line 84 "parse-gram.y"
 {
   /* Bison's grammar can initial empty locations, hence a default
@@ -1696,8 +1709,8 @@ YYLTYPE yylloc;
   boundary_set (&yylloc.end, current_file, 1, 1);
 }
 
-/* Line 1250 of yacc.c  */
-#line 1701 "parse-gram.c"
+/* Line 1244 of yacc.c  */
+#line 1714 "../../../src/parse-gram.c"
   yylsp[0] = yylloc;
 
   goto yysetstate;
@@ -1885,7 +1898,7 @@ yyreduce:
         case 6:
 
 /* Line 1457 of yacc.c  */
-#line 218 "parse-gram.y"
+#line 219 "parse-gram.y"
     {
       code_props plain_code;
       code_props_plain_init (&plain_code, (yyvsp[(1) - (1)].chars), (yylsp[(1) - (1)]));
@@ -1897,121 +1910,121 @@ yyreduce:
     }
 
 /* Line 1457 of yacc.c  */
-#line 1901 "parse-gram.c"
+#line 1914 "../../../src/parse-gram.c"
     break;
 
   case 7:
 
 /* Line 1457 of yacc.c  */
-#line 227 "parse-gram.y"
+#line 228 "parse-gram.y"
     { debug_flag = true; }
 
 /* Line 1457 of yacc.c  */
-#line 1911 "parse-gram.c"
+#line 1924 "../../../src/parse-gram.c"
     break;
 
   case 8:
 
 /* Line 1457 of yacc.c  */
-#line 229 "parse-gram.y"
+#line 230 "parse-gram.y"
     {
       muscle_percent_define_insert ((yyvsp[(2) - (3)].uniqstr), (yylsp[(2) - (3)]), (yyvsp[(3) - (3)].chars));
     }
 
 /* Line 1457 of yacc.c  */
-#line 1923 "parse-gram.c"
+#line 1936 "../../../src/parse-gram.c"
     break;
 
   case 9:
 
 /* Line 1457 of yacc.c  */
-#line 232 "parse-gram.y"
+#line 233 "parse-gram.y"
     { defines_flag = true; }
 
 /* Line 1457 of yacc.c  */
-#line 1933 "parse-gram.c"
+#line 1946 "../../../src/parse-gram.c"
     break;
 
   case 10:
 
 /* Line 1457 of yacc.c  */
-#line 234 "parse-gram.y"
+#line 235 "parse-gram.y"
     {
       defines_flag = true;
       spec_defines_file = xstrdup ((yyvsp[(2) - (2)].chars));
     }
 
 /* Line 1457 of yacc.c  */
-#line 1946 "parse-gram.c"
+#line 1959 "../../../src/parse-gram.c"
     break;
 
   case 11:
 
 /* Line 1457 of yacc.c  */
-#line 238 "parse-gram.y"
+#line 239 "parse-gram.y"
     { error_verbose = true; }
 
 /* Line 1457 of yacc.c  */
-#line 1956 "parse-gram.c"
+#line 1969 "../../../src/parse-gram.c"
     break;
 
   case 12:
 
 /* Line 1457 of yacc.c  */
-#line 239 "parse-gram.y"
+#line 240 "parse-gram.y"
     { expected_sr_conflicts = (yyvsp[(2) - (2)].integer); }
 
 /* Line 1457 of yacc.c  */
-#line 1966 "parse-gram.c"
+#line 1979 "../../../src/parse-gram.c"
     break;
 
   case 13:
 
 /* Line 1457 of yacc.c  */
-#line 240 "parse-gram.y"
+#line 241 "parse-gram.y"
     { expected_rr_conflicts = (yyvsp[(2) - (2)].integer); }
 
 /* Line 1457 of yacc.c  */
-#line 1976 "parse-gram.c"
+#line 1989 "../../../src/parse-gram.c"
     break;
 
   case 14:
 
 /* Line 1457 of yacc.c  */
-#line 241 "parse-gram.y"
+#line 242 "parse-gram.y"
     { spec_file_prefix = (yyvsp[(2) - (2)].chars); }
 
 /* Line 1457 of yacc.c  */
-#line 1986 "parse-gram.c"
+#line 1999 "../../../src/parse-gram.c"
     break;
 
   case 15:
 
 /* Line 1457 of yacc.c  */
-#line 242 "parse-gram.y"
+#line 243 "parse-gram.y"
     { spec_file_prefix = (yyvsp[(3) - (3)].chars); }
 
 /* Line 1457 of yacc.c  */
-#line 1996 "parse-gram.c"
+#line 2009 "../../../src/parse-gram.c"
     break;
 
   case 16:
 
 /* Line 1457 of yacc.c  */
-#line 244 "parse-gram.y"
+#line 245 "parse-gram.y"
     {
       nondeterministic_parser = true;
       glr_parser = true;
     }
 
 /* Line 1457 of yacc.c  */
-#line 2009 "parse-gram.c"
+#line 2022 "../../../src/parse-gram.c"
     break;
 
   case 17:
 
 /* Line 1457 of yacc.c  */
-#line 249 "parse-gram.y"
+#line 250 "parse-gram.y"
     {
       code_props action;
       code_props_symbol_action_init (&action, (yyvsp[(2) - (2)].code), (yylsp[(2) - (2)]));
@@ -2022,113 +2035,113 @@ yyreduce:
     }
 
 /* Line 1457 of yacc.c  */
-#line 2026 "parse-gram.c"
+#line 2039 "../../../src/parse-gram.c"
     break;
 
   case 18:
 
 /* Line 1457 of yacc.c  */
-#line 257 "parse-gram.y"
+#line 258 "parse-gram.y"
     { language_argmatch ((yyvsp[(2) - (2)].chars), grammar_prio, (yylsp[(1) - (2)])); }
 
 /* Line 1457 of yacc.c  */
-#line 2036 "parse-gram.c"
+#line 2049 "../../../src/parse-gram.c"
     break;
 
   case 19:
 
 /* Line 1457 of yacc.c  */
-#line 258 "parse-gram.y"
+#line 259 "parse-gram.y"
     { add_param ("lex_param", (yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
 
 /* Line 1457 of yacc.c  */
-#line 2046 "parse-gram.c"
+#line 2059 "../../../src/parse-gram.c"
     break;
 
   case 20:
 
 /* Line 1457 of yacc.c  */
-#line 259 "parse-gram.y"
+#line 260 "parse-gram.y"
     { locations_flag = true; }
 
 /* Line 1457 of yacc.c  */
-#line 2056 "parse-gram.c"
+#line 2069 "../../../src/parse-gram.c"
     break;
 
   case 21:
 
 /* Line 1457 of yacc.c  */
-#line 260 "parse-gram.y"
+#line 261 "parse-gram.y"
     { spec_name_prefix = (yyvsp[(2) - (2)].chars); }
 
 /* Line 1457 of yacc.c  */
-#line 2066 "parse-gram.c"
+#line 2079 "../../../src/parse-gram.c"
     break;
 
   case 22:
 
 /* Line 1457 of yacc.c  */
-#line 261 "parse-gram.y"
+#line 262 "parse-gram.y"
     { spec_name_prefix = (yyvsp[(3) - (3)].chars); }
 
 /* Line 1457 of yacc.c  */
-#line 2076 "parse-gram.c"
+#line 2089 "../../../src/parse-gram.c"
     break;
 
   case 23:
 
 /* Line 1457 of yacc.c  */
-#line 262 "parse-gram.y"
+#line 263 "parse-gram.y"
     { no_lines_flag = true; }
 
 /* Line 1457 of yacc.c  */
-#line 2086 "parse-gram.c"
+#line 2099 "../../../src/parse-gram.c"
     break;
 
   case 24:
 
 /* Line 1457 of yacc.c  */
-#line 263 "parse-gram.y"
+#line 264 "parse-gram.y"
     { nondeterministic_parser = true; }
 
 /* Line 1457 of yacc.c  */
-#line 2096 "parse-gram.c"
+#line 2109 "../../../src/parse-gram.c"
     break;
 
   case 25:
 
 /* Line 1457 of yacc.c  */
-#line 264 "parse-gram.y"
+#line 265 "parse-gram.y"
     { spec_outfile = (yyvsp[(2) - (2)].chars); }
 
 /* Line 1457 of yacc.c  */
-#line 2106 "parse-gram.c"
+#line 2119 "../../../src/parse-gram.c"
     break;
 
   case 26:
 
 /* Line 1457 of yacc.c  */
-#line 265 "parse-gram.y"
+#line 266 "parse-gram.y"
     { spec_outfile = (yyvsp[(3) - (3)].chars); }
 
 /* Line 1457 of yacc.c  */
-#line 2116 "parse-gram.c"
+#line 2129 "../../../src/parse-gram.c"
     break;
 
   case 27:
 
 /* Line 1457 of yacc.c  */
-#line 266 "parse-gram.y"
+#line 267 "parse-gram.y"
     { add_param ("parse_param", (yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
 
 /* Line 1457 of yacc.c  */
-#line 2126 "parse-gram.c"
+#line 2139 "../../../src/parse-gram.c"
     break;
 
   case 28:
 
 /* Line 1457 of yacc.c  */
-#line 268 "parse-gram.y"
+#line 269 "parse-gram.y"
     {
       /* %pure-parser is deprecated in favor of `%define api.pure', so use
          `%define api.pure' in a backward-compatible manner here.  First, don't
@@ -2143,23 +2156,23 @@ yyreduce:
     }
 
 /* Line 1457 of yacc.c  */
-#line 2147 "parse-gram.c"
+#line 2160 "../../../src/parse-gram.c"
     break;
 
   case 29:
 
 /* Line 1457 of yacc.c  */
-#line 280 "parse-gram.y"
+#line 281 "parse-gram.y"
     { version_check (&(yylsp[(2) - (2)]), (yyvsp[(2) - (2)].chars)); }
 
 /* Line 1457 of yacc.c  */
-#line 2157 "parse-gram.c"
+#line 2170 "../../../src/parse-gram.c"
     break;
 
   case 30:
 
 /* Line 1457 of yacc.c  */
-#line 282 "parse-gram.y"
+#line 283 "parse-gram.y"
     {
       char const *skeleton_user = (yyvsp[(2) - (2)].chars);
       if (strchr (skeleton_user, '/'))
@@ -2185,55 +2198,55 @@ yyreduce:
     }
 
 /* Line 1457 of yacc.c  */
-#line 2189 "parse-gram.c"
+#line 2202 "../../../src/parse-gram.c"
     break;
 
   case 31:
 
 /* Line 1457 of yacc.c  */
-#line 305 "parse-gram.y"
+#line 306 "parse-gram.y"
     { token_table_flag = true; }
 
 /* Line 1457 of yacc.c  */
-#line 2199 "parse-gram.c"
+#line 2212 "../../../src/parse-gram.c"
     break;
 
   case 32:
 
 /* Line 1457 of yacc.c  */
-#line 306 "parse-gram.y"
+#line 307 "parse-gram.y"
     { report_flag |= report_states; }
 
 /* Line 1457 of yacc.c  */
-#line 2209 "parse-gram.c"
+#line 2222 "../../../src/parse-gram.c"
     break;
 
   case 33:
 
 /* Line 1457 of yacc.c  */
-#line 307 "parse-gram.y"
+#line 308 "parse-gram.y"
     { yacc_flag = true; }
 
 /* Line 1457 of yacc.c  */
-#line 2219 "parse-gram.c"
+#line 2232 "../../../src/parse-gram.c"
     break;
 
   case 37:
 
 /* Line 1457 of yacc.c  */
-#line 315 "parse-gram.y"
+#line 316 "parse-gram.y"
     {
       grammar_start_symbol_set ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]));
     }
 
 /* Line 1457 of yacc.c  */
-#line 2231 "parse-gram.c"
+#line 2244 "../../../src/parse-gram.c"
     break;
 
   case 38:
 
 /* Line 1457 of yacc.c  */
-#line 319 "parse-gram.y"
+#line 320 "parse-gram.y"
     {
       symbol_list *list;
       for (list = (yyvsp[(3) - (3)].list); list; list = list->next)
@@ -2242,13 +2255,13 @@ yyreduce:
     }
 
 /* Line 1457 of yacc.c  */
-#line 2246 "parse-gram.c"
+#line 2259 "../../../src/parse-gram.c"
     break;
 
   case 39:
 
 /* Line 1457 of yacc.c  */
-#line 326 "parse-gram.y"
+#line 327 "parse-gram.y"
     {
       symbol_list *list;
       for (list = (yyvsp[(3) - (3)].list); list; list = list->next)
@@ -2257,37 +2270,37 @@ yyreduce:
     }
 
 /* Line 1457 of yacc.c  */
-#line 2261 "parse-gram.c"
+#line 2274 "../../../src/parse-gram.c"
     break;
 
   case 40:
 
 /* Line 1457 of yacc.c  */
-#line 333 "parse-gram.y"
+#line 334 "parse-gram.y"
     {
       default_prec = true;
     }
 
 /* Line 1457 of yacc.c  */
-#line 2273 "parse-gram.c"
+#line 2286 "../../../src/parse-gram.c"
     break;
 
   case 41:
 
 /* Line 1457 of yacc.c  */
-#line 337 "parse-gram.y"
+#line 338 "parse-gram.y"
     {
       default_prec = false;
     }
 
 /* Line 1457 of yacc.c  */
-#line 2285 "parse-gram.c"
+#line 2298 "../../../src/parse-gram.c"
     break;
 
   case 42:
 
 /* Line 1457 of yacc.c  */
-#line 341 "parse-gram.y"
+#line 342 "parse-gram.y"
     {
       /* Do not invoke muscle_percent_code_grow here since it invokes
          muscle_user_name_list_grow.  */
@@ -2296,46 +2309,46 @@ yyreduce:
     }
 
 /* Line 1457 of yacc.c  */
-#line 2300 "parse-gram.c"
+#line 2313 "../../../src/parse-gram.c"
     break;
 
   case 43:
 
 /* Line 1457 of yacc.c  */
-#line 348 "parse-gram.y"
+#line 349 "parse-gram.y"
     {
       muscle_percent_code_grow ((yyvsp[(2) - (3)].uniqstr), (yylsp[(2) - (3)]), (yyvsp[(3) - (3)].chars), (yylsp[(3) - (3)]));
       code_scanner_last_string_free ();
     }
 
 /* Line 1457 of yacc.c  */
-#line 2313 "parse-gram.c"
+#line 2326 "../../../src/parse-gram.c"
     break;
 
   case 44:
 
 /* Line 1457 of yacc.c  */
-#line 362 "parse-gram.y"
+#line 363 "parse-gram.y"
     {}
 
 /* Line 1457 of yacc.c  */
-#line 2323 "parse-gram.c"
+#line 2336 "../../../src/parse-gram.c"
     break;
 
   case 45:
 
 /* Line 1457 of yacc.c  */
-#line 363 "parse-gram.y"
+#line 364 "parse-gram.y"
     { muscle_code_grow ("union_name", (yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
 
 /* Line 1457 of yacc.c  */
-#line 2333 "parse-gram.c"
+#line 2346 "../../../src/parse-gram.c"
     break;
 
   case 46:
 
 /* Line 1457 of yacc.c  */
-#line 368 "parse-gram.y"
+#line 369 "parse-gram.y"
     {
       union_seen = true;
       muscle_code_grow ("stype", (yyvsp[(3) - (3)].chars), (yylsp[(3) - (3)]));
@@ -2343,59 +2356,59 @@ yyreduce:
     }
 
 /* Line 1457 of yacc.c  */
-#line 2347 "parse-gram.c"
+#line 2360 "../../../src/parse-gram.c"
     break;
 
   case 47:
 
 /* Line 1457 of yacc.c  */
-#line 379 "parse-gram.y"
+#line 380 "parse-gram.y"
     { current_class = nterm_sym; }
 
 /* Line 1457 of yacc.c  */
-#line 2357 "parse-gram.c"
+#line 2370 "../../../src/parse-gram.c"
     break;
 
   case 48:
 
 /* Line 1457 of yacc.c  */
-#line 380 "parse-gram.y"
+#line 381 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
 
 /* Line 1457 of yacc.c  */
-#line 2370 "parse-gram.c"
+#line 2383 "../../../src/parse-gram.c"
     break;
 
   case 49:
 
 /* Line 1457 of yacc.c  */
-#line 384 "parse-gram.y"
+#line 385 "parse-gram.y"
     { current_class = token_sym; }
 
 /* Line 1457 of yacc.c  */
-#line 2380 "parse-gram.c"
+#line 2393 "../../../src/parse-gram.c"
     break;
 
   case 50:
 
 /* Line 1457 of yacc.c  */
-#line 385 "parse-gram.y"
+#line 386 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
 
 /* Line 1457 of yacc.c  */
-#line 2393 "parse-gram.c"
+#line 2406 "../../../src/parse-gram.c"
     break;
 
   case 51:
 
 /* Line 1457 of yacc.c  */
-#line 390 "parse-gram.y"
+#line 391 "parse-gram.y"
     {
       symbol_list *list;
       tag_seen = true;
@@ -2405,13 +2418,13 @@ yyreduce:
     }
 
 /* Line 1457 of yacc.c  */
-#line 2409 "parse-gram.c"
+#line 2422 "../../../src/parse-gram.c"
     break;
 
   case 52:
 
 /* Line 1457 of yacc.c  */
-#line 401 "parse-gram.y"
+#line 402 "parse-gram.y"
     {
       symbol_list *list;
       ++current_prec;
@@ -2425,209 +2438,219 @@ yyreduce:
     }
 
 /* Line 1457 of yacc.c  */
-#line 2429 "parse-gram.c"
+#line 2442 "../../../src/parse-gram.c"
     break;
 
   case 53:
 
 /* Line 1457 of yacc.c  */
-#line 415 "parse-gram.y"
+#line 416 "parse-gram.y"
     { (yyval.assoc) = left_assoc; }
 
 /* Line 1457 of yacc.c  */
-#line 2439 "parse-gram.c"
+#line 2452 "../../../src/parse-gram.c"
     break;
 
   case 54:
 
 /* Line 1457 of yacc.c  */
-#line 416 "parse-gram.y"
+#line 417 "parse-gram.y"
     { (yyval.assoc) = right_assoc; }
 
 /* Line 1457 of yacc.c  */
-#line 2449 "parse-gram.c"
+#line 2462 "../../../src/parse-gram.c"
     break;
 
   case 55:
 
 /* Line 1457 of yacc.c  */
-#line 417 "parse-gram.y"
+#line 418 "parse-gram.y"
     { (yyval.assoc) = non_assoc; }
 
 /* Line 1457 of yacc.c  */
-#line 2459 "parse-gram.c"
+#line 2472 "../../../src/parse-gram.c"
     break;
 
   case 56:
 
 /* Line 1457 of yacc.c  */
-#line 421 "parse-gram.y"
-    { current_type = NULL; }
+#line 419 "parse-gram.y"
+    { (yyval.assoc) = precedence_assoc; }
 
 /* Line 1457 of yacc.c  */
-#line 2469 "parse-gram.c"
+#line 2482 "../../../src/parse-gram.c"
     break;
 
   case 57:
 
 /* Line 1457 of yacc.c  */
-#line 422 "parse-gram.y"
-    { current_type = (yyvsp[(1) - (1)].uniqstr); tag_seen = true; }
+#line 423 "parse-gram.y"
+    { current_type = NULL; }
 
 /* Line 1457 of yacc.c  */
-#line 2479 "parse-gram.c"
+#line 2492 "../../../src/parse-gram.c"
     break;
 
   case 58:
 
 /* Line 1457 of yacc.c  */
-#line 428 "parse-gram.y"
-    { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
+#line 424 "parse-gram.y"
+    { current_type = (yyvsp[(1) - (1)].uniqstr); tag_seen = true; }
 
 /* Line 1457 of yacc.c  */
-#line 2489 "parse-gram.c"
+#line 2502 "../../../src/parse-gram.c"
     break;
 
   case 59:
 
 /* Line 1457 of yacc.c  */
 #line 430 "parse-gram.y"
-    { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), symbol_list_sym_new ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]))); }
+    { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
 
 /* Line 1457 of yacc.c  */
-#line 2499 "parse-gram.c"
+#line 2512 "../../../src/parse-gram.c"
     break;
 
   case 60:
 
 /* Line 1457 of yacc.c  */
-#line 434 "parse-gram.y"
-    { (yyval.symbol) = (yyvsp[(1) - (1)].symbol); }
+#line 432 "parse-gram.y"
+    { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), symbol_list_sym_new ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]))); }
 
 /* Line 1457 of yacc.c  */
-#line 2509 "parse-gram.c"
+#line 2522 "../../../src/parse-gram.c"
     break;
 
   case 61:
 
 /* Line 1457 of yacc.c  */
-#line 435 "parse-gram.y"
-    { (yyval.symbol) = (yyvsp[(1) - (2)].symbol); symbol_user_token_number_set ((yyvsp[(1) - (2)].symbol), (yyvsp[(2) - (2)].integer), (yylsp[(2) - (2)])); }
+#line 436 "parse-gram.y"
+    { (yyval.symbol) = (yyvsp[(1) - (1)].symbol); }
 
 /* Line 1457 of yacc.c  */
-#line 2519 "parse-gram.c"
+#line 2532 "../../../src/parse-gram.c"
     break;
 
   case 62:
 
 /* Line 1457 of yacc.c  */
-#line 441 "parse-gram.y"
-    { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
+#line 437 "parse-gram.y"
+    { (yyval.symbol) = (yyvsp[(1) - (2)].symbol); symbol_user_token_number_set ((yyvsp[(1) - (2)].symbol), (yyvsp[(2) - (2)].integer), (yylsp[(2) - (2)])); }
 
 /* Line 1457 of yacc.c  */
-#line 2529 "parse-gram.c"
+#line 2542 "../../../src/parse-gram.c"
     break;
 
   case 63:
 
 /* Line 1457 of yacc.c  */
 #line 443 "parse-gram.y"
-    { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), symbol_list_sym_new ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]))); }
+    { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
 
 /* Line 1457 of yacc.c  */
-#line 2539 "parse-gram.c"
+#line 2552 "../../../src/parse-gram.c"
     break;
 
   case 64:
 
 /* Line 1457 of yacc.c  */
-#line 447 "parse-gram.y"
-    { (yyval.list) = (yyvsp[(1) - (1)].list); }
+#line 445 "parse-gram.y"
+    { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), symbol_list_sym_new ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]))); }
 
 /* Line 1457 of yacc.c  */
-#line 2549 "parse-gram.c"
+#line 2562 "../../../src/parse-gram.c"
     break;
 
   case 65:
 
 /* Line 1457 of yacc.c  */
-#line 448 "parse-gram.y"
-    { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), (yyvsp[(2) - (2)].list)); }
+#line 449 "parse-gram.y"
+    { (yyval.list) = (yyvsp[(1) - (1)].list); }
 
 /* Line 1457 of yacc.c  */
-#line 2559 "parse-gram.c"
+#line 2572 "../../../src/parse-gram.c"
     break;
 
   case 66:
 
 /* Line 1457 of yacc.c  */
-#line 452 "parse-gram.y"
-    { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
+#line 450 "parse-gram.y"
+    { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), (yyvsp[(2) - (2)].list)); }
 
 /* Line 1457 of yacc.c  */
-#line 2569 "parse-gram.c"
+#line 2582 "../../../src/parse-gram.c"
     break;
 
   case 67:
 
 /* Line 1457 of yacc.c  */
-#line 453 "parse-gram.y"
-    { (yyval.list) = symbol_list_type_new ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
+#line 454 "parse-gram.y"
+    { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
 
 /* Line 1457 of yacc.c  */
-#line 2579 "parse-gram.c"
+#line 2592 "../../../src/parse-gram.c"
     break;
 
   case 68:
 
 /* Line 1457 of yacc.c  */
-#line 454 "parse-gram.y"
-    { (yyval.list) = symbol_list_default_tagged_new ((yylsp[(1) - (1)])); }
+#line 455 "parse-gram.y"
+    { (yyval.list) = symbol_list_type_new ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
 
 /* Line 1457 of yacc.c  */
-#line 2589 "parse-gram.c"
+#line 2602 "../../../src/parse-gram.c"
     break;
 
   case 69:
 
 /* Line 1457 of yacc.c  */
-#line 455 "parse-gram.y"
-    { (yyval.list) = symbol_list_default_tagless_new ((yylsp[(1) - (1)])); }
+#line 456 "parse-gram.y"
+    { (yyval.list) = symbol_list_default_tagged_new ((yylsp[(1) - (1)])); }
 
 /* Line 1457 of yacc.c  */
-#line 2599 "parse-gram.c"
+#line 2612 "../../../src/parse-gram.c"
     break;
 
   case 70:
 
 /* Line 1457 of yacc.c  */
-#line 461 "parse-gram.y"
+#line 457 "parse-gram.y"
+    { (yyval.list) = symbol_list_default_tagless_new ((yylsp[(1) - (1)])); }
+
+/* Line 1457 of yacc.c  */
+#line 2622 "../../../src/parse-gram.c"
+    break;
+
+  case 71:
+
+/* Line 1457 of yacc.c  */
+#line 463 "parse-gram.y"
     {
        current_type = (yyvsp[(1) - (1)].uniqstr);
        tag_seen = true;
      }
 
 /* Line 1457 of yacc.c  */
-#line 2612 "parse-gram.c"
+#line 2635 "../../../src/parse-gram.c"
     break;
 
-  case 71:
+  case 72:
 
 /* Line 1457 of yacc.c  */
-#line 466 "parse-gram.y"
+#line 468 "parse-gram.y"
     {
        symbol_class_set ((yyvsp[(1) - (1)].symbol), current_class, (yylsp[(1) - (1)]), true);
        symbol_type_set ((yyvsp[(1) - (1)].symbol), current_type, (yylsp[(1) - (1)]));
      }
 
 /* Line 1457 of yacc.c  */
-#line 2625 "parse-gram.c"
+#line 2648 "../../../src/parse-gram.c"
     break;
 
-  case 72:
+  case 73:
 
 /* Line 1457 of yacc.c  */
-#line 471 "parse-gram.y"
+#line 473 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
       symbol_type_set ((yyvsp[(1) - (2)].symbol), current_type, (yylsp[(1) - (2)]));
@@ -2635,13 +2658,13 @@ yyreduce:
     }
 
 /* Line 1457 of yacc.c  */
-#line 2639 "parse-gram.c"
+#line 2662 "../../../src/parse-gram.c"
     break;
 
-  case 73:
+  case 74:
 
 /* Line 1457 of yacc.c  */
-#line 477 "parse-gram.y"
+#line 479 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
       symbol_type_set ((yyvsp[(1) - (2)].symbol), current_type, (yylsp[(1) - (2)]));
@@ -2649,13 +2672,13 @@ yyreduce:
     }
 
 /* Line 1457 of yacc.c  */
-#line 2653 "parse-gram.c"
+#line 2676 "../../../src/parse-gram.c"
     break;
 
-  case 74:
+  case 75:
 
 /* Line 1457 of yacc.c  */
-#line 483 "parse-gram.y"
+#line 485 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (3)].symbol), current_class, (yylsp[(1) - (3)]), true);
       symbol_type_set ((yyvsp[(1) - (3)].symbol), current_type, (yylsp[(1) - (3)]));
@@ -2664,137 +2687,137 @@ yyreduce:
     }
 
 /* Line 1457 of yacc.c  */
-#line 2668 "parse-gram.c"
+#line 2691 "../../../src/parse-gram.c"
     break;
 
-  case 81:
+  case 82:
 
 /* Line 1457 of yacc.c  */
-#line 513 "parse-gram.y"
+#line 515 "parse-gram.y"
     {
       yyerrok;
     }
 
 /* Line 1457 of yacc.c  */
-#line 2680 "parse-gram.c"
+#line 2703 "../../../src/parse-gram.c"
     break;
 
-  case 82:
+  case 83:
 
 /* Line 1457 of yacc.c  */
-#line 519 "parse-gram.y"
+#line 521 "parse-gram.y"
     { current_lhs = (yyvsp[(1) - (1)].symbol); current_lhs_location = (yylsp[(1) - (1)]); }
 
 /* Line 1457 of yacc.c  */
-#line 2690 "parse-gram.c"
+#line 2713 "../../../src/parse-gram.c"
     break;
 
-  case 84:
+  case 85:
 
 /* Line 1457 of yacc.c  */
-#line 523 "parse-gram.y"
+#line 525 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(1) - (1)])); }
 
 /* Line 1457 of yacc.c  */
-#line 2700 "parse-gram.c"
+#line 2723 "../../../src/parse-gram.c"
     break;
 
-  case 85:
+  case 86:
 
 /* Line 1457 of yacc.c  */
-#line 524 "parse-gram.y"
+#line 526 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(3) - (3)])); }
 
 /* Line 1457 of yacc.c  */
-#line 2710 "parse-gram.c"
+#line 2733 "../../../src/parse-gram.c"
     break;
 
-  case 87:
+  case 88:
 
 /* Line 1457 of yacc.c  */
-#line 530 "parse-gram.y"
+#line 532 "parse-gram.y"
     { grammar_current_rule_begin (current_lhs, current_lhs_location); }
 
 /* Line 1457 of yacc.c  */
-#line 2720 "parse-gram.c"
+#line 2743 "../../../src/parse-gram.c"
     break;
 
-  case 88:
+  case 89:
 
 /* Line 1457 of yacc.c  */
-#line 532 "parse-gram.y"
+#line 534 "parse-gram.y"
     { grammar_current_rule_symbol_append ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)])); }
 
 /* Line 1457 of yacc.c  */
-#line 2730 "parse-gram.c"
+#line 2753 "../../../src/parse-gram.c"
     break;
 
-  case 89:
+  case 90:
 
 /* Line 1457 of yacc.c  */
-#line 534 "parse-gram.y"
+#line 536 "parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
 
 /* Line 1457 of yacc.c  */
-#line 2740 "parse-gram.c"
+#line 2763 "../../../src/parse-gram.c"
     break;
 
-  case 90:
+  case 91:
 
 /* Line 1457 of yacc.c  */
-#line 536 "parse-gram.y"
+#line 538 "parse-gram.y"
     { grammar_current_rule_prec_set ((yyvsp[(3) - (3)].symbol), (yylsp[(3) - (3)])); }
 
 /* Line 1457 of yacc.c  */
-#line 2750 "parse-gram.c"
+#line 2773 "../../../src/parse-gram.c"
     break;
 
-  case 91:
+  case 92:
 
 /* Line 1457 of yacc.c  */
-#line 538 "parse-gram.y"
+#line 540 "parse-gram.y"
     { grammar_current_rule_dprec_set ((yyvsp[(3) - (3)].integer), (yylsp[(3) - (3)])); }
 
 /* Line 1457 of yacc.c  */
-#line 2760 "parse-gram.c"
+#line 2783 "../../../src/parse-gram.c"
     break;
 
-  case 92:
+  case 93:
 
 /* Line 1457 of yacc.c  */
-#line 540 "parse-gram.y"
+#line 542 "parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[(3) - (3)].uniqstr), (yylsp[(3) - (3)])); }
 
 /* Line 1457 of yacc.c  */
-#line 2770 "parse-gram.c"
+#line 2793 "../../../src/parse-gram.c"
     break;
 
-  case 94:
+  case 95:
 
 /* Line 1457 of yacc.c  */
-#line 550 "parse-gram.y"
+#line 552 "parse-gram.y"
     { (yyval.uniqstr) = uniqstr_new ((yyvsp[(1) - (1)].chars)); }
 
 /* Line 1457 of yacc.c  */
-#line 2780 "parse-gram.c"
+#line 2803 "../../../src/parse-gram.c"
     break;
 
-  case 95:
+  case 96:
 
 /* Line 1457 of yacc.c  */
-#line 556 "parse-gram.y"
+#line 558 "parse-gram.y"
     {
       (yyval.chars) = "";
     }
 
 /* Line 1457 of yacc.c  */
-#line 2792 "parse-gram.c"
+#line 2815 "../../../src/parse-gram.c"
     break;
 
-  case 97:
+  case 98:
 
 /* Line 1457 of yacc.c  */
-#line 569 "parse-gram.y"
+#line 571 "parse-gram.y"
     {
       code_props plain_code;
       (yyvsp[(1) - (1)].code)[strlen ((yyvsp[(1) - (1)].code)) - 1] = '\n';
@@ -2805,23 +2828,23 @@ yyreduce:
     }
 
 /* Line 1457 of yacc.c  */
-#line 2809 "parse-gram.c"
+#line 2832 "../../../src/parse-gram.c"
     break;
 
-  case 98:
+  case 99:
 
 /* Line 1457 of yacc.c  */
-#line 589 "parse-gram.y"
+#line 591 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
 
 /* Line 1457 of yacc.c  */
-#line 2819 "parse-gram.c"
+#line 2842 "../../../src/parse-gram.c"
     break;
 
-  case 99:
+  case 100:
 
 /* Line 1457 of yacc.c  */
-#line 591 "parse-gram.y"
+#line 593 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[(1) - (1)].character)), (yylsp[(1) - (1)]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[(1) - (1)]), false);
@@ -2829,36 +2852,36 @@ yyreduce:
     }
 
 /* Line 1457 of yacc.c  */
-#line 2833 "parse-gram.c"
+#line 2856 "../../../src/parse-gram.c"
     break;
 
-  case 100:
+  case 101:
 
 /* Line 1457 of yacc.c  */
-#line 599 "parse-gram.y"
+#line 601 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
 
 /* Line 1457 of yacc.c  */
-#line 2843 "parse-gram.c"
+#line 2866 "../../../src/parse-gram.c"
     break;
 
-  case 103:
+  case 104:
 
 /* Line 1457 of yacc.c  */
-#line 611 "parse-gram.y"
+#line 613 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[(1) - (1)].chars)), (yylsp[(1) - (1)]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[(1) - (1)]), false);
     }
 
 /* Line 1457 of yacc.c  */
-#line 2856 "parse-gram.c"
+#line 2879 "../../../src/parse-gram.c"
     break;
 
-  case 105:
+  case 106:
 
 /* Line 1457 of yacc.c  */
-#line 620 "parse-gram.y"
+#line 622 "parse-gram.y"
     {
       code_props plain_code;
       code_props_plain_init (&plain_code, (yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)]));
@@ -2869,13 +2892,13 @@ yyreduce:
     }
 
 /* Line 1457 of yacc.c  */
-#line 2873 "parse-gram.c"
+#line 2896 "../../../src/parse-gram.c"
     break;
 
 
 
 /* Line 1457 of yacc.c  */
-#line 2879 "parse-gram.c"
+#line 2902 "../../../src/parse-gram.c"
       default: break;
     }
   YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);
@@ -3094,7 +3117,7 @@ yyreturn:
 
 
 /* Line 1677 of yacc.c  */
-#line 630 "parse-gram.y"
+#line 632 "parse-gram.y"
 
 
 
