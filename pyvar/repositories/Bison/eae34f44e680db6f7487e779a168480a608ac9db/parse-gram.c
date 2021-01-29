@@ -254,16 +254,16 @@ typedef struct YYLTYPE
 
 /* The parser invokes alloca or malloc; define the necessary symbols.  */
 
-# if YYSTACK_USE_ALLOCA
-#  define YYSTACK_ALLOC alloca
+# ifdef YYSTACK_USE_ALLOCA
+#  if YYSTACK_USE_ALLOCA
+#   define YYSTACK_ALLOC alloca
+#  endif
 # else
-#  ifndef YYSTACK_USE_ALLOCA
-#   if defined (alloca) || defined (_ALLOCA_H)
-#    define YYSTACK_ALLOC alloca
-#   else
-#    ifdef __GNUC__
-#     define YYSTACK_ALLOC __builtin_alloca
-#    endif
+#  if defined (alloca) || defined (_ALLOCA_H)
+#   define YYSTACK_ALLOC alloca
+#  else
+#   ifdef __GNUC__
+#    define YYSTACK_ALLOC __builtin_alloca
 #   endif
 #  endif
 # endif
@@ -348,7 +348,7 @@ union yyalloc
 /* YYFINAL -- State number of the termination state. */
 #define YYFINAL  3
 /* YYLAST -- Last index in YYTABLE.  */
-#define YYLAST   147
+#define YYLAST   148
 
 /* YYNTOKENS -- Number of terminals. */
 #define YYNTOKENS  47
@@ -357,7 +357,7 @@ union yyalloc
 /* YYNRULES -- Number of rules. */
 #define YYNRULES  75
 /* YYNRULES -- Number of states. */
-#define YYNSTATES  102
+#define YYNSTATES  103
 
 /* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
 #define YYUNDEFTOK  2
@@ -412,9 +412,9 @@ static const unsigned char yyprhs[] =
       51,    53,    55,    58,    60,    62,    64,    66,    68,    70,
       73,    75,    78,    81,    82,    86,    87,    91,    95,    99,
      101,   103,   105,   106,   108,   110,   113,   115,   117,   120,
-     123,   127,   129,   132,   134,   137,   139,   141,   144,   146,
-     147,   151,   153,   157,   158,   161,   164,   168,   172,   176,
-     178,   180,   182,   184,   186,   187
+     123,   127,   129,   132,   134,   137,   139,   142,   145,   146,
+     150,   152,   156,   159,   160,   163,   166,   170,   174,   178,
+     180,   182,   184,   186,   188,   189
 };
 
 /* YYRHS -- A `-1'-separated list of the rules' RHS. */
@@ -434,11 +434,12 @@ static const yysigned_char yyrhs[] =
       58,    67,    -1,    37,    -1,    41,    -1,    41,     4,    -1,
       41,    69,    -1,    41,     4,    69,    -1,    59,    -1,    60,
       59,    -1,    62,    -1,    61,    62,    -1,    63,    -1,    51,
-      -1,     1,    39,    -1,    39,    -1,    -1,    42,    64,    65,
-      -1,    66,    -1,    65,    40,    66,    -1,    -1,    66,    67,
-      -1,    66,    68,    -1,    66,    14,    67,    -1,    66,    15,
-       4,    -1,    66,    16,    37,    -1,    41,    -1,    69,    -1,
-      46,    -1,     3,    -1,     3,    -1,    -1,    43,    45,    -1
+      39,    -1,     1,    39,    -1,    -1,    42,    64,    65,    -1,
+      66,    -1,    65,    40,    66,    -1,    65,    39,    -1,    -1,
+      66,    67,    -1,    66,    68,    -1,    66,    14,    67,    -1,
+      66,    15,     4,    -1,    66,    16,    37,    -1,    41,    -1,
+      69,    -1,    46,    -1,     3,    -1,     3,    -1,    -1,    43,
+      45,    -1
 };
 
 /* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
@@ -449,8 +450,8 @@ static const unsigned short yyrline[] =
      192,   193,   194,   195,   196,   197,   198,   202,   203,   204,
      208,   214,   221,   231,   231,   236,   236,   241,   251,   266,
      267,   268,   272,   273,   279,   280,   285,   289,   294,   300,
-     306,   317,   318,   327,   328,   334,   335,   340,   344,   348,
-     348,   352,   353,   358,   359,   361,   363,   365,   367,   372,
+     306,   317,   318,   327,   328,   334,   335,   340,   347,   347,
+     351,   352,   353,   358,   359,   361,   363,   365,   367,   372,
      373,   377,   383,   392,   399,   401
 };
 #endif
@@ -460,22 +461,22 @@ static const unsigned short yyrline[] =
    First, the terminals, then, starting at YYNTOKENS, nonterminals. */
 static const char *const yytname[] =
 {
-  "\"end of file\"", "error", "$undefined", "\"string\"", "\"integer\"", 
-  "\"%token\"", "\"%nterm\"", "\"%type\"", "\"%destructor {...}\"", 
-  "\"%printer {...}\"", "\"%union {...}\"", "\"%left\"", "\"%right\"", 
-  "\"%nonassoc\"", "\"%prec\"", "\"%dprec\"", "\"%merge\"", "\"%debug\"", 
-  "\"%define\"", "\"%defines\"", "\"%error-verbose\"", "\"%expect\"", 
-  "\"%file-prefix\"", "\"%glr-parser\"", "\"%lex-param {...}\"", 
-  "\"%locations\"", "\"%name-prefix\"", "\"%no-lines\"", 
-  "\"%nondeterministic-parser\"", "\"%output\"", "\"%parse-param {...}\"", 
-  "\"%pure-parser\"", "\"%skeleton\"", "\"%start\"", "\"%token-table\"", 
-  "\"%verbose\"", "\"%yacc\"", "\"type\"", "\"=\"", "\";\"", "\"|\"", 
-  "\"identifier\"", "\"identifier:\"", "\"%%\"", "\"%{...%}\"", 
-  "\"epilogue\"", "\"{...}\"", "$accept", "input", "declarations", 
-  "declaration", "grammar_declaration", "symbol_declaration", "@1", "@2", 
-  "precedence_declaration", "precedence_declarator", "type.opt", 
-  "symbols.1", "symbol_def", "symbol_defs.1", "grammar", 
-  "rules_or_grammar_declaration", "rules", "@3", "rhses.1", "rhs", 
+  "\"end of file\"", "error", "$undefined", "\"string\"", "\"integer\"",
+  "\"%token\"", "\"%nterm\"", "\"%type\"", "\"%destructor {...}\"",
+  "\"%printer {...}\"", "\"%union {...}\"", "\"%left\"", "\"%right\"",
+  "\"%nonassoc\"", "\"%prec\"", "\"%dprec\"", "\"%merge\"", "\"%debug\"",
+  "\"%define\"", "\"%defines\"", "\"%error-verbose\"", "\"%expect\"",
+  "\"%file-prefix\"", "\"%glr-parser\"", "\"%lex-param {...}\"",
+  "\"%locations\"", "\"%name-prefix\"", "\"%no-lines\"",
+  "\"%nondeterministic-parser\"", "\"%output\"", "\"%parse-param {...}\"",
+  "\"%pure-parser\"", "\"%skeleton\"", "\"%start\"", "\"%token-table\"",
+  "\"%verbose\"", "\"%yacc\"", "\"type\"", "\"=\"", "\";\"", "\"|\"",
+  "\"identifier\"", "\"identifier:\"", "\"%%\"", "\"%{...%}\"",
+  "\"epilogue\"", "\"{...}\"", "$accept", "input", "declarations",
+  "declaration", "grammar_declaration", "symbol_declaration", "@1", "@2",
+  "precedence_declaration", "precedence_declarator", "type.opt",
+  "symbols.1", "symbol_def", "symbol_defs.1", "grammar",
+  "rules_or_grammar_declaration", "rules", "@3", "rhses.1", "rhs",
   "symbol", "action", "string_as_id", "string_content", "epilogue.opt", 0
 };
 #endif
@@ -501,8 +502,8 @@ static const unsigned char yyr1[] =
       50,    50,    50,    50,    50,    50,    50,    51,    51,    51,
       51,    51,    51,    53,    52,    54,    52,    52,    55,    56,
       56,    56,    57,    57,    58,    58,    59,    59,    59,    59,
-      59,    60,    60,    61,    61,    62,    62,    62,    62,    64,
-      63,    65,    65,    66,    66,    66,    66,    66,    66,    67,
+      59,    60,    60,    61,    61,    62,    62,    62,    64,    63,
+      65,    65,    65,    66,    66,    66,    66,    66,    66,    67,
       67,    68,    69,    70,    71,    71
 };
 
@@ -514,8 +515,8 @@ static const unsigned char yyr2[] =
        1,     1,     2,     1,     1,     1,     1,     1,     1,     2,
        1,     2,     2,     0,     3,     0,     3,     3,     3,     1,
        1,     1,     0,     1,     1,     2,     1,     1,     2,     2,
-       3,     1,     2,     1,     2,     1,     1,     2,     1,     0,
-       3,     1,     3,     0,     2,     2,     3,     3,     3,     1,
+       3,     1,     2,     1,     2,     1,     2,     2,     0,     3,
+       1,     3,     2,     0,     2,     2,     3,     3,     3,     1,
        1,     1,     1,     1,     0,     2
 };
 
@@ -530,45 +531,45 @@ static const unsigned char yydefact[] =
       23,    24,    25,    26,     0,     6,     4,     5,    28,    27,
       42,     0,     0,     0,    72,    69,    31,    44,    70,    32,
       73,     0,    11,     0,     0,     0,    22,    29,     0,    58,
-      59,    56,     0,    53,    55,    43,     0,    46,    47,    51,
-      36,    34,    37,    45,     8,    12,    16,    19,    57,    63,
-       0,    54,     2,    38,    48,    49,    52,    60,    61,    75,
-      50,    63,     0,     0,     0,    71,    64,    65,    62,    66,
-      67,    68
+       0,     0,    53,    55,    43,     0,    46,    47,    51,    36,
+      34,    37,    45,     8,    12,    16,    19,    57,    63,    56,
+       0,    54,     2,    38,    48,    49,    52,    59,    60,    75,
+      50,    62,    63,     0,     0,     0,    71,    64,    65,    61,
+      66,    67,    68
 };
 
 /* YYDEFGOTO[NTERM-NUM]. */
 static const yysigned_char yydefgoto[] =
 {
-      -1,     1,     2,    36,    61,    38,    42,    41,    39,    40,
-      66,    46,    69,    70,    62,    63,    64,    79,    87,    88,
-      47,    97,    48,    51,    82
+      -1,     1,     2,    36,    60,    38,    42,    41,    39,    40,
+      65,    46,    68,    69,    61,    62,    63,    78,    87,    88,
+      47,    98,    48,    51,    82
 };
 
 /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
    STATE-NUM.  */
-#define YYPACT_NINF -65
+#define YYPACT_NINF -64
 static const yysigned_char yypact[] =
 {
-     -65,    27,   103,   -65,   -65,   -65,   -15,    -2,    -2,   -65,
-     -65,   -65,   -65,   -65,    25,   -65,   -65,    28,    -5,   -65,
-     -65,   -65,    -3,   -65,   -65,     0,   -65,   -65,    25,    -2,
-     -65,   -65,   -65,   -65,    65,   -65,   -65,   -65,   -65,   -65,
-       4,   -18,   -18,    -2,   -65,   -65,    -2,   -65,   -65,    -2,
-     -65,    25,   -65,    25,    25,    25,   -65,   -65,     1,   -65,
-     -65,   -65,     3,   -65,   -65,   -65,    -2,   -65,    22,   -65,
-     -18,   -18,    -2,   -65,   -65,   -65,   -65,   -65,   -65,   -65,
-     -11,   -65,   -65,    -2,    41,   -65,   -65,     8,    15,   -65,
-     -65,   -65,    -2,    48,    16,   -65,   -65,   -65,    15,   -65,
-     -65,   -65
+     -64,    32,   104,   -64,   -64,   -64,   -21,    16,    16,   -64,
+     -64,   -64,   -64,   -64,    30,   -64,   -64,    33,    -4,   -64,
+     -64,   -64,     0,   -64,   -64,     1,   -64,   -64,    30,    16,
+     -64,   -64,   -64,   -64,    66,   -64,   -64,   -64,   -64,   -64,
+       3,   -15,   -15,    16,   -64,   -64,    16,   -64,   -64,    16,
+     -64,    30,   -64,    30,    30,    30,   -64,   -64,     4,   -64,
+       8,     2,   -64,   -64,   -64,    16,   -64,    21,   -64,   -15,
+     -15,    16,   -64,   -64,   -64,   -64,   -64,   -64,   -64,   -64,
+       6,   -64,   -64,    16,    38,   -64,   -64,   -34,    15,   -64,
+     -64,   -64,   -64,    16,    48,    18,   -64,   -64,   -64,    15,
+     -64,   -64,   -64
 };
 
 /* YYPGOTO[NTERM-NUM].  */
 static const yysigned_char yypgoto[] =
 {
-     -65,   -65,   -65,   -65,    53,   -65,   -65,   -65,   -65,   -65,
-     -65,    -6,   -64,    20,   -65,     2,   -65,   -65,   -65,   -34,
-     -29,   -65,   -63,    -4,   -65
+     -64,   -64,   -64,   -64,    51,   -64,   -64,   -64,   -64,   -64,
+     -64,    -7,   -42,    20,   -64,    -1,   -64,   -64,   -64,   -27,
+     -29,   -64,   -63,    -5,   -64
 };
 
 /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
@@ -578,40 +579,40 @@ static const yysigned_char yypgoto[] =
 #define YYTABLE_NINF -75
 static const yysigned_char yytable[] =
 {
-      57,    44,    49,   -74,    58,    85,    86,    86,     4,     5,
-       6,     7,     8,     9,    10,    11,    12,    73,    44,    67,
-      73,    90,    43,    68,    56,    44,    84,     3,    50,    92,
-      93,    94,    52,    53,    89,    54,    29,    72,    55,    45,
-      78,    65,    59,    73,    44,    60,    80,    74,    91,    75,
-      76,    77,   100,   101,    73,    37,    45,    98,     0,    96,
-      83,    95,    71,    99,    81,     0,    58,     0,     0,    96,
-       4,     5,     6,     7,     8,     9,    10,    11,    12,     0,
+      57,    49,   -74,    58,    85,    91,    92,     4,     5,     6,
+       7,     8,     9,    10,    11,    12,    43,    72,    44,    44,
+      72,    90,    66,    56,    44,    84,    67,    86,    86,    93,
+      94,    95,     3,    50,    53,    29,    71,    52,    54,    55,
+      64,    44,    72,    77,    59,    80,    73,    79,    74,    75,
+      76,    89,   101,    37,    72,   102,    45,    45,    83,    97,
+      81,    96,    70,     0,   100,    99,     0,    58,     0,     0,
+      97,     4,     5,     6,     7,     8,     9,    10,    11,    12,
        0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
-       0,     0,     0,     0,     0,     0,     0,     0,    29,     0,
-       0,     0,     0,     0,    59,     0,     0,    60,     4,     5,
-       6,     7,     8,     9,    10,    11,    12,     0,     0,     0,
-      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
-      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
-       0,     0,    33,     0,     0,     0,    34,    35
+       0,     0,     0,     0,     0,     0,     0,     0,     0,    29,
+       0,     0,     0,     0,     0,     0,     0,     0,    59,     4,
+       5,     6,     7,     8,     9,    10,    11,    12,     0,     0,
+       0,    13,    14,    15,    16,    17,    18,    19,    20,    21,
+      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
+      32,     0,     0,    33,     0,     0,     0,    34,    35
 };
 
 static const yysigned_char yycheck[] =
 {
-      29,     3,     8,     0,     1,    68,    70,    71,     5,     6,
-       7,     8,     9,    10,    11,    12,    13,    46,     3,    37,
-      49,    84,    37,    41,    28,     3,     4,     0,     3,    14,
-      15,    16,     4,    38,    45,    38,    33,    43,    38,    41,
-      39,    37,    39,    72,     3,    42,    43,    51,    40,    53,
-      54,    55,     4,    37,    83,     2,    41,    91,    -1,    88,
-      66,    46,    42,    92,    62,    -1,     1,    -1,    -1,    98,
-       5,     6,     7,     8,     9,    10,    11,    12,    13,    -1,
+      29,     8,     0,     1,    67,    39,    40,     5,     6,     7,
+       8,     9,    10,    11,    12,    13,    37,    46,     3,     3,
+      49,    84,    37,    28,     3,     4,    41,    69,    70,    14,
+      15,    16,     0,     3,    38,    33,    43,     4,    38,    38,
+      37,     3,    71,    39,    42,    43,    51,    39,    53,    54,
+      55,    45,     4,     2,    83,    37,    41,    41,    65,    88,
+      61,    46,    42,    -1,    93,    92,    -1,     1,    -1,    -1,
+      99,     5,     6,     7,     8,     9,    10,    11,    12,    13,
       -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
-      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,    -1,
-      -1,    -1,    -1,    -1,    39,    -1,    -1,    42,     5,     6,
-       7,     8,     9,    10,    11,    12,    13,    -1,    -1,    -1,
-      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
-      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
-      -1,    -1,    39,    -1,    -1,    -1,    43,    44
+      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,
+      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,     5,
+       6,     7,     8,     9,    10,    11,    12,    13,    -1,    -1,
+      -1,    17,    18,    19,    20,    21,    22,    23,    24,    25,
+      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
+      36,    -1,    -1,    39,    -1,    -1,    -1,    43,    44
 };
 
 /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
@@ -623,12 +624,12 @@ static const unsigned char yystos[] =
       24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
       34,    35,    36,    39,    43,    44,    50,    51,    52,    55,
       56,    54,    53,    37,     3,    41,    58,    67,    69,    58,
-       3,    70,     4,    38,    38,    38,    70,    67,     1,    39,
-      42,    51,    61,    62,    63,    37,    57,    37,    41,    59,
-      60,    60,    58,    67,    70,    70,    70,    70,    39,    64,
+       3,    70,     4,    38,    38,    38,    70,    67,     1,    42,
+      51,    61,    62,    63,    37,    57,    37,    41,    59,    60,
+      60,    58,    67,    70,    70,    70,    70,    39,    64,    39,
       43,    62,    71,    58,     4,    69,    59,    65,    66,    45,
-      69,    40,    14,    15,    16,    46,    67,    68,    66,    67,
-       4,    37
+      69,    39,    40,    14,    15,    16,    46,    67,    68,    66,
+      67,     4,    37
 };
 
 #if ! defined (YYSIZE_T) && defined (__SIZE_TYPE__)
@@ -822,7 +823,7 @@ int yydebug;
    SIZE_MAX < YYSTACK_BYTES (YYMAXDEPTH)
    evaluated with infinite-precision integer arithmetic.  */
 
-#if YYMAXDEPTH == 0
+#if defined (YYMAXDEPTH) && YYMAXDEPTH == 0
 # undef YYMAXDEPTH
 #endif
 
@@ -1536,18 +1537,18 @@ yyreduce:
     }
     break;
 
-  case 59:
-#line 348 "parse-gram.y"
+  case 58:
+#line 347 "parse-gram.y"
     { current_lhs = yyvsp[0].symbol; current_lhs_location = yylsp[0]; }
     break;
 
-  case 61:
-#line 352 "parse-gram.y"
+  case 60:
+#line 351 "parse-gram.y"
     { grammar_rule_end (yylsp[0]); }
     break;
 
-  case 62:
-#line 353 "parse-gram.y"
+  case 61:
+#line 352 "parse-gram.y"
     { grammar_rule_end (yylsp[0]); }
     break;
 
@@ -1624,7 +1625,7 @@ yyreduce:
     }
 
 /* Line 999 of yacc.c.  */
-#line 1628 "parse-gram.c"
+#line 1629 "parse-gram.c"
 
   yyvsp -= yylen;
   yyssp -= yylen;
