@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 3.2.1.46-77eb-dirty.  */
+/* A Bison parser, made by GNU Bison 3.2.1.57-7965.  */
 
 /* Bison implementation for Yacc-like parsers in C
 
@@ -47,7 +47,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "3.2.1.46-77eb-dirty"
+#define YYBISON_VERSION "3.2.1.57-7965"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -133,7 +133,7 @@ extern int gram_debug;
     param_parse  = 1 << 1,
     param_both   = param_lex | param_parse
   } param_type;
-#line 612 "src/parse-gram.y" /* yacc.c:353  */
+#line 636 "src/parse-gram.y" /* yacc.c:353  */
 
   #include "muscle-tab.h"
   typedef struct
@@ -590,16 +590,16 @@ union yyalloc
 /* YYFINAL -- State number of the termination state.  */
 #define YYFINAL  3
 /* YYLAST -- Last index in YYTABLE.  */
-#define YYLAST   172
+#define YYLAST   212
 
 /* YYNTOKENS -- Number of terminals.  */
 #define YYNTOKENS  57
 /* YYNNTS -- Number of nonterminals.  */
 #define YYNNTS  37
 /* YYNRULES -- Number of rules.  */
-#define YYNRULES  110
+#define YYNRULES  111
 /* YYNSTATES -- Number of states.  */
-#define YYNSTATES  147
+#define YYNSTATES  149
 
 #define YYUNDEFTOK  2
 #define YYMAXUTOK   311
@@ -653,16 +653,16 @@ static const yytype_uint16 yyrline[] =
 {
        0,   260,   260,   269,   270,   274,   275,   281,   285,   290,
      291,   296,   297,   298,   299,   304,   309,   310,   311,   312,
-     313,   314,   314,   315,   316,   317,   318,   319,   320,   324,
-     325,   334,   335,   336,   340,   351,   355,   359,   367,   377,
-     378,   388,   389,   395,   407,   407,   412,   412,   417,   427,
-     441,   442,   443,   444,   448,   449,   454,   456,   461,   466,
-     476,   478,   483,   484,   488,   489,   493,   494,   495,   500,
-     505,   510,   516,   522,   533,   534,   543,   544,   550,   551,
-     552,   559,   559,   567,   568,   569,   574,   577,   579,   581,
-     583,   585,   587,   589,   591,   593,   598,   599,   608,   632,
-     633,   634,   635,   647,   649,   658,   663,   664,   669,   677,
-     678
+     313,   314,   314,   315,   316,   317,   318,   319,   320,   321,
+     325,   326,   335,   336,   337,   341,   352,   356,   360,   368,
+     378,   379,   389,   390,   396,   408,   408,   413,   413,   418,
+     428,   442,   443,   444,   445,   449,   450,   455,   457,   462,
+     467,   477,   479,   484,   485,   489,   490,   494,   495,   496,
+     501,   506,   511,   523,   535,   554,   555,   567,   568,   574,
+     575,   576,   583,   583,   591,   592,   593,   598,   601,   603,
+     605,   607,   609,   611,   613,   615,   617,   622,   623,   632,
+     656,   657,   658,   659,   671,   673,   688,   693,   694,   699,
+     707,   708
 };
 #endif
 
@@ -710,35 +710,35 @@ static const yytype_uint16 yytoknum[] =
 };
 # endif
 
-#define YYPACT_NINF -123
+#define YYPACT_NINF -124
 
 #define yypact_value_is_default(Yystate) \
-  (!!((Yystate) == (-123)))
+  (!!((Yystate) == (-124)))
 
-#define YYTABLE_NINF -110
+#define YYTABLE_NINF -111
 
 #define yytable_value_is_error(Yytable_value) \
   0
 
   /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
      STATE-NUM.  */
-static const yytype_int8 yypact[] =
+static const yytype_int16 yypact[] =
 {
-    -123,    25,   117,  -123,  -123,  -123,   -22,  -123,  -123,  -123,
-    -123,  -123,  -123,   -17,  -123,    -9,    34,   -15,   -14,  -123,
-      37,  -123,     3,    40,    46,  -123,  -123,  -123,    49,    50,
-      51,    28,  -123,  -123,  -123,    54,  -123,  -123,  -123,    29,
-    -123,  -123,    38,  -123,  -123,    31,   -21,   -21,    28,  -123,
-      52,  -123,    30,  -123,  -123,  -123,  -123,  -123,  -123,  -123,
-    -123,  -123,  -123,  -123,  -123,  -123,  -123,  -123,  -123,    26,
-    -123,    47,     2,  -123,  -123,    57,    53,  -123,    62,    42,
-    -123,    28,  -123,  -123,   -21,    -2,   -21,    28,  -123,  -123,
-    -123,  -123,  -123,  -123,  -123,  -123,    45,  -123,  -123,  -123,
-    -123,  -123,    63,  -123,  -123,  -123,  -123,    42,  -123,  -123,
-    -123,    28,  -123,    36,  -123,   101,  -123,  -123,  -123,  -123,
-    -123,  -123,  -123,  -123,  -123,   -23,    64,  -123,  -123,    28,
-      58,    56,    59,    60,  -123,  -123,    72,    57,    64,  -123,
-    -123,  -123,  -123,  -123,    57,  -123,  -123
+    -124,     1,   105,  -124,   -43,  -124,  -124,   -28,  -124,  -124,
+    -124,  -124,  -124,  -124,   -17,  -124,   -15,    29,   -20,   -13,
+    -124,    41,  -124,     7,    47,    51,  -124,  -124,  -124,    53,
+      61,    65,     2,  -124,  -124,  -124,   157,  -124,  -124,  -124,
+      25,  -124,  -124,    32,  -124,  -124,    30,  -124,    38,    38,
+       2,  -124,    37,  -124,    23,  -124,  -124,  -124,  -124,  -124,
+    -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,
+    -124,    34,  -124,    35,     3,  -124,  -124,    45,    48,  -124,
+      49,    22,  -124,     2,  -124,  -124,    38,    -1,    38,     2,
+    -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,    50,  -124,
+    -124,  -124,  -124,  -124,    52,  -124,  -124,  -124,  -124,    22,
+    -124,  -124,  -124,     2,  -124,    36,  -124,    88,  -124,  -124,
+    -124,  -124,  -124,  -124,  -124,  -124,  -124,   -19,    21,  -124,
+    -124,     2,    40,    44,    42,    54,  -124,  -124,    59,    45,
+      21,  -124,  -124,  -124,  -124,  -124,    45,  -124,  -124
 };
 
   /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
@@ -746,39 +746,39 @@ static const yytype_int8 yypact[] =
      means the default is an error.  */
 static const yytype_uint8 yydefact[] =
 {
-       3,     0,     0,     1,    46,    44,     0,    39,    40,    50,
-      51,    52,    53,     0,    35,     0,     9,     0,     0,     7,
-       0,    14,     0,     0,     0,    36,    18,    19,     0,     0,
-       0,     0,    25,    26,    27,     0,     6,    28,    21,    41,
-       4,     5,     0,    32,    31,    54,     0,     0,     0,    37,
-       0,    98,    99,    10,    11,    12,    13,    15,    16,    17,
-      20,    23,    24,   108,   104,   103,   106,    33,   107,     0,
-     105,     0,     0,    76,    78,    96,     0,    42,     0,     0,
-      55,     0,    69,    74,    47,    70,    45,    48,    60,    38,
-     101,   102,   100,     8,    80,    79,     0,    77,     2,    97,
-      81,    30,    22,    43,    66,    67,    68,    34,    62,    65,
-      64,    49,    56,    58,    75,    71,    72,    61,   110,    86,
-      29,    63,    57,    59,    73,    82,    83,    86,    85,     0,
-       0,     0,     0,     0,    89,    90,     0,    96,    84,    91,
-      92,    93,    94,    95,    96,    87,    88
+       3,     0,     0,     1,     0,    47,    45,     0,    40,    41,
+      51,    52,    53,    54,     0,    36,     0,     9,     0,     0,
+       7,     0,    14,     0,     0,     0,    37,    18,    19,     0,
+       0,     0,     0,    25,    26,    27,     0,     6,    29,    21,
+      42,     4,     5,     0,    33,    32,    55,    28,     0,     0,
+       0,    38,     0,    99,   100,    10,    11,    12,    13,    15,
+      16,    17,    20,    23,    24,   109,   105,   104,   107,    34,
+     108,     0,   106,     0,     0,    77,    79,    97,     0,    43,
+       0,     0,    56,     0,    70,    75,    48,    71,    46,    49,
+      61,    39,   102,   103,   101,     8,    81,    80,     0,    78,
+       2,    98,    82,    31,    22,    44,    67,    68,    69,    35,
+      63,    66,    65,    50,    57,    59,    76,    72,    73,    62,
+     111,    87,    30,    64,    58,    60,    74,    83,    84,    87,
+      86,     0,     0,     0,     0,     0,    90,    91,     0,    97,
+      85,    92,    93,    94,    95,    96,    97,    88,    89
 };
 
   /* YYPGOTO[NTERM-NUM].  */
 static const yytype_int8 yypgoto[] =
 {
-    -123,  -123,  -123,  -123,  -123,  -123,   113,  -123,  -123,  -123,
-    -123,  -123,  -123,  -123,    71,  -123,     6,  -123,  -123,    11,
-    -123,   -52,    83,  -123,    84,  -123,  -123,  -123,    -8,  -122,
-    -123,  -123,   -42,  -123,   -31,   -69,  -123
+    -124,  -124,  -124,  -124,  -124,  -124,    96,  -124,  -124,  -124,
+    -124,  -124,  -124,  -124,    55,  -124,   -11,  -124,  -124,    -9,
+    -124,   -33,    56,  -124,    46,  -124,  -124,  -124,   -26,  -123,
+    -124,  -124,   -10,  -124,   -32,   -70,  -124
 };
 
   /* YYDEFGOTO[NTERM-NUM].  */
 static const yytype_int16 yydefgoto[] =
 {
-      -1,     1,     2,    40,    76,   102,    71,    42,    78,    43,
-      47,    46,    44,    45,   136,   111,   112,    87,   107,   108,
-     109,    83,    84,    72,    73,    74,   119,   125,   126,   100,
-      52,    93,    66,    75,   110,    68,    98
+      -1,     1,     2,    41,    78,   104,    73,    43,    80,    44,
+      49,    48,    45,    46,   138,   113,   114,    89,   109,   110,
+     111,    85,    86,    74,    75,    76,   121,   127,   128,   102,
+      54,    95,    68,    77,   112,    70,   100
 };
 
   /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
@@ -786,67 +786,75 @@ static const yytype_int16 yydefgoto[] =
      number is the opposite.  If YYTABLE_NINF, syntax error.  */
 static const yytype_int16 yytable[] =
 {
-      67,    63,  -109,    69,    85,    85,     4,     5,     6,     7,
-       8,     9,    10,    11,    12,   145,   116,    88,    13,    14,
-      64,    49,   146,    65,   127,     3,   128,    50,    48,    82,
-      25,    63,   114,    90,   114,    51,    31,    53,    54,    55,
-      56,    57,    85,    58,    85,    63,   124,    70,    96,    59,
-     113,   115,    60,    61,    62,    69,   117,    39,     4,     5,
-       6,     7,     8,     9,    10,    11,    12,    63,    91,    64,
-      13,    14,    65,    77,    92,    94,    79,   129,   130,   131,
-     113,    80,    25,    64,   132,   133,    65,   118,    31,   123,
-      89,   101,   104,   105,   106,   137,    95,    99,   139,    70,
-     103,   120,   -54,   134,    63,    64,   141,   137,    65,    39,
-     144,   140,   142,   143,    80,    41,    81,   122,   121,   138,
-     135,     4,     5,     6,     7,     8,     9,    10,    11,    12,
-      86,     0,     0,    13,    14,    15,    16,    17,    18,    19,
-      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
-      30,    31,    32,    33,    34,     0,    97,     0,     0,     0,
-       0,     0,     0,    35,     0,    36,    37,     0,     0,     0,
-       0,    38,    39
+      69,     3,    65,  -110,    71,    65,    47,     5,     6,     7,
+       8,     9,    10,    11,    12,    13,   147,   118,    90,    14,
+      15,    51,    50,   148,    65,    65,    92,    52,   129,    53,
+     130,    26,    55,    56,   131,   132,   133,    32,    87,    87,
+      57,   134,   135,    66,    58,    59,    67,   126,    72,    98,
+      60,   115,   117,   116,    61,   116,    62,   119,    40,   -55,
+     136,    93,    66,    66,    63,    67,    67,    94,    64,    79,
+      81,    82,   106,   107,   108,    91,    87,   137,    87,    66,
+      82,   115,    67,    96,    97,   101,   103,   105,    84,   125,
+     122,    65,   120,   142,   143,   144,   139,   146,    42,   141,
+     123,    83,   124,   140,     0,    88,     4,   145,   139,     5,
+       6,     7,     8,     9,    10,    11,    12,    13,     0,     0,
+      99,    14,    15,    16,    17,    18,    19,    20,    21,    22,
+      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
+      33,    34,    35,     0,     0,     0,     0,     0,     0,     0,
+       0,    36,     0,    37,    38,     0,     0,     0,    71,    39,
+      40,     5,     6,     7,     8,     9,    10,    11,    12,    13,
+       0,     0,     0,    14,    15,     0,     0,     0,     0,     0,
+       0,     0,     0,     0,     0,    26,     0,     0,     0,     0,
+       0,    32,     0,     0,     0,     0,     0,     0,     0,     0,
+       0,     0,    72,     0,     0,     0,     0,     0,     0,     0,
+       0,     0,    40
 };
 
 static const yytype_int16 yycheck[] =
 {
-      31,     3,     0,     1,    46,    47,     4,     5,     6,     7,
-       8,     9,    10,    11,    12,   137,    85,    48,    16,    17,
-      41,    38,   144,    44,    47,     0,    49,    44,    50,    50,
-      28,     3,    84,     3,    86,    44,    34,     3,    53,    53,
-       3,    38,    84,     3,    86,     3,   115,    45,    46,     3,
-      81,    53,     3,     3,     3,     1,    87,    55,     4,     5,
-       6,     7,     8,     9,    10,    11,    12,     3,    38,    41,
-      16,    17,    44,    44,    44,    49,    38,    13,    14,    15,
-     111,    50,    28,    41,    20,    21,    44,    42,    34,    53,
-      38,    38,    50,    51,    52,   126,    49,    40,   129,    45,
-      38,    38,    38,    39,     3,    41,    50,   138,    44,    55,
-      38,    53,    53,    53,    50,     2,    45,   111,   107,   127,
-      56,     4,     5,     6,     7,     8,     9,    10,    11,    12,
-      47,    -1,    -1,    16,    17,    18,    19,    20,    21,    22,
-      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
-      33,    34,    35,    36,    37,    -1,    72,    -1,    -1,    -1,
-      -1,    -1,    -1,    46,    -1,    48,    49,    -1,    -1,    -1,
-      -1,    54,    55
+      32,     0,     3,     0,     1,     3,    49,     4,     5,     6,
+       7,     8,     9,    10,    11,    12,   139,    87,    50,    16,
+      17,    38,    50,   146,     3,     3,     3,    44,    47,    44,
+      49,    28,     3,    53,    13,    14,    15,    34,    48,    49,
+      53,    20,    21,    41,     3,    38,    44,   117,    45,    46,
+       3,    83,    53,    86,     3,    88,     3,    89,    55,    38,
+      39,    38,    41,    41,     3,    44,    44,    44,     3,    44,
+      38,    50,    50,    51,    52,    38,    86,    56,    88,    41,
+      50,   113,    44,    49,    49,    40,    38,    38,    50,    53,
+      38,     3,    42,    53,    50,    53,   128,    38,     2,   131,
+     109,    46,   113,   129,    -1,    49,     1,    53,   140,     4,
+       5,     6,     7,     8,     9,    10,    11,    12,    -1,    -1,
+      74,    16,    17,    18,    19,    20,    21,    22,    23,    24,
+      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
+      35,    36,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
+      -1,    46,    -1,    48,    49,    -1,    -1,    -1,     1,    54,
+      55,     4,     5,     6,     7,     8,     9,    10,    11,    12,
+      -1,    -1,    -1,    16,    17,    -1,    -1,    -1,    -1,    -1,
+      -1,    -1,    -1,    -1,    -1,    28,    -1,    -1,    -1,    -1,
+      -1,    34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
+      -1,    -1,    45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
+      -1,    -1,    55
 };
 
   /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
      symbol of state STATE-NUM.  */
 static const yytype_uint8 yystos[] =
 {
-       0,    58,    59,     0,     4,     5,     6,     7,     8,     9,
-      10,    11,    12,    16,    17,    18,    19,    20,    21,    22,
-      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
-      33,    34,    35,    36,    37,    46,    48,    49,    54,    55,
-      60,    63,    64,    66,    69,    70,    68,    67,    50,    38,
-      44,    44,    87,     3,    53,    53,     3,    38,     3,     3,
-       3,     3,     3,     3,    41,    44,    89,    91,    92,     1,
-      45,    63,    80,    81,    82,    90,    61,    44,    65,    38,
-      50,    71,    50,    78,    79,    89,    79,    74,    91,    38,
-       3,    38,    44,    88,    49,    49,    46,    81,    93,    40,
-      86,    38,    62,    38,    50,    51,    52,    75,    76,    77,
-      91,    72,    73,    91,    78,    53,    92,    91,    42,    83,
-      38,    76,    73,    53,    92,    84,    85,    47,    49,    13,
-      14,    15,    20,    21,    39,    56,    71,    91,    85,    91,
-      53,    50,    53,    53,    38,    86,    86
+       0,    58,    59,     0,     1,     4,     5,     6,     7,     8,
+       9,    10,    11,    12,    16,    17,    18,    19,    20,    21,
+      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
+      32,    33,    34,    35,    36,    37,    46,    48,    49,    54,
+      55,    60,    63,    64,    66,    69,    70,    49,    68,    67,
+      50,    38,    44,    44,    87,     3,    53,    53,     3,    38,
+       3,     3,     3,     3,     3,     3,    41,    44,    89,    91,
+      92,     1,    45,    63,    80,    81,    82,    90,    61,    44,
+      65,    38,    50,    71,    50,    78,    79,    89,    79,    74,
+      91,    38,     3,    38,    44,    88,    49,    49,    46,    81,
+      93,    40,    86,    38,    62,    38,    50,    51,    52,    75,
+      76,    77,    91,    72,    73,    91,    78,    53,    92,    91,
+      42,    83,    38,    76,    73,    53,    92,    84,    85,    47,
+      49,    13,    14,    15,    20,    21,    39,    56,    71,    91,
+      85,    91,    53,    50,    53,    53,    38,    86,    86
 };
 
   /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
@@ -854,16 +862,16 @@ static const yytype_uint8 yyr1[] =
 {
        0,    57,    58,    59,    59,    60,    60,    60,    60,    60,
       60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
-      60,    61,    60,    60,    60,    60,    60,    60,    60,    62,
-      62,    63,    63,    63,    63,    63,    63,    63,    63,    64,
-      64,    65,    65,    63,    67,    66,    68,    66,    66,    69,
-      70,    70,    70,    70,    71,    71,    72,    72,    73,    73,
-      74,    74,    75,    75,    76,    76,    77,    77,    77,    78,
-      78,    78,    78,    78,    79,    79,    80,    80,    81,    81,
-      81,    83,    82,    84,    84,    84,    85,    85,    85,    85,
-      85,    85,    85,    85,    85,    85,    86,    86,    87,    88,
-      88,    88,    88,    89,    89,    90,    91,    91,    92,    93,
-      93
+      60,    61,    60,    60,    60,    60,    60,    60,    60,    60,
+      62,    62,    63,    63,    63,    63,    63,    63,    63,    63,
+      64,    64,    65,    65,    63,    67,    66,    68,    66,    66,
+      69,    70,    70,    70,    70,    71,    71,    72,    72,    73,
+      73,    74,    74,    75,    75,    76,    76,    77,    77,    77,
+      78,    78,    78,    78,    78,    79,    79,    80,    80,    81,
+      81,    81,    83,    82,    84,    84,    84,    85,    85,    85,
+      85,    85,    85,    85,    85,    85,    85,    86,    86,    87,
+      88,    88,    88,    88,    89,    89,    90,    91,    91,    92,
+      93,    93
 };
 
   /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
@@ -871,16 +879,16 @@ static const yytype_uint8 yyr2[] =
 {
        0,     2,     4,     0,     2,     1,     1,     1,     3,     1,
        2,     2,     2,     2,     1,     2,     2,     2,     1,     1,
-       2,     0,     3,     2,     2,     1,     1,     1,     1,     2,
-       1,     1,     1,     2,     3,     1,     1,     2,     3,     1,
-       1,     0,     1,     3,     0,     3,     0,     3,     3,     3,
-       1,     1,     1,     1,     0,     1,     1,     2,     1,     2,
-       1,     2,     1,     2,     1,     1,     1,     1,     1,     1,
-       1,     2,     2,     3,     1,     2,     1,     2,     1,     2,
-       2,     0,     4,     1,     3,     2,     0,     3,     4,     2,
-       2,     3,     3,     3,     3,     3,     0,     1,     1,     0,
-       1,     1,     1,     1,     1,     1,     1,     1,     1,     0,
-       2
+       2,     0,     3,     2,     2,     1,     1,     1,     2,     1,
+       2,     1,     1,     1,     2,     3,     1,     1,     2,     3,
+       1,     1,     0,     1,     3,     0,     3,     0,     3,     3,
+       3,     1,     1,     1,     1,     0,     1,     1,     2,     1,
+       2,     1,     2,     1,     2,     1,     1,     1,     1,     1,
+       1,     1,     2,     2,     3,     1,     2,     1,     2,     1,
+       2,     2,     0,     4,     1,     3,     2,     0,     3,     4,
+       2,     2,     3,     3,     3,     3,     3,     0,     1,     1,
+       0,     1,     1,     1,     1,     1,     1,     1,     1,     1,
+       0,     2
 };
 
 
@@ -1038,73 +1046,73 @@ yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YY
           case 3: /* "string"  */
 #line 191 "src/parse-gram.y" /* yacc.c:681  */
       { fputs (quotearg_style (c_quoting_style, (*(char**)(&(*yyvaluep)))), yyo); }
-#line 1042 "src/parse-gram.c" /* yacc.c:681  */
+#line 1050 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 22: /* "%<flag>"  */
 #line 198 "src/parse-gram.y" /* yacc.c:681  */
       { fprintf (yyo, "%%%s", (*(uniqstr*)(&(*yyvaluep)))); }
-#line 1048 "src/parse-gram.c" /* yacc.c:681  */
+#line 1056 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 38: /* "{...}"  */
 #line 192 "src/parse-gram.y" /* yacc.c:681  */
       { fprintf (yyo, "{\n%s\n}", (*(char**)(&(*yyvaluep)))); }
-#line 1054 "src/parse-gram.c" /* yacc.c:681  */
+#line 1062 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 39: /* "%?{...}"  */
 #line 192 "src/parse-gram.y" /* yacc.c:681  */
       { fprintf (yyo, "{\n%s\n}", (*(char**)(&(*yyvaluep)))); }
-#line 1060 "src/parse-gram.c" /* yacc.c:681  */
+#line 1068 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 40: /* "[identifier]"  */
 #line 196 "src/parse-gram.y" /* yacc.c:681  */
       { fprintf (yyo, "[%s]", (*(uniqstr*)(&(*yyvaluep)))); }
-#line 1066 "src/parse-gram.c" /* yacc.c:681  */
+#line 1074 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 41: /* "char"  */
 #line 188 "src/parse-gram.y" /* yacc.c:681  */
       { fputs (char_name ((*(unsigned char*)(&(*yyvaluep)))), yyo); }
-#line 1072 "src/parse-gram.c" /* yacc.c:681  */
+#line 1080 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 42: /* "epilogue"  */
 #line 192 "src/parse-gram.y" /* yacc.c:681  */
       { fprintf (yyo, "{\n%s\n}", (*(char**)(&(*yyvaluep)))); }
-#line 1078 "src/parse-gram.c" /* yacc.c:681  */
+#line 1086 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 44: /* "identifier"  */
 #line 195 "src/parse-gram.y" /* yacc.c:681  */
       { fputs ((*(uniqstr*)(&(*yyvaluep))), yyo); }
-#line 1084 "src/parse-gram.c" /* yacc.c:681  */
+#line 1092 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 45: /* "identifier:"  */
 #line 197 "src/parse-gram.y" /* yacc.c:681  */
       { fprintf (yyo, "%s:", (*(uniqstr*)(&(*yyvaluep)))); }
-#line 1090 "src/parse-gram.c" /* yacc.c:681  */
+#line 1098 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 48: /* "%{...%}"  */
 #line 192 "src/parse-gram.y" /* yacc.c:681  */
       { fprintf (yyo, "{\n%s\n}", (*(char**)(&(*yyvaluep)))); }
-#line 1096 "src/parse-gram.c" /* yacc.c:681  */
+#line 1104 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 50: /* "<tag>"  */
 #line 199 "src/parse-gram.y" /* yacc.c:681  */
       { fprintf (yyo, "<%s>", (*(uniqstr*)(&(*yyvaluep)))); }
-#line 1102 "src/parse-gram.c" /* yacc.c:681  */
+#line 1110 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 53: /* "integer"  */
 #line 202 "src/parse-gram.y" /* yacc.c:681  */
       { fprintf (yyo, "%d", (*(int*)(&(*yyvaluep)))); }
-#line 1108 "src/parse-gram.c" /* yacc.c:681  */
+#line 1116 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 54: /* "%param"  */
@@ -1121,35 +1129,35 @@ yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YY
       case param_none: aver (false); break;
     }
 }
-#line 1125 "src/parse-gram.c" /* yacc.c:681  */
+#line 1133 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 64: /* code_props_type  */
-#line 375 "src/parse-gram.y" /* yacc.c:681  */
+#line 376 "src/parse-gram.y" /* yacc.c:681  */
       { fprintf (yyo, "%s", code_props_type_string ((*(code_props_type*)(&(*yyvaluep))))); }
-#line 1131 "src/parse-gram.c" /* yacc.c:681  */
+#line 1139 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 73: /* symbol.prec  */
 #line 205 "src/parse-gram.y" /* yacc.c:681  */
       { fprintf (yyo, "%s", (*(symbol**)(&(*yyvaluep)))->tag); }
-#line 1137 "src/parse-gram.c" /* yacc.c:681  */
+#line 1145 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 77: /* tag  */
 #line 199 "src/parse-gram.y" /* yacc.c:681  */
       { fprintf (yyo, "<%s>", (*(uniqstr*)(&(*yyvaluep)))); }
-#line 1143 "src/parse-gram.c" /* yacc.c:681  */
+#line 1151 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 87: /* variable  */
 #line 195 "src/parse-gram.y" /* yacc.c:681  */
       { fputs ((*(uniqstr*)(&(*yyvaluep))), yyo); }
-#line 1149 "src/parse-gram.c" /* yacc.c:681  */
+#line 1157 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 88: /* value  */
-#line 622 "src/parse-gram.y" /* yacc.c:681  */
+#line 646 "src/parse-gram.y" /* yacc.c:681  */
       {
   switch ((*(value_type*)(&(*yyvaluep))).kind)
     {
@@ -1158,31 +1166,31 @@ yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YY
     case muscle_string:  fprintf (yyo, "\"%s\"", (*(value_type*)(&(*yyvaluep))).chars); break;
     }
 }
-#line 1162 "src/parse-gram.c" /* yacc.c:681  */
+#line 1170 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 89: /* id  */
 #line 205 "src/parse-gram.y" /* yacc.c:681  */
       { fprintf (yyo, "%s", (*(symbol**)(&(*yyvaluep)))->tag); }
-#line 1168 "src/parse-gram.c" /* yacc.c:681  */
+#line 1176 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 90: /* id_colon  */
 #line 206 "src/parse-gram.y" /* yacc.c:681  */
       { fprintf (yyo, "%s:", (*(symbol**)(&(*yyvaluep)))->tag); }
-#line 1174 "src/parse-gram.c" /* yacc.c:681  */
+#line 1182 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 91: /* symbol  */
 #line 205 "src/parse-gram.y" /* yacc.c:681  */
       { fprintf (yyo, "%s", (*(symbol**)(&(*yyvaluep)))->tag); }
-#line 1180 "src/parse-gram.c" /* yacc.c:681  */
+#line 1188 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 92: /* string_as_id  */
 #line 205 "src/parse-gram.y" /* yacc.c:681  */
       { fprintf (yyo, "%s", (*(symbol**)(&(*yyvaluep)))->tag); }
-#line 1186 "src/parse-gram.c" /* yacc.c:681  */
+#line 1194 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
 
@@ -1884,7 +1892,7 @@ YYLTYPE yylloc = yyloc_default;
   boundary_set (&yylloc.end, current_file, 1, 1);
 }
 
-#line 1888 "src/parse-gram.c" /* yacc.c:1428  */
+#line 1896 "src/parse-gram.c" /* yacc.c:1428  */
   yylsp[0] = yylloc;
   goto yysetstate;
 
@@ -2089,7 +2097,7 @@ yyreduce:
                         translate_code ((*(char**)(&yyvsp[0])), (yylsp[0]), true), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2093 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2101 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 7:
@@ -2097,7 +2105,7 @@ yyreduce:
     {
       muscle_percent_define_ensure ((*(uniqstr*)(&yyvsp[0])), (yylsp[0]), true);
     }
-#line 2101 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2109 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 8:
@@ -2106,13 +2114,13 @@ yyreduce:
       muscle_percent_define_insert ((*(uniqstr*)(&yyvsp[-1])), (yylsp[-1]), (*(value_type*)(&yyvsp[0])).kind, (*(value_type*)(&yyvsp[0])).chars,
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
     }
-#line 2110 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2118 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 9:
 #line 290 "src/parse-gram.y" /* yacc.c:1649  */
     { defines_flag = true; }
-#line 2116 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2124 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 10:
@@ -2121,25 +2129,25 @@ yyreduce:
       defines_flag = true;
       spec_defines_file = xstrdup ((*(char**)(&yyvsp[0])));
     }
-#line 2125 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2133 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 11:
 #line 296 "src/parse-gram.y" /* yacc.c:1649  */
     { expected_sr_conflicts = (*(int*)(&yyvsp[0])); }
-#line 2131 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2139 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 12:
 #line 297 "src/parse-gram.y" /* yacc.c:1649  */
     { expected_rr_conflicts = (*(int*)(&yyvsp[0])); }
-#line 2137 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2145 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 13:
 #line 298 "src/parse-gram.y" /* yacc.c:1649  */
     { spec_file_prefix = (*(char**)(&yyvsp[0])); }
-#line 2143 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2151 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 14:
@@ -2148,7 +2156,7 @@ yyreduce:
       nondeterministic_parser = true;
       glr_parser = true;
     }
-#line 2152 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2160 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 15:
@@ -2157,103 +2165,109 @@ yyreduce:
       muscle_code_grow ("initial_action", translate_code ((*(char**)(&yyvsp[0])), (yylsp[0]), false), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2161 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2169 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 16:
 #line 309 "src/parse-gram.y" /* yacc.c:1649  */
     { language_argmatch ((*(char**)(&yyvsp[0])), grammar_prio, (yylsp[-1])); }
-#line 2167 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2175 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 17:
 #line 310 "src/parse-gram.y" /* yacc.c:1649  */
     { spec_name_prefix = (*(char**)(&yyvsp[0])); }
-#line 2173 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2181 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 18:
 #line 311 "src/parse-gram.y" /* yacc.c:1649  */
     { no_lines_flag = true; }
-#line 2179 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2187 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 19:
 #line 312 "src/parse-gram.y" /* yacc.c:1649  */
     { nondeterministic_parser = true; }
-#line 2185 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2193 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 20:
 #line 313 "src/parse-gram.y" /* yacc.c:1649  */
     { spec_outfile = (*(char**)(&yyvsp[0])); }
-#line 2191 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2199 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 21:
 #line 314 "src/parse-gram.y" /* yacc.c:1649  */
     { current_param = (*(param_type*)(&yyvsp[0])); }
-#line 2197 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2205 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 22:
 #line 314 "src/parse-gram.y" /* yacc.c:1649  */
     { current_param = param_none; }
-#line 2203 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2211 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 23:
 #line 315 "src/parse-gram.y" /* yacc.c:1649  */
     { do_require (&(yylsp[0]), (*(char**)(&yyvsp[0]))); }
-#line 2209 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2217 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 24:
 #line 316 "src/parse-gram.y" /* yacc.c:1649  */
     { do_skeleton (&(yylsp[0]), (*(char**)(&yyvsp[0]))); }
-#line 2215 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2223 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 25:
 #line 317 "src/parse-gram.y" /* yacc.c:1649  */
     { token_table_flag = true; }
-#line 2221 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2229 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 26:
 #line 318 "src/parse-gram.y" /* yacc.c:1649  */
     { report_flag |= report_states; }
-#line 2227 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2235 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 27:
 #line 319 "src/parse-gram.y" /* yacc.c:1649  */
     { yacc_flag = true; }
-#line 2233 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2241 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
-  case 29:
-#line 324 "src/parse-gram.y" /* yacc.c:1649  */
-    { add_param (current_param, (*(char**)(&yyvsp[0])), (yylsp[0])); }
-#line 2239 "src/parse-gram.c" /* yacc.c:1649  */
+  case 28:
+#line 320 "src/parse-gram.y" /* yacc.c:1649  */
+    { current_class = unknown_sym; yyerrok; }
+#line 2247 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 30:
 #line 325 "src/parse-gram.y" /* yacc.c:1649  */
     { add_param (current_param, (*(char**)(&yyvsp[0])), (yylsp[0])); }
-#line 2245 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2253 "src/parse-gram.c" /* yacc.c:1649  */
+    break;
+
+  case 31:
+#line 326 "src/parse-gram.y" /* yacc.c:1649  */
+    { add_param (current_param, (*(char**)(&yyvsp[0])), (yylsp[0])); }
+#line 2259 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
-  case 33:
-#line 337 "src/parse-gram.y" /* yacc.c:1649  */
+  case 34:
+#line 338 "src/parse-gram.y" /* yacc.c:1649  */
     {
       grammar_start_symbol_set ((*(symbol**)(&yyvsp[0])), (yylsp[0]));
     }
-#line 2253 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2267 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
-  case 34:
-#line 341 "src/parse-gram.y" /* yacc.c:1649  */
+  case 35:
+#line 342 "src/parse-gram.y" /* yacc.c:1649  */
     {
       code_props code;
       code_props_symbol_action_init (&code, (*(char**)(&yyvsp[-1])), (yylsp[-1]));
@@ -2264,27 +2278,27 @@ yyreduce:
         symbol_list_free ((*(symbol_list**)(&yyvsp[0])));
       }
     }
-#line 2268 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2282 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
-  case 35:
-#line 352 "src/parse-gram.y" /* yacc.c:1649  */
+  case 36:
+#line 353 "src/parse-gram.y" /* yacc.c:1649  */
     {
       default_prec = true;
     }
-#line 2276 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2290 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
-  case 36:
-#line 356 "src/parse-gram.y" /* yacc.c:1649  */
+  case 37:
+#line 357 "src/parse-gram.y" /* yacc.c:1649  */
     {
       default_prec = false;
     }
-#line 2284 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2298 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
-  case 37:
-#line 360 "src/parse-gram.y" /* yacc.c:1649  */
+  case 38:
+#line 361 "src/parse-gram.y" /* yacc.c:1649  */
     {
       /* Do not invoke muscle_percent_code_grow here since it invokes
          muscle_user_name_list_grow.  */
@@ -2292,97 +2306,97 @@ yyreduce:
                         translate_code_braceless ((*(char**)(&yyvsp[0])), (yylsp[0])), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2296 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2310 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
-  case 38:
-#line 368 "src/parse-gram.y" /* yacc.c:1649  */
+  case 39:
+#line 369 "src/parse-gram.y" /* yacc.c:1649  */
     {
       muscle_percent_code_grow ((*(uniqstr*)(&yyvsp[-1])), (yylsp[-1]), translate_code_braceless ((*(char**)(&yyvsp[0])), (yylsp[0])), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2305 "src/parse-gram.c" /* yacc.c:1649  */
-    break;
-
-  case 39:
-#line 377 "src/parse-gram.y" /* yacc.c:1649  */
-    { (*(code_props_type*)(&yyval)) = destructor; }
-#line 2311 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2319 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 40:
 #line 378 "src/parse-gram.y" /* yacc.c:1649  */
-    { (*(code_props_type*)(&yyval)) = printer; }
-#line 2317 "src/parse-gram.c" /* yacc.c:1649  */
+    { (*(code_props_type*)(&yyval)) = destructor; }
+#line 2325 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 41:
-#line 388 "src/parse-gram.y" /* yacc.c:1649  */
-    {}
-#line 2323 "src/parse-gram.c" /* yacc.c:1649  */
+#line 379 "src/parse-gram.y" /* yacc.c:1649  */
+    { (*(code_props_type*)(&yyval)) = printer; }
+#line 2331 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 42:
 #line 389 "src/parse-gram.y" /* yacc.c:1649  */
+    {}
+#line 2337 "src/parse-gram.c" /* yacc.c:1649  */
+    break;
+
+  case 43:
+#line 390 "src/parse-gram.y" /* yacc.c:1649  */
     { muscle_percent_define_insert ("api.value.union.name",
                                          (yylsp[0]), muscle_keyword, (*(uniqstr*)(&yyvsp[0])),
                                          MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE); }
-#line 2331 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2345 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
-  case 43:
-#line 396 "src/parse-gram.y" /* yacc.c:1649  */
+  case 44:
+#line 397 "src/parse-gram.y" /* yacc.c:1649  */
     {
       union_seen = true;
       muscle_code_grow ("union_members", translate_code_braceless ((*(char**)(&yyvsp[0])), (yylsp[0])), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2341 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2355 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
-  case 44:
-#line 407 "src/parse-gram.y" /* yacc.c:1649  */
+  case 45:
+#line 408 "src/parse-gram.y" /* yacc.c:1649  */
     { current_class = nterm_sym; }
-#line 2347 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2361 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
-  case 45:
-#line 408 "src/parse-gram.y" /* yacc.c:1649  */
+  case 46:
+#line 409 "src/parse-gram.y" /* yacc.c:1649  */
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
-#line 2356 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2370 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
-  case 46:
-#line 412 "src/parse-gram.y" /* yacc.c:1649  */
+  case 47:
+#line 413 "src/parse-gram.y" /* yacc.c:1649  */
     { current_class = token_sym; }
-#line 2362 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2376 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
-  case 47:
-#line 413 "src/parse-gram.y" /* yacc.c:1649  */
+  case 48:
+#line 414 "src/parse-gram.y" /* yacc.c:1649  */
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
-#line 2371 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2385 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
-  case 48:
-#line 418 "src/parse-gram.y" /* yacc.c:1649  */
+  case 49:
+#line 419 "src/parse-gram.y" /* yacc.c:1649  */
     {
       tag_seen = true;
       for (symbol_list *list = (*(symbol_list**)(&yyvsp[0])); list; list = list->next)
         symbol_type_set (list->content.sym, (*(uniqstr*)(&yyvsp[-1])), (yylsp[-1]));
       symbol_list_free ((*(symbol_list**)(&yyvsp[0])));
     }
-#line 2382 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2396 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
-  case 49:
-#line 428 "src/parse-gram.y" /* yacc.c:1649  */
+  case 50:
+#line 429 "src/parse-gram.y" /* yacc.c:1649  */
     {
       ++current_prec;
       for (symbol_list *list = (*(symbol_list**)(&yyvsp[0])); list; list = list->next)
@@ -2393,347 +2407,373 @@ yyreduce:
       symbol_list_free ((*(symbol_list**)(&yyvsp[0])));
       current_type = NULL;
     }
-#line 2397 "src/parse-gram.c" /* yacc.c:1649  */
-    break;
-
-  case 50:
-#line 441 "src/parse-gram.y" /* yacc.c:1649  */
-    { (*(assoc*)(&yyval)) = left_assoc; }
-#line 2403 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2411 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 51:
 #line 442 "src/parse-gram.y" /* yacc.c:1649  */
-    { (*(assoc*)(&yyval)) = right_assoc; }
-#line 2409 "src/parse-gram.c" /* yacc.c:1649  */
+    { (*(assoc*)(&yyval)) = left_assoc; }
+#line 2417 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 52:
 #line 443 "src/parse-gram.y" /* yacc.c:1649  */
-    { (*(assoc*)(&yyval)) = non_assoc; }
-#line 2415 "src/parse-gram.c" /* yacc.c:1649  */
+    { (*(assoc*)(&yyval)) = right_assoc; }
+#line 2423 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 53:
 #line 444 "src/parse-gram.y" /* yacc.c:1649  */
-    { (*(assoc*)(&yyval)) = precedence_assoc; }
-#line 2421 "src/parse-gram.c" /* yacc.c:1649  */
+    { (*(assoc*)(&yyval)) = non_assoc; }
+#line 2429 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 54:
-#line 448 "src/parse-gram.y" /* yacc.c:1649  */
-    { current_type = NULL; }
-#line 2427 "src/parse-gram.c" /* yacc.c:1649  */
+#line 445 "src/parse-gram.y" /* yacc.c:1649  */
+    { (*(assoc*)(&yyval)) = precedence_assoc; }
+#line 2435 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 55:
 #line 449 "src/parse-gram.y" /* yacc.c:1649  */
-    { current_type = (*(uniqstr*)(&yyvsp[0])); tag_seen = true; }
-#line 2433 "src/parse-gram.c" /* yacc.c:1649  */
+    { current_type = NULL; }
+#line 2441 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 56:
-#line 455 "src/parse-gram.y" /* yacc.c:1649  */
-    { (*(symbol_list**)(&yyval)) = symbol_list_sym_new ((*(symbol**)(&yyvsp[0])), (yylsp[0])); }
-#line 2439 "src/parse-gram.c" /* yacc.c:1649  */
+#line 450 "src/parse-gram.y" /* yacc.c:1649  */
+    { current_type = (*(uniqstr*)(&yyvsp[0])); tag_seen = true; }
+#line 2447 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 57:
-#line 457 "src/parse-gram.y" /* yacc.c:1649  */
-    { (*(symbol_list**)(&yyval)) = symbol_list_append ((*(symbol_list**)(&yyvsp[-1])), symbol_list_sym_new ((*(symbol**)(&yyvsp[0])), (yylsp[0]))); }
-#line 2445 "src/parse-gram.c" /* yacc.c:1649  */
+#line 456 "src/parse-gram.y" /* yacc.c:1649  */
+    { (*(symbol_list**)(&yyval)) = symbol_list_sym_new ((*(symbol**)(&yyvsp[0])), (yylsp[0])); }
+#line 2453 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 58:
-#line 462 "src/parse-gram.y" /* yacc.c:1649  */
+#line 458 "src/parse-gram.y" /* yacc.c:1649  */
+    { (*(symbol_list**)(&yyval)) = symbol_list_append ((*(symbol_list**)(&yyvsp[-1])), symbol_list_sym_new ((*(symbol**)(&yyvsp[0])), (yylsp[0]))); }
+#line 2459 "src/parse-gram.c" /* yacc.c:1649  */
+    break;
+
+  case 59:
+#line 463 "src/parse-gram.y" /* yacc.c:1649  */
     {
       (*(symbol**)(&yyval)) = (*(symbol**)(&yyvsp[0]));
       symbol_class_set ((*(symbol**)(&yyvsp[0])), token_sym, (yylsp[0]), false);
     }
-#line 2454 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2468 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
-  case 59:
-#line 467 "src/parse-gram.y" /* yacc.c:1649  */
+  case 60:
+#line 468 "src/parse-gram.y" /* yacc.c:1649  */
     {
       (*(symbol**)(&yyval)) = (*(symbol**)(&yyvsp[-1]));
       symbol_user_token_number_set ((*(symbol**)(&yyvsp[-1])), (*(int*)(&yyvsp[0])), (yylsp[0]));
       symbol_class_set ((*(symbol**)(&yyvsp[-1])), token_sym, (yylsp[-1]), false);
     }
-#line 2464 "src/parse-gram.c" /* yacc.c:1649  */
-    break;
-
-  case 60:
-#line 477 "src/parse-gram.y" /* yacc.c:1649  */
-    { (*(symbol_list**)(&yyval)) = symbol_list_sym_new ((*(symbol**)(&yyvsp[0])), (yylsp[0])); }
-#line 2470 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2478 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 61:
-#line 479 "src/parse-gram.y" /* yacc.c:1649  */
-    { (*(symbol_list**)(&yyval)) = symbol_list_append ((*(symbol_list**)(&yyvsp[-1])), symbol_list_sym_new ((*(symbol**)(&yyvsp[0])), (yylsp[0]))); }
-#line 2476 "src/parse-gram.c" /* yacc.c:1649  */
+#line 478 "src/parse-gram.y" /* yacc.c:1649  */
+    { (*(symbol_list**)(&yyval)) = symbol_list_sym_new ((*(symbol**)(&yyvsp[0])), (yylsp[0])); }
+#line 2484 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 62:
-#line 483 "src/parse-gram.y" /* yacc.c:1649  */
-    { (*(symbol_list**)(&yyval)) = (*(symbol_list**)(&yyvsp[0])); }
-#line 2482 "src/parse-gram.c" /* yacc.c:1649  */
+#line 480 "src/parse-gram.y" /* yacc.c:1649  */
+    { (*(symbol_list**)(&yyval)) = symbol_list_append ((*(symbol_list**)(&yyvsp[-1])), symbol_list_sym_new ((*(symbol**)(&yyvsp[0])), (yylsp[0]))); }
+#line 2490 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 63:
 #line 484 "src/parse-gram.y" /* yacc.c:1649  */
-    { (*(symbol_list**)(&yyval)) = symbol_list_append ((*(symbol_list**)(&yyvsp[-1])), (*(symbol_list**)(&yyvsp[0]))); }
-#line 2488 "src/parse-gram.c" /* yacc.c:1649  */
+    { (*(symbol_list**)(&yyval)) = (*(symbol_list**)(&yyvsp[0])); }
+#line 2496 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 64:
-#line 488 "src/parse-gram.y" /* yacc.c:1649  */
-    { (*(symbol_list**)(&yyval)) = symbol_list_sym_new ((*(symbol**)(&yyvsp[0])), (yylsp[0])); }
-#line 2494 "src/parse-gram.c" /* yacc.c:1649  */
+#line 485 "src/parse-gram.y" /* yacc.c:1649  */
+    { (*(symbol_list**)(&yyval)) = symbol_list_append ((*(symbol_list**)(&yyvsp[-1])), (*(symbol_list**)(&yyvsp[0]))); }
+#line 2502 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 65:
 #line 489 "src/parse-gram.y" /* yacc.c:1649  */
-    { (*(symbol_list**)(&yyval)) = symbol_list_type_new ((*(uniqstr*)(&yyvsp[0])), (yylsp[0])); }
-#line 2500 "src/parse-gram.c" /* yacc.c:1649  */
+    { (*(symbol_list**)(&yyval)) = symbol_list_sym_new ((*(symbol**)(&yyvsp[0])), (yylsp[0])); }
+#line 2508 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
-  case 67:
-#line 494 "src/parse-gram.y" /* yacc.c:1649  */
-    { (*(uniqstr*)(&yyval)) = uniqstr_new ("*"); }
-#line 2506 "src/parse-gram.c" /* yacc.c:1649  */
+  case 66:
+#line 490 "src/parse-gram.y" /* yacc.c:1649  */
+    { (*(symbol_list**)(&yyval)) = symbol_list_type_new ((*(uniqstr*)(&yyvsp[0])), (yylsp[0])); }
+#line 2514 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 68:
 #line 495 "src/parse-gram.y" /* yacc.c:1649  */
-    { (*(uniqstr*)(&yyval)) = uniqstr_new (""); }
-#line 2512 "src/parse-gram.c" /* yacc.c:1649  */
+    { (*(uniqstr*)(&yyval)) = uniqstr_new ("*"); }
+#line 2520 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 69:
-#line 501 "src/parse-gram.y" /* yacc.c:1649  */
+#line 496 "src/parse-gram.y" /* yacc.c:1649  */
+    { (*(uniqstr*)(&yyval)) = uniqstr_new (""); }
+#line 2526 "src/parse-gram.c" /* yacc.c:1649  */
+    break;
+
+  case 70:
+#line 502 "src/parse-gram.y" /* yacc.c:1649  */
     {
       current_type = (*(uniqstr*)(&yyvsp[0]));
       tag_seen = true;
     }
-#line 2521 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2535 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
-  case 70:
-#line 506 "src/parse-gram.y" /* yacc.c:1649  */
+  case 71:
+#line 507 "src/parse-gram.y" /* yacc.c:1649  */
     {
       symbol_class_set ((*(symbol**)(&yyvsp[0])), current_class, (yylsp[0]), true);
       symbol_type_set ((*(symbol**)(&yyvsp[0])), current_type, (yylsp[0]));
     }
-#line 2530 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2544 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
-  case 71:
-#line 511 "src/parse-gram.y" /* yacc.c:1649  */
+  case 72:
+#line 512 "src/parse-gram.y" /* yacc.c:1649  */
     {
+      if (current_class != token_sym)
+        {
+          gram_error (&(yylsp[0]),
+                      _("non-terminals cannot be given an explicit number"));
+          YYERROR;
+        }
       symbol_class_set ((*(symbol**)(&yyvsp[-1])), current_class, (yylsp[-1]), true);
       symbol_type_set ((*(symbol**)(&yyvsp[-1])), current_type, (yylsp[-1]));
       symbol_user_token_number_set ((*(symbol**)(&yyvsp[-1])), (*(int*)(&yyvsp[0])), (yylsp[0]));
     }
-#line 2540 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2560 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
-  case 72:
-#line 517 "src/parse-gram.y" /* yacc.c:1649  */
+  case 73:
+#line 524 "src/parse-gram.y" /* yacc.c:1649  */
     {
+      if (current_class != token_sym)
+        {
+          gram_error (&(yylsp[0]),
+                      _("non-terminals cannot be given a string alias"));
+          YYERROR;
+        }
       symbol_class_set ((*(symbol**)(&yyvsp[-1])), current_class, (yylsp[-1]), true);
       symbol_type_set ((*(symbol**)(&yyvsp[-1])), current_type, (yylsp[-1]));
       symbol_make_alias ((*(symbol**)(&yyvsp[-1])), (*(symbol**)(&yyvsp[0])), (yyloc));
     }
-#line 2550 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2576 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
-  case 73:
-#line 523 "src/parse-gram.y" /* yacc.c:1649  */
+  case 74:
+#line 536 "src/parse-gram.y" /* yacc.c:1649  */
     {
+      if (current_class != token_sym)
+        {
+          gram_error (&(yylsp[-1]),
+                      _("non-terminals cannot be given an explicit number"));
+          gram_error (&(yylsp[0]),
+                      _("non-terminals cannot be given a string alias"));
+          YYERROR;
+        }
       symbol_class_set ((*(symbol**)(&yyvsp[-2])), current_class, (yylsp[-2]), true);
       symbol_type_set ((*(symbol**)(&yyvsp[-2])), current_type, (yylsp[-2]));
       symbol_user_token_number_set ((*(symbol**)(&yyvsp[-2])), (*(int*)(&yyvsp[-1])), (yylsp[-1]));
       symbol_make_alias ((*(symbol**)(&yyvsp[-2])), (*(symbol**)(&yyvsp[0])), (yyloc));
     }
-#line 2561 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2595 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
-  case 80:
-#line 553 "src/parse-gram.y" /* yacc.c:1649  */
+  case 81:
+#line 577 "src/parse-gram.y" /* yacc.c:1649  */
     {
       yyerrok;
     }
-#line 2569 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2603 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
-  case 81:
-#line 559 "src/parse-gram.y" /* yacc.c:1649  */
+  case 82:
+#line 583 "src/parse-gram.y" /* yacc.c:1649  */
     { current_lhs ((*(symbol**)(&yyvsp[-1])), (yylsp[-1]), (*(named_ref**)(&yyvsp[0]))); }
-#line 2575 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2609 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
-  case 82:
-#line 560 "src/parse-gram.y" /* yacc.c:1649  */
+  case 83:
+#line 584 "src/parse-gram.y" /* yacc.c:1649  */
     {
       /* Free the current lhs. */
       current_lhs (0, (yylsp[-3]), 0);
     }
-#line 2584 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2618 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
-  case 83:
-#line 567 "src/parse-gram.y" /* yacc.c:1649  */
+  case 84:
+#line 591 "src/parse-gram.y" /* yacc.c:1649  */
     { grammar_current_rule_end ((yylsp[0])); }
-#line 2590 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2624 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
-  case 84:
-#line 568 "src/parse-gram.y" /* yacc.c:1649  */
+  case 85:
+#line 592 "src/parse-gram.y" /* yacc.c:1649  */
     { grammar_current_rule_end ((yylsp[0])); }
-#line 2596 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2630 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
-  case 86:
-#line 575 "src/parse-gram.y" /* yacc.c:1649  */
+  case 87:
+#line 599 "src/parse-gram.y" /* yacc.c:1649  */
     { grammar_current_rule_begin (current_lhs_symbol, current_lhs_location,
                                   current_lhs_named_ref); }
-#line 2603 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2637 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
-  case 87:
-#line 578 "src/parse-gram.y" /* yacc.c:1649  */
+  case 88:
+#line 602 "src/parse-gram.y" /* yacc.c:1649  */
     { grammar_current_rule_symbol_append ((*(symbol**)(&yyvsp[-1])), (yylsp[-1]), (*(named_ref**)(&yyvsp[0]))); }
-#line 2609 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2643 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
-  case 88:
-#line 580 "src/parse-gram.y" /* yacc.c:1649  */
+  case 89:
+#line 604 "src/parse-gram.y" /* yacc.c:1649  */
     { grammar_current_rule_action_append ((*(char**)(&yyvsp[-1])), (yylsp[-1]), (*(named_ref**)(&yyvsp[0])), current_type); }
-#line 2615 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2649 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
-  case 89:
-#line 582 "src/parse-gram.y" /* yacc.c:1649  */
+  case 90:
+#line 606 "src/parse-gram.y" /* yacc.c:1649  */
     { grammar_current_rule_predicate_append ((*(char**)(&yyvsp[0])), (yylsp[0])); }
-#line 2621 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2655 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
-  case 90:
-#line 584 "src/parse-gram.y" /* yacc.c:1649  */
+  case 91:
+#line 608 "src/parse-gram.y" /* yacc.c:1649  */
     { grammar_current_rule_empty_set ((yylsp[0])); }
-#line 2627 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2661 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
-  case 91:
-#line 586 "src/parse-gram.y" /* yacc.c:1649  */
+  case 92:
+#line 610 "src/parse-gram.y" /* yacc.c:1649  */
     { grammar_current_rule_prec_set ((*(symbol**)(&yyvsp[0])), (yylsp[0])); }
-#line 2633 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2667 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
-  case 92:
-#line 588 "src/parse-gram.y" /* yacc.c:1649  */
+  case 93:
+#line 612 "src/parse-gram.y" /* yacc.c:1649  */
     { grammar_current_rule_dprec_set ((*(int*)(&yyvsp[0])), (yylsp[0])); }
-#line 2639 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2673 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
-  case 93:
-#line 590 "src/parse-gram.y" /* yacc.c:1649  */
+  case 94:
+#line 614 "src/parse-gram.y" /* yacc.c:1649  */
     { grammar_current_rule_merge_set ((*(uniqstr*)(&yyvsp[0])), (yylsp[0])); }
-#line 2645 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2679 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
-  case 94:
-#line 592 "src/parse-gram.y" /* yacc.c:1649  */
+  case 95:
+#line 616 "src/parse-gram.y" /* yacc.c:1649  */
     { grammar_current_rule_expect_sr ((*(int*)(&yyvsp[0])), (yylsp[0])); }
-#line 2651 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2685 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
-  case 95:
-#line 594 "src/parse-gram.y" /* yacc.c:1649  */
+  case 96:
+#line 618 "src/parse-gram.y" /* yacc.c:1649  */
     { grammar_current_rule_expect_rr ((*(int*)(&yyvsp[0])), (yylsp[0])); }
-#line 2657 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2691 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
-  case 96:
-#line 598 "src/parse-gram.y" /* yacc.c:1649  */
+  case 97:
+#line 622 "src/parse-gram.y" /* yacc.c:1649  */
     { (*(named_ref**)(&yyval)) = 0; }
-#line 2663 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2697 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
-  case 97:
-#line 599 "src/parse-gram.y" /* yacc.c:1649  */
+  case 98:
+#line 623 "src/parse-gram.y" /* yacc.c:1649  */
     { (*(named_ref**)(&yyval)) = named_ref_new ((*(uniqstr*)(&yyvsp[0])), (yylsp[0])); }
-#line 2669 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2703 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
-  case 99:
-#line 632 "src/parse-gram.y" /* yacc.c:1649  */
+  case 100:
+#line 656 "src/parse-gram.y" /* yacc.c:1649  */
     { (*(value_type*)(&yyval)).kind = muscle_keyword; (*(value_type*)(&yyval)).chars = ""; }
-#line 2675 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2709 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
-  case 100:
-#line 633 "src/parse-gram.y" /* yacc.c:1649  */
+  case 101:
+#line 657 "src/parse-gram.y" /* yacc.c:1649  */
     { (*(value_type*)(&yyval)).kind = muscle_keyword; (*(value_type*)(&yyval)).chars = (*(uniqstr*)(&yyvsp[0])); }
-#line 2681 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2715 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
-  case 101:
-#line 634 "src/parse-gram.y" /* yacc.c:1649  */
+  case 102:
+#line 658 "src/parse-gram.y" /* yacc.c:1649  */
     { (*(value_type*)(&yyval)).kind = muscle_string;  (*(value_type*)(&yyval)).chars = (*(char**)(&yyvsp[0])); }
-#line 2687 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2721 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
-  case 102:
-#line 635 "src/parse-gram.y" /* yacc.c:1649  */
+  case 103:
+#line 659 "src/parse-gram.y" /* yacc.c:1649  */
     { (*(value_type*)(&yyval)).kind = muscle_code;    (*(value_type*)(&yyval)).chars = strip_braces ((*(char**)(&yyvsp[0]))); }
-#line 2693 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2727 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
-  case 103:
-#line 648 "src/parse-gram.y" /* yacc.c:1649  */
+  case 104:
+#line 672 "src/parse-gram.y" /* yacc.c:1649  */
     { (*(symbol**)(&yyval)) = symbol_from_uniqstr ((*(uniqstr*)(&yyvsp[0])), (yylsp[0])); }
-#line 2699 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2733 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
-  case 104:
-#line 650 "src/parse-gram.y" /* yacc.c:1649  */
+  case 105:
+#line 674 "src/parse-gram.y" /* yacc.c:1649  */
     {
+      if (current_class == nterm_sym)
+        {
+          gram_error (&(yylsp[0]),
+                      _("character literals cannot be non-terminals"));
+          YYERROR;
+        }
       (*(symbol**)(&yyval)) = symbol_get (char_name ((*(unsigned char*)(&yyvsp[0]))), (yylsp[0]));
       symbol_class_set ((*(symbol**)(&yyval)), token_sym, (yylsp[0]), false);
       symbol_user_token_number_set ((*(symbol**)(&yyval)), (*(unsigned char*)(&yyvsp[0])), (yylsp[0]));
     }
-#line 2709 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2749 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
-  case 105:
-#line 658 "src/parse-gram.y" /* yacc.c:1649  */
+  case 106:
+#line 688 "src/parse-gram.y" /* yacc.c:1649  */
     { (*(symbol**)(&yyval)) = symbol_from_uniqstr ((*(uniqstr*)(&yyvsp[0])), (yylsp[0])); }
-#line 2715 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2755 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
-  case 108:
-#line 670 "src/parse-gram.y" /* yacc.c:1649  */
+  case 109:
+#line 700 "src/parse-gram.y" /* yacc.c:1649  */
     {
       (*(symbol**)(&yyval)) = symbol_get (quotearg_style (c_quoting_style, (*(char**)(&yyvsp[0]))), (yylsp[0]));
       symbol_class_set ((*(symbol**)(&yyval)), token_sym, (yylsp[0]), false);
     }
-#line 2724 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2764 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
-  case 110:
-#line 679 "src/parse-gram.y" /* yacc.c:1649  */
+  case 111:
+#line 709 "src/parse-gram.y" /* yacc.c:1649  */
     {
       muscle_code_grow ("epilogue", translate_code ((*(char**)(&yyvsp[0])), (yylsp[0]), true), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2733 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2773 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
 
-#line 2737 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2777 "src/parse-gram.c" /* yacc.c:1649  */
         default: break;
       }
     if (yychar_backup != yychar)
@@ -2982,7 +3022,7 @@ yyreturn:
 #endif
   return yyresult;
 }
-#line 685 "src/parse-gram.y" /* yacc.c:1915  */
+#line 715 "src/parse-gram.y" /* yacc.c:1915  */
 
 
 /* Return the location of the left-hand side of a rule whose
