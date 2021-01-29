@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 1.75d.  */
+/* A Bison parser, made by GNU Bison 1.75e.  */
 
 /* Skeleton parser for Yacc-like parsing with Bison,
    Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002 Free Software Foundation, Inc.
@@ -188,7 +188,7 @@ static void gram_error (location const *, char const *);
 	print_token_value (File, Type, &Value)
 static void print_token_value (FILE *, int, YYSTYPE const *);
 
-static void add_param (char const *, char const *, location);
+static void add_param (char const *, char *, location);
 
 symbol_class current_class = unknown_sym;
 uniqstr current_type = 0;
@@ -196,7 +196,6 @@ symbol *current_lhs;
 location current_lhs_location;
 assoc current_assoc;
 int current_prec = 0;
-braced_code current_braced_code = action_braced_code;
 
 
 /* Enabling traces.  */
@@ -212,39 +211,42 @@ braced_code current_braced_code = action_braced_code;
 # define YYERROR_VERBOSE 0
 #endif
 
-#ifndef YYSTYPE
-#line 75 "parse-gram.y"
-typedef union {
+#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
+#line 74 "parse-gram.y"
+typedef union YYSTYPE {
   symbol *symbol;
   symbol_list *list;
   int integer;
   char *chars;
   assoc assoc;
   uniqstr uniqstr;
-} yystype;
-/* Line 195 of yacc.c.  */
-#line 226 "parse-gram.c"
-# define YYSTYPE yystype
+} YYSTYPE;
+/* Line 192 of yacc.c.  */
+#line 225 "parse-gram.c"
+# define yystype YYSTYPE /* obsolescent; will be withdrawn */
+# define YYSTYPE_IS_DECLARED 1
 # define YYSTYPE_IS_TRIVIAL 1
 #endif
 
-#ifndef YYLTYPE
-typedef struct yyltype
+#if ! defined (YYLTYPE) && ! defined (YYLTYPE_IS_DECLARED)
+typedef struct YYLTYPE
 {
   int first_line;
   int first_column;
   int last_line;
   int last_column;
-} yyltype;
-# define YYLTYPE yyltype
+} YYLTYPE;
+# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
+# define YYLTYPE_IS_DECLARED 1
 # define YYLTYPE_IS_TRIVIAL 1
 #endif
 
+
 /* Copy the second part of user declarations.  */
 
 
 /* Line 215 of yacc.c.  */
-#line 247 "parse-gram.c"
+#line 249 "parse-gram.c"
 
 #if ! defined (yyoverflow) || YYERROR_VERBOSE
 
@@ -344,24 +346,23 @@ union yyalloc
 /* YYFINAL -- State number of the termination state. */
 #define YYFINAL  3
 /* YYLAST -- Last index in YYTABLE.  */
-#define YYLAST   153
+#define YYLAST   157
 
 /* YYNTOKENS -- Number of terminals. */
 #define YYNTOKENS  46
 /* YYNNTS -- Number of nonterminals. */
-#define YYNNTS  28
+#define YYNNTS  25
 /* YYNRULES -- Number of rules. */
-#define YYNRULES  77
+#define YYNRULES  74
 /* YYNRULES -- Number of states. */
-#define YYNSTATES  109
+#define YYNSTATES  101
 
 /* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
 #define YYUNDEFTOK  2
 #define YYMAXUTOK   300
 
 #define YYTRANSLATE(YYX) 						\
-  ((YYX <= 0) ? YYEOF :							\
-   (unsigned)(YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)
+  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)
 
 /* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
 static const unsigned char yytranslate[] =
@@ -405,51 +406,50 @@ static const unsigned char yytranslate[] =
 static const unsigned char yyprhs[] =
 {
        0,     0,     3,     8,     9,    12,    14,    16,    18,    22,
-      24,    26,    29,    33,    35,    38,    40,    44,    46,    50,
-      53,    55,    58,    60,    62,    64,    66,    68,    70,    73,
-      76,    77,    82,    83,    88,    89,    93,    94,    98,   102,
-     106,   108,   110,   112,   113,   115,   117,   120,   122,   124,
-     127,   130,   134,   136,   139,   141,   144,   146,   148,   151,
-     153,   154,   158,   160,   164,   165,   168,   171,   175,   179,
-     183,   185,   187,   189,   191,   193,   195,   196
+      24,    26,    29,    33,    35,    37,    39,    43,    45,    49,
+      51,    53,    56,    58,    60,    62,    64,    66,    68,    71,
+      73,    76,    79,    80,    84,    85,    89,    93,    97,    99,
+     101,   103,   104,   106,   108,   111,   113,   115,   118,   121,
+     125,   127,   130,   132,   135,   137,   139,   142,   144,   145,
+     149,   151,   155,   156,   159,   162,   166,   170,   174,   176,
+     178,   180,   182,   184,   185
 };
 
 /* YYRHS -- A `-1'-separated list of the rules' RHS. */
 static const yysigned_char yyrhs[] =
 {
-      47,     0,    -1,    48,    42,    62,    73,    -1,    -1,    48,
-      49,    -1,    50,    -1,    43,    -1,    17,    -1,    18,    71,
-      71,    -1,    19,    -1,    20,    -1,    21,     4,    -1,    22,
-      37,    71,    -1,    23,    -1,    24,    72,    -1,    25,    -1,
-      26,    37,    71,    -1,    27,    -1,    28,    37,    71,    -1,
-      29,    72,    -1,    30,    -1,    31,    71,    -1,    33,    -1,
-      34,    -1,    35,    -1,    38,    -1,    56,    -1,    53,    -1,
-      32,    68,    -1,    10,    45,    -1,    -1,     8,    51,    45,
-      59,    -1,    -1,     9,    52,    45,    59,    -1,    -1,     6,
-      54,    61,    -1,    -1,     5,    55,    61,    -1,     7,    36,
-      59,    -1,    57,    58,    59,    -1,    11,    -1,    12,    -1,
-      13,    -1,    -1,    36,    -1,    68,    -1,    59,    68,    -1,
-      36,    -1,    40,    -1,    40,     4,    -1,    40,    70,    -1,
-      40,     4,    70,    -1,    60,    -1,    61,    60,    -1,    63,
-      -1,    62,    63,    -1,    64,    -1,    50,    -1,     1,    38,
-      -1,    38,    -1,    -1,    41,    65,    66,    -1,    67,    -1,
-      66,    39,    67,    -1,    -1,    67,    68,    -1,    67,    69,
-      -1,    67,    14,    68,    -1,    67,    15,     4,    -1,    67,
-      16,    36,    -1,    40,    -1,    70,    -1,    45,    -1,     3,
-      -1,     3,    -1,    45,    -1,    -1,    42,    44,    -1
+      47,     0,    -1,    48,    42,    60,    70,    -1,    -1,    48,
+      49,    -1,    50,    -1,    43,    -1,    17,    -1,    18,    69,
+      69,    -1,    19,    -1,    20,    -1,    21,     4,    -1,    22,
+      37,    69,    -1,    23,    -1,    24,    -1,    25,    -1,    26,
+      37,    69,    -1,    27,    -1,    28,    37,    69,    -1,    29,
+      -1,    30,    -1,    31,    69,    -1,    33,    -1,    34,    -1,
+      35,    -1,    38,    -1,    54,    -1,    51,    -1,    32,    66,
+      -1,    10,    -1,     8,    57,    -1,     9,    57,    -1,    -1,
+       6,    52,    59,    -1,    -1,     5,    53,    59,    -1,     7,
+      36,    57,    -1,    55,    56,    57,    -1,    11,    -1,    12,
+      -1,    13,    -1,    -1,    36,    -1,    66,    -1,    57,    66,
+      -1,    36,    -1,    40,    -1,    40,     4,    -1,    40,    68,
+      -1,    40,     4,    68,    -1,    58,    -1,    59,    58,    -1,
+      61,    -1,    60,    61,    -1,    62,    -1,    50,    -1,     1,
+      38,    -1,    38,    -1,    -1,    41,    63,    64,    -1,    65,
+      -1,    64,    39,    65,    -1,    -1,    65,    66,    -1,    65,
+      67,    -1,    65,    14,    66,    -1,    65,    15,     4,    -1,
+      65,    16,    36,    -1,    40,    -1,    68,    -1,    45,    -1,
+       3,    -1,     3,    -1,    -1,    42,    44,    -1
 };
 
 /* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
 static const unsigned short yyrline[] =
 {
-       0,   156,   156,   164,   166,   170,   171,   172,   173,   174,
-     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
-     185,   186,   187,   188,   189,   190,   194,   195,   196,   200,
-     207,   206,   217,   216,   229,   229,   234,   234,   239,   249,
-     264,   265,   266,   270,   271,   277,   278,   283,   287,   292,
-     298,   304,   315,   316,   325,   326,   332,   333,   338,   342,
-     346,   346,   350,   351,   356,   357,   359,   361,   363,   365,
-     370,   371,   375,   381,   390,   399,   406,   408
+       0,   160,   160,   168,   170,   174,   175,   176,   177,   178,
+     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
+     189,   190,   191,   192,   193,   194,   198,   199,   200,   204,
+     210,   217,   227,   227,   232,   232,   237,   247,   262,   263,
+     264,   268,   269,   275,   276,   281,   285,   290,   296,   302,
+     313,   314,   323,   324,   330,   331,   336,   340,   344,   344,
+     348,   349,   354,   355,   357,   359,   361,   363,   368,   369,
+     373,   379,   388,   395,   397
 };
 #endif
 
@@ -459,22 +459,22 @@ static const unsigned short yyrline[] =
 static const char *const yytname[] =
 {
   "\"end of file\"", "error", "$undefined", "\"string\"", "\"integer\"", 
-  "\"%token\"", "\"%nterm\"", "\"%type\"", "\"%destructor\"", 
-  "\"%printer\"", "\"%union\"", "\"%left\"", "\"%right\"", 
+  "\"%token\"", "\"%nterm\"", "\"%type\"", "\"%destructor {...}\"", 
+  "\"%printer {...}\"", "\"%union {...}\"", "\"%left\"", "\"%right\"", 
   "\"%nonassoc\"", "\"%prec\"", "\"%dprec\"", "\"%merge\"", "\"%debug\"", 
   "\"%define\"", "\"%defines\"", "\"%error-verbose\"", "\"%expect\"", 
-  "\"%file-prefix\"", "\"%glr-parser\"", "\"%lex-param\"", 
+  "\"%file-prefix\"", "\"%glr-parser\"", "\"%lex-param {...}\"", 
   "\"%locations\"", "\"%name-prefix\"", "\"%no-lines\"", "\"%output\"", 
-  "\"%parse-param\"", "\"%pure-parser\"", "\"%skeleton\"", "\"%start\"", 
-  "\"%token-table\"", "\"%verbose\"", "\"%yacc\"", "\"type\"", "\"=\"", 
-  "\";\"", "\"|\"", "\"identifier\"", "\"identifier:\"", "\"%%\"", 
-  "\"%{...%}\"", "\"epilogue\"", "\"{...}\"", "$accept", "input", 
-  "declarations", "declaration", "grammar_declaration", "@1", "@2", 
-  "symbol_declaration", "@3", "@4", "precedence_declaration", 
-  "precedence_declarator", "type.opt", "symbols.1", "symbol_def", 
-  "symbol_defs.1", "grammar", "rules_or_grammar_declaration", "rules", 
-  "@5", "rhses.1", "rhs", "symbol", "action", "string_as_id", 
-  "string_content", "code_content", "epilogue.opt", 0
+  "\"%parse-param {...}\"", "\"%pure-parser\"", "\"%skeleton\"", 
+  "\"%start\"", "\"%token-table\"", "\"%verbose\"", "\"%yacc\"", 
+  "\"type\"", "\"=\"", "\";\"", "\"|\"", "\"identifier\"", 
+  "\"identifier:\"", "\"%%\"", "\"%{...%}\"", "\"epilogue\"", "\"{...}\"", 
+  "$accept", "input", "declarations", "declaration", 
+  "grammar_declaration", "symbol_declaration", "@1", "@2", 
+  "precedence_declaration", "precedence_declarator", "type.opt", 
+  "symbols.1", "symbol_def", "symbol_defs.1", "grammar", 
+  "rules_or_grammar_declaration", "rules", "@3", "rhses.1", "rhs", 
+  "symbol", "action", "string_as_id", "string_content", "epilogue.opt", 0
 };
 #endif
 
@@ -497,24 +497,24 @@ static const unsigned char yyr1[] =
        0,    46,    47,    48,    48,    49,    49,    49,    49,    49,
       49,    49,    49,    49,    49,    49,    49,    49,    49,    49,
       49,    49,    49,    49,    49,    49,    50,    50,    50,    50,
-      51,    50,    52,    50,    54,    53,    55,    53,    53,    56,
-      57,    57,    57,    58,    58,    59,    59,    60,    60,    60,
-      60,    60,    61,    61,    62,    62,    63,    63,    63,    63,
-      65,    64,    66,    66,    67,    67,    67,    67,    67,    67,
-      68,    68,    69,    70,    71,    72,    73,    73
+      50,    50,    52,    51,    53,    51,    51,    54,    55,    55,
+      55,    56,    56,    57,    57,    58,    58,    58,    58,    58,
+      59,    59,    60,    60,    61,    61,    61,    61,    63,    62,
+      64,    64,    65,    65,    65,    65,    65,    65,    66,    66,
+      67,    68,    69,    70,    70
 };
 
 /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
 static const unsigned char yyr2[] =
 {
        0,     2,     4,     0,     2,     1,     1,     1,     3,     1,
-       1,     2,     3,     1,     2,     1,     3,     1,     3,     2,
-       1,     2,     1,     1,     1,     1,     1,     1,     2,     2,
-       0,     4,     0,     4,     0,     3,     0,     3,     3,     3,
-       1,     1,     1,     0,     1,     1,     2,     1,     1,     2,
-       2,     3,     1,     2,     1,     2,     1,     1,     2,     1,
-       0,     3,     1,     3,     0,     2,     2,     3,     3,     3,
-       1,     1,     1,     1,     1,     1,     0,     2
+       1,     2,     3,     1,     1,     1,     3,     1,     3,     1,
+       1,     2,     1,     1,     1,     1,     1,     1,     2,     1,
+       2,     2,     0,     3,     0,     3,     3,     3,     1,     1,
+       1,     0,     1,     1,     2,     1,     1,     2,     2,     3,
+       1,     2,     1,     2,     1,     1,     2,     1,     0,     3,
+       1,     3,     0,     2,     2,     3,     3,     3,     1,     1,
+       1,     1,     1,     0,     2
 };
 
 /* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
@@ -522,96 +522,96 @@ static const unsigned char yyr2[] =
    means the default is an error.  */
 static const unsigned char yydefact[] =
 {
-       3,     0,     0,     1,    36,    34,     0,    30,    32,     0,
-      40,    41,    42,     7,     0,     9,    10,     0,     0,    13,
-       0,    15,     0,    17,     0,     0,    20,     0,     0,    22,
-      23,    24,    25,     0,     6,     4,     5,    27,    26,    43,
-       0,     0,     0,     0,     0,    29,    74,     0,    11,     0,
-      75,    14,     0,     0,    19,    21,    73,    70,    28,    71,
-       0,    59,    60,    57,     0,    54,    56,    44,     0,    47,
-      48,    52,    37,    35,    38,    45,     0,     0,     8,    12,
-      16,    18,    58,    64,     0,    55,     2,    39,    49,    50,
-      53,    46,    31,    33,    61,    62,    77,    51,    64,     0,
-       0,     0,    72,    65,    66,    63,    67,    68,    69
+       3,     0,     0,     1,    34,    32,     0,     0,     0,    29,
+      38,    39,    40,     7,     0,     9,    10,     0,     0,    13,
+      14,    15,     0,    17,     0,    19,    20,     0,     0,    22,
+      23,    24,    25,     0,     6,     4,     5,    27,    26,    41,
+       0,     0,     0,    71,    68,    30,    43,    69,    31,    72,
+       0,    11,     0,     0,     0,    21,    28,     0,    57,    58,
+      55,     0,    52,    54,    42,     0,    45,    46,    50,    35,
+      33,    36,    44,     8,    12,    16,    18,    56,    62,     0,
+      53,     2,    37,    47,    48,    51,    59,    60,    74,    49,
+      62,     0,     0,     0,    70,    63,    64,    61,    65,    66,
+      67
 };
 
 /* YYDEFGOTO[NTERM-NUM]. */
 static const yysigned_char yydefgoto[] =
 {
-      -1,     1,     2,    35,    63,    43,    44,    37,    41,    40,
-      38,    39,    68,    74,    71,    72,    64,    65,    66,    83,
-      94,    95,    75,   104,    59,    47,    51,    86
+      -1,     1,     2,    35,    60,    37,    41,    40,    38,    39,
+      65,    45,    68,    69,    61,    62,    63,    78,    86,    87,
+      46,    96,    47,    50,    81
 };
 
 /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
    STATE-NUM.  */
-#define YYPACT_NINF -67
+#define YYPACT_NINF -65
 static const yysigned_char yypact[] =
 {
-     -67,     5,   110,   -67,   -67,   -67,   -17,   -67,   -67,   -14,
-     -67,   -67,   -67,   -67,    29,   -67,   -67,    30,    -1,   -67,
-     -10,   -67,     4,   -67,     7,   -10,   -67,    29,     0,   -67,
-     -67,   -67,   -67,    73,   -67,   -67,   -67,   -67,   -67,     2,
-     -20,   -20,     0,    -8,     3,   -67,   -67,    29,   -67,    29,
-     -67,   -67,    29,    29,   -67,   -67,   -67,   -67,   -67,   -67,
-      11,   -67,   -67,   -67,     1,   -67,   -67,   -67,     0,   -67,
-      14,   -67,   -20,   -20,     0,   -67,     0,     0,   -67,   -67,
-     -67,   -67,   -67,   -67,     9,   -67,   -67,     0,    51,   -67,
-     -67,   -67,     0,     0,    16,    12,   -67,   -67,   -67,     0,
-      52,    22,   -67,   -67,   -67,    12,   -67,   -67,   -67
+     -65,     5,   114,   -65,   -65,   -65,   -24,     1,     1,   -65,
+     -65,   -65,   -65,   -65,    10,   -65,   -65,    11,   -23,   -65,
+     -65,   -65,   -21,   -65,   -15,   -65,   -65,    10,     1,   -65,
+     -65,   -65,   -65,    77,   -65,   -65,   -65,   -65,   -65,   -13,
+     -34,   -34,     1,   -65,   -65,     1,   -65,   -65,     1,   -65,
+      10,   -65,    10,    10,    10,   -65,   -65,   -17,   -65,   -65,
+     -65,    39,   -65,   -65,   -65,     1,   -65,     4,   -65,   -34,
+     -34,     1,   -65,   -65,   -65,   -65,   -65,   -65,   -65,   -20,
+     -65,   -65,     1,    22,   -65,   -65,   -12,    15,   -65,   -65,
+     -65,     1,    24,   -10,   -65,   -65,   -65,    15,   -65,   -65,
+     -65
 };
 
 /* YYPGOTO[NTERM-NUM].  */
 static const yysigned_char yypgoto[] =
 {
-     -67,   -67,   -67,   -67,    58,   -67,   -67,   -67,   -67,   -67,
-     -67,   -67,   -67,   -47,   -49,    20,   -67,     6,   -67,   -67,
-     -67,   -36,   -28,   -67,   -66,    -2,    38,   -67
+     -65,   -65,   -65,   -65,    30,   -65,   -65,   -65,   -65,   -65,
+     -65,    -7,   -60,    -8,   -65,   -19,   -65,   -65,   -65,   -37,
+     -28,   -65,   -64,   -16,   -65
 };
 
 /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
    positive, shift that token.  If negative, reduce the rule which
    number is the opposite.  If zero, do what YYDEFACT says.
    If YYTABLE_NINF, syntax error.  */
-#define YYTABLE_NINF -77
+#define YYTABLE_NINF -74
 static const yysigned_char yytable[] =
 {
-      58,   -76,    60,    56,    89,     3,     4,     5,     6,     7,
-       8,     9,    10,    11,    12,    56,    69,    56,    88,    42,
-      70,    87,    97,    90,    90,    55,    99,   100,   101,    92,
-      93,    45,    46,    28,    48,    50,    49,    76,    67,    61,
-      57,    52,    62,    84,    53,    78,    91,    79,    77,    82,
-      80,    81,    57,    96,    56,    98,   107,   102,   108,    91,
-      36,    73,   105,    54,    91,    91,     0,   103,     0,     0,
-      85,   106,     0,     0,    60,     0,     0,   103,     4,     5,
-       6,     7,     8,     9,    10,    11,    12,     0,     0,     0,
-       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
-       0,     0,     0,     0,     0,    28,     0,     0,     0,     0,
-       0,    61,     0,     0,    62,     4,     5,     6,     7,     8,
-       9,    10,    11,    12,     0,     0,     0,    13,    14,    15,
-      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
-      26,    27,    28,    29,    30,    31,     0,     0,    32,     0,
-       0,     0,    33,    34
+      56,    48,    66,    84,    43,     3,    67,    43,    83,    85,
+      85,    55,    42,    49,    52,    51,    53,    72,    43,    89,
+      72,    77,    54,    64,    88,    43,   100,    90,    99,    91,
+      92,    93,    36,    70,    73,    71,    74,    75,    76,   -73,
+      57,    44,    80,    72,     4,     5,     6,     7,     8,     9,
+      10,    11,    12,    97,    72,    44,     0,     0,    82,    95,
+      94,     0,     0,    98,     0,     0,     0,     0,     0,    95,
+       0,    28,     0,     0,     0,     0,     0,    58,    57,     0,
+      59,    79,     4,     5,     6,     7,     8,     9,    10,    11,
+      12,     0,     0,     0,     0,     0,     0,     0,     0,     0,
+       0,     0,     0,     0,     0,     0,     0,     0,     0,    28,
+       0,     0,     0,     0,     0,    58,     0,     0,    59,     4,
+       5,     6,     7,     8,     9,    10,    11,    12,     0,     0,
+       0,    13,    14,    15,    16,    17,    18,    19,    20,    21,
+      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
+       0,     0,    32,     0,     0,     0,    33,    34
 };
 
 static const yysigned_char yycheck[] =
 {
-      28,     0,     1,     3,    70,     0,     5,     6,     7,     8,
-       9,    10,    11,    12,    13,     3,    36,     3,     4,    36,
-      40,    68,    88,    72,    73,    27,    14,    15,    16,    76,
-      77,    45,     3,    32,     4,    45,    37,    45,    36,    38,
-      40,    37,    41,    42,    37,    47,    74,    49,    45,    38,
-      52,    53,    40,    44,     3,    39,     4,    45,    36,    87,
-       2,    41,    98,    25,    92,    93,    -1,    95,    -1,    -1,
-      64,    99,    -1,    -1,     1,    -1,    -1,   105,     5,     6,
-       7,     8,     9,    10,    11,    12,    13,    -1,    -1,    -1,
-      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
-      -1,    -1,    -1,    -1,    -1,    32,    -1,    -1,    -1,    -1,
-      -1,    38,    -1,    -1,    41,     5,     6,     7,     8,     9,
-      10,    11,    12,    13,    -1,    -1,    -1,    17,    18,    19,
-      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
-      30,    31,    32,    33,    34,    35,    -1,    -1,    38,    -1,
-      -1,    -1,    42,    43
+      28,     8,    36,    67,     3,     0,    40,     3,     4,    69,
+      70,    27,    36,     3,    37,     4,    37,    45,     3,    83,
+      48,    38,    37,    36,    44,     3,    36,    39,     4,    14,
+      15,    16,     2,    41,    50,    42,    52,    53,    54,     0,
+       1,    40,    61,    71,     5,     6,     7,     8,     9,    10,
+      11,    12,    13,    90,    82,    40,    -1,    -1,    65,    87,
+      45,    -1,    -1,    91,    -1,    -1,    -1,    -1,    -1,    97,
+      -1,    32,    -1,    -1,    -1,    -1,    -1,    38,     1,    -1,
+      41,    42,     5,     6,     7,     8,     9,    10,    11,    12,
+      13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
+      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,
+      -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,    41,     5,
+       6,     7,     8,     9,    10,    11,    12,    13,    -1,    -1,
+      -1,    17,    18,    19,    20,    21,    22,    23,    24,    25,
+      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
+      -1,    -1,    38,    -1,    -1,    -1,    42,    43
 };
 
 /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
@@ -621,14 +621,14 @@ static const unsigned char yystos[] =
        0,    47,    48,     0,     5,     6,     7,     8,     9,    10,
       11,    12,    13,    17,    18,    19,    20,    21,    22,    23,
       24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
-      34,    35,    38,    42,    43,    49,    50,    53,    56,    57,
-      55,    54,    36,    51,    52,    45,     3,    71,     4,    37,
-      45,    72,    37,    37,    72,    71,     3,    40,    68,    70,
-       1,    38,    41,    50,    62,    63,    64,    36,    58,    36,
-      40,    60,    61,    61,    59,    68,    45,    45,    71,    71,
-      71,    71,    38,    65,    42,    63,    73,    59,     4,    70,
-      60,    68,    59,    59,    66,    67,    44,    70,    39,    14,
-      15,    16,    45,    68,    69,    67,    68,     4,    36
+      34,    35,    38,    42,    43,    49,    50,    51,    54,    55,
+      53,    52,    36,     3,    40,    57,    66,    68,    57,     3,
+      69,     4,    37,    37,    37,    69,    66,     1,    38,    41,
+      50,    60,    61,    62,    36,    56,    36,    40,    58,    59,
+      59,    57,    66,    69,    69,    69,    69,    38,    63,    42,
+      61,    70,    57,     4,    68,    58,    64,    65,    44,    68,
+      39,    14,    15,    16,    45,    66,    67,    65,    66,     4,
+      36
 };
 
 #if ! defined (YYSIZE_T) && defined (__SIZE_TYPE__)
@@ -648,8 +648,8 @@ static const unsigned char yystos[] =
 #endif
 
 #define yyerrok		(yyerrstatus = 0)
-#define yyclearin	(yytoken = YYEMPTY)
-#define YYEMPTY		-2
+#define yyclearin	(yychar = YYEMPTY)
+#define YYEMPTY		(-2)
 #define YYEOF		0
 
 #define YYACCEPT	goto yyacceptlab
@@ -666,7 +666,7 @@ static const unsigned char yystos[] =
 
 #define YYBACKUP(Token, Value)					\
 do								\
-  if (yytoken == YYEMPTY && yylen == 1)				\
+  if (yychar == YYEMPTY && yylen == 1)				\
     {								\
       yychar = (Token);						\
       yylval = (Value);						\
@@ -1051,7 +1051,7 @@ YYLTYPE yylloc;
   yystate = 0;
   yyerrstatus = 0;
   yynerrs = 0;
-  yychar = yytoken = YYEMPTY;		/* Cause a token to be read.  */
+  yychar = YYEMPTY;		/* Cause a token to be read.  */
 
   /* Initialize stack pointers.
      Waste one element of value and location stack
@@ -1161,20 +1161,21 @@ yybackup:
 
   /* Not known => get a lookahead token if don't already have one.  */
 
-  /* YYTOKEN is either YYEMPTY or YYEOF or a valid token.  */
-  if (yytoken == YYEMPTY)
+  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
+  if (yychar == YYEMPTY)
     {
       YYDPRINTF ((stderr, "Reading a token: "));
       yychar = YYLEX;
-      yytoken = YYTRANSLATE (yychar);
     }
 
-  if (yytoken == YYEOF)
+  if (yychar <= YYEOF)
     {
+      yychar = yytoken = YYEOF;
       YYDPRINTF ((stderr, "Now at end of input.\n"));
     }
   else
     {
+      yytoken = YYTRANSLATE (yychar);
       YYDSYMPRINTF ("Next token is", yytoken, &yylval, &yylloc);
     }
 
@@ -1199,8 +1200,8 @@ yybackup:
   YYDPRINTF ((stderr, "Shifting token %s, ", yytname[yytoken]));
 
   /* Discard the token being shifted unless it is eof.  */
-  if (yytoken != YYEOF)
-    yytoken = YYEMPTY;
+  if (yychar != YYEOF)
+    yychar = YYEMPTY;
 
   *++yyvsp = yylval;
   *++yylsp = yylloc;
@@ -1247,109 +1248,109 @@ yyreduce:
   switch (yyn)
     {
         case 6:
-#line 171 "parse-gram.y"
+#line 175 "parse-gram.y"
     { prologue_augment (yyvsp[0].chars, yylsp[0]); }
     break;
 
   case 7:
-#line 172 "parse-gram.y"
+#line 176 "parse-gram.y"
     { debug_flag = 1; }
     break;
 
   case 8:
-#line 173 "parse-gram.y"
+#line 177 "parse-gram.y"
     { muscle_insert (yyvsp[-1].chars, yyvsp[0].chars); }
     break;
 
   case 9:
-#line 174 "parse-gram.y"
+#line 178 "parse-gram.y"
     { defines_flag = 1; }
     break;
 
   case 10:
-#line 175 "parse-gram.y"
+#line 179 "parse-gram.y"
     { error_verbose = 1; }
     break;
 
   case 11:
-#line 176 "parse-gram.y"
+#line 180 "parse-gram.y"
     { expected_conflicts = yyvsp[0].integer; }
     break;
 
   case 12:
-#line 177 "parse-gram.y"
+#line 181 "parse-gram.y"
     { spec_file_prefix = yyvsp[0].chars; }
     break;
 
   case 13:
-#line 178 "parse-gram.y"
+#line 182 "parse-gram.y"
     { glr_parser = 1; }
     break;
 
   case 14:
-#line 179 "parse-gram.y"
+#line 183 "parse-gram.y"
     { add_param ("lex_param", yyvsp[0].chars, yylsp[0]); }
     break;
 
   case 15:
-#line 180 "parse-gram.y"
+#line 184 "parse-gram.y"
     { locations_flag = 1; }
     break;
 
   case 16:
-#line 181 "parse-gram.y"
+#line 185 "parse-gram.y"
     { spec_name_prefix = yyvsp[0].chars; }
     break;
 
   case 17:
-#line 182 "parse-gram.y"
+#line 186 "parse-gram.y"
     { no_lines_flag = 1; }
     break;
 
   case 18:
-#line 183 "parse-gram.y"
+#line 187 "parse-gram.y"
     { spec_outfile = yyvsp[0].chars; }
     break;
 
   case 19:
-#line 184 "parse-gram.y"
+#line 188 "parse-gram.y"
     { add_param ("parse_param", yyvsp[0].chars, yylsp[0]); }
     break;
 
   case 20:
-#line 185 "parse-gram.y"
+#line 189 "parse-gram.y"
     { pure_parser = 1; }
     break;
 
   case 21:
-#line 186 "parse-gram.y"
+#line 190 "parse-gram.y"
     { skeleton = yyvsp[0].chars; }
     break;
 
   case 22:
-#line 187 "parse-gram.y"
+#line 191 "parse-gram.y"
     { token_table_flag = 1; }
     break;
 
   case 23:
-#line 188 "parse-gram.y"
+#line 192 "parse-gram.y"
     { report_flag = 1; }
     break;
 
   case 24:
-#line 189 "parse-gram.y"
+#line 193 "parse-gram.y"
     { yacc_flag = 1; }
     break;
 
   case 28:
-#line 197 "parse-gram.y"
+#line 201 "parse-gram.y"
     {
       grammar_start_symbol_set (yyvsp[0].symbol, yylsp[0]);
     }
     break;
 
   case 29:
-#line 201 "parse-gram.y"
+#line 205 "parse-gram.y"
     {
       typed = 1;
       MUSCLE_INSERT_INT ("stype_line", yylsp[0].start.line);
@@ -1358,65 +1359,53 @@ yyreduce:
     break;
 
   case 30:
-#line 207 "parse-gram.y"
-    { current_braced_code = destructor_braced_code; }
-    break;
-
-  case 31:
-#line 209 "parse-gram.y"
+#line 211 "parse-gram.y"
     {
       symbol_list *list;
       for (list = yyvsp[0].list; list; list = list->next)
 	symbol_destructor_set (list->sym, yyvsp[-1].chars, yylsp[-1]);
       symbol_list_free (yyvsp[0].list);
-      current_braced_code = action_braced_code;
     }
     break;
 
-  case 32:
-#line 217 "parse-gram.y"
-    { current_braced_code = printer_braced_code; }
-    break;
-
-  case 33:
-#line 219 "parse-gram.y"
+  case 31:
+#line 218 "parse-gram.y"
     {
       symbol_list *list;
       for (list = yyvsp[0].list; list; list = list->next)
 	symbol_printer_set (list->sym, yyvsp[-1].chars, list->location);
       symbol_list_free (yyvsp[0].list);
-      current_braced_code = action_braced_code;
     }
     break;
 
-  case 34:
-#line 229 "parse-gram.y"
+  case 32:
+#line 227 "parse-gram.y"
     { current_class = nterm_sym; }
     break;
 
-  case 35:
-#line 230 "parse-gram.y"
+  case 33:
+#line 228 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
     break;
 
-  case 36:
-#line 234 "parse-gram.y"
+  case 34:
+#line 232 "parse-gram.y"
     { current_class = token_sym; }
     break;
 
-  case 37:
-#line 235 "parse-gram.y"
+  case 35:
+#line 233 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
     break;
 
-  case 38:
-#line 240 "parse-gram.y"
+  case 36:
+#line 238 "parse-gram.y"
     {
       symbol_list *list;
       for (list = yyvsp[0].list; list; list = list->next)
@@ -1425,8 +1414,8 @@ yyreduce:
     }
     break;
 
-  case 39:
-#line 250 "parse-gram.y"
+  case 37:
+#line 248 "parse-gram.y"
     {
       symbol_list *list;
       ++current_prec;
@@ -1440,58 +1429,58 @@ yyreduce:
     }
     break;
 
-  case 40:
-#line 264 "parse-gram.y"
+  case 38:
+#line 262 "parse-gram.y"
     { yyval.assoc = left_assoc; }
     break;
 
-  case 41:
-#line 265 "parse-gram.y"
+  case 39:
+#line 263 "parse-gram.y"
     { yyval.assoc = right_assoc; }
     break;
 
-  case 42:
-#line 266 "parse-gram.y"
+  case 40:
+#line 264 "parse-gram.y"
     { yyval.assoc = non_assoc; }
     break;
 
-  case 43:
-#line 270 "parse-gram.y"
+  case 41:
+#line 268 "parse-gram.y"
     { current_type = NULL; }
     break;
 
-  case 44:
-#line 271 "parse-gram.y"
+  case 42:
+#line 269 "parse-gram.y"
     { current_type = yyvsp[0].uniqstr; }
     break;
 
-  case 45:
-#line 277 "parse-gram.y"
+  case 43:
+#line 275 "parse-gram.y"
     { yyval.list = symbol_list_new (yyvsp[0].symbol, yylsp[0]); }
     break;
 
-  case 46:
-#line 278 "parse-gram.y"
+  case 44:
+#line 276 "parse-gram.y"
     { yyval.list = symbol_list_prepend (yyvsp[-1].list, yyvsp[0].symbol, yylsp[0]); }
     break;
 
-  case 47:
-#line 284 "parse-gram.y"
+  case 45:
+#line 282 "parse-gram.y"
     {
        current_type = yyvsp[0].uniqstr;
      }
     break;
 
-  case 48:
-#line 288 "parse-gram.y"
+  case 46:
+#line 286 "parse-gram.y"
     {
        symbol_class_set (yyvsp[0].symbol, current_class, yylsp[0]);
        symbol_type_set (yyvsp[0].symbol, current_type, yylsp[0]);
      }
     break;
 
-  case 49:
-#line 293 "parse-gram.y"
+  case 47:
+#line 291 "parse-gram.y"
     {
       symbol_class_set (yyvsp[-1].symbol, current_class, yylsp[-1]);
       symbol_type_set (yyvsp[-1].symbol, current_type, yylsp[-1]);
@@ -1499,8 +1488,8 @@ yyreduce:
     }
     break;
 
-  case 50:
-#line 299 "parse-gram.y"
+  case 48:
+#line 297 "parse-gram.y"
     {
       symbol_class_set (yyvsp[-1].symbol, current_class, yylsp[-1]);
       symbol_type_set (yyvsp[-1].symbol, current_type, yylsp[-1]);
@@ -1508,8 +1497,8 @@ yyreduce:
     }
     break;
 
-  case 51:
-#line 305 "parse-gram.y"
+  case 49:
+#line 303 "parse-gram.y"
     {
       symbol_class_set (yyvsp[-2].symbol, current_class, yylsp[-2]);
       symbol_type_set (yyvsp[-2].symbol, current_type, yylsp[-2]);
@@ -1518,107 +1507,99 @@ yyreduce:
     }
     break;
 
-  case 57:
-#line 334 "parse-gram.y"
+  case 55:
+#line 332 "parse-gram.y"
     {
       if (yacc_flag)
 	complain_at (yyloc, _("POSIX forbids declarations in the grammar"));
     }
     break;
 
-  case 58:
-#line 339 "parse-gram.y"
+  case 56:
+#line 337 "parse-gram.y"
     {
       yyerrok;
     }
     break;
 
-  case 60:
-#line 346 "parse-gram.y"
+  case 58:
+#line 344 "parse-gram.y"
     { current_lhs = yyvsp[0].symbol; current_lhs_location = yylsp[0]; }
     break;
 
-  case 62:
-#line 350 "parse-gram.y"
+  case 60:
+#line 348 "parse-gram.y"
     { grammar_rule_end (yylsp[0]); }
     break;
 
-  case 63:
-#line 351 "parse-gram.y"
+  case 61:
+#line 349 "parse-gram.y"
     { grammar_rule_end (yylsp[0]); }
     break;
 
-  case 64:
-#line 356 "parse-gram.y"
+  case 62:
+#line 354 "parse-gram.y"
     { grammar_rule_begin (current_lhs, current_lhs_location); }
     break;
 
-  case 65:
-#line 358 "parse-gram.y"
+  case 63:
+#line 356 "parse-gram.y"
     { grammar_current_rule_symbol_append (yyvsp[0].symbol, yylsp[0]); }
     break;
 
-  case 66:
-#line 360 "parse-gram.y"
+  case 64:
+#line 358 "parse-gram.y"
     { grammar_current_rule_action_append (yyvsp[0].chars, yylsp[0]); }
     break;
 
-  case 67:
-#line 362 "parse-gram.y"
+  case 65:
+#line 360 "parse-gram.y"
     { grammar_current_rule_prec_set (yyvsp[0].symbol, yylsp[0]); }
     break;
 
-  case 68:
-#line 364 "parse-gram.y"
+  case 66:
+#line 362 "parse-gram.y"
     { grammar_current_rule_dprec_set (yyvsp[0].integer, yylsp[0]); }
     break;
 
-  case 69:
-#line 366 "parse-gram.y"
+  case 67:
+#line 364 "parse-gram.y"
     { grammar_current_rule_merge_set (yyvsp[0].uniqstr, yylsp[0]); }
     break;
 
-  case 70:
-#line 370 "parse-gram.y"
+  case 68:
+#line 368 "parse-gram.y"
     { yyval.symbol = yyvsp[0].symbol; }
     break;
 
-  case 71:
-#line 371 "parse-gram.y"
+  case 69:
+#line 369 "parse-gram.y"
     { yyval.symbol = yyvsp[0].symbol; }
     break;
 
-  case 72:
-#line 376 "parse-gram.y"
+  case 70:
+#line 374 "parse-gram.y"
     { yyval.chars = yyvsp[0].chars; }
     break;
 
-  case 73:
-#line 382 "parse-gram.y"
+  case 71:
+#line 380 "parse-gram.y"
     {
       yyval.symbol = symbol_get (yyvsp[0].chars, yylsp[0]);
       symbol_class_set (yyval.symbol, token_sym, yylsp[0]);
     }
     break;
 
-  case 74:
-#line 391 "parse-gram.y"
-    {
-      yyval.chars = yyvsp[0].chars + 1;
-      yyval.chars[strlen (yyval.chars) - 1] = '\0';
-    }
-    break;
-
-  case 75:
-#line 400 "parse-gram.y"
+  case 72:
+#line 389 "parse-gram.y"
     {
       yyval.chars = yyvsp[0].chars + 1;
       yyval.chars[strlen (yyval.chars) - 1] = '\0';
     }
     break;
 
-  case 77:
-#line 409 "parse-gram.y"
+  case 74:
+#line 398 "parse-gram.y"
     {
       epilogue_augment (yyvsp[0].chars, yylsp[0]);
       scanner_last_string_free ();
@@ -1629,7 +1610,7 @@ yyreduce:
     }
 
 /* Line 991 of yacc.c.  */
-#line 1632 "parse-gram.c"
+#line 1613 "parse-gram.c"
 
   yyvsp -= yylen;
   yyssp -= yylen;
@@ -1719,7 +1700,7 @@ yyerrlab:
 	 error, discard it.  */
 
       /* Return failure if at end of input.  */
-      if (yytoken == YYEOF)
+      if (yychar == YYEOF)
         {
 	  /* Pop the error token.  */
           YYPOPSTACK;
@@ -1735,7 +1716,7 @@ yyerrlab:
 
       YYDSYMPRINTF ("Error: discarding", yytoken, &yylval, &yylloc);
       yydestruct (yytoken, &yylval, &yylloc);
-      yytoken = YYEMPTY;
+      yychar = YYEMPTY;
     }
 
   /* Else will try to reuse lookahead token after shifting the error
@@ -1820,7 +1801,7 @@ yyreturn:
 }
 
 
-#line 415 "parse-gram.y"
+#line 404 "parse-gram.y"
 
 
 
@@ -1833,20 +1814,16 @@ static YYLTYPE
 lloc_default (YYLTYPE const *rhs, int n)
 {
   int i;
-  int j;
   YYLTYPE r;
   r.start = r.end = rhs[n].end;
 
+  /* Ignore empty nonterminals the start of the the right-hand side.
+     Do not bother to ignore them at the end of the right-hand side,
+     since empty nonterminals have the same end as their predecessors.  */
   for (i = 1; i <= n; i++)
     if (! equal_boundaries (rhs[i].start, rhs[i].end))
       {
 	r.start = rhs[i].start;
-
-	for (j = n; i < j; j--)
-	  if (! equal_boundaries (rhs[j].start, rhs[j].end))
-	    break;
-	r.end = rhs[j].end;
-
 	break;
       }
 
@@ -1858,7 +1835,7 @@ lloc_default (YYLTYPE const *rhs, int n)
    declaration DECL and location LOC.  */
 
 static void
-add_param (char const *type, char const *decl, location loc)
+add_param (char const *type, char *decl, location loc)
 {
   static char const alphanum[] =
     "0123456789"
@@ -1867,12 +1844,16 @@ add_param (char const *type, char const *decl, location loc)
     "_";
   char const *alpha = alphanum + 10;
   char const *name_start = NULL;
-  char const *p;
+  char *p;
 
   for (p = decl; *p; p++)
     if ((p == decl || ! strchr (alphanum, p[-1])) && strchr (alpha, p[0]))
       name_start = p;
 
+  /* Strip the surrounding '{' and '}'.  */
+  decl++;
+  p[-1] = '\0';
+
   if (! name_start)
     complain_at (loc, _("missing identifier in parameter declaration"));
   else
@@ -1895,9 +1876,9 @@ add_param (char const *type, char const *decl, location loc)
   scanner_last_string_free ();
 }
 
-/*------------------------------------------------------------------.
-| When debugging the parser, display tokens' locations and values.  |
-`------------------------------------------------------------------*/
+/*----------------------------------------------------.
+| When debugging the parser, display tokens' values.  |
+`----------------------------------------------------*/
 
 static void
 print_token_value (FILE *file, int type, YYSTYPE const *value)
@@ -1922,6 +1903,11 @@ print_token_value (FILE *file, int type, YYSTYPE const *value)
       break;
 
     case BRACED_CODE:
+    case PERCENT_DESTRUCTOR:
+    case PERCENT_LEX_PARAM:
+    case PERCENT_PARSE_PARAM:
+    case PERCENT_PRINTER:
+    case PERCENT_UNION:
     case PROLOGUE:
     case EPILOGUE:
       fprintf (file, " = {{ %s }}", value->chars);
@@ -1939,3 +1925,9 @@ gram_error (location const *loc, char const *msg)
   complain_at (*loc, "%s", msg);
 }
 
+char const *
+token_name (int type)
+{
+  return yytname[type];
+}
+
