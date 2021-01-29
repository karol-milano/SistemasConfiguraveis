@@ -54,12 +54,6 @@
 /* Pure parsers.  */
 #define YYPURE 1
 
-/* Push parsers.  */
-#define YYPUSH 0
-
-/* Pull parsers.  */
-#define YYPULL 1
-
 /* Using locations.  */
 #define YYLSP_NEEDED 1
 
@@ -75,7 +69,7 @@
 
 /* Copy the first part of user declarations.  */
 
-/* Line 1535 of yacc.c  */
+/* Line 1538 of yacc.c  */
 #line 1 "parse-gram.y"
 /* Bison Grammar Parser                             -*- C -*-
 
@@ -152,8 +146,8 @@ static int current_prec = 0;
 #define YYTYPE_UINT8 uint_fast8_t
 
 
-/* Line 1535 of yacc.c  */
-#line 157 "parse-gram.c"
+/* Line 1538 of yacc.c  */
+#line 151 "parse-gram.c"
 
 /* Enabling traces.  */
 #ifndef YYDEBUG
@@ -215,28 +209,26 @@ static int current_prec = 0;
      PERCENT_OUTPUT = 289,
      PERCENT_PARSE_PARAM = 290,
      PERCENT_PURE_PARSER = 291,
-     PERCENT_PUSH_PARSER = 292,
-     PERCENT_PUSH_PULL_PARSER = 293,
-     PERCENT_REQUIRE = 294,
-     PERCENT_SKELETON = 295,
-     PERCENT_START = 296,
-     PERCENT_TOKEN_TABLE = 297,
-     PERCENT_VERBOSE = 298,
-     PERCENT_YACC = 299,
-     BRACED_CODE = 300,
-     CHAR = 301,
-     EPILOGUE = 302,
-     EQUAL = 303,
-     ID = 304,
-     ID_COLON = 305,
-     PERCENT_PERCENT = 306,
-     PIPE = 307,
-     PROLOGUE = 308,
-     SEMICOLON = 309,
-     TYPE = 310,
-     TYPE_TAG_ANY = 311,
-     TYPE_TAG_NONE = 312,
-     PERCENT_UNION = 313
+     PERCENT_REQUIRE = 292,
+     PERCENT_SKELETON = 293,
+     PERCENT_START = 294,
+     PERCENT_TOKEN_TABLE = 295,
+     PERCENT_VERBOSE = 296,
+     PERCENT_YACC = 297,
+     BRACED_CODE = 298,
+     CHAR = 299,
+     EPILOGUE = 300,
+     EQUAL = 301,
+     ID = 302,
+     ID_COLON = 303,
+     PERCENT_PERCENT = 304,
+     PIPE = 305,
+     PROLOGUE = 306,
+     SEMICOLON = 307,
+     TYPE = 308,
+     TYPE_TAG_ANY = 309,
+     TYPE_TAG_NONE = 310,
+     PERCENT_UNION = 311
    };
 #endif
 /* Tokens.  */
@@ -275,28 +267,26 @@ static int current_prec = 0;
 #define PERCENT_OUTPUT 289
 #define PERCENT_PARSE_PARAM 290
 #define PERCENT_PURE_PARSER 291
-#define PERCENT_PUSH_PARSER 292
-#define PERCENT_PUSH_PULL_PARSER 293
-#define PERCENT_REQUIRE 294
-#define PERCENT_SKELETON 295
-#define PERCENT_START 296
-#define PERCENT_TOKEN_TABLE 297
-#define PERCENT_VERBOSE 298
-#define PERCENT_YACC 299
-#define BRACED_CODE 300
-#define CHAR 301
-#define EPILOGUE 302
-#define EQUAL 303
-#define ID 304
-#define ID_COLON 305
-#define PERCENT_PERCENT 306
-#define PIPE 307
-#define PROLOGUE 308
-#define SEMICOLON 309
-#define TYPE 310
-#define TYPE_TAG_ANY 311
-#define TYPE_TAG_NONE 312
-#define PERCENT_UNION 313
+#define PERCENT_REQUIRE 292
+#define PERCENT_SKELETON 293
+#define PERCENT_START 294
+#define PERCENT_TOKEN_TABLE 295
+#define PERCENT_VERBOSE 296
+#define PERCENT_YACC 297
+#define BRACED_CODE 298
+#define CHAR 299
+#define EPILOGUE 300
+#define EQUAL 301
+#define ID 302
+#define ID_COLON 303
+#define PERCENT_PERCENT 304
+#define PIPE 305
+#define PROLOGUE 306
+#define SEMICOLON 307
+#define TYPE 308
+#define TYPE_TAG_ANY 309
+#define TYPE_TAG_NONE 310
+#define PERCENT_UNION 311
 
 
 
@@ -305,7 +295,7 @@ static int current_prec = 0;
 typedef union YYSTYPE
 {
 
-/* Line 1535 of yacc.c  */
+/* Line 1538 of yacc.c  */
 #line 94 "parse-gram.y"
 
   symbol *symbol;
@@ -319,8 +309,8 @@ typedef union YYSTYPE
 
 
 
-/* Line 1535 of yacc.c  */
-#line 324 "parse-gram.c"
+/* Line 1538 of yacc.c  */
+#line 314 "parse-gram.c"
 } YYSTYPE;
 # define YYSTYPE_IS_TRIVIAL 1
 # define yystype YYSTYPE /* obsolescent; will be withdrawn */
@@ -344,8 +334,8 @@ typedef struct YYLTYPE
 /* Copy the second part of user declarations.  */
 
 
-/* Line 1535 of yacc.c  */
-#line 349 "parse-gram.c"
+/* Line 1538 of yacc.c  */
+#line 339 "parse-gram.c"
 
 #ifdef short
 # undef short
@@ -562,20 +552,20 @@ union yyalloc
 /* YYFINAL -- State number of the termination state.  */
 #define YYFINAL  3
 /* YYLAST -- Last index in YYTABLE.  */
-#define YYLAST   158
+#define YYLAST   155
 
 /* YYNTOKENS -- Number of terminals.  */
-#define YYNTOKENS  59
+#define YYNTOKENS  57
 /* YYNNTS -- Number of nonterminals.  */
 #define YYNNTS  31
 /* YYNRULES -- Number of rules.  */
-#define YYNRULES  103
+#define YYNRULES  101
 /* YYNRULES -- Number of states.  */
-#define YYNSTATES  141
+#define YYNSTATES  139
 
 /* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
 #define YYUNDEFTOK  2
-#define YYMAXUTOK   313
+#define YYMAXUTOK   311
 
 #define YYTRANSLATE(YYX)						\
   ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)
@@ -614,7 +604,7 @@ static const yytype_uint8 yytranslate[] =
       25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
       35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
       45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
-      55,    56,    57,    58
+      55,    56
 };
 
 #if YYDEBUG
@@ -625,62 +615,61 @@ static const yytype_uint16 yyprhs[] =
        0,     0,     3,     8,     9,    12,    14,    16,    18,    22,
       24,    27,    29,    32,    35,    38,    42,    44,    47,    50,
       53,    55,    58,    62,    64,    66,    69,    73,    76,    78,
-      80,    82,    85,    88,    90,    92,    94,    96,    98,   100,
-     103,   107,   111,   113,   115,   118,   122,   123,   125,   129,
-     130,   134,   135,   139,   143,   147,   149,   151,   153,   154,
-     156,   158,   161,   163,   166,   168,   170,   172,   174,   176,
-     178,   181,   184,   188,   190,   193,   195,   198,   200,   203,
-     206,   207,   211,   213,   217,   220,   221,   224,   227,   231,
-     235,   239,   241,   243,   244,   246,   248,   250,   252,   254,
-     256,   258,   260,   261
+      81,    84,    86,    88,    90,    92,    94,    96,    99,   103,
+     107,   109,   111,   114,   118,   119,   121,   125,   126,   130,
+     131,   135,   139,   143,   145,   147,   149,   150,   152,   154,
+     157,   159,   162,   164,   166,   168,   170,   172,   174,   177,
+     180,   184,   186,   189,   191,   194,   196,   199,   202,   203,
+     207,   209,   213,   216,   217,   220,   223,   227,   231,   235,
+     237,   239,   240,   242,   244,   246,   248,   250,   252,   254,
+     256,   257
 };
 
 /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
 static const yytype_int8 yyrhs[] =
 {
-      60,     0,    -1,    61,    51,    76,    89,    -1,    -1,    61,
-      62,    -1,    63,    -1,    53,    -1,    17,    -1,    19,    82,
-      83,    -1,    20,    -1,    20,     3,    -1,    21,    -1,    22,
-       4,    -1,    23,     4,    -1,    24,     3,    -1,    24,    48,
-       3,    -1,    25,    -1,    26,    45,    -1,    27,     3,    -1,
-      28,    45,    -1,    29,    -1,    30,     3,    -1,    30,    48,
+      58,     0,    -1,    59,    49,    74,    87,    -1,    -1,    59,
+      60,    -1,    61,    -1,    51,    -1,    17,    -1,    19,    80,
+      81,    -1,    20,    -1,    20,     3,    -1,    21,    -1,    22,
+       4,    -1,    23,     4,    -1,    24,     3,    -1,    24,    46,
+       3,    -1,    25,    -1,    26,    43,    -1,    27,     3,    -1,
+      28,    43,    -1,    29,    -1,    30,     3,    -1,    30,    46,
        3,    -1,    32,    -1,    33,    -1,    34,     3,    -1,    34,
-      48,     3,    -1,    35,    45,    -1,    36,    -1,    37,    -1,
-      38,    -1,    39,     3,    -1,    40,     3,    -1,    42,    -1,
-      43,    -1,    44,    -1,    54,    -1,    68,    -1,    65,    -1,
-      41,    87,    -1,     8,    45,    72,    -1,     9,    45,    72,
-      -1,    18,    -1,    31,    -1,    16,    84,    -1,    16,    49,
-      84,    -1,    -1,    49,    -1,    58,    64,    84,    -1,    -1,
-       6,    66,    75,    -1,    -1,     5,    67,    75,    -1,     7,
-      55,    71,    -1,    69,    70,    71,    -1,    10,    -1,    11,
-      -1,    12,    -1,    -1,    55,    -1,    87,    -1,    71,    87,
-      -1,    73,    -1,    72,    73,    -1,    87,    -1,    55,    -1,
-      56,    -1,    57,    -1,    55,    -1,    85,    -1,    85,     4,
-      -1,    85,    88,    -1,    85,     4,    88,    -1,    74,    -1,
-      75,    74,    -1,    77,    -1,    76,    77,    -1,    78,    -1,
-      63,    54,    -1,     1,    54,    -1,    -1,    86,    79,    80,
-      -1,    81,    -1,    80,    52,    81,    -1,    80,    54,    -1,
-      -1,    81,    87,    -1,    81,    45,    -1,    81,    13,    87,
-      -1,    81,    14,     4,    -1,    81,    15,    55,    -1,    49,
-      -1,     3,    -1,    -1,     3,    -1,    45,    -1,    49,    -1,
-      46,    -1,    50,    -1,    85,    -1,    88,    -1,     3,    -1,
-      -1,    51,    47,    -1
+      46,     3,    -1,    35,    43,    -1,    36,    -1,    37,     3,
+      -1,    38,     3,    -1,    40,    -1,    41,    -1,    42,    -1,
+      52,    -1,    66,    -1,    63,    -1,    39,    85,    -1,     8,
+      43,    70,    -1,     9,    43,    70,    -1,    18,    -1,    31,
+      -1,    16,    82,    -1,    16,    47,    82,    -1,    -1,    47,
+      -1,    56,    62,    82,    -1,    -1,     6,    64,    73,    -1,
+      -1,     5,    65,    73,    -1,     7,    53,    69,    -1,    67,
+      68,    69,    -1,    10,    -1,    11,    -1,    12,    -1,    -1,
+      53,    -1,    85,    -1,    69,    85,    -1,    71,    -1,    70,
+      71,    -1,    85,    -1,    53,    -1,    54,    -1,    55,    -1,
+      53,    -1,    83,    -1,    83,     4,    -1,    83,    86,    -1,
+      83,     4,    86,    -1,    72,    -1,    73,    72,    -1,    75,
+      -1,    74,    75,    -1,    76,    -1,    61,    52,    -1,     1,
+      52,    -1,    -1,    84,    77,    78,    -1,    79,    -1,    78,
+      50,    79,    -1,    78,    52,    -1,    -1,    79,    85,    -1,
+      79,    43,    -1,    79,    13,    85,    -1,    79,    14,     4,
+      -1,    79,    15,    53,    -1,    47,    -1,     3,    -1,    -1,
+       3,    -1,    43,    -1,    47,    -1,    44,    -1,    48,    -1,
+      83,    -1,    86,    -1,     3,    -1,    -1,    49,    45,    -1
 };
 
 /* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
 static const yytype_uint16 yyrline[] =
 {
-       0,   207,   207,   215,   217,   221,   222,   232,   233,   237,
-     238,   243,   244,   245,   246,   247,   248,   253,   262,   263,
-     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
-     274,   275,   276,   300,   301,   302,   303,   307,   308,   309,
-     313,   320,   327,   331,   335,   342,   357,   358,   362,   374,
-     374,   379,   379,   384,   395,   410,   411,   412,   416,   417,
-     422,   424,   429,   430,   434,   435,   436,   437,   442,   447,
-     452,   458,   464,   475,   476,   485,   486,   492,   493,   494,
-     501,   501,   505,   506,   507,   512,   513,   515,   517,   519,
-     521,   531,   532,   538,   541,   550,   570,   572,   581,   586,
-     587,   592,   599,   601
+       0,   204,   204,   212,   214,   218,   219,   229,   230,   234,
+     235,   240,   241,   242,   243,   244,   245,   250,   259,   260,
+     261,   262,   263,   264,   265,   266,   267,   268,   269,   270,
+     271,   295,   296,   297,   298,   302,   303,   304,   308,   315,
+     322,   326,   330,   337,   352,   353,   357,   369,   369,   374,
+     374,   379,   390,   405,   406,   407,   411,   412,   417,   419,
+     424,   425,   429,   430,   431,   432,   437,   442,   447,   453,
+     459,   470,   471,   480,   481,   487,   488,   489,   496,   496,
+     500,   501,   502,   507,   508,   510,   512,   514,   516,   526,
+     527,   533,   536,   545,   565,   567,   576,   581,   582,   587,
+     594,   596
 };
 #endif
 
@@ -698,19 +687,18 @@ static const char *const yytname[] =
   "\"%initial-action\"", "\"%language\"", "\"%lex-param\"",
   "\"%locations\"", "\"%name-prefix\"", "\"%no-default-prec\"",
   "\"%no-lines\"", "\"%nondeterministic-parser\"", "\"%output\"",
-  "\"%parse-param\"", "\"%pure-parser\"", "\"%push-parser\"",
-  "\"%push-pull-parser\"", "\"%require\"", "\"%skeleton\"", "\"%start\"",
-  "\"%token-table\"", "\"%verbose\"", "\"%yacc\"", "\"{...}\"", "\"char\"",
-  "\"epilogue\"", "\"=\"", "\"identifier\"", "\"identifier:\"", "\"%%\"",
-  "\"|\"", "\"%{...%}\"", "\";\"", "\"type\"", "\"<*>\"", "\"<>\"",
-  "\"%union\"", "$accept", "input", "prologue_declarations",
-  "prologue_declaration", "grammar_declaration", "union_name",
-  "symbol_declaration", "$@1", "$@2", "precedence_declaration",
-  "precedence_declarator", "type.opt", "symbols.1", "generic_symlist",
-  "generic_symlist_item", "symbol_def", "symbol_defs.1", "grammar",
-  "rules_or_grammar_declaration", "rules", "$@3", "rhses.1", "rhs",
-  "variable", "content.opt", "braceless", "id", "id_colon", "symbol",
-  "string_as_id", "epilogue.opt", 0
+  "\"%parse-param\"", "\"%pure-parser\"", "\"%require\"", "\"%skeleton\"",
+  "\"%start\"", "\"%token-table\"", "\"%verbose\"", "\"%yacc\"",
+  "\"{...}\"", "\"char\"", "\"epilogue\"", "\"=\"", "\"identifier\"",
+  "\"identifier:\"", "\"%%\"", "\"|\"", "\"%{...%}\"", "\";\"", "\"type\"",
+  "\"<*>\"", "\"<>\"", "\"%union\"", "$accept", "input",
+  "prologue_declarations", "prologue_declaration", "grammar_declaration",
+  "union_name", "symbol_declaration", "$@1", "$@2",
+  "precedence_declaration", "precedence_declarator", "type.opt",
+  "symbols.1", "generic_symlist", "generic_symlist_item", "symbol_def",
+  "symbol_defs.1", "grammar", "rules_or_grammar_declaration", "rules",
+  "$@3", "rhses.1", "rhs", "variable", "content.opt", "braceless", "id",
+  "id_colon", "symbol", "string_as_id", "epilogue.opt", 0
 };
 #endif
 
@@ -724,24 +712,24 @@ static const yytype_uint16 yytoknum[] =
      275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
      285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
      295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
-     305,   306,   307,   308,   309,   310,   311,   312,   313
+     305,   306,   307,   308,   309,   310,   311
 };
 # endif
 
 /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
 static const yytype_uint8 yyr1[] =
 {
-       0,    59,    60,    61,    61,    62,    62,    62,    62,    62,
-      62,    62,    62,    62,    62,    62,    62,    62,    62,    62,
-      62,    62,    62,    62,    62,    62,    62,    62,    62,    62,
-      62,    62,    62,    62,    62,    62,    62,    63,    63,    63,
-      63,    63,    63,    63,    63,    63,    64,    64,    63,    66,
-      65,    67,    65,    65,    68,    69,    69,    69,    70,    70,
-      71,    71,    72,    72,    73,    73,    73,    73,    74,    74,
-      74,    74,    74,    75,    75,    76,    76,    77,    77,    77,
-      79,    78,    80,    80,    80,    81,    81,    81,    81,    81,
-      81,    82,    82,    83,    83,    84,    85,    85,    86,    87,
-      87,    88,    89,    89
+       0,    57,    58,    59,    59,    60,    60,    60,    60,    60,
+      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
+      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
+      60,    60,    60,    60,    60,    61,    61,    61,    61,    61,
+      61,    61,    61,    61,    62,    62,    61,    64,    63,    65,
+      63,    63,    66,    67,    67,    67,    68,    68,    69,    69,
+      70,    70,    71,    71,    71,    71,    72,    72,    72,    72,
+      72,    73,    73,    74,    74,    75,    75,    75,    77,    76,
+      78,    78,    78,    79,    79,    79,    79,    79,    79,    80,
+      80,    81,    81,    82,    83,    83,    84,    85,    85,    86,
+      87,    87
 };
 
 /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
@@ -749,15 +737,15 @@ static const yytype_uint8 yyr2[] =
 {
        0,     2,     4,     0,     2,     1,     1,     1,     3,     1,
        2,     1,     2,     2,     2,     3,     1,     2,     2,     2,
-       1,     2,     3,     1,     1,     2,     3,     2,     1,     1,
-       1,     2,     2,     1,     1,     1,     1,     1,     1,     2,
-       3,     3,     1,     1,     2,     3,     0,     1,     3,     0,
-       3,     0,     3,     3,     3,     1,     1,     1,     0,     1,
-       1,     2,     1,     2,     1,     1,     1,     1,     1,     1,
-       2,     2,     3,     1,     2,     1,     2,     1,     2,     2,
-       0,     3,     1,     3,     2,     0,     2,     2,     3,     3,
-       3,     1,     1,     0,     1,     1,     1,     1,     1,     1,
-       1,     1,     0,     2
+       1,     2,     3,     1,     1,     2,     3,     2,     1,     2,
+       2,     1,     1,     1,     1,     1,     1,     2,     3,     3,
+       1,     1,     2,     3,     0,     1,     3,     0,     3,     0,
+       3,     3,     3,     1,     1,     1,     0,     1,     1,     2,
+       1,     2,     1,     1,     1,     1,     1,     1,     2,     2,
+       3,     1,     2,     1,     2,     1,     2,     2,     0,     3,
+       1,     3,     2,     0,     2,     2,     3,     3,     3,     1,
+       1,     0,     1,     1,     1,     1,     1,     1,     1,     1,
+       0,     2
 };
 
 /* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
@@ -765,127 +753,124 @@ static const yytype_uint8 yyr2[] =
    means the default is an error.  */
 static const yytype_uint8 yydefact[] =
 {
-       3,     0,     0,     1,    51,    49,     0,     0,     0,    55,
-      56,    57,     0,     7,    42,     0,     9,    11,     0,     0,
-       0,    16,     0,     0,     0,    20,     0,    43,    23,    24,
-       0,     0,    28,    29,    30,     0,     0,     0,    33,    34,
-      35,     0,     6,    36,    46,     4,     5,    38,    37,    58,
-       0,     0,     0,     0,     0,    95,     0,    44,    92,    91,
-      93,    10,    12,    13,    14,     0,    17,    18,    19,    21,
-       0,    25,     0,    27,    31,    32,   101,    97,    96,    99,
-      39,   100,     0,    98,     0,     0,    75,    77,    80,    47,
-       0,    59,     0,    68,    73,    52,    69,    50,    53,    60,
-      65,    66,    67,    40,    62,    64,    41,    45,    94,     8,
-      15,    22,    26,    79,    78,     0,    76,     2,    85,    48,
-      54,    74,    70,    71,    61,    63,   103,    81,    82,    72,
-      85,    84,     0,     0,     0,    87,    86,    83,    88,    89,
-      90
+       3,     0,     0,     1,    49,    47,     0,     0,     0,    53,
+      54,    55,     0,     7,    40,     0,     9,    11,     0,     0,
+       0,    16,     0,     0,     0,    20,     0,    41,    23,    24,
+       0,     0,    28,     0,     0,     0,    31,    32,    33,     0,
+       6,    34,    44,     4,     5,    36,    35,    56,     0,     0,
+       0,     0,     0,    93,     0,    42,    90,    89,    91,    10,
+      12,    13,    14,     0,    17,    18,    19,    21,     0,    25,
+       0,    27,    29,    30,    99,    95,    94,    97,    37,    98,
+       0,    96,     0,     0,    73,    75,    78,    45,     0,    57,
+       0,    66,    71,    50,    67,    48,    51,    58,    63,    64,
+      65,    38,    60,    62,    39,    43,    92,     8,    15,    22,
+      26,    77,    76,     0,    74,     2,    83,    46,    52,    72,
+      68,    69,    59,    61,   101,    79,    80,    70,    83,    82,
+       0,     0,     0,    85,    84,    81,    86,    87,    88
 };
 
 /* YYDEFGOTO[NTERM-NUM].  */
-static const yytype_int16 yydefgoto[] =
+static const yytype_int8 yydefgoto[] =
 {
-      -1,     1,     2,    45,    84,    90,    47,    51,    50,    48,
-      49,    92,    98,   103,   104,    94,    95,    85,    86,    87,
-     118,   127,   128,    60,   109,    57,    79,    88,   105,    81,
-     117
+      -1,     1,     2,    43,    82,    88,    45,    49,    48,    46,
+      47,    90,    96,   101,   102,    92,    93,    83,    84,    85,
+     116,   125,   126,    58,   107,    55,    77,    86,   103,    79,
+     115
 };
 
 /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
    STATE-NUM.  */
-#define YYPACT_NINF -79
+#define YYPACT_NINF -60
 static const yytype_int16 yypact[] =
 {
-     -79,     5,    96,   -79,   -79,   -79,    -6,    13,    18,   -79,
-     -79,   -79,    -8,   -79,   -79,    27,    66,   -79,    74,    82,
-      31,   -79,    43,    86,    45,   -79,    32,   -79,   -79,   -79,
-      33,    47,   -79,   -79,   -79,    91,    93,    26,   -79,   -79,
-     -79,    15,   -79,   -79,    48,   -79,   -79,   -79,   -79,    44,
-      38,    38,    26,    11,    11,   -79,    53,   -79,   -79,   -79,
-     106,   -79,   -79,   -79,   -79,   107,   -79,   -79,   -79,   -79,
-     108,   -79,   138,   -79,   -79,   -79,   -79,   -79,   -79,   -79,
-     -79,   -79,    88,   -79,    89,     1,   -79,   -79,   -79,   -79,
-      53,   -79,    26,   -79,   -79,    38,    50,    38,    26,   -79,
-     -79,   -79,   -79,    11,   -79,   -79,    11,   -79,   -79,   -79,
-     -79,   -79,   -79,   -79,   -79,    97,   -79,   -79,   -79,   -79,
-      26,   -79,   142,   -79,   -79,   -79,   -79,    -7,    25,   -79,
-     -79,   -79,    26,   144,    98,   -79,   -79,    25,   -79,   -79,
-     -79
+     -60,    18,    96,   -60,   -60,   -60,   -16,    17,    24,   -60,
+     -60,   -60,    -8,   -60,   -60,    11,    70,   -60,    71,    80,
+       2,   -60,    46,    87,    49,   -60,    31,   -60,   -60,   -60,
+      40,    50,   -60,    91,    93,     0,   -60,   -60,   -60,    15,
+     -60,   -60,    51,   -60,   -60,   -60,   -60,    44,    12,    12,
+       0,    25,    25,   -60,    56,   -60,   -60,   -60,   106,   -60,
+     -60,   -60,   -60,   107,   -60,   -60,   -60,   -60,   108,   -60,
+     136,   -60,   -60,   -60,   -60,   -60,   -60,   -60,   -60,   -60,
+      88,   -60,    89,     1,   -60,   -60,   -60,   -60,    56,   -60,
+       0,   -60,   -60,    12,    84,    12,     0,   -60,   -60,   -60,
+     -60,    25,   -60,   -60,    25,   -60,   -60,   -60,   -60,   -60,
+     -60,   -60,   -60,    97,   -60,   -60,   -60,   -60,     0,   -60,
+     140,   -60,   -60,   -60,   -60,    14,    38,   -60,   -60,   -60,
+       0,   142,    98,   -60,   -60,    38,   -60,   -60,   -60
 };
 
 /* YYPGOTO[NTERM-NUM].  */
 static const yytype_int16 yypgoto[] =
 {
-     -79,   -79,   -79,   -79,   149,   -79,   -79,   -79,   -79,   -79,
-     -79,   -79,    54,   101,   -21,   -33,   105,   -79,    67,   -79,
-     -79,   -79,    28,   -79,   -79,   -13,   -47,   -79,   -37,   -78,
-     -79
+     -60,   -60,   -60,   -60,   147,   -60,   -60,   -60,   -60,   -60,
+     -60,   -60,    54,   101,   -59,   -25,   105,   -60,    67,   -60,
+     -60,   -60,    27,   -60,   -60,   -50,   -19,   -60,   -35,   -58,
+     -60
 };
 
 /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
    positive, shift that token.  If negative, reduce the rule which
    number is the opposite.  If zero, do what YYDEFACT says.
    If YYTABLE_NINF, syntax error.  */
-#define YYTABLE_NINF -103
+#define YYTABLE_NINF -101
 static const yytype_int16 yytable[] =
 {
-      80,  -102,    82,    96,    96,     3,     4,     5,     6,     7,
-       8,     9,    10,    11,    76,    99,    82,    12,   123,    14,
-       4,     5,     6,     7,     8,     9,    10,    11,    76,    76,
-      58,    12,    27,    14,    64,    69,    71,    55,   132,   133,
-     134,    56,    37,   107,   129,   130,    27,   131,    96,    52,
-      96,    83,   115,    76,   122,    99,    37,    77,    53,    44,
-      78,   124,   121,    54,   121,    83,   100,   101,   102,    61,
-     135,    77,    77,    44,    78,    78,    59,   119,    62,    65,
-      70,    72,   125,   124,    77,   125,    63,    78,    66,    67,
-      68,   136,    73,    93,    74,   138,    75,    89,    55,    91,
-     136,     4,     5,     6,     7,     8,     9,    10,    11,   108,
-     110,   111,    12,    13,    14,    15,    16,    17,    18,    19,
+      78,  -100,    80,    74,   105,    62,     4,     5,     6,     7,
+       8,     9,    10,    11,    56,    97,    80,    12,     3,    14,
+       4,     5,     6,     7,     8,     9,    10,    11,    74,    94,
+      94,    12,    27,    14,    67,    53,   121,    50,   117,    54,
+      35,    74,   123,    69,    75,   123,    27,    76,    63,    81,
+     113,   130,   131,   132,    35,    97,    75,    42,    57,    76,
+      51,   122,   127,    81,   128,    91,   129,    52,   119,    75,
+     119,    42,    76,    59,    94,    60,    94,    68,    98,    99,
+     100,   133,    75,   122,    61,    76,    70,    74,   120,    64,
+      65,   134,    66,    71,    72,   136,    73,    89,    87,    53,
+     134,     4,     5,     6,     7,     8,     9,    10,    11,   106,
+     108,   109,    12,    13,    14,    15,    16,    17,    18,    19,
       20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
-      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
-      40,   112,   113,   114,   126,    76,   120,    41,   139,    42,
-      43,    46,   116,   140,    44,   106,    97,     0,   137
+      30,    31,    32,    33,    34,    35,    36,    37,    38,   110,
+     111,   112,   124,    74,   118,    39,   137,    40,    41,    44,
+     114,   138,    42,   104,    95,   135
 };
 
-static const yytype_int16 yycheck[] =
+static const yytype_uint8 yycheck[] =
 {
-      37,     0,     1,    50,    51,     0,     5,     6,     7,     8,
-       9,    10,    11,    12,     3,    52,     1,    16,    96,    18,
-       5,     6,     7,     8,     9,    10,    11,    12,     3,     3,
-       3,    16,    31,    18,     3,     3,     3,    45,    13,    14,
-      15,    49,    41,    56,   122,    52,    31,    54,    95,    55,
-      97,    50,    51,     3,     4,    92,    41,    46,    45,    58,
-      49,    98,    95,    45,    97,    50,    55,    56,    57,     3,
-      45,    46,    46,    58,    49,    49,    49,    90,     4,    48,
-      48,    48,   103,   120,    46,   106,     4,    49,    45,     3,
-      45,   128,    45,    55,     3,   132,     3,    49,    45,    55,
-     137,     5,     6,     7,     8,     9,    10,    11,    12,     3,
+      35,     0,     1,     3,    54,     3,     5,     6,     7,     8,
+       9,    10,    11,    12,     3,    50,     1,    16,     0,    18,
+       5,     6,     7,     8,     9,    10,    11,    12,     3,    48,
+      49,    16,    31,    18,     3,    43,    94,    53,    88,    47,
+      39,     3,   101,     3,    44,   104,    31,    47,    46,    48,
+      49,    13,    14,    15,    39,    90,    44,    56,    47,    47,
+      43,    96,   120,    48,    50,    53,    52,    43,    93,    44,
+      95,    56,    47,     3,    93,     4,    95,    46,    53,    54,
+      55,    43,    44,   118,     4,    47,    46,     3,     4,    43,
+       3,   126,    43,    43,     3,   130,     3,    53,    47,    43,
+     135,     5,     6,     7,     8,     9,    10,    11,    12,     3,
        3,     3,    16,    17,    18,    19,    20,    21,    22,    23,
       24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
-      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
-      44,     3,    54,    54,    47,     3,    92,    51,     4,    53,
-      54,     2,    85,    55,    58,    54,    51,    -1,   130
+      34,    35,    36,    37,    38,    39,    40,    41,    42,     3,
+      52,    52,    45,     3,    90,    49,     4,    51,    52,     2,
+      83,    53,    56,    52,    49,   128
 };
 
 /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
    symbol of state STATE-NUM.  */
 static const yytype_uint8 yystos[] =
 {
-       0,    60,    61,     0,     5,     6,     7,     8,     9,    10,
+       0,    58,    59,     0,     5,     6,     7,     8,     9,    10,
       11,    12,    16,    17,    18,    19,    20,    21,    22,    23,
       24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
-      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
-      44,    51,    53,    54,    58,    62,    63,    65,    68,    69,
-      67,    66,    55,    45,    45,    45,    49,    84,     3,    49,
-      82,     3,     4,     4,     3,    48,    45,     3,    45,     3,
-      48,     3,    48,    45,     3,     3,     3,    46,    49,    85,
-      87,    88,     1,    50,    63,    76,    77,    78,    86,    49,
-      64,    55,    70,    55,    74,    75,    85,    75,    71,    87,
-      55,    56,    57,    72,    73,    87,    72,    84,     3,    83,
-       3,     3,     3,    54,    54,    51,    77,    89,    79,    84,
-      71,    74,     4,    88,    87,    73,    47,    80,    81,    88,
-      52,    54,    13,    14,    15,    45,    87,    81,    87,     4,
-      55
+      34,    35,    36,    37,    38,    39,    40,    41,    42,    49,
+      51,    52,    56,    60,    61,    63,    66,    67,    65,    64,
+      53,    43,    43,    43,    47,    82,     3,    47,    80,     3,
+       4,     4,     3,    46,    43,     3,    43,     3,    46,     3,
+      46,    43,     3,     3,     3,    44,    47,    83,    85,    86,
+       1,    48,    61,    74,    75,    76,    84,    47,    62,    53,
+      68,    53,    72,    73,    83,    73,    69,    85,    53,    54,
+      55,    70,    71,    85,    70,    82,     3,    81,     3,     3,
+       3,    52,    52,    49,    75,    87,    77,    82,    69,    72,
+       4,    86,    85,    71,    45,    78,    79,    86,    50,    52,
+      13,    14,    15,    43,    85,    79,    85,     4,    53
 };
 
 #define yyerrok		(yyerrstatus = 0)
@@ -1035,147 +1020,147 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
     {
       case 3: /* "\"string\"" */
 
-/* Line 1535 of yacc.c  */
-#line 185 "parse-gram.y"
+/* Line 1538 of yacc.c  */
+#line 182 "parse-gram.y"
 	{ fputs (quotearg_style (c_quoting_style, (yyvaluep->chars)), stderr); };
 
-/* Line 1535 of yacc.c  */
-#line 1044 "parse-gram.c"
+/* Line 1538 of yacc.c  */
+#line 1029 "parse-gram.c"
 	break;
       case 4: /* "\"integer\"" */
 
-/* Line 1535 of yacc.c  */
-#line 196 "parse-gram.y"
+/* Line 1538 of yacc.c  */
+#line 193 "parse-gram.y"
 	{ fprintf (stderr, "%d", (yyvaluep->integer)); };
 
-/* Line 1535 of yacc.c  */
-#line 1053 "parse-gram.c"
+/* Line 1538 of yacc.c  */
+#line 1038 "parse-gram.c"
 	break;
-      case 45: /* "\"{...}\"" */
+      case 43: /* "\"{...}\"" */
 
-/* Line 1535 of yacc.c  */
-#line 187 "parse-gram.y"
+/* Line 1538 of yacc.c  */
+#line 184 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->code)); };
 
-/* Line 1535 of yacc.c  */
-#line 1062 "parse-gram.c"
+/* Line 1538 of yacc.c  */
+#line 1047 "parse-gram.c"
 	break;
-      case 46: /* "\"char\"" */
+      case 44: /* "\"char\"" */
 
-/* Line 1535 of yacc.c  */
-#line 179 "parse-gram.y"
+/* Line 1538 of yacc.c  */
+#line 176 "parse-gram.y"
 	{ fputs (char_name ((yyvaluep->character)), stderr); };
 
-/* Line 1535 of yacc.c  */
-#line 1071 "parse-gram.c"
+/* Line 1538 of yacc.c  */
+#line 1056 "parse-gram.c"
 	break;
-      case 47: /* "\"epilogue\"" */
+      case 45: /* "\"epilogue\"" */
 
-/* Line 1535 of yacc.c  */
-#line 187 "parse-gram.y"
+/* Line 1538 of yacc.c  */
+#line 184 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
-/* Line 1535 of yacc.c  */
-#line 1080 "parse-gram.c"
+/* Line 1538 of yacc.c  */
+#line 1065 "parse-gram.c"
 	break;
-      case 49: /* "\"identifier\"" */
+      case 47: /* "\"identifier\"" */
 
-/* Line 1535 of yacc.c  */
-#line 192 "parse-gram.y"
+/* Line 1538 of yacc.c  */
+#line 189 "parse-gram.y"
 	{ fputs ((yyvaluep->uniqstr), stderr); };
 
-/* Line 1535 of yacc.c  */
-#line 1089 "parse-gram.c"
+/* Line 1538 of yacc.c  */
+#line 1074 "parse-gram.c"
 	break;
-      case 50: /* "\"identifier:\"" */
+      case 48: /* "\"identifier:\"" */
 
-/* Line 1535 of yacc.c  */
-#line 193 "parse-gram.y"
+/* Line 1538 of yacc.c  */
+#line 190 "parse-gram.y"
 	{ fprintf (stderr, "%s:", (yyvaluep->uniqstr)); };
 
-/* Line 1535 of yacc.c  */
-#line 1098 "parse-gram.c"
+/* Line 1538 of yacc.c  */
+#line 1083 "parse-gram.c"
 	break;
-      case 53: /* "\"%{...%}\"" */
+      case 51: /* "\"%{...%}\"" */
 
-/* Line 1535 of yacc.c  */
-#line 187 "parse-gram.y"
+/* Line 1538 of yacc.c  */
+#line 184 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
-/* Line 1535 of yacc.c  */
-#line 1107 "parse-gram.c"
+/* Line 1538 of yacc.c  */
+#line 1092 "parse-gram.c"
 	break;
-      case 55: /* "\"type\"" */
+      case 53: /* "\"type\"" */
 
-/* Line 1535 of yacc.c  */
-#line 191 "parse-gram.y"
+/* Line 1538 of yacc.c  */
+#line 188 "parse-gram.y"
 	{ fprintf (stderr, "<%s>", (yyvaluep->uniqstr)); };
 
-/* Line 1535 of yacc.c  */
-#line 1116 "parse-gram.c"
+/* Line 1538 of yacc.c  */
+#line 1101 "parse-gram.c"
 	break;
-      case 82: /* "variable" */
+      case 80: /* "variable" */
 
-/* Line 1535 of yacc.c  */
-#line 192 "parse-gram.y"
+/* Line 1538 of yacc.c  */
+#line 189 "parse-gram.y"
 	{ fputs ((yyvaluep->uniqstr), stderr); };
 
-/* Line 1535 of yacc.c  */
-#line 1125 "parse-gram.c"
+/* Line 1538 of yacc.c  */
+#line 1110 "parse-gram.c"
 	break;
-      case 83: /* "content.opt" */
+      case 81: /* "content.opt" */
 
-/* Line 1535 of yacc.c  */
-#line 187 "parse-gram.y"
+/* Line 1538 of yacc.c  */
+#line 184 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
-/* Line 1535 of yacc.c  */
-#line 1134 "parse-gram.c"
+/* Line 1538 of yacc.c  */
+#line 1119 "parse-gram.c"
 	break;
-      case 84: /* "braceless" */
+      case 82: /* "braceless" */
 
-/* Line 1535 of yacc.c  */
-#line 187 "parse-gram.y"
+/* Line 1538 of yacc.c  */
+#line 184 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
-/* Line 1535 of yacc.c  */
-#line 1143 "parse-gram.c"
+/* Line 1538 of yacc.c  */
+#line 1128 "parse-gram.c"
 	break;
-      case 85: /* "id" */
+      case 83: /* "id" */
 
-/* Line 1535 of yacc.c  */
-#line 199 "parse-gram.y"
+/* Line 1538 of yacc.c  */
+#line 196 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
-/* Line 1535 of yacc.c  */
-#line 1152 "parse-gram.c"
+/* Line 1538 of yacc.c  */
+#line 1137 "parse-gram.c"
 	break;
-      case 86: /* "id_colon" */
+      case 84: /* "id_colon" */
 
-/* Line 1535 of yacc.c  */
-#line 200 "parse-gram.y"
+/* Line 1538 of yacc.c  */
+#line 197 "parse-gram.y"
 	{ fprintf (stderr, "%s:", (yyvaluep->symbol)->tag); };
 
-/* Line 1535 of yacc.c  */
-#line 1161 "parse-gram.c"
+/* Line 1538 of yacc.c  */
+#line 1146 "parse-gram.c"
 	break;
-      case 87: /* "symbol" */
+      case 85: /* "symbol" */
 
-/* Line 1535 of yacc.c  */
-#line 199 "parse-gram.y"
+/* Line 1538 of yacc.c  */
+#line 196 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
-/* Line 1535 of yacc.c  */
-#line 1170 "parse-gram.c"
+/* Line 1538 of yacc.c  */
+#line 1155 "parse-gram.c"
 	break;
-      case 88: /* "string_as_id" */
+      case 86: /* "string_as_id" */
 
-/* Line 1535 of yacc.c  */
-#line 199 "parse-gram.y"
+/* Line 1538 of yacc.c  */
+#line 196 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
-/* Line 1535 of yacc.c  */
-#line 1179 "parse-gram.c"
+/* Line 1538 of yacc.c  */
+#line 1164 "parse-gram.c"
 	break;
       default:
 	break;
@@ -1689,7 +1674,7 @@ YYLTYPE yylloc;
 
   /* User initialization code.  */
   
-/* Line 1535 of yacc.c  */
+/* Line 1538 of yacc.c  */
 #line 86 "parse-gram.y"
 {
   /* Bison's grammar can initial empty locations, hence a default
@@ -1698,8 +1683,8 @@ YYLTYPE yylloc;
   boundary_set (&yylloc.end, current_file, 1, 1);
 }
 
-/* Line 1535 of yacc.c  */
-#line 1703 "parse-gram.c"
+/* Line 1538 of yacc.c  */
+#line 1688 "parse-gram.c"
   yylsp[0] = yylloc;
   goto yysetstate;
 
@@ -1884,8 +1869,8 @@ yyreduce:
     {
         case 6:
 
-/* Line 1535 of yacc.c  */
-#line 223 "parse-gram.y"
+/* Line 1538 of yacc.c  */
+#line 220 "parse-gram.y"
     {
       code_props plain_code;
       code_props_plain_init (&plain_code, (yyvsp[(1) - (1)].chars), (yylsp[(1) - (1)]));
@@ -1899,15 +1884,15 @@ yyreduce:
 
   case 7:
 
-/* Line 1535 of yacc.c  */
-#line 232 "parse-gram.y"
+/* Line 1538 of yacc.c  */
+#line 229 "parse-gram.y"
     { debug_flag = true; }
     break;
 
   case 8:
 
-/* Line 1535 of yacc.c  */
-#line 234 "parse-gram.y"
+/* Line 1538 of yacc.c  */
+#line 231 "parse-gram.y"
     {
       muscle_percent_define_insert ((yyvsp[(2) - (3)].uniqstr), (yylsp[(2) - (3)]), (yyvsp[(3) - (3)].chars));
     }
@@ -1915,15 +1900,15 @@ yyreduce:
 
   case 9:
 
-/* Line 1535 of yacc.c  */
-#line 237 "parse-gram.y"
+/* Line 1538 of yacc.c  */
+#line 234 "parse-gram.y"
     { defines_flag = true; }
     break;
 
   case 10:
 
-/* Line 1535 of yacc.c  */
-#line 239 "parse-gram.y"
+/* Line 1538 of yacc.c  */
+#line 236 "parse-gram.y"
     {
       defines_flag = true;
       spec_defines_file = xstrdup ((yyvsp[(2) - (2)].chars));
@@ -1932,43 +1917,43 @@ yyreduce:
 
   case 11:
 
-/* Line 1535 of yacc.c  */
-#line 243 "parse-gram.y"
+/* Line 1538 of yacc.c  */
+#line 240 "parse-gram.y"
     { error_verbose = true; }
     break;
 
   case 12:
 
-/* Line 1535 of yacc.c  */
-#line 244 "parse-gram.y"
+/* Line 1538 of yacc.c  */
+#line 241 "parse-gram.y"
     { expected_sr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 13:
 
-/* Line 1535 of yacc.c  */
-#line 245 "parse-gram.y"
+/* Line 1538 of yacc.c  */
+#line 242 "parse-gram.y"
     { expected_rr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 14:
 
-/* Line 1535 of yacc.c  */
-#line 246 "parse-gram.y"
+/* Line 1538 of yacc.c  */
+#line 243 "parse-gram.y"
     { spec_file_prefix = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 15:
 
-/* Line 1535 of yacc.c  */
-#line 247 "parse-gram.y"
+/* Line 1538 of yacc.c  */
+#line 244 "parse-gram.y"
     { spec_file_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 16:
 
-/* Line 1535 of yacc.c  */
-#line 249 "parse-gram.y"
+/* Line 1538 of yacc.c  */
+#line 246 "parse-gram.y"
     {
       nondeterministic_parser = true;
       glr_parser = true;
@@ -1977,8 +1962,8 @@ yyreduce:
 
   case 17:
 
-/* Line 1535 of yacc.c  */
-#line 254 "parse-gram.y"
+/* Line 1538 of yacc.c  */
+#line 251 "parse-gram.y"
     {
       code_props action;
       code_props_symbol_action_init (&action, (yyvsp[(2) - (2)].code), (yylsp[(2) - (2)]));
@@ -1991,106 +1976,92 @@ yyreduce:
 
   case 18:
 
-/* Line 1535 of yacc.c  */
-#line 262 "parse-gram.y"
+/* Line 1538 of yacc.c  */
+#line 259 "parse-gram.y"
     { language_argmatch ((yyvsp[(2) - (2)].chars), 1, &(yylsp[(1) - (2)])); }
     break;
 
   case 19:
 
-/* Line 1535 of yacc.c  */
-#line 263 "parse-gram.y"
+/* Line 1538 of yacc.c  */
+#line 260 "parse-gram.y"
     { add_param ("lex_param", (yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
     break;
 
   case 20:
 
-/* Line 1535 of yacc.c  */
-#line 264 "parse-gram.y"
+/* Line 1538 of yacc.c  */
+#line 261 "parse-gram.y"
     { locations_flag = true; }
     break;
 
   case 21:
 
-/* Line 1535 of yacc.c  */
-#line 265 "parse-gram.y"
+/* Line 1538 of yacc.c  */
+#line 262 "parse-gram.y"
     { spec_name_prefix = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 22:
 
-/* Line 1535 of yacc.c  */
-#line 266 "parse-gram.y"
+/* Line 1538 of yacc.c  */
+#line 263 "parse-gram.y"
     { spec_name_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 23:
 
-/* Line 1535 of yacc.c  */
-#line 267 "parse-gram.y"
+/* Line 1538 of yacc.c  */
+#line 264 "parse-gram.y"
     { no_lines_flag = true; }
     break;
 
   case 24:
 
-/* Line 1535 of yacc.c  */
-#line 268 "parse-gram.y"
+/* Line 1538 of yacc.c  */
+#line 265 "parse-gram.y"
     { nondeterministic_parser = true; }
     break;
 
   case 25:
 
-/* Line 1535 of yacc.c  */
-#line 269 "parse-gram.y"
+/* Line 1538 of yacc.c  */
+#line 266 "parse-gram.y"
     { spec_outfile = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 26:
 
-/* Line 1535 of yacc.c  */
-#line 270 "parse-gram.y"
+/* Line 1538 of yacc.c  */
+#line 267 "parse-gram.y"
     { spec_outfile = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 27:
 
-/* Line 1535 of yacc.c  */
-#line 271 "parse-gram.y"
+/* Line 1538 of yacc.c  */
+#line 268 "parse-gram.y"
     { add_param ("parse_param", (yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
     break;
 
   case 28:
 
-/* Line 1535 of yacc.c  */
-#line 272 "parse-gram.y"
+/* Line 1538 of yacc.c  */
+#line 269 "parse-gram.y"
     { pure_parser = true; }
     break;
 
   case 29:
 
-/* Line 1535 of yacc.c  */
-#line 273 "parse-gram.y"
-    { push_parser = true; pull_parser = false; }
-    break;
-
-  case 30:
-
-/* Line 1535 of yacc.c  */
-#line 274 "parse-gram.y"
-    { push_parser = true; pull_parser = true; }
-    break;
-
-  case 31:
-
-/* Line 1535 of yacc.c  */
-#line 275 "parse-gram.y"
+/* Line 1538 of yacc.c  */
+#line 270 "parse-gram.y"
     { version_check (&(yylsp[(2) - (2)]), (yyvsp[(2) - (2)].chars)); }
     break;
 
-  case 32:
+  case 30:
 
-/* Line 1535 of yacc.c  */
-#line 277 "parse-gram.y"
+/* Line 1538 of yacc.c  */
+#line 272 "parse-gram.y"
     {
       char const *skeleton_user = (yyvsp[(2) - (2)].chars);
       if (strchr (skeleton_user, '/'))
@@ -2116,40 +2087,40 @@ yyreduce:
     }
     break;
 
-  case 33:
+  case 31:
 
-/* Line 1535 of yacc.c  */
-#line 300 "parse-gram.y"
+/* Line 1538 of yacc.c  */
+#line 295 "parse-gram.y"
     { token_table_flag = true; }
     break;
 
-  case 34:
+  case 32:
 
-/* Line 1535 of yacc.c  */
-#line 301 "parse-gram.y"
+/* Line 1538 of yacc.c  */
+#line 296 "parse-gram.y"
     { report_flag = report_states; }
     break;
 
-  case 35:
+  case 33:
 
-/* Line 1535 of yacc.c  */
-#line 302 "parse-gram.y"
+/* Line 1538 of yacc.c  */
+#line 297 "parse-gram.y"
     { yacc_flag = true; }
     break;
 
-  case 39:
+  case 37:
 
-/* Line 1535 of yacc.c  */
-#line 310 "parse-gram.y"
+/* Line 1538 of yacc.c  */
+#line 305 "parse-gram.y"
     {
       grammar_start_symbol_set ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]));
     }
     break;
 
-  case 40:
+  case 38:
 
-/* Line 1535 of yacc.c  */
-#line 314 "parse-gram.y"
+/* Line 1538 of yacc.c  */
+#line 309 "parse-gram.y"
     {
       symbol_list *list;
       for (list = (yyvsp[(3) - (3)].list); list; list = list->next)
@@ -2158,10 +2129,10 @@ yyreduce:
     }
     break;
 
-  case 41:
+  case 39:
 
-/* Line 1535 of yacc.c  */
-#line 321 "parse-gram.y"
+/* Line 1538 of yacc.c  */
+#line 316 "parse-gram.y"
     {
       symbol_list *list;
       for (list = (yyvsp[(3) - (3)].list); list; list = list->next)
@@ -2170,28 +2141,28 @@ yyreduce:
     }
     break;
 
-  case 42:
+  case 40:
 
-/* Line 1535 of yacc.c  */
-#line 328 "parse-gram.y"
+/* Line 1538 of yacc.c  */
+#line 323 "parse-gram.y"
     {
       default_prec = true;
     }
     break;
 
-  case 43:
+  case 41:
 
-/* Line 1535 of yacc.c  */
-#line 332 "parse-gram.y"
+/* Line 1538 of yacc.c  */
+#line 327 "parse-gram.y"
     {
       default_prec = false;
     }
     break;
 
-  case 44:
+  case 42:
 
-/* Line 1535 of yacc.c  */
-#line 336 "parse-gram.y"
+/* Line 1538 of yacc.c  */
+#line 331 "parse-gram.y"
     {
       /* Do not invoke muscle_percent_code_grow here since it invokes
          muscle_user_name_list_grow.  */
@@ -2200,34 +2171,34 @@ yyreduce:
     }
     break;
 
-  case 45:
+  case 43:
 
-/* Line 1535 of yacc.c  */
-#line 343 "parse-gram.y"
+/* Line 1538 of yacc.c  */
+#line 338 "parse-gram.y"
     {
       muscle_percent_code_grow ((yyvsp[(2) - (3)].uniqstr), (yylsp[(2) - (3)]), (yyvsp[(3) - (3)].chars), (yylsp[(3) - (3)]));
       code_scanner_last_string_free ();
     }
     break;
 
-  case 46:
+  case 44:
 
-/* Line 1535 of yacc.c  */
-#line 357 "parse-gram.y"
+/* Line 1538 of yacc.c  */
+#line 352 "parse-gram.y"
     {}
     break;
 
-  case 47:
+  case 45:
 
-/* Line 1535 of yacc.c  */
-#line 358 "parse-gram.y"
+/* Line 1538 of yacc.c  */
+#line 353 "parse-gram.y"
     { muscle_code_grow ("union_name", (yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
-  case 48:
+  case 46:
 
-/* Line 1535 of yacc.c  */
-#line 363 "parse-gram.y"
+/* Line 1538 of yacc.c  */
+#line 358 "parse-gram.y"
     {
       union_seen = true;
       muscle_code_grow ("stype", (yyvsp[(3) - (3)].chars), (yylsp[(3) - (3)]));
@@ -2235,44 +2206,44 @@ yyreduce:
     }
     break;
 
-  case 49:
+  case 47:
 
-/* Line 1535 of yacc.c  */
-#line 374 "parse-gram.y"
+/* Line 1538 of yacc.c  */
+#line 369 "parse-gram.y"
     { current_class = nterm_sym; }
     break;
 
-  case 50:
+  case 48:
 
-/* Line 1535 of yacc.c  */
-#line 375 "parse-gram.y"
+/* Line 1538 of yacc.c  */
+#line 370 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
     break;
 
-  case 51:
+  case 49:
 
-/* Line 1535 of yacc.c  */
-#line 379 "parse-gram.y"
+/* Line 1538 of yacc.c  */
+#line 374 "parse-gram.y"
     { current_class = token_sym; }
     break;
 
-  case 52:
+  case 50:
 
-/* Line 1535 of yacc.c  */
-#line 380 "parse-gram.y"
+/* Line 1538 of yacc.c  */
+#line 375 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
     break;
 
-  case 53:
+  case 51:
 
-/* Line 1535 of yacc.c  */
-#line 385 "parse-gram.y"
+/* Line 1538 of yacc.c  */
+#line 380 "parse-gram.y"
     {
       symbol_list *list;
       tag_seen = true;
@@ -2282,10 +2253,10 @@ yyreduce:
     }
     break;
 
-  case 54:
+  case 52:
 
-/* Line 1535 of yacc.c  */
-#line 396 "parse-gram.y"
+/* Line 1538 of yacc.c  */
+#line 391 "parse-gram.y"
     {
       symbol_list *list;
       ++current_prec;
@@ -2299,121 +2270,121 @@ yyreduce:
     }
     break;
 
-  case 55:
+  case 53:
 
-/* Line 1535 of yacc.c  */
-#line 410 "parse-gram.y"
+/* Line 1538 of yacc.c  */
+#line 405 "parse-gram.y"
     { (yyval.assoc) = left_assoc; }
     break;
 
-  case 56:
+  case 54:
 
-/* Line 1535 of yacc.c  */
-#line 411 "parse-gram.y"
+/* Line 1538 of yacc.c  */
+#line 406 "parse-gram.y"
     { (yyval.assoc) = right_assoc; }
     break;
 
-  case 57:
+  case 55:
 
-/* Line 1535 of yacc.c  */
-#line 412 "parse-gram.y"
+/* Line 1538 of yacc.c  */
+#line 407 "parse-gram.y"
     { (yyval.assoc) = non_assoc; }
     break;
 
-  case 58:
+  case 56:
 
-/* Line 1535 of yacc.c  */
-#line 416 "parse-gram.y"
+/* Line 1538 of yacc.c  */
+#line 411 "parse-gram.y"
     { current_type = NULL; }
     break;
 
-  case 59:
+  case 57:
 
-/* Line 1535 of yacc.c  */
-#line 417 "parse-gram.y"
+/* Line 1538 of yacc.c  */
+#line 412 "parse-gram.y"
     { current_type = (yyvsp[(1) - (1)].uniqstr); tag_seen = true; }
     break;
 
-  case 60:
+  case 58:
 
-/* Line 1535 of yacc.c  */
-#line 423 "parse-gram.y"
+/* Line 1538 of yacc.c  */
+#line 418 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
-  case 61:
+  case 59:
 
-/* Line 1535 of yacc.c  */
-#line 425 "parse-gram.y"
+/* Line 1538 of yacc.c  */
+#line 420 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), symbol_list_sym_new ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]))); }
     break;
 
-  case 62:
+  case 60:
 
-/* Line 1535 of yacc.c  */
-#line 429 "parse-gram.y"
+/* Line 1538 of yacc.c  */
+#line 424 "parse-gram.y"
     { (yyval.list) = (yyvsp[(1) - (1)].list); }
     break;
 
-  case 63:
+  case 61:
 
-/* Line 1535 of yacc.c  */
-#line 430 "parse-gram.y"
+/* Line 1538 of yacc.c  */
+#line 425 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), (yyvsp[(2) - (2)].list)); }
     break;
 
-  case 64:
+  case 62:
 
-/* Line 1535 of yacc.c  */
-#line 434 "parse-gram.y"
+/* Line 1538 of yacc.c  */
+#line 429 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
-  case 65:
+  case 63:
 
-/* Line 1535 of yacc.c  */
-#line 435 "parse-gram.y"
+/* Line 1538 of yacc.c  */
+#line 430 "parse-gram.y"
     { (yyval.list) = symbol_list_type_new ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
-  case 66:
+  case 64:
 
-/* Line 1535 of yacc.c  */
-#line 436 "parse-gram.y"
+/* Line 1538 of yacc.c  */
+#line 431 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagged_new ((yylsp[(1) - (1)])); }
     break;
 
-  case 67:
+  case 65:
 
-/* Line 1535 of yacc.c  */
-#line 437 "parse-gram.y"
+/* Line 1538 of yacc.c  */
+#line 432 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagless_new ((yylsp[(1) - (1)])); }
     break;
 
-  case 68:
+  case 66:
 
-/* Line 1535 of yacc.c  */
-#line 443 "parse-gram.y"
+/* Line 1538 of yacc.c  */
+#line 438 "parse-gram.y"
     {
        current_type = (yyvsp[(1) - (1)].uniqstr);
        tag_seen = true;
      }
     break;
 
-  case 69:
+  case 67:
 
-/* Line 1535 of yacc.c  */
-#line 448 "parse-gram.y"
+/* Line 1538 of yacc.c  */
+#line 443 "parse-gram.y"
     {
        symbol_class_set ((yyvsp[(1) - (1)].symbol), current_class, (yylsp[(1) - (1)]), true);
        symbol_type_set ((yyvsp[(1) - (1)].symbol), current_type, (yylsp[(1) - (1)]));
      }
     break;
 
-  case 70:
+  case 68:
 
-/* Line 1535 of yacc.c  */
-#line 453 "parse-gram.y"
+/* Line 1538 of yacc.c  */
+#line 448 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
       symbol_type_set ((yyvsp[(1) - (2)].symbol), current_type, (yylsp[(1) - (2)]));
@@ -2421,10 +2392,10 @@ yyreduce:
     }
     break;
 
-  case 71:
+  case 69:
 
-/* Line 1535 of yacc.c  */
-#line 459 "parse-gram.y"
+/* Line 1538 of yacc.c  */
+#line 454 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
       symbol_type_set ((yyvsp[(1) - (2)].symbol), current_type, (yylsp[(1) - (2)]));
@@ -2432,10 +2403,10 @@ yyreduce:
     }
     break;
 
-  case 72:
+  case 70:
 
-/* Line 1535 of yacc.c  */
-#line 465 "parse-gram.y"
+/* Line 1538 of yacc.c  */
+#line 460 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (3)].symbol), current_class, (yylsp[(1) - (3)]), true);
       symbol_type_set ((yyvsp[(1) - (3)].symbol), current_type, (yylsp[(1) - (3)]));
@@ -2444,98 +2415,98 @@ yyreduce:
     }
     break;
 
-  case 79:
+  case 77:
 
-/* Line 1535 of yacc.c  */
-#line 495 "parse-gram.y"
+/* Line 1538 of yacc.c  */
+#line 490 "parse-gram.y"
     {
       yyerrok;
     }
     break;
 
-  case 80:
+  case 78:
 
-/* Line 1535 of yacc.c  */
-#line 501 "parse-gram.y"
+/* Line 1538 of yacc.c  */
+#line 496 "parse-gram.y"
     { current_lhs = (yyvsp[(1) - (1)].symbol); current_lhs_location = (yylsp[(1) - (1)]); }
     break;
 
-  case 82:
+  case 80:
 
-/* Line 1535 of yacc.c  */
-#line 505 "parse-gram.y"
+/* Line 1538 of yacc.c  */
+#line 500 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(1) - (1)])); }
     break;
 
-  case 83:
+  case 81:
 
-/* Line 1535 of yacc.c  */
-#line 506 "parse-gram.y"
+/* Line 1538 of yacc.c  */
+#line 501 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(3) - (3)])); }
     break;
 
-  case 85:
+  case 83:
 
-/* Line 1535 of yacc.c  */
-#line 512 "parse-gram.y"
+/* Line 1538 of yacc.c  */
+#line 507 "parse-gram.y"
     { grammar_current_rule_begin (current_lhs, current_lhs_location); }
     break;
 
-  case 86:
+  case 84:
 
-/* Line 1535 of yacc.c  */
-#line 514 "parse-gram.y"
+/* Line 1538 of yacc.c  */
+#line 509 "parse-gram.y"
     { grammar_current_rule_symbol_append ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)])); }
     break;
 
-  case 87:
+  case 85:
 
-/* Line 1535 of yacc.c  */
-#line 516 "parse-gram.y"
+/* Line 1538 of yacc.c  */
+#line 511 "parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
     break;
 
-  case 88:
+  case 86:
 
-/* Line 1535 of yacc.c  */
-#line 518 "parse-gram.y"
+/* Line 1538 of yacc.c  */
+#line 513 "parse-gram.y"
     { grammar_current_rule_prec_set ((yyvsp[(3) - (3)].symbol), (yylsp[(3) - (3)])); }
     break;
 
-  case 89:
+  case 87:
 
-/* Line 1535 of yacc.c  */
-#line 520 "parse-gram.y"
+/* Line 1538 of yacc.c  */
+#line 515 "parse-gram.y"
     { grammar_current_rule_dprec_set ((yyvsp[(3) - (3)].integer), (yylsp[(3) - (3)])); }
     break;
 
-  case 90:
+  case 88:
 
-/* Line 1535 of yacc.c  */
-#line 522 "parse-gram.y"
+/* Line 1538 of yacc.c  */
+#line 517 "parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[(3) - (3)].uniqstr), (yylsp[(3) - (3)])); }
     break;
 
-  case 92:
+  case 90:
 
-/* Line 1535 of yacc.c  */
-#line 532 "parse-gram.y"
+/* Line 1538 of yacc.c  */
+#line 527 "parse-gram.y"
     { (yyval.uniqstr) = uniqstr_new ((yyvsp[(1) - (1)].chars)); }
     break;
 
-  case 93:
+  case 91:
 
-/* Line 1535 of yacc.c  */
-#line 538 "parse-gram.y"
+/* Line 1538 of yacc.c  */
+#line 533 "parse-gram.y"
     {
       (yyval.chars) = "";
     }
     break;
 
-  case 95:
+  case 93:
 
-/* Line 1535 of yacc.c  */
-#line 551 "parse-gram.y"
+/* Line 1538 of yacc.c  */
+#line 546 "parse-gram.y"
     {
       code_props plain_code;
       (yyvsp[(1) - (1)].code)[strlen ((yyvsp[(1) - (1)].code)) - 1] = '\n';
@@ -2546,17 +2517,17 @@ yyreduce:
     }
     break;
 
-  case 96:
+  case 94:
 
-/* Line 1535 of yacc.c  */
-#line 571 "parse-gram.y"
+/* Line 1538 of yacc.c  */
+#line 566 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
-  case 97:
+  case 95:
 
-/* Line 1535 of yacc.c  */
-#line 573 "parse-gram.y"
+/* Line 1538 of yacc.c  */
+#line 568 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[(1) - (1)].character)), (yylsp[(1) - (1)]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[(1) - (1)]), false);
@@ -2564,27 +2535,27 @@ yyreduce:
     }
     break;
 
-  case 98:
+  case 96:
 
-/* Line 1535 of yacc.c  */
-#line 581 "parse-gram.y"
+/* Line 1538 of yacc.c  */
+#line 576 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
-  case 101:
+  case 99:
 
-/* Line 1535 of yacc.c  */
-#line 593 "parse-gram.y"
+/* Line 1538 of yacc.c  */
+#line 588 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[(1) - (1)].chars)), (yylsp[(1) - (1)]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[(1) - (1)]), false);
     }
     break;
 
-  case 103:
+  case 101:
 
-/* Line 1535 of yacc.c  */
-#line 602 "parse-gram.y"
+/* Line 1538 of yacc.c  */
+#line 597 "parse-gram.y"
     {
       code_props plain_code;
       code_props_plain_init (&plain_code, (yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)]));
@@ -2597,8 +2568,8 @@ yyreduce:
 
 
 
-/* Line 1535 of yacc.c  */
-#line 2602 "parse-gram.c"
+/* Line 1538 of yacc.c  */
+#line 2573 "parse-gram.c"
       default: break;
     }
   YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);
@@ -2816,8 +2787,8 @@ yyreturn:
 
 
 
-/* Line 1535 of yacc.c  */
-#line 612 "parse-gram.y"
+/* Line 1538 of yacc.c  */
+#line 607 "parse-gram.y"
 
 
 
