@@ -104,6 +104,7 @@
 #include "quotearg.h"
 #include "reader.h"
 #include "symlist.h"
+#include "symtab.h"
 #include "scan-gram.h"
 #include "scan-code.h"
 #include "xmemdup0.h"
@@ -126,7 +127,7 @@ static void gram_error (location const *, char const *);
 static char const *char_name (char);
 
 /* Line 337 of yacc.c  */
-#line 130 "src/parse-gram.c"
+#line 131 "src/parse-gram.c"
 
 # ifndef YY_NULL
 #  if defined __cplusplus && 201103L <= __cplusplus
@@ -157,7 +158,7 @@ extern int gram_debug;
 #endif
 /* "%code requires" blocks.  */
 /* Line 351 of yacc.c  */
-#line 221 "src/parse-gram.y"
+#line 222 "src/parse-gram.y"
 
 # ifndef PARAM_TYPE
 #  define PARAM_TYPE
@@ -172,7 +173,7 @@ extern int gram_debug;
 
 
 /* Line 351 of yacc.c  */
-#line 176 "src/parse-gram.c"
+#line 177 "src/parse-gram.c"
 
 /* Tokens.  */
 #ifndef YYTOKENTYPE
@@ -299,7 +300,7 @@ extern int gram_debug;
 typedef union YYSTYPE
 {
 /* Line 351 of yacc.c  */
-#line 107 "src/parse-gram.y"
+#line 108 "src/parse-gram.y"
 
   assoc assoc;
   char *code;
@@ -312,13 +313,16 @@ typedef union YYSTYPE
   unsigned char character;
 
 /* Line 351 of yacc.c  */
-#line 245 "src/parse-gram.y"
+#line 246 "src/parse-gram.y"
 
   param_type param;
 
+/* Line 351 of yacc.c  */
+#line 420 "src/parse-gram.y"
+code_props_type code_type;
 
 /* Line 351 of yacc.c  */
-#line 322 "src/parse-gram.c"
+#line 326 "src/parse-gram.c"
 } YYSTYPE;
 # define YYSTYPE_IS_TRIVIAL 1
 # define yystype YYSTYPE /* obsolescent; will be withdrawn */
@@ -360,10 +364,10 @@ int gram_parse ();
 /* Copy the second part of user declarations.  */
 
 /* Line 354 of yacc.c  */
-#line 364 "src/parse-gram.c"
+#line 368 "src/parse-gram.c"
 /* Unqualified %code blocks.  */
 /* Line 355 of yacc.c  */
-#line 56 "src/parse-gram.y"
+#line 57 "src/parse-gram.y"
 
   static int current_prec = 0;
   static location current_lhs_location;
@@ -396,7 +400,7 @@ int gram_parse ();
   #define YYTYPE_UINT8 uint_fast8_t
 
 /* Line 355 of yacc.c  */
-#line 234 "src/parse-gram.y"
+#line 235 "src/parse-gram.y"
 
   /** Add a lex-param and/or a parse-param.
    *
@@ -409,7 +413,7 @@ int gram_parse ();
 
 
 /* Line 355 of yacc.c  */
-#line 413 "src/parse-gram.c"
+#line 417 "src/parse-gram.c"
 
 #ifdef short
 # undef short
@@ -612,9 +616,9 @@ union yyalloc
 /* YYNTOKENS -- Number of terminals.  */
 #define YYNTOKENS  57
 /* YYNNTS -- Number of nonterminals.  */
-#define YYNNTS  36
+#define YYNNTS  38
 /* YYNRULES -- Number of rules.  */
-#define YYNRULES  110
+#define YYNRULES  112
 /* YYNSTATES -- Number of states.  */
 #define YYNSTATES  149
 
@@ -668,18 +672,18 @@ static const yytype_uint8 yytranslate[] =
   /* YYRLINEYYN -- Source line where rule number YYN was defined.    */
 static const yytype_uint16 yyrline[] =
 {
-       0,   270,   270,   278,   280,   284,   285,   295,   299,   304,
-     305,   310,   315,   316,   317,   318,   319,   324,   333,   334,
-     335,   336,   337,   338,   339,   340,   340,   341,   342,   366,
-     367,   368,   369,   373,   374,   383,   384,   385,   389,   396,
-     403,   407,   411,   418,   433,   434,   438,   450,   450,   455,
-     455,   460,   471,   486,   487,   488,   489,   493,   494,   499,
-     501,   506,   507,   512,   514,   519,   520,   524,   525,   526,
-     527,   532,   537,   542,   548,   554,   565,   566,   575,   576,
-     582,   583,   584,   591,   591,   599,   600,   601,   606,   608,
-     610,   612,   614,   616,   618,   623,   625,   635,   636,   641,
-     642,   643,   652,   672,   674,   683,   688,   689,   694,   701,
-     703
+       0,   271,   271,   279,   281,   285,   286,   296,   300,   305,
+     306,   311,   316,   317,   318,   319,   320,   325,   334,   335,
+     336,   337,   338,   339,   340,   341,   341,   342,   343,   367,
+     368,   369,   370,   374,   375,   384,   385,   386,   390,   397,
+     401,   405,   412,   423,   424,   434,   435,   439,   451,   451,
+     456,   456,   461,   472,   487,   488,   489,   490,   494,   495,
+     500,   502,   507,   508,   513,   515,   520,   521,   525,   526,
+     530,   531,   532,   537,   542,   547,   553,   559,   570,   571,
+     580,   581,   587,   588,   589,   596,   596,   604,   605,   606,
+     611,   613,   615,   617,   619,   621,   623,   628,   630,   640,
+     641,   646,   647,   648,   657,   677,   679,   688,   693,   694,
+     699,   706,   708
 };
 #endif
 
@@ -703,10 +707,10 @@ static const char *const yytname[] =
   "\"|\"", "\"%{...%}\"", "\";\"", "\"<tag>\"", "\"<*>\"", "\"<>\"",
   "\"%param\"", "\"%union\"", "$accept", "input", "prologue_declarations",
   "prologue_declaration", "$@1", "params", "grammar_declaration",
-  "union_name", "symbol_declaration", "$@2", "$@3",
+  "code_props_type", "union_name", "symbol_declaration", "$@2", "$@3",
   "precedence_declaration", "precedence_declarator", "tag.opt",
   "symbols.prec", "symbol.prec", "symbols.1", "generic_symlist",
-  "generic_symlist_item", "symbol_def", "symbol_defs.1", "grammar",
+  "generic_symlist_item", "tag", "symbol_def", "symbol_defs.1", "grammar",
   "rules_or_grammar_declaration", "rules", "$@4", "rhses.1", "rhs",
   "named_ref.opt", "variable", "content.opt", "braceless", "id",
   "id_colon", "symbol", "string_as_id", "epilogue.opt", YY_NULL
@@ -727,12 +731,12 @@ static const yytype_uint16 yytoknum[] =
 };
 # endif
 
-#define YYPACT_NINF -50
+#define YYPACT_NINF -88
 
 #define yypact_value_is_default(yystate) \
-  ((yystate) == (-50))
+  ((yystate) == (-88))
 
-#define YYTABLE_NINF -110
+#define YYTABLE_NINF -112
 
 #define yytable_value_is_error(yytable_value) \
   YYID (0)
@@ -741,21 +745,21 @@ static const yytype_uint16 yytoknum[] =
      STATE-NUM.    */
 static const yytype_int16 yypact[] =
 {
-     -50,     4,   107,   -50,   -50,   -50,   -20,     3,    11,   -50,
-     -50,   -50,   -50,    14,   -50,    12,    68,   -50,    72,    73,
-     -50,     0,   -50,    45,    86,     2,   -50,   -50,   -50,    17,
-      95,    96,    32,   -50,   -50,   -50,    16,   -50,   -50,   -50,
-      54,   -50,   -50,   -50,   -50,    49,    -2,    -2,    32,    27,
-      27,   -50,    63,   -50,   -50,   -50,    37,   -50,   -50,   -50,
-     -50,   101,   -50,   -50,   -50,   103,   -50,   104,   -50,   -50,
-     -50,   -50,   -50,   -50,   -50,   -50,    57,   -50,    58,     1,
-     -50,   -50,    79,    70,   -50,    63,   -50,    32,   -50,   -50,
-      -2,    64,    -2,    32,   -50,   -50,   -50,   -50,    27,   -50,
-     -50,    27,   -50,   -50,   -50,   -50,   -50,   -50,   -50,   -50,
-     -50,    78,   -50,   -50,   -50,   -50,   -50,    83,   -50,    32,
-     -50,   143,   -50,   145,   -50,   -50,   -50,   -50,   -50,   -50,
-     -50,   -50,   -50,    43,    50,   -50,   -50,    32,   146,    97,
-      79,   -50,    79,    50,   -50,   -50,   -50,   -50,   -50
+     -88,    42,   107,   -88,   -88,   -88,     8,   -88,   -88,   -88,
+     -88,   -88,   -88,    19,   -88,    12,    60,   -88,    66,    72,
+     -88,     2,   -88,    39,    83,    35,   -88,   -88,   -88,    36,
+      87,    88,    32,   -88,   -88,   -88,    15,   -88,   -88,   -88,
+      46,   -88,   -88,    55,   -88,   -88,    45,    -2,    -2,    32,
+     -88,    58,   -88,   -88,   -88,    31,   -88,   -88,   -88,   -88,
+      97,   -88,   -88,   -88,    98,   -88,   100,   -88,   -88,   -88,
+     -88,   -88,   -88,   -88,   -88,    56,   -88,    57,     1,   -88,
+     -88,    62,    69,   -88,    58,     0,   -88,    32,   -88,   -88,
+      -2,    85,    -2,    32,   -88,   -88,   -88,   -88,   -88,   -88,
+     -88,   -88,   -88,   -88,    77,   -88,   -88,   -88,   -88,   -88,
+      70,   -88,   -88,   -88,   -88,     0,   -88,   -88,   -88,    32,
+     -88,   102,   -88,   119,   -88,   -88,   -88,   -88,   -88,   -88,
+     -88,   -88,   -88,    33,    53,   -88,   -88,    32,   143,    71,
+      62,   -88,    62,    53,   -88,   -88,   -88,   -88,   -88
 };
 
   /* YYDEFACT[S] -- default reduction number in state S.  Performed when
@@ -763,39 +767,39 @@ static const yytype_int16 yypact[] =
      is an error.    */
 static const yytype_uint8 yydefact[] =
 {
-       3,     0,     0,     1,    49,    47,     0,     0,     0,    53,
-      54,    55,    56,     0,    40,     0,     9,    11,     0,     0,
-       7,     0,    16,     0,     0,     0,    41,    21,    22,     0,
+       3,     0,     0,     1,    50,    48,     0,    43,    44,    54,
+      55,    56,    57,     0,    39,     0,     9,    11,     0,     0,
+       7,     0,    16,     0,     0,     0,    40,    21,    22,     0,
        0,     0,     0,    29,    30,    31,     0,     6,    32,    25,
-      44,     4,     5,    36,    35,    57,     0,     0,     0,     0,
-       0,   102,     0,    42,    98,    97,    99,    10,    12,    13,
-      14,     0,    17,    18,    19,     0,    23,     0,    27,    28,
-     108,   104,   103,   106,    37,   107,     0,   105,     0,     0,
-      78,    80,    95,     0,    45,     0,    58,     0,    71,    76,
-      50,    72,    48,    51,    63,    68,    69,    70,    38,    65,
-      67,    39,    43,   101,   100,     8,    15,    20,    24,    82,
-      81,     0,    79,     2,    96,    83,    34,    26,    46,    52,
-      59,    61,    77,    73,    74,    64,    66,   110,    88,    33,
-      60,    62,    75,    84,    85,    88,    87,     0,     0,     0,
-      95,    91,    95,    86,    92,    93,    94,    90,    89
+      45,     4,     5,     0,    36,    35,    58,     0,     0,     0,
+     104,     0,    41,   100,    99,   101,    10,    12,    13,    14,
+       0,    17,    18,    19,     0,    23,     0,    27,    28,   110,
+     106,   105,   108,    37,   109,     0,   107,     0,     0,    80,
+      82,    97,     0,    46,     0,     0,    59,     0,    73,    78,
+      51,    74,    49,    52,    64,    42,   103,   102,     8,    15,
+      20,    24,    84,    83,     0,    81,     2,    98,    85,    34,
+      26,    47,    70,    71,    72,    38,    66,    69,    68,    53,
+      60,    62,    79,    75,    76,    65,   112,    90,    33,    67,
+      61,    63,    77,    86,    87,    90,    89,     0,     0,     0,
+      97,    93,    97,    88,    94,    95,    96,    92,    91
 };
 
   /* YYPGOTO[NTERM-NUM].    */
 static const yytype_int16 yypgoto[] =
 {
-     -50,   -50,   -50,   -50,   -50,   -50,   149,   -50,   -50,   -50,
-     -50,   -50,   -50,   -50,   -50,    33,   -50,   106,   -42,    -4,
-     112,   -50,    74,   -50,   -50,   -50,    19,   -45,   -50,   -50,
-     -16,    -8,   -50,   -32,   -49,   -50
+     -88,   -88,   -88,   -88,   -88,   -88,   146,   -88,   -88,   -88,
+     -88,   -88,   -88,   -88,   -88,   -88,    30,   -88,   -88,    37,
+     -88,   -26,   103,   -88,    75,   -88,   -88,   -88,    21,   -57,
+     -88,   -88,   -11,   -18,   -88,   -32,   -87,   -88
 };
 
   /* YYDEFGOTO[NTERM-NUM].    */
 static const yytype_int16 yydefgoto[] =
 {
-      -1,     1,     2,    41,    83,   117,    78,    85,    43,    47,
-      46,    44,    45,    87,   119,   120,    93,    98,    99,    89,
-      90,    79,    80,    81,   128,   133,   134,   115,    56,   105,
-      53,    73,    82,   100,    75,   113
+      -1,     1,     2,    41,    82,   110,    77,    43,    84,    44,
+      48,    47,    45,    46,    87,   119,   120,    93,   115,   116,
+     117,    89,    90,    78,    79,    80,   127,   133,   134,   108,
+      55,    98,    52,    72,    81,   118,    74,   106
 };
 
   /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
@@ -803,43 +807,43 @@ static const yytype_int16 yydefgoto[] =
      number is the opposite.  If YYTABLE_NINF, syntax error.    */
 static const yytype_int16 yytable[] =
 {
-      74,  -109,    76,    60,     3,    64,     4,     5,     6,     7,
-       8,     9,    10,    11,    12,    54,    94,    76,    13,    14,
-      66,     4,     5,     6,     7,     8,     9,    10,    11,    12,
-      70,    26,    48,    13,    14,    70,   102,    32,    91,    91,
-     103,    71,   124,    49,    72,    61,    26,    65,    77,   111,
-      88,    50,    32,    70,    51,   121,   126,    40,    55,   126,
-      52,   125,    67,    77,   137,   138,   139,    70,   123,   118,
-      71,    57,    40,    72,   132,    71,    58,    59,    72,    95,
-      96,    97,    91,   104,    91,    62,   122,   121,   122,    63,
-     140,   141,   135,    71,   136,   147,    72,   148,    68,    69,
-      84,    86,   142,    51,   106,   144,   107,   108,   109,   110,
-     116,   142,     4,     5,     6,     7,     8,     9,    10,    11,
-      12,   114,   127,   129,    13,    14,    15,    16,    17,    18,
+      73,  -111,    75,    69,   124,    59,     4,     5,     6,     7,
+       8,     9,    10,    11,    12,    53,    75,    94,    13,    14,
+       4,     5,     6,     7,     8,     9,    10,    11,    12,    91,
+      91,    26,    13,    14,    96,    69,   132,    32,    63,    65,
+      95,    70,     3,    70,    71,    26,    71,    60,    76,   104,
+      88,    32,   112,   113,   114,   121,    69,    40,    54,    50,
+      49,   125,    76,    56,   122,    51,   122,   137,   138,   139,
+      57,    40,    91,   111,    91,    70,    58,    97,    71,    61,
+      64,    66,   135,   147,   136,   148,    62,   121,    69,   123,
+      67,    68,    83,   140,   141,    85,    70,    86,    50,    71,
+      99,   100,   142,   101,   107,   144,   131,   102,   103,   109,
+     128,   142,     4,     5,     6,     7,     8,     9,    10,    11,
+      12,   126,    69,   146,    13,    14,    15,    16,    17,    18,
       19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
-      29,    30,    31,    32,    33,    34,    35,   131,    70,   146,
-     145,    42,   130,   112,   143,    36,   101,    37,    38,    92,
+      29,    30,    31,    32,    33,    34,    35,   145,    42,   130,
+       0,    92,   129,   105,     0,    36,   143,    37,    38,     0,
        0,     0,    39,    40
 };
 
 static const yytype_int16 yycheck[] =
 {
-      32,     0,     1,     3,     0,     3,     5,     6,     7,     8,
-       9,    10,    11,    12,    13,     3,    48,     1,    17,    18,
-       3,     5,     6,     7,     8,     9,    10,    11,    12,    13,
-       3,    30,    52,    17,    18,     3,    52,    36,    46,    47,
-       3,    43,    91,    40,    46,    45,    30,    45,    47,    48,
-      52,    40,    36,     3,    40,    87,    98,    56,    46,   101,
-      46,    93,    45,    47,    14,    15,    16,     3,     4,    85,
-      43,     3,    56,    46,   123,    43,     4,     4,    46,    52,
-      53,    54,    90,    46,    92,    40,    90,   119,    92,     3,
-      40,    41,    49,    43,    51,   140,    46,   142,     3,     3,
-      46,    52,   134,    40,     3,   137,     3,     3,    51,    51,
+      32,     0,     1,     3,    91,     3,     5,     6,     7,     8,
+       9,    10,    11,    12,    13,     3,     1,    49,    17,    18,
+       5,     6,     7,     8,     9,    10,    11,    12,    13,    47,
+      48,    30,    17,    18,     3,     3,   123,    36,     3,     3,
+      51,    43,     0,    43,    46,    30,    46,    45,    47,    48,
+      52,    36,    52,    53,    54,    87,     3,    56,    46,    40,
+      52,    93,    47,     3,    90,    46,    92,    14,    15,    16,
+       4,    56,    90,    84,    92,    43,     4,    46,    46,    40,
+      45,    45,    49,   140,    51,   142,     3,   119,     3,     4,
+       3,     3,    46,    40,    41,    40,    43,    52,    40,    46,
+       3,     3,   134,     3,    42,   137,     4,    51,    51,    40,
       40,   143,     5,     6,     7,     8,     9,    10,    11,    12,
-      13,    42,    44,    40,    17,    18,    19,    20,    21,    22,
+      13,    44,     3,    52,    17,    18,    19,    20,    21,    22,
       23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
-      33,    34,    35,    36,    37,    38,    39,     4,     3,    52,
-       4,     2,   119,    79,   135,    48,    50,    50,    51,    47,
+      33,    34,    35,    36,    37,    38,    39,     4,     2,   119,
+      -1,    48,   115,    78,    -1,    48,   135,    50,    51,    -1,
       -1,    -1,    55,    56
 };
 
@@ -851,17 +855,17 @@ static const yytype_uint8 yystos[] =
       11,    12,    13,    17,    18,    19,    20,    21,    22,    23,
       24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
       34,    35,    36,    37,    38,    39,    48,    50,    51,    55,
-      56,    60,    63,    65,    68,    69,    67,    66,    52,    40,
-      40,    40,    46,    87,     3,    46,    85,     3,     4,     4,
-       3,    45,    40,     3,     3,    45,     3,    45,     3,     3,
-       3,    43,    46,    88,    90,    91,     1,    47,    63,    78,
-      79,    80,    89,    61,    46,    64,    52,    70,    52,    76,
-      77,    88,    77,    73,    90,    52,    53,    54,    74,    75,
-      90,    74,    87,     3,    46,    86,     3,     3,     3,    51,
-      51,    48,    79,    92,    42,    84,    40,    62,    87,    71,
-      72,    90,    76,     4,    91,    90,    75,    44,    81,    40,
-      72,     4,    91,    82,    83,    49,    51,    14,    15,    16,
-      40,    41,    90,    83,    90,     4,    52,    84,    84
+      56,    60,    63,    64,    66,    69,    70,    68,    67,    52,
+      40,    46,    89,     3,    46,    87,     3,     4,     4,     3,
+      45,    40,     3,     3,    45,     3,    45,     3,     3,     3,
+      43,    46,    90,    92,    93,     1,    47,    63,    80,    81,
+      82,    91,    61,    46,    65,    40,    52,    71,    52,    78,
+      79,    90,    79,    74,    92,    89,     3,    46,    88,     3,
+       3,     3,    51,    51,    48,    81,    94,    42,    86,    40,
+      62,    89,    52,    53,    54,    75,    76,    77,    92,    72,
+      73,    92,    78,     4,    93,    92,    44,    83,    40,    76,
+      73,     4,    93,    84,    85,    49,    51,    14,    15,    16,
+      40,    41,    92,    85,    92,     4,    52,    86,    86
 };
 
   /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.    */
@@ -871,14 +875,14 @@ static const yytype_uint8 yyr1[] =
       60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
       60,    60,    60,    60,    60,    61,    60,    60,    60,    60,
       60,    60,    60,    62,    62,    63,    63,    63,    63,    63,
-      63,    63,    63,    63,    64,    64,    63,    66,    65,    67,
-      65,    65,    68,    69,    69,    69,    69,    70,    70,    71,
-      71,    72,    72,    73,    73,    74,    74,    75,    75,    75,
-      75,    76,    76,    76,    76,    76,    77,    77,    78,    78,
-      79,    79,    79,    81,    80,    82,    82,    82,    83,    83,
-      83,    83,    83,    83,    83,    84,    84,    85,    85,    86,
-      86,    86,    87,    88,    88,    89,    90,    90,    91,    92,
-      92
+      63,    63,    63,    64,    64,    65,    65,    63,    67,    66,
+      68,    66,    66,    69,    70,    70,    70,    70,    71,    71,
+      72,    72,    73,    73,    74,    74,    75,    75,    76,    76,
+      77,    77,    77,    78,    78,    78,    78,    78,    79,    79,
+      80,    80,    81,    81,    81,    83,    82,    84,    84,    84,
+      85,    85,    85,    85,    85,    85,    85,    86,    86,    87,
+      87,    88,    88,    88,    89,    90,    90,    91,    92,    92,
+      93,    94,    94
 };
 
   /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.    */
@@ -887,15 +891,15 @@ static const yytype_uint8 yyr2[] =
        0,     2,     4,     0,     2,     1,     1,     1,     3,     1,
        2,     1,     2,     2,     2,     3,     1,     2,     2,     2,
        3,     1,     1,     2,     3,     0,     3,     2,     2,     1,
-       1,     1,     1,     2,     1,     1,     1,     2,     3,     3,
-       1,     1,     2,     3,     0,     1,     3,     0,     3,     0,
-       3,     3,     3,     1,     1,     1,     1,     0,     1,     1,
-       2,     1,     2,     1,     2,     1,     2,     1,     1,     1,
-       1,     1,     1,     2,     2,     3,     1,     2,     1,     2,
-       1,     2,     2,     0,     4,     1,     3,     2,     0,     3,
-       3,     2,     3,     3,     3,     0,     1,     1,     1,     0,
-       1,     1,     1,     1,     1,     1,     1,     1,     1,     0,
-       2
+       1,     1,     1,     2,     1,     1,     1,     2,     3,     1,
+       1,     2,     3,     1,     1,     0,     1,     3,     0,     3,
+       0,     3,     3,     3,     1,     1,     1,     1,     0,     1,
+       1,     2,     1,     2,     1,     2,     1,     2,     1,     1,
+       1,     1,     1,     1,     1,     2,     2,     3,     1,     2,
+       1,     2,     1,     2,     2,     0,     4,     1,     3,     2,
+       0,     3,     3,     2,     3,     3,     3,     0,     1,     1,
+       1,     0,     1,     1,     1,     1,     1,     1,     1,     1,
+       1,     0,     2
 };
 
 
@@ -1055,108 +1059,96 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
   switch (yytype)
     {
             case 3: // "string"
-
 /* Line 740 of yacc.c  */
-#line 194 "src/parse-gram.y"
-        { fputs (quotearg_style (c_quoting_style, ((*yyvaluep).chars)), stderr); }
+#line 195 "src/parse-gram.y"
+        { fputs (quotearg_style (c_quoting_style, ((*yyvaluep).chars)), yyo); }
 /* Line 740 of yacc.c  */
-#line 1064 "src/parse-gram.c"
+#line 1067 "src/parse-gram.c"
         break;
 
             case 4: // "integer"
-
 /* Line 740 of yacc.c  */
-#line 207 "src/parse-gram.y"
-        { fprintf (stderr, "%d", ((*yyvaluep).integer)); }
+#line 208 "src/parse-gram.y"
+        { fprintf (yyo, "%d", ((*yyvaluep).integer)); }
 /* Line 740 of yacc.c  */
-#line 1073 "src/parse-gram.c"
+#line 1075 "src/parse-gram.c"
         break;
 
             case 24: // "%<flag>"
-
 /* Line 740 of yacc.c  */
-#line 203 "src/parse-gram.y"
-        { fprintf (stderr, "%%%s", ((*yyvaluep).uniqstr)); }
+#line 204 "src/parse-gram.y"
+        { fprintf (yyo, "%%%s", ((*yyvaluep).uniqstr)); }
 /* Line 740 of yacc.c  */
-#line 1082 "src/parse-gram.c"
+#line 1083 "src/parse-gram.c"
         break;
 
             case 40: // "{...}"
-
 /* Line 740 of yacc.c  */
-#line 196 "src/parse-gram.y"
-        { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).code)); }
+#line 197 "src/parse-gram.y"
+        { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).code)); }
 /* Line 740 of yacc.c  */
 #line 1091 "src/parse-gram.c"
         break;
 
             case 42: // "[identifier]"
-
 /* Line 740 of yacc.c  */
-#line 201 "src/parse-gram.y"
-        { fprintf (stderr, "[%s]", ((*yyvaluep).uniqstr)); }
+#line 202 "src/parse-gram.y"
+        { fprintf (yyo, "[%s]", ((*yyvaluep).uniqstr)); }
 /* Line 740 of yacc.c  */
-#line 1100 "src/parse-gram.c"
+#line 1099 "src/parse-gram.c"
         break;
 
             case 43: // "char"
-
 /* Line 740 of yacc.c  */
-#line 188 "src/parse-gram.y"
-        { fputs (char_name (((*yyvaluep).character)), stderr); }
+#line 189 "src/parse-gram.y"
+        { fputs (char_name (((*yyvaluep).character)), yyo); }
 /* Line 740 of yacc.c  */
-#line 1109 "src/parse-gram.c"
+#line 1107 "src/parse-gram.c"
         break;
 
             case 44: // "epilogue"
-
 /* Line 740 of yacc.c  */
-#line 196 "src/parse-gram.y"
-        { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); }
+#line 197 "src/parse-gram.y"
+        { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).chars)); }
 /* Line 740 of yacc.c  */
-#line 1118 "src/parse-gram.c"
+#line 1115 "src/parse-gram.c"
         break;
 
             case 46: // "identifier"
-
 /* Line 740 of yacc.c  */
-#line 200 "src/parse-gram.y"
-        { fputs (((*yyvaluep).uniqstr), stderr); }
+#line 201 "src/parse-gram.y"
+        { fputs (((*yyvaluep).uniqstr), yyo); }
 /* Line 740 of yacc.c  */
-#line 1127 "src/parse-gram.c"
+#line 1123 "src/parse-gram.c"
         break;
 
             case 47: // "identifier:"
-
 /* Line 740 of yacc.c  */
-#line 202 "src/parse-gram.y"
-        { fprintf (stderr, "%s:", ((*yyvaluep).uniqstr)); }
+#line 203 "src/parse-gram.y"
+        { fprintf (yyo, "%s:", ((*yyvaluep).uniqstr)); }
 /* Line 740 of yacc.c  */
-#line 1136 "src/parse-gram.c"
+#line 1131 "src/parse-gram.c"
         break;
 
             case 50: // "%{...%}"
-
 /* Line 740 of yacc.c  */
-#line 196 "src/parse-gram.y"
-        { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); }
+#line 197 "src/parse-gram.y"
+        { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).chars)); }
 /* Line 740 of yacc.c  */
-#line 1145 "src/parse-gram.c"
+#line 1139 "src/parse-gram.c"
         break;
 
             case 52: // "<tag>"
-
 /* Line 740 of yacc.c  */
-#line 204 "src/parse-gram.y"
-        { fprintf (stderr, "<%s>", ((*yyvaluep).uniqstr)); }
+#line 205 "src/parse-gram.y"
+        { fprintf (yyo, "<%s>", ((*yyvaluep).uniqstr)); }
 /* Line 740 of yacc.c  */
-#line 1154 "src/parse-gram.c"
+#line 1147 "src/parse-gram.c"
         break;
 
             case 55: // "%param"
-
 /* Line 740 of yacc.c  */
-#line 250 "src/parse-gram.y"
+#line 251 "src/parse-gram.y"
         {
   switch (((*yyvaluep).param))
     {
@@ -1170,77 +1162,85 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
     }
 }
 /* Line 740 of yacc.c  */
-#line 1174 "src/parse-gram.c"
+#line 1166 "src/parse-gram.c"
         break;
 
-            case 72: // symbol.prec
-
+            case 64: // code_props_type
 /* Line 740 of yacc.c  */
-#line 210 "src/parse-gram.y"
-        { fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); }
+#line 421 "src/parse-gram.y"
+        { fprintf (yyo, "%s", code_props_type_string (((*yyvaluep).code_type))); }
 /* Line 740 of yacc.c  */
-#line 1183 "src/parse-gram.c"
+#line 1174 "src/parse-gram.c"
         break;
 
-            case 85: // variable
-
+            case 73: // symbol.prec
 /* Line 740 of yacc.c  */
-#line 200 "src/parse-gram.y"
-        { fputs (((*yyvaluep).uniqstr), stderr); }
+#line 211 "src/parse-gram.y"
+        { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
 /* Line 740 of yacc.c  */
-#line 1192 "src/parse-gram.c"
+#line 1182 "src/parse-gram.c"
         break;
 
-            case 86: // content.opt
-
+            case 77: // tag
 /* Line 740 of yacc.c  */
-#line 196 "src/parse-gram.y"
-        { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); }
+#line 205 "src/parse-gram.y"
+        { fprintf (yyo, "<%s>", ((*yyvaluep).uniqstr)); }
 /* Line 740 of yacc.c  */
-#line 1201 "src/parse-gram.c"
+#line 1190 "src/parse-gram.c"
         break;
 
-            case 87: // braceless
-
+            case 87: // variable
 /* Line 740 of yacc.c  */
-#line 196 "src/parse-gram.y"
-        { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); }
+#line 201 "src/parse-gram.y"
+        { fputs (((*yyvaluep).uniqstr), yyo); }
 /* Line 740 of yacc.c  */
-#line 1210 "src/parse-gram.c"
+#line 1198 "src/parse-gram.c"
         break;
 
-            case 88: // id
-
+            case 88: // content.opt
 /* Line 740 of yacc.c  */
-#line 210 "src/parse-gram.y"
-        { fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); }
+#line 197 "src/parse-gram.y"
+        { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).chars)); }
 /* Line 740 of yacc.c  */
-#line 1219 "src/parse-gram.c"
+#line 1206 "src/parse-gram.c"
         break;
 
-            case 89: // id_colon
+            case 89: // braceless
+/* Line 740 of yacc.c  */
+#line 197 "src/parse-gram.y"
+        { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).chars)); }
+/* Line 740 of yacc.c  */
+#line 1214 "src/parse-gram.c"
+        break;
 
+            case 90: // id
 /* Line 740 of yacc.c  */
 #line 211 "src/parse-gram.y"
-        { fprintf (stderr, "%s:", ((*yyvaluep).symbol)->tag); }
+        { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
 /* Line 740 of yacc.c  */
-#line 1228 "src/parse-gram.c"
+#line 1222 "src/parse-gram.c"
         break;
 
-            case 90: // symbol
-
+            case 91: // id_colon
 /* Line 740 of yacc.c  */
-#line 210 "src/parse-gram.y"
-        { fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); }
+#line 212 "src/parse-gram.y"
+        { fprintf (yyo, "%s:", ((*yyvaluep).symbol)->tag); }
 /* Line 740 of yacc.c  */
-#line 1237 "src/parse-gram.c"
+#line 1230 "src/parse-gram.c"
         break;
 
-            case 91: // string_as_id
+            case 92: // symbol
+/* Line 740 of yacc.c  */
+#line 211 "src/parse-gram.y"
+        { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
+/* Line 740 of yacc.c  */
+#line 1238 "src/parse-gram.c"
+        break;
 
+            case 93: // string_as_id
 /* Line 740 of yacc.c  */
-#line 210 "src/parse-gram.y"
-        { fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); }
+#line 211 "src/parse-gram.y"
+        { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
 /* Line 740 of yacc.c  */
 #line 1246 "src/parse-gram.c"
         break;
@@ -2020,7 +2020,7 @@ YYLTYPE yylloc;
 
 /* User initialization code.  */
 /* Line 1505 of yacc.c  */
-#line 99 "src/parse-gram.y"
+#line 100 "src/parse-gram.y"
 {
   /* Bison's grammar can initial empty locations, hence a default
      location is needed. */
@@ -2222,7 +2222,7 @@ yyreduce:
       {
           case 6:
 /* Line 1721 of yacc.c  */
-#line 286 "src/parse-gram.y"
+#line 287 "src/parse-gram.y"
     {
       code_props plain_code;
       code_props_plain_init (&plain_code, (yyvsp[0].chars), (yylsp[0]));
@@ -2238,7 +2238,7 @@ yyreduce:
 
   case 7:
 /* Line 1721 of yacc.c  */
-#line 296 "src/parse-gram.y"
+#line 297 "src/parse-gram.y"
     {
       muscle_percent_define_ensure ((yyvsp[0].uniqstr), (yylsp[0]), true);
     }
@@ -2248,7 +2248,7 @@ yyreduce:
 
   case 8:
 /* Line 1721 of yacc.c  */
-#line 300 "src/parse-gram.y"
+#line 301 "src/parse-gram.y"
     {
       muscle_percent_define_insert ((yyvsp[-1].uniqstr), (yylsp[-1]), (yyvsp[0].chars),
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
@@ -2259,7 +2259,7 @@ yyreduce:
 
   case 9:
 /* Line 1721 of yacc.c  */
-#line 304 "src/parse-gram.y"
+#line 305 "src/parse-gram.y"
     { defines_flag = true; }
 /* Line 1721 of yacc.c  */
 #line 2266 "src/parse-gram.c"
@@ -2267,7 +2267,7 @@ yyreduce:
 
   case 10:
 /* Line 1721 of yacc.c  */
-#line 306 "src/parse-gram.y"
+#line 307 "src/parse-gram.y"
     {
       defines_flag = true;
       spec_defines_file = xstrdup ((yyvsp[0].chars));
@@ -2278,7 +2278,7 @@ yyreduce:
 
   case 11:
 /* Line 1721 of yacc.c  */
-#line 311 "src/parse-gram.y"
+#line 312 "src/parse-gram.y"
     {
       muscle_percent_define_insert ("parse.error", (yylsp[0]), "verbose",
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
@@ -2289,7 +2289,7 @@ yyreduce:
 
   case 12:
 /* Line 1721 of yacc.c  */
-#line 315 "src/parse-gram.y"
+#line 316 "src/parse-gram.y"
     { expected_sr_conflicts = (yyvsp[0].integer); }
 /* Line 1721 of yacc.c  */
 #line 2296 "src/parse-gram.c"
@@ -2297,7 +2297,7 @@ yyreduce:
 
   case 13:
 /* Line 1721 of yacc.c  */
-#line 316 "src/parse-gram.y"
+#line 317 "src/parse-gram.y"
     { expected_rr_conflicts = (yyvsp[0].integer); }
 /* Line 1721 of yacc.c  */
 #line 2304 "src/parse-gram.c"
@@ -2305,7 +2305,7 @@ yyreduce:
 
   case 14:
 /* Line 1721 of yacc.c  */
-#line 317 "src/parse-gram.y"
+#line 318 "src/parse-gram.y"
     { spec_file_prefix = (yyvsp[0].chars); }
 /* Line 1721 of yacc.c  */
 #line 2312 "src/parse-gram.c"
@@ -2313,7 +2313,7 @@ yyreduce:
 
   case 15:
 /* Line 1721 of yacc.c  */
-#line 318 "src/parse-gram.y"
+#line 319 "src/parse-gram.y"
     { spec_file_prefix = (yyvsp[0].chars); }
 /* Line 1721 of yacc.c  */
 #line 2320 "src/parse-gram.c"
@@ -2321,7 +2321,7 @@ yyreduce:
 
   case 16:
 /* Line 1721 of yacc.c  */
-#line 320 "src/parse-gram.y"
+#line 321 "src/parse-gram.y"
     {
       nondeterministic_parser = true;
       glr_parser = true;
@@ -2332,7 +2332,7 @@ yyreduce:
 
   case 17:
 /* Line 1721 of yacc.c  */
-#line 325 "src/parse-gram.y"
+#line 326 "src/parse-gram.y"
     {
       code_props action;
       code_props_symbol_action_init (&action, (yyvsp[0].code), (yylsp[0]));
@@ -2347,7 +2347,7 @@ yyreduce:
 
   case 18:
 /* Line 1721 of yacc.c  */
-#line 333 "src/parse-gram.y"
+#line 334 "src/parse-gram.y"
     { language_argmatch ((yyvsp[0].chars), grammar_prio, (yylsp[-1])); }
 /* Line 1721 of yacc.c  */
 #line 2354 "src/parse-gram.c"
@@ -2355,7 +2355,7 @@ yyreduce:
 
   case 19:
 /* Line 1721 of yacc.c  */
-#line 334 "src/parse-gram.y"
+#line 335 "src/parse-gram.y"
     { spec_name_prefix = (yyvsp[0].chars); }
 /* Line 1721 of yacc.c  */
 #line 2362 "src/parse-gram.c"
@@ -2363,7 +2363,7 @@ yyreduce:
 
   case 20:
 /* Line 1721 of yacc.c  */
-#line 335 "src/parse-gram.y"
+#line 336 "src/parse-gram.y"
     { spec_name_prefix = (yyvsp[0].chars); }
 /* Line 1721 of yacc.c  */
 #line 2370 "src/parse-gram.c"
@@ -2371,7 +2371,7 @@ yyreduce:
 
   case 21:
 /* Line 1721 of yacc.c  */
-#line 336 "src/parse-gram.y"
+#line 337 "src/parse-gram.y"
     { no_lines_flag = true; }
 /* Line 1721 of yacc.c  */
 #line 2378 "src/parse-gram.c"
@@ -2379,7 +2379,7 @@ yyreduce:
 
   case 22:
 /* Line 1721 of yacc.c  */
-#line 337 "src/parse-gram.y"
+#line 338 "src/parse-gram.y"
     { nondeterministic_parser = true; }
 /* Line 1721 of yacc.c  */
 #line 2386 "src/parse-gram.c"
@@ -2387,7 +2387,7 @@ yyreduce:
 
   case 23:
 /* Line 1721 of yacc.c  */
-#line 338 "src/parse-gram.y"
+#line 339 "src/parse-gram.y"
     { spec_outfile = (yyvsp[0].chars); }
 /* Line 1721 of yacc.c  */
 #line 2394 "src/parse-gram.c"
@@ -2395,7 +2395,7 @@ yyreduce:
 
   case 24:
 /* Line 1721 of yacc.c  */
-#line 339 "src/parse-gram.y"
+#line 340 "src/parse-gram.y"
     { spec_outfile = (yyvsp[0].chars); }
 /* Line 1721 of yacc.c  */
 #line 2402 "src/parse-gram.c"
@@ -2403,7 +2403,7 @@ yyreduce:
 
   case 25:
 /* Line 1721 of yacc.c  */
-#line 340 "src/parse-gram.y"
+#line 341 "src/parse-gram.y"
     { current_param = (yyvsp[0].param); }
 /* Line 1721 of yacc.c  */
 #line 2410 "src/parse-gram.c"
@@ -2411,7 +2411,7 @@ yyreduce:
 
   case 26:
 /* Line 1721 of yacc.c  */
-#line 340 "src/parse-gram.y"
+#line 341 "src/parse-gram.y"
     { current_param = param_none; }
 /* Line 1721 of yacc.c  */
 #line 2418 "src/parse-gram.c"
@@ -2419,7 +2419,7 @@ yyreduce:
 
   case 27:
 /* Line 1721 of yacc.c  */
-#line 341 "src/parse-gram.y"
+#line 342 "src/parse-gram.y"
     { version_check (&(yylsp[0]), (yyvsp[0].chars)); }
 /* Line 1721 of yacc.c  */
 #line 2426 "src/parse-gram.c"
@@ -2427,7 +2427,7 @@ yyreduce:
 
   case 28:
 /* Line 1721 of yacc.c  */
-#line 343 "src/parse-gram.y"
+#line 344 "src/parse-gram.y"
     {
       char const *skeleton_user = (yyvsp[0].chars);
       if (strchr (skeleton_user, '/'))
@@ -2457,7 +2457,7 @@ yyreduce:
 
   case 29:
 /* Line 1721 of yacc.c  */
-#line 366 "src/parse-gram.y"
+#line 367 "src/parse-gram.y"
     { token_table_flag = true; }
 /* Line 1721 of yacc.c  */
 #line 2464 "src/parse-gram.c"
@@ -2465,7 +2465,7 @@ yyreduce:
 
   case 30:
 /* Line 1721 of yacc.c  */
-#line 367 "src/parse-gram.y"
+#line 368 "src/parse-gram.y"
     { report_flag |= report_states; }
 /* Line 1721 of yacc.c  */
 #line 2472 "src/parse-gram.c"
@@ -2473,7 +2473,7 @@ yyreduce:
 
   case 31:
 /* Line 1721 of yacc.c  */
-#line 368 "src/parse-gram.y"
+#line 369 "src/parse-gram.y"
     { yacc_flag = true; }
 /* Line 1721 of yacc.c  */
 #line 2480 "src/parse-gram.c"
@@ -2481,7 +2481,7 @@ yyreduce:
 
   case 33:
 /* Line 1721 of yacc.c  */
-#line 373 "src/parse-gram.y"
+#line 374 "src/parse-gram.y"
     { add_param (current_param, (yyvsp[0].code), (yylsp[0])); }
 /* Line 1721 of yacc.c  */
 #line 2488 "src/parse-gram.c"
@@ -2489,7 +2489,7 @@ yyreduce:
 
   case 34:
 /* Line 1721 of yacc.c  */
-#line 374 "src/parse-gram.y"
+#line 375 "src/parse-gram.y"
     { add_param (current_param, (yyvsp[0].code), (yylsp[0])); }
 /* Line 1721 of yacc.c  */
 #line 2496 "src/parse-gram.c"
@@ -2497,7 +2497,7 @@ yyreduce:
 
   case 37:
 /* Line 1721 of yacc.c  */
-#line 386 "src/parse-gram.y"
+#line 387 "src/parse-gram.y"
     {
       grammar_start_symbol_set ((yyvsp[0].symbol), (yylsp[0]));
     }
@@ -2507,11 +2507,11 @@ yyreduce:
 
   case 38:
 /* Line 1721 of yacc.c  */
-#line 390 "src/parse-gram.y"
+#line 391 "src/parse-gram.y"
     {
       symbol_list *list;
       for (list = (yyvsp[0].list); list; list = list->next)
-        symbol_list_code_props_set (list, destructor, (yylsp[-1]), (yyvsp[-1].code));
+        symbol_list_code_props_set (list, (yyvsp[-2].code_type), (yylsp[-1]), (yyvsp[-1].code));
       symbol_list_free ((yyvsp[0].list));
     }
 /* Line 1721 of yacc.c  */
@@ -2520,32 +2520,32 @@ yyreduce:
 
   case 39:
 /* Line 1721 of yacc.c  */
-#line 397 "src/parse-gram.y"
+#line 398 "src/parse-gram.y"
     {
-      symbol_list *list;
-      for (list = (yyvsp[0].list); list; list = list->next)
-        symbol_list_code_props_set (list, printer, (yylsp[-1]), (yyvsp[-1].code));
-      symbol_list_free ((yyvsp[0].list));
+      default_prec = true;
     }
 /* Line 1721 of yacc.c  */
-#line 2532 "src/parse-gram.c"
+#line 2529 "src/parse-gram.c"
     break;
 
   case 40:
 /* Line 1721 of yacc.c  */
-#line 404 "src/parse-gram.y"
+#line 402 "src/parse-gram.y"
     {
-      default_prec = true;
+      default_prec = false;
     }
 /* Line 1721 of yacc.c  */
-#line 2542 "src/parse-gram.c"
+#line 2539 "src/parse-gram.c"
     break;
 
   case 41:
 /* Line 1721 of yacc.c  */
-#line 408 "src/parse-gram.y"
+#line 406 "src/parse-gram.y"
     {
-      default_prec = false;
+      /* Do not invoke muscle_percent_code_grow here since it invokes
+         muscle_user_name_list_grow.  */
+      muscle_code_grow ("percent_code()", (yyvsp[0].chars), (yylsp[0]));
+      code_scanner_last_string_free ();
     }
 /* Line 1721 of yacc.c  */
 #line 2552 "src/parse-gram.c"
@@ -2553,97 +2553,100 @@ yyreduce:
 
   case 42:
 /* Line 1721 of yacc.c  */
-#line 412 "src/parse-gram.y"
+#line 413 "src/parse-gram.y"
     {
-      /* Do not invoke muscle_percent_code_grow here since it invokes
-         muscle_user_name_list_grow.  */
-      muscle_code_grow ("percent_code()", (yyvsp[0].chars), (yylsp[0]));
+      muscle_percent_code_grow ((yyvsp[-1].uniqstr), (yylsp[-1]), (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
 /* Line 1721 of yacc.c  */
-#line 2565 "src/parse-gram.c"
+#line 2563 "src/parse-gram.c"
     break;
 
   case 43:
 /* Line 1721 of yacc.c  */
-#line 419 "src/parse-gram.y"
-    {
-      muscle_percent_code_grow ((yyvsp[-1].uniqstr), (yylsp[-1]), (yyvsp[0].chars), (yylsp[0]));
-      code_scanner_last_string_free ();
-    }
+#line 423 "src/parse-gram.y"
+    { (yyval.code_type) = destructor; }
 /* Line 1721 of yacc.c  */
-#line 2576 "src/parse-gram.c"
+#line 2571 "src/parse-gram.c"
     break;
 
   case 44:
 /* Line 1721 of yacc.c  */
-#line 433 "src/parse-gram.y"
-    {}
+#line 424 "src/parse-gram.y"
+    { (yyval.code_type) = printer; }
 /* Line 1721 of yacc.c  */
-#line 2584 "src/parse-gram.c"
+#line 2579 "src/parse-gram.c"
     break;
 
   case 45:
 /* Line 1721 of yacc.c  */
 #line 434 "src/parse-gram.y"
-    { muscle_code_grow ("union_name", (yyvsp[0].uniqstr), (yylsp[0])); }
+    {}
 /* Line 1721 of yacc.c  */
-#line 2592 "src/parse-gram.c"
+#line 2587 "src/parse-gram.c"
     break;
 
   case 46:
 /* Line 1721 of yacc.c  */
-#line 439 "src/parse-gram.y"
+#line 435 "src/parse-gram.y"
+    { muscle_code_grow ("union_name", (yyvsp[0].uniqstr), (yylsp[0])); }
+/* Line 1721 of yacc.c  */
+#line 2595 "src/parse-gram.c"
+    break;
+
+  case 47:
+/* Line 1721 of yacc.c  */
+#line 440 "src/parse-gram.y"
     {
       union_seen = true;
       muscle_code_grow ("stype", (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
 /* Line 1721 of yacc.c  */
-#line 2604 "src/parse-gram.c"
+#line 2607 "src/parse-gram.c"
     break;
 
-  case 47:
+  case 48:
 /* Line 1721 of yacc.c  */
-#line 450 "src/parse-gram.y"
+#line 451 "src/parse-gram.y"
     { current_class = nterm_sym; }
 /* Line 1721 of yacc.c  */
-#line 2612 "src/parse-gram.c"
+#line 2615 "src/parse-gram.c"
     break;
 
-  case 48:
+  case 49:
 /* Line 1721 of yacc.c  */
-#line 451 "src/parse-gram.y"
+#line 452 "src/parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
 /* Line 1721 of yacc.c  */
-#line 2623 "src/parse-gram.c"
+#line 2626 "src/parse-gram.c"
     break;
 
-  case 49:
+  case 50:
 /* Line 1721 of yacc.c  */
-#line 455 "src/parse-gram.y"
+#line 456 "src/parse-gram.y"
     { current_class = token_sym; }
 /* Line 1721 of yacc.c  */
-#line 2631 "src/parse-gram.c"
+#line 2634 "src/parse-gram.c"
     break;
 
-  case 50:
+  case 51:
 /* Line 1721 of yacc.c  */
-#line 456 "src/parse-gram.y"
+#line 457 "src/parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
 /* Line 1721 of yacc.c  */
-#line 2642 "src/parse-gram.c"
+#line 2645 "src/parse-gram.c"
     break;
 
-  case 51:
+  case 52:
 /* Line 1721 of yacc.c  */
-#line 461 "src/parse-gram.y"
+#line 462 "src/parse-gram.y"
     {
       symbol_list *list;
       tag_seen = true;
@@ -2652,12 +2655,12 @@ yyreduce:
       symbol_list_free ((yyvsp[0].list));
     }
 /* Line 1721 of yacc.c  */
-#line 2656 "src/parse-gram.c"
+#line 2659 "src/parse-gram.c"
     break;
 
-  case 52:
+  case 53:
 /* Line 1721 of yacc.c  */
-#line 472 "src/parse-gram.y"
+#line 473 "src/parse-gram.y"
     {
       symbol_list *list;
       ++current_prec;
@@ -2670,202 +2673,202 @@ yyreduce:
       current_type = NULL;
     }
 /* Line 1721 of yacc.c  */
-#line 2674 "src/parse-gram.c"
-    break;
-
-  case 53:
-/* Line 1721 of yacc.c  */
-#line 486 "src/parse-gram.y"
-    { (yyval.assoc) = left_assoc; }
-/* Line 1721 of yacc.c  */
-#line 2682 "src/parse-gram.c"
+#line 2677 "src/parse-gram.c"
     break;
 
   case 54:
 /* Line 1721 of yacc.c  */
 #line 487 "src/parse-gram.y"
-    { (yyval.assoc) = right_assoc; }
+    { (yyval.assoc) = left_assoc; }
 /* Line 1721 of yacc.c  */
-#line 2690 "src/parse-gram.c"
+#line 2685 "src/parse-gram.c"
     break;
 
   case 55:
 /* Line 1721 of yacc.c  */
 #line 488 "src/parse-gram.y"
-    { (yyval.assoc) = non_assoc; }
+    { (yyval.assoc) = right_assoc; }
 /* Line 1721 of yacc.c  */
-#line 2698 "src/parse-gram.c"
+#line 2693 "src/parse-gram.c"
     break;
 
   case 56:
 /* Line 1721 of yacc.c  */
 #line 489 "src/parse-gram.y"
-    { (yyval.assoc) = precedence_assoc; }
+    { (yyval.assoc) = non_assoc; }
 /* Line 1721 of yacc.c  */
-#line 2706 "src/parse-gram.c"
+#line 2701 "src/parse-gram.c"
     break;
 
   case 57:
 /* Line 1721 of yacc.c  */
-#line 493 "src/parse-gram.y"
-    { current_type = NULL; }
+#line 490 "src/parse-gram.y"
+    { (yyval.assoc) = precedence_assoc; }
 /* Line 1721 of yacc.c  */
-#line 2714 "src/parse-gram.c"
+#line 2709 "src/parse-gram.c"
     break;
 
   case 58:
 /* Line 1721 of yacc.c  */
 #line 494 "src/parse-gram.y"
-    { current_type = (yyvsp[0].uniqstr); tag_seen = true; }
+    { current_type = NULL; }
 /* Line 1721 of yacc.c  */
-#line 2722 "src/parse-gram.c"
+#line 2717 "src/parse-gram.c"
     break;
 
   case 59:
 /* Line 1721 of yacc.c  */
-#line 500 "src/parse-gram.y"
-    { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
+#line 495 "src/parse-gram.y"
+    { current_type = (yyvsp[0].uniqstr); tag_seen = true; }
 /* Line 1721 of yacc.c  */
-#line 2730 "src/parse-gram.c"
+#line 2725 "src/parse-gram.c"
     break;
 
   case 60:
 /* Line 1721 of yacc.c  */
-#line 502 "src/parse-gram.y"
-    { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
+#line 501 "src/parse-gram.y"
+    { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
 /* Line 1721 of yacc.c  */
-#line 2738 "src/parse-gram.c"
+#line 2733 "src/parse-gram.c"
     break;
 
   case 61:
 /* Line 1721 of yacc.c  */
-#line 506 "src/parse-gram.y"
-    { (yyval.symbol) = (yyvsp[0].symbol); }
+#line 503 "src/parse-gram.y"
+    { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
 /* Line 1721 of yacc.c  */
-#line 2746 "src/parse-gram.c"
+#line 2741 "src/parse-gram.c"
     break;
 
   case 62:
 /* Line 1721 of yacc.c  */
 #line 507 "src/parse-gram.y"
-    { (yyval.symbol) = (yyvsp[-1].symbol); symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0])); }
+    { (yyval.symbol) = (yyvsp[0].symbol); }
 /* Line 1721 of yacc.c  */
-#line 2754 "src/parse-gram.c"
+#line 2749 "src/parse-gram.c"
     break;
 
   case 63:
 /* Line 1721 of yacc.c  */
-#line 513 "src/parse-gram.y"
-    { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
+#line 508 "src/parse-gram.y"
+    { (yyval.symbol) = (yyvsp[-1].symbol); symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0])); }
 /* Line 1721 of yacc.c  */
-#line 2762 "src/parse-gram.c"
+#line 2757 "src/parse-gram.c"
     break;
 
   case 64:
 /* Line 1721 of yacc.c  */
-#line 515 "src/parse-gram.y"
-    { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
+#line 514 "src/parse-gram.y"
+    { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
 /* Line 1721 of yacc.c  */
-#line 2770 "src/parse-gram.c"
+#line 2765 "src/parse-gram.c"
     break;
 
   case 65:
 /* Line 1721 of yacc.c  */
-#line 519 "src/parse-gram.y"
-    { (yyval.list) = (yyvsp[0].list); }
+#line 516 "src/parse-gram.y"
+    { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
 /* Line 1721 of yacc.c  */
-#line 2778 "src/parse-gram.c"
+#line 2773 "src/parse-gram.c"
     break;
 
   case 66:
 /* Line 1721 of yacc.c  */
 #line 520 "src/parse-gram.y"
-    { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), (yyvsp[0].list)); }
+    { (yyval.list) = (yyvsp[0].list); }
 /* Line 1721 of yacc.c  */
-#line 2786 "src/parse-gram.c"
+#line 2781 "src/parse-gram.c"
     break;
 
   case 67:
 /* Line 1721 of yacc.c  */
-#line 524 "src/parse-gram.y"
-    { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
+#line 521 "src/parse-gram.y"
+    { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), (yyvsp[0].list)); }
 /* Line 1721 of yacc.c  */
-#line 2794 "src/parse-gram.c"
+#line 2789 "src/parse-gram.c"
     break;
 
   case 68:
 /* Line 1721 of yacc.c  */
 #line 525 "src/parse-gram.y"
-    { (yyval.list) = symbol_list_type_new ((yyvsp[0].uniqstr), (yylsp[0])); }
+    { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
 /* Line 1721 of yacc.c  */
-#line 2802 "src/parse-gram.c"
+#line 2797 "src/parse-gram.c"
     break;
 
   case 69:
 /* Line 1721 of yacc.c  */
 #line 526 "src/parse-gram.y"
-    { (yyval.list) = symbol_list_type_new ("*", (yylsp[0])); }
+    { (yyval.list) = symbol_list_type_new ((yyvsp[0].uniqstr), (yylsp[0])); }
 /* Line 1721 of yacc.c  */
-#line 2810 "src/parse-gram.c"
+#line 2805 "src/parse-gram.c"
     break;
 
-  case 70:
+  case 71:
 /* Line 1721 of yacc.c  */
-#line 527 "src/parse-gram.y"
-    { (yyval.list) = symbol_list_type_new ("", (yylsp[0])); }
+#line 531 "src/parse-gram.y"
+    { (yyval.uniqstr) = uniqstr_new ("*"); }
 /* Line 1721 of yacc.c  */
-#line 2818 "src/parse-gram.c"
+#line 2813 "src/parse-gram.c"
     break;
 
-  case 71:
+  case 72:
+/* Line 1721 of yacc.c  */
+#line 532 "src/parse-gram.y"
+    { (yyval.uniqstr) = uniqstr_new (""); }
 /* Line 1721 of yacc.c  */
-#line 533 "src/parse-gram.y"
+#line 2821 "src/parse-gram.c"
+    break;
+
+  case 73:
+/* Line 1721 of yacc.c  */
+#line 538 "src/parse-gram.y"
     {
        current_type = (yyvsp[0].uniqstr);
        tag_seen = true;
      }
 /* Line 1721 of yacc.c  */
-#line 2829 "src/parse-gram.c"
+#line 2832 "src/parse-gram.c"
     break;
 
-  case 72:
+  case 74:
 /* Line 1721 of yacc.c  */
-#line 538 "src/parse-gram.y"
+#line 543 "src/parse-gram.y"
     {
        symbol_class_set ((yyvsp[0].symbol), current_class, (yylsp[0]), true);
        symbol_type_set ((yyvsp[0].symbol), current_type, (yylsp[0]));
      }
 /* Line 1721 of yacc.c  */
-#line 2840 "src/parse-gram.c"
+#line 2843 "src/parse-gram.c"
     break;
 
-  case 73:
+  case 75:
 /* Line 1721 of yacc.c  */
-#line 543 "src/parse-gram.y"
+#line 548 "src/parse-gram.y"
     {
       symbol_class_set ((yyvsp[-1].symbol), current_class, (yylsp[-1]), true);
       symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
       symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0]));
     }
 /* Line 1721 of yacc.c  */
-#line 2852 "src/parse-gram.c"
+#line 2855 "src/parse-gram.c"
     break;
 
-  case 74:
+  case 76:
 /* Line 1721 of yacc.c  */
-#line 549 "src/parse-gram.y"
+#line 554 "src/parse-gram.y"
     {
       symbol_class_set ((yyvsp[-1].symbol), current_class, (yylsp[-1]), true);
       symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
       symbol_make_alias ((yyvsp[-1].symbol), (yyvsp[0].symbol), (yyloc));
     }
 /* Line 1721 of yacc.c  */
-#line 2864 "src/parse-gram.c"
+#line 2867 "src/parse-gram.c"
     break;
 
-  case 75:
+  case 77:
 /* Line 1721 of yacc.c  */
-#line 555 "src/parse-gram.y"
+#line 560 "src/parse-gram.y"
     {
       symbol_class_set ((yyvsp[-2].symbol), current_class, (yylsp[-2]), true);
       symbol_type_set ((yyvsp[-2].symbol), current_type, (yylsp[-2]));
@@ -2873,154 +2876,154 @@ yyreduce:
       symbol_make_alias ((yyvsp[-2].symbol), (yyvsp[0].symbol), (yyloc));
     }
 /* Line 1721 of yacc.c  */
-#line 2877 "src/parse-gram.c"
+#line 2880 "src/parse-gram.c"
     break;
 
-  case 82:
+  case 84:
 /* Line 1721 of yacc.c  */
-#line 585 "src/parse-gram.y"
+#line 590 "src/parse-gram.y"
     {
       yyerrok;
     }
 /* Line 1721 of yacc.c  */
-#line 2887 "src/parse-gram.c"
+#line 2890 "src/parse-gram.c"
     break;
 
-  case 83:
+  case 85:
 /* Line 1721 of yacc.c  */
-#line 591 "src/parse-gram.y"
+#line 596 "src/parse-gram.y"
     { current_lhs ((yyvsp[-1].symbol), (yylsp[-1]), (yyvsp[0].named_ref)); }
 /* Line 1721 of yacc.c  */
-#line 2895 "src/parse-gram.c"
+#line 2898 "src/parse-gram.c"
     break;
 
-  case 84:
+  case 86:
 /* Line 1721 of yacc.c  */
-#line 592 "src/parse-gram.y"
+#line 597 "src/parse-gram.y"
     {
     /* Free the current lhs. */
     current_lhs (0, (yylsp[-3]), 0);
   }
 /* Line 1721 of yacc.c  */
-#line 2906 "src/parse-gram.c"
+#line 2909 "src/parse-gram.c"
     break;
 
-  case 85:
+  case 87:
 /* Line 1721 of yacc.c  */
-#line 599 "src/parse-gram.y"
+#line 604 "src/parse-gram.y"
     { grammar_current_rule_end ((yylsp[0])); }
 /* Line 1721 of yacc.c  */
-#line 2914 "src/parse-gram.c"
+#line 2917 "src/parse-gram.c"
     break;
 
-  case 86:
+  case 88:
 /* Line 1721 of yacc.c  */
-#line 600 "src/parse-gram.y"
+#line 605 "src/parse-gram.y"
     { grammar_current_rule_end ((yylsp[0])); }
 /* Line 1721 of yacc.c  */
-#line 2922 "src/parse-gram.c"
+#line 2925 "src/parse-gram.c"
     break;
 
-  case 88:
+  case 90:
 /* Line 1721 of yacc.c  */
-#line 606 "src/parse-gram.y"
+#line 611 "src/parse-gram.y"
     { grammar_current_rule_begin (current_lhs_symbol, current_lhs_location,
                                   current_lhs_named_ref); }
 /* Line 1721 of yacc.c  */
-#line 2931 "src/parse-gram.c"
+#line 2934 "src/parse-gram.c"
     break;
 
-  case 89:
+  case 91:
 /* Line 1721 of yacc.c  */
-#line 609 "src/parse-gram.y"
+#line 614 "src/parse-gram.y"
     { grammar_current_rule_symbol_append ((yyvsp[-1].symbol), (yylsp[-1]), (yyvsp[0].named_ref)); }
 /* Line 1721 of yacc.c  */
-#line 2939 "src/parse-gram.c"
+#line 2942 "src/parse-gram.c"
     break;
 
-  case 90:
+  case 92:
 /* Line 1721 of yacc.c  */
-#line 611 "src/parse-gram.y"
+#line 616 "src/parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[-1].code), (yylsp[-1]), (yyvsp[0].named_ref), false); }
 /* Line 1721 of yacc.c  */
-#line 2947 "src/parse-gram.c"
+#line 2950 "src/parse-gram.c"
     break;
 
-  case 91:
+  case 93:
 /* Line 1721 of yacc.c  */
-#line 613 "src/parse-gram.y"
+#line 618 "src/parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[0].code), (yylsp[0]), NULL, true); }
 /* Line 1721 of yacc.c  */
-#line 2955 "src/parse-gram.c"
+#line 2958 "src/parse-gram.c"
     break;
 
-  case 92:
+  case 94:
 /* Line 1721 of yacc.c  */
-#line 615 "src/parse-gram.y"
+#line 620 "src/parse-gram.y"
     { grammar_current_rule_prec_set ((yyvsp[0].symbol), (yylsp[0])); }
 /* Line 1721 of yacc.c  */
-#line 2963 "src/parse-gram.c"
+#line 2966 "src/parse-gram.c"
     break;
 
-  case 93:
+  case 95:
 /* Line 1721 of yacc.c  */
-#line 617 "src/parse-gram.y"
+#line 622 "src/parse-gram.y"
     { grammar_current_rule_dprec_set ((yyvsp[0].integer), (yylsp[0])); }
 /* Line 1721 of yacc.c  */
-#line 2971 "src/parse-gram.c"
+#line 2974 "src/parse-gram.c"
     break;
 
-  case 94:
+  case 96:
 /* Line 1721 of yacc.c  */
-#line 619 "src/parse-gram.y"
+#line 624 "src/parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[0].uniqstr), (yylsp[0])); }
 /* Line 1721 of yacc.c  */
-#line 2979 "src/parse-gram.c"
+#line 2982 "src/parse-gram.c"
     break;
 
-  case 95:
+  case 97:
 /* Line 1721 of yacc.c  */
-#line 623 "src/parse-gram.y"
+#line 628 "src/parse-gram.y"
     { (yyval.named_ref) = 0; }
 /* Line 1721 of yacc.c  */
-#line 2987 "src/parse-gram.c"
+#line 2990 "src/parse-gram.c"
     break;
 
-  case 96:
+  case 98:
 /* Line 1721 of yacc.c  */
-#line 625 "src/parse-gram.y"
+#line 630 "src/parse-gram.y"
     { (yyval.named_ref) = named_ref_new((yyvsp[0].uniqstr), (yylsp[0])); }
 /* Line 1721 of yacc.c  */
-#line 2995 "src/parse-gram.c"
+#line 2998 "src/parse-gram.c"
     break;
 
-  case 98:
+  case 100:
 /* Line 1721 of yacc.c  */
-#line 636 "src/parse-gram.y"
+#line 641 "src/parse-gram.y"
     { (yyval.uniqstr) = uniqstr_new ((yyvsp[0].chars)); }
 /* Line 1721 of yacc.c  */
-#line 3003 "src/parse-gram.c"
+#line 3006 "src/parse-gram.c"
     break;
 
-  case 99:
+  case 101:
 /* Line 1721 of yacc.c  */
-#line 641 "src/parse-gram.y"
+#line 646 "src/parse-gram.y"
     { (yyval.chars) = ""; }
 /* Line 1721 of yacc.c  */
-#line 3011 "src/parse-gram.c"
+#line 3014 "src/parse-gram.c"
     break;
 
-  case 100:
+  case 102:
 /* Line 1721 of yacc.c  */
-#line 642 "src/parse-gram.y"
+#line 647 "src/parse-gram.y"
     { (yyval.chars) = (yyvsp[0].uniqstr); }
 /* Line 1721 of yacc.c  */
-#line 3019 "src/parse-gram.c"
+#line 3022 "src/parse-gram.c"
     break;
 
-  case 102:
+  case 104:
 /* Line 1721 of yacc.c  */
-#line 653 "src/parse-gram.y"
+#line 658 "src/parse-gram.y"
     {
       code_props plain_code;
       (yyvsp[0].code)[strlen ((yyvsp[0].code)) - 1] = '\n';
@@ -3030,51 +3033,51 @@ yyreduce:
       (yyval.chars) = plain_code.code;
     }
 /* Line 1721 of yacc.c  */
-#line 3034 "src/parse-gram.c"
+#line 3037 "src/parse-gram.c"
     break;
 
-  case 103:
+  case 105:
 /* Line 1721 of yacc.c  */
-#line 673 "src/parse-gram.y"
+#line 678 "src/parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
 /* Line 1721 of yacc.c  */
-#line 3042 "src/parse-gram.c"
+#line 3045 "src/parse-gram.c"
     break;
 
-  case 104:
+  case 106:
 /* Line 1721 of yacc.c  */
-#line 675 "src/parse-gram.y"
+#line 680 "src/parse-gram.y"
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[0].character)), (yylsp[0]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
       symbol_user_token_number_set ((yyval.symbol), (yyvsp[0].character), (yylsp[0]));
     }
 /* Line 1721 of yacc.c  */
-#line 3054 "src/parse-gram.c"
+#line 3057 "src/parse-gram.c"
     break;
 
-  case 105:
+  case 107:
 /* Line 1721 of yacc.c  */
-#line 683 "src/parse-gram.y"
+#line 688 "src/parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
 /* Line 1721 of yacc.c  */
-#line 3062 "src/parse-gram.c"
+#line 3065 "src/parse-gram.c"
     break;
 
-  case 108:
+  case 110:
 /* Line 1721 of yacc.c  */
-#line 695 "src/parse-gram.y"
+#line 700 "src/parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[0].chars)), (yylsp[0]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
     }
 /* Line 1721 of yacc.c  */
-#line 3073 "src/parse-gram.c"
+#line 3076 "src/parse-gram.c"
     break;
 
-  case 110:
+  case 112:
 /* Line 1721 of yacc.c  */
-#line 704 "src/parse-gram.y"
+#line 709 "src/parse-gram.y"
     {
       code_props plain_code;
       code_props_plain_init (&plain_code, (yyvsp[0].chars), (yylsp[0]));
@@ -3084,12 +3087,12 @@ yyreduce:
       code_scanner_last_string_free ();
     }
 /* Line 1721 of yacc.c  */
-#line 3088 "src/parse-gram.c"
+#line 3091 "src/parse-gram.c"
     break;
 
 
 /* Line 1721 of yacc.c  */
-#line 3093 "src/parse-gram.c"
+#line 3096 "src/parse-gram.c"
         default: break;
       }
     if (yychar_backup != yychar)
@@ -3337,7 +3340,7 @@ yyreturn:
 }
 
 /* Line 1981 of yacc.c  */
-#line 714 "src/parse-gram.y"
+#line 719 "src/parse-gram.y"
 
 
 
