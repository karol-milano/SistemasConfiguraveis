@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 3.3.2.153-f5a4-dirty.  */
+/* A Bison parser, made by GNU Bison 3.3.91.21-ba0ae5-dirty.  */
 
 /* Bison implementation for Yacc-like parsers in C
 
@@ -48,7 +48,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "3.3.2.153-f5a4-dirty"
+#define YYBISON_VERSION "3.3.91.21-ba0ae5-dirty"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -167,6 +167,9 @@
   static void handle_name_prefix (location const *loc,
                                   char const *directive, char const *value);
 
+  /* Handle a %pure-parser directive.  */
+  static void handle_pure_parser (location const *loc, char const *directive);
+
   /* Handle a %require directive.  */
   static void handle_require (location const *loc, char const *version);
 
@@ -412,19 +415,19 @@ union yyalloc
 /* YYFINAL -- State number of the termination state.  */
 #define YYFINAL  3
 /* YYLAST -- Last index in YYTABLE.  */
-#define YYLAST   232
+#define YYLAST   234
 
 /* YYNTOKENS -- Number of terminals.  */
-#define YYNTOKENS  59
+#define YYNTOKENS  60
 /* YYNNTS -- Number of nonterminals.  */
 #define YYNNTS  42
 /* YYNRULES -- Number of rules.  */
-#define YYNRULES  121
+#define YYNRULES  122
 /* YYNSTATES -- Number of states.  */
-#define YYNSTATES  165
+#define YYNSTATES  166
 
 #define YYUNDEFTOK  2
-#define YYMAXUTOK   313
+#define YYMAXUTOK   314
 
 /* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
    as returned by yylex, with out-of-bounds checking.  */
@@ -466,26 +469,26 @@ static const yytype_uint8 yytranslate[] =
       25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
       35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
       45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
-      55,    56,    57,    58
+      55,    56,    57,    58,    59
 };
 
 #if GRAM_DEBUG
   /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
 static const yytype_uint16 yyrline[] =
 {
-       0,   290,   290,   299,   300,   304,   305,   311,   315,   320,
-     321,   326,   327,   328,   329,   330,   335,   340,   341,   342,
-     343,   344,   345,   345,   346,   347,   348,   349,   350,   351,
-     352,   356,   357,   366,   367,   371,   382,   386,   390,   398,
-     408,   409,   419,   420,   426,   439,   439,   444,   444,   449,
-     453,   463,   464,   465,   466,   470,   471,   476,   477,   481,
-     482,   486,   487,   488,   501,   510,   514,   518,   526,   527,
-     531,   544,   545,   557,   561,   565,   573,   575,   580,   587,
-     597,   601,   605,   613,   614,   622,   623,   629,   630,   631,
-     638,   638,   646,   647,   648,   653,   656,   658,   660,   662,
-     664,   666,   668,   670,   672,   677,   678,   687,   711,   712,
-     713,   714,   726,   728,   743,   748,   749,   754,   763,   764,
-     768,   769
+       0,   294,   294,   303,   304,   308,   309,   315,   319,   324,
+     325,   330,   331,   332,   333,   334,   339,   344,   345,   346,
+     347,   348,   349,   349,   350,   351,   352,   353,   354,   355,
+     356,   357,   361,   362,   371,   372,   376,   387,   391,   395,
+     403,   413,   414,   424,   425,   431,   444,   444,   449,   449,
+     454,   458,   468,   469,   470,   471,   475,   476,   481,   482,
+     486,   487,   491,   492,   493,   506,   515,   519,   523,   531,
+     532,   536,   549,   550,   562,   566,   570,   578,   580,   585,
+     592,   602,   606,   610,   618,   619,   627,   628,   634,   635,
+     636,   643,   643,   651,   652,   653,   658,   661,   663,   665,
+     667,   669,   671,   673,   675,   677,   682,   683,   692,   716,
+     717,   718,   719,   731,   733,   748,   753,   754,   759,   768,
+     769,   773,   774
 };
 #endif
 
@@ -502,22 +505,22 @@ static const char *const yytname[] =
   "\"%expect\"", "\"%expect-rr\"", "\"%<flag>\"", "\"%file-prefix\"",
   "\"%glr-parser\"", "\"%initial-action\"", "\"%language\"",
   "\"%name-prefix\"", "\"%no-default-prec\"", "\"%no-lines\"",
-  "\"%nondeterministic-parser\"", "\"%output\"", "\"%require\"",
-  "\"%skeleton\"", "\"%start\"", "\"%token-table\"", "\"%verbose\"",
-  "\"%yacc\"", "\"{...}\"", "\"%?{...}\"", "\"[identifier]\"", "\"char\"",
-  "\":\"", "\"epilogue\"", "\"=\"", "\"identifier\"", "\"identifier:\"",
-  "\"%%\"", "\"|\"", "\"%{...%}\"", "\";\"", "\"<tag>\"", "\"<*>\"",
-  "\"<>\"", "\"integer\"", "\"%param\"", "\"%union\"", "\"%empty\"",
-  "$accept", "input", "prologue_declarations", "prologue_declaration",
-  "$@1", "params", "grammar_declaration", "code_props_type", "union_name",
-  "symbol_declaration", "$@2", "$@3", "precedence_declarator", "tag.opt",
-  "generic_symlist", "generic_symlist_item", "tag", "nterm_decls",
-  "token_decls", "token_decl.1", "token_decl", "int.opt",
-  "token_decls_for_prec", "token_decl_for_prec.1", "token_decl_for_prec",
-  "symbol_decls", "symbol_decl.1", "grammar",
-  "rules_or_grammar_declaration", "rules", "$@4", "rhses.1", "rhs",
-  "named_ref.opt", "variable", "value", "id", "id_colon", "symbol",
-  "string_as_id", "string_as_id.opt", "epilogue.opt", YY_NULLPTR
+  "\"%nondeterministic-parser\"", "\"%output\"", "\"%pure-parser\"",
+  "\"%require\"", "\"%skeleton\"", "\"%start\"", "\"%token-table\"",
+  "\"%verbose\"", "\"%yacc\"", "\"{...}\"", "\"%?{...}\"",
+  "\"[identifier]\"", "\"char\"", "\":\"", "\"epilogue\"", "\"=\"",
+  "\"identifier\"", "\"identifier:\"", "\"%%\"", "\"|\"", "\"%{...%}\"",
+  "\";\"", "\"<tag>\"", "\"<*>\"", "\"<>\"", "\"integer\"", "\"%param\"",
+  "\"%union\"", "\"%empty\"", "$accept", "input", "prologue_declarations",
+  "prologue_declaration", "$@1", "params", "grammar_declaration",
+  "code_props_type", "union_name", "symbol_declaration", "$@2", "$@3",
+  "precedence_declarator", "tag.opt", "generic_symlist",
+  "generic_symlist_item", "tag", "nterm_decls", "token_decls",
+  "token_decl.1", "token_decl", "int.opt", "token_decls_for_prec",
+  "token_decl_for_prec.1", "token_decl_for_prec", "symbol_decls",
+  "symbol_decl.1", "grammar", "rules_or_grammar_declaration", "rules",
+  "$@4", "rhses.1", "rhs", "named_ref.opt", "variable", "value", "id",
+  "id_colon", "symbol", "string_as_id", "string_as_id.opt", "epilogue.opt", YY_NULLPTR
 };
 #endif
 
@@ -531,16 +534,16 @@ static const yytype_uint16 yytoknum[] =
      275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
      285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
      295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
-     305,   306,   307,   308,   309,   310,   311,   312,   313
+     305,   306,   307,   308,   309,   310,   311,   312,   313,   314
 };
 # endif
 
-#define YYPACT_NINF -127
+#define YYPACT_NINF -130
 
 #define yypact_value_is_default(Yystate) \
-  (!!((Yystate) == (-127)))
+  (!!((Yystate) == (-130)))
 
-#define YYTABLE_NINF -121
+#define YYTABLE_NINF -122
 
 #define yytable_value_is_error(Yytable_value) \
   0
@@ -549,23 +552,23 @@ static const yytype_uint16 yytoknum[] =
      STATE-NUM.  */
 static const yytype_int16 yypact[] =
 {
-    -127,    31,   110,  -127,   -19,  -127,  -127,    30,  -127,  -127,
-    -127,  -127,  -127,  -127,   -12,  -127,   -11,    36,  -127,    -1,
-       5,  -127,    40,  -127,    41,    66,    67,  -127,  -127,  -127,
-      82,    87,    88,     3,  -127,  -127,  -127,   164,  -127,  -127,
-    -127,    48,  -127,  -127,    56,  -127,    55,  -127,    35,    35,
-    -127,  -127,  -127,     3,    46,     3,  -127,  -127,  -127,  -127,
-      61,  -127,    25,  -127,  -127,  -127,  -127,  -127,  -127,  -127,
-    -127,  -127,  -127,  -127,    52,  -127,    53,     9,  -127,  -127,
-      64,    69,  -127,    70,    21,     3,    54,     3,  -127,    57,
-    -127,   -34,    72,   -34,  -127,    57,  -127,    72,     3,     3,
-    -127,  -127,  -127,  -127,  -127,  -127,  -127,  -127,    81,  -127,
-    -127,  -127,  -127,  -127,   111,  -127,  -127,  -127,  -127,    21,
-    -127,  -127,  -127,     3,     3,  -127,  -127,  -127,   -34,   -34,
-    -127,   146,     3,  -127,   108,  -127,  -127,     3,   -34,  -127,
-    -127,  -127,    10,   174,  -127,  -127,     3,    97,   101,    99,
-     100,  -127,  -127,  -127,   117,    64,   174,  -127,  -127,  -127,
-    -127,  -127,    64,  -127,  -127
+    -130,    36,   110,  -130,   -22,  -130,  -130,     2,  -130,  -130,
+    -130,  -130,  -130,  -130,   -19,  -130,    -9,    40,  -130,   -17,
+      -2,  -130,    57,  -130,    21,    66,    77,  -130,  -130,  -130,
+      78,  -130,    87,    92,    44,  -130,  -130,  -130,   165,  -130,
+    -130,  -130,    50,  -130,  -130,    58,  -130,    29,  -130,    15,
+      15,  -130,  -130,  -130,    44,    47,    44,  -130,  -130,  -130,
+    -130,    61,  -130,    30,  -130,  -130,  -130,  -130,  -130,  -130,
+    -130,  -130,  -130,  -130,  -130,    51,  -130,    53,     8,  -130,
+    -130,    64,    67,  -130,    68,    20,    44,    56,    44,  -130,
+      69,  -130,   -37,    59,   -37,  -130,    69,  -130,    59,    44,
+      44,  -130,  -130,  -130,  -130,  -130,  -130,  -130,  -130,    79,
+    -130,  -130,  -130,  -130,  -130,   111,  -130,  -130,  -130,  -130,
+      20,  -130,  -130,  -130,    44,    44,  -130,  -130,  -130,   -37,
+     -37,  -130,   147,    44,  -130,   108,  -130,  -130,    44,   -37,
+    -130,  -130,  -130,   -21,   175,  -130,  -130,    44,    97,   101,
+      99,   100,  -130,  -130,  -130,   117,    64,   175,  -130,  -130,
+    -130,  -130,  -130,    64,  -130,  -130
 };
 
   /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
@@ -573,43 +576,43 @@ static const yytype_int16 yypact[] =
      means the default is an error.  */
 static const yytype_uint8 yydefact[] =
 {
-       3,     0,     0,     1,     0,    47,    45,     0,    40,    41,
-      51,    52,    53,    54,     0,    36,     0,     9,    11,     0,
-       0,     7,     0,    15,     0,     0,     0,    37,    19,    20,
-       0,     0,     0,     0,    26,    27,    28,     0,     6,    30,
-      22,    42,     4,     5,     0,    33,     0,    29,     0,     0,
-     117,   113,   112,     0,    49,    80,   115,    83,   116,    38,
-       0,   107,   108,    10,    12,    13,    14,    16,    17,    18,
-      21,    24,    25,    34,     0,   114,     0,     0,    85,    87,
-     105,     0,    43,     0,     0,     0,    50,    73,    76,    71,
-      79,     0,    48,    65,    68,    71,    46,    64,    81,     0,
-      84,    39,   110,   111,   109,     8,    89,    88,     0,    86,
-       2,   106,    90,    32,    23,    44,    61,    62,    63,    35,
-      57,    60,    59,    74,     0,    77,    72,    78,    66,     0,
-      69,   118,    82,   121,     0,    31,    58,    75,    67,   119,
-      70,    95,    91,    92,    95,    94,     0,     0,     0,     0,
-       0,    98,    56,    99,     0,   105,    93,   100,   101,   102,
-     103,   104,   105,    96,    97
+       3,     0,     0,     1,     0,    48,    46,     0,    41,    42,
+      52,    53,    54,    55,     0,    37,     0,     9,    11,     0,
+       0,     7,     0,    15,     0,     0,     0,    38,    19,    20,
+       0,    24,     0,     0,     0,    27,    28,    29,     0,     6,
+      31,    22,    43,     4,     5,     0,    34,     0,    30,     0,
+       0,   118,   114,   113,     0,    50,    81,   116,    84,   117,
+      39,     0,   108,   109,    10,    12,    13,    14,    16,    17,
+      18,    21,    25,    26,    35,     0,   115,     0,     0,    86,
+      88,   106,     0,    44,     0,     0,     0,    51,    74,    77,
+      72,    80,     0,    49,    66,    69,    72,    47,    65,    82,
+       0,    85,    40,   111,   112,   110,     8,    90,    89,     0,
+      87,     2,   107,    91,    33,    23,    45,    62,    63,    64,
+      36,    58,    61,    60,    75,     0,    78,    73,    79,    67,
+       0,    70,   119,    83,   122,     0,    32,    59,    76,    68,
+     120,    71,    96,    92,    93,    96,    95,     0,     0,     0,
+       0,     0,    99,    57,   100,     0,   106,    94,   101,   102,
+     103,   104,   105,   106,    97,    98
 };
 
   /* YYPGOTO[NTERM-NUM].  */
 static const yytype_int16 yypgoto[] =
 {
-    -127,  -127,  -127,  -127,  -127,  -127,   155,  -127,  -127,  -127,
-    -127,  -127,  -127,  -127,  -127,    43,  -127,  -127,   114,   -61,
-     -91,    83,  -127,   -62,   -82,  -127,   -46,  -127,   102,  -127,
-    -127,  -127,    15,  -126,  -127,  -127,   -45,  -127,   -33,   -35,
-    -127,  -127
+    -130,  -130,  -130,  -130,  -130,  -130,   156,  -130,  -130,  -130,
+    -130,  -130,  -130,  -130,  -130,    43,  -130,  -130,   114,   -66,
+     -35,    83,  -130,   -84,   -53,  -130,   -47,  -130,    82,  -130,
+    -130,  -130,    35,  -129,  -130,  -130,   -46,  -130,   -34,   -36,
+    -130,  -130
 };
 
   /* YYDEFGOTO[NTERM-NUM].  */
 static const yytype_int16 yydefgoto[] =
 {
-      -1,     1,     2,    42,    81,   114,    76,    44,    83,    45,
-      49,    48,    46,   154,   119,   120,   121,    96,    92,    93,
-      94,   127,    86,    87,    88,    54,    55,    77,    78,    79,
-     134,   142,   143,   112,    62,   105,    56,    80,    57,    58,
-     140,   110
+      -1,     1,     2,    43,    82,   115,    77,    45,    84,    46,
+      50,    49,    47,   155,   120,   121,   122,    97,    93,    94,
+      95,   128,    87,    88,    89,    55,    56,    78,    79,    80,
+     135,   143,   144,   113,    63,   106,    57,    81,    58,    59,
+     141,   111
 };
 
   /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
@@ -617,99 +620,99 @@ static const yytype_int16 yydefgoto[] =
      number is the opposite.  If YYTABLE_NINF, syntax error.  */
 static const yytype_int16 yytable[] =
 {
-      73,    89,   130,    95,    95,   125,    50,    98,    51,  -120,
-      74,    90,    52,     5,     6,     7,     8,     9,    10,    11,
-      12,    13,   100,   123,    50,    14,    15,    59,   102,   163,
-     128,     3,    47,    50,    60,    61,   164,   130,    27,    63,
-      89,   125,    89,    66,    33,    51,    95,   130,    95,    52,
-      90,   122,    90,   132,    64,   125,    75,   108,    50,   144,
-      65,   145,   137,    51,   103,   100,    41,    52,   138,    68,
-      69,   104,    51,   116,   117,   118,    52,    51,    89,    89,
-      67,    52,    53,    95,    95,    70,   122,    91,    90,    90,
-      71,    72,    89,    95,    82,    84,   139,    51,    99,   100,
-     101,    52,    90,   106,   107,   111,   124,    85,   113,   115,
-     155,     4,   126,   157,     5,     6,     7,     8,     9,    10,
-      11,    12,    13,   155,   129,   133,    14,    15,    16,    17,
+      74,    90,   124,    96,    96,    51,    52,    99,  -121,    75,
+      53,    91,     5,     6,     7,     8,     9,    10,    11,    12,
+      13,    60,   101,    51,    14,    15,   129,   164,    61,   145,
+      48,   146,    51,   103,   165,   126,     3,    27,    62,    65,
+      90,   138,    90,    64,    34,    52,    96,    51,    96,    53,
+      91,   123,    91,   133,    66,    54,    76,   109,    52,   131,
+      67,    68,    53,    52,   139,   101,    42,    53,    92,    69,
+     104,   126,    52,   117,   118,   119,    53,   105,    90,    90,
+      70,    71,    86,    96,    96,   126,   123,    52,    91,    91,
+      72,    53,    90,    96,   131,    73,   140,    83,    85,   101,
+     100,   102,    91,   107,   131,   108,   112,   114,   116,   125,
+     156,     4,   130,   158,     5,     6,     7,     8,     9,    10,
+      11,    12,    13,   156,   134,   127,    14,    15,    16,    17,
       18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
-      28,    29,    30,    31,    32,    33,    34,    35,    36,    50,
-     135,   141,   158,   159,   160,   161,   162,    43,    37,   156,
-      38,    39,   136,    97,     0,    74,    40,    41,     5,     6,
-       7,     8,     9,    10,    11,    12,    13,    50,   131,   109,
-      14,    15,     0,     0,     0,     0,     0,   146,   147,   148,
-       0,     0,     0,    27,     0,   149,   150,     0,     0,    33,
-       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
-       0,    75,     0,   -55,   151,     0,    51,     0,     0,     0,
-      52,    41,     0,     0,     0,     0,   152,     0,     0,     0,
-       0,     0,   153
+      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
+      51,   136,   142,   159,   160,   161,   162,   163,    44,    38,
+     110,    39,    40,   137,    98,     0,    75,    41,    42,     5,
+       6,     7,     8,     9,    10,    11,    12,    13,    51,   132,
+     157,    14,    15,     0,     0,     0,     0,     0,   147,   148,
+     149,     0,     0,     0,    27,     0,   150,   151,     0,     0,
+       0,    34,     0,     0,     0,     0,     0,     0,     0,     0,
+       0,     0,     0,    76,     0,   -56,   152,     0,    52,     0,
+       0,     0,    53,    42,     0,     0,     0,     0,   153,     0,
+       0,     0,     0,     0,   154
 };
 
 static const yytype_int16 yycheck[] =
 {
-      33,    46,    93,    48,    49,    87,     3,    53,    42,     0,
-       1,    46,    46,     4,     5,     6,     7,     8,     9,    10,
-      11,    12,    55,    85,     3,    16,    17,    39,     3,   155,
-      91,     0,    51,     3,    46,    46,   162,   128,    29,     3,
-      85,   123,    87,     3,    35,    42,    91,   138,    93,    46,
-      85,    84,    87,    99,    55,   137,    47,    48,     3,    49,
-      55,    51,   124,    42,    39,    98,    57,    46,   129,     3,
-       3,    46,    42,    52,    53,    54,    46,    42,   123,   124,
-      39,    46,    52,   128,   129,     3,   119,    52,   123,   124,
-       3,     3,   137,   138,    46,    39,   131,    42,    52,   132,
-      39,    46,   137,    51,    51,    41,    52,    52,    39,    39,
-     143,     1,    55,   146,     4,     5,     6,     7,     8,     9,
-      10,    11,    12,   156,    52,    44,    16,    17,    18,    19,
+      34,    47,    86,    49,    50,     3,    43,    54,     0,     1,
+      47,    47,     4,     5,     6,     7,     8,     9,    10,    11,
+      12,    40,    56,     3,    16,    17,    92,   156,    47,    50,
+      52,    52,     3,     3,   163,    88,     0,    29,    47,    56,
+      86,   125,    88,     3,    36,    43,    92,     3,    94,    47,
+      86,    85,    88,   100,    56,    53,    48,    49,    43,    94,
+       3,    40,    47,    43,   130,    99,    58,    47,    53,     3,
+      40,   124,    43,    53,    54,    55,    47,    47,   124,   125,
+       3,     3,    53,   129,   130,   138,   120,    43,   124,   125,
+       3,    47,   138,   139,   129,     3,   132,    47,    40,   133,
+      53,    40,   138,    52,   139,    52,    42,    40,    40,    53,
+     144,     1,    53,   147,     4,     5,     6,     7,     8,     9,
+      10,    11,    12,   157,    45,    56,    16,    17,    18,    19,
       20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
-      30,    31,    32,    33,    34,    35,    36,    37,    38,     3,
-      39,    43,    55,    52,    55,    55,    39,     2,    48,   144,
-      50,    51,   119,    49,    -1,     1,    56,    57,     4,     5,
-       6,     7,     8,     9,    10,    11,    12,     3,    95,    77,
-      16,    17,    -1,    -1,    -1,    -1,    -1,    13,    14,    15,
-      -1,    -1,    -1,    29,    -1,    21,    22,    -1,    -1,    35,
-      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
-      -1,    47,    -1,    39,    40,    -1,    42,    -1,    -1,    -1,
-      46,    57,    -1,    -1,    -1,    -1,    52,    -1,    -1,    -1,
-      -1,    -1,    58
+      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
+       3,    40,    44,    56,    53,    56,    56,    40,     2,    49,
+      78,    51,    52,   120,    50,    -1,     1,    57,    58,     4,
+       5,     6,     7,     8,     9,    10,    11,    12,     3,    96,
+     145,    16,    17,    -1,    -1,    -1,    -1,    -1,    13,    14,
+      15,    -1,    -1,    -1,    29,    -1,    21,    22,    -1,    -1,
+      -1,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
+      -1,    -1,    -1,    48,    -1,    40,    41,    -1,    43,    -1,
+      -1,    -1,    47,    58,    -1,    -1,    -1,    -1,    53,    -1,
+      -1,    -1,    -1,    -1,    59
 };
 
   /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
      symbol of state STATE-NUM.  */
 static const yytype_uint8 yystos[] =
 {
-       0,    60,    61,     0,     1,     4,     5,     6,     7,     8,
+       0,    61,    62,     0,     1,     4,     5,     6,     7,     8,
        9,    10,    11,    12,    16,    17,    18,    19,    20,    21,
       22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
-      32,    33,    34,    35,    36,    37,    38,    48,    50,    51,
-      56,    57,    62,    65,    66,    68,    71,    51,    70,    69,
-       3,    42,    46,    52,    84,    85,    95,    97,    98,    39,
-      46,    46,    93,     3,    55,    55,     3,    39,     3,     3,
-       3,     3,     3,    97,     1,    47,    65,    86,    87,    88,
-      96,    63,    46,    67,    39,    52,    81,    82,    83,    95,
-      98,    52,    77,    78,    79,    95,    76,    77,    85,    52,
-      97,    39,     3,    39,    46,    94,    51,    51,    48,    87,
-     100,    41,    92,    39,    64,    39,    52,    53,    54,    73,
-      74,    75,    97,    82,    52,    83,    55,    80,    78,    52,
-      79,    80,    85,    44,    89,    39,    74,    82,    78,    98,
-      99,    43,    90,    91,    49,    51,    13,    14,    15,    21,
-      22,    40,    52,    58,    72,    97,    91,    97,    55,    52,
-      55,    55,    39,    92,    92
+      32,    33,    34,    35,    36,    37,    38,    39,    49,    51,
+      52,    57,    58,    63,    66,    67,    69,    72,    52,    71,
+      70,     3,    43,    47,    53,    85,    86,    96,    98,    99,
+      40,    47,    47,    94,     3,    56,    56,     3,    40,     3,
+       3,     3,     3,     3,    98,     1,    48,    66,    87,    88,
+      89,    97,    64,    47,    68,    40,    53,    82,    83,    84,
+      96,    99,    53,    78,    79,    80,    96,    77,    78,    86,
+      53,    98,    40,     3,    40,    47,    95,    52,    52,    49,
+      88,   101,    42,    93,    40,    65,    40,    53,    54,    55,
+      74,    75,    76,    98,    83,    53,    84,    56,    81,    79,
+      53,    80,    81,    86,    45,    90,    40,    75,    83,    79,
+      99,   100,    44,    91,    92,    50,    52,    13,    14,    15,
+      21,    22,    41,    53,    59,    73,    98,    92,    98,    56,
+      53,    56,    56,    40,    93,    93
 };
 
   /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
 static const yytype_uint8 yyr1[] =
 {
-       0,    59,    60,    61,    61,    62,    62,    62,    62,    62,
-      62,    62,    62,    62,    62,    62,    62,    62,    62,    62,
-      62,    62,    63,    62,    62,    62,    62,    62,    62,    62,
-      62,    64,    64,    65,    65,    65,    65,    65,    65,    65,
-      66,    66,    67,    67,    65,    69,    68,    70,    68,    68,
-      68,    71,    71,    71,    71,    72,    72,    73,    73,    74,
-      74,    75,    75,    75,    76,    77,    77,    77,    78,    78,
-      79,    80,    80,    81,    81,    81,    82,    82,    83,    83,
-      84,    84,    84,    85,    85,    86,    86,    87,    87,    87,
-      89,    88,    90,    90,    90,    91,    91,    91,    91,    91,
-      91,    91,    91,    91,    91,    92,    92,    93,    94,    94,
-      94,    94,    95,    95,    96,    97,    97,    98,    99,    99,
-     100,   100
+       0,    60,    61,    62,    62,    63,    63,    63,    63,    63,
+      63,    63,    63,    63,    63,    63,    63,    63,    63,    63,
+      63,    63,    64,    63,    63,    63,    63,    63,    63,    63,
+      63,    63,    65,    65,    66,    66,    66,    66,    66,    66,
+      66,    67,    67,    68,    68,    66,    70,    69,    71,    69,
+      69,    69,    72,    72,    72,    72,    73,    73,    74,    74,
+      75,    75,    76,    76,    76,    77,    78,    78,    78,    79,
+      79,    80,    81,    81,    82,    82,    82,    83,    83,    84,
+      84,    85,    85,    85,    86,    86,    87,    87,    88,    88,
+      88,    90,    89,    91,    91,    91,    92,    92,    92,    92,
+      92,    92,    92,    92,    92,    92,    93,    93,    94,    95,
+      95,    95,    95,    96,    96,    97,    98,    98,    99,   100,
+     100,   101,   101
 };
 
   /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
@@ -717,17 +720,17 @@ static const yytype_uint8 yyr2[] =
 {
        0,     2,     4,     0,     2,     1,     1,     1,     3,     1,
        2,     1,     2,     2,     2,     1,     2,     2,     2,     1,
-       1,     2,     0,     3,     2,     2,     1,     1,     1,     2,
-       1,     2,     1,     1,     2,     3,     1,     1,     2,     3,
-       1,     1,     0,     1,     3,     0,     3,     0,     3,     2,
-       2,     1,     1,     1,     1,     0,     1,     1,     2,     1,
-       1,     1,     1,     1,     1,     1,     2,     3,     1,     2,
-       3,     0,     1,     1,     2,     3,     1,     2,     2,     1,
-       1,     2,     3,     1,     2,     1,     2,     1,     2,     2,
-       0,     5,     1,     3,     2,     0,     3,     4,     2,     2,
-       3,     3,     3,     3,     3,     0,     1,     1,     0,     1,
-       1,     1,     1,     1,     1,     1,     1,     1,     0,     1,
-       0,     2
+       1,     2,     0,     3,     1,     2,     2,     1,     1,     1,
+       2,     1,     2,     1,     1,     2,     3,     1,     1,     2,
+       3,     1,     1,     0,     1,     3,     0,     3,     0,     3,
+       2,     2,     1,     1,     1,     1,     0,     1,     1,     2,
+       1,     1,     1,     1,     1,     1,     1,     2,     3,     1,
+       2,     3,     0,     1,     1,     2,     3,     1,     2,     2,
+       1,     1,     2,     3,     1,     2,     1,     2,     1,     2,
+       2,     0,     5,     1,     3,     2,     0,     3,     4,     2,
+       2,     3,     3,     3,     3,     3,     0,     1,     1,     0,
+       1,     1,     1,     1,     1,     1,     1,     1,     1,     0,
+       1,     0,     2
 };
 
 
@@ -905,51 +908,55 @@ tron (yyo);
       { fputs (((*yyvaluep).PERCENT_NAME_PREFIX), yyo); }
         break;
 
-    case 38: /* "%yacc"  */
+    case 33: /* "%pure-parser"  */
+      { fputs (((*yyvaluep).PERCENT_PURE_PARSER), yyo); }
+        break;
+
+    case 39: /* "%yacc"  */
       { fputs (((*yyvaluep).PERCENT_YACC), yyo); }
         break;
 
-    case 39: /* "{...}"  */
+    case 40: /* "{...}"  */
       { fputs (((*yyvaluep).BRACED_CODE), yyo); }
         break;
 
-    case 40: /* "%?{...}"  */
+    case 41: /* "%?{...}"  */
       { fputs (((*yyvaluep).BRACED_PREDICATE), yyo); }
         break;
 
-    case 41: /* "[identifier]"  */
+    case 42: /* "[identifier]"  */
       { fprintf (yyo, "[%s]", ((*yyvaluep).BRACKETED_ID)); }
         break;
 
-    case 42: /* "char"  */
+    case 43: /* "char"  */
       { fputs (char_name (((*yyvaluep).CHAR)), yyo); }
         break;
 
-    case 44: /* "epilogue"  */
+    case 45: /* "epilogue"  */
       { fputs (((*yyvaluep).EPILOGUE), yyo); }
         break;
 
-    case 46: /* "identifier"  */
+    case 47: /* "identifier"  */
       { fputs (((*yyvaluep).ID), yyo); }
         break;
 
-    case 47: /* "identifier:"  */
+    case 48: /* "identifier:"  */
       { fprintf (yyo, "%s:", ((*yyvaluep).ID_COLON)); }
         break;
 
-    case 50: /* "%{...%}"  */
+    case 51: /* "%{...%}"  */
       { fputs (((*yyvaluep).PROLOGUE), yyo); }
         break;
 
-    case 52: /* "<tag>"  */
+    case 53: /* "<tag>"  */
       { fprintf (yyo, "<%s>", ((*yyvaluep).TAG)); }
         break;
 
-    case 55: /* "integer"  */
+    case 56: /* "integer"  */
       { fprintf (yyo, "%d", ((*yyvaluep).INT)); }
         break;
 
-    case 56: /* "%param"  */
+    case 57: /* "%param"  */
       {
   switch (((*yyvaluep).PERCENT_PARAM))
     {
@@ -964,71 +971,71 @@ tron (yyo);
 }
         break;
 
-    case 66: /* code_props_type  */
+    case 67: /* code_props_type  */
       { fprintf (yyo, "%s", code_props_type_string (((*yyvaluep).code_props_type))); }
         break;
 
-    case 72: /* tag.opt  */
-      { fputs (((*yyvaluep).yytype_72), yyo); }
+    case 73: /* tag.opt  */
+      { fputs (((*yyvaluep).yytype_73), yyo); }
         break;
 
-    case 73: /* generic_symlist  */
+    case 74: /* generic_symlist  */
       { symbol_list_syms_print (((*yyvaluep).generic_symlist), yyo); }
         break;
 
-    case 74: /* generic_symlist_item  */
+    case 75: /* generic_symlist_item  */
       { symbol_list_syms_print (((*yyvaluep).generic_symlist_item), yyo); }
         break;
 
-    case 75: /* tag  */
+    case 76: /* tag  */
       { fprintf (yyo, "<%s>", ((*yyvaluep).tag)); }
         break;
 
-    case 76: /* nterm_decls  */
+    case 77: /* nterm_decls  */
       { symbol_list_syms_print (((*yyvaluep).nterm_decls), yyo); }
         break;
 
-    case 77: /* token_decls  */
+    case 78: /* token_decls  */
       { symbol_list_syms_print (((*yyvaluep).token_decls), yyo); }
         break;
 
-    case 78: /* token_decl.1  */
-      { symbol_list_syms_print (((*yyvaluep).yytype_78), yyo); }
+    case 79: /* token_decl.1  */
+      { symbol_list_syms_print (((*yyvaluep).yytype_79), yyo); }
         break;
 
-    case 79: /* token_decl  */
+    case 80: /* token_decl  */
       { fprintf (yyo, "%s", ((*yyvaluep).token_decl) ? ((*yyvaluep).token_decl)->tag : "<NULL>"); }
         break;
 
-    case 80: /* int.opt  */
-      { fprintf (yyo, "%d", ((*yyvaluep).yytype_80)); }
+    case 81: /* int.opt  */
+      { fprintf (yyo, "%d", ((*yyvaluep).yytype_81)); }
         break;
 
-    case 81: /* token_decls_for_prec  */
+    case 82: /* token_decls_for_prec  */
       { symbol_list_syms_print (((*yyvaluep).token_decls_for_prec), yyo); }
         break;
 
-    case 82: /* token_decl_for_prec.1  */
-      { symbol_list_syms_print (((*yyvaluep).yytype_82), yyo); }
+    case 83: /* token_decl_for_prec.1  */
+      { symbol_list_syms_print (((*yyvaluep).yytype_83), yyo); }
         break;
 
-    case 83: /* token_decl_for_prec  */
+    case 84: /* token_decl_for_prec  */
       { fprintf (yyo, "%s", ((*yyvaluep).token_decl_for_prec) ? ((*yyvaluep).token_decl_for_prec)->tag : "<NULL>"); }
         break;
 
-    case 84: /* symbol_decls  */
+    case 85: /* symbol_decls  */
       { symbol_list_syms_print (((*yyvaluep).symbol_decls), yyo); }
         break;
 
-    case 85: /* symbol_decl.1  */
-      { symbol_list_syms_print (((*yyvaluep).yytype_85), yyo); }
+    case 86: /* symbol_decl.1  */
+      { symbol_list_syms_print (((*yyvaluep).yytype_86), yyo); }
         break;
 
-    case 93: /* variable  */
+    case 94: /* variable  */
       { fputs (((*yyvaluep).variable), yyo); }
         break;
 
-    case 94: /* value  */
+    case 95: /* value  */
       {
   switch (((*yyvaluep).value).kind)
     {
@@ -1039,24 +1046,24 @@ tron (yyo);
 }
         break;
 
-    case 95: /* id  */
+    case 96: /* id  */
       { fprintf (yyo, "%s", ((*yyvaluep).id) ? ((*yyvaluep).id)->tag : "<NULL>"); }
         break;
 
-    case 96: /* id_colon  */
+    case 97: /* id_colon  */
       { fprintf (yyo, "%s:", ((*yyvaluep).id_colon)->tag); }
         break;
 
-    case 97: /* symbol  */
+    case 98: /* symbol  */
       { fprintf (yyo, "%s", ((*yyvaluep).symbol) ? ((*yyvaluep).symbol)->tag : "<NULL>"); }
         break;
 
-    case 98: /* string_as_id  */
+    case 99: /* string_as_id  */
       { fprintf (yyo, "%s", ((*yyvaluep).string_as_id) ? ((*yyvaluep).string_as_id)->tag : "<NULL>"); }
         break;
 
-    case 99: /* string_as_id.opt  */
-      { fprintf (yyo, "%s", ((*yyvaluep).yytype_99) ? ((*yyvaluep).yytype_99)->tag : "<NULL>"); }
+    case 100: /* string_as_id.opt  */
+      { fprintf (yyo, "%s", ((*yyvaluep).yytype_100) ? ((*yyvaluep).yytype_100)->tag : "<NULL>"); }
         break;
 
       default:
@@ -1646,40 +1653,40 @@ yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocatio
   YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
   switch (yytype)
     {
-    case 73: /* generic_symlist  */
+    case 74: /* generic_symlist  */
       { symbol_list_free (((*yyvaluep).generic_symlist)); }
         break;
 
-    case 74: /* generic_symlist_item  */
+    case 75: /* generic_symlist_item  */
       { symbol_list_free (((*yyvaluep).generic_symlist_item)); }
         break;
 
-    case 76: /* nterm_decls  */
+    case 77: /* nterm_decls  */
       { symbol_list_free (((*yyvaluep).nterm_decls)); }
         break;
 
-    case 77: /* token_decls  */
+    case 78: /* token_decls  */
       { symbol_list_free (((*yyvaluep).token_decls)); }
         break;
 
-    case 78: /* token_decl.1  */
-      { symbol_list_free (((*yyvaluep).yytype_78)); }
+    case 79: /* token_decl.1  */
+      { symbol_list_free (((*yyvaluep).yytype_79)); }
         break;
 
-    case 81: /* token_decls_for_prec  */
+    case 82: /* token_decls_for_prec  */
       { symbol_list_free (((*yyvaluep).token_decls_for_prec)); }
         break;
 
-    case 82: /* token_decl_for_prec.1  */
-      { symbol_list_free (((*yyvaluep).yytype_82)); }
+    case 83: /* token_decl_for_prec.1  */
+      { symbol_list_free (((*yyvaluep).yytype_83)); }
         break;
 
-    case 84: /* symbol_decls  */
+    case 85: /* symbol_decls  */
       { symbol_list_free (((*yyvaluep).symbol_decls)); }
         break;
 
-    case 85: /* symbol_decl.1  */
-      { symbol_list_free (((*yyvaluep).yytype_85)); }
+    case 86: /* symbol_decl.1  */
+      { symbol_list_free (((*yyvaluep).yytype_86)); }
         break;
 
       default:
@@ -2092,44 +2099,48 @@ yyreduce:
     break;
 
   case 24:
-    { handle_require (&(yylsp[0]), (yyvsp[0].STRING)); }
+    { handle_pure_parser (&(yyloc), (yyvsp[0].PERCENT_PURE_PARSER)); }
     break;
 
   case 25:
-    { handle_skeleton (&(yylsp[0]), (yyvsp[0].STRING)); }
+    { handle_require (&(yylsp[0]), (yyvsp[0].STRING)); }
     break;
 
   case 26:
-    { token_table_flag = true; }
+    { handle_skeleton (&(yylsp[0]), (yyvsp[0].STRING)); }
     break;
 
   case 27:
-    { report_flag |= report_states; }
+    { token_table_flag = true; }
     break;
 
   case 28:
-    { handle_yacc (&(yyloc), (yyvsp[0].PERCENT_YACC)); }
+    { report_flag |= report_states; }
     break;
 
   case 29:
+    { handle_yacc (&(yyloc), (yyvsp[0].PERCENT_YACC)); }
+    break;
+
+  case 30:
     { current_class = unknown_sym; yyerrok; }
     break;
 
-  case 31:
+  case 32:
     { add_param (current_param, (yyvsp[0].BRACED_CODE), (yylsp[0])); }
     break;
 
-  case 32:
+  case 33:
     { add_param (current_param, (yyvsp[0].BRACED_CODE), (yylsp[0])); }
     break;
 
-  case 34:
+  case 35:
     {
       grammar_start_symbol_set ((yyvsp[0].symbol), (yylsp[0]));
     }
     break;
 
-  case 35:
+  case 36:
     {
       code_props code;
       code_props_symbol_action_init (&code, (yyvsp[-1].BRACED_CODE), (yylsp[-1]));
@@ -2142,19 +2153,19 @@ yyreduce:
     }
     break;
 
-  case 36:
+  case 37:
     {
       default_prec = true;
     }
     break;
 
-  case 37:
+  case 38:
     {
       default_prec = false;
     }
     break;
 
-  case 38:
+  case 39:
     {
       /* Do not invoke muscle_percent_code_grow here since it invokes
          muscle_user_name_list_grow.  */
@@ -2164,32 +2175,32 @@ yyreduce:
     }
     break;
 
-  case 39:
+  case 40:
     {
       muscle_percent_code_grow ((yyvsp[-1].ID), (yylsp[-1]), translate_code_braceless ((yyvsp[0].BRACED_CODE), (yylsp[0])), (yylsp[0]));
       code_scanner_last_string_free ();
     }
     break;
 
-  case 40:
+  case 41:
     { (yyval.code_props_type) = destructor; }
     break;
 
-  case 41:
+  case 42:
     { (yyval.code_props_type) = printer; }
     break;
 
-  case 42:
+  case 43:
     {}
     break;
 
-  case 43:
+  case 44:
     { muscle_percent_define_insert ("api.value.union.name",
                                          (yylsp[0]), muscle_keyword, (yyvsp[0].ID),
                                          MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE); }
     break;
 
-  case 44:
+  case 45:
     {
       union_seen = true;
       muscle_code_grow ("union_members", translate_code_braceless ((yyvsp[0].BRACED_CODE), (yylsp[0])), (yylsp[0]));
@@ -2197,35 +2208,35 @@ yyreduce:
     }
     break;
 
-  case 45:
+  case 46:
     { current_class = nterm_sym; }
     break;
 
-  case 46:
+  case 47:
     {
       current_class = unknown_sym;
       symbol_list_free ((yyvsp[0].nterm_decls));
     }
     break;
 
-  case 47:
+  case 48:
     { current_class = token_sym; }
     break;
 
-  case 48:
+  case 49:
     {
       current_class = unknown_sym;
       symbol_list_free ((yyvsp[0].token_decls));
     }
     break;
 
-  case 49:
+  case 50:
     {
       symbol_list_free ((yyvsp[0].symbol_decls));
     }
     break;
 
-  case 50:
+  case 51:
     {
       ++current_prec;
       for (symbol_list *list = (yyvsp[0].token_decls_for_prec); list; list = list->next)
@@ -2234,247 +2245,247 @@ yyreduce:
     }
     break;
 
-  case 51:
+  case 52:
     { (yyval.precedence_declarator) = left_assoc; }
     break;
 
-  case 52:
+  case 53:
     { (yyval.precedence_declarator) = right_assoc; }
     break;
 
-  case 53:
+  case 54:
     { (yyval.precedence_declarator) = non_assoc; }
     break;
 
-  case 54:
+  case 55:
     { (yyval.precedence_declarator) = precedence_assoc; }
     break;
 
-  case 55:
-    { (yyval.yytype_72) = NULL; }
+  case 56:
+    { (yyval.yytype_73) = NULL; }
     break;
 
-  case 56:
-    { (yyval.yytype_72) = (yyvsp[0].TAG); }
+  case 57:
+    { (yyval.yytype_73) = (yyvsp[0].TAG); }
     break;
 
-  case 58:
+  case 59:
     { (yyval.generic_symlist) = symbol_list_append ((yyvsp[-1].generic_symlist), (yyvsp[0].generic_symlist_item)); }
     break;
 
-  case 59:
+  case 60:
     { (yyval.generic_symlist_item) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
     break;
 
-  case 60:
+  case 61:
     { (yyval.generic_symlist_item) = symbol_list_type_new ((yyvsp[0].tag), (yylsp[0])); }
     break;
 
-  case 62:
+  case 63:
     { (yyval.tag) = uniqstr_new ("*"); }
     break;
 
-  case 63:
+  case 64:
     { (yyval.tag) = uniqstr_new (""); }
     break;
 
-  case 65:
-    {
-      (yyval.token_decls) = (yyvsp[0].yytype_78);
-    }
-    break;
-
   case 66:
     {
-      (yyval.token_decls) = symbol_list_type_set ((yyvsp[0].yytype_78), (yyvsp[-1].TAG), (yylsp[-1]));
+      (yyval.token_decls) = (yyvsp[0].yytype_79);
     }
     break;
 
   case 67:
     {
-      (yyval.token_decls) = symbol_list_append ((yyvsp[-2].token_decls), symbol_list_type_set ((yyvsp[0].yytype_78), (yyvsp[-1].TAG), (yylsp[-1])));
+      (yyval.token_decls) = symbol_list_type_set ((yyvsp[0].yytype_79), (yyvsp[-1].TAG), (yylsp[-1]));
     }
     break;
 
   case 68:
-    { (yyval.yytype_78) = symbol_list_sym_new ((yyvsp[0].token_decl), (yylsp[0])); }
+    {
+      (yyval.token_decls) = symbol_list_append ((yyvsp[-2].token_decls), symbol_list_type_set ((yyvsp[0].yytype_79), (yyvsp[-1].TAG), (yylsp[-1])));
+    }
     break;
 
   case 69:
-    { (yyval.yytype_78) = symbol_list_append ((yyvsp[-1].yytype_78), symbol_list_sym_new ((yyvsp[0].token_decl), (yylsp[0]))); }
+    { (yyval.yytype_79) = symbol_list_sym_new ((yyvsp[0].token_decl), (yylsp[0])); }
     break;
 
   case 70:
+    { (yyval.yytype_79) = symbol_list_append ((yyvsp[-1].yytype_79), symbol_list_sym_new ((yyvsp[0].token_decl), (yylsp[0]))); }
+    break;
+
+  case 71:
     {
       (yyval.token_decl) = (yyvsp[-2].id);
       symbol_class_set ((yyvsp[-2].id), current_class, (yylsp[-2]), true);
-      if (0 <= (yyvsp[-1].yytype_80))
-        symbol_user_token_number_set ((yyvsp[-2].id), (yyvsp[-1].yytype_80), (yylsp[-1]));
-      if ((yyvsp[0].yytype_99))
-        symbol_make_alias ((yyvsp[-2].id), (yyvsp[0].yytype_99), (yylsp[0]));
+      if (0 <= (yyvsp[-1].yytype_81))
+        symbol_user_token_number_set ((yyvsp[-2].id), (yyvsp[-1].yytype_81), (yylsp[-1]));
+      if ((yyvsp[0].yytype_100))
+        symbol_make_alias ((yyvsp[-2].id), (yyvsp[0].yytype_100), (yylsp[0]));
     }
     break;
 
-  case 71:
-    { (yyval.yytype_80) = -1; }
-    break;
-
-  case 73:
-    {
-      (yyval.token_decls_for_prec) = (yyvsp[0].yytype_82);
-    }
+  case 72:
+    { (yyval.yytype_81) = -1; }
     break;
 
   case 74:
     {
-      (yyval.token_decls_for_prec) = symbol_list_type_set ((yyvsp[0].yytype_82), (yyvsp[-1].TAG), (yylsp[-1]));
+      (yyval.token_decls_for_prec) = (yyvsp[0].yytype_83);
     }
     break;
 
   case 75:
     {
-      (yyval.token_decls_for_prec) = symbol_list_append ((yyvsp[-2].token_decls_for_prec), symbol_list_type_set ((yyvsp[0].yytype_82), (yyvsp[-1].TAG), (yylsp[-1])));
+      (yyval.token_decls_for_prec) = symbol_list_type_set ((yyvsp[0].yytype_83), (yyvsp[-1].TAG), (yylsp[-1]));
     }
     break;
 
   case 76:
-    { (yyval.yytype_82) = symbol_list_sym_new ((yyvsp[0].token_decl_for_prec), (yylsp[0])); }
+    {
+      (yyval.token_decls_for_prec) = symbol_list_append ((yyvsp[-2].token_decls_for_prec), symbol_list_type_set ((yyvsp[0].yytype_83), (yyvsp[-1].TAG), (yylsp[-1])));
+    }
     break;
 
   case 77:
-    { (yyval.yytype_82) = symbol_list_append ((yyvsp[-1].yytype_82), symbol_list_sym_new ((yyvsp[0].token_decl_for_prec), (yylsp[0]))); }
+    { (yyval.yytype_83) = symbol_list_sym_new ((yyvsp[0].token_decl_for_prec), (yylsp[0])); }
     break;
 
   case 78:
-    {
-      (yyval.token_decl_for_prec) = (yyvsp[-1].id);
-      symbol_class_set ((yyvsp[-1].id), token_sym, (yylsp[-1]), false);
-      if (0 <= (yyvsp[0].yytype_80))
-        symbol_user_token_number_set ((yyvsp[-1].id), (yyvsp[0].yytype_80), (yylsp[0]));
-    }
+    { (yyval.yytype_83) = symbol_list_append ((yyvsp[-1].yytype_83), symbol_list_sym_new ((yyvsp[0].token_decl_for_prec), (yylsp[0]))); }
     break;
 
-  case 80:
+  case 79:
     {
-      (yyval.symbol_decls) = (yyvsp[0].yytype_85);
+      (yyval.token_decl_for_prec) = (yyvsp[-1].id);
+      symbol_class_set ((yyvsp[-1].id), token_sym, (yylsp[-1]), false);
+      if (0 <= (yyvsp[0].yytype_81))
+        symbol_user_token_number_set ((yyvsp[-1].id), (yyvsp[0].yytype_81), (yylsp[0]));
     }
     break;
 
   case 81:
     {
-      (yyval.symbol_decls) = symbol_list_type_set ((yyvsp[0].yytype_85), (yyvsp[-1].TAG), (yylsp[-1]));
+      (yyval.symbol_decls) = (yyvsp[0].yytype_86);
     }
     break;
 
   case 82:
     {
-      (yyval.symbol_decls) = symbol_list_append ((yyvsp[-2].symbol_decls), symbol_list_type_set ((yyvsp[0].yytype_85), (yyvsp[-1].TAG), (yylsp[-1])));
+      (yyval.symbol_decls) = symbol_list_type_set ((yyvsp[0].yytype_86), (yyvsp[-1].TAG), (yylsp[-1]));
     }
     break;
 
   case 83:
-    { (yyval.yytype_85) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
+    {
+      (yyval.symbol_decls) = symbol_list_append ((yyvsp[-2].symbol_decls), symbol_list_type_set ((yyvsp[0].yytype_86), (yyvsp[-1].TAG), (yylsp[-1])));
+    }
     break;
 
   case 84:
-    { (yyval.yytype_85) = symbol_list_append ((yyvsp[-1].yytype_85), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
+    { (yyval.yytype_86) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
     break;
 
-  case 89:
+  case 85:
+    { (yyval.yytype_86) = symbol_list_append ((yyvsp[-1].yytype_86), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
+    break;
+
+  case 90:
     {
       yyerrok;
     }
     break;
 
-  case 90:
-    { current_lhs ((yyvsp[-1].id_colon), (yylsp[-1]), (yyvsp[0].yytype_92)); }
+  case 91:
+    { current_lhs ((yyvsp[-1].id_colon), (yylsp[-1]), (yyvsp[0].yytype_93)); }
     break;
 
-  case 91:
+  case 92:
     {
       /* Free the current lhs. */
       current_lhs (0, (yylsp[-4]), 0);
     }
     break;
 
-  case 92:
+  case 93:
     { grammar_current_rule_end ((yylsp[0])); }
     break;
 
-  case 93:
+  case 94:
     { grammar_current_rule_end ((yylsp[0])); }
     break;
 
-  case 95:
+  case 96:
     { grammar_current_rule_begin (current_lhs_symbol, current_lhs_loc,
                                   current_lhs_named_ref); }
     break;
 
-  case 96:
-    { grammar_current_rule_symbol_append ((yyvsp[-1].symbol), (yylsp[-1]), (yyvsp[0].yytype_92)); }
-    break;
-
   case 97:
-    { grammar_current_rule_action_append ((yyvsp[-1].BRACED_CODE), (yylsp[-1]), (yyvsp[0].yytype_92), (yyvsp[-2].yytype_72)); }
+    { grammar_current_rule_symbol_append ((yyvsp[-1].symbol), (yylsp[-1]), (yyvsp[0].yytype_93)); }
     break;
 
   case 98:
-    { grammar_current_rule_predicate_append ((yyvsp[0].BRACED_PREDICATE), (yylsp[0])); }
+    { grammar_current_rule_action_append ((yyvsp[-1].BRACED_CODE), (yylsp[-1]), (yyvsp[0].yytype_93), (yyvsp[-2].yytype_73)); }
     break;
 
   case 99:
-    { grammar_current_rule_empty_set ((yylsp[0])); }
+    { grammar_current_rule_predicate_append ((yyvsp[0].BRACED_PREDICATE), (yylsp[0])); }
     break;
 
   case 100:
-    { grammar_current_rule_prec_set ((yyvsp[0].symbol), (yylsp[0])); }
+    { grammar_current_rule_empty_set ((yylsp[0])); }
     break;
 
   case 101:
-    { grammar_current_rule_dprec_set ((yyvsp[0].INT), (yylsp[0])); }
+    { grammar_current_rule_prec_set ((yyvsp[0].symbol), (yylsp[0])); }
     break;
 
   case 102:
-    { grammar_current_rule_merge_set ((yyvsp[0].TAG), (yylsp[0])); }
+    { grammar_current_rule_dprec_set ((yyvsp[0].INT), (yylsp[0])); }
     break;
 
   case 103:
-    { grammar_current_rule_expect_sr ((yyvsp[0].INT), (yylsp[0])); }
+    { grammar_current_rule_merge_set ((yyvsp[0].TAG), (yylsp[0])); }
     break;
 
   case 104:
-    { grammar_current_rule_expect_rr ((yyvsp[0].INT), (yylsp[0])); }
+    { grammar_current_rule_expect_sr ((yyvsp[0].INT), (yylsp[0])); }
     break;
 
   case 105:
-    { (yyval.yytype_92) = NULL; }
+    { grammar_current_rule_expect_rr ((yyvsp[0].INT), (yylsp[0])); }
     break;
 
   case 106:
-    { (yyval.yytype_92) = named_ref_new ((yyvsp[0].BRACKETED_ID), (yylsp[0])); }
+    { (yyval.yytype_93) = NULL; }
     break;
 
-  case 108:
-    { (yyval.value).kind = muscle_keyword; (yyval.value).chars = ""; }
+  case 107:
+    { (yyval.yytype_93) = named_ref_new ((yyvsp[0].BRACKETED_ID), (yylsp[0])); }
     break;
 
   case 109:
-    { (yyval.value).kind = muscle_keyword; (yyval.value).chars = (yyvsp[0].ID); }
+    { (yyval.value).kind = muscle_keyword; (yyval.value).chars = ""; }
     break;
 
   case 110:
-    { (yyval.value).kind = muscle_string;  (yyval.value).chars = (yyvsp[0].STRING); }
+    { (yyval.value).kind = muscle_keyword; (yyval.value).chars = (yyvsp[0].ID); }
     break;
 
   case 111:
-    { (yyval.value).kind = muscle_code;    (yyval.value).chars = strip_braces ((yyvsp[0].BRACED_CODE)); }
+    { (yyval.value).kind = muscle_string;  (yyval.value).chars = (yyvsp[0].STRING); }
     break;
 
   case 112:
-    { (yyval.id) = symbol_from_uniqstr ((yyvsp[0].ID), (yylsp[0])); }
+    { (yyval.value).kind = muscle_code;    (yyval.value).chars = strip_braces ((yyvsp[0].BRACED_CODE)); }
     break;
 
   case 113:
+    { (yyval.id) = symbol_from_uniqstr ((yyvsp[0].ID), (yylsp[0])); }
+    break;
+
+  case 114:
     {
       if (current_class == nterm_sym)
         {
@@ -2488,22 +2499,22 @@ yyreduce:
     }
     break;
 
-  case 114:
+  case 115:
     { (yyval.id_colon) = symbol_from_uniqstr ((yyvsp[0].ID_COLON), (yylsp[0])); }
     break;
 
-  case 117:
+  case 118:
     {
       (yyval.string_as_id) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[0].STRING)), (yylsp[0]));
       symbol_class_set ((yyval.string_as_id), token_sym, (yylsp[0]), false);
     }
     break;
 
-  case 118:
-    { (yyval.yytype_99) = NULL; }
+  case 119:
+    { (yyval.yytype_100) = NULL; }
     break;
 
-  case 121:
+  case 122:
     {
       muscle_code_grow ("epilogue", translate_code ((yyvsp[0].EPILOGUE), (yylsp[0]), true), (yylsp[0]));
       code_scanner_last_string_free ();
@@ -2897,6 +2908,7 @@ handle_file_prefix (location const *loc,
     deprecated_directive (dir_loc, directive, "%file-prefix");
 }
 
+
 static void
 handle_name_prefix (location const *loc,
                     char const *directive, char const *value)
@@ -2931,6 +2943,16 @@ handle_name_prefix (location const *loc,
 }
 
 
+static void
+handle_pure_parser (location const *loc, char const *directive)
+{
+  bison_directive (loc, directive);
+  deprecated_directive (loc, directive, "%define api.pure");
+  muscle_percent_define_insert ("api.pure", *loc, muscle_keyword, "",
+                                MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
+}
+
+
 static void
 handle_require (location const *loc, char const *version)
 {
@@ -2993,6 +3015,7 @@ handle_skeleton (location const *loc, char const *skel)
   skeleton_arg (skeleton_user, grammar_prio, *loc);
 }
 
+
 static void
 handle_yacc (location const *loc, char const *directive)
 {
@@ -3013,6 +3036,7 @@ handle_yacc (location const *loc, char const *directive)
     deprecated_directive (loc, directive, "%fixed-output-files");
 }
 
+
 static void
 gram_error (location const *loc, char const *msg)
 {
