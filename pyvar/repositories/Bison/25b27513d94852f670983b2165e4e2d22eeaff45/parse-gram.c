@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 2.6.2.891-3f15-dirty.  */
+/* A Bison parser, made by GNU Bison 2.6.2.950-7c7ce-dirty.  */
 
 /* Bison implementation for Yacc-like parsers in C
 
@@ -44,7 +44,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "2.6.2.891-3f15-dirty"
+#define YYBISON_VERSION "2.6.2.950-7c7ce-dirty"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -70,7 +70,7 @@
 #define yylloc          gram_lloc
 
 /* Copy the first part of user declarations.  */
-/* Line 331 of yacc.c  */
+/* Line 353 of yacc.c  */
 #line 1 "src/parse-gram.y"
 /* Bison Grammar Parser                             -*- C -*-
 
@@ -127,7 +127,7 @@ static void gram_error (location const *, char const *);
 
 static char const *char_name (char);
 
-/* Line 331 of yacc.c  */
+/* Line 353 of yacc.c  */
 #line 132 "src/parse-gram.c"
 
 # ifndef YY_NULL
@@ -158,7 +158,7 @@ static char const *char_name (char);
 extern int gram_debug;
 #endif
 /* "%code requires" blocks.  */
-/* Line 347 of yacc.c  */
+/* Line 369 of yacc.c  */
 #line 223 "src/parse-gram.y"
 
 # ifndef PARAM_TYPE
@@ -173,7 +173,7 @@ extern int gram_debug;
 # endif
 
 
-/* Line 347 of yacc.c  */
+/* Line 369 of yacc.c  */
 #line 178 "src/parse-gram.c"
 
 /* Tokens.  */
@@ -300,7 +300,7 @@ extern int gram_debug;
 #if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
 typedef union YYSTYPE
 {
-/* Line 347 of yacc.c  */
+/* Line 369 of yacc.c  */
 #line 109 "src/parse-gram.y"
 
   assoc assoc;
@@ -313,16 +313,16 @@ typedef union YYSTYPE
   uniqstr uniqstr;
   unsigned char character;
 
-/* Line 347 of yacc.c  */
+/* Line 369 of yacc.c  */
 #line 247 "src/parse-gram.y"
 
   param_type param;
 
-/* Line 347 of yacc.c  */
-#line 426 "src/parse-gram.y"
+/* Line 369 of yacc.c  */
+#line 423 "src/parse-gram.y"
 code_props_type code_type;
 
-/* Line 347 of yacc.c  */
+/* Line 369 of yacc.c  */
 #line 327 "src/parse-gram.c"
 } YYSTYPE;
 # define YYSTYPE_IS_TRIVIAL 1
@@ -348,10 +348,10 @@ int gram_parse (void);
 
 /* Copy the second part of user declarations.  */
 
-/* Line 350 of yacc.c  */
+/* Line 372 of yacc.c  */
 #line 353 "src/parse-gram.c"
 /* Unqualified %code blocks.  */
-/* Line 351 of yacc.c  */
+/* Line 373 of yacc.c  */
 #line 58 "src/parse-gram.y"
 
   static int current_prec = 0;
@@ -384,7 +384,7 @@ int gram_parse (void);
   #define YYTYPE_UINT16 uint_fast16_t
   #define YYTYPE_UINT8 uint_fast8_t
 
-/* Line 351 of yacc.c  */
+/* Line 373 of yacc.c  */
 #line 236 "src/parse-gram.y"
 
   /** Add a lex-param and/or a parse-param.
@@ -397,7 +397,7 @@ int gram_parse (void);
   static param_type current_param = param_none;
 
 
-/* Line 351 of yacc.c  */
+/* Line 373 of yacc.c  */
 #line 402 "src/parse-gram.c"
 
 #ifdef short
@@ -447,19 +447,19 @@ typedef short int yytype_int16;
 # if defined YYENABLE_NLS && YYENABLE_NLS
 #  if ENABLE_NLS
 #   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
-#   define YY_(msgid) dgettext ("bison-runtime", msgid)
+#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
 #  endif
 # endif
 # ifndef YY_
-#  define YY_(msgid) msgid
+#  define YY_(Msgid) Msgid
 # endif
 #endif
 
 /* Suppress unused-variable warnings by "using" E.  */
 #ifdef __GNUC__
-# define YYUSE(e) ((void) (e))
+# define YYUSE(E) ((void) (E))
 #else
-# define YYUSE(e) /* empty */
+# define YYUSE(E) /* empty */
 #endif
 
 #if 1
@@ -572,16 +572,16 @@ union yyalloc
 /* YYFINAL -- State number of the termination state.  */
 #define YYFINAL  3
 /* YYLAST -- Last index in YYTABLE.  */
-#define YYLAST   163
+#define YYLAST   157
 
 /* YYNTOKENS -- Number of terminals.  */
 #define YYNTOKENS  57
 /* YYNNTS -- Number of nonterminals.  */
 #define YYNNTS  38
 /* YYNRULES -- Number of rules.  */
-#define YYNRULES  112
+#define YYNRULES  109
 /* YYNSTATES -- Number of states.  */
-#define YYNSTATES  149
+#define YYNSTATES  143
 
 /* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
    by yylex, with out-of-bounds checking.  */
@@ -634,17 +634,16 @@ static const yytype_uint8 yytranslate[] =
 static const yytype_uint16 yyrline[] =
 {
        0,   272,   272,   280,   282,   286,   287,   297,   301,   306,
-     307,   312,   317,   318,   319,   320,   321,   326,   335,   336,
-     337,   338,   339,   340,   341,   342,   342,   343,   344,   368,
-     369,   370,   371,   375,   376,   385,   386,   387,   391,   403,
-     407,   411,   418,   429,   430,   440,   441,   445,   457,   457,
-     462,   462,   467,   478,   493,   494,   495,   496,   500,   501,
-     506,   508,   513,   514,   519,   521,   526,   527,   531,   532,
-     536,   537,   538,   543,   548,   553,   559,   565,   576,   577,
-     586,   587,   593,   594,   595,   602,   602,   610,   611,   612,
-     617,   619,   621,   623,   625,   627,   629,   634,   636,   646,
-     647,   652,   653,   654,   663,   683,   685,   694,   699,   700,
-     705,   712,   714
+     307,   312,   317,   318,   319,   320,   325,   334,   335,   336,
+     337,   338,   339,   339,   340,   341,   365,   366,   367,   368,
+     372,   373,   382,   383,   384,   388,   400,   404,   408,   415,
+     426,   427,   437,   438,   442,   454,   454,   459,   459,   464,
+     475,   490,   491,   492,   493,   497,   498,   503,   505,   510,
+     511,   516,   518,   523,   524,   528,   529,   533,   534,   535,
+     540,   545,   550,   556,   562,   573,   574,   583,   584,   590,
+     591,   592,   599,   599,   607,   608,   609,   614,   616,   618,
+     620,   622,   624,   626,   631,   633,   643,   644,   649,   650,
+     651,   660,   680,   682,   691,   696,   697,   702,   709,   711
 };
 #endif
 
@@ -692,35 +691,35 @@ static const yytype_uint16 yytoknum[] =
 };
 # endif
 
-#define YYPACT_NINF -88
+#define YYPACT_NINF -74
 
-#define yypact_value_is_default(yystate) \
-  ((yystate) == (-88))
+#define yypact_value_is_default(Yystate) \
+  (!!((Yystate) == (-74)))
 
-#define YYTABLE_NINF -112
+#define YYTABLE_NINF -109
 
-#define yytable_value_is_error(yytable_value) \
+#define yytable_value_is_error(Yytable_value) \
   0
 
   /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
      STATE-NUM.    */
 static const yytype_int16 yypact[] =
 {
-     -88,    42,   107,   -88,   -88,   -88,     8,   -88,   -88,   -88,
-     -88,   -88,   -88,    19,   -88,    12,    60,   -88,    66,    72,
-     -88,     2,   -88,    39,    83,    35,   -88,   -88,   -88,    36,
-      87,    88,    32,   -88,   -88,   -88,    15,   -88,   -88,   -88,
-      46,   -88,   -88,    55,   -88,   -88,    45,    -2,    -2,    32,
-     -88,    58,   -88,   -88,   -88,    31,   -88,   -88,   -88,   -88,
-      97,   -88,   -88,   -88,    98,   -88,   100,   -88,   -88,   -88,
-     -88,   -88,   -88,   -88,   -88,    56,   -88,    57,     1,   -88,
-     -88,    62,    69,   -88,    58,     0,   -88,    32,   -88,   -88,
-      -2,    85,    -2,    32,   -88,   -88,   -88,   -88,   -88,   -88,
-     -88,   -88,   -88,   -88,    77,   -88,   -88,   -88,   -88,   -88,
-      70,   -88,   -88,   -88,   -88,     0,   -88,   -88,   -88,    32,
-     -88,   102,   -88,   119,   -88,   -88,   -88,   -88,   -88,   -88,
-     -88,   -88,   -88,    33,    53,   -88,   -88,    32,   143,    71,
-      62,   -88,    62,    53,   -88,   -88,   -88,   -88,   -88
+     -74,    40,   101,   -74,   -74,   -74,   -48,   -74,   -74,   -74,
+     -74,   -74,   -74,    19,   -74,     0,    52,   -74,    56,    79,
+     -74,    81,   -74,    45,    83,    84,   -74,   -74,   -74,    85,
+      86,    87,    31,   -74,   -74,   -74,    15,   -74,   -74,   -74,
+      46,   -74,   -74,    51,   -74,   -74,    42,     4,     4,    31,
+     -74,    57,   -74,   -74,   -74,    36,   -74,   -74,   -74,   -74,
+     -74,   -74,   -74,   -74,   -74,   -74,   -74,   -74,   -74,   -74,
+     -74,   -74,    47,   -74,    49,     1,   -74,   -74,    59,    62,
+     -74,    57,    26,   -74,    31,   -74,   -74,     4,    72,     4,
+      31,   -74,   -74,   -74,   -74,   -74,   -74,   -74,    60,   -74,
+     -74,   -74,   -74,   -74,    63,   -74,   -74,   -74,   -74,    26,
+     -74,   -74,   -74,    31,   -74,   111,   -74,   113,   -74,   -74,
+     -74,   -74,   -74,   -74,   -74,   -74,   -74,   -13,    27,   -74,
+     -74,    31,   137,    65,    59,   -74,    59,    27,   -74,   -74,
+     -74,   -74,   -74
 };
 
   /* YYDEFACT[S] -- default reduction number in state S.  Performed when
@@ -728,39 +727,39 @@ static const yytype_int16 yypact[] =
      is an error.    */
 static const yytype_uint8 yydefact[] =
 {
-       3,     0,     0,     1,    50,    48,     0,    43,    44,    54,
-      55,    56,    57,     0,    39,     0,     9,    11,     0,     0,
-       7,     0,    16,     0,     0,     0,    40,    21,    22,     0,
-       0,     0,     0,    29,    30,    31,     0,     6,    32,    25,
-      45,     4,     5,     0,    36,    35,    58,     0,     0,     0,
-     104,     0,    41,   100,    99,   101,    10,    12,    13,    14,
-       0,    17,    18,    19,     0,    23,     0,    27,    28,   110,
-     106,   105,   108,    37,   109,     0,   107,     0,     0,    80,
-      82,    97,     0,    46,     0,     0,    59,     0,    73,    78,
-      51,    74,    49,    52,    64,    42,   103,   102,     8,    15,
-      20,    24,    84,    83,     0,    81,     2,    98,    85,    34,
-      26,    47,    70,    71,    72,    38,    66,    69,    68,    53,
-      60,    62,    79,    75,    76,    65,   112,    90,    33,    67,
-      61,    63,    77,    86,    87,    90,    89,     0,     0,     0,
-      97,    93,    97,    88,    94,    95,    96,    92,    91
+       3,     0,     0,     1,    47,    45,     0,    40,    41,    51,
+      52,    53,    54,     0,    36,     0,     9,    11,     0,     0,
+       7,     0,    15,     0,     0,     0,    37,    19,    20,     0,
+       0,     0,     0,    26,    27,    28,     0,     6,    29,    22,
+      42,     4,     5,     0,    33,    32,    55,     0,     0,     0,
+     101,     0,    38,    97,    96,    98,    10,    12,    13,    14,
+      16,    17,    18,    21,    24,    25,   107,   103,   102,   105,
+      34,   106,     0,   104,     0,     0,    77,    79,    94,     0,
+      43,     0,     0,    56,     0,    70,    75,    48,    71,    46,
+      49,    61,    39,   100,    99,     8,    81,    80,     0,    78,
+       2,    95,    82,    31,    23,    44,    67,    68,    69,    35,
+      63,    66,    65,    50,    57,    59,    76,    72,    73,    62,
+     109,    87,    30,    64,    58,    60,    74,    83,    84,    87,
+      86,     0,     0,     0,    94,    90,    94,    85,    91,    92,
+      93,    89,    88
 };
 
   /* YYPGOTO[NTERM-NUM].    */
 static const yytype_int16 yypgoto[] =
 {
-     -88,   -88,   -88,   -88,   -88,   -88,   146,   -88,   -88,   -88,
-     -88,   -88,   -88,   -88,   -88,   -88,    30,   -88,   -88,    37,
-     -88,   -26,   103,   -88,    75,   -88,   -88,   -88,    21,   -57,
-     -88,   -88,   -11,   -18,   -88,   -32,   -87,   -88
+     -74,   -74,   -74,   -74,   -74,   -74,   140,   -74,   -74,   -74,
+     -74,   -74,   -74,   -74,   -74,   -74,    30,   -74,   -74,    35,
+     -74,   -26,    97,   -74,    71,   -74,   -74,   -74,    18,   -70,
+     -74,   -74,   -46,     6,   -74,   -32,   -73,   -74
 };
 
   /* YYDEFGOTO[NTERM-NUM].    */
 static const yytype_int16 yydefgoto[] =
 {
-      -1,     1,     2,    41,    82,   110,    77,    43,    84,    44,
-      48,    47,    45,    46,    87,   119,   120,    93,   115,   116,
-     117,    89,    90,    78,    79,    80,   127,   133,   134,   108,
-      55,    98,    52,    72,    81,   118,    74,   106
+      -1,     1,     2,    41,    79,   104,    74,    43,    81,    44,
+      48,    47,    45,    46,    84,   113,   114,    90,   109,   110,
+     111,    86,    87,    75,    76,    77,   121,   127,   128,   102,
+      55,    95,    52,    69,    78,   112,    71,   100
 };
 
   /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
@@ -768,44 +767,42 @@ static const yytype_int16 yydefgoto[] =
      number is the opposite.  If YYTABLE_NINF, syntax error.    */
 static const yytype_int16 yytable[] =
 {
-      73,  -111,    75,    69,   124,    59,     4,     5,     6,     7,
-       8,     9,    10,    11,    12,    53,    75,    94,    13,    14,
-       4,     5,     6,     7,     8,     9,    10,    11,    12,    91,
-      91,    26,    13,    14,    96,    69,   132,    32,    63,    65,
-      95,    70,     3,    70,    71,    26,    71,    60,    76,   104,
-      88,    32,   112,   113,   114,   121,    69,    40,    54,    50,
-      49,   125,    76,    56,   122,    51,   122,   137,   138,   139,
-      57,    40,    91,   111,    91,    70,    58,    97,    71,    61,
-      64,    66,   135,   147,   136,   148,    62,   121,    69,   123,
-      67,    68,    83,   140,   141,    85,    70,    86,    50,    71,
-      99,   100,   142,   101,   107,   144,   131,   102,   103,   109,
-     128,   142,     4,     5,     6,     7,     8,     9,    10,    11,
-      12,   126,    69,   146,    13,    14,    15,    16,    17,    18,
-      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
-      29,    30,    31,    32,    33,    34,    35,   145,    42,   130,
-       0,    92,   129,   105,     0,    36,   143,    37,    38,     0,
-       0,     0,    39,    40
+      70,  -108,    72,    53,    49,    92,     4,     5,     6,     7,
+       8,     9,    10,    11,    12,   118,    72,    91,    13,    14,
+       4,     5,     6,     7,     8,     9,    10,    11,    12,    66,
+      66,    26,    13,    14,    66,   105,   129,    32,   130,    93,
+       3,   131,   132,   133,   126,    26,    54,    67,    73,    98,
+      68,    32,   115,    88,    88,    56,    85,    40,   119,    50,
+      57,   116,    73,   116,   141,    51,   142,   134,   135,    67,
+      67,    40,    68,    68,    67,    66,   117,    68,   106,   107,
+     108,   115,    94,    58,    59,    60,    61,    62,    63,    64,
+      65,    82,    80,    88,    83,    88,   136,    50,    96,   138,
+      97,   101,   103,   122,   120,   136,     4,     5,     6,     7,
+       8,     9,    10,    11,    12,   125,    66,   140,    13,    14,
+      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
+      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
+      35,   139,    42,   124,   123,    89,    99,   137,     0,    36,
+       0,    37,    38,     0,     0,     0,    39,    40
 };
 
 static const yytype_int16 yycheck[] =
 {
-      32,     0,     1,     3,    91,     3,     5,     6,     7,     8,
-       9,    10,    11,    12,    13,     3,     1,    49,    17,    18,
-       5,     6,     7,     8,     9,    10,    11,    12,    13,    47,
-      48,    30,    17,    18,     3,     3,   123,    36,     3,     3,
-      51,    43,     0,    43,    46,    30,    46,    45,    47,    48,
-      52,    36,    52,    53,    54,    87,     3,    56,    46,    40,
-      52,    93,    47,     3,    90,    46,    92,    14,    15,    16,
-       4,    56,    90,    84,    92,    43,     4,    46,    46,    40,
-      45,    45,    49,   140,    51,   142,     3,   119,     3,     4,
-       3,     3,    46,    40,    41,    40,    43,    52,    40,    46,
-       3,     3,   134,     3,    42,   137,     4,    51,    51,    40,
-      40,   143,     5,     6,     7,     8,     9,    10,    11,    12,
-      13,    44,     3,    52,    17,    18,    19,    20,    21,    22,
-      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
-      33,    34,    35,    36,    37,    38,    39,     4,     2,   119,
-      -1,    48,   115,    78,    -1,    48,   135,    50,    51,    -1,
-      -1,    -1,    55,    56
+      32,     0,     1,     3,    52,    51,     5,     6,     7,     8,
+       9,    10,    11,    12,    13,    88,     1,    49,    17,    18,
+       5,     6,     7,     8,     9,    10,    11,    12,    13,     3,
+       3,    30,    17,    18,     3,    81,    49,    36,    51,     3,
+       0,    14,    15,    16,   117,    30,    46,    43,    47,    48,
+      46,    36,    84,    47,    48,     3,    52,    56,    90,    40,
+       4,    87,    47,    89,   134,    46,   136,    40,    41,    43,
+      43,    56,    46,    46,    43,     3,     4,    46,    52,    53,
+      54,   113,    46,     4,     3,    40,     3,     3,     3,     3,
+       3,    40,    46,    87,    52,    89,   128,    40,    51,   131,
+      51,    42,    40,    40,    44,   137,     5,     6,     7,     8,
+       9,    10,    11,    12,    13,     4,     3,    52,    17,    18,
+      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
+      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
+      39,     4,     2,   113,   109,    48,    75,   129,    -1,    48,
+      -1,    50,    51,    -1,    -1,    -1,    55,    56
 };
 
   /* STOS_[STATE-NUM] -- The (internal number of the) accessing
@@ -818,15 +815,15 @@ static const yytype_uint8 yystos[] =
       34,    35,    36,    37,    38,    39,    48,    50,    51,    55,
       56,    60,    63,    64,    66,    69,    70,    68,    67,    52,
       40,    46,    89,     3,    46,    87,     3,     4,     4,     3,
-      45,    40,     3,     3,    45,     3,    45,     3,     3,     3,
-      43,    46,    90,    92,    93,     1,    47,    63,    80,    81,
-      82,    91,    61,    46,    65,    40,    52,    71,    52,    78,
-      79,    90,    79,    74,    92,    89,     3,    46,    88,     3,
-       3,     3,    51,    51,    48,    81,    94,    42,    86,    40,
-      62,    89,    52,    53,    54,    75,    76,    77,    92,    72,
-      73,    92,    78,     4,    93,    92,    44,    83,    40,    76,
-      73,     4,    93,    84,    85,    49,    51,    14,    15,    16,
-      40,    41,    92,    85,    92,     4,    52,    86,    86
+      40,     3,     3,     3,     3,     3,     3,    43,    46,    90,
+      92,    93,     1,    47,    63,    80,    81,    82,    91,    61,
+      46,    65,    40,    52,    71,    52,    78,    79,    90,    79,
+      74,    92,    89,     3,    46,    88,    51,    51,    48,    81,
+      94,    42,    86,    40,    62,    89,    52,    53,    54,    75,
+      76,    77,    92,    72,    73,    92,    78,     4,    93,    92,
+      44,    83,    40,    76,    73,     4,    93,    84,    85,    49,
+      51,    14,    15,    16,    40,    41,    92,    85,    92,     4,
+      52,    86,    86
 };
 
   /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.    */
@@ -834,33 +831,31 @@ static const yytype_uint8 yyr1[] =
 {
        0,    57,    58,    59,    59,    60,    60,    60,    60,    60,
       60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
-      60,    60,    60,    60,    60,    61,    60,    60,    60,    60,
-      60,    60,    60,    62,    62,    63,    63,    63,    63,    63,
-      63,    63,    63,    64,    64,    65,    65,    63,    67,    66,
-      68,    66,    66,    69,    70,    70,    70,    70,    71,    71,
-      72,    72,    73,    73,    74,    74,    75,    75,    76,    76,
-      77,    77,    77,    78,    78,    78,    78,    78,    79,    79,
-      80,    80,    81,    81,    81,    83,    82,    84,    84,    84,
-      85,    85,    85,    85,    85,    85,    85,    86,    86,    87,
-      87,    88,    88,    88,    89,    90,    90,    91,    92,    92,
-      93,    94,    94
+      60,    60,    61,    60,    60,    60,    60,    60,    60,    60,
+      62,    62,    63,    63,    63,    63,    63,    63,    63,    63,
+      64,    64,    65,    65,    63,    67,    66,    68,    66,    66,
+      69,    70,    70,    70,    70,    71,    71,    72,    72,    73,
+      73,    74,    74,    75,    75,    76,    76,    77,    77,    77,
+      78,    78,    78,    78,    78,    79,    79,    80,    80,    81,
+      81,    81,    83,    82,    84,    84,    84,    85,    85,    85,
+      85,    85,    85,    85,    86,    86,    87,    87,    88,    88,
+      88,    89,    90,    90,    91,    92,    92,    93,    94,    94
 };
 
   /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.    */
 static const yytype_uint8 yyr2[] =
 {
        0,     2,     4,     0,     2,     1,     1,     1,     3,     1,
-       2,     1,     2,     2,     2,     3,     1,     2,     2,     2,
-       3,     1,     1,     2,     3,     0,     3,     2,     2,     1,
-       1,     1,     1,     2,     1,     1,     1,     2,     3,     1,
-       1,     2,     3,     1,     1,     0,     1,     3,     0,     3,
-       0,     3,     3,     3,     1,     1,     1,     1,     0,     1,
-       1,     2,     1,     2,     1,     2,     1,     2,     1,     1,
-       1,     1,     1,     1,     1,     2,     2,     3,     1,     2,
-       1,     2,     1,     2,     2,     0,     4,     1,     3,     2,
-       0,     3,     3,     2,     3,     3,     3,     0,     1,     1,
-       1,     0,     1,     1,     1,     1,     1,     1,     1,     1,
-       1,     0,     2
+       2,     1,     2,     2,     2,     1,     2,     2,     2,     1,
+       1,     2,     0,     3,     2,     2,     1,     1,     1,     1,
+       2,     1,     1,     1,     2,     3,     1,     1,     2,     3,
+       1,     1,     0,     1,     3,     0,     3,     0,     3,     3,
+       3,     1,     1,     1,     1,     0,     1,     1,     2,     1,
+       2,     1,     2,     1,     2,     1,     1,     1,     1,     1,
+       1,     1,     2,     2,     3,     1,     2,     1,     2,     1,
+       2,     2,     0,     4,     1,     3,     2,     0,     3,     3,
+       2,     3,     3,     3,     0,     1,     1,     1,     0,     1,
+       1,     1,     1,     1,     1,     1,     1,     1,     0,     2
 };
 
 
@@ -994,95 +989,95 @@ yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvalue
   switch (yytype)
     {
             case 3: // "string"
-/* Line 709 of yacc.c  */
+/* Line 731 of yacc.c  */
 #line 196 "src/parse-gram.y"
         { fputs (quotearg_style (c_quoting_style, ((*yyvaluep).chars)), yyo); }
-/* Line 709 of yacc.c  */
-#line 1002 "src/parse-gram.c"
+/* Line 731 of yacc.c  */
+#line 997 "src/parse-gram.c"
         break;
 
             case 4: // "integer"
-/* Line 709 of yacc.c  */
+/* Line 731 of yacc.c  */
 #line 209 "src/parse-gram.y"
         { fprintf (yyo, "%d", ((*yyvaluep).integer)); }
-/* Line 709 of yacc.c  */
-#line 1010 "src/parse-gram.c"
+/* Line 731 of yacc.c  */
+#line 1005 "src/parse-gram.c"
         break;
 
             case 24: // "%<flag>"
-/* Line 709 of yacc.c  */
+/* Line 731 of yacc.c  */
 #line 205 "src/parse-gram.y"
         { fprintf (yyo, "%%%s", ((*yyvaluep).uniqstr)); }
-/* Line 709 of yacc.c  */
-#line 1018 "src/parse-gram.c"
+/* Line 731 of yacc.c  */
+#line 1013 "src/parse-gram.c"
         break;
 
             case 40: // "{...}"
-/* Line 709 of yacc.c  */
+/* Line 731 of yacc.c  */
 #line 198 "src/parse-gram.y"
         { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).code)); }
-/* Line 709 of yacc.c  */
-#line 1026 "src/parse-gram.c"
+/* Line 731 of yacc.c  */
+#line 1021 "src/parse-gram.c"
         break;
 
             case 42: // "[identifier]"
-/* Line 709 of yacc.c  */
+/* Line 731 of yacc.c  */
 #line 203 "src/parse-gram.y"
         { fprintf (yyo, "[%s]", ((*yyvaluep).uniqstr)); }
-/* Line 709 of yacc.c  */
-#line 1034 "src/parse-gram.c"
+/* Line 731 of yacc.c  */
+#line 1029 "src/parse-gram.c"
         break;
 
             case 43: // "char"
-/* Line 709 of yacc.c  */
+/* Line 731 of yacc.c  */
 #line 190 "src/parse-gram.y"
         { fputs (char_name (((*yyvaluep).character)), yyo); }
-/* Line 709 of yacc.c  */
-#line 1042 "src/parse-gram.c"
+/* Line 731 of yacc.c  */
+#line 1037 "src/parse-gram.c"
         break;
 
             case 44: // "epilogue"
-/* Line 709 of yacc.c  */
+/* Line 731 of yacc.c  */
 #line 198 "src/parse-gram.y"
         { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).chars)); }
-/* Line 709 of yacc.c  */
-#line 1050 "src/parse-gram.c"
+/* Line 731 of yacc.c  */
+#line 1045 "src/parse-gram.c"
         break;
 
             case 46: // "identifier"
-/* Line 709 of yacc.c  */
+/* Line 731 of yacc.c  */
 #line 202 "src/parse-gram.y"
         { fputs (((*yyvaluep).uniqstr), yyo); }
-/* Line 709 of yacc.c  */
-#line 1058 "src/parse-gram.c"
+/* Line 731 of yacc.c  */
+#line 1053 "src/parse-gram.c"
         break;
 
             case 47: // "identifier:"
-/* Line 709 of yacc.c  */
+/* Line 731 of yacc.c  */
 #line 204 "src/parse-gram.y"
         { fprintf (yyo, "%s:", ((*yyvaluep).uniqstr)); }
-/* Line 709 of yacc.c  */
-#line 1066 "src/parse-gram.c"
+/* Line 731 of yacc.c  */
+#line 1061 "src/parse-gram.c"
         break;
 
             case 50: // "%{...%}"
-/* Line 709 of yacc.c  */
+/* Line 731 of yacc.c  */
 #line 198 "src/parse-gram.y"
         { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).chars)); }
-/* Line 709 of yacc.c  */
-#line 1074 "src/parse-gram.c"
+/* Line 731 of yacc.c  */
+#line 1069 "src/parse-gram.c"
         break;
 
             case 52: // "<tag>"
-/* Line 709 of yacc.c  */
+/* Line 731 of yacc.c  */
 #line 206 "src/parse-gram.y"
         { fprintf (yyo, "<%s>", ((*yyvaluep).uniqstr)); }
-/* Line 709 of yacc.c  */
-#line 1082 "src/parse-gram.c"
+/* Line 731 of yacc.c  */
+#line 1077 "src/parse-gram.c"
         break;
 
             case 55: // "%param"
-/* Line 709 of yacc.c  */
+/* Line 731 of yacc.c  */
 #line 252 "src/parse-gram.y"
         {
   switch (((*yyvaluep).param))
@@ -1096,88 +1091,88 @@ yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvalue
       case param_none: aver (false); break;
     }
 }
-/* Line 709 of yacc.c  */
-#line 1101 "src/parse-gram.c"
+/* Line 731 of yacc.c  */
+#line 1096 "src/parse-gram.c"
         break;
 
             case 64: // code_props_type
-/* Line 709 of yacc.c  */
-#line 427 "src/parse-gram.y"
+/* Line 731 of yacc.c  */
+#line 424 "src/parse-gram.y"
         { fprintf (yyo, "%s", code_props_type_string (((*yyvaluep).code_type))); }
-/* Line 709 of yacc.c  */
-#line 1109 "src/parse-gram.c"
+/* Line 731 of yacc.c  */
+#line 1104 "src/parse-gram.c"
         break;
 
             case 73: // symbol.prec
-/* Line 709 of yacc.c  */
+/* Line 731 of yacc.c  */
 #line 212 "src/parse-gram.y"
         { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
-/* Line 709 of yacc.c  */
-#line 1117 "src/parse-gram.c"
+/* Line 731 of yacc.c  */
+#line 1112 "src/parse-gram.c"
         break;
 
             case 77: // tag
-/* Line 709 of yacc.c  */
+/* Line 731 of yacc.c  */
 #line 206 "src/parse-gram.y"
         { fprintf (yyo, "<%s>", ((*yyvaluep).uniqstr)); }
-/* Line 709 of yacc.c  */
-#line 1125 "src/parse-gram.c"
+/* Line 731 of yacc.c  */
+#line 1120 "src/parse-gram.c"
         break;
 
             case 87: // variable
-/* Line 709 of yacc.c  */
+/* Line 731 of yacc.c  */
 #line 202 "src/parse-gram.y"
         { fputs (((*yyvaluep).uniqstr), yyo); }
-/* Line 709 of yacc.c  */
-#line 1133 "src/parse-gram.c"
+/* Line 731 of yacc.c  */
+#line 1128 "src/parse-gram.c"
         break;
 
             case 88: // content.opt
-/* Line 709 of yacc.c  */
+/* Line 731 of yacc.c  */
 #line 198 "src/parse-gram.y"
         { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).chars)); }
-/* Line 709 of yacc.c  */
-#line 1141 "src/parse-gram.c"
+/* Line 731 of yacc.c  */
+#line 1136 "src/parse-gram.c"
         break;
 
             case 89: // braceless
-/* Line 709 of yacc.c  */
+/* Line 731 of yacc.c  */
 #line 198 "src/parse-gram.y"
         { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).chars)); }
-/* Line 709 of yacc.c  */
-#line 1149 "src/parse-gram.c"
+/* Line 731 of yacc.c  */
+#line 1144 "src/parse-gram.c"
         break;
 
             case 90: // id
-/* Line 709 of yacc.c  */
+/* Line 731 of yacc.c  */
 #line 212 "src/parse-gram.y"
         { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
-/* Line 709 of yacc.c  */
-#line 1157 "src/parse-gram.c"
+/* Line 731 of yacc.c  */
+#line 1152 "src/parse-gram.c"
         break;
 
             case 91: // id_colon
-/* Line 709 of yacc.c  */
+/* Line 731 of yacc.c  */
 #line 213 "src/parse-gram.y"
         { fprintf (yyo, "%s:", ((*yyvaluep).symbol)->tag); }
-/* Line 709 of yacc.c  */
-#line 1165 "src/parse-gram.c"
+/* Line 731 of yacc.c  */
+#line 1160 "src/parse-gram.c"
         break;
 
             case 92: // symbol
-/* Line 709 of yacc.c  */
+/* Line 731 of yacc.c  */
 #line 212 "src/parse-gram.y"
         { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
-/* Line 709 of yacc.c  */
-#line 1173 "src/parse-gram.c"
+/* Line 731 of yacc.c  */
+#line 1168 "src/parse-gram.c"
         break;
 
             case 93: // string_as_id
-/* Line 709 of yacc.c  */
+/* Line 731 of yacc.c  */
 #line 212 "src/parse-gram.y"
         { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
-/* Line 709 of yacc.c  */
-#line 1181 "src/parse-gram.c"
+/* Line 731 of yacc.c  */
+#line 1176 "src/parse-gram.c"
         break;
 
       default:
@@ -1776,6 +1771,28 @@ yyparse (void)
 /* The lookahead symbol.  */
 int yychar;
 
+
+#if defined __GNUC__ && (4 < __GNUC__ + (6 <= __GNUC_MINOR__))
+/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
+# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
+    _Pragma ("GCC diagnostic push") \
+    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
+# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
+    _Pragma ("GCC diagnostic pop")
+#else
+/* Default value used for initialization, for pacifying older GCCs
+   or non-GCC compilers.  */
+static YYSTYPE yyval_default;
+# define YYLVAL_INITIALIZE() (yylval = yyval_default)
+#endif
+#ifndef YYLVAL_INITIALIZE
+# define YYLVAL_INITIALIZE()
+#endif
+#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
+# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
+# define YY_IGNORE_MAYBE_UNINITIALIZED_END
+#endif
+
 /* The semantic value of the lookahead symbol.  */
 YYSTYPE yylval;
 
@@ -1869,6 +1886,7 @@ YYLTYPE yylloc;
   yyvsp = yyvs;
   yylsp = yyls;
 
+  YYLVAL_INITIALIZE ();
 #if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
   /* Initialize the default location before parsing starts.  */
   yylloc.first_line   = yylloc.last_line   = 1;
@@ -1876,7 +1894,7 @@ YYLTYPE yylloc;
 #endif
 
 /* User initialization code.  */
-/* Line 1464 of yacc.c  */
+/* Line 1487 of yacc.c  */
 #line 101 "src/parse-gram.y"
 {
   /* Bison's grammar can initial empty locations, hence a default
@@ -1884,8 +1902,8 @@ YYLTYPE yylloc;
   boundary_set (&yylloc.start, current_file, 1, 1);
   boundary_set (&yylloc.end, current_file, 1, 1);
 }
-/* Line 1464 of yacc.c  */
-#line 1889 "src/parse-gram.c"
+/* Line 1487 of yacc.c  */
+#line 1907 "src/parse-gram.c"
   yylsp[0] = yylloc;
   goto yysetstate;
 
@@ -2037,7 +2055,9 @@ yybackup:
   YY_LAC_DISCARD ("shift");
 
   yystate = yyn;
+  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
   *++yyvsp = yylval;
+  YY_IGNORE_MAYBE_UNINITIALIZED_END
   *++yylsp = yylloc;
   goto yynewstate;
 
@@ -2077,7 +2097,7 @@ yyreduce:
     switch (yyn)
       {
           case 6:
-/* Line 1679 of yacc.c  */
+/* Line 1704 of yacc.c  */
 #line 288 "src/parse-gram.y"
     {
       code_props plain_code;
@@ -2088,107 +2108,99 @@ yyreduce:
                         plain_code.code, (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1679 of yacc.c  */
-#line 2093 "src/parse-gram.c"
+/* Line 1704 of yacc.c  */
+#line 2113 "src/parse-gram.c"
     break;
 
   case 7:
-/* Line 1679 of yacc.c  */
+/* Line 1704 of yacc.c  */
 #line 298 "src/parse-gram.y"
     {
       muscle_percent_define_ensure ((yyvsp[0].uniqstr), (yylsp[0]), true);
     }
-/* Line 1679 of yacc.c  */
-#line 2103 "src/parse-gram.c"
+/* Line 1704 of yacc.c  */
+#line 2123 "src/parse-gram.c"
     break;
 
   case 8:
-/* Line 1679 of yacc.c  */
+/* Line 1704 of yacc.c  */
 #line 302 "src/parse-gram.y"
     {
       muscle_percent_define_insert ((yyvsp[-1].uniqstr), (yylsp[-1]), (yyvsp[0].chars),
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
     }
-/* Line 1679 of yacc.c  */
-#line 2114 "src/parse-gram.c"
+/* Line 1704 of yacc.c  */
+#line 2134 "src/parse-gram.c"
     break;
 
   case 9:
-/* Line 1679 of yacc.c  */
+/* Line 1704 of yacc.c  */
 #line 306 "src/parse-gram.y"
     { defines_flag = true; }
-/* Line 1679 of yacc.c  */
-#line 2122 "src/parse-gram.c"
+/* Line 1704 of yacc.c  */
+#line 2142 "src/parse-gram.c"
     break;
 
   case 10:
-/* Line 1679 of yacc.c  */
+/* Line 1704 of yacc.c  */
 #line 308 "src/parse-gram.y"
     {
       defines_flag = true;
       spec_defines_file = xstrdup ((yyvsp[0].chars));
     }
-/* Line 1679 of yacc.c  */
-#line 2133 "src/parse-gram.c"
+/* Line 1704 of yacc.c  */
+#line 2153 "src/parse-gram.c"
     break;
 
   case 11:
-/* Line 1679 of yacc.c  */
+/* Line 1704 of yacc.c  */
 #line 313 "src/parse-gram.y"
     {
       muscle_percent_define_insert ("parse.error", (yylsp[0]), "verbose",
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
     }
-/* Line 1679 of yacc.c  */
-#line 2144 "src/parse-gram.c"
+/* Line 1704 of yacc.c  */
+#line 2164 "src/parse-gram.c"
     break;
 
   case 12:
-/* Line 1679 of yacc.c  */
+/* Line 1704 of yacc.c  */
 #line 317 "src/parse-gram.y"
     { expected_sr_conflicts = (yyvsp[0].integer); }
-/* Line 1679 of yacc.c  */
-#line 2152 "src/parse-gram.c"
+/* Line 1704 of yacc.c  */
+#line 2172 "src/parse-gram.c"
     break;
 
   case 13:
-/* Line 1679 of yacc.c  */
+/* Line 1704 of yacc.c  */
 #line 318 "src/parse-gram.y"
     { expected_rr_conflicts = (yyvsp[0].integer); }
-/* Line 1679 of yacc.c  */
-#line 2160 "src/parse-gram.c"
+/* Line 1704 of yacc.c  */
+#line 2180 "src/parse-gram.c"
     break;
 
   case 14:
-/* Line 1679 of yacc.c  */
+/* Line 1704 of yacc.c  */
 #line 319 "src/parse-gram.y"
     { spec_file_prefix = (yyvsp[0].chars); }
-/* Line 1679 of yacc.c  */
-#line 2168 "src/parse-gram.c"
+/* Line 1704 of yacc.c  */
+#line 2188 "src/parse-gram.c"
     break;
 
   case 15:
-/* Line 1679 of yacc.c  */
-#line 320 "src/parse-gram.y"
-    { spec_file_prefix = (yyvsp[0].chars); }
-/* Line 1679 of yacc.c  */
-#line 2176 "src/parse-gram.c"
-    break;
-
-  case 16:
-/* Line 1679 of yacc.c  */
-#line 322 "src/parse-gram.y"
+/* Line 1704 of yacc.c  */
+#line 321 "src/parse-gram.y"
     {
       nondeterministic_parser = true;
       glr_parser = true;
     }
-/* Line 1679 of yacc.c  */
-#line 2187 "src/parse-gram.c"
+/* Line 1704 of yacc.c  */
+#line 2199 "src/parse-gram.c"
     break;
 
-  case 17:
-/* Line 1679 of yacc.c  */
-#line 327 "src/parse-gram.y"
+  case 16:
+/* Line 1704 of yacc.c  */
+#line 326 "src/parse-gram.y"
     {
       code_props action;
       code_props_symbol_action_init (&action, (yyvsp[0].code), (yylsp[0]));
@@ -2197,93 +2209,77 @@ yyreduce:
       muscle_code_grow ("initial_action", action.code, (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1679 of yacc.c  */
-#line 2202 "src/parse-gram.c"
+/* Line 1704 of yacc.c  */
+#line 2214 "src/parse-gram.c"
+    break;
+
+  case 17:
+/* Line 1704 of yacc.c  */
+#line 334 "src/parse-gram.y"
+    { language_argmatch ((yyvsp[0].chars), grammar_prio, (yylsp[-1])); }
+/* Line 1704 of yacc.c  */
+#line 2222 "src/parse-gram.c"
     break;
 
   case 18:
-/* Line 1679 of yacc.c  */
+/* Line 1704 of yacc.c  */
 #line 335 "src/parse-gram.y"
-    { language_argmatch ((yyvsp[0].chars), grammar_prio, (yylsp[-1])); }
-/* Line 1679 of yacc.c  */
-#line 2210 "src/parse-gram.c"
+    { spec_name_prefix = (yyvsp[0].chars); }
+/* Line 1704 of yacc.c  */
+#line 2230 "src/parse-gram.c"
     break;
 
   case 19:
-/* Line 1679 of yacc.c  */
+/* Line 1704 of yacc.c  */
 #line 336 "src/parse-gram.y"
-    { spec_name_prefix = (yyvsp[0].chars); }
-/* Line 1679 of yacc.c  */
-#line 2218 "src/parse-gram.c"
+    { no_lines_flag = true; }
+/* Line 1704 of yacc.c  */
+#line 2238 "src/parse-gram.c"
     break;
 
   case 20:
-/* Line 1679 of yacc.c  */
+/* Line 1704 of yacc.c  */
 #line 337 "src/parse-gram.y"
-    { spec_name_prefix = (yyvsp[0].chars); }
-/* Line 1679 of yacc.c  */
-#line 2226 "src/parse-gram.c"
+    { nondeterministic_parser = true; }
+/* Line 1704 of yacc.c  */
+#line 2246 "src/parse-gram.c"
     break;
 
   case 21:
-/* Line 1679 of yacc.c  */
+/* Line 1704 of yacc.c  */
 #line 338 "src/parse-gram.y"
-    { no_lines_flag = true; }
-/* Line 1679 of yacc.c  */
-#line 2234 "src/parse-gram.c"
+    { spec_outfile = (yyvsp[0].chars); }
+/* Line 1704 of yacc.c  */
+#line 2254 "src/parse-gram.c"
     break;
 
   case 22:
-/* Line 1679 of yacc.c  */
+/* Line 1704 of yacc.c  */
 #line 339 "src/parse-gram.y"
-    { nondeterministic_parser = true; }
-/* Line 1679 of yacc.c  */
-#line 2242 "src/parse-gram.c"
+    { current_param = (yyvsp[0].param); }
+/* Line 1704 of yacc.c  */
+#line 2262 "src/parse-gram.c"
     break;
 
   case 23:
-/* Line 1679 of yacc.c  */
-#line 340 "src/parse-gram.y"
-    { spec_outfile = (yyvsp[0].chars); }
-/* Line 1679 of yacc.c  */
-#line 2250 "src/parse-gram.c"
+/* Line 1704 of yacc.c  */
+#line 339 "src/parse-gram.y"
+    { current_param = param_none; }
+/* Line 1704 of yacc.c  */
+#line 2270 "src/parse-gram.c"
     break;
 
   case 24:
-/* Line 1679 of yacc.c  */
-#line 341 "src/parse-gram.y"
-    { spec_outfile = (yyvsp[0].chars); }
-/* Line 1679 of yacc.c  */
-#line 2258 "src/parse-gram.c"
+/* Line 1704 of yacc.c  */
+#line 340 "src/parse-gram.y"
+    { version_check (&(yylsp[0]), (yyvsp[0].chars)); }
+/* Line 1704 of yacc.c  */
+#line 2278 "src/parse-gram.c"
     break;
 
   case 25:
-/* Line 1679 of yacc.c  */
-#line 342 "src/parse-gram.y"
-    { current_param = (yyvsp[0].param); }
-/* Line 1679 of yacc.c  */
-#line 2266 "src/parse-gram.c"
-    break;
-
-  case 26:
-/* Line 1679 of yacc.c  */
+/* Line 1704 of yacc.c  */
 #line 342 "src/parse-gram.y"
-    { current_param = param_none; }
-/* Line 1679 of yacc.c  */
-#line 2274 "src/parse-gram.c"
-    break;
-
-  case 27:
-/* Line 1679 of yacc.c  */
-#line 343 "src/parse-gram.y"
-    { version_check (&(yylsp[0]), (yyvsp[0].chars)); }
-/* Line 1679 of yacc.c  */
-#line 2282 "src/parse-gram.c"
-    break;
-
-  case 28:
-/* Line 1679 of yacc.c  */
-#line 345 "src/parse-gram.y"
     {
       char const *skeleton_user = (yyvsp[0].chars);
       if (strchr (skeleton_user, '/'))
@@ -2307,63 +2303,63 @@ yyreduce:
         }
       skeleton_arg (skeleton_user, grammar_prio, (yylsp[-1]));
     }
-/* Line 1679 of yacc.c  */
-#line 2312 "src/parse-gram.c"
+/* Line 1704 of yacc.c  */
+#line 2308 "src/parse-gram.c"
     break;
 
-  case 29:
-/* Line 1679 of yacc.c  */
-#line 368 "src/parse-gram.y"
+  case 26:
+/* Line 1704 of yacc.c  */
+#line 365 "src/parse-gram.y"
     { token_table_flag = true; }
-/* Line 1679 of yacc.c  */
-#line 2320 "src/parse-gram.c"
+/* Line 1704 of yacc.c  */
+#line 2316 "src/parse-gram.c"
     break;
 
-  case 30:
-/* Line 1679 of yacc.c  */
-#line 369 "src/parse-gram.y"
+  case 27:
+/* Line 1704 of yacc.c  */
+#line 366 "src/parse-gram.y"
     { report_flag |= report_states; }
-/* Line 1679 of yacc.c  */
-#line 2328 "src/parse-gram.c"
+/* Line 1704 of yacc.c  */
+#line 2324 "src/parse-gram.c"
     break;
 
-  case 31:
-/* Line 1679 of yacc.c  */
-#line 370 "src/parse-gram.y"
+  case 28:
+/* Line 1704 of yacc.c  */
+#line 367 "src/parse-gram.y"
     { yacc_flag = true; }
-/* Line 1679 of yacc.c  */
-#line 2336 "src/parse-gram.c"
+/* Line 1704 of yacc.c  */
+#line 2332 "src/parse-gram.c"
     break;
 
-  case 33:
-/* Line 1679 of yacc.c  */
-#line 375 "src/parse-gram.y"
+  case 30:
+/* Line 1704 of yacc.c  */
+#line 372 "src/parse-gram.y"
     { add_param (current_param, (yyvsp[0].code), (yylsp[0])); }
-/* Line 1679 of yacc.c  */
-#line 2344 "src/parse-gram.c"
+/* Line 1704 of yacc.c  */
+#line 2340 "src/parse-gram.c"
     break;
 
-  case 34:
-/* Line 1679 of yacc.c  */
-#line 376 "src/parse-gram.y"
+  case 31:
+/* Line 1704 of yacc.c  */
+#line 373 "src/parse-gram.y"
     { add_param (current_param, (yyvsp[0].code), (yylsp[0])); }
-/* Line 1679 of yacc.c  */
-#line 2352 "src/parse-gram.c"
+/* Line 1704 of yacc.c  */
+#line 2348 "src/parse-gram.c"
     break;
 
-  case 37:
-/* Line 1679 of yacc.c  */
-#line 388 "src/parse-gram.y"
+  case 34:
+/* Line 1704 of yacc.c  */
+#line 385 "src/parse-gram.y"
     {
       grammar_start_symbol_set ((yyvsp[0].symbol), (yylsp[0]));
     }
-/* Line 1679 of yacc.c  */
-#line 2362 "src/parse-gram.c"
+/* Line 1704 of yacc.c  */
+#line 2358 "src/parse-gram.c"
     break;
 
-  case 38:
-/* Line 1679 of yacc.c  */
-#line 392 "src/parse-gram.y"
+  case 35:
+/* Line 1704 of yacc.c  */
+#line 389 "src/parse-gram.y"
     {
       code_props code;
       code_props_symbol_action_init (&code, (yyvsp[-1].code), (yylsp[-1]));
@@ -2375,139 +2371,139 @@ yyreduce:
         symbol_list_free ((yyvsp[0].list));
       }
     }
-/* Line 1679 of yacc.c  */
-#line 2380 "src/parse-gram.c"
+/* Line 1704 of yacc.c  */
+#line 2376 "src/parse-gram.c"
     break;
 
-  case 39:
-/* Line 1679 of yacc.c  */
-#line 404 "src/parse-gram.y"
+  case 36:
+/* Line 1704 of yacc.c  */
+#line 401 "src/parse-gram.y"
     {
       default_prec = true;
     }
-/* Line 1679 of yacc.c  */
-#line 2390 "src/parse-gram.c"
+/* Line 1704 of yacc.c  */
+#line 2386 "src/parse-gram.c"
     break;
 
-  case 40:
-/* Line 1679 of yacc.c  */
-#line 408 "src/parse-gram.y"
+  case 37:
+/* Line 1704 of yacc.c  */
+#line 405 "src/parse-gram.y"
     {
       default_prec = false;
     }
-/* Line 1679 of yacc.c  */
-#line 2400 "src/parse-gram.c"
+/* Line 1704 of yacc.c  */
+#line 2396 "src/parse-gram.c"
     break;
 
-  case 41:
-/* Line 1679 of yacc.c  */
-#line 412 "src/parse-gram.y"
+  case 38:
+/* Line 1704 of yacc.c  */
+#line 409 "src/parse-gram.y"
     {
       /* Do not invoke muscle_percent_code_grow here since it invokes
          muscle_user_name_list_grow.  */
       muscle_code_grow ("percent_code()", (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1679 of yacc.c  */
-#line 2413 "src/parse-gram.c"
+/* Line 1704 of yacc.c  */
+#line 2409 "src/parse-gram.c"
     break;
 
-  case 42:
-/* Line 1679 of yacc.c  */
-#line 419 "src/parse-gram.y"
+  case 39:
+/* Line 1704 of yacc.c  */
+#line 416 "src/parse-gram.y"
     {
       muscle_percent_code_grow ((yyvsp[-1].uniqstr), (yylsp[-1]), (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1679 of yacc.c  */
-#line 2424 "src/parse-gram.c"
+/* Line 1704 of yacc.c  */
+#line 2420 "src/parse-gram.c"
     break;
 
-  case 43:
-/* Line 1679 of yacc.c  */
-#line 429 "src/parse-gram.y"
+  case 40:
+/* Line 1704 of yacc.c  */
+#line 426 "src/parse-gram.y"
     { (yyval.code_type) = destructor; }
-/* Line 1679 of yacc.c  */
-#line 2432 "src/parse-gram.c"
+/* Line 1704 of yacc.c  */
+#line 2428 "src/parse-gram.c"
     break;
 
-  case 44:
-/* Line 1679 of yacc.c  */
-#line 430 "src/parse-gram.y"
+  case 41:
+/* Line 1704 of yacc.c  */
+#line 427 "src/parse-gram.y"
     { (yyval.code_type) = printer; }
-/* Line 1679 of yacc.c  */
-#line 2440 "src/parse-gram.c"
+/* Line 1704 of yacc.c  */
+#line 2436 "src/parse-gram.c"
     break;
 
-  case 45:
-/* Line 1679 of yacc.c  */
-#line 440 "src/parse-gram.y"
+  case 42:
+/* Line 1704 of yacc.c  */
+#line 437 "src/parse-gram.y"
     {}
-/* Line 1679 of yacc.c  */
-#line 2448 "src/parse-gram.c"
+/* Line 1704 of yacc.c  */
+#line 2444 "src/parse-gram.c"
     break;
 
-  case 46:
-/* Line 1679 of yacc.c  */
-#line 441 "src/parse-gram.y"
+  case 43:
+/* Line 1704 of yacc.c  */
+#line 438 "src/parse-gram.y"
     { muscle_code_grow ("union_name", (yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1679 of yacc.c  */
-#line 2456 "src/parse-gram.c"
+/* Line 1704 of yacc.c  */
+#line 2452 "src/parse-gram.c"
     break;
 
-  case 47:
-/* Line 1679 of yacc.c  */
-#line 446 "src/parse-gram.y"
+  case 44:
+/* Line 1704 of yacc.c  */
+#line 443 "src/parse-gram.y"
     {
       union_seen = true;
       muscle_code_grow ("stype", (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1679 of yacc.c  */
-#line 2468 "src/parse-gram.c"
+/* Line 1704 of yacc.c  */
+#line 2464 "src/parse-gram.c"
     break;
 
-  case 48:
-/* Line 1679 of yacc.c  */
-#line 457 "src/parse-gram.y"
+  case 45:
+/* Line 1704 of yacc.c  */
+#line 454 "src/parse-gram.y"
     { current_class = nterm_sym; }
-/* Line 1679 of yacc.c  */
-#line 2476 "src/parse-gram.c"
+/* Line 1704 of yacc.c  */
+#line 2472 "src/parse-gram.c"
     break;
 
-  case 49:
-/* Line 1679 of yacc.c  */
-#line 458 "src/parse-gram.y"
+  case 46:
+/* Line 1704 of yacc.c  */
+#line 455 "src/parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
-/* Line 1679 of yacc.c  */
-#line 2487 "src/parse-gram.c"
+/* Line 1704 of yacc.c  */
+#line 2483 "src/parse-gram.c"
     break;
 
-  case 50:
-/* Line 1679 of yacc.c  */
-#line 462 "src/parse-gram.y"
+  case 47:
+/* Line 1704 of yacc.c  */
+#line 459 "src/parse-gram.y"
     { current_class = token_sym; }
-/* Line 1679 of yacc.c  */
-#line 2495 "src/parse-gram.c"
+/* Line 1704 of yacc.c  */
+#line 2491 "src/parse-gram.c"
     break;
 
-  case 51:
-/* Line 1679 of yacc.c  */
-#line 463 "src/parse-gram.y"
+  case 48:
+/* Line 1704 of yacc.c  */
+#line 460 "src/parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
-/* Line 1679 of yacc.c  */
-#line 2506 "src/parse-gram.c"
+/* Line 1704 of yacc.c  */
+#line 2502 "src/parse-gram.c"
     break;
 
-  case 52:
-/* Line 1679 of yacc.c  */
-#line 468 "src/parse-gram.y"
+  case 49:
+/* Line 1704 of yacc.c  */
+#line 465 "src/parse-gram.y"
     {
       symbol_list *list;
       tag_seen = true;
@@ -2515,13 +2511,13 @@ yyreduce:
         symbol_type_set (list->content.sym, (yyvsp[-1].uniqstr), (yylsp[-1]));
       symbol_list_free ((yyvsp[0].list));
     }
-/* Line 1679 of yacc.c  */
-#line 2520 "src/parse-gram.c"
+/* Line 1704 of yacc.c  */
+#line 2516 "src/parse-gram.c"
     break;
 
-  case 53:
-/* Line 1679 of yacc.c  */
-#line 479 "src/parse-gram.y"
+  case 50:
+/* Line 1704 of yacc.c  */
+#line 476 "src/parse-gram.y"
     {
       symbol_list *list;
       ++current_prec;
@@ -2533,358 +2529,358 @@ yyreduce:
       symbol_list_free ((yyvsp[0].list));
       current_type = NULL;
     }
-/* Line 1679 of yacc.c  */
-#line 2538 "src/parse-gram.c"
+/* Line 1704 of yacc.c  */
+#line 2534 "src/parse-gram.c"
     break;
 
-  case 54:
-/* Line 1679 of yacc.c  */
-#line 493 "src/parse-gram.y"
+  case 51:
+/* Line 1704 of yacc.c  */
+#line 490 "src/parse-gram.y"
     { (yyval.assoc) = left_assoc; }
-/* Line 1679 of yacc.c  */
-#line 2546 "src/parse-gram.c"
+/* Line 1704 of yacc.c  */
+#line 2542 "src/parse-gram.c"
     break;
 
-  case 55:
-/* Line 1679 of yacc.c  */
-#line 494 "src/parse-gram.y"
+  case 52:
+/* Line 1704 of yacc.c  */
+#line 491 "src/parse-gram.y"
     { (yyval.assoc) = right_assoc; }
-/* Line 1679 of yacc.c  */
-#line 2554 "src/parse-gram.c"
+/* Line 1704 of yacc.c  */
+#line 2550 "src/parse-gram.c"
     break;
 
-  case 56:
-/* Line 1679 of yacc.c  */
-#line 495 "src/parse-gram.y"
+  case 53:
+/* Line 1704 of yacc.c  */
+#line 492 "src/parse-gram.y"
     { (yyval.assoc) = non_assoc; }
-/* Line 1679 of yacc.c  */
-#line 2562 "src/parse-gram.c"
+/* Line 1704 of yacc.c  */
+#line 2558 "src/parse-gram.c"
     break;
 
-  case 57:
-/* Line 1679 of yacc.c  */
-#line 496 "src/parse-gram.y"
+  case 54:
+/* Line 1704 of yacc.c  */
+#line 493 "src/parse-gram.y"
     { (yyval.assoc) = precedence_assoc; }
-/* Line 1679 of yacc.c  */
-#line 2570 "src/parse-gram.c"
+/* Line 1704 of yacc.c  */
+#line 2566 "src/parse-gram.c"
     break;
 
-  case 58:
-/* Line 1679 of yacc.c  */
-#line 500 "src/parse-gram.y"
+  case 55:
+/* Line 1704 of yacc.c  */
+#line 497 "src/parse-gram.y"
     { current_type = NULL; }
-/* Line 1679 of yacc.c  */
-#line 2578 "src/parse-gram.c"
+/* Line 1704 of yacc.c  */
+#line 2574 "src/parse-gram.c"
     break;
 
-  case 59:
-/* Line 1679 of yacc.c  */
-#line 501 "src/parse-gram.y"
+  case 56:
+/* Line 1704 of yacc.c  */
+#line 498 "src/parse-gram.y"
     { current_type = (yyvsp[0].uniqstr); tag_seen = true; }
-/* Line 1679 of yacc.c  */
-#line 2586 "src/parse-gram.c"
+/* Line 1704 of yacc.c  */
+#line 2582 "src/parse-gram.c"
     break;
 
-  case 60:
-/* Line 1679 of yacc.c  */
-#line 507 "src/parse-gram.y"
+  case 57:
+/* Line 1704 of yacc.c  */
+#line 504 "src/parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-/* Line 1679 of yacc.c  */
-#line 2594 "src/parse-gram.c"
+/* Line 1704 of yacc.c  */
+#line 2590 "src/parse-gram.c"
     break;
 
-  case 61:
-/* Line 1679 of yacc.c  */
-#line 509 "src/parse-gram.y"
+  case 58:
+/* Line 1704 of yacc.c  */
+#line 506 "src/parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
-/* Line 1679 of yacc.c  */
-#line 2602 "src/parse-gram.c"
+/* Line 1704 of yacc.c  */
+#line 2598 "src/parse-gram.c"
     break;
 
-  case 62:
-/* Line 1679 of yacc.c  */
-#line 513 "src/parse-gram.y"
+  case 59:
+/* Line 1704 of yacc.c  */
+#line 510 "src/parse-gram.y"
     { (yyval.symbol) = (yyvsp[0].symbol); }
-/* Line 1679 of yacc.c  */
-#line 2610 "src/parse-gram.c"
+/* Line 1704 of yacc.c  */
+#line 2606 "src/parse-gram.c"
     break;
 
-  case 63:
-/* Line 1679 of yacc.c  */
-#line 514 "src/parse-gram.y"
+  case 60:
+/* Line 1704 of yacc.c  */
+#line 511 "src/parse-gram.y"
     { (yyval.symbol) = (yyvsp[-1].symbol); symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0])); }
-/* Line 1679 of yacc.c  */
-#line 2618 "src/parse-gram.c"
+/* Line 1704 of yacc.c  */
+#line 2614 "src/parse-gram.c"
     break;
 
-  case 64:
-/* Line 1679 of yacc.c  */
-#line 520 "src/parse-gram.y"
+  case 61:
+/* Line 1704 of yacc.c  */
+#line 517 "src/parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-/* Line 1679 of yacc.c  */
-#line 2626 "src/parse-gram.c"
+/* Line 1704 of yacc.c  */
+#line 2622 "src/parse-gram.c"
     break;
 
-  case 65:
-/* Line 1679 of yacc.c  */
-#line 522 "src/parse-gram.y"
+  case 62:
+/* Line 1704 of yacc.c  */
+#line 519 "src/parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
-/* Line 1679 of yacc.c  */
-#line 2634 "src/parse-gram.c"
+/* Line 1704 of yacc.c  */
+#line 2630 "src/parse-gram.c"
     break;
 
-  case 66:
-/* Line 1679 of yacc.c  */
-#line 526 "src/parse-gram.y"
+  case 63:
+/* Line 1704 of yacc.c  */
+#line 523 "src/parse-gram.y"
     { (yyval.list) = (yyvsp[0].list); }
-/* Line 1679 of yacc.c  */
-#line 2642 "src/parse-gram.c"
+/* Line 1704 of yacc.c  */
+#line 2638 "src/parse-gram.c"
     break;
 
-  case 67:
-/* Line 1679 of yacc.c  */
-#line 527 "src/parse-gram.y"
+  case 64:
+/* Line 1704 of yacc.c  */
+#line 524 "src/parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), (yyvsp[0].list)); }
-/* Line 1679 of yacc.c  */
-#line 2650 "src/parse-gram.c"
+/* Line 1704 of yacc.c  */
+#line 2646 "src/parse-gram.c"
     break;
 
-  case 68:
-/* Line 1679 of yacc.c  */
-#line 531 "src/parse-gram.y"
+  case 65:
+/* Line 1704 of yacc.c  */
+#line 528 "src/parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-/* Line 1679 of yacc.c  */
-#line 2658 "src/parse-gram.c"
+/* Line 1704 of yacc.c  */
+#line 2654 "src/parse-gram.c"
     break;
 
-  case 69:
-/* Line 1679 of yacc.c  */
-#line 532 "src/parse-gram.y"
+  case 66:
+/* Line 1704 of yacc.c  */
+#line 529 "src/parse-gram.y"
     { (yyval.list) = symbol_list_type_new ((yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1679 of yacc.c  */
-#line 2666 "src/parse-gram.c"
+/* Line 1704 of yacc.c  */
+#line 2662 "src/parse-gram.c"
     break;
 
-  case 71:
-/* Line 1679 of yacc.c  */
-#line 537 "src/parse-gram.y"
+  case 68:
+/* Line 1704 of yacc.c  */
+#line 534 "src/parse-gram.y"
     { (yyval.uniqstr) = uniqstr_new ("*"); }
-/* Line 1679 of yacc.c  */
-#line 2674 "src/parse-gram.c"
+/* Line 1704 of yacc.c  */
+#line 2670 "src/parse-gram.c"
     break;
 
-  case 72:
-/* Line 1679 of yacc.c  */
-#line 538 "src/parse-gram.y"
+  case 69:
+/* Line 1704 of yacc.c  */
+#line 535 "src/parse-gram.y"
     { (yyval.uniqstr) = uniqstr_new (""); }
-/* Line 1679 of yacc.c  */
-#line 2682 "src/parse-gram.c"
+/* Line 1704 of yacc.c  */
+#line 2678 "src/parse-gram.c"
     break;
 
-  case 73:
-/* Line 1679 of yacc.c  */
-#line 544 "src/parse-gram.y"
+  case 70:
+/* Line 1704 of yacc.c  */
+#line 541 "src/parse-gram.y"
     {
        current_type = (yyvsp[0].uniqstr);
        tag_seen = true;
      }
-/* Line 1679 of yacc.c  */
-#line 2693 "src/parse-gram.c"
+/* Line 1704 of yacc.c  */
+#line 2689 "src/parse-gram.c"
     break;
 
-  case 74:
-/* Line 1679 of yacc.c  */
-#line 549 "src/parse-gram.y"
+  case 71:
+/* Line 1704 of yacc.c  */
+#line 546 "src/parse-gram.y"
     {
        symbol_class_set ((yyvsp[0].symbol), current_class, (yylsp[0]), true);
        symbol_type_set ((yyvsp[0].symbol), current_type, (yylsp[0]));
      }
-/* Line 1679 of yacc.c  */
-#line 2704 "src/parse-gram.c"
+/* Line 1704 of yacc.c  */
+#line 2700 "src/parse-gram.c"
     break;
 
-  case 75:
-/* Line 1679 of yacc.c  */
-#line 554 "src/parse-gram.y"
+  case 72:
+/* Line 1704 of yacc.c  */
+#line 551 "src/parse-gram.y"
     {
       symbol_class_set ((yyvsp[-1].symbol), current_class, (yylsp[-1]), true);
       symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
       symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0]));
     }
-/* Line 1679 of yacc.c  */
-#line 2716 "src/parse-gram.c"
+/* Line 1704 of yacc.c  */
+#line 2712 "src/parse-gram.c"
     break;
 
-  case 76:
-/* Line 1679 of yacc.c  */
-#line 560 "src/parse-gram.y"
+  case 73:
+/* Line 1704 of yacc.c  */
+#line 557 "src/parse-gram.y"
     {
       symbol_class_set ((yyvsp[-1].symbol), current_class, (yylsp[-1]), true);
       symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
       symbol_make_alias ((yyvsp[-1].symbol), (yyvsp[0].symbol), (yyloc));
     }
-/* Line 1679 of yacc.c  */
-#line 2728 "src/parse-gram.c"
+/* Line 1704 of yacc.c  */
+#line 2724 "src/parse-gram.c"
     break;
 
-  case 77:
-/* Line 1679 of yacc.c  */
-#line 566 "src/parse-gram.y"
+  case 74:
+/* Line 1704 of yacc.c  */
+#line 563 "src/parse-gram.y"
     {
       symbol_class_set ((yyvsp[-2].symbol), current_class, (yylsp[-2]), true);
       symbol_type_set ((yyvsp[-2].symbol), current_type, (yylsp[-2]));
       symbol_user_token_number_set ((yyvsp[-2].symbol), (yyvsp[-1].integer), (yylsp[-1]));
       symbol_make_alias ((yyvsp[-2].symbol), (yyvsp[0].symbol), (yyloc));
     }
-/* Line 1679 of yacc.c  */
-#line 2741 "src/parse-gram.c"
+/* Line 1704 of yacc.c  */
+#line 2737 "src/parse-gram.c"
     break;
 
-  case 84:
-/* Line 1679 of yacc.c  */
-#line 596 "src/parse-gram.y"
+  case 81:
+/* Line 1704 of yacc.c  */
+#line 593 "src/parse-gram.y"
     {
       yyerrok;
     }
-/* Line 1679 of yacc.c  */
-#line 2751 "src/parse-gram.c"
+/* Line 1704 of yacc.c  */
+#line 2747 "src/parse-gram.c"
     break;
 
-  case 85:
-/* Line 1679 of yacc.c  */
-#line 602 "src/parse-gram.y"
+  case 82:
+/* Line 1704 of yacc.c  */
+#line 599 "src/parse-gram.y"
     { current_lhs ((yyvsp[-1].symbol), (yylsp[-1]), (yyvsp[0].named_ref)); }
-/* Line 1679 of yacc.c  */
-#line 2759 "src/parse-gram.c"
+/* Line 1704 of yacc.c  */
+#line 2755 "src/parse-gram.c"
     break;
 
-  case 86:
-/* Line 1679 of yacc.c  */
-#line 603 "src/parse-gram.y"
+  case 83:
+/* Line 1704 of yacc.c  */
+#line 600 "src/parse-gram.y"
     {
     /* Free the current lhs. */
     current_lhs (0, (yylsp[-3]), 0);
   }
-/* Line 1679 of yacc.c  */
-#line 2770 "src/parse-gram.c"
+/* Line 1704 of yacc.c  */
+#line 2766 "src/parse-gram.c"
     break;
 
-  case 87:
-/* Line 1679 of yacc.c  */
-#line 610 "src/parse-gram.y"
+  case 84:
+/* Line 1704 of yacc.c  */
+#line 607 "src/parse-gram.y"
     { grammar_current_rule_end ((yylsp[0])); }
-/* Line 1679 of yacc.c  */
-#line 2778 "src/parse-gram.c"
+/* Line 1704 of yacc.c  */
+#line 2774 "src/parse-gram.c"
     break;
 
-  case 88:
-/* Line 1679 of yacc.c  */
-#line 611 "src/parse-gram.y"
+  case 85:
+/* Line 1704 of yacc.c  */
+#line 608 "src/parse-gram.y"
     { grammar_current_rule_end ((yylsp[0])); }
-/* Line 1679 of yacc.c  */
-#line 2786 "src/parse-gram.c"
+/* Line 1704 of yacc.c  */
+#line 2782 "src/parse-gram.c"
     break;
 
-  case 90:
-/* Line 1679 of yacc.c  */
-#line 617 "src/parse-gram.y"
+  case 87:
+/* Line 1704 of yacc.c  */
+#line 614 "src/parse-gram.y"
     { grammar_current_rule_begin (current_lhs_symbol, current_lhs_location,
                                   current_lhs_named_ref); }
-/* Line 1679 of yacc.c  */
-#line 2795 "src/parse-gram.c"
+/* Line 1704 of yacc.c  */
+#line 2791 "src/parse-gram.c"
     break;
 
-  case 91:
-/* Line 1679 of yacc.c  */
-#line 620 "src/parse-gram.y"
+  case 88:
+/* Line 1704 of yacc.c  */
+#line 617 "src/parse-gram.y"
     { grammar_current_rule_symbol_append ((yyvsp[-1].symbol), (yylsp[-1]), (yyvsp[0].named_ref)); }
-/* Line 1679 of yacc.c  */
-#line 2803 "src/parse-gram.c"
+/* Line 1704 of yacc.c  */
+#line 2799 "src/parse-gram.c"
     break;
 
-  case 92:
-/* Line 1679 of yacc.c  */
-#line 622 "src/parse-gram.y"
+  case 89:
+/* Line 1704 of yacc.c  */
+#line 619 "src/parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[-1].code), (yylsp[-1]), (yyvsp[0].named_ref), false); }
-/* Line 1679 of yacc.c  */
-#line 2811 "src/parse-gram.c"
+/* Line 1704 of yacc.c  */
+#line 2807 "src/parse-gram.c"
     break;
 
-  case 93:
-/* Line 1679 of yacc.c  */
-#line 624 "src/parse-gram.y"
+  case 90:
+/* Line 1704 of yacc.c  */
+#line 621 "src/parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[0].code), (yylsp[0]), NULL, true); }
-/* Line 1679 of yacc.c  */
-#line 2819 "src/parse-gram.c"
+/* Line 1704 of yacc.c  */
+#line 2815 "src/parse-gram.c"
     break;
 
-  case 94:
-/* Line 1679 of yacc.c  */
-#line 626 "src/parse-gram.y"
+  case 91:
+/* Line 1704 of yacc.c  */
+#line 623 "src/parse-gram.y"
     { grammar_current_rule_prec_set ((yyvsp[0].symbol), (yylsp[0])); }
-/* Line 1679 of yacc.c  */
-#line 2827 "src/parse-gram.c"
+/* Line 1704 of yacc.c  */
+#line 2823 "src/parse-gram.c"
     break;
 
-  case 95:
-/* Line 1679 of yacc.c  */
-#line 628 "src/parse-gram.y"
+  case 92:
+/* Line 1704 of yacc.c  */
+#line 625 "src/parse-gram.y"
     { grammar_current_rule_dprec_set ((yyvsp[0].integer), (yylsp[0])); }
-/* Line 1679 of yacc.c  */
-#line 2835 "src/parse-gram.c"
+/* Line 1704 of yacc.c  */
+#line 2831 "src/parse-gram.c"
     break;
 
-  case 96:
-/* Line 1679 of yacc.c  */
-#line 630 "src/parse-gram.y"
+  case 93:
+/* Line 1704 of yacc.c  */
+#line 627 "src/parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1679 of yacc.c  */
-#line 2843 "src/parse-gram.c"
+/* Line 1704 of yacc.c  */
+#line 2839 "src/parse-gram.c"
     break;
 
-  case 97:
-/* Line 1679 of yacc.c  */
-#line 634 "src/parse-gram.y"
+  case 94:
+/* Line 1704 of yacc.c  */
+#line 631 "src/parse-gram.y"
     { (yyval.named_ref) = 0; }
-/* Line 1679 of yacc.c  */
-#line 2851 "src/parse-gram.c"
+/* Line 1704 of yacc.c  */
+#line 2847 "src/parse-gram.c"
     break;
 
-  case 98:
-/* Line 1679 of yacc.c  */
-#line 636 "src/parse-gram.y"
+  case 95:
+/* Line 1704 of yacc.c  */
+#line 633 "src/parse-gram.y"
     { (yyval.named_ref) = named_ref_new((yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1679 of yacc.c  */
-#line 2859 "src/parse-gram.c"
+/* Line 1704 of yacc.c  */
+#line 2855 "src/parse-gram.c"
     break;
 
-  case 100:
-/* Line 1679 of yacc.c  */
-#line 647 "src/parse-gram.y"
+  case 97:
+/* Line 1704 of yacc.c  */
+#line 644 "src/parse-gram.y"
     { (yyval.uniqstr) = uniqstr_new ((yyvsp[0].chars)); }
-/* Line 1679 of yacc.c  */
-#line 2867 "src/parse-gram.c"
+/* Line 1704 of yacc.c  */
+#line 2863 "src/parse-gram.c"
     break;
 
-  case 101:
-/* Line 1679 of yacc.c  */
-#line 652 "src/parse-gram.y"
+  case 98:
+/* Line 1704 of yacc.c  */
+#line 649 "src/parse-gram.y"
     { (yyval.chars) = ""; }
-/* Line 1679 of yacc.c  */
-#line 2875 "src/parse-gram.c"
+/* Line 1704 of yacc.c  */
+#line 2871 "src/parse-gram.c"
     break;
 
-  case 102:
-/* Line 1679 of yacc.c  */
-#line 653 "src/parse-gram.y"
+  case 99:
+/* Line 1704 of yacc.c  */
+#line 650 "src/parse-gram.y"
     { (yyval.chars) = (yyvsp[0].uniqstr); }
-/* Line 1679 of yacc.c  */
-#line 2883 "src/parse-gram.c"
+/* Line 1704 of yacc.c  */
+#line 2879 "src/parse-gram.c"
     break;
 
-  case 104:
-/* Line 1679 of yacc.c  */
-#line 664 "src/parse-gram.y"
+  case 101:
+/* Line 1704 of yacc.c  */
+#line 661 "src/parse-gram.y"
     {
       code_props plain_code;
       (yyvsp[0].code)[strlen ((yyvsp[0].code)) - 1] = '\n';
@@ -2893,52 +2889,52 @@ yyreduce:
       gram_scanner_last_string_free ();
       (yyval.chars) = plain_code.code;
     }
-/* Line 1679 of yacc.c  */
-#line 2898 "src/parse-gram.c"
+/* Line 1704 of yacc.c  */
+#line 2894 "src/parse-gram.c"
     break;
 
-  case 105:
-/* Line 1679 of yacc.c  */
-#line 684 "src/parse-gram.y"
+  case 102:
+/* Line 1704 of yacc.c  */
+#line 681 "src/parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1679 of yacc.c  */
-#line 2906 "src/parse-gram.c"
+/* Line 1704 of yacc.c  */
+#line 2902 "src/parse-gram.c"
     break;
 
-  case 106:
-/* Line 1679 of yacc.c  */
-#line 686 "src/parse-gram.y"
+  case 103:
+/* Line 1704 of yacc.c  */
+#line 683 "src/parse-gram.y"
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[0].character)), (yylsp[0]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
       symbol_user_token_number_set ((yyval.symbol), (yyvsp[0].character), (yylsp[0]));
     }
-/* Line 1679 of yacc.c  */
-#line 2918 "src/parse-gram.c"
+/* Line 1704 of yacc.c  */
+#line 2914 "src/parse-gram.c"
     break;
 
-  case 107:
-/* Line 1679 of yacc.c  */
-#line 694 "src/parse-gram.y"
+  case 104:
+/* Line 1704 of yacc.c  */
+#line 691 "src/parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1679 of yacc.c  */
-#line 2926 "src/parse-gram.c"
+/* Line 1704 of yacc.c  */
+#line 2922 "src/parse-gram.c"
     break;
 
-  case 110:
-/* Line 1679 of yacc.c  */
-#line 706 "src/parse-gram.y"
+  case 107:
+/* Line 1704 of yacc.c  */
+#line 703 "src/parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[0].chars)), (yylsp[0]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
     }
-/* Line 1679 of yacc.c  */
-#line 2937 "src/parse-gram.c"
+/* Line 1704 of yacc.c  */
+#line 2933 "src/parse-gram.c"
     break;
 
-  case 112:
-/* Line 1679 of yacc.c  */
-#line 715 "src/parse-gram.y"
+  case 109:
+/* Line 1704 of yacc.c  */
+#line 712 "src/parse-gram.y"
     {
       code_props plain_code;
       code_props_plain_init (&plain_code, (yyvsp[0].chars), (yylsp[0]));
@@ -2947,13 +2943,13 @@ yyreduce:
       muscle_code_grow ("epilogue", plain_code.code, (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1679 of yacc.c  */
-#line 2952 "src/parse-gram.c"
+/* Line 1704 of yacc.c  */
+#line 2948 "src/parse-gram.c"
     break;
 
 
-/* Line 1679 of yacc.c  */
-#line 2957 "src/parse-gram.c"
+/* Line 1704 of yacc.c  */
+#line 2953 "src/parse-gram.c"
         default: break;
       }
     if (yychar_backup != yychar)
@@ -3128,7 +3124,9 @@ yyerrlab1:
      current lookahead token, the shift below will for sure.  */
   YY_LAC_DISCARD ("error recovery");
 
+  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
   *++yyvsp = yylval;
+  YY_IGNORE_MAYBE_UNINITIALIZED_END
 
   yyerror_range[2] = yylloc;
   /* Using YYLLOC is tempting, but would change the location of
@@ -3198,9 +3196,8 @@ yyreturn:
 #endif
   return yyresult;
 }
-/* Line 1937 of yacc.c  */
-#line 725 "src/parse-gram.y"
-
+/* Line 1964 of yacc.c  */
+#line 722 "src/parse-gram.y"
 
 
 /* Return the location of the left-hand side of a rule whose
