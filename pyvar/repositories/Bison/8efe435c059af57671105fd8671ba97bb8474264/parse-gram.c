@@ -74,6 +74,20 @@
 
 /* Produce verbose parse errors.  */
 #define YYERROR_VERBOSE 1
+#define YYLLOC_DEFAULT(Current, Rhs, N)			\
+do {							\
+  if (N)						\
+  {							\
+    Current.first_column  = Rhs[1].first_column;	\
+    Current.first_line    = Rhs[1].first_line;		\
+    Current.last_column   = Rhs[N].last_column;		\
+    Current.last_line     = Rhs[N].last_line;		\
+  }							\
+  else							\
+  {							\
+    Current = Rhs[0];					\
+  }							\
+} while (0)
 
 /* Pass the control structure to YYPARSE and YYLEX. */
 #define YYPARSE_PARAM gram_control
@@ -98,6 +112,7 @@ static void yyprint (FILE *file, const location_t *loc,
 symbol_class current_class = unknown_sym;
 char *current_type = 0;
 symbol_t *current_lhs;
+location_t current_lhs_location;
 associativity current_assoc;
 int current_prec = 0;
 
@@ -207,15 +222,15 @@ int current_prec = 0;
 #endif
 
 #ifndef YYSTYPE
-#line 74 "parse-gram.y"
+#line 89 "parse-gram.y"
 typedef union {
   symbol_t *symbol;
   int integer;
   char *string;
   associativity assoc;
 } yystype;
-/* Line 199 of /home/akim/src/bison/data/bison.simple.  */
-#line 219 "parse-gram.c"
+/* Line 199 of /usr/local/share/bison/bison.simple.  */
+#line 234 "parse-gram.c"
 # define YYSTYPE yystype
 # define YYSTYPE_IS_TRIVIAL 1
 #endif
@@ -235,8 +250,8 @@ typedef struct yyltype
 /* Copy the second part of user declarations.  */
 
 
-/* Line 219 of /home/akim/src/bison/data/bison.simple.  */
-#line 240 "parse-gram.c"
+/* Line 219 of /usr/local/share/bison/bison.simple.  */
+#line 255 "parse-gram.c"
 
 #if ! defined (yyoverflow) || YYERROR_VERBOSE
 
@@ -338,16 +353,16 @@ union yyalloc
 /* YYFINAL -- State number of the termination state. */
 #define YYFINAL  3
 #define YYFLAG	 -32768
-#define YYLAST   91
+#define YYLAST   90
 
 /* YYNTOKENS -- Number of terminals. */
 #define YYNTOKENS  40
 /* YYNNTS -- Number of nonterminals. */
-#define YYNNTS  30
+#define YYNNTS  29
 /* YYNRULES -- Number of rules. */
-#define YYNRULES  72
+#define YYNRULES  71
 /* YYNRULES -- Number of states. */
-#define YYNSTATES  98
+#define YYNSTATES  97
 
 /* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
 #define YYUNDEFTOK  2
@@ -396,51 +411,50 @@ static const unsigned char yytranslate[] =
    YYRHS.  */
 static const unsigned char yyprhs[] =
 {
-       0,     0,     3,     4,    10,    11,    15,    17,    19,    21,
-      25,    27,    29,    32,    36,    38,    42,    44,    48,    50,
-      53,    55,    57,    59,    61,    63,    66,    69,    70,    74,
-      75,    79,    80,    85,    86,    91,    93,    95,    97,    98,
-     100,   102,   105,   107,   110,   112,   114,   117,   120,   124,
-     126,   129,   131,   134,   136,   139,   140,   146,   148,   152,
-     153,   156,   159,   163,   165,   167,   169,   171,   173,   175,
-     176,   179,   180
+       0,     0,     3,     8,     9,    13,    15,    17,    19,    23,
+      25,    27,    30,    34,    36,    40,    42,    46,    48,    51,
+      53,    55,    57,    59,    61,    64,    67,    68,    72,    73,
+      77,    78,    83,    84,    89,    91,    93,    95,    96,    98,
+     100,   103,   105,   108,   110,   112,   115,   118,   122,   124,
+     127,   129,   132,   134,   137,   138,   144,   146,   150,   151,
+     154,   157,   161,   163,   165,   167,   169,   171,   173,   174,
+     177,   178
 };
 
 /* YYRHS -- A `-1'-separated list of the rules' RHS. */
 static const signed char yyrhs[] =
 {
-      41,     0,    -1,    -1,    42,    43,    33,    58,    68,    -1,
-      -1,    43,    44,    69,    -1,    45,    -1,    34,    -1,    22,
-      -1,    18,    67,    67,    -1,    20,    -1,    14,    -1,    10,
-       5,    -1,    16,    28,    67,    -1,    23,    -1,    17,    28,
-      67,    -1,    24,    -1,    15,    28,    67,    -1,    19,    -1,
-      25,    67,    -1,    26,    -1,    13,    -1,    21,    -1,    50,
-      -1,    46,    -1,    11,    64,    -1,     9,    36,    -1,    -1,
-       7,    47,    57,    -1,    -1,     6,    48,    57,    -1,    -1,
-       8,    27,    49,    54,    -1,    -1,    52,    53,    51,    55,
-      -1,    37,    -1,    38,    -1,    39,    -1,    -1,    27,    -1,
-      32,    -1,    54,    32,    -1,    64,    -1,    55,    64,    -1,
-      27,    -1,    32,    -1,    32,     5,    -1,    32,    66,    -1,
-      32,     5,    66,    -1,    56,    -1,    57,    56,    -1,    59,
-      -1,    58,    59,    -1,    60,    -1,    45,    29,    -1,    -1,
-      32,    30,    61,    62,    29,    -1,    63,    -1,    62,    31,
-      63,    -1,    -1,    63,    64,    -1,    63,    65,    -1,    63,
-      12,    64,    -1,    32,    -1,    66,    -1,     4,    -1,    36,
-      -1,     3,    -1,     3,    -1,    -1,    33,    35,    -1,    -1,
-      29,    -1
+      41,     0,    -1,    42,    33,    57,    67,    -1,    -1,    42,
+      43,    68,    -1,    44,    -1,    34,    -1,    22,    -1,    18,
+      66,    66,    -1,    20,    -1,    14,    -1,    10,     5,    -1,
+      16,    28,    66,    -1,    23,    -1,    17,    28,    66,    -1,
+      24,    -1,    15,    28,    66,    -1,    19,    -1,    25,    66,
+      -1,    26,    -1,    13,    -1,    21,    -1,    49,    -1,    45,
+      -1,    11,    63,    -1,     9,    36,    -1,    -1,     7,    46,
+      56,    -1,    -1,     6,    47,    56,    -1,    -1,     8,    27,
+      48,    53,    -1,    -1,    51,    52,    50,    54,    -1,    37,
+      -1,    38,    -1,    39,    -1,    -1,    27,    -1,    32,    -1,
+      53,    32,    -1,    63,    -1,    54,    63,    -1,    27,    -1,
+      32,    -1,    32,     5,    -1,    32,    65,    -1,    32,     5,
+      65,    -1,    55,    -1,    56,    55,    -1,    58,    -1,    57,
+      58,    -1,    59,    -1,    44,    29,    -1,    -1,    32,    30,
+      60,    61,    29,    -1,    62,    -1,    61,    31,    62,    -1,
+      -1,    62,    63,    -1,    62,    64,    -1,    62,    12,    63,
+      -1,    32,    -1,    65,    -1,     4,    -1,    36,    -1,     3,
+      -1,     3,    -1,    -1,    33,    35,    -1,    -1,    29,    -1
 };
 
 /* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
 static const unsigned short yyrline[] =
 {
-       0,   131,   131,   131,   144,   146,   149,   151,   152,   153,
-     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
-     164,   165,   166,   169,   171,   172,   176,   184,   184,   190,
-     190,   195,   195,   201,   201,   211,   213,   214,   217,   219,
-     223,   225,   229,   235,   243,   248,   253,   259,   265,   275,
-     278,   287,   289,   295,   297,   300,   300,   305,   307,   310,
-     313,   315,   317,   321,   323,   324,   327,   333,   342,   350,
-     355,   361,   363
+       0,   146,   146,   159,   161,   164,   166,   167,   168,   169,
+     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
+     180,   181,   184,   186,   187,   191,   199,   199,   205,   205,
+     210,   210,   216,   216,   226,   228,   229,   232,   234,   238,
+     240,   244,   250,   258,   263,   268,   274,   280,   290,   293,
+     302,   304,   310,   312,   315,   315,   320,   322,   325,   328,
+     330,   332,   336,   338,   339,   342,   348,   357,   365,   370,
+     376,   378
 };
 #endif
 
@@ -457,11 +471,11 @@ static const char *const yytname[] =
   "\"%locations\"", "\"%no-lines\"", "\"%skeleton\"", "\"%token-table\"", 
   "TYPE", "\"=\"", "\";\"", "\":\"", "\"|\"", "\"identifier\"", "\"%%\"", 
   "PROLOGUE", "EPILOGUE", "BRACED_CODE", "\"%left\"", "\"%right\"", 
-  "\"%nonassoc\"", "$axiom", "input", "@1", "declarations", "declaration", 
-  "grammar_declaration", "symbol_declaration", "@2", "@3", "@4", 
-  "precedence_declaration", "@5", "precedence_declarator", "type.opt", 
+  "\"%nonassoc\"", "$axiom", "input", "declarations", "declaration", 
+  "grammar_declaration", "symbol_declaration", "@1", "@2", "@3", 
+  "precedence_declaration", "@4", "precedence_declarator", "type.opt", 
   "nterms_to_type.1", "terms_to_prec.1", "symbol_def", "symbol_defs.1", 
-  "grammar", "rules_or_grammar_declaration", "rules", "@6", "rhses.1", 
+  "grammar", "rules_or_grammar_declaration", "rules", "@5", "rhses.1", 
   "rhs", "symbol", "action", "string_as_id", "string_content", 
   "epilogue.opt", "semi_colon.opt", 0
 };
@@ -481,27 +495,27 @@ static const short yytoknum[] =
 /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
 static const unsigned char yyr1[] =
 {
-       0,    40,    42,    41,    43,    43,    44,    44,    44,    44,
-      44,    44,    44,    44,    44,    44,    44,    44,    44,    44,
-      44,    44,    44,    45,    45,    45,    45,    47,    46,    48,
-      46,    49,    46,    51,    50,    52,    52,    52,    53,    53,
-      54,    54,    55,    55,    56,    56,    56,    56,    56,    57,
-      57,    58,    58,    59,    59,    61,    60,    62,    62,    63,
-      63,    63,    63,    64,    64,    64,    65,    66,    67,    68,
-      68,    69,    69
+       0,    40,    41,    42,    42,    43,    43,    43,    43,    43,
+      43,    43,    43,    43,    43,    43,    43,    43,    43,    43,
+      43,    43,    44,    44,    44,    44,    46,    45,    47,    45,
+      48,    45,    50,    49,    51,    51,    51,    52,    52,    53,
+      53,    54,    54,    55,    55,    55,    55,    55,    56,    56,
+      57,    57,    58,    58,    60,    59,    61,    61,    62,    62,
+      62,    62,    63,    63,    63,    64,    65,    66,    67,    67,
+      68,    68
 };
 
 /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
 static const unsigned char yyr2[] =
 {
-       0,     2,     0,     5,     0,     3,     1,     1,     1,     3,
-       1,     1,     2,     3,     1,     3,     1,     3,     1,     2,
-       1,     1,     1,     1,     1,     2,     2,     0,     3,     0,
-       3,     0,     4,     0,     4,     1,     1,     1,     0,     1,
-       1,     2,     1,     2,     1,     1,     2,     2,     3,     1,
-       2,     1,     2,     1,     2,     0,     5,     1,     3,     0,
-       2,     2,     3,     1,     1,     1,     1,     1,     1,     0,
-       2,     0,     1
+       0,     2,     4,     0,     3,     1,     1,     1,     3,     1,
+       1,     2,     3,     1,     3,     1,     3,     1,     2,     1,
+       1,     1,     1,     1,     2,     2,     0,     3,     0,     3,
+       0,     4,     0,     4,     1,     1,     1,     0,     1,     1,
+       2,     1,     2,     1,     1,     2,     2,     3,     1,     2,
+       1,     2,     1,     2,     0,     5,     1,     3,     0,     2,
+       2,     3,     1,     1,     1,     1,     1,     1,     0,     2,
+       0,     1
 };
 
 /* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
@@ -509,48 +523,48 @@ static const unsigned char yyr2[] =
    means the default is an error.  */
 static const short yydefact[] =
 {
-       2,     0,     4,     0,     0,    29,    27,     0,     0,     0,
-       0,    21,    11,     0,     0,     0,     0,    18,    10,    22,
-       8,    14,    16,     0,    20,     0,     7,    35,    36,    37,
-      71,     6,    24,    23,    38,     0,     0,    31,    26,    12,
-      67,    65,    63,    25,    64,     0,     0,     0,    68,     0,
-      19,     0,     0,    69,    51,    53,    72,     5,    39,    33,
-      44,    45,    49,    30,    28,     0,    17,    13,    15,     9,
-      55,    54,     0,    52,     3,     0,    46,    47,    50,    40,
-      32,    59,    70,    34,    42,    48,    41,     0,    57,    43,
-      56,    59,     0,    66,    60,    61,    58,    62
+       3,     0,     0,     0,    28,    26,     0,     0,     0,     0,
+      20,    10,     0,     0,     0,     0,    17,     9,    21,     7,
+      13,    15,     0,    19,     0,     6,    34,    35,    36,    70,
+       5,    23,    22,    37,     0,     0,    30,    25,    11,    66,
+      64,    62,    24,    63,     0,     0,     0,    67,     0,    18,
+       0,     0,    68,    50,    52,    71,     4,    38,    32,    43,
+      44,    48,    29,    27,     0,    16,    12,    14,     8,    54,
+      53,     0,    51,     2,     0,    45,    46,    49,    39,    31,
+      58,    69,    33,    41,    47,    40,     0,    56,    42,    55,
+      58,     0,    65,    59,    60,    57,    61
 };
 
 /* YYPGOTO[NTERM-NUM]. */
 static const short yydefgoto[] =
 {
-      -1,     1,     2,     4,    30,    52,    32,    36,    35,    65,
-      33,    75,    34,    59,    80,    83,    62,    63,    53,    54,
-      55,    81,    87,    88,    94,    95,    44,    49,    74,    57
+      -1,     1,     2,    29,    51,    31,    35,    34,    64,    32,
+      74,    33,    58,    79,    82,    61,    62,    52,    53,    54,
+      80,    86,    87,    93,    94,    43,    48,    73,    56
 };
 
 /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
    STATE-NUM.  */
 static const short yypact[] =
 {
-  -32768,     7,-32768,-32768,    -5,-32768,-32768,    -1,    11,    51,
-      38,-32768,-32768,    36,    43,    44,    66,-32768,-32768,-32768,
-  -32768,-32768,-32768,    66,-32768,    29,-32768,-32768,-32768,-32768,
-      45,-32768,-32768,-32768,    48,    18,    18,-32768,-32768,-32768,
-  -32768,-32768,-32768,-32768,-32768,    66,    66,    66,-32768,    66,
-  -32768,    46,    49,    16,-32768,-32768,-32768,-32768,-32768,-32768,
-  -32768,    41,-32768,    18,    18,    52,-32768,-32768,-32768,-32768,
-  -32768,-32768,    42,-32768,-32768,    38,    82,-32768,-32768,-32768,
-      54,-32768,-32768,    38,-32768,-32768,-32768,    31,    27,-32768,
-  -32768,-32768,    38,-32768,-32768,-32768,    27,-32768
+  -32768,     7,    -5,-32768,-32768,-32768,    -1,    11,    46,    38,
+  -32768,-32768,    36,    43,    44,    66,-32768,-32768,-32768,-32768,
+  -32768,-32768,    66,-32768,    29,-32768,-32768,-32768,-32768,    48,
+  -32768,-32768,-32768,    52,    18,    18,-32768,-32768,-32768,-32768,
+  -32768,-32768,-32768,-32768,    66,    66,    66,-32768,    66,-32768,
+      50,    54,    16,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
+      41,-32768,    18,    18,    49,-32768,-32768,-32768,-32768,-32768,
+  -32768,    51,-32768,-32768,    38,    81,-32768,-32768,-32768,    53,
+  -32768,-32768,    38,-32768,-32768,-32768,    31,    27,-32768,-32768,
+  -32768,    38,-32768,-32768,-32768,    27,-32768
 };
 
 /* YYPGOTO[NTERM-NUM].  */
 static const short yypgoto[] =
 {
-  -32768,-32768,-32768,-32768,-32768,    83,-32768,-32768,-32768,-32768,
-  -32768,-32768,-32768,-32768,-32768,-32768,   -12,    53,-32768,    35,
-  -32768,-32768,-32768,     0,   -10,-32768,   -18,    34,-32768,-32768
+  -32768,-32768,-32768,-32768,    85,-32768,-32768,-32768,-32768,-32768,
+  -32768,-32768,-32768,-32768,-32768,    -6,    55,-32768,    37,-32768,
+  -32768,-32768,    -2,    -9,-32768,   -17,    30,-32768,-32768
 };
 
 /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
@@ -558,30 +572,30 @@ static const short yypgoto[] =
    number is the opposite.  If zero, do what YYDEFACT says.  */
 static const short yytable[] =
 {
-      43,     5,     6,     7,     8,     9,    10,     3,    11,    12,
-      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
-      23,    24,     5,     6,     7,     8,    37,    10,    25,    26,
-      40,    41,    27,    28,    29,     5,     6,     7,     8,    92,
-      10,    40,    41,    77,    40,    60,    76,    38,    51,    72,
-      61,    78,    78,    27,    28,    29,    39,    50,    85,    42,
-      90,    51,    91,    93,    45,    84,    27,    28,    29,    48,
-      42,    46,    47,    89,    56,    58,    70,    82,    71,    66,
-      67,    68,    97,    69,    79,    40,    86,    31,    73,    64,
-       0,    96
+      42,     4,     5,     6,     7,     8,     9,     3,    10,    11,
+      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
+      22,    23,     4,     5,     6,     7,    36,     9,    24,    25,
+      39,    40,    26,    27,    28,     4,     5,     6,     7,    91,
+       9,    39,    40,    76,    39,    59,    75,    37,    50,    71,
+      60,    38,    49,    26,    27,    28,    77,    77,    84,    41,
+      89,    50,    90,    92,    44,    83,    26,    27,    28,    47,
+      41,    45,    46,    88,    65,    66,    67,    55,    68,    57,
+      69,    78,    96,    70,    39,    85,    81,    30,    95,    72,
+      63
 };
 
 static const short yycheck[] =
 {
-      10,     6,     7,     8,     9,    10,    11,     0,    13,    14,
+       9,     6,     7,     8,     9,    10,    11,     0,    13,    14,
       15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
       25,    26,     6,     7,     8,     9,    27,    11,    33,    34,
        3,     4,    37,    38,    39,     6,     7,     8,     9,    12,
-      11,     3,     4,    61,     3,    27,     5,    36,    32,    33,
-      32,    63,    64,    37,    38,    39,     5,    23,    76,    32,
-      29,    32,    31,    36,    28,    75,    37,    38,    39,     3,
-      32,    28,    28,    83,    29,    27,    30,    35,    29,    45,
-      46,    47,    92,    49,    32,     3,    32,     4,    53,    36,
-      -1,    91
+      11,     3,     4,    60,     3,    27,     5,    36,    32,    33,
+      32,     5,    22,    37,    38,    39,    62,    63,    75,    32,
+      29,    32,    31,    36,    28,    74,    37,    38,    39,     3,
+      32,    28,    28,    82,    44,    45,    46,    29,    48,    27,
+      30,    32,    91,    29,     3,    32,    35,     2,    90,    52,
+      35
 };
 
 #if YYDEBUG
@@ -589,16 +603,16 @@ static const short yycheck[] =
    symbol of state STATE-NUM.  */
 static const unsigned char yystos[] =
 {
-       0,    41,    42,     0,    43,     6,     7,     8,     9,    10,
-      11,    13,    14,    15,    16,    17,    18,    19,    20,    21,
-      22,    23,    24,    25,    26,    33,    34,    37,    38,    39,
-      44,    45,    46,    50,    52,    48,    47,    27,    36,     5,
-       3,     4,    32,    64,    66,    28,    28,    28,     3,    67,
-      67,    32,    45,    58,    59,    60,    29,    69,    27,    53,
-      27,    32,    56,    57,    57,    49,    67,    67,    67,    67,
-      30,    29,    33,    59,    68,    51,     5,    66,    56,    32,
-      54,    61,    35,    55,    64,    66,    32,    62,    63,    64,
-      29,    31,    12,    36,    64,    65,    63,    64
+       0,    41,    42,     0,     6,     7,     8,     9,    10,    11,
+      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
+      23,    24,    25,    26,    33,    34,    37,    38,    39,    43,
+      44,    45,    49,    51,    47,    46,    27,    36,     5,     3,
+       4,    32,    63,    65,    28,    28,    28,     3,    66,    66,
+      32,    44,    57,    58,    59,    29,    68,    27,    52,    27,
+      32,    55,    56,    56,    48,    66,    66,    66,    66,    30,
+      29,    33,    58,    67,    50,     5,    65,    55,    32,    53,
+      60,    35,    54,    63,    65,    32,    61,    62,    63,    29,
+      31,    12,    36,    63,    64,    62,    63
 };
 #endif
 
@@ -1168,107 +1182,102 @@ yyreduce:
   switch (yyn)
     {
         case 2:
-#line 131 "parse-gram.y"
-    { LOCATION_RESET (yylloc); }
-    break;
-
-  case 3:
-#line 133 "parse-gram.y"
+#line 148 "parse-gram.y"
     {
       yycontrol->errcode = 0;
       epilogue_set (yyvsp[0].string, yylsp[0]);
     }
     break;
 
-  case 7:
-#line 151 "parse-gram.y"
+  case 6:
+#line 166 "parse-gram.y"
     { prologue_augment (yyvsp[0].string, yylsp[0]); }
     break;
 
-  case 8:
-#line 152 "parse-gram.y"
+  case 7:
+#line 167 "parse-gram.y"
     { debug_flag = 1; }
     break;
 
-  case 9:
-#line 153 "parse-gram.y"
+  case 8:
+#line 168 "parse-gram.y"
     { muscle_insert (yyvsp[-1].string, yyvsp[0].string); }
     break;
 
-  case 10:
-#line 154 "parse-gram.y"
+  case 9:
+#line 169 "parse-gram.y"
     { defines_flag = 1; }
     break;
 
-  case 11:
-#line 155 "parse-gram.y"
+  case 10:
+#line 170 "parse-gram.y"
     { error_verbose = 1; }
     break;
 
-  case 12:
-#line 156 "parse-gram.y"
+  case 11:
+#line 171 "parse-gram.y"
     { expected_conflicts = yyvsp[0].integer; }
     break;
 
-  case 13:
-#line 157 "parse-gram.y"
+  case 12:
+#line 172 "parse-gram.y"
     { spec_file_prefix = yyvsp[0].string; }
     break;
 
-  case 14:
-#line 158 "parse-gram.y"
+  case 13:
+#line 173 "parse-gram.y"
     { locations_flag = 1; }
     break;
 
-  case 15:
-#line 159 "parse-gram.y"
+  case 14:
+#line 174 "parse-gram.y"
     { spec_name_prefix = yyvsp[0].string; }
     break;
 
-  case 16:
-#line 160 "parse-gram.y"
+  case 15:
+#line 175 "parse-gram.y"
     { no_lines_flag = 1; }
     break;
 
-  case 17:
-#line 161 "parse-gram.y"
+  case 16:
+#line 176 "parse-gram.y"
     { spec_outfile = yyvsp[0].string; }
     break;
 
-  case 18:
-#line 162 "parse-gram.y"
+  case 17:
+#line 177 "parse-gram.y"
     { pure_parser = 1; }
     break;
 
-  case 19:
-#line 163 "parse-gram.y"
+  case 18:
+#line 178 "parse-gram.y"
     { skeleton = yyvsp[0].string; }
     break;
 
-  case 20:
-#line 164 "parse-gram.y"
+  case 19:
+#line 179 "parse-gram.y"
     { token_table_flag = 1; }
     break;
 
-  case 21:
-#line 165 "parse-gram.y"
+  case 20:
+#line 180 "parse-gram.y"
     { report_flag = 1; }
     break;
 
-  case 22:
-#line 166 "parse-gram.y"
+  case 21:
+#line 181 "parse-gram.y"
     { yacc_flag = 1; }
     break;
 
-  case 25:
-#line 173 "parse-gram.y"
+  case 24:
+#line 188 "parse-gram.y"
     {
-      grammar_start_symbol_set (yyvsp[0].symbol);
+      grammar_start_symbol_set (yyvsp[0].symbol, yylsp[0]);
     }
     break;
 
-  case 26:
-#line 177 "parse-gram.y"
+  case 25:
+#line 192 "parse-gram.y"
     {
       typed = 1;
       MUSCLE_INSERT_INT ("stype_line", yylsp[0].first_line);
@@ -1276,122 +1285,122 @@ yyreduce:
     }
     break;
 
-  case 27:
-#line 185 "parse-gram.y"
+  case 26:
+#line 200 "parse-gram.y"
     { current_class = nterm_sym; }
     break;
 
-  case 28:
-#line 186 "parse-gram.y"
+  case 27:
+#line 201 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
     break;
 
-  case 29:
-#line 190 "parse-gram.y"
+  case 28:
+#line 205 "parse-gram.y"
     { current_class = token_sym; }
     break;
 
-  case 30:
-#line 191 "parse-gram.y"
+  case 29:
+#line 206 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
     break;
 
-  case 31:
-#line 195 "parse-gram.y"
+  case 30:
+#line 210 "parse-gram.y"
     {current_type = yyvsp[0].string; }
     break;
 
-  case 32:
-#line 196 "parse-gram.y"
+  case 31:
+#line 211 "parse-gram.y"
     {
       current_type = NULL;
     }
     break;
 
-  case 33:
-#line 203 "parse-gram.y"
+  case 32:
+#line 218 "parse-gram.y"
     { current_assoc = yyvsp[-1].assoc; ++current_prec; }
     break;
 
-  case 34:
-#line 205 "parse-gram.y"
+  case 33:
+#line 220 "parse-gram.y"
     { current_assoc = non_assoc; current_type = NULL; }
     break;
 
-  case 35:
-#line 212 "parse-gram.y"
+  case 34:
+#line 227 "parse-gram.y"
     { yyval.assoc = left_assoc; }
     break;
 
-  case 36:
-#line 213 "parse-gram.y"
+  case 35:
+#line 228 "parse-gram.y"
     { yyval.assoc = right_assoc; }
     break;
 
-  case 37:
-#line 214 "parse-gram.y"
+  case 36:
+#line 229 "parse-gram.y"
     { yyval.assoc = non_assoc; }
     break;
 
-  case 38:
-#line 218 "parse-gram.y"
+  case 37:
+#line 233 "parse-gram.y"
     { current_type = NULL;}
     break;
 
-  case 39:
-#line 219 "parse-gram.y"
+  case 38:
+#line 234 "parse-gram.y"
     { current_type = yyvsp[0].string; }
     break;
 
-  case 40:
-#line 224 "parse-gram.y"
+  case 39:
+#line 239 "parse-gram.y"
     { symbol_type_set (yyvsp[0].symbol, current_type); }
     break;
 
-  case 41:
-#line 225 "parse-gram.y"
+  case 40:
+#line 240 "parse-gram.y"
     { symbol_type_set (yyvsp[0].symbol, current_type); }
     break;
 
-  case 42:
-#line 231 "parse-gram.y"
+  case 41:
+#line 246 "parse-gram.y"
     {
       symbol_type_set (yyvsp[0].symbol, current_type);
       symbol_precedence_set (yyvsp[0].symbol, current_prec, current_assoc);
     }
     break;
 
-  case 43:
-#line 236 "parse-gram.y"
+  case 42:
+#line 251 "parse-gram.y"
     {
       symbol_type_set (yyvsp[0].symbol, current_type);
       symbol_precedence_set (yyvsp[0].symbol, current_prec, current_assoc);
     }
     break;
 
-  case 44:
-#line 245 "parse-gram.y"
+  case 43:
+#line 260 "parse-gram.y"
     {
        current_type = yyvsp[0].string;
      }
     break;
 
-  case 45:
-#line 249 "parse-gram.y"
+  case 44:
+#line 264 "parse-gram.y"
     {
        symbol_class_set (yyvsp[0].symbol, current_class);
        symbol_type_set (yyvsp[0].symbol, current_type);
      }
     break;
 
-  case 46:
-#line 254 "parse-gram.y"
+  case 45:
+#line 269 "parse-gram.y"
     {
       symbol_class_set (yyvsp[-1].symbol, current_class);
       symbol_type_set (yyvsp[-1].symbol, current_type);
@@ -1399,8 +1408,8 @@ yyreduce:
     }
     break;
 
-  case 47:
-#line 260 "parse-gram.y"
+  case 46:
+#line 275 "parse-gram.y"
     {
       symbol_class_set (yyvsp[-1].symbol, current_class);
       symbol_type_set (yyvsp[-1].symbol, current_type);
@@ -1408,8 +1417,8 @@ yyreduce:
     }
     break;
 
-  case 48:
-#line 266 "parse-gram.y"
+  case 47:
+#line 281 "parse-gram.y"
     {
       symbol_class_set (yyvsp[-2].symbol, current_class);
       symbol_type_set (yyvsp[-2].symbol, current_type);
@@ -1418,101 +1427,101 @@ yyreduce:
     }
     break;
 
-  case 49:
-#line 277 "parse-gram.y"
+  case 48:
+#line 292 "parse-gram.y"
     {;}
     break;
 
-  case 50:
-#line 279 "parse-gram.y"
+  case 49:
+#line 294 "parse-gram.y"
     {;}
     break;
 
+  case 54:
+#line 316 "parse-gram.y"
+    { current_lhs = yyvsp[-1].symbol; current_lhs_location = yylsp[-1]; }
+    break;
+
   case 55:
-#line 301 "parse-gram.y"
-    { current_lhs = yyvsp[-1].symbol; }
+#line 317 "parse-gram.y"
+    {;}
     break;
 
   case 56:
-#line 302 "parse-gram.y"
-    {;}
+#line 321 "parse-gram.y"
+    { grammar_rule_end (yylsp[0]); }
     break;
 
   case 57:
-#line 306 "parse-gram.y"
-    { grammar_rule_end (); }
+#line 322 "parse-gram.y"
+    { grammar_rule_end (yylsp[0]); }
     break;
 
   case 58:
-#line 307 "parse-gram.y"
-    { grammar_rule_end (); }
+#line 327 "parse-gram.y"
+    { grammar_rule_begin (current_lhs, current_lhs_location); }
     break;
 
   case 59:
-#line 312 "parse-gram.y"
-    { grammar_rule_begin (current_lhs); }
+#line 329 "parse-gram.y"
+    { grammar_current_rule_symbol_append (yyvsp[0].symbol, yylsp[0]); }
     break;
 
   case 60:
-#line 314 "parse-gram.y"
-    { grammar_current_rule_symbol_append (yyvsp[0].symbol); }
+#line 331 "parse-gram.y"
+    { grammar_current_rule_action_append (yyvsp[0].string, yylsp[0]); }
     break;
 
   case 61:
-#line 316 "parse-gram.y"
-    { grammar_current_rule_action_append (yyvsp[0].string, yylsp[0].first_line); }
+#line 333 "parse-gram.y"
+    { grammar_current_rule_prec_set (yyvsp[0].symbol); }
     break;
 
   case 62:
-#line 318 "parse-gram.y"
-    { grammar_current_rule_prec_set (yyvsp[0].symbol); }
+#line 337 "parse-gram.y"
+    { yyval.symbol = yyvsp[0].symbol; }
     break;
 
   case 63:
-#line 322 "parse-gram.y"
+#line 338 "parse-gram.y"
     { yyval.symbol = yyvsp[0].symbol; }
     break;
 
   case 64:
-#line 323 "parse-gram.y"
-    { yyval.symbol = yyvsp[0].symbol; }
-    break;
-
-  case 65:
-#line 324 "parse-gram.y"
+#line 339 "parse-gram.y"
     { yyval.symbol = getsym (yyvsp[0].string); }
     break;
 
-  case 66:
-#line 329 "parse-gram.y"
+  case 65:
+#line 344 "parse-gram.y"
     { yyval.string = yyvsp[0].string; }
     break;
 
-  case 67:
-#line 335 "parse-gram.y"
+  case 66:
+#line 350 "parse-gram.y"
     {
       yyval.symbol = getsym (yyvsp[0].string);
       symbol_class_set (yyval.symbol, token_sym);
     }
     break;
 
-  case 68:
-#line 344 "parse-gram.y"
+  case 67:
+#line 359 "parse-gram.y"
     {
       yyval.string = yyvsp[0].string + 1;
       yyval.string[strlen (yyval.string) - 1] = '\0';
     }
     break;
 
-  case 69:
-#line 352 "parse-gram.y"
+  case 68:
+#line 367 "parse-gram.y"
     {
       yyval.string = xstrdup ("");
     }
     break;
 
-  case 70:
-#line 356 "parse-gram.y"
+  case 69:
+#line 371 "parse-gram.y"
     {
       yyval.string = yyvsp[0].string;
     }
@@ -1521,8 +1530,8 @@ yyreduce:
 
     }
 
-/* Line 1012 of /home/akim/src/bison/data/bison.simple.  */
-#line 1526 "parse-gram.c"
+/* Line 1012 of /usr/local/share/bison/bison.simple.  */
+#line 1535 "parse-gram.c"
 
   yyvsp -= yylen;
   yyssp -= yylen;
@@ -1743,7 +1752,7 @@ yyreturn:
   return yyresult;
 }
 
-#line 365 "parse-gram.y"
+#line 380 "parse-gram.y"
 
 /*------------------------------------------------------------------.
 | When debugging the parser, display tokens' locations and values.  |
