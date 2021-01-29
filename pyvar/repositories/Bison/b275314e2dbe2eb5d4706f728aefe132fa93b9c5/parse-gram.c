@@ -57,6 +57,7 @@
 #line 31 "parse-gram.y"
 
 #include "system.h"
+#include "complain.h"
 #include "muscle_tab.h"
 #include "files.h"
 #include "getargs.h"
@@ -224,7 +225,7 @@ braced_code_t current_braced_code = action_braced_code;
 #endif
 
 #ifndef YYSTYPE
-#line 88 "parse-gram.y"
+#line 89 "parse-gram.y"
 typedef union {
   symbol_t *symbol;
   symbol_list_t *list;
@@ -232,8 +233,8 @@ typedef union {
   char *string;
   associativity assoc;
 } yystype;
-/* Line 187 of /home/lrde/prof/akim/src/bison/data/yacc.c.  */
-#line 237 "parse-gram.c"
+/* Line 187 of /usr/local/share/bison/yacc.c.  */
+#line 238 "parse-gram.c"
 # define YYSTYPE yystype
 # define YYSTYPE_IS_TRIVIAL 1
 #endif
@@ -253,8 +254,8 @@ typedef struct yyltype
 /* Copy the second part of user declarations.  */
 
 
-/* Line 207 of /home/lrde/prof/akim/src/bison/data/yacc.c.  */
-#line 258 "parse-gram.c"
+/* Line 207 of /usr/local/share/bison/yacc.c.  */
+#line 259 "parse-gram.c"
 
 #if ! defined (yyoverflow) || YYERROR_VERBOSE
 
@@ -348,16 +349,16 @@ union yyalloc
 /* YYFINAL -- State number of the termination state. */
 #define YYFINAL  3
 #define YYFLAG	 -32768
-#define YYLAST   125
+#define YYLAST   127
 
 /* YYNTOKENS -- Number of terminals. */
 #define YYNTOKENS  45
 /* YYNNTS -- Number of nonterminals. */
 #define YYNNTS  28
 /* YYNRULES -- Number of rules. */
-#define YYNRULES  74
+#define YYNRULES  75
 /* YYNRULES -- Number of states. */
-#define YYNSTATES  106
+#define YYNSTATES  108
 
 /* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
 #define YYUNDEFTOK  2
@@ -411,9 +412,9 @@ static const unsigned char yyprhs[] =
       53,    55,    57,    59,    61,    63,    66,    69,    70,    75,
       76,    81,    82,    86,    87,    91,    95,    99,   101,   103,
      105,   106,   108,   110,   113,   115,   117,   120,   123,   127,
-     129,   132,   134,   137,   139,   142,   143,   149,   151,   155,
-     156,   159,   162,   166,   170,   174,   176,   178,   180,   182,
-     184,   186,   187,   190,   191
+     129,   132,   134,   137,   139,   142,   145,   146,   152,   154,
+     158,   159,   162,   165,   169,   173,   177,   179,   181,   183,
+     185,   187,   189,   190,   193,   194
 };
 
 /* YYRHS -- A `-1'-separated list of the rules' RHS. */
@@ -433,25 +434,25 @@ static const signed char yyrhs[] =
       58,    67,    -1,    35,    -1,    40,    -1,    40,     5,    -1,
       40,    69,    -1,    40,     5,    69,    -1,    59,    -1,    60,
       59,    -1,    62,    -1,    61,    62,    -1,    63,    -1,    49,
-      37,    -1,    -1,    40,    38,    64,    65,    37,    -1,    66,
-      -1,    65,    39,    66,    -1,    -1,    66,    67,    -1,    66,
-      68,    -1,    66,    17,    67,    -1,    66,    18,     5,    -1,
-      66,    19,    35,    -1,    40,    -1,    69,    -1,     4,    -1,
-      44,    -1,     3,    -1,     3,    -1,    -1,    41,    43,    -1,
-      -1,    37,    -1
+      37,    -1,     1,    37,    -1,    -1,    40,    38,    64,    65,
+      37,    -1,    66,    -1,    65,    39,    66,    -1,    -1,    66,
+      67,    -1,    66,    68,    -1,    66,    17,    67,    -1,    66,
+      18,     5,    -1,    66,    19,    35,    -1,    40,    -1,    69,
+      -1,     4,    -1,    44,    -1,     3,    -1,     3,    -1,    -1,
+      41,    43,    -1,    -1,    37,    -1
 };
 
 /* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
 static const unsigned short yyrline[] =
 {
-       0,   158,   158,   171,   173,   176,   178,   179,   180,   181,
-     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
-     192,   193,   194,   197,   199,   200,   204,   211,   210,   221,
-     220,   233,   232,   238,   238,   243,   252,   267,   269,   270,
-     273,   275,   280,   282,   286,   291,   296,   302,   308,   318,
-     321,   330,   332,   338,   340,   344,   343,   348,   350,   353,
-     356,   358,   360,   362,   364,   368,   370,   371,   374,   380,
-     389,   397,   402,   408,   410
+       0,   159,   159,   172,   174,   177,   179,   180,   181,   182,
+     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
+     193,   194,   195,   198,   200,   201,   205,   212,   211,   222,
+     221,   234,   233,   239,   239,   244,   253,   268,   270,   271,
+     274,   276,   281,   283,   287,   292,   297,   303,   309,   319,
+     322,   331,   333,   339,   341,   346,   353,   352,   357,   359,
+     362,   365,   367,   369,   371,   373,   377,   379,   380,   383,
+     389,   398,   406,   411,   417,   419
 };
 #endif
 
@@ -498,9 +499,9 @@ static const unsigned char yyr1[] =
       48,    48,    48,    49,    49,    49,    49,    50,    49,    51,
       49,    53,    52,    54,    52,    52,    55,    56,    56,    56,
       57,    57,    58,    58,    59,    59,    59,    59,    59,    60,
-      60,    61,    61,    62,    62,    64,    63,    65,    65,    66,
-      66,    66,    66,    66,    66,    67,    67,    67,    68,    69,
-      70,    71,    71,    72,    72
+      60,    61,    61,    62,    62,    62,    64,    63,    65,    65,
+      66,    66,    66,    66,    66,    66,    67,    67,    67,    68,
+      69,    70,    71,    71,    72,    72
 };
 
 /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
@@ -511,9 +512,9 @@ static const unsigned char yyr2[] =
        1,     1,     1,     1,     1,     2,     2,     0,     4,     0,
        4,     0,     3,     0,     3,     3,     3,     1,     1,     1,
        0,     1,     1,     2,     1,     1,     2,     2,     3,     1,
-       2,     1,     2,     1,     2,     0,     5,     1,     3,     0,
-       2,     2,     3,     3,     3,     1,     1,     1,     1,     1,
-       1,     0,     2,     0,     1
+       2,     1,     2,     1,     2,     2,     0,     5,     1,     3,
+       0,     2,     2,     3,     3,     3,     1,     1,     1,     1,
+       1,     1,     0,     2,     0,     1
 };
 
 /* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
@@ -524,47 +525,47 @@ static const short yydefact[] =
        3,     0,     0,     0,    33,    31,     0,    27,    29,     0,
       37,    38,    39,     0,     0,    21,    10,     0,     0,     0,
        0,    17,    18,     9,    22,     7,    13,    15,     0,    20,
-       0,     6,    73,     5,    24,    23,    40,     0,     0,     0,
-       0,     0,    26,    11,    69,    67,    65,    25,    66,     0,
-       0,     0,    70,     0,    19,     0,     0,    71,    51,    53,
-      74,     4,    41,     0,    44,    45,    49,    34,    32,    35,
-      42,     0,     0,    16,    12,    14,     8,    55,    54,     0,
-      52,     2,    36,    46,    47,    50,    43,    28,    30,    59,
-      72,    48,     0,    57,    56,    59,     0,     0,     0,    68,
-      60,    61,    58,    62,    63,    64
+       0,     6,    74,     5,    24,    23,    40,     0,     0,     0,
+       0,     0,    26,    11,    70,    68,    66,    25,    67,     0,
+       0,     0,    71,     0,    19,     0,     0,     0,     0,    51,
+      53,    75,     4,    41,     0,    44,    45,    49,    34,    32,
+      35,    42,     0,     0,    16,    12,    14,     8,    55,    56,
+      54,     0,    52,     2,    36,    46,    47,    50,    43,    28,
+      30,    60,    73,    48,     0,    58,    57,    60,     0,     0,
+       0,    69,    61,    62,    59,    63,    64,    65
 };
 
 /* YYPGOTO[NTERM-NUM]. */
 static const short yydefgoto[] =
 {
-      -1,     1,     2,    32,    56,    40,    41,    34,    38,    37,
-      35,    36,    63,    69,    66,    67,    57,    58,    59,    89,
-      92,    93,    70,   101,    48,    53,    81,    61
+      -1,     1,     2,    32,    57,    40,    41,    34,    38,    37,
+      35,    36,    64,    70,    67,    68,    58,    59,    60,    91,
+      94,    95,    71,   103,    48,    53,    83,    62
 };
 
 /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
    STATE-NUM.  */
 static const short yypact[] =
 {
-  -32768,     7,    83,-32768,-32768,-32768,   -23,-32768,-32768,     3,
-  -32768,-32768,-32768,    43,     0,-32768,-32768,    13,    14,    15,
-      51,-32768,-32768,-32768,-32768,-32768,-32768,-32768,    51,-32768,
-      23,-32768,    19,-32768,-32768,-32768,    22,   -29,   -29,     0,
-      17,    18,-32768,-32768,-32768,-32768,-32768,-32768,-32768,    51,
-      51,    51,-32768,    51,-32768,    20,    27,    12,-32768,-32768,
-  -32768,-32768,-32768,     0,-32768,     5,-32768,   -29,   -29,     0,
-  -32768,     0,     0,-32768,-32768,-32768,-32768,-32768,-32768,    28,
-  -32768,-32768,     0,    56,-32768,-32768,-32768,     0,     0,-32768,
-  -32768,-32768,     4,    -2,-32768,-32768,     0,    55,    35,-32768,
-  -32768,-32768,    -2,-32768,-32768,-32768
+  -32768,    35,    85,-32768,-32768,-32768,     2,-32768,-32768,    -5,
+  -32768,-32768,-32768,    31,     0,-32768,-32768,    18,    21,    22,
+      59,-32768,-32768,-32768,-32768,-32768,-32768,-32768,    59,-32768,
+      37,-32768,    26,-32768,-32768,-32768,    29,   -19,   -19,     0,
+      23,    24,-32768,-32768,-32768,-32768,-32768,-32768,-32768,    59,
+      59,    59,-32768,    59,-32768,    28,    33,    32,     1,-32768,
+  -32768,-32768,-32768,-32768,     0,-32768,    17,-32768,   -19,   -19,
+       0,-32768,     0,     0,-32768,-32768,-32768,-32768,-32768,-32768,
+  -32768,    30,-32768,-32768,     0,    63,-32768,-32768,-32768,     0,
+       0,-32768,-32768,-32768,    -8,    15,-32768,-32768,     0,    67,
+      39,-32768,-32768,-32768,    15,-32768,-32768,-32768
 };
 
 /* YYPGOTO[NTERM-NUM].  */
 static const short yypgoto[] =
 {
-  -32768,-32768,-32768,-32768,    70,-32768,-32768,-32768,-32768,-32768,
-  -32768,-32768,-32768,   -58,   -22,    37,-32768,    21,-32768,-32768,
-  -32768,   -19,   -14,-32768,   -56,    16,-32768,-32768
+  -32768,-32768,-32768,-32768,    76,-32768,-32768,-32768,-32768,-32768,
+  -32768,-32768,-32768,   -12,   -45,    41,-32768,    25,-32768,-32768,
+  -32768,   -17,   -14,-32768,   -60,   -23,-32768,-32768
 };
 
 /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
@@ -572,36 +573,36 @@ static const short yypgoto[] =
    number is the opposite.  If zero, do what YYDEFACT says.  */
 static const short yytable[] =
 {
-      47,    44,    45,    44,    45,    82,    64,     3,    44,    84,
-      83,    65,    39,    87,    88,    96,    97,    98,     4,     5,
-       6,     7,     8,     9,    10,    11,    12,    91,    14,     4,
-       5,     6,     7,     8,     9,    10,    11,    12,    46,    14,
-      46,    94,    99,    95,    54,    85,    85,    42,    43,    49,
-      50,    51,    55,    79,    52,    86,    60,    62,    77,    44,
-     104,    71,    72,    55,    78,    73,    74,    75,    86,    76,
-     105,    90,    33,    86,    86,    68,   102,     0,    80,   100,
-       0,     0,   103,     0,     0,     0,     0,     0,   100,     4,
-       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
-       0,     0,     0,    15,    16,    17,    18,    19,    20,    21,
-      22,    23,    24,    25,    26,    27,    28,    29,     0,     0,
-       0,     0,     0,     0,    30,    31
+      47,   -72,    55,    44,    45,    54,    86,     4,     5,     6,
+       7,     8,     9,    10,    11,    12,    65,    14,    44,    45,
+      44,    66,    85,    87,    87,    93,    74,    75,    76,    96,
+      77,    97,    98,    99,   100,     3,    43,    39,    55,    42,
+      46,    56,    81,     4,     5,     6,     7,     8,     9,    10,
+      11,    12,    84,    14,    49,    46,    88,    50,    51,   101,
+      89,    90,    52,    61,    63,    78,    44,    72,    73,    80,
+      88,    79,   106,    92,   107,    88,    88,    56,    33,    69,
+     104,   102,     0,    82,   105,     0,     0,     0,     0,     0,
+     102,     4,     5,     6,     7,     8,     9,    10,    11,    12,
+      13,    14,     0,     0,     0,    15,    16,    17,    18,    19,
+      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
+       0,     0,     0,     0,     0,     0,    30,    31
 };
 
 static const short yycheck[] =
 {
-      14,     3,     4,     3,     4,    63,    35,     0,     3,    65,
-       5,    40,    35,    71,    72,    17,    18,    19,     6,     7,
-       8,     9,    10,    11,    12,    13,    14,    83,    16,     6,
-       7,     8,     9,    10,    11,    12,    13,    14,    40,    16,
-      40,    37,    44,    39,    28,    67,    68,    44,     5,    36,
-      36,    36,    40,    41,     3,    69,    37,    35,    38,     3,
-       5,    44,    44,    40,    37,    49,    50,    51,    82,    53,
-      35,    43,     2,    87,    88,    38,    95,    -1,    57,    93,
-      -1,    -1,    96,    -1,    -1,    -1,    -1,    -1,   102,     6,
-       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
-      -1,    -1,    -1,    20,    21,    22,    23,    24,    25,    26,
-      27,    28,    29,    30,    31,    32,    33,    34,    -1,    -1,
-      -1,    -1,    -1,    -1,    41,    42
+      14,     0,     1,     3,     4,    28,    66,     6,     7,     8,
+       9,    10,    11,    12,    13,    14,    35,    16,     3,     4,
+       3,    40,     5,    68,    69,    85,    49,    50,    51,    37,
+      53,    39,    17,    18,    19,     0,     5,    35,     1,    44,
+      40,    40,    41,     6,     7,     8,     9,    10,    11,    12,
+      13,    14,    64,    16,    36,    40,    70,    36,    36,    44,
+      72,    73,     3,    37,    35,    37,     3,    44,    44,    37,
+      84,    38,     5,    43,    35,    89,    90,    40,     2,    38,
+      97,    95,    -1,    58,    98,    -1,    -1,    -1,    -1,    -1,
+     104,     6,     7,     8,     9,    10,    11,    12,    13,    14,
+      15,    16,    -1,    -1,    -1,    20,    21,    22,    23,    24,
+      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
+      -1,    -1,    -1,    -1,    -1,    -1,    41,    42
 };
 
 /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
@@ -613,12 +614,12 @@ static const unsigned char yystos[] =
       25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
       41,    42,    48,    49,    52,    55,    56,    54,    53,    35,
       50,    51,    44,     5,     3,     4,    40,    67,    69,    36,
-      36,    36,     3,    70,    70,    40,    49,    61,    62,    63,
-      37,    72,    35,    57,    35,    40,    59,    60,    60,    58,
-      67,    44,    44,    70,    70,    70,    70,    38,    37,    41,
-      62,    71,    58,     5,    69,    59,    67,    58,    58,    64,
-      43,    69,    65,    66,    37,    39,    17,    18,    19,    44,
-      67,    68,    66,    67,     5,    35
+      36,    36,     3,    70,    70,     1,    40,    49,    61,    62,
+      63,    37,    72,    35,    57,    35,    40,    59,    60,    60,
+      58,    67,    44,    44,    70,    70,    70,    70,    37,    38,
+      37,    41,    62,    71,    58,     5,    69,    59,    67,    58,
+      58,    64,    43,    69,    65,    66,    37,    39,    17,    18,
+      19,    44,    67,    68,    66,    67,     5,    35
 };
 
 #if ! defined (YYSIZE_T) && defined (__SIZE_TYPE__)
@@ -1134,7 +1135,7 @@ yyreduce:
   switch (yyn)
     {
         case 2:
-#line 160 "parse-gram.y"
+#line 161 "parse-gram.y"
     {
       yycontrol->errcode = 0;
       epilogue_set (yyvsp[0].string, yylsp[0]);
@@ -1142,99 +1143,99 @@ yyreduce:
     break;
 
   case 6:
-#line 178 "parse-gram.y"
+#line 179 "parse-gram.y"
     { prologue_augment (yyvsp[0].string, yylsp[0]); }
     break;
 
   case 7:
-#line 179 "parse-gram.y"
+#line 180 "parse-gram.y"
     { debug_flag = 1; }
     break;
 
   case 8:
-#line 180 "parse-gram.y"
+#line 181 "parse-gram.y"
     { muscle_insert (yyvsp[-1].string, yyvsp[0].string); }
     break;
 
   case 9:
-#line 181 "parse-gram.y"
+#line 182 "parse-gram.y"
     { defines_flag = 1; }
     break;
 
   case 10:
-#line 182 "parse-gram.y"
+#line 183 "parse-gram.y"
     { error_verbose = 1; }
     break;
 
   case 11:
-#line 183 "parse-gram.y"
+#line 184 "parse-gram.y"
     { expected_conflicts = yyvsp[0].integer; }
     break;
 
   case 12:
-#line 184 "parse-gram.y"
+#line 185 "parse-gram.y"
     { spec_file_prefix = yyvsp[0].string; }
     break;
 
   case 13:
-#line 185 "parse-gram.y"
+#line 186 "parse-gram.y"
     { locations_flag = 1; }
     break;
 
   case 14:
-#line 186 "parse-gram.y"
+#line 187 "parse-gram.y"
     { spec_name_prefix = yyvsp[0].string; }
     break;
 
   case 15:
-#line 187 "parse-gram.y"
+#line 188 "parse-gram.y"
     { no_lines_flag = 1; }
     break;
 
   case 16:
-#line 188 "parse-gram.y"
+#line 189 "parse-gram.y"
     { spec_outfile = yyvsp[0].string; }
     break;
 
   case 17:
-#line 189 "parse-gram.y"
+#line 190 "parse-gram.y"
     { pure_parser = 1; }
     break;
 
   case 18:
-#line 190 "parse-gram.y"
+#line 191 "parse-gram.y"
     { glr_parser = 1; }
     break;
 
   case 19:
-#line 191 "parse-gram.y"
+#line 192 "parse-gram.y"
     { skeleton = yyvsp[0].string; }
     break;
 
   case 20:
-#line 192 "parse-gram.y"
+#line 193 "parse-gram.y"
     { token_table_flag = 1; }
     break;
 
   case 21:
-#line 193 "parse-gram.y"
+#line 194 "parse-gram.y"
     { report_flag = 1; }
     break;
 
   case 22:
-#line 194 "parse-gram.y"
+#line 195 "parse-gram.y"
     { yacc_flag = 1; }
     break;
 
   case 25:
-#line 201 "parse-gram.y"
+#line 202 "parse-gram.y"
     {
       grammar_start_symbol_set (yyvsp[0].symbol, yylsp[0]);
     }
     break;
 
   case 26:
-#line 205 "parse-gram.y"
+#line 206 "parse-gram.y"
     {
       typed = 1;
       MUSCLE_INSERT_INT ("stype_line", yylsp[0].first_line);
@@ -1243,12 +1244,12 @@ yyreduce:
     break;
 
   case 27:
-#line 211 "parse-gram.y"
+#line 212 "parse-gram.y"
     { current_braced_code = destructor_braced_code; }
     break;
 
   case 28:
-#line 213 "parse-gram.y"
+#line 214 "parse-gram.y"
     {
       symbol_list_t *list;
       for (list = yyvsp[0].list; list; list = list->next)
@@ -1259,12 +1260,12 @@ yyreduce:
     break;
 
   case 29:
-#line 221 "parse-gram.y"
+#line 222 "parse-gram.y"
     { current_braced_code = printer_braced_code; }
     break;
 
   case 30:
-#line 223 "parse-gram.y"
+#line 224 "parse-gram.y"
     {
       symbol_list_t *list;
       for (list = yyvsp[0].list; list; list = list->next)
@@ -1275,12 +1276,12 @@ yyreduce:
     break;
 
   case 31:
-#line 233 "parse-gram.y"
+#line 234 "parse-gram.y"
     { current_class = nterm_sym; }
     break;
 
   case 32:
-#line 234 "parse-gram.y"
+#line 235 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
@@ -1288,12 +1289,12 @@ yyreduce:
     break;
 
   case 33:
-#line 238 "parse-gram.y"
+#line 239 "parse-gram.y"
     { current_class = token_sym; }
     break;
 
   case 34:
-#line 239 "parse-gram.y"
+#line 240 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
@@ -1301,7 +1302,7 @@ yyreduce:
     break;
 
   case 35:
-#line 244 "parse-gram.y"
+#line 245 "parse-gram.y"
     {
       symbol_list_t *list;
       for (list = yyvsp[0].list; list; list = list->next)
@@ -1311,7 +1312,7 @@ yyreduce:
     break;
 
   case 36:
-#line 254 "parse-gram.y"
+#line 255 "parse-gram.y"
     {
       symbol_list_t *list;
       ++current_prec;
@@ -1326,49 +1327,49 @@ yyreduce:
     break;
 
   case 37:
-#line 268 "parse-gram.y"
+#line 269 "parse-gram.y"
     { yyval.assoc = left_assoc; }
     break;
 
   case 38:
-#line 269 "parse-gram.y"
+#line 270 "parse-gram.y"
     { yyval.assoc = right_assoc; }
     break;
 
   case 39:
-#line 270 "parse-gram.y"
+#line 271 "parse-gram.y"
     { yyval.assoc = non_assoc; }
     break;
 
   case 40:
-#line 274 "parse-gram.y"
+#line 275 "parse-gram.y"
     { current_type = NULL;}
     break;
 
   case 41:
-#line 275 "parse-gram.y"
+#line 276 "parse-gram.y"
     { current_type = yyvsp[0].string; }
     break;
 
   case 42:
-#line 281 "parse-gram.y"
+#line 282 "parse-gram.y"
     { yyval.list = symbol_list_new (yyvsp[0].symbol, yylsp[0]); }
     break;
 
   case 43:
-#line 282 "parse-gram.y"
+#line 283 "parse-gram.y"
     { yyval.list = symbol_list_prepend (yyvsp[-1].list, yyvsp[0].symbol, yylsp[0]); }
     break;
 
   case 44:
-#line 288 "parse-gram.y"
+#line 289 "parse-gram.y"
     {
        current_type = yyvsp[0].string;
      }
     break;
 
   case 45:
-#line 292 "parse-gram.y"
+#line 293 "parse-gram.y"
     {
        symbol_class_set (yyvsp[0].symbol, current_class, yylsp[0]);
        symbol_type_set (yyvsp[0].symbol, current_type, yylsp[0]);
@@ -1376,7 +1377,7 @@ yyreduce:
     break;
 
   case 46:
-#line 297 "parse-gram.y"
+#line 298 "parse-gram.y"
     {
       symbol_class_set (yyvsp[-1].symbol, current_class, yylsp[-1]);
       symbol_type_set (yyvsp[-1].symbol, current_type, yylsp[-1]);
@@ -1385,7 +1386,7 @@ yyreduce:
     break;
 
   case 47:
-#line 303 "parse-gram.y"
+#line 304 "parse-gram.y"
     {
       symbol_class_set (yyvsp[-1].symbol, current_class, yylsp[-1]);
       symbol_type_set (yyvsp[-1].symbol, current_type, yylsp[-1]);
@@ -1394,7 +1395,7 @@ yyreduce:
     break;
 
   case 48:
-#line 309 "parse-gram.y"
+#line 310 "parse-gram.y"
     {
       symbol_class_set (yyvsp[-2].symbol, current_class, yylsp[-2]);
       symbol_type_set (yyvsp[-2].symbol, current_type, yylsp[-2]);
@@ -1404,110 +1405,125 @@ yyreduce:
     break;
 
   case 49:
-#line 320 "parse-gram.y"
+#line 321 "parse-gram.y"
     {;}
     break;
 
   case 50:
-#line 322 "parse-gram.y"
+#line 323 "parse-gram.y"
     {;}
     break;
 
+  case 54:
+#line 342 "parse-gram.y"
+    {
+      if (yacc_flag)
+	complain_at (yyloc, _("POSIX forbids declarations in the grammar"));
+    }
+    break;
+
   case 55:
-#line 344 "parse-gram.y"
-    { current_lhs = yyvsp[-1].symbol; current_lhs_location = yylsp[-1]; }
+#line 347 "parse-gram.y"
+    {
+      yyerrok;
+    }
     break;
 
   case 56:
-#line 345 "parse-gram.y"
-    {;}
+#line 353 "parse-gram.y"
+    { current_lhs = yyvsp[-1].symbol; current_lhs_location = yylsp[-1]; }
     break;
 
   case 57:
-#line 349 "parse-gram.y"
-    { grammar_rule_end (yylsp[0]); }
+#line 354 "parse-gram.y"
+    {;}
     break;
 
   case 58:
-#line 350 "parse-gram.y"
+#line 358 "parse-gram.y"
     { grammar_rule_end (yylsp[0]); }
     break;
 
   case 59:
-#line 355 "parse-gram.y"
-    { grammar_rule_begin (current_lhs, current_lhs_location); }
+#line 359 "parse-gram.y"
+    { grammar_rule_end (yylsp[0]); }
     break;
 
   case 60:
-#line 357 "parse-gram.y"
-    { grammar_current_rule_symbol_append (yyvsp[0].symbol, yylsp[0]); }
+#line 364 "parse-gram.y"
+    { grammar_rule_begin (current_lhs, current_lhs_location); }
     break;
 
   case 61:
-#line 359 "parse-gram.y"
-    { grammar_current_rule_action_append (yyvsp[0].string, yylsp[0]); }
+#line 366 "parse-gram.y"
+    { grammar_current_rule_symbol_append (yyvsp[0].symbol, yylsp[0]); }
     break;
 
   case 62:
-#line 361 "parse-gram.y"
-    { grammar_current_rule_prec_set (yyvsp[0].symbol, yylsp[0]); }
+#line 368 "parse-gram.y"
+    { grammar_current_rule_action_append (yyvsp[0].string, yylsp[0]); }
     break;
 
   case 63:
-#line 363 "parse-gram.y"
-    { grammar_current_rule_dprec_set (yyvsp[0].integer, yylsp[0]); }
+#line 370 "parse-gram.y"
+    { grammar_current_rule_prec_set (yyvsp[0].symbol, yylsp[0]); }
     break;
 
   case 64:
-#line 365 "parse-gram.y"
-    { grammar_current_rule_merge_set (yyvsp[0].string, yylsp[0]); }
+#line 372 "parse-gram.y"
+    { grammar_current_rule_dprec_set (yyvsp[0].integer, yylsp[0]); }
     break;
 
   case 65:
-#line 369 "parse-gram.y"
-    { yyval.symbol = yyvsp[0].symbol; }
+#line 374 "parse-gram.y"
+    { grammar_current_rule_merge_set (yyvsp[0].string, yylsp[0]); }
     break;
 
   case 66:
-#line 370 "parse-gram.y"
+#line 378 "parse-gram.y"
     { yyval.symbol = yyvsp[0].symbol; }
     break;
 
   case 67:
-#line 371 "parse-gram.y"
-    { yyval.symbol = symbol_get (yyvsp[0].string, yylsp[0]); }
+#line 379 "parse-gram.y"
+    { yyval.symbol = yyvsp[0].symbol; }
     break;
 
   case 68:
-#line 376 "parse-gram.y"
-    { yyval.string = yyvsp[0].string; }
+#line 380 "parse-gram.y"
+    { yyval.symbol = symbol_get (yyvsp[0].string, yylsp[0]); }
     break;
 
   case 69:
-#line 382 "parse-gram.y"
+#line 385 "parse-gram.y"
+    { yyval.string = yyvsp[0].string; }
+    break;
+
+  case 70:
+#line 391 "parse-gram.y"
     {
       yyval.symbol = symbol_get (yyvsp[0].string, yylsp[0]);
       symbol_class_set (yyval.symbol, token_sym, yylsp[0]);
     }
     break;
 
-  case 70:
-#line 391 "parse-gram.y"
+  case 71:
+#line 400 "parse-gram.y"
     {
       yyval.string = yyvsp[0].string + 1;
       yyval.string[strlen (yyval.string) - 1] = '\0';
     }
     break;
 
-  case 71:
-#line 399 "parse-gram.y"
+  case 72:
+#line 408 "parse-gram.y"
     {
       yyval.string = xstrdup ("");
     }
     break;
 
-  case 72:
-#line 403 "parse-gram.y"
+  case 73:
+#line 412 "parse-gram.y"
     {
       yyval.string = yyvsp[0].string;
     }
@@ -1516,8 +1532,8 @@ yyreduce:
 
     }
 
-/* Line 955 of /home/lrde/prof/akim/src/bison/data/yacc.c.  */
-#line 1521 "parse-gram.c"
+/* Line 955 of /usr/local/share/bison/yacc.c.  */
+#line 1537 "parse-gram.c"
 
   yyvsp -= yylen;
   yyssp -= yylen;
@@ -1788,7 +1804,7 @@ yysymprint (FILE* yyout, int yytype,
 }
 #endif /* YYDEBUG. */
 
-#line 412 "parse-gram.y"
+#line 421 "parse-gram.y"
 
 /*------------------------------------------------------------------.
 | When debugging the parser, display tokens' locations and values.  |
@@ -1833,7 +1849,6 @@ void
 gram_error (gram_control_t *control ATTRIBUTE_UNUSED,
 	    location_t *yylloc, const char *msg)
 {
-  LOCATION_PRINT (stderr, *yylloc);
-  fprintf (stderr, ": %s\n", msg);
+  complain_at (*yylloc, "%s", msg);
 }
 
