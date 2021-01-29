@@ -188,55 +188,56 @@ static int current_prec = 0;
      PERCENT_TYPE = 262,
      PERCENT_DESTRUCTOR = 263,
      PERCENT_PRINTER = 264,
-     PERCENT_SYMBOL_DEFAULT = 265,
-     PERCENT_LEFT = 266,
-     PERCENT_RIGHT = 267,
-     PERCENT_NONASSOC = 268,
-     PERCENT_PREC = 269,
-     PERCENT_DPREC = 270,
-     PERCENT_MERGE = 271,
-     PERCENT_CODE = 272,
-     PERCENT_CODE_TOP = 273,
-     PERCENT_DEBUG = 274,
-     PERCENT_DEFAULT_PREC = 275,
-     PERCENT_DEFINE = 276,
-     PERCENT_DEFINES = 277,
-     PERCENT_ERROR_VERBOSE = 278,
-     PERCENT_EXPECT = 279,
-     PERCENT_EXPECT_RR = 280,
-     PERCENT_FILE_PREFIX = 281,
-     PERCENT_GLR_PARSER = 282,
-     PERCENT_INITIAL_ACTION = 283,
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
-     PERCENT_UNION = 313
+     PERCENT_LEFT = 265,
+     PERCENT_RIGHT = 266,
+     PERCENT_NONASSOC = 267,
+     PERCENT_PREC = 268,
+     PERCENT_DPREC = 269,
+     PERCENT_MERGE = 270,
+     PERCENT_CODE = 271,
+     PERCENT_CODE_TOP = 272,
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
+     PERCENT_LEX_PARAM = 283,
+     PERCENT_LOCATIONS = 284,
+     PERCENT_NAME_PREFIX = 285,
+     PERCENT_NO_DEFAULT_PREC = 286,
+     PERCENT_NO_LINES = 287,
+     PERCENT_NONDETERMINISTIC_PARSER = 288,
+     PERCENT_OUTPUT = 289,
+     PERCENT_PARSE_PARAM = 290,
+     PERCENT_PROVIDES = 291,
+     PERCENT_PURE_PARSER = 292,
+     PERCENT_PUSH_PARSER = 293,
+     PERCENT_REQUIRE = 294,
+     PERCENT_REQUIRES = 295,
+     PERCENT_SKELETON = 296,
+     PERCENT_START = 297,
+     PERCENT_TOKEN_TABLE = 298,
+     PERCENT_VERBOSE = 299,
+     PERCENT_YACC = 300,
+     BRACED_CODE = 301,
+     CHAR = 302,
+     EPILOGUE = 303,
+     EQUAL = 304,
+     ID = 305,
+     ID_COLON = 306,
+     PERCENT_PERCENT = 307,
+     PIPE = 308,
+     PROLOGUE = 309,
+     SEMICOLON = 310,
+     TYPE = 311,
+     TYPE_TAG_ANY = 312,
+     TYPE_TAG_NONE = 313,
+     PERCENT_UNION = 314
    };
 #endif
 /* Tokens.  */
@@ -248,55 +249,56 @@ static int current_prec = 0;
 #define PERCENT_TYPE 262
 #define PERCENT_DESTRUCTOR 263
 #define PERCENT_PRINTER 264
-#define PERCENT_SYMBOL_DEFAULT 265
-#define PERCENT_LEFT 266
-#define PERCENT_RIGHT 267
-#define PERCENT_NONASSOC 268
-#define PERCENT_PREC 269
-#define PERCENT_DPREC 270
-#define PERCENT_MERGE 271
-#define PERCENT_CODE 272
-#define PERCENT_CODE_TOP 273
-#define PERCENT_DEBUG 274
-#define PERCENT_DEFAULT_PREC 275
-#define PERCENT_DEFINE 276
-#define PERCENT_DEFINES 277
-#define PERCENT_ERROR_VERBOSE 278
-#define PERCENT_EXPECT 279
-#define PERCENT_EXPECT_RR 280
-#define PERCENT_FILE_PREFIX 281
-#define PERCENT_GLR_PARSER 282
-#define PERCENT_INITIAL_ACTION 283
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
-#define PERCENT_UNION 313
+#define PERCENT_LEFT 265
+#define PERCENT_RIGHT 266
+#define PERCENT_NONASSOC 267
+#define PERCENT_PREC 268
+#define PERCENT_DPREC 269
+#define PERCENT_MERGE 270
+#define PERCENT_CODE 271
+#define PERCENT_CODE_TOP 272
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
+#define PERCENT_LEX_PARAM 283
+#define PERCENT_LOCATIONS 284
+#define PERCENT_NAME_PREFIX 285
+#define PERCENT_NO_DEFAULT_PREC 286
+#define PERCENT_NO_LINES 287
+#define PERCENT_NONDETERMINISTIC_PARSER 288
+#define PERCENT_OUTPUT 289
+#define PERCENT_PARSE_PARAM 290
+#define PERCENT_PROVIDES 291
+#define PERCENT_PURE_PARSER 292
+#define PERCENT_PUSH_PARSER 293
+#define PERCENT_REQUIRE 294
+#define PERCENT_REQUIRES 295
+#define PERCENT_SKELETON 296
+#define PERCENT_START 297
+#define PERCENT_TOKEN_TABLE 298
+#define PERCENT_VERBOSE 299
+#define PERCENT_YACC 300
+#define BRACED_CODE 301
+#define CHAR 302
+#define EPILOGUE 303
+#define EQUAL 304
+#define ID 305
+#define ID_COLON 306
+#define PERCENT_PERCENT 307
+#define PIPE 308
+#define PROLOGUE 309
+#define SEMICOLON 310
+#define TYPE 311
+#define TYPE_TAG_ANY 312
+#define TYPE_TAG_NONE 313
+#define PERCENT_UNION 314
 
 
 
@@ -317,7 +319,7 @@ typedef union YYSTYPE
 }
 
 /* Line 198 of yacc.c  */
-#line 321 "parse-gram.c"
+#line 323 "parse-gram.c"
 	YYSTYPE;
 # define YYSTYPE_IS_TRIVIAL 1
 # define yystype YYSTYPE /* obsolescent; will be withdrawn */
@@ -342,7 +344,7 @@ typedef struct YYLTYPE
 
 
 /* Line 221 of yacc.c  */
-#line 346 "parse-gram.c"
+#line 348 "parse-gram.c"
 
 #ifdef short
 # undef short
@@ -559,20 +561,20 @@ union yyalloc
 /* YYFINAL -- State number of the termination state.  */
 #define YYFINAL  3
 /* YYLAST -- Last index in YYTABLE.  */
-#define YYLAST   187
+#define YYLAST   205
 
 /* YYNTOKENS -- Number of terminals.  */
-#define YYNTOKENS  59
+#define YYNTOKENS  60
 /* YYNNTS -- Number of nonterminals.  */
 #define YYNNTS  31
 /* YYNRULES -- Number of rules.  */
-#define YYNRULES  98
+#define YYNRULES  99
 /* YYNRULES -- Number of states.  */
-#define YYNSTATES  137
+#define YYNSTATES  138
 
 /* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
 #define YYUNDEFTOK  2
-#define YYMAXUTOK   313
+#define YYMAXUTOK   314
 
 #define YYTRANSLATE(YYX)						\
   ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)
@@ -611,7 +613,7 @@ static const yytype_uint8 yytranslate[] =
       25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
       35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
       45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
-      55,    56,    57,    58
+      55,    56,    57,    58,    59
 };
 
 #if YYDEBUG
@@ -625,40 +627,41 @@ static const yytype_uint8 yyprhs[] =
       77,    79,    81,    83,    86,    90,    94,    96,    98,   101,
      104,   107,   110,   111,   113,   117,   118,   122,   123,   127,
      131,   135,   137,   139,   141,   142,   144,   146,   149,   151,
-     154,   156,   158,   160,   162,   164,   167,   170,   174,   176,
-     179,   181,   184,   186,   189,   192,   193,   197,   199,   203,
-     206,   207,   210,   213,   217,   221,   225,   227,   229,   230,
-     232,   234,   236,   238,   240,   242,   244,   246,   247
+     154,   156,   158,   160,   162,   164,   166,   169,   172,   176,
+     178,   181,   183,   186,   188,   191,   194,   195,   199,   201,
+     205,   208,   209,   212,   215,   219,   223,   227,   229,   231,
+     232,   234,   236,   238,   240,   242,   244,   246,   248,   249
 };
 
 /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
 static const yytype_int8 yyrhs[] =
 {
-      60,     0,    -1,    61,    53,    76,    89,    -1,    -1,    61,
-      62,    -1,    63,    -1,    55,    -1,    19,    -1,    21,     3,
-      83,    -1,    22,    -1,    23,    -1,    24,     4,    -1,    25,
-       4,    -1,    26,    50,     3,    -1,    27,    -1,    28,    47,
-      -1,    29,    47,    -1,    30,    -1,    31,    50,     3,    -1,
-      33,    -1,    34,    -1,    35,    50,     3,    -1,    36,    47,
-      -1,    38,    -1,    39,    -1,    40,     3,    -1,    42,     3,
-      -1,    44,    -1,    45,    -1,    46,    -1,    56,    -1,    68,
-      -1,    65,    -1,    43,    87,    -1,     8,    47,    72,    -1,
-       9,    47,    72,    -1,    20,    -1,    32,    -1,    17,    84,
-      -1,    18,    84,    -1,    37,    84,    -1,    41,    84,    -1,
-      -1,    51,    -1,    58,    64,    47,    -1,    -1,     6,    66,
-      75,    -1,    -1,     5,    67,    75,    -1,     7,    57,    71,
-      -1,    69,    70,    71,    -1,    11,    -1,    12,    -1,    13,
-      -1,    -1,    57,    -1,    87,    -1,    71,    87,    -1,    73,
-      -1,    72,    73,    -1,    87,    -1,    57,    -1,    10,    -1,
-      57,    -1,    85,    -1,    85,     4,    -1,    85,    88,    -1,
-      85,     4,    88,    -1,    74,    -1,    75,    74,    -1,    77,
-      -1,    76,    77,    -1,    78,    -1,    63,    56,    -1,     1,
-      56,    -1,    -1,    86,    79,    80,    -1,    81,    -1,    80,
-      54,    81,    -1,    80,    56,    -1,    -1,    81,    87,    -1,
-      81,    47,    -1,    81,    14,    87,    -1,    81,    15,     4,
-      -1,    81,    16,    57,    -1,     3,    -1,    84,    -1,    -1,
-      82,    -1,    47,    -1,    51,    -1,    48,    -1,    52,    -1,
-      85,    -1,    88,    -1,     3,    -1,    -1,    53,    49,    -1
+      61,     0,    -1,    62,    52,    77,    90,    -1,    -1,    62,
+      63,    -1,    64,    -1,    54,    -1,    18,    -1,    20,     3,
+      84,    -1,    21,    -1,    22,    -1,    23,     4,    -1,    24,
+       4,    -1,    25,    49,     3,    -1,    26,    -1,    27,    46,
+      -1,    28,    46,    -1,    29,    -1,    30,    49,     3,    -1,
+      32,    -1,    33,    -1,    34,    49,     3,    -1,    35,    46,
+      -1,    37,    -1,    38,    -1,    39,     3,    -1,    41,     3,
+      -1,    43,    -1,    44,    -1,    45,    -1,    55,    -1,    69,
+      -1,    66,    -1,    42,    88,    -1,     8,    46,    73,    -1,
+       9,    46,    73,    -1,    19,    -1,    31,    -1,    16,    85,
+      -1,    17,    85,    -1,    36,    85,    -1,    40,    85,    -1,
+      -1,    50,    -1,    59,    65,    46,    -1,    -1,     6,    67,
+      76,    -1,    -1,     5,    68,    76,    -1,     7,    56,    72,
+      -1,    70,    71,    72,    -1,    10,    -1,    11,    -1,    12,
+      -1,    -1,    56,    -1,    88,    -1,    72,    88,    -1,    74,
+      -1,    73,    74,    -1,    88,    -1,    56,    -1,    57,    -1,
+      58,    -1,    56,    -1,    86,    -1,    86,     4,    -1,    86,
+      89,    -1,    86,     4,    89,    -1,    75,    -1,    76,    75,
+      -1,    78,    -1,    77,    78,    -1,    79,    -1,    64,    55,
+      -1,     1,    55,    -1,    -1,    87,    80,    81,    -1,    82,
+      -1,    81,    53,    82,    -1,    81,    55,    -1,    -1,    82,
+      88,    -1,    82,    46,    -1,    82,    13,    88,    -1,    82,
+      14,     4,    -1,    82,    15,    56,    -1,     3,    -1,    85,
+      -1,    -1,    83,    -1,    46,    -1,    50,    -1,    47,    -1,
+      51,    -1,    86,    -1,    89,    -1,     3,    -1,    -1,    52,
+      48,    -1
 };
 
 /* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
@@ -670,10 +673,10 @@ static const yytype_uint16 yyrline[] =
      255,   259,   260,   261,   265,   273,   281,   285,   289,   290,
      291,   292,   303,   304,   308,   336,   336,   341,   341,   346,
      357,   372,   373,   374,   378,   379,   384,   386,   391,   392,
-     396,   397,   398,   403,   408,   413,   419,   425,   436,   437,
-     446,   447,   453,   454,   455,   462,   462,   466,   467,   468,
-     473,   474,   476,   478,   480,   482,   492,   493,   499,   503,
-     508,   524,   526,   535,   540,   541,   546,   553,   555
+     396,   397,   398,   399,   404,   409,   414,   420,   426,   437,
+     438,   447,   448,   454,   455,   456,   463,   463,   467,   468,
+     469,   474,   475,   477,   479,   481,   483,   493,   494,   500,
+     504,   509,   525,   527,   536,   541,   542,   547,   554,   556
 };
 #endif
 
@@ -684,26 +687,25 @@ static const char *const yytname[] =
 {
   "\"end of file\"", "error", "$undefined", "\"string\"", "\"integer\"",
   "\"%token\"", "\"%nterm\"", "\"%type\"", "\"%destructor\"",
-  "\"%printer\"", "\"%symbol-default\"", "\"%left\"", "\"%right\"",
-  "\"%nonassoc\"", "\"%prec\"", "\"%dprec\"", "\"%merge\"", "\"%code\"",
-  "\"%code-top\"", "\"%debug\"", "\"%default-prec\"", "\"%define\"",
-  "\"%defines\"", "\"%error-verbose\"", "\"%expect\"", "\"%expect-rr\"",
-  "\"%file-prefix\"", "\"%glr-parser\"", "\"%initial-action\"",
-  "\"%lex-param\"", "\"%locations\"", "\"%name-prefix\"",
-  "\"%no-default-prec\"", "\"%no-lines\"", "\"%nondeterministic-parser\"",
-  "\"%output\"", "\"%parse-param\"", "\"%provides\"", "\"%pure-parser\"",
-  "\"%push-parser\"", "\"%require\"", "\"%requires\"", "\"%skeleton\"",
-  "\"%start\"", "\"%token-table\"", "\"%verbose\"", "\"%yacc\"",
-  "\"{...}\"", "\"char\"", "\"epilogue\"", "\"=\"", "\"identifier\"",
-  "\"identifier:\"", "\"%%\"", "\"|\"", "\"%{...%}\"", "\";\"", "\"type\"",
-  "\"%union\"", "$accept", "input", "prologue_declarations",
-  "prologue_declaration", "grammar_declaration", "union_name",
-  "symbol_declaration", "@1", "@2", "precedence_declaration",
-  "precedence_declarator", "type.opt", "symbols.1", "generic_symlist",
-  "generic_symlist_item", "symbol_def", "symbol_defs.1", "grammar",
-  "rules_or_grammar_declaration", "rules", "@3", "rhses.1", "rhs",
-  "content", "content.opt", "braceless", "id", "id_colon", "symbol",
-  "string_as_id", "epilogue.opt", 0
+  "\"%printer\"", "\"%left\"", "\"%right\"", "\"%nonassoc\"", "\"%prec\"",
+  "\"%dprec\"", "\"%merge\"", "\"%code\"", "\"%code-top\"", "\"%debug\"",
+  "\"%default-prec\"", "\"%define\"", "\"%defines\"", "\"%error-verbose\"",
+  "\"%expect\"", "\"%expect-rr\"", "\"%file-prefix\"", "\"%glr-parser\"",
+  "\"%initial-action\"", "\"%lex-param\"", "\"%locations\"",
+  "\"%name-prefix\"", "\"%no-default-prec\"", "\"%no-lines\"",
+  "\"%nondeterministic-parser\"", "\"%output\"", "\"%parse-param\"",
+  "\"%provides\"", "\"%pure-parser\"", "\"%push-parser\"", "\"%require\"",
+  "\"%requires\"", "\"%skeleton\"", "\"%start\"", "\"%token-table\"",
+  "\"%verbose\"", "\"%yacc\"", "\"{...}\"", "\"char\"", "\"epilogue\"",
+  "\"=\"", "\"identifier\"", "\"identifier:\"", "\"%%\"", "\"|\"",
+  "\"%{...%}\"", "\";\"", "\"type\"", "\"<*>\"", "\"<!>\"", "\"%union\"",
+  "$accept", "input", "prologue_declarations", "prologue_declaration",
+  "grammar_declaration", "union_name", "symbol_declaration", "$@1", "$@2",
+  "precedence_declaration", "precedence_declarator", "type.opt",
+  "symbols.1", "generic_symlist", "generic_symlist_item", "symbol_def",
+  "symbol_defs.1", "grammar", "rules_or_grammar_declaration", "rules",
+  "$@3", "rhses.1", "rhs", "content", "content.opt", "braceless", "id",
+  "id_colon", "symbol", "string_as_id", "epilogue.opt", 0
 };
 #endif
 
@@ -717,23 +719,23 @@ static const yytype_uint16 yytoknum[] =
      275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
      285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
      295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
-     305,   306,   307,   308,   309,   310,   311,   312,   313
+     305,   306,   307,   308,   309,   310,   311,   312,   313,   314
 };
 # endif
 
 /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
 static const yytype_uint8 yyr1[] =
 {
-       0,    59,    60,    61,    61,    62,    62,    62,    62,    62,
-      62,    62,    62,    62,    62,    62,    62,    62,    62,    62,
-      62,    62,    62,    62,    62,    62,    62,    62,    62,    62,
-      62,    63,    63,    63,    63,    63,    63,    63,    63,    63,
-      63,    63,    64,    64,    63,    66,    65,    67,    65,    65,
-      68,    69,    69,    69,    70,    70,    71,    71,    72,    72,
-      73,    73,    73,    74,    74,    74,    74,    74,    75,    75,
-      76,    76,    77,    77,    77,    79,    78,    80,    80,    80,
-      81,    81,    81,    81,    81,    81,    82,    82,    83,    83,
-      84,    85,    85,    86,    87,    87,    88,    89,    89
+       0,    60,    61,    62,    62,    63,    63,    63,    63,    63,
+      63,    63,    63,    63,    63,    63,    63,    63,    63,    63,
+      63,    63,    63,    63,    63,    63,    63,    63,    63,    63,
+      63,    64,    64,    64,    64,    64,    64,    64,    64,    64,
+      64,    64,    65,    65,    64,    67,    66,    68,    66,    66,
+      69,    70,    70,    70,    71,    71,    72,    72,    73,    73,
+      74,    74,    74,    74,    75,    75,    75,    75,    75,    76,
+      76,    77,    77,    78,    78,    78,    80,    79,    81,    81,
+      81,    82,    82,    82,    82,    82,    82,    83,    83,    84,
+      84,    85,    86,    86,    87,    88,    88,    89,    90,    90
 };
 
 /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
@@ -745,10 +747,10 @@ static const yytype_uint8 yyr2[] =
        1,     1,     1,     2,     3,     3,     1,     1,     2,     2,
        2,     2,     0,     1,     3,     0,     3,     0,     3,     3,
        3,     1,     1,     1,     0,     1,     1,     2,     1,     2,
-       1,     1,     1,     1,     1,     2,     2,     3,     1,     2,
-       1,     2,     1,     2,     2,     0,     3,     1,     3,     2,
-       0,     2,     2,     3,     3,     3,     1,     1,     0,     1,
-       1,     1,     1,     1,     1,     1,     1,     0,     2
+       1,     1,     1,     1,     1,     1,     2,     2,     3,     1,
+       2,     1,     2,     1,     2,     2,     0,     3,     1,     3,
+       2,     0,     2,     2,     3,     3,     3,     1,     1,     0,
+       1,     1,     1,     1,     1,     1,     1,     1,     0,     2
 };
 
 /* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
@@ -761,125 +763,129 @@ static const yytype_uint8 yydefact[] =
        0,     0,    14,     0,     0,    17,     0,    37,    19,    20,
        0,     0,     0,    23,    24,     0,     0,     0,     0,    27,
       28,    29,     0,     6,    30,    42,     4,     5,    32,    31,
-      54,     0,     0,     0,     0,     0,    90,    38,    39,    88,
+      54,     0,     0,     0,     0,     0,    91,    38,    39,    89,
       11,    12,     0,    15,    16,     0,     0,    22,    40,    25,
-      41,    26,    96,    92,    91,    94,    33,    95,     0,    93,
-       0,     0,    70,    72,    75,    43,     0,    55,     0,    63,
-      68,    48,    64,    46,    49,    56,    62,    61,    34,    58,
-      60,    35,    86,    89,     8,    87,    13,    18,    21,    74,
-      73,     0,    71,     2,    80,    44,    50,    69,    65,    66,
-      57,    59,    98,    76,    77,    67,    80,    79,     0,     0,
-       0,    82,    81,    78,    83,    84,    85
+      41,    26,    97,    93,    92,    95,    33,    96,     0,    94,
+       0,     0,    71,    73,    76,    43,     0,    55,     0,    64,
+      69,    48,    65,    46,    49,    56,    61,    62,    63,    34,
+      58,    60,    35,    87,    90,     8,    88,    13,    18,    21,
+      75,    74,     0,    72,     2,    81,    44,    50,    70,    66,
+      67,    57,    59,    99,    77,    78,    68,    81,    80,     0,
+       0,     0,    83,    82,    79,    84,    85,    86
 };
 
 /* YYDEFGOTO[NTERM-NUM].  */
 static const yytype_int8 yydefgoto[] =
 {
       -1,     1,     2,    46,    80,    86,    48,    52,    51,    49,
-      50,    88,    94,    98,    99,    90,    91,    81,    82,    83,
-     114,   123,   124,   103,   104,    57,    75,    84,   100,    77,
-     113
+      50,    88,    94,    99,   100,    90,    91,    81,    82,    83,
+     115,   124,   125,   104,   105,    57,    75,    84,   101,    77,
+     114
 };
 
 /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
    STATE-NUM.  */
-#define YYPACT_NINF -82
+#define YYPACT_NINF -89
 static const yytype_int16 yypact[] =
 {
-     -82,     4,    91,   -82,   -82,   -82,   -52,   -31,   -24,   -82,
-     -82,   -82,    -8,    -8,   -82,   -82,    49,   -82,   -82,    53,
-      54,    12,   -82,    16,    26,   -82,    30,   -82,   -82,   -82,
-      32,    36,    -8,   -82,   -82,    81,    -8,    82,     0,   -82,
-     -82,   -82,    23,   -82,   -82,    37,   -82,   -82,   -82,   -82,
-      34,    19,    19,     0,    17,    17,   -82,   -82,   -82,    14,
-     -82,   -82,    84,   -82,   -82,    86,    90,   -82,   -82,   -82,
-     -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,    38,   -82,
-      45,     1,   -82,   -82,   -82,   -82,    58,   -82,     0,   -82,
-     -82,    19,    43,    19,     0,   -82,   -82,   -82,    17,   -82,
-     -82,    17,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,
-     -82,    57,   -82,   -82,   -82,   -82,     0,   -82,   104,   -82,
-     -82,   -82,   -82,    15,   136,   -82,   -82,   -82,     0,    88,
-      85,   -82,   -82,   136,   -82,   -82,   -82
+     -89,    14,   112,   -89,   -89,   -89,   -33,   -16,   -11,   -89,
+     -89,   -89,    -6,    -6,   -89,   -89,    39,   -89,   -89,    42,
+      43,     5,   -89,     9,    11,   -89,    10,   -89,   -89,   -89,
+      12,    24,    -6,   -89,   -89,    48,    -6,    68,    30,   -89,
+     -89,   -89,    57,   -89,   -89,    28,   -89,   -89,   -89,   -89,
+      29,   -31,   -31,    30,    25,    25,   -89,   -89,   -89,     2,
+     -89,   -89,    86,   -89,   -89,    87,    89,   -89,   -89,   -89,
+     -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,    40,   -89,
+      45,     1,   -89,   -89,   -89,   -89,    52,   -89,    30,   -89,
+     -89,   -31,    35,   -31,    30,   -89,   -89,   -89,   -89,    25,
+     -89,   -89,    25,   -89,   -89,   -89,   -89,   -89,   -89,   -89,
+     -89,   -89,    46,   -89,   -89,   -89,   -89,    30,   -89,    98,
+     -89,   -89,   -89,   -89,   -26,   155,   -89,   -89,   -89,    30,
+      99,    49,   -89,   -89,   155,   -89,   -89,   -89
 };
 
 /* YYPGOTO[NTERM-NUM].  */
-static const yytype_int16 yypgoto[] =
+static const yytype_int8 yypgoto[] =
 {
-     -82,   -82,   -82,   -82,   141,   -82,   -82,   -82,   -82,   -82,
-     -82,   -82,    50,    93,   -76,   -14,   101,   -82,    64,   -82,
-     -82,   -82,    28,   -82,   -82,    13,    89,   -82,   -38,   -81,
-     -82
+     -89,   -89,   -89,   -89,   100,   -89,   -89,   -89,   -89,   -89,
+     -89,   -89,    16,    51,   -78,   -57,    55,   -89,    31,   -89,
+     -89,   -89,   -18,   -89,   -89,   -10,    -7,   -89,   -38,   -88,
+     -89
 };
 
 /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
    positive, shift that token.  If negative, reduce the rule which
    number is the opposite.  If zero, do what YYDEFACT says.
    If YYTABLE_NINF, syntax error.  */
-#define YYTABLE_NINF -98
+#define YYTABLE_NINF -99
 static const yytype_int16 yytable[] =
 {
-      76,   -97,    78,    72,     3,    53,     4,     5,     6,     7,
-       8,   119,     9,    10,    11,    95,    54,   102,    12,    13,
-      72,    15,   121,    55,    78,   121,    58,    96,     4,     5,
-       6,     7,     8,    27,     9,    10,    11,   125,    32,    56,
-      12,    13,    36,    15,    38,    68,    72,   118,    73,    70,
-      95,    74,    59,    79,   111,    27,   120,    60,    61,    45,
-      32,    56,    62,    63,    36,    73,    38,    73,    74,   126,
-      74,   127,   105,    64,    97,    79,    89,   117,   120,   117,
-      65,    45,    66,    67,    69,    71,   132,   106,    85,   107,
-     134,    87,   135,   108,   109,   132,     4,     5,     6,     7,
-       8,   110,     9,    10,    11,   115,   122,    72,    12,    13,
+      76,   -98,    78,    58,   120,   103,     4,     5,     6,     7,
+       8,     9,    10,    11,     3,    95,    73,    12,    13,    74,
+      15,   122,    68,    53,   122,    89,    70,   127,    72,   128,
+      54,   126,    27,    72,   118,    55,   118,    32,    72,   119,
+      56,    36,    59,    38,    92,    92,    60,    61,    56,   106,
+      95,    69,    79,   112,    62,    63,   121,    64,    78,    65,
+      45,    66,     4,     5,     6,     7,     8,     9,    10,    11,
+      67,    71,    73,    12,    13,    74,    15,    73,    85,   121,
+      74,    96,    97,    98,    92,    87,    92,   133,    27,   107,
+     108,   135,   109,    32,   123,   110,   133,    36,   116,    38,
+     111,    72,    47,   136,   117,   137,   102,    93,    79,   134,
+       0,     0,   113,     0,     0,     0,    45,     4,     5,     6,
+       7,     8,     9,    10,    11,     0,     0,     0,    12,    13,
       14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
       24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
-      34,    35,    36,    37,    38,    39,    40,    41,   116,    72,
-      92,    92,   136,    47,    42,   112,    43,    44,   101,    45,
-     128,   129,   130,    93,   133,     0,     0,     0,     0,     0,
+      34,    35,    36,    37,    38,    39,    40,    41,    72,     0,
+       0,     0,     0,     0,    42,     0,    43,    44,   129,   130,
+     131,    45,     0,     0,     0,     0,     0,     0,     0,     0,
        0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
        0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
-      92,     0,    92,   131,    73,     0,     0,    74
+       0,   132,    73,     0,     0,    74
 };
 
 static const yytype_int16 yycheck[] =
 {
-      38,     0,     1,     3,     0,    57,     5,     6,     7,     8,
-       9,    92,    11,    12,    13,    53,    47,     3,    17,    18,
-       3,    20,    98,    47,     1,   101,    13,    10,     5,     6,
-       7,     8,     9,    32,    11,    12,    13,   118,    37,    47,
-      17,    18,    41,    20,    43,    32,     3,     4,    48,    36,
-      88,    51,     3,    52,    53,    32,    94,     4,     4,    58,
-      37,    47,    50,    47,    41,    48,    43,    48,    51,    54,
-      51,    56,    59,    47,    57,    52,    57,    91,   116,    93,
-      50,    58,    50,    47,     3,     3,   124,     3,    51,     3,
-     128,    57,     4,     3,    56,   133,     5,     6,     7,     8,
-       9,    56,    11,    12,    13,    47,    49,     3,    17,    18,
-      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
-      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
-      39,    40,    41,    42,    43,    44,    45,    46,    88,     3,
-      51,    52,    57,     2,    53,    81,    55,    56,    55,    58,
-      14,    15,    16,    52,   126,    -1,    -1,    -1,    -1,    -1,
+      38,     0,     1,    13,    92,     3,     5,     6,     7,     8,
+       9,    10,    11,    12,     0,    53,    47,    16,    17,    50,
+      19,    99,    32,    56,   102,    56,    36,    53,     3,    55,
+      46,   119,    31,     3,    91,    46,    93,    36,     3,     4,
+      46,    40,     3,    42,    51,    52,     4,     4,    46,    59,
+      88,     3,    51,    52,    49,    46,    94,    46,     1,    49,
+      59,    49,     5,     6,     7,     8,     9,    10,    11,    12,
+      46,     3,    47,    16,    17,    50,    19,    47,    50,   117,
+      50,    56,    57,    58,    91,    56,    93,   125,    31,     3,
+       3,   129,     3,    36,    48,    55,   134,    40,    46,    42,
+      55,     3,     2,     4,    88,    56,    55,    52,    51,   127,
+      -1,    -1,    81,    -1,    -1,    -1,    59,     5,     6,     7,
+       8,     9,    10,    11,    12,    -1,    -1,    -1,    16,    17,
+      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
+      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
+      38,    39,    40,    41,    42,    43,    44,    45,     3,    -1,
+      -1,    -1,    -1,    -1,    52,    -1,    54,    55,    13,    14,
+      15,    59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
-      91,    -1,    93,    47,    48,    -1,    -1,    51
+      -1,    46,    47,    -1,    -1,    50
 };
 
 /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
    symbol of state STATE-NUM.  */
 static const yytype_uint8 yystos[] =
 {
-       0,    60,    61,     0,     5,     6,     7,     8,     9,    11,
-      12,    13,    17,    18,    19,    20,    21,    22,    23,    24,
-      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
-      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
-      45,    46,    53,    55,    56,    58,    62,    63,    65,    68,
-      69,    67,    66,    57,    47,    47,    47,    84,    84,     3,
-       4,     4,    50,    47,    47,    50,    50,    47,    84,     3,
-      84,     3,     3,    48,    51,    85,    87,    88,     1,    52,
-      63,    76,    77,    78,    86,    51,    64,    57,    70,    57,
-      74,    75,    85,    75,    71,    87,    10,    57,    72,    73,
-      87,    72,     3,    82,    83,    84,     3,     3,     3,    56,
-      56,    53,    77,    89,    79,    47,    71,    74,     4,    88,
-      87,    73,    49,    80,    81,    88,    54,    56,    14,    15,
-      16,    47,    87,    81,    87,     4,    57
+       0,    61,    62,     0,     5,     6,     7,     8,     9,    10,
+      11,    12,    16,    17,    18,    19,    20,    21,    22,    23,
+      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
+      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
+      44,    45,    52,    54,    55,    59,    63,    64,    66,    69,
+      70,    68,    67,    56,    46,    46,    46,    85,    85,     3,
+       4,     4,    49,    46,    46,    49,    49,    46,    85,     3,
+      85,     3,     3,    47,    50,    86,    88,    89,     1,    51,
+      64,    77,    78,    79,    87,    50,    65,    56,    71,    56,
+      75,    76,    86,    76,    72,    88,    56,    57,    58,    73,
+      74,    88,    73,     3,    83,    84,    85,     3,     3,     3,
+      55,    55,    52,    78,    90,    80,    46,    72,    75,     4,
+      89,    88,    74,    48,    81,    82,    89,    53,    55,    13,
+      14,    15,    46,    88,    82,    88,     4,    56
 };
 
 #define yyerrok		(yyerrstatus = 0)
@@ -1034,7 +1040,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 	{ fputs (quotearg_style (c_quoting_style, (yyvaluep->chars)), stderr); };
 
 /* Line 670 of yacc.c  */
-#line 1038 "parse-gram.c"
+#line 1044 "parse-gram.c"
 	break;
       case 4: /* "\"integer\"" */
 
@@ -1043,133 +1049,133 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 	{ fprintf (stderr, "%d", (yyvaluep->integer)); };
 
 /* Line 670 of yacc.c  */
-#line 1047 "parse-gram.c"
+#line 1053 "parse-gram.c"
 	break;
-      case 47: /* "\"{...}\"" */
+      case 46: /* "\"{...}\"" */
 
 /* Line 670 of yacc.c  */
 #line 189 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
 /* Line 670 of yacc.c  */
-#line 1056 "parse-gram.c"
+#line 1062 "parse-gram.c"
 	break;
-      case 48: /* "\"char\"" */
+      case 47: /* "\"char\"" */
 
 /* Line 670 of yacc.c  */
 #line 182 "parse-gram.y"
 	{ fputs (char_name ((yyvaluep->character)), stderr); };
 
 /* Line 670 of yacc.c  */
-#line 1065 "parse-gram.c"
+#line 1071 "parse-gram.c"
 	break;
-      case 49: /* "\"epilogue\"" */
+      case 48: /* "\"epilogue\"" */
 
 /* Line 670 of yacc.c  */
 #line 189 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
 /* Line 670 of yacc.c  */
-#line 1074 "parse-gram.c"
+#line 1080 "parse-gram.c"
 	break;
-      case 51: /* "\"identifier\"" */
+      case 50: /* "\"identifier\"" */
 
 /* Line 670 of yacc.c  */
 #line 194 "parse-gram.y"
 	{ fputs ((yyvaluep->uniqstr), stderr); };
 
 /* Line 670 of yacc.c  */
-#line 1083 "parse-gram.c"
+#line 1089 "parse-gram.c"
 	break;
-      case 52: /* "\"identifier:\"" */
+      case 51: /* "\"identifier:\"" */
 
 /* Line 670 of yacc.c  */
 #line 195 "parse-gram.y"
 	{ fprintf (stderr, "%s:", (yyvaluep->uniqstr)); };
 
 /* Line 670 of yacc.c  */
-#line 1092 "parse-gram.c"
+#line 1098 "parse-gram.c"
 	break;
-      case 55: /* "\"%{...%}\"" */
+      case 54: /* "\"%{...%}\"" */
 
 /* Line 670 of yacc.c  */
 #line 189 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
 /* Line 670 of yacc.c  */
-#line 1101 "parse-gram.c"
+#line 1107 "parse-gram.c"
 	break;
-      case 57: /* "\"type\"" */
+      case 56: /* "\"type\"" */
 
 /* Line 670 of yacc.c  */
 #line 193 "parse-gram.y"
 	{ fprintf (stderr, "<%s>", (yyvaluep->uniqstr)); };
 
 /* Line 670 of yacc.c  */
-#line 1110 "parse-gram.c"
+#line 1116 "parse-gram.c"
 	break;
-      case 82: /* "content" */
+      case 83: /* "content" */
 
 /* Line 670 of yacc.c  */
 #line 189 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
 /* Line 670 of yacc.c  */
-#line 1119 "parse-gram.c"
+#line 1125 "parse-gram.c"
 	break;
-      case 83: /* "content.opt" */
+      case 84: /* "content.opt" */
 
 /* Line 670 of yacc.c  */
 #line 189 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
 /* Line 670 of yacc.c  */
-#line 1128 "parse-gram.c"
+#line 1134 "parse-gram.c"
 	break;
-      case 84: /* "braceless" */
+      case 85: /* "braceless" */
 
 /* Line 670 of yacc.c  */
 #line 189 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
 /* Line 670 of yacc.c  */
-#line 1137 "parse-gram.c"
+#line 1143 "parse-gram.c"
 	break;
-      case 85: /* "id" */
+      case 86: /* "id" */
 
 /* Line 670 of yacc.c  */
 #line 201 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
 /* Line 670 of yacc.c  */
-#line 1146 "parse-gram.c"
+#line 1152 "parse-gram.c"
 	break;
-      case 86: /* "id_colon" */
+      case 87: /* "id_colon" */
 
 /* Line 670 of yacc.c  */
 #line 202 "parse-gram.y"
 	{ fprintf (stderr, "%s:", (yyvaluep->symbol)->tag); };
 
 /* Line 670 of yacc.c  */
-#line 1155 "parse-gram.c"
+#line 1161 "parse-gram.c"
 	break;
-      case 87: /* "symbol" */
+      case 88: /* "symbol" */
 
 /* Line 670 of yacc.c  */
 #line 201 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
 /* Line 670 of yacc.c  */
-#line 1164 "parse-gram.c"
+#line 1170 "parse-gram.c"
 	break;
-      case 88: /* "string_as_id" */
+      case 89: /* "string_as_id" */
 
 /* Line 670 of yacc.c  */
 #line 201 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
 /* Line 670 of yacc.c  */
-#line 1173 "parse-gram.c"
+#line 1179 "parse-gram.c"
 	break;
       default:
 	break;
@@ -1693,7 +1699,7 @@ YYLTYPE yylloc;
 }
 
 /* Line 1082 of yacc.c  */
-#line 1697 "parse-gram.c"
+#line 1703 "parse-gram.c"
   yylsp[0] = yylloc;
   goto yysetstate;
 
@@ -2316,33 +2322,40 @@ yyreduce:
 
 /* Line 1269 of yacc.c  */
 #line 398 "parse-gram.y"
-    { (yyval.list) = symbol_list_default_new ((yylsp[(1) - (1)])); }
+    { (yyval.list) = symbol_list_default_tagged_new ((yylsp[(1) - (1)])); }
     break;
 
   case 63:
 
 /* Line 1269 of yacc.c  */
-#line 404 "parse-gram.y"
+#line 399 "parse-gram.y"
+    { (yyval.list) = symbol_list_default_tagless_new ((yylsp[(1) - (1)])); }
+    break;
+
+  case 64:
+
+/* Line 1269 of yacc.c  */
+#line 405 "parse-gram.y"
     {
        current_type = (yyvsp[(1) - (1)].uniqstr);
        tag_seen = true;
      }
     break;
 
-  case 64:
+  case 65:
 
 /* Line 1269 of yacc.c  */
-#line 409 "parse-gram.y"
+#line 410 "parse-gram.y"
     {
        symbol_class_set ((yyvsp[(1) - (1)].symbol), current_class, (yylsp[(1) - (1)]), true);
        symbol_type_set ((yyvsp[(1) - (1)].symbol), current_type, (yylsp[(1) - (1)]));
      }
     break;
 
-  case 65:
+  case 66:
 
 /* Line 1269 of yacc.c  */
-#line 414 "parse-gram.y"
+#line 415 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
       symbol_type_set ((yyvsp[(1) - (2)].symbol), current_type, (yylsp[(1) - (2)]));
@@ -2350,10 +2363,10 @@ yyreduce:
     }
     break;
 
-  case 66:
+  case 67:
 
 /* Line 1269 of yacc.c  */
-#line 420 "parse-gram.y"
+#line 421 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
       symbol_type_set ((yyvsp[(1) - (2)].symbol), current_type, (yylsp[(1) - (2)]));
@@ -2361,10 +2374,10 @@ yyreduce:
     }
     break;
 
-  case 67:
+  case 68:
 
 /* Line 1269 of yacc.c  */
-#line 426 "parse-gram.y"
+#line 427 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (3)].symbol), current_class, (yylsp[(1) - (3)]), true);
       symbol_type_set ((yyvsp[(1) - (3)].symbol), current_type, (yylsp[(1) - (3)]));
@@ -2373,109 +2386,109 @@ yyreduce:
     }
     break;
 
-  case 74:
+  case 75:
 
 /* Line 1269 of yacc.c  */
-#line 456 "parse-gram.y"
+#line 457 "parse-gram.y"
     {
       yyerrok;
     }
     break;
 
-  case 75:
+  case 76:
 
 /* Line 1269 of yacc.c  */
-#line 462 "parse-gram.y"
+#line 463 "parse-gram.y"
     { current_lhs = (yyvsp[(1) - (1)].symbol); current_lhs_location = (yylsp[(1) - (1)]); }
     break;
 
-  case 77:
+  case 78:
 
 /* Line 1269 of yacc.c  */
-#line 466 "parse-gram.y"
+#line 467 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(1) - (1)])); }
     break;
 
-  case 78:
+  case 79:
 
 /* Line 1269 of yacc.c  */
-#line 467 "parse-gram.y"
+#line 468 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(3) - (3)])); }
     break;
 
-  case 80:
+  case 81:
 
 /* Line 1269 of yacc.c  */
-#line 473 "parse-gram.y"
+#line 474 "parse-gram.y"
     { grammar_current_rule_begin (current_lhs, current_lhs_location); }
     break;
 
-  case 81:
+  case 82:
 
 /* Line 1269 of yacc.c  */
-#line 475 "parse-gram.y"
+#line 476 "parse-gram.y"
     { grammar_current_rule_symbol_append ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)])); }
     break;
 
-  case 82:
+  case 83:
 
 /* Line 1269 of yacc.c  */
-#line 477 "parse-gram.y"
+#line 478 "parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])); }
     break;
 
-  case 83:
+  case 84:
 
 /* Line 1269 of yacc.c  */
-#line 479 "parse-gram.y"
+#line 480 "parse-gram.y"
     { grammar_current_rule_prec_set ((yyvsp[(3) - (3)].symbol), (yylsp[(3) - (3)])); }
     break;
 
-  case 84:
+  case 85:
 
 /* Line 1269 of yacc.c  */
-#line 481 "parse-gram.y"
+#line 482 "parse-gram.y"
     { grammar_current_rule_dprec_set ((yyvsp[(3) - (3)].integer), (yylsp[(3) - (3)])); }
     break;
 
-  case 85:
+  case 86:
 
 /* Line 1269 of yacc.c  */
-#line 483 "parse-gram.y"
+#line 484 "parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[(3) - (3)].uniqstr), (yylsp[(3) - (3)])); }
     break;
 
-  case 88:
+  case 89:
 
 /* Line 1269 of yacc.c  */
-#line 499 "parse-gram.y"
+#line 500 "parse-gram.y"
     {
       static char one[] = "1";
       (yyval.chars) = one;
     }
     break;
 
-  case 90:
+  case 91:
 
 /* Line 1269 of yacc.c  */
-#line 509 "parse-gram.y"
+#line 510 "parse-gram.y"
     {
       (yyvsp[(1) - (1)].chars)[strlen ((yyvsp[(1) - (1)].chars)) - 1] = '\n';
       (yyval.chars) = translate_code ((yyvsp[(1) - (1)].chars) + 1, (yylsp[(1) - (1)]));
     }
     break;
 
-  case 91:
+  case 92:
 
 /* Line 1269 of yacc.c  */
-#line 525 "parse-gram.y"
+#line 526 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
-  case 92:
+  case 93:
 
 /* Line 1269 of yacc.c  */
-#line 527 "parse-gram.y"
+#line 528 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[(1) - (1)].character)), (yylsp[(1) - (1)]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[(1) - (1)]), false);
@@ -2483,27 +2496,27 @@ yyreduce:
     }
     break;
 
-  case 93:
+  case 94:
 
 /* Line 1269 of yacc.c  */
-#line 535 "parse-gram.y"
+#line 536 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
-  case 96:
+  case 97:
 
 /* Line 1269 of yacc.c  */
-#line 547 "parse-gram.y"
+#line 548 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[(1) - (1)].chars)), (yylsp[(1) - (1)]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[(1) - (1)]), false);
     }
     break;
 
-  case 98:
+  case 99:
 
 /* Line 1269 of yacc.c  */
-#line 556 "parse-gram.y"
+#line 557 "parse-gram.y"
     {
       muscle_code_grow ("epilogue", translate_code ((yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])), (yylsp[(2) - (2)]));
       gram_scanner_last_string_free ();
@@ -2513,7 +2526,7 @@ yyreduce:
 
 
 /* Line 1269 of yacc.c  */
-#line 2517 "parse-gram.c"
+#line 2530 "parse-gram.c"
       default: break;
     }
   YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);
@@ -2732,7 +2745,7 @@ yyreturn:
 
 
 /* Line 1486 of yacc.c  */
-#line 562 "parse-gram.y"
+#line 563 "parse-gram.y"
 
 
 
