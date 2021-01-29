@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 2.7.1081-93af.  */
+/* A Bison parser, made by GNU Bison 2.7.1087-c21e-dirty.  */
 
 /* Bison implementation for Yacc-like parsers in C
 
@@ -44,7 +44,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "2.7.1081-93af"
+#define YYBISON_VERSION "2.7.1087-c21e-dirty"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -235,7 +235,8 @@ extern int gram_debug;
     TAG_ANY = 308,
     TAG_NONE = 309,
     PERCENT_PARAM = 310,
-    PERCENT_UNION = 311
+    PERCENT_UNION = 311,
+    PERCENT_EMPTY = 312
   };
 #endif
 /* Tokens.  */
@@ -294,6 +295,7 @@ extern int gram_debug;
 #define TAG_NONE 309
 #define PERCENT_PARAM 310
 #define PERCENT_UNION 311
+#define PERCENT_EMPTY 312
 
 /* Value type.  */
 #if ! defined GRAM_STYPE && ! defined GRAM_STYPE_IS_DECLARED
@@ -319,7 +321,7 @@ union GRAM_STYPE
 #line 419 "src/parse-gram.y" /* yacc.c:373  */
 code_props_type code_type;
 
-#line 323 "src/parse-gram.c" /* yacc.c:373  */
+#line 325 "src/parse-gram.c" /* yacc.c:373  */
 };
 # define GRAM_STYPE_IS_TRIVIAL 1
 # define GRAM_STYPE_IS_DECLARED 1
@@ -347,7 +349,7 @@ int gram_parse (void);
 
 /* Copy the second part of user declarations.  */
 
-#line 351 "src/parse-gram.c" /* yacc.c:376  */
+#line 353 "src/parse-gram.c" /* yacc.c:376  */
 /* Unqualified %code blocks.  */
 #line 54 "src/parse-gram.y" /* yacc.c:377  */
 
@@ -393,7 +395,7 @@ int gram_parse (void);
   static param_type current_param = param_none;
 
 
-#line 397 "src/parse-gram.c" /* yacc.c:377  */
+#line 399 "src/parse-gram.c" /* yacc.c:377  */
 
 #ifdef short
 # undef short
@@ -567,21 +569,21 @@ union yyalloc
 /* YYFINAL -- State number of the termination state.  */
 #define YYFINAL  3
 /* YYLAST -- Last index in YYTABLE.  */
-#define YYLAST   157
+#define YYLAST   158
 
 /* YYNTOKENS -- Number of terminals.  */
-#define YYNTOKENS  57
+#define YYNTOKENS  58
 /* YYNNTS -- Number of nonterminals.  */
 #define YYNNTS  38
 /* YYNRULES -- Number of rules.  */
-#define YYNRULES  109
+#define YYNRULES  110
 /* YYNSTATES -- Number of states.  */
-#define YYNSTATES  143
+#define YYNSTATES  144
 
 /* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
    by yylex, with out-of-bounds checking.  */
 #define YYUNDEFTOK  2
-#define YYMAXUTOK   311
+#define YYMAXUTOK   312
 
 #define YYTRANSLATE(YYX)                                                \
   ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)
@@ -621,14 +623,14 @@ static const yytype_uint8 yytranslate[] =
       25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
       35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
       45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
-      55,    56
+      55,    56,    57
 };
 
 #if GRAM_DEBUG
   /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
 static const yytype_uint16 yyrline[] =
 {
-       0,   268,   268,   276,   278,   282,   283,   293,   297,   302,
+       0,   268,   268,   277,   278,   282,   283,   293,   297,   302,
      303,   308,   313,   314,   315,   316,   321,   330,   331,   332,
      333,   334,   335,   335,   336,   337,   361,   362,   363,   364,
      368,   369,   378,   379,   380,   384,   396,   400,   404,   411,
@@ -636,9 +638,10 @@ static const yytype_uint16 yyrline[] =
      471,   486,   487,   488,   489,   493,   494,   499,   501,   506,
      507,   512,   514,   519,   520,   524,   525,   529,   530,   531,
      536,   541,   546,   552,   558,   569,   570,   579,   580,   586,
-     587,   588,   595,   595,   603,   604,   605,   610,   612,   614,
-     616,   618,   620,   622,   627,   629,   639,   640,   645,   646,
-     647,   656,   676,   678,   687,   692,   693,   698,   705,   707
+     587,   588,   595,   595,   603,   604,   605,   610,   613,   615,
+     617,   619,   621,   623,   625,   630,   631,   641,   642,   647,
+     648,   649,   658,   678,   680,   689,   694,   695,   700,   708,
+     709
 };
 #endif
 
@@ -660,15 +663,16 @@ static const char *const yytname[] =
   "\"%yacc\"", "\"{...}\"", "\"%?{...}\"", "\"[identifier]\"", "\"char\"",
   "\"epilogue\"", "\"=\"", "\"identifier\"", "\"identifier:\"", "\"%%\"",
   "\"|\"", "\"%{...%}\"", "\";\"", "\"<tag>\"", "\"<*>\"", "\"<>\"",
-  "\"%param\"", "\"%union\"", "$accept", "input", "prologue_declarations",
-  "prologue_declaration", "$@1", "params", "grammar_declaration",
-  "code_props_type", "union_name", "symbol_declaration", "$@2", "$@3",
-  "precedence_declaration", "precedence_declarator", "tag.opt",
-  "symbols.prec", "symbol.prec", "symbols.1", "generic_symlist",
-  "generic_symlist_item", "tag", "symbol_def", "symbol_defs.1", "grammar",
-  "rules_or_grammar_declaration", "rules", "$@4", "rhses.1", "rhs",
-  "named_ref.opt", "variable", "content.opt", "braceless", "id",
-  "id_colon", "symbol", "string_as_id", "epilogue.opt", YY_NULL
+  "\"%param\"", "\"%union\"", "\"%empty\"", "$accept", "input",
+  "prologue_declarations", "prologue_declaration", "$@1", "params",
+  "grammar_declaration", "code_props_type", "union_name",
+  "symbol_declaration", "$@2", "$@3", "precedence_declaration",
+  "precedence_declarator", "tag.opt", "symbols.prec", "symbol.prec",
+  "symbols.1", "generic_symlist", "generic_symlist_item", "tag",
+  "symbol_def", "symbol_defs.1", "grammar", "rules_or_grammar_declaration",
+  "rules", "$@4", "rhses.1", "rhs", "named_ref.opt", "variable",
+  "content.opt", "braceless", "id", "id_colon", "symbol", "string_as_id",
+  "epilogue.opt", YY_NULL
 };
 #endif
 
@@ -682,16 +686,16 @@ static const yytype_uint16 yytoknum[] =
      275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
      285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
      295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
-     305,   306,   307,   308,   309,   310,   311
+     305,   306,   307,   308,   309,   310,   311,   312
 };
 # endif
 
-#define YYPACT_NINF -74
+#define YYPACT_NINF -99
 
 #define yypact_value_is_default(Yystate) \
-  (!!((Yystate) == (-74)))
+  (!!((Yystate) == (-99)))
 
-#define YYTABLE_NINF -109
+#define YYTABLE_NINF -110
 
 #define yytable_value_is_error(Yytable_value) \
   0
@@ -700,21 +704,21 @@ static const yytype_uint16 yytoknum[] =
      STATE-NUM.  */
 static const yytype_int16 yypact[] =
 {
-     -74,    40,   101,   -74,   -74,   -74,   -48,   -74,   -74,   -74,
-     -74,   -74,   -74,    19,   -74,     0,    52,   -74,    56,    79,
-     -74,    81,   -74,    45,    83,    84,   -74,   -74,   -74,    85,
-      86,    87,    31,   -74,   -74,   -74,    15,   -74,   -74,   -74,
-      46,   -74,   -74,    51,   -74,   -74,    42,     4,     4,    31,
-     -74,    57,   -74,   -74,   -74,    36,   -74,   -74,   -74,   -74,
-     -74,   -74,   -74,   -74,   -74,   -74,   -74,   -74,   -74,   -74,
-     -74,   -74,    47,   -74,    49,     1,   -74,   -74,    59,    62,
-     -74,    57,    26,   -74,    31,   -74,   -74,     4,    72,     4,
-      31,   -74,   -74,   -74,   -74,   -74,   -74,   -74,    60,   -74,
-     -74,   -74,   -74,   -74,    63,   -74,   -74,   -74,   -74,    26,
-     -74,   -74,   -74,    31,   -74,   111,   -74,   113,   -74,   -74,
-     -74,   -74,   -74,   -74,   -74,   -74,   -74,   -13,    27,   -74,
-     -74,    31,   137,    65,    59,   -74,    59,    27,   -74,   -74,
-     -74,   -74,   -74
+     -99,     5,   102,   -99,   -99,   -99,   -48,   -99,   -99,   -99,
+     -99,   -99,   -99,    19,   -99,    27,    52,   -99,    56,    60,
+     -99,    67,   -99,    34,    73,    76,   -99,   -99,   -99,    86,
+      87,    88,     0,   -99,   -99,   -99,    15,   -99,   -99,   -99,
+      46,   -99,   -99,    54,   -99,   -99,    45,     4,     4,     0,
+     -99,    58,   -99,   -99,   -99,    31,   -99,   -99,   -99,   -99,
+     -99,   -99,   -99,   -99,   -99,   -99,   -99,   -99,   -99,   -99,
+     -99,   -99,    49,   -99,    50,     1,   -99,   -99,    61,    62,
+     -99,    58,    32,   -99,     0,   -99,   -99,     4,    84,     4,
+       0,   -99,   -99,   -99,   -99,   -99,   -99,   -99,    72,   -99,
+     -99,   -99,   -99,   -99,    64,   -99,   -99,   -99,   -99,    32,
+     -99,   -99,   -99,     0,   -99,   101,   -99,   114,   -99,   -99,
+     -99,   -99,   -99,   -99,   -99,   -99,   -99,    12,    26,   -99,
+     -99,     0,   138,    66,    61,   -99,   -99,    61,    26,   -99,
+     -99,   -99,   -99,   -99
 };
 
   /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
@@ -727,25 +731,25 @@ static const yytype_uint8 yydefact[] =
        7,     0,    15,     0,     0,     0,    37,    19,    20,     0,
        0,     0,     0,    26,    27,    28,     0,     6,    29,    22,
       42,     4,     5,     0,    33,    32,    55,     0,     0,     0,
-     101,     0,    38,    97,    96,    98,    10,    12,    13,    14,
-      16,    17,    18,    21,    24,    25,   107,   103,   102,   105,
-      34,   106,     0,   104,     0,     0,    77,    79,    94,     0,
+     102,     0,    38,    98,    97,    99,    10,    12,    13,    14,
+      16,    17,    18,    21,    24,    25,   108,   104,   103,   106,
+      34,   107,     0,   105,     0,     0,    77,    79,    95,     0,
       43,     0,     0,    56,     0,    70,    75,    48,    71,    46,
-      49,    61,    39,   100,    99,     8,    81,    80,     0,    78,
-       2,    95,    82,    31,    23,    44,    67,    68,    69,    35,
+      49,    61,    39,   101,   100,     8,    81,    80,     0,    78,
+       2,    96,    82,    31,    23,    44,    67,    68,    69,    35,
       63,    66,    65,    50,    57,    59,    76,    72,    73,    62,
-     109,    87,    30,    64,    58,    60,    74,    83,    84,    87,
-      86,     0,     0,     0,    94,    90,    94,    85,    91,    92,
-      93,    89,    88
+     110,    87,    30,    64,    58,    60,    74,    83,    84,    87,
+      86,     0,     0,     0,    95,    90,    91,    95,    85,    92,
+      93,    94,    89,    88
 };
 
   /* YYPGOTO[NTERM-NUM].  */
 static const yytype_int16 yypgoto[] =
 {
-     -74,   -74,   -74,   -74,   -74,   -74,   140,   -74,   -74,   -74,
-     -74,   -74,   -74,   -74,   -74,   -74,    30,   -74,   -74,    35,
-     -74,   -26,    97,   -74,    71,   -74,   -74,   -74,    18,   -70,
-     -74,   -74,   -46,     6,   -74,   -32,   -73,   -74
+     -99,   -99,   -99,   -99,   -99,   -99,   141,   -99,   -99,   -99,
+     -99,   -99,   -99,   -99,   -99,   -99,    33,   -99,   -99,    35,
+     -99,    -7,    97,   -99,    74,   -99,   -99,   -99,    18,   -98,
+     -99,   -99,   -13,     6,   -99,   -32,   -73,   -99
 };
 
   /* YYDEFGOTO[NTERM-NUM].  */
@@ -762,79 +766,80 @@ static const yytype_int16 yydefgoto[] =
      number is the opposite.  If YYTABLE_NINF, syntax error.  */
 static const yytype_int16 yytable[] =
 {
-      70,  -108,    72,    53,    49,    92,     4,     5,     6,     7,
+      70,  -109,    72,    66,    49,     3,     4,     5,     6,     7,
        8,     9,    10,    11,    12,   118,    72,    91,    13,    14,
        4,     5,     6,     7,     8,     9,    10,    11,    12,    66,
-      66,    26,    13,    14,    66,   105,   129,    32,   130,    93,
-       3,   131,   132,   133,   126,    26,    54,    67,    73,    98,
+      53,    26,    13,    14,    93,    66,   142,    32,    92,   143,
+     131,   132,   133,    67,   126,    26,    68,    67,    73,    98,
       68,    32,   115,    88,    88,    56,    85,    40,   119,    50,
-      57,   116,    73,   116,   141,    51,   142,   134,   135,    67,
-      67,    40,    68,    68,    67,    66,   117,    68,   106,   107,
-     108,   115,    94,    58,    59,    60,    61,    62,    63,    64,
-      65,    82,    80,    88,    83,    88,   136,    50,    96,   138,
-      97,   101,   103,   122,   120,   136,     4,     5,     6,     7,
-       8,     9,    10,    11,    12,   125,    66,   140,    13,    14,
-      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
-      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
-      35,   139,    42,   124,   123,    89,    99,   137,     0,    36,
-       0,    37,    38,     0,     0,     0,    39,    40
+      57,   129,    73,   130,    58,    51,   134,   135,   105,    67,
+      59,    40,    68,    54,    60,    67,    61,    94,    68,    62,
+     116,   115,   116,   136,   106,   107,   108,    66,   117,    63,
+      64,    65,    80,    88,    82,    88,   137,    83,    50,   139,
+      96,    97,   103,   101,   122,   125,   137,     4,     5,     6,
+       7,     8,     9,    10,    11,    12,   120,    66,   141,    13,
+      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
+      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
+      34,    35,   140,    42,   123,    89,   124,   138,     0,    99,
+      36,     0,    37,    38,     0,     0,     0,    39,    40
 };
 
 static const yytype_int16 yycheck[] =
 {
-      32,     0,     1,     3,    52,    51,     5,     6,     7,     8,
+      32,     0,     1,     3,    52,     0,     5,     6,     7,     8,
        9,    10,    11,    12,    13,    88,     1,    49,    17,    18,
        5,     6,     7,     8,     9,    10,    11,    12,    13,     3,
-       3,    30,    17,    18,     3,    81,    49,    36,    51,     3,
-       0,    14,    15,    16,   117,    30,    46,    43,    47,    48,
+       3,    30,    17,    18,     3,     3,   134,    36,    51,   137,
+      14,    15,    16,    43,   117,    30,    46,    43,    47,    48,
       46,    36,    84,    47,    48,     3,    52,    56,    90,    40,
-       4,    87,    47,    89,   134,    46,   136,    40,    41,    43,
-      43,    56,    46,    46,    43,     3,     4,    46,    52,    53,
-      54,   113,    46,     4,     3,    40,     3,     3,     3,     3,
-       3,    40,    46,    87,    52,    89,   128,    40,    51,   131,
-      51,    42,    40,    40,    44,   137,     5,     6,     7,     8,
-       9,    10,    11,    12,    13,     4,     3,    52,    17,    18,
-      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
-      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
-      39,     4,     2,   113,   109,    48,    75,   129,    -1,    48,
-      -1,    50,    51,    -1,    -1,    -1,    55,    56
+       4,    49,    47,    51,     4,    46,    40,    41,    81,    43,
+       3,    56,    46,    46,    40,    43,     3,    46,    46,     3,
+      87,   113,    89,    57,    52,    53,    54,     3,     4,     3,
+       3,     3,    46,    87,    40,    89,   128,    52,    40,   131,
+      51,    51,    40,    42,    40,     4,   138,     5,     6,     7,
+       8,     9,    10,    11,    12,    13,    44,     3,    52,    17,
+      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
+      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
+      38,    39,     4,     2,   109,    48,   113,   129,    -1,    75,
+      48,    -1,    50,    51,    -1,    -1,    -1,    55,    56
 };
 
   /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
      symbol of state STATE-NUM.  */
 static const yytype_uint8 yystos[] =
 {
-       0,    58,    59,     0,     5,     6,     7,     8,     9,    10,
+       0,    59,    60,     0,     5,     6,     7,     8,     9,    10,
       11,    12,    13,    17,    18,    19,    20,    21,    22,    23,
       24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
       34,    35,    36,    37,    38,    39,    48,    50,    51,    55,
-      56,    60,    63,    64,    66,    69,    70,    68,    67,    52,
-      40,    46,    89,     3,    46,    87,     3,     4,     4,     3,
-      40,     3,     3,     3,     3,     3,     3,    43,    46,    90,
-      92,    93,     1,    47,    63,    80,    81,    82,    91,    61,
-      46,    65,    40,    52,    71,    52,    78,    79,    90,    79,
-      74,    92,    89,     3,    46,    88,    51,    51,    48,    81,
-      94,    42,    86,    40,    62,    89,    52,    53,    54,    75,
-      76,    77,    92,    72,    73,    92,    78,     4,    93,    92,
-      44,    83,    40,    76,    73,     4,    93,    84,    85,    49,
-      51,    14,    15,    16,    40,    41,    92,    85,    92,     4,
-      52,    86,    86
+      56,    61,    64,    65,    67,    70,    71,    69,    68,    52,
+      40,    46,    90,     3,    46,    88,     3,     4,     4,     3,
+      40,     3,     3,     3,     3,     3,     3,    43,    46,    91,
+      93,    94,     1,    47,    64,    81,    82,    83,    92,    62,
+      46,    66,    40,    52,    72,    52,    79,    80,    91,    80,
+      75,    93,    90,     3,    46,    89,    51,    51,    48,    82,
+      95,    42,    87,    40,    63,    90,    52,    53,    54,    76,
+      77,    78,    93,    73,    74,    93,    79,     4,    94,    93,
+      44,    84,    40,    77,    74,     4,    94,    85,    86,    49,
+      51,    14,    15,    16,    40,    41,    57,    93,    86,    93,
+       4,    52,    87,    87
 };
 
   /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
 static const yytype_uint8 yyr1[] =
 {
-       0,    57,    58,    59,    59,    60,    60,    60,    60,    60,
-      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
-      60,    60,    61,    60,    60,    60,    60,    60,    60,    60,
-      62,    62,    63,    63,    63,    63,    63,    63,    63,    63,
-      64,    64,    65,    65,    63,    67,    66,    68,    66,    66,
-      69,    70,    70,    70,    70,    71,    71,    72,    72,    73,
-      73,    74,    74,    75,    75,    76,    76,    77,    77,    77,
-      78,    78,    78,    78,    78,    79,    79,    80,    80,    81,
-      81,    81,    83,    82,    84,    84,    84,    85,    85,    85,
-      85,    85,    85,    85,    86,    86,    87,    87,    88,    88,
-      88,    89,    90,    90,    91,    92,    92,    93,    94,    94
+       0,    58,    59,    60,    60,    61,    61,    61,    61,    61,
+      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
+      61,    61,    62,    61,    61,    61,    61,    61,    61,    61,
+      63,    63,    64,    64,    64,    64,    64,    64,    64,    64,
+      65,    65,    66,    66,    64,    68,    67,    69,    67,    67,
+      70,    71,    71,    71,    71,    72,    72,    73,    73,    74,
+      74,    75,    75,    76,    76,    77,    77,    78,    78,    78,
+      79,    79,    79,    79,    79,    80,    80,    81,    81,    82,
+      82,    82,    84,    83,    85,    85,    85,    86,    86,    86,
+      86,    86,    86,    86,    86,    87,    87,    88,    88,    89,
+      89,    89,    90,    91,    91,    92,    93,    93,    94,    95,
+      95
 };
 
   /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
@@ -849,8 +854,9 @@ static const yytype_uint8 yyr2[] =
        2,     1,     2,     1,     2,     1,     1,     1,     1,     1,
        1,     1,     2,     2,     3,     1,     2,     1,     2,     1,
        2,     2,     0,     4,     1,     3,     2,     0,     3,     3,
-       2,     3,     3,     3,     0,     1,     1,     1,     0,     1,
-       1,     1,     1,     1,     1,     1,     1,     1,     0,     2
+       2,     2,     3,     3,     3,     0,     1,     1,     1,     0,
+       1,     1,     1,     1,     1,     1,     1,     1,     1,     0,
+       2
 };
 
 
@@ -1008,67 +1014,67 @@ yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvalue
     case 3: /* "string"  */
 #line 192 "src/parse-gram.y" /* yacc.c:707  */
       { fputs (quotearg_style (c_quoting_style, ((*yyvaluep).chars)), yyo); }
-#line 1012 "src/parse-gram.c" /* yacc.c:707  */
+#line 1018 "src/parse-gram.c" /* yacc.c:707  */
         break;
 
     case 4: /* "integer"  */
 #line 205 "src/parse-gram.y" /* yacc.c:707  */
       { fprintf (yyo, "%d", ((*yyvaluep).integer)); }
-#line 1018 "src/parse-gram.c" /* yacc.c:707  */
+#line 1024 "src/parse-gram.c" /* yacc.c:707  */
         break;
 
     case 24: /* "%<flag>"  */
 #line 201 "src/parse-gram.y" /* yacc.c:707  */
       { fprintf (yyo, "%%%s", ((*yyvaluep).uniqstr)); }
-#line 1024 "src/parse-gram.c" /* yacc.c:707  */
+#line 1030 "src/parse-gram.c" /* yacc.c:707  */
         break;
 
     case 40: /* "{...}"  */
 #line 194 "src/parse-gram.y" /* yacc.c:707  */
       { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).code)); }
-#line 1030 "src/parse-gram.c" /* yacc.c:707  */
+#line 1036 "src/parse-gram.c" /* yacc.c:707  */
         break;
 
     case 42: /* "[identifier]"  */
 #line 199 "src/parse-gram.y" /* yacc.c:707  */
       { fprintf (yyo, "[%s]", ((*yyvaluep).uniqstr)); }
-#line 1036 "src/parse-gram.c" /* yacc.c:707  */
+#line 1042 "src/parse-gram.c" /* yacc.c:707  */
         break;
 
     case 43: /* "char"  */
 #line 186 "src/parse-gram.y" /* yacc.c:707  */
       { fputs (char_name (((*yyvaluep).character)), yyo); }
-#line 1042 "src/parse-gram.c" /* yacc.c:707  */
+#line 1048 "src/parse-gram.c" /* yacc.c:707  */
         break;
 
     case 44: /* "epilogue"  */
 #line 194 "src/parse-gram.y" /* yacc.c:707  */
       { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).chars)); }
-#line 1048 "src/parse-gram.c" /* yacc.c:707  */
+#line 1054 "src/parse-gram.c" /* yacc.c:707  */
         break;
 
     case 46: /* "identifier"  */
 #line 198 "src/parse-gram.y" /* yacc.c:707  */
       { fputs (((*yyvaluep).uniqstr), yyo); }
-#line 1054 "src/parse-gram.c" /* yacc.c:707  */
+#line 1060 "src/parse-gram.c" /* yacc.c:707  */
         break;
 
     case 47: /* "identifier:"  */
 #line 200 "src/parse-gram.y" /* yacc.c:707  */
       { fprintf (yyo, "%s:", ((*yyvaluep).uniqstr)); }
-#line 1060 "src/parse-gram.c" /* yacc.c:707  */
+#line 1066 "src/parse-gram.c" /* yacc.c:707  */
         break;
 
     case 50: /* "%{...%}"  */
 #line 194 "src/parse-gram.y" /* yacc.c:707  */
       { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).chars)); }
-#line 1066 "src/parse-gram.c" /* yacc.c:707  */
+#line 1072 "src/parse-gram.c" /* yacc.c:707  */
         break;
 
     case 52: /* "<tag>"  */
 #line 202 "src/parse-gram.y" /* yacc.c:707  */
       { fprintf (yyo, "<%s>", ((*yyvaluep).uniqstr)); }
-#line 1072 "src/parse-gram.c" /* yacc.c:707  */
+#line 1078 "src/parse-gram.c" /* yacc.c:707  */
         break;
 
     case 55: /* "%param"  */
@@ -1085,67 +1091,67 @@ yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvalue
       case param_none: aver (false); break;
     }
 }
-#line 1089 "src/parse-gram.c" /* yacc.c:707  */
+#line 1095 "src/parse-gram.c" /* yacc.c:707  */
         break;
 
-    case 64: /* code_props_type  */
+    case 65: /* code_props_type  */
 #line 420 "src/parse-gram.y" /* yacc.c:707  */
       { fprintf (yyo, "%s", code_props_type_string (((*yyvaluep).code_type))); }
-#line 1095 "src/parse-gram.c" /* yacc.c:707  */
+#line 1101 "src/parse-gram.c" /* yacc.c:707  */
         break;
 
-    case 73: /* symbol.prec  */
+    case 74: /* symbol.prec  */
 #line 208 "src/parse-gram.y" /* yacc.c:707  */
       { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
-#line 1101 "src/parse-gram.c" /* yacc.c:707  */
+#line 1107 "src/parse-gram.c" /* yacc.c:707  */
         break;
 
-    case 77: /* tag  */
+    case 78: /* tag  */
 #line 202 "src/parse-gram.y" /* yacc.c:707  */
       { fprintf (yyo, "<%s>", ((*yyvaluep).uniqstr)); }
-#line 1107 "src/parse-gram.c" /* yacc.c:707  */
+#line 1113 "src/parse-gram.c" /* yacc.c:707  */
         break;
 
-    case 87: /* variable  */
+    case 88: /* variable  */
 #line 198 "src/parse-gram.y" /* yacc.c:707  */
       { fputs (((*yyvaluep).uniqstr), yyo); }
-#line 1113 "src/parse-gram.c" /* yacc.c:707  */
+#line 1119 "src/parse-gram.c" /* yacc.c:707  */
         break;
 
-    case 88: /* content.opt  */
+    case 89: /* content.opt  */
 #line 194 "src/parse-gram.y" /* yacc.c:707  */
       { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).chars)); }
-#line 1119 "src/parse-gram.c" /* yacc.c:707  */
+#line 1125 "src/parse-gram.c" /* yacc.c:707  */
         break;
 
-    case 89: /* braceless  */
+    case 90: /* braceless  */
 #line 194 "src/parse-gram.y" /* yacc.c:707  */
       { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).chars)); }
-#line 1125 "src/parse-gram.c" /* yacc.c:707  */
+#line 1131 "src/parse-gram.c" /* yacc.c:707  */
         break;
 
-    case 90: /* id  */
+    case 91: /* id  */
 #line 208 "src/parse-gram.y" /* yacc.c:707  */
       { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
-#line 1131 "src/parse-gram.c" /* yacc.c:707  */
+#line 1137 "src/parse-gram.c" /* yacc.c:707  */
         break;
 
-    case 91: /* id_colon  */
+    case 92: /* id_colon  */
 #line 209 "src/parse-gram.y" /* yacc.c:707  */
       { fprintf (yyo, "%s:", ((*yyvaluep).symbol)->tag); }
-#line 1137 "src/parse-gram.c" /* yacc.c:707  */
+#line 1143 "src/parse-gram.c" /* yacc.c:707  */
         break;
 
-    case 92: /* symbol  */
+    case 93: /* symbol  */
 #line 208 "src/parse-gram.y" /* yacc.c:707  */
       { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
-#line 1143 "src/parse-gram.c" /* yacc.c:707  */
+#line 1149 "src/parse-gram.c" /* yacc.c:707  */
         break;
 
-    case 93: /* string_as_id  */
+    case 94: /* string_as_id  */
 #line 208 "src/parse-gram.y" /* yacc.c:707  */
       { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
-#line 1149 "src/parse-gram.c" /* yacc.c:707  */
+#line 1155 "src/parse-gram.c" /* yacc.c:707  */
         break;
 
       default:
@@ -1867,7 +1873,7 @@ YYLTYPE yylloc = yyloc_default;
   boundary_set (&yylloc.start, current_file, 1, 1);
   boundary_set (&yylloc.end, current_file, 1, 1);
 }
-#line 1871 "src/parse-gram.c" /* yacc.c:1452  */
+#line 1877 "src/parse-gram.c" /* yacc.c:1452  */
   yylsp[0] = yylloc;
   goto yysetstate;
 
@@ -2071,7 +2077,7 @@ yyreduce:
                         plain_code.code, (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2075 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2081 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 7:
@@ -2079,7 +2085,7 @@ yyreduce:
     {
       muscle_percent_define_ensure ((yyvsp[0].uniqstr), (yylsp[0]), true);
     }
-#line 2083 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2089 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 8:
@@ -2088,13 +2094,13 @@ yyreduce:
       muscle_percent_define_insert ((yyvsp[-1].uniqstr), (yylsp[-1]), (yyvsp[0].chars),
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
     }
-#line 2092 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2098 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 9:
 #line 302 "src/parse-gram.y" /* yacc.c:1669  */
     { defines_flag = true; }
-#line 2098 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2104 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 10:
@@ -2103,7 +2109,7 @@ yyreduce:
       defines_flag = true;
       spec_defines_file = xstrdup ((yyvsp[0].chars));
     }
-#line 2107 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2113 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 11:
@@ -2112,25 +2118,25 @@ yyreduce:
       muscle_percent_define_insert ("parse.error", (yylsp[0]), "verbose",
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
     }
-#line 2116 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2122 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 12:
 #line 313 "src/parse-gram.y" /* yacc.c:1669  */
     { expected_sr_conflicts = (yyvsp[0].integer); }
-#line 2122 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2128 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 13:
 #line 314 "src/parse-gram.y" /* yacc.c:1669  */
     { expected_rr_conflicts = (yyvsp[0].integer); }
-#line 2128 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2134 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 14:
 #line 315 "src/parse-gram.y" /* yacc.c:1669  */
     { spec_file_prefix = (yyvsp[0].chars); }
-#line 2134 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2140 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 15:
@@ -2139,7 +2145,7 @@ yyreduce:
       nondeterministic_parser = true;
       glr_parser = true;
     }
-#line 2143 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2149 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 16:
@@ -2152,55 +2158,55 @@ yyreduce:
       muscle_code_grow ("initial_action", action.code, (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2156 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2162 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 17:
 #line 330 "src/parse-gram.y" /* yacc.c:1669  */
     { language_argmatch ((yyvsp[0].chars), grammar_prio, (yylsp[-1])); }
-#line 2162 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2168 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 18:
 #line 331 "src/parse-gram.y" /* yacc.c:1669  */
     { spec_name_prefix = (yyvsp[0].chars); }
-#line 2168 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2174 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 19:
 #line 332 "src/parse-gram.y" /* yacc.c:1669  */
     { no_lines_flag = true; }
-#line 2174 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2180 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 20:
 #line 333 "src/parse-gram.y" /* yacc.c:1669  */
     { nondeterministic_parser = true; }
-#line 2180 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2186 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 21:
 #line 334 "src/parse-gram.y" /* yacc.c:1669  */
     { spec_outfile = (yyvsp[0].chars); }
-#line 2186 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2192 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 22:
 #line 335 "src/parse-gram.y" /* yacc.c:1669  */
     { current_param = (yyvsp[0].param); }
-#line 2192 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2198 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 23:
 #line 335 "src/parse-gram.y" /* yacc.c:1669  */
     { current_param = param_none; }
-#line 2198 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2204 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 24:
 #line 336 "src/parse-gram.y" /* yacc.c:1669  */
     { version_check (&(yylsp[0]), (yyvsp[0].chars)); }
-#line 2204 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2210 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 25:
@@ -2228,37 +2234,37 @@ yyreduce:
         }
       skeleton_arg (skeleton_user, grammar_prio, (yylsp[-1]));
     }
-#line 2232 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2238 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 26:
 #line 361 "src/parse-gram.y" /* yacc.c:1669  */
     { token_table_flag = true; }
-#line 2238 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2244 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 27:
 #line 362 "src/parse-gram.y" /* yacc.c:1669  */
     { report_flag |= report_states; }
-#line 2244 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2250 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 28:
 #line 363 "src/parse-gram.y" /* yacc.c:1669  */
     { yacc_flag = true; }
-#line 2250 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2256 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 30:
 #line 368 "src/parse-gram.y" /* yacc.c:1669  */
     { add_param (current_param, (yyvsp[0].code), (yylsp[0])); }
-#line 2256 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2262 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 31:
 #line 369 "src/parse-gram.y" /* yacc.c:1669  */
     { add_param (current_param, (yyvsp[0].code), (yylsp[0])); }
-#line 2262 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2268 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 34:
@@ -2266,7 +2272,7 @@ yyreduce:
     {
       grammar_start_symbol_set ((yyvsp[0].symbol), (yylsp[0]));
     }
-#line 2270 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2276 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 35:
@@ -2282,7 +2288,7 @@ yyreduce:
         symbol_list_free ((yyvsp[0].list));
       }
     }
-#line 2286 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2292 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 36:
@@ -2290,7 +2296,7 @@ yyreduce:
     {
       default_prec = true;
     }
-#line 2294 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2300 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 37:
@@ -2298,7 +2304,7 @@ yyreduce:
     {
       default_prec = false;
     }
-#line 2302 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2308 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 38:
@@ -2309,7 +2315,7 @@ yyreduce:
       muscle_code_grow ("percent_code()", (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2313 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2319 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 39:
@@ -2318,31 +2324,31 @@ yyreduce:
       muscle_percent_code_grow ((yyvsp[-1].uniqstr), (yylsp[-1]), (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2322 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2328 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 40:
 #line 422 "src/parse-gram.y" /* yacc.c:1669  */
     { (yyval.code_type) = destructor; }
-#line 2328 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2334 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 41:
 #line 423 "src/parse-gram.y" /* yacc.c:1669  */
     { (yyval.code_type) = printer; }
-#line 2334 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2340 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 42:
 #line 433 "src/parse-gram.y" /* yacc.c:1669  */
     {}
-#line 2340 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2346 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 43:
 #line 434 "src/parse-gram.y" /* yacc.c:1669  */
     { muscle_code_grow ("union_name", (yyvsp[0].uniqstr), (yylsp[0])); }
-#line 2346 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2352 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 44:
@@ -2352,13 +2358,13 @@ yyreduce:
       muscle_code_grow ("union_members", (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2356 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2362 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 45:
 #line 450 "src/parse-gram.y" /* yacc.c:1669  */
     { current_class = nterm_sym; }
-#line 2362 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2368 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 46:
@@ -2367,13 +2373,13 @@ yyreduce:
       current_class = unknown_sym;
       current_type = NULL;
     }
-#line 2371 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2377 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 47:
 #line 455 "src/parse-gram.y" /* yacc.c:1669  */
     { current_class = token_sym; }
-#line 2377 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2383 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 48:
@@ -2382,7 +2388,7 @@ yyreduce:
       current_class = unknown_sym;
       current_type = NULL;
     }
-#line 2386 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2392 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 49:
@@ -2394,7 +2400,7 @@ yyreduce:
         symbol_type_set (list->content.sym, (yyvsp[-1].uniqstr), (yylsp[-1]));
       symbol_list_free ((yyvsp[0].list));
     }
-#line 2398 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2404 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 50:
@@ -2410,115 +2416,115 @@ yyreduce:
       symbol_list_free ((yyvsp[0].list));
       current_type = NULL;
     }
-#line 2414 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2420 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 51:
 #line 486 "src/parse-gram.y" /* yacc.c:1669  */
     { (yyval.assoc) = left_assoc; }
-#line 2420 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2426 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 52:
 #line 487 "src/parse-gram.y" /* yacc.c:1669  */
     { (yyval.assoc) = right_assoc; }
-#line 2426 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2432 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 53:
 #line 488 "src/parse-gram.y" /* yacc.c:1669  */
     { (yyval.assoc) = non_assoc; }
-#line 2432 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2438 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 54:
 #line 489 "src/parse-gram.y" /* yacc.c:1669  */
     { (yyval.assoc) = precedence_assoc; }
-#line 2438 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2444 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 55:
 #line 493 "src/parse-gram.y" /* yacc.c:1669  */
     { current_type = NULL; }
-#line 2444 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2450 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 56:
 #line 494 "src/parse-gram.y" /* yacc.c:1669  */
     { current_type = (yyvsp[0].uniqstr); tag_seen = true; }
-#line 2450 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2456 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 57:
 #line 500 "src/parse-gram.y" /* yacc.c:1669  */
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-#line 2456 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2462 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 58:
 #line 502 "src/parse-gram.y" /* yacc.c:1669  */
     { (yyval.list) = symbol_list_append ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
-#line 2462 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2468 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 59:
 #line 506 "src/parse-gram.y" /* yacc.c:1669  */
     { (yyval.symbol) = (yyvsp[0].symbol); }
-#line 2468 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2474 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 60:
 #line 507 "src/parse-gram.y" /* yacc.c:1669  */
     { (yyval.symbol) = (yyvsp[-1].symbol); symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0])); }
-#line 2474 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2480 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 61:
 #line 513 "src/parse-gram.y" /* yacc.c:1669  */
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-#line 2480 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2486 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 62:
 #line 515 "src/parse-gram.y" /* yacc.c:1669  */
     { (yyval.list) = symbol_list_append ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
-#line 2486 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2492 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 63:
 #line 519 "src/parse-gram.y" /* yacc.c:1669  */
     { (yyval.list) = (yyvsp[0].list); }
-#line 2492 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2498 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 64:
 #line 520 "src/parse-gram.y" /* yacc.c:1669  */
     { (yyval.list) = symbol_list_append ((yyvsp[-1].list), (yyvsp[0].list)); }
-#line 2498 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2504 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 65:
 #line 524 "src/parse-gram.y" /* yacc.c:1669  */
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-#line 2504 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2510 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 66:
 #line 525 "src/parse-gram.y" /* yacc.c:1669  */
     { (yyval.list) = symbol_list_type_new ((yyvsp[0].uniqstr), (yylsp[0])); }
-#line 2510 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2516 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 68:
 #line 530 "src/parse-gram.y" /* yacc.c:1669  */
     { (yyval.uniqstr) = uniqstr_new ("*"); }
-#line 2516 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2522 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 69:
 #line 531 "src/parse-gram.y" /* yacc.c:1669  */
     { (yyval.uniqstr) = uniqstr_new (""); }
-#line 2522 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2528 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 70:
@@ -2527,7 +2533,7 @@ yyreduce:
       current_type = (yyvsp[0].uniqstr);
       tag_seen = true;
     }
-#line 2531 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2537 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 71:
@@ -2536,7 +2542,7 @@ yyreduce:
       symbol_class_set ((yyvsp[0].symbol), current_class, (yylsp[0]), true);
       symbol_type_set ((yyvsp[0].symbol), current_type, (yylsp[0]));
     }
-#line 2540 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2546 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 72:
@@ -2546,7 +2552,7 @@ yyreduce:
       symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
       symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0]));
     }
-#line 2550 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2556 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 73:
@@ -2556,7 +2562,7 @@ yyreduce:
       symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
       symbol_make_alias ((yyvsp[-1].symbol), (yyvsp[0].symbol), (yyloc));
     }
-#line 2560 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2566 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 74:
@@ -2567,7 +2573,7 @@ yyreduce:
       symbol_user_token_number_set ((yyvsp[-2].symbol), (yyvsp[-1].integer), (yylsp[-1]));
       symbol_make_alias ((yyvsp[-2].symbol), (yyvsp[0].symbol), (yyloc));
     }
-#line 2571 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2577 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 81:
@@ -2575,13 +2581,13 @@ yyreduce:
     {
       yyerrok;
     }
-#line 2579 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2585 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 82:
 #line 595 "src/parse-gram.y" /* yacc.c:1669  */
     { current_lhs ((yyvsp[-1].symbol), (yylsp[-1]), (yyvsp[0].named_ref)); }
-#line 2585 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2591 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 83:
@@ -2590,96 +2596,108 @@ yyreduce:
     /* Free the current lhs. */
     current_lhs (0, (yylsp[-3]), 0);
   }
-#line 2594 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2600 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 84:
 #line 603 "src/parse-gram.y" /* yacc.c:1669  */
     { grammar_current_rule_end ((yylsp[0])); }
-#line 2600 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2606 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 85:
 #line 604 "src/parse-gram.y" /* yacc.c:1669  */
     { grammar_current_rule_end ((yylsp[0])); }
-#line 2606 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2612 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 87:
-#line 610 "src/parse-gram.y" /* yacc.c:1669  */
+#line 611 "src/parse-gram.y" /* yacc.c:1669  */
     { grammar_current_rule_begin (current_lhs_symbol, current_lhs_location,
                                   current_lhs_named_ref); }
-#line 2613 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2619 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 88:
-#line 613 "src/parse-gram.y" /* yacc.c:1669  */
+#line 614 "src/parse-gram.y" /* yacc.c:1669  */
     { grammar_current_rule_symbol_append ((yyvsp[-1].symbol), (yylsp[-1]), (yyvsp[0].named_ref)); }
-#line 2619 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2625 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 89:
-#line 615 "src/parse-gram.y" /* yacc.c:1669  */
+#line 616 "src/parse-gram.y" /* yacc.c:1669  */
     { grammar_current_rule_action_append ((yyvsp[-1].code), (yylsp[-1]), (yyvsp[0].named_ref), false); }
-#line 2625 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2631 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 90:
-#line 617 "src/parse-gram.y" /* yacc.c:1669  */
+#line 618 "src/parse-gram.y" /* yacc.c:1669  */
     { grammar_current_rule_action_append ((yyvsp[0].code), (yylsp[0]), NULL, true); }
-#line 2631 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2637 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 91:
-#line 619 "src/parse-gram.y" /* yacc.c:1669  */
-    { grammar_current_rule_prec_set ((yyvsp[0].symbol), (yylsp[0])); }
-#line 2637 "src/parse-gram.c" /* yacc.c:1669  */
+#line 620 "src/parse-gram.y" /* yacc.c:1669  */
+    { grammar_current_rule_empty_set ((yylsp[0])); }
+#line 2643 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 92:
-#line 621 "src/parse-gram.y" /* yacc.c:1669  */
-    { grammar_current_rule_dprec_set ((yyvsp[0].integer), (yylsp[0])); }
-#line 2643 "src/parse-gram.c" /* yacc.c:1669  */
+#line 622 "src/parse-gram.y" /* yacc.c:1669  */
+    { grammar_current_rule_prec_set ((yyvsp[0].symbol), (yylsp[0])); }
+#line 2649 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 93:
-#line 623 "src/parse-gram.y" /* yacc.c:1669  */
-    { grammar_current_rule_merge_set ((yyvsp[0].uniqstr), (yylsp[0])); }
-#line 2649 "src/parse-gram.c" /* yacc.c:1669  */
+#line 624 "src/parse-gram.y" /* yacc.c:1669  */
+    { grammar_current_rule_dprec_set ((yyvsp[0].integer), (yylsp[0])); }
+#line 2655 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 94:
-#line 627 "src/parse-gram.y" /* yacc.c:1669  */
-    { (yyval.named_ref) = 0; }
-#line 2655 "src/parse-gram.c" /* yacc.c:1669  */
+#line 626 "src/parse-gram.y" /* yacc.c:1669  */
+    { grammar_current_rule_merge_set ((yyvsp[0].uniqstr), (yylsp[0])); }
+#line 2661 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 95:
-#line 629 "src/parse-gram.y" /* yacc.c:1669  */
-    { (yyval.named_ref) = named_ref_new ((yyvsp[0].uniqstr), (yylsp[0])); }
-#line 2661 "src/parse-gram.c" /* yacc.c:1669  */
+#line 630 "src/parse-gram.y" /* yacc.c:1669  */
+    { (yyval.named_ref) = 0; }
+#line 2667 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
-  case 97:
-#line 640 "src/parse-gram.y" /* yacc.c:1669  */
-    { (yyval.uniqstr) = uniqstr_new ((yyvsp[0].chars)); }
-#line 2667 "src/parse-gram.c" /* yacc.c:1669  */
+  case 96:
+#line 631 "src/parse-gram.y" /* yacc.c:1669  */
+    { (yyval.named_ref) = named_ref_new((yyvsp[0].uniqstr), (yylsp[0])); }
+#line 2673 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 98:
-#line 645 "src/parse-gram.y" /* yacc.c:1669  */
-    { (yyval.chars) = ""; }
-#line 2673 "src/parse-gram.c" /* yacc.c:1669  */
+#line 642 "src/parse-gram.y" /* yacc.c:1669  */
+    { (yyval.uniqstr) = uniqstr_new ((yyvsp[0].chars)); }
+#line 2679 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 99:
-#line 646 "src/parse-gram.y" /* yacc.c:1669  */
+#line 647 "src/parse-gram.y" /* yacc.c:1669  */
+    { (yyval.chars) = ""; }
+#line 2685 "src/parse-gram.c" /* yacc.c:1669  */
+    break;
+
+  case 100:
+#line 648 "src/parse-gram.y" /* yacc.c:1669  */
     { (yyval.chars) = (yyvsp[0].uniqstr); }
-#line 2679 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2691 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 101:
-#line 657 "src/parse-gram.y" /* yacc.c:1669  */
+#line 649 "src/parse-gram.y" /* yacc.c:1669  */
+    { (yyval.chars) = (yyvsp[0].chars); }
+#line 2697 "src/parse-gram.c" /* yacc.c:1669  */
+    break;
+
+  case 102:
+#line 659 "src/parse-gram.y" /* yacc.c:1669  */
     {
       code_props plain_code;
       (yyvsp[0].code)[strlen ((yyvsp[0].code)) - 1] = '\n';
@@ -2688,42 +2706,42 @@ yyreduce:
       gram_scanner_last_string_free ();
       (yyval.chars) = plain_code.code;
     }
-#line 2692 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2710 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
-  case 102:
-#line 677 "src/parse-gram.y" /* yacc.c:1669  */
+  case 103:
+#line 679 "src/parse-gram.y" /* yacc.c:1669  */
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
-#line 2698 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2716 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
-  case 103:
-#line 679 "src/parse-gram.y" /* yacc.c:1669  */
+  case 104:
+#line 681 "src/parse-gram.y" /* yacc.c:1669  */
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[0].character)), (yylsp[0]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
       symbol_user_token_number_set ((yyval.symbol), (yyvsp[0].character), (yylsp[0]));
     }
-#line 2708 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2726 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
-  case 104:
-#line 687 "src/parse-gram.y" /* yacc.c:1669  */
+  case 105:
+#line 689 "src/parse-gram.y" /* yacc.c:1669  */
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
-#line 2714 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2732 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
-  case 107:
-#line 699 "src/parse-gram.y" /* yacc.c:1669  */
+  case 108:
+#line 701 "src/parse-gram.y" /* yacc.c:1669  */
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[0].chars)), (yylsp[0]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
     }
-#line 2723 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2741 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
-  case 109:
-#line 708 "src/parse-gram.y" /* yacc.c:1669  */
+  case 110:
+#line 710 "src/parse-gram.y" /* yacc.c:1669  */
     {
       code_props plain_code;
       code_props_plain_init (&plain_code, (yyvsp[0].chars), (yylsp[0]));
@@ -2732,11 +2750,11 @@ yyreduce:
       muscle_code_grow ("epilogue", plain_code.code, (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2736 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2754 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
 
-#line 2740 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2758 "src/parse-gram.c" /* yacc.c:1669  */
         default: break;
       }
     if (yychar_backup != yychar)
@@ -2983,7 +3001,7 @@ yyreturn:
 #endif
   return yyresult;
 }
-#line 718 "src/parse-gram.y" /* yacc.c:1929  */
+#line 720 "src/parse-gram.y" /* yacc.c:1929  */
 
 
 /* Return the location of the left-hand side of a rule whose
