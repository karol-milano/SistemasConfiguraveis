@@ -485,16 +485,16 @@ union yyalloc
 #define YYLAST   234
 
 /* YYNTOKENS -- Number of terminals.  */
-#define YYNTOKENS  60
+#define YYNTOKENS  61
 /* YYNNTS -- Number of nonterminals.  */
 #define YYNNTS  42
 /* YYNRULES -- Number of rules.  */
-#define YYNRULES  122
+#define YYNRULES  123
 /* YYNSTATES -- Number of states.  */
-#define YYNSTATES  166
+#define YYNSTATES  167
 
 #define YYUNDEFTOK  2
-#define YYMAXUTOK   314
+#define YYMAXUTOK   315
 
 
 /* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
@@ -505,19 +505,19 @@ union yyalloc
   /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
 static const yytype_int16 yyrline[] =
 {
-       0,   293,   293,   302,   303,   307,   308,   314,   318,   323,
-     324,   329,   330,   331,   332,   333,   338,   343,   344,   345,
-     346,   347,   348,   348,   349,   350,   351,   352,   353,   354,
-     355,   356,   360,   361,   370,   371,   375,   386,   390,   394,
-     402,   412,   413,   423,   424,   430,   443,   443,   448,   448,
-     453,   457,   467,   468,   469,   470,   474,   475,   480,   481,
-     485,   486,   490,   491,   492,   505,   514,   518,   522,   530,
-     531,   535,   548,   549,   561,   565,   569,   577,   579,   584,
-     591,   601,   605,   609,   617,   622,   634,   635,   641,   642,
-     643,   650,   650,   658,   659,   660,   665,   668,   670,   672,
-     674,   676,   678,   680,   682,   684,   689,   690,   699,   723,
-     724,   725,   726,   738,   740,   767,   772,   773,   778,   787,
-     788,   792,   793
+       0,   294,   294,   303,   304,   308,   309,   315,   319,   324,
+     325,   330,   331,   332,   333,   334,   339,   344,   345,   346,
+     347,   348,   349,   349,   350,   351,   352,   353,   354,   355,
+     356,   357,   361,   362,   371,   372,   376,   387,   391,   395,
+     403,   413,   414,   424,   425,   431,   444,   444,   449,   449,
+     454,   458,   468,   469,   470,   471,   475,   476,   481,   482,
+     486,   487,   491,   492,   493,   506,   515,   519,   523,   531,
+     532,   536,   549,   550,   555,   556,   557,   575,   579,   583,
+     591,   593,   598,   605,   615,   619,   623,   631,   636,   648,
+     649,   655,   656,   657,   664,   664,   672,   673,   674,   679,
+     682,   684,   686,   688,   690,   692,   694,   696,   698,   703,
+     704,   713,   737,   738,   739,   740,   752,   754,   781,   786,
+     787,   792,   800,   801
 };
 #endif
 
@@ -535,27 +535,27 @@ yysymbol_name (int yysymbol)
 {
   static const char *const yy_sname[] =
   {
-  "end of file", "error", "$undefined", "string", "%token", "%nterm",
-  "%type", "%destructor", "%printer", "%left", "%right", "%nonassoc",
-  "%precedence", "%prec", "%dprec", "%merge", "%code", "%default-prec",
-  "%define", "%defines", "%error-verbose", "%expect", "%expect-rr",
-  "%<flag>", "%file-prefix", "%glr-parser", "%initial-action", "%language",
-  "%name-prefix", "%no-default-prec", "%no-lines",
-  "%nondeterministic-parser", "%output", "%pure-parser", "%require",
-  "%skeleton", "%start", "%token-table", "%verbose", "%yacc", "{...}",
-  "%?{...}", "[identifier]", "character literal", ":", "epilogue", "=",
-  "identifier", "identifier:", "%%", "|", "%{...%}", ";", "<tag>", "<*>",
-  "<>", "integer", "%param", "%union", "%empty", "$accept", "input",
+  "end of file", "error", "$undefined", "string", "translatable string",
+  "%token", "%nterm", "%type", "%destructor", "%printer", "%left",
+  "%right", "%nonassoc", "%precedence", "%prec", "%dprec", "%merge",
+  "%code", "%default-prec", "%define", "%defines", "%error-verbose",
+  "%expect", "%expect-rr", "%<flag>", "%file-prefix", "%glr-parser",
+  "%initial-action", "%language", "%name-prefix", "%no-default-prec",
+  "%no-lines", "%nondeterministic-parser", "%output", "%pure-parser",
+  "%require", "%skeleton", "%start", "%token-table", "%verbose", "%yacc",
+  "{...}", "%?{...}", "[identifier]", "character literal", ":", "epilogue",
+  "=", "identifier", "identifier:", "%%", "|", "%{...%}", ";", "<tag>",
+  "<*>", "<>", "integer", "%param", "%union", "%empty", "$accept", "input",
   "prologue_declarations", "prologue_declaration", "$@1", "params",
   "grammar_declaration", "code_props_type", "union_name",
   "symbol_declaration", "$@2", "$@3", "precedence_declarator", "tag.opt",
   "generic_symlist", "generic_symlist_item", "tag", "nterm_decls",
-  "token_decls", "token_decl.1", "token_decl", "int.opt",
+  "token_decls", "token_decl.1", "token_decl", "int.opt", "alias",
   "token_decls_for_prec", "token_decl_for_prec.1", "token_decl_for_prec",
   "symbol_decls", "symbol_decl.1", "grammar",
   "rules_or_grammar_declaration", "rules", "$@4", "rhses.1", "rhs",
   "named_ref.opt", "variable", "value", "id", "id_colon", "symbol",
-  "string_as_id", "string_as_id.opt", "epilogue.opt", YY_NULLPTR
+  "string_as_id", "epilogue.opt", YY_NULLPTR
   };
   return yy_sname[yysymbol];
 }
@@ -571,16 +571,17 @@ static const yytype_int16 yytoknum[] =
      275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
      285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
      295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
-     305,   306,   307,   308,   309,   310,   311,   312,   313,   314
+     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
+     315
 };
 # endif
 
-#define YYPACT_NINF (-130)
+#define YYPACT_NINF (-80)
 
 #define yypact_value_is_default(Yyn) \
   ((Yyn) == YYPACT_NINF)
 
-#define YYTABLE_NINF (-122)
+#define YYTABLE_NINF (-123)
 
 #define yytable_value_is_error(Yyn) \
   0
@@ -589,23 +590,23 @@ static const yytype_int16 yytoknum[] =
      STATE-NUM.  */
 static const yytype_int16 yypact[] =
 {
-    -130,    36,   110,  -130,   -22,  -130,  -130,     2,  -130,  -130,
-    -130,  -130,  -130,  -130,   -19,  -130,    -9,    40,  -130,   -17,
-      -2,  -130,    57,  -130,    21,    66,    77,  -130,  -130,  -130,
-      78,  -130,    87,    92,    44,  -130,  -130,  -130,   165,  -130,
-    -130,  -130,    50,  -130,  -130,    58,  -130,    29,  -130,    15,
-      15,  -130,  -130,  -130,    44,    47,    44,  -130,  -130,  -130,
-    -130,    61,  -130,    30,  -130,  -130,  -130,  -130,  -130,  -130,
-    -130,  -130,  -130,  -130,  -130,    51,  -130,    53,     8,  -130,
-    -130,    64,    67,  -130,    68,    20,    44,    56,    44,  -130,
-      69,  -130,   -37,    59,   -37,  -130,    69,  -130,    59,    44,
-      44,  -130,  -130,  -130,  -130,  -130,  -130,  -130,  -130,    79,
-    -130,  -130,  -130,  -130,  -130,   111,  -130,  -130,  -130,  -130,
-      20,  -130,  -130,  -130,    44,    44,  -130,  -130,  -130,   -37,
-     -37,  -130,   147,    44,  -130,   108,  -130,  -130,    44,   -37,
-    -130,  -130,  -130,   -21,   175,  -130,  -130,    44,    97,   101,
-      99,   100,  -130,  -130,  -130,   117,    64,   175,  -130,  -130,
-    -130,  -130,  -130,    64,  -130,  -130
+     -80,     5,   120,   -80,   -17,   -80,   -80,    23,   -80,   -80,
+     -80,   -80,   -80,   -80,    -7,   -80,    10,    58,   -80,     6,
+      34,   -80,    82,   -80,    54,    95,   101,   -80,   -80,   -80,
+     103,   -80,   105,   107,    24,   -80,   -80,   -80,   175,   -80,
+     -80,   -80,    64,   -80,   -80,    75,   -80,    61,   -80,   -15,
+     -15,   -80,   -80,   -80,    24,    63,    24,   -80,   -80,   -80,
+     -80,    77,   -80,    46,   -80,   -80,   -80,   -80,   -80,   -80,
+     -80,   -80,   -80,   -80,   -80,    67,   -80,    69,     7,   -80,
+     -80,    80,    93,   -80,    94,    -1,    24,   108,    24,   -80,
+      79,   -80,   -38,   109,   -38,   -80,    79,   -80,   109,    24,
+      24,   -80,   -80,   -80,   -80,   -80,   -80,   -80,   -80,   115,
+     -80,   -80,   -80,   -80,   -80,   123,   -80,   -80,   -80,   -80,
+      -1,   -80,   -80,   -80,    24,    24,   -80,   -80,   -80,   -38,
+     -38,   -80,    28,    24,   -80,   121,   -80,   -80,    24,   -38,
+     -80,   -80,   -80,   -80,   -23,    59,   -80,   -80,    24,   110,
+     111,   112,   114,   -80,   -80,   -80,   127,    80,    59,   -80,
+     -80,   -80,   -80,   -80,    80,   -80,   -80
 };
 
   /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
@@ -618,38 +619,38 @@ static const yytype_int8 yydefact[] =
        0,     7,     0,    15,     0,     0,     0,    38,    19,    20,
        0,    24,     0,     0,     0,    27,    28,    29,     0,     6,
       31,    22,    43,     4,     5,     0,    34,     0,    30,     0,
-       0,   118,   114,   113,     0,    50,    81,   116,    84,   117,
-      39,     0,   108,   109,    10,    12,    13,    14,    16,    17,
-      18,    21,    25,    26,    35,     0,   115,     0,     0,    86,
-      88,   106,     0,    44,     0,     0,     0,    51,    74,    77,
-      72,    80,     0,    49,    66,    69,    72,    47,    65,    82,
-       0,    85,    40,   111,   112,   110,     8,    90,    89,     0,
-      87,     2,   107,    91,    33,    23,    45,    62,    63,    64,
-      36,    58,    61,    60,    75,     0,    78,    73,    79,    67,
-       0,    70,   119,    83,   122,     0,    32,    59,    76,    68,
-     120,    71,    96,    92,    93,    96,    95,     0,     0,     0,
-       0,     0,    99,    57,   100,     0,   106,    94,   101,   102,
-     103,   104,   105,   106,    97,    98
+       0,   121,   117,   116,     0,    50,    84,   119,    87,   120,
+      39,     0,   111,   112,    10,    12,    13,    14,    16,    17,
+      18,    21,    25,    26,    35,     0,   118,     0,     0,    89,
+      91,   109,     0,    44,     0,     0,     0,    51,    77,    80,
+      72,    83,     0,    49,    66,    69,    72,    47,    65,    85,
+       0,    88,    40,   114,   115,   113,     8,    93,    92,     0,
+      90,     2,   110,    94,    33,    23,    45,    62,    63,    64,
+      36,    58,    61,    60,    78,     0,    81,    73,    82,    67,
+       0,    70,    74,    86,   123,     0,    32,    59,    79,    68,
+      76,    71,    75,    99,    95,    96,    99,    98,     0,     0,
+       0,     0,     0,   102,    57,   103,     0,   109,    97,   104,
+     105,   106,   107,   108,   109,   100,   101
 };
 
   /* YYPGOTO[NTERM-NUM].  */
 static const yytype_int16 yypgoto[] =
 {
-    -130,  -130,  -130,  -130,  -130,  -130,   156,  -130,  -130,  -130,
-    -130,  -130,  -130,  -130,  -130,    43,  -130,  -130,   114,   -66,
-     -35,    83,  -130,   -84,   -53,  -130,   -47,  -130,    82,  -130,
-    -130,  -130,    35,  -129,  -130,  -130,   -46,  -130,   -34,   -36,
-    -130,  -130
+     -80,   -80,   -80,   -80,   -80,   -80,   172,   -80,   -80,   -80,
+     -80,   -80,   -80,   -80,   -80,    55,   -80,   -80,   139,   -54,
+     -59,    81,   -80,   -80,   -65,   -79,   -80,   -31,   -80,   113,
+     -80,   -80,   -80,    44,   -67,   -80,   -80,   -46,   -80,   -34,
+     -36,   -80
 };
 
   /* YYDEFGOTO[NTERM-NUM].  */
 static const yytype_int16 yydefgoto[] =
 {
       -1,     1,     2,    43,    82,   115,    77,    45,    84,    46,
-      50,    49,    47,   155,   120,   121,   122,    97,    93,    94,
-      95,   128,    87,    88,    89,    55,    56,    78,    79,    80,
-     135,   143,   144,   113,    63,   106,    57,    81,    58,    59,
-     141,   111
+      50,    49,    47,   156,   120,   121,   122,    97,    93,    94,
+      95,   128,   141,    87,    88,    89,    55,    56,    78,    79,
+      80,   135,   144,   145,   113,    63,   106,    57,    81,    58,
+      59,   111
 };
 
   /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
@@ -657,57 +658,57 @@ static const yytype_int16 yydefgoto[] =
      number is the opposite.  If YYTABLE_NINF, syntax error.  */
 static const yytype_int16 yytable[] =
 {
-      74,    90,   124,    96,    96,    51,    52,    99,  -121,    75,
+      74,    90,    51,    96,    96,     3,    52,  -122,    75,   126,
       53,    91,     5,     6,     7,     8,     9,    10,    11,    12,
-      13,    60,   101,    51,    14,    15,   129,   164,    61,   145,
-      48,   146,    51,   103,   165,   126,     3,    27,    62,    65,
-      90,   138,    90,    64,    34,    52,    96,    51,    96,    53,
-      91,   123,    91,   133,    66,    54,    76,   109,    52,   131,
-      67,    68,    53,    52,   139,   101,    42,    53,    92,    69,
-     104,   126,    52,   117,   118,   119,    53,   105,    90,    90,
-      70,    71,    86,    96,    96,   126,   123,    52,    91,    91,
-      72,    53,    90,    96,   131,    73,   140,    83,    85,   101,
-     100,   102,    91,   107,   131,   108,   112,   114,   116,   125,
-     156,     4,   130,   158,     5,     6,     7,     8,     9,    10,
-      11,    12,    13,   156,   134,   127,    14,    15,    16,    17,
-      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
-      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
-      51,   136,   142,   159,   160,   161,   162,   163,    44,    38,
-     110,    39,    40,   137,    98,     0,    75,    41,    42,     5,
-       6,     7,     8,     9,    10,    11,    12,    13,    51,   132,
-     157,    14,    15,     0,     0,     0,     0,     0,   147,   148,
-     149,     0,     0,     0,    27,     0,   150,   151,     0,     0,
-       0,    34,     0,     0,     0,     0,     0,     0,     0,     0,
-       0,     0,     0,    76,     0,   -56,   152,     0,    52,     0,
-       0,     0,    53,    42,     0,     0,     0,     0,   153,     0,
-       0,     0,     0,     0,   154
+      13,   124,   101,    99,    14,    15,    51,    51,   146,    52,
+     147,    51,   140,    53,    60,   131,    48,    27,   129,    92,
+      90,    61,    90,    52,    34,   126,    96,    53,    96,   103,
+      91,   123,    91,   117,   118,   119,    76,   109,    62,   126,
+     138,    64,    51,    65,    51,   101,    42,    52,    52,   133,
+     131,    53,    53,   148,   149,   150,   139,    54,    90,    90,
+     131,   151,   152,    96,    96,    67,   123,   104,    91,    91,
+     165,    66,    90,    96,   105,    68,   142,   166,    69,   101,
+     -56,   153,    91,    52,    70,    52,    71,    53,    72,    53,
+      73,   157,    83,   154,   159,    86,    85,   100,   102,   155,
+     107,     4,   108,   112,   157,     5,     6,     7,     8,     9,
+      10,    11,    12,    13,   114,   116,   127,    14,    15,    16,
+      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
+      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
+      37,   134,   125,   130,   136,   161,   143,   160,   164,   162,
+      38,   163,    39,    40,    44,   137,    75,   132,    41,    42,
+       5,     6,     7,     8,     9,    10,    11,    12,    13,    98,
+     158,   110,    14,    15,     0,     0,     0,     0,     0,     0,
+       0,     0,     0,     0,     0,    27,     0,     0,     0,     0,
+       0,     0,    34,     0,     0,     0,     0,     0,     0,     0,
+       0,     0,     0,     0,    76,     0,     0,     0,     0,     0,
+       0,     0,     0,     0,    42
 };
 
 static const yytype_int16 yycheck[] =
 {
-      34,    47,    86,    49,    50,     3,    43,    54,     0,     1,
-      47,    47,     4,     5,     6,     7,     8,     9,    10,    11,
-      12,    40,    56,     3,    16,    17,    92,   156,    47,    50,
-      52,    52,     3,     3,   163,    88,     0,    29,    47,    56,
-      86,   125,    88,     3,    36,    43,    92,     3,    94,    47,
-      86,    85,    88,   100,    56,    53,    48,    49,    43,    94,
-       3,    40,    47,    43,   130,    99,    58,    47,    53,     3,
-      40,   124,    43,    53,    54,    55,    47,    47,   124,   125,
-       3,     3,    53,   129,   130,   138,   120,    43,   124,   125,
-       3,    47,   138,   139,   129,     3,   132,    47,    40,   133,
-      53,    40,   138,    52,   139,    52,    42,    40,    40,    53,
-     144,     1,    53,   147,     4,     5,     6,     7,     8,     9,
-      10,    11,    12,   157,    45,    56,    16,    17,    18,    19,
+      34,    47,     3,    49,    50,     0,    44,     0,     1,    88,
+      48,    47,     5,     6,     7,     8,     9,    10,    11,    12,
+      13,    86,    56,    54,    17,    18,     3,     3,    51,    44,
+      53,     3,     4,    48,    41,    94,    53,    30,    92,    54,
+      86,    48,    88,    44,    37,   124,    92,    48,    94,     3,
+      86,    85,    88,    54,    55,    56,    49,    50,    48,   138,
+     125,     3,     3,    57,     3,    99,    59,    44,    44,   100,
+     129,    48,    48,    14,    15,    16,   130,    54,   124,   125,
+     139,    22,    23,   129,   130,     3,   120,    41,   124,   125,
+     157,    57,   138,   139,    48,    41,   132,   164,     3,   133,
+      41,    42,   138,    44,     3,    44,     3,    48,     3,    48,
+       3,   145,    48,    54,   148,    54,    41,    54,    41,    60,
+      53,     1,    53,    43,   158,     5,     6,     7,     8,     9,
+      10,    11,    12,    13,    41,    41,    57,    17,    18,    19,
       20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
       30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
-       3,    40,    44,    56,    53,    56,    56,    40,     2,    49,
-      78,    51,    52,   120,    50,    -1,     1,    57,    58,     4,
-       5,     6,     7,     8,     9,    10,    11,    12,     3,    96,
-     145,    16,    17,    -1,    -1,    -1,    -1,    -1,    13,    14,
-      15,    -1,    -1,    -1,    29,    -1,    21,    22,    -1,    -1,
-      -1,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
-      -1,    -1,    -1,    48,    -1,    40,    41,    -1,    43,    -1,
-      -1,    -1,    47,    58,    -1,    -1,    -1,    -1,    53,    -1,
+      40,    46,    54,    54,    41,    54,    45,    57,    41,    57,
+      50,    57,    52,    53,     2,   120,     1,    96,    58,    59,
+       5,     6,     7,     8,     9,    10,    11,    12,    13,    50,
+     146,    78,    17,    18,    -1,    -1,    -1,    -1,    -1,    -1,
+      -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,
+      -1,    -1,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
+      -1,    -1,    -1,    -1,    49,    -1,    -1,    -1,    -1,    -1,
       -1,    -1,    -1,    -1,    59
 };
 
@@ -715,41 +716,41 @@ static const yytype_int16 yycheck[] =
      symbol of state STATE-NUM.  */
 static const yytype_int8 yystos[] =
 {
-       0,    61,    62,     0,     1,     4,     5,     6,     7,     8,
-       9,    10,    11,    12,    16,    17,    18,    19,    20,    21,
-      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
-      32,    33,    34,    35,    36,    37,    38,    39,    49,    51,
-      52,    57,    58,    63,    66,    67,    69,    72,    52,    71,
-      70,     3,    43,    47,    53,    85,    86,    96,    98,    99,
-      40,    47,    47,    94,     3,    56,    56,     3,    40,     3,
-       3,     3,     3,     3,    98,     1,    48,    66,    87,    88,
-      89,    97,    64,    47,    68,    40,    53,    82,    83,    84,
-      96,    99,    53,    78,    79,    80,    96,    77,    78,    86,
-      53,    98,    40,     3,    40,    47,    95,    52,    52,    49,
-      88,   101,    42,    93,    40,    65,    40,    53,    54,    55,
-      74,    75,    76,    98,    83,    53,    84,    56,    81,    79,
-      53,    80,    81,    86,    45,    90,    40,    75,    83,    79,
-      99,   100,    44,    91,    92,    50,    52,    13,    14,    15,
-      21,    22,    41,    53,    59,    73,    98,    92,    98,    56,
-      53,    56,    56,    40,    93,    93
+       0,    62,    63,     0,     1,     5,     6,     7,     8,     9,
+      10,    11,    12,    13,    17,    18,    19,    20,    21,    22,
+      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
+      33,    34,    35,    36,    37,    38,    39,    40,    50,    52,
+      53,    58,    59,    64,    67,    68,    70,    73,    53,    72,
+      71,     3,    44,    48,    54,    87,    88,    98,   100,   101,
+      41,    48,    48,    96,     3,    57,    57,     3,    41,     3,
+       3,     3,     3,     3,   100,     1,    49,    67,    89,    90,
+      91,    99,    65,    48,    69,    41,    54,    84,    85,    86,
+      98,   101,    54,    79,    80,    81,    98,    78,    79,    88,
+      54,   100,    41,     3,    41,    48,    97,    53,    53,    50,
+      90,   102,    43,    95,    41,    66,    41,    54,    55,    56,
+      75,    76,    77,   100,    85,    54,    86,    57,    82,    80,
+      54,    81,    82,    88,    46,    92,    41,    76,    85,    80,
+       4,    83,   101,    45,    93,    94,    51,    53,    14,    15,
+      16,    22,    23,    42,    54,    60,    74,   100,    94,   100,
+      57,    54,    57,    57,    41,    95,    95
 };
 
   /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
 static const yytype_int8 yyr1[] =
 {
-       0,    60,    61,    62,    62,    63,    63,    63,    63,    63,
-      63,    63,    63,    63,    63,    63,    63,    63,    63,    63,
-      63,    63,    64,    63,    63,    63,    63,    63,    63,    63,
-      63,    63,    65,    65,    66,    66,    66,    66,    66,    66,
-      66,    67,    67,    68,    68,    66,    70,    69,    71,    69,
-      69,    69,    72,    72,    72,    72,    73,    73,    74,    74,
-      75,    75,    76,    76,    76,    77,    78,    78,    78,    79,
-      79,    80,    81,    81,    82,    82,    82,    83,    83,    84,
-      84,    85,    85,    85,    86,    86,    87,    87,    88,    88,
-      88,    90,    89,    91,    91,    91,    92,    92,    92,    92,
-      92,    92,    92,    92,    92,    92,    93,    93,    94,    95,
-      95,    95,    95,    96,    96,    97,    98,    98,    99,   100,
-     100,   101,   101
+       0,    61,    62,    63,    63,    64,    64,    64,    64,    64,
+      64,    64,    64,    64,    64,    64,    64,    64,    64,    64,
+      64,    64,    65,    64,    64,    64,    64,    64,    64,    64,
+      64,    64,    66,    66,    67,    67,    67,    67,    67,    67,
+      67,    68,    68,    69,    69,    67,    71,    70,    72,    70,
+      70,    70,    73,    73,    73,    73,    74,    74,    75,    75,
+      76,    76,    77,    77,    77,    78,    79,    79,    79,    80,
+      80,    81,    82,    82,    83,    83,    83,    84,    84,    84,
+      85,    85,    86,    86,    87,    87,    87,    88,    88,    89,
+      89,    90,    90,    90,    92,    91,    93,    93,    93,    94,
+      94,    94,    94,    94,    94,    94,    94,    94,    94,    95,
+      95,    96,    97,    97,    97,    97,    98,    98,    99,   100,
+     100,   101,   102,   102
 };
 
   /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
@@ -762,12 +763,12 @@ static const yytype_int8 yyr2[] =
        3,     1,     1,     0,     1,     3,     0,     3,     0,     3,
        2,     2,     1,     1,     1,     1,     0,     1,     1,     2,
        1,     1,     1,     1,     1,     1,     1,     2,     3,     1,
-       2,     3,     0,     1,     1,     2,     3,     1,     2,     2,
-       1,     1,     2,     3,     1,     2,     1,     2,     1,     2,
-       2,     0,     5,     1,     3,     2,     0,     3,     4,     2,
-       2,     3,     3,     3,     3,     3,     0,     1,     1,     0,
-       1,     1,     1,     1,     1,     1,     1,     1,     1,     0,
-       1,     0,     2
+       2,     3,     0,     1,     0,     1,     1,     1,     2,     3,
+       1,     2,     2,     1,     1,     2,     3,     1,     2,     1,
+       2,     1,     2,     2,     0,     5,     1,     3,     2,     0,
+       3,     4,     2,     2,     3,     3,     3,     3,     3,     0,
+       1,     1,     0,     1,     1,     1,     1,     1,     1,     1,
+       1,     1,     0,     2
 };
 
 
@@ -931,67 +932,71 @@ tron (yyo);
          { fputs (((*yyvaluep).STRING), yyo); }
         break;
 
-    case 20: /* "%error-verbose"  */
+    case 4: /* "translatable string"  */
+         { fputs (((*yyvaluep).TSTRING), yyo); }
+        break;
+
+    case 21: /* "%error-verbose"  */
          { fputs (((*yyvaluep).PERCENT_ERROR_VERBOSE), yyo); }
         break;
 
-    case 23: /* "%<flag>"  */
+    case 24: /* "%<flag>"  */
          { fprintf (yyo, "%%%s", ((*yyvaluep).PERCENT_FLAG)); }
         break;
 
-    case 24: /* "%file-prefix"  */
+    case 25: /* "%file-prefix"  */
          { fputs (((*yyvaluep).PERCENT_FILE_PREFIX), yyo); }
         break;
 
-    case 28: /* "%name-prefix"  */
+    case 29: /* "%name-prefix"  */
          { fputs (((*yyvaluep).PERCENT_NAME_PREFIX), yyo); }
         break;
 
-    case 33: /* "%pure-parser"  */
+    case 34: /* "%pure-parser"  */
          { fputs (((*yyvaluep).PERCENT_PURE_PARSER), yyo); }
         break;
 
-    case 40: /* "{...}"  */
+    case 41: /* "{...}"  */
          { fputs (((*yyvaluep).BRACED_CODE), yyo); }
         break;
 
-    case 41: /* "%?{...}"  */
+    case 42: /* "%?{...}"  */
          { fputs (((*yyvaluep).BRACED_PREDICATE), yyo); }
         break;
 
-    case 42: /* "[identifier]"  */
+    case 43: /* "[identifier]"  */
          { fprintf (yyo, "[%s]", ((*yyvaluep).BRACKETED_ID)); }
         break;
 
-    case 43: /* "character literal"  */
+    case 44: /* "character literal"  */
          { fputs (char_name (((*yyvaluep).CHAR)), yyo); }
         break;
 
-    case 45: /* "epilogue"  */
+    case 46: /* "epilogue"  */
          { fputs (((*yyvaluep).EPILOGUE), yyo); }
         break;
 
-    case 47: /* "identifier"  */
+    case 48: /* "identifier"  */
          { fputs (((*yyvaluep).ID), yyo); }
         break;
 
-    case 48: /* "identifier:"  */
+    case 49: /* "identifier:"  */
          { fprintf (yyo, "%s:", ((*yyvaluep).ID_COLON)); }
         break;
 
-    case 51: /* "%{...%}"  */
+    case 52: /* "%{...%}"  */
          { fputs (((*yyvaluep).PROLOGUE), yyo); }
         break;
 
-    case 53: /* "<tag>"  */
+    case 54: /* "<tag>"  */
          { fprintf (yyo, "<%s>", ((*yyvaluep).TAG)); }
         break;
 
-    case 56: /* "integer"  */
+    case 57: /* "integer"  */
          { fprintf (yyo, "%d", ((*yyvaluep).INT)); }
         break;
 
-    case 57: /* "%param"  */
+    case 58: /* "%param"  */
 {
   switch (((*yyvaluep).PERCENT_PARAM))
     {
@@ -1006,71 +1011,75 @@ tron (yyo);
 }
         break;
 
-    case 67: /* code_props_type  */
+    case 68: /* code_props_type  */
          { fprintf (yyo, "%s", code_props_type_string (((*yyvaluep).code_props_type))); }
         break;
 
-    case 73: /* tag.opt  */
-         { fputs (((*yyvaluep).yytype_73), yyo); }
+    case 74: /* tag.opt  */
+         { fputs (((*yyvaluep).yytype_74), yyo); }
         break;
 
-    case 74: /* generic_symlist  */
+    case 75: /* generic_symlist  */
          { symbol_list_syms_print (((*yyvaluep).generic_symlist), yyo); }
         break;
 
-    case 75: /* generic_symlist_item  */
+    case 76: /* generic_symlist_item  */
          { symbol_list_syms_print (((*yyvaluep).generic_symlist_item), yyo); }
         break;
 
-    case 76: /* tag  */
+    case 77: /* tag  */
          { fprintf (yyo, "<%s>", ((*yyvaluep).tag)); }
         break;
 
-    case 77: /* nterm_decls  */
+    case 78: /* nterm_decls  */
          { symbol_list_syms_print (((*yyvaluep).nterm_decls), yyo); }
         break;
 
-    case 78: /* token_decls  */
+    case 79: /* token_decls  */
          { symbol_list_syms_print (((*yyvaluep).token_decls), yyo); }
         break;
 
-    case 79: /* token_decl.1  */
-         { symbol_list_syms_print (((*yyvaluep).yytype_79), yyo); }
+    case 80: /* token_decl.1  */
+         { symbol_list_syms_print (((*yyvaluep).yytype_80), yyo); }
         break;
 
-    case 80: /* token_decl  */
+    case 81: /* token_decl  */
          { fprintf (yyo, "%s", ((*yyvaluep).token_decl) ? ((*yyvaluep).token_decl)->tag : "<NULL>"); }
         break;
 
-    case 81: /* int.opt  */
-         { fprintf (yyo, "%d", ((*yyvaluep).yytype_81)); }
+    case 82: /* int.opt  */
+         { fprintf (yyo, "%d", ((*yyvaluep).yytype_82)); }
         break;
 
-    case 82: /* token_decls_for_prec  */
+    case 83: /* alias  */
+         { fprintf (yyo, "%s", ((*yyvaluep).alias) ? ((*yyvaluep).alias)->tag : "<NULL>"); }
+        break;
+
+    case 84: /* token_decls_for_prec  */
          { symbol_list_syms_print (((*yyvaluep).token_decls_for_prec), yyo); }
         break;
 
-    case 83: /* token_decl_for_prec.1  */
-         { symbol_list_syms_print (((*yyvaluep).yytype_83), yyo); }
+    case 85: /* token_decl_for_prec.1  */
+         { symbol_list_syms_print (((*yyvaluep).yytype_85), yyo); }
         break;
 
-    case 84: /* token_decl_for_prec  */
+    case 86: /* token_decl_for_prec  */
          { fprintf (yyo, "%s", ((*yyvaluep).token_decl_for_prec) ? ((*yyvaluep).token_decl_for_prec)->tag : "<NULL>"); }
         break;
 
-    case 85: /* symbol_decls  */
+    case 87: /* symbol_decls  */
          { symbol_list_syms_print (((*yyvaluep).symbol_decls), yyo); }
         break;
 
-    case 86: /* symbol_decl.1  */
-         { symbol_list_syms_print (((*yyvaluep).yytype_86), yyo); }
+    case 88: /* symbol_decl.1  */
+         { symbol_list_syms_print (((*yyvaluep).yytype_88), yyo); }
         break;
 
-    case 94: /* variable  */
+    case 96: /* variable  */
          { fputs (((*yyvaluep).variable), yyo); }
         break;
 
-    case 95: /* value  */
+    case 97: /* value  */
 {
   switch (((*yyvaluep).value).kind)
     {
@@ -1081,26 +1090,22 @@ tron (yyo);
 }
         break;
 
-    case 96: /* id  */
+    case 98: /* id  */
          { fprintf (yyo, "%s", ((*yyvaluep).id) ? ((*yyvaluep).id)->tag : "<NULL>"); }
         break;
 
-    case 97: /* id_colon  */
+    case 99: /* id_colon  */
          { fprintf (yyo, "%s:", ((*yyvaluep).id_colon)->tag); }
         break;
 
-    case 98: /* symbol  */
+    case 100: /* symbol  */
          { fprintf (yyo, "%s", ((*yyvaluep).symbol) ? ((*yyvaluep).symbol)->tag : "<NULL>"); }
         break;
 
-    case 99: /* string_as_id  */
+    case 101: /* string_as_id  */
          { fprintf (yyo, "%s", ((*yyvaluep).string_as_id) ? ((*yyvaluep).string_as_id)->tag : "<NULL>"); }
         break;
 
-    case 100: /* string_as_id.opt  */
-         { fprintf (yyo, "%s", ((*yyvaluep).yytype_100) ? ((*yyvaluep).yytype_100)->tag : "<NULL>"); }
-        break;
-
       default:
         break;
     }
@@ -1684,40 +1689,40 @@ yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocatio
   YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
   switch (yytype)
     {
-    case 74: /* generic_symlist  */
+    case 75: /* generic_symlist  */
             { symbol_list_free (((*yyvaluep).generic_symlist)); }
         break;
 
-    case 75: /* generic_symlist_item  */
+    case 76: /* generic_symlist_item  */
             { symbol_list_free (((*yyvaluep).generic_symlist_item)); }
         break;
 
-    case 77: /* nterm_decls  */
+    case 78: /* nterm_decls  */
             { symbol_list_free (((*yyvaluep).nterm_decls)); }
         break;
 
-    case 78: /* token_decls  */
+    case 79: /* token_decls  */
             { symbol_list_free (((*yyvaluep).token_decls)); }
         break;
 
-    case 79: /* token_decl.1  */
-            { symbol_list_free (((*yyvaluep).yytype_79)); }
+    case 80: /* token_decl.1  */
+            { symbol_list_free (((*yyvaluep).yytype_80)); }
         break;
 
-    case 82: /* token_decls_for_prec  */
+    case 84: /* token_decls_for_prec  */
             { symbol_list_free (((*yyvaluep).token_decls_for_prec)); }
         break;
 
-    case 83: /* token_decl_for_prec.1  */
-            { symbol_list_free (((*yyvaluep).yytype_83)); }
+    case 85: /* token_decl_for_prec.1  */
+            { symbol_list_free (((*yyvaluep).yytype_85)); }
         break;
 
-    case 85: /* symbol_decls  */
+    case 87: /* symbol_decls  */
             { symbol_list_free (((*yyvaluep).symbol_decls)); }
         break;
 
-    case 86: /* symbol_decl.1  */
-            { symbol_list_free (((*yyvaluep).yytype_86)); }
+    case 88: /* symbol_decl.1  */
+            { symbol_list_free (((*yyvaluep).yytype_88)); }
         break;
 
       default:
@@ -2297,11 +2302,11 @@ yyreduce:
     break;
 
   case 56:
-         { (yyval.yytype_73) = NULL; }
+         { (yyval.yytype_74) = NULL; }
     break;
 
   case 57:
-         { (yyval.yytype_73) = (yyvsp[0].TAG); }
+         { (yyval.yytype_74) = (yyvsp[0].TAG); }
     break;
 
   case 59:
@@ -2326,207 +2331,223 @@ yyreduce:
 
   case 66:
     {
-      (yyval.token_decls) = (yyvsp[0].yytype_79);
+      (yyval.token_decls) = (yyvsp[0].yytype_80);
     }
     break;
 
   case 67:
     {
-      (yyval.token_decls) = symbol_list_type_set ((yyvsp[0].yytype_79), (yyvsp[-1].TAG), (yylsp[-1]));
+      (yyval.token_decls) = symbol_list_type_set ((yyvsp[0].yytype_80), (yyvsp[-1].TAG), (yylsp[-1]));
     }
     break;
 
   case 68:
     {
-      (yyval.token_decls) = symbol_list_append ((yyvsp[-2].token_decls), symbol_list_type_set ((yyvsp[0].yytype_79), (yyvsp[-1].TAG), (yylsp[-1])));
+      (yyval.token_decls) = symbol_list_append ((yyvsp[-2].token_decls), symbol_list_type_set ((yyvsp[0].yytype_80), (yyvsp[-1].TAG), (yylsp[-1])));
     }
     break;
 
   case 69:
-                            { (yyval.yytype_79) = symbol_list_sym_new ((yyvsp[0].token_decl), (yylsp[0])); }
+                            { (yyval.yytype_80) = symbol_list_sym_new ((yyvsp[0].token_decl), (yylsp[0])); }
     break;
 
   case 70:
-                            { (yyval.yytype_79) = symbol_list_append ((yyvsp[-1].yytype_79), symbol_list_sym_new ((yyvsp[0].token_decl), (yylsp[0]))); }
+                            { (yyval.yytype_80) = symbol_list_append ((yyvsp[-1].yytype_80), symbol_list_sym_new ((yyvsp[0].token_decl), (yylsp[0]))); }
     break;
 
   case 71:
     {
       (yyval.token_decl) = (yyvsp[-2].id);
       symbol_class_set ((yyvsp[-2].id), current_class, (yylsp[-2]), true);
-      if (0 <= (yyvsp[-1].yytype_81))
-        symbol_user_token_number_set ((yyvsp[-2].id), (yyvsp[-1].yytype_81), (yylsp[-1]));
-      if ((yyvsp[0].yytype_100))
-        symbol_make_alias ((yyvsp[-2].id), (yyvsp[0].yytype_100), (yylsp[0]));
+      if (0 <= (yyvsp[-1].yytype_82))
+        symbol_user_token_number_set ((yyvsp[-2].id), (yyvsp[-1].yytype_82), (yylsp[-1]));
+      if ((yyvsp[0].alias))
+        symbol_make_alias ((yyvsp[-2].id), (yyvsp[0].alias), (yylsp[0]));
     }
     break;
 
   case 72:
-          { (yyval.yytype_81) = -1; }
+          { (yyval.yytype_82) = -1; }
     break;
 
   case 74:
-    {
-      (yyval.token_decls_for_prec) = (yyvsp[0].yytype_83);
-    }
+                 { (yyval.alias) = NULL; }
     break;
 
   case 75:
-    {
-      (yyval.token_decls_for_prec) = symbol_list_type_set ((yyvsp[0].yytype_83), (yyvsp[-1].TAG), (yylsp[-1]));
-    }
+                 { (yyval.alias) = (yyvsp[0].string_as_id); }
     break;
 
   case 76:
     {
-      (yyval.token_decls_for_prec) = symbol_list_append ((yyvsp[-2].token_decls_for_prec), symbol_list_type_set ((yyvsp[0].yytype_83), (yyvsp[-1].TAG), (yylsp[-1])));
+      (yyval.alias) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[0].TSTRING)), (yylsp[0]));
+      symbol_class_set ((yyval.alias), token_sym, (yylsp[0]), false);
+      (yyval.alias)->translatable = true;
     }
     break;
 
   case 77:
-    { (yyval.yytype_83) = symbol_list_sym_new ((yyvsp[0].token_decl_for_prec), (yylsp[0])); }
+    {
+      (yyval.token_decls_for_prec) = (yyvsp[0].yytype_85);
+    }
     break;
 
   case 78:
-    { (yyval.yytype_83) = symbol_list_append ((yyvsp[-1].yytype_83), symbol_list_sym_new ((yyvsp[0].token_decl_for_prec), (yylsp[0]))); }
+    {
+      (yyval.token_decls_for_prec) = symbol_list_type_set ((yyvsp[0].yytype_85), (yyvsp[-1].TAG), (yylsp[-1]));
+    }
     break;
 
   case 79:
+    {
+      (yyval.token_decls_for_prec) = symbol_list_append ((yyvsp[-2].token_decls_for_prec), symbol_list_type_set ((yyvsp[0].yytype_85), (yyvsp[-1].TAG), (yylsp[-1])));
+    }
+    break;
+
+  case 80:
+    { (yyval.yytype_85) = symbol_list_sym_new ((yyvsp[0].token_decl_for_prec), (yylsp[0])); }
+    break;
+
+  case 81:
+    { (yyval.yytype_85) = symbol_list_append ((yyvsp[-1].yytype_85), symbol_list_sym_new ((yyvsp[0].token_decl_for_prec), (yylsp[0]))); }
+    break;
+
+  case 82:
     {
       (yyval.token_decl_for_prec) = (yyvsp[-1].id);
       symbol_class_set ((yyvsp[-1].id), token_sym, (yylsp[-1]), false);
-      if (0 <= (yyvsp[0].yytype_81))
-        symbol_user_token_number_set ((yyvsp[-1].id), (yyvsp[0].yytype_81), (yylsp[0]));
+      if (0 <= (yyvsp[0].yytype_82))
+        symbol_user_token_number_set ((yyvsp[-1].id), (yyvsp[0].yytype_82), (yylsp[0]));
     }
     break;
 
-  case 81:
+  case 84:
     {
-      (yyval.symbol_decls) = (yyvsp[0].yytype_86);
+      (yyval.symbol_decls) = (yyvsp[0].yytype_88);
     }
     break;
 
-  case 82:
+  case 85:
     {
-      (yyval.symbol_decls) = symbol_list_type_set ((yyvsp[0].yytype_86), (yyvsp[-1].TAG), (yylsp[-1]));
+      (yyval.symbol_decls) = symbol_list_type_set ((yyvsp[0].yytype_88), (yyvsp[-1].TAG), (yylsp[-1]));
     }
     break;
 
-  case 83:
+  case 86:
     {
-      (yyval.symbol_decls) = symbol_list_append ((yyvsp[-2].symbol_decls), symbol_list_type_set ((yyvsp[0].yytype_86), (yyvsp[-1].TAG), (yylsp[-1])));
+      (yyval.symbol_decls) = symbol_list_append ((yyvsp[-2].symbol_decls), symbol_list_type_set ((yyvsp[0].yytype_88), (yyvsp[-1].TAG), (yylsp[-1])));
     }
     break;
 
-  case 84:
+  case 87:
     {
       symbol_class_set ((yyvsp[0].symbol), pct_type_sym, (yylsp[0]), false);
-      (yyval.yytype_86) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]));
+      (yyval.yytype_88) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]));
     }
     break;
 
-  case 85:
+  case 88:
     {
       symbol_class_set ((yyvsp[0].symbol), pct_type_sym, (yylsp[0]), false);
-      (yyval.yytype_86) = symbol_list_append ((yyvsp[-1].yytype_86), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])));
+      (yyval.yytype_88) = symbol_list_append ((yyvsp[-1].yytype_88), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])));
     }
     break;
 
-  case 90:
+  case 93:
     {
       yyerrok;
     }
     break;
 
-  case 91:
-                         { current_lhs ((yyvsp[-1].id_colon), (yylsp[-1]), (yyvsp[0].yytype_93)); }
+  case 94:
+                         { current_lhs ((yyvsp[-1].id_colon), (yylsp[-1]), (yyvsp[0].yytype_95)); }
     break;
 
-  case 92:
+  case 95:
     {
       /* Free the current lhs. */
       current_lhs (0, (yylsp[-4]), 0);
     }
     break;
 
-  case 93:
+  case 96:
                      { grammar_current_rule_end ((yylsp[0])); }
     break;
 
-  case 94:
+  case 97:
                      { grammar_current_rule_end ((yylsp[0])); }
     break;
 
-  case 96:
+  case 99:
     { grammar_current_rule_begin (current_lhs_symbol, current_lhs_loc,
                                   current_lhs_named_ref); }
     break;
 
-  case 97:
-    { grammar_current_rule_symbol_append ((yyvsp[-1].symbol), (yylsp[-1]), (yyvsp[0].yytype_93)); }
+  case 100:
+    { grammar_current_rule_symbol_append ((yyvsp[-1].symbol), (yylsp[-1]), (yyvsp[0].yytype_95)); }
     break;
 
-  case 98:
-    { grammar_current_rule_action_append ((yyvsp[-1].BRACED_CODE), (yylsp[-1]), (yyvsp[0].yytype_93), (yyvsp[-2].yytype_73)); }
+  case 101:
+    { grammar_current_rule_action_append ((yyvsp[-1].BRACED_CODE), (yylsp[-1]), (yyvsp[0].yytype_95), (yyvsp[-2].yytype_74)); }
     break;
 
-  case 99:
+  case 102:
     { grammar_current_rule_predicate_append ((yyvsp[0].BRACED_PREDICATE), (yylsp[0])); }
     break;
 
-  case 100:
+  case 103:
     { grammar_current_rule_empty_set ((yylsp[0])); }
     break;
 
-  case 101:
+  case 104:
     { grammar_current_rule_prec_set ((yyvsp[0].symbol), (yylsp[0])); }
     break;
 
-  case 102:
+  case 105:
     { grammar_current_rule_dprec_set ((yyvsp[0].INT), (yylsp[0])); }
     break;
 
-  case 103:
+  case 106:
     { grammar_current_rule_merge_set ((yyvsp[0].TAG), (yylsp[0])); }
     break;
 
-  case 104:
+  case 107:
     { grammar_current_rule_expect_sr ((yyvsp[0].INT), (yylsp[0])); }
     break;
 
-  case 105:
+  case 108:
     { grammar_current_rule_expect_rr ((yyvsp[0].INT), (yylsp[0])); }
     break;
 
-  case 106:
-                 { (yyval.yytype_93) = NULL; }
+  case 109:
+                 { (yyval.yytype_95) = NULL; }
     break;
 
-  case 107:
-                 { (yyval.yytype_93) = named_ref_new ((yyvsp[0].BRACKETED_ID), (yylsp[0])); }
+  case 110:
+                 { (yyval.yytype_95) = named_ref_new ((yyvsp[0].BRACKETED_ID), (yylsp[0])); }
     break;
 
-  case 109:
+  case 112:
           { (yyval.value).kind = muscle_keyword; (yyval.value).chars = ""; }
     break;
 
-  case 110:
+  case 113:
           { (yyval.value).kind = muscle_keyword; (yyval.value).chars = (yyvsp[0].ID); }
     break;
 
-  case 111:
+  case 114:
           { (yyval.value).kind = muscle_string;  (yyval.value).chars = (yyvsp[0].STRING); }
     break;
 
-  case 112:
+  case 115:
           { (yyval.value).kind = muscle_code;    (yyval.value).chars = strip_braces ((yyvsp[0].BRACED_CODE)); }
     break;
 
-  case 113:
+  case 116:
     { (yyval.id) = symbol_from_uniqstr ((yyvsp[0].ID), (yylsp[0])); }
     break;
 
-  case 114:
+  case 117:
     {
       const char *var = "api.token.raw";
       if (current_class == nterm_sym)
@@ -2552,22 +2573,18 @@ yyreduce:
     }
     break;
 
-  case 115:
+  case 118:
            { (yyval.id_colon) = symbol_from_uniqstr ((yyvsp[0].ID_COLON), (yylsp[0])); }
     break;
 
-  case 118:
+  case 121:
     {
       (yyval.string_as_id) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[0].STRING)), (yylsp[0]));
       symbol_class_set ((yyval.string_as_id), token_sym, (yylsp[0]), false);
     }
     break;
 
-  case 119:
-                     { (yyval.yytype_100) = NULL; }
-    break;
-
-  case 122:
+  case 123:
     {
       muscle_code_grow ("epilogue", translate_code ((yyvsp[0].EPILOGUE), (yylsp[0]), true), (yylsp[0]));
       code_scanner_last_string_free ();
