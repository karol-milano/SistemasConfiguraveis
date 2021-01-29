@@ -82,48 +82,49 @@
      PERCENT_TYPE = 262,
      PERCENT_DESTRUCTOR = 263,
      PERCENT_PRINTER = 264,
-     PERCENT_UNION = 265,
-     PERCENT_LEFT = 266,
-     PERCENT_RIGHT = 267,
-     PERCENT_NONASSOC = 268,
-     PERCENT_PREC = 269,
-     PERCENT_DPREC = 270,
-     PERCENT_MERGE = 271,
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
-     PERCENT_LEX_PARAM = 282,
-     PERCENT_LOCATIONS = 283,
-     PERCENT_NAME_PREFIX = 284,
-     PERCENT_NO_DEFAULT_PREC = 285,
-     PERCENT_NO_LINES = 286,
-     PERCENT_NONDETERMINISTIC_PARSER = 287,
-     PERCENT_OUTPUT = 288,
-     PERCENT_PARSE_PARAM = 289,
-     PERCENT_PURE_PARSER = 290,
-     PERCENT_REQUIRE = 291,
-     PERCENT_SKELETON = 292,
-     PERCENT_START = 293,
-     PERCENT_TOKEN_TABLE = 294,
-     PERCENT_VERBOSE = 295,
-     PERCENT_YACC = 296,
-     TYPE = 297,
-     EQUAL = 298,
-     SEMICOLON = 299,
-     PIPE = 300,
-     ID = 301,
-     ID_COLON = 302,
-     PERCENT_PERCENT = 303,
+     PERCENT_LEFT = 265,
+     PERCENT_RIGHT = 266,
+     PERCENT_NONASSOC = 267,
+     PERCENT_PREC = 268,
+     PERCENT_DPREC = 269,
+     PERCENT_MERGE = 270,
+     PERCENT_DEBUG = 271,
+     PERCENT_DEFAULT_PREC = 272,
+     PERCENT_DEFINE = 273,
+     PERCENT_DEFINES = 274,
+     PERCENT_ERROR_VERBOSE = 275,
+     PERCENT_EXPECT = 276,
+     PERCENT_EXPECT_RR = 277,
+     PERCENT_FILE_PREFIX = 278,
+     PERCENT_GLR_PARSER = 279,
+     PERCENT_INITIAL_ACTION = 280,
+     PERCENT_LEX_PARAM = 281,
+     PERCENT_LOCATIONS = 282,
+     PERCENT_NAME_PREFIX = 283,
+     PERCENT_NO_DEFAULT_PREC = 284,
+     PERCENT_NO_LINES = 285,
+     PERCENT_NONDETERMINISTIC_PARSER = 286,
+     PERCENT_OUTPUT = 287,
+     PERCENT_PARSE_PARAM = 288,
+     PERCENT_PURE_PARSER = 289,
+     PERCENT_REQUIRE = 290,
+     PERCENT_SKELETON = 291,
+     PERCENT_START = 292,
+     PERCENT_TOKEN_TABLE = 293,
+     PERCENT_VERBOSE = 294,
+     PERCENT_YACC = 295,
+     BRACED_CODE = 296,
+     CHAR = 297,
+     EPILOGUE = 298,
+     EQUAL = 299,
+     ID = 300,
+     ID_COLON = 301,
+     PERCENT_PERCENT = 302,
+     PIPE = 303,
      PROLOGUE = 304,
-     EPILOGUE = 305,
-     BRACED_CODE = 306
+     SEMICOLON = 305,
+     TYPE = 306,
+     PERCENT_UNION = 307
    };
 #endif
 /* Tokens.  */
@@ -135,48 +136,49 @@
 #define PERCENT_TYPE 262
 #define PERCENT_DESTRUCTOR 263
 #define PERCENT_PRINTER 264
-#define PERCENT_UNION 265
-#define PERCENT_LEFT 266
-#define PERCENT_RIGHT 267
-#define PERCENT_NONASSOC 268
-#define PERCENT_PREC 269
-#define PERCENT_DPREC 270
-#define PERCENT_MERGE 271
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
-#define PERCENT_LEX_PARAM 282
-#define PERCENT_LOCATIONS 283
-#define PERCENT_NAME_PREFIX 284
-#define PERCENT_NO_DEFAULT_PREC 285
-#define PERCENT_NO_LINES 286
-#define PERCENT_NONDETERMINISTIC_PARSER 287
-#define PERCENT_OUTPUT 288
-#define PERCENT_PARSE_PARAM 289
-#define PERCENT_PURE_PARSER 290
-#define PERCENT_REQUIRE 291
-#define PERCENT_SKELETON 292
-#define PERCENT_START 293
-#define PERCENT_TOKEN_TABLE 294
-#define PERCENT_VERBOSE 295
-#define PERCENT_YACC 296
-#define TYPE 297
-#define EQUAL 298
-#define SEMICOLON 299
-#define PIPE 300
-#define ID 301
-#define ID_COLON 302
-#define PERCENT_PERCENT 303
+#define PERCENT_LEFT 265
+#define PERCENT_RIGHT 266
+#define PERCENT_NONASSOC 267
+#define PERCENT_PREC 268
+#define PERCENT_DPREC 269
+#define PERCENT_MERGE 270
+#define PERCENT_DEBUG 271
+#define PERCENT_DEFAULT_PREC 272
+#define PERCENT_DEFINE 273
+#define PERCENT_DEFINES 274
+#define PERCENT_ERROR_VERBOSE 275
+#define PERCENT_EXPECT 276
+#define PERCENT_EXPECT_RR 277
+#define PERCENT_FILE_PREFIX 278
+#define PERCENT_GLR_PARSER 279
+#define PERCENT_INITIAL_ACTION 280
+#define PERCENT_LEX_PARAM 281
+#define PERCENT_LOCATIONS 282
+#define PERCENT_NAME_PREFIX 283
+#define PERCENT_NO_DEFAULT_PREC 284
+#define PERCENT_NO_LINES 285
+#define PERCENT_NONDETERMINISTIC_PARSER 286
+#define PERCENT_OUTPUT 287
+#define PERCENT_PARSE_PARAM 288
+#define PERCENT_PURE_PARSER 289
+#define PERCENT_REQUIRE 290
+#define PERCENT_SKELETON 291
+#define PERCENT_START 292
+#define PERCENT_TOKEN_TABLE 293
+#define PERCENT_VERBOSE 294
+#define PERCENT_YACC 295
+#define BRACED_CODE 296
+#define CHAR 297
+#define EPILOGUE 298
+#define EQUAL 299
+#define ID 300
+#define ID_COLON 301
+#define PERCENT_PERCENT 302
+#define PIPE 303
 #define PROLOGUE 304
-#define EPILOGUE 305
-#define BRACED_CODE 306
+#define SEMICOLON 305
+#define TYPE 306
+#define PERCENT_UNION 307
 
 
 
@@ -286,9 +288,10 @@ typedef union YYSTYPE
   char *chars;
   assoc assoc;
   uniqstr uniqstr;
+  unsigned char character;
 }
 /* Line 193 of yacc.c.  */
-#line 292 "../../src/parse-gram.c"
+#line 295 "../../src/parse-gram.c"
 	YYSTYPE;
 # define yystype YYSTYPE /* obsolescent; will be withdrawn */
 # define YYSTYPE_IS_DECLARED 1
@@ -313,7 +316,7 @@ typedef struct YYLTYPE
 
 
 /* Line 216 of yacc.c.  */
-#line 317 "../../src/parse-gram.c"
+#line 320 "../../src/parse-gram.c"
 
 #ifdef short
 # undef short
@@ -530,20 +533,20 @@ union yyalloc
 /* YYFINAL -- State number of the termination state.  */
 #define YYFINAL  3
 /* YYLAST -- Last index in YYTABLE.  */
-#define YYLAST   164
+#define YYLAST   134
 
 /* YYNTOKENS -- Number of terminals.  */
-#define YYNTOKENS  52
+#define YYNTOKENS  53
 /* YYNNTS -- Number of nonterminals.  */
-#define YYNNTS  24
+#define YYNNTS  27
 /* YYNRULES -- Number of rules.  */
-#define YYNRULES  80
+#define YYNRULES  85
 /* YYNRULES -- Number of states.  */
-#define YYNSTATES  114
+#define YYNSTATES  120
 
 /* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
 #define YYUNDEFTOK  2
-#define YYMAXUTOK   306
+#define YYMAXUTOK   307
 
 #define YYTRANSLATE(YYX)						\
   ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)
@@ -581,7 +584,7 @@ static const yytype_uint8 yytranslate[] =
       15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
       25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
       35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
-      45,    46,    47,    48,    49,    50,    51
+      45,    46,    47,    48,    49,    50,    51,    52
 };
 
 #if YYDEBUG
@@ -592,52 +595,54 @@ static const yytype_uint8 yyprhs[] =
        0,     0,     3,     8,     9,    12,    14,    16,    18,    21,
       25,    27,    29,    32,    35,    39,    41,    44,    47,    49,
       53,    55,    57,    61,    64,    66,    69,    72,    74,    76,
-      78,    80,    82,    84,    87,    89,    93,    97,    99,   101,
-     102,   106,   107,   111,   115,   119,   121,   123,   125,   126,
-     128,   130,   133,   135,   137,   140,   143,   147,   149,   152,
-     154,   157,   159,   162,   165,   166,   170,   172,   176,   179,
-     180,   183,   186,   190,   194,   198,   200,   202,   204,   206,
-     207
+      78,    80,    82,    84,    87,    91,    95,    97,    99,   100,
+     102,   106,   107,   111,   112,   116,   120,   124,   126,   128,
+     130,   131,   133,   135,   138,   140,   142,   145,   148,   152,
+     154,   157,   159,   162,   164,   167,   170,   171,   175,   177,
+     181,   184,   185,   188,   191,   195,   199,   203,   205,   207,
+     209,   211,   213,   215,   217,   218
 };
 
 /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
 static const yytype_int8 yyrhs[] =
 {
-      53,     0,    -1,    54,    48,    66,    75,    -1,    -1,    54,
-      55,    -1,    56,    -1,    49,    -1,    17,    -1,    19,    74,
-      -1,    19,    74,    74,    -1,    20,    -1,    21,    -1,    22,
-       4,    -1,    23,     4,    -1,    24,    43,    74,    -1,    25,
-      -1,    26,    51,    -1,    27,    51,    -1,    28,    -1,    29,
-      43,    74,    -1,    31,    -1,    32,    -1,    33,    43,    74,
-      -1,    34,    51,    -1,    35,    -1,    36,    74,    -1,    37,
-      74,    -1,    39,    -1,    40,    -1,    41,    -1,    44,    -1,
-      60,    -1,    57,    -1,    38,    72,    -1,    10,    -1,     8,
-      51,    63,    -1,     9,    51,    63,    -1,    18,    -1,    30,
-      -1,    -1,     6,    58,    65,    -1,    -1,     5,    59,    65,
-      -1,     7,    42,    63,    -1,    61,    62,    63,    -1,    11,
-      -1,    12,    -1,    13,    -1,    -1,    42,    -1,    72,    -1,
-      63,    72,    -1,    42,    -1,    46,    -1,    46,     4,    -1,
-      46,    73,    -1,    46,     4,    73,    -1,    64,    -1,    65,
-      64,    -1,    67,    -1,    66,    67,    -1,    68,    -1,    56,
-      44,    -1,     1,    44,    -1,    -1,    47,    69,    70,    -1,
-      71,    -1,    70,    45,    71,    -1,    70,    44,    -1,    -1,
-      71,    72,    -1,    71,    51,    -1,    71,    14,    72,    -1,
-      71,    15,     4,    -1,    71,    16,    42,    -1,    46,    -1,
-      73,    -1,     3,    -1,     3,    -1,    -1,    48,    50,    -1
+      54,     0,    -1,    55,    47,    68,    79,    -1,    -1,    55,
+      56,    -1,    57,    -1,    49,    -1,    16,    -1,    18,    78,
+      -1,    18,    78,    78,    -1,    19,    -1,    20,    -1,    21,
+       4,    -1,    22,     4,    -1,    23,    44,    78,    -1,    24,
+      -1,    25,    41,    -1,    26,    41,    -1,    27,    -1,    28,
+      44,    78,    -1,    30,    -1,    31,    -1,    32,    44,    78,
+      -1,    33,    41,    -1,    34,    -1,    35,    78,    -1,    36,
+      78,    -1,    38,    -1,    39,    -1,    40,    -1,    50,    -1,
+      62,    -1,    59,    -1,    37,    76,    -1,     8,    41,    65,
+      -1,     9,    41,    65,    -1,    17,    -1,    29,    -1,    -1,
+      45,    -1,    52,    58,    41,    -1,    -1,     6,    60,    67,
+      -1,    -1,     5,    61,    67,    -1,     7,    51,    65,    -1,
+      63,    64,    65,    -1,    10,    -1,    11,    -1,    12,    -1,
+      -1,    51,    -1,    76,    -1,    65,    76,    -1,    51,    -1,
+      74,    -1,    74,     4,    -1,    74,    77,    -1,    74,     4,
+      77,    -1,    66,    -1,    67,    66,    -1,    69,    -1,    68,
+      69,    -1,    70,    -1,    57,    50,    -1,     1,    50,    -1,
+      -1,    75,    71,    72,    -1,    73,    -1,    72,    48,    73,
+      -1,    72,    50,    -1,    -1,    73,    76,    -1,    73,    41,
+      -1,    73,    13,    76,    -1,    73,    14,     4,    -1,    73,
+      15,    51,    -1,    45,    -1,    42,    -1,    46,    -1,    74,
+      -1,    77,    -1,     3,    -1,     3,    -1,    -1,    47,    43,
+      -1
 };
 
 /* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
 static const yytype_uint16 yyrline[] =
 {
-       0,   194,   194,   202,   204,   208,   209,   211,   212,   217,
-     218,   219,   220,   221,   222,   223,   228,   232,   233,   234,
-     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
-     245,   249,   250,   251,   255,   271,   279,   287,   291,   298,
-     298,   303,   303,   308,   318,   333,   334,   335,   339,   340,
-     345,   346,   351,   355,   360,   366,   372,   383,   384,   393,
-     394,   400,   401,   402,   409,   409,   413,   414,   415,   420,
-     421,   423,   426,   428,   430,   435,   436,   441,   450,   455,
-     457
+       0,   195,   195,   203,   205,   209,   210,   212,   213,   218,
+     219,   220,   221,   222,   223,   224,   229,   233,   234,   235,
+     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
+     246,   250,   251,   252,   256,   264,   272,   276,   290,   291,
+     295,   317,   317,   322,   322,   327,   337,   352,   353,   354,
+     358,   359,   364,   365,   370,   374,   379,   385,   391,   402,
+     403,   412,   413,   419,   420,   421,   428,   428,   432,   433,
+     434,   439,   440,   442,   445,   447,   449,   462,   463,   472,
+     477,   478,   483,   492,   497,   499
 };
 #endif
 
@@ -648,23 +653,23 @@ static const char *const yytname[] =
 {
   "\"end of file\"", "error", "$undefined", "\"string\"", "\"integer\"",
   "\"%token\"", "\"%nterm\"", "\"%type\"", "\"%destructor\"",
-  "\"%printer\"", "\"%union {...}\"", "\"%left\"", "\"%right\"",
-  "\"%nonassoc\"", "\"%prec\"", "\"%dprec\"", "\"%merge\"", "\"%debug\"",
-  "\"%default-prec\"", "\"%define\"", "\"%defines\"", "\"%error-verbose\"",
-  "\"%expect\"", "\"%expect-rr\"", "\"%file-prefix\"", "\"%glr-parser\"",
+  "\"%printer\"", "\"%left\"", "\"%right\"", "\"%nonassoc\"", "\"%prec\"",
+  "\"%dprec\"", "\"%merge\"", "\"%debug\"", "\"%default-prec\"",
+  "\"%define\"", "\"%defines\"", "\"%error-verbose\"", "\"%expect\"",
+  "\"%expect-rr\"", "\"%file-prefix\"", "\"%glr-parser\"",
   "\"%initial-action\"", "\"%lex-param\"", "\"%locations\"",
   "\"%name-prefix\"", "\"%no-default-prec\"", "\"%no-lines\"",
   "\"%nondeterministic-parser\"", "\"%output\"", "\"%parse-param\"",
   "\"%pure-parser\"", "\"%require\"", "\"%skeleton\"", "\"%start\"",
-  "\"%token-table\"", "\"%verbose\"", "\"%yacc\"", "\"type\"", "\"=\"",
-  "\";\"", "\"|\"", "\"identifier\"", "\"identifier:\"", "\"%%\"",
-  "\"%{...%}\"", "\"epilogue\"", "\"{...}\"", "$accept", "input",
-  "declarations", "declaration", "grammar_declaration",
-  "symbol_declaration", "@1", "@2", "precedence_declaration",
+  "\"%token-table\"", "\"%verbose\"", "\"%yacc\"", "\"{...}\"", "\"char\"",
+  "\"epilogue\"", "\"=\"", "\"identifier\"", "\"identifier:\"", "\"%%\"",
+  "\"|\"", "\"%{...%}\"", "\";\"", "\"type\"", "\"%union\"", "$accept",
+  "input", "declarations", "declaration", "grammar_declaration",
+  "union_name", "symbol_declaration", "@1", "@2", "precedence_declaration",
   "precedence_declarator", "type.opt", "symbols.1", "symbol_def",
   "symbol_defs.1", "grammar", "rules_or_grammar_declaration", "rules",
-  "@3", "rhses.1", "rhs", "symbol", "string_as_id", "string_content",
-  "epilogue.opt", 0
+  "@3", "rhses.1", "rhs", "id", "id_colon", "symbol", "string_as_id",
+  "string_content", "epilogue.opt", 0
 };
 #endif
 
@@ -678,22 +683,22 @@ static const yytype_uint16 yytoknum[] =
      275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
      285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
      295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
-     305,   306
+     305,   306,   307
 };
 # endif
 
 /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
 static const yytype_uint8 yyr1[] =
 {
-       0,    52,    53,    54,    54,    55,    55,    55,    55,    55,
-      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
-      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
-      55,    56,    56,    56,    56,    56,    56,    56,    56,    58,
-      57,    59,    57,    57,    60,    61,    61,    61,    62,    62,
-      63,    63,    64,    64,    64,    64,    64,    65,    65,    66,
-      66,    67,    67,    67,    69,    68,    70,    70,    70,    71,
-      71,    71,    71,    71,    71,    72,    72,    73,    74,    75,
-      75
+       0,    53,    54,    55,    55,    56,    56,    56,    56,    56,
+      56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
+      56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
+      56,    57,    57,    57,    57,    57,    57,    57,    58,    58,
+      57,    60,    59,    61,    59,    59,    62,    63,    63,    63,
+      64,    64,    65,    65,    66,    66,    66,    66,    66,    67,
+      67,    68,    68,    69,    69,    69,    71,    70,    72,    72,
+      72,    73,    73,    73,    73,    73,    73,    74,    74,    75,
+      76,    76,    77,    78,    79,    79
 };
 
 /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
@@ -702,12 +707,12 @@ static const yytype_uint8 yyr2[] =
        0,     2,     4,     0,     2,     1,     1,     1,     2,     3,
        1,     1,     2,     2,     3,     1,     2,     2,     1,     3,
        1,     1,     3,     2,     1,     2,     2,     1,     1,     1,
-       1,     1,     1,     2,     1,     3,     3,     1,     1,     0,
-       3,     0,     3,     3,     3,     1,     1,     1,     0,     1,
-       1,     2,     1,     1,     2,     2,     3,     1,     2,     1,
-       2,     1,     2,     2,     0,     3,     1,     3,     2,     0,
-       2,     2,     3,     3,     3,     1,     1,     1,     1,     0,
-       2
+       1,     1,     1,     2,     3,     3,     1,     1,     0,     1,
+       3,     0,     3,     0,     3,     3,     3,     1,     1,     1,
+       0,     1,     1,     2,     1,     1,     2,     2,     3,     1,
+       2,     1,     2,     1,     2,     2,     0,     3,     1,     3,
+       2,     0,     2,     2,     3,     3,     3,     1,     1,     1,
+       1,     1,     1,     1,     0,     2
 };
 
 /* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
@@ -715,118 +720,112 @@ static const yytype_uint8 yyr2[] =
    means the default is an error.  */
 static const yytype_uint8 yydefact[] =
 {
-       3,     0,     0,     1,    41,    39,     0,     0,     0,    34,
-      45,    46,    47,     7,    37,     0,    10,    11,     0,     0,
-       0,    15,     0,     0,    18,     0,    38,    20,    21,     0,
-       0,    24,     0,     0,     0,    27,    28,    29,    30,     0,
-       6,     4,     5,    32,    31,    48,     0,     0,     0,     0,
-       0,    78,     8,    12,    13,     0,    16,    17,     0,     0,
-      23,    25,    26,    77,    75,    33,    76,     0,    64,     0,
-       0,    59,    61,    49,     0,    52,    53,    57,    42,    40,
-      43,    50,    35,    36,     9,    14,    19,    22,    63,    69,
-      62,     0,    60,     2,    44,    54,    55,    58,    51,    65,
-      66,    80,    56,    68,    69,     0,     0,     0,    71,    70,
-      67,    72,    73,    74
+       3,     0,     0,     1,    43,    41,     0,     0,     0,    47,
+      48,    49,     7,    36,     0,    10,    11,     0,     0,     0,
+      15,     0,     0,    18,     0,    37,    20,    21,     0,     0,
+      24,     0,     0,     0,    27,    28,    29,     0,     6,    30,
+      38,     4,     5,    32,    31,    50,     0,     0,     0,     0,
+       0,    83,     8,    12,    13,     0,    16,    17,     0,     0,
+      23,    25,    26,    82,    78,    77,    80,    33,    81,     0,
+      79,     0,     0,    61,    63,    66,    39,     0,    51,     0,
+      54,    59,    44,    55,    42,    45,    52,    34,    35,     9,
+      14,    19,    22,    65,    64,     0,    62,     2,    71,    40,
+      46,    60,    56,    57,    53,    85,    67,    68,    58,    71,
+      70,     0,     0,     0,    73,    72,    69,    74,    75,    76
 };
 
 /* YYDEFGOTO[NTERM-NUM].  */
 static const yytype_int8 yydefgoto[] =
 {
-      -1,     1,     2,    41,    69,    43,    47,    46,    44,    45,
-      74,    80,    77,    78,    70,    71,    72,    89,    99,   100,
-      81,    66,    52,    93
+      -1,     1,     2,    41,    71,    77,    43,    47,    46,    44,
+      45,    79,    85,    81,    82,    72,    73,    74,    98,   106,
+     107,    66,    75,    86,    68,    52,    97
 };
 
 /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
    STATE-NUM.  */
-#define YYPACT_NINF -72
+#define YYPACT_NINF -70
 static const yytype_int8 yypact[] =
 {
-     -72,     7,   115,   -72,   -72,   -72,   -22,   -17,   -16,   -72,
-     -72,   -72,   -72,   -72,   -72,    26,   -72,   -72,    32,    33,
-      -3,   -72,    -8,    -6,   -72,     4,   -72,   -72,   -72,     9,
-       2,   -72,    26,    26,    -2,   -72,   -72,   -72,   -72,    72,
-     -72,   -72,   -72,   -72,   -72,    12,   -40,   -40,    -2,    -2,
-      -2,   -72,    26,   -72,   -72,    26,   -72,   -72,    26,    26,
-     -72,   -72,   -72,   -72,   -72,   -72,   -72,    11,   -72,    13,
-       3,   -72,   -72,   -72,    -2,   -72,    19,   -72,   -40,   -40,
-      -2,   -72,    -2,    -2,   -72,   -72,   -72,   -72,   -72,   -72,
-     -72,    18,   -72,   -72,    -2,    53,   -72,   -72,   -72,   -19,
-      16,   -72,   -72,   -72,   -72,    -2,    55,    21,   -72,   -72,
-      16,   -72,   -72,   -72
+     -70,     5,    79,   -70,   -70,   -70,   -19,    -4,     8,   -70,
+     -70,   -70,   -70,   -70,    47,   -70,   -70,    54,    61,    25,
+     -70,    38,    39,   -70,    37,   -70,   -70,   -70,    48,    41,
+     -70,    47,    47,    26,   -70,   -70,   -70,    14,   -70,   -70,
+      49,   -70,   -70,   -70,   -70,    42,    19,    19,    26,    26,
+      26,   -70,    47,   -70,   -70,    47,   -70,   -70,    47,    47,
+     -70,   -70,   -70,   -70,   -70,   -70,   -70,   -70,   -70,    70,
+     -70,    71,     1,   -70,   -70,   -70,   -70,    81,   -70,    26,
+     -70,   -70,    19,    13,    19,    26,   -70,    26,    26,   -70,
+     -70,   -70,   -70,   -70,   -70,    80,   -70,   -70,   -70,   -70,
+      26,   -70,   121,   -70,   -70,   -70,    -8,    31,   -70,   -70,
+     -70,    26,   123,    74,   -70,   -70,    31,   -70,   -70,   -70
 };
 
 /* YYPGOTO[NTERM-NUM].  */
-static const yytype_int8 yypgoto[] =
+static const yytype_int16 yypgoto[] =
 {
-     -72,   -72,   -72,   -72,    67,   -72,   -72,   -72,   -72,   -72,
-     -72,   -32,   -51,    23,   -72,     5,   -72,   -72,   -72,   -30,
-     -34,   -71,     6,   -72
+     -70,   -70,   -70,   -70,   128,   -70,   -70,   -70,   -70,   -70,
+     -70,   -70,   -22,    -7,    85,   -70,    62,   -70,   -70,   -70,
+      24,   -43,   -70,   -33,   -69,     4,   -70
 };
 
 /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
    positive, shift that token.  If negative, reduce the rule which
    number is the opposite.  If zero, do what YYDEFACT says.
    If YYTABLE_NINF, syntax error.  */
-#define YYTABLE_NINF -80
+#define YYTABLE_NINF -85
 static const yytype_int8 yytable[] =
 {
-      65,    63,    75,   -79,    67,    96,    76,     3,     4,     5,
-       6,     7,     8,     9,    10,    11,    12,    82,    83,    63,
-      48,    14,    63,    95,   102,   103,   104,    97,    97,    51,
-     105,   106,   107,    26,    49,    50,    53,    54,    61,    62,
-      55,    34,    94,    56,    64,    57,    98,    58,    98,    98,
-      68,    91,    59,    60,    73,    88,    63,    90,    84,   112,
-      98,    85,    64,   113,    86,    87,   109,   108,   101,    42,
-      79,   111,     0,    67,   110,    92,   109,     4,     5,     6,
-       7,     8,     9,    10,    11,    12,     0,     0,     0,     0,
-      14,     0,     0,     0,     0,     0,     0,     0,     0,     0,
-       0,     0,    26,     0,     0,     0,     0,     0,     0,     0,
-      34,     0,     0,     0,     0,     0,     0,     0,     0,    68,
-       4,     5,     6,     7,     8,     9,    10,    11,    12,     0,
-       0,     0,    13,    14,    15,    16,    17,    18,    19,    20,
-      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
-      31,    32,    33,    34,    35,    36,    37,     0,     0,    38,
-       0,     0,     0,    39,    40
+      67,   -84,    69,    83,    83,     3,     4,     5,     6,     7,
+       8,     9,    10,    11,   103,    69,    63,   102,    13,     4,
+       5,     6,     7,     8,     9,    10,    11,    87,    88,    63,
+      25,    13,    48,   108,    63,    61,    62,    49,    33,    83,
+     109,    83,   110,    25,   111,   112,   113,    70,    95,    50,
+      51,    33,   104,    40,   104,   104,    89,   100,    53,    90,
+      70,    64,    91,    92,    65,    54,    40,   104,    64,    55,
+      80,    65,   114,    64,   115,   101,    65,   101,   117,    56,
+      57,    58,    60,   115,     4,     5,     6,     7,     8,     9,
+      10,    11,    59,    78,    76,    12,    13,    14,    15,    16,
+      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
+      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
+      93,    94,    99,   105,    63,   119,    37,   118,    38,    39,
+      42,    40,    84,   116,    96
 };
 
-static const yytype_int8 yycheck[] =
+static const yytype_uint8 yycheck[] =
 {
-      34,     3,    42,     0,     1,    76,    46,     0,     5,     6,
-       7,     8,     9,    10,    11,    12,    13,    49,    50,     3,
-      42,    18,     3,     4,    95,    44,    45,    78,    79,     3,
-      14,    15,    16,    30,    51,    51,     4,     4,    32,    33,
-      43,    38,    74,    51,    46,    51,    80,    43,    82,    83,
-      47,    48,    43,    51,    42,    44,     3,    44,    52,     4,
-      94,    55,    46,    42,    58,    59,   100,    51,    50,     2,
-      47,   105,    -1,     1,   104,    70,   110,     5,     6,     7,
-       8,     9,    10,    11,    12,    13,    -1,    -1,    -1,    -1,
-      18,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
-      -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
-      38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,
-       5,     6,     7,     8,     9,    10,    11,    12,    13,    -1,
-      -1,    -1,    17,    18,    19,    20,    21,    22,    23,    24,
-      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
-      35,    36,    37,    38,    39,    40,    41,    -1,    -1,    44,
-      -1,    -1,    -1,    48,    49
+      33,     0,     1,    46,    47,     0,     5,     6,     7,     8,
+       9,    10,    11,    12,    83,     1,     3,     4,    17,     5,
+       6,     7,     8,     9,    10,    11,    12,    49,    50,     3,
+      29,    17,    51,   102,     3,    31,    32,    41,    37,    82,
+      48,    84,    50,    29,    13,    14,    15,    46,    47,    41,
+       3,    37,    85,    52,    87,    88,    52,    79,     4,    55,
+      46,    42,    58,    59,    45,     4,    52,   100,    42,    44,
+      51,    45,    41,    42,   107,    82,    45,    84,   111,    41,
+      41,    44,    41,   116,     5,     6,     7,     8,     9,    10,
+      11,    12,    44,    51,    45,    16,    17,    18,    19,    20,
+      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
+      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
+      50,    50,    41,    43,     3,    51,    47,     4,    49,    50,
+       2,    52,    47,   109,    72
 };
 
 /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
    symbol of state STATE-NUM.  */
 static const yytype_uint8 yystos[] =
 {
-       0,    53,    54,     0,     5,     6,     7,     8,     9,    10,
-      11,    12,    13,    17,    18,    19,    20,    21,    22,    23,
+       0,    54,    55,     0,     5,     6,     7,     8,     9,    10,
+      11,    12,    16,    17,    18,    19,    20,    21,    22,    23,
       24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
-      34,    35,    36,    37,    38,    39,    40,    41,    44,    48,
-      49,    55,    56,    57,    60,    61,    59,    58,    42,    51,
-      51,     3,    74,     4,     4,    43,    51,    51,    43,    43,
-      51,    74,    74,     3,    46,    72,    73,     1,    47,    56,
-      66,    67,    68,    42,    62,    42,    46,    64,    65,    65,
-      63,    72,    63,    63,    74,    74,    74,    74,    44,    69,
-      44,    48,    67,    75,    63,     4,    73,    64,    72,    70,
-      71,    50,    73,    44,    45,    14,    15,    16,    51,    72,
-      71,    72,     4,    42
+      34,    35,    36,    37,    38,    39,    40,    47,    49,    50,
+      52,    56,    57,    59,    62,    63,    61,    60,    51,    41,
+      41,     3,    78,     4,     4,    44,    41,    41,    44,    44,
+      41,    78,    78,     3,    42,    45,    74,    76,    77,     1,
+      46,    57,    68,    69,    70,    75,    45,    58,    51,    64,
+      51,    66,    67,    74,    67,    65,    76,    65,    65,    78,
+      78,    78,    78,    50,    50,    47,    69,    79,    71,    41,
+      65,    66,     4,    77,    76,    43,    72,    73,    77,    48,
+      50,    13,    14,    15,    41,    76,    73,    76,     4,    51
 };
 
 #define yyerrok		(yyerrstatus = 0)
@@ -953,14 +952,14 @@ do {									  \
 #if (defined __STDC__ || defined __C99__FUNC__ \
      || defined __cplusplus || defined _MSC_VER)
 static void
-yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
+yy_symbol_value_print (FILE *yyoutput, int yytype, const YYSTYPE * const yyvaluep, const YYLTYPE * const yylocationp)
 #else
 static void
 yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
     FILE *yyoutput;
     int yytype;
-    YYSTYPE const * const yyvaluep;
-    YYLTYPE const * const yylocationp;
+    const YYSTYPE * const yyvaluep;
+    const YYLTYPE * const yylocationp;
 #endif
 {
   if (!yyvaluep)
@@ -977,62 +976,72 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
       case 3: /* "\"string\"" */
 #line 175 "../../src/parse-gram.y"
 	{ fprintf (stderr, "\"%s\"", (yyvaluep->chars)); };
-#line 981 "../../src/parse-gram.c"
+#line 980 "../../src/parse-gram.c"
 	break;
       case 4: /* "\"integer\"" */
 #line 184 "../../src/parse-gram.y"
 	{ fprintf (stderr, "%d", (yyvaluep->integer)); };
-#line 986 "../../src/parse-gram.c"
+#line 985 "../../src/parse-gram.c"
 	break;
-      case 10: /* "\"%union {...}\"" */
-#line 177 "../../src/parse-gram.y"
+      case 41: /* "\"{...}\"" */
+#line 176 "../../src/parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 991 "../../src/parse-gram.c"
+#line 990 "../../src/parse-gram.c"
 	break;
-      case 42: /* "\"type\"" */
-#line 182 "../../src/parse-gram.y"
-	{ fprintf (stderr, "<%s>", (yyvaluep->uniqstr)); };
-#line 996 "../../src/parse-gram.c"
+      case 42: /* "\"char\"" */
+#line 172 "../../src/parse-gram.y"
+	{ fprintf (stderr, "'%c' (%d)", (yyvaluep->character), (yyvaluep->character)); };
+#line 995 "../../src/parse-gram.c"
 	break;
-      case 46: /* "\"identifier\"" */
-#line 186 "../../src/parse-gram.y"
-	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
-#line 1001 "../../src/parse-gram.c"
+      case 43: /* "\"epilogue\"" */
+#line 176 "../../src/parse-gram.y"
+	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
+#line 1000 "../../src/parse-gram.c"
 	break;
-      case 47: /* "\"identifier:\"" */
-#line 188 "../../src/parse-gram.y"
-	{ fprintf (stderr, "%s:", (yyvaluep->symbol)->tag); };
-#line 1006 "../../src/parse-gram.c"
+      case 45: /* "\"identifier\"" */
+#line 180 "../../src/parse-gram.y"
+	{ fprintf (stderr, "%s", (yyvaluep->uniqstr)); };
+#line 1005 "../../src/parse-gram.c"
+	break;
+      case 46: /* "\"identifier:\"" */
+#line 181 "../../src/parse-gram.y"
+	{ fprintf (stderr, "%s:", (yyvaluep->uniqstr)); };
+#line 1010 "../../src/parse-gram.c"
 	break;
       case 49: /* "\"%{...%}\"" */
-#line 177 "../../src/parse-gram.y"
+#line 176 "../../src/parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1011 "../../src/parse-gram.c"
+#line 1015 "../../src/parse-gram.c"
 	break;
-      case 50: /* "\"epilogue\"" */
-#line 177 "../../src/parse-gram.y"
-	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1016 "../../src/parse-gram.c"
+      case 51: /* "\"type\"" */
+#line 179 "../../src/parse-gram.y"
+	{ fprintf (stderr, "<%s>", (yyvaluep->uniqstr)); };
+#line 1020 "../../src/parse-gram.c"
 	break;
-      case 51: /* "\"{...}\"" */
-#line 177 "../../src/parse-gram.y"
-	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1021 "../../src/parse-gram.c"
+      case 74: /* "id" */
+#line 187 "../../src/parse-gram.y"
+	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
+#line 1025 "../../src/parse-gram.c"
 	break;
-      case 72: /* "symbol" */
-#line 186 "../../src/parse-gram.y"
+      case 75: /* "id_colon" */
+#line 188 "../../src/parse-gram.y"
+	{ fprintf (stderr, "%s:", (yyvaluep->symbol)->tag); };
+#line 1030 "../../src/parse-gram.c"
+	break;
+      case 76: /* "symbol" */
+#line 187 "../../src/parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
-#line 1026 "../../src/parse-gram.c"
+#line 1035 "../../src/parse-gram.c"
 	break;
-      case 73: /* "string_as_id" */
-#line 186 "../../src/parse-gram.y"
+      case 77: /* "string_as_id" */
+#line 187 "../../src/parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
-#line 1031 "../../src/parse-gram.c"
+#line 1040 "../../src/parse-gram.c"
 	break;
-      case 74: /* "string_content" */
+      case 78: /* "string_content" */
 #line 175 "../../src/parse-gram.y"
 	{ fprintf (stderr, "\"%s\"", (yyvaluep->chars)); };
-#line 1036 "../../src/parse-gram.c"
+#line 1045 "../../src/parse-gram.c"
 	break;
       default:
 	break;
@@ -1047,14 +1056,14 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 #if (defined __STDC__ || defined __C99__FUNC__ \
      || defined __cplusplus || defined _MSC_VER)
 static void
-yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
+yy_symbol_print (FILE *yyoutput, int yytype, const YYSTYPE * const yyvaluep, const YYLTYPE * const yylocationp)
 #else
 static void
 yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp)
     FILE *yyoutput;
     int yytype;
-    YYSTYPE const * const yyvaluep;
-    YYLTYPE const * const yylocationp;
+    const YYSTYPE * const yyvaluep;
+    const YYLTYPE * const yylocationp;
 #endif
 {
   if (yytype < YYNTOKENS)
@@ -1107,7 +1116,8 @@ static void
 yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
 #else
 static void
-yy_reduce_print (yyvsp, yylsp, yyrule)
+yy_reduce_print (yyvsp, yylsp, yyrule
+		   )
     YYSTYPE *yyvsp;
     YYLTYPE *yylsp;
     int yyrule;
@@ -1230,7 +1240,7 @@ yytnamerr (char *yyres, const char *yystr)
 {
   if (*yystr == '"')
     {
-      YYSIZE_T yyn = 0;
+      size_t yyn = 0;
       char const *yyp = yystr;
 
       for (;;)
@@ -1277,7 +1287,7 @@ yysyntax_error (char *yyresult, int yystate, int yychar)
 {
   int yyn = yypact[yystate];
 
-  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
+  if (! (YYPACT_NINF < yyn && yyn < YYLAST))
     return 0;
   else
     {
@@ -1315,7 +1325,7 @@ yysyntax_error (char *yyresult, int yystate, int yychar)
       int yyxbegin = yyn < 0 ? -yyn : 0;
 
       /* Stay within bounds of both yycheck and yytname.  */
-      int yychecklim = YYLAST - yyn + 1;
+      int yychecklim = YYLAST - yyn;
       int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
       int yycount = 1;
 
@@ -1456,15 +1466,15 @@ yyparse ()
 #endif
 #endif
 {
-  /* The lookahead symbol.  */
+  /* The look-ahead symbol.  */
 int yychar;
 
-/* The semantic value of the lookahead symbol.  */
+/* The semantic value of the look-ahead symbol.  */
 YYSTYPE yylval;
 
 /* Number of syntax errors so far.  */
 int yynerrs;
-/* Location data for the lookahead symbol.  */
+/* Location data for the look-ahead symbol.  */
 YYLTYPE yylloc;
 
   int yystate;
@@ -1472,7 +1482,7 @@ YYLTYPE yylloc;
   int yyresult;
   /* Number of tokens to shift before error messages enabled.  */
   int yyerrstatus;
-  /* Lookahead token as an internal (translated) token number.  */
+  /* Look-ahead token as an internal (translated) token number.  */
   int yytoken = 0;
 #if YYERROR_VERBOSE
   /* Buffer for error messages, and its allocated size.  */
@@ -1550,7 +1560,7 @@ YYLTYPE yylloc;
   boundary_set (&yylloc.end, current_file, 1, 0);
 }
 /* Line 1078 of yacc.c.  */
-#line 1554 "../../src/parse-gram.c"
+#line 1564 "../../src/parse-gram.c"
   yylsp[0] = yylloc;
   goto yysetstate;
 
@@ -1640,16 +1650,16 @@ YYLTYPE yylloc;
 yybackup:
 
   /* Do appropriate processing given the current state.  Read a
-     lookahead token if we need one and don't already have one.  */
+     look-ahead token if we need one and don't already have one.  */
 
-  /* First try to decide what to do without reference to lookahead token.  */
+  /* First try to decide what to do without reference to look-ahead token.  */
   yyn = yypact[yystate];
   if (yyn == YYPACT_NINF)
     goto yydefault;
 
-  /* Not known => get a lookahead token if don't already have one.  */
+  /* Not known => get a look-ahead token if don't already have one.  */
 
-  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
+  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
   if (yychar == YYEMPTY)
     {
       YYDPRINTF ((stderr, "Reading a token: "));
@@ -1689,7 +1699,7 @@ yybackup:
   if (yyerrstatus)
     yyerrstatus--;
 
-  /* Shift the lookahead token.  */
+  /* Shift the look-ahead token.  */
   YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
 
   /* Discard the shifted token unless it is eof.  */
@@ -1735,18 +1745,18 @@ yyreduce:
   switch (yyn)
     {
         case 6:
-#line 209 "../../src/parse-gram.y"
+#line 210 "../../src/parse-gram.y"
     { prologue_augment (translate_code ((yyvsp[(1) - (1)].chars), (yylsp[(1) - (1)])),
 						       (yylsp[(1) - (1)])); }
     break;
 
   case 7:
-#line 211 "../../src/parse-gram.y"
+#line 212 "../../src/parse-gram.y"
     { debug_flag = true; }
     break;
 
   case 8:
-#line 213 "../../src/parse-gram.y"
+#line 214 "../../src/parse-gram.y"
     {
       static char one[] = "1";
       muscle_insert ((yyvsp[(2) - (2)].chars), one);
@@ -1754,37 +1764,37 @@ yyreduce:
     break;
 
   case 9:
-#line 217 "../../src/parse-gram.y"
+#line 218 "../../src/parse-gram.y"
     { muscle_insert ((yyvsp[(2) - (3)].chars), (yyvsp[(3) - (3)].chars)); }
     break;
 
   case 10:
-#line 218 "../../src/parse-gram.y"
+#line 219 "../../src/parse-gram.y"
     { defines_flag = true; }
     break;
 
   case 11:
-#line 219 "../../src/parse-gram.y"
+#line 220 "../../src/parse-gram.y"
     { error_verbose = true; }
     break;
 
   case 12:
-#line 220 "../../src/parse-gram.y"
+#line 221 "../../src/parse-gram.y"
     { expected_sr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 13:
-#line 221 "../../src/parse-gram.y"
+#line 222 "../../src/parse-gram.y"
     { expected_rr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 14:
-#line 222 "../../src/parse-gram.y"
+#line 223 "../../src/parse-gram.y"
     { spec_file_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 15:
-#line 224 "../../src/parse-gram.y"
+#line 225 "../../src/parse-gram.y"
     {
       nondeterministic_parser = true;
       glr_parser = true;
@@ -1792,105 +1802,86 @@ yyreduce:
     break;
 
   case 16:
-#line 229 "../../src/parse-gram.y"
+#line 230 "../../src/parse-gram.y"
     {
       muscle_code_grow ("initial_action", translate_symbol_action ((yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])), (yylsp[(2) - (2)]));
     }
     break;
 
   case 17:
-#line 232 "../../src/parse-gram.y"
+#line 233 "../../src/parse-gram.y"
     { add_param ("lex_param", (yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])); }
     break;
 
   case 18:
-#line 233 "../../src/parse-gram.y"
+#line 234 "../../src/parse-gram.y"
     { locations_flag = true; }
     break;
 
   case 19:
-#line 234 "../../src/parse-gram.y"
+#line 235 "../../src/parse-gram.y"
     { spec_name_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 20:
-#line 235 "../../src/parse-gram.y"
+#line 236 "../../src/parse-gram.y"
     { no_lines_flag = true; }
     break;
 
   case 21:
-#line 236 "../../src/parse-gram.y"
+#line 237 "../../src/parse-gram.y"
     { nondeterministic_parser = true; }
     break;
 
   case 22:
-#line 237 "../../src/parse-gram.y"
+#line 238 "../../src/parse-gram.y"
     { spec_outfile = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 23:
-#line 238 "../../src/parse-gram.y"
+#line 239 "../../src/parse-gram.y"
     { add_param ("parse_param", (yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])); }
     break;
 
   case 24:
-#line 239 "../../src/parse-gram.y"
+#line 240 "../../src/parse-gram.y"
     { pure_parser = true; }
     break;
 
   case 25:
-#line 240 "../../src/parse-gram.y"
+#line 241 "../../src/parse-gram.y"
     { version_check (&(yylsp[(2) - (2)]), (yyvsp[(2) - (2)].chars)); }
     break;
 
   case 26:
-#line 241 "../../src/parse-gram.y"
+#line 242 "../../src/parse-gram.y"
     { skeleton = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 27:
-#line 242 "../../src/parse-gram.y"
+#line 243 "../../src/parse-gram.y"
     { token_table_flag = true; }
     break;
 
   case 28:
-#line 243 "../../src/parse-gram.y"
+#line 244 "../../src/parse-gram.y"
     { report_flag = report_states; }
     break;
 
   case 29:
-#line 244 "../../src/parse-gram.y"
+#line 245 "../../src/parse-gram.y"
     { yacc_flag = true; }
     break;
 
   case 33:
-#line 252 "../../src/parse-gram.y"
+#line 253 "../../src/parse-gram.y"
     {
       grammar_start_symbol_set ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]));
     }
     break;
 
   case 34:
-#line 256 "../../src/parse-gram.y"
-    {
-      char const *body = (yyvsp[(1) - (1)].chars);
-
-      if (typed)
-	{
-	  /* Concatenate the union bodies, turning the first one's
-	     trailing '}' into '\n', and omitting the second one's '{'.  */
-	  char *code = muscle_find ("stype");
-	  code[strlen (code) - 1] = '\n';
-	  body++;
-	}
-
-      typed = true;
-      muscle_code_grow ("stype", body, (yylsp[(1) - (1)]));
-    }
-    break;
-
-  case 35:
-#line 272 "../../src/parse-gram.y"
+#line 257 "../../src/parse-gram.y"
     {
       symbol_list *list;
       const char *action = translate_symbol_action ((yyvsp[(2) - (3)].chars), (yylsp[(2) - (3)]));
@@ -1900,8 +1891,8 @@ yyreduce:
     }
     break;
 
-  case 36:
-#line 280 "../../src/parse-gram.y"
+  case 35:
+#line 265 "../../src/parse-gram.y"
     {
       symbol_list *list;
       const char *action = translate_symbol_action ((yyvsp[(2) - (3)].chars), (yylsp[(2) - (3)]));
@@ -1911,40 +1902,56 @@ yyreduce:
     }
     break;
 
-  case 37:
-#line 288 "../../src/parse-gram.y"
+  case 36:
+#line 273 "../../src/parse-gram.y"
     {
       default_prec = true;
     }
     break;
 
-  case 38:
-#line 292 "../../src/parse-gram.y"
+  case 37:
+#line 277 "../../src/parse-gram.y"
     {
       default_prec = false;
     }
     break;
 
+  case 38:
+#line 290 "../../src/parse-gram.y"
+    {}
+    break;
+
   case 39:
-#line 298 "../../src/parse-gram.y"
-    { current_class = nterm_sym; }
+#line 291 "../../src/parse-gram.y"
+    { muscle_code_grow ("union_name", (yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 40:
-#line 299 "../../src/parse-gram.y"
+#line 296 "../../src/parse-gram.y"
     {
-      current_class = unknown_sym;
-      current_type = NULL;
+      char const *body = (yyvsp[(3) - (3)].chars);
+
+      if (typed)
+	{
+	  /* Concatenate the union bodies, turning the first one's
+	     trailing '}' into '\n', and omitting the second one's '{'.  */
+	  char *code = muscle_find ("stype");
+	  code[strlen (code) - 1] = '\n';
+	  body++;
+	}
+
+      typed = true;
+      muscle_code_grow ("stype", body, (yylsp[(3) - (3)]));
     }
     break;
 
   case 41:
-#line 303 "../../src/parse-gram.y"
-    { current_class = token_sym; }
+#line 317 "../../src/parse-gram.y"
+    { current_class = nterm_sym; }
     break;
 
   case 42:
-#line 304 "../../src/parse-gram.y"
+#line 318 "../../src/parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
@@ -1952,7 +1959,20 @@ yyreduce:
     break;
 
   case 43:
-#line 309 "../../src/parse-gram.y"
+#line 322 "../../src/parse-gram.y"
+    { current_class = token_sym; }
+    break;
+
+  case 44:
+#line 323 "../../src/parse-gram.y"
+    {
+      current_class = unknown_sym;
+      current_type = NULL;
+    }
+    break;
+
+  case 45:
+#line 328 "../../src/parse-gram.y"
     {
       symbol_list *list;
       for (list = (yyvsp[(3) - (3)].list); list; list = list->next)
@@ -1961,8 +1981,8 @@ yyreduce:
     }
     break;
 
-  case 44:
-#line 319 "../../src/parse-gram.y"
+  case 46:
+#line 338 "../../src/parse-gram.y"
     {
       symbol_list *list;
       ++current_prec;
@@ -1976,58 +1996,58 @@ yyreduce:
     }
     break;
 
-  case 45:
-#line 333 "../../src/parse-gram.y"
+  case 47:
+#line 352 "../../src/parse-gram.y"
     { (yyval.assoc) = left_assoc; }
     break;
 
-  case 46:
-#line 334 "../../src/parse-gram.y"
+  case 48:
+#line 353 "../../src/parse-gram.y"
     { (yyval.assoc) = right_assoc; }
     break;
 
-  case 47:
-#line 335 "../../src/parse-gram.y"
+  case 49:
+#line 354 "../../src/parse-gram.y"
     { (yyval.assoc) = non_assoc; }
     break;
 
-  case 48:
-#line 339 "../../src/parse-gram.y"
+  case 50:
+#line 358 "../../src/parse-gram.y"
     { current_type = NULL; }
     break;
 
-  case 49:
-#line 340 "../../src/parse-gram.y"
+  case 51:
+#line 359 "../../src/parse-gram.y"
     { current_type = (yyvsp[(1) - (1)].uniqstr); }
     break;
 
-  case 50:
-#line 345 "../../src/parse-gram.y"
+  case 52:
+#line 364 "../../src/parse-gram.y"
     { (yyval.list) = symbol_list_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
-  case 51:
-#line 346 "../../src/parse-gram.y"
+  case 53:
+#line 365 "../../src/parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), (yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)])); }
     break;
 
-  case 52:
-#line 352 "../../src/parse-gram.y"
+  case 54:
+#line 371 "../../src/parse-gram.y"
     {
        current_type = (yyvsp[(1) - (1)].uniqstr);
      }
     break;
 
-  case 53:
-#line 356 "../../src/parse-gram.y"
+  case 55:
+#line 375 "../../src/parse-gram.y"
     {
        symbol_class_set ((yyvsp[(1) - (1)].symbol), current_class, (yylsp[(1) - (1)]), true);
        symbol_type_set ((yyvsp[(1) - (1)].symbol), current_type, (yylsp[(1) - (1)]));
      }
     break;
 
-  case 54:
-#line 361 "../../src/parse-gram.y"
+  case 56:
+#line 380 "../../src/parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
       symbol_type_set ((yyvsp[(1) - (2)].symbol), current_type, (yylsp[(1) - (2)]));
@@ -2035,8 +2055,8 @@ yyreduce:
     }
     break;
 
-  case 55:
-#line 367 "../../src/parse-gram.y"
+  case 57:
+#line 386 "../../src/parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
       symbol_type_set ((yyvsp[(1) - (2)].symbol), current_type, (yylsp[(1) - (2)]));
@@ -2044,8 +2064,8 @@ yyreduce:
     }
     break;
 
-  case 56:
-#line 373 "../../src/parse-gram.y"
+  case 58:
+#line 392 "../../src/parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (3)].symbol), current_class, (yylsp[(1) - (3)]), true);
       symbol_type_set ((yyvsp[(1) - (3)].symbol), current_type, (yylsp[(1) - (3)]));
@@ -2054,84 +2074,94 @@ yyreduce:
     }
     break;
 
-  case 63:
-#line 403 "../../src/parse-gram.y"
+  case 65:
+#line 422 "../../src/parse-gram.y"
     {
       yyerrok;
     }
     break;
 
-  case 64:
-#line 409 "../../src/parse-gram.y"
+  case 66:
+#line 428 "../../src/parse-gram.y"
     { current_lhs = (yyvsp[(1) - (1)].symbol); current_lhs_location = (yylsp[(1) - (1)]); }
     break;
 
-  case 66:
-#line 413 "../../src/parse-gram.y"
+  case 68:
+#line 432 "../../src/parse-gram.y"
     { grammar_current_rule_end ((yylsp[(1) - (1)])); }
     break;
 
-  case 67:
-#line 414 "../../src/parse-gram.y"
+  case 69:
+#line 433 "../../src/parse-gram.y"
     { grammar_current_rule_end ((yylsp[(3) - (3)])); }
     break;
 
-  case 69:
-#line 420 "../../src/parse-gram.y"
+  case 71:
+#line 439 "../../src/parse-gram.y"
     { grammar_current_rule_begin (current_lhs, current_lhs_location); }
     break;
 
-  case 70:
-#line 422 "../../src/parse-gram.y"
+  case 72:
+#line 441 "../../src/parse-gram.y"
     { grammar_current_rule_symbol_append ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)])); }
     break;
 
-  case 71:
-#line 424 "../../src/parse-gram.y"
+  case 73:
+#line 443 "../../src/parse-gram.y"
     { grammar_current_rule_action_append (gram_last_string,
 					  gram_last_braced_code_loc); }
     break;
 
-  case 72:
-#line 427 "../../src/parse-gram.y"
+  case 74:
+#line 446 "../../src/parse-gram.y"
     { grammar_current_rule_prec_set ((yyvsp[(3) - (3)].symbol), (yylsp[(3) - (3)])); }
     break;
 
-  case 73:
-#line 429 "../../src/parse-gram.y"
+  case 75:
+#line 448 "../../src/parse-gram.y"
     { grammar_current_rule_dprec_set ((yyvsp[(3) - (3)].integer), (yylsp[(3) - (3)])); }
     break;
 
-  case 74:
-#line 431 "../../src/parse-gram.y"
+  case 76:
+#line 450 "../../src/parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[(3) - (3)].uniqstr), (yylsp[(3) - (3)])); }
     break;
 
-  case 75:
-#line 435 "../../src/parse-gram.y"
-    { (yyval.symbol) = (yyvsp[(1) - (1)].symbol); }
+  case 77:
+#line 462 "../../src/parse-gram.y"
+    { (yyval.symbol) = symbol_get ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
-  case 76:
-#line 436 "../../src/parse-gram.y"
-    { (yyval.symbol) = (yyvsp[(1) - (1)].symbol); }
+  case 78:
+#line 463 "../../src/parse-gram.y"
+    { char cp[4] = { '\'', (yyvsp[(1) - (1)].character), '\'', 0 };
+                    (yyval.symbol) = symbol_get (quotearg_style (escape_quoting_style, cp),
+				     (yylsp[(1) - (1)]));
+		    symbol_class_set ((yyval.symbol), token_sym, (yylsp[(1) - (1)]), false);
+		    symbol_user_token_number_set ((yyval.symbol), (yyvsp[(1) - (1)].character), (yylsp[(1) - (1)]));
+                  }
     break;
 
-  case 77:
-#line 442 "../../src/parse-gram.y"
+  case 79:
+#line 472 "../../src/parse-gram.y"
+    { (yyval.symbol) = symbol_get ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
+    break;
+
+  case 82:
+#line 484 "../../src/parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[(1) - (1)].chars)), (yylsp[(1) - (1)]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[(1) - (1)]), false);
     }
     break;
 
-  case 78:
-#line 451 "../../src/parse-gram.y"
+  case 83:
+#line 493 "../../src/parse-gram.y"
     { (yyval.chars) = (yyvsp[(1) - (1)].chars); }
     break;
 
-  case 80:
-#line 458 "../../src/parse-gram.y"
+  case 85:
+#line 500 "../../src/parse-gram.y"
     {
       muscle_code_grow ("epilogue", translate_code ((yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])), (yylsp[(2) - (2)]));
       gram_scanner_last_string_free ();
@@ -2140,7 +2170,7 @@ yyreduce:
 
 
 /* Line 1267 of yacc.c.  */
-#line 2144 "../../src/parse-gram.c"
+#line 2174 "../../src/parse-gram.c"
       default: break;
     }
   YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);
@@ -2216,7 +2246,7 @@ yyerrlab:
 
   if (yyerrstatus == 3)
     {
-      /* If just tried and failed to reuse lookahead token after an
+      /* If just tried and failed to reuse look-ahead token after an
 	 error, discard it.  */
 
       if (yychar <= YYEOF)
@@ -2233,7 +2263,7 @@ yyerrlab:
 	}
     }
 
-  /* Else will try to reuse lookahead token after shifting the error
+  /* Else will try to reuse look-ahead token after shifting the error
      token.  */
   goto yyerrlab1;
 
@@ -2298,7 +2328,7 @@ yyerrlab1:
 
   yyerror_range[1] = yylloc;
   /* Using YYLLOC is tempting, but would change the location of
-     the lookahead.  YYLOC is available though.  */
+     the look-ahead.  YYLOC is available though.  */
   YYLLOC_DEFAULT (yyloc, (yyerror_range - 1), 2);
   *++yylsp = yyloc;
 
@@ -2355,12 +2385,11 @@ yyreturn:
   if (yymsg != yymsgbuf)
     YYSTACK_FREE (yymsg);
 #endif
-  /* Make sure YYID is used.  */
-  return YYID (yyresult);
+  return yyresult;
 }
 
 
-#line 464 "../../src/parse-gram.y"
+#line 506 "../../src/parse-gram.y"
 
 
 
