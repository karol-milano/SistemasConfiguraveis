@@ -98,21 +98,22 @@
      PERCENT_OUTPUT = 288,
      PERCENT_PARSE_PARAM = 289,
      PERCENT_PURE_PARSER = 290,
-     PERCENT_SKELETON = 291,
-     PERCENT_START = 292,
-     PERCENT_TOKEN_TABLE = 293,
-     PERCENT_VERBOSE = 294,
-     PERCENT_YACC = 295,
-     TYPE = 296,
-     EQUAL = 297,
-     SEMICOLON = 298,
-     PIPE = 299,
-     ID = 300,
-     ID_COLON = 301,
-     PERCENT_PERCENT = 302,
-     PROLOGUE = 303,
-     EPILOGUE = 304,
-     BRACED_CODE = 305
+     PERCENT_REQUIRE = 291,
+     PERCENT_SKELETON = 292,
+     PERCENT_START = 293,
+     PERCENT_TOKEN_TABLE = 294,
+     PERCENT_VERBOSE = 295,
+     PERCENT_YACC = 296,
+     TYPE = 297,
+     EQUAL = 298,
+     SEMICOLON = 299,
+     PIPE = 300,
+     ID = 301,
+     ID_COLON = 302,
+     PERCENT_PERCENT = 303,
+     PROLOGUE = 304,
+     EPILOGUE = 305,
+     BRACED_CODE = 306
    };
 #endif
 /* Tokens.  */
@@ -150,21 +151,22 @@
 #define PERCENT_OUTPUT 288
 #define PERCENT_PARSE_PARAM 289
 #define PERCENT_PURE_PARSER 290
-#define PERCENT_SKELETON 291
-#define PERCENT_START 292
-#define PERCENT_TOKEN_TABLE 293
-#define PERCENT_VERBOSE 294
-#define PERCENT_YACC 295
-#define TYPE 296
-#define EQUAL 297
-#define SEMICOLON 298
-#define PIPE 299
-#define ID 300
-#define ID_COLON 301
-#define PERCENT_PERCENT 302
-#define PROLOGUE 303
-#define EPILOGUE 304
-#define BRACED_CODE 305
+#define PERCENT_REQUIRE 291
+#define PERCENT_SKELETON 292
+#define PERCENT_START 293
+#define PERCENT_TOKEN_TABLE 294
+#define PERCENT_VERBOSE 295
+#define PERCENT_YACC 296
+#define TYPE 297
+#define EQUAL 298
+#define SEMICOLON 299
+#define PIPE 300
+#define ID 301
+#define ID_COLON 302
+#define PERCENT_PERCENT 303
+#define PROLOGUE 304
+#define EPILOGUE 305
+#define BRACED_CODE 306
 
 
 
@@ -205,6 +207,7 @@
 #include "quotearg.h"
 #include "reader.h"
 #include "symlist.h"
+#include "strverscmp.h"
 
 #define YYLLOC_DEFAULT(Current, Rhs, N)  (Current) = lloc_default (Rhs, N)
 static YYLTYPE lloc_default (YYLTYPE const *, int);
@@ -212,6 +215,8 @@ static YYLTYPE lloc_default (YYLTYPE const *, int);
 #define YY_LOCATION_PRINT(File, Loc) \
           location_print (File, Loc)
 
+static void version_check (location const *loc, char const *version);
+
 /* Request detailed syntax error messages, and pass them to GRAM_ERROR.
    FIXME: depends on the undocumented availability of YYLLOC.  */
 #undef  yyerror
@@ -248,7 +253,7 @@ static int current_prec = 0;
 #endif
 
 #if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
-#line 79 "../../src/parse-gram.y"
+#line 82 "../../src/parse-gram.y"
 typedef union YYSTYPE {
   symbol *symbol;
   symbol_list *list;
@@ -258,7 +263,7 @@ typedef union YYSTYPE {
   uniqstr uniqstr;
 } YYSTYPE;
 /* Line 196 of yacc.c.  */
-#line 262 "../../src/parse-gram.c"
+#line 267 "../../src/parse-gram.c"
 # define yystype YYSTYPE /* obsolescent; will be withdrawn */
 # define YYSTYPE_IS_DECLARED 1
 # define YYSTYPE_IS_TRIVIAL 1
@@ -282,7 +287,7 @@ typedef struct YYLTYPE
 
 
 /* Line 219 of yacc.c.  */
-#line 286 "../../src/parse-gram.c"
+#line 291 "../../src/parse-gram.c"
 
 #ifndef YYSIZE_T
 # if defined (__SIZE_TYPE__)
@@ -446,20 +451,20 @@ union yyalloc
 /* YYFINAL -- State number of the termination state. */
 #define YYFINAL  3
 /* YYLAST -- Last index in YYTABLE.  */
-#define YYLAST   158
+#define YYLAST   161
 
 /* YYNTOKENS -- Number of terminals. */
-#define YYNTOKENS  51
+#define YYNTOKENS  52
 /* YYNNTS -- Number of nonterminals. */
 #define YYNNTS  25
 /* YYNRULES -- Number of rules. */
-#define YYNRULES  80
+#define YYNRULES  81
 /* YYNRULES -- Number of states. */
-#define YYNSTATES  108
+#define YYNSTATES  110
 
 /* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
 #define YYUNDEFTOK  2
-#define YYMAXUTOK   305
+#define YYMAXUTOK   306
 
 #define YYTRANSLATE(YYX)						\
   ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)
@@ -497,7 +502,7 @@ static const unsigned char yytranslate[] =
       15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
       25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
       35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
-      45,    46,    47,    48,    49,    50
+      45,    46,    47,    48,    49,    50,    51
 };
 
 #if YYDEBUG
@@ -507,53 +512,53 @@ static const unsigned char yyprhs[] =
 {
        0,     0,     3,     8,     9,    12,    14,    16,    18,    21,
       25,    27,    29,    32,    35,    39,    41,    43,    45,    47,
-      51,    53,    55,    59,    61,    63,    66,    68,    70,    72,
-      74,    76,    78,    81,    83,    86,    89,    91,    93,    94,
-      98,    99,   103,   107,   111,   113,   115,   117,   118,   120,
-     122,   125,   127,   129,   132,   135,   139,   141,   144,   146,
-     149,   151,   154,   157,   158,   162,   164,   168,   171,   172,
-     175,   178,   182,   186,   190,   192,   194,   196,   198,   200,
-     201
+      51,    53,    55,    59,    61,    63,    66,    69,    71,    73,
+      75,    77,    79,    81,    84,    86,    89,    92,    94,    96,
+      97,   101,   102,   106,   110,   114,   116,   118,   120,   121,
+     123,   125,   128,   130,   132,   135,   138,   142,   144,   147,
+     149,   152,   154,   157,   160,   161,   165,   167,   171,   174,
+     175,   178,   181,   185,   189,   193,   195,   197,   199,   201,
+     203,   204
 };
 
 /* YYRHS -- A `-1'-separated list of the rules' RHS. */
 static const yysigned_char yyrhs[] =
 {
-      52,     0,    -1,    53,    47,    65,    75,    -1,    -1,    53,
-      54,    -1,    55,    -1,    48,    -1,    17,    -1,    19,    74,
-      -1,    19,    74,    74,    -1,    20,    -1,    21,    -1,    22,
-       4,    -1,    23,     4,    -1,    24,    42,    74,    -1,    25,
-      -1,    26,    -1,    27,    -1,    28,    -1,    29,    42,    74,
-      -1,    31,    -1,    32,    -1,    33,    42,    74,    -1,    34,
-      -1,    35,    -1,    36,    74,    -1,    38,    -1,    39,    -1,
-      40,    -1,    43,    -1,    59,    -1,    56,    -1,    37,    71,
-      -1,    10,    -1,     8,    62,    -1,     9,    62,    -1,    18,
-      -1,    30,    -1,    -1,     6,    57,    64,    -1,    -1,     5,
-      58,    64,    -1,     7,    41,    62,    -1,    60,    61,    62,
-      -1,    11,    -1,    12,    -1,    13,    -1,    -1,    41,    -1,
-      71,    -1,    62,    71,    -1,    41,    -1,    45,    -1,    45,
-       4,    -1,    45,    73,    -1,    45,     4,    73,    -1,    63,
-      -1,    64,    63,    -1,    66,    -1,    65,    66,    -1,    67,
-      -1,    55,    43,    -1,     1,    43,    -1,    -1,    46,    68,
-      69,    -1,    70,    -1,    69,    44,    70,    -1,    69,    43,
-      -1,    -1,    70,    71,    -1,    70,    72,    -1,    70,    14,
-      71,    -1,    70,    15,     4,    -1,    70,    16,    41,    -1,
-      45,    -1,    73,    -1,    50,    -1,     3,    -1,     3,    -1,
-      -1,    47,    49,    -1
+      53,     0,    -1,    54,    48,    66,    76,    -1,    -1,    54,
+      55,    -1,    56,    -1,    49,    -1,    17,    -1,    19,    75,
+      -1,    19,    75,    75,    -1,    20,    -1,    21,    -1,    22,
+       4,    -1,    23,     4,    -1,    24,    43,    75,    -1,    25,
+      -1,    26,    -1,    27,    -1,    28,    -1,    29,    43,    75,
+      -1,    31,    -1,    32,    -1,    33,    43,    75,    -1,    34,
+      -1,    35,    -1,    36,    75,    -1,    37,    75,    -1,    39,
+      -1,    40,    -1,    41,    -1,    44,    -1,    60,    -1,    57,
+      -1,    38,    72,    -1,    10,    -1,     8,    63,    -1,     9,
+      63,    -1,    18,    -1,    30,    -1,    -1,     6,    58,    65,
+      -1,    -1,     5,    59,    65,    -1,     7,    42,    63,    -1,
+      61,    62,    63,    -1,    11,    -1,    12,    -1,    13,    -1,
+      -1,    42,    -1,    72,    -1,    63,    72,    -1,    42,    -1,
+      46,    -1,    46,     4,    -1,    46,    74,    -1,    46,     4,
+      74,    -1,    64,    -1,    65,    64,    -1,    67,    -1,    66,
+      67,    -1,    68,    -1,    56,    44,    -1,     1,    44,    -1,
+      -1,    47,    69,    70,    -1,    71,    -1,    70,    45,    71,
+      -1,    70,    44,    -1,    -1,    71,    72,    -1,    71,    73,
+      -1,    71,    14,    72,    -1,    71,    15,     4,    -1,    71,
+      16,    42,    -1,    46,    -1,    74,    -1,    51,    -1,     3,
+      -1,     3,    -1,    -1,    48,    50,    -1
 };
 
 /* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
 static const unsigned short int yyrline[] =
 {
-       0,   188,   188,   196,   198,   202,   203,   204,   205,   206,
-     207,   208,   209,   210,   211,   212,   217,   221,   222,   223,
-     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
-     237,   238,   239,   243,   249,   256,   263,   267,   274,   274,
-     279,   279,   284,   294,   309,   310,   311,   315,   316,   322,
-     323,   328,   332,   337,   343,   349,   360,   361,   370,   371,
-     377,   378,   383,   390,   390,   394,   395,   396,   401,   402,
-     404,   406,   408,   410,   415,   416,   420,   426,   435,   440,
-     442
+       0,   192,   192,   200,   202,   206,   207,   208,   209,   210,
+     211,   212,   213,   214,   215,   216,   221,   225,   226,   227,
+     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
+     238,   242,   243,   244,   248,   254,   261,   268,   272,   279,
+     279,   284,   284,   289,   299,   314,   315,   316,   320,   321,
+     327,   328,   333,   337,   342,   348,   354,   365,   366,   375,
+     376,   382,   383,   388,   395,   395,   399,   400,   401,   406,
+     407,   409,   411,   413,   415,   420,   421,   425,   431,   440,
+     445,   447
 };
 #endif
 
@@ -571,15 +576,16 @@ static const char *const yytname[] =
   "\"%initial-action {...}\"", "\"%lex-param {...}\"", "\"%locations\"",
   "\"%name-prefix\"", "\"%no-default-prec\"", "\"%no-lines\"",
   "\"%nondeterministic-parser\"", "\"%output\"", "\"%parse-param {...}\"",
-  "\"%pure-parser\"", "\"%skeleton\"", "\"%start\"", "\"%token-table\"",
-  "\"%verbose\"", "\"%yacc\"", "\"type\"", "\"=\"", "\";\"", "\"|\"",
-  "\"identifier\"", "\"identifier:\"", "\"%%\"", "\"%{...%}\"",
-  "\"epilogue\"", "\"{...}\"", "$accept", "input", "declarations",
-  "declaration", "grammar_declaration", "symbol_declaration", "@1", "@2",
-  "precedence_declaration", "precedence_declarator", "type.opt",
-  "symbols.1", "symbol_def", "symbol_defs.1", "grammar",
-  "rules_or_grammar_declaration", "rules", "@3", "rhses.1", "rhs",
-  "symbol", "action", "string_as_id", "string_content", "epilogue.opt", 0
+  "\"%pure-parser\"", "\"%require\"", "\"%skeleton\"", "\"%start\"",
+  "\"%token-table\"", "\"%verbose\"", "\"%yacc\"", "\"type\"", "\"=\"",
+  "\";\"", "\"|\"", "\"identifier\"", "\"identifier:\"", "\"%%\"",
+  "\"%{...%}\"", "\"epilogue\"", "\"{...}\"", "$accept", "input",
+  "declarations", "declaration", "grammar_declaration",
+  "symbol_declaration", "@1", "@2", "precedence_declaration",
+  "precedence_declarator", "type.opt", "symbols.1", "symbol_def",
+  "symbol_defs.1", "grammar", "rules_or_grammar_declaration", "rules",
+  "@3", "rhses.1", "rhs", "symbol", "action", "string_as_id",
+  "string_content", "epilogue.opt", 0
 };
 #endif
 
@@ -593,22 +599,22 @@ static const unsigned short int yytoknum[] =
      275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
      285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
      295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
-     305
+     305,   306
 };
 # endif
 
 /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
 static const unsigned char yyr1[] =
 {
-       0,    51,    52,    53,    53,    54,    54,    54,    54,    54,
-      54,    54,    54,    54,    54,    54,    54,    54,    54,    54,
-      54,    54,    54,    54,    54,    54,    54,    54,    54,    54,
-      55,    55,    55,    55,    55,    55,    55,    55,    57,    56,
-      58,    56,    56,    59,    60,    60,    60,    61,    61,    62,
-      62,    63,    63,    63,    63,    63,    64,    64,    65,    65,
-      66,    66,    66,    68,    67,    69,    69,    69,    70,    70,
-      70,    70,    70,    70,    71,    71,    72,    73,    74,    75,
-      75
+       0,    52,    53,    54,    54,    55,    55,    55,    55,    55,
+      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
+      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
+      55,    56,    56,    56,    56,    56,    56,    56,    56,    58,
+      57,    59,    57,    57,    60,    61,    61,    61,    62,    62,
+      63,    63,    64,    64,    64,    64,    64,    65,    65,    66,
+      66,    67,    67,    67,    69,    68,    70,    70,    70,    71,
+      71,    71,    71,    71,    71,    72,    72,    73,    74,    75,
+      76,    76
 };
 
 /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
@@ -616,13 +622,13 @@ static const unsigned char yyr2[] =
 {
        0,     2,     4,     0,     2,     1,     1,     1,     2,     3,
        1,     1,     2,     2,     3,     1,     1,     1,     1,     3,
-       1,     1,     3,     1,     1,     2,     1,     1,     1,     1,
-       1,     1,     2,     1,     2,     2,     1,     1,     0,     3,
-       0,     3,     3,     3,     1,     1,     1,     0,     1,     1,
-       2,     1,     1,     2,     2,     3,     1,     2,     1,     2,
-       1,     2,     2,     0,     3,     1,     3,     2,     0,     2,
-       2,     3,     3,     3,     1,     1,     1,     1,     1,     0,
-       2
+       1,     1,     3,     1,     1,     2,     2,     1,     1,     1,
+       1,     1,     1,     2,     1,     2,     2,     1,     1,     0,
+       3,     0,     3,     3,     3,     1,     1,     1,     0,     1,
+       1,     2,     1,     1,     2,     2,     3,     1,     2,     1,
+       2,     1,     2,     2,     0,     3,     1,     3,     2,     0,
+       2,     2,     3,     3,     3,     1,     1,     1,     1,     1,
+       0,     2
 };
 
 /* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
@@ -630,113 +636,115 @@ static const unsigned char yyr2[] =
    means the default is an error.  */
 static const unsigned char yydefact[] =
 {
-       3,     0,     0,     1,    40,    38,     0,     0,     0,    33,
-      44,    45,    46,     7,    36,     0,    10,    11,     0,     0,
-       0,    15,    16,    17,    18,     0,    37,    20,    21,     0,
-      23,    24,     0,     0,    26,    27,    28,    29,     0,     6,
-       4,     5,    31,    30,    47,     0,     0,     0,    77,    74,
-      34,    49,    75,    35,    78,     8,    12,    13,     0,     0,
-       0,    25,    32,     0,    63,     0,     0,    58,    60,    48,
-       0,    51,    52,    56,    41,    39,    42,    50,     9,    14,
-      19,    22,    62,    68,    61,     0,    59,     2,    43,    53,
-      54,    57,    64,    65,    80,    55,    67,    68,     0,     0,
-       0,    76,    69,    70,    66,    71,    72,    73
+       3,     0,     0,     1,    41,    39,     0,     0,     0,    34,
+      45,    46,    47,     7,    37,     0,    10,    11,     0,     0,
+       0,    15,    16,    17,    18,     0,    38,    20,    21,     0,
+      23,    24,     0,     0,     0,    27,    28,    29,    30,     0,
+       6,     4,     5,    32,    31,    48,     0,     0,     0,    78,
+      75,    35,    50,    76,    36,    79,     8,    12,    13,     0,
+       0,     0,    25,    26,    33,     0,    64,     0,     0,    59,
+      61,    49,     0,    52,    53,    57,    42,    40,    43,    51,
+       9,    14,    19,    22,    63,    69,    62,     0,    60,     2,
+      44,    54,    55,    58,    65,    66,    81,    56,    68,    69,
+       0,     0,     0,    77,    70,    71,    67,    72,    73,    74
 };
 
 /* YYDEFGOTO[NTERM-NUM]. */
 static const yysigned_char yydefgoto[] =
 {
-      -1,     1,     2,    40,    65,    42,    46,    45,    43,    44,
-      70,    50,    73,    74,    66,    67,    68,    83,    92,    93,
-      51,   103,    52,    55,    87
+      -1,     1,     2,    41,    67,    43,    47,    46,    44,    45,
+      72,    51,    75,    76,    68,    69,    70,    85,    94,    95,
+      52,   105,    53,    56,    89
 };
 
 /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
    STATE-NUM.  */
-#define YYPACT_NINF -67
+#define YYPACT_NINF -69
 static const yysigned_char yypact[] =
 {
-     -67,     5,   110,   -67,   -67,   -67,   -34,     0,     0,   -67,
-     -67,   -67,   -67,   -67,   -67,    13,   -67,   -67,    20,    31,
-     -17,   -67,   -67,   -67,   -67,    -6,   -67,   -67,   -67,    -5,
-     -67,   -67,    13,     0,   -67,   -67,   -67,   -67,    68,   -67,
-     -67,   -67,   -67,   -67,    -3,   -37,   -37,     0,   -67,   -67,
-       0,   -67,   -67,     0,   -67,    13,   -67,   -67,    13,    13,
-      13,   -67,   -67,    -2,   -67,     3,    21,   -67,   -67,   -67,
-       0,   -67,     6,   -67,   -37,   -37,     0,   -67,   -67,   -67,
-     -67,   -67,   -67,   -67,   -67,     1,   -67,   -67,     0,    39,
-     -67,   -67,   -32,    -1,   -67,   -67,   -67,   -67,     0,    43,
-       7,   -67,   -67,   -67,    -1,   -67,   -67,   -67
+     -69,     5,   112,   -69,   -69,   -69,   -35,     0,     0,   -69,
+     -69,   -69,   -69,   -69,   -69,    13,   -69,   -69,    20,    31,
+     -18,   -69,   -69,   -69,   -69,    -6,   -69,   -69,   -69,    -5,
+     -69,   -69,    13,    13,     0,   -69,   -69,   -69,   -69,    69,
+     -69,   -69,   -69,   -69,   -69,    -2,   -38,   -38,     0,   -69,
+     -69,     0,   -69,   -69,     0,   -69,    13,   -69,   -69,    13,
+      13,    13,   -69,   -69,   -69,    -8,   -69,     3,    21,   -69,
+     -69,   -69,     0,   -69,     6,   -69,   -38,   -38,     0,   -69,
+     -69,   -69,   -69,   -69,   -69,   -69,   -69,     2,   -69,   -69,
+       0,    39,   -69,   -69,   -33,    -1,   -69,   -69,   -69,   -69,
+       0,    44,     1,   -69,   -69,   -69,    -1,   -69,   -69,   -69
 };
 
 /* YYPGOTO[NTERM-NUM].  */
 static const yysigned_char yypgoto[] =
 {
-     -67,   -67,   -67,   -67,    50,   -67,   -67,   -67,   -67,   -67,
-     -67,    -7,   -56,     8,   -67,   -13,   -67,   -67,   -67,   -41,
-     -33,   -67,   -66,    29,   -67
+     -69,   -69,   -69,   -69,    47,   -69,   -69,   -69,   -69,   -69,
+     -69,    -7,   -58,     7,   -69,   -15,   -69,   -69,   -69,   -44,
+     -34,   -69,   -68,    30,   -69
 };
 
 /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
    positive, shift that token.  If negative, reduce the rule which
    number is the opposite.  If zero, do what YYDEFACT says.
    If YYTABLE_NINF, syntax error.  */
-#define YYTABLE_NINF -80
+#define YYTABLE_NINF -81
 static const yysigned_char yytable[] =
 {
-      62,    53,    48,    48,    71,     3,    90,    47,    72,    48,
-      89,    96,    97,    98,    99,   100,    54,    77,    91,    91,
-      77,   -79,    63,    95,    56,    58,     4,     5,     6,     7,
-       8,     9,    10,    11,    12,    57,    59,    60,    69,    14,
-      76,    82,    48,    77,    49,    49,    84,   106,   107,   101,
-      94,    26,    41,    86,    75,    77,   104,     0,    33,     0,
-     102,    61,     0,    88,     0,   105,     0,    64,    85,    63,
-       0,   102,     0,     4,     5,     6,     7,     8,     9,    10,
-      11,    12,     0,     0,    78,     0,    14,    79,    80,    81,
-       0,     0,     0,     0,     0,     0,     0,     0,    26,     0,
-       0,     0,     0,     0,     0,    33,     0,     0,     0,     0,
-       0,     0,     0,     0,    64,     4,     5,     6,     7,     8,
-       9,    10,    11,    12,     0,     0,     0,    13,    14,    15,
-      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
-      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
-      36,     0,     0,    37,     0,     0,     0,    38,    39
+      64,    54,    49,    49,    73,     3,    92,    48,    74,    49,
+      91,    98,    99,   100,   101,   102,    55,    79,    93,    93,
+      79,   -80,    65,    97,    57,    59,     4,     5,     6,     7,
+       8,     9,    10,    11,    12,    58,    84,    60,    61,    14,
+      71,    78,    49,   109,    79,    50,    50,    86,   108,    42,
+     103,    26,    96,    88,    77,   106,    79,     0,     0,    34,
+       0,   104,    62,    63,     0,    90,   107,     0,    66,    87,
+      65,     0,   104,     0,     4,     5,     6,     7,     8,     9,
+      10,    11,    12,     0,     0,     0,    80,    14,     0,    81,
+      82,    83,     0,     0,     0,     0,     0,     0,     0,    26,
+       0,     0,     0,     0,     0,     0,     0,    34,     0,     0,
+       0,     0,     0,     0,     0,     0,    66,     4,     5,     6,
+       7,     8,     9,    10,    11,    12,     0,     0,     0,    13,
+      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
+      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
+      34,    35,    36,    37,     0,     0,    38,     0,     0,     0,
+      39,    40
 };
 
 static const yysigned_char yycheck[] =
 {
-      33,     8,     3,     3,    41,     0,    72,    41,    45,     3,
-       4,    43,    44,    14,    15,    16,     3,    50,    74,    75,
-      53,     0,     1,    89,     4,    42,     5,     6,     7,     8,
-       9,    10,    11,    12,    13,     4,    42,    42,    41,    18,
-      47,    43,     3,    76,    45,    45,    43,     4,    41,    50,
-      49,    30,     2,    66,    46,    88,    97,    -1,    37,    -1,
-      93,    32,    -1,    70,    -1,    98,    -1,    46,    47,     1,
-      -1,   104,    -1,     5,     6,     7,     8,     9,    10,    11,
-      12,    13,    -1,    -1,    55,    -1,    18,    58,    59,    60,
-      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,
-      -1,    -1,    -1,    -1,    -1,    37,    -1,    -1,    -1,    -1,
-      -1,    -1,    -1,    -1,    46,     5,     6,     7,     8,     9,
-      10,    11,    12,    13,    -1,    -1,    -1,    17,    18,    19,
-      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
-      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
-      40,    -1,    -1,    43,    -1,    -1,    -1,    47,    48
+      34,     8,     3,     3,    42,     0,    74,    42,    46,     3,
+       4,    44,    45,    14,    15,    16,     3,    51,    76,    77,
+      54,     0,     1,    91,     4,    43,     5,     6,     7,     8,
+       9,    10,    11,    12,    13,     4,    44,    43,    43,    18,
+      42,    48,     3,    42,    78,    46,    46,    44,     4,     2,
+      51,    30,    50,    68,    47,    99,    90,    -1,    -1,    38,
+      -1,    95,    32,    33,    -1,    72,   100,    -1,    47,    48,
+       1,    -1,   106,    -1,     5,     6,     7,     8,     9,    10,
+      11,    12,    13,    -1,    -1,    -1,    56,    18,    -1,    59,
+      60,    61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,
+      -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,
+      -1,    -1,    -1,    -1,    -1,    -1,    47,     5,     6,     7,
+       8,     9,    10,    11,    12,    13,    -1,    -1,    -1,    17,
+      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
+      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
+      38,    39,    40,    41,    -1,    -1,    44,    -1,    -1,    -1,
+      48,    49
 };
 
 /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
    symbol of state STATE-NUM.  */
 static const unsigned char yystos[] =
 {
-       0,    52,    53,     0,     5,     6,     7,     8,     9,    10,
+       0,    53,    54,     0,     5,     6,     7,     8,     9,    10,
       11,    12,    13,    17,    18,    19,    20,    21,    22,    23,
       24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
-      34,    35,    36,    37,    38,    39,    40,    43,    47,    48,
-      54,    55,    56,    59,    60,    58,    57,    41,     3,    45,
-      62,    71,    73,    62,     3,    74,     4,     4,    42,    42,
-      42,    74,    71,     1,    46,    55,    65,    66,    67,    41,
-      61,    41,    45,    63,    64,    64,    62,    71,    74,    74,
-      74,    74,    43,    68,    43,    47,    66,    75,    62,     4,
-      73,    63,    69,    70,    49,    73,    43,    44,    14,    15,
-      16,    50,    71,    72,    70,    71,     4,    41
+      34,    35,    36,    37,    38,    39,    40,    41,    44,    48,
+      49,    55,    56,    57,    60,    61,    59,    58,    42,     3,
+      46,    63,    72,    74,    63,     3,    75,     4,     4,    43,
+      43,    43,    75,    75,    72,     1,    47,    56,    66,    67,
+      68,    42,    62,    42,    46,    64,    65,    65,    63,    72,
+      75,    75,    75,    75,    44,    69,    44,    48,    67,    76,
+      63,     4,    74,    64,    70,    71,    50,    74,    44,    45,
+      14,    15,    16,    51,    72,    73,    71,    72,     4,    42
 };
 
 #define yyerrok		(yyerrstatus = 0)
@@ -1185,94 +1193,94 @@ yysymprint (yyoutput, yytype, yyvaluep, yylocationp)
   switch (yytype)
     {
       case 3: /* "\"string\"" */
-#line 165 "../../src/parse-gram.y"
+#line 169 "../../src/parse-gram.y"
         { fprintf (stderr, "\"%s\"", (yyvaluep->chars)); };
-#line 1191 "../../src/parse-gram.c"
+#line 1199 "../../src/parse-gram.c"
         break;
       case 4: /* "\"integer\"" */
-#line 178 "../../src/parse-gram.y"
+#line 182 "../../src/parse-gram.y"
         { fprintf (stderr, "%d", (yyvaluep->integer)); };
-#line 1196 "../../src/parse-gram.c"
+#line 1204 "../../src/parse-gram.c"
         break;
       case 8: /* "\"%destructor {...}\"" */
-#line 167 "../../src/parse-gram.y"
+#line 171 "../../src/parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1201 "../../src/parse-gram.c"
+#line 1209 "../../src/parse-gram.c"
         break;
       case 9: /* "\"%printer {...}\"" */
-#line 171 "../../src/parse-gram.y"
+#line 175 "../../src/parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1206 "../../src/parse-gram.c"
+#line 1214 "../../src/parse-gram.c"
         break;
       case 10: /* "\"%union {...}\"" */
-#line 172 "../../src/parse-gram.y"
+#line 176 "../../src/parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1211 "../../src/parse-gram.c"
+#line 1219 "../../src/parse-gram.c"
         break;
       case 26: /* "\"%initial-action {...}\"" */
-#line 168 "../../src/parse-gram.y"
+#line 172 "../../src/parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1216 "../../src/parse-gram.c"
+#line 1224 "../../src/parse-gram.c"
         break;
       case 27: /* "\"%lex-param {...}\"" */
-#line 169 "../../src/parse-gram.y"
+#line 173 "../../src/parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1221 "../../src/parse-gram.c"
+#line 1229 "../../src/parse-gram.c"
         break;
       case 34: /* "\"%parse-param {...}\"" */
-#line 170 "../../src/parse-gram.y"
+#line 174 "../../src/parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1226 "../../src/parse-gram.c"
+#line 1234 "../../src/parse-gram.c"
         break;
-      case 41: /* "\"type\"" */
-#line 176 "../../src/parse-gram.y"
+      case 42: /* "\"type\"" */
+#line 180 "../../src/parse-gram.y"
         { fprintf (stderr, "<%s>", (yyvaluep->uniqstr)); };
-#line 1231 "../../src/parse-gram.c"
+#line 1239 "../../src/parse-gram.c"
         break;
-      case 45: /* "\"identifier\"" */
-#line 180 "../../src/parse-gram.y"
+      case 46: /* "\"identifier\"" */
+#line 184 "../../src/parse-gram.y"
         { fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
-#line 1236 "../../src/parse-gram.c"
+#line 1244 "../../src/parse-gram.c"
         break;
-      case 46: /* "\"identifier:\"" */
-#line 182 "../../src/parse-gram.y"
+      case 47: /* "\"identifier:\"" */
+#line 186 "../../src/parse-gram.y"
         { fprintf (stderr, "%s:", (yyvaluep->symbol)->tag); };
-#line 1241 "../../src/parse-gram.c"
+#line 1249 "../../src/parse-gram.c"
         break;
-      case 48: /* "\"%{...%}\"" */
-#line 174 "../../src/parse-gram.y"
+      case 49: /* "\"%{...%}\"" */
+#line 178 "../../src/parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1246 "../../src/parse-gram.c"
+#line 1254 "../../src/parse-gram.c"
         break;
-      case 49: /* "\"epilogue\"" */
-#line 174 "../../src/parse-gram.y"
+      case 50: /* "\"epilogue\"" */
+#line 178 "../../src/parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1251 "../../src/parse-gram.c"
+#line 1259 "../../src/parse-gram.c"
         break;
-      case 50: /* "\"{...}\"" */
-#line 173 "../../src/parse-gram.y"
+      case 51: /* "\"{...}\"" */
+#line 177 "../../src/parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1256 "../../src/parse-gram.c"
+#line 1264 "../../src/parse-gram.c"
         break;
-      case 71: /* "symbol" */
-#line 180 "../../src/parse-gram.y"
+      case 72: /* "symbol" */
+#line 184 "../../src/parse-gram.y"
         { fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
-#line 1261 "../../src/parse-gram.c"
+#line 1269 "../../src/parse-gram.c"
         break;
-      case 72: /* "action" */
-#line 173 "../../src/parse-gram.y"
+      case 73: /* "action" */
+#line 177 "../../src/parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1266 "../../src/parse-gram.c"
+#line 1274 "../../src/parse-gram.c"
         break;
-      case 73: /* "string_as_id" */
-#line 180 "../../src/parse-gram.y"
+      case 74: /* "string_as_id" */
+#line 184 "../../src/parse-gram.y"
         { fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
-#line 1271 "../../src/parse-gram.c"
+#line 1279 "../../src/parse-gram.c"
         break;
-      case 74: /* "string_content" */
-#line 165 "../../src/parse-gram.y"
+      case 75: /* "string_content" */
+#line 169 "../../src/parse-gram.y"
         { fprintf (stderr, "\"%s\"", (yyvaluep->chars)); };
-#line 1276 "../../src/parse-gram.c"
+#line 1284 "../../src/parse-gram.c"
         break;
       default:
         break;
@@ -1443,7 +1451,7 @@ YYLTYPE yylloc;
 
 
   /* User initialization code. */
-#line 69 "../../src/parse-gram.y"
+#line 72 "../../src/parse-gram.y"
 {
   /* Bison's grammar can initial empty locations, hence a default
      location is needed. */
@@ -1452,7 +1460,7 @@ YYLTYPE yylloc;
   yylloc.start.column = yylloc.end.column = 0;
 }
 /* Line 1053 of yacc.c.  */
-#line 1456 "../../src/parse-gram.c"
+#line 1464 "../../src/parse-gram.c"
   yylsp[0] = yylloc;
   goto yysetstate;
 
@@ -1641,52 +1649,52 @@ yyreduce:
   switch (yyn)
     {
         case 6:
-#line 203 "../../src/parse-gram.y"
+#line 207 "../../src/parse-gram.y"
     { prologue_augment ((yyvsp[0].chars), (yylsp[0])); }
     break;
 
   case 7:
-#line 204 "../../src/parse-gram.y"
+#line 208 "../../src/parse-gram.y"
     { debug_flag = true; }
     break;
 
   case 8:
-#line 205 "../../src/parse-gram.y"
+#line 209 "../../src/parse-gram.y"
     { muscle_insert ((yyvsp[0].chars), "1"); }
     break;
 
   case 9:
-#line 206 "../../src/parse-gram.y"
+#line 210 "../../src/parse-gram.y"
     { muscle_insert ((yyvsp[-1].chars), (yyvsp[0].chars)); }
     break;
 
   case 10:
-#line 207 "../../src/parse-gram.y"
+#line 211 "../../src/parse-gram.y"
     { defines_flag = true; }
     break;
 
   case 11:
-#line 208 "../../src/parse-gram.y"
+#line 212 "../../src/parse-gram.y"
     { error_verbose = true; }
     break;
 
   case 12:
-#line 209 "../../src/parse-gram.y"
+#line 213 "../../src/parse-gram.y"
     { expected_sr_conflicts = (yyvsp[0].integer); }
     break;
 
   case 13:
-#line 210 "../../src/parse-gram.y"
+#line 214 "../../src/parse-gram.y"
     { expected_rr_conflicts = (yyvsp[0].integer); }
     break;
 
   case 14:
-#line 211 "../../src/parse-gram.y"
+#line 215 "../../src/parse-gram.y"
     { spec_file_prefix = (yyvsp[0].chars); }
     break;
 
   case 15:
-#line 213 "../../src/parse-gram.y"
+#line 217 "../../src/parse-gram.y"
     {
     nondeterministic_parser = true;
     glr_parser = true;
@@ -1694,81 +1702,86 @@ yyreduce:
     break;
 
   case 16:
-#line 218 "../../src/parse-gram.y"
+#line 222 "../../src/parse-gram.y"
     {
     muscle_code_grow ("initial_action", (yyvsp[0].chars), (yylsp[0]));
   }
     break;
 
   case 17:
-#line 221 "../../src/parse-gram.y"
+#line 225 "../../src/parse-gram.y"
     { add_param ("lex_param", (yyvsp[0].chars), (yylsp[0])); }
     break;
 
   case 18:
-#line 222 "../../src/parse-gram.y"
+#line 226 "../../src/parse-gram.y"
     { locations_flag = true; }
     break;
 
   case 19:
-#line 223 "../../src/parse-gram.y"
+#line 227 "../../src/parse-gram.y"
     { spec_name_prefix = (yyvsp[0].chars); }
     break;
 
   case 20:
-#line 224 "../../src/parse-gram.y"
+#line 228 "../../src/parse-gram.y"
     { no_lines_flag = true; }
     break;
 
   case 21:
-#line 225 "../../src/parse-gram.y"
+#line 229 "../../src/parse-gram.y"
     { nondeterministic_parser = true; }
     break;
 
   case 22:
-#line 226 "../../src/parse-gram.y"
+#line 230 "../../src/parse-gram.y"
     { spec_outfile = (yyvsp[0].chars); }
     break;
 
   case 23:
-#line 227 "../../src/parse-gram.y"
+#line 231 "../../src/parse-gram.y"
     { add_param ("parse_param", (yyvsp[0].chars), (yylsp[0])); }
     break;
 
   case 24:
-#line 228 "../../src/parse-gram.y"
+#line 232 "../../src/parse-gram.y"
     { pure_parser = true; }
     break;
 
   case 25:
-#line 229 "../../src/parse-gram.y"
-    { skeleton = (yyvsp[0].chars); }
+#line 233 "../../src/parse-gram.y"
+    { version_check (&(yylsp[0]), (yyvsp[0].chars)); }
     break;
 
   case 26:
-#line 230 "../../src/parse-gram.y"
-    { token_table_flag = true; }
+#line 234 "../../src/parse-gram.y"
+    { skeleton = (yyvsp[0].chars); }
     break;
 
   case 27:
-#line 231 "../../src/parse-gram.y"
-    { report_flag = report_states; }
+#line 235 "../../src/parse-gram.y"
+    { token_table_flag = true; }
     break;
 
   case 28:
-#line 232 "../../src/parse-gram.y"
+#line 236 "../../src/parse-gram.y"
+    { report_flag = report_states; }
+    break;
+
+  case 29:
+#line 237 "../../src/parse-gram.y"
     { yacc_flag = true; }
     break;
 
-  case 32:
-#line 240 "../../src/parse-gram.y"
+  case 33:
+#line 245 "../../src/parse-gram.y"
     {
       grammar_start_symbol_set ((yyvsp[0].symbol), (yylsp[0]));
     }
     break;
 
-  case 33:
-#line 244 "../../src/parse-gram.y"
+  case 34:
+#line 249 "../../src/parse-gram.y"
     {
       typed = true;
       MUSCLE_INSERT_INT ("stype_line", (yylsp[0]).start.line);
@@ -1776,8 +1789,8 @@ yyreduce:
     }
     break;
 
-  case 34:
-#line 250 "../../src/parse-gram.y"
+  case 35:
+#line 255 "../../src/parse-gram.y"
     {
       symbol_list *list;
       for (list = (yyvsp[0].list); list; list = list->next)
@@ -1786,8 +1799,8 @@ yyreduce:
     }
     break;
 
-  case 35:
-#line 257 "../../src/parse-gram.y"
+  case 36:
+#line 262 "../../src/parse-gram.y"
     {
       symbol_list *list;
       for (list = (yyvsp[0].list); list; list = list->next)
@@ -1796,48 +1809,48 @@ yyreduce:
     }
     break;
 
-  case 36:
-#line 264 "../../src/parse-gram.y"
+  case 37:
+#line 269 "../../src/parse-gram.y"
     {
       default_prec = true;
     }
     break;
 
-  case 37:
-#line 268 "../../src/parse-gram.y"
+  case 38:
+#line 273 "../../src/parse-gram.y"
     {
       default_prec = false;
     }
     break;
 
-  case 38:
-#line 274 "../../src/parse-gram.y"
+  case 39:
+#line 279 "../../src/parse-gram.y"
     { current_class = nterm_sym; }
     break;
 
-  case 39:
-#line 275 "../../src/parse-gram.y"
+  case 40:
+#line 280 "../../src/parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
     break;
 
-  case 40:
-#line 279 "../../src/parse-gram.y"
+  case 41:
+#line 284 "../../src/parse-gram.y"
     { current_class = token_sym; }
     break;
 
-  case 41:
-#line 280 "../../src/parse-gram.y"
+  case 42:
+#line 285 "../../src/parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
     break;
 
-  case 42:
-#line 285 "../../src/parse-gram.y"
+  case 43:
+#line 290 "../../src/parse-gram.y"
     {
       symbol_list *list;
       for (list = (yyvsp[0].list); list; list = list->next)
@@ -1846,8 +1859,8 @@ yyreduce:
     }
     break;
 
-  case 43:
-#line 295 "../../src/parse-gram.y"
+  case 44:
+#line 300 "../../src/parse-gram.y"
     {
       symbol_list *list;
       ++current_prec;
@@ -1861,58 +1874,58 @@ yyreduce:
     }
     break;
 
-  case 44:
-#line 309 "../../src/parse-gram.y"
+  case 45:
+#line 314 "../../src/parse-gram.y"
     { (yyval.assoc) = left_assoc; }
     break;
 
-  case 45:
-#line 310 "../../src/parse-gram.y"
+  case 46:
+#line 315 "../../src/parse-gram.y"
     { (yyval.assoc) = right_assoc; }
     break;
 
-  case 46:
-#line 311 "../../src/parse-gram.y"
+  case 47:
+#line 316 "../../src/parse-gram.y"
     { (yyval.assoc) = non_assoc; }
     break;
 
-  case 47:
-#line 315 "../../src/parse-gram.y"
+  case 48:
+#line 320 "../../src/parse-gram.y"
     { current_type = NULL; }
     break;
 
-  case 48:
-#line 316 "../../src/parse-gram.y"
+  case 49:
+#line 321 "../../src/parse-gram.y"
     { current_type = (yyvsp[0].uniqstr); }
     break;
 
-  case 49:
-#line 322 "../../src/parse-gram.y"
+  case 50:
+#line 327 "../../src/parse-gram.y"
     { (yyval.list) = symbol_list_new ((yyvsp[0].symbol), (yylsp[0])); }
     break;
 
-  case 50:
-#line 323 "../../src/parse-gram.y"
+  case 51:
+#line 328 "../../src/parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), (yyvsp[0].symbol), (yylsp[0])); }
     break;
 
-  case 51:
-#line 329 "../../src/parse-gram.y"
+  case 52:
+#line 334 "../../src/parse-gram.y"
     {
        current_type = (yyvsp[0].uniqstr);
      }
     break;
 
-  case 52:
-#line 333 "../../src/parse-gram.y"
+  case 53:
+#line 338 "../../src/parse-gram.y"
     {
        symbol_class_set ((yyvsp[0].symbol), current_class, (yylsp[0]));
        symbol_type_set ((yyvsp[0].symbol), current_type, (yylsp[0]));
      }
     break;
 
-  case 53:
-#line 338 "../../src/parse-gram.y"
+  case 54:
+#line 343 "../../src/parse-gram.y"
     {
       symbol_class_set ((yyvsp[-1].symbol), current_class, (yylsp[-1]));
       symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
@@ -1920,8 +1933,8 @@ yyreduce:
     }
     break;
 
-  case 54:
-#line 344 "../../src/parse-gram.y"
+  case 55:
+#line 349 "../../src/parse-gram.y"
     {
       symbol_class_set ((yyvsp[-1].symbol), current_class, (yylsp[-1]));
       symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
@@ -1929,8 +1942,8 @@ yyreduce:
     }
     break;
 
-  case 55:
-#line 350 "../../src/parse-gram.y"
+  case 56:
+#line 355 "../../src/parse-gram.y"
     {
       symbol_class_set ((yyvsp[-2].symbol), current_class, (yylsp[-2]));
       symbol_type_set ((yyvsp[-2].symbol), current_type, (yylsp[-2]));
@@ -1939,96 +1952,96 @@ yyreduce:
     }
     break;
 
-  case 61:
-#line 379 "../../src/parse-gram.y"
+  case 62:
+#line 384 "../../src/parse-gram.y"
     {
       if (yacc_flag)
 	complain_at ((yyloc), _("POSIX forbids declarations in the grammar"));
     }
     break;
 
-  case 62:
-#line 384 "../../src/parse-gram.y"
+  case 63:
+#line 389 "../../src/parse-gram.y"
     {
       yyerrok;
     }
     break;
 
-  case 63:
-#line 390 "../../src/parse-gram.y"
+  case 64:
+#line 395 "../../src/parse-gram.y"
     { current_lhs = (yyvsp[0].symbol); current_lhs_location = (yylsp[0]); }
     break;
 
-  case 65:
-#line 394 "../../src/parse-gram.y"
-    { grammar_rule_end ((yylsp[0])); }
-    break;
-
   case 66:
-#line 395 "../../src/parse-gram.y"
+#line 399 "../../src/parse-gram.y"
     { grammar_rule_end ((yylsp[0])); }
     break;
 
-  case 68:
-#line 401 "../../src/parse-gram.y"
-    { grammar_rule_begin (current_lhs, current_lhs_location); }
+  case 67:
+#line 400 "../../src/parse-gram.y"
+    { grammar_rule_end ((yylsp[0])); }
     break;
 
   case 69:
-#line 403 "../../src/parse-gram.y"
-    { grammar_current_rule_symbol_append ((yyvsp[0].symbol), (yylsp[0])); }
+#line 406 "../../src/parse-gram.y"
+    { grammar_rule_begin (current_lhs, current_lhs_location); }
     break;
 
   case 70:
-#line 405 "../../src/parse-gram.y"
-    { grammar_current_rule_action_append ((yyvsp[0].chars), (yylsp[0])); }
+#line 408 "../../src/parse-gram.y"
+    { grammar_current_rule_symbol_append ((yyvsp[0].symbol), (yylsp[0])); }
     break;
 
   case 71:
-#line 407 "../../src/parse-gram.y"
-    { grammar_current_rule_prec_set ((yyvsp[0].symbol), (yylsp[0])); }
+#line 410 "../../src/parse-gram.y"
+    { grammar_current_rule_action_append ((yyvsp[0].chars), (yylsp[0])); }
     break;
 
   case 72:
-#line 409 "../../src/parse-gram.y"
-    { grammar_current_rule_dprec_set ((yyvsp[0].integer), (yylsp[0])); }
+#line 412 "../../src/parse-gram.y"
+    { grammar_current_rule_prec_set ((yyvsp[0].symbol), (yylsp[0])); }
     break;
 
   case 73:
-#line 411 "../../src/parse-gram.y"
-    { grammar_current_rule_merge_set ((yyvsp[0].uniqstr), (yylsp[0])); }
+#line 414 "../../src/parse-gram.y"
+    { grammar_current_rule_dprec_set ((yyvsp[0].integer), (yylsp[0])); }
     break;
 
   case 74:
-#line 415 "../../src/parse-gram.y"
-    { (yyval.symbol) = (yyvsp[0].symbol); }
+#line 416 "../../src/parse-gram.y"
+    { grammar_current_rule_merge_set ((yyvsp[0].uniqstr), (yylsp[0])); }
     break;
 
   case 75:
-#line 416 "../../src/parse-gram.y"
+#line 420 "../../src/parse-gram.y"
     { (yyval.symbol) = (yyvsp[0].symbol); }
     break;
 
   case 76:
 #line 421 "../../src/parse-gram.y"
-    { (yyval.chars) = (yyvsp[0].chars); }
+    { (yyval.symbol) = (yyvsp[0].symbol); }
     break;
 
   case 77:
-#line 427 "../../src/parse-gram.y"
+#line 426 "../../src/parse-gram.y"
+    { (yyval.chars) = (yyvsp[0].chars); }
+    break;
+
+  case 78:
+#line 432 "../../src/parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[0].chars)), (yylsp[0]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]));
     }
     break;
 
-  case 78:
-#line 436 "../../src/parse-gram.y"
+  case 79:
+#line 441 "../../src/parse-gram.y"
     { (yyval.chars) = (yyvsp[0].chars); }
     break;
 
-  case 80:
-#line 443 "../../src/parse-gram.y"
+  case 81:
+#line 448 "../../src/parse-gram.y"
     {
       muscle_code_grow ("epilogue", (yyvsp[0].chars), (yylsp[0]));
       scanner_last_string_free ();
@@ -2040,7 +2053,7 @@ yyreduce:
     }
 
 /* Line 1249 of yacc.c.  */
-#line 2044 "../../src/parse-gram.c"
+#line 2057 "../../src/parse-gram.c"
 
   yyvsp -= yylen;
   yyssp -= yylen;
@@ -2250,7 +2263,7 @@ yyreturn:
 }
 
 
-#line 449 "../../src/parse-gram.y"
+#line 454 "../../src/parse-gram.y"
 
 
 
@@ -2335,6 +2348,14 @@ add_param (char const *type, char *decl, location loc)
   scanner_last_string_free ();
 }
 
+static void
+version_check (location const *loc, char const *version)
+{
+  if (strverscmp (version, PACKAGE_VERSION) > 0)
+    complain_at (*loc, "require bison %s, but have %s",
+		 version, PACKAGE_VERSION);
+}
+
 static void
 gram_error (location const *loc, char const *msg)
 {
