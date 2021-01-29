@@ -70,7 +70,7 @@
 
 /* Copy the first part of user declarations.  */
 /* Line 164 of yacc.c.  */
-#line 1 "parse-gram.y"
+#line 1 "../../src/parse-gram.y"
 /* Bison Grammar Parser                             -*- C -*-
 
    Copyright (C) 2002, 2003, 2004, 2005, 2006 Free Software Foundation, Inc.
@@ -127,7 +127,14 @@ static void gram_error (location const *, char const *);
 
 static char const *char_name (char);
 
-static void add_param (char const *, char *, location);
+/** Add a lex-param or a parse-param.
+ *
+ * \param type  \a lex_param or \a parse_param
+ * \param decl  the formal argument
+ * \param loc   the location in the source.
+ */
+static void add_param (char const *type, char *decl, location loc);
+
 
 static symbol_class current_class = unknown_sym;
 static uniqstr current_type = NULL;
@@ -286,7 +293,7 @@ static int current_prec = 0;
 #if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
 typedef union YYSTYPE
 /* Line 198 of yacc.c.  */
-#line 90 "parse-gram.y"
+#line 97 "../../src/parse-gram.y"
 {
   symbol *symbol;
   symbol_list *list;
@@ -297,7 +304,7 @@ typedef union YYSTYPE
   unsigned char character;
 }
 /* Line 198 of yacc.c.  */
-#line 301 "parse-gram.c"
+#line 308 "../../src/parse-gram.c"
 	YYSTYPE;
 # define YYSTYPE_IS_TRIVIAL 1
 # define yystype YYSTYPE /* obsolescent; will be withdrawn */
@@ -321,7 +328,7 @@ typedef struct YYLTYPE
 /* Copy the second part of user declarations.  */
 
 /* Line 221 of yacc.c.  */
-#line 325 "parse-gram.c"
+#line 332 "../../src/parse-gram.c"
 
 #ifdef short
 # undef short
@@ -538,16 +545,16 @@ union yyalloc
 /* YYFINAL -- State number of the termination state.  */
 #define YYFINAL  3
 /* YYLAST -- Last index in YYTABLE.  */
-#define YYLAST   192
+#define YYLAST   168
 
 /* YYNTOKENS -- Number of terminals.  */
 #define YYNTOKENS  57
 /* YYNNTS -- Number of nonterminals.  */
-#define YYNNTS  27
+#define YYNNTS  29
 /* YYNRULES -- Number of rules.  */
-#define YYNRULES  89
+#define YYNRULES  92
 /* YYNRULES -- Number of states.  */
-#define YYNSTATES  128
+#define YYNSTATES  131
 
 /* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
 #define YYUNDEFTOK  2
@@ -599,57 +606,59 @@ static const yytype_uint8 yytranslate[] =
 static const yytype_uint8 yyprhs[] =
 {
        0,     0,     3,     8,     9,    12,    14,    16,    19,    22,
-      24,    27,    31,    33,    36,    38,    41,    44,    48,    50,
-      53,    56,    58,    62,    64,    66,    70,    73,    75,    78,
-      81,    84,    86,    88,    90,    92,    94,    96,    99,   103,
-     107,   109,   111,   112,   114,   118,   119,   123,   124,   128,
-     132,   136,   138,   140,   142,   143,   145,   147,   150,   152,
-     154,   157,   160,   164,   166,   169,   171,   174,   176,   179,
-     182,   183,   187,   189,   193,   196,   197,   200,   203,   207,
-     211,   215,   217,   219,   221,   223,   225,   227,   229,   230
+      24,    28,    30,    33,    35,    38,    41,    45,    47,    50,
+      53,    55,    59,    61,    63,    67,    70,    72,    75,    78,
+      81,    83,    85,    87,    89,    91,    93,    96,   100,   104,
+     106,   108,   109,   111,   115,   116,   120,   121,   125,   129,
+     133,   135,   137,   139,   140,   142,   144,   147,   149,   151,
+     154,   157,   161,   163,   166,   168,   171,   173,   176,   179,
+     180,   184,   186,   190,   193,   194,   197,   200,   204,   208,
+     212,   214,   216,   217,   219,   221,   223,   225,   227,   229,
+     231,   233,   234
 };
 
 /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
 static const yytype_int8 yyrhs[] =
 {
-      58,     0,    -1,    59,    51,    72,    83,    -1,    -1,    59,
-      60,    -1,    61,    -1,    53,    -1,    16,    45,    -1,    17,
-      45,    -1,    18,    -1,    20,    82,    -1,    20,    82,    82,
-      -1,    21,    -1,    22,    45,    -1,    23,    -1,    24,     4,
-      -1,    25,     4,    -1,    26,    48,    82,    -1,    27,    -1,
-      28,    45,    -1,    29,    45,    -1,    30,    -1,    31,    48,
-      82,    -1,    33,    -1,    34,    -1,    35,    48,    82,    -1,
-      36,    45,    -1,    37,    -1,    38,    82,    -1,    39,    82,
-      -1,    41,    45,    -1,    42,    -1,    43,    -1,    44,    -1,
-      54,    -1,    66,    -1,    63,    -1,    40,    80,    -1,     8,
-      45,    69,    -1,     9,    45,    69,    -1,    19,    -1,    32,
-      -1,    -1,    49,    -1,    56,    62,    45,    -1,    -1,     6,
-      64,    71,    -1,    -1,     5,    65,    71,    -1,     7,    55,
-      69,    -1,    67,    68,    69,    -1,    10,    -1,    11,    -1,
-      12,    -1,    -1,    55,    -1,    80,    -1,    69,    80,    -1,
-      55,    -1,    78,    -1,    78,     4,    -1,    78,    81,    -1,
-      78,     4,    81,    -1,    70,    -1,    71,    70,    -1,    73,
-      -1,    72,    73,    -1,    74,    -1,    61,    54,    -1,     1,
-      54,    -1,    -1,    79,    75,    76,    -1,    77,    -1,    76,
-      52,    77,    -1,    76,    54,    -1,    -1,    77,    80,    -1,
-      77,    45,    -1,    77,    13,    80,    -1,    77,    14,     4,
-      -1,    77,    15,    55,    -1,    49,    -1,    46,    -1,    50,
-      -1,    78,    -1,    81,    -1,     3,    -1,     3,    -1,    -1,
-      51,    47,    -1
+      58,     0,    -1,    59,    51,    72,    85,    -1,    -1,    59,
+      60,    -1,    61,    -1,    53,    -1,    16,    80,    -1,    17,
+      80,    -1,    18,    -1,    20,     3,    79,    -1,    21,    -1,
+      22,    80,    -1,    23,    -1,    24,     4,    -1,    25,     4,
+      -1,    26,    48,     3,    -1,    27,    -1,    28,    45,    -1,
+      29,    45,    -1,    30,    -1,    31,    48,     3,    -1,    33,
+      -1,    34,    -1,    35,    48,     3,    -1,    36,    45,    -1,
+      37,    -1,    38,     3,    -1,    39,     3,    -1,    41,    80,
+      -1,    42,    -1,    43,    -1,    44,    -1,    54,    -1,    66,
+      -1,    63,    -1,    40,    83,    -1,     8,    45,    69,    -1,
+       9,    45,    69,    -1,    19,    -1,    32,    -1,    -1,    49,
+      -1,    56,    62,    45,    -1,    -1,     6,    64,    71,    -1,
+      -1,     5,    65,    71,    -1,     7,    55,    69,    -1,    67,
+      68,    69,    -1,    10,    -1,    11,    -1,    12,    -1,    -1,
+      55,    -1,    83,    -1,    69,    83,    -1,    55,    -1,    81,
+      -1,    81,     4,    -1,    81,    84,    -1,    81,     4,    84,
+      -1,    70,    -1,    71,    70,    -1,    73,    -1,    72,    73,
+      -1,    74,    -1,    61,    54,    -1,     1,    54,    -1,    -1,
+      82,    75,    76,    -1,    77,    -1,    76,    52,    77,    -1,
+      76,    54,    -1,    -1,    77,    83,    -1,    77,    45,    -1,
+      77,    13,    83,    -1,    77,    14,     4,    -1,    77,    15,
+      55,    -1,     3,    -1,    80,    -1,    -1,    78,    -1,    45,
+      -1,    49,    -1,    46,    -1,    50,    -1,    81,    -1,    84,
+      -1,     3,    -1,    -1,    51,    47,    -1
 };
 
 /* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
 static const yytype_uint16 yyrline[] =
 {
-       0,   195,   195,   203,   205,   209,   210,   214,   220,   226,
-     227,   232,   233,   234,   240,   241,   242,   243,   244,   249,
-     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
-     263,   269,   270,   271,   272,   276,   277,   278,   282,   290,
-     298,   302,   316,   317,   321,   343,   343,   348,   348,   353,
-     364,   379,   380,   381,   385,   386,   391,   392,   397,   402,
-     407,   413,   419,   430,   431,   440,   441,   447,   448,   449,
-     456,   456,   460,   461,   462,   467,   468,   470,   472,   474,
-     476,   489,   491,   500,   505,   506,   511,   520,   525,   527
+       0,   205,   205,   213,   215,   219,   220,   221,   222,   223,
+     224,   225,   226,   227,   228,   229,   230,   231,   236,   240,
+     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
+     251,   252,   253,   254,   258,   259,   260,   264,   272,   280,
+     284,   298,   299,   303,   325,   325,   330,   330,   335,   346,
+     361,   362,   363,   367,   368,   373,   374,   379,   384,   389,
+     395,   401,   412,   413,   422,   423,   429,   430,   431,   438,
+     438,   442,   443,   444,   449,   450,   452,   454,   456,   458,
+     468,   469,   475,   479,   484,   500,   502,   511,   516,   517,
+     522,   529,   531
 };
 #endif
 
@@ -672,12 +681,12 @@ static const char *const yytname[] =
   "\"%verbose\"", "\"%yacc\"", "\"{...}\"", "\"char\"", "\"epilogue\"",
   "\"=\"", "\"identifier\"", "\"identifier:\"", "\"%%\"", "\"|\"",
   "\"%{...%}\"", "\";\"", "\"type\"", "\"%union\"", "$accept", "input",
-  "declarations", "declaration", "grammar_declaration", "union_name",
-  "symbol_declaration", "@1", "@2", "precedence_declaration",
+  "prologue_declarations", "prologue_declaration", "grammar_declaration",
+  "union_name", "symbol_declaration", "@1", "@2", "precedence_declaration",
   "precedence_declarator", "type.opt", "symbols.1", "symbol_def",
   "symbol_defs.1", "grammar", "rules_or_grammar_declaration", "rules",
-  "@3", "rhses.1", "rhs", "id", "id_colon", "symbol", "string_as_id",
-  "string_content", "epilogue.opt", 0
+  "@3", "rhses.1", "rhs", "content", "content.opt", "braceless", "id",
+  "id_colon", "symbol", "string_as_id", "epilogue.opt", 0
 };
 #endif
 
@@ -701,26 +710,28 @@ static const yytype_uint8 yyr1[] =
        0,    57,    58,    59,    59,    60,    60,    60,    60,    60,
       60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
       60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
-      60,    60,    60,    60,    60,    61,    61,    61,    61,    61,
-      61,    61,    62,    62,    61,    64,    63,    65,    63,    63,
-      66,    67,    67,    67,    68,    68,    69,    69,    70,    70,
-      70,    70,    70,    71,    71,    72,    72,    73,    73,    73,
-      75,    74,    76,    76,    76,    77,    77,    77,    77,    77,
-      77,    78,    78,    79,    80,    80,    81,    82,    83,    83
+      60,    60,    60,    60,    61,    61,    61,    61,    61,    61,
+      61,    62,    62,    61,    64,    63,    65,    63,    63,    66,
+      67,    67,    67,    68,    68,    69,    69,    70,    70,    70,
+      70,    70,    71,    71,    72,    72,    73,    73,    73,    75,
+      74,    76,    76,    76,    77,    77,    77,    77,    77,    77,
+      78,    78,    79,    79,    80,    81,    81,    82,    83,    83,
+      84,    85,    85
 };
 
 /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
 static const yytype_uint8 yyr2[] =
 {
        0,     2,     4,     0,     2,     1,     1,     2,     2,     1,
-       2,     3,     1,     2,     1,     2,     2,     3,     1,     2,
-       2,     1,     3,     1,     1,     3,     2,     1,     2,     2,
-       2,     1,     1,     1,     1,     1,     1,     2,     3,     3,
-       1,     1,     0,     1,     3,     0,     3,     0,     3,     3,
-       3,     1,     1,     1,     0,     1,     1,     2,     1,     1,
-       2,     2,     3,     1,     2,     1,     2,     1,     2,     2,
-       0,     3,     1,     3,     2,     0,     2,     2,     3,     3,
-       3,     1,     1,     1,     1,     1,     1,     1,     0,     2
+       3,     1,     2,     1,     2,     2,     3,     1,     2,     2,
+       1,     3,     1,     1,     3,     2,     1,     2,     2,     2,
+       1,     1,     1,     1,     1,     1,     2,     3,     3,     1,
+       1,     0,     1,     3,     0,     3,     0,     3,     3,     3,
+       1,     1,     1,     0,     1,     1,     2,     1,     1,     2,
+       2,     3,     1,     2,     1,     2,     1,     2,     2,     0,
+       3,     1,     3,     2,     0,     2,     2,     3,     3,     3,
+       1,     1,     0,     1,     1,     1,     1,     1,     1,     1,
+       1,     0,     2
 };
 
 /* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
@@ -728,108 +739,104 @@ static const yytype_uint8 yyr2[] =
    means the default is an error.  */
 static const yytype_uint8 yydefact[] =
 {
-       3,     0,     0,     1,    47,    45,     0,     0,     0,    51,
-      52,    53,     0,     0,     9,    40,     0,    12,     0,    14,
-       0,     0,     0,    18,     0,     0,    21,     0,    41,    23,
-      24,     0,     0,    27,     0,     0,     0,     0,    31,    32,
-      33,     0,     6,    34,    42,     4,     5,    36,    35,    54,
-       0,     0,     0,     0,     0,     7,     8,    87,    10,    13,
-      15,    16,     0,    19,    20,     0,     0,    26,    28,    29,
-      86,    82,    81,    84,    37,    85,    30,     0,    83,     0,
-       0,    65,    67,    70,    43,     0,    55,     0,    58,    63,
-      48,    59,    46,    49,    56,    38,    39,    11,    17,    22,
-      25,    69,    68,     0,    66,     2,    75,    44,    50,    64,
-      60,    61,    57,    89,    71,    72,    62,    75,    74,     0,
-       0,     0,    77,    76,    73,    78,    79,    80
+       3,     0,     0,     1,    46,    44,     0,     0,     0,    50,
+      51,    52,     0,     0,     9,    39,     0,    11,     0,    13,
+       0,     0,     0,    17,     0,     0,    20,     0,    40,    22,
+      23,     0,     0,    26,     0,     0,     0,     0,    30,    31,
+      32,     0,     6,    33,    41,     4,     5,    35,    34,    53,
+       0,     0,     0,     0,     0,    84,     7,     8,    82,    12,
+      14,    15,     0,    18,    19,     0,     0,    25,    27,    28,
+      90,    86,    85,    88,    36,    89,    29,     0,    87,     0,
+       0,    64,    66,    69,    42,     0,    54,     0,    57,    62,
+      47,    58,    45,    48,    55,    37,    38,    80,    83,    10,
+      81,    16,    21,    24,    68,    67,     0,    65,     2,    74,
+      43,    49,    63,    59,    60,    56,    92,    70,    71,    61,
+      74,    73,     0,     0,     0,    76,    75,    72,    77,    78,
+      79
 };
 
 /* YYDEFGOTO[NTERM-NUM].  */
 static const yytype_int8 yydefgoto[] =
 {
       -1,     1,     2,    45,    79,    85,    47,    51,    50,    48,
-      49,    87,    93,    89,    90,    80,    81,    82,   106,   114,
-     115,    73,    83,    94,    75,    58,   105
+      49,    87,    93,    89,    90,    80,    81,    82,   109,   117,
+     118,    98,    99,    56,    73,    83,    94,    75,   108
 };
 
 /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
    STATE-NUM.  */
-#define YYPACT_NINF -76
-static const yytype_int16 yypact[] =
+#define YYPACT_NINF -91
+static const yytype_int8 yypact[] =
 {
-     -76,     6,   136,   -76,   -76,   -76,   -40,   -12,    -9,   -76,
-     -76,   -76,    -5,     1,   -76,   -76,    40,   -76,     5,   -76,
-      47,    50,     7,   -76,    11,    18,   -76,    19,   -76,   -76,
-     -76,    20,    25,   -76,    40,    40,    -2,    26,   -76,   -76,
-     -76,    84,   -76,   -76,    27,   -76,   -76,   -76,   -76,    14,
-     -23,   -23,    -2,    -2,    -2,   -76,   -76,   -76,    40,   -76,
-     -76,   -76,    40,   -76,   -76,    40,    40,   -76,   -76,   -76,
-     -76,   -76,   -76,   -76,   -76,   -76,   -76,    21,   -76,    23,
-       2,   -76,   -76,   -76,   -76,    28,   -76,    -2,   -76,   -76,
-     -23,    24,   -23,    -2,   -76,    -2,    -2,   -76,   -76,   -76,
-     -76,   -76,   -76,    31,   -76,   -76,   -76,   -76,    -2,   -76,
-      71,   -76,   -76,   -76,   -32,    16,   -76,   -76,   -76,    -2,
-      76,    29,   -76,   -76,    16,   -76,   -76,   -76
+     -91,    29,   112,   -91,   -91,   -91,   -39,   -14,   -13,   -91,
+     -91,   -91,   -12,   -12,   -91,   -91,    33,   -91,   -12,   -91,
+      35,    36,   -11,   -91,     5,     6,   -91,     1,   -91,   -91,
+     -91,     7,     9,   -91,    53,    61,    27,   -12,   -91,   -91,
+     -91,    60,   -91,   -91,    14,   -91,   -91,   -91,   -91,    19,
+     -31,   -31,    27,    27,    27,   -91,   -91,   -91,     3,   -91,
+     -91,   -91,    77,   -91,   -91,    81,    84,   -91,   -91,   -91,
+     -91,   -91,   -91,   -91,   -91,   -91,   -91,    34,   -91,    39,
+       2,   -91,   -91,   -91,   -91,    44,   -91,    27,   -91,   -91,
+     -31,    16,   -31,    27,   -91,    27,    27,   -91,   -91,   -91,
+     -91,   -91,   -91,   -91,   -91,   -91,    43,   -91,   -91,   -91,
+     -91,    27,   -91,    91,   -91,   -91,   -91,   -27,    32,   -91,
+     -91,   -91,    27,    92,    40,   -91,   -91,    32,   -91,   -91,
+     -91
 };
 
 /* YYPGOTO[NTERM-NUM].  */
 static const yytype_int8 yypgoto[] =
 {
-     -76,   -76,   -76,   -76,    79,   -76,   -76,   -76,   -76,   -76,
-     -76,   -76,   -49,   -53,    35,   -76,    17,   -76,   -76,   -76,
-     -35,   -26,   -76,   -36,   -75,   -17,   -76
+     -91,   -91,   -91,   -91,    95,   -91,   -91,   -91,   -91,   -91,
+     -91,   -91,   -49,   -64,    47,   -91,    21,   -91,   -91,   -91,
+     -21,   -91,   -91,     4,    -7,   -91,   -36,   -90,   -91
 };
 
 /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
    positive, shift that token.  If negative, reduce the rule which
    number is the opposite.  If zero, do what YYDEFACT says.
    If YYTABLE_NINF, syntax error.  */
-#define YYTABLE_NINF -89
-static const yytype_int8 yytable[] =
+#define YYTABLE_NINF -92
+static const yytype_int16 yytable[] =
 {
-      74,    70,   -88,    77,    95,    96,     3,     4,     5,     6,
-       7,     8,     9,    10,    11,    52,   111,    68,    69,    70,
-     117,    15,   118,    71,    91,    91,    72,    70,   110,   119,
-     120,   121,    88,    53,    28,   116,    54,   109,   108,   109,
-      55,    97,    36,    57,    71,    98,    56,    72,    99,   100,
-      59,    60,    78,   103,    61,    62,    63,   112,    44,   112,
-     112,   122,    71,    64,    91,    72,    91,    65,    66,    86,
-      67,    76,   112,   107,    70,   101,    84,   102,   113,   123,
-     126,    46,   124,   125,   127,    77,    92,     0,   123,     4,
-       5,     6,     7,     8,     9,    10,    11,   104,     0,     0,
-       0,     0,     0,    15,     0,     0,     0,     0,     0,     0,
-       0,     0,     0,     0,     0,     0,    28,     0,     0,     0,
-       0,     0,     0,     0,    36,     0,     0,     0,     0,     0,
-       0,     0,     0,     0,    78,     0,     0,     0,     0,     0,
-      44,     4,     5,     6,     7,     8,     9,    10,    11,     0,
-       0,     0,    12,    13,    14,    15,    16,    17,    18,    19,
-      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
-      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
-      40,     0,     0,     0,     0,     0,     0,    41,     0,    42,
-      43,     0,    44
+      74,   114,   -91,    77,    95,    96,    97,     4,     5,     6,
+       7,     8,     9,    10,    11,    71,    52,    57,    72,    70,
+     113,    15,    59,   119,    88,   120,   112,   121,   112,     3,
+      70,    53,    54,    55,    28,    70,    58,    62,   111,    60,
+      61,    76,    36,    91,    91,   122,   123,   124,    55,    65,
+      63,    64,    78,   106,    67,    66,    68,   115,    44,   115,
+     115,    77,   100,    84,    69,     4,     5,     6,     7,     8,
+       9,    10,    11,    71,    86,   115,    72,   125,    71,    15,
+     101,    72,   126,    91,   102,    91,   128,   103,   104,   110,
+     116,   126,    28,   105,    70,   130,   129,    46,    92,   127,
+      36,   107,     0,     0,     0,     0,     0,     0,     0,     0,
+      78,     0,     0,     0,     0,     0,    44,     4,     5,     6,
+       7,     8,     9,    10,    11,     0,     0,     0,    12,    13,
+      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
+      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
+      34,    35,    36,    37,    38,    39,    40,     0,     0,     0,
+       0,     0,     0,    41,     0,    42,    43,     0,    44
 };
 
 static const yytype_int8 yycheck[] =
 {
-      36,     3,     0,     1,    53,    54,     0,     5,     6,     7,
-       8,     9,    10,    11,    12,    55,    91,    34,    35,     3,
-      52,    19,    54,    46,    50,    51,    49,     3,     4,    13,
-      14,    15,    55,    45,    32,   110,    45,    90,    87,    92,
-      45,    58,    40,     3,    46,    62,    45,    49,    65,    66,
-      45,     4,    50,    51,     4,    48,    45,    93,    56,    95,
-      96,    45,    46,    45,    90,    49,    92,    48,    48,    55,
-      45,    45,   108,    45,     3,    54,    49,    54,    47,   115,
-       4,     2,   117,   119,    55,     1,    51,    -1,   124,     5,
-       6,     7,     8,     9,    10,    11,    12,    80,    -1,    -1,
-      -1,    -1,    -1,    19,    -1,    -1,    -1,    -1,    -1,    -1,
-      -1,    -1,    -1,    -1,    -1,    -1,    32,    -1,    -1,    -1,
-      -1,    -1,    -1,    -1,    40,    -1,    -1,    -1,    -1,    -1,
-      -1,    -1,    -1,    -1,    50,    -1,    -1,    -1,    -1,    -1,
-      56,     5,     6,     7,     8,     9,    10,    11,    12,    -1,
-      -1,    -1,    16,    17,    18,    19,    20,    21,    22,    23,
-      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
-      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
-      44,    -1,    -1,    -1,    -1,    -1,    -1,    51,    -1,    53,
-      54,    -1,    56
+      36,    91,     0,     1,    53,    54,     3,     5,     6,     7,
+       8,     9,    10,    11,    12,    46,    55,    13,    49,     3,
+       4,    19,    18,   113,    55,    52,    90,    54,    92,     0,
+       3,    45,    45,    45,    32,     3,     3,    48,    87,     4,
+       4,    37,    40,    50,    51,    13,    14,    15,    45,    48,
+      45,    45,    50,    51,    45,    48,     3,    93,    56,    95,
+      96,     1,    58,    49,     3,     5,     6,     7,     8,     9,
+      10,    11,    12,    46,    55,   111,    49,    45,    46,    19,
+       3,    49,   118,    90,     3,    92,   122,     3,    54,    45,
+      47,   127,    32,    54,     3,    55,     4,     2,    51,   120,
+      40,    80,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
+      50,    -1,    -1,    -1,    -1,    -1,    56,     5,     6,     7,
+       8,     9,    10,    11,    12,    -1,    -1,    -1,    16,    17,
+      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
+      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
+      38,    39,    40,    41,    42,    43,    44,    -1,    -1,    -1,
+      -1,    -1,    -1,    51,    -1,    53,    54,    -1,    56
 };
 
 /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
@@ -841,14 +848,15 @@ static const yytype_uint8 yystos[] =
       24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
       34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
       44,    51,    53,    54,    56,    60,    61,    63,    66,    67,
-      65,    64,    55,    45,    45,    45,    45,     3,    82,    45,
-       4,     4,    48,    45,    45,    48,    48,    45,    82,    82,
-       3,    46,    49,    78,    80,    81,    45,     1,    50,    61,
-      72,    73,    74,    79,    49,    62,    55,    68,    55,    70,
-      71,    78,    71,    69,    80,    69,    69,    82,    82,    82,
-      82,    54,    54,    51,    73,    83,    75,    45,    69,    70,
-       4,    81,    80,    47,    76,    77,    81,    52,    54,    13,
-      14,    15,    45,    80,    77,    80,     4,    55
+      65,    64,    55,    45,    45,    45,    80,    80,     3,    80,
+       4,     4,    48,    45,    45,    48,    48,    45,     3,     3,
+       3,    46,    49,    81,    83,    84,    80,     1,    50,    61,
+      72,    73,    74,    82,    49,    62,    55,    68,    55,    70,
+      71,    81,    71,    69,    83,    69,    69,     3,    78,    79,
+      80,     3,     3,     3,    54,    54,    51,    73,    85,    75,
+      45,    69,    70,     4,    84,    83,    47,    76,    77,    84,
+      52,    54,    13,    14,    15,    45,    83,    77,    83,     4,
+      55
 };
 
 #define yyerrok		(yyerrstatus = 0)
@@ -998,101 +1006,115 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
     {
       case 3: /* "\"string\"" */
 /* Line 670 of yacc.c.  */
-#line 174 "parse-gram.y"
+#line 183 "../../src/parse-gram.y"
 	{ fputs (quotearg_style (c_quoting_style, (yyvaluep->chars)), stderr); };
 /* Line 670 of yacc.c.  */
-#line 1005 "parse-gram.c"
+#line 1013 "../../src/parse-gram.c"
 	break;
       case 4: /* "\"integer\"" */
 /* Line 670 of yacc.c.  */
-#line 184 "parse-gram.y"
+#line 194 "../../src/parse-gram.y"
 	{ fprintf (stderr, "%d", (yyvaluep->integer)); };
 /* Line 670 of yacc.c.  */
-#line 1012 "parse-gram.c"
+#line 1020 "../../src/parse-gram.c"
 	break;
       case 45: /* "\"{...}\"" */
 /* Line 670 of yacc.c.  */
-#line 176 "parse-gram.y"
+#line 185 "../../src/parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 /* Line 670 of yacc.c.  */
-#line 1019 "parse-gram.c"
+#line 1027 "../../src/parse-gram.c"
 	break;
       case 46: /* "\"char\"" */
 /* Line 670 of yacc.c.  */
-#line 171 "parse-gram.y"
+#line 178 "../../src/parse-gram.y"
 	{ fputs (char_name ((yyvaluep->character)), stderr); };
 /* Line 670 of yacc.c.  */
-#line 1026 "parse-gram.c"
+#line 1034 "../../src/parse-gram.c"
 	break;
       case 47: /* "\"epilogue\"" */
 /* Line 670 of yacc.c.  */
-#line 176 "parse-gram.y"
+#line 185 "../../src/parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 /* Line 670 of yacc.c.  */
-#line 1033 "parse-gram.c"
+#line 1041 "../../src/parse-gram.c"
 	break;
       case 49: /* "\"identifier\"" */
 /* Line 670 of yacc.c.  */
-#line 180 "parse-gram.y"
+#line 190 "../../src/parse-gram.y"
 	{ fputs ((yyvaluep->uniqstr), stderr); };
 /* Line 670 of yacc.c.  */
-#line 1040 "parse-gram.c"
+#line 1048 "../../src/parse-gram.c"
 	break;
       case 50: /* "\"identifier:\"" */
 /* Line 670 of yacc.c.  */
-#line 181 "parse-gram.y"
+#line 191 "../../src/parse-gram.y"
 	{ fprintf (stderr, "%s:", (yyvaluep->uniqstr)); };
 /* Line 670 of yacc.c.  */
-#line 1047 "parse-gram.c"
+#line 1055 "../../src/parse-gram.c"
 	break;
       case 53: /* "\"%{...%}\"" */
 /* Line 670 of yacc.c.  */
-#line 176 "parse-gram.y"
+#line 185 "../../src/parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 /* Line 670 of yacc.c.  */
-#line 1054 "parse-gram.c"
+#line 1062 "../../src/parse-gram.c"
 	break;
       case 55: /* "\"type\"" */
 /* Line 670 of yacc.c.  */
-#line 179 "parse-gram.y"
+#line 189 "../../src/parse-gram.y"
 	{ fprintf (stderr, "<%s>", (yyvaluep->uniqstr)); };
 /* Line 670 of yacc.c.  */
-#line 1061 "parse-gram.c"
+#line 1069 "../../src/parse-gram.c"
 	break;
-      case 78: /* "id" */
+      case 78: /* "content" */
 /* Line 670 of yacc.c.  */
-#line 187 "parse-gram.y"
-	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
+#line 185 "../../src/parse-gram.y"
+	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 /* Line 670 of yacc.c.  */
-#line 1068 "parse-gram.c"
+#line 1076 "../../src/parse-gram.c"
 	break;
-      case 79: /* "id_colon" */
+      case 79: /* "content.opt" */
 /* Line 670 of yacc.c.  */
-#line 188 "parse-gram.y"
-	{ fprintf (stderr, "%s:", (yyvaluep->symbol)->tag); };
+#line 185 "../../src/parse-gram.y"
+	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 /* Line 670 of yacc.c.  */
-#line 1075 "parse-gram.c"
+#line 1083 "../../src/parse-gram.c"
 	break;
-      case 80: /* "symbol" */
+      case 80: /* "braceless" */
 /* Line 670 of yacc.c.  */
-#line 187 "parse-gram.y"
+#line 185 "../../src/parse-gram.y"
+	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
+/* Line 670 of yacc.c.  */
+#line 1090 "../../src/parse-gram.c"
+	break;
+      case 81: /* "id" */
+/* Line 670 of yacc.c.  */
+#line 197 "../../src/parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 /* Line 670 of yacc.c.  */
-#line 1082 "parse-gram.c"
+#line 1097 "../../src/parse-gram.c"
+	break;
+      case 82: /* "id_colon" */
+/* Line 670 of yacc.c.  */
+#line 198 "../../src/parse-gram.y"
+	{ fprintf (stderr, "%s:", (yyvaluep->symbol)->tag); };
+/* Line 670 of yacc.c.  */
+#line 1104 "../../src/parse-gram.c"
 	break;
-      case 81: /* "string_as_id" */
+      case 83: /* "symbol" */
 /* Line 670 of yacc.c.  */
-#line 187 "parse-gram.y"
+#line 197 "../../src/parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 /* Line 670 of yacc.c.  */
-#line 1089 "parse-gram.c"
+#line 1111 "../../src/parse-gram.c"
 	break;
-      case 82: /* "string_content" */
+      case 84: /* "string_as_id" */
 /* Line 670 of yacc.c.  */
-#line 174 "parse-gram.y"
-	{ fputs (quotearg_style (c_quoting_style, (yyvaluep->chars)), stderr); };
+#line 197 "../../src/parse-gram.y"
+	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 /* Line 670 of yacc.c.  */
-#line 1096 "parse-gram.c"
+#line 1118 "../../src/parse-gram.c"
 	break;
       default:
 	break;
@@ -1606,7 +1628,7 @@ YYLTYPE yylloc;
 
   /* User initialization code.  */
   /* Line 1082 of yacc.c.  */
-#line 81 "parse-gram.y"
+#line 88 "../../src/parse-gram.y"
 {
   /* Bison's grammar can initial empty locations, hence a default
      location is needed. */
@@ -1614,7 +1636,7 @@ YYLTYPE yylloc;
   boundary_set (&yylloc.end, current_file, 1, 1);
 }
 /* Line 1082 of yacc.c.  */
-#line 1618 "parse-gram.c"
+#line 1640 "../../src/parse-gram.c"
   yylsp[0] = yylloc;
   goto yysetstate;
 
@@ -1800,209 +1822,182 @@ yyreduce:
     {
         case 6:
 /* Line 1270 of yacc.c.  */
-#line 211 "parse-gram.y"
-    {
-      prologue_augment (translate_code ((yyvsp[(1) - (1)].chars), (yylsp[(1) - (1)])), (yylsp[(1) - (1)]), union_seen);
-    }
+#line 220 "../../src/parse-gram.y"
+    { prologue_augment (translate_code ((yyvsp[(1) - (1)].chars), (yylsp[(1) - (1)])), (yylsp[(1) - (1)]), union_seen); }
     break;
 
   case 7:
 /* Line 1270 of yacc.c.  */
-#line 215 "parse-gram.y"
-    {
-      /* Remove the '{', and replace the '}' with '\n'.  */
-      (yyvsp[(2) - (2)].chars)[strlen ((yyvsp[(2) - (2)].chars)) - 1] = '\n';
-      prologue_augment (translate_code ((yyvsp[(2) - (2)].chars)+1, (yylsp[(2) - (2)])), (yylsp[(2) - (2)]), true);
-    }
+#line 221 "../../src/parse-gram.y"
+    { prologue_augment ((yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)]), true); }
     break;
 
   case 8:
 /* Line 1270 of yacc.c.  */
-#line 221 "parse-gram.y"
-    {
-      /* Remove the '{', and replace the '}' with '\n'.  */
-      (yyvsp[(2) - (2)].chars)[strlen ((yyvsp[(2) - (2)].chars)) - 1] = '\n';
-      prologue_augment (translate_code ((yyvsp[(2) - (2)].chars)+1, (yylsp[(2) - (2)])), (yylsp[(2) - (2)]), false);
-    }
+#line 222 "../../src/parse-gram.y"
+    { prologue_augment ((yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)]), false); }
     break;
 
   case 9:
 /* Line 1270 of yacc.c.  */
-#line 226 "parse-gram.y"
+#line 223 "../../src/parse-gram.y"
     { debug_flag = true; }
     break;
 
   case 10:
 /* Line 1270 of yacc.c.  */
-#line 228 "parse-gram.y"
-    {
-      static char one[] = "1";
-      muscle_insert ((yyvsp[(2) - (2)].chars), one);
-    }
+#line 224 "../../src/parse-gram.y"
+    { muscle_insert ((yyvsp[(2) - (3)].chars), (yyvsp[(3) - (3)].chars)); }
     break;
 
   case 11:
 /* Line 1270 of yacc.c.  */
-#line 232 "parse-gram.y"
-    { muscle_insert ((yyvsp[(2) - (3)].chars), (yyvsp[(3) - (3)].chars)); }
+#line 225 "../../src/parse-gram.y"
+    { defines_flag = true; }
     break;
 
   case 12:
 /* Line 1270 of yacc.c.  */
-#line 233 "parse-gram.y"
-    { defines_flag = true; }
+#line 226 "../../src/parse-gram.y"
+    { muscle_code_grow ("end_header", (yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])); }
     break;
 
   case 13:
 /* Line 1270 of yacc.c.  */
-#line 235 "parse-gram.y"
-    {
-      /* Remove the '{', and replace the '}' with '\n'.  */
-      (yyvsp[(2) - (2)].chars)[strlen ((yyvsp[(2) - (2)].chars)) - 1] = '\n';
-      muscle_code_grow ("end_header", translate_code ((yyvsp[(2) - (2)].chars)+1, (yylsp[(2) - (2)])), (yylsp[(2) - (2)]));
-    }
-    break;
-
-  case 14:
-/* Line 1270 of yacc.c.  */
-#line 240 "parse-gram.y"
+#line 227 "../../src/parse-gram.y"
     { error_verbose = true; }
     break;
 
-  case 15:
+  case 14:
 /* Line 1270 of yacc.c.  */
-#line 241 "parse-gram.y"
+#line 228 "../../src/parse-gram.y"
     { expected_sr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
-  case 16:
+  case 15:
 /* Line 1270 of yacc.c.  */
-#line 242 "parse-gram.y"
+#line 229 "../../src/parse-gram.y"
     { expected_rr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
-  case 17:
+  case 16:
 /* Line 1270 of yacc.c.  */
-#line 243 "parse-gram.y"
+#line 230 "../../src/parse-gram.y"
     { spec_file_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
-  case 18:
+  case 17:
 /* Line 1270 of yacc.c.  */
-#line 245 "parse-gram.y"
+#line 232 "../../src/parse-gram.y"
     {
       nondeterministic_parser = true;
       glr_parser = true;
     }
     break;
 
-  case 19:
+  case 18:
 /* Line 1270 of yacc.c.  */
-#line 250 "parse-gram.y"
+#line 237 "../../src/parse-gram.y"
     {
       muscle_code_grow ("initial_action", translate_symbol_action ((yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])), (yylsp[(2) - (2)]));
     }
     break;
 
-  case 20:
+  case 19:
 /* Line 1270 of yacc.c.  */
-#line 253 "parse-gram.y"
+#line 240 "../../src/parse-gram.y"
     { add_param ("lex_param", (yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])); }
     break;
 
-  case 21:
+  case 20:
 /* Line 1270 of yacc.c.  */
-#line 254 "parse-gram.y"
+#line 241 "../../src/parse-gram.y"
     { locations_flag = true; }
     break;
 
-  case 22:
+  case 21:
 /* Line 1270 of yacc.c.  */
-#line 255 "parse-gram.y"
+#line 242 "../../src/parse-gram.y"
     { spec_name_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
-  case 23:
+  case 22:
 /* Line 1270 of yacc.c.  */
-#line 256 "parse-gram.y"
+#line 243 "../../src/parse-gram.y"
     { no_lines_flag = true; }
     break;
 
-  case 24:
+  case 23:
 /* Line 1270 of yacc.c.  */
-#line 257 "parse-gram.y"
+#line 244 "../../src/parse-gram.y"
     { nondeterministic_parser = true; }
     break;
 
-  case 25:
+  case 24:
 /* Line 1270 of yacc.c.  */
-#line 258 "parse-gram.y"
+#line 245 "../../src/parse-gram.y"
     { spec_outfile = (yyvsp[(3) - (3)].chars); }
     break;
 
-  case 26:
+  case 25:
 /* Line 1270 of yacc.c.  */
-#line 259 "parse-gram.y"
+#line 246 "../../src/parse-gram.y"
     { add_param ("parse_param", (yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])); }
     break;
 
-  case 27:
+  case 26:
 /* Line 1270 of yacc.c.  */
-#line 260 "parse-gram.y"
+#line 247 "../../src/parse-gram.y"
     { pure_parser = true; }
     break;
 
-  case 28:
+  case 27:
 /* Line 1270 of yacc.c.  */
-#line 261 "parse-gram.y"
+#line 248 "../../src/parse-gram.y"
     { version_check (&(yylsp[(2) - (2)]), (yyvsp[(2) - (2)].chars)); }
     break;
 
-  case 29:
+  case 28:
 /* Line 1270 of yacc.c.  */
-#line 262 "parse-gram.y"
+#line 249 "../../src/parse-gram.y"
     { skeleton = (yyvsp[(2) - (2)].chars); }
     break;
 
-  case 30:
+  case 29:
 /* Line 1270 of yacc.c.  */
-#line 264 "parse-gram.y"
-    {
-      /* Remove the '{', and replace the '}' with '\n'.  */
-      (yyvsp[(2) - (2)].chars)[strlen ((yyvsp[(2) - (2)].chars)) - 1] = '\n';
-      muscle_code_grow ("start_header", translate_code ((yyvsp[(2) - (2)].chars)+1, (yylsp[(2) - (2)])), (yylsp[(2) - (2)]));
-    }
+#line 250 "../../src/parse-gram.y"
+    { muscle_code_grow ("start_header", (yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])); }
     break;
 
-  case 31:
+  case 30:
 /* Line 1270 of yacc.c.  */
-#line 269 "parse-gram.y"
+#line 251 "../../src/parse-gram.y"
     { token_table_flag = true; }
     break;
 
-  case 32:
+  case 31:
 /* Line 1270 of yacc.c.  */
-#line 270 "parse-gram.y"
+#line 252 "../../src/parse-gram.y"
     { report_flag = report_states; }
     break;
 
-  case 33:
+  case 32:
 /* Line 1270 of yacc.c.  */
-#line 271 "parse-gram.y"
+#line 253 "../../src/parse-gram.y"
     { yacc_flag = true; }
     break;
 
-  case 37:
+  case 36:
 /* Line 1270 of yacc.c.  */
-#line 279 "parse-gram.y"
+#line 261 "../../src/parse-gram.y"
     {
       grammar_start_symbol_set ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]));
     }
     break;
 
-  case 38:
+  case 37:
 /* Line 1270 of yacc.c.  */
-#line 283 "parse-gram.y"
+#line 265 "../../src/parse-gram.y"
     {
       symbol_list *list;
       const char *action = translate_symbol_action ((yyvsp[(2) - (3)].chars), (yylsp[(2) - (3)]));
@@ -2012,9 +2007,9 @@ yyreduce:
     }
     break;
 
-  case 39:
+  case 38:
 /* Line 1270 of yacc.c.  */
-#line 291 "parse-gram.y"
+#line 273 "../../src/parse-gram.y"
     {
       symbol_list *list;
       const char *action = translate_symbol_action ((yyvsp[(2) - (3)].chars), (yylsp[(2) - (3)]));
@@ -2024,37 +2019,37 @@ yyreduce:
     }
     break;
 
-  case 40:
+  case 39:
 /* Line 1270 of yacc.c.  */
-#line 299 "parse-gram.y"
+#line 281 "../../src/parse-gram.y"
     {
       default_prec = true;
     }
     break;
 
-  case 41:
+  case 40:
 /* Line 1270 of yacc.c.  */
-#line 303 "parse-gram.y"
+#line 285 "../../src/parse-gram.y"
     {
       default_prec = false;
     }
     break;
 
-  case 42:
+  case 41:
 /* Line 1270 of yacc.c.  */
-#line 316 "parse-gram.y"
+#line 298 "../../src/parse-gram.y"
     {}
     break;
 
-  case 43:
+  case 42:
 /* Line 1270 of yacc.c.  */
-#line 317 "parse-gram.y"
+#line 299 "../../src/parse-gram.y"
     { muscle_code_grow ("union_name", (yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
-  case 44:
+  case 43:
 /* Line 1270 of yacc.c.  */
-#line 322 "parse-gram.y"
+#line 304 "../../src/parse-gram.y"
     {
       char const *body = (yyvsp[(3) - (3)].chars);
 
@@ -2072,39 +2067,39 @@ yyreduce:
     }
     break;
 
-  case 45:
+  case 44:
 /* Line 1270 of yacc.c.  */
-#line 343 "parse-gram.y"
+#line 325 "../../src/parse-gram.y"
     { current_class = nterm_sym; }
     break;
 
-  case 46:
+  case 45:
 /* Line 1270 of yacc.c.  */
-#line 344 "parse-gram.y"
+#line 326 "../../src/parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
     break;
 
-  case 47:
+  case 46:
 /* Line 1270 of yacc.c.  */
-#line 348 "parse-gram.y"
+#line 330 "../../src/parse-gram.y"
     { current_class = token_sym; }
     break;
 
-  case 48:
+  case 47:
 /* Line 1270 of yacc.c.  */
-#line 349 "parse-gram.y"
+#line 331 "../../src/parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
     break;
 
-  case 49:
+  case 48:
 /* Line 1270 of yacc.c.  */
-#line 354 "parse-gram.y"
+#line 336 "../../src/parse-gram.y"
     {
       tag_seen = true;
       symbol_list *list;
@@ -2114,9 +2109,9 @@ yyreduce:
     }
     break;
 
-  case 50:
+  case 49:
 /* Line 1270 of yacc.c.  */
-#line 365 "parse-gram.y"
+#line 347 "../../src/parse-gram.y"
     {
       symbol_list *list;
       ++current_prec;
@@ -2130,69 +2125,69 @@ yyreduce:
     }
     break;
 
-  case 51:
+  case 50:
 /* Line 1270 of yacc.c.  */
-#line 379 "parse-gram.y"
+#line 361 "../../src/parse-gram.y"
     { (yyval.assoc) = left_assoc; }
     break;
 
-  case 52:
+  case 51:
 /* Line 1270 of yacc.c.  */
-#line 380 "parse-gram.y"
+#line 362 "../../src/parse-gram.y"
     { (yyval.assoc) = right_assoc; }
     break;
 
-  case 53:
+  case 52:
 /* Line 1270 of yacc.c.  */
-#line 381 "parse-gram.y"
+#line 363 "../../src/parse-gram.y"
     { (yyval.assoc) = non_assoc; }
     break;
 
-  case 54:
+  case 53:
 /* Line 1270 of yacc.c.  */
-#line 385 "parse-gram.y"
+#line 367 "../../src/parse-gram.y"
     { current_type = NULL; }
     break;
 
-  case 55:
+  case 54:
 /* Line 1270 of yacc.c.  */
-#line 386 "parse-gram.y"
+#line 368 "../../src/parse-gram.y"
     { current_type = (yyvsp[(1) - (1)].uniqstr); tag_seen = true; }
     break;
 
-  case 56:
+  case 55:
 /* Line 1270 of yacc.c.  */
-#line 391 "parse-gram.y"
+#line 373 "../../src/parse-gram.y"
     { (yyval.list) = symbol_list_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
-  case 57:
+  case 56:
 /* Line 1270 of yacc.c.  */
-#line 392 "parse-gram.y"
+#line 374 "../../src/parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), (yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)])); }
     break;
 
-  case 58:
+  case 57:
 /* Line 1270 of yacc.c.  */
-#line 398 "parse-gram.y"
+#line 380 "../../src/parse-gram.y"
     {
        current_type = (yyvsp[(1) - (1)].uniqstr);
        tag_seen = true;
      }
     break;
 
-  case 59:
+  case 58:
 /* Line 1270 of yacc.c.  */
-#line 403 "parse-gram.y"
+#line 385 "../../src/parse-gram.y"
     {
        symbol_class_set ((yyvsp[(1) - (1)].symbol), current_class, (yylsp[(1) - (1)]), true);
        symbol_type_set ((yyvsp[(1) - (1)].symbol), current_type, (yylsp[(1) - (1)]));
      }
     break;
 
-  case 60:
+  case 59:
 /* Line 1270 of yacc.c.  */
-#line 408 "parse-gram.y"
+#line 390 "../../src/parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
       symbol_type_set ((yyvsp[(1) - (2)].symbol), current_type, (yylsp[(1) - (2)]));
@@ -2200,9 +2195,9 @@ yyreduce:
     }
     break;
 
-  case 61:
+  case 60:
 /* Line 1270 of yacc.c.  */
-#line 414 "parse-gram.y"
+#line 396 "../../src/parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
       symbol_type_set ((yyvsp[(1) - (2)].symbol), current_type, (yylsp[(1) - (2)]));
@@ -2210,9 +2205,9 @@ yyreduce:
     }
     break;
 
-  case 62:
+  case 61:
 /* Line 1270 of yacc.c.  */
-#line 420 "parse-gram.y"
+#line 402 "../../src/parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (3)].symbol), current_class, (yylsp[(1) - (3)]), true);
       symbol_type_set ((yyvsp[(1) - (3)].symbol), current_type, (yylsp[(1) - (3)]));
@@ -2221,77 +2216,95 @@ yyreduce:
     }
     break;
 
-  case 69:
+  case 68:
 /* Line 1270 of yacc.c.  */
-#line 450 "parse-gram.y"
+#line 432 "../../src/parse-gram.y"
     {
       yyerrok;
     }
     break;
 
-  case 70:
+  case 69:
 /* Line 1270 of yacc.c.  */
-#line 456 "parse-gram.y"
+#line 438 "../../src/parse-gram.y"
     { current_lhs = (yyvsp[(1) - (1)].symbol); current_lhs_location = (yylsp[(1) - (1)]); }
     break;
 
-  case 72:
+  case 71:
 /* Line 1270 of yacc.c.  */
-#line 460 "parse-gram.y"
+#line 442 "../../src/parse-gram.y"
     { grammar_current_rule_end ((yylsp[(1) - (1)])); }
     break;
 
-  case 73:
+  case 72:
 /* Line 1270 of yacc.c.  */
-#line 461 "parse-gram.y"
+#line 443 "../../src/parse-gram.y"
     { grammar_current_rule_end ((yylsp[(3) - (3)])); }
     break;
 
-  case 75:
+  case 74:
 /* Line 1270 of yacc.c.  */
-#line 467 "parse-gram.y"
+#line 449 "../../src/parse-gram.y"
     { grammar_current_rule_begin (current_lhs, current_lhs_location); }
     break;
 
-  case 76:
+  case 75:
 /* Line 1270 of yacc.c.  */
-#line 469 "parse-gram.y"
+#line 451 "../../src/parse-gram.y"
     { grammar_current_rule_symbol_append ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)])); }
     break;
 
-  case 77:
+  case 76:
 /* Line 1270 of yacc.c.  */
-#line 471 "parse-gram.y"
+#line 453 "../../src/parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])); }
     break;
 
-  case 78:
+  case 77:
 /* Line 1270 of yacc.c.  */
-#line 473 "parse-gram.y"
+#line 455 "../../src/parse-gram.y"
     { grammar_current_rule_prec_set ((yyvsp[(3) - (3)].symbol), (yylsp[(3) - (3)])); }
     break;
 
-  case 79:
+  case 78:
 /* Line 1270 of yacc.c.  */
-#line 475 "parse-gram.y"
+#line 457 "../../src/parse-gram.y"
     { grammar_current_rule_dprec_set ((yyvsp[(3) - (3)].integer), (yylsp[(3) - (3)])); }
     break;
 
-  case 80:
+  case 79:
 /* Line 1270 of yacc.c.  */
-#line 477 "parse-gram.y"
+#line 459 "../../src/parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[(3) - (3)].uniqstr), (yylsp[(3) - (3)])); }
     break;
 
-  case 81:
+  case 82:
+/* Line 1270 of yacc.c.  */
+#line 475 "../../src/parse-gram.y"
+    {
+      static char one[] = "1";
+      (yyval.chars) = one;
+    }
+    break;
+
+  case 84:
+/* Line 1270 of yacc.c.  */
+#line 485 "../../src/parse-gram.y"
+    {
+      (yyvsp[(1) - (1)].chars)[strlen ((yyvsp[(1) - (1)].chars)) - 1] = '\n';
+      (yyval.chars) = translate_code ((yyvsp[(1) - (1)].chars) + 1, (yylsp[(1) - (1)]));
+    }
+    break;
+
+  case 85:
 /* Line 1270 of yacc.c.  */
-#line 490 "parse-gram.y"
+#line 501 "../../src/parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
-  case 82:
+  case 86:
 /* Line 1270 of yacc.c.  */
-#line 492 "parse-gram.y"
+#line 503 "../../src/parse-gram.y"
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[(1) - (1)].character)), (yylsp[(1) - (1)]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[(1) - (1)]), false);
@@ -2299,30 +2312,24 @@ yyreduce:
     }
     break;
 
-  case 83:
+  case 87:
 /* Line 1270 of yacc.c.  */
-#line 500 "parse-gram.y"
+#line 511 "../../src/parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
-  case 86:
+  case 90:
 /* Line 1270 of yacc.c.  */
-#line 512 "parse-gram.y"
+#line 523 "../../src/parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[(1) - (1)].chars)), (yylsp[(1) - (1)]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[(1) - (1)]), false);
     }
     break;
 
-  case 87:
+  case 92:
 /* Line 1270 of yacc.c.  */
-#line 521 "parse-gram.y"
-    { (yyval.chars) = (yyvsp[(1) - (1)].chars); }
-    break;
-
-  case 89:
-/* Line 1270 of yacc.c.  */
-#line 528 "parse-gram.y"
+#line 532 "../../src/parse-gram.y"
     {
       muscle_code_grow ("epilogue", translate_code ((yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])), (yylsp[(2) - (2)]));
       gram_scanner_last_string_free ();
@@ -2331,7 +2338,7 @@ yyreduce:
 
 
 /* Line 1270 of yacc.c.  */
-#line 2335 "parse-gram.c"
+#line 2342 "../../src/parse-gram.c"
       default: break;
     }
   YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);
@@ -2552,7 +2559,7 @@ yyreturn:
 
 
 /* Line 1490 of yacc.c.  */
-#line 534 "parse-gram.y"
+#line 538 "../../src/parse-gram.y"
 
 
 
@@ -2637,6 +2644,7 @@ add_param (char const *type, char *decl, location loc)
   gram_scanner_last_string_free ();
 }
 
+
 static void
 version_check (location const *loc, char const *version)
 {
