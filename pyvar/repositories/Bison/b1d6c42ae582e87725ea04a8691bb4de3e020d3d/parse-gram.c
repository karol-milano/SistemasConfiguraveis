@@ -133,7 +133,7 @@ extern int gram_debug;
     param_parse  = 1 << 1,
     param_both   = param_lex | param_parse
   } param_type;
-#line 636 "src/parse-gram.y" /* yacc.c:353  */
+#line 621 "src/parse-gram.y" /* yacc.c:353  */
 
   #include "muscle-tab.h"
   typedef struct
@@ -229,8 +229,10 @@ union GRAM_STYPE
   code_props_type code_props_type;
   /* "integer"  */
   int INT;
+  /* int.opt  */
+  int yytype_79;
   /* named_ref.opt  */
-  named_ref* yytype_86;
+  named_ref* yytype_87;
   /* "%param"  */
   param_type PERCENT_PARAM;
   /* symbol.prec  */
@@ -243,6 +245,8 @@ union GRAM_STYPE
   symbol* symbol;
   /* string_as_id  */
   symbol* string_as_id;
+  /* string_as_id.opt  */
+  symbol* yytype_94;
   /* symbols.prec  */
   symbol_list* yytype_72;
   /* symbols.1  */
@@ -269,7 +273,7 @@ union GRAM_STYPE
   unsigned char CHAR;
   /* value  */
   value_type value;
-#line 273 "src/parse-gram.c" /* yacc.c:353  */
+#line 277 "src/parse-gram.c" /* yacc.c:353  */
 };
 
 typedef union GRAM_STYPE GRAM_STYPE;
@@ -378,7 +382,7 @@ int gram_parse (void);
   static void add_param (param_type type, char *decl, location loc);
   static param_type current_param = param_none;
 
-#line 382 "src/parse-gram.c" /* yacc.c:356  */
+#line 386 "src/parse-gram.c" /* yacc.c:356  */
 
 #ifdef short
 # undef short
@@ -590,16 +594,16 @@ union yyalloc
 /* YYFINAL -- State number of the termination state.  */
 #define YYFINAL  3
 /* YYLAST -- Last index in YYTABLE.  */
-#define YYLAST   212
+#define YYLAST   213
 
 /* YYNTOKENS -- Number of terminals.  */
 #define YYNTOKENS  57
 /* YYNNTS -- Number of nonterminals.  */
-#define YYNNTS  37
+#define YYNNTS  39
 /* YYNRULES -- Number of rules.  */
-#define YYNRULES  111
+#define YYNRULES  112
 /* YYNSTATES -- Number of states.  */
-#define YYNSTATES  149
+#define YYNSTATES  150
 
 #define YYUNDEFTOK  2
 #define YYMAXUTOK   311
@@ -658,11 +662,11 @@ static const yytype_uint16 yyrline[] =
      378,   379,   389,   390,   396,   408,   408,   413,   413,   418,
      428,   442,   443,   444,   445,   449,   450,   455,   457,   462,
      467,   477,   479,   484,   485,   489,   490,   494,   495,   496,
-     501,   506,   511,   523,   535,   554,   555,   567,   568,   574,
-     575,   576,   583,   583,   591,   592,   593,   598,   601,   603,
-     605,   607,   609,   611,   613,   615,   617,   622,   623,   632,
-     656,   657,   658,   659,   671,   673,   688,   693,   694,   699,
-     707,   708
+     501,   506,   533,   534,   539,   540,   552,   553,   559,   560,
+     561,   568,   568,   576,   577,   578,   583,   586,   588,   590,
+     592,   594,   596,   598,   600,   602,   607,   608,   617,   641,
+     642,   643,   644,   656,   658,   673,   678,   679,   684,   693,
+     694,   698,   699
 };
 #endif
 
@@ -689,10 +693,10 @@ static const char *const yytname[] =
   "code_props_type", "union_name", "symbol_declaration", "$@2", "$@3",
   "precedence_declaration", "precedence_declarator", "tag.opt",
   "symbols.prec", "symbol.prec", "symbols.1", "generic_symlist",
-  "generic_symlist_item", "tag", "symbol_def", "symbol_defs.1", "grammar",
-  "rules_or_grammar_declaration", "rules", "$@4", "rhses.1", "rhs",
-  "named_ref.opt", "variable", "value", "id", "id_colon", "symbol",
-  "string_as_id", "epilogue.opt", YY_NULLPTR
+  "generic_symlist_item", "tag", "symbol_def", "int.opt", "symbol_defs.1",
+  "grammar", "rules_or_grammar_declaration", "rules", "$@4", "rhses.1",
+  "rhs", "named_ref.opt", "variable", "value", "id", "id_colon", "symbol",
+  "string_as_id", "string_as_id.opt", "epilogue.opt", YY_NULLPTR
 };
 #endif
 
@@ -710,12 +714,12 @@ static const yytype_uint16 yytoknum[] =
 };
 # endif
 
-#define YYPACT_NINF -124
+#define YYPACT_NINF -119
 
 #define yypact_value_is_default(Yystate) \
-  (!!((Yystate) == (-124)))
+  (!!((Yystate) == (-119)))
 
-#define YYTABLE_NINF -111
+#define YYTABLE_NINF -112
 
 #define yytable_value_is_error(Yytable_value) \
   0
@@ -724,21 +728,21 @@ static const yytype_uint16 yytoknum[] =
      STATE-NUM.  */
 static const yytype_int16 yypact[] =
 {
-    -124,     1,   105,  -124,   -43,  -124,  -124,   -28,  -124,  -124,
-    -124,  -124,  -124,  -124,   -17,  -124,   -15,    29,   -20,   -13,
-    -124,    41,  -124,     7,    47,    51,  -124,  -124,  -124,    53,
-      61,    65,     2,  -124,  -124,  -124,   157,  -124,  -124,  -124,
-      25,  -124,  -124,    32,  -124,  -124,    30,  -124,    38,    38,
-       2,  -124,    37,  -124,    23,  -124,  -124,  -124,  -124,  -124,
-    -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,
-    -124,    34,  -124,    35,     3,  -124,  -124,    45,    48,  -124,
-      49,    22,  -124,     2,  -124,  -124,    38,    -1,    38,     2,
-    -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,    50,  -124,
-    -124,  -124,  -124,  -124,    52,  -124,  -124,  -124,  -124,    22,
-    -124,  -124,  -124,     2,  -124,    36,  -124,    88,  -124,  -124,
-    -124,  -124,  -124,  -124,  -124,  -124,  -124,   -19,    21,  -124,
-    -124,     2,    40,    44,    42,    54,  -124,  -124,    59,    45,
-      21,  -124,  -124,  -124,  -124,  -124,    45,  -124,  -124
+    -119,     1,   106,  -119,   -47,  -119,  -119,   -44,  -119,  -119,
+    -119,  -119,  -119,  -119,   -17,  -119,   -28,    14,   -27,   -23,
+    -119,    22,  -119,     7,    36,    41,  -119,  -119,  -119,    52,
+      64,    70,    20,  -119,  -119,  -119,   158,  -119,  -119,  -119,
+      30,  -119,  -119,    37,  -119,  -119,    26,  -119,     6,     6,
+      20,  -119,    40,  -119,    25,  -119,  -119,  -119,  -119,  -119,
+    -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,
+    -119,    31,  -119,    33,     3,  -119,  -119,    39,    45,  -119,
+      46,     2,  -119,    20,  -119,  -119,     6,    32,     6,    20,
+    -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,    44,  -119,
+    -119,  -119,  -119,  -119,    49,  -119,  -119,  -119,  -119,     2,
+    -119,  -119,  -119,    20,  -119,    35,  -119,  -119,    86,  -119,
+    -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,    -9,    21,
+    -119,  -119,    20,    38,    42,    43,    48,  -119,  -119,    55,
+      39,    21,  -119,  -119,  -119,  -119,  -119,    39,  -119,  -119
 };
 
   /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
@@ -751,34 +755,34 @@ static const yytype_uint8 yydefact[] =
        7,     0,    14,     0,     0,     0,    37,    18,    19,     0,
        0,     0,     0,    25,    26,    27,     0,     6,    29,    21,
       42,     4,     5,     0,    33,    32,    55,    28,     0,     0,
-       0,    38,     0,    99,   100,    10,    11,    12,    13,    15,
-      16,    17,    20,    23,    24,   109,   105,   104,   107,    34,
-     108,     0,   106,     0,     0,    77,    79,    97,     0,    43,
-       0,     0,    56,     0,    70,    75,    48,    71,    46,    49,
-      61,    39,   102,   103,   101,     8,    81,    80,     0,    78,
-       2,    98,    82,    31,    22,    44,    67,    68,    69,    35,
-      63,    66,    65,    50,    57,    59,    76,    72,    73,    62,
-     111,    87,    30,    64,    58,    60,    74,    83,    84,    87,
-      86,     0,     0,     0,     0,     0,    90,    91,     0,    97,
-      85,    92,    93,    94,    95,    96,    97,    88,    89
+       0,    38,     0,    98,    99,    10,    11,    12,    13,    15,
+      16,    17,    20,    23,    24,   108,   104,   103,   106,    34,
+     107,     0,   105,     0,     0,    76,    78,    96,     0,    43,
+       0,     0,    56,     0,    70,    74,    48,    72,    46,    49,
+      61,    39,   101,   102,   100,     8,    80,    79,     0,    77,
+       2,    97,    81,    31,    22,    44,    67,    68,    69,    35,
+      63,    66,    65,    50,    57,    59,    75,    73,   109,    62,
+     112,    86,    30,    64,    58,    60,   110,    71,    82,    83,
+      86,    85,     0,     0,     0,     0,     0,    89,    90,     0,
+      96,    84,    91,    92,    93,    94,    95,    96,    87,    88
 };
 
   /* YYPGOTO[NTERM-NUM].  */
 static const yytype_int8 yypgoto[] =
 {
-    -124,  -124,  -124,  -124,  -124,  -124,    96,  -124,  -124,  -124,
-    -124,  -124,  -124,  -124,    55,  -124,   -11,  -124,  -124,    -9,
-    -124,   -33,    56,  -124,    46,  -124,  -124,  -124,   -26,  -123,
-    -124,  -124,   -10,  -124,   -32,   -70,  -124
+    -119,  -119,  -119,  -119,  -119,  -119,    88,  -119,  -119,  -119,
+    -119,  -119,  -119,  -119,    53,  -119,   -19,  -119,  -119,   -14,
+    -119,   -20,  -119,    54,  -119,    24,  -119,  -119,  -119,   -26,
+    -118,  -119,  -119,   -16,  -119,   -32,   -13,  -119,  -119
 };
 
   /* YYDEFGOTO[NTERM-NUM].  */
 static const yytype_int16 yydefgoto[] =
 {
       -1,     1,     2,    41,    78,   104,    73,    43,    80,    44,
-      49,    48,    45,    46,   138,   113,   114,    89,   109,   110,
-     111,    85,    86,    74,    75,    76,   121,   127,   128,   102,
-      54,    95,    68,    77,   112,    70,   100
+      49,    48,    45,    46,   139,   113,   114,    89,   109,   110,
+     111,    85,   118,    86,    74,    75,    76,   121,   128,   129,
+     102,    54,    95,    68,    77,   112,    70,   127,   100
 };
 
   /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
@@ -786,54 +790,54 @@ static const yytype_int16 yydefgoto[] =
      number is the opposite.  If YYTABLE_NINF, syntax error.  */
 static const yytype_int16 yytable[] =
 {
-      69,     3,    65,  -110,    71,    65,    47,     5,     6,     7,
-       8,     9,    10,    11,    12,    13,   147,   118,    90,    14,
-      15,    51,    50,   148,    65,    65,    92,    52,   129,    53,
-     130,    26,    55,    56,   131,   132,   133,    32,    87,    87,
-      57,   134,   135,    66,    58,    59,    67,   126,    72,    98,
-      60,   115,   117,   116,    61,   116,    62,   119,    40,   -55,
-     136,    93,    66,    66,    63,    67,    67,    94,    64,    79,
-      81,    82,   106,   107,   108,    91,    87,   137,    87,    66,
-      82,   115,    67,    96,    97,   101,   103,   105,    84,   125,
-     122,    65,   120,   142,   143,   144,   139,   146,    42,   141,
-     123,    83,   124,   140,     0,    88,     4,   145,   139,     5,
-       6,     7,     8,     9,    10,    11,    12,    13,     0,     0,
-      99,    14,    15,    16,    17,    18,    19,    20,    21,    22,
-      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
-      33,    34,    35,     0,     0,     0,     0,     0,     0,     0,
-       0,    36,     0,    37,    38,     0,     0,     0,    71,    39,
-      40,     5,     6,     7,     8,     9,    10,    11,    12,    13,
-       0,     0,     0,    14,    15,     0,     0,     0,     0,     0,
-       0,     0,     0,     0,     0,    26,     0,     0,     0,     0,
-       0,    32,     0,     0,     0,     0,     0,     0,     0,     0,
-       0,     0,    72,     0,     0,     0,     0,     0,     0,     0,
-       0,     0,    40
+      69,     3,    47,  -111,    71,    65,    50,     5,     6,     7,
+       8,     9,    10,    11,    12,    13,    53,    55,    90,    14,
+      15,    51,   148,    65,    65,    58,    56,    52,    92,   149,
+      57,    26,    87,    87,   132,   133,   134,    32,   130,    60,
+     131,   135,   136,    66,    61,    59,    67,    66,    72,    98,
+      67,   115,   106,   107,   108,    62,    84,   119,    40,   -55,
+     137,    66,    66,    93,    67,    67,   116,    63,   116,    94,
+      87,    82,    87,    64,    79,    81,    82,   138,    91,   101,
+      96,   115,    97,   103,   105,   117,   120,   122,   125,    65,
+      42,   143,   144,   147,   124,   123,   145,   140,    99,    83,
+     142,   146,     0,    88,   141,   126,     0,     4,     0,   140,
+       5,     6,     7,     8,     9,    10,    11,    12,    13,     0,
+       0,     0,    14,    15,    16,    17,    18,    19,    20,    21,
+      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
+      32,    33,    34,    35,     0,     0,     0,     0,     0,     0,
+       0,     0,    36,     0,    37,    38,     0,     0,     0,    71,
+      39,    40,     5,     6,     7,     8,     9,    10,    11,    12,
+      13,     0,     0,     0,    14,    15,     0,     0,     0,     0,
+       0,     0,     0,     0,     0,     0,    26,     0,     0,     0,
+       0,     0,    32,     0,     0,     0,     0,     0,     0,     0,
+       0,     0,     0,    72,     0,     0,     0,     0,     0,     0,
+       0,     0,     0,    40
 };
 
 static const yytype_int16 yycheck[] =
 {
-      32,     0,     3,     0,     1,     3,    49,     4,     5,     6,
-       7,     8,     9,    10,    11,    12,   139,    87,    50,    16,
-      17,    38,    50,   146,     3,     3,     3,    44,    47,    44,
-      49,    28,     3,    53,    13,    14,    15,    34,    48,    49,
-      53,    20,    21,    41,     3,    38,    44,   117,    45,    46,
-       3,    83,    53,    86,     3,    88,     3,    89,    55,    38,
-      39,    38,    41,    41,     3,    44,    44,    44,     3,    44,
-      38,    50,    50,    51,    52,    38,    86,    56,    88,    41,
-      50,   113,    44,    49,    49,    40,    38,    38,    50,    53,
-      38,     3,    42,    53,    50,    53,   128,    38,     2,   131,
-     109,    46,   113,   129,    -1,    49,     1,    53,   140,     4,
-       5,     6,     7,     8,     9,    10,    11,    12,    -1,    -1,
-      74,    16,    17,    18,    19,    20,    21,    22,    23,    24,
-      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
-      35,    36,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
-      -1,    46,    -1,    48,    49,    -1,    -1,    -1,     1,    54,
-      55,     4,     5,     6,     7,     8,     9,    10,    11,    12,
-      -1,    -1,    -1,    16,    17,    -1,    -1,    -1,    -1,    -1,
-      -1,    -1,    -1,    -1,    -1,    28,    -1,    -1,    -1,    -1,
-      -1,    34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
-      -1,    -1,    45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
-      -1,    -1,    55
+      32,     0,    49,     0,     1,     3,    50,     4,     5,     6,
+       7,     8,     9,    10,    11,    12,    44,     3,    50,    16,
+      17,    38,   140,     3,     3,     3,    53,    44,     3,   147,
+      53,    28,    48,    49,    13,    14,    15,    34,    47,     3,
+      49,    20,    21,    41,     3,    38,    44,    41,    45,    46,
+      44,    83,    50,    51,    52,     3,    50,    89,    55,    38,
+      39,    41,    41,    38,    44,    44,    86,     3,    88,    44,
+      86,    50,    88,     3,    44,    38,    50,    56,    38,    40,
+      49,   113,    49,    38,    38,    53,    42,    38,    53,     3,
+       2,    53,    50,    38,   113,   109,    53,   129,    74,    46,
+     132,    53,    -1,    49,   130,   118,    -1,     1,    -1,   141,
+       4,     5,     6,     7,     8,     9,    10,    11,    12,    -1,
+      -1,    -1,    16,    17,    18,    19,    20,    21,    22,    23,
+      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
+      34,    35,    36,    37,    -1,    -1,    -1,    -1,    -1,    -1,
+      -1,    -1,    46,    -1,    48,    49,    -1,    -1,    -1,     1,
+      54,    55,     4,     5,     6,     7,     8,     9,    10,    11,
+      12,    -1,    -1,    -1,    16,    17,    -1,    -1,    -1,    -1,
+      -1,    -1,    -1,    -1,    -1,    -1,    28,    -1,    -1,    -1,
+      -1,    -1,    34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
+      -1,    -1,    -1,    45,    -1,    -1,    -1,    -1,    -1,    -1,
+      -1,    -1,    -1,    55
 };
 
   /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
@@ -845,16 +849,16 @@ static const yytype_uint8 yystos[] =
       22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
       32,    33,    34,    35,    36,    37,    46,    48,    49,    54,
       55,    60,    63,    64,    66,    69,    70,    49,    68,    67,
-      50,    38,    44,    44,    87,     3,    53,    53,     3,    38,
-       3,     3,     3,     3,     3,     3,    41,    44,    89,    91,
-      92,     1,    45,    63,    80,    81,    82,    90,    61,    44,
-      65,    38,    50,    71,    50,    78,    79,    89,    79,    74,
-      91,    38,     3,    38,    44,    88,    49,    49,    46,    81,
-      93,    40,    86,    38,    62,    38,    50,    51,    52,    75,
-      76,    77,    91,    72,    73,    91,    78,    53,    92,    91,
-      42,    83,    38,    76,    73,    53,    92,    84,    85,    47,
-      49,    13,    14,    15,    20,    21,    39,    56,    71,    91,
-      85,    91,    53,    50,    53,    53,    38,    86,    86
+      50,    38,    44,    44,    88,     3,    53,    53,     3,    38,
+       3,     3,     3,     3,     3,     3,    41,    44,    90,    92,
+      93,     1,    45,    63,    81,    82,    83,    91,    61,    44,
+      65,    38,    50,    71,    50,    78,    80,    90,    80,    74,
+      92,    38,     3,    38,    44,    89,    49,    49,    46,    82,
+      95,    40,    87,    38,    62,    38,    50,    51,    52,    75,
+      76,    77,    92,    72,    73,    92,    78,    53,    79,    92,
+      42,    84,    38,    76,    73,    53,    93,    94,    85,    86,
+      47,    49,    13,    14,    15,    20,    21,    39,    56,    71,
+      92,    86,    92,    53,    50,    53,    53,    38,    87,    87
 };
 
   /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
@@ -867,11 +871,11 @@ static const yytype_uint8 yyr1[] =
       64,    64,    65,    65,    63,    67,    66,    68,    66,    66,
       69,    70,    70,    70,    70,    71,    71,    72,    72,    73,
       73,    74,    74,    75,    75,    76,    76,    77,    77,    77,
-      78,    78,    78,    78,    78,    79,    79,    80,    80,    81,
-      81,    81,    83,    82,    84,    84,    84,    85,    85,    85,
-      85,    85,    85,    85,    85,    85,    85,    86,    86,    87,
-      88,    88,    88,    88,    89,    89,    90,    91,    91,    92,
-      93,    93
+      78,    78,    79,    79,    80,    80,    81,    81,    82,    82,
+      82,    84,    83,    85,    85,    85,    86,    86,    86,    86,
+      86,    86,    86,    86,    86,    86,    87,    87,    88,    89,
+      89,    89,    89,    90,    90,    91,    92,    92,    93,    94,
+      94,    95,    95
 };
 
   /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
@@ -884,11 +888,11 @@ static const yytype_uint8 yyr2[] =
        1,     1,     0,     1,     3,     0,     3,     0,     3,     3,
        3,     1,     1,     1,     1,     0,     1,     1,     2,     1,
        2,     1,     2,     1,     2,     1,     1,     1,     1,     1,
-       1,     1,     2,     2,     3,     1,     2,     1,     2,     1,
-       2,     2,     0,     4,     1,     3,     2,     0,     3,     4,
-       2,     2,     3,     3,     3,     3,     3,     0,     1,     1,
-       0,     1,     1,     1,     1,     1,     1,     1,     1,     1,
-       0,     2
+       1,     3,     0,     1,     1,     2,     1,     2,     1,     2,
+       2,     0,     4,     1,     3,     2,     0,     3,     4,     2,
+       2,     3,     3,     3,     3,     3,     0,     1,     1,     0,
+       1,     1,     1,     1,     1,     1,     1,     1,     1,     0,
+       1,     0,     2
 };
 
 
@@ -1046,73 +1050,73 @@ yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YY
           case 3: /* "string"  */
 #line 191 "src/parse-gram.y" /* yacc.c:681  */
       { fputs (quotearg_style (c_quoting_style, (*(char**)(&(*yyvaluep)))), yyo); }
-#line 1050 "src/parse-gram.c" /* yacc.c:681  */
+#line 1054 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 22: /* "%<flag>"  */
 #line 198 "src/parse-gram.y" /* yacc.c:681  */
       { fprintf (yyo, "%%%s", (*(uniqstr*)(&(*yyvaluep)))); }
-#line 1056 "src/parse-gram.c" /* yacc.c:681  */
+#line 1060 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 38: /* "{...}"  */
 #line 192 "src/parse-gram.y" /* yacc.c:681  */
       { fprintf (yyo, "{\n%s\n}", (*(char**)(&(*yyvaluep)))); }
-#line 1062 "src/parse-gram.c" /* yacc.c:681  */
+#line 1066 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 39: /* "%?{...}"  */
 #line 192 "src/parse-gram.y" /* yacc.c:681  */
       { fprintf (yyo, "{\n%s\n}", (*(char**)(&(*yyvaluep)))); }
-#line 1068 "src/parse-gram.c" /* yacc.c:681  */
+#line 1072 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 40: /* "[identifier]"  */
 #line 196 "src/parse-gram.y" /* yacc.c:681  */
       { fprintf (yyo, "[%s]", (*(uniqstr*)(&(*yyvaluep)))); }
-#line 1074 "src/parse-gram.c" /* yacc.c:681  */
+#line 1078 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 41: /* "char"  */
 #line 188 "src/parse-gram.y" /* yacc.c:681  */
       { fputs (char_name ((*(unsigned char*)(&(*yyvaluep)))), yyo); }
-#line 1080 "src/parse-gram.c" /* yacc.c:681  */
+#line 1084 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 42: /* "epilogue"  */
 #line 192 "src/parse-gram.y" /* yacc.c:681  */
       { fprintf (yyo, "{\n%s\n}", (*(char**)(&(*yyvaluep)))); }
-#line 1086 "src/parse-gram.c" /* yacc.c:681  */
+#line 1090 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 44: /* "identifier"  */
 #line 195 "src/parse-gram.y" /* yacc.c:681  */
       { fputs ((*(uniqstr*)(&(*yyvaluep))), yyo); }
-#line 1092 "src/parse-gram.c" /* yacc.c:681  */
+#line 1096 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 45: /* "identifier:"  */
 #line 197 "src/parse-gram.y" /* yacc.c:681  */
       { fprintf (yyo, "%s:", (*(uniqstr*)(&(*yyvaluep)))); }
-#line 1098 "src/parse-gram.c" /* yacc.c:681  */
+#line 1102 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 48: /* "%{...%}"  */
 #line 192 "src/parse-gram.y" /* yacc.c:681  */
       { fprintf (yyo, "{\n%s\n}", (*(char**)(&(*yyvaluep)))); }
-#line 1104 "src/parse-gram.c" /* yacc.c:681  */
+#line 1108 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 50: /* "<tag>"  */
 #line 199 "src/parse-gram.y" /* yacc.c:681  */
       { fprintf (yyo, "<%s>", (*(uniqstr*)(&(*yyvaluep)))); }
-#line 1110 "src/parse-gram.c" /* yacc.c:681  */
+#line 1114 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 53: /* "integer"  */
 #line 202 "src/parse-gram.y" /* yacc.c:681  */
       { fprintf (yyo, "%d", (*(int*)(&(*yyvaluep)))); }
-#line 1116 "src/parse-gram.c" /* yacc.c:681  */
+#line 1120 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 54: /* "%param"  */
@@ -1129,35 +1133,41 @@ yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YY
       case param_none: aver (false); break;
     }
 }
-#line 1133 "src/parse-gram.c" /* yacc.c:681  */
+#line 1137 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 64: /* code_props_type  */
 #line 376 "src/parse-gram.y" /* yacc.c:681  */
       { fprintf (yyo, "%s", code_props_type_string ((*(code_props_type*)(&(*yyvaluep))))); }
-#line 1139 "src/parse-gram.c" /* yacc.c:681  */
+#line 1143 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 73: /* symbol.prec  */
 #line 205 "src/parse-gram.y" /* yacc.c:681  */
       { fprintf (yyo, "%s", (*(symbol**)(&(*yyvaluep)))->tag); }
-#line 1145 "src/parse-gram.c" /* yacc.c:681  */
+#line 1149 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 77: /* tag  */
 #line 199 "src/parse-gram.y" /* yacc.c:681  */
       { fprintf (yyo, "<%s>", (*(uniqstr*)(&(*yyvaluep)))); }
-#line 1151 "src/parse-gram.c" /* yacc.c:681  */
+#line 1155 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
-    case 87: /* variable  */
+    case 79: /* int.opt  */
+#line 202 "src/parse-gram.y" /* yacc.c:681  */
+      { fprintf (yyo, "%d", (*(int*)(&(*yyvaluep)))); }
+#line 1161 "src/parse-gram.c" /* yacc.c:681  */
+        break;
+
+    case 88: /* variable  */
 #line 195 "src/parse-gram.y" /* yacc.c:681  */
       { fputs ((*(uniqstr*)(&(*yyvaluep))), yyo); }
-#line 1157 "src/parse-gram.c" /* yacc.c:681  */
+#line 1167 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
-    case 88: /* value  */
-#line 646 "src/parse-gram.y" /* yacc.c:681  */
+    case 89: /* value  */
+#line 631 "src/parse-gram.y" /* yacc.c:681  */
       {
   switch ((*(value_type*)(&(*yyvaluep))).kind)
     {
@@ -1166,31 +1176,37 @@ yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YY
     case muscle_string:  fprintf (yyo, "\"%s\"", (*(value_type*)(&(*yyvaluep))).chars); break;
     }
 }
-#line 1170 "src/parse-gram.c" /* yacc.c:681  */
+#line 1180 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
-    case 89: /* id  */
+    case 90: /* id  */
 #line 205 "src/parse-gram.y" /* yacc.c:681  */
       { fprintf (yyo, "%s", (*(symbol**)(&(*yyvaluep)))->tag); }
-#line 1176 "src/parse-gram.c" /* yacc.c:681  */
+#line 1186 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
-    case 90: /* id_colon  */
+    case 91: /* id_colon  */
 #line 206 "src/parse-gram.y" /* yacc.c:681  */
       { fprintf (yyo, "%s:", (*(symbol**)(&(*yyvaluep)))->tag); }
-#line 1182 "src/parse-gram.c" /* yacc.c:681  */
+#line 1192 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
-    case 91: /* symbol  */
+    case 92: /* symbol  */
 #line 205 "src/parse-gram.y" /* yacc.c:681  */
       { fprintf (yyo, "%s", (*(symbol**)(&(*yyvaluep)))->tag); }
-#line 1188 "src/parse-gram.c" /* yacc.c:681  */
+#line 1198 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
-    case 92: /* string_as_id  */
+    case 93: /* string_as_id  */
 #line 205 "src/parse-gram.y" /* yacc.c:681  */
       { fprintf (yyo, "%s", (*(symbol**)(&(*yyvaluep)))->tag); }
-#line 1194 "src/parse-gram.c" /* yacc.c:681  */
+#line 1204 "src/parse-gram.c" /* yacc.c:681  */
+        break;
+
+    case 94: /* string_as_id.opt  */
+#line 205 "src/parse-gram.y" /* yacc.c:681  */
+      { fprintf (yyo, "%s", (*(symbol**)(&(*yyvaluep)))->tag); }
+#line 1210 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
 
@@ -1892,7 +1908,7 @@ YYLTYPE yylloc = yyloc_default;
   boundary_set (&yylloc.end, current_file, 1, 1);
 }
 
-#line 1896 "src/parse-gram.c" /* yacc.c:1428  */
+#line 1912 "src/parse-gram.c" /* yacc.c:1428  */
   yylsp[0] = yylloc;
   goto yysetstate;
 
@@ -2097,7 +2113,7 @@ yyreduce:
                         translate_code ((*(char**)(&yyvsp[0])), (yylsp[0]), true), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2101 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2117 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 7:
@@ -2105,7 +2121,7 @@ yyreduce:
     {
       muscle_percent_define_ensure ((*(uniqstr*)(&yyvsp[0])), (yylsp[0]), true);
     }
-#line 2109 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2125 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 8:
@@ -2114,13 +2130,13 @@ yyreduce:
       muscle_percent_define_insert ((*(uniqstr*)(&yyvsp[-1])), (yylsp[-1]), (*(value_type*)(&yyvsp[0])).kind, (*(value_type*)(&yyvsp[0])).chars,
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
     }
-#line 2118 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2134 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 9:
 #line 290 "src/parse-gram.y" /* yacc.c:1649  */
     { defines_flag = true; }
-#line 2124 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2140 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 10:
@@ -2129,25 +2145,25 @@ yyreduce:
       defines_flag = true;
       spec_defines_file = xstrdup ((*(char**)(&yyvsp[0])));
     }
-#line 2133 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2149 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 11:
 #line 296 "src/parse-gram.y" /* yacc.c:1649  */
     { expected_sr_conflicts = (*(int*)(&yyvsp[0])); }
-#line 2139 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2155 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 12:
 #line 297 "src/parse-gram.y" /* yacc.c:1649  */
     { expected_rr_conflicts = (*(int*)(&yyvsp[0])); }
-#line 2145 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2161 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 13:
 #line 298 "src/parse-gram.y" /* yacc.c:1649  */
     { spec_file_prefix = (*(char**)(&yyvsp[0])); }
-#line 2151 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2167 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 14:
@@ -2156,7 +2172,7 @@ yyreduce:
       nondeterministic_parser = true;
       glr_parser = true;
     }
-#line 2160 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2176 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 15:
@@ -2165,97 +2181,97 @@ yyreduce:
       muscle_code_grow ("initial_action", translate_code ((*(char**)(&yyvsp[0])), (yylsp[0]), false), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2169 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2185 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 16:
 #line 309 "src/parse-gram.y" /* yacc.c:1649  */
     { language_argmatch ((*(char**)(&yyvsp[0])), grammar_prio, (yylsp[-1])); }
-#line 2175 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2191 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 17:
 #line 310 "src/parse-gram.y" /* yacc.c:1649  */
     { spec_name_prefix = (*(char**)(&yyvsp[0])); }
-#line 2181 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2197 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 18:
 #line 311 "src/parse-gram.y" /* yacc.c:1649  */
     { no_lines_flag = true; }
-#line 2187 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2203 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 19:
 #line 312 "src/parse-gram.y" /* yacc.c:1649  */
     { nondeterministic_parser = true; }
-#line 2193 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2209 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 20:
 #line 313 "src/parse-gram.y" /* yacc.c:1649  */
     { spec_outfile = (*(char**)(&yyvsp[0])); }
-#line 2199 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2215 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 21:
 #line 314 "src/parse-gram.y" /* yacc.c:1649  */
     { current_param = (*(param_type*)(&yyvsp[0])); }
-#line 2205 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2221 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 22:
 #line 314 "src/parse-gram.y" /* yacc.c:1649  */
     { current_param = param_none; }
-#line 2211 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2227 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 23:
 #line 315 "src/parse-gram.y" /* yacc.c:1649  */
     { do_require (&(yylsp[0]), (*(char**)(&yyvsp[0]))); }
-#line 2217 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2233 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 24:
 #line 316 "src/parse-gram.y" /* yacc.c:1649  */
     { do_skeleton (&(yylsp[0]), (*(char**)(&yyvsp[0]))); }
-#line 2223 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2239 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 25:
 #line 317 "src/parse-gram.y" /* yacc.c:1649  */
     { token_table_flag = true; }
-#line 2229 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2245 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 26:
 #line 318 "src/parse-gram.y" /* yacc.c:1649  */
     { report_flag |= report_states; }
-#line 2235 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2251 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 27:
 #line 319 "src/parse-gram.y" /* yacc.c:1649  */
     { yacc_flag = true; }
-#line 2241 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2257 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 28:
 #line 320 "src/parse-gram.y" /* yacc.c:1649  */
     { current_class = unknown_sym; yyerrok; }
-#line 2247 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2263 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 30:
 #line 325 "src/parse-gram.y" /* yacc.c:1649  */
     { add_param (current_param, (*(char**)(&yyvsp[0])), (yylsp[0])); }
-#line 2253 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2269 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 31:
 #line 326 "src/parse-gram.y" /* yacc.c:1649  */
     { add_param (current_param, (*(char**)(&yyvsp[0])), (yylsp[0])); }
-#line 2259 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2275 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 34:
@@ -2263,7 +2279,7 @@ yyreduce:
     {
       grammar_start_symbol_set ((*(symbol**)(&yyvsp[0])), (yylsp[0]));
     }
-#line 2267 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2283 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 35:
@@ -2278,7 +2294,7 @@ yyreduce:
         symbol_list_free ((*(symbol_list**)(&yyvsp[0])));
       }
     }
-#line 2282 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2298 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 36:
@@ -2286,7 +2302,7 @@ yyreduce:
     {
       default_prec = true;
     }
-#line 2290 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2306 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 37:
@@ -2294,7 +2310,7 @@ yyreduce:
     {
       default_prec = false;
     }
-#line 2298 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2314 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 38:
@@ -2306,7 +2322,7 @@ yyreduce:
                         translate_code_braceless ((*(char**)(&yyvsp[0])), (yylsp[0])), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2310 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2326 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 39:
@@ -2315,25 +2331,25 @@ yyreduce:
       muscle_percent_code_grow ((*(uniqstr*)(&yyvsp[-1])), (yylsp[-1]), translate_code_braceless ((*(char**)(&yyvsp[0])), (yylsp[0])), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2319 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2335 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 40:
 #line 378 "src/parse-gram.y" /* yacc.c:1649  */
     { (*(code_props_type*)(&yyval)) = destructor; }
-#line 2325 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2341 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 41:
 #line 379 "src/parse-gram.y" /* yacc.c:1649  */
     { (*(code_props_type*)(&yyval)) = printer; }
-#line 2331 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2347 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 42:
 #line 389 "src/parse-gram.y" /* yacc.c:1649  */
     {}
-#line 2337 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2353 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 43:
@@ -2341,7 +2357,7 @@ yyreduce:
     { muscle_percent_define_insert ("api.value.union.name",
                                          (yylsp[0]), muscle_keyword, (*(uniqstr*)(&yyvsp[0])),
                                          MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE); }
-#line 2345 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2361 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 44:
@@ -2351,13 +2367,13 @@ yyreduce:
       muscle_code_grow ("union_members", translate_code_braceless ((*(char**)(&yyvsp[0])), (yylsp[0])), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2355 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2371 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 45:
 #line 408 "src/parse-gram.y" /* yacc.c:1649  */
     { current_class = nterm_sym; }
-#line 2361 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2377 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 46:
@@ -2366,13 +2382,13 @@ yyreduce:
       current_class = unknown_sym;
       current_type = NULL;
     }
-#line 2370 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2386 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 47:
 #line 413 "src/parse-gram.y" /* yacc.c:1649  */
     { current_class = token_sym; }
-#line 2376 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2392 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 48:
@@ -2381,7 +2397,7 @@ yyreduce:
       current_class = unknown_sym;
       current_type = NULL;
     }
-#line 2385 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2401 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 49:
@@ -2392,7 +2408,7 @@ yyreduce:
         symbol_type_set (list->content.sym, (*(uniqstr*)(&yyvsp[-1])), (yylsp[-1]));
       symbol_list_free ((*(symbol_list**)(&yyvsp[0])));
     }
-#line 2396 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2412 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 50:
@@ -2407,55 +2423,55 @@ yyreduce:
       symbol_list_free ((*(symbol_list**)(&yyvsp[0])));
       current_type = NULL;
     }
-#line 2411 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2427 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 51:
 #line 442 "src/parse-gram.y" /* yacc.c:1649  */
     { (*(assoc*)(&yyval)) = left_assoc; }
-#line 2417 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2433 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 52:
 #line 443 "src/parse-gram.y" /* yacc.c:1649  */
     { (*(assoc*)(&yyval)) = right_assoc; }
-#line 2423 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2439 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 53:
 #line 444 "src/parse-gram.y" /* yacc.c:1649  */
     { (*(assoc*)(&yyval)) = non_assoc; }
-#line 2429 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2445 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 54:
 #line 445 "src/parse-gram.y" /* yacc.c:1649  */
     { (*(assoc*)(&yyval)) = precedence_assoc; }
-#line 2435 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2451 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 55:
 #line 449 "src/parse-gram.y" /* yacc.c:1649  */
     { current_type = NULL; }
-#line 2441 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2457 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 56:
 #line 450 "src/parse-gram.y" /* yacc.c:1649  */
     { current_type = (*(uniqstr*)(&yyvsp[0])); tag_seen = true; }
-#line 2447 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2463 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 57:
 #line 456 "src/parse-gram.y" /* yacc.c:1649  */
     { (*(symbol_list**)(&yyval)) = symbol_list_sym_new ((*(symbol**)(&yyvsp[0])), (yylsp[0])); }
-#line 2453 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2469 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 58:
 #line 458 "src/parse-gram.y" /* yacc.c:1649  */
     { (*(symbol_list**)(&yyval)) = symbol_list_append ((*(symbol_list**)(&yyvsp[-1])), symbol_list_sym_new ((*(symbol**)(&yyvsp[0])), (yylsp[0]))); }
-#line 2459 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2475 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 59:
@@ -2464,7 +2480,7 @@ yyreduce:
       (*(symbol**)(&yyval)) = (*(symbol**)(&yyvsp[0]));
       symbol_class_set ((*(symbol**)(&yyvsp[0])), token_sym, (yylsp[0]), false);
     }
-#line 2468 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2484 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 60:
@@ -2474,55 +2490,55 @@ yyreduce:
       symbol_user_token_number_set ((*(symbol**)(&yyvsp[-1])), (*(int*)(&yyvsp[0])), (yylsp[0]));
       symbol_class_set ((*(symbol**)(&yyvsp[-1])), token_sym, (yylsp[-1]), false);
     }
-#line 2478 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2494 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 61:
 #line 478 "src/parse-gram.y" /* yacc.c:1649  */
     { (*(symbol_list**)(&yyval)) = symbol_list_sym_new ((*(symbol**)(&yyvsp[0])), (yylsp[0])); }
-#line 2484 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2500 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 62:
 #line 480 "src/parse-gram.y" /* yacc.c:1649  */
     { (*(symbol_list**)(&yyval)) = symbol_list_append ((*(symbol_list**)(&yyvsp[-1])), symbol_list_sym_new ((*(symbol**)(&yyvsp[0])), (yylsp[0]))); }
-#line 2490 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2506 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 63:
 #line 484 "src/parse-gram.y" /* yacc.c:1649  */
     { (*(symbol_list**)(&yyval)) = (*(symbol_list**)(&yyvsp[0])); }
-#line 2496 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2512 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 64:
 #line 485 "src/parse-gram.y" /* yacc.c:1649  */
     { (*(symbol_list**)(&yyval)) = symbol_list_append ((*(symbol_list**)(&yyvsp[-1])), (*(symbol_list**)(&yyvsp[0]))); }
-#line 2502 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2518 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 65:
 #line 489 "src/parse-gram.y" /* yacc.c:1649  */
     { (*(symbol_list**)(&yyval)) = symbol_list_sym_new ((*(symbol**)(&yyvsp[0])), (yylsp[0])); }
-#line 2508 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2524 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 66:
 #line 490 "src/parse-gram.y" /* yacc.c:1649  */
     { (*(symbol_list**)(&yyval)) = symbol_list_type_new ((*(uniqstr*)(&yyvsp[0])), (yylsp[0])); }
-#line 2514 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2530 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 68:
 #line 495 "src/parse-gram.y" /* yacc.c:1649  */
     { (*(uniqstr*)(&yyval)) = uniqstr_new ("*"); }
-#line 2520 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2536 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 69:
 #line 496 "src/parse-gram.y" /* yacc.c:1649  */
     { (*(uniqstr*)(&yyval)) = uniqstr_new (""); }
-#line 2526 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2542 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 70:
@@ -2531,209 +2547,182 @@ yyreduce:
       current_type = (*(uniqstr*)(&yyvsp[0]));
       tag_seen = true;
     }
-#line 2535 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2551 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 71:
 #line 507 "src/parse-gram.y" /* yacc.c:1649  */
     {
-      symbol_class_set ((*(symbol**)(&yyvsp[0])), current_class, (yylsp[0]), true);
-      symbol_type_set ((*(symbol**)(&yyvsp[0])), current_type, (yylsp[0]));
-    }
-#line 2544 "src/parse-gram.c" /* yacc.c:1649  */
-    break;
-
-  case 72:
-#line 512 "src/parse-gram.y" /* yacc.c:1649  */
-    {
-      if (current_class != token_sym)
+      symbol_class_set ((*(symbol**)(&yyvsp[-2])), current_class, (yylsp[-2]), true);
+      symbol_type_set ((*(symbol**)(&yyvsp[-2])), current_type, (yylsp[-2]));
+      if (0 <= (*(int*)(&yyvsp[-1])))
         {
-          gram_error (&(yylsp[0]),
-                      _("non-terminals cannot be given an explicit number"));
-          YYERROR;
+          if (current_class != token_sym)
+            gram_error (&(yylsp[-1]),
+                        _("non-terminals cannot be given an explicit number"));
+          else
+            symbol_user_token_number_set ((*(symbol**)(&yyvsp[-2])), (*(int*)(&yyvsp[-1])), (yylsp[-1]));
         }
-      symbol_class_set ((*(symbol**)(&yyvsp[-1])), current_class, (yylsp[-1]), true);
-      symbol_type_set ((*(symbol**)(&yyvsp[-1])), current_type, (yylsp[-1]));
-      symbol_user_token_number_set ((*(symbol**)(&yyvsp[-1])), (*(int*)(&yyvsp[0])), (yylsp[0]));
-    }
-#line 2560 "src/parse-gram.c" /* yacc.c:1649  */
-    break;
-
-  case 73:
-#line 524 "src/parse-gram.y" /* yacc.c:1649  */
-    {
-      if (current_class != token_sym)
+      if ((*(symbol**)(&yyvsp[0])))
         {
-          gram_error (&(yylsp[0]),
-                      _("non-terminals cannot be given a string alias"));
-          YYERROR;
+          if (current_class != token_sym)
+            gram_error (&(yylsp[0]),
+                        _("non-terminals cannot be given a string alias"));
+          else
+            symbol_make_alias ((*(symbol**)(&yyvsp[-2])), (*(symbol**)(&yyvsp[0])), (yylsp[0]));
         }
-      symbol_class_set ((*(symbol**)(&yyvsp[-1])), current_class, (yylsp[-1]), true);
-      symbol_type_set ((*(symbol**)(&yyvsp[-1])), current_type, (yylsp[-1]));
-      symbol_make_alias ((*(symbol**)(&yyvsp[-1])), (*(symbol**)(&yyvsp[0])), (yyloc));
+      if (current_class != token_sym && (0 <= (*(int*)(&yyvsp[-1])) || !(*(symbol**)(&yyvsp[0]))))
+        YYERROR;
     }
-#line 2576 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2578 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
-  case 74:
-#line 536 "src/parse-gram.y" /* yacc.c:1649  */
-    {
-      if (current_class != token_sym)
-        {
-          gram_error (&(yylsp[-1]),
-                      _("non-terminals cannot be given an explicit number"));
-          gram_error (&(yylsp[0]),
-                      _("non-terminals cannot be given a string alias"));
-          YYERROR;
-        }
-      symbol_class_set ((*(symbol**)(&yyvsp[-2])), current_class, (yylsp[-2]), true);
-      symbol_type_set ((*(symbol**)(&yyvsp[-2])), current_type, (yylsp[-2]));
-      symbol_user_token_number_set ((*(symbol**)(&yyvsp[-2])), (*(int*)(&yyvsp[-1])), (yylsp[-1]));
-      symbol_make_alias ((*(symbol**)(&yyvsp[-2])), (*(symbol**)(&yyvsp[0])), (yyloc));
-    }
-#line 2595 "src/parse-gram.c" /* yacc.c:1649  */
+  case 72:
+#line 533 "src/parse-gram.y" /* yacc.c:1649  */
+    { (*(int*)(&yyval)) = -1; }
+#line 2584 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
-  case 81:
-#line 577 "src/parse-gram.y" /* yacc.c:1649  */
+  case 80:
+#line 562 "src/parse-gram.y" /* yacc.c:1649  */
     {
       yyerrok;
     }
-#line 2603 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2592 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
-  case 82:
-#line 583 "src/parse-gram.y" /* yacc.c:1649  */
+  case 81:
+#line 568 "src/parse-gram.y" /* yacc.c:1649  */
     { current_lhs ((*(symbol**)(&yyvsp[-1])), (yylsp[-1]), (*(named_ref**)(&yyvsp[0]))); }
-#line 2609 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2598 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
-  case 83:
-#line 584 "src/parse-gram.y" /* yacc.c:1649  */
+  case 82:
+#line 569 "src/parse-gram.y" /* yacc.c:1649  */
     {
       /* Free the current lhs. */
       current_lhs (0, (yylsp[-3]), 0);
     }
-#line 2618 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2607 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
-  case 84:
-#line 591 "src/parse-gram.y" /* yacc.c:1649  */
+  case 83:
+#line 576 "src/parse-gram.y" /* yacc.c:1649  */
     { grammar_current_rule_end ((yylsp[0])); }
-#line 2624 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2613 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
-  case 85:
-#line 592 "src/parse-gram.y" /* yacc.c:1649  */
+  case 84:
+#line 577 "src/parse-gram.y" /* yacc.c:1649  */
     { grammar_current_rule_end ((yylsp[0])); }
-#line 2630 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2619 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
-  case 87:
-#line 599 "src/parse-gram.y" /* yacc.c:1649  */
+  case 86:
+#line 584 "src/parse-gram.y" /* yacc.c:1649  */
     { grammar_current_rule_begin (current_lhs_symbol, current_lhs_location,
                                   current_lhs_named_ref); }
-#line 2637 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2626 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
-  case 88:
-#line 602 "src/parse-gram.y" /* yacc.c:1649  */
+  case 87:
+#line 587 "src/parse-gram.y" /* yacc.c:1649  */
     { grammar_current_rule_symbol_append ((*(symbol**)(&yyvsp[-1])), (yylsp[-1]), (*(named_ref**)(&yyvsp[0]))); }
-#line 2643 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2632 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
-  case 89:
-#line 604 "src/parse-gram.y" /* yacc.c:1649  */
+  case 88:
+#line 589 "src/parse-gram.y" /* yacc.c:1649  */
     { grammar_current_rule_action_append ((*(char**)(&yyvsp[-1])), (yylsp[-1]), (*(named_ref**)(&yyvsp[0])), current_type); }
-#line 2649 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2638 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
-  case 90:
-#line 606 "src/parse-gram.y" /* yacc.c:1649  */
+  case 89:
+#line 591 "src/parse-gram.y" /* yacc.c:1649  */
     { grammar_current_rule_predicate_append ((*(char**)(&yyvsp[0])), (yylsp[0])); }
-#line 2655 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2644 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
-  case 91:
-#line 608 "src/parse-gram.y" /* yacc.c:1649  */
+  case 90:
+#line 593 "src/parse-gram.y" /* yacc.c:1649  */
     { grammar_current_rule_empty_set ((yylsp[0])); }
-#line 2661 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2650 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
-  case 92:
-#line 610 "src/parse-gram.y" /* yacc.c:1649  */
+  case 91:
+#line 595 "src/parse-gram.y" /* yacc.c:1649  */
     { grammar_current_rule_prec_set ((*(symbol**)(&yyvsp[0])), (yylsp[0])); }
-#line 2667 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2656 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
-  case 93:
-#line 612 "src/parse-gram.y" /* yacc.c:1649  */
+  case 92:
+#line 597 "src/parse-gram.y" /* yacc.c:1649  */
     { grammar_current_rule_dprec_set ((*(int*)(&yyvsp[0])), (yylsp[0])); }
-#line 2673 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2662 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
-  case 94:
-#line 614 "src/parse-gram.y" /* yacc.c:1649  */
+  case 93:
+#line 599 "src/parse-gram.y" /* yacc.c:1649  */
     { grammar_current_rule_merge_set ((*(uniqstr*)(&yyvsp[0])), (yylsp[0])); }
-#line 2679 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2668 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
-  case 95:
-#line 616 "src/parse-gram.y" /* yacc.c:1649  */
+  case 94:
+#line 601 "src/parse-gram.y" /* yacc.c:1649  */
     { grammar_current_rule_expect_sr ((*(int*)(&yyvsp[0])), (yylsp[0])); }
-#line 2685 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2674 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
-  case 96:
-#line 618 "src/parse-gram.y" /* yacc.c:1649  */
+  case 95:
+#line 603 "src/parse-gram.y" /* yacc.c:1649  */
     { grammar_current_rule_expect_rr ((*(int*)(&yyvsp[0])), (yylsp[0])); }
-#line 2691 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2680 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
-  case 97:
-#line 622 "src/parse-gram.y" /* yacc.c:1649  */
+  case 96:
+#line 607 "src/parse-gram.y" /* yacc.c:1649  */
     { (*(named_ref**)(&yyval)) = 0; }
-#line 2697 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2686 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
-  case 98:
-#line 623 "src/parse-gram.y" /* yacc.c:1649  */
+  case 97:
+#line 608 "src/parse-gram.y" /* yacc.c:1649  */
     { (*(named_ref**)(&yyval)) = named_ref_new ((*(uniqstr*)(&yyvsp[0])), (yylsp[0])); }
-#line 2703 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2692 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
-  case 100:
-#line 656 "src/parse-gram.y" /* yacc.c:1649  */
+  case 99:
+#line 641 "src/parse-gram.y" /* yacc.c:1649  */
     { (*(value_type*)(&yyval)).kind = muscle_keyword; (*(value_type*)(&yyval)).chars = ""; }
-#line 2709 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2698 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
-  case 101:
-#line 657 "src/parse-gram.y" /* yacc.c:1649  */
+  case 100:
+#line 642 "src/parse-gram.y" /* yacc.c:1649  */
     { (*(value_type*)(&yyval)).kind = muscle_keyword; (*(value_type*)(&yyval)).chars = (*(uniqstr*)(&yyvsp[0])); }
-#line 2715 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2704 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
-  case 102:
-#line 658 "src/parse-gram.y" /* yacc.c:1649  */
+  case 101:
+#line 643 "src/parse-gram.y" /* yacc.c:1649  */
     { (*(value_type*)(&yyval)).kind = muscle_string;  (*(value_type*)(&yyval)).chars = (*(char**)(&yyvsp[0])); }
-#line 2721 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2710 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
-  case 103:
-#line 659 "src/parse-gram.y" /* yacc.c:1649  */
+  case 102:
+#line 644 "src/parse-gram.y" /* yacc.c:1649  */
     { (*(value_type*)(&yyval)).kind = muscle_code;    (*(value_type*)(&yyval)).chars = strip_braces ((*(char**)(&yyvsp[0]))); }
-#line 2727 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2716 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
-  case 104:
-#line 672 "src/parse-gram.y" /* yacc.c:1649  */
+  case 103:
+#line 657 "src/parse-gram.y" /* yacc.c:1649  */
     { (*(symbol**)(&yyval)) = symbol_from_uniqstr ((*(uniqstr*)(&yyvsp[0])), (yylsp[0])); }
-#line 2733 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2722 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
-  case 105:
-#line 674 "src/parse-gram.y" /* yacc.c:1649  */
+  case 104:
+#line 659 "src/parse-gram.y" /* yacc.c:1649  */
     {
       if (current_class == nterm_sym)
         {
@@ -2745,35 +2734,41 @@ yyreduce:
       symbol_class_set ((*(symbol**)(&yyval)), token_sym, (yylsp[0]), false);
       symbol_user_token_number_set ((*(symbol**)(&yyval)), (*(unsigned char*)(&yyvsp[0])), (yylsp[0]));
     }
-#line 2749 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2738 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
-  case 106:
-#line 688 "src/parse-gram.y" /* yacc.c:1649  */
+  case 105:
+#line 673 "src/parse-gram.y" /* yacc.c:1649  */
     { (*(symbol**)(&yyval)) = symbol_from_uniqstr ((*(uniqstr*)(&yyvsp[0])), (yylsp[0])); }
-#line 2755 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2744 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
-  case 109:
-#line 700 "src/parse-gram.y" /* yacc.c:1649  */
+  case 108:
+#line 685 "src/parse-gram.y" /* yacc.c:1649  */
     {
       (*(symbol**)(&yyval)) = symbol_get (quotearg_style (c_quoting_style, (*(char**)(&yyvsp[0]))), (yylsp[0]));
       symbol_class_set ((*(symbol**)(&yyval)), token_sym, (yylsp[0]), false);
     }
-#line 2764 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2753 "src/parse-gram.c" /* yacc.c:1649  */
+    break;
+
+  case 109:
+#line 693 "src/parse-gram.y" /* yacc.c:1649  */
+    { (*(symbol**)(&yyval)) = NULL; }
+#line 2759 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
-  case 111:
-#line 709 "src/parse-gram.y" /* yacc.c:1649  */
+  case 112:
+#line 700 "src/parse-gram.y" /* yacc.c:1649  */
     {
       muscle_code_grow ("epilogue", translate_code ((*(char**)(&yyvsp[0])), (yylsp[0]), true), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2773 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2768 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
 
-#line 2777 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2772 "src/parse-gram.c" /* yacc.c:1649  */
         default: break;
       }
     if (yychar_backup != yychar)
@@ -3022,7 +3017,7 @@ yyreturn:
 #endif
   return yyresult;
 }
-#line 715 "src/parse-gram.y" /* yacc.c:1915  */
+#line 706 "src/parse-gram.y" /* yacc.c:1915  */
 
 
 /* Return the location of the left-hand side of a rule whose
