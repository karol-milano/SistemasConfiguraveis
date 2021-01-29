@@ -157,6 +157,7 @@ static char const *char_name (char);
 #  define PARAM_TYPE
   typedef enum
   {
+    param_none   = 0,
     param_lex    = 1 << 0,
     param_parse  = 1 << 1,
     param_both   = param_lex | param_parse
@@ -165,7 +166,7 @@ static char const *char_name (char);
 
 
 /* Line 211 of yacc.c  */
-#line 169 "src/parse-gram.c"
+#line 170 "src/parse-gram.c"
 
 /* Tokens.  */
 #ifndef YYTOKENTYPE
@@ -305,13 +306,13 @@ typedef union YYSTYPE
   unsigned char character;
 
 /* Line 216 of yacc.c  */
-#line 223 "src/parse-gram.y"
+#line 225 "src/parse-gram.y"
 
   param_type param;
 
 
 /* Line 216 of yacc.c  */
-#line 315 "src/parse-gram.c"
+#line 316 "src/parse-gram.c"
 } YYSTYPE;
 # define YYSTYPE_IS_TRIVIAL 1
 # define yystype YYSTYPE /* obsolescent; will be withdrawn */
@@ -335,17 +336,17 @@ typedef struct YYLTYPE
 /* Copy the second part of user declarations.  */
 
 /* Line 266 of yacc.c  */
-#line 339 "src/parse-gram.c"
+#line 340 "src/parse-gram.c"
 /* Unqualified %code blocks.  */
 /* Line 267 of yacc.c  */
 #line 56 "src/parse-gram.y"
 
-  static symbol_class current_class = unknown_sym;
-  static uniqstr current_type = NULL;
-  static symbol *current_lhs;
+  static int current_prec = 0;
   static location current_lhs_location;
   static named_ref *current_lhs_named_ref;
-  static int current_prec = 0;
+  static symbol *current_lhs;
+  static symbol_class current_class = unknown_sym;
+  static uniqstr current_type = NULL;
 
   #define YYTYPE_INT16 int_fast16_t
   #define YYTYPE_INT8 int_fast8_t
@@ -353,7 +354,7 @@ typedef struct YYLTYPE
   #define YYTYPE_UINT8 uint_fast8_t
 
 /* Line 267 of yacc.c  */
-#line 213 "src/parse-gram.y"
+#line 214 "src/parse-gram.y"
 
   /** Add a lex-param and/or a parse-param.
    *
@@ -362,10 +363,11 @@ typedef struct YYLTYPE
    * \param loc   the location in the source.
    */
   static void add_param (param_type type, char *decl, location loc);
+  static param_type current_param = param_none;
 
 
 /* Line 267 of yacc.c  */
-#line 369 "src/parse-gram.c"
+#line 371 "src/parse-gram.c"
 
 #ifdef short
 # undef short
@@ -587,11 +589,11 @@ union yyalloc
 /* YYNTOKENS -- Number of terminals.  */
 #define YYNTOKENS  56
 /* YYNNTS -- Number of nonterminals.  */
-#define YYNNTS  34
+#define YYNNTS  36
 /* YYNRULES -- Number of rules.  */
-#define YYNRULES  106
+#define YYNRULES  109
 /* YYNSTATES -- Number of states.  */
-#define YYNSTATES  145
+#define YYNSTATES  148
 
 /* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
    by yylex, with out-of-bounds checking.  */
@@ -643,17 +645,17 @@ static const yytype_uint8 yytranslate[] =
   /* YYRLINEYYN -- Source line where rule number YYN was defined.    */
 static const yytype_uint16 yyrline[] =
 {
-       0,   244,   244,   252,   254,   258,   259,   269,   273,   278,
-     279,   284,   289,   290,   291,   292,   293,   298,   307,   308,
-     309,   310,   311,   312,   313,   314,   315,   316,   340,   341,
-     342,   343,   352,   353,   354,   358,   365,   372,   376,   380,
-     387,   402,   403,   407,   419,   419,   424,   424,   429,   440,
-     455,   456,   457,   458,   462,   463,   468,   470,   475,   476,
-     481,   483,   488,   489,   493,   494,   495,   496,   501,   506,
-     511,   517,   523,   534,   535,   544,   545,   551,   552,   553,
-     560,   560,   565,   566,   567,   572,   574,   576,   578,   580,
-     582,   587,   589,   600,   601,   606,   607,   608,   617,   637,
-     639,   648,   653,   654,   659,   666,   668
+       0,   249,   249,   257,   259,   263,   264,   274,   278,   283,
+     284,   289,   294,   295,   296,   297,   298,   303,   312,   313,
+     314,   315,   316,   317,   318,   319,   319,   320,   321,   345,
+     346,   347,   348,   352,   353,   362,   363,   364,   368,   375,
+     382,   386,   390,   397,   412,   413,   417,   429,   429,   434,
+     434,   439,   450,   465,   466,   467,   468,   472,   473,   478,
+     480,   485,   486,   491,   493,   498,   499,   503,   504,   505,
+     506,   511,   516,   521,   527,   533,   544,   545,   554,   555,
+     561,   562,   563,   570,   570,   575,   576,   577,   582,   584,
+     586,   588,   590,   592,   597,   599,   610,   611,   616,   617,
+     618,   627,   647,   649,   658,   663,   664,   669,   676,   678
 };
 #endif
 
@@ -676,13 +678,14 @@ static const char *const yytname[] =
   "\"identifier\"", "\"identifier:\"", "\"%%\"", "\"|\"", "\"%{...%}\"",
   "\";\"", "\"<tag>\"", "\"<*>\"", "\"<>\"", "\"[identifier]\"",
   "\"%param\"", "\"%union\"", "$accept", "input", "prologue_declarations",
-  "prologue_declaration", "grammar_declaration", "union_name",
-  "symbol_declaration", "$@1", "$@2", "precedence_declaration",
-  "precedence_declarator", "tag.opt", "symbols.prec", "symbol.prec",
-  "symbols.1", "generic_symlist", "generic_symlist_item", "symbol_def",
-  "symbol_defs.1", "grammar", "rules_or_grammar_declaration", "rules",
-  "$@3", "rhses.1", "rhs", "named_ref.opt", "variable", "content.opt",
-  "braceless", "id", "id_colon", "symbol", "string_as_id", "epilogue.opt", 0
+  "prologue_declaration", "$@1", "params", "grammar_declaration",
+  "union_name", "symbol_declaration", "$@2", "$@3",
+  "precedence_declaration", "precedence_declarator", "tag.opt",
+  "symbols.prec", "symbol.prec", "symbols.1", "generic_symlist",
+  "generic_symlist_item", "symbol_def", "symbol_defs.1", "grammar",
+  "rules_or_grammar_declaration", "rules", "$@4", "rhses.1", "rhs",
+  "named_ref.opt", "variable", "content.opt", "braceless", "id",
+  "id_colon", "symbol", "string_as_id", "epilogue.opt", 0
 };
 #endif
 
@@ -705,7 +708,7 @@ static const yytype_uint16 yytoknum[] =
 #define yypact_value_is_default(yystate) \
   ((yystate) == (-88))
 
-#define YYTABLE_NINF -106
+#define YYTABLE_NINF -109
 
 #define yytable_value_is_error(yytable_value) \
   YYID (0)
@@ -714,21 +717,21 @@ static const yytype_uint16 yytoknum[] =
      STATE-NUM.    */
 static const yytype_int16 yypact[] =
 {
-     -88,    23,   109,   -88,   -88,   -88,   -15,    -8,     3,   -88,
-     -88,   -88,   -88,    -2,   -88,    14,    37,   -88,    45,    53,
-     -88,     2,   -88,    38,    81,    17,   -88,   -88,   -88,    30,
-      83,    84,    36,   -88,   -88,   -88,    58,   -88,   -88,    49,
-      46,   -88,   -88,   -88,   -88,    41,   -14,   -14,    36,     0,
+     -88,    38,   109,   -88,   -88,   -88,    -8,    13,    41,   -88,
+     -88,   -88,   -88,   -17,   -88,    14,    51,   -88,    53,    78,
+     -88,     2,   -88,    43,    81,    17,   -88,   -88,   -88,    30,
+      82,    83,    36,   -88,   -88,   -88,    58,   -88,   -88,   -88,
+      45,   -88,   -88,   -88,   -88,    40,    -1,    -1,    36,     0,
        0,   -88,    52,   -88,   -88,   -88,    18,   -88,   -88,   -88,
-     -88,    90,   -88,   -88,   -88,    92,   -88,    93,   -88,   -88,
-     -88,   -88,   -88,   -88,   -88,   -88,    48,   -88,    51,     1,
-     -88,   -88,    55,   -88,   -88,    52,   -88,    36,   -88,   -88,
-     -14,    50,   -14,    36,   -88,   -88,   -88,   -88,     0,   -88,
+     -88,    88,   -88,   -88,   -88,    90,   -88,    92,   -88,   -88,
+     -88,   -88,   -88,   -88,   -88,   -88,    47,   -88,    48,     1,
+     -88,   -88,    46,    60,   -88,    52,   -88,    36,   -88,   -88,
+      -1,    31,    -1,    36,   -88,   -88,   -88,   -88,     0,   -88,
      -88,     0,   -88,   -88,   -88,   -88,   -88,   -88,   -88,   -88,
-     -88,    56,   -88,   -88,   -88,   -88,   -88,    36,   -88,    97,
-     -88,   101,   -88,   -88,   -88,   -88,   -88,   -88,   -88,   -88,
-     -23,   146,   -88,   -88,    36,   102,    59,    55,    55,   146,
-     -88,   -88,   -88,   -88,   -88
+     -88,    56,   -88,   -88,   -88,   -88,   -88,    61,   -88,    36,
+     -88,   100,   -88,   103,   -88,   -88,   -88,   -88,   -88,   -88,
+     -88,   -88,   -88,   -23,   146,   -88,   -88,    36,   104,    57,
+      46,    46,   146,   -88,   -88,   -88,   -88,   -88
 };
 
   /* YYDEFACT[S] -- default reduction number in state S.  Performed when
@@ -736,39 +739,39 @@ static const yytype_int16 yypact[] =
      is an error.    */
 static const yytype_uint8 yydefact[] =
 {
-       3,     0,     0,     1,    46,    44,     0,     0,     0,    50,
-      51,    52,    53,     0,    37,     0,     9,    11,     0,     0,
-       7,     0,    16,     0,     0,     0,    38,    21,    22,     0,
-       0,     0,     0,    28,    29,    30,     0,     6,    31,     0,
-      41,     4,     5,    33,    32,    54,     0,     0,     0,     0,
-       0,    98,     0,    39,    94,    93,    95,    10,    12,    13,
-      14,     0,    17,    18,    19,     0,    23,     0,    26,    27,
-     104,   100,    99,   102,    34,   103,     0,   101,     0,     0,
-      75,    77,    91,    25,    42,     0,    55,     0,    68,    73,
-      47,    69,    45,    48,    60,    65,    66,    67,    35,    62,
-      64,    36,    40,    97,    96,     8,    15,    20,    24,    79,
-      78,     0,    76,     2,    92,    80,    43,    49,    56,    58,
-      74,    70,    71,    61,    63,   106,    85,    57,    59,    72,
-      81,    82,    85,    84,     0,     0,     0,    91,    91,    83,
-      88,    89,    90,    87,    86
+       3,     0,     0,     1,    49,    47,     0,     0,     0,    53,
+      54,    55,    56,     0,    40,     0,     9,    11,     0,     0,
+       7,     0,    16,     0,     0,     0,    41,    21,    22,     0,
+       0,     0,     0,    29,    30,    31,     0,     6,    32,    25,
+      44,     4,     5,    36,    35,    57,     0,     0,     0,     0,
+       0,   101,     0,    42,    97,    96,    98,    10,    12,    13,
+      14,     0,    17,    18,    19,     0,    23,     0,    27,    28,
+     107,   103,   102,   105,    37,   106,     0,   104,     0,     0,
+      78,    80,    94,     0,    45,     0,    58,     0,    71,    76,
+      50,    72,    48,    51,    63,    68,    69,    70,    38,    65,
+      67,    39,    43,   100,    99,     8,    15,    20,    24,    82,
+      81,     0,    79,     2,    95,    83,    34,    26,    46,    52,
+      59,    61,    77,    73,    74,    64,    66,   109,    88,    33,
+      60,    62,    75,    84,    85,    88,    87,     0,     0,     0,
+      94,    94,    86,    91,    92,    93,    90,    89
 };
 
   /* YYPGOTO[NTERM-NUM].    */
 static const yytype_int8 yypgoto[] =
 {
-     -88,   -88,   -88,   -88,   103,   -88,   -88,   -88,   -88,   -88,
-     -88,   -88,   -88,    -7,   -88,    61,   -76,   -11,    65,   -88,
-      44,   -88,   -88,   -88,    19,   -55,   -88,   -88,   -37,   -18,
-     -88,   -32,   -87,   -88
+     -88,   -88,   -88,   -88,   -88,   -88,   107,   -88,   -88,   -88,
+     -88,   -88,   -88,   -88,   -88,    -7,   -88,    73,   -76,   -60,
+      64,   -88,    71,   -88,   -88,   -88,   -11,   -62,   -88,   -88,
+     -37,   -18,   -88,   -32,   -87,   -88
 };
 
   /* YYDEFGOTO[NTERM-NUM].    */
 static const yytype_int16 yydefgoto[] =
 {
-      -1,     1,     2,    41,    78,    85,    43,    47,    46,    44,
-      45,    87,   117,   118,    93,    98,    99,    89,    90,    79,
-      80,    81,   126,   130,   131,   115,    56,   105,    53,    73,
-      82,   100,    75,   113
+      -1,     1,     2,    41,    83,   117,    78,    85,    43,    47,
+      46,    44,    45,    87,   119,   120,    93,    98,    99,    89,
+      90,    79,    80,    81,   128,   133,   134,   115,    56,   105,
+      53,    73,    82,   100,    75,   113
 };
 
   /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
@@ -776,25 +779,25 @@ static const yytype_int16 yydefgoto[] =
      number is the opposite.  If YYTABLE_NINF, syntax error.    */
 static const yytype_int16 yytable[] =
 {
-      74,  -105,    76,    70,   122,    60,     4,     5,     6,     7,
+      74,  -108,    76,    70,   124,    60,     4,     5,     6,     7,
        8,     9,    10,    11,    12,   102,    94,    54,    13,    14,
-      64,   103,   124,     3,   132,   124,   133,    71,    91,    91,
-      72,    26,    49,    66,   129,    48,    88,    32,    51,    70,
-      57,    71,    52,    50,    72,    61,    77,   111,   116,    58,
-      95,    96,    97,    70,   121,   119,    40,    59,    55,    76,
-      65,   123,   104,     4,     5,     6,     7,     8,     9,    10,
-      11,    12,    91,    67,    91,    13,    14,    71,    62,   120,
-      72,   120,   143,   144,    63,   119,    68,    69,    26,    83,
-      84,    86,    51,   106,    32,   107,   108,   109,   125,   138,
-     110,   128,   140,    77,    70,    42,   141,   138,   114,   142,
-     127,   101,    92,    40,     4,     5,     6,     7,     8,     9,
-      10,    11,    12,   112,     0,     0,    13,    14,    15,    16,
+      64,   103,   126,    51,   135,   126,   136,    52,    91,    91,
+     122,    26,   122,    66,    70,   123,   132,    32,     3,    70,
+      71,    71,    48,    72,    72,    61,    77,   111,   118,    88,
+      95,    96,    97,    49,    57,   121,    40,    58,    55,    76,
+      65,   125,   104,     4,     5,     6,     7,     8,     9,    10,
+      11,    12,    91,    67,    91,    13,    14,    71,   146,   147,
+      72,    50,    59,    62,    63,    68,    69,   121,    26,    84,
+      86,   106,    51,   107,    32,   108,   109,   110,   127,   114,
+     116,   129,   141,    77,   131,   143,    70,   145,   144,    42,
+     141,    92,   130,    40,     4,     5,     6,     7,     8,     9,
+      10,    11,    12,   101,   142,     0,    13,    14,    15,    16,
       17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
       27,    28,    29,    30,    31,    32,    33,    34,    35,    70,
-       0,   139,     0,     0,     0,    36,     0,    37,    38,     0,
-     134,   135,   136,    39,    40,     0,     0,     0,     0,     0,
+     112,     0,     0,     0,     0,    36,     0,    37,    38,     0,
+     137,   138,   139,    39,    40,     0,     0,     0,     0,     0,
        0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
-       0,     0,     0,     0,     0,     0,   137,    71,     0,     0,
+       0,     0,     0,     0,     0,     0,   140,    71,     0,     0,
       72
 };
 
@@ -802,20 +805,20 @@ static const yytype_int16 yycheck[] =
 {
       32,     0,     1,     3,    91,     3,     5,     6,     7,     8,
        9,    10,    11,    12,    13,    52,    48,     3,    17,    18,
-       3,     3,    98,     0,    47,   101,    49,    41,    46,    47,
-      44,    30,    40,     3,   121,    50,    50,    36,    40,     3,
-       3,    41,    44,    40,    44,    43,    45,    46,    85,     4,
-      50,    51,    52,     3,     4,    87,    55,     4,    44,     1,
+       3,     3,    98,    40,    47,   101,    49,    44,    46,    47,
+      90,    30,    92,     3,     3,     4,   123,    36,     0,     3,
+      41,    41,    50,    44,    44,    43,    45,    46,    85,    50,
+      50,    51,    52,    40,     3,    87,    55,     4,    44,     1,
       43,    93,    44,     5,     6,     7,     8,     9,    10,    11,
-      12,    13,    90,    43,    92,    17,    18,    41,    40,    90,
-      44,    92,   137,   138,     3,   117,     3,     3,    30,    40,
-      44,    50,    40,     3,    36,     3,     3,    49,    42,   131,
-      49,     4,   134,    45,     3,     2,     4,   139,    53,    50,
-     117,    50,    47,    55,     5,     6,     7,     8,     9,    10,
-      11,    12,    13,    79,    -1,    -1,    17,    18,    19,    20,
+      12,    13,    90,    43,    92,    17,    18,    41,   140,   141,
+      44,    40,     4,    40,     3,     3,     3,   119,    30,    44,
+      50,     3,    40,     3,    36,     3,    49,    49,    42,    53,
+      40,    40,   134,    45,     4,   137,     3,    50,     4,     2,
+     142,    47,   119,    55,     5,     6,     7,     8,     9,    10,
+      11,    12,    13,    50,   135,    -1,    17,    18,    19,    20,
       21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
       31,    32,    33,    34,    35,    36,    37,    38,    39,     3,
-      -1,   132,    -1,    -1,    -1,    46,    -1,    48,    49,    -1,
+      79,    -1,    -1,    -1,    -1,    46,    -1,    48,    49,    -1,
       14,    15,    16,    54,    55,    -1,    -1,    -1,    -1,    -1,
       -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       -1,    -1,    -1,    -1,    -1,    -1,    40,    41,    -1,    -1,
@@ -830,17 +833,17 @@ static const yytype_uint8 yystos[] =
       11,    12,    13,    17,    18,    19,    20,    21,    22,    23,
       24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
       34,    35,    36,    37,    38,    39,    46,    48,    49,    54,
-      55,    59,    60,    62,    65,    66,    64,    63,    50,    40,
-      40,    40,    44,    84,     3,    44,    82,     3,     4,     4,
+      55,    59,    62,    64,    67,    68,    66,    65,    50,    40,
+      40,    40,    44,    86,     3,    44,    84,     3,     4,     4,
        3,    43,    40,     3,     3,    43,     3,    43,     3,     3,
-       3,    41,    44,    85,    87,    88,     1,    45,    60,    75,
-      76,    77,    86,    40,    44,    61,    50,    67,    50,    73,
-      74,    85,    74,    70,    87,    50,    51,    52,    71,    72,
-      87,    71,    84,     3,    44,    83,     3,     3,     3,    49,
-      49,    46,    76,    89,    53,    81,    84,    68,    69,    87,
-      73,     4,    88,    87,    72,    42,    78,    69,     4,    88,
-      79,    80,    47,    49,    14,    15,    16,    40,    87,    80,
-      87,     4,    50,    81,    81
+       3,    41,    44,    87,    89,    90,     1,    45,    62,    77,
+      78,    79,    88,    60,    44,    63,    50,    69,    50,    75,
+      76,    87,    76,    72,    89,    50,    51,    52,    73,    74,
+      89,    73,    86,     3,    44,    85,     3,     3,     3,    49,
+      49,    46,    78,    91,    53,    83,    40,    61,    86,    70,
+      71,    89,    75,     4,    90,    89,    74,    42,    80,    40,
+      71,     4,    90,    81,    82,    47,    49,    14,    15,    16,
+      40,    89,    82,    89,     4,    50,    83,    83
 };
 
   /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.    */
@@ -848,15 +851,15 @@ static const yytype_uint8 yyr1[] =
 {
        0,    56,    57,    58,    58,    59,    59,    59,    59,    59,
       59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
-      59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
-      59,    59,    60,    60,    60,    60,    60,    60,    60,    60,
-      60,    61,    61,    60,    63,    62,    64,    62,    62,    65,
-      66,    66,    66,    66,    67,    67,    68,    68,    69,    69,
-      70,    70,    71,    71,    72,    72,    72,    72,    73,    73,
-      73,    73,    73,    74,    74,    75,    75,    76,    76,    76,
-      78,    77,    79,    79,    79,    80,    80,    80,    80,    80,
-      80,    81,    81,    82,    82,    83,    83,    83,    84,    85,
-      85,    86,    87,    87,    88,    89,    89
+      59,    59,    59,    59,    59,    60,    59,    59,    59,    59,
+      59,    59,    59,    61,    61,    62,    62,    62,    62,    62,
+      62,    62,    62,    62,    63,    63,    62,    65,    64,    66,
+      64,    64,    67,    68,    68,    68,    68,    69,    69,    70,
+      70,    71,    71,    72,    72,    73,    73,    74,    74,    74,
+      74,    75,    75,    75,    75,    75,    76,    76,    77,    77,
+      78,    78,    78,    80,    79,    81,    81,    81,    82,    82,
+      82,    82,    82,    82,    83,    83,    84,    84,    85,    85,
+      85,    86,    87,    87,    88,    89,    89,    90,    91,    91
 };
 
   /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.    */
@@ -864,15 +867,15 @@ static const yytype_uint8 yyr2[] =
 {
        0,     2,     4,     0,     2,     1,     1,     1,     3,     1,
        2,     1,     2,     2,     2,     3,     1,     2,     2,     2,
-       3,     1,     1,     2,     3,     2,     2,     2,     1,     1,
-       1,     1,     1,     1,     2,     3,     3,     1,     1,     2,
-       3,     0,     1,     3,     0,     3,     0,     3,     3,     3,
-       1,     1,     1,     1,     0,     1,     1,     2,     1,     2,
-       1,     2,     1,     2,     1,     1,     1,     1,     1,     1,
-       2,     2,     3,     1,     2,     1,     2,     1,     2,     2,
-       0,     4,     1,     3,     2,     0,     3,     3,     3,     3,
-       3,     0,     1,     1,     1,     0,     1,     1,     1,     1,
-       1,     1,     1,     1,     1,     0,     2
+       3,     1,     1,     2,     3,     0,     3,     2,     2,     1,
+       1,     1,     1,     2,     1,     1,     1,     2,     3,     3,
+       1,     1,     2,     3,     0,     1,     3,     0,     3,     0,
+       3,     3,     3,     1,     1,     1,     1,     0,     1,     1,
+       2,     1,     2,     1,     2,     1,     2,     1,     1,     1,
+       1,     1,     1,     2,     2,     3,     1,     2,     1,     2,
+       1,     2,     2,     0,     4,     1,     3,     2,     0,     3,
+       3,     3,     3,     3,     0,     1,     1,     1,     0,     1,
+       1,     1,     1,     1,     1,     1,     1,     1,     0,     2
 };
 
 
@@ -1027,7 +1030,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 #line 175 "src/parse-gram.y"
         { fputs (quotearg_style (c_quoting_style, ((*yyvaluep).chars)), stderr); }
 /* Line 653 of yacc.c  */
-#line 1031 "src/parse-gram.c"
+#line 1034 "src/parse-gram.c"
         break;
 
             case 4: // "integer"
@@ -1036,7 +1039,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 #line 188 "src/parse-gram.y"
         { fprintf (stderr, "%d", ((*yyvaluep).integer)); }
 /* Line 653 of yacc.c  */
-#line 1040 "src/parse-gram.c"
+#line 1043 "src/parse-gram.c"
         break;
 
             case 24: // "%<flag>"
@@ -1045,7 +1048,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 #line 184 "src/parse-gram.y"
         { fprintf (stderr, "%%%s", ((*yyvaluep).uniqstr)); }
 /* Line 653 of yacc.c  */
-#line 1049 "src/parse-gram.c"
+#line 1052 "src/parse-gram.c"
         break;
 
             case 40: // "{...}"
@@ -1054,7 +1057,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 #line 177 "src/parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).code)); }
 /* Line 653 of yacc.c  */
-#line 1058 "src/parse-gram.c"
+#line 1061 "src/parse-gram.c"
         break;
 
             case 41: // "char"
@@ -1063,7 +1066,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 #line 169 "src/parse-gram.y"
         { fputs (char_name (((*yyvaluep).character)), stderr); }
 /* Line 653 of yacc.c  */
-#line 1067 "src/parse-gram.c"
+#line 1070 "src/parse-gram.c"
         break;
 
             case 42: // "epilogue"
@@ -1072,7 +1075,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 #line 177 "src/parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); }
 /* Line 653 of yacc.c  */
-#line 1076 "src/parse-gram.c"
+#line 1079 "src/parse-gram.c"
         break;
 
             case 44: // "identifier"
@@ -1081,7 +1084,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 #line 182 "src/parse-gram.y"
         { fputs (((*yyvaluep).uniqstr), stderr); }
 /* Line 653 of yacc.c  */
-#line 1085 "src/parse-gram.c"
+#line 1088 "src/parse-gram.c"
         break;
 
             case 45: // "identifier:"
@@ -1090,7 +1093,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 #line 183 "src/parse-gram.y"
         { fprintf (stderr, "%s:", ((*yyvaluep).uniqstr)); }
 /* Line 653 of yacc.c  */
-#line 1094 "src/parse-gram.c"
+#line 1097 "src/parse-gram.c"
         break;
 
             case 48: // "%{...%}"
@@ -1099,7 +1102,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 #line 177 "src/parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); }
 /* Line 653 of yacc.c  */
-#line 1103 "src/parse-gram.c"
+#line 1106 "src/parse-gram.c"
         break;
 
             case 50: // "<tag>"
@@ -1108,90 +1111,89 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 #line 185 "src/parse-gram.y"
         { fprintf (stderr, "<%s>", ((*yyvaluep).uniqstr)); }
 /* Line 653 of yacc.c  */
-#line 1112 "src/parse-gram.c"
+#line 1115 "src/parse-gram.c"
         break;
 
             case 54: // "%param"
 
 /* Line 653 of yacc.c  */
-#line 228 "src/parse-gram.y"
+#line 230 "src/parse-gram.y"
         {
   switch (((*yyvaluep).param))
     {
 #define CASE(In, Out)                                           \
-      case param_ ## In:   fputs ("%" #Out, stderr); break
-
+      case param_ ## In: fputs ("%" #Out, stderr); break
       CASE(lex,   lex-param);
       CASE(parse, parse-param);
       CASE(both,  param);
-    }
 #undef CASE
+    }
 }
 /* Line 653 of yacc.c  */
-#line 1132 "src/parse-gram.c"
+#line 1134 "src/parse-gram.c"
         break;
 
-            case 82: // variable
+            case 84: // variable
 
 /* Line 653 of yacc.c  */
 #line 182 "src/parse-gram.y"
         { fputs (((*yyvaluep).uniqstr), stderr); }
 /* Line 653 of yacc.c  */
-#line 1141 "src/parse-gram.c"
+#line 1143 "src/parse-gram.c"
         break;
 
-            case 83: // content.opt
+            case 85: // content.opt
 
 /* Line 653 of yacc.c  */
 #line 177 "src/parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); }
 /* Line 653 of yacc.c  */
-#line 1150 "src/parse-gram.c"
+#line 1152 "src/parse-gram.c"
         break;
 
-            case 84: // braceless
+            case 86: // braceless
 
 /* Line 653 of yacc.c  */
 #line 177 "src/parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); }
 /* Line 653 of yacc.c  */
-#line 1159 "src/parse-gram.c"
+#line 1161 "src/parse-gram.c"
         break;
 
-            case 85: // id
+            case 87: // id
 
 /* Line 653 of yacc.c  */
 #line 191 "src/parse-gram.y"
         { fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); }
 /* Line 653 of yacc.c  */
-#line 1168 "src/parse-gram.c"
+#line 1170 "src/parse-gram.c"
         break;
 
-            case 86: // id_colon
+            case 88: // id_colon
 
 /* Line 653 of yacc.c  */
 #line 192 "src/parse-gram.y"
         { fprintf (stderr, "%s:", ((*yyvaluep).symbol)->tag); }
 /* Line 653 of yacc.c  */
-#line 1177 "src/parse-gram.c"
+#line 1179 "src/parse-gram.c"
         break;
 
-            case 87: // symbol
+            case 89: // symbol
 
 /* Line 653 of yacc.c  */
 #line 191 "src/parse-gram.y"
         { fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); }
 /* Line 653 of yacc.c  */
-#line 1186 "src/parse-gram.c"
+#line 1188 "src/parse-gram.c"
         break;
 
-            case 88: // string_as_id
+            case 90: // string_as_id
 
 /* Line 653 of yacc.c  */
 #line 191 "src/parse-gram.y"
         { fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); }
 /* Line 653 of yacc.c  */
-#line 1195 "src/parse-gram.c"
+#line 1197 "src/parse-gram.c"
         break;
 
       default:
@@ -1715,7 +1717,7 @@ YYLTYPE yylloc;
   boundary_set (&yylloc.end, current_file, 1, 1);
 }
 /* Line 1175 of yacc.c  */
-#line 1719 "src/parse-gram.c"
+#line 1721 "src/parse-gram.c"
   yylsp[0] = yylloc;
 
   goto yysetstate;
@@ -1902,7 +1904,7 @@ yyreduce:
     {
         case 6:
 /* Line 1388 of yacc.c  */
-#line 260 "src/parse-gram.y"
+#line 265 "src/parse-gram.y"
     {
       code_props plain_code;
       code_props_plain_init (&plain_code, (yyvsp[0].chars), (yylsp[0]));
@@ -1913,106 +1915,106 @@ yyreduce:
       code_scanner_last_string_free ();
     }
 /* Line 1388 of yacc.c  */
-#line 1917 "src/parse-gram.c"
+#line 1919 "src/parse-gram.c"
     break;
 
   case 7:
 /* Line 1388 of yacc.c  */
-#line 270 "src/parse-gram.y"
+#line 275 "src/parse-gram.y"
     {
       muscle_percent_define_ensure ((yyvsp[0].uniqstr), (yylsp[0]), true);
     }
 /* Line 1388 of yacc.c  */
-#line 1927 "src/parse-gram.c"
+#line 1929 "src/parse-gram.c"
     break;
 
   case 8:
 /* Line 1388 of yacc.c  */
-#line 274 "src/parse-gram.y"
+#line 279 "src/parse-gram.y"
     {
       muscle_percent_define_insert ((yyvsp[-1].uniqstr), (yylsp[-1]), (yyvsp[0].chars),
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
     }
 /* Line 1388 of yacc.c  */
-#line 1938 "src/parse-gram.c"
+#line 1940 "src/parse-gram.c"
     break;
 
   case 9:
 /* Line 1388 of yacc.c  */
-#line 278 "src/parse-gram.y"
+#line 283 "src/parse-gram.y"
     { defines_flag = true; }
 /* Line 1388 of yacc.c  */
-#line 1946 "src/parse-gram.c"
+#line 1948 "src/parse-gram.c"
     break;
 
   case 10:
 /* Line 1388 of yacc.c  */
-#line 280 "src/parse-gram.y"
+#line 285 "src/parse-gram.y"
     {
       defines_flag = true;
       spec_defines_file = xstrdup ((yyvsp[0].chars));
     }
 /* Line 1388 of yacc.c  */
-#line 1957 "src/parse-gram.c"
+#line 1959 "src/parse-gram.c"
     break;
 
   case 11:
 /* Line 1388 of yacc.c  */
-#line 285 "src/parse-gram.y"
+#line 290 "src/parse-gram.y"
     {
       muscle_percent_define_insert ("parse.error", (yylsp[0]), "verbose",
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
     }
 /* Line 1388 of yacc.c  */
-#line 1968 "src/parse-gram.c"
+#line 1970 "src/parse-gram.c"
     break;
 
   case 12:
 /* Line 1388 of yacc.c  */
-#line 289 "src/parse-gram.y"
+#line 294 "src/parse-gram.y"
     { expected_sr_conflicts = (yyvsp[0].integer); }
 /* Line 1388 of yacc.c  */
-#line 1976 "src/parse-gram.c"
+#line 1978 "src/parse-gram.c"
     break;
 
   case 13:
 /* Line 1388 of yacc.c  */
-#line 290 "src/parse-gram.y"
+#line 295 "src/parse-gram.y"
     { expected_rr_conflicts = (yyvsp[0].integer); }
 /* Line 1388 of yacc.c  */
-#line 1984 "src/parse-gram.c"
+#line 1986 "src/parse-gram.c"
     break;
 
   case 14:
 /* Line 1388 of yacc.c  */
-#line 291 "src/parse-gram.y"
+#line 296 "src/parse-gram.y"
     { spec_file_prefix = (yyvsp[0].chars); }
 /* Line 1388 of yacc.c  */
-#line 1992 "src/parse-gram.c"
+#line 1994 "src/parse-gram.c"
     break;
 
   case 15:
 /* Line 1388 of yacc.c  */
-#line 292 "src/parse-gram.y"
+#line 297 "src/parse-gram.y"
     { spec_file_prefix = (yyvsp[0].chars); }
 /* Line 1388 of yacc.c  */
-#line 2000 "src/parse-gram.c"
+#line 2002 "src/parse-gram.c"
     break;
 
   case 16:
 /* Line 1388 of yacc.c  */
-#line 294 "src/parse-gram.y"
+#line 299 "src/parse-gram.y"
     {
       nondeterministic_parser = true;
       glr_parser = true;
     }
 /* Line 1388 of yacc.c  */
-#line 2011 "src/parse-gram.c"
+#line 2013 "src/parse-gram.c"
     break;
 
   case 17:
 /* Line 1388 of yacc.c  */
-#line 299 "src/parse-gram.y"
+#line 304 "src/parse-gram.y"
     {
       code_props action;
       code_props_symbol_action_init (&action, (yyvsp[0].code), (yylsp[0]));
@@ -2022,84 +2024,92 @@ yyreduce:
       code_scanner_last_string_free ();
     }
 /* Line 1388 of yacc.c  */
-#line 2026 "src/parse-gram.c"
+#line 2028 "src/parse-gram.c"
     break;
 
   case 18:
 /* Line 1388 of yacc.c  */
-#line 307 "src/parse-gram.y"
+#line 312 "src/parse-gram.y"
     { language_argmatch ((yyvsp[0].chars), grammar_prio, (yylsp[-1])); }
 /* Line 1388 of yacc.c  */
-#line 2034 "src/parse-gram.c"
+#line 2036 "src/parse-gram.c"
     break;
 
   case 19:
 /* Line 1388 of yacc.c  */
-#line 308 "src/parse-gram.y"
+#line 313 "src/parse-gram.y"
     { spec_name_prefix = (yyvsp[0].chars); }
 /* Line 1388 of yacc.c  */
-#line 2042 "src/parse-gram.c"
+#line 2044 "src/parse-gram.c"
     break;
 
   case 20:
 /* Line 1388 of yacc.c  */
-#line 309 "src/parse-gram.y"
+#line 314 "src/parse-gram.y"
     { spec_name_prefix = (yyvsp[0].chars); }
 /* Line 1388 of yacc.c  */
-#line 2050 "src/parse-gram.c"
+#line 2052 "src/parse-gram.c"
     break;
 
   case 21:
 /* Line 1388 of yacc.c  */
-#line 310 "src/parse-gram.y"
+#line 315 "src/parse-gram.y"
     { no_lines_flag = true; }
 /* Line 1388 of yacc.c  */
-#line 2058 "src/parse-gram.c"
+#line 2060 "src/parse-gram.c"
     break;
 
   case 22:
 /* Line 1388 of yacc.c  */
-#line 311 "src/parse-gram.y"
+#line 316 "src/parse-gram.y"
     { nondeterministic_parser = true; }
 /* Line 1388 of yacc.c  */
-#line 2066 "src/parse-gram.c"
+#line 2068 "src/parse-gram.c"
     break;
 
   case 23:
 /* Line 1388 of yacc.c  */
-#line 312 "src/parse-gram.y"
+#line 317 "src/parse-gram.y"
     { spec_outfile = (yyvsp[0].chars); }
 /* Line 1388 of yacc.c  */
-#line 2074 "src/parse-gram.c"
+#line 2076 "src/parse-gram.c"
     break;
 
   case 24:
 /* Line 1388 of yacc.c  */
-#line 313 "src/parse-gram.y"
+#line 318 "src/parse-gram.y"
     { spec_outfile = (yyvsp[0].chars); }
 /* Line 1388 of yacc.c  */
-#line 2082 "src/parse-gram.c"
+#line 2084 "src/parse-gram.c"
     break;
 
   case 25:
 /* Line 1388 of yacc.c  */
-#line 314 "src/parse-gram.y"
-    { add_param ((yyvsp[-1].param), (yyvsp[0].code), (yylsp[0])); }
+#line 319 "src/parse-gram.y"
+    { current_param = (yyvsp[0].param); }
 /* Line 1388 of yacc.c  */
-#line 2090 "src/parse-gram.c"
+#line 2092 "src/parse-gram.c"
     break;
 
   case 26:
 /* Line 1388 of yacc.c  */
-#line 315 "src/parse-gram.y"
-    { version_check (&(yylsp[0]), (yyvsp[0].chars)); }
+#line 319 "src/parse-gram.y"
+    { current_param = param_none; }
 /* Line 1388 of yacc.c  */
-#line 2098 "src/parse-gram.c"
+#line 2100 "src/parse-gram.c"
     break;
 
   case 27:
 /* Line 1388 of yacc.c  */
-#line 317 "src/parse-gram.y"
+#line 320 "src/parse-gram.y"
+    { version_check (&(yylsp[0]), (yyvsp[0].chars)); }
+/* Line 1388 of yacc.c  */
+#line 2108 "src/parse-gram.c"
+    break;
+
+  case 28:
+/* Line 1388 of yacc.c  */
+#line 322 "src/parse-gram.y"
     {
       char const *skeleton_user = (yyvsp[0].chars);
       if (strchr (skeleton_user, '/'))
@@ -2124,46 +2134,62 @@ yyreduce:
       skeleton_arg (skeleton_user, grammar_prio, (yylsp[-1]));
     }
 /* Line 1388 of yacc.c  */
-#line 2128 "src/parse-gram.c"
+#line 2138 "src/parse-gram.c"
     break;
 
-  case 28:
+  case 29:
 /* Line 1388 of yacc.c  */
-#line 340 "src/parse-gram.y"
+#line 345 "src/parse-gram.y"
     { token_table_flag = true; }
 /* Line 1388 of yacc.c  */
-#line 2136 "src/parse-gram.c"
+#line 2146 "src/parse-gram.c"
     break;
 
-  case 29:
+  case 30:
 /* Line 1388 of yacc.c  */
-#line 341 "src/parse-gram.y"
+#line 346 "src/parse-gram.y"
     { report_flag |= report_states; }
 /* Line 1388 of yacc.c  */
-#line 2144 "src/parse-gram.c"
+#line 2154 "src/parse-gram.c"
     break;
 
-  case 30:
+  case 31:
 /* Line 1388 of yacc.c  */
-#line 342 "src/parse-gram.y"
+#line 347 "src/parse-gram.y"
     { yacc_flag = true; }
 /* Line 1388 of yacc.c  */
-#line 2152 "src/parse-gram.c"
+#line 2162 "src/parse-gram.c"
+    break;
+
+  case 33:
+/* Line 1388 of yacc.c  */
+#line 352 "src/parse-gram.y"
+    { add_param (current_param, (yyvsp[0].code), (yylsp[0])); }
+/* Line 1388 of yacc.c  */
+#line 2170 "src/parse-gram.c"
     break;
 
   case 34:
 /* Line 1388 of yacc.c  */
-#line 355 "src/parse-gram.y"
+#line 353 "src/parse-gram.y"
+    { add_param (current_param, (yyvsp[0].code), (yylsp[0])); }
+/* Line 1388 of yacc.c  */
+#line 2178 "src/parse-gram.c"
+    break;
+
+  case 37:
+/* Line 1388 of yacc.c  */
+#line 365 "src/parse-gram.y"
     {
       grammar_start_symbol_set ((yyvsp[0].symbol), (yylsp[0]));
     }
 /* Line 1388 of yacc.c  */
-#line 2162 "src/parse-gram.c"
+#line 2188 "src/parse-gram.c"
     break;
 
-  case 35:
+  case 38:
 /* Line 1388 of yacc.c  */
-#line 359 "src/parse-gram.y"
+#line 369 "src/parse-gram.y"
     {
       symbol_list *list;
       for (list = (yyvsp[0].list); list; list = list->next)
@@ -2171,12 +2197,12 @@ yyreduce:
       symbol_list_free ((yyvsp[0].list));
     }
 /* Line 1388 of yacc.c  */
-#line 2175 "src/parse-gram.c"
+#line 2201 "src/parse-gram.c"
     break;
 
-  case 36:
+  case 39:
 /* Line 1388 of yacc.c  */
-#line 366 "src/parse-gram.y"
+#line 376 "src/parse-gram.y"
     {
       symbol_list *list;
       for (list = (yyvsp[0].list); list; list = list->next)
@@ -2184,32 +2210,32 @@ yyreduce:
       symbol_list_free ((yyvsp[0].list));
     }
 /* Line 1388 of yacc.c  */
-#line 2188 "src/parse-gram.c"
+#line 2214 "src/parse-gram.c"
     break;
 
-  case 37:
+  case 40:
 /* Line 1388 of yacc.c  */
-#line 373 "src/parse-gram.y"
+#line 383 "src/parse-gram.y"
     {
       default_prec = true;
     }
 /* Line 1388 of yacc.c  */
-#line 2198 "src/parse-gram.c"
+#line 2224 "src/parse-gram.c"
     break;
 
-  case 38:
+  case 41:
 /* Line 1388 of yacc.c  */
-#line 377 "src/parse-gram.y"
+#line 387 "src/parse-gram.y"
     {
       default_prec = false;
     }
 /* Line 1388 of yacc.c  */
-#line 2208 "src/parse-gram.c"
+#line 2234 "src/parse-gram.c"
     break;
 
-  case 39:
+  case 42:
 /* Line 1388 of yacc.c  */
-#line 381 "src/parse-gram.y"
+#line 391 "src/parse-gram.y"
     {
       /* Do not invoke muscle_percent_code_grow here since it invokes
          muscle_user_name_list_grow.  */
@@ -2217,89 +2243,89 @@ yyreduce:
       code_scanner_last_string_free ();
     }
 /* Line 1388 of yacc.c  */
-#line 2221 "src/parse-gram.c"
+#line 2247 "src/parse-gram.c"
     break;
 
-  case 40:
+  case 43:
 /* Line 1388 of yacc.c  */
-#line 388 "src/parse-gram.y"
+#line 398 "src/parse-gram.y"
     {
       muscle_percent_code_grow ((yyvsp[-1].uniqstr), (yylsp[-1]), (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
 /* Line 1388 of yacc.c  */
-#line 2232 "src/parse-gram.c"
+#line 2258 "src/parse-gram.c"
     break;
 
-  case 41:
+  case 44:
 /* Line 1388 of yacc.c  */
-#line 402 "src/parse-gram.y"
+#line 412 "src/parse-gram.y"
     {}
 /* Line 1388 of yacc.c  */
-#line 2240 "src/parse-gram.c"
+#line 2266 "src/parse-gram.c"
     break;
 
-  case 42:
+  case 45:
 /* Line 1388 of yacc.c  */
-#line 403 "src/parse-gram.y"
+#line 413 "src/parse-gram.y"
     { muscle_code_grow ("union_name", (yyvsp[0].uniqstr), (yylsp[0])); }
 /* Line 1388 of yacc.c  */
-#line 2248 "src/parse-gram.c"
+#line 2274 "src/parse-gram.c"
     break;
 
-  case 43:
+  case 46:
 /* Line 1388 of yacc.c  */
-#line 408 "src/parse-gram.y"
+#line 418 "src/parse-gram.y"
     {
       union_seen = true;
       muscle_code_grow ("stype", (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
 /* Line 1388 of yacc.c  */
-#line 2260 "src/parse-gram.c"
+#line 2286 "src/parse-gram.c"
     break;
 
-  case 44:
+  case 47:
 /* Line 1388 of yacc.c  */
-#line 419 "src/parse-gram.y"
+#line 429 "src/parse-gram.y"
     { current_class = nterm_sym; }
 /* Line 1388 of yacc.c  */
-#line 2268 "src/parse-gram.c"
+#line 2294 "src/parse-gram.c"
     break;
 
-  case 45:
+  case 48:
 /* Line 1388 of yacc.c  */
-#line 420 "src/parse-gram.y"
+#line 430 "src/parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
 /* Line 1388 of yacc.c  */
-#line 2279 "src/parse-gram.c"
+#line 2305 "src/parse-gram.c"
     break;
 
-  case 46:
+  case 49:
 /* Line 1388 of yacc.c  */
-#line 424 "src/parse-gram.y"
+#line 434 "src/parse-gram.y"
     { current_class = token_sym; }
 /* Line 1388 of yacc.c  */
-#line 2287 "src/parse-gram.c"
+#line 2313 "src/parse-gram.c"
     break;
 
-  case 47:
+  case 50:
 /* Line 1388 of yacc.c  */
-#line 425 "src/parse-gram.y"
+#line 435 "src/parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
 /* Line 1388 of yacc.c  */
-#line 2298 "src/parse-gram.c"
+#line 2324 "src/parse-gram.c"
     break;
 
-  case 48:
+  case 51:
 /* Line 1388 of yacc.c  */
-#line 430 "src/parse-gram.y"
+#line 440 "src/parse-gram.y"
     {
       symbol_list *list;
       tag_seen = true;
@@ -2308,12 +2334,12 @@ yyreduce:
       symbol_list_free ((yyvsp[0].list));
     }
 /* Line 1388 of yacc.c  */
-#line 2312 "src/parse-gram.c"
+#line 2338 "src/parse-gram.c"
     break;
 
-  case 49:
+  case 52:
 /* Line 1388 of yacc.c  */
-#line 441 "src/parse-gram.y"
+#line 451 "src/parse-gram.y"
     {
       symbol_list *list;
       ++current_prec;
@@ -2326,202 +2352,202 @@ yyreduce:
       current_type = NULL;
     }
 /* Line 1388 of yacc.c  */
-#line 2330 "src/parse-gram.c"
+#line 2356 "src/parse-gram.c"
     break;
 
-  case 50:
+  case 53:
 /* Line 1388 of yacc.c  */
-#line 455 "src/parse-gram.y"
+#line 465 "src/parse-gram.y"
     { (yyval.assoc) = left_assoc; }
 /* Line 1388 of yacc.c  */
-#line 2338 "src/parse-gram.c"
+#line 2364 "src/parse-gram.c"
     break;
 
-  case 51:
+  case 54:
 /* Line 1388 of yacc.c  */
-#line 456 "src/parse-gram.y"
+#line 466 "src/parse-gram.y"
     { (yyval.assoc) = right_assoc; }
 /* Line 1388 of yacc.c  */
-#line 2346 "src/parse-gram.c"
+#line 2372 "src/parse-gram.c"
     break;
 
-  case 52:
+  case 55:
 /* Line 1388 of yacc.c  */
-#line 457 "src/parse-gram.y"
+#line 467 "src/parse-gram.y"
     { (yyval.assoc) = non_assoc; }
 /* Line 1388 of yacc.c  */
-#line 2354 "src/parse-gram.c"
+#line 2380 "src/parse-gram.c"
     break;
 
-  case 53:
+  case 56:
 /* Line 1388 of yacc.c  */
-#line 458 "src/parse-gram.y"
+#line 468 "src/parse-gram.y"
     { (yyval.assoc) = precedence_assoc; }
 /* Line 1388 of yacc.c  */
-#line 2362 "src/parse-gram.c"
+#line 2388 "src/parse-gram.c"
     break;
 
-  case 54:
+  case 57:
 /* Line 1388 of yacc.c  */
-#line 462 "src/parse-gram.y"
+#line 472 "src/parse-gram.y"
     { current_type = NULL; }
 /* Line 1388 of yacc.c  */
-#line 2370 "src/parse-gram.c"
+#line 2396 "src/parse-gram.c"
     break;
 
-  case 55:
+  case 58:
 /* Line 1388 of yacc.c  */
-#line 463 "src/parse-gram.y"
+#line 473 "src/parse-gram.y"
     { current_type = (yyvsp[0].uniqstr); tag_seen = true; }
 /* Line 1388 of yacc.c  */
-#line 2378 "src/parse-gram.c"
+#line 2404 "src/parse-gram.c"
     break;
 
-  case 56:
+  case 59:
 /* Line 1388 of yacc.c  */
-#line 469 "src/parse-gram.y"
+#line 479 "src/parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
 /* Line 1388 of yacc.c  */
-#line 2386 "src/parse-gram.c"
+#line 2412 "src/parse-gram.c"
     break;
 
-  case 57:
+  case 60:
 /* Line 1388 of yacc.c  */
-#line 471 "src/parse-gram.y"
+#line 481 "src/parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
 /* Line 1388 of yacc.c  */
-#line 2394 "src/parse-gram.c"
+#line 2420 "src/parse-gram.c"
     break;
 
-  case 58:
+  case 61:
 /* Line 1388 of yacc.c  */
-#line 475 "src/parse-gram.y"
+#line 485 "src/parse-gram.y"
     { (yyval.symbol) = (yyvsp[0].symbol); }
 /* Line 1388 of yacc.c  */
-#line 2402 "src/parse-gram.c"
+#line 2428 "src/parse-gram.c"
     break;
 
-  case 59:
+  case 62:
 /* Line 1388 of yacc.c  */
-#line 476 "src/parse-gram.y"
+#line 486 "src/parse-gram.y"
     { (yyval.symbol) = (yyvsp[-1].symbol); symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0])); }
 /* Line 1388 of yacc.c  */
-#line 2410 "src/parse-gram.c"
+#line 2436 "src/parse-gram.c"
     break;
 
-  case 60:
+  case 63:
 /* Line 1388 of yacc.c  */
-#line 482 "src/parse-gram.y"
+#line 492 "src/parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
 /* Line 1388 of yacc.c  */
-#line 2418 "src/parse-gram.c"
+#line 2444 "src/parse-gram.c"
     break;
 
-  case 61:
+  case 64:
 /* Line 1388 of yacc.c  */
-#line 484 "src/parse-gram.y"
+#line 494 "src/parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
 /* Line 1388 of yacc.c  */
-#line 2426 "src/parse-gram.c"
+#line 2452 "src/parse-gram.c"
     break;
 
-  case 62:
+  case 65:
 /* Line 1388 of yacc.c  */
-#line 488 "src/parse-gram.y"
+#line 498 "src/parse-gram.y"
     { (yyval.list) = (yyvsp[0].list); }
 /* Line 1388 of yacc.c  */
-#line 2434 "src/parse-gram.c"
+#line 2460 "src/parse-gram.c"
     break;
 
-  case 63:
+  case 66:
 /* Line 1388 of yacc.c  */
-#line 489 "src/parse-gram.y"
+#line 499 "src/parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), (yyvsp[0].list)); }
 /* Line 1388 of yacc.c  */
-#line 2442 "src/parse-gram.c"
+#line 2468 "src/parse-gram.c"
     break;
 
-  case 64:
+  case 67:
 /* Line 1388 of yacc.c  */
-#line 493 "src/parse-gram.y"
+#line 503 "src/parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
 /* Line 1388 of yacc.c  */
-#line 2450 "src/parse-gram.c"
+#line 2476 "src/parse-gram.c"
     break;
 
-  case 65:
+  case 68:
 /* Line 1388 of yacc.c  */
-#line 494 "src/parse-gram.y"
+#line 504 "src/parse-gram.y"
     { (yyval.list) = symbol_list_type_new ((yyvsp[0].uniqstr), (yylsp[0])); }
 /* Line 1388 of yacc.c  */
-#line 2458 "src/parse-gram.c"
+#line 2484 "src/parse-gram.c"
     break;
 
-  case 66:
+  case 69:
 /* Line 1388 of yacc.c  */
-#line 495 "src/parse-gram.y"
+#line 505 "src/parse-gram.y"
     { (yyval.list) = symbol_list_default_tagged_new ((yylsp[0])); }
 /* Line 1388 of yacc.c  */
-#line 2466 "src/parse-gram.c"
+#line 2492 "src/parse-gram.c"
     break;
 
-  case 67:
+  case 70:
 /* Line 1388 of yacc.c  */
-#line 496 "src/parse-gram.y"
+#line 506 "src/parse-gram.y"
     { (yyval.list) = symbol_list_default_tagless_new ((yylsp[0])); }
 /* Line 1388 of yacc.c  */
-#line 2474 "src/parse-gram.c"
+#line 2500 "src/parse-gram.c"
     break;
 
-  case 68:
+  case 71:
 /* Line 1388 of yacc.c  */
-#line 502 "src/parse-gram.y"
+#line 512 "src/parse-gram.y"
     {
        current_type = (yyvsp[0].uniqstr);
        tag_seen = true;
      }
 /* Line 1388 of yacc.c  */
-#line 2485 "src/parse-gram.c"
+#line 2511 "src/parse-gram.c"
     break;
 
-  case 69:
+  case 72:
 /* Line 1388 of yacc.c  */
-#line 507 "src/parse-gram.y"
+#line 517 "src/parse-gram.y"
     {
        symbol_class_set ((yyvsp[0].symbol), current_class, (yylsp[0]), true);
        symbol_type_set ((yyvsp[0].symbol), current_type, (yylsp[0]));
      }
 /* Line 1388 of yacc.c  */
-#line 2496 "src/parse-gram.c"
+#line 2522 "src/parse-gram.c"
     break;
 
-  case 70:
+  case 73:
 /* Line 1388 of yacc.c  */
-#line 512 "src/parse-gram.y"
+#line 522 "src/parse-gram.y"
     {
       symbol_class_set ((yyvsp[-1].symbol), current_class, (yylsp[-1]), true);
       symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
       symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0]));
     }
 /* Line 1388 of yacc.c  */
-#line 2508 "src/parse-gram.c"
+#line 2534 "src/parse-gram.c"
     break;
 
-  case 71:
+  case 74:
 /* Line 1388 of yacc.c  */
-#line 518 "src/parse-gram.y"
+#line 528 "src/parse-gram.y"
     {
       symbol_class_set ((yyvsp[-1].symbol), current_class, (yylsp[-1]), true);
       symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
       symbol_make_alias ((yyvsp[-1].symbol), (yyvsp[0].symbol), (yyloc));
     }
 /* Line 1388 of yacc.c  */
-#line 2520 "src/parse-gram.c"
+#line 2546 "src/parse-gram.c"
     break;
 
-  case 72:
+  case 75:
 /* Line 1388 of yacc.c  */
-#line 524 "src/parse-gram.y"
+#line 534 "src/parse-gram.y"
     {
       symbol_class_set ((yyvsp[-2].symbol), current_class, (yylsp[-2]), true);
       symbol_type_set ((yyvsp[-2].symbol), current_type, (yylsp[-2]));
@@ -2529,136 +2555,136 @@ yyreduce:
       symbol_make_alias ((yyvsp[-2].symbol), (yyvsp[0].symbol), (yyloc));
     }
 /* Line 1388 of yacc.c  */
-#line 2533 "src/parse-gram.c"
+#line 2559 "src/parse-gram.c"
     break;
 
-  case 79:
+  case 82:
 /* Line 1388 of yacc.c  */
-#line 554 "src/parse-gram.y"
+#line 564 "src/parse-gram.y"
     {
       yyerrok;
     }
 /* Line 1388 of yacc.c  */
-#line 2543 "src/parse-gram.c"
+#line 2569 "src/parse-gram.c"
     break;
 
-  case 80:
+  case 83:
 /* Line 1388 of yacc.c  */
-#line 560 "src/parse-gram.y"
+#line 570 "src/parse-gram.y"
     { current_lhs = (yyvsp[-1].symbol); current_lhs_location = (yylsp[-1]);
     current_lhs_named_ref = (yyvsp[0].named_ref); }
 /* Line 1388 of yacc.c  */
-#line 2552 "src/parse-gram.c"
+#line 2578 "src/parse-gram.c"
     break;
 
-  case 82:
+  case 85:
 /* Line 1388 of yacc.c  */
-#line 565 "src/parse-gram.y"
+#line 575 "src/parse-gram.y"
     { grammar_current_rule_end ((yylsp[0])); }
 /* Line 1388 of yacc.c  */
-#line 2560 "src/parse-gram.c"
+#line 2586 "src/parse-gram.c"
     break;
 
-  case 83:
+  case 86:
 /* Line 1388 of yacc.c  */
-#line 566 "src/parse-gram.y"
+#line 576 "src/parse-gram.y"
     { grammar_current_rule_end ((yylsp[0])); }
 /* Line 1388 of yacc.c  */
-#line 2568 "src/parse-gram.c"
+#line 2594 "src/parse-gram.c"
     break;
 
-  case 85:
+  case 88:
 /* Line 1388 of yacc.c  */
-#line 572 "src/parse-gram.y"
+#line 582 "src/parse-gram.y"
     { grammar_current_rule_begin (current_lhs, current_lhs_location,
 				  current_lhs_named_ref); }
 /* Line 1388 of yacc.c  */
-#line 2577 "src/parse-gram.c"
+#line 2603 "src/parse-gram.c"
     break;
 
-  case 86:
+  case 89:
 /* Line 1388 of yacc.c  */
-#line 575 "src/parse-gram.y"
+#line 585 "src/parse-gram.y"
     { grammar_current_rule_symbol_append ((yyvsp[-1].symbol), (yylsp[-1]), (yyvsp[0].named_ref)); }
 /* Line 1388 of yacc.c  */
-#line 2585 "src/parse-gram.c"
+#line 2611 "src/parse-gram.c"
     break;
 
-  case 87:
+  case 90:
 /* Line 1388 of yacc.c  */
-#line 577 "src/parse-gram.y"
+#line 587 "src/parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[-1].code), (yylsp[-1]), (yyvsp[0].named_ref)); }
 /* Line 1388 of yacc.c  */
-#line 2593 "src/parse-gram.c"
+#line 2619 "src/parse-gram.c"
     break;
 
-  case 88:
+  case 91:
 /* Line 1388 of yacc.c  */
-#line 579 "src/parse-gram.y"
+#line 589 "src/parse-gram.y"
     { grammar_current_rule_prec_set ((yyvsp[0].symbol), (yylsp[0])); }
 /* Line 1388 of yacc.c  */
-#line 2601 "src/parse-gram.c"
+#line 2627 "src/parse-gram.c"
     break;
 
-  case 89:
+  case 92:
 /* Line 1388 of yacc.c  */
-#line 581 "src/parse-gram.y"
+#line 591 "src/parse-gram.y"
     { grammar_current_rule_dprec_set ((yyvsp[0].integer), (yylsp[0])); }
 /* Line 1388 of yacc.c  */
-#line 2609 "src/parse-gram.c"
+#line 2635 "src/parse-gram.c"
     break;
 
-  case 90:
+  case 93:
 /* Line 1388 of yacc.c  */
-#line 583 "src/parse-gram.y"
+#line 593 "src/parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[0].uniqstr), (yylsp[0])); }
 /* Line 1388 of yacc.c  */
-#line 2617 "src/parse-gram.c"
+#line 2643 "src/parse-gram.c"
     break;
 
-  case 91:
+  case 94:
 /* Line 1388 of yacc.c  */
-#line 587 "src/parse-gram.y"
+#line 597 "src/parse-gram.y"
     { (yyval.named_ref) = 0; }
 /* Line 1388 of yacc.c  */
-#line 2625 "src/parse-gram.c"
+#line 2651 "src/parse-gram.c"
     break;
 
-  case 92:
+  case 95:
 /* Line 1388 of yacc.c  */
-#line 589 "src/parse-gram.y"
+#line 599 "src/parse-gram.y"
     { (yyval.named_ref) = named_ref_new((yyvsp[0].uniqstr), (yylsp[0])); }
 /* Line 1388 of yacc.c  */
-#line 2633 "src/parse-gram.c"
+#line 2659 "src/parse-gram.c"
     break;
 
-  case 94:
+  case 97:
 /* Line 1388 of yacc.c  */
-#line 601 "src/parse-gram.y"
+#line 611 "src/parse-gram.y"
     { (yyval.uniqstr) = uniqstr_new ((yyvsp[0].chars)); }
 /* Line 1388 of yacc.c  */
-#line 2641 "src/parse-gram.c"
+#line 2667 "src/parse-gram.c"
     break;
 
-  case 95:
+  case 98:
 /* Line 1388 of yacc.c  */
-#line 606 "src/parse-gram.y"
+#line 616 "src/parse-gram.y"
     { (yyval.chars) = ""; }
 /* Line 1388 of yacc.c  */
-#line 2649 "src/parse-gram.c"
+#line 2675 "src/parse-gram.c"
     break;
 
-  case 96:
+  case 99:
 /* Line 1388 of yacc.c  */
-#line 607 "src/parse-gram.y"
+#line 617 "src/parse-gram.y"
     { (yyval.chars) = (yyvsp[0].uniqstr); }
 /* Line 1388 of yacc.c  */
-#line 2657 "src/parse-gram.c"
+#line 2683 "src/parse-gram.c"
     break;
 
-  case 98:
+  case 101:
 /* Line 1388 of yacc.c  */
-#line 618 "src/parse-gram.y"
+#line 628 "src/parse-gram.y"
     {
       code_props plain_code;
       (yyvsp[0].code)[strlen ((yyvsp[0].code)) - 1] = '\n';
@@ -2668,51 +2694,51 @@ yyreduce:
       (yyval.chars) = plain_code.code;
     }
 /* Line 1388 of yacc.c  */
-#line 2672 "src/parse-gram.c"
+#line 2698 "src/parse-gram.c"
     break;
 
-  case 99:
+  case 102:
 /* Line 1388 of yacc.c  */
-#line 638 "src/parse-gram.y"
+#line 648 "src/parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
 /* Line 1388 of yacc.c  */
-#line 2680 "src/parse-gram.c"
+#line 2706 "src/parse-gram.c"
     break;
 
-  case 100:
+  case 103:
 /* Line 1388 of yacc.c  */
-#line 640 "src/parse-gram.y"
+#line 650 "src/parse-gram.y"
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[0].character)), (yylsp[0]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
       symbol_user_token_number_set ((yyval.symbol), (yyvsp[0].character), (yylsp[0]));
     }
 /* Line 1388 of yacc.c  */
-#line 2692 "src/parse-gram.c"
+#line 2718 "src/parse-gram.c"
     break;
 
-  case 101:
+  case 104:
 /* Line 1388 of yacc.c  */
-#line 648 "src/parse-gram.y"
+#line 658 "src/parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
 /* Line 1388 of yacc.c  */
-#line 2700 "src/parse-gram.c"
+#line 2726 "src/parse-gram.c"
     break;
 
-  case 104:
+  case 107:
 /* Line 1388 of yacc.c  */
-#line 660 "src/parse-gram.y"
+#line 670 "src/parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[0].chars)), (yylsp[0]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
     }
 /* Line 1388 of yacc.c  */
-#line 2711 "src/parse-gram.c"
+#line 2737 "src/parse-gram.c"
     break;
 
-  case 106:
+  case 109:
 /* Line 1388 of yacc.c  */
-#line 669 "src/parse-gram.y"
+#line 679 "src/parse-gram.y"
     {
       code_props plain_code;
       code_props_plain_init (&plain_code, (yyvsp[0].chars), (yylsp[0]));
@@ -2722,12 +2748,12 @@ yyreduce:
       code_scanner_last_string_free ();
     }
 /* Line 1388 of yacc.c  */
-#line 2726 "src/parse-gram.c"
+#line 2752 "src/parse-gram.c"
     break;
 
 
 /* Line 1388 of yacc.c  */
-#line 2731 "src/parse-gram.c"
+#line 2757 "src/parse-gram.c"
       default: break;
     }
   YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);
@@ -2944,7 +2970,7 @@ yyreturn:
 }
 
 /* Line 1607 of yacc.c  */
-#line 679 "src/parse-gram.y"
+#line 689 "src/parse-gram.y"
 
 
 
@@ -2986,23 +3012,25 @@ add_param (param_type type, char *decl, location loc)
     "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
     "_"
     "0123456789";
+
   char const *name_start = NULL;
-  char *p;
-
-  /* Stop on last actual character.  */
-  for (p = decl; p[1]; p++)
-    if ((p == decl
-	 || ! memchr (alphanum, p[-1], sizeof alphanum))
-	&& memchr (alphanum, p[0], sizeof alphanum - 10))
-      name_start = p;
-
-  /* Strip the surrounding '{' and '}', and any blanks just inside
-     the braces.  */
-  while (*--p == ' ' || *p == '\t')
-    continue;
-  p[1] = '\0';
-  while (*++decl == ' ' || *decl == '\t')
-    continue;
+  {
+    char *p;
+    /* Stop on last actual character.  */
+    for (p = decl; p[1]; p++)
+      if ((p == decl
+           || ! memchr (alphanum, p[-1], sizeof alphanum))
+          && memchr (alphanum, p[0], sizeof alphanum - 10))
+        name_start = p;
+
+    /* Strip the surrounding '{' and '}', and any blanks just inside
+       the braces.  */
+    while (*--p == ' ' || *p == '\t')
+      continue;
+    p[1] = '\0';
+    while (*++decl == ' ' || *decl == '\t')
+      continue;
+  }
 
   if (! name_start)
     complain_at (loc, _("missing identifier in parameter declaration"));
