@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 3.2.1.94-fe97.  */
+/* A Bison parser, made by GNU Bison 3.2.1.108-19b4e.  */
 
 /* Bison implementation for Yacc-like parsers in C
 
@@ -47,7 +47,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "3.2.1.94-fe97"
+#define YYBISON_VERSION "3.2.1.108-19b4e"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -133,7 +133,7 @@ extern int gram_debug;
     param_parse  = 1 << 1,
     param_both   = param_lex | param_parse
   } param_type;
-#line 602 "src/parse-gram.y" /* yacc.c:352  */
+#line 660 "src/parse-gram.y" /* yacc.c:352  */
 
   #include "muscle-tab.h"
   typedef struct
@@ -230,13 +230,15 @@ union GRAM_STYPE
   /* "integer"  */
   int INT;
   /* int.opt  */
-  int yytype_79;
+  int yytype_78;
   /* named_ref.opt  */
-  named_ref* yytype_87;
+  named_ref* yytype_90;
   /* "%param"  */
   param_type PERCENT_PARAM;
-  /* symbol.prec  */
-  symbol* yytype_73;
+  /* token_decl  */
+  symbol* token_decl;
+  /* token_decl_for_prec  */
+  symbol* token_decl_for_prec;
   /* id  */
   symbol* id;
   /* id_colon  */
@@ -246,15 +248,25 @@ union GRAM_STYPE
   /* string_as_id  */
   symbol* string_as_id;
   /* string_as_id.opt  */
-  symbol* yytype_94;
-  /* symbols.prec  */
-  symbol_list* yytype_72;
-  /* symbols.1  */
-  symbol_list* yytype_74;
+  symbol* yytype_97;
   /* generic_symlist  */
   symbol_list* generic_symlist;
   /* generic_symlist_item  */
   symbol_list* generic_symlist_item;
+  /* nterm_decls  */
+  symbol_list* nterm_decls;
+  /* token_decls  */
+  symbol_list* token_decls;
+  /* token_decl.1  */
+  symbol_list* yytype_76;
+  /* token_decls_for_prec  */
+  symbol_list* token_decls_for_prec;
+  /* token_decl_for_prec.1  */
+  symbol_list* yytype_80;
+  /* symbol_decls  */
+  symbol_list* symbol_decls;
+  /* symbol_decl.1  */
+  symbol_list* yytype_83;
   /* "%<flag>"  */
   uniqstr PERCENT_FLAG;
   /* "[identifier]"  */
@@ -266,7 +278,7 @@ union GRAM_STYPE
   /* "<tag>"  */
   uniqstr TAG;
   /* tag.opt  */
-  uniqstr yytype_71;
+  uniqstr yytype_70;
   /* tag  */
   uniqstr tag;
   /* variable  */
@@ -275,7 +287,7 @@ union GRAM_STYPE
   unsigned char CHAR;
   /* value  */
   value_type value;
-#line 279 "src/parse-gram.c" /* yacc.c:352  */
+#line 291 "src/parse-gram.c" /* yacc.c:352  */
 };
 
 typedef union GRAM_STYPE GRAM_STYPE;
@@ -328,7 +340,6 @@ int gram_parse (void);
   static named_ref *current_lhs_named_ref;
   static symbol *current_lhs_symbol;
   static symbol_class current_class = unknown_sym;
-  static uniqstr current_type = NULL;
 
   /** Set the new current left-hand side symbol, possibly common
    * to several right-hand side parts of rule.
@@ -384,7 +395,7 @@ int gram_parse (void);
   static void add_param (param_type type, char *decl, location loc);
   static param_type current_param = param_none;
 
-#line 388 "src/parse-gram.c" /* yacc.c:355  */
+#line 399 "src/parse-gram.c" /* yacc.c:355  */
 
 #ifdef short
 # undef short
@@ -596,16 +607,16 @@ union yyalloc
 /* YYFINAL -- State number of the termination state.  */
 #define YYFINAL  3
 /* YYLAST -- Last index in YYTABLE.  */
-#define YYLAST   213
+#define YYLAST   227
 
 /* YYNTOKENS -- Number of terminals.  */
 #define YYNTOKENS  57
 /* YYNNTS -- Number of nonterminals.  */
-#define YYNNTS  39
+#define YYNNTS  42
 /* YYNRULES -- Number of rules.  */
-#define YYNRULES  111
+#define YYNRULES  120
 /* YYNSTATES -- Number of states.  */
-#define YYNSTATES  150
+#define YYNSTATES  163
 
 #define YYUNDEFTOK  2
 #define YYMAXUTOK   311
@@ -660,15 +671,16 @@ static const yytype_uint16 yyrline[] =
        0,   260,   260,   269,   270,   274,   275,   281,   285,   290,
      291,   296,   297,   298,   299,   304,   309,   310,   311,   312,
      313,   314,   314,   315,   316,   317,   318,   319,   320,   321,
-     325,   326,   335,   336,   337,   341,   352,   356,   360,   368,
-     378,   379,   389,   390,   396,   408,   408,   413,   413,   418,
-     428,   441,   442,   443,   444,   448,   449,   454,   456,   461,
-     472,   474,   479,   480,   484,   485,   489,   490,   491,   496,
-     501,   514,   515,   520,   521,   533,   534,   540,   541,   542,
-     549,   549,   557,   558,   559,   564,   567,   569,   571,   573,
-     575,   577,   579,   581,   583,   588,   589,   598,   622,   623,
-     624,   625,   637,   639,   654,   659,   660,   665,   674,   675,
-     679,   680
+     325,   326,   335,   336,   340,   351,   355,   359,   367,   377,
+     378,   388,   389,   395,   408,   408,   413,   413,   418,   422,
+     432,   433,   434,   435,   439,   440,   445,   446,   450,   451,
+     455,   456,   457,   470,   479,   483,   487,   495,   496,   500,
+     513,   514,   526,   530,   534,   542,   544,   549,   556,   566,
+     570,   574,   582,   583,   591,   592,   598,   599,   600,   607,
+     607,   615,   616,   617,   622,   625,   627,   629,   631,   633,
+     635,   637,   639,   641,   646,   647,   656,   680,   681,   682,
+     683,   695,   697,   712,   717,   718,   723,   732,   733,   737,
+     738
 };
 #endif
 
@@ -693,12 +705,13 @@ static const char *const yytname[] =
   "\"%union\"", "\"%empty\"", "$accept", "input", "prologue_declarations",
   "prologue_declaration", "$@1", "params", "grammar_declaration",
   "code_props_type", "union_name", "symbol_declaration", "$@2", "$@3",
-  "precedence_declaration", "precedence_declarator", "tag.opt",
-  "symbols.prec", "symbol.prec", "symbols.1", "generic_symlist",
-  "generic_symlist_item", "tag", "symbol_def", "int.opt", "symbol_defs.1",
-  "grammar", "rules_or_grammar_declaration", "rules", "$@4", "rhses.1",
-  "rhs", "named_ref.opt", "variable", "value", "id", "id_colon", "symbol",
-  "string_as_id", "string_as_id.opt", "epilogue.opt", YY_NULLPTR
+  "precedence_declarator", "tag.opt", "generic_symlist",
+  "generic_symlist_item", "tag", "nterm_decls", "token_decls",
+  "token_decl.1", "token_decl", "int.opt", "token_decls_for_prec",
+  "token_decl_for_prec.1", "token_decl_for_prec", "symbol_decls",
+  "symbol_decl.1", "grammar", "rules_or_grammar_declaration", "rules",
+  "$@4", "rhses.1", "rhs", "named_ref.opt", "variable", "value", "id",
+  "id_colon", "symbol", "string_as_id", "string_as_id.opt", "epilogue.opt", YY_NULLPTR
 };
 #endif
 
@@ -716,12 +729,12 @@ static const yytype_uint16 yytoknum[] =
 };
 # endif
 
-#define YYPACT_NINF -119
+#define YYPACT_NINF -131
 
 #define yypact_value_is_default(Yystate) \
-  (!!((Yystate) == (-119)))
+  (!!((Yystate) == (-131)))
 
-#define YYTABLE_NINF -111
+#define YYTABLE_NINF -120
 
 #define yytable_value_is_error(Yytable_value) \
   0
@@ -730,21 +743,23 @@ static const yytype_uint16 yytoknum[] =
      STATE-NUM.  */
 static const yytype_int16 yypact[] =
 {
-    -119,     1,   106,  -119,   -47,  -119,  -119,   -44,  -119,  -119,
-    -119,  -119,  -119,  -119,   -17,  -119,   -28,    14,   -27,   -23,
-    -119,    22,  -119,     7,    36,    41,  -119,  -119,  -119,    52,
-      64,    70,    20,  -119,  -119,  -119,   158,  -119,  -119,  -119,
-      30,  -119,  -119,    37,  -119,  -119,    26,  -119,     6,     6,
-      20,  -119,    40,  -119,    25,  -119,  -119,  -119,  -119,  -119,
-    -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,
-    -119,    31,  -119,    33,     3,  -119,  -119,    39,    45,  -119,
-      46,     2,  -119,    20,  -119,  -119,     6,    32,     6,    20,
-    -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,    44,  -119,
-    -119,  -119,  -119,  -119,    49,  -119,  -119,  -119,  -119,     2,
-    -119,  -119,  -119,    20,  -119,    32,  -119,  -119,    85,  -119,
-    -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,    -9,    21,
-    -119,  -119,    20,    38,    42,    43,    48,  -119,  -119,    51,
-      39,    21,  -119,  -119,  -119,  -119,  -119,    39,  -119,  -119
+    -131,     5,   109,  -131,   -43,  -131,  -131,    30,  -131,  -131,
+    -131,  -131,  -131,  -131,    23,  -131,    -9,    33,   -14,     3,
+    -131,    56,  -131,    22,    60,    69,  -131,  -131,  -131,    70,
+      78,    79,    46,  -131,  -131,  -131,   161,  -131,  -131,  -131,
+      41,  -131,  -131,    63,  -131,    50,  -131,   -12,   -12,  -131,
+    -131,  -131,    46,    53,    46,  -131,  -131,  -131,  -131,    66,
+    -131,    24,  -131,  -131,  -131,  -131,  -131,  -131,  -131,  -131,
+    -131,  -131,  -131,    49,  -131,    57,     9,  -131,  -131,    65,
+      73,  -131,    85,    25,    46,    58,    46,  -131,    54,  -131,
+     -10,    74,   -10,  -131,    54,  -131,    74,    46,    46,  -131,
+    -131,  -131,  -131,  -131,  -131,  -131,  -131,   105,  -131,  -131,
+    -131,  -131,  -131,   110,  -131,  -131,  -131,  -131,    25,  -131,
+    -131,  -131,    46,    46,  -131,  -131,  -131,   -10,   -10,  -131,
+     146,    46,  -131,  -131,  -131,  -131,    46,   -10,  -131,  -131,
+      48,   171,  -131,  -131,    46,    97,   101,    99,   100,  -131,
+    -131,  -131,   116,    65,   171,  -131,  -131,  -131,  -131,  -131,
+      65,  -131,  -131
 };
 
   /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
@@ -752,39 +767,43 @@ static const yytype_int16 yypact[] =
      means the default is an error.  */
 static const yytype_uint8 yydefact[] =
 {
-       3,     0,     0,     1,     0,    47,    45,     0,    40,    41,
-      51,    52,    53,    54,     0,    36,     0,     9,     0,     0,
-       7,     0,    14,     0,     0,     0,    37,    18,    19,     0,
+       3,     0,     0,     1,     0,    46,    44,     0,    39,    40,
+      50,    51,    52,    53,     0,    35,     0,     9,     0,     0,
+       7,     0,    14,     0,     0,     0,    36,    18,    19,     0,
        0,     0,     0,    25,    26,    27,     0,     6,    29,    21,
-      42,     4,     5,     0,    33,    32,    55,    28,     0,     0,
-       0,    38,     0,    97,    98,    10,    11,    12,    13,    15,
-      16,    17,    20,    23,    24,   107,   103,   102,   105,    34,
-     106,     0,   104,     0,     0,    75,    77,    95,     0,    43,
-       0,     0,    56,     0,    69,    73,    48,    71,    46,    49,
-      60,    39,   100,   101,    99,     8,    79,    78,     0,    76,
-       2,    96,    80,    31,    22,    44,    66,    67,    68,    35,
-      62,    65,    64,    50,    57,    71,    74,    72,   108,    61,
-     111,    85,    30,    63,    58,    59,   109,    70,    81,    82,
-      85,    84,     0,     0,     0,     0,     0,    88,    89,     0,
-      95,    83,    90,    91,    92,    93,    94,    95,    86,    87
+      41,     4,     5,     0,    32,     0,    28,     0,     0,   116,
+     112,   111,     0,    48,    79,   114,    82,   115,    37,     0,
+     106,   107,    10,    11,    12,    13,    15,    16,    17,    20,
+      23,    24,    33,     0,   113,     0,     0,    84,    86,   104,
+       0,    42,     0,     0,     0,    49,    72,    75,    70,    78,
+       0,    47,    64,    67,    70,    45,    63,    80,     0,    83,
+      38,   109,   110,   108,     8,    88,    87,     0,    85,     2,
+     105,    89,    31,    22,    43,    60,    61,    62,    34,    56,
+      59,    58,    73,     0,    76,    71,    77,    65,     0,    68,
+     117,    81,   120,    94,    30,    57,    74,    66,   118,    69,
+      90,    91,    94,    93,     0,     0,     0,     0,     0,    97,
+      55,    98,     0,   104,    92,    99,   100,   101,   102,   103,
+     104,    95,    96
 };
 
   /* YYPGOTO[NTERM-NUM].  */
-static const yytype_int8 yypgoto[] =
+static const yytype_int16 yypgoto[] =
 {
-    -119,  -119,  -119,  -119,  -119,  -119,    88,  -119,  -119,  -119,
-    -119,  -119,  -119,  -119,    47,  -119,   -19,  -119,  -119,   -14,
-    -119,   -20,   -13,    50,  -119,    24,  -119,  -119,  -119,   -26,
-    -118,  -119,  -119,   -16,  -119,   -32,   -15,  -119,  -119
+    -131,  -131,  -131,  -131,  -131,  -131,   154,  -131,  -131,  -131,
+    -131,  -131,  -131,  -131,  -131,    42,  -131,  -131,   111,   -83,
+     -80,    67,  -131,   -82,   -78,  -131,   -28,  -131,   103,  -131,
+    -131,  -131,    34,  -130,  -131,  -131,   -44,  -131,   -32,   -34,
+    -131,  -131
 };
 
   /* YYDEFGOTO[NTERM-NUM].  */
 static const yytype_int16 yydefgoto[] =
 {
-      -1,     1,     2,    41,    78,   104,    73,    43,    80,    44,
-      49,    48,    45,    46,   139,   113,   114,    89,   109,   110,
-     111,    85,   118,    86,    74,    75,    76,   121,   128,   129,
-     102,    54,    95,    68,    77,   112,    70,   127,   100
+      -1,     1,     2,    41,    80,   113,    75,    43,    82,    44,
+      48,    47,    45,   152,   118,   119,   120,    95,    91,    92,
+      93,   126,    85,    86,    87,    53,    54,    76,    77,    78,
+     133,   140,   141,   111,    61,   104,    55,    79,    56,    57,
+     139,   109
 };
 
   /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
@@ -792,54 +811,56 @@ static const yytype_int16 yydefgoto[] =
      number is the opposite.  If YYTABLE_NINF, syntax error.  */
 static const yytype_int16 yytable[] =
 {
-      69,     3,    47,  -110,    71,    65,    50,     5,     6,     7,
-       8,     9,    10,    11,    12,    13,    53,    55,    90,    14,
-      15,    51,   148,    65,    65,    58,    56,    52,    92,   149,
-      57,    26,    87,    87,   132,   133,   134,    32,   130,    60,
-     131,   135,   136,    66,    61,    59,    67,    66,    72,    98,
-      67,   115,   106,   107,   108,    62,    84,   119,    40,   -55,
-     137,    66,    66,    93,    67,    67,   116,    63,   116,    94,
-      87,    82,    87,    64,    79,    81,    82,   138,    91,   101,
-      96,   115,    97,   103,   105,   117,   120,   122,    65,   147,
-      42,   143,   144,    83,   124,   123,   145,   140,    99,    88,
-     142,   146,   125,   126,   141,     0,     0,     4,     0,   140,
-       5,     6,     7,     8,     9,    10,    11,    12,    13,     0,
-       0,     0,    14,    15,    16,    17,    18,    19,    20,    21,
-      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
-      32,    33,    34,    35,     0,     0,     0,     0,     0,     0,
-       0,     0,    36,     0,    37,    38,     0,     0,     0,    71,
-      39,    40,     5,     6,     7,     8,     9,    10,    11,    12,
-      13,     0,     0,     0,    14,    15,     0,     0,     0,     0,
-       0,     0,     0,     0,     0,     0,    26,     0,     0,     0,
-       0,     0,    32,     0,     0,     0,     0,     0,     0,     0,
-       0,     0,     0,    72,     0,     0,     0,     0,     0,     0,
-       0,     0,     0,    40
+      72,    88,   122,    94,    94,     3,    46,   127,   124,  -119,
+      73,    89,   129,     5,     6,     7,     8,     9,    10,    11,
+      12,    13,    99,   161,    97,    14,    15,   101,    49,    50,
+     162,    50,    51,    49,    51,    60,    62,    26,    90,    63,
+      88,   136,    88,    32,   124,   137,    94,   129,    94,    49,
+      89,   121,    89,    49,    74,   107,    64,   129,   124,    65,
+      66,    58,   102,    67,    40,    99,    50,    59,   103,    51,
+     131,    50,    68,    69,    51,   115,   116,   117,    88,    88,
+      52,    70,    71,    94,    94,    81,   121,    50,    89,    89,
+      51,    50,    88,    94,    51,   142,   138,   143,   105,    99,
+      84,    83,    89,    98,   100,   110,   106,   125,   123,   153,
+       4,   112,   155,     5,     6,     7,     8,     9,    10,    11,
+      12,    13,   153,   114,   128,    14,    15,    16,    17,    18,
+      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
+      29,    30,    31,    32,    33,    34,    35,   132,   134,    49,
+     156,   157,   158,   159,   160,    36,    42,    37,    38,    96,
+     135,   130,    73,    39,    40,     5,     6,     7,     8,     9,
+      10,    11,    12,    13,    49,     0,   154,    14,    15,   108,
+       0,     0,     0,     0,   144,   145,   146,     0,     0,    26,
+       0,   147,   148,     0,     0,    32,     0,     0,     0,     0,
+       0,     0,     0,     0,     0,     0,    74,     0,     0,   -54,
+     149,     0,    50,     0,     0,    51,    40,     0,     0,     0,
+       0,   150,     0,     0,     0,     0,     0,   151
 };
 
 static const yytype_int16 yycheck[] =
 {
-      32,     0,    49,     0,     1,     3,    50,     4,     5,     6,
-       7,     8,     9,    10,    11,    12,    44,     3,    50,    16,
-      17,    38,   140,     3,     3,     3,    53,    44,     3,   147,
-      53,    28,    48,    49,    13,    14,    15,    34,    47,     3,
-      49,    20,    21,    41,     3,    38,    44,    41,    45,    46,
-      44,    83,    50,    51,    52,     3,    50,    89,    55,    38,
-      39,    41,    41,    38,    44,    44,    86,     3,    88,    44,
-      86,    50,    88,     3,    44,    38,    50,    56,    38,    40,
-      49,   113,    49,    38,    38,    53,    42,    38,     3,    38,
-       2,    53,    50,    46,   113,   109,    53,   129,    74,    49,
-     132,    53,   115,   118,   130,    -1,    -1,     1,    -1,   141,
-       4,     5,     6,     7,     8,     9,    10,    11,    12,    -1,
-      -1,    -1,    16,    17,    18,    19,    20,    21,    22,    23,
-      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
-      34,    35,    36,    37,    -1,    -1,    -1,    -1,    -1,    -1,
-      -1,    -1,    46,    -1,    48,    49,    -1,    -1,    -1,     1,
-      54,    55,     4,     5,     6,     7,     8,     9,    10,    11,
-      12,    -1,    -1,    -1,    16,    17,    -1,    -1,    -1,    -1,
-      -1,    -1,    -1,    -1,    -1,    -1,    28,    -1,    -1,    -1,
-      -1,    -1,    34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
-      -1,    -1,    -1,    45,    -1,    -1,    -1,    -1,    -1,    -1,
-      -1,    -1,    -1,    55
+      32,    45,    84,    47,    48,     0,    49,    90,    86,     0,
+       1,    45,    92,     4,     5,     6,     7,     8,     9,    10,
+      11,    12,    54,   153,    52,    16,    17,     3,     3,    41,
+     160,    41,    44,     3,    44,    44,     3,    28,    50,    53,
+      84,   123,    86,    34,   122,   128,    90,   127,    92,     3,
+      84,    83,    86,     3,    45,    46,    53,   137,   136,     3,
+      38,    38,    38,     3,    55,    97,    41,    44,    44,    44,
+      98,    41,     3,     3,    44,    50,    51,    52,   122,   123,
+      50,     3,     3,   127,   128,    44,   118,    41,   122,   123,
+      44,    41,   136,   137,    44,    47,   130,    49,    49,   131,
+      50,    38,   136,    50,    38,    40,    49,    53,    50,   141,
+       1,    38,   144,     4,     5,     6,     7,     8,     9,    10,
+      11,    12,   154,    38,    50,    16,    17,    18,    19,    20,
+      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
+      31,    32,    33,    34,    35,    36,    37,    42,    38,     3,
+      53,    50,    53,    53,    38,    46,     2,    48,    49,    48,
+     118,    94,     1,    54,    55,     4,     5,     6,     7,     8,
+       9,    10,    11,    12,     3,    -1,   142,    16,    17,    76,
+      -1,    -1,    -1,    -1,    13,    14,    15,    -1,    -1,    28,
+      -1,    20,    21,    -1,    -1,    34,    -1,    -1,    -1,    -1,
+      -1,    -1,    -1,    -1,    -1,    -1,    45,    -1,    -1,    38,
+      39,    -1,    41,    -1,    -1,    44,    55,    -1,    -1,    -1,
+      -1,    50,    -1,    -1,    -1,    -1,    -1,    56
 };
 
   /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
@@ -850,17 +871,19 @@ static const yytype_uint8 yystos[] =
        9,    10,    11,    12,    16,    17,    18,    19,    20,    21,
       22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
       32,    33,    34,    35,    36,    37,    46,    48,    49,    54,
-      55,    60,    63,    64,    66,    69,    70,    49,    68,    67,
-      50,    38,    44,    44,    88,     3,    53,    53,     3,    38,
-       3,     3,     3,     3,     3,     3,    41,    44,    90,    92,
-      93,     1,    45,    63,    81,    82,    83,    91,    61,    44,
-      65,    38,    50,    71,    50,    78,    80,    90,    80,    74,
-      92,    38,     3,    38,    44,    89,    49,    49,    46,    82,
-      95,    40,    87,    38,    62,    38,    50,    51,    52,    75,
-      76,    77,    92,    72,    73,    92,    78,    53,    79,    92,
-      42,    84,    38,    76,    73,    79,    93,    94,    85,    86,
-      47,    49,    13,    14,    15,    20,    21,    39,    56,    71,
-      92,    86,    92,    53,    50,    53,    53,    38,    87,    87
+      55,    60,    63,    64,    66,    69,    49,    68,    67,     3,
+      41,    44,    50,    82,    83,    93,    95,    96,    38,    44,
+      44,    91,     3,    53,    53,     3,    38,     3,     3,     3,
+       3,     3,    95,     1,    45,    63,    84,    85,    86,    94,
+      61,    44,    65,    38,    50,    79,    80,    81,    93,    96,
+      50,    75,    76,    77,    93,    74,    75,    83,    50,    95,
+      38,     3,    38,    44,    92,    49,    49,    46,    85,    98,
+      40,    90,    38,    62,    38,    50,    51,    52,    71,    72,
+      73,    95,    80,    50,    81,    53,    78,    76,    50,    77,
+      78,    83,    42,    87,    38,    72,    80,    76,    96,    97,
+      88,    89,    47,    49,    13,    14,    15,    20,    21,    39,
+      50,    56,    70,    95,    89,    95,    53,    50,    53,    53,
+      38,    90,    90
 };
 
   /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
@@ -869,15 +892,16 @@ static const yytype_uint8 yyr1[] =
        0,    57,    58,    59,    59,    60,    60,    60,    60,    60,
       60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
       60,    61,    60,    60,    60,    60,    60,    60,    60,    60,
-      62,    62,    63,    63,    63,    63,    63,    63,    63,    63,
-      64,    64,    65,    65,    63,    67,    66,    68,    66,    66,
-      69,    70,    70,    70,    70,    71,    71,    72,    72,    73,
-      74,    74,    75,    75,    76,    76,    77,    77,    77,    78,
-      78,    79,    79,    80,    80,    81,    81,    82,    82,    82,
-      84,    83,    85,    85,    85,    86,    86,    86,    86,    86,
-      86,    86,    86,    86,    86,    87,    87,    88,    89,    89,
-      89,    89,    90,    90,    91,    92,    92,    93,    94,    94,
-      95,    95
+      62,    62,    63,    63,    63,    63,    63,    63,    63,    64,
+      64,    65,    65,    63,    67,    66,    68,    66,    66,    66,
+      69,    69,    69,    69,    70,    70,    71,    71,    72,    72,
+      73,    73,    73,    74,    75,    75,    75,    76,    76,    77,
+      78,    78,    79,    79,    79,    80,    80,    81,    81,    82,
+      82,    82,    83,    83,    84,    84,    85,    85,    85,    87,
+      86,    88,    88,    88,    89,    89,    89,    89,    89,    89,
+      89,    89,    89,    89,    90,    90,    91,    92,    92,    92,
+      92,    93,    93,    94,    95,    95,    96,    97,    97,    98,
+      98
 };
 
   /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
@@ -886,15 +910,16 @@ static const yytype_uint8 yyr2[] =
        0,     2,     4,     0,     2,     1,     1,     1,     3,     1,
        2,     2,     2,     2,     1,     2,     2,     2,     1,     1,
        2,     0,     3,     2,     2,     1,     1,     1,     2,     1,
-       2,     1,     1,     1,     2,     3,     1,     1,     2,     3,
-       1,     1,     0,     1,     3,     0,     3,     0,     3,     3,
-       3,     1,     1,     1,     1,     0,     1,     1,     2,     2,
-       1,     2,     1,     2,     1,     1,     1,     1,     1,     1,
-       3,     0,     1,     1,     2,     1,     2,     1,     2,     2,
-       0,     4,     1,     3,     2,     0,     3,     4,     2,     2,
-       3,     3,     3,     3,     3,     0,     1,     1,     0,     1,
-       1,     1,     1,     1,     1,     1,     1,     1,     0,     1,
-       0,     2
+       2,     1,     1,     2,     3,     1,     1,     2,     3,     1,
+       1,     0,     1,     3,     0,     3,     0,     3,     2,     2,
+       1,     1,     1,     1,     0,     1,     1,     2,     1,     1,
+       1,     1,     1,     1,     1,     2,     3,     1,     2,     3,
+       0,     1,     1,     2,     3,     1,     2,     2,     1,     1,
+       2,     3,     1,     2,     1,     2,     1,     2,     2,     0,
+       4,     1,     3,     2,     0,     3,     4,     2,     2,     3,
+       3,     3,     3,     3,     0,     1,     1,     0,     1,     1,
+       1,     1,     1,     1,     1,     1,     1,     0,     1,     0,
+       2
 };
 
 
@@ -1050,75 +1075,75 @@ yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YY
   switch (yytype)
     {
     case 3: /* "string"  */
-#line 191 "src/parse-gram.y" /* yacc.c:680  */
+#line 190 "src/parse-gram.y" /* yacc.c:680  */
       { fputs (quotearg_style (c_quoting_style, ((*yyvaluep).STRING)), yyo); }
-#line 1056 "src/parse-gram.c" /* yacc.c:680  */
+#line 1081 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 22: /* "%<flag>"  */
-#line 198 "src/parse-gram.y" /* yacc.c:680  */
+#line 197 "src/parse-gram.y" /* yacc.c:680  */
       { fprintf (yyo, "%%%s", ((*yyvaluep).PERCENT_FLAG)); }
-#line 1062 "src/parse-gram.c" /* yacc.c:680  */
+#line 1087 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 38: /* "{...}"  */
-#line 192 "src/parse-gram.y" /* yacc.c:680  */
+#line 191 "src/parse-gram.y" /* yacc.c:680  */
       { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).BRACED_CODE)); }
-#line 1068 "src/parse-gram.c" /* yacc.c:680  */
+#line 1093 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 39: /* "%?{...}"  */
-#line 192 "src/parse-gram.y" /* yacc.c:680  */
+#line 191 "src/parse-gram.y" /* yacc.c:680  */
       { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).BRACED_PREDICATE)); }
-#line 1074 "src/parse-gram.c" /* yacc.c:680  */
+#line 1099 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 40: /* "[identifier]"  */
-#line 196 "src/parse-gram.y" /* yacc.c:680  */
+#line 195 "src/parse-gram.y" /* yacc.c:680  */
       { fprintf (yyo, "[%s]", ((*yyvaluep).BRACKETED_ID)); }
-#line 1080 "src/parse-gram.c" /* yacc.c:680  */
+#line 1105 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 41: /* "char"  */
-#line 188 "src/parse-gram.y" /* yacc.c:680  */
+#line 187 "src/parse-gram.y" /* yacc.c:680  */
       { fputs (char_name (((*yyvaluep).CHAR)), yyo); }
-#line 1086 "src/parse-gram.c" /* yacc.c:680  */
+#line 1111 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 42: /* "epilogue"  */
-#line 192 "src/parse-gram.y" /* yacc.c:680  */
+#line 191 "src/parse-gram.y" /* yacc.c:680  */
       { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).EPILOGUE)); }
-#line 1092 "src/parse-gram.c" /* yacc.c:680  */
+#line 1117 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 44: /* "identifier"  */
-#line 195 "src/parse-gram.y" /* yacc.c:680  */
+#line 194 "src/parse-gram.y" /* yacc.c:680  */
       { fputs (((*yyvaluep).ID), yyo); }
-#line 1098 "src/parse-gram.c" /* yacc.c:680  */
+#line 1123 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 45: /* "identifier:"  */
-#line 197 "src/parse-gram.y" /* yacc.c:680  */
+#line 196 "src/parse-gram.y" /* yacc.c:680  */
       { fprintf (yyo, "%s:", ((*yyvaluep).ID_COLON)); }
-#line 1104 "src/parse-gram.c" /* yacc.c:680  */
+#line 1129 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 48: /* "%{...%}"  */
-#line 192 "src/parse-gram.y" /* yacc.c:680  */
+#line 191 "src/parse-gram.y" /* yacc.c:680  */
       { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).PROLOGUE)); }
-#line 1110 "src/parse-gram.c" /* yacc.c:680  */
+#line 1135 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 50: /* "<tag>"  */
-#line 199 "src/parse-gram.y" /* yacc.c:680  */
+#line 198 "src/parse-gram.y" /* yacc.c:680  */
       { fprintf (yyo, "<%s>", ((*yyvaluep).TAG)); }
-#line 1116 "src/parse-gram.c" /* yacc.c:680  */
+#line 1141 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 53: /* "integer"  */
-#line 202 "src/parse-gram.y" /* yacc.c:680  */
+#line 201 "src/parse-gram.y" /* yacc.c:680  */
       { fprintf (yyo, "%d", ((*yyvaluep).INT)); }
-#line 1122 "src/parse-gram.c" /* yacc.c:680  */
+#line 1147 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 54: /* "%param"  */
@@ -1135,47 +1160,107 @@ yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YY
       case param_none: aver (false); break;
     }
 }
-#line 1139 "src/parse-gram.c" /* yacc.c:680  */
+#line 1164 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 64: /* code_props_type  */
-#line 376 "src/parse-gram.y" /* yacc.c:680  */
+#line 375 "src/parse-gram.y" /* yacc.c:680  */
       { fprintf (yyo, "%s", code_props_type_string (((*yyvaluep).code_props_type))); }
-#line 1145 "src/parse-gram.c" /* yacc.c:680  */
+#line 1170 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
-    case 71: /* tag.opt  */
-#line 195 "src/parse-gram.y" /* yacc.c:680  */
-      { fputs (((*yyvaluep).yytype_71), yyo); }
-#line 1151 "src/parse-gram.c" /* yacc.c:680  */
+    case 70: /* tag.opt  */
+#line 194 "src/parse-gram.y" /* yacc.c:680  */
+      { fputs (((*yyvaluep).yytype_70), yyo); }
+#line 1176 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
-    case 73: /* symbol.prec  */
-#line 205 "src/parse-gram.y" /* yacc.c:680  */
-      { fprintf (yyo, "%s", ((*yyvaluep).yytype_73)->tag); }
-#line 1157 "src/parse-gram.c" /* yacc.c:680  */
+    case 71: /* generic_symlist  */
+#line 210 "src/parse-gram.y" /* yacc.c:680  */
+      { symbol_list_syms_print (((*yyvaluep).generic_symlist), yyo); }
+#line 1182 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
-    case 77: /* tag  */
-#line 199 "src/parse-gram.y" /* yacc.c:680  */
+    case 72: /* generic_symlist_item  */
+#line 210 "src/parse-gram.y" /* yacc.c:680  */
+      { symbol_list_syms_print (((*yyvaluep).generic_symlist_item), yyo); }
+#line 1188 "src/parse-gram.c" /* yacc.c:680  */
+        break;
+
+    case 73: /* tag  */
+#line 198 "src/parse-gram.y" /* yacc.c:680  */
       { fprintf (yyo, "<%s>", ((*yyvaluep).tag)); }
-#line 1163 "src/parse-gram.c" /* yacc.c:680  */
+#line 1194 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
-    case 79: /* int.opt  */
-#line 202 "src/parse-gram.y" /* yacc.c:680  */
-      { fprintf (yyo, "%d", ((*yyvaluep).yytype_79)); }
-#line 1169 "src/parse-gram.c" /* yacc.c:680  */
+    case 74: /* nterm_decls  */
+#line 210 "src/parse-gram.y" /* yacc.c:680  */
+      { symbol_list_syms_print (((*yyvaluep).nterm_decls), yyo); }
+#line 1200 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
-    case 88: /* variable  */
-#line 195 "src/parse-gram.y" /* yacc.c:680  */
+    case 75: /* token_decls  */
+#line 210 "src/parse-gram.y" /* yacc.c:680  */
+      { symbol_list_syms_print (((*yyvaluep).token_decls), yyo); }
+#line 1206 "src/parse-gram.c" /* yacc.c:680  */
+        break;
+
+    case 76: /* token_decl.1  */
+#line 210 "src/parse-gram.y" /* yacc.c:680  */
+      { symbol_list_syms_print (((*yyvaluep).yytype_76), yyo); }
+#line 1212 "src/parse-gram.c" /* yacc.c:680  */
+        break;
+
+    case 77: /* token_decl  */
+#line 204 "src/parse-gram.y" /* yacc.c:680  */
+      { fprintf (yyo, "%s", ((*yyvaluep).token_decl) ? ((*yyvaluep).token_decl)->tag : "<NULL>"); }
+#line 1218 "src/parse-gram.c" /* yacc.c:680  */
+        break;
+
+    case 78: /* int.opt  */
+#line 201 "src/parse-gram.y" /* yacc.c:680  */
+      { fprintf (yyo, "%d", ((*yyvaluep).yytype_78)); }
+#line 1224 "src/parse-gram.c" /* yacc.c:680  */
+        break;
+
+    case 79: /* token_decls_for_prec  */
+#line 210 "src/parse-gram.y" /* yacc.c:680  */
+      { symbol_list_syms_print (((*yyvaluep).token_decls_for_prec), yyo); }
+#line 1230 "src/parse-gram.c" /* yacc.c:680  */
+        break;
+
+    case 80: /* token_decl_for_prec.1  */
+#line 210 "src/parse-gram.y" /* yacc.c:680  */
+      { symbol_list_syms_print (((*yyvaluep).yytype_80), yyo); }
+#line 1236 "src/parse-gram.c" /* yacc.c:680  */
+        break;
+
+    case 81: /* token_decl_for_prec  */
+#line 204 "src/parse-gram.y" /* yacc.c:680  */
+      { fprintf (yyo, "%s", ((*yyvaluep).token_decl_for_prec) ? ((*yyvaluep).token_decl_for_prec)->tag : "<NULL>"); }
+#line 1242 "src/parse-gram.c" /* yacc.c:680  */
+        break;
+
+    case 82: /* symbol_decls  */
+#line 210 "src/parse-gram.y" /* yacc.c:680  */
+      { symbol_list_syms_print (((*yyvaluep).symbol_decls), yyo); }
+#line 1248 "src/parse-gram.c" /* yacc.c:680  */
+        break;
+
+    case 83: /* symbol_decl.1  */
+#line 210 "src/parse-gram.y" /* yacc.c:680  */
+      { symbol_list_syms_print (((*yyvaluep).yytype_83), yyo); }
+#line 1254 "src/parse-gram.c" /* yacc.c:680  */
+        break;
+
+    case 91: /* variable  */
+#line 194 "src/parse-gram.y" /* yacc.c:680  */
       { fputs (((*yyvaluep).variable), yyo); }
-#line 1175 "src/parse-gram.c" /* yacc.c:680  */
+#line 1260 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
-    case 89: /* value  */
-#line 612 "src/parse-gram.y" /* yacc.c:680  */
+    case 92: /* value  */
+#line 670 "src/parse-gram.y" /* yacc.c:680  */
       {
   switch (((*yyvaluep).value).kind)
     {
@@ -1184,37 +1269,37 @@ yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YY
     case muscle_string:  fprintf (yyo, "\"%s\"", ((*yyvaluep).value).chars); break;
     }
 }
-#line 1188 "src/parse-gram.c" /* yacc.c:680  */
+#line 1273 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
-    case 90: /* id  */
-#line 205 "src/parse-gram.y" /* yacc.c:680  */
-      { fprintf (yyo, "%s", ((*yyvaluep).id)->tag); }
-#line 1194 "src/parse-gram.c" /* yacc.c:680  */
+    case 93: /* id  */
+#line 204 "src/parse-gram.y" /* yacc.c:680  */
+      { fprintf (yyo, "%s", ((*yyvaluep).id) ? ((*yyvaluep).id)->tag : "<NULL>"); }
+#line 1279 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
-    case 91: /* id_colon  */
-#line 206 "src/parse-gram.y" /* yacc.c:680  */
+    case 94: /* id_colon  */
+#line 205 "src/parse-gram.y" /* yacc.c:680  */
       { fprintf (yyo, "%s:", ((*yyvaluep).id_colon)->tag); }
-#line 1200 "src/parse-gram.c" /* yacc.c:680  */
+#line 1285 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
-    case 92: /* symbol  */
-#line 205 "src/parse-gram.y" /* yacc.c:680  */
-      { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
-#line 1206 "src/parse-gram.c" /* yacc.c:680  */
+    case 95: /* symbol  */
+#line 204 "src/parse-gram.y" /* yacc.c:680  */
+      { fprintf (yyo, "%s", ((*yyvaluep).symbol) ? ((*yyvaluep).symbol)->tag : "<NULL>"); }
+#line 1291 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
-    case 93: /* string_as_id  */
-#line 205 "src/parse-gram.y" /* yacc.c:680  */
-      { fprintf (yyo, "%s", ((*yyvaluep).string_as_id)->tag); }
-#line 1212 "src/parse-gram.c" /* yacc.c:680  */
+    case 96: /* string_as_id  */
+#line 204 "src/parse-gram.y" /* yacc.c:680  */
+      { fprintf (yyo, "%s", ((*yyvaluep).string_as_id) ? ((*yyvaluep).string_as_id)->tag : "<NULL>"); }
+#line 1297 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
-    case 94: /* string_as_id.opt  */
-#line 205 "src/parse-gram.y" /* yacc.c:680  */
-      { fprintf (yyo, "%s", ((*yyvaluep).yytype_94)->tag); }
-#line 1218 "src/parse-gram.c" /* yacc.c:680  */
+    case 97: /* string_as_id.opt  */
+#line 204 "src/parse-gram.y" /* yacc.c:680  */
+      { fprintf (yyo, "%s", ((*yyvaluep).yytype_97) ? ((*yyvaluep).yytype_97)->tag : "<NULL>"); }
+#line 1303 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
       default:
@@ -1795,7 +1880,65 @@ yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocatio
   YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);
 
   YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
-  YYUSE (yytype);
+  switch (yytype)
+    {
+    case 71: /* generic_symlist  */
+#line 209 "src/parse-gram.y" /* yacc.c:1253  */
+      { symbol_list_free (((*yyvaluep).generic_symlist)); }
+#line 1889 "src/parse-gram.c" /* yacc.c:1253  */
+        break;
+
+    case 72: /* generic_symlist_item  */
+#line 209 "src/parse-gram.y" /* yacc.c:1253  */
+      { symbol_list_free (((*yyvaluep).generic_symlist_item)); }
+#line 1895 "src/parse-gram.c" /* yacc.c:1253  */
+        break;
+
+    case 74: /* nterm_decls  */
+#line 209 "src/parse-gram.y" /* yacc.c:1253  */
+      { symbol_list_free (((*yyvaluep).nterm_decls)); }
+#line 1901 "src/parse-gram.c" /* yacc.c:1253  */
+        break;
+
+    case 75: /* token_decls  */
+#line 209 "src/parse-gram.y" /* yacc.c:1253  */
+      { symbol_list_free (((*yyvaluep).token_decls)); }
+#line 1907 "src/parse-gram.c" /* yacc.c:1253  */
+        break;
+
+    case 76: /* token_decl.1  */
+#line 209 "src/parse-gram.y" /* yacc.c:1253  */
+      { symbol_list_free (((*yyvaluep).yytype_76)); }
+#line 1913 "src/parse-gram.c" /* yacc.c:1253  */
+        break;
+
+    case 79: /* token_decls_for_prec  */
+#line 209 "src/parse-gram.y" /* yacc.c:1253  */
+      { symbol_list_free (((*yyvaluep).token_decls_for_prec)); }
+#line 1919 "src/parse-gram.c" /* yacc.c:1253  */
+        break;
+
+    case 80: /* token_decl_for_prec.1  */
+#line 209 "src/parse-gram.y" /* yacc.c:1253  */
+      { symbol_list_free (((*yyvaluep).yytype_80)); }
+#line 1925 "src/parse-gram.c" /* yacc.c:1253  */
+        break;
+
+    case 82: /* symbol_decls  */
+#line 209 "src/parse-gram.y" /* yacc.c:1253  */
+      { symbol_list_free (((*yyvaluep).symbol_decls)); }
+#line 1931 "src/parse-gram.c" /* yacc.c:1253  */
+        break;
+
+    case 83: /* symbol_decl.1  */
+#line 209 "src/parse-gram.y" /* yacc.c:1253  */
+      { symbol_list_free (((*yyvaluep).yytype_83)); }
+#line 1937 "src/parse-gram.c" /* yacc.c:1253  */
+        break;
+
+      default:
+        break;
+    }
   YY_IGNORE_MAYBE_UNINITIALIZED_END
 }
 
@@ -1907,7 +2050,7 @@ YYLTYPE yylloc = yyloc_default;
   yychar = YYEMPTY; /* Cause a token to be read.  */
 
 /* User initialization code.  */
-#line 114 "src/parse-gram.y" /* yacc.c:1427  */
+#line 113 "src/parse-gram.y" /* yacc.c:1427  */
 {
   /* Bison's grammar can initial empty locations, hence a default
      location is needed. */
@@ -1915,7 +2058,7 @@ YYLTYPE yylloc = yyloc_default;
   boundary_set (&yylloc.end, current_file, 1, 1);
 }
 
-#line 1919 "src/parse-gram.c" /* yacc.c:1427  */
+#line 2062 "src/parse-gram.c" /* yacc.c:1427  */
   yylsp[0] = yylloc;
   goto yysetstate;
 
@@ -2120,7 +2263,7 @@ yyreduce:
                         translate_code ((yyvsp[0].PROLOGUE), (yylsp[0]), true), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2124 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2267 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 7:
@@ -2128,7 +2271,7 @@ yyreduce:
     {
       muscle_percent_define_ensure ((yyvsp[0].PERCENT_FLAG), (yylsp[0]), true);
     }
-#line 2132 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2275 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 8:
@@ -2137,13 +2280,13 @@ yyreduce:
       muscle_percent_define_insert ((yyvsp[-1].variable), (yylsp[-1]), (yyvsp[0].value).kind, (yyvsp[0].value).chars,
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
     }
-#line 2141 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2284 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 9:
 #line 290 "src/parse-gram.y" /* yacc.c:1648  */
     { defines_flag = true; }
-#line 2147 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2290 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 10:
@@ -2152,25 +2295,25 @@ yyreduce:
       defines_flag = true;
       spec_defines_file = xstrdup ((yyvsp[0].STRING));
     }
-#line 2156 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2299 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 11:
 #line 296 "src/parse-gram.y" /* yacc.c:1648  */
     { expected_sr_conflicts = (yyvsp[0].INT); }
-#line 2162 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2305 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 12:
 #line 297 "src/parse-gram.y" /* yacc.c:1648  */
     { expected_rr_conflicts = (yyvsp[0].INT); }
-#line 2168 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2311 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 13:
 #line 298 "src/parse-gram.y" /* yacc.c:1648  */
     { spec_file_prefix = (yyvsp[0].STRING); }
-#line 2174 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2317 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 14:
@@ -2179,7 +2322,7 @@ yyreduce:
       nondeterministic_parser = true;
       glr_parser = true;
     }
-#line 2183 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2326 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 15:
@@ -2188,109 +2331,109 @@ yyreduce:
       muscle_code_grow ("initial_action", translate_code ((yyvsp[0].BRACED_CODE), (yylsp[0]), false), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2192 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2335 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 16:
 #line 309 "src/parse-gram.y" /* yacc.c:1648  */
     { language_argmatch ((yyvsp[0].STRING), grammar_prio, (yylsp[-1])); }
-#line 2198 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2341 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 17:
 #line 310 "src/parse-gram.y" /* yacc.c:1648  */
     { spec_name_prefix = (yyvsp[0].STRING); }
-#line 2204 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2347 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 18:
 #line 311 "src/parse-gram.y" /* yacc.c:1648  */
     { no_lines_flag = true; }
-#line 2210 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2353 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 19:
 #line 312 "src/parse-gram.y" /* yacc.c:1648  */
     { nondeterministic_parser = true; }
-#line 2216 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2359 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 20:
 #line 313 "src/parse-gram.y" /* yacc.c:1648  */
     { spec_outfile = (yyvsp[0].STRING); }
-#line 2222 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2365 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 21:
 #line 314 "src/parse-gram.y" /* yacc.c:1648  */
     { current_param = (yyvsp[0].PERCENT_PARAM); }
-#line 2228 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2371 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 22:
 #line 314 "src/parse-gram.y" /* yacc.c:1648  */
     { current_param = param_none; }
-#line 2234 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2377 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 23:
 #line 315 "src/parse-gram.y" /* yacc.c:1648  */
     { do_require (&(yylsp[0]), (yyvsp[0].STRING)); }
-#line 2240 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2383 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 24:
 #line 316 "src/parse-gram.y" /* yacc.c:1648  */
     { do_skeleton (&(yylsp[0]), (yyvsp[0].STRING)); }
-#line 2246 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2389 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 25:
 #line 317 "src/parse-gram.y" /* yacc.c:1648  */
     { token_table_flag = true; }
-#line 2252 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2395 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 26:
 #line 318 "src/parse-gram.y" /* yacc.c:1648  */
     { report_flag |= report_states; }
-#line 2258 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2401 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 27:
 #line 319 "src/parse-gram.y" /* yacc.c:1648  */
     { yacc_flag = true; }
-#line 2264 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2407 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 28:
 #line 320 "src/parse-gram.y" /* yacc.c:1648  */
     { current_class = unknown_sym; yyerrok; }
-#line 2270 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2413 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 30:
 #line 325 "src/parse-gram.y" /* yacc.c:1648  */
     { add_param (current_param, (yyvsp[0].BRACED_CODE), (yylsp[0])); }
-#line 2276 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2419 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 31:
 #line 326 "src/parse-gram.y" /* yacc.c:1648  */
     { add_param (current_param, (yyvsp[0].BRACED_CODE), (yylsp[0])); }
-#line 2282 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2425 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
-  case 34:
-#line 338 "src/parse-gram.y" /* yacc.c:1648  */
+  case 33:
+#line 337 "src/parse-gram.y" /* yacc.c:1648  */
     {
       grammar_start_symbol_set ((yyvsp[0].symbol), (yylsp[0]));
     }
-#line 2290 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2433 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
-  case 35:
-#line 342 "src/parse-gram.y" /* yacc.c:1648  */
+  case 34:
+#line 341 "src/parse-gram.y" /* yacc.c:1648  */
     {
       code_props code;
       code_props_symbol_action_init (&code, (yyvsp[-1].BRACED_CODE), (yylsp[-1]));
@@ -2301,27 +2444,27 @@ yyreduce:
         symbol_list_free ((yyvsp[0].generic_symlist));
       }
     }
-#line 2305 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2448 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
-  case 36:
-#line 353 "src/parse-gram.y" /* yacc.c:1648  */
+  case 35:
+#line 352 "src/parse-gram.y" /* yacc.c:1648  */
     {
       default_prec = true;
     }
-#line 2313 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2456 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
-  case 37:
-#line 357 "src/parse-gram.y" /* yacc.c:1648  */
+  case 36:
+#line 356 "src/parse-gram.y" /* yacc.c:1648  */
     {
       default_prec = false;
     }
-#line 2321 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2464 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
-  case 38:
-#line 361 "src/parse-gram.y" /* yacc.c:1648  */
+  case 37:
+#line 360 "src/parse-gram.y" /* yacc.c:1648  */
     {
       /* Do not invoke muscle_percent_code_grow here since it invokes
          muscle_user_name_list_grow.  */
@@ -2329,378 +2472,447 @@ yyreduce:
                         translate_code_braceless ((yyvsp[0].BRACED_CODE), (yylsp[0])), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2333 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2476 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
-  case 39:
-#line 369 "src/parse-gram.y" /* yacc.c:1648  */
+  case 38:
+#line 368 "src/parse-gram.y" /* yacc.c:1648  */
     {
       muscle_percent_code_grow ((yyvsp[-1].ID), (yylsp[-1]), translate_code_braceless ((yyvsp[0].BRACED_CODE), (yylsp[0])), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2342 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2485 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
-  case 40:
-#line 378 "src/parse-gram.y" /* yacc.c:1648  */
+  case 39:
+#line 377 "src/parse-gram.y" /* yacc.c:1648  */
     { (yyval.code_props_type) = destructor; }
-#line 2348 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2491 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
-  case 41:
-#line 379 "src/parse-gram.y" /* yacc.c:1648  */
+  case 40:
+#line 378 "src/parse-gram.y" /* yacc.c:1648  */
     { (yyval.code_props_type) = printer; }
-#line 2354 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2497 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
-  case 42:
-#line 389 "src/parse-gram.y" /* yacc.c:1648  */
+  case 41:
+#line 388 "src/parse-gram.y" /* yacc.c:1648  */
     {}
-#line 2360 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2503 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
-  case 43:
-#line 390 "src/parse-gram.y" /* yacc.c:1648  */
+  case 42:
+#line 389 "src/parse-gram.y" /* yacc.c:1648  */
     { muscle_percent_define_insert ("api.value.union.name",
                                          (yylsp[0]), muscle_keyword, (yyvsp[0].ID),
                                          MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE); }
-#line 2368 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2511 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
-  case 44:
-#line 397 "src/parse-gram.y" /* yacc.c:1648  */
+  case 43:
+#line 396 "src/parse-gram.y" /* yacc.c:1648  */
     {
       union_seen = true;
       muscle_code_grow ("union_members", translate_code_braceless ((yyvsp[0].BRACED_CODE), (yylsp[0])), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2378 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2521 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
-  case 45:
+  case 44:
 #line 408 "src/parse-gram.y" /* yacc.c:1648  */
     { current_class = nterm_sym; }
-#line 2384 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2527 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
-  case 46:
+  case 45:
 #line 409 "src/parse-gram.y" /* yacc.c:1648  */
     {
       current_class = unknown_sym;
-      current_type = NULL;
+      symbol_list_free ((yyvsp[0].nterm_decls));
     }
-#line 2393 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2536 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
-  case 47:
+  case 46:
 #line 413 "src/parse-gram.y" /* yacc.c:1648  */
     { current_class = token_sym; }
-#line 2399 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2542 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
-  case 48:
+  case 47:
 #line 414 "src/parse-gram.y" /* yacc.c:1648  */
     {
       current_class = unknown_sym;
-      current_type = NULL;
+      symbol_list_free ((yyvsp[0].token_decls));
     }
-#line 2408 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2551 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
-  case 49:
+  case 48:
 #line 419 "src/parse-gram.y" /* yacc.c:1648  */
     {
-      tag_seen = true;
-      for (symbol_list *list = (yyvsp[0].yytype_74); list; list = list->next)
-        symbol_type_set (list->content.sym, (yyvsp[-1].TAG), (yylsp[-1]));
-      symbol_list_free ((yyvsp[0].yytype_74));
+      symbol_list_free ((yyvsp[0].symbol_decls));
     }
-#line 2419 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2559 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
-  case 50:
-#line 429 "src/parse-gram.y" /* yacc.c:1648  */
+  case 49:
+#line 423 "src/parse-gram.y" /* yacc.c:1648  */
     {
       ++current_prec;
-      for (symbol_list *list = (yyvsp[0].yytype_72); list; list = list->next)
-        {
-          symbol_type_set (list->content.sym, (yyvsp[-1].yytype_71), (yylsp[-1]));
-          symbol_precedence_set (list->content.sym, current_prec, (yyvsp[-2].precedence_declarator), (yylsp[-2]));
-        }
-      symbol_list_free ((yyvsp[0].yytype_72));
+      for (symbol_list *list = (yyvsp[0].token_decls_for_prec); list; list = list->next)
+        symbol_precedence_set (list->content.sym, current_prec, (yyvsp[-1].precedence_declarator), (yylsp[-1]));
+      symbol_list_free ((yyvsp[0].token_decls_for_prec));
     }
-#line 2433 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2570 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
-  case 51:
-#line 441 "src/parse-gram.y" /* yacc.c:1648  */
+  case 50:
+#line 432 "src/parse-gram.y" /* yacc.c:1648  */
     { (yyval.precedence_declarator) = left_assoc; }
-#line 2439 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2576 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
-  case 52:
-#line 442 "src/parse-gram.y" /* yacc.c:1648  */
+  case 51:
+#line 433 "src/parse-gram.y" /* yacc.c:1648  */
     { (yyval.precedence_declarator) = right_assoc; }
-#line 2445 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2582 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
-  case 53:
-#line 443 "src/parse-gram.y" /* yacc.c:1648  */
+  case 52:
+#line 434 "src/parse-gram.y" /* yacc.c:1648  */
     { (yyval.precedence_declarator) = non_assoc; }
-#line 2451 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2588 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
-  case 54:
-#line 444 "src/parse-gram.y" /* yacc.c:1648  */
+  case 53:
+#line 435 "src/parse-gram.y" /* yacc.c:1648  */
     { (yyval.precedence_declarator) = precedence_assoc; }
-#line 2457 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2594 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
-  case 55:
-#line 448 "src/parse-gram.y" /* yacc.c:1648  */
-    { (yyval.yytype_71) = NULL; }
-#line 2463 "src/parse-gram.c" /* yacc.c:1648  */
+  case 54:
+#line 439 "src/parse-gram.y" /* yacc.c:1648  */
+    { (yyval.yytype_70) = NULL; }
+#line 2600 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
-  case 56:
-#line 449 "src/parse-gram.y" /* yacc.c:1648  */
-    { (yyval.yytype_71) = (yyvsp[0].TAG); tag_seen = true; }
-#line 2469 "src/parse-gram.c" /* yacc.c:1648  */
+  case 55:
+#line 440 "src/parse-gram.y" /* yacc.c:1648  */
+    { (yyval.yytype_70) = (yyvsp[0].TAG); }
+#line 2606 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 57:
-#line 455 "src/parse-gram.y" /* yacc.c:1648  */
-    { (yyval.yytype_72) = symbol_list_sym_new ((yyvsp[0].yytype_73), (yylsp[0])); }
-#line 2475 "src/parse-gram.c" /* yacc.c:1648  */
+#line 446 "src/parse-gram.y" /* yacc.c:1648  */
+    { (yyval.generic_symlist) = symbol_list_append ((yyvsp[-1].generic_symlist), (yyvsp[0].generic_symlist_item)); }
+#line 2612 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 58:
-#line 457 "src/parse-gram.y" /* yacc.c:1648  */
-    { (yyval.yytype_72) = symbol_list_append ((yyvsp[-1].yytype_72), symbol_list_sym_new ((yyvsp[0].yytype_73), (yylsp[0]))); }
-#line 2481 "src/parse-gram.c" /* yacc.c:1648  */
+#line 450 "src/parse-gram.y" /* yacc.c:1648  */
+    { (yyval.generic_symlist_item) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
+#line 2618 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 59:
-#line 462 "src/parse-gram.y" /* yacc.c:1648  */
-    {
-      (yyval.yytype_73) = (yyvsp[-1].symbol);
-      symbol_class_set ((yyvsp[-1].symbol), token_sym, (yylsp[-1]), false);
-      if (0 <= (yyvsp[0].yytype_79))
-        symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].yytype_79), (yylsp[0]));
-    }
-#line 2492 "src/parse-gram.c" /* yacc.c:1648  */
+#line 451 "src/parse-gram.y" /* yacc.c:1648  */
+    { (yyval.generic_symlist_item) = symbol_list_type_new ((yyvsp[0].tag), (yylsp[0])); }
+#line 2624 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
-  case 60:
-#line 473 "src/parse-gram.y" /* yacc.c:1648  */
-    { (yyval.yytype_74) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-#line 2498 "src/parse-gram.c" /* yacc.c:1648  */
+  case 61:
+#line 456 "src/parse-gram.y" /* yacc.c:1648  */
+    { (yyval.tag) = uniqstr_new ("*"); }
+#line 2630 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
-  case 61:
-#line 475 "src/parse-gram.y" /* yacc.c:1648  */
-    { (yyval.yytype_74) = symbol_list_append ((yyvsp[-1].yytype_74), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
-#line 2504 "src/parse-gram.c" /* yacc.c:1648  */
+  case 62:
+#line 457 "src/parse-gram.y" /* yacc.c:1648  */
+    { (yyval.tag) = uniqstr_new (""); }
+#line 2636 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
-  case 63:
+  case 64:
 #line 480 "src/parse-gram.y" /* yacc.c:1648  */
-    { (yyval.generic_symlist) = symbol_list_append ((yyvsp[-1].generic_symlist), (yyvsp[0].generic_symlist_item)); }
-#line 2510 "src/parse-gram.c" /* yacc.c:1648  */
+    {
+      (yyval.token_decls) = (yyvsp[0].yytype_76);
+    }
+#line 2644 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
-  case 64:
+  case 65:
 #line 484 "src/parse-gram.y" /* yacc.c:1648  */
-    { (yyval.generic_symlist_item) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-#line 2516 "src/parse-gram.c" /* yacc.c:1648  */
+    {
+      (yyval.token_decls) = symbol_list_type_set ((yyvsp[0].yytype_76), (yyvsp[-1].TAG), (yylsp[-1]));
+    }
+#line 2652 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
-  case 65:
-#line 485 "src/parse-gram.y" /* yacc.c:1648  */
-    { (yyval.generic_symlist_item) = symbol_list_type_new ((yyvsp[0].tag), (yylsp[0])); }
-#line 2522 "src/parse-gram.c" /* yacc.c:1648  */
+  case 66:
+#line 488 "src/parse-gram.y" /* yacc.c:1648  */
+    {
+      (yyval.token_decls) = symbol_list_append ((yyvsp[-2].token_decls), symbol_list_type_set ((yyvsp[0].yytype_76), (yyvsp[-1].TAG), (yylsp[-1])));
+    }
+#line 2660 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 67:
-#line 490 "src/parse-gram.y" /* yacc.c:1648  */
-    { (yyval.tag) = uniqstr_new ("*"); }
-#line 2528 "src/parse-gram.c" /* yacc.c:1648  */
+#line 495 "src/parse-gram.y" /* yacc.c:1648  */
+    { (yyval.yytype_76) = symbol_list_sym_new ((yyvsp[0].token_decl), (yylsp[0])); }
+#line 2666 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 68:
-#line 491 "src/parse-gram.y" /* yacc.c:1648  */
-    { (yyval.tag) = uniqstr_new (""); }
-#line 2534 "src/parse-gram.c" /* yacc.c:1648  */
+#line 496 "src/parse-gram.y" /* yacc.c:1648  */
+    { (yyval.yytype_76) = symbol_list_append ((yyvsp[-1].yytype_76), symbol_list_sym_new ((yyvsp[0].token_decl), (yylsp[0]))); }
+#line 2672 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 69:
-#line 497 "src/parse-gram.y" /* yacc.c:1648  */
+#line 501 "src/parse-gram.y" /* yacc.c:1648  */
     {
-      current_type = (yyvsp[0].TAG);
-      tag_seen = true;
+      (yyval.token_decl) = (yyvsp[-2].id);
+      symbol_class_set ((yyvsp[-2].id), current_class, (yylsp[-2]), true);
+      if (0 <= (yyvsp[-1].yytype_78))
+        symbol_user_token_number_set ((yyvsp[-2].id), (yyvsp[-1].yytype_78), (yylsp[-1]));
+      if ((yyvsp[0].yytype_97))
+        symbol_make_alias ((yyvsp[-2].id), (yyvsp[0].yytype_97), (yylsp[0]));
     }
-#line 2543 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2685 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 70:
-#line 502 "src/parse-gram.y" /* yacc.c:1648  */
+#line 513 "src/parse-gram.y" /* yacc.c:1648  */
+    { (yyval.yytype_78) = -1; }
+#line 2691 "src/parse-gram.c" /* yacc.c:1648  */
+    break;
+
+  case 72:
+#line 527 "src/parse-gram.y" /* yacc.c:1648  */
     {
-      symbol_class_set ((yyvsp[-2].id), current_class, (yylsp[-2]), true);
-      symbol_type_set ((yyvsp[-2].id), current_type, (yylsp[-2]));
-      if (0 <= (yyvsp[-1].yytype_79))
-        symbol_user_token_number_set ((yyvsp[-2].id), (yyvsp[-1].yytype_79), (yylsp[-1]));
-      if ((yyvsp[0].yytype_94))
-        symbol_make_alias ((yyvsp[-2].id), (yyvsp[0].yytype_94), (yylsp[0]));
+      (yyval.token_decls_for_prec) = (yyvsp[0].yytype_80);
+    }
+#line 2699 "src/parse-gram.c" /* yacc.c:1648  */
+    break;
+
+  case 73:
+#line 531 "src/parse-gram.y" /* yacc.c:1648  */
+    {
+      (yyval.token_decls_for_prec) = symbol_list_type_set ((yyvsp[0].yytype_80), (yyvsp[-1].TAG), (yylsp[-1]));
     }
-#line 2556 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2707 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
-  case 71:
-#line 514 "src/parse-gram.y" /* yacc.c:1648  */
-    { (yyval.yytype_79) = -1; }
-#line 2562 "src/parse-gram.c" /* yacc.c:1648  */
+  case 74:
+#line 535 "src/parse-gram.y" /* yacc.c:1648  */
+    {
+      (yyval.token_decls_for_prec) = symbol_list_append ((yyvsp[-2].token_decls_for_prec), symbol_list_type_set ((yyvsp[0].yytype_80), (yyvsp[-1].TAG), (yylsp[-1])));
+    }
+#line 2715 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
-  case 79:
+  case 75:
 #line 543 "src/parse-gram.y" /* yacc.c:1648  */
+    { (yyval.yytype_80) = symbol_list_sym_new ((yyvsp[0].token_decl_for_prec), (yylsp[0])); }
+#line 2721 "src/parse-gram.c" /* yacc.c:1648  */
+    break;
+
+  case 76:
+#line 545 "src/parse-gram.y" /* yacc.c:1648  */
+    { (yyval.yytype_80) = symbol_list_append ((yyvsp[-1].yytype_80), symbol_list_sym_new ((yyvsp[0].token_decl_for_prec), (yylsp[0]))); }
+#line 2727 "src/parse-gram.c" /* yacc.c:1648  */
+    break;
+
+  case 77:
+#line 550 "src/parse-gram.y" /* yacc.c:1648  */
     {
-      yyerrok;
+      (yyval.token_decl_for_prec) = (yyvsp[-1].id);
+      symbol_class_set ((yyvsp[-1].id), token_sym, (yylsp[-1]), false);
+      if (0 <= (yyvsp[0].yytype_78))
+        symbol_user_token_number_set ((yyvsp[-1].id), (yyvsp[0].yytype_78), (yylsp[0]));
     }
-#line 2570 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2738 "src/parse-gram.c" /* yacc.c:1648  */
+    break;
+
+  case 79:
+#line 567 "src/parse-gram.y" /* yacc.c:1648  */
+    {
+      (yyval.symbol_decls) = (yyvsp[0].yytype_83);
+    }
+#line 2746 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 80:
-#line 549 "src/parse-gram.y" /* yacc.c:1648  */
-    { current_lhs ((yyvsp[-1].id_colon), (yylsp[-1]), (yyvsp[0].yytype_87)); }
-#line 2576 "src/parse-gram.c" /* yacc.c:1648  */
+#line 571 "src/parse-gram.y" /* yacc.c:1648  */
+    {
+      (yyval.symbol_decls) = symbol_list_type_set ((yyvsp[0].yytype_83), (yyvsp[-1].TAG), (yylsp[-1]));
+    }
+#line 2754 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 81:
-#line 550 "src/parse-gram.y" /* yacc.c:1648  */
+#line 575 "src/parse-gram.y" /* yacc.c:1648  */
+    {
+      (yyval.symbol_decls) = symbol_list_append ((yyvsp[-2].symbol_decls), symbol_list_type_set ((yyvsp[0].yytype_83), (yyvsp[-1].TAG), (yylsp[-1])));
+    }
+#line 2762 "src/parse-gram.c" /* yacc.c:1648  */
+    break;
+
+  case 82:
+#line 582 "src/parse-gram.y" /* yacc.c:1648  */
+    { (yyval.yytype_83) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
+#line 2768 "src/parse-gram.c" /* yacc.c:1648  */
+    break;
+
+  case 83:
+#line 583 "src/parse-gram.y" /* yacc.c:1648  */
+    { (yyval.yytype_83) = symbol_list_append ((yyvsp[-1].yytype_83), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
+#line 2774 "src/parse-gram.c" /* yacc.c:1648  */
+    break;
+
+  case 88:
+#line 601 "src/parse-gram.y" /* yacc.c:1648  */
+    {
+      yyerrok;
+    }
+#line 2782 "src/parse-gram.c" /* yacc.c:1648  */
+    break;
+
+  case 89:
+#line 607 "src/parse-gram.y" /* yacc.c:1648  */
+    { current_lhs ((yyvsp[-1].id_colon), (yylsp[-1]), (yyvsp[0].yytype_90)); }
+#line 2788 "src/parse-gram.c" /* yacc.c:1648  */
+    break;
+
+  case 90:
+#line 608 "src/parse-gram.y" /* yacc.c:1648  */
     {
       /* Free the current lhs. */
       current_lhs (0, (yylsp[-3]), 0);
     }
-#line 2585 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2797 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
-  case 82:
-#line 557 "src/parse-gram.y" /* yacc.c:1648  */
+  case 91:
+#line 615 "src/parse-gram.y" /* yacc.c:1648  */
     { grammar_current_rule_end ((yylsp[0])); }
-#line 2591 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2803 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
-  case 83:
-#line 558 "src/parse-gram.y" /* yacc.c:1648  */
+  case 92:
+#line 616 "src/parse-gram.y" /* yacc.c:1648  */
     { grammar_current_rule_end ((yylsp[0])); }
-#line 2597 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2809 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
-  case 85:
-#line 565 "src/parse-gram.y" /* yacc.c:1648  */
+  case 94:
+#line 623 "src/parse-gram.y" /* yacc.c:1648  */
     { grammar_current_rule_begin (current_lhs_symbol, current_lhs_location,
                                   current_lhs_named_ref); }
-#line 2604 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2816 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
-  case 86:
-#line 568 "src/parse-gram.y" /* yacc.c:1648  */
-    { grammar_current_rule_symbol_append ((yyvsp[-1].symbol), (yylsp[-1]), (yyvsp[0].yytype_87)); }
-#line 2610 "src/parse-gram.c" /* yacc.c:1648  */
+  case 95:
+#line 626 "src/parse-gram.y" /* yacc.c:1648  */
+    { grammar_current_rule_symbol_append ((yyvsp[-1].symbol), (yylsp[-1]), (yyvsp[0].yytype_90)); }
+#line 2822 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
-  case 87:
-#line 570 "src/parse-gram.y" /* yacc.c:1648  */
-    { grammar_current_rule_action_append ((yyvsp[-1].BRACED_CODE), (yylsp[-1]), (yyvsp[0].yytype_87), (yyvsp[-2].yytype_71)); }
-#line 2616 "src/parse-gram.c" /* yacc.c:1648  */
+  case 96:
+#line 628 "src/parse-gram.y" /* yacc.c:1648  */
+    { grammar_current_rule_action_append ((yyvsp[-1].BRACED_CODE), (yylsp[-1]), (yyvsp[0].yytype_90), (yyvsp[-2].yytype_70)); }
+#line 2828 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
-  case 88:
-#line 572 "src/parse-gram.y" /* yacc.c:1648  */
+  case 97:
+#line 630 "src/parse-gram.y" /* yacc.c:1648  */
     { grammar_current_rule_predicate_append ((yyvsp[0].BRACED_PREDICATE), (yylsp[0])); }
-#line 2622 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2834 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
-  case 89:
-#line 574 "src/parse-gram.y" /* yacc.c:1648  */
+  case 98:
+#line 632 "src/parse-gram.y" /* yacc.c:1648  */
     { grammar_current_rule_empty_set ((yylsp[0])); }
-#line 2628 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2840 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
-  case 90:
-#line 576 "src/parse-gram.y" /* yacc.c:1648  */
+  case 99:
+#line 634 "src/parse-gram.y" /* yacc.c:1648  */
     { grammar_current_rule_prec_set ((yyvsp[0].symbol), (yylsp[0])); }
-#line 2634 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2846 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
-  case 91:
-#line 578 "src/parse-gram.y" /* yacc.c:1648  */
+  case 100:
+#line 636 "src/parse-gram.y" /* yacc.c:1648  */
     { grammar_current_rule_dprec_set ((yyvsp[0].INT), (yylsp[0])); }
-#line 2640 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2852 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
-  case 92:
-#line 580 "src/parse-gram.y" /* yacc.c:1648  */
+  case 101:
+#line 638 "src/parse-gram.y" /* yacc.c:1648  */
     { grammar_current_rule_merge_set ((yyvsp[0].TAG), (yylsp[0])); }
-#line 2646 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2858 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
-  case 93:
-#line 582 "src/parse-gram.y" /* yacc.c:1648  */
+  case 102:
+#line 640 "src/parse-gram.y" /* yacc.c:1648  */
     { grammar_current_rule_expect_sr ((yyvsp[0].INT), (yylsp[0])); }
-#line 2652 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2864 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
-  case 94:
-#line 584 "src/parse-gram.y" /* yacc.c:1648  */
+  case 103:
+#line 642 "src/parse-gram.y" /* yacc.c:1648  */
     { grammar_current_rule_expect_rr ((yyvsp[0].INT), (yylsp[0])); }
-#line 2658 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2870 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
-  case 95:
-#line 588 "src/parse-gram.y" /* yacc.c:1648  */
-    { (yyval.yytype_87) = 0; }
-#line 2664 "src/parse-gram.c" /* yacc.c:1648  */
+  case 104:
+#line 646 "src/parse-gram.y" /* yacc.c:1648  */
+    { (yyval.yytype_90) = 0; }
+#line 2876 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
-  case 96:
-#line 589 "src/parse-gram.y" /* yacc.c:1648  */
-    { (yyval.yytype_87) = named_ref_new ((yyvsp[0].BRACKETED_ID), (yylsp[0])); }
-#line 2670 "src/parse-gram.c" /* yacc.c:1648  */
+  case 105:
+#line 647 "src/parse-gram.y" /* yacc.c:1648  */
+    { (yyval.yytype_90) = named_ref_new ((yyvsp[0].BRACKETED_ID), (yylsp[0])); }
+#line 2882 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
-  case 98:
-#line 622 "src/parse-gram.y" /* yacc.c:1648  */
+  case 107:
+#line 680 "src/parse-gram.y" /* yacc.c:1648  */
     { (yyval.value).kind = muscle_keyword; (yyval.value).chars = ""; }
-#line 2676 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2888 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
-  case 99:
-#line 623 "src/parse-gram.y" /* yacc.c:1648  */
+  case 108:
+#line 681 "src/parse-gram.y" /* yacc.c:1648  */
     { (yyval.value).kind = muscle_keyword; (yyval.value).chars = (yyvsp[0].ID); }
-#line 2682 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2894 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
-  case 100:
-#line 624 "src/parse-gram.y" /* yacc.c:1648  */
+  case 109:
+#line 682 "src/parse-gram.y" /* yacc.c:1648  */
     { (yyval.value).kind = muscle_string;  (yyval.value).chars = (yyvsp[0].STRING); }
-#line 2688 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2900 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
-  case 101:
-#line 625 "src/parse-gram.y" /* yacc.c:1648  */
+  case 110:
+#line 683 "src/parse-gram.y" /* yacc.c:1648  */
     { (yyval.value).kind = muscle_code;    (yyval.value).chars = strip_braces ((yyvsp[0].BRACED_CODE)); }
-#line 2694 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2906 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
-  case 102:
-#line 638 "src/parse-gram.y" /* yacc.c:1648  */
+  case 111:
+#line 696 "src/parse-gram.y" /* yacc.c:1648  */
     { (yyval.id) = symbol_from_uniqstr ((yyvsp[0].ID), (yylsp[0])); }
-#line 2700 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2912 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
-  case 103:
-#line 640 "src/parse-gram.y" /* yacc.c:1648  */
+  case 112:
+#line 698 "src/parse-gram.y" /* yacc.c:1648  */
     {
       if (current_class == nterm_sym)
         {
@@ -2712,41 +2924,41 @@ yyreduce:
       symbol_class_set ((yyval.id), token_sym, (yylsp[0]), false);
       symbol_user_token_number_set ((yyval.id), (yyvsp[0].CHAR), (yylsp[0]));
     }
-#line 2716 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2928 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
-  case 104:
-#line 654 "src/parse-gram.y" /* yacc.c:1648  */
+  case 113:
+#line 712 "src/parse-gram.y" /* yacc.c:1648  */
     { (yyval.id_colon) = symbol_from_uniqstr ((yyvsp[0].ID_COLON), (yylsp[0])); }
-#line 2722 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2934 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
-  case 107:
-#line 666 "src/parse-gram.y" /* yacc.c:1648  */
+  case 116:
+#line 724 "src/parse-gram.y" /* yacc.c:1648  */
     {
       (yyval.string_as_id) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[0].STRING)), (yylsp[0]));
       symbol_class_set ((yyval.string_as_id), token_sym, (yylsp[0]), false);
     }
-#line 2731 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2943 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
-  case 108:
-#line 674 "src/parse-gram.y" /* yacc.c:1648  */
-    { (yyval.yytype_94) = NULL; }
-#line 2737 "src/parse-gram.c" /* yacc.c:1648  */
+  case 117:
+#line 732 "src/parse-gram.y" /* yacc.c:1648  */
+    { (yyval.yytype_97) = NULL; }
+#line 2949 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
-  case 111:
-#line 681 "src/parse-gram.y" /* yacc.c:1648  */
+  case 120:
+#line 739 "src/parse-gram.y" /* yacc.c:1648  */
     {
       muscle_code_grow ("epilogue", translate_code ((yyvsp[0].EPILOGUE), (yylsp[0]), true), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2746 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2958 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
 
-#line 2750 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2962 "src/parse-gram.c" /* yacc.c:1648  */
         default: break;
       }
     if (yychar_backup != yychar)
@@ -2995,7 +3207,7 @@ yyreturn:
 #endif
   return yyresult;
 }
-#line 687 "src/parse-gram.y" /* yacc.c:1914  */
+#line 745 "src/parse-gram.y" /* yacc.c:1914  */
 
 
 /* Return the location of the left-hand side of a rule whose
