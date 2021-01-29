@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 2.3+.  */
+/* A Bison parser, made by GNU Bison 2.3a.  */
 
 /* Skeleton implementation for Bison's Yacc-like parsers in C
 
@@ -47,7 +47,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "2.3+"
+#define YYBISON_VERSION "2.3a"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -55,6 +55,9 @@
 /* Pure parsers.  */
 #define YYPURE 1
 
+/* Push parsers.  */
+#define YYPUSH 0
+
 /* Using locations.  */
 #define YYLSP_NEEDED 1
 
@@ -210,25 +213,26 @@ static int current_prec = 0;
      PERCENT_OUTPUT = 291,
      PERCENT_PARSE_PARAM = 292,
      PERCENT_PURE_PARSER = 293,
-     PERCENT_REQUIRE = 294,
-     PERCENT_SKELETON = 295,
-     PERCENT_START = 296,
-     PERCENT_START_HEADER = 297,
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
+     PERCENT_PUSH_PARSER = 294,
+     PERCENT_REQUIRE = 295,
+     PERCENT_SKELETON = 296,
+     PERCENT_START = 297,
+     PERCENT_START_HEADER = 298,
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
@@ -269,25 +273,26 @@ static int current_prec = 0;
 #define PERCENT_OUTPUT 291
 #define PERCENT_PARSE_PARAM 292
 #define PERCENT_PURE_PARSER 293
-#define PERCENT_REQUIRE 294
-#define PERCENT_SKELETON 295
-#define PERCENT_START 296
-#define PERCENT_START_HEADER 297
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
+#define PERCENT_PUSH_PARSER 294
+#define PERCENT_REQUIRE 295
+#define PERCENT_SKELETON 296
+#define PERCENT_START 297
+#define PERCENT_START_HEADER 298
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
 
 
 
@@ -306,7 +311,7 @@ typedef union YYSTYPE
   unsigned char character;
 }
 /* Line 198 of yacc.c.  */
-#line 310 "parse-gram.c"
+#line 315 "parse-gram.c"
 	YYSTYPE;
 # define YYSTYPE_IS_TRIVIAL 1
 # define yystype YYSTYPE /* obsolescent; will be withdrawn */
@@ -330,7 +335,7 @@ typedef struct YYLTYPE
 /* Copy the second part of user declarations.  */
 
 /* Line 221 of yacc.c.  */
-#line 334 "parse-gram.c"
+#line 339 "parse-gram.c"
 
 #ifdef short
 # undef short
@@ -547,20 +552,20 @@ union yyalloc
 /* YYFINAL -- State number of the termination state.  */
 #define YYFINAL  3
 /* YYLAST -- Last index in YYTABLE.  */
-#define YYLAST   195
+#define YYLAST   185
 
 /* YYNTOKENS -- Number of terminals.  */
-#define YYNTOKENS  58
+#define YYNTOKENS  59
 /* YYNNTS -- Number of nonterminals.  */
 #define YYNNTS  31
 /* YYNRULES -- Number of rules.  */
-#define YYNRULES  97
+#define YYNRULES  98
 /* YYNRULES -- Number of states.  */
-#define YYNSTATES  136
+#define YYNSTATES  137
 
 /* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
 #define YYUNDEFTOK  2
-#define YYMAXUTOK   312
+#define YYMAXUTOK   313
 
 #define YYTRANSLATE(YYX)						\
   ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)
@@ -599,7 +604,7 @@ static const yytype_uint8 yytranslate[] =
       25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
       35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
       45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
-      55,    56,    57
+      55,    56,    57,    58
 };
 
 #if YYDEBUG
@@ -609,59 +614,59 @@ static const yytype_uint8 yyprhs[] =
 {
        0,     0,     3,     8,     9,    12,    14,    16,    19,    22,
       24,    28,    30,    33,    35,    38,    41,    45,    47,    50,
-      53,    55,    59,    61,    63,    67,    70,    72,    75,    78,
-      81,    83,    85,    87,    89,    91,    93,    96,   100,   104,
-     106,   108,   109,   111,   115,   116,   120,   121,   125,   129,
-     133,   135,   137,   139,   140,   142,   144,   147,   149,   152,
-     154,   156,   158,   160,   162,   165,   168,   172,   174,   177,
-     179,   182,   184,   187,   190,   191,   195,   197,   201,   204,
-     205,   208,   211,   215,   219,   223,   225,   227,   228,   230,
-     232,   234,   236,   238,   240,   242,   244,   245
+      53,    55,    59,    61,    63,    67,    70,    72,    74,    77,
+      80,    83,    85,    87,    89,    91,    93,    95,    98,   102,
+     106,   108,   110,   111,   113,   117,   118,   122,   123,   127,
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
-      83,    -1,    19,    -1,    21,     3,    82,    -1,    22,    -1,
-      23,    83,    -1,    24,    -1,    25,     4,    -1,    26,     4,
-      -1,    27,    49,     3,    -1,    28,    -1,    29,    46,    -1,
-      30,    46,    -1,    31,    -1,    32,    49,     3,    -1,    34,
-      -1,    35,    -1,    36,    49,     3,    -1,    37,    46,    -1,
-      38,    -1,    39,     3,    -1,    40,     3,    -1,    42,    83,
-      -1,    43,    -1,    44,    -1,    45,    -1,    55,    -1,    67,
-      -1,    64,    -1,    41,    86,    -1,     8,    46,    71,    -1,
-       9,    46,    71,    -1,    20,    -1,    33,    -1,    -1,    50,
-      -1,    57,    63,    46,    -1,    -1,     6,    65,    74,    -1,
-      -1,     5,    66,    74,    -1,     7,    56,    70,    -1,    68,
-      69,    70,    -1,    11,    -1,    12,    -1,    13,    -1,    -1,
-      56,    -1,    86,    -1,    70,    86,    -1,    72,    -1,    71,
-      72,    -1,    86,    -1,    56,    -1,    10,    -1,    56,    -1,
-      84,    -1,    84,     4,    -1,    84,    87,    -1,    84,     4,
-      87,    -1,    73,    -1,    74,    73,    -1,    76,    -1,    75,
-      76,    -1,    77,    -1,    62,    55,    -1,     1,    55,    -1,
-      -1,    85,    78,    79,    -1,    80,    -1,    79,    53,    80,
-      -1,    79,    55,    -1,    -1,    80,    86,    -1,    80,    46,
-      -1,    80,    14,    86,    -1,    80,    15,     4,    -1,    80,
-      16,    56,    -1,     3,    -1,    83,    -1,    -1,    81,    -1,
-      46,    -1,    50,    -1,    47,    -1,    51,    -1,    84,    -1,
-      87,    -1,     3,    -1,    -1,    52,    48,    -1
+      60,     0,    -1,    61,    53,    76,    89,    -1,    -1,    61,
+      62,    -1,    63,    -1,    55,    -1,    17,    84,    -1,    18,
+      84,    -1,    19,    -1,    21,     3,    83,    -1,    22,    -1,
+      23,    84,    -1,    24,    -1,    25,     4,    -1,    26,     4,
+      -1,    27,    50,     3,    -1,    28,    -1,    29,    47,    -1,
+      30,    47,    -1,    31,    -1,    32,    50,     3,    -1,    34,
+      -1,    35,    -1,    36,    50,     3,    -1,    37,    47,    -1,
+      38,    -1,    39,    -1,    40,     3,    -1,    41,     3,    -1,
+      43,    84,    -1,    44,    -1,    45,    -1,    46,    -1,    56,
+      -1,    68,    -1,    65,    -1,    42,    87,    -1,     8,    47,
+      72,    -1,     9,    47,    72,    -1,    20,    -1,    33,    -1,
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
-     227,   228,   229,   230,   231,   232,   233,   234,   239,   243,
-     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
-     254,   255,   256,   257,   261,   262,   263,   267,   275,   283,
-     287,   301,   302,   306,   334,   334,   339,   339,   344,   355,
-     370,   371,   372,   376,   377,   382,   384,   389,   390,   394,
-     395,   396,   401,   406,   411,   417,   423,   434,   435,   444,
-     445,   451,   452,   453,   460,   460,   464,   465,   466,   471,
-     472,   474,   476,   478,   480,   490,   491,   497,   501,   506,
-     522,   524,   533,   538,   539,   544,   551,   553
+       0,   209,   209,   217,   219,   223,   224,   225,   226,   227,
+     228,   229,   230,   231,   232,   233,   234,   235,   240,   244,
+     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
+     255,   256,   257,   258,   259,   263,   264,   265,   269,   277,
+     285,   289,   303,   304,   308,   336,   336,   341,   341,   346,
+     357,   372,   373,   374,   378,   379,   384,   386,   391,   392,
+     396,   397,   398,   403,   408,   413,   419,   425,   436,   437,
+     446,   447,   453,   454,   455,   462,   462,   466,   467,   468,
+     473,   474,   476,   478,   480,   482,   492,   493,   499,   503,
+     508,   524,   526,   535,   540,   541,   546,   553,   555
 };
 #endif
 
@@ -680,13 +685,14 @@ static const char *const yytname[] =
   "\"%file-prefix\"", "\"%glr-parser\"", "\"%initial-action\"",
   "\"%lex-param\"", "\"%locations\"", "\"%name-prefix\"",
   "\"%no-default-prec\"", "\"%no-lines\"", "\"%nondeterministic-parser\"",
-  "\"%output\"", "\"%parse-param\"", "\"%pure-parser\"", "\"%require\"",
-  "\"%skeleton\"", "\"%start\"", "\"%start-header\"", "\"%token-table\"",
-  "\"%verbose\"", "\"%yacc\"", "\"{...}\"", "\"char\"", "\"epilogue\"",
-  "\"=\"", "\"identifier\"", "\"identifier:\"", "\"%%\"", "\"|\"",
-  "\"%{...%}\"", "\";\"", "\"type\"", "\"%union\"", "$accept", "input",
-  "prologue_declarations", "prologue_declaration", "grammar_declaration",
-  "union_name", "symbol_declaration", "@1", "@2", "precedence_declaration",
+  "\"%output\"", "\"%parse-param\"", "\"%pure-parser\"",
+  "\"%push-parser\"", "\"%require\"", "\"%skeleton\"", "\"%start\"",
+  "\"%start-header\"", "\"%token-table\"", "\"%verbose\"", "\"%yacc\"",
+  "\"{...}\"", "\"char\"", "\"epilogue\"", "\"=\"", "\"identifier\"",
+  "\"identifier:\"", "\"%%\"", "\"|\"", "\"%{...%}\"", "\";\"", "\"type\"",
+  "\"%union\"", "$accept", "input", "prologue_declarations",
+  "prologue_declaration", "grammar_declaration", "union_name",
+  "symbol_declaration", "@1", "@2", "precedence_declaration",
   "precedence_declarator", "type.opt", "symbols.1", "generic_symlist",
   "generic_symlist_item", "symbol_def", "symbol_defs.1", "grammar",
   "rules_or_grammar_declaration", "rules", "@3", "rhses.1", "rhs",
@@ -705,23 +711,23 @@ static const yytype_uint16 yytoknum[] =
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
+      62,    62,    62,    62,    62,    63,    63,    63,    63,    63,
+      63,    63,    64,    64,    63,    66,    65,    67,    65,    65,
+      68,    69,    69,    69,    70,    70,    71,    71,    72,    72,
+      73,    73,    73,    74,    74,    74,    74,    74,    75,    75,
+      76,    76,    77,    77,    77,    79,    78,    80,    80,    80,
+      81,    81,    81,    81,    81,    81,    82,    82,    83,    83,
+      84,    85,    85,    86,    87,    87,    88,    89,    89
 };
 
 /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
@@ -729,14 +735,14 @@ static const yytype_uint8 yyr2[] =
 {
        0,     2,     4,     0,     2,     1,     1,     2,     2,     1,
        3,     1,     2,     1,     2,     2,     3,     1,     2,     2,
-       1,     3,     1,     1,     3,     2,     1,     2,     2,     2,
-       1,     1,     1,     1,     1,     1,     2,     3,     3,     1,
-       1,     0,     1,     3,     0,     3,     0,     3,     3,     3,
-       1,     1,     1,     0,     1,     1,     2,     1,     2,     1,
-       1,     1,     1,     1,     2,     2,     3,     1,     2,     1,
-       2,     1,     2,     2,     0,     3,     1,     3,     2,     0,
-       2,     2,     3,     3,     3,     1,     1,     0,     1,     1,
-       1,     1,     1,     1,     1,     1,     0,     2
+       1,     3,     1,     1,     3,     2,     1,     1,     2,     2,
+       2,     1,     1,     1,     1,     1,     1,     2,     3,     3,
+       1,     1,     0,     1,     3,     0,     3,     0,     3,     3,
+       3,     1,     1,     1,     0,     1,     1,     2,     1,     2,
+       1,     1,     1,     1,     1,     2,     2,     3,     1,     2,
+       1,     2,     1,     2,     2,     0,     3,     1,     3,     2,
+       0,     2,     2,     3,     3,     3,     1,     1,     0,     1,
+       1,     1,     1,     1,     1,     1,     1,     0,     2
 };
 
 /* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
@@ -744,132 +750,130 @@ static const yytype_uint8 yyr2[] =
    means the default is an error.  */
 static const yytype_uint8 yydefact[] =
 {
-       3,     0,     0,     1,    46,    44,     0,     0,     0,    50,
-      51,    52,     0,     0,     9,    39,     0,    11,     0,    13,
-       0,     0,     0,    17,     0,     0,    20,     0,    40,    22,
-      23,     0,     0,    26,     0,     0,     0,     0,    30,    31,
-      32,     0,     6,    33,    41,     4,     5,    35,    34,    53,
-       0,     0,     0,     0,     0,    89,     7,     8,    87,    12,
-      14,    15,     0,    18,    19,     0,     0,    25,    27,    28,
-      95,    91,    90,    93,    36,    94,    29,     0,    92,     0,
-       0,    69,    71,    74,    42,     0,    54,     0,    62,    67,
-      47,    63,    45,    48,    55,    61,    60,    37,    57,    59,
-      38,    85,    88,    10,    86,    16,    21,    24,    73,    72,
-       0,    70,     2,    79,    43,    49,    68,    64,    65,    56,
-      58,    97,    75,    76,    66,    79,    78,     0,     0,     0,
-      81,    80,    77,    82,    83,    84
+       3,     0,     0,     1,    47,    45,     0,     0,     0,    51,
+      52,    53,     0,     0,     9,    40,     0,    11,     0,    13,
+       0,     0,     0,    17,     0,     0,    20,     0,    41,    22,
+      23,     0,     0,    26,    27,     0,     0,     0,     0,    31,
+      32,    33,     0,     6,    34,    42,     4,     5,    36,    35,
+      54,     0,     0,     0,     0,     0,    90,     7,     8,    88,
+      12,    14,    15,     0,    18,    19,     0,     0,    25,    28,
+      29,    96,    92,    91,    94,    37,    95,    30,     0,    93,
+       0,     0,    70,    72,    75,    43,     0,    55,     0,    63,
+      68,    48,    64,    46,    49,    56,    62,    61,    38,    58,
+      60,    39,    86,    89,    10,    87,    16,    21,    24,    74,
+      73,     0,    71,     2,    80,    44,    50,    69,    65,    66,
+      57,    59,    98,    76,    77,    67,    80,    79,     0,     0,
+       0,    82,    81,    78,    83,    84,    85
 };
 
 /* YYDEFGOTO[NTERM-NUM].  */
 static const yytype_int8 yydefgoto[] =
 {
-      -1,     1,     2,    45,    79,    85,    47,    51,    50,    48,
-      49,    87,    93,    97,    98,    89,    90,    80,    81,    82,
-     113,   122,   123,   102,   103,    56,    73,    83,    99,    75,
-     112
+      -1,     1,     2,    46,    80,    86,    48,    52,    51,    49,
+      50,    88,    94,    98,    99,    90,    91,    81,    82,    83,
+     114,   123,   124,   103,   104,    57,    74,    84,   100,    76,
+     113
 };
 
 /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
    STATE-NUM.  */
-#define YYPACT_NINF -75
-static const yytype_int16 yypact[] =
+#define YYPACT_NINF -90
+static const yytype_int8 yypact[] =
 {
-     -75,    18,   101,   -75,   -75,   -75,   -21,   -20,   -10,   -75,
-     -75,   -75,    -8,    -8,   -75,   -75,    37,   -75,    -8,   -75,
-      41,    44,     6,   -75,    -5,     3,   -75,     7,   -75,   -75,
-     -75,    10,    16,   -75,    61,    67,     0,    -8,   -75,   -75,
-     -75,    60,   -75,   -75,    13,   -75,   -75,   -75,   -75,    19,
-     -28,   -28,     0,    27,    27,   -75,   -75,   -75,     8,   -75,
-     -75,   -75,    73,   -75,   -75,    75,    78,   -75,   -75,   -75,
-     -75,   -75,   -75,   -75,   -75,   -75,   -75,    30,   -75,    31,
-       1,   -75,   -75,   -75,   -75,    36,   -75,     0,   -75,   -75,
-     -28,    29,   -28,     0,   -75,   -75,   -75,    27,   -75,   -75,
-      27,   -75,   -75,   -75,   -75,   -75,   -75,   -75,   -75,   -75,
-      40,   -75,   -75,   -75,   -75,     0,   -75,    81,   -75,   -75,
-     -75,   -75,   -30,   145,   -75,   -75,   -75,     0,    85,    34,
-     -75,   -75,   145,   -75,   -75,   -75
+     -90,    23,    92,   -90,   -90,   -90,   -24,   -10,    -6,   -90,
+     -90,   -90,    -2,    -2,   -90,   -90,    47,   -90,    -2,   -90,
+      62,    64,    20,   -90,    25,    27,   -90,    26,   -90,   -90,
+     -90,    28,    35,   -90,   -90,    72,    80,    14,    -2,   -90,
+     -90,   -90,    19,   -90,   -90,    34,   -90,   -90,   -90,   -90,
+      29,    16,    16,    14,    12,    12,   -90,   -90,   -90,     8,
+     -90,   -90,   -90,    85,   -90,   -90,    86,    87,   -90,   -90,
+     -90,   -90,   -90,   -90,   -90,   -90,   -90,   -90,    36,   -90,
+      37,     1,   -90,   -90,   -90,   -90,    48,   -90,    14,   -90,
+     -90,    16,    15,    16,    14,   -90,   -90,   -90,    12,   -90,
+     -90,    12,   -90,   -90,   -90,   -90,   -90,   -90,   -90,   -90,
+     -90,    45,   -90,   -90,   -90,   -90,    14,   -90,    99,   -90,
+     -90,   -90,   -90,   -14,    33,   -90,   -90,   -90,    14,   102,
+      50,   -90,   -90,    33,   -90,   -90,   -90
 };
 
 /* YYPGOTO[NTERM-NUM].  */
 static const yytype_int8 yypgoto[] =
 {
-     -75,   -75,   -75,   -75,    90,   -75,   -75,   -75,   -75,   -75,
-     -75,   -75,    11,    43,   -73,   -61,    48,   -75,    14,   -75,
-     -75,   -75,   -25,   -75,   -75,     2,   -46,   -75,   -36,   -74,
-     -75
+     -90,   -90,   -90,   -90,   106,   -90,   -90,   -90,   -90,   -90,
+     -90,   -90,    52,    88,   -63,   -35,    89,   -90,    61,   -90,
+     -90,   -90,    30,   -90,   -90,   126,   -47,   -90,   -37,   -89,
+     -90
 };
 
 /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
    positive, shift that token.  If negative, reduce the rule which
    number is the opposite.  If zero, do what YYDEFACT says.
    If YYTABLE_NINF, syntax error.  */
-#define YYTABLE_NINF -97
+#define YYTABLE_NINF -98
 static const yytype_int16 yytable[] =
 {
-      74,   -96,    77,    70,    91,    91,     4,     5,     6,     7,
-       8,   101,     9,    10,    11,    57,    94,   118,     3,    71,
-      59,    15,    72,   125,   120,   126,    53,   120,    88,   116,
-      70,   116,    70,   117,    28,    52,    54,    95,    55,    76,
-      58,    63,    36,   124,    91,    60,    91,    71,    61,    64,
-      72,    94,    78,   110,    55,    62,    65,   119,    44,    66,
-     104,    77,    67,    84,    68,     4,     5,     6,     7,     8,
-      69,     9,    10,    11,    71,    86,   105,    72,   106,   119,
-      15,   107,   114,    96,    70,   108,   109,   131,   121,   134,
-     135,   133,    46,    28,   111,     0,   131,   100,   115,    92,
-     132,    36,     0,     0,     0,     0,     4,     5,     6,     7,
-       8,    78,     9,    10,    11,     0,     0,    44,    12,    13,
-      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
-      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
-      34,    35,    36,    37,    38,    39,    40,     0,    70,     0,
-       0,     0,     0,    41,     0,    42,    43,     0,    44,   127,
-     128,   129,     0,     0,     0,     0,     0,     0,     0,     0,
-       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
+      75,   -97,    78,   119,    92,    92,     4,     5,     6,     7,
+       8,   102,     9,    10,    11,    71,    95,    71,    71,   118,
+      78,    15,    96,     3,     4,     5,     6,     7,     8,   125,
+       9,    10,    11,    53,    28,   121,    71,    54,   121,    15,
+     126,    55,   127,    37,    92,    56,    92,   128,   129,   130,
+      59,    95,    28,    79,   111,    56,   117,   120,   117,    45,
+      72,    37,    72,    73,    72,    73,    61,    73,    62,    97,
+      63,    79,    64,    89,    65,    69,    66,    45,    67,   120,
+     131,    72,    68,    70,    73,    85,    87,   132,   106,   107,
+     108,   134,   109,   110,   122,   115,   132,     4,     5,     6,
+       7,     8,    71,     9,    10,    11,   135,   136,    47,    12,
+      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
+      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
+      33,    34,    35,    36,    37,    38,    39,    40,    41,    58,
+     116,    93,   112,   101,    60,    42,     0,    43,    44,     0,
+      45,     0,     0,     0,     0,     0,   133,     0,     0,     0,
+       0,     0,     0,     0,    77,     0,     0,     0,     0,     0,
        0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
-       0,   130,    71,     0,     0,    72
+       0,     0,     0,     0,     0,   105
 };
 
 static const yytype_int16 yycheck[] =
 {
-      36,     0,     1,     3,    50,    51,     5,     6,     7,     8,
-       9,     3,    11,    12,    13,    13,    52,    91,     0,    47,
-      18,    20,    50,    53,    97,    55,    46,   100,    56,    90,
-       3,    92,     3,     4,    33,    56,    46,    10,    46,    37,
-       3,    46,    41,   117,    90,     4,    92,    47,     4,    46,
-      50,    87,    51,    52,    46,    49,    49,    93,    57,    49,
-      58,     1,    46,    50,     3,     5,     6,     7,     8,     9,
-       3,    11,    12,    13,    47,    56,     3,    50,     3,   115,
-      20,     3,    46,    56,     3,    55,    55,   123,    48,     4,
-      56,   127,     2,    33,    80,    -1,   132,    54,    87,    51,
-     125,    41,    -1,    -1,    -1,    -1,     5,     6,     7,     8,
-       9,    51,    11,    12,    13,    -1,    -1,    57,    17,    18,
-      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
-      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
-      39,    40,    41,    42,    43,    44,    45,    -1,     3,    -1,
-      -1,    -1,    -1,    52,    -1,    54,    55,    -1,    57,    14,
-      15,    16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
-      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
+      37,     0,     1,    92,    51,    52,     5,     6,     7,     8,
+       9,     3,    11,    12,    13,     3,    53,     3,     3,     4,
+       1,    20,    10,     0,     5,     6,     7,     8,     9,   118,
+      11,    12,    13,    57,    33,    98,     3,    47,   101,    20,
+      54,    47,    56,    42,    91,    47,    93,    14,    15,    16,
+       3,    88,    33,    52,    53,    47,    91,    94,    93,    58,
+      48,    42,    48,    51,    48,    51,     4,    51,     4,    57,
+      50,    52,    47,    57,    47,     3,    50,    58,    50,   116,
+      47,    48,    47,     3,    51,    51,    57,   124,     3,     3,
+       3,   128,    56,    56,    49,    47,   133,     5,     6,     7,
+       8,     9,     3,    11,    12,    13,     4,    57,     2,    17,
+      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
+      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
+      38,    39,    40,    41,    42,    43,    44,    45,    46,    13,
+      88,    52,    81,    55,    18,    53,    -1,    55,    56,    -1,
+      58,    -1,    -1,    -1,    -1,    -1,   126,    -1,    -1,    -1,
+      -1,    -1,    -1,    -1,    38,    -1,    -1,    -1,    -1,    -1,
       -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
-      -1,    46,    47,    -1,    -1,    50
+      -1,    -1,    -1,    -1,    -1,    59
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
-      66,    65,    56,    46,    46,    46,    83,    83,     3,    83,
-       4,     4,    49,    46,    46,    49,    49,    46,     3,     3,
-       3,    47,    50,    84,    86,    87,    83,     1,    51,    62,
-      75,    76,    77,    85,    50,    63,    56,    69,    56,    73,
-      74,    84,    74,    70,    86,    10,    56,    71,    72,    86,
-      71,     3,    81,    82,    83,     3,     3,     3,    55,    55,
-      52,    76,    88,    78,    46,    70,    73,     4,    87,    86,
-      72,    48,    79,    80,    87,    53,    55,    14,    15,    16,
-      46,    86,    80,    86,     4,    56
+      45,    46,    53,    55,    56,    58,    62,    63,    65,    68,
+      69,    67,    66,    57,    47,    47,    47,    84,    84,     3,
+      84,     4,     4,    50,    47,    47,    50,    50,    47,     3,
+       3,     3,    48,    51,    85,    87,    88,    84,     1,    52,
+      63,    76,    77,    78,    86,    51,    64,    57,    70,    57,
+      74,    75,    85,    75,    71,    87,    10,    57,    72,    73,
+      87,    72,     3,    82,    83,    84,     3,     3,     3,    56,
+      56,    53,    77,    89,    79,    47,    71,    74,     4,    88,
+      87,    73,    49,    80,    81,    88,    54,    56,    14,    15,
+      16,    47,    87,    81,    87,     4,    57
 };
 
 #define yyerrok		(yyerrstatus = 0)
@@ -1019,115 +1023,115 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
     {
       case 3: /* "\"string\"" */
 /* Line 670 of yacc.c.  */
-#line 186 "parse-gram.y"
+#line 187 "parse-gram.y"
 	{ fputs (quotearg_style (c_quoting_style, (yyvaluep->chars)), stderr); };
 /* Line 670 of yacc.c.  */
-#line 1026 "parse-gram.c"
+#line 1030 "parse-gram.c"
 	break;
       case 4: /* "\"integer\"" */
 /* Line 670 of yacc.c.  */
-#line 197 "parse-gram.y"
+#line 198 "parse-gram.y"
 	{ fprintf (stderr, "%d", (yyvaluep->integer)); };
 /* Line 670 of yacc.c.  */
-#line 1033 "parse-gram.c"
+#line 1037 "parse-gram.c"
 	break;
-      case 46: /* "\"{...}\"" */
+      case 47: /* "\"{...}\"" */
 /* Line 670 of yacc.c.  */
-#line 188 "parse-gram.y"
+#line 189 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 /* Line 670 of yacc.c.  */
-#line 1040 "parse-gram.c"
+#line 1044 "parse-gram.c"
 	break;
-      case 47: /* "\"char\"" */
+      case 48: /* "\"char\"" */
 /* Line 670 of yacc.c.  */
-#line 181 "parse-gram.y"
+#line 182 "parse-gram.y"
 	{ fputs (char_name ((yyvaluep->character)), stderr); };
 /* Line 670 of yacc.c.  */
-#line 1047 "parse-gram.c"
+#line 1051 "parse-gram.c"
 	break;
-      case 48: /* "\"epilogue\"" */
+      case 49: /* "\"epilogue\"" */
 /* Line 670 of yacc.c.  */
-#line 188 "parse-gram.y"
+#line 189 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 /* Line 670 of yacc.c.  */
-#line 1054 "parse-gram.c"
+#line 1058 "parse-gram.c"
 	break;
-      case 50: /* "\"identifier\"" */
+      case 51: /* "\"identifier\"" */
 /* Line 670 of yacc.c.  */
-#line 193 "parse-gram.y"
+#line 194 "parse-gram.y"
 	{ fputs ((yyvaluep->uniqstr), stderr); };
 /* Line 670 of yacc.c.  */
-#line 1061 "parse-gram.c"
+#line 1065 "parse-gram.c"
 	break;
-      case 51: /* "\"identifier:\"" */
+      case 52: /* "\"identifier:\"" */
 /* Line 670 of yacc.c.  */
-#line 194 "parse-gram.y"
+#line 195 "parse-gram.y"
 	{ fprintf (stderr, "%s:", (yyvaluep->uniqstr)); };
 /* Line 670 of yacc.c.  */
-#line 1068 "parse-gram.c"
+#line 1072 "parse-gram.c"
 	break;
-      case 54: /* "\"%{...%}\"" */
+      case 55: /* "\"%{...%}\"" */
 /* Line 670 of yacc.c.  */
-#line 188 "parse-gram.y"
+#line 189 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 /* Line 670 of yacc.c.  */
-#line 1075 "parse-gram.c"
+#line 1079 "parse-gram.c"
 	break;
-      case 56: /* "\"type\"" */
+      case 57: /* "\"type\"" */
 /* Line 670 of yacc.c.  */
-#line 192 "parse-gram.y"
+#line 193 "parse-gram.y"
 	{ fprintf (stderr, "<%s>", (yyvaluep->uniqstr)); };
 /* Line 670 of yacc.c.  */
-#line 1082 "parse-gram.c"
+#line 1086 "parse-gram.c"
 	break;
-      case 81: /* "content" */
+      case 82: /* "content" */
 /* Line 670 of yacc.c.  */
-#line 188 "parse-gram.y"
+#line 189 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 /* Line 670 of yacc.c.  */
-#line 1089 "parse-gram.c"
+#line 1093 "parse-gram.c"
 	break;
-      case 82: /* "content.opt" */
+      case 83: /* "content.opt" */
 /* Line 670 of yacc.c.  */
-#line 188 "parse-gram.y"
+#line 189 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 /* Line 670 of yacc.c.  */
-#line 1096 "parse-gram.c"
+#line 1100 "parse-gram.c"
 	break;
-      case 83: /* "braceless" */
+      case 84: /* "braceless" */
 /* Line 670 of yacc.c.  */
-#line 188 "parse-gram.y"
+#line 189 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 /* Line 670 of yacc.c.  */
-#line 1103 "parse-gram.c"
+#line 1107 "parse-gram.c"
 	break;
-      case 84: /* "id" */
+      case 85: /* "id" */
 /* Line 670 of yacc.c.  */
-#line 200 "parse-gram.y"
+#line 201 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 /* Line 670 of yacc.c.  */
-#line 1110 "parse-gram.c"
+#line 1114 "parse-gram.c"
 	break;
-      case 85: /* "id_colon" */
+      case 86: /* "id_colon" */
 /* Line 670 of yacc.c.  */
-#line 201 "parse-gram.y"
+#line 202 "parse-gram.y"
 	{ fprintf (stderr, "%s:", (yyvaluep->symbol)->tag); };
 /* Line 670 of yacc.c.  */
-#line 1117 "parse-gram.c"
+#line 1121 "parse-gram.c"
 	break;
-      case 86: /* "symbol" */
+      case 87: /* "symbol" */
 /* Line 670 of yacc.c.  */
-#line 200 "parse-gram.y"
+#line 201 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 /* Line 670 of yacc.c.  */
-#line 1124 "parse-gram.c"
+#line 1128 "parse-gram.c"
 	break;
-      case 87: /* "string_as_id" */
+      case 88: /* "string_as_id" */
 /* Line 670 of yacc.c.  */
-#line 200 "parse-gram.y"
+#line 201 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 /* Line 670 of yacc.c.  */
-#line 1131 "parse-gram.c"
+#line 1135 "parse-gram.c"
 	break;
       default:
 	break;
@@ -1649,7 +1653,7 @@ YYLTYPE yylloc;
   boundary_set (&yylloc.end, current_file, 1, 1);
 }
 /* Line 1082 of yacc.c.  */
-#line 1653 "parse-gram.c"
+#line 1657 "parse-gram.c"
   yylsp[0] = yylloc;
   goto yysetstate;
 
@@ -1834,73 +1838,73 @@ yyreduce:
     {
         case 6:
 /* Line 1269 of yacc.c.  */
-#line 223 "parse-gram.y"
+#line 224 "parse-gram.y"
     { prologue_augment (translate_code ((yyvsp[(1) - (1)].chars), (yylsp[(1) - (1)])), (yylsp[(1) - (1)]), union_seen); }
     break;
 
   case 7:
 /* Line 1269 of yacc.c.  */
-#line 224 "parse-gram.y"
+#line 225 "parse-gram.y"
     { prologue_augment ((yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)]), true); }
     break;
 
   case 8:
 /* Line 1269 of yacc.c.  */
-#line 225 "parse-gram.y"
+#line 226 "parse-gram.y"
     { prologue_augment ((yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)]), false); }
     break;
 
   case 9:
 /* Line 1269 of yacc.c.  */
-#line 226 "parse-gram.y"
+#line 227 "parse-gram.y"
     { debug_flag = true; }
     break;
 
   case 10:
 /* Line 1269 of yacc.c.  */
-#line 227 "parse-gram.y"
+#line 228 "parse-gram.y"
     { muscle_insert ((yyvsp[(2) - (3)].chars), (yyvsp[(3) - (3)].chars)); }
     break;
 
   case 11:
 /* Line 1269 of yacc.c.  */
-#line 228 "parse-gram.y"
+#line 229 "parse-gram.y"
     { defines_flag = true; }
     break;
 
   case 12:
 /* Line 1269 of yacc.c.  */
-#line 229 "parse-gram.y"
+#line 230 "parse-gram.y"
     { muscle_code_grow ("end_header", (yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])); }
     break;
 
   case 13:
 /* Line 1269 of yacc.c.  */
-#line 230 "parse-gram.y"
+#line 231 "parse-gram.y"
     { error_verbose = true; }
     break;
 
   case 14:
 /* Line 1269 of yacc.c.  */
-#line 231 "parse-gram.y"
+#line 232 "parse-gram.y"
     { expected_sr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 15:
 /* Line 1269 of yacc.c.  */
-#line 232 "parse-gram.y"
+#line 233 "parse-gram.y"
     { expected_rr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 16:
 /* Line 1269 of yacc.c.  */
-#line 233 "parse-gram.y"
+#line 234 "parse-gram.y"
     { spec_file_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 17:
 /* Line 1269 of yacc.c.  */
-#line 235 "parse-gram.y"
+#line 236 "parse-gram.y"
     {
       nondeterministic_parser = true;
       glr_parser = true;
@@ -1909,7 +1913,7 @@ yyreduce:
 
   case 18:
 /* Line 1269 of yacc.c.  */
-#line 240 "parse-gram.y"
+#line 241 "parse-gram.y"
     {
       muscle_code_grow ("initial_action", translate_symbol_action ((yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])), (yylsp[(2) - (2)]));
     }
@@ -1917,99 +1921,105 @@ yyreduce:
 
   case 19:
 /* Line 1269 of yacc.c.  */
-#line 243 "parse-gram.y"
+#line 244 "parse-gram.y"
     { add_param ("lex_param", (yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])); }
     break;
 
   case 20:
 /* Line 1269 of yacc.c.  */
-#line 244 "parse-gram.y"
+#line 245 "parse-gram.y"
     { locations_flag = true; }
     break;
 
   case 21:
 /* Line 1269 of yacc.c.  */
-#line 245 "parse-gram.y"
+#line 246 "parse-gram.y"
     { spec_name_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 22:
 /* Line 1269 of yacc.c.  */
-#line 246 "parse-gram.y"
+#line 247 "parse-gram.y"
     { no_lines_flag = true; }
     break;
 
   case 23:
 /* Line 1269 of yacc.c.  */
-#line 247 "parse-gram.y"
+#line 248 "parse-gram.y"
     { nondeterministic_parser = true; }
     break;
 
   case 24:
 /* Line 1269 of yacc.c.  */
-#line 248 "parse-gram.y"
+#line 249 "parse-gram.y"
     { spec_outfile = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 25:
 /* Line 1269 of yacc.c.  */
-#line 249 "parse-gram.y"
+#line 250 "parse-gram.y"
     { add_param ("parse_param", (yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])); }
     break;
 
   case 26:
 /* Line 1269 of yacc.c.  */
-#line 250 "parse-gram.y"
+#line 251 "parse-gram.y"
     { pure_parser = true; }
     break;
 
   case 27:
 /* Line 1269 of yacc.c.  */
-#line 251 "parse-gram.y"
-    { version_check (&(yylsp[(2) - (2)]), (yyvsp[(2) - (2)].chars)); }
+#line 252 "parse-gram.y"
+    { push_parser = true; }
     break;
 
   case 28:
 /* Line 1269 of yacc.c.  */
-#line 252 "parse-gram.y"
-    { skeleton = (yyvsp[(2) - (2)].chars); }
+#line 253 "parse-gram.y"
+    { version_check (&(yylsp[(2) - (2)]), (yyvsp[(2) - (2)].chars)); }
     break;
 
   case 29:
 /* Line 1269 of yacc.c.  */
-#line 253 "parse-gram.y"
-    { muscle_code_grow ("start_header", (yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])); }
+#line 254 "parse-gram.y"
+    { skeleton = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 30:
 /* Line 1269 of yacc.c.  */
-#line 254 "parse-gram.y"
-    { token_table_flag = true; }
+#line 255 "parse-gram.y"
+    { muscle_code_grow ("start_header", (yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])); }
     break;
 
   case 31:
 /* Line 1269 of yacc.c.  */
-#line 255 "parse-gram.y"
-    { report_flag = report_states; }
+#line 256 "parse-gram.y"
+    { token_table_flag = true; }
     break;
 
   case 32:
 /* Line 1269 of yacc.c.  */
-#line 256 "parse-gram.y"
+#line 257 "parse-gram.y"
+    { report_flag = report_states; }
+    break;
+
+  case 33:
+/* Line 1269 of yacc.c.  */
+#line 258 "parse-gram.y"
     { yacc_flag = true; }
     break;
 
-  case 36:
+  case 37:
 /* Line 1269 of yacc.c.  */
-#line 264 "parse-gram.y"
+#line 266 "parse-gram.y"
     {
       grammar_start_symbol_set ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]));
     }
     break;
 
-  case 37:
+  case 38:
 /* Line 1269 of yacc.c.  */
-#line 268 "parse-gram.y"
+#line 270 "parse-gram.y"
     {
       symbol_list *list;
       const char *action = translate_symbol_action ((yyvsp[(2) - (3)].chars), (yylsp[(2) - (3)]));
@@ -2019,9 +2029,9 @@ yyreduce:
     }
     break;
 
-  case 38:
+  case 39:
 /* Line 1269 of yacc.c.  */
-#line 276 "parse-gram.y"
+#line 278 "parse-gram.y"
     {
       symbol_list *list;
       const char *action = translate_symbol_action ((yyvsp[(2) - (3)].chars), (yylsp[(2) - (3)]));
@@ -2031,37 +2041,37 @@ yyreduce:
     }
     break;
 
-  case 39:
+  case 40:
 /* Line 1269 of yacc.c.  */
-#line 284 "parse-gram.y"
+#line 286 "parse-gram.y"
     {
       default_prec = true;
     }
     break;
 
-  case 40:
+  case 41:
 /* Line 1269 of yacc.c.  */
-#line 288 "parse-gram.y"
+#line 290 "parse-gram.y"
     {
       default_prec = false;
     }
     break;
 
-  case 41:
+  case 42:
 /* Line 1269 of yacc.c.  */
-#line 301 "parse-gram.y"
+#line 303 "parse-gram.y"
     {}
     break;
 
-  case 42:
+  case 43:
 /* Line 1269 of yacc.c.  */
-#line 302 "parse-gram.y"
+#line 304 "parse-gram.y"
     { muscle_code_grow ("union_name", (yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
-  case 43:
+  case 44:
 /* Line 1269 of yacc.c.  */
-#line 307 "parse-gram.y"
+#line 309 "parse-gram.y"
     {
       char const *body = (yyvsp[(3) - (3)].chars);
 
@@ -2085,39 +2095,39 @@ yyreduce:
     }
     break;
 
-  case 44:
+  case 45:
 /* Line 1269 of yacc.c.  */
-#line 334 "parse-gram.y"
+#line 336 "parse-gram.y"
     { current_class = nterm_sym; }
     break;
 
-  case 45:
+  case 46:
 /* Line 1269 of yacc.c.  */
-#line 335 "parse-gram.y"
+#line 337 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
     break;
 
-  case 46:
+  case 47:
 /* Line 1269 of yacc.c.  */
-#line 339 "parse-gram.y"
+#line 341 "parse-gram.y"
     { current_class = token_sym; }
     break;
 
-  case 47:
+  case 48:
 /* Line 1269 of yacc.c.  */
-#line 340 "parse-gram.y"
+#line 342 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
     break;
 
-  case 48:
+  case 49:
 /* Line 1269 of yacc.c.  */
-#line 345 "parse-gram.y"
+#line 347 "parse-gram.y"
     {
       tag_seen = true;
       symbol_list *list;
@@ -2127,9 +2137,9 @@ yyreduce:
     }
     break;
 
-  case 49:
+  case 50:
 /* Line 1269 of yacc.c.  */
-#line 356 "parse-gram.y"
+#line 358 "parse-gram.y"
     {
       symbol_list *list;
       ++current_prec;
@@ -2143,99 +2153,99 @@ yyreduce:
     }
     break;
 
-  case 50:
+  case 51:
 /* Line 1269 of yacc.c.  */
-#line 370 "parse-gram.y"
+#line 372 "parse-gram.y"
     { (yyval.assoc) = left_assoc; }
     break;
 
-  case 51:
+  case 52:
 /* Line 1269 of yacc.c.  */
-#line 371 "parse-gram.y"
+#line 373 "parse-gram.y"
     { (yyval.assoc) = right_assoc; }
     break;
 
-  case 52:
+  case 53:
 /* Line 1269 of yacc.c.  */
-#line 372 "parse-gram.y"
+#line 374 "parse-gram.y"
     { (yyval.assoc) = non_assoc; }
     break;
 
-  case 53:
+  case 54:
 /* Line 1269 of yacc.c.  */
-#line 376 "parse-gram.y"
+#line 378 "parse-gram.y"
     { current_type = NULL; }
     break;
 
-  case 54:
+  case 55:
 /* Line 1269 of yacc.c.  */
-#line 377 "parse-gram.y"
+#line 379 "parse-gram.y"
     { current_type = (yyvsp[(1) - (1)].uniqstr); tag_seen = true; }
     break;
 
-  case 55:
+  case 56:
 /* Line 1269 of yacc.c.  */
-#line 383 "parse-gram.y"
+#line 385 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
-  case 56:
+  case 57:
 /* Line 1269 of yacc.c.  */
-#line 385 "parse-gram.y"
+#line 387 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), symbol_list_sym_new ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]))); }
     break;
 
-  case 57:
+  case 58:
 /* Line 1269 of yacc.c.  */
-#line 389 "parse-gram.y"
+#line 391 "parse-gram.y"
     { (yyval.list) = (yyvsp[(1) - (1)].list); }
     break;
 
-  case 58:
+  case 59:
 /* Line 1269 of yacc.c.  */
-#line 390 "parse-gram.y"
+#line 392 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), (yyvsp[(2) - (2)].list)); }
     break;
 
-  case 59:
+  case 60:
 /* Line 1269 of yacc.c.  */
-#line 394 "parse-gram.y"
+#line 396 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
-  case 60:
+  case 61:
 /* Line 1269 of yacc.c.  */
-#line 395 "parse-gram.y"
+#line 397 "parse-gram.y"
     { (yyval.list) = symbol_list_type_new ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
-  case 61:
+  case 62:
 /* Line 1269 of yacc.c.  */
-#line 396 "parse-gram.y"
+#line 398 "parse-gram.y"
     { (yyval.list) = symbol_list_default_new ((yylsp[(1) - (1)])); }
     break;
 
-  case 62:
+  case 63:
 /* Line 1269 of yacc.c.  */
-#line 402 "parse-gram.y"
+#line 404 "parse-gram.y"
     {
        current_type = (yyvsp[(1) - (1)].uniqstr);
        tag_seen = true;
      }
     break;
 
-  case 63:
+  case 64:
 /* Line 1269 of yacc.c.  */
-#line 407 "parse-gram.y"
+#line 409 "parse-gram.y"
     {
        symbol_class_set ((yyvsp[(1) - (1)].symbol), current_class, (yylsp[(1) - (1)]), true);
        symbol_type_set ((yyvsp[(1) - (1)].symbol), current_type, (yylsp[(1) - (1)]));
      }
     break;
 
-  case 64:
+  case 65:
 /* Line 1269 of yacc.c.  */
-#line 412 "parse-gram.y"
+#line 414 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
       symbol_type_set ((yyvsp[(1) - (2)].symbol), current_type, (yylsp[(1) - (2)]));
@@ -2243,9 +2253,9 @@ yyreduce:
     }
     break;
 
-  case 65:
+  case 66:
 /* Line 1269 of yacc.c.  */
-#line 418 "parse-gram.y"
+#line 420 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
       symbol_type_set ((yyvsp[(1) - (2)].symbol), current_type, (yylsp[(1) - (2)]));
@@ -2253,9 +2263,9 @@ yyreduce:
     }
     break;
 
-  case 66:
+  case 67:
 /* Line 1269 of yacc.c.  */
-#line 424 "parse-gram.y"
+#line 426 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (3)].symbol), current_class, (yylsp[(1) - (3)]), true);
       symbol_type_set ((yyvsp[(1) - (3)].symbol), current_type, (yylsp[(1) - (3)]));
@@ -2264,95 +2274,95 @@ yyreduce:
     }
     break;
 
-  case 73:
+  case 74:
 /* Line 1269 of yacc.c.  */
-#line 454 "parse-gram.y"
+#line 456 "parse-gram.y"
     {
       yyerrok;
     }
     break;
 
-  case 74:
+  case 75:
 /* Line 1269 of yacc.c.  */
-#line 460 "parse-gram.y"
+#line 462 "parse-gram.y"
     { current_lhs = (yyvsp[(1) - (1)].symbol); current_lhs_location = (yylsp[(1) - (1)]); }
     break;
 
-  case 76:
+  case 77:
 /* Line 1269 of yacc.c.  */
-#line 464 "parse-gram.y"
+#line 466 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(1) - (1)])); }
     break;
 
-  case 77:
+  case 78:
 /* Line 1269 of yacc.c.  */
-#line 465 "parse-gram.y"
+#line 467 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(3) - (3)])); }
     break;
 
-  case 79:
-/* Line 1269 of yacc.c.  */
-#line 471 "parse-gram.y"
-    { grammar_current_rule_begin (current_lhs, current_lhs_location); }
-    break;
-
   case 80:
 /* Line 1269 of yacc.c.  */
 #line 473 "parse-gram.y"
-    { grammar_current_rule_symbol_append ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)])); }
+    { grammar_current_rule_begin (current_lhs, current_lhs_location); }
     break;
 
   case 81:
 /* Line 1269 of yacc.c.  */
 #line 475 "parse-gram.y"
-    { grammar_current_rule_action_append ((yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])); }
+    { grammar_current_rule_symbol_append ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)])); }
     break;
 
   case 82:
 /* Line 1269 of yacc.c.  */
 #line 477 "parse-gram.y"
-    { grammar_current_rule_prec_set ((yyvsp[(3) - (3)].symbol), (yylsp[(3) - (3)])); }
+    { grammar_current_rule_action_append ((yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])); }
     break;
 
   case 83:
 /* Line 1269 of yacc.c.  */
 #line 479 "parse-gram.y"
-    { grammar_current_rule_dprec_set ((yyvsp[(3) - (3)].integer), (yylsp[(3) - (3)])); }
+    { grammar_current_rule_prec_set ((yyvsp[(3) - (3)].symbol), (yylsp[(3) - (3)])); }
     break;
 
   case 84:
 /* Line 1269 of yacc.c.  */
 #line 481 "parse-gram.y"
+    { grammar_current_rule_dprec_set ((yyvsp[(3) - (3)].integer), (yylsp[(3) - (3)])); }
+    break;
+
+  case 85:
+/* Line 1269 of yacc.c.  */
+#line 483 "parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[(3) - (3)].uniqstr), (yylsp[(3) - (3)])); }
     break;
 
-  case 87:
+  case 88:
 /* Line 1269 of yacc.c.  */
-#line 497 "parse-gram.y"
+#line 499 "parse-gram.y"
     {
       static char one[] = "1";
       (yyval.chars) = one;
     }
     break;
 
-  case 89:
+  case 90:
 /* Line 1269 of yacc.c.  */
-#line 507 "parse-gram.y"
+#line 509 "parse-gram.y"
     {
       (yyvsp[(1) - (1)].chars)[strlen ((yyvsp[(1) - (1)].chars)) - 1] = '\n';
       (yyval.chars) = translate_code ((yyvsp[(1) - (1)].chars) + 1, (yylsp[(1) - (1)]));
     }
     break;
 
-  case 90:
+  case 91:
 /* Line 1269 of yacc.c.  */
-#line 523 "parse-gram.y"
+#line 525 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
-  case 91:
+  case 92:
 /* Line 1269 of yacc.c.  */
-#line 525 "parse-gram.y"
+#line 527 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[(1) - (1)].character)), (yylsp[(1) - (1)]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[(1) - (1)]), false);
@@ -2360,24 +2370,24 @@ yyreduce:
     }
     break;
 
-  case 92:
+  case 93:
 /* Line 1269 of yacc.c.  */
-#line 533 "parse-gram.y"
+#line 535 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
-  case 95:
+  case 96:
 /* Line 1269 of yacc.c.  */
-#line 545 "parse-gram.y"
+#line 547 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[(1) - (1)].chars)), (yylsp[(1) - (1)]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[(1) - (1)]), false);
     }
     break;
 
-  case 97:
+  case 98:
 /* Line 1269 of yacc.c.  */
-#line 554 "parse-gram.y"
+#line 556 "parse-gram.y"
     {
       muscle_code_grow ("epilogue", translate_code ((yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])), (yylsp[(2) - (2)]));
       gram_scanner_last_string_free ();
@@ -2386,7 +2396,7 @@ yyreduce:
 
 
 /* Line 1269 of yacc.c.  */
-#line 2390 "parse-gram.c"
+#line 2400 "parse-gram.c"
       default: break;
     }
   YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);
@@ -2604,7 +2614,7 @@ yyreturn:
 
 
 /* Line 1486 of yacc.c.  */
-#line 560 "parse-gram.y"
+#line 562 "parse-gram.y"
 
 
 
