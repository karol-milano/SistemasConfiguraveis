@@ -178,37 +178,38 @@ enum yysymbol_kind_t
   YYSYMBOL_symbol_declaration = 70,        /* symbol_declaration  */
   YYSYMBOL_71_2 = 71,                      /* $@2  */
   YYSYMBOL_72_3 = 72,                      /* $@3  */
-  YYSYMBOL_precedence_declarator = 73,     /* precedence_declarator  */
-  YYSYMBOL_74_string_opt = 74,             /* string.opt  */
-  YYSYMBOL_75_tag_opt = 75,                /* tag.opt  */
-  YYSYMBOL_generic_symlist = 76,           /* generic_symlist  */
-  YYSYMBOL_generic_symlist_item = 77,      /* generic_symlist_item  */
-  YYSYMBOL_tag = 78,                       /* tag  */
-  YYSYMBOL_nterm_decls = 79,               /* nterm_decls  */
-  YYSYMBOL_token_decls = 80,               /* token_decls  */
-  YYSYMBOL_81_token_decl_1 = 81,           /* token_decl.1  */
-  YYSYMBOL_token_decl = 82,                /* token_decl  */
-  YYSYMBOL_83_int_opt = 83,                /* int.opt  */
-  YYSYMBOL_alias = 84,                     /* alias  */
-  YYSYMBOL_token_decls_for_prec = 85,      /* token_decls_for_prec  */
-  YYSYMBOL_86_token_decl_for_prec_1 = 86,  /* token_decl_for_prec.1  */
-  YYSYMBOL_token_decl_for_prec = 87,       /* token_decl_for_prec  */
-  YYSYMBOL_symbol_decls = 88,              /* symbol_decls  */
-  YYSYMBOL_89_symbol_decl_1 = 89,          /* symbol_decl.1  */
-  YYSYMBOL_grammar = 90,                   /* grammar  */
-  YYSYMBOL_rules_or_grammar_declaration = 91, /* rules_or_grammar_declaration  */
-  YYSYMBOL_rules = 92,                     /* rules  */
-  YYSYMBOL_93_4 = 93,                      /* $@4  */
-  YYSYMBOL_94_rhses_1 = 94,                /* rhses.1  */
-  YYSYMBOL_rhs = 95,                       /* rhs  */
-  YYSYMBOL_96_named_ref_opt = 96,          /* named_ref.opt  */
-  YYSYMBOL_variable = 97,                  /* variable  */
-  YYSYMBOL_value = 98,                     /* value  */
-  YYSYMBOL_id = 99,                        /* id  */
-  YYSYMBOL_id_colon = 100,                 /* id_colon  */
-  YYSYMBOL_symbol = 101,                   /* symbol  */
-  YYSYMBOL_string_as_id = 102,             /* string_as_id  */
-  YYSYMBOL_103_epilogue_opt = 103          /* epilogue.opt  */
+  YYSYMBOL_73_4 = 73,                      /* $@4  */
+  YYSYMBOL_precedence_declarator = 74,     /* precedence_declarator  */
+  YYSYMBOL_75_string_opt = 75,             /* string.opt  */
+  YYSYMBOL_76_tag_opt = 76,                /* tag.opt  */
+  YYSYMBOL_generic_symlist = 77,           /* generic_symlist  */
+  YYSYMBOL_generic_symlist_item = 78,      /* generic_symlist_item  */
+  YYSYMBOL_tag = 79,                       /* tag  */
+  YYSYMBOL_nterm_decls = 80,               /* nterm_decls  */
+  YYSYMBOL_token_decls = 81,               /* token_decls  */
+  YYSYMBOL_82_token_decl_1 = 82,           /* token_decl.1  */
+  YYSYMBOL_token_decl = 83,                /* token_decl  */
+  YYSYMBOL_84_int_opt = 84,                /* int.opt  */
+  YYSYMBOL_alias = 85,                     /* alias  */
+  YYSYMBOL_token_decls_for_prec = 86,      /* token_decls_for_prec  */
+  YYSYMBOL_87_token_decl_for_prec_1 = 87,  /* token_decl_for_prec.1  */
+  YYSYMBOL_token_decl_for_prec = 88,       /* token_decl_for_prec  */
+  YYSYMBOL_symbol_decls = 89,              /* symbol_decls  */
+  YYSYMBOL_90_symbols_1 = 90,              /* symbols.1  */
+  YYSYMBOL_grammar = 91,                   /* grammar  */
+  YYSYMBOL_rules_or_grammar_declaration = 92, /* rules_or_grammar_declaration  */
+  YYSYMBOL_rules = 93,                     /* rules  */
+  YYSYMBOL_94_5 = 94,                      /* $@5  */
+  YYSYMBOL_95_rhses_1 = 95,                /* rhses.1  */
+  YYSYMBOL_rhs = 96,                       /* rhs  */
+  YYSYMBOL_97_named_ref_opt = 97,          /* named_ref.opt  */
+  YYSYMBOL_variable = 98,                  /* variable  */
+  YYSYMBOL_value = 99,                     /* value  */
+  YYSYMBOL_id = 100,                       /* id  */
+  YYSYMBOL_id_colon = 101,                 /* id_colon  */
+  YYSYMBOL_symbol = 102,                   /* symbol  */
+  YYSYMBOL_string_as_id = 103,             /* string_as_id  */
+  YYSYMBOL_104_epilogue_opt = 104          /* epilogue.opt  */
 };
 typedef enum yysymbol_kind_t yysymbol_kind_t;
 
@@ -623,16 +624,16 @@ union yyalloc
 /* YYFINAL -- State number of the termination state.  */
 #define YYFINAL  3
 /* YYLAST -- Last index in YYTABLE.  */
-#define YYLAST   235
+#define YYLAST   236
 
 /* YYNTOKENS -- Number of terminals.  */
 #define YYNTOKENS  61
 /* YYNNTS -- Number of nonterminals.  */
-#define YYNNTS  43
+#define YYNNTS  44
 /* YYNRULES -- Number of rules.  */
-#define YYNRULES  124
+#define YYNRULES  125
 /* YYNSTATES -- Number of states.  */
-#define YYNSTATES  168
+#define YYNSTATES  169
 
 /* YYMAXUTOK -- Last valid token kind.  */
 #define YYMAXUTOK   315
@@ -651,14 +652,14 @@ static const yytype_int16 yyrline[] =
      360,   361,   361,   362,   363,   364,   365,   366,   367,   368,
      369,   373,   374,   383,   384,   388,   399,   403,   407,   415,
      425,   426,   436,   437,   443,   456,   456,   461,   461,   466,
-     470,   480,   481,   482,   483,   488,   489,   493,   494,   499,
-     500,   504,   505,   509,   510,   511,   524,   533,   537,   541,
-     549,   550,   554,   567,   568,   573,   574,   575,   593,   597,
-     601,   609,   611,   616,   623,   633,   637,   641,   649,   654,
-     666,   667,   673,   674,   675,   682,   682,   690,   691,   692,
-     697,   700,   702,   704,   706,   708,   710,   712,   714,   716,
-     721,   722,   731,   755,   756,   757,   758,   770,   772,   796,
-     801,   802,   807,   815,   816
+     466,   471,   481,   482,   483,   484,   489,   490,   494,   495,
+     500,   501,   505,   506,   510,   511,   512,   525,   534,   538,
+     542,   550,   551,   555,   568,   569,   574,   575,   576,   594,
+     598,   602,   610,   612,   617,   624,   634,   638,   642,   650,
+     656,   669,   670,   676,   677,   678,   685,   685,   693,   694,
+     695,   700,   703,   705,   707,   709,   711,   713,   715,   717,
+     719,   724,   725,   734,   758,   759,   760,   761,   773,   775,
+     799,   804,   805,   810,   818,   819
 };
 #endif
 
@@ -689,12 +690,12 @@ yysymbol_name (yysymbol_kind_t yysymbol)
   N_("integer literal"), "%param", "%union", "%empty", "$accept", "input",
   "prologue_declarations", "prologue_declaration", "$@1", "params",
   "grammar_declaration", "code_props_type", "union_name",
-  "symbol_declaration", "$@2", "$@3", "precedence_declarator",
+  "symbol_declaration", "$@2", "$@3", "$@4", "precedence_declarator",
   "string.opt", "tag.opt", "generic_symlist", "generic_symlist_item",
   "tag", "nterm_decls", "token_decls", "token_decl.1", "token_decl",
   "int.opt", "alias", "token_decls_for_prec", "token_decl_for_prec.1",
-  "token_decl_for_prec", "symbol_decls", "symbol_decl.1", "grammar",
-  "rules_or_grammar_declaration", "rules", "$@4", "rhses.1", "rhs",
+  "token_decl_for_prec", "symbol_decls", "symbols.1", "grammar",
+  "rules_or_grammar_declaration", "rules", "$@5", "rhses.1", "rhs",
   "named_ref.opt", "variable", "value", "id", "id_colon", "symbol",
   "string_as_id", "epilogue.opt", YY_NULLPTR
   };
@@ -731,12 +732,12 @@ static const yytype_int16 yytoknum[] =
 };
 #endif
 
-#define YYPACT_NINF (-129)
+#define YYPACT_NINF (-147)
 
 #define yypact_value_is_default(Yyn) \
   ((Yyn) == YYPACT_NINF)
 
-#define YYTABLE_NINF (-124)
+#define YYTABLE_NINF (-125)
 
 #define yytable_value_is_error(Yyn) \
   0
@@ -745,23 +746,23 @@ static const yytype_int16 yytoknum[] =
      STATE-NUM.  */
 static const yytype_int16 yypact[] =
 {
-    -129,     7,   121,  -129,   -17,  -129,  -129,     2,  -129,  -129,
-    -129,  -129,  -129,  -129,   -13,  -129,    11,  -129,    -2,     3,
-      58,  -129,  -129,    61,    36,    80,    83,  -129,  -129,  -129,
-      85,  -129,    88,    89,    21,  -129,  -129,  -129,   176,  -129,
-    -129,  -129,    48,  -129,  -129,    57,  -129,    24,  -129,   -15,
-     -15,  -129,  -129,  -129,    21,    56,    21,  -129,  -129,  -129,
-    -129,    70,  -129,    68,  -129,  -129,  -129,  -129,  -129,  -129,
-    -129,  -129,  -129,  -129,  -129,  -129,    64,  -129,    65,     8,
-    -129,  -129,    76,    72,  -129,    82,    51,    21,    81,    21,
-    -129,    79,  -129,   -38,   109,   -38,  -129,    79,  -129,   109,
-      21,    21,  -129,  -129,  -129,  -129,  -129,  -129,  -129,  -129,
-      75,  -129,  -129,  -129,  -129,  -129,    96,  -129,  -129,  -129,
-    -129,    51,  -129,  -129,  -129,    21,    21,  -129,  -129,  -129,
-     -38,   -38,  -129,    28,    21,  -129,   119,  -129,  -129,    21,
-     -38,  -129,  -129,  -129,  -129,    -9,    60,  -129,  -129,    21,
-     108,   112,   110,   111,  -129,  -129,  -129,   128,    76,    60,
-    -129,  -129,  -129,  -129,  -129,    76,  -129,  -129
+    -147,     9,   122,  -147,   -39,  -147,  -147,  -147,  -147,  -147,
+    -147,  -147,  -147,  -147,   -33,  -147,   -17,  -147,     1,    11,
+      71,  -147,  -147,    72,    38,    77,    78,  -147,  -147,  -147,
+      81,  -147,    83,    88,    13,  -147,  -147,  -147,   177,  -147,
+    -147,  -147,    51,  -147,  -147,    59,  -147,    53,  -147,   -11,
+     -11,    70,  -147,    63,  -147,     4,  -147,  -147,  -147,  -147,
+    -147,  -147,  -147,  -147,  -147,  -147,  -147,  -147,  -147,  -147,
+    -147,  -147,  -147,    52,  -147,    56,    17,  -147,  -147,    69,
+      65,  -147,    74,   161,    13,    57,    13,  -147,    60,  -147,
+     -12,    66,   -12,  -147,    60,  -147,    66,    13,    67,    13,
+    -147,  -147,  -147,  -147,  -147,  -147,  -147,  -147,    73,  -147,
+    -147,  -147,  -147,  -147,    84,  -147,  -147,  -147,  -147,   161,
+    -147,  -147,  -147,    13,    13,  -147,  -147,  -147,   -12,   -12,
+    -147,    68,    13,    13,  -147,  -147,    91,  -147,  -147,    13,
+     -12,  -147,  -147,  -147,    13,  -147,   -41,    48,  -147,  -147,
+      13,    80,   109,   108,   110,  -147,  -147,  -147,    97,    69,
+      48,  -147,  -147,  -147,  -147,  -147,    69,  -147,  -147
 };
 
   /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
@@ -769,43 +770,43 @@ static const yytype_int16 yypact[] =
      means the default is an error.  */
 static const yytype_int8 yydefact[] =
 {
-       3,     0,     0,     1,     0,    47,    45,     0,    40,    41,
-      51,    52,    53,    54,     0,    36,     0,    10,     0,     0,
-       0,     7,    14,    55,     0,     0,     0,    37,    18,    19,
+       3,     0,     0,     1,     0,    47,    45,    49,    40,    41,
+      52,    53,    54,    55,     0,    36,     0,    10,     0,     0,
+       0,     7,    14,    56,     0,     0,     0,    37,    18,    19,
        0,    23,     0,     0,     0,    26,    27,    28,     0,     6,
       30,    21,    42,     4,     5,     0,    33,     0,    29,     0,
-       0,   122,   118,   117,     0,    49,    85,   120,    88,   121,
-      38,     0,   112,   113,    11,    12,    13,    56,     9,    15,
-      16,    17,    20,    24,    25,    34,     0,   119,     0,     0,
-      90,    92,   110,     0,    43,     0,     0,     0,    50,    78,
-      81,    73,    84,     0,    48,    67,    70,    73,    46,    66,
-      86,     0,    89,    39,   115,   116,   114,     8,    94,    93,
-       0,    91,     2,   111,    95,    32,    22,    44,    63,    64,
-      65,    35,    59,    62,    61,    79,     0,    82,    74,    83,
-      68,     0,    71,    75,    87,   124,     0,    31,    60,    80,
-      69,    77,    72,    76,   100,    96,    97,   100,    99,     0,
-       0,     0,     0,     0,   103,    58,   104,     0,   110,    98,
-     105,   106,   107,   108,   109,   110,   101,   102
+       0,     0,    38,     0,   113,   114,    11,    12,    13,    57,
+       9,    15,    16,    17,    20,    24,    25,   123,   119,   118,
+     121,    34,   122,     0,   120,     0,     0,    91,    93,   111,
+       0,    43,     0,     0,     0,    51,    79,    82,    74,    85,
+       0,    48,    68,    71,    74,    46,    67,     0,    50,    86,
+      89,    39,   116,   117,   115,     8,    95,    94,     0,    92,
+       2,   112,    96,    32,    22,    44,    64,    65,    66,    35,
+      60,    63,    62,    80,     0,    83,    75,    84,    69,     0,
+      72,    76,    87,     0,    90,   125,     0,    31,    61,    81,
+      70,    78,    73,    77,    88,   101,    97,    98,   101,   100,
+       0,     0,     0,     0,     0,   104,    59,   105,     0,   111,
+      99,   106,   107,   108,   109,   110,   111,   102,   103
 };
 
   /* YYPGOTO[NTERM-NUM].  */
 static const yytype_int16 yypgoto[] =
 {
-    -129,  -129,  -129,  -129,  -129,  -129,   122,  -129,  -129,  -129,
-    -129,  -129,  -129,  -129,  -129,  -129,    49,  -129,  -129,   125,
-     -91,    67,    93,  -129,  -129,   -53,   -77,  -129,   -31,  -129,
-      97,  -129,  -129,  -129,    25,  -128,  -129,  -129,   -46,  -129,
-     -34,   -36,  -129
+    -147,  -147,  -147,  -147,  -147,  -147,   120,  -147,  -147,  -147,
+    -147,  -147,  -147,  -147,  -147,  -147,  -147,    47,  -147,  -147,
+     118,   -69,   -87,    75,  -147,  -147,   -65,   -84,  -147,   -91,
+    -147,    94,  -147,  -147,  -147,    23,  -146,  -147,  -147,   -46,
+    -147,   -34,   -36,  -147
 };
 
   /* YYDEFGOTO[NTERM-NUM].  */
 static const yytype_int16 yydefgoto[] =
 {
-      -1,     1,     2,    43,    83,   116,    78,    45,    85,    46,
-      50,    49,    47,    68,   157,   121,   122,   123,    98,    94,
-      95,    96,   129,   142,    88,    89,    90,    55,    56,    79,
-      80,    81,   136,   145,   146,   114,    63,   107,    57,    82,
-      58,    59,   112
+      -1,     1,     2,    43,    80,   114,    75,    45,    82,    46,
+      50,    49,    51,    47,    60,   158,   119,   120,   121,    95,
+      91,    92,    93,   127,   142,    85,    86,    87,    98,    99,
+      76,    77,    78,   136,   146,   147,   112,    55,   105,    70,
+      79,   100,    72,   110
 };
 
   /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
@@ -813,58 +814,58 @@ static const yytype_int16 yydefgoto[] =
      number is the opposite.  If YYTABLE_NINF, syntax error.  */
 static const yytype_int16 yytable[] =
 {
-      75,    91,   130,    97,    97,    51,    52,     3,  -123,    76,
-      53,    92,   127,     5,     6,     7,     8,     9,    10,    11,
-      12,    13,   102,   100,    51,    14,    15,    51,    60,    52,
-     166,    51,   141,    53,   125,    61,    48,   167,    27,    93,
-     140,    91,   147,    91,   148,    34,    52,    97,   127,    97,
-      53,    92,   124,    92,    51,    64,    54,    77,   110,    62,
-      65,    66,   127,    51,    67,    52,   102,    42,    52,    53,
-     134,   104,    53,   139,   149,   150,   151,    69,    87,    91,
-      91,   152,   153,    70,    97,    97,    71,   124,    72,    92,
-      92,    73,    74,    91,    97,    52,    84,   143,    86,    53,
-     102,   -57,   154,    92,    52,   118,   119,   120,    53,   105,
-     101,   103,   158,   115,   155,   160,   106,   108,   109,   113,
-     156,   135,     4,   117,    44,   158,     5,     6,     7,     8,
-       9,    10,    11,    12,    13,   126,   128,   137,    14,    15,
-      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
-      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
-      36,    37,   132,   131,   144,   161,   162,   163,   164,   165,
-     138,    38,   159,    39,    40,    99,   111,    76,     0,    41,
-      42,     5,     6,     7,     8,     9,    10,    11,    12,    13,
-     133,     0,     0,    14,    15,     0,     0,   132,     0,     0,
-       0,     0,     0,     0,     0,     0,    27,   132,     0,     0,
-       0,     0,     0,    34,     0,     0,     0,     0,     0,     0,
-       0,     0,     0,     0,     0,    77,     0,     0,     0,     0,
-       0,     0,     0,     0,     0,    42
+      71,    88,   125,    94,    94,   130,   132,   102,    52,     3,
+     148,    89,   149,   167,    48,    53,    67,  -124,    73,   123,
+     168,   128,     5,     6,     7,     8,     9,    10,    11,    12,
+      13,    54,    68,    68,    14,    15,    69,    69,    88,   125,
+      88,   130,   144,    90,    94,   103,    94,    27,    89,   122,
+      89,    67,   104,   130,    34,   125,    67,    68,    56,   139,
+     140,    69,   150,   151,   152,   134,    74,   108,    57,   153,
+     154,    67,   141,    67,    58,    59,    42,    88,    88,    61,
+      62,    63,    94,    94,    64,   122,    65,    89,    89,   -58,
+     155,    66,    68,    88,    94,   143,    69,    68,   134,    81,
+      83,    69,   156,    89,   101,   106,   113,    84,   157,   107,
+     134,   124,   111,   159,    68,   115,   161,   126,    69,   135,
+     129,   133,    44,     4,    97,   137,   159,     5,     6,     7,
+       8,     9,    10,    11,    12,    13,   145,   162,   166,    14,
+      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
+      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
+      35,    36,    37,   163,    67,   164,   138,   165,    96,   131,
+     109,   160,    38,     0,    39,    40,     0,     0,    73,     0,
+      41,    42,     5,     6,     7,     8,     9,    10,    11,    12,
+      13,     0,     0,     0,    14,    15,     0,     0,     0,     0,
+       0,     0,     0,     0,     0,    68,     0,    27,     0,    69,
+       0,     0,     0,     0,    34,   116,   117,   118,     0,     0,
+       0,     0,     0,     0,     0,     0,    74,     0,     0,     0,
+       0,     0,     0,     0,     0,     0,    42
 };
 
 static const yytype_int16 yycheck[] =
 {
-      34,    47,    93,    49,    50,     3,    44,     0,     0,     1,
-      48,    47,    89,     5,     6,     7,     8,     9,    10,    11,
-      12,    13,    56,    54,     3,    17,    18,     3,    41,    44,
-     158,     3,     4,    48,    87,    48,    53,   165,    30,    54,
-     131,    87,    51,    89,    53,    37,    44,    93,   125,    95,
-      48,    87,    86,    89,     3,    57,    54,    49,    50,    48,
-      57,     3,   139,     3,     3,    44,   100,    59,    44,    48,
-     101,     3,    48,   126,    14,    15,    16,    41,    54,   125,
-     126,    21,    22,     3,   130,   131,     3,   121,     3,   125,
-     126,     3,     3,   139,   140,    44,    48,   133,    41,    48,
-     134,    41,    42,   139,    44,    54,    55,    56,    48,    41,
-      54,    41,   146,    41,    54,   149,    48,    53,    53,    43,
-      60,    46,     1,    41,     2,   159,     5,     6,     7,     8,
-       9,    10,    11,    12,    13,    54,    57,    41,    17,    18,
-      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
-      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
-      39,    40,    95,    54,    45,    57,    54,    57,    57,    41,
-     121,    50,   147,    52,    53,    50,    79,     1,    -1,    58,
-      59,     5,     6,     7,     8,     9,    10,    11,    12,    13,
-      97,    -1,    -1,    17,    18,    -1,    -1,   130,    -1,    -1,
-      -1,    -1,    -1,    -1,    -1,    -1,    30,   140,    -1,    -1,
-      -1,    -1,    -1,    37,    -1,    -1,    -1,    -1,    -1,    -1,
-      -1,    -1,    -1,    -1,    -1,    49,    -1,    -1,    -1,    -1,
-      -1,    -1,    -1,    -1,    -1,    59
+      34,    47,    86,    49,    50,    92,    97,     3,    41,     0,
+      51,    47,    53,   159,    53,    48,     3,     0,     1,    84,
+     166,    90,     5,     6,     7,     8,     9,    10,    11,    12,
+      13,    48,    44,    44,    17,    18,    48,    48,    84,   123,
+      86,   128,   133,    54,    90,    41,    92,    30,    84,    83,
+      86,     3,    48,   140,    37,   139,     3,    44,    57,   124,
+     129,    48,    14,    15,    16,    99,    49,    50,    57,    21,
+      22,     3,     4,     3,     3,     3,    59,   123,   124,    41,
+       3,     3,   128,   129,     3,   119,     3,   123,   124,    41,
+      42,     3,    44,   139,   140,   131,    48,    44,   132,    48,
+      41,    48,    54,   139,    41,    53,    41,    54,    60,    53,
+     144,    54,    43,   147,    44,    41,   150,    57,    48,    46,
+      54,    54,     2,     1,    54,    41,   160,     5,     6,     7,
+       8,     9,    10,    11,    12,    13,    45,    57,    41,    17,
+      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
+      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
+      38,    39,    40,    54,     3,    57,   119,    57,    50,    94,
+      76,   148,    50,    -1,    52,    53,    -1,    -1,     1,    -1,
+      58,    59,     5,     6,     7,     8,     9,    10,    11,    12,
+      13,    -1,    -1,    -1,    17,    18,    -1,    -1,    -1,    -1,
+      -1,    -1,    -1,    -1,    -1,    44,    -1,    30,    -1,    48,
+      -1,    -1,    -1,    -1,    37,    54,    55,    56,    -1,    -1,
+      -1,    -1,    -1,    -1,    -1,    -1,    49,    -1,    -1,    -1,
+      -1,    -1,    -1,    -1,    -1,    -1,    59
 };
 
   /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
@@ -875,19 +876,19 @@ static const yytype_int8 yystos[] =
       10,    11,    12,    13,    17,    18,    19,    20,    21,    22,
       23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
       33,    34,    35,    36,    37,    38,    39,    40,    50,    52,
-      53,    58,    59,    64,    67,    68,    70,    73,    53,    72,
-      71,     3,    44,    48,    54,    88,    89,    99,   101,   102,
-      41,    48,    48,    97,    57,    57,     3,     3,    74,    41,
-       3,     3,     3,     3,     3,   101,     1,    49,    67,    90,
-      91,    92,   100,    65,    48,    69,    41,    54,    85,    86,
-      87,    99,   102,    54,    80,    81,    82,    99,    79,    80,
-      89,    54,   101,    41,     3,    41,    48,    98,    53,    53,
-      50,    91,   103,    43,    96,    41,    66,    41,    54,    55,
-      56,    76,    77,    78,   101,    86,    54,    87,    57,    83,
-      81,    54,    82,    83,    89,    46,    93,    41,    77,    86,
-      81,     4,    84,   102,    45,    94,    95,    51,    53,    14,
-      15,    16,    21,    22,    42,    54,    60,    75,   101,    95,
-     101,    57,    54,    57,    57,    41,    96,    96
+      53,    58,    59,    64,    67,    68,    70,    74,    53,    72,
+      71,    73,    41,    48,    48,    98,    57,    57,     3,     3,
+      75,    41,     3,     3,     3,     3,     3,     3,    44,    48,
+     100,   102,   103,     1,    49,    67,    91,    92,    93,   101,
+      65,    48,    69,    41,    54,    86,    87,    88,   100,   103,
+      54,    81,    82,    83,   100,    80,    81,    54,    89,    90,
+     102,    41,     3,    41,    48,    99,    53,    53,    50,    92,
+     104,    43,    97,    41,    66,    41,    54,    55,    56,    77,
+      78,    79,   102,    87,    54,    88,    57,    84,    82,    54,
+      83,    84,    90,    54,   102,    46,    94,    41,    78,    87,
+      82,     4,    85,   103,    90,    45,    95,    96,    51,    53,
+      14,    15,    16,    21,    22,    42,    54,    60,    76,   102,
+      96,   102,    57,    54,    57,    57,    41,    97,    97
 };
 
   /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
@@ -897,15 +898,15 @@ static const yytype_int8 yyr1[] =
       64,    64,    64,    64,    64,    64,    64,    64,    64,    64,
       64,    65,    64,    64,    64,    64,    64,    64,    64,    64,
       64,    66,    66,    67,    67,    67,    67,    67,    67,    67,
-      68,    68,    69,    69,    67,    71,    70,    72,    70,    70,
-      70,    73,    73,    73,    73,    74,    74,    75,    75,    76,
-      76,    77,    77,    78,    78,    78,    79,    80,    80,    80,
-      81,    81,    82,    83,    83,    84,    84,    84,    85,    85,
-      85,    86,    86,    87,    87,    88,    88,    88,    89,    89,
-      90,    90,    91,    91,    91,    93,    92,    94,    94,    94,
-      95,    95,    95,    95,    95,    95,    95,    95,    95,    95,
-      96,    96,    97,    98,    98,    98,    98,    99,    99,   100,
-     101,   101,   102,   103,   103
+      68,    68,    69,    69,    67,    71,    70,    72,    70,    73,
+      70,    70,    74,    74,    74,    74,    75,    75,    76,    76,
+      77,    77,    78,    78,    79,    79,    79,    80,    81,    81,
+      81,    82,    82,    83,    84,    84,    85,    85,    85,    86,
+      86,    86,    87,    87,    88,    88,    89,    89,    89,    90,
+      90,    91,    91,    92,    92,    92,    94,    93,    95,    95,
+      95,    96,    96,    96,    96,    96,    96,    96,    96,    96,
+      96,    97,    97,    98,    99,    99,    99,    99,   100,   100,
+     101,   102,   102,   103,   104,   104
 };
 
   /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
@@ -915,15 +916,15 @@ static const yytype_int8 yyr2[] =
        1,     2,     2,     2,     1,     2,     2,     2,     1,     1,
        2,     0,     3,     1,     2,     2,     1,     1,     1,     2,
        1,     2,     1,     1,     2,     3,     1,     1,     2,     3,
-       1,     1,     0,     1,     3,     0,     3,     0,     3,     2,
-       2,     1,     1,     1,     1,     0,     1,     0,     1,     1,
-       2,     1,     1,     1,     1,     1,     1,     1,     2,     3,
-       1,     2,     3,     0,     1,     0,     1,     1,     1,     2,
-       3,     1,     2,     2,     1,     1,     2,     3,     1,     2,
-       1,     2,     1,     2,     2,     0,     5,     1,     3,     2,
-       0,     3,     4,     2,     2,     3,     3,     3,     3,     3,
-       0,     1,     1,     0,     1,     1,     1,     1,     1,     1,
-       1,     1,     1,     0,     2
+       1,     1,     0,     1,     3,     0,     3,     0,     3,     0,
+       3,     2,     1,     1,     1,     1,     0,     1,     0,     1,
+       1,     2,     1,     1,     1,     1,     1,     1,     1,     2,
+       3,     1,     2,     3,     0,     1,     0,     1,     1,     1,
+       2,     3,     1,     2,     2,     1,     1,     2,     3,     1,
+       2,     1,     2,     1,     2,     2,     0,     5,     1,     3,
+       2,     0,     3,     4,     2,     2,     3,     3,     3,     3,
+       3,     0,     1,     1,     0,     1,     1,     1,     1,     1,
+       1,     1,     1,     1,     0,     2
 };
 
 
@@ -1169,12 +1170,12 @@ tron (yyo);
          { fprintf (yyo, "%s", code_props_type_string (((*yyvaluep).code_props_type))); }
         break;
 
-    case YYSYMBOL_74_string_opt: /* string.opt  */
-         { fputs (((*yyvaluep).yykind_74), yyo); }
+    case YYSYMBOL_75_string_opt: /* string.opt  */
+         { fputs (((*yyvaluep).yykind_75), yyo); }
         break;
 
-    case YYSYMBOL_75_tag_opt: /* tag.opt  */
-         { fputs (((*yyvaluep).yykind_75), yyo); }
+    case YYSYMBOL_76_tag_opt: /* tag.opt  */
+         { fputs (((*yyvaluep).yykind_76), yyo); }
         break;
 
     case YYSYMBOL_generic_symlist: /* generic_symlist  */
@@ -1197,16 +1198,16 @@ tron (yyo);
          { symbol_list_syms_print (((*yyvaluep).token_decls), yyo); }
         break;
 
-    case YYSYMBOL_81_token_decl_1: /* token_decl.1  */
-         { symbol_list_syms_print (((*yyvaluep).yykind_81), yyo); }
+    case YYSYMBOL_82_token_decl_1: /* token_decl.1  */
+         { symbol_list_syms_print (((*yyvaluep).yykind_82), yyo); }
         break;
 
     case YYSYMBOL_token_decl: /* token_decl  */
          { fprintf (yyo, "%s", ((*yyvaluep).token_decl) ? ((*yyvaluep).token_decl)->tag : "<NULL>"); }
         break;
 
-    case YYSYMBOL_83_int_opt: /* int.opt  */
-         { fprintf (yyo, "%d", ((*yyvaluep).yykind_83)); }
+    case YYSYMBOL_84_int_opt: /* int.opt  */
+         { fprintf (yyo, "%d", ((*yyvaluep).yykind_84)); }
         break;
 
     case YYSYMBOL_alias: /* alias  */
@@ -1217,8 +1218,8 @@ tron (yyo);
          { symbol_list_syms_print (((*yyvaluep).token_decls_for_prec), yyo); }
         break;
 
-    case YYSYMBOL_86_token_decl_for_prec_1: /* token_decl_for_prec.1  */
-         { symbol_list_syms_print (((*yyvaluep).yykind_86), yyo); }
+    case YYSYMBOL_87_token_decl_for_prec_1: /* token_decl_for_prec.1  */
+         { symbol_list_syms_print (((*yyvaluep).yykind_87), yyo); }
         break;
 
     case YYSYMBOL_token_decl_for_prec: /* token_decl_for_prec  */
@@ -1229,8 +1230,8 @@ tron (yyo);
          { symbol_list_syms_print (((*yyvaluep).symbol_decls), yyo); }
         break;
 
-    case YYSYMBOL_89_symbol_decl_1: /* symbol_decl.1  */
-         { symbol_list_syms_print (((*yyvaluep).yykind_89), yyo); }
+    case YYSYMBOL_90_symbols_1: /* symbols.1  */
+         { symbol_list_syms_print (((*yyvaluep).yykind_90), yyo); }
         break;
 
     case YYSYMBOL_variable: /* variable  */
@@ -1726,24 +1727,24 @@ yydestruct (const char *yymsg,
             { symbol_list_free (((*yyvaluep).token_decls)); }
         break;
 
-    case YYSYMBOL_81_token_decl_1: /* token_decl.1  */
-            { symbol_list_free (((*yyvaluep).yykind_81)); }
+    case YYSYMBOL_82_token_decl_1: /* token_decl.1  */
+            { symbol_list_free (((*yyvaluep).yykind_82)); }
         break;
 
     case YYSYMBOL_token_decls_for_prec: /* token_decls_for_prec  */
             { symbol_list_free (((*yyvaluep).token_decls_for_prec)); }
         break;
 
-    case YYSYMBOL_86_token_decl_for_prec_1: /* token_decl_for_prec.1  */
-            { symbol_list_free (((*yyvaluep).yykind_86)); }
+    case YYSYMBOL_87_token_decl_for_prec_1: /* token_decl_for_prec.1  */
+            { symbol_list_free (((*yyvaluep).yykind_87)); }
         break;
 
     case YYSYMBOL_symbol_decls: /* symbol_decls  */
             { symbol_list_free (((*yyvaluep).symbol_decls)); }
         break;
 
-    case YYSYMBOL_89_symbol_decl_1: /* symbol_decl.1  */
-            { symbol_list_free (((*yyvaluep).yykind_89)); }
+    case YYSYMBOL_90_symbols_1: /* symbols.1  */
+            { symbol_list_free (((*yyvaluep).yykind_90)); }
         break;
 
       default:
@@ -2086,7 +2087,7 @@ yyreduce:
     break;
 
   case 9: /* prologue_declaration: "%header" string.opt  */
-                                   { handle_header ((yyvsp[0].yykind_74)); }
+                                   { handle_header ((yyvsp[0].yykind_75)); }
     break;
 
   case 10: /* prologue_declaration: "%error-verbose"  */
@@ -2279,13 +2280,18 @@ yyreduce:
     }
     break;
 
-  case 49: /* symbol_declaration: "%type" symbol_decls  */
+  case 49: /* $@4: %empty  */
+          { current_class = pct_type_sym; }
+    break;
+
+  case 50: /* symbol_declaration: "%type" $@4 symbol_decls  */
     {
+      current_class = unknown_sym;
       symbol_list_free ((yyvsp[0].symbol_decls));
     }
     break;
 
-  case 50: /* symbol_declaration: precedence_declarator token_decls_for_prec  */
+  case 51: /* symbol_declaration: precedence_declarator token_decls_for_prec  */
     {
       ++current_prec;
       for (symbol_list *list = (yyvsp[0].token_decls_for_prec); list; list = list->next)
@@ -2294,108 +2300,108 @@ yyreduce:
     }
     break;
 
-  case 51: /* precedence_declarator: "%left"  */
+  case 52: /* precedence_declarator: "%left"  */
                 { (yyval.precedence_declarator) = left_assoc; }
     break;
 
-  case 52: /* precedence_declarator: "%right"  */
+  case 53: /* precedence_declarator: "%right"  */
                 { (yyval.precedence_declarator) = right_assoc; }
     break;
 
-  case 53: /* precedence_declarator: "%nonassoc"  */
+  case 54: /* precedence_declarator: "%nonassoc"  */
                 { (yyval.precedence_declarator) = non_assoc; }
     break;
 
-  case 54: /* precedence_declarator: "%precedence"  */
+  case 55: /* precedence_declarator: "%precedence"  */
                 { (yyval.precedence_declarator) = precedence_assoc; }
     break;
 
-  case 55: /* string.opt: %empty  */
-          { (yyval.yykind_74) = NULL; }
+  case 56: /* string.opt: %empty  */
+          { (yyval.yykind_75) = NULL; }
     break;
 
-  case 56: /* string.opt: "string"  */
-          { (yyval.yykind_74) = (yyvsp[0].STRING); }
+  case 57: /* string.opt: "string"  */
+          { (yyval.yykind_75) = (yyvsp[0].STRING); }
     break;
 
-  case 57: /* tag.opt: %empty  */
-         { (yyval.yykind_75) = NULL; }
+  case 58: /* tag.opt: %empty  */
+         { (yyval.yykind_76) = NULL; }
     break;
 
-  case 58: /* tag.opt: "<tag>"  */
-         { (yyval.yykind_75) = (yyvsp[0].TAG); }
+  case 59: /* tag.opt: "<tag>"  */
+         { (yyval.yykind_76) = (yyvsp[0].TAG); }
     break;
 
-  case 60: /* generic_symlist: generic_symlist generic_symlist_item  */
+  case 61: /* generic_symlist: generic_symlist generic_symlist_item  */
                                          { (yyval.generic_symlist) = symbol_list_append ((yyvsp[-1].generic_symlist), (yyvsp[0].generic_symlist_item)); }
     break;
 
-  case 61: /* generic_symlist_item: symbol  */
+  case 62: /* generic_symlist_item: symbol  */
             { (yyval.generic_symlist_item) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
     break;
 
-  case 62: /* generic_symlist_item: tag  */
+  case 63: /* generic_symlist_item: tag  */
             { (yyval.generic_symlist_item) = symbol_list_type_new ((yyvsp[0].tag), (yylsp[0])); }
     break;
 
-  case 64: /* tag: "<*>"  */
+  case 65: /* tag: "<*>"  */
         { (yyval.tag) = uniqstr_new ("*"); }
     break;
 
-  case 65: /* tag: "<>"  */
+  case 66: /* tag: "<>"  */
         { (yyval.tag) = uniqstr_new (""); }
     break;
 
-  case 67: /* token_decls: token_decl.1  */
+  case 68: /* token_decls: token_decl.1  */
     {
-      (yyval.token_decls) = (yyvsp[0].yykind_81);
+      (yyval.token_decls) = (yyvsp[0].yykind_82);
     }
     break;
 
-  case 68: /* token_decls: "<tag>" token_decl.1  */
+  case 69: /* token_decls: "<tag>" token_decl.1  */
     {
-      (yyval.token_decls) = symbol_list_type_set ((yyvsp[0].yykind_81), (yyvsp[-1].TAG));
+      (yyval.token_decls) = symbol_list_type_set ((yyvsp[0].yykind_82), (yyvsp[-1].TAG));
     }
     break;
 
-  case 69: /* token_decls: token_decls "<tag>" token_decl.1  */
+  case 70: /* token_decls: token_decls "<tag>" token_decl.1  */
     {
-      (yyval.token_decls) = symbol_list_append ((yyvsp[-2].token_decls), symbol_list_type_set ((yyvsp[0].yykind_81), (yyvsp[-1].TAG)));
+      (yyval.token_decls) = symbol_list_append ((yyvsp[-2].token_decls), symbol_list_type_set ((yyvsp[0].yykind_82), (yyvsp[-1].TAG)));
     }
     break;
 
-  case 70: /* token_decl.1: token_decl  */
-                            { (yyval.yykind_81) = symbol_list_sym_new ((yyvsp[0].token_decl), (yylsp[0])); }
+  case 71: /* token_decl.1: token_decl  */
+                            { (yyval.yykind_82) = symbol_list_sym_new ((yyvsp[0].token_decl), (yylsp[0])); }
     break;
 
-  case 71: /* token_decl.1: token_decl.1 token_decl  */
-                            { (yyval.yykind_81) = symbol_list_append ((yyvsp[-1].yykind_81), symbol_list_sym_new ((yyvsp[0].token_decl), (yylsp[0]))); }
+  case 72: /* token_decl.1: token_decl.1 token_decl  */
+                            { (yyval.yykind_82) = symbol_list_append ((yyvsp[-1].yykind_82), symbol_list_sym_new ((yyvsp[0].token_decl), (yylsp[0]))); }
     break;
 
-  case 72: /* token_decl: id int.opt alias  */
+  case 73: /* token_decl: id int.opt alias  */
     {
       (yyval.token_decl) = (yyvsp[-2].id);
       symbol_class_set ((yyvsp[-2].id), current_class, (yylsp[-2]), true);
-      if (0 <= (yyvsp[-1].yykind_83))
-        symbol_code_set ((yyvsp[-2].id), (yyvsp[-1].yykind_83), (yylsp[-1]));
+      if (0 <= (yyvsp[-1].yykind_84))
+        symbol_code_set ((yyvsp[-2].id), (yyvsp[-1].yykind_84), (yylsp[-1]));
       if ((yyvsp[0].alias))
         symbol_make_alias ((yyvsp[-2].id), (yyvsp[0].alias), (yylsp[0]));
     }
     break;
 
-  case 73: /* int.opt: %empty  */
-          { (yyval.yykind_83) = -1; }
+  case 74: /* int.opt: %empty  */
+          { (yyval.yykind_84) = -1; }
     break;
 
-  case 75: /* alias: %empty  */
+  case 76: /* alias: %empty  */
                  { (yyval.alias) = NULL; }
     break;
 
-  case 76: /* alias: string_as_id  */
+  case 77: /* alias: string_as_id  */
                  { (yyval.alias) = (yyvsp[0].string_as_id); }
     break;
 
-  case 77: /* alias: "translatable string"  */
+  case 78: /* alias: "translatable string"  */
     {
       (yyval.alias) = symbol_get ((yyvsp[0].TSTRING), (yylsp[0]));
       symbol_class_set ((yyval.alias), token_sym, (yylsp[0]), false);
@@ -2403,168 +2409,170 @@ yyreduce:
     }
     break;
 
-  case 78: /* token_decls_for_prec: token_decl_for_prec.1  */
+  case 79: /* token_decls_for_prec: token_decl_for_prec.1  */
     {
-      (yyval.token_decls_for_prec) = (yyvsp[0].yykind_86);
+      (yyval.token_decls_for_prec) = (yyvsp[0].yykind_87);
     }
     break;
 
-  case 79: /* token_decls_for_prec: "<tag>" token_decl_for_prec.1  */
+  case 80: /* token_decls_for_prec: "<tag>" token_decl_for_prec.1  */
     {
-      (yyval.token_decls_for_prec) = symbol_list_type_set ((yyvsp[0].yykind_86), (yyvsp[-1].TAG));
+      (yyval.token_decls_for_prec) = symbol_list_type_set ((yyvsp[0].yykind_87), (yyvsp[-1].TAG));
     }
     break;
 
-  case 80: /* token_decls_for_prec: token_decls_for_prec "<tag>" token_decl_for_prec.1  */
+  case 81: /* token_decls_for_prec: token_decls_for_prec "<tag>" token_decl_for_prec.1  */
     {
-      (yyval.token_decls_for_prec) = symbol_list_append ((yyvsp[-2].token_decls_for_prec), symbol_list_type_set ((yyvsp[0].yykind_86), (yyvsp[-1].TAG)));
+      (yyval.token_decls_for_prec) = symbol_list_append ((yyvsp[-2].token_decls_for_prec), symbol_list_type_set ((yyvsp[0].yykind_87), (yyvsp[-1].TAG)));
     }
     break;
 
-  case 81: /* token_decl_for_prec.1: token_decl_for_prec  */
-    { (yyval.yykind_86) = symbol_list_sym_new ((yyvsp[0].token_decl_for_prec), (yylsp[0])); }
+  case 82: /* token_decl_for_prec.1: token_decl_for_prec  */
+    { (yyval.yykind_87) = symbol_list_sym_new ((yyvsp[0].token_decl_for_prec), (yylsp[0])); }
     break;
 
-  case 82: /* token_decl_for_prec.1: token_decl_for_prec.1 token_decl_for_prec  */
-    { (yyval.yykind_86) = symbol_list_append ((yyvsp[-1].yykind_86), symbol_list_sym_new ((yyvsp[0].token_decl_for_prec), (yylsp[0]))); }
+  case 83: /* token_decl_for_prec.1: token_decl_for_prec.1 token_decl_for_prec  */
+    { (yyval.yykind_87) = symbol_list_append ((yyvsp[-1].yykind_87), symbol_list_sym_new ((yyvsp[0].token_decl_for_prec), (yylsp[0]))); }
     break;
 
-  case 83: /* token_decl_for_prec: id int.opt  */
+  case 84: /* token_decl_for_prec: id int.opt  */
     {
       (yyval.token_decl_for_prec) = (yyvsp[-1].id);
       symbol_class_set ((yyvsp[-1].id), token_sym, (yylsp[-1]), false);
-      if (0 <= (yyvsp[0].yykind_83))
-        symbol_code_set ((yyvsp[-1].id), (yyvsp[0].yykind_83), (yylsp[0]));
+      if (0 <= (yyvsp[0].yykind_84))
+        symbol_code_set ((yyvsp[-1].id), (yyvsp[0].yykind_84), (yylsp[0]));
     }
     break;
 
-  case 85: /* symbol_decls: symbol_decl.1  */
+  case 86: /* symbol_decls: symbols.1  */
     {
-      (yyval.symbol_decls) = (yyvsp[0].yykind_89);
+      (yyval.symbol_decls) = (yyvsp[0].yykind_90);
     }
     break;
 
-  case 86: /* symbol_decls: "<tag>" symbol_decl.1  */
+  case 87: /* symbol_decls: "<tag>" symbols.1  */
     {
-      (yyval.symbol_decls) = symbol_list_type_set ((yyvsp[0].yykind_89), (yyvsp[-1].TAG));
+      (yyval.symbol_decls) = symbol_list_type_set ((yyvsp[0].yykind_90), (yyvsp[-1].TAG));
     }
     break;
 
-  case 87: /* symbol_decls: symbol_decls "<tag>" symbol_decl.1  */
+  case 88: /* symbol_decls: symbol_decls "<tag>" symbols.1  */
     {
-      (yyval.symbol_decls) = symbol_list_append ((yyvsp[-2].symbol_decls), symbol_list_type_set ((yyvsp[0].yykind_89), (yyvsp[-1].TAG)));
+      (yyval.symbol_decls) = symbol_list_append ((yyvsp[-2].symbol_decls), symbol_list_type_set ((yyvsp[0].yykind_90), (yyvsp[-1].TAG)));
     }
     break;
 
-  case 88: /* symbol_decl.1: symbol  */
+  case 89: /* symbols.1: symbol  */
     {
-      symbol_class_set ((yyvsp[0].symbol), pct_type_sym, (yylsp[0]), false);
-      (yyval.yykind_89) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]));
+      if (current_class != unknown_sym)
+        symbol_class_set ((yyvsp[0].symbol), current_class, (yylsp[0]), false);
+      (yyval.yykind_90) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]));
     }
     break;
 
-  case 89: /* symbol_decl.1: symbol_decl.1 symbol  */
+  case 90: /* symbols.1: symbols.1 symbol  */
     {
-      symbol_class_set ((yyvsp[0].symbol), pct_type_sym, (yylsp[0]), false);
-      (yyval.yykind_89) = symbol_list_append ((yyvsp[-1].yykind_89), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])));
+      if (current_class != unknown_sym)
+        symbol_class_set ((yyvsp[0].symbol), current_class, (yylsp[0]), false);
+      (yyval.yykind_90) = symbol_list_append ((yyvsp[-1].yykind_90), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])));
     }
     break;
 
-  case 94: /* rules_or_grammar_declaration: error ";"  */
+  case 95: /* rules_or_grammar_declaration: error ";"  */
     {
       yyerrok;
     }
     break;
 
-  case 95: /* $@4: %empty  */
-                         { current_lhs ((yyvsp[-1].id_colon), (yylsp[-1]), (yyvsp[0].yykind_96)); }
+  case 96: /* $@5: %empty  */
+                         { current_lhs ((yyvsp[-1].id_colon), (yylsp[-1]), (yyvsp[0].yykind_97)); }
     break;
 
-  case 96: /* rules: id_colon named_ref.opt $@4 ":" rhses.1  */
+  case 97: /* rules: id_colon named_ref.opt $@5 ":" rhses.1  */
     {
       /* Free the current lhs. */
       current_lhs (0, (yylsp[-4]), 0);
     }
     break;
 
-  case 97: /* rhses.1: rhs  */
+  case 98: /* rhses.1: rhs  */
                      { grammar_current_rule_end ((yylsp[0])); }
     break;
 
-  case 98: /* rhses.1: rhses.1 "|" rhs  */
+  case 99: /* rhses.1: rhses.1 "|" rhs  */
                      { grammar_current_rule_end ((yylsp[0])); }
     break;
 
-  case 100: /* rhs: %empty  */
+  case 101: /* rhs: %empty  */
     { grammar_current_rule_begin (current_lhs_symbol, current_lhs_loc,
                                   current_lhs_named_ref); }
     break;
 
-  case 101: /* rhs: rhs symbol named_ref.opt  */
-    { grammar_current_rule_symbol_append ((yyvsp[-1].symbol), (yylsp[-1]), (yyvsp[0].yykind_96)); }
+  case 102: /* rhs: rhs symbol named_ref.opt  */
+    { grammar_current_rule_symbol_append ((yyvsp[-1].symbol), (yylsp[-1]), (yyvsp[0].yykind_97)); }
     break;
 
-  case 102: /* rhs: rhs tag.opt "{...}" named_ref.opt  */
-    { grammar_current_rule_action_append ((yyvsp[-1].BRACED_CODE), (yylsp[-1]), (yyvsp[0].yykind_96), (yyvsp[-2].yykind_75)); }
+  case 103: /* rhs: rhs tag.opt "{...}" named_ref.opt  */
+    { grammar_current_rule_action_append ((yyvsp[-1].BRACED_CODE), (yylsp[-1]), (yyvsp[0].yykind_97), (yyvsp[-2].yykind_76)); }
     break;
 
-  case 103: /* rhs: rhs "%?{...}"  */
+  case 104: /* rhs: rhs "%?{...}"  */
     { grammar_current_rule_predicate_append ((yyvsp[0].BRACED_PREDICATE), (yylsp[0])); }
     break;
 
-  case 104: /* rhs: rhs "%empty"  */
+  case 105: /* rhs: rhs "%empty"  */
     { grammar_current_rule_empty_set ((yylsp[0])); }
     break;
 
-  case 105: /* rhs: rhs "%prec" symbol  */
+  case 106: /* rhs: rhs "%prec" symbol  */
     { grammar_current_rule_prec_set ((yyvsp[0].symbol), (yylsp[0])); }
     break;
 
-  case 106: /* rhs: rhs "%dprec" "integer literal"  */
+  case 107: /* rhs: rhs "%dprec" "integer literal"  */
     { grammar_current_rule_dprec_set ((yyvsp[0].INT_LITERAL), (yylsp[0])); }
     break;
 
-  case 107: /* rhs: rhs "%merge" "<tag>"  */
+  case 108: /* rhs: rhs "%merge" "<tag>"  */
     { grammar_current_rule_merge_set ((yyvsp[0].TAG), (yylsp[0])); }
     break;
 
-  case 108: /* rhs: rhs "%expect" "integer literal"  */
+  case 109: /* rhs: rhs "%expect" "integer literal"  */
     { grammar_current_rule_expect_sr ((yyvsp[0].INT_LITERAL), (yylsp[0])); }
     break;
 
-  case 109: /* rhs: rhs "%expect-rr" "integer literal"  */
+  case 110: /* rhs: rhs "%expect-rr" "integer literal"  */
     { grammar_current_rule_expect_rr ((yyvsp[0].INT_LITERAL), (yylsp[0])); }
     break;
 
-  case 110: /* named_ref.opt: %empty  */
-                 { (yyval.yykind_96) = NULL; }
+  case 111: /* named_ref.opt: %empty  */
+                 { (yyval.yykind_97) = NULL; }
     break;
 
-  case 111: /* named_ref.opt: "[identifier]"  */
-                 { (yyval.yykind_96) = named_ref_new ((yyvsp[0].BRACKETED_ID), (yylsp[0])); }
+  case 112: /* named_ref.opt: "[identifier]"  */
+                 { (yyval.yykind_97) = named_ref_new ((yyvsp[0].BRACKETED_ID), (yylsp[0])); }
     break;
 
-  case 113: /* value: %empty  */
+  case 114: /* value: %empty  */
           { (yyval.value).kind = muscle_keyword; (yyval.value).chars = ""; }
     break;
 
-  case 114: /* value: "identifier"  */
+  case 115: /* value: "identifier"  */
           { (yyval.value).kind = muscle_keyword; (yyval.value).chars = (yyvsp[0].ID); }
     break;
 
-  case 115: /* value: "string"  */
+  case 116: /* value: "string"  */
           { (yyval.value).kind = muscle_string;  (yyval.value).chars = unquote ((yyvsp[0].STRING)); gram_scanner_last_string_free ();}
     break;
 
-  case 116: /* value: "{...}"  */
+  case 117: /* value: "{...}"  */
           { (yyval.value).kind = muscle_code;    (yyval.value).chars = strip_braces ((yyvsp[0].BRACED_CODE)); gram_scanner_last_string_free (); }
     break;
 
-  case 117: /* id: "identifier"  */
+  case 118: /* id: "identifier"  */
     { (yyval.id) = symbol_from_uniqstr ((yyvsp[0].ID), (yylsp[0])); }
     break;
 
-  case 118: /* id: "character literal"  */
+  case 119: /* id: "character literal"  */
     {
       const char *var = "api.token.raw";
       if (current_class == nterm_sym)
@@ -2587,18 +2595,18 @@ yyreduce:
     }
     break;
 
-  case 119: /* id_colon: "identifier:"  */
+  case 120: /* id_colon: "identifier:"  */
            { (yyval.id_colon) = symbol_from_uniqstr ((yyvsp[0].ID_COLON), (yylsp[0])); }
     break;
 
-  case 122: /* string_as_id: "string"  */
+  case 123: /* string_as_id: "string"  */
     {
       (yyval.string_as_id) = symbol_get ((yyvsp[0].STRING), (yylsp[0]));
       symbol_class_set ((yyval.string_as_id), token_sym, (yylsp[0]), false);
     }
     break;
 
-  case 124: /* epilogue.opt: "%%" "epilogue"  */
+  case 125: /* epilogue.opt: "%%" "epilogue"  */
     {
       muscle_code_grow ("epilogue", translate_code ((yyvsp[0].EPILOGUE), (yylsp[0]), true), (yylsp[0]));
       code_scanner_last_string_free ();
