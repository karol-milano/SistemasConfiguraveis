@@ -135,30 +135,33 @@ braced_code_t current_braced_code = action_braced_code;
      PERCENT_EXPECT = 270,
      PERCENT_START = 271,
      PERCENT_PREC = 272,
-     PERCENT_VERBOSE = 273,
-     PERCENT_ERROR_VERBOSE = 274,
-     PERCENT_OUTPUT = 275,
-     PERCENT_FILE_PREFIX = 276,
-     PERCENT_NAME_PREFIX = 277,
-     PERCENT_DEFINE = 278,
-     PERCENT_PURE_PARSER = 279,
-     PERCENT_DEFINES = 280,
-     PERCENT_YACC = 281,
-     PERCENT_DEBUG = 282,
-     PERCENT_LOCATIONS = 283,
-     PERCENT_NO_LINES = 284,
-     PERCENT_SKELETON = 285,
-     PERCENT_TOKEN_TABLE = 286,
-     TYPE = 287,
-     EQUAL = 288,
-     SEMICOLON = 289,
-     COLON = 290,
-     PIPE = 291,
-     ID = 292,
-     PERCENT_PERCENT = 293,
-     PROLOGUE = 294,
-     EPILOGUE = 295,
-     BRACED_CODE = 296
+     PERCENT_DPREC = 273,
+     PERCENT_MERGE = 274,
+     PERCENT_VERBOSE = 275,
+     PERCENT_ERROR_VERBOSE = 276,
+     PERCENT_OUTPUT = 277,
+     PERCENT_FILE_PREFIX = 278,
+     PERCENT_NAME_PREFIX = 279,
+     PERCENT_DEFINE = 280,
+     PERCENT_PURE_PARSER = 281,
+     PERCENT_GLR_PARSER = 282,
+     PERCENT_DEFINES = 283,
+     PERCENT_YACC = 284,
+     PERCENT_DEBUG = 285,
+     PERCENT_LOCATIONS = 286,
+     PERCENT_NO_LINES = 287,
+     PERCENT_SKELETON = 288,
+     PERCENT_TOKEN_TABLE = 289,
+     TYPE = 290,
+     EQUAL = 291,
+     SEMICOLON = 292,
+     COLON = 293,
+     PIPE = 294,
+     ID = 295,
+     PERCENT_PERCENT = 296,
+     PROLOGUE = 297,
+     EPILOGUE = 298,
+     BRACED_CODE = 299
    };
 # endif
   /* POSIX requires `int' for tokens in interfaces.  */
@@ -180,30 +183,33 @@ braced_code_t current_braced_code = action_braced_code;
 #define PERCENT_EXPECT 270
 #define PERCENT_START 271
 #define PERCENT_PREC 272
-#define PERCENT_VERBOSE 273
-#define PERCENT_ERROR_VERBOSE 274
-#define PERCENT_OUTPUT 275
-#define PERCENT_FILE_PREFIX 276
-#define PERCENT_NAME_PREFIX 277
-#define PERCENT_DEFINE 278
-#define PERCENT_PURE_PARSER 279
-#define PERCENT_DEFINES 280
-#define PERCENT_YACC 281
-#define PERCENT_DEBUG 282
-#define PERCENT_LOCATIONS 283
-#define PERCENT_NO_LINES 284
-#define PERCENT_SKELETON 285
-#define PERCENT_TOKEN_TABLE 286
-#define TYPE 287
-#define EQUAL 288
-#define SEMICOLON 289
-#define COLON 290
-#define PIPE 291
-#define ID 292
-#define PERCENT_PERCENT 293
-#define PROLOGUE 294
-#define EPILOGUE 295
-#define BRACED_CODE 296
+#define PERCENT_DPREC 273
+#define PERCENT_MERGE 274
+#define PERCENT_VERBOSE 275
+#define PERCENT_ERROR_VERBOSE 276
+#define PERCENT_OUTPUT 277
+#define PERCENT_FILE_PREFIX 278
+#define PERCENT_NAME_PREFIX 279
+#define PERCENT_DEFINE 280
+#define PERCENT_PURE_PARSER 281
+#define PERCENT_GLR_PARSER 282
+#define PERCENT_DEFINES 283
+#define PERCENT_YACC 284
+#define PERCENT_DEBUG 285
+#define PERCENT_LOCATIONS 286
+#define PERCENT_NO_LINES 287
+#define PERCENT_SKELETON 288
+#define PERCENT_TOKEN_TABLE 289
+#define TYPE 290
+#define EQUAL 291
+#define SEMICOLON 292
+#define COLON 293
+#define PIPE 294
+#define ID 295
+#define PERCENT_PERCENT 296
+#define PROLOGUE 297
+#define EPILOGUE 298
+#define BRACED_CODE 299
 
 
 
@@ -230,8 +236,8 @@ typedef union {
   char *string;
   associativity assoc;
 } yystype;
-/* Line 232 of /usr/local/share/bison/bison.simple.  */
-#line 235 "parse-gram.c"
+/* Line 272 of /home/cs/hilfingr/work/grammars/glr2/install/share/bison/yacc.c.  */
+#line 241 "parse-gram.c"
 # define YYSTYPE yystype
 # define YYSTYPE_IS_TRIVIAL 1
 #endif
@@ -251,8 +257,8 @@ typedef struct yyltype
 /* Copy the second part of user declarations.  */
 
 
-/* Line 252 of /usr/local/share/bison/bison.simple.  */
-#line 256 "parse-gram.c"
+/* Line 292 of /home/cs/hilfingr/work/grammars/glr2/install/share/bison/yacc.c.  */
+#line 262 "parse-gram.c"
 
 #if ! defined (yyoverflow) || YYERROR_VERBOSE
 
@@ -346,20 +352,20 @@ union yyalloc
 /* YYFINAL -- State number of the termination state. */
 #define YYFINAL  3
 #define YYFLAG	 -32768
-#define YYLAST   151
+#define YYLAST   125
 
 /* YYNTOKENS -- Number of terminals. */
-#define YYNTOKENS  42
+#define YYNTOKENS  45
 /* YYNNTS -- Number of nonterminals. */
 #define YYNNTS  28
 /* YYNRULES -- Number of rules. */
-#define YYNRULES  71
+#define YYNRULES  74
 /* YYNRULES -- Number of states. */
-#define YYNSTATES  101
+#define YYNSTATES  106
 
 /* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
 #define YYUNDEFTOK  2
-#define YYMAXUTOK   296
+#define YYMAXUTOK   299
 
 #define YYTRANSLATE(X) \
   ((unsigned)(X) <= YYMAXUTOK ? yytranslate[X] : YYUNDEFTOK)
@@ -396,7 +402,7 @@ static const unsigned char yytranslate[] =
        5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
       15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
       25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
-      35,    36,    37,    38,    39,    40,    41
+      35,    36,    37,    38,    39,    40,    41,    42,    43,    44
 };
 
 #if YYDEBUG
@@ -405,50 +411,51 @@ static const unsigned char yytranslate[] =
 static const unsigned char yyprhs[] =
 {
        0,     0,     3,     8,     9,    13,    15,    17,    19,    23,
-      25,    27,    30,    34,    36,    40,    42,    46,    48,    51,
-      53,    55,    57,    59,    61,    64,    67,    68,    73,    74,
-      79,    80,    84,    85,    89,    93,    97,    99,   101,   103,
-     104,   106,   108,   111,   113,   115,   118,   121,   125,   127,
-     130,   132,   135,   137,   140,   141,   147,   149,   153,   154,
-     157,   160,   164,   166,   168,   170,   172,   174,   176,   177,
-     180,   181
+      25,    27,    30,    34,    36,    40,    42,    46,    48,    50,
+      53,    55,    57,    59,    61,    63,    66,    69,    70,    75,
+      76,    81,    82,    86,    87,    91,    95,    99,   101,   103,
+     105,   106,   108,   110,   113,   115,   117,   120,   123,   127,
+     129,   132,   134,   137,   139,   142,   143,   149,   151,   155,
+     156,   159,   162,   166,   170,   174,   176,   178,   180,   182,
+     184,   186,   187,   190,   191
 };
 
 /* YYRHS -- A `-1'-separated list of the rules' RHS. */
 static const signed char yyrhs[] =
 {
-      43,     0,    -1,    44,    38,    58,    68,    -1,    -1,    44,
-      45,    69,    -1,    46,    -1,    39,    -1,    27,    -1,    23,
-      67,    67,    -1,    25,    -1,    19,    -1,    15,     5,    -1,
-      21,    33,    67,    -1,    28,    -1,    22,    33,    67,    -1,
-      29,    -1,    20,    33,    67,    -1,    24,    -1,    30,    67,
-      -1,    31,    -1,    18,    -1,    26,    -1,    52,    -1,    49,
-      -1,    16,    64,    -1,    11,    41,    -1,    -1,     9,    47,
-      41,    55,    -1,    -1,    10,    48,    41,    55,    -1,    -1,
-       7,    50,    57,    -1,    -1,     6,    51,    57,    -1,     8,
-      32,    55,    -1,    53,    54,    55,    -1,    12,    -1,    13,
-      -1,    14,    -1,    -1,    32,    -1,    64,    -1,    55,    64,
-      -1,    32,    -1,    37,    -1,    37,     5,    -1,    37,    66,
-      -1,    37,     5,    66,    -1,    56,    -1,    57,    56,    -1,
-      59,    -1,    58,    59,    -1,    60,    -1,    46,    34,    -1,
-      -1,    37,    35,    61,    62,    34,    -1,    63,    -1,    62,
-      36,    63,    -1,    -1,    63,    64,    -1,    63,    65,    -1,
-      63,    17,    64,    -1,    37,    -1,    66,    -1,     4,    -1,
-      41,    -1,     3,    -1,     3,    -1,    -1,    38,    40,    -1,
-      -1,    34,    -1
+      46,     0,    -1,    47,    41,    61,    71,    -1,    -1,    47,
+      48,    72,    -1,    49,    -1,    42,    -1,    30,    -1,    25,
+      70,    70,    -1,    28,    -1,    21,    -1,    15,     5,    -1,
+      23,    36,    70,    -1,    31,    -1,    24,    36,    70,    -1,
+      32,    -1,    22,    36,    70,    -1,    26,    -1,    27,    -1,
+      33,    70,    -1,    34,    -1,    20,    -1,    29,    -1,    55,
+      -1,    52,    -1,    16,    67,    -1,    11,    44,    -1,    -1,
+       9,    50,    44,    58,    -1,    -1,    10,    51,    44,    58,
+      -1,    -1,     7,    53,    60,    -1,    -1,     6,    54,    60,
+      -1,     8,    35,    58,    -1,    56,    57,    58,    -1,    12,
+      -1,    13,    -1,    14,    -1,    -1,    35,    -1,    67,    -1,
+      58,    67,    -1,    35,    -1,    40,    -1,    40,     5,    -1,
+      40,    69,    -1,    40,     5,    69,    -1,    59,    -1,    60,
+      59,    -1,    62,    -1,    61,    62,    -1,    63,    -1,    49,
+      37,    -1,    -1,    40,    38,    64,    65,    37,    -1,    66,
+      -1,    65,    39,    66,    -1,    -1,    66,    67,    -1,    66,
+      68,    -1,    66,    17,    67,    -1,    66,    18,     5,    -1,
+      66,    19,    35,    -1,    40,    -1,    69,    -1,     4,    -1,
+      44,    -1,     3,    -1,     3,    -1,    -1,    41,    43,    -1,
+      -1,    37,    -1
 };
 
 /* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
 static const unsigned short yyrline[] =
 {
-       0,   155,   155,   168,   170,   173,   175,   176,   177,   178,
-     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
-     189,   190,   193,   195,   196,   200,   207,   206,   217,   216,
-     229,   228,   234,   234,   239,   248,   263,   265,   266,   269,
-     271,   276,   278,   282,   287,   292,   298,   304,   314,   317,
-     326,   328,   334,   336,   340,   339,   344,   346,   349,   352,
-     354,   356,   360,   362,   363,   366,   372,   381,   389,   394,
-     400,   402
+       0,   158,   158,   171,   173,   176,   178,   179,   180,   181,
+     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
+     192,   193,   194,   197,   199,   200,   204,   211,   210,   221,
+     220,   233,   232,   238,   238,   243,   252,   267,   269,   270,
+     273,   275,   280,   282,   286,   291,   296,   302,   308,   318,
+     321,   330,   332,   338,   340,   344,   343,   348,   350,   353,
+     356,   358,   360,   362,   364,   368,   370,   371,   374,   380,
+     389,   397,   402,   408,   410
 };
 #endif
 
@@ -460,19 +467,19 @@ static const char *const yytname[] =
   "\"end of string\"", "error", "$undefined.", "STRING", "CHARACTER", "INT", 
   "\"%token\"", "\"%nterm\"", "\"%type\"", "\"%destructor\"", 
   "\"%printer\"", "\"%union\"", "\"%left\"", "\"%right\"", 
-  "\"%nonassoc\"", "\"%expect\"", "\"%start\"", "\"%prec\"", 
-  "\"%verbose\"", "\"%error-verbose\"", "\"%output\"", "\"%file-prefix\"", 
-  "\"%name-prefix\"", "\"%define\"", "\"%pure-parser\"", "\"%defines\"", 
-  "\"%yacc\"", "\"%debug\"", "\"%locations\"", "\"%no-lines\"", 
-  "\"%skeleton\"", "\"%token-table\"", "TYPE", "\"=\"", "\";\"", "\":\"", 
-  "\"|\"", "\"identifier\"", "\"%%\"", "PROLOGUE", "EPILOGUE", 
-  "BRACED_CODE", "$axiom", "input", "declarations", "declaration", 
-  "grammar_declaration", "@1", "@2", "symbol_declaration", "@3", "@4", 
-  "precedence_declaration", "precedence_declarator", "type.opt", 
-  "symbols.1", "symbol_def", "symbol_defs.1", "grammar", 
-  "rules_or_grammar_declaration", "rules", "@5", "rhses.1", "rhs", 
-  "symbol", "action", "string_as_id", "string_content", "epilogue.opt", 
-  "semi_colon.opt", 0
+  "\"%nonassoc\"", "\"%expect\"", "\"%start\"", "\"%prec\"", "\"%dprec\"", 
+  "\"%merge\"", "\"%verbose\"", "\"%error-verbose\"", "\"%output\"", 
+  "\"%file-prefix\"", "\"%name-prefix\"", "\"%define\"", 
+  "\"%pure-parser\"", "\"%glr-parser\"", "\"%defines\"", "\"%yacc\"", 
+  "\"%debug\"", "\"%locations\"", "\"%no-lines\"", "\"%skeleton\"", 
+  "\"%token-table\"", "TYPE", "\"=\"", "\";\"", "\":\"", "\"|\"", 
+  "\"identifier\"", "\"%%\"", "PROLOGUE", "EPILOGUE", "BRACED_CODE", 
+  "$axiom", "input", "declarations", "declaration", "grammar_declaration", 
+  "@1", "@2", "symbol_declaration", "@3", "@4", "precedence_declaration", 
+  "precedence_declarator", "type.opt", "symbols.1", "symbol_def", 
+  "symbol_defs.1", "grammar", "rules_or_grammar_declaration", "rules", 
+  "@5", "rhses.1", "rhs", "symbol", "action", "string_as_id", 
+  "string_content", "epilogue.opt", "semi_colon.opt", 0
 };
 #endif
 
@@ -484,33 +491,33 @@ static const short yytoknum[] =
      265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
      275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
      285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
-     295,   296,    -1
+     295,   296,   297,   298,   299,    -1
 };
 
 /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
 static const unsigned char yyr1[] =
 {
-       0,    42,    43,    44,    44,    45,    45,    45,    45,    45,
-      45,    45,    45,    45,    45,    45,    45,    45,    45,    45,
-      45,    45,    46,    46,    46,    46,    47,    46,    48,    46,
-      50,    49,    51,    49,    49,    52,    53,    53,    53,    54,
-      54,    55,    55,    56,    56,    56,    56,    56,    57,    57,
-      58,    58,    59,    59,    61,    60,    62,    62,    63,    63,
-      63,    63,    64,    64,    64,    65,    66,    67,    68,    68,
-      69,    69
+       0,    45,    46,    47,    47,    48,    48,    48,    48,    48,
+      48,    48,    48,    48,    48,    48,    48,    48,    48,    48,
+      48,    48,    48,    49,    49,    49,    49,    50,    49,    51,
+      49,    53,    52,    54,    52,    52,    55,    56,    56,    56,
+      57,    57,    58,    58,    59,    59,    59,    59,    59,    60,
+      60,    61,    61,    62,    62,    64,    63,    65,    65,    66,
+      66,    66,    66,    66,    66,    67,    67,    67,    68,    69,
+      70,    71,    71,    72,    72
 };
 
 /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
 static const unsigned char yyr2[] =
 {
        0,     2,     4,     0,     3,     1,     1,     1,     3,     1,
-       1,     2,     3,     1,     3,     1,     3,     1,     2,     1,
-       1,     1,     1,     1,     2,     2,     0,     4,     0,     4,
-       0,     3,     0,     3,     3,     3,     1,     1,     1,     0,
-       1,     1,     2,     1,     1,     2,     2,     3,     1,     2,
-       1,     2,     1,     2,     0,     5,     1,     3,     0,     2,
-       2,     3,     1,     1,     1,     1,     1,     1,     0,     2,
-       0,     1
+       1,     2,     3,     1,     3,     1,     3,     1,     1,     2,
+       1,     1,     1,     1,     1,     2,     2,     0,     4,     0,
+       4,     0,     3,     0,     3,     3,     3,     1,     1,     1,
+       0,     1,     1,     2,     1,     1,     2,     2,     3,     1,
+       2,     1,     2,     1,     2,     0,     5,     1,     3,     0,
+       2,     2,     3,     3,     3,     1,     1,     1,     1,     1,
+       1,     0,     2,     0,     1
 };
 
 /* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
@@ -518,50 +525,50 @@ static const unsigned char yyr2[] =
    means the default is an error.  */
 static const short yydefact[] =
 {
-       3,     0,     0,     0,    32,    30,     0,    26,    28,     0,
-      36,    37,    38,     0,     0,    20,    10,     0,     0,     0,
-       0,    17,     9,    21,     7,    13,    15,     0,    19,     0,
-       6,    70,     5,    23,    22,    39,     0,     0,     0,     0,
-       0,    25,    11,    66,    64,    62,    24,    63,     0,     0,
-       0,    67,     0,    18,     0,     0,    68,    50,    52,    71,
-       4,    40,     0,    43,    44,    48,    33,    31,    34,    41,
-       0,     0,    16,    12,    14,     8,    54,    53,     0,    51,
-       2,    35,    45,    46,    49,    42,    27,    29,    58,    69,
-      47,     0,    56,    55,    58,     0,    65,    59,    60,    57,
-      61
+       3,     0,     0,     0,    33,    31,     0,    27,    29,     0,
+      37,    38,    39,     0,     0,    21,    10,     0,     0,     0,
+       0,    17,    18,     9,    22,     7,    13,    15,     0,    20,
+       0,     6,    73,     5,    24,    23,    40,     0,     0,     0,
+       0,     0,    26,    11,    69,    67,    65,    25,    66,     0,
+       0,     0,    70,     0,    19,     0,     0,    71,    51,    53,
+      74,     4,    41,     0,    44,    45,    49,    34,    32,    35,
+      42,     0,     0,    16,    12,    14,     8,    55,    54,     0,
+      52,     2,    36,    46,    47,    50,    43,    28,    30,    59,
+      72,    48,     0,    57,    56,    59,     0,     0,     0,    68,
+      60,    61,    58,    62,    63,    64
 };
 
 /* YYPGOTO[NTERM-NUM]. */
 static const short yydefgoto[] =
 {
-      -1,     1,     2,    31,    55,    39,    40,    33,    37,    36,
-      34,    35,    62,    68,    65,    66,    56,    57,    58,    88,
-      91,    92,    69,    98,    47,    52,    80,    60
+      -1,     1,     2,    32,    56,    40,    41,    34,    38,    37,
+      35,    36,    63,    69,    66,    67,    57,    58,    59,    89,
+      92,    93,    70,   101,    48,    53,    81,    61
 };
 
 /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
    STATE-NUM.  */
 static const short yypact[] =
 {
-  -32768,     8,    80,-32768,-32768,-32768,   -19,-32768,-32768,   -11,
-  -32768,-32768,-32768,    31,     0,-32768,-32768,     5,     9,    11,
-      40,-32768,-32768,-32768,-32768,-32768,-32768,    40,-32768,   114,
-  -32768,    12,-32768,-32768,-32768,    13,   -27,   -27,     0,    14,
-      15,-32768,-32768,-32768,-32768,-32768,-32768,-32768,    40,    40,
-      40,-32768,    40,-32768,    16,    18,    10,-32768,-32768,-32768,
-  -32768,-32768,     0,-32768,     6,-32768,   -27,   -27,     0,-32768,
-       0,     0,-32768,-32768,-32768,-32768,-32768,-32768,    17,-32768,
-  -32768,     0,    46,-32768,-32768,-32768,     0,     0,-32768,-32768,
-  -32768,   -22,    -2,-32768,-32768,     0,-32768,-32768,-32768,    -2,
-  -32768
+  -32768,     7,    83,-32768,-32768,-32768,   -23,-32768,-32768,     3,
+  -32768,-32768,-32768,    43,     0,-32768,-32768,    13,    14,    15,
+      51,-32768,-32768,-32768,-32768,-32768,-32768,-32768,    51,-32768,
+      23,-32768,    19,-32768,-32768,-32768,    22,   -29,   -29,     0,
+      17,    18,-32768,-32768,-32768,-32768,-32768,-32768,-32768,    51,
+      51,    51,-32768,    51,-32768,    20,    27,    12,-32768,-32768,
+  -32768,-32768,-32768,     0,-32768,     5,-32768,   -29,   -29,     0,
+  -32768,     0,     0,-32768,-32768,-32768,-32768,-32768,-32768,    28,
+  -32768,-32768,     0,    56,-32768,-32768,-32768,     0,     0,-32768,
+  -32768,-32768,     4,    -2,-32768,-32768,     0,    55,    35,-32768,
+  -32768,-32768,    -2,-32768,-32768,-32768
 };
 
 /* YYPGOTO[NTERM-NUM].  */
 static const short yypgoto[] =
 {
-  -32768,-32768,-32768,-32768,    48,-32768,-32768,-32768,-32768,-32768,
-  -32768,-32768,-32768,   -30,   -33,    21,-32768,    -3,-32768,-32768,
-  -32768,   -35,   -14,-32768,   -57,   -21,-32768,-32768
+  -32768,-32768,-32768,-32768,    70,-32768,-32768,-32768,-32768,-32768,
+  -32768,-32768,-32768,   -58,   -22,    37,-32768,    21,-32768,-32768,
+  -32768,   -19,   -14,-32768,   -56,    16,-32768,-32768
 };
 
 /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
@@ -569,59 +576,53 @@ static const short yypgoto[] =
    number is the opposite.  If zero, do what YYDEFACT says.  */
 static const short yytable[] =
 {
-      46,    43,    44,    43,    44,    63,    53,    83,     3,    43,
-      64,    82,    93,    38,    94,    95,     4,     5,     6,     7,
-       8,     9,    10,    11,    12,    90,    14,    72,    73,    74,
-      41,    75,    81,    84,    84,    45,    42,    45,    48,    96,
-      86,    87,    49,    51,    50,    61,    59,    54,    78,    43,
-      32,    76,    77,    79,    85,    70,    71,    89,    67,    99,
-       0,     0,     0,     0,     0,     0,     0,    85,     0,     0,
-       0,     0,    85,    85,     0,     0,     0,     0,    97,     0,
-       0,   100,     0,     0,     0,    97,     4,     5,     6,     7,
-       8,     9,    10,    11,    12,    13,    14,     0,    15,    16,
-      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
-      27,    28,     0,     0,     0,     0,     0,     0,    29,    30,
-       4,     5,     6,     7,     8,     9,    10,    11,    12,     0,
-      14,     0,     0,     0,     0,     0,     0,     0,     0,     0,
-       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
-       0,    54
+      47,    44,    45,    44,    45,    82,    64,     3,    44,    84,
+      83,    65,    39,    87,    88,    96,    97,    98,     4,     5,
+       6,     7,     8,     9,    10,    11,    12,    91,    14,     4,
+       5,     6,     7,     8,     9,    10,    11,    12,    46,    14,
+      46,    94,    99,    95,    54,    85,    85,    42,    43,    49,
+      50,    51,    55,    79,    52,    86,    60,    62,    77,    44,
+     104,    71,    72,    55,    78,    73,    74,    75,    86,    76,
+     105,    90,    33,    86,    86,    68,   102,     0,    80,   100,
+       0,     0,   103,     0,     0,     0,     0,     0,   100,     4,
+       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
+       0,     0,     0,    15,    16,    17,    18,    19,    20,    21,
+      22,    23,    24,    25,    26,    27,    28,    29,     0,     0,
+       0,     0,     0,     0,    30,    31
 };
 
 static const short yycheck[] =
 {
-      14,     3,     4,     3,     4,    32,    27,    64,     0,     3,
-      37,     5,    34,    32,    36,    17,     6,     7,     8,     9,
-      10,    11,    12,    13,    14,    82,    16,    48,    49,    50,
-      41,    52,    62,    66,    67,    37,     5,    37,    33,    41,
-      70,    71,    33,     3,    33,    32,    34,    37,    38,     3,
-       2,    35,    34,    56,    68,    41,    41,    40,    37,    94,
-      -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,    -1,    -1,
-      -1,    -1,    86,    87,    -1,    -1,    -1,    -1,    92,    -1,
-      -1,    95,    -1,    -1,    -1,    99,     6,     7,     8,     9,
-      10,    11,    12,    13,    14,    15,    16,    -1,    18,    19,
-      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
-      30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    38,    39,
-       6,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
-      16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
-      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
-      -1,    37
+      14,     3,     4,     3,     4,    63,    35,     0,     3,    65,
+       5,    40,    35,    71,    72,    17,    18,    19,     6,     7,
+       8,     9,    10,    11,    12,    13,    14,    83,    16,     6,
+       7,     8,     9,    10,    11,    12,    13,    14,    40,    16,
+      40,    37,    44,    39,    28,    67,    68,    44,     5,    36,
+      36,    36,    40,    41,     3,    69,    37,    35,    38,     3,
+       5,    44,    44,    40,    37,    49,    50,    51,    82,    53,
+      35,    43,     2,    87,    88,    38,    95,    -1,    57,    93,
+      -1,    -1,    96,    -1,    -1,    -1,    -1,    -1,   102,     6,
+       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
+      -1,    -1,    -1,    20,    21,    22,    23,    24,    25,    26,
+      27,    28,    29,    30,    31,    32,    33,    34,    -1,    -1,
+      -1,    -1,    -1,    -1,    41,    42
 };
 
 /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
    symbol of state STATE-NUM.  */
 static const unsigned char yystos[] =
 {
-       0,    43,    44,     0,     6,     7,     8,     9,    10,    11,
-      12,    13,    14,    15,    16,    18,    19,    20,    21,    22,
-      23,    24,    25,    26,    27,    28,    29,    30,    31,    38,
-      39,    45,    46,    49,    52,    53,    51,    50,    32,    47,
-      48,    41,     5,     3,     4,    37,    64,    66,    33,    33,
-      33,     3,    67,    67,    37,    46,    58,    59,    60,    34,
-      69,    32,    54,    32,    37,    56,    57,    57,    55,    64,
-      41,    41,    67,    67,    67,    67,    35,    34,    38,    59,
-      68,    55,     5,    66,    56,    64,    55,    55,    61,    40,
-      66,    62,    63,    34,    36,    17,    41,    64,    65,    63,
-      64
+       0,    46,    47,     0,     6,     7,     8,     9,    10,    11,
+      12,    13,    14,    15,    16,    20,    21,    22,    23,    24,
+      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
+      41,    42,    48,    49,    52,    55,    56,    54,    53,    35,
+      50,    51,    44,     5,     3,     4,    40,    67,    69,    36,
+      36,    36,     3,    70,    70,    40,    49,    61,    62,    63,
+      37,    72,    35,    57,    35,    40,    59,    60,    60,    58,
+      67,    44,    44,    70,    70,    70,    70,    38,    37,    41,
+      62,    71,    58,     5,    69,    59,    67,    58,    58,    64,
+      43,    69,    65,    66,    37,    39,    17,    18,    19,    44,
+      67,    68,    66,    67,     5,    35
 };
 
 #if ! defined (YYSIZE_T) && defined (__SIZE_TYPE__)
@@ -828,8 +829,8 @@ int yyparse (void);
 #endif
 
 #if defined (__STDC__) || defined (__cplusplus)
-static void yydestructor (int yytype,
-			  YYSTYPE yyvalue, YYLTYPE yylocation);
+static void yydestruct (int yytype,
+			YYSTYPE yyvalue, YYLTYPE yylocation);
 # if YYDEBUG
 static void yysymprint (FILE* out, int yytype,
 			YYSTYPE yyvalue, YYLTYPE yylocation);
@@ -1137,7 +1138,7 @@ yyreduce:
   switch (yyn)
     {
         case 2:
-#line 157 "parse-gram.y"
+#line 160 "parse-gram.y"
     {
       yycontrol->errcode = 0;
       epilogue_set (yyvsp[0].string, yylsp[0]);
@@ -1145,94 +1146,99 @@ yyreduce:
     break;
 
   case 6:
-#line 175 "parse-gram.y"
+#line 178 "parse-gram.y"
     { prologue_augment (yyvsp[0].string, yylsp[0]); }
     break;
 
   case 7:
-#line 176 "parse-gram.y"
+#line 179 "parse-gram.y"
     { debug_flag = 1; }
     break;
 
   case 8:
-#line 177 "parse-gram.y"
+#line 180 "parse-gram.y"
     { muscle_insert (yyvsp[-1].string, yyvsp[0].string); }
     break;
 
   case 9:
-#line 178 "parse-gram.y"
+#line 181 "parse-gram.y"
     { defines_flag = 1; }
     break;
 
   case 10:
-#line 179 "parse-gram.y"
+#line 182 "parse-gram.y"
     { error_verbose = 1; }
     break;
 
   case 11:
-#line 180 "parse-gram.y"
+#line 183 "parse-gram.y"
     { expected_conflicts = yyvsp[0].integer; }
     break;
 
   case 12:
-#line 181 "parse-gram.y"
+#line 184 "parse-gram.y"
     { spec_file_prefix = yyvsp[0].string; }
     break;
 
   case 13:
-#line 182 "parse-gram.y"
+#line 185 "parse-gram.y"
     { locations_flag = 1; }
     break;
 
   case 14:
-#line 183 "parse-gram.y"
+#line 186 "parse-gram.y"
     { spec_name_prefix = yyvsp[0].string; }
     break;
 
   case 15:
-#line 184 "parse-gram.y"
+#line 187 "parse-gram.y"
     { no_lines_flag = 1; }
     break;
 
   case 16:
-#line 185 "parse-gram.y"
+#line 188 "parse-gram.y"
     { spec_outfile = yyvsp[0].string; }
     break;
 
   case 17:
-#line 186 "parse-gram.y"
+#line 189 "parse-gram.y"
     { pure_parser = 1; }
     break;
 
   case 18:
-#line 187 "parse-gram.y"
-    { skeleton = yyvsp[0].string; }
+#line 190 "parse-gram.y"
+    { glr_parser = 1; }
     break;
 
   case 19:
-#line 188 "parse-gram.y"
-    { token_table_flag = 1; }
+#line 191 "parse-gram.y"
+    { skeleton = yyvsp[0].string; }
     break;
 
   case 20:
-#line 189 "parse-gram.y"
-    { report_flag = 1; }
+#line 192 "parse-gram.y"
+    { token_table_flag = 1; }
     break;
 
   case 21:
-#line 190 "parse-gram.y"
+#line 193 "parse-gram.y"
+    { report_flag = 1; }
+    break;
+
+  case 22:
+#line 194 "parse-gram.y"
     { yacc_flag = 1; }
     break;
 
-  case 24:
-#line 197 "parse-gram.y"
+  case 25:
+#line 201 "parse-gram.y"
     {
       grammar_start_symbol_set (yyvsp[0].symbol, yylsp[0]);
     }
     break;
 
-  case 25:
-#line 201 "parse-gram.y"
+  case 26:
+#line 205 "parse-gram.y"
     {
       typed = 1;
       MUSCLE_INSERT_INT ("stype_line", yylsp[0].first_line);
@@ -1240,13 +1246,13 @@ yyreduce:
     }
     break;
 
-  case 26:
-#line 207 "parse-gram.y"
+  case 27:
+#line 211 "parse-gram.y"
     { current_braced_code = destructor_braced_code; }
     break;
 
-  case 27:
-#line 209 "parse-gram.y"
+  case 28:
+#line 213 "parse-gram.y"
     {
       symbol_list_t *list;
       for (list = yyvsp[0].list; list; list = list->next)
@@ -1256,13 +1262,13 @@ yyreduce:
     }
     break;
 
-  case 28:
-#line 217 "parse-gram.y"
+  case 29:
+#line 221 "parse-gram.y"
     { current_braced_code = printer_braced_code; }
     break;
 
-  case 29:
-#line 219 "parse-gram.y"
+  case 30:
+#line 223 "parse-gram.y"
     {
       symbol_list_t *list;
       for (list = yyvsp[0].list; list; list = list->next)
@@ -1272,34 +1278,34 @@ yyreduce:
     }
     break;
 
-  case 30:
-#line 229 "parse-gram.y"
+  case 31:
+#line 233 "parse-gram.y"
     { current_class = nterm_sym; }
     break;
 
-  case 31:
-#line 230 "parse-gram.y"
+  case 32:
+#line 234 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
     break;
 
-  case 32:
-#line 234 "parse-gram.y"
+  case 33:
+#line 238 "parse-gram.y"
     { current_class = token_sym; }
     break;
 
-  case 33:
-#line 235 "parse-gram.y"
+  case 34:
+#line 239 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
     break;
 
-  case 34:
-#line 240 "parse-gram.y"
+  case 35:
+#line 244 "parse-gram.y"
     {
       symbol_list_t *list;
       for (list = yyvsp[0].list; list; list = list->next)
@@ -1308,8 +1314,8 @@ yyreduce:
     }
     break;
 
-  case 35:
-#line 250 "parse-gram.y"
+  case 36:
+#line 254 "parse-gram.y"
     {
       symbol_list_t *list;
       ++current_prec;
@@ -1323,58 +1329,58 @@ yyreduce:
     }
     break;
 
-  case 36:
-#line 264 "parse-gram.y"
+  case 37:
+#line 268 "parse-gram.y"
     { yyval.assoc = left_assoc; }
     break;
 
-  case 37:
-#line 265 "parse-gram.y"
+  case 38:
+#line 269 "parse-gram.y"
     { yyval.assoc = right_assoc; }
     break;
 
-  case 38:
-#line 266 "parse-gram.y"
+  case 39:
+#line 270 "parse-gram.y"
     { yyval.assoc = non_assoc; }
     break;
 
-  case 39:
-#line 270 "parse-gram.y"
+  case 40:
+#line 274 "parse-gram.y"
     { current_type = NULL;}
     break;
 
-  case 40:
-#line 271 "parse-gram.y"
+  case 41:
+#line 275 "parse-gram.y"
     { current_type = yyvsp[0].string; }
     break;
 
-  case 41:
-#line 277 "parse-gram.y"
+  case 42:
+#line 281 "parse-gram.y"
     { yyval.list = symbol_list_new (yyvsp[0].symbol, yylsp[0]); }
     break;
 
-  case 42:
-#line 278 "parse-gram.y"
+  case 43:
+#line 282 "parse-gram.y"
     { yyval.list = symbol_list_prepend (yyvsp[-1].list, yyvsp[0].symbol, yylsp[0]); }
     break;
 
-  case 43:
-#line 284 "parse-gram.y"
+  case 44:
+#line 288 "parse-gram.y"
     {
        current_type = yyvsp[0].string;
      }
     break;
 
-  case 44:
-#line 288 "parse-gram.y"
+  case 45:
+#line 292 "parse-gram.y"
     {
        symbol_class_set (yyvsp[0].symbol, current_class, yylsp[0]);
        symbol_type_set (yyvsp[0].symbol, current_type, yylsp[0]);
      }
     break;
 
-  case 45:
-#line 293 "parse-gram.y"
+  case 46:
+#line 297 "parse-gram.y"
     {
       symbol_class_set (yyvsp[-1].symbol, current_class, yylsp[-1]);
       symbol_type_set (yyvsp[-1].symbol, current_type, yylsp[-1]);
@@ -1382,8 +1388,8 @@ yyreduce:
     }
     break;
 
-  case 46:
-#line 299 "parse-gram.y"
+  case 47:
+#line 303 "parse-gram.y"
     {
       symbol_class_set (yyvsp[-1].symbol, current_class, yylsp[-1]);
       symbol_type_set (yyvsp[-1].symbol, current_type, yylsp[-1]);
@@ -1391,8 +1397,8 @@ yyreduce:
     }
     break;
 
-  case 47:
-#line 305 "parse-gram.y"
+  case 48:
+#line 309 "parse-gram.y"
     {
       symbol_class_set (yyvsp[-2].symbol, current_class, yylsp[-2]);
       symbol_type_set (yyvsp[-2].symbol, current_type, yylsp[-2]);
@@ -1401,101 +1407,111 @@ yyreduce:
     }
     break;
 
-  case 48:
-#line 316 "parse-gram.y"
-    {;}
-    break;
-
   case 49:
-#line 318 "parse-gram.y"
+#line 320 "parse-gram.y"
     {;}
     break;
 
-  case 54:
-#line 340 "parse-gram.y"
-    { current_lhs = yyvsp[-1].symbol; current_lhs_location = yylsp[-1]; }
+  case 50:
+#line 322 "parse-gram.y"
+    {;}
     break;
 
   case 55:
-#line 341 "parse-gram.y"
-    {;}
+#line 344 "parse-gram.y"
+    { current_lhs = yyvsp[-1].symbol; current_lhs_location = yylsp[-1]; }
     break;
 
   case 56:
 #line 345 "parse-gram.y"
-    { grammar_rule_end (yylsp[0]); }
+    {;}
     break;
 
   case 57:
-#line 346 "parse-gram.y"
+#line 349 "parse-gram.y"
     { grammar_rule_end (yylsp[0]); }
     break;
 
   case 58:
-#line 351 "parse-gram.y"
-    { grammar_rule_begin (current_lhs, current_lhs_location); }
+#line 350 "parse-gram.y"
+    { grammar_rule_end (yylsp[0]); }
     break;
 
   case 59:
-#line 353 "parse-gram.y"
-    { grammar_current_rule_symbol_append (yyvsp[0].symbol, yylsp[0]); }
+#line 355 "parse-gram.y"
+    { grammar_rule_begin (current_lhs, current_lhs_location); }
     break;
 
   case 60:
-#line 355 "parse-gram.y"
-    { grammar_current_rule_action_append (yyvsp[0].string, yylsp[0]); }
+#line 357 "parse-gram.y"
+    { grammar_current_rule_symbol_append (yyvsp[0].symbol, yylsp[0]); }
     break;
 
   case 61:
-#line 357 "parse-gram.y"
-    { grammar_current_rule_prec_set (yyvsp[0].symbol, yylsp[0]); }
+#line 359 "parse-gram.y"
+    { grammar_current_rule_action_append (yyvsp[0].string, yylsp[0]); }
     break;
 
   case 62:
 #line 361 "parse-gram.y"
-    { yyval.symbol = yyvsp[0].symbol; }
+    { grammar_current_rule_prec_set (yyvsp[0].symbol, yylsp[0]); }
     break;
 
   case 63:
-#line 362 "parse-gram.y"
-    { yyval.symbol = yyvsp[0].symbol; }
+#line 363 "parse-gram.y"
+    { grammar_current_rule_dprec_set (yyvsp[0].integer, yylsp[0]); }
     break;
 
   case 64:
-#line 363 "parse-gram.y"
-    { yyval.symbol = getsym (yyvsp[0].string, yylsp[0]); }
+#line 365 "parse-gram.y"
+    { grammar_current_rule_merge_set (yyvsp[0].string, yylsp[0]); }
     break;
 
   case 65:
-#line 368 "parse-gram.y"
-    { yyval.string = yyvsp[0].string; }
+#line 369 "parse-gram.y"
+    { yyval.symbol = yyvsp[0].symbol; }
     break;
 
   case 66:
-#line 374 "parse-gram.y"
+#line 370 "parse-gram.y"
+    { yyval.symbol = yyvsp[0].symbol; }
+    break;
+
+  case 67:
+#line 371 "parse-gram.y"
+    { yyval.symbol = getsym (yyvsp[0].string, yylsp[0]); }
+    break;
+
+  case 68:
+#line 376 "parse-gram.y"
+    { yyval.string = yyvsp[0].string; }
+    break;
+
+  case 69:
+#line 382 "parse-gram.y"
     {
       yyval.symbol = getsym (yyvsp[0].string, yylsp[0]);
       symbol_class_set (yyval.symbol, token_sym, yylsp[0]);
     }
     break;
 
-  case 67:
-#line 383 "parse-gram.y"
+  case 70:
+#line 391 "parse-gram.y"
     {
       yyval.string = yyvsp[0].string + 1;
       yyval.string[strlen (yyval.string) - 1] = '\0';
     }
     break;
 
-  case 68:
-#line 391 "parse-gram.y"
+  case 71:
+#line 399 "parse-gram.y"
     {
       yyval.string = xstrdup ("");
     }
     break;
 
-  case 69:
-#line 395 "parse-gram.y"
+  case 72:
+#line 403 "parse-gram.y"
     {
       yyval.string = yyvsp[0].string;
     }
@@ -1504,8 +1520,8 @@ yyreduce:
 
     }
 
-/* Line 1000 of /usr/local/share/bison/bison.simple.  */
-#line 1509 "parse-gram.c"
+/* Line 1040 of /home/cs/hilfingr/work/grammars/glr2/install/share/bison/yacc.c.  */
+#line 1525 "parse-gram.c"
 
   yyvsp -= yylen;
   yyssp -= yylen;
@@ -1622,7 +1638,7 @@ yyerrlab1:
 			    yystos[*yyssp],
 			    *yyvsp, *yylsp));
 	      YYDPRINTF ((stderr, "\n"));
-	      yydestructor (yystos[*yyssp], *yyvsp, *yylsp);
+	      yydestruct (yystos[*yyssp], *yyvsp, *yylsp);
 	      YYPOPSTACK;
 	    }
 	  YYABORT;
@@ -1630,7 +1646,7 @@ yyerrlab1:
 
       YYDPRINTF ((stderr, "Discarding token %d (%s).\n",
 		  yychar, yytname[yychar1]));
-      yydestructor (yychar1, yylval, yylloc);
+      yydestruct (yychar1, yylval, yylloc);
       yychar = YYEMPTY;
     }
 
@@ -1662,7 +1678,7 @@ yyerrlab1:
 		    yystos[*yyssp], *yyvsp, *yylsp));
       YYDPRINTF ((stderr, "\n"));
 
-      yydestructor (yystos[yystate], *yyvsp, *yylsp);
+      yydestruct (yystos[yystate], *yyvsp, *yylsp);
       yyvsp--;
       yystate = *--yyssp;
       yylsp--;
@@ -1729,8 +1745,8 @@ yyreturn:
 `-----------------------------------------------*/
 
 static void
-yydestructor (int yytype,
-	      YYSTYPE yyvalue, YYLTYPE yylocation)
+yydestruct (int yytype,
+	    YYSTYPE yyvalue, YYLTYPE yylocation)
 {
   switch (yytype)
     {
@@ -1750,23 +1766,25 @@ yysymprint (FILE* yyout, int yytype,
 	    YYSTYPE yyvalue, YYLTYPE yylocation)
 {
   if (yytype < YYNTOKENS)
-    YYFPRINTF (yyout, "token %s (", yytname[yytype]);
+    {
+      YYFPRINTF (yyout, "token %s (", yytname[yytype]);
+# ifdef YYPRINT
+      YYPRINT (yyout, yytoknum[yytype], yyvalue);
+# endif
+    }
   else
     YYFPRINTF (yyout, "nterm %s (", yytname[yytype]);
-# ifdef YYPRINT
-  YYPRINT (yyout, yytype, yyvalue);
-# else
+
   switch (yytype)
     {
       default:
         break;
     }
-# endif /* !defined YYPRINT. */
   YYFPRINTF (yyout, ")");
 }
 #endif /* YYDEBUG. */
 
-#line 404 "parse-gram.y"
+#line 412 "parse-gram.y"
 
 /*------------------------------------------------------------------.
 | When debugging the parser, display tokens' locations and values.  |
