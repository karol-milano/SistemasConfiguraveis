@@ -88,24 +88,25 @@
      PERCENT_LOCATIONS = 280,
      PERCENT_NAME_PREFIX = 281,
      PERCENT_NO_LINES = 282,
-     PERCENT_OUTPUT = 283,
-     PERCENT_PARSE_PARAM = 284,
-     PERCENT_PURE_PARSER = 285,
-     PERCENT_SKELETON = 286,
-     PERCENT_START = 287,
-     PERCENT_TOKEN_TABLE = 288,
-     PERCENT_VERBOSE = 289,
-     PERCENT_YACC = 290,
-     TYPE = 291,
-     EQUAL = 292,
-     SEMICOLON = 293,
-     PIPE = 294,
-     ID = 295,
-     ID_COLON = 296,
-     PERCENT_PERCENT = 297,
-     PROLOGUE = 298,
-     EPILOGUE = 299,
-     BRACED_CODE = 300
+     PERCENT_NONDETERMINISTIC_PARSER = 283,
+     PERCENT_OUTPUT = 284,
+     PERCENT_PARSE_PARAM = 285,
+     PERCENT_PURE_PARSER = 286,
+     PERCENT_SKELETON = 287,
+     PERCENT_START = 288,
+     PERCENT_TOKEN_TABLE = 289,
+     PERCENT_VERBOSE = 290,
+     PERCENT_YACC = 291,
+     TYPE = 292,
+     EQUAL = 293,
+     SEMICOLON = 294,
+     PIPE = 295,
+     ID = 296,
+     ID_COLON = 297,
+     PERCENT_PERCENT = 298,
+     PROLOGUE = 299,
+     EPILOGUE = 300,
+     BRACED_CODE = 301
    };
 #endif
 #define GRAM_EOF 0
@@ -134,24 +135,25 @@
 #define PERCENT_LOCATIONS 280
 #define PERCENT_NAME_PREFIX 281
 #define PERCENT_NO_LINES 282
-#define PERCENT_OUTPUT 283
-#define PERCENT_PARSE_PARAM 284
-#define PERCENT_PURE_PARSER 285
-#define PERCENT_SKELETON 286
-#define PERCENT_START 287
-#define PERCENT_TOKEN_TABLE 288
-#define PERCENT_VERBOSE 289
-#define PERCENT_YACC 290
-#define TYPE 291
-#define EQUAL 292
-#define SEMICOLON 293
-#define PIPE 294
-#define ID 295
-#define ID_COLON 296
-#define PERCENT_PERCENT 297
-#define PROLOGUE 298
-#define EPILOGUE 299
-#define BRACED_CODE 300
+#define PERCENT_NONDETERMINISTIC_PARSER 283
+#define PERCENT_OUTPUT 284
+#define PERCENT_PARSE_PARAM 285
+#define PERCENT_PURE_PARSER 286
+#define PERCENT_SKELETON 287
+#define PERCENT_START 288
+#define PERCENT_TOKEN_TABLE 289
+#define PERCENT_VERBOSE 290
+#define PERCENT_YACC 291
+#define TYPE 292
+#define EQUAL 293
+#define SEMICOLON 294
+#define PIPE 295
+#define ID 296
+#define ID_COLON 297
+#define PERCENT_PERCENT 298
+#define PROLOGUE 299
+#define EPILOGUE 300
+#define BRACED_CODE 301
 
 
 
@@ -222,7 +224,7 @@ typedef union YYSTYPE {
   uniqstr uniqstr;
 } YYSTYPE;
 /* Line 191 of yacc.c.  */
-#line 226 "parse-gram.c"
+#line 228 "parse-gram.c"
 # define yystype YYSTYPE /* obsolescent; will be withdrawn */
 # define YYSTYPE_IS_DECLARED 1
 # define YYSTYPE_IS_TRIVIAL 1
@@ -246,7 +248,7 @@ typedef struct YYLTYPE
 
 
 /* Line 214 of yacc.c.  */
-#line 250 "parse-gram.c"
+#line 252 "parse-gram.c"
 
 #if ! defined (yyoverflow) || YYERROR_VERBOSE
 
@@ -346,20 +348,20 @@ union yyalloc
 /* YYFINAL -- State number of the termination state. */
 #define YYFINAL  3
 /* YYLAST -- Last index in YYTABLE.  */
-#define YYLAST   157
+#define YYLAST   147
 
 /* YYNTOKENS -- Number of terminals. */
-#define YYNTOKENS  46
+#define YYNTOKENS  47
 /* YYNNTS -- Number of nonterminals. */
 #define YYNNTS  25
 /* YYNRULES -- Number of rules. */
-#define YYNRULES  74
+#define YYNRULES  75
 /* YYNRULES -- Number of states. */
-#define YYNSTATES  101
+#define YYNSTATES  102
 
 /* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
 #define YYUNDEFTOK  2
-#define YYMAXUTOK   300
+#define YYMAXUTOK   301
 
 #define YYTRANSLATE(YYX) 						\
   ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)
@@ -397,7 +399,7 @@ static const unsigned char yytranslate[] =
       15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
       25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
       35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
-      45
+      45,    46
 };
 
 #if YYDEBUG
@@ -406,50 +408,50 @@ static const unsigned char yytranslate[] =
 static const unsigned char yyprhs[] =
 {
        0,     0,     3,     8,     9,    12,    14,    16,    18,    22,
-      24,    26,    29,    33,    35,    37,    39,    43,    45,    49,
-      51,    53,    56,    58,    60,    62,    64,    66,    68,    71,
-      73,    76,    79,    80,    84,    85,    89,    93,    97,    99,
-     101,   103,   104,   106,   108,   111,   113,   115,   118,   121,
-     125,   127,   130,   132,   135,   137,   139,   142,   144,   145,
-     149,   151,   155,   156,   159,   162,   166,   170,   174,   176,
-     178,   180,   182,   184,   185
+      24,    26,    29,    33,    35,    37,    39,    43,    45,    47,
+      51,    53,    55,    58,    60,    62,    64,    66,    68,    70,
+      73,    75,    78,    81,    82,    86,    87,    91,    95,    99,
+     101,   103,   105,   106,   108,   110,   113,   115,   117,   120,
+     123,   127,   129,   132,   134,   137,   139,   141,   144,   146,
+     147,   151,   153,   157,   158,   161,   164,   168,   172,   176,
+     178,   180,   182,   184,   186,   187
 };
 
 /* YYRHS -- A `-1'-separated list of the rules' RHS. */
 static const yysigned_char yyrhs[] =
 {
-      47,     0,    -1,    48,    42,    60,    70,    -1,    -1,    48,
-      49,    -1,    50,    -1,    43,    -1,    17,    -1,    18,    69,
-      69,    -1,    19,    -1,    20,    -1,    21,     4,    -1,    22,
-      37,    69,    -1,    23,    -1,    24,    -1,    25,    -1,    26,
-      37,    69,    -1,    27,    -1,    28,    37,    69,    -1,    29,
-      -1,    30,    -1,    31,    69,    -1,    33,    -1,    34,    -1,
-      35,    -1,    38,    -1,    54,    -1,    51,    -1,    32,    66,
-      -1,    10,    -1,     8,    57,    -1,     9,    57,    -1,    -1,
-       6,    52,    59,    -1,    -1,     5,    53,    59,    -1,     7,
-      36,    57,    -1,    55,    56,    57,    -1,    11,    -1,    12,
-      -1,    13,    -1,    -1,    36,    -1,    66,    -1,    57,    66,
-      -1,    36,    -1,    40,    -1,    40,     4,    -1,    40,    68,
-      -1,    40,     4,    68,    -1,    58,    -1,    59,    58,    -1,
-      61,    -1,    60,    61,    -1,    62,    -1,    50,    -1,     1,
-      38,    -1,    38,    -1,    -1,    41,    63,    64,    -1,    65,
-      -1,    64,    39,    65,    -1,    -1,    65,    66,    -1,    65,
-      67,    -1,    65,    14,    66,    -1,    65,    15,     4,    -1,
-      65,    16,    36,    -1,    40,    -1,    68,    -1,    45,    -1,
-       3,    -1,     3,    -1,    -1,    42,    44,    -1
+      48,     0,    -1,    49,    43,    61,    71,    -1,    -1,    49,
+      50,    -1,    51,    -1,    44,    -1,    17,    -1,    18,    70,
+      70,    -1,    19,    -1,    20,    -1,    21,     4,    -1,    22,
+      38,    70,    -1,    23,    -1,    24,    -1,    25,    -1,    26,
+      38,    70,    -1,    27,    -1,    28,    -1,    29,    38,    70,
+      -1,    30,    -1,    31,    -1,    32,    70,    -1,    34,    -1,
+      35,    -1,    36,    -1,    39,    -1,    55,    -1,    52,    -1,
+      33,    67,    -1,    10,    -1,     8,    58,    -1,     9,    58,
+      -1,    -1,     6,    53,    60,    -1,    -1,     5,    54,    60,
+      -1,     7,    37,    58,    -1,    56,    57,    58,    -1,    11,
+      -1,    12,    -1,    13,    -1,    -1,    37,    -1,    67,    -1,
+      58,    67,    -1,    37,    -1,    41,    -1,    41,     4,    -1,
+      41,    69,    -1,    41,     4,    69,    -1,    59,    -1,    60,
+      59,    -1,    62,    -1,    61,    62,    -1,    63,    -1,    51,
+      -1,     1,    39,    -1,    39,    -1,    -1,    42,    64,    65,
+      -1,    66,    -1,    65,    40,    66,    -1,    -1,    66,    67,
+      -1,    66,    68,    -1,    66,    14,    67,    -1,    66,    15,
+       4,    -1,    66,    16,    37,    -1,    41,    -1,    69,    -1,
+      46,    -1,     3,    -1,     3,    -1,    -1,    43,    45,    -1
 };
 
 /* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
 static const unsigned short yyrline[] =
 {
-       0,   161,   161,   169,   171,   175,   176,   177,   178,   179,
-     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
-     190,   191,   192,   193,   194,   195,   199,   200,   201,   205,
-     211,   218,   228,   228,   233,   233,   238,   248,   263,   264,
-     265,   269,   270,   276,   277,   282,   286,   291,   297,   303,
-     314,   315,   324,   325,   331,   332,   337,   341,   345,   345,
-     349,   350,   355,   356,   358,   360,   362,   364,   369,   370,
-     374,   380,   389,   396,   398
+       0,   162,   162,   170,   172,   176,   177,   178,   179,   180,
+     181,   182,   183,   184,   186,   187,   188,   189,   190,   191,
+     192,   193,   194,   195,   196,   197,   198,   202,   203,   204,
+     208,   214,   221,   231,   231,   236,   236,   241,   251,   266,
+     267,   268,   272,   273,   279,   280,   285,   289,   294,   300,
+     306,   317,   318,   327,   328,   334,   335,   340,   344,   348,
+     348,   352,   353,   358,   359,   361,   363,   365,   367,   372,
+     373,   377,   383,   392,   399,   401
 };
 #endif
 
@@ -464,13 +466,13 @@ static const char *const yytname[] =
   "\"%nonassoc\"", "\"%prec\"", "\"%dprec\"", "\"%merge\"", "\"%debug\"", 
   "\"%define\"", "\"%defines\"", "\"%error-verbose\"", "\"%expect\"", 
   "\"%file-prefix\"", "\"%glr-parser\"", "\"%lex-param {...}\"", 
-  "\"%locations\"", "\"%name-prefix\"", "\"%no-lines\"", "\"%output\"", 
-  "\"%parse-param {...}\"", "\"%pure-parser\"", "\"%skeleton\"", 
-  "\"%start\"", "\"%token-table\"", "\"%verbose\"", "\"%yacc\"", 
-  "\"type\"", "\"=\"", "\";\"", "\"|\"", "\"identifier\"", 
-  "\"identifier:\"", "\"%%\"", "\"%{...%}\"", "\"epilogue\"", "\"{...}\"", 
-  "$accept", "input", "declarations", "declaration", 
-  "grammar_declaration", "symbol_declaration", "@1", "@2", 
+  "\"%locations\"", "\"%name-prefix\"", "\"%no-lines\"", 
+  "\"%nondeterministic-parser\"", "\"%output\"", "\"%parse-param {...}\"", 
+  "\"%pure-parser\"", "\"%skeleton\"", "\"%start\"", "\"%token-table\"", 
+  "\"%verbose\"", "\"%yacc\"", "\"type\"", "\"=\"", "\";\"", "\"|\"", 
+  "\"identifier\"", "\"identifier:\"", "\"%%\"", "\"%{...%}\"", 
+  "\"epilogue\"", "\"{...}\"", "$accept", "input", "declarations", 
+  "declaration", "grammar_declaration", "symbol_declaration", "@1", "@2", 
   "precedence_declaration", "precedence_declarator", "type.opt", 
   "symbols.1", "symbol_def", "symbol_defs.1", "grammar", 
   "rules_or_grammar_declaration", "rules", "@3", "rhses.1", "rhs", 
@@ -487,34 +489,34 @@ static const unsigned short yytoknum[] =
      265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
      275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
      285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
-     295,   296,   297,   298,   299,   300
+     295,   296,   297,   298,   299,   300,   301
 };
 # endif
 
 /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
 static const unsigned char yyr1[] =
 {
-       0,    46,    47,    48,    48,    49,    49,    49,    49,    49,
-      49,    49,    49,    49,    49,    49,    49,    49,    49,    49,
-      49,    49,    49,    49,    49,    49,    50,    50,    50,    50,
-      50,    50,    52,    51,    53,    51,    51,    54,    55,    55,
-      55,    56,    56,    57,    57,    58,    58,    58,    58,    58,
-      59,    59,    60,    60,    61,    61,    61,    61,    63,    62,
-      64,    64,    65,    65,    65,    65,    65,    65,    66,    66,
-      67,    68,    69,    70,    70
+       0,    47,    48,    49,    49,    50,    50,    50,    50,    50,
+      50,    50,    50,    50,    50,    50,    50,    50,    50,    50,
+      50,    50,    50,    50,    50,    50,    50,    51,    51,    51,
+      51,    51,    51,    53,    52,    54,    52,    52,    55,    56,
+      56,    56,    57,    57,    58,    58,    59,    59,    59,    59,
+      59,    60,    60,    61,    61,    62,    62,    62,    62,    64,
+      63,    65,    65,    66,    66,    66,    66,    66,    66,    67,
+      67,    68,    69,    70,    71,    71
 };
 
 /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
 static const unsigned char yyr2[] =
 {
        0,     2,     4,     0,     2,     1,     1,     1,     3,     1,
-       1,     2,     3,     1,     1,     1,     3,     1,     3,     1,
-       1,     2,     1,     1,     1,     1,     1,     1,     2,     1,
-       2,     2,     0,     3,     0,     3,     3,     3,     1,     1,
-       1,     0,     1,     1,     2,     1,     1,     2,     2,     3,
-       1,     2,     1,     2,     1,     1,     2,     1,     0,     3,
-       1,     3,     0,     2,     2,     3,     3,     3,     1,     1,
-       1,     1,     1,     0,     2
+       1,     2,     3,     1,     1,     1,     3,     1,     1,     3,
+       1,     1,     2,     1,     1,     1,     1,     1,     1,     2,
+       1,     2,     2,     0,     3,     0,     3,     3,     3,     1,
+       1,     1,     0,     1,     1,     2,     1,     1,     2,     2,
+       3,     1,     2,     1,     2,     1,     1,     2,     1,     0,
+       3,     1,     3,     0,     2,     2,     3,     3,     3,     1,
+       1,     1,     1,     1,     0,     2
 };
 
 /* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
@@ -522,25 +524,25 @@ static const unsigned char yyr2[] =
    means the default is an error.  */
 static const unsigned char yydefact[] =
 {
-       3,     0,     0,     1,    34,    32,     0,     0,     0,    29,
-      38,    39,    40,     7,     0,     9,    10,     0,     0,    13,
-      14,    15,     0,    17,     0,    19,    20,     0,     0,    22,
-      23,    24,    25,     0,     6,     4,     5,    27,    26,    41,
-       0,     0,     0,    71,    68,    30,    43,    69,    31,    72,
-       0,    11,     0,     0,     0,    21,    28,     0,    57,    58,
-      55,     0,    52,    54,    42,     0,    45,    46,    50,    35,
-      33,    36,    44,     8,    12,    16,    18,    56,    62,     0,
-      53,     2,    37,    47,    48,    51,    59,    60,    74,    49,
-      62,     0,     0,     0,    70,    63,    64,    61,    65,    66,
-      67
+       3,     0,     0,     1,    35,    33,     0,     0,     0,    30,
+      39,    40,    41,     7,     0,     9,    10,     0,     0,    13,
+      14,    15,     0,    17,    18,     0,    20,    21,     0,     0,
+      23,    24,    25,    26,     0,     6,     4,     5,    28,    27,
+      42,     0,     0,     0,    72,    69,    31,    44,    70,    32,
+      73,     0,    11,     0,     0,     0,    22,    29,     0,    58,
+      59,    56,     0,    53,    55,    43,     0,    46,    47,    51,
+      36,    34,    37,    45,     8,    12,    16,    19,    57,    63,
+       0,    54,     2,    38,    48,    49,    52,    60,    61,    75,
+      50,    63,     0,     0,     0,    71,    64,    65,    62,    66,
+      67,    68
 };
 
 /* YYDEFGOTO[NTERM-NUM]. */
 static const yysigned_char yydefgoto[] =
 {
-      -1,     1,     2,    35,    60,    37,    41,    40,    38,    39,
-      65,    45,    68,    69,    61,    62,    63,    78,    86,    87,
-      46,    96,    47,    50,    81
+      -1,     1,     2,    36,    61,    38,    42,    41,    39,    40,
+      66,    46,    69,    70,    62,    63,    64,    79,    87,    88,
+      47,    97,    48,    51,    82
 };
 
 /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
@@ -548,87 +550,85 @@ static const yysigned_char yydefgoto[] =
 #define YYPACT_NINF -65
 static const yysigned_char yypact[] =
 {
-     -65,     5,   114,   -65,   -65,   -65,   -24,     1,     1,   -65,
-     -65,   -65,   -65,   -65,    10,   -65,   -65,    11,   -23,   -65,
-     -65,   -65,   -21,   -65,   -15,   -65,   -65,    10,     1,   -65,
-     -65,   -65,   -65,    77,   -65,   -65,   -65,   -65,   -65,   -13,
-     -34,   -34,     1,   -65,   -65,     1,   -65,   -65,     1,   -65,
-      10,   -65,    10,    10,    10,   -65,   -65,   -17,   -65,   -65,
-     -65,    39,   -65,   -65,   -65,     1,   -65,     4,   -65,   -34,
-     -34,     1,   -65,   -65,   -65,   -65,   -65,   -65,   -65,   -20,
-     -65,   -65,     1,    22,   -65,   -65,   -12,    15,   -65,   -65,
-     -65,     1,    24,   -10,   -65,   -65,   -65,    15,   -65,   -65,
-     -65
+     -65,    27,   103,   -65,   -65,   -65,   -15,    -2,    -2,   -65,
+     -65,   -65,   -65,   -65,    25,   -65,   -65,    28,    -5,   -65,
+     -65,   -65,    -3,   -65,   -65,     0,   -65,   -65,    25,    -2,
+     -65,   -65,   -65,   -65,    65,   -65,   -65,   -65,   -65,   -65,
+       4,   -18,   -18,    -2,   -65,   -65,    -2,   -65,   -65,    -2,
+     -65,    25,   -65,    25,    25,    25,   -65,   -65,     1,   -65,
+     -65,   -65,     3,   -65,   -65,   -65,    -2,   -65,    22,   -65,
+     -18,   -18,    -2,   -65,   -65,   -65,   -65,   -65,   -65,   -65,
+     -11,   -65,   -65,    -2,    41,   -65,   -65,     8,    15,   -65,
+     -65,   -65,    -2,    48,    16,   -65,   -65,   -65,    15,   -65,
+     -65,   -65
 };
 
 /* YYPGOTO[NTERM-NUM].  */
 static const yysigned_char yypgoto[] =
 {
-     -65,   -65,   -65,   -65,    30,   -65,   -65,   -65,   -65,   -65,
-     -65,    -7,   -60,    -8,   -65,   -19,   -65,   -65,   -65,   -37,
-     -28,   -65,   -64,   -16,   -65
+     -65,   -65,   -65,   -65,    53,   -65,   -65,   -65,   -65,   -65,
+     -65,    -6,   -64,    20,   -65,     2,   -65,   -65,   -65,   -34,
+     -29,   -65,   -63,    -4,   -65
 };
 
 /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
    positive, shift that token.  If negative, reduce the rule which
    number is the opposite.  If zero, do what YYDEFACT says.
    If YYTABLE_NINF, syntax error.  */
-#define YYTABLE_NINF -74
+#define YYTABLE_NINF -75
 static const yysigned_char yytable[] =
 {
-      56,    48,    66,    84,    43,     3,    67,    43,    83,    85,
-      85,    55,    42,    49,    52,    51,    53,    72,    43,    89,
-      72,    77,    54,    64,    88,    43,   100,    90,    99,    91,
-      92,    93,    36,    70,    73,    71,    74,    75,    76,   -73,
-      57,    44,    80,    72,     4,     5,     6,     7,     8,     9,
-      10,    11,    12,    97,    72,    44,     0,     0,    82,    95,
-      94,     0,     0,    98,     0,     0,     0,     0,     0,    95,
-       0,    28,     0,     0,     0,     0,     0,    58,    57,     0,
-      59,    79,     4,     5,     6,     7,     8,     9,    10,    11,
-      12,     0,     0,     0,     0,     0,     0,     0,     0,     0,
-       0,     0,     0,     0,     0,     0,     0,     0,     0,    28,
-       0,     0,     0,     0,     0,    58,     0,     0,    59,     4,
-       5,     6,     7,     8,     9,    10,    11,    12,     0,     0,
-       0,    13,    14,    15,    16,    17,    18,    19,    20,    21,
-      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
-       0,     0,    32,     0,     0,     0,    33,    34
+      57,    44,    49,   -74,    58,    85,    86,    86,     4,     5,
+       6,     7,     8,     9,    10,    11,    12,    73,    44,    67,
+      73,    90,    43,    68,    56,    44,    84,     3,    50,    92,
+      93,    94,    52,    53,    89,    54,    29,    72,    55,    45,
+      78,    65,    59,    73,    44,    60,    80,    74,    91,    75,
+      76,    77,   100,   101,    73,    37,    45,    98,     0,    96,
+      83,    95,    71,    99,    81,     0,    58,     0,     0,    96,
+       4,     5,     6,     7,     8,     9,    10,    11,    12,     0,
+       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
+       0,     0,     0,     0,     0,     0,     0,     0,    29,     0,
+       0,     0,     0,     0,    59,     0,     0,    60,     4,     5,
+       6,     7,     8,     9,    10,    11,    12,     0,     0,     0,
+      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
+      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
+       0,     0,    33,     0,     0,     0,    34,    35
 };
 
 static const yysigned_char yycheck[] =
 {
-      28,     8,    36,    67,     3,     0,    40,     3,     4,    69,
-      70,    27,    36,     3,    37,     4,    37,    45,     3,    83,
-      48,    38,    37,    36,    44,     3,    36,    39,     4,    14,
-      15,    16,     2,    41,    50,    42,    52,    53,    54,     0,
-       1,    40,    61,    71,     5,     6,     7,     8,     9,    10,
-      11,    12,    13,    90,    82,    40,    -1,    -1,    65,    87,
-      45,    -1,    -1,    91,    -1,    -1,    -1,    -1,    -1,    97,
-      -1,    32,    -1,    -1,    -1,    -1,    -1,    38,     1,    -1,
-      41,    42,     5,     6,     7,     8,     9,    10,    11,    12,
-      13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
-      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,
-      -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,    41,     5,
-       6,     7,     8,     9,    10,    11,    12,    13,    -1,    -1,
-      -1,    17,    18,    19,    20,    21,    22,    23,    24,    25,
-      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
-      -1,    -1,    38,    -1,    -1,    -1,    42,    43
+      29,     3,     8,     0,     1,    68,    70,    71,     5,     6,
+       7,     8,     9,    10,    11,    12,    13,    46,     3,    37,
+      49,    84,    37,    41,    28,     3,     4,     0,     3,    14,
+      15,    16,     4,    38,    45,    38,    33,    43,    38,    41,
+      39,    37,    39,    72,     3,    42,    43,    51,    40,    53,
+      54,    55,     4,    37,    83,     2,    41,    91,    -1,    88,
+      66,    46,    42,    92,    62,    -1,     1,    -1,    -1,    98,
+       5,     6,     7,     8,     9,    10,    11,    12,    13,    -1,
+      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
+      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,    -1,
+      -1,    -1,    -1,    -1,    39,    -1,    -1,    42,     5,     6,
+       7,     8,     9,    10,    11,    12,    13,    -1,    -1,    -1,
+      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
+      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
+      -1,    -1,    39,    -1,    -1,    -1,    43,    44
 };
 
 /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
    symbol of state STATE-NUM.  */
 static const unsigned char yystos[] =
 {
-       0,    47,    48,     0,     5,     6,     7,     8,     9,    10,
+       0,    48,    49,     0,     5,     6,     7,     8,     9,    10,
       11,    12,    13,    17,    18,    19,    20,    21,    22,    23,
       24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
-      34,    35,    38,    42,    43,    49,    50,    51,    54,    55,
-      53,    52,    36,     3,    40,    57,    66,    68,    57,     3,
-      69,     4,    37,    37,    37,    69,    66,     1,    38,    41,
-      50,    60,    61,    62,    36,    56,    36,    40,    58,    59,
-      59,    57,    66,    69,    69,    69,    69,    38,    63,    42,
-      61,    70,    57,     4,    68,    58,    64,    65,    44,    68,
-      39,    14,    15,    16,    45,    66,    67,    65,    66,     4,
-      36
+      34,    35,    36,    39,    43,    44,    50,    51,    52,    55,
+      56,    54,    53,    37,     3,    41,    58,    67,    69,    58,
+       3,    70,     4,    38,    38,    38,    70,    67,     1,    39,
+      42,    51,    61,    62,    63,    37,    57,    37,    41,    59,
+      60,    60,    58,    67,    70,    70,    70,    70,    39,    64,
+      43,    62,    71,    58,     4,    69,    59,    65,    66,    45,
+      69,    40,    14,    15,    16,    46,    67,    68,    66,    67,
+       4,    37
 };
 
 #if ! defined (YYSIZE_T) && defined (__SIZE_TYPE__)
@@ -1256,109 +1256,115 @@ yyreduce:
   switch (yyn)
     {
         case 6:
-#line 176 "parse-gram.y"
+#line 177 "parse-gram.y"
     { prologue_augment (yyvsp[0].chars, yylsp[0]); }
     break;
 
   case 7:
-#line 177 "parse-gram.y"
+#line 178 "parse-gram.y"
     { debug_flag = 1; }
     break;
 
   case 8:
-#line 178 "parse-gram.y"
+#line 179 "parse-gram.y"
     { muscle_insert (yyvsp[-1].chars, yyvsp[0].chars); }
     break;
 
   case 9:
-#line 179 "parse-gram.y"
+#line 180 "parse-gram.y"
     { defines_flag = 1; }
     break;
 
   case 10:
-#line 180 "parse-gram.y"
+#line 181 "parse-gram.y"
     { error_verbose = 1; }
     break;
 
   case 11:
-#line 181 "parse-gram.y"
+#line 182 "parse-gram.y"
     { expected_conflicts = yyvsp[0].integer; }
     break;
 
   case 12:
-#line 182 "parse-gram.y"
+#line 183 "parse-gram.y"
     { spec_file_prefix = yyvsp[0].chars; }
     break;
 
   case 13:
-#line 183 "parse-gram.y"
-    { glr_parser = 1; }
+#line 184 "parse-gram.y"
+    { nondeterministic_parser = true;
+                                             glr_parser = true; }
     break;
 
   case 14:
-#line 184 "parse-gram.y"
+#line 186 "parse-gram.y"
     { add_param ("lex_param", yyvsp[0].chars, yylsp[0]); }
     break;
 
   case 15:
-#line 185 "parse-gram.y"
+#line 187 "parse-gram.y"
     { locations_flag = 1; }
     break;
 
   case 16:
-#line 186 "parse-gram.y"
+#line 188 "parse-gram.y"
     { spec_name_prefix = yyvsp[0].chars; }
     break;
 
   case 17:
-#line 187 "parse-gram.y"
+#line 189 "parse-gram.y"
     { no_lines_flag = 1; }
     break;
 
   case 18:
-#line 188 "parse-gram.y"
-    { spec_outfile = yyvsp[0].chars; }
+#line 190 "parse-gram.y"
+    { nondeterministic_parser = true; }
     break;
 
   case 19:
-#line 189 "parse-gram.y"
-    { add_param ("parse_param", yyvsp[0].chars, yylsp[0]); }
+#line 191 "parse-gram.y"
+    { spec_outfile = yyvsp[0].chars; }
     break;
 
   case 20:
-#line 190 "parse-gram.y"
-    { pure_parser = 1; }
+#line 192 "parse-gram.y"
+    { add_param ("parse_param", yyvsp[0].chars, yylsp[0]); }
     break;
 
   case 21:
-#line 191 "parse-gram.y"
-    { skeleton = yyvsp[0].chars; }
+#line 193 "parse-gram.y"
+    { pure_parser = true; }
     break;
 
   case 22:
-#line 192 "parse-gram.y"
-    { token_table_flag = 1; }
+#line 194 "parse-gram.y"
+    { skeleton = yyvsp[0].chars; }
     break;
 
   case 23:
-#line 193 "parse-gram.y"
-    { report_flag = report_states; }
+#line 195 "parse-gram.y"
+    { token_table_flag = 1; }
     break;
 
   case 24:
-#line 194 "parse-gram.y"
+#line 196 "parse-gram.y"
+    { report_flag = report_states; }
+    break;
+
+  case 25:
+#line 197 "parse-gram.y"
     { yacc_flag = 1; }
     break;
 
-  case 28:
-#line 202 "parse-gram.y"
+  case 29:
+#line 205 "parse-gram.y"
     {
       grammar_start_symbol_set (yyvsp[0].symbol, yylsp[0]);
     }
     break;
 
-  case 29:
-#line 206 "parse-gram.y"
+  case 30:
+#line 209 "parse-gram.y"
     {
       typed = 1;
       MUSCLE_INSERT_INT ("stype_line", yylsp[0].start.line);
@@ -1366,8 +1372,8 @@ yyreduce:
     }
     break;
 
-  case 30:
-#line 212 "parse-gram.y"
+  case 31:
+#line 215 "parse-gram.y"
     {
       symbol_list *list;
       for (list = yyvsp[0].list; list; list = list->next)
@@ -1376,8 +1382,8 @@ yyreduce:
     }
     break;
 
-  case 31:
-#line 219 "parse-gram.y"
+  case 32:
+#line 222 "parse-gram.y"
     {
       symbol_list *list;
       for (list = yyvsp[0].list; list; list = list->next)
@@ -1386,34 +1392,34 @@ yyreduce:
     }
     break;
 
-  case 32:
-#line 228 "parse-gram.y"
+  case 33:
+#line 231 "parse-gram.y"
     { current_class = nterm_sym; }
     break;
 
-  case 33:
-#line 229 "parse-gram.y"
+  case 34:
+#line 232 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
     break;
 
-  case 34:
-#line 233 "parse-gram.y"
+  case 35:
+#line 236 "parse-gram.y"
     { current_class = token_sym; }
     break;
 
-  case 35:
-#line 234 "parse-gram.y"
+  case 36:
+#line 237 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
     break;
 
-  case 36:
-#line 239 "parse-gram.y"
+  case 37:
+#line 242 "parse-gram.y"
     {
       symbol_list *list;
       for (list = yyvsp[0].list; list; list = list->next)
@@ -1422,8 +1428,8 @@ yyreduce:
     }
     break;
 
-  case 37:
-#line 249 "parse-gram.y"
+  case 38:
+#line 252 "parse-gram.y"
     {
       symbol_list *list;
       ++current_prec;
@@ -1437,58 +1443,58 @@ yyreduce:
     }
     break;
 
-  case 38:
-#line 263 "parse-gram.y"
+  case 39:
+#line 266 "parse-gram.y"
     { yyval.assoc = left_assoc; }
     break;
 
-  case 39:
-#line 264 "parse-gram.y"
+  case 40:
+#line 267 "parse-gram.y"
     { yyval.assoc = right_assoc; }
     break;
 
-  case 40:
-#line 265 "parse-gram.y"
+  case 41:
+#line 268 "parse-gram.y"
     { yyval.assoc = non_assoc; }
     break;
 
-  case 41:
-#line 269 "parse-gram.y"
+  case 42:
+#line 272 "parse-gram.y"
     { current_type = NULL; }
     break;
 
-  case 42:
-#line 270 "parse-gram.y"
+  case 43:
+#line 273 "parse-gram.y"
     { current_type = yyvsp[0].uniqstr; }
     break;
 
-  case 43:
-#line 276 "parse-gram.y"
+  case 44:
+#line 279 "parse-gram.y"
     { yyval.list = symbol_list_new (yyvsp[0].symbol, yylsp[0]); }
     break;
 
-  case 44:
-#line 277 "parse-gram.y"
+  case 45:
+#line 280 "parse-gram.y"
     { yyval.list = symbol_list_prepend (yyvsp[-1].list, yyvsp[0].symbol, yylsp[0]); }
     break;
 
-  case 45:
-#line 283 "parse-gram.y"
+  case 46:
+#line 286 "parse-gram.y"
     {
        current_type = yyvsp[0].uniqstr;
      }
     break;
 
-  case 46:
-#line 287 "parse-gram.y"
+  case 47:
+#line 290 "parse-gram.y"
     {
        symbol_class_set (yyvsp[0].symbol, current_class, yylsp[0]);
        symbol_type_set (yyvsp[0].symbol, current_type, yylsp[0]);
      }
     break;
 
-  case 47:
-#line 292 "parse-gram.y"
+  case 48:
+#line 295 "parse-gram.y"
     {
       symbol_class_set (yyvsp[-1].symbol, current_class, yylsp[-1]);
       symbol_type_set (yyvsp[-1].symbol, current_type, yylsp[-1]);
@@ -1496,8 +1502,8 @@ yyreduce:
     }
     break;
 
-  case 48:
-#line 298 "parse-gram.y"
+  case 49:
+#line 301 "parse-gram.y"
     {
       symbol_class_set (yyvsp[-1].symbol, current_class, yylsp[-1]);
       symbol_type_set (yyvsp[-1].symbol, current_type, yylsp[-1]);
@@ -1505,8 +1511,8 @@ yyreduce:
     }
     break;
 
-  case 49:
-#line 304 "parse-gram.y"
+  case 50:
+#line 307 "parse-gram.y"
     {
       symbol_class_set (yyvsp[-2].symbol, current_class, yylsp[-2]);
       symbol_type_set (yyvsp[-2].symbol, current_type, yylsp[-2]);
@@ -1515,99 +1521,99 @@ yyreduce:
     }
     break;
 
-  case 55:
-#line 333 "parse-gram.y"
+  case 56:
+#line 336 "parse-gram.y"
     {
       if (yacc_flag)
 	complain_at (yyloc, _("POSIX forbids declarations in the grammar"));
     }
     break;
 
-  case 56:
-#line 338 "parse-gram.y"
+  case 57:
+#line 341 "parse-gram.y"
     {
       yyerrok;
     }
     break;
 
-  case 58:
-#line 345 "parse-gram.y"
+  case 59:
+#line 348 "parse-gram.y"
     { current_lhs = yyvsp[0].symbol; current_lhs_location = yylsp[0]; }
     break;
 
-  case 60:
-#line 349 "parse-gram.y"
-    { grammar_rule_end (yylsp[0]); }
-    break;
-
   case 61:
-#line 350 "parse-gram.y"
+#line 352 "parse-gram.y"
     { grammar_rule_end (yylsp[0]); }
     break;
 
   case 62:
-#line 355 "parse-gram.y"
-    { grammar_rule_begin (current_lhs, current_lhs_location); }
+#line 353 "parse-gram.y"
+    { grammar_rule_end (yylsp[0]); }
     break;
 
   case 63:
-#line 357 "parse-gram.y"
-    { grammar_current_rule_symbol_append (yyvsp[0].symbol, yylsp[0]); }
+#line 358 "parse-gram.y"
+    { grammar_rule_begin (current_lhs, current_lhs_location); }
     break;
 
   case 64:
-#line 359 "parse-gram.y"
-    { grammar_current_rule_action_append (yyvsp[0].chars, yylsp[0]); }
+#line 360 "parse-gram.y"
+    { grammar_current_rule_symbol_append (yyvsp[0].symbol, yylsp[0]); }
     break;
 
   case 65:
-#line 361 "parse-gram.y"
-    { grammar_current_rule_prec_set (yyvsp[0].symbol, yylsp[0]); }
+#line 362 "parse-gram.y"
+    { grammar_current_rule_action_append (yyvsp[0].chars, yylsp[0]); }
     break;
 
   case 66:
-#line 363 "parse-gram.y"
-    { grammar_current_rule_dprec_set (yyvsp[0].integer, yylsp[0]); }
+#line 364 "parse-gram.y"
+    { grammar_current_rule_prec_set (yyvsp[0].symbol, yylsp[0]); }
     break;
 
   case 67:
-#line 365 "parse-gram.y"
-    { grammar_current_rule_merge_set (yyvsp[0].uniqstr, yylsp[0]); }
+#line 366 "parse-gram.y"
+    { grammar_current_rule_dprec_set (yyvsp[0].integer, yylsp[0]); }
     break;
 
   case 68:
-#line 369 "parse-gram.y"
-    { yyval.symbol = yyvsp[0].symbol; }
+#line 368 "parse-gram.y"
+    { grammar_current_rule_merge_set (yyvsp[0].uniqstr, yylsp[0]); }
     break;
 
   case 69:
-#line 370 "parse-gram.y"
+#line 372 "parse-gram.y"
     { yyval.symbol = yyvsp[0].symbol; }
     break;
 
   case 70:
-#line 375 "parse-gram.y"
-    { yyval.chars = yyvsp[0].chars; }
+#line 373 "parse-gram.y"
+    { yyval.symbol = yyvsp[0].symbol; }
     break;
 
   case 71:
-#line 381 "parse-gram.y"
+#line 378 "parse-gram.y"
+    { yyval.chars = yyvsp[0].chars; }
+    break;
+
+  case 72:
+#line 384 "parse-gram.y"
     {
       yyval.symbol = symbol_get (yyvsp[0].chars, yylsp[0]);
       symbol_class_set (yyval.symbol, token_sym, yylsp[0]);
     }
     break;
 
-  case 72:
-#line 390 "parse-gram.y"
+  case 73:
+#line 393 "parse-gram.y"
     {
       yyval.chars = yyvsp[0].chars + 1;
       yyval.chars[strlen (yyval.chars) - 1] = '\0';
     }
     break;
 
-  case 74:
-#line 399 "parse-gram.y"
+  case 75:
+#line 402 "parse-gram.y"
     {
       epilogue_augment (yyvsp[0].chars, yylsp[0]);
       scanner_last_string_free ();
@@ -1618,7 +1624,7 @@ yyreduce:
     }
 
 /* Line 999 of yacc.c.  */
-#line 1622 "parse-gram.c"
+#line 1628 "parse-gram.c"
 
   yyvsp -= yylen;
   yyssp -= yylen;
@@ -1825,7 +1831,7 @@ yyreturn:
 }
 
 
-#line 405 "parse-gram.y"
+#line 408 "parse-gram.y"
 
 
 
