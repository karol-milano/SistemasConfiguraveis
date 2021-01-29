@@ -1,4 +1,4 @@
-/* A Bison parser, made from parse-gram.y, by GNU bison 1.75a.  */
+/* A Bison parser, made by GNU Bison 1.75b.  */
 
 /* Skeleton parser for Yacc-like parsing with Bison,
    Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002 Free Software Foundation, Inc.
@@ -34,10 +34,13 @@
    USER NAME SPACE" below.  */
 
 /* Identify Bison output.  */
-#define YYBISON	1
+#define YYBISON 1
+
+/* Skeleton name.  */
+#define YYSKELETON_NAME "yacc.c"
 
 /* Pure parsers.  */
-#define YYPURE	1
+#define YYPURE 1
 
 /* Using locations.  */
 #define YYLSP_NEEDED 1
@@ -61,98 +64,96 @@
    enum yytokentype {
      GRAM_EOF = 0,
      STRING = 258,
-     CHARACTER = 259,
-     INT = 260,
-     PERCENT_TOKEN = 261,
-     PERCENT_NTERM = 262,
-     PERCENT_TYPE = 263,
-     PERCENT_DESTRUCTOR = 264,
-     PERCENT_PRINTER = 265,
-     PERCENT_UNION = 266,
-     PERCENT_LEFT = 267,
-     PERCENT_RIGHT = 268,
-     PERCENT_NONASSOC = 269,
-     PERCENT_PREC = 270,
-     PERCENT_DPREC = 271,
-     PERCENT_MERGE = 272,
-     PERCENT_DEBUG = 273,
-     PERCENT_DEFINE = 274,
-     PERCENT_DEFINES = 275,
-     PERCENT_ERROR_VERBOSE = 276,
-     PERCENT_EXPECT = 277,
-     PERCENT_FILE_PREFIX = 278,
-     PERCENT_GLR_PARSER = 279,
-     PERCENT_LEX_PARAM = 280,
-     PERCENT_LOCATIONS = 281,
-     PERCENT_NAME_PREFIX = 282,
-     PERCENT_NO_LINES = 283,
-     PERCENT_OUTPUT = 284,
-     PERCENT_PARSE_PARAM = 285,
-     PERCENT_PURE_PARSER = 286,
-     PERCENT_SKELETON = 287,
-     PERCENT_START = 288,
-     PERCENT_TOKEN_TABLE = 289,
-     PERCENT_VERBOSE = 290,
-     PERCENT_YACC = 291,
-     TYPE = 292,
-     EQUAL = 293,
-     SEMICOLON = 294,
-     COLON = 295,
-     COMMA = 296,
-     PIPE = 297,
-     ID = 298,
-     PERCENT_PERCENT = 299,
-     PROLOGUE = 300,
-     EPILOGUE = 301,
-     BRACED_CODE = 302
+     INT = 259,
+     PERCENT_TOKEN = 260,
+     PERCENT_NTERM = 261,
+     PERCENT_TYPE = 262,
+     PERCENT_DESTRUCTOR = 263,
+     PERCENT_PRINTER = 264,
+     PERCENT_UNION = 265,
+     PERCENT_LEFT = 266,
+     PERCENT_RIGHT = 267,
+     PERCENT_NONASSOC = 268,
+     PERCENT_PREC = 269,
+     PERCENT_DPREC = 270,
+     PERCENT_MERGE = 271,
+     PERCENT_DEBUG = 272,
+     PERCENT_DEFINE = 273,
+     PERCENT_DEFINES = 274,
+     PERCENT_ERROR_VERBOSE = 275,
+     PERCENT_EXPECT = 276,
+     PERCENT_FILE_PREFIX = 277,
+     PERCENT_GLR_PARSER = 278,
+     PERCENT_LEX_PARAM = 279,
+     PERCENT_LOCATIONS = 280,
+     PERCENT_NAME_PREFIX = 281,
+     PERCENT_NO_LINES = 282,
+     PERCENT_OUTPUT = 283,
+     PERCENT_PARSE_PARAM = 284,
+     PERCENT_PURE_PARSER = 285,
+     PERCENT_SKELETON = 286,
+     PERCENT_START = 287,
+     PERCENT_TOKEN_TABLE = 288,
+     PERCENT_VERBOSE = 289,
+     PERCENT_YACC = 290,
+     TYPE = 291,
+     EQUAL = 292,
+     SEMICOLON = 293,
+     COLON = 294,
+     COMMA = 295,
+     PIPE = 296,
+     ID = 297,
+     PERCENT_PERCENT = 298,
+     PROLOGUE = 299,
+     EPILOGUE = 300,
+     BRACED_CODE = 301
    };
 #endif
 #define GRAM_EOF 0
 #define STRING 258
-#define CHARACTER 259
-#define INT 260
-#define PERCENT_TOKEN 261
-#define PERCENT_NTERM 262
-#define PERCENT_TYPE 263
-#define PERCENT_DESTRUCTOR 264
-#define PERCENT_PRINTER 265
-#define PERCENT_UNION 266
-#define PERCENT_LEFT 267
-#define PERCENT_RIGHT 268
-#define PERCENT_NONASSOC 269
-#define PERCENT_PREC 270
-#define PERCENT_DPREC 271
-#define PERCENT_MERGE 272
-#define PERCENT_DEBUG 273
-#define PERCENT_DEFINE 274
-#define PERCENT_DEFINES 275
-#define PERCENT_ERROR_VERBOSE 276
-#define PERCENT_EXPECT 277
-#define PERCENT_FILE_PREFIX 278
-#define PERCENT_GLR_PARSER 279
-#define PERCENT_LEX_PARAM 280
-#define PERCENT_LOCATIONS 281
-#define PERCENT_NAME_PREFIX 282
-#define PERCENT_NO_LINES 283
-#define PERCENT_OUTPUT 284
-#define PERCENT_PARSE_PARAM 285
-#define PERCENT_PURE_PARSER 286
-#define PERCENT_SKELETON 287
-#define PERCENT_START 288
-#define PERCENT_TOKEN_TABLE 289
-#define PERCENT_VERBOSE 290
-#define PERCENT_YACC 291
-#define TYPE 292
-#define EQUAL 293
-#define SEMICOLON 294
-#define COLON 295
-#define COMMA 296
-#define PIPE 297
-#define ID 298
-#define PERCENT_PERCENT 299
-#define PROLOGUE 300
-#define EPILOGUE 301
-#define BRACED_CODE 302
+#define INT 259
+#define PERCENT_TOKEN 260
+#define PERCENT_NTERM 261
+#define PERCENT_TYPE 262
+#define PERCENT_DESTRUCTOR 263
+#define PERCENT_PRINTER 264
+#define PERCENT_UNION 265
+#define PERCENT_LEFT 266
+#define PERCENT_RIGHT 267
+#define PERCENT_NONASSOC 268
+#define PERCENT_PREC 269
+#define PERCENT_DPREC 270
+#define PERCENT_MERGE 271
+#define PERCENT_DEBUG 272
+#define PERCENT_DEFINE 273
+#define PERCENT_DEFINES 274
+#define PERCENT_ERROR_VERBOSE 275
+#define PERCENT_EXPECT 276
+#define PERCENT_FILE_PREFIX 277
+#define PERCENT_GLR_PARSER 278
+#define PERCENT_LEX_PARAM 279
+#define PERCENT_LOCATIONS 280
+#define PERCENT_NAME_PREFIX 281
+#define PERCENT_NO_LINES 282
+#define PERCENT_OUTPUT 283
+#define PERCENT_PARSE_PARAM 284
+#define PERCENT_PURE_PARSER 285
+#define PERCENT_SKELETON 286
+#define PERCENT_START 287
+#define PERCENT_TOKEN_TABLE 288
+#define PERCENT_VERBOSE 289
+#define PERCENT_YACC 290
+#define TYPE 291
+#define EQUAL 292
+#define SEMICOLON 293
+#define COLON 294
+#define COMMA 295
+#define PIPE 296
+#define ID 297
+#define PERCENT_PERCENT 298
+#define PROLOGUE 299
+#define EPILOGUE 300
+#define BRACED_CODE 301
 
 
 
@@ -236,7 +237,7 @@ typedef union {
   char *string;
   assoc_t assoc;
 } yystype;
-/* Line 226 of /tmp/prefix/share/bison/yacc.c.  */
+/* Line 212 of /tmp/prefix/share/bison/yacc.c.  */
 #line 241 "parse-gram.c"
 # define YYSTYPE yystype
 # define YYSTYPE_IS_TRIVIAL 1
@@ -257,7 +258,7 @@ typedef struct yyltype
 /* Copy the second part of user declarations.  */
 
 
-/* Line 246 of /tmp/prefix/share/bison/yacc.c.  */
+/* Line 232 of /tmp/prefix/share/bison/yacc.c.  */
 #line 262 "parse-gram.c"
 
 #if ! defined (yyoverflow) || YYERROR_VERBOSE
@@ -358,20 +359,20 @@ union yyalloc
 /* YYFINAL -- State number of the termination state. */
 #define YYFINAL  3
 /* YYLAST -- Last index in YYTABLE.  */
-#define YYLAST   152
+#define YYLAST   125
 
 /* YYNTOKENS -- Number of terminals. */
-#define YYNTOKENS  48
+#define YYNTOKENS  47
 /* YYNNTS -- Number of nonterminals. */
 #define YYNNTS  28
 /* YYNRULES -- Number of rules. */
-#define YYNRULES  77
+#define YYNRULES  76
 /* YYNRULES -- Number of states. */
-#define YYNSTATES  116
+#define YYNSTATES  115
 
 /* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
 #define YYUNDEFTOK  2
-#define YYMAXUTOK   302
+#define YYMAXUTOK   301
 
 #define YYTRANSLATE(X) \
   ((unsigned)(X) <= YYMAXUTOK ? yytranslate[X] : YYUNDEFTOK)
@@ -409,7 +410,7 @@ static const unsigned char yytranslate[] =
       15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
       25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
       35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
-      45,    46,    47
+      45,    46
 };
 
 #if YYDEBUG
@@ -424,46 +425,46 @@ static const unsigned char yyprhs[] =
      111,   113,   115,   116,   118,   120,   123,   125,   127,   130,
      133,   137,   139,   142,   144,   147,   149,   152,   155,   156,
      162,   164,   168,   169,   172,   175,   179,   183,   187,   189,
-     191,   193,   195,   197,   199,   200,   203,   204
+     191,   193,   195,   197,   198,   201,   202
 };
 
 /* YYRHS -- A `-1'-separated list of the rules' RHS. */
 static const yysigned_char yyrhs[] =
 {
-      49,     0,    -1,    50,    44,    64,    74,    -1,    -1,    50,
-      51,    75,    -1,    52,    -1,    45,    -1,    18,    -1,    19,
-      73,    73,    -1,    20,    -1,    21,    -1,    22,     5,    -1,
-      23,    38,    73,    -1,    24,    -1,    25,    73,    41,    73,
-      -1,    26,    -1,    27,    38,    73,    -1,    28,    -1,    29,
-      38,    73,    -1,    30,    73,    41,    73,    -1,    31,    -1,
-      32,    73,    -1,    34,    -1,    35,    -1,    36,    -1,    58,
-      -1,    55,    -1,    33,    70,    -1,    11,    47,    -1,    -1,
-       9,    53,    47,    61,    -1,    -1,    10,    54,    47,    61,
-      -1,    -1,     7,    56,    63,    -1,    -1,     6,    57,    63,
-      -1,     8,    37,    61,    -1,    59,    60,    61,    -1,    12,
-      -1,    13,    -1,    14,    -1,    -1,    37,    -1,    70,    -1,
-      61,    70,    -1,    37,    -1,    43,    -1,    43,     5,    -1,
-      43,    72,    -1,    43,     5,    72,    -1,    62,    -1,    63,
-      62,    -1,    65,    -1,    64,    65,    -1,    66,    -1,    52,
-      39,    -1,     1,    39,    -1,    -1,    43,    40,    67,    68,
-      39,    -1,    69,    -1,    68,    42,    69,    -1,    -1,    69,
-      70,    -1,    69,    71,    -1,    69,    15,    70,    -1,    69,
-      16,     5,    -1,    69,    17,    37,    -1,    43,    -1,    72,
-      -1,     4,    -1,    47,    -1,     3,    -1,     3,    -1,    -1,
-      44,    46,    -1,    -1,    39,    -1
+      48,     0,    -1,    49,    43,    63,    73,    -1,    -1,    49,
+      50,    74,    -1,    51,    -1,    44,    -1,    17,    -1,    18,
+      72,    72,    -1,    19,    -1,    20,    -1,    21,     4,    -1,
+      22,    37,    72,    -1,    23,    -1,    24,    72,    40,    72,
+      -1,    25,    -1,    26,    37,    72,    -1,    27,    -1,    28,
+      37,    72,    -1,    29,    72,    40,    72,    -1,    30,    -1,
+      31,    72,    -1,    33,    -1,    34,    -1,    35,    -1,    57,
+      -1,    54,    -1,    32,    69,    -1,    10,    46,    -1,    -1,
+       8,    52,    46,    60,    -1,    -1,     9,    53,    46,    60,
+      -1,    -1,     6,    55,    62,    -1,    -1,     5,    56,    62,
+      -1,     7,    36,    60,    -1,    58,    59,    60,    -1,    11,
+      -1,    12,    -1,    13,    -1,    -1,    36,    -1,    69,    -1,
+      60,    69,    -1,    36,    -1,    42,    -1,    42,     4,    -1,
+      42,    71,    -1,    42,     4,    71,    -1,    61,    -1,    62,
+      61,    -1,    64,    -1,    63,    64,    -1,    65,    -1,    51,
+      38,    -1,     1,    38,    -1,    -1,    42,    39,    66,    67,
+      38,    -1,    68,    -1,    67,    41,    68,    -1,    -1,    68,
+      69,    -1,    68,    70,    -1,    68,    14,    69,    -1,    68,
+      15,     4,    -1,    68,    16,    36,    -1,    42,    -1,    71,
+      -1,    46,    -1,     3,    -1,     3,    -1,    -1,    43,    45,
+      -1,    -1,    38,    -1
 };
 
 /* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
 static const unsigned short yyrline[] =
 {
-       0,   168,   168,   181,   183,   186,   188,   189,   190,   191,
-     192,   193,   194,   195,   196,   198,   199,   200,   201,   202,
-     204,   205,   206,   207,   208,   211,   213,   214,   218,   225,
-     224,   235,   234,   247,   246,   252,   252,   257,   266,   281,
-     283,   284,   287,   289,   294,   296,   300,   305,   310,   316,
-     322,   332,   335,   344,   346,   352,   354,   359,   366,   365,
-     370,   372,   375,   378,   380,   382,   384,   386,   390,   392,
-     393,   396,   402,   411,   419,   424,   430,   432
+       0,   167,   167,   180,   182,   185,   187,   188,   189,   190,
+     191,   192,   193,   194,   195,   197,   198,   199,   200,   201,
+     203,   204,   205,   206,   207,   210,   212,   213,   217,   224,
+     223,   234,   233,   246,   245,   251,   251,   256,   265,   280,
+     282,   283,   286,   288,   293,   295,   299,   304,   309,   315,
+     321,   331,   334,   343,   345,   351,   353,   358,   365,   364,
+     369,   371,   374,   377,   379,   381,   383,   385,   389,   391,
+     394,   400,   409,   417,   422,   428,   430
 };
 #endif
 
@@ -472,12 +473,12 @@ static const unsigned short yyrline[] =
    First, the terminals, then, starting at YYNTOKENS, nonterminals. */
 static const char *const yytname[] =
 {
-  "\"end of file\"", "error", "$undefined", "\"string\"", "\"character\"", 
-  "\"integer\"", "\"%token\"", "\"%nterm\"", "\"%type\"", 
-  "\"%destructor\"", "\"%printer\"", "\"%union\"", "\"%left\"", 
-  "\"%right\"", "\"%nonassoc\"", "\"%prec\"", "\"%dprec\"", "\"%merge\"", 
-  "\"%debug\"", "\"%define\"", "\"%defines\"", "\"%error-verbose\"", 
-  "\"%expect\"", "\"%file-prefix\"", "\"%glr-parser\"", "\"%lex-param\"", 
+  "\"end of file\"", "error", "$undefined", "\"string\"", "\"integer\"", 
+  "\"%token\"", "\"%nterm\"", "\"%type\"", "\"%destructor\"", 
+  "\"%printer\"", "\"%union\"", "\"%left\"", "\"%right\"", 
+  "\"%nonassoc\"", "\"%prec\"", "\"%dprec\"", "\"%merge\"", "\"%debug\"", 
+  "\"%define\"", "\"%defines\"", "\"%error-verbose\"", "\"%expect\"", 
+  "\"%file-prefix\"", "\"%glr-parser\"", "\"%lex-param\"", 
   "\"%locations\"", "\"%name-prefix\"", "\"%no-lines\"", "\"%output\"", 
   "\"%parse-param\"", "\"%pure-parser\"", "\"%skeleton\"", "\"%start\"", 
   "\"%token-table\"", "\"%verbose\"", "\"%yacc\"", "\"type\"", "\"=\"", 
@@ -501,21 +502,21 @@ static const unsigned short yytoknum[] =
      265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
      275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
      285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
-     295,   296,   297,   298,   299,   300,   301,   302
+     295,   296,   297,   298,   299,   300,   301
 };
 # endif
 
 /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
 static const unsigned char yyr1[] =
 {
-       0,    48,    49,    50,    50,    51,    51,    51,    51,    51,
-      51,    51,    51,    51,    51,    51,    51,    51,    51,    51,
-      51,    51,    51,    51,    51,    52,    52,    52,    52,    53,
-      52,    54,    52,    56,    55,    57,    55,    55,    58,    59,
-      59,    59,    60,    60,    61,    61,    62,    62,    62,    62,
-      62,    63,    63,    64,    64,    65,    65,    65,    67,    66,
-      68,    68,    69,    69,    69,    69,    69,    69,    70,    70,
-      70,    71,    72,    73,    74,    74,    75,    75
+       0,    47,    48,    49,    49,    50,    50,    50,    50,    50,
+      50,    50,    50,    50,    50,    50,    50,    50,    50,    50,
+      50,    50,    50,    50,    50,    51,    51,    51,    51,    52,
+      51,    53,    51,    55,    54,    56,    54,    54,    57,    58,
+      58,    58,    59,    59,    60,    60,    61,    61,    61,    61,
+      61,    62,    62,    63,    63,    64,    64,    64,    66,    65,
+      67,    67,    68,    68,    68,    68,    68,    68,    69,    69,
+      70,    71,    72,    73,    73,    74,    74
 };
 
 /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
@@ -528,7 +529,7 @@ static const unsigned char yyr2[] =
        1,     1,     0,     1,     1,     2,     1,     1,     2,     2,
        3,     1,     2,     1,     2,     1,     2,     2,     0,     5,
        1,     3,     0,     2,     2,     3,     3,     3,     1,     1,
-       1,     1,     1,     1,     0,     2,     0,     1
+       1,     1,     1,     0,     2,     0,     1
 };
 
 /* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
@@ -539,113 +540,107 @@ static const unsigned char yydefact[] =
        3,     0,     0,     1,    35,    33,     0,    29,    31,     0,
       39,    40,    41,     7,     0,     9,    10,     0,     0,    13,
        0,    15,     0,    17,     0,     0,    20,     0,     0,    22,
-      23,    24,     0,     6,    76,     5,    26,    25,    42,     0,
-       0,     0,     0,     0,    28,    73,     0,    11,     0,     0,
-       0,     0,     0,    21,    72,    70,    68,    27,    69,     0,
-       0,     0,     0,    53,    55,    77,     4,    43,     0,    46,
-      47,    51,    36,    34,    37,    44,     0,     0,     8,    12,
-       0,    16,    18,     0,    57,    58,    56,     0,    54,     2,
-      38,    48,    49,    52,    45,    30,    32,    14,    19,    62,
-      75,    50,     0,    60,    59,    62,     0,     0,     0,    71,
-      63,    64,    61,    65,    66,    67
+      23,    24,     0,     6,    75,     5,    26,    25,    42,     0,
+       0,     0,     0,     0,    28,    72,     0,    11,     0,     0,
+       0,     0,     0,    21,    71,    68,    27,    69,     0,     0,
+       0,     0,    53,    55,    76,     4,    43,     0,    46,    47,
+      51,    36,    34,    37,    44,     0,     0,     8,    12,     0,
+      16,    18,     0,    57,    58,    56,     0,    54,     2,    38,
+      48,    49,    52,    45,    30,    32,    14,    19,    62,    74,
+      50,     0,    60,    59,    62,     0,     0,     0,    70,    63,
+      64,    61,    65,    66,    67
 };
 
 /* YYDEFGOTO[NTERM-NUM]. */
 static const yysigned_char yydefgoto[] =
 {
-      -1,     1,     2,    34,    61,    42,    43,    36,    40,    39,
-      37,    38,    68,    74,    71,    72,    62,    63,    64,    99,
-     102,   103,    75,   111,    58,    46,    89,    66
+      -1,     1,     2,    34,    60,    42,    43,    36,    40,    39,
+      37,    38,    67,    73,    70,    71,    61,    62,    63,    98,
+     101,   102,    74,   110,    57,    46,    88,    65
 };
 
 /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
    STATE-NUM.  */
-#define YYPACT_NINF -64
+#define YYPACT_NINF -67
 static const yysigned_char yypact[] =
 {
-     -64,     9,   107,   -64,   -64,   -64,   -13,   -64,   -64,    -9,
-     -64,   -64,   -64,   -64,    27,   -64,   -64,    38,     3,   -64,
-      27,   -64,     6,   -64,     7,    27,   -64,    27,    -1,   -64,
-     -64,   -64,    79,   -64,    10,   -64,   -64,   -64,    13,   -17,
-     -17,    -1,     8,    11,   -64,   -64,    27,   -64,    27,    15,
-      27,    27,    16,   -64,   -64,   -64,   -64,   -64,   -64,    20,
-      14,    21,     4,   -64,   -64,   -64,   -64,   -64,    -1,   -64,
-      18,   -64,   -17,   -17,    -1,   -64,    -1,    -1,   -64,   -64,
-      27,   -64,   -64,    27,   -64,   -64,   -64,    17,   -64,   -64,
-      -1,    62,   -64,   -64,   -64,    -1,    -1,   -64,   -64,   -64,
-     -64,   -64,   -20,    36,   -64,   -64,    -1,    61,    32,   -64,
-     -64,   -64,    36,   -64,   -64,   -64
+     -67,     7,    81,   -67,   -67,   -67,   -13,   -67,   -67,   -16,
+     -67,   -67,   -67,   -67,    32,   -67,   -67,    36,    20,   -67,
+      32,   -67,    21,   -67,    22,    32,   -67,    32,    -1,   -67,
+     -67,   -67,    43,   -67,    24,   -67,   -67,   -67,    28,   -14,
+     -14,    -1,    25,    26,   -67,   -67,    32,   -67,    32,    30,
+      32,    32,    33,   -67,   -67,   -67,   -67,   -67,    38,    29,
+      40,     4,   -67,   -67,   -67,   -67,   -67,    -1,   -67,    16,
+     -67,   -14,   -14,    -1,   -67,    -1,    -1,   -67,   -67,    32,
+     -67,   -67,    32,   -67,   -67,   -67,    34,   -67,   -67,    -1,
+      77,   -67,   -67,   -67,    -1,    -1,   -67,   -67,   -67,   -67,
+     -67,   -20,    23,   -67,   -67,    -1,    78,    45,   -67,   -67,
+     -67,    23,   -67,   -67,   -67
 };
 
 /* YYPGOTO[NTERM-NUM].  */
 static const yysigned_char yypgoto[] =
 {
-     -64,   -64,   -64,   -64,    68,   -64,   -64,   -64,   -64,   -64,
-     -64,   -64,   -64,   -43,   -37,    31,   -64,    12,   -64,   -64,
-     -64,   -33,   -28,   -64,   -63,   -19,   -64,   -64
+     -67,   -67,   -67,   -67,    82,   -67,   -67,   -67,   -67,   -67,
+     -67,   -67,   -67,   -42,   -29,    55,   -67,    35,   -67,   -67,
+     -67,    -7,   -28,   -67,   -66,   -19,   -67,   -67
 };
 
 /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
    positive, shift that token.  If negative, reduce the rule which
    number is the opposite.  If zero, do what YYDEFACT says.
    If YYTABLE_NINF, parse error.  */
-#define YYTABLE_NINF -75
+#define YYTABLE_NINF -74
 static const yysigned_char yytable[] =
 {
-      57,    49,    54,    55,   -74,    59,    52,    92,    53,     3,
-       4,     5,     6,     7,     8,     9,    10,    11,    12,   104,
-      69,    54,   105,    91,    41,    90,    70,    78,   101,    79,
-      45,    81,    82,    95,    96,    93,    93,    28,    44,    54,
-      55,    48,    56,    47,    50,    51,    94,    60,    87,    65,
-      67,   106,   107,   108,    85,    76,    80,    83,    77,    84,
-      86,    97,    94,   100,    98,    54,   114,    94,    94,   115,
-      35,    73,   112,     0,    88,   110,     0,     0,   113,    56,
-      59,     0,     0,   109,   110,     4,     5,     6,     7,     8,
-       9,    10,    11,    12,     0,     0,     0,     0,     0,     0,
-       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
-       0,     0,    28,     4,     5,     6,     7,     8,     9,    10,
-      11,    12,    60,     0,     0,    13,    14,    15,    16,    17,
-      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
-      28,    29,    30,    31,     0,     0,     0,     0,     0,     0,
-       0,    32,    33
+      56,    49,    54,    91,   -73,    58,    52,     3,    53,     4,
+       5,     6,     7,     8,     9,    10,    11,    12,   103,    54,
+      90,   104,    68,    41,   100,    89,    54,    77,    69,    78,
+      44,    80,    81,    94,    95,    45,    28,   105,   106,   107,
+      47,    55,    92,    92,    58,    93,    59,    86,     4,     5,
+       6,     7,     8,     9,    10,    11,    12,    48,    50,    51,
+      96,    93,    64,    97,    66,    55,    93,    93,    84,   108,
+      79,    75,    76,    82,   109,    28,    83,   112,    85,    99,
+      54,   114,   113,   109,    35,    59,     4,     5,     6,     7,
+       8,     9,    10,    11,    12,    72,    87,   111,    13,    14,
+      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
+      25,    26,    27,    28,    29,    30,    31,     0,     0,     0,
+       0,     0,     0,     0,    32,    33
 };
 
 static const yysigned_char yycheck[] =
 {
-      28,    20,     3,     4,     0,     1,    25,    70,    27,     0,
-       6,     7,     8,     9,    10,    11,    12,    13,    14,    39,
-      37,     3,    42,     5,    37,    68,    43,    46,    91,    48,
-       3,    50,    51,    76,    77,    72,    73,    33,    47,     3,
-       4,    38,    43,     5,    38,    38,    74,    43,    44,    39,
-      37,    15,    16,    17,    40,    47,    41,    41,    47,    39,
-      39,    80,    90,    46,    83,     3,     5,    95,    96,    37,
-       2,    40,   105,    -1,    62,   103,    -1,    -1,   106,    43,
-       1,    -1,    -1,    47,   112,     6,     7,     8,     9,    10,
-      11,    12,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,
-      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
-      -1,    -1,    33,     6,     7,     8,     9,    10,    11,    12,
-      13,    14,    43,    -1,    -1,    18,    19,    20,    21,    22,
-      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
-      33,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,
-      -1,    44,    45
+      28,    20,     3,    69,     0,     1,    25,     0,    27,     5,
+       6,     7,     8,     9,    10,    11,    12,    13,    38,     3,
+       4,    41,    36,    36,    90,    67,     3,    46,    42,    48,
+      46,    50,    51,    75,    76,     3,    32,    14,    15,    16,
+       4,    42,    71,    72,     1,    73,    42,    43,     5,     6,
+       7,     8,     9,    10,    11,    12,    13,    37,    37,    37,
+      79,    89,    38,    82,    36,    42,    94,    95,    39,    46,
+      40,    46,    46,    40,   102,    32,    38,   105,    38,    45,
+       3,    36,     4,   111,     2,    42,     5,     6,     7,     8,
+       9,    10,    11,    12,    13,    40,    61,   104,    17,    18,
+      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
+      29,    30,    31,    32,    33,    34,    35,    -1,    -1,    -1,
+      -1,    -1,    -1,    -1,    43,    44
 };
 
 /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
    symbol of state STATE-NUM.  */
 static const unsigned char yystos[] =
 {
-       0,    49,    50,     0,     6,     7,     8,     9,    10,    11,
-      12,    13,    14,    18,    19,    20,    21,    22,    23,    24,
-      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
-      35,    36,    44,    45,    51,    52,    55,    58,    59,    57,
-      56,    37,    53,    54,    47,     3,    73,     5,    38,    73,
-      38,    38,    73,    73,     3,     4,    43,    70,    72,     1,
-      43,    52,    64,    65,    66,    39,    75,    37,    60,    37,
-      43,    62,    63,    63,    61,    70,    47,    47,    73,    73,
-      41,    73,    73,    41,    39,    40,    39,    44,    65,    74,
-      61,     5,    72,    62,    70,    61,    61,    73,    73,    67,
-      46,    72,    68,    69,    39,    42,    15,    16,    17,    47,
-      70,    71,    69,    70,     5,    37
+       0,    48,    49,     0,     5,     6,     7,     8,     9,    10,
+      11,    12,    13,    17,    18,    19,    20,    21,    22,    23,
+      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
+      34,    35,    43,    44,    50,    51,    54,    57,    58,    56,
+      55,    36,    52,    53,    46,     3,    72,     4,    37,    72,
+      37,    37,    72,    72,     3,    42,    69,    71,     1,    42,
+      51,    63,    64,    65,    38,    74,    36,    59,    36,    42,
+      61,    62,    62,    60,    69,    46,    46,    72,    72,    40,
+      72,    72,    40,    38,    39,    38,    43,    64,    73,    60,
+       4,    71,    61,    69,    60,    60,    72,    72,    66,    45,
+      71,    67,    68,    38,    41,    14,    15,    16,    46,    69,
+      70,    68,    69,     4,    36
 };
 
 #if ! defined (YYSIZE_T) && defined (__SIZE_TYPE__)
@@ -693,7 +688,7 @@ do								\
     }								\
   else								\
     { 								\
-      yyerror ("syntax error: cannot back up");			\
+      yyerror ("syntax error: cannot back up");	\
       YYERROR;							\
     }								\
 while (0)
@@ -1220,7 +1215,7 @@ yyreduce:
   switch (yyn)
     {
         case 2:
-#line 170 "parse-gram.y"
+#line 169 "parse-gram.y"
     {
       yycontrol->errcode = 0;
       epilogue_set (yyvsp[0].string, yylsp[0]);
@@ -1228,109 +1223,109 @@ yyreduce:
     break;
 
   case 6:
-#line 188 "parse-gram.y"
+#line 187 "parse-gram.y"
     { prologue_augment (yyvsp[0].string, yylsp[0]); }
     break;
 
   case 7:
-#line 189 "parse-gram.y"
+#line 188 "parse-gram.y"
     { debug_flag = 1; }
     break;
 
   case 8:
-#line 190 "parse-gram.y"
+#line 189 "parse-gram.y"
     { muscle_insert (yyvsp[-1].string, yyvsp[0].string); }
     break;
 
   case 9:
-#line 191 "parse-gram.y"
+#line 190 "parse-gram.y"
     { defines_flag = 1; }
     break;
 
   case 10:
-#line 192 "parse-gram.y"
+#line 191 "parse-gram.y"
     { error_verbose = 1; }
     break;
 
   case 11:
-#line 193 "parse-gram.y"
+#line 192 "parse-gram.y"
     { expected_conflicts = yyvsp[0].integer; }
     break;
 
   case 12:
-#line 194 "parse-gram.y"
+#line 193 "parse-gram.y"
     { spec_file_prefix = yyvsp[0].string; }
     break;
 
   case 13:
-#line 195 "parse-gram.y"
+#line 194 "parse-gram.y"
     { glr_parser = 1; }
     break;
 
   case 14:
-#line 197 "parse-gram.y"
+#line 196 "parse-gram.y"
     { muscle_pair_list_grow ("lex_param", yyvsp[-2].string, yyvsp[0].string); }
     break;
 
   case 15:
-#line 198 "parse-gram.y"
+#line 197 "parse-gram.y"
     { locations_flag = 1; }
     break;
 
   case 16:
-#line 199 "parse-gram.y"
+#line 198 "parse-gram.y"
     { spec_name_prefix = yyvsp[0].string; }
     break;
 
   case 17:
-#line 200 "parse-gram.y"
+#line 199 "parse-gram.y"
     { no_lines_flag = 1; }
     break;
 
   case 18:
-#line 201 "parse-gram.y"
+#line 200 "parse-gram.y"
     { spec_outfile = yyvsp[0].string; }
     break;
 
   case 19:
-#line 203 "parse-gram.y"
+#line 202 "parse-gram.y"
     { muscle_pair_list_grow ("parse_param", yyvsp[-2].string, yyvsp[0].string); }
     break;
 
   case 20:
-#line 204 "parse-gram.y"
+#line 203 "parse-gram.y"
     { pure_parser = 1; }
     break;
 
   case 21:
-#line 205 "parse-gram.y"
+#line 204 "parse-gram.y"
     { skeleton = yyvsp[0].string; }
     break;
 
   case 22:
-#line 206 "parse-gram.y"
+#line 205 "parse-gram.y"
     { token_table_flag = 1; }
     break;
 
   case 23:
-#line 207 "parse-gram.y"
+#line 206 "parse-gram.y"
     { report_flag = 1; }
     break;
 
   case 24:
-#line 208 "parse-gram.y"
+#line 207 "parse-gram.y"
     { yacc_flag = 1; }
     break;
 
   case 27:
-#line 215 "parse-gram.y"
+#line 214 "parse-gram.y"
     {
       grammar_start_symbol_set (yyvsp[0].symbol, yylsp[0]);
     }
     break;
 
   case 28:
-#line 219 "parse-gram.y"
+#line 218 "parse-gram.y"
     {
       typed = 1;
       MUSCLE_INSERT_INT ("stype_line", yylsp[0].first_line);
@@ -1339,12 +1334,12 @@ yyreduce:
     break;
 
   case 29:
-#line 225 "parse-gram.y"
+#line 224 "parse-gram.y"
     { current_braced_code = destructor_braced_code; }
     break;
 
   case 30:
-#line 227 "parse-gram.y"
+#line 226 "parse-gram.y"
     {
       symbol_list_t *list;
       for (list = yyvsp[0].list; list; list = list->next)
@@ -1355,12 +1350,12 @@ yyreduce:
     break;
 
   case 31:
-#line 235 "parse-gram.y"
+#line 234 "parse-gram.y"
     { current_braced_code = printer_braced_code; }
     break;
 
   case 32:
-#line 237 "parse-gram.y"
+#line 236 "parse-gram.y"
     {
       symbol_list_t *list;
       for (list = yyvsp[0].list; list; list = list->next)
@@ -1371,12 +1366,12 @@ yyreduce:
     break;
 
   case 33:
-#line 247 "parse-gram.y"
+#line 246 "parse-gram.y"
     { current_class = nterm_sym; }
     break;
 
   case 34:
-#line 248 "parse-gram.y"
+#line 247 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
@@ -1384,12 +1379,12 @@ yyreduce:
     break;
 
   case 35:
-#line 252 "parse-gram.y"
+#line 251 "parse-gram.y"
     { current_class = token_sym; }
     break;
 
   case 36:
-#line 253 "parse-gram.y"
+#line 252 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
@@ -1397,7 +1392,7 @@ yyreduce:
     break;
 
   case 37:
-#line 258 "parse-gram.y"
+#line 257 "parse-gram.y"
     {
       symbol_list_t *list;
       for (list = yyvsp[0].list; list; list = list->next)
@@ -1407,7 +1402,7 @@ yyreduce:
     break;
 
   case 38:
-#line 268 "parse-gram.y"
+#line 267 "parse-gram.y"
     {
       symbol_list_t *list;
       ++current_prec;
@@ -1422,49 +1417,49 @@ yyreduce:
     break;
 
   case 39:
-#line 282 "parse-gram.y"
+#line 281 "parse-gram.y"
     { yyval.assoc = left_assoc; }
     break;
 
   case 40:
-#line 283 "parse-gram.y"
+#line 282 "parse-gram.y"
     { yyval.assoc = right_assoc; }
     break;
 
   case 41:
-#line 284 "parse-gram.y"
+#line 283 "parse-gram.y"
     { yyval.assoc = non_assoc; }
     break;
 
   case 42:
-#line 288 "parse-gram.y"
-    { current_type = NULL;}
+#line 287 "parse-gram.y"
+    { current_type = NULL; }
     break;
 
   case 43:
-#line 289 "parse-gram.y"
+#line 288 "parse-gram.y"
     { current_type = yyvsp[0].string; }
     break;
 
   case 44:
-#line 295 "parse-gram.y"
+#line 294 "parse-gram.y"
     { yyval.list = symbol_list_new (yyvsp[0].symbol, yylsp[0]); }
     break;
 
   case 45:
-#line 296 "parse-gram.y"
+#line 295 "parse-gram.y"
     { yyval.list = symbol_list_prepend (yyvsp[-1].list, yyvsp[0].symbol, yylsp[0]); }
     break;
 
   case 46:
-#line 302 "parse-gram.y"
+#line 301 "parse-gram.y"
     {
        current_type = yyvsp[0].string;
      }
     break;
 
   case 47:
-#line 306 "parse-gram.y"
+#line 305 "parse-gram.y"
     {
        symbol_class_set (yyvsp[0].symbol, current_class, yylsp[0]);
        symbol_type_set (yyvsp[0].symbol, current_type, yylsp[0]);
@@ -1472,7 +1467,7 @@ yyreduce:
     break;
 
   case 48:
-#line 311 "parse-gram.y"
+#line 310 "parse-gram.y"
     {
       symbol_class_set (yyvsp[-1].symbol, current_class, yylsp[-1]);
       symbol_type_set (yyvsp[-1].symbol, current_type, yylsp[-1]);
@@ -1481,7 +1476,7 @@ yyreduce:
     break;
 
   case 49:
-#line 317 "parse-gram.y"
+#line 316 "parse-gram.y"
     {
       symbol_class_set (yyvsp[-1].symbol, current_class, yylsp[-1]);
       symbol_type_set (yyvsp[-1].symbol, current_type, yylsp[-1]);
@@ -1490,7 +1485,7 @@ yyreduce:
     break;
 
   case 50:
-#line 323 "parse-gram.y"
+#line 322 "parse-gram.y"
     {
       symbol_class_set (yyvsp[-2].symbol, current_class, yylsp[-2]);
       symbol_type_set (yyvsp[-2].symbol, current_type, yylsp[-2]);
@@ -1500,17 +1495,17 @@ yyreduce:
     break;
 
   case 51:
-#line 334 "parse-gram.y"
+#line 333 "parse-gram.y"
     {;}
     break;
 
   case 52:
-#line 336 "parse-gram.y"
+#line 335 "parse-gram.y"
     {;}
     break;
 
   case 56:
-#line 355 "parse-gram.y"
+#line 354 "parse-gram.y"
     {
       if (yacc_flag)
 	complain_at (yyloc, _("POSIX forbids declarations in the grammar"));
@@ -1518,107 +1513,102 @@ yyreduce:
     break;
 
   case 57:
-#line 360 "parse-gram.y"
+#line 359 "parse-gram.y"
     {
       yyerrok;
     }
     break;
 
   case 58:
-#line 366 "parse-gram.y"
+#line 365 "parse-gram.y"
     { current_lhs = yyvsp[-1].symbol; current_lhs_location = yylsp[-1]; }
     break;
 
   case 59:
-#line 367 "parse-gram.y"
+#line 366 "parse-gram.y"
     {;}
     break;
 
   case 60:
-#line 371 "parse-gram.y"
+#line 370 "parse-gram.y"
     { grammar_rule_end (yylsp[0]); }
     break;
 
   case 61:
-#line 372 "parse-gram.y"
+#line 371 "parse-gram.y"
     { grammar_rule_end (yylsp[0]); }
     break;
 
   case 62:
-#line 377 "parse-gram.y"
+#line 376 "parse-gram.y"
     { grammar_rule_begin (current_lhs, current_lhs_location); }
     break;
 
   case 63:
-#line 379 "parse-gram.y"
+#line 378 "parse-gram.y"
     { grammar_current_rule_symbol_append (yyvsp[0].symbol, yylsp[0]); }
     break;
 
   case 64:
-#line 381 "parse-gram.y"
+#line 380 "parse-gram.y"
     { grammar_current_rule_action_append (yyvsp[0].string, yylsp[0]); }
     break;
 
   case 65:
-#line 383 "parse-gram.y"
+#line 382 "parse-gram.y"
     { grammar_current_rule_prec_set (yyvsp[0].symbol, yylsp[0]); }
     break;
 
   case 66:
-#line 385 "parse-gram.y"
+#line 384 "parse-gram.y"
     { grammar_current_rule_dprec_set (yyvsp[0].integer, yylsp[0]); }
     break;
 
   case 67:
-#line 387 "parse-gram.y"
+#line 386 "parse-gram.y"
     { grammar_current_rule_merge_set (yyvsp[0].string, yylsp[0]); }
     break;
 
   case 68:
-#line 391 "parse-gram.y"
+#line 390 "parse-gram.y"
     { yyval.symbol = yyvsp[0].symbol; }
     break;
 
   case 69:
-#line 392 "parse-gram.y"
+#line 391 "parse-gram.y"
     { yyval.symbol = yyvsp[0].symbol; }
     break;
 
   case 70:
-#line 393 "parse-gram.y"
-    { yyval.symbol = symbol_get (yyvsp[0].string, yylsp[0]); }
-    break;
-
-  case 71:
-#line 398 "parse-gram.y"
+#line 396 "parse-gram.y"
     { yyval.string = yyvsp[0].string; }
     break;
 
-  case 72:
-#line 404 "parse-gram.y"
+  case 71:
+#line 402 "parse-gram.y"
     {
       yyval.symbol = symbol_get (yyvsp[0].string, yylsp[0]);
       symbol_class_set (yyval.symbol, token_sym, yylsp[0]);
     }
     break;
 
-  case 73:
-#line 413 "parse-gram.y"
+  case 72:
+#line 411 "parse-gram.y"
     {
       yyval.string = yyvsp[0].string + 1;
       yyval.string[strlen (yyval.string) - 1] = '\0';
     }
     break;
 
-  case 74:
-#line 421 "parse-gram.y"
+  case 73:
+#line 419 "parse-gram.y"
     {
       yyval.string = xstrdup ("");
     }
     break;
 
-  case 75:
-#line 425 "parse-gram.y"
+  case 74:
+#line 423 "parse-gram.y"
     {
       yyval.string = yyvsp[0].string;
     }
@@ -1627,8 +1617,8 @@ yyreduce:
 
     }
 
-/* Line 1045 of /tmp/prefix/share/bison/yacc.c.  */
-#line 1632 "parse-gram.c"
+/* Line 1031 of /tmp/prefix/share/bison/yacc.c.  */
+#line 1621 "parse-gram.c"
 
   yyvsp -= yylen;
   yyssp -= yylen;
@@ -1847,7 +1837,7 @@ yyreturn:
 }
 
 
-#line 434 "parse-gram.y"
+#line 432 "parse-gram.y"
 
 /*------------------------------------------------------------------.
 | When debugging the parser, display tokens' locations and values.  |
@@ -1860,10 +1850,6 @@ yyprint (FILE *file,
   fputc (' ', file);
   switch (type)
     {
-    case CHARACTER:
-      fprintf (file, " = '%s'", value->string);
-      break;
-
     case ID:
       fprintf (file, " = %s", value->symbol->tag);
       break;
