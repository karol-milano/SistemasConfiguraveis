@@ -1,4 +1,4 @@
-/* A Bison parser, made from parse-gram.y, by GNU bison 1.49c.  */
+/* A Bison parser, made from parse-gram.y, by GNU bison 1.75a.  */
 
 /* Skeleton parser for Yacc-like parsing with Bison,
    Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002 Free Software Foundation, Inc.
@@ -53,6 +53,110 @@
 #define yynerrs gram_nerrs
 #define yylloc gram_lloc
 
+/* Tokens.  */
+#ifndef YYTOKENTYPE
+# define YYTOKENTYPE
+   /* Put the tokens into the symbol table, so that GDB and other debuggers
+      know about them.  */
+   enum yytokentype {
+     GRAM_EOF = 0,
+     STRING = 258,
+     CHARACTER = 259,
+     INT = 260,
+     PERCENT_TOKEN = 261,
+     PERCENT_NTERM = 262,
+     PERCENT_TYPE = 263,
+     PERCENT_DESTRUCTOR = 264,
+     PERCENT_PRINTER = 265,
+     PERCENT_UNION = 266,
+     PERCENT_LEFT = 267,
+     PERCENT_RIGHT = 268,
+     PERCENT_NONASSOC = 269,
+     PERCENT_PREC = 270,
+     PERCENT_DPREC = 271,
+     PERCENT_MERGE = 272,
+     PERCENT_DEBUG = 273,
+     PERCENT_DEFINE = 274,
+     PERCENT_DEFINES = 275,
+     PERCENT_ERROR_VERBOSE = 276,
+     PERCENT_EXPECT = 277,
+     PERCENT_FILE_PREFIX = 278,
+     PERCENT_GLR_PARSER = 279,
+     PERCENT_LEX_PARAM = 280,
+     PERCENT_LOCATIONS = 281,
+     PERCENT_NAME_PREFIX = 282,
+     PERCENT_NO_LINES = 283,
+     PERCENT_OUTPUT = 284,
+     PERCENT_PARSE_PARAM = 285,
+     PERCENT_PURE_PARSER = 286,
+     PERCENT_SKELETON = 287,
+     PERCENT_START = 288,
+     PERCENT_TOKEN_TABLE = 289,
+     PERCENT_VERBOSE = 290,
+     PERCENT_YACC = 291,
+     TYPE = 292,
+     EQUAL = 293,
+     SEMICOLON = 294,
+     COLON = 295,
+     COMMA = 296,
+     PIPE = 297,
+     ID = 298,
+     PERCENT_PERCENT = 299,
+     PROLOGUE = 300,
+     EPILOGUE = 301,
+     BRACED_CODE = 302
+   };
+#endif
+#define GRAM_EOF 0
+#define STRING 258
+#define CHARACTER 259
+#define INT 260
+#define PERCENT_TOKEN 261
+#define PERCENT_NTERM 262
+#define PERCENT_TYPE 263
+#define PERCENT_DESTRUCTOR 264
+#define PERCENT_PRINTER 265
+#define PERCENT_UNION 266
+#define PERCENT_LEFT 267
+#define PERCENT_RIGHT 268
+#define PERCENT_NONASSOC 269
+#define PERCENT_PREC 270
+#define PERCENT_DPREC 271
+#define PERCENT_MERGE 272
+#define PERCENT_DEBUG 273
+#define PERCENT_DEFINE 274
+#define PERCENT_DEFINES 275
+#define PERCENT_ERROR_VERBOSE 276
+#define PERCENT_EXPECT 277
+#define PERCENT_FILE_PREFIX 278
+#define PERCENT_GLR_PARSER 279
+#define PERCENT_LEX_PARAM 280
+#define PERCENT_LOCATIONS 281
+#define PERCENT_NAME_PREFIX 282
+#define PERCENT_NO_LINES 283
+#define PERCENT_OUTPUT 284
+#define PERCENT_PARSE_PARAM 285
+#define PERCENT_PURE_PARSER 286
+#define PERCENT_SKELETON 287
+#define PERCENT_START 288
+#define PERCENT_TOKEN_TABLE 289
+#define PERCENT_VERBOSE 290
+#define PERCENT_YACC 291
+#define TYPE 292
+#define EQUAL 293
+#define SEMICOLON 294
+#define COLON 295
+#define COMMA 296
+#define PIPE 297
+#define ID 298
+#define PERCENT_PERCENT 299
+#define PROLOGUE 300
+#define EPILOGUE 301
+#define BRACED_CODE 302
+
+
+
+
 /* Copy the first part of user declarations.  */
 #line 31 "parse-gram.y"
 
@@ -110,107 +214,6 @@ int current_prec = 0;
 braced_code_t current_braced_code = action_braced_code;
 
 
-/* Tokens.  */
-#ifndef YYTOKENTYPE
-# if defined (__STDC__) || defined (__cplusplus)
-   /* Put the tokens into the symbol table, so that GDB and other debuggers
-      know about them.  */
-   enum yytokentype {
-     GRAM_EOF = 0,
-     STRING = 258,
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
-     PERCENT_EXPECT = 270,
-     PERCENT_START = 271,
-     PERCENT_PREC = 272,
-     PERCENT_DPREC = 273,
-     PERCENT_MERGE = 274,
-     PERCENT_VERBOSE = 275,
-     PERCENT_ERROR_VERBOSE = 276,
-     PERCENT_OUTPUT = 277,
-     PERCENT_FILE_PREFIX = 278,
-     PERCENT_NAME_PREFIX = 279,
-     PERCENT_DEFINE = 280,
-     PERCENT_PURE_PARSER = 281,
-     PERCENT_GLR_PARSER = 282,
-     PERCENT_DEFINES = 283,
-     PERCENT_YACC = 284,
-     PERCENT_DEBUG = 285,
-     PERCENT_LOCATIONS = 286,
-     PERCENT_NO_LINES = 287,
-     PERCENT_SKELETON = 288,
-     PERCENT_TOKEN_TABLE = 289,
-     TYPE = 290,
-     EQUAL = 291,
-     SEMICOLON = 292,
-     COLON = 293,
-     PIPE = 294,
-     ID = 295,
-     PERCENT_PERCENT = 296,
-     PROLOGUE = 297,
-     EPILOGUE = 298,
-     BRACED_CODE = 299
-   };
-# endif
-  /* POSIX requires `int' for tokens in interfaces.  */
-# define YYTOKENTYPE int
-#endif /* !YYTOKENTYPE */
-#define GRAM_EOF 0
-#define STRING 258
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
-#define PERCENT_EXPECT 270
-#define PERCENT_START 271
-#define PERCENT_PREC 272
-#define PERCENT_DPREC 273
-#define PERCENT_MERGE 274
-#define PERCENT_VERBOSE 275
-#define PERCENT_ERROR_VERBOSE 276
-#define PERCENT_OUTPUT 277
-#define PERCENT_FILE_PREFIX 278
-#define PERCENT_NAME_PREFIX 279
-#define PERCENT_DEFINE 280
-#define PERCENT_PURE_PARSER 281
-#define PERCENT_GLR_PARSER 282
-#define PERCENT_DEFINES 283
-#define PERCENT_YACC 284
-#define PERCENT_DEBUG 285
-#define PERCENT_LOCATIONS 286
-#define PERCENT_NO_LINES 287
-#define PERCENT_SKELETON 288
-#define PERCENT_TOKEN_TABLE 289
-#define TYPE 290
-#define EQUAL 291
-#define SEMICOLON 292
-#define COLON 293
-#define PIPE 294
-#define ID 295
-#define PERCENT_PERCENT 296
-#define PROLOGUE 297
-#define EPILOGUE 298
-#define BRACED_CODE 299
-
-
-
-
 /* Enabling traces.  */
 #ifndef YYDEBUG
 # define YYDEBUG 1
@@ -233,8 +236,8 @@ typedef union {
   char *string;
   assoc_t assoc;
 } yystype;
-/* Line 188 of /usr/local/share/bison/yacc.c.  */
-#line 238 "parse-gram.c"
+/* Line 193 of /usr/local/share/bison/yacc.c.  */
+#line 241 "parse-gram.c"
 # define YYSTYPE yystype
 # define YYSTYPE_IS_TRIVIAL 1
 #endif
@@ -254,8 +257,8 @@ typedef struct yyltype
 /* Copy the second part of user declarations.  */
 
 
-/* Line 208 of /usr/local/share/bison/yacc.c.  */
-#line 259 "parse-gram.c"
+/* Line 213 of /usr/local/share/bison/yacc.c.  */
+#line 262 "parse-gram.c"
 
 #if ! defined (yyoverflow) || YYERROR_VERBOSE
 
@@ -346,22 +349,28 @@ union yyalloc
 
 #endif
 
+#if defined (__STDC__) || defined (__cplusplus)
+   typedef signed char yysigned_char;
+#else
+   typedef short yysigned_char;
+#endif
+
 /* YYFINAL -- State number of the termination state. */
 #define YYFINAL  3
-#define YYLAST   127
+#define YYLAST   152
 
 /* YYNTOKENS -- Number of terminals. */
-#define YYNTOKENS  45
+#define YYNTOKENS  48
 /* YYNNTS -- Number of nonterminals. */
 #define YYNNTS  28
 /* YYNRULES -- Number of rules. */
-#define YYNRULES  75
+#define YYNRULES  77
 /* YYNRULES -- Number of states. */
-#define YYNSTATES  108
+#define YYNSTATES  116
 
 /* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
 #define YYUNDEFTOK  2
-#define YYMAXUTOK   299
+#define YYMAXUTOK   302
 
 #define YYTRANSLATE(X) \
   ((unsigned)(X) <= YYMAXUTOK ? yytranslate[X] : YYUNDEFTOK)
@@ -398,7 +407,8 @@ static const unsigned char yytranslate[] =
        5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
       15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
       25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
-      35,    36,    37,    38,    39,    40,    41,    42,    43,    44
+      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
+      45,    46,    47
 };
 
 #if YYDEBUG
@@ -407,51 +417,52 @@ static const unsigned char yytranslate[] =
 static const unsigned char yyprhs[] =
 {
        0,     0,     3,     8,     9,    13,    15,    17,    19,    23,
-      25,    27,    30,    34,    36,    40,    42,    46,    48,    50,
-      53,    55,    57,    59,    61,    63,    66,    69,    70,    75,
-      76,    81,    82,    86,    87,    91,    95,    99,   101,   103,
-     105,   106,   108,   110,   113,   115,   117,   120,   123,   127,
-     129,   132,   134,   137,   139,   142,   145,   146,   152,   154,
-     158,   159,   162,   165,   169,   173,   177,   179,   181,   183,
-     185,   187,   189,   190,   193,   194
+      25,    27,    30,    34,    36,    41,    43,    47,    49,    53,
+      58,    60,    63,    65,    67,    69,    71,    73,    76,    79,
+      80,    85,    86,    91,    92,    96,    97,   101,   105,   109,
+     111,   113,   115,   116,   118,   120,   123,   125,   127,   130,
+     133,   137,   139,   142,   144,   147,   149,   152,   155,   156,
+     162,   164,   168,   169,   172,   175,   179,   183,   187,   189,
+     191,   193,   195,   197,   199,   200,   203,   204
 };
 
 /* YYRHS -- A `-1'-separated list of the rules' RHS. */
-static const signed char yyrhs[] =
+static const yysigned_char yyrhs[] =
 {
-      46,     0,    -1,    47,    41,    61,    71,    -1,    -1,    47,
-      48,    72,    -1,    49,    -1,    42,    -1,    30,    -1,    25,
-      70,    70,    -1,    28,    -1,    21,    -1,    15,     5,    -1,
-      23,    36,    70,    -1,    31,    -1,    24,    36,    70,    -1,
-      32,    -1,    22,    36,    70,    -1,    26,    -1,    27,    -1,
-      33,    70,    -1,    34,    -1,    20,    -1,    29,    -1,    55,
-      -1,    52,    -1,    16,    67,    -1,    11,    44,    -1,    -1,
-       9,    50,    44,    58,    -1,    -1,    10,    51,    44,    58,
-      -1,    -1,     7,    53,    60,    -1,    -1,     6,    54,    60,
-      -1,     8,    35,    58,    -1,    56,    57,    58,    -1,    12,
-      -1,    13,    -1,    14,    -1,    -1,    35,    -1,    67,    -1,
-      58,    67,    -1,    35,    -1,    40,    -1,    40,     5,    -1,
-      40,    69,    -1,    40,     5,    69,    -1,    59,    -1,    60,
-      59,    -1,    62,    -1,    61,    62,    -1,    63,    -1,    49,
-      37,    -1,     1,    37,    -1,    -1,    40,    38,    64,    65,
-      37,    -1,    66,    -1,    65,    39,    66,    -1,    -1,    66,
-      67,    -1,    66,    68,    -1,    66,    17,    67,    -1,    66,
-      18,     5,    -1,    66,    19,    35,    -1,    40,    -1,    69,
-      -1,     4,    -1,    44,    -1,     3,    -1,     3,    -1,    -1,
-      41,    43,    -1,    -1,    37,    -1
+      49,     0,    -1,    50,    44,    64,    74,    -1,    -1,    50,
+      51,    75,    -1,    52,    -1,    45,    -1,    18,    -1,    19,
+      73,    73,    -1,    20,    -1,    21,    -1,    22,     5,    -1,
+      23,    38,    73,    -1,    24,    -1,    25,    73,    41,    73,
+      -1,    26,    -1,    27,    38,    73,    -1,    28,    -1,    29,
+      38,    73,    -1,    30,    73,    41,    73,    -1,    31,    -1,
+      32,    73,    -1,    34,    -1,    35,    -1,    36,    -1,    58,
+      -1,    55,    -1,    33,    70,    -1,    11,    47,    -1,    -1,
+       9,    53,    47,    61,    -1,    -1,    10,    54,    47,    61,
+      -1,    -1,     7,    56,    63,    -1,    -1,     6,    57,    63,
+      -1,     8,    37,    61,    -1,    59,    60,    61,    -1,    12,
+      -1,    13,    -1,    14,    -1,    -1,    37,    -1,    70,    -1,
+      61,    70,    -1,    37,    -1,    43,    -1,    43,     5,    -1,
+      43,    72,    -1,    43,     5,    72,    -1,    62,    -1,    63,
+      62,    -1,    65,    -1,    64,    65,    -1,    66,    -1,    52,
+      39,    -1,     1,    39,    -1,    -1,    43,    40,    67,    68,
+      39,    -1,    69,    -1,    68,    42,    69,    -1,    -1,    69,
+      70,    -1,    69,    71,    -1,    69,    15,    70,    -1,    69,
+      16,     5,    -1,    69,    17,    37,    -1,    43,    -1,    72,
+      -1,     4,    -1,    47,    -1,     3,    -1,     3,    -1,    -1,
+      44,    46,    -1,    -1,    39,    -1
 };
 
 /* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
 static const unsigned short yyrline[] =
 {
-       0,   162,   162,   175,   177,   180,   182,   183,   184,   185,
-     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
-     196,   197,   198,   201,   203,   204,   208,   215,   214,   225,
-     224,   237,   236,   242,   242,   247,   256,   271,   273,   274,
-     277,   279,   284,   286,   290,   295,   300,   306,   312,   322,
-     325,   334,   336,   342,   344,   349,   356,   355,   360,   362,
-     365,   368,   370,   372,   374,   376,   380,   382,   383,   386,
-     392,   401,   409,   414,   420,   422
+       0,   168,   168,   181,   183,   186,   188,   189,   190,   191,
+     192,   193,   194,   195,   196,   198,   199,   200,   201,   202,
+     204,   205,   206,   207,   208,   211,   213,   214,   218,   225,
+     224,   235,   234,   247,   246,   252,   252,   257,   266,   281,
+     283,   284,   287,   289,   294,   296,   300,   305,   310,   316,
+     322,   332,   335,   344,   346,   352,   354,   359,   366,   365,
+     370,   372,   375,   378,   380,   382,   384,   386,   390,   392,
+     393,   396,   402,   411,   419,   424,   430,   432
 };
 #endif
 
@@ -463,20 +474,20 @@ static const char *const yytname[] =
   "\"end of file\"", "error", "$undefined", "\"string\"", "\"character\"", 
   "\"integer\"", "\"%token\"", "\"%nterm\"", "\"%type\"", 
   "\"%destructor\"", "\"%printer\"", "\"%union\"", "\"%left\"", 
-  "\"%right\"", "\"%nonassoc\"", "\"%expect\"", "\"%start\"", "\"%prec\"", 
-  "\"%dprec\"", "\"%merge\"", "\"%verbose\"", "\"%error-verbose\"", 
-  "\"%output\"", "\"%file-prefix\"", "\"%name-prefix\"", "\"%define\"", 
-  "\"%pure-parser\"", "\"%glr-parser\"", "\"%defines\"", "\"%yacc\"", 
-  "\"%debug\"", "\"%locations\"", "\"%no-lines\"", "\"%skeleton\"", 
-  "\"%token-table\"", "\"type\"", "\"=\"", "\";\"", "\":\"", "\"|\"", 
-  "\"identifier\"", "\"%%\"", "\"%{...%}\"", "\"epilogue\"", "\"{...}\"", 
-  "$accept", "input", "declarations", "declaration", 
-  "grammar_declaration", "@1", "@2", "symbol_declaration", "@3", "@4", 
-  "precedence_declaration", "precedence_declarator", "type.opt", 
-  "symbols.1", "symbol_def", "symbol_defs.1", "grammar", 
-  "rules_or_grammar_declaration", "rules", "@5", "rhses.1", "rhs", 
-  "symbol", "action", "string_as_id", "string_content", "epilogue.opt", 
-  "semi_colon.opt", 0
+  "\"%right\"", "\"%nonassoc\"", "\"%prec\"", "\"%dprec\"", "\"%merge\"", 
+  "\"%debug\"", "\"%define\"", "\"%defines\"", "\"%error-verbose\"", 
+  "\"%expect\"", "\"%file-prefix\"", "\"%glr-parser\"", "\"%lex-param\"", 
+  "\"%locations\"", "\"%name-prefix\"", "\"%no-lines\"", "\"%output\"", 
+  "\"%parse-param\"", "\"%pure-parser\"", "\"%skeleton\"", "\"%start\"", 
+  "\"%token-table\"", "\"%verbose\"", "\"%yacc\"", "\"type\"", "\"=\"", 
+  "\";\"", "\":\"", "\",\"", "\"|\"", "\"identifier\"", "\"%%\"", 
+  "\"%{...%}\"", "\"epilogue\"", "\"{...}\"", "$accept", "input", 
+  "declarations", "declaration", "grammar_declaration", "@1", "@2", 
+  "symbol_declaration", "@3", "@4", "precedence_declaration", 
+  "precedence_declarator", "type.opt", "symbols.1", "symbol_def", 
+  "symbol_defs.1", "grammar", "rules_or_grammar_declaration", "rules", 
+  "@5", "rhses.1", "rhs", "symbol", "action", "string_as_id", 
+  "string_content", "epilogue.opt", "semi_colon.opt", 0
 };
 #endif
 
@@ -489,34 +500,34 @@ static const unsigned short yytoknum[] =
      265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
      275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
      285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
-     295,   296,   297,   298,   299
+     295,   296,   297,   298,   299,   300,   301,   302
 };
 # endif
 
 /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
 static const unsigned char yyr1[] =
 {
-       0,    45,    46,    47,    47,    48,    48,    48,    48,    48,
-      48,    48,    48,    48,    48,    48,    48,    48,    48,    48,
-      48,    48,    48,    49,    49,    49,    49,    50,    49,    51,
-      49,    53,    52,    54,    52,    52,    55,    56,    56,    56,
-      57,    57,    58,    58,    59,    59,    59,    59,    59,    60,
-      60,    61,    61,    62,    62,    62,    64,    63,    65,    65,
-      66,    66,    66,    66,    66,    66,    67,    67,    67,    68,
-      69,    70,    71,    71,    72,    72
+       0,    48,    49,    50,    50,    51,    51,    51,    51,    51,
+      51,    51,    51,    51,    51,    51,    51,    51,    51,    51,
+      51,    51,    51,    51,    51,    52,    52,    52,    52,    53,
+      52,    54,    52,    56,    55,    57,    55,    55,    58,    59,
+      59,    59,    60,    60,    61,    61,    62,    62,    62,    62,
+      62,    63,    63,    64,    64,    65,    65,    65,    67,    66,
+      68,    68,    69,    69,    69,    69,    69,    69,    70,    70,
+      70,    71,    72,    73,    74,    74,    75,    75
 };
 
 /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
 static const unsigned char yyr2[] =
 {
        0,     2,     4,     0,     3,     1,     1,     1,     3,     1,
-       1,     2,     3,     1,     3,     1,     3,     1,     1,     2,
-       1,     1,     1,     1,     1,     2,     2,     0,     4,     0,
-       4,     0,     3,     0,     3,     3,     3,     1,     1,     1,
-       0,     1,     1,     2,     1,     1,     2,     2,     3,     1,
-       2,     1,     2,     1,     2,     2,     0,     5,     1,     3,
-       0,     2,     2,     3,     3,     3,     1,     1,     1,     1,
-       1,     1,     0,     2,     0,     1
+       1,     2,     3,     1,     4,     1,     3,     1,     3,     4,
+       1,     2,     1,     1,     1,     1,     1,     2,     2,     0,
+       4,     0,     4,     0,     3,     0,     3,     3,     3,     1,
+       1,     1,     0,     1,     1,     2,     1,     1,     2,     2,
+       3,     1,     2,     1,     2,     1,     2,     2,     0,     5,
+       1,     3,     0,     2,     2,     3,     3,     3,     1,     1,
+       1,     1,     1,     1,     0,     2,     0,     1
 };
 
 /* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
@@ -524,106 +535,116 @@ static const unsigned char yyr2[] =
    means the default is an error.  */
 static const unsigned char yydefact[] =
 {
-       3,     0,     0,     1,    33,    31,     0,    27,    29,     0,
-      37,    38,    39,     0,     0,    21,    10,     0,     0,     0,
-       0,    17,    18,     9,    22,     7,    13,    15,     0,    20,
-       0,     6,    74,     5,    24,    23,    40,     0,     0,     0,
-       0,     0,    26,    11,    70,    68,    66,    25,    67,     0,
-       0,     0,    71,     0,    19,     0,     0,     0,     0,    51,
-      53,    75,     4,    41,     0,    44,    45,    49,    34,    32,
-      35,    42,     0,     0,    16,    12,    14,     8,    55,    56,
-      54,     0,    52,     2,    36,    46,    47,    50,    43,    28,
-      30,    60,    73,    48,     0,    58,    57,    60,     0,     0,
-       0,    69,    61,    62,    59,    63,    64,    65
+       3,     0,     0,     1,    35,    33,     0,    29,    31,     0,
+      39,    40,    41,     7,     0,     9,    10,     0,     0,    13,
+       0,    15,     0,    17,     0,     0,    20,     0,     0,    22,
+      23,    24,     0,     6,    76,     5,    26,    25,    42,     0,
+       0,     0,     0,     0,    28,    73,     0,    11,     0,     0,
+       0,     0,     0,    21,    72,    70,    68,    27,    69,     0,
+       0,     0,     0,    53,    55,    77,     4,    43,     0,    46,
+      47,    51,    36,    34,    37,    44,     0,     0,     8,    12,
+       0,    16,    18,     0,    57,    58,    56,     0,    54,     2,
+      38,    48,    49,    52,    45,    30,    32,    14,    19,    62,
+      75,    50,     0,    60,    59,    62,     0,     0,     0,    71,
+      63,    64,    61,    65,    66,    67
 };
 
 /* YYDEFGOTO[NTERM-NUM]. */
-static const signed char yydefgoto[] =
+static const yysigned_char yydefgoto[] =
 {
-      -1,     1,     2,    32,    57,    40,    41,    34,    38,    37,
-      35,    36,    64,    70,    67,    68,    58,    59,    60,    91,
-      94,    95,    71,   103,    48,    53,    83,    62
+      -1,     1,     2,    34,    61,    42,    43,    36,    40,    39,
+      37,    38,    68,    74,    71,    72,    62,    63,    64,    99,
+     102,   103,    75,   111,    58,    46,    89,    66
 };
 
 /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
    STATE-NUM.  */
-#define YYPACT_NINF -61
-static const signed char yypact[] =
+#define YYPACT_NINF -64
+static const yysigned_char yypact[] =
 {
-     -61,    35,    85,   -61,   -61,   -61,     2,   -61,   -61,    -5,
-     -61,   -61,   -61,    31,     0,   -61,   -61,    18,    21,    22,
-      59,   -61,   -61,   -61,   -61,   -61,   -61,   -61,    59,   -61,
-      37,   -61,    26,   -61,   -61,   -61,    29,   -19,   -19,     0,
-      23,    24,   -61,   -61,   -61,   -61,   -61,   -61,   -61,    59,
-      59,    59,   -61,    59,   -61,    28,    33,    32,     1,   -61,
-     -61,   -61,   -61,   -61,     0,   -61,    17,   -61,   -19,   -19,
-       0,   -61,     0,     0,   -61,   -61,   -61,   -61,   -61,   -61,
-     -61,    30,   -61,   -61,     0,    63,   -61,   -61,   -61,     0,
-       0,   -61,   -61,   -61,    -8,    15,   -61,   -61,     0,    67,
-      39,   -61,   -61,   -61,    15,   -61,   -61,   -61
+     -64,     9,   107,   -64,   -64,   -64,   -13,   -64,   -64,    -9,
+     -64,   -64,   -64,   -64,    27,   -64,   -64,    38,     3,   -64,
+      27,   -64,     6,   -64,     7,    27,   -64,    27,    -1,   -64,
+     -64,   -64,    79,   -64,    10,   -64,   -64,   -64,    13,   -17,
+     -17,    -1,     8,    11,   -64,   -64,    27,   -64,    27,    15,
+      27,    27,    16,   -64,   -64,   -64,   -64,   -64,   -64,    20,
+      14,    21,     4,   -64,   -64,   -64,   -64,   -64,    -1,   -64,
+      18,   -64,   -17,   -17,    -1,   -64,    -1,    -1,   -64,   -64,
+      27,   -64,   -64,    27,   -64,   -64,   -64,    17,   -64,   -64,
+      -1,    62,   -64,   -64,   -64,    -1,    -1,   -64,   -64,   -64,
+     -64,   -64,   -20,    36,   -64,   -64,    -1,    61,    32,   -64,
+     -64,   -64,    36,   -64,   -64,   -64
 };
 
 /* YYPGOTO[NTERM-NUM].  */
-static const signed char yypgoto[] =
+static const yysigned_char yypgoto[] =
 {
-     -61,   -61,   -61,   -61,    76,   -61,   -61,   -61,   -61,   -61,
-     -61,   -61,   -61,   -12,   -45,    41,   -61,    25,   -61,   -61,
-     -61,   -17,   -14,   -61,   -60,   -23,   -61,   -61
+     -64,   -64,   -64,   -64,    68,   -64,   -64,   -64,   -64,   -64,
+     -64,   -64,   -64,   -43,   -37,    31,   -64,    12,   -64,   -64,
+     -64,   -33,   -28,   -64,   -63,   -19,   -64,   -64
 };
 
 /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
    positive, shift that token.  If negative, reduce the rule which
-   number is the opposite.  If zero, do what YYDEFACT says.  */
-#define YYTABLE_NINF -62
-static const signed char yytable[] =
+   number is the opposite.  If zero, do what YYDEFACT says.
+   If YYTABLE_NINF, parse error.  */
+#define YYTABLE_NINF -75
+static const yysigned_char yytable[] =
 {
-      47,   -72,    55,    44,    45,    54,    86,     4,     5,     6,
-       7,     8,     9,    10,    11,    12,    65,    14,    44,    45,
-      44,    66,    85,    87,    87,    93,    74,    75,    76,    96,
-      77,    97,    98,    99,   100,     3,    43,    39,    55,    42,
-      46,    56,    81,     4,     5,     6,     7,     8,     9,    10,
-      11,    12,    84,    14,    49,    46,    88,    50,    51,   101,
-      89,    90,    52,    61,    63,    78,    44,    72,    73,    80,
-      88,    79,   106,    92,   107,    88,    88,    56,    33,    69,
-     104,   102,     0,    82,   105,     0,     0,     0,     0,     0,
-     102,     4,     5,     6,     7,     8,     9,    10,    11,    12,
-      13,    14,     0,     0,     0,    15,    16,    17,    18,    19,
-      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
-       0,     0,     0,     0,     0,     0,    30,    31
+      57,    49,    54,    55,   -74,    59,    52,    92,    53,     3,
+       4,     5,     6,     7,     8,     9,    10,    11,    12,   104,
+      69,    54,   105,    91,    41,    90,    70,    78,   101,    79,
+      45,    81,    82,    95,    96,    93,    93,    28,    44,    54,
+      55,    48,    56,    47,    50,    51,    94,    60,    87,    65,
+      67,   106,   107,   108,    85,    76,    80,    83,    77,    84,
+      86,    97,    94,   100,    98,    54,   114,    94,    94,   115,
+      35,    73,   112,     0,    88,   110,     0,     0,   113,    56,
+      59,     0,     0,   109,   110,     4,     5,     6,     7,     8,
+       9,    10,    11,    12,     0,     0,     0,     0,     0,     0,
+       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
+       0,     0,    28,     4,     5,     6,     7,     8,     9,    10,
+      11,    12,    60,     0,     0,    13,    14,    15,    16,    17,
+      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
+      28,    29,    30,    31,     0,     0,     0,     0,     0,     0,
+       0,    32,    33
 };
 
-static const signed char yycheck[] =
+static const yysigned_char yycheck[] =
 {
-      14,     0,     1,     3,     4,    28,    66,     6,     7,     8,
-       9,    10,    11,    12,    13,    14,    35,    16,     3,     4,
-       3,    40,     5,    68,    69,    85,    49,    50,    51,    37,
-      53,    39,    17,    18,    19,     0,     5,    35,     1,    44,
-      40,    40,    41,     6,     7,     8,     9,    10,    11,    12,
-      13,    14,    64,    16,    36,    40,    70,    36,    36,    44,
-      72,    73,     3,    37,    35,    37,     3,    44,    44,    37,
-      84,    38,     5,    43,    35,    89,    90,    40,     2,    38,
-      97,    95,    -1,    58,    98,    -1,    -1,    -1,    -1,    -1,
-     104,     6,     7,     8,     9,    10,    11,    12,    13,    14,
-      15,    16,    -1,    -1,    -1,    20,    21,    22,    23,    24,
-      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
-      -1,    -1,    -1,    -1,    -1,    -1,    41,    42
+      28,    20,     3,     4,     0,     1,    25,    70,    27,     0,
+       6,     7,     8,     9,    10,    11,    12,    13,    14,    39,
+      37,     3,    42,     5,    37,    68,    43,    46,    91,    48,
+       3,    50,    51,    76,    77,    72,    73,    33,    47,     3,
+       4,    38,    43,     5,    38,    38,    74,    43,    44,    39,
+      37,    15,    16,    17,    40,    47,    41,    41,    47,    39,
+      39,    80,    90,    46,    83,     3,     5,    95,    96,    37,
+       2,    40,   105,    -1,    62,   103,    -1,    -1,   106,    43,
+       1,    -1,    -1,    47,   112,     6,     7,     8,     9,    10,
+      11,    12,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,
+      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
+      -1,    -1,    33,     6,     7,     8,     9,    10,    11,    12,
+      13,    14,    43,    -1,    -1,    18,    19,    20,    21,    22,
+      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
+      33,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,
+      -1,    44,    45
 };
 
 /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
    symbol of state STATE-NUM.  */
 static const unsigned char yystos[] =
 {
-       0,    46,    47,     0,     6,     7,     8,     9,    10,    11,
-      12,    13,    14,    15,    16,    20,    21,    22,    23,    24,
+       0,    49,    50,     0,     6,     7,     8,     9,    10,    11,
+      12,    13,    14,    18,    19,    20,    21,    22,    23,    24,
       25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
-      41,    42,    48,    49,    52,    55,    56,    54,    53,    35,
-      50,    51,    44,     5,     3,     4,    40,    67,    69,    36,
-      36,    36,     3,    70,    70,     1,    40,    49,    61,    62,
-      63,    37,    72,    35,    57,    35,    40,    59,    60,    60,
-      58,    67,    44,    44,    70,    70,    70,    70,    37,    38,
-      37,    41,    62,    71,    58,     5,    69,    59,    67,    58,
-      58,    64,    43,    69,    65,    66,    37,    39,    17,    18,
-      19,    44,    67,    68,    66,    67,     5,    35
+      35,    36,    44,    45,    51,    52,    55,    58,    59,    57,
+      56,    37,    53,    54,    47,     3,    73,     5,    38,    73,
+      38,    38,    73,    73,     3,     4,    43,    70,    72,     1,
+      43,    52,    64,    65,    66,    39,    75,    37,    60,    37,
+      43,    62,    63,    63,    61,    70,    47,    47,    73,    73,
+      41,    73,    73,    41,    39,    40,    39,    44,    65,    74,
+      61,     5,    72,    62,    70,    61,    61,    73,    73,    67,
+      46,    72,    68,    69,    39,    42,    15,    16,    17,    47,
+      70,    71,    69,    70,     5,    37
 };
 
 #if ! defined (YYSIZE_T) && defined (__SIZE_TYPE__)
@@ -841,78 +862,6 @@ yysymprint (yyout, yytype, yyvalue, yylocation)
 #endif /* YYDEBUG. */
 
 
-/*----------------------------------------------------------.
-| yyreport_parse_error -- report a parse error in YYSTATE.  |
-`----------------------------------------------------------*/
-
-static void
-#if defined (__STDC__) || defined (__cplusplus)
-yyreport_parse_error (int yystate, int yychar, YYSTYPE yyvalue, YYLTYPE yylloc)
-#else
-yyreport_parse_error (yystate, yychar, yyvalue, yylloc)
-    int yystate;
-    int yychar;
-    YYSTYPE yyvalue;
-    YYLTYPE yylloc;
-#endif
-{
-#if YYERROR_VERBOSE
-  int yyn = yypact[yystate];
-
-  if (YYPACT_NINF < yyn && yyn < YYLAST)
-    {
-      YYSIZE_T yysize = 0;
-      int yytype = YYTRANSLATE (yychar);
-      char *yymsg;
-      int yyx, yycount;
-
-      yycount = 0;
-      /* Start YYX at -YYN if negative to avoid negative indexes in
-	 YYCHECK.  */
-      for (yyx = yyn < 0 ? -yyn : 0;
-	   yyx < (int) (sizeof (yytname) / sizeof (char *)); yyx++)
-	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
-	  yysize += yystrlen (yytname[yyx]) + 15, yycount++;
-      yysize += yystrlen ("parse error, unexpected ") + 1;
-      yysize += yystrlen (yytname[yytype]);
-      yymsg = (char *) YYSTACK_ALLOC (yysize);
-      if (yymsg != 0)
-	{
-	  char *yyp = yystpcpy (yymsg, "parse error, unexpected ");
-	  yyp = yystpcpy (yyp, yytname[yytype]);
-
-	  if (yycount < 5)
-	    {
-	      yycount = 0;
-	      for (yyx = yyn < 0 ? -yyn : 0;
-		   yyx < (int) (sizeof (yytname) / sizeof (char *));
-		   yyx++)
-		if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
-		  {
-		    const char *yyq = ! yycount ? ", expecting " : " or ";
-		    yyp = yystpcpy (yyp, yyq);
-		    yyp = yystpcpy (yyp, yytname[yyx]);
-		    yycount++;
-		  }
-	    }
-	  yyerror (yymsg);
-	  YYSTACK_FREE (yymsg);
-	}
-      else
-	yyerror ("parse error; also virtual memory exhausted");
-    }
-  else
-#endif /* YYERROR_VERBOSE */
-    yyerror ("parse error");
-
-  /* Pacify ``unused variable'' warnings.  */
-  (void) yystate;
-  (void) yychar;
-  (void) yyvalue;
-  (void) yylloc;
-}
-
-
 /*-----------------------------------------------.
 | Release the memory associated to this symbol.  |
 `-----------------------------------------------*/
@@ -1174,28 +1123,19 @@ yybackup:
       YYDPRINTF ((stderr, "\n"));
     }
 
+  /* If the proper action on seeing token YYCHAR1 is to reduce or to
+     detect an error, take that action.  */
   yyn += yychar1;
   if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yychar1)
     goto yydefault;
-
   yyn = yytable[yyn];
-
-  /* yyn is what to do for this token type in this state.
-     Negative => reduce, -yyn is rule number.
-     Positive => shift, yyn is new state.
-       New state is final state => don't bother to shift,
-       just return success.
-     0, or most negative number => error.  */
-
-  if (yyn < 0)
+  if (yyn <= 0)
     {
-      if (yyn == YYTABLE_NINF)
+      if (yyn == 0 || yyn == YYTABLE_NINF)
 	goto yyerrlab;
       yyn = -yyn;
       goto yyreduce;
     }
-  else if (yyn == 0)
-    goto yyerrlab;
 
   if (yyn == YYFINAL)
     YYACCEPT;
@@ -1269,7 +1209,7 @@ yyreduce:
   switch (yyn)
     {
         case 2:
-#line 164 "parse-gram.y"
+#line 170 "parse-gram.y"
     {
       yycontrol->errcode = 0;
       epilogue_set (yyvsp[0].string, yylsp[0]);
@@ -1277,99 +1217,109 @@ yyreduce:
     break;
 
   case 6:
-#line 182 "parse-gram.y"
+#line 188 "parse-gram.y"
     { prologue_augment (yyvsp[0].string, yylsp[0]); }
     break;
 
   case 7:
-#line 183 "parse-gram.y"
+#line 189 "parse-gram.y"
     { debug_flag = 1; }
     break;
 
   case 8:
-#line 184 "parse-gram.y"
+#line 190 "parse-gram.y"
     { muscle_insert (yyvsp[-1].string, yyvsp[0].string); }
     break;
 
   case 9:
-#line 185 "parse-gram.y"
+#line 191 "parse-gram.y"
     { defines_flag = 1; }
     break;
 
   case 10:
-#line 186 "parse-gram.y"
+#line 192 "parse-gram.y"
     { error_verbose = 1; }
     break;
 
   case 11:
-#line 187 "parse-gram.y"
+#line 193 "parse-gram.y"
     { expected_conflicts = yyvsp[0].integer; }
     break;
 
   case 12:
-#line 188 "parse-gram.y"
+#line 194 "parse-gram.y"
     { spec_file_prefix = yyvsp[0].string; }
     break;
 
   case 13:
-#line 189 "parse-gram.y"
-    { locations_flag = 1; }
+#line 195 "parse-gram.y"
+    { glr_parser = 1; }
     break;
 
   case 14:
-#line 190 "parse-gram.y"
-    { spec_name_prefix = yyvsp[0].string; }
+#line 197 "parse-gram.y"
+    { muscle_pair_list_grow ("lex_param", yyvsp[-2].string, yyvsp[0].string); }
     break;
 
   case 15:
-#line 191 "parse-gram.y"
-    { no_lines_flag = 1; }
+#line 198 "parse-gram.y"
+    { locations_flag = 1; }
     break;
 
   case 16:
-#line 192 "parse-gram.y"
-    { spec_outfile = yyvsp[0].string; }
+#line 199 "parse-gram.y"
+    { spec_name_prefix = yyvsp[0].string; }
     break;
 
   case 17:
-#line 193 "parse-gram.y"
-    { pure_parser = 1; }
+#line 200 "parse-gram.y"
+    { no_lines_flag = 1; }
     break;
 
   case 18:
-#line 194 "parse-gram.y"
-    { glr_parser = 1; }
+#line 201 "parse-gram.y"
+    { spec_outfile = yyvsp[0].string; }
     break;
 
   case 19:
-#line 195 "parse-gram.y"
-    { skeleton = yyvsp[0].string; }
+#line 203 "parse-gram.y"
+    { muscle_pair_list_grow ("parse_param", yyvsp[-2].string, yyvsp[0].string); }
     break;
 
   case 20:
-#line 196 "parse-gram.y"
-    { token_table_flag = 1; }
+#line 204 "parse-gram.y"
+    { pure_parser = 1; }
     break;
 
   case 21:
-#line 197 "parse-gram.y"
-    { report_flag = 1; }
+#line 205 "parse-gram.y"
+    { skeleton = yyvsp[0].string; }
     break;
 
   case 22:
-#line 198 "parse-gram.y"
+#line 206 "parse-gram.y"
+    { token_table_flag = 1; }
+    break;
+
+  case 23:
+#line 207 "parse-gram.y"
+    { report_flag = 1; }
+    break;
+
+  case 24:
+#line 208 "parse-gram.y"
     { yacc_flag = 1; }
     break;
 
-  case 25:
-#line 205 "parse-gram.y"
+  case 27:
+#line 215 "parse-gram.y"
     {
       grammar_start_symbol_set (yyvsp[0].symbol, yylsp[0]);
     }
     break;
 
-  case 26:
-#line 209 "parse-gram.y"
+  case 28:
+#line 219 "parse-gram.y"
     {
       typed = 1;
       MUSCLE_INSERT_INT ("stype_line", yylsp[0].first_line);
@@ -1377,13 +1327,13 @@ yyreduce:
     }
     break;
 
-  case 27:
-#line 215 "parse-gram.y"
+  case 29:
+#line 225 "parse-gram.y"
     { current_braced_code = destructor_braced_code; }
     break;
 
-  case 28:
-#line 217 "parse-gram.y"
+  case 30:
+#line 227 "parse-gram.y"
     {
       symbol_list_t *list;
       for (list = yyvsp[0].list; list; list = list->next)
@@ -1393,13 +1343,13 @@ yyreduce:
     }
     break;
 
-  case 29:
-#line 225 "parse-gram.y"
+  case 31:
+#line 235 "parse-gram.y"
     { current_braced_code = printer_braced_code; }
     break;
 
-  case 30:
-#line 227 "parse-gram.y"
+  case 32:
+#line 237 "parse-gram.y"
     {
       symbol_list_t *list;
       for (list = yyvsp[0].list; list; list = list->next)
@@ -1409,34 +1359,34 @@ yyreduce:
     }
     break;
 
-  case 31:
-#line 237 "parse-gram.y"
+  case 33:
+#line 247 "parse-gram.y"
     { current_class = nterm_sym; }
     break;
 
-  case 32:
-#line 238 "parse-gram.y"
+  case 34:
+#line 248 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
     break;
 
-  case 33:
-#line 242 "parse-gram.y"
+  case 35:
+#line 252 "parse-gram.y"
     { current_class = token_sym; }
     break;
 
-  case 34:
-#line 243 "parse-gram.y"
+  case 36:
+#line 253 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
     break;
 
-  case 35:
-#line 248 "parse-gram.y"
+  case 37:
+#line 258 "parse-gram.y"
     {
       symbol_list_t *list;
       for (list = yyvsp[0].list; list; list = list->next)
@@ -1445,8 +1395,8 @@ yyreduce:
     }
     break;
 
-  case 36:
-#line 258 "parse-gram.y"
+  case 38:
+#line 268 "parse-gram.y"
     {
       symbol_list_t *list;
       ++current_prec;
@@ -1460,58 +1410,58 @@ yyreduce:
     }
     break;
 
-  case 37:
-#line 272 "parse-gram.y"
+  case 39:
+#line 282 "parse-gram.y"
     { yyval.assoc = left_assoc; }
     break;
 
-  case 38:
-#line 273 "parse-gram.y"
+  case 40:
+#line 283 "parse-gram.y"
     { yyval.assoc = right_assoc; }
     break;
 
-  case 39:
-#line 274 "parse-gram.y"
+  case 41:
+#line 284 "parse-gram.y"
     { yyval.assoc = non_assoc; }
     break;
 
-  case 40:
-#line 278 "parse-gram.y"
+  case 42:
+#line 288 "parse-gram.y"
     { current_type = NULL;}
     break;
 
-  case 41:
-#line 279 "parse-gram.y"
+  case 43:
+#line 289 "parse-gram.y"
     { current_type = yyvsp[0].string; }
     break;
 
-  case 42:
-#line 285 "parse-gram.y"
+  case 44:
+#line 295 "parse-gram.y"
     { yyval.list = symbol_list_new (yyvsp[0].symbol, yylsp[0]); }
     break;
 
-  case 43:
-#line 286 "parse-gram.y"
+  case 45:
+#line 296 "parse-gram.y"
     { yyval.list = symbol_list_prepend (yyvsp[-1].list, yyvsp[0].symbol, yylsp[0]); }
     break;
 
-  case 44:
-#line 292 "parse-gram.y"
+  case 46:
+#line 302 "parse-gram.y"
     {
        current_type = yyvsp[0].string;
      }
     break;
 
-  case 45:
-#line 296 "parse-gram.y"
+  case 47:
+#line 306 "parse-gram.y"
     {
        symbol_class_set (yyvsp[0].symbol, current_class, yylsp[0]);
        symbol_type_set (yyvsp[0].symbol, current_type, yylsp[0]);
      }
     break;
 
-  case 46:
-#line 301 "parse-gram.y"
+  case 48:
+#line 311 "parse-gram.y"
     {
       symbol_class_set (yyvsp[-1].symbol, current_class, yylsp[-1]);
       symbol_type_set (yyvsp[-1].symbol, current_type, yylsp[-1]);
@@ -1519,8 +1469,8 @@ yyreduce:
     }
     break;
 
-  case 47:
-#line 307 "parse-gram.y"
+  case 49:
+#line 317 "parse-gram.y"
     {
       symbol_class_set (yyvsp[-1].symbol, current_class, yylsp[-1]);
       symbol_type_set (yyvsp[-1].symbol, current_type, yylsp[-1]);
@@ -1528,8 +1478,8 @@ yyreduce:
     }
     break;
 
-  case 48:
-#line 313 "parse-gram.y"
+  case 50:
+#line 323 "parse-gram.y"
     {
       symbol_class_set (yyvsp[-2].symbol, current_class, yylsp[-2]);
       symbol_type_set (yyvsp[-2].symbol, current_type, yylsp[-2]);
@@ -1538,126 +1488,126 @@ yyreduce:
     }
     break;
 
-  case 49:
-#line 324 "parse-gram.y"
+  case 51:
+#line 334 "parse-gram.y"
     {;}
     break;
 
-  case 50:
-#line 326 "parse-gram.y"
+  case 52:
+#line 336 "parse-gram.y"
     {;}
     break;
 
-  case 54:
-#line 345 "parse-gram.y"
+  case 56:
+#line 355 "parse-gram.y"
     {
       if (yacc_flag)
 	complain_at (yyloc, _("POSIX forbids declarations in the grammar"));
     }
     break;
 
-  case 55:
-#line 350 "parse-gram.y"
+  case 57:
+#line 360 "parse-gram.y"
     {
       yyerrok;
     }
     break;
 
-  case 56:
-#line 356 "parse-gram.y"
+  case 58:
+#line 366 "parse-gram.y"
     { current_lhs = yyvsp[-1].symbol; current_lhs_location = yylsp[-1]; }
     break;
 
-  case 57:
-#line 357 "parse-gram.y"
+  case 59:
+#line 367 "parse-gram.y"
     {;}
     break;
 
-  case 58:
-#line 361 "parse-gram.y"
+  case 60:
+#line 371 "parse-gram.y"
     { grammar_rule_end (yylsp[0]); }
     break;
 
-  case 59:
-#line 362 "parse-gram.y"
+  case 61:
+#line 372 "parse-gram.y"
     { grammar_rule_end (yylsp[0]); }
     break;
 
-  case 60:
-#line 367 "parse-gram.y"
+  case 62:
+#line 377 "parse-gram.y"
     { grammar_rule_begin (current_lhs, current_lhs_location); }
     break;
 
-  case 61:
-#line 369 "parse-gram.y"
+  case 63:
+#line 379 "parse-gram.y"
     { grammar_current_rule_symbol_append (yyvsp[0].symbol, yylsp[0]); }
     break;
 
-  case 62:
-#line 371 "parse-gram.y"
+  case 64:
+#line 381 "parse-gram.y"
     { grammar_current_rule_action_append (yyvsp[0].string, yylsp[0]); }
     break;
 
-  case 63:
-#line 373 "parse-gram.y"
+  case 65:
+#line 383 "parse-gram.y"
     { grammar_current_rule_prec_set (yyvsp[0].symbol, yylsp[0]); }
     break;
 
-  case 64:
-#line 375 "parse-gram.y"
+  case 66:
+#line 385 "parse-gram.y"
     { grammar_current_rule_dprec_set (yyvsp[0].integer, yylsp[0]); }
     break;
 
-  case 65:
-#line 377 "parse-gram.y"
+  case 67:
+#line 387 "parse-gram.y"
     { grammar_current_rule_merge_set (yyvsp[0].string, yylsp[0]); }
     break;
 
-  case 66:
-#line 381 "parse-gram.y"
+  case 68:
+#line 391 "parse-gram.y"
     { yyval.symbol = yyvsp[0].symbol; }
     break;
 
-  case 67:
-#line 382 "parse-gram.y"
+  case 69:
+#line 392 "parse-gram.y"
     { yyval.symbol = yyvsp[0].symbol; }
     break;
 
-  case 68:
-#line 383 "parse-gram.y"
+  case 70:
+#line 393 "parse-gram.y"
     { yyval.symbol = symbol_get (yyvsp[0].string, yylsp[0]); }
     break;
 
-  case 69:
-#line 388 "parse-gram.y"
+  case 71:
+#line 398 "parse-gram.y"
     { yyval.string = yyvsp[0].string; }
     break;
 
-  case 70:
-#line 394 "parse-gram.y"
+  case 72:
+#line 404 "parse-gram.y"
     {
       yyval.symbol = symbol_get (yyvsp[0].string, yylsp[0]);
       symbol_class_set (yyval.symbol, token_sym, yylsp[0]);
     }
     break;
 
-  case 71:
-#line 403 "parse-gram.y"
+  case 73:
+#line 413 "parse-gram.y"
     {
       yyval.string = yyvsp[0].string + 1;
       yyval.string[strlen (yyval.string) - 1] = '\0';
     }
     break;
 
-  case 72:
-#line 411 "parse-gram.y"
+  case 74:
+#line 421 "parse-gram.y"
     {
       yyval.string = xstrdup ("");
     }
     break;
 
-  case 73:
-#line 415 "parse-gram.y"
+  case 75:
+#line 425 "parse-gram.y"
     {
       yyval.string = yyvsp[0].string;
     }
@@ -1666,8 +1616,8 @@ yyreduce:
 
     }
 
-/* Line 1081 of /usr/local/share/bison/yacc.c.  */
-#line 1671 "parse-gram.c"
+/* Line 1016 of /usr/local/share/bison/yacc.c.  */
+#line 1621 "parse-gram.c"
 
   yyvsp -= yylen;
   yyssp -= yylen;
@@ -1710,7 +1660,54 @@ yyerrlab:
   if (!yyerrstatus)
     {
       ++yynerrs;
-      yyreport_parse_error (yystate, yychar, yylval, yylloc);
+#if YYERROR_VERBOSE
+      yyn = yypact[yystate];
+
+      if (YYPACT_NINF < yyn && yyn < YYLAST)
+	{
+	  YYSIZE_T yysize = 0;
+	  int yytype = YYTRANSLATE (yychar);
+	  char *yymsg;
+	  int yyx, yycount;
+
+	  yycount = 0;
+	  /* Start YYX at -YYN if negative to avoid negative indexes in
+	     YYCHECK.  */
+	  for (yyx = yyn < 0 ? -yyn : 0;
+	       yyx < (int) (sizeof (yytname) / sizeof (char *)); yyx++)
+	    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
+	      yysize += yystrlen (yytname[yyx]) + 15, yycount++;
+	  yysize += yystrlen ("parse error, unexpected ") + 1;
+	  yysize += yystrlen (yytname[yytype]);
+	  yymsg = (char *) YYSTACK_ALLOC (yysize);
+	  if (yymsg != 0)
+	    {
+	      char *yyp = yystpcpy (yymsg, "parse error, unexpected ");
+	      yyp = yystpcpy (yyp, yytname[yytype]);
+
+	      if (yycount < 5)
+		{
+		  yycount = 0;
+		  for (yyx = yyn < 0 ? -yyn : 0;
+		       yyx < (int) (sizeof (yytname) / sizeof (char *));
+		       yyx++)
+		    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
+		      {
+			const char *yyq = ! yycount ? ", expecting " : " or ";
+			yyp = yystpcpy (yyp, yyq);
+			yyp = yystpcpy (yyp, yytname[yyx]);
+			yycount++;
+		      }
+		}
+	      yyerror (yymsg);
+	      YYSTACK_FREE (yymsg);
+	    }
+	  else
+	    yyerror ("parse error; also virtual memory exhausted");
+	}
+      else
+#endif /* YYERROR_VERBOSE */
+	yyerror ("parse error");
     }
   goto yyerrlab1;
 
@@ -1839,7 +1836,7 @@ yyreturn:
 }
 
 
-#line 424 "parse-gram.y"
+#line 434 "parse-gram.y"
 
 /*------------------------------------------------------------------.
 | When debugging the parser, display tokens' locations and values.  |
