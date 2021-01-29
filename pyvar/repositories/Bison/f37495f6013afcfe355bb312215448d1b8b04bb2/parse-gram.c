@@ -560,16 +560,16 @@ union yyalloc
 /* YYFINAL -- State number of the termination state.  */
 #define YYFINAL  3
 /* YYLAST -- Last index in YYTABLE.  */
-#define YYLAST   159
+#define YYLAST   160
 
 /* YYNTOKENS -- Number of terminals.  */
 #define YYNTOKENS  58
 /* YYNNTS -- Number of nonterminals.  */
 #define YYNNTS  34
 /* YYNRULES -- Number of rules.  */
-#define YYNRULES  107
+#define YYNRULES  108
 /* YYNRULES -- Number of states.  */
-#define YYNSTATES  147
+#define YYNSTATES  148
 
 /* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
 #define YYUNDEFTOK  2
@@ -630,7 +630,7 @@ static const yytype_uint16 yyprhs[] =
      180,   182,   184,   187,   190,   194,   196,   199,   201,   204,
      206,   209,   212,   213,   218,   220,   224,   227,   228,   232,
      236,   240,   244,   248,   249,   251,   253,   255,   256,   258,
-     260,   262,   264,   266,   268,   270,   272,   273
+     260,   262,   264,   266,   268,   270,   272,   274,   275
 };
 
 /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
@@ -661,9 +661,9 @@ static const yytype_int8 yyrhs[] =
       81,    50,    82,    -1,    81,    52,    -1,    -1,    82,    89,
       83,    -1,    82,    43,    83,    -1,    82,    13,    89,    -1,
       82,    14,     4,    -1,    82,    15,    53,    -1,    -1,    56,
-      -1,    47,    -1,     3,    -1,    -1,     3,    -1,    43,    -1,
-      47,    -1,    44,    -1,    48,    -1,    87,    -1,    90,    -1,
-       3,    -1,    -1,    49,    45,    -1
+      -1,    47,    -1,     3,    -1,    -1,    47,    -1,     3,    -1,
+      43,    -1,    47,    -1,    44,    -1,    48,    -1,    87,    -1,
+      90,    -1,     3,    -1,    -1,    49,    45,    -1
 };
 
 /* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
@@ -678,8 +678,8 @@ static const yytype_uint16 yyrline[] =
      442,   443,   448,   450,   455,   456,   460,   461,   462,   463,
      468,   473,   478,   484,   490,   501,   502,   511,   512,   518,
      519,   520,   527,   527,   532,   533,   534,   539,   541,   543,
-     545,   547,   549,   554,   556,   567,   568,   573,   574,   583,
-     603,   605,   614,   619,   620,   625,   632,   634
+     545,   547,   549,   554,   556,   567,   568,   573,   574,   575,
+     584,   604,   606,   615,   620,   621,   626,   633,   635
 };
 #endif
 
@@ -739,8 +739,8 @@ static const yytype_uint8 yyr1[] =
       71,    71,    72,    72,    73,    73,    74,    74,    74,    74,
       75,    75,    75,    75,    75,    76,    76,    77,    77,    78,
       78,    78,    80,    79,    81,    81,    81,    82,    82,    82,
-      82,    82,    82,    83,    83,    84,    84,    85,    85,    86,
-      87,    87,    88,    89,    89,    90,    91,    91
+      82,    82,    82,    83,    83,    84,    84,    85,    85,    85,
+      86,    87,    87,    88,    89,    89,    90,    91,    91
 };
 
 /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
@@ -756,7 +756,7 @@ static const yytype_uint8 yyr2[] =
        1,     1,     2,     2,     3,     1,     2,     1,     2,     1,
        2,     2,     0,     4,     1,     3,     2,     0,     3,     3,
        3,     3,     3,     0,     1,     1,     1,     0,     1,     1,
-       1,     1,     1,     1,     1,     1,     0,     2
+       1,     1,     1,     1,     1,     1,     1,     0,     2
 };
 
 /* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
@@ -769,25 +769,25 @@ static const yytype_uint8 yydefact[] =
        0,    16,     0,     0,     0,    20,     0,    41,    23,    24,
        0,     0,    28,     0,     0,     0,    31,    32,    33,     0,
        6,    34,    44,     4,     5,    36,    35,    56,     0,     0,
-       0,     0,     0,    99,     0,    42,    96,    95,    97,    10,
+       0,     0,     0,   100,     0,    42,    96,    95,    97,    10,
       12,    13,    14,     0,    17,    18,    19,    21,     0,    25,
-       0,    27,    29,    30,   105,   101,   100,   103,    37,   104,
-       0,   102,     0,     0,    77,    79,    93,    45,     0,    57,
+       0,    27,    29,    30,   106,   102,   101,   104,    37,   105,
+       0,   103,     0,     0,    77,    79,    93,    45,     0,    57,
        0,    70,    75,    50,    71,    48,    51,    62,    67,    68,
-      69,    38,    64,    66,    39,    43,    98,     8,    15,    22,
-      26,    81,    80,     0,    78,     2,    94,    82,    46,    52,
-      58,    60,    76,    72,    73,    63,    65,   107,    87,    59,
-      61,    74,    83,    84,    87,    86,     0,     0,     0,    93,
-      93,    85,    90,    91,    92,    89,    88
+      69,    38,    64,    66,    39,    43,    99,    98,     8,    15,
+      22,    26,    81,    80,     0,    78,     2,    94,    82,    46,
+      52,    58,    60,    76,    72,    73,    63,    65,   108,    87,
+      59,    61,    74,    83,    84,    87,    86,     0,     0,     0,
+      93,    93,    85,    90,    91,    92,    89,    88
 };
 
 /* YYDEFGOTO[NTERM-NUM].  */
 static const yytype_int16 yydefgoto[] =
 {
       -1,     1,     2,    43,    82,    88,    45,    49,    48,    46,
-      47,    90,   119,   120,    96,   101,   102,    92,    93,    83,
-      84,    85,   128,   132,   133,   117,    58,   107,    55,    77,
-      86,   103,    79,   115
+      47,    90,   120,   121,    96,   101,   102,    92,    93,    83,
+      84,    85,   129,   133,   134,   118,    58,   108,    55,    77,
+      86,   103,    79,   116
 };
 
 /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
@@ -795,54 +795,55 @@ static const yytype_int16 yydefgoto[] =
 #define YYPACT_NINF -60
 static const yytype_int16 yypact[] =
 {
-     -60,     4,   102,   -60,   -60,   -60,     7,    10,    22,   -60,
-     -60,   -60,    -6,   -60,   -60,    27,    40,   -60,    65,    72,
-       2,   -60,    35,    79,    47,   -60,    11,   -60,   -60,   -60,
-      25,    48,   -60,    89,    90,     0,   -60,   -60,   -60,    15,
-     -60,   -60,    52,   -60,   -60,   -60,   -60,    41,    -2,    -2,
-       0,    26,    26,   -60,    59,   -60,   -60,   -60,    92,   -60,
-     -60,   -60,   -60,   100,   -60,   -60,   -60,   -60,   101,   -60,
-     112,   -60,   -60,   -60,   -60,   -60,   -60,   -60,   -60,   -60,
-      64,   -60,    93,     1,   -60,   -60,    49,   -60,    59,   -60,
-       0,   -60,   -60,    -2,    83,    -2,     0,   -60,   -60,   -60,
+     -60,     4,   103,   -60,   -60,   -60,    -2,    -1,    10,   -60,
+     -60,   -60,    17,   -60,   -60,    27,    66,   -60,    72,    79,
+       2,   -60,    47,    88,    49,   -60,    11,   -60,   -60,   -60,
+      25,    50,   -60,    91,    92,     0,   -60,   -60,   -60,    15,
+     -60,   -60,    51,   -60,   -60,   -60,   -60,    48,    -8,    -8,
+       0,    26,    26,   -60,    60,   -60,   -60,   -60,    31,   -60,
+     -60,   -60,   -60,   101,   -60,   -60,   -60,   -60,   102,   -60,
+     113,   -60,   -60,   -60,   -60,   -60,   -60,   -60,   -60,   -60,
+      54,   -60,    65,     1,   -60,   -60,    62,   -60,    60,   -60,
+       0,   -60,   -60,    -8,    83,    -8,     0,   -60,   -60,   -60,
      -60,    26,   -60,   -60,    26,   -60,   -60,   -60,   -60,   -60,
-     -60,   -60,   -60,   103,   -60,   -60,   -60,   -60,   -60,     0,
-     -60,   113,   -60,   143,   -60,   -60,   -60,   -60,   -60,   -60,
-     -60,   -60,   -16,    53,   -60,   -60,     0,   145,    94,    49,
-      49,    53,   -60,   -60,   -60,   -60,   -60
+     -60,   -60,   -60,   -60,   104,   -60,   -60,   -60,   -60,   -60,
+       0,   -60,   142,   -60,   144,   -60,   -60,   -60,   -60,   -60,
+     -60,   -60,   -60,    -9,    53,   -60,   -60,     0,   146,    95,
+      62,    62,    53,   -60,   -60,   -60,   -60,   -60
 };
 
 /* YYPGOTO[NTERM-NUM].  */
 static const yytype_int16 yypgoto[] =
 {
-     -60,   -60,   -60,   -60,   148,   -60,   -60,   -60,   -60,   -60,
-     -60,   -60,   -60,    33,   -60,   104,   -42,   -18,   106,   -60,
-      74,   -60,   -60,   -60,    24,   -51,   -60,   -60,   -36,   -10,
+     -60,   -60,   -60,   -60,   149,   -60,   -60,   -60,   -60,   -60,
+     -60,   -60,   -60,    33,   -60,   105,   -42,   -18,   107,   -60,
+      75,   -60,   -60,   -60,    24,   -52,   -60,   -60,   -36,   -11,
      -60,   -35,   -59,   -60
 };
 
 /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
    positive, shift that token.  If negative, reduce the rule which
    number is the opposite.  If YYTABLE_NINF, syntax error.  */
-#define YYTABLE_NINF -107
+#define YYTABLE_NINF -108
 static const yytype_int16 yytable[] =
 {
-      78,  -106,    80,    74,     3,    62,     4,     5,     6,     7,
+      78,  -107,    80,    74,     3,    62,     4,     5,     6,     7,
        8,     9,    10,    11,    67,    97,    80,    12,   105,    14,
        4,     5,     6,     7,     8,     9,    10,    11,    69,    74,
-      56,    12,    27,    14,   134,   124,   135,    53,    94,    94,
-      35,    54,    75,    59,    75,    76,    27,    76,    63,    81,
-     113,    91,   118,    51,    35,   121,    74,    68,    42,   126,
-      50,   125,   126,    81,   131,    52,   136,   137,   138,    60,
-      75,    70,    42,    76,    57,   122,    61,   122,    64,    98,
-      99,   100,    65,    94,   121,    94,    74,   123,   145,   146,
-      66,    71,    72,    73,    89,   106,   139,    75,   140,    87,
-      76,   142,    53,   108,   109,   116,   140,     4,     5,     6,
-       7,     8,     9,    10,    11,   110,   111,   130,    12,    13,
-      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
-      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
-      34,    35,    36,    37,    38,   112,    74,   144,   127,   143,
-      44,    39,   129,    40,    41,    95,   104,   114,   141,    42
+      56,    12,    27,    14,   106,   125,    75,    94,    94,    76,
+      35,   135,    51,   136,    75,    91,    27,    76,    63,    81,
+     114,    50,   119,    52,    35,   122,    74,    68,    42,   127,
+      53,   126,   127,    81,    54,   132,   137,   138,   139,    59,
+      75,    70,    42,    76,    57,   123,    60,   123,   107,    98,
+      99,   100,    94,    61,    94,   122,    74,   124,   146,   147,
+      64,    65,    66,    71,    72,    73,   140,    75,    87,   141,
+      76,    89,   143,    53,   109,   110,   112,   141,     4,     5,
+       6,     7,     8,     9,    10,    11,   111,   113,   117,    12,
+      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
+      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
+      33,    34,    35,    36,    37,    38,   131,    74,   145,   128,
+     144,    44,    39,   130,    40,    41,    95,   104,   115,   142,
+      42
 };
 
 #define yypact_value_is_default(yystate) \
@@ -856,19 +857,20 @@ static const yytype_uint8 yycheck[] =
       35,     0,     1,     3,     0,     3,     5,     6,     7,     8,
        9,    10,    11,    12,     3,    50,     1,    16,    54,    18,
        5,     6,     7,     8,     9,    10,    11,    12,     3,     3,
-       3,    16,    31,    18,    50,    94,    52,    43,    48,    49,
-      39,    47,    44,     3,    44,    47,    31,    47,    46,    48,
+       3,    16,    31,    18,     3,    94,    44,    48,    49,    47,
+      39,    50,    43,    52,    44,    53,    31,    47,    46,    48,
       49,    53,    88,    43,    39,    90,     3,    46,    57,   101,
-      53,    96,   104,    48,   123,    43,    13,    14,    15,     4,
-      44,    46,    57,    47,    47,    93,     4,    95,    43,    53,
-      54,    55,     3,    93,   119,    95,     3,     4,   139,   140,
-      43,    43,     3,     3,    53,     3,    43,    44,   133,    47,
-      47,   136,    43,     3,     3,    56,   141,     5,     6,     7,
-       8,     9,    10,    11,    12,     3,    52,     4,    16,    17,
-      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
-      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
-      38,    39,    40,    41,    42,    52,     3,    53,    45,     4,
-       2,    49,   119,    51,    52,    49,    52,    83,   134,    57
+      43,    96,   104,    48,    47,   124,    13,    14,    15,     3,
+      44,    46,    57,    47,    47,    93,     4,    95,    47,    53,
+      54,    55,    93,     4,    95,   120,     3,     4,   140,   141,
+      43,     3,    43,    43,     3,     3,    43,    44,    47,   134,
+      47,    53,   137,    43,     3,     3,    52,   142,     5,     6,
+       7,     8,     9,    10,    11,    12,     3,    52,    56,    16,
+      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
+      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
+      37,    38,    39,    40,    41,    42,     4,     3,    53,    45,
+       4,     2,    49,   120,    51,    52,    49,    52,    83,   135,
+      57
 };
 
 /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
@@ -885,11 +887,11 @@ static const yytype_uint8 yystos[] =
       46,    43,     3,     3,     3,    44,    47,    87,    89,    90,
        1,    48,    62,    77,    78,    79,    88,    47,    63,    53,
       69,    53,    75,    76,    87,    76,    72,    89,    53,    54,
-      55,    73,    74,    89,    73,    86,     3,    85,     3,     3,
-       3,    52,    52,    49,    78,    91,    56,    83,    86,    70,
-      71,    89,    75,     4,    90,    89,    74,    45,    80,    71,
-       4,    90,    81,    82,    50,    52,    13,    14,    15,    43,
-      89,    82,    89,     4,    53,    83,    83
+      55,    73,    74,    89,    73,    86,     3,    47,    85,     3,
+       3,     3,    52,    52,    49,    78,    91,    56,    83,    86,
+      70,    71,    89,    75,     4,    90,    89,    74,    45,    80,
+      71,     4,    90,    81,    82,    50,    52,    13,    14,    15,
+      43,    89,    82,    89,     4,    53,    83,    83
 };
 
 #define yyerrok		(yyerrstatus = 0)
@@ -1044,7 +1046,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 	{ fputs (quotearg_style (c_quoting_style, (yyvaluep->chars)), stderr); };
 
 /* Line 721 of yacc.c  */
-#line 1048 "parse-gram.c"
+#line 1050 "parse-gram.c"
 	break;
       case 4: /* "\"integer\"" */
 
@@ -1053,7 +1055,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 	{ fprintf (stderr, "%d", (yyvaluep->integer)); };
 
 /* Line 721 of yacc.c  */
-#line 1057 "parse-gram.c"
+#line 1059 "parse-gram.c"
 	break;
       case 43: /* "\"{...}\"" */
 
@@ -1062,7 +1064,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->code)); };
 
 /* Line 721 of yacc.c  */
-#line 1066 "parse-gram.c"
+#line 1068 "parse-gram.c"
 	break;
       case 44: /* "\"char\"" */
 
@@ -1071,7 +1073,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 	{ fputs (char_name ((yyvaluep->character)), stderr); };
 
 /* Line 721 of yacc.c  */
-#line 1075 "parse-gram.c"
+#line 1077 "parse-gram.c"
 	break;
       case 45: /* "\"epilogue\"" */
 
@@ -1080,7 +1082,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
 /* Line 721 of yacc.c  */
-#line 1084 "parse-gram.c"
+#line 1086 "parse-gram.c"
 	break;
       case 47: /* "\"identifier\"" */
 
@@ -1089,7 +1091,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 	{ fputs ((yyvaluep->uniqstr), stderr); };
 
 /* Line 721 of yacc.c  */
-#line 1093 "parse-gram.c"
+#line 1095 "parse-gram.c"
 	break;
       case 48: /* "\"identifier:\"" */
 
@@ -1098,7 +1100,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 	{ fprintf (stderr, "%s:", (yyvaluep->uniqstr)); };
 
 /* Line 721 of yacc.c  */
-#line 1102 "parse-gram.c"
+#line 1104 "parse-gram.c"
 	break;
       case 51: /* "\"%{...%}\"" */
 
@@ -1107,7 +1109,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
 /* Line 721 of yacc.c  */
-#line 1111 "parse-gram.c"
+#line 1113 "parse-gram.c"
 	break;
       case 53: /* "\"type\"" */
 
@@ -1116,7 +1118,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 	{ fprintf (stderr, "<%s>", (yyvaluep->uniqstr)); };
 
 /* Line 721 of yacc.c  */
-#line 1120 "parse-gram.c"
+#line 1122 "parse-gram.c"
 	break;
       case 84: /* "variable" */
 
@@ -1125,7 +1127,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 	{ fputs ((yyvaluep->uniqstr), stderr); };
 
 /* Line 721 of yacc.c  */
-#line 1129 "parse-gram.c"
+#line 1131 "parse-gram.c"
 	break;
       case 85: /* "content.opt" */
 
@@ -1134,7 +1136,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
 /* Line 721 of yacc.c  */
-#line 1138 "parse-gram.c"
+#line 1140 "parse-gram.c"
 	break;
       case 86: /* "braceless" */
 
@@ -1143,7 +1145,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
 /* Line 721 of yacc.c  */
-#line 1147 "parse-gram.c"
+#line 1149 "parse-gram.c"
 	break;
       case 87: /* "id" */
 
@@ -1152,7 +1154,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
 /* Line 721 of yacc.c  */
-#line 1156 "parse-gram.c"
+#line 1158 "parse-gram.c"
 	break;
       case 88: /* "id_colon" */
 
@@ -1161,7 +1163,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 	{ fprintf (stderr, "%s:", (yyvaluep->symbol)->tag); };
 
 /* Line 721 of yacc.c  */
-#line 1165 "parse-gram.c"
+#line 1167 "parse-gram.c"
 	break;
       case 89: /* "symbol" */
 
@@ -1170,7 +1172,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
 /* Line 721 of yacc.c  */
-#line 1174 "parse-gram.c"
+#line 1176 "parse-gram.c"
 	break;
       case 90: /* "string_as_id" */
 
@@ -1179,7 +1181,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
 /* Line 721 of yacc.c  */
-#line 1183 "parse-gram.c"
+#line 1185 "parse-gram.c"
 	break;
       default:
 	break;
@@ -1710,7 +1712,7 @@ YYLTYPE yylloc;
 }
 
 /* Line 1250 of yacc.c  */
-#line 1714 "parse-gram.c"
+#line 1716 "parse-gram.c"
   yylsp[0] = yylloc;
 
   goto yysetstate;
@@ -2587,10 +2589,17 @@ yyreduce:
     { (yyval.chars) = ""; }
     break;
 
-  case 99:
+  case 98:
+
+/* Line 1463 of yacc.c  */
+#line 574 "parse-gram.y"
+    { (yyval.chars) = (yyvsp[(1) - (1)].uniqstr); }
+    break;
+
+  case 100:
 
 /* Line 1463 of yacc.c  */
-#line 584 "parse-gram.y"
+#line 585 "parse-gram.y"
     {
       code_props plain_code;
       (yyvsp[(1) - (1)].code)[strlen ((yyvsp[(1) - (1)].code)) - 1] = '\n';
@@ -2601,17 +2610,17 @@ yyreduce:
     }
     break;
 
-  case 100:
+  case 101:
 
 /* Line 1463 of yacc.c  */
-#line 604 "parse-gram.y"
+#line 605 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
-  case 101:
+  case 102:
 
 /* Line 1463 of yacc.c  */
-#line 606 "parse-gram.y"
+#line 607 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[(1) - (1)].character)), (yylsp[(1) - (1)]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[(1) - (1)]), false);
@@ -2619,27 +2628,27 @@ yyreduce:
     }
     break;
 
-  case 102:
+  case 103:
 
 /* Line 1463 of yacc.c  */
-#line 614 "parse-gram.y"
+#line 615 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
-  case 105:
+  case 106:
 
 /* Line 1463 of yacc.c  */
-#line 626 "parse-gram.y"
+#line 627 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[(1) - (1)].chars)), (yylsp[(1) - (1)]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[(1) - (1)]), false);
     }
     break;
 
-  case 107:
+  case 108:
 
 /* Line 1463 of yacc.c  */
-#line 635 "parse-gram.y"
+#line 636 "parse-gram.y"
     {
       code_props plain_code;
       code_props_plain_init (&plain_code, (yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)]));
@@ -2653,7 +2662,7 @@ yyreduce:
 
 
 /* Line 1463 of yacc.c  */
-#line 2657 "parse-gram.c"
+#line 2666 "parse-gram.c"
       default: break;
     }
   YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);
@@ -2872,7 +2881,7 @@ yyreturn:
 
 
 /* Line 1683 of yacc.c  */
-#line 645 "parse-gram.y"
+#line 646 "parse-gram.y"
 
 
 
