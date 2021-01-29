@@ -565,16 +565,16 @@ union yyalloc
 /* YYFINAL -- State number of the termination state.  */
 #define YYFINAL  3
 /* YYLAST -- Last index in YYTABLE.  */
-#define YYLAST   185
+#define YYLAST   158
 
 /* YYNTOKENS -- Number of terminals.  */
 #define YYNTOKENS  59
 /* YYNNTS -- Number of nonterminals.  */
-#define YYNNTS  30
+#define YYNNTS  31
 /* YYNRULES -- Number of rules.  */
-#define YYNRULES  101
+#define YYNRULES  103
 /* YYNRULES -- Number of states.  */
-#define YYNSTATES  139
+#define YYNSTATES  141
 
 /* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
 #define YYUNDEFTOK  2
@@ -634,16 +634,16 @@ static const yytype_uint16 yyprhs[] =
      156,   158,   161,   163,   166,   168,   170,   172,   174,   176,
      178,   181,   184,   188,   190,   193,   195,   198,   200,   203,
      206,   207,   211,   213,   217,   220,   221,   224,   227,   231,
-     235,   239,   240,   242,   244,   246,   248,   250,   252,   254,
-     256,   257
+     235,   239,   241,   243,   244,   246,   248,   250,   252,   254,
+     256,   258,   260,   261
 };
 
 /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
 static const yytype_int8 yyrhs[] =
 {
-      60,     0,    -1,    61,    51,    76,    88,    -1,    -1,    61,
-      62,    -1,    63,    -1,    53,    -1,    17,    -1,    19,     3,
-      82,    -1,    20,    -1,    20,     3,    -1,    21,    -1,    22,
+      60,     0,    -1,    61,    51,    76,    89,    -1,    -1,    61,
+      62,    -1,    63,    -1,    53,    -1,    17,    -1,    19,    82,
+      83,    -1,    20,    -1,    20,     3,    -1,    21,    -1,    22,
        4,    -1,    23,     4,    -1,    24,     3,    -1,    24,    48,
        3,    -1,    25,    -1,    26,    45,    -1,    27,     3,    -1,
       28,    45,    -1,    29,    -1,    30,     3,    -1,    30,    48,
@@ -651,38 +651,39 @@ static const yytype_int8 yyrhs[] =
       48,     3,    -1,    35,    45,    -1,    36,    -1,    37,    -1,
       38,    -1,    39,     3,    -1,    40,     3,    -1,    42,    -1,
       43,    -1,    44,    -1,    54,    -1,    68,    -1,    65,    -1,
-      41,    86,    -1,     8,    45,    72,    -1,     9,    45,    72,
-      -1,    18,    -1,    31,    -1,    16,    83,    -1,    16,     3,
-      83,    -1,    -1,    49,    -1,    58,    64,    45,    -1,    -1,
+      41,    87,    -1,     8,    45,    72,    -1,     9,    45,    72,
+      -1,    18,    -1,    31,    -1,    16,    84,    -1,    16,    49,
+      84,    -1,    -1,    49,    -1,    58,    64,    45,    -1,    -1,
        6,    66,    75,    -1,    -1,     5,    67,    75,    -1,     7,
       55,    71,    -1,    69,    70,    71,    -1,    10,    -1,    11,
-      -1,    12,    -1,    -1,    55,    -1,    86,    -1,    71,    86,
-      -1,    73,    -1,    72,    73,    -1,    86,    -1,    55,    -1,
-      56,    -1,    57,    -1,    55,    -1,    84,    -1,    84,     4,
-      -1,    84,    87,    -1,    84,     4,    87,    -1,    74,    -1,
+      -1,    12,    -1,    -1,    55,    -1,    87,    -1,    71,    87,
+      -1,    73,    -1,    72,    73,    -1,    87,    -1,    55,    -1,
+      56,    -1,    57,    -1,    55,    -1,    85,    -1,    85,     4,
+      -1,    85,    88,    -1,    85,     4,    88,    -1,    74,    -1,
       75,    74,    -1,    77,    -1,    76,    77,    -1,    78,    -1,
-      63,    54,    -1,     1,    54,    -1,    -1,    85,    79,    80,
+      63,    54,    -1,     1,    54,    -1,    -1,    86,    79,    80,
       -1,    81,    -1,    80,    52,    81,    -1,    80,    54,    -1,
-      -1,    81,    86,    -1,    81,    45,    -1,    81,    13,    86,
-      -1,    81,    14,     4,    -1,    81,    15,    55,    -1,    -1,
-       3,    -1,    45,    -1,    49,    -1,    46,    -1,    50,    -1,
-      84,    -1,    87,    -1,     3,    -1,    -1,    51,    47,    -1
+      -1,    81,    87,    -1,    81,    45,    -1,    81,    13,    87,
+      -1,    81,    14,     4,    -1,    81,    15,    55,    -1,    49,
+      -1,     3,    -1,    -1,     3,    -1,    45,    -1,    49,    -1,
+      46,    -1,    50,    -1,    85,    -1,    88,    -1,     3,    -1,
+      -1,    51,    47,    -1
 };
 
 /* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
 static const yytype_uint16 yyrline[] =
 {
-       0,   210,   210,   218,   220,   224,   225,   234,   235,   249,
-     250,   255,   256,   257,   258,   259,   260,   265,   274,   275,
-     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
-     286,   287,   288,   289,   290,   291,   292,   296,   297,   298,
-     302,   309,   316,   320,   324,   329,   352,   353,   357,   386,
-     386,   391,   391,   396,   407,   422,   423,   424,   428,   429,
-     434,   436,   441,   442,   446,   447,   448,   449,   454,   459,
-     464,   470,   476,   487,   488,   497,   498,   504,   505,   506,
-     513,   513,   517,   518,   519,   524,   525,   527,   529,   531,
-     533,   545,   549,   558,   578,   580,   589,   594,   595,   600,
-     607,   609
+       0,   210,   210,   218,   220,   224,   225,   234,   235,   247,
+     248,   253,   254,   255,   256,   257,   258,   263,   272,   273,
+     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
+     284,   285,   286,   287,   288,   289,   290,   294,   295,   296,
+     300,   307,   314,   318,   322,   327,   348,   349,   353,   382,
+     382,   387,   387,   392,   403,   418,   419,   420,   424,   425,
+     430,   432,   437,   438,   442,   443,   444,   445,   450,   455,
+     460,   466,   472,   483,   484,   493,   494,   500,   501,   502,
+     509,   509,   513,   514,   515,   520,   521,   523,   525,   527,
+     529,   539,   540,   546,   550,   559,   579,   581,   590,   595,
+     596,   601,   608,   610
 };
 #endif
 
@@ -711,8 +712,8 @@ static const char *const yytname[] =
   "precedence_declarator", "type.opt", "symbols.1", "generic_symlist",
   "generic_symlist_item", "symbol_def", "symbol_defs.1", "grammar",
   "rules_or_grammar_declaration", "rules", "$@3", "rhses.1", "rhs",
-  "content.opt", "braceless", "id", "id_colon", "symbol", "string_as_id",
-  "epilogue.opt", 0
+  "variable", "content.opt", "braceless", "id", "id_colon", "symbol",
+  "string_as_id", "epilogue.opt", 0
 };
 #endif
 
@@ -742,8 +743,8 @@ static const yytype_uint8 yyr1[] =
       71,    71,    72,    72,    73,    73,    73,    73,    74,    74,
       74,    74,    74,    75,    75,    76,    76,    77,    77,    77,
       79,    78,    80,    80,    80,    81,    81,    81,    81,    81,
-      81,    82,    82,    83,    84,    84,    85,    86,    86,    87,
-      88,    88
+      81,    82,    82,    83,    83,    84,    85,    85,    86,    87,
+      87,    88,    89,    89
 };
 
 /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
@@ -758,8 +759,8 @@ static const yytype_uint8 yyr2[] =
        1,     2,     1,     2,     1,     1,     1,     1,     1,     1,
        2,     2,     3,     1,     2,     1,     2,     1,     2,     2,
        0,     3,     1,     3,     2,     0,     2,     2,     3,     3,
-       3,     0,     1,     1,     1,     1,     1,     1,     1,     1,
-       0,     2
+       3,     1,     1,     0,     1,     1,     1,     1,     1,     1,
+       1,     1,     0,     2
 };
 
 /* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
@@ -772,103 +773,101 @@ static const yytype_uint8 yydefact[] =
        0,    16,     0,     0,     0,    20,     0,    43,    23,    24,
        0,     0,    28,    29,    30,     0,     0,     0,    33,    34,
       35,     0,     6,    36,    46,     4,     5,    38,    37,    58,
-       0,     0,     0,     0,     0,     0,    93,    44,    91,    10,
-      12,    13,    14,     0,    17,    18,    19,    21,     0,    25,
-       0,    27,    31,    32,    99,    95,    94,    97,    39,    98,
-       0,    96,     0,     0,    75,    77,    80,    47,     0,    59,
-       0,    68,    73,    52,    69,    50,    53,    60,    65,    66,
-      67,    40,    62,    64,    41,    45,    92,     8,    15,    22,
-      26,    79,    78,     0,    76,     2,    85,    48,    54,    74,
-      70,    71,    61,    63,   101,    81,    82,    72,    85,    84,
-       0,     0,     0,    87,    86,    83,    88,    89,    90
+       0,     0,     0,     0,     0,    95,     0,    44,    92,    91,
+      93,    10,    12,    13,    14,     0,    17,    18,    19,    21,
+       0,    25,     0,    27,    31,    32,   101,    97,    96,    99,
+      39,   100,     0,    98,     0,     0,    75,    77,    80,    47,
+       0,    59,     0,    68,    73,    52,    69,    50,    53,    60,
+      65,    66,    67,    40,    62,    64,    41,    45,    94,     8,
+      15,    22,    26,    79,    78,     0,    76,     2,    85,    48,
+      54,    74,    70,    71,    61,    63,   103,    81,    82,    72,
+      85,    84,     0,     0,     0,    87,    86,    83,    88,    89,
+      90
 };
 
 /* YYDEFGOTO[NTERM-NUM].  */
-static const yytype_int8 yydefgoto[] =
+static const yytype_int16 yydefgoto[] =
 {
-      -1,     1,     2,    45,    82,    88,    47,    51,    50,    48,
-      49,    90,    96,   101,   102,    92,    93,    83,    84,    85,
-     116,   125,   126,   107,    57,    77,    86,   103,    79,   115
+      -1,     1,     2,    45,    84,    90,    47,    51,    50,    48,
+      49,    92,    98,   103,   104,    94,    95,    85,    86,    87,
+     118,   127,   128,    60,   109,    57,    79,    88,   105,    81,
+     117
 };
 
 /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
    STATE-NUM.  */
-#define YYPACT_NINF -93
+#define YYPACT_NINF -79
 static const yytype_int16 yypact[] =
 {
-     -93,     8,    94,   -93,   -93,   -93,   -41,   -20,    -6,   -93,
-     -93,   -93,     4,   -93,   -93,    42,    54,   -93,    56,    64,
-       2,   -93,    28,    71,    34,   -93,     3,   -93,   -93,   -93,
-       6,    35,   -93,   -93,   -93,    79,    81,    -2,   -93,   -93,
-     -93,    25,   -93,   -93,    36,   -93,   -93,   -93,   -93,    31,
-       9,     9,    -2,    21,    21,    43,   -93,   -93,    84,   -93,
-     -93,   -93,   -93,    87,   -93,   -93,   -93,   -93,    88,   -93,
-      89,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,
-      40,   -93,    41,    11,   -93,   -93,   -93,   -93,    51,   -93,
-      -2,   -93,   -93,     9,    68,     9,    -2,   -93,   -93,   -93,
-     -93,    21,   -93,   -93,    21,   -93,   -93,   -93,   -93,   -93,
-     -93,   -93,   -93,    50,   -93,   -93,   -93,   -93,    -2,   -93,
-     104,   -93,   -93,   -93,   -93,   -14,   136,   -93,   -93,   -93,
-      -2,   105,    53,   -93,   -93,   136,   -93,   -93,   -93
+     -79,     5,    96,   -79,   -79,   -79,     3,    17,    18,   -79,
+     -79,   -79,    -8,   -79,   -79,    27,    61,   -79,    65,    73,
+      31,   -79,    41,    75,    43,   -79,    32,   -79,   -79,   -79,
+      33,    44,   -79,   -79,   -79,    87,    89,    26,   -79,   -79,
+     -79,    15,   -79,   -79,    45,   -79,   -79,   -79,   -79,    42,
+      38,    38,    26,    11,    11,   -79,    51,   -79,   -79,   -79,
+      95,   -79,   -79,   -79,   -79,   106,   -79,   -79,   -79,   -79,
+     107,   -79,   108,   -79,   -79,   -79,   -79,   -79,   -79,   -79,
+     -79,   -79,    88,   -79,    90,     1,   -79,   -79,   -79,   -79,
+      54,   -79,    26,   -79,   -79,    38,    50,    38,    26,   -79,
+     -79,   -79,   -79,    11,   -79,   -79,    11,   -79,   -79,   -79,
+     -79,   -79,   -79,   -79,   -79,    94,   -79,   -79,   -79,   -79,
+      26,   -79,   140,   -79,   -79,   -79,   -79,    -9,    25,   -79,
+     -79,   -79,    26,   141,    91,   -79,   -79,    25,   -79,   -79,
+     -79
 };
 
 /* YYPGOTO[NTERM-NUM].  */
 static const yytype_int16 yypgoto[] =
 {
-     -93,   -93,   -93,   -93,   138,   -93,   -93,   -93,   -93,   -93,
-     -93,   -93,    52,    90,   -91,   -30,    92,   -93,    58,   -93,
-     -93,   -93,    18,   -93,    98,   -47,   -93,   -37,   -92,   -93
+     -79,   -79,   -79,   -79,   146,   -79,   -79,   -79,   -79,   -79,
+     -79,   -79,    59,    98,   -21,   -48,   102,   -79,    70,   -79,
+     -79,   -79,    28,   -79,   -79,   100,   -47,   -79,   -37,   -78,
+     -79
 };
 
 /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
    positive, shift that token.  If negative, reduce the rule which
    number is the opposite.  If zero, do what YYDEFACT says.
    If YYTABLE_NINF, syntax error.  */
-#define YYTABLE_NINF -101
+#define YYTABLE_NINF -103
 static const yytype_int16 yytable[] =
 {
-      78,    74,   121,    94,    94,    62,    67,    55,     3,    69,
-     123,  -100,    80,   123,    52,    97,     4,     5,     6,     7,
-       8,     9,    10,    11,    74,    53,    80,    12,   127,    14,
-       4,     5,     6,     7,     8,     9,    10,    11,   128,    54,
-     129,    12,    27,    14,    75,    58,    94,    76,    94,    56,
-      63,    68,    37,    97,    70,    75,    27,    59,    76,   122,
-      60,    81,   113,   119,    91,   119,    37,    75,    61,    44,
-      76,    74,   120,    64,    65,    81,    98,    99,   100,    66,
-      71,   122,    72,    44,    73,    87,    89,   106,    56,   134,
-     108,   109,   110,   136,   111,   112,   117,   124,   134,     4,
-       5,     6,     7,     8,     9,    10,    11,    74,   138,   137,
-      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
-      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
-      32,    33,    34,    35,    36,    37,    38,    39,    40,    74,
-      46,   114,   118,    95,   104,    41,   135,    42,    43,   130,
-     131,   132,    44,   105,     0,     0,     0,     0,     0,     0,
-       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
-       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
-       0,   133,    75,     0,     0,    76
+      80,  -102,    82,    96,    96,     3,     4,     5,     6,     7,
+       8,     9,    10,    11,    76,    99,    82,    12,   123,    14,
+       4,     5,     6,     7,     8,     9,    10,    11,    76,    76,
+      58,    12,    27,    14,    64,    69,    71,    55,   132,   133,
+     134,    56,    37,   130,   129,   131,    27,   121,    96,   121,
+      96,    83,   115,    76,   122,    99,    37,    77,    52,    44,
+      78,   124,    53,    54,    61,    83,   100,   101,   102,    62,
+     135,    77,    77,    44,    78,    78,    59,    63,    67,    65,
+      70,    72,   125,   124,    77,   125,    66,    78,    68,    73,
+      74,   136,    75,    93,    89,   138,    55,    91,   108,   119,
+     136,     4,     5,     6,     7,     8,     9,    10,    11,   110,
+     111,   112,    12,    13,    14,    15,    16,    17,    18,    19,
+      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
+      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
+      40,   126,   113,    76,   114,   139,   140,    41,    46,    42,
+      43,   120,   106,    97,    44,   116,   107,     0,   137
 };
 
 static const yytype_int16 yycheck[] =
 {
-      37,     3,    94,    50,    51,     3,     3,     3,     0,     3,
-     101,     0,     1,   104,    55,    52,     5,     6,     7,     8,
-       9,    10,    11,    12,     3,    45,     1,    16,   120,    18,
-       5,     6,     7,     8,     9,    10,    11,    12,    52,    45,
-      54,    16,    31,    18,    46,     3,    93,    49,    95,    45,
-      48,    48,    41,    90,    48,    46,    31,     3,    49,    96,
-       4,    50,    51,    93,    55,    95,    41,    46,     4,    58,
-      49,     3,     4,    45,     3,    50,    55,    56,    57,    45,
-      45,   118,     3,    58,     3,    49,    55,     3,    45,   126,
-       3,     3,     3,   130,    54,    54,    45,    47,   135,     5,
-       6,     7,     8,     9,    10,    11,    12,     3,    55,     4,
-      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
-      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
-      36,    37,    38,    39,    40,    41,    42,    43,    44,     3,
-       2,    83,    90,    51,    54,    51,   128,    53,    54,    13,
-      14,    15,    58,    55,    -1,    -1,    -1,    -1,    -1,    -1,
-      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
-      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
-      -1,    45,    46,    -1,    -1,    49
+      37,     0,     1,    50,    51,     0,     5,     6,     7,     8,
+       9,    10,    11,    12,     3,    52,     1,    16,    96,    18,
+       5,     6,     7,     8,     9,    10,    11,    12,     3,     3,
+       3,    16,    31,    18,     3,     3,     3,    45,    13,    14,
+      15,    49,    41,    52,   122,    54,    31,    95,    95,    97,
+      97,    50,    51,     3,     4,    92,    41,    46,    55,    58,
+      49,    98,    45,    45,     3,    50,    55,    56,    57,     4,
+      45,    46,    46,    58,    49,    49,    49,     4,     3,    48,
+      48,    48,   103,   120,    46,   106,    45,    49,    45,    45,
+       3,   128,     3,    55,    49,   132,    45,    55,     3,    45,
+     137,     5,     6,     7,     8,     9,    10,    11,    12,     3,
+       3,     3,    16,    17,    18,    19,    20,    21,    22,    23,
+      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
+      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
+      44,    47,    54,     3,    54,     4,    55,    51,     2,    53,
+      54,    92,    54,    51,    58,    85,    56,    -1,   130
 };
 
 /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
@@ -880,15 +879,16 @@ static const yytype_uint8 yystos[] =
       24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
       34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
       44,    51,    53,    54,    58,    62,    63,    65,    68,    69,
-      67,    66,    55,    45,    45,     3,    45,    83,     3,     3,
-       4,     4,     3,    48,    45,     3,    45,     3,    48,     3,
-      48,    45,     3,     3,     3,    46,    49,    84,    86,    87,
-       1,    50,    63,    76,    77,    78,    85,    49,    64,    55,
-      70,    55,    74,    75,    84,    75,    71,    86,    55,    56,
-      57,    72,    73,    86,    72,    83,     3,    82,     3,     3,
-       3,    54,    54,    51,    77,    88,    79,    45,    71,    74,
-       4,    87,    86,    73,    47,    80,    81,    87,    52,    54,
-      13,    14,    15,    45,    86,    81,    86,     4,    55
+      67,    66,    55,    45,    45,    45,    49,    84,     3,    49,
+      82,     3,     4,     4,     3,    48,    45,     3,    45,     3,
+      48,     3,    48,    45,     3,     3,     3,    46,    49,    85,
+      87,    88,     1,    50,    63,    76,    77,    78,    86,    49,
+      64,    55,    70,    55,    74,    75,    85,    75,    71,    87,
+      55,    56,    57,    72,    73,    87,    72,    84,     3,    83,
+       3,     3,     3,    54,    54,    51,    77,    89,    79,    45,
+      71,    74,     4,    88,    87,    73,    47,    80,    81,    88,
+      52,    54,    13,    14,    15,    45,    87,    81,    87,     4,
+      55
 };
 
 #define yyerrok		(yyerrstatus = 0)
@@ -1117,16 +1117,16 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 /* Line 1535 of yacc.c  */
 #line 1119 "parse-gram.c"
 	break;
-      case 82: /* "content.opt" */
+      case 82: /* "variable" */
 
 /* Line 1535 of yacc.c  */
-#line 190 "parse-gram.y"
-	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
+#line 195 "parse-gram.y"
+	{ fputs ((yyvaluep->uniqstr), stderr); };
 
 /* Line 1535 of yacc.c  */
 #line 1128 "parse-gram.c"
 	break;
-      case 83: /* "braceless" */
+      case 83: /* "content.opt" */
 
 /* Line 1535 of yacc.c  */
 #line 190 "parse-gram.y"
@@ -1135,41 +1135,50 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 /* Line 1535 of yacc.c  */
 #line 1137 "parse-gram.c"
 	break;
-      case 84: /* "id" */
+      case 84: /* "braceless" */
+
+/* Line 1535 of yacc.c  */
+#line 190 "parse-gram.y"
+	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
+
+/* Line 1535 of yacc.c  */
+#line 1146 "parse-gram.c"
+	break;
+      case 85: /* "id" */
 
 /* Line 1535 of yacc.c  */
 #line 202 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
 /* Line 1535 of yacc.c  */
-#line 1146 "parse-gram.c"
+#line 1155 "parse-gram.c"
 	break;
-      case 85: /* "id_colon" */
+      case 86: /* "id_colon" */
 
 /* Line 1535 of yacc.c  */
 #line 203 "parse-gram.y"
 	{ fprintf (stderr, "%s:", (yyvaluep->symbol)->tag); };
 
 /* Line 1535 of yacc.c  */
-#line 1155 "parse-gram.c"
+#line 1164 "parse-gram.c"
 	break;
-      case 86: /* "symbol" */
+      case 87: /* "symbol" */
 
 /* Line 1535 of yacc.c  */
 #line 202 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
 /* Line 1535 of yacc.c  */
-#line 1164 "parse-gram.c"
+#line 1173 "parse-gram.c"
 	break;
-      case 87: /* "string_as_id" */
+      case 88: /* "string_as_id" */
 
 /* Line 1535 of yacc.c  */
 #line 202 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
 /* Line 1535 of yacc.c  */
-#line 1173 "parse-gram.c"
+#line 1182 "parse-gram.c"
 	break;
       default:
 	break;
@@ -1693,7 +1702,7 @@ YYLTYPE yylloc;
 }
 
 /* Line 1535 of yacc.c  */
-#line 1697 "parse-gram.c"
+#line 1706 "parse-gram.c"
   yylsp[0] = yylloc;
   goto yysetstate;
 
@@ -1902,31 +1911,29 @@ yyreduce:
 /* Line 1535 of yacc.c  */
 #line 236 "parse-gram.y"
     {
-      /* FIXME: Special characters in $2 may break %define.
-         For example: `['.  */
       char const name_prefix[] = "percent_define_";
-      char *name = xmalloc (sizeof name_prefix + strlen ((yyvsp[(2) - (3)].chars)));
+      char *name = xmalloc (sizeof name_prefix + strlen ((yyvsp[(2) - (3)].uniqstr)));
       strcpy (name, name_prefix);
-      strcpy (name + sizeof name_prefix - 1, (yyvsp[(2) - (3)].chars));
+      strcpy (name + sizeof name_prefix - 1, (yyvsp[(2) - (3)].uniqstr));
       if (muscle_find_const (name))
-        warn_at ((yylsp[(2) - (3)]), _("%s `%s' redefined"), "%define variable", (yyvsp[(2) - (3)].chars));
+        warn_at ((yylsp[(2) - (3)]), _("%s `%s' redefined"), "%define variable", (yyvsp[(2) - (3)].uniqstr));
       MUSCLE_INSERT_STRING (uniqstr_new (name), (yyvsp[(3) - (3)].chars));
       free (name);
-      muscle_grow_user_name_list ("user_percent_define_variables", (yyvsp[(2) - (3)].chars), (yylsp[(2) - (3)]));
+      muscle_grow_user_name_list ("user_percent_define_variables", (yyvsp[(2) - (3)].uniqstr), (yylsp[(2) - (3)]));
     }
     break;
 
   case 9:
 
 /* Line 1535 of yacc.c  */
-#line 249 "parse-gram.y"
+#line 247 "parse-gram.y"
     { defines_flag = true; }
     break;
 
   case 10:
 
 /* Line 1535 of yacc.c  */
-#line 251 "parse-gram.y"
+#line 249 "parse-gram.y"
     {
       defines_flag = true;
       spec_defines_file = xstrdup ((yyvsp[(2) - (2)].chars));
@@ -1936,42 +1943,42 @@ yyreduce:
   case 11:
 
 /* Line 1535 of yacc.c  */
-#line 255 "parse-gram.y"
+#line 253 "parse-gram.y"
     { error_verbose = true; }
     break;
 
   case 12:
 
 /* Line 1535 of yacc.c  */
-#line 256 "parse-gram.y"
+#line 254 "parse-gram.y"
     { expected_sr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 13:
 
 /* Line 1535 of yacc.c  */
-#line 257 "parse-gram.y"
+#line 255 "parse-gram.y"
     { expected_rr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 14:
 
 /* Line 1535 of yacc.c  */
-#line 258 "parse-gram.y"
+#line 256 "parse-gram.y"
     { spec_file_prefix = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 15:
 
 /* Line 1535 of yacc.c  */
-#line 259 "parse-gram.y"
+#line 257 "parse-gram.y"
     { spec_file_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 16:
 
 /* Line 1535 of yacc.c  */
-#line 261 "parse-gram.y"
+#line 259 "parse-gram.y"
     {
       nondeterministic_parser = true;
       glr_parser = true;
@@ -1981,7 +1988,7 @@ yyreduce:
   case 17:
 
 /* Line 1535 of yacc.c  */
-#line 266 "parse-gram.y"
+#line 264 "parse-gram.y"
     {
       code_props action;
       code_props_symbol_action_init (&action, (yyvsp[(2) - (2)].code), (yylsp[(2) - (2)]));
@@ -1995,133 +2002,133 @@ yyreduce:
   case 18:
 
 /* Line 1535 of yacc.c  */
-#line 274 "parse-gram.y"
+#line 272 "parse-gram.y"
     { language_argmatch ((yyvsp[(2) - (2)].chars), 1, &(yylsp[(1) - (2)])); }
     break;
 
   case 19:
 
 /* Line 1535 of yacc.c  */
-#line 275 "parse-gram.y"
+#line 273 "parse-gram.y"
     { add_param ("lex_param", (yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
     break;
 
   case 20:
 
 /* Line 1535 of yacc.c  */
-#line 276 "parse-gram.y"
+#line 274 "parse-gram.y"
     { locations_flag = true; }
     break;
 
   case 21:
 
 /* Line 1535 of yacc.c  */
-#line 277 "parse-gram.y"
+#line 275 "parse-gram.y"
     { spec_name_prefix = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 22:
 
 /* Line 1535 of yacc.c  */
-#line 278 "parse-gram.y"
+#line 276 "parse-gram.y"
     { spec_name_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 23:
 
 /* Line 1535 of yacc.c  */
-#line 279 "parse-gram.y"
+#line 277 "parse-gram.y"
     { no_lines_flag = true; }
     break;
 
   case 24:
 
 /* Line 1535 of yacc.c  */
-#line 280 "parse-gram.y"
+#line 278 "parse-gram.y"
     { nondeterministic_parser = true; }
     break;
 
   case 25:
 
 /* Line 1535 of yacc.c  */
-#line 281 "parse-gram.y"
+#line 279 "parse-gram.y"
     { spec_outfile = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 26:
 
 /* Line 1535 of yacc.c  */
-#line 282 "parse-gram.y"
+#line 280 "parse-gram.y"
     { spec_outfile = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 27:
 
 /* Line 1535 of yacc.c  */
-#line 283 "parse-gram.y"
+#line 281 "parse-gram.y"
     { add_param ("parse_param", (yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
     break;
 
   case 28:
 
 /* Line 1535 of yacc.c  */
-#line 284 "parse-gram.y"
+#line 282 "parse-gram.y"
     { pure_parser = true; }
     break;
 
   case 29:
 
 /* Line 1535 of yacc.c  */
-#line 285 "parse-gram.y"
+#line 283 "parse-gram.y"
     { push_parser = true; pull_parser = false; }
     break;
 
   case 30:
 
 /* Line 1535 of yacc.c  */
-#line 286 "parse-gram.y"
+#line 284 "parse-gram.y"
     { push_parser = true; pull_parser = true; }
     break;
 
   case 31:
 
 /* Line 1535 of yacc.c  */
-#line 287 "parse-gram.y"
+#line 285 "parse-gram.y"
     { version_check (&(yylsp[(2) - (2)]), (yyvsp[(2) - (2)].chars)); }
     break;
 
   case 32:
 
 /* Line 1535 of yacc.c  */
-#line 288 "parse-gram.y"
+#line 286 "parse-gram.y"
     { skeleton_arg ((yyvsp[(2) - (2)].chars), 1, &(yylsp[(1) - (2)])); }
     break;
 
   case 33:
 
 /* Line 1535 of yacc.c  */
-#line 289 "parse-gram.y"
+#line 287 "parse-gram.y"
     { token_table_flag = true; }
     break;
 
   case 34:
 
 /* Line 1535 of yacc.c  */
-#line 290 "parse-gram.y"
+#line 288 "parse-gram.y"
     { report_flag = report_states; }
     break;
 
   case 35:
 
 /* Line 1535 of yacc.c  */
-#line 291 "parse-gram.y"
+#line 289 "parse-gram.y"
     { yacc_flag = true; }
     break;
 
   case 39:
 
 /* Line 1535 of yacc.c  */
-#line 299 "parse-gram.y"
+#line 297 "parse-gram.y"
     {
       grammar_start_symbol_set ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]));
     }
@@ -2130,7 +2137,7 @@ yyreduce:
   case 40:
 
 /* Line 1535 of yacc.c  */
-#line 303 "parse-gram.y"
+#line 301 "parse-gram.y"
     {
       symbol_list *list;
       for (list = (yyvsp[(3) - (3)].list); list; list = list->next)
@@ -2142,7 +2149,7 @@ yyreduce:
   case 41:
 
 /* Line 1535 of yacc.c  */
-#line 310 "parse-gram.y"
+#line 308 "parse-gram.y"
     {
       symbol_list *list;
       for (list = (yyvsp[(3) - (3)].list); list; list = list->next)
@@ -2154,7 +2161,7 @@ yyreduce:
   case 42:
 
 /* Line 1535 of yacc.c  */
-#line 317 "parse-gram.y"
+#line 315 "parse-gram.y"
     {
       default_prec = true;
     }
@@ -2163,7 +2170,7 @@ yyreduce:
   case 43:
 
 /* Line 1535 of yacc.c  */
-#line 321 "parse-gram.y"
+#line 319 "parse-gram.y"
     {
       default_prec = false;
     }
@@ -2172,7 +2179,7 @@ yyreduce:
   case 44:
 
 /* Line 1535 of yacc.c  */
-#line 325 "parse-gram.y"
+#line 323 "parse-gram.y"
     {
       muscle_code_grow ("percent_code", (yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)]));
       code_scanner_last_string_free ();
@@ -2182,39 +2189,37 @@ yyreduce:
   case 45:
 
 /* Line 1535 of yacc.c  */
-#line 330 "parse-gram.y"
+#line 328 "parse-gram.y"
     {
-      /* FIXME: Special characters in $2 may break %code.
-         For example: `['.  */
       char const name_prefix[] = "percent_code_";
-      char *name = xmalloc (sizeof name_prefix + strlen ((yyvsp[(2) - (3)].chars)));
+      char *name = xmalloc (sizeof name_prefix + strlen ((yyvsp[(2) - (3)].uniqstr)));
       strcpy (name, name_prefix);
-      strcpy (name + sizeof name_prefix - 1, (yyvsp[(2) - (3)].chars));
+      strcpy (name + sizeof name_prefix - 1, (yyvsp[(2) - (3)].uniqstr));
       muscle_code_grow (uniqstr_new (name), (yyvsp[(3) - (3)].chars), (yylsp[(3) - (3)]));
       free (name);
       code_scanner_last_string_free ();
-      muscle_grow_user_name_list ("user_percent_code_qualifiers", (yyvsp[(2) - (3)].chars), (yylsp[(2) - (3)]));
+      muscle_grow_user_name_list ("user_percent_code_qualifiers", (yyvsp[(2) - (3)].uniqstr), (yylsp[(2) - (3)]));
     }
     break;
 
   case 46:
 
 /* Line 1535 of yacc.c  */
-#line 352 "parse-gram.y"
+#line 348 "parse-gram.y"
     {}
     break;
 
   case 47:
 
 /* Line 1535 of yacc.c  */
-#line 353 "parse-gram.y"
+#line 349 "parse-gram.y"
     { muscle_code_grow ("union_name", (yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 48:
 
 /* Line 1535 of yacc.c  */
-#line 358 "parse-gram.y"
+#line 354 "parse-gram.y"
     {
       char const *body = (yyvsp[(3) - (3)].code);
 
@@ -2242,14 +2247,14 @@ yyreduce:
   case 49:
 
 /* Line 1535 of yacc.c  */
-#line 386 "parse-gram.y"
+#line 382 "parse-gram.y"
     { current_class = nterm_sym; }
     break;
 
   case 50:
 
 /* Line 1535 of yacc.c  */
-#line 387 "parse-gram.y"
+#line 383 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
@@ -2259,14 +2264,14 @@ yyreduce:
   case 51:
 
 /* Line 1535 of yacc.c  */
-#line 391 "parse-gram.y"
+#line 387 "parse-gram.y"
     { current_class = token_sym; }
     break;
 
   case 52:
 
 /* Line 1535 of yacc.c  */
-#line 392 "parse-gram.y"
+#line 388 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
@@ -2276,7 +2281,7 @@ yyreduce:
   case 53:
 
 /* Line 1535 of yacc.c  */
-#line 397 "parse-gram.y"
+#line 393 "parse-gram.y"
     {
       symbol_list *list;
       tag_seen = true;
@@ -2289,7 +2294,7 @@ yyreduce:
   case 54:
 
 /* Line 1535 of yacc.c  */
-#line 408 "parse-gram.y"
+#line 404 "parse-gram.y"
     {
       symbol_list *list;
       ++current_prec;
@@ -2306,98 +2311,98 @@ yyreduce:
   case 55:
 
 /* Line 1535 of yacc.c  */
-#line 422 "parse-gram.y"
+#line 418 "parse-gram.y"
     { (yyval.assoc) = left_assoc; }
     break;
 
   case 56:
 
 /* Line 1535 of yacc.c  */
-#line 423 "parse-gram.y"
+#line 419 "parse-gram.y"
     { (yyval.assoc) = right_assoc; }
     break;
 
   case 57:
 
 /* Line 1535 of yacc.c  */
-#line 424 "parse-gram.y"
+#line 420 "parse-gram.y"
     { (yyval.assoc) = non_assoc; }
     break;
 
   case 58:
 
 /* Line 1535 of yacc.c  */
-#line 428 "parse-gram.y"
+#line 424 "parse-gram.y"
     { current_type = NULL; }
     break;
 
   case 59:
 
 /* Line 1535 of yacc.c  */
-#line 429 "parse-gram.y"
+#line 425 "parse-gram.y"
     { current_type = (yyvsp[(1) - (1)].uniqstr); tag_seen = true; }
     break;
 
   case 60:
 
 /* Line 1535 of yacc.c  */
-#line 435 "parse-gram.y"
+#line 431 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 61:
 
 /* Line 1535 of yacc.c  */
-#line 437 "parse-gram.y"
+#line 433 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), symbol_list_sym_new ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]))); }
     break;
 
   case 62:
 
 /* Line 1535 of yacc.c  */
-#line 441 "parse-gram.y"
+#line 437 "parse-gram.y"
     { (yyval.list) = (yyvsp[(1) - (1)].list); }
     break;
 
   case 63:
 
 /* Line 1535 of yacc.c  */
-#line 442 "parse-gram.y"
+#line 438 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), (yyvsp[(2) - (2)].list)); }
     break;
 
   case 64:
 
 /* Line 1535 of yacc.c  */
-#line 446 "parse-gram.y"
+#line 442 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 65:
 
 /* Line 1535 of yacc.c  */
-#line 447 "parse-gram.y"
+#line 443 "parse-gram.y"
     { (yyval.list) = symbol_list_type_new ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 66:
 
 /* Line 1535 of yacc.c  */
-#line 448 "parse-gram.y"
+#line 444 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagged_new ((yylsp[(1) - (1)])); }
     break;
 
   case 67:
 
 /* Line 1535 of yacc.c  */
-#line 449 "parse-gram.y"
+#line 445 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagless_new ((yylsp[(1) - (1)])); }
     break;
 
   case 68:
 
 /* Line 1535 of yacc.c  */
-#line 455 "parse-gram.y"
+#line 451 "parse-gram.y"
     {
        current_type = (yyvsp[(1) - (1)].uniqstr);
        tag_seen = true;
@@ -2407,7 +2412,7 @@ yyreduce:
   case 69:
 
 /* Line 1535 of yacc.c  */
-#line 460 "parse-gram.y"
+#line 456 "parse-gram.y"
     {
        symbol_class_set ((yyvsp[(1) - (1)].symbol), current_class, (yylsp[(1) - (1)]), true);
        symbol_type_set ((yyvsp[(1) - (1)].symbol), current_type, (yylsp[(1) - (1)]));
@@ -2417,7 +2422,7 @@ yyreduce:
   case 70:
 
 /* Line 1535 of yacc.c  */
-#line 465 "parse-gram.y"
+#line 461 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
       symbol_type_set ((yyvsp[(1) - (2)].symbol), current_type, (yylsp[(1) - (2)]));
@@ -2428,7 +2433,7 @@ yyreduce:
   case 71:
 
 /* Line 1535 of yacc.c  */
-#line 471 "parse-gram.y"
+#line 467 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
       symbol_type_set ((yyvsp[(1) - (2)].symbol), current_type, (yylsp[(1) - (2)]));
@@ -2439,7 +2444,7 @@ yyreduce:
   case 72:
 
 /* Line 1535 of yacc.c  */
-#line 477 "parse-gram.y"
+#line 473 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (3)].symbol), current_class, (yylsp[(1) - (3)]), true);
       symbol_type_set ((yyvsp[(1) - (3)].symbol), current_type, (yylsp[(1) - (3)]));
@@ -2451,7 +2456,7 @@ yyreduce:
   case 79:
 
 /* Line 1535 of yacc.c  */
-#line 507 "parse-gram.y"
+#line 503 "parse-gram.y"
     {
       yyerrok;
     }
@@ -2460,80 +2465,87 @@ yyreduce:
   case 80:
 
 /* Line 1535 of yacc.c  */
-#line 513 "parse-gram.y"
+#line 509 "parse-gram.y"
     { current_lhs = (yyvsp[(1) - (1)].symbol); current_lhs_location = (yylsp[(1) - (1)]); }
     break;
 
   case 82:
 
 /* Line 1535 of yacc.c  */
-#line 517 "parse-gram.y"
+#line 513 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(1) - (1)])); }
     break;
 
   case 83:
 
 /* Line 1535 of yacc.c  */
-#line 518 "parse-gram.y"
+#line 514 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(3) - (3)])); }
     break;
 
   case 85:
 
 /* Line 1535 of yacc.c  */
-#line 524 "parse-gram.y"
+#line 520 "parse-gram.y"
     { grammar_current_rule_begin (current_lhs, current_lhs_location); }
     break;
 
   case 86:
 
 /* Line 1535 of yacc.c  */
-#line 526 "parse-gram.y"
+#line 522 "parse-gram.y"
     { grammar_current_rule_symbol_append ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)])); }
     break;
 
   case 87:
 
 /* Line 1535 of yacc.c  */
-#line 528 "parse-gram.y"
+#line 524 "parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
     break;
 
   case 88:
 
 /* Line 1535 of yacc.c  */
-#line 530 "parse-gram.y"
+#line 526 "parse-gram.y"
     { grammar_current_rule_prec_set ((yyvsp[(3) - (3)].symbol), (yylsp[(3) - (3)])); }
     break;
 
   case 89:
 
 /* Line 1535 of yacc.c  */
-#line 532 "parse-gram.y"
+#line 528 "parse-gram.y"
     { grammar_current_rule_dprec_set ((yyvsp[(3) - (3)].integer), (yylsp[(3) - (3)])); }
     break;
 
   case 90:
 
 /* Line 1535 of yacc.c  */
-#line 534 "parse-gram.y"
+#line 530 "parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[(3) - (3)].uniqstr), (yylsp[(3) - (3)])); }
     break;
 
-  case 91:
+  case 92:
 
 /* Line 1535 of yacc.c  */
-#line 545 "parse-gram.y"
+#line 540 "parse-gram.y"
+    { (yyval.uniqstr) = uniqstr_new ((yyvsp[(1) - (1)].chars)); }
+    break;
+
+  case 93:
+
+/* Line 1535 of yacc.c  */
+#line 546 "parse-gram.y"
     {
       static char one[] = "1";
       (yyval.chars) = one;
     }
     break;
 
-  case 93:
+  case 95:
 
 /* Line 1535 of yacc.c  */
-#line 559 "parse-gram.y"
+#line 560 "parse-gram.y"
     {
       code_props plain_code;
       (yyvsp[(1) - (1)].code)[strlen ((yyvsp[(1) - (1)].code)) - 1] = '\n';
@@ -2544,17 +2556,17 @@ yyreduce:
     }
     break;
 
-  case 94:
+  case 96:
 
 /* Line 1535 of yacc.c  */
-#line 579 "parse-gram.y"
+#line 580 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
-  case 95:
+  case 97:
 
 /* Line 1535 of yacc.c  */
-#line 581 "parse-gram.y"
+#line 582 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[(1) - (1)].character)), (yylsp[(1) - (1)]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[(1) - (1)]), false);
@@ -2562,27 +2574,27 @@ yyreduce:
     }
     break;
 
-  case 96:
+  case 98:
 
 /* Line 1535 of yacc.c  */
-#line 589 "parse-gram.y"
+#line 590 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
-  case 99:
+  case 101:
 
 /* Line 1535 of yacc.c  */
-#line 601 "parse-gram.y"
+#line 602 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[(1) - (1)].chars)), (yylsp[(1) - (1)]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[(1) - (1)]), false);
     }
     break;
 
-  case 101:
+  case 103:
 
 /* Line 1535 of yacc.c  */
-#line 610 "parse-gram.y"
+#line 611 "parse-gram.y"
     {
       code_props plain_code;
       code_props_plain_init (&plain_code, (yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)]));
@@ -2596,7 +2608,7 @@ yyreduce:
 
 
 /* Line 1535 of yacc.c  */
-#line 2600 "parse-gram.c"
+#line 2612 "parse-gram.c"
       default: break;
     }
   YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);
@@ -2815,7 +2827,7 @@ yyreturn:
 
 
 /* Line 1535 of yacc.c  */
-#line 620 "parse-gram.y"
+#line 621 "parse-gram.y"
 
 
 
