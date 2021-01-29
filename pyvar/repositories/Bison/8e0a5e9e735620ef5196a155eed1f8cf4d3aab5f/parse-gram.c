@@ -76,7 +76,7 @@
 
 /* Copy the first part of user declarations.  */
 
-/* Line 167 of yacc.c  */
+/* Line 171 of yacc.c  */
 #line 1 "parse-gram.y"
 /* Bison Grammar Parser                             -*- C -*-
 
@@ -156,7 +156,7 @@ static int current_prec = 0;
 #define YYTYPE_UINT8 uint_fast8_t
 
 
-/* Line 167 of yacc.c  */
+/* Line 171 of yacc.c  */
 #line 161 "parse-gram.c"
 
 /* Enabling traces.  */
@@ -199,51 +199,48 @@ static int current_prec = 0;
      PERCENT_DPREC = 269,
      PERCENT_MERGE = 270,
      PERCENT_CODE = 271,
-     PERCENT_CODE_TOP = 272,
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
-     PERCENT_LANGUAGE = 283,
-     PERCENT_LEX_PARAM = 284,
-     PERCENT_LOCATIONS = 285,
-     PERCENT_NAME_PREFIX = 286,
-     PERCENT_NO_DEFAULT_PREC = 287,
-     PERCENT_NO_LINES = 288,
-     PERCENT_NONDETERMINISTIC_PARSER = 289,
-     PERCENT_OUTPUT = 290,
-     PERCENT_PARSE_PARAM = 291,
-     PERCENT_PROVIDES = 292,
-     PERCENT_PURE_PARSER = 293,
-     PERCENT_PUSH_PARSER = 294,
-     PERCENT_PUSH_PULL_PARSER = 295,
-     PERCENT_REQUIRE = 296,
-     PERCENT_REQUIRES = 297,
-     PERCENT_SKELETON = 298,
-     PERCENT_START = 299,
-     PERCENT_TOKEN_TABLE = 300,
-     PERCENT_VERBOSE = 301,
-     PERCENT_YACC = 302,
-     BRACED_CODE = 303,
-     CHAR = 304,
-     EPILOGUE = 305,
-     EQUAL = 306,
-     ID = 307,
-     ID_COLON = 308,
-     PERCENT_PERCENT = 309,
-     PIPE = 310,
-     PROLOGUE = 311,
-     SEMICOLON = 312,
-     TYPE = 313,
-     TYPE_TAG_ANY = 314,
-     TYPE_TAG_NONE = 315,
-     PERCENT_UNION = 316
+     PERCENT_DEBUG = 272,
+     PERCENT_DEFAULT_PREC = 273,
+     PERCENT_DEFINE = 274,
+     PERCENT_DEFINES = 275,
+     PERCENT_ERROR_VERBOSE = 276,
+     PERCENT_EXPECT = 277,
+     PERCENT_EXPECT_RR = 278,
+     PERCENT_FILE_PREFIX = 279,
+     PERCENT_GLR_PARSER = 280,
+     PERCENT_INITIAL_ACTION = 281,
+     PERCENT_LANGUAGE = 282,
+     PERCENT_LEX_PARAM = 283,
+     PERCENT_LOCATIONS = 284,
+     PERCENT_NAME_PREFIX = 285,
+     PERCENT_NO_DEFAULT_PREC = 286,
+     PERCENT_NO_LINES = 287,
+     PERCENT_NONDETERMINISTIC_PARSER = 288,
+     PERCENT_OUTPUT = 289,
+     PERCENT_PARSE_PARAM = 290,
+     PERCENT_PURE_PARSER = 291,
+     PERCENT_PUSH_PARSER = 292,
+     PERCENT_PUSH_PULL_PARSER = 293,
+     PERCENT_REQUIRE = 294,
+     PERCENT_SKELETON = 295,
+     PERCENT_START = 296,
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
+     TYPE_TAG_ANY = 311,
+     TYPE_TAG_NONE = 312,
+     PERCENT_UNION = 313
    };
 #endif
 /* Tokens.  */
@@ -262,51 +259,48 @@ static int current_prec = 0;
 #define PERCENT_DPREC 269
 #define PERCENT_MERGE 270
 #define PERCENT_CODE 271
-#define PERCENT_CODE_TOP 272
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
-#define PERCENT_LANGUAGE 283
-#define PERCENT_LEX_PARAM 284
-#define PERCENT_LOCATIONS 285
-#define PERCENT_NAME_PREFIX 286
-#define PERCENT_NO_DEFAULT_PREC 287
-#define PERCENT_NO_LINES 288
-#define PERCENT_NONDETERMINISTIC_PARSER 289
-#define PERCENT_OUTPUT 290
-#define PERCENT_PARSE_PARAM 291
-#define PERCENT_PROVIDES 292
-#define PERCENT_PURE_PARSER 293
-#define PERCENT_PUSH_PARSER 294
-#define PERCENT_PUSH_PULL_PARSER 295
-#define PERCENT_REQUIRE 296
-#define PERCENT_REQUIRES 297
-#define PERCENT_SKELETON 298
-#define PERCENT_START 299
-#define PERCENT_TOKEN_TABLE 300
-#define PERCENT_VERBOSE 301
-#define PERCENT_YACC 302
-#define BRACED_CODE 303
-#define CHAR 304
-#define EPILOGUE 305
-#define EQUAL 306
-#define ID 307
-#define ID_COLON 308
-#define PERCENT_PERCENT 309
-#define PIPE 310
-#define PROLOGUE 311
-#define SEMICOLON 312
-#define TYPE 313
-#define TYPE_TAG_ANY 314
-#define TYPE_TAG_NONE 315
-#define PERCENT_UNION 316
+#define PERCENT_DEBUG 272
+#define PERCENT_DEFAULT_PREC 273
+#define PERCENT_DEFINE 274
+#define PERCENT_DEFINES 275
+#define PERCENT_ERROR_VERBOSE 276
+#define PERCENT_EXPECT 277
+#define PERCENT_EXPECT_RR 278
+#define PERCENT_FILE_PREFIX 279
+#define PERCENT_GLR_PARSER 280
+#define PERCENT_INITIAL_ACTION 281
+#define PERCENT_LANGUAGE 282
+#define PERCENT_LEX_PARAM 283
+#define PERCENT_LOCATIONS 284
+#define PERCENT_NAME_PREFIX 285
+#define PERCENT_NO_DEFAULT_PREC 286
+#define PERCENT_NO_LINES 287
+#define PERCENT_NONDETERMINISTIC_PARSER 288
+#define PERCENT_OUTPUT 289
+#define PERCENT_PARSE_PARAM 290
+#define PERCENT_PURE_PARSER 291
+#define PERCENT_PUSH_PARSER 292
+#define PERCENT_PUSH_PULL_PARSER 293
+#define PERCENT_REQUIRE 294
+#define PERCENT_SKELETON 295
+#define PERCENT_START 296
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
+#define TYPE_TAG_ANY 311
+#define TYPE_TAG_NONE 312
+#define PERCENT_UNION 313
 
 
 
@@ -314,7 +308,7 @@ static int current_prec = 0;
 #if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
 typedef union YYSTYPE
 {
-/* Line 201 of yacc.c  */
+/* Line 205 of yacc.c  */
 #line 98 "parse-gram.y"
 
   symbol *symbol;
@@ -327,8 +321,8 @@ typedef union YYSTYPE
   unsigned char character;
 }
 
-/* Line 201 of yacc.c  */
-#line 332 "parse-gram.c"
+/* Line 205 of yacc.c  */
+#line 326 "parse-gram.c"
 	YYSTYPE;
 # define YYSTYPE_IS_TRIVIAL 1
 # define yystype YYSTYPE /* obsolescent; will be withdrawn */
@@ -352,8 +346,8 @@ typedef struct YYLTYPE
 /* Copy the second part of user declarations.  */
 
 
-/* Line 224 of yacc.c  */
-#line 357 "parse-gram.c"
+/* Line 228 of yacc.c  */
+#line 351 "parse-gram.c"
 
 #ifdef short
 # undef short
@@ -570,20 +564,20 @@ union yyalloc
 /* YYFINAL -- State number of the termination state.  */
 #define YYFINAL  3
 /* YYLAST -- Last index in YYTABLE.  */
-#define YYLAST   224
+#define YYLAST   187
 
 /* YYNTOKENS -- Number of terminals.  */
-#define YYNTOKENS  62
+#define YYNTOKENS  59
 /* YYNNTS -- Number of nonterminals.  */
 #define YYNNTS  31
 /* YYNRULES -- Number of rules.  */
-#define YYNRULES  105
+#define YYNRULES  103
 /* YYNRULES -- Number of states.  */
-#define YYNSTATES  145
+#define YYNSTATES  141
 
 /* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
 #define YYUNDEFTOK  2
-#define YYMAXUTOK   316
+#define YYMAXUTOK   313
 
 #define YYTRANSLATE(YYX)						\
   ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)
@@ -622,7 +616,7 @@ static const yytype_uint8 yytranslate[] =
       25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
       35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
       45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
-      55,    56,    57,    58,    59,    60,    61
+      55,    56,    57,    58
 };
 
 #if YYDEBUG
@@ -634,61 +628,61 @@ static const yytype_uint16 yyprhs[] =
       24,    27,    29,    32,    35,    38,    42,    44,    47,    50,
       53,    55,    58,    62,    64,    66,    69,    73,    76,    78,
       80,    82,    85,    88,    90,    92,    94,    96,    98,   100,
-     103,   107,   111,   113,   115,   118,   121,   124,   127,   128,
-     130,   134,   135,   139,   140,   144,   148,   152,   154,   156,
-     158,   159,   161,   163,   166,   168,   171,   173,   175,   177,
-     179,   181,   183,   186,   189,   193,   195,   198,   200,   203,
-     205,   208,   211,   212,   216,   218,   222,   225,   226,   229,
-     232,   236,   240,   244,   246,   248,   249,   251,   253,   255,
-     257,   259,   261,   263,   265,   266
+     103,   107,   111,   113,   115,   118,   122,   123,   125,   129,
+     130,   134,   135,   139,   143,   147,   149,   151,   153,   154,
+     156,   158,   161,   163,   166,   168,   170,   172,   174,   176,
+     178,   181,   184,   188,   190,   193,   195,   198,   200,   203,
+     206,   207,   211,   213,   217,   220,   221,   224,   227,   231,
+     235,   239,   241,   243,   244,   246,   248,   250,   252,   254,
+     256,   258,   260,   261
 };
 
 /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
 static const yytype_int8 yyrhs[] =
 {
-      63,     0,    -1,    64,    54,    79,    92,    -1,    -1,    64,
-      65,    -1,    66,    -1,    56,    -1,    18,    -1,    20,     3,
-      86,    -1,    21,    -1,    21,     3,    -1,    22,    -1,    23,
-       4,    -1,    24,     4,    -1,    25,     3,    -1,    25,    51,
-       3,    -1,    26,    -1,    27,    48,    -1,    28,     3,    -1,
-      29,    48,    -1,    30,    -1,    31,     3,    -1,    31,    51,
-       3,    -1,    33,    -1,    34,    -1,    35,     3,    -1,    35,
-      51,     3,    -1,    36,    48,    -1,    38,    -1,    39,    -1,
-      40,    -1,    41,     3,    -1,    43,     3,    -1,    45,    -1,
-      46,    -1,    47,    -1,    57,    -1,    71,    -1,    68,    -1,
-      44,    90,    -1,     8,    48,    75,    -1,     9,    48,    75,
-      -1,    19,    -1,    32,    -1,    16,    87,    -1,    17,    87,
-      -1,    37,    87,    -1,    42,    87,    -1,    -1,    52,    -1,
-      61,    67,    48,    -1,    -1,     6,    69,    78,    -1,    -1,
-       5,    70,    78,    -1,     7,    58,    74,    -1,    72,    73,
-      74,    -1,    10,    -1,    11,    -1,    12,    -1,    -1,    58,
-      -1,    90,    -1,    74,    90,    -1,    76,    -1,    75,    76,
-      -1,    90,    -1,    58,    -1,    59,    -1,    60,    -1,    58,
-      -1,    88,    -1,    88,     4,    -1,    88,    91,    -1,    88,
-       4,    91,    -1,    77,    -1,    78,    77,    -1,    80,    -1,
-      79,    80,    -1,    81,    -1,    66,    57,    -1,     1,    57,
-      -1,    -1,    89,    82,    83,    -1,    84,    -1,    83,    55,
-      84,    -1,    83,    57,    -1,    -1,    84,    90,    -1,    84,
-      48,    -1,    84,    13,    90,    -1,    84,    14,     4,    -1,
-      84,    15,    58,    -1,     3,    -1,    87,    -1,    -1,    85,
-      -1,    48,    -1,    52,    -1,    49,    -1,    53,    -1,    88,
-      -1,    91,    -1,     3,    -1,    -1,    54,    50,    -1
+      60,     0,    -1,    61,    51,    76,    89,    -1,    -1,    61,
+      62,    -1,    63,    -1,    53,    -1,    17,    -1,    19,     3,
+      83,    -1,    20,    -1,    20,     3,    -1,    21,    -1,    22,
+       4,    -1,    23,     4,    -1,    24,     3,    -1,    24,    48,
+       3,    -1,    25,    -1,    26,    45,    -1,    27,     3,    -1,
+      28,    45,    -1,    29,    -1,    30,     3,    -1,    30,    48,
+       3,    -1,    32,    -1,    33,    -1,    34,     3,    -1,    34,
+      48,     3,    -1,    35,    45,    -1,    36,    -1,    37,    -1,
+      38,    -1,    39,     3,    -1,    40,     3,    -1,    42,    -1,
+      43,    -1,    44,    -1,    54,    -1,    68,    -1,    65,    -1,
+      41,    87,    -1,     8,    45,    72,    -1,     9,    45,    72,
+      -1,    18,    -1,    31,    -1,    16,    84,    -1,    16,     3,
+      84,    -1,    -1,    49,    -1,    58,    64,    45,    -1,    -1,
+       6,    66,    75,    -1,    -1,     5,    67,    75,    -1,     7,
+      55,    71,    -1,    69,    70,    71,    -1,    10,    -1,    11,
+      -1,    12,    -1,    -1,    55,    -1,    87,    -1,    71,    87,
+      -1,    73,    -1,    72,    73,    -1,    87,    -1,    55,    -1,
+      56,    -1,    57,    -1,    55,    -1,    85,    -1,    85,     4,
+      -1,    85,    88,    -1,    85,     4,    88,    -1,    74,    -1,
+      75,    74,    -1,    77,    -1,    76,    77,    -1,    78,    -1,
+      63,    54,    -1,     1,    54,    -1,    -1,    86,    79,    80,
+      -1,    81,    -1,    80,    52,    81,    -1,    80,    54,    -1,
+      -1,    81,    87,    -1,    81,    45,    -1,    81,    13,    87,
+      -1,    81,    14,     4,    -1,    81,    15,    55,    -1,     3,
+      -1,    84,    -1,    -1,    82,    -1,    45,    -1,    49,    -1,
+      46,    -1,    50,    -1,    85,    -1,    88,    -1,     3,    -1,
+      -1,    51,    47,    -1
 };
 
 /* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
 static const yytype_uint16 yyrline[] =
 {
-       0,   214,   214,   222,   224,   228,   229,   238,   239,   240,
-     241,   246,   247,   248,   249,   250,   251,   256,   265,   266,
-     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
-     277,   278,   279,   280,   281,   282,   283,   287,   288,   289,
-     293,   300,   307,   311,   315,   316,   317,   318,   329,   330,
-     334,   363,   363,   368,   368,   373,   384,   399,   400,   401,
-     405,   406,   411,   413,   418,   419,   423,   424,   425,   426,
-     431,   436,   441,   447,   453,   464,   465,   474,   475,   481,
-     482,   483,   490,   490,   494,   495,   496,   501,   502,   504,
-     506,   508,   510,   520,   521,   527,   531,   536,   556,   558,
-     567,   572,   573,   578,   585,   587
+       0,   211,   211,   219,   221,   225,   226,   235,   236,   237,
+     238,   243,   244,   245,   246,   247,   248,   253,   262,   263,
+     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
+     274,   275,   276,   277,   278,   279,   280,   284,   285,   286,
+     290,   297,   304,   308,   312,   317,   338,   339,   343,   372,
+     372,   377,   377,   382,   393,   408,   409,   410,   414,   415,
+     420,   422,   427,   428,   432,   433,   434,   435,   440,   445,
+     450,   456,   462,   473,   474,   483,   484,   490,   491,   492,
+     499,   499,   503,   504,   505,   510,   511,   513,   515,   517,
+     519,   529,   530,   536,   540,   545,   565,   567,   576,   581,
+     582,   587,   594,   596
 };
 #endif
 
@@ -700,25 +694,25 @@ static const char *const yytname[] =
   "\"end of file\"", "error", "$undefined", "\"string\"", "\"integer\"",
   "\"%token\"", "\"%nterm\"", "\"%type\"", "\"%destructor\"",
   "\"%printer\"", "\"%left\"", "\"%right\"", "\"%nonassoc\"", "\"%prec\"",
-  "\"%dprec\"", "\"%merge\"", "\"%code\"", "\"%code-top\"", "\"%debug\"",
+  "\"%dprec\"", "\"%merge\"", "\"%code\"", "\"%debug\"",
   "\"%default-prec\"", "\"%define\"", "\"%defines\"", "\"%error-verbose\"",
   "\"%expect\"", "\"%expect-rr\"", "\"%file-prefix\"", "\"%glr-parser\"",
   "\"%initial-action\"", "\"%language\"", "\"%lex-param\"",
   "\"%locations\"", "\"%name-prefix\"", "\"%no-default-prec\"",
   "\"%no-lines\"", "\"%nondeterministic-parser\"", "\"%output\"",
-  "\"%parse-param\"", "\"%provides\"", "\"%pure-parser\"",
-  "\"%push-parser\"", "\"%push-pull-parser\"", "\"%require\"",
-  "\"%requires\"", "\"%skeleton\"", "\"%start\"", "\"%token-table\"",
-  "\"%verbose\"", "\"%yacc\"", "\"{...}\"", "\"char\"", "\"epilogue\"",
-  "\"=\"", "\"identifier\"", "\"identifier:\"", "\"%%\"", "\"|\"",
-  "\"%{...%}\"", "\";\"", "\"type\"", "\"<*>\"", "\"<>\"", "\"%union\"",
-  "$accept", "input", "prologue_declarations", "prologue_declaration",
-  "grammar_declaration", "union_name", "symbol_declaration", "$@1", "$@2",
-  "precedence_declaration", "precedence_declarator", "type.opt",
-  "symbols.1", "generic_symlist", "generic_symlist_item", "symbol_def",
-  "symbol_defs.1", "grammar", "rules_or_grammar_declaration", "rules",
-  "$@3", "rhses.1", "rhs", "content", "content.opt", "braceless", "id",
-  "id_colon", "symbol", "string_as_id", "epilogue.opt", 0
+  "\"%parse-param\"", "\"%pure-parser\"", "\"%push-parser\"",
+  "\"%push-pull-parser\"", "\"%require\"", "\"%skeleton\"", "\"%start\"",
+  "\"%token-table\"", "\"%verbose\"", "\"%yacc\"", "\"{...}\"", "\"char\"",
+  "\"epilogue\"", "\"=\"", "\"identifier\"", "\"identifier:\"", "\"%%\"",
+  "\"|\"", "\"%{...%}\"", "\";\"", "\"type\"", "\"<*>\"", "\"<>\"",
+  "\"%union\"", "$accept", "input", "prologue_declarations",
+  "prologue_declaration", "grammar_declaration", "union_name",
+  "symbol_declaration", "$@1", "$@2", "precedence_declaration",
+  "precedence_declarator", "type.opt", "symbols.1", "generic_symlist",
+  "generic_symlist_item", "symbol_def", "symbol_defs.1", "grammar",
+  "rules_or_grammar_declaration", "rules", "$@3", "rhses.1", "rhs",
+  "content", "content.opt", "braceless", "id", "id_colon", "symbol",
+  "string_as_id", "epilogue.opt", 0
 };
 #endif
 
@@ -732,25 +726,24 @@ static const yytype_uint16 yytoknum[] =
      275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
      285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
      295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
-     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
-     315,   316
+     305,   306,   307,   308,   309,   310,   311,   312,   313
 };
 # endif
 
 /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
 static const yytype_uint8 yyr1[] =
 {
-       0,    62,    63,    64,    64,    65,    65,    65,    65,    65,
-      65,    65,    65,    65,    65,    65,    65,    65,    65,    65,
-      65,    65,    65,    65,    65,    65,    65,    65,    65,    65,
-      65,    65,    65,    65,    65,    65,    65,    66,    66,    66,
-      66,    66,    66,    66,    66,    66,    66,    66,    67,    67,
-      66,    69,    68,    70,    68,    68,    71,    72,    72,    72,
-      73,    73,    74,    74,    75,    75,    76,    76,    76,    76,
-      77,    77,    77,    77,    77,    78,    78,    79,    79,    80,
-      80,    80,    82,    81,    83,    83,    83,    84,    84,    84,
-      84,    84,    84,    85,    85,    86,    86,    87,    88,    88,
-      89,    90,    90,    91,    92,    92
+       0,    59,    60,    61,    61,    62,    62,    62,    62,    62,
+      62,    62,    62,    62,    62,    62,    62,    62,    62,    62,
+      62,    62,    62,    62,    62,    62,    62,    62,    62,    62,
+      62,    62,    62,    62,    62,    62,    62,    63,    63,    63,
+      63,    63,    63,    63,    63,    63,    64,    64,    63,    66,
+      65,    67,    65,    65,    68,    69,    69,    69,    70,    70,
+      71,    71,    72,    72,    73,    73,    73,    73,    74,    74,
+      74,    74,    74,    75,    75,    76,    76,    77,    77,    77,
+      79,    78,    80,    80,    80,    81,    81,    81,    81,    81,
+      81,    82,    82,    83,    83,    84,    85,    85,    86,    87,
+      87,    88,    89,    89
 };
 
 /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
@@ -760,13 +753,13 @@ static const yytype_uint8 yyr2[] =
        2,     1,     2,     2,     2,     3,     1,     2,     2,     2,
        1,     2,     3,     1,     1,     2,     3,     2,     1,     1,
        1,     2,     2,     1,     1,     1,     1,     1,     1,     2,
-       3,     3,     1,     1,     2,     2,     2,     2,     0,     1,
-       3,     0,     3,     0,     3,     3,     3,     1,     1,     1,
-       0,     1,     1,     2,     1,     2,     1,     1,     1,     1,
-       1,     1,     2,     2,     3,     1,     2,     1,     2,     1,
-       2,     2,     0,     3,     1,     3,     2,     0,     2,     2,
-       3,     3,     3,     1,     1,     0,     1,     1,     1,     1,
-       1,     1,     1,     1,     0,     2
+       3,     3,     1,     1,     2,     3,     0,     1,     3,     0,
+       3,     0,     3,     3,     3,     1,     1,     1,     0,     1,
+       1,     2,     1,     2,     1,     1,     1,     1,     1,     1,
+       2,     2,     3,     1,     2,     1,     2,     1,     2,     2,
+       0,     3,     1,     3,     2,     0,     2,     2,     3,     3,
+       3,     1,     1,     0,     1,     1,     1,     1,     1,     1,
+       1,     1,     0,     2
 };
 
 /* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
@@ -774,141 +767,133 @@ static const yytype_uint8 yyr2[] =
    means the default is an error.  */
 static const yytype_uint8 yydefact[] =
 {
-       3,     0,     0,     1,    53,    51,     0,     0,     0,    57,
-      58,    59,     0,     0,     7,    42,     0,     9,    11,     0,
-       0,     0,    16,     0,     0,     0,    20,     0,    43,    23,
-      24,     0,     0,     0,    28,    29,    30,     0,     0,     0,
-       0,    33,    34,    35,     0,     6,    36,    48,     4,     5,
-      38,    37,    60,     0,     0,     0,     0,     0,    97,    44,
-      45,    95,    10,    12,    13,    14,     0,    17,    18,    19,
-      21,     0,    25,     0,    27,    46,    31,    47,    32,   103,
-      99,    98,   101,    39,   102,     0,   100,     0,     0,    77,
-      79,    82,    49,     0,    61,     0,    70,    75,    54,    71,
-      52,    55,    62,    67,    68,    69,    40,    64,    66,    41,
-      93,    96,     8,    94,    15,    22,    26,    81,    80,     0,
-      78,     2,    87,    50,    56,    76,    72,    73,    63,    65,
-     105,    83,    84,    74,    87,    86,     0,     0,     0,    89,
-      88,    85,    90,    91,    92
+       3,     0,     0,     1,    51,    49,     0,     0,     0,    55,
+      56,    57,     0,     7,    42,     0,     9,    11,     0,     0,
+       0,    16,     0,     0,     0,    20,     0,    43,    23,    24,
+       0,     0,    28,    29,    30,     0,     0,     0,    33,    34,
+      35,     0,     6,    36,    46,     4,     5,    38,    37,    58,
+       0,     0,     0,     0,     0,     0,    95,    44,    93,    10,
+      12,    13,    14,     0,    17,    18,    19,    21,     0,    25,
+       0,    27,    31,    32,   101,    97,    96,    99,    39,   100,
+       0,    98,     0,     0,    75,    77,    80,    47,     0,    59,
+       0,    68,    73,    52,    69,    50,    53,    60,    65,    66,
+      67,    40,    62,    64,    41,    45,    91,    94,     8,    92,
+      15,    22,    26,    79,    78,     0,    76,     2,    85,    48,
+      54,    74,    70,    71,    61,    63,   103,    81,    82,    72,
+      85,    84,     0,     0,     0,    87,    86,    83,    88,    89,
+      90
 };
 
 /* YYDEFGOTO[NTERM-NUM].  */
 static const yytype_int16 yydefgoto[] =
 {
-      -1,     1,     2,    48,    87,    93,    50,    54,    53,    51,
-      52,    95,   101,   106,   107,    97,    98,    88,    89,    90,
-     122,   131,   132,   111,   112,    59,    82,    91,   108,    84,
-     121
+      -1,     1,     2,    45,    82,    88,    47,    51,    50,    48,
+      49,    90,    96,   101,   102,    92,    93,    83,    84,    85,
+     118,   127,   128,   107,   108,    57,    77,    86,   103,    79,
+     117
 };
 
 /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
    STATE-NUM.  */
-#define YYPACT_NINF -100
+#define YYPACT_NINF -93
 static const yytype_int16 yypact[] =
 {
-    -100,     3,   127,  -100,  -100,  -100,   -50,   -22,   -11,  -100,
-    -100,  -100,    -3,    -3,  -100,  -100,    37,    43,  -100,    56,
-      59,     1,  -100,    19,    65,    21,  -100,    11,  -100,  -100,
-    -100,    13,    22,    -3,  -100,  -100,  -100,    71,    -3,    85,
-      -2,  -100,  -100,  -100,    70,  -100,  -100,    38,  -100,  -100,
-    -100,  -100,    33,   -17,   -17,    -2,    -1,    -1,  -100,  -100,
-    -100,    24,  -100,  -100,  -100,  -100,    90,  -100,  -100,  -100,
-    -100,    91,  -100,    92,  -100,  -100,  -100,  -100,  -100,  -100,
-    -100,  -100,  -100,  -100,  -100,    40,  -100,    41,    12,  -100,
-    -100,  -100,  -100,    51,  -100,    -2,  -100,  -100,   -17,    39,
-     -17,    -2,  -100,  -100,  -100,  -100,    -1,  -100,  -100,    -1,
-    -100,  -100,  -100,  -100,  -100,  -100,  -100,  -100,  -100,    50,
-    -100,  -100,  -100,  -100,    -2,  -100,   100,  -100,  -100,  -100,
-    -100,   -46,   172,  -100,  -100,  -100,    -2,   101,    46,  -100,
-    -100,   172,  -100,  -100,  -100
+     -93,    14,    96,   -93,   -93,   -93,    -4,    20,    30,   -93,
+     -93,   -93,    21,   -93,   -93,    73,    75,   -93,    76,    77,
+       6,   -93,    34,    79,    39,   -93,    22,   -93,   -93,   -93,
+      23,    41,   -93,   -93,   -93,    84,    85,    -2,   -93,   -93,
+     -93,    27,   -93,   -93,    40,   -93,   -93,   -93,   -93,    35,
+     -42,   -42,    -2,     0,     0,    47,   -93,   -93,    28,   -93,
+     -93,   -93,   -93,    90,   -93,   -93,   -93,   -93,    91,   -93,
+      93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,
+      43,   -93,    44,    11,   -93,   -93,   -93,   -93,    54,   -93,
+      -2,   -93,   -93,   -42,    37,   -42,    -2,   -93,   -93,   -93,
+     -93,     0,   -93,   -93,     0,   -93,   -93,   -93,   -93,   -93,
+     -93,   -93,   -93,   -93,   -93,    62,   -93,   -93,   -93,   -93,
+      -2,   -93,   107,   -93,   -93,   -93,   -93,   -44,   138,   -93,
+     -93,   -93,    -2,   139,    56,   -93,   -93,   138,   -93,   -93,
+     -93
 };
 
 /* YYPGOTO[NTERM-NUM].  */
-static const yytype_int8 yypgoto[] =
+static const yytype_int16 yypgoto[] =
 {
-    -100,  -100,  -100,  -100,   104,  -100,  -100,  -100,  -100,  -100,
-    -100,  -100,    14,    53,   -99,   -64,    54,  -100,    23,  -100,
-    -100,  -100,   -21,  -100,  -100,    -8,   -15,  -100,   -40,   -93,
-    -100
+     -93,   -93,   -93,   -93,   140,   -93,   -93,   -93,   -93,   -93,
+     -93,   -93,    55,    92,   -41,   -21,    97,   -93,    61,   -93,
+     -93,   -93,    25,   -93,   -93,     9,   -45,   -93,   -37,   -92,
+     -93
 };
 
 /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
    positive, shift that token.  If negative, reduce the rule which
    number is the opposite.  If zero, do what YYDEFACT says.
    If YYTABLE_NINF, syntax error.  */
-#define YYTABLE_NINF -105
+#define YYTABLE_NINF -103
 static const yytype_int16 yytable[] =
 {
-      83,    79,    79,     3,    65,    60,   127,   129,    55,   134,
-     129,   135,  -104,    85,    70,   102,    72,     4,     5,     6,
-       7,     8,     9,    10,    11,    75,    56,   110,    12,    13,
-      77,    15,    80,   133,   125,    81,   125,    57,    99,    99,
-      61,    96,    79,   126,    28,    58,    62,    80,    80,    33,
-      81,    81,    66,   113,    38,   102,    40,   103,   104,   105,
-      63,   128,    71,    64,    73,    86,   119,    67,    68,    69,
-      74,    85,    58,    47,    76,     4,     5,     6,     7,     8,
-       9,    10,    11,    99,   128,    99,    12,    13,    78,    15,
-      92,    94,   140,   114,   115,   116,   142,   117,   118,   123,
-     130,   140,    28,    79,   144,   143,    49,    33,   100,   124,
-     109,   120,    38,   141,    40,     0,     0,     0,     0,     0,
-       0,     0,     0,    86,     0,     0,     0,     0,     0,     0,
-       0,    47,     4,     5,     6,     7,     8,     9,    10,    11,
-       0,     0,     0,    12,    13,    14,    15,    16,    17,    18,
-      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
-      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
-      39,    40,    41,    42,    43,    79,     0,     0,     0,     0,
-       0,    44,     0,    45,    46,   136,   137,   138,    47,     0,
+      78,    74,   123,    74,    75,    94,    94,    76,   130,    62,
+     131,  -102,    80,    91,     3,    97,     4,     5,     6,     7,
+       8,     9,    10,    11,    55,    67,    69,    12,    80,    14,
+     129,   106,     4,     5,     6,     7,     8,     9,    10,    11,
+      74,   122,    27,    12,    75,    14,    75,    76,    94,    76,
+      94,    52,    37,    97,    63,    98,    99,   100,    27,   124,
+     125,    81,   115,   125,   105,    53,    56,   109,    37,    44,
+      68,    70,   121,    56,   121,    54,    58,    81,    59,    64,
+      60,    61,    65,   124,    66,    44,    71,    72,    73,    87,
+      89,   136,    56,   110,   111,   138,   112,   113,   114,   119,
+     136,     4,     5,     6,     7,     8,     9,    10,    11,   126,
+      74,   140,    12,    13,    14,    15,    16,    17,    18,    19,
+      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
+      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
+      40,    74,    46,   139,   116,   120,   104,    41,    95,    42,
+      43,   132,   133,   134,    44,   137,     0,     0,     0,     0,
        0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
        0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
-       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
-     139,    80,     0,     0,    81
+       0,     0,     0,   135,    75,     0,     0,    76
 };
 
 static const yytype_int16 yycheck[] =
 {
-      40,     3,     3,     0,     3,    13,    99,   106,    58,    55,
-     109,    57,     0,     1,     3,    55,     3,     5,     6,     7,
-       8,     9,    10,    11,    12,    33,    48,     3,    16,    17,
-      38,    19,    49,   126,    98,    52,   100,    48,    53,    54,
-       3,    58,     3,     4,    32,    48,     3,    49,    49,    37,
-      52,    52,    51,    61,    42,    95,    44,    58,    59,    60,
-       4,   101,    51,     4,    51,    53,    54,    48,     3,    48,
-      48,     1,    48,    61,     3,     5,     6,     7,     8,     9,
-      10,    11,    12,    98,   124,   100,    16,    17,     3,    19,
-      52,    58,   132,     3,     3,     3,   136,    57,    57,    48,
-      50,   141,    32,     3,    58,     4,     2,    37,    54,    95,
-      57,    88,    42,   134,    44,    -1,    -1,    -1,    -1,    -1,
-      -1,    -1,    -1,    53,    -1,    -1,    -1,    -1,    -1,    -1,
-      -1,    61,     5,     6,     7,     8,     9,    10,    11,    12,
-      -1,    -1,    -1,    16,    17,    18,    19,    20,    21,    22,
-      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
-      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
-      43,    44,    45,    46,    47,     3,    -1,    -1,    -1,    -1,
-      -1,    54,    -1,    56,    57,    13,    14,    15,    61,    -1,
-      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
+      37,     3,    94,     3,    46,    50,    51,    49,    52,     3,
+      54,     0,     1,    55,     0,    52,     5,     6,     7,     8,
+       9,    10,    11,    12,     3,     3,     3,    16,     1,    18,
+     122,     3,     5,     6,     7,     8,     9,    10,    11,    12,
+       3,     4,    31,    16,    46,    18,    46,    49,    93,    49,
+      95,    55,    41,    90,    48,    55,    56,    57,    31,    96,
+     101,    50,    51,   104,    55,    45,    45,    58,    41,    58,
+      48,    48,    93,    45,    95,    45,     3,    50,     3,    45,
+       4,     4,     3,   120,    45,    58,    45,     3,     3,    49,
+      55,   128,    45,     3,     3,   132,     3,    54,    54,    45,
+     137,     5,     6,     7,     8,     9,    10,    11,    12,    47,
+       3,    55,    16,    17,    18,    19,    20,    21,    22,    23,
+      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
+      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
+      44,     3,     2,     4,    83,    90,    54,    51,    51,    53,
+      54,    13,    14,    15,    58,   130,    -1,    -1,    -1,    -1,
       -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
-      48,    49,    -1,    -1,    52
+      -1,    -1,    -1,    45,    46,    -1,    -1,    49
 };
 
 /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
    symbol of state STATE-NUM.  */
 static const yytype_uint8 yystos[] =
 {
-       0,    63,    64,     0,     5,     6,     7,     8,     9,    10,
+       0,    60,    61,     0,     5,     6,     7,     8,     9,    10,
       11,    12,    16,    17,    18,    19,    20,    21,    22,    23,
       24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
       34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
-      44,    45,    46,    47,    54,    56,    57,    61,    65,    66,
-      68,    71,    72,    70,    69,    58,    48,    48,    48,    87,
-      87,     3,     3,     4,     4,     3,    51,    48,     3,    48,
-       3,    51,     3,    51,    48,    87,     3,    87,     3,     3,
-      49,    52,    88,    90,    91,     1,    53,    66,    79,    80,
-      81,    89,    52,    67,    58,    73,    58,    77,    78,    88,
-      78,    74,    90,    58,    59,    60,    75,    76,    90,    75,
-       3,    85,    86,    87,     3,     3,     3,    57,    57,    54,
-      80,    92,    82,    48,    74,    77,     4,    91,    90,    76,
-      50,    83,    84,    91,    55,    57,    13,    14,    15,    48,
-      90,    84,    90,     4,    58
+      44,    51,    53,    54,    58,    62,    63,    65,    68,    69,
+      67,    66,    55,    45,    45,     3,    45,    84,     3,     3,
+       4,     4,     3,    48,    45,     3,    45,     3,    48,     3,
+      48,    45,     3,     3,     3,    46,    49,    85,    87,    88,
+       1,    50,    63,    76,    77,    78,    86,    49,    64,    55,
+      70,    55,    74,    75,    85,    75,    71,    87,    55,    56,
+      57,    72,    73,    87,    72,    84,     3,    82,    83,    84,
+       3,     3,     3,    54,    54,    51,    77,    89,    79,    45,
+      71,    74,     4,    88,    87,    73,    47,    80,    81,    88,
+      52,    54,    13,    14,    15,    45,    87,    81,    87,     4,
+      55
 };
 
 #define yyerrok		(yyerrstatus = 0)
@@ -1058,147 +1043,147 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
     {
       case 3: /* "\"string\"" */
 
-/* Line 673 of yacc.c  */
-#line 192 "parse-gram.y"
+/* Line 681 of yacc.c  */
+#line 189 "parse-gram.y"
 	{ fputs (quotearg_style (c_quoting_style, (yyvaluep->chars)), stderr); };
 
-/* Line 673 of yacc.c  */
-#line 1067 "parse-gram.c"
+/* Line 681 of yacc.c  */
+#line 1052 "parse-gram.c"
 	break;
       case 4: /* "\"integer\"" */
 
-/* Line 673 of yacc.c  */
-#line 203 "parse-gram.y"
+/* Line 681 of yacc.c  */
+#line 200 "parse-gram.y"
 	{ fprintf (stderr, "%d", (yyvaluep->integer)); };
 
-/* Line 673 of yacc.c  */
-#line 1076 "parse-gram.c"
+/* Line 681 of yacc.c  */
+#line 1061 "parse-gram.c"
 	break;
-      case 48: /* "\"{...}\"" */
+      case 45: /* "\"{...}\"" */
 
-/* Line 673 of yacc.c  */
-#line 194 "parse-gram.y"
+/* Line 681 of yacc.c  */
+#line 191 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->code)); };
 
-/* Line 673 of yacc.c  */
-#line 1085 "parse-gram.c"
+/* Line 681 of yacc.c  */
+#line 1070 "parse-gram.c"
 	break;
-      case 49: /* "\"char\"" */
+      case 46: /* "\"char\"" */
 
-/* Line 673 of yacc.c  */
-#line 186 "parse-gram.y"
+/* Line 681 of yacc.c  */
+#line 183 "parse-gram.y"
 	{ fputs (char_name ((yyvaluep->character)), stderr); };
 
-/* Line 673 of yacc.c  */
-#line 1094 "parse-gram.c"
+/* Line 681 of yacc.c  */
+#line 1079 "parse-gram.c"
 	break;
-      case 50: /* "\"epilogue\"" */
+      case 47: /* "\"epilogue\"" */
 
-/* Line 673 of yacc.c  */
-#line 194 "parse-gram.y"
+/* Line 681 of yacc.c  */
+#line 191 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
-/* Line 673 of yacc.c  */
-#line 1103 "parse-gram.c"
+/* Line 681 of yacc.c  */
+#line 1088 "parse-gram.c"
 	break;
-      case 52: /* "\"identifier\"" */
+      case 49: /* "\"identifier\"" */
 
-/* Line 673 of yacc.c  */
-#line 199 "parse-gram.y"
+/* Line 681 of yacc.c  */
+#line 196 "parse-gram.y"
 	{ fputs ((yyvaluep->uniqstr), stderr); };
 
-/* Line 673 of yacc.c  */
-#line 1112 "parse-gram.c"
+/* Line 681 of yacc.c  */
+#line 1097 "parse-gram.c"
 	break;
-      case 53: /* "\"identifier:\"" */
+      case 50: /* "\"identifier:\"" */
 
-/* Line 673 of yacc.c  */
-#line 200 "parse-gram.y"
+/* Line 681 of yacc.c  */
+#line 197 "parse-gram.y"
 	{ fprintf (stderr, "%s:", (yyvaluep->uniqstr)); };
 
-/* Line 673 of yacc.c  */
-#line 1121 "parse-gram.c"
+/* Line 681 of yacc.c  */
+#line 1106 "parse-gram.c"
 	break;
-      case 56: /* "\"%{...%}\"" */
+      case 53: /* "\"%{...%}\"" */
 
-/* Line 673 of yacc.c  */
-#line 194 "parse-gram.y"
+/* Line 681 of yacc.c  */
+#line 191 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
-/* Line 673 of yacc.c  */
-#line 1130 "parse-gram.c"
+/* Line 681 of yacc.c  */
+#line 1115 "parse-gram.c"
 	break;
-      case 58: /* "\"type\"" */
+      case 55: /* "\"type\"" */
 
-/* Line 673 of yacc.c  */
-#line 198 "parse-gram.y"
+/* Line 681 of yacc.c  */
+#line 195 "parse-gram.y"
 	{ fprintf (stderr, "<%s>", (yyvaluep->uniqstr)); };
 
-/* Line 673 of yacc.c  */
-#line 1139 "parse-gram.c"
+/* Line 681 of yacc.c  */
+#line 1124 "parse-gram.c"
 	break;
-      case 85: /* "content" */
+      case 82: /* "content" */
 
-/* Line 673 of yacc.c  */
-#line 194 "parse-gram.y"
+/* Line 681 of yacc.c  */
+#line 191 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
-/* Line 673 of yacc.c  */
-#line 1148 "parse-gram.c"
+/* Line 681 of yacc.c  */
+#line 1133 "parse-gram.c"
 	break;
-      case 86: /* "content.opt" */
+      case 83: /* "content.opt" */
 
-/* Line 673 of yacc.c  */
-#line 194 "parse-gram.y"
+/* Line 681 of yacc.c  */
+#line 191 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
-/* Line 673 of yacc.c  */
-#line 1157 "parse-gram.c"
+/* Line 681 of yacc.c  */
+#line 1142 "parse-gram.c"
 	break;
-      case 87: /* "braceless" */
+      case 84: /* "braceless" */
 
-/* Line 673 of yacc.c  */
-#line 194 "parse-gram.y"
+/* Line 681 of yacc.c  */
+#line 191 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
-/* Line 673 of yacc.c  */
-#line 1166 "parse-gram.c"
+/* Line 681 of yacc.c  */
+#line 1151 "parse-gram.c"
 	break;
-      case 88: /* "id" */
+      case 85: /* "id" */
 
-/* Line 673 of yacc.c  */
-#line 206 "parse-gram.y"
+/* Line 681 of yacc.c  */
+#line 203 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
-/* Line 673 of yacc.c  */
-#line 1175 "parse-gram.c"
+/* Line 681 of yacc.c  */
+#line 1160 "parse-gram.c"
 	break;
-      case 89: /* "id_colon" */
+      case 86: /* "id_colon" */
 
-/* Line 673 of yacc.c  */
-#line 207 "parse-gram.y"
+/* Line 681 of yacc.c  */
+#line 204 "parse-gram.y"
 	{ fprintf (stderr, "%s:", (yyvaluep->symbol)->tag); };
 
-/* Line 673 of yacc.c  */
-#line 1184 "parse-gram.c"
+/* Line 681 of yacc.c  */
+#line 1169 "parse-gram.c"
 	break;
-      case 90: /* "symbol" */
+      case 87: /* "symbol" */
 
-/* Line 673 of yacc.c  */
-#line 206 "parse-gram.y"
+/* Line 681 of yacc.c  */
+#line 203 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
-/* Line 673 of yacc.c  */
-#line 1193 "parse-gram.c"
+/* Line 681 of yacc.c  */
+#line 1178 "parse-gram.c"
 	break;
-      case 91: /* "string_as_id" */
+      case 88: /* "string_as_id" */
 
-/* Line 673 of yacc.c  */
-#line 206 "parse-gram.y"
+/* Line 681 of yacc.c  */
+#line 203 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
-/* Line 673 of yacc.c  */
-#line 1202 "parse-gram.c"
+/* Line 681 of yacc.c  */
+#line 1187 "parse-gram.c"
 	break;
       default:
 	break;
@@ -1712,7 +1697,7 @@ YYLTYPE yylloc;
 
   /* User initialization code.  */
   
-/* Line 1085 of yacc.c  */
+/* Line 1093 of yacc.c  */
 #line 90 "parse-gram.y"
 {
   /* Bison's grammar can initial empty locations, hence a default
@@ -1721,8 +1706,8 @@ YYLTYPE yylloc;
   boundary_set (&yylloc.end, current_file, 1, 1);
 }
 
-/* Line 1085 of yacc.c  */
-#line 1726 "parse-gram.c"
+/* Line 1093 of yacc.c  */
+#line 1711 "parse-gram.c"
   yylsp[0] = yylloc;
   goto yysetstate;
 
@@ -1907,8 +1892,8 @@ yyreduce:
     {
         case 6:
 
-/* Line 1272 of yacc.c  */
-#line 230 "parse-gram.y"
+/* Line 1280 of yacc.c  */
+#line 227 "parse-gram.y"
     {
       code_props plain_code;
       code_props_plain_init (&plain_code, (yyvsp[(1) - (1)].chars), (yylsp[(1) - (1)]));
@@ -1921,29 +1906,29 @@ yyreduce:
 
   case 7:
 
-/* Line 1272 of yacc.c  */
-#line 238 "parse-gram.y"
+/* Line 1280 of yacc.c  */
+#line 235 "parse-gram.y"
     { debug_flag = true; }
     break;
 
   case 8:
 
-/* Line 1272 of yacc.c  */
-#line 239 "parse-gram.y"
+/* Line 1280 of yacc.c  */
+#line 236 "parse-gram.y"
     { muscle_insert ((yyvsp[(2) - (3)].chars), (yyvsp[(3) - (3)].chars)); }
     break;
 
   case 9:
 
-/* Line 1272 of yacc.c  */
-#line 240 "parse-gram.y"
+/* Line 1280 of yacc.c  */
+#line 237 "parse-gram.y"
     { defines_flag = true; }
     break;
 
   case 10:
 
-/* Line 1272 of yacc.c  */
-#line 242 "parse-gram.y"
+/* Line 1280 of yacc.c  */
+#line 239 "parse-gram.y"
     {
       defines_flag = true;
       spec_defines_file = xstrdup ((yyvsp[(2) - (2)].chars));
@@ -1952,43 +1937,43 @@ yyreduce:
 
   case 11:
 
-/* Line 1272 of yacc.c  */
-#line 246 "parse-gram.y"
+/* Line 1280 of yacc.c  */
+#line 243 "parse-gram.y"
     { error_verbose = true; }
     break;
 
   case 12:
 
-/* Line 1272 of yacc.c  */
-#line 247 "parse-gram.y"
+/* Line 1280 of yacc.c  */
+#line 244 "parse-gram.y"
     { expected_sr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 13:
 
-/* Line 1272 of yacc.c  */
-#line 248 "parse-gram.y"
+/* Line 1280 of yacc.c  */
+#line 245 "parse-gram.y"
     { expected_rr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 14:
 
-/* Line 1272 of yacc.c  */
-#line 249 "parse-gram.y"
+/* Line 1280 of yacc.c  */
+#line 246 "parse-gram.y"
     { spec_file_prefix = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 15:
 
-/* Line 1272 of yacc.c  */
-#line 250 "parse-gram.y"
+/* Line 1280 of yacc.c  */
+#line 247 "parse-gram.y"
     { spec_file_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 16:
 
-/* Line 1272 of yacc.c  */
-#line 252 "parse-gram.y"
+/* Line 1280 of yacc.c  */
+#line 249 "parse-gram.y"
     {
       nondeterministic_parser = true;
       glr_parser = true;
@@ -1997,8 +1982,8 @@ yyreduce:
 
   case 17:
 
-/* Line 1272 of yacc.c  */
-#line 257 "parse-gram.y"
+/* Line 1280 of yacc.c  */
+#line 254 "parse-gram.y"
     {
       code_props action;
       code_props_symbol_action_init (&action, (yyvsp[(2) - (2)].code), (yylsp[(2) - (2)]));
@@ -2011,134 +1996,134 @@ yyreduce:
 
   case 18:
 
-/* Line 1272 of yacc.c  */
-#line 265 "parse-gram.y"
+/* Line 1280 of yacc.c  */
+#line 262 "parse-gram.y"
     { language_argmatch ((yyvsp[(2) - (2)].chars), 1, &(yylsp[(1) - (2)])); }
     break;
 
   case 19:
 
-/* Line 1272 of yacc.c  */
-#line 266 "parse-gram.y"
+/* Line 1280 of yacc.c  */
+#line 263 "parse-gram.y"
     { add_param ("lex_param", (yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
     break;
 
   case 20:
 
-/* Line 1272 of yacc.c  */
-#line 267 "parse-gram.y"
+/* Line 1280 of yacc.c  */
+#line 264 "parse-gram.y"
     { locations_flag = true; }
     break;
 
   case 21:
 
-/* Line 1272 of yacc.c  */
-#line 268 "parse-gram.y"
+/* Line 1280 of yacc.c  */
+#line 265 "parse-gram.y"
     { spec_name_prefix = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 22:
 
-/* Line 1272 of yacc.c  */
-#line 269 "parse-gram.y"
+/* Line 1280 of yacc.c  */
+#line 266 "parse-gram.y"
     { spec_name_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 23:
 
-/* Line 1272 of yacc.c  */
-#line 270 "parse-gram.y"
+/* Line 1280 of yacc.c  */
+#line 267 "parse-gram.y"
     { no_lines_flag = true; }
     break;
 
   case 24:
 
-/* Line 1272 of yacc.c  */
-#line 271 "parse-gram.y"
+/* Line 1280 of yacc.c  */
+#line 268 "parse-gram.y"
     { nondeterministic_parser = true; }
     break;
 
   case 25:
 
-/* Line 1272 of yacc.c  */
-#line 272 "parse-gram.y"
+/* Line 1280 of yacc.c  */
+#line 269 "parse-gram.y"
     { spec_outfile = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 26:
 
-/* Line 1272 of yacc.c  */
-#line 273 "parse-gram.y"
+/* Line 1280 of yacc.c  */
+#line 270 "parse-gram.y"
     { spec_outfile = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 27:
 
-/* Line 1272 of yacc.c  */
-#line 274 "parse-gram.y"
+/* Line 1280 of yacc.c  */
+#line 271 "parse-gram.y"
     { add_param ("parse_param", (yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
     break;
 
   case 28:
 
-/* Line 1272 of yacc.c  */
-#line 275 "parse-gram.y"
+/* Line 1280 of yacc.c  */
+#line 272 "parse-gram.y"
     { pure_parser = true; }
     break;
 
   case 29:
 
-/* Line 1272 of yacc.c  */
-#line 276 "parse-gram.y"
+/* Line 1280 of yacc.c  */
+#line 273 "parse-gram.y"
     { push_parser = true; pull_parser = false; }
     break;
 
   case 30:
 
-/* Line 1272 of yacc.c  */
-#line 277 "parse-gram.y"
+/* Line 1280 of yacc.c  */
+#line 274 "parse-gram.y"
     { push_parser = true; pull_parser = true; }
     break;
 
   case 31:
 
-/* Line 1272 of yacc.c  */
-#line 278 "parse-gram.y"
+/* Line 1280 of yacc.c  */
+#line 275 "parse-gram.y"
     { version_check (&(yylsp[(2) - (2)]), (yyvsp[(2) - (2)].chars)); }
     break;
 
   case 32:
 
-/* Line 1272 of yacc.c  */
-#line 279 "parse-gram.y"
+/* Line 1280 of yacc.c  */
+#line 276 "parse-gram.y"
     { skeleton_arg ((yyvsp[(2) - (2)].chars), 1, &(yylsp[(1) - (2)])); }
     break;
 
   case 33:
 
-/* Line 1272 of yacc.c  */
-#line 280 "parse-gram.y"
+/* Line 1280 of yacc.c  */
+#line 277 "parse-gram.y"
     { token_table_flag = true; }
     break;
 
   case 34:
 
-/* Line 1272 of yacc.c  */
-#line 281 "parse-gram.y"
+/* Line 1280 of yacc.c  */
+#line 278 "parse-gram.y"
     { report_flag = report_states; }
     break;
 
   case 35:
 
-/* Line 1272 of yacc.c  */
-#line 282 "parse-gram.y"
+/* Line 1280 of yacc.c  */
+#line 279 "parse-gram.y"
     { yacc_flag = true; }
     break;
 
   case 39:
 
-/* Line 1272 of yacc.c  */
-#line 290 "parse-gram.y"
+/* Line 1280 of yacc.c  */
+#line 287 "parse-gram.y"
     {
       grammar_start_symbol_set ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]));
     }
@@ -2146,8 +2131,8 @@ yyreduce:
 
   case 40:
 
-/* Line 1272 of yacc.c  */
-#line 294 "parse-gram.y"
+/* Line 1280 of yacc.c  */
+#line 291 "parse-gram.y"
     {
       symbol_list *list;
       for (list = (yyvsp[(3) - (3)].list); list; list = list->next)
@@ -2158,8 +2143,8 @@ yyreduce:
 
   case 41:
 
-/* Line 1272 of yacc.c  */
-#line 301 "parse-gram.y"
+/* Line 1280 of yacc.c  */
+#line 298 "parse-gram.y"
     {
       symbol_list *list;
       for (list = (yyvsp[(3) - (3)].list); list; list = list->next)
@@ -2170,8 +2155,8 @@ yyreduce:
 
   case 42:
 
-/* Line 1272 of yacc.c  */
-#line 308 "parse-gram.y"
+/* Line 1280 of yacc.c  */
+#line 305 "parse-gram.y"
     {
       default_prec = true;
     }
@@ -2179,8 +2164,8 @@ yyreduce:
 
   case 43:
 
-/* Line 1272 of yacc.c  */
-#line 312 "parse-gram.y"
+/* Line 1280 of yacc.c  */
+#line 309 "parse-gram.y"
     {
       default_prec = false;
     }
@@ -2188,50 +2173,48 @@ yyreduce:
 
   case 44:
 
-/* Line 1272 of yacc.c  */
-#line 315 "parse-gram.y"
-    { prologue_augment ((yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)]), true); }
+/* Line 1280 of yacc.c  */
+#line 313 "parse-gram.y"
+    {
+      muscle_code_grow ("percent_code", (yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)]));
+      code_scanner_last_string_free ();
+    }
     break;
 
   case 45:
 
-/* Line 1272 of yacc.c  */
-#line 316 "parse-gram.y"
-    { prologue_augment ((yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)]), false); }
-    break;
-
-  case 46:
-
-/* Line 1272 of yacc.c  */
-#line 317 "parse-gram.y"
-    { muscle_code_grow ("provides", (yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])); }
-    break;
-
-  case 47:
-
-/* Line 1272 of yacc.c  */
+/* Line 1280 of yacc.c  */
 #line 318 "parse-gram.y"
-    { muscle_code_grow ("requires", (yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])); }
+    {
+      char const name_prefix[] = "percent_code_";
+      char *name = xmalloc (sizeof name_prefix + strlen ((yyvsp[(2) - (3)].chars)));
+      strcpy (name, name_prefix);
+      strcpy (name + sizeof name_prefix - 1, (yyvsp[(2) - (3)].chars));
+      muscle_code_grow (uniqstr_new (name), (yyvsp[(3) - (3)].chars), (yylsp[(3) - (3)]));
+      free (name);
+      code_scanner_last_string_free ();
+      muscle_grow ("used_percent_code_qualifiers", (yyvsp[(2) - (3)].chars), ",");
+    }
     break;
 
-  case 48:
+  case 46:
 
-/* Line 1272 of yacc.c  */
-#line 329 "parse-gram.y"
+/* Line 1280 of yacc.c  */
+#line 338 "parse-gram.y"
     {}
     break;
 
-  case 49:
+  case 47:
 
-/* Line 1272 of yacc.c  */
-#line 330 "parse-gram.y"
+/* Line 1280 of yacc.c  */
+#line 339 "parse-gram.y"
     { muscle_code_grow ("union_name", (yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
-  case 50:
+  case 48:
 
-/* Line 1272 of yacc.c  */
-#line 335 "parse-gram.y"
+/* Line 1280 of yacc.c  */
+#line 344 "parse-gram.y"
     {
       char const *body = (yyvsp[(3) - (3)].code);
 
@@ -2256,44 +2239,44 @@ yyreduce:
     }
     break;
 
-  case 51:
+  case 49:
 
-/* Line 1272 of yacc.c  */
-#line 363 "parse-gram.y"
+/* Line 1280 of yacc.c  */
+#line 372 "parse-gram.y"
     { current_class = nterm_sym; }
     break;
 
-  case 52:
+  case 50:
 
-/* Line 1272 of yacc.c  */
-#line 364 "parse-gram.y"
+/* Line 1280 of yacc.c  */
+#line 373 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
     break;
 
-  case 53:
+  case 51:
 
-/* Line 1272 of yacc.c  */
-#line 368 "parse-gram.y"
+/* Line 1280 of yacc.c  */
+#line 377 "parse-gram.y"
     { current_class = token_sym; }
     break;
 
-  case 54:
+  case 52:
 
-/* Line 1272 of yacc.c  */
-#line 369 "parse-gram.y"
+/* Line 1280 of yacc.c  */
+#line 378 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
     break;
 
-  case 55:
+  case 53:
 
-/* Line 1272 of yacc.c  */
-#line 374 "parse-gram.y"
+/* Line 1280 of yacc.c  */
+#line 383 "parse-gram.y"
     {
       symbol_list *list;
       tag_seen = true;
@@ -2303,10 +2286,10 @@ yyreduce:
     }
     break;
 
-  case 56:
+  case 54:
 
-/* Line 1272 of yacc.c  */
-#line 385 "parse-gram.y"
+/* Line 1280 of yacc.c  */
+#line 394 "parse-gram.y"
     {
       symbol_list *list;
       ++current_prec;
@@ -2320,121 +2303,121 @@ yyreduce:
     }
     break;
 
-  case 57:
+  case 55:
 
-/* Line 1272 of yacc.c  */
-#line 399 "parse-gram.y"
+/* Line 1280 of yacc.c  */
+#line 408 "parse-gram.y"
     { (yyval.assoc) = left_assoc; }
     break;
 
-  case 58:
+  case 56:
 
-/* Line 1272 of yacc.c  */
-#line 400 "parse-gram.y"
+/* Line 1280 of yacc.c  */
+#line 409 "parse-gram.y"
     { (yyval.assoc) = right_assoc; }
     break;
 
-  case 59:
+  case 57:
 
-/* Line 1272 of yacc.c  */
-#line 401 "parse-gram.y"
+/* Line 1280 of yacc.c  */
+#line 410 "parse-gram.y"
     { (yyval.assoc) = non_assoc; }
     break;
 
-  case 60:
+  case 58:
 
-/* Line 1272 of yacc.c  */
-#line 405 "parse-gram.y"
+/* Line 1280 of yacc.c  */
+#line 414 "parse-gram.y"
     { current_type = NULL; }
     break;
 
-  case 61:
+  case 59:
 
-/* Line 1272 of yacc.c  */
-#line 406 "parse-gram.y"
+/* Line 1280 of yacc.c  */
+#line 415 "parse-gram.y"
     { current_type = (yyvsp[(1) - (1)].uniqstr); tag_seen = true; }
     break;
 
-  case 62:
+  case 60:
 
-/* Line 1272 of yacc.c  */
-#line 412 "parse-gram.y"
+/* Line 1280 of yacc.c  */
+#line 421 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
-  case 63:
+  case 61:
 
-/* Line 1272 of yacc.c  */
-#line 414 "parse-gram.y"
+/* Line 1280 of yacc.c  */
+#line 423 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), symbol_list_sym_new ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]))); }
     break;
 
-  case 64:
+  case 62:
 
-/* Line 1272 of yacc.c  */
-#line 418 "parse-gram.y"
+/* Line 1280 of yacc.c  */
+#line 427 "parse-gram.y"
     { (yyval.list) = (yyvsp[(1) - (1)].list); }
     break;
 
-  case 65:
+  case 63:
 
-/* Line 1272 of yacc.c  */
-#line 419 "parse-gram.y"
+/* Line 1280 of yacc.c  */
+#line 428 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), (yyvsp[(2) - (2)].list)); }
     break;
 
-  case 66:
+  case 64:
 
-/* Line 1272 of yacc.c  */
-#line 423 "parse-gram.y"
+/* Line 1280 of yacc.c  */
+#line 432 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
-  case 67:
+  case 65:
 
-/* Line 1272 of yacc.c  */
-#line 424 "parse-gram.y"
+/* Line 1280 of yacc.c  */
+#line 433 "parse-gram.y"
     { (yyval.list) = symbol_list_type_new ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
-  case 68:
+  case 66:
 
-/* Line 1272 of yacc.c  */
-#line 425 "parse-gram.y"
+/* Line 1280 of yacc.c  */
+#line 434 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagged_new ((yylsp[(1) - (1)])); }
     break;
 
-  case 69:
+  case 67:
 
-/* Line 1272 of yacc.c  */
-#line 426 "parse-gram.y"
+/* Line 1280 of yacc.c  */
+#line 435 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagless_new ((yylsp[(1) - (1)])); }
     break;
 
-  case 70:
+  case 68:
 
-/* Line 1272 of yacc.c  */
-#line 432 "parse-gram.y"
+/* Line 1280 of yacc.c  */
+#line 441 "parse-gram.y"
     {
        current_type = (yyvsp[(1) - (1)].uniqstr);
        tag_seen = true;
      }
     break;
 
-  case 71:
+  case 69:
 
-/* Line 1272 of yacc.c  */
-#line 437 "parse-gram.y"
+/* Line 1280 of yacc.c  */
+#line 446 "parse-gram.y"
     {
        symbol_class_set ((yyvsp[(1) - (1)].symbol), current_class, (yylsp[(1) - (1)]), true);
        symbol_type_set ((yyvsp[(1) - (1)].symbol), current_type, (yylsp[(1) - (1)]));
      }
     break;
 
-  case 72:
+  case 70:
 
-/* Line 1272 of yacc.c  */
-#line 442 "parse-gram.y"
+/* Line 1280 of yacc.c  */
+#line 451 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
       symbol_type_set ((yyvsp[(1) - (2)].symbol), current_type, (yylsp[(1) - (2)]));
@@ -2442,10 +2425,10 @@ yyreduce:
     }
     break;
 
-  case 73:
+  case 71:
 
-/* Line 1272 of yacc.c  */
-#line 448 "parse-gram.y"
+/* Line 1280 of yacc.c  */
+#line 457 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
       symbol_type_set ((yyvsp[(1) - (2)].symbol), current_type, (yylsp[(1) - (2)]));
@@ -2453,10 +2436,10 @@ yyreduce:
     }
     break;
 
-  case 74:
+  case 72:
 
-/* Line 1272 of yacc.c  */
-#line 454 "parse-gram.y"
+/* Line 1280 of yacc.c  */
+#line 463 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (3)].symbol), current_class, (yylsp[(1) - (3)]), true);
       symbol_type_set ((yyvsp[(1) - (3)].symbol), current_type, (yylsp[(1) - (3)]));
@@ -2465,92 +2448,92 @@ yyreduce:
     }
     break;
 
-  case 81:
+  case 79:
 
-/* Line 1272 of yacc.c  */
-#line 484 "parse-gram.y"
+/* Line 1280 of yacc.c  */
+#line 493 "parse-gram.y"
     {
       yyerrok;
     }
     break;
 
-  case 82:
+  case 80:
 
-/* Line 1272 of yacc.c  */
-#line 490 "parse-gram.y"
+/* Line 1280 of yacc.c  */
+#line 499 "parse-gram.y"
     { current_lhs = (yyvsp[(1) - (1)].symbol); current_lhs_location = (yylsp[(1) - (1)]); }
     break;
 
-  case 84:
+  case 82:
 
-/* Line 1272 of yacc.c  */
-#line 494 "parse-gram.y"
+/* Line 1280 of yacc.c  */
+#line 503 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(1) - (1)])); }
     break;
 
-  case 85:
+  case 83:
 
-/* Line 1272 of yacc.c  */
-#line 495 "parse-gram.y"
+/* Line 1280 of yacc.c  */
+#line 504 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(3) - (3)])); }
     break;
 
-  case 87:
+  case 85:
 
-/* Line 1272 of yacc.c  */
-#line 501 "parse-gram.y"
+/* Line 1280 of yacc.c  */
+#line 510 "parse-gram.y"
     { grammar_current_rule_begin (current_lhs, current_lhs_location); }
     break;
 
-  case 88:
+  case 86:
 
-/* Line 1272 of yacc.c  */
-#line 503 "parse-gram.y"
+/* Line 1280 of yacc.c  */
+#line 512 "parse-gram.y"
     { grammar_current_rule_symbol_append ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)])); }
     break;
 
-  case 89:
+  case 87:
 
-/* Line 1272 of yacc.c  */
-#line 505 "parse-gram.y"
+/* Line 1280 of yacc.c  */
+#line 514 "parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
     break;
 
-  case 90:
+  case 88:
 
-/* Line 1272 of yacc.c  */
-#line 507 "parse-gram.y"
+/* Line 1280 of yacc.c  */
+#line 516 "parse-gram.y"
     { grammar_current_rule_prec_set ((yyvsp[(3) - (3)].symbol), (yylsp[(3) - (3)])); }
     break;
 
-  case 91:
+  case 89:
 
-/* Line 1272 of yacc.c  */
-#line 509 "parse-gram.y"
+/* Line 1280 of yacc.c  */
+#line 518 "parse-gram.y"
     { grammar_current_rule_dprec_set ((yyvsp[(3) - (3)].integer), (yylsp[(3) - (3)])); }
     break;
 
-  case 92:
+  case 90:
 
-/* Line 1272 of yacc.c  */
-#line 511 "parse-gram.y"
+/* Line 1280 of yacc.c  */
+#line 520 "parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[(3) - (3)].uniqstr), (yylsp[(3) - (3)])); }
     break;
 
-  case 95:
+  case 93:
 
-/* Line 1272 of yacc.c  */
-#line 527 "parse-gram.y"
+/* Line 1280 of yacc.c  */
+#line 536 "parse-gram.y"
     {
       static char one[] = "1";
       (yyval.chars) = one;
     }
     break;
 
-  case 97:
+  case 95:
 
-/* Line 1272 of yacc.c  */
-#line 537 "parse-gram.y"
+/* Line 1280 of yacc.c  */
+#line 546 "parse-gram.y"
     {
       code_props plain_code;
       (yyvsp[(1) - (1)].code)[strlen ((yyvsp[(1) - (1)].code)) - 1] = '\n';
@@ -2561,17 +2544,17 @@ yyreduce:
     }
     break;
 
-  case 98:
+  case 96:
 
-/* Line 1272 of yacc.c  */
-#line 557 "parse-gram.y"
+/* Line 1280 of yacc.c  */
+#line 566 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
-  case 99:
+  case 97:
 
-/* Line 1272 of yacc.c  */
-#line 559 "parse-gram.y"
+/* Line 1280 of yacc.c  */
+#line 568 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[(1) - (1)].character)), (yylsp[(1) - (1)]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[(1) - (1)]), false);
@@ -2579,27 +2562,27 @@ yyreduce:
     }
     break;
 
-  case 100:
+  case 98:
 
-/* Line 1272 of yacc.c  */
-#line 567 "parse-gram.y"
+/* Line 1280 of yacc.c  */
+#line 576 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
-  case 103:
+  case 101:
 
-/* Line 1272 of yacc.c  */
-#line 579 "parse-gram.y"
+/* Line 1280 of yacc.c  */
+#line 588 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[(1) - (1)].chars)), (yylsp[(1) - (1)]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[(1) - (1)]), false);
     }
     break;
 
-  case 105:
+  case 103:
 
-/* Line 1272 of yacc.c  */
-#line 588 "parse-gram.y"
+/* Line 1280 of yacc.c  */
+#line 597 "parse-gram.y"
     {
       code_props plain_code;
       code_props_plain_init (&plain_code, (yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)]));
@@ -2612,8 +2595,8 @@ yyreduce:
 
 
 
-/* Line 1272 of yacc.c  */
-#line 2617 "parse-gram.c"
+/* Line 1280 of yacc.c  */
+#line 2600 "parse-gram.c"
       default: break;
     }
   YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);
@@ -2831,8 +2814,8 @@ yyreturn:
 
 
 
-/* Line 1489 of yacc.c  */
-#line 598 "parse-gram.y"
+/* Line 1497 of yacc.c  */
+#line 607 "parse-gram.y"
 
 
 
