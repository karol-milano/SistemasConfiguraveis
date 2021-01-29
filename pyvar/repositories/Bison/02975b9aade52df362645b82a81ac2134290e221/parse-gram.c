@@ -562,16 +562,16 @@ union yyalloc
 /* YYFINAL -- State number of the termination state.  */
 #define YYFINAL  3
 /* YYLAST -- Last index in YYTABLE.  */
-#define YYLAST   205
+#define YYLAST   182
 
 /* YYNTOKENS -- Number of terminals.  */
 #define YYNTOKENS  60
 /* YYNNTS -- Number of nonterminals.  */
 #define YYNNTS  31
 /* YYNRULES -- Number of rules.  */
-#define YYNRULES  99
+#define YYNRULES  103
 /* YYNRULES -- Number of states.  */
-#define YYNSTATES  138
+#define YYNSTATES  142
 
 /* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
 #define YYUNDEFTOK  2
@@ -620,18 +620,19 @@ static const yytype_uint8 yytranslate[] =
 #if YYDEBUG
 /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
    YYRHS.  */
-static const yytype_uint8 yyprhs[] =
+static const yytype_uint16 yyprhs[] =
 {
        0,     0,     3,     8,     9,    12,    14,    16,    18,    22,
-      24,    26,    29,    32,    36,    38,    41,    44,    46,    50,
-      52,    54,    58,    61,    63,    65,    68,    71,    73,    75,
-      77,    79,    81,    83,    86,    90,    94,    96,    98,   101,
-     104,   107,   110,   111,   113,   117,   118,   122,   123,   127,
-     131,   135,   137,   139,   141,   142,   144,   146,   149,   151,
-     154,   156,   158,   160,   162,   164,   166,   169,   172,   176,
-     178,   181,   183,   186,   188,   191,   194,   195,   199,   201,
-     205,   208,   209,   212,   215,   219,   223,   227,   229,   231,
-     232,   234,   236,   238,   240,   242,   244,   246,   248,   249
+      24,    27,    29,    32,    35,    38,    42,    44,    47,    50,
+      52,    55,    59,    61,    63,    66,    70,    73,    75,    77,
+      80,    83,    85,    87,    89,    91,    93,    95,    98,   102,
+     106,   108,   110,   113,   116,   119,   122,   123,   125,   129,
+     130,   134,   135,   139,   143,   147,   149,   151,   153,   154,
+     156,   158,   161,   163,   166,   168,   170,   172,   174,   176,
+     178,   181,   184,   188,   190,   193,   195,   198,   200,   203,
+     206,   207,   211,   213,   217,   220,   221,   224,   227,   231,
+     235,   239,   241,   243,   244,   246,   248,   250,   252,   254,
+     256,   258,   260,   261
 };
 
 /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
@@ -639,45 +640,47 @@ static const yytype_int8 yyrhs[] =
 {
       61,     0,    -1,    62,    52,    77,    90,    -1,    -1,    62,
       63,    -1,    64,    -1,    54,    -1,    18,    -1,    20,     3,
-      84,    -1,    21,    -1,    22,    -1,    23,     4,    -1,    24,
-       4,    -1,    25,    49,     3,    -1,    26,    -1,    27,    46,
-      -1,    28,    46,    -1,    29,    -1,    30,    49,     3,    -1,
-      32,    -1,    33,    -1,    34,    49,     3,    -1,    35,    46,
-      -1,    37,    -1,    38,    -1,    39,     3,    -1,    41,     3,
-      -1,    43,    -1,    44,    -1,    45,    -1,    55,    -1,    69,
-      -1,    66,    -1,    42,    88,    -1,     8,    46,    73,    -1,
-       9,    46,    73,    -1,    19,    -1,    31,    -1,    16,    85,
-      -1,    17,    85,    -1,    36,    85,    -1,    40,    85,    -1,
-      -1,    50,    -1,    59,    65,    46,    -1,    -1,     6,    67,
-      76,    -1,    -1,     5,    68,    76,    -1,     7,    56,    72,
-      -1,    70,    71,    72,    -1,    10,    -1,    11,    -1,    12,
-      -1,    -1,    56,    -1,    88,    -1,    72,    88,    -1,    74,
-      -1,    73,    74,    -1,    88,    -1,    56,    -1,    57,    -1,
-      58,    -1,    56,    -1,    86,    -1,    86,     4,    -1,    86,
-      89,    -1,    86,     4,    89,    -1,    75,    -1,    76,    75,
-      -1,    78,    -1,    77,    78,    -1,    79,    -1,    64,    55,
-      -1,     1,    55,    -1,    -1,    87,    80,    81,    -1,    82,
-      -1,    81,    53,    82,    -1,    81,    55,    -1,    -1,    82,
-      88,    -1,    82,    46,    -1,    82,    13,    88,    -1,    82,
-      14,     4,    -1,    82,    15,    56,    -1,     3,    -1,    85,
-      -1,    -1,    83,    -1,    46,    -1,    50,    -1,    47,    -1,
-      51,    -1,    86,    -1,    89,    -1,     3,    -1,    -1,    52,
-      48,    -1
+      84,    -1,    21,    -1,    21,     3,    -1,    22,    -1,    23,
+       4,    -1,    24,     4,    -1,    25,     3,    -1,    25,    49,
+       3,    -1,    26,    -1,    27,    46,    -1,    28,    46,    -1,
+      29,    -1,    30,     3,    -1,    30,    49,     3,    -1,    32,
+      -1,    33,    -1,    34,     3,    -1,    34,    49,     3,    -1,
+      35,    46,    -1,    37,    -1,    38,    -1,    39,     3,    -1,
+      41,     3,    -1,    43,    -1,    44,    -1,    45,    -1,    55,
+      -1,    69,    -1,    66,    -1,    42,    88,    -1,     8,    46,
+      73,    -1,     9,    46,    73,    -1,    19,    -1,    31,    -1,
+      16,    85,    -1,    17,    85,    -1,    36,    85,    -1,    40,
+      85,    -1,    -1,    50,    -1,    59,    65,    46,    -1,    -1,
+       6,    67,    76,    -1,    -1,     5,    68,    76,    -1,     7,
+      56,    72,    -1,    70,    71,    72,    -1,    10,    -1,    11,
+      -1,    12,    -1,    -1,    56,    -1,    88,    -1,    72,    88,
+      -1,    74,    -1,    73,    74,    -1,    88,    -1,    56,    -1,
+      57,    -1,    58,    -1,    56,    -1,    86,    -1,    86,     4,
+      -1,    86,    89,    -1,    86,     4,    89,    -1,    75,    -1,
+      76,    75,    -1,    78,    -1,    77,    78,    -1,    79,    -1,
+      64,    55,    -1,     1,    55,    -1,    -1,    87,    80,    81,
+      -1,    82,    -1,    81,    53,    82,    -1,    81,    55,    -1,
+      -1,    82,    88,    -1,    82,    46,    -1,    82,    13,    88,
+      -1,    82,    14,     4,    -1,    82,    15,    56,    -1,     3,
+      -1,    85,    -1,    -1,    83,    -1,    46,    -1,    50,    -1,
+      47,    -1,    51,    -1,    86,    -1,    89,    -1,     3,    -1,
+      -1,    52,    48,    -1
 };
 
 /* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
 static const yytype_uint16 yyrline[] =
 {
        0,   210,   210,   218,   220,   224,   225,   226,   227,   228,
-     229,   230,   231,   232,   233,   238,   242,   243,   244,   245,
-     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
-     256,   260,   261,   262,   266,   274,   282,   286,   290,   291,
-     292,   293,   304,   305,   309,   337,   337,   342,   342,   347,
-     358,   373,   374,   375,   379,   380,   385,   387,   392,   393,
-     397,   398,   399,   400,   405,   410,   415,   421,   427,   438,
-     439,   448,   449,   455,   456,   457,   464,   464,   468,   469,
-     470,   475,   476,   478,   480,   482,   484,   494,   495,   501,
-     505,   510,   526,   528,   537,   542,   543,   548,   555,   557
+     229,   234,   235,   236,   237,   238,   239,   244,   248,   249,
+     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
+     260,   261,   262,   263,   264,   268,   269,   270,   274,   282,
+     290,   294,   298,   299,   300,   301,   312,   313,   317,   345,
+     345,   350,   350,   355,   366,   381,   382,   383,   387,   388,
+     393,   395,   400,   401,   405,   406,   407,   408,   413,   418,
+     423,   429,   435,   446,   447,   456,   457,   463,   464,   465,
+     472,   472,   476,   477,   478,   483,   484,   486,   488,   490,
+     492,   502,   503,   509,   513,   518,   534,   536,   545,   550,
+     551,   556,   563,   565
 };
 #endif
 
@@ -730,28 +733,30 @@ static const yytype_uint8 yyr1[] =
        0,    60,    61,    62,    62,    63,    63,    63,    63,    63,
       63,    63,    63,    63,    63,    63,    63,    63,    63,    63,
       63,    63,    63,    63,    63,    63,    63,    63,    63,    63,
-      63,    64,    64,    64,    64,    64,    64,    64,    64,    64,
-      64,    64,    65,    65,    64,    67,    66,    68,    66,    66,
-      69,    70,    70,    70,    71,    71,    72,    72,    73,    73,
-      74,    74,    74,    74,    75,    75,    75,    75,    75,    76,
-      76,    77,    77,    78,    78,    78,    80,    79,    81,    81,
-      81,    82,    82,    82,    82,    82,    82,    83,    83,    84,
-      84,    85,    86,    86,    87,    88,    88,    89,    90,    90
+      63,    63,    63,    63,    63,    64,    64,    64,    64,    64,
+      64,    64,    64,    64,    64,    64,    65,    65,    64,    67,
+      66,    68,    66,    66,    69,    70,    70,    70,    71,    71,
+      72,    72,    73,    73,    74,    74,    74,    74,    75,    75,
+      75,    75,    75,    76,    76,    77,    77,    78,    78,    78,
+      80,    79,    81,    81,    81,    82,    82,    82,    82,    82,
+      82,    83,    83,    84,    84,    85,    86,    86,    87,    88,
+      88,    89,    90,    90
 };
 
 /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
 static const yytype_uint8 yyr2[] =
 {
        0,     2,     4,     0,     2,     1,     1,     1,     3,     1,
-       1,     2,     2,     3,     1,     2,     2,     1,     3,     1,
-       1,     3,     2,     1,     1,     2,     2,     1,     1,     1,
-       1,     1,     1,     2,     3,     3,     1,     1,     2,     2,
-       2,     2,     0,     1,     3,     0,     3,     0,     3,     3,
-       3,     1,     1,     1,     0,     1,     1,     2,     1,     2,
-       1,     1,     1,     1,     1,     1,     2,     2,     3,     1,
-       2,     1,     2,     1,     2,     2,     0,     3,     1,     3,
-       2,     0,     2,     2,     3,     3,     3,     1,     1,     0,
-       1,     1,     1,     1,     1,     1,     1,     1,     0,     2
+       2,     1,     2,     2,     2,     3,     1,     2,     2,     1,
+       2,     3,     1,     1,     2,     3,     2,     1,     1,     2,
+       2,     1,     1,     1,     1,     1,     1,     2,     3,     3,
+       1,     1,     2,     2,     2,     2,     0,     1,     3,     0,
+       3,     0,     3,     3,     3,     1,     1,     1,     0,     1,
+       1,     2,     1,     2,     1,     1,     1,     1,     1,     1,
+       2,     2,     3,     1,     2,     1,     2,     1,     2,     2,
+       0,     3,     1,     3,     2,     0,     2,     2,     3,     3,
+       3,     1,     1,     0,     1,     1,     1,     1,     1,     1,
+       1,     1,     0,     2
 };
 
 /* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
@@ -759,114 +764,112 @@ static const yytype_uint8 yyr2[] =
    means the default is an error.  */
 static const yytype_uint8 yydefact[] =
 {
-       3,     0,     0,     1,    47,    45,     0,     0,     0,    51,
-      52,    53,     0,     0,     7,    36,     0,     9,    10,     0,
-       0,     0,    14,     0,     0,    17,     0,    37,    19,    20,
-       0,     0,     0,    23,    24,     0,     0,     0,     0,    27,
-      28,    29,     0,     6,    30,    42,     4,     5,    32,    31,
-      54,     0,     0,     0,     0,     0,    91,    38,    39,    89,
-      11,    12,     0,    15,    16,     0,     0,    22,    40,    25,
-      41,    26,    97,    93,    92,    95,    33,    96,     0,    94,
-       0,     0,    71,    73,    76,    43,     0,    55,     0,    64,
-      69,    48,    65,    46,    49,    56,    61,    62,    63,    34,
-      58,    60,    35,    87,    90,     8,    88,    13,    18,    21,
-      75,    74,     0,    72,     2,    81,    44,    50,    70,    66,
-      67,    57,    59,    99,    77,    78,    68,    81,    80,     0,
-       0,     0,    83,    82,    79,    84,    85,    86
+       3,     0,     0,     1,    51,    49,     0,     0,     0,    55,
+      56,    57,     0,     0,     7,    40,     0,     9,    11,     0,
+       0,     0,    16,     0,     0,    19,     0,    41,    22,    23,
+       0,     0,     0,    27,    28,     0,     0,     0,     0,    31,
+      32,    33,     0,     6,    34,    46,     4,     5,    36,    35,
+      58,     0,     0,     0,     0,     0,    95,    42,    43,    93,
+      10,    12,    13,    14,     0,    17,    18,    20,     0,    24,
+       0,    26,    44,    29,    45,    30,   101,    97,    96,    99,
+      37,   100,     0,    98,     0,     0,    75,    77,    80,    47,
+       0,    59,     0,    68,    73,    52,    69,    50,    53,    60,
+      65,    66,    67,    38,    62,    64,    39,    91,    94,     8,
+      92,    15,    21,    25,    79,    78,     0,    76,     2,    85,
+      48,    54,    74,    70,    71,    61,    63,   103,    81,    82,
+      72,    85,    84,     0,     0,     0,    87,    86,    83,    88,
+      89,    90
 };
 
 /* YYDEFGOTO[NTERM-NUM].  */
-static const yytype_int8 yydefgoto[] =
+static const yytype_int16 yydefgoto[] =
 {
-      -1,     1,     2,    46,    80,    86,    48,    52,    51,    49,
-      50,    88,    94,    99,   100,    90,    91,    81,    82,    83,
-     115,   124,   125,   104,   105,    57,    75,    84,   101,    77,
-     114
+      -1,     1,     2,    46,    84,    90,    48,    52,    51,    49,
+      50,    92,    98,   103,   104,    94,    95,    85,    86,    87,
+     119,   128,   129,   108,   109,    57,    79,    88,   105,    81,
+     118
 };
 
 /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
    STATE-NUM.  */
-#define YYPACT_NINF -89
-static const yytype_int16 yypact[] =
+#define YYPACT_NINF -97
+static const yytype_int8 yypact[] =
 {
-     -89,    14,   112,   -89,   -89,   -89,   -33,   -16,   -11,   -89,
-     -89,   -89,    -6,    -6,   -89,   -89,    39,   -89,   -89,    42,
-      43,     5,   -89,     9,    11,   -89,    10,   -89,   -89,   -89,
-      12,    24,    -6,   -89,   -89,    48,    -6,    68,    30,   -89,
-     -89,   -89,    57,   -89,   -89,    28,   -89,   -89,   -89,   -89,
-      29,   -31,   -31,    30,    25,    25,   -89,   -89,   -89,     2,
-     -89,   -89,    86,   -89,   -89,    87,    89,   -89,   -89,   -89,
-     -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,    40,   -89,
-      45,     1,   -89,   -89,   -89,   -89,    52,   -89,    30,   -89,
-     -89,   -31,    35,   -31,    30,   -89,   -89,   -89,   -89,    25,
-     -89,   -89,    25,   -89,   -89,   -89,   -89,   -89,   -89,   -89,
-     -89,   -89,    46,   -89,   -89,   -89,   -89,    30,   -89,    98,
-     -89,   -89,   -89,   -89,   -26,   155,   -89,   -89,   -89,    30,
-      99,    49,   -89,   -89,   155,   -89,   -89,   -89
+     -97,     3,   123,   -97,   -97,   -97,   -42,    -6,    -5,   -97,
+     -97,   -97,    -3,    -3,   -97,   -97,    41,    55,   -97,    57,
+      60,     1,   -97,    36,    40,   -97,    10,   -97,   -97,   -97,
+      23,    44,    -3,   -97,   -97,    85,    -3,    90,    -2,   -97,
+     -97,   -97,    68,   -97,   -97,    46,   -97,   -97,   -97,   -97,
+      38,    42,    42,    -2,    -1,    -1,   -97,   -97,   -97,    35,
+     -97,   -97,   -97,   -97,    94,   -97,   -97,   -97,    98,   -97,
+      99,   -97,   -97,   -97,   -97,   -97,   -97,   -97,   -97,   -97,
+     -97,   -97,    48,   -97,    50,    11,   -97,   -97,   -97,   -97,
+      61,   -97,    -2,   -97,   -97,    42,     5,    42,    -2,   -97,
+     -97,   -97,   -97,    -1,   -97,   -97,    -1,   -97,   -97,   -97,
+     -97,   -97,   -97,   -97,   -97,   -97,    58,   -97,   -97,   -97,
+     -97,    -2,   -97,   109,   -97,   -97,   -97,   -97,   -22,    21,
+     -97,   -97,   -97,    -2,   110,    59,   -97,   -97,    21,   -97,
+     -97,   -97
 };
 
 /* YYPGOTO[NTERM-NUM].  */
 static const yytype_int8 yypgoto[] =
 {
-     -89,   -89,   -89,   -89,   100,   -89,   -89,   -89,   -89,   -89,
-     -89,   -89,    16,    51,   -78,   -57,    55,   -89,    31,   -89,
-     -89,   -89,   -18,   -89,   -89,   -10,    -7,   -89,   -38,   -88,
-     -89
+     -97,   -97,   -97,   -97,   111,   -97,   -97,   -97,   -97,   -97,
+     -97,   -97,    24,    62,   -96,   -58,    66,   -97,    37,   -97,
+     -97,   -97,   -11,   -97,   -97,    -7,    14,   -97,   -38,   -91,
+     -97
 };
 
 /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
    positive, shift that token.  If negative, reduce the rule which
    number is the opposite.  If zero, do what YYDEFACT says.
    If YYTABLE_NINF, syntax error.  */
-#define YYTABLE_NINF -99
+#define YYTABLE_NINF -103
 static const yytype_int16 yytable[] =
 {
-      76,   -98,    78,    58,   120,   103,     4,     5,     6,     7,
-       8,     9,    10,    11,     3,    95,    73,    12,    13,    74,
-      15,   122,    68,    53,   122,    89,    70,   127,    72,   128,
-      54,   126,    27,    72,   118,    55,   118,    32,    72,   119,
-      56,    36,    59,    38,    92,    92,    60,    61,    56,   106,
-      95,    69,    79,   112,    62,    63,   121,    64,    78,    65,
-      45,    66,     4,     5,     6,     7,     8,     9,    10,    11,
-      67,    71,    73,    12,    13,    74,    15,    73,    85,   121,
-      74,    96,    97,    98,    92,    87,    92,   133,    27,   107,
-     108,   135,   109,    32,   123,   110,   133,    36,   116,    38,
-     111,    72,    47,   136,   117,   137,   102,    93,    79,   134,
-       0,     0,   113,     0,     0,     0,    45,     4,     5,     6,
-       7,     8,     9,    10,    11,     0,     0,     0,    12,    13,
-      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
-      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
-      34,    35,    36,    37,    38,    39,    40,    41,    72,     0,
-       0,     0,     0,     0,    42,     0,    43,    44,   129,   130,
-     131,    45,     0,     0,     0,     0,     0,     0,     0,     0,
-       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
-       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
-       0,   132,    73,     0,     0,    74
+      80,    76,    76,     3,    63,   124,    58,   126,    76,   123,
+     126,  -102,    82,    67,    53,    99,     4,     5,     6,     7,
+       8,     9,    10,    11,    76,    72,    69,    12,    13,    74,
+      15,   131,   130,   132,   133,   134,   135,   122,   107,   122,
+      54,    55,    27,    56,    59,    77,    77,    32,    78,    78,
+      64,    36,   110,    38,    99,   100,   101,   102,    60,    68,
+     125,    61,    83,   116,    62,    96,    96,   136,    77,    82,
+      45,    78,    70,     4,     5,     6,     7,     8,     9,    10,
+      11,    56,    65,   125,    12,    13,    66,    15,    73,    77,
+      71,   137,    78,    75,    91,   139,    89,   111,    93,    27,
+     137,   112,   113,   114,    32,   115,   127,   120,    36,    96,
+      38,    96,    76,    47,   140,   141,   121,   106,    97,    83,
+     138,     0,   117,     0,     0,     0,     0,    45,     4,     5,
+       6,     7,     8,     9,    10,    11,     0,     0,     0,    12,
+      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
+      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
+      33,    34,    35,    36,    37,    38,    39,    40,    41,     0,
+       0,     0,     0,     0,     0,    42,     0,    43,    44,     0,
+       0,     0,    45
 };
 
 static const yytype_int16 yycheck[] =
 {
-      38,     0,     1,    13,    92,     3,     5,     6,     7,     8,
-       9,    10,    11,    12,     0,    53,    47,    16,    17,    50,
-      19,    99,    32,    56,   102,    56,    36,    53,     3,    55,
-      46,   119,    31,     3,    91,    46,    93,    36,     3,     4,
-      46,    40,     3,    42,    51,    52,     4,     4,    46,    59,
-      88,     3,    51,    52,    49,    46,    94,    46,     1,    49,
-      59,    49,     5,     6,     7,     8,     9,    10,    11,    12,
-      46,     3,    47,    16,    17,    50,    19,    47,    50,   117,
-      50,    56,    57,    58,    91,    56,    93,   125,    31,     3,
-       3,   129,     3,    36,    48,    55,   134,    40,    46,    42,
-      55,     3,     2,     4,    88,    56,    55,    52,    51,   127,
-      -1,    -1,    81,    -1,    -1,    -1,    59,     5,     6,     7,
-       8,     9,    10,    11,    12,    -1,    -1,    -1,    16,    17,
-      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
-      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
-      38,    39,    40,    41,    42,    43,    44,    45,     3,    -1,
-      -1,    -1,    -1,    -1,    52,    -1,    54,    55,    13,    14,
-      15,    59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
-      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
-      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
-      -1,    46,    47,    -1,    -1,    50
+      38,     3,     3,     0,     3,    96,    13,   103,     3,     4,
+     106,     0,     1,     3,    56,    53,     5,     6,     7,     8,
+       9,    10,    11,    12,     3,    32,     3,    16,    17,    36,
+      19,    53,   123,    55,    13,    14,    15,    95,     3,    97,
+      46,    46,    31,    46,     3,    47,    47,    36,    50,    50,
+      49,    40,    59,    42,    92,    56,    57,    58,     3,    49,
+      98,     4,    51,    52,     4,    51,    52,    46,    47,     1,
+      59,    50,    49,     5,     6,     7,     8,     9,    10,    11,
+      12,    46,    46,   121,    16,    17,    46,    19,     3,    47,
+      46,   129,    50,     3,    56,   133,    50,     3,    56,    31,
+     138,     3,     3,    55,    36,    55,    48,    46,    40,    95,
+      42,    97,     3,     2,     4,    56,    92,    55,    52,    51,
+     131,    -1,    85,    -1,    -1,    -1,    -1,    59,     5,     6,
+       7,     8,     9,    10,    11,    12,    -1,    -1,    -1,    16,
+      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
+      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
+      37,    38,    39,    40,    41,    42,    43,    44,    45,    -1,
+      -1,    -1,    -1,    -1,    -1,    52,    -1,    54,    55,    -1,
+      -1,    -1,    59
 };
 
 /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
@@ -879,14 +882,15 @@ static const yytype_uint8 yystos[] =
       34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
       44,    45,    52,    54,    55,    59,    63,    64,    66,    69,
       70,    68,    67,    56,    46,    46,    46,    85,    85,     3,
-       4,     4,    49,    46,    46,    49,    49,    46,    85,     3,
-      85,     3,     3,    47,    50,    86,    88,    89,     1,    51,
-      64,    77,    78,    79,    87,    50,    65,    56,    71,    56,
-      75,    76,    86,    76,    72,    88,    56,    57,    58,    73,
-      74,    88,    73,     3,    83,    84,    85,     3,     3,     3,
-      55,    55,    52,    78,    90,    80,    46,    72,    75,     4,
-      89,    88,    74,    48,    81,    82,    89,    53,    55,    13,
-      14,    15,    46,    88,    82,    88,     4,    56
+       3,     4,     4,     3,    49,    46,    46,     3,    49,     3,
+      49,    46,    85,     3,    85,     3,     3,    47,    50,    86,
+      88,    89,     1,    51,    64,    77,    78,    79,    87,    50,
+      65,    56,    71,    56,    75,    76,    86,    76,    72,    88,
+      56,    57,    58,    73,    74,    88,    73,     3,    83,    84,
+      85,     3,     3,     3,    55,    55,    52,    78,    90,    80,
+      46,    72,    75,     4,    89,    88,    74,    48,    81,    82,
+      89,    53,    55,    13,    14,    15,    46,    88,    82,    88,
+       4,    56
 };
 
 #define yyerrok		(yyerrstatus = 0)
@@ -1041,7 +1045,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 	{ fputs (quotearg_style (c_quoting_style, (yyvaluep->chars)), stderr); };
 
 /* Line 670 of yacc.c  */
-#line 1045 "parse-gram.c"
+#line 1049 "parse-gram.c"
 	break;
       case 4: /* "\"integer\"" */
 
@@ -1050,7 +1054,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 	{ fprintf (stderr, "%d", (yyvaluep->integer)); };
 
 /* Line 670 of yacc.c  */
-#line 1054 "parse-gram.c"
+#line 1058 "parse-gram.c"
 	break;
       case 46: /* "\"{...}\"" */
 
@@ -1059,7 +1063,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->code)); };
 
 /* Line 670 of yacc.c  */
-#line 1063 "parse-gram.c"
+#line 1067 "parse-gram.c"
 	break;
       case 47: /* "\"char\"" */
 
@@ -1068,7 +1072,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 	{ fputs (char_name ((yyvaluep->character)), stderr); };
 
 /* Line 670 of yacc.c  */
-#line 1072 "parse-gram.c"
+#line 1076 "parse-gram.c"
 	break;
       case 48: /* "\"epilogue\"" */
 
@@ -1077,7 +1081,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
 /* Line 670 of yacc.c  */
-#line 1081 "parse-gram.c"
+#line 1085 "parse-gram.c"
 	break;
       case 50: /* "\"identifier\"" */
 
@@ -1086,7 +1090,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 	{ fputs ((yyvaluep->uniqstr), stderr); };
 
 /* Line 670 of yacc.c  */
-#line 1090 "parse-gram.c"
+#line 1094 "parse-gram.c"
 	break;
       case 51: /* "\"identifier:\"" */
 
@@ -1095,7 +1099,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 	{ fprintf (stderr, "%s:", (yyvaluep->uniqstr)); };
 
 /* Line 670 of yacc.c  */
-#line 1099 "parse-gram.c"
+#line 1103 "parse-gram.c"
 	break;
       case 54: /* "\"%{...%}\"" */
 
@@ -1104,7 +1108,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
 /* Line 670 of yacc.c  */
-#line 1108 "parse-gram.c"
+#line 1112 "parse-gram.c"
 	break;
       case 56: /* "\"type\"" */
 
@@ -1113,7 +1117,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 	{ fprintf (stderr, "<%s>", (yyvaluep->uniqstr)); };
 
 /* Line 670 of yacc.c  */
-#line 1117 "parse-gram.c"
+#line 1121 "parse-gram.c"
 	break;
       case 83: /* "content" */
 
@@ -1122,7 +1126,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
 /* Line 670 of yacc.c  */
-#line 1126 "parse-gram.c"
+#line 1130 "parse-gram.c"
 	break;
       case 84: /* "content.opt" */
 
@@ -1131,7 +1135,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
 /* Line 670 of yacc.c  */
-#line 1135 "parse-gram.c"
+#line 1139 "parse-gram.c"
 	break;
       case 85: /* "braceless" */
 
@@ -1140,7 +1144,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
 /* Line 670 of yacc.c  */
-#line 1144 "parse-gram.c"
+#line 1148 "parse-gram.c"
 	break;
       case 86: /* "id" */
 
@@ -1149,7 +1153,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
 /* Line 670 of yacc.c  */
-#line 1153 "parse-gram.c"
+#line 1157 "parse-gram.c"
 	break;
       case 87: /* "id_colon" */
 
@@ -1158,7 +1162,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 	{ fprintf (stderr, "%s:", (yyvaluep->symbol)->tag); };
 
 /* Line 670 of yacc.c  */
-#line 1162 "parse-gram.c"
+#line 1166 "parse-gram.c"
 	break;
       case 88: /* "symbol" */
 
@@ -1167,7 +1171,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
 /* Line 670 of yacc.c  */
-#line 1171 "parse-gram.c"
+#line 1175 "parse-gram.c"
 	break;
       case 89: /* "string_as_id" */
 
@@ -1176,7 +1180,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
 /* Line 670 of yacc.c  */
-#line 1180 "parse-gram.c"
+#line 1184 "parse-gram.c"
 	break;
       default:
 	break;
@@ -1700,7 +1704,7 @@ YYLTYPE yylloc;
 }
 
 /* Line 1082 of yacc.c  */
-#line 1704 "parse-gram.c"
+#line 1708 "parse-gram.c"
   yylsp[0] = yylloc;
   goto yysetstate;
 
@@ -1914,161 +1918,192 @@ yyreduce:
   case 10:
 
 /* Line 1269 of yacc.c  */
-#line 229 "parse-gram.y"
-    { error_verbose = true; }
+#line 230 "parse-gram.y"
+    {
+      defines_flag = true;
+      spec_defines_file = xstrdup ((yyvsp[(2) - (2)].chars));
+    }
     break;
 
   case 11:
 
 /* Line 1269 of yacc.c  */
-#line 230 "parse-gram.y"
-    { expected_sr_conflicts = (yyvsp[(2) - (2)].integer); }
+#line 234 "parse-gram.y"
+    { error_verbose = true; }
     break;
 
   case 12:
 
 /* Line 1269 of yacc.c  */
-#line 231 "parse-gram.y"
-    { expected_rr_conflicts = (yyvsp[(2) - (2)].integer); }
+#line 235 "parse-gram.y"
+    { expected_sr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 13:
 
 /* Line 1269 of yacc.c  */
-#line 232 "parse-gram.y"
-    { spec_file_prefix = (yyvsp[(3) - (3)].chars); }
+#line 236 "parse-gram.y"
+    { expected_rr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 14:
 
 /* Line 1269 of yacc.c  */
-#line 234 "parse-gram.y"
+#line 237 "parse-gram.y"
+    { spec_file_prefix = (yyvsp[(2) - (2)].chars); }
+    break;
+
+  case 15:
+
+/* Line 1269 of yacc.c  */
+#line 238 "parse-gram.y"
+    { spec_file_prefix = (yyvsp[(3) - (3)].chars); }
+    break;
+
+  case 16:
+
+/* Line 1269 of yacc.c  */
+#line 240 "parse-gram.y"
     {
       nondeterministic_parser = true;
       glr_parser = true;
     }
     break;
 
-  case 15:
+  case 17:
 
 /* Line 1269 of yacc.c  */
-#line 239 "parse-gram.y"
+#line 245 "parse-gram.y"
     {
       muscle_code_grow ("initial_action", translate_symbol_action ((yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])), (yylsp[(2) - (2)]));
     }
     break;
 
-  case 16:
+  case 18:
 
 /* Line 1269 of yacc.c  */
-#line 242 "parse-gram.y"
+#line 248 "parse-gram.y"
     { add_param ("lex_param", (yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
     break;
 
-  case 17:
+  case 19:
 
 /* Line 1269 of yacc.c  */
-#line 243 "parse-gram.y"
+#line 249 "parse-gram.y"
     { locations_flag = true; }
     break;
 
-  case 18:
+  case 20:
 
 /* Line 1269 of yacc.c  */
-#line 244 "parse-gram.y"
+#line 250 "parse-gram.y"
+    { spec_name_prefix = (yyvsp[(2) - (2)].chars); }
+    break;
+
+  case 21:
+
+/* Line 1269 of yacc.c  */
+#line 251 "parse-gram.y"
     { spec_name_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
-  case 19:
+  case 22:
 
 /* Line 1269 of yacc.c  */
-#line 245 "parse-gram.y"
+#line 252 "parse-gram.y"
     { no_lines_flag = true; }
     break;
 
-  case 20:
+  case 23:
 
 /* Line 1269 of yacc.c  */
-#line 246 "parse-gram.y"
+#line 253 "parse-gram.y"
     { nondeterministic_parser = true; }
     break;
 
-  case 21:
+  case 24:
+
+/* Line 1269 of yacc.c  */
+#line 254 "parse-gram.y"
+    { spec_outfile = (yyvsp[(2) - (2)].chars); }
+    break;
+
+  case 25:
 
 /* Line 1269 of yacc.c  */
-#line 247 "parse-gram.y"
+#line 255 "parse-gram.y"
     { spec_outfile = (yyvsp[(3) - (3)].chars); }
     break;
 
-  case 22:
+  case 26:
 
 /* Line 1269 of yacc.c  */
-#line 248 "parse-gram.y"
+#line 256 "parse-gram.y"
     { add_param ("parse_param", (yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
     break;
 
-  case 23:
+  case 27:
 
 /* Line 1269 of yacc.c  */
-#line 249 "parse-gram.y"
+#line 257 "parse-gram.y"
     { pure_parser = true; }
     break;
 
-  case 24:
+  case 28:
 
 /* Line 1269 of yacc.c  */
-#line 250 "parse-gram.y"
+#line 258 "parse-gram.y"
     { push_parser = true; }
     break;
 
-  case 25:
+  case 29:
 
 /* Line 1269 of yacc.c  */
-#line 251 "parse-gram.y"
+#line 259 "parse-gram.y"
     { version_check (&(yylsp[(2) - (2)]), (yyvsp[(2) - (2)].chars)); }
     break;
 
-  case 26:
+  case 30:
 
 /* Line 1269 of yacc.c  */
-#line 252 "parse-gram.y"
+#line 260 "parse-gram.y"
     { skeleton = (yyvsp[(2) - (2)].chars); }
     break;
 
-  case 27:
+  case 31:
 
 /* Line 1269 of yacc.c  */
-#line 253 "parse-gram.y"
+#line 261 "parse-gram.y"
     { token_table_flag = true; }
     break;
 
-  case 28:
+  case 32:
 
 /* Line 1269 of yacc.c  */
-#line 254 "parse-gram.y"
+#line 262 "parse-gram.y"
     { report_flag = report_states; }
     break;
 
-  case 29:
+  case 33:
 
 /* Line 1269 of yacc.c  */
-#line 255 "parse-gram.y"
+#line 263 "parse-gram.y"
     { yacc_flag = true; }
     break;
 
-  case 33:
+  case 37:
 
 /* Line 1269 of yacc.c  */
-#line 263 "parse-gram.y"
+#line 271 "parse-gram.y"
     {
       grammar_start_symbol_set ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]));
     }
     break;
 
-  case 34:
+  case 38:
 
 /* Line 1269 of yacc.c  */
-#line 267 "parse-gram.y"
+#line 275 "parse-gram.y"
     {
       symbol_list *list;
       const char *action = translate_symbol_action ((yyvsp[(2) - (3)].code), (yylsp[(2) - (3)]));
@@ -2078,10 +2113,10 @@ yyreduce:
     }
     break;
 
-  case 35:
+  case 39:
 
 /* Line 1269 of yacc.c  */
-#line 275 "parse-gram.y"
+#line 283 "parse-gram.y"
     {
       symbol_list *list;
       const char *action = translate_symbol_action ((yyvsp[(2) - (3)].code), (yylsp[(2) - (3)]));
@@ -2091,70 +2126,70 @@ yyreduce:
     }
     break;
 
-  case 36:
+  case 40:
 
 /* Line 1269 of yacc.c  */
-#line 283 "parse-gram.y"
+#line 291 "parse-gram.y"
     {
       default_prec = true;
     }
     break;
 
-  case 37:
+  case 41:
 
 /* Line 1269 of yacc.c  */
-#line 287 "parse-gram.y"
+#line 295 "parse-gram.y"
     {
       default_prec = false;
     }
     break;
 
-  case 38:
+  case 42:
 
 /* Line 1269 of yacc.c  */
-#line 290 "parse-gram.y"
+#line 298 "parse-gram.y"
     { prologue_augment ((yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)]), true); }
     break;
 
-  case 39:
+  case 43:
 
 /* Line 1269 of yacc.c  */
-#line 291 "parse-gram.y"
+#line 299 "parse-gram.y"
     { prologue_augment ((yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)]), false); }
     break;
 
-  case 40:
+  case 44:
 
 /* Line 1269 of yacc.c  */
-#line 292 "parse-gram.y"
+#line 300 "parse-gram.y"
     { muscle_code_grow ("provides", (yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])); }
     break;
 
-  case 41:
+  case 45:
 
 /* Line 1269 of yacc.c  */
-#line 293 "parse-gram.y"
+#line 301 "parse-gram.y"
     { muscle_code_grow ("requires", (yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])); }
     break;
 
-  case 42:
+  case 46:
 
 /* Line 1269 of yacc.c  */
-#line 304 "parse-gram.y"
+#line 312 "parse-gram.y"
     {}
     break;
 
-  case 43:
+  case 47:
 
 /* Line 1269 of yacc.c  */
-#line 305 "parse-gram.y"
+#line 313 "parse-gram.y"
     { muscle_code_grow ("union_name", (yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
-  case 44:
+  case 48:
 
 /* Line 1269 of yacc.c  */
-#line 310 "parse-gram.y"
+#line 318 "parse-gram.y"
     {
       char const *body = (yyvsp[(3) - (3)].code);
 
@@ -2178,44 +2213,44 @@ yyreduce:
     }
     break;
 
-  case 45:
+  case 49:
 
 /* Line 1269 of yacc.c  */
-#line 337 "parse-gram.y"
+#line 345 "parse-gram.y"
     { current_class = nterm_sym; }
     break;
 
-  case 46:
+  case 50:
 
 /* Line 1269 of yacc.c  */
-#line 338 "parse-gram.y"
+#line 346 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
     break;
 
-  case 47:
+  case 51:
 
 /* Line 1269 of yacc.c  */
-#line 342 "parse-gram.y"
+#line 350 "parse-gram.y"
     { current_class = token_sym; }
     break;
 
-  case 48:
+  case 52:
 
 /* Line 1269 of yacc.c  */
-#line 343 "parse-gram.y"
+#line 351 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
     break;
 
-  case 49:
+  case 53:
 
 /* Line 1269 of yacc.c  */
-#line 348 "parse-gram.y"
+#line 356 "parse-gram.y"
     {
       symbol_list *list;
       tag_seen = true;
@@ -2225,10 +2260,10 @@ yyreduce:
     }
     break;
 
-  case 50:
+  case 54:
 
 /* Line 1269 of yacc.c  */
-#line 359 "parse-gram.y"
+#line 367 "parse-gram.y"
     {
       symbol_list *list;
       ++current_prec;
@@ -2242,121 +2277,121 @@ yyreduce:
     }
     break;
 
-  case 51:
+  case 55:
 
 /* Line 1269 of yacc.c  */
-#line 373 "parse-gram.y"
+#line 381 "parse-gram.y"
     { (yyval.assoc) = left_assoc; }
     break;
 
-  case 52:
+  case 56:
 
 /* Line 1269 of yacc.c  */
-#line 374 "parse-gram.y"
+#line 382 "parse-gram.y"
     { (yyval.assoc) = right_assoc; }
     break;
 
-  case 53:
+  case 57:
 
 /* Line 1269 of yacc.c  */
-#line 375 "parse-gram.y"
+#line 383 "parse-gram.y"
     { (yyval.assoc) = non_assoc; }
     break;
 
-  case 54:
+  case 58:
 
 /* Line 1269 of yacc.c  */
-#line 379 "parse-gram.y"
+#line 387 "parse-gram.y"
     { current_type = NULL; }
     break;
 
-  case 55:
+  case 59:
 
 /* Line 1269 of yacc.c  */
-#line 380 "parse-gram.y"
+#line 388 "parse-gram.y"
     { current_type = (yyvsp[(1) - (1)].uniqstr); tag_seen = true; }
     break;
 
-  case 56:
+  case 60:
 
 /* Line 1269 of yacc.c  */
-#line 386 "parse-gram.y"
+#line 394 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
-  case 57:
+  case 61:
 
 /* Line 1269 of yacc.c  */
-#line 388 "parse-gram.y"
+#line 396 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), symbol_list_sym_new ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]))); }
     break;
 
-  case 58:
+  case 62:
 
 /* Line 1269 of yacc.c  */
-#line 392 "parse-gram.y"
+#line 400 "parse-gram.y"
     { (yyval.list) = (yyvsp[(1) - (1)].list); }
     break;
 
-  case 59:
+  case 63:
 
 /* Line 1269 of yacc.c  */
-#line 393 "parse-gram.y"
+#line 401 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), (yyvsp[(2) - (2)].list)); }
     break;
 
-  case 60:
+  case 64:
 
 /* Line 1269 of yacc.c  */
-#line 397 "parse-gram.y"
+#line 405 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
-  case 61:
+  case 65:
 
 /* Line 1269 of yacc.c  */
-#line 398 "parse-gram.y"
+#line 406 "parse-gram.y"
     { (yyval.list) = symbol_list_type_new ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
-  case 62:
+  case 66:
 
 /* Line 1269 of yacc.c  */
-#line 399 "parse-gram.y"
+#line 407 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagged_new ((yylsp[(1) - (1)])); }
     break;
 
-  case 63:
+  case 67:
 
 /* Line 1269 of yacc.c  */
-#line 400 "parse-gram.y"
+#line 408 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagless_new ((yylsp[(1) - (1)])); }
     break;
 
-  case 64:
+  case 68:
 
 /* Line 1269 of yacc.c  */
-#line 406 "parse-gram.y"
+#line 414 "parse-gram.y"
     {
        current_type = (yyvsp[(1) - (1)].uniqstr);
        tag_seen = true;
      }
     break;
 
-  case 65:
+  case 69:
 
 /* Line 1269 of yacc.c  */
-#line 411 "parse-gram.y"
+#line 419 "parse-gram.y"
     {
        symbol_class_set ((yyvsp[(1) - (1)].symbol), current_class, (yylsp[(1) - (1)]), true);
        symbol_type_set ((yyvsp[(1) - (1)].symbol), current_type, (yylsp[(1) - (1)]));
      }
     break;
 
-  case 66:
+  case 70:
 
 /* Line 1269 of yacc.c  */
-#line 416 "parse-gram.y"
+#line 424 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
       symbol_type_set ((yyvsp[(1) - (2)].symbol), current_type, (yylsp[(1) - (2)]));
@@ -2364,10 +2399,10 @@ yyreduce:
     }
     break;
 
-  case 67:
+  case 71:
 
 /* Line 1269 of yacc.c  */
-#line 422 "parse-gram.y"
+#line 430 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
       symbol_type_set ((yyvsp[(1) - (2)].symbol), current_type, (yylsp[(1) - (2)]));
@@ -2375,10 +2410,10 @@ yyreduce:
     }
     break;
 
-  case 68:
+  case 72:
 
 /* Line 1269 of yacc.c  */
-#line 428 "parse-gram.y"
+#line 436 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (3)].symbol), current_class, (yylsp[(1) - (3)]), true);
       symbol_type_set ((yyvsp[(1) - (3)].symbol), current_type, (yylsp[(1) - (3)]));
@@ -2387,109 +2422,109 @@ yyreduce:
     }
     break;
 
-  case 75:
+  case 79:
 
 /* Line 1269 of yacc.c  */
-#line 458 "parse-gram.y"
+#line 466 "parse-gram.y"
     {
       yyerrok;
     }
     break;
 
-  case 76:
+  case 80:
 
 /* Line 1269 of yacc.c  */
-#line 464 "parse-gram.y"
+#line 472 "parse-gram.y"
     { current_lhs = (yyvsp[(1) - (1)].symbol); current_lhs_location = (yylsp[(1) - (1)]); }
     break;
 
-  case 78:
+  case 82:
 
 /* Line 1269 of yacc.c  */
-#line 468 "parse-gram.y"
+#line 476 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(1) - (1)])); }
     break;
 
-  case 79:
+  case 83:
 
 /* Line 1269 of yacc.c  */
-#line 469 "parse-gram.y"
+#line 477 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(3) - (3)])); }
     break;
 
-  case 81:
+  case 85:
 
 /* Line 1269 of yacc.c  */
-#line 475 "parse-gram.y"
+#line 483 "parse-gram.y"
     { grammar_current_rule_begin (current_lhs, current_lhs_location); }
     break;
 
-  case 82:
+  case 86:
 
 /* Line 1269 of yacc.c  */
-#line 477 "parse-gram.y"
+#line 485 "parse-gram.y"
     { grammar_current_rule_symbol_append ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)])); }
     break;
 
-  case 83:
+  case 87:
 
 /* Line 1269 of yacc.c  */
-#line 479 "parse-gram.y"
+#line 487 "parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
     break;
 
-  case 84:
+  case 88:
 
 /* Line 1269 of yacc.c  */
-#line 481 "parse-gram.y"
+#line 489 "parse-gram.y"
     { grammar_current_rule_prec_set ((yyvsp[(3) - (3)].symbol), (yylsp[(3) - (3)])); }
     break;
 
-  case 85:
+  case 89:
 
 /* Line 1269 of yacc.c  */
-#line 483 "parse-gram.y"
+#line 491 "parse-gram.y"
     { grammar_current_rule_dprec_set ((yyvsp[(3) - (3)].integer), (yylsp[(3) - (3)])); }
     break;
 
-  case 86:
+  case 90:
 
 /* Line 1269 of yacc.c  */
-#line 485 "parse-gram.y"
+#line 493 "parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[(3) - (3)].uniqstr), (yylsp[(3) - (3)])); }
     break;
 
-  case 89:
+  case 93:
 
 /* Line 1269 of yacc.c  */
-#line 501 "parse-gram.y"
+#line 509 "parse-gram.y"
     {
       static char one[] = "1";
       (yyval.chars) = one;
     }
     break;
 
-  case 91:
+  case 95:
 
 /* Line 1269 of yacc.c  */
-#line 511 "parse-gram.y"
+#line 519 "parse-gram.y"
     {
       (yyvsp[(1) - (1)].code)[strlen ((yyvsp[(1) - (1)].code)) - 1] = '\n';
       (yyval.chars) = translate_code ((yyvsp[(1) - (1)].code) + 1, (yylsp[(1) - (1)]));
     }
     break;
 
-  case 92:
+  case 96:
 
 /* Line 1269 of yacc.c  */
-#line 527 "parse-gram.y"
+#line 535 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
-  case 93:
+  case 97:
 
 /* Line 1269 of yacc.c  */
-#line 529 "parse-gram.y"
+#line 537 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[(1) - (1)].character)), (yylsp[(1) - (1)]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[(1) - (1)]), false);
@@ -2497,27 +2532,27 @@ yyreduce:
     }
     break;
 
-  case 94:
+  case 98:
 
 /* Line 1269 of yacc.c  */
-#line 537 "parse-gram.y"
+#line 545 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
-  case 97:
+  case 101:
 
 /* Line 1269 of yacc.c  */
-#line 549 "parse-gram.y"
+#line 557 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[(1) - (1)].chars)), (yylsp[(1) - (1)]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[(1) - (1)]), false);
     }
     break;
 
-  case 99:
+  case 103:
 
 /* Line 1269 of yacc.c  */
-#line 558 "parse-gram.y"
+#line 566 "parse-gram.y"
     {
       muscle_code_grow ("epilogue", translate_code ((yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])), (yylsp[(2) - (2)]));
       gram_scanner_last_string_free ();
@@ -2527,7 +2562,7 @@ yyreduce:
 
 
 /* Line 1269 of yacc.c  */
-#line 2531 "parse-gram.c"
+#line 2566 "parse-gram.c"
       default: break;
     }
   YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);
@@ -2746,7 +2781,7 @@ yyreturn:
 
 
 /* Line 1486 of yacc.c  */
-#line 564 "parse-gram.y"
+#line 572 "parse-gram.y"
 
 
 
