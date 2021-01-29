@@ -77,7 +77,7 @@
 
 /* Copy the first part of user declarations.  */
 
-/* Line 176 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 1 "parse-gram.y"
 /* Bison Grammar Parser                             -*- C -*-
 
@@ -157,7 +157,7 @@ static int current_prec = 0;
 #define YYTYPE_UINT8 uint_fast8_t
 
 
-/* Line 176 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 162 "parse-gram.c"
 
 /* Enabling traces.  */
@@ -309,7 +309,7 @@ static int current_prec = 0;
 #if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
 typedef union YYSTYPE
 {
-/* Line 210 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 97 "parse-gram.y"
 
   symbol *symbol;
@@ -322,7 +322,7 @@ typedef union YYSTYPE
   unsigned char character;
 }
 
-/* Line 210 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 327 "parse-gram.c"
 	YYSTYPE;
 # define YYSTYPE_IS_TRIVIAL 1
@@ -347,7 +347,7 @@ typedef struct YYLTYPE
 /* Copy the second part of user declarations.  */
 
 
-/* Line 233 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 352 "parse-gram.c"
 
 #ifdef short
@@ -565,16 +565,16 @@ union yyalloc
 /* YYFINAL -- State number of the termination state.  */
 #define YYFINAL  3
 /* YYLAST -- Last index in YYTABLE.  */
-#define YYLAST   187
+#define YYLAST   185
 
 /* YYNTOKENS -- Number of terminals.  */
 #define YYNTOKENS  59
 /* YYNNTS -- Number of nonterminals.  */
-#define YYNNTS  31
+#define YYNNTS  30
 /* YYNRULES -- Number of rules.  */
-#define YYNRULES  103
+#define YYNRULES  101
 /* YYNRULES -- Number of states.  */
-#define YYNSTATES  141
+#define YYNSTATES  139
 
 /* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
 #define YYUNDEFTOK  2
@@ -634,16 +634,16 @@ static const yytype_uint16 yyprhs[] =
      156,   158,   161,   163,   166,   168,   170,   172,   174,   176,
      178,   181,   184,   188,   190,   193,   195,   198,   200,   203,
      206,   207,   211,   213,   217,   220,   221,   224,   227,   231,
-     235,   239,   241,   243,   244,   246,   248,   250,   252,   254,
-     256,   258,   260,   261
+     235,   239,   240,   242,   244,   246,   248,   250,   252,   254,
+     256,   257
 };
 
 /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
 static const yytype_int8 yyrhs[] =
 {
-      60,     0,    -1,    61,    51,    76,    89,    -1,    -1,    61,
+      60,     0,    -1,    61,    51,    76,    88,    -1,    -1,    61,
       62,    -1,    63,    -1,    53,    -1,    17,    -1,    19,     3,
-      83,    -1,    20,    -1,    20,     3,    -1,    21,    -1,    22,
+      82,    -1,    20,    -1,    20,     3,    -1,    21,    -1,    22,
        4,    -1,    23,     4,    -1,    24,     3,    -1,    24,    48,
        3,    -1,    25,    -1,    26,    45,    -1,    27,     3,    -1,
       28,    45,    -1,    29,    -1,    30,     3,    -1,    30,    48,
@@ -651,39 +651,38 @@ static const yytype_int8 yyrhs[] =
       48,     3,    -1,    35,    45,    -1,    36,    -1,    37,    -1,
       38,    -1,    39,     3,    -1,    40,     3,    -1,    42,    -1,
       43,    -1,    44,    -1,    54,    -1,    68,    -1,    65,    -1,
-      41,    87,    -1,     8,    45,    72,    -1,     9,    45,    72,
-      -1,    18,    -1,    31,    -1,    16,    84,    -1,    16,     3,
-      84,    -1,    -1,    49,    -1,    58,    64,    45,    -1,    -1,
+      41,    86,    -1,     8,    45,    72,    -1,     9,    45,    72,
+      -1,    18,    -1,    31,    -1,    16,    83,    -1,    16,     3,
+      83,    -1,    -1,    49,    -1,    58,    64,    45,    -1,    -1,
        6,    66,    75,    -1,    -1,     5,    67,    75,    -1,     7,
       55,    71,    -1,    69,    70,    71,    -1,    10,    -1,    11,
-      -1,    12,    -1,    -1,    55,    -1,    87,    -1,    71,    87,
-      -1,    73,    -1,    72,    73,    -1,    87,    -1,    55,    -1,
-      56,    -1,    57,    -1,    55,    -1,    85,    -1,    85,     4,
-      -1,    85,    88,    -1,    85,     4,    88,    -1,    74,    -1,
+      -1,    12,    -1,    -1,    55,    -1,    86,    -1,    71,    86,
+      -1,    73,    -1,    72,    73,    -1,    86,    -1,    55,    -1,
+      56,    -1,    57,    -1,    55,    -1,    84,    -1,    84,     4,
+      -1,    84,    87,    -1,    84,     4,    87,    -1,    74,    -1,
       75,    74,    -1,    77,    -1,    76,    77,    -1,    78,    -1,
-      63,    54,    -1,     1,    54,    -1,    -1,    86,    79,    80,
+      63,    54,    -1,     1,    54,    -1,    -1,    85,    79,    80,
       -1,    81,    -1,    80,    52,    81,    -1,    80,    54,    -1,
-      -1,    81,    87,    -1,    81,    45,    -1,    81,    13,    87,
-      -1,    81,    14,     4,    -1,    81,    15,    55,    -1,     3,
-      -1,    84,    -1,    -1,    82,    -1,    45,    -1,    49,    -1,
-      46,    -1,    50,    -1,    85,    -1,    88,    -1,     3,    -1,
-      -1,    51,    47,    -1
+      -1,    81,    86,    -1,    81,    45,    -1,    81,    13,    86,
+      -1,    81,    14,     4,    -1,    81,    15,    55,    -1,    -1,
+       3,    -1,    45,    -1,    49,    -1,    46,    -1,    50,    -1,
+      84,    -1,    87,    -1,     3,    -1,    -1,    51,    47,    -1
 };
 
 /* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
 static const yytype_uint16 yyrline[] =
 {
-       0,   210,   210,   218,   220,   224,   225,   234,   235,   244,
-     245,   250,   251,   252,   253,   254,   255,   260,   269,   270,
-     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
-     281,   282,   283,   284,   285,   286,   287,   291,   292,   293,
-     297,   304,   311,   315,   319,   324,   347,   348,   352,   381,
-     381,   386,   386,   391,   402,   417,   418,   419,   423,   424,
-     429,   431,   436,   437,   441,   442,   443,   444,   449,   454,
-     459,   465,   471,   482,   483,   492,   493,   499,   500,   501,
-     508,   508,   512,   513,   514,   519,   520,   522,   524,   526,
-     528,   538,   539,   545,   549,   554,   574,   576,   585,   590,
-     591,   596,   603,   605
+       0,   210,   210,   218,   220,   224,   225,   234,   235,   249,
+     250,   255,   256,   257,   258,   259,   260,   265,   274,   275,
+     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
+     286,   287,   288,   289,   290,   291,   292,   296,   297,   298,
+     302,   309,   316,   320,   324,   329,   352,   353,   357,   386,
+     386,   391,   391,   396,   407,   422,   423,   424,   428,   429,
+     434,   436,   441,   442,   446,   447,   448,   449,   454,   459,
+     464,   470,   476,   487,   488,   497,   498,   504,   505,   506,
+     513,   513,   517,   518,   519,   524,   525,   527,   529,   531,
+     533,   545,   549,   558,   578,   580,   589,   594,   595,   600,
+     607,   609
 };
 #endif
 
@@ -712,8 +711,8 @@ static const char *const yytname[] =
   "precedence_declarator", "type.opt", "symbols.1", "generic_symlist",
   "generic_symlist_item", "symbol_def", "symbol_defs.1", "grammar",
   "rules_or_grammar_declaration", "rules", "$@3", "rhses.1", "rhs",
-  "content", "content.opt", "braceless", "id", "id_colon", "symbol",
-  "string_as_id", "epilogue.opt", 0
+  "content.opt", "braceless", "id", "id_colon", "symbol", "string_as_id",
+  "epilogue.opt", 0
 };
 #endif
 
@@ -743,8 +742,8 @@ static const yytype_uint8 yyr1[] =
       71,    71,    72,    72,    73,    73,    73,    73,    74,    74,
       74,    74,    74,    75,    75,    76,    76,    77,    77,    77,
       79,    78,    80,    80,    80,    81,    81,    81,    81,    81,
-      81,    82,    82,    83,    83,    84,    85,    85,    86,    87,
-      87,    88,    89,    89
+      81,    82,    82,    83,    84,    84,    85,    86,    86,    87,
+      88,    88
 };
 
 /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
@@ -759,8 +758,8 @@ static const yytype_uint8 yyr2[] =
        1,     2,     1,     2,     1,     1,     1,     1,     1,     1,
        2,     2,     3,     1,     2,     1,     2,     1,     2,     2,
        0,     3,     1,     3,     2,     0,     2,     2,     3,     3,
-       3,     1,     1,     0,     1,     1,     1,     1,     1,     1,
-       1,     1,     0,     2
+       3,     0,     1,     1,     1,     1,     1,     1,     1,     1,
+       0,     2
 };
 
 /* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
@@ -773,25 +772,23 @@ static const yytype_uint8 yydefact[] =
        0,    16,     0,     0,     0,    20,     0,    43,    23,    24,
        0,     0,    28,    29,    30,     0,     0,     0,    33,    34,
       35,     0,     6,    36,    46,     4,     5,    38,    37,    58,
-       0,     0,     0,     0,     0,     0,    95,    44,    93,    10,
+       0,     0,     0,     0,     0,     0,    93,    44,    91,    10,
       12,    13,    14,     0,    17,    18,    19,    21,     0,    25,
-       0,    27,    31,    32,   101,    97,    96,    99,    39,   100,
-       0,    98,     0,     0,    75,    77,    80,    47,     0,    59,
+       0,    27,    31,    32,    99,    95,    94,    97,    39,    98,
+       0,    96,     0,     0,    75,    77,    80,    47,     0,    59,
        0,    68,    73,    52,    69,    50,    53,    60,    65,    66,
-      67,    40,    62,    64,    41,    45,    91,    94,     8,    92,
-      15,    22,    26,    79,    78,     0,    76,     2,    85,    48,
-      54,    74,    70,    71,    61,    63,   103,    81,    82,    72,
-      85,    84,     0,     0,     0,    87,    86,    83,    88,    89,
-      90
+      67,    40,    62,    64,    41,    45,    92,     8,    15,    22,
+      26,    79,    78,     0,    76,     2,    85,    48,    54,    74,
+      70,    71,    61,    63,   101,    81,    82,    72,    85,    84,
+       0,     0,     0,    87,    86,    83,    88,    89,    90
 };
 
 /* YYDEFGOTO[NTERM-NUM].  */
-static const yytype_int16 yydefgoto[] =
+static const yytype_int8 yydefgoto[] =
 {
       -1,     1,     2,    45,    82,    88,    47,    51,    50,    48,
       49,    90,    96,   101,   102,    92,    93,    83,    84,    85,
-     118,   127,   128,   107,   108,    57,    77,    86,   103,    79,
-     117
+     116,   125,   126,   107,    57,    77,    86,   103,    79,   115
 };
 
 /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
@@ -799,81 +796,79 @@ static const yytype_int16 yydefgoto[] =
 #define YYPACT_NINF -93
 static const yytype_int16 yypact[] =
 {
-     -93,    14,    96,   -93,   -93,   -93,    -4,    20,    30,   -93,
-     -93,   -93,    21,   -93,   -93,    73,    75,   -93,    76,    77,
-       6,   -93,    34,    79,    39,   -93,    22,   -93,   -93,   -93,
-      23,    41,   -93,   -93,   -93,    84,    85,    -2,   -93,   -93,
-     -93,    27,   -93,   -93,    40,   -93,   -93,   -93,   -93,    35,
-     -42,   -42,    -2,     0,     0,    47,   -93,   -93,    28,   -93,
-     -93,   -93,   -93,    90,   -93,   -93,   -93,   -93,    91,   -93,
-      93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,
-      43,   -93,    44,    11,   -93,   -93,   -93,   -93,    54,   -93,
-      -2,   -93,   -93,   -42,    37,   -42,    -2,   -93,   -93,   -93,
-     -93,     0,   -93,   -93,     0,   -93,   -93,   -93,   -93,   -93,
-     -93,   -93,   -93,   -93,   -93,    62,   -93,   -93,   -93,   -93,
-      -2,   -93,   107,   -93,   -93,   -93,   -93,   -44,   138,   -93,
-     -93,   -93,    -2,   139,    56,   -93,   -93,   138,   -93,   -93,
-     -93
+     -93,     8,    94,   -93,   -93,   -93,   -41,   -20,    -6,   -93,
+     -93,   -93,     4,   -93,   -93,    42,    54,   -93,    56,    64,
+       2,   -93,    28,    71,    34,   -93,     3,   -93,   -93,   -93,
+       6,    35,   -93,   -93,   -93,    79,    81,    -2,   -93,   -93,
+     -93,    25,   -93,   -93,    36,   -93,   -93,   -93,   -93,    31,
+       9,     9,    -2,    21,    21,    43,   -93,   -93,    84,   -93,
+     -93,   -93,   -93,    87,   -93,   -93,   -93,   -93,    88,   -93,
+      89,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,
+      40,   -93,    41,    11,   -93,   -93,   -93,   -93,    51,   -93,
+      -2,   -93,   -93,     9,    68,     9,    -2,   -93,   -93,   -93,
+     -93,    21,   -93,   -93,    21,   -93,   -93,   -93,   -93,   -93,
+     -93,   -93,   -93,    50,   -93,   -93,   -93,   -93,    -2,   -93,
+     104,   -93,   -93,   -93,   -93,   -14,   136,   -93,   -93,   -93,
+      -2,   105,    53,   -93,   -93,   136,   -93,   -93,   -93
 };
 
 /* YYPGOTO[NTERM-NUM].  */
 static const yytype_int16 yypgoto[] =
 {
-     -93,   -93,   -93,   -93,   140,   -93,   -93,   -93,   -93,   -93,
-     -93,   -93,    55,    92,   -41,   -21,    97,   -93,    61,   -93,
-     -93,   -93,    25,   -93,   -93,     9,   -45,   -93,   -37,   -92,
-     -93
+     -93,   -93,   -93,   -93,   138,   -93,   -93,   -93,   -93,   -93,
+     -93,   -93,    52,    90,   -91,   -30,    92,   -93,    58,   -93,
+     -93,   -93,    18,   -93,    98,   -47,   -93,   -37,   -92,   -93
 };
 
 /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
    positive, shift that token.  If negative, reduce the rule which
    number is the opposite.  If zero, do what YYDEFACT says.
    If YYTABLE_NINF, syntax error.  */
-#define YYTABLE_NINF -103
+#define YYTABLE_NINF -101
 static const yytype_int16 yytable[] =
 {
-      78,    74,   123,    74,    75,    94,    94,    76,   130,    62,
-     131,  -102,    80,    91,     3,    97,     4,     5,     6,     7,
-       8,     9,    10,    11,    55,    67,    69,    12,    80,    14,
-     129,   106,     4,     5,     6,     7,     8,     9,    10,    11,
-      74,   122,    27,    12,    75,    14,    75,    76,    94,    76,
-      94,    52,    37,    97,    63,    98,    99,   100,    27,   124,
-     125,    81,   115,   125,   105,    53,    56,   109,    37,    44,
-      68,    70,   121,    56,   121,    54,    58,    81,    59,    64,
-      60,    61,    65,   124,    66,    44,    71,    72,    73,    87,
-      89,   136,    56,   110,   111,   138,   112,   113,   114,   119,
-     136,     4,     5,     6,     7,     8,     9,    10,    11,   126,
-      74,   140,    12,    13,    14,    15,    16,    17,    18,    19,
-      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
-      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
-      40,    74,    46,   139,   116,   120,   104,    41,    95,    42,
-      43,   132,   133,   134,    44,   137,     0,     0,     0,     0,
+      78,    74,   121,    94,    94,    62,    67,    55,     3,    69,
+     123,  -100,    80,   123,    52,    97,     4,     5,     6,     7,
+       8,     9,    10,    11,    74,    53,    80,    12,   127,    14,
+       4,     5,     6,     7,     8,     9,    10,    11,   128,    54,
+     129,    12,    27,    14,    75,    58,    94,    76,    94,    56,
+      63,    68,    37,    97,    70,    75,    27,    59,    76,   122,
+      60,    81,   113,   119,    91,   119,    37,    75,    61,    44,
+      76,    74,   120,    64,    65,    81,    98,    99,   100,    66,
+      71,   122,    72,    44,    73,    87,    89,   106,    56,   134,
+     108,   109,   110,   136,   111,   112,   117,   124,   134,     4,
+       5,     6,     7,     8,     9,    10,    11,    74,   138,   137,
+      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
+      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
+      32,    33,    34,    35,    36,    37,    38,    39,    40,    74,
+      46,   114,   118,    95,   104,    41,   135,    42,    43,   130,
+     131,   132,    44,   105,     0,     0,     0,     0,     0,     0,
        0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
        0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
-       0,     0,     0,   135,    75,     0,     0,    76
+       0,   133,    75,     0,     0,    76
 };
 
 static const yytype_int16 yycheck[] =
 {
-      37,     3,    94,     3,    46,    50,    51,    49,    52,     3,
-      54,     0,     1,    55,     0,    52,     5,     6,     7,     8,
-       9,    10,    11,    12,     3,     3,     3,    16,     1,    18,
-     122,     3,     5,     6,     7,     8,     9,    10,    11,    12,
-       3,     4,    31,    16,    46,    18,    46,    49,    93,    49,
-      95,    55,    41,    90,    48,    55,    56,    57,    31,    96,
-     101,    50,    51,   104,    55,    45,    45,    58,    41,    58,
-      48,    48,    93,    45,    95,    45,     3,    50,     3,    45,
-       4,     4,     3,   120,    45,    58,    45,     3,     3,    49,
-      55,   128,    45,     3,     3,   132,     3,    54,    54,    45,
-     137,     5,     6,     7,     8,     9,    10,    11,    12,    47,
-       3,    55,    16,    17,    18,    19,    20,    21,    22,    23,
-      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
-      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
-      44,     3,     2,     4,    83,    90,    54,    51,    51,    53,
-      54,    13,    14,    15,    58,   130,    -1,    -1,    -1,    -1,
+      37,     3,    94,    50,    51,     3,     3,     3,     0,     3,
+     101,     0,     1,   104,    55,    52,     5,     6,     7,     8,
+       9,    10,    11,    12,     3,    45,     1,    16,   120,    18,
+       5,     6,     7,     8,     9,    10,    11,    12,    52,    45,
+      54,    16,    31,    18,    46,     3,    93,    49,    95,    45,
+      48,    48,    41,    90,    48,    46,    31,     3,    49,    96,
+       4,    50,    51,    93,    55,    95,    41,    46,     4,    58,
+      49,     3,     4,    45,     3,    50,    55,    56,    57,    45,
+      45,   118,     3,    58,     3,    49,    55,     3,    45,   126,
+       3,     3,     3,   130,    54,    54,    45,    47,   135,     5,
+       6,     7,     8,     9,    10,    11,    12,     3,    55,     4,
+      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
+      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
+      36,    37,    38,    39,    40,    41,    42,    43,    44,     3,
+       2,    83,    90,    51,    54,    51,   128,    53,    54,    13,
+      14,    15,    58,    55,    -1,    -1,    -1,    -1,    -1,    -1,
       -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
-      -1,    -1,    -1,    45,    46,    -1,    -1,    49
+      -1,    45,    46,    -1,    -1,    49
 };
 
 /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
@@ -885,16 +880,15 @@ static const yytype_uint8 yystos[] =
       24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
       34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
       44,    51,    53,    54,    58,    62,    63,    65,    68,    69,
-      67,    66,    55,    45,    45,     3,    45,    84,     3,     3,
+      67,    66,    55,    45,    45,     3,    45,    83,     3,     3,
        4,     4,     3,    48,    45,     3,    45,     3,    48,     3,
-      48,    45,     3,     3,     3,    46,    49,    85,    87,    88,
-       1,    50,    63,    76,    77,    78,    86,    49,    64,    55,
-      70,    55,    74,    75,    85,    75,    71,    87,    55,    56,
-      57,    72,    73,    87,    72,    84,     3,    82,    83,    84,
-       3,     3,     3,    54,    54,    51,    77,    89,    79,    45,
-      71,    74,     4,    88,    87,    73,    47,    80,    81,    88,
-      52,    54,    13,    14,    15,    45,    87,    81,    87,     4,
-      55
+      48,    45,     3,     3,     3,    46,    49,    84,    86,    87,
+       1,    50,    63,    76,    77,    78,    85,    49,    64,    55,
+      70,    55,    74,    75,    84,    75,    71,    86,    55,    56,
+      57,    72,    73,    86,    72,    83,     3,    82,     3,     3,
+       3,    54,    54,    51,    77,    88,    79,    45,    71,    74,
+       4,    87,    86,    73,    47,    80,    81,    87,    52,    54,
+      13,    14,    15,    45,    86,    81,    86,     4,    55
 };
 
 #define yyerrok		(yyerrstatus = 0)
@@ -1044,147 +1038,138 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
     {
       case 3: /* "\"string\"" */
 
-/* Line 686 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 188 "parse-gram.y"
 	{ fputs (quotearg_style (c_quoting_style, (yyvaluep->chars)), stderr); };
 
-/* Line 686 of yacc.c  */
-#line 1053 "parse-gram.c"
+/* Line 1535 of yacc.c  */
+#line 1047 "parse-gram.c"
 	break;
       case 4: /* "\"integer\"" */
 
-/* Line 686 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 199 "parse-gram.y"
 	{ fprintf (stderr, "%d", (yyvaluep->integer)); };
 
-/* Line 686 of yacc.c  */
-#line 1062 "parse-gram.c"
+/* Line 1535 of yacc.c  */
+#line 1056 "parse-gram.c"
 	break;
       case 45: /* "\"{...}\"" */
 
-/* Line 686 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 190 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->code)); };
 
-/* Line 686 of yacc.c  */
-#line 1071 "parse-gram.c"
+/* Line 1535 of yacc.c  */
+#line 1065 "parse-gram.c"
 	break;
       case 46: /* "\"char\"" */
 
-/* Line 686 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 182 "parse-gram.y"
 	{ fputs (char_name ((yyvaluep->character)), stderr); };
 
-/* Line 686 of yacc.c  */
-#line 1080 "parse-gram.c"
+/* Line 1535 of yacc.c  */
+#line 1074 "parse-gram.c"
 	break;
       case 47: /* "\"epilogue\"" */
 
-/* Line 686 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 190 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
-/* Line 686 of yacc.c  */
-#line 1089 "parse-gram.c"
+/* Line 1535 of yacc.c  */
+#line 1083 "parse-gram.c"
 	break;
       case 49: /* "\"identifier\"" */
 
-/* Line 686 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 195 "parse-gram.y"
 	{ fputs ((yyvaluep->uniqstr), stderr); };
 
-/* Line 686 of yacc.c  */
-#line 1098 "parse-gram.c"
+/* Line 1535 of yacc.c  */
+#line 1092 "parse-gram.c"
 	break;
       case 50: /* "\"identifier:\"" */
 
-/* Line 686 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 196 "parse-gram.y"
 	{ fprintf (stderr, "%s:", (yyvaluep->uniqstr)); };
 
-/* Line 686 of yacc.c  */
-#line 1107 "parse-gram.c"
+/* Line 1535 of yacc.c  */
+#line 1101 "parse-gram.c"
 	break;
       case 53: /* "\"%{...%}\"" */
 
-/* Line 686 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 190 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
-/* Line 686 of yacc.c  */
-#line 1116 "parse-gram.c"
+/* Line 1535 of yacc.c  */
+#line 1110 "parse-gram.c"
 	break;
       case 55: /* "\"type\"" */
 
-/* Line 686 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 194 "parse-gram.y"
 	{ fprintf (stderr, "<%s>", (yyvaluep->uniqstr)); };
 
-/* Line 686 of yacc.c  */
-#line 1125 "parse-gram.c"
-	break;
-      case 82: /* "content" */
-
-/* Line 686 of yacc.c  */
-#line 190 "parse-gram.y"
-	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-
-/* Line 686 of yacc.c  */
-#line 1134 "parse-gram.c"
+/* Line 1535 of yacc.c  */
+#line 1119 "parse-gram.c"
 	break;
-      case 83: /* "content.opt" */
+      case 82: /* "content.opt" */
 
-/* Line 686 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 190 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
-/* Line 686 of yacc.c  */
-#line 1143 "parse-gram.c"
+/* Line 1535 of yacc.c  */
+#line 1128 "parse-gram.c"
 	break;
-      case 84: /* "braceless" */
+      case 83: /* "braceless" */
 
-/* Line 686 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 190 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
-/* Line 686 of yacc.c  */
-#line 1152 "parse-gram.c"
+/* Line 1535 of yacc.c  */
+#line 1137 "parse-gram.c"
 	break;
-      case 85: /* "id" */
+      case 84: /* "id" */
 
-/* Line 686 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 202 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
-/* Line 686 of yacc.c  */
-#line 1161 "parse-gram.c"
+/* Line 1535 of yacc.c  */
+#line 1146 "parse-gram.c"
 	break;
-      case 86: /* "id_colon" */
+      case 85: /* "id_colon" */
 
-/* Line 686 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 203 "parse-gram.y"
 	{ fprintf (stderr, "%s:", (yyvaluep->symbol)->tag); };
 
-/* Line 686 of yacc.c  */
-#line 1170 "parse-gram.c"
+/* Line 1535 of yacc.c  */
+#line 1155 "parse-gram.c"
 	break;
-      case 87: /* "symbol" */
+      case 86: /* "symbol" */
 
-/* Line 686 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 202 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
-/* Line 686 of yacc.c  */
-#line 1179 "parse-gram.c"
+/* Line 1535 of yacc.c  */
+#line 1164 "parse-gram.c"
 	break;
-      case 88: /* "string_as_id" */
+      case 87: /* "string_as_id" */
 
-/* Line 686 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 202 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
-/* Line 686 of yacc.c  */
-#line 1188 "parse-gram.c"
+/* Line 1535 of yacc.c  */
+#line 1173 "parse-gram.c"
 	break;
       default:
 	break;
@@ -1698,7 +1683,7 @@ YYLTYPE yylloc;
 
   /* User initialization code.  */
   
-/* Line 1098 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 89 "parse-gram.y"
 {
   /* Bison's grammar can initial empty locations, hence a default
@@ -1707,8 +1692,8 @@ YYLTYPE yylloc;
   boundary_set (&yylloc.end, current_file, 1, 1);
 }
 
-/* Line 1098 of yacc.c  */
-#line 1712 "parse-gram.c"
+/* Line 1535 of yacc.c  */
+#line 1697 "parse-gram.c"
   yylsp[0] = yylloc;
   goto yysetstate;
 
@@ -1893,7 +1878,7 @@ yyreduce:
     {
         case 6:
 
-/* Line 1285 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 226 "parse-gram.y"
     {
       code_props plain_code;
@@ -1907,36 +1892,41 @@ yyreduce:
 
   case 7:
 
-/* Line 1285 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 234 "parse-gram.y"
     { debug_flag = true; }
     break;
 
   case 8:
 
-/* Line 1285 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 236 "parse-gram.y"
     {
       /* FIXME: Special characters in $2 may break %define.
          For example: `['.  */
-      if (muscle_find_const ((yyvsp[(2) - (3)].chars)))
-        warn_at ((yylsp[(2) - (3)]), _("%s: `%s' redefined"), "%define", (yyvsp[(2) - (3)].chars));
-      muscle_insert ((yyvsp[(2) - (3)].chars), (yyvsp[(3) - (3)].chars));
-      muscle_grow_used_name_list ("used_percent_define_variables", (yyvsp[(2) - (3)].chars), (yylsp[(2) - (3)]));
+      char const name_prefix[] = "percent_define_";
+      char *name = xmalloc (sizeof name_prefix + strlen ((yyvsp[(2) - (3)].chars)));
+      strcpy (name, name_prefix);
+      strcpy (name + sizeof name_prefix - 1, (yyvsp[(2) - (3)].chars));
+      if (muscle_find_const (name))
+        warn_at ((yylsp[(2) - (3)]), _("%s `%s' redefined"), "%define variable", (yyvsp[(2) - (3)].chars));
+      muscle_insert (uniqstr_new (name), (yyvsp[(3) - (3)].chars));
+      free (name);
+      muscle_grow_user_name_list ("user_percent_define_variables", (yyvsp[(2) - (3)].chars), (yylsp[(2) - (3)]));
     }
     break;
 
   case 9:
 
-/* Line 1285 of yacc.c  */
-#line 244 "parse-gram.y"
+/* Line 1535 of yacc.c  */
+#line 249 "parse-gram.y"
     { defines_flag = true; }
     break;
 
   case 10:
 
-/* Line 1285 of yacc.c  */
-#line 246 "parse-gram.y"
+/* Line 1535 of yacc.c  */
+#line 251 "parse-gram.y"
     {
       defines_flag = true;
       spec_defines_file = xstrdup ((yyvsp[(2) - (2)].chars));
@@ -1945,43 +1935,43 @@ yyreduce:
 
   case 11:
 
-/* Line 1285 of yacc.c  */
-#line 250 "parse-gram.y"
+/* Line 1535 of yacc.c  */
+#line 255 "parse-gram.y"
     { error_verbose = true; }
     break;
 
   case 12:
 
-/* Line 1285 of yacc.c  */
-#line 251 "parse-gram.y"
+/* Line 1535 of yacc.c  */
+#line 256 "parse-gram.y"
     { expected_sr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 13:
 
-/* Line 1285 of yacc.c  */
-#line 252 "parse-gram.y"
+/* Line 1535 of yacc.c  */
+#line 257 "parse-gram.y"
     { expected_rr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 14:
 
-/* Line 1285 of yacc.c  */
-#line 253 "parse-gram.y"
+/* Line 1535 of yacc.c  */
+#line 258 "parse-gram.y"
     { spec_file_prefix = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 15:
 
-/* Line 1285 of yacc.c  */
-#line 254 "parse-gram.y"
+/* Line 1535 of yacc.c  */
+#line 259 "parse-gram.y"
     { spec_file_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 16:
 
-/* Line 1285 of yacc.c  */
-#line 256 "parse-gram.y"
+/* Line 1535 of yacc.c  */
+#line 261 "parse-gram.y"
     {
       nondeterministic_parser = true;
       glr_parser = true;
@@ -1990,8 +1980,8 @@ yyreduce:
 
   case 17:
 
-/* Line 1285 of yacc.c  */
-#line 261 "parse-gram.y"
+/* Line 1535 of yacc.c  */
+#line 266 "parse-gram.y"
     {
       code_props action;
       code_props_symbol_action_init (&action, (yyvsp[(2) - (2)].code), (yylsp[(2) - (2)]));
@@ -2004,134 +1994,134 @@ yyreduce:
 
   case 18:
 
-/* Line 1285 of yacc.c  */
-#line 269 "parse-gram.y"
+/* Line 1535 of yacc.c  */
+#line 274 "parse-gram.y"
     { language_argmatch ((yyvsp[(2) - (2)].chars), 1, &(yylsp[(1) - (2)])); }
     break;
 
   case 19:
 
-/* Line 1285 of yacc.c  */
-#line 270 "parse-gram.y"
+/* Line 1535 of yacc.c  */
+#line 275 "parse-gram.y"
     { add_param ("lex_param", (yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
     break;
 
   case 20:
 
-/* Line 1285 of yacc.c  */
-#line 271 "parse-gram.y"
+/* Line 1535 of yacc.c  */
+#line 276 "parse-gram.y"
     { locations_flag = true; }
     break;
 
   case 21:
 
-/* Line 1285 of yacc.c  */
-#line 272 "parse-gram.y"
+/* Line 1535 of yacc.c  */
+#line 277 "parse-gram.y"
     { spec_name_prefix = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 22:
 
-/* Line 1285 of yacc.c  */
-#line 273 "parse-gram.y"
+/* Line 1535 of yacc.c  */
+#line 278 "parse-gram.y"
     { spec_name_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 23:
 
-/* Line 1285 of yacc.c  */
-#line 274 "parse-gram.y"
+/* Line 1535 of yacc.c  */
+#line 279 "parse-gram.y"
     { no_lines_flag = true; }
     break;
 
   case 24:
 
-/* Line 1285 of yacc.c  */
-#line 275 "parse-gram.y"
+/* Line 1535 of yacc.c  */
+#line 280 "parse-gram.y"
     { nondeterministic_parser = true; }
     break;
 
   case 25:
 
-/* Line 1285 of yacc.c  */
-#line 276 "parse-gram.y"
+/* Line 1535 of yacc.c  */
+#line 281 "parse-gram.y"
     { spec_outfile = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 26:
 
-/* Line 1285 of yacc.c  */
-#line 277 "parse-gram.y"
+/* Line 1535 of yacc.c  */
+#line 282 "parse-gram.y"
     { spec_outfile = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 27:
 
-/* Line 1285 of yacc.c  */
-#line 278 "parse-gram.y"
+/* Line 1535 of yacc.c  */
+#line 283 "parse-gram.y"
     { add_param ("parse_param", (yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
     break;
 
   case 28:
 
-/* Line 1285 of yacc.c  */
-#line 279 "parse-gram.y"
+/* Line 1535 of yacc.c  */
+#line 284 "parse-gram.y"
     { pure_parser = true; }
     break;
 
   case 29:
 
-/* Line 1285 of yacc.c  */
-#line 280 "parse-gram.y"
+/* Line 1535 of yacc.c  */
+#line 285 "parse-gram.y"
     { push_parser = true; pull_parser = false; }
     break;
 
   case 30:
 
-/* Line 1285 of yacc.c  */
-#line 281 "parse-gram.y"
+/* Line 1535 of yacc.c  */
+#line 286 "parse-gram.y"
     { push_parser = true; pull_parser = true; }
     break;
 
   case 31:
 
-/* Line 1285 of yacc.c  */
-#line 282 "parse-gram.y"
+/* Line 1535 of yacc.c  */
+#line 287 "parse-gram.y"
     { version_check (&(yylsp[(2) - (2)]), (yyvsp[(2) - (2)].chars)); }
     break;
 
   case 32:
 
-/* Line 1285 of yacc.c  */
-#line 283 "parse-gram.y"
+/* Line 1535 of yacc.c  */
+#line 288 "parse-gram.y"
     { skeleton_arg ((yyvsp[(2) - (2)].chars), 1, &(yylsp[(1) - (2)])); }
     break;
 
   case 33:
 
-/* Line 1285 of yacc.c  */
-#line 284 "parse-gram.y"
+/* Line 1535 of yacc.c  */
+#line 289 "parse-gram.y"
     { token_table_flag = true; }
     break;
 
   case 34:
 
-/* Line 1285 of yacc.c  */
-#line 285 "parse-gram.y"
+/* Line 1535 of yacc.c  */
+#line 290 "parse-gram.y"
     { report_flag = report_states; }
     break;
 
   case 35:
 
-/* Line 1285 of yacc.c  */
-#line 286 "parse-gram.y"
+/* Line 1535 of yacc.c  */
+#line 291 "parse-gram.y"
     { yacc_flag = true; }
     break;
 
   case 39:
 
-/* Line 1285 of yacc.c  */
-#line 294 "parse-gram.y"
+/* Line 1535 of yacc.c  */
+#line 299 "parse-gram.y"
     {
       grammar_start_symbol_set ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]));
     }
@@ -2139,8 +2129,8 @@ yyreduce:
 
   case 40:
 
-/* Line 1285 of yacc.c  */
-#line 298 "parse-gram.y"
+/* Line 1535 of yacc.c  */
+#line 303 "parse-gram.y"
     {
       symbol_list *list;
       for (list = (yyvsp[(3) - (3)].list); list; list = list->next)
@@ -2151,8 +2141,8 @@ yyreduce:
 
   case 41:
 
-/* Line 1285 of yacc.c  */
-#line 305 "parse-gram.y"
+/* Line 1535 of yacc.c  */
+#line 310 "parse-gram.y"
     {
       symbol_list *list;
       for (list = (yyvsp[(3) - (3)].list); list; list = list->next)
@@ -2163,8 +2153,8 @@ yyreduce:
 
   case 42:
 
-/* Line 1285 of yacc.c  */
-#line 312 "parse-gram.y"
+/* Line 1535 of yacc.c  */
+#line 317 "parse-gram.y"
     {
       default_prec = true;
     }
@@ -2172,8 +2162,8 @@ yyreduce:
 
   case 43:
 
-/* Line 1285 of yacc.c  */
-#line 316 "parse-gram.y"
+/* Line 1535 of yacc.c  */
+#line 321 "parse-gram.y"
     {
       default_prec = false;
     }
@@ -2181,8 +2171,8 @@ yyreduce:
 
   case 44:
 
-/* Line 1285 of yacc.c  */
-#line 320 "parse-gram.y"
+/* Line 1535 of yacc.c  */
+#line 325 "parse-gram.y"
     {
       muscle_code_grow ("percent_code", (yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)]));
       code_scanner_last_string_free ();
@@ -2191,8 +2181,8 @@ yyreduce:
 
   case 45:
 
-/* Line 1285 of yacc.c  */
-#line 325 "parse-gram.y"
+/* Line 1535 of yacc.c  */
+#line 330 "parse-gram.y"
     {
       /* FIXME: Special characters in $2 may break %code.
          For example: `['.  */
@@ -2203,28 +2193,28 @@ yyreduce:
       muscle_code_grow (uniqstr_new (name), (yyvsp[(3) - (3)].chars), (yylsp[(3) - (3)]));
       free (name);
       code_scanner_last_string_free ();
-      muscle_grow_used_name_list ("used_percent_code_qualifiers", (yyvsp[(2) - (3)].chars), (yylsp[(2) - (3)]));
+      muscle_grow_user_name_list ("user_percent_code_qualifiers", (yyvsp[(2) - (3)].chars), (yylsp[(2) - (3)]));
     }
     break;
 
   case 46:
 
-/* Line 1285 of yacc.c  */
-#line 347 "parse-gram.y"
+/* Line 1535 of yacc.c  */
+#line 352 "parse-gram.y"
     {}
     break;
 
   case 47:
 
-/* Line 1285 of yacc.c  */
-#line 348 "parse-gram.y"
+/* Line 1535 of yacc.c  */
+#line 353 "parse-gram.y"
     { muscle_code_grow ("union_name", (yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 48:
 
-/* Line 1285 of yacc.c  */
-#line 353 "parse-gram.y"
+/* Line 1535 of yacc.c  */
+#line 358 "parse-gram.y"
     {
       char const *body = (yyvsp[(3) - (3)].code);
 
@@ -2251,15 +2241,15 @@ yyreduce:
 
   case 49:
 
-/* Line 1285 of yacc.c  */
-#line 381 "parse-gram.y"
+/* Line 1535 of yacc.c  */
+#line 386 "parse-gram.y"
     { current_class = nterm_sym; }
     break;
 
   case 50:
 
-/* Line 1285 of yacc.c  */
-#line 382 "parse-gram.y"
+/* Line 1535 of yacc.c  */
+#line 387 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
@@ -2268,15 +2258,15 @@ yyreduce:
 
   case 51:
 
-/* Line 1285 of yacc.c  */
-#line 386 "parse-gram.y"
+/* Line 1535 of yacc.c  */
+#line 391 "parse-gram.y"
     { current_class = token_sym; }
     break;
 
   case 52:
 
-/* Line 1285 of yacc.c  */
-#line 387 "parse-gram.y"
+/* Line 1535 of yacc.c  */
+#line 392 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
@@ -2285,8 +2275,8 @@ yyreduce:
 
   case 53:
 
-/* Line 1285 of yacc.c  */
-#line 392 "parse-gram.y"
+/* Line 1535 of yacc.c  */
+#line 397 "parse-gram.y"
     {
       symbol_list *list;
       tag_seen = true;
@@ -2298,8 +2288,8 @@ yyreduce:
 
   case 54:
 
-/* Line 1285 of yacc.c  */
-#line 403 "parse-gram.y"
+/* Line 1535 of yacc.c  */
+#line 408 "parse-gram.y"
     {
       symbol_list *list;
       ++current_prec;
@@ -2315,99 +2305,99 @@ yyreduce:
 
   case 55:
 
-/* Line 1285 of yacc.c  */
-#line 417 "parse-gram.y"
+/* Line 1535 of yacc.c  */
+#line 422 "parse-gram.y"
     { (yyval.assoc) = left_assoc; }
     break;
 
   case 56:
 
-/* Line 1285 of yacc.c  */
-#line 418 "parse-gram.y"
+/* Line 1535 of yacc.c  */
+#line 423 "parse-gram.y"
     { (yyval.assoc) = right_assoc; }
     break;
 
   case 57:
 
-/* Line 1285 of yacc.c  */
-#line 419 "parse-gram.y"
+/* Line 1535 of yacc.c  */
+#line 424 "parse-gram.y"
     { (yyval.assoc) = non_assoc; }
     break;
 
   case 58:
 
-/* Line 1285 of yacc.c  */
-#line 423 "parse-gram.y"
+/* Line 1535 of yacc.c  */
+#line 428 "parse-gram.y"
     { current_type = NULL; }
     break;
 
   case 59:
 
-/* Line 1285 of yacc.c  */
-#line 424 "parse-gram.y"
+/* Line 1535 of yacc.c  */
+#line 429 "parse-gram.y"
     { current_type = (yyvsp[(1) - (1)].uniqstr); tag_seen = true; }
     break;
 
   case 60:
 
-/* Line 1285 of yacc.c  */
-#line 430 "parse-gram.y"
+/* Line 1535 of yacc.c  */
+#line 435 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 61:
 
-/* Line 1285 of yacc.c  */
-#line 432 "parse-gram.y"
+/* Line 1535 of yacc.c  */
+#line 437 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), symbol_list_sym_new ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]))); }
     break;
 
   case 62:
 
-/* Line 1285 of yacc.c  */
-#line 436 "parse-gram.y"
+/* Line 1535 of yacc.c  */
+#line 441 "parse-gram.y"
     { (yyval.list) = (yyvsp[(1) - (1)].list); }
     break;
 
   case 63:
 
-/* Line 1285 of yacc.c  */
-#line 437 "parse-gram.y"
+/* Line 1535 of yacc.c  */
+#line 442 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), (yyvsp[(2) - (2)].list)); }
     break;
 
   case 64:
 
-/* Line 1285 of yacc.c  */
-#line 441 "parse-gram.y"
+/* Line 1535 of yacc.c  */
+#line 446 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 65:
 
-/* Line 1285 of yacc.c  */
-#line 442 "parse-gram.y"
+/* Line 1535 of yacc.c  */
+#line 447 "parse-gram.y"
     { (yyval.list) = symbol_list_type_new ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 66:
 
-/* Line 1285 of yacc.c  */
-#line 443 "parse-gram.y"
+/* Line 1535 of yacc.c  */
+#line 448 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagged_new ((yylsp[(1) - (1)])); }
     break;
 
   case 67:
 
-/* Line 1285 of yacc.c  */
-#line 444 "parse-gram.y"
+/* Line 1535 of yacc.c  */
+#line 449 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagless_new ((yylsp[(1) - (1)])); }
     break;
 
   case 68:
 
-/* Line 1285 of yacc.c  */
-#line 450 "parse-gram.y"
+/* Line 1535 of yacc.c  */
+#line 455 "parse-gram.y"
     {
        current_type = (yyvsp[(1) - (1)].uniqstr);
        tag_seen = true;
@@ -2416,8 +2406,8 @@ yyreduce:
 
   case 69:
 
-/* Line 1285 of yacc.c  */
-#line 455 "parse-gram.y"
+/* Line 1535 of yacc.c  */
+#line 460 "parse-gram.y"
     {
        symbol_class_set ((yyvsp[(1) - (1)].symbol), current_class, (yylsp[(1) - (1)]), true);
        symbol_type_set ((yyvsp[(1) - (1)].symbol), current_type, (yylsp[(1) - (1)]));
@@ -2426,8 +2416,8 @@ yyreduce:
 
   case 70:
 
-/* Line 1285 of yacc.c  */
-#line 460 "parse-gram.y"
+/* Line 1535 of yacc.c  */
+#line 465 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
       symbol_type_set ((yyvsp[(1) - (2)].symbol), current_type, (yylsp[(1) - (2)]));
@@ -2437,8 +2427,8 @@ yyreduce:
 
   case 71:
 
-/* Line 1285 of yacc.c  */
-#line 466 "parse-gram.y"
+/* Line 1535 of yacc.c  */
+#line 471 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
       symbol_type_set ((yyvsp[(1) - (2)].symbol), current_type, (yylsp[(1) - (2)]));
@@ -2448,8 +2438,8 @@ yyreduce:
 
   case 72:
 
-/* Line 1285 of yacc.c  */
-#line 472 "parse-gram.y"
+/* Line 1535 of yacc.c  */
+#line 477 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (3)].symbol), current_class, (yylsp[(1) - (3)]), true);
       symbol_type_set ((yyvsp[(1) - (3)].symbol), current_type, (yylsp[(1) - (3)]));
@@ -2460,8 +2450,8 @@ yyreduce:
 
   case 79:
 
-/* Line 1285 of yacc.c  */
-#line 502 "parse-gram.y"
+/* Line 1535 of yacc.c  */
+#line 507 "parse-gram.y"
     {
       yyerrok;
     }
@@ -2469,70 +2459,70 @@ yyreduce:
 
   case 80:
 
-/* Line 1285 of yacc.c  */
-#line 508 "parse-gram.y"
+/* Line 1535 of yacc.c  */
+#line 513 "parse-gram.y"
     { current_lhs = (yyvsp[(1) - (1)].symbol); current_lhs_location = (yylsp[(1) - (1)]); }
     break;
 
   case 82:
 
-/* Line 1285 of yacc.c  */
-#line 512 "parse-gram.y"
+/* Line 1535 of yacc.c  */
+#line 517 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(1) - (1)])); }
     break;
 
   case 83:
 
-/* Line 1285 of yacc.c  */
-#line 513 "parse-gram.y"
+/* Line 1535 of yacc.c  */
+#line 518 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(3) - (3)])); }
     break;
 
   case 85:
 
-/* Line 1285 of yacc.c  */
-#line 519 "parse-gram.y"
+/* Line 1535 of yacc.c  */
+#line 524 "parse-gram.y"
     { grammar_current_rule_begin (current_lhs, current_lhs_location); }
     break;
 
   case 86:
 
-/* Line 1285 of yacc.c  */
-#line 521 "parse-gram.y"
+/* Line 1535 of yacc.c  */
+#line 526 "parse-gram.y"
     { grammar_current_rule_symbol_append ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)])); }
     break;
 
   case 87:
 
-/* Line 1285 of yacc.c  */
-#line 523 "parse-gram.y"
+/* Line 1535 of yacc.c  */
+#line 528 "parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
     break;
 
   case 88:
 
-/* Line 1285 of yacc.c  */
-#line 525 "parse-gram.y"
+/* Line 1535 of yacc.c  */
+#line 530 "parse-gram.y"
     { grammar_current_rule_prec_set ((yyvsp[(3) - (3)].symbol), (yylsp[(3) - (3)])); }
     break;
 
   case 89:
 
-/* Line 1285 of yacc.c  */
-#line 527 "parse-gram.y"
+/* Line 1535 of yacc.c  */
+#line 532 "parse-gram.y"
     { grammar_current_rule_dprec_set ((yyvsp[(3) - (3)].integer), (yylsp[(3) - (3)])); }
     break;
 
   case 90:
 
-/* Line 1285 of yacc.c  */
-#line 529 "parse-gram.y"
+/* Line 1535 of yacc.c  */
+#line 534 "parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[(3) - (3)].uniqstr), (yylsp[(3) - (3)])); }
     break;
 
-  case 93:
+  case 91:
 
-/* Line 1285 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 545 "parse-gram.y"
     {
       static char one[] = "1";
@@ -2540,10 +2530,10 @@ yyreduce:
     }
     break;
 
-  case 95:
+  case 93:
 
-/* Line 1285 of yacc.c  */
-#line 555 "parse-gram.y"
+/* Line 1535 of yacc.c  */
+#line 559 "parse-gram.y"
     {
       code_props plain_code;
       (yyvsp[(1) - (1)].code)[strlen ((yyvsp[(1) - (1)].code)) - 1] = '\n';
@@ -2554,17 +2544,17 @@ yyreduce:
     }
     break;
 
-  case 96:
+  case 94:
 
-/* Line 1285 of yacc.c  */
-#line 575 "parse-gram.y"
+/* Line 1535 of yacc.c  */
+#line 579 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
-  case 97:
+  case 95:
 
-/* Line 1285 of yacc.c  */
-#line 577 "parse-gram.y"
+/* Line 1535 of yacc.c  */
+#line 581 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[(1) - (1)].character)), (yylsp[(1) - (1)]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[(1) - (1)]), false);
@@ -2572,27 +2562,27 @@ yyreduce:
     }
     break;
 
-  case 98:
+  case 96:
 
-/* Line 1285 of yacc.c  */
-#line 585 "parse-gram.y"
+/* Line 1535 of yacc.c  */
+#line 589 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
-  case 101:
+  case 99:
 
-/* Line 1285 of yacc.c  */
-#line 597 "parse-gram.y"
+/* Line 1535 of yacc.c  */
+#line 601 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[(1) - (1)].chars)), (yylsp[(1) - (1)]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[(1) - (1)]), false);
     }
     break;
 
-  case 103:
+  case 101:
 
-/* Line 1285 of yacc.c  */
-#line 606 "parse-gram.y"
+/* Line 1535 of yacc.c  */
+#line 610 "parse-gram.y"
     {
       code_props plain_code;
       code_props_plain_init (&plain_code, (yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)]));
@@ -2605,8 +2595,8 @@ yyreduce:
 
 
 
-/* Line 1285 of yacc.c  */
-#line 2610 "parse-gram.c"
+/* Line 1535 of yacc.c  */
+#line 2600 "parse-gram.c"
       default: break;
     }
   YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);
@@ -2824,8 +2814,8 @@ yyreturn:
 
 
 
-/* Line 1502 of yacc.c  */
-#line 616 "parse-gram.y"
+/* Line 1535 of yacc.c  */
+#line 620 "parse-gram.y"
 
 
 
