@@ -186,45 +186,47 @@ static int current_prec = 0;
      PERCENT_PREC = 268,
      PERCENT_DPREC = 269,
      PERCENT_MERGE = 270,
-     PERCENT_AFTER_DEFINITIONS = 271,
-     PERCENT_BEFORE_DEFINITIONS = 272,
+     PERCENT_AFTER_HEADER = 271,
+     PERCENT_BEFORE_HEADER = 272,
      PERCENT_DEBUG = 273,
      PERCENT_DEFAULT_PREC = 274,
      PERCENT_DEFINE = 275,
      PERCENT_DEFINES = 276,
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
-     PERCENT_UNION = 309
+     PERCENT_END_HEADER = 277,
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
+     PERCENT_PURE_PARSER = 292,
+     PERCENT_REQUIRE = 293,
+     PERCENT_SKELETON = 294,
+     PERCENT_START = 295,
+     PERCENT_START_HEADER = 296,
+     PERCENT_TOKEN_TABLE = 297,
+     PERCENT_VERBOSE = 298,
+     PERCENT_YACC = 299,
+     BRACED_CODE = 300,
+     CHAR = 301,
+     EPILOGUE = 302,
+     EQUAL = 303,
+     ID = 304,
+     ID_COLON = 305,
+     PERCENT_PERCENT = 306,
+     PIPE = 307,
+     PROLOGUE = 308,
+     SEMICOLON = 309,
+     TYPE = 310,
+     PERCENT_UNION = 311
    };
 #endif
 /* Tokens.  */
@@ -242,45 +244,47 @@ static int current_prec = 0;
 #define PERCENT_PREC 268
 #define PERCENT_DPREC 269
 #define PERCENT_MERGE 270
-#define PERCENT_AFTER_DEFINITIONS 271
-#define PERCENT_BEFORE_DEFINITIONS 272
+#define PERCENT_AFTER_HEADER 271
+#define PERCENT_BEFORE_HEADER 272
 #define PERCENT_DEBUG 273
 #define PERCENT_DEFAULT_PREC 274
 #define PERCENT_DEFINE 275
 #define PERCENT_DEFINES 276
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
-#define PERCENT_UNION 309
+#define PERCENT_END_HEADER 277
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
+#define PERCENT_PURE_PARSER 292
+#define PERCENT_REQUIRE 293
+#define PERCENT_SKELETON 294
+#define PERCENT_START 295
+#define PERCENT_START_HEADER 296
+#define PERCENT_TOKEN_TABLE 297
+#define PERCENT_VERBOSE 298
+#define PERCENT_YACC 299
+#define BRACED_CODE 300
+#define CHAR 301
+#define EPILOGUE 302
+#define EQUAL 303
+#define ID 304
+#define ID_COLON 305
+#define PERCENT_PERCENT 306
+#define PIPE 307
+#define PROLOGUE 308
+#define SEMICOLON 309
+#define TYPE 310
+#define PERCENT_UNION 311
 
 
 
@@ -298,7 +302,7 @@ typedef union YYSTYPE
   unsigned char character;
 }
 /* Line 197 of yacc.c.  */
-#line 302 "parse-gram.c"
+#line 306 "parse-gram.c"
 	YYSTYPE;
 # define yystype YYSTYPE /* obsolescent; will be withdrawn */
 # define YYSTYPE_IS_DECLARED 1
@@ -323,7 +327,7 @@ typedef struct YYLTYPE
 
 
 /* Line __line__ of yacc.c.  */
-#line 327 "parse-gram.c"
+#line 331 "parse-gram.c"
 
 #ifdef short
 # undef short
@@ -540,20 +544,20 @@ union yyalloc
 /* YYFINAL -- State number of the termination state.  */
 #define YYFINAL  3
 /* YYLAST -- Last index in YYTABLE.  */
-#define YYLAST   185
+#define YYLAST   192
 
 /* YYNTOKENS -- Number of terminals.  */
-#define YYNTOKENS  55
+#define YYNTOKENS  57
 /* YYNNTS -- Number of nonterminals.  */
 #define YYNNTS  27
 /* YYNRULES -- Number of rules.  */
-#define YYNRULES  87
+#define YYNRULES  89
 /* YYNRULES -- Number of states.  */
-#define YYNSTATES  124
+#define YYNSTATES  128
 
 /* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
 #define YYUNDEFTOK  2
-#define YYMAXUTOK   309
+#define YYMAXUTOK   311
 
 #define YYTRANSLATE(YYX)						\
   ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)
@@ -591,7 +595,8 @@ static const yytype_uint8 yytranslate[] =
       15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
       25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
       35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
-      45,    46,    47,    48,    49,    50,    51,    52,    53,    54
+      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
+      55,    56
 };
 
 #if YYDEBUG
@@ -600,56 +605,57 @@ static const yytype_uint8 yytranslate[] =
 static const yytype_uint8 yyprhs[] =
 {
        0,     0,     3,     8,     9,    12,    14,    16,    19,    22,
-      24,    27,    31,    33,    35,    38,    41,    45,    47,    50,
-      53,    55,    59,    61,    63,    67,    70,    72,    75,    78,
-      80,    82,    84,    86,    88,    90,    93,    97,   101,   103,
-     105,   106,   108,   112,   113,   117,   118,   122,   126,   130,
-     132,   134,   136,   137,   139,   141,   144,   146,   148,   151,
-     154,   158,   160,   163,   165,   168,   170,   173,   176,   177,
-     181,   183,   187,   190,   191,   194,   197,   201,   205,   209,
-     211,   213,   215,   217,   219,   221,   223,   224
+      24,    27,    31,    33,    36,    38,    41,    44,    48,    50,
+      53,    56,    58,    62,    64,    66,    70,    73,    75,    78,
+      81,    84,    86,    88,    90,    92,    94,    96,    99,   103,
+     107,   109,   111,   112,   114,   118,   119,   123,   124,   128,
+     132,   136,   138,   140,   142,   143,   145,   147,   150,   152,
+     154,   157,   160,   164,   166,   169,   171,   174,   176,   179,
+     182,   183,   187,   189,   193,   196,   197,   200,   203,   207,
+     211,   215,   217,   219,   221,   223,   225,   227,   229,   230
 };
 
 /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
 static const yytype_int8 yyrhs[] =
 {
-      56,     0,    -1,    57,    49,    70,    81,    -1,    -1,    57,
-      58,    -1,    59,    -1,    51,    -1,    16,    43,    -1,    17,
-      43,    -1,    18,    -1,    20,    80,    -1,    20,    80,    80,
-      -1,    21,    -1,    22,    -1,    23,     4,    -1,    24,     4,
-      -1,    25,    46,    80,    -1,    26,    -1,    27,    43,    -1,
-      28,    43,    -1,    29,    -1,    30,    46,    80,    -1,    32,
-      -1,    33,    -1,    34,    46,    80,    -1,    35,    43,    -1,
-      36,    -1,    37,    80,    -1,    38,    80,    -1,    40,    -1,
-      41,    -1,    42,    -1,    52,    -1,    64,    -1,    61,    -1,
-      39,    78,    -1,     8,    43,    67,    -1,     9,    43,    67,
-      -1,    19,    -1,    31,    -1,    -1,    47,    -1,    54,    60,
-      43,    -1,    -1,     6,    62,    69,    -1,    -1,     5,    63,
-      69,    -1,     7,    53,    67,    -1,    65,    66,    67,    -1,
-      10,    -1,    11,    -1,    12,    -1,    -1,    53,    -1,    78,
-      -1,    67,    78,    -1,    53,    -1,    76,    -1,    76,     4,
-      -1,    76,    79,    -1,    76,     4,    79,    -1,    68,    -1,
-      69,    68,    -1,    71,    -1,    70,    71,    -1,    72,    -1,
-      59,    52,    -1,     1,    52,    -1,    -1,    77,    73,    74,
-      -1,    75,    -1,    74,    50,    75,    -1,    74,    52,    -1,
-      -1,    75,    78,    -1,    75,    43,    -1,    75,    13,    78,
-      -1,    75,    14,     4,    -1,    75,    15,    53,    -1,    47,
-      -1,    44,    -1,    48,    -1,    76,    -1,    79,    -1,     3,
-      -1,     3,    -1,    -1,    49,    45,    -1
+      58,     0,    -1,    59,    51,    72,    83,    -1,    -1,    59,
+      60,    -1,    61,    -1,    53,    -1,    16,    45,    -1,    17,
+      45,    -1,    18,    -1,    20,    82,    -1,    20,    82,    82,
+      -1,    21,    -1,    22,    45,    -1,    23,    -1,    24,     4,
+      -1,    25,     4,    -1,    26,    48,    82,    -1,    27,    -1,
+      28,    45,    -1,    29,    45,    -1,    30,    -1,    31,    48,
+      82,    -1,    33,    -1,    34,    -1,    35,    48,    82,    -1,
+      36,    45,    -1,    37,    -1,    38,    82,    -1,    39,    82,
+      -1,    41,    45,    -1,    42,    -1,    43,    -1,    44,    -1,
+      54,    -1,    66,    -1,    63,    -1,    40,    80,    -1,     8,
+      45,    69,    -1,     9,    45,    69,    -1,    19,    -1,    32,
+      -1,    -1,    49,    -1,    56,    62,    45,    -1,    -1,     6,
+      64,    71,    -1,    -1,     5,    65,    71,    -1,     7,    55,
+      69,    -1,    67,    68,    69,    -1,    10,    -1,    11,    -1,
+      12,    -1,    -1,    55,    -1,    80,    -1,    69,    80,    -1,
+      55,    -1,    78,    -1,    78,     4,    -1,    78,    81,    -1,
+      78,     4,    81,    -1,    70,    -1,    71,    70,    -1,    73,
+      -1,    72,    73,    -1,    74,    -1,    61,    54,    -1,     1,
+      54,    -1,    -1,    79,    75,    76,    -1,    77,    -1,    76,
+      52,    77,    -1,    76,    54,    -1,    -1,    77,    80,    -1,
+      77,    45,    -1,    77,    13,    80,    -1,    77,    14,     4,
+      -1,    77,    15,    55,    -1,    49,    -1,    46,    -1,    50,
+      -1,    78,    -1,    81,    -1,     3,    -1,     3,    -1,    -1,
+      51,    47,    -1
 };
 
 /* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
 static const yytype_uint16 yyrline[] =
 {
-       0,   202,   202,   210,   212,   216,   217,   219,   226,   233,
-     234,   239,   240,   241,   242,   243,   244,   245,   250,   254,
-     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
-     265,   266,   267,   271,   272,   273,   277,   285,   293,   297,
-     311,   312,   316,   338,   338,   343,   343,   348,   358,   373,
-     374,   375,   379,   380,   385,   386,   391,   395,   400,   406,
-     412,   423,   424,   433,   434,   440,   441,   442,   449,   449,
-     453,   454,   455,   460,   461,   463,   466,   468,   470,   483,
-     485,   494,   499,   500,   505,   514,   519,   521
+       0,   202,   202,   210,   212,   216,   217,   221,   227,   233,
+     234,   239,   240,   241,   247,   248,   249,   250,   251,   256,
+     260,   261,   262,   263,   264,   265,   266,   267,   268,   269,
+     270,   276,   277,   278,   279,   283,   284,   285,   289,   297,
+     305,   309,   323,   324,   328,   350,   350,   355,   355,   360,
+     370,   385,   386,   387,   391,   392,   397,   398,   403,   407,
+     412,   418,   424,   435,   436,   445,   446,   452,   453,   454,
+     461,   461,   465,   466,   467,   472,   473,   475,   478,   480,
+     482,   495,   497,   506,   511,   512,   517,   526,   531,   533
 };
 #endif
 
@@ -661,19 +667,19 @@ static const char *const yytname[] =
   "\"end of file\"", "error", "$undefined", "\"string\"", "\"integer\"",
   "\"%token\"", "\"%nterm\"", "\"%type\"", "\"%destructor\"",
   "\"%printer\"", "\"%left\"", "\"%right\"", "\"%nonassoc\"", "\"%prec\"",
-  "\"%dprec\"", "\"%merge\"", "\"%after-definitions\"",
-  "\"%before-definitions\"", "\"%debug\"", "\"%default-prec\"",
-  "\"%define\"", "\"%defines\"", "\"%error-verbose\"", "\"%expect\"",
-  "\"%expect-rr\"", "\"%file-prefix\"", "\"%glr-parser\"",
-  "\"%initial-action\"", "\"%lex-param\"", "\"%locations\"",
-  "\"%name-prefix\"", "\"%no-default-prec\"", "\"%no-lines\"",
-  "\"%nondeterministic-parser\"", "\"%output\"", "\"%parse-param\"",
-  "\"%pure-parser\"", "\"%require\"", "\"%skeleton\"", "\"%start\"",
-  "\"%token-table\"", "\"%verbose\"", "\"%yacc\"", "\"{...}\"", "\"char\"",
-  "\"epilogue\"", "\"=\"", "\"identifier\"", "\"identifier:\"", "\"%%\"",
-  "\"|\"", "\"%{...%}\"", "\";\"", "\"type\"", "\"%union\"", "$accept",
-  "input", "declarations", "declaration", "grammar_declaration",
-  "union_name", "symbol_declaration", "@1", "@2", "precedence_declaration",
+  "\"%dprec\"", "\"%merge\"", "\"%after-header\"", "\"%before-header\"",
+  "\"%debug\"", "\"%default-prec\"", "\"%define\"", "\"%defines\"",
+  "\"%end-header\"", "\"%error-verbose\"", "\"%expect\"", "\"%expect-rr\"",
+  "\"%file-prefix\"", "\"%glr-parser\"", "\"%initial-action\"",
+  "\"%lex-param\"", "\"%locations\"", "\"%name-prefix\"",
+  "\"%no-default-prec\"", "\"%no-lines\"", "\"%nondeterministic-parser\"",
+  "\"%output\"", "\"%parse-param\"", "\"%pure-parser\"", "\"%require\"",
+  "\"%skeleton\"", "\"%start\"", "\"%start-header\"", "\"%token-table\"",
+  "\"%verbose\"", "\"%yacc\"", "\"{...}\"", "\"char\"", "\"epilogue\"",
+  "\"=\"", "\"identifier\"", "\"identifier:\"", "\"%%\"", "\"|\"",
+  "\"%{...%}\"", "\";\"", "\"type\"", "\"%union\"", "$accept", "input",
+  "declarations", "declaration", "grammar_declaration", "union_name",
+  "symbol_declaration", "@1", "@2", "precedence_declaration",
   "precedence_declarator", "type.opt", "symbols.1", "symbol_def",
   "symbol_defs.1", "grammar", "rules_or_grammar_declaration", "rules",
   "@3", "rhses.1", "rhs", "id", "id_colon", "symbol", "string_as_id",
@@ -691,36 +697,36 @@ static const yytype_uint16 yytoknum[] =
      275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
      285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
      295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
-     305,   306,   307,   308,   309
+     305,   306,   307,   308,   309,   310,   311
 };
 # endif
 
 /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
 static const yytype_uint8 yyr1[] =
 {
-       0,    55,    56,    57,    57,    58,    58,    58,    58,    58,
-      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
-      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
-      58,    58,    58,    59,    59,    59,    59,    59,    59,    59,
-      60,    60,    59,    62,    61,    63,    61,    61,    64,    65,
-      65,    65,    66,    66,    67,    67,    68,    68,    68,    68,
-      68,    69,    69,    70,    70,    71,    71,    71,    73,    72,
-      74,    74,    74,    75,    75,    75,    75,    75,    75,    76,
-      76,    77,    78,    78,    79,    80,    81,    81
+       0,    57,    58,    59,    59,    60,    60,    60,    60,    60,
+      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
+      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
+      60,    60,    60,    60,    60,    61,    61,    61,    61,    61,
+      61,    61,    62,    62,    61,    64,    63,    65,    63,    63,
+      66,    67,    67,    67,    68,    68,    69,    69,    70,    70,
+      70,    70,    70,    71,    71,    72,    72,    73,    73,    73,
+      75,    74,    76,    76,    76,    77,    77,    77,    77,    77,
+      77,    78,    78,    79,    80,    80,    81,    82,    83,    83
 };
 
 /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
 static const yytype_uint8 yyr2[] =
 {
        0,     2,     4,     0,     2,     1,     1,     2,     2,     1,
-       2,     3,     1,     1,     2,     2,     3,     1,     2,     2,
-       1,     3,     1,     1,     3,     2,     1,     2,     2,     1,
-       1,     1,     1,     1,     1,     2,     3,     3,     1,     1,
-       0,     1,     3,     0,     3,     0,     3,     3,     3,     1,
-       1,     1,     0,     1,     1,     2,     1,     1,     2,     2,
-       3,     1,     2,     1,     2,     1,     2,     2,     0,     3,
-       1,     3,     2,     0,     2,     2,     3,     3,     3,     1,
-       1,     1,     1,     1,     1,     1,     0,     2
+       2,     3,     1,     2,     1,     2,     2,     3,     1,     2,
+       2,     1,     3,     1,     1,     3,     2,     1,     2,     2,
+       2,     1,     1,     1,     1,     1,     1,     2,     3,     3,
+       1,     1,     0,     1,     3,     0,     3,     0,     3,     3,
+       3,     1,     1,     1,     0,     1,     1,     2,     1,     1,
+       2,     2,     3,     1,     2,     1,     2,     1,     2,     2,
+       0,     3,     1,     3,     2,     0,     2,     2,     3,     3,
+       3,     1,     1,     1,     1,     1,     1,     1,     0,     2
 };
 
 /* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
@@ -728,125 +734,127 @@ static const yytype_uint8 yyr2[] =
    means the default is an error.  */
 static const yytype_uint8 yydefact[] =
 {
-       3,     0,     0,     1,    45,    43,     0,     0,     0,    49,
-      50,    51,     0,     0,     9,    38,     0,    12,    13,     0,
-       0,     0,    17,     0,     0,    20,     0,    39,    22,    23,
-       0,     0,    26,     0,     0,     0,    29,    30,    31,     0,
-       6,    32,    40,     4,     5,    34,    33,    52,     0,     0,
-       0,     0,     0,     7,     8,    85,    10,    14,    15,     0,
-      18,    19,     0,     0,    25,    27,    28,    84,    80,    79,
-      82,    35,    83,     0,    81,     0,     0,    63,    65,    68,
-      41,     0,    53,     0,    56,    61,    46,    57,    44,    47,
-      54,    36,    37,    11,    16,    21,    24,    67,    66,     0,
-      64,     2,    73,    42,    48,    62,    58,    59,    55,    87,
-      69,    70,    60,    73,    72,     0,     0,     0,    75,    74,
-      71,    76,    77,    78
+       3,     0,     0,     1,    47,    45,     0,     0,     0,    51,
+      52,    53,     0,     0,     9,    40,     0,    12,     0,    14,
+       0,     0,     0,    18,     0,     0,    21,     0,    41,    23,
+      24,     0,     0,    27,     0,     0,     0,     0,    31,    32,
+      33,     0,     6,    34,    42,     4,     5,    36,    35,    54,
+       0,     0,     0,     0,     0,     7,     8,    87,    10,    13,
+      15,    16,     0,    19,    20,     0,     0,    26,    28,    29,
+      86,    82,    81,    84,    37,    85,    30,     0,    83,     0,
+       0,    65,    67,    70,    43,     0,    55,     0,    58,    63,
+      48,    59,    46,    49,    56,    38,    39,    11,    17,    22,
+      25,    69,    68,     0,    66,     2,    75,    44,    50,    64,
+      60,    61,    57,    89,    71,    72,    62,    75,    74,     0,
+       0,     0,    77,    76,    73,    78,    79,    80
 };
 
 /* YYDEFGOTO[NTERM-NUM].  */
 static const yytype_int8 yydefgoto[] =
 {
-      -1,     1,     2,    43,    75,    81,    45,    49,    48,    46,
-      47,    83,    89,    85,    86,    76,    77,    78,   102,   110,
-     111,    70,    79,    90,    72,    56,   101
+      -1,     1,     2,    45,    79,    85,    47,    51,    50,    48,
+      49,    87,    93,    89,    90,    80,    81,    82,   106,   114,
+     115,    73,    83,    94,    75,    58,   105
 };
 
 /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
    STATE-NUM.  */
-#define YYPACT_NINF -74
+#define YYPACT_NINF -76
 static const yytype_int16 yypact[] =
 {
-     -74,    34,   131,   -74,   -74,   -74,   -38,    -5,    -2,   -74,
-     -74,   -74,     5,     8,   -74,   -74,    40,   -74,   -74,    48,
-      49,    14,   -74,    21,    22,   -74,    20,   -74,   -74,   -74,
-      24,    25,   -74,    40,    40,     0,   -74,   -74,   -74,    81,
-     -74,   -74,    26,   -74,   -74,   -74,   -74,    18,   -22,   -22,
-       0,     0,     0,   -74,   -74,   -74,    40,   -74,   -74,    40,
-     -74,   -74,    40,    40,   -74,   -74,   -74,   -74,   -74,   -74,
-     -74,   -74,   -74,    27,   -74,    29,     1,   -74,   -74,   -74,
-     -74,    31,   -74,     0,   -74,   -74,   -22,    23,   -22,     0,
-     -74,     0,     0,   -74,   -74,   -74,   -74,   -74,   -74,    30,
-     -74,   -74,   -74,   -74,     0,   -74,    64,   -74,   -74,   -74,
-     -31,    15,   -74,   -74,   -74,     0,    68,    41,   -74,   -74,
-      15,   -74,   -74,   -74
+     -76,     6,   136,   -76,   -76,   -76,   -40,   -12,    -9,   -76,
+     -76,   -76,    -5,     1,   -76,   -76,    40,   -76,     5,   -76,
+      47,    50,     7,   -76,    11,    18,   -76,    19,   -76,   -76,
+     -76,    20,    25,   -76,    40,    40,    -2,    26,   -76,   -76,
+     -76,    84,   -76,   -76,    27,   -76,   -76,   -76,   -76,    14,
+     -23,   -23,    -2,    -2,    -2,   -76,   -76,   -76,    40,   -76,
+     -76,   -76,    40,   -76,   -76,    40,    40,   -76,   -76,   -76,
+     -76,   -76,   -76,   -76,   -76,   -76,   -76,    21,   -76,    23,
+       2,   -76,   -76,   -76,   -76,    28,   -76,    -2,   -76,   -76,
+     -23,    24,   -23,    -2,   -76,    -2,    -2,   -76,   -76,   -76,
+     -76,   -76,   -76,    31,   -76,   -76,   -76,   -76,    -2,   -76,
+      71,   -76,   -76,   -76,   -32,    16,   -76,   -76,   -76,    -2,
+      76,    29,   -76,   -76,    16,   -76,   -76,   -76
 };
 
 /* YYPGOTO[NTERM-NUM].  */
 static const yytype_int8 yypgoto[] =
 {
-     -74,   -74,   -74,   -74,    75,   -74,   -74,   -74,   -74,   -74,
-     -74,   -74,   -47,   -51,    35,   -74,     2,   -74,   -74,   -74,
-     -30,   -25,   -74,   -35,   -73,   -17,   -74
+     -76,   -76,   -76,   -76,    79,   -76,   -76,   -76,   -76,   -76,
+     -76,   -76,   -49,   -53,    35,   -76,    17,   -76,   -76,   -76,
+     -35,   -26,   -76,   -36,   -75,   -17,   -76
 };
 
 /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
    positive, shift that token.  If negative, reduce the rule which
    number is the opposite.  If zero, do what YYDEFACT says.
    If YYTABLE_NINF, syntax error.  */
-#define YYTABLE_NINF -87
+#define YYTABLE_NINF -89
 static const yytype_int8 yytable[] =
 {
-      71,   -86,    73,    67,    91,    92,     4,     5,     6,     7,
-       8,     9,    10,    11,   107,    50,    65,    66,    67,   113,
-      15,   114,    68,    87,    87,    69,    67,   106,   115,   116,
-     117,    84,    27,   112,     3,   105,   104,   105,    51,    93,
-      35,    52,    94,    55,    68,    95,    96,    69,    53,    74,
-      99,    54,    57,    58,   108,    42,   108,   108,   118,    68,
-      59,    87,    69,    87,    60,    61,    62,    67,    64,   108,
-      63,    82,   122,    80,   103,   109,   119,    44,   100,    97,
-     121,    98,    73,   120,    88,   119,     4,     5,     6,     7,
-       8,     9,    10,    11,   123,     0,     0,     0,     0,     0,
-      15,     0,     0,     0,     0,     0,     0,     0,     0,     0,
-       0,     0,    27,     0,     0,     0,     0,     0,     0,     0,
-      35,     0,     0,     0,     0,     0,     0,     0,     0,    74,
-       0,     0,     0,     0,     0,    42,     4,     5,     6,     7,
-       8,     9,    10,    11,     0,     0,     0,    12,    13,    14,
-      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
-      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
-      35,    36,    37,    38,     0,     0,     0,     0,     0,     0,
-      39,     0,    40,    41,     0,    42
+      74,    70,   -88,    77,    95,    96,     3,     4,     5,     6,
+       7,     8,     9,    10,    11,    52,   111,    68,    69,    70,
+     117,    15,   118,    71,    91,    91,    72,    70,   110,   119,
+     120,   121,    88,    53,    28,   116,    54,   109,   108,   109,
+      55,    97,    36,    57,    71,    98,    56,    72,    99,   100,
+      59,    60,    78,   103,    61,    62,    63,   112,    44,   112,
+     112,   122,    71,    64,    91,    72,    91,    65,    66,    86,
+      67,    76,   112,   107,    70,   101,    84,   102,   113,   123,
+     126,    46,   124,   125,   127,    77,    92,     0,   123,     4,
+       5,     6,     7,     8,     9,    10,    11,   104,     0,     0,
+       0,     0,     0,    15,     0,     0,     0,     0,     0,     0,
+       0,     0,     0,     0,     0,     0,    28,     0,     0,     0,
+       0,     0,     0,     0,    36,     0,     0,     0,     0,     0,
+       0,     0,     0,     0,    78,     0,     0,     0,     0,     0,
+      44,     4,     5,     6,     7,     8,     9,    10,    11,     0,
+       0,     0,    12,    13,    14,    15,    16,    17,    18,    19,
+      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
+      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
+      40,     0,     0,     0,     0,     0,     0,    41,     0,    42,
+      43,     0,    44
 };
 
 static const yytype_int8 yycheck[] =
 {
-      35,     0,     1,     3,    51,    52,     5,     6,     7,     8,
-       9,    10,    11,    12,    87,    53,    33,    34,     3,    50,
-      19,    52,    44,    48,    49,    47,     3,     4,    13,    14,
-      15,    53,    31,   106,     0,    86,    83,    88,    43,    56,
-      39,    43,    59,     3,    44,    62,    63,    47,    43,    48,
-      49,    43,     4,     4,    89,    54,    91,    92,    43,    44,
-      46,    86,    47,    88,    43,    43,    46,     3,    43,   104,
-      46,    53,     4,    47,    43,    45,   111,     2,    76,    52,
-     115,    52,     1,   113,    49,   120,     5,     6,     7,     8,
-       9,    10,    11,    12,    53,    -1,    -1,    -1,    -1,    -1,
-      19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
-      -1,    -1,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
-      39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,
-      -1,    -1,    -1,    -1,    -1,    54,     5,     6,     7,     8,
-       9,    10,    11,    12,    -1,    -1,    -1,    16,    17,    18,
-      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
-      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
-      39,    40,    41,    42,    -1,    -1,    -1,    -1,    -1,    -1,
-      49,    -1,    51,    52,    -1,    54
+      36,     3,     0,     1,    53,    54,     0,     5,     6,     7,
+       8,     9,    10,    11,    12,    55,    91,    34,    35,     3,
+      52,    19,    54,    46,    50,    51,    49,     3,     4,    13,
+      14,    15,    55,    45,    32,   110,    45,    90,    87,    92,
+      45,    58,    40,     3,    46,    62,    45,    49,    65,    66,
+      45,     4,    50,    51,     4,    48,    45,    93,    56,    95,
+      96,    45,    46,    45,    90,    49,    92,    48,    48,    55,
+      45,    45,   108,    45,     3,    54,    49,    54,    47,   115,
+       4,     2,   117,   119,    55,     1,    51,    -1,   124,     5,
+       6,     7,     8,     9,    10,    11,    12,    80,    -1,    -1,
+      -1,    -1,    -1,    19,    -1,    -1,    -1,    -1,    -1,    -1,
+      -1,    -1,    -1,    -1,    -1,    -1,    32,    -1,    -1,    -1,
+      -1,    -1,    -1,    -1,    40,    -1,    -1,    -1,    -1,    -1,
+      -1,    -1,    -1,    -1,    50,    -1,    -1,    -1,    -1,    -1,
+      56,     5,     6,     7,     8,     9,    10,    11,    12,    -1,
+      -1,    -1,    16,    17,    18,    19,    20,    21,    22,    23,
+      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
+      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
+      44,    -1,    -1,    -1,    -1,    -1,    -1,    51,    -1,    53,
+      54,    -1,    56
 };
 
 /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
    symbol of state STATE-NUM.  */
 static const yytype_uint8 yystos[] =
 {
-       0,    56,    57,     0,     5,     6,     7,     8,     9,    10,
+       0,    58,    59,     0,     5,     6,     7,     8,     9,    10,
       11,    12,    16,    17,    18,    19,    20,    21,    22,    23,
       24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
-      34,    35,    36,    37,    38,    39,    40,    41,    42,    49,
-      51,    52,    54,    58,    59,    61,    64,    65,    63,    62,
-      53,    43,    43,    43,    43,     3,    80,     4,     4,    46,
-      43,    43,    46,    46,    43,    80,    80,     3,    44,    47,
-      76,    78,    79,     1,    48,    59,    70,    71,    72,    77,
-      47,    60,    53,    66,    53,    68,    69,    76,    69,    67,
-      78,    67,    67,    80,    80,    80,    80,    52,    52,    49,
-      71,    81,    73,    43,    67,    68,     4,    79,    78,    45,
-      74,    75,    79,    50,    52,    13,    14,    15,    43,    78,
-      75,    78,     4,    53
+      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
+      44,    51,    53,    54,    56,    60,    61,    63,    66,    67,
+      65,    64,    55,    45,    45,    45,    45,     3,    82,    45,
+       4,     4,    48,    45,    45,    48,    48,    45,    82,    82,
+       3,    46,    49,    78,    80,    81,    45,     1,    50,    61,
+      72,    73,    74,    79,    49,    62,    55,    68,    55,    70,
+      71,    78,    71,    69,    80,    69,    69,    82,    82,    82,
+      82,    54,    54,    51,    73,    83,    75,    45,    69,    70,
+       4,    81,    80,    47,    76,    77,    81,    52,    54,    13,
+      14,    15,    45,    80,    77,    80,     4,    55
 };
 
 #define yyerrok		(yyerrstatus = 0)
@@ -997,72 +1005,72 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
       case 3: /* "\"string\"" */
 #line 181 "parse-gram.y"
 	{ fputs (quotearg_style (c_quoting_style, (yyvaluep->chars)), stderr); };
-#line 1001 "parse-gram.c"
+#line 1009 "parse-gram.c"
 	break;
       case 4: /* "\"integer\"" */
 #line 191 "parse-gram.y"
 	{ fprintf (stderr, "%d", (yyvaluep->integer)); };
-#line 1006 "parse-gram.c"
+#line 1014 "parse-gram.c"
 	break;
-      case 43: /* "\"{...}\"" */
+      case 45: /* "\"{...}\"" */
 #line 183 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1011 "parse-gram.c"
+#line 1019 "parse-gram.c"
 	break;
-      case 44: /* "\"char\"" */
+      case 46: /* "\"char\"" */
 #line 178 "parse-gram.y"
 	{ fputs (char_name ((yyvaluep->character)), stderr); };
-#line 1016 "parse-gram.c"
+#line 1024 "parse-gram.c"
 	break;
-      case 45: /* "\"epilogue\"" */
+      case 47: /* "\"epilogue\"" */
 #line 183 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1021 "parse-gram.c"
+#line 1029 "parse-gram.c"
 	break;
-      case 47: /* "\"identifier\"" */
+      case 49: /* "\"identifier\"" */
 #line 187 "parse-gram.y"
 	{ fputs ((yyvaluep->uniqstr), stderr); };
-#line 1026 "parse-gram.c"
+#line 1034 "parse-gram.c"
 	break;
-      case 48: /* "\"identifier:\"" */
+      case 50: /* "\"identifier:\"" */
 #line 188 "parse-gram.y"
 	{ fprintf (stderr, "%s:", (yyvaluep->uniqstr)); };
-#line 1031 "parse-gram.c"
+#line 1039 "parse-gram.c"
 	break;
-      case 51: /* "\"%{...%}\"" */
+      case 53: /* "\"%{...%}\"" */
 #line 183 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1036 "parse-gram.c"
+#line 1044 "parse-gram.c"
 	break;
-      case 53: /* "\"type\"" */
+      case 55: /* "\"type\"" */
 #line 186 "parse-gram.y"
 	{ fprintf (stderr, "<%s>", (yyvaluep->uniqstr)); };
-#line 1041 "parse-gram.c"
+#line 1049 "parse-gram.c"
 	break;
-      case 76: /* "id" */
+      case 78: /* "id" */
 #line 194 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
-#line 1046 "parse-gram.c"
+#line 1054 "parse-gram.c"
 	break;
-      case 77: /* "id_colon" */
+      case 79: /* "id_colon" */
 #line 195 "parse-gram.y"
 	{ fprintf (stderr, "%s:", (yyvaluep->symbol)->tag); };
-#line 1051 "parse-gram.c"
+#line 1059 "parse-gram.c"
 	break;
-      case 78: /* "symbol" */
+      case 80: /* "symbol" */
 #line 194 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
-#line 1056 "parse-gram.c"
+#line 1064 "parse-gram.c"
 	break;
-      case 79: /* "string_as_id" */
+      case 81: /* "string_as_id" */
 #line 194 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
-#line 1061 "parse-gram.c"
+#line 1069 "parse-gram.c"
 	break;
-      case 80: /* "string_content" */
+      case 82: /* "string_content" */
 #line 181 "parse-gram.y"
 	{ fputs (quotearg_style (c_quoting_style, (yyvaluep->chars)), stderr); };
-#line 1066 "parse-gram.c"
+#line 1074 "parse-gram.c"
 	break;
       default:
 	break;
@@ -1580,7 +1588,7 @@ YYLTYPE yylloc;
   boundary_set (&yylloc.end, current_file, 1, 0);
 }
 /* Line 1085 of yacc.c.  */
-#line 1584 "parse-gram.c"
+#line 1592 "parse-gram.c"
   yylsp[0] = yylloc;
   goto yysetstate;
 
@@ -1765,28 +1773,27 @@ yyreduce:
   switch (yyn)
     {
         case 6:
-#line 217 "parse-gram.y"
-    { prologue_augment (translate_code ((yyvsp[(1) - (1)].chars), (yylsp[(1) - (1)])),
-						       (yylsp[(1) - (1)])); }
+#line 218 "parse-gram.y"
+    {
+      prologue_augment (translate_code ((yyvsp[(1) - (1)].chars), (yylsp[(1) - (1)])), (yylsp[(1) - (1)]), typed);
+    }
     break;
 
   case 7:
-#line 220 "parse-gram.y"
+#line 222 "parse-gram.y"
     {
-      after_definitions = true;
       /* Remove the '{', and replace the '}' with '\n'.  */
       (yyvsp[(2) - (2)].chars)[strlen ((yyvsp[(2) - (2)].chars)) - 1] = '\n';
-      muscle_code_grow ("after_definitions", (yyvsp[(2) - (2)].chars)+1, (yylsp[(2) - (2)]));
+      prologue_augment (translate_code ((yyvsp[(2) - (2)].chars)+1, (yylsp[(2) - (2)])), (yylsp[(2) - (2)]), true);
     }
     break;
 
   case 8:
-#line 227 "parse-gram.y"
+#line 228 "parse-gram.y"
     {
-      before_definitions = true;
       /* Remove the '{', and replace the '}' with '\n'.  */
       (yyvsp[(2) - (2)].chars)[strlen ((yyvsp[(2) - (2)].chars)) - 1] = '\n';
-      muscle_code_grow ("before_definitions", (yyvsp[(2) - (2)].chars)+1, (yylsp[(2) - (2)]));
+      prologue_augment (translate_code ((yyvsp[(2) - (2)].chars)+1, (yylsp[(2) - (2)])), (yylsp[(2) - (2)]), false);
     }
     break;
 
@@ -1814,114 +1821,132 @@ yyreduce:
     break;
 
   case 13:
-#line 241 "parse-gram.y"
-    { error_verbose = true; }
+#line 242 "parse-gram.y"
+    {
+      /* Remove the '{', and replace the '}' with '\n'.  */
+      (yyvsp[(2) - (2)].chars)[strlen ((yyvsp[(2) - (2)].chars)) - 1] = '\n';
+      muscle_code_grow ("end_header", translate_code ((yyvsp[(2) - (2)].chars)+1, (yylsp[(2) - (2)])), (yylsp[(2) - (2)]));
+    }
     break;
 
   case 14:
-#line 242 "parse-gram.y"
-    { expected_sr_conflicts = (yyvsp[(2) - (2)].integer); }
+#line 247 "parse-gram.y"
+    { error_verbose = true; }
     break;
 
   case 15:
-#line 243 "parse-gram.y"
-    { expected_rr_conflicts = (yyvsp[(2) - (2)].integer); }
+#line 248 "parse-gram.y"
+    { expected_sr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 16:
-#line 244 "parse-gram.y"
-    { spec_file_prefix = (yyvsp[(3) - (3)].chars); }
+#line 249 "parse-gram.y"
+    { expected_rr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 17:
-#line 246 "parse-gram.y"
+#line 250 "parse-gram.y"
+    { spec_file_prefix = (yyvsp[(3) - (3)].chars); }
+    break;
+
+  case 18:
+#line 252 "parse-gram.y"
     {
       nondeterministic_parser = true;
       glr_parser = true;
     }
     break;
 
-  case 18:
-#line 251 "parse-gram.y"
+  case 19:
+#line 257 "parse-gram.y"
     {
       muscle_code_grow ("initial_action", translate_symbol_action ((yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])), (yylsp[(2) - (2)]));
     }
     break;
 
-  case 19:
-#line 254 "parse-gram.y"
+  case 20:
+#line 260 "parse-gram.y"
     { add_param ("lex_param", (yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])); }
     break;
 
-  case 20:
-#line 255 "parse-gram.y"
+  case 21:
+#line 261 "parse-gram.y"
     { locations_flag = true; }
     break;
 
-  case 21:
-#line 256 "parse-gram.y"
+  case 22:
+#line 262 "parse-gram.y"
     { spec_name_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
-  case 22:
-#line 257 "parse-gram.y"
+  case 23:
+#line 263 "parse-gram.y"
     { no_lines_flag = true; }
     break;
 
-  case 23:
-#line 258 "parse-gram.y"
+  case 24:
+#line 264 "parse-gram.y"
     { nondeterministic_parser = true; }
     break;
 
-  case 24:
-#line 259 "parse-gram.y"
+  case 25:
+#line 265 "parse-gram.y"
     { spec_outfile = (yyvsp[(3) - (3)].chars); }
     break;
 
-  case 25:
-#line 260 "parse-gram.y"
+  case 26:
+#line 266 "parse-gram.y"
     { add_param ("parse_param", (yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])); }
     break;
 
-  case 26:
-#line 261 "parse-gram.y"
+  case 27:
+#line 267 "parse-gram.y"
     { pure_parser = true; }
     break;
 
-  case 27:
-#line 262 "parse-gram.y"
+  case 28:
+#line 268 "parse-gram.y"
     { version_check (&(yylsp[(2) - (2)]), (yyvsp[(2) - (2)].chars)); }
     break;
 
-  case 28:
-#line 263 "parse-gram.y"
+  case 29:
+#line 269 "parse-gram.y"
     { skeleton = (yyvsp[(2) - (2)].chars); }
     break;
 
-  case 29:
-#line 264 "parse-gram.y"
+  case 30:
+#line 271 "parse-gram.y"
+    {
+      /* Remove the '{', and replace the '}' with '\n'.  */
+      (yyvsp[(2) - (2)].chars)[strlen ((yyvsp[(2) - (2)].chars)) - 1] = '\n';
+      muscle_code_grow ("start_header", translate_code ((yyvsp[(2) - (2)].chars)+1, (yylsp[(2) - (2)])), (yylsp[(2) - (2)]));
+    }
+    break;
+
+  case 31:
+#line 276 "parse-gram.y"
     { token_table_flag = true; }
     break;
 
-  case 30:
-#line 265 "parse-gram.y"
+  case 32:
+#line 277 "parse-gram.y"
     { report_flag = report_states; }
     break;
 
-  case 31:
-#line 266 "parse-gram.y"
+  case 33:
+#line 278 "parse-gram.y"
     { yacc_flag = true; }
     break;
 
-  case 35:
-#line 274 "parse-gram.y"
+  case 37:
+#line 286 "parse-gram.y"
     {
       grammar_start_symbol_set ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]));
     }
     break;
 
-  case 36:
-#line 278 "parse-gram.y"
+  case 38:
+#line 290 "parse-gram.y"
     {
       symbol_list *list;
       const char *action = translate_symbol_action ((yyvsp[(2) - (3)].chars), (yylsp[(2) - (3)]));
@@ -1931,8 +1956,8 @@ yyreduce:
     }
     break;
 
-  case 37:
-#line 286 "parse-gram.y"
+  case 39:
+#line 298 "parse-gram.y"
     {
       symbol_list *list;
       const char *action = translate_symbol_action ((yyvsp[(2) - (3)].chars), (yylsp[(2) - (3)]));
@@ -1942,32 +1967,32 @@ yyreduce:
     }
     break;
 
-  case 38:
-#line 294 "parse-gram.y"
+  case 40:
+#line 306 "parse-gram.y"
     {
       default_prec = true;
     }
     break;
 
-  case 39:
-#line 298 "parse-gram.y"
+  case 41:
+#line 310 "parse-gram.y"
     {
       default_prec = false;
     }
     break;
 
-  case 40:
-#line 311 "parse-gram.y"
+  case 42:
+#line 323 "parse-gram.y"
     {}
     break;
 
-  case 41:
-#line 312 "parse-gram.y"
+  case 43:
+#line 324 "parse-gram.y"
     { muscle_code_grow ("union_name", (yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
-  case 42:
-#line 317 "parse-gram.y"
+  case 44:
+#line 329 "parse-gram.y"
     {
       char const *body = (yyvsp[(3) - (3)].chars);
 
@@ -1985,34 +2010,34 @@ yyreduce:
     }
     break;
 
-  case 43:
-#line 338 "parse-gram.y"
+  case 45:
+#line 350 "parse-gram.y"
     { current_class = nterm_sym; }
     break;
 
-  case 44:
-#line 339 "parse-gram.y"
+  case 46:
+#line 351 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
     break;
 
-  case 45:
-#line 343 "parse-gram.y"
+  case 47:
+#line 355 "parse-gram.y"
     { current_class = token_sym; }
     break;
 
-  case 46:
-#line 344 "parse-gram.y"
+  case 48:
+#line 356 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
     break;
 
-  case 47:
-#line 349 "parse-gram.y"
+  case 49:
+#line 361 "parse-gram.y"
     {
       symbol_list *list;
       for (list = (yyvsp[(3) - (3)].list); list; list = list->next)
@@ -2021,8 +2046,8 @@ yyreduce:
     }
     break;
 
-  case 48:
-#line 359 "parse-gram.y"
+  case 50:
+#line 371 "parse-gram.y"
     {
       symbol_list *list;
       ++current_prec;
@@ -2036,58 +2061,58 @@ yyreduce:
     }
     break;
 
-  case 49:
-#line 373 "parse-gram.y"
+  case 51:
+#line 385 "parse-gram.y"
     { (yyval.assoc) = left_assoc; }
     break;
 
-  case 50:
-#line 374 "parse-gram.y"
+  case 52:
+#line 386 "parse-gram.y"
     { (yyval.assoc) = right_assoc; }
     break;
 
-  case 51:
-#line 375 "parse-gram.y"
+  case 53:
+#line 387 "parse-gram.y"
     { (yyval.assoc) = non_assoc; }
     break;
 
-  case 52:
-#line 379 "parse-gram.y"
+  case 54:
+#line 391 "parse-gram.y"
     { current_type = NULL; }
     break;
 
-  case 53:
-#line 380 "parse-gram.y"
+  case 55:
+#line 392 "parse-gram.y"
     { current_type = (yyvsp[(1) - (1)].uniqstr); }
     break;
 
-  case 54:
-#line 385 "parse-gram.y"
+  case 56:
+#line 397 "parse-gram.y"
     { (yyval.list) = symbol_list_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
-  case 55:
-#line 386 "parse-gram.y"
+  case 57:
+#line 398 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), (yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)])); }
     break;
 
-  case 56:
-#line 392 "parse-gram.y"
+  case 58:
+#line 404 "parse-gram.y"
     {
        current_type = (yyvsp[(1) - (1)].uniqstr);
      }
     break;
 
-  case 57:
-#line 396 "parse-gram.y"
+  case 59:
+#line 408 "parse-gram.y"
     {
        symbol_class_set ((yyvsp[(1) - (1)].symbol), current_class, (yylsp[(1) - (1)]), true);
        symbol_type_set ((yyvsp[(1) - (1)].symbol), current_type, (yylsp[(1) - (1)]));
      }
     break;
 
-  case 58:
-#line 401 "parse-gram.y"
+  case 60:
+#line 413 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
       symbol_type_set ((yyvsp[(1) - (2)].symbol), current_type, (yylsp[(1) - (2)]));
@@ -2095,8 +2120,8 @@ yyreduce:
     }
     break;
 
-  case 59:
-#line 407 "parse-gram.y"
+  case 61:
+#line 419 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
       symbol_type_set ((yyvsp[(1) - (2)].symbol), current_type, (yylsp[(1) - (2)]));
@@ -2104,8 +2129,8 @@ yyreduce:
     }
     break;
 
-  case 60:
-#line 413 "parse-gram.y"
+  case 62:
+#line 425 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (3)].symbol), current_class, (yylsp[(1) - (3)]), true);
       symbol_type_set ((yyvsp[(1) - (3)].symbol), current_type, (yylsp[(1) - (3)]));
@@ -2114,66 +2139,66 @@ yyreduce:
     }
     break;
 
-  case 67:
-#line 443 "parse-gram.y"
+  case 69:
+#line 455 "parse-gram.y"
     {
       yyerrok;
     }
     break;
 
-  case 68:
-#line 449 "parse-gram.y"
+  case 70:
+#line 461 "parse-gram.y"
     { current_lhs = (yyvsp[(1) - (1)].symbol); current_lhs_location = (yylsp[(1) - (1)]); }
     break;
 
-  case 70:
-#line 453 "parse-gram.y"
+  case 72:
+#line 465 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(1) - (1)])); }
     break;
 
-  case 71:
-#line 454 "parse-gram.y"
+  case 73:
+#line 466 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(3) - (3)])); }
     break;
 
-  case 73:
-#line 460 "parse-gram.y"
+  case 75:
+#line 472 "parse-gram.y"
     { grammar_current_rule_begin (current_lhs, current_lhs_location); }
     break;
 
-  case 74:
-#line 462 "parse-gram.y"
+  case 76:
+#line 474 "parse-gram.y"
     { grammar_current_rule_symbol_append ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)])); }
     break;
 
-  case 75:
-#line 464 "parse-gram.y"
+  case 77:
+#line 476 "parse-gram.y"
     { grammar_current_rule_action_append (gram_last_string,
 					  gram_last_braced_code_loc); }
     break;
 
-  case 76:
-#line 467 "parse-gram.y"
+  case 78:
+#line 479 "parse-gram.y"
     { grammar_current_rule_prec_set ((yyvsp[(3) - (3)].symbol), (yylsp[(3) - (3)])); }
     break;
 
-  case 77:
-#line 469 "parse-gram.y"
+  case 79:
+#line 481 "parse-gram.y"
     { grammar_current_rule_dprec_set ((yyvsp[(3) - (3)].integer), (yylsp[(3) - (3)])); }
     break;
 
-  case 78:
-#line 471 "parse-gram.y"
+  case 80:
+#line 483 "parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[(3) - (3)].uniqstr), (yylsp[(3) - (3)])); }
     break;
 
-  case 79:
-#line 484 "parse-gram.y"
+  case 81:
+#line 496 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
-  case 80:
-#line 486 "parse-gram.y"
+  case 82:
+#line 498 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[(1) - (1)].character)), (yylsp[(1) - (1)]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[(1) - (1)]), false);
@@ -2181,26 +2206,26 @@ yyreduce:
     }
     break;
 
-  case 81:
-#line 494 "parse-gram.y"
+  case 83:
+#line 506 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
-  case 84:
-#line 506 "parse-gram.y"
+  case 86:
+#line 518 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[(1) - (1)].chars)), (yylsp[(1) - (1)]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[(1) - (1)]), false);
     }
     break;
 
-  case 85:
-#line 515 "parse-gram.y"
+  case 87:
+#line 527 "parse-gram.y"
     { (yyval.chars) = (yyvsp[(1) - (1)].chars); }
     break;
 
-  case 87:
-#line 522 "parse-gram.y"
+  case 89:
+#line 534 "parse-gram.y"
     {
       muscle_code_grow ("epilogue", translate_code ((yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])), (yylsp[(2) - (2)]));
       gram_scanner_last_string_free ();
@@ -2209,7 +2234,7 @@ yyreduce:
 
 
 /* Line 1274 of yacc.c.  */
-#line 2213 "parse-gram.c"
+#line 2238 "parse-gram.c"
       default: break;
     }
   YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);
@@ -2429,7 +2454,7 @@ yyreturn:
 }
 
 
-#line 528 "parse-gram.y"
+#line 540 "parse-gram.y"
 
 
 
