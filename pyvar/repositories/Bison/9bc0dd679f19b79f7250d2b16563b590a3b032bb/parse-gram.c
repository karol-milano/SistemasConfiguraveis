@@ -68,123 +68,8 @@
 #define yynerrs gram_nerrs
 #define yylloc gram_lloc
 
-/* Tokens.  */
-#ifndef YYTOKENTYPE
-# define YYTOKENTYPE
-   /* Put the tokens into the symbol table, so that GDB and other debuggers
-      know about them.  */
-   enum yytokentype {
-     GRAM_EOF = 0,
-     STRING = 258,
-     INT = 259,
-     PERCENT_TOKEN = 260,
-     PERCENT_NTERM = 261,
-     PERCENT_TYPE = 262,
-     PERCENT_DESTRUCTOR = 263,
-     PERCENT_PRINTER = 264,
-     PERCENT_LEFT = 265,
-     PERCENT_RIGHT = 266,
-     PERCENT_NONASSOC = 267,
-     PERCENT_PREC = 268,
-     PERCENT_DPREC = 269,
-     PERCENT_MERGE = 270,
-     PERCENT_DEBUG = 271,
-     PERCENT_DEFAULT_PREC = 272,
-     PERCENT_DEFINE = 273,
-     PERCENT_DEFINES = 274,
-     PERCENT_ERROR_VERBOSE = 275,
-     PERCENT_EXPECT = 276,
-     PERCENT_EXPECT_RR = 277,
-     PERCENT_FILE_PREFIX = 278,
-     PERCENT_GLR_PARSER = 279,
-     PERCENT_INITIAL_ACTION = 280,
-     PERCENT_LEX_PARAM = 281,
-     PERCENT_LOCATIONS = 282,
-     PERCENT_NAME_PREFIX = 283,
-     PERCENT_NO_DEFAULT_PREC = 284,
-     PERCENT_NO_LINES = 285,
-     PERCENT_NONDETERMINISTIC_PARSER = 286,
-     PERCENT_OUTPUT = 287,
-     PERCENT_PARSE_PARAM = 288,
-     PERCENT_PURE_PARSER = 289,
-     PERCENT_REQUIRE = 290,
-     PERCENT_SKELETON = 291,
-     PERCENT_START = 292,
-     PERCENT_TOKEN_TABLE = 293,
-     PERCENT_VERBOSE = 294,
-     PERCENT_YACC = 295,
-     BRACED_CODE = 296,
-     CHAR = 297,
-     EPILOGUE = 298,
-     EQUAL = 299,
-     ID = 300,
-     ID_COLON = 301,
-     PERCENT_PERCENT = 302,
-     PIPE = 303,
-     PROLOGUE = 304,
-     SEMICOLON = 305,
-     TYPE = 306,
-     PERCENT_UNION = 307
-   };
-#endif
-/* Tokens.  */
-#define GRAM_EOF 0
-#define STRING 258
-#define INT 259
-#define PERCENT_TOKEN 260
-#define PERCENT_NTERM 261
-#define PERCENT_TYPE 262
-#define PERCENT_DESTRUCTOR 263
-#define PERCENT_PRINTER 264
-#define PERCENT_LEFT 265
-#define PERCENT_RIGHT 266
-#define PERCENT_NONASSOC 267
-#define PERCENT_PREC 268
-#define PERCENT_DPREC 269
-#define PERCENT_MERGE 270
-#define PERCENT_DEBUG 271
-#define PERCENT_DEFAULT_PREC 272
-#define PERCENT_DEFINE 273
-#define PERCENT_DEFINES 274
-#define PERCENT_ERROR_VERBOSE 275
-#define PERCENT_EXPECT 276
-#define PERCENT_EXPECT_RR 277
-#define PERCENT_FILE_PREFIX 278
-#define PERCENT_GLR_PARSER 279
-#define PERCENT_INITIAL_ACTION 280
-#define PERCENT_LEX_PARAM 281
-#define PERCENT_LOCATIONS 282
-#define PERCENT_NAME_PREFIX 283
-#define PERCENT_NO_DEFAULT_PREC 284
-#define PERCENT_NO_LINES 285
-#define PERCENT_NONDETERMINISTIC_PARSER 286
-#define PERCENT_OUTPUT 287
-#define PERCENT_PARSE_PARAM 288
-#define PERCENT_PURE_PARSER 289
-#define PERCENT_REQUIRE 290
-#define PERCENT_SKELETON 291
-#define PERCENT_START 292
-#define PERCENT_TOKEN_TABLE 293
-#define PERCENT_VERBOSE 294
-#define PERCENT_YACC 295
-#define BRACED_CODE 296
-#define CHAR 297
-#define EPILOGUE 298
-#define EQUAL 299
-#define ID 300
-#define ID_COLON 301
-#define PERCENT_PERCENT 302
-#define PIPE 303
-#define PROLOGUE 304
-#define SEMICOLON 305
-#define TYPE 306
-#define PERCENT_UNION 307
-
-
-
-
 /* Copy the first part of user declarations.  */
-#line 1 "../../src/parse-gram.y"
+#line 1 "parse-gram.y"
 /* Bison Grammar Parser                             -*- C -*-
 
    Copyright (C) 2002, 2003, 2004, 2005, 2006 Free Software Foundation, Inc.
@@ -280,9 +165,129 @@ static int current_prec = 0;
 # define YYTOKEN_TABLE 0
 #endif
 
+
+/* Tokens.  */
+#ifndef YYTOKENTYPE
+# define YYTOKENTYPE
+   /* Put the tokens into the symbol table, so that GDB and other debuggers
+      know about them.  */
+   enum yytokentype {
+     GRAM_EOF = 0,
+     STRING = 258,
+     INT = 259,
+     PERCENT_TOKEN = 260,
+     PERCENT_NTERM = 261,
+     PERCENT_TYPE = 262,
+     PERCENT_DESTRUCTOR = 263,
+     PERCENT_PRINTER = 264,
+     PERCENT_LEFT = 265,
+     PERCENT_RIGHT = 266,
+     PERCENT_NONASSOC = 267,
+     PERCENT_PREC = 268,
+     PERCENT_DPREC = 269,
+     PERCENT_MERGE = 270,
+     PERCENT_AFTER_DEFINITIONS = 271,
+     PERCENT_BEFORE_DEFINITIONS = 272,
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
+     PERCENT_PURE_PARSER = 291,
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
+     PERCENT_UNION = 309
+   };
+#endif
+/* Tokens.  */
+#define GRAM_EOF 0
+#define STRING 258
+#define INT 259
+#define PERCENT_TOKEN 260
+#define PERCENT_NTERM 261
+#define PERCENT_TYPE 262
+#define PERCENT_DESTRUCTOR 263
+#define PERCENT_PRINTER 264
+#define PERCENT_LEFT 265
+#define PERCENT_RIGHT 266
+#define PERCENT_NONASSOC 267
+#define PERCENT_PREC 268
+#define PERCENT_DPREC 269
+#define PERCENT_MERGE 270
+#define PERCENT_AFTER_DEFINITIONS 271
+#define PERCENT_BEFORE_DEFINITIONS 272
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
+#define PERCENT_PURE_PARSER 291
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
+#define PERCENT_UNION 309
+
+
+
+
 #if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
 typedef union YYSTYPE
-#line 97 "../../src/parse-gram.y"
+#line 97 "parse-gram.y"
 {
   symbol *symbol;
   symbol_list *list;
@@ -292,8 +297,8 @@ typedef union YYSTYPE
   uniqstr uniqstr;
   unsigned char character;
 }
-/* Line 193 of yacc.c.  */
-#line 297 "../../src/parse-gram.c"
+/* Line 197 of yacc.c.  */
+#line 302 "parse-gram.c"
 	YYSTYPE;
 # define yystype YYSTYPE /* obsolescent; will be withdrawn */
 # define YYSTYPE_IS_DECLARED 1
@@ -317,8 +322,8 @@ typedef struct YYLTYPE
 /* Copy the second part of user declarations.  */
 
 
-/* Line 216 of yacc.c.  */
-#line 322 "../../src/parse-gram.c"
+/* Line __line__ of yacc.c.  */
+#line 327 "parse-gram.c"
 
 #ifdef short
 # undef short
@@ -535,20 +540,20 @@ union yyalloc
 /* YYFINAL -- State number of the termination state.  */
 #define YYFINAL  3
 /* YYLAST -- Last index in YYTABLE.  */
-#define YYLAST   134
+#define YYLAST   185
 
 /* YYNTOKENS -- Number of terminals.  */
-#define YYNTOKENS  53
+#define YYNTOKENS  55
 /* YYNNTS -- Number of nonterminals.  */
 #define YYNNTS  27
 /* YYNRULES -- Number of rules.  */
-#define YYNRULES  85
+#define YYNRULES  87
 /* YYNRULES -- Number of states.  */
-#define YYNSTATES  120
+#define YYNSTATES  124
 
 /* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
 #define YYUNDEFTOK  2
-#define YYMAXUTOK   307
+#define YYMAXUTOK   309
 
 #define YYTRANSLATE(YYX)						\
   ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)
@@ -586,7 +591,7 @@ static const yytype_uint8 yytranslate[] =
       15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
       25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
       35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
-      45,    46,    47,    48,    49,    50,    51,    52
+      45,    46,    47,    48,    49,    50,    51,    52,    53,    54
 };
 
 #if YYDEBUG
@@ -594,57 +599,57 @@ static const yytype_uint8 yytranslate[] =
    YYRHS.  */
 static const yytype_uint8 yyprhs[] =
 {
-       0,     0,     3,     8,     9,    12,    14,    16,    18,    21,
-      25,    27,    29,    32,    35,    39,    41,    44,    47,    49,
-      53,    55,    57,    61,    64,    66,    69,    72,    74,    76,
-      78,    80,    82,    84,    87,    91,    95,    97,    99,   100,
-     102,   106,   107,   111,   112,   116,   120,   124,   126,   128,
-     130,   131,   133,   135,   138,   140,   142,   145,   148,   152,
-     154,   157,   159,   162,   164,   167,   170,   171,   175,   177,
-     181,   184,   185,   188,   191,   195,   199,   203,   205,   207,
-     209,   211,   213,   215,   217,   218
+       0,     0,     3,     8,     9,    12,    14,    16,    19,    22,
+      24,    27,    31,    33,    35,    38,    41,    45,    47,    50,
+      53,    55,    59,    61,    63,    67,    70,    72,    75,    78,
+      80,    82,    84,    86,    88,    90,    93,    97,   101,   103,
+     105,   106,   108,   112,   113,   117,   118,   122,   126,   130,
+     132,   134,   136,   137,   139,   141,   144,   146,   148,   151,
+     154,   158,   160,   163,   165,   168,   170,   173,   176,   177,
+     181,   183,   187,   190,   191,   194,   197,   201,   205,   209,
+     211,   213,   215,   217,   219,   221,   223,   224
 };
 
 /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
 static const yytype_int8 yyrhs[] =
 {
-      54,     0,    -1,    55,    47,    68,    79,    -1,    -1,    55,
-      56,    -1,    57,    -1,    49,    -1,    16,    -1,    18,    78,
-      -1,    18,    78,    78,    -1,    19,    -1,    20,    -1,    21,
-       4,    -1,    22,     4,    -1,    23,    44,    78,    -1,    24,
-      -1,    25,    41,    -1,    26,    41,    -1,    27,    -1,    28,
-      44,    78,    -1,    30,    -1,    31,    -1,    32,    44,    78,
-      -1,    33,    41,    -1,    34,    -1,    35,    78,    -1,    36,
-      78,    -1,    38,    -1,    39,    -1,    40,    -1,    50,    -1,
-      62,    -1,    59,    -1,    37,    76,    -1,     8,    41,    65,
-      -1,     9,    41,    65,    -1,    17,    -1,    29,    -1,    -1,
-      45,    -1,    52,    58,    41,    -1,    -1,     6,    60,    67,
-      -1,    -1,     5,    61,    67,    -1,     7,    51,    65,    -1,
-      63,    64,    65,    -1,    10,    -1,    11,    -1,    12,    -1,
-      -1,    51,    -1,    76,    -1,    65,    76,    -1,    51,    -1,
-      74,    -1,    74,     4,    -1,    74,    77,    -1,    74,     4,
-      77,    -1,    66,    -1,    67,    66,    -1,    69,    -1,    68,
-      69,    -1,    70,    -1,    57,    50,    -1,     1,    50,    -1,
-      -1,    75,    71,    72,    -1,    73,    -1,    72,    48,    73,
-      -1,    72,    50,    -1,    -1,    73,    76,    -1,    73,    41,
-      -1,    73,    13,    76,    -1,    73,    14,     4,    -1,    73,
-      15,    51,    -1,    45,    -1,    42,    -1,    46,    -1,    74,
-      -1,    77,    -1,     3,    -1,     3,    -1,    -1,    47,    43,
-      -1
+      56,     0,    -1,    57,    49,    70,    81,    -1,    -1,    57,
+      58,    -1,    59,    -1,    51,    -1,    16,    43,    -1,    17,
+      43,    -1,    18,    -1,    20,    80,    -1,    20,    80,    80,
+      -1,    21,    -1,    22,    -1,    23,     4,    -1,    24,     4,
+      -1,    25,    46,    80,    -1,    26,    -1,    27,    43,    -1,
+      28,    43,    -1,    29,    -1,    30,    46,    80,    -1,    32,
+      -1,    33,    -1,    34,    46,    80,    -1,    35,    43,    -1,
+      36,    -1,    37,    80,    -1,    38,    80,    -1,    40,    -1,
+      41,    -1,    42,    -1,    52,    -1,    64,    -1,    61,    -1,
+      39,    78,    -1,     8,    43,    67,    -1,     9,    43,    67,
+      -1,    19,    -1,    31,    -1,    -1,    47,    -1,    54,    60,
+      43,    -1,    -1,     6,    62,    69,    -1,    -1,     5,    63,
+      69,    -1,     7,    53,    67,    -1,    65,    66,    67,    -1,
+      10,    -1,    11,    -1,    12,    -1,    -1,    53,    -1,    78,
+      -1,    67,    78,    -1,    53,    -1,    76,    -1,    76,     4,
+      -1,    76,    79,    -1,    76,     4,    79,    -1,    68,    -1,
+      69,    68,    -1,    71,    -1,    70,    71,    -1,    72,    -1,
+      59,    52,    -1,     1,    52,    -1,    -1,    77,    73,    74,
+      -1,    75,    -1,    74,    50,    75,    -1,    74,    52,    -1,
+      -1,    75,    78,    -1,    75,    43,    -1,    75,    13,    78,
+      -1,    75,    14,     4,    -1,    75,    15,    53,    -1,    47,
+      -1,    44,    -1,    48,    -1,    76,    -1,    79,    -1,     3,
+      -1,     3,    -1,    -1,    49,    45,    -1
 };
 
 /* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
 static const yytype_uint16 yyrline[] =
 {
-       0,   198,   198,   206,   208,   212,   213,   215,   216,   221,
-     222,   223,   224,   225,   226,   227,   232,   236,   237,   238,
-     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
-     249,   253,   254,   255,   259,   267,   275,   279,   293,   294,
-     298,   320,   320,   325,   325,   330,   340,   355,   356,   357,
-     361,   362,   367,   368,   373,   377,   382,   388,   394,   405,
-     406,   415,   416,   422,   423,   424,   431,   431,   435,   436,
-     437,   442,   443,   445,   448,   450,   452,   465,   467,   476,
-     481,   482,   487,   496,   501,   503
+       0,   202,   202,   210,   212,   216,   217,   219,   226,   233,
+     234,   239,   240,   241,   242,   243,   244,   245,   250,   254,
+     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
+     265,   266,   267,   271,   272,   273,   277,   285,   293,   297,
+     311,   312,   316,   338,   338,   343,   343,   348,   358,   373,
+     374,   375,   379,   380,   385,   386,   391,   395,   400,   406,
+     412,   423,   424,   433,   434,   440,   441,   442,   449,   449,
+     453,   454,   455,   460,   461,   463,   466,   468,   470,   483,
+     485,   494,   499,   500,   505,   514,   519,   521
 };
 #endif
 
@@ -656,7 +661,8 @@ static const char *const yytname[] =
   "\"end of file\"", "error", "$undefined", "\"string\"", "\"integer\"",
   "\"%token\"", "\"%nterm\"", "\"%type\"", "\"%destructor\"",
   "\"%printer\"", "\"%left\"", "\"%right\"", "\"%nonassoc\"", "\"%prec\"",
-  "\"%dprec\"", "\"%merge\"", "\"%debug\"", "\"%default-prec\"",
+  "\"%dprec\"", "\"%merge\"", "\"%after-definitions\"",
+  "\"%before-definitions\"", "\"%debug\"", "\"%default-prec\"",
   "\"%define\"", "\"%defines\"", "\"%error-verbose\"", "\"%expect\"",
   "\"%expect-rr\"", "\"%file-prefix\"", "\"%glr-parser\"",
   "\"%initial-action\"", "\"%lex-param\"", "\"%locations\"",
@@ -685,36 +691,36 @@ static const yytype_uint16 yytoknum[] =
      275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
      285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
      295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
-     305,   306,   307
+     305,   306,   307,   308,   309
 };
 # endif
 
 /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
 static const yytype_uint8 yyr1[] =
 {
-       0,    53,    54,    55,    55,    56,    56,    56,    56,    56,
-      56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
-      56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
-      56,    57,    57,    57,    57,    57,    57,    57,    58,    58,
-      57,    60,    59,    61,    59,    59,    62,    63,    63,    63,
-      64,    64,    65,    65,    66,    66,    66,    66,    66,    67,
-      67,    68,    68,    69,    69,    69,    71,    70,    72,    72,
-      72,    73,    73,    73,    73,    73,    73,    74,    74,    75,
-      76,    76,    77,    78,    79,    79
+       0,    55,    56,    57,    57,    58,    58,    58,    58,    58,
+      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
+      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
+      58,    58,    58,    59,    59,    59,    59,    59,    59,    59,
+      60,    60,    59,    62,    61,    63,    61,    61,    64,    65,
+      65,    65,    66,    66,    67,    67,    68,    68,    68,    68,
+      68,    69,    69,    70,    70,    71,    71,    71,    73,    72,
+      74,    74,    74,    75,    75,    75,    75,    75,    75,    76,
+      76,    77,    78,    78,    79,    80,    81,    81
 };
 
 /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
 static const yytype_uint8 yyr2[] =
 {
-       0,     2,     4,     0,     2,     1,     1,     1,     2,     3,
-       1,     1,     2,     2,     3,     1,     2,     2,     1,     3,
-       1,     1,     3,     2,     1,     2,     2,     1,     1,     1,
-       1,     1,     1,     2,     3,     3,     1,     1,     0,     1,
-       3,     0,     3,     0,     3,     3,     3,     1,     1,     1,
-       0,     1,     1,     2,     1,     1,     2,     2,     3,     1,
-       2,     1,     2,     1,     2,     2,     0,     3,     1,     3,
-       2,     0,     2,     2,     3,     3,     3,     1,     1,     1,
-       1,     1,     1,     1,     0,     2
+       0,     2,     4,     0,     2,     1,     1,     2,     2,     1,
+       2,     3,     1,     1,     2,     2,     3,     1,     2,     2,
+       1,     3,     1,     1,     3,     2,     1,     2,     2,     1,
+       1,     1,     1,     1,     1,     2,     3,     3,     1,     1,
+       0,     1,     3,     0,     3,     0,     3,     3,     3,     1,
+       1,     1,     0,     1,     1,     2,     1,     1,     2,     2,
+       3,     1,     2,     1,     2,     1,     2,     2,     0,     3,
+       1,     3,     2,     0,     2,     2,     3,     3,     3,     1,
+       1,     1,     1,     1,     1,     1,     0,     2
 };
 
 /* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
@@ -722,112 +728,125 @@ static const yytype_uint8 yyr2[] =
    means the default is an error.  */
 static const yytype_uint8 yydefact[] =
 {
-       3,     0,     0,     1,    43,    41,     0,     0,     0,    47,
-      48,    49,     7,    36,     0,    10,    11,     0,     0,     0,
-      15,     0,     0,    18,     0,    37,    20,    21,     0,     0,
-      24,     0,     0,     0,    27,    28,    29,     0,     6,    30,
-      38,     4,     5,    32,    31,    50,     0,     0,     0,     0,
-       0,    83,     8,    12,    13,     0,    16,    17,     0,     0,
-      23,    25,    26,    82,    78,    77,    80,    33,    81,     0,
-      79,     0,     0,    61,    63,    66,    39,     0,    51,     0,
-      54,    59,    44,    55,    42,    45,    52,    34,    35,     9,
-      14,    19,    22,    65,    64,     0,    62,     2,    71,    40,
-      46,    60,    56,    57,    53,    85,    67,    68,    58,    71,
-      70,     0,     0,     0,    73,    72,    69,    74,    75,    76
+       3,     0,     0,     1,    45,    43,     0,     0,     0,    49,
+      50,    51,     0,     0,     9,    38,     0,    12,    13,     0,
+       0,     0,    17,     0,     0,    20,     0,    39,    22,    23,
+       0,     0,    26,     0,     0,     0,    29,    30,    31,     0,
+       6,    32,    40,     4,     5,    34,    33,    52,     0,     0,
+       0,     0,     0,     7,     8,    85,    10,    14,    15,     0,
+      18,    19,     0,     0,    25,    27,    28,    84,    80,    79,
+      82,    35,    83,     0,    81,     0,     0,    63,    65,    68,
+      41,     0,    53,     0,    56,    61,    46,    57,    44,    47,
+      54,    36,    37,    11,    16,    21,    24,    67,    66,     0,
+      64,     2,    73,    42,    48,    62,    58,    59,    55,    87,
+      69,    70,    60,    73,    72,     0,     0,     0,    75,    74,
+      71,    76,    77,    78
 };
 
 /* YYDEFGOTO[NTERM-NUM].  */
 static const yytype_int8 yydefgoto[] =
 {
-      -1,     1,     2,    41,    71,    77,    43,    47,    46,    44,
-      45,    79,    85,    81,    82,    72,    73,    74,    98,   106,
-     107,    66,    75,    86,    68,    52,    97
+      -1,     1,     2,    43,    75,    81,    45,    49,    48,    46,
+      47,    83,    89,    85,    86,    76,    77,    78,   102,   110,
+     111,    70,    79,    90,    72,    56,   101
 };
 
 /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
    STATE-NUM.  */
-#define YYPACT_NINF -70
-static const yytype_int8 yypact[] =
+#define YYPACT_NINF -74
+static const yytype_int16 yypact[] =
 {
-     -70,     5,    79,   -70,   -70,   -70,   -19,    -4,     8,   -70,
-     -70,   -70,   -70,   -70,    47,   -70,   -70,    54,    61,    25,
-     -70,    38,    39,   -70,    37,   -70,   -70,   -70,    48,    41,
-     -70,    47,    47,    26,   -70,   -70,   -70,    14,   -70,   -70,
-      49,   -70,   -70,   -70,   -70,    42,    19,    19,    26,    26,
-      26,   -70,    47,   -70,   -70,    47,   -70,   -70,    47,    47,
-     -70,   -70,   -70,   -70,   -70,   -70,   -70,   -70,   -70,    70,
-     -70,    71,     1,   -70,   -70,   -70,   -70,    81,   -70,    26,
-     -70,   -70,    19,    13,    19,    26,   -70,    26,    26,   -70,
-     -70,   -70,   -70,   -70,   -70,    80,   -70,   -70,   -70,   -70,
-      26,   -70,   121,   -70,   -70,   -70,    -8,    31,   -70,   -70,
-     -70,    26,   123,    74,   -70,   -70,    31,   -70,   -70,   -70
+     -74,    34,   131,   -74,   -74,   -74,   -38,    -5,    -2,   -74,
+     -74,   -74,     5,     8,   -74,   -74,    40,   -74,   -74,    48,
+      49,    14,   -74,    21,    22,   -74,    20,   -74,   -74,   -74,
+      24,    25,   -74,    40,    40,     0,   -74,   -74,   -74,    81,
+     -74,   -74,    26,   -74,   -74,   -74,   -74,    18,   -22,   -22,
+       0,     0,     0,   -74,   -74,   -74,    40,   -74,   -74,    40,
+     -74,   -74,    40,    40,   -74,   -74,   -74,   -74,   -74,   -74,
+     -74,   -74,   -74,    27,   -74,    29,     1,   -74,   -74,   -74,
+     -74,    31,   -74,     0,   -74,   -74,   -22,    23,   -22,     0,
+     -74,     0,     0,   -74,   -74,   -74,   -74,   -74,   -74,    30,
+     -74,   -74,   -74,   -74,     0,   -74,    64,   -74,   -74,   -74,
+     -31,    15,   -74,   -74,   -74,     0,    68,    41,   -74,   -74,
+      15,   -74,   -74,   -74
 };
 
 /* YYPGOTO[NTERM-NUM].  */
-static const yytype_int16 yypgoto[] =
+static const yytype_int8 yypgoto[] =
 {
-     -70,   -70,   -70,   -70,   128,   -70,   -70,   -70,   -70,   -70,
-     -70,   -70,   -22,    -7,    85,   -70,    62,   -70,   -70,   -70,
-      24,   -43,   -70,   -33,   -69,     4,   -70
+     -74,   -74,   -74,   -74,    75,   -74,   -74,   -74,   -74,   -74,
+     -74,   -74,   -47,   -51,    35,   -74,     2,   -74,   -74,   -74,
+     -30,   -25,   -74,   -35,   -73,   -17,   -74
 };
 
 /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
    positive, shift that token.  If negative, reduce the rule which
    number is the opposite.  If zero, do what YYDEFACT says.
    If YYTABLE_NINF, syntax error.  */
-#define YYTABLE_NINF -85
+#define YYTABLE_NINF -87
 static const yytype_int8 yytable[] =
 {
-      67,   -84,    69,    83,    83,     3,     4,     5,     6,     7,
-       8,     9,    10,    11,   103,    69,    63,   102,    13,     4,
-       5,     6,     7,     8,     9,    10,    11,    87,    88,    63,
-      25,    13,    48,   108,    63,    61,    62,    49,    33,    83,
-     109,    83,   110,    25,   111,   112,   113,    70,    95,    50,
-      51,    33,   104,    40,   104,   104,    89,   100,    53,    90,
-      70,    64,    91,    92,    65,    54,    40,   104,    64,    55,
-      80,    65,   114,    64,   115,   101,    65,   101,   117,    56,
-      57,    58,    60,   115,     4,     5,     6,     7,     8,     9,
-      10,    11,    59,    78,    76,    12,    13,    14,    15,    16,
-      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
-      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
-      93,    94,    99,   105,    63,   119,    37,   118,    38,    39,
-      42,    40,    84,   116,    96
+      71,   -86,    73,    67,    91,    92,     4,     5,     6,     7,
+       8,     9,    10,    11,   107,    50,    65,    66,    67,   113,
+      15,   114,    68,    87,    87,    69,    67,   106,   115,   116,
+     117,    84,    27,   112,     3,   105,   104,   105,    51,    93,
+      35,    52,    94,    55,    68,    95,    96,    69,    53,    74,
+      99,    54,    57,    58,   108,    42,   108,   108,   118,    68,
+      59,    87,    69,    87,    60,    61,    62,    67,    64,   108,
+      63,    82,   122,    80,   103,   109,   119,    44,   100,    97,
+     121,    98,    73,   120,    88,   119,     4,     5,     6,     7,
+       8,     9,    10,    11,   123,     0,     0,     0,     0,     0,
+      15,     0,     0,     0,     0,     0,     0,     0,     0,     0,
+       0,     0,    27,     0,     0,     0,     0,     0,     0,     0,
+      35,     0,     0,     0,     0,     0,     0,     0,     0,    74,
+       0,     0,     0,     0,     0,    42,     4,     5,     6,     7,
+       8,     9,    10,    11,     0,     0,     0,    12,    13,    14,
+      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
+      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
+      35,    36,    37,    38,     0,     0,     0,     0,     0,     0,
+      39,     0,    40,    41,     0,    42
 };
 
-static const yytype_uint8 yycheck[] =
+static const yytype_int8 yycheck[] =
 {
-      33,     0,     1,    46,    47,     0,     5,     6,     7,     8,
-       9,    10,    11,    12,    83,     1,     3,     4,    17,     5,
-       6,     7,     8,     9,    10,    11,    12,    49,    50,     3,
-      29,    17,    51,   102,     3,    31,    32,    41,    37,    82,
-      48,    84,    50,    29,    13,    14,    15,    46,    47,    41,
-       3,    37,    85,    52,    87,    88,    52,    79,     4,    55,
-      46,    42,    58,    59,    45,     4,    52,   100,    42,    44,
-      51,    45,    41,    42,   107,    82,    45,    84,   111,    41,
-      41,    44,    41,   116,     5,     6,     7,     8,     9,    10,
-      11,    12,    44,    51,    45,    16,    17,    18,    19,    20,
-      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
-      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
-      50,    50,    41,    43,     3,    51,    47,     4,    49,    50,
-       2,    52,    47,   109,    72
+      35,     0,     1,     3,    51,    52,     5,     6,     7,     8,
+       9,    10,    11,    12,    87,    53,    33,    34,     3,    50,
+      19,    52,    44,    48,    49,    47,     3,     4,    13,    14,
+      15,    53,    31,   106,     0,    86,    83,    88,    43,    56,
+      39,    43,    59,     3,    44,    62,    63,    47,    43,    48,
+      49,    43,     4,     4,    89,    54,    91,    92,    43,    44,
+      46,    86,    47,    88,    43,    43,    46,     3,    43,   104,
+      46,    53,     4,    47,    43,    45,   111,     2,    76,    52,
+     115,    52,     1,   113,    49,   120,     5,     6,     7,     8,
+       9,    10,    11,    12,    53,    -1,    -1,    -1,    -1,    -1,
+      19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
+      -1,    -1,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
+      39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,
+      -1,    -1,    -1,    -1,    -1,    54,     5,     6,     7,     8,
+       9,    10,    11,    12,    -1,    -1,    -1,    16,    17,    18,
+      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
+      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
+      39,    40,    41,    42,    -1,    -1,    -1,    -1,    -1,    -1,
+      49,    -1,    51,    52,    -1,    54
 };
 
 /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
    symbol of state STATE-NUM.  */
 static const yytype_uint8 yystos[] =
 {
-       0,    54,    55,     0,     5,     6,     7,     8,     9,    10,
+       0,    56,    57,     0,     5,     6,     7,     8,     9,    10,
       11,    12,    16,    17,    18,    19,    20,    21,    22,    23,
       24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
-      34,    35,    36,    37,    38,    39,    40,    47,    49,    50,
-      52,    56,    57,    59,    62,    63,    61,    60,    51,    41,
-      41,     3,    78,     4,     4,    44,    41,    41,    44,    44,
-      41,    78,    78,     3,    42,    45,    74,    76,    77,     1,
-      46,    57,    68,    69,    70,    75,    45,    58,    51,    64,
-      51,    66,    67,    74,    67,    65,    76,    65,    65,    78,
-      78,    78,    78,    50,    50,    47,    69,    79,    71,    41,
-      65,    66,     4,    77,    76,    43,    72,    73,    77,    48,
-      50,    13,    14,    15,    41,    76,    73,    76,     4,    51
+      34,    35,    36,    37,    38,    39,    40,    41,    42,    49,
+      51,    52,    54,    58,    59,    61,    64,    65,    63,    62,
+      53,    43,    43,    43,    43,     3,    80,     4,     4,    46,
+      43,    43,    46,    46,    43,    80,    80,     3,    44,    47,
+      76,    78,    79,     1,    48,    59,    70,    71,    72,    77,
+      47,    60,    53,    66,    53,    68,    69,    76,    69,    67,
+      78,    67,    67,    80,    80,    80,    80,    52,    52,    49,
+      71,    81,    73,    43,    67,    68,     4,    79,    78,    45,
+      74,    75,    79,    50,    52,    13,    14,    15,    43,    78,
+      75,    78,     4,    53
 };
 
 #define yyerrok		(yyerrstatus = 0)
@@ -976,74 +995,74 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
   switch (yytype)
     {
       case 3: /* "\"string\"" */
-#line 177 "../../src/parse-gram.y"
+#line 181 "parse-gram.y"
 	{ fputs (quotearg_style (c_quoting_style, (yyvaluep->chars)), stderr); };
-#line 982 "../../src/parse-gram.c"
+#line 1001 "parse-gram.c"
 	break;
       case 4: /* "\"integer\"" */
-#line 187 "../../src/parse-gram.y"
+#line 191 "parse-gram.y"
 	{ fprintf (stderr, "%d", (yyvaluep->integer)); };
-#line 987 "../../src/parse-gram.c"
+#line 1006 "parse-gram.c"
 	break;
-      case 41: /* "\"{...}\"" */
-#line 179 "../../src/parse-gram.y"
+      case 43: /* "\"{...}\"" */
+#line 183 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 992 "../../src/parse-gram.c"
+#line 1011 "parse-gram.c"
 	break;
-      case 42: /* "\"char\"" */
-#line 174 "../../src/parse-gram.y"
+      case 44: /* "\"char\"" */
+#line 178 "parse-gram.y"
 	{ fputs (char_name ((yyvaluep->character)), stderr); };
-#line 997 "../../src/parse-gram.c"
+#line 1016 "parse-gram.c"
 	break;
-      case 43: /* "\"epilogue\"" */
-#line 179 "../../src/parse-gram.y"
+      case 45: /* "\"epilogue\"" */
+#line 183 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1002 "../../src/parse-gram.c"
+#line 1021 "parse-gram.c"
 	break;
-      case 45: /* "\"identifier\"" */
-#line 183 "../../src/parse-gram.y"
+      case 47: /* "\"identifier\"" */
+#line 187 "parse-gram.y"
 	{ fputs ((yyvaluep->uniqstr), stderr); };
-#line 1007 "../../src/parse-gram.c"
+#line 1026 "parse-gram.c"
 	break;
-      case 46: /* "\"identifier:\"" */
-#line 184 "../../src/parse-gram.y"
+      case 48: /* "\"identifier:\"" */
+#line 188 "parse-gram.y"
 	{ fprintf (stderr, "%s:", (yyvaluep->uniqstr)); };
-#line 1012 "../../src/parse-gram.c"
+#line 1031 "parse-gram.c"
 	break;
-      case 49: /* "\"%{...%}\"" */
-#line 179 "../../src/parse-gram.y"
+      case 51: /* "\"%{...%}\"" */
+#line 183 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1017 "../../src/parse-gram.c"
+#line 1036 "parse-gram.c"
 	break;
-      case 51: /* "\"type\"" */
-#line 182 "../../src/parse-gram.y"
+      case 53: /* "\"type\"" */
+#line 186 "parse-gram.y"
 	{ fprintf (stderr, "<%s>", (yyvaluep->uniqstr)); };
-#line 1022 "../../src/parse-gram.c"
+#line 1041 "parse-gram.c"
 	break;
-      case 74: /* "id" */
-#line 190 "../../src/parse-gram.y"
+      case 76: /* "id" */
+#line 194 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
-#line 1027 "../../src/parse-gram.c"
+#line 1046 "parse-gram.c"
 	break;
-      case 75: /* "id_colon" */
-#line 191 "../../src/parse-gram.y"
+      case 77: /* "id_colon" */
+#line 195 "parse-gram.y"
 	{ fprintf (stderr, "%s:", (yyvaluep->symbol)->tag); };
-#line 1032 "../../src/parse-gram.c"
+#line 1051 "parse-gram.c"
 	break;
-      case 76: /* "symbol" */
-#line 190 "../../src/parse-gram.y"
+      case 78: /* "symbol" */
+#line 194 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
-#line 1037 "../../src/parse-gram.c"
+#line 1056 "parse-gram.c"
 	break;
-      case 77: /* "string_as_id" */
-#line 190 "../../src/parse-gram.y"
+      case 79: /* "string_as_id" */
+#line 194 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
-#line 1042 "../../src/parse-gram.c"
+#line 1061 "parse-gram.c"
 	break;
-      case 78: /* "string_content" */
-#line 177 "../../src/parse-gram.y"
+      case 80: /* "string_content" */
+#line 181 "parse-gram.y"
 	{ fputs (quotearg_style (c_quoting_style, (yyvaluep->chars)), stderr); };
-#line 1047 "../../src/parse-gram.c"
+#line 1066 "parse-gram.c"
 	break;
       default:
 	break;
@@ -1467,15 +1486,15 @@ yyparse ()
 #endif
 #endif
 {
-  /* The look-ahead symbol.  */
+  /* The lookahead symbol.  */
 int yychar;
 
-/* The semantic value of the look-ahead symbol.  */
+/* The semantic value of the lookahead symbol.  */
 YYSTYPE yylval;
 
 /* Number of syntax errors so far.  */
 int yynerrs;
-/* Location data for the look-ahead symbol.  */
+/* Location data for the lookahead symbol.  */
 YYLTYPE yylloc;
 
   int yystate;
@@ -1483,7 +1502,7 @@ YYLTYPE yylloc;
   int yyresult;
   /* Number of tokens to shift before error messages enabled.  */
   int yyerrstatus;
-  /* Look-ahead token as an internal (translated) token number.  */
+  /* Lookahead token as an internal (translated) token number.  */
   int yytoken = 0;
 #if YYERROR_VERBOSE
   /* Buffer for error messages, and its allocated size.  */
@@ -1553,15 +1572,15 @@ YYLTYPE yylloc;
 
 
   /* User initialization code.  */
-#line 88 "../../src/parse-gram.y"
+#line 88 "parse-gram.y"
 {
   /* Bison's grammar can initial empty locations, hence a default
      location is needed. */
   boundary_set (&yylloc.start, current_file, 1, 0);
   boundary_set (&yylloc.end, current_file, 1, 0);
 }
-/* Line 1078 of yacc.c.  */
-#line 1565 "../../src/parse-gram.c"
+/* Line 1085 of yacc.c.  */
+#line 1584 "parse-gram.c"
   yylsp[0] = yylloc;
   goto yysetstate;
 
@@ -1651,16 +1670,16 @@ YYLTYPE yylloc;
 yybackup:
 
   /* Do appropriate processing given the current state.  Read a
-     look-ahead token if we need one and don't already have one.  */
+     lookahead token if we need one and don't already have one.  */
 
-  /* First try to decide what to do without reference to look-ahead token.  */
+  /* First try to decide what to do without reference to lookahead token.  */
   yyn = yypact[yystate];
   if (yyn == YYPACT_NINF)
     goto yydefault;
 
-  /* Not known => get a look-ahead token if don't already have one.  */
+  /* Not known => get a lookahead token if don't already have one.  */
 
-  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
+  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
   if (yychar == YYEMPTY)
     {
       YYDPRINTF ((stderr, "Reading a token: "));
@@ -1700,7 +1719,7 @@ yybackup:
   if (yyerrstatus)
     yyerrstatus--;
 
-  /* Shift the look-ahead token.  */
+  /* Shift the lookahead token.  */
   YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
 
   /* Discard the shifted token unless it is eof.  */
@@ -1746,143 +1765,163 @@ yyreduce:
   switch (yyn)
     {
         case 6:
-#line 213 "../../src/parse-gram.y"
+#line 217 "parse-gram.y"
     { prologue_augment (translate_code ((yyvsp[(1) - (1)].chars), (yylsp[(1) - (1)])),
 						       (yylsp[(1) - (1)])); }
     break;
 
   case 7:
-#line 215 "../../src/parse-gram.y"
-    { debug_flag = true; }
+#line 220 "parse-gram.y"
+    {
+      after_definitions = true;
+      /* Remove the '{', and replace the '}' with '\n'.  */
+      (yyvsp[(2) - (2)].chars)[strlen ((yyvsp[(2) - (2)].chars)) - 1] = '\n';
+      muscle_code_grow ("after_definitions", (yyvsp[(2) - (2)].chars)+1, (yylsp[(2) - (2)]));
+    }
     break;
 
   case 8:
-#line 217 "../../src/parse-gram.y"
+#line 227 "parse-gram.y"
+    {
+      before_definitions = true;
+      /* Remove the '{', and replace the '}' with '\n'.  */
+      (yyvsp[(2) - (2)].chars)[strlen ((yyvsp[(2) - (2)].chars)) - 1] = '\n';
+      muscle_code_grow ("before_definitions", (yyvsp[(2) - (2)].chars)+1, (yylsp[(2) - (2)]));
+    }
+    break;
+
+  case 9:
+#line 233 "parse-gram.y"
+    { debug_flag = true; }
+    break;
+
+  case 10:
+#line 235 "parse-gram.y"
     {
       static char one[] = "1";
       muscle_insert ((yyvsp[(2) - (2)].chars), one);
     }
     break;
 
-  case 9:
-#line 221 "../../src/parse-gram.y"
+  case 11:
+#line 239 "parse-gram.y"
     { muscle_insert ((yyvsp[(2) - (3)].chars), (yyvsp[(3) - (3)].chars)); }
     break;
 
-  case 10:
-#line 222 "../../src/parse-gram.y"
+  case 12:
+#line 240 "parse-gram.y"
     { defines_flag = true; }
     break;
 
-  case 11:
-#line 223 "../../src/parse-gram.y"
+  case 13:
+#line 241 "parse-gram.y"
     { error_verbose = true; }
     break;
 
-  case 12:
-#line 224 "../../src/parse-gram.y"
+  case 14:
+#line 242 "parse-gram.y"
     { expected_sr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
-  case 13:
-#line 225 "../../src/parse-gram.y"
+  case 15:
+#line 243 "parse-gram.y"
     { expected_rr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
-  case 14:
-#line 226 "../../src/parse-gram.y"
+  case 16:
+#line 244 "parse-gram.y"
     { spec_file_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
-  case 15:
-#line 228 "../../src/parse-gram.y"
+  case 17:
+#line 246 "parse-gram.y"
     {
       nondeterministic_parser = true;
       glr_parser = true;
     }
     break;
 
-  case 16:
-#line 233 "../../src/parse-gram.y"
+  case 18:
+#line 251 "parse-gram.y"
     {
       muscle_code_grow ("initial_action", translate_symbol_action ((yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])), (yylsp[(2) - (2)]));
     }
     break;
 
-  case 17:
-#line 236 "../../src/parse-gram.y"
+  case 19:
+#line 254 "parse-gram.y"
     { add_param ("lex_param", (yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])); }
     break;
 
-  case 18:
-#line 237 "../../src/parse-gram.y"
+  case 20:
+#line 255 "parse-gram.y"
     { locations_flag = true; }
     break;
 
-  case 19:
-#line 238 "../../src/parse-gram.y"
+  case 21:
+#line 256 "parse-gram.y"
     { spec_name_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
-  case 20:
-#line 239 "../../src/parse-gram.y"
+  case 22:
+#line 257 "parse-gram.y"
     { no_lines_flag = true; }
     break;
 
-  case 21:
-#line 240 "../../src/parse-gram.y"
+  case 23:
+#line 258 "parse-gram.y"
     { nondeterministic_parser = true; }
     break;
 
-  case 22:
-#line 241 "../../src/parse-gram.y"
+  case 24:
+#line 259 "parse-gram.y"
     { spec_outfile = (yyvsp[(3) - (3)].chars); }
     break;
 
-  case 23:
-#line 242 "../../src/parse-gram.y"
+  case 25:
+#line 260 "parse-gram.y"
     { add_param ("parse_param", (yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])); }
     break;
 
-  case 24:
-#line 243 "../../src/parse-gram.y"
+  case 26:
+#line 261 "parse-gram.y"
     { pure_parser = true; }
     break;
 
-  case 25:
-#line 244 "../../src/parse-gram.y"
+  case 27:
+#line 262 "parse-gram.y"
     { version_check (&(yylsp[(2) - (2)]), (yyvsp[(2) - (2)].chars)); }
     break;
 
-  case 26:
-#line 245 "../../src/parse-gram.y"
+  case 28:
+#line 263 "parse-gram.y"
     { skeleton = (yyvsp[(2) - (2)].chars); }
     break;
 
-  case 27:
-#line 246 "../../src/parse-gram.y"
+  case 29:
+#line 264 "parse-gram.y"
     { token_table_flag = true; }
     break;
 
-  case 28:
-#line 247 "../../src/parse-gram.y"
+  case 30:
+#line 265 "parse-gram.y"
     { report_flag = report_states; }
     break;
 
-  case 29:
-#line 248 "../../src/parse-gram.y"
+  case 31:
+#line 266 "parse-gram.y"
     { yacc_flag = true; }
     break;
 
-  case 33:
-#line 256 "../../src/parse-gram.y"
+  case 35:
+#line 274 "parse-gram.y"
     {
       grammar_start_symbol_set ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]));
     }
     break;
 
-  case 34:
-#line 260 "../../src/parse-gram.y"
+  case 36:
+#line 278 "parse-gram.y"
     {
       symbol_list *list;
       const char *action = translate_symbol_action ((yyvsp[(2) - (3)].chars), (yylsp[(2) - (3)]));
@@ -1892,8 +1931,8 @@ yyreduce:
     }
     break;
 
-  case 35:
-#line 268 "../../src/parse-gram.y"
+  case 37:
+#line 286 "parse-gram.y"
     {
       symbol_list *list;
       const char *action = translate_symbol_action ((yyvsp[(2) - (3)].chars), (yylsp[(2) - (3)]));
@@ -1903,32 +1942,32 @@ yyreduce:
     }
     break;
 
-  case 36:
-#line 276 "../../src/parse-gram.y"
+  case 38:
+#line 294 "parse-gram.y"
     {
       default_prec = true;
     }
     break;
 
-  case 37:
-#line 280 "../../src/parse-gram.y"
+  case 39:
+#line 298 "parse-gram.y"
     {
       default_prec = false;
     }
     break;
 
-  case 38:
-#line 293 "../../src/parse-gram.y"
+  case 40:
+#line 311 "parse-gram.y"
     {}
     break;
 
-  case 39:
-#line 294 "../../src/parse-gram.y"
+  case 41:
+#line 312 "parse-gram.y"
     { muscle_code_grow ("union_name", (yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
-  case 40:
-#line 299 "../../src/parse-gram.y"
+  case 42:
+#line 317 "parse-gram.y"
     {
       char const *body = (yyvsp[(3) - (3)].chars);
 
@@ -1946,34 +1985,34 @@ yyreduce:
     }
     break;
 
-  case 41:
-#line 320 "../../src/parse-gram.y"
+  case 43:
+#line 338 "parse-gram.y"
     { current_class = nterm_sym; }
     break;
 
-  case 42:
-#line 321 "../../src/parse-gram.y"
+  case 44:
+#line 339 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
     break;
 
-  case 43:
-#line 325 "../../src/parse-gram.y"
+  case 45:
+#line 343 "parse-gram.y"
     { current_class = token_sym; }
     break;
 
-  case 44:
-#line 326 "../../src/parse-gram.y"
+  case 46:
+#line 344 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
     break;
 
-  case 45:
-#line 331 "../../src/parse-gram.y"
+  case 47:
+#line 349 "parse-gram.y"
     {
       symbol_list *list;
       for (list = (yyvsp[(3) - (3)].list); list; list = list->next)
@@ -1982,8 +2021,8 @@ yyreduce:
     }
     break;
 
-  case 46:
-#line 341 "../../src/parse-gram.y"
+  case 48:
+#line 359 "parse-gram.y"
     {
       symbol_list *list;
       ++current_prec;
@@ -1997,58 +2036,58 @@ yyreduce:
     }
     break;
 
-  case 47:
-#line 355 "../../src/parse-gram.y"
+  case 49:
+#line 373 "parse-gram.y"
     { (yyval.assoc) = left_assoc; }
     break;
 
-  case 48:
-#line 356 "../../src/parse-gram.y"
+  case 50:
+#line 374 "parse-gram.y"
     { (yyval.assoc) = right_assoc; }
     break;
 
-  case 49:
-#line 357 "../../src/parse-gram.y"
+  case 51:
+#line 375 "parse-gram.y"
     { (yyval.assoc) = non_assoc; }
     break;
 
-  case 50:
-#line 361 "../../src/parse-gram.y"
+  case 52:
+#line 379 "parse-gram.y"
     { current_type = NULL; }
     break;
 
-  case 51:
-#line 362 "../../src/parse-gram.y"
+  case 53:
+#line 380 "parse-gram.y"
     { current_type = (yyvsp[(1) - (1)].uniqstr); }
     break;
 
-  case 52:
-#line 367 "../../src/parse-gram.y"
+  case 54:
+#line 385 "parse-gram.y"
     { (yyval.list) = symbol_list_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
-  case 53:
-#line 368 "../../src/parse-gram.y"
+  case 55:
+#line 386 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), (yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)])); }
     break;
 
-  case 54:
-#line 374 "../../src/parse-gram.y"
+  case 56:
+#line 392 "parse-gram.y"
     {
        current_type = (yyvsp[(1) - (1)].uniqstr);
      }
     break;
 
-  case 55:
-#line 378 "../../src/parse-gram.y"
+  case 57:
+#line 396 "parse-gram.y"
     {
        symbol_class_set ((yyvsp[(1) - (1)].symbol), current_class, (yylsp[(1) - (1)]), true);
        symbol_type_set ((yyvsp[(1) - (1)].symbol), current_type, (yylsp[(1) - (1)]));
      }
     break;
 
-  case 56:
-#line 383 "../../src/parse-gram.y"
+  case 58:
+#line 401 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
       symbol_type_set ((yyvsp[(1) - (2)].symbol), current_type, (yylsp[(1) - (2)]));
@@ -2056,8 +2095,8 @@ yyreduce:
     }
     break;
 
-  case 57:
-#line 389 "../../src/parse-gram.y"
+  case 59:
+#line 407 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
       symbol_type_set ((yyvsp[(1) - (2)].symbol), current_type, (yylsp[(1) - (2)]));
@@ -2065,8 +2104,8 @@ yyreduce:
     }
     break;
 
-  case 58:
-#line 395 "../../src/parse-gram.y"
+  case 60:
+#line 413 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (3)].symbol), current_class, (yylsp[(1) - (3)]), true);
       symbol_type_set ((yyvsp[(1) - (3)].symbol), current_type, (yylsp[(1) - (3)]));
@@ -2075,66 +2114,66 @@ yyreduce:
     }
     break;
 
-  case 65:
-#line 425 "../../src/parse-gram.y"
+  case 67:
+#line 443 "parse-gram.y"
     {
       yyerrok;
     }
     break;
 
-  case 66:
-#line 431 "../../src/parse-gram.y"
+  case 68:
+#line 449 "parse-gram.y"
     { current_lhs = (yyvsp[(1) - (1)].symbol); current_lhs_location = (yylsp[(1) - (1)]); }
     break;
 
-  case 68:
-#line 435 "../../src/parse-gram.y"
+  case 70:
+#line 453 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(1) - (1)])); }
     break;
 
-  case 69:
-#line 436 "../../src/parse-gram.y"
+  case 71:
+#line 454 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(3) - (3)])); }
     break;
 
-  case 71:
-#line 442 "../../src/parse-gram.y"
+  case 73:
+#line 460 "parse-gram.y"
     { grammar_current_rule_begin (current_lhs, current_lhs_location); }
     break;
 
-  case 72:
-#line 444 "../../src/parse-gram.y"
+  case 74:
+#line 462 "parse-gram.y"
     { grammar_current_rule_symbol_append ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)])); }
     break;
 
-  case 73:
-#line 446 "../../src/parse-gram.y"
+  case 75:
+#line 464 "parse-gram.y"
     { grammar_current_rule_action_append (gram_last_string,
 					  gram_last_braced_code_loc); }
     break;
 
-  case 74:
-#line 449 "../../src/parse-gram.y"
+  case 76:
+#line 467 "parse-gram.y"
     { grammar_current_rule_prec_set ((yyvsp[(3) - (3)].symbol), (yylsp[(3) - (3)])); }
     break;
 
-  case 75:
-#line 451 "../../src/parse-gram.y"
+  case 77:
+#line 469 "parse-gram.y"
     { grammar_current_rule_dprec_set ((yyvsp[(3) - (3)].integer), (yylsp[(3) - (3)])); }
     break;
 
-  case 76:
-#line 453 "../../src/parse-gram.y"
+  case 78:
+#line 471 "parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[(3) - (3)].uniqstr), (yylsp[(3) - (3)])); }
     break;
 
-  case 77:
-#line 466 "../../src/parse-gram.y"
+  case 79:
+#line 484 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
-  case 78:
-#line 468 "../../src/parse-gram.y"
+  case 80:
+#line 486 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[(1) - (1)].character)), (yylsp[(1) - (1)]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[(1) - (1)]), false);
@@ -2142,26 +2181,26 @@ yyreduce:
     }
     break;
 
-  case 79:
-#line 476 "../../src/parse-gram.y"
+  case 81:
+#line 494 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
-  case 82:
-#line 488 "../../src/parse-gram.y"
+  case 84:
+#line 506 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[(1) - (1)].chars)), (yylsp[(1) - (1)]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[(1) - (1)]), false);
     }
     break;
 
-  case 83:
-#line 497 "../../src/parse-gram.y"
+  case 85:
+#line 515 "parse-gram.y"
     { (yyval.chars) = (yyvsp[(1) - (1)].chars); }
     break;
 
-  case 85:
-#line 504 "../../src/parse-gram.y"
+  case 87:
+#line 522 "parse-gram.y"
     {
       muscle_code_grow ("epilogue", translate_code ((yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])), (yylsp[(2) - (2)]));
       gram_scanner_last_string_free ();
@@ -2169,8 +2208,8 @@ yyreduce:
     break;
 
 
-/* Line 1267 of yacc.c.  */
-#line 2174 "../../src/parse-gram.c"
+/* Line 1274 of yacc.c.  */
+#line 2213 "parse-gram.c"
       default: break;
     }
   YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);
@@ -2246,7 +2285,7 @@ yyerrlab:
 
   if (yyerrstatus == 3)
     {
-      /* If just tried and failed to reuse look-ahead token after an
+      /* If just tried and failed to reuse lookahead token after an
 	 error, discard it.  */
 
       if (yychar <= YYEOF)
@@ -2263,7 +2302,7 @@ yyerrlab:
 	}
     }
 
-  /* Else will try to reuse look-ahead token after shifting the error
+  /* Else will try to reuse lookahead token after shifting the error
      token.  */
   goto yyerrlab1;
 
@@ -2328,7 +2367,7 @@ yyerrlab1:
 
   yyerror_range[1] = yylloc;
   /* Using YYLLOC is tempting, but would change the location of
-     the look-ahead.  YYLOC is available though.  */
+     the lookahead.  YYLOC is available though.  */
   YYLLOC_DEFAULT (yyloc, (yyerror_range - 1), 2);
   *++yylsp = yyloc;
 
@@ -2390,7 +2429,7 @@ yyreturn:
 }
 
 
-#line 510 "../../src/parse-gram.y"
+#line 528 "parse-gram.y"
 
 
 
