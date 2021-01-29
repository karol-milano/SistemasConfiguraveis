@@ -116,6 +116,7 @@ symbol_t *current_lhs;
 location_t current_lhs_location;
 associativity current_assoc;
 int current_prec = 0;
+braced_code_t current_braced_code = action_braced_code;
 
 
 /* Tokens.  */
@@ -131,37 +132,38 @@ int current_prec = 0;
      PERCENT_TOKEN = 261,
      PERCENT_NTERM = 262,
      PERCENT_TYPE = 263,
-     PERCENT_UNION = 264,
-     PERCENT_LEFT = 265,
-     PERCENT_RIGHT = 266,
-     PERCENT_NONASSOC = 267,
-     PERCENT_EXPECT = 268,
-     PERCENT_START = 269,
-     PERCENT_PREC = 270,
-     PERCENT_VERBOSE = 271,
-     PERCENT_ERROR_VERBOSE = 272,
-     PERCENT_OUTPUT = 273,
-     PERCENT_FILE_PREFIX = 274,
-     PERCENT_NAME_PREFIX = 275,
-     PERCENT_DEFINE = 276,
-     PERCENT_PURE_PARSER = 277,
-     PERCENT_DEFINES = 278,
-     PERCENT_YACC = 279,
-     PERCENT_DEBUG = 280,
-     PERCENT_LOCATIONS = 281,
-     PERCENT_NO_LINES = 282,
-     PERCENT_SKELETON = 283,
-     PERCENT_TOKEN_TABLE = 284,
-     TYPE = 285,
-     EQUAL = 286,
-     SEMICOLON = 287,
-     COLON = 288,
-     PIPE = 289,
-     ID = 290,
-     PERCENT_PERCENT = 291,
-     PROLOGUE = 292,
-     EPILOGUE = 293,
-     BRACED_CODE = 294
+     PERCENT_DESTRUCTOR = 264,
+     PERCENT_UNION = 265,
+     PERCENT_LEFT = 266,
+     PERCENT_RIGHT = 267,
+     PERCENT_NONASSOC = 268,
+     PERCENT_EXPECT = 269,
+     PERCENT_START = 270,
+     PERCENT_PREC = 271,
+     PERCENT_VERBOSE = 272,
+     PERCENT_ERROR_VERBOSE = 273,
+     PERCENT_OUTPUT = 274,
+     PERCENT_FILE_PREFIX = 275,
+     PERCENT_NAME_PREFIX = 276,
+     PERCENT_DEFINE = 277,
+     PERCENT_PURE_PARSER = 278,
+     PERCENT_DEFINES = 279,
+     PERCENT_YACC = 280,
+     PERCENT_DEBUG = 281,
+     PERCENT_LOCATIONS = 282,
+     PERCENT_NO_LINES = 283,
+     PERCENT_SKELETON = 284,
+     PERCENT_TOKEN_TABLE = 285,
+     TYPE = 286,
+     EQUAL = 287,
+     SEMICOLON = 288,
+     COLON = 289,
+     PIPE = 290,
+     ID = 291,
+     PERCENT_PERCENT = 292,
+     PROLOGUE = 293,
+     EPILOGUE = 294,
+     BRACED_CODE = 295
    };
 # endif
   /* POSIX requires `int' for tokens in interfaces.  */
@@ -174,37 +176,38 @@ int current_prec = 0;
 #define PERCENT_TOKEN 261
 #define PERCENT_NTERM 262
 #define PERCENT_TYPE 263
-#define PERCENT_UNION 264
-#define PERCENT_LEFT 265
-#define PERCENT_RIGHT 266
-#define PERCENT_NONASSOC 267
-#define PERCENT_EXPECT 268
-#define PERCENT_START 269
-#define PERCENT_PREC 270
-#define PERCENT_VERBOSE 271
-#define PERCENT_ERROR_VERBOSE 272
-#define PERCENT_OUTPUT 273
-#define PERCENT_FILE_PREFIX 274
-#define PERCENT_NAME_PREFIX 275
-#define PERCENT_DEFINE 276
-#define PERCENT_PURE_PARSER 277
-#define PERCENT_DEFINES 278
-#define PERCENT_YACC 279
-#define PERCENT_DEBUG 280
-#define PERCENT_LOCATIONS 281
-#define PERCENT_NO_LINES 282
-#define PERCENT_SKELETON 283
-#define PERCENT_TOKEN_TABLE 284
-#define TYPE 285
-#define EQUAL 286
-#define SEMICOLON 287
-#define COLON 288
-#define PIPE 289
-#define ID 290
-#define PERCENT_PERCENT 291
-#define PROLOGUE 292
-#define EPILOGUE 293
-#define BRACED_CODE 294
+#define PERCENT_DESTRUCTOR 264
+#define PERCENT_UNION 265
+#define PERCENT_LEFT 266
+#define PERCENT_RIGHT 267
+#define PERCENT_NONASSOC 268
+#define PERCENT_EXPECT 269
+#define PERCENT_START 270
+#define PERCENT_PREC 271
+#define PERCENT_VERBOSE 272
+#define PERCENT_ERROR_VERBOSE 273
+#define PERCENT_OUTPUT 274
+#define PERCENT_FILE_PREFIX 275
+#define PERCENT_NAME_PREFIX 276
+#define PERCENT_DEFINE 277
+#define PERCENT_PURE_PARSER 278
+#define PERCENT_DEFINES 279
+#define PERCENT_YACC 280
+#define PERCENT_DEBUG 281
+#define PERCENT_LOCATIONS 282
+#define PERCENT_NO_LINES 283
+#define PERCENT_SKELETON 284
+#define PERCENT_TOKEN_TABLE 285
+#define TYPE 286
+#define EQUAL 287
+#define SEMICOLON 288
+#define COLON 289
+#define PIPE 290
+#define ID 291
+#define PERCENT_PERCENT 292
+#define PROLOGUE 293
+#define EPILOGUE 294
+#define BRACED_CODE 295
 
 
 
@@ -223,7 +226,7 @@ int current_prec = 0;
 #endif
 
 #ifndef YYSTYPE
-#line 90 "parse-gram.y"
+#line 91 "parse-gram.y"
 typedef union {
   symbol_t *symbol;
   symbol_list_t *list;
@@ -232,7 +235,7 @@ typedef union {
   associativity assoc;
 } yystype;
 /* Line 199 of /usr/local/share/bison/bison.simple.  */
-#line 236 "parse-gram.c"
+#line 239 "parse-gram.c"
 # define YYSTYPE yystype
 # define YYSTYPE_IS_TRIVIAL 1
 #endif
@@ -253,7 +256,7 @@ typedef struct yyltype
 
 
 /* Line 219 of /usr/local/share/bison/bison.simple.  */
-#line 257 "parse-gram.c"
+#line 260 "parse-gram.c"
 
 #if ! defined (yyoverflow) || YYERROR_VERBOSE
 
@@ -355,20 +358,20 @@ union yyalloc
 /* YYFINAL -- State number of the termination state. */
 #define YYFINAL  3
 #define YYFLAG	 -32768
-#define YYLAST   111
+#define YYLAST   115
 
 /* YYNTOKENS -- Number of terminals. */
-#define YYNTOKENS  40
+#define YYNTOKENS  41
 /* YYNNTS -- Number of nonterminals. */
-#define YYNNTS  26
+#define YYNNTS  27
 /* YYNRULES -- Number of rules. */
-#define YYNRULES  67
+#define YYNRULES  69
 /* YYNRULES -- Number of states. */
-#define YYNSTATES  93
+#define YYNSTATES  97
 
 /* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
 #define YYUNDEFTOK  2
-#define YYMAXUTOK   294
+#define YYMAXUTOK   295
 
 #define YYTRANSLATE(X) \
   ((unsigned)(X) <= YYMAXUTOK ? yytranslate[X] : YYUNDEFTOK)
@@ -405,7 +408,7 @@ static const unsigned char yytranslate[] =
        5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
       15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
       25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
-      35,    36,    37,    38,    39
+      35,    36,    37,    38,    39,    40
 };
 
 #if YYDEBUG
@@ -415,46 +418,46 @@ static const unsigned char yyprhs[] =
 {
        0,     0,     3,     8,     9,    13,    15,    17,    19,    23,
       25,    27,    30,    34,    36,    40,    42,    46,    48,    51,
-      53,    55,    57,    59,    61,    64,    67,    68,    72,    73,
-      77,    81,    85,    87,    89,    91,    92,    94,    96,    99,
-     101,   103,   106,   109,   113,   115,   118,   120,   123,   125,
-     128,   129,   135,   137,   141,   142,   145,   148,   152,   154,
-     156,   158,   160,   162,   164,   165,   168,   169
+      53,    55,    57,    59,    61,    64,    67,    68,    73,    74,
+      78,    79,    83,    87,    91,    93,    95,    97,    98,   100,
+     102,   105,   107,   109,   112,   115,   119,   121,   124,   126,
+     129,   131,   134,   135,   141,   143,   147,   148,   151,   154,
+     158,   160,   162,   164,   166,   168,   170,   171,   174,   175
 };
 
 /* YYRHS -- A `-1'-separated list of the rules' RHS. */
 static const signed char yyrhs[] =
 {
-      41,     0,    -1,    42,    36,    54,    64,    -1,    -1,    42,
-      43,    65,    -1,    44,    -1,    37,    -1,    25,    -1,    21,
-      63,    63,    -1,    23,    -1,    17,    -1,    13,     5,    -1,
-      19,    31,    63,    -1,    26,    -1,    20,    31,    63,    -1,
-      27,    -1,    18,    31,    63,    -1,    22,    -1,    28,    63,
-      -1,    29,    -1,    16,    -1,    24,    -1,    48,    -1,    45,
-      -1,    14,    60,    -1,     9,    39,    -1,    -1,     7,    46,
-      53,    -1,    -1,     6,    47,    53,    -1,     8,    30,    51,
-      -1,    49,    50,    51,    -1,    10,    -1,    11,    -1,    12,
-      -1,    -1,    30,    -1,    60,    -1,    51,    60,    -1,    30,
-      -1,    35,    -1,    35,     5,    -1,    35,    62,    -1,    35,
-       5,    62,    -1,    52,    -1,    53,    52,    -1,    55,    -1,
-      54,    55,    -1,    56,    -1,    44,    32,    -1,    -1,    35,
-      33,    57,    58,    32,    -1,    59,    -1,    58,    34,    59,
-      -1,    -1,    59,    60,    -1,    59,    61,    -1,    59,    15,
-      60,    -1,    35,    -1,    62,    -1,     4,    -1,    39,    -1,
-       3,    -1,     3,    -1,    -1,    36,    38,    -1,    -1,    32,
-      -1
+      42,     0,    -1,    43,    37,    56,    66,    -1,    -1,    43,
+      44,    67,    -1,    45,    -1,    38,    -1,    26,    -1,    22,
+      65,    65,    -1,    24,    -1,    18,    -1,    14,     5,    -1,
+      20,    32,    65,    -1,    27,    -1,    21,    32,    65,    -1,
+      28,    -1,    19,    32,    65,    -1,    23,    -1,    29,    65,
+      -1,    30,    -1,    17,    -1,    25,    -1,    50,    -1,    47,
+      -1,    15,    62,    -1,    10,    40,    -1,    -1,     9,    46,
+      40,    53,    -1,    -1,     7,    48,    55,    -1,    -1,     6,
+      49,    55,    -1,     8,    31,    53,    -1,    51,    52,    53,
+      -1,    11,    -1,    12,    -1,    13,    -1,    -1,    31,    -1,
+      62,    -1,    53,    62,    -1,    31,    -1,    36,    -1,    36,
+       5,    -1,    36,    64,    -1,    36,     5,    64,    -1,    54,
+      -1,    55,    54,    -1,    57,    -1,    56,    57,    -1,    58,
+      -1,    45,    33,    -1,    -1,    36,    34,    59,    60,    33,
+      -1,    61,    -1,    60,    35,    61,    -1,    -1,    61,    62,
+      -1,    61,    63,    -1,    61,    16,    62,    -1,    36,    -1,
+      64,    -1,     4,    -1,    40,    -1,     3,    -1,     3,    -1,
+      -1,    37,    39,    -1,    -1,    33,    -1
 };
 
 /* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
 static const unsigned short yyrline[] =
 {
-       0,   152,   152,   165,   167,   170,   172,   173,   174,   175,
-     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
-     186,   187,   190,   192,   193,   197,   205,   205,   211,   211,
-     216,   225,   240,   242,   243,   246,   248,   253,   255,   259,
-     264,   269,   275,   281,   291,   294,   303,   305,   311,   313,
-     316,   316,   321,   323,   326,   329,   331,   333,   337,   339,
-     340,   343,   349,   358,   366,   371,   377,   379
+       0,   154,   154,   167,   169,   172,   174,   175,   176,   177,
+     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
+     188,   189,   192,   194,   195,   199,   205,   205,   217,   217,
+     223,   223,   228,   237,   252,   254,   255,   258,   260,   265,
+     267,   271,   276,   281,   287,   293,   303,   306,   315,   317,
+     323,   325,   328,   328,   333,   335,   338,   341,   343,   345,
+     349,   351,   352,   355,   361,   370,   378,   383,   389,   391
 };
 #endif
 
@@ -464,20 +467,20 @@ static const unsigned short yyrline[] =
 static const char *const yytname[] =
 {
   "\"end of string\"", "error", "$undefined.", "STRING", "CHARACTER", "INT", 
-  "\"%token\"", "\"%nterm\"", "\"%type\"", "\"%union\"", "\"%left\"", 
-  "\"%right\"", "\"%nonassoc\"", "\"%expect\"", "\"%start\"", "\"%prec\"", 
-  "\"%verbose\"", "\"%error-verbose\"", "\"%output\"", "\"%file-prefix\"", 
-  "\"%name-prefix\"", "\"%define\"", "\"%pure-parser\"", "\"%defines\"", 
-  "\"%yacc\"", "\"%debug\"", "\"%locations\"", "\"%no-lines\"", 
-  "\"%skeleton\"", "\"%token-table\"", "TYPE", "\"=\"", "\";\"", "\":\"", 
-  "\"|\"", "\"identifier\"", "\"%%\"", "PROLOGUE", "EPILOGUE", 
-  "BRACED_CODE", "$axiom", "input", "declarations", "declaration", 
-  "grammar_declaration", "symbol_declaration", "@1", "@2", 
-  "precedence_declaration", "precedence_declarator", "type.opt", 
-  "symbols.1", "symbol_def", "symbol_defs.1", "grammar", 
-  "rules_or_grammar_declaration", "rules", "@3", "rhses.1", "rhs", 
-  "symbol", "action", "string_as_id", "string_content", "epilogue.opt", 
-  "semi_colon.opt", 0
+  "\"%token\"", "\"%nterm\"", "\"%type\"", "\"%destructor\"", 
+  "\"%union\"", "\"%left\"", "\"%right\"", "\"%nonassoc\"", "\"%expect\"", 
+  "\"%start\"", "\"%prec\"", "\"%verbose\"", "\"%error-verbose\"", 
+  "\"%output\"", "\"%file-prefix\"", "\"%name-prefix\"", "\"%define\"", 
+  "\"%pure-parser\"", "\"%defines\"", "\"%yacc\"", "\"%debug\"", 
+  "\"%locations\"", "\"%no-lines\"", "\"%skeleton\"", "\"%token-table\"", 
+  "TYPE", "\"=\"", "\";\"", "\":\"", "\"|\"", "\"identifier\"", "\"%%\"", 
+  "PROLOGUE", "EPILOGUE", "BRACED_CODE", "$axiom", "input", 
+  "declarations", "declaration", "grammar_declaration", "@1", 
+  "symbol_declaration", "@2", "@3", "precedence_declaration", 
+  "precedence_declarator", "type.opt", "symbols.1", "symbol_def", 
+  "symbol_defs.1", "grammar", "rules_or_grammar_declaration", "rules", 
+  "@4", "rhses.1", "rhs", "symbol", "action", "string_as_id", 
+  "string_content", "epilogue.opt", "semi_colon.opt", 0
 };
 #endif
 
@@ -489,19 +492,19 @@ static const short yytoknum[] =
      265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
      275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
      285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
-      -1
+     295,    -1
 };
 
 /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
 static const unsigned char yyr1[] =
 {
-       0,    40,    41,    42,    42,    43,    43,    43,    43,    43,
-      43,    43,    43,    43,    43,    43,    43,    43,    43,    43,
-      43,    43,    44,    44,    44,    44,    46,    45,    47,    45,
-      45,    48,    49,    49,    49,    50,    50,    51,    51,    52,
-      52,    52,    52,    52,    53,    53,    54,    54,    55,    55,
-      57,    56,    58,    58,    59,    59,    59,    59,    60,    60,
-      60,    61,    62,    63,    64,    64,    65,    65
+       0,    41,    42,    43,    43,    44,    44,    44,    44,    44,
+      44,    44,    44,    44,    44,    44,    44,    44,    44,    44,
+      44,    44,    45,    45,    45,    45,    46,    45,    48,    47,
+      49,    47,    47,    50,    51,    51,    51,    52,    52,    53,
+      53,    54,    54,    54,    54,    54,    55,    55,    56,    56,
+      57,    57,    59,    58,    60,    60,    61,    61,    61,    61,
+      62,    62,    62,    63,    64,    65,    66,    66,    67,    67
 };
 
 /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
@@ -509,11 +512,11 @@ static const unsigned char yyr2[] =
 {
        0,     2,     4,     0,     3,     1,     1,     1,     3,     1,
        1,     2,     3,     1,     3,     1,     3,     1,     2,     1,
-       1,     1,     1,     1,     2,     2,     0,     3,     0,     3,
-       3,     3,     1,     1,     1,     0,     1,     1,     2,     1,
-       1,     2,     2,     3,     1,     2,     1,     2,     1,     2,
-       0,     5,     1,     3,     0,     2,     2,     3,     1,     1,
-       1,     1,     1,     1,     0,     2,     0,     1
+       1,     1,     1,     1,     2,     2,     0,     4,     0,     3,
+       0,     3,     3,     3,     1,     1,     1,     0,     1,     1,
+       2,     1,     1,     2,     2,     3,     1,     2,     1,     2,
+       1,     2,     0,     5,     1,     3,     0,     2,     2,     3,
+       1,     1,     1,     1,     1,     1,     0,     2,     0,     1
 };
 
 /* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
@@ -521,48 +524,48 @@ static const unsigned char yyr2[] =
    means the default is an error.  */
 static const short yydefact[] =
 {
-       3,     0,     0,     0,    28,    26,     0,     0,    32,    33,
-      34,     0,     0,    20,    10,     0,     0,     0,     0,    17,
-       9,    21,     7,    13,    15,     0,    19,     0,     6,    66,
-       5,    23,    22,    35,     0,     0,     0,    25,    11,    62,
-      60,    58,    24,    59,     0,     0,     0,    63,     0,    18,
-       0,     0,    64,    46,    48,    67,     4,    36,     0,    39,
-      40,    44,    29,    27,    30,    37,    16,    12,    14,     8,
-      50,    49,     0,    47,     2,    31,    41,    42,    45,    38,
-      54,    65,    43,     0,    52,    51,    54,     0,    61,    55,
-      56,    53,    57
+       3,     0,     0,     0,    30,    28,     0,    26,     0,    34,
+      35,    36,     0,     0,    20,    10,     0,     0,     0,     0,
+      17,     9,    21,     7,    13,    15,     0,    19,     0,     6,
+      68,     5,    23,    22,    37,     0,     0,     0,     0,    25,
+      11,    64,    62,    60,    24,    61,     0,     0,     0,    65,
+       0,    18,     0,     0,    66,    48,    50,    69,     4,    38,
+       0,    41,    42,    46,    31,    29,    32,    39,     0,    16,
+      12,    14,     8,    52,    51,     0,    49,     2,    33,    43,
+      44,    47,    40,    27,    56,    67,    45,     0,    54,    53,
+      56,     0,    63,    57,    58,    55,    59
 };
 
 /* YYPGOTO[NTERM-NUM]. */
 static const short yydefgoto[] =
 {
-      -1,     1,     2,    29,    51,    31,    35,    34,    32,    33,
-      58,    64,    61,    62,    52,    53,    54,    80,    83,    84,
-      65,    90,    43,    48,    74,    56
+      -1,     1,     2,    30,    53,    38,    32,    36,    35,    33,
+      34,    60,    66,    63,    64,    54,    55,    56,    84,    87,
+      88,    67,    94,    45,    50,    77,    58
 };
 
 /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
    STATE-NUM.  */
 static const short yypact[] =
 {
-  -32768,    23,    74,-32768,-32768,-32768,     1,   -31,-32768,-32768,
-  -32768,    29,     0,-32768,-32768,     7,    10,    14,    39,-32768,
-  -32768,-32768,-32768,-32768,-32768,    39,-32768,    18,-32768,    15,
-  -32768,-32768,-32768,    16,   -24,   -24,     0,-32768,-32768,-32768,
-  -32768,-32768,-32768,-32768,    39,    39,    39,-32768,    39,-32768,
-      17,    19,     8,-32768,-32768,-32768,-32768,-32768,     0,-32768,
-       4,-32768,   -24,   -24,     0,-32768,-32768,-32768,-32768,-32768,
-  -32768,-32768,    20,-32768,-32768,     0,    45,-32768,-32768,-32768,
-  -32768,-32768,-32768,   -22,    -2,-32768,-32768,     0,-32768,-32768,
-  -32768,    -2,-32768
+  -32768,    25,    77,-32768,-32768,-32768,   -20,-32768,   -31,-32768,
+  -32768,-32768,    35,     0,-32768,-32768,    12,    15,    16,    46,
+  -32768,-32768,-32768,-32768,-32768,-32768,    46,-32768,    20,-32768,
+      17,-32768,-32768,-32768,    21,   -24,   -24,     0,    14,-32768,
+  -32768,-32768,-32768,-32768,-32768,-32768,    46,    46,    46,-32768,
+      46,-32768,    26,    18,     9,-32768,-32768,-32768,-32768,-32768,
+       0,-32768,     5,-32768,   -24,   -24,     0,-32768,     0,-32768,
+  -32768,-32768,-32768,-32768,-32768,    23,-32768,-32768,     0,    52,
+  -32768,-32768,-32768,     0,-32768,-32768,-32768,     6,    -2,-32768,
+  -32768,     0,-32768,-32768,-32768,    -2,-32768
 };
 
 /* YYPGOTO[NTERM-NUM].  */
 static const short yypgoto[] =
 {
-  -32768,-32768,-32768,-32768,    47,-32768,-32768,-32768,-32768,-32768,
-  -32768,    -4,   -23,    25,-32768,     9,-32768,-32768,-32768,   -21,
-     -12,-32768,   -55,    11,-32768,-32768
+  -32768,-32768,-32768,-32768,    61,-32768,-32768,-32768,-32768,-32768,
+  -32768,-32768,   -55,   -22,    28,-32768,    13,-32768,-32768,-32768,
+     -21,   -13,-32768,   -56,    11,-32768,-32768
 };
 
 /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
@@ -570,34 +573,34 @@ static const short yypgoto[] =
    number is the opposite.  If zero, do what YYDEFACT says.  */
 static const short yytable[] =
 {
-      42,    39,    40,    39,    40,    77,    59,    39,    37,    76,
-      85,    60,    86,    87,     4,     5,     6,     7,     8,     9,
-      10,    82,    12,     3,     4,     5,     6,     7,     8,     9,
-      10,    36,    12,    41,    38,    41,    49,    88,    44,    78,
-      78,    45,    47,    50,    72,    46,    57,    55,    39,    30,
-      70,    71,    79,    50,    75,    66,    67,    68,    81,    69,
-      63,    73,     0,    79,     0,    91,     0,     0,     0,     0,
-       0,     0,    89,     0,     0,    92,     0,     0,     0,    89,
-       4,     5,     6,     7,     8,     9,    10,    11,    12,     0,
-      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
-      23,    24,    25,    26,     0,     0,     0,     0,     0,     0,
-      27,    28
+      44,    41,    42,    41,    42,    78,    80,    61,    41,    39,
+      79,    37,    62,    83,    91,     4,     5,     6,     7,     8,
+       9,    10,    11,    86,    13,     3,     4,     5,     6,     7,
+       8,     9,    10,    11,    43,    13,    43,    51,    92,    89,
+      40,    90,    81,    81,    46,    52,    75,    47,    48,    49,
+      57,    74,    59,    82,    68,    41,    52,    69,    70,    71,
+      73,    72,    85,    31,    65,    82,     0,    76,     0,    95,
+      82,     0,     0,     0,     0,    93,     0,     0,    96,     0,
+       0,     0,    93,     4,     5,     6,     7,     8,     9,    10,
+      11,    12,    13,     0,    14,    15,    16,    17,    18,    19,
+      20,    21,    22,    23,    24,    25,    26,    27,     0,     0,
+       0,     0,     0,     0,    28,    29
 };
 
 static const short yycheck[] =
 {
-      12,     3,     4,     3,     4,    60,    30,     3,    39,     5,
-      32,    35,    34,    15,     6,     7,     8,     9,    10,    11,
-      12,    76,    14,     0,     6,     7,     8,     9,    10,    11,
-      12,    30,    14,    35,     5,    35,    25,    39,    31,    62,
-      63,    31,     3,    35,    36,    31,    30,    32,     3,     2,
-      33,    32,    64,    35,    58,    44,    45,    46,    38,    48,
-      35,    52,    -1,    75,    -1,    86,    -1,    -1,    -1,    -1,
-      -1,    -1,    84,    -1,    -1,    87,    -1,    -1,    -1,    91,
-       6,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
-      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
-      26,    27,    28,    29,    -1,    -1,    -1,    -1,    -1,    -1,
-      36,    37
+      13,     3,     4,     3,     4,    60,    62,    31,     3,    40,
+       5,    31,    36,    68,    16,     6,     7,     8,     9,    10,
+      11,    12,    13,    79,    15,     0,     6,     7,     8,     9,
+      10,    11,    12,    13,    36,    15,    36,    26,    40,    33,
+       5,    35,    64,    65,    32,    36,    37,    32,    32,     3,
+      33,    33,    31,    66,    40,     3,    36,    46,    47,    48,
+      34,    50,    39,     2,    36,    78,    -1,    54,    -1,    90,
+      83,    -1,    -1,    -1,    -1,    88,    -1,    -1,    91,    -1,
+      -1,    -1,    95,     6,     7,     8,     9,    10,    11,    12,
+      13,    14,    15,    -1,    17,    18,    19,    20,    21,    22,
+      23,    24,    25,    26,    27,    28,    29,    30,    -1,    -1,
+      -1,    -1,    -1,    -1,    37,    38
 };
 
 #if YYDEBUG
@@ -605,16 +608,16 @@ static const short yycheck[] =
    symbol of state STATE-NUM.  */
 static const unsigned char yystos[] =
 {
-       0,    41,    42,     0,     6,     7,     8,     9,    10,    11,
-      12,    13,    14,    16,    17,    18,    19,    20,    21,    22,
-      23,    24,    25,    26,    27,    28,    29,    36,    37,    43,
-      44,    45,    48,    49,    47,    46,    30,    39,     5,     3,
-       4,    35,    60,    62,    31,    31,    31,     3,    63,    63,
-      35,    44,    54,    55,    56,    32,    65,    30,    50,    30,
-      35,    52,    53,    53,    51,    60,    63,    63,    63,    63,
-      33,    32,    36,    55,    64,    51,     5,    62,    52,    60,
-      57,    38,    62,    58,    59,    32,    34,    15,    39,    60,
-      61,    59,    60
+       0,    42,    43,     0,     6,     7,     8,     9,    10,    11,
+      12,    13,    14,    15,    17,    18,    19,    20,    21,    22,
+      23,    24,    25,    26,    27,    28,    29,    30,    37,    38,
+      44,    45,    47,    50,    51,    49,    48,    31,    46,    40,
+       5,     3,     4,    36,    62,    64,    32,    32,    32,     3,
+      65,    65,    36,    45,    56,    57,    58,    33,    67,    31,
+      52,    31,    36,    54,    55,    55,    53,    62,    40,    65,
+      65,    65,    65,    34,    33,    37,    57,    66,    53,     5,
+      64,    54,    62,    53,    59,    39,    64,    60,    61,    33,
+      35,    16,    40,    62,    63,    61,    62
 };
 #endif
 
@@ -1184,7 +1187,7 @@ yyreduce:
   switch (yyn)
     {
         case 2:
-#line 154 "parse-gram.y"
+#line 156 "parse-gram.y"
     {
       yycontrol->errcode = 0;
       epilogue_set (yyvsp[0].string, yylsp[0]);
@@ -1192,94 +1195,94 @@ yyreduce:
     break;
 
   case 6:
-#line 172 "parse-gram.y"
+#line 174 "parse-gram.y"
     { prologue_augment (yyvsp[0].string, yylsp[0]); }
     break;
 
   case 7:
-#line 173 "parse-gram.y"
+#line 175 "parse-gram.y"
     { debug_flag = 1; }
     break;
 
   case 8:
-#line 174 "parse-gram.y"
+#line 176 "parse-gram.y"
     { muscle_insert (yyvsp[-1].string, yyvsp[0].string); }
     break;
 
   case 9:
-#line 175 "parse-gram.y"
+#line 177 "parse-gram.y"
     { defines_flag = 1; }
     break;
 
   case 10:
-#line 176 "parse-gram.y"
+#line 178 "parse-gram.y"
     { error_verbose = 1; }
     break;
 
   case 11:
-#line 177 "parse-gram.y"
+#line 179 "parse-gram.y"
     { expected_conflicts = yyvsp[0].integer; }
     break;
 
   case 12:
-#line 178 "parse-gram.y"
+#line 180 "parse-gram.y"
     { spec_file_prefix = yyvsp[0].string; }
     break;
 
   case 13:
-#line 179 "parse-gram.y"
+#line 181 "parse-gram.y"
     { locations_flag = 1; }
     break;
 
   case 14:
-#line 180 "parse-gram.y"
+#line 182 "parse-gram.y"
     { spec_name_prefix = yyvsp[0].string; }
     break;
 
   case 15:
-#line 181 "parse-gram.y"
+#line 183 "parse-gram.y"
     { no_lines_flag = 1; }
     break;
 
   case 16:
-#line 182 "parse-gram.y"
+#line 184 "parse-gram.y"
     { spec_outfile = yyvsp[0].string; }
     break;
 
   case 17:
-#line 183 "parse-gram.y"
+#line 185 "parse-gram.y"
     { pure_parser = 1; }
     break;
 
   case 18:
-#line 184 "parse-gram.y"
+#line 186 "parse-gram.y"
     { skeleton = yyvsp[0].string; }
     break;
 
   case 19:
-#line 185 "parse-gram.y"
+#line 187 "parse-gram.y"
     { token_table_flag = 1; }
     break;
 
   case 20:
-#line 186 "parse-gram.y"
+#line 188 "parse-gram.y"
     { report_flag = 1; }
     break;
 
   case 21:
-#line 187 "parse-gram.y"
+#line 189 "parse-gram.y"
     { yacc_flag = 1; }
     break;
 
   case 24:
-#line 194 "parse-gram.y"
+#line 196 "parse-gram.y"
     {
       grammar_start_symbol_set (yyvsp[0].symbol, yylsp[0]);
     }
     break;
 
   case 25:
-#line 198 "parse-gram.y"
+#line 200 "parse-gram.y"
     {
       typed = 1;
       MUSCLE_INSERT_INT ("stype_line", yylsp[0].first_line);
@@ -1289,24 +1292,27 @@ yyreduce:
 
   case 26:
 #line 206 "parse-gram.y"
-    { current_class = nterm_sym; }
+    { current_braced_code = destructor_braced_code; }
     break;
 
   case 27:
-#line 207 "parse-gram.y"
+#line 208 "parse-gram.y"
     {
-      current_class = unknown_sym;
-      current_type = NULL;
+      symbol_list_t *list;
+      for (list = yyvsp[0].list; list; list = list->next)
+	symbol_destructor_set (list->sym, list->location, yyvsp[-1].string);
+      symbol_list_free (yyvsp[0].list);
+      current_braced_code = action_braced_code;
     }
     break;
 
   case 28:
-#line 211 "parse-gram.y"
-    { current_class = token_sym; }
+#line 218 "parse-gram.y"
+    { current_class = nterm_sym; }
     break;
 
   case 29:
-#line 212 "parse-gram.y"
+#line 219 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
@@ -1314,7 +1320,20 @@ yyreduce:
     break;
 
   case 30:
-#line 217 "parse-gram.y"
+#line 223 "parse-gram.y"
+    { current_class = token_sym; }
+    break;
+
+  case 31:
+#line 224 "parse-gram.y"
+    {
+      current_class = unknown_sym;
+      current_type = NULL;
+    }
+    break;
+
+  case 32:
+#line 229 "parse-gram.y"
     {
       symbol_list_t *list;
       for (list = yyvsp[0].list; list; list = list->next)
@@ -1323,8 +1342,8 @@ yyreduce:
     }
     break;
 
-  case 31:
-#line 227 "parse-gram.y"
+  case 33:
+#line 239 "parse-gram.y"
     {
       symbol_list_t *list;
       ++current_prec;
@@ -1338,58 +1357,58 @@ yyreduce:
     }
     break;
 
-  case 32:
-#line 241 "parse-gram.y"
+  case 34:
+#line 253 "parse-gram.y"
     { yyval.assoc = left_assoc; }
     break;
 
-  case 33:
-#line 242 "parse-gram.y"
+  case 35:
+#line 254 "parse-gram.y"
     { yyval.assoc = right_assoc; }
     break;
 
-  case 34:
-#line 243 "parse-gram.y"
+  case 36:
+#line 255 "parse-gram.y"
     { yyval.assoc = non_assoc; }
     break;
 
-  case 35:
-#line 247 "parse-gram.y"
+  case 37:
+#line 259 "parse-gram.y"
     { current_type = NULL;}
     break;
 
-  case 36:
-#line 248 "parse-gram.y"
+  case 38:
+#line 260 "parse-gram.y"
     { current_type = yyvsp[0].string; }
     break;
 
-  case 37:
-#line 254 "parse-gram.y"
+  case 39:
+#line 266 "parse-gram.y"
     { yyval.list = symbol_list_new (yyvsp[0].symbol, yylsp[0]); }
     break;
 
-  case 38:
-#line 255 "parse-gram.y"
+  case 40:
+#line 267 "parse-gram.y"
     { yyval.list = symbol_list_prepend (yyvsp[-1].list, yyvsp[0].symbol, yylsp[0]); }
     break;
 
-  case 39:
-#line 261 "parse-gram.y"
+  case 41:
+#line 273 "parse-gram.y"
     {
        current_type = yyvsp[0].string;
      }
     break;
 
-  case 40:
-#line 265 "parse-gram.y"
+  case 42:
+#line 277 "parse-gram.y"
     {
        symbol_class_set (yyvsp[0].symbol, current_class);
        symbol_type_set (yyvsp[0].symbol, yylsp[0], current_type);
      }
     break;
 
-  case 41:
-#line 270 "parse-gram.y"
+  case 43:
+#line 282 "parse-gram.y"
     {
       symbol_class_set (yyvsp[-1].symbol, current_class);
       symbol_type_set (yyvsp[-1].symbol, yylsp[-1], current_type);
@@ -1397,8 +1416,8 @@ yyreduce:
     }
     break;
 
-  case 42:
-#line 276 "parse-gram.y"
+  case 44:
+#line 288 "parse-gram.y"
     {
       symbol_class_set (yyvsp[-1].symbol, current_class);
       symbol_type_set (yyvsp[-1].symbol, yylsp[-1], current_type);
@@ -1406,8 +1425,8 @@ yyreduce:
     }
     break;
 
-  case 43:
-#line 282 "parse-gram.y"
+  case 45:
+#line 294 "parse-gram.y"
     {
       symbol_class_set (yyvsp[-2].symbol, current_class);
       symbol_type_set (yyvsp[-2].symbol, yylsp[-2], current_type);
@@ -1416,101 +1435,101 @@ yyreduce:
     }
     break;
 
-  case 44:
-#line 293 "parse-gram.y"
+  case 46:
+#line 305 "parse-gram.y"
     {;}
     break;
 
-  case 45:
-#line 295 "parse-gram.y"
+  case 47:
+#line 307 "parse-gram.y"
     {;}
     break;
 
-  case 50:
-#line 317 "parse-gram.y"
+  case 52:
+#line 329 "parse-gram.y"
     { current_lhs = yyvsp[-1].symbol; current_lhs_location = yylsp[-1]; }
     break;
 
-  case 51:
-#line 318 "parse-gram.y"
+  case 53:
+#line 330 "parse-gram.y"
     {;}
     break;
 
-  case 52:
-#line 322 "parse-gram.y"
+  case 54:
+#line 334 "parse-gram.y"
     { grammar_rule_end (yylsp[0]); }
     break;
 
-  case 53:
-#line 323 "parse-gram.y"
+  case 55:
+#line 335 "parse-gram.y"
     { grammar_rule_end (yylsp[0]); }
     break;
 
-  case 54:
-#line 328 "parse-gram.y"
+  case 56:
+#line 340 "parse-gram.y"
     { grammar_rule_begin (current_lhs, current_lhs_location); }
     break;
 
-  case 55:
-#line 330 "parse-gram.y"
+  case 57:
+#line 342 "parse-gram.y"
     { grammar_current_rule_symbol_append (yyvsp[0].symbol, yylsp[0]); }
     break;
 
-  case 56:
-#line 332 "parse-gram.y"
+  case 58:
+#line 344 "parse-gram.y"
     { grammar_current_rule_action_append (yyvsp[0].string, yylsp[0]); }
     break;
 
-  case 57:
-#line 334 "parse-gram.y"
+  case 59:
+#line 346 "parse-gram.y"
     { grammar_current_rule_prec_set (yyvsp[0].symbol); }
     break;
 
-  case 58:
-#line 338 "parse-gram.y"
+  case 60:
+#line 350 "parse-gram.y"
     { yyval.symbol = yyvsp[0].symbol; }
     break;
 
-  case 59:
-#line 339 "parse-gram.y"
+  case 61:
+#line 351 "parse-gram.y"
     { yyval.symbol = yyvsp[0].symbol; }
     break;
 
-  case 60:
-#line 340 "parse-gram.y"
+  case 62:
+#line 352 "parse-gram.y"
     { yyval.symbol = getsym (yyvsp[0].string, yylsp[0]); }
     break;
 
-  case 61:
-#line 345 "parse-gram.y"
+  case 63:
+#line 357 "parse-gram.y"
     { yyval.string = yyvsp[0].string; }
     break;
 
-  case 62:
-#line 351 "parse-gram.y"
+  case 64:
+#line 363 "parse-gram.y"
     {
       yyval.symbol = getsym (yyvsp[0].string, yylsp[0]);
       symbol_class_set (yyval.symbol, token_sym);
     }
     break;
 
-  case 63:
-#line 360 "parse-gram.y"
+  case 65:
+#line 372 "parse-gram.y"
     {
       yyval.string = yyvsp[0].string + 1;
       yyval.string[strlen (yyval.string) - 1] = '\0';
     }
     break;
 
-  case 64:
-#line 368 "parse-gram.y"
+  case 66:
+#line 380 "parse-gram.y"
     {
       yyval.string = xstrdup ("");
     }
     break;
 
-  case 65:
-#line 372 "parse-gram.y"
+  case 67:
+#line 384 "parse-gram.y"
     {
       yyval.string = yyvsp[0].string;
     }
@@ -1520,7 +1539,7 @@ yyreduce:
     }
 
 /* Line 1012 of /usr/local/share/bison/bison.simple.  */
-#line 1524 "parse-gram.c"
+#line 1543 "parse-gram.c"
 
   yyvsp -= yylen;
   yyssp -= yylen;
@@ -1741,7 +1760,7 @@ yyreturn:
   return yyresult;
 }
 
-#line 381 "parse-gram.y"
+#line 393 "parse-gram.y"
 
 /*------------------------------------------------------------------.
 | When debugging the parser, display tokens' locations and values.  |
