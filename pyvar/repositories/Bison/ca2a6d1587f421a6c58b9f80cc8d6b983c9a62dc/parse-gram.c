@@ -1,8 +1,9 @@
-/* A Bison parser, made by GNU Bison 2.4.483-4ad39-dirty.  */
+/* A Bison parser, made by GNU Bison 2.4.516-804e.  */
 
 /* Implementation for Bison's Yacc-like parsers in C
 
-   Copyright (C) 1984, 1989-1990, 2000-2010 Free Software Foundation, Inc.
+   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006,
+   2007, 2008, 2009, 2010 Free Software Foundation, Inc.
 
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
@@ -44,7 +45,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "2.4.483-4ad39-dirty"
+#define YYBISON_VERSION "2.4.516-804e"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -76,7 +77,8 @@
 #line 1 "src/parse-gram.y"
 /* Bison Grammar Parser                             -*- C -*-
 
-   Copyright (C) 2002-2010 Free Software Foundation, Inc.
+   Copyright (C) 2002, 2003, 2004, 2005, 2006, 2007, 2008, 2009, 2010
+   Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -127,7 +129,7 @@ static void gram_error (location const *, char const *);
 static char const *char_name (char);
 
 /* Line 252 of yacc.c  */
-#line 131 "src/parse-gram.c"
+#line 133 "src/parse-gram.c"
 
 /* Enabling traces.  */
 #ifndef YYDEBUG
@@ -149,7 +151,7 @@ static char const *char_name (char);
 
 /* "%code requires" blocks.  */
 /* Line 272 of yacc.c  */
-#line 201 "src/parse-gram.y"
+#line 202 "src/parse-gram.y"
 
 # ifndef PARAM_TYPE
 #  define PARAM_TYPE
@@ -164,7 +166,7 @@ static char const *char_name (char);
 
 
 /* Line 272 of yacc.c  */
-#line 168 "src/parse-gram.c"
+#line 170 "src/parse-gram.c"
 
 /* Tokens.  */
 #ifndef YYTOKENTYPE
@@ -211,21 +213,22 @@ static char const *char_name (char);
      PERCENT_VERBOSE = 293,
      PERCENT_YACC = 294,
      BRACED_CODE = 295,
-     BRACKETED_ID = 296,
-     CHAR = 297,
-     EPILOGUE = 298,
-     EQUAL = 299,
-     ID = 300,
-     ID_COLON = 301,
-     PERCENT_PERCENT = 302,
-     PIPE = 303,
-     PROLOGUE = 304,
-     SEMICOLON = 305,
-     TAG = 306,
-     TAG_ANY = 307,
-     TAG_NONE = 308,
-     PERCENT_PARAM = 309,
-     PERCENT_UNION = 310
+     BRACED_PREDICATE = 296,
+     BRACKETED_ID = 297,
+     CHAR = 298,
+     EPILOGUE = 299,
+     EQUAL = 300,
+     ID = 301,
+     ID_COLON = 302,
+     PERCENT_PERCENT = 303,
+     PIPE = 304,
+     PROLOGUE = 305,
+     SEMICOLON = 306,
+     TAG = 307,
+     TAG_ANY = 308,
+     TAG_NONE = 309,
+     PERCENT_PARAM = 310,
+     PERCENT_UNION = 311
    };
 #endif
 /* Tokens.  */
@@ -268,21 +271,22 @@ static char const *char_name (char);
 #define PERCENT_VERBOSE 293
 #define PERCENT_YACC 294
 #define BRACED_CODE 295
-#define BRACKETED_ID 296
-#define CHAR 297
-#define EPILOGUE 298
-#define EQUAL 299
-#define ID 300
-#define ID_COLON 301
-#define PERCENT_PERCENT 302
-#define PIPE 303
-#define PROLOGUE 304
-#define SEMICOLON 305
-#define TAG 306
-#define TAG_ANY 307
-#define TAG_NONE 308
-#define PERCENT_PARAM 309
-#define PERCENT_UNION 310
+#define BRACED_PREDICATE 296
+#define BRACKETED_ID 297
+#define CHAR 298
+#define EPILOGUE 299
+#define EQUAL 300
+#define ID 301
+#define ID_COLON 302
+#define PERCENT_PERCENT 303
+#define PIPE 304
+#define PROLOGUE 305
+#define SEMICOLON 306
+#define TAG 307
+#define TAG_ANY 308
+#define TAG_NONE 309
+#define PERCENT_PARAM 310
+#define PERCENT_UNION 311
 
 
 
@@ -291,7 +295,7 @@ static char const *char_name (char);
 typedef union YYSTYPE
 {
 /* Line 277 of yacc.c  */
-#line 87 "src/parse-gram.y"
+#line 88 "src/parse-gram.y"
 
   assoc assoc;
   char *code;
@@ -304,13 +308,13 @@ typedef union YYSTYPE
   unsigned char character;
 
 /* Line 277 of yacc.c  */
-#line 225 "src/parse-gram.y"
+#line 226 "src/parse-gram.y"
 
   param_type param;
 
 
 /* Line 277 of yacc.c  */
-#line 314 "src/parse-gram.c"
+#line 318 "src/parse-gram.c"
 } YYSTYPE;
 # define YYSTYPE_IS_TRIVIAL 1
 # define yystype YYSTYPE /* obsolescent; will be withdrawn */
@@ -334,10 +338,10 @@ typedef struct YYLTYPE
 /* Copy the second part of user declarations.  */
 
 /* Line 327 of yacc.c  */
-#line 338 "src/parse-gram.c"
+#line 342 "src/parse-gram.c"
 /* Unqualified %code blocks.  */
 /* Line 328 of yacc.c  */
-#line 55 "src/parse-gram.y"
+#line 56 "src/parse-gram.y"
 
   static int current_prec = 0;
   static location current_lhs_location;
@@ -352,7 +356,7 @@ typedef struct YYLTYPE
   #define YYTYPE_UINT8 uint_fast8_t
 
 /* Line 328 of yacc.c  */
-#line 214 "src/parse-gram.y"
+#line 215 "src/parse-gram.y"
 
   /** Add a lex-param and/or a parse-param.
    *
@@ -365,7 +369,7 @@ typedef struct YYLTYPE
 
 
 /* Line 328 of yacc.c  */
-#line 369 "src/parse-gram.c"
+#line 373 "src/parse-gram.c"
 
 #ifdef short
 # undef short
@@ -582,21 +586,21 @@ union yyalloc
 /* YYFINAL -- State number of the termination state.  */
 #define YYFINAL  3
 /* YYLAST -- Last index in YYTABLE.  */
-#define YYLAST   162
+#define YYLAST   163
 
 /* YYNTOKENS -- Number of terminals.  */
-#define YYNTOKENS  56
+#define YYNTOKENS  57
 /* YYNNTS -- Number of nonterminals.  */
 #define YYNNTS  36
 /* YYNRULES -- Number of rules.  */
-#define YYNRULES  109
+#define YYNRULES  110
 /* YYNSTATES -- Number of states.  */
-#define YYNSTATES  148
+#define YYNSTATES  149
 
 /* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
    by yylex, with out-of-bounds checking.  */
 #define YYUNDEFTOK  2
-#define YYMAXUTOK   310
+#define YYMAXUTOK   311
 
 #define YYTRANSLATE(YYX)						\
   ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)
@@ -636,24 +640,25 @@ static const yytype_uint8 yytranslate[] =
       25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
       35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
       45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
-      55
+      55,    56
 };
 
 #if YYDEBUG
   /* YYRLINEYYN -- Source line where rule number YYN was defined.    */
 static const yytype_uint16 yyrline[] =
 {
-       0,   250,   250,   258,   260,   264,   265,   275,   279,   284,
-     285,   290,   295,   296,   297,   298,   299,   304,   313,   314,
-     315,   316,   317,   318,   319,   320,   320,   321,   322,   346,
-     347,   348,   349,   353,   354,   363,   364,   365,   369,   376,
-     383,   387,   391,   398,   413,   414,   418,   430,   430,   435,
-     435,   440,   451,   466,   467,   468,   469,   473,   474,   479,
-     481,   486,   487,   492,   494,   499,   500,   504,   505,   506,
-     507,   512,   517,   522,   528,   534,   545,   546,   555,   556,
-     562,   563,   564,   571,   571,   576,   577,   578,   583,   585,
-     587,   589,   591,   593,   598,   600,   611,   612,   617,   618,
-     619,   628,   648,   650,   659,   664,   665,   670,   677,   679
+       0,   251,   251,   259,   261,   265,   266,   276,   280,   285,
+     286,   291,   296,   297,   298,   299,   300,   305,   314,   315,
+     316,   317,   318,   319,   320,   321,   321,   322,   323,   347,
+     348,   349,   350,   354,   355,   364,   365,   366,   370,   377,
+     384,   388,   392,   399,   414,   415,   419,   431,   431,   436,
+     436,   441,   452,   467,   468,   469,   470,   474,   475,   480,
+     482,   487,   488,   493,   495,   500,   501,   505,   506,   507,
+     508,   513,   518,   523,   529,   535,   546,   547,   556,   557,
+     563,   564,   565,   572,   572,   577,   578,   579,   584,   586,
+     588,   590,   592,   594,   596,   601,   603,   613,   614,   619,
+     620,   621,   630,   650,   652,   661,   666,   667,   672,   679,
+     681
 };
 #endif
 
@@ -672,10 +677,10 @@ static const char *const yytname[] =
   "\"%name-prefix\"", "\"%no-default-prec\"", "\"%no-lines\"",
   "\"%nondeterministic-parser\"", "\"%output\"", "\"%require\"",
   "\"%skeleton\"", "\"%start\"", "\"%token-table\"", "\"%verbose\"",
-  "\"%yacc\"", "\"{...}\"", "\"[identifier]\"", "\"char\"", "\"epilogue\"",
-  "\"=\"", "\"identifier\"", "\"identifier:\"", "\"%%\"", "\"|\"",
-  "\"%{...%}\"", "\";\"", "\"<tag>\"", "\"<*>\"", "\"<>\"", "\"%param\"",
-  "\"%union\"", "$accept", "input", "prologue_declarations",
+  "\"%yacc\"", "\"{...}\"", "\"%?{...}\"", "\"[identifier]\"", "\"char\"",
+  "\"epilogue\"", "\"=\"", "\"identifier\"", "\"identifier:\"", "\"%%\"",
+  "\"|\"", "\"%{...%}\"", "\";\"", "\"<tag>\"", "\"<*>\"", "\"<>\"",
+  "\"%param\"", "\"%union\"", "$accept", "input", "prologue_declarations",
   "prologue_declaration", "$@1", "params", "grammar_declaration",
   "union_name", "symbol_declaration", "$@2", "$@3",
   "precedence_declaration", "precedence_declarator", "tag.opt",
@@ -697,16 +702,16 @@ static const yytype_uint16 yytoknum[] =
      275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
      285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
      295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
-     305,   306,   307,   308,   309,   310
+     305,   306,   307,   308,   309,   310,   311
 };
 # endif
 
-#define YYPACT_NINF -137
+#define YYPACT_NINF -50
 
 #define yypact_value_is_default(yystate) \
-  ((yystate) == (-137))
+  ((yystate) == (-50))
 
-#define YYTABLE_NINF -109
+#define YYTABLE_NINF -110
 
 #define yytable_value_is_error(yytable_value) \
   YYID (0)
@@ -715,21 +720,21 @@ static const yytype_uint16 yytoknum[] =
      STATE-NUM.    */
 static const yytype_int16 yypact[] =
 {
-    -137,    20,   106,  -137,  -137,  -137,    19,    -1,    36,  -137,
-    -137,  -137,  -137,    13,  -137,     0,    79,  -137,    89,    90,
-    -137,    41,  -137,    55,    93,    46,  -137,  -137,  -137,    47,
-      94,    95,    35,  -137,  -137,  -137,    16,  -137,  -137,  -137,
-      54,  -137,  -137,  -137,  -137,    49,    33,    33,    35,    12,
-      12,  -137,    61,  -137,  -137,  -137,    29,  -137,  -137,  -137,
-    -137,   100,  -137,  -137,  -137,   101,  -137,   103,  -137,  -137,
-    -137,  -137,  -137,  -137,  -137,  -137,    57,  -137,    58,     1,
-    -137,  -137,    68,    80,  -137,    61,  -137,    35,  -137,  -137,
-      33,    56,    33,    35,  -137,  -137,  -137,  -137,    12,  -137,
-    -137,    12,  -137,  -137,  -137,  -137,  -137,  -137,  -137,  -137,
-    -137,    78,  -137,  -137,  -137,  -137,  -137,    82,  -137,    35,
-    -137,   142,  -137,   144,  -137,  -137,  -137,  -137,  -137,  -137,
-    -137,  -137,  -137,    18,    27,  -137,  -137,    35,   145,    97,
-      68,    68,    27,  -137,  -137,  -137,  -137,  -137
+     -50,     4,   107,   -50,   -50,   -50,   -20,     3,    11,   -50,
+     -50,   -50,   -50,    14,   -50,    12,    68,   -50,    72,    73,
+     -50,     0,   -50,    45,    86,     2,   -50,   -50,   -50,    17,
+      95,    96,    32,   -50,   -50,   -50,    16,   -50,   -50,   -50,
+      54,   -50,   -50,   -50,   -50,    49,    -2,    -2,    32,    27,
+      27,   -50,    63,   -50,   -50,   -50,    37,   -50,   -50,   -50,
+     -50,   101,   -50,   -50,   -50,   103,   -50,   104,   -50,   -50,
+     -50,   -50,   -50,   -50,   -50,   -50,    57,   -50,    58,     1,
+     -50,   -50,    79,    70,   -50,    63,   -50,    32,   -50,   -50,
+      -2,    64,    -2,    32,   -50,   -50,   -50,   -50,    27,   -50,
+     -50,    27,   -50,   -50,   -50,   -50,   -50,   -50,   -50,   -50,
+     -50,    78,   -50,   -50,   -50,   -50,   -50,    83,   -50,    32,
+     -50,   143,   -50,   145,   -50,   -50,   -50,   -50,   -50,   -50,
+     -50,   -50,   -50,    43,    50,   -50,   -50,    32,   146,    97,
+      79,   -50,    79,    50,   -50,   -50,   -50,   -50,   -50
 };
 
   /* YYDEFACT[S] -- default reduction number in state S.  Performed when
@@ -742,25 +747,25 @@ static const yytype_uint8 yydefact[] =
        7,     0,    16,     0,     0,     0,    41,    21,    22,     0,
        0,     0,     0,    29,    30,    31,     0,     6,    32,    25,
       44,     4,     5,    36,    35,    57,     0,     0,     0,     0,
-       0,   101,     0,    42,    97,    96,    98,    10,    12,    13,
+       0,   102,     0,    42,    98,    97,    99,    10,    12,    13,
       14,     0,    17,    18,    19,     0,    23,     0,    27,    28,
-     107,   103,   102,   105,    37,   106,     0,   104,     0,     0,
-      78,    80,    94,     0,    45,     0,    58,     0,    71,    76,
+     108,   104,   103,   106,    37,   107,     0,   105,     0,     0,
+      78,    80,    95,     0,    45,     0,    58,     0,    71,    76,
       50,    72,    48,    51,    63,    68,    69,    70,    38,    65,
-      67,    39,    43,   100,    99,     8,    15,    20,    24,    82,
-      81,     0,    79,     2,    95,    83,    34,    26,    46,    52,
-      59,    61,    77,    73,    74,    64,    66,   109,    88,    33,
+      67,    39,    43,   101,   100,     8,    15,    20,    24,    82,
+      81,     0,    79,     2,    96,    83,    34,    26,    46,    52,
+      59,    61,    77,    73,    74,    64,    66,   110,    88,    33,
       60,    62,    75,    84,    85,    88,    87,     0,     0,     0,
-      94,    94,    86,    91,    92,    93,    90,    89
+      95,    91,    95,    86,    92,    93,    94,    90,    89
 };
 
   /* YYPGOTO[NTERM-NUM].    */
 static const yytype_int16 yypgoto[] =
 {
-    -137,  -137,  -137,  -137,  -137,  -137,   148,  -137,  -137,  -137,
-    -137,  -137,  -137,  -137,  -137,    32,  -137,   102,    -9,    -4,
-     107,  -137,    83,  -137,  -137,  -137,    22,  -136,  -137,  -137,
-     -12,   -11,  -137,   -32,   -40,  -137
+     -50,   -50,   -50,   -50,   -50,   -50,   149,   -50,   -50,   -50,
+     -50,   -50,   -50,   -50,   -50,    33,   -50,   106,   -42,    -4,
+     112,   -50,    74,   -50,   -50,   -50,    19,   -45,   -50,   -50,
+     -16,    -8,   -50,   -32,   -49,   -50
 };
 
   /* YYDEFGOTO[NTERM-NUM].    */
@@ -777,81 +782,82 @@ static const yytype_int16 yydefgoto[] =
      number is the opposite.  If YYTABLE_NINF, syntax error.    */
 static const yytype_int16 yytable[] =
 {
-      74,  -108,    76,    54,   146,   147,     4,     5,     6,     7,
-       8,     9,    10,    11,    12,    70,    94,    76,    13,    14,
-       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
-      70,    26,   103,    13,    14,    91,    91,    32,    70,    49,
-     102,   137,   138,   139,    60,    55,    26,    77,   111,    64,
-      66,   124,    32,    51,    71,   121,    40,    72,    52,    70,
-     123,   125,    77,    95,    96,    97,   135,   140,   136,    71,
-      48,    40,    72,   118,   104,    71,    50,    71,    72,    91,
-      72,    91,    57,   132,    88,    61,   122,   121,   122,   126,
-      65,    67,   126,    58,    59,    62,    63,    68,    69,    84,
-      86,    51,   141,   106,   107,   143,   108,   109,   110,   114,
-     141,     4,     5,     6,     7,     8,     9,    10,    11,    12,
-     116,   127,   129,    13,    14,    15,    16,    17,    18,    19,
-      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
-      30,    31,    32,    33,    34,    35,   131,    70,   145,   144,
-      42,   130,   101,    36,    92,    37,    38,   142,     0,     0,
-      39,    40,   112
+      74,  -109,    76,    60,     3,    64,     4,     5,     6,     7,
+       8,     9,    10,    11,    12,    54,    94,    76,    13,    14,
+      66,     4,     5,     6,     7,     8,     9,    10,    11,    12,
+      70,    26,    48,    13,    14,    70,   102,    32,    91,    91,
+     103,    71,   124,    49,    72,    61,    26,    65,    77,   111,
+      88,    50,    32,    70,    51,   121,   126,    40,    55,   126,
+      52,   125,    67,    77,   137,   138,   139,    70,   123,   118,
+      71,    57,    40,    72,   132,    71,    58,    59,    72,    95,
+      96,    97,    91,   104,    91,    62,   122,   121,   122,    63,
+     140,   141,   135,    71,   136,   147,    72,   148,    68,    69,
+      84,    86,   142,    51,   106,   144,   107,   108,   109,   110,
+     116,   142,     4,     5,     6,     7,     8,     9,    10,    11,
+      12,   114,   127,   129,    13,    14,    15,    16,    17,    18,
+      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
+      29,    30,    31,    32,    33,    34,    35,   131,    70,   146,
+     145,    42,   130,   112,   143,    36,   101,    37,    38,    92,
+       0,     0,    39,    40
 };
 
 static const yytype_int16 yycheck[] =
 {
-      32,     0,     1,     3,   140,   141,     5,     6,     7,     8,
+      32,     0,     1,     3,     0,     3,     5,     6,     7,     8,
        9,    10,    11,    12,    13,     3,    48,     1,    17,    18,
-       0,     5,     6,     7,     8,     9,    10,    11,    12,    13,
-       3,    30,     3,    17,    18,    46,    47,    36,     3,    40,
-      52,    14,    15,    16,     3,    45,    30,    46,    47,     3,
-       3,    91,    36,    40,    42,    87,    55,    45,    45,     3,
-       4,    93,    46,    51,    52,    53,    48,    40,    50,    42,
-      51,    55,    45,    85,    45,    42,    40,    42,    45,    90,
-      45,    92,     3,   123,    51,    44,    90,   119,    92,    98,
-      44,    44,   101,     4,     4,    40,     3,     3,     3,    45,
-      51,    40,   134,     3,     3,   137,     3,    50,    50,    41,
-     142,     5,     6,     7,     8,     9,    10,    11,    12,    13,
-      40,    43,    40,    17,    18,    19,    20,    21,    22,    23,
-      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
-      34,    35,    36,    37,    38,    39,     4,     3,    51,     4,
-       2,   119,    50,    47,    47,    49,    50,   135,    -1,    -1,
-      54,    55,    79
+       3,     5,     6,     7,     8,     9,    10,    11,    12,    13,
+       3,    30,    52,    17,    18,     3,    52,    36,    46,    47,
+       3,    43,    91,    40,    46,    45,    30,    45,    47,    48,
+      52,    40,    36,     3,    40,    87,    98,    56,    46,   101,
+      46,    93,    45,    47,    14,    15,    16,     3,     4,    85,
+      43,     3,    56,    46,   123,    43,     4,     4,    46,    52,
+      53,    54,    90,    46,    92,    40,    90,   119,    92,     3,
+      40,    41,    49,    43,    51,   140,    46,   142,     3,     3,
+      46,    52,   134,    40,     3,   137,     3,     3,    51,    51,
+      40,   143,     5,     6,     7,     8,     9,    10,    11,    12,
+      13,    42,    44,    40,    17,    18,    19,    20,    21,    22,
+      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
+      33,    34,    35,    36,    37,    38,    39,     4,     3,    52,
+       4,     2,   119,    79,   135,    48,    50,    50,    51,    47,
+      -1,    -1,    55,    56
 };
 
   /* STOS_[STATE-NUM] -- The (internal number of the) accessing
      symbol of state STATE-NUM.    */
 static const yytype_uint8 yystos[] =
 {
-       0,    57,    58,     0,     5,     6,     7,     8,     9,    10,
+       0,    58,    59,     0,     5,     6,     7,     8,     9,    10,
       11,    12,    13,    17,    18,    19,    20,    21,    22,    23,
       24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
-      34,    35,    36,    37,    38,    39,    47,    49,    50,    54,
-      55,    59,    62,    64,    67,    68,    66,    65,    51,    40,
-      40,    40,    45,    86,     3,    45,    84,     3,     4,     4,
-       3,    44,    40,     3,     3,    44,     3,    44,     3,     3,
-       3,    42,    45,    87,    89,    90,     1,    46,    62,    77,
-      78,    79,    88,    60,    45,    63,    51,    69,    51,    75,
-      76,    87,    76,    72,    89,    51,    52,    53,    73,    74,
-      89,    73,    86,     3,    45,    85,     3,     3,     3,    50,
-      50,    47,    78,    91,    41,    83,    40,    61,    86,    70,
-      71,    89,    75,     4,    90,    89,    74,    43,    80,    40,
-      71,     4,    90,    81,    82,    48,    50,    14,    15,    16,
-      40,    89,    82,    89,     4,    51,    83,    83
+      34,    35,    36,    37,    38,    39,    48,    50,    51,    55,
+      56,    60,    63,    65,    68,    69,    67,    66,    52,    40,
+      40,    40,    46,    87,     3,    46,    85,     3,     4,     4,
+       3,    45,    40,     3,     3,    45,     3,    45,     3,     3,
+       3,    43,    46,    88,    90,    91,     1,    47,    63,    78,
+      79,    80,    89,    61,    46,    64,    52,    70,    52,    76,
+      77,    88,    77,    73,    90,    52,    53,    54,    74,    75,
+      90,    74,    87,     3,    46,    86,     3,     3,     3,    51,
+      51,    48,    79,    92,    42,    84,    40,    62,    87,    71,
+      72,    90,    76,     4,    91,    90,    75,    44,    81,    40,
+      72,     4,    91,    82,    83,    49,    51,    14,    15,    16,
+      40,    41,    90,    83,    90,     4,    52,    84,    84
 };
 
   /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.    */
 static const yytype_uint8 yyr1[] =
 {
-       0,    56,    57,    58,    58,    59,    59,    59,    59,    59,
-      59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
-      59,    59,    59,    59,    59,    60,    59,    59,    59,    59,
-      59,    59,    59,    61,    61,    62,    62,    62,    62,    62,
-      62,    62,    62,    62,    63,    63,    62,    65,    64,    66,
-      64,    64,    67,    68,    68,    68,    68,    69,    69,    70,
-      70,    71,    71,    72,    72,    73,    73,    74,    74,    74,
-      74,    75,    75,    75,    75,    75,    76,    76,    77,    77,
-      78,    78,    78,    80,    79,    81,    81,    81,    82,    82,
-      82,    82,    82,    82,    83,    83,    84,    84,    85,    85,
-      85,    86,    87,    87,    88,    89,    89,    90,    91,    91
+       0,    57,    58,    59,    59,    60,    60,    60,    60,    60,
+      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
+      60,    60,    60,    60,    60,    61,    60,    60,    60,    60,
+      60,    60,    60,    62,    62,    63,    63,    63,    63,    63,
+      63,    63,    63,    63,    64,    64,    63,    66,    65,    67,
+      65,    65,    68,    69,    69,    69,    69,    70,    70,    71,
+      71,    72,    72,    73,    73,    74,    74,    75,    75,    75,
+      75,    76,    76,    76,    76,    76,    77,    77,    78,    78,
+      79,    79,    79,    81,    80,    82,    82,    82,    83,    83,
+      83,    83,    83,    83,    83,    84,    84,    85,    85,    86,
+      86,    86,    87,    88,    88,    89,    90,    90,    91,    92,
+      92
 };
 
   /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.    */
@@ -866,8 +872,9 @@ static const yytype_uint8 yyr2[] =
        2,     1,     2,     1,     2,     1,     2,     1,     1,     1,
        1,     1,     1,     2,     2,     3,     1,     2,     1,     2,
        1,     2,     2,     0,     4,     1,     3,     2,     0,     3,
-       3,     3,     3,     3,     0,     1,     1,     1,     0,     1,
-       1,     1,     1,     1,     1,     1,     1,     1,     0,     2
+       3,     2,     3,     3,     3,     0,     1,     1,     1,     0,
+       1,     1,     1,     1,     1,     1,     1,     1,     1,     0,
+       2
 };
 
 
@@ -1027,106 +1034,106 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
             case 3: // "string"
 
 /* Line 729 of yacc.c  */
-#line 174 "src/parse-gram.y"
+#line 175 "src/parse-gram.y"
         { fputs (quotearg_style (c_quoting_style, ((*yyvaluep).chars)), stderr); }
 /* Line 729 of yacc.c  */
-#line 1034 "src/parse-gram.c"
+#line 1041 "src/parse-gram.c"
         break;
 
             case 4: // "integer"
 
 /* Line 729 of yacc.c  */
-#line 187 "src/parse-gram.y"
+#line 188 "src/parse-gram.y"
         { fprintf (stderr, "%d", ((*yyvaluep).integer)); }
 /* Line 729 of yacc.c  */
-#line 1043 "src/parse-gram.c"
+#line 1050 "src/parse-gram.c"
         break;
 
             case 24: // "%<flag>"
 
 /* Line 729 of yacc.c  */
-#line 183 "src/parse-gram.y"
+#line 184 "src/parse-gram.y"
         { fprintf (stderr, "%%%s", ((*yyvaluep).uniqstr)); }
 /* Line 729 of yacc.c  */
-#line 1052 "src/parse-gram.c"
+#line 1059 "src/parse-gram.c"
         break;
 
             case 40: // "{...}"
 
 /* Line 729 of yacc.c  */
-#line 176 "src/parse-gram.y"
+#line 177 "src/parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).code)); }
 /* Line 729 of yacc.c  */
-#line 1061 "src/parse-gram.c"
+#line 1068 "src/parse-gram.c"
         break;
 
-            case 41: // "[identifier]"
+            case 42: // "[identifier]"
 
 /* Line 729 of yacc.c  */
-#line 181 "src/parse-gram.y"
+#line 182 "src/parse-gram.y"
         { fprintf (stderr, "[%s]", ((*yyvaluep).uniqstr)); }
 /* Line 729 of yacc.c  */
-#line 1070 "src/parse-gram.c"
+#line 1077 "src/parse-gram.c"
         break;
 
-            case 42: // "char"
+            case 43: // "char"
 
 /* Line 729 of yacc.c  */
-#line 168 "src/parse-gram.y"
+#line 169 "src/parse-gram.y"
         { fputs (char_name (((*yyvaluep).character)), stderr); }
 /* Line 729 of yacc.c  */
-#line 1079 "src/parse-gram.c"
+#line 1086 "src/parse-gram.c"
         break;
 
-            case 43: // "epilogue"
+            case 44: // "epilogue"
 
 /* Line 729 of yacc.c  */
-#line 176 "src/parse-gram.y"
+#line 177 "src/parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); }
 /* Line 729 of yacc.c  */
-#line 1088 "src/parse-gram.c"
+#line 1095 "src/parse-gram.c"
         break;
 
-            case 45: // "identifier"
+            case 46: // "identifier"
 
 /* Line 729 of yacc.c  */
-#line 180 "src/parse-gram.y"
+#line 181 "src/parse-gram.y"
         { fputs (((*yyvaluep).uniqstr), stderr); }
 /* Line 729 of yacc.c  */
-#line 1097 "src/parse-gram.c"
+#line 1104 "src/parse-gram.c"
         break;
 
-            case 46: // "identifier:"
+            case 47: // "identifier:"
 
 /* Line 729 of yacc.c  */
-#line 182 "src/parse-gram.y"
+#line 183 "src/parse-gram.y"
         { fprintf (stderr, "%s:", ((*yyvaluep).uniqstr)); }
 /* Line 729 of yacc.c  */
-#line 1106 "src/parse-gram.c"
+#line 1113 "src/parse-gram.c"
         break;
 
-            case 49: // "%{...%}"
+            case 50: // "%{...%}"
 
 /* Line 729 of yacc.c  */
-#line 176 "src/parse-gram.y"
+#line 177 "src/parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); }
 /* Line 729 of yacc.c  */
-#line 1115 "src/parse-gram.c"
+#line 1122 "src/parse-gram.c"
         break;
 
-            case 51: // "<tag>"
+            case 52: // "<tag>"
 
 /* Line 729 of yacc.c  */
-#line 184 "src/parse-gram.y"
+#line 185 "src/parse-gram.y"
         { fprintf (stderr, "<%s>", ((*yyvaluep).uniqstr)); }
 /* Line 729 of yacc.c  */
-#line 1124 "src/parse-gram.c"
+#line 1131 "src/parse-gram.c"
         break;
 
-            case 54: // "%param"
+            case 55: // "%param"
 
 /* Line 729 of yacc.c  */
-#line 230 "src/parse-gram.y"
+#line 231 "src/parse-gram.y"
         {
   switch (((*yyvaluep).param))
     {
@@ -1140,79 +1147,79 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
     }
 }
 /* Line 729 of yacc.c  */
-#line 1144 "src/parse-gram.c"
+#line 1151 "src/parse-gram.c"
         break;
 
-            case 71: // symbol.prec
+            case 72: // symbol.prec
 
 /* Line 729 of yacc.c  */
-#line 190 "src/parse-gram.y"
+#line 191 "src/parse-gram.y"
         { fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); }
 /* Line 729 of yacc.c  */
-#line 1153 "src/parse-gram.c"
+#line 1160 "src/parse-gram.c"
         break;
 
-            case 84: // variable
+            case 85: // variable
 
 /* Line 729 of yacc.c  */
-#line 180 "src/parse-gram.y"
+#line 181 "src/parse-gram.y"
         { fputs (((*yyvaluep).uniqstr), stderr); }
 /* Line 729 of yacc.c  */
-#line 1162 "src/parse-gram.c"
+#line 1169 "src/parse-gram.c"
         break;
 
-            case 85: // content.opt
+            case 86: // content.opt
 
 /* Line 729 of yacc.c  */
-#line 176 "src/parse-gram.y"
+#line 177 "src/parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); }
 /* Line 729 of yacc.c  */
-#line 1171 "src/parse-gram.c"
+#line 1178 "src/parse-gram.c"
         break;
 
-            case 86: // braceless
+            case 87: // braceless
 
 /* Line 729 of yacc.c  */
-#line 176 "src/parse-gram.y"
+#line 177 "src/parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); }
 /* Line 729 of yacc.c  */
-#line 1180 "src/parse-gram.c"
+#line 1187 "src/parse-gram.c"
         break;
 
-            case 87: // id
+            case 88: // id
 
 /* Line 729 of yacc.c  */
-#line 190 "src/parse-gram.y"
+#line 191 "src/parse-gram.y"
         { fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); }
 /* Line 729 of yacc.c  */
-#line 1189 "src/parse-gram.c"
+#line 1196 "src/parse-gram.c"
         break;
 
-            case 88: // id_colon
+            case 89: // id_colon
 
 /* Line 729 of yacc.c  */
-#line 191 "src/parse-gram.y"
+#line 192 "src/parse-gram.y"
         { fprintf (stderr, "%s:", ((*yyvaluep).symbol)->tag); }
 /* Line 729 of yacc.c  */
-#line 1198 "src/parse-gram.c"
+#line 1205 "src/parse-gram.c"
         break;
 
-            case 89: // symbol
+            case 90: // symbol
 
 /* Line 729 of yacc.c  */
-#line 190 "src/parse-gram.y"
+#line 191 "src/parse-gram.y"
         { fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); }
 /* Line 729 of yacc.c  */
-#line 1207 "src/parse-gram.c"
+#line 1214 "src/parse-gram.c"
         break;
 
-            case 90: // string_as_id
+            case 91: // string_as_id
 
 /* Line 729 of yacc.c  */
-#line 190 "src/parse-gram.y"
+#line 191 "src/parse-gram.y"
         { fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); }
 /* Line 729 of yacc.c  */
-#line 1216 "src/parse-gram.c"
+#line 1223 "src/parse-gram.c"
         break;
 
       default:
@@ -1743,7 +1750,7 @@ YYLTYPE yylloc;
 
 /* User initialization code.  */
 /* Line 1214 of yacc.c  */
-#line 79 "src/parse-gram.y"
+#line 80 "src/parse-gram.y"
 {
   /* Bison's grammar can initial empty locations, hence a default
      location is needed. */
@@ -1751,7 +1758,7 @@ YYLTYPE yylloc;
   boundary_set (&yylloc.end, current_file, 1, 1);
 }
 /* Line 1214 of yacc.c  */
-#line 1755 "src/parse-gram.c"
+#line 1762 "src/parse-gram.c"
   yylsp[0] = yylloc;
 
   goto yysetstate;
@@ -1938,7 +1945,7 @@ yyreduce:
     {
         case 6:
 /* Line 1427 of yacc.c  */
-#line 266 "src/parse-gram.y"
+#line 267 "src/parse-gram.y"
     {
       code_props plain_code;
       code_props_plain_init (&plain_code, (yyvsp[0].chars), (yylsp[0]));
@@ -1949,106 +1956,106 @@ yyreduce:
       code_scanner_last_string_free ();
     }
 /* Line 1427 of yacc.c  */
-#line 1953 "src/parse-gram.c"
+#line 1960 "src/parse-gram.c"
     break;
 
   case 7:
 /* Line 1427 of yacc.c  */
-#line 276 "src/parse-gram.y"
+#line 277 "src/parse-gram.y"
     {
       muscle_percent_define_ensure ((yyvsp[0].uniqstr), (yylsp[0]), true);
     }
 /* Line 1427 of yacc.c  */
-#line 1963 "src/parse-gram.c"
+#line 1970 "src/parse-gram.c"
     break;
 
   case 8:
 /* Line 1427 of yacc.c  */
-#line 280 "src/parse-gram.y"
+#line 281 "src/parse-gram.y"
     {
       muscle_percent_define_insert ((yyvsp[-1].uniqstr), (yylsp[-1]), (yyvsp[0].chars),
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
     }
 /* Line 1427 of yacc.c  */
-#line 1974 "src/parse-gram.c"
+#line 1981 "src/parse-gram.c"
     break;
 
   case 9:
 /* Line 1427 of yacc.c  */
-#line 284 "src/parse-gram.y"
+#line 285 "src/parse-gram.y"
     { defines_flag = true; }
 /* Line 1427 of yacc.c  */
-#line 1982 "src/parse-gram.c"
+#line 1989 "src/parse-gram.c"
     break;
 
   case 10:
 /* Line 1427 of yacc.c  */
-#line 286 "src/parse-gram.y"
+#line 287 "src/parse-gram.y"
     {
       defines_flag = true;
       spec_defines_file = xstrdup ((yyvsp[0].chars));
     }
 /* Line 1427 of yacc.c  */
-#line 1993 "src/parse-gram.c"
+#line 2000 "src/parse-gram.c"
     break;
 
   case 11:
 /* Line 1427 of yacc.c  */
-#line 291 "src/parse-gram.y"
+#line 292 "src/parse-gram.y"
     {
       muscle_percent_define_insert ("parse.error", (yylsp[0]), "verbose",
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
     }
 /* Line 1427 of yacc.c  */
-#line 2004 "src/parse-gram.c"
+#line 2011 "src/parse-gram.c"
     break;
 
   case 12:
 /* Line 1427 of yacc.c  */
-#line 295 "src/parse-gram.y"
+#line 296 "src/parse-gram.y"
     { expected_sr_conflicts = (yyvsp[0].integer); }
 /* Line 1427 of yacc.c  */
-#line 2012 "src/parse-gram.c"
+#line 2019 "src/parse-gram.c"
     break;
 
   case 13:
 /* Line 1427 of yacc.c  */
-#line 296 "src/parse-gram.y"
+#line 297 "src/parse-gram.y"
     { expected_rr_conflicts = (yyvsp[0].integer); }
 /* Line 1427 of yacc.c  */
-#line 2020 "src/parse-gram.c"
+#line 2027 "src/parse-gram.c"
     break;
 
   case 14:
 /* Line 1427 of yacc.c  */
-#line 297 "src/parse-gram.y"
+#line 298 "src/parse-gram.y"
     { spec_file_prefix = (yyvsp[0].chars); }
 /* Line 1427 of yacc.c  */
-#line 2028 "src/parse-gram.c"
+#line 2035 "src/parse-gram.c"
     break;
 
   case 15:
 /* Line 1427 of yacc.c  */
-#line 298 "src/parse-gram.y"
+#line 299 "src/parse-gram.y"
     { spec_file_prefix = (yyvsp[0].chars); }
 /* Line 1427 of yacc.c  */
-#line 2036 "src/parse-gram.c"
+#line 2043 "src/parse-gram.c"
     break;
 
   case 16:
 /* Line 1427 of yacc.c  */
-#line 300 "src/parse-gram.y"
+#line 301 "src/parse-gram.y"
     {
       nondeterministic_parser = true;
       glr_parser = true;
     }
 /* Line 1427 of yacc.c  */
-#line 2047 "src/parse-gram.c"
+#line 2054 "src/parse-gram.c"
     break;
 
   case 17:
 /* Line 1427 of yacc.c  */
-#line 305 "src/parse-gram.y"
+#line 306 "src/parse-gram.y"
     {
       code_props action;
       code_props_symbol_action_init (&action, (yyvsp[0].code), (yylsp[0]));
@@ -2058,92 +2065,92 @@ yyreduce:
       code_scanner_last_string_free ();
     }
 /* Line 1427 of yacc.c  */
-#line 2062 "src/parse-gram.c"
+#line 2069 "src/parse-gram.c"
     break;
 
   case 18:
 /* Line 1427 of yacc.c  */
-#line 313 "src/parse-gram.y"
+#line 314 "src/parse-gram.y"
     { language_argmatch ((yyvsp[0].chars), grammar_prio, (yylsp[-1])); }
 /* Line 1427 of yacc.c  */
-#line 2070 "src/parse-gram.c"
+#line 2077 "src/parse-gram.c"
     break;
 
   case 19:
 /* Line 1427 of yacc.c  */
-#line 314 "src/parse-gram.y"
+#line 315 "src/parse-gram.y"
     { spec_name_prefix = (yyvsp[0].chars); }
 /* Line 1427 of yacc.c  */
-#line 2078 "src/parse-gram.c"
+#line 2085 "src/parse-gram.c"
     break;
 
   case 20:
 /* Line 1427 of yacc.c  */
-#line 315 "src/parse-gram.y"
+#line 316 "src/parse-gram.y"
     { spec_name_prefix = (yyvsp[0].chars); }
 /* Line 1427 of yacc.c  */
-#line 2086 "src/parse-gram.c"
+#line 2093 "src/parse-gram.c"
     break;
 
   case 21:
 /* Line 1427 of yacc.c  */
-#line 316 "src/parse-gram.y"
+#line 317 "src/parse-gram.y"
     { no_lines_flag = true; }
 /* Line 1427 of yacc.c  */
-#line 2094 "src/parse-gram.c"
+#line 2101 "src/parse-gram.c"
     break;
 
   case 22:
 /* Line 1427 of yacc.c  */
-#line 317 "src/parse-gram.y"
+#line 318 "src/parse-gram.y"
     { nondeterministic_parser = true; }
 /* Line 1427 of yacc.c  */
-#line 2102 "src/parse-gram.c"
+#line 2109 "src/parse-gram.c"
     break;
 
   case 23:
 /* Line 1427 of yacc.c  */
-#line 318 "src/parse-gram.y"
+#line 319 "src/parse-gram.y"
     { spec_outfile = (yyvsp[0].chars); }
 /* Line 1427 of yacc.c  */
-#line 2110 "src/parse-gram.c"
+#line 2117 "src/parse-gram.c"
     break;
 
   case 24:
 /* Line 1427 of yacc.c  */
-#line 319 "src/parse-gram.y"
+#line 320 "src/parse-gram.y"
     { spec_outfile = (yyvsp[0].chars); }
 /* Line 1427 of yacc.c  */
-#line 2118 "src/parse-gram.c"
+#line 2125 "src/parse-gram.c"
     break;
 
   case 25:
 /* Line 1427 of yacc.c  */
-#line 320 "src/parse-gram.y"
+#line 321 "src/parse-gram.y"
     { current_param = (yyvsp[0].param); }
 /* Line 1427 of yacc.c  */
-#line 2126 "src/parse-gram.c"
+#line 2133 "src/parse-gram.c"
     break;
 
   case 26:
 /* Line 1427 of yacc.c  */
-#line 320 "src/parse-gram.y"
+#line 321 "src/parse-gram.y"
     { current_param = param_none; }
 /* Line 1427 of yacc.c  */
-#line 2134 "src/parse-gram.c"
+#line 2141 "src/parse-gram.c"
     break;
 
   case 27:
 /* Line 1427 of yacc.c  */
-#line 321 "src/parse-gram.y"
+#line 322 "src/parse-gram.y"
     { version_check (&(yylsp[0]), (yyvsp[0].chars)); }
 /* Line 1427 of yacc.c  */
-#line 2142 "src/parse-gram.c"
+#line 2149 "src/parse-gram.c"
     break;
 
   case 28:
 /* Line 1427 of yacc.c  */
-#line 323 "src/parse-gram.y"
+#line 324 "src/parse-gram.y"
     {
       char const *skeleton_user = (yyvsp[0].chars);
       if (strchr (skeleton_user, '/'))
@@ -2168,62 +2175,62 @@ yyreduce:
       skeleton_arg (skeleton_user, grammar_prio, (yylsp[-1]));
     }
 /* Line 1427 of yacc.c  */
-#line 2172 "src/parse-gram.c"
+#line 2179 "src/parse-gram.c"
     break;
 
   case 29:
 /* Line 1427 of yacc.c  */
-#line 346 "src/parse-gram.y"
+#line 347 "src/parse-gram.y"
     { token_table_flag = true; }
 /* Line 1427 of yacc.c  */
-#line 2180 "src/parse-gram.c"
+#line 2187 "src/parse-gram.c"
     break;
 
   case 30:
 /* Line 1427 of yacc.c  */
-#line 347 "src/parse-gram.y"
+#line 348 "src/parse-gram.y"
     { report_flag |= report_states; }
 /* Line 1427 of yacc.c  */
-#line 2188 "src/parse-gram.c"
+#line 2195 "src/parse-gram.c"
     break;
 
   case 31:
 /* Line 1427 of yacc.c  */
-#line 348 "src/parse-gram.y"
+#line 349 "src/parse-gram.y"
     { yacc_flag = true; }
 /* Line 1427 of yacc.c  */
-#line 2196 "src/parse-gram.c"
+#line 2203 "src/parse-gram.c"
     break;
 
   case 33:
 /* Line 1427 of yacc.c  */
-#line 353 "src/parse-gram.y"
+#line 354 "src/parse-gram.y"
     { add_param (current_param, (yyvsp[0].code), (yylsp[0])); }
 /* Line 1427 of yacc.c  */
-#line 2204 "src/parse-gram.c"
+#line 2211 "src/parse-gram.c"
     break;
 
   case 34:
 /* Line 1427 of yacc.c  */
-#line 354 "src/parse-gram.y"
+#line 355 "src/parse-gram.y"
     { add_param (current_param, (yyvsp[0].code), (yylsp[0])); }
 /* Line 1427 of yacc.c  */
-#line 2212 "src/parse-gram.c"
+#line 2219 "src/parse-gram.c"
     break;
 
   case 37:
 /* Line 1427 of yacc.c  */
-#line 366 "src/parse-gram.y"
+#line 367 "src/parse-gram.y"
     {
       grammar_start_symbol_set ((yyvsp[0].symbol), (yylsp[0]));
     }
 /* Line 1427 of yacc.c  */
-#line 2222 "src/parse-gram.c"
+#line 2229 "src/parse-gram.c"
     break;
 
   case 38:
 /* Line 1427 of yacc.c  */
-#line 370 "src/parse-gram.y"
+#line 371 "src/parse-gram.y"
     {
       symbol_list *list;
       for (list = (yyvsp[0].list); list; list = list->next)
@@ -2231,12 +2238,12 @@ yyreduce:
       symbol_list_free ((yyvsp[0].list));
     }
 /* Line 1427 of yacc.c  */
-#line 2235 "src/parse-gram.c"
+#line 2242 "src/parse-gram.c"
     break;
 
   case 39:
 /* Line 1427 of yacc.c  */
-#line 377 "src/parse-gram.y"
+#line 378 "src/parse-gram.y"
     {
       symbol_list *list;
       for (list = (yyvsp[0].list); list; list = list->next)
@@ -2244,32 +2251,32 @@ yyreduce:
       symbol_list_free ((yyvsp[0].list));
     }
 /* Line 1427 of yacc.c  */
-#line 2248 "src/parse-gram.c"
+#line 2255 "src/parse-gram.c"
     break;
 
   case 40:
 /* Line 1427 of yacc.c  */
-#line 384 "src/parse-gram.y"
+#line 385 "src/parse-gram.y"
     {
       default_prec = true;
     }
 /* Line 1427 of yacc.c  */
-#line 2258 "src/parse-gram.c"
+#line 2265 "src/parse-gram.c"
     break;
 
   case 41:
 /* Line 1427 of yacc.c  */
-#line 388 "src/parse-gram.y"
+#line 389 "src/parse-gram.y"
     {
       default_prec = false;
     }
 /* Line 1427 of yacc.c  */
-#line 2268 "src/parse-gram.c"
+#line 2275 "src/parse-gram.c"
     break;
 
   case 42:
 /* Line 1427 of yacc.c  */
-#line 392 "src/parse-gram.y"
+#line 393 "src/parse-gram.y"
     {
       /* Do not invoke muscle_percent_code_grow here since it invokes
          muscle_user_name_list_grow.  */
@@ -2277,89 +2284,89 @@ yyreduce:
       code_scanner_last_string_free ();
     }
 /* Line 1427 of yacc.c  */
-#line 2281 "src/parse-gram.c"
+#line 2288 "src/parse-gram.c"
     break;
 
   case 43:
 /* Line 1427 of yacc.c  */
-#line 399 "src/parse-gram.y"
+#line 400 "src/parse-gram.y"
     {
       muscle_percent_code_grow ((yyvsp[-1].uniqstr), (yylsp[-1]), (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
 /* Line 1427 of yacc.c  */
-#line 2292 "src/parse-gram.c"
+#line 2299 "src/parse-gram.c"
     break;
 
   case 44:
 /* Line 1427 of yacc.c  */
-#line 413 "src/parse-gram.y"
+#line 414 "src/parse-gram.y"
     {}
 /* Line 1427 of yacc.c  */
-#line 2300 "src/parse-gram.c"
+#line 2307 "src/parse-gram.c"
     break;
 
   case 45:
 /* Line 1427 of yacc.c  */
-#line 414 "src/parse-gram.y"
+#line 415 "src/parse-gram.y"
     { muscle_code_grow ("union_name", (yyvsp[0].uniqstr), (yylsp[0])); }
 /* Line 1427 of yacc.c  */
-#line 2308 "src/parse-gram.c"
+#line 2315 "src/parse-gram.c"
     break;
 
   case 46:
 /* Line 1427 of yacc.c  */
-#line 419 "src/parse-gram.y"
+#line 420 "src/parse-gram.y"
     {
       union_seen = true;
       muscle_code_grow ("stype", (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
 /* Line 1427 of yacc.c  */
-#line 2320 "src/parse-gram.c"
+#line 2327 "src/parse-gram.c"
     break;
 
   case 47:
 /* Line 1427 of yacc.c  */
-#line 430 "src/parse-gram.y"
+#line 431 "src/parse-gram.y"
     { current_class = nterm_sym; }
 /* Line 1427 of yacc.c  */
-#line 2328 "src/parse-gram.c"
+#line 2335 "src/parse-gram.c"
     break;
 
   case 48:
 /* Line 1427 of yacc.c  */
-#line 431 "src/parse-gram.y"
+#line 432 "src/parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
 /* Line 1427 of yacc.c  */
-#line 2339 "src/parse-gram.c"
+#line 2346 "src/parse-gram.c"
     break;
 
   case 49:
 /* Line 1427 of yacc.c  */
-#line 435 "src/parse-gram.y"
+#line 436 "src/parse-gram.y"
     { current_class = token_sym; }
 /* Line 1427 of yacc.c  */
-#line 2347 "src/parse-gram.c"
+#line 2354 "src/parse-gram.c"
     break;
 
   case 50:
 /* Line 1427 of yacc.c  */
-#line 436 "src/parse-gram.y"
+#line 437 "src/parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
 /* Line 1427 of yacc.c  */
-#line 2358 "src/parse-gram.c"
+#line 2365 "src/parse-gram.c"
     break;
 
   case 51:
 /* Line 1427 of yacc.c  */
-#line 441 "src/parse-gram.y"
+#line 442 "src/parse-gram.y"
     {
       symbol_list *list;
       tag_seen = true;
@@ -2368,12 +2375,12 @@ yyreduce:
       symbol_list_free ((yyvsp[0].list));
     }
 /* Line 1427 of yacc.c  */
-#line 2372 "src/parse-gram.c"
+#line 2379 "src/parse-gram.c"
     break;
 
   case 52:
 /* Line 1427 of yacc.c  */
-#line 452 "src/parse-gram.y"
+#line 453 "src/parse-gram.y"
     {
       symbol_list *list;
       ++current_prec;
@@ -2386,202 +2393,202 @@ yyreduce:
       current_type = NULL;
     }
 /* Line 1427 of yacc.c  */
-#line 2390 "src/parse-gram.c"
+#line 2397 "src/parse-gram.c"
     break;
 
   case 53:
 /* Line 1427 of yacc.c  */
-#line 466 "src/parse-gram.y"
+#line 467 "src/parse-gram.y"
     { (yyval.assoc) = left_assoc; }
 /* Line 1427 of yacc.c  */
-#line 2398 "src/parse-gram.c"
+#line 2405 "src/parse-gram.c"
     break;
 
   case 54:
 /* Line 1427 of yacc.c  */
-#line 467 "src/parse-gram.y"
+#line 468 "src/parse-gram.y"
     { (yyval.assoc) = right_assoc; }
 /* Line 1427 of yacc.c  */
-#line 2406 "src/parse-gram.c"
+#line 2413 "src/parse-gram.c"
     break;
 
   case 55:
 /* Line 1427 of yacc.c  */
-#line 468 "src/parse-gram.y"
+#line 469 "src/parse-gram.y"
     { (yyval.assoc) = non_assoc; }
 /* Line 1427 of yacc.c  */
-#line 2414 "src/parse-gram.c"
+#line 2421 "src/parse-gram.c"
     break;
 
   case 56:
 /* Line 1427 of yacc.c  */
-#line 469 "src/parse-gram.y"
+#line 470 "src/parse-gram.y"
     { (yyval.assoc) = precedence_assoc; }
 /* Line 1427 of yacc.c  */
-#line 2422 "src/parse-gram.c"
+#line 2429 "src/parse-gram.c"
     break;
 
   case 57:
 /* Line 1427 of yacc.c  */
-#line 473 "src/parse-gram.y"
+#line 474 "src/parse-gram.y"
     { current_type = NULL; }
 /* Line 1427 of yacc.c  */
-#line 2430 "src/parse-gram.c"
+#line 2437 "src/parse-gram.c"
     break;
 
   case 58:
 /* Line 1427 of yacc.c  */
-#line 474 "src/parse-gram.y"
+#line 475 "src/parse-gram.y"
     { current_type = (yyvsp[0].uniqstr); tag_seen = true; }
 /* Line 1427 of yacc.c  */
-#line 2438 "src/parse-gram.c"
+#line 2445 "src/parse-gram.c"
     break;
 
   case 59:
 /* Line 1427 of yacc.c  */
-#line 480 "src/parse-gram.y"
+#line 481 "src/parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
 /* Line 1427 of yacc.c  */
-#line 2446 "src/parse-gram.c"
+#line 2453 "src/parse-gram.c"
     break;
 
   case 60:
 /* Line 1427 of yacc.c  */
-#line 482 "src/parse-gram.y"
+#line 483 "src/parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
 /* Line 1427 of yacc.c  */
-#line 2454 "src/parse-gram.c"
+#line 2461 "src/parse-gram.c"
     break;
 
   case 61:
 /* Line 1427 of yacc.c  */
-#line 486 "src/parse-gram.y"
+#line 487 "src/parse-gram.y"
     { (yyval.symbol) = (yyvsp[0].symbol); }
 /* Line 1427 of yacc.c  */
-#line 2462 "src/parse-gram.c"
+#line 2469 "src/parse-gram.c"
     break;
 
   case 62:
 /* Line 1427 of yacc.c  */
-#line 487 "src/parse-gram.y"
+#line 488 "src/parse-gram.y"
     { (yyval.symbol) = (yyvsp[-1].symbol); symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0])); }
 /* Line 1427 of yacc.c  */
-#line 2470 "src/parse-gram.c"
+#line 2477 "src/parse-gram.c"
     break;
 
   case 63:
 /* Line 1427 of yacc.c  */
-#line 493 "src/parse-gram.y"
+#line 494 "src/parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
 /* Line 1427 of yacc.c  */
-#line 2478 "src/parse-gram.c"
+#line 2485 "src/parse-gram.c"
     break;
 
   case 64:
 /* Line 1427 of yacc.c  */
-#line 495 "src/parse-gram.y"
+#line 496 "src/parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
 /* Line 1427 of yacc.c  */
-#line 2486 "src/parse-gram.c"
+#line 2493 "src/parse-gram.c"
     break;
 
   case 65:
 /* Line 1427 of yacc.c  */
-#line 499 "src/parse-gram.y"
+#line 500 "src/parse-gram.y"
     { (yyval.list) = (yyvsp[0].list); }
 /* Line 1427 of yacc.c  */
-#line 2494 "src/parse-gram.c"
+#line 2501 "src/parse-gram.c"
     break;
 
   case 66:
 /* Line 1427 of yacc.c  */
-#line 500 "src/parse-gram.y"
+#line 501 "src/parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), (yyvsp[0].list)); }
 /* Line 1427 of yacc.c  */
-#line 2502 "src/parse-gram.c"
+#line 2509 "src/parse-gram.c"
     break;
 
   case 67:
 /* Line 1427 of yacc.c  */
-#line 504 "src/parse-gram.y"
+#line 505 "src/parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
 /* Line 1427 of yacc.c  */
-#line 2510 "src/parse-gram.c"
+#line 2517 "src/parse-gram.c"
     break;
 
   case 68:
 /* Line 1427 of yacc.c  */
-#line 505 "src/parse-gram.y"
+#line 506 "src/parse-gram.y"
     { (yyval.list) = symbol_list_type_new ((yyvsp[0].uniqstr), (yylsp[0])); }
 /* Line 1427 of yacc.c  */
-#line 2518 "src/parse-gram.c"
+#line 2525 "src/parse-gram.c"
     break;
 
   case 69:
 /* Line 1427 of yacc.c  */
-#line 506 "src/parse-gram.y"
+#line 507 "src/parse-gram.y"
     { (yyval.list) = symbol_list_default_tagged_new ((yylsp[0])); }
 /* Line 1427 of yacc.c  */
-#line 2526 "src/parse-gram.c"
+#line 2533 "src/parse-gram.c"
     break;
 
   case 70:
 /* Line 1427 of yacc.c  */
-#line 507 "src/parse-gram.y"
+#line 508 "src/parse-gram.y"
     { (yyval.list) = symbol_list_default_tagless_new ((yylsp[0])); }
 /* Line 1427 of yacc.c  */
-#line 2534 "src/parse-gram.c"
+#line 2541 "src/parse-gram.c"
     break;
 
   case 71:
 /* Line 1427 of yacc.c  */
-#line 513 "src/parse-gram.y"
+#line 514 "src/parse-gram.y"
     {
        current_type = (yyvsp[0].uniqstr);
        tag_seen = true;
      }
 /* Line 1427 of yacc.c  */
-#line 2545 "src/parse-gram.c"
+#line 2552 "src/parse-gram.c"
     break;
 
   case 72:
 /* Line 1427 of yacc.c  */
-#line 518 "src/parse-gram.y"
+#line 519 "src/parse-gram.y"
     {
        symbol_class_set ((yyvsp[0].symbol), current_class, (yylsp[0]), true);
        symbol_type_set ((yyvsp[0].symbol), current_type, (yylsp[0]));
      }
 /* Line 1427 of yacc.c  */
-#line 2556 "src/parse-gram.c"
+#line 2563 "src/parse-gram.c"
     break;
 
   case 73:
 /* Line 1427 of yacc.c  */
-#line 523 "src/parse-gram.y"
+#line 524 "src/parse-gram.y"
     {
       symbol_class_set ((yyvsp[-1].symbol), current_class, (yylsp[-1]), true);
       symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
       symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0]));
     }
 /* Line 1427 of yacc.c  */
-#line 2568 "src/parse-gram.c"
+#line 2575 "src/parse-gram.c"
     break;
 
   case 74:
 /* Line 1427 of yacc.c  */
-#line 529 "src/parse-gram.y"
+#line 530 "src/parse-gram.y"
     {
       symbol_class_set ((yyvsp[-1].symbol), current_class, (yylsp[-1]), true);
       symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
       symbol_make_alias ((yyvsp[-1].symbol), (yyvsp[0].symbol), (yyloc));
     }
 /* Line 1427 of yacc.c  */
-#line 2580 "src/parse-gram.c"
+#line 2587 "src/parse-gram.c"
     break;
 
   case 75:
 /* Line 1427 of yacc.c  */
-#line 535 "src/parse-gram.y"
+#line 536 "src/parse-gram.y"
     {
       symbol_class_set ((yyvsp[-2].symbol), current_class, (yylsp[-2]), true);
       symbol_type_set ((yyvsp[-2].symbol), current_type, (yylsp[-2]));
@@ -2589,136 +2596,144 @@ yyreduce:
       symbol_make_alias ((yyvsp[-2].symbol), (yyvsp[0].symbol), (yyloc));
     }
 /* Line 1427 of yacc.c  */
-#line 2593 "src/parse-gram.c"
+#line 2600 "src/parse-gram.c"
     break;
 
   case 82:
 /* Line 1427 of yacc.c  */
-#line 565 "src/parse-gram.y"
+#line 566 "src/parse-gram.y"
     {
       yyerrok;
     }
 /* Line 1427 of yacc.c  */
-#line 2603 "src/parse-gram.c"
+#line 2610 "src/parse-gram.c"
     break;
 
   case 83:
 /* Line 1427 of yacc.c  */
-#line 571 "src/parse-gram.y"
+#line 572 "src/parse-gram.y"
     { current_lhs = (yyvsp[-1].symbol); current_lhs_location = (yylsp[-1]);
     current_lhs_named_ref = (yyvsp[0].named_ref); }
 /* Line 1427 of yacc.c  */
-#line 2612 "src/parse-gram.c"
+#line 2619 "src/parse-gram.c"
     break;
 
   case 85:
 /* Line 1427 of yacc.c  */
-#line 576 "src/parse-gram.y"
+#line 577 "src/parse-gram.y"
     { grammar_current_rule_end ((yylsp[0])); }
 /* Line 1427 of yacc.c  */
-#line 2620 "src/parse-gram.c"
+#line 2627 "src/parse-gram.c"
     break;
 
   case 86:
 /* Line 1427 of yacc.c  */
-#line 577 "src/parse-gram.y"
+#line 578 "src/parse-gram.y"
     { grammar_current_rule_end ((yylsp[0])); }
 /* Line 1427 of yacc.c  */
-#line 2628 "src/parse-gram.c"
+#line 2635 "src/parse-gram.c"
     break;
 
   case 88:
 /* Line 1427 of yacc.c  */
-#line 583 "src/parse-gram.y"
+#line 584 "src/parse-gram.y"
     { grammar_current_rule_begin (current_lhs, current_lhs_location,
 				  current_lhs_named_ref); }
 /* Line 1427 of yacc.c  */
-#line 2637 "src/parse-gram.c"
+#line 2644 "src/parse-gram.c"
     break;
 
   case 89:
 /* Line 1427 of yacc.c  */
-#line 586 "src/parse-gram.y"
+#line 587 "src/parse-gram.y"
     { grammar_current_rule_symbol_append ((yyvsp[-1].symbol), (yylsp[-1]), (yyvsp[0].named_ref)); }
 /* Line 1427 of yacc.c  */
-#line 2645 "src/parse-gram.c"
+#line 2652 "src/parse-gram.c"
     break;
 
   case 90:
 /* Line 1427 of yacc.c  */
-#line 588 "src/parse-gram.y"
-    { grammar_current_rule_action_append ((yyvsp[-1].code), (yylsp[-1]), (yyvsp[0].named_ref)); }
+#line 589 "src/parse-gram.y"
+    { grammar_current_rule_action_append ((yyvsp[-1].code), (yylsp[-1]), (yyvsp[0].named_ref), false); }
 /* Line 1427 of yacc.c  */
-#line 2653 "src/parse-gram.c"
+#line 2660 "src/parse-gram.c"
     break;
 
   case 91:
 /* Line 1427 of yacc.c  */
-#line 590 "src/parse-gram.y"
-    { grammar_current_rule_prec_set ((yyvsp[0].symbol), (yylsp[0])); }
+#line 591 "src/parse-gram.y"
+    { grammar_current_rule_action_append ((yyvsp[0].code), (yylsp[0]), NULL, true); }
 /* Line 1427 of yacc.c  */
-#line 2661 "src/parse-gram.c"
+#line 2668 "src/parse-gram.c"
     break;
 
   case 92:
 /* Line 1427 of yacc.c  */
-#line 592 "src/parse-gram.y"
-    { grammar_current_rule_dprec_set ((yyvsp[0].integer), (yylsp[0])); }
+#line 593 "src/parse-gram.y"
+    { grammar_current_rule_prec_set ((yyvsp[0].symbol), (yylsp[0])); }
 /* Line 1427 of yacc.c  */
-#line 2669 "src/parse-gram.c"
+#line 2676 "src/parse-gram.c"
     break;
 
   case 93:
 /* Line 1427 of yacc.c  */
-#line 594 "src/parse-gram.y"
-    { grammar_current_rule_merge_set ((yyvsp[0].uniqstr), (yylsp[0])); }
+#line 595 "src/parse-gram.y"
+    { grammar_current_rule_dprec_set ((yyvsp[0].integer), (yylsp[0])); }
 /* Line 1427 of yacc.c  */
-#line 2677 "src/parse-gram.c"
+#line 2684 "src/parse-gram.c"
     break;
 
   case 94:
 /* Line 1427 of yacc.c  */
-#line 598 "src/parse-gram.y"
-    { (yyval.named_ref) = 0; }
+#line 597 "src/parse-gram.y"
+    { grammar_current_rule_merge_set ((yyvsp[0].uniqstr), (yylsp[0])); }
 /* Line 1427 of yacc.c  */
-#line 2685 "src/parse-gram.c"
+#line 2692 "src/parse-gram.c"
     break;
 
   case 95:
 /* Line 1427 of yacc.c  */
-#line 600 "src/parse-gram.y"
+#line 601 "src/parse-gram.y"
+    { (yyval.named_ref) = 0; }
+/* Line 1427 of yacc.c  */
+#line 2700 "src/parse-gram.c"
+    break;
+
+  case 96:
+/* Line 1427 of yacc.c  */
+#line 603 "src/parse-gram.y"
     { (yyval.named_ref) = named_ref_new((yyvsp[0].uniqstr), (yylsp[0])); }
 /* Line 1427 of yacc.c  */
-#line 2693 "src/parse-gram.c"
+#line 2708 "src/parse-gram.c"
     break;
 
-  case 97:
+  case 98:
 /* Line 1427 of yacc.c  */
-#line 612 "src/parse-gram.y"
+#line 614 "src/parse-gram.y"
     { (yyval.uniqstr) = uniqstr_new ((yyvsp[0].chars)); }
 /* Line 1427 of yacc.c  */
-#line 2701 "src/parse-gram.c"
+#line 2716 "src/parse-gram.c"
     break;
 
-  case 98:
+  case 99:
 /* Line 1427 of yacc.c  */
-#line 617 "src/parse-gram.y"
+#line 619 "src/parse-gram.y"
     { (yyval.chars) = ""; }
 /* Line 1427 of yacc.c  */
-#line 2709 "src/parse-gram.c"
+#line 2724 "src/parse-gram.c"
     break;
 
-  case 99:
+  case 100:
 /* Line 1427 of yacc.c  */
-#line 618 "src/parse-gram.y"
+#line 620 "src/parse-gram.y"
     { (yyval.chars) = (yyvsp[0].uniqstr); }
 /* Line 1427 of yacc.c  */
-#line 2717 "src/parse-gram.c"
+#line 2732 "src/parse-gram.c"
     break;
 
-  case 101:
+  case 102:
 /* Line 1427 of yacc.c  */
-#line 629 "src/parse-gram.y"
+#line 631 "src/parse-gram.y"
     {
       code_props plain_code;
       (yyvsp[0].code)[strlen ((yyvsp[0].code)) - 1] = '\n';
@@ -2728,51 +2743,51 @@ yyreduce:
       (yyval.chars) = plain_code.code;
     }
 /* Line 1427 of yacc.c  */
-#line 2732 "src/parse-gram.c"
+#line 2747 "src/parse-gram.c"
     break;
 
-  case 102:
+  case 103:
 /* Line 1427 of yacc.c  */
-#line 649 "src/parse-gram.y"
+#line 651 "src/parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
 /* Line 1427 of yacc.c  */
-#line 2740 "src/parse-gram.c"
+#line 2755 "src/parse-gram.c"
     break;
 
-  case 103:
+  case 104:
 /* Line 1427 of yacc.c  */
-#line 651 "src/parse-gram.y"
+#line 653 "src/parse-gram.y"
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[0].character)), (yylsp[0]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
       symbol_user_token_number_set ((yyval.symbol), (yyvsp[0].character), (yylsp[0]));
     }
 /* Line 1427 of yacc.c  */
-#line 2752 "src/parse-gram.c"
+#line 2767 "src/parse-gram.c"
     break;
 
-  case 104:
+  case 105:
 /* Line 1427 of yacc.c  */
-#line 659 "src/parse-gram.y"
+#line 661 "src/parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
 /* Line 1427 of yacc.c  */
-#line 2760 "src/parse-gram.c"
+#line 2775 "src/parse-gram.c"
     break;
 
-  case 107:
+  case 108:
 /* Line 1427 of yacc.c  */
-#line 671 "src/parse-gram.y"
+#line 673 "src/parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[0].chars)), (yylsp[0]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
     }
 /* Line 1427 of yacc.c  */
-#line 2771 "src/parse-gram.c"
+#line 2786 "src/parse-gram.c"
     break;
 
-  case 109:
+  case 110:
 /* Line 1427 of yacc.c  */
-#line 680 "src/parse-gram.y"
+#line 682 "src/parse-gram.y"
     {
       code_props plain_code;
       code_props_plain_init (&plain_code, (yyvsp[0].chars), (yylsp[0]));
@@ -2782,12 +2797,12 @@ yyreduce:
       code_scanner_last_string_free ();
     }
 /* Line 1427 of yacc.c  */
-#line 2786 "src/parse-gram.c"
+#line 2801 "src/parse-gram.c"
     break;
 
 
 /* Line 1427 of yacc.c  */
-#line 2791 "src/parse-gram.c"
+#line 2806 "src/parse-gram.c"
       default: break;
     }
   /* User semantic actions sometimes alter yychar, and that requires
@@ -3015,7 +3030,7 @@ yyreturn:
 }
 
 /* Line 1657 of yacc.c  */
-#line 690 "src/parse-gram.y"
+#line 692 "src/parse-gram.y"
 
 
 
