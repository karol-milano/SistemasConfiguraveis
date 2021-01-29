@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 1.875b.  */
+/* A Bison parser, made by GNU Bison 1.875c.  */
 
 /* Skeleton parser for Yacc-like parsing with Bison,
    Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003 Free Software Foundation, Inc.
@@ -84,29 +84,30 @@
      PERCENT_EXPECT = 276,
      PERCENT_FILE_PREFIX = 277,
      PERCENT_GLR_PARSER = 278,
-     PERCENT_LEX_PARAM = 279,
-     PERCENT_LOCATIONS = 280,
-     PERCENT_NAME_PREFIX = 281,
-     PERCENT_NO_LINES = 282,
-     PERCENT_NONDETERMINISTIC_PARSER = 283,
-     PERCENT_OUTPUT = 284,
-     PERCENT_PARSE_PARAM = 285,
-     PERCENT_PURE_PARSER = 286,
-     PERCENT_SKELETON = 287,
-     PERCENT_START = 288,
-     PERCENT_TOKEN_TABLE = 289,
-     PERCENT_VERBOSE = 290,
-     PERCENT_YACC = 291,
-     TYPE = 292,
-     EQUAL = 293,
-     SEMICOLON = 294,
-     PIPE = 295,
-     ID = 296,
-     ID_COLON = 297,
-     PERCENT_PERCENT = 298,
-     PROLOGUE = 299,
-     EPILOGUE = 300,
-     BRACED_CODE = 301
+     PERCENT_INITIAL_ACTION = 279,
+     PERCENT_LEX_PARAM = 280,
+     PERCENT_LOCATIONS = 281,
+     PERCENT_NAME_PREFIX = 282,
+     PERCENT_NO_LINES = 283,
+     PERCENT_NONDETERMINISTIC_PARSER = 284,
+     PERCENT_OUTPUT = 285,
+     PERCENT_PARSE_PARAM = 286,
+     PERCENT_PURE_PARSER = 287,
+     PERCENT_SKELETON = 288,
+     PERCENT_START = 289,
+     PERCENT_TOKEN_TABLE = 290,
+     PERCENT_VERBOSE = 291,
+     PERCENT_YACC = 292,
+     TYPE = 293,
+     EQUAL = 294,
+     SEMICOLON = 295,
+     PIPE = 296,
+     ID = 297,
+     ID_COLON = 298,
+     PERCENT_PERCENT = 299,
+     PROLOGUE = 300,
+     EPILOGUE = 301,
+     BRACED_CODE = 302
    };
 #endif
 #define GRAM_EOF 0
@@ -131,29 +132,30 @@
 #define PERCENT_EXPECT 276
 #define PERCENT_FILE_PREFIX 277
 #define PERCENT_GLR_PARSER 278
-#define PERCENT_LEX_PARAM 279
-#define PERCENT_LOCATIONS 280
-#define PERCENT_NAME_PREFIX 281
-#define PERCENT_NO_LINES 282
-#define PERCENT_NONDETERMINISTIC_PARSER 283
-#define PERCENT_OUTPUT 284
-#define PERCENT_PARSE_PARAM 285
-#define PERCENT_PURE_PARSER 286
-#define PERCENT_SKELETON 287
-#define PERCENT_START 288
-#define PERCENT_TOKEN_TABLE 289
-#define PERCENT_VERBOSE 290
-#define PERCENT_YACC 291
-#define TYPE 292
-#define EQUAL 293
-#define SEMICOLON 294
-#define PIPE 295
-#define ID 296
-#define ID_COLON 297
-#define PERCENT_PERCENT 298
-#define PROLOGUE 299
-#define EPILOGUE 300
-#define BRACED_CODE 301
+#define PERCENT_INITIAL_ACTION 279
+#define PERCENT_LEX_PARAM 280
+#define PERCENT_LOCATIONS 281
+#define PERCENT_NAME_PREFIX 282
+#define PERCENT_NO_LINES 283
+#define PERCENT_NONDETERMINISTIC_PARSER 284
+#define PERCENT_OUTPUT 285
+#define PERCENT_PARSE_PARAM 286
+#define PERCENT_PURE_PARSER 287
+#define PERCENT_SKELETON 288
+#define PERCENT_START 289
+#define PERCENT_TOKEN_TABLE 290
+#define PERCENT_VERBOSE 291
+#define PERCENT_YACC 292
+#define TYPE 293
+#define EQUAL 294
+#define SEMICOLON 295
+#define PIPE 296
+#define ID 297
+#define ID_COLON 298
+#define PERCENT_PERCENT 299
+#define PROLOGUE 300
+#define EPILOGUE 301
+#define BRACED_CODE 302
 
 
 
@@ -173,9 +175,6 @@
 #include "reader.h"
 #include "symlist.h"
 
-/* Produce verbose syntax errors.  */
-#define YYERROR_VERBOSE 1
-
 #define YYLLOC_DEFAULT(Current, Rhs, N)  (Current) = lloc_default (Rhs, N)
 static YYLTYPE lloc_default (YYLTYPE const *, int);
 
@@ -210,11 +209,11 @@ int current_prec = 0;
 # undef YYERROR_VERBOSE
 # define YYERROR_VERBOSE 1
 #else
-# define YYERROR_VERBOSE 0
+# define YYERROR_VERBOSE 1
 #endif
 
 #if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
-#line 75 "parse-gram.y"
+#line 80 "parse-gram.y"
 typedef union YYSTYPE {
   symbol *symbol;
   symbol_list *list;
@@ -224,7 +223,7 @@ typedef union YYSTYPE {
   uniqstr uniqstr;
 } YYSTYPE;
 /* Line 191 of yacc.c.  */
-#line 228 "parse-gram.c"
+#line 227 "parse-gram.c"
 # define yystype YYSTYPE /* obsolescent; will be withdrawn */
 # define YYSTYPE_IS_DECLARED 1
 # define YYSTYPE_IS_TRIVIAL 1
@@ -248,10 +247,17 @@ typedef struct YYLTYPE
 
 
 /* Line 214 of yacc.c.  */
-#line 252 "parse-gram.c"
+#line 251 "parse-gram.c"
 
 #if ! defined (yyoverflow) || YYERROR_VERBOSE
 
+# ifndef YYFREE
+#  define YYFREE free
+# endif
+# ifndef YYMALLOC
+#  define YYMALLOC malloc
+# endif
+
 /* The parser invokes alloca or malloc; define the necessary symbols.  */
 
 # ifdef YYSTACK_USE_ALLOCA
@@ -276,8 +282,8 @@ typedef struct YYLTYPE
 #   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
 #   define YYSIZE_T size_t
 #  endif
-#  define YYSTACK_ALLOC malloc
-#  define YYSTACK_FREE free
+#  define YYSTACK_ALLOC YYMALLOC
+#  define YYSTACK_FREE YYFREE
 # endif
 #endif /* ! defined (yyoverflow) || YYERROR_VERBOSE */
 
@@ -349,20 +355,20 @@ union yyalloc
 /* YYFINAL -- State number of the termination state. */
 #define YYFINAL  3
 /* YYLAST -- Last index in YYTABLE.  */
-#define YYLAST   148
+#define YYLAST   150
 
 /* YYNTOKENS -- Number of terminals. */
-#define YYNTOKENS  47
+#define YYNTOKENS  48
 /* YYNNTS -- Number of nonterminals. */
 #define YYNNTS  25
 /* YYNRULES -- Number of rules. */
-#define YYNRULES  75
+#define YYNRULES  76
 /* YYNRULES -- Number of states. */
-#define YYNSTATES  103
+#define YYNSTATES  104
 
 /* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
 #define YYUNDEFTOK  2
-#define YYMAXUTOK   301
+#define YYMAXUTOK   302
 
 #define YYTRANSLATE(YYX) 						\
   ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)
@@ -400,7 +406,7 @@ static const unsigned char yytranslate[] =
       15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
       25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
       35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
-      45,    46
+      45,    46,    47
 };
 
 #if YYDEBUG
@@ -409,51 +415,51 @@ static const unsigned char yytranslate[] =
 static const unsigned char yyprhs[] =
 {
        0,     0,     3,     8,     9,    12,    14,    16,    18,    22,
-      24,    26,    29,    33,    35,    37,    39,    43,    45,    47,
-      51,    53,    55,    58,    60,    62,    64,    66,    68,    70,
-      73,    75,    78,    81,    82,    86,    87,    91,    95,    99,
-     101,   103,   105,   106,   108,   110,   113,   115,   117,   120,
-     123,   127,   129,   132,   134,   137,   139,   142,   145,   146,
-     150,   152,   156,   159,   160,   163,   166,   170,   174,   178,
-     180,   182,   184,   186,   188,   189
+      24,    26,    29,    33,    35,    37,    39,    41,    45,    47,
+      49,    53,    55,    57,    60,    62,    64,    66,    68,    70,
+      72,    75,    77,    80,    83,    84,    88,    89,    93,    97,
+     101,   103,   105,   107,   108,   110,   112,   115,   117,   119,
+     122,   125,   129,   131,   134,   136,   139,   141,   144,   147,
+     148,   152,   154,   158,   161,   162,   165,   168,   172,   176,
+     180,   182,   184,   186,   188,   190,   191
 };
 
 /* YYRHS -- A `-1'-separated list of the rules' RHS. */
 static const yysigned_char yyrhs[] =
 {
-      48,     0,    -1,    49,    43,    61,    71,    -1,    -1,    49,
-      50,    -1,    51,    -1,    44,    -1,    17,    -1,    18,    70,
-      70,    -1,    19,    -1,    20,    -1,    21,     4,    -1,    22,
-      38,    70,    -1,    23,    -1,    24,    -1,    25,    -1,    26,
-      38,    70,    -1,    27,    -1,    28,    -1,    29,    38,    70,
-      -1,    30,    -1,    31,    -1,    32,    70,    -1,    34,    -1,
-      35,    -1,    36,    -1,    39,    -1,    55,    -1,    52,    -1,
-      33,    67,    -1,    10,    -1,     8,    58,    -1,     9,    58,
-      -1,    -1,     6,    53,    60,    -1,    -1,     5,    54,    60,
-      -1,     7,    37,    58,    -1,    56,    57,    58,    -1,    11,
-      -1,    12,    -1,    13,    -1,    -1,    37,    -1,    67,    -1,
-      58,    67,    -1,    37,    -1,    41,    -1,    41,     4,    -1,
-      41,    69,    -1,    41,     4,    69,    -1,    59,    -1,    60,
-      59,    -1,    62,    -1,    61,    62,    -1,    63,    -1,    51,
-      39,    -1,     1,    39,    -1,    -1,    42,    64,    65,    -1,
-      66,    -1,    65,    40,    66,    -1,    65,    39,    -1,    -1,
-      66,    67,    -1,    66,    68,    -1,    66,    14,    67,    -1,
-      66,    15,     4,    -1,    66,    16,    37,    -1,    41,    -1,
-      69,    -1,    46,    -1,     3,    -1,     3,    -1,    -1,    43,
-      45,    -1
+      49,     0,    -1,    50,    44,    62,    72,    -1,    -1,    50,
+      51,    -1,    52,    -1,    45,    -1,    17,    -1,    18,    71,
+      71,    -1,    19,    -1,    20,    -1,    21,     4,    -1,    22,
+      39,    71,    -1,    23,    -1,    24,    -1,    25,    -1,    26,
+      -1,    27,    39,    71,    -1,    28,    -1,    29,    -1,    30,
+      39,    71,    -1,    31,    -1,    32,    -1,    33,    71,    -1,
+      35,    -1,    36,    -1,    37,    -1,    40,    -1,    56,    -1,
+      53,    -1,    34,    68,    -1,    10,    -1,     8,    59,    -1,
+       9,    59,    -1,    -1,     6,    54,    61,    -1,    -1,     5,
+      55,    61,    -1,     7,    38,    59,    -1,    57,    58,    59,
+      -1,    11,    -1,    12,    -1,    13,    -1,    -1,    38,    -1,
+      68,    -1,    59,    68,    -1,    38,    -1,    42,    -1,    42,
+       4,    -1,    42,    70,    -1,    42,     4,    70,    -1,    60,
+      -1,    61,    60,    -1,    63,    -1,    62,    63,    -1,    64,
+      -1,    52,    40,    -1,     1,    40,    -1,    -1,    43,    65,
+      66,    -1,    67,    -1,    66,    41,    67,    -1,    66,    40,
+      -1,    -1,    67,    68,    -1,    67,    69,    -1,    67,    14,
+      68,    -1,    67,    15,     4,    -1,    67,    16,    38,    -1,
+      42,    -1,    70,    -1,    47,    -1,     3,    -1,     3,    -1,
+      -1,    44,    46,    -1
 };
 
 /* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
 static const unsigned short yyrline[] =
 {
-       0,   162,   162,   170,   172,   176,   177,   178,   179,   180,
-     181,   182,   183,   184,   186,   187,   188,   189,   190,   191,
-     192,   193,   194,   195,   196,   197,   198,   202,   203,   204,
-     208,   214,   221,   231,   231,   236,   236,   241,   251,   266,
-     267,   268,   272,   273,   279,   280,   285,   289,   294,   300,
-     306,   317,   318,   327,   328,   334,   335,   340,   347,   347,
-     351,   352,   353,   358,   359,   361,   363,   365,   367,   372,
-     373,   377,   383,   392,   399,   401
+       0,   170,   170,   178,   180,   184,   185,   186,   187,   188,
+     189,   190,   191,   192,   197,   201,   202,   203,   204,   205,
+     206,   207,   208,   209,   210,   211,   212,   213,   217,   218,
+     219,   223,   229,   236,   246,   246,   251,   251,   256,   266,
+     281,   282,   283,   287,   288,   294,   295,   300,   304,   309,
+     315,   321,   332,   333,   342,   343,   349,   350,   355,   362,
+     362,   366,   367,   368,   373,   374,   376,   378,   380,   382,
+     387,   388,   392,   398,   407,   414,   416
 };
 #endif
 
@@ -467,18 +473,19 @@ static const char *const yytname[] =
   "\"%printer {...}\"", "\"%union {...}\"", "\"%left\"", "\"%right\"",
   "\"%nonassoc\"", "\"%prec\"", "\"%dprec\"", "\"%merge\"", "\"%debug\"",
   "\"%define\"", "\"%defines\"", "\"%error-verbose\"", "\"%expect\"",
-  "\"%file-prefix\"", "\"%glr-parser\"", "\"%lex-param {...}\"",
-  "\"%locations\"", "\"%name-prefix\"", "\"%no-lines\"",
-  "\"%nondeterministic-parser\"", "\"%output\"", "\"%parse-param {...}\"",
-  "\"%pure-parser\"", "\"%skeleton\"", "\"%start\"", "\"%token-table\"",
-  "\"%verbose\"", "\"%yacc\"", "\"type\"", "\"=\"", "\";\"", "\"|\"",
-  "\"identifier\"", "\"identifier:\"", "\"%%\"", "\"%{...%}\"",
-  "\"epilogue\"", "\"{...}\"", "$accept", "input", "declarations",
-  "declaration", "grammar_declaration", "symbol_declaration", "@1", "@2",
-  "precedence_declaration", "precedence_declarator", "type.opt",
-  "symbols.1", "symbol_def", "symbol_defs.1", "grammar",
-  "rules_or_grammar_declaration", "rules", "@3", "rhses.1", "rhs",
-  "symbol", "action", "string_as_id", "string_content", "epilogue.opt", 0
+  "\"%file-prefix\"", "\"%glr-parser\"", "\"%initial-action {...}\"",
+  "\"%lex-param {...}\"", "\"%locations\"", "\"%name-prefix\"",
+  "\"%no-lines\"", "\"%nondeterministic-parser\"", "\"%output\"",
+  "\"%parse-param {...}\"", "\"%pure-parser\"", "\"%skeleton\"",
+  "\"%start\"", "\"%token-table\"", "\"%verbose\"", "\"%yacc\"",
+  "\"type\"", "\"=\"", "\";\"", "\"|\"", "\"identifier\"",
+  "\"identifier:\"", "\"%%\"", "\"%{...%}\"", "\"epilogue\"", "\"{...}\"",
+  "$accept", "input", "declarations", "declaration", "grammar_declaration",
+  "symbol_declaration", "@1", "@2", "precedence_declaration",
+  "precedence_declarator", "type.opt", "symbols.1", "symbol_def",
+  "symbol_defs.1", "grammar", "rules_or_grammar_declaration", "rules",
+  "@3", "rhses.1", "rhs", "symbol", "action", "string_as_id",
+  "string_content", "epilogue.opt", 0
 };
 #endif
 
@@ -491,34 +498,34 @@ static const unsigned short yytoknum[] =
      265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
      275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
      285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
-     295,   296,   297,   298,   299,   300,   301
+     295,   296,   297,   298,   299,   300,   301,   302
 };
 # endif
 
 /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
 static const unsigned char yyr1[] =
 {
-       0,    47,    48,    49,    49,    50,    50,    50,    50,    50,
-      50,    50,    50,    50,    50,    50,    50,    50,    50,    50,
-      50,    50,    50,    50,    50,    50,    50,    51,    51,    51,
-      51,    51,    51,    53,    52,    54,    52,    52,    55,    56,
-      56,    56,    57,    57,    58,    58,    59,    59,    59,    59,
-      59,    60,    60,    61,    61,    62,    62,    62,    64,    63,
-      65,    65,    65,    66,    66,    66,    66,    66,    66,    67,
-      67,    68,    69,    70,    71,    71
+       0,    48,    49,    50,    50,    51,    51,    51,    51,    51,
+      51,    51,    51,    51,    51,    51,    51,    51,    51,    51,
+      51,    51,    51,    51,    51,    51,    51,    51,    52,    52,
+      52,    52,    52,    52,    54,    53,    55,    53,    53,    56,
+      57,    57,    57,    58,    58,    59,    59,    60,    60,    60,
+      60,    60,    61,    61,    62,    62,    63,    63,    63,    65,
+      64,    66,    66,    66,    67,    67,    67,    67,    67,    67,
+      68,    68,    69,    70,    71,    72,    72
 };
 
 /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
 static const unsigned char yyr2[] =
 {
        0,     2,     4,     0,     2,     1,     1,     1,     3,     1,
-       1,     2,     3,     1,     1,     1,     3,     1,     1,     3,
-       1,     1,     2,     1,     1,     1,     1,     1,     1,     2,
-       1,     2,     2,     0,     3,     0,     3,     3,     3,     1,
-       1,     1,     0,     1,     1,     2,     1,     1,     2,     2,
-       3,     1,     2,     1,     2,     1,     2,     2,     0,     3,
-       1,     3,     2,     0,     2,     2,     3,     3,     3,     1,
-       1,     1,     1,     1,     0,     2
+       1,     2,     3,     1,     1,     1,     1,     3,     1,     1,
+       3,     1,     1,     2,     1,     1,     1,     1,     1,     1,
+       2,     1,     2,     2,     0,     3,     0,     3,     3,     3,
+       1,     1,     1,     0,     1,     1,     2,     1,     1,     2,
+       2,     3,     1,     2,     1,     2,     1,     2,     2,     0,
+       3,     1,     3,     2,     0,     2,     2,     3,     3,     3,
+       1,     1,     1,     1,     1,     0,     2
 };
 
 /* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
@@ -526,25 +533,25 @@ static const unsigned char yyr2[] =
    means the default is an error.  */
 static const unsigned char yydefact[] =
 {
-       3,     0,     0,     1,    35,    33,     0,     0,     0,    30,
-      39,    40,    41,     7,     0,     9,    10,     0,     0,    13,
-      14,    15,     0,    17,    18,     0,    20,    21,     0,     0,
-      23,    24,    25,    26,     0,     6,     4,     5,    28,    27,
-      42,     0,     0,     0,    72,    69,    31,    44,    70,    32,
-      73,     0,    11,     0,     0,     0,    22,    29,     0,    58,
-       0,     0,    53,    55,    43,     0,    46,    47,    51,    36,
-      34,    37,    45,     8,    12,    16,    19,    57,    63,    56,
-       0,    54,     2,    38,    48,    49,    52,    59,    60,    75,
-      50,    62,    63,     0,     0,     0,    71,    64,    65,    61,
-      66,    67,    68
+       3,     0,     0,     1,    36,    34,     0,     0,     0,    31,
+      40,    41,    42,     7,     0,     9,    10,     0,     0,    13,
+      14,    15,    16,     0,    18,    19,     0,    21,    22,     0,
+       0,    24,    25,    26,    27,     0,     6,     4,     5,    29,
+      28,    43,     0,     0,     0,    73,    70,    32,    45,    71,
+      33,    74,     0,    11,     0,     0,     0,    23,    30,     0,
+      59,     0,     0,    54,    56,    44,     0,    47,    48,    52,
+      37,    35,    38,    46,     8,    12,    17,    20,    58,    64,
+      57,     0,    55,     2,    39,    49,    50,    53,    60,    61,
+      76,    51,    63,    64,     0,     0,     0,    72,    65,    66,
+      62,    67,    68,    69
 };
 
 /* YYDEFGOTO[NTERM-NUM]. */
 static const yysigned_char yydefgoto[] =
 {
-      -1,     1,     2,    36,    60,    38,    42,    41,    39,    40,
-      65,    46,    68,    69,    61,    62,    63,    78,    87,    88,
-      47,    98,    48,    51,    82
+      -1,     1,     2,    37,    61,    39,    43,    42,    40,    41,
+      66,    47,    69,    70,    62,    63,    64,    79,    88,    89,
+      48,    99,    49,    52,    83
 };
 
 /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
@@ -552,85 +559,87 @@ static const yysigned_char yydefgoto[] =
 #define YYPACT_NINF -64
 static const yysigned_char yypact[] =
 {
-     -64,    32,   104,   -64,   -64,   -64,   -21,    16,    16,   -64,
-     -64,   -64,   -64,   -64,    30,   -64,   -64,    33,    -4,   -64,
-     -64,   -64,     0,   -64,   -64,     1,   -64,   -64,    30,    16,
-     -64,   -64,   -64,   -64,    66,   -64,   -64,   -64,   -64,   -64,
-       3,   -15,   -15,    16,   -64,   -64,    16,   -64,   -64,    16,
-     -64,    30,   -64,    30,    30,    30,   -64,   -64,     4,   -64,
-       8,     2,   -64,   -64,   -64,    16,   -64,    21,   -64,   -15,
-     -15,    16,   -64,   -64,   -64,   -64,   -64,   -64,   -64,   -64,
-       6,   -64,   -64,    16,    38,   -64,   -64,   -34,    15,   -64,
-     -64,   -64,   -64,    16,    48,    18,   -64,   -64,   -64,    15,
-     -64,   -64,   -64
+     -64,    21,   105,   -64,   -64,   -64,   -14,    -2,    -2,   -64,
+     -64,   -64,   -64,   -64,    25,   -64,   -64,    30,    -3,   -64,
+     -64,   -64,   -64,     0,   -64,   -64,     2,   -64,   -64,    25,
+      -2,   -64,   -64,   -64,   -64,    66,   -64,   -64,   -64,   -64,
+     -64,     5,   -19,   -19,    -2,   -64,   -64,    -2,   -64,   -64,
+      -2,   -64,    25,   -64,    25,    25,    25,   -64,   -64,    -5,
+     -64,     4,     3,   -64,   -64,   -64,    -2,   -64,    23,   -64,
+     -19,   -19,    -2,   -64,   -64,   -64,   -64,   -64,   -64,   -64,
+     -64,    -1,   -64,   -64,    -2,    46,   -64,   -64,   -34,    15,
+     -64,   -64,   -64,   -64,    -2,    49,    17,   -64,   -64,   -64,
+      15,   -64,   -64,   -64
 };
 
 /* YYPGOTO[NTERM-NUM].  */
 static const yysigned_char yypgoto[] =
 {
-     -64,   -64,   -64,   -64,    51,   -64,   -64,   -64,   -64,   -64,
-     -64,    -7,   -42,    20,   -64,    -1,   -64,   -64,   -64,   -27,
-     -29,   -64,   -63,    -5,   -64
+     -64,   -64,   -64,   -64,    54,   -64,   -64,   -64,   -64,   -64,
+     -64,    -6,   -38,    18,   -64,     1,   -64,   -64,   -64,   -35,
+     -30,   -64,   -63,    -4,   -64
 };
 
 /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
    positive, shift that token.  If negative, reduce the rule which
    number is the opposite.  If zero, do what YYDEFACT says.
    If YYTABLE_NINF, syntax error.  */
-#define YYTABLE_NINF -75
+#define YYTABLE_NINF -76
 static const yysigned_char yytable[] =
 {
-      57,    49,   -74,    58,    85,    91,    92,     4,     5,     6,
-       7,     8,     9,    10,    11,    12,    43,    72,    44,    44,
-      72,    90,    66,    56,    44,    84,    67,    86,    86,    93,
-      94,    95,     3,    50,    53,    29,    71,    52,    54,    55,
-      64,    44,    72,    77,    59,    80,    73,    79,    74,    75,
-      76,    89,   101,    37,    72,   102,    45,    45,    83,    97,
-      81,    96,    70,     0,   100,    99,     0,    58,     0,     0,
-      97,     4,     5,     6,     7,     8,     9,    10,    11,    12,
+      58,    45,    50,   -75,    59,    86,    92,    93,     4,     5,
+       6,     7,     8,     9,    10,    11,    12,    73,    45,    67,
+      73,     3,    91,    68,    44,    57,    45,    85,    51,    94,
+      95,    96,    87,    87,    53,    78,    54,    30,    72,    55,
+      46,    56,    73,    65,    80,    90,    60,    81,    74,    45,
+      75,    76,    77,   102,    73,   103,    38,    46,   100,    98,
+      84,    71,    97,    82,   101,     0,     0,    59,     0,     0,
+      98,     4,     5,     6,     7,     8,     9,    10,    11,    12,
        0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
-       0,     0,     0,     0,     0,     0,     0,     0,     0,    29,
-       0,     0,     0,     0,     0,     0,     0,     0,    59,     4,
-       5,     6,     7,     8,     9,    10,    11,    12,     0,     0,
-       0,    13,    14,    15,    16,    17,    18,    19,    20,    21,
-      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
-      32,     0,     0,    33,     0,     0,     0,    34,    35
+       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
+      30,     0,     0,     0,     0,     0,     0,     0,     0,    60,
+       4,     5,     6,     7,     8,     9,    10,    11,    12,     0,
+       0,     0,    13,    14,    15,    16,    17,    18,    19,    20,
+      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
+      31,    32,    33,     0,     0,    34,     0,     0,     0,    35,
+      36
 };
 
 static const yysigned_char yycheck[] =
 {
-      29,     8,     0,     1,    67,    39,    40,     5,     6,     7,
-       8,     9,    10,    11,    12,    13,    37,    46,     3,     3,
-      49,    84,    37,    28,     3,     4,    41,    69,    70,    14,
-      15,    16,     0,     3,    38,    33,    43,     4,    38,    38,
-      37,     3,    71,    39,    42,    43,    51,    39,    53,    54,
-      55,    45,     4,     2,    83,    37,    41,    41,    65,    88,
-      61,    46,    42,    -1,    93,    92,    -1,     1,    -1,    -1,
-      99,     5,     6,     7,     8,     9,    10,    11,    12,    13,
+      30,     3,     8,     0,     1,    68,    40,    41,     5,     6,
+       7,     8,     9,    10,    11,    12,    13,    47,     3,    38,
+      50,     0,    85,    42,    38,    29,     3,     4,     3,    14,
+      15,    16,    70,    71,     4,    40,    39,    34,    44,    39,
+      42,    39,    72,    38,    40,    46,    43,    44,    52,     3,
+      54,    55,    56,     4,    84,    38,     2,    42,    93,    89,
+      66,    43,    47,    62,    94,    -1,    -1,     1,    -1,    -1,
+     100,     5,     6,     7,     8,     9,    10,    11,    12,    13,
+      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
-      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,
-      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,     5,
-       6,     7,     8,     9,    10,    11,    12,    13,    -1,    -1,
-      -1,    17,    18,    19,    20,    21,    22,    23,    24,    25,
-      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
-      36,    -1,    -1,    39,    -1,    -1,    -1,    43,    44
+      34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,
+       5,     6,     7,     8,     9,    10,    11,    12,    13,    -1,
+      -1,    -1,    17,    18,    19,    20,    21,    22,    23,    24,
+      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
+      35,    36,    37,    -1,    -1,    40,    -1,    -1,    -1,    44,
+      45
 };
 
 /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
    symbol of state STATE-NUM.  */
 static const unsigned char yystos[] =
 {
-       0,    48,    49,     0,     5,     6,     7,     8,     9,    10,
+       0,    49,    50,     0,     5,     6,     7,     8,     9,    10,
       11,    12,    13,    17,    18,    19,    20,    21,    22,    23,
       24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
-      34,    35,    36,    39,    43,    44,    50,    51,    52,    55,
-      56,    54,    53,    37,     3,    41,    58,    67,    69,    58,
-       3,    70,     4,    38,    38,    38,    70,    67,     1,    42,
-      51,    61,    62,    63,    37,    57,    37,    41,    59,    60,
-      60,    58,    67,    70,    70,    70,    70,    39,    64,    39,
-      43,    62,    71,    58,     4,    69,    59,    65,    66,    45,
-      69,    39,    40,    14,    15,    16,    46,    67,    68,    66,
-      67,     4,    37
+      34,    35,    36,    37,    40,    44,    45,    51,    52,    53,
+      56,    57,    55,    54,    38,     3,    42,    59,    68,    70,
+      59,     3,    71,     4,    39,    39,    39,    71,    68,     1,
+      43,    52,    62,    63,    64,    38,    58,    38,    42,    60,
+      61,    61,    59,    68,    71,    71,    71,    71,    40,    65,
+      40,    44,    63,    72,    59,     4,    70,    60,    66,    67,
+      46,    70,    40,    41,    14,    15,    16,    47,    68,    69,
+      67,    68,     4,    38
 };
 
 #if ! defined (YYSIZE_T) && defined (__SIZE_TYPE__)
@@ -691,11 +700,11 @@ while (0)
    are run).  */
 
 #ifndef YYLLOC_DEFAULT
-# define YYLLOC_DEFAULT(Current, Rhs, N)         \
-  Current.first_line   = Rhs[1].first_line;      \
-  Current.first_column = Rhs[1].first_column;    \
-  Current.last_line    = Rhs[N].last_line;       \
-  Current.last_column  = Rhs[N].last_column;
+# define YYLLOC_DEFAULT(Current, Rhs, N)		\
+   ((Current).first_line   = (Rhs)[1].first_line,	\
+    (Current).first_column = (Rhs)[1].first_column,	\
+    (Current).last_line    = (Rhs)[N].last_line,	\
+    (Current).last_column  = (Rhs)[N].last_column)
 #endif
 
 /* YYLEX -- calling `yylex' with the right arguments.  */
@@ -739,7 +748,7 @@ do {								\
 
 /*------------------------------------------------------------------.
 | yy_stack_print -- Print the state stack from its BOTTOM up to its |
-| TOP (cinluded).                                                   |
+| TOP (included).                                                   |
 `------------------------------------------------------------------*/
 
 #if defined (__STDC__) || defined (__cplusplus)
@@ -1065,6 +1074,18 @@ YYLTYPE yylloc;
   yyssp = yyss;
   yyvsp = yyvs;
   yylsp = yyls;
+
+  /* User initialization code. */
+  #line 70 "parse-gram.y"
+{
+  /* Bison's grammar can initial empty locations, hence a default
+     location is needed. */
+  (*yylsp).start.file   = (*yylsp).end.file   = current_file;
+  (*yylsp).start.line   = (*yylsp).end.line   = 1;
+  (*yylsp).start.column = (*yylsp).end.column = 0;
+}
+/* Line 818 of yacc.c.  */
+#line 1089 "parse-gram.c"
   goto yysetstate;
 
 /*------------------------------------------------------------.
@@ -1247,120 +1268,129 @@ yyreduce:
   yyval = yyvsp[1-yylen];
 
   /* Default location. */
-  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
+  YYLLOC_DEFAULT (yyloc, yylsp - yylen, yylen);
   YY_REDUCE_PRINT (yyn);
   switch (yyn)
     {
         case 6:
-#line 177 "parse-gram.y"
+#line 185 "parse-gram.y"
     { prologue_augment (yyvsp[0].chars, yylsp[0]); }
     break;
 
   case 7:
-#line 178 "parse-gram.y"
+#line 186 "parse-gram.y"
     { debug_flag = true; }
     break;
 
   case 8:
-#line 179 "parse-gram.y"
+#line 187 "parse-gram.y"
     { muscle_insert (yyvsp[-1].chars, yyvsp[0].chars); }
     break;
 
   case 9:
-#line 180 "parse-gram.y"
+#line 188 "parse-gram.y"
     { defines_flag = true; }
     break;
 
   case 10:
-#line 181 "parse-gram.y"
+#line 189 "parse-gram.y"
     { error_verbose = true; }
     break;
 
   case 11:
-#line 182 "parse-gram.y"
+#line 190 "parse-gram.y"
     { expected_conflicts = yyvsp[0].integer; }
     break;
 
   case 12:
-#line 183 "parse-gram.y"
+#line 191 "parse-gram.y"
     { spec_file_prefix = yyvsp[0].chars; }
     break;
 
   case 13:
-#line 184 "parse-gram.y"
-    { nondeterministic_parser = true;
-                                             glr_parser = true; }
+#line 193 "parse-gram.y"
+    {
+    nondeterministic_parser = true;
+    glr_parser = true;
+  }
     break;
 
   case 14:
-#line 186 "parse-gram.y"
-    { add_param ("lex_param", yyvsp[0].chars, yylsp[0]); }
+#line 198 "parse-gram.y"
+    {
+    muscle_code_grow ("initial_action", yyvsp[0].chars, yylsp[0]);
+  }
     break;
 
   case 15:
-#line 187 "parse-gram.y"
-    { locations_flag = true; }
+#line 201 "parse-gram.y"
+    { add_param ("lex_param", yyvsp[0].chars, yylsp[0]); }
     break;
 
   case 16:
-#line 188 "parse-gram.y"
-    { spec_name_prefix = yyvsp[0].chars; }
+#line 202 "parse-gram.y"
+    { locations_flag = true; }
     break;
 
   case 17:
-#line 189 "parse-gram.y"
-    { no_lines_flag = true; }
+#line 203 "parse-gram.y"
+    { spec_name_prefix = yyvsp[0].chars; }
     break;
 
   case 18:
-#line 190 "parse-gram.y"
-    { nondeterministic_parser = true; }
+#line 204 "parse-gram.y"
+    { no_lines_flag = true; }
     break;
 
   case 19:
-#line 191 "parse-gram.y"
-    { spec_outfile = yyvsp[0].chars; }
+#line 205 "parse-gram.y"
+    { nondeterministic_parser = true; }
     break;
 
   case 20:
-#line 192 "parse-gram.y"
-    { add_param ("parse_param", yyvsp[0].chars, yylsp[0]); }
+#line 206 "parse-gram.y"
+    { spec_outfile = yyvsp[0].chars; }
     break;
 
   case 21:
-#line 193 "parse-gram.y"
-    { pure_parser = true; }
+#line 207 "parse-gram.y"
+    { add_param ("parse_param", yyvsp[0].chars, yylsp[0]); }
     break;
 
   case 22:
-#line 194 "parse-gram.y"
-    { skeleton = yyvsp[0].chars; }
+#line 208 "parse-gram.y"
+    { pure_parser = true; }
     break;
 
   case 23:
-#line 195 "parse-gram.y"
-    { token_table_flag = true; }
+#line 209 "parse-gram.y"
+    { skeleton = yyvsp[0].chars; }
     break;
 
   case 24:
-#line 196 "parse-gram.y"
-    { report_flag = report_states; }
+#line 210 "parse-gram.y"
+    { token_table_flag = true; }
     break;
 
   case 25:
-#line 197 "parse-gram.y"
+#line 211 "parse-gram.y"
+    { report_flag = report_states; }
+    break;
+
+  case 26:
+#line 212 "parse-gram.y"
     { yacc_flag = true; }
     break;
 
-  case 29:
-#line 205 "parse-gram.y"
+  case 30:
+#line 220 "parse-gram.y"
     {
       grammar_start_symbol_set (yyvsp[0].symbol, yylsp[0]);
     }
     break;
 
-  case 30:
-#line 209 "parse-gram.y"
+  case 31:
+#line 224 "parse-gram.y"
     {
       typed = true;
       MUSCLE_INSERT_INT ("stype_line", yylsp[0].start.line);
@@ -1368,8 +1398,8 @@ yyreduce:
     }
     break;
 
-  case 31:
-#line 215 "parse-gram.y"
+  case 32:
+#line 230 "parse-gram.y"
     {
       symbol_list *list;
       for (list = yyvsp[0].list; list; list = list->next)
@@ -1378,8 +1408,8 @@ yyreduce:
     }
     break;
 
-  case 32:
-#line 222 "parse-gram.y"
+  case 33:
+#line 237 "parse-gram.y"
     {
       symbol_list *list;
       for (list = yyvsp[0].list; list; list = list->next)
@@ -1388,34 +1418,34 @@ yyreduce:
     }
     break;
 
-  case 33:
-#line 231 "parse-gram.y"
+  case 34:
+#line 246 "parse-gram.y"
     { current_class = nterm_sym; }
     break;
 
-  case 34:
-#line 232 "parse-gram.y"
+  case 35:
+#line 247 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
     break;
 
-  case 35:
-#line 236 "parse-gram.y"
+  case 36:
+#line 251 "parse-gram.y"
     { current_class = token_sym; }
     break;
 
-  case 36:
-#line 237 "parse-gram.y"
+  case 37:
+#line 252 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
     break;
 
-  case 37:
-#line 242 "parse-gram.y"
+  case 38:
+#line 257 "parse-gram.y"
     {
       symbol_list *list;
       for (list = yyvsp[0].list; list; list = list->next)
@@ -1424,8 +1454,8 @@ yyreduce:
     }
     break;
 
-  case 38:
-#line 252 "parse-gram.y"
+  case 39:
+#line 267 "parse-gram.y"
     {
       symbol_list *list;
       ++current_prec;
@@ -1439,58 +1469,58 @@ yyreduce:
     }
     break;
 
-  case 39:
-#line 266 "parse-gram.y"
+  case 40:
+#line 281 "parse-gram.y"
     { yyval.assoc = left_assoc; }
     break;
 
-  case 40:
-#line 267 "parse-gram.y"
+  case 41:
+#line 282 "parse-gram.y"
     { yyval.assoc = right_assoc; }
     break;
 
-  case 41:
-#line 268 "parse-gram.y"
+  case 42:
+#line 283 "parse-gram.y"
     { yyval.assoc = non_assoc; }
     break;
 
-  case 42:
-#line 272 "parse-gram.y"
+  case 43:
+#line 287 "parse-gram.y"
     { current_type = NULL; }
     break;
 
-  case 43:
-#line 273 "parse-gram.y"
+  case 44:
+#line 288 "parse-gram.y"
     { current_type = yyvsp[0].uniqstr; }
     break;
 
-  case 44:
-#line 279 "parse-gram.y"
+  case 45:
+#line 294 "parse-gram.y"
     { yyval.list = symbol_list_new (yyvsp[0].symbol, yylsp[0]); }
     break;
 
-  case 45:
-#line 280 "parse-gram.y"
+  case 46:
+#line 295 "parse-gram.y"
     { yyval.list = symbol_list_prepend (yyvsp[-1].list, yyvsp[0].symbol, yylsp[0]); }
     break;
 
-  case 46:
-#line 286 "parse-gram.y"
+  case 47:
+#line 301 "parse-gram.y"
     {
        current_type = yyvsp[0].uniqstr;
      }
     break;
 
-  case 47:
-#line 290 "parse-gram.y"
+  case 48:
+#line 305 "parse-gram.y"
     {
        symbol_class_set (yyvsp[0].symbol, current_class, yylsp[0]);
        symbol_type_set (yyvsp[0].symbol, current_type, yylsp[0]);
      }
     break;
 
-  case 48:
-#line 295 "parse-gram.y"
+  case 49:
+#line 310 "parse-gram.y"
     {
       symbol_class_set (yyvsp[-1].symbol, current_class, yylsp[-1]);
       symbol_type_set (yyvsp[-1].symbol, current_type, yylsp[-1]);
@@ -1498,8 +1528,8 @@ yyreduce:
     }
     break;
 
-  case 49:
-#line 301 "parse-gram.y"
+  case 50:
+#line 316 "parse-gram.y"
     {
       symbol_class_set (yyvsp[-1].symbol, current_class, yylsp[-1]);
       symbol_type_set (yyvsp[-1].symbol, current_type, yylsp[-1]);
@@ -1507,8 +1537,8 @@ yyreduce:
     }
     break;
 
-  case 50:
-#line 307 "parse-gram.y"
+  case 51:
+#line 322 "parse-gram.y"
     {
       symbol_class_set (yyvsp[-2].symbol, current_class, yylsp[-2]);
       symbol_type_set (yyvsp[-2].symbol, current_type, yylsp[-2]);
@@ -1517,101 +1547,101 @@ yyreduce:
     }
     break;
 
-  case 56:
-#line 336 "parse-gram.y"
+  case 57:
+#line 351 "parse-gram.y"
     {
       if (yacc_flag)
 	complain_at (yyloc, _("POSIX forbids declarations in the grammar"));
     }
     break;
 
-  case 57:
-#line 341 "parse-gram.y"
+  case 58:
+#line 356 "parse-gram.y"
     {
       yyerrok;
     }
     break;
 
-  case 58:
-#line 347 "parse-gram.y"
+  case 59:
+#line 362 "parse-gram.y"
     { current_lhs = yyvsp[0].symbol; current_lhs_location = yylsp[0]; }
     break;
 
-  case 60:
-#line 351 "parse-gram.y"
+  case 61:
+#line 366 "parse-gram.y"
     { grammar_rule_end (yylsp[0]); }
     break;
 
-  case 61:
-#line 352 "parse-gram.y"
+  case 62:
+#line 367 "parse-gram.y"
     { grammar_rule_end (yylsp[0]); }
     break;
 
-  case 63:
-#line 358 "parse-gram.y"
+  case 64:
+#line 373 "parse-gram.y"
     { grammar_rule_begin (current_lhs, current_lhs_location); }
     break;
 
-  case 64:
-#line 360 "parse-gram.y"
+  case 65:
+#line 375 "parse-gram.y"
     { grammar_current_rule_symbol_append (yyvsp[0].symbol, yylsp[0]); }
     break;
 
-  case 65:
-#line 362 "parse-gram.y"
+  case 66:
+#line 377 "parse-gram.y"
     { grammar_current_rule_action_append (yyvsp[0].chars, yylsp[0]); }
     break;
 
-  case 66:
-#line 364 "parse-gram.y"
+  case 67:
+#line 379 "parse-gram.y"
     { grammar_current_rule_prec_set (yyvsp[0].symbol, yylsp[0]); }
     break;
 
-  case 67:
-#line 366 "parse-gram.y"
+  case 68:
+#line 381 "parse-gram.y"
     { grammar_current_rule_dprec_set (yyvsp[0].integer, yylsp[0]); }
     break;
 
-  case 68:
-#line 368 "parse-gram.y"
+  case 69:
+#line 383 "parse-gram.y"
     { grammar_current_rule_merge_set (yyvsp[0].uniqstr, yylsp[0]); }
     break;
 
-  case 69:
-#line 372 "parse-gram.y"
+  case 70:
+#line 387 "parse-gram.y"
     { yyval.symbol = yyvsp[0].symbol; }
     break;
 
-  case 70:
-#line 373 "parse-gram.y"
+  case 71:
+#line 388 "parse-gram.y"
     { yyval.symbol = yyvsp[0].symbol; }
     break;
 
-  case 71:
-#line 378 "parse-gram.y"
+  case 72:
+#line 393 "parse-gram.y"
     { yyval.chars = yyvsp[0].chars; }
     break;
 
-  case 72:
-#line 384 "parse-gram.y"
+  case 73:
+#line 399 "parse-gram.y"
     {
       yyval.symbol = symbol_get (yyvsp[0].chars, yylsp[0]);
       symbol_class_set (yyval.symbol, token_sym, yylsp[0]);
     }
     break;
 
-  case 73:
-#line 393 "parse-gram.y"
+  case 74:
+#line 408 "parse-gram.y"
     {
       yyval.chars = yyvsp[0].chars + 1;
       yyval.chars[strlen (yyval.chars) - 1] = '\0';
     }
     break;
 
-  case 75:
-#line 402 "parse-gram.y"
+  case 76:
+#line 417 "parse-gram.y"
     {
-      epilogue_augment (yyvsp[0].chars, yylsp[0]);
+      muscle_code_grow ("epilogue", yyvsp[0].chars, yylsp[0]);
       scanner_last_string_free ();
     }
     break;
@@ -1619,8 +1649,8 @@ yyreduce:
 
     }
 
-/* Line 993 of yacc.c.  */
-#line 1624 "parse-gram.c"
+/* Line 1010 of yacc.c.  */
+#line 1654 "parse-gram.c"
 
   yyvsp -= yylen;
   yyssp -= yylen;
@@ -1809,7 +1839,7 @@ yyerrlab1:
   YYDPRINTF ((stderr, "Shifting error token, "));
 
   *++yyvsp = yylval;
-  YYLLOC_DEFAULT (yyloc, yylsp, (yylerrsp - yylsp));
+  YYLLOC_DEFAULT (yyloc, yylsp, yylerrsp - yylsp);
   *++yylsp = yyloc;
 
   yystate = yyn;
@@ -1849,7 +1879,7 @@ yyreturn:
 }
 
 
-#line 408 "parse-gram.y"
+#line 423 "parse-gram.y"
 
 
 
