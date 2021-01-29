@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 2.4.1.71-377d.  */
+/* A Bison parser, made by GNU Bison 2.4.1.82-67f8.  */
 
 /* Skeleton implementation for Bison's Yacc-like parsers in C
    
@@ -45,7 +45,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "2.4.1.71-377d"
+#define YYBISON_VERSION "2.4.1.82-67f8"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -108,6 +108,7 @@
 #include "quotearg.h"
 #include "reader.h"
 #include "symlist.h"
+#include "named-ref.h"
 #include "scan-gram.h"
 #include "scan-code.h"
 
@@ -141,6 +142,7 @@ static symbol_class current_class = unknown_sym;
 static uniqstr current_type = NULL;
 static symbol *current_lhs;
 static location current_lhs_location;
+static named_ref *current_lhs_named_ref;
 static int current_prec = 0;
 
 #define YYTYPE_INT16 int_fast16_t
@@ -150,7 +152,7 @@ static int current_prec = 0;
 
 
 /* Line 190 of yacc.c  */
-#line 154 "parse-gram.c"
+#line 156 "../../bison-2.5/src/parse-gram.c"
 
 /* Enabling traces.  */
 #ifndef YYDEBUG
@@ -231,7 +233,8 @@ static int current_prec = 0;
      TYPE = 308,
      TYPE_TAG_ANY = 309,
      TYPE_TAG_NONE = 310,
-     PERCENT_UNION = 311
+     BRACKETED_ID = 311,
+     PERCENT_UNION = 312
    };
 #endif
 /* Tokens.  */
@@ -289,7 +292,8 @@ static int current_prec = 0;
 #define TYPE 308
 #define TYPE_TAG_ANY 309
 #define TYPE_TAG_NONE 310
-#define PERCENT_UNION 311
+#define BRACKETED_ID 311
+#define PERCENT_UNION 312
 
 
 
@@ -298,8 +302,8 @@ static int current_prec = 0;
 typedef union YYSTYPE
 {
 
-/* Line 223 of yacc.c  */
-#line 92 "parse-gram.y"
+/* Line 215 of yacc.c  */
+#line 94 "parse-gram.y"
 
   symbol *symbol;
   symbol_list *list;
@@ -309,11 +313,12 @@ typedef union YYSTYPE
   assoc assoc;
   uniqstr uniqstr;
   unsigned char character;
+  named_ref *named_ref;
 
 
 
-/* Line 223 of yacc.c  */
-#line 317 "parse-gram.c"
+/* Line 215 of yacc.c  */
+#line 322 "../../bison-2.5/src/parse-gram.c"
 } YYSTYPE;
 # define YYSTYPE_IS_TRIVIAL 1
 # define yystype YYSTYPE /* obsolescent; will be withdrawn */
@@ -338,7 +343,7 @@ typedef struct YYLTYPE
 
 
 /* Line 265 of yacc.c  */
-#line 342 "parse-gram.c"
+#line 347 "../../bison-2.5/src/parse-gram.c"
 
 #ifdef short
 # undef short
@@ -555,20 +560,20 @@ union yyalloc
 /* YYFINAL -- State number of the termination state.  */
 #define YYFINAL  3
 /* YYLAST -- Last index in YYTABLE.  */
-#define YYLAST   156
+#define YYLAST   159
 
 /* YYNTOKENS -- Number of terminals.  */
-#define YYNTOKENS  57
+#define YYNTOKENS  58
 /* YYNNTS -- Number of nonterminals.  */
-#define YYNNTS  33
+#define YYNNTS  34
 /* YYNRULES -- Number of rules.  */
-#define YYNRULES  105
+#define YYNRULES  107
 /* YYNRULES -- Number of states.  */
-#define YYNSTATES  143
+#define YYNSTATES  147
 
 /* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
 #define YYUNDEFTOK  2
-#define YYMAXUTOK   311
+#define YYMAXUTOK   312
 
 #define YYTRANSLATE(YYX)						\
   ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)
@@ -607,7 +612,7 @@ static const yytype_uint8 yytranslate[] =
       25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
       35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
       45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
-      55,    56
+      55,    56,    57
 };
 
 #if YYDEBUG
@@ -623,57 +628,58 @@ static const yytype_uint16 yyprhs[] =
      131,   135,   139,   143,   145,   147,   149,   150,   152,   154,
      157,   159,   162,   164,   167,   169,   172,   174,   176,   178,
      180,   182,   184,   187,   190,   194,   196,   199,   201,   204,
-     206,   209,   212,   213,   217,   219,   223,   226,   227,   230,
-     233,   237,   241,   245,   247,   249,   250,   252,   254,   256,
-     258,   260,   262,   264,   266,   267
+     206,   209,   212,   213,   218,   220,   224,   227,   228,   232,
+     236,   240,   244,   248,   249,   251,   253,   255,   256,   258,
+     260,   262,   264,   266,   268,   270,   272,   273
 };
 
 /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
 static const yytype_int8 yyrhs[] =
 {
-      58,     0,    -1,    59,    49,    76,    89,    -1,    -1,    59,
-      60,    -1,    61,    -1,    51,    -1,    17,    -1,    19,    82,
-      83,    -1,    20,    -1,    20,     3,    -1,    21,    -1,    22,
+      59,     0,    -1,    60,    49,    77,    91,    -1,    -1,    60,
+      61,    -1,    62,    -1,    51,    -1,    17,    -1,    19,    84,
+      85,    -1,    20,    -1,    20,     3,    -1,    21,    -1,    22,
        4,    -1,    23,     4,    -1,    24,     3,    -1,    24,    46,
        3,    -1,    25,    -1,    26,    43,    -1,    27,     3,    -1,
       28,    43,    -1,    29,    -1,    30,     3,    -1,    30,    46,
        3,    -1,    32,    -1,    33,    -1,    34,     3,    -1,    34,
       46,     3,    -1,    35,    43,    -1,    36,    -1,    37,     3,
       -1,    38,     3,    -1,    40,    -1,    41,    -1,    42,    -1,
-      52,    -1,    66,    -1,    63,    -1,    39,    87,    -1,     8,
-      43,    72,    -1,     9,    43,    72,    -1,    18,    -1,    31,
-      -1,    16,    84,    -1,    16,    47,    84,    -1,    -1,    47,
-      -1,    56,    62,    84,    -1,    -1,     6,    64,    75,    -1,
-      -1,     5,    65,    75,    -1,     7,    53,    71,    -1,    67,
-      68,    69,    -1,    10,    -1,    11,    -1,    12,    -1,    -1,
-      53,    -1,    70,    -1,    69,    70,    -1,    87,    -1,    87,
-       4,    -1,    87,    -1,    71,    87,    -1,    73,    -1,    72,
-      73,    -1,    87,    -1,    53,    -1,    54,    -1,    55,    -1,
-      53,    -1,    85,    -1,    85,     4,    -1,    85,    88,    -1,
-      85,     4,    88,    -1,    74,    -1,    75,    74,    -1,    77,
-      -1,    76,    77,    -1,    78,    -1,    61,    52,    -1,     1,
-      52,    -1,    -1,    86,    79,    80,    -1,    81,    -1,    80,
-      50,    81,    -1,    80,    52,    -1,    -1,    81,    87,    -1,
-      81,    43,    -1,    81,    13,    87,    -1,    81,    14,     4,
-      -1,    81,    15,    53,    -1,    47,    -1,     3,    -1,    -1,
-       3,    -1,    43,    -1,    47,    -1,    44,    -1,    48,    -1,
-      85,    -1,    88,    -1,     3,    -1,    -1,    49,    45,    -1
+      52,    -1,    67,    -1,    64,    -1,    39,    89,    -1,     8,
+      43,    73,    -1,     9,    43,    73,    -1,    18,    -1,    31,
+      -1,    16,    86,    -1,    16,    47,    86,    -1,    -1,    47,
+      -1,    57,    63,    86,    -1,    -1,     6,    65,    76,    -1,
+      -1,     5,    66,    76,    -1,     7,    53,    72,    -1,    68,
+      69,    70,    -1,    10,    -1,    11,    -1,    12,    -1,    -1,
+      53,    -1,    71,    -1,    70,    71,    -1,    89,    -1,    89,
+       4,    -1,    89,    -1,    72,    89,    -1,    74,    -1,    73,
+      74,    -1,    89,    -1,    53,    -1,    54,    -1,    55,    -1,
+      53,    -1,    87,    -1,    87,     4,    -1,    87,    90,    -1,
+      87,     4,    90,    -1,    75,    -1,    76,    75,    -1,    78,
+      -1,    77,    78,    -1,    79,    -1,    62,    52,    -1,     1,
+      52,    -1,    -1,    88,    83,    80,    81,    -1,    82,    -1,
+      81,    50,    82,    -1,    81,    52,    -1,    -1,    82,    89,
+      83,    -1,    82,    43,    83,    -1,    82,    13,    89,    -1,
+      82,    14,     4,    -1,    82,    15,    53,    -1,    -1,    56,
+      -1,    47,    -1,     3,    -1,    -1,     3,    -1,    43,    -1,
+      47,    -1,    44,    -1,    48,    -1,    87,    -1,    90,    -1,
+       3,    -1,    -1,    49,    45,    -1
 };
 
 /* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
 static const yytype_uint16 yyrline[] =
 {
-       0,   202,   202,   210,   212,   216,   217,   227,   228,   233,
-     234,   239,   240,   241,   242,   243,   244,   249,   258,   259,
-     260,   261,   262,   263,   264,   265,   266,   267,   268,   283,
-     284,   308,   309,   310,   311,   315,   316,   317,   321,   328,
-     335,   339,   343,   350,   365,   366,   370,   382,   382,   387,
-     387,   392,   403,   418,   419,   420,   424,   425,   430,   432,
-     437,   438,   443,   445,   450,   451,   455,   456,   457,   458,
-     463,   468,   473,   479,   485,   496,   497,   506,   507,   513,
-     514,   515,   522,   522,   526,   527,   528,   533,   534,   536,
-     538,   540,   542,   554,   555,   560,   561,   570,   590,   592,
-     601,   606,   607,   612,   619,   621
+       0,   207,   207,   215,   217,   221,   222,   232,   233,   238,
+     239,   244,   245,   246,   247,   248,   249,   254,   263,   264,
+     265,   266,   267,   268,   269,   270,   271,   272,   273,   288,
+     289,   313,   314,   315,   316,   320,   321,   322,   326,   333,
+     340,   344,   348,   355,   370,   371,   375,   387,   387,   392,
+     392,   397,   408,   423,   424,   425,   429,   430,   435,   437,
+     442,   443,   448,   450,   455,   456,   460,   461,   462,   463,
+     468,   473,   478,   484,   490,   501,   502,   511,   512,   518,
+     519,   520,   527,   527,   532,   533,   534,   539,   541,   543,
+     545,   547,   549,   555,   557,   569,   570,   575,   576,   585,
+     605,   607,   616,   621,   622,   627,   634,   636
 };
 #endif
 
@@ -695,15 +701,15 @@ static const char *const yytname[] =
   "\"%start\"", "\"%token-table\"", "\"%verbose\"", "\"%yacc\"",
   "\"{...}\"", "\"char\"", "\"epilogue\"", "\"=\"", "\"identifier\"",
   "\"identifier:\"", "\"%%\"", "\"|\"", "\"%{...%}\"", "\";\"", "\"type\"",
-  "\"<*>\"", "\"<>\"", "\"%union\"", "$accept", "input",
+  "\"<*>\"", "\"<>\"", "\"[id]\"", "\"%union\"", "$accept", "input",
   "prologue_declarations", "prologue_declaration", "grammar_declaration",
   "union_name", "symbol_declaration", "$@1", "$@2",
   "precedence_declaration", "precedence_declarator", "type.opt",
   "symbols.prec", "symbol.prec", "symbols.1", "generic_symlist",
   "generic_symlist_item", "symbol_def", "symbol_defs.1", "grammar",
   "rules_or_grammar_declaration", "rules", "$@3", "rhses.1", "rhs",
-  "variable", "content.opt", "braceless", "id", "id_colon", "symbol",
-  "string_as_id", "epilogue.opt", 0
+  "named_ref.opt", "variable", "content.opt", "braceless", "id",
+  "id_colon", "symbol", "string_as_id", "epilogue.opt", 0
 };
 #endif
 
@@ -717,24 +723,24 @@ static const yytype_uint16 yytoknum[] =
      275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
      285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
      295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
-     305,   306,   307,   308,   309,   310,   311
+     305,   306,   307,   308,   309,   310,   311,   312
 };
 # endif
 
 /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
 static const yytype_uint8 yyr1[] =
 {
-       0,    57,    58,    59,    59,    60,    60,    60,    60,    60,
-      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
-      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
-      60,    60,    60,    60,    60,    61,    61,    61,    61,    61,
-      61,    61,    61,    61,    62,    62,    61,    64,    63,    65,
-      63,    63,    66,    67,    67,    67,    68,    68,    69,    69,
-      70,    70,    71,    71,    72,    72,    73,    73,    73,    73,
-      74,    74,    74,    74,    74,    75,    75,    76,    76,    77,
-      77,    77,    79,    78,    80,    80,    80,    81,    81,    81,
-      81,    81,    81,    82,    82,    83,    83,    84,    85,    85,
-      86,    87,    87,    88,    89,    89
+       0,    58,    59,    60,    60,    61,    61,    61,    61,    61,
+      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
+      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
+      61,    61,    61,    61,    61,    62,    62,    62,    62,    62,
+      62,    62,    62,    62,    63,    63,    62,    65,    64,    66,
+      64,    64,    67,    68,    68,    68,    69,    69,    70,    70,
+      71,    71,    72,    72,    73,    73,    74,    74,    74,    74,
+      75,    75,    75,    75,    75,    76,    76,    77,    77,    78,
+      78,    78,    80,    79,    81,    81,    81,    82,    82,    82,
+      82,    82,    82,    83,    83,    84,    84,    85,    85,    86,
+      87,    87,    88,    89,    89,    90,    91,    91
 };
 
 /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
@@ -748,9 +754,9 @@ static const yytype_uint8 yyr2[] =
        3,     3,     3,     1,     1,     1,     0,     1,     1,     2,
        1,     2,     1,     2,     1,     2,     1,     1,     1,     1,
        1,     1,     2,     2,     3,     1,     2,     1,     2,     1,
-       2,     2,     0,     3,     1,     3,     2,     0,     2,     2,
-       3,     3,     3,     1,     1,     0,     1,     1,     1,     1,
-       1,     1,     1,     1,     0,     2
+       2,     2,     0,     4,     1,     3,     2,     0,     3,     3,
+       3,     3,     3,     0,     1,     1,     1,     0,     1,     1,
+       1,     1,     1,     1,     1,     1,     0,     2
 };
 
 /* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
@@ -763,25 +769,25 @@ static const yytype_uint8 yydefact[] =
        0,    16,     0,     0,     0,    20,     0,    41,    23,    24,
        0,     0,    28,     0,     0,     0,    31,    32,    33,     0,
        6,    34,    44,     4,     5,    36,    35,    56,     0,     0,
-       0,     0,     0,    97,     0,    42,    94,    93,    95,    10,
+       0,     0,     0,    99,     0,    42,    96,    95,    97,    10,
       12,    13,    14,     0,    17,    18,    19,    21,     0,    25,
-       0,    27,    29,    30,   103,    99,    98,   101,    37,   102,
-       0,   100,     0,     0,    77,    79,    82,    45,     0,    57,
+       0,    27,    29,    30,   105,   101,   100,   103,    37,   104,
+       0,   102,     0,     0,    77,    79,    93,    45,     0,    57,
        0,    70,    75,    50,    71,    48,    51,    62,    67,    68,
-      69,    38,    64,    66,    39,    43,    96,     8,    15,    22,
-      26,    81,    80,     0,    78,     2,    87,    46,    52,    58,
-      60,    76,    72,    73,    63,    65,   105,    83,    84,    59,
-      61,    74,    87,    86,     0,     0,     0,    89,    88,    85,
-      90,    91,    92
+      69,    38,    64,    66,    39,    43,    98,     8,    15,    22,
+      26,    81,    80,     0,    78,     2,    94,    82,    46,    52,
+      58,    60,    76,    72,    73,    63,    65,   107,    87,    59,
+      61,    74,    83,    84,    87,    86,     0,     0,     0,    93,
+      93,    85,    90,    91,    92,    89,    88
 };
 
 /* YYDEFGOTO[NTERM-NUM].  */
 static const yytype_int16 yydefgoto[] =
 {
       -1,     1,     2,    43,    82,    88,    45,    49,    48,    46,
-      47,    90,   118,   119,    96,   101,   102,    92,    93,    83,
-      84,    85,   116,   127,   128,    58,   107,    55,    77,    86,
-     103,    79,   115
+      47,    90,   119,   120,    96,   101,   102,    92,    93,    83,
+      84,    85,   128,   132,   133,   117,    58,   107,    55,    77,
+      86,   103,    79,   115
 };
 
 /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
@@ -789,96 +795,96 @@ static const yytype_int16 yydefgoto[] =
 #define YYPACT_NINF -60
 static const yytype_int16 yypact[] =
 {
-     -60,    18,   100,   -60,   -60,   -60,   -16,    24,    27,   -60,
-     -60,   -60,    -8,   -60,   -60,    11,    70,   -60,    71,    80,
-       2,   -60,    46,    87,    48,   -60,    31,   -60,   -60,   -60,
-      40,    49,   -60,    91,    92,     0,   -60,   -60,   -60,    15,
-     -60,   -60,    50,   -60,   -60,   -60,   -60,    43,    12,    12,
-       0,    25,    25,   -60,    55,   -60,   -60,   -60,    97,   -60,
-     -60,   -60,   -60,    98,   -60,   -60,   -60,   -60,    99,   -60,
-     110,   -60,   -60,   -60,   -60,   -60,   -60,   -60,   -60,   -60,
-      51,   -60,    62,     1,   -60,   -60,   -60,   -60,    55,   -60,
-       0,   -60,   -60,    12,    84,    12,     0,   -60,   -60,   -60,
-     -60,    25,   -60,   -60,    25,   -60,   -60,   -60,   -60,   -60,
-     -60,   -60,   -60,   101,   -60,   -60,   -60,   -60,     0,   -60,
-     111,   -60,   140,   -60,   -60,   -60,   -60,    10,    38,   -60,
-     -60,   -60,   -60,   -60,     0,   141,    94,   -60,   -60,    38,
-     -60,   -60,   -60
+     -60,     4,   102,   -60,   -60,   -60,     7,    10,    22,   -60,
+     -60,   -60,    -6,   -60,   -60,    27,    40,   -60,    65,    72,
+       2,   -60,    35,    79,    47,   -60,    11,   -60,   -60,   -60,
+      25,    48,   -60,    89,    90,     0,   -60,   -60,   -60,    15,
+     -60,   -60,    52,   -60,   -60,   -60,   -60,    41,    -2,    -2,
+       0,    26,    26,   -60,    59,   -60,   -60,   -60,    92,   -60,
+     -60,   -60,   -60,   100,   -60,   -60,   -60,   -60,   101,   -60,
+     112,   -60,   -60,   -60,   -60,   -60,   -60,   -60,   -60,   -60,
+      64,   -60,    93,     1,   -60,   -60,    49,   -60,    59,   -60,
+       0,   -60,   -60,    -2,    83,    -2,     0,   -60,   -60,   -60,
+     -60,    26,   -60,   -60,    26,   -60,   -60,   -60,   -60,   -60,
+     -60,   -60,   -60,   103,   -60,   -60,   -60,   -60,   -60,     0,
+     -60,   113,   -60,   143,   -60,   -60,   -60,   -60,   -60,   -60,
+     -60,   -60,   -16,    53,   -60,   -60,     0,   145,    94,    49,
+      49,    53,   -60,   -60,   -60,   -60,   -60
 };
 
 /* YYPGOTO[NTERM-NUM].  */
 static const yytype_int16 yypgoto[] =
 {
-     -60,   -60,   -60,   -60,   142,   -60,   -60,   -60,   -60,   -60,
-     -60,   -60,   -60,    30,   -60,   102,   -59,   -27,   104,   -60,
-      67,   -60,   -60,   -60,    23,   -60,   -60,   -50,   -19,   -60,
-     -35,   -58,   -60
+     -60,   -60,   -60,   -60,   148,   -60,   -60,   -60,   -60,   -60,
+     -60,   -60,   -60,    33,   -60,   104,   -42,   -18,   106,   -60,
+      74,   -60,   -60,   -60,    24,   -51,   -60,   -60,   -36,   -10,
+     -60,   -35,   -59,   -60
 };
 
 /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
    positive, shift that token.  If negative, reduce the rule which
    number is the opposite.  If zero, do what YYDEFACT says.
    If YYTABLE_NINF, syntax error.  */
-#define YYTABLE_NINF -105
+#define YYTABLE_NINF -107
 static const yytype_int16 yytable[] =
 {
-      78,  -104,    80,    74,   105,    62,     4,     5,     6,     7,
-       8,     9,    10,    11,    56,    97,    80,    12,     3,    14,
-       4,     5,     6,     7,     8,     9,    10,    11,    74,    94,
-      94,    12,    27,    14,    67,    53,   123,    50,   117,    54,
-      35,    74,   125,    69,    75,   125,    27,    76,    63,    81,
-     113,   134,   135,   136,    35,   120,    75,    42,    57,    76,
-     132,   124,   133,    81,   131,    91,   121,    51,   121,    75,
-      52,    42,    76,    59,    94,    60,    94,    68,    98,    99,
-     100,   137,    75,   120,    61,    76,    70,    74,   122,    64,
-      65,    66,    71,   138,    72,    73,    89,    87,    53,   140,
-     106,   108,   109,   111,   138,     4,     5,     6,     7,     8,
-       9,    10,    11,   110,   112,   130,    12,    13,    14,    15,
-      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
-      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
-      36,    37,    38,    74,    44,   141,   126,   142,   129,    39,
-     114,    40,    41,    95,   104,   139,    42
+      78,  -106,    80,    74,     3,    62,     4,     5,     6,     7,
+       8,     9,    10,    11,    67,    97,    80,    12,   105,    14,
+       4,     5,     6,     7,     8,     9,    10,    11,    69,    74,
+      56,    12,    27,    14,   134,   124,   135,    53,    94,    94,
+      35,    54,    75,    59,    75,    76,    27,    76,    63,    81,
+     113,    91,   118,    51,    35,   121,    74,    68,    42,   126,
+      50,   125,   126,    81,   131,    52,   136,   137,   138,    60,
+      75,    70,    42,    76,    57,   122,    61,   122,    64,    98,
+      99,   100,    65,    94,   121,    94,    74,   123,   145,   146,
+      66,    71,    72,    73,    89,   106,   139,    75,   140,    87,
+      76,   142,    53,   108,   109,   116,   140,     4,     5,     6,
+       7,     8,     9,    10,    11,   110,   111,   130,    12,    13,
+      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
+      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
+      34,    35,    36,    37,    38,   112,    74,   144,   127,   143,
+      44,    39,   129,    40,    41,    95,   104,   114,   141,    42
 };
 
 static const yytype_uint8 yycheck[] =
 {
-      35,     0,     1,     3,    54,     3,     5,     6,     7,     8,
-       9,    10,    11,    12,     3,    50,     1,    16,     0,    18,
-       5,     6,     7,     8,     9,    10,    11,    12,     3,    48,
-      49,    16,    31,    18,     3,    43,    94,    53,    88,    47,
-      39,     3,   101,     3,    44,   104,    31,    47,    46,    48,
-      49,    13,    14,    15,    39,    90,    44,    56,    47,    47,
-      50,    96,    52,    48,   122,    53,    93,    43,    95,    44,
-      43,    56,    47,     3,    93,     4,    95,    46,    53,    54,
-      55,    43,    44,   118,     4,    47,    46,     3,     4,    43,
-       3,    43,    43,   128,     3,     3,    53,    47,    43,   134,
-       3,     3,     3,    52,   139,     5,     6,     7,     8,     9,
-      10,    11,    12,     3,    52,     4,    16,    17,    18,    19,
-      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
-      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
-      40,    41,    42,     3,     2,     4,    45,    53,   118,    49,
-      83,    51,    52,    49,    52,   132,    56
+      35,     0,     1,     3,     0,     3,     5,     6,     7,     8,
+       9,    10,    11,    12,     3,    50,     1,    16,    54,    18,
+       5,     6,     7,     8,     9,    10,    11,    12,     3,     3,
+       3,    16,    31,    18,    50,    94,    52,    43,    48,    49,
+      39,    47,    44,     3,    44,    47,    31,    47,    46,    48,
+      49,    53,    88,    43,    39,    90,     3,    46,    57,   101,
+      53,    96,   104,    48,   123,    43,    13,    14,    15,     4,
+      44,    46,    57,    47,    47,    93,     4,    95,    43,    53,
+      54,    55,     3,    93,   119,    95,     3,     4,   139,   140,
+      43,    43,     3,     3,    53,     3,    43,    44,   133,    47,
+      47,   136,    43,     3,     3,    56,   141,     5,     6,     7,
+       8,     9,    10,    11,    12,     3,    52,     4,    16,    17,
+      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
+      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
+      38,    39,    40,    41,    42,    52,     3,    53,    45,     4,
+       2,    49,   119,    51,    52,    49,    52,    83,   134,    57
 };
 
 /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
    symbol of state STATE-NUM.  */
 static const yytype_uint8 yystos[] =
 {
-       0,    58,    59,     0,     5,     6,     7,     8,     9,    10,
+       0,    59,    60,     0,     5,     6,     7,     8,     9,    10,
       11,    12,    16,    17,    18,    19,    20,    21,    22,    23,
       24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
       34,    35,    36,    37,    38,    39,    40,    41,    42,    49,
-      51,    52,    56,    60,    61,    63,    66,    67,    65,    64,
-      53,    43,    43,    43,    47,    84,     3,    47,    82,     3,
+      51,    52,    57,    61,    62,    64,    67,    68,    66,    65,
+      53,    43,    43,    43,    47,    86,     3,    47,    84,     3,
        4,     4,     3,    46,    43,     3,    43,     3,    46,     3,
-      46,    43,     3,     3,     3,    44,    47,    85,    87,    88,
-       1,    48,    61,    76,    77,    78,    86,    47,    62,    53,
-      68,    53,    74,    75,    85,    75,    71,    87,    53,    54,
-      55,    72,    73,    87,    72,    84,     3,    83,     3,     3,
-       3,    52,    52,    49,    77,    89,    79,    84,    69,    70,
-      87,    74,     4,    88,    87,    73,    45,    80,    81,    70,
-       4,    88,    50,    52,    13,    14,    15,    43,    87,    81,
-      87,     4,    53
+      46,    43,     3,     3,     3,    44,    47,    87,    89,    90,
+       1,    48,    62,    77,    78,    79,    88,    47,    63,    53,
+      69,    53,    75,    76,    87,    76,    72,    89,    53,    54,
+      55,    73,    74,    89,    73,    86,     3,    85,     3,     3,
+       3,    52,    52,    49,    78,    91,    56,    83,    86,    70,
+      71,    89,    75,     4,    90,    89,    74,    45,    80,    71,
+       4,    90,    81,    82,    50,    52,    13,    14,    15,    43,
+      89,    82,    89,     4,    53,    83,    83
 };
 
 #define yyerrok		(yyerrstatus = 0)
@@ -1029,146 +1035,146 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
       case 3: /* "\"string\"" */
 
 /* Line 716 of yacc.c  */
-#line 180 "parse-gram.y"
+#line 184 "parse-gram.y"
 	{ fputs (quotearg_style (c_quoting_style, (yyvaluep->chars)), stderr); };
 
 /* Line 716 of yacc.c  */
-#line 1037 "parse-gram.c"
+#line 1043 "../../bison-2.5/src/parse-gram.c"
 	break;
       case 4: /* "\"integer\"" */
 
 /* Line 716 of yacc.c  */
-#line 191 "parse-gram.y"
+#line 196 "parse-gram.y"
 	{ fprintf (stderr, "%d", (yyvaluep->integer)); };
 
 /* Line 716 of yacc.c  */
-#line 1046 "parse-gram.c"
+#line 1052 "../../bison-2.5/src/parse-gram.c"
 	break;
       case 43: /* "\"{...}\"" */
 
 /* Line 716 of yacc.c  */
-#line 182 "parse-gram.y"
+#line 186 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->code)); };
 
 /* Line 716 of yacc.c  */
-#line 1055 "parse-gram.c"
+#line 1061 "../../bison-2.5/src/parse-gram.c"
 	break;
       case 44: /* "\"char\"" */
 
 /* Line 716 of yacc.c  */
-#line 174 "parse-gram.y"
+#line 178 "parse-gram.y"
 	{ fputs (char_name ((yyvaluep->character)), stderr); };
 
 /* Line 716 of yacc.c  */
-#line 1064 "parse-gram.c"
+#line 1070 "../../bison-2.5/src/parse-gram.c"
 	break;
       case 45: /* "\"epilogue\"" */
 
 /* Line 716 of yacc.c  */
-#line 182 "parse-gram.y"
+#line 186 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
 /* Line 716 of yacc.c  */
-#line 1073 "parse-gram.c"
+#line 1079 "../../bison-2.5/src/parse-gram.c"
 	break;
       case 47: /* "\"identifier\"" */
 
 /* Line 716 of yacc.c  */
-#line 187 "parse-gram.y"
+#line 192 "parse-gram.y"
 	{ fputs ((yyvaluep->uniqstr), stderr); };
 
 /* Line 716 of yacc.c  */
-#line 1082 "parse-gram.c"
+#line 1088 "../../bison-2.5/src/parse-gram.c"
 	break;
       case 48: /* "\"identifier:\"" */
 
 /* Line 716 of yacc.c  */
-#line 188 "parse-gram.y"
+#line 193 "parse-gram.y"
 	{ fprintf (stderr, "%s:", (yyvaluep->uniqstr)); };
 
 /* Line 716 of yacc.c  */
-#line 1091 "parse-gram.c"
+#line 1097 "../../bison-2.5/src/parse-gram.c"
 	break;
       case 51: /* "\"%{...%}\"" */
 
 /* Line 716 of yacc.c  */
-#line 182 "parse-gram.y"
+#line 186 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
 /* Line 716 of yacc.c  */
-#line 1100 "parse-gram.c"
+#line 1106 "../../bison-2.5/src/parse-gram.c"
 	break;
       case 53: /* "\"type\"" */
 
 /* Line 716 of yacc.c  */
-#line 186 "parse-gram.y"
+#line 191 "parse-gram.y"
 	{ fprintf (stderr, "<%s>", (yyvaluep->uniqstr)); };
 
 /* Line 716 of yacc.c  */
-#line 1109 "parse-gram.c"
+#line 1115 "../../bison-2.5/src/parse-gram.c"
 	break;
-      case 82: /* "variable" */
+      case 84: /* "variable" */
 
 /* Line 716 of yacc.c  */
-#line 187 "parse-gram.y"
+#line 192 "parse-gram.y"
 	{ fputs ((yyvaluep->uniqstr), stderr); };
 
 /* Line 716 of yacc.c  */
-#line 1118 "parse-gram.c"
+#line 1124 "../../bison-2.5/src/parse-gram.c"
 	break;
-      case 83: /* "content.opt" */
+      case 85: /* "content.opt" */
 
 /* Line 716 of yacc.c  */
-#line 182 "parse-gram.y"
+#line 186 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
 /* Line 716 of yacc.c  */
-#line 1127 "parse-gram.c"
+#line 1133 "../../bison-2.5/src/parse-gram.c"
 	break;
-      case 84: /* "braceless" */
+      case 86: /* "braceless" */
 
 /* Line 716 of yacc.c  */
-#line 182 "parse-gram.y"
+#line 186 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
 /* Line 716 of yacc.c  */
-#line 1136 "parse-gram.c"
+#line 1142 "../../bison-2.5/src/parse-gram.c"
 	break;
-      case 85: /* "id" */
+      case 87: /* "id" */
 
 /* Line 716 of yacc.c  */
-#line 194 "parse-gram.y"
+#line 199 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
 /* Line 716 of yacc.c  */
-#line 1145 "parse-gram.c"
+#line 1151 "../../bison-2.5/src/parse-gram.c"
 	break;
-      case 86: /* "id_colon" */
+      case 88: /* "id_colon" */
 
 /* Line 716 of yacc.c  */
-#line 195 "parse-gram.y"
+#line 200 "parse-gram.y"
 	{ fprintf (stderr, "%s:", (yyvaluep->symbol)->tag); };
 
 /* Line 716 of yacc.c  */
-#line 1154 "parse-gram.c"
+#line 1160 "../../bison-2.5/src/parse-gram.c"
 	break;
-      case 87: /* "symbol" */
+      case 89: /* "symbol" */
 
 /* Line 716 of yacc.c  */
-#line 194 "parse-gram.y"
+#line 199 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
 /* Line 716 of yacc.c  */
-#line 1163 "parse-gram.c"
+#line 1169 "../../bison-2.5/src/parse-gram.c"
 	break;
-      case 88: /* "string_as_id" */
+      case 90: /* "string_as_id" */
 
 /* Line 716 of yacc.c  */
-#line 194 "parse-gram.y"
+#line 199 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
 /* Line 716 of yacc.c  */
-#line 1172 "parse-gram.c"
+#line 1178 "../../bison-2.5/src/parse-gram.c"
 	break;
       default:
 	break;
@@ -1687,8 +1693,8 @@ YYLTYPE yylloc;
 
 /* User initialization code.  */
 
-/* Line 1249 of yacc.c  */
-#line 84 "parse-gram.y"
+/* Line 1243 of yacc.c  */
+#line 86 "parse-gram.y"
 {
   /* Bison's grammar can initial empty locations, hence a default
      location is needed. */
@@ -1696,8 +1702,8 @@ YYLTYPE yylloc;
   boundary_set (&yylloc.end, current_file, 1, 1);
 }
 
-/* Line 1249 of yacc.c  */
-#line 1701 "parse-gram.c"
+/* Line 1243 of yacc.c  */
+#line 1707 "../../bison-2.5/src/parse-gram.c"
   yylsp[0] = yylloc;
 
   goto yysetstate;
@@ -1885,7 +1891,7 @@ yyreduce:
         case 6:
 
 /* Line 1456 of yacc.c  */
-#line 218 "parse-gram.y"
+#line 223 "parse-gram.y"
     {
       code_props plain_code;
       code_props_plain_init (&plain_code, (yyvsp[(1) - (1)].chars), (yylsp[(1) - (1)]));
@@ -1900,14 +1906,14 @@ yyreduce:
   case 7:
 
 /* Line 1456 of yacc.c  */
-#line 227 "parse-gram.y"
+#line 232 "parse-gram.y"
     { debug_flag = true; }
     break;
 
   case 8:
 
 /* Line 1456 of yacc.c  */
-#line 229 "parse-gram.y"
+#line 234 "parse-gram.y"
     {
       muscle_percent_define_insert ((yyvsp[(2) - (3)].uniqstr), (yylsp[(2) - (3)]), (yyvsp[(3) - (3)].chars),
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
@@ -1917,14 +1923,14 @@ yyreduce:
   case 9:
 
 /* Line 1456 of yacc.c  */
-#line 233 "parse-gram.y"
+#line 238 "parse-gram.y"
     { defines_flag = true; }
     break;
 
   case 10:
 
 /* Line 1456 of yacc.c  */
-#line 235 "parse-gram.y"
+#line 240 "parse-gram.y"
     {
       defines_flag = true;
       spec_defines_file = xstrdup ((yyvsp[(2) - (2)].chars));
@@ -1934,42 +1940,42 @@ yyreduce:
   case 11:
 
 /* Line 1456 of yacc.c  */
-#line 239 "parse-gram.y"
+#line 244 "parse-gram.y"
     { error_verbose = true; }
     break;
 
   case 12:
 
 /* Line 1456 of yacc.c  */
-#line 240 "parse-gram.y"
+#line 245 "parse-gram.y"
     { expected_sr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 13:
 
 /* Line 1456 of yacc.c  */
-#line 241 "parse-gram.y"
+#line 246 "parse-gram.y"
     { expected_rr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 14:
 
 /* Line 1456 of yacc.c  */
-#line 242 "parse-gram.y"
+#line 247 "parse-gram.y"
     { spec_file_prefix = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 15:
 
 /* Line 1456 of yacc.c  */
-#line 243 "parse-gram.y"
+#line 248 "parse-gram.y"
     { spec_file_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 16:
 
 /* Line 1456 of yacc.c  */
-#line 245 "parse-gram.y"
+#line 250 "parse-gram.y"
     {
       nondeterministic_parser = true;
       glr_parser = true;
@@ -1979,7 +1985,7 @@ yyreduce:
   case 17:
 
 /* Line 1456 of yacc.c  */
-#line 250 "parse-gram.y"
+#line 255 "parse-gram.y"
     {
       code_props action;
       code_props_symbol_action_init (&action, (yyvsp[(2) - (2)].code), (yylsp[(2) - (2)]));
@@ -1993,77 +1999,77 @@ yyreduce:
   case 18:
 
 /* Line 1456 of yacc.c  */
-#line 258 "parse-gram.y"
+#line 263 "parse-gram.y"
     { language_argmatch ((yyvsp[(2) - (2)].chars), grammar_prio, (yylsp[(1) - (2)])); }
     break;
 
   case 19:
 
 /* Line 1456 of yacc.c  */
-#line 259 "parse-gram.y"
+#line 264 "parse-gram.y"
     { add_param ("lex_param", (yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
     break;
 
   case 20:
 
 /* Line 1456 of yacc.c  */
-#line 260 "parse-gram.y"
+#line 265 "parse-gram.y"
     { locations_flag = true; }
     break;
 
   case 21:
 
 /* Line 1456 of yacc.c  */
-#line 261 "parse-gram.y"
+#line 266 "parse-gram.y"
     { spec_name_prefix = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 22:
 
 /* Line 1456 of yacc.c  */
-#line 262 "parse-gram.y"
+#line 267 "parse-gram.y"
     { spec_name_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 23:
 
 /* Line 1456 of yacc.c  */
-#line 263 "parse-gram.y"
+#line 268 "parse-gram.y"
     { no_lines_flag = true; }
     break;
 
   case 24:
 
 /* Line 1456 of yacc.c  */
-#line 264 "parse-gram.y"
+#line 269 "parse-gram.y"
     { nondeterministic_parser = true; }
     break;
 
   case 25:
 
 /* Line 1456 of yacc.c  */
-#line 265 "parse-gram.y"
+#line 270 "parse-gram.y"
     { spec_outfile = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 26:
 
 /* Line 1456 of yacc.c  */
-#line 266 "parse-gram.y"
+#line 271 "parse-gram.y"
     { spec_outfile = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 27:
 
 /* Line 1456 of yacc.c  */
-#line 267 "parse-gram.y"
+#line 272 "parse-gram.y"
     { add_param ("parse_param", (yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
     break;
 
   case 28:
 
 /* Line 1456 of yacc.c  */
-#line 269 "parse-gram.y"
+#line 274 "parse-gram.y"
     {
       /* %pure-parser is deprecated in favor of `%define api.pure', so use
          `%define api.pure' in a backward-compatible manner here.  First, don't
@@ -2083,14 +2089,14 @@ yyreduce:
   case 29:
 
 /* Line 1456 of yacc.c  */
-#line 283 "parse-gram.y"
+#line 288 "parse-gram.y"
     { version_check (&(yylsp[(2) - (2)]), (yyvsp[(2) - (2)].chars)); }
     break;
 
   case 30:
 
 /* Line 1456 of yacc.c  */
-#line 285 "parse-gram.y"
+#line 290 "parse-gram.y"
     {
       char const *skeleton_user = (yyvsp[(2) - (2)].chars);
       if (strchr (skeleton_user, '/'))
@@ -2119,28 +2125,28 @@ yyreduce:
   case 31:
 
 /* Line 1456 of yacc.c  */
-#line 308 "parse-gram.y"
+#line 313 "parse-gram.y"
     { token_table_flag = true; }
     break;
 
   case 32:
 
 /* Line 1456 of yacc.c  */
-#line 309 "parse-gram.y"
+#line 314 "parse-gram.y"
     { report_flag |= report_states; }
     break;
 
   case 33:
 
 /* Line 1456 of yacc.c  */
-#line 310 "parse-gram.y"
+#line 315 "parse-gram.y"
     { yacc_flag = true; }
     break;
 
   case 37:
 
 /* Line 1456 of yacc.c  */
-#line 318 "parse-gram.y"
+#line 323 "parse-gram.y"
     {
       grammar_start_symbol_set ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]));
     }
@@ -2149,7 +2155,7 @@ yyreduce:
   case 38:
 
 /* Line 1456 of yacc.c  */
-#line 322 "parse-gram.y"
+#line 327 "parse-gram.y"
     {
       symbol_list *list;
       for (list = (yyvsp[(3) - (3)].list); list; list = list->next)
@@ -2161,7 +2167,7 @@ yyreduce:
   case 39:
 
 /* Line 1456 of yacc.c  */
-#line 329 "parse-gram.y"
+#line 334 "parse-gram.y"
     {
       symbol_list *list;
       for (list = (yyvsp[(3) - (3)].list); list; list = list->next)
@@ -2173,7 +2179,7 @@ yyreduce:
   case 40:
 
 /* Line 1456 of yacc.c  */
-#line 336 "parse-gram.y"
+#line 341 "parse-gram.y"
     {
       default_prec = true;
     }
@@ -2182,7 +2188,7 @@ yyreduce:
   case 41:
 
 /* Line 1456 of yacc.c  */
-#line 340 "parse-gram.y"
+#line 345 "parse-gram.y"
     {
       default_prec = false;
     }
@@ -2191,7 +2197,7 @@ yyreduce:
   case 42:
 
 /* Line 1456 of yacc.c  */
-#line 344 "parse-gram.y"
+#line 349 "parse-gram.y"
     {
       /* Do not invoke muscle_percent_code_grow here since it invokes
          muscle_user_name_list_grow.  */
@@ -2203,7 +2209,7 @@ yyreduce:
   case 43:
 
 /* Line 1456 of yacc.c  */
-#line 351 "parse-gram.y"
+#line 356 "parse-gram.y"
     {
       muscle_percent_code_grow ((yyvsp[(2) - (3)].uniqstr), (yylsp[(2) - (3)]), (yyvsp[(3) - (3)].chars), (yylsp[(3) - (3)]));
       code_scanner_last_string_free ();
@@ -2213,21 +2219,21 @@ yyreduce:
   case 44:
 
 /* Line 1456 of yacc.c  */
-#line 365 "parse-gram.y"
+#line 370 "parse-gram.y"
     {}
     break;
 
   case 45:
 
 /* Line 1456 of yacc.c  */
-#line 366 "parse-gram.y"
+#line 371 "parse-gram.y"
     { muscle_code_grow ("union_name", (yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 46:
 
 /* Line 1456 of yacc.c  */
-#line 371 "parse-gram.y"
+#line 376 "parse-gram.y"
     {
       union_seen = true;
       muscle_code_grow ("stype", (yyvsp[(3) - (3)].chars), (yylsp[(3) - (3)]));
@@ -2238,14 +2244,14 @@ yyreduce:
   case 47:
 
 /* Line 1456 of yacc.c  */
-#line 382 "parse-gram.y"
+#line 387 "parse-gram.y"
     { current_class = nterm_sym; }
     break;
 
   case 48:
 
 /* Line 1456 of yacc.c  */
-#line 383 "parse-gram.y"
+#line 388 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
@@ -2255,14 +2261,14 @@ yyreduce:
   case 49:
 
 /* Line 1456 of yacc.c  */
-#line 387 "parse-gram.y"
+#line 392 "parse-gram.y"
     { current_class = token_sym; }
     break;
 
   case 50:
 
 /* Line 1456 of yacc.c  */
-#line 388 "parse-gram.y"
+#line 393 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
@@ -2272,7 +2278,7 @@ yyreduce:
   case 51:
 
 /* Line 1456 of yacc.c  */
-#line 393 "parse-gram.y"
+#line 398 "parse-gram.y"
     {
       symbol_list *list;
       tag_seen = true;
@@ -2285,7 +2291,7 @@ yyreduce:
   case 52:
 
 /* Line 1456 of yacc.c  */
-#line 404 "parse-gram.y"
+#line 409 "parse-gram.y"
     {
       symbol_list *list;
       ++current_prec;
@@ -2302,126 +2308,126 @@ yyreduce:
   case 53:
 
 /* Line 1456 of yacc.c  */
-#line 418 "parse-gram.y"
+#line 423 "parse-gram.y"
     { (yyval.assoc) = left_assoc; }
     break;
 
   case 54:
 
 /* Line 1456 of yacc.c  */
-#line 419 "parse-gram.y"
+#line 424 "parse-gram.y"
     { (yyval.assoc) = right_assoc; }
     break;
 
   case 55:
 
 /* Line 1456 of yacc.c  */
-#line 420 "parse-gram.y"
+#line 425 "parse-gram.y"
     { (yyval.assoc) = non_assoc; }
     break;
 
   case 56:
 
 /* Line 1456 of yacc.c  */
-#line 424 "parse-gram.y"
+#line 429 "parse-gram.y"
     { current_type = NULL; }
     break;
 
   case 57:
 
 /* Line 1456 of yacc.c  */
-#line 425 "parse-gram.y"
+#line 430 "parse-gram.y"
     { current_type = (yyvsp[(1) - (1)].uniqstr); tag_seen = true; }
     break;
 
   case 58:
 
 /* Line 1456 of yacc.c  */
-#line 431 "parse-gram.y"
+#line 436 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 59:
 
 /* Line 1456 of yacc.c  */
-#line 433 "parse-gram.y"
+#line 438 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), symbol_list_sym_new ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]))); }
     break;
 
   case 60:
 
 /* Line 1456 of yacc.c  */
-#line 437 "parse-gram.y"
+#line 442 "parse-gram.y"
     { (yyval.symbol) = (yyvsp[(1) - (1)].symbol); }
     break;
 
   case 61:
 
 /* Line 1456 of yacc.c  */
-#line 438 "parse-gram.y"
+#line 443 "parse-gram.y"
     { (yyval.symbol) = (yyvsp[(1) - (2)].symbol); symbol_user_token_number_set ((yyvsp[(1) - (2)].symbol), (yyvsp[(2) - (2)].integer), (yylsp[(2) - (2)])); }
     break;
 
   case 62:
 
 /* Line 1456 of yacc.c  */
-#line 444 "parse-gram.y"
+#line 449 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 63:
 
 /* Line 1456 of yacc.c  */
-#line 446 "parse-gram.y"
+#line 451 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), symbol_list_sym_new ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]))); }
     break;
 
   case 64:
 
 /* Line 1456 of yacc.c  */
-#line 450 "parse-gram.y"
+#line 455 "parse-gram.y"
     { (yyval.list) = (yyvsp[(1) - (1)].list); }
     break;
 
   case 65:
 
 /* Line 1456 of yacc.c  */
-#line 451 "parse-gram.y"
+#line 456 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), (yyvsp[(2) - (2)].list)); }
     break;
 
   case 66:
 
 /* Line 1456 of yacc.c  */
-#line 455 "parse-gram.y"
+#line 460 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 67:
 
 /* Line 1456 of yacc.c  */
-#line 456 "parse-gram.y"
+#line 461 "parse-gram.y"
     { (yyval.list) = symbol_list_type_new ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 68:
 
 /* Line 1456 of yacc.c  */
-#line 457 "parse-gram.y"
+#line 462 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagged_new ((yylsp[(1) - (1)])); }
     break;
 
   case 69:
 
 /* Line 1456 of yacc.c  */
-#line 458 "parse-gram.y"
+#line 463 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagless_new ((yylsp[(1) - (1)])); }
     break;
 
   case 70:
 
 /* Line 1456 of yacc.c  */
-#line 464 "parse-gram.y"
+#line 469 "parse-gram.y"
     {
        current_type = (yyvsp[(1) - (1)].uniqstr);
        tag_seen = true;
@@ -2431,7 +2437,7 @@ yyreduce:
   case 71:
 
 /* Line 1456 of yacc.c  */
-#line 469 "parse-gram.y"
+#line 474 "parse-gram.y"
     {
        symbol_class_set ((yyvsp[(1) - (1)].symbol), current_class, (yylsp[(1) - (1)]), true);
        symbol_type_set ((yyvsp[(1) - (1)].symbol), current_type, (yylsp[(1) - (1)]));
@@ -2441,7 +2447,7 @@ yyreduce:
   case 72:
 
 /* Line 1456 of yacc.c  */
-#line 474 "parse-gram.y"
+#line 479 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
       symbol_type_set ((yyvsp[(1) - (2)].symbol), current_type, (yylsp[(1) - (2)]));
@@ -2452,7 +2458,7 @@ yyreduce:
   case 73:
 
 /* Line 1456 of yacc.c  */
-#line 480 "parse-gram.y"
+#line 485 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
       symbol_type_set ((yyvsp[(1) - (2)].symbol), current_type, (yylsp[(1) - (2)]));
@@ -2463,7 +2469,7 @@ yyreduce:
   case 74:
 
 /* Line 1456 of yacc.c  */
-#line 486 "parse-gram.y"
+#line 491 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (3)].symbol), current_class, (yylsp[(1) - (3)]), true);
       symbol_type_set ((yyvsp[(1) - (3)].symbol), current_type, (yylsp[(1) - (3)]));
@@ -2475,7 +2481,7 @@ yyreduce:
   case 81:
 
 /* Line 1456 of yacc.c  */
-#line 516 "parse-gram.y"
+#line 521 "parse-gram.y"
     {
       yyerrok;
     }
@@ -2484,84 +2490,100 @@ yyreduce:
   case 82:
 
 /* Line 1456 of yacc.c  */
-#line 522 "parse-gram.y"
-    { current_lhs = (yyvsp[(1) - (1)].symbol); current_lhs_location = (yylsp[(1) - (1)]); }
+#line 527 "parse-gram.y"
+    { current_lhs = (yyvsp[(1) - (2)].symbol); current_lhs_location = (yylsp[(1) - (2)]);
+    current_lhs_named_ref = (yyvsp[(2) - (2)].named_ref); }
     break;
 
   case 84:
 
 /* Line 1456 of yacc.c  */
-#line 526 "parse-gram.y"
+#line 532 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(1) - (1)])); }
     break;
 
   case 85:
 
 /* Line 1456 of yacc.c  */
-#line 527 "parse-gram.y"
+#line 533 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(3) - (3)])); }
     break;
 
   case 87:
 
 /* Line 1456 of yacc.c  */
-#line 533 "parse-gram.y"
-    { grammar_current_rule_begin (current_lhs, current_lhs_location); }
+#line 539 "parse-gram.y"
+    { grammar_current_rule_begin (current_lhs, current_lhs_location,
+				  current_lhs_named_ref); }
     break;
 
   case 88:
 
 /* Line 1456 of yacc.c  */
-#line 535 "parse-gram.y"
-    { grammar_current_rule_symbol_append ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)])); }
+#line 542 "parse-gram.y"
+    { grammar_current_rule_symbol_append ((yyvsp[(2) - (3)].symbol), (yylsp[(2) - (3)]), (yyvsp[(3) - (3)].named_ref)); }
     break;
 
   case 89:
 
 /* Line 1456 of yacc.c  */
-#line 537 "parse-gram.y"
-    { grammar_current_rule_action_append ((yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
+#line 544 "parse-gram.y"
+    { grammar_current_rule_action_append ((yyvsp[(2) - (3)].code), (yylsp[(2) - (3)]), (yyvsp[(3) - (3)].named_ref)); }
     break;
 
   case 90:
 
 /* Line 1456 of yacc.c  */
-#line 539 "parse-gram.y"
+#line 546 "parse-gram.y"
     { grammar_current_rule_prec_set ((yyvsp[(3) - (3)].symbol), (yylsp[(3) - (3)])); }
     break;
 
   case 91:
 
 /* Line 1456 of yacc.c  */
-#line 541 "parse-gram.y"
+#line 548 "parse-gram.y"
     { grammar_current_rule_dprec_set ((yyvsp[(3) - (3)].integer), (yylsp[(3) - (3)])); }
     break;
 
   case 92:
 
 /* Line 1456 of yacc.c  */
-#line 543 "parse-gram.y"
+#line 550 "parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[(3) - (3)].uniqstr), (yylsp[(3) - (3)])); }
     break;
 
-  case 94:
+  case 93:
 
 /* Line 1456 of yacc.c  */
 #line 555 "parse-gram.y"
+    { (yyval.named_ref) = 0; }
+    break;
+
+  case 94:
+
+/* Line 1456 of yacc.c  */
+#line 558 "parse-gram.y"
+    { (yyval.named_ref) = named_ref_new((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
+    break;
+
+  case 96:
+
+/* Line 1456 of yacc.c  */
+#line 570 "parse-gram.y"
     { (yyval.uniqstr) = uniqstr_new ((yyvsp[(1) - (1)].chars)); }
     break;
 
-  case 95:
+  case 97:
 
 /* Line 1456 of yacc.c  */
-#line 560 "parse-gram.y"
+#line 575 "parse-gram.y"
     { (yyval.chars) = ""; }
     break;
 
-  case 97:
+  case 99:
 
 /* Line 1456 of yacc.c  */
-#line 571 "parse-gram.y"
+#line 586 "parse-gram.y"
     {
       code_props plain_code;
       (yyvsp[(1) - (1)].code)[strlen ((yyvsp[(1) - (1)].code)) - 1] = '\n';
@@ -2572,17 +2594,17 @@ yyreduce:
     }
     break;
 
-  case 98:
+  case 100:
 
 /* Line 1456 of yacc.c  */
-#line 591 "parse-gram.y"
+#line 606 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
-  case 99:
+  case 101:
 
 /* Line 1456 of yacc.c  */
-#line 593 "parse-gram.y"
+#line 608 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[(1) - (1)].character)), (yylsp[(1) - (1)]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[(1) - (1)]), false);
@@ -2590,27 +2612,27 @@ yyreduce:
     }
     break;
 
-  case 100:
+  case 102:
 
 /* Line 1456 of yacc.c  */
-#line 601 "parse-gram.y"
+#line 616 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
-  case 103:
+  case 105:
 
 /* Line 1456 of yacc.c  */
-#line 613 "parse-gram.y"
+#line 628 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[(1) - (1)].chars)), (yylsp[(1) - (1)]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[(1) - (1)]), false);
     }
     break;
 
-  case 105:
+  case 107:
 
 /* Line 1456 of yacc.c  */
-#line 622 "parse-gram.y"
+#line 637 "parse-gram.y"
     {
       code_props plain_code;
       code_props_plain_init (&plain_code, (yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)]));
@@ -2624,7 +2646,7 @@ yyreduce:
 
 
 /* Line 1456 of yacc.c  */
-#line 2628 "parse-gram.c"
+#line 2650 "../../bison-2.5/src/parse-gram.c"
       default: break;
     }
   YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);
@@ -2843,7 +2865,7 @@ yyreturn:
 
 
 /* Line 1676 of yacc.c  */
-#line 632 "parse-gram.y"
+#line 647 "parse-gram.y"
 
 
 
