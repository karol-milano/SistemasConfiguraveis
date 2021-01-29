@@ -225,12 +225,13 @@ int current_prec = 0;
 #line 89 "parse-gram.y"
 typedef union {
   symbol_t *symbol;
+  symbol_list *list;
   int integer;
   char *string;
   associativity assoc;
 } yystype;
 /* Line 199 of /usr/local/share/bison/bison.simple.  */
-#line 234 "parse-gram.c"
+#line 235 "parse-gram.c"
 # define YYSTYPE yystype
 # define YYSTYPE_IS_TRIVIAL 1
 #endif
@@ -251,7 +252,7 @@ typedef struct yyltype
 
 
 /* Line 219 of /usr/local/share/bison/bison.simple.  */
-#line 255 "parse-gram.c"
+#line 256 "parse-gram.c"
 
 #if ! defined (yyoverflow) || YYERROR_VERBOSE
 
@@ -353,16 +354,16 @@ union yyalloc
 /* YYFINAL -- State number of the termination state. */
 #define YYFINAL  3
 #define YYFLAG	 -32768
-#define YYLAST   102
+#define YYLAST   111
 
 /* YYNTOKENS -- Number of terminals. */
 #define YYNTOKENS  40
 /* YYNNTS -- Number of nonterminals. */
-#define YYNNTS  29
+#define YYNNTS  26
 /* YYNRULES -- Number of rules. */
-#define YYNRULES  71
+#define YYNRULES  67
 /* YYNRULES -- Number of states. */
-#define YYNSTATES  97
+#define YYNSTATES  93
 
 /* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
 #define YYUNDEFTOK  2
@@ -414,47 +415,45 @@ static const unsigned char yyprhs[] =
        0,     0,     3,     8,     9,    13,    15,    17,    19,    23,
       25,    27,    30,    34,    36,    40,    42,    46,    48,    51,
       53,    55,    57,    59,    61,    64,    67,    68,    72,    73,
-      77,    78,    83,    84,    89,    91,    93,    95,    96,    98,
-     100,   103,   105,   108,   110,   112,   115,   118,   122,   124,
-     127,   129,   132,   134,   137,   138,   144,   146,   150,   151,
-     154,   157,   161,   163,   165,   167,   169,   171,   173,   174,
-     177,   178
+      77,    81,    85,    87,    89,    91,    92,    94,    96,    99,
+     101,   103,   106,   109,   113,   115,   118,   120,   123,   125,
+     128,   129,   135,   137,   141,   142,   145,   148,   152,   154,
+     156,   158,   160,   162,   164,   165,   168,   169
 };
 
 /* YYRHS -- A `-1'-separated list of the rules' RHS. */
 static const signed char yyrhs[] =
 {
-      41,     0,    -1,    42,    36,    57,    67,    -1,    -1,    42,
-      43,    68,    -1,    44,    -1,    37,    -1,    25,    -1,    21,
-      66,    66,    -1,    23,    -1,    17,    -1,    13,     5,    -1,
-      19,    31,    66,    -1,    26,    -1,    20,    31,    66,    -1,
-      27,    -1,    18,    31,    66,    -1,    22,    -1,    28,    66,
-      -1,    29,    -1,    16,    -1,    24,    -1,    49,    -1,    45,
-      -1,    14,    63,    -1,     9,    39,    -1,    -1,     7,    46,
-      56,    -1,    -1,     6,    47,    56,    -1,    -1,     8,    30,
-      48,    53,    -1,    -1,    51,    52,    50,    54,    -1,    10,
-      -1,    11,    -1,    12,    -1,    -1,    30,    -1,    35,    -1,
-      53,    35,    -1,    63,    -1,    54,    63,    -1,    30,    -1,
-      35,    -1,    35,     5,    -1,    35,    65,    -1,    35,     5,
-      65,    -1,    55,    -1,    56,    55,    -1,    58,    -1,    57,
-      58,    -1,    59,    -1,    44,    32,    -1,    -1,    35,    33,
-      60,    61,    32,    -1,    62,    -1,    61,    34,    62,    -1,
-      -1,    62,    63,    -1,    62,    64,    -1,    62,    15,    63,
-      -1,    35,    -1,    65,    -1,     4,    -1,    39,    -1,     3,
-      -1,     3,    -1,    -1,    36,    38,    -1,    -1,    32,    -1
+      41,     0,    -1,    42,    36,    54,    64,    -1,    -1,    42,
+      43,    65,    -1,    44,    -1,    37,    -1,    25,    -1,    21,
+      63,    63,    -1,    23,    -1,    17,    -1,    13,     5,    -1,
+      19,    31,    63,    -1,    26,    -1,    20,    31,    63,    -1,
+      27,    -1,    18,    31,    63,    -1,    22,    -1,    28,    63,
+      -1,    29,    -1,    16,    -1,    24,    -1,    48,    -1,    45,
+      -1,    14,    60,    -1,     9,    39,    -1,    -1,     7,    46,
+      53,    -1,    -1,     6,    47,    53,    -1,     8,    30,    51,
+      -1,    49,    50,    51,    -1,    10,    -1,    11,    -1,    12,
+      -1,    -1,    30,    -1,    60,    -1,    51,    60,    -1,    30,
+      -1,    35,    -1,    35,     5,    -1,    35,    62,    -1,    35,
+       5,    62,    -1,    52,    -1,    53,    52,    -1,    55,    -1,
+      54,    55,    -1,    56,    -1,    44,    32,    -1,    -1,    35,
+      33,    57,    58,    32,    -1,    59,    -1,    58,    34,    59,
+      -1,    -1,    59,    60,    -1,    59,    61,    -1,    59,    15,
+      60,    -1,    35,    -1,    62,    -1,     4,    -1,    39,    -1,
+       3,    -1,     3,    -1,    -1,    36,    38,    -1,    -1,    32,
+      -1
 };
 
 /* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
 static const unsigned short yyrline[] =
 {
-       0,   150,   150,   163,   165,   168,   170,   171,   172,   173,
-     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
-     184,   185,   188,   190,   191,   195,   203,   203,   209,   209,
-     214,   214,   220,   220,   227,   229,   230,   233,   235,   239,
-     241,   245,   251,   259,   264,   269,   275,   281,   291,   294,
-     303,   305,   311,   313,   316,   316,   321,   323,   326,   329,
-     331,   333,   337,   339,   340,   343,   349,   358,   366,   371,
-     377,   379
+       0,   151,   151,   164,   166,   169,   171,   172,   173,   174,
+     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
+     185,   186,   189,   191,   192,   196,   204,   204,   210,   210,
+     215,   224,   239,   241,   242,   245,   247,   252,   254,   258,
+     263,   268,   274,   280,   290,   293,   302,   304,   310,   312,
+     315,   315,   320,   322,   325,   328,   330,   332,   336,   338,
+     339,   342,   348,   357,   365,   370,   376,   378
 };
 #endif
 
@@ -472,12 +471,12 @@ static const char *const yytname[] =
   "\"%skeleton\"", "\"%token-table\"", "TYPE", "\"=\"", "\";\"", "\":\"", 
   "\"|\"", "\"identifier\"", "\"%%\"", "PROLOGUE", "EPILOGUE", 
   "BRACED_CODE", "$axiom", "input", "declarations", "declaration", 
-  "grammar_declaration", "symbol_declaration", "@1", "@2", "@3", 
-  "precedence_declaration", "@4", "precedence_declarator", "type.opt", 
-  "nterms_to_type.1", "terms_to_prec.1", "symbol_def", "symbol_defs.1", 
-  "grammar", "rules_or_grammar_declaration", "rules", "@5", "rhses.1", 
-  "rhs", "symbol", "action", "string_as_id", "string_content", 
-  "epilogue.opt", "semi_colon.opt", 0
+  "grammar_declaration", "symbol_declaration", "@1", "@2", 
+  "precedence_declaration", "precedence_declarator", "type.opt", 
+  "symbols.1", "symbol_def", "symbol_defs.1", "grammar", 
+  "rules_or_grammar_declaration", "rules", "@3", "rhses.1", "rhs", 
+  "symbol", "action", "string_as_id", "string_content", "epilogue.opt", 
+  "semi_colon.opt", 0
 };
 #endif
 
@@ -498,11 +497,10 @@ static const unsigned char yyr1[] =
        0,    40,    41,    42,    42,    43,    43,    43,    43,    43,
       43,    43,    43,    43,    43,    43,    43,    43,    43,    43,
       43,    43,    44,    44,    44,    44,    46,    45,    47,    45,
-      48,    45,    50,    49,    51,    51,    51,    52,    52,    53,
-      53,    54,    54,    55,    55,    55,    55,    55,    56,    56,
-      57,    57,    58,    58,    60,    59,    61,    61,    62,    62,
-      62,    62,    63,    63,    63,    64,    65,    66,    67,    67,
-      68,    68
+      45,    48,    49,    49,    49,    50,    50,    51,    51,    52,
+      52,    52,    52,    52,    53,    53,    54,    54,    55,    55,
+      57,    56,    58,    58,    59,    59,    59,    59,    60,    60,
+      60,    61,    62,    63,    64,    64,    65,    65
 };
 
 /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
@@ -511,11 +509,10 @@ static const unsigned char yyr2[] =
        0,     2,     4,     0,     3,     1,     1,     1,     3,     1,
        1,     2,     3,     1,     3,     1,     3,     1,     2,     1,
        1,     1,     1,     1,     2,     2,     0,     3,     0,     3,
-       0,     4,     0,     4,     1,     1,     1,     0,     1,     1,
-       2,     1,     2,     1,     1,     2,     2,     3,     1,     2,
-       1,     2,     1,     2,     0,     5,     1,     3,     0,     2,
-       2,     3,     1,     1,     1,     1,     1,     1,     0,     2,
-       0,     1
+       3,     3,     1,     1,     1,     0,     1,     1,     2,     1,
+       1,     2,     2,     3,     1,     2,     1,     2,     1,     2,
+       0,     5,     1,     3,     0,     2,     2,     3,     1,     1,
+       1,     1,     1,     1,     0,     2,     0,     1
 };
 
 /* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
@@ -523,48 +520,48 @@ static const unsigned char yyr2[] =
    means the default is an error.  */
 static const short yydefact[] =
 {
-       3,     0,     0,     0,    28,    26,     0,     0,    34,    35,
-      36,     0,     0,    20,    10,     0,     0,     0,     0,    17,
-       9,    21,     7,    13,    15,     0,    19,     0,     6,    70,
-       5,    23,    22,    37,     0,     0,    30,    25,    11,    66,
-      64,    62,    24,    63,     0,     0,     0,    67,     0,    18,
-       0,     0,    68,    50,    52,    71,     4,    38,    32,    43,
-      44,    48,    29,    27,     0,    16,    12,    14,     8,    54,
-      53,     0,    51,     2,     0,    45,    46,    49,    39,    31,
-      58,    69,    33,    41,    47,    40,     0,    56,    42,    55,
-      58,     0,    65,    59,    60,    57,    61
+       3,     0,     0,     0,    28,    26,     0,     0,    32,    33,
+      34,     0,     0,    20,    10,     0,     0,     0,     0,    17,
+       9,    21,     7,    13,    15,     0,    19,     0,     6,    66,
+       5,    23,    22,    35,     0,     0,     0,    25,    11,    62,
+      60,    58,    24,    59,     0,     0,     0,    63,     0,    18,
+       0,     0,    64,    46,    48,    67,     4,    36,     0,    39,
+      40,    44,    29,    27,    30,    37,    16,    12,    14,     8,
+      50,    49,     0,    47,     2,    31,    41,    42,    45,    38,
+      54,    65,    43,     0,    52,    51,    54,     0,    61,    55,
+      56,    53,    57
 };
 
 /* YYPGOTO[NTERM-NUM]. */
 static const short yydefgoto[] =
 {
-      -1,     1,     2,    29,    51,    31,    35,    34,    64,    32,
-      74,    33,    58,    79,    82,    61,    62,    52,    53,    54,
-      80,    86,    87,    93,    94,    43,    48,    73,    56
+      -1,     1,     2,    29,    51,    31,    35,    34,    32,    33,
+      58,    64,    61,    62,    52,    53,    54,    80,    83,    84,
+      65,    90,    43,    48,    74,    56
 };
 
 /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
    STATE-NUM.  */
 static const short yypact[] =
 {
-  -32768,     9,    32,-32768,-32768,-32768,   -13,    -9,-32768,-32768,
-  -32768,    27,     0,-32768,-32768,     3,     5,    33,    60,-32768,
-  -32768,-32768,-32768,-32768,-32768,    60,-32768,    12,-32768,    34,
-  -32768,-32768,-32768,    35,   -24,   -24,-32768,-32768,-32768,-32768,
-  -32768,-32768,-32768,-32768,    60,    60,    60,-32768,    60,-32768,
-      38,    49,    66,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-       2,-32768,   -24,   -24,    47,-32768,-32768,-32768,-32768,-32768,
-  -32768,    29,-32768,-32768,     0,    80,-32768,-32768,-32768,    50,
-  -32768,-32768,     0,-32768,-32768,-32768,   -20,    -2,-32768,-32768,
-  -32768,     0,-32768,-32768,-32768,    -2,-32768
+  -32768,    23,    74,-32768,-32768,-32768,     1,   -31,-32768,-32768,
+  -32768,    29,     0,-32768,-32768,     7,    10,    14,    39,-32768,
+  -32768,-32768,-32768,-32768,-32768,    39,-32768,    18,-32768,    15,
+  -32768,-32768,-32768,    16,   -24,   -24,     0,-32768,-32768,-32768,
+  -32768,-32768,-32768,-32768,    39,    39,    39,-32768,    39,-32768,
+      17,    19,     8,-32768,-32768,-32768,-32768,-32768,     0,-32768,
+       4,-32768,   -24,   -24,     0,-32768,-32768,-32768,-32768,-32768,
+  -32768,-32768,    20,-32768,-32768,     0,    45,-32768,-32768,-32768,
+  -32768,-32768,-32768,   -22,    -2,-32768,-32768,     0,-32768,-32768,
+  -32768,    -2,-32768
 };
 
 /* YYPGOTO[NTERM-NUM].  */
 static const short yypgoto[] =
 {
-  -32768,-32768,-32768,-32768,    82,-32768,-32768,-32768,-32768,-32768,
-  -32768,-32768,-32768,-32768,-32768,   -47,    51,-32768,    36,-32768,
-  -32768,-32768,    -3,   -12,-32768,   -50,   -17,-32768,-32768
+  -32768,-32768,-32768,-32768,    47,-32768,-32768,-32768,-32768,-32768,
+  -32768,    -4,   -23,    25,-32768,     9,-32768,-32768,-32768,   -21,
+     -12,-32768,   -55,    11,-32768,-32768
 };
 
 /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
@@ -572,32 +569,34 @@ static const short yypgoto[] =
    number is the opposite.  If zero, do what YYDEFACT says.  */
 static const short yytable[] =
 {
-      42,    39,    40,    39,    40,    39,    59,    75,    49,     3,
-      76,    60,    89,    91,    90,    77,    77,    36,     4,     5,
-       6,     7,     8,     9,    10,    84,    12,    65,    66,    67,
-      37,    68,    38,    41,    44,    41,    45,    92,     4,     5,
-       6,     7,     8,     9,    10,    11,    12,    50,    13,    14,
-      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
-      25,    26,    83,    47,    46,    57,    55,    81,    27,    28,
-      88,    69,     4,     5,     6,     7,     8,     9,    10,    96,
-      12,    70,    78,    39,    30,    85,    63,    95,    72,     0,
-       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
-       0,    50,    71
+      42,    39,    40,    39,    40,    77,    59,    39,    37,    76,
+      85,    60,    86,    87,     4,     5,     6,     7,     8,     9,
+      10,    82,    12,     3,     4,     5,     6,     7,     8,     9,
+      10,    36,    12,    41,    38,    41,    49,    88,    44,    78,
+      78,    45,    47,    50,    72,    46,    57,    55,    39,    30,
+      70,    71,    79,    50,    75,    66,    67,    68,    81,    69,
+      63,    73,     0,    79,     0,    91,     0,     0,     0,     0,
+       0,     0,    89,     0,     0,    92,     0,     0,     0,    89,
+       4,     5,     6,     7,     8,     9,    10,    11,    12,     0,
+      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
+      23,    24,    25,    26,     0,     0,     0,     0,     0,     0,
+      27,    28
 };
 
 static const short yycheck[] =
 {
-      12,     3,     4,     3,     4,     3,    30,     5,    25,     0,
-      60,    35,    32,    15,    34,    62,    63,    30,     6,     7,
-       8,     9,    10,    11,    12,    75,    14,    44,    45,    46,
-      39,    48,     5,    35,    31,    35,    31,    39,     6,     7,
-       8,     9,    10,    11,    12,    13,    14,    35,    16,    17,
-      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
-      28,    29,    74,     3,    31,    30,    32,    38,    36,    37,
-      82,    33,     6,     7,     8,     9,    10,    11,    12,    91,
-      14,    32,    35,     3,     2,    35,    35,    90,    52,    -1,
-      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
-      -1,    35,    36
+      12,     3,     4,     3,     4,    60,    30,     3,    39,     5,
+      32,    35,    34,    15,     6,     7,     8,     9,    10,    11,
+      12,    76,    14,     0,     6,     7,     8,     9,    10,    11,
+      12,    30,    14,    35,     5,    35,    25,    39,    31,    62,
+      63,    31,     3,    35,    36,    31,    30,    32,     3,     2,
+      33,    32,    64,    35,    58,    44,    45,    46,    38,    48,
+      35,    52,    -1,    75,    -1,    86,    -1,    -1,    -1,    -1,
+      -1,    -1,    84,    -1,    -1,    87,    -1,    -1,    -1,    91,
+       6,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
+      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
+      26,    27,    28,    29,    -1,    -1,    -1,    -1,    -1,    -1,
+      36,    37
 };
 
 #if YYDEBUG
@@ -608,13 +607,13 @@ static const unsigned char yystos[] =
        0,    41,    42,     0,     6,     7,     8,     9,    10,    11,
       12,    13,    14,    16,    17,    18,    19,    20,    21,    22,
       23,    24,    25,    26,    27,    28,    29,    36,    37,    43,
-      44,    45,    49,    51,    47,    46,    30,    39,     5,     3,
-       4,    35,    63,    65,    31,    31,    31,     3,    66,    66,
-      35,    44,    57,    58,    59,    32,    68,    30,    52,    30,
-      35,    55,    56,    56,    48,    66,    66,    66,    66,    33,
-      32,    36,    58,    67,    50,     5,    65,    55,    35,    53,
-      60,    38,    54,    63,    65,    35,    61,    62,    63,    32,
-      34,    15,    39,    63,    64,    62,    63
+      44,    45,    48,    49,    47,    46,    30,    39,     5,     3,
+       4,    35,    60,    62,    31,    31,    31,     3,    63,    63,
+      35,    44,    54,    55,    56,    32,    65,    30,    50,    30,
+      35,    52,    53,    53,    51,    60,    63,    63,    63,    63,
+      33,    32,    36,    55,    64,    51,     5,    62,    52,    60,
+      57,    38,    62,    58,    59,    32,    34,    15,    39,    60,
+      61,    59,    60
 };
 #endif
 
@@ -1184,7 +1183,7 @@ yyreduce:
   switch (yyn)
     {
         case 2:
-#line 152 "parse-gram.y"
+#line 153 "parse-gram.y"
     {
       yycontrol->errcode = 0;
       epilogue_set (yyvsp[0].string, yylsp[0]);
@@ -1192,94 +1191,94 @@ yyreduce:
     break;
 
   case 6:
-#line 170 "parse-gram.y"
+#line 171 "parse-gram.y"
     { prologue_augment (yyvsp[0].string, yylsp[0]); }
     break;
 
   case 7:
-#line 171 "parse-gram.y"
+#line 172 "parse-gram.y"
     { debug_flag = 1; }
     break;
 
   case 8:
-#line 172 "parse-gram.y"
+#line 173 "parse-gram.y"
     { muscle_insert (yyvsp[-1].string, yyvsp[0].string); }
     break;
 
   case 9:
-#line 173 "parse-gram.y"
+#line 174 "parse-gram.y"
     { defines_flag = 1; }
     break;
 
   case 10:
-#line 174 "parse-gram.y"
+#line 175 "parse-gram.y"
     { error_verbose = 1; }
     break;
 
   case 11:
-#line 175 "parse-gram.y"
+#line 176 "parse-gram.y"
     { expected_conflicts = yyvsp[0].integer; }
     break;
 
   case 12:
-#line 176 "parse-gram.y"
+#line 177 "parse-gram.y"
     { spec_file_prefix = yyvsp[0].string; }
     break;
 
   case 13:
-#line 177 "parse-gram.y"
+#line 178 "parse-gram.y"
     { locations_flag = 1; }
     break;
 
   case 14:
-#line 178 "parse-gram.y"
+#line 179 "parse-gram.y"
     { spec_name_prefix = yyvsp[0].string; }
     break;
 
   case 15:
-#line 179 "parse-gram.y"
+#line 180 "parse-gram.y"
     { no_lines_flag = 1; }
     break;
 
   case 16:
-#line 180 "parse-gram.y"
+#line 181 "parse-gram.y"
     { spec_outfile = yyvsp[0].string; }
     break;
 
   case 17:
-#line 181 "parse-gram.y"
+#line 182 "parse-gram.y"
     { pure_parser = 1; }
     break;
 
   case 18:
-#line 182 "parse-gram.y"
+#line 183 "parse-gram.y"
     { skeleton = yyvsp[0].string; }
     break;
 
   case 19:
-#line 183 "parse-gram.y"
+#line 184 "parse-gram.y"
     { token_table_flag = 1; }
     break;
 
   case 20:
-#line 184 "parse-gram.y"
+#line 185 "parse-gram.y"
     { report_flag = 1; }
     break;
 
   case 21:
-#line 185 "parse-gram.y"
+#line 186 "parse-gram.y"
     { yacc_flag = 1; }
     break;
 
   case 24:
-#line 192 "parse-gram.y"
+#line 193 "parse-gram.y"
     {
       grammar_start_symbol_set (yyvsp[0].symbol, yylsp[0]);
     }
     break;
 
   case 25:
-#line 196 "parse-gram.y"
+#line 197 "parse-gram.y"
     {
       typed = 1;
       MUSCLE_INSERT_INT ("stype_line", yylsp[0].first_line);
@@ -1288,12 +1287,12 @@ yyreduce:
     break;
 
   case 26:
-#line 204 "parse-gram.y"
+#line 205 "parse-gram.y"
     { current_class = nterm_sym; }
     break;
 
   case 27:
-#line 205 "parse-gram.y"
+#line 206 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
@@ -1301,12 +1300,12 @@ yyreduce:
     break;
 
   case 28:
-#line 209 "parse-gram.y"
+#line 210 "parse-gram.y"
     { current_class = token_sym; }
     break;
 
   case 29:
-#line 210 "parse-gram.y"
+#line 211 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
@@ -1314,216 +1313,203 @@ yyreduce:
     break;
 
   case 30:
-#line 214 "parse-gram.y"
-    {current_type = yyvsp[0].string; }
+#line 216 "parse-gram.y"
+    {
+      symbol_list *list;
+      for (list = yyvsp[0].list; list; list = list->next)
+	symbol_type_set (list->sym, list->location, yyvsp[-1].string);
+      LIST_FREE (symbol_list, yyvsp[0].list);
+    }
     break;
 
   case 31:
-#line 215 "parse-gram.y"
+#line 226 "parse-gram.y"
     {
+      symbol_list *list;
+      ++current_prec;
+      for (list = yyvsp[0].list; list; list = list->next)
+	{
+	  symbol_type_set (list->sym, list->location, current_type);
+	  symbol_precedence_set (list->sym, list->location, current_prec, yyvsp[-2].assoc);
+	}
+      LIST_FREE (symbol_list, yyvsp[0].list);
       current_type = NULL;
     }
     break;
 
   case 32:
-#line 222 "parse-gram.y"
-    { current_assoc = yyvsp[-1].assoc; ++current_prec; }
+#line 240 "parse-gram.y"
+    { yyval.assoc = left_assoc; }
     break;
 
   case 33:
-#line 224 "parse-gram.y"
-    { current_assoc = non_assoc; current_type = NULL; }
+#line 241 "parse-gram.y"
+    { yyval.assoc = right_assoc; }
     break;
 
   case 34:
-#line 228 "parse-gram.y"
-    { yyval.assoc = left_assoc; }
+#line 242 "parse-gram.y"
+    { yyval.assoc = non_assoc; }
     break;
 
   case 35:
-#line 229 "parse-gram.y"
-    { yyval.assoc = right_assoc; }
+#line 246 "parse-gram.y"
+    { current_type = NULL;}
     break;
 
   case 36:
-#line 230 "parse-gram.y"
-    { yyval.assoc = non_assoc; }
+#line 247 "parse-gram.y"
+    { current_type = yyvsp[0].string; }
     break;
 
   case 37:
-#line 234 "parse-gram.y"
-    { current_type = NULL;}
+#line 253 "parse-gram.y"
+    { yyval.list = symbol_list_new (yyvsp[0].symbol, yylsp[0]); }
     break;
 
   case 38:
-#line 235 "parse-gram.y"
-    { current_type = yyvsp[0].string; }
+#line 254 "parse-gram.y"
+    { yyval.list = symbol_list_prepend (yyvsp[-1].list, yyvsp[0].symbol, yylsp[0]); }
     break;
 
   case 39:
-#line 240 "parse-gram.y"
-    { symbol_type_set (yyvsp[0].symbol, current_type); }
-    break;
-
-  case 40:
-#line 241 "parse-gram.y"
-    { symbol_type_set (yyvsp[0].symbol, current_type); }
-    break;
-
-  case 41:
-#line 247 "parse-gram.y"
-    {
-      symbol_type_set (yyvsp[0].symbol, current_type);
-      symbol_precedence_set (yyvsp[0].symbol, current_prec, current_assoc);
-    }
-    break;
-
-  case 42:
-#line 252 "parse-gram.y"
-    {
-      symbol_type_set (yyvsp[0].symbol, current_type);
-      symbol_precedence_set (yyvsp[0].symbol, current_prec, current_assoc);
-    }
-    break;
-
-  case 43:
-#line 261 "parse-gram.y"
+#line 260 "parse-gram.y"
     {
        current_type = yyvsp[0].string;
      }
     break;
 
-  case 44:
-#line 265 "parse-gram.y"
+  case 40:
+#line 264 "parse-gram.y"
     {
        symbol_class_set (yyvsp[0].symbol, current_class);
-       symbol_type_set (yyvsp[0].symbol, current_type);
+       symbol_type_set (yyvsp[0].symbol, yylsp[0], current_type);
      }
     break;
 
-  case 45:
-#line 270 "parse-gram.y"
+  case 41:
+#line 269 "parse-gram.y"
     {
       symbol_class_set (yyvsp[-1].symbol, current_class);
-      symbol_type_set (yyvsp[-1].symbol, current_type);
+      symbol_type_set (yyvsp[-1].symbol, yylsp[-1], current_type);
       symbol_user_token_number_set (yyvsp[-1].symbol, yyvsp[0].integer);
     }
     break;
 
-  case 46:
-#line 276 "parse-gram.y"
+  case 42:
+#line 275 "parse-gram.y"
     {
       symbol_class_set (yyvsp[-1].symbol, current_class);
-      symbol_type_set (yyvsp[-1].symbol, current_type);
+      symbol_type_set (yyvsp[-1].symbol, yylsp[-1], current_type);
       symbol_make_alias (yyvsp[-1].symbol, yyvsp[0].symbol);
     }
     break;
 
-  case 47:
-#line 282 "parse-gram.y"
+  case 43:
+#line 281 "parse-gram.y"
     {
       symbol_class_set (yyvsp[-2].symbol, current_class);
-      symbol_type_set (yyvsp[-2].symbol, current_type);
+      symbol_type_set (yyvsp[-2].symbol, yylsp[-2], current_type);
       symbol_user_token_number_set (yyvsp[-2].symbol, yyvsp[-1].integer);
       symbol_make_alias (yyvsp[-2].symbol, yyvsp[0].symbol);
     }
     break;
 
-  case 48:
-#line 293 "parse-gram.y"
+  case 44:
+#line 292 "parse-gram.y"
     {;}
     break;
 
-  case 49:
-#line 295 "parse-gram.y"
+  case 45:
+#line 294 "parse-gram.y"
     {;}
     break;
 
-  case 54:
-#line 317 "parse-gram.y"
+  case 50:
+#line 316 "parse-gram.y"
     { current_lhs = yyvsp[-1].symbol; current_lhs_location = yylsp[-1]; }
     break;
 
-  case 55:
-#line 318 "parse-gram.y"
+  case 51:
+#line 317 "parse-gram.y"
     {;}
     break;
 
-  case 56:
-#line 322 "parse-gram.y"
+  case 52:
+#line 321 "parse-gram.y"
     { grammar_rule_end (yylsp[0]); }
     break;
 
-  case 57:
-#line 323 "parse-gram.y"
+  case 53:
+#line 322 "parse-gram.y"
     { grammar_rule_end (yylsp[0]); }
     break;
 
-  case 58:
-#line 328 "parse-gram.y"
+  case 54:
+#line 327 "parse-gram.y"
     { grammar_rule_begin (current_lhs, current_lhs_location); }
     break;
 
-  case 59:
-#line 330 "parse-gram.y"
+  case 55:
+#line 329 "parse-gram.y"
     { grammar_current_rule_symbol_append (yyvsp[0].symbol, yylsp[0]); }
     break;
 
-  case 60:
-#line 332 "parse-gram.y"
+  case 56:
+#line 331 "parse-gram.y"
     { grammar_current_rule_action_append (yyvsp[0].string, yylsp[0]); }
     break;
 
-  case 61:
-#line 334 "parse-gram.y"
+  case 57:
+#line 333 "parse-gram.y"
     { grammar_current_rule_prec_set (yyvsp[0].symbol); }
     break;
 
-  case 62:
-#line 338 "parse-gram.y"
+  case 58:
+#line 337 "parse-gram.y"
     { yyval.symbol = yyvsp[0].symbol; }
     break;
 
-  case 63:
-#line 339 "parse-gram.y"
+  case 59:
+#line 338 "parse-gram.y"
     { yyval.symbol = yyvsp[0].symbol; }
     break;
 
-  case 64:
-#line 340 "parse-gram.y"
+  case 60:
+#line 339 "parse-gram.y"
     { yyval.symbol = getsym (yyvsp[0].string, yylsp[0]); }
     break;
 
-  case 65:
-#line 345 "parse-gram.y"
+  case 61:
+#line 344 "parse-gram.y"
     { yyval.string = yyvsp[0].string; }
     break;
 
-  case 66:
-#line 351 "parse-gram.y"
+  case 62:
+#line 350 "parse-gram.y"
     {
       yyval.symbol = getsym (yyvsp[0].string, yylsp[0]);
       symbol_class_set (yyval.symbol, token_sym);
     }
     break;
 
-  case 67:
-#line 360 "parse-gram.y"
+  case 63:
+#line 359 "parse-gram.y"
     {
       yyval.string = yyvsp[0].string + 1;
       yyval.string[strlen (yyval.string) - 1] = '\0';
     }
     break;
 
-  case 68:
-#line 368 "parse-gram.y"
+  case 64:
+#line 367 "parse-gram.y"
     {
       yyval.string = xstrdup ("");
     }
     break;
 
-  case 69:
-#line 372 "parse-gram.y"
+  case 65:
+#line 371 "parse-gram.y"
     {
       yyval.string = yyvsp[0].string;
     }
@@ -1533,7 +1519,7 @@ yyreduce:
     }
 
 /* Line 1012 of /usr/local/share/bison/bison.simple.  */
-#line 1537 "parse-gram.c"
+#line 1523 "parse-gram.c"
 
   yyvsp -= yylen;
   yyssp -= yylen;
@@ -1754,7 +1740,7 @@ yyreturn:
   return yyresult;
 }
 
-#line 381 "parse-gram.y"
+#line 380 "parse-gram.y"
 
 /*------------------------------------------------------------------.
 | When debugging the parser, display tokens' locations and values.  |
