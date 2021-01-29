@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 2.4.323-f8e7-dirty.  */
+/* A Bison parser, made by GNU Bison 2.4.336-b5c21.  */
 
 /* Implementation for Bison's Yacc-like parsers in C
 
@@ -45,7 +45,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "2.4.323-f8e7-dirty"
+#define YYBISON_VERSION "2.4.336-b5c21"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -107,6 +107,7 @@
 #include "quotearg.h"
 #include "reader.h"
 #include "symlist.h"
+#include "named-ref.h"
 #include "scan-gram.h"
 #include "scan-code.h"
 
@@ -140,6 +141,7 @@ static symbol_class current_class = unknown_sym;
 static uniqstr current_type = NULL;
 static symbol *current_lhs;
 static location current_lhs_location;
+static named_ref *current_lhs_named_ref;
 static int current_prec = 0;
 
 #define YYTYPE_INT16 int_fast16_t
@@ -148,7 +150,7 @@ static int current_prec = 0;
 #define YYTYPE_UINT8 uint_fast8_t
 
 /* Line 191 of yacc.c  */
-#line 152 "src/parse-gram.c"
+#line 154 "../bison/src/parse-gram.c"
 
 /* Enabling traces.  */
 #ifndef YYDEBUG
@@ -227,7 +229,8 @@ static int current_prec = 0;
      TAG = 306,
      TAG_ANY = 307,
      TAG_NONE = 308,
-     PERCENT_UNION = 309
+     BRACKETED_ID = 309,
+     PERCENT_UNION = 310
    };
 #endif
 /* Tokens.  */
@@ -283,7 +286,8 @@ static int current_prec = 0;
 #define TAG 306
 #define TAG_ANY 307
 #define TAG_NONE 308
-#define PERCENT_UNION 309
+#define BRACKETED_ID 309
+#define PERCENT_UNION 310
 
 
 
@@ -291,8 +295,8 @@ static int current_prec = 0;
 #if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
 typedef union YYSTYPE
 {
-/* Line 224 of yacc.c  */
-#line 92 "parse-gram.y"
+/* Line 216 of yacc.c  */
+#line 94 "parse-gram.y"
 
   symbol *symbol;
   symbol_list *list;
@@ -302,10 +306,11 @@ typedef union YYSTYPE
   assoc assoc;
   uniqstr uniqstr;
   unsigned char character;
+  named_ref *named_ref;
 
 
-/* Line 224 of yacc.c  */
-#line 309 "src/parse-gram.c"
+/* Line 216 of yacc.c  */
+#line 314 "../bison/src/parse-gram.c"
 } YYSTYPE;
 # define YYSTYPE_IS_TRIVIAL 1
 # define yystype YYSTYPE /* obsolescent; will be withdrawn */
@@ -329,7 +334,7 @@ typedef struct YYLTYPE
 /* Copy the second part of user declarations.  */
 
 /* Line 266 of yacc.c  */
-#line 333 "src/parse-gram.c"
+#line 338 "../bison/src/parse-gram.c"
 
 #ifdef short
 # undef short
@@ -546,21 +551,21 @@ union yyalloc
 /* YYFINAL -- State number of the termination state.  */
 #define YYFINAL  3
 /* YYLAST -- Last index in YYTABLE.  */
-#define YYLAST   186
+#define YYLAST   160
 
 /* YYNTOKENS -- Number of terminals.  */
-#define YYNTOKENS  55
+#define YYNTOKENS  56
 /* YYNNTS -- Number of nonterminals.  */
-#define YYNNTS  33
+#define YYNNTS  34
 /* YYNRULES -- Number of rules.  */
-#define YYNRULES  103
+#define YYNRULES  105
 /* YYNSTATES -- Number of states.  */
-#define YYNSTATES  141
+#define YYNSTATES  145
 
 /* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
    by yylex, with out-of-bounds checking.  */
 #define YYUNDEFTOK  2
-#define YYMAXUTOK   309
+#define YYMAXUTOK   310
 
 #define YYTRANSLATE(YYX)						\
   ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)
@@ -599,24 +604,25 @@ static const yytype_uint8 yytranslate[] =
       15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
       25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
       35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
-      45,    46,    47,    48,    49,    50,    51,    52,    53,    54
+      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
+      55
 };
 
 #if YYDEBUG
   /* YYRLINEYYN -- Source line where rule number YYN was defined.    */
 static const yytype_uint16 yyrline[] =
 {
-       0,   201,   201,   209,   211,   215,   216,   226,   230,   235,
-     236,   241,   242,   243,   244,   245,   250,   259,   260,   261,
-     262,   263,   264,   265,   266,   267,   268,   269,   293,   294,
-     295,   296,   300,   301,   302,   306,   313,   320,   324,   328,
-     335,   350,   351,   355,   367,   367,   372,   372,   377,   388,
-     403,   404,   405,   406,   410,   411,   416,   418,   423,   424,
-     429,   431,   436,   437,   441,   442,   443,   444,   449,   454,
-     459,   465,   471,   482,   483,   492,   493,   499,   500,   501,
-     508,   508,   512,   513,   514,   519,   520,   522,   524,   526,
-     528,   540,   541,   546,   547,   556,   576,   578,   587,   592,
-     593,   598,   605,   607
+       0,   206,   206,   214,   216,   220,   221,   231,   235,   240,
+     241,   246,   247,   248,   249,   250,   255,   264,   265,   266,
+     267,   268,   269,   270,   271,   272,   273,   274,   298,   299,
+     300,   301,   305,   306,   307,   311,   318,   325,   329,   333,
+     340,   355,   356,   360,   372,   372,   377,   377,   382,   393,
+     408,   409,   410,   411,   415,   416,   421,   423,   428,   429,
+     434,   436,   441,   442,   446,   447,   448,   449,   454,   459,
+     464,   470,   476,   487,   488,   497,   498,   504,   505,   506,
+     513,   513,   518,   519,   520,   525,   527,   529,   531,   533,
+     535,   541,   543,   555,   556,   561,   562,   571,   591,   593,
+     602,   607,   608,   613,   620,   622
 };
 #endif
 
@@ -637,15 +643,15 @@ static const char *const yytname[] =
   "\"%require\"", "\"%skeleton\"", "\"%start\"", "\"%token-table\"",
   "\"%verbose\"", "\"%yacc\"", "\"{...}\"", "\"char\"", "\"epilogue\"",
   "\"=\"", "\"identifier\"", "\"identifier:\"", "\"%%\"", "\"|\"",
-  "\"%{...%}\"", "\";\"", "\"<tag>\"", "\"<*>\"", "\"<>\"", "\"%union\"",
-  "$accept", "input", "prologue_declarations", "prologue_declaration",
-  "grammar_declaration", "union_name", "symbol_declaration", "$@1", "$@2",
-  "precedence_declaration", "precedence_declarator", "tag.opt",
-  "symbols.prec", "symbol.prec", "symbols.1", "generic_symlist",
-  "generic_symlist_item", "symbol_def", "symbol_defs.1", "grammar",
-  "rules_or_grammar_declaration", "rules", "$@3", "rhses.1", "rhs",
-  "variable", "content.opt", "braceless", "id", "id_colon", "symbol",
-  "string_as_id", "epilogue.opt", 0
+  "\"%{...%}\"", "\";\"", "\"<tag>\"", "\"<*>\"", "\"<>\"", "\"[id]\"",
+  "\"%union\"", "$accept", "input", "prologue_declarations",
+  "prologue_declaration", "grammar_declaration", "union_name",
+  "symbol_declaration", "$@1", "$@2", "precedence_declaration",
+  "precedence_declarator", "tag.opt", "symbols.prec", "symbol.prec",
+  "symbols.1", "generic_symlist", "generic_symlist_item", "symbol_def",
+  "symbol_defs.1", "grammar", "rules_or_grammar_declaration", "rules",
+  "$@3", "rhses.1", "rhs", "named_ref.opt", "variable", "content.opt",
+  "braceless", "id", "id_colon", "symbol", "string_as_id", "epilogue.opt", 0
 };
 #endif
 
@@ -659,33 +665,33 @@ static const yytype_uint16 yytoknum[] =
      275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
      285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
      295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
-     305,   306,   307,   308,   309
+     305,   306,   307,   308,   309,   310
 };
 # endif
 
-#define YYPACT_NINF -93
+#define YYPACT_NINF -56
 
-#define YYTABLE_NINF -103
+#define YYTABLE_NINF -105
 
   /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
      STATE-NUM.    */
 static const yytype_int16 yypact[] =
 {
-     -93,     9,   100,   -93,   -93,   -93,   -50,    21,    32,   -93,
-     -93,   -93,   -93,   -39,   -93,     1,    56,    73,    74,   -93,
-      10,   -93,    38,    79,    43,    27,   -93,   -93,   -93,    37,
-      44,    83,    84,    22,   -93,   -93,   -93,    26,   -93,   -93,
-      45,   -93,   -93,   -93,   -93,    40,   -37,   -37,    22,     0,
-       0,   -93,    47,   -93,   -93,   -93,    86,   -93,   -93,   -93,
-     -93,    89,   -93,   -93,   -93,   -93,    92,   -93,    94,   -93,
-     -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,    48,   -93,
-      50,    11,   -93,   -93,   -93,   -93,    47,   -93,    22,   -93,
-     -93,   -37,    66,   -37,    22,   -93,   -93,   -93,   -93,     0,
-     -93,   -93,     0,   -93,   -93,   -93,   -93,   -93,   -93,   -93,
-     -93,    58,   -93,   -93,   -93,   -93,    22,   -93,    98,   -93,
-     111,   -93,   -93,   -93,   -93,    18,   141,   -93,   -93,   -93,
-     -93,   -93,    22,    99,    64,   -93,   -93,   141,   -93,   -93,
-     -93
+     -56,    40,   102,   -56,   -56,   -56,    30,    19,    26,   -56,
+     -56,   -56,   -56,    -2,   -56,    13,    80,    84,    85,   -56,
+      29,   -56,    51,    90,    54,    32,   -56,   -56,   -56,    33,
+      55,    94,    96,     0,   -56,   -56,   -56,    16,   -56,   -56,
+      57,   -56,   -56,   -56,   -56,    52,    -1,    -1,     0,    27,
+      27,   -56,    59,   -56,   -56,   -56,   101,   -56,   -56,   -56,
+     -56,   113,   -56,   -56,   -56,   -56,   114,   -56,   115,   -56,
+     -56,   -56,   -56,   -56,   -56,   -56,   -56,   -56,    93,   -56,
+      95,     1,   -56,   -56,    92,   -56,    59,   -56,     0,   -56,
+     -56,    -1,    71,    -1,     0,   -56,   -56,   -56,   -56,    27,
+     -56,   -56,    27,   -56,   -56,   -56,   -56,   -56,   -56,   -56,
+     -56,    62,   -56,   -56,   -56,   -56,   -56,     0,   -56,   140,
+     -56,   144,   -56,   -56,   -56,   -56,   -56,   -56,   -56,   -56,
+       9,    49,   -56,   -56,     0,   146,    97,    92,    92,    49,
+     -56,   -56,   -56,   -56,   -56
 };
 
   /* YYDEFACT[S] -- default reduction number in state S.  Performed when
@@ -698,34 +704,34 @@ static const yytype_uint8 yydefact[] =
        0,    15,     0,     0,     0,     0,    38,    21,    22,     0,
        0,     0,     0,     0,    28,    29,    30,     0,     6,    31,
       41,     4,     5,    33,    32,    54,     0,     0,     0,     0,
-       0,    95,     0,    39,    92,    91,    93,    10,    11,    12,
+       0,    97,     0,    39,    94,    93,    95,    10,    11,    12,
       13,     0,    16,    17,    18,    19,     0,    23,     0,    25,
-      26,    27,   101,    97,    96,    99,    34,   100,     0,    98,
-       0,     0,    75,    77,    80,    42,     0,    55,     0,    68,
+      26,    27,   103,    99,    98,   101,    34,   102,     0,   100,
+       0,     0,    75,    77,    91,    42,     0,    55,     0,    68,
       73,    47,    69,    45,    48,    60,    65,    66,    67,    35,
-      62,    64,    36,    40,    94,     8,    14,    20,    24,    79,
-      78,     0,    76,     2,    85,    43,    49,    56,    58,    74,
-      70,    71,    61,    63,   103,    81,    82,    57,    59,    72,
-      85,    84,     0,     0,     0,    87,    86,    83,    88,    89,
-      90
+      62,    64,    36,    40,    96,     8,    14,    20,    24,    79,
+      78,     0,    76,     2,    92,    80,    43,    49,    56,    58,
+      74,    70,    71,    61,    63,   105,    85,    57,    59,    72,
+      81,    82,    85,    84,     0,     0,     0,    91,    91,    83,
+      88,    89,    90,    87,    86
 };
 
   /* YYPGOTO[NTERM-NUM].    */
-static const yytype_int8 yypgoto[] =
+static const yytype_int16 yypgoto[] =
 {
-     -93,   -93,   -93,   -93,   114,   -93,   -93,   -93,   -93,   -93,
-     -93,   -93,   -93,    25,   -93,    93,   -92,   -17,    95,   -93,
-      65,   -93,   -93,   -93,    15,   -93,   -93,   -26,     3,   -93,
-     -33,   -45,   -93
+     -56,   -56,   -56,   -56,   151,   -56,   -56,   -56,   -56,   -56,
+     -56,   -56,   -56,    37,   -56,   105,   -17,   -23,   109,   -56,
+      77,   -56,   -56,   -56,    28,   -51,   -56,   -56,   -32,   -42,
+     -56,   -33,   -55,   -56
 };
 
   /* YYDEFGOTO[NTERM-NUM].    */
-static const yytype_int8 yydefgoto[] =
+static const yytype_int16 yydefgoto[] =
 {
       -1,     1,     2,    41,    80,    86,    43,    47,    46,    44,
-      45,    88,   116,   117,    94,    99,   100,    90,    91,    81,
-      82,    83,   114,   125,   126,    56,   105,    53,    75,    84,
-     101,    77,   113
+      45,    88,   117,   118,    94,    99,   100,    90,    91,    81,
+      82,    83,   126,   130,   131,   115,    56,   105,    53,    75,
+      84,   101,    77,   113
 };
 
   /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
@@ -734,85 +740,81 @@ static const yytype_int8 yydefgoto[] =
      If YYTABLE_NINF, syntax error.    */
 static const yytype_int16 yytable[] =
 {
-      76,    48,    51,    72,    54,    73,    52,   123,    74,     3,
-     123,  -102,    78,    60,    89,    95,     4,     5,     6,     7,
-       8,     9,    10,    11,    12,    72,   103,    78,    13,    14,
-      65,     4,     5,     6,     7,     8,     9,    10,    11,    12,
-      67,    26,    73,    13,    14,    74,    55,   121,    33,    92,
-      92,    96,    97,    98,    61,   118,    26,    79,   111,    57,
-     115,   122,    49,    33,    73,    40,   130,    74,   131,    72,
-     120,    66,    79,    50,   119,   129,   119,    58,    59,    62,
-      40,    68,    63,   118,    64,    69,    70,    71,    51,   104,
-      85,    87,   106,   136,    92,   107,    92,   108,   109,   138,
-     110,   124,   128,   139,   136,     4,     5,     6,     7,     8,
-       9,    10,    11,    12,    72,   140,    42,    13,    14,    15,
-      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
-      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
-      36,   127,    93,   102,    72,   137,   112,    37,     0,    38,
-      39,     0,     0,     0,    40,   132,   133,   134,     0,     0,
-       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
-       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
-       0,     0,   135,    73,     0,     0,    74
+      76,  -104,    78,    72,    92,    92,     4,     5,     6,     7,
+       8,     9,    10,    11,    12,    95,    54,    78,    13,    14,
+     103,     4,     5,     6,     7,     8,     9,    10,    11,    12,
+      72,    26,    60,    13,    14,    65,    67,   122,    33,    51,
+       3,    73,    73,    52,    74,    74,    26,    79,   111,    92,
+      89,    92,    72,    33,   116,   119,    40,   132,    55,   133,
+      49,   123,    79,   134,   135,   136,   129,    50,   120,    73,
+     120,    40,    74,    61,    72,   121,    66,    68,    96,    97,
+      98,    48,   124,    57,   119,   124,   143,   144,    58,    59,
+     137,    73,    62,    63,    74,    64,    69,    70,   138,    71,
+      51,   140,    85,    87,   104,   125,   138,     4,     5,     6,
+       7,     8,     9,    10,    11,    12,   106,   107,   108,    13,
+      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
+      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
+      34,    35,    36,   109,   128,   110,   114,    72,   142,    37,
+     141,    38,    39,    42,   127,   102,    93,    40,   112,     0,
+     139
 };
 
 static const yytype_int16 yycheck[] =
 {
-      33,    51,    41,     3,     3,    42,    45,    99,    45,     0,
-     102,     0,     1,     3,    51,    48,     5,     6,     7,     8,
-       9,    10,    11,    12,    13,     3,    52,     1,    17,    18,
-       3,     5,     6,     7,     8,     9,    10,    11,    12,    13,
-       3,    30,    42,    17,    18,    45,    45,    92,    37,    46,
-      47,    51,    52,    53,    44,    88,    30,    46,    47,     3,
-      86,    94,    41,    37,    42,    54,    48,    45,    50,     3,
-       4,    44,    46,    41,    91,   120,    93,     4,     4,    41,
-      54,    44,     3,   116,    41,    41,     3,     3,    41,     3,
-      45,    51,     3,   126,    91,     3,    93,     3,    50,   132,
-      50,    43,     4,     4,   137,     5,     6,     7,     8,     9,
-      10,    11,    12,    13,     3,    51,     2,    17,    18,    19,
-      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
-      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
-      40,   116,    47,    50,     3,   130,    81,    47,    -1,    49,
-      50,    -1,    -1,    -1,    54,    14,    15,    16,    -1,    -1,
-      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
-      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
-      -1,    -1,    41,    42,    -1,    -1,    45
+      33,     0,     1,     3,    46,    47,     5,     6,     7,     8,
+       9,    10,    11,    12,    13,    48,     3,     1,    17,    18,
+      52,     5,     6,     7,     8,     9,    10,    11,    12,    13,
+       3,    30,     3,    17,    18,     3,     3,    92,    37,    41,
+       0,    42,    42,    45,    45,    45,    30,    46,    47,    91,
+      51,    93,     3,    37,    86,    88,    55,    48,    45,    50,
+      41,    94,    46,    14,    15,    16,   121,    41,    91,    42,
+      93,    55,    45,    44,     3,     4,    44,    44,    51,    52,
+      53,    51,    99,     3,   117,   102,   137,   138,     4,     4,
+      41,    42,    41,     3,    45,    41,    41,     3,   131,     3,
+      41,   134,    45,    51,     3,    43,   139,     5,     6,     7,
+       8,     9,    10,    11,    12,    13,     3,     3,     3,    17,
+      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
+      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
+      38,    39,    40,    50,     4,    50,    54,     3,    51,    47,
+       4,    49,    50,     2,   117,    50,    47,    55,    81,    -1,
+     132
 };
 
   /* STOS_[STATE-NUM] -- The (internal number of the) accessing
      symbol of state STATE-NUM.    */
 static const yytype_uint8 yystos[] =
 {
-       0,    56,    57,     0,     5,     6,     7,     8,     9,    10,
+       0,    57,    58,     0,     5,     6,     7,     8,     9,    10,
       11,    12,    13,    17,    18,    19,    20,    21,    22,    23,
       24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
       34,    35,    36,    37,    38,    39,    40,    47,    49,    50,
-      54,    58,    59,    61,    64,    65,    63,    62,    51,    41,
-      41,    41,    45,    82,     3,    45,    80,     3,     4,     4,
+      55,    59,    60,    62,    65,    66,    64,    63,    51,    41,
+      41,    41,    45,    84,     3,    45,    82,     3,     4,     4,
        3,    44,    41,     3,    41,     3,    44,     3,    44,    41,
-       3,     3,     3,    42,    45,    83,    85,    86,     1,    46,
-      59,    74,    75,    76,    84,    45,    60,    51,    66,    51,
-      72,    73,    83,    73,    69,    85,    51,    52,    53,    70,
-      71,    85,    70,    82,     3,    81,     3,     3,     3,    50,
-      50,    47,    75,    87,    77,    82,    67,    68,    85,    72,
-       4,    86,    85,    71,    43,    78,    79,    68,     4,    86,
-      48,    50,    14,    15,    16,    41,    85,    79,    85,     4,
-      51
+       3,     3,     3,    42,    45,    85,    87,    88,     1,    46,
+      60,    75,    76,    77,    86,    45,    61,    51,    67,    51,
+      73,    74,    85,    74,    70,    87,    51,    52,    53,    71,
+      72,    87,    71,    84,     3,    83,     3,     3,     3,    50,
+      50,    47,    76,    89,    54,    81,    84,    68,    69,    87,
+      73,     4,    88,    87,    72,    43,    78,    69,     4,    88,
+      79,    80,    48,    50,    14,    15,    16,    41,    87,    80,
+      87,     4,    51,    81,    81
 };
 
   /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.    */
 static const yytype_uint8 yyr1[] =
 {
-       0,    55,    56,    57,    57,    58,    58,    58,    58,    58,
-      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
-      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
-      58,    58,    59,    59,    59,    59,    59,    59,    59,    59,
-      59,    60,    60,    59,    62,    61,    63,    61,    61,    64,
-      65,    65,    65,    65,    66,    66,    67,    67,    68,    68,
-      69,    69,    70,    70,    71,    71,    71,    71,    72,    72,
-      72,    72,    72,    73,    73,    74,    74,    75,    75,    75,
-      77,    76,    78,    78,    78,    79,    79,    79,    79,    79,
-      79,    80,    80,    81,    81,    82,    83,    83,    84,    85,
-      85,    86,    87,    87
+       0,    56,    57,    58,    58,    59,    59,    59,    59,    59,
+      59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
+      59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
+      59,    59,    60,    60,    60,    60,    60,    60,    60,    60,
+      60,    61,    61,    60,    63,    62,    64,    62,    62,    65,
+      66,    66,    66,    66,    67,    67,    68,    68,    69,    69,
+      70,    70,    71,    71,    72,    72,    72,    72,    73,    73,
+      73,    73,    73,    74,    74,    75,    75,    76,    76,    76,
+      78,    77,    79,    79,    79,    80,    80,    80,    80,    80,
+      80,    81,    81,    82,    82,    83,    83,    84,    85,    85,
+      86,    87,    87,    88,    89,    89
 };
 
   /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.    */
@@ -826,9 +828,9 @@ static const yytype_uint8 yyr2[] =
        1,     1,     1,     1,     0,     1,     1,     2,     1,     2,
        1,     2,     1,     2,     1,     1,     1,     1,     1,     1,
        2,     2,     3,     1,     2,     1,     2,     1,     2,     2,
-       0,     3,     1,     3,     2,     0,     2,     2,     3,     3,
-       3,     1,     1,     0,     1,     1,     1,     1,     1,     1,
-       1,     1,     0,     2
+       0,     4,     1,     3,     2,     0,     3,     3,     3,     3,
+       3,     0,     1,     1,     1,     0,     1,     1,     1,     1,
+       1,     1,     1,     1,     0,     2
 };
 
 
@@ -980,154 +982,154 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
             case 3: // "string"
 
 /* Line 647 of yacc.c  */
-#line 178 "parse-gram.y"
+#line 182 "parse-gram.y"
         { fputs (quotearg_style (c_quoting_style, ((*yyvaluep).chars)), stderr); }
 /* Line 647 of yacc.c  */
-#line 987 "src/parse-gram.c"
+#line 989 "../bison/src/parse-gram.c"
         break;
 
             case 4: // "integer"
 
 /* Line 647 of yacc.c  */
-#line 190 "parse-gram.y"
+#line 195 "parse-gram.y"
         { fprintf (stderr, "%d", ((*yyvaluep).integer)); }
 /* Line 647 of yacc.c  */
-#line 996 "src/parse-gram.c"
+#line 998 "../bison/src/parse-gram.c"
         break;
 
             case 23: // "%<flag>"
 
 /* Line 647 of yacc.c  */
-#line 186 "parse-gram.y"
+#line 191 "parse-gram.y"
         { fprintf (stderr, "%%%s", ((*yyvaluep).uniqstr)); }
 /* Line 647 of yacc.c  */
-#line 1005 "src/parse-gram.c"
+#line 1007 "../bison/src/parse-gram.c"
         break;
 
             case 41: // "{...}"
 
 /* Line 647 of yacc.c  */
-#line 180 "parse-gram.y"
+#line 184 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).code)); }
 /* Line 647 of yacc.c  */
-#line 1014 "src/parse-gram.c"
+#line 1016 "../bison/src/parse-gram.c"
         break;
 
             case 42: // "char"
 
 /* Line 647 of yacc.c  */
-#line 172 "parse-gram.y"
+#line 176 "parse-gram.y"
         { fputs (char_name (((*yyvaluep).character)), stderr); }
 /* Line 647 of yacc.c  */
-#line 1023 "src/parse-gram.c"
+#line 1025 "../bison/src/parse-gram.c"
         break;
 
             case 43: // "epilogue"
 
 /* Line 647 of yacc.c  */
-#line 180 "parse-gram.y"
+#line 184 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); }
 /* Line 647 of yacc.c  */
-#line 1032 "src/parse-gram.c"
+#line 1034 "../bison/src/parse-gram.c"
         break;
 
             case 45: // "identifier"
 
 /* Line 647 of yacc.c  */
-#line 184 "parse-gram.y"
+#line 189 "parse-gram.y"
         { fputs (((*yyvaluep).uniqstr), stderr); }
 /* Line 647 of yacc.c  */
-#line 1041 "src/parse-gram.c"
+#line 1043 "../bison/src/parse-gram.c"
         break;
 
             case 46: // "identifier:"
 
 /* Line 647 of yacc.c  */
-#line 185 "parse-gram.y"
+#line 190 "parse-gram.y"
         { fprintf (stderr, "%s:", ((*yyvaluep).uniqstr)); }
 /* Line 647 of yacc.c  */
-#line 1050 "src/parse-gram.c"
+#line 1052 "../bison/src/parse-gram.c"
         break;
 
             case 49: // "%{...%}"
 
 /* Line 647 of yacc.c  */
-#line 180 "parse-gram.y"
+#line 184 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); }
 /* Line 647 of yacc.c  */
-#line 1059 "src/parse-gram.c"
+#line 1061 "../bison/src/parse-gram.c"
         break;
 
             case 51: // "<tag>"
 
 /* Line 647 of yacc.c  */
-#line 187 "parse-gram.y"
+#line 192 "parse-gram.y"
         { fprintf (stderr, "<%s>", ((*yyvaluep).uniqstr)); }
 /* Line 647 of yacc.c  */
-#line 1068 "src/parse-gram.c"
+#line 1070 "../bison/src/parse-gram.c"
         break;
 
-            case 80: // variable
+            case 82: // variable
 
 /* Line 647 of yacc.c  */
-#line 184 "parse-gram.y"
+#line 189 "parse-gram.y"
         { fputs (((*yyvaluep).uniqstr), stderr); }
 /* Line 647 of yacc.c  */
-#line 1077 "src/parse-gram.c"
+#line 1079 "../bison/src/parse-gram.c"
         break;
 
-            case 81: // content.opt
+            case 83: // content.opt
 
 /* Line 647 of yacc.c  */
-#line 180 "parse-gram.y"
+#line 184 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); }
 /* Line 647 of yacc.c  */
-#line 1086 "src/parse-gram.c"
+#line 1088 "../bison/src/parse-gram.c"
         break;
 
-            case 82: // braceless
+            case 84: // braceless
 
 /* Line 647 of yacc.c  */
-#line 180 "parse-gram.y"
+#line 184 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); }
 /* Line 647 of yacc.c  */
-#line 1095 "src/parse-gram.c"
+#line 1097 "../bison/src/parse-gram.c"
         break;
 
-            case 83: // id
+            case 85: // id
 
 /* Line 647 of yacc.c  */
-#line 193 "parse-gram.y"
+#line 198 "parse-gram.y"
         { fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); }
 /* Line 647 of yacc.c  */
-#line 1104 "src/parse-gram.c"
+#line 1106 "../bison/src/parse-gram.c"
         break;
 
-            case 84: // id_colon
+            case 86: // id_colon
 
 /* Line 647 of yacc.c  */
-#line 194 "parse-gram.y"
+#line 199 "parse-gram.y"
         { fprintf (stderr, "%s:", ((*yyvaluep).symbol)->tag); }
 /* Line 647 of yacc.c  */
-#line 1113 "src/parse-gram.c"
+#line 1115 "../bison/src/parse-gram.c"
         break;
 
-            case 85: // symbol
+            case 87: // symbol
 
 /* Line 647 of yacc.c  */
-#line 193 "parse-gram.y"
+#line 198 "parse-gram.y"
         { fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); }
 /* Line 647 of yacc.c  */
-#line 1122 "src/parse-gram.c"
+#line 1124 "../bison/src/parse-gram.c"
         break;
 
-            case 86: // string_as_id
+            case 88: // string_as_id
 
 /* Line 647 of yacc.c  */
-#line 193 "parse-gram.y"
+#line 198 "parse-gram.y"
         { fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); }
 /* Line 647 of yacc.c  */
-#line 1131 "src/parse-gram.c"
+#line 1133 "../bison/src/parse-gram.c"
         break;
 
       default:
@@ -1640,16 +1642,16 @@ YYLTYPE yylloc;
 #endif
 
 /* User initialization code.  */
-/* Line 1173 of yacc.c  */
-#line 84 "parse-gram.y"
+/* Line 1167 of yacc.c  */
+#line 86 "parse-gram.y"
 {
   /* Bison's grammar can initial empty locations, hence a default
      location is needed. */
   boundary_set (&yylloc.start, current_file, 1, 1);
   boundary_set (&yylloc.end, current_file, 1, 1);
 }
-/* Line 1173 of yacc.c  */
-#line 1653 "src/parse-gram.c"
+/* Line 1167 of yacc.c  */
+#line 1655 "../bison/src/parse-gram.c"
   yylsp[0] = yylloc;
 
   goto yysetstate;
@@ -1836,7 +1838,7 @@ yyreduce:
     {
         case 6:
 /* Line 1380 of yacc.c  */
-#line 217 "parse-gram.y"
+#line 222 "parse-gram.y"
     {
       code_props plain_code;
       code_props_plain_init (&plain_code, (yyvsp[0].chars), (yylsp[0]));
@@ -1847,95 +1849,95 @@ yyreduce:
       code_scanner_last_string_free ();
     }
 /* Line 1380 of yacc.c  */
-#line 1851 "src/parse-gram.c"
+#line 1853 "../bison/src/parse-gram.c"
     break;
 
   case 7:
 /* Line 1380 of yacc.c  */
-#line 227 "parse-gram.y"
+#line 232 "parse-gram.y"
     {
       muscle_percent_define_ensure ((yyvsp[0].uniqstr), (yylsp[0]), true);
     }
 /* Line 1380 of yacc.c  */
-#line 1861 "src/parse-gram.c"
+#line 1863 "../bison/src/parse-gram.c"
     break;
 
   case 8:
 /* Line 1380 of yacc.c  */
-#line 231 "parse-gram.y"
+#line 236 "parse-gram.y"
     {
       muscle_percent_define_insert ((yyvsp[-1].uniqstr), (yylsp[-1]), (yyvsp[0].chars),
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
     }
 /* Line 1380 of yacc.c  */
-#line 1872 "src/parse-gram.c"
+#line 1874 "../bison/src/parse-gram.c"
     break;
 
   case 9:
 /* Line 1380 of yacc.c  */
-#line 235 "parse-gram.y"
+#line 240 "parse-gram.y"
     { defines_flag = true; }
 /* Line 1380 of yacc.c  */
-#line 1880 "src/parse-gram.c"
+#line 1882 "../bison/src/parse-gram.c"
     break;
 
   case 10:
 /* Line 1380 of yacc.c  */
-#line 237 "parse-gram.y"
+#line 242 "parse-gram.y"
     {
       defines_flag = true;
       spec_defines_file = xstrdup ((yyvsp[0].chars));
     }
 /* Line 1380 of yacc.c  */
-#line 1891 "src/parse-gram.c"
+#line 1893 "../bison/src/parse-gram.c"
     break;
 
   case 11:
 /* Line 1380 of yacc.c  */
-#line 241 "parse-gram.y"
+#line 246 "parse-gram.y"
     { expected_sr_conflicts = (yyvsp[0].integer); }
 /* Line 1380 of yacc.c  */
-#line 1899 "src/parse-gram.c"
+#line 1901 "../bison/src/parse-gram.c"
     break;
 
   case 12:
 /* Line 1380 of yacc.c  */
-#line 242 "parse-gram.y"
+#line 247 "parse-gram.y"
     { expected_rr_conflicts = (yyvsp[0].integer); }
 /* Line 1380 of yacc.c  */
-#line 1907 "src/parse-gram.c"
+#line 1909 "../bison/src/parse-gram.c"
     break;
 
   case 13:
 /* Line 1380 of yacc.c  */
-#line 243 "parse-gram.y"
+#line 248 "parse-gram.y"
     { spec_file_prefix = (yyvsp[0].chars); }
 /* Line 1380 of yacc.c  */
-#line 1915 "src/parse-gram.c"
+#line 1917 "../bison/src/parse-gram.c"
     break;
 
   case 14:
 /* Line 1380 of yacc.c  */
-#line 244 "parse-gram.y"
+#line 249 "parse-gram.y"
     { spec_file_prefix = (yyvsp[0].chars); }
 /* Line 1380 of yacc.c  */
-#line 1923 "src/parse-gram.c"
+#line 1925 "../bison/src/parse-gram.c"
     break;
 
   case 15:
 /* Line 1380 of yacc.c  */
-#line 246 "parse-gram.y"
+#line 251 "parse-gram.y"
     {
       nondeterministic_parser = true;
       glr_parser = true;
     }
 /* Line 1380 of yacc.c  */
-#line 1934 "src/parse-gram.c"
+#line 1936 "../bison/src/parse-gram.c"
     break;
 
   case 16:
 /* Line 1380 of yacc.c  */
-#line 251 "parse-gram.y"
+#line 256 "parse-gram.y"
     {
       code_props action;
       code_props_symbol_action_init (&action, (yyvsp[0].code), (yylsp[0]));
@@ -1945,92 +1947,92 @@ yyreduce:
       code_scanner_last_string_free ();
     }
 /* Line 1380 of yacc.c  */
-#line 1949 "src/parse-gram.c"
+#line 1951 "../bison/src/parse-gram.c"
     break;
 
   case 17:
 /* Line 1380 of yacc.c  */
-#line 259 "parse-gram.y"
+#line 264 "parse-gram.y"
     { language_argmatch ((yyvsp[0].chars), grammar_prio, (yylsp[-1])); }
 /* Line 1380 of yacc.c  */
-#line 1957 "src/parse-gram.c"
+#line 1959 "../bison/src/parse-gram.c"
     break;
 
   case 18:
 /* Line 1380 of yacc.c  */
-#line 260 "parse-gram.y"
+#line 265 "parse-gram.y"
     { add_param ("lex_param", (yyvsp[0].code), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 1965 "src/parse-gram.c"
+#line 1967 "../bison/src/parse-gram.c"
     break;
 
   case 19:
 /* Line 1380 of yacc.c  */
-#line 261 "parse-gram.y"
+#line 266 "parse-gram.y"
     { spec_name_prefix = (yyvsp[0].chars); }
 /* Line 1380 of yacc.c  */
-#line 1973 "src/parse-gram.c"
+#line 1975 "../bison/src/parse-gram.c"
     break;
 
   case 20:
 /* Line 1380 of yacc.c  */
-#line 262 "parse-gram.y"
+#line 267 "parse-gram.y"
     { spec_name_prefix = (yyvsp[0].chars); }
 /* Line 1380 of yacc.c  */
-#line 1981 "src/parse-gram.c"
+#line 1983 "../bison/src/parse-gram.c"
     break;
 
   case 21:
 /* Line 1380 of yacc.c  */
-#line 263 "parse-gram.y"
+#line 268 "parse-gram.y"
     { no_lines_flag = true; }
 /* Line 1380 of yacc.c  */
-#line 1989 "src/parse-gram.c"
+#line 1991 "../bison/src/parse-gram.c"
     break;
 
   case 22:
 /* Line 1380 of yacc.c  */
-#line 264 "parse-gram.y"
+#line 269 "parse-gram.y"
     { nondeterministic_parser = true; }
 /* Line 1380 of yacc.c  */
-#line 1997 "src/parse-gram.c"
+#line 1999 "../bison/src/parse-gram.c"
     break;
 
   case 23:
 /* Line 1380 of yacc.c  */
-#line 265 "parse-gram.y"
+#line 270 "parse-gram.y"
     { spec_outfile = (yyvsp[0].chars); }
 /* Line 1380 of yacc.c  */
-#line 2005 "src/parse-gram.c"
+#line 2007 "../bison/src/parse-gram.c"
     break;
 
   case 24:
 /* Line 1380 of yacc.c  */
-#line 266 "parse-gram.y"
+#line 271 "parse-gram.y"
     { spec_outfile = (yyvsp[0].chars); }
 /* Line 1380 of yacc.c  */
-#line 2013 "src/parse-gram.c"
+#line 2015 "../bison/src/parse-gram.c"
     break;
 
   case 25:
 /* Line 1380 of yacc.c  */
-#line 267 "parse-gram.y"
+#line 272 "parse-gram.y"
     { add_param ("parse_param", (yyvsp[0].code), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2021 "src/parse-gram.c"
+#line 2023 "../bison/src/parse-gram.c"
     break;
 
   case 26:
 /* Line 1380 of yacc.c  */
-#line 268 "parse-gram.y"
+#line 273 "parse-gram.y"
     { version_check (&(yylsp[0]), (yyvsp[0].chars)); }
 /* Line 1380 of yacc.c  */
-#line 2029 "src/parse-gram.c"
+#line 2031 "../bison/src/parse-gram.c"
     break;
 
   case 27:
 /* Line 1380 of yacc.c  */
-#line 270 "parse-gram.y"
+#line 275 "parse-gram.y"
     {
       char const *skeleton_user = (yyvsp[0].chars);
       if (strchr (skeleton_user, '/'))
@@ -2055,46 +2057,46 @@ yyreduce:
       skeleton_arg (skeleton_user, grammar_prio, (yylsp[-1]));
     }
 /* Line 1380 of yacc.c  */
-#line 2059 "src/parse-gram.c"
+#line 2061 "../bison/src/parse-gram.c"
     break;
 
   case 28:
 /* Line 1380 of yacc.c  */
-#line 293 "parse-gram.y"
+#line 298 "parse-gram.y"
     { token_table_flag = true; }
 /* Line 1380 of yacc.c  */
-#line 2067 "src/parse-gram.c"
+#line 2069 "../bison/src/parse-gram.c"
     break;
 
   case 29:
 /* Line 1380 of yacc.c  */
-#line 294 "parse-gram.y"
+#line 299 "parse-gram.y"
     { report_flag |= report_states; }
 /* Line 1380 of yacc.c  */
-#line 2075 "src/parse-gram.c"
+#line 2077 "../bison/src/parse-gram.c"
     break;
 
   case 30:
 /* Line 1380 of yacc.c  */
-#line 295 "parse-gram.y"
+#line 300 "parse-gram.y"
     { yacc_flag = true; }
 /* Line 1380 of yacc.c  */
-#line 2083 "src/parse-gram.c"
+#line 2085 "../bison/src/parse-gram.c"
     break;
 
   case 34:
 /* Line 1380 of yacc.c  */
-#line 303 "parse-gram.y"
+#line 308 "parse-gram.y"
     {
       grammar_start_symbol_set ((yyvsp[0].symbol), (yylsp[0]));
     }
 /* Line 1380 of yacc.c  */
-#line 2093 "src/parse-gram.c"
+#line 2095 "../bison/src/parse-gram.c"
     break;
 
   case 35:
 /* Line 1380 of yacc.c  */
-#line 307 "parse-gram.y"
+#line 312 "parse-gram.y"
     {
       symbol_list *list;
       for (list = (yyvsp[0].list); list; list = list->next)
@@ -2102,12 +2104,12 @@ yyreduce:
       symbol_list_free ((yyvsp[0].list));
     }
 /* Line 1380 of yacc.c  */
-#line 2106 "src/parse-gram.c"
+#line 2108 "../bison/src/parse-gram.c"
     break;
 
   case 36:
 /* Line 1380 of yacc.c  */
-#line 314 "parse-gram.y"
+#line 319 "parse-gram.y"
     {
       symbol_list *list;
       for (list = (yyvsp[0].list); list; list = list->next)
@@ -2115,32 +2117,32 @@ yyreduce:
       symbol_list_free ((yyvsp[0].list));
     }
 /* Line 1380 of yacc.c  */
-#line 2119 "src/parse-gram.c"
+#line 2121 "../bison/src/parse-gram.c"
     break;
 
   case 37:
 /* Line 1380 of yacc.c  */
-#line 321 "parse-gram.y"
+#line 326 "parse-gram.y"
     {
       default_prec = true;
     }
 /* Line 1380 of yacc.c  */
-#line 2129 "src/parse-gram.c"
+#line 2131 "../bison/src/parse-gram.c"
     break;
 
   case 38:
 /* Line 1380 of yacc.c  */
-#line 325 "parse-gram.y"
+#line 330 "parse-gram.y"
     {
       default_prec = false;
     }
 /* Line 1380 of yacc.c  */
-#line 2139 "src/parse-gram.c"
+#line 2141 "../bison/src/parse-gram.c"
     break;
 
   case 39:
 /* Line 1380 of yacc.c  */
-#line 329 "parse-gram.y"
+#line 334 "parse-gram.y"
     {
       /* Do not invoke muscle_percent_code_grow here since it invokes
          muscle_user_name_list_grow.  */
@@ -2148,89 +2150,89 @@ yyreduce:
       code_scanner_last_string_free ();
     }
 /* Line 1380 of yacc.c  */
-#line 2152 "src/parse-gram.c"
+#line 2154 "../bison/src/parse-gram.c"
     break;
 
   case 40:
 /* Line 1380 of yacc.c  */
-#line 336 "parse-gram.y"
+#line 341 "parse-gram.y"
     {
       muscle_percent_code_grow ((yyvsp[-1].uniqstr), (yylsp[-1]), (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
 /* Line 1380 of yacc.c  */
-#line 2163 "src/parse-gram.c"
+#line 2165 "../bison/src/parse-gram.c"
     break;
 
   case 41:
 /* Line 1380 of yacc.c  */
-#line 350 "parse-gram.y"
+#line 355 "parse-gram.y"
     {}
 /* Line 1380 of yacc.c  */
-#line 2171 "src/parse-gram.c"
+#line 2173 "../bison/src/parse-gram.c"
     break;
 
   case 42:
 /* Line 1380 of yacc.c  */
-#line 351 "parse-gram.y"
+#line 356 "parse-gram.y"
     { muscle_code_grow ("union_name", (yyvsp[0].uniqstr), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2179 "src/parse-gram.c"
+#line 2181 "../bison/src/parse-gram.c"
     break;
 
   case 43:
 /* Line 1380 of yacc.c  */
-#line 356 "parse-gram.y"
+#line 361 "parse-gram.y"
     {
       union_seen = true;
       muscle_code_grow ("stype", (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
 /* Line 1380 of yacc.c  */
-#line 2191 "src/parse-gram.c"
+#line 2193 "../bison/src/parse-gram.c"
     break;
 
   case 44:
 /* Line 1380 of yacc.c  */
-#line 367 "parse-gram.y"
+#line 372 "parse-gram.y"
     { current_class = nterm_sym; }
 /* Line 1380 of yacc.c  */
-#line 2199 "src/parse-gram.c"
+#line 2201 "../bison/src/parse-gram.c"
     break;
 
   case 45:
 /* Line 1380 of yacc.c  */
-#line 368 "parse-gram.y"
+#line 373 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
 /* Line 1380 of yacc.c  */
-#line 2210 "src/parse-gram.c"
+#line 2212 "../bison/src/parse-gram.c"
     break;
 
   case 46:
 /* Line 1380 of yacc.c  */
-#line 372 "parse-gram.y"
+#line 377 "parse-gram.y"
     { current_class = token_sym; }
 /* Line 1380 of yacc.c  */
-#line 2218 "src/parse-gram.c"
+#line 2220 "../bison/src/parse-gram.c"
     break;
 
   case 47:
 /* Line 1380 of yacc.c  */
-#line 373 "parse-gram.y"
+#line 378 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
 /* Line 1380 of yacc.c  */
-#line 2229 "src/parse-gram.c"
+#line 2231 "../bison/src/parse-gram.c"
     break;
 
   case 48:
 /* Line 1380 of yacc.c  */
-#line 378 "parse-gram.y"
+#line 383 "parse-gram.y"
     {
       symbol_list *list;
       tag_seen = true;
@@ -2239,12 +2241,12 @@ yyreduce:
       symbol_list_free ((yyvsp[0].list));
     }
 /* Line 1380 of yacc.c  */
-#line 2243 "src/parse-gram.c"
+#line 2245 "../bison/src/parse-gram.c"
     break;
 
   case 49:
 /* Line 1380 of yacc.c  */
-#line 389 "parse-gram.y"
+#line 394 "parse-gram.y"
     {
       symbol_list *list;
       ++current_prec;
@@ -2257,202 +2259,202 @@ yyreduce:
       current_type = NULL;
     }
 /* Line 1380 of yacc.c  */
-#line 2261 "src/parse-gram.c"
+#line 2263 "../bison/src/parse-gram.c"
     break;
 
   case 50:
 /* Line 1380 of yacc.c  */
-#line 403 "parse-gram.y"
+#line 408 "parse-gram.y"
     { (yyval.assoc) = left_assoc; }
 /* Line 1380 of yacc.c  */
-#line 2269 "src/parse-gram.c"
+#line 2271 "../bison/src/parse-gram.c"
     break;
 
   case 51:
 /* Line 1380 of yacc.c  */
-#line 404 "parse-gram.y"
+#line 409 "parse-gram.y"
     { (yyval.assoc) = right_assoc; }
 /* Line 1380 of yacc.c  */
-#line 2277 "src/parse-gram.c"
+#line 2279 "../bison/src/parse-gram.c"
     break;
 
   case 52:
 /* Line 1380 of yacc.c  */
-#line 405 "parse-gram.y"
+#line 410 "parse-gram.y"
     { (yyval.assoc) = non_assoc; }
 /* Line 1380 of yacc.c  */
-#line 2285 "src/parse-gram.c"
+#line 2287 "../bison/src/parse-gram.c"
     break;
 
   case 53:
 /* Line 1380 of yacc.c  */
-#line 406 "parse-gram.y"
+#line 411 "parse-gram.y"
     { (yyval.assoc) = precedence_assoc; }
 /* Line 1380 of yacc.c  */
-#line 2293 "src/parse-gram.c"
+#line 2295 "../bison/src/parse-gram.c"
     break;
 
   case 54:
 /* Line 1380 of yacc.c  */
-#line 410 "parse-gram.y"
+#line 415 "parse-gram.y"
     { current_type = NULL; }
 /* Line 1380 of yacc.c  */
-#line 2301 "src/parse-gram.c"
+#line 2303 "../bison/src/parse-gram.c"
     break;
 
   case 55:
 /* Line 1380 of yacc.c  */
-#line 411 "parse-gram.y"
+#line 416 "parse-gram.y"
     { current_type = (yyvsp[0].uniqstr); tag_seen = true; }
 /* Line 1380 of yacc.c  */
-#line 2309 "src/parse-gram.c"
+#line 2311 "../bison/src/parse-gram.c"
     break;
 
   case 56:
 /* Line 1380 of yacc.c  */
-#line 417 "parse-gram.y"
+#line 422 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2317 "src/parse-gram.c"
+#line 2319 "../bison/src/parse-gram.c"
     break;
 
   case 57:
 /* Line 1380 of yacc.c  */
-#line 419 "parse-gram.y"
+#line 424 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
 /* Line 1380 of yacc.c  */
-#line 2325 "src/parse-gram.c"
+#line 2327 "../bison/src/parse-gram.c"
     break;
 
   case 58:
 /* Line 1380 of yacc.c  */
-#line 423 "parse-gram.y"
+#line 428 "parse-gram.y"
     { (yyval.symbol) = (yyvsp[0].symbol); }
 /* Line 1380 of yacc.c  */
-#line 2333 "src/parse-gram.c"
+#line 2335 "../bison/src/parse-gram.c"
     break;
 
   case 59:
 /* Line 1380 of yacc.c  */
-#line 424 "parse-gram.y"
+#line 429 "parse-gram.y"
     { (yyval.symbol) = (yyvsp[-1].symbol); symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2341 "src/parse-gram.c"
+#line 2343 "../bison/src/parse-gram.c"
     break;
 
   case 60:
 /* Line 1380 of yacc.c  */
-#line 430 "parse-gram.y"
+#line 435 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2349 "src/parse-gram.c"
+#line 2351 "../bison/src/parse-gram.c"
     break;
 
   case 61:
 /* Line 1380 of yacc.c  */
-#line 432 "parse-gram.y"
+#line 437 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
 /* Line 1380 of yacc.c  */
-#line 2357 "src/parse-gram.c"
+#line 2359 "../bison/src/parse-gram.c"
     break;
 
   case 62:
 /* Line 1380 of yacc.c  */
-#line 436 "parse-gram.y"
+#line 441 "parse-gram.y"
     { (yyval.list) = (yyvsp[0].list); }
 /* Line 1380 of yacc.c  */
-#line 2365 "src/parse-gram.c"
+#line 2367 "../bison/src/parse-gram.c"
     break;
 
   case 63:
 /* Line 1380 of yacc.c  */
-#line 437 "parse-gram.y"
+#line 442 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), (yyvsp[0].list)); }
 /* Line 1380 of yacc.c  */
-#line 2373 "src/parse-gram.c"
+#line 2375 "../bison/src/parse-gram.c"
     break;
 
   case 64:
 /* Line 1380 of yacc.c  */
-#line 441 "parse-gram.y"
+#line 446 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2381 "src/parse-gram.c"
+#line 2383 "../bison/src/parse-gram.c"
     break;
 
   case 65:
 /* Line 1380 of yacc.c  */
-#line 442 "parse-gram.y"
+#line 447 "parse-gram.y"
     { (yyval.list) = symbol_list_type_new ((yyvsp[0].uniqstr), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2389 "src/parse-gram.c"
+#line 2391 "../bison/src/parse-gram.c"
     break;
 
   case 66:
 /* Line 1380 of yacc.c  */
-#line 443 "parse-gram.y"
+#line 448 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagged_new ((yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2397 "src/parse-gram.c"
+#line 2399 "../bison/src/parse-gram.c"
     break;
 
   case 67:
 /* Line 1380 of yacc.c  */
-#line 444 "parse-gram.y"
+#line 449 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagless_new ((yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2405 "src/parse-gram.c"
+#line 2407 "../bison/src/parse-gram.c"
     break;
 
   case 68:
 /* Line 1380 of yacc.c  */
-#line 450 "parse-gram.y"
+#line 455 "parse-gram.y"
     {
        current_type = (yyvsp[0].uniqstr);
        tag_seen = true;
      }
 /* Line 1380 of yacc.c  */
-#line 2416 "src/parse-gram.c"
+#line 2418 "../bison/src/parse-gram.c"
     break;
 
   case 69:
 /* Line 1380 of yacc.c  */
-#line 455 "parse-gram.y"
+#line 460 "parse-gram.y"
     {
        symbol_class_set ((yyvsp[0].symbol), current_class, (yylsp[0]), true);
        symbol_type_set ((yyvsp[0].symbol), current_type, (yylsp[0]));
      }
 /* Line 1380 of yacc.c  */
-#line 2427 "src/parse-gram.c"
+#line 2429 "../bison/src/parse-gram.c"
     break;
 
   case 70:
 /* Line 1380 of yacc.c  */
-#line 460 "parse-gram.y"
+#line 465 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[-1].symbol), current_class, (yylsp[-1]), true);
       symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
       symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0]));
     }
 /* Line 1380 of yacc.c  */
-#line 2439 "src/parse-gram.c"
+#line 2441 "../bison/src/parse-gram.c"
     break;
 
   case 71:
 /* Line 1380 of yacc.c  */
-#line 466 "parse-gram.y"
+#line 471 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[-1].symbol), current_class, (yylsp[-1]), true);
       symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
       symbol_make_alias ((yyvsp[-1].symbol), (yyvsp[0].symbol), (yyloc));
     }
 /* Line 1380 of yacc.c  */
-#line 2451 "src/parse-gram.c"
+#line 2453 "../bison/src/parse-gram.c"
     break;
 
   case 72:
 /* Line 1380 of yacc.c  */
-#line 472 "parse-gram.y"
+#line 477 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[-2].symbol), current_class, (yylsp[-2]), true);
       symbol_type_set ((yyvsp[-2].symbol), current_type, (yylsp[-2]));
@@ -2460,110 +2462,128 @@ yyreduce:
       symbol_make_alias ((yyvsp[-2].symbol), (yyvsp[0].symbol), (yyloc));
     }
 /* Line 1380 of yacc.c  */
-#line 2464 "src/parse-gram.c"
+#line 2466 "../bison/src/parse-gram.c"
     break;
 
   case 79:
 /* Line 1380 of yacc.c  */
-#line 502 "parse-gram.y"
+#line 507 "parse-gram.y"
     {
       yyerrok;
     }
 /* Line 1380 of yacc.c  */
-#line 2474 "src/parse-gram.c"
+#line 2476 "../bison/src/parse-gram.c"
     break;
 
   case 80:
 /* Line 1380 of yacc.c  */
-#line 508 "parse-gram.y"
-    { current_lhs = (yyvsp[0].symbol); current_lhs_location = (yylsp[0]); }
+#line 513 "parse-gram.y"
+    { current_lhs = (yyvsp[-1].symbol); current_lhs_location = (yylsp[-1]);
+    current_lhs_named_ref = (yyvsp[0].named_ref); }
 /* Line 1380 of yacc.c  */
-#line 2482 "src/parse-gram.c"
+#line 2485 "../bison/src/parse-gram.c"
     break;
 
   case 82:
 /* Line 1380 of yacc.c  */
-#line 512 "parse-gram.y"
+#line 518 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2490 "src/parse-gram.c"
+#line 2493 "../bison/src/parse-gram.c"
     break;
 
   case 83:
 /* Line 1380 of yacc.c  */
-#line 513 "parse-gram.y"
+#line 519 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2498 "src/parse-gram.c"
+#line 2501 "../bison/src/parse-gram.c"
     break;
 
   case 85:
 /* Line 1380 of yacc.c  */
-#line 519 "parse-gram.y"
-    { grammar_current_rule_begin (current_lhs, current_lhs_location); }
+#line 525 "parse-gram.y"
+    { grammar_current_rule_begin (current_lhs, current_lhs_location,
+				  current_lhs_named_ref); }
 /* Line 1380 of yacc.c  */
-#line 2506 "src/parse-gram.c"
+#line 2510 "../bison/src/parse-gram.c"
     break;
 
   case 86:
 /* Line 1380 of yacc.c  */
-#line 521 "parse-gram.y"
-    { grammar_current_rule_symbol_append ((yyvsp[0].symbol), (yylsp[0])); }
+#line 528 "parse-gram.y"
+    { grammar_current_rule_symbol_append ((yyvsp[-1].symbol), (yylsp[-1]), (yyvsp[0].named_ref)); }
 /* Line 1380 of yacc.c  */
-#line 2514 "src/parse-gram.c"
+#line 2518 "../bison/src/parse-gram.c"
     break;
 
   case 87:
 /* Line 1380 of yacc.c  */
-#line 523 "parse-gram.y"
-    { grammar_current_rule_action_append ((yyvsp[0].code), (yylsp[0])); }
+#line 530 "parse-gram.y"
+    { grammar_current_rule_action_append ((yyvsp[-1].code), (yylsp[-1]), (yyvsp[0].named_ref)); }
 /* Line 1380 of yacc.c  */
-#line 2522 "src/parse-gram.c"
+#line 2526 "../bison/src/parse-gram.c"
     break;
 
   case 88:
 /* Line 1380 of yacc.c  */
-#line 525 "parse-gram.y"
+#line 532 "parse-gram.y"
     { grammar_current_rule_prec_set ((yyvsp[0].symbol), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2530 "src/parse-gram.c"
+#line 2534 "../bison/src/parse-gram.c"
     break;
 
   case 89:
 /* Line 1380 of yacc.c  */
-#line 527 "parse-gram.y"
+#line 534 "parse-gram.y"
     { grammar_current_rule_dprec_set ((yyvsp[0].integer), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2538 "src/parse-gram.c"
+#line 2542 "../bison/src/parse-gram.c"
     break;
 
   case 90:
 /* Line 1380 of yacc.c  */
-#line 529 "parse-gram.y"
+#line 536 "parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[0].uniqstr), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2546 "src/parse-gram.c"
+#line 2550 "../bison/src/parse-gram.c"
     break;
 
-  case 92:
+  case 91:
 /* Line 1380 of yacc.c  */
 #line 541 "parse-gram.y"
+    { (yyval.named_ref) = 0; }
+/* Line 1380 of yacc.c  */
+#line 2558 "../bison/src/parse-gram.c"
+    break;
+
+  case 92:
+/* Line 1380 of yacc.c  */
+#line 544 "parse-gram.y"
+    { (yyval.named_ref) = named_ref_new((yyvsp[0].uniqstr), (yylsp[0])); }
+/* Line 1380 of yacc.c  */
+#line 2566 "../bison/src/parse-gram.c"
+    break;
+
+  case 94:
+/* Line 1380 of yacc.c  */
+#line 556 "parse-gram.y"
     { (yyval.uniqstr) = uniqstr_new ((yyvsp[0].chars)); }
 /* Line 1380 of yacc.c  */
-#line 2554 "src/parse-gram.c"
+#line 2574 "../bison/src/parse-gram.c"
     break;
 
-  case 93:
+  case 95:
 /* Line 1380 of yacc.c  */
-#line 546 "parse-gram.y"
+#line 561 "parse-gram.y"
     { (yyval.chars) = ""; }
 /* Line 1380 of yacc.c  */
-#line 2562 "src/parse-gram.c"
+#line 2582 "../bison/src/parse-gram.c"
     break;
 
-  case 95:
+  case 97:
 /* Line 1380 of yacc.c  */
-#line 557 "parse-gram.y"
+#line 572 "parse-gram.y"
     {
       code_props plain_code;
       (yyvsp[0].code)[strlen ((yyvsp[0].code)) - 1] = '\n';
@@ -2573,51 +2593,51 @@ yyreduce:
       (yyval.chars) = plain_code.code;
     }
 /* Line 1380 of yacc.c  */
-#line 2577 "src/parse-gram.c"
+#line 2597 "../bison/src/parse-gram.c"
     break;
 
-  case 96:
+  case 98:
 /* Line 1380 of yacc.c  */
-#line 577 "parse-gram.y"
+#line 592 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2585 "src/parse-gram.c"
+#line 2605 "../bison/src/parse-gram.c"
     break;
 
-  case 97:
+  case 99:
 /* Line 1380 of yacc.c  */
-#line 579 "parse-gram.y"
+#line 594 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[0].character)), (yylsp[0]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
       symbol_user_token_number_set ((yyval.symbol), (yyvsp[0].character), (yylsp[0]));
     }
 /* Line 1380 of yacc.c  */
-#line 2597 "src/parse-gram.c"
+#line 2617 "../bison/src/parse-gram.c"
     break;
 
-  case 98:
+  case 100:
 /* Line 1380 of yacc.c  */
-#line 587 "parse-gram.y"
+#line 602 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2605 "src/parse-gram.c"
+#line 2625 "../bison/src/parse-gram.c"
     break;
 
-  case 101:
+  case 103:
 /* Line 1380 of yacc.c  */
-#line 599 "parse-gram.y"
+#line 614 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[0].chars)), (yylsp[0]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
     }
 /* Line 1380 of yacc.c  */
-#line 2616 "src/parse-gram.c"
+#line 2636 "../bison/src/parse-gram.c"
     break;
 
-  case 103:
+  case 105:
 /* Line 1380 of yacc.c  */
-#line 608 "parse-gram.y"
+#line 623 "parse-gram.y"
     {
       code_props plain_code;
       code_props_plain_init (&plain_code, (yyvsp[0].chars), (yylsp[0]));
@@ -2627,12 +2647,12 @@ yyreduce:
       code_scanner_last_string_free ();
     }
 /* Line 1380 of yacc.c  */
-#line 2631 "src/parse-gram.c"
+#line 2651 "../bison/src/parse-gram.c"
     break;
 
 
 /* Line 1380 of yacc.c  */
-#line 2636 "src/parse-gram.c"
+#line 2656 "../bison/src/parse-gram.c"
       default: break;
     }
   YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);
@@ -2849,7 +2869,7 @@ yyreturn:
 }
 
 /* Line 1599 of yacc.c  */
-#line 618 "parse-gram.y"
+#line 633 "parse-gram.y"
 
 
 
