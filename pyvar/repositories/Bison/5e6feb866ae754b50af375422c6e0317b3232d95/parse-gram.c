@@ -206,38 +206,39 @@ static int current_prec = 0;
      PERCENT_FILE_PREFIX = 280,
      PERCENT_GLR_PARSER = 281,
      PERCENT_INITIAL_ACTION = 282,
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
-     TYPE_TAG_ANY = 312,
-     TYPE_TAG_NONE = 313,
-     PERCENT_UNION = 314
+     PERCENT_LANGUAGE = 283,
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
+     TYPE_TAG_ANY = 313,
+     TYPE_TAG_NONE = 314,
+     PERCENT_UNION = 315
    };
 #endif
 /* Tokens.  */
@@ -267,38 +268,39 @@ static int current_prec = 0;
 #define PERCENT_FILE_PREFIX 280
 #define PERCENT_GLR_PARSER 281
 #define PERCENT_INITIAL_ACTION 282
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
-#define TYPE_TAG_ANY 312
-#define TYPE_TAG_NONE 313
-#define PERCENT_UNION 314
+#define PERCENT_LANGUAGE 283
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
+#define TYPE_TAG_ANY 313
+#define TYPE_TAG_NONE 314
+#define PERCENT_UNION 315
 
 
 
@@ -306,7 +308,7 @@ static int current_prec = 0;
 #if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
 typedef union YYSTYPE
 {
-/* Line 198 of yacc.c  */
+/* Line 191 of yacc.c  */
 #line 97 "parse-gram.y"
 
   symbol *symbol;
@@ -319,8 +321,8 @@ typedef union YYSTYPE
   unsigned char character;
 }
 
-/* Line 198 of yacc.c  */
-#line 324 "parse-gram.c"
+/* Line 191 of yacc.c  */
+#line 326 "parse-gram.c"
 	YYSTYPE;
 # define YYSTYPE_IS_TRIVIAL 1
 # define yystype YYSTYPE /* obsolescent; will be withdrawn */
@@ -345,7 +347,7 @@ typedef struct YYLTYPE
 
 
 /* Line 221 of yacc.c  */
-#line 349 "parse-gram.c"
+#line 351 "parse-gram.c"
 
 #ifdef short
 # undef short
@@ -562,20 +564,20 @@ union yyalloc
 /* YYFINAL -- State number of the termination state.  */
 #define YYFINAL  3
 /* YYLAST -- Last index in YYTABLE.  */
-#define YYLAST   182
+#define YYLAST   187
 
 /* YYNTOKENS -- Number of terminals.  */
-#define YYNTOKENS  60
+#define YYNTOKENS  61
 /* YYNNTS -- Number of nonterminals.  */
 #define YYNNTS  31
 /* YYNRULES -- Number of rules.  */
-#define YYNRULES  103
+#define YYNRULES  104
 /* YYNRULES -- Number of states.  */
-#define YYNSTATES  142
+#define YYNSTATES  144
 
 /* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
 #define YYUNDEFTOK  2
-#define YYMAXUTOK   314
+#define YYMAXUTOK   315
 
 #define YYTRANSLATE(YYX)						\
   ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)
@@ -614,7 +616,7 @@ static const yytype_uint8 yytranslate[] =
       25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
       35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
       45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
-      55,    56,    57,    58,    59
+      55,    56,    57,    58,    59,    60
 };
 
 #if YYDEBUG
@@ -624,63 +626,63 @@ static const yytype_uint16 yyprhs[] =
 {
        0,     0,     3,     8,     9,    12,    14,    16,    18,    22,
       24,    27,    29,    32,    35,    38,    42,    44,    47,    50,
-      52,    55,    59,    61,    63,    66,    70,    73,    75,    77,
-      80,    83,    85,    87,    89,    91,    93,    95,    98,   102,
-     106,   108,   110,   113,   116,   119,   122,   123,   125,   129,
-     130,   134,   135,   139,   143,   147,   149,   151,   153,   154,
-     156,   158,   161,   163,   166,   168,   170,   172,   174,   176,
-     178,   181,   184,   188,   190,   193,   195,   198,   200,   203,
-     206,   207,   211,   213,   217,   220,   221,   224,   227,   231,
-     235,   239,   241,   243,   244,   246,   248,   250,   252,   254,
-     256,   258,   260,   261
+      53,    55,    58,    62,    64,    66,    69,    73,    76,    78,
+      80,    83,    86,    88,    90,    92,    94,    96,    98,   101,
+     105,   109,   111,   113,   116,   119,   122,   125,   126,   128,
+     132,   133,   137,   138,   142,   146,   150,   152,   154,   156,
+     157,   159,   161,   164,   166,   169,   171,   173,   175,   177,
+     179,   181,   184,   187,   191,   193,   196,   198,   201,   203,
+     206,   209,   210,   214,   216,   220,   223,   224,   227,   230,
+     234,   238,   242,   244,   246,   247,   249,   251,   253,   255,
+     257,   259,   261,   263,   264
 };
 
 /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
 static const yytype_int8 yyrhs[] =
 {
-      61,     0,    -1,    62,    52,    77,    90,    -1,    -1,    62,
-      63,    -1,    64,    -1,    54,    -1,    18,    -1,    20,     3,
-      84,    -1,    21,    -1,    21,     3,    -1,    22,    -1,    23,
-       4,    -1,    24,     4,    -1,    25,     3,    -1,    25,    49,
-       3,    -1,    26,    -1,    27,    46,    -1,    28,    46,    -1,
-      29,    -1,    30,     3,    -1,    30,    49,     3,    -1,    32,
-      -1,    33,    -1,    34,     3,    -1,    34,    49,     3,    -1,
-      35,    46,    -1,    37,    -1,    38,    -1,    39,     3,    -1,
-      41,     3,    -1,    43,    -1,    44,    -1,    45,    -1,    55,
-      -1,    69,    -1,    66,    -1,    42,    88,    -1,     8,    46,
-      73,    -1,     9,    46,    73,    -1,    19,    -1,    31,    -1,
-      16,    85,    -1,    17,    85,    -1,    36,    85,    -1,    40,
-      85,    -1,    -1,    50,    -1,    59,    65,    46,    -1,    -1,
-       6,    67,    76,    -1,    -1,     5,    68,    76,    -1,     7,
-      56,    72,    -1,    70,    71,    72,    -1,    10,    -1,    11,
-      -1,    12,    -1,    -1,    56,    -1,    88,    -1,    72,    88,
-      -1,    74,    -1,    73,    74,    -1,    88,    -1,    56,    -1,
-      57,    -1,    58,    -1,    56,    -1,    86,    -1,    86,     4,
-      -1,    86,    89,    -1,    86,     4,    89,    -1,    75,    -1,
-      76,    75,    -1,    78,    -1,    77,    78,    -1,    79,    -1,
-      64,    55,    -1,     1,    55,    -1,    -1,    87,    80,    81,
-      -1,    82,    -1,    81,    53,    82,    -1,    81,    55,    -1,
-      -1,    82,    88,    -1,    82,    46,    -1,    82,    13,    88,
-      -1,    82,    14,     4,    -1,    82,    15,    56,    -1,     3,
-      -1,    85,    -1,    -1,    83,    -1,    46,    -1,    50,    -1,
-      47,    -1,    51,    -1,    86,    -1,    89,    -1,     3,    -1,
-      -1,    52,    48,    -1
+      62,     0,    -1,    63,    53,    78,    91,    -1,    -1,    63,
+      64,    -1,    65,    -1,    55,    -1,    18,    -1,    20,     3,
+      85,    -1,    21,    -1,    21,     3,    -1,    22,    -1,    23,
+       4,    -1,    24,     4,    -1,    25,     3,    -1,    25,    50,
+       3,    -1,    26,    -1,    27,    47,    -1,    28,     3,    -1,
+      29,    47,    -1,    30,    -1,    31,     3,    -1,    31,    50,
+       3,    -1,    33,    -1,    34,    -1,    35,     3,    -1,    35,
+      50,     3,    -1,    36,    47,    -1,    38,    -1,    39,    -1,
+      40,     3,    -1,    42,     3,    -1,    44,    -1,    45,    -1,
+      46,    -1,    56,    -1,    70,    -1,    67,    -1,    43,    89,
+      -1,     8,    47,    74,    -1,     9,    47,    74,    -1,    19,
+      -1,    32,    -1,    16,    86,    -1,    17,    86,    -1,    37,
+      86,    -1,    41,    86,    -1,    -1,    51,    -1,    60,    66,
+      47,    -1,    -1,     6,    68,    77,    -1,    -1,     5,    69,
+      77,    -1,     7,    57,    73,    -1,    71,    72,    73,    -1,
+      10,    -1,    11,    -1,    12,    -1,    -1,    57,    -1,    89,
+      -1,    73,    89,    -1,    75,    -1,    74,    75,    -1,    89,
+      -1,    57,    -1,    58,    -1,    59,    -1,    57,    -1,    87,
+      -1,    87,     4,    -1,    87,    90,    -1,    87,     4,    90,
+      -1,    76,    -1,    77,    76,    -1,    79,    -1,    78,    79,
+      -1,    80,    -1,    65,    56,    -1,     1,    56,    -1,    -1,
+      88,    81,    82,    -1,    83,    -1,    82,    54,    83,    -1,
+      82,    56,    -1,    -1,    83,    89,    -1,    83,    47,    -1,
+      83,    13,    89,    -1,    83,    14,     4,    -1,    83,    15,
+      57,    -1,     3,    -1,    86,    -1,    -1,    84,    -1,    47,
+      -1,    51,    -1,    48,    -1,    52,    -1,    87,    -1,    90,
+      -1,     3,    -1,    -1,    53,    49,    -1
 };
 
 /* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
 static const yytype_uint16 yyrline[] =
 {
-       0,   210,   210,   218,   220,   224,   225,   226,   227,   228,
-     229,   234,   235,   236,   237,   238,   239,   244,   248,   249,
-     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
-     260,   261,   262,   263,   264,   268,   269,   270,   274,   282,
-     290,   294,   298,   299,   300,   301,   312,   313,   317,   345,
-     345,   350,   350,   355,   366,   381,   382,   383,   387,   388,
-     393,   395,   400,   401,   405,   406,   407,   408,   413,   418,
-     423,   429,   435,   446,   447,   456,   457,   463,   464,   465,
-     472,   472,   476,   477,   478,   483,   484,   486,   488,   490,
-     492,   502,   503,   509,   513,   518,   534,   536,   545,   550,
-     551,   556,   563,   565
+       0,   211,   211,   219,   221,   225,   226,   227,   228,   229,
+     230,   235,   236,   237,   238,   239,   240,   245,   249,   250,
+     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
+     261,   262,   263,   264,   265,   266,   270,   271,   272,   276,
+     284,   292,   296,   300,   301,   302,   303,   314,   315,   319,
+     347,   347,   352,   352,   357,   368,   383,   384,   385,   389,
+     390,   395,   397,   402,   403,   407,   408,   409,   410,   415,
+     420,   425,   431,   437,   448,   449,   458,   459,   465,   466,
+     467,   474,   474,   478,   479,   480,   485,   486,   488,   490,
+     492,   494,   504,   505,   511,   515,   520,   536,   538,   547,
+     552,   553,   558,   565,   567
 };
 #endif
 
@@ -695,16 +697,17 @@ static const char *const yytname[] =
   "\"%dprec\"", "\"%merge\"", "\"%code\"", "\"%code-top\"", "\"%debug\"",
   "\"%default-prec\"", "\"%define\"", "\"%defines\"", "\"%error-verbose\"",
   "\"%expect\"", "\"%expect-rr\"", "\"%file-prefix\"", "\"%glr-parser\"",
-  "\"%initial-action\"", "\"%lex-param\"", "\"%locations\"",
-  "\"%name-prefix\"", "\"%no-default-prec\"", "\"%no-lines\"",
-  "\"%nondeterministic-parser\"", "\"%output\"", "\"%parse-param\"",
-  "\"%provides\"", "\"%pure-parser\"", "\"%push-parser\"", "\"%require\"",
-  "\"%requires\"", "\"%skeleton\"", "\"%start\"", "\"%token-table\"",
-  "\"%verbose\"", "\"%yacc\"", "\"{...}\"", "\"char\"", "\"epilogue\"",
-  "\"=\"", "\"identifier\"", "\"identifier:\"", "\"%%\"", "\"|\"",
-  "\"%{...%}\"", "\";\"", "\"type\"", "\"<*>\"", "\"<>\"", "\"%union\"",
-  "$accept", "input", "prologue_declarations", "prologue_declaration",
-  "grammar_declaration", "union_name", "symbol_declaration", "$@1", "$@2",
+  "\"%initial-action\"", "\"%language\"", "\"%lex-param\"",
+  "\"%locations\"", "\"%name-prefix\"", "\"%no-default-prec\"",
+  "\"%no-lines\"", "\"%nondeterministic-parser\"", "\"%output\"",
+  "\"%parse-param\"", "\"%provides\"", "\"%pure-parser\"",
+  "\"%push-parser\"", "\"%require\"", "\"%requires\"", "\"%skeleton\"",
+  "\"%start\"", "\"%token-table\"", "\"%verbose\"", "\"%yacc\"",
+  "\"{...}\"", "\"char\"", "\"epilogue\"", "\"=\"", "\"identifier\"",
+  "\"identifier:\"", "\"%%\"", "\"|\"", "\"%{...%}\"", "\";\"", "\"type\"",
+  "\"<*>\"", "\"<>\"", "\"%union\"", "$accept", "input",
+  "prologue_declarations", "prologue_declaration", "grammar_declaration",
+  "union_name", "symbol_declaration", "$@1", "$@2",
   "precedence_declaration", "precedence_declarator", "type.opt",
   "symbols.1", "generic_symlist", "generic_symlist_item", "symbol_def",
   "symbol_defs.1", "grammar", "rules_or_grammar_declaration", "rules",
@@ -723,40 +726,41 @@ static const yytype_uint16 yytoknum[] =
      275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
      285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
      295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
-     305,   306,   307,   308,   309,   310,   311,   312,   313,   314
+     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
+     315
 };
 # endif
 
 /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
 static const yytype_uint8 yyr1[] =
 {
-       0,    60,    61,    62,    62,    63,    63,    63,    63,    63,
-      63,    63,    63,    63,    63,    63,    63,    63,    63,    63,
-      63,    63,    63,    63,    63,    63,    63,    63,    63,    63,
-      63,    63,    63,    63,    63,    64,    64,    64,    64,    64,
-      64,    64,    64,    64,    64,    64,    65,    65,    64,    67,
-      66,    68,    66,    66,    69,    70,    70,    70,    71,    71,
-      72,    72,    73,    73,    74,    74,    74,    74,    75,    75,
-      75,    75,    75,    76,    76,    77,    77,    78,    78,    78,
-      80,    79,    81,    81,    81,    82,    82,    82,    82,    82,
-      82,    83,    83,    84,    84,    85,    86,    86,    87,    88,
-      88,    89,    90,    90
+       0,    61,    62,    63,    63,    64,    64,    64,    64,    64,
+      64,    64,    64,    64,    64,    64,    64,    64,    64,    64,
+      64,    64,    64,    64,    64,    64,    64,    64,    64,    64,
+      64,    64,    64,    64,    64,    64,    65,    65,    65,    65,
+      65,    65,    65,    65,    65,    65,    65,    66,    66,    65,
+      68,    67,    69,    67,    67,    70,    71,    71,    71,    72,
+      72,    73,    73,    74,    74,    75,    75,    75,    75,    76,
+      76,    76,    76,    76,    77,    77,    78,    78,    79,    79,
+      79,    81,    80,    82,    82,    82,    83,    83,    83,    83,
+      83,    83,    84,    84,    85,    85,    86,    87,    87,    88,
+      89,    89,    90,    91,    91
 };
 
 /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
 static const yytype_uint8 yyr2[] =
 {
        0,     2,     4,     0,     2,     1,     1,     1,     3,     1,
-       2,     1,     2,     2,     2,     3,     1,     2,     2,     1,
-       2,     3,     1,     1,     2,     3,     2,     1,     1,     2,
-       2,     1,     1,     1,     1,     1,     1,     2,     3,     3,
-       1,     1,     2,     2,     2,     2,     0,     1,     3,     0,
-       3,     0,     3,     3,     3,     1,     1,     1,     0,     1,
-       1,     2,     1,     2,     1,     1,     1,     1,     1,     1,
-       2,     2,     3,     1,     2,     1,     2,     1,     2,     2,
-       0,     3,     1,     3,     2,     0,     2,     2,     3,     3,
-       3,     1,     1,     0,     1,     1,     1,     1,     1,     1,
-       1,     1,     0,     2
+       2,     1,     2,     2,     2,     3,     1,     2,     2,     2,
+       1,     2,     3,     1,     1,     2,     3,     2,     1,     1,
+       2,     2,     1,     1,     1,     1,     1,     1,     2,     3,
+       3,     1,     1,     2,     2,     2,     2,     0,     1,     3,
+       0,     3,     0,     3,     3,     3,     1,     1,     1,     0,
+       1,     1,     2,     1,     2,     1,     1,     1,     1,     1,
+       1,     2,     2,     3,     1,     2,     1,     2,     1,     2,
+       2,     0,     3,     1,     3,     2,     0,     2,     2,     3,
+       3,     3,     1,     1,     0,     1,     1,     1,     1,     1,
+       1,     1,     1,     0,     2
 };
 
 /* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
@@ -764,133 +768,133 @@ static const yytype_uint8 yyr2[] =
    means the default is an error.  */
 static const yytype_uint8 yydefact[] =
 {
-       3,     0,     0,     1,    51,    49,     0,     0,     0,    55,
-      56,    57,     0,     0,     7,    40,     0,     9,    11,     0,
-       0,     0,    16,     0,     0,    19,     0,    41,    22,    23,
-       0,     0,     0,    27,    28,     0,     0,     0,     0,    31,
-      32,    33,     0,     6,    34,    46,     4,     5,    36,    35,
-      58,     0,     0,     0,     0,     0,    95,    42,    43,    93,
-      10,    12,    13,    14,     0,    17,    18,    20,     0,    24,
-       0,    26,    44,    29,    45,    30,   101,    97,    96,    99,
-      37,   100,     0,    98,     0,     0,    75,    77,    80,    47,
-       0,    59,     0,    68,    73,    52,    69,    50,    53,    60,
-      65,    66,    67,    38,    62,    64,    39,    91,    94,     8,
-      92,    15,    21,    25,    79,    78,     0,    76,     2,    85,
-      48,    54,    74,    70,    71,    61,    63,   103,    81,    82,
-      72,    85,    84,     0,     0,     0,    87,    86,    83,    88,
-      89,    90
+       3,     0,     0,     1,    52,    50,     0,     0,     0,    56,
+      57,    58,     0,     0,     7,    41,     0,     9,    11,     0,
+       0,     0,    16,     0,     0,     0,    20,     0,    42,    23,
+      24,     0,     0,     0,    28,    29,     0,     0,     0,     0,
+      32,    33,    34,     0,     6,    35,    47,     4,     5,    37,
+      36,    59,     0,     0,     0,     0,     0,    96,    43,    44,
+      94,    10,    12,    13,    14,     0,    17,    18,    19,    21,
+       0,    25,     0,    27,    45,    30,    46,    31,   102,    98,
+      97,   100,    38,   101,     0,    99,     0,     0,    76,    78,
+      81,    48,     0,    60,     0,    69,    74,    53,    70,    51,
+      54,    61,    66,    67,    68,    39,    63,    65,    40,    92,
+      95,     8,    93,    15,    22,    26,    80,    79,     0,    77,
+       2,    86,    49,    55,    75,    71,    72,    62,    64,   104,
+      82,    83,    73,    86,    85,     0,     0,     0,    88,    87,
+      84,    89,    90,    91
 };
 
 /* YYDEFGOTO[NTERM-NUM].  */
 static const yytype_int16 yydefgoto[] =
 {
-      -1,     1,     2,    46,    84,    90,    48,    52,    51,    49,
-      50,    92,    98,   103,   104,    94,    95,    85,    86,    87,
-     119,   128,   129,   108,   109,    57,    79,    88,   105,    81,
-     118
+      -1,     1,     2,    47,    86,    92,    49,    53,    52,    50,
+      51,    94,   100,   105,   106,    96,    97,    87,    88,    89,
+     121,   130,   131,   110,   111,    58,    81,    90,   107,    83,
+     120
 };
 
 /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
    STATE-NUM.  */
-#define YYPACT_NINF -97
+#define YYPACT_NINF -95
 static const yytype_int8 yypact[] =
 {
-     -97,     3,   123,   -97,   -97,   -97,   -42,    -6,    -5,   -97,
-     -97,   -97,    -3,    -3,   -97,   -97,    41,    55,   -97,    57,
-      60,     1,   -97,    36,    40,   -97,    10,   -97,   -97,   -97,
-      23,    44,    -3,   -97,   -97,    85,    -3,    90,    -2,   -97,
-     -97,   -97,    68,   -97,   -97,    46,   -97,   -97,   -97,   -97,
-      38,    42,    42,    -2,    -1,    -1,   -97,   -97,   -97,    35,
-     -97,   -97,   -97,   -97,    94,   -97,   -97,   -97,    98,   -97,
-      99,   -97,   -97,   -97,   -97,   -97,   -97,   -97,   -97,   -97,
-     -97,   -97,    48,   -97,    50,    11,   -97,   -97,   -97,   -97,
-      61,   -97,    -2,   -97,   -97,    42,     5,    42,    -2,   -97,
-     -97,   -97,   -97,    -1,   -97,   -97,    -1,   -97,   -97,   -97,
-     -97,   -97,   -97,   -97,   -97,   -97,    58,   -97,   -97,   -97,
-     -97,    -2,   -97,   109,   -97,   -97,   -97,   -97,   -22,    21,
-     -97,   -97,   -97,    -2,   110,    59,   -97,   -97,    21,   -97,
-     -97,   -97
+     -95,     3,   127,   -95,   -95,   -95,   -24,    -7,    -6,   -95,
+     -95,   -95,    -3,    -3,   -95,   -95,    42,    56,   -95,    70,
+      87,    10,   -95,    28,    90,    47,   -95,    35,   -95,   -95,
+     -95,    36,    48,    -3,   -95,   -95,    94,    -3,    95,    -2,
+     -95,   -95,   -95,    71,   -95,   -95,    49,   -95,   -95,   -95,
+     -95,    45,   -43,   -43,    -2,    -1,    -1,   -95,   -95,   -95,
+      21,   -95,   -95,   -95,   -95,    96,   -95,   -95,   -95,   -95,
+     101,   -95,   102,   -95,   -95,   -95,   -95,   -95,   -95,   -95,
+     -95,   -95,   -95,   -95,    50,   -95,    51,    11,   -95,   -95,
+     -95,   -95,    62,   -95,    -2,   -95,   -95,   -43,     6,   -43,
+      -2,   -95,   -95,   -95,   -95,    -1,   -95,   -95,    -1,   -95,
+     -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,    61,   -95,
+     -95,   -95,   -95,    -2,   -95,   108,   -95,   -95,   -95,   -95,
+     -22,    22,   -95,   -95,   -95,    -2,   109,    58,   -95,   -95,
+      22,   -95,   -95,   -95
 };
 
 /* YYPGOTO[NTERM-NUM].  */
 static const yytype_int8 yypgoto[] =
 {
-     -97,   -97,   -97,   -97,   111,   -97,   -97,   -97,   -97,   -97,
-     -97,   -97,    24,    62,   -96,   -58,    66,   -97,    37,   -97,
-     -97,   -97,   -11,   -97,   -97,    -7,    14,   -97,   -38,   -91,
-     -97
+     -95,   -95,   -95,   -95,   114,   -95,   -95,   -95,   -95,   -95,
+     -95,   -95,    23,    63,   -79,   -32,    65,   -95,    33,   -95,
+     -95,   -95,   -12,   -95,   -95,    29,   -46,   -95,   -39,   -94,
+     -95
 };
 
 /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
    positive, shift that token.  If negative, reduce the rule which
    number is the opposite.  If zero, do what YYDEFACT says.
    If YYTABLE_NINF, syntax error.  */
-#define YYTABLE_NINF -103
+#define YYTABLE_NINF -104
 static const yytype_int16 yytable[] =
 {
-      80,    76,    76,     3,    63,   124,    58,   126,    76,   123,
-     126,  -102,    82,    67,    53,    99,     4,     5,     6,     7,
-       8,     9,    10,    11,    76,    72,    69,    12,    13,    74,
-      15,   131,   130,   132,   133,   134,   135,   122,   107,   122,
-      54,    55,    27,    56,    59,    77,    77,    32,    78,    78,
-      64,    36,   110,    38,    99,   100,   101,   102,    60,    68,
-     125,    61,    83,   116,    62,    96,    96,   136,    77,    82,
-      45,    78,    70,     4,     5,     6,     7,     8,     9,    10,
-      11,    56,    65,   125,    12,    13,    66,    15,    73,    77,
-      71,   137,    78,    75,    91,   139,    89,   111,    93,    27,
-     137,   112,   113,   114,    32,   115,   127,   120,    36,    96,
-      38,    96,    76,    47,   140,   141,   121,   106,    97,    83,
-     138,     0,   117,     0,     0,     0,     0,    45,     4,     5,
-       6,     7,     8,     9,    10,    11,     0,     0,     0,    12,
-      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
-      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
-      33,    34,    35,    36,    37,    38,    39,    40,    41,     0,
-       0,     0,     0,     0,     0,    42,     0,    43,    44,     0,
-       0,     0,    45
+      82,    78,    78,     3,   126,    79,    98,    98,    80,    78,
+     125,  -103,    84,    64,    95,   101,     4,     5,     6,     7,
+       8,     9,    10,    11,   109,    78,   128,    12,    13,   128,
+      15,   132,   133,    54,   134,   135,   136,   137,    69,    71,
+      55,    56,    59,    28,    57,    60,    79,    79,    33,    80,
+      80,    98,    37,    98,    39,   101,   102,   103,   104,    61,
+      65,   127,    74,    85,   118,   124,    76,   124,    57,   138,
+      79,    46,    84,    80,    62,    66,     4,     5,     6,     7,
+       8,     9,    10,    11,   127,    70,    72,    12,    13,   112,
+      15,    63,   139,    67,    68,    73,   141,    75,    77,   113,
+      91,   139,    93,    28,   114,   115,   116,   117,    33,   122,
+     129,    78,    37,   142,    39,   143,    48,   123,    99,   108,
+     119,   140,     0,    85,     0,     0,     0,     0,     0,     0,
+       0,    46,     4,     5,     6,     7,     8,     9,    10,    11,
+       0,     0,     0,    12,    13,    14,    15,    16,    17,    18,
+      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
+      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
+      39,    40,    41,    42,     0,     0,     0,     0,     0,     0,
+      43,     0,    44,    45,     0,     0,     0,    46
 };
 
 static const yytype_int16 yycheck[] =
 {
-      38,     3,     3,     0,     3,    96,    13,   103,     3,     4,
-     106,     0,     1,     3,    56,    53,     5,     6,     7,     8,
-       9,    10,    11,    12,     3,    32,     3,    16,    17,    36,
-      19,    53,   123,    55,    13,    14,    15,    95,     3,    97,
-      46,    46,    31,    46,     3,    47,    47,    36,    50,    50,
-      49,    40,    59,    42,    92,    56,    57,    58,     3,    49,
-      98,     4,    51,    52,     4,    51,    52,    46,    47,     1,
-      59,    50,    49,     5,     6,     7,     8,     9,    10,    11,
-      12,    46,    46,   121,    16,    17,    46,    19,     3,    47,
-      46,   129,    50,     3,    56,   133,    50,     3,    56,    31,
-     138,     3,     3,    55,    36,    55,    48,    46,    40,    95,
-      42,    97,     3,     2,     4,    56,    92,    55,    52,    51,
-     131,    -1,    85,    -1,    -1,    -1,    -1,    59,     5,     6,
-       7,     8,     9,    10,    11,    12,    -1,    -1,    -1,    16,
-      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
-      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
-      37,    38,    39,    40,    41,    42,    43,    44,    45,    -1,
-      -1,    -1,    -1,    -1,    -1,    52,    -1,    54,    55,    -1,
-      -1,    -1,    59
+      39,     3,     3,     0,    98,    48,    52,    53,    51,     3,
+       4,     0,     1,     3,    57,    54,     5,     6,     7,     8,
+       9,    10,    11,    12,     3,     3,   105,    16,    17,   108,
+      19,   125,    54,    57,    56,    13,    14,    15,     3,     3,
+      47,    47,    13,    32,    47,     3,    48,    48,    37,    51,
+      51,    97,    41,    99,    43,    94,    57,    58,    59,     3,
+      50,   100,    33,    52,    53,    97,    37,    99,    47,    47,
+      48,    60,     1,    51,     4,    47,     5,     6,     7,     8,
+       9,    10,    11,    12,   123,    50,    50,    16,    17,    60,
+      19,     4,   131,     3,    47,    47,   135,     3,     3,     3,
+      51,   140,    57,    32,     3,     3,    56,    56,    37,    47,
+      49,     3,    41,     4,    43,    57,     2,    94,    53,    56,
+      87,   133,    -1,    52,    -1,    -1,    -1,    -1,    -1,    -1,
+      -1,    60,     5,     6,     7,     8,     9,    10,    11,    12,
+      -1,    -1,    -1,    16,    17,    18,    19,    20,    21,    22,
+      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
+      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
+      43,    44,    45,    46,    -1,    -1,    -1,    -1,    -1,    -1,
+      53,    -1,    55,    56,    -1,    -1,    -1,    60
 };
 
 /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
    symbol of state STATE-NUM.  */
 static const yytype_uint8 yystos[] =
 {
-       0,    61,    62,     0,     5,     6,     7,     8,     9,    10,
+       0,    62,    63,     0,     5,     6,     7,     8,     9,    10,
       11,    12,    16,    17,    18,    19,    20,    21,    22,    23,
       24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
       34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
-      44,    45,    52,    54,    55,    59,    63,    64,    66,    69,
-      70,    68,    67,    56,    46,    46,    46,    85,    85,     3,
-       3,     4,     4,     3,    49,    46,    46,     3,    49,     3,
-      49,    46,    85,     3,    85,     3,     3,    47,    50,    86,
-      88,    89,     1,    51,    64,    77,    78,    79,    87,    50,
-      65,    56,    71,    56,    75,    76,    86,    76,    72,    88,
-      56,    57,    58,    73,    74,    88,    73,     3,    83,    84,
-      85,     3,     3,     3,    55,    55,    52,    78,    90,    80,
-      46,    72,    75,     4,    89,    88,    74,    48,    81,    82,
-      89,    53,    55,    13,    14,    15,    46,    88,    82,    88,
-       4,    56
+      44,    45,    46,    53,    55,    56,    60,    64,    65,    67,
+      70,    71,    69,    68,    57,    47,    47,    47,    86,    86,
+       3,     3,     4,     4,     3,    50,    47,     3,    47,     3,
+      50,     3,    50,    47,    86,     3,    86,     3,     3,    48,
+      51,    87,    89,    90,     1,    52,    65,    78,    79,    80,
+      88,    51,    66,    57,    72,    57,    76,    77,    87,    77,
+      73,    89,    57,    58,    59,    74,    75,    89,    74,     3,
+      84,    85,    86,     3,     3,     3,    56,    56,    53,    79,
+      91,    81,    47,    73,    76,     4,    90,    89,    75,    49,
+      82,    83,    90,    54,    56,    13,    14,    15,    47,    89,
+      83,    89,     4,    57
 };
 
 #define yyerrok		(yyerrstatus = 0)
@@ -1041,146 +1045,146 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
       case 3: /* "\"string\"" */
 
 /* Line 670 of yacc.c  */
-#line 188 "parse-gram.y"
+#line 189 "parse-gram.y"
 	{ fputs (quotearg_style (c_quoting_style, (yyvaluep->chars)), stderr); };
 
 /* Line 670 of yacc.c  */
-#line 1049 "parse-gram.c"
+#line 1053 "parse-gram.c"
 	break;
       case 4: /* "\"integer\"" */
 
 /* Line 670 of yacc.c  */
-#line 199 "parse-gram.y"
+#line 200 "parse-gram.y"
 	{ fprintf (stderr, "%d", (yyvaluep->integer)); };
 
 /* Line 670 of yacc.c  */
-#line 1058 "parse-gram.c"
+#line 1062 "parse-gram.c"
 	break;
-      case 46: /* "\"{...}\"" */
+      case 47: /* "\"{...}\"" */
 
 /* Line 670 of yacc.c  */
-#line 190 "parse-gram.y"
+#line 191 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->code)); };
 
 /* Line 670 of yacc.c  */
-#line 1067 "parse-gram.c"
+#line 1071 "parse-gram.c"
 	break;
-      case 47: /* "\"char\"" */
+      case 48: /* "\"char\"" */
 
 /* Line 670 of yacc.c  */
-#line 182 "parse-gram.y"
+#line 183 "parse-gram.y"
 	{ fputs (char_name ((yyvaluep->character)), stderr); };
 
 /* Line 670 of yacc.c  */
-#line 1076 "parse-gram.c"
+#line 1080 "parse-gram.c"
 	break;
-      case 48: /* "\"epilogue\"" */
+      case 49: /* "\"epilogue\"" */
 
 /* Line 670 of yacc.c  */
-#line 190 "parse-gram.y"
+#line 191 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
 /* Line 670 of yacc.c  */
-#line 1085 "parse-gram.c"
+#line 1089 "parse-gram.c"
 	break;
-      case 50: /* "\"identifier\"" */
+      case 51: /* "\"identifier\"" */
 
 /* Line 670 of yacc.c  */
-#line 195 "parse-gram.y"
+#line 196 "parse-gram.y"
 	{ fputs ((yyvaluep->uniqstr), stderr); };
 
 /* Line 670 of yacc.c  */
-#line 1094 "parse-gram.c"
+#line 1098 "parse-gram.c"
 	break;
-      case 51: /* "\"identifier:\"" */
+      case 52: /* "\"identifier:\"" */
 
 /* Line 670 of yacc.c  */
-#line 196 "parse-gram.y"
+#line 197 "parse-gram.y"
 	{ fprintf (stderr, "%s:", (yyvaluep->uniqstr)); };
 
 /* Line 670 of yacc.c  */
-#line 1103 "parse-gram.c"
+#line 1107 "parse-gram.c"
 	break;
-      case 54: /* "\"%{...%}\"" */
+      case 55: /* "\"%{...%}\"" */
 
 /* Line 670 of yacc.c  */
-#line 190 "parse-gram.y"
+#line 191 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
 /* Line 670 of yacc.c  */
-#line 1112 "parse-gram.c"
+#line 1116 "parse-gram.c"
 	break;
-      case 56: /* "\"type\"" */
+      case 57: /* "\"type\"" */
 
 /* Line 670 of yacc.c  */
-#line 194 "parse-gram.y"
+#line 195 "parse-gram.y"
 	{ fprintf (stderr, "<%s>", (yyvaluep->uniqstr)); };
 
 /* Line 670 of yacc.c  */
-#line 1121 "parse-gram.c"
+#line 1125 "parse-gram.c"
 	break;
-      case 83: /* "content" */
+      case 84: /* "content" */
 
 /* Line 670 of yacc.c  */
-#line 190 "parse-gram.y"
+#line 191 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
 /* Line 670 of yacc.c  */
-#line 1130 "parse-gram.c"
+#line 1134 "parse-gram.c"
 	break;
-      case 84: /* "content.opt" */
+      case 85: /* "content.opt" */
 
 /* Line 670 of yacc.c  */
-#line 190 "parse-gram.y"
+#line 191 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
 /* Line 670 of yacc.c  */
-#line 1139 "parse-gram.c"
+#line 1143 "parse-gram.c"
 	break;
-      case 85: /* "braceless" */
+      case 86: /* "braceless" */
 
 /* Line 670 of yacc.c  */
-#line 190 "parse-gram.y"
+#line 191 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
 /* Line 670 of yacc.c  */
-#line 1148 "parse-gram.c"
+#line 1152 "parse-gram.c"
 	break;
-      case 86: /* "id" */
+      case 87: /* "id" */
 
 /* Line 670 of yacc.c  */
-#line 202 "parse-gram.y"
+#line 203 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
 /* Line 670 of yacc.c  */
-#line 1157 "parse-gram.c"
+#line 1161 "parse-gram.c"
 	break;
-      case 87: /* "id_colon" */
+      case 88: /* "id_colon" */
 
 /* Line 670 of yacc.c  */
-#line 203 "parse-gram.y"
+#line 204 "parse-gram.y"
 	{ fprintf (stderr, "%s:", (yyvaluep->symbol)->tag); };
 
 /* Line 670 of yacc.c  */
-#line 1166 "parse-gram.c"
+#line 1170 "parse-gram.c"
 	break;
-      case 88: /* "symbol" */
+      case 89: /* "symbol" */
 
 /* Line 670 of yacc.c  */
-#line 202 "parse-gram.y"
+#line 203 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
 /* Line 670 of yacc.c  */
-#line 1175 "parse-gram.c"
+#line 1179 "parse-gram.c"
 	break;
-      case 89: /* "string_as_id" */
+      case 90: /* "string_as_id" */
 
 /* Line 670 of yacc.c  */
-#line 202 "parse-gram.y"
+#line 203 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
 /* Line 670 of yacc.c  */
-#line 1184 "parse-gram.c"
+#line 1188 "parse-gram.c"
 	break;
       default:
 	break;
@@ -1694,7 +1698,7 @@ YYLTYPE yylloc;
 
   /* User initialization code.  */
   
-/* Line 1082 of yacc.c  */
+/* Line 1076 of yacc.c  */
 #line 89 "parse-gram.y"
 {
   /* Bison's grammar can initial empty locations, hence a default
@@ -1703,8 +1707,8 @@ YYLTYPE yylloc;
   boundary_set (&yylloc.end, current_file, 1, 1);
 }
 
-/* Line 1082 of yacc.c  */
-#line 1708 "parse-gram.c"
+/* Line 1076 of yacc.c  */
+#line 1712 "parse-gram.c"
   yylsp[0] = yylloc;
   goto yysetstate;
 
@@ -1890,35 +1894,35 @@ yyreduce:
         case 6:
 
 /* Line 1269 of yacc.c  */
-#line 225 "parse-gram.y"
+#line 226 "parse-gram.y"
     { prologue_augment (translate_code ((yyvsp[(1) - (1)].chars), (yylsp[(1) - (1)])), (yylsp[(1) - (1)]), union_seen); }
     break;
 
   case 7:
 
 /* Line 1269 of yacc.c  */
-#line 226 "parse-gram.y"
+#line 227 "parse-gram.y"
     { debug_flag = true; }
     break;
 
   case 8:
 
 /* Line 1269 of yacc.c  */
-#line 227 "parse-gram.y"
+#line 228 "parse-gram.y"
     { muscle_insert ((yyvsp[(2) - (3)].chars), (yyvsp[(3) - (3)].chars)); }
     break;
 
   case 9:
 
 /* Line 1269 of yacc.c  */
-#line 228 "parse-gram.y"
+#line 229 "parse-gram.y"
     { defines_flag = true; }
     break;
 
   case 10:
 
 /* Line 1269 of yacc.c  */
-#line 230 "parse-gram.y"
+#line 231 "parse-gram.y"
     {
       defines_flag = true;
       spec_defines_file = xstrdup ((yyvsp[(2) - (2)].chars));
@@ -1928,42 +1932,42 @@ yyreduce:
   case 11:
 
 /* Line 1269 of yacc.c  */
-#line 234 "parse-gram.y"
+#line 235 "parse-gram.y"
     { error_verbose = true; }
     break;
 
   case 12:
 
 /* Line 1269 of yacc.c  */
-#line 235 "parse-gram.y"
+#line 236 "parse-gram.y"
     { expected_sr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 13:
 
 /* Line 1269 of yacc.c  */
-#line 236 "parse-gram.y"
+#line 237 "parse-gram.y"
     { expected_rr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 14:
 
 /* Line 1269 of yacc.c  */
-#line 237 "parse-gram.y"
+#line 238 "parse-gram.y"
     { spec_file_prefix = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 15:
 
 /* Line 1269 of yacc.c  */
-#line 238 "parse-gram.y"
+#line 239 "parse-gram.y"
     { spec_file_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 16:
 
 /* Line 1269 of yacc.c  */
-#line 240 "parse-gram.y"
+#line 241 "parse-gram.y"
     {
       nondeterministic_parser = true;
       glr_parser = true;
@@ -1973,7 +1977,7 @@ yyreduce:
   case 17:
 
 /* Line 1269 of yacc.c  */
-#line 245 "parse-gram.y"
+#line 246 "parse-gram.y"
     {
       muscle_code_grow ("initial_action", translate_symbol_action ((yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])), (yylsp[(2) - (2)]));
     }
@@ -1982,128 +1986,135 @@ yyreduce:
   case 18:
 
 /* Line 1269 of yacc.c  */
-#line 248 "parse-gram.y"
-    { add_param ("lex_param", (yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
+#line 249 "parse-gram.y"
+    { language_argmatch ((yyvsp[(2) - (2)].chars), 1, &(yylsp[(1) - (2)])); }
     break;
 
   case 19:
 
 /* Line 1269 of yacc.c  */
-#line 249 "parse-gram.y"
-    { locations_flag = true; }
+#line 250 "parse-gram.y"
+    { add_param ("lex_param", (yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
     break;
 
   case 20:
 
 /* Line 1269 of yacc.c  */
-#line 250 "parse-gram.y"
-    { spec_name_prefix = (yyvsp[(2) - (2)].chars); }
+#line 251 "parse-gram.y"
+    { locations_flag = true; }
     break;
 
   case 21:
 
 /* Line 1269 of yacc.c  */
-#line 251 "parse-gram.y"
-    { spec_name_prefix = (yyvsp[(3) - (3)].chars); }
+#line 252 "parse-gram.y"
+    { spec_name_prefix = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 22:
 
 /* Line 1269 of yacc.c  */
-#line 252 "parse-gram.y"
-    { no_lines_flag = true; }
+#line 253 "parse-gram.y"
+    { spec_name_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 23:
 
 /* Line 1269 of yacc.c  */
-#line 253 "parse-gram.y"
-    { nondeterministic_parser = true; }
+#line 254 "parse-gram.y"
+    { no_lines_flag = true; }
     break;
 
   case 24:
 
 /* Line 1269 of yacc.c  */
-#line 254 "parse-gram.y"
-    { spec_outfile = (yyvsp[(2) - (2)].chars); }
+#line 255 "parse-gram.y"
+    { nondeterministic_parser = true; }
     break;
 
   case 25:
 
 /* Line 1269 of yacc.c  */
-#line 255 "parse-gram.y"
-    { spec_outfile = (yyvsp[(3) - (3)].chars); }
+#line 256 "parse-gram.y"
+    { spec_outfile = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 26:
 
 /* Line 1269 of yacc.c  */
-#line 256 "parse-gram.y"
-    { add_param ("parse_param", (yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
+#line 257 "parse-gram.y"
+    { spec_outfile = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 27:
 
 /* Line 1269 of yacc.c  */
-#line 257 "parse-gram.y"
-    { pure_parser = true; }
+#line 258 "parse-gram.y"
+    { add_param ("parse_param", (yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
     break;
 
   case 28:
 
 /* Line 1269 of yacc.c  */
-#line 258 "parse-gram.y"
-    { push_parser = true; pure_parser = true; }
+#line 259 "parse-gram.y"
+    { pure_parser = true; }
     break;
 
   case 29:
 
 /* Line 1269 of yacc.c  */
-#line 259 "parse-gram.y"
-    { version_check (&(yylsp[(2) - (2)]), (yyvsp[(2) - (2)].chars)); }
+#line 260 "parse-gram.y"
+    { push_parser = true; pure_parser = true; }
     break;
 
   case 30:
 
 /* Line 1269 of yacc.c  */
-#line 260 "parse-gram.y"
-    { skeleton = (yyvsp[(2) - (2)].chars); }
+#line 261 "parse-gram.y"
+    { version_check (&(yylsp[(2) - (2)]), (yyvsp[(2) - (2)].chars)); }
     break;
 
   case 31:
 
 /* Line 1269 of yacc.c  */
-#line 261 "parse-gram.y"
-    { token_table_flag = true; }
+#line 262 "parse-gram.y"
+    { skeleton_arg ((yyvsp[(2) - (2)].chars), 1, &(yylsp[(1) - (2)])); }
     break;
 
   case 32:
 
 /* Line 1269 of yacc.c  */
-#line 262 "parse-gram.y"
-    { report_flag = report_states; }
+#line 263 "parse-gram.y"
+    { token_table_flag = true; }
     break;
 
   case 33:
 
 /* Line 1269 of yacc.c  */
-#line 263 "parse-gram.y"
+#line 264 "parse-gram.y"
+    { report_flag = report_states; }
+    break;
+
+  case 34:
+
+/* Line 1269 of yacc.c  */
+#line 265 "parse-gram.y"
     { yacc_flag = true; }
     break;
 
-  case 37:
+  case 38:
 
 /* Line 1269 of yacc.c  */
-#line 271 "parse-gram.y"
+#line 273 "parse-gram.y"
     {
       grammar_start_symbol_set ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]));
     }
     break;
 
-  case 38:
+  case 39:
 
 /* Line 1269 of yacc.c  */
-#line 275 "parse-gram.y"
+#line 277 "parse-gram.y"
     {
       symbol_list *list;
       const char *action = translate_symbol_action ((yyvsp[(2) - (3)].code), (yylsp[(2) - (3)]));
@@ -2113,10 +2124,10 @@ yyreduce:
     }
     break;
 
-  case 39:
+  case 40:
 
 /* Line 1269 of yacc.c  */
-#line 283 "parse-gram.y"
+#line 285 "parse-gram.y"
     {
       symbol_list *list;
       const char *action = translate_symbol_action ((yyvsp[(2) - (3)].code), (yylsp[(2) - (3)]));
@@ -2126,70 +2137,70 @@ yyreduce:
     }
     break;
 
-  case 40:
+  case 41:
 
 /* Line 1269 of yacc.c  */
-#line 291 "parse-gram.y"
+#line 293 "parse-gram.y"
     {
       default_prec = true;
     }
     break;
 
-  case 41:
+  case 42:
 
 /* Line 1269 of yacc.c  */
-#line 295 "parse-gram.y"
+#line 297 "parse-gram.y"
     {
       default_prec = false;
     }
     break;
 
-  case 42:
+  case 43:
 
 /* Line 1269 of yacc.c  */
-#line 298 "parse-gram.y"
+#line 300 "parse-gram.y"
     { prologue_augment ((yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)]), true); }
     break;
 
-  case 43:
+  case 44:
 
 /* Line 1269 of yacc.c  */
-#line 299 "parse-gram.y"
+#line 301 "parse-gram.y"
     { prologue_augment ((yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)]), false); }
     break;
 
-  case 44:
+  case 45:
 
 /* Line 1269 of yacc.c  */
-#line 300 "parse-gram.y"
+#line 302 "parse-gram.y"
     { muscle_code_grow ("provides", (yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])); }
     break;
 
-  case 45:
+  case 46:
 
 /* Line 1269 of yacc.c  */
-#line 301 "parse-gram.y"
+#line 303 "parse-gram.y"
     { muscle_code_grow ("requires", (yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])); }
     break;
 
-  case 46:
+  case 47:
 
 /* Line 1269 of yacc.c  */
-#line 312 "parse-gram.y"
+#line 314 "parse-gram.y"
     {}
     break;
 
-  case 47:
+  case 48:
 
 /* Line 1269 of yacc.c  */
-#line 313 "parse-gram.y"
+#line 315 "parse-gram.y"
     { muscle_code_grow ("union_name", (yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
-  case 48:
+  case 49:
 
 /* Line 1269 of yacc.c  */
-#line 318 "parse-gram.y"
+#line 320 "parse-gram.y"
     {
       char const *body = (yyvsp[(3) - (3)].code);
 
@@ -2213,44 +2224,44 @@ yyreduce:
     }
     break;
 
-  case 49:
+  case 50:
 
 /* Line 1269 of yacc.c  */
-#line 345 "parse-gram.y"
+#line 347 "parse-gram.y"
     { current_class = nterm_sym; }
     break;
 
-  case 50:
+  case 51:
 
 /* Line 1269 of yacc.c  */
-#line 346 "parse-gram.y"
+#line 348 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
     break;
 
-  case 51:
+  case 52:
 
 /* Line 1269 of yacc.c  */
-#line 350 "parse-gram.y"
+#line 352 "parse-gram.y"
     { current_class = token_sym; }
     break;
 
-  case 52:
+  case 53:
 
 /* Line 1269 of yacc.c  */
-#line 351 "parse-gram.y"
+#line 353 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
     break;
 
-  case 53:
+  case 54:
 
 /* Line 1269 of yacc.c  */
-#line 356 "parse-gram.y"
+#line 358 "parse-gram.y"
     {
       symbol_list *list;
       tag_seen = true;
@@ -2260,10 +2271,10 @@ yyreduce:
     }
     break;
 
-  case 54:
+  case 55:
 
 /* Line 1269 of yacc.c  */
-#line 367 "parse-gram.y"
+#line 369 "parse-gram.y"
     {
       symbol_list *list;
       ++current_prec;
@@ -2277,121 +2288,121 @@ yyreduce:
     }
     break;
 
-  case 55:
+  case 56:
 
 /* Line 1269 of yacc.c  */
-#line 381 "parse-gram.y"
+#line 383 "parse-gram.y"
     { (yyval.assoc) = left_assoc; }
     break;
 
-  case 56:
+  case 57:
 
 /* Line 1269 of yacc.c  */
-#line 382 "parse-gram.y"
+#line 384 "parse-gram.y"
     { (yyval.assoc) = right_assoc; }
     break;
 
-  case 57:
+  case 58:
 
 /* Line 1269 of yacc.c  */
-#line 383 "parse-gram.y"
+#line 385 "parse-gram.y"
     { (yyval.assoc) = non_assoc; }
     break;
 
-  case 58:
+  case 59:
 
 /* Line 1269 of yacc.c  */
-#line 387 "parse-gram.y"
+#line 389 "parse-gram.y"
     { current_type = NULL; }
     break;
 
-  case 59:
+  case 60:
 
 /* Line 1269 of yacc.c  */
-#line 388 "parse-gram.y"
+#line 390 "parse-gram.y"
     { current_type = (yyvsp[(1) - (1)].uniqstr); tag_seen = true; }
     break;
 
-  case 60:
+  case 61:
 
 /* Line 1269 of yacc.c  */
-#line 394 "parse-gram.y"
+#line 396 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
-  case 61:
+  case 62:
 
 /* Line 1269 of yacc.c  */
-#line 396 "parse-gram.y"
+#line 398 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), symbol_list_sym_new ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]))); }
     break;
 
-  case 62:
+  case 63:
 
 /* Line 1269 of yacc.c  */
-#line 400 "parse-gram.y"
+#line 402 "parse-gram.y"
     { (yyval.list) = (yyvsp[(1) - (1)].list); }
     break;
 
-  case 63:
+  case 64:
 
 /* Line 1269 of yacc.c  */
-#line 401 "parse-gram.y"
+#line 403 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), (yyvsp[(2) - (2)].list)); }
     break;
 
-  case 64:
+  case 65:
 
 /* Line 1269 of yacc.c  */
-#line 405 "parse-gram.y"
+#line 407 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
-  case 65:
+  case 66:
 
 /* Line 1269 of yacc.c  */
-#line 406 "parse-gram.y"
+#line 408 "parse-gram.y"
     { (yyval.list) = symbol_list_type_new ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
-  case 66:
+  case 67:
 
 /* Line 1269 of yacc.c  */
-#line 407 "parse-gram.y"
+#line 409 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagged_new ((yylsp[(1) - (1)])); }
     break;
 
-  case 67:
+  case 68:
 
 /* Line 1269 of yacc.c  */
-#line 408 "parse-gram.y"
+#line 410 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagless_new ((yylsp[(1) - (1)])); }
     break;
 
-  case 68:
+  case 69:
 
 /* Line 1269 of yacc.c  */
-#line 414 "parse-gram.y"
+#line 416 "parse-gram.y"
     {
        current_type = (yyvsp[(1) - (1)].uniqstr);
        tag_seen = true;
      }
     break;
 
-  case 69:
+  case 70:
 
 /* Line 1269 of yacc.c  */
-#line 419 "parse-gram.y"
+#line 421 "parse-gram.y"
     {
        symbol_class_set ((yyvsp[(1) - (1)].symbol), current_class, (yylsp[(1) - (1)]), true);
        symbol_type_set ((yyvsp[(1) - (1)].symbol), current_type, (yylsp[(1) - (1)]));
      }
     break;
 
-  case 70:
+  case 71:
 
 /* Line 1269 of yacc.c  */
-#line 424 "parse-gram.y"
+#line 426 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
       symbol_type_set ((yyvsp[(1) - (2)].symbol), current_type, (yylsp[(1) - (2)]));
@@ -2399,10 +2410,10 @@ yyreduce:
     }
     break;
 
-  case 71:
+  case 72:
 
 /* Line 1269 of yacc.c  */
-#line 430 "parse-gram.y"
+#line 432 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
       symbol_type_set ((yyvsp[(1) - (2)].symbol), current_type, (yylsp[(1) - (2)]));
@@ -2410,10 +2421,10 @@ yyreduce:
     }
     break;
 
-  case 72:
+  case 73:
 
 /* Line 1269 of yacc.c  */
-#line 436 "parse-gram.y"
+#line 438 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (3)].symbol), current_class, (yylsp[(1) - (3)]), true);
       symbol_type_set ((yyvsp[(1) - (3)].symbol), current_type, (yylsp[(1) - (3)]));
@@ -2422,109 +2433,109 @@ yyreduce:
     }
     break;
 
-  case 79:
+  case 80:
 
 /* Line 1269 of yacc.c  */
-#line 466 "parse-gram.y"
+#line 468 "parse-gram.y"
     {
       yyerrok;
     }
     break;
 
-  case 80:
+  case 81:
 
 /* Line 1269 of yacc.c  */
-#line 472 "parse-gram.y"
+#line 474 "parse-gram.y"
     { current_lhs = (yyvsp[(1) - (1)].symbol); current_lhs_location = (yylsp[(1) - (1)]); }
     break;
 
-  case 82:
+  case 83:
 
 /* Line 1269 of yacc.c  */
-#line 476 "parse-gram.y"
+#line 478 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(1) - (1)])); }
     break;
 
-  case 83:
+  case 84:
 
 /* Line 1269 of yacc.c  */
-#line 477 "parse-gram.y"
+#line 479 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(3) - (3)])); }
     break;
 
-  case 85:
-
-/* Line 1269 of yacc.c  */
-#line 483 "parse-gram.y"
-    { grammar_current_rule_begin (current_lhs, current_lhs_location); }
-    break;
-
   case 86:
 
 /* Line 1269 of yacc.c  */
 #line 485 "parse-gram.y"
-    { grammar_current_rule_symbol_append ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)])); }
+    { grammar_current_rule_begin (current_lhs, current_lhs_location); }
     break;
 
   case 87:
 
 /* Line 1269 of yacc.c  */
 #line 487 "parse-gram.y"
-    { grammar_current_rule_action_append ((yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
+    { grammar_current_rule_symbol_append ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)])); }
     break;
 
   case 88:
 
 /* Line 1269 of yacc.c  */
 #line 489 "parse-gram.y"
-    { grammar_current_rule_prec_set ((yyvsp[(3) - (3)].symbol), (yylsp[(3) - (3)])); }
+    { grammar_current_rule_action_append ((yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
     break;
 
   case 89:
 
 /* Line 1269 of yacc.c  */
 #line 491 "parse-gram.y"
-    { grammar_current_rule_dprec_set ((yyvsp[(3) - (3)].integer), (yylsp[(3) - (3)])); }
+    { grammar_current_rule_prec_set ((yyvsp[(3) - (3)].symbol), (yylsp[(3) - (3)])); }
     break;
 
   case 90:
 
 /* Line 1269 of yacc.c  */
 #line 493 "parse-gram.y"
+    { grammar_current_rule_dprec_set ((yyvsp[(3) - (3)].integer), (yylsp[(3) - (3)])); }
+    break;
+
+  case 91:
+
+/* Line 1269 of yacc.c  */
+#line 495 "parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[(3) - (3)].uniqstr), (yylsp[(3) - (3)])); }
     break;
 
-  case 93:
+  case 94:
 
 /* Line 1269 of yacc.c  */
-#line 509 "parse-gram.y"
+#line 511 "parse-gram.y"
     {
       static char one[] = "1";
       (yyval.chars) = one;
     }
     break;
 
-  case 95:
+  case 96:
 
 /* Line 1269 of yacc.c  */
-#line 519 "parse-gram.y"
+#line 521 "parse-gram.y"
     {
       (yyvsp[(1) - (1)].code)[strlen ((yyvsp[(1) - (1)].code)) - 1] = '\n';
       (yyval.chars) = translate_code ((yyvsp[(1) - (1)].code) + 1, (yylsp[(1) - (1)]));
     }
     break;
 
-  case 96:
+  case 97:
 
 /* Line 1269 of yacc.c  */
-#line 535 "parse-gram.y"
+#line 537 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
-  case 97:
+  case 98:
 
 /* Line 1269 of yacc.c  */
-#line 537 "parse-gram.y"
+#line 539 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[(1) - (1)].character)), (yylsp[(1) - (1)]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[(1) - (1)]), false);
@@ -2532,27 +2543,27 @@ yyreduce:
     }
     break;
 
-  case 98:
+  case 99:
 
 /* Line 1269 of yacc.c  */
-#line 545 "parse-gram.y"
+#line 547 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
-  case 101:
+  case 102:
 
 /* Line 1269 of yacc.c  */
-#line 557 "parse-gram.y"
+#line 559 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[(1) - (1)].chars)), (yylsp[(1) - (1)]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[(1) - (1)]), false);
     }
     break;
 
-  case 103:
+  case 104:
 
 /* Line 1269 of yacc.c  */
-#line 566 "parse-gram.y"
+#line 568 "parse-gram.y"
     {
       muscle_code_grow ("epilogue", translate_code ((yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])), (yylsp[(2) - (2)]));
       gram_scanner_last_string_free ();
@@ -2562,7 +2573,7 @@ yyreduce:
 
 
 /* Line 1269 of yacc.c  */
-#line 2566 "parse-gram.c"
+#line 2577 "parse-gram.c"
       default: break;
     }
   YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);
@@ -2781,7 +2792,7 @@ yyreturn:
 
 
 /* Line 1486 of yacc.c  */
-#line 572 "parse-gram.y"
+#line 574 "parse-gram.y"
 
 
 
