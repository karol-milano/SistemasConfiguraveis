@@ -624,7 +624,7 @@ union yyalloc
 /* YYFINAL -- State number of the termination state.  */
 #define YYFINAL  3
 /* YYLAST -- Last index in YYTABLE.  */
-#define YYLAST   236
+#define YYLAST   240
 
 /* YYNTOKENS -- Number of terminals.  */
 #define YYNTOKENS  61
@@ -732,7 +732,7 @@ static const yytype_int16 yytoknum[] =
 };
 #endif
 
-#define YYPACT_NINF (-147)
+#define YYPACT_NINF (-148)
 
 #define yypact_value_is_default(Yyn) \
   ((Yyn) == YYPACT_NINF)
@@ -746,23 +746,23 @@ static const yytype_int16 yytoknum[] =
      STATE-NUM.  */
 static const yytype_int16 yypact[] =
 {
-    -147,     9,   122,  -147,   -39,  -147,  -147,  -147,  -147,  -147,
-    -147,  -147,  -147,  -147,   -33,  -147,   -17,  -147,     1,    11,
-      71,  -147,  -147,    72,    38,    77,    78,  -147,  -147,  -147,
-      81,  -147,    83,    88,    13,  -147,  -147,  -147,   177,  -147,
-    -147,  -147,    51,  -147,  -147,    59,  -147,    53,  -147,   -11,
-     -11,    70,  -147,    63,  -147,     4,  -147,  -147,  -147,  -147,
-    -147,  -147,  -147,  -147,  -147,  -147,  -147,  -147,  -147,  -147,
-    -147,  -147,  -147,    52,  -147,    56,    17,  -147,  -147,    69,
-      65,  -147,    74,   161,    13,    57,    13,  -147,    60,  -147,
-     -12,    66,   -12,  -147,    60,  -147,    66,    13,    67,    13,
-    -147,  -147,  -147,  -147,  -147,  -147,  -147,  -147,    73,  -147,
-    -147,  -147,  -147,  -147,    84,  -147,  -147,  -147,  -147,   161,
-    -147,  -147,  -147,    13,    13,  -147,  -147,  -147,   -12,   -12,
-    -147,    68,    13,    13,  -147,  -147,    91,  -147,  -147,    13,
-     -12,  -147,  -147,  -147,    13,  -147,   -41,    48,  -147,  -147,
-      13,    80,   109,   108,   110,  -147,  -147,  -147,    97,    69,
-      48,  -147,  -147,  -147,  -147,  -147,    69,  -147,  -147
+    -148,    13,   113,  -148,   -27,  -148,  -148,  -148,  -148,  -148,
+    -148,  -148,  -148,  -148,   -33,  -148,   -21,  -148,   -29,   -26,
+      26,  -148,  -148,    27,    -9,    30,    31,  -148,  -148,  -148,
+      32,  -148,    34,    36,   112,  -148,  -148,  -148,   168,  -148,
+    -148,  -148,    -3,  -148,  -148,    19,  -148,     7,  -148,   -37,
+     -37,   164,  -148,    33,  -148,     2,  -148,  -148,  -148,  -148,
+    -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,
+     112,  -148,  -148,  -148,     9,  -148,    20,    58,  -148,  -148,
+      37,    38,  -148,    40,   155,   112,    35,   112,  -148,    41,
+    -148,   -28,    43,   -28,  -148,    41,  -148,    43,   112,    46,
+     112,  -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,    44,
+    -148,  -148,  -148,  -148,  -148,    50,  -148,  -148,  -148,  -148,
+     155,  -148,  -148,  -148,   112,   112,  -148,  -148,  -148,   -28,
+     -28,  -148,    21,   112,   112,  -148,    59,  -148,  -148,   112,
+     -28,  -148,  -148,  -148,   112,  -148,   -30,   180,  -148,  -148,
+     112,    48,    49,    52,    53,  -148,  -148,  -148,    65,    37,
+     180,  -148,  -148,  -148,  -148,  -148,    37,  -148,  -148
 };
 
   /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
@@ -777,13 +777,13 @@ static const yytype_int8 yydefact[] =
       30,    21,    42,     4,     5,     0,    33,     0,    29,     0,
        0,     0,    38,     0,   113,   114,    11,    12,    13,    57,
        9,    15,    16,    17,    20,    24,    25,   123,   119,   118,
-     121,    34,   122,     0,   120,     0,     0,    91,    93,   111,
-       0,    43,     0,     0,     0,    51,    79,    82,    74,    85,
-       0,    48,    68,    71,    74,    46,    67,     0,    50,    86,
-      89,    39,   116,   117,   115,     8,    95,    94,     0,    92,
-       2,   112,    96,    32,    22,    44,    64,    65,    66,    35,
-      60,    63,    62,    80,     0,    83,    75,    84,    69,     0,
-      72,    76,    87,     0,    90,   125,     0,    31,    61,    81,
+      34,   121,    89,   122,     0,   120,     0,     0,    91,    93,
+     111,     0,    43,     0,     0,     0,    51,    79,    82,    74,
+      85,     0,    48,    68,    71,    74,    46,    67,     0,    50,
+      86,    39,   116,   117,   115,     8,    90,    95,    94,     0,
+      92,     2,   112,    96,    32,    22,    44,    64,    65,    66,
+      35,    60,    63,    62,    80,     0,    83,    75,    84,    69,
+       0,    72,    76,    87,     0,   125,     0,    31,    61,    81,
       70,    78,    73,    77,    88,   101,    97,    98,   101,   100,
        0,     0,     0,     0,     0,   104,    59,   105,     0,   111,
       99,   106,   107,   108,   109,   110,   111,   102,   103
@@ -792,21 +792,21 @@ static const yytype_int8 yydefact[] =
   /* YYPGOTO[NTERM-NUM].  */
 static const yytype_int16 yypgoto[] =
 {
-    -147,  -147,  -147,  -147,  -147,  -147,   120,  -147,  -147,  -147,
-    -147,  -147,  -147,  -147,  -147,  -147,  -147,    47,  -147,  -147,
-     118,   -69,   -87,    75,  -147,  -147,   -65,   -84,  -147,   -91,
-    -147,    94,  -147,  -147,  -147,    23,  -146,  -147,  -147,   -46,
-    -147,   -34,   -36,  -147
+    -148,  -148,  -148,  -148,  -148,  -148,   109,  -148,  -148,  -148,
+    -148,  -148,  -148,  -148,  -148,  -148,  -148,    -7,  -148,  -148,
+      66,   -73,   -87,    60,  -148,  -148,   -71,   -83,  -148,   -50,
+    -148,    51,  -148,  -148,  -148,   -19,  -147,  -148,  -148,   -47,
+    -148,   -48,   -38,  -148
 };
 
   /* YYDEFGOTO[NTERM-NUM].  */
 static const yytype_int16 yydefgoto[] =
 {
-      -1,     1,     2,    43,    80,   114,    75,    45,    82,    46,
-      50,    49,    51,    47,    60,   158,   119,   120,   121,    95,
-      91,    92,    93,   127,   142,    85,    86,    87,    98,    99,
-      76,    77,    78,   136,   146,   147,   112,    55,   105,    70,
-      79,   100,    72,   110
+      -1,     1,     2,    43,    81,   115,    76,    45,    83,    46,
+      50,    49,    51,    47,    60,   158,   120,   121,   122,    96,
+      92,    93,    94,   128,   142,    86,    87,    88,    99,    70,
+      77,    78,    79,   136,   146,   147,   113,    55,   105,    71,
+      80,    72,    73,   111
 };
 
   /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
@@ -814,58 +814,60 @@ static const yytype_int16 yydefgoto[] =
      number is the opposite.  If YYTABLE_NINF, syntax error.  */
 static const yytype_int16 yytable[] =
 {
-      71,    88,   125,    94,    94,   130,   132,   102,    52,     3,
-     148,    89,   149,   167,    48,    53,    67,  -124,    73,   123,
-     168,   128,     5,     6,     7,     8,     9,    10,    11,    12,
-      13,    54,    68,    68,    14,    15,    69,    69,    88,   125,
-      88,   130,   144,    90,    94,   103,    94,    27,    89,   122,
-      89,    67,   104,   130,    34,   125,    67,    68,    56,   139,
-     140,    69,   150,   151,   152,   134,    74,   108,    57,   153,
-     154,    67,   141,    67,    58,    59,    42,    88,    88,    61,
-      62,    63,    94,    94,    64,   122,    65,    89,    89,   -58,
-     155,    66,    68,    88,    94,   143,    69,    68,   134,    81,
-      83,    69,   156,    89,   101,   106,   113,    84,   157,   107,
-     134,   124,   111,   159,    68,   115,   161,   126,    69,   135,
-     129,   133,    44,     4,    97,   137,   159,     5,     6,     7,
-       8,     9,    10,    11,    12,    13,   145,   162,   166,    14,
-      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
-      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
-      35,    36,    37,   163,    67,   164,   138,   165,    96,   131,
-     109,   160,    38,     0,    39,    40,     0,     0,    73,     0,
-      41,    42,     5,     6,     7,     8,     9,    10,    11,    12,
-      13,     0,     0,     0,    14,    15,     0,     0,     0,     0,
-       0,     0,     0,     0,     0,    68,     0,    27,     0,    69,
-       0,     0,     0,     0,    34,   116,   117,   118,     0,     0,
-       0,     0,     0,     0,     0,     0,    74,     0,     0,     0,
-       0,     0,     0,     0,     0,     0,    42
+      89,   100,    95,    95,   126,   102,   131,    68,    52,    90,
+      67,    69,   167,     3,   124,    53,    68,    91,   129,   168,
+      69,   148,   106,   149,    67,   141,    48,    54,    56,    58,
+      59,    57,    61,    62,    63,    64,   123,    65,    89,    66,
+      89,   126,   131,   103,    95,    82,    95,    90,   133,    90,
+     104,    68,   106,   131,   139,    69,   126,   140,  -124,    74,
+      84,    85,   107,     5,     6,     7,     8,     9,    10,    11,
+      12,    13,   123,   108,   101,    14,    15,    89,    89,   114,
+     112,   116,    95,    95,   144,   106,    90,    90,    27,   125,
+     135,   137,    89,    95,   143,    34,   106,   130,   127,   159,
+     134,    90,   161,   163,   145,   162,   166,    75,   109,   164,
+     165,    44,   159,   138,     4,    67,    97,    42,     5,     6,
+       7,     8,     9,    10,    11,    12,    13,     0,   110,   160,
+      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
+      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
+      34,    35,    36,    37,     0,   132,    68,     0,    67,     0,
+      69,     0,     0,    38,     0,    39,    40,    67,     0,    74,
+       0,    41,    42,     5,     6,     7,     8,     9,    10,    11,
+      12,    13,     0,    67,     0,    14,    15,     0,     0,     0,
+       0,     0,     0,     0,   150,   151,   152,     0,    27,    68,
+       0,   153,   154,    69,     0,    34,     0,     0,    68,   117,
+     118,   119,    69,     0,     0,     0,     0,    75,    98,     0,
+       0,   -58,   155,     0,    68,     0,     0,    42,    69,     0,
+       0,     0,     0,     0,   156,     0,     0,     0,     0,     0,
+     157
 };
 
 static const yytype_int16 yycheck[] =
 {
-      34,    47,    86,    49,    50,    92,    97,     3,    41,     0,
-      51,    47,    53,   159,    53,    48,     3,     0,     1,    84,
-     166,    90,     5,     6,     7,     8,     9,    10,    11,    12,
-      13,    48,    44,    44,    17,    18,    48,    48,    84,   123,
-      86,   128,   133,    54,    90,    41,    92,    30,    84,    83,
-      86,     3,    48,   140,    37,   139,     3,    44,    57,   124,
-     129,    48,    14,    15,    16,    99,    49,    50,    57,    21,
-      22,     3,     4,     3,     3,     3,    59,   123,   124,    41,
-       3,     3,   128,   129,     3,   119,     3,   123,   124,    41,
-      42,     3,    44,   139,   140,   131,    48,    44,   132,    48,
-      41,    48,    54,   139,    41,    53,    41,    54,    60,    53,
-     144,    54,    43,   147,    44,    41,   150,    57,    48,    46,
-      54,    54,     2,     1,    54,    41,   160,     5,     6,     7,
-       8,     9,    10,    11,    12,    13,    45,    57,    41,    17,
-      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
-      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
-      38,    39,    40,    54,     3,    57,   119,    57,    50,    94,
-      76,   148,    50,    -1,    52,    53,    -1,    -1,     1,    -1,
-      58,    59,     5,     6,     7,     8,     9,    10,    11,    12,
-      13,    -1,    -1,    -1,    17,    18,    -1,    -1,    -1,    -1,
-      -1,    -1,    -1,    -1,    -1,    44,    -1,    30,    -1,    48,
-      -1,    -1,    -1,    -1,    37,    54,    55,    56,    -1,    -1,
-      -1,    -1,    -1,    -1,    -1,    -1,    49,    -1,    -1,    -1,
-      -1,    -1,    -1,    -1,    -1,    -1,    59
+      47,    51,    49,    50,    87,     3,    93,    44,    41,    47,
+       3,    48,   159,     0,    85,    48,    44,    54,    91,   166,
+      48,    51,    70,    53,     3,     4,    53,    48,    57,     3,
+       3,    57,    41,     3,     3,     3,    84,     3,    85,     3,
+      87,   124,   129,    41,    91,    48,    93,    85,    98,    87,
+      48,    44,   100,   140,   125,    48,   139,   130,     0,     1,
+      41,    54,    53,     5,     6,     7,     8,     9,    10,    11,
+      12,    13,   120,    53,    41,    17,    18,   124,   125,    41,
+      43,    41,   129,   130,   134,   133,   124,   125,    30,    54,
+      46,    41,   139,   140,   132,    37,   144,    54,    57,   147,
+      54,   139,   150,    54,    45,    57,    41,    49,    50,    57,
+      57,     2,   160,   120,     1,     3,    50,    59,     5,     6,
+       7,     8,     9,    10,    11,    12,    13,    -1,    77,   148,
+      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
+      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
+      37,    38,    39,    40,    -1,    95,    44,    -1,     3,    -1,
+      48,    -1,    -1,    50,    -1,    52,    53,     3,    -1,     1,
+      -1,    58,    59,     5,     6,     7,     8,     9,    10,    11,
+      12,    13,    -1,     3,    -1,    17,    18,    -1,    -1,    -1,
+      -1,    -1,    -1,    -1,    14,    15,    16,    -1,    30,    44,
+      -1,    21,    22,    48,    -1,    37,    -1,    -1,    44,    54,
+      55,    56,    48,    -1,    -1,    -1,    -1,    49,    54,    -1,
+      -1,    41,    42,    -1,    44,    -1,    -1,    59,    48,    -1,
+      -1,    -1,    -1,    -1,    54,    -1,    -1,    -1,    -1,    -1,
+      60
 };
 
   /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
@@ -879,13 +881,13 @@ static const yytype_int8 yystos[] =
       53,    58,    59,    64,    67,    68,    70,    74,    53,    72,
       71,    73,    41,    48,    48,    98,    57,    57,     3,     3,
       75,    41,     3,     3,     3,     3,     3,     3,    44,    48,
-     100,   102,   103,     1,    49,    67,    91,    92,    93,   101,
-      65,    48,    69,    41,    54,    86,    87,    88,   100,   103,
-      54,    81,    82,    83,   100,    80,    81,    54,    89,    90,
-     102,    41,     3,    41,    48,    99,    53,    53,    50,    92,
-     104,    43,    97,    41,    66,    41,    54,    55,    56,    77,
-      78,    79,   102,    87,    54,    88,    57,    84,    82,    54,
-      83,    84,    90,    54,   102,    46,    94,    41,    78,    87,
+      90,   100,   102,   103,     1,    49,    67,    91,    92,    93,
+     101,    65,    48,    69,    41,    54,    86,    87,    88,   100,
+     103,    54,    81,    82,    83,   100,    80,    81,    54,    89,
+      90,    41,     3,    41,    48,    99,   102,    53,    53,    50,
+      92,   104,    43,    97,    41,    66,    41,    54,    55,    56,
+      77,    78,    79,   102,    87,    54,    88,    57,    84,    82,
+      54,    83,    84,    90,    54,    46,    94,    41,    78,    87,
       82,     4,    85,   103,    90,    45,    95,    96,    51,    53,
       14,    15,    16,    21,    22,    42,    54,    60,    76,   102,
       96,   102,    57,    54,    57,    57,    41,    97,    97
@@ -2184,9 +2186,9 @@ yyreduce:
                    { add_param (current_param, (yyvsp[0].BRACED_CODE), (yylsp[0])); }
     break;
 
-  case 34: /* grammar_declaration: "%start" symbol  */
+  case 34: /* grammar_declaration: "%start" symbols.1  */
     {
-      grammar_start_symbol_set ((yyvsp[0].symbol), (yylsp[0]));
+      grammar_start_symbols_set ((yyvsp[0].yykind_90));
     }
     break;
 
