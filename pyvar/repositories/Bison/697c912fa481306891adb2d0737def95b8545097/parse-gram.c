@@ -559,9 +559,9 @@ union yyalloc
 /* YYNNTS -- Number of nonterminals.  */
 #define YYNNTS  33
 /* YYNRULES -- Number of rules.  */
-#define YYNRULES  105
+#define YYNRULES  104
 /* YYNSTATES -- Number of states.  */
-#define YYNSTATES  143
+#define YYNSTATES  142
 
 /* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
    by yylex, with out-of-bounds checking.  */
@@ -615,15 +615,15 @@ static const yytype_uint16 yyrline[] =
 {
        0,   204,   204,   212,   214,   218,   219,   229,   233,   237,
      238,   243,   244,   245,   246,   247,   252,   261,   262,   263,
-     264,   265,   266,   267,   268,   269,   270,   271,   284,   285,
-     309,   310,   311,   312,   316,   317,   318,   322,   329,   336,
-     340,   344,   351,   366,   367,   371,   383,   383,   388,   388,
-     393,   404,   419,   420,   421,   422,   426,   427,   432,   434,
-     439,   440,   445,   447,   452,   453,   457,   458,   459,   460,
-     465,   470,   475,   481,   487,   498,   499,   508,   509,   515,
-     516,   517,   524,   524,   528,   529,   530,   535,   536,   538,
-     540,   542,   544,   554,   555,   561,   564,   573,   593,   595,
-     604,   609,   610,   615,   622,   624
+     264,   265,   266,   267,   268,   269,   270,   271,   272,   296,
+     297,   298,   299,   303,   304,   305,   309,   316,   323,   327,
+     331,   338,   353,   354,   358,   370,   370,   375,   375,   380,
+     391,   406,   407,   408,   409,   413,   414,   419,   421,   426,
+     427,   432,   434,   439,   440,   444,   445,   446,   447,   452,
+     457,   462,   468,   474,   485,   486,   495,   496,   502,   503,
+     504,   511,   511,   515,   516,   517,   522,   523,   525,   527,
+     529,   531,   541,   542,   548,   551,   560,   580,   582,   591,
+     596,   597,   602,   609,   611
 };
 #endif
 
@@ -671,29 +671,29 @@ static const yytype_uint16 yytoknum[] =
 };
 # endif
 
-#define YYPACT_NINF -82
+#define YYPACT_NINF -81
 
-#define YYTABLE_NINF -105
+#define YYTABLE_NINF -104
 
   /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
      STATE-NUM.    */
 static const yytype_int16 yypact[] =
 {
-     -82,    21,   111,   -82,   -82,   -82,   -14,    -8,     3,   -82,
-     -82,   -82,   -82,   -18,   -82,    14,    41,    42,    49,   -82,
-       2,   -82,    10,    53,    34,   -82,    13,   -82,   -82,   -82,
-      26,    35,   -82,    54,    78,     0,   -82,   -82,   -82,    58,
-     -82,   -82,    36,   -82,   -82,   -82,   -82,    28,   -23,   -23,
-       0,    32,    32,   -82,    45,   -82,   -82,   -82,    82,   -82,
-     -82,   -82,   -82,    88,   -82,   -82,   -82,   -82,    89,   -82,
-      91,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,
-      43,   -82,    44,     1,   -82,   -82,   -82,   -82,    45,   -82,
-       0,   -82,   -82,   -23,    39,   -23,     0,   -82,   -82,   -82,
-     -82,    32,   -82,   -82,    32,   -82,   -82,   -82,   -82,   -82,
-     -82,   -82,   -82,    55,   -82,   -82,   -82,   -82,     0,   -82,
-      96,   -82,    92,   -82,   -82,   -82,   -82,   -19,   155,   -82,
-     -82,   -82,   -82,   -82,     0,    98,    51,   -82,   -82,   155,
-     -82,   -82,   -82
+     -81,    21,   111,   -81,   -81,   -81,   -14,    -8,     3,   -81,
+     -81,   -81,   -81,   -18,   -81,    14,    41,    42,    49,   -81,
+       2,   -81,    10,    53,    34,   -81,    13,   -81,   -81,   -81,
+      26,    35,    54,    78,     0,   -81,   -81,   -81,    58,   -81,
+     -81,    36,   -81,   -81,   -81,   -81,    28,   -23,   -23,     0,
+      32,    32,   -81,    45,   -81,   -81,   -81,    82,   -81,   -81,
+     -81,   -81,    88,   -81,   -81,   -81,   -81,    89,   -81,    91,
+     -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,    43,
+     -81,    44,     1,   -81,   -81,   -81,   -81,    45,   -81,     0,
+     -81,   -81,   -23,    39,   -23,     0,   -81,   -81,   -81,   -81,
+      32,   -81,   -81,    32,   -81,   -81,   -81,   -81,   -81,   -81,
+     -81,   -81,    55,   -81,   -81,   -81,   -81,     0,   -81,    96,
+     -81,    92,   -81,   -81,   -81,   -81,   -19,   155,   -81,   -81,
+     -81,   -81,   -81,     0,    98,    51,   -81,   -81,   155,   -81,
+     -81,   -81
 };
 
   /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
@@ -701,39 +701,39 @@ static const yytype_int16 yypact[] =
      error.    */
 static const yytype_uint8 yydefact[] =
 {
-       3,     0,     0,     1,    48,    46,     0,     0,     0,    52,
-      53,    54,    55,     0,    39,     0,     9,     0,     0,     7,
-       0,    15,     0,     0,     0,    19,     0,    40,    22,    23,
-       0,     0,    27,     0,     0,     0,    30,    31,    32,     0,
-       6,    33,    43,     4,     5,    35,    34,    56,     0,     0,
-       0,     0,     0,    97,     0,    41,    94,    93,    95,    10,
-      11,    12,    13,     0,    16,    17,    18,    20,     0,    24,
-       0,    26,    28,    29,   103,    99,    98,   101,    36,   102,
-       0,   100,     0,     0,    77,    79,    82,    44,     0,    57,
-       0,    70,    75,    49,    71,    47,    50,    62,    67,    68,
-      69,    37,    64,    66,    38,    42,    96,     8,    14,    21,
-      25,    81,    80,     0,    78,     2,    87,    45,    51,    58,
-      60,    76,    72,    73,    63,    65,   105,    83,    84,    59,
-      61,    74,    87,    86,     0,     0,     0,    89,    88,    85,
-      90,    91,    92
+       3,     0,     0,     1,    47,    45,     0,     0,     0,    51,
+      52,    53,    54,     0,    38,     0,     9,     0,     0,     7,
+       0,    15,     0,     0,     0,    19,     0,    39,    22,    23,
+       0,     0,     0,     0,     0,    29,    30,    31,     0,     6,
+      32,    42,     4,     5,    34,    33,    55,     0,     0,     0,
+       0,     0,    96,     0,    40,    93,    92,    94,    10,    11,
+      12,    13,     0,    16,    17,    18,    20,     0,    24,     0,
+      26,    27,    28,   102,    98,    97,   100,    35,   101,     0,
+      99,     0,     0,    76,    78,    81,    43,     0,    56,     0,
+      69,    74,    48,    70,    46,    49,    61,    66,    67,    68,
+      36,    63,    65,    37,    41,    95,     8,    14,    21,    25,
+      80,    79,     0,    77,     2,    86,    44,    50,    57,    59,
+      75,    71,    72,    62,    64,   104,    82,    83,    58,    60,
+      73,    86,    85,     0,     0,     0,    88,    87,    84,    89,
+      90,    91
 };
 
   /* YYPGOTO[NTERM-NUM].    */
 static const yytype_int8 yypgoto[] =
 {
-     -82,   -82,   -82,   -82,   101,   -82,   -82,   -82,   -82,   -82,
-     -82,   -82,   -82,   -12,   -82,    56,   -81,   -56,    60,   -82,
-      27,   -82,   -82,   -82,   -20,   -82,   -82,   -50,   -21,   -82,
-     -35,   -70,   -82
+     -81,   -81,   -81,   -81,   101,   -81,   -81,   -81,   -81,   -81,
+     -81,   -81,   -81,   -11,   -81,    57,   -80,   -55,    61,   -81,
+      29,   -81,   -81,   -81,   -21,   -81,   -81,   -49,   -20,   -81,
+     -34,   -69,   -81
 };
 
   /* YYDEFGOTO[NTERM-NUM].    */
-static const yytype_int16 yydefgoto[] =
+static const yytype_int8 yydefgoto[] =
 {
-      -1,     1,     2,    43,    82,    88,    45,    49,    48,    46,
-      47,    90,   118,   119,    96,   101,   102,    92,    93,    83,
-      84,    85,   116,   127,   128,    58,   107,    55,    77,    86,
-     103,    79,   115
+      -1,     1,     2,    42,    81,    87,    44,    48,    47,    45,
+      46,    89,   117,   118,    95,   100,   101,    91,    92,    82,
+      83,    84,   115,   126,   127,    57,   106,    54,    76,    85,
+     102,    78,   114
 };
 
   /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
@@ -742,46 +742,46 @@ static const yytype_int16 yydefgoto[] =
      If YYTABLE_NINF, syntax error.    */
 static const yytype_int16 yytable[] =
 {
-      78,  -104,    80,    74,   105,    62,     4,     5,     6,     7,
-       8,     9,    10,    11,    12,    97,    67,    56,    13,    14,
-     125,     3,    75,   125,   123,    76,    53,    94,    94,    69,
-      54,    91,   132,    27,   133,    74,    51,   121,   117,   121,
-      50,    35,    74,   122,    59,    75,    60,    52,    76,    63,
-      81,   113,   131,    61,    64,   120,    65,    72,    42,    80,
-      68,   124,    57,     4,     5,     6,     7,     8,     9,    10,
-      11,    12,    94,    70,    94,    13,    14,    75,    66,    71,
-      76,    73,    89,   120,    87,   106,    98,    99,   100,    53,
-      27,   108,   109,   138,   110,    74,   111,   112,    35,   140,
-     130,   126,   141,    44,   138,   142,   129,    81,   104,    95,
-     114,     0,   139,     0,     0,    42,     4,     5,     6,     7,
+      77,  -103,    79,    73,   104,    61,     4,     5,     6,     7,
+       8,     9,    10,    11,    12,    96,    66,    55,    13,    14,
+     124,     3,    74,   124,   122,    75,    52,    93,    93,    68,
+      53,    90,   131,    27,   132,    73,    50,   120,   116,   120,
+      49,    34,    73,   121,    58,    74,    59,    51,    75,    62,
+      80,   112,   130,    60,    63,   119,    64,    71,    41,    79,
+      67,   123,    56,     4,     5,     6,     7,     8,     9,    10,
+      11,    12,    93,    69,    93,    13,    14,    74,    65,    70,
+      75,    72,    88,   119,    86,   105,    97,    98,    99,    52,
+      27,   107,   108,   137,   109,    73,   110,   111,    34,   139,
+     129,   125,   140,    43,   137,   141,   128,    80,   103,    94,
+     138,   113,     0,     0,     0,    41,     4,     5,     6,     7,
        8,     9,    10,    11,    12,     0,     0,     0,    13,    14,
       15,    16,     0,    17,    18,    19,    20,    21,    22,    23,
-      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
-      34,    35,    36,    37,    38,     0,     0,     0,    74,     0,
-       0,    39,     0,    40,    41,     0,     0,     0,    42,   134,
-     135,   136,     0,     0,     0,     0,     0,     0,     0,     0,
+      24,    25,    26,    27,    28,    29,    30,    31,     0,    32,
+      33,    34,    35,    36,    37,     0,     0,     0,    73,     0,
+       0,    38,     0,    39,    40,     0,     0,     0,    41,   133,
+     134,   135,     0,     0,     0,     0,     0,     0,     0,     0,
        0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
-       0,     0,     0,     0,     0,     0,     0,     0,     0,   137,
-      75,     0,     0,    76
+       0,     0,     0,     0,     0,     0,     0,     0,     0,   136,
+      74,     0,     0,    75
 };
 
 static const yytype_int16 yycheck[] =
 {
-      35,     0,     1,     3,    54,     3,     5,     6,     7,     8,
-       9,    10,    11,    12,    13,    50,     3,     3,    17,    18,
-     101,     0,    45,   104,    94,    48,    44,    48,    49,     3,
-      48,    54,    51,    32,    53,     3,    44,    93,    88,    95,
+      34,     0,     1,     3,    53,     3,     5,     6,     7,     8,
+       9,    10,    11,    12,    13,    49,     3,     3,    17,    18,
+     100,     0,    45,   103,    93,    48,    44,    47,    48,     3,
+      48,    54,    51,    32,    53,     3,    44,    92,    87,    94,
       54,    40,     3,     4,     3,    45,     4,    44,    48,    47,
-      49,    50,   122,     4,    44,    90,     3,     3,    57,     1,
-      47,    96,    48,     5,     6,     7,     8,     9,    10,    11,
-      12,    13,    93,    47,    95,    17,    18,    45,    44,    44,
-      48,     3,    54,   118,    48,     3,    54,    55,    56,    44,
-      32,     3,     3,   128,     3,     3,    53,    53,    40,   134,
-       4,    46,     4,     2,   139,    54,   118,    49,    52,    49,
-      83,    -1,   132,    -1,    -1,    57,     5,     6,     7,     8,
+      49,    50,   121,     4,    44,    89,     3,     3,    57,     1,
+      47,    95,    48,     5,     6,     7,     8,     9,    10,    11,
+      12,    13,    92,    47,    94,    17,    18,    45,    44,    44,
+      48,     3,    54,   117,    48,     3,    54,    55,    56,    44,
+      32,     3,     3,   127,     3,     3,    53,    53,    40,   133,
+       4,    46,     4,     2,   138,    54,   117,    49,    51,    48,
+     131,    82,    -1,    -1,    -1,    57,     5,     6,     7,     8,
        9,    10,    11,    12,    13,    -1,    -1,    -1,    17,    18,
       19,    20,    -1,    22,    23,    24,    25,    26,    27,    28,
-      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
+      29,    30,    31,    32,    33,    34,    35,    36,    -1,    38,
       39,    40,    41,    42,    43,    -1,    -1,    -1,     3,    -1,
       -1,    50,    -1,    52,    53,    -1,    -1,    -1,    57,    14,
       15,    16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
@@ -797,18 +797,18 @@ static const yytype_uint8 yystos[] =
        0,    59,    60,     0,     5,     6,     7,     8,     9,    10,
       11,    12,    13,    17,    18,    19,    20,    22,    23,    24,
       25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
-      35,    36,    37,    38,    39,    40,    41,    42,    43,    50,
-      52,    53,    57,    61,    62,    64,    67,    68,    66,    65,
-      54,    44,    44,    44,    48,    85,     3,    48,    83,     3,
-       4,     4,     3,    47,    44,     3,    44,     3,    47,     3,
-      47,    44,     3,     3,     3,    45,    48,    86,    88,    89,
-       1,    49,    62,    77,    78,    79,    87,    48,    63,    54,
-      69,    54,    75,    76,    86,    76,    72,    88,    54,    55,
-      56,    73,    74,    88,    73,    85,     3,    84,     3,     3,
-       3,    53,    53,    50,    78,    90,    80,    85,    70,    71,
-      88,    75,     4,    89,    88,    74,    46,    81,    82,    71,
-       4,    89,    51,    53,    14,    15,    16,    44,    88,    82,
-      88,     4,    54
+      35,    36,    38,    39,    40,    41,    42,    43,    50,    52,
+      53,    57,    61,    62,    64,    67,    68,    66,    65,    54,
+      44,    44,    44,    48,    85,     3,    48,    83,     3,     4,
+       4,     3,    47,    44,     3,    44,     3,    47,     3,    47,
+      44,     3,     3,     3,    45,    48,    86,    88,    89,     1,
+      49,    62,    77,    78,    79,    87,    48,    63,    54,    69,
+      54,    75,    76,    86,    76,    72,    88,    54,    55,    56,
+      73,    74,    88,    73,    85,     3,    84,     3,     3,     3,
+      53,    53,    50,    78,    90,    80,    85,    70,    71,    88,
+      75,     4,    89,    88,    74,    46,    81,    82,    71,     4,
+      89,    51,    53,    14,    15,    16,    44,    88,    82,    88,
+       4,    54
 };
 
   /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.    */
@@ -817,14 +817,14 @@ static const yytype_uint8 yyr1[] =
        0,    58,    59,    60,    60,    61,    61,    61,    61,    61,
       61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
       61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
-      61,    61,    61,    61,    62,    62,    62,    62,    62,    62,
-      62,    62,    62,    63,    63,    62,    65,    64,    66,    64,
-      64,    67,    68,    68,    68,    68,    69,    69,    70,    70,
-      71,    71,    72,    72,    73,    73,    74,    74,    74,    74,
-      75,    75,    75,    75,    75,    76,    76,    77,    77,    78,
-      78,    78,    80,    79,    81,    81,    81,    82,    82,    82,
-      82,    82,    82,    83,    83,    84,    84,    85,    86,    86,
-      87,    88,    88,    89,    90,    90
+      61,    61,    61,    62,    62,    62,    62,    62,    62,    62,
+      62,    62,    63,    63,    62,    65,    64,    66,    64,    64,
+      67,    68,    68,    68,    68,    69,    69,    70,    70,    71,
+      71,    72,    72,    73,    73,    74,    74,    74,    74,    75,
+      75,    75,    75,    75,    76,    76,    77,    77,    78,    78,
+      78,    80,    79,    81,    81,    81,    82,    82,    82,    82,
+      82,    82,    83,    83,    84,    84,    85,    86,    86,    87,
+      88,    88,    89,    90,    90
 };
 
   /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.    */
@@ -832,15 +832,15 @@ static const yytype_uint8 yyr2[] =
 {
        0,     2,     4,     0,     2,     1,     1,     1,     3,     1,
        2,     2,     2,     2,     3,     1,     2,     2,     2,     1,
-       2,     3,     1,     1,     2,     3,     2,     1,     2,     2,
-       1,     1,     1,     1,     1,     1,     2,     3,     3,     1,
-       1,     2,     3,     0,     1,     3,     0,     3,     0,     3,
-       3,     3,     1,     1,     1,     1,     0,     1,     1,     2,
-       1,     2,     1,     2,     1,     2,     1,     1,     1,     1,
-       1,     1,     2,     2,     3,     1,     2,     1,     2,     1,
-       2,     2,     0,     3,     1,     3,     2,     0,     2,     2,
-       3,     3,     3,     1,     1,     0,     1,     1,     1,     1,
-       1,     1,     1,     1,     0,     2
+       2,     3,     1,     1,     2,     3,     2,     2,     2,     1,
+       1,     1,     1,     1,     1,     2,     3,     3,     1,     1,
+       2,     3,     0,     1,     3,     0,     3,     0,     3,     3,
+       3,     1,     1,     1,     1,     0,     1,     1,     2,     1,
+       2,     1,     2,     1,     2,     1,     1,     1,     1,     1,
+       1,     2,     2,     3,     1,     2,     1,     2,     1,     2,
+       2,     0,     3,     1,     3,     2,     0,     2,     2,     3,
+       3,     3,     1,     1,     0,     1,     1,     1,     1,     1,
+       1,     1,     1,     0,     2
 };
 
 
@@ -1866,7 +1866,7 @@ yyreduce:
 /* Line 1380 of yacc.c  */
 #line 230 "parse-gram.y"
     {
-      muscle_percent_define_insert ((yyvsp[0].uniqstr), (yylsp[0]), "");
+      muscle_percent_define_ensure ((yyvsp[0].uniqstr), (yylsp[0]), true);
     }
 /* Line 1380 of yacc.c  */
 #line 1873 "../../src/parse-gram.c"
@@ -2041,34 +2041,15 @@ yyreduce:
 
   case 27:
 /* Line 1380 of yacc.c  */
-#line 272 "parse-gram.y"
-    {
-      /* %pure-parser is deprecated in favor of `%define api.pure', so use
-         `%define api.pure' in a backward-compatible manner here.  First, don't
-         complain if %pure-parser is specified multiple times.  */
-      if (!muscle_find_const ("percent_define(api.pure)"))
-        muscle_percent_define_insert ("api.pure", (yylsp[0]), "");
-      /* In all cases, use api.pure now so that the backend doesn't complain if
-         the skeleton ignores api.pure, but do warn now if there's a previous
-         conflicting definition from an actual %define.  */
-      if (!muscle_percent_define_flag_if ("api.pure"))
-        muscle_percent_define_insert ("api.pure", (yylsp[0]), "");
-    }
-/* Line 1380 of yacc.c  */
-#line 2059 "../../src/parse-gram.c"
-    break;
-
-  case 28:
-/* Line 1380 of yacc.c  */
-#line 284 "parse-gram.y"
+#line 271 "parse-gram.y"
     { version_check (&(yylsp[0]), (yyvsp[0].chars)); }
 /* Line 1380 of yacc.c  */
-#line 2067 "../../src/parse-gram.c"
+#line 2048 "../../src/parse-gram.c"
     break;
 
-  case 29:
+  case 28:
 /* Line 1380 of yacc.c  */
-#line 286 "parse-gram.y"
+#line 273 "parse-gram.y"
     {
       char const *skeleton_user = (yyvsp[0].chars);
       if (strchr (skeleton_user, '/'))
@@ -2093,46 +2074,46 @@ yyreduce:
       skeleton_arg (skeleton_user, grammar_prio, (yylsp[-1]));
     }
 /* Line 1380 of yacc.c  */
-#line 2097 "../../src/parse-gram.c"
+#line 2078 "../../src/parse-gram.c"
     break;
 
-  case 30:
+  case 29:
 /* Line 1380 of yacc.c  */
-#line 309 "parse-gram.y"
+#line 296 "parse-gram.y"
     { token_table_flag = true; }
 /* Line 1380 of yacc.c  */
-#line 2105 "../../src/parse-gram.c"
+#line 2086 "../../src/parse-gram.c"
     break;
 
-  case 31:
+  case 30:
 /* Line 1380 of yacc.c  */
-#line 310 "parse-gram.y"
+#line 297 "parse-gram.y"
     { report_flag |= report_states; }
 /* Line 1380 of yacc.c  */
-#line 2113 "../../src/parse-gram.c"
+#line 2094 "../../src/parse-gram.c"
     break;
 
-  case 32:
+  case 31:
 /* Line 1380 of yacc.c  */
-#line 311 "parse-gram.y"
+#line 298 "parse-gram.y"
     { yacc_flag = true; }
 /* Line 1380 of yacc.c  */
-#line 2121 "../../src/parse-gram.c"
+#line 2102 "../../src/parse-gram.c"
     break;
 
-  case 36:
+  case 35:
 /* Line 1380 of yacc.c  */
-#line 319 "parse-gram.y"
+#line 306 "parse-gram.y"
     {
       grammar_start_symbol_set ((yyvsp[0].symbol), (yylsp[0]));
     }
 /* Line 1380 of yacc.c  */
-#line 2131 "../../src/parse-gram.c"
+#line 2112 "../../src/parse-gram.c"
     break;
 
-  case 37:
+  case 36:
 /* Line 1380 of yacc.c  */
-#line 323 "parse-gram.y"
+#line 310 "parse-gram.y"
     {
       symbol_list *list;
       for (list = (yyvsp[0].list); list; list = list->next)
@@ -2140,12 +2121,12 @@ yyreduce:
       symbol_list_free ((yyvsp[0].list));
     }
 /* Line 1380 of yacc.c  */
-#line 2144 "../../src/parse-gram.c"
+#line 2125 "../../src/parse-gram.c"
     break;
 
-  case 38:
+  case 37:
 /* Line 1380 of yacc.c  */
-#line 330 "parse-gram.y"
+#line 317 "parse-gram.y"
     {
       symbol_list *list;
       for (list = (yyvsp[0].list); list; list = list->next)
@@ -2153,32 +2134,32 @@ yyreduce:
       symbol_list_free ((yyvsp[0].list));
     }
 /* Line 1380 of yacc.c  */
-#line 2157 "../../src/parse-gram.c"
+#line 2138 "../../src/parse-gram.c"
     break;
 
-  case 39:
+  case 38:
 /* Line 1380 of yacc.c  */
-#line 337 "parse-gram.y"
+#line 324 "parse-gram.y"
     {
       default_prec = true;
     }
 /* Line 1380 of yacc.c  */
-#line 2167 "../../src/parse-gram.c"
+#line 2148 "../../src/parse-gram.c"
     break;
 
-  case 40:
+  case 39:
 /* Line 1380 of yacc.c  */
-#line 341 "parse-gram.y"
+#line 328 "parse-gram.y"
     {
       default_prec = false;
     }
 /* Line 1380 of yacc.c  */
-#line 2177 "../../src/parse-gram.c"
+#line 2158 "../../src/parse-gram.c"
     break;
 
-  case 41:
+  case 40:
 /* Line 1380 of yacc.c  */
-#line 345 "parse-gram.y"
+#line 332 "parse-gram.y"
     {
       /* Do not invoke muscle_percent_code_grow here since it invokes
          muscle_user_name_list_grow.  */
@@ -2186,89 +2167,89 @@ yyreduce:
       code_scanner_last_string_free ();
     }
 /* Line 1380 of yacc.c  */
-#line 2190 "../../src/parse-gram.c"
+#line 2171 "../../src/parse-gram.c"
     break;
 
-  case 42:
+  case 41:
 /* Line 1380 of yacc.c  */
-#line 352 "parse-gram.y"
+#line 339 "parse-gram.y"
     {
       muscle_percent_code_grow ((yyvsp[-1].uniqstr), (yylsp[-1]), (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
 /* Line 1380 of yacc.c  */
-#line 2201 "../../src/parse-gram.c"
+#line 2182 "../../src/parse-gram.c"
     break;
 
-  case 43:
+  case 42:
 /* Line 1380 of yacc.c  */
-#line 366 "parse-gram.y"
+#line 353 "parse-gram.y"
     {}
 /* Line 1380 of yacc.c  */
-#line 2209 "../../src/parse-gram.c"
+#line 2190 "../../src/parse-gram.c"
     break;
 
-  case 44:
+  case 43:
 /* Line 1380 of yacc.c  */
-#line 367 "parse-gram.y"
+#line 354 "parse-gram.y"
     { muscle_code_grow ("union_name", (yyvsp[0].uniqstr), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2217 "../../src/parse-gram.c"
+#line 2198 "../../src/parse-gram.c"
     break;
 
-  case 45:
+  case 44:
 /* Line 1380 of yacc.c  */
-#line 372 "parse-gram.y"
+#line 359 "parse-gram.y"
     {
       union_seen = true;
       muscle_code_grow ("stype", (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
 /* Line 1380 of yacc.c  */
-#line 2229 "../../src/parse-gram.c"
+#line 2210 "../../src/parse-gram.c"
     break;
 
-  case 46:
+  case 45:
 /* Line 1380 of yacc.c  */
-#line 383 "parse-gram.y"
+#line 370 "parse-gram.y"
     { current_class = nterm_sym; }
 /* Line 1380 of yacc.c  */
-#line 2237 "../../src/parse-gram.c"
+#line 2218 "../../src/parse-gram.c"
     break;
 
-  case 47:
+  case 46:
 /* Line 1380 of yacc.c  */
-#line 384 "parse-gram.y"
+#line 371 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
 /* Line 1380 of yacc.c  */
-#line 2248 "../../src/parse-gram.c"
+#line 2229 "../../src/parse-gram.c"
     break;
 
-  case 48:
+  case 47:
 /* Line 1380 of yacc.c  */
-#line 388 "parse-gram.y"
+#line 375 "parse-gram.y"
     { current_class = token_sym; }
 /* Line 1380 of yacc.c  */
-#line 2256 "../../src/parse-gram.c"
+#line 2237 "../../src/parse-gram.c"
     break;
 
-  case 49:
+  case 48:
 /* Line 1380 of yacc.c  */
-#line 389 "parse-gram.y"
+#line 376 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
 /* Line 1380 of yacc.c  */
-#line 2267 "../../src/parse-gram.c"
+#line 2248 "../../src/parse-gram.c"
     break;
 
-  case 50:
+  case 49:
 /* Line 1380 of yacc.c  */
-#line 394 "parse-gram.y"
+#line 381 "parse-gram.y"
     {
       symbol_list *list;
       tag_seen = true;
@@ -2277,12 +2258,12 @@ yyreduce:
       symbol_list_free ((yyvsp[0].list));
     }
 /* Line 1380 of yacc.c  */
-#line 2281 "../../src/parse-gram.c"
+#line 2262 "../../src/parse-gram.c"
     break;
 
-  case 51:
+  case 50:
 /* Line 1380 of yacc.c  */
-#line 405 "parse-gram.y"
+#line 392 "parse-gram.y"
     {
       symbol_list *list;
       ++current_prec;
@@ -2295,202 +2276,202 @@ yyreduce:
       current_type = NULL;
     }
 /* Line 1380 of yacc.c  */
-#line 2299 "../../src/parse-gram.c"
+#line 2280 "../../src/parse-gram.c"
     break;
 
-  case 52:
+  case 51:
 /* Line 1380 of yacc.c  */
-#line 419 "parse-gram.y"
+#line 406 "parse-gram.y"
     { (yyval.assoc) = left_assoc; }
 /* Line 1380 of yacc.c  */
-#line 2307 "../../src/parse-gram.c"
+#line 2288 "../../src/parse-gram.c"
     break;
 
-  case 53:
+  case 52:
 /* Line 1380 of yacc.c  */
-#line 420 "parse-gram.y"
+#line 407 "parse-gram.y"
     { (yyval.assoc) = right_assoc; }
 /* Line 1380 of yacc.c  */
-#line 2315 "../../src/parse-gram.c"
+#line 2296 "../../src/parse-gram.c"
     break;
 
-  case 54:
+  case 53:
 /* Line 1380 of yacc.c  */
-#line 421 "parse-gram.y"
+#line 408 "parse-gram.y"
     { (yyval.assoc) = non_assoc; }
 /* Line 1380 of yacc.c  */
-#line 2323 "../../src/parse-gram.c"
+#line 2304 "../../src/parse-gram.c"
     break;
 
-  case 55:
+  case 54:
 /* Line 1380 of yacc.c  */
-#line 422 "parse-gram.y"
+#line 409 "parse-gram.y"
     { (yyval.assoc) = precedence_assoc; }
 /* Line 1380 of yacc.c  */
-#line 2331 "../../src/parse-gram.c"
+#line 2312 "../../src/parse-gram.c"
     break;
 
-  case 56:
+  case 55:
 /* Line 1380 of yacc.c  */
-#line 426 "parse-gram.y"
+#line 413 "parse-gram.y"
     { current_type = NULL; }
 /* Line 1380 of yacc.c  */
-#line 2339 "../../src/parse-gram.c"
+#line 2320 "../../src/parse-gram.c"
     break;
 
-  case 57:
+  case 56:
 /* Line 1380 of yacc.c  */
-#line 427 "parse-gram.y"
+#line 414 "parse-gram.y"
     { current_type = (yyvsp[0].uniqstr); tag_seen = true; }
 /* Line 1380 of yacc.c  */
-#line 2347 "../../src/parse-gram.c"
+#line 2328 "../../src/parse-gram.c"
     break;
 
-  case 58:
+  case 57:
 /* Line 1380 of yacc.c  */
-#line 433 "parse-gram.y"
+#line 420 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2355 "../../src/parse-gram.c"
+#line 2336 "../../src/parse-gram.c"
     break;
 
-  case 59:
+  case 58:
 /* Line 1380 of yacc.c  */
-#line 435 "parse-gram.y"
+#line 422 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
 /* Line 1380 of yacc.c  */
-#line 2363 "../../src/parse-gram.c"
+#line 2344 "../../src/parse-gram.c"
     break;
 
-  case 60:
+  case 59:
 /* Line 1380 of yacc.c  */
-#line 439 "parse-gram.y"
+#line 426 "parse-gram.y"
     { (yyval.symbol) = (yyvsp[0].symbol); }
 /* Line 1380 of yacc.c  */
-#line 2371 "../../src/parse-gram.c"
+#line 2352 "../../src/parse-gram.c"
     break;
 
-  case 61:
+  case 60:
 /* Line 1380 of yacc.c  */
-#line 440 "parse-gram.y"
+#line 427 "parse-gram.y"
     { (yyval.symbol) = (yyvsp[-1].symbol); symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2379 "../../src/parse-gram.c"
+#line 2360 "../../src/parse-gram.c"
     break;
 
-  case 62:
+  case 61:
 /* Line 1380 of yacc.c  */
-#line 446 "parse-gram.y"
+#line 433 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2387 "../../src/parse-gram.c"
+#line 2368 "../../src/parse-gram.c"
     break;
 
-  case 63:
+  case 62:
 /* Line 1380 of yacc.c  */
-#line 448 "parse-gram.y"
+#line 435 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
 /* Line 1380 of yacc.c  */
-#line 2395 "../../src/parse-gram.c"
+#line 2376 "../../src/parse-gram.c"
     break;
 
-  case 64:
+  case 63:
 /* Line 1380 of yacc.c  */
-#line 452 "parse-gram.y"
+#line 439 "parse-gram.y"
     { (yyval.list) = (yyvsp[0].list); }
 /* Line 1380 of yacc.c  */
-#line 2403 "../../src/parse-gram.c"
+#line 2384 "../../src/parse-gram.c"
     break;
 
-  case 65:
+  case 64:
 /* Line 1380 of yacc.c  */
-#line 453 "parse-gram.y"
+#line 440 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), (yyvsp[0].list)); }
 /* Line 1380 of yacc.c  */
-#line 2411 "../../src/parse-gram.c"
+#line 2392 "../../src/parse-gram.c"
     break;
 
-  case 66:
+  case 65:
 /* Line 1380 of yacc.c  */
-#line 457 "parse-gram.y"
+#line 444 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2419 "../../src/parse-gram.c"
+#line 2400 "../../src/parse-gram.c"
     break;
 
-  case 67:
+  case 66:
 /* Line 1380 of yacc.c  */
-#line 458 "parse-gram.y"
+#line 445 "parse-gram.y"
     { (yyval.list) = symbol_list_type_new ((yyvsp[0].uniqstr), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2427 "../../src/parse-gram.c"
+#line 2408 "../../src/parse-gram.c"
     break;
 
-  case 68:
+  case 67:
 /* Line 1380 of yacc.c  */
-#line 459 "parse-gram.y"
+#line 446 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagged_new ((yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2435 "../../src/parse-gram.c"
+#line 2416 "../../src/parse-gram.c"
     break;
 
-  case 69:
+  case 68:
 /* Line 1380 of yacc.c  */
-#line 460 "parse-gram.y"
+#line 447 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagless_new ((yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2443 "../../src/parse-gram.c"
+#line 2424 "../../src/parse-gram.c"
     break;
 
-  case 70:
+  case 69:
 /* Line 1380 of yacc.c  */
-#line 466 "parse-gram.y"
+#line 453 "parse-gram.y"
     {
        current_type = (yyvsp[0].uniqstr);
        tag_seen = true;
      }
 /* Line 1380 of yacc.c  */
-#line 2454 "../../src/parse-gram.c"
+#line 2435 "../../src/parse-gram.c"
     break;
 
-  case 71:
+  case 70:
 /* Line 1380 of yacc.c  */
-#line 471 "parse-gram.y"
+#line 458 "parse-gram.y"
     {
        symbol_class_set ((yyvsp[0].symbol), current_class, (yylsp[0]), true);
        symbol_type_set ((yyvsp[0].symbol), current_type, (yylsp[0]));
      }
 /* Line 1380 of yacc.c  */
-#line 2465 "../../src/parse-gram.c"
+#line 2446 "../../src/parse-gram.c"
     break;
 
-  case 72:
+  case 71:
 /* Line 1380 of yacc.c  */
-#line 476 "parse-gram.y"
+#line 463 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[-1].symbol), current_class, (yylsp[-1]), true);
       symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
       symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0]));
     }
 /* Line 1380 of yacc.c  */
-#line 2477 "../../src/parse-gram.c"
+#line 2458 "../../src/parse-gram.c"
     break;
 
-  case 73:
+  case 72:
 /* Line 1380 of yacc.c  */
-#line 482 "parse-gram.y"
+#line 469 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[-1].symbol), current_class, (yylsp[-1]), true);
       symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
       symbol_make_alias ((yyvsp[-1].symbol), (yyvsp[0].symbol), (yyloc));
     }
 /* Line 1380 of yacc.c  */
-#line 2489 "../../src/parse-gram.c"
+#line 2470 "../../src/parse-gram.c"
     break;
 
-  case 74:
+  case 73:
 /* Line 1380 of yacc.c  */
-#line 488 "parse-gram.y"
+#line 475 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[-2].symbol), current_class, (yylsp[-2]), true);
       symbol_type_set ((yyvsp[-2].symbol), current_type, (yylsp[-2]));
@@ -2498,112 +2479,112 @@ yyreduce:
       symbol_make_alias ((yyvsp[-2].symbol), (yyvsp[0].symbol), (yyloc));
     }
 /* Line 1380 of yacc.c  */
-#line 2502 "../../src/parse-gram.c"
+#line 2483 "../../src/parse-gram.c"
     break;
 
-  case 81:
+  case 80:
 /* Line 1380 of yacc.c  */
-#line 518 "parse-gram.y"
+#line 505 "parse-gram.y"
     {
       yyerrok;
     }
 /* Line 1380 of yacc.c  */
-#line 2512 "../../src/parse-gram.c"
+#line 2493 "../../src/parse-gram.c"
     break;
 
-  case 82:
+  case 81:
 /* Line 1380 of yacc.c  */
-#line 524 "parse-gram.y"
+#line 511 "parse-gram.y"
     { current_lhs = (yyvsp[0].symbol); current_lhs_location = (yylsp[0]); }
 /* Line 1380 of yacc.c  */
-#line 2520 "../../src/parse-gram.c"
+#line 2501 "../../src/parse-gram.c"
     break;
 
-  case 84:
+  case 83:
 /* Line 1380 of yacc.c  */
-#line 528 "parse-gram.y"
+#line 515 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2528 "../../src/parse-gram.c"
+#line 2509 "../../src/parse-gram.c"
     break;
 
-  case 85:
+  case 84:
 /* Line 1380 of yacc.c  */
-#line 529 "parse-gram.y"
+#line 516 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2536 "../../src/parse-gram.c"
+#line 2517 "../../src/parse-gram.c"
     break;
 
-  case 87:
+  case 86:
 /* Line 1380 of yacc.c  */
-#line 535 "parse-gram.y"
+#line 522 "parse-gram.y"
     { grammar_current_rule_begin (current_lhs, current_lhs_location); }
 /* Line 1380 of yacc.c  */
-#line 2544 "../../src/parse-gram.c"
+#line 2525 "../../src/parse-gram.c"
     break;
 
-  case 88:
+  case 87:
 /* Line 1380 of yacc.c  */
-#line 537 "parse-gram.y"
+#line 524 "parse-gram.y"
     { grammar_current_rule_symbol_append ((yyvsp[0].symbol), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2552 "../../src/parse-gram.c"
+#line 2533 "../../src/parse-gram.c"
     break;
 
-  case 89:
+  case 88:
 /* Line 1380 of yacc.c  */
-#line 539 "parse-gram.y"
+#line 526 "parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[0].code), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2560 "../../src/parse-gram.c"
+#line 2541 "../../src/parse-gram.c"
     break;
 
-  case 90:
+  case 89:
 /* Line 1380 of yacc.c  */
-#line 541 "parse-gram.y"
+#line 528 "parse-gram.y"
     { grammar_current_rule_prec_set ((yyvsp[0].symbol), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2568 "../../src/parse-gram.c"
+#line 2549 "../../src/parse-gram.c"
     break;
 
-  case 91:
+  case 90:
 /* Line 1380 of yacc.c  */
-#line 543 "parse-gram.y"
+#line 530 "parse-gram.y"
     { grammar_current_rule_dprec_set ((yyvsp[0].integer), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2576 "../../src/parse-gram.c"
+#line 2557 "../../src/parse-gram.c"
     break;
 
-  case 92:
+  case 91:
 /* Line 1380 of yacc.c  */
-#line 545 "parse-gram.y"
+#line 532 "parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[0].uniqstr), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2584 "../../src/parse-gram.c"
+#line 2565 "../../src/parse-gram.c"
     break;
 
-  case 94:
+  case 93:
 /* Line 1380 of yacc.c  */
-#line 555 "parse-gram.y"
+#line 542 "parse-gram.y"
     { (yyval.uniqstr) = uniqstr_new ((yyvsp[0].chars)); }
 /* Line 1380 of yacc.c  */
-#line 2592 "../../src/parse-gram.c"
+#line 2573 "../../src/parse-gram.c"
     break;
 
-  case 95:
+  case 94:
 /* Line 1380 of yacc.c  */
-#line 561 "parse-gram.y"
+#line 548 "parse-gram.y"
     {
       (yyval.chars) = "";
     }
 /* Line 1380 of yacc.c  */
-#line 2602 "../../src/parse-gram.c"
+#line 2583 "../../src/parse-gram.c"
     break;
 
-  case 97:
+  case 96:
 /* Line 1380 of yacc.c  */
-#line 574 "parse-gram.y"
+#line 561 "parse-gram.y"
     {
       code_props plain_code;
       (yyvsp[0].code)[strlen ((yyvsp[0].code)) - 1] = '\n';
@@ -2613,51 +2594,51 @@ yyreduce:
       (yyval.chars) = plain_code.code;
     }
 /* Line 1380 of yacc.c  */
-#line 2617 "../../src/parse-gram.c"
+#line 2598 "../../src/parse-gram.c"
     break;
 
-  case 98:
+  case 97:
 /* Line 1380 of yacc.c  */
-#line 594 "parse-gram.y"
+#line 581 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2625 "../../src/parse-gram.c"
+#line 2606 "../../src/parse-gram.c"
     break;
 
-  case 99:
+  case 98:
 /* Line 1380 of yacc.c  */
-#line 596 "parse-gram.y"
+#line 583 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[0].character)), (yylsp[0]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
       symbol_user_token_number_set ((yyval.symbol), (yyvsp[0].character), (yylsp[0]));
     }
 /* Line 1380 of yacc.c  */
-#line 2637 "../../src/parse-gram.c"
+#line 2618 "../../src/parse-gram.c"
     break;
 
-  case 100:
+  case 99:
 /* Line 1380 of yacc.c  */
-#line 604 "parse-gram.y"
+#line 591 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2645 "../../src/parse-gram.c"
+#line 2626 "../../src/parse-gram.c"
     break;
 
-  case 103:
+  case 102:
 /* Line 1380 of yacc.c  */
-#line 616 "parse-gram.y"
+#line 603 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[0].chars)), (yylsp[0]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
     }
 /* Line 1380 of yacc.c  */
-#line 2656 "../../src/parse-gram.c"
+#line 2637 "../../src/parse-gram.c"
     break;
 
-  case 105:
+  case 104:
 /* Line 1380 of yacc.c  */
-#line 625 "parse-gram.y"
+#line 612 "parse-gram.y"
     {
       code_props plain_code;
       code_props_plain_init (&plain_code, (yyvsp[0].chars), (yylsp[0]));
@@ -2667,12 +2648,12 @@ yyreduce:
       code_scanner_last_string_free ();
     }
 /* Line 1380 of yacc.c  */
-#line 2671 "../../src/parse-gram.c"
+#line 2652 "../../src/parse-gram.c"
     break;
 
 
 /* Line 1380 of yacc.c  */
-#line 2676 "../../src/parse-gram.c"
+#line 2657 "../../src/parse-gram.c"
       default: break;
     }
   YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);
@@ -2889,7 +2870,7 @@ yyreturn:
 }
 
 /* Line 1599 of yacc.c  */
-#line 635 "parse-gram.y"
+#line 622 "parse-gram.y"
 
 
 
