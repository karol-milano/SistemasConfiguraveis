@@ -162,8 +162,6 @@ extern int gram_debug;
 /* "%code requires" blocks.  */
 #line 219 "src/parse-gram.y" /* yacc.c:372  */
 
-# ifndef PARAM_TYPE
-#  define PARAM_TYPE
   typedef enum
   {
     param_none   = 0,
@@ -171,10 +169,9 @@ extern int gram_debug;
     param_parse  = 1 << 1,
     param_both   = param_lex | param_parse
   } param_type;
-# endif
 
 
-#line 178 "src/parse-gram.c" /* yacc.c:372  */
+#line 175 "src/parse-gram.c" /* yacc.c:372  */
 
 /* Token type.  */
 #ifndef GRAM_TOKENTYPE
@@ -183,57 +180,57 @@ extern int gram_debug;
   {
     GRAM_EOF = 0,
     STRING = 258,
-    INT = 259,
-    PERCENT_TOKEN = 260,
-    PERCENT_NTERM = 261,
-    PERCENT_TYPE = 262,
-    PERCENT_DESTRUCTOR = 263,
-    PERCENT_PRINTER = 264,
-    PERCENT_LEFT = 265,
-    PERCENT_RIGHT = 266,
-    PERCENT_NONASSOC = 267,
-    PERCENT_PRECEDENCE = 268,
-    PERCENT_PREC = 269,
-    PERCENT_DPREC = 270,
-    PERCENT_MERGE = 271,
-    PERCENT_CODE = 272,
-    PERCENT_DEFAULT_PREC = 273,
-    PERCENT_DEFINE = 274,
-    PERCENT_DEFINES = 275,
-    PERCENT_ERROR_VERBOSE = 276,
-    PERCENT_EXPECT = 277,
-    PERCENT_EXPECT_RR = 278,
-    PERCENT_FLAG = 279,
-    PERCENT_FILE_PREFIX = 280,
-    PERCENT_GLR_PARSER = 281,
-    PERCENT_INITIAL_ACTION = 282,
-    PERCENT_LANGUAGE = 283,
-    PERCENT_NAME_PREFIX = 284,
-    PERCENT_NO_DEFAULT_PREC = 285,
-    PERCENT_NO_LINES = 286,
-    PERCENT_NONDETERMINISTIC_PARSER = 287,
-    PERCENT_OUTPUT = 288,
-    PERCENT_REQUIRE = 289,
-    PERCENT_SKELETON = 290,
-    PERCENT_START = 291,
-    PERCENT_TOKEN_TABLE = 292,
-    PERCENT_VERBOSE = 293,
-    PERCENT_YACC = 294,
-    BRACED_CODE = 295,
-    BRACED_PREDICATE = 296,
-    BRACKETED_ID = 297,
-    CHAR = 298,
-    EPILOGUE = 299,
-    EQUAL = 300,
-    ID = 301,
-    ID_COLON = 302,
-    PERCENT_PERCENT = 303,
-    PIPE = 304,
-    PROLOGUE = 305,
-    SEMICOLON = 306,
-    TAG = 307,
-    TAG_ANY = 308,
-    TAG_NONE = 309,
+    PERCENT_TOKEN = 259,
+    PERCENT_NTERM = 260,
+    PERCENT_TYPE = 261,
+    PERCENT_DESTRUCTOR = 262,
+    PERCENT_PRINTER = 263,
+    PERCENT_LEFT = 264,
+    PERCENT_RIGHT = 265,
+    PERCENT_NONASSOC = 266,
+    PERCENT_PRECEDENCE = 267,
+    PERCENT_PREC = 268,
+    PERCENT_DPREC = 269,
+    PERCENT_MERGE = 270,
+    PERCENT_CODE = 271,
+    PERCENT_DEFAULT_PREC = 272,
+    PERCENT_DEFINE = 273,
+    PERCENT_DEFINES = 274,
+    PERCENT_ERROR_VERBOSE = 275,
+    PERCENT_EXPECT = 276,
+    PERCENT_EXPECT_RR = 277,
+    PERCENT_FLAG = 278,
+    PERCENT_FILE_PREFIX = 279,
+    PERCENT_GLR_PARSER = 280,
+    PERCENT_INITIAL_ACTION = 281,
+    PERCENT_LANGUAGE = 282,
+    PERCENT_NAME_PREFIX = 283,
+    PERCENT_NO_DEFAULT_PREC = 284,
+    PERCENT_NO_LINES = 285,
+    PERCENT_NONDETERMINISTIC_PARSER = 286,
+    PERCENT_OUTPUT = 287,
+    PERCENT_REQUIRE = 288,
+    PERCENT_SKELETON = 289,
+    PERCENT_START = 290,
+    PERCENT_TOKEN_TABLE = 291,
+    PERCENT_VERBOSE = 292,
+    PERCENT_YACC = 293,
+    BRACED_CODE = 294,
+    BRACED_PREDICATE = 295,
+    BRACKETED_ID = 296,
+    CHAR = 297,
+    EPILOGUE = 298,
+    EQUAL = 299,
+    ID = 300,
+    ID_COLON = 301,
+    PERCENT_PERCENT = 302,
+    PIPE = 303,
+    PROLOGUE = 304,
+    SEMICOLON = 305,
+    TAG = 306,
+    TAG_ANY = 307,
+    TAG_NONE = 308,
+    INT = 309,
     PERCENT_PARAM = 310,
     PERCENT_UNION = 311,
     PERCENT_EMPTY = 312
@@ -245,26 +242,31 @@ extern int gram_debug;
 typedef union GRAM_STYPE GRAM_STYPE;
 union GRAM_STYPE
 {
-#line 105 "src/parse-gram.y" /* yacc.c:372  */
+#line 171 "src/parse-gram.y" /* yacc.c:372  */
+unsigned char character;
+#line 178 "src/parse-gram.y" /* yacc.c:372  */
 
-  assoc assoc;
   char *code;
   char const *chars;
-  int integer;
-  named_ref *named_ref;
-  symbol *symbol;
-  symbol_list *list;
-  uniqstr uniqstr;
-  unsigned char character;
-
-#line 243 "src/parse-gram.y" /* yacc.c:372  */
 
-  param_type param;
-
-#line 419 "src/parse-gram.y" /* yacc.c:372  */
+#line 189 "src/parse-gram.y" /* yacc.c:372  */
+uniqstr uniqstr;
+#line 197 "src/parse-gram.y" /* yacc.c:372  */
+int integer;
+#line 201 "src/parse-gram.y" /* yacc.c:372  */
+symbol *symbol;
+#line 206 "src/parse-gram.y" /* yacc.c:372  */
+assoc assoc;
+#line 209 "src/parse-gram.y" /* yacc.c:372  */
+symbol_list *list;
+#line 212 "src/parse-gram.y" /* yacc.c:372  */
+named_ref *named_ref;
+#line 239 "src/parse-gram.y" /* yacc.c:372  */
+param_type param;
+#line 413 "src/parse-gram.y" /* yacc.c:372  */
 code_props_type code_type;
 
-#line 268 "src/parse-gram.c" /* yacc.c:372  */
+#line 270 "src/parse-gram.c" /* yacc.c:372  */
 };
 # define GRAM_STYPE_IS_TRIVIAL 1
 # define GRAM_STYPE_IS_DECLARED 1
@@ -292,7 +294,7 @@ int gram_parse (void);
 
 /* Copy the second part of user declarations.  */
 
-#line 296 "src/parse-gram.c" /* yacc.c:375  */
+#line 298 "src/parse-gram.c" /* yacc.c:375  */
 /* Unqualified %code blocks.  */
 #line 54 "src/parse-gram.y" /* yacc.c:376  */
 
@@ -326,7 +328,7 @@ int gram_parse (void);
   #define YYTYPE_UINT16 uint_fast16_t
   #define YYTYPE_UINT8 uint_fast8_t
 
-#line 232 "src/parse-gram.y" /* yacc.c:376  */
+#line 229 "src/parse-gram.y" /* yacc.c:376  */
 
   /** Add a lex-param and/or a parse-param.
    *
@@ -338,7 +340,7 @@ int gram_parse (void);
   static param_type current_param = param_none;
 
 
-#line 342 "src/parse-gram.c" /* yacc.c:376  */
+#line 344 "src/parse-gram.c" /* yacc.c:376  */
 
 #ifdef short
 # undef short
@@ -512,7 +514,7 @@ union yyalloc
 /* YYFINAL -- State number of the termination state.  */
 #define YYFINAL  3
 /* YYLAST -- Last index in YYTABLE.  */
-#define YYLAST   158
+#define YYLAST   172
 
 /* YYNTOKENS -- Number of terminals.  */
 #define YYNTOKENS  58
@@ -573,18 +575,18 @@ static const yytype_uint8 yytranslate[] =
   /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
 static const yytype_uint16 yyrline[] =
 {
-       0,   268,   268,   277,   278,   282,   283,   293,   297,   302,
-     303,   308,   313,   314,   315,   316,   321,   330,   331,   332,
-     333,   334,   335,   335,   336,   337,   361,   362,   363,   364,
-     368,   369,   378,   379,   380,   384,   396,   400,   404,   411,
-     422,   423,   433,   434,   438,   450,   450,   455,   455,   460,
-     471,   486,   487,   488,   489,   493,   494,   499,   501,   506,
-     511,   521,   523,   528,   529,   533,   534,   538,   539,   540,
-     545,   550,   555,   561,   567,   578,   579,   588,   589,   595,
-     596,   597,   604,   604,   612,   613,   614,   619,   622,   624,
-     626,   628,   630,   632,   634,   639,   640,   650,   651,   656,
-     657,   658,   667,   687,   689,   698,   703,   704,   709,   717,
-     718
+       0,   262,   262,   271,   272,   276,   277,   287,   291,   296,
+     297,   302,   307,   308,   309,   310,   315,   324,   325,   326,
+     327,   328,   329,   329,   330,   331,   355,   356,   357,   358,
+     362,   363,   372,   373,   374,   378,   390,   394,   398,   405,
+     416,   417,   427,   428,   432,   444,   444,   449,   449,   454,
+     465,   480,   481,   482,   483,   487,   488,   493,   495,   500,
+     505,   515,   517,   522,   523,   527,   528,   532,   533,   534,
+     539,   544,   549,   555,   561,   572,   573,   582,   583,   589,
+     590,   591,   598,   598,   606,   607,   608,   613,   616,   618,
+     620,   622,   624,   626,   628,   633,   634,   644,   645,   650,
+     651,   652,   661,   681,   683,   692,   697,   698,   703,   711,
+     712
 };
 #endif
 
@@ -593,10 +595,10 @@ static const yytype_uint16 yyrline[] =
    First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
 static const char *const yytname[] =
 {
-  "\"end of file\"", "error", "$undefined", "\"string\"", "\"integer\"",
-  "\"%token\"", "\"%nterm\"", "\"%type\"", "\"%destructor\"",
-  "\"%printer\"", "\"%left\"", "\"%right\"", "\"%nonassoc\"",
-  "\"%precedence\"", "\"%prec\"", "\"%dprec\"", "\"%merge\"", "\"%code\"",
+  "\"end of file\"", "error", "$undefined", "\"string\"", "\"%token\"",
+  "\"%nterm\"", "\"%type\"", "\"%destructor\"", "\"%printer\"",
+  "\"%left\"", "\"%right\"", "\"%nonassoc\"", "\"%precedence\"",
+  "\"%prec\"", "\"%dprec\"", "\"%merge\"", "\"%code\"",
   "\"%default-prec\"", "\"%define\"", "\"%defines\"", "\"%error-verbose\"",
   "\"%expect\"", "\"%expect-rr\"", "\"%<flag>\"", "\"%file-prefix\"",
   "\"%glr-parser\"", "\"%initial-action\"", "\"%language\"",
@@ -606,9 +608,9 @@ static const char *const yytname[] =
   "\"%yacc\"", "\"{...}\"", "\"%?{...}\"", "\"[identifier]\"", "\"char\"",
   "\"epilogue\"", "\"=\"", "\"identifier\"", "\"identifier:\"", "\"%%\"",
   "\"|\"", "\"%{...%}\"", "\";\"", "\"<tag>\"", "\"<*>\"", "\"<>\"",
-  "\"%param\"", "\"%union\"", "\"%empty\"", "$accept", "input",
-  "prologue_declarations", "prologue_declaration", "$@1", "params",
-  "grammar_declaration", "code_props_type", "union_name",
+  "\"integer\"", "\"%param\"", "\"%union\"", "\"%empty\"", "$accept",
+  "input", "prologue_declarations", "prologue_declaration", "$@1",
+  "params", "grammar_declaration", "code_props_type", "union_name",
   "symbol_declaration", "$@2", "$@3", "precedence_declaration",
   "precedence_declarator", "tag.opt", "symbols.prec", "symbol.prec",
   "symbols.1", "generic_symlist", "generic_symlist_item", "tag",
@@ -633,10 +635,10 @@ static const yytype_uint16 yytoknum[] =
 };
 # endif
 
-#define YYPACT_NINF -99
+#define YYPACT_NINF -104
 
 #define yypact_value_is_default(Yystate) \
-  (!!((Yystate) == (-99)))
+  (!!((Yystate) == (-104)))
 
 #define YYTABLE_NINF -110
 
@@ -645,23 +647,23 @@ static const yytype_uint16 yytoknum[] =
 
   /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
      STATE-NUM.  */
-static const yytype_int16 yypact[] =
+static const yytype_int8 yypact[] =
 {
-     -99,     5,   102,   -99,   -99,   -99,   -48,   -99,   -99,   -99,
-     -99,   -99,   -99,    19,   -99,    27,    52,   -99,    56,    60,
-     -99,    67,   -99,    34,    73,    76,   -99,   -99,   -99,    86,
-      87,    88,     0,   -99,   -99,   -99,    15,   -99,   -99,   -99,
-      46,   -99,   -99,    54,   -99,   -99,    45,     4,     4,     0,
-     -99,    58,   -99,   -99,   -99,    31,   -99,   -99,   -99,   -99,
-     -99,   -99,   -99,   -99,   -99,   -99,   -99,   -99,   -99,   -99,
-     -99,   -99,    49,   -99,    50,     1,   -99,   -99,    61,    62,
-     -99,    58,    32,   -99,     0,   -99,   -99,     4,    84,     4,
-       0,   -99,   -99,   -99,   -99,   -99,   -99,   -99,    72,   -99,
-     -99,   -99,   -99,   -99,    64,   -99,   -99,   -99,   -99,    32,
-     -99,   -99,   -99,     0,   -99,   101,   -99,   114,   -99,   -99,
-     -99,   -99,   -99,   -99,   -99,   -99,   -99,    12,    26,   -99,
-     -99,     0,   138,    66,    61,   -99,   -99,    61,    26,   -99,
-     -99,   -99,   -99,   -99
+    -104,    18,   116,  -104,  -104,  -104,   -26,  -104,  -104,  -104,
+    -104,  -104,  -104,   -16,  -104,    24,    23,  -104,   -18,   -13,
+    -104,    39,  -104,     9,    51,    52,  -104,  -104,  -104,    53,
+      68,    71,    -2,  -104,  -104,  -104,    56,  -104,  -104,  -104,
+      30,  -104,  -104,    37,  -104,  -104,    27,   -21,   -21,    -2,
+    -104,    40,  -104,  -104,  -104,    25,  -104,  -104,  -104,  -104,
+    -104,  -104,  -104,  -104,  -104,  -104,  -104,  -104,  -104,  -104,
+    -104,  -104,    32,  -104,    34,     3,  -104,  -104,    49,    58,
+    -104,    40,    41,  -104,    -2,  -104,  -104,   -21,    -1,   -21,
+      -2,  -104,  -104,  -104,  -104,  -104,  -104,  -104,    55,  -104,
+    -104,  -104,  -104,  -104,    61,  -104,  -104,  -104,  -104,    41,
+    -104,  -104,  -104,    -2,  -104,    26,  -104,    92,  -104,  -104,
+    -104,  -104,  -104,  -104,  -104,  -104,  -104,   -15,    74,  -104,
+    -104,    -2,    47,    54,    49,  -104,  -104,    49,    74,  -104,
+    -104,  -104,  -104,  -104
 };
 
   /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
@@ -687,12 +689,12 @@ static const yytype_uint8 yydefact[] =
 };
 
   /* YYPGOTO[NTERM-NUM].  */
-static const yytype_int16 yypgoto[] =
+static const yytype_int8 yypgoto[] =
 {
-     -99,   -99,   -99,   -99,   -99,   -99,   141,   -99,   -99,   -99,
-     -99,   -99,   -99,   -99,   -99,   -99,    33,   -99,   -99,    35,
-     -99,    -7,    97,   -99,    74,   -99,   -99,   -99,    18,   -98,
-     -99,   -99,   -13,     6,   -99,   -32,   -73,   -99
+    -104,  -104,  -104,  -104,  -104,  -104,   101,  -104,  -104,  -104,
+    -104,  -104,  -104,  -104,  -104,  -104,    -9,  -104,  -104,     0,
+    -104,   -50,    59,  -104,    33,  -104,  -104,  -104,   -19,  -103,
+    -104,  -104,   -35,   -42,  -104,   -32,   -66,  -104
 };
 
   /* YYDEFGOTO[NTERM-NUM].  */
@@ -709,63 +711,67 @@ static const yytype_int16 yydefgoto[] =
      number is the opposite.  If YYTABLE_NINF, syntax error.  */
 static const yytype_int16 yytable[] =
 {
-      70,  -109,    72,    66,    49,     3,     4,     5,     6,     7,
-       8,     9,    10,    11,    12,   118,    72,    91,    13,    14,
-       4,     5,     6,     7,     8,     9,    10,    11,    12,    66,
-      53,    26,    13,    14,    93,    66,   142,    32,    92,   143,
-     131,   132,   133,    67,   126,    26,    68,    67,    73,    98,
-      68,    32,   115,    88,    88,    56,    85,    40,   119,    50,
-      57,   129,    73,   130,    58,    51,   134,   135,   105,    67,
-      59,    40,    68,    54,    60,    67,    61,    94,    68,    62,
-     116,   115,   116,   136,   106,   107,   108,    66,   117,    63,
-      64,    65,    80,    88,    82,    88,   137,    83,    50,   139,
-      96,    97,   103,   101,   122,   125,   137,     4,     5,     6,
-       7,     8,     9,    10,    11,    12,   120,    66,   141,    13,
-      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
-      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
-      34,    35,   140,    42,   123,    89,   124,   138,     0,    99,
-      36,     0,    37,    38,     0,     0,     0,    39,    40
+      70,    66,    66,  -109,    72,    88,    88,     4,     5,     6,
+       7,     8,     9,    10,    11,    12,    92,    91,     3,    13,
+      14,    67,   118,    50,    68,    49,    56,    53,    93,    51,
+      85,   142,    26,   129,   143,   130,    57,   116,    32,   116,
+      67,    58,    59,    68,    66,    88,   105,    88,    60,    73,
+      98,   126,   115,   117,    61,    62,    63,    72,   119,    40,
+       4,     5,     6,     7,     8,     9,    10,    11,    12,    54,
+      94,    64,    13,    14,    65,    80,    82,    66,    83,    50,
+     125,   115,    96,    67,    97,    26,    68,   131,   132,   133,
+     101,    32,   106,   107,   108,    66,   137,   103,   120,   139,
+     122,   140,    73,    42,   124,   141,   137,    89,    99,   123,
+     138,     0,    40,   134,   135,     0,    67,     0,     0,    68,
+       4,     5,     6,     7,     8,     9,    10,    11,    12,     0,
+       0,   136,    13,    14,    15,    16,    17,    18,    19,    20,
+      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
+      31,    32,    33,    34,    35,     0,     0,     0,     0,     0,
+       0,     0,     0,    36,     0,    37,    38,     0,     0,     0,
+       0,    39,    40
 };
 
 static const yytype_int16 yycheck[] =
 {
-      32,     0,     1,     3,    52,     0,     5,     6,     7,     8,
-       9,    10,    11,    12,    13,    88,     1,    49,    17,    18,
-       5,     6,     7,     8,     9,    10,    11,    12,    13,     3,
-       3,    30,    17,    18,     3,     3,   134,    36,    51,   137,
-      14,    15,    16,    43,   117,    30,    46,    43,    47,    48,
-      46,    36,    84,    47,    48,     3,    52,    56,    90,    40,
-       4,    49,    47,    51,     4,    46,    40,    41,    81,    43,
-       3,    56,    46,    46,    40,    43,     3,    46,    46,     3,
-      87,   113,    89,    57,    52,    53,    54,     3,     4,     3,
-       3,     3,    46,    87,    40,    89,   128,    52,    40,   131,
-      51,    51,    40,    42,    40,     4,   138,     5,     6,     7,
-       8,     9,    10,    11,    12,    13,    44,     3,    52,    17,
-      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
-      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
-      38,    39,     4,     2,   109,    48,   113,   129,    -1,    75,
-      48,    -1,    50,    51,    -1,    -1,    -1,    55,    56
+      32,     3,     3,     0,     1,    47,    48,     4,     5,     6,
+       7,     8,     9,    10,    11,    12,    51,    49,     0,    16,
+      17,    42,    88,    39,    45,    51,     3,     3,     3,    45,
+      51,   134,    29,    48,   137,    50,    54,    87,    35,    89,
+      42,    54,     3,    45,     3,    87,    81,    89,    39,    46,
+      47,   117,    84,    54,     3,     3,     3,     1,    90,    56,
+       4,     5,     6,     7,     8,     9,    10,    11,    12,    45,
+      45,     3,    16,    17,     3,    45,    39,     3,    51,    39,
+      54,   113,    50,    42,    50,    29,    45,    13,    14,    15,
+      41,    35,    51,    52,    53,     3,   128,    39,    43,   131,
+      39,    54,    46,     2,   113,    51,   138,    48,    75,   109,
+     129,    -1,    56,    39,    40,    -1,    42,    -1,    -1,    45,
+       4,     5,     6,     7,     8,     9,    10,    11,    12,    -1,
+      -1,    57,    16,    17,    18,    19,    20,    21,    22,    23,
+      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
+      34,    35,    36,    37,    38,    -1,    -1,    -1,    -1,    -1,
+      -1,    -1,    -1,    47,    -1,    49,    50,    -1,    -1,    -1,
+      -1,    55,    56
 };
 
   /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
      symbol of state STATE-NUM.  */
 static const yytype_uint8 yystos[] =
 {
-       0,    59,    60,     0,     5,     6,     7,     8,     9,    10,
-      11,    12,    13,    17,    18,    19,    20,    21,    22,    23,
-      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
-      34,    35,    36,    37,    38,    39,    48,    50,    51,    55,
-      56,    61,    64,    65,    67,    70,    71,    69,    68,    52,
-      40,    46,    90,     3,    46,    88,     3,     4,     4,     3,
-      40,     3,     3,     3,     3,     3,     3,    43,    46,    91,
-      93,    94,     1,    47,    64,    81,    82,    83,    92,    62,
-      46,    66,    40,    52,    72,    52,    79,    80,    91,    80,
-      75,    93,    90,     3,    46,    89,    51,    51,    48,    82,
-      95,    42,    87,    40,    63,    90,    52,    53,    54,    76,
-      77,    78,    93,    73,    74,    93,    79,     4,    94,    93,
-      44,    84,    40,    77,    74,     4,    94,    85,    86,    49,
-      51,    14,    15,    16,    40,    41,    57,    93,    86,    93,
-       4,    52,    87,    87
+       0,    59,    60,     0,     4,     5,     6,     7,     8,     9,
+      10,    11,    12,    16,    17,    18,    19,    20,    21,    22,
+      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
+      33,    34,    35,    36,    37,    38,    47,    49,    50,    55,
+      56,    61,    64,    65,    67,    70,    71,    69,    68,    51,
+      39,    45,    90,     3,    45,    88,     3,    54,    54,     3,
+      39,     3,     3,     3,     3,     3,     3,    42,    45,    91,
+      93,    94,     1,    46,    64,    81,    82,    83,    92,    62,
+      45,    66,    39,    51,    72,    51,    79,    80,    91,    80,
+      75,    93,    90,     3,    45,    89,    50,    50,    47,    82,
+      95,    41,    87,    39,    63,    90,    51,    52,    53,    76,
+      77,    78,    93,    73,    74,    93,    79,    54,    94,    93,
+      43,    84,    39,    77,    74,    54,    94,    85,    86,    48,
+      50,    13,    14,    15,    39,    40,    57,    93,    86,    93,
+      54,    51,    87,    87
 };
 
   /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
@@ -955,78 +961,78 @@ yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvalue
   switch (yytype)
     {
     case 3: /* "string"  */
-#line 192 "src/parse-gram.y" /* yacc.c:706  */
+#line 184 "src/parse-gram.y" /* yacc.c:706  */
       { fputs (quotearg_style (c_quoting_style, ((*yyvaluep).chars)), yyo); }
-#line 961 "src/parse-gram.c" /* yacc.c:706  */
-        break;
-
-    case 4: /* "integer"  */
-#line 205 "src/parse-gram.y" /* yacc.c:706  */
-      { fprintf (yyo, "%d", ((*yyvaluep).integer)); }
 #line 967 "src/parse-gram.c" /* yacc.c:706  */
         break;
 
-    case 24: /* "%<flag>"  */
-#line 201 "src/parse-gram.y" /* yacc.c:706  */
+    case 23: /* "%<flag>"  */
+#line 194 "src/parse-gram.y" /* yacc.c:706  */
       { fprintf (yyo, "%%%s", ((*yyvaluep).uniqstr)); }
 #line 973 "src/parse-gram.c" /* yacc.c:706  */
         break;
 
-    case 40: /* "{...}"  */
-#line 194 "src/parse-gram.y" /* yacc.c:706  */
+    case 39: /* "{...}"  */
+#line 186 "src/parse-gram.y" /* yacc.c:706  */
       { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).code)); }
 #line 979 "src/parse-gram.c" /* yacc.c:706  */
         break;
 
-    case 42: /* "[identifier]"  */
-#line 199 "src/parse-gram.y" /* yacc.c:706  */
+    case 41: /* "[identifier]"  */
+#line 192 "src/parse-gram.y" /* yacc.c:706  */
       { fprintf (yyo, "[%s]", ((*yyvaluep).uniqstr)); }
 #line 985 "src/parse-gram.c" /* yacc.c:706  */
         break;
 
-    case 43: /* "char"  */
-#line 186 "src/parse-gram.y" /* yacc.c:706  */
+    case 42: /* "char"  */
+#line 173 "src/parse-gram.y" /* yacc.c:706  */
       { fputs (char_name (((*yyvaluep).character)), yyo); }
 #line 991 "src/parse-gram.c" /* yacc.c:706  */
         break;
 
-    case 44: /* "epilogue"  */
-#line 194 "src/parse-gram.y" /* yacc.c:706  */
+    case 43: /* "epilogue"  */
+#line 186 "src/parse-gram.y" /* yacc.c:706  */
       { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).chars)); }
 #line 997 "src/parse-gram.c" /* yacc.c:706  */
         break;
 
-    case 46: /* "identifier"  */
-#line 198 "src/parse-gram.y" /* yacc.c:706  */
+    case 45: /* "identifier"  */
+#line 191 "src/parse-gram.y" /* yacc.c:706  */
       { fputs (((*yyvaluep).uniqstr), yyo); }
 #line 1003 "src/parse-gram.c" /* yacc.c:706  */
         break;
 
-    case 47: /* "identifier:"  */
-#line 200 "src/parse-gram.y" /* yacc.c:706  */
+    case 46: /* "identifier:"  */
+#line 193 "src/parse-gram.y" /* yacc.c:706  */
       { fprintf (yyo, "%s:", ((*yyvaluep).uniqstr)); }
 #line 1009 "src/parse-gram.c" /* yacc.c:706  */
         break;
 
-    case 50: /* "%{...%}"  */
-#line 194 "src/parse-gram.y" /* yacc.c:706  */
+    case 49: /* "%{...%}"  */
+#line 186 "src/parse-gram.y" /* yacc.c:706  */
       { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).chars)); }
 #line 1015 "src/parse-gram.c" /* yacc.c:706  */
         break;
 
-    case 52: /* "<tag>"  */
-#line 202 "src/parse-gram.y" /* yacc.c:706  */
+    case 51: /* "<tag>"  */
+#line 195 "src/parse-gram.y" /* yacc.c:706  */
       { fprintf (yyo, "<%s>", ((*yyvaluep).uniqstr)); }
 #line 1021 "src/parse-gram.c" /* yacc.c:706  */
         break;
 
+    case 54: /* "integer"  */
+#line 199 "src/parse-gram.y" /* yacc.c:706  */
+      { fprintf (yyo, "%d", ((*yyvaluep).integer)); }
+#line 1027 "src/parse-gram.c" /* yacc.c:706  */
+        break;
+
     case 55: /* "%param"  */
-#line 248 "src/parse-gram.y" /* yacc.c:706  */
+#line 242 "src/parse-gram.y" /* yacc.c:706  */
       {
   switch (((*yyvaluep).param))
     {
 #define CASE(In, Out)                                           \
-      case param_ ## In: fputs ("%" #Out, stderr); break
+      case param_ ## In: fputs ("%" #Out, yyo); break
       CASE (lex,   lex-param);
       CASE (parse, parse-param);
       CASE (both,  param);
@@ -1034,67 +1040,67 @@ yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvalue
       case param_none: aver (false); break;
     }
 }
-#line 1038 "src/parse-gram.c" /* yacc.c:706  */
+#line 1044 "src/parse-gram.c" /* yacc.c:706  */
         break;
 
     case 65: /* code_props_type  */
-#line 420 "src/parse-gram.y" /* yacc.c:706  */
+#line 414 "src/parse-gram.y" /* yacc.c:706  */
       { fprintf (yyo, "%s", code_props_type_string (((*yyvaluep).code_type))); }
-#line 1044 "src/parse-gram.c" /* yacc.c:706  */
+#line 1050 "src/parse-gram.c" /* yacc.c:706  */
         break;
 
     case 74: /* symbol.prec  */
-#line 208 "src/parse-gram.y" /* yacc.c:706  */
+#line 203 "src/parse-gram.y" /* yacc.c:706  */
       { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
-#line 1050 "src/parse-gram.c" /* yacc.c:706  */
+#line 1056 "src/parse-gram.c" /* yacc.c:706  */
         break;
 
     case 78: /* tag  */
-#line 202 "src/parse-gram.y" /* yacc.c:706  */
+#line 195 "src/parse-gram.y" /* yacc.c:706  */
       { fprintf (yyo, "<%s>", ((*yyvaluep).uniqstr)); }
-#line 1056 "src/parse-gram.c" /* yacc.c:706  */
+#line 1062 "src/parse-gram.c" /* yacc.c:706  */
         break;
 
     case 88: /* variable  */
-#line 198 "src/parse-gram.y" /* yacc.c:706  */
+#line 191 "src/parse-gram.y" /* yacc.c:706  */
       { fputs (((*yyvaluep).uniqstr), yyo); }
-#line 1062 "src/parse-gram.c" /* yacc.c:706  */
+#line 1068 "src/parse-gram.c" /* yacc.c:706  */
         break;
 
     case 89: /* content.opt  */
-#line 194 "src/parse-gram.y" /* yacc.c:706  */
+#line 186 "src/parse-gram.y" /* yacc.c:706  */
       { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).chars)); }
-#line 1068 "src/parse-gram.c" /* yacc.c:706  */
+#line 1074 "src/parse-gram.c" /* yacc.c:706  */
         break;
 
     case 90: /* braceless  */
-#line 194 "src/parse-gram.y" /* yacc.c:706  */
+#line 186 "src/parse-gram.y" /* yacc.c:706  */
       { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).chars)); }
-#line 1074 "src/parse-gram.c" /* yacc.c:706  */
+#line 1080 "src/parse-gram.c" /* yacc.c:706  */
         break;
 
     case 91: /* id  */
-#line 208 "src/parse-gram.y" /* yacc.c:706  */
+#line 203 "src/parse-gram.y" /* yacc.c:706  */
       { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
-#line 1080 "src/parse-gram.c" /* yacc.c:706  */
+#line 1086 "src/parse-gram.c" /* yacc.c:706  */
         break;
 
     case 92: /* id_colon  */
-#line 209 "src/parse-gram.y" /* yacc.c:706  */
+#line 204 "src/parse-gram.y" /* yacc.c:706  */
       { fprintf (yyo, "%s:", ((*yyvaluep).symbol)->tag); }
-#line 1086 "src/parse-gram.c" /* yacc.c:706  */
+#line 1092 "src/parse-gram.c" /* yacc.c:706  */
         break;
 
     case 93: /* symbol  */
-#line 208 "src/parse-gram.y" /* yacc.c:706  */
+#line 203 "src/parse-gram.y" /* yacc.c:706  */
       { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
-#line 1092 "src/parse-gram.c" /* yacc.c:706  */
+#line 1098 "src/parse-gram.c" /* yacc.c:706  */
         break;
 
     case 94: /* string_as_id  */
-#line 208 "src/parse-gram.y" /* yacc.c:706  */
+#line 203 "src/parse-gram.y" /* yacc.c:706  */
       { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
-#line 1098 "src/parse-gram.c" /* yacc.c:706  */
+#line 1104 "src/parse-gram.c" /* yacc.c:706  */
         break;
 
       default:
@@ -1816,7 +1822,7 @@ YYLTYPE yylloc = yyloc_default;
   boundary_set (&yylloc.start, current_file, 1, 1);
   boundary_set (&yylloc.end, current_file, 1, 1);
 }
-#line 1820 "src/parse-gram.c" /* yacc.c:1451  */
+#line 1826 "src/parse-gram.c" /* yacc.c:1451  */
   yylsp[0] = yylloc;
   goto yysetstate;
 
@@ -2010,7 +2016,7 @@ yyreduce:
     switch (yyn)
       {
           case 6:
-#line 284 "src/parse-gram.y" /* yacc.c:1668  */
+#line 278 "src/parse-gram.y" /* yacc.c:1668  */
     {
       code_props plain_code;
       code_props_plain_init (&plain_code, (yyvsp[0].chars), (yylsp[0]));
@@ -2020,79 +2026,79 @@ yyreduce:
                         plain_code.code, (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2024 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2030 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 7:
-#line 294 "src/parse-gram.y" /* yacc.c:1668  */
+#line 288 "src/parse-gram.y" /* yacc.c:1668  */
     {
       muscle_percent_define_ensure ((yyvsp[0].uniqstr), (yylsp[0]), true);
     }
-#line 2032 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2038 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 8:
-#line 298 "src/parse-gram.y" /* yacc.c:1668  */
+#line 292 "src/parse-gram.y" /* yacc.c:1668  */
     {
       muscle_percent_define_insert ((yyvsp[-1].uniqstr), (yylsp[-1]), (yyvsp[0].chars),
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
     }
-#line 2041 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2047 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 9:
-#line 302 "src/parse-gram.y" /* yacc.c:1668  */
+#line 296 "src/parse-gram.y" /* yacc.c:1668  */
     { defines_flag = true; }
-#line 2047 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2053 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 10:
-#line 304 "src/parse-gram.y" /* yacc.c:1668  */
+#line 298 "src/parse-gram.y" /* yacc.c:1668  */
     {
       defines_flag = true;
       spec_defines_file = xstrdup ((yyvsp[0].chars));
     }
-#line 2056 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2062 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 11:
-#line 309 "src/parse-gram.y" /* yacc.c:1668  */
+#line 303 "src/parse-gram.y" /* yacc.c:1668  */
     {
       muscle_percent_define_insert ("parse.error", (yylsp[0]), "verbose",
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
     }
-#line 2065 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2071 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 12:
-#line 313 "src/parse-gram.y" /* yacc.c:1668  */
+#line 307 "src/parse-gram.y" /* yacc.c:1668  */
     { expected_sr_conflicts = (yyvsp[0].integer); }
-#line 2071 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2077 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 13:
-#line 314 "src/parse-gram.y" /* yacc.c:1668  */
+#line 308 "src/parse-gram.y" /* yacc.c:1668  */
     { expected_rr_conflicts = (yyvsp[0].integer); }
-#line 2077 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2083 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 14:
-#line 315 "src/parse-gram.y" /* yacc.c:1668  */
+#line 309 "src/parse-gram.y" /* yacc.c:1668  */
     { spec_file_prefix = (yyvsp[0].chars); }
-#line 2083 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2089 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 15:
-#line 317 "src/parse-gram.y" /* yacc.c:1668  */
+#line 311 "src/parse-gram.y" /* yacc.c:1668  */
     {
       nondeterministic_parser = true;
       glr_parser = true;
     }
-#line 2092 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2098 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 16:
-#line 322 "src/parse-gram.y" /* yacc.c:1668  */
+#line 316 "src/parse-gram.y" /* yacc.c:1668  */
     {
       code_props action;
       code_props_symbol_action_init (&action, (yyvsp[0].code), (yylsp[0]));
@@ -2101,59 +2107,59 @@ yyreduce:
       muscle_code_grow ("initial_action", action.code, (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2105 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2111 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 17:
-#line 330 "src/parse-gram.y" /* yacc.c:1668  */
+#line 324 "src/parse-gram.y" /* yacc.c:1668  */
     { language_argmatch ((yyvsp[0].chars), grammar_prio, (yylsp[-1])); }
-#line 2111 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2117 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 18:
-#line 331 "src/parse-gram.y" /* yacc.c:1668  */
+#line 325 "src/parse-gram.y" /* yacc.c:1668  */
     { spec_name_prefix = (yyvsp[0].chars); }
-#line 2117 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2123 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 19:
-#line 332 "src/parse-gram.y" /* yacc.c:1668  */
+#line 326 "src/parse-gram.y" /* yacc.c:1668  */
     { no_lines_flag = true; }
-#line 2123 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2129 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 20:
-#line 333 "src/parse-gram.y" /* yacc.c:1668  */
+#line 327 "src/parse-gram.y" /* yacc.c:1668  */
     { nondeterministic_parser = true; }
-#line 2129 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2135 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 21:
-#line 334 "src/parse-gram.y" /* yacc.c:1668  */
+#line 328 "src/parse-gram.y" /* yacc.c:1668  */
     { spec_outfile = (yyvsp[0].chars); }
-#line 2135 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2141 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 22:
-#line 335 "src/parse-gram.y" /* yacc.c:1668  */
+#line 329 "src/parse-gram.y" /* yacc.c:1668  */
     { current_param = (yyvsp[0].param); }
-#line 2141 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2147 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 23:
-#line 335 "src/parse-gram.y" /* yacc.c:1668  */
+#line 329 "src/parse-gram.y" /* yacc.c:1668  */
     { current_param = param_none; }
-#line 2147 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2153 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 24:
-#line 336 "src/parse-gram.y" /* yacc.c:1668  */
+#line 330 "src/parse-gram.y" /* yacc.c:1668  */
     { version_check (&(yylsp[0]), (yyvsp[0].chars)); }
-#line 2153 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2159 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 25:
-#line 338 "src/parse-gram.y" /* yacc.c:1668  */
+#line 332 "src/parse-gram.y" /* yacc.c:1668  */
     {
       char const *skeleton_user = (yyvsp[0].chars);
       if (strchr (skeleton_user, '/'))
@@ -2177,49 +2183,49 @@ yyreduce:
         }
       skeleton_arg (skeleton_user, grammar_prio, (yylsp[-1]));
     }
-#line 2181 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2187 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 26:
-#line 361 "src/parse-gram.y" /* yacc.c:1668  */
+#line 355 "src/parse-gram.y" /* yacc.c:1668  */
     { token_table_flag = true; }
-#line 2187 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2193 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 27:
-#line 362 "src/parse-gram.y" /* yacc.c:1668  */
+#line 356 "src/parse-gram.y" /* yacc.c:1668  */
     { report_flag |= report_states; }
-#line 2193 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2199 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 28:
-#line 363 "src/parse-gram.y" /* yacc.c:1668  */
+#line 357 "src/parse-gram.y" /* yacc.c:1668  */
     { yacc_flag = true; }
-#line 2199 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2205 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 30:
-#line 368 "src/parse-gram.y" /* yacc.c:1668  */
+#line 362 "src/parse-gram.y" /* yacc.c:1668  */
     { add_param (current_param, (yyvsp[0].code), (yylsp[0])); }
-#line 2205 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2211 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 31:
-#line 369 "src/parse-gram.y" /* yacc.c:1668  */
+#line 363 "src/parse-gram.y" /* yacc.c:1668  */
     { add_param (current_param, (yyvsp[0].code), (yylsp[0])); }
-#line 2211 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2217 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 34:
-#line 381 "src/parse-gram.y" /* yacc.c:1668  */
+#line 375 "src/parse-gram.y" /* yacc.c:1668  */
     {
       grammar_start_symbol_set ((yyvsp[0].symbol), (yylsp[0]));
     }
-#line 2219 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2225 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 35:
-#line 385 "src/parse-gram.y" /* yacc.c:1668  */
+#line 379 "src/parse-gram.y" /* yacc.c:1668  */
     {
       code_props code;
       code_props_symbol_action_init (&code, (yyvsp[-1].code), (yylsp[-1]));
@@ -2231,111 +2237,111 @@ yyreduce:
         symbol_list_free ((yyvsp[0].list));
       }
     }
-#line 2235 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2241 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 36:
-#line 397 "src/parse-gram.y" /* yacc.c:1668  */
+#line 391 "src/parse-gram.y" /* yacc.c:1668  */
     {
       default_prec = true;
     }
-#line 2243 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2249 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 37:
-#line 401 "src/parse-gram.y" /* yacc.c:1668  */
+#line 395 "src/parse-gram.y" /* yacc.c:1668  */
     {
       default_prec = false;
     }
-#line 2251 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2257 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 38:
-#line 405 "src/parse-gram.y" /* yacc.c:1668  */
+#line 399 "src/parse-gram.y" /* yacc.c:1668  */
     {
       /* Do not invoke muscle_percent_code_grow here since it invokes
          muscle_user_name_list_grow.  */
       muscle_code_grow ("percent_code()", (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2262 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2268 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 39:
-#line 412 "src/parse-gram.y" /* yacc.c:1668  */
+#line 406 "src/parse-gram.y" /* yacc.c:1668  */
     {
       muscle_percent_code_grow ((yyvsp[-1].uniqstr), (yylsp[-1]), (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2271 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2277 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 40:
-#line 422 "src/parse-gram.y" /* yacc.c:1668  */
+#line 416 "src/parse-gram.y" /* yacc.c:1668  */
     { (yyval.code_type) = destructor; }
-#line 2277 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2283 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 41:
-#line 423 "src/parse-gram.y" /* yacc.c:1668  */
+#line 417 "src/parse-gram.y" /* yacc.c:1668  */
     { (yyval.code_type) = printer; }
-#line 2283 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2289 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 42:
-#line 433 "src/parse-gram.y" /* yacc.c:1668  */
+#line 427 "src/parse-gram.y" /* yacc.c:1668  */
     {}
-#line 2289 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2295 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 43:
-#line 434 "src/parse-gram.y" /* yacc.c:1668  */
+#line 428 "src/parse-gram.y" /* yacc.c:1668  */
     { muscle_code_grow ("union_name", (yyvsp[0].uniqstr), (yylsp[0])); }
-#line 2295 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2301 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 44:
-#line 439 "src/parse-gram.y" /* yacc.c:1668  */
+#line 433 "src/parse-gram.y" /* yacc.c:1668  */
     {
       union_seen = true;
       muscle_code_grow ("union_members", (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2305 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2311 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 45:
-#line 450 "src/parse-gram.y" /* yacc.c:1668  */
+#line 444 "src/parse-gram.y" /* yacc.c:1668  */
     { current_class = nterm_sym; }
-#line 2311 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2317 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 46:
-#line 451 "src/parse-gram.y" /* yacc.c:1668  */
+#line 445 "src/parse-gram.y" /* yacc.c:1668  */
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
-#line 2320 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2326 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 47:
-#line 455 "src/parse-gram.y" /* yacc.c:1668  */
+#line 449 "src/parse-gram.y" /* yacc.c:1668  */
     { current_class = token_sym; }
-#line 2326 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2332 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 48:
-#line 456 "src/parse-gram.y" /* yacc.c:1668  */
+#line 450 "src/parse-gram.y" /* yacc.c:1668  */
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
-#line 2335 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2341 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 49:
-#line 461 "src/parse-gram.y" /* yacc.c:1668  */
+#line 455 "src/parse-gram.y" /* yacc.c:1668  */
     {
       symbol_list *list;
       tag_seen = true;
@@ -2343,11 +2349,11 @@ yyreduce:
         symbol_type_set (list->content.sym, (yyvsp[-1].uniqstr), (yylsp[-1]));
       symbol_list_free ((yyvsp[0].list));
     }
-#line 2347 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2353 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 50:
-#line 472 "src/parse-gram.y" /* yacc.c:1668  */
+#line 466 "src/parse-gram.y" /* yacc.c:1668  */
     {
       symbol_list *list;
       ++current_prec;
@@ -2359,295 +2365,295 @@ yyreduce:
       symbol_list_free ((yyvsp[0].list));
       current_type = NULL;
     }
-#line 2363 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2369 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 51:
-#line 486 "src/parse-gram.y" /* yacc.c:1668  */
+#line 480 "src/parse-gram.y" /* yacc.c:1668  */
     { (yyval.assoc) = left_assoc; }
-#line 2369 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2375 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 52:
-#line 487 "src/parse-gram.y" /* yacc.c:1668  */
+#line 481 "src/parse-gram.y" /* yacc.c:1668  */
     { (yyval.assoc) = right_assoc; }
-#line 2375 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2381 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 53:
-#line 488 "src/parse-gram.y" /* yacc.c:1668  */
+#line 482 "src/parse-gram.y" /* yacc.c:1668  */
     { (yyval.assoc) = non_assoc; }
-#line 2381 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2387 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 54:
-#line 489 "src/parse-gram.y" /* yacc.c:1668  */
+#line 483 "src/parse-gram.y" /* yacc.c:1668  */
     { (yyval.assoc) = precedence_assoc; }
-#line 2387 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2393 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 55:
-#line 493 "src/parse-gram.y" /* yacc.c:1668  */
+#line 487 "src/parse-gram.y" /* yacc.c:1668  */
     { current_type = NULL; }
-#line 2393 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2399 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 56:
-#line 494 "src/parse-gram.y" /* yacc.c:1668  */
+#line 488 "src/parse-gram.y" /* yacc.c:1668  */
     { current_type = (yyvsp[0].uniqstr); tag_seen = true; }
-#line 2399 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2405 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 57:
-#line 500 "src/parse-gram.y" /* yacc.c:1668  */
+#line 494 "src/parse-gram.y" /* yacc.c:1668  */
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-#line 2405 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2411 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 58:
-#line 502 "src/parse-gram.y" /* yacc.c:1668  */
+#line 496 "src/parse-gram.y" /* yacc.c:1668  */
     { (yyval.list) = symbol_list_append ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
-#line 2411 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2417 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 59:
-#line 507 "src/parse-gram.y" /* yacc.c:1668  */
+#line 501 "src/parse-gram.y" /* yacc.c:1668  */
     {
       (yyval.symbol) = (yyvsp[0].symbol);
       symbol_class_set ((yyvsp[0].symbol), token_sym, (yylsp[0]), false);
     }
-#line 2420 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2426 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 60:
-#line 512 "src/parse-gram.y" /* yacc.c:1668  */
+#line 506 "src/parse-gram.y" /* yacc.c:1668  */
     {
       (yyval.symbol) = (yyvsp[-1].symbol);
       symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0]));
       symbol_class_set ((yyvsp[-1].symbol), token_sym, (yylsp[-1]), false);
     }
-#line 2430 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2436 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 61:
-#line 522 "src/parse-gram.y" /* yacc.c:1668  */
+#line 516 "src/parse-gram.y" /* yacc.c:1668  */
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-#line 2436 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2442 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 62:
-#line 524 "src/parse-gram.y" /* yacc.c:1668  */
+#line 518 "src/parse-gram.y" /* yacc.c:1668  */
     { (yyval.list) = symbol_list_append ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
-#line 2442 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2448 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 63:
-#line 528 "src/parse-gram.y" /* yacc.c:1668  */
+#line 522 "src/parse-gram.y" /* yacc.c:1668  */
     { (yyval.list) = (yyvsp[0].list); }
-#line 2448 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2454 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 64:
-#line 529 "src/parse-gram.y" /* yacc.c:1668  */
+#line 523 "src/parse-gram.y" /* yacc.c:1668  */
     { (yyval.list) = symbol_list_append ((yyvsp[-1].list), (yyvsp[0].list)); }
-#line 2454 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2460 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 65:
-#line 533 "src/parse-gram.y" /* yacc.c:1668  */
+#line 527 "src/parse-gram.y" /* yacc.c:1668  */
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-#line 2460 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2466 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 66:
-#line 534 "src/parse-gram.y" /* yacc.c:1668  */
+#line 528 "src/parse-gram.y" /* yacc.c:1668  */
     { (yyval.list) = symbol_list_type_new ((yyvsp[0].uniqstr), (yylsp[0])); }
-#line 2466 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2472 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 68:
-#line 539 "src/parse-gram.y" /* yacc.c:1668  */
+#line 533 "src/parse-gram.y" /* yacc.c:1668  */
     { (yyval.uniqstr) = uniqstr_new ("*"); }
-#line 2472 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2478 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 69:
-#line 540 "src/parse-gram.y" /* yacc.c:1668  */
+#line 534 "src/parse-gram.y" /* yacc.c:1668  */
     { (yyval.uniqstr) = uniqstr_new (""); }
-#line 2478 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2484 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 70:
-#line 546 "src/parse-gram.y" /* yacc.c:1668  */
+#line 540 "src/parse-gram.y" /* yacc.c:1668  */
     {
       current_type = (yyvsp[0].uniqstr);
       tag_seen = true;
     }
-#line 2487 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2493 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 71:
-#line 551 "src/parse-gram.y" /* yacc.c:1668  */
+#line 545 "src/parse-gram.y" /* yacc.c:1668  */
     {
       symbol_class_set ((yyvsp[0].symbol), current_class, (yylsp[0]), true);
       symbol_type_set ((yyvsp[0].symbol), current_type, (yylsp[0]));
     }
-#line 2496 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2502 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 72:
-#line 556 "src/parse-gram.y" /* yacc.c:1668  */
+#line 550 "src/parse-gram.y" /* yacc.c:1668  */
     {
       symbol_class_set ((yyvsp[-1].symbol), current_class, (yylsp[-1]), true);
       symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
       symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0]));
     }
-#line 2506 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2512 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 73:
-#line 562 "src/parse-gram.y" /* yacc.c:1668  */
+#line 556 "src/parse-gram.y" /* yacc.c:1668  */
     {
       symbol_class_set ((yyvsp[-1].symbol), current_class, (yylsp[-1]), true);
       symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
       symbol_make_alias ((yyvsp[-1].symbol), (yyvsp[0].symbol), (yyloc));
     }
-#line 2516 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2522 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 74:
-#line 568 "src/parse-gram.y" /* yacc.c:1668  */
+#line 562 "src/parse-gram.y" /* yacc.c:1668  */
     {
       symbol_class_set ((yyvsp[-2].symbol), current_class, (yylsp[-2]), true);
       symbol_type_set ((yyvsp[-2].symbol), current_type, (yylsp[-2]));
       symbol_user_token_number_set ((yyvsp[-2].symbol), (yyvsp[-1].integer), (yylsp[-1]));
       symbol_make_alias ((yyvsp[-2].symbol), (yyvsp[0].symbol), (yyloc));
     }
-#line 2527 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2533 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 81:
-#line 598 "src/parse-gram.y" /* yacc.c:1668  */
+#line 592 "src/parse-gram.y" /* yacc.c:1668  */
     {
       yyerrok;
     }
-#line 2535 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2541 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 82:
-#line 604 "src/parse-gram.y" /* yacc.c:1668  */
+#line 598 "src/parse-gram.y" /* yacc.c:1668  */
     { current_lhs ((yyvsp[-1].symbol), (yylsp[-1]), (yyvsp[0].named_ref)); }
-#line 2541 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2547 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 83:
-#line 605 "src/parse-gram.y" /* yacc.c:1668  */
+#line 599 "src/parse-gram.y" /* yacc.c:1668  */
     {
     /* Free the current lhs. */
     current_lhs (0, (yylsp[-3]), 0);
   }
-#line 2550 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2556 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 84:
-#line 612 "src/parse-gram.y" /* yacc.c:1668  */
+#line 606 "src/parse-gram.y" /* yacc.c:1668  */
     { grammar_current_rule_end ((yylsp[0])); }
-#line 2556 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2562 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 85:
-#line 613 "src/parse-gram.y" /* yacc.c:1668  */
+#line 607 "src/parse-gram.y" /* yacc.c:1668  */
     { grammar_current_rule_end ((yylsp[0])); }
-#line 2562 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2568 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 87:
-#line 620 "src/parse-gram.y" /* yacc.c:1668  */
+#line 614 "src/parse-gram.y" /* yacc.c:1668  */
     { grammar_current_rule_begin (current_lhs_symbol, current_lhs_location,
                                   current_lhs_named_ref); }
-#line 2569 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2575 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 88:
-#line 623 "src/parse-gram.y" /* yacc.c:1668  */
+#line 617 "src/parse-gram.y" /* yacc.c:1668  */
     { grammar_current_rule_symbol_append ((yyvsp[-1].symbol), (yylsp[-1]), (yyvsp[0].named_ref)); }
-#line 2575 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2581 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 89:
-#line 625 "src/parse-gram.y" /* yacc.c:1668  */
+#line 619 "src/parse-gram.y" /* yacc.c:1668  */
     { grammar_current_rule_action_append ((yyvsp[-1].code), (yylsp[-1]), (yyvsp[0].named_ref), false); }
-#line 2581 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2587 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 90:
-#line 627 "src/parse-gram.y" /* yacc.c:1668  */
+#line 621 "src/parse-gram.y" /* yacc.c:1668  */
     { grammar_current_rule_action_append ((yyvsp[0].code), (yylsp[0]), NULL, true); }
-#line 2587 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2593 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 91:
-#line 629 "src/parse-gram.y" /* yacc.c:1668  */
+#line 623 "src/parse-gram.y" /* yacc.c:1668  */
     { grammar_current_rule_empty_set ((yylsp[0])); }
-#line 2593 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2599 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 92:
-#line 631 "src/parse-gram.y" /* yacc.c:1668  */
+#line 625 "src/parse-gram.y" /* yacc.c:1668  */
     { grammar_current_rule_prec_set ((yyvsp[0].symbol), (yylsp[0])); }
-#line 2599 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2605 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 93:
-#line 633 "src/parse-gram.y" /* yacc.c:1668  */
+#line 627 "src/parse-gram.y" /* yacc.c:1668  */
     { grammar_current_rule_dprec_set ((yyvsp[0].integer), (yylsp[0])); }
-#line 2605 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2611 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 94:
-#line 635 "src/parse-gram.y" /* yacc.c:1668  */
+#line 629 "src/parse-gram.y" /* yacc.c:1668  */
     { grammar_current_rule_merge_set ((yyvsp[0].uniqstr), (yylsp[0])); }
-#line 2611 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2617 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 95:
-#line 639 "src/parse-gram.y" /* yacc.c:1668  */
+#line 633 "src/parse-gram.y" /* yacc.c:1668  */
     { (yyval.named_ref) = 0; }
-#line 2617 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2623 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 96:
-#line 640 "src/parse-gram.y" /* yacc.c:1668  */
+#line 634 "src/parse-gram.y" /* yacc.c:1668  */
     { (yyval.named_ref) = named_ref_new((yyvsp[0].uniqstr), (yylsp[0])); }
-#line 2623 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2629 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 98:
-#line 651 "src/parse-gram.y" /* yacc.c:1668  */
+#line 645 "src/parse-gram.y" /* yacc.c:1668  */
     { (yyval.uniqstr) = uniqstr_new ((yyvsp[0].chars)); }
-#line 2629 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2635 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 99:
-#line 656 "src/parse-gram.y" /* yacc.c:1668  */
+#line 650 "src/parse-gram.y" /* yacc.c:1668  */
     { (yyval.chars) = ""; }
-#line 2635 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2641 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 100:
-#line 657 "src/parse-gram.y" /* yacc.c:1668  */
+#line 651 "src/parse-gram.y" /* yacc.c:1668  */
     { (yyval.chars) = (yyvsp[0].uniqstr); }
-#line 2641 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2647 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 101:
-#line 658 "src/parse-gram.y" /* yacc.c:1668  */
+#line 652 "src/parse-gram.y" /* yacc.c:1668  */
     { (yyval.chars) = (yyvsp[0].chars); }
-#line 2647 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2653 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 102:
-#line 668 "src/parse-gram.y" /* yacc.c:1668  */
+#line 662 "src/parse-gram.y" /* yacc.c:1668  */
     {
       code_props plain_code;
       (yyvsp[0].code)[strlen ((yyvsp[0].code)) - 1] = '\n';
@@ -2656,42 +2662,42 @@ yyreduce:
       gram_scanner_last_string_free ();
       (yyval.chars) = plain_code.code;
     }
-#line 2660 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2666 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 103:
-#line 688 "src/parse-gram.y" /* yacc.c:1668  */
+#line 682 "src/parse-gram.y" /* yacc.c:1668  */
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
-#line 2666 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2672 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 104:
-#line 690 "src/parse-gram.y" /* yacc.c:1668  */
+#line 684 "src/parse-gram.y" /* yacc.c:1668  */
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[0].character)), (yylsp[0]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
       symbol_user_token_number_set ((yyval.symbol), (yyvsp[0].character), (yylsp[0]));
     }
-#line 2676 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2682 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 105:
-#line 698 "src/parse-gram.y" /* yacc.c:1668  */
+#line 692 "src/parse-gram.y" /* yacc.c:1668  */
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
-#line 2682 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2688 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 108:
-#line 710 "src/parse-gram.y" /* yacc.c:1668  */
+#line 704 "src/parse-gram.y" /* yacc.c:1668  */
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[0].chars)), (yylsp[0]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
     }
-#line 2691 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2697 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 110:
-#line 719 "src/parse-gram.y" /* yacc.c:1668  */
+#line 713 "src/parse-gram.y" /* yacc.c:1668  */
     {
       code_props plain_code;
       code_props_plain_init (&plain_code, (yyvsp[0].chars), (yylsp[0]));
@@ -2700,11 +2706,11 @@ yyreduce:
       muscle_code_grow ("epilogue", plain_code.code, (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2704 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2710 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
 
-#line 2708 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2714 "src/parse-gram.c" /* yacc.c:1668  */
         default: break;
       }
     if (yychar_backup != yychar)
@@ -2951,7 +2957,7 @@ yyreturn:
 #endif
   return yyresult;
 }
-#line 729 "src/parse-gram.y" /* yacc.c:1928  */
+#line 723 "src/parse-gram.y" /* yacc.c:1928  */
 
 
 /* Return the location of the left-hand side of a rule whose
