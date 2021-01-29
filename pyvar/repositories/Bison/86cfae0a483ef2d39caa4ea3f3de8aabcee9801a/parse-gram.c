@@ -191,13 +191,13 @@ static int current_prec = 0;
      PERCENT_DPREC = 270,
      PERCENT_MERGE = 271,
      PERCENT_CODE = 272,
-     PERCENT_DEBUG = 273,
-     PERCENT_DEFAULT_PREC = 274,
-     PERCENT_DEFINE = 275,
-     PERCENT_DEFINES = 276,
-     PERCENT_ERROR_VERBOSE = 277,
-     PERCENT_EXPECT = 278,
-     PERCENT_EXPECT_RR = 279,
+     PERCENT_DEFAULT_PREC = 273,
+     PERCENT_DEFINE = 274,
+     PERCENT_DEFINES = 275,
+     PERCENT_ERROR_VERBOSE = 276,
+     PERCENT_EXPECT = 277,
+     PERCENT_EXPECT_RR = 278,
+     PERCENT_FLAG = 279,
      PERCENT_FILE_PREFIX = 280,
      PERCENT_GLR_PARSER = 281,
      PERCENT_INITIAL_ACTION = 282,
@@ -250,13 +250,13 @@ static int current_prec = 0;
 #define PERCENT_DPREC 270
 #define PERCENT_MERGE 271
 #define PERCENT_CODE 272
-#define PERCENT_DEBUG 273
-#define PERCENT_DEFAULT_PREC 274
-#define PERCENT_DEFINE 275
-#define PERCENT_DEFINES 276
-#define PERCENT_ERROR_VERBOSE 277
-#define PERCENT_EXPECT 278
-#define PERCENT_EXPECT_RR 279
+#define PERCENT_DEFAULT_PREC 273
+#define PERCENT_DEFINE 274
+#define PERCENT_DEFINES 275
+#define PERCENT_ERROR_VERBOSE 276
+#define PERCENT_EXPECT 277
+#define PERCENT_EXPECT_RR 278
+#define PERCENT_FLAG 279
 #define PERCENT_FILE_PREFIX 280
 #define PERCENT_GLR_PARSER 281
 #define PERCENT_INITIAL_ACTION 282
@@ -559,9 +559,9 @@ union yyalloc
 /* YYNNTS -- Number of nonterminals.  */
 #define YYNNTS  33
 /* YYNRULES -- Number of rules.  */
-#define YYNRULES  106
+#define YYNRULES  105
 /* YYNSTATES -- Number of states.  */
-#define YYNSTATES  144
+#define YYNSTATES  143
 
 /* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
    by yylex, with out-of-bounds checking.  */
@@ -613,17 +613,17 @@ static const yytype_uint8 yytranslate[] =
   /* YYRLINEYYN -- Source line where rule number YYN was defined.    */
 static const yytype_uint16 yyrline[] =
 {
-       0,   203,   203,   211,   213,   217,   218,   228,   232,   236,
-     237,   242,   246,   247,   248,   249,   250,   255,   264,   265,
-     266,   267,   268,   269,   270,   271,   272,   273,   274,   287,
-     288,   312,   313,   314,   315,   319,   320,   321,   325,   332,
-     339,   343,   347,   354,   369,   370,   374,   386,   386,   391,
-     391,   396,   407,   422,   423,   424,   425,   429,   430,   435,
-     437,   442,   443,   448,   450,   455,   456,   460,   461,   462,
-     463,   468,   473,   478,   484,   490,   501,   502,   511,   512,
-     518,   519,   520,   527,   527,   531,   532,   533,   538,   539,
-     541,   543,   545,   547,   557,   558,   564,   567,   576,   596,
-     598,   607,   612,   613,   618,   625,   627
+       0,   204,   204,   212,   214,   218,   219,   229,   233,   237,
+     238,   243,   244,   245,   246,   247,   252,   261,   262,   263,
+     264,   265,   266,   267,   268,   269,   270,   271,   284,   285,
+     309,   310,   311,   312,   316,   317,   318,   322,   329,   336,
+     340,   344,   351,   366,   367,   371,   383,   383,   388,   388,
+     393,   404,   419,   420,   421,   422,   426,   427,   432,   434,
+     439,   440,   445,   447,   452,   453,   457,   458,   459,   460,
+     465,   470,   475,   481,   487,   498,   499,   508,   509,   515,
+     516,   517,   524,   524,   528,   529,   530,   535,   536,   538,
+     540,   542,   544,   554,   555,   561,   564,   573,   593,   595,
+     604,   609,   610,   615,   622,   624
 };
 #endif
 
@@ -636,10 +636,10 @@ static const char *const yytname[] =
   "\"%token\"", "\"%nterm\"", "\"%type\"", "\"%destructor\"",
   "\"%printer\"", "\"%left\"", "\"%right\"", "\"%nonassoc\"",
   "\"%precedence\"", "\"%prec\"", "\"%dprec\"", "\"%merge\"", "\"%code\"",
-  "\"%debug\"", "\"%default-prec\"", "\"%define\"", "\"%defines\"",
-  "\"%error-verbose\"", "\"%expect\"", "\"%expect-rr\"",
-  "\"%file-prefix\"", "\"%glr-parser\"", "\"%initial-action\"",
-  "\"%language\"", "\"%lex-param\"", "\"%locations\"", "\"%name-prefix\"",
+  "\"%default-prec\"", "\"%define\"", "\"%defines\"", "\"%error-verbose\"",
+  "\"%expect\"", "\"%expect-rr\"", "\"%<flag>\"", "\"%file-prefix\"",
+  "\"%glr-parser\"", "\"%initial-action\"", "\"%language\"",
+  "\"%lex-param\"", "\"%locations\"", "\"%name-prefix\"",
   "\"%no-default-prec\"", "\"%no-lines\"", "\"%nondeterministic-parser\"",
   "\"%output\"", "\"%parse-param\"", "\"%pure-parser\"", "\"%require\"",
   "\"%skeleton\"", "\"%start\"", "\"%token-table\"", "\"%verbose\"",
@@ -671,29 +671,29 @@ static const yytype_uint16 yytoknum[] =
 };
 # endif
 
-#define YYPACT_NINF -81
+#define YYPACT_NINF -82
 
-#define YYTABLE_NINF -106
+#define YYTABLE_NINF -105
 
   /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
      STATE-NUM.    */
 static const yytype_int16 yypact[] =
 {
-     -81,    23,   111,   -81,   -81,   -81,   -28,   -12,    -8,   -81,
-     -81,   -81,   -81,   -13,   -81,   -81,    14,    43,   -81,    48,
-      49,     2,   -81,    10,    53,    34,   -81,    13,   -81,   -81,
-     -81,    26,    36,   -81,    54,    78,     0,   -81,   -81,   -81,
-      58,   -81,   -81,    41,   -81,   -81,   -81,   -81,    28,   -24,
-     -24,     0,    31,    31,   -81,    44,   -81,   -81,   -81,    81,
-     -81,   -81,   -81,   -81,    88,   -81,   -81,   -81,   -81,    89,
-     -81,    91,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,
-     -81,    42,   -81,    47,     1,   -81,   -81,   -81,   -81,    44,
-     -81,     0,   -81,   -81,   -24,    40,   -24,     0,   -81,   -81,
-     -81,   -81,    31,   -81,   -81,    31,   -81,   -81,   -81,   -81,
-     -81,   -81,   -81,   -81,    50,   -81,   -81,   -81,   -81,     0,
-     -81,    93,   -81,    98,   -81,   -81,   -81,   -81,   -14,   155,
-     -81,   -81,   -81,   -81,   -81,     0,    99,    51,   -81,   -81,
-     155,   -81,   -81,   -81
+     -82,    21,   111,   -82,   -82,   -82,   -14,    -8,     3,   -82,
+     -82,   -82,   -82,   -18,   -82,    14,    41,    42,    49,   -82,
+       2,   -82,    10,    53,    34,   -82,    13,   -82,   -82,   -82,
+      26,    35,   -82,    54,    78,     0,   -82,   -82,   -82,    58,
+     -82,   -82,    36,   -82,   -82,   -82,   -82,    28,   -23,   -23,
+       0,    32,    32,   -82,    45,   -82,   -82,   -82,    82,   -82,
+     -82,   -82,   -82,    88,   -82,   -82,   -82,   -82,    89,   -82,
+      91,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,
+      43,   -82,    44,     1,   -82,   -82,   -82,   -82,    45,   -82,
+       0,   -82,   -82,   -23,    39,   -23,     0,   -82,   -82,   -82,
+     -82,    32,   -82,   -82,    32,   -82,   -82,   -82,   -82,   -82,
+     -82,   -82,   -82,    55,   -82,   -82,   -82,   -82,     0,   -82,
+      96,   -82,    92,   -82,   -82,   -82,   -82,   -19,   155,   -82,
+     -82,   -82,   -82,   -82,     0,    98,    51,   -82,   -82,   155,
+     -82,   -82,   -82
 };
 
   /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
@@ -701,39 +701,39 @@ static const yytype_int16 yypact[] =
      error.    */
 static const yytype_uint8 yydefact[] =
 {
-       3,     0,     0,     1,    49,    47,     0,     0,     0,    53,
-      54,    55,    56,     0,     7,    40,     0,     9,    11,     0,
-       0,     0,    16,     0,     0,     0,    20,     0,    41,    23,
-      24,     0,     0,    28,     0,     0,     0,    31,    32,    33,
-       0,     6,    34,    44,     4,     5,    36,    35,    57,     0,
-       0,     0,     0,     0,    98,     0,    42,    95,    94,    96,
-      10,    12,    13,    14,     0,    17,    18,    19,    21,     0,
-      25,     0,    27,    29,    30,   104,   100,    99,   102,    37,
-     103,     0,   101,     0,     0,    78,    80,    83,    45,     0,
-      58,     0,    71,    76,    50,    72,    48,    51,    63,    68,
-      69,    70,    38,    65,    67,    39,    43,    97,     8,    15,
-      22,    26,    82,    81,     0,    79,     2,    88,    46,    52,
-      59,    61,    77,    73,    74,    64,    66,   106,    84,    85,
-      60,    62,    75,    88,    87,     0,     0,     0,    90,    89,
-      86,    91,    92,    93
+       3,     0,     0,     1,    48,    46,     0,     0,     0,    52,
+      53,    54,    55,     0,    39,     0,     9,     0,     0,     7,
+       0,    15,     0,     0,     0,    19,     0,    40,    22,    23,
+       0,     0,    27,     0,     0,     0,    30,    31,    32,     0,
+       6,    33,    43,     4,     5,    35,    34,    56,     0,     0,
+       0,     0,     0,    97,     0,    41,    94,    93,    95,    10,
+      11,    12,    13,     0,    16,    17,    18,    20,     0,    24,
+       0,    26,    28,    29,   103,    99,    98,   101,    36,   102,
+       0,   100,     0,     0,    77,    79,    82,    44,     0,    57,
+       0,    70,    75,    49,    71,    47,    50,    62,    67,    68,
+      69,    37,    64,    66,    38,    42,    96,     8,    14,    21,
+      25,    81,    80,     0,    78,     2,    87,    45,    51,    58,
+      60,    76,    72,    73,    63,    65,   105,    83,    84,    59,
+      61,    74,    87,    86,     0,     0,     0,    89,    88,    85,
+      90,    91,    92
 };
 
   /* YYPGOTO[NTERM-NUM].    */
 static const yytype_int8 yypgoto[] =
 {
-     -81,   -81,   -81,   -81,   100,   -81,   -81,   -81,   -81,   -81,
-     -81,   -81,   -81,   -11,   -81,    56,   -80,   -54,    60,   -81,
-      22,   -81,   -81,   -81,   -21,   -81,   -81,   -51,   -22,   -81,
-     -36,   -76,   -81
+     -82,   -82,   -82,   -82,   101,   -82,   -82,   -82,   -82,   -82,
+     -82,   -82,   -82,   -12,   -82,    56,   -81,   -56,    60,   -82,
+      27,   -82,   -82,   -82,   -20,   -82,   -82,   -50,   -21,   -82,
+     -35,   -70,   -82
 };
 
   /* YYDEFGOTO[NTERM-NUM].    */
 static const yytype_int16 yydefgoto[] =
 {
-      -1,     1,     2,    44,    83,    89,    46,    50,    49,    47,
-      48,    91,   119,   120,    97,   102,   103,    93,    94,    84,
-      85,    86,   117,   128,   129,    59,   108,    56,    78,    87,
-     104,    80,   116
+      -1,     1,     2,    43,    82,    88,    45,    49,    48,    46,
+      47,    90,   118,   119,    96,   101,   102,    92,    93,    83,
+      84,    85,   116,   127,   128,    58,   107,    55,    77,    86,
+     103,    79,   115
 };
 
   /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
@@ -742,45 +742,45 @@ static const yytype_int16 yydefgoto[] =
      If YYTABLE_NINF, syntax error.    */
 static const yytype_int16 yytable[] =
 {
-      79,  -105,    81,    75,   106,    63,     4,     5,     6,     7,
-       8,     9,    10,    11,    12,    98,    68,    57,    13,   124,
-      15,    76,   126,     3,    77,   126,    51,    95,    95,    70,
-      92,    54,    52,    28,    75,    55,    53,   133,   118,   134,
-     122,    36,   122,    75,   123,    76,    60,   132,    77,    64,
-      82,   114,    61,    62,    65,   121,    66,    73,    43,    81,
-      69,   125,    58,     4,     5,     6,     7,     8,     9,    10,
-      11,    12,    95,    71,    95,    13,    76,    15,    67,    77,
-      72,    74,    90,   121,   107,    99,   100,   101,    54,    88,
-      28,   109,   110,   139,   111,   112,   127,   131,    36,   141,
-     113,    75,    45,   142,   139,   143,   115,    82,   130,   105,
-      96,     0,   140,     0,     0,    43,     4,     5,     6,     7,
+      78,  -104,    80,    74,   105,    62,     4,     5,     6,     7,
+       8,     9,    10,    11,    12,    97,    67,    56,    13,    14,
+     125,     3,    75,   125,   123,    76,    53,    94,    94,    69,
+      54,    91,   132,    27,   133,    74,    51,   121,   117,   121,
+      50,    35,    74,   122,    59,    75,    60,    52,    76,    63,
+      81,   113,   131,    61,    64,   120,    65,    72,    42,    80,
+      68,   124,    57,     4,     5,     6,     7,     8,     9,    10,
+      11,    12,    94,    70,    94,    13,    14,    75,    66,    71,
+      76,    73,    89,   120,    87,   106,    98,    99,   100,    53,
+      27,   108,   109,   138,   110,    74,   111,   112,    35,   140,
+     130,   126,   141,    44,   138,   142,   129,    81,   104,    95,
+     114,     0,   139,     0,     0,    42,     4,     5,     6,     7,
        8,     9,    10,    11,    12,     0,     0,     0,    13,    14,
-      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
-      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
-      35,    36,    37,    38,    39,     0,     0,     0,    75,     0,
-       0,    40,     0,    41,    42,     0,     0,     0,    43,   135,
-     136,   137,     0,     0,     0,     0,     0,     0,     0,     0,
+      15,    16,     0,    17,    18,    19,    20,    21,    22,    23,
+      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
+      34,    35,    36,    37,    38,     0,     0,     0,    74,     0,
+       0,    39,     0,    40,    41,     0,     0,     0,    42,   134,
+     135,   136,     0,     0,     0,     0,     0,     0,     0,     0,
        0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
-       0,     0,     0,     0,     0,     0,     0,     0,     0,   138,
-      76,     0,     0,    77
+       0,     0,     0,     0,     0,     0,     0,     0,     0,   137,
+      75,     0,     0,    76
 };
 
 static const yytype_int16 yycheck[] =
 {
-      36,     0,     1,     3,    55,     3,     5,     6,     7,     8,
-       9,    10,    11,    12,    13,    51,     3,     3,    17,    95,
-      19,    45,   102,     0,    48,   105,    54,    49,    50,     3,
-      54,    44,    44,    32,     3,    48,    44,    51,    89,    53,
-      94,    40,    96,     3,     4,    45,     3,   123,    48,    47,
-      49,    50,     4,     4,    44,    91,     3,     3,    57,     1,
-      47,    97,    48,     5,     6,     7,     8,     9,    10,    11,
-      12,    13,    94,    47,    96,    17,    45,    19,    44,    48,
-      44,     3,    54,   119,     3,    54,    55,    56,    44,    48,
-      32,     3,     3,   129,     3,    53,    46,     4,    40,   135,
-      53,     3,     2,     4,   140,    54,    84,    49,   119,    53,
-      50,    -1,   133,    -1,    -1,    57,     5,     6,     7,     8,
+      35,     0,     1,     3,    54,     3,     5,     6,     7,     8,
+       9,    10,    11,    12,    13,    50,     3,     3,    17,    18,
+     101,     0,    45,   104,    94,    48,    44,    48,    49,     3,
+      48,    54,    51,    32,    53,     3,    44,    93,    88,    95,
+      54,    40,     3,     4,     3,    45,     4,    44,    48,    47,
+      49,    50,   122,     4,    44,    90,     3,     3,    57,     1,
+      47,    96,    48,     5,     6,     7,     8,     9,    10,    11,
+      12,    13,    93,    47,    95,    17,    18,    45,    44,    44,
+      48,     3,    54,   118,    48,     3,    54,    55,    56,    44,
+      32,     3,     3,   128,     3,     3,    53,    53,    40,   134,
+       4,    46,     4,     2,   139,    54,   118,    49,    52,    49,
+      83,    -1,   132,    -1,    -1,    57,     5,     6,     7,     8,
        9,    10,    11,    12,    13,    -1,    -1,    -1,    17,    18,
-      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
+      19,    20,    -1,    22,    23,    24,    25,    26,    27,    28,
       29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
       39,    40,    41,    42,    43,    -1,    -1,    -1,     3,    -1,
       -1,    50,    -1,    52,    53,    -1,    -1,    -1,    57,    14,
@@ -795,20 +795,20 @@ static const yytype_int16 yycheck[] =
 static const yytype_uint8 yystos[] =
 {
        0,    59,    60,     0,     5,     6,     7,     8,     9,    10,
-      11,    12,    13,    17,    18,    19,    20,    21,    22,    23,
-      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
-      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
-      50,    52,    53,    57,    61,    62,    64,    67,    68,    66,
-      65,    54,    44,    44,    44,    48,    85,     3,    48,    83,
-       3,     4,     4,     3,    47,    44,     3,    44,     3,    47,
-       3,    47,    44,     3,     3,     3,    45,    48,    86,    88,
-      89,     1,    49,    62,    77,    78,    79,    87,    48,    63,
-      54,    69,    54,    75,    76,    86,    76,    72,    88,    54,
-      55,    56,    73,    74,    88,    73,    85,     3,    84,     3,
-       3,     3,    53,    53,    50,    78,    90,    80,    85,    70,
-      71,    88,    75,     4,    89,    88,    74,    46,    81,    82,
-      71,     4,    89,    51,    53,    14,    15,    16,    44,    88,
-      82,    88,     4,    54
+      11,    12,    13,    17,    18,    19,    20,    22,    23,    24,
+      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
+      35,    36,    37,    38,    39,    40,    41,    42,    43,    50,
+      52,    53,    57,    61,    62,    64,    67,    68,    66,    65,
+      54,    44,    44,    44,    48,    85,     3,    48,    83,     3,
+       4,     4,     3,    47,    44,     3,    44,     3,    47,     3,
+      47,    44,     3,     3,     3,    45,    48,    86,    88,    89,
+       1,    49,    62,    77,    78,    79,    87,    48,    63,    54,
+      69,    54,    75,    76,    86,    76,    72,    88,    54,    55,
+      56,    73,    74,    88,    73,    85,     3,    84,     3,     3,
+       3,    53,    53,    50,    78,    90,    80,    85,    70,    71,
+      88,    75,     4,    89,    88,    74,    46,    81,    82,    71,
+       4,    89,    51,    53,    14,    15,    16,    44,    88,    82,
+      88,     4,    54
 };
 
   /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.    */
@@ -817,30 +817,30 @@ static const yytype_uint8 yyr1[] =
        0,    58,    59,    60,    60,    61,    61,    61,    61,    61,
       61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
       61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
-      61,    61,    61,    61,    61,    62,    62,    62,    62,    62,
-      62,    62,    62,    62,    63,    63,    62,    65,    64,    66,
-      64,    64,    67,    68,    68,    68,    68,    69,    69,    70,
-      70,    71,    71,    72,    72,    73,    73,    74,    74,    74,
-      74,    75,    75,    75,    75,    75,    76,    76,    77,    77,
-      78,    78,    78,    80,    79,    81,    81,    81,    82,    82,
-      82,    82,    82,    82,    83,    83,    84,    84,    85,    86,
-      86,    87,    88,    88,    89,    90,    90
+      61,    61,    61,    61,    62,    62,    62,    62,    62,    62,
+      62,    62,    62,    63,    63,    62,    65,    64,    66,    64,
+      64,    67,    68,    68,    68,    68,    69,    69,    70,    70,
+      71,    71,    72,    72,    73,    73,    74,    74,    74,    74,
+      75,    75,    75,    75,    75,    76,    76,    77,    77,    78,
+      78,    78,    80,    79,    81,    81,    81,    82,    82,    82,
+      82,    82,    82,    83,    83,    84,    84,    85,    86,    86,
+      87,    88,    88,    89,    90,    90
 };
 
   /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.    */
 static const yytype_uint8 yyr2[] =
 {
        0,     2,     4,     0,     2,     1,     1,     1,     3,     1,
-       2,     1,     2,     2,     2,     3,     1,     2,     2,     2,
-       1,     2,     3,     1,     1,     2,     3,     2,     1,     2,
-       2,     1,     1,     1,     1,     1,     1,     2,     3,     3,
-       1,     1,     2,     3,     0,     1,     3,     0,     3,     0,
-       3,     3,     3,     1,     1,     1,     1,     0,     1,     1,
-       2,     1,     2,     1,     2,     1,     2,     1,     1,     1,
-       1,     1,     1,     2,     2,     3,     1,     2,     1,     2,
-       1,     2,     2,     0,     3,     1,     3,     2,     0,     2,
-       2,     3,     3,     3,     1,     1,     0,     1,     1,     1,
-       1,     1,     1,     1,     1,     0,     2
+       2,     2,     2,     2,     3,     1,     2,     2,     2,     1,
+       2,     3,     1,     1,     2,     3,     2,     1,     2,     2,
+       1,     1,     1,     1,     1,     1,     2,     3,     3,     1,
+       1,     2,     3,     0,     1,     3,     0,     3,     0,     3,
+       3,     3,     1,     1,     1,     1,     0,     1,     1,     2,
+       1,     2,     1,     2,     1,     2,     1,     1,     1,     1,
+       1,     1,     2,     2,     3,     1,     2,     1,     2,     1,
+       2,     2,     0,     3,     1,     3,     2,     0,     2,     2,
+       3,     3,     3,     1,     1,     0,     1,     1,     1,     1,
+       1,     1,     1,     1,     0,     2
 };
 
 
@@ -1001,10 +1001,19 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
             case 4: // "integer"
 
 /* Line 647 of yacc.c  */
-#line 192 "parse-gram.y"
+#line 193 "parse-gram.y"
         { fprintf (stderr, "%d", ((*yyvaluep).integer)); }
 /* Line 647 of yacc.c  */
 #line 1008 "../../src/parse-gram.c"
+        break;
+
+            case 24: // "%<flag>"
+
+/* Line 647 of yacc.c  */
+#line 189 "parse-gram.y"
+        { fprintf (stderr, "%%%s", ((*yyvaluep).uniqstr)); }
+/* Line 647 of yacc.c  */
+#line 1017 "../../src/parse-gram.c"
         break;
 
             case 44: // "{...}"
@@ -1013,7 +1022,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 #line 183 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).code)); }
 /* Line 647 of yacc.c  */
-#line 1017 "../../src/parse-gram.c"
+#line 1026 "../../src/parse-gram.c"
         break;
 
             case 45: // "char"
@@ -1022,7 +1031,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 #line 175 "parse-gram.y"
         { fputs (char_name (((*yyvaluep).character)), stderr); }
 /* Line 647 of yacc.c  */
-#line 1026 "../../src/parse-gram.c"
+#line 1035 "../../src/parse-gram.c"
         break;
 
             case 46: // "epilogue"
@@ -1031,25 +1040,25 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 #line 183 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); }
 /* Line 647 of yacc.c  */
-#line 1035 "../../src/parse-gram.c"
+#line 1044 "../../src/parse-gram.c"
         break;
 
             case 48: // "identifier"
 
 /* Line 647 of yacc.c  */
-#line 188 "parse-gram.y"
+#line 187 "parse-gram.y"
         { fputs (((*yyvaluep).uniqstr), stderr); }
 /* Line 647 of yacc.c  */
-#line 1044 "../../src/parse-gram.c"
+#line 1053 "../../src/parse-gram.c"
         break;
 
             case 49: // "identifier:"
 
 /* Line 647 of yacc.c  */
-#line 189 "parse-gram.y"
+#line 188 "parse-gram.y"
         { fprintf (stderr, "%s:", ((*yyvaluep).uniqstr)); }
 /* Line 647 of yacc.c  */
-#line 1053 "../../src/parse-gram.c"
+#line 1062 "../../src/parse-gram.c"
         break;
 
             case 52: // "%{...%}"
@@ -1058,25 +1067,25 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 #line 183 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); }
 /* Line 647 of yacc.c  */
-#line 1062 "../../src/parse-gram.c"
+#line 1071 "../../src/parse-gram.c"
         break;
 
             case 54: // "<tag>"
 
 /* Line 647 of yacc.c  */
-#line 187 "parse-gram.y"
+#line 190 "parse-gram.y"
         { fprintf (stderr, "<%s>", ((*yyvaluep).uniqstr)); }
 /* Line 647 of yacc.c  */
-#line 1071 "../../src/parse-gram.c"
+#line 1080 "../../src/parse-gram.c"
         break;
 
             case 83: // variable
 
 /* Line 647 of yacc.c  */
-#line 188 "parse-gram.y"
+#line 187 "parse-gram.y"
         { fputs (((*yyvaluep).uniqstr), stderr); }
 /* Line 647 of yacc.c  */
-#line 1080 "../../src/parse-gram.c"
+#line 1089 "../../src/parse-gram.c"
         break;
 
             case 84: // content.opt
@@ -1085,7 +1094,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 #line 183 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); }
 /* Line 647 of yacc.c  */
-#line 1089 "../../src/parse-gram.c"
+#line 1098 "../../src/parse-gram.c"
         break;
 
             case 85: // braceless
@@ -1094,43 +1103,43 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 #line 183 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); }
 /* Line 647 of yacc.c  */
-#line 1098 "../../src/parse-gram.c"
+#line 1107 "../../src/parse-gram.c"
         break;
 
             case 86: // id
 
 /* Line 647 of yacc.c  */
-#line 195 "parse-gram.y"
+#line 196 "parse-gram.y"
         { fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); }
 /* Line 647 of yacc.c  */
-#line 1107 "../../src/parse-gram.c"
+#line 1116 "../../src/parse-gram.c"
         break;
 
             case 87: // id_colon
 
 /* Line 647 of yacc.c  */
-#line 196 "parse-gram.y"
+#line 197 "parse-gram.y"
         { fprintf (stderr, "%s:", ((*yyvaluep).symbol)->tag); }
 /* Line 647 of yacc.c  */
-#line 1116 "../../src/parse-gram.c"
+#line 1125 "../../src/parse-gram.c"
         break;
 
             case 88: // symbol
 
 /* Line 647 of yacc.c  */
-#line 195 "parse-gram.y"
+#line 196 "parse-gram.y"
         { fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); }
 /* Line 647 of yacc.c  */
-#line 1125 "../../src/parse-gram.c"
+#line 1134 "../../src/parse-gram.c"
         break;
 
             case 89: // string_as_id
 
 /* Line 647 of yacc.c  */
-#line 195 "parse-gram.y"
+#line 196 "parse-gram.y"
         { fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); }
 /* Line 647 of yacc.c  */
-#line 1134 "../../src/parse-gram.c"
+#line 1143 "../../src/parse-gram.c"
         break;
 
       default:
@@ -1652,7 +1661,7 @@ YYLTYPE yylloc;
   boundary_set (&yylloc.end, current_file, 1, 1);
 }
 /* Line 1167 of yacc.c  */
-#line 1656 "../../src/parse-gram.c"
+#line 1665 "../../src/parse-gram.c"
   yylsp[0] = yylloc;
 
   goto yysetstate;
@@ -1839,7 +1848,7 @@ yyreduce:
     {
         case 6:
 /* Line 1380 of yacc.c  */
-#line 219 "parse-gram.y"
+#line 220 "parse-gram.y"
     {
       code_props plain_code;
       code_props_plain_init (&plain_code, (yyvsp[0].chars), (yylsp[0]));
@@ -1850,104 +1859,94 @@ yyreduce:
       code_scanner_last_string_free ();
     }
 /* Line 1380 of yacc.c  */
-#line 1854 "../../src/parse-gram.c"
+#line 1863 "../../src/parse-gram.c"
     break;
 
   case 7:
 /* Line 1380 of yacc.c  */
-#line 229 "parse-gram.y"
+#line 230 "parse-gram.y"
     {
-      muscle_percent_define_insert ("debug", (yyloc), "");
+      muscle_percent_define_insert ((yyvsp[0].uniqstr), (yylsp[0]), "");
     }
 /* Line 1380 of yacc.c  */
-#line 1864 "../../src/parse-gram.c"
+#line 1873 "../../src/parse-gram.c"
     break;
 
   case 8:
 /* Line 1380 of yacc.c  */
-#line 233 "parse-gram.y"
+#line 234 "parse-gram.y"
     {
       muscle_percent_define_insert ((yyvsp[-1].uniqstr), (yylsp[-1]), (yyvsp[0].chars));
     }
 /* Line 1380 of yacc.c  */
-#line 1874 "../../src/parse-gram.c"
+#line 1883 "../../src/parse-gram.c"
     break;
 
   case 9:
 /* Line 1380 of yacc.c  */
-#line 236 "parse-gram.y"
+#line 237 "parse-gram.y"
     { defines_flag = true; }
 /* Line 1380 of yacc.c  */
-#line 1882 "../../src/parse-gram.c"
+#line 1891 "../../src/parse-gram.c"
     break;
 
   case 10:
 /* Line 1380 of yacc.c  */
-#line 238 "parse-gram.y"
+#line 239 "parse-gram.y"
     {
       defines_flag = true;
       spec_defines_file = xstrdup ((yyvsp[0].chars));
     }
 /* Line 1380 of yacc.c  */
-#line 1893 "../../src/parse-gram.c"
+#line 1902 "../../src/parse-gram.c"
     break;
 
   case 11:
 /* Line 1380 of yacc.c  */
 #line 243 "parse-gram.y"
-    {
-      muscle_percent_define_insert ("error_verbose", (yyloc), "");
-    }
+    { expected_sr_conflicts = (yyvsp[0].integer); }
 /* Line 1380 of yacc.c  */
-#line 1903 "../../src/parse-gram.c"
+#line 1910 "../../src/parse-gram.c"
     break;
 
   case 12:
 /* Line 1380 of yacc.c  */
-#line 246 "parse-gram.y"
-    { expected_sr_conflicts = (yyvsp[0].integer); }
+#line 244 "parse-gram.y"
+    { expected_rr_conflicts = (yyvsp[0].integer); }
 /* Line 1380 of yacc.c  */
-#line 1911 "../../src/parse-gram.c"
+#line 1918 "../../src/parse-gram.c"
     break;
 
   case 13:
 /* Line 1380 of yacc.c  */
-#line 247 "parse-gram.y"
-    { expected_rr_conflicts = (yyvsp[0].integer); }
+#line 245 "parse-gram.y"
+    { spec_file_prefix = (yyvsp[0].chars); }
 /* Line 1380 of yacc.c  */
-#line 1919 "../../src/parse-gram.c"
+#line 1926 "../../src/parse-gram.c"
     break;
 
   case 14:
 /* Line 1380 of yacc.c  */
-#line 248 "parse-gram.y"
+#line 246 "parse-gram.y"
     { spec_file_prefix = (yyvsp[0].chars); }
 /* Line 1380 of yacc.c  */
-#line 1927 "../../src/parse-gram.c"
+#line 1934 "../../src/parse-gram.c"
     break;
 
   case 15:
 /* Line 1380 of yacc.c  */
-#line 249 "parse-gram.y"
-    { spec_file_prefix = (yyvsp[0].chars); }
-/* Line 1380 of yacc.c  */
-#line 1935 "../../src/parse-gram.c"
-    break;
-
-  case 16:
-/* Line 1380 of yacc.c  */
-#line 251 "parse-gram.y"
+#line 248 "parse-gram.y"
     {
       nondeterministic_parser = true;
       glr_parser = true;
     }
 /* Line 1380 of yacc.c  */
-#line 1946 "../../src/parse-gram.c"
+#line 1945 "../../src/parse-gram.c"
     break;
 
-  case 17:
+  case 16:
 /* Line 1380 of yacc.c  */
-#line 256 "parse-gram.y"
+#line 253 "parse-gram.y"
     {
       code_props action;
       code_props_symbol_action_init (&action, (yyvsp[0].code), (yylsp[0]));
@@ -1957,92 +1956,92 @@ yyreduce:
       code_scanner_last_string_free ();
     }
 /* Line 1380 of yacc.c  */
-#line 1961 "../../src/parse-gram.c"
+#line 1960 "../../src/parse-gram.c"
     break;
 
-  case 18:
+  case 17:
 /* Line 1380 of yacc.c  */
-#line 264 "parse-gram.y"
+#line 261 "parse-gram.y"
     { language_argmatch ((yyvsp[0].chars), grammar_prio, (yylsp[-1])); }
 /* Line 1380 of yacc.c  */
-#line 1969 "../../src/parse-gram.c"
+#line 1968 "../../src/parse-gram.c"
     break;
 
-  case 19:
+  case 18:
 /* Line 1380 of yacc.c  */
-#line 265 "parse-gram.y"
+#line 262 "parse-gram.y"
     { add_param ("lex_param", (yyvsp[0].code), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 1977 "../../src/parse-gram.c"
+#line 1976 "../../src/parse-gram.c"
     break;
 
-  case 20:
+  case 19:
 /* Line 1380 of yacc.c  */
-#line 266 "parse-gram.y"
+#line 263 "parse-gram.y"
     { locations_flag = true; }
 /* Line 1380 of yacc.c  */
-#line 1985 "../../src/parse-gram.c"
+#line 1984 "../../src/parse-gram.c"
     break;
 
-  case 21:
+  case 20:
 /* Line 1380 of yacc.c  */
-#line 267 "parse-gram.y"
+#line 264 "parse-gram.y"
     { spec_name_prefix = (yyvsp[0].chars); }
 /* Line 1380 of yacc.c  */
-#line 1993 "../../src/parse-gram.c"
+#line 1992 "../../src/parse-gram.c"
     break;
 
-  case 22:
+  case 21:
 /* Line 1380 of yacc.c  */
-#line 268 "parse-gram.y"
+#line 265 "parse-gram.y"
     { spec_name_prefix = (yyvsp[0].chars); }
 /* Line 1380 of yacc.c  */
-#line 2001 "../../src/parse-gram.c"
+#line 2000 "../../src/parse-gram.c"
     break;
 
-  case 23:
+  case 22:
 /* Line 1380 of yacc.c  */
-#line 269 "parse-gram.y"
+#line 266 "parse-gram.y"
     { no_lines_flag = true; }
 /* Line 1380 of yacc.c  */
-#line 2009 "../../src/parse-gram.c"
+#line 2008 "../../src/parse-gram.c"
     break;
 
-  case 24:
+  case 23:
 /* Line 1380 of yacc.c  */
-#line 270 "parse-gram.y"
+#line 267 "parse-gram.y"
     { nondeterministic_parser = true; }
 /* Line 1380 of yacc.c  */
-#line 2017 "../../src/parse-gram.c"
+#line 2016 "../../src/parse-gram.c"
     break;
 
-  case 25:
+  case 24:
 /* Line 1380 of yacc.c  */
-#line 271 "parse-gram.y"
+#line 268 "parse-gram.y"
     { spec_outfile = (yyvsp[0].chars); }
 /* Line 1380 of yacc.c  */
-#line 2025 "../../src/parse-gram.c"
+#line 2024 "../../src/parse-gram.c"
     break;
 
-  case 26:
+  case 25:
 /* Line 1380 of yacc.c  */
-#line 272 "parse-gram.y"
+#line 269 "parse-gram.y"
     { spec_outfile = (yyvsp[0].chars); }
 /* Line 1380 of yacc.c  */
-#line 2033 "../../src/parse-gram.c"
+#line 2032 "../../src/parse-gram.c"
     break;
 
-  case 27:
+  case 26:
 /* Line 1380 of yacc.c  */
-#line 273 "parse-gram.y"
+#line 270 "parse-gram.y"
     { add_param ("parse_param", (yyvsp[0].code), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2041 "../../src/parse-gram.c"
+#line 2040 "../../src/parse-gram.c"
     break;
 
-  case 28:
+  case 27:
 /* Line 1380 of yacc.c  */
-#line 275 "parse-gram.y"
+#line 272 "parse-gram.y"
     {
       /* %pure-parser is deprecated in favor of `%define api.pure', so use
          `%define api.pure' in a backward-compatible manner here.  First, don't
@@ -2056,20 +2055,20 @@ yyreduce:
         muscle_percent_define_insert ("api.pure", (yylsp[0]), "");
     }
 /* Line 1380 of yacc.c  */
-#line 2060 "../../src/parse-gram.c"
+#line 2059 "../../src/parse-gram.c"
     break;
 
-  case 29:
+  case 28:
 /* Line 1380 of yacc.c  */
-#line 287 "parse-gram.y"
+#line 284 "parse-gram.y"
     { version_check (&(yylsp[0]), (yyvsp[0].chars)); }
 /* Line 1380 of yacc.c  */
-#line 2068 "../../src/parse-gram.c"
+#line 2067 "../../src/parse-gram.c"
     break;
 
-  case 30:
+  case 29:
 /* Line 1380 of yacc.c  */
-#line 289 "parse-gram.y"
+#line 286 "parse-gram.y"
     {
       char const *skeleton_user = (yyvsp[0].chars);
       if (strchr (skeleton_user, '/'))
@@ -2094,46 +2093,46 @@ yyreduce:
       skeleton_arg (skeleton_user, grammar_prio, (yylsp[-1]));
     }
 /* Line 1380 of yacc.c  */
-#line 2098 "../../src/parse-gram.c"
+#line 2097 "../../src/parse-gram.c"
     break;
 
-  case 31:
+  case 30:
 /* Line 1380 of yacc.c  */
-#line 312 "parse-gram.y"
+#line 309 "parse-gram.y"
     { token_table_flag = true; }
 /* Line 1380 of yacc.c  */
-#line 2106 "../../src/parse-gram.c"
+#line 2105 "../../src/parse-gram.c"
     break;
 
-  case 32:
+  case 31:
 /* Line 1380 of yacc.c  */
-#line 313 "parse-gram.y"
+#line 310 "parse-gram.y"
     { report_flag |= report_states; }
 /* Line 1380 of yacc.c  */
-#line 2114 "../../src/parse-gram.c"
+#line 2113 "../../src/parse-gram.c"
     break;
 
-  case 33:
+  case 32:
 /* Line 1380 of yacc.c  */
-#line 314 "parse-gram.y"
+#line 311 "parse-gram.y"
     { yacc_flag = true; }
 /* Line 1380 of yacc.c  */
-#line 2122 "../../src/parse-gram.c"
+#line 2121 "../../src/parse-gram.c"
     break;
 
-  case 37:
+  case 36:
 /* Line 1380 of yacc.c  */
-#line 322 "parse-gram.y"
+#line 319 "parse-gram.y"
     {
       grammar_start_symbol_set ((yyvsp[0].symbol), (yylsp[0]));
     }
 /* Line 1380 of yacc.c  */
-#line 2132 "../../src/parse-gram.c"
+#line 2131 "../../src/parse-gram.c"
     break;
 
-  case 38:
+  case 37:
 /* Line 1380 of yacc.c  */
-#line 326 "parse-gram.y"
+#line 323 "parse-gram.y"
     {
       symbol_list *list;
       for (list = (yyvsp[0].list); list; list = list->next)
@@ -2141,12 +2140,12 @@ yyreduce:
       symbol_list_free ((yyvsp[0].list));
     }
 /* Line 1380 of yacc.c  */
-#line 2145 "../../src/parse-gram.c"
+#line 2144 "../../src/parse-gram.c"
     break;
 
-  case 39:
+  case 38:
 /* Line 1380 of yacc.c  */
-#line 333 "parse-gram.y"
+#line 330 "parse-gram.y"
     {
       symbol_list *list;
       for (list = (yyvsp[0].list); list; list = list->next)
@@ -2154,32 +2153,32 @@ yyreduce:
       symbol_list_free ((yyvsp[0].list));
     }
 /* Line 1380 of yacc.c  */
-#line 2158 "../../src/parse-gram.c"
+#line 2157 "../../src/parse-gram.c"
     break;
 
-  case 40:
+  case 39:
 /* Line 1380 of yacc.c  */
-#line 340 "parse-gram.y"
+#line 337 "parse-gram.y"
     {
       default_prec = true;
     }
 /* Line 1380 of yacc.c  */
-#line 2168 "../../src/parse-gram.c"
+#line 2167 "../../src/parse-gram.c"
     break;
 
-  case 41:
+  case 40:
 /* Line 1380 of yacc.c  */
-#line 344 "parse-gram.y"
+#line 341 "parse-gram.y"
     {
       default_prec = false;
     }
 /* Line 1380 of yacc.c  */
-#line 2178 "../../src/parse-gram.c"
+#line 2177 "../../src/parse-gram.c"
     break;
 
-  case 42:
+  case 41:
 /* Line 1380 of yacc.c  */
-#line 348 "parse-gram.y"
+#line 345 "parse-gram.y"
     {
       /* Do not invoke muscle_percent_code_grow here since it invokes
          muscle_user_name_list_grow.  */
@@ -2187,89 +2186,89 @@ yyreduce:
       code_scanner_last_string_free ();
     }
 /* Line 1380 of yacc.c  */
-#line 2191 "../../src/parse-gram.c"
+#line 2190 "../../src/parse-gram.c"
     break;
 
-  case 43:
+  case 42:
 /* Line 1380 of yacc.c  */
-#line 355 "parse-gram.y"
+#line 352 "parse-gram.y"
     {
       muscle_percent_code_grow ((yyvsp[-1].uniqstr), (yylsp[-1]), (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
 /* Line 1380 of yacc.c  */
-#line 2202 "../../src/parse-gram.c"
+#line 2201 "../../src/parse-gram.c"
     break;
 
-  case 44:
+  case 43:
 /* Line 1380 of yacc.c  */
-#line 369 "parse-gram.y"
+#line 366 "parse-gram.y"
     {}
 /* Line 1380 of yacc.c  */
-#line 2210 "../../src/parse-gram.c"
+#line 2209 "../../src/parse-gram.c"
     break;
 
-  case 45:
+  case 44:
 /* Line 1380 of yacc.c  */
-#line 370 "parse-gram.y"
+#line 367 "parse-gram.y"
     { muscle_code_grow ("union_name", (yyvsp[0].uniqstr), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2218 "../../src/parse-gram.c"
+#line 2217 "../../src/parse-gram.c"
     break;
 
-  case 46:
+  case 45:
 /* Line 1380 of yacc.c  */
-#line 375 "parse-gram.y"
+#line 372 "parse-gram.y"
     {
       union_seen = true;
       muscle_code_grow ("stype", (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
 /* Line 1380 of yacc.c  */
-#line 2230 "../../src/parse-gram.c"
+#line 2229 "../../src/parse-gram.c"
     break;
 
-  case 47:
+  case 46:
 /* Line 1380 of yacc.c  */
-#line 386 "parse-gram.y"
+#line 383 "parse-gram.y"
     { current_class = nterm_sym; }
 /* Line 1380 of yacc.c  */
-#line 2238 "../../src/parse-gram.c"
+#line 2237 "../../src/parse-gram.c"
     break;
 
-  case 48:
+  case 47:
 /* Line 1380 of yacc.c  */
-#line 387 "parse-gram.y"
+#line 384 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
 /* Line 1380 of yacc.c  */
-#line 2249 "../../src/parse-gram.c"
+#line 2248 "../../src/parse-gram.c"
     break;
 
-  case 49:
+  case 48:
 /* Line 1380 of yacc.c  */
-#line 391 "parse-gram.y"
+#line 388 "parse-gram.y"
     { current_class = token_sym; }
 /* Line 1380 of yacc.c  */
-#line 2257 "../../src/parse-gram.c"
+#line 2256 "../../src/parse-gram.c"
     break;
 
-  case 50:
+  case 49:
 /* Line 1380 of yacc.c  */
-#line 392 "parse-gram.y"
+#line 389 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
 /* Line 1380 of yacc.c  */
-#line 2268 "../../src/parse-gram.c"
+#line 2267 "../../src/parse-gram.c"
     break;
 
-  case 51:
+  case 50:
 /* Line 1380 of yacc.c  */
-#line 397 "parse-gram.y"
+#line 394 "parse-gram.y"
     {
       symbol_list *list;
       tag_seen = true;
@@ -2278,12 +2277,12 @@ yyreduce:
       symbol_list_free ((yyvsp[0].list));
     }
 /* Line 1380 of yacc.c  */
-#line 2282 "../../src/parse-gram.c"
+#line 2281 "../../src/parse-gram.c"
     break;
 
-  case 52:
+  case 51:
 /* Line 1380 of yacc.c  */
-#line 408 "parse-gram.y"
+#line 405 "parse-gram.y"
     {
       symbol_list *list;
       ++current_prec;
@@ -2296,202 +2295,202 @@ yyreduce:
       current_type = NULL;
     }
 /* Line 1380 of yacc.c  */
-#line 2300 "../../src/parse-gram.c"
+#line 2299 "../../src/parse-gram.c"
     break;
 
-  case 53:
+  case 52:
 /* Line 1380 of yacc.c  */
-#line 422 "parse-gram.y"
+#line 419 "parse-gram.y"
     { (yyval.assoc) = left_assoc; }
 /* Line 1380 of yacc.c  */
-#line 2308 "../../src/parse-gram.c"
+#line 2307 "../../src/parse-gram.c"
     break;
 
-  case 54:
+  case 53:
 /* Line 1380 of yacc.c  */
-#line 423 "parse-gram.y"
+#line 420 "parse-gram.y"
     { (yyval.assoc) = right_assoc; }
 /* Line 1380 of yacc.c  */
-#line 2316 "../../src/parse-gram.c"
+#line 2315 "../../src/parse-gram.c"
     break;
 
-  case 55:
+  case 54:
 /* Line 1380 of yacc.c  */
-#line 424 "parse-gram.y"
+#line 421 "parse-gram.y"
     { (yyval.assoc) = non_assoc; }
 /* Line 1380 of yacc.c  */
-#line 2324 "../../src/parse-gram.c"
+#line 2323 "../../src/parse-gram.c"
     break;
 
-  case 56:
+  case 55:
 /* Line 1380 of yacc.c  */
-#line 425 "parse-gram.y"
+#line 422 "parse-gram.y"
     { (yyval.assoc) = precedence_assoc; }
 /* Line 1380 of yacc.c  */
-#line 2332 "../../src/parse-gram.c"
+#line 2331 "../../src/parse-gram.c"
     break;
 
-  case 57:
+  case 56:
 /* Line 1380 of yacc.c  */
-#line 429 "parse-gram.y"
+#line 426 "parse-gram.y"
     { current_type = NULL; }
 /* Line 1380 of yacc.c  */
-#line 2340 "../../src/parse-gram.c"
+#line 2339 "../../src/parse-gram.c"
     break;
 
-  case 58:
+  case 57:
 /* Line 1380 of yacc.c  */
-#line 430 "parse-gram.y"
+#line 427 "parse-gram.y"
     { current_type = (yyvsp[0].uniqstr); tag_seen = true; }
 /* Line 1380 of yacc.c  */
-#line 2348 "../../src/parse-gram.c"
+#line 2347 "../../src/parse-gram.c"
     break;
 
-  case 59:
+  case 58:
 /* Line 1380 of yacc.c  */
-#line 436 "parse-gram.y"
+#line 433 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2356 "../../src/parse-gram.c"
+#line 2355 "../../src/parse-gram.c"
     break;
 
-  case 60:
+  case 59:
 /* Line 1380 of yacc.c  */
-#line 438 "parse-gram.y"
+#line 435 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
 /* Line 1380 of yacc.c  */
-#line 2364 "../../src/parse-gram.c"
+#line 2363 "../../src/parse-gram.c"
     break;
 
-  case 61:
+  case 60:
 /* Line 1380 of yacc.c  */
-#line 442 "parse-gram.y"
+#line 439 "parse-gram.y"
     { (yyval.symbol) = (yyvsp[0].symbol); }
 /* Line 1380 of yacc.c  */
-#line 2372 "../../src/parse-gram.c"
+#line 2371 "../../src/parse-gram.c"
     break;
 
-  case 62:
+  case 61:
 /* Line 1380 of yacc.c  */
-#line 443 "parse-gram.y"
+#line 440 "parse-gram.y"
     { (yyval.symbol) = (yyvsp[-1].symbol); symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2380 "../../src/parse-gram.c"
+#line 2379 "../../src/parse-gram.c"
     break;
 
-  case 63:
+  case 62:
 /* Line 1380 of yacc.c  */
-#line 449 "parse-gram.y"
+#line 446 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2388 "../../src/parse-gram.c"
+#line 2387 "../../src/parse-gram.c"
     break;
 
-  case 64:
+  case 63:
 /* Line 1380 of yacc.c  */
-#line 451 "parse-gram.y"
+#line 448 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
 /* Line 1380 of yacc.c  */
-#line 2396 "../../src/parse-gram.c"
+#line 2395 "../../src/parse-gram.c"
     break;
 
-  case 65:
+  case 64:
 /* Line 1380 of yacc.c  */
-#line 455 "parse-gram.y"
+#line 452 "parse-gram.y"
     { (yyval.list) = (yyvsp[0].list); }
 /* Line 1380 of yacc.c  */
-#line 2404 "../../src/parse-gram.c"
+#line 2403 "../../src/parse-gram.c"
     break;
 
-  case 66:
+  case 65:
 /* Line 1380 of yacc.c  */
-#line 456 "parse-gram.y"
+#line 453 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), (yyvsp[0].list)); }
 /* Line 1380 of yacc.c  */
-#line 2412 "../../src/parse-gram.c"
+#line 2411 "../../src/parse-gram.c"
     break;
 
-  case 67:
+  case 66:
 /* Line 1380 of yacc.c  */
-#line 460 "parse-gram.y"
+#line 457 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2420 "../../src/parse-gram.c"
+#line 2419 "../../src/parse-gram.c"
     break;
 
-  case 68:
+  case 67:
 /* Line 1380 of yacc.c  */
-#line 461 "parse-gram.y"
+#line 458 "parse-gram.y"
     { (yyval.list) = symbol_list_type_new ((yyvsp[0].uniqstr), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2428 "../../src/parse-gram.c"
+#line 2427 "../../src/parse-gram.c"
     break;
 
-  case 69:
+  case 68:
 /* Line 1380 of yacc.c  */
-#line 462 "parse-gram.y"
+#line 459 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagged_new ((yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2436 "../../src/parse-gram.c"
+#line 2435 "../../src/parse-gram.c"
     break;
 
-  case 70:
+  case 69:
 /* Line 1380 of yacc.c  */
-#line 463 "parse-gram.y"
+#line 460 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagless_new ((yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2444 "../../src/parse-gram.c"
+#line 2443 "../../src/parse-gram.c"
     break;
 
-  case 71:
+  case 70:
 /* Line 1380 of yacc.c  */
-#line 469 "parse-gram.y"
+#line 466 "parse-gram.y"
     {
        current_type = (yyvsp[0].uniqstr);
        tag_seen = true;
      }
 /* Line 1380 of yacc.c  */
-#line 2455 "../../src/parse-gram.c"
+#line 2454 "../../src/parse-gram.c"
     break;
 
-  case 72:
+  case 71:
 /* Line 1380 of yacc.c  */
-#line 474 "parse-gram.y"
+#line 471 "parse-gram.y"
     {
        symbol_class_set ((yyvsp[0].symbol), current_class, (yylsp[0]), true);
        symbol_type_set ((yyvsp[0].symbol), current_type, (yylsp[0]));
      }
 /* Line 1380 of yacc.c  */
-#line 2466 "../../src/parse-gram.c"
+#line 2465 "../../src/parse-gram.c"
     break;
 
-  case 73:
+  case 72:
 /* Line 1380 of yacc.c  */
-#line 479 "parse-gram.y"
+#line 476 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[-1].symbol), current_class, (yylsp[-1]), true);
       symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
       symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0]));
     }
 /* Line 1380 of yacc.c  */
-#line 2478 "../../src/parse-gram.c"
+#line 2477 "../../src/parse-gram.c"
     break;
 
-  case 74:
+  case 73:
 /* Line 1380 of yacc.c  */
-#line 485 "parse-gram.y"
+#line 482 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[-1].symbol), current_class, (yylsp[-1]), true);
       symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
       symbol_make_alias ((yyvsp[-1].symbol), (yyvsp[0].symbol), (yyloc));
     }
 /* Line 1380 of yacc.c  */
-#line 2490 "../../src/parse-gram.c"
+#line 2489 "../../src/parse-gram.c"
     break;
 
-  case 75:
+  case 74:
 /* Line 1380 of yacc.c  */
-#line 491 "parse-gram.y"
+#line 488 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[-2].symbol), current_class, (yylsp[-2]), true);
       symbol_type_set ((yyvsp[-2].symbol), current_type, (yylsp[-2]));
@@ -2499,112 +2498,112 @@ yyreduce:
       symbol_make_alias ((yyvsp[-2].symbol), (yyvsp[0].symbol), (yyloc));
     }
 /* Line 1380 of yacc.c  */
-#line 2503 "../../src/parse-gram.c"
+#line 2502 "../../src/parse-gram.c"
     break;
 
-  case 82:
+  case 81:
 /* Line 1380 of yacc.c  */
-#line 521 "parse-gram.y"
+#line 518 "parse-gram.y"
     {
       yyerrok;
     }
 /* Line 1380 of yacc.c  */
-#line 2513 "../../src/parse-gram.c"
+#line 2512 "../../src/parse-gram.c"
     break;
 
-  case 83:
+  case 82:
 /* Line 1380 of yacc.c  */
-#line 527 "parse-gram.y"
+#line 524 "parse-gram.y"
     { current_lhs = (yyvsp[0].symbol); current_lhs_location = (yylsp[0]); }
 /* Line 1380 of yacc.c  */
-#line 2521 "../../src/parse-gram.c"
+#line 2520 "../../src/parse-gram.c"
     break;
 
-  case 85:
+  case 84:
 /* Line 1380 of yacc.c  */
-#line 531 "parse-gram.y"
+#line 528 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2529 "../../src/parse-gram.c"
+#line 2528 "../../src/parse-gram.c"
     break;
 
-  case 86:
+  case 85:
 /* Line 1380 of yacc.c  */
-#line 532 "parse-gram.y"
+#line 529 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2537 "../../src/parse-gram.c"
+#line 2536 "../../src/parse-gram.c"
     break;
 
-  case 88:
+  case 87:
 /* Line 1380 of yacc.c  */
-#line 538 "parse-gram.y"
+#line 535 "parse-gram.y"
     { grammar_current_rule_begin (current_lhs, current_lhs_location); }
 /* Line 1380 of yacc.c  */
-#line 2545 "../../src/parse-gram.c"
+#line 2544 "../../src/parse-gram.c"
     break;
 
-  case 89:
+  case 88:
 /* Line 1380 of yacc.c  */
-#line 540 "parse-gram.y"
+#line 537 "parse-gram.y"
     { grammar_current_rule_symbol_append ((yyvsp[0].symbol), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2553 "../../src/parse-gram.c"
+#line 2552 "../../src/parse-gram.c"
     break;
 
-  case 90:
+  case 89:
 /* Line 1380 of yacc.c  */
-#line 542 "parse-gram.y"
+#line 539 "parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[0].code), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2561 "../../src/parse-gram.c"
+#line 2560 "../../src/parse-gram.c"
     break;
 
-  case 91:
+  case 90:
 /* Line 1380 of yacc.c  */
-#line 544 "parse-gram.y"
+#line 541 "parse-gram.y"
     { grammar_current_rule_prec_set ((yyvsp[0].symbol), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2569 "../../src/parse-gram.c"
+#line 2568 "../../src/parse-gram.c"
     break;
 
-  case 92:
+  case 91:
 /* Line 1380 of yacc.c  */
-#line 546 "parse-gram.y"
+#line 543 "parse-gram.y"
     { grammar_current_rule_dprec_set ((yyvsp[0].integer), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2577 "../../src/parse-gram.c"
+#line 2576 "../../src/parse-gram.c"
     break;
 
-  case 93:
+  case 92:
 /* Line 1380 of yacc.c  */
-#line 548 "parse-gram.y"
+#line 545 "parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[0].uniqstr), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2585 "../../src/parse-gram.c"
+#line 2584 "../../src/parse-gram.c"
     break;
 
-  case 95:
+  case 94:
 /* Line 1380 of yacc.c  */
-#line 558 "parse-gram.y"
+#line 555 "parse-gram.y"
     { (yyval.uniqstr) = uniqstr_new ((yyvsp[0].chars)); }
 /* Line 1380 of yacc.c  */
-#line 2593 "../../src/parse-gram.c"
+#line 2592 "../../src/parse-gram.c"
     break;
 
-  case 96:
+  case 95:
 /* Line 1380 of yacc.c  */
-#line 564 "parse-gram.y"
+#line 561 "parse-gram.y"
     {
       (yyval.chars) = "";
     }
 /* Line 1380 of yacc.c  */
-#line 2603 "../../src/parse-gram.c"
+#line 2602 "../../src/parse-gram.c"
     break;
 
-  case 98:
+  case 97:
 /* Line 1380 of yacc.c  */
-#line 577 "parse-gram.y"
+#line 574 "parse-gram.y"
     {
       code_props plain_code;
       (yyvsp[0].code)[strlen ((yyvsp[0].code)) - 1] = '\n';
@@ -2614,51 +2613,51 @@ yyreduce:
       (yyval.chars) = plain_code.code;
     }
 /* Line 1380 of yacc.c  */
-#line 2618 "../../src/parse-gram.c"
+#line 2617 "../../src/parse-gram.c"
     break;
 
-  case 99:
+  case 98:
 /* Line 1380 of yacc.c  */
-#line 597 "parse-gram.y"
+#line 594 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2626 "../../src/parse-gram.c"
+#line 2625 "../../src/parse-gram.c"
     break;
 
-  case 100:
+  case 99:
 /* Line 1380 of yacc.c  */
-#line 599 "parse-gram.y"
+#line 596 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[0].character)), (yylsp[0]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
       symbol_user_token_number_set ((yyval.symbol), (yyvsp[0].character), (yylsp[0]));
     }
 /* Line 1380 of yacc.c  */
-#line 2638 "../../src/parse-gram.c"
+#line 2637 "../../src/parse-gram.c"
     break;
 
-  case 101:
+  case 100:
 /* Line 1380 of yacc.c  */
-#line 607 "parse-gram.y"
+#line 604 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2646 "../../src/parse-gram.c"
+#line 2645 "../../src/parse-gram.c"
     break;
 
-  case 104:
+  case 103:
 /* Line 1380 of yacc.c  */
-#line 619 "parse-gram.y"
+#line 616 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[0].chars)), (yylsp[0]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
     }
 /* Line 1380 of yacc.c  */
-#line 2657 "../../src/parse-gram.c"
+#line 2656 "../../src/parse-gram.c"
     break;
 
-  case 106:
+  case 105:
 /* Line 1380 of yacc.c  */
-#line 628 "parse-gram.y"
+#line 625 "parse-gram.y"
     {
       code_props plain_code;
       code_props_plain_init (&plain_code, (yyvsp[0].chars), (yylsp[0]));
@@ -2668,12 +2667,12 @@ yyreduce:
       code_scanner_last_string_free ();
     }
 /* Line 1380 of yacc.c  */
-#line 2672 "../../src/parse-gram.c"
+#line 2671 "../../src/parse-gram.c"
     break;
 
 
 /* Line 1380 of yacc.c  */
-#line 2677 "../../src/parse-gram.c"
+#line 2676 "../../src/parse-gram.c"
       default: break;
     }
   YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);
@@ -2890,7 +2889,7 @@ yyreturn:
 }
 
 /* Line 1599 of yacc.c  */
-#line 638 "parse-gram.y"
+#line 635 "parse-gram.y"
 
 
 
