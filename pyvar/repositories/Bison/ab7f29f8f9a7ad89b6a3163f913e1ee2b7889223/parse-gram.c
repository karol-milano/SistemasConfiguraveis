@@ -73,8 +73,8 @@
 #line 1 "parse-gram.y"
 /* Bison Grammar Parser                             -*- C -*-
 
-   Copyright (C) 2002, 2003, 2004, 2005, 2006, 2007 Free Software Foundation,
-   Inc.
+   Copyright (C) 2002, 2003, 2004, 2005, 2006, 2007, 2008 Free Software
+   Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -552,16 +552,16 @@ union yyalloc
 /* YYFINAL -- State number of the termination state.  */
 #define YYFINAL  3
 /* YYLAST -- Last index in YYTABLE.  */
-#define YYLAST   155
+#define YYLAST   156
 
 /* YYNTOKENS -- Number of terminals.  */
 #define YYNTOKENS  57
 /* YYNNTS -- Number of nonterminals.  */
-#define YYNNTS  31
+#define YYNNTS  33
 /* YYNRULES -- Number of rules.  */
-#define YYNRULES  101
+#define YYNRULES  105
 /* YYNRULES -- Number of states.  */
-#define YYNSTATES  139
+#define YYNSTATES  143
 
 /* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
 #define YYUNDEFTOK  2
@@ -618,42 +618,43 @@ static const yytype_uint16 yyprhs[] =
       81,    84,    86,    88,    90,    92,    94,    96,    99,   103,
      107,   109,   111,   114,   118,   119,   121,   125,   126,   130,
      131,   135,   139,   143,   145,   147,   149,   150,   152,   154,
-     157,   159,   162,   164,   166,   168,   170,   172,   174,   177,
-     180,   184,   186,   189,   191,   194,   196,   199,   202,   203,
-     207,   209,   213,   216,   217,   220,   223,   227,   231,   235,
-     237,   239,   240,   242,   244,   246,   248,   250,   252,   254,
-     256,   257
+     157,   159,   162,   164,   167,   169,   172,   174,   176,   178,
+     180,   182,   184,   187,   190,   194,   196,   199,   201,   204,
+     206,   209,   212,   213,   217,   219,   223,   226,   227,   230,
+     233,   237,   241,   245,   247,   249,   250,   252,   254,   256,
+     258,   260,   262,   264,   266,   267
 };
 
 /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
 static const yytype_int8 yyrhs[] =
 {
-      58,     0,    -1,    59,    49,    74,    87,    -1,    -1,    59,
-      60,    -1,    61,    -1,    51,    -1,    17,    -1,    19,    80,
-      81,    -1,    20,    -1,    20,     3,    -1,    21,    -1,    22,
+      58,     0,    -1,    59,    49,    76,    89,    -1,    -1,    59,
+      60,    -1,    61,    -1,    51,    -1,    17,    -1,    19,    82,
+      83,    -1,    20,    -1,    20,     3,    -1,    21,    -1,    22,
        4,    -1,    23,     4,    -1,    24,     3,    -1,    24,    46,
        3,    -1,    25,    -1,    26,    43,    -1,    27,     3,    -1,
       28,    43,    -1,    29,    -1,    30,     3,    -1,    30,    46,
        3,    -1,    32,    -1,    33,    -1,    34,     3,    -1,    34,
       46,     3,    -1,    35,    43,    -1,    36,    -1,    37,     3,
       -1,    38,     3,    -1,    40,    -1,    41,    -1,    42,    -1,
-      52,    -1,    66,    -1,    63,    -1,    39,    85,    -1,     8,
-      43,    70,    -1,     9,    43,    70,    -1,    18,    -1,    31,
-      -1,    16,    82,    -1,    16,    47,    82,    -1,    -1,    47,
-      -1,    56,    62,    82,    -1,    -1,     6,    64,    73,    -1,
-      -1,     5,    65,    73,    -1,     7,    53,    69,    -1,    67,
+      52,    -1,    66,    -1,    63,    -1,    39,    87,    -1,     8,
+      43,    72,    -1,     9,    43,    72,    -1,    18,    -1,    31,
+      -1,    16,    84,    -1,    16,    47,    84,    -1,    -1,    47,
+      -1,    56,    62,    84,    -1,    -1,     6,    64,    75,    -1,
+      -1,     5,    65,    75,    -1,     7,    53,    71,    -1,    67,
       68,    69,    -1,    10,    -1,    11,    -1,    12,    -1,    -1,
-      53,    -1,    85,    -1,    69,    85,    -1,    71,    -1,    70,
-      71,    -1,    85,    -1,    53,    -1,    54,    -1,    55,    -1,
-      53,    -1,    83,    -1,    83,     4,    -1,    83,    86,    -1,
-      83,     4,    86,    -1,    72,    -1,    73,    72,    -1,    75,
-      -1,    74,    75,    -1,    76,    -1,    61,    52,    -1,     1,
-      52,    -1,    -1,    84,    77,    78,    -1,    79,    -1,    78,
-      50,    79,    -1,    78,    52,    -1,    -1,    79,    85,    -1,
-      79,    43,    -1,    79,    13,    85,    -1,    79,    14,     4,
-      -1,    79,    15,    53,    -1,    47,    -1,     3,    -1,    -1,
+      53,    -1,    70,    -1,    69,    70,    -1,    87,    -1,    87,
+       4,    -1,    87,    -1,    71,    87,    -1,    73,    -1,    72,
+      73,    -1,    87,    -1,    53,    -1,    54,    -1,    55,    -1,
+      53,    -1,    85,    -1,    85,     4,    -1,    85,    88,    -1,
+      85,     4,    88,    -1,    74,    -1,    75,    74,    -1,    77,
+      -1,    76,    77,    -1,    78,    -1,    61,    52,    -1,     1,
+      52,    -1,    -1,    86,    79,    80,    -1,    81,    -1,    80,
+      50,    81,    -1,    80,    52,    -1,    -1,    81,    87,    -1,
+      81,    43,    -1,    81,    13,    87,    -1,    81,    14,     4,
+      -1,    81,    15,    53,    -1,    47,    -1,     3,    -1,    -1,
        3,    -1,    43,    -1,    47,    -1,    44,    -1,    48,    -1,
-      83,    -1,    86,    -1,     3,    -1,    -1,    49,    45,    -1
+      85,    -1,    88,    -1,     3,    -1,    -1,    49,    45,    -1
 };
 
 /* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
@@ -665,11 +666,11 @@ static const yytype_uint16 yyrline[] =
      283,   307,   308,   309,   310,   314,   315,   316,   320,   327,
      334,   338,   342,   349,   364,   365,   369,   381,   381,   386,
      386,   391,   402,   417,   418,   419,   423,   424,   429,   431,
-     436,   437,   441,   442,   443,   444,   449,   454,   459,   465,
-     471,   482,   483,   492,   493,   499,   500,   501,   508,   508,
-     512,   513,   514,   519,   520,   522,   524,   526,   528,   538,
-     539,   545,   548,   557,   577,   579,   588,   593,   594,   599,
-     606,   608
+     436,   437,   442,   444,   449,   450,   454,   455,   456,   457,
+     462,   467,   472,   478,   484,   495,   496,   505,   506,   512,
+     513,   514,   521,   521,   525,   526,   527,   532,   533,   535,
+     537,   539,   541,   551,   552,   558,   561,   570,   590,   592,
+     601,   606,   607,   612,   619,   621
 };
 #endif
 
@@ -695,10 +696,11 @@ static const char *const yytname[] =
   "prologue_declarations", "prologue_declaration", "grammar_declaration",
   "union_name", "symbol_declaration", "$@1", "$@2",
   "precedence_declaration", "precedence_declarator", "type.opt",
-  "symbols.1", "generic_symlist", "generic_symlist_item", "symbol_def",
-  "symbol_defs.1", "grammar", "rules_or_grammar_declaration", "rules",
-  "$@3", "rhses.1", "rhs", "variable", "content.opt", "braceless", "id",
-  "id_colon", "symbol", "string_as_id", "epilogue.opt", 0
+  "symbols.prec", "symbol.prec", "symbols.1", "generic_symlist",
+  "generic_symlist_item", "symbol_def", "symbol_defs.1", "grammar",
+  "rules_or_grammar_declaration", "rules", "$@3", "rhses.1", "rhs",
+  "variable", "content.opt", "braceless", "id", "id_colon", "symbol",
+  "string_as_id", "epilogue.opt", 0
 };
 #endif
 
@@ -725,11 +727,11 @@ static const yytype_uint8 yyr1[] =
       60,    60,    60,    60,    60,    61,    61,    61,    61,    61,
       61,    61,    61,    61,    62,    62,    61,    64,    63,    65,
       63,    63,    66,    67,    67,    67,    68,    68,    69,    69,
-      70,    70,    71,    71,    71,    71,    72,    72,    72,    72,
-      72,    73,    73,    74,    74,    75,    75,    75,    77,    76,
-      78,    78,    78,    79,    79,    79,    79,    79,    79,    80,
-      80,    81,    81,    82,    83,    83,    84,    85,    85,    86,
-      87,    87
+      70,    70,    71,    71,    72,    72,    73,    73,    73,    73,
+      74,    74,    74,    74,    74,    75,    75,    76,    76,    77,
+      77,    77,    79,    78,    80,    80,    80,    81,    81,    81,
+      81,    81,    81,    82,    82,    83,    83,    84,    85,    85,
+      86,    87,    87,    88,    89,    89
 };
 
 /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
@@ -741,11 +743,11 @@ static const yytype_uint8 yyr2[] =
        2,     1,     1,     1,     1,     1,     1,     2,     3,     3,
        1,     1,     2,     3,     0,     1,     3,     0,     3,     0,
        3,     3,     3,     1,     1,     1,     0,     1,     1,     2,
-       1,     2,     1,     1,     1,     1,     1,     1,     2,     2,
-       3,     1,     2,     1,     2,     1,     2,     2,     0,     3,
-       1,     3,     2,     0,     2,     2,     3,     3,     3,     1,
-       1,     0,     1,     1,     1,     1,     1,     1,     1,     1,
-       0,     2
+       1,     2,     1,     2,     1,     2,     1,     1,     1,     1,
+       1,     1,     2,     2,     3,     1,     2,     1,     2,     1,
+       2,     2,     0,     3,     1,     3,     2,     0,     2,     2,
+       3,     3,     3,     1,     1,     0,     1,     1,     1,     1,
+       1,     1,     1,     1,     0,     2
 };
 
 /* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
@@ -758,24 +760,25 @@ static const yytype_uint8 yydefact[] =
        0,    16,     0,     0,     0,    20,     0,    41,    23,    24,
        0,     0,    28,     0,     0,     0,    31,    32,    33,     0,
        6,    34,    44,     4,     5,    36,    35,    56,     0,     0,
-       0,     0,     0,    93,     0,    42,    90,    89,    91,    10,
+       0,     0,     0,    97,     0,    42,    94,    93,    95,    10,
       12,    13,    14,     0,    17,    18,    19,    21,     0,    25,
-       0,    27,    29,    30,    99,    95,    94,    97,    37,    98,
-       0,    96,     0,     0,    73,    75,    78,    45,     0,    57,
-       0,    66,    71,    50,    67,    48,    51,    58,    63,    64,
-      65,    38,    60,    62,    39,    43,    92,     8,    15,    22,
-      26,    77,    76,     0,    74,     2,    83,    46,    52,    72,
-      68,    69,    59,    61,   101,    79,    80,    70,    83,    82,
-       0,     0,     0,    85,    84,    81,    86,    87,    88
+       0,    27,    29,    30,   103,    99,    98,   101,    37,   102,
+       0,   100,     0,     0,    77,    79,    82,    45,     0,    57,
+       0,    70,    75,    50,    71,    48,    51,    62,    67,    68,
+      69,    38,    64,    66,    39,    43,    96,     8,    15,    22,
+      26,    81,    80,     0,    78,     2,    87,    46,    52,    58,
+      60,    76,    72,    73,    63,    65,   105,    83,    84,    59,
+      61,    74,    87,    86,     0,     0,     0,    89,    88,    85,
+      90,    91,    92
 };
 
 /* YYDEFGOTO[NTERM-NUM].  */
-static const yytype_int8 yydefgoto[] =
+static const yytype_int16 yydefgoto[] =
 {
       -1,     1,     2,    43,    82,    88,    45,    49,    48,    46,
-      47,    90,    96,   101,   102,    92,    93,    83,    84,    85,
-     116,   125,   126,    58,   107,    55,    77,    86,   103,    79,
-     115
+      47,    90,   118,   119,    96,   101,   102,    92,    93,    83,
+      84,    85,   116,   127,   128,    58,   107,    55,    77,    86,
+     103,    79,   115
 };
 
 /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
@@ -783,54 +786,55 @@ static const yytype_int8 yydefgoto[] =
 #define YYPACT_NINF -60
 static const yytype_int16 yypact[] =
 {
-     -60,    18,    96,   -60,   -60,   -60,   -16,    17,    24,   -60,
+     -60,    18,   100,   -60,   -60,   -60,   -16,    24,    27,   -60,
      -60,   -60,    -8,   -60,   -60,    11,    70,   -60,    71,    80,
-       2,   -60,    46,    87,    49,   -60,    31,   -60,   -60,   -60,
-      40,    50,   -60,    91,    93,     0,   -60,   -60,   -60,    15,
-     -60,   -60,    51,   -60,   -60,   -60,   -60,    44,    12,    12,
-       0,    25,    25,   -60,    56,   -60,   -60,   -60,   106,   -60,
-     -60,   -60,   -60,   107,   -60,   -60,   -60,   -60,   108,   -60,
-     136,   -60,   -60,   -60,   -60,   -60,   -60,   -60,   -60,   -60,
-      88,   -60,    89,     1,   -60,   -60,   -60,   -60,    56,   -60,
+       2,   -60,    46,    87,    48,   -60,    31,   -60,   -60,   -60,
+      40,    49,   -60,    91,    92,     0,   -60,   -60,   -60,    15,
+     -60,   -60,    50,   -60,   -60,   -60,   -60,    43,    12,    12,
+       0,    25,    25,   -60,    55,   -60,   -60,   -60,    97,   -60,
+     -60,   -60,   -60,    98,   -60,   -60,   -60,   -60,    99,   -60,
+     110,   -60,   -60,   -60,   -60,   -60,   -60,   -60,   -60,   -60,
+      51,   -60,    62,     1,   -60,   -60,   -60,   -60,    55,   -60,
        0,   -60,   -60,    12,    84,    12,     0,   -60,   -60,   -60,
      -60,    25,   -60,   -60,    25,   -60,   -60,   -60,   -60,   -60,
-     -60,   -60,   -60,    97,   -60,   -60,   -60,   -60,     0,   -60,
-     140,   -60,   -60,   -60,   -60,    14,    38,   -60,   -60,   -60,
-       0,   142,    98,   -60,   -60,    38,   -60,   -60,   -60
+     -60,   -60,   -60,   101,   -60,   -60,   -60,   -60,     0,   -60,
+     111,   -60,   140,   -60,   -60,   -60,   -60,    10,    38,   -60,
+     -60,   -60,   -60,   -60,     0,   141,    94,   -60,   -60,    38,
+     -60,   -60,   -60
 };
 
 /* YYPGOTO[NTERM-NUM].  */
 static const yytype_int16 yypgoto[] =
 {
-     -60,   -60,   -60,   -60,   147,   -60,   -60,   -60,   -60,   -60,
-     -60,   -60,    54,   101,   -59,   -25,   105,   -60,    67,   -60,
-     -60,   -60,    27,   -60,   -60,   -50,   -19,   -60,   -35,   -58,
-     -60
+     -60,   -60,   -60,   -60,   142,   -60,   -60,   -60,   -60,   -60,
+     -60,   -60,   -60,    30,   -60,   102,   -59,   -27,   104,   -60,
+      67,   -60,   -60,   -60,    23,   -60,   -60,   -50,   -19,   -60,
+     -35,   -58,   -60
 };
 
 /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
    positive, shift that token.  If negative, reduce the rule which
    number is the opposite.  If zero, do what YYDEFACT says.
    If YYTABLE_NINF, syntax error.  */
-#define YYTABLE_NINF -101
+#define YYTABLE_NINF -105
 static const yytype_int16 yytable[] =
 {
-      78,  -100,    80,    74,   105,    62,     4,     5,     6,     7,
+      78,  -104,    80,    74,   105,    62,     4,     5,     6,     7,
        8,     9,    10,    11,    56,    97,    80,    12,     3,    14,
        4,     5,     6,     7,     8,     9,    10,    11,    74,    94,
-      94,    12,    27,    14,    67,    53,   121,    50,   117,    54,
-      35,    74,   123,    69,    75,   123,    27,    76,    63,    81,
-     113,   130,   131,   132,    35,    97,    75,    42,    57,    76,
-      51,   122,   127,    81,   128,    91,   129,    52,   119,    75,
-     119,    42,    76,    59,    94,    60,    94,    68,    98,    99,
-     100,   133,    75,   122,    61,    76,    70,    74,   120,    64,
-      65,   134,    66,    71,    72,   136,    73,    89,    87,    53,
-     134,     4,     5,     6,     7,     8,     9,    10,    11,   106,
-     108,   109,    12,    13,    14,    15,    16,    17,    18,    19,
-      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
-      30,    31,    32,    33,    34,    35,    36,    37,    38,   110,
-     111,   112,   124,    74,   118,    39,   137,    40,    41,    44,
-     114,   138,    42,   104,    95,   135
+      94,    12,    27,    14,    67,    53,   123,    50,   117,    54,
+      35,    74,   125,    69,    75,   125,    27,    76,    63,    81,
+     113,   134,   135,   136,    35,   120,    75,    42,    57,    76,
+     132,   124,   133,    81,   131,    91,   121,    51,   121,    75,
+      52,    42,    76,    59,    94,    60,    94,    68,    98,    99,
+     100,   137,    75,   120,    61,    76,    70,    74,   122,    64,
+      65,    66,    71,   138,    72,    73,    89,    87,    53,   140,
+     106,   108,   109,   111,   138,     4,     5,     6,     7,     8,
+       9,    10,    11,   110,   112,   130,    12,    13,    14,    15,
+      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
+      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
+      36,    37,    38,    74,    44,   141,   126,   142,   129,    39,
+     114,    40,    41,    95,   104,   139,    42
 };
 
 static const yytype_uint8 yycheck[] =
@@ -841,16 +845,16 @@ static const yytype_uint8 yycheck[] =
       49,    16,    31,    18,     3,    43,    94,    53,    88,    47,
       39,     3,   101,     3,    44,   104,    31,    47,    46,    48,
       49,    13,    14,    15,    39,    90,    44,    56,    47,    47,
-      43,    96,   120,    48,    50,    53,    52,    43,    93,    44,
-      95,    56,    47,     3,    93,     4,    95,    46,    53,    54,
+      50,    96,    52,    48,   122,    53,    93,    43,    95,    44,
+      43,    56,    47,     3,    93,     4,    95,    46,    53,    54,
       55,    43,    44,   118,     4,    47,    46,     3,     4,    43,
-       3,   126,    43,    43,     3,   130,     3,    53,    47,    43,
-     135,     5,     6,     7,     8,     9,    10,    11,    12,     3,
-       3,     3,    16,    17,    18,    19,    20,    21,    22,    23,
-      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
-      34,    35,    36,    37,    38,    39,    40,    41,    42,     3,
-      52,    52,    45,     3,    90,    49,     4,    51,    52,     2,
-      83,    53,    56,    52,    49,   128
+       3,    43,    43,   128,     3,     3,    53,    47,    43,   134,
+       3,     3,     3,    52,   139,     5,     6,     7,     8,     9,
+      10,    11,    12,     3,    52,     4,    16,    17,    18,    19,
+      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
+      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
+      40,    41,    42,     3,     2,     4,    45,    53,   118,    49,
+      83,    51,    52,    49,    52,   132,    56
 };
 
 /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
@@ -862,15 +866,16 @@ static const yytype_uint8 yystos[] =
       24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
       34,    35,    36,    37,    38,    39,    40,    41,    42,    49,
       51,    52,    56,    60,    61,    63,    66,    67,    65,    64,
-      53,    43,    43,    43,    47,    82,     3,    47,    80,     3,
+      53,    43,    43,    43,    47,    84,     3,    47,    82,     3,
        4,     4,     3,    46,    43,     3,    43,     3,    46,     3,
-      46,    43,     3,     3,     3,    44,    47,    83,    85,    86,
-       1,    48,    61,    74,    75,    76,    84,    47,    62,    53,
-      68,    53,    72,    73,    83,    73,    69,    85,    53,    54,
-      55,    70,    71,    85,    70,    82,     3,    81,     3,     3,
-       3,    52,    52,    49,    75,    87,    77,    82,    69,    72,
-       4,    86,    85,    71,    45,    78,    79,    86,    50,    52,
-      13,    14,    15,    43,    85,    79,    85,     4,    53
+      46,    43,     3,     3,     3,    44,    47,    85,    87,    88,
+       1,    48,    61,    76,    77,    78,    86,    47,    62,    53,
+      68,    53,    74,    75,    85,    75,    71,    87,    53,    54,
+      55,    72,    73,    87,    72,    84,     3,    83,     3,     3,
+       3,    52,    52,    49,    77,    89,    79,    84,    69,    70,
+      87,    74,     4,    88,    87,    73,    45,    80,    81,    70,
+       4,    88,    50,    52,    13,    14,    15,    43,    87,    81,
+      87,     4,    53
 };
 
 #define yyerrok		(yyerrstatus = 0)
@@ -1025,7 +1030,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 	{ fputs (quotearg_style (c_quoting_style, (yyvaluep->chars)), stderr); };
 
 /* Line 22 of yacc.c  */
-#line 1029 "parse-gram.c"
+#line 1034 "parse-gram.c"
 	break;
       case 4: /* "\"integer\"" */
 
@@ -1034,7 +1039,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 	{ fprintf (stderr, "%d", (yyvaluep->integer)); };
 
 /* Line 22 of yacc.c  */
-#line 1038 "parse-gram.c"
+#line 1043 "parse-gram.c"
 	break;
       case 43: /* "\"{...}\"" */
 
@@ -1043,7 +1048,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->code)); };
 
 /* Line 22 of yacc.c  */
-#line 1047 "parse-gram.c"
+#line 1052 "parse-gram.c"
 	break;
       case 44: /* "\"char\"" */
 
@@ -1052,7 +1057,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 	{ fputs (char_name ((yyvaluep->character)), stderr); };
 
 /* Line 22 of yacc.c  */
-#line 1056 "parse-gram.c"
+#line 1061 "parse-gram.c"
 	break;
       case 45: /* "\"epilogue\"" */
 
@@ -1061,7 +1066,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
 /* Line 22 of yacc.c  */
-#line 1065 "parse-gram.c"
+#line 1070 "parse-gram.c"
 	break;
       case 47: /* "\"identifier\"" */
 
@@ -1070,7 +1075,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 	{ fputs ((yyvaluep->uniqstr), stderr); };
 
 /* Line 22 of yacc.c  */
-#line 1074 "parse-gram.c"
+#line 1079 "parse-gram.c"
 	break;
       case 48: /* "\"identifier:\"" */
 
@@ -1079,7 +1084,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 	{ fprintf (stderr, "%s:", (yyvaluep->uniqstr)); };
 
 /* Line 22 of yacc.c  */
-#line 1083 "parse-gram.c"
+#line 1088 "parse-gram.c"
 	break;
       case 51: /* "\"%{...%}\"" */
 
@@ -1088,7 +1093,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
 /* Line 22 of yacc.c  */
-#line 1092 "parse-gram.c"
+#line 1097 "parse-gram.c"
 	break;
       case 53: /* "\"type\"" */
 
@@ -1097,70 +1102,70 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 	{ fprintf (stderr, "<%s>", (yyvaluep->uniqstr)); };
 
 /* Line 22 of yacc.c  */
-#line 1101 "parse-gram.c"
+#line 1106 "parse-gram.c"
 	break;
-      case 80: /* "variable" */
+      case 82: /* "variable" */
 
 /* Line 22 of yacc.c  */
 #line 189 "parse-gram.y"
 	{ fputs ((yyvaluep->uniqstr), stderr); };
 
 /* Line 22 of yacc.c  */
-#line 1110 "parse-gram.c"
+#line 1115 "parse-gram.c"
 	break;
-      case 81: /* "content.opt" */
+      case 83: /* "content.opt" */
 
 /* Line 22 of yacc.c  */
 #line 184 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
 /* Line 22 of yacc.c  */
-#line 1119 "parse-gram.c"
+#line 1124 "parse-gram.c"
 	break;
-      case 82: /* "braceless" */
+      case 84: /* "braceless" */
 
 /* Line 22 of yacc.c  */
 #line 184 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
 /* Line 22 of yacc.c  */
-#line 1128 "parse-gram.c"
+#line 1133 "parse-gram.c"
 	break;
-      case 83: /* "id" */
+      case 85: /* "id" */
 
 /* Line 22 of yacc.c  */
 #line 196 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
 /* Line 22 of yacc.c  */
-#line 1137 "parse-gram.c"
+#line 1142 "parse-gram.c"
 	break;
-      case 84: /* "id_colon" */
+      case 86: /* "id_colon" */
 
 /* Line 22 of yacc.c  */
 #line 197 "parse-gram.y"
 	{ fprintf (stderr, "%s:", (yyvaluep->symbol)->tag); };
 
 /* Line 22 of yacc.c  */
-#line 1146 "parse-gram.c"
+#line 1151 "parse-gram.c"
 	break;
-      case 85: /* "symbol" */
+      case 87: /* "symbol" */
 
 /* Line 22 of yacc.c  */
 #line 196 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
 /* Line 22 of yacc.c  */
-#line 1155 "parse-gram.c"
+#line 1160 "parse-gram.c"
 	break;
-      case 86: /* "string_as_id" */
+      case 88: /* "string_as_id" */
 
 /* Line 22 of yacc.c  */
 #line 196 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
 /* Line 22 of yacc.c  */
-#line 1164 "parse-gram.c"
+#line 1169 "parse-gram.c"
 	break;
       default:
 	break;
@@ -1612,10 +1617,10 @@ YYLTYPE yylloc;
   YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
 #endif
 
-  /* Three stacks and their tools:
-     `yyss': related to states,
-     `yyvs': related to semantic values,
-     `yyls': related to locations.
+  /* The stacks and their tools:
+     `yyss' is related to states.
+     `yyvs' is related to semantic values.
+     `yyls' is related to locations.
 
      Refer to the stacks thru separate pointers, to allow yyoverflow
      to reallocate them elsewhere.  */
@@ -1684,7 +1689,7 @@ YYLTYPE yylloc;
 }
 
 /* Line 22 of yacc.c  */
-#line 1688 "parse-gram.c"
+#line 1693 "parse-gram.c"
   yylsp[0] = yylloc;
   goto yysetstate;
 
@@ -2334,68 +2339,96 @@ yyreduce:
 
 /* Line 22 of yacc.c  */
 #line 436 "parse-gram.y"
-    { (yyval.list) = (yyvsp[(1) - (1)].list); }
+    { (yyval.symbol) = (yyvsp[(1) - (1)].symbol); }
     break;
 
   case 61:
 
 /* Line 22 of yacc.c  */
 #line 437 "parse-gram.y"
-    { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), (yyvsp[(2) - (2)].list)); }
+    { (yyval.symbol) = (yyvsp[(1) - (2)].symbol); symbol_user_token_number_set ((yyvsp[(1) - (2)].symbol), (yyvsp[(2) - (2)].integer), (yylsp[(2) - (2)])); }
     break;
 
   case 62:
 
 /* Line 22 of yacc.c  */
-#line 441 "parse-gram.y"
+#line 443 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 63:
 
 /* Line 22 of yacc.c  */
-#line 442 "parse-gram.y"
-    { (yyval.list) = symbol_list_type_new ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
+#line 445 "parse-gram.y"
+    { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), symbol_list_sym_new ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]))); }
     break;
 
   case 64:
 
 /* Line 22 of yacc.c  */
-#line 443 "parse-gram.y"
-    { (yyval.list) = symbol_list_default_tagged_new ((yylsp[(1) - (1)])); }
+#line 449 "parse-gram.y"
+    { (yyval.list) = (yyvsp[(1) - (1)].list); }
     break;
 
   case 65:
 
 /* Line 22 of yacc.c  */
-#line 444 "parse-gram.y"
-    { (yyval.list) = symbol_list_default_tagless_new ((yylsp[(1) - (1)])); }
+#line 450 "parse-gram.y"
+    { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), (yyvsp[(2) - (2)].list)); }
     break;
 
   case 66:
 
 /* Line 22 of yacc.c  */
-#line 450 "parse-gram.y"
+#line 454 "parse-gram.y"
+    { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
+    break;
+
+  case 67:
+
+/* Line 22 of yacc.c  */
+#line 455 "parse-gram.y"
+    { (yyval.list) = symbol_list_type_new ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
+    break;
+
+  case 68:
+
+/* Line 22 of yacc.c  */
+#line 456 "parse-gram.y"
+    { (yyval.list) = symbol_list_default_tagged_new ((yylsp[(1) - (1)])); }
+    break;
+
+  case 69:
+
+/* Line 22 of yacc.c  */
+#line 457 "parse-gram.y"
+    { (yyval.list) = symbol_list_default_tagless_new ((yylsp[(1) - (1)])); }
+    break;
+
+  case 70:
+
+/* Line 22 of yacc.c  */
+#line 463 "parse-gram.y"
     {
        current_type = (yyvsp[(1) - (1)].uniqstr);
        tag_seen = true;
      }
     break;
 
-  case 67:
+  case 71:
 
 /* Line 22 of yacc.c  */
-#line 455 "parse-gram.y"
+#line 468 "parse-gram.y"
     {
        symbol_class_set ((yyvsp[(1) - (1)].symbol), current_class, (yylsp[(1) - (1)]), true);
        symbol_type_set ((yyvsp[(1) - (1)].symbol), current_type, (yylsp[(1) - (1)]));
      }
     break;
 
-  case 68:
+  case 72:
 
 /* Line 22 of yacc.c  */
-#line 460 "parse-gram.y"
+#line 473 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
       symbol_type_set ((yyvsp[(1) - (2)].symbol), current_type, (yylsp[(1) - (2)]));
@@ -2403,10 +2436,10 @@ yyreduce:
     }
     break;
 
-  case 69:
+  case 73:
 
 /* Line 22 of yacc.c  */
-#line 466 "parse-gram.y"
+#line 479 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
       symbol_type_set ((yyvsp[(1) - (2)].symbol), current_type, (yylsp[(1) - (2)]));
@@ -2414,10 +2447,10 @@ yyreduce:
     }
     break;
 
-  case 70:
+  case 74:
 
 /* Line 22 of yacc.c  */
-#line 472 "parse-gram.y"
+#line 485 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (3)].symbol), current_class, (yylsp[(1) - (3)]), true);
       symbol_type_set ((yyvsp[(1) - (3)].symbol), current_type, (yylsp[(1) - (3)]));
@@ -2426,98 +2459,98 @@ yyreduce:
     }
     break;
 
-  case 77:
+  case 81:
 
 /* Line 22 of yacc.c  */
-#line 502 "parse-gram.y"
+#line 515 "parse-gram.y"
     {
       yyerrok;
     }
     break;
 
-  case 78:
+  case 82:
 
 /* Line 22 of yacc.c  */
-#line 508 "parse-gram.y"
+#line 521 "parse-gram.y"
     { current_lhs = (yyvsp[(1) - (1)].symbol); current_lhs_location = (yylsp[(1) - (1)]); }
     break;
 
-  case 80:
+  case 84:
 
 /* Line 22 of yacc.c  */
-#line 512 "parse-gram.y"
+#line 525 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(1) - (1)])); }
     break;
 
-  case 81:
+  case 85:
 
 /* Line 22 of yacc.c  */
-#line 513 "parse-gram.y"
+#line 526 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(3) - (3)])); }
     break;
 
-  case 83:
+  case 87:
 
 /* Line 22 of yacc.c  */
-#line 519 "parse-gram.y"
+#line 532 "parse-gram.y"
     { grammar_current_rule_begin (current_lhs, current_lhs_location); }
     break;
 
-  case 84:
+  case 88:
 
 /* Line 22 of yacc.c  */
-#line 521 "parse-gram.y"
+#line 534 "parse-gram.y"
     { grammar_current_rule_symbol_append ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)])); }
     break;
 
-  case 85:
+  case 89:
 
 /* Line 22 of yacc.c  */
-#line 523 "parse-gram.y"
+#line 536 "parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
     break;
 
-  case 86:
+  case 90:
 
 /* Line 22 of yacc.c  */
-#line 525 "parse-gram.y"
+#line 538 "parse-gram.y"
     { grammar_current_rule_prec_set ((yyvsp[(3) - (3)].symbol), (yylsp[(3) - (3)])); }
     break;
 
-  case 87:
+  case 91:
 
 /* Line 22 of yacc.c  */
-#line 527 "parse-gram.y"
+#line 540 "parse-gram.y"
     { grammar_current_rule_dprec_set ((yyvsp[(3) - (3)].integer), (yylsp[(3) - (3)])); }
     break;
 
-  case 88:
+  case 92:
 
 /* Line 22 of yacc.c  */
-#line 529 "parse-gram.y"
+#line 542 "parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[(3) - (3)].uniqstr), (yylsp[(3) - (3)])); }
     break;
 
-  case 90:
+  case 94:
 
 /* Line 22 of yacc.c  */
-#line 539 "parse-gram.y"
+#line 552 "parse-gram.y"
     { (yyval.uniqstr) = uniqstr_new ((yyvsp[(1) - (1)].chars)); }
     break;
 
-  case 91:
+  case 95:
 
 /* Line 22 of yacc.c  */
-#line 545 "parse-gram.y"
+#line 558 "parse-gram.y"
     {
       (yyval.chars) = "";
     }
     break;
 
-  case 93:
+  case 97:
 
 /* Line 22 of yacc.c  */
-#line 558 "parse-gram.y"
+#line 571 "parse-gram.y"
     {
       code_props plain_code;
       (yyvsp[(1) - (1)].code)[strlen ((yyvsp[(1) - (1)].code)) - 1] = '\n';
@@ -2528,17 +2561,17 @@ yyreduce:
     }
     break;
 
-  case 94:
+  case 98:
 
 /* Line 22 of yacc.c  */
-#line 578 "parse-gram.y"
+#line 591 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
-  case 95:
+  case 99:
 
 /* Line 22 of yacc.c  */
-#line 580 "parse-gram.y"
+#line 593 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[(1) - (1)].character)), (yylsp[(1) - (1)]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[(1) - (1)]), false);
@@ -2546,27 +2579,27 @@ yyreduce:
     }
     break;
 
-  case 96:
+  case 100:
 
 /* Line 22 of yacc.c  */
-#line 588 "parse-gram.y"
+#line 601 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
-  case 99:
+  case 103:
 
 /* Line 22 of yacc.c  */
-#line 600 "parse-gram.y"
+#line 613 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[(1) - (1)].chars)), (yylsp[(1) - (1)]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[(1) - (1)]), false);
     }
     break;
 
-  case 101:
+  case 105:
 
 /* Line 22 of yacc.c  */
-#line 609 "parse-gram.y"
+#line 622 "parse-gram.y"
     {
       code_props plain_code;
       code_props_plain_init (&plain_code, (yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)]));
@@ -2580,7 +2613,7 @@ yyreduce:
 
 
 /* Line 22 of yacc.c  */
-#line 2584 "parse-gram.c"
+#line 2617 "parse-gram.c"
       default: break;
     }
   YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);
@@ -2799,7 +2832,7 @@ yyreturn:
 
 
 /* Line 22 of yacc.c  */
-#line 619 "parse-gram.y"
+#line 632 "parse-gram.y"
 
 
 
