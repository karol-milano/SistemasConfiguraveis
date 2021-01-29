@@ -103,7 +103,7 @@
 #include "files.h"
 #include "getargs.h"
 #include "gram.h"
-#include "muscle_tab.h"
+#include "muscle-tab.h"
 #include "quotearg.h"
 #include "reader.h"
 #include "symlist.h"
@@ -194,43 +194,40 @@ static int current_prec = 0;
      PERCENT_DEFAULT_PREC = 273,
      PERCENT_DEFINE = 274,
      PERCENT_DEFINES = 275,
-     PERCENT_ERROR_VERBOSE = 276,
-     PERCENT_EXPECT = 277,
-     PERCENT_EXPECT_RR = 278,
-     PERCENT_FLAG = 279,
-     PERCENT_FILE_PREFIX = 280,
-     PERCENT_GLR_PARSER = 281,
-     PERCENT_INITIAL_ACTION = 282,
-     PERCENT_LANGUAGE = 283,
-     PERCENT_LEX_PARAM = 284,
-     PERCENT_LOCATIONS = 285,
-     PERCENT_NAME_PREFIX = 286,
-     PERCENT_NO_DEFAULT_PREC = 287,
-     PERCENT_NO_LINES = 288,
-     PERCENT_NONDETERMINISTIC_PARSER = 289,
-     PERCENT_OUTPUT = 290,
-     PERCENT_PARSE_PARAM = 291,
-     PERCENT_PURE_PARSER = 292,
-     PERCENT_REQUIRE = 293,
-     PERCENT_SKELETON = 294,
-     PERCENT_START = 295,
-     PERCENT_TOKEN_TABLE = 296,
-     PERCENT_VERBOSE = 297,
-     PERCENT_YACC = 298,
-     BRACED_CODE = 299,
-     CHAR = 300,
-     EPILOGUE = 301,
-     EQUAL = 302,
-     ID = 303,
-     ID_COLON = 304,
-     PERCENT_PERCENT = 305,
-     PIPE = 306,
-     PROLOGUE = 307,
-     SEMICOLON = 308,
-     TAG = 309,
-     TAG_ANY = 310,
-     TAG_NONE = 311,
-     PERCENT_UNION = 312
+     PERCENT_EXPECT = 276,
+     PERCENT_EXPECT_RR = 277,
+     PERCENT_FLAG = 278,
+     PERCENT_FILE_PREFIX = 279,
+     PERCENT_GLR_PARSER = 280,
+     PERCENT_INITIAL_ACTION = 281,
+     PERCENT_LANGUAGE = 282,
+     PERCENT_LEX_PARAM = 283,
+     PERCENT_NAME_PREFIX = 284,
+     PERCENT_NO_DEFAULT_PREC = 285,
+     PERCENT_NO_LINES = 286,
+     PERCENT_NONDETERMINISTIC_PARSER = 287,
+     PERCENT_OUTPUT = 288,
+     PERCENT_PARSE_PARAM = 289,
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
+     PROLOGUE = 304,
+     SEMICOLON = 305,
+     TAG = 306,
+     TAG_ANY = 307,
+     TAG_NONE = 308,
+     PERCENT_UNION = 309
    };
 #endif
 /* Tokens.  */
@@ -253,43 +250,40 @@ static int current_prec = 0;
 #define PERCENT_DEFAULT_PREC 273
 #define PERCENT_DEFINE 274
 #define PERCENT_DEFINES 275
-#define PERCENT_ERROR_VERBOSE 276
-#define PERCENT_EXPECT 277
-#define PERCENT_EXPECT_RR 278
-#define PERCENT_FLAG 279
-#define PERCENT_FILE_PREFIX 280
-#define PERCENT_GLR_PARSER 281
-#define PERCENT_INITIAL_ACTION 282
-#define PERCENT_LANGUAGE 283
-#define PERCENT_LEX_PARAM 284
-#define PERCENT_LOCATIONS 285
-#define PERCENT_NAME_PREFIX 286
-#define PERCENT_NO_DEFAULT_PREC 287
-#define PERCENT_NO_LINES 288
-#define PERCENT_NONDETERMINISTIC_PARSER 289
-#define PERCENT_OUTPUT 290
-#define PERCENT_PARSE_PARAM 291
-#define PERCENT_PURE_PARSER 292
-#define PERCENT_REQUIRE 293
-#define PERCENT_SKELETON 294
-#define PERCENT_START 295
-#define PERCENT_TOKEN_TABLE 296
-#define PERCENT_VERBOSE 297
-#define PERCENT_YACC 298
-#define BRACED_CODE 299
-#define CHAR 300
-#define EPILOGUE 301
-#define EQUAL 302
-#define ID 303
-#define ID_COLON 304
-#define PERCENT_PERCENT 305
-#define PIPE 306
-#define PROLOGUE 307
-#define SEMICOLON 308
-#define TAG 309
-#define TAG_ANY 310
-#define TAG_NONE 311
-#define PERCENT_UNION 312
+#define PERCENT_EXPECT 276
+#define PERCENT_EXPECT_RR 277
+#define PERCENT_FLAG 278
+#define PERCENT_FILE_PREFIX 279
+#define PERCENT_GLR_PARSER 280
+#define PERCENT_INITIAL_ACTION 281
+#define PERCENT_LANGUAGE 282
+#define PERCENT_LEX_PARAM 283
+#define PERCENT_NAME_PREFIX 284
+#define PERCENT_NO_DEFAULT_PREC 285
+#define PERCENT_NO_LINES 286
+#define PERCENT_NONDETERMINISTIC_PARSER 287
+#define PERCENT_OUTPUT 288
+#define PERCENT_PARSE_PARAM 289
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
+#define PROLOGUE 304
+#define SEMICOLON 305
+#define TAG 306
+#define TAG_ANY 307
+#define TAG_NONE 308
+#define PERCENT_UNION 309
 
 
 
@@ -311,7 +305,7 @@ typedef union YYSTYPE
 
 
 /* Line 216 of yacc.c  */
-#line 315 "../../src/parse-gram.c"
+#line 309 "../../src/parse-gram.c"
 } YYSTYPE;
 # define YYSTYPE_IS_TRIVIAL 1
 # define yystype YYSTYPE /* obsolescent; will be withdrawn */
@@ -335,7 +329,7 @@ typedef struct YYLTYPE
 /* Copy the second part of user declarations.  */
 
 /* Line 266 of yacc.c  */
-#line 339 "../../src/parse-gram.c"
+#line 333 "../../src/parse-gram.c"
 
 #ifdef short
 # undef short
@@ -552,21 +546,21 @@ union yyalloc
 /* YYFINAL -- State number of the termination state.  */
 #define YYFINAL  3
 /* YYLAST -- Last index in YYTABLE.  */
-#define YYLAST   203
+#define YYLAST   186
 
 /* YYNTOKENS -- Number of terminals.  */
-#define YYNTOKENS  58
+#define YYNTOKENS  55
 /* YYNNTS -- Number of nonterminals.  */
 #define YYNNTS  33
 /* YYNRULES -- Number of rules.  */
-#define YYNRULES  104
+#define YYNRULES  103
 /* YYNSTATES -- Number of states.  */
-#define YYNSTATES  142
+#define YYNSTATES  141
 
 /* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
    by yylex, with out-of-bounds checking.  */
 #define YYUNDEFTOK  2
-#define YYMAXUTOK   312
+#define YYMAXUTOK   309
 
 #define YYTRANSLATE(YYX)						\
   ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)
@@ -605,25 +599,24 @@ static const yytype_uint8 yytranslate[] =
       15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
       25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
       35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
-      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
-      55,    56,    57
+      45,    46,    47,    48,    49,    50,    51,    52,    53,    54
 };
 
 #if YYDEBUG
   /* YYRLINEYYN -- Source line where rule number YYN was defined.    */
 static const yytype_uint16 yyrline[] =
 {
-       0,   204,   204,   212,   214,   218,   219,   229,   233,   237,
-     238,   243,   244,   245,   246,   247,   252,   261,   262,   263,
-     264,   265,   266,   267,   268,   269,   270,   271,   272,   296,
-     297,   298,   299,   303,   304,   305,   309,   316,   323,   327,
-     331,   338,   353,   354,   358,   370,   370,   375,   375,   380,
-     391,   406,   407,   408,   409,   413,   414,   419,   421,   426,
-     427,   432,   434,   439,   440,   444,   445,   446,   447,   452,
-     457,   462,   468,   474,   485,   486,   495,   496,   502,   503,
-     504,   511,   511,   515,   516,   517,   522,   523,   525,   527,
-     529,   531,   541,   542,   548,   551,   560,   580,   582,   591,
-     596,   597,   602,   609,   611
+       0,   201,   201,   209,   211,   215,   216,   226,   230,   234,
+     235,   240,   241,   242,   243,   244,   249,   258,   259,   260,
+     261,   262,   263,   264,   265,   266,   267,   268,   292,   293,
+     294,   295,   299,   300,   301,   305,   312,   319,   323,   327,
+     334,   349,   350,   354,   366,   366,   371,   371,   376,   387,
+     402,   403,   404,   405,   409,   410,   415,   417,   422,   423,
+     428,   430,   435,   436,   440,   441,   442,   443,   448,   453,
+     458,   464,   470,   481,   482,   491,   492,   498,   499,   500,
+     507,   507,   511,   512,   513,   518,   519,   521,   523,   525,
+     527,   537,   538,   544,   547,   556,   576,   578,   587,   592,
+     593,   598,   605,   607
 };
 #endif
 
@@ -636,17 +629,16 @@ static const char *const yytname[] =
   "\"%token\"", "\"%nterm\"", "\"%type\"", "\"%destructor\"",
   "\"%printer\"", "\"%left\"", "\"%right\"", "\"%nonassoc\"",
   "\"%precedence\"", "\"%prec\"", "\"%dprec\"", "\"%merge\"", "\"%code\"",
-  "\"%default-prec\"", "\"%define\"", "\"%defines\"", "\"%error-verbose\"",
-  "\"%expect\"", "\"%expect-rr\"", "\"%<flag>\"", "\"%file-prefix\"",
-  "\"%glr-parser\"", "\"%initial-action\"", "\"%language\"",
-  "\"%lex-param\"", "\"%locations\"", "\"%name-prefix\"",
-  "\"%no-default-prec\"", "\"%no-lines\"", "\"%nondeterministic-parser\"",
-  "\"%output\"", "\"%parse-param\"", "\"%pure-parser\"", "\"%require\"",
-  "\"%skeleton\"", "\"%start\"", "\"%token-table\"", "\"%verbose\"",
-  "\"%yacc\"", "\"{...}\"", "\"char\"", "\"epilogue\"", "\"=\"",
-  "\"identifier\"", "\"identifier:\"", "\"%%\"", "\"|\"", "\"%{...%}\"",
-  "\";\"", "\"<tag>\"", "\"<*>\"", "\"<>\"", "\"%union\"", "$accept",
-  "input", "prologue_declarations", "prologue_declaration",
+  "\"%default-prec\"", "\"%define\"", "\"%defines\"", "\"%expect\"",
+  "\"%expect-rr\"", "\"%<flag>\"", "\"%file-prefix\"", "\"%glr-parser\"",
+  "\"%initial-action\"", "\"%language\"", "\"%lex-param\"",
+  "\"%name-prefix\"", "\"%no-default-prec\"", "\"%no-lines\"",
+  "\"%nondeterministic-parser\"", "\"%output\"", "\"%parse-param\"",
+  "\"%require\"", "\"%skeleton\"", "\"%start\"", "\"%token-table\"",
+  "\"%verbose\"", "\"%yacc\"", "\"{...}\"", "\"char\"", "\"epilogue\"",
+  "\"=\"", "\"identifier\"", "\"identifier:\"", "\"%%\"", "\"|\"",
+  "\"%{...%}\"", "\";\"", "\"<tag>\"", "\"<*>\"", "\"<>\"", "\"%union\"",
+  "$accept", "input", "prologue_declarations", "prologue_declaration",
   "grammar_declaration", "union_name", "symbol_declaration", "$@1", "$@2",
   "precedence_declaration", "precedence_declarator", "tag.opt",
   "symbols.prec", "symbol.prec", "symbols.1", "generic_symlist",
@@ -667,33 +659,33 @@ static const yytype_uint16 yytoknum[] =
      275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
      285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
      295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
-     305,   306,   307,   308,   309,   310,   311,   312
+     305,   306,   307,   308,   309
 };
 # endif
 
-#define YYPACT_NINF -81
+#define YYPACT_NINF -93
 
-#define YYTABLE_NINF -104
+#define YYTABLE_NINF -103
 
   /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
      STATE-NUM.    */
 static const yytype_int16 yypact[] =
 {
-     -81,    21,   111,   -81,   -81,   -81,   -14,    -8,     3,   -81,
-     -81,   -81,   -81,   -18,   -81,    14,    41,    42,    49,   -81,
-       2,   -81,    10,    53,    34,   -81,    13,   -81,   -81,   -81,
-      26,    35,    54,    78,     0,   -81,   -81,   -81,    58,   -81,
-     -81,    36,   -81,   -81,   -81,   -81,    28,   -23,   -23,     0,
-      32,    32,   -81,    45,   -81,   -81,   -81,    82,   -81,   -81,
-     -81,   -81,    88,   -81,   -81,   -81,   -81,    89,   -81,    91,
-     -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,    43,
-     -81,    44,     1,   -81,   -81,   -81,   -81,    45,   -81,     0,
-     -81,   -81,   -23,    39,   -23,     0,   -81,   -81,   -81,   -81,
-      32,   -81,   -81,    32,   -81,   -81,   -81,   -81,   -81,   -81,
-     -81,   -81,    55,   -81,   -81,   -81,   -81,     0,   -81,    96,
-     -81,    92,   -81,   -81,   -81,   -81,   -19,   155,   -81,   -81,
-     -81,   -81,   -81,     0,    98,    51,   -81,   -81,   155,   -81,
-     -81,   -81
+     -93,     9,   100,   -93,   -93,   -93,   -50,    21,    32,   -93,
+     -93,   -93,   -93,   -39,   -93,     1,    56,    73,    74,   -93,
+      10,   -93,    38,    79,    43,    27,   -93,   -93,   -93,    37,
+      44,    83,    84,    22,   -93,   -93,   -93,    26,   -93,   -93,
+      45,   -93,   -93,   -93,   -93,    40,   -37,   -37,    22,     0,
+       0,   -93,    47,   -93,   -93,   -93,    86,   -93,   -93,   -93,
+     -93,    89,   -93,   -93,   -93,   -93,    92,   -93,    94,   -93,
+     -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,    48,   -93,
+      50,    11,   -93,   -93,   -93,   -93,    47,   -93,    22,   -93,
+     -93,   -37,    66,   -37,    22,   -93,   -93,   -93,   -93,     0,
+     -93,   -93,     0,   -93,   -93,   -93,   -93,   -93,   -93,   -93,
+     -93,    58,   -93,   -93,   -93,   -93,    22,   -93,    98,   -93,
+     111,   -93,   -93,   -93,   -93,    18,   141,   -93,   -93,   -93,
+     -93,   -93,    22,    99,    64,   -93,   -93,   141,   -93,   -93,
+     -93
 };
 
   /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
@@ -701,39 +693,39 @@ static const yytype_int16 yypact[] =
      error.    */
 static const yytype_uint8 yydefact[] =
 {
-       3,     0,     0,     1,    47,    45,     0,     0,     0,    51,
-      52,    53,    54,     0,    38,     0,     9,     0,     0,     7,
-       0,    15,     0,     0,     0,    19,     0,    39,    22,    23,
-       0,     0,     0,     0,     0,    29,    30,    31,     0,     6,
-      32,    42,     4,     5,    34,    33,    55,     0,     0,     0,
-       0,     0,    96,     0,    40,    93,    92,    94,    10,    11,
-      12,    13,     0,    16,    17,    18,    20,     0,    24,     0,
-      26,    27,    28,   102,    98,    97,   100,    35,   101,     0,
-      99,     0,     0,    76,    78,    81,    43,     0,    56,     0,
-      69,    74,    48,    70,    46,    49,    61,    66,    67,    68,
-      36,    63,    65,    37,    41,    95,     8,    14,    21,    25,
-      80,    79,     0,    77,     2,    86,    44,    50,    57,    59,
-      75,    71,    72,    62,    64,   104,    82,    83,    58,    60,
-      73,    86,    85,     0,     0,     0,    88,    87,    84,    89,
-      90,    91
+       3,     0,     0,     1,    46,    44,     0,     0,     0,    50,
+      51,    52,    53,     0,    37,     0,     9,     0,     0,     7,
+       0,    15,     0,     0,     0,     0,    38,    21,    22,     0,
+       0,     0,     0,     0,    28,    29,    30,     0,     6,    31,
+      41,     4,     5,    33,    32,    54,     0,     0,     0,     0,
+       0,    95,     0,    39,    92,    91,    93,    10,    11,    12,
+      13,     0,    16,    17,    18,    19,     0,    23,     0,    25,
+      26,    27,   101,    97,    96,    99,    34,   100,     0,    98,
+       0,     0,    75,    77,    80,    42,     0,    55,     0,    68,
+      73,    47,    69,    45,    48,    60,    65,    66,    67,    35,
+      62,    64,    36,    40,    94,     8,    14,    20,    24,    79,
+      78,     0,    76,     2,    85,    43,    49,    56,    58,    74,
+      70,    71,    61,    63,   103,    81,    82,    57,    59,    72,
+      85,    84,     0,     0,     0,    87,    86,    83,    88,    89,
+      90
 };
 
   /* YYPGOTO[NTERM-NUM].    */
 static const yytype_int8 yypgoto[] =
 {
-     -81,   -81,   -81,   -81,   101,   -81,   -81,   -81,   -81,   -81,
-     -81,   -81,   -81,   -11,   -81,    57,   -80,   -55,    61,   -81,
-      29,   -81,   -81,   -81,   -21,   -81,   -81,   -49,   -20,   -81,
-     -34,   -69,   -81
+     -93,   -93,   -93,   -93,   114,   -93,   -93,   -93,   -93,   -93,
+     -93,   -93,   -93,    25,   -93,    93,   -92,   -17,    95,   -93,
+      65,   -93,   -93,   -93,    15,   -93,   -93,   -26,     3,   -93,
+     -33,   -45,   -93
 };
 
   /* YYDEFGOTO[NTERM-NUM].    */
 static const yytype_int8 yydefgoto[] =
 {
-      -1,     1,     2,    42,    81,    87,    44,    48,    47,    45,
-      46,    89,   117,   118,    95,   100,   101,    91,    92,    82,
-      83,    84,   115,   126,   127,    57,   106,    54,    76,    85,
-     102,    78,   114
+      -1,     1,     2,    41,    80,    86,    43,    47,    46,    44,
+      45,    88,   116,   117,    94,    99,   100,    90,    91,    81,
+      82,    83,   114,   125,   126,    56,   105,    53,    75,    84,
+     101,    77,   113
 };
 
   /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
@@ -742,105 +734,101 @@ static const yytype_int8 yydefgoto[] =
      If YYTABLE_NINF, syntax error.    */
 static const yytype_int16 yytable[] =
 {
-      77,  -103,    79,    73,   104,    61,     4,     5,     6,     7,
-       8,     9,    10,    11,    12,    96,    66,    55,    13,    14,
-     124,     3,    74,   124,   122,    75,    52,    93,    93,    68,
-      53,    90,   131,    27,   132,    73,    50,   120,   116,   120,
-      49,    34,    73,   121,    58,    74,    59,    51,    75,    62,
-      80,   112,   130,    60,    63,   119,    64,    71,    41,    79,
-      67,   123,    56,     4,     5,     6,     7,     8,     9,    10,
-      11,    12,    93,    69,    93,    13,    14,    74,    65,    70,
-      75,    72,    88,   119,    86,   105,    97,    98,    99,    52,
-      27,   107,   108,   137,   109,    73,   110,   111,    34,   139,
-     129,   125,   140,    43,   137,   141,   128,    80,   103,    94,
-     138,   113,     0,     0,     0,    41,     4,     5,     6,     7,
-       8,     9,    10,    11,    12,     0,     0,     0,    13,    14,
-      15,    16,     0,    17,    18,    19,    20,    21,    22,    23,
-      24,    25,    26,    27,    28,    29,    30,    31,     0,    32,
-      33,    34,    35,    36,    37,     0,     0,     0,    73,     0,
-       0,    38,     0,    39,    40,     0,     0,     0,    41,   133,
-     134,   135,     0,     0,     0,     0,     0,     0,     0,     0,
+      76,    48,    51,    72,    54,    73,    52,   123,    74,     3,
+     123,  -102,    78,    60,    89,    95,     4,     5,     6,     7,
+       8,     9,    10,    11,    12,    72,   103,    78,    13,    14,
+      65,     4,     5,     6,     7,     8,     9,    10,    11,    12,
+      67,    26,    73,    13,    14,    74,    55,   121,    33,    92,
+      92,    96,    97,    98,    61,   118,    26,    79,   111,    57,
+     115,   122,    49,    33,    73,    40,   130,    74,   131,    72,
+     120,    66,    79,    50,   119,   129,   119,    58,    59,    62,
+      40,    68,    63,   118,    64,    69,    70,    71,    51,   104,
+      85,    87,   106,   136,    92,   107,    92,   108,   109,   138,
+     110,   124,   128,   139,   136,     4,     5,     6,     7,     8,
+       9,    10,    11,    12,    72,   140,    42,    13,    14,    15,
+      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
+      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
+      36,   127,    93,   102,    72,   137,   112,    37,     0,    38,
+      39,     0,     0,     0,    40,   132,   133,   134,     0,     0,
        0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
-       0,     0,     0,     0,     0,     0,     0,     0,     0,   136,
-      74,     0,     0,    75
+       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
+       0,     0,   135,    73,     0,     0,    74
 };
 
 static const yytype_int16 yycheck[] =
 {
-      34,     0,     1,     3,    53,     3,     5,     6,     7,     8,
-       9,    10,    11,    12,    13,    49,     3,     3,    17,    18,
-     100,     0,    45,   103,    93,    48,    44,    47,    48,     3,
-      48,    54,    51,    32,    53,     3,    44,    92,    87,    94,
-      54,    40,     3,     4,     3,    45,     4,    44,    48,    47,
-      49,    50,   121,     4,    44,    89,     3,     3,    57,     1,
-      47,    95,    48,     5,     6,     7,     8,     9,    10,    11,
-      12,    13,    92,    47,    94,    17,    18,    45,    44,    44,
-      48,     3,    54,   117,    48,     3,    54,    55,    56,    44,
-      32,     3,     3,   127,     3,     3,    53,    53,    40,   133,
-       4,    46,     4,     2,   138,    54,   117,    49,    51,    48,
-     131,    82,    -1,    -1,    -1,    57,     5,     6,     7,     8,
-       9,    10,    11,    12,    13,    -1,    -1,    -1,    17,    18,
-      19,    20,    -1,    22,    23,    24,    25,    26,    27,    28,
-      29,    30,    31,    32,    33,    34,    35,    36,    -1,    38,
-      39,    40,    41,    42,    43,    -1,    -1,    -1,     3,    -1,
-      -1,    50,    -1,    52,    53,    -1,    -1,    -1,    57,    14,
-      15,    16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
+      33,    51,    41,     3,     3,    42,    45,    99,    45,     0,
+     102,     0,     1,     3,    51,    48,     5,     6,     7,     8,
+       9,    10,    11,    12,    13,     3,    52,     1,    17,    18,
+       3,     5,     6,     7,     8,     9,    10,    11,    12,    13,
+       3,    30,    42,    17,    18,    45,    45,    92,    37,    46,
+      47,    51,    52,    53,    44,    88,    30,    46,    47,     3,
+      86,    94,    41,    37,    42,    54,    48,    45,    50,     3,
+       4,    44,    46,    41,    91,   120,    93,     4,     4,    41,
+      54,    44,     3,   116,    41,    41,     3,     3,    41,     3,
+      45,    51,     3,   126,    91,     3,    93,     3,    50,   132,
+      50,    43,     4,     4,   137,     5,     6,     7,     8,     9,
+      10,    11,    12,    13,     3,    51,     2,    17,    18,    19,
+      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
+      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
+      40,   116,    47,    50,     3,   130,    81,    47,    -1,    49,
+      50,    -1,    -1,    -1,    54,    14,    15,    16,    -1,    -1,
+      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
-      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,
-      45,    -1,    -1,    48
+      -1,    -1,    41,    42,    -1,    -1,    45
 };
 
   /* STOS_[STATE-NUM] -- The (internal number of the) accessing
      symbol of state STATE-NUM.    */
 static const yytype_uint8 yystos[] =
 {
-       0,    59,    60,     0,     5,     6,     7,     8,     9,    10,
-      11,    12,    13,    17,    18,    19,    20,    22,    23,    24,
-      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
-      35,    36,    38,    39,    40,    41,    42,    43,    50,    52,
-      53,    57,    61,    62,    64,    67,    68,    66,    65,    54,
-      44,    44,    44,    48,    85,     3,    48,    83,     3,     4,
-       4,     3,    47,    44,     3,    44,     3,    47,     3,    47,
-      44,     3,     3,     3,    45,    48,    86,    88,    89,     1,
-      49,    62,    77,    78,    79,    87,    48,    63,    54,    69,
-      54,    75,    76,    86,    76,    72,    88,    54,    55,    56,
-      73,    74,    88,    73,    85,     3,    84,     3,     3,     3,
-      53,    53,    50,    78,    90,    80,    85,    70,    71,    88,
-      75,     4,    89,    88,    74,    46,    81,    82,    71,     4,
-      89,    51,    53,    14,    15,    16,    44,    88,    82,    88,
-       4,    54
+       0,    56,    57,     0,     5,     6,     7,     8,     9,    10,
+      11,    12,    13,    17,    18,    19,    20,    21,    22,    23,
+      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
+      34,    35,    36,    37,    38,    39,    40,    47,    49,    50,
+      54,    58,    59,    61,    64,    65,    63,    62,    51,    41,
+      41,    41,    45,    82,     3,    45,    80,     3,     4,     4,
+       3,    44,    41,     3,    41,     3,    44,     3,    44,    41,
+       3,     3,     3,    42,    45,    83,    85,    86,     1,    46,
+      59,    74,    75,    76,    84,    45,    60,    51,    66,    51,
+      72,    73,    83,    73,    69,    85,    51,    52,    53,    70,
+      71,    85,    70,    82,     3,    81,     3,     3,     3,    50,
+      50,    47,    75,    87,    77,    82,    67,    68,    85,    72,
+       4,    86,    85,    71,    43,    78,    79,    68,     4,    86,
+      48,    50,    14,    15,    16,    41,    85,    79,    85,     4,
+      51
 };
 
   /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.    */
 static const yytype_uint8 yyr1[] =
 {
-       0,    58,    59,    60,    60,    61,    61,    61,    61,    61,
-      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
-      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
-      61,    61,    61,    62,    62,    62,    62,    62,    62,    62,
-      62,    62,    63,    63,    62,    65,    64,    66,    64,    64,
-      67,    68,    68,    68,    68,    69,    69,    70,    70,    71,
-      71,    72,    72,    73,    73,    74,    74,    74,    74,    75,
-      75,    75,    75,    75,    76,    76,    77,    77,    78,    78,
-      78,    80,    79,    81,    81,    81,    82,    82,    82,    82,
-      82,    82,    83,    83,    84,    84,    85,    86,    86,    87,
-      88,    88,    89,    90,    90
+       0,    55,    56,    57,    57,    58,    58,    58,    58,    58,
+      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
+      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
+      58,    58,    59,    59,    59,    59,    59,    59,    59,    59,
+      59,    60,    60,    59,    62,    61,    63,    61,    61,    64,
+      65,    65,    65,    65,    66,    66,    67,    67,    68,    68,
+      69,    69,    70,    70,    71,    71,    71,    71,    72,    72,
+      72,    72,    72,    73,    73,    74,    74,    75,    75,    75,
+      77,    76,    78,    78,    78,    79,    79,    79,    79,    79,
+      79,    80,    80,    81,    81,    82,    83,    83,    84,    85,
+      85,    86,    87,    87
 };
 
   /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.    */
 static const yytype_uint8 yyr2[] =
 {
        0,     2,     4,     0,     2,     1,     1,     1,     3,     1,
-       2,     2,     2,     2,     3,     1,     2,     2,     2,     1,
-       2,     3,     1,     1,     2,     3,     2,     2,     2,     1,
-       1,     1,     1,     1,     1,     2,     3,     3,     1,     1,
-       2,     3,     0,     1,     3,     0,     3,     0,     3,     3,
-       3,     1,     1,     1,     1,     0,     1,     1,     2,     1,
-       2,     1,     2,     1,     2,     1,     1,     1,     1,     1,
-       1,     2,     2,     3,     1,     2,     1,     2,     1,     2,
-       2,     0,     3,     1,     3,     2,     0,     2,     2,     3,
-       3,     3,     1,     1,     0,     1,     1,     1,     1,     1,
-       1,     1,     1,     0,     2
+       2,     2,     2,     2,     3,     1,     2,     2,     2,     2,
+       3,     1,     1,     2,     3,     2,     2,     2,     1,     1,
+       1,     1,     1,     1,     2,     3,     3,     1,     1,     2,
+       3,     0,     1,     3,     0,     3,     0,     3,     3,     3,
+       1,     1,     1,     1,     0,     1,     1,     2,     1,     2,
+       1,     2,     1,     2,     1,     1,     1,     1,     1,     1,
+       2,     2,     3,     1,     2,     1,     2,     1,     2,     2,
+       0,     3,     1,     3,     2,     0,     2,     2,     3,     3,
+       3,     1,     1,     0,     1,     1,     1,     1,     1,     1,
+       1,     1,     0,     2
 };
 
 
@@ -992,154 +980,154 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
             case 3: // "string"
 
 /* Line 647 of yacc.c  */
-#line 181 "parse-gram.y"
+#line 178 "parse-gram.y"
         { fputs (quotearg_style (c_quoting_style, ((*yyvaluep).chars)), stderr); }
 /* Line 647 of yacc.c  */
-#line 999 "../../src/parse-gram.c"
+#line 987 "../../src/parse-gram.c"
         break;
 
             case 4: // "integer"
 
 /* Line 647 of yacc.c  */
-#line 193 "parse-gram.y"
+#line 190 "parse-gram.y"
         { fprintf (stderr, "%d", ((*yyvaluep).integer)); }
 /* Line 647 of yacc.c  */
-#line 1008 "../../src/parse-gram.c"
+#line 996 "../../src/parse-gram.c"
         break;
 
-            case 24: // "%<flag>"
+            case 23: // "%<flag>"
 
 /* Line 647 of yacc.c  */
-#line 189 "parse-gram.y"
+#line 186 "parse-gram.y"
         { fprintf (stderr, "%%%s", ((*yyvaluep).uniqstr)); }
 /* Line 647 of yacc.c  */
-#line 1017 "../../src/parse-gram.c"
+#line 1005 "../../src/parse-gram.c"
         break;
 
-            case 44: // "{...}"
+            case 41: // "{...}"
 
 /* Line 647 of yacc.c  */
-#line 183 "parse-gram.y"
+#line 180 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).code)); }
 /* Line 647 of yacc.c  */
-#line 1026 "../../src/parse-gram.c"
+#line 1014 "../../src/parse-gram.c"
         break;
 
-            case 45: // "char"
+            case 42: // "char"
 
 /* Line 647 of yacc.c  */
-#line 175 "parse-gram.y"
+#line 172 "parse-gram.y"
         { fputs (char_name (((*yyvaluep).character)), stderr); }
 /* Line 647 of yacc.c  */
-#line 1035 "../../src/parse-gram.c"
+#line 1023 "../../src/parse-gram.c"
         break;
 
-            case 46: // "epilogue"
+            case 43: // "epilogue"
 
 /* Line 647 of yacc.c  */
-#line 183 "parse-gram.y"
+#line 180 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); }
 /* Line 647 of yacc.c  */
-#line 1044 "../../src/parse-gram.c"
+#line 1032 "../../src/parse-gram.c"
         break;
 
-            case 48: // "identifier"
+            case 45: // "identifier"
 
 /* Line 647 of yacc.c  */
-#line 187 "parse-gram.y"
+#line 184 "parse-gram.y"
         { fputs (((*yyvaluep).uniqstr), stderr); }
 /* Line 647 of yacc.c  */
-#line 1053 "../../src/parse-gram.c"
+#line 1041 "../../src/parse-gram.c"
         break;
 
-            case 49: // "identifier:"
+            case 46: // "identifier:"
 
 /* Line 647 of yacc.c  */
-#line 188 "parse-gram.y"
+#line 185 "parse-gram.y"
         { fprintf (stderr, "%s:", ((*yyvaluep).uniqstr)); }
 /* Line 647 of yacc.c  */
-#line 1062 "../../src/parse-gram.c"
+#line 1050 "../../src/parse-gram.c"
         break;
 
-            case 52: // "%{...%}"
+            case 49: // "%{...%}"
 
 /* Line 647 of yacc.c  */
-#line 183 "parse-gram.y"
+#line 180 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); }
 /* Line 647 of yacc.c  */
-#line 1071 "../../src/parse-gram.c"
+#line 1059 "../../src/parse-gram.c"
         break;
 
-            case 54: // "<tag>"
+            case 51: // "<tag>"
 
 /* Line 647 of yacc.c  */
-#line 190 "parse-gram.y"
+#line 187 "parse-gram.y"
         { fprintf (stderr, "<%s>", ((*yyvaluep).uniqstr)); }
 /* Line 647 of yacc.c  */
-#line 1080 "../../src/parse-gram.c"
+#line 1068 "../../src/parse-gram.c"
         break;
 
-            case 83: // variable
+            case 80: // variable
 
 /* Line 647 of yacc.c  */
-#line 187 "parse-gram.y"
+#line 184 "parse-gram.y"
         { fputs (((*yyvaluep).uniqstr), stderr); }
 /* Line 647 of yacc.c  */
-#line 1089 "../../src/parse-gram.c"
+#line 1077 "../../src/parse-gram.c"
         break;
 
-            case 84: // content.opt
+            case 81: // content.opt
 
 /* Line 647 of yacc.c  */
-#line 183 "parse-gram.y"
+#line 180 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); }
 /* Line 647 of yacc.c  */
-#line 1098 "../../src/parse-gram.c"
+#line 1086 "../../src/parse-gram.c"
         break;
 
-            case 85: // braceless
+            case 82: // braceless
 
 /* Line 647 of yacc.c  */
-#line 183 "parse-gram.y"
+#line 180 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); }
 /* Line 647 of yacc.c  */
-#line 1107 "../../src/parse-gram.c"
+#line 1095 "../../src/parse-gram.c"
         break;
 
-            case 86: // id
+            case 83: // id
 
 /* Line 647 of yacc.c  */
-#line 196 "parse-gram.y"
+#line 193 "parse-gram.y"
         { fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); }
 /* Line 647 of yacc.c  */
-#line 1116 "../../src/parse-gram.c"
+#line 1104 "../../src/parse-gram.c"
         break;
 
-            case 87: // id_colon
+            case 84: // id_colon
 
 /* Line 647 of yacc.c  */
-#line 197 "parse-gram.y"
+#line 194 "parse-gram.y"
         { fprintf (stderr, "%s:", ((*yyvaluep).symbol)->tag); }
 /* Line 647 of yacc.c  */
-#line 1125 "../../src/parse-gram.c"
+#line 1113 "../../src/parse-gram.c"
         break;
 
-            case 88: // symbol
+            case 85: // symbol
 
 /* Line 647 of yacc.c  */
-#line 196 "parse-gram.y"
+#line 193 "parse-gram.y"
         { fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); }
 /* Line 647 of yacc.c  */
-#line 1134 "../../src/parse-gram.c"
+#line 1122 "../../src/parse-gram.c"
         break;
 
-            case 89: // string_as_id
+            case 86: // string_as_id
 
 /* Line 647 of yacc.c  */
-#line 196 "parse-gram.y"
+#line 193 "parse-gram.y"
         { fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); }
 /* Line 647 of yacc.c  */
-#line 1143 "../../src/parse-gram.c"
+#line 1131 "../../src/parse-gram.c"
         break;
 
       default:
@@ -1661,7 +1649,7 @@ YYLTYPE yylloc;
   boundary_set (&yylloc.end, current_file, 1, 1);
 }
 /* Line 1167 of yacc.c  */
-#line 1665 "../../src/parse-gram.c"
+#line 1653 "../../src/parse-gram.c"
   yylsp[0] = yylloc;
 
   goto yysetstate;
@@ -1848,7 +1836,7 @@ yyreduce:
     {
         case 6:
 /* Line 1380 of yacc.c  */
-#line 220 "parse-gram.y"
+#line 217 "parse-gram.y"
     {
       code_props plain_code;
       code_props_plain_init (&plain_code, (yyvsp[0].chars), (yylsp[0]));
@@ -1859,94 +1847,94 @@ yyreduce:
       code_scanner_last_string_free ();
     }
 /* Line 1380 of yacc.c  */
-#line 1863 "../../src/parse-gram.c"
+#line 1851 "../../src/parse-gram.c"
     break;
 
   case 7:
 /* Line 1380 of yacc.c  */
-#line 230 "parse-gram.y"
+#line 227 "parse-gram.y"
     {
       muscle_percent_define_ensure ((yyvsp[0].uniqstr), (yylsp[0]), true);
     }
 /* Line 1380 of yacc.c  */
-#line 1873 "../../src/parse-gram.c"
+#line 1861 "../../src/parse-gram.c"
     break;
 
   case 8:
 /* Line 1380 of yacc.c  */
-#line 234 "parse-gram.y"
+#line 231 "parse-gram.y"
     {
       muscle_percent_define_insert ((yyvsp[-1].uniqstr), (yylsp[-1]), (yyvsp[0].chars));
     }
 /* Line 1380 of yacc.c  */
-#line 1883 "../../src/parse-gram.c"
+#line 1871 "../../src/parse-gram.c"
     break;
 
   case 9:
 /* Line 1380 of yacc.c  */
-#line 237 "parse-gram.y"
+#line 234 "parse-gram.y"
     { defines_flag = true; }
 /* Line 1380 of yacc.c  */
-#line 1891 "../../src/parse-gram.c"
+#line 1879 "../../src/parse-gram.c"
     break;
 
   case 10:
 /* Line 1380 of yacc.c  */
-#line 239 "parse-gram.y"
+#line 236 "parse-gram.y"
     {
       defines_flag = true;
       spec_defines_file = xstrdup ((yyvsp[0].chars));
     }
 /* Line 1380 of yacc.c  */
-#line 1902 "../../src/parse-gram.c"
+#line 1890 "../../src/parse-gram.c"
     break;
 
   case 11:
 /* Line 1380 of yacc.c  */
-#line 243 "parse-gram.y"
+#line 240 "parse-gram.y"
     { expected_sr_conflicts = (yyvsp[0].integer); }
 /* Line 1380 of yacc.c  */
-#line 1910 "../../src/parse-gram.c"
+#line 1898 "../../src/parse-gram.c"
     break;
 
   case 12:
 /* Line 1380 of yacc.c  */
-#line 244 "parse-gram.y"
+#line 241 "parse-gram.y"
     { expected_rr_conflicts = (yyvsp[0].integer); }
 /* Line 1380 of yacc.c  */
-#line 1918 "../../src/parse-gram.c"
+#line 1906 "../../src/parse-gram.c"
     break;
 
   case 13:
 /* Line 1380 of yacc.c  */
-#line 245 "parse-gram.y"
+#line 242 "parse-gram.y"
     { spec_file_prefix = (yyvsp[0].chars); }
 /* Line 1380 of yacc.c  */
-#line 1926 "../../src/parse-gram.c"
+#line 1914 "../../src/parse-gram.c"
     break;
 
   case 14:
 /* Line 1380 of yacc.c  */
-#line 246 "parse-gram.y"
+#line 243 "parse-gram.y"
     { spec_file_prefix = (yyvsp[0].chars); }
 /* Line 1380 of yacc.c  */
-#line 1934 "../../src/parse-gram.c"
+#line 1922 "../../src/parse-gram.c"
     break;
 
   case 15:
 /* Line 1380 of yacc.c  */
-#line 248 "parse-gram.y"
+#line 245 "parse-gram.y"
     {
       nondeterministic_parser = true;
       glr_parser = true;
     }
 /* Line 1380 of yacc.c  */
-#line 1945 "../../src/parse-gram.c"
+#line 1933 "../../src/parse-gram.c"
     break;
 
   case 16:
 /* Line 1380 of yacc.c  */
-#line 253 "parse-gram.y"
+#line 250 "parse-gram.y"
     {
       code_props action;
       code_props_symbol_action_init (&action, (yyvsp[0].code), (yylsp[0]));
@@ -1956,100 +1944,92 @@ yyreduce:
       code_scanner_last_string_free ();
     }
 /* Line 1380 of yacc.c  */
-#line 1960 "../../src/parse-gram.c"
+#line 1948 "../../src/parse-gram.c"
     break;
 
   case 17:
 /* Line 1380 of yacc.c  */
-#line 261 "parse-gram.y"
+#line 258 "parse-gram.y"
     { language_argmatch ((yyvsp[0].chars), grammar_prio, (yylsp[-1])); }
 /* Line 1380 of yacc.c  */
-#line 1968 "../../src/parse-gram.c"
+#line 1956 "../../src/parse-gram.c"
     break;
 
   case 18:
 /* Line 1380 of yacc.c  */
-#line 262 "parse-gram.y"
+#line 259 "parse-gram.y"
     { add_param ("lex_param", (yyvsp[0].code), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 1976 "../../src/parse-gram.c"
+#line 1964 "../../src/parse-gram.c"
     break;
 
   case 19:
 /* Line 1380 of yacc.c  */
-#line 263 "parse-gram.y"
-    { locations_flag = true; }
+#line 260 "parse-gram.y"
+    { spec_name_prefix = (yyvsp[0].chars); }
 /* Line 1380 of yacc.c  */
-#line 1984 "../../src/parse-gram.c"
+#line 1972 "../../src/parse-gram.c"
     break;
 
   case 20:
 /* Line 1380 of yacc.c  */
-#line 264 "parse-gram.y"
+#line 261 "parse-gram.y"
     { spec_name_prefix = (yyvsp[0].chars); }
 /* Line 1380 of yacc.c  */
-#line 1992 "../../src/parse-gram.c"
+#line 1980 "../../src/parse-gram.c"
     break;
 
   case 21:
 /* Line 1380 of yacc.c  */
-#line 265 "parse-gram.y"
-    { spec_name_prefix = (yyvsp[0].chars); }
+#line 262 "parse-gram.y"
+    { no_lines_flag = true; }
 /* Line 1380 of yacc.c  */
-#line 2000 "../../src/parse-gram.c"
+#line 1988 "../../src/parse-gram.c"
     break;
 
   case 22:
 /* Line 1380 of yacc.c  */
-#line 266 "parse-gram.y"
-    { no_lines_flag = true; }
+#line 263 "parse-gram.y"
+    { nondeterministic_parser = true; }
 /* Line 1380 of yacc.c  */
-#line 2008 "../../src/parse-gram.c"
+#line 1996 "../../src/parse-gram.c"
     break;
 
   case 23:
 /* Line 1380 of yacc.c  */
-#line 267 "parse-gram.y"
-    { nondeterministic_parser = true; }
+#line 264 "parse-gram.y"
+    { spec_outfile = (yyvsp[0].chars); }
 /* Line 1380 of yacc.c  */
-#line 2016 "../../src/parse-gram.c"
+#line 2004 "../../src/parse-gram.c"
     break;
 
   case 24:
 /* Line 1380 of yacc.c  */
-#line 268 "parse-gram.y"
+#line 265 "parse-gram.y"
     { spec_outfile = (yyvsp[0].chars); }
 /* Line 1380 of yacc.c  */
-#line 2024 "../../src/parse-gram.c"
+#line 2012 "../../src/parse-gram.c"
     break;
 
   case 25:
 /* Line 1380 of yacc.c  */
-#line 269 "parse-gram.y"
-    { spec_outfile = (yyvsp[0].chars); }
-/* Line 1380 of yacc.c  */
-#line 2032 "../../src/parse-gram.c"
-    break;
-
-  case 26:
-/* Line 1380 of yacc.c  */
-#line 270 "parse-gram.y"
+#line 266 "parse-gram.y"
     { add_param ("parse_param", (yyvsp[0].code), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2040 "../../src/parse-gram.c"
+#line 2020 "../../src/parse-gram.c"
     break;
 
-  case 27:
+  case 26:
 /* Line 1380 of yacc.c  */
-#line 271 "parse-gram.y"
+#line 267 "parse-gram.y"
     { version_check (&(yylsp[0]), (yyvsp[0].chars)); }
 /* Line 1380 of yacc.c  */
-#line 2048 "../../src/parse-gram.c"
+#line 2028 "../../src/parse-gram.c"
     break;
 
-  case 28:
+  case 27:
 /* Line 1380 of yacc.c  */
-#line 273 "parse-gram.y"
+#line 269 "parse-gram.y"
     {
       char const *skeleton_user = (yyvsp[0].chars);
       if (strchr (skeleton_user, '/'))
@@ -2074,46 +2054,46 @@ yyreduce:
       skeleton_arg (skeleton_user, grammar_prio, (yylsp[-1]));
     }
 /* Line 1380 of yacc.c  */
-#line 2078 "../../src/parse-gram.c"
+#line 2058 "../../src/parse-gram.c"
     break;
 
-  case 29:
+  case 28:
 /* Line 1380 of yacc.c  */
-#line 296 "parse-gram.y"
+#line 292 "parse-gram.y"
     { token_table_flag = true; }
 /* Line 1380 of yacc.c  */
-#line 2086 "../../src/parse-gram.c"
+#line 2066 "../../src/parse-gram.c"
     break;
 
-  case 30:
+  case 29:
 /* Line 1380 of yacc.c  */
-#line 297 "parse-gram.y"
+#line 293 "parse-gram.y"
     { report_flag |= report_states; }
 /* Line 1380 of yacc.c  */
-#line 2094 "../../src/parse-gram.c"
+#line 2074 "../../src/parse-gram.c"
     break;
 
-  case 31:
+  case 30:
 /* Line 1380 of yacc.c  */
-#line 298 "parse-gram.y"
+#line 294 "parse-gram.y"
     { yacc_flag = true; }
 /* Line 1380 of yacc.c  */
-#line 2102 "../../src/parse-gram.c"
+#line 2082 "../../src/parse-gram.c"
     break;
 
-  case 35:
+  case 34:
 /* Line 1380 of yacc.c  */
-#line 306 "parse-gram.y"
+#line 302 "parse-gram.y"
     {
       grammar_start_symbol_set ((yyvsp[0].symbol), (yylsp[0]));
     }
 /* Line 1380 of yacc.c  */
-#line 2112 "../../src/parse-gram.c"
+#line 2092 "../../src/parse-gram.c"
     break;
 
-  case 36:
+  case 35:
 /* Line 1380 of yacc.c  */
-#line 310 "parse-gram.y"
+#line 306 "parse-gram.y"
     {
       symbol_list *list;
       for (list = (yyvsp[0].list); list; list = list->next)
@@ -2121,12 +2101,12 @@ yyreduce:
       symbol_list_free ((yyvsp[0].list));
     }
 /* Line 1380 of yacc.c  */
-#line 2125 "../../src/parse-gram.c"
+#line 2105 "../../src/parse-gram.c"
     break;
 
-  case 37:
+  case 36:
 /* Line 1380 of yacc.c  */
-#line 317 "parse-gram.y"
+#line 313 "parse-gram.y"
     {
       symbol_list *list;
       for (list = (yyvsp[0].list); list; list = list->next)
@@ -2134,32 +2114,32 @@ yyreduce:
       symbol_list_free ((yyvsp[0].list));
     }
 /* Line 1380 of yacc.c  */
-#line 2138 "../../src/parse-gram.c"
+#line 2118 "../../src/parse-gram.c"
     break;
 
-  case 38:
+  case 37:
 /* Line 1380 of yacc.c  */
-#line 324 "parse-gram.y"
+#line 320 "parse-gram.y"
     {
       default_prec = true;
     }
 /* Line 1380 of yacc.c  */
-#line 2148 "../../src/parse-gram.c"
+#line 2128 "../../src/parse-gram.c"
     break;
 
-  case 39:
+  case 38:
 /* Line 1380 of yacc.c  */
-#line 328 "parse-gram.y"
+#line 324 "parse-gram.y"
     {
       default_prec = false;
     }
 /* Line 1380 of yacc.c  */
-#line 2158 "../../src/parse-gram.c"
+#line 2138 "../../src/parse-gram.c"
     break;
 
-  case 40:
+  case 39:
 /* Line 1380 of yacc.c  */
-#line 332 "parse-gram.y"
+#line 328 "parse-gram.y"
     {
       /* Do not invoke muscle_percent_code_grow here since it invokes
          muscle_user_name_list_grow.  */
@@ -2167,89 +2147,89 @@ yyreduce:
       code_scanner_last_string_free ();
     }
 /* Line 1380 of yacc.c  */
-#line 2171 "../../src/parse-gram.c"
+#line 2151 "../../src/parse-gram.c"
     break;
 
-  case 41:
+  case 40:
 /* Line 1380 of yacc.c  */
-#line 339 "parse-gram.y"
+#line 335 "parse-gram.y"
     {
       muscle_percent_code_grow ((yyvsp[-1].uniqstr), (yylsp[-1]), (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
 /* Line 1380 of yacc.c  */
-#line 2182 "../../src/parse-gram.c"
+#line 2162 "../../src/parse-gram.c"
     break;
 
-  case 42:
+  case 41:
 /* Line 1380 of yacc.c  */
-#line 353 "parse-gram.y"
+#line 349 "parse-gram.y"
     {}
 /* Line 1380 of yacc.c  */
-#line 2190 "../../src/parse-gram.c"
+#line 2170 "../../src/parse-gram.c"
     break;
 
-  case 43:
+  case 42:
 /* Line 1380 of yacc.c  */
-#line 354 "parse-gram.y"
+#line 350 "parse-gram.y"
     { muscle_code_grow ("union_name", (yyvsp[0].uniqstr), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2198 "../../src/parse-gram.c"
+#line 2178 "../../src/parse-gram.c"
     break;
 
-  case 44:
+  case 43:
 /* Line 1380 of yacc.c  */
-#line 359 "parse-gram.y"
+#line 355 "parse-gram.y"
     {
       union_seen = true;
       muscle_code_grow ("stype", (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
 /* Line 1380 of yacc.c  */
-#line 2210 "../../src/parse-gram.c"
+#line 2190 "../../src/parse-gram.c"
     break;
 
-  case 45:
+  case 44:
 /* Line 1380 of yacc.c  */
-#line 370 "parse-gram.y"
+#line 366 "parse-gram.y"
     { current_class = nterm_sym; }
 /* Line 1380 of yacc.c  */
-#line 2218 "../../src/parse-gram.c"
+#line 2198 "../../src/parse-gram.c"
     break;
 
-  case 46:
+  case 45:
 /* Line 1380 of yacc.c  */
-#line 371 "parse-gram.y"
+#line 367 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
 /* Line 1380 of yacc.c  */
-#line 2229 "../../src/parse-gram.c"
+#line 2209 "../../src/parse-gram.c"
     break;
 
-  case 47:
+  case 46:
 /* Line 1380 of yacc.c  */
-#line 375 "parse-gram.y"
+#line 371 "parse-gram.y"
     { current_class = token_sym; }
 /* Line 1380 of yacc.c  */
-#line 2237 "../../src/parse-gram.c"
+#line 2217 "../../src/parse-gram.c"
     break;
 
-  case 48:
+  case 47:
 /* Line 1380 of yacc.c  */
-#line 376 "parse-gram.y"
+#line 372 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
 /* Line 1380 of yacc.c  */
-#line 2248 "../../src/parse-gram.c"
+#line 2228 "../../src/parse-gram.c"
     break;
 
-  case 49:
+  case 48:
 /* Line 1380 of yacc.c  */
-#line 381 "parse-gram.y"
+#line 377 "parse-gram.y"
     {
       symbol_list *list;
       tag_seen = true;
@@ -2258,12 +2238,12 @@ yyreduce:
       symbol_list_free ((yyvsp[0].list));
     }
 /* Line 1380 of yacc.c  */
-#line 2262 "../../src/parse-gram.c"
+#line 2242 "../../src/parse-gram.c"
     break;
 
-  case 50:
+  case 49:
 /* Line 1380 of yacc.c  */
-#line 392 "parse-gram.y"
+#line 388 "parse-gram.y"
     {
       symbol_list *list;
       ++current_prec;
@@ -2276,202 +2256,202 @@ yyreduce:
       current_type = NULL;
     }
 /* Line 1380 of yacc.c  */
-#line 2280 "../../src/parse-gram.c"
+#line 2260 "../../src/parse-gram.c"
     break;
 
-  case 51:
+  case 50:
 /* Line 1380 of yacc.c  */
-#line 406 "parse-gram.y"
+#line 402 "parse-gram.y"
     { (yyval.assoc) = left_assoc; }
 /* Line 1380 of yacc.c  */
-#line 2288 "../../src/parse-gram.c"
+#line 2268 "../../src/parse-gram.c"
     break;
 
-  case 52:
+  case 51:
 /* Line 1380 of yacc.c  */
-#line 407 "parse-gram.y"
+#line 403 "parse-gram.y"
     { (yyval.assoc) = right_assoc; }
 /* Line 1380 of yacc.c  */
-#line 2296 "../../src/parse-gram.c"
+#line 2276 "../../src/parse-gram.c"
     break;
 
-  case 53:
+  case 52:
 /* Line 1380 of yacc.c  */
-#line 408 "parse-gram.y"
+#line 404 "parse-gram.y"
     { (yyval.assoc) = non_assoc; }
 /* Line 1380 of yacc.c  */
-#line 2304 "../../src/parse-gram.c"
+#line 2284 "../../src/parse-gram.c"
     break;
 
-  case 54:
+  case 53:
 /* Line 1380 of yacc.c  */
-#line 409 "parse-gram.y"
+#line 405 "parse-gram.y"
     { (yyval.assoc) = precedence_assoc; }
 /* Line 1380 of yacc.c  */
-#line 2312 "../../src/parse-gram.c"
+#line 2292 "../../src/parse-gram.c"
     break;
 
-  case 55:
+  case 54:
 /* Line 1380 of yacc.c  */
-#line 413 "parse-gram.y"
+#line 409 "parse-gram.y"
     { current_type = NULL; }
 /* Line 1380 of yacc.c  */
-#line 2320 "../../src/parse-gram.c"
+#line 2300 "../../src/parse-gram.c"
     break;
 
-  case 56:
+  case 55:
 /* Line 1380 of yacc.c  */
-#line 414 "parse-gram.y"
+#line 410 "parse-gram.y"
     { current_type = (yyvsp[0].uniqstr); tag_seen = true; }
 /* Line 1380 of yacc.c  */
-#line 2328 "../../src/parse-gram.c"
+#line 2308 "../../src/parse-gram.c"
     break;
 
-  case 57:
+  case 56:
 /* Line 1380 of yacc.c  */
-#line 420 "parse-gram.y"
+#line 416 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2336 "../../src/parse-gram.c"
+#line 2316 "../../src/parse-gram.c"
     break;
 
-  case 58:
+  case 57:
 /* Line 1380 of yacc.c  */
-#line 422 "parse-gram.y"
+#line 418 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
 /* Line 1380 of yacc.c  */
-#line 2344 "../../src/parse-gram.c"
+#line 2324 "../../src/parse-gram.c"
     break;
 
-  case 59:
+  case 58:
 /* Line 1380 of yacc.c  */
-#line 426 "parse-gram.y"
+#line 422 "parse-gram.y"
     { (yyval.symbol) = (yyvsp[0].symbol); }
 /* Line 1380 of yacc.c  */
-#line 2352 "../../src/parse-gram.c"
+#line 2332 "../../src/parse-gram.c"
     break;
 
-  case 60:
+  case 59:
 /* Line 1380 of yacc.c  */
-#line 427 "parse-gram.y"
+#line 423 "parse-gram.y"
     { (yyval.symbol) = (yyvsp[-1].symbol); symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2360 "../../src/parse-gram.c"
+#line 2340 "../../src/parse-gram.c"
     break;
 
-  case 61:
+  case 60:
 /* Line 1380 of yacc.c  */
-#line 433 "parse-gram.y"
+#line 429 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2368 "../../src/parse-gram.c"
+#line 2348 "../../src/parse-gram.c"
     break;
 
-  case 62:
+  case 61:
 /* Line 1380 of yacc.c  */
-#line 435 "parse-gram.y"
+#line 431 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
 /* Line 1380 of yacc.c  */
-#line 2376 "../../src/parse-gram.c"
+#line 2356 "../../src/parse-gram.c"
     break;
 
-  case 63:
+  case 62:
 /* Line 1380 of yacc.c  */
-#line 439 "parse-gram.y"
+#line 435 "parse-gram.y"
     { (yyval.list) = (yyvsp[0].list); }
 /* Line 1380 of yacc.c  */
-#line 2384 "../../src/parse-gram.c"
+#line 2364 "../../src/parse-gram.c"
     break;
 
-  case 64:
+  case 63:
 /* Line 1380 of yacc.c  */
-#line 440 "parse-gram.y"
+#line 436 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), (yyvsp[0].list)); }
 /* Line 1380 of yacc.c  */
-#line 2392 "../../src/parse-gram.c"
+#line 2372 "../../src/parse-gram.c"
     break;
 
-  case 65:
+  case 64:
 /* Line 1380 of yacc.c  */
-#line 444 "parse-gram.y"
+#line 440 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2400 "../../src/parse-gram.c"
+#line 2380 "../../src/parse-gram.c"
     break;
 
-  case 66:
+  case 65:
 /* Line 1380 of yacc.c  */
-#line 445 "parse-gram.y"
+#line 441 "parse-gram.y"
     { (yyval.list) = symbol_list_type_new ((yyvsp[0].uniqstr), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2408 "../../src/parse-gram.c"
+#line 2388 "../../src/parse-gram.c"
     break;
 
-  case 67:
+  case 66:
 /* Line 1380 of yacc.c  */
-#line 446 "parse-gram.y"
+#line 442 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagged_new ((yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2416 "../../src/parse-gram.c"
+#line 2396 "../../src/parse-gram.c"
     break;
 
-  case 68:
+  case 67:
 /* Line 1380 of yacc.c  */
-#line 447 "parse-gram.y"
+#line 443 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagless_new ((yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2424 "../../src/parse-gram.c"
+#line 2404 "../../src/parse-gram.c"
     break;
 
-  case 69:
+  case 68:
 /* Line 1380 of yacc.c  */
-#line 453 "parse-gram.y"
+#line 449 "parse-gram.y"
     {
        current_type = (yyvsp[0].uniqstr);
        tag_seen = true;
      }
 /* Line 1380 of yacc.c  */
-#line 2435 "../../src/parse-gram.c"
+#line 2415 "../../src/parse-gram.c"
     break;
 
-  case 70:
+  case 69:
 /* Line 1380 of yacc.c  */
-#line 458 "parse-gram.y"
+#line 454 "parse-gram.y"
     {
        symbol_class_set ((yyvsp[0].symbol), current_class, (yylsp[0]), true);
        symbol_type_set ((yyvsp[0].symbol), current_type, (yylsp[0]));
      }
 /* Line 1380 of yacc.c  */
-#line 2446 "../../src/parse-gram.c"
+#line 2426 "../../src/parse-gram.c"
     break;
 
-  case 71:
+  case 70:
 /* Line 1380 of yacc.c  */
-#line 463 "parse-gram.y"
+#line 459 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[-1].symbol), current_class, (yylsp[-1]), true);
       symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
       symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0]));
     }
 /* Line 1380 of yacc.c  */
-#line 2458 "../../src/parse-gram.c"
+#line 2438 "../../src/parse-gram.c"
     break;
 
-  case 72:
+  case 71:
 /* Line 1380 of yacc.c  */
-#line 469 "parse-gram.y"
+#line 465 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[-1].symbol), current_class, (yylsp[-1]), true);
       symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
       symbol_make_alias ((yyvsp[-1].symbol), (yyvsp[0].symbol), (yyloc));
     }
 /* Line 1380 of yacc.c  */
-#line 2470 "../../src/parse-gram.c"
+#line 2450 "../../src/parse-gram.c"
     break;
 
-  case 73:
+  case 72:
 /* Line 1380 of yacc.c  */
-#line 475 "parse-gram.y"
+#line 471 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[-2].symbol), current_class, (yylsp[-2]), true);
       symbol_type_set ((yyvsp[-2].symbol), current_type, (yylsp[-2]));
@@ -2479,112 +2459,112 @@ yyreduce:
       symbol_make_alias ((yyvsp[-2].symbol), (yyvsp[0].symbol), (yyloc));
     }
 /* Line 1380 of yacc.c  */
-#line 2483 "../../src/parse-gram.c"
+#line 2463 "../../src/parse-gram.c"
     break;
 
-  case 80:
+  case 79:
 /* Line 1380 of yacc.c  */
-#line 505 "parse-gram.y"
+#line 501 "parse-gram.y"
     {
       yyerrok;
     }
 /* Line 1380 of yacc.c  */
-#line 2493 "../../src/parse-gram.c"
+#line 2473 "../../src/parse-gram.c"
     break;
 
-  case 81:
+  case 80:
 /* Line 1380 of yacc.c  */
-#line 511 "parse-gram.y"
+#line 507 "parse-gram.y"
     { current_lhs = (yyvsp[0].symbol); current_lhs_location = (yylsp[0]); }
 /* Line 1380 of yacc.c  */
-#line 2501 "../../src/parse-gram.c"
+#line 2481 "../../src/parse-gram.c"
     break;
 
-  case 83:
+  case 82:
 /* Line 1380 of yacc.c  */
-#line 515 "parse-gram.y"
+#line 511 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2509 "../../src/parse-gram.c"
+#line 2489 "../../src/parse-gram.c"
     break;
 
-  case 84:
+  case 83:
 /* Line 1380 of yacc.c  */
-#line 516 "parse-gram.y"
+#line 512 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2517 "../../src/parse-gram.c"
+#line 2497 "../../src/parse-gram.c"
     break;
 
-  case 86:
+  case 85:
 /* Line 1380 of yacc.c  */
-#line 522 "parse-gram.y"
+#line 518 "parse-gram.y"
     { grammar_current_rule_begin (current_lhs, current_lhs_location); }
 /* Line 1380 of yacc.c  */
-#line 2525 "../../src/parse-gram.c"
+#line 2505 "../../src/parse-gram.c"
     break;
 
-  case 87:
+  case 86:
 /* Line 1380 of yacc.c  */
-#line 524 "parse-gram.y"
+#line 520 "parse-gram.y"
     { grammar_current_rule_symbol_append ((yyvsp[0].symbol), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2533 "../../src/parse-gram.c"
+#line 2513 "../../src/parse-gram.c"
     break;
 
-  case 88:
+  case 87:
 /* Line 1380 of yacc.c  */
-#line 526 "parse-gram.y"
+#line 522 "parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[0].code), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2541 "../../src/parse-gram.c"
+#line 2521 "../../src/parse-gram.c"
     break;
 
-  case 89:
+  case 88:
 /* Line 1380 of yacc.c  */
-#line 528 "parse-gram.y"
+#line 524 "parse-gram.y"
     { grammar_current_rule_prec_set ((yyvsp[0].symbol), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2549 "../../src/parse-gram.c"
+#line 2529 "../../src/parse-gram.c"
     break;
 
-  case 90:
+  case 89:
 /* Line 1380 of yacc.c  */
-#line 530 "parse-gram.y"
+#line 526 "parse-gram.y"
     { grammar_current_rule_dprec_set ((yyvsp[0].integer), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2557 "../../src/parse-gram.c"
+#line 2537 "../../src/parse-gram.c"
     break;
 
-  case 91:
+  case 90:
 /* Line 1380 of yacc.c  */
-#line 532 "parse-gram.y"
+#line 528 "parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[0].uniqstr), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2565 "../../src/parse-gram.c"
+#line 2545 "../../src/parse-gram.c"
     break;
 
-  case 93:
+  case 92:
 /* Line 1380 of yacc.c  */
-#line 542 "parse-gram.y"
+#line 538 "parse-gram.y"
     { (yyval.uniqstr) = uniqstr_new ((yyvsp[0].chars)); }
 /* Line 1380 of yacc.c  */
-#line 2573 "../../src/parse-gram.c"
+#line 2553 "../../src/parse-gram.c"
     break;
 
-  case 94:
+  case 93:
 /* Line 1380 of yacc.c  */
-#line 548 "parse-gram.y"
+#line 544 "parse-gram.y"
     {
       (yyval.chars) = "";
     }
 /* Line 1380 of yacc.c  */
-#line 2583 "../../src/parse-gram.c"
+#line 2563 "../../src/parse-gram.c"
     break;
 
-  case 96:
+  case 95:
 /* Line 1380 of yacc.c  */
-#line 561 "parse-gram.y"
+#line 557 "parse-gram.y"
     {
       code_props plain_code;
       (yyvsp[0].code)[strlen ((yyvsp[0].code)) - 1] = '\n';
@@ -2594,51 +2574,51 @@ yyreduce:
       (yyval.chars) = plain_code.code;
     }
 /* Line 1380 of yacc.c  */
-#line 2598 "../../src/parse-gram.c"
+#line 2578 "../../src/parse-gram.c"
     break;
 
-  case 97:
+  case 96:
 /* Line 1380 of yacc.c  */
-#line 581 "parse-gram.y"
+#line 577 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2606 "../../src/parse-gram.c"
+#line 2586 "../../src/parse-gram.c"
     break;
 
-  case 98:
+  case 97:
 /* Line 1380 of yacc.c  */
-#line 583 "parse-gram.y"
+#line 579 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[0].character)), (yylsp[0]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
       symbol_user_token_number_set ((yyval.symbol), (yyvsp[0].character), (yylsp[0]));
     }
 /* Line 1380 of yacc.c  */
-#line 2618 "../../src/parse-gram.c"
+#line 2598 "../../src/parse-gram.c"
     break;
 
-  case 99:
+  case 98:
 /* Line 1380 of yacc.c  */
-#line 591 "parse-gram.y"
+#line 587 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2626 "../../src/parse-gram.c"
+#line 2606 "../../src/parse-gram.c"
     break;
 
-  case 102:
+  case 101:
 /* Line 1380 of yacc.c  */
-#line 603 "parse-gram.y"
+#line 599 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[0].chars)), (yylsp[0]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
     }
 /* Line 1380 of yacc.c  */
-#line 2637 "../../src/parse-gram.c"
+#line 2617 "../../src/parse-gram.c"
     break;
 
-  case 104:
+  case 103:
 /* Line 1380 of yacc.c  */
-#line 612 "parse-gram.y"
+#line 608 "parse-gram.y"
     {
       code_props plain_code;
       code_props_plain_init (&plain_code, (yyvsp[0].chars), (yylsp[0]));
@@ -2648,12 +2628,12 @@ yyreduce:
       code_scanner_last_string_free ();
     }
 /* Line 1380 of yacc.c  */
-#line 2652 "../../src/parse-gram.c"
+#line 2632 "../../src/parse-gram.c"
     break;
 
 
 /* Line 1380 of yacc.c  */
-#line 2657 "../../src/parse-gram.c"
+#line 2637 "../../src/parse-gram.c"
       default: break;
     }
   YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);
@@ -2870,7 +2850,7 @@ yyreturn:
 }
 
 /* Line 1599 of yacc.c  */
-#line 622 "parse-gram.y"
+#line 618 "parse-gram.y"
 
 
 
