@@ -181,53 +181,54 @@ static int current_prec = 0;
      PERCENT_TYPE = 262,
      PERCENT_DESTRUCTOR = 263,
      PERCENT_PRINTER = 264,
-     PERCENT_LEFT = 265,
-     PERCENT_RIGHT = 266,
-     PERCENT_NONASSOC = 267,
-     PERCENT_PREC = 268,
-     PERCENT_DPREC = 269,
-     PERCENT_MERGE = 270,
-     PERCENT_AFTER_HEADER = 271,
-     PERCENT_BEFORE_HEADER = 272,
-     PERCENT_DEBUG = 273,
-     PERCENT_DEFAULT_PREC = 274,
-     PERCENT_DEFINE = 275,
-     PERCENT_DEFINES = 276,
-     PERCENT_END_HEADER = 277,
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
-     PERCENT_PURE_PARSER = 292,
-     PERCENT_REQUIRE = 293,
-     PERCENT_SKELETON = 294,
-     PERCENT_START = 295,
-     PERCENT_START_HEADER = 296,
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
-     PERCENT_UNION = 311
+     PERCENT_SYMBOL_DEFAULT = 265,
+     PERCENT_LEFT = 266,
+     PERCENT_RIGHT = 267,
+     PERCENT_NONASSOC = 268,
+     PERCENT_PREC = 269,
+     PERCENT_DPREC = 270,
+     PERCENT_MERGE = 271,
+     PERCENT_AFTER_HEADER = 272,
+     PERCENT_BEFORE_HEADER = 273,
+     PERCENT_DEBUG = 274,
+     PERCENT_DEFAULT_PREC = 275,
+     PERCENT_DEFINE = 276,
+     PERCENT_DEFINES = 277,
+     PERCENT_END_HEADER = 278,
+     PERCENT_ERROR_VERBOSE = 279,
+     PERCENT_EXPECT = 280,
+     PERCENT_EXPECT_RR = 281,
+     PERCENT_FILE_PREFIX = 282,
+     PERCENT_GLR_PARSER = 283,
+     PERCENT_INITIAL_ACTION = 284,
+     PERCENT_LEX_PARAM = 285,
+     PERCENT_LOCATIONS = 286,
+     PERCENT_NAME_PREFIX = 287,
+     PERCENT_NO_DEFAULT_PREC = 288,
+     PERCENT_NO_LINES = 289,
+     PERCENT_NONDETERMINISTIC_PARSER = 290,
+     PERCENT_OUTPUT = 291,
+     PERCENT_PARSE_PARAM = 292,
+     PERCENT_PURE_PARSER = 293,
+     PERCENT_REQUIRE = 294,
+     PERCENT_SKELETON = 295,
+     PERCENT_START = 296,
+     PERCENT_START_HEADER = 297,
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
+     PERCENT_UNION = 312
    };
 #endif
 /* Tokens.  */
@@ -239,53 +240,54 @@ static int current_prec = 0;
 #define PERCENT_TYPE 262
 #define PERCENT_DESTRUCTOR 263
 #define PERCENT_PRINTER 264
-#define PERCENT_LEFT 265
-#define PERCENT_RIGHT 266
-#define PERCENT_NONASSOC 267
-#define PERCENT_PREC 268
-#define PERCENT_DPREC 269
-#define PERCENT_MERGE 270
-#define PERCENT_AFTER_HEADER 271
-#define PERCENT_BEFORE_HEADER 272
-#define PERCENT_DEBUG 273
-#define PERCENT_DEFAULT_PREC 274
-#define PERCENT_DEFINE 275
-#define PERCENT_DEFINES 276
-#define PERCENT_END_HEADER 277
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
-#define PERCENT_PURE_PARSER 292
-#define PERCENT_REQUIRE 293
-#define PERCENT_SKELETON 294
-#define PERCENT_START 295
-#define PERCENT_START_HEADER 296
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
-#define PERCENT_UNION 311
+#define PERCENT_SYMBOL_DEFAULT 265
+#define PERCENT_LEFT 266
+#define PERCENT_RIGHT 267
+#define PERCENT_NONASSOC 268
+#define PERCENT_PREC 269
+#define PERCENT_DPREC 270
+#define PERCENT_MERGE 271
+#define PERCENT_AFTER_HEADER 272
+#define PERCENT_BEFORE_HEADER 273
+#define PERCENT_DEBUG 274
+#define PERCENT_DEFAULT_PREC 275
+#define PERCENT_DEFINE 276
+#define PERCENT_DEFINES 277
+#define PERCENT_END_HEADER 278
+#define PERCENT_ERROR_VERBOSE 279
+#define PERCENT_EXPECT 280
+#define PERCENT_EXPECT_RR 281
+#define PERCENT_FILE_PREFIX 282
+#define PERCENT_GLR_PARSER 283
+#define PERCENT_INITIAL_ACTION 284
+#define PERCENT_LEX_PARAM 285
+#define PERCENT_LOCATIONS 286
+#define PERCENT_NAME_PREFIX 287
+#define PERCENT_NO_DEFAULT_PREC 288
+#define PERCENT_NO_LINES 289
+#define PERCENT_NONDETERMINISTIC_PARSER 290
+#define PERCENT_OUTPUT 291
+#define PERCENT_PARSE_PARAM 292
+#define PERCENT_PURE_PARSER 293
+#define PERCENT_REQUIRE 294
+#define PERCENT_SKELETON 295
+#define PERCENT_START 296
+#define PERCENT_START_HEADER 297
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
+#define PERCENT_UNION 312
 
 
 
@@ -304,7 +306,7 @@ typedef union YYSTYPE
   unsigned char character;
 }
 /* Line 198 of yacc.c.  */
-#line 308 "parse-gram.c"
+#line 310 "parse-gram.c"
 	YYSTYPE;
 # define YYSTYPE_IS_TRIVIAL 1
 # define yystype YYSTYPE /* obsolescent; will be withdrawn */
@@ -328,7 +330,7 @@ typedef struct YYLTYPE
 /* Copy the second part of user declarations.  */
 
 /* Line 221 of yacc.c.  */
-#line 332 "parse-gram.c"
+#line 334 "parse-gram.c"
 
 #ifdef short
 # undef short
@@ -545,20 +547,20 @@ union yyalloc
 /* YYFINAL -- State number of the termination state.  */
 #define YYFINAL  3
 /* YYLAST -- Last index in YYTABLE.  */
-#define YYLAST   168
+#define YYLAST   195
 
 /* YYNTOKENS -- Number of terminals.  */
-#define YYNTOKENS  57
+#define YYNTOKENS  58
 /* YYNNTS -- Number of nonterminals.  */
-#define YYNNTS  29
+#define YYNNTS  31
 /* YYNRULES -- Number of rules.  */
-#define YYNRULES  94
+#define YYNRULES  97
 /* YYNRULES -- Number of states.  */
-#define YYNSTATES  131
+#define YYNSTATES  136
 
 /* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
 #define YYUNDEFTOK  2
-#define YYMAXUTOK   311
+#define YYMAXUTOK   312
 
 #define YYTRANSLATE(YYX)						\
   ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)
@@ -597,7 +599,7 @@ static const yytype_uint8 yytranslate[] =
       25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
       35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
       45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
-      55,    56
+      55,    56,    57
 };
 
 #if YYDEBUG
@@ -608,58 +610,58 @@ static const yytype_uint8 yyprhs[] =
        0,     0,     3,     8,     9,    12,    14,    16,    19,    22,
       24,    28,    30,    33,    35,    38,    41,    45,    47,    50,
       53,    55,    59,    61,    63,    67,    70,    72,    75,    78,
-      81,    83,    85,    87,    89,    91,    93,    96,    99,   103,
-     107,   110,   112,   114,   115,   117,   121,   122,   126,   127,
-     131,   135,   139,   141,   143,   145,   146,   148,   150,   153,
-     155,   157,   160,   163,   167,   169,   172,   174,   177,   179,
-     182,   185,   186,   190,   192,   196,   199,   200,   203,   206,
-     210,   214,   218,   220,   222,   223,   225,   227,   229,   231,
-     233,   235,   237,   239,   240
+      81,    83,    85,    87,    89,    91,    93,    96,   100,   104,
+     106,   108,   109,   111,   115,   116,   120,   121,   125,   129,
+     133,   135,   137,   139,   140,   142,   144,   147,   149,   152,
+     154,   156,   158,   160,   162,   165,   168,   172,   174,   177,
+     179,   182,   184,   187,   190,   191,   195,   197,   201,   204,
+     205,   208,   211,   215,   219,   223,   225,   227,   228,   230,
+     232,   234,   236,   238,   240,   242,   244,   245
 };
 
 /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
 static const yytype_int8 yyrhs[] =
 {
-      58,     0,    -1,    59,    51,    72,    85,    -1,    -1,    59,
-      60,    -1,    61,    -1,    53,    -1,    16,    80,    -1,    17,
-      80,    -1,    18,    -1,    20,     3,    79,    -1,    21,    -1,
-      22,    80,    -1,    23,    -1,    24,     4,    -1,    25,     4,
-      -1,    26,    48,     3,    -1,    27,    -1,    28,    45,    -1,
-      29,    45,    -1,    30,    -1,    31,    48,     3,    -1,    33,
-      -1,    34,    -1,    35,    48,     3,    -1,    36,    45,    -1,
-      37,    -1,    38,     3,    -1,    39,     3,    -1,    41,    80,
-      -1,    42,    -1,    43,    -1,    44,    -1,    54,    -1,    66,
-      -1,    63,    -1,    40,    83,    -1,     8,    45,    -1,     8,
-      45,    69,    -1,     9,    45,    69,    -1,     9,    45,    -1,
-      19,    -1,    32,    -1,    -1,    49,    -1,    56,    62,    45,
-      -1,    -1,     6,    64,    71,    -1,    -1,     5,    65,    71,
-      -1,     7,    55,    69,    -1,    67,    68,    69,    -1,    10,
-      -1,    11,    -1,    12,    -1,    -1,    55,    -1,    83,    -1,
-      69,    83,    -1,    55,    -1,    81,    -1,    81,     4,    -1,
-      81,    84,    -1,    81,     4,    84,    -1,    70,    -1,    71,
-      70,    -1,    73,    -1,    72,    73,    -1,    74,    -1,    61,
-      54,    -1,     1,    54,    -1,    -1,    82,    75,    76,    -1,
-      77,    -1,    76,    52,    77,    -1,    76,    54,    -1,    -1,
-      77,    83,    -1,    77,    45,    -1,    77,    13,    83,    -1,
-      77,    14,     4,    -1,    77,    15,    55,    -1,     3,    -1,
-      80,    -1,    -1,    78,    -1,    45,    -1,    49,    -1,    46,
-      -1,    50,    -1,    81,    -1,    84,    -1,     3,    -1,    -1,
-      51,    47,    -1
+      59,     0,    -1,    60,    52,    75,    88,    -1,    -1,    60,
+      61,    -1,    62,    -1,    54,    -1,    17,    83,    -1,    18,
+      83,    -1,    19,    -1,    21,     3,    82,    -1,    22,    -1,
+      23,    83,    -1,    24,    -1,    25,     4,    -1,    26,     4,
+      -1,    27,    49,     3,    -1,    28,    -1,    29,    46,    -1,
+      30,    46,    -1,    31,    -1,    32,    49,     3,    -1,    34,
+      -1,    35,    -1,    36,    49,     3,    -1,    37,    46,    -1,
+      38,    -1,    39,     3,    -1,    40,     3,    -1,    42,    83,
+      -1,    43,    -1,    44,    -1,    45,    -1,    55,    -1,    67,
+      -1,    64,    -1,    41,    86,    -1,     8,    46,    71,    -1,
+       9,    46,    71,    -1,    20,    -1,    33,    -1,    -1,    50,
+      -1,    57,    63,    46,    -1,    -1,     6,    65,    74,    -1,
+      -1,     5,    66,    74,    -1,     7,    56,    70,    -1,    68,
+      69,    70,    -1,    11,    -1,    12,    -1,    13,    -1,    -1,
+      56,    -1,    86,    -1,    70,    86,    -1,    72,    -1,    71,
+      72,    -1,    86,    -1,    56,    -1,    10,    -1,    56,    -1,
+      84,    -1,    84,     4,    -1,    84,    87,    -1,    84,     4,
+      87,    -1,    73,    -1,    74,    73,    -1,    76,    -1,    75,
+      76,    -1,    77,    -1,    62,    55,    -1,     1,    55,    -1,
+      -1,    85,    78,    79,    -1,    80,    -1,    79,    53,    80,
+      -1,    79,    55,    -1,    -1,    80,    86,    -1,    80,    46,
+      -1,    80,    14,    86,    -1,    80,    15,     4,    -1,    80,
+      16,    56,    -1,     3,    -1,    83,    -1,    -1,    81,    -1,
+      46,    -1,    50,    -1,    47,    -1,    51,    -1,    84,    -1,
+      87,    -1,     3,    -1,    -1,    52,    48,    -1
 };
 
 /* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
 static const yytype_uint16 yyrline[] =
 {
-       0,   206,   206,   214,   216,   220,   221,   222,   223,   224,
-     225,   226,   227,   228,   229,   230,   231,   232,   237,   241,
-     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
-     252,   253,   254,   255,   259,   260,   261,   265,   269,   277,
-     285,   289,   293,   307,   308,   312,   340,   340,   345,   345,
-     350,   361,   376,   377,   378,   382,   383,   388,   389,   394,
-     399,   404,   410,   416,   427,   428,   437,   438,   444,   445,
-     446,   453,   453,   457,   458,   459,   464,   465,   467,   469,
-     471,   473,   483,   484,   490,   494,   499,   515,   517,   526,
-     531,   532,   537,   544,   546
+       0,   208,   208,   216,   218,   222,   223,   224,   225,   226,
+     227,   228,   229,   230,   231,   232,   233,   234,   239,   243,
+     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
+     254,   255,   256,   257,   261,   262,   263,   267,   275,   283,
+     287,   301,   302,   306,   334,   334,   339,   339,   344,   355,
+     370,   371,   372,   376,   377,   382,   384,   389,   390,   394,
+     395,   396,   401,   406,   411,   417,   423,   434,   435,   444,
+     445,   451,   452,   453,   460,   460,   464,   465,   466,   471,
+     472,   474,   476,   478,   480,   490,   491,   497,   501,   506,
+     522,   524,   533,   538,   539,   544,   551,   553
 };
 #endif
 
@@ -670,10 +672,11 @@ static const char *const yytname[] =
 {
   "\"end of file\"", "error", "$undefined", "\"string\"", "\"integer\"",
   "\"%token\"", "\"%nterm\"", "\"%type\"", "\"%destructor\"",
-  "\"%printer\"", "\"%left\"", "\"%right\"", "\"%nonassoc\"", "\"%prec\"",
-  "\"%dprec\"", "\"%merge\"", "\"%after-header\"", "\"%before-header\"",
-  "\"%debug\"", "\"%default-prec\"", "\"%define\"", "\"%defines\"",
-  "\"%end-header\"", "\"%error-verbose\"", "\"%expect\"", "\"%expect-rr\"",
+  "\"%printer\"", "\"%symbol-default\"", "\"%left\"", "\"%right\"",
+  "\"%nonassoc\"", "\"%prec\"", "\"%dprec\"", "\"%merge\"",
+  "\"%after-header\"", "\"%before-header\"", "\"%debug\"",
+  "\"%default-prec\"", "\"%define\"", "\"%defines\"", "\"%end-header\"",
+  "\"%error-verbose\"", "\"%expect\"", "\"%expect-rr\"",
   "\"%file-prefix\"", "\"%glr-parser\"", "\"%initial-action\"",
   "\"%lex-param\"", "\"%locations\"", "\"%name-prefix\"",
   "\"%no-default-prec\"", "\"%no-lines\"", "\"%nondeterministic-parser\"",
@@ -684,10 +687,11 @@ static const char *const yytname[] =
   "\"%{...%}\"", "\";\"", "\"type\"", "\"%union\"", "$accept", "input",
   "prologue_declarations", "prologue_declaration", "grammar_declaration",
   "union_name", "symbol_declaration", "@1", "@2", "precedence_declaration",
-  "precedence_declarator", "type.opt", "symbols.1", "symbol_def",
-  "symbol_defs.1", "grammar", "rules_or_grammar_declaration", "rules",
-  "@3", "rhses.1", "rhs", "content", "content.opt", "braceless", "id",
-  "id_colon", "symbol", "string_as_id", "epilogue.opt", 0
+  "precedence_declarator", "type.opt", "symbols.1", "generic_symlist",
+  "generic_symlist_item", "symbol_def", "symbol_defs.1", "grammar",
+  "rules_or_grammar_declaration", "rules", "@3", "rhses.1", "rhs",
+  "content", "content.opt", "braceless", "id", "id_colon", "symbol",
+  "string_as_id", "epilogue.opt", 0
 };
 #endif
 
@@ -701,23 +705,23 @@ static const yytype_uint16 yytoknum[] =
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
-      60,    60,    60,    60,    61,    61,    61,    61,    61,    61,
-      61,    61,    61,    62,    62,    61,    64,    63,    65,    63,
-      63,    66,    67,    67,    67,    68,    68,    69,    69,    70,
-      70,    70,    70,    70,    71,    71,    72,    72,    73,    73,
-      73,    75,    74,    76,    76,    76,    77,    77,    77,    77,
-      77,    77,    78,    78,    79,    79,    80,    81,    81,    82,
-      83,    83,    84,    85,    85
+       0,    58,    59,    60,    60,    61,    61,    61,    61,    61,
+      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
+      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
+      61,    61,    61,    61,    62,    62,    62,    62,    62,    62,
+      62,    63,    63,    62,    65,    64,    66,    64,    64,    67,
+      68,    68,    68,    69,    69,    70,    70,    71,    71,    72,
+      72,    72,    73,    73,    73,    73,    73,    74,    74,    75,
+      75,    76,    76,    76,    78,    77,    79,    79,    79,    80,
+      80,    80,    80,    80,    80,    81,    81,    82,    82,    83,
+      84,    84,    85,    86,    86,    87,    88,    88
 };
 
 /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
@@ -726,13 +730,13 @@ static const yytype_uint8 yyr2[] =
        0,     2,     4,     0,     2,     1,     1,     2,     2,     1,
        3,     1,     2,     1,     2,     2,     3,     1,     2,     2,
        1,     3,     1,     1,     3,     2,     1,     2,     2,     2,
-       1,     1,     1,     1,     1,     1,     2,     2,     3,     3,
-       2,     1,     1,     0,     1,     3,     0,     3,     0,     3,
-       3,     3,     1,     1,     1,     0,     1,     1,     2,     1,
-       1,     2,     2,     3,     1,     2,     1,     2,     1,     2,
-       2,     0,     3,     1,     3,     2,     0,     2,     2,     3,
-       3,     3,     1,     1,     0,     1,     1,     1,     1,     1,
-       1,     1,     1,     0,     2
+       1,     1,     1,     1,     1,     1,     2,     3,     3,     1,
+       1,     0,     1,     3,     0,     3,     0,     3,     3,     3,
+       1,     1,     1,     0,     1,     1,     2,     1,     2,     1,
+       1,     1,     1,     1,     2,     2,     3,     1,     2,     1,
+       2,     1,     2,     2,     0,     3,     1,     3,     2,     0,
+       2,     2,     3,     3,     3,     1,     1,     0,     1,     1,
+       1,     1,     1,     1,     1,     1,     0,     2
 };
 
 /* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
@@ -740,124 +744,132 @@ static const yytype_uint8 yyr2[] =
    means the default is an error.  */
 static const yytype_uint8 yydefact[] =
 {
-       3,     0,     0,     1,    48,    46,     0,     0,     0,    52,
-      53,    54,     0,     0,     9,    41,     0,    11,     0,    13,
-       0,     0,     0,    17,     0,     0,    20,     0,    42,    22,
+       3,     0,     0,     1,    46,    44,     0,     0,     0,    50,
+      51,    52,     0,     0,     9,    39,     0,    11,     0,    13,
+       0,     0,     0,    17,     0,     0,    20,     0,    40,    22,
       23,     0,     0,    26,     0,     0,     0,     0,    30,    31,
-      32,     0,     6,    33,    43,     4,     5,    35,    34,    55,
-       0,     0,     0,    37,    40,    86,     7,     8,    84,    12,
+      32,     0,     6,    33,    41,     4,     5,    35,    34,    53,
+       0,     0,     0,     0,     0,    89,     7,     8,    87,    12,
       14,    15,     0,    18,    19,     0,     0,    25,    27,    28,
-      92,    88,    87,    90,    36,    91,    29,     0,    89,     0,
-       0,    66,    68,    71,    44,     0,    56,     0,    59,    64,
-      49,    60,    47,    50,    57,    38,    39,    82,    85,    10,
-      83,    16,    21,    24,    70,    69,     0,    67,     2,    76,
-      45,    51,    65,    61,    62,    58,    94,    72,    73,    63,
-      76,    75,     0,     0,     0,    78,    77,    74,    79,    80,
-      81
+      95,    91,    90,    93,    36,    94,    29,     0,    92,     0,
+       0,    69,    71,    74,    42,     0,    54,     0,    62,    67,
+      47,    63,    45,    48,    55,    61,    60,    37,    57,    59,
+      38,    85,    88,    10,    86,    16,    21,    24,    73,    72,
+       0,    70,     2,    79,    43,    49,    68,    64,    65,    56,
+      58,    97,    75,    76,    66,    79,    78,     0,     0,     0,
+      81,    80,    77,    82,    83,    84
 };
 
 /* YYDEFGOTO[NTERM-NUM].  */
 static const yytype_int8 yydefgoto[] =
 {
       -1,     1,     2,    45,    79,    85,    47,    51,    50,    48,
-      49,    87,    93,    89,    90,    80,    81,    82,   109,   117,
-     118,    98,    99,    56,    73,    83,    94,    75,   108
+      49,    87,    93,    97,    98,    89,    90,    80,    81,    82,
+     113,   122,   123,   102,   103,    56,    73,    83,    99,    75,
+     112
 };
 
 /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
    STATE-NUM.  */
-#define YYPACT_NINF -91
-static const yytype_int8 yypact[] =
+#define YYPACT_NINF -75
+static const yytype_int16 yypact[] =
 {
-     -91,    29,   112,   -91,   -91,   -91,   -39,   -14,   -13,   -91,
-     -91,   -91,   -12,   -12,   -91,   -91,    33,   -91,   -12,   -91,
-      35,    36,   -11,   -91,     5,     6,   -91,     1,   -91,   -91,
-     -91,     7,     9,   -91,    53,    61,    27,   -12,   -91,   -91,
-     -91,    60,   -91,   -91,    14,   -91,   -91,   -91,   -91,    19,
-     -31,   -31,    27,    27,    27,   -91,   -91,   -91,     3,   -91,
-     -91,   -91,    77,   -91,   -91,    81,    84,   -91,   -91,   -91,
-     -91,   -91,   -91,   -91,   -91,   -91,   -91,    34,   -91,    39,
-       2,   -91,   -91,   -91,   -91,    44,   -91,    27,   -91,   -91,
-     -31,    16,   -31,    27,   -91,    27,    27,   -91,   -91,   -91,
-     -91,   -91,   -91,   -91,   -91,   -91,    43,   -91,   -91,   -91,
-     -91,    27,   -91,    91,   -91,   -91,   -91,   -27,    32,   -91,
-     -91,   -91,    27,    92,    40,   -91,   -91,    32,   -91,   -91,
-     -91
+     -75,    18,   101,   -75,   -75,   -75,   -21,   -20,   -10,   -75,
+     -75,   -75,    -8,    -8,   -75,   -75,    37,   -75,    -8,   -75,
+      41,    44,     6,   -75,    -5,     3,   -75,     7,   -75,   -75,
+     -75,    10,    16,   -75,    61,    67,     0,    -8,   -75,   -75,
+     -75,    60,   -75,   -75,    13,   -75,   -75,   -75,   -75,    19,
+     -28,   -28,     0,    27,    27,   -75,   -75,   -75,     8,   -75,
+     -75,   -75,    73,   -75,   -75,    75,    78,   -75,   -75,   -75,
+     -75,   -75,   -75,   -75,   -75,   -75,   -75,    30,   -75,    31,
+       1,   -75,   -75,   -75,   -75,    36,   -75,     0,   -75,   -75,
+     -28,    29,   -28,     0,   -75,   -75,   -75,    27,   -75,   -75,
+      27,   -75,   -75,   -75,   -75,   -75,   -75,   -75,   -75,   -75,
+      40,   -75,   -75,   -75,   -75,     0,   -75,    81,   -75,   -75,
+     -75,   -75,   -30,   145,   -75,   -75,   -75,     0,    85,    34,
+     -75,   -75,   145,   -75,   -75,   -75
 };
 
 /* YYPGOTO[NTERM-NUM].  */
 static const yytype_int8 yypgoto[] =
 {
-     -91,   -91,   -91,   -91,    95,   -91,   -91,   -91,   -91,   -91,
-     -91,   -91,   -49,   -64,    47,   -91,    21,   -91,   -91,   -91,
-     -21,   -91,   -91,     4,    -7,   -91,   -36,   -90,   -91
+     -75,   -75,   -75,   -75,    90,   -75,   -75,   -75,   -75,   -75,
+     -75,   -75,    11,    43,   -73,   -61,    48,   -75,    14,   -75,
+     -75,   -75,   -25,   -75,   -75,     2,   -46,   -75,   -36,   -74,
+     -75
 };
 
 /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
    positive, shift that token.  If negative, reduce the rule which
    number is the opposite.  If zero, do what YYDEFACT says.
    If YYTABLE_NINF, syntax error.  */
-#define YYTABLE_NINF -94
+#define YYTABLE_NINF -97
 static const yytype_int16 yytable[] =
 {
-      74,   114,   -93,    77,    95,    96,    97,     4,     5,     6,
-       7,     8,     9,    10,    11,    71,    52,    57,    72,    70,
-     113,    15,    59,   119,    88,   120,   112,   121,   112,     3,
-      70,    53,    54,    55,    28,    70,    58,    62,   111,    60,
-      61,    76,    36,    91,    91,   122,   123,   124,    55,    65,
-      63,    64,    78,   106,    67,    66,    68,   115,    44,   115,
-     115,    77,   100,    84,    69,     4,     5,     6,     7,     8,
-       9,    10,    11,    71,    86,   115,    72,   125,    71,    15,
-     101,    72,   126,    91,   102,    91,   128,   103,   104,   110,
-     116,   126,    28,   105,    70,   130,   129,    46,    92,   127,
-      36,   107,     0,     0,     0,     0,     0,     0,     0,     0,
-      78,     0,     0,     0,     0,     0,    44,     4,     5,     6,
-       7,     8,     9,    10,    11,     0,     0,     0,    12,    13,
+      74,   -96,    77,    70,    91,    91,     4,     5,     6,     7,
+       8,   101,     9,    10,    11,    57,    94,   118,     3,    71,
+      59,    15,    72,   125,   120,   126,    53,   120,    88,   116,
+      70,   116,    70,   117,    28,    52,    54,    95,    55,    76,
+      58,    63,    36,   124,    91,    60,    91,    71,    61,    64,
+      72,    94,    78,   110,    55,    62,    65,   119,    44,    66,
+     104,    77,    67,    84,    68,     4,     5,     6,     7,     8,
+      69,     9,    10,    11,    71,    86,   105,    72,   106,   119,
+      15,   107,   114,    96,    70,   108,   109,   131,   121,   134,
+     135,   133,    46,    28,   111,     0,   131,   100,   115,    92,
+     132,    36,     0,     0,     0,     0,     4,     5,     6,     7,
+       8,    78,     9,    10,    11,     0,     0,    44,    12,    13,
       14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
       24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
-      34,    35,    36,    37,    38,    39,    40,     0,     0,     0,
-       0,     0,     0,    41,     0,    42,    43,     0,    44
+      34,    35,    36,    37,    38,    39,    40,     0,    70,     0,
+       0,     0,     0,    41,     0,    42,    43,     0,    44,   127,
+     128,   129,     0,     0,     0,     0,     0,     0,     0,     0,
+       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
+       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
+       0,   130,    71,     0,     0,    72
 };
 
-static const yytype_int8 yycheck[] =
+static const yytype_int16 yycheck[] =
 {
-      36,    91,     0,     1,    53,    54,     3,     5,     6,     7,
-       8,     9,    10,    11,    12,    46,    55,    13,    49,     3,
-       4,    19,    18,   113,    55,    52,    90,    54,    92,     0,
-       3,    45,    45,    45,    32,     3,     3,    48,    87,     4,
-       4,    37,    40,    50,    51,    13,    14,    15,    45,    48,
-      45,    45,    50,    51,    45,    48,     3,    93,    56,    95,
-      96,     1,    58,    49,     3,     5,     6,     7,     8,     9,
-      10,    11,    12,    46,    55,   111,    49,    45,    46,    19,
-       3,    49,   118,    90,     3,    92,   122,     3,    54,    45,
-      47,   127,    32,    54,     3,    55,     4,     2,    51,   120,
-      40,    80,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
-      50,    -1,    -1,    -1,    -1,    -1,    56,     5,     6,     7,
-       8,     9,    10,    11,    12,    -1,    -1,    -1,    16,    17,
-      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
-      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
-      38,    39,    40,    41,    42,    43,    44,    -1,    -1,    -1,
-      -1,    -1,    -1,    51,    -1,    53,    54,    -1,    56
+      36,     0,     1,     3,    50,    51,     5,     6,     7,     8,
+       9,     3,    11,    12,    13,    13,    52,    91,     0,    47,
+      18,    20,    50,    53,    97,    55,    46,   100,    56,    90,
+       3,    92,     3,     4,    33,    56,    46,    10,    46,    37,
+       3,    46,    41,   117,    90,     4,    92,    47,     4,    46,
+      50,    87,    51,    52,    46,    49,    49,    93,    57,    49,
+      58,     1,    46,    50,     3,     5,     6,     7,     8,     9,
+       3,    11,    12,    13,    47,    56,     3,    50,     3,   115,
+      20,     3,    46,    56,     3,    55,    55,   123,    48,     4,
+      56,   127,     2,    33,    80,    -1,   132,    54,    87,    51,
+     125,    41,    -1,    -1,    -1,    -1,     5,     6,     7,     8,
+       9,    51,    11,    12,    13,    -1,    -1,    57,    17,    18,
+      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
+      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
+      39,    40,    41,    42,    43,    44,    45,    -1,     3,    -1,
+      -1,    -1,    -1,    52,    -1,    54,    55,    -1,    57,    14,
+      15,    16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
+      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
+      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
+      -1,    46,    47,    -1,    -1,    50
 };
 
 /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
    symbol of state STATE-NUM.  */
 static const yytype_uint8 yystos[] =
 {
-       0,    58,    59,     0,     5,     6,     7,     8,     9,    10,
-      11,    12,    16,    17,    18,    19,    20,    21,    22,    23,
-      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
-      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
-      44,    51,    53,    54,    56,    60,    61,    63,    66,    67,
-      65,    64,    55,    45,    45,    45,    80,    80,     3,    80,
-       4,     4,    48,    45,    45,    48,    48,    45,     3,     3,
-       3,    46,    49,    81,    83,    84,    80,     1,    50,    61,
-      72,    73,    74,    82,    49,    62,    55,    68,    55,    70,
-      71,    81,    71,    69,    83,    69,    69,     3,    78,    79,
-      80,     3,     3,     3,    54,    54,    51,    73,    85,    75,
-      45,    69,    70,     4,    84,    83,    47,    76,    77,    84,
-      52,    54,    13,    14,    15,    45,    83,    77,    83,     4,
-      55
+       0,    59,    60,     0,     5,     6,     7,     8,     9,    11,
+      12,    13,    17,    18,    19,    20,    21,    22,    23,    24,
+      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
+      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
+      45,    52,    54,    55,    57,    61,    62,    64,    67,    68,
+      66,    65,    56,    46,    46,    46,    83,    83,     3,    83,
+       4,     4,    49,    46,    46,    49,    49,    46,     3,     3,
+       3,    47,    50,    84,    86,    87,    83,     1,    51,    62,
+      75,    76,    77,    85,    50,    63,    56,    69,    56,    73,
+      74,    84,    74,    70,    86,    10,    56,    71,    72,    86,
+      71,     3,    81,    82,    83,     3,     3,     3,    55,    55,
+      52,    76,    88,    78,    46,    70,    73,     4,    87,    86,
+      72,    48,    79,    80,    87,    53,    55,    14,    15,    16,
+      46,    86,    80,    86,     4,    56
 };
 
 #define yyerrok		(yyerrstatus = 0)
@@ -1007,115 +1019,115 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
     {
       case 3: /* "\"string\"" */
 /* Line 670 of yacc.c.  */
-#line 184 "parse-gram.y"
+#line 186 "parse-gram.y"
 	{ fputs (quotearg_style (c_quoting_style, (yyvaluep->chars)), stderr); };
 /* Line 670 of yacc.c.  */
-#line 1014 "parse-gram.c"
+#line 1026 "parse-gram.c"
 	break;
       case 4: /* "\"integer\"" */
 /* Line 670 of yacc.c.  */
-#line 195 "parse-gram.y"
+#line 197 "parse-gram.y"
 	{ fprintf (stderr, "%d", (yyvaluep->integer)); };
 /* Line 670 of yacc.c.  */
-#line 1021 "parse-gram.c"
+#line 1033 "parse-gram.c"
 	break;
-      case 45: /* "\"{...}\"" */
+      case 46: /* "\"{...}\"" */
 /* Line 670 of yacc.c.  */
-#line 186 "parse-gram.y"
+#line 188 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 /* Line 670 of yacc.c.  */
-#line 1028 "parse-gram.c"
+#line 1040 "parse-gram.c"
 	break;
-      case 46: /* "\"char\"" */
+      case 47: /* "\"char\"" */
 /* Line 670 of yacc.c.  */
-#line 179 "parse-gram.y"
+#line 181 "parse-gram.y"
 	{ fputs (char_name ((yyvaluep->character)), stderr); };
 /* Line 670 of yacc.c.  */
-#line 1035 "parse-gram.c"
+#line 1047 "parse-gram.c"
 	break;
-      case 47: /* "\"epilogue\"" */
+      case 48: /* "\"epilogue\"" */
 /* Line 670 of yacc.c.  */
-#line 186 "parse-gram.y"
+#line 188 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 /* Line 670 of yacc.c.  */
-#line 1042 "parse-gram.c"
+#line 1054 "parse-gram.c"
 	break;
-      case 49: /* "\"identifier\"" */
+      case 50: /* "\"identifier\"" */
 /* Line 670 of yacc.c.  */
-#line 191 "parse-gram.y"
+#line 193 "parse-gram.y"
 	{ fputs ((yyvaluep->uniqstr), stderr); };
 /* Line 670 of yacc.c.  */
-#line 1049 "parse-gram.c"
+#line 1061 "parse-gram.c"
 	break;
-      case 50: /* "\"identifier:\"" */
+      case 51: /* "\"identifier:\"" */
 /* Line 670 of yacc.c.  */
-#line 192 "parse-gram.y"
+#line 194 "parse-gram.y"
 	{ fprintf (stderr, "%s:", (yyvaluep->uniqstr)); };
 /* Line 670 of yacc.c.  */
-#line 1056 "parse-gram.c"
+#line 1068 "parse-gram.c"
 	break;
-      case 53: /* "\"%{...%}\"" */
+      case 54: /* "\"%{...%}\"" */
 /* Line 670 of yacc.c.  */
-#line 186 "parse-gram.y"
+#line 188 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 /* Line 670 of yacc.c.  */
-#line 1063 "parse-gram.c"
+#line 1075 "parse-gram.c"
 	break;
-      case 55: /* "\"type\"" */
+      case 56: /* "\"type\"" */
 /* Line 670 of yacc.c.  */
-#line 190 "parse-gram.y"
+#line 192 "parse-gram.y"
 	{ fprintf (stderr, "<%s>", (yyvaluep->uniqstr)); };
 /* Line 670 of yacc.c.  */
-#line 1070 "parse-gram.c"
+#line 1082 "parse-gram.c"
 	break;
-      case 78: /* "content" */
+      case 81: /* "content" */
 /* Line 670 of yacc.c.  */
-#line 186 "parse-gram.y"
+#line 188 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 /* Line 670 of yacc.c.  */
-#line 1077 "parse-gram.c"
+#line 1089 "parse-gram.c"
 	break;
-      case 79: /* "content.opt" */
+      case 82: /* "content.opt" */
 /* Line 670 of yacc.c.  */
-#line 186 "parse-gram.y"
+#line 188 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 /* Line 670 of yacc.c.  */
-#line 1084 "parse-gram.c"
+#line 1096 "parse-gram.c"
 	break;
-      case 80: /* "braceless" */
+      case 83: /* "braceless" */
 /* Line 670 of yacc.c.  */
-#line 186 "parse-gram.y"
+#line 188 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 /* Line 670 of yacc.c.  */
-#line 1091 "parse-gram.c"
+#line 1103 "parse-gram.c"
 	break;
-      case 81: /* "id" */
+      case 84: /* "id" */
 /* Line 670 of yacc.c.  */
-#line 198 "parse-gram.y"
+#line 200 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 /* Line 670 of yacc.c.  */
-#line 1098 "parse-gram.c"
+#line 1110 "parse-gram.c"
 	break;
-      case 82: /* "id_colon" */
+      case 85: /* "id_colon" */
 /* Line 670 of yacc.c.  */
-#line 199 "parse-gram.y"
+#line 201 "parse-gram.y"
 	{ fprintf (stderr, "%s:", (yyvaluep->symbol)->tag); };
 /* Line 670 of yacc.c.  */
-#line 1105 "parse-gram.c"
+#line 1117 "parse-gram.c"
 	break;
-      case 83: /* "symbol" */
+      case 86: /* "symbol" */
 /* Line 670 of yacc.c.  */
-#line 198 "parse-gram.y"
+#line 200 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 /* Line 670 of yacc.c.  */
-#line 1112 "parse-gram.c"
+#line 1124 "parse-gram.c"
 	break;
-      case 84: /* "string_as_id" */
+      case 87: /* "string_as_id" */
 /* Line 670 of yacc.c.  */
-#line 198 "parse-gram.y"
+#line 200 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 /* Line 670 of yacc.c.  */
-#line 1119 "parse-gram.c"
+#line 1131 "parse-gram.c"
 	break;
       default:
 	break;
@@ -1637,7 +1649,7 @@ YYLTYPE yylloc;
   boundary_set (&yylloc.end, current_file, 1, 1);
 }
 /* Line 1082 of yacc.c.  */
-#line 1641 "parse-gram.c"
+#line 1653 "parse-gram.c"
   yylsp[0] = yylloc;
   goto yysetstate;
 
@@ -1822,73 +1834,73 @@ yyreduce:
     {
         case 6:
 /* Line 1269 of yacc.c.  */
-#line 221 "parse-gram.y"
+#line 223 "parse-gram.y"
     { prologue_augment (translate_code ((yyvsp[(1) - (1)].chars), (yylsp[(1) - (1)])), (yylsp[(1) - (1)]), union_seen); }
     break;
 
   case 7:
 /* Line 1269 of yacc.c.  */
-#line 222 "parse-gram.y"
+#line 224 "parse-gram.y"
     { prologue_augment ((yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)]), true); }
     break;
 
   case 8:
 /* Line 1269 of yacc.c.  */
-#line 223 "parse-gram.y"
+#line 225 "parse-gram.y"
     { prologue_augment ((yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)]), false); }
     break;
 
   case 9:
 /* Line 1269 of yacc.c.  */
-#line 224 "parse-gram.y"
+#line 226 "parse-gram.y"
     { debug_flag = true; }
     break;
 
   case 10:
 /* Line 1269 of yacc.c.  */
-#line 225 "parse-gram.y"
+#line 227 "parse-gram.y"
     { muscle_insert ((yyvsp[(2) - (3)].chars), (yyvsp[(3) - (3)].chars)); }
     break;
 
   case 11:
 /* Line 1269 of yacc.c.  */
-#line 226 "parse-gram.y"
+#line 228 "parse-gram.y"
     { defines_flag = true; }
     break;
 
   case 12:
 /* Line 1269 of yacc.c.  */
-#line 227 "parse-gram.y"
+#line 229 "parse-gram.y"
     { muscle_code_grow ("end_header", (yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])); }
     break;
 
   case 13:
 /* Line 1269 of yacc.c.  */
-#line 228 "parse-gram.y"
+#line 230 "parse-gram.y"
     { error_verbose = true; }
     break;
 
   case 14:
 /* Line 1269 of yacc.c.  */
-#line 229 "parse-gram.y"
+#line 231 "parse-gram.y"
     { expected_sr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 15:
 /* Line 1269 of yacc.c.  */
-#line 230 "parse-gram.y"
+#line 232 "parse-gram.y"
     { expected_rr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 16:
 /* Line 1269 of yacc.c.  */
-#line 231 "parse-gram.y"
+#line 233 "parse-gram.y"
     { spec_file_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 17:
 /* Line 1269 of yacc.c.  */
-#line 233 "parse-gram.y"
+#line 235 "parse-gram.y"
     {
       nondeterministic_parser = true;
       glr_parser = true;
@@ -1897,7 +1909,7 @@ yyreduce:
 
   case 18:
 /* Line 1269 of yacc.c.  */
-#line 238 "parse-gram.y"
+#line 240 "parse-gram.y"
     {
       muscle_code_grow ("initial_action", translate_symbol_action ((yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])), (yylsp[(2) - (2)]));
     }
@@ -1905,91 +1917,91 @@ yyreduce:
 
   case 19:
 /* Line 1269 of yacc.c.  */
-#line 241 "parse-gram.y"
+#line 243 "parse-gram.y"
     { add_param ("lex_param", (yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])); }
     break;
 
   case 20:
 /* Line 1269 of yacc.c.  */
-#line 242 "parse-gram.y"
+#line 244 "parse-gram.y"
     { locations_flag = true; }
     break;
 
   case 21:
 /* Line 1269 of yacc.c.  */
-#line 243 "parse-gram.y"
+#line 245 "parse-gram.y"
     { spec_name_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 22:
 /* Line 1269 of yacc.c.  */
-#line 244 "parse-gram.y"
+#line 246 "parse-gram.y"
     { no_lines_flag = true; }
     break;
 
   case 23:
 /* Line 1269 of yacc.c.  */
-#line 245 "parse-gram.y"
+#line 247 "parse-gram.y"
     { nondeterministic_parser = true; }
     break;
 
   case 24:
 /* Line 1269 of yacc.c.  */
-#line 246 "parse-gram.y"
+#line 248 "parse-gram.y"
     { spec_outfile = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 25:
 /* Line 1269 of yacc.c.  */
-#line 247 "parse-gram.y"
+#line 249 "parse-gram.y"
     { add_param ("parse_param", (yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])); }
     break;
 
   case 26:
 /* Line 1269 of yacc.c.  */
-#line 248 "parse-gram.y"
+#line 250 "parse-gram.y"
     { pure_parser = true; }
     break;
 
   case 27:
 /* Line 1269 of yacc.c.  */
-#line 249 "parse-gram.y"
+#line 251 "parse-gram.y"
     { version_check (&(yylsp[(2) - (2)]), (yyvsp[(2) - (2)].chars)); }
     break;
 
   case 28:
 /* Line 1269 of yacc.c.  */
-#line 250 "parse-gram.y"
+#line 252 "parse-gram.y"
     { skeleton = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 29:
 /* Line 1269 of yacc.c.  */
-#line 251 "parse-gram.y"
+#line 253 "parse-gram.y"
     { muscle_code_grow ("start_header", (yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])); }
     break;
 
   case 30:
 /* Line 1269 of yacc.c.  */
-#line 252 "parse-gram.y"
+#line 254 "parse-gram.y"
     { token_table_flag = true; }
     break;
 
   case 31:
 /* Line 1269 of yacc.c.  */
-#line 253 "parse-gram.y"
+#line 255 "parse-gram.y"
     { report_flag = report_states; }
     break;
 
   case 32:
 /* Line 1269 of yacc.c.  */
-#line 254 "parse-gram.y"
+#line 256 "parse-gram.y"
     { yacc_flag = true; }
     break;
 
   case 36:
 /* Line 1269 of yacc.c.  */
-#line 262 "parse-gram.y"
+#line 264 "parse-gram.y"
     {
       grammar_start_symbol_set ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]));
     }
@@ -1997,75 +2009,59 @@ yyreduce:
 
   case 37:
 /* Line 1269 of yacc.c.  */
-#line 266 "parse-gram.y"
-    {
-      default_destructor_set (translate_symbol_action ((yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])), (yylsp[(2) - (2)]));
-    }
-    break;
-
-  case 38:
-/* Line 1269 of yacc.c.  */
-#line 270 "parse-gram.y"
+#line 268 "parse-gram.y"
     {
       symbol_list *list;
       const char *action = translate_symbol_action ((yyvsp[(2) - (3)].chars), (yylsp[(2) - (3)]));
       for (list = (yyvsp[(3) - (3)].list); list; list = list->next)
- 	symbol_destructor_set (list->sym, action, (yylsp[(2) - (3)]));
+        symbol_list_destructor_set (list, action, (yylsp[(2) - (3)]));
       symbol_list_free ((yyvsp[(3) - (3)].list));
     }
     break;
 
-  case 39:
+  case 38:
 /* Line 1269 of yacc.c.  */
-#line 278 "parse-gram.y"
+#line 276 "parse-gram.y"
     {
       symbol_list *list;
       const char *action = translate_symbol_action ((yyvsp[(2) - (3)].chars), (yylsp[(2) - (3)]));
       for (list = (yyvsp[(3) - (3)].list); list; list = list->next)
-	symbol_printer_set (list->sym, action, (yylsp[(2) - (3)]));
+        symbol_list_printer_set (list, action, (yylsp[(2) - (3)]));
       symbol_list_free ((yyvsp[(3) - (3)].list));
     }
     break;
 
-  case 40:
-/* Line 1269 of yacc.c.  */
-#line 286 "parse-gram.y"
-    {
-      default_printer_set (translate_symbol_action ((yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])), (yylsp[(2) - (2)]));
-    }
-    break;
-
-  case 41:
+  case 39:
 /* Line 1269 of yacc.c.  */
-#line 290 "parse-gram.y"
+#line 284 "parse-gram.y"
     {
       default_prec = true;
     }
     break;
 
-  case 42:
+  case 40:
 /* Line 1269 of yacc.c.  */
-#line 294 "parse-gram.y"
+#line 288 "parse-gram.y"
     {
       default_prec = false;
     }
     break;
 
-  case 43:
+  case 41:
 /* Line 1269 of yacc.c.  */
-#line 307 "parse-gram.y"
+#line 301 "parse-gram.y"
     {}
     break;
 
-  case 44:
+  case 42:
 /* Line 1269 of yacc.c.  */
-#line 308 "parse-gram.y"
+#line 302 "parse-gram.y"
     { muscle_code_grow ("union_name", (yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
-  case 45:
+  case 43:
 /* Line 1269 of yacc.c.  */
-#line 313 "parse-gram.y"
+#line 307 "parse-gram.y"
     {
       char const *body = (yyvsp[(3) - (3)].chars);
 
@@ -2089,127 +2085,157 @@ yyreduce:
     }
     break;
 
-  case 46:
+  case 44:
 /* Line 1269 of yacc.c.  */
-#line 340 "parse-gram.y"
+#line 334 "parse-gram.y"
     { current_class = nterm_sym; }
     break;
 
-  case 47:
+  case 45:
 /* Line 1269 of yacc.c.  */
-#line 341 "parse-gram.y"
+#line 335 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
     break;
 
-  case 48:
+  case 46:
 /* Line 1269 of yacc.c.  */
-#line 345 "parse-gram.y"
+#line 339 "parse-gram.y"
     { current_class = token_sym; }
     break;
 
-  case 49:
+  case 47:
 /* Line 1269 of yacc.c.  */
-#line 346 "parse-gram.y"
+#line 340 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
     break;
 
-  case 50:
+  case 48:
 /* Line 1269 of yacc.c.  */
-#line 351 "parse-gram.y"
+#line 345 "parse-gram.y"
     {
       tag_seen = true;
       symbol_list *list;
       for (list = (yyvsp[(3) - (3)].list); list; list = list->next)
-	symbol_type_set (list->sym, (yyvsp[(2) - (3)].uniqstr), (yylsp[(2) - (3)]));
+	symbol_type_set (list->content.sym, (yyvsp[(2) - (3)].uniqstr), (yylsp[(2) - (3)]));
       symbol_list_free ((yyvsp[(3) - (3)].list));
     }
     break;
 
-  case 51:
+  case 49:
 /* Line 1269 of yacc.c.  */
-#line 362 "parse-gram.y"
+#line 356 "parse-gram.y"
     {
       symbol_list *list;
       ++current_prec;
       for (list = (yyvsp[(3) - (3)].list); list; list = list->next)
 	{
-	  symbol_type_set (list->sym, current_type, (yylsp[(2) - (3)]));
-	  symbol_precedence_set (list->sym, current_prec, (yyvsp[(1) - (3)].assoc), (yylsp[(1) - (3)]));
+	  symbol_type_set (list->content.sym, current_type, (yylsp[(2) - (3)]));
+	  symbol_precedence_set (list->content.sym, current_prec, (yyvsp[(1) - (3)].assoc), (yylsp[(1) - (3)]));
 	}
       symbol_list_free ((yyvsp[(3) - (3)].list));
       current_type = NULL;
     }
     break;
 
-  case 52:
+  case 50:
 /* Line 1269 of yacc.c.  */
-#line 376 "parse-gram.y"
+#line 370 "parse-gram.y"
     { (yyval.assoc) = left_assoc; }
     break;
 
-  case 53:
+  case 51:
 /* Line 1269 of yacc.c.  */
-#line 377 "parse-gram.y"
+#line 371 "parse-gram.y"
     { (yyval.assoc) = right_assoc; }
     break;
 
-  case 54:
+  case 52:
 /* Line 1269 of yacc.c.  */
-#line 378 "parse-gram.y"
+#line 372 "parse-gram.y"
     { (yyval.assoc) = non_assoc; }
     break;
 
-  case 55:
+  case 53:
 /* Line 1269 of yacc.c.  */
-#line 382 "parse-gram.y"
+#line 376 "parse-gram.y"
     { current_type = NULL; }
     break;
 
-  case 56:
+  case 54:
 /* Line 1269 of yacc.c.  */
-#line 383 "parse-gram.y"
+#line 377 "parse-gram.y"
     { current_type = (yyvsp[(1) - (1)].uniqstr); tag_seen = true; }
     break;
 
+  case 55:
+/* Line 1269 of yacc.c.  */
+#line 383 "parse-gram.y"
+    { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
+    break;
+
+  case 56:
+/* Line 1269 of yacc.c.  */
+#line 385 "parse-gram.y"
+    { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), symbol_list_sym_new ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]))); }
+    break;
+
   case 57:
 /* Line 1269 of yacc.c.  */
-#line 388 "parse-gram.y"
-    { (yyval.list) = symbol_list_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
+#line 389 "parse-gram.y"
+    { (yyval.list) = (yyvsp[(1) - (1)].list); }
     break;
 
   case 58:
 /* Line 1269 of yacc.c.  */
-#line 389 "parse-gram.y"
-    { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), (yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)])); }
+#line 390 "parse-gram.y"
+    { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), (yyvsp[(2) - (2)].list)); }
     break;
 
   case 59:
 /* Line 1269 of yacc.c.  */
+#line 394 "parse-gram.y"
+    { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
+    break;
+
+  case 60:
+/* Line 1269 of yacc.c.  */
 #line 395 "parse-gram.y"
+    { (yyval.list) = symbol_list_type_new ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
+    break;
+
+  case 61:
+/* Line 1269 of yacc.c.  */
+#line 396 "parse-gram.y"
+    { (yyval.list) = symbol_list_default_new ((yylsp[(1) - (1)])); }
+    break;
+
+  case 62:
+/* Line 1269 of yacc.c.  */
+#line 402 "parse-gram.y"
     {
        current_type = (yyvsp[(1) - (1)].uniqstr);
        tag_seen = true;
      }
     break;
 
-  case 60:
+  case 63:
 /* Line 1269 of yacc.c.  */
-#line 400 "parse-gram.y"
+#line 407 "parse-gram.y"
     {
        symbol_class_set ((yyvsp[(1) - (1)].symbol), current_class, (yylsp[(1) - (1)]), true);
        symbol_type_set ((yyvsp[(1) - (1)].symbol), current_type, (yylsp[(1) - (1)]));
      }
     break;
 
-  case 61:
+  case 64:
 /* Line 1269 of yacc.c.  */
-#line 405 "parse-gram.y"
+#line 412 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
       symbol_type_set ((yyvsp[(1) - (2)].symbol), current_type, (yylsp[(1) - (2)]));
@@ -2217,9 +2243,9 @@ yyreduce:
     }
     break;
 
-  case 62:
+  case 65:
 /* Line 1269 of yacc.c.  */
-#line 411 "parse-gram.y"
+#line 418 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
       symbol_type_set ((yyvsp[(1) - (2)].symbol), current_type, (yylsp[(1) - (2)]));
@@ -2227,9 +2253,9 @@ yyreduce:
     }
     break;
 
-  case 63:
+  case 66:
 /* Line 1269 of yacc.c.  */
-#line 417 "parse-gram.y"
+#line 424 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (3)].symbol), current_class, (yylsp[(1) - (3)]), true);
       symbol_type_set ((yyvsp[(1) - (3)].symbol), current_type, (yylsp[(1) - (3)]));
@@ -2238,95 +2264,95 @@ yyreduce:
     }
     break;
 
-  case 70:
+  case 73:
 /* Line 1269 of yacc.c.  */
-#line 447 "parse-gram.y"
+#line 454 "parse-gram.y"
     {
       yyerrok;
     }
     break;
 
-  case 71:
+  case 74:
 /* Line 1269 of yacc.c.  */
-#line 453 "parse-gram.y"
+#line 460 "parse-gram.y"
     { current_lhs = (yyvsp[(1) - (1)].symbol); current_lhs_location = (yylsp[(1) - (1)]); }
     break;
 
-  case 73:
+  case 76:
 /* Line 1269 of yacc.c.  */
-#line 457 "parse-gram.y"
+#line 464 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(1) - (1)])); }
     break;
 
-  case 74:
+  case 77:
 /* Line 1269 of yacc.c.  */
-#line 458 "parse-gram.y"
+#line 465 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(3) - (3)])); }
     break;
 
-  case 76:
+  case 79:
 /* Line 1269 of yacc.c.  */
-#line 464 "parse-gram.y"
+#line 471 "parse-gram.y"
     { grammar_current_rule_begin (current_lhs, current_lhs_location); }
     break;
 
-  case 77:
+  case 80:
 /* Line 1269 of yacc.c.  */
-#line 466 "parse-gram.y"
+#line 473 "parse-gram.y"
     { grammar_current_rule_symbol_append ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)])); }
     break;
 
-  case 78:
+  case 81:
 /* Line 1269 of yacc.c.  */
-#line 468 "parse-gram.y"
+#line 475 "parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])); }
     break;
 
-  case 79:
+  case 82:
 /* Line 1269 of yacc.c.  */
-#line 470 "parse-gram.y"
+#line 477 "parse-gram.y"
     { grammar_current_rule_prec_set ((yyvsp[(3) - (3)].symbol), (yylsp[(3) - (3)])); }
     break;
 
-  case 80:
+  case 83:
 /* Line 1269 of yacc.c.  */
-#line 472 "parse-gram.y"
+#line 479 "parse-gram.y"
     { grammar_current_rule_dprec_set ((yyvsp[(3) - (3)].integer), (yylsp[(3) - (3)])); }
     break;
 
-  case 81:
+  case 84:
 /* Line 1269 of yacc.c.  */
-#line 474 "parse-gram.y"
+#line 481 "parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[(3) - (3)].uniqstr), (yylsp[(3) - (3)])); }
     break;
 
-  case 84:
+  case 87:
 /* Line 1269 of yacc.c.  */
-#line 490 "parse-gram.y"
+#line 497 "parse-gram.y"
     {
       static char one[] = "1";
       (yyval.chars) = one;
     }
     break;
 
-  case 86:
+  case 89:
 /* Line 1269 of yacc.c.  */
-#line 500 "parse-gram.y"
+#line 507 "parse-gram.y"
     {
       (yyvsp[(1) - (1)].chars)[strlen ((yyvsp[(1) - (1)].chars)) - 1] = '\n';
       (yyval.chars) = translate_code ((yyvsp[(1) - (1)].chars) + 1, (yylsp[(1) - (1)]));
     }
     break;
 
-  case 87:
+  case 90:
 /* Line 1269 of yacc.c.  */
-#line 516 "parse-gram.y"
+#line 523 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
-  case 88:
+  case 91:
 /* Line 1269 of yacc.c.  */
-#line 518 "parse-gram.y"
+#line 525 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[(1) - (1)].character)), (yylsp[(1) - (1)]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[(1) - (1)]), false);
@@ -2334,24 +2360,24 @@ yyreduce:
     }
     break;
 
-  case 89:
+  case 92:
 /* Line 1269 of yacc.c.  */
-#line 526 "parse-gram.y"
+#line 533 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
-  case 92:
+  case 95:
 /* Line 1269 of yacc.c.  */
-#line 538 "parse-gram.y"
+#line 545 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[(1) - (1)].chars)), (yylsp[(1) - (1)]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[(1) - (1)]), false);
     }
     break;
 
-  case 94:
+  case 97:
 /* Line 1269 of yacc.c.  */
-#line 547 "parse-gram.y"
+#line 554 "parse-gram.y"
     {
       muscle_code_grow ("epilogue", translate_code ((yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])), (yylsp[(2) - (2)]));
       gram_scanner_last_string_free ();
@@ -2360,7 +2386,7 @@ yyreduce:
 
 
 /* Line 1269 of yacc.c.  */
-#line 2364 "parse-gram.c"
+#line 2390 "parse-gram.c"
       default: break;
     }
   YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);
@@ -2578,7 +2604,7 @@ yyreturn:
 
 
 /* Line 1486 of yacc.c.  */
-#line 553 "parse-gram.y"
+#line 560 "parse-gram.y"
 
 
 
