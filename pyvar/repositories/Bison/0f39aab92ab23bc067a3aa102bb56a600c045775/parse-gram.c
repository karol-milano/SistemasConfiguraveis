@@ -360,16 +360,16 @@ union yyalloc
 /* YYFINAL -- State number of the termination state. */
 #define YYFINAL  3
 /* YYLAST -- Last index in YYTABLE.  */
-#define YYLAST   125
+#define YYLAST   152
 
 /* YYNTOKENS -- Number of terminals. */
 #define YYNTOKENS  47
 /* YYNNTS -- Number of nonterminals. */
-#define YYNNTS  28
+#define YYNNTS  29
 /* YYNRULES -- Number of rules. */
-#define YYNRULES  76
+#define YYNRULES  77
 /* YYNRULES -- Number of states. */
-#define YYNSTATES  115
+#define YYNSTATES  116
 
 /* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
 #define YYUNDEFTOK  2
@@ -427,18 +427,18 @@ static const unsigned char yyprhs[] =
      111,   113,   115,   116,   118,   120,   123,   125,   127,   130,
      133,   137,   139,   142,   144,   147,   149,   152,   155,   156,
      162,   164,   168,   169,   172,   175,   179,   183,   187,   189,
-     191,   193,   195,   197,   198,   201,   202
+     191,   193,   195,   197,   199,   200,   203,   204
 };
 
 /* YYRHS -- A `-1'-separated list of the rules' RHS. */
 static const yysigned_char yyrhs[] =
 {
-      48,     0,    -1,    49,    43,    63,    73,    -1,    -1,    49,
-      50,    74,    -1,    51,    -1,    44,    -1,    17,    -1,    18,
+      48,     0,    -1,    49,    43,    63,    74,    -1,    -1,    49,
+      50,    75,    -1,    51,    -1,    44,    -1,    17,    -1,    18,
       72,    72,    -1,    19,    -1,    20,    -1,    21,     4,    -1,
-      22,    37,    72,    -1,    23,    -1,    24,    72,    40,    72,
+      22,    37,    72,    -1,    23,    -1,    24,    73,    40,    73,
       -1,    25,    -1,    26,    37,    72,    -1,    27,    -1,    28,
-      37,    72,    -1,    29,    72,    40,    72,    -1,    30,    -1,
+      37,    72,    -1,    29,    73,    40,    73,    -1,    30,    -1,
       31,    72,    -1,    33,    -1,    34,    -1,    35,    -1,    57,
       -1,    54,    -1,    32,    69,    -1,    10,    46,    -1,    -1,
        8,    52,    46,    60,    -1,    -1,     9,    53,    46,    60,
@@ -452,21 +452,21 @@ static const yysigned_char yyrhs[] =
       38,    -1,    68,    -1,    67,    41,    68,    -1,    -1,    68,
       69,    -1,    68,    70,    -1,    68,    14,    69,    -1,    68,
       15,     4,    -1,    68,    16,    36,    -1,    42,    -1,    71,
-      -1,    46,    -1,     3,    -1,     3,    -1,    -1,    43,    45,
-      -1,    -1,    38,    -1
+      -1,    46,    -1,     3,    -1,     3,    -1,    46,    -1,    -1,
+      43,    45,    -1,    -1,    38,    -1
 };
 
 /* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
 static const unsigned short yyrline[] =
 {
        0,   170,   170,   182,   184,   187,   189,   190,   191,   192,
-     193,   194,   195,   196,   197,   199,   200,   201,   202,   203,
-     205,   206,   207,   208,   209,   212,   214,   215,   219,   226,
-     225,   236,   235,   248,   247,   253,   253,   258,   267,   282,
-     284,   285,   288,   290,   295,   297,   301,   306,   311,   317,
-     323,   333,   336,   345,   347,   353,   355,   360,   367,   366,
-     371,   373,   376,   379,   381,   383,   385,   387,   391,   393,
-     396,   402,   411,   419,   421,   428,   430
+     193,   194,   195,   196,   197,   202,   203,   204,   205,   206,
+     211,   212,   213,   214,   215,   218,   220,   221,   225,   232,
+     231,   242,   241,   254,   253,   259,   259,   264,   273,   288,
+     290,   291,   294,   296,   301,   303,   307,   312,   317,   323,
+     329,   339,   342,   351,   353,   359,   361,   366,   373,   372,
+     377,   379,   382,   385,   387,   389,   391,   393,   397,   399,
+     402,   408,   417,   426,   434,   436,   443,   445
 };
 #endif
 
@@ -491,7 +491,7 @@ static const char *const yytname[] =
   "precedence_declarator", "type.opt", "symbols.1", "symbol_def", 
   "symbol_defs.1", "grammar", "rules_or_grammar_declaration", "rules", 
   "@5", "rhses.1", "rhs", "symbol", "action", "string_as_id", 
-  "string_content", "epilogue.opt", "semi_colon.opt", 0
+  "string_content", "code_content", "epilogue.opt", "semi_colon.opt", 0
 };
 #endif
 
@@ -518,7 +518,7 @@ static const unsigned char yyr1[] =
       58,    58,    59,    59,    60,    60,    61,    61,    61,    61,
       61,    62,    62,    63,    63,    64,    64,    64,    66,    65,
       67,    67,    68,    68,    68,    68,    68,    68,    69,    69,
-      70,    71,    72,    73,    73,    74,    74
+      70,    71,    72,    73,    74,    74,    75,    75
 };
 
 /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
@@ -531,7 +531,7 @@ static const unsigned char yyr2[] =
        1,     1,     0,     1,     1,     2,     1,     1,     2,     2,
        3,     1,     2,     1,     2,     1,     2,     2,     0,     5,
        1,     3,     0,     2,     2,     3,     3,     3,     1,     1,
-       1,     1,     1,     0,     2,     0,     1
+       1,     1,     1,     1,     0,     2,     0,     1
 };
 
 /* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
@@ -542,89 +542,95 @@ static const unsigned char yydefact[] =
        3,     0,     0,     1,    35,    33,     0,    29,    31,     0,
       39,    40,    41,     7,     0,     9,    10,     0,     0,    13,
        0,    15,     0,    17,     0,     0,    20,     0,     0,    22,
-      23,    24,     0,     6,    75,     5,    26,    25,    42,     0,
-       0,     0,     0,     0,    28,    72,     0,    11,     0,     0,
-       0,     0,     0,    21,    71,    68,    27,    69,     0,     0,
-       0,     0,    53,    55,    76,     4,    43,     0,    46,    47,
-      51,    36,    34,    37,    44,     0,     0,     8,    12,     0,
-      16,    18,     0,    57,    58,    56,     0,    54,     2,    38,
-      48,    49,    52,    45,    30,    32,    14,    19,    62,    74,
-      50,     0,    60,    59,    62,     0,     0,     0,    70,    63,
-      64,    61,    65,    66,    67
+      23,    24,     0,     6,    76,     5,    26,    25,    42,     0,
+       0,     0,     0,     0,    28,    72,     0,    11,     0,    73,
+       0,     0,     0,     0,    21,    71,    68,    27,    69,     0,
+       0,     0,     0,    53,    55,    77,     4,    43,     0,    46,
+      47,    51,    36,    34,    37,    44,     0,     0,     8,    12,
+       0,    16,    18,     0,    57,    58,    56,     0,    54,     2,
+      38,    48,    49,    52,    45,    30,    32,    14,    19,    62,
+      75,    50,     0,    60,    59,    62,     0,     0,     0,    70,
+      63,    64,    61,    65,    66,    67
 };
 
 /* YYDEFGOTO[NTERM-NUM]. */
 static const yysigned_char yydefgoto[] =
 {
-      -1,     1,     2,    34,    60,    42,    43,    36,    40,    39,
-      37,    38,    67,    73,    70,    71,    61,    62,    63,    98,
-     101,   102,    74,   110,    57,    46,    88,    65
+      -1,     1,     2,    34,    61,    42,    43,    36,    40,    39,
+      37,    38,    68,    74,    71,    72,    62,    63,    64,    99,
+     102,   103,    75,   111,    58,    46,    50,    89,    66
 };
 
 /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
    STATE-NUM.  */
-#define YYPACT_NINF -67
+#define YYPACT_NINF -66
 static const yysigned_char yypact[] =
 {
-     -67,     7,    81,   -67,   -67,   -67,   -13,   -67,   -67,   -16,
-     -67,   -67,   -67,   -67,    32,   -67,   -67,    36,    20,   -67,
-      32,   -67,    21,   -67,    22,    32,   -67,    32,    -1,   -67,
-     -67,   -67,    43,   -67,    24,   -67,   -67,   -67,    28,   -14,
-     -14,    -1,    25,    26,   -67,   -67,    32,   -67,    32,    30,
-      32,    32,    33,   -67,   -67,   -67,   -67,   -67,    38,    29,
-      40,     4,   -67,   -67,   -67,   -67,   -67,    -1,   -67,    16,
-     -67,   -14,   -14,    -1,   -67,    -1,    -1,   -67,   -67,    32,
-     -67,   -67,    32,   -67,   -67,   -67,    34,   -67,   -67,    -1,
-      77,   -67,   -67,   -67,    -1,    -1,   -67,   -67,   -67,   -67,
-     -67,   -20,    23,   -67,   -67,    -1,    78,    45,   -67,   -67,
-     -67,    23,   -67,   -67,   -67
+     -66,     6,   108,   -66,   -66,   -66,   -16,   -66,   -66,   -21,
+     -66,   -66,   -66,   -66,    19,   -66,   -66,    32,     5,   -66,
+       3,   -66,    10,   -66,    11,     3,   -66,    19,     1,   -66,
+     -66,   -66,    80,   -66,    12,   -66,   -66,   -66,    16,   -19,
+     -19,     1,     7,     8,   -66,   -66,    19,   -66,    19,   -66,
+      18,    19,    19,    20,   -66,   -66,   -66,   -66,   -66,    13,
+      24,    17,     2,   -66,   -66,   -66,   -66,   -66,     1,   -66,
+      29,   -66,   -19,   -19,     1,   -66,     1,     1,   -66,   -66,
+       3,   -66,   -66,     3,   -66,   -66,   -66,    21,   -66,   -66,
+       1,    61,   -66,   -66,   -66,     1,     1,   -66,   -66,   -66,
+     -66,   -66,   -17,    15,   -66,   -66,     1,    65,    34,   -66,
+     -66,   -66,    15,   -66,   -66,   -66
 };
 
 /* YYPGOTO[NTERM-NUM].  */
 static const yysigned_char yypgoto[] =
 {
-     -67,   -67,   -67,   -67,    82,   -67,   -67,   -67,   -67,   -67,
-     -67,   -67,   -67,   -42,   -29,    55,   -67,    35,   -67,   -67,
-     -67,    -7,   -28,   -67,   -66,   -19,   -67,   -67
+     -66,   -66,   -66,   -66,    63,   -66,   -66,   -66,   -66,   -66,
+     -66,   -66,   -66,   -49,   -34,    31,   -66,    14,   -66,   -66,
+     -66,   -33,   -28,   -66,   -65,   -11,   -24,   -66,   -66
 };
 
 /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
    positive, shift that token.  If negative, reduce the rule which
    number is the opposite.  If zero, do what YYDEFACT says.
    If YYTABLE_NINF, parse error.  */
-#define YYTABLE_NINF -74
+#define YYTABLE_NINF -75
 static const yysigned_char yytable[] =
 {
-      56,    49,    54,    91,   -73,    58,    52,     3,    53,     4,
-       5,     6,     7,     8,     9,    10,    11,    12,   103,    54,
-      90,   104,    68,    41,   100,    89,    54,    77,    69,    78,
-      44,    80,    81,    94,    95,    45,    28,   105,   106,   107,
-      47,    55,    92,    92,    58,    93,    59,    86,     4,     5,
-       6,     7,     8,     9,    10,    11,    12,    48,    50,    51,
-      96,    93,    64,    97,    66,    55,    93,    93,    84,   108,
-      79,    75,    76,    82,   109,    28,    83,   112,    85,    99,
-      54,   114,   113,   109,    35,    59,     4,     5,     6,     7,
-       8,     9,    10,    11,    12,    72,    87,   111,    13,    14,
-      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
-      25,    26,    27,    28,    29,    30,    31,     0,     0,     0,
-       0,     0,     0,     0,    32,    33
+      57,    53,   -74,    59,    55,    92,     3,     4,     5,     6,
+       7,     8,     9,    10,    11,    12,    54,    69,    55,    90,
+      41,   104,    45,    70,   105,    44,   101,    95,    96,   106,
+     107,   108,    55,    91,    28,    78,    47,    79,    93,    93,
+      81,    82,    48,    56,    60,    87,    94,    51,    52,    49,
+      65,    84,    67,    76,    77,    86,    97,    56,    80,    98,
+      83,   109,    94,    85,    55,    35,   100,    94,    94,   114,
+     115,    73,   112,     0,     0,   110,    88,     0,   113,     0,
+       0,    59,     0,     0,   110,     4,     5,     6,     7,     8,
+       9,    10,    11,    12,     0,     0,     0,     0,     0,     0,
+       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
+       0,     0,    28,     4,     5,     6,     7,     8,     9,    10,
+      11,    12,    60,     0,     0,    13,    14,    15,    16,    17,
+      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
+      28,    29,    30,    31,     0,     0,     0,     0,     0,     0,
+       0,    32,    33
 };
 
 static const yysigned_char yycheck[] =
 {
-      28,    20,     3,    69,     0,     1,    25,     0,    27,     5,
-       6,     7,     8,     9,    10,    11,    12,    13,    38,     3,
-       4,    41,    36,    36,    90,    67,     3,    46,    42,    48,
-      46,    50,    51,    75,    76,     3,    32,    14,    15,    16,
-       4,    42,    71,    72,     1,    73,    42,    43,     5,     6,
-       7,     8,     9,    10,    11,    12,    13,    37,    37,    37,
-      79,    89,    38,    82,    36,    42,    94,    95,    39,    46,
-      40,    46,    46,    40,   102,    32,    38,   105,    38,    45,
-       3,    36,     4,   111,     2,    42,     5,     6,     7,     8,
-       9,    10,    11,    12,    13,    40,    61,   104,    17,    18,
-      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
-      29,    30,    31,    32,    33,    34,    35,    -1,    -1,    -1,
-      -1,    -1,    -1,    -1,    43,    44
+      28,    25,     0,     1,     3,    70,     0,     5,     6,     7,
+       8,     9,    10,    11,    12,    13,    27,    36,     3,    68,
+      36,    38,     3,    42,    41,    46,    91,    76,    77,    14,
+      15,    16,     3,     4,    32,    46,     4,    48,    72,    73,
+      51,    52,    37,    42,    42,    43,    74,    37,    37,    46,
+      38,    38,    36,    46,    46,    38,    80,    42,    40,    83,
+      40,    46,    90,    39,     3,     2,    45,    95,    96,     4,
+      36,    40,   105,    -1,    -1,   103,    62,    -1,   106,    -1,
+      -1,     1,    -1,    -1,   112,     5,     6,     7,     8,     9,
+      10,    11,    12,    13,    -1,    -1,    -1,    -1,    -1,    -1,
+      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
+      -1,    -1,    32,     5,     6,     7,     8,     9,    10,    11,
+      12,    13,    42,    -1,    -1,    17,    18,    19,    20,    21,
+      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
+      32,    33,    34,    35,    -1,    -1,    -1,    -1,    -1,    -1,
+      -1,    43,    44
 };
 
 /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
@@ -635,14 +641,14 @@ static const unsigned char yystos[] =
       11,    12,    13,    17,    18,    19,    20,    21,    22,    23,
       24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
       34,    35,    43,    44,    50,    51,    54,    57,    58,    56,
-      55,    36,    52,    53,    46,     3,    72,     4,    37,    72,
-      37,    37,    72,    72,     3,    42,    69,    71,     1,    42,
-      51,    63,    64,    65,    38,    74,    36,    59,    36,    42,
-      61,    62,    62,    60,    69,    46,    46,    72,    72,    40,
-      72,    72,    40,    38,    39,    38,    43,    64,    73,    60,
-       4,    71,    61,    69,    60,    60,    72,    72,    66,    45,
-      71,    67,    68,    38,    41,    14,    15,    16,    46,    69,
-      70,    68,    69,     4,    36
+      55,    36,    52,    53,    46,     3,    72,     4,    37,    46,
+      73,    37,    37,    73,    72,     3,    42,    69,    71,     1,
+      42,    51,    63,    64,    65,    38,    75,    36,    59,    36,
+      42,    61,    62,    62,    60,    69,    46,    46,    72,    72,
+      40,    72,    72,    40,    38,    39,    38,    43,    64,    74,
+      60,     4,    71,    61,    69,    60,    60,    73,    73,    66,
+      45,    71,    67,    68,    38,    41,    14,    15,    16,    46,
+      69,    70,    68,    69,     4,    36
 };
 
 #if ! defined (YYSIZE_T) && defined (__SIZE_TYPE__)
@@ -1256,68 +1262,74 @@ yyreduce:
 
   case 14:
 #line 198 "parse-gram.y"
-    { muscle_pair_list_grow ("lex_param", yyvsp[-2].string, yyvsp[0].string); }
+    {
+			     muscle_pair_list_grow ("lex_param", yyvsp[-2].string, yyvsp[0].string);
+			     scanner_last_string_free ();
+			   }
     break;
 
   case 15:
-#line 199 "parse-gram.y"
+#line 202 "parse-gram.y"
     { locations_flag = 1; }
     break;
 
   case 16:
-#line 200 "parse-gram.y"
+#line 203 "parse-gram.y"
     { spec_name_prefix = yyvsp[0].string; }
     break;
 
   case 17:
-#line 201 "parse-gram.y"
+#line 204 "parse-gram.y"
     { no_lines_flag = 1; }
     break;
 
   case 18:
-#line 202 "parse-gram.y"
+#line 205 "parse-gram.y"
     { spec_outfile = yyvsp[0].string; }
     break;
 
   case 19:
-#line 204 "parse-gram.y"
-    { muscle_pair_list_grow ("parse_param", yyvsp[-2].string, yyvsp[0].string); }
+#line 207 "parse-gram.y"
+    {
+			     muscle_pair_list_grow ("parse_param", yyvsp[-2].string, yyvsp[0].string);
+			     scanner_last_string_free ();
+			   }
     break;
 
   case 20:
-#line 205 "parse-gram.y"
+#line 211 "parse-gram.y"
     { pure_parser = 1; }
     break;
 
   case 21:
-#line 206 "parse-gram.y"
+#line 212 "parse-gram.y"
     { skeleton = yyvsp[0].string; }
     break;
 
   case 22:
-#line 207 "parse-gram.y"
+#line 213 "parse-gram.y"
     { token_table_flag = 1; }
     break;
 
   case 23:
-#line 208 "parse-gram.y"
+#line 214 "parse-gram.y"
     { report_flag = 1; }
     break;
 
   case 24:
-#line 209 "parse-gram.y"
+#line 215 "parse-gram.y"
     { yacc_flag = 1; }
     break;
 
   case 27:
-#line 216 "parse-gram.y"
+#line 222 "parse-gram.y"
     {
       grammar_start_symbol_set (yyvsp[0].symbol, yylsp[0]);
     }
     break;
 
   case 28:
-#line 220 "parse-gram.y"
+#line 226 "parse-gram.y"
     {
       typed = 1;
       MUSCLE_INSERT_INT ("stype_line", yylsp[0].first_line);
@@ -1326,12 +1338,12 @@ yyreduce:
     break;
 
   case 29:
-#line 226 "parse-gram.y"
+#line 232 "parse-gram.y"
     { current_braced_code = destructor_braced_code; }
     break;
 
   case 30:
-#line 228 "parse-gram.y"
+#line 234 "parse-gram.y"
     {
       symbol_list_t *list;
       for (list = yyvsp[0].list; list; list = list->next)
@@ -1342,12 +1354,12 @@ yyreduce:
     break;
 
   case 31:
-#line 236 "parse-gram.y"
+#line 242 "parse-gram.y"
     { current_braced_code = printer_braced_code; }
     break;
 
   case 32:
-#line 238 "parse-gram.y"
+#line 244 "parse-gram.y"
     {
       symbol_list_t *list;
       for (list = yyvsp[0].list; list; list = list->next)
@@ -1358,12 +1370,12 @@ yyreduce:
     break;
 
   case 33:
-#line 248 "parse-gram.y"
+#line 254 "parse-gram.y"
     { current_class = nterm_sym; }
     break;
 
   case 34:
-#line 249 "parse-gram.y"
+#line 255 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
@@ -1371,12 +1383,12 @@ yyreduce:
     break;
 
   case 35:
-#line 253 "parse-gram.y"
+#line 259 "parse-gram.y"
     { current_class = token_sym; }
     break;
 
   case 36:
-#line 254 "parse-gram.y"
+#line 260 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
@@ -1384,7 +1396,7 @@ yyreduce:
     break;
 
   case 37:
-#line 259 "parse-gram.y"
+#line 265 "parse-gram.y"
     {
       symbol_list_t *list;
       for (list = yyvsp[0].list; list; list = list->next)
@@ -1394,7 +1406,7 @@ yyreduce:
     break;
 
   case 38:
-#line 269 "parse-gram.y"
+#line 275 "parse-gram.y"
     {
       symbol_list_t *list;
       ++current_prec;
@@ -1409,49 +1421,49 @@ yyreduce:
     break;
 
   case 39:
-#line 283 "parse-gram.y"
+#line 289 "parse-gram.y"
     { yyval.assoc = left_assoc; }
     break;
 
   case 40:
-#line 284 "parse-gram.y"
+#line 290 "parse-gram.y"
     { yyval.assoc = right_assoc; }
     break;
 
   case 41:
-#line 285 "parse-gram.y"
+#line 291 "parse-gram.y"
     { yyval.assoc = non_assoc; }
     break;
 
   case 42:
-#line 289 "parse-gram.y"
+#line 295 "parse-gram.y"
     { current_type = NULL; }
     break;
 
   case 43:
-#line 290 "parse-gram.y"
+#line 296 "parse-gram.y"
     { current_type = yyvsp[0].struniq; }
     break;
 
   case 44:
-#line 296 "parse-gram.y"
+#line 302 "parse-gram.y"
     { yyval.list = symbol_list_new (yyvsp[0].symbol, yylsp[0]); }
     break;
 
   case 45:
-#line 297 "parse-gram.y"
+#line 303 "parse-gram.y"
     { yyval.list = symbol_list_prepend (yyvsp[-1].list, yyvsp[0].symbol, yylsp[0]); }
     break;
 
   case 46:
-#line 303 "parse-gram.y"
+#line 309 "parse-gram.y"
     {
        current_type = yyvsp[0].struniq;
      }
     break;
 
   case 47:
-#line 307 "parse-gram.y"
+#line 313 "parse-gram.y"
     {
        symbol_class_set (yyvsp[0].symbol, current_class, yylsp[0]);
        symbol_type_set (yyvsp[0].symbol, current_type, yylsp[0]);
@@ -1459,7 +1471,7 @@ yyreduce:
     break;
 
   case 48:
-#line 312 "parse-gram.y"
+#line 318 "parse-gram.y"
     {
       symbol_class_set (yyvsp[-1].symbol, current_class, yylsp[-1]);
       symbol_type_set (yyvsp[-1].symbol, current_type, yylsp[-1]);
@@ -1468,7 +1480,7 @@ yyreduce:
     break;
 
   case 49:
-#line 318 "parse-gram.y"
+#line 324 "parse-gram.y"
     {
       symbol_class_set (yyvsp[-1].symbol, current_class, yylsp[-1]);
       symbol_type_set (yyvsp[-1].symbol, current_type, yylsp[-1]);
@@ -1477,7 +1489,7 @@ yyreduce:
     break;
 
   case 50:
-#line 324 "parse-gram.y"
+#line 330 "parse-gram.y"
     {
       symbol_class_set (yyvsp[-2].symbol, current_class, yylsp[-2]);
       symbol_type_set (yyvsp[-2].symbol, current_type, yylsp[-2]);
@@ -1487,17 +1499,17 @@ yyreduce:
     break;
 
   case 51:
-#line 335 "parse-gram.y"
+#line 341 "parse-gram.y"
     {;}
     break;
 
   case 52:
-#line 337 "parse-gram.y"
+#line 343 "parse-gram.y"
     {;}
     break;
 
   case 56:
-#line 356 "parse-gram.y"
+#line 362 "parse-gram.y"
     {
       if (yacc_flag)
 	complain_at (yyloc, _("POSIX forbids declarations in the grammar"));
@@ -1505,79 +1517,79 @@ yyreduce:
     break;
 
   case 57:
-#line 361 "parse-gram.y"
+#line 367 "parse-gram.y"
     {
       yyerrok;
     }
     break;
 
   case 58:
-#line 367 "parse-gram.y"
+#line 373 "parse-gram.y"
     { current_lhs = yyvsp[-1].symbol; current_lhs_location = yylsp[-1]; }
     break;
 
   case 59:
-#line 368 "parse-gram.y"
+#line 374 "parse-gram.y"
     {;}
     break;
 
   case 60:
-#line 372 "parse-gram.y"
+#line 378 "parse-gram.y"
     { grammar_rule_end (yylsp[0]); }
     break;
 
   case 61:
-#line 373 "parse-gram.y"
+#line 379 "parse-gram.y"
     { grammar_rule_end (yylsp[0]); }
     break;
 
   case 62:
-#line 378 "parse-gram.y"
+#line 384 "parse-gram.y"
     { grammar_rule_begin (current_lhs, current_lhs_location); }
     break;
 
   case 63:
-#line 380 "parse-gram.y"
+#line 386 "parse-gram.y"
     { grammar_current_rule_symbol_append (yyvsp[0].symbol, yylsp[0]); }
     break;
 
   case 64:
-#line 382 "parse-gram.y"
+#line 388 "parse-gram.y"
     { grammar_current_rule_action_append (yyvsp[0].string, yylsp[0]); }
     break;
 
   case 65:
-#line 384 "parse-gram.y"
+#line 390 "parse-gram.y"
     { grammar_current_rule_prec_set (yyvsp[0].symbol, yylsp[0]); }
     break;
 
   case 66:
-#line 386 "parse-gram.y"
+#line 392 "parse-gram.y"
     { grammar_current_rule_dprec_set (yyvsp[0].integer, yylsp[0]); }
     break;
 
   case 67:
-#line 388 "parse-gram.y"
+#line 394 "parse-gram.y"
     { grammar_current_rule_merge_set (yyvsp[0].struniq, yylsp[0]); }
     break;
 
   case 68:
-#line 392 "parse-gram.y"
+#line 398 "parse-gram.y"
     { yyval.symbol = yyvsp[0].symbol; }
     break;
 
   case 69:
-#line 393 "parse-gram.y"
+#line 399 "parse-gram.y"
     { yyval.symbol = yyvsp[0].symbol; }
     break;
 
   case 70:
-#line 398 "parse-gram.y"
+#line 404 "parse-gram.y"
     { yyval.string = yyvsp[0].string; }
     break;
 
   case 71:
-#line 404 "parse-gram.y"
+#line 410 "parse-gram.y"
     {
       yyval.symbol = symbol_get (yyvsp[0].string, yylsp[0]);
       symbol_class_set (yyval.symbol, token_sym, yylsp[0]);
@@ -1585,15 +1597,23 @@ yyreduce:
     break;
 
   case 72:
-#line 413 "parse-gram.y"
+#line 419 "parse-gram.y"
+    {
+      yyval.string = yyvsp[0].string + 1;
+      yyval.string[strlen (yyval.string) - 1] = '\0';
+    }
+    break;
+
+  case 73:
+#line 428 "parse-gram.y"
     {
       yyval.string = yyvsp[0].string + 1;
       yyval.string[strlen (yyval.string) - 1] = '\0';
     }
     break;
 
-  case 74:
-#line 422 "parse-gram.y"
+  case 75:
+#line 437 "parse-gram.y"
     {
       epilogue_augment (yyvsp[0].string, yylsp[0]);
       scanner_last_string_free ();
@@ -1604,7 +1624,7 @@ yyreduce:
     }
 
 /* Line 950 of /usr/local/share/bison/yacc.c.  */
-#line 1607 "parse-gram.c"
+#line 1627 "parse-gram.c"
 
   yyvsp -= yylen;
   yyssp -= yylen;
@@ -1823,7 +1843,7 @@ yyreturn:
 }
 
 
-#line 432 "parse-gram.y"
+#line 447 "parse-gram.y"
 
 /*------------------------------------------------------------------.
 | When debugging the parser, display tokens' locations and values.  |
