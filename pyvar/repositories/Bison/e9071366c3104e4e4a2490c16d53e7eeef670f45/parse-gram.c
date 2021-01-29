@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 2.2a.  */
+/* A Bison parser, made by GNU Bison 2.1b.  */
 
 /* Skeleton implementation for Bison's Yacc-like parsers in C
 
@@ -47,7 +47,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "2.2a"
+#define YYBISON_VERSION "2.1b"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -182,7 +182,7 @@
 
 
 /* Copy the first part of user declarations.  */
-#line 1 "parse-gram.y"
+#line 1 "../../src/parse-gram.y"
 /* Bison Grammar Parser                             -*- C -*-
 
    Copyright (C) 2002, 2003, 2004, 2005, 2006 Free Software Foundation, Inc.
@@ -217,6 +217,8 @@
 #include "quotearg.h"
 #include "reader.h"
 #include "symlist.h"
+#include "scan-gram.h"
+#include "scan-code.h"
 #include "strverscmp.h"
 
 #define YYLLOC_DEFAULT(Current, Rhs, N)  (Current) = lloc_default (Rhs, N)
@@ -276,7 +278,7 @@ static int current_prec = 0;
 
 #if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
 typedef union YYSTYPE
-#line 94 "parse-gram.y"
+#line 95 "../../src/parse-gram.y"
 {
   symbol *symbol;
   symbol_list *list;
@@ -286,7 +288,7 @@ typedef union YYSTYPE
   uniqstr uniqstr;
 }
 /* Line 193 of yacc.c.  */
-#line 290 "parse-gram.c"
+#line 292 "../../src/parse-gram.c"
 	YYSTYPE;
 # define yystype YYSTYPE /* obsolescent; will be withdrawn */
 # define YYSTYPE_IS_DECLARED 1
@@ -311,7 +313,7 @@ typedef struct YYLTYPE
 
 
 /* Line 216 of yacc.c.  */
-#line 315 "parse-gram.c"
+#line 317 "../../src/parse-gram.c"
 
 #ifdef short
 # undef short
@@ -528,16 +530,16 @@ union yyalloc
 /* YYFINAL -- State number of the termination state.  */
 #define YYFINAL  3
 /* YYLAST -- Last index in YYTABLE.  */
-#define YYLAST   161
+#define YYLAST   164
 
 /* YYNTOKENS -- Number of terminals.  */
 #define YYNTOKENS  52
 /* YYNNTS -- Number of nonterminals.  */
-#define YYNNTS  26
+#define YYNNTS  24
 /* YYNRULES -- Number of rules.  */
-#define YYNRULES  82
+#define YYNRULES  80
 /* YYNRULES -- Number of states.  */
-#define YYNSTATES  111
+#define YYNSTATES  114
 
 /* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
 #define YYUNDEFTOK  2
@@ -588,54 +590,54 @@ static const yytype_uint8 yytranslate[] =
 static const yytype_uint8 yyprhs[] =
 {
        0,     0,     3,     8,     9,    12,    14,    16,    18,    21,
-      25,    27,    29,    32,    35,    39,    41,    43,    45,    47,
-      51,    53,    55,    59,    61,    63,    66,    69,    71,    73,
-      75,    77,    79,    81,    84,    86,    89,    92,    94,    96,
-      97,   101,   102,   106,   110,   114,   116,   118,   120,   121,
-     123,   125,   128,   130,   132,   135,   138,   142,   144,   147,
-     149,   152,   154,   157,   160,   161,   165,   167,   171,   174,
-     175,   178,   181,   185,   189,   193,   195,   197,   198,   201,
-     203,   205,   206
+      25,    27,    29,    32,    35,    39,    41,    44,    47,    49,
+      53,    55,    57,    61,    64,    66,    69,    72,    74,    76,
+      78,    80,    82,    84,    87,    89,    93,    97,    99,   101,
+     102,   106,   107,   111,   115,   119,   121,   123,   125,   126,
+     128,   130,   133,   135,   137,   140,   143,   147,   149,   152,
+     154,   157,   159,   162,   165,   166,   170,   172,   176,   179,
+     180,   183,   186,   190,   194,   198,   200,   202,   204,   206,
+     207
 };
 
 /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
 static const yytype_int8 yyrhs[] =
 {
-      53,     0,    -1,    54,    48,    66,    77,    -1,    -1,    54,
-      55,    -1,    56,    -1,    49,    -1,    17,    -1,    19,    76,
-      -1,    19,    76,    76,    -1,    20,    -1,    21,    -1,    22,
-       4,    -1,    23,     4,    -1,    24,    43,    76,    -1,    25,
-      -1,    26,    -1,    27,    -1,    28,    -1,    29,    43,    76,
-      -1,    31,    -1,    32,    -1,    33,    43,    76,    -1,    34,
-      -1,    35,    -1,    36,    76,    -1,    37,    76,    -1,    39,
-      -1,    40,    -1,    41,    -1,    44,    -1,    60,    -1,    57,
-      -1,    38,    72,    -1,    10,    -1,     8,    63,    -1,     9,
-      63,    -1,    18,    -1,    30,    -1,    -1,     6,    58,    65,
-      -1,    -1,     5,    59,    65,    -1,     7,    42,    63,    -1,
-      61,    62,    63,    -1,    11,    -1,    12,    -1,    13,    -1,
-      -1,    42,    -1,    72,    -1,    63,    72,    -1,    42,    -1,
-      46,    -1,    46,     4,    -1,    46,    75,    -1,    46,     4,
-      75,    -1,    64,    -1,    65,    64,    -1,    67,    -1,    66,
-      67,    -1,    68,    -1,    56,    44,    -1,     1,    44,    -1,
-      -1,    47,    69,    70,    -1,    71,    -1,    70,    45,    71,
-      -1,    70,    44,    -1,    -1,    71,    72,    -1,    71,    73,
-      -1,    71,    14,    72,    -1,    71,    15,     4,    -1,    71,
-      16,    42,    -1,    46,    -1,    75,    -1,    -1,    74,    51,
-      -1,     3,    -1,     3,    -1,    -1,    48,    50,    -1
+      53,     0,    -1,    54,    48,    66,    75,    -1,    -1,    54,
+      55,    -1,    56,    -1,    49,    -1,    17,    -1,    19,    74,
+      -1,    19,    74,    74,    -1,    20,    -1,    21,    -1,    22,
+       4,    -1,    23,     4,    -1,    24,    43,    74,    -1,    25,
+      -1,    26,    51,    -1,    27,    51,    -1,    28,    -1,    29,
+      43,    74,    -1,    31,    -1,    32,    -1,    33,    43,    74,
+      -1,    34,    51,    -1,    35,    -1,    36,    74,    -1,    37,
+      74,    -1,    39,    -1,    40,    -1,    41,    -1,    44,    -1,
+      60,    -1,    57,    -1,    38,    72,    -1,    10,    -1,     8,
+      51,    63,    -1,     9,    51,    63,    -1,    18,    -1,    30,
+      -1,    -1,     6,    58,    65,    -1,    -1,     5,    59,    65,
+      -1,     7,    42,    63,    -1,    61,    62,    63,    -1,    11,
+      -1,    12,    -1,    13,    -1,    -1,    42,    -1,    72,    -1,
+      63,    72,    -1,    42,    -1,    46,    -1,    46,     4,    -1,
+      46,    73,    -1,    46,     4,    73,    -1,    64,    -1,    65,
+      64,    -1,    67,    -1,    66,    67,    -1,    68,    -1,    56,
+      44,    -1,     1,    44,    -1,    -1,    47,    69,    70,    -1,
+      71,    -1,    70,    45,    71,    -1,    70,    44,    -1,    -1,
+      71,    72,    -1,    71,    51,    -1,    71,    14,    72,    -1,
+      71,    15,     4,    -1,    71,    16,    42,    -1,    46,    -1,
+      73,    -1,     3,    -1,     3,    -1,    -1,    48,    50,    -1
 };
 
 /* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
 static const yytype_uint16 yyrline[] =
 {
-       0,   202,   202,   210,   212,   216,   217,   218,   219,   224,
-     225,   226,   227,   228,   229,   230,   235,   239,   240,   241,
-     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
-     252,   256,   257,   258,   262,   278,   285,   292,   296,   303,
-     303,   308,   308,   313,   323,   338,   339,   340,   344,   345,
-     351,   352,   357,   361,   366,   372,   378,   389,   390,   399,
-     400,   406,   407,   408,   415,   415,   419,   420,   421,   426,
-     427,   429,   430,   432,   434,   439,   440,   456,   456,   462,
-     471,   476,   478
+       0,   194,   194,   202,   204,   208,   209,   211,   212,   217,
+     218,   219,   220,   221,   222,   223,   228,   232,   233,   234,
+     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
+     245,   249,   250,   251,   255,   271,   279,   287,   291,   298,
+     298,   303,   303,   308,   318,   333,   334,   335,   339,   340,
+     345,   346,   351,   355,   360,   366,   372,   383,   384,   393,
+     394,   400,   401,   402,   409,   409,   413,   414,   415,   420,
+     421,   423,   426,   428,   430,   435,   436,   441,   450,   455,
+     457
 };
 #endif
 
@@ -645,14 +647,14 @@ static const yytype_uint16 yyrline[] =
 static const char *const yytname[] =
 {
   "\"end of file\"", "error", "$undefined", "\"string\"", "\"integer\"",
-  "\"%token\"", "\"%nterm\"", "\"%type\"", "\"%destructor {...}\"",
-  "\"%printer {...}\"", "\"%union {...}\"", "\"%left\"", "\"%right\"",
+  "\"%token\"", "\"%nterm\"", "\"%type\"", "\"%destructor\"",
+  "\"%printer\"", "\"%union {...}\"", "\"%left\"", "\"%right\"",
   "\"%nonassoc\"", "\"%prec\"", "\"%dprec\"", "\"%merge\"", "\"%debug\"",
   "\"%default-prec\"", "\"%define\"", "\"%defines\"", "\"%error-verbose\"",
   "\"%expect\"", "\"%expect-rr\"", "\"%file-prefix\"", "\"%glr-parser\"",
-  "\"%initial-action {...}\"", "\"%lex-param {...}\"", "\"%locations\"",
+  "\"%initial-action\"", "\"%lex-param\"", "\"%locations\"",
   "\"%name-prefix\"", "\"%no-default-prec\"", "\"%no-lines\"",
-  "\"%nondeterministic-parser\"", "\"%output\"", "\"%parse-param {...}\"",
+  "\"%nondeterministic-parser\"", "\"%output\"", "\"%parse-param\"",
   "\"%pure-parser\"", "\"%require\"", "\"%skeleton\"", "\"%start\"",
   "\"%token-table\"", "\"%verbose\"", "\"%yacc\"", "\"type\"", "\"=\"",
   "\";\"", "\"|\"", "\"identifier\"", "\"identifier:\"", "\"%%\"",
@@ -661,8 +663,8 @@ static const char *const yytname[] =
   "symbol_declaration", "@1", "@2", "precedence_declaration",
   "precedence_declarator", "type.opt", "symbols.1", "symbol_def",
   "symbol_defs.1", "grammar", "rules_or_grammar_declaration", "rules",
-  "@3", "rhses.1", "rhs", "symbol", "action", "@4", "string_as_id",
-  "string_content", "epilogue.opt", 0
+  "@3", "rhses.1", "rhs", "symbol", "string_as_id", "string_content",
+  "epilogue.opt", 0
 };
 #endif
 
@@ -690,22 +692,22 @@ static const yytype_uint8 yyr1[] =
       57,    59,    57,    57,    60,    61,    61,    61,    62,    62,
       63,    63,    64,    64,    64,    64,    64,    65,    65,    66,
       66,    67,    67,    67,    69,    68,    70,    70,    70,    71,
-      71,    71,    71,    71,    71,    72,    72,    74,    73,    75,
-      76,    77,    77
+      71,    71,    71,    71,    71,    72,    72,    73,    74,    75,
+      75
 };
 
 /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
 static const yytype_uint8 yyr2[] =
 {
        0,     2,     4,     0,     2,     1,     1,     1,     2,     3,
-       1,     1,     2,     2,     3,     1,     1,     1,     1,     3,
-       1,     1,     3,     1,     1,     2,     2,     1,     1,     1,
-       1,     1,     1,     2,     1,     2,     2,     1,     1,     0,
+       1,     1,     2,     2,     3,     1,     2,     2,     1,     3,
+       1,     1,     3,     2,     1,     2,     2,     1,     1,     1,
+       1,     1,     1,     2,     1,     3,     3,     1,     1,     0,
        3,     0,     3,     3,     3,     1,     1,     1,     0,     1,
        1,     2,     1,     1,     2,     2,     3,     1,     2,     1,
        2,     1,     2,     2,     0,     3,     1,     3,     2,     0,
-       2,     2,     3,     3,     3,     1,     1,     0,     2,     1,
-       1,     0,     2
+       2,     2,     3,     3,     3,     1,     1,     1,     1,     0,
+       2
 };
 
 /* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
@@ -715,98 +717,98 @@ static const yytype_uint8 yydefact[] =
 {
        3,     0,     0,     1,    41,    39,     0,     0,     0,    34,
       45,    46,    47,     7,    37,     0,    10,    11,     0,     0,
-       0,    15,    16,    17,    18,     0,    38,    20,    21,     0,
-      23,    24,     0,     0,     0,    27,    28,    29,    30,     0,
-       6,     4,     5,    32,    31,    48,     0,     0,     0,    79,
-      75,    35,    50,    76,    36,    80,     8,    12,    13,     0,
-       0,     0,    25,    26,    33,     0,    64,     0,     0,    59,
-      61,    49,     0,    52,    53,    57,    42,    40,    43,    51,
-       9,    14,    19,    22,    63,    69,    62,     0,    60,     2,
-      44,    54,    55,    58,    65,    66,    82,    56,    68,    69,
-       0,     0,     0,    70,    71,     0,    67,    72,    73,    74,
-      78
+       0,    15,     0,     0,    18,     0,    38,    20,    21,     0,
+       0,    24,     0,     0,     0,    27,    28,    29,    30,     0,
+       6,     4,     5,    32,    31,    48,     0,     0,     0,     0,
+       0,    78,     8,    12,    13,     0,    16,    17,     0,     0,
+      23,    25,    26,    77,    75,    33,    76,     0,    64,     0,
+       0,    59,    61,    49,     0,    52,    53,    57,    42,    40,
+      43,    50,    35,    36,     9,    14,    19,    22,    63,    69,
+      62,     0,    60,     2,    44,    54,    55,    58,    51,    65,
+      66,    80,    56,    68,    69,     0,     0,     0,    71,    70,
+      67,    72,    73,    74
 };
 
 /* YYDEFGOTO[NTERM-NUM].  */
 static const yytype_int8 yydefgoto[] =
 {
-      -1,     1,     2,    41,    67,    43,    47,    46,    44,    45,
-      72,    51,    75,    76,    68,    69,    70,    85,    94,    95,
-      52,   104,   105,    53,    56,    89
+      -1,     1,     2,    41,    69,    43,    47,    46,    44,    45,
+      74,    80,    77,    78,    70,    71,    72,    89,    99,   100,
+      81,    66,    52,    93
 };
 
 /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
    STATE-NUM.  */
-#define YYPACT_NINF -69
+#define YYPACT_NINF -72
 static const yytype_int8 yypact[] =
 {
-     -69,     5,   112,   -69,   -69,   -69,   -35,     0,     0,   -69,
-     -69,   -69,   -69,   -69,   -69,    13,   -69,   -69,    20,    31,
-     -18,   -69,   -69,   -69,   -69,    -6,   -69,   -69,   -69,    -5,
-     -69,   -69,    13,    13,     0,   -69,   -69,   -69,   -69,    69,
-     -69,   -69,   -69,   -69,   -69,    -2,   -38,   -38,     0,   -69,
-     -69,     0,   -69,   -69,     0,   -69,    13,   -69,   -69,    13,
-      13,    13,   -69,   -69,   -69,    -8,   -69,     3,    21,   -69,
-     -69,   -69,     0,   -69,     6,   -69,   -38,   -38,     0,   -69,
-     -69,   -69,   -69,   -69,   -69,   -69,   -69,     2,   -69,   -69,
-       0,    39,   -69,   -69,   -33,    -1,   -69,   -69,   -69,   -69,
-       0,    44,     1,   -69,   -69,     4,    -1,   -69,   -69,   -69,
-     -69
+     -72,     7,   115,   -72,   -72,   -72,   -22,   -17,   -16,   -72,
+     -72,   -72,   -72,   -72,   -72,    26,   -72,   -72,    32,    33,
+      -3,   -72,    -8,    -6,   -72,     4,   -72,   -72,   -72,     9,
+       2,   -72,    26,    26,    -2,   -72,   -72,   -72,   -72,    72,
+     -72,   -72,   -72,   -72,   -72,    12,   -40,   -40,    -2,    -2,
+      -2,   -72,    26,   -72,   -72,    26,   -72,   -72,    26,    26,
+     -72,   -72,   -72,   -72,   -72,   -72,   -72,    11,   -72,    13,
+       3,   -72,   -72,   -72,    -2,   -72,    19,   -72,   -40,   -40,
+      -2,   -72,    -2,    -2,   -72,   -72,   -72,   -72,   -72,   -72,
+     -72,    18,   -72,   -72,    -2,    53,   -72,   -72,   -72,   -19,
+      16,   -72,   -72,   -72,   -72,    -2,    55,    21,   -72,   -72,
+      16,   -72,   -72,   -72
 };
 
 /* YYPGOTO[NTERM-NUM].  */
 static const yytype_int8 yypgoto[] =
 {
-     -69,   -69,   -69,   -69,    47,   -69,   -69,   -69,   -69,   -69,
-     -69,    -7,   -58,     7,   -69,   -15,   -69,   -69,   -69,   -42,
-     -34,   -69,   -69,   -68,    30,   -69
+     -72,   -72,   -72,   -72,    67,   -72,   -72,   -72,   -72,   -72,
+     -72,   -32,   -51,    23,   -72,     5,   -72,   -72,   -72,   -30,
+     -34,   -71,     6,   -72
 };
 
 /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
    positive, shift that token.  If negative, reduce the rule which
    number is the opposite.  If zero, do what YYDEFACT says.
    If YYTABLE_NINF, syntax error.  */
-#define YYTABLE_NINF -82
+#define YYTABLE_NINF -80
 static const yytype_int8 yytable[] =
 {
-      64,    54,    49,    49,    73,     3,    92,    48,    74,    49,
-      91,    98,    99,   100,   101,   102,    55,    79,    93,    93,
-      79,   -81,    65,    97,    57,    59,     4,     5,     6,     7,
-       8,     9,    10,    11,    12,    58,    84,    60,    61,    14,
-      71,    78,    49,   109,    79,    50,    50,    86,   108,    42,
-     -77,    26,    96,    88,    77,   110,    79,   106,     0,    34,
-       0,   103,    62,    63,     0,    90,   107,     0,    66,    87,
-      65,     0,   103,     0,     4,     5,     6,     7,     8,     9,
-      10,    11,    12,     0,     0,     0,    80,    14,     0,    81,
-      82,    83,     0,     0,     0,     0,     0,     0,     0,    26,
-       0,     0,     0,     0,     0,     0,     0,    34,     0,     0,
-       0,     0,     0,     0,     0,     0,    66,     4,     5,     6,
-       7,     8,     9,    10,    11,    12,     0,     0,     0,    13,
-      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
-      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
-      34,    35,    36,    37,     0,     0,    38,     0,     0,     0,
-      39,    40
+      65,    63,    75,   -79,    67,    96,    76,     3,     4,     5,
+       6,     7,     8,     9,    10,    11,    12,    82,    83,    63,
+      48,    14,    63,    95,   102,   103,   104,    97,    97,    51,
+     105,   106,   107,    26,    49,    50,    53,    54,    61,    62,
+      55,    34,    94,    56,    64,    57,    98,    58,    98,    98,
+      68,    91,    59,    60,    73,    88,    63,    90,    84,   112,
+      98,    85,    64,   113,    86,    87,   109,   108,   101,    42,
+      79,   111,     0,    67,   110,    92,   109,     4,     5,     6,
+       7,     8,     9,    10,    11,    12,     0,     0,     0,     0,
+      14,     0,     0,     0,     0,     0,     0,     0,     0,     0,
+       0,     0,    26,     0,     0,     0,     0,     0,     0,     0,
+      34,     0,     0,     0,     0,     0,     0,     0,     0,    68,
+       4,     5,     6,     7,     8,     9,    10,    11,    12,     0,
+       0,     0,    13,    14,    15,    16,    17,    18,    19,    20,
+      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
+      31,    32,    33,    34,    35,    36,    37,     0,     0,    38,
+       0,     0,     0,    39,    40
 };
 
 static const yytype_int8 yycheck[] =
 {
-      34,     8,     3,     3,    42,     0,    74,    42,    46,     3,
-       4,    44,    45,    14,    15,    16,     3,    51,    76,    77,
-      54,     0,     1,    91,     4,    43,     5,     6,     7,     8,
-       9,    10,    11,    12,    13,     4,    44,    43,    43,    18,
-      42,    48,     3,    42,    78,    46,    46,    44,     4,     2,
-      51,    30,    50,    68,    47,    51,    90,    99,    -1,    38,
-      -1,    95,    32,    33,    -1,    72,   100,    -1,    47,    48,
-       1,    -1,   106,    -1,     5,     6,     7,     8,     9,    10,
-      11,    12,    13,    -1,    -1,    -1,    56,    18,    -1,    59,
-      60,    61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,
-      -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,
-      -1,    -1,    -1,    -1,    -1,    -1,    47,     5,     6,     7,
-       8,     9,    10,    11,    12,    13,    -1,    -1,    -1,    17,
-      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
-      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
-      38,    39,    40,    41,    -1,    -1,    44,    -1,    -1,    -1,
-      48,    49
+      34,     3,    42,     0,     1,    76,    46,     0,     5,     6,
+       7,     8,     9,    10,    11,    12,    13,    49,    50,     3,
+      42,    18,     3,     4,    95,    44,    45,    78,    79,     3,
+      14,    15,    16,    30,    51,    51,     4,     4,    32,    33,
+      43,    38,    74,    51,    46,    51,    80,    43,    82,    83,
+      47,    48,    43,    51,    42,    44,     3,    44,    52,     4,
+      94,    55,    46,    42,    58,    59,   100,    51,    50,     2,
+      47,   105,    -1,     1,   104,    70,   110,     5,     6,     7,
+       8,     9,    10,    11,    12,    13,    -1,    -1,    -1,    -1,
+      18,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
+      -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
+      38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,
+       5,     6,     7,     8,     9,    10,    11,    12,    13,    -1,
+      -1,    -1,    17,    18,    19,    20,    21,    22,    23,    24,
+      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
+      35,    36,    37,    38,    39,    40,    41,    -1,    -1,    44,
+      -1,    -1,    -1,    48,    49
 };
 
 /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
@@ -817,14 +819,14 @@ static const yytype_uint8 yystos[] =
       11,    12,    13,    17,    18,    19,    20,    21,    22,    23,
       24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
       34,    35,    36,    37,    38,    39,    40,    41,    44,    48,
-      49,    55,    56,    57,    60,    61,    59,    58,    42,     3,
-      46,    63,    72,    75,    63,     3,    76,     4,     4,    43,
-      43,    43,    76,    76,    72,     1,    47,    56,    66,    67,
-      68,    42,    62,    42,    46,    64,    65,    65,    63,    72,
-      76,    76,    76,    76,    44,    69,    44,    48,    67,    77,
-      63,     4,    75,    64,    70,    71,    50,    75,    44,    45,
-      14,    15,    16,    72,    73,    74,    71,    72,     4,    42,
-      51
+      49,    55,    56,    57,    60,    61,    59,    58,    42,    51,
+      51,     3,    74,     4,     4,    43,    51,    51,    43,    43,
+      51,    74,    74,     3,    46,    72,    73,     1,    47,    56,
+      66,    67,    68,    42,    62,    42,    46,    64,    65,    65,
+      63,    72,    63,    63,    74,    74,    74,    74,    44,    69,
+      44,    48,    67,    75,    63,     4,    73,    64,    72,    70,
+      71,    50,    73,    44,    45,    14,    15,    16,    51,    72,
+      71,    72,     4,    42
 };
 
 #define yyerrok		(yyerrstatus = 0)
@@ -973,84 +975,64 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
   switch (yytype)
     {
       case 3: /* "\"string\"" */
-#line 179 "parse-gram.y"
+#line 175 "../../src/parse-gram.y"
 	{ fprintf (stderr, "\"%s\"", (yyvaluep->chars)); };
-#line 979 "parse-gram.c"
+#line 981 "../../src/parse-gram.c"
 	break;
       case 4: /* "\"integer\"" */
-#line 192 "parse-gram.y"
+#line 184 "../../src/parse-gram.y"
 	{ fprintf (stderr, "%d", (yyvaluep->integer)); };
-#line 984 "parse-gram.c"
-	break;
-      case 8: /* "\"%destructor {...}\"" */
-#line 181 "parse-gram.y"
-	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 989 "parse-gram.c"
-	break;
-      case 9: /* "\"%printer {...}\"" */
-#line 181 "parse-gram.y"
-	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 994 "parse-gram.c"
+#line 986 "../../src/parse-gram.c"
 	break;
       case 10: /* "\"%union {...}\"" */
-#line 181 "parse-gram.y"
-	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 999 "parse-gram.c"
-	break;
-      case 26: /* "\"%initial-action {...}\"" */
-#line 181 "parse-gram.y"
-	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1004 "parse-gram.c"
-	break;
-      case 27: /* "\"%lex-param {...}\"" */
-#line 181 "parse-gram.y"
-	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1009 "parse-gram.c"
-	break;
-      case 34: /* "\"%parse-param {...}\"" */
-#line 181 "parse-gram.y"
+#line 177 "../../src/parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1014 "parse-gram.c"
+#line 991 "../../src/parse-gram.c"
 	break;
       case 42: /* "\"type\"" */
-#line 190 "parse-gram.y"
+#line 182 "../../src/parse-gram.y"
 	{ fprintf (stderr, "<%s>", (yyvaluep->uniqstr)); };
-#line 1019 "parse-gram.c"
+#line 996 "../../src/parse-gram.c"
 	break;
       case 46: /* "\"identifier\"" */
-#line 194 "parse-gram.y"
+#line 186 "../../src/parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
-#line 1024 "parse-gram.c"
+#line 1001 "../../src/parse-gram.c"
 	break;
       case 47: /* "\"identifier:\"" */
-#line 196 "parse-gram.y"
+#line 188 "../../src/parse-gram.y"
 	{ fprintf (stderr, "%s:", (yyvaluep->symbol)->tag); };
-#line 1029 "parse-gram.c"
+#line 1006 "../../src/parse-gram.c"
 	break;
       case 49: /* "\"%{...%}\"" */
-#line 181 "parse-gram.y"
+#line 177 "../../src/parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1034 "parse-gram.c"
+#line 1011 "../../src/parse-gram.c"
 	break;
       case 50: /* "\"epilogue\"" */
-#line 181 "parse-gram.y"
+#line 177 "../../src/parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1039 "parse-gram.c"
+#line 1016 "../../src/parse-gram.c"
+	break;
+      case 51: /* "\"{...}\"" */
+#line 177 "../../src/parse-gram.y"
+	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
+#line 1021 "../../src/parse-gram.c"
 	break;
       case 72: /* "symbol" */
-#line 194 "parse-gram.y"
+#line 186 "../../src/parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
-#line 1044 "parse-gram.c"
+#line 1026 "../../src/parse-gram.c"
 	break;
-      case 75: /* "string_as_id" */
-#line 194 "parse-gram.y"
+      case 73: /* "string_as_id" */
+#line 186 "../../src/parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
-#line 1049 "parse-gram.c"
+#line 1031 "../../src/parse-gram.c"
 	break;
-      case 76: /* "string_content" */
-#line 179 "parse-gram.y"
+      case 74: /* "string_content" */
+#line 175 "../../src/parse-gram.y"
 	{ fprintf (stderr, "\"%s\"", (yyvaluep->chars)); };
-#line 1054 "parse-gram.c"
+#line 1036 "../../src/parse-gram.c"
 	break;
       default:
 	break;
@@ -1560,16 +1542,15 @@ YYLTYPE yylloc;
 
 
   /* User initialization code.  */
-#line 84 "parse-gram.y"
+#line 86 "../../src/parse-gram.y"
 {
   /* Bison's grammar can initial empty locations, hence a default
      location is needed. */
-  yylloc.start.file   = yylloc.end.file   = current_file;
-  yylloc.start.line   = yylloc.end.line   = 1;
-  yylloc.start.column = yylloc.end.column = 0;
+  boundary_set (&yylloc.start, current_file, 1, 0);
+  boundary_set (&yylloc.end, current_file, 1, 0);
 }
 /* Line 1078 of yacc.c.  */
-#line 1573 "parse-gram.c"
+#line 1554 "../../src/parse-gram.c"
   yylsp[0] = yylloc;
   goto yysetstate;
 
@@ -1754,17 +1735,18 @@ yyreduce:
   switch (yyn)
     {
         case 6:
-#line 217 "parse-gram.y"
-    { prologue_augment ((yyvsp[(1) - (1)].chars), (yylsp[(1) - (1)])); }
+#line 209 "../../src/parse-gram.y"
+    { prologue_augment (translate_code ((yyvsp[(1) - (1)].chars), (yylsp[(1) - (1)])),
+						       (yylsp[(1) - (1)])); }
     break;
 
   case 7:
-#line 218 "parse-gram.y"
+#line 211 "../../src/parse-gram.y"
     { debug_flag = true; }
     break;
 
   case 8:
-#line 220 "parse-gram.y"
+#line 213 "../../src/parse-gram.y"
     {
       static char one[] = "1";
       muscle_insert ((yyvsp[(2) - (2)].chars), one);
@@ -1772,37 +1754,37 @@ yyreduce:
     break;
 
   case 9:
-#line 224 "parse-gram.y"
+#line 217 "../../src/parse-gram.y"
     { muscle_insert ((yyvsp[(2) - (3)].chars), (yyvsp[(3) - (3)].chars)); }
     break;
 
   case 10:
-#line 225 "parse-gram.y"
+#line 218 "../../src/parse-gram.y"
     { defines_flag = true; }
     break;
 
   case 11:
-#line 226 "parse-gram.y"
+#line 219 "../../src/parse-gram.y"
     { error_verbose = true; }
     break;
 
   case 12:
-#line 227 "parse-gram.y"
+#line 220 "../../src/parse-gram.y"
     { expected_sr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 13:
-#line 228 "parse-gram.y"
+#line 221 "../../src/parse-gram.y"
     { expected_rr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 14:
-#line 229 "parse-gram.y"
+#line 222 "../../src/parse-gram.y"
     { spec_file_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 15:
-#line 231 "parse-gram.y"
+#line 224 "../../src/parse-gram.y"
     {
       nondeterministic_parser = true;
       glr_parser = true;
@@ -1810,86 +1792,86 @@ yyreduce:
     break;
 
   case 16:
-#line 236 "parse-gram.y"
+#line 229 "../../src/parse-gram.y"
     {
-      muscle_code_grow ("initial_action", (yyvsp[(1) - (1)].chars), (yylsp[(1) - (1)]));
+      muscle_code_grow ("initial_action", translate_symbol_action ((yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])), (yylsp[(2) - (2)]));
     }
     break;
 
   case 17:
-#line 239 "parse-gram.y"
-    { add_param ("lex_param", (yyvsp[(1) - (1)].chars), (yylsp[(1) - (1)])); }
+#line 232 "../../src/parse-gram.y"
+    { add_param ("lex_param", (yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])); }
     break;
 
   case 18:
-#line 240 "parse-gram.y"
+#line 233 "../../src/parse-gram.y"
     { locations_flag = true; }
     break;
 
   case 19:
-#line 241 "parse-gram.y"
+#line 234 "../../src/parse-gram.y"
     { spec_name_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 20:
-#line 242 "parse-gram.y"
+#line 235 "../../src/parse-gram.y"
     { no_lines_flag = true; }
     break;
 
   case 21:
-#line 243 "parse-gram.y"
+#line 236 "../../src/parse-gram.y"
     { nondeterministic_parser = true; }
     break;
 
   case 22:
-#line 244 "parse-gram.y"
+#line 237 "../../src/parse-gram.y"
     { spec_outfile = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 23:
-#line 245 "parse-gram.y"
-    { add_param ("parse_param", (yyvsp[(1) - (1)].chars), (yylsp[(1) - (1)])); }
+#line 238 "../../src/parse-gram.y"
+    { add_param ("parse_param", (yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])); }
     break;
 
   case 24:
-#line 246 "parse-gram.y"
+#line 239 "../../src/parse-gram.y"
     { pure_parser = true; }
     break;
 
   case 25:
-#line 247 "parse-gram.y"
+#line 240 "../../src/parse-gram.y"
     { version_check (&(yylsp[(2) - (2)]), (yyvsp[(2) - (2)].chars)); }
     break;
 
   case 26:
-#line 248 "parse-gram.y"
+#line 241 "../../src/parse-gram.y"
     { skeleton = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 27:
-#line 249 "parse-gram.y"
+#line 242 "../../src/parse-gram.y"
     { token_table_flag = true; }
     break;
 
   case 28:
-#line 250 "parse-gram.y"
+#line 243 "../../src/parse-gram.y"
     { report_flag = report_states; }
     break;
 
   case 29:
-#line 251 "parse-gram.y"
+#line 244 "../../src/parse-gram.y"
     { yacc_flag = true; }
     break;
 
   case 33:
-#line 259 "parse-gram.y"
+#line 252 "../../src/parse-gram.y"
     {
       grammar_start_symbol_set ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]));
     }
     break;
 
   case 34:
-#line 263 "parse-gram.y"
+#line 256 "../../src/parse-gram.y"
     {
       char const *body = (yyvsp[(1) - (1)].chars);
 
@@ -1908,46 +1890,48 @@ yyreduce:
     break;
 
   case 35:
-#line 279 "parse-gram.y"
+#line 272 "../../src/parse-gram.y"
     {
       symbol_list *list;
-      for (list = (yyvsp[(2) - (2)].list); list; list = list->next)
-	symbol_destructor_set (list->sym, (yyvsp[(1) - (2)].chars), (yylsp[(1) - (2)]));
-      symbol_list_free ((yyvsp[(2) - (2)].list));
+      const char *action = translate_symbol_action ((yyvsp[(2) - (3)].chars), (yylsp[(2) - (3)]));
+      for (list = (yyvsp[(3) - (3)].list); list; list = list->next)
+ 	symbol_destructor_set (list->sym, action, (yylsp[(2) - (3)]));
+      symbol_list_free ((yyvsp[(3) - (3)].list));
     }
     break;
 
   case 36:
-#line 286 "parse-gram.y"
+#line 280 "../../src/parse-gram.y"
     {
       symbol_list *list;
-      for (list = (yyvsp[(2) - (2)].list); list; list = list->next)
-	symbol_printer_set (list->sym, (yyvsp[(1) - (2)].chars), (yylsp[(1) - (2)]));
-      symbol_list_free ((yyvsp[(2) - (2)].list));
+      const char *action = translate_symbol_action ((yyvsp[(2) - (3)].chars), (yylsp[(2) - (3)]));
+      for (list = (yyvsp[(3) - (3)].list); list; list = list->next)
+	symbol_printer_set (list->sym, action, (yylsp[(2) - (3)]));
+      symbol_list_free ((yyvsp[(3) - (3)].list));
     }
     break;
 
   case 37:
-#line 293 "parse-gram.y"
+#line 288 "../../src/parse-gram.y"
     {
       default_prec = true;
     }
     break;
 
   case 38:
-#line 297 "parse-gram.y"
+#line 292 "../../src/parse-gram.y"
     {
       default_prec = false;
     }
     break;
 
   case 39:
-#line 303 "parse-gram.y"
+#line 298 "../../src/parse-gram.y"
     { current_class = nterm_sym; }
     break;
 
   case 40:
-#line 304 "parse-gram.y"
+#line 299 "../../src/parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
@@ -1955,12 +1939,12 @@ yyreduce:
     break;
 
   case 41:
-#line 308 "parse-gram.y"
+#line 303 "../../src/parse-gram.y"
     { current_class = token_sym; }
     break;
 
   case 42:
-#line 309 "parse-gram.y"
+#line 304 "../../src/parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
@@ -1968,7 +1952,7 @@ yyreduce:
     break;
 
   case 43:
-#line 314 "parse-gram.y"
+#line 309 "../../src/parse-gram.y"
     {
       symbol_list *list;
       for (list = (yyvsp[(3) - (3)].list); list; list = list->next)
@@ -1978,7 +1962,7 @@ yyreduce:
     break;
 
   case 44:
-#line 324 "parse-gram.y"
+#line 319 "../../src/parse-gram.y"
     {
       symbol_list *list;
       ++current_prec;
@@ -1993,49 +1977,49 @@ yyreduce:
     break;
 
   case 45:
-#line 338 "parse-gram.y"
+#line 333 "../../src/parse-gram.y"
     { (yyval.assoc) = left_assoc; }
     break;
 
   case 46:
-#line 339 "parse-gram.y"
+#line 334 "../../src/parse-gram.y"
     { (yyval.assoc) = right_assoc; }
     break;
 
   case 47:
-#line 340 "parse-gram.y"
+#line 335 "../../src/parse-gram.y"
     { (yyval.assoc) = non_assoc; }
     break;
 
   case 48:
-#line 344 "parse-gram.y"
+#line 339 "../../src/parse-gram.y"
     { current_type = NULL; }
     break;
 
   case 49:
-#line 345 "parse-gram.y"
+#line 340 "../../src/parse-gram.y"
     { current_type = (yyvsp[(1) - (1)].uniqstr); }
     break;
 
   case 50:
-#line 351 "parse-gram.y"
+#line 345 "../../src/parse-gram.y"
     { (yyval.list) = symbol_list_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 51:
-#line 352 "parse-gram.y"
+#line 346 "../../src/parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), (yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)])); }
     break;
 
   case 52:
-#line 358 "parse-gram.y"
+#line 352 "../../src/parse-gram.y"
     {
        current_type = (yyvsp[(1) - (1)].uniqstr);
      }
     break;
 
   case 53:
-#line 362 "parse-gram.y"
+#line 356 "../../src/parse-gram.y"
     {
        symbol_class_set ((yyvsp[(1) - (1)].symbol), current_class, (yylsp[(1) - (1)]), true);
        symbol_type_set ((yyvsp[(1) - (1)].symbol), current_type, (yylsp[(1) - (1)]));
@@ -2043,7 +2027,7 @@ yyreduce:
     break;
 
   case 54:
-#line 367 "parse-gram.y"
+#line 361 "../../src/parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
       symbol_type_set ((yyvsp[(1) - (2)].symbol), current_type, (yylsp[(1) - (2)]));
@@ -2052,7 +2036,7 @@ yyreduce:
     break;
 
   case 55:
-#line 373 "parse-gram.y"
+#line 367 "../../src/parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
       symbol_type_set ((yyvsp[(1) - (2)].symbol), current_type, (yylsp[(1) - (2)]));
@@ -2061,7 +2045,7 @@ yyreduce:
     break;
 
   case 56:
-#line 379 "parse-gram.y"
+#line 373 "../../src/parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (3)].symbol), current_class, (yylsp[(1) - (3)]), true);
       symbol_type_set ((yyvsp[(1) - (3)].symbol), current_type, (yylsp[(1) - (3)]));
@@ -2071,91 +2055,92 @@ yyreduce:
     break;
 
   case 63:
-#line 409 "parse-gram.y"
+#line 403 "../../src/parse-gram.y"
     {
       yyerrok;
     }
     break;
 
   case 64:
-#line 415 "parse-gram.y"
+#line 409 "../../src/parse-gram.y"
     { current_lhs = (yyvsp[(1) - (1)].symbol); current_lhs_location = (yylsp[(1) - (1)]); }
     break;
 
   case 66:
-#line 419 "parse-gram.y"
+#line 413 "../../src/parse-gram.y"
     { grammar_current_rule_end ((yylsp[(1) - (1)])); }
     break;
 
   case 67:
-#line 420 "parse-gram.y"
+#line 414 "../../src/parse-gram.y"
     { grammar_current_rule_end ((yylsp[(3) - (3)])); }
     break;
 
   case 69:
-#line 426 "parse-gram.y"
+#line 420 "../../src/parse-gram.y"
     { grammar_current_rule_begin (current_lhs, current_lhs_location); }
     break;
 
   case 70:
-#line 428 "parse-gram.y"
+#line 422 "../../src/parse-gram.y"
     { grammar_current_rule_symbol_append ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)])); }
     break;
 
+  case 71:
+#line 424 "../../src/parse-gram.y"
+    { grammar_current_rule_action_append (gram_last_string,
+					  gram_last_braced_code_loc); }
+    break;
+
   case 72:
-#line 431 "parse-gram.y"
+#line 427 "../../src/parse-gram.y"
     { grammar_current_rule_prec_set ((yyvsp[(3) - (3)].symbol), (yylsp[(3) - (3)])); }
     break;
 
   case 73:
-#line 433 "parse-gram.y"
+#line 429 "../../src/parse-gram.y"
     { grammar_current_rule_dprec_set ((yyvsp[(3) - (3)].integer), (yylsp[(3) - (3)])); }
     break;
 
   case 74:
-#line 435 "parse-gram.y"
+#line 431 "../../src/parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[(3) - (3)].uniqstr), (yylsp[(3) - (3)])); }
     break;
 
   case 75:
-#line 439 "parse-gram.y"
+#line 435 "../../src/parse-gram.y"
     { (yyval.symbol) = (yyvsp[(1) - (1)].symbol); }
     break;
 
   case 76:
-#line 440 "parse-gram.y"
+#line 436 "../../src/parse-gram.y"
     { (yyval.symbol) = (yyvsp[(1) - (1)].symbol); }
     break;
 
   case 77:
-#line 456 "parse-gram.y"
-    { grammar_current_rule_action_append (last_string, last_braced_code_loc); }
-    break;
-
-  case 79:
-#line 463 "parse-gram.y"
+#line 442 "../../src/parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[(1) - (1)].chars)), (yylsp[(1) - (1)]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[(1) - (1)]), false);
     }
     break;
 
-  case 80:
-#line 472 "parse-gram.y"
+  case 78:
+#line 451 "../../src/parse-gram.y"
     { (yyval.chars) = (yyvsp[(1) - (1)].chars); }
     break;
 
-  case 82:
-#line 479 "parse-gram.y"
+  case 80:
+#line 458 "../../src/parse-gram.y"
     {
-      muscle_code_grow ("epilogue", (yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)]));
-      scanner_last_string_free ();
+      muscle_code_grow ("epilogue", translate_code ((yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])), (yylsp[(2) - (2)]));
+      gram_scanner_last_string_free ();
     }
     break;
 
 
 /* Line 1267 of yacc.c.  */
-#line 2159 "parse-gram.c"
+#line 2144 "../../src/parse-gram.c"
       default: break;
     }
   YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);
@@ -2375,7 +2360,7 @@ yyreturn:
 }
 
 
-#line 485 "parse-gram.y"
+#line 464 "../../src/parse-gram.y"
 
 
 
@@ -2457,7 +2442,7 @@ add_param (char const *type, char *decl, location loc)
       free (name);
     }
 
-  scanner_last_string_free ();
+  gram_scanner_last_string_free ();
 }
 
 static void
