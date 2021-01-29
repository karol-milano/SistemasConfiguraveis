@@ -55,10 +55,7 @@
 #define yychar  gram_char
 #define yydebug gram_debug
 #define yynerrs gram_nerrs
-#if YYLSP_NEEDED
-# define yylloc gram_lloc
-#endif
-
+#define yylloc gram_lloc
 
 /* Copy the first part of user declarations.  */
 #line 31 "parse-gram.y"
@@ -133,37 +130,38 @@ braced_code_t current_braced_code = action_braced_code;
      PERCENT_NTERM = 262,
      PERCENT_TYPE = 263,
      PERCENT_DESTRUCTOR = 264,
-     PERCENT_UNION = 265,
-     PERCENT_LEFT = 266,
-     PERCENT_RIGHT = 267,
-     PERCENT_NONASSOC = 268,
-     PERCENT_EXPECT = 269,
-     PERCENT_START = 270,
-     PERCENT_PREC = 271,
-     PERCENT_VERBOSE = 272,
-     PERCENT_ERROR_VERBOSE = 273,
-     PERCENT_OUTPUT = 274,
-     PERCENT_FILE_PREFIX = 275,
-     PERCENT_NAME_PREFIX = 276,
-     PERCENT_DEFINE = 277,
-     PERCENT_PURE_PARSER = 278,
-     PERCENT_DEFINES = 279,
-     PERCENT_YACC = 280,
-     PERCENT_DEBUG = 281,
-     PERCENT_LOCATIONS = 282,
-     PERCENT_NO_LINES = 283,
-     PERCENT_SKELETON = 284,
-     PERCENT_TOKEN_TABLE = 285,
-     TYPE = 286,
-     EQUAL = 287,
-     SEMICOLON = 288,
-     COLON = 289,
-     PIPE = 290,
-     ID = 291,
-     PERCENT_PERCENT = 292,
-     PROLOGUE = 293,
-     EPILOGUE = 294,
-     BRACED_CODE = 295
+     PERCENT_PRINTER = 265,
+     PERCENT_UNION = 266,
+     PERCENT_LEFT = 267,
+     PERCENT_RIGHT = 268,
+     PERCENT_NONASSOC = 269,
+     PERCENT_EXPECT = 270,
+     PERCENT_START = 271,
+     PERCENT_PREC = 272,
+     PERCENT_VERBOSE = 273,
+     PERCENT_ERROR_VERBOSE = 274,
+     PERCENT_OUTPUT = 275,
+     PERCENT_FILE_PREFIX = 276,
+     PERCENT_NAME_PREFIX = 277,
+     PERCENT_DEFINE = 278,
+     PERCENT_PURE_PARSER = 279,
+     PERCENT_DEFINES = 280,
+     PERCENT_YACC = 281,
+     PERCENT_DEBUG = 282,
+     PERCENT_LOCATIONS = 283,
+     PERCENT_NO_LINES = 284,
+     PERCENT_SKELETON = 285,
+     PERCENT_TOKEN_TABLE = 286,
+     TYPE = 287,
+     EQUAL = 288,
+     SEMICOLON = 289,
+     COLON = 290,
+     PIPE = 291,
+     ID = 292,
+     PERCENT_PERCENT = 293,
+     PROLOGUE = 294,
+     EPILOGUE = 295,
+     BRACED_CODE = 296
    };
 # endif
   /* POSIX requires `int' for tokens in interfaces.  */
@@ -177,37 +175,38 @@ braced_code_t current_braced_code = action_braced_code;
 #define PERCENT_NTERM 262
 #define PERCENT_TYPE 263
 #define PERCENT_DESTRUCTOR 264
-#define PERCENT_UNION 265
-#define PERCENT_LEFT 266
-#define PERCENT_RIGHT 267
-#define PERCENT_NONASSOC 268
-#define PERCENT_EXPECT 269
-#define PERCENT_START 270
-#define PERCENT_PREC 271
-#define PERCENT_VERBOSE 272
-#define PERCENT_ERROR_VERBOSE 273
-#define PERCENT_OUTPUT 274
-#define PERCENT_FILE_PREFIX 275
-#define PERCENT_NAME_PREFIX 276
-#define PERCENT_DEFINE 277
-#define PERCENT_PURE_PARSER 278
-#define PERCENT_DEFINES 279
-#define PERCENT_YACC 280
-#define PERCENT_DEBUG 281
-#define PERCENT_LOCATIONS 282
-#define PERCENT_NO_LINES 283
-#define PERCENT_SKELETON 284
-#define PERCENT_TOKEN_TABLE 285
-#define TYPE 286
-#define EQUAL 287
-#define SEMICOLON 288
-#define COLON 289
-#define PIPE 290
-#define ID 291
-#define PERCENT_PERCENT 292
-#define PROLOGUE 293
-#define EPILOGUE 294
-#define BRACED_CODE 295
+#define PERCENT_PRINTER 265
+#define PERCENT_UNION 266
+#define PERCENT_LEFT 267
+#define PERCENT_RIGHT 268
+#define PERCENT_NONASSOC 269
+#define PERCENT_EXPECT 270
+#define PERCENT_START 271
+#define PERCENT_PREC 272
+#define PERCENT_VERBOSE 273
+#define PERCENT_ERROR_VERBOSE 274
+#define PERCENT_OUTPUT 275
+#define PERCENT_FILE_PREFIX 276
+#define PERCENT_NAME_PREFIX 277
+#define PERCENT_DEFINE 278
+#define PERCENT_PURE_PARSER 279
+#define PERCENT_DEFINES 280
+#define PERCENT_YACC 281
+#define PERCENT_DEBUG 282
+#define PERCENT_LOCATIONS 283
+#define PERCENT_NO_LINES 284
+#define PERCENT_SKELETON 285
+#define PERCENT_TOKEN_TABLE 286
+#define TYPE 287
+#define EQUAL 288
+#define SEMICOLON 289
+#define COLON 290
+#define PIPE 291
+#define ID 292
+#define PERCENT_PERCENT 293
+#define PROLOGUE 294
+#define EPILOGUE 295
+#define BRACED_CODE 296
 
 
 
@@ -234,8 +233,8 @@ typedef union {
   char *string;
   associativity assoc;
 } yystype;
-/* Line 199 of /usr/local/share/bison/bison.simple.  */
-#line 239 "parse-gram.c"
+/* Line 232 of /usr/local/share/bison/bison.simple.  */
+#line 238 "parse-gram.c"
 # define YYSTYPE yystype
 # define YYSTYPE_IS_TRIVIAL 1
 #endif
@@ -255,8 +254,8 @@ typedef struct yyltype
 /* Copy the second part of user declarations.  */
 
 
-/* Line 219 of /usr/local/share/bison/bison.simple.  */
-#line 260 "parse-gram.c"
+/* Line 252 of /usr/local/share/bison/bison.simple.  */
+#line 259 "parse-gram.c"
 
 #if ! defined (yyoverflow) || YYERROR_VERBOSE
 
@@ -299,9 +298,7 @@ union yyalloc
 {
   short yyss;
   YYSTYPE yyvs;
-# if YYLSP_NEEDED
-  YYLTYPE yyls;
-# endif
+    YYLTYPE yyls;
 };
 
 /* The size of the maximum gap between one aligned stack and the next.  */
@@ -309,15 +306,9 @@ union yyalloc
 
 /* The size of an array large to enough to hold all stacks, each with
    N elements.  */
-# if YYLSP_NEEDED
-#  define YYSTACK_BYTES(N) \
+# define YYSTACK_BYTES(N) \
      ((N) * (sizeof (short) + sizeof (YYSTYPE) + sizeof (YYLTYPE))	\
       + 2 * YYSTACK_GAP_MAX)
-# else
-#  define YYSTACK_BYTES(N) \
-     ((N) * (sizeof (short) + sizeof (YYSTYPE))				\
-      + YYSTACK_GAP_MAX)
-# endif
 
 /* Copy COUNT objects from FROM to TO.  The source and destination do
    not overlap.  */
@@ -358,20 +349,20 @@ union yyalloc
 /* YYFINAL -- State number of the termination state. */
 #define YYFINAL  3
 #define YYFLAG	 -32768
-#define YYLAST   115
+#define YYLAST   151
 
 /* YYNTOKENS -- Number of terminals. */
-#define YYNTOKENS  41
+#define YYNTOKENS  42
 /* YYNNTS -- Number of nonterminals. */
-#define YYNNTS  27
+#define YYNNTS  28
 /* YYNRULES -- Number of rules. */
-#define YYNRULES  69
+#define YYNRULES  71
 /* YYNRULES -- Number of states. */
-#define YYNSTATES  97
+#define YYNSTATES  101
 
 /* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
 #define YYUNDEFTOK  2
-#define YYMAXUTOK   295
+#define YYMAXUTOK   296
 
 #define YYTRANSLATE(X) \
   ((unsigned)(X) <= YYMAXUTOK ? yytranslate[X] : YYUNDEFTOK)
@@ -408,7 +399,7 @@ static const unsigned char yytranslate[] =
        5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
       15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
       25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
-      35,    36,    37,    38,    39,    40
+      35,    36,    37,    38,    39,    40,    41
 };
 
 #if YYDEBUG
@@ -419,45 +410,48 @@ static const unsigned char yyprhs[] =
        0,     0,     3,     8,     9,    13,    15,    17,    19,    23,
       25,    27,    30,    34,    36,    40,    42,    46,    48,    51,
       53,    55,    57,    59,    61,    64,    67,    68,    73,    74,
-      78,    79,    83,    87,    91,    93,    95,    97,    98,   100,
-     102,   105,   107,   109,   112,   115,   119,   121,   124,   126,
-     129,   131,   134,   135,   141,   143,   147,   148,   151,   154,
-     158,   160,   162,   164,   166,   168,   170,   171,   174,   175
+      79,    80,    84,    85,    89,    93,    97,    99,   101,   103,
+     104,   106,   108,   111,   113,   115,   118,   121,   125,   127,
+     130,   132,   135,   137,   140,   141,   147,   149,   153,   154,
+     157,   160,   164,   166,   168,   170,   172,   174,   176,   177,
+     180,   181
 };
 
 /* YYRHS -- A `-1'-separated list of the rules' RHS. */
 static const signed char yyrhs[] =
 {
-      42,     0,    -1,    43,    37,    56,    66,    -1,    -1,    43,
-      44,    67,    -1,    45,    -1,    38,    -1,    26,    -1,    22,
-      65,    65,    -1,    24,    -1,    18,    -1,    14,     5,    -1,
-      20,    32,    65,    -1,    27,    -1,    21,    32,    65,    -1,
-      28,    -1,    19,    32,    65,    -1,    23,    -1,    29,    65,
-      -1,    30,    -1,    17,    -1,    25,    -1,    50,    -1,    47,
-      -1,    15,    62,    -1,    10,    40,    -1,    -1,     9,    46,
-      40,    53,    -1,    -1,     7,    48,    55,    -1,    -1,     6,
-      49,    55,    -1,     8,    31,    53,    -1,    51,    52,    53,
-      -1,    11,    -1,    12,    -1,    13,    -1,    -1,    31,    -1,
-      62,    -1,    53,    62,    -1,    31,    -1,    36,    -1,    36,
-       5,    -1,    36,    64,    -1,    36,     5,    64,    -1,    54,
-      -1,    55,    54,    -1,    57,    -1,    56,    57,    -1,    58,
-      -1,    45,    33,    -1,    -1,    36,    34,    59,    60,    33,
-      -1,    61,    -1,    60,    35,    61,    -1,    -1,    61,    62,
-      -1,    61,    63,    -1,    61,    16,    62,    -1,    36,    -1,
-      64,    -1,     4,    -1,    40,    -1,     3,    -1,     3,    -1,
-      -1,    37,    39,    -1,    -1,    33,    -1
+      43,     0,    -1,    44,    38,    58,    68,    -1,    -1,    44,
+      45,    69,    -1,    46,    -1,    39,    -1,    27,    -1,    23,
+      67,    67,    -1,    25,    -1,    19,    -1,    15,     5,    -1,
+      21,    33,    67,    -1,    28,    -1,    22,    33,    67,    -1,
+      29,    -1,    20,    33,    67,    -1,    24,    -1,    30,    67,
+      -1,    31,    -1,    18,    -1,    26,    -1,    52,    -1,    49,
+      -1,    16,    64,    -1,    11,    41,    -1,    -1,     9,    47,
+      41,    55,    -1,    -1,    10,    48,    41,    55,    -1,    -1,
+       7,    50,    57,    -1,    -1,     6,    51,    57,    -1,     8,
+      32,    55,    -1,    53,    54,    55,    -1,    12,    -1,    13,
+      -1,    14,    -1,    -1,    32,    -1,    64,    -1,    55,    64,
+      -1,    32,    -1,    37,    -1,    37,     5,    -1,    37,    66,
+      -1,    37,     5,    66,    -1,    56,    -1,    57,    56,    -1,
+      59,    -1,    58,    59,    -1,    60,    -1,    46,    34,    -1,
+      -1,    37,    35,    61,    62,    34,    -1,    63,    -1,    62,
+      36,    63,    -1,    -1,    63,    64,    -1,    63,    65,    -1,
+      63,    17,    64,    -1,    37,    -1,    66,    -1,     4,    -1,
+      41,    -1,     3,    -1,     3,    -1,    -1,    38,    40,    -1,
+      -1,    34,    -1
 };
 
 /* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
 static const unsigned short yyrline[] =
 {
-       0,   154,   154,   167,   169,   172,   174,   175,   176,   177,
-     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
-     188,   189,   192,   194,   195,   199,   205,   205,   217,   217,
-     223,   223,   228,   237,   252,   254,   255,   258,   260,   265,
-     267,   271,   276,   281,   287,   293,   303,   306,   315,   317,
-     323,   325,   328,   328,   333,   335,   338,   341,   343,   345,
-     349,   351,   352,   355,   361,   370,   378,   383,   389,   391
+       0,   158,   158,   171,   173,   176,   178,   179,   180,   181,
+     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
+     192,   193,   196,   198,   199,   203,   210,   209,   220,   219,
+     232,   231,   237,   237,   242,   251,   266,   268,   269,   272,
+     274,   279,   281,   285,   290,   295,   301,   307,   317,   320,
+     329,   331,   337,   339,   343,   342,   347,   349,   352,   355,
+     357,   359,   363,   365,   366,   369,   375,   384,   392,   397,
+     403,   405
 };
 #endif
 
@@ -468,19 +462,20 @@ static const char *const yytname[] =
 {
   "\"end of string\"", "error", "$undefined.", "STRING", "CHARACTER", "INT", 
   "\"%token\"", "\"%nterm\"", "\"%type\"", "\"%destructor\"", 
-  "\"%union\"", "\"%left\"", "\"%right\"", "\"%nonassoc\"", "\"%expect\"", 
-  "\"%start\"", "\"%prec\"", "\"%verbose\"", "\"%error-verbose\"", 
-  "\"%output\"", "\"%file-prefix\"", "\"%name-prefix\"", "\"%define\"", 
-  "\"%pure-parser\"", "\"%defines\"", "\"%yacc\"", "\"%debug\"", 
-  "\"%locations\"", "\"%no-lines\"", "\"%skeleton\"", "\"%token-table\"", 
-  "TYPE", "\"=\"", "\";\"", "\":\"", "\"|\"", "\"identifier\"", "\"%%\"", 
-  "PROLOGUE", "EPILOGUE", "BRACED_CODE", "$axiom", "input", 
-  "declarations", "declaration", "grammar_declaration", "@1", 
-  "symbol_declaration", "@2", "@3", "precedence_declaration", 
-  "precedence_declarator", "type.opt", "symbols.1", "symbol_def", 
-  "symbol_defs.1", "grammar", "rules_or_grammar_declaration", "rules", 
-  "@4", "rhses.1", "rhs", "symbol", "action", "string_as_id", 
-  "string_content", "epilogue.opt", "semi_colon.opt", 0
+  "\"%printer\"", "\"%union\"", "\"%left\"", "\"%right\"", 
+  "\"%nonassoc\"", "\"%expect\"", "\"%start\"", "\"%prec\"", 
+  "\"%verbose\"", "\"%error-verbose\"", "\"%output\"", "\"%file-prefix\"", 
+  "\"%name-prefix\"", "\"%define\"", "\"%pure-parser\"", "\"%defines\"", 
+  "\"%yacc\"", "\"%debug\"", "\"%locations\"", "\"%no-lines\"", 
+  "\"%skeleton\"", "\"%token-table\"", "TYPE", "\"=\"", "\";\"", "\":\"", 
+  "\"|\"", "\"identifier\"", "\"%%\"", "PROLOGUE", "EPILOGUE", 
+  "BRACED_CODE", "$axiom", "input", "declarations", "declaration", 
+  "grammar_declaration", "@1", "@2", "symbol_declaration", "@3", "@4", 
+  "precedence_declaration", "precedence_declarator", "type.opt", 
+  "symbols.1", "symbol_def", "symbol_defs.1", "grammar", 
+  "rules_or_grammar_declaration", "rules", "@5", "rhses.1", "rhs", 
+  "symbol", "action", "string_as_id", "string_content", "epilogue.opt", 
+  "semi_colon.opt", 0
 };
 #endif
 
@@ -492,19 +487,20 @@ static const short yytoknum[] =
      265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
      275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
      285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
-     295,    -1
+     295,   296,    -1
 };
 
 /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
 static const unsigned char yyr1[] =
 {
-       0,    41,    42,    43,    43,    44,    44,    44,    44,    44,
-      44,    44,    44,    44,    44,    44,    44,    44,    44,    44,
-      44,    44,    45,    45,    45,    45,    46,    45,    48,    47,
-      49,    47,    47,    50,    51,    51,    51,    52,    52,    53,
-      53,    54,    54,    54,    54,    54,    55,    55,    56,    56,
-      57,    57,    59,    58,    60,    60,    61,    61,    61,    61,
-      62,    62,    62,    63,    64,    65,    66,    66,    67,    67
+       0,    42,    43,    44,    44,    45,    45,    45,    45,    45,
+      45,    45,    45,    45,    45,    45,    45,    45,    45,    45,
+      45,    45,    46,    46,    46,    46,    47,    46,    48,    46,
+      50,    49,    51,    49,    49,    52,    53,    53,    53,    54,
+      54,    55,    55,    56,    56,    56,    56,    56,    57,    57,
+      58,    58,    59,    59,    61,    60,    62,    62,    63,    63,
+      63,    63,    64,    64,    64,    65,    66,    67,    68,    68,
+      69,    69
 };
 
 /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
@@ -512,11 +508,12 @@ static const unsigned char yyr2[] =
 {
        0,     2,     4,     0,     3,     1,     1,     1,     3,     1,
        1,     2,     3,     1,     3,     1,     3,     1,     2,     1,
-       1,     1,     1,     1,     2,     2,     0,     4,     0,     3,
-       0,     3,     3,     3,     1,     1,     1,     0,     1,     1,
-       2,     1,     1,     2,     2,     3,     1,     2,     1,     2,
-       1,     2,     0,     5,     1,     3,     0,     2,     2,     3,
-       1,     1,     1,     1,     1,     1,     0,     2,     0,     1
+       1,     1,     1,     1,     2,     2,     0,     4,     0,     4,
+       0,     3,     0,     3,     3,     3,     1,     1,     1,     0,
+       1,     1,     2,     1,     1,     2,     2,     3,     1,     2,
+       1,     2,     1,     2,     0,     5,     1,     3,     0,     2,
+       2,     3,     1,     1,     1,     1,     1,     1,     0,     2,
+       0,     1
 };
 
 /* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
@@ -524,48 +521,50 @@ static const unsigned char yyr2[] =
    means the default is an error.  */
 static const short yydefact[] =
 {
-       3,     0,     0,     0,    30,    28,     0,    26,     0,    34,
-      35,    36,     0,     0,    20,    10,     0,     0,     0,     0,
-      17,     9,    21,     7,    13,    15,     0,    19,     0,     6,
-      68,     5,    23,    22,    37,     0,     0,     0,     0,    25,
-      11,    64,    62,    60,    24,    61,     0,     0,     0,    65,
-       0,    18,     0,     0,    66,    48,    50,    69,     4,    38,
-       0,    41,    42,    46,    31,    29,    32,    39,     0,    16,
-      12,    14,     8,    52,    51,     0,    49,     2,    33,    43,
-      44,    47,    40,    27,    56,    67,    45,     0,    54,    53,
-      56,     0,    63,    57,    58,    55,    59
+       3,     0,     0,     0,    32,    30,     0,    26,    28,     0,
+      36,    37,    38,     0,     0,    20,    10,     0,     0,     0,
+       0,    17,     9,    21,     7,    13,    15,     0,    19,     0,
+       6,    70,     5,    23,    22,    39,     0,     0,     0,     0,
+       0,    25,    11,    66,    64,    62,    24,    63,     0,     0,
+       0,    67,     0,    18,     0,     0,    68,    50,    52,    71,
+       4,    40,     0,    43,    44,    48,    33,    31,    34,    41,
+       0,     0,    16,    12,    14,     8,    54,    53,     0,    51,
+       2,    35,    45,    46,    49,    42,    27,    29,    58,    69,
+      47,     0,    56,    55,    58,     0,    65,    59,    60,    57,
+      61
 };
 
 /* YYPGOTO[NTERM-NUM]. */
 static const short yydefgoto[] =
 {
-      -1,     1,     2,    30,    53,    38,    32,    36,    35,    33,
-      34,    60,    66,    63,    64,    54,    55,    56,    84,    87,
-      88,    67,    94,    45,    50,    77,    58
+      -1,     1,     2,    31,    55,    39,    40,    33,    37,    36,
+      34,    35,    62,    68,    65,    66,    56,    57,    58,    88,
+      91,    92,    69,    98,    47,    52,    80,    60
 };
 
 /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
    STATE-NUM.  */
 static const short yypact[] =
 {
-  -32768,    25,    77,-32768,-32768,-32768,   -20,-32768,   -31,-32768,
-  -32768,-32768,    35,     0,-32768,-32768,    12,    15,    16,    46,
-  -32768,-32768,-32768,-32768,-32768,-32768,    46,-32768,    20,-32768,
-      17,-32768,-32768,-32768,    21,   -24,   -24,     0,    14,-32768,
-  -32768,-32768,-32768,-32768,-32768,-32768,    46,    46,    46,-32768,
-      46,-32768,    26,    18,     9,-32768,-32768,-32768,-32768,-32768,
-       0,-32768,     5,-32768,   -24,   -24,     0,-32768,     0,-32768,
-  -32768,-32768,-32768,-32768,-32768,    23,-32768,-32768,     0,    52,
-  -32768,-32768,-32768,     0,-32768,-32768,-32768,     6,    -2,-32768,
-  -32768,     0,-32768,-32768,-32768,    -2,-32768
+  -32768,     8,    80,-32768,-32768,-32768,   -19,-32768,-32768,   -11,
+  -32768,-32768,-32768,    31,     0,-32768,-32768,     5,     9,    11,
+      40,-32768,-32768,-32768,-32768,-32768,-32768,    40,-32768,   114,
+  -32768,    12,-32768,-32768,-32768,    13,   -27,   -27,     0,    14,
+      15,-32768,-32768,-32768,-32768,-32768,-32768,-32768,    40,    40,
+      40,-32768,    40,-32768,    16,    18,    10,-32768,-32768,-32768,
+  -32768,-32768,     0,-32768,     6,-32768,   -27,   -27,     0,-32768,
+       0,     0,-32768,-32768,-32768,-32768,-32768,-32768,    17,-32768,
+  -32768,     0,    46,-32768,-32768,-32768,     0,     0,-32768,-32768,
+  -32768,   -22,    -2,-32768,-32768,     0,-32768,-32768,-32768,    -2,
+  -32768
 };
 
 /* YYPGOTO[NTERM-NUM].  */
 static const short yypgoto[] =
 {
-  -32768,-32768,-32768,-32768,    61,-32768,-32768,-32768,-32768,-32768,
-  -32768,-32768,   -55,   -22,    28,-32768,    13,-32768,-32768,-32768,
-     -21,   -13,-32768,   -56,    11,-32768,-32768
+  -32768,-32768,-32768,-32768,    48,-32768,-32768,-32768,-32768,-32768,
+  -32768,-32768,-32768,   -30,   -33,    21,-32768,    -3,-32768,-32768,
+  -32768,   -35,   -14,-32768,   -57,   -21,-32768,-32768
 };
 
 /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
@@ -573,53 +572,60 @@ static const short yypgoto[] =
    number is the opposite.  If zero, do what YYDEFACT says.  */
 static const short yytable[] =
 {
-      44,    41,    42,    41,    42,    78,    80,    61,    41,    39,
-      79,    37,    62,    83,    91,     4,     5,     6,     7,     8,
-       9,    10,    11,    86,    13,     3,     4,     5,     6,     7,
-       8,     9,    10,    11,    43,    13,    43,    51,    92,    89,
-      40,    90,    81,    81,    46,    52,    75,    47,    48,    49,
-      57,    74,    59,    82,    68,    41,    52,    69,    70,    71,
-      73,    72,    85,    31,    65,    82,     0,    76,     0,    95,
-      82,     0,     0,     0,     0,    93,     0,     0,    96,     0,
-       0,     0,    93,     4,     5,     6,     7,     8,     9,    10,
-      11,    12,    13,     0,    14,    15,    16,    17,    18,    19,
-      20,    21,    22,    23,    24,    25,    26,    27,     0,     0,
-       0,     0,     0,     0,    28,    29
+      46,    43,    44,    43,    44,    63,    53,    83,     3,    43,
+      64,    82,    93,    38,    94,    95,     4,     5,     6,     7,
+       8,     9,    10,    11,    12,    90,    14,    72,    73,    74,
+      41,    75,    81,    84,    84,    45,    42,    45,    48,    96,
+      86,    87,    49,    51,    50,    61,    59,    54,    78,    43,
+      32,    76,    77,    79,    85,    70,    71,    89,    67,    99,
+       0,     0,     0,     0,     0,     0,     0,    85,     0,     0,
+       0,     0,    85,    85,     0,     0,     0,     0,    97,     0,
+       0,   100,     0,     0,     0,    97,     4,     5,     6,     7,
+       8,     9,    10,    11,    12,    13,    14,     0,    15,    16,
+      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
+      27,    28,     0,     0,     0,     0,     0,     0,    29,    30,
+       4,     5,     6,     7,     8,     9,    10,    11,    12,     0,
+      14,     0,     0,     0,     0,     0,     0,     0,     0,     0,
+       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
+       0,    54
 };
 
 static const short yycheck[] =
 {
-      13,     3,     4,     3,     4,    60,    62,    31,     3,    40,
-       5,    31,    36,    68,    16,     6,     7,     8,     9,    10,
-      11,    12,    13,    79,    15,     0,     6,     7,     8,     9,
-      10,    11,    12,    13,    36,    15,    36,    26,    40,    33,
-       5,    35,    64,    65,    32,    36,    37,    32,    32,     3,
-      33,    33,    31,    66,    40,     3,    36,    46,    47,    48,
-      34,    50,    39,     2,    36,    78,    -1,    54,    -1,    90,
-      83,    -1,    -1,    -1,    -1,    88,    -1,    -1,    91,    -1,
-      -1,    -1,    95,     6,     7,     8,     9,    10,    11,    12,
-      13,    14,    15,    -1,    17,    18,    19,    20,    21,    22,
-      23,    24,    25,    26,    27,    28,    29,    30,    -1,    -1,
-      -1,    -1,    -1,    -1,    37,    38
+      14,     3,     4,     3,     4,    32,    27,    64,     0,     3,
+      37,     5,    34,    32,    36,    17,     6,     7,     8,     9,
+      10,    11,    12,    13,    14,    82,    16,    48,    49,    50,
+      41,    52,    62,    66,    67,    37,     5,    37,    33,    41,
+      70,    71,    33,     3,    33,    32,    34,    37,    38,     3,
+       2,    35,    34,    56,    68,    41,    41,    40,    37,    94,
+      -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,    -1,    -1,
+      -1,    -1,    86,    87,    -1,    -1,    -1,    -1,    92,    -1,
+      -1,    95,    -1,    -1,    -1,    99,     6,     7,     8,     9,
+      10,    11,    12,    13,    14,    15,    16,    -1,    18,    19,
+      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
+      30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    38,    39,
+       6,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
+      16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
+      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
+      -1,    37
 };
 
-#if YYDEBUG
 /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
    symbol of state STATE-NUM.  */
 static const unsigned char yystos[] =
 {
-       0,    42,    43,     0,     6,     7,     8,     9,    10,    11,
-      12,    13,    14,    15,    17,    18,    19,    20,    21,    22,
-      23,    24,    25,    26,    27,    28,    29,    30,    37,    38,
-      44,    45,    47,    50,    51,    49,    48,    31,    46,    40,
-       5,     3,     4,    36,    62,    64,    32,    32,    32,     3,
-      65,    65,    36,    45,    56,    57,    58,    33,    67,    31,
-      52,    31,    36,    54,    55,    55,    53,    62,    40,    65,
-      65,    65,    65,    34,    33,    37,    57,    66,    53,     5,
-      64,    54,    62,    53,    59,    39,    64,    60,    61,    33,
-      35,    16,    40,    62,    63,    61,    62
+       0,    43,    44,     0,     6,     7,     8,     9,    10,    11,
+      12,    13,    14,    15,    16,    18,    19,    20,    21,    22,
+      23,    24,    25,    26,    27,    28,    29,    30,    31,    38,
+      39,    45,    46,    49,    52,    53,    51,    50,    32,    47,
+      48,    41,     5,     3,     4,    37,    64,    66,    33,    33,
+      33,     3,    67,    67,    37,    46,    58,    59,    60,    34,
+      69,    32,    54,    32,    37,    56,    57,    57,    55,    64,
+      41,    41,    67,    67,    67,    67,    35,    34,    38,    59,
+      68,    55,     5,    66,    56,    64,    55,    55,    61,    40,
+      66,    62,    63,    34,    36,    17,    41,    64,    65,    63,
+      64
 };
-#endif
 
 #if ! defined (YYSIZE_T) && defined (__SIZE_TYPE__)
 # define YYSIZE_T __SIZE_TYPE__
@@ -687,23 +693,11 @@ while (0)
 
 /* YYLEX -- calling `yylex' with the right arguments.  */
 
-#if YYPURE
-# if YYLSP_NEEDED
-#  ifdef YYLEX_PARAM
-#   define YYLEX		yylex (&yylval, &yylloc, YYLEX_PARAM)
-#  else
-#   define YYLEX		yylex (&yylval, &yylloc)
-#  endif
-# else /* !YYLSP_NEEDED */
-#  ifdef YYLEX_PARAM
-#   define YYLEX		yylex (&yylval, YYLEX_PARAM)
-#  else
-#   define YYLEX		yylex (&yylval)
-#  endif
-# endif /* !YYLSP_NEEDED */
-#else /* !YYPURE */
-# define YYLEX			yylex ()
-#endif /* !YYPURE */
+#ifdef YYLEX_PARAM
+# define YYLEX	yylex (&yylval, &yylloc, YYLEX_PARAM)
+#else
+# define YYLEX	yylex (&yylval, &yylloc, )
+#endif
 
 /* Enable debugging if requested.  */
 #if YYDEBUG
@@ -829,45 +823,25 @@ int yyparse (void *);
 int yyparse (void);
 # endif
 #endif
+static void yydestructor (int symbol_type, YYSTYPE symbol_value);
 
-/* YY_DECL_VARIABLES -- depending whether we use a pure parser,
-   variables are global, or local to YYPARSE.  */
-
-#define YY_DECL_NON_LSP_VARIABLES			\
-/* The lookahead symbol.  */				\
-int yychar;						\
-							\
-/* The semantic value of the lookahead symbol.  */	\
-YYSTYPE yylval;						\
-							\
-/* Number of parse errors so far.  */			\
-int yynerrs;
 
-#if YYLSP_NEEDED
-# define YY_DECL_VARIABLES			\
-YY_DECL_NON_LSP_VARIABLES			\
-						\
-/* Location data for the lookahead symbol.  */	\
-YYLTYPE yylloc;
-#else
-# define YY_DECL_VARIABLES			\
-YY_DECL_NON_LSP_VARIABLES
-#endif
 
-/* If nonreentrant, generate the variables here.  */
-
-#if !YYPURE
-YY_DECL_VARIABLES
-#endif  /* !YYPURE */
 
 int
 yyparse (YYPARSE_PARAM_ARG)
      YYPARSE_PARAM_DECL
 {
-  /* If reentrant, generate the variables here.  */
-#if YYPURE
-  YY_DECL_VARIABLES
-#endif  /* !YYPURE */
+  /* The lookahead symbol.  */
+int yychar;
+
+/* The semantic value of the lookahead symbol.  */
+YYSTYPE yylval;
+
+/* Number of parse errors so far.  */
+int yynerrs;
+/* Location data for the lookahead symbol.  */
+YYLTYPE yylloc;
 
   register int yystate;
   register int yyn;
@@ -895,27 +869,19 @@ yyparse (YYPARSE_PARAM_ARG)
   YYSTYPE *yyvs = yyvsa;
   register YYSTYPE *yyvsp;
 
-#if YYLSP_NEEDED
   /* The location stack.  */
   YYLTYPE yylsa[YYINITDEPTH];
   YYLTYPE *yyls = yylsa;
   YYLTYPE *yylsp;
-#endif
 
-#if YYLSP_NEEDED
-# define YYPOPSTACK   (yyvsp--, yyssp--, yylsp--)
-#else
-# define YYPOPSTACK   (yyvsp--, yyssp--)
-#endif
+#define YYPOPSTACK   (yyvsp--, yyssp--, yylsp--)
 
   YYSIZE_T yystacksize = YYINITDEPTH;
 
   /* The variables used to return semantic value and location from the
      action routines.  */
   YYSTYPE yyval;
-#if YYLSP_NEEDED
   YYLTYPE yyloc;
-#endif
 
   /* When reducing, the number of symbols on the RHS of the reduced
      rule.  */
@@ -935,9 +901,7 @@ yyparse (YYPARSE_PARAM_ARG)
 
   yyssp = yyss;
   yyvsp = yyvs;
-#if YYLSP_NEEDED
   yylsp = yyls;
-#endif
   goto yysetstate;
 
 /*------------------------------------------------------------.
@@ -964,25 +928,18 @@ yyparse (YYPARSE_PARAM_ARG)
 	   memory.  */
 	YYSTYPE *yyvs1 = yyvs;
 	short *yyss1 = yyss;
+	YYLTYPE *yyls1 = yyls;
 
 	/* Each stack pointer address is followed by the size of the
-	   data in use in that stack, in bytes.  */
-# if YYLSP_NEEDED
-	YYLTYPE *yyls1 = yyls;
-	/* This used to be a conditional around just the two extra args,
-	   but that might be undefined if yyoverflow is a macro.  */
+	   data in use in that stack, in bytes.  This used to be a
+	   conditional around just the two extra args, but that might
+	   be undefined if yyoverflow is a macro.  */
 	yyoverflow ("parser stack overflow",
 		    &yyss1, yysize * sizeof (*yyssp),
 		    &yyvs1, yysize * sizeof (*yyvsp),
 		    &yyls1, yysize * sizeof (*yylsp),
 		    &yystacksize);
 	yyls = yyls1;
-# else
-	yyoverflow ("parser stack overflow",
-		    &yyss1, yysize * sizeof (*yyssp),
-		    &yyvs1, yysize * sizeof (*yyvsp),
-		    &yystacksize);
-# endif
 	yyss = yyss1;
 	yyvs = yyvs1;
       }
@@ -1005,9 +962,7 @@ yyparse (YYPARSE_PARAM_ARG)
 	  goto yyoverflowlab;
 	YYSTACK_RELOCATE (yyss);
 	YYSTACK_RELOCATE (yyvs);
-#  if YYLSP_NEEDED
 	YYSTACK_RELOCATE (yyls);
-#  endif
 #  undef YYSTACK_RELOCATE
 	if (yyss1 != yyssa)
 	  YYSTACK_FREE (yyss1);
@@ -1017,9 +972,7 @@ yyparse (YYPARSE_PARAM_ARG)
 
       yyssp = yyss + yysize - 1;
       yyvsp = yyvs + yysize - 1;
-#if YYLSP_NEEDED
       yylsp = yyls + yysize - 1;
-#endif
 
       YYDPRINTF ((stderr, "Stack size increased to %lu\n",
 		  (unsigned long int) yystacksize));
@@ -1123,9 +1076,7 @@ yybackup:
     yychar = YYEMPTY;
 
   *++yyvsp = yylval;
-#if YYLSP_NEEDED
   *++yylsp = yylloc;
-#endif
 
   /* Count tokens shifted since error; after three, turn off error
      status.  */
@@ -1163,10 +1114,8 @@ yyreduce:
      GCC warning that YYVAL may be used uninitialized.  */
   yyval = yyvsp[1-yylen];
 
-#if YYLSP_NEEDED
   /* Default location. */
   YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
-#endif
 
 #if YYDEBUG
   /* We have to keep this `#if YYDEBUG', since we use variables which
@@ -1187,7 +1136,7 @@ yyreduce:
   switch (yyn)
     {
         case 2:
-#line 156 "parse-gram.y"
+#line 160 "parse-gram.y"
     {
       yycontrol->errcode = 0;
       epilogue_set (yyvsp[0].string, yylsp[0]);
@@ -1195,94 +1144,94 @@ yyreduce:
     break;
 
   case 6:
-#line 174 "parse-gram.y"
+#line 178 "parse-gram.y"
     { prologue_augment (yyvsp[0].string, yylsp[0]); }
     break;
 
   case 7:
-#line 175 "parse-gram.y"
+#line 179 "parse-gram.y"
     { debug_flag = 1; }
     break;
 
   case 8:
-#line 176 "parse-gram.y"
+#line 180 "parse-gram.y"
     { muscle_insert (yyvsp[-1].string, yyvsp[0].string); }
     break;
 
   case 9:
-#line 177 "parse-gram.y"
+#line 181 "parse-gram.y"
     { defines_flag = 1; }
     break;
 
   case 10:
-#line 178 "parse-gram.y"
+#line 182 "parse-gram.y"
     { error_verbose = 1; }
     break;
 
   case 11:
-#line 179 "parse-gram.y"
+#line 183 "parse-gram.y"
     { expected_conflicts = yyvsp[0].integer; }
     break;
 
   case 12:
-#line 180 "parse-gram.y"
+#line 184 "parse-gram.y"
     { spec_file_prefix = yyvsp[0].string; }
     break;
 
   case 13:
-#line 181 "parse-gram.y"
+#line 185 "parse-gram.y"
     { locations_flag = 1; }
     break;
 
   case 14:
-#line 182 "parse-gram.y"
+#line 186 "parse-gram.y"
     { spec_name_prefix = yyvsp[0].string; }
     break;
 
   case 15:
-#line 183 "parse-gram.y"
+#line 187 "parse-gram.y"
     { no_lines_flag = 1; }
     break;
 
   case 16:
-#line 184 "parse-gram.y"
+#line 188 "parse-gram.y"
     { spec_outfile = yyvsp[0].string; }
     break;
 
   case 17:
-#line 185 "parse-gram.y"
+#line 189 "parse-gram.y"
     { pure_parser = 1; }
     break;
 
   case 18:
-#line 186 "parse-gram.y"
+#line 190 "parse-gram.y"
     { skeleton = yyvsp[0].string; }
     break;
 
   case 19:
-#line 187 "parse-gram.y"
+#line 191 "parse-gram.y"
     { token_table_flag = 1; }
     break;
 
   case 20:
-#line 188 "parse-gram.y"
+#line 192 "parse-gram.y"
     { report_flag = 1; }
     break;
 
   case 21:
-#line 189 "parse-gram.y"
+#line 193 "parse-gram.y"
     { yacc_flag = 1; }
     break;
 
   case 24:
-#line 196 "parse-gram.y"
+#line 200 "parse-gram.y"
     {
       grammar_start_symbol_set (yyvsp[0].symbol, yylsp[0]);
     }
     break;
 
   case 25:
-#line 200 "parse-gram.y"
+#line 204 "parse-gram.y"
     {
       typed = 1;
       MUSCLE_INSERT_INT ("stype_line", yylsp[0].first_line);
@@ -1291,12 +1240,12 @@ yyreduce:
     break;
 
   case 26:
-#line 206 "parse-gram.y"
+#line 210 "parse-gram.y"
     { current_braced_code = destructor_braced_code; }
     break;
 
   case 27:
-#line 208 "parse-gram.y"
+#line 212 "parse-gram.y"
     {
       symbol_list_t *list;
       for (list = yyvsp[0].list; list; list = list->next)
@@ -1307,25 +1256,28 @@ yyreduce:
     break;
 
   case 28:
-#line 218 "parse-gram.y"
-    { current_class = nterm_sym; }
+#line 220 "parse-gram.y"
+    { current_braced_code = printer_braced_code; }
     break;
 
   case 29:
-#line 219 "parse-gram.y"
+#line 222 "parse-gram.y"
     {
-      current_class = unknown_sym;
-      current_type = NULL;
+      symbol_list_t *list;
+      for (list = yyvsp[0].list; list; list = list->next)
+	symbol_printer_set (list->sym, yyvsp[-1].string, list->location);
+      symbol_list_free (yyvsp[0].list);
+      current_braced_code = action_braced_code;
     }
     break;
 
   case 30:
-#line 223 "parse-gram.y"
-    { current_class = token_sym; }
+#line 232 "parse-gram.y"
+    { current_class = nterm_sym; }
     break;
 
   case 31:
-#line 224 "parse-gram.y"
+#line 233 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
@@ -1333,7 +1285,20 @@ yyreduce:
     break;
 
   case 32:
-#line 229 "parse-gram.y"
+#line 237 "parse-gram.y"
+    { current_class = token_sym; }
+    break;
+
+  case 33:
+#line 238 "parse-gram.y"
+    {
+      current_class = unknown_sym;
+      current_type = NULL;
+    }
+    break;
+
+  case 34:
+#line 243 "parse-gram.y"
     {
       symbol_list_t *list;
       for (list = yyvsp[0].list; list; list = list->next)
@@ -1342,8 +1307,8 @@ yyreduce:
     }
     break;
 
-  case 33:
-#line 239 "parse-gram.y"
+  case 35:
+#line 253 "parse-gram.y"
     {
       symbol_list_t *list;
       ++current_prec;
@@ -1357,58 +1322,58 @@ yyreduce:
     }
     break;
 
-  case 34:
-#line 253 "parse-gram.y"
+  case 36:
+#line 267 "parse-gram.y"
     { yyval.assoc = left_assoc; }
     break;
 
-  case 35:
-#line 254 "parse-gram.y"
+  case 37:
+#line 268 "parse-gram.y"
     { yyval.assoc = right_assoc; }
     break;
 
-  case 36:
-#line 255 "parse-gram.y"
+  case 38:
+#line 269 "parse-gram.y"
     { yyval.assoc = non_assoc; }
     break;
 
-  case 37:
-#line 259 "parse-gram.y"
+  case 39:
+#line 273 "parse-gram.y"
     { current_type = NULL;}
     break;
 
-  case 38:
-#line 260 "parse-gram.y"
+  case 40:
+#line 274 "parse-gram.y"
     { current_type = yyvsp[0].string; }
     break;
 
-  case 39:
-#line 266 "parse-gram.y"
+  case 41:
+#line 280 "parse-gram.y"
     { yyval.list = symbol_list_new (yyvsp[0].symbol, yylsp[0]); }
     break;
 
-  case 40:
-#line 267 "parse-gram.y"
+  case 42:
+#line 281 "parse-gram.y"
     { yyval.list = symbol_list_prepend (yyvsp[-1].list, yyvsp[0].symbol, yylsp[0]); }
     break;
 
-  case 41:
-#line 273 "parse-gram.y"
+  case 43:
+#line 287 "parse-gram.y"
     {
        current_type = yyvsp[0].string;
      }
     break;
 
-  case 42:
-#line 277 "parse-gram.y"
+  case 44:
+#line 291 "parse-gram.y"
     {
        symbol_class_set (yyvsp[0].symbol, current_class);
        symbol_type_set (yyvsp[0].symbol, yylsp[0], current_type);
      }
     break;
 
-  case 43:
-#line 282 "parse-gram.y"
+  case 45:
+#line 296 "parse-gram.y"
     {
       symbol_class_set (yyvsp[-1].symbol, current_class);
       symbol_type_set (yyvsp[-1].symbol, yylsp[-1], current_type);
@@ -1416,8 +1381,8 @@ yyreduce:
     }
     break;
 
-  case 44:
-#line 288 "parse-gram.y"
+  case 46:
+#line 302 "parse-gram.y"
     {
       symbol_class_set (yyvsp[-1].symbol, current_class);
       symbol_type_set (yyvsp[-1].symbol, yylsp[-1], current_type);
@@ -1425,8 +1390,8 @@ yyreduce:
     }
     break;
 
-  case 45:
-#line 294 "parse-gram.y"
+  case 47:
+#line 308 "parse-gram.y"
     {
       symbol_class_set (yyvsp[-2].symbol, current_class);
       symbol_type_set (yyvsp[-2].symbol, yylsp[-2], current_type);
@@ -1435,101 +1400,101 @@ yyreduce:
     }
     break;
 
-  case 46:
-#line 305 "parse-gram.y"
+  case 48:
+#line 319 "parse-gram.y"
     {;}
     break;
 
-  case 47:
-#line 307 "parse-gram.y"
+  case 49:
+#line 321 "parse-gram.y"
     {;}
     break;
 
-  case 52:
-#line 329 "parse-gram.y"
+  case 54:
+#line 343 "parse-gram.y"
     { current_lhs = yyvsp[-1].symbol; current_lhs_location = yylsp[-1]; }
     break;
 
-  case 53:
-#line 330 "parse-gram.y"
+  case 55:
+#line 344 "parse-gram.y"
     {;}
     break;
 
-  case 54:
-#line 334 "parse-gram.y"
+  case 56:
+#line 348 "parse-gram.y"
     { grammar_rule_end (yylsp[0]); }
     break;
 
-  case 55:
-#line 335 "parse-gram.y"
+  case 57:
+#line 349 "parse-gram.y"
     { grammar_rule_end (yylsp[0]); }
     break;
 
-  case 56:
-#line 340 "parse-gram.y"
+  case 58:
+#line 354 "parse-gram.y"
     { grammar_rule_begin (current_lhs, current_lhs_location); }
     break;
 
-  case 57:
-#line 342 "parse-gram.y"
+  case 59:
+#line 356 "parse-gram.y"
     { grammar_current_rule_symbol_append (yyvsp[0].symbol, yylsp[0]); }
     break;
 
-  case 58:
-#line 344 "parse-gram.y"
+  case 60:
+#line 358 "parse-gram.y"
     { grammar_current_rule_action_append (yyvsp[0].string, yylsp[0]); }
     break;
 
-  case 59:
-#line 346 "parse-gram.y"
+  case 61:
+#line 360 "parse-gram.y"
     { grammar_current_rule_prec_set (yyvsp[0].symbol); }
     break;
 
-  case 60:
-#line 350 "parse-gram.y"
+  case 62:
+#line 364 "parse-gram.y"
     { yyval.symbol = yyvsp[0].symbol; }
     break;
 
-  case 61:
-#line 351 "parse-gram.y"
+  case 63:
+#line 365 "parse-gram.y"
     { yyval.symbol = yyvsp[0].symbol; }
     break;
 
-  case 62:
-#line 352 "parse-gram.y"
+  case 64:
+#line 366 "parse-gram.y"
     { yyval.symbol = getsym (yyvsp[0].string, yylsp[0]); }
     break;
 
-  case 63:
-#line 357 "parse-gram.y"
+  case 65:
+#line 371 "parse-gram.y"
     { yyval.string = yyvsp[0].string; }
     break;
 
-  case 64:
-#line 363 "parse-gram.y"
+  case 66:
+#line 377 "parse-gram.y"
     {
       yyval.symbol = getsym (yyvsp[0].string, yylsp[0]);
       symbol_class_set (yyval.symbol, token_sym);
     }
     break;
 
-  case 65:
-#line 372 "parse-gram.y"
+  case 67:
+#line 386 "parse-gram.y"
     {
       yyval.string = yyvsp[0].string + 1;
       yyval.string[strlen (yyval.string) - 1] = '\0';
     }
     break;
 
-  case 66:
-#line 380 "parse-gram.y"
+  case 68:
+#line 394 "parse-gram.y"
     {
       yyval.string = xstrdup ("");
     }
     break;
 
-  case 67:
-#line 384 "parse-gram.y"
+  case 69:
+#line 398 "parse-gram.y"
     {
       yyval.string = yyvsp[0].string;
     }
@@ -1538,14 +1503,12 @@ yyreduce:
 
     }
 
-/* Line 1012 of /usr/local/share/bison/bison.simple.  */
-#line 1543 "parse-gram.c"
+/* Line 996 of /usr/local/share/bison/bison.simple.  */
+#line 1508 "parse-gram.c"
 
   yyvsp -= yylen;
   yyssp -= yylen;
-#if YYLSP_NEEDED
   yylsp -= yylen;
-#endif
 
 #if YYDEBUG
   if (yydebug)
@@ -1559,9 +1522,7 @@ yyreduce:
 #endif
 
   *++yyvsp = yyval;
-#if YYLSP_NEEDED
   *++yylsp = yyloc;
-#endif
 
   /* Now `shift' the result of the reduction.  Determine what state
      that goes to, based on the state we popped back to and the rule
@@ -1649,9 +1610,41 @@ yyerrlab1:
 
       /* Return failure if at end of input.  */
       if (yychar == YYEOF)
-	YYABORT;
+        {
+	  /* Pop the error token.  */
+          YYPOPSTACK;
+	  /* Pop the rest of the stack.  */
+	  while (yyssp > yyss)
+	    {
+#if YYDEBUG
+	      if (yydebug)
+		{
+		  if (yystos[*yyssp] < YYNTOKENS)
+		    {
+		      YYFPRINTF (stderr, "Error: popping token %d (%s",
+				 yytoknum[yystos[*yyssp]],
+				 yytname[yystos[*yyssp]]);
+# ifdef YYPRINT
+		      YYPRINT (stderr, yytoknum[yystos[*yyssp]], *yyvsp);
+# endif
+		      YYFPRINTF (stderr, ")\n");
+		    }
+		  else
+		    {
+		      YYFPRINTF (stderr, "Error: popping nonterminal (%s)\n",
+				 yytname[yystos[*yyssp]]);
+		    }
+		}
+#endif
+	      yydestructor (yystos[*yyssp], *yyvsp);
+	      YYPOPSTACK;
+	    }
+	  YYABORT;
+        }
+
       YYDPRINTF ((stderr, "Discarding token %d (%s).\n",
 		  yychar, yytname[yychar1]));
+      yydestructor (yychar1, yylval);
       yychar = YYEMPTY;
     }
 
@@ -1698,11 +1691,10 @@ yyerrlab1:
 	}
 #endif
 
+      yydestructor (yystos[yystate], *yyvsp);
       yyvsp--;
       yystate = *--yyssp;
-#if YYLSP_NEEDED
       yylsp--;
-#endif
 
 #if YYDEBUG
       if (yydebug)
@@ -1722,9 +1714,7 @@ yyerrlab1:
   YYDPRINTF ((stderr, "Shifting error token, "));
 
   *++yyvsp = yylval;
-#if YYLSP_NEEDED
   *++yylsp = yylloc;
-#endif
 
   yystate = yyn;
   goto yynewstate;
@@ -1744,13 +1734,15 @@ yyabortlab:
   yyresult = 1;
   goto yyreturn;
 
-/*---------------------------------------------.
-| yyoverflowab -- parser overflow comes here.  |
-`---------------------------------------------*/
+#ifndef yyoverflow
+/*----------------------------------------------.
+| yyoverflowlab -- parser overflow comes here.  |
+`----------------------------------------------*/
 yyoverflowlab:
   yyerror ("parser stack overflow");
   yyresult = 2;
   /* Fall through.  */
+#endif
 
 yyreturn:
 #ifndef yyoverflow
@@ -1760,7 +1752,24 @@ yyreturn:
   return yyresult;
 }
 
-#line 393 "parse-gram.y"
+
+/*-------------------------------------------------.
+| Release the memory associated to SYMBOL-NUMBER.  |
+`-------------------------------------------------*/
+
+static void
+yydestructor (int symbol_type, YYSTYPE symbol_value)
+{
+  switch (symbol_type)
+    {
+      default:
+        YYDPRINTF ((stderr, "yydestructor: unknown symbol type: %d (%s)\n",
+		    symbol_type, yytname[symbol_type]));
+        break;
+    }
+}
+
+#line 407 "parse-gram.y"
 
 /*------------------------------------------------------------------.
 | When debugging the parser, display tokens' locations and values.  |
