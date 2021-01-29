@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 3.3.2.122-5915.  */
+/* A Bison parser, made by GNU Bison 3.3.2.147-dd3d0.  */
 
 /* Bison implementation for Yacc-like parsers in C
 
@@ -48,7 +48,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "3.3.2.122-5915"
+#define YYBISON_VERSION "3.3.2.147-dd3d0"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -408,19 +408,19 @@ union yyalloc
 /* YYFINAL -- State number of the termination state.  */
 #define YYFINAL  3
 /* YYLAST -- Last index in YYTABLE.  */
-#define YYLAST   229
+#define YYLAST   232
 
 /* YYNTOKENS -- Number of terminals.  */
-#define YYNTOKENS  58
+#define YYNTOKENS  59
 /* YYNNTS -- Number of nonterminals.  */
 #define YYNNTS  42
 /* YYNRULES -- Number of rules.  */
 #define YYNRULES  121
 /* YYNSTATES -- Number of states.  */
-#define YYNSTATES  164
+#define YYNSTATES  165
 
 #define YYUNDEFTOK  2
-#define YYMAXUTOK   312
+#define YYMAXUTOK   313
 
 /* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
    as returned by yylex, with out-of-bounds checking.  */
@@ -462,26 +462,26 @@ static const yytype_uint8 yytranslate[] =
       25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
       35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
       45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
-      55,    56,    57
+      55,    56,    57,    58
 };
 
 #if GRAM_DEBUG
   /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
 static const yytype_uint16 yyrline[] =
 {
-       0,   282,   282,   291,   292,   296,   297,   303,   307,   312,
-     313,   318,   319,   320,   321,   322,   327,   332,   333,   334,
-     335,   336,   337,   337,   338,   339,   340,   341,   342,   343,
-     344,   348,   349,   358,   359,   363,   374,   378,   382,   390,
-     400,   401,   411,   412,   418,   431,   431,   436,   436,   441,
-     445,   455,   456,   457,   458,   462,   463,   468,   469,   473,
-     474,   478,   479,   480,   493,   502,   506,   510,   518,   519,
-     523,   536,   537,   549,   553,   557,   565,   567,   572,   579,
-     589,   593,   597,   605,   606,   614,   615,   621,   622,   623,
-     630,   630,   638,   639,   640,   645,   648,   650,   652,   654,
-     656,   658,   660,   662,   664,   669,   670,   679,   703,   704,
-     705,   706,   718,   720,   735,   740,   741,   746,   755,   756,
-     760,   761
+       0,   283,   283,   292,   293,   297,   298,   304,   308,   313,
+     314,   319,   320,   321,   322,   323,   328,   333,   334,   335,
+     336,   337,   338,   338,   339,   340,   341,   342,   343,   344,
+     345,   349,   350,   359,   360,   364,   375,   379,   383,   391,
+     401,   402,   412,   413,   419,   432,   432,   437,   437,   442,
+     446,   456,   457,   458,   459,   463,   464,   469,   470,   474,
+     475,   479,   480,   481,   494,   503,   507,   511,   519,   520,
+     524,   537,   538,   550,   554,   558,   566,   568,   573,   580,
+     590,   594,   598,   606,   607,   615,   616,   622,   623,   624,
+     631,   631,   639,   640,   641,   646,   649,   651,   653,   655,
+     657,   659,   661,   663,   665,   670,   671,   680,   704,   705,
+     706,   707,   719,   721,   736,   741,   742,   747,   756,   757,
+     761,   762
 };
 #endif
 
@@ -501,11 +501,11 @@ static const char *const yytname[] =
   "\"%nondeterministic-parser\"", "\"%output\"", "\"%require\"",
   "\"%skeleton\"", "\"%start\"", "\"%token-table\"", "\"%verbose\"",
   "\"%yacc\"", "\"{...}\"", "\"%?{...}\"", "\"[identifier]\"", "\"char\"",
-  "\"epilogue\"", "\"=\"", "\"identifier\"", "\"identifier:\"", "\"%%\"",
-  "\"|\"", "\"%{...%}\"", "\";\"", "\"<tag>\"", "\"<*>\"", "\"<>\"",
-  "\"integer\"", "\"%param\"", "\"%union\"", "\"%empty\"", "$accept",
-  "input", "prologue_declarations", "prologue_declaration", "$@1",
-  "params", "grammar_declaration", "code_props_type", "union_name",
+  "\":\"", "\"epilogue\"", "\"=\"", "\"identifier\"", "\"identifier:\"",
+  "\"%%\"", "\"|\"", "\"%{...%}\"", "\";\"", "\"<tag>\"", "\"<*>\"",
+  "\"<>\"", "\"integer\"", "\"%param\"", "\"%union\"", "\"%empty\"",
+  "$accept", "input", "prologue_declarations", "prologue_declaration",
+  "$@1", "params", "grammar_declaration", "code_props_type", "union_name",
   "symbol_declaration", "$@2", "$@3", "precedence_declarator", "tag.opt",
   "generic_symlist", "generic_symlist_item", "tag", "nterm_decls",
   "token_decls", "token_decl.1", "token_decl", "int.opt",
@@ -527,14 +527,14 @@ static const yytype_uint16 yytoknum[] =
      275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
      285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
      295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
-     305,   306,   307,   308,   309,   310,   311,   312
+     305,   306,   307,   308,   309,   310,   311,   312,   313
 };
 # endif
 
-#define YYPACT_NINF -123
+#define YYPACT_NINF -127
 
 #define yypact_value_is_default(Yystate) \
-  (!!((Yystate) == (-123)))
+  (!!((Yystate) == (-127)))
 
 #define YYTABLE_NINF -121
 
@@ -545,23 +545,23 @@ static const yytype_uint16 yytoknum[] =
      STATE-NUM.  */
 static const yytype_int16 yypact[] =
 {
-    -123,     6,   109,  -123,   -21,  -123,  -123,     2,  -123,  -123,
-    -123,  -123,  -123,  -123,   -11,  -123,    -7,    46,  -123,     3,
-      13,  -123,    77,  -123,    43,    87,    88,  -123,  -123,  -123,
-      91,    92,    94,    32,  -123,  -123,  -123,   162,  -123,  -123,
-    -123,    53,  -123,  -123,    61,  -123,    30,  -123,   -15,   -15,
-    -123,  -123,  -123,    32,    50,    32,  -123,  -123,  -123,  -123,
-      64,  -123,    23,  -123,  -123,  -123,  -123,  -123,  -123,  -123,
-    -123,  -123,  -123,  -123,    54,  -123,    55,     8,  -123,  -123,
-      65,    68,  -123,    69,    18,    32,    60,    32,  -123,    70,
-    -123,    16,    72,    16,  -123,    70,  -123,    72,    32,    32,
-    -123,  -123,  -123,  -123,  -123,  -123,  -123,  -123,   105,  -123,
-    -123,  -123,  -123,  -123,   110,  -123,  -123,  -123,  -123,    18,
-    -123,  -123,  -123,    32,    32,  -123,  -123,  -123,    16,    16,
-    -123,   147,    32,  -123,  -123,  -123,  -123,    32,    16,  -123,
-    -123,    37,   172,  -123,  -123,    32,    97,   101,    99,   100,
-    -123,  -123,  -123,   116,    65,   172,  -123,  -123,  -123,  -123,
-    -123,    65,  -123,  -123
+    -127,    31,   110,  -127,   -19,  -127,  -127,    30,  -127,  -127,
+    -127,  -127,  -127,  -127,   -12,  -127,   -11,    36,  -127,    -1,
+       5,  -127,    40,  -127,    41,    66,    67,  -127,  -127,  -127,
+      82,    87,    88,     3,  -127,  -127,  -127,   164,  -127,  -127,
+    -127,    48,  -127,  -127,    56,  -127,    55,  -127,    35,    35,
+    -127,  -127,  -127,     3,    46,     3,  -127,  -127,  -127,  -127,
+      61,  -127,    25,  -127,  -127,  -127,  -127,  -127,  -127,  -127,
+    -127,  -127,  -127,  -127,    52,  -127,    53,     9,  -127,  -127,
+      64,    69,  -127,    70,    21,     3,    54,     3,  -127,    57,
+    -127,   -34,    72,   -34,  -127,    57,  -127,    72,     3,     3,
+    -127,  -127,  -127,  -127,  -127,  -127,  -127,  -127,    81,  -127,
+    -127,  -127,  -127,  -127,   111,  -127,  -127,  -127,  -127,    21,
+    -127,  -127,  -127,     3,     3,  -127,  -127,  -127,   -34,   -34,
+    -127,   146,     3,  -127,   108,  -127,  -127,     3,   -34,  -127,
+    -127,  -127,    10,   174,  -127,  -127,     3,    97,   101,    99,
+     100,  -127,  -127,  -127,   117,    64,   174,  -127,  -127,  -127,
+    -127,  -127,    64,  -127,  -127
 };
 
   /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
@@ -582,29 +582,29 @@ static const yytype_uint8 yydefact[] =
       84,    39,   110,   111,   109,     8,    89,    88,     0,    86,
        2,   106,    90,    32,    23,    44,    61,    62,    63,    35,
       57,    60,    59,    74,     0,    77,    72,    78,    66,     0,
-      69,   118,    82,   121,    95,    31,    58,    75,    67,   119,
-      70,    91,    92,    95,    94,     0,     0,     0,     0,     0,
-      98,    56,    99,     0,   105,    93,   100,   101,   102,   103,
-     104,   105,    96,    97
+      69,   118,    82,   121,     0,    31,    58,    75,    67,   119,
+      70,    95,    91,    92,    95,    94,     0,     0,     0,     0,
+       0,    98,    56,    99,     0,   105,    93,   100,   101,   102,
+     103,   104,   105,    96,    97
 };
 
   /* YYPGOTO[NTERM-NUM].  */
 static const yytype_int16 yypgoto[] =
 {
-    -123,  -123,  -123,  -123,  -123,  -123,   155,  -123,  -123,  -123,
-    -123,  -123,  -123,  -123,  -123,    41,  -123,  -123,   112,   -84,
-     -62,    67,  -123,   -83,   -64,  -123,   -43,  -123,   103,  -123,
-    -123,  -123,    33,  -122,  -123,  -123,   -45,  -123,   -33,   -35,
-    -123,  -123
+    -127,  -127,  -127,  -127,  -127,  -127,   155,  -127,  -127,  -127,
+    -127,  -127,  -127,  -127,  -127,    43,  -127,  -127,   114,   -61,
+     -91,    83,  -127,   -62,   -82,  -127,   -46,  -127,   102,  -127,
+    -127,  -127,    15,  -126,  -127,  -127,   -45,  -127,   -33,   -35,
+    -127,  -127
 };
 
   /* YYDEFGOTO[NTERM-NUM].  */
 static const yytype_int16 yydefgoto[] =
 {
       -1,     1,     2,    42,    81,   114,    76,    44,    83,    45,
-      49,    48,    46,   153,   119,   120,   121,    96,    92,    93,
+      49,    48,    46,   154,   119,   120,   121,    96,    92,    93,
       94,   127,    86,    87,    88,    54,    55,    77,    78,    79,
-     134,   141,   142,   112,    62,   105,    56,    80,    57,    58,
+     134,   142,   143,   112,    62,   105,    56,    80,    57,    58,
      140,   110
 };
 
@@ -613,97 +613,99 @@ static const yytype_int16 yydefgoto[] =
      number is the opposite.  If YYTABLE_NINF, syntax error.  */
 static const yytype_int16 yytable[] =
 {
-      73,    89,   123,    95,    95,    50,     3,   128,  -120,    74,
-      98,    90,     5,     6,     7,     8,     9,    10,    11,    12,
-      13,    50,   100,   125,    14,    15,   102,    51,    59,    47,
-      52,   130,   162,    50,    60,    50,    91,    27,    61,   163,
-      89,   137,    89,    33,    51,   138,    95,    52,    95,    63,
-      90,   122,    90,    53,    75,   108,   132,    64,    51,   125,
-      51,    52,   103,    52,    41,   100,   130,    65,   104,   116,
-     117,   118,    51,   125,    51,    52,   130,    52,    89,    89,
-      66,    85,    67,    95,    95,   143,   122,   144,    90,    90,
-      68,    69,    89,    95,    70,    71,   139,    72,    82,   100,
-      84,    99,    90,   101,   106,   107,   111,   113,   115,   154,
-       4,   124,   156,     5,     6,     7,     8,     9,    10,    11,
-      12,    13,   154,   129,   126,    14,    15,    16,    17,    18,
-      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
-      29,    30,    31,    32,    33,    34,    35,    36,   133,   135,
-      50,   157,   158,   159,   160,   161,    37,    43,    38,    39,
-     136,    97,   131,    74,    40,    41,     5,     6,     7,     8,
-       9,    10,    11,    12,    13,    50,   155,     0,    14,    15,
-     109,     0,     0,     0,     0,   145,   146,   147,     0,     0,
-       0,    27,     0,   148,   149,     0,     0,    33,     0,     0,
-       0,     0,     0,     0,     0,     0,     0,     0,    75,     0,
-       0,   -55,   150,     0,    51,     0,     0,    52,    41,     0,
-       0,     0,     0,   151,     0,     0,     0,     0,     0,   152
+      73,    89,   130,    95,    95,   125,    50,    98,    51,  -120,
+      74,    90,    52,     5,     6,     7,     8,     9,    10,    11,
+      12,    13,   100,   123,    50,    14,    15,    59,   102,   163,
+     128,     3,    47,    50,    60,    61,   164,   130,    27,    63,
+      89,   125,    89,    66,    33,    51,    95,   130,    95,    52,
+      90,   122,    90,   132,    64,   125,    75,   108,    50,   144,
+      65,   145,   137,    51,   103,   100,    41,    52,   138,    68,
+      69,   104,    51,   116,   117,   118,    52,    51,    89,    89,
+      67,    52,    53,    95,    95,    70,   122,    91,    90,    90,
+      71,    72,    89,    95,    82,    84,   139,    51,    99,   100,
+     101,    52,    90,   106,   107,   111,   124,    85,   113,   115,
+     155,     4,   126,   157,     5,     6,     7,     8,     9,    10,
+      11,    12,    13,   155,   129,   133,    14,    15,    16,    17,
+      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
+      28,    29,    30,    31,    32,    33,    34,    35,    36,    50,
+     135,   141,   158,   159,   160,   161,   162,    43,    37,   156,
+      38,    39,   136,    97,     0,    74,    40,    41,     5,     6,
+       7,     8,     9,    10,    11,    12,    13,    50,   131,   109,
+      14,    15,     0,     0,     0,     0,     0,   146,   147,   148,
+       0,     0,     0,    27,     0,   149,   150,     0,     0,    33,
+       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
+       0,    75,     0,   -55,   151,     0,    51,     0,     0,     0,
+      52,    41,     0,     0,     0,     0,   152,     0,     0,     0,
+       0,     0,   153
 };
 
 static const yytype_int16 yycheck[] =
 {
-      33,    46,    85,    48,    49,     3,     0,    91,     0,     1,
-      53,    46,     4,     5,     6,     7,     8,     9,    10,    11,
-      12,     3,    55,    87,    16,    17,     3,    42,    39,    50,
-      45,    93,   154,     3,    45,     3,    51,    29,    45,   161,
-      85,   124,    87,    35,    42,   129,    91,    45,    93,     3,
-      85,    84,    87,    51,    46,    47,    99,    54,    42,   123,
-      42,    45,    39,    45,    56,    98,   128,    54,    45,    51,
-      52,    53,    42,   137,    42,    45,   138,    45,   123,   124,
-       3,    51,    39,   128,   129,    48,   119,    50,   123,   124,
-       3,     3,   137,   138,     3,     3,   131,     3,    45,   132,
-      39,    51,   137,    39,    50,    50,    41,    39,    39,   142,
-       1,    51,   145,     4,     5,     6,     7,     8,     9,    10,
-      11,    12,   155,    51,    54,    16,    17,    18,    19,    20,
-      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
-      31,    32,    33,    34,    35,    36,    37,    38,    43,    39,
-       3,    54,    51,    54,    54,    39,    47,     2,    49,    50,
-     119,    49,    95,     1,    55,    56,     4,     5,     6,     7,
-       8,     9,    10,    11,    12,     3,   143,    -1,    16,    17,
-      77,    -1,    -1,    -1,    -1,    13,    14,    15,    -1,    -1,
-      -1,    29,    -1,    21,    22,    -1,    -1,    35,    -1,    -1,
-      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,    -1,
-      -1,    39,    40,    -1,    42,    -1,    -1,    45,    56,    -1,
-      -1,    -1,    -1,    51,    -1,    -1,    -1,    -1,    -1,    57
+      33,    46,    93,    48,    49,    87,     3,    53,    42,     0,
+       1,    46,    46,     4,     5,     6,     7,     8,     9,    10,
+      11,    12,    55,    85,     3,    16,    17,    39,     3,   155,
+      91,     0,    51,     3,    46,    46,   162,   128,    29,     3,
+      85,   123,    87,     3,    35,    42,    91,   138,    93,    46,
+      85,    84,    87,    99,    55,   137,    47,    48,     3,    49,
+      55,    51,   124,    42,    39,    98,    57,    46,   129,     3,
+       3,    46,    42,    52,    53,    54,    46,    42,   123,   124,
+      39,    46,    52,   128,   129,     3,   119,    52,   123,   124,
+       3,     3,   137,   138,    46,    39,   131,    42,    52,   132,
+      39,    46,   137,    51,    51,    41,    52,    52,    39,    39,
+     143,     1,    55,   146,     4,     5,     6,     7,     8,     9,
+      10,    11,    12,   156,    52,    44,    16,    17,    18,    19,
+      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
+      30,    31,    32,    33,    34,    35,    36,    37,    38,     3,
+      39,    43,    55,    52,    55,    55,    39,     2,    48,   144,
+      50,    51,   119,    49,    -1,     1,    56,    57,     4,     5,
+       6,     7,     8,     9,    10,    11,    12,     3,    95,    77,
+      16,    17,    -1,    -1,    -1,    -1,    -1,    13,    14,    15,
+      -1,    -1,    -1,    29,    -1,    21,    22,    -1,    -1,    35,
+      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
+      -1,    47,    -1,    39,    40,    -1,    42,    -1,    -1,    -1,
+      46,    57,    -1,    -1,    -1,    -1,    52,    -1,    -1,    -1,
+      -1,    -1,    58
 };
 
   /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
      symbol of state STATE-NUM.  */
 static const yytype_uint8 yystos[] =
 {
-       0,    59,    60,     0,     1,     4,     5,     6,     7,     8,
+       0,    60,    61,     0,     1,     4,     5,     6,     7,     8,
        9,    10,    11,    12,    16,    17,    18,    19,    20,    21,
       22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
-      32,    33,    34,    35,    36,    37,    38,    47,    49,    50,
-      55,    56,    61,    64,    65,    67,    70,    50,    69,    68,
-       3,    42,    45,    51,    83,    84,    94,    96,    97,    39,
-      45,    45,    92,     3,    54,    54,     3,    39,     3,     3,
-       3,     3,     3,    96,     1,    46,    64,    85,    86,    87,
-      95,    62,    45,    66,    39,    51,    80,    81,    82,    94,
-      97,    51,    76,    77,    78,    94,    75,    76,    84,    51,
-      96,    39,     3,    39,    45,    93,    50,    50,    47,    86,
-      99,    41,    91,    39,    63,    39,    51,    52,    53,    72,
-      73,    74,    96,    81,    51,    82,    54,    79,    77,    51,
-      78,    79,    84,    43,    88,    39,    73,    81,    77,    97,
-      98,    89,    90,    48,    50,    13,    14,    15,    21,    22,
-      40,    51,    57,    71,    96,    90,    96,    54,    51,    54,
-      54,    39,    91,    91
+      32,    33,    34,    35,    36,    37,    38,    48,    50,    51,
+      56,    57,    62,    65,    66,    68,    71,    51,    70,    69,
+       3,    42,    46,    52,    84,    85,    95,    97,    98,    39,
+      46,    46,    93,     3,    55,    55,     3,    39,     3,     3,
+       3,     3,     3,    97,     1,    47,    65,    86,    87,    88,
+      96,    63,    46,    67,    39,    52,    81,    82,    83,    95,
+      98,    52,    77,    78,    79,    95,    76,    77,    85,    52,
+      97,    39,     3,    39,    46,    94,    51,    51,    48,    87,
+     100,    41,    92,    39,    64,    39,    52,    53,    54,    73,
+      74,    75,    97,    82,    52,    83,    55,    80,    78,    52,
+      79,    80,    85,    44,    89,    39,    74,    82,    78,    98,
+      99,    43,    90,    91,    49,    51,    13,    14,    15,    21,
+      22,    40,    52,    58,    72,    97,    91,    97,    55,    52,
+      55,    55,    39,    92,    92
 };
 
   /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
 static const yytype_uint8 yyr1[] =
 {
-       0,    58,    59,    60,    60,    61,    61,    61,    61,    61,
-      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
-      61,    61,    62,    61,    61,    61,    61,    61,    61,    61,
-      61,    63,    63,    64,    64,    64,    64,    64,    64,    64,
-      65,    65,    66,    66,    64,    68,    67,    69,    67,    67,
-      67,    70,    70,    70,    70,    71,    71,    72,    72,    73,
-      73,    74,    74,    74,    75,    76,    76,    76,    77,    77,
-      78,    79,    79,    80,    80,    80,    81,    81,    82,    82,
-      83,    83,    83,    84,    84,    85,    85,    86,    86,    86,
-      88,    87,    89,    89,    89,    90,    90,    90,    90,    90,
-      90,    90,    90,    90,    90,    91,    91,    92,    93,    93,
-      93,    93,    94,    94,    95,    96,    96,    97,    98,    98,
-      99,    99
+       0,    59,    60,    61,    61,    62,    62,    62,    62,    62,
+      62,    62,    62,    62,    62,    62,    62,    62,    62,    62,
+      62,    62,    63,    62,    62,    62,    62,    62,    62,    62,
+      62,    64,    64,    65,    65,    65,    65,    65,    65,    65,
+      66,    66,    67,    67,    65,    69,    68,    70,    68,    68,
+      68,    71,    71,    71,    71,    72,    72,    73,    73,    74,
+      74,    75,    75,    75,    76,    77,    77,    77,    78,    78,
+      79,    80,    80,    81,    81,    81,    82,    82,    83,    83,
+      84,    84,    84,    85,    85,    86,    86,    87,    87,    87,
+      89,    88,    90,    90,    90,    91,    91,    91,    91,    91,
+      91,    91,    91,    91,    91,    92,    92,    93,    94,    94,
+      94,    94,    95,    95,    96,    97,    97,    98,    99,    99,
+     100,   100
 };
 
   /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
@@ -718,7 +720,7 @@ static const yytype_uint8 yyr2[] =
        1,     1,     1,     1,     1,     1,     2,     3,     1,     2,
        3,     0,     1,     1,     2,     3,     1,     2,     2,     1,
        1,     2,     3,     1,     2,     1,     2,     1,     2,     2,
-       0,     4,     1,     3,     2,     0,     3,     4,     2,     2,
+       0,     5,     1,     3,     2,     0,     3,     4,     2,     2,
        3,     3,     3,     3,     3,     0,     1,     1,     0,     1,
        1,     1,     1,     1,     1,     1,     1,     1,     0,     1,
        0,     2
@@ -916,31 +918,31 @@ yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YY
       { fputs (char_name (((*yyvaluep).CHAR)), yyo); }
         break;
 
-    case 43: /* "epilogue"  */
+    case 44: /* "epilogue"  */
       { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).EPILOGUE)); }
         break;
 
-    case 45: /* "identifier"  */
+    case 46: /* "identifier"  */
       { fputs (((*yyvaluep).ID), yyo); }
         break;
 
-    case 46: /* "identifier:"  */
+    case 47: /* "identifier:"  */
       { fprintf (yyo, "%s:", ((*yyvaluep).ID_COLON)); }
         break;
 
-    case 49: /* "%{...%}"  */
+    case 50: /* "%{...%}"  */
       { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).PROLOGUE)); }
         break;
 
-    case 51: /* "<tag>"  */
+    case 52: /* "<tag>"  */
       { fprintf (yyo, "<%s>", ((*yyvaluep).TAG)); }
         break;
 
-    case 54: /* "integer"  */
+    case 55: /* "integer"  */
       { fprintf (yyo, "%d", ((*yyvaluep).INT)); }
         break;
 
-    case 55: /* "%param"  */
+    case 56: /* "%param"  */
       {
   switch (((*yyvaluep).PERCENT_PARAM))
     {
@@ -955,71 +957,71 @@ yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YY
 }
         break;
 
-    case 65: /* code_props_type  */
+    case 66: /* code_props_type  */
       { fprintf (yyo, "%s", code_props_type_string (((*yyvaluep).code_props_type))); }
         break;
 
-    case 71: /* tag.opt  */
-      { fputs (((*yyvaluep).yytype_71), yyo); }
+    case 72: /* tag.opt  */
+      { fputs (((*yyvaluep).yytype_72), yyo); }
         break;
 
-    case 72: /* generic_symlist  */
+    case 73: /* generic_symlist  */
       { symbol_list_syms_print (((*yyvaluep).generic_symlist), yyo); }
         break;
 
-    case 73: /* generic_symlist_item  */
+    case 74: /* generic_symlist_item  */
       { symbol_list_syms_print (((*yyvaluep).generic_symlist_item), yyo); }
         break;
 
-    case 74: /* tag  */
+    case 75: /* tag  */
       { fprintf (yyo, "<%s>", ((*yyvaluep).tag)); }
         break;
 
-    case 75: /* nterm_decls  */
+    case 76: /* nterm_decls  */
       { symbol_list_syms_print (((*yyvaluep).nterm_decls), yyo); }
         break;
 
-    case 76: /* token_decls  */
+    case 77: /* token_decls  */
       { symbol_list_syms_print (((*yyvaluep).token_decls), yyo); }
         break;
 
-    case 77: /* token_decl.1  */
-      { symbol_list_syms_print (((*yyvaluep).yytype_77), yyo); }
+    case 78: /* token_decl.1  */
+      { symbol_list_syms_print (((*yyvaluep).yytype_78), yyo); }
         break;
 
-    case 78: /* token_decl  */
+    case 79: /* token_decl  */
       { fprintf (yyo, "%s", ((*yyvaluep).token_decl) ? ((*yyvaluep).token_decl)->tag : "<NULL>"); }
         break;
 
-    case 79: /* int.opt  */
-      { fprintf (yyo, "%d", ((*yyvaluep).yytype_79)); }
+    case 80: /* int.opt  */
+      { fprintf (yyo, "%d", ((*yyvaluep).yytype_80)); }
         break;
 
-    case 80: /* token_decls_for_prec  */
+    case 81: /* token_decls_for_prec  */
       { symbol_list_syms_print (((*yyvaluep).token_decls_for_prec), yyo); }
         break;
 
-    case 81: /* token_decl_for_prec.1  */
-      { symbol_list_syms_print (((*yyvaluep).yytype_81), yyo); }
+    case 82: /* token_decl_for_prec.1  */
+      { symbol_list_syms_print (((*yyvaluep).yytype_82), yyo); }
         break;
 
-    case 82: /* token_decl_for_prec  */
+    case 83: /* token_decl_for_prec  */
       { fprintf (yyo, "%s", ((*yyvaluep).token_decl_for_prec) ? ((*yyvaluep).token_decl_for_prec)->tag : "<NULL>"); }
         break;
 
-    case 83: /* symbol_decls  */
+    case 84: /* symbol_decls  */
       { symbol_list_syms_print (((*yyvaluep).symbol_decls), yyo); }
         break;
 
-    case 84: /* symbol_decl.1  */
-      { symbol_list_syms_print (((*yyvaluep).yytype_84), yyo); }
+    case 85: /* symbol_decl.1  */
+      { symbol_list_syms_print (((*yyvaluep).yytype_85), yyo); }
         break;
 
-    case 92: /* variable  */
+    case 93: /* variable  */
       { fputs (((*yyvaluep).variable), yyo); }
         break;
 
-    case 93: /* value  */
+    case 94: /* value  */
       {
   switch (((*yyvaluep).value).kind)
     {
@@ -1030,24 +1032,24 @@ yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YY
 }
         break;
 
-    case 94: /* id  */
+    case 95: /* id  */
       { fprintf (yyo, "%s", ((*yyvaluep).id) ? ((*yyvaluep).id)->tag : "<NULL>"); }
         break;
 
-    case 95: /* id_colon  */
+    case 96: /* id_colon  */
       { fprintf (yyo, "%s:", ((*yyvaluep).id_colon)->tag); }
         break;
 
-    case 96: /* symbol  */
+    case 97: /* symbol  */
       { fprintf (yyo, "%s", ((*yyvaluep).symbol) ? ((*yyvaluep).symbol)->tag : "<NULL>"); }
         break;
 
-    case 97: /* string_as_id  */
+    case 98: /* string_as_id  */
       { fprintf (yyo, "%s", ((*yyvaluep).string_as_id) ? ((*yyvaluep).string_as_id)->tag : "<NULL>"); }
         break;
 
-    case 98: /* string_as_id.opt  */
-      { fprintf (yyo, "%s", ((*yyvaluep).yytype_98) ? ((*yyvaluep).yytype_98)->tag : "<NULL>"); }
+    case 99: /* string_as_id.opt  */
+      { fprintf (yyo, "%s", ((*yyvaluep).yytype_99) ? ((*yyvaluep).yytype_99)->tag : "<NULL>"); }
         break;
 
       default:
@@ -1634,40 +1636,40 @@ yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocatio
   YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
   switch (yytype)
     {
-    case 72: /* generic_symlist  */
+    case 73: /* generic_symlist  */
       { symbol_list_free (((*yyvaluep).generic_symlist)); }
         break;
 
-    case 73: /* generic_symlist_item  */
+    case 74: /* generic_symlist_item  */
       { symbol_list_free (((*yyvaluep).generic_symlist_item)); }
         break;
 
-    case 75: /* nterm_decls  */
+    case 76: /* nterm_decls  */
       { symbol_list_free (((*yyvaluep).nterm_decls)); }
         break;
 
-    case 76: /* token_decls  */
+    case 77: /* token_decls  */
       { symbol_list_free (((*yyvaluep).token_decls)); }
         break;
 
-    case 77: /* token_decl.1  */
-      { symbol_list_free (((*yyvaluep).yytype_77)); }
+    case 78: /* token_decl.1  */
+      { symbol_list_free (((*yyvaluep).yytype_78)); }
         break;
 
-    case 80: /* token_decls_for_prec  */
+    case 81: /* token_decls_for_prec  */
       { symbol_list_free (((*yyvaluep).token_decls_for_prec)); }
         break;
 
-    case 81: /* token_decl_for_prec.1  */
-      { symbol_list_free (((*yyvaluep).yytype_81)); }
+    case 82: /* token_decl_for_prec.1  */
+      { symbol_list_free (((*yyvaluep).yytype_82)); }
         break;
 
-    case 83: /* symbol_decls  */
+    case 84: /* symbol_decls  */
       { symbol_list_free (((*yyvaluep).symbol_decls)); }
         break;
 
-    case 84: /* symbol_decl.1  */
-      { symbol_list_free (((*yyvaluep).yytype_84)); }
+    case 85: /* symbol_decl.1  */
+      { symbol_list_free (((*yyvaluep).yytype_85)); }
         break;
 
       default:
@@ -2239,11 +2241,11 @@ yyreduce:
     break;
 
   case 55:
-    { (yyval.yytype_71) = NULL; }
+    { (yyval.yytype_72) = NULL; }
     break;
 
   case 56:
-    { (yyval.yytype_71) = (yyvsp[0].TAG); }
+    { (yyval.yytype_72) = (yyvsp[0].TAG); }
     break;
 
   case 58:
@@ -2268,104 +2270,104 @@ yyreduce:
 
   case 65:
     {
-      (yyval.token_decls) = (yyvsp[0].yytype_77);
+      (yyval.token_decls) = (yyvsp[0].yytype_78);
     }
     break;
 
   case 66:
     {
-      (yyval.token_decls) = symbol_list_type_set ((yyvsp[0].yytype_77), (yyvsp[-1].TAG), (yylsp[-1]));
+      (yyval.token_decls) = symbol_list_type_set ((yyvsp[0].yytype_78), (yyvsp[-1].TAG), (yylsp[-1]));
     }
     break;
 
   case 67:
     {
-      (yyval.token_decls) = symbol_list_append ((yyvsp[-2].token_decls), symbol_list_type_set ((yyvsp[0].yytype_77), (yyvsp[-1].TAG), (yylsp[-1])));
+      (yyval.token_decls) = symbol_list_append ((yyvsp[-2].token_decls), symbol_list_type_set ((yyvsp[0].yytype_78), (yyvsp[-1].TAG), (yylsp[-1])));
     }
     break;
 
   case 68:
-    { (yyval.yytype_77) = symbol_list_sym_new ((yyvsp[0].token_decl), (yylsp[0])); }
+    { (yyval.yytype_78) = symbol_list_sym_new ((yyvsp[0].token_decl), (yylsp[0])); }
     break;
 
   case 69:
-    { (yyval.yytype_77) = symbol_list_append ((yyvsp[-1].yytype_77), symbol_list_sym_new ((yyvsp[0].token_decl), (yylsp[0]))); }
+    { (yyval.yytype_78) = symbol_list_append ((yyvsp[-1].yytype_78), symbol_list_sym_new ((yyvsp[0].token_decl), (yylsp[0]))); }
     break;
 
   case 70:
     {
       (yyval.token_decl) = (yyvsp[-2].id);
       symbol_class_set ((yyvsp[-2].id), current_class, (yylsp[-2]), true);
-      if (0 <= (yyvsp[-1].yytype_79))
-        symbol_user_token_number_set ((yyvsp[-2].id), (yyvsp[-1].yytype_79), (yylsp[-1]));
-      if ((yyvsp[0].yytype_98))
-        symbol_make_alias ((yyvsp[-2].id), (yyvsp[0].yytype_98), (yylsp[0]));
+      if (0 <= (yyvsp[-1].yytype_80))
+        symbol_user_token_number_set ((yyvsp[-2].id), (yyvsp[-1].yytype_80), (yylsp[-1]));
+      if ((yyvsp[0].yytype_99))
+        symbol_make_alias ((yyvsp[-2].id), (yyvsp[0].yytype_99), (yylsp[0]));
     }
     break;
 
   case 71:
-    { (yyval.yytype_79) = -1; }
+    { (yyval.yytype_80) = -1; }
     break;
 
   case 73:
     {
-      (yyval.token_decls_for_prec) = (yyvsp[0].yytype_81);
+      (yyval.token_decls_for_prec) = (yyvsp[0].yytype_82);
     }
     break;
 
   case 74:
     {
-      (yyval.token_decls_for_prec) = symbol_list_type_set ((yyvsp[0].yytype_81), (yyvsp[-1].TAG), (yylsp[-1]));
+      (yyval.token_decls_for_prec) = symbol_list_type_set ((yyvsp[0].yytype_82), (yyvsp[-1].TAG), (yylsp[-1]));
     }
     break;
 
   case 75:
     {
-      (yyval.token_decls_for_prec) = symbol_list_append ((yyvsp[-2].token_decls_for_prec), symbol_list_type_set ((yyvsp[0].yytype_81), (yyvsp[-1].TAG), (yylsp[-1])));
+      (yyval.token_decls_for_prec) = symbol_list_append ((yyvsp[-2].token_decls_for_prec), symbol_list_type_set ((yyvsp[0].yytype_82), (yyvsp[-1].TAG), (yylsp[-1])));
     }
     break;
 
   case 76:
-    { (yyval.yytype_81) = symbol_list_sym_new ((yyvsp[0].token_decl_for_prec), (yylsp[0])); }
+    { (yyval.yytype_82) = symbol_list_sym_new ((yyvsp[0].token_decl_for_prec), (yylsp[0])); }
     break;
 
   case 77:
-    { (yyval.yytype_81) = symbol_list_append ((yyvsp[-1].yytype_81), symbol_list_sym_new ((yyvsp[0].token_decl_for_prec), (yylsp[0]))); }
+    { (yyval.yytype_82) = symbol_list_append ((yyvsp[-1].yytype_82), symbol_list_sym_new ((yyvsp[0].token_decl_for_prec), (yylsp[0]))); }
     break;
 
   case 78:
     {
       (yyval.token_decl_for_prec) = (yyvsp[-1].id);
       symbol_class_set ((yyvsp[-1].id), token_sym, (yylsp[-1]), false);
-      if (0 <= (yyvsp[0].yytype_79))
-        symbol_user_token_number_set ((yyvsp[-1].id), (yyvsp[0].yytype_79), (yylsp[0]));
+      if (0 <= (yyvsp[0].yytype_80))
+        symbol_user_token_number_set ((yyvsp[-1].id), (yyvsp[0].yytype_80), (yylsp[0]));
     }
     break;
 
   case 80:
     {
-      (yyval.symbol_decls) = (yyvsp[0].yytype_84);
+      (yyval.symbol_decls) = (yyvsp[0].yytype_85);
     }
     break;
 
   case 81:
     {
-      (yyval.symbol_decls) = symbol_list_type_set ((yyvsp[0].yytype_84), (yyvsp[-1].TAG), (yylsp[-1]));
+      (yyval.symbol_decls) = symbol_list_type_set ((yyvsp[0].yytype_85), (yyvsp[-1].TAG), (yylsp[-1]));
     }
     break;
 
   case 82:
     {
-      (yyval.symbol_decls) = symbol_list_append ((yyvsp[-2].symbol_decls), symbol_list_type_set ((yyvsp[0].yytype_84), (yyvsp[-1].TAG), (yylsp[-1])));
+      (yyval.symbol_decls) = symbol_list_append ((yyvsp[-2].symbol_decls), symbol_list_type_set ((yyvsp[0].yytype_85), (yyvsp[-1].TAG), (yylsp[-1])));
     }
     break;
 
   case 83:
-    { (yyval.yytype_84) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
+    { (yyval.yytype_85) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
     break;
 
   case 84:
-    { (yyval.yytype_84) = symbol_list_append ((yyvsp[-1].yytype_84), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
+    { (yyval.yytype_85) = symbol_list_append ((yyvsp[-1].yytype_85), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
     break;
 
   case 89:
@@ -2375,13 +2377,13 @@ yyreduce:
     break;
 
   case 90:
-    { current_lhs ((yyvsp[-1].id_colon), (yylsp[-1]), (yyvsp[0].yytype_91)); }
+    { current_lhs ((yyvsp[-1].id_colon), (yylsp[-1]), (yyvsp[0].yytype_92)); }
     break;
 
   case 91:
     {
       /* Free the current lhs. */
-      current_lhs (0, (yylsp[-3]), 0);
+      current_lhs (0, (yylsp[-4]), 0);
     }
     break;
 
@@ -2399,11 +2401,11 @@ yyreduce:
     break;
 
   case 96:
-    { grammar_current_rule_symbol_append ((yyvsp[-1].symbol), (yylsp[-1]), (yyvsp[0].yytype_91)); }
+    { grammar_current_rule_symbol_append ((yyvsp[-1].symbol), (yylsp[-1]), (yyvsp[0].yytype_92)); }
     break;
 
   case 97:
-    { grammar_current_rule_action_append ((yyvsp[-1].BRACED_CODE), (yylsp[-1]), (yyvsp[0].yytype_91), (yyvsp[-2].yytype_71)); }
+    { grammar_current_rule_action_append ((yyvsp[-1].BRACED_CODE), (yylsp[-1]), (yyvsp[0].yytype_92), (yyvsp[-2].yytype_72)); }
     break;
 
   case 98:
@@ -2435,11 +2437,11 @@ yyreduce:
     break;
 
   case 105:
-    { (yyval.yytype_91) = NULL; }
+    { (yyval.yytype_92) = NULL; }
     break;
 
   case 106:
-    { (yyval.yytype_91) = named_ref_new ((yyvsp[0].BRACKETED_ID), (yylsp[0])); }
+    { (yyval.yytype_92) = named_ref_new ((yyvsp[0].BRACKETED_ID), (yylsp[0])); }
     break;
 
   case 108:
@@ -2488,7 +2490,7 @@ yyreduce:
     break;
 
   case 118:
-    { (yyval.yytype_98) = NULL; }
+    { (yyval.yytype_99) = NULL; }
     break;
 
   case 121:
