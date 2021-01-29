@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 2.3b.445-2755.  */
+/* A Bison parser, made by GNU Bison 2.4.403-43f2.  */
 
 /* Implementation for Bison's Yacc-like parsers in C
 
@@ -45,7 +45,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "2.3b.445-2755"
+#define YYBISON_VERSION "2.4.403-43f2"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -128,29 +128,8 @@ static void gram_error (location const *, char const *);
 
 static char const *char_name (char);
 
-/** Add a lex-param or a parse-param.
- *
- * \param type  \a lex_param or \a parse_param
- * \param decl  the formal argument
- * \param loc   the location in the source.
- */
-static void add_param (char const *type, char *decl, location loc);
-
-
-static symbol_class current_class = unknown_sym;
-static uniqstr current_type = NULL;
-static symbol *current_lhs;
-static location current_lhs_location;
-static named_ref *current_lhs_named_ref;
-static int current_prec = 0;
-
-#define YYTYPE_INT16 int_fast16_t
-#define YYTYPE_INT8 int_fast8_t
-#define YYTYPE_UINT16 uint_fast16_t
-#define YYTYPE_UINT8 uint_fast8_t
-
 /* Line 191 of yacc.c  */
-#line 154 "src/parse-gram.c"
+#line 133 "src/parse-gram.c"
 
 /* Enabling traces.  */
 #ifndef YYDEBUG
@@ -170,6 +149,23 @@ static int current_prec = 0;
 # define YYTOKEN_TABLE 0
 #endif
 
+/* "%code requires" blocks.  */
+/* Line 211 of yacc.c  */
+#line 201 "src/parse-gram.y"
+
+# ifndef PARAM_TYPE
+#  define PARAM_TYPE
+  typedef enum
+  {
+    param_lex    = 1 << 0,
+    param_parse  = 1 << 1,
+    param_both   = param_lex | param_parse
+  } param_type;
+# endif
+
+
+/* Line 211 of yacc.c  */
+#line 169 "src/parse-gram.c"
 
 /* Tokens.  */
 #ifndef YYTOKENTYPE
@@ -204,34 +200,33 @@ static int current_prec = 0;
      PERCENT_GLR_PARSER = 281,
      PERCENT_INITIAL_ACTION = 282,
      PERCENT_LANGUAGE = 283,
-     PERCENT_LEX_PARAM = 284,
-     PERCENT_NAME_PREFIX = 285,
-     PERCENT_NO_DEFAULT_PREC = 286,
-     PERCENT_NO_LINES = 287,
-     PERCENT_NONDETERMINISTIC_PARSER = 288,
-     PERCENT_OUTPUT = 289,
-     PERCENT_PARSE_PARAM = 290,
-     PERCENT_REQUIRE = 291,
-     PERCENT_SKELETON = 292,
-     PERCENT_START = 293,
-     PERCENT_TOKEN_TABLE = 294,
-     PERCENT_VERBOSE = 295,
-     PERCENT_YACC = 296,
-     BRACED_CODE = 297,
-     CHAR = 298,
-     EPILOGUE = 299,
-     EQUAL = 300,
-     ID = 301,
-     ID_COLON = 302,
-     PERCENT_PERCENT = 303,
-     PIPE = 304,
-     PROLOGUE = 305,
-     SEMICOLON = 306,
-     TAG = 307,
-     TAG_ANY = 308,
-     TAG_NONE = 309,
-     BRACKETED_ID = 310,
-     PERCENT_UNION = 311
+     PERCENT_NAME_PREFIX = 284,
+     PERCENT_NO_DEFAULT_PREC = 285,
+     PERCENT_NO_LINES = 286,
+     PERCENT_NONDETERMINISTIC_PARSER = 287,
+     PERCENT_OUTPUT = 288,
+     PERCENT_REQUIRE = 289,
+     PERCENT_SKELETON = 290,
+     PERCENT_START = 291,
+     PERCENT_TOKEN_TABLE = 292,
+     PERCENT_VERBOSE = 293,
+     PERCENT_YACC = 294,
+     BRACED_CODE = 295,
+     CHAR = 296,
+     EPILOGUE = 297,
+     EQUAL = 298,
+     ID = 299,
+     ID_COLON = 300,
+     PERCENT_PERCENT = 301,
+     PIPE = 302,
+     PROLOGUE = 303,
+     SEMICOLON = 304,
+     TAG = 305,
+     TAG_ANY = 306,
+     TAG_NONE = 307,
+     BRACKETED_ID = 308,
+     PERCENT_PARAM = 309,
+     PERCENT_UNION = 310
    };
 #endif
 /* Tokens.  */
@@ -262,34 +257,33 @@ static int current_prec = 0;
 #define PERCENT_GLR_PARSER 281
 #define PERCENT_INITIAL_ACTION 282
 #define PERCENT_LANGUAGE 283
-#define PERCENT_LEX_PARAM 284
-#define PERCENT_NAME_PREFIX 285
-#define PERCENT_NO_DEFAULT_PREC 286
-#define PERCENT_NO_LINES 287
-#define PERCENT_NONDETERMINISTIC_PARSER 288
-#define PERCENT_OUTPUT 289
-#define PERCENT_PARSE_PARAM 290
-#define PERCENT_REQUIRE 291
-#define PERCENT_SKELETON 292
-#define PERCENT_START 293
-#define PERCENT_TOKEN_TABLE 294
-#define PERCENT_VERBOSE 295
-#define PERCENT_YACC 296
-#define BRACED_CODE 297
-#define CHAR 298
-#define EPILOGUE 299
-#define EQUAL 300
-#define ID 301
-#define ID_COLON 302
-#define PERCENT_PERCENT 303
-#define PIPE 304
-#define PROLOGUE 305
-#define SEMICOLON 306
-#define TAG 307
-#define TAG_ANY 308
-#define TAG_NONE 309
-#define BRACKETED_ID 310
-#define PERCENT_UNION 311
+#define PERCENT_NAME_PREFIX 284
+#define PERCENT_NO_DEFAULT_PREC 285
+#define PERCENT_NO_LINES 286
+#define PERCENT_NONDETERMINISTIC_PARSER 287
+#define PERCENT_OUTPUT 288
+#define PERCENT_REQUIRE 289
+#define PERCENT_SKELETON 290
+#define PERCENT_START 291
+#define PERCENT_TOKEN_TABLE 292
+#define PERCENT_VERBOSE 293
+#define PERCENT_YACC 294
+#define BRACED_CODE 295
+#define CHAR 296
+#define EPILOGUE 297
+#define EQUAL 298
+#define ID 299
+#define ID_COLON 300
+#define PERCENT_PERCENT 301
+#define PIPE 302
+#define PROLOGUE 303
+#define SEMICOLON 304
+#define TAG 305
+#define TAG_ANY 306
+#define TAG_NONE 307
+#define BRACKETED_ID 308
+#define PERCENT_PARAM 309
+#define PERCENT_UNION 310
 
 
 
@@ -298,21 +292,26 @@ static int current_prec = 0;
 typedef union YYSTYPE
 {
 /* Line 216 of yacc.c  */
-#line 94 "src/parse-gram.y"
+#line 88 "src/parse-gram.y"
 
+  assoc assoc;
+  char *code;
+  char const *chars;
+  int integer;
+  named_ref *named_ref;
   symbol *symbol;
   symbol_list *list;
-  int integer;
-  char const *chars;
-  char *code;
-  assoc assoc;
   uniqstr uniqstr;
   unsigned char character;
-  named_ref *named_ref;
+
+/* Line 216 of yacc.c  */
+#line 223 "src/parse-gram.y"
+
+  param_type param;
 
 
 /* Line 216 of yacc.c  */
-#line 316 "src/parse-gram.c"
+#line 315 "src/parse-gram.c"
 } YYSTYPE;
 # define YYSTYPE_IS_TRIVIAL 1
 # define yystype YYSTYPE /* obsolescent; will be withdrawn */
@@ -336,7 +335,37 @@ typedef struct YYLTYPE
 /* Copy the second part of user declarations.  */
 
 /* Line 266 of yacc.c  */
-#line 340 "src/parse-gram.c"
+#line 339 "src/parse-gram.c"
+/* Unqualified %code blocks.  */
+/* Line 267 of yacc.c  */
+#line 56 "src/parse-gram.y"
+
+  static symbol_class current_class = unknown_sym;
+  static uniqstr current_type = NULL;
+  static symbol *current_lhs;
+  static location current_lhs_location;
+  static named_ref *current_lhs_named_ref;
+  static int current_prec = 0;
+
+  #define YYTYPE_INT16 int_fast16_t
+  #define YYTYPE_INT8 int_fast8_t
+  #define YYTYPE_UINT16 uint_fast16_t
+  #define YYTYPE_UINT8 uint_fast8_t
+
+/* Line 267 of yacc.c  */
+#line 213 "src/parse-gram.y"
+
+  /** Add a lex-param and/or a parse-param.
+   *
+   * \param type  where to push this formal argument.
+   * \param decl  the formal argument.  Destroyed.
+   * \param loc   the location in the source.
+   */
+  static void add_param (param_type type, char *decl, location loc);
+
+
+/* Line 267 of yacc.c  */
+#line 369 "src/parse-gram.c"
 
 #ifdef short
 # undef short
@@ -553,21 +582,21 @@ union yyalloc
 /* YYFINAL -- State number of the termination state.  */
 #define YYFINAL  3
 /* YYLAST -- Last index in YYTABLE.  */
-#define YYLAST   161
+#define YYLAST   190
 
 /* YYNTOKENS -- Number of terminals.  */
-#define YYNTOKENS  57
+#define YYNTOKENS  56
 /* YYNNTS -- Number of nonterminals.  */
 #define YYNNTS  34
 /* YYNRULES -- Number of rules.  */
-#define YYNRULES  107
+#define YYNRULES  106
 /* YYNSTATES -- Number of states.  */
-#define YYNSTATES  147
+#define YYNSTATES  145
 
 /* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
    by yylex, with out-of-bounds checking.  */
 #define YYUNDEFTOK  2
-#define YYMAXUTOK   311
+#define YYMAXUTOK   310
 
 #define YYTRANSLATE(YYX)						\
   ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)
@@ -607,24 +636,24 @@ static const yytype_uint8 yytranslate[] =
       25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
       35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
       45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
-      55,    56
+      55
 };
 
 #if YYDEBUG
   /* YYRLINEYYN -- Source line where rule number YYN was defined.    */
 static const yytype_uint16 yyrline[] =
 {
-       0,   207,   207,   215,   217,   221,   222,   232,   236,   241,
-     242,   247,   252,   253,   254,   255,   256,   261,   270,   271,
-     272,   273,   274,   275,   276,   277,   278,   279,   280,   304,
-     305,   306,   307,   311,   312,   313,   317,   324,   331,   335,
-     339,   346,   361,   362,   366,   378,   378,   383,   383,   388,
-     399,   414,   415,   416,   417,   421,   422,   427,   429,   434,
-     435,   440,   442,   447,   448,   452,   453,   454,   455,   460,
-     465,   470,   476,   482,   493,   494,   503,   504,   510,   511,
-     512,   519,   519,   524,   525,   526,   531,   533,   535,   537,
-     539,   541,   546,   548,   559,   560,   565,   566,   567,   576,
-     596,   598,   607,   612,   613,   618,   625,   627
+       0,   244,   244,   252,   254,   258,   259,   269,   273,   278,
+     279,   284,   289,   290,   291,   292,   293,   298,   307,   308,
+     309,   310,   311,   312,   313,   314,   315,   316,   340,   341,
+     342,   343,   352,   353,   354,   358,   365,   372,   376,   380,
+     387,   402,   403,   407,   419,   419,   424,   424,   429,   440,
+     455,   456,   457,   458,   462,   463,   468,   470,   475,   476,
+     481,   483,   488,   489,   493,   494,   495,   496,   501,   506,
+     511,   517,   523,   534,   535,   544,   545,   551,   552,   553,
+     560,   560,   565,   566,   567,   572,   574,   576,   578,   580,
+     582,   587,   589,   600,   601,   606,   607,   608,   617,   637,
+     639,   648,   653,   654,   659,   666,   668
 };
 #endif
 
@@ -640,21 +669,20 @@ static const char *const yytname[] =
   "\"%default-prec\"", "\"%define\"", "\"%defines\"", "\"%error-verbose\"",
   "\"%expect\"", "\"%expect-rr\"", "\"%<flag>\"", "\"%file-prefix\"",
   "\"%glr-parser\"", "\"%initial-action\"", "\"%language\"",
-  "\"%lex-param\"", "\"%name-prefix\"", "\"%no-default-prec\"",
-  "\"%no-lines\"", "\"%nondeterministic-parser\"", "\"%output\"",
-  "\"%parse-param\"", "\"%require\"", "\"%skeleton\"", "\"%start\"",
-  "\"%token-table\"", "\"%verbose\"", "\"%yacc\"", "\"{...}\"", "\"char\"",
-  "\"epilogue\"", "\"=\"", "\"identifier\"", "\"identifier:\"", "\"%%\"",
-  "\"|\"", "\"%{...%}\"", "\";\"", "\"<tag>\"", "\"<*>\"", "\"<>\"",
-  "\"[identifier]\"", "\"%union\"", "$accept", "input",
-  "prologue_declarations", "prologue_declaration", "grammar_declaration",
-  "union_name", "symbol_declaration", "$@1", "$@2",
-  "precedence_declaration", "precedence_declarator", "tag.opt",
-  "symbols.prec", "symbol.prec", "symbols.1", "generic_symlist",
-  "generic_symlist_item", "symbol_def", "symbol_defs.1", "grammar",
-  "rules_or_grammar_declaration", "rules", "$@3", "rhses.1", "rhs",
-  "named_ref.opt", "variable", "content.opt", "braceless", "id",
-  "id_colon", "symbol", "string_as_id", "epilogue.opt", 0
+  "\"%name-prefix\"", "\"%no-default-prec\"", "\"%no-lines\"",
+  "\"%nondeterministic-parser\"", "\"%output\"", "\"%require\"",
+  "\"%skeleton\"", "\"%start\"", "\"%token-table\"", "\"%verbose\"",
+  "\"%yacc\"", "\"{...}\"", "\"char\"", "\"epilogue\"", "\"=\"",
+  "\"identifier\"", "\"identifier:\"", "\"%%\"", "\"|\"", "\"%{...%}\"",
+  "\";\"", "\"<tag>\"", "\"<*>\"", "\"<>\"", "\"[identifier]\"",
+  "\"%param\"", "\"%union\"", "$accept", "input", "prologue_declarations",
+  "prologue_declaration", "grammar_declaration", "union_name",
+  "symbol_declaration", "$@1", "$@2", "precedence_declaration",
+  "precedence_declarator", "tag.opt", "symbols.prec", "symbol.prec",
+  "symbols.1", "generic_symlist", "generic_symlist_item", "symbol_def",
+  "symbol_defs.1", "grammar", "rules_or_grammar_declaration", "rules",
+  "$@3", "rhses.1", "rhs", "named_ref.opt", "variable", "content.opt",
+  "braceless", "id", "id_colon", "symbol", "string_as_id", "epilogue.opt", 0
 };
 #endif
 
@@ -668,16 +696,16 @@ static const yytype_uint16 yytoknum[] =
      275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
      285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
      295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
-     305,   306,   307,   308,   309,   310,   311
+     305,   306,   307,   308,   309,   310
 };
 # endif
 
-#define YYPACT_NINF -136
+#define YYPACT_NINF -88
 
 #define yypact_value_is_default(yystate) \
-  ((yystate) == (-136))
+  ((yystate) == (-88))
 
-#define YYTABLE_NINF -107
+#define YYTABLE_NINF -106
 
 #define yytable_value_is_error(yytable_value) \
   YYID (0)
@@ -686,21 +714,21 @@ static const yytype_uint16 yytoknum[] =
      STATE-NUM.    */
 static const yytype_int16 yypact[] =
 {
-    -136,    36,   103,  -136,  -136,  -136,    -2,    18,    22,  -136,
-    -136,  -136,  -136,    -1,  -136,    32,    66,  -136,    70,    90,
-    -136,    17,  -136,    53,    93,    55,    39,  -136,  -136,  -136,
-      41,    56,    97,    98,     0,  -136,  -136,  -136,    16,  -136,
-    -136,    57,  -136,  -136,  -136,  -136,    52,    30,    30,     0,
-      13,    13,  -136,    63,  -136,  -136,  -136,    35,  -136,  -136,
-    -136,  -136,   114,  -136,  -136,  -136,  -136,   115,  -136,   116,
-    -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,    94,
-    -136,    95,     1,  -136,  -136,    51,  -136,    63,  -136,     0,
-    -136,  -136,    30,    89,    30,     0,  -136,  -136,  -136,  -136,
-      13,  -136,  -136,    13,  -136,  -136,  -136,  -136,  -136,  -136,
-    -136,  -136,  -136,   104,  -136,  -136,  -136,  -136,  -136,     0,
-    -136,   143,  -136,   146,  -136,  -136,  -136,  -136,  -136,  -136,
-    -136,  -136,    19,    37,  -136,  -136,     0,   148,   105,    51,
-      51,    37,  -136,  -136,  -136,  -136,  -136
+     -88,    23,   109,   -88,   -88,   -88,   -15,    -8,     3,   -88,
+     -88,   -88,   -88,    -2,   -88,    14,    37,   -88,    45,    53,
+     -88,     2,   -88,    38,    81,    17,   -88,   -88,   -88,    30,
+      83,    84,    36,   -88,   -88,   -88,    58,   -88,   -88,    49,
+      46,   -88,   -88,   -88,   -88,    41,   -14,   -14,    36,     0,
+       0,   -88,    52,   -88,   -88,   -88,    18,   -88,   -88,   -88,
+     -88,    90,   -88,   -88,   -88,    92,   -88,    93,   -88,   -88,
+     -88,   -88,   -88,   -88,   -88,   -88,    48,   -88,    51,     1,
+     -88,   -88,    55,   -88,   -88,    52,   -88,    36,   -88,   -88,
+     -14,    50,   -14,    36,   -88,   -88,   -88,   -88,     0,   -88,
+     -88,     0,   -88,   -88,   -88,   -88,   -88,   -88,   -88,   -88,
+     -88,    56,   -88,   -88,   -88,   -88,   -88,    36,   -88,    97,
+     -88,   101,   -88,   -88,   -88,   -88,   -88,   -88,   -88,   -88,
+     -23,   146,   -88,   -88,    36,   102,    59,    55,    55,   146,
+     -88,   -88,   -88,   -88,   -88
 };
 
   /* YYDEFACT[S] -- default reduction number in state S.  Performed when
@@ -708,39 +736,39 @@ static const yytype_int16 yypact[] =
      is an error.    */
 static const yytype_uint8 yydefact[] =
 {
-       3,     0,     0,     1,    47,    45,     0,     0,     0,    51,
-      52,    53,    54,     0,    38,     0,     9,    11,     0,     0,
-       7,     0,    16,     0,     0,     0,     0,    39,    22,    23,
-       0,     0,     0,     0,     0,    29,    30,    31,     0,     6,
-      32,    42,     4,     5,    34,    33,    55,     0,     0,     0,
-       0,     0,    99,     0,    40,    95,    94,    96,    10,    12,
-      13,    14,     0,    17,    18,    19,    20,     0,    24,     0,
-      26,    27,    28,   105,   101,   100,   103,    35,   104,     0,
-     102,     0,     0,    76,    78,    92,    43,     0,    56,     0,
-      69,    74,    48,    70,    46,    49,    61,    66,    67,    68,
-      36,    63,    65,    37,    41,    98,    97,     8,    15,    21,
-      25,    80,    79,     0,    77,     2,    93,    81,    44,    50,
-      57,    59,    75,    71,    72,    62,    64,   107,    86,    58,
-      60,    73,    82,    83,    86,    85,     0,     0,     0,    92,
-      92,    84,    89,    90,    91,    88,    87
+       3,     0,     0,     1,    46,    44,     0,     0,     0,    50,
+      51,    52,    53,     0,    37,     0,     9,    11,     0,     0,
+       7,     0,    16,     0,     0,     0,    38,    21,    22,     0,
+       0,     0,     0,    28,    29,    30,     0,     6,    31,     0,
+      41,     4,     5,    33,    32,    54,     0,     0,     0,     0,
+       0,    98,     0,    39,    94,    93,    95,    10,    12,    13,
+      14,     0,    17,    18,    19,     0,    23,     0,    26,    27,
+     104,   100,    99,   102,    34,   103,     0,   101,     0,     0,
+      75,    77,    91,    25,    42,     0,    55,     0,    68,    73,
+      47,    69,    45,    48,    60,    65,    66,    67,    35,    62,
+      64,    36,    40,    97,    96,     8,    15,    20,    24,    79,
+      78,     0,    76,     2,    92,    80,    43,    49,    56,    58,
+      74,    70,    71,    61,    63,   106,    85,    57,    59,    72,
+      81,    82,    85,    84,     0,     0,     0,    91,    91,    83,
+      88,    89,    90,    87,    86
 };
 
   /* YYPGOTO[NTERM-NUM].    */
-static const yytype_int16 yypgoto[] =
+static const yytype_int8 yypgoto[] =
 {
-    -136,  -136,  -136,  -136,   153,  -136,  -136,  -136,  -136,  -136,
-    -136,  -136,  -136,    31,  -136,   107,   -13,    -3,   108,  -136,
-      78,  -136,  -136,  -136,    27,  -135,  -136,  -136,   -16,   -17,
-    -136,   -34,   -35,  -136
+     -88,   -88,   -88,   -88,   103,   -88,   -88,   -88,   -88,   -88,
+     -88,   -88,   -88,    -7,   -88,    61,   -76,   -11,    65,   -88,
+      44,   -88,   -88,   -88,    19,   -55,   -88,   -88,   -37,   -18,
+     -88,   -32,   -87,   -88
 };
 
   /* YYDEFGOTO[NTERM-NUM].    */
 static const yytype_int16 yydefgoto[] =
 {
-      -1,     1,     2,    42,    81,    87,    44,    48,    47,    45,
-      46,    89,   119,   120,    95,   100,   101,    91,    92,    82,
-      83,    84,   128,   132,   133,   117,    57,   107,    54,    76,
-      85,   102,    78,   115
+      -1,     1,     2,    41,    78,    85,    43,    47,    46,    44,
+      45,    87,   117,   118,    93,    98,    99,    89,    90,    79,
+      80,    81,   126,   130,   131,   115,    56,   105,    53,    73,
+      82,   100,    75,   113
 };
 
   /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
@@ -748,81 +776,87 @@ static const yytype_int16 yydefgoto[] =
      number is the opposite.  If YYTABLE_NINF, syntax error.    */
 static const yytype_int16 yytable[] =
 {
-      77,  -106,    79,    73,   145,   146,     4,     5,     6,     7,
-       8,     9,    10,    11,    12,    96,    73,    79,    13,    14,
-      61,     4,     5,     6,     7,     8,     9,    10,    11,    12,
-      93,    93,    27,    13,    14,    55,     3,   104,   105,    34,
-      73,    52,    66,    74,    68,    53,    75,    27,    80,   113,
-      49,   136,   137,   138,    34,   121,    74,    41,   124,    75,
-      50,   125,    62,    80,    51,    97,    98,    99,   134,    58,
-     135,   118,    41,    74,    59,    93,    75,    93,    56,   139,
-      74,   106,    90,    75,    67,   121,    69,   126,   131,   122,
-     126,   122,    73,   123,    60,    63,    64,    65,    70,   140,
-      71,    72,   142,    86,    88,    52,   116,   140,     4,     5,
-       6,     7,     8,     9,    10,    11,    12,   108,   109,   110,
-      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
-      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
-      33,    34,    35,    36,    37,   111,   112,   130,   127,    73,
-     129,    38,   143,    39,    40,    43,    94,   144,   103,    41,
-     114,   141
+      74,  -105,    76,    70,   122,    60,     4,     5,     6,     7,
+       8,     9,    10,    11,    12,   102,    94,    54,    13,    14,
+      64,   103,   124,     3,   132,   124,   133,    71,    91,    91,
+      72,    26,    49,    66,   129,    48,    88,    32,    51,    70,
+      57,    71,    52,    50,    72,    61,    77,   111,   116,    58,
+      95,    96,    97,    70,   121,   119,    40,    59,    55,    76,
+      65,   123,   104,     4,     5,     6,     7,     8,     9,    10,
+      11,    12,    91,    67,    91,    13,    14,    71,    62,   120,
+      72,   120,   143,   144,    63,   119,    68,    69,    26,    83,
+      84,    86,    51,   106,    32,   107,   108,   109,   125,   138,
+     110,   128,   140,    77,    70,    42,   141,   138,   114,   142,
+     127,   101,    92,    40,     4,     5,     6,     7,     8,     9,
+      10,    11,    12,   112,     0,     0,    13,    14,    15,    16,
+      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
+      27,    28,    29,    30,    31,    32,    33,    34,    35,    70,
+       0,   139,     0,     0,     0,    36,     0,    37,    38,     0,
+     134,   135,   136,    39,    40,     0,     0,     0,     0,     0,
+       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
+       0,     0,     0,     0,     0,     0,   137,    71,     0,     0,
+      72
 };
 
-static const yytype_uint8 yycheck[] =
+static const yytype_int16 yycheck[] =
 {
-      34,     0,     1,     3,   139,   140,     5,     6,     7,     8,
-       9,    10,    11,    12,    13,    49,     3,     1,    17,    18,
-       3,     5,     6,     7,     8,     9,    10,    11,    12,    13,
-      47,    48,    31,    17,    18,     3,     0,    53,     3,    38,
-       3,    42,     3,    43,     3,    46,    46,    31,    47,    48,
-      52,    14,    15,    16,    38,    89,    43,    56,    93,    46,
-      42,    95,    45,    47,    42,    52,    53,    54,    49,     3,
-      51,    87,    56,    43,     4,    92,    46,    94,    46,    42,
-      43,    46,    52,    46,    45,   119,    45,   100,   123,    92,
-     103,    94,     3,     4,     4,    42,     3,    42,    42,   133,
-       3,     3,   136,    46,    52,    42,    55,   141,     5,     6,
-       7,     8,     9,    10,    11,    12,    13,     3,     3,     3,
-      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
-      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
-      37,    38,    39,    40,    41,    51,    51,     4,    44,     3,
-     119,    48,     4,    50,    51,     2,    48,    52,    51,    56,
-      82,   134
+      32,     0,     1,     3,    91,     3,     5,     6,     7,     8,
+       9,    10,    11,    12,    13,    52,    48,     3,    17,    18,
+       3,     3,    98,     0,    47,   101,    49,    41,    46,    47,
+      44,    30,    40,     3,   121,    50,    50,    36,    40,     3,
+       3,    41,    44,    40,    44,    43,    45,    46,    85,     4,
+      50,    51,    52,     3,     4,    87,    55,     4,    44,     1,
+      43,    93,    44,     5,     6,     7,     8,     9,    10,    11,
+      12,    13,    90,    43,    92,    17,    18,    41,    40,    90,
+      44,    92,   137,   138,     3,   117,     3,     3,    30,    40,
+      44,    50,    40,     3,    36,     3,     3,    49,    42,   131,
+      49,     4,   134,    45,     3,     2,     4,   139,    53,    50,
+     117,    50,    47,    55,     5,     6,     7,     8,     9,    10,
+      11,    12,    13,    79,    -1,    -1,    17,    18,    19,    20,
+      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
+      31,    32,    33,    34,    35,    36,    37,    38,    39,     3,
+      -1,   132,    -1,    -1,    -1,    46,    -1,    48,    49,    -1,
+      14,    15,    16,    54,    55,    -1,    -1,    -1,    -1,    -1,
+      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
+      -1,    -1,    -1,    -1,    -1,    -1,    40,    41,    -1,    -1,
+      44
 };
 
   /* STOS_[STATE-NUM] -- The (internal number of the) accessing
      symbol of state STATE-NUM.    */
 static const yytype_uint8 yystos[] =
 {
-       0,    58,    59,     0,     5,     6,     7,     8,     9,    10,
+       0,    57,    58,     0,     5,     6,     7,     8,     9,    10,
       11,    12,    13,    17,    18,    19,    20,    21,    22,    23,
       24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
-      34,    35,    36,    37,    38,    39,    40,    41,    48,    50,
-      51,    56,    60,    61,    63,    66,    67,    65,    64,    52,
-      42,    42,    42,    46,    85,     3,    46,    83,     3,     4,
-       4,     3,    45,    42,     3,    42,     3,    45,     3,    45,
-      42,     3,     3,     3,    43,    46,    86,    88,    89,     1,
-      47,    61,    76,    77,    78,    87,    46,    62,    52,    68,
-      52,    74,    75,    86,    75,    71,    88,    52,    53,    54,
-      72,    73,    88,    72,    85,     3,    46,    84,     3,     3,
-       3,    51,    51,    48,    77,    90,    55,    82,    85,    69,
-      70,    88,    74,     4,    89,    88,    73,    44,    79,    70,
-       4,    89,    80,    81,    49,    51,    14,    15,    16,    42,
-      88,    81,    88,     4,    52,    82,    82
+      34,    35,    36,    37,    38,    39,    46,    48,    49,    54,
+      55,    59,    60,    62,    65,    66,    64,    63,    50,    40,
+      40,    40,    44,    84,     3,    44,    82,     3,     4,     4,
+       3,    43,    40,     3,     3,    43,     3,    43,     3,     3,
+       3,    41,    44,    85,    87,    88,     1,    45,    60,    75,
+      76,    77,    86,    40,    44,    61,    50,    67,    50,    73,
+      74,    85,    74,    70,    87,    50,    51,    52,    71,    72,
+      87,    71,    84,     3,    44,    83,     3,     3,     3,    49,
+      49,    46,    76,    89,    53,    81,    84,    68,    69,    87,
+      73,     4,    88,    87,    72,    42,    78,    69,     4,    88,
+      79,    80,    47,    49,    14,    15,    16,    40,    87,    80,
+      87,     4,    50,    81,    81
 };
 
   /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.    */
 static const yytype_uint8 yyr1[] =
 {
-       0,    57,    58,    59,    59,    60,    60,    60,    60,    60,
-      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
-      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
-      60,    60,    60,    61,    61,    61,    61,    61,    61,    61,
-      61,    61,    62,    62,    61,    64,    63,    65,    63,    63,
-      66,    67,    67,    67,    67,    68,    68,    69,    69,    70,
-      70,    71,    71,    72,    72,    73,    73,    73,    73,    74,
-      74,    74,    74,    74,    75,    75,    76,    76,    77,    77,
-      77,    79,    78,    80,    80,    80,    81,    81,    81,    81,
-      81,    81,    82,    82,    83,    83,    84,    84,    84,    85,
-      86,    86,    87,    88,    88,    89,    90,    90
+       0,    56,    57,    58,    58,    59,    59,    59,    59,    59,
+      59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
+      59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
+      59,    59,    60,    60,    60,    60,    60,    60,    60,    60,
+      60,    61,    61,    60,    63,    62,    64,    62,    62,    65,
+      66,    66,    66,    66,    67,    67,    68,    68,    69,    69,
+      70,    70,    71,    71,    72,    72,    72,    72,    73,    73,
+      73,    73,    73,    74,    74,    75,    75,    76,    76,    76,
+      78,    77,    79,    79,    79,    80,    80,    80,    80,    80,
+      80,    81,    81,    82,    82,    83,    83,    83,    84,    85,
+      85,    86,    87,    87,    88,    89,    89
 };
 
   /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.    */
@@ -830,15 +864,15 @@ static const yytype_uint8 yyr2[] =
 {
        0,     2,     4,     0,     2,     1,     1,     1,     3,     1,
        2,     1,     2,     2,     2,     3,     1,     2,     2,     2,
-       2,     3,     1,     1,     2,     3,     2,     2,     2,     1,
-       1,     1,     1,     1,     1,     2,     3,     3,     1,     1,
-       2,     3,     0,     1,     3,     0,     3,     0,     3,     3,
-       3,     1,     1,     1,     1,     0,     1,     1,     2,     1,
-       2,     1,     2,     1,     2,     1,     1,     1,     1,     1,
-       1,     2,     2,     3,     1,     2,     1,     2,     1,     2,
-       2,     0,     4,     1,     3,     2,     0,     3,     3,     3,
-       3,     3,     0,     1,     1,     1,     0,     1,     1,     1,
-       1,     1,     1,     1,     1,     1,     0,     2
+       3,     1,     1,     2,     3,     2,     2,     2,     1,     1,
+       1,     1,     1,     1,     2,     3,     3,     1,     1,     2,
+       3,     0,     1,     3,     0,     3,     0,     3,     3,     3,
+       1,     1,     1,     1,     0,     1,     1,     2,     1,     2,
+       1,     2,     1,     2,     1,     1,     1,     1,     1,     1,
+       2,     2,     3,     1,     2,     1,     2,     1,     2,     2,
+       0,     4,     1,     3,     2,     0,     3,     3,     3,     3,
+       3,     0,     1,     1,     1,     0,     1,     1,     1,     1,
+       1,     1,     1,     1,     1,     0,     2
 };
 
 
@@ -990,154 +1024,174 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
             case 3: // "string"
 
 /* Line 653 of yacc.c  */
-#line 183 "src/parse-gram.y"
+#line 175 "src/parse-gram.y"
         { fputs (quotearg_style (c_quoting_style, ((*yyvaluep).chars)), stderr); }
 /* Line 653 of yacc.c  */
-#line 997 "src/parse-gram.c"
+#line 1031 "src/parse-gram.c"
         break;
 
             case 4: // "integer"
 
 /* Line 653 of yacc.c  */
-#line 196 "src/parse-gram.y"
+#line 188 "src/parse-gram.y"
         { fprintf (stderr, "%d", ((*yyvaluep).integer)); }
 /* Line 653 of yacc.c  */
-#line 1006 "src/parse-gram.c"
+#line 1040 "src/parse-gram.c"
         break;
 
             case 24: // "%<flag>"
 
 /* Line 653 of yacc.c  */
-#line 192 "src/parse-gram.y"
+#line 184 "src/parse-gram.y"
         { fprintf (stderr, "%%%s", ((*yyvaluep).uniqstr)); }
 /* Line 653 of yacc.c  */
-#line 1015 "src/parse-gram.c"
+#line 1049 "src/parse-gram.c"
         break;
 
-            case 42: // "{...}"
+            case 40: // "{...}"
 
 /* Line 653 of yacc.c  */
-#line 185 "src/parse-gram.y"
+#line 177 "src/parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).code)); }
 /* Line 653 of yacc.c  */
-#line 1024 "src/parse-gram.c"
+#line 1058 "src/parse-gram.c"
         break;
 
-            case 43: // "char"
+            case 41: // "char"
 
 /* Line 653 of yacc.c  */
-#line 177 "src/parse-gram.y"
+#line 169 "src/parse-gram.y"
         { fputs (char_name (((*yyvaluep).character)), stderr); }
 /* Line 653 of yacc.c  */
-#line 1033 "src/parse-gram.c"
+#line 1067 "src/parse-gram.c"
         break;
 
-            case 44: // "epilogue"
+            case 42: // "epilogue"
 
 /* Line 653 of yacc.c  */
-#line 185 "src/parse-gram.y"
+#line 177 "src/parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); }
 /* Line 653 of yacc.c  */
-#line 1042 "src/parse-gram.c"
+#line 1076 "src/parse-gram.c"
         break;
 
-            case 46: // "identifier"
+            case 44: // "identifier"
 
 /* Line 653 of yacc.c  */
-#line 190 "src/parse-gram.y"
+#line 182 "src/parse-gram.y"
         { fputs (((*yyvaluep).uniqstr), stderr); }
 /* Line 653 of yacc.c  */
-#line 1051 "src/parse-gram.c"
+#line 1085 "src/parse-gram.c"
         break;
 
-            case 47: // "identifier:"
+            case 45: // "identifier:"
 
 /* Line 653 of yacc.c  */
-#line 191 "src/parse-gram.y"
+#line 183 "src/parse-gram.y"
         { fprintf (stderr, "%s:", ((*yyvaluep).uniqstr)); }
 /* Line 653 of yacc.c  */
-#line 1060 "src/parse-gram.c"
+#line 1094 "src/parse-gram.c"
         break;
 
-            case 50: // "%{...%}"
+            case 48: // "%{...%}"
 
 /* Line 653 of yacc.c  */
-#line 185 "src/parse-gram.y"
+#line 177 "src/parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); }
 /* Line 653 of yacc.c  */
-#line 1069 "src/parse-gram.c"
+#line 1103 "src/parse-gram.c"
         break;
 
-            case 52: // "<tag>"
+            case 50: // "<tag>"
 
 /* Line 653 of yacc.c  */
-#line 193 "src/parse-gram.y"
+#line 185 "src/parse-gram.y"
         { fprintf (stderr, "<%s>", ((*yyvaluep).uniqstr)); }
 /* Line 653 of yacc.c  */
-#line 1078 "src/parse-gram.c"
+#line 1112 "src/parse-gram.c"
+        break;
+
+            case 54: // "%param"
+
+/* Line 653 of yacc.c  */
+#line 228 "src/parse-gram.y"
+        {
+  switch (((*yyvaluep).param))
+    {
+#define CASE(In, Out)                                           \
+      case param_ ## In:   fputs ("%" #Out, stderr); break
+
+      CASE(lex,   lex-param);
+      CASE(parse, parse-param);
+      CASE(both,  param);
+    }
+#undef CASE
+}
+/* Line 653 of yacc.c  */
+#line 1132 "src/parse-gram.c"
         break;
 
-            case 83: // variable
+            case 82: // variable
 
 /* Line 653 of yacc.c  */
-#line 190 "src/parse-gram.y"
+#line 182 "src/parse-gram.y"
         { fputs (((*yyvaluep).uniqstr), stderr); }
 /* Line 653 of yacc.c  */
-#line 1087 "src/parse-gram.c"
+#line 1141 "src/parse-gram.c"
         break;
 
-            case 84: // content.opt
+            case 83: // content.opt
 
 /* Line 653 of yacc.c  */
-#line 185 "src/parse-gram.y"
+#line 177 "src/parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); }
 /* Line 653 of yacc.c  */
-#line 1096 "src/parse-gram.c"
+#line 1150 "src/parse-gram.c"
         break;
 
-            case 85: // braceless
+            case 84: // braceless
 
 /* Line 653 of yacc.c  */
-#line 185 "src/parse-gram.y"
+#line 177 "src/parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); }
 /* Line 653 of yacc.c  */
-#line 1105 "src/parse-gram.c"
+#line 1159 "src/parse-gram.c"
         break;
 
-            case 86: // id
+            case 85: // id
 
 /* Line 653 of yacc.c  */
-#line 199 "src/parse-gram.y"
+#line 191 "src/parse-gram.y"
         { fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); }
 /* Line 653 of yacc.c  */
-#line 1114 "src/parse-gram.c"
+#line 1168 "src/parse-gram.c"
         break;
 
-            case 87: // id_colon
+            case 86: // id_colon
 
 /* Line 653 of yacc.c  */
-#line 200 "src/parse-gram.y"
+#line 192 "src/parse-gram.y"
         { fprintf (stderr, "%s:", ((*yyvaluep).symbol)->tag); }
 /* Line 653 of yacc.c  */
-#line 1123 "src/parse-gram.c"
+#line 1177 "src/parse-gram.c"
         break;
 
-            case 88: // symbol
+            case 87: // symbol
 
 /* Line 653 of yacc.c  */
-#line 199 "src/parse-gram.y"
+#line 191 "src/parse-gram.y"
         { fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); }
 /* Line 653 of yacc.c  */
-#line 1132 "src/parse-gram.c"
+#line 1186 "src/parse-gram.c"
         break;
 
-            case 89: // string_as_id
+            case 88: // string_as_id
 
 /* Line 653 of yacc.c  */
-#line 199 "src/parse-gram.y"
+#line 191 "src/parse-gram.y"
         { fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); }
 /* Line 653 of yacc.c  */
-#line 1141 "src/parse-gram.c"
+#line 1195 "src/parse-gram.c"
         break;
 
       default:
@@ -1653,7 +1707,7 @@ YYLTYPE yylloc;
 
 /* User initialization code.  */
 /* Line 1175 of yacc.c  */
-#line 86 "src/parse-gram.y"
+#line 80 "src/parse-gram.y"
 {
   /* Bison's grammar can initial empty locations, hence a default
      location is needed. */
@@ -1661,7 +1715,7 @@ YYLTYPE yylloc;
   boundary_set (&yylloc.end, current_file, 1, 1);
 }
 /* Line 1175 of yacc.c  */
-#line 1665 "src/parse-gram.c"
+#line 1719 "src/parse-gram.c"
   yylsp[0] = yylloc;
 
   goto yysetstate;
@@ -1848,7 +1902,7 @@ yyreduce:
     {
         case 6:
 /* Line 1388 of yacc.c  */
-#line 223 "src/parse-gram.y"
+#line 260 "src/parse-gram.y"
     {
       code_props plain_code;
       code_props_plain_init (&plain_code, (yyvsp[0].chars), (yylsp[0]));
@@ -1859,106 +1913,106 @@ yyreduce:
       code_scanner_last_string_free ();
     }
 /* Line 1388 of yacc.c  */
-#line 1863 "src/parse-gram.c"
+#line 1917 "src/parse-gram.c"
     break;
 
   case 7:
 /* Line 1388 of yacc.c  */
-#line 233 "src/parse-gram.y"
+#line 270 "src/parse-gram.y"
     {
       muscle_percent_define_ensure ((yyvsp[0].uniqstr), (yylsp[0]), true);
     }
 /* Line 1388 of yacc.c  */
-#line 1873 "src/parse-gram.c"
+#line 1927 "src/parse-gram.c"
     break;
 
   case 8:
 /* Line 1388 of yacc.c  */
-#line 237 "src/parse-gram.y"
+#line 274 "src/parse-gram.y"
     {
       muscle_percent_define_insert ((yyvsp[-1].uniqstr), (yylsp[-1]), (yyvsp[0].chars),
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
     }
 /* Line 1388 of yacc.c  */
-#line 1884 "src/parse-gram.c"
+#line 1938 "src/parse-gram.c"
     break;
 
   case 9:
 /* Line 1388 of yacc.c  */
-#line 241 "src/parse-gram.y"
+#line 278 "src/parse-gram.y"
     { defines_flag = true; }
 /* Line 1388 of yacc.c  */
-#line 1892 "src/parse-gram.c"
+#line 1946 "src/parse-gram.c"
     break;
 
   case 10:
 /* Line 1388 of yacc.c  */
-#line 243 "src/parse-gram.y"
+#line 280 "src/parse-gram.y"
     {
       defines_flag = true;
       spec_defines_file = xstrdup ((yyvsp[0].chars));
     }
 /* Line 1388 of yacc.c  */
-#line 1903 "src/parse-gram.c"
+#line 1957 "src/parse-gram.c"
     break;
 
   case 11:
 /* Line 1388 of yacc.c  */
-#line 248 "src/parse-gram.y"
+#line 285 "src/parse-gram.y"
     {
       muscle_percent_define_insert ("parse.error", (yylsp[0]), "verbose",
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
     }
 /* Line 1388 of yacc.c  */
-#line 1914 "src/parse-gram.c"
+#line 1968 "src/parse-gram.c"
     break;
 
   case 12:
 /* Line 1388 of yacc.c  */
-#line 252 "src/parse-gram.y"
+#line 289 "src/parse-gram.y"
     { expected_sr_conflicts = (yyvsp[0].integer); }
 /* Line 1388 of yacc.c  */
-#line 1922 "src/parse-gram.c"
+#line 1976 "src/parse-gram.c"
     break;
 
   case 13:
 /* Line 1388 of yacc.c  */
-#line 253 "src/parse-gram.y"
+#line 290 "src/parse-gram.y"
     { expected_rr_conflicts = (yyvsp[0].integer); }
 /* Line 1388 of yacc.c  */
-#line 1930 "src/parse-gram.c"
+#line 1984 "src/parse-gram.c"
     break;
 
   case 14:
 /* Line 1388 of yacc.c  */
-#line 254 "src/parse-gram.y"
+#line 291 "src/parse-gram.y"
     { spec_file_prefix = (yyvsp[0].chars); }
 /* Line 1388 of yacc.c  */
-#line 1938 "src/parse-gram.c"
+#line 1992 "src/parse-gram.c"
     break;
 
   case 15:
 /* Line 1388 of yacc.c  */
-#line 255 "src/parse-gram.y"
+#line 292 "src/parse-gram.y"
     { spec_file_prefix = (yyvsp[0].chars); }
 /* Line 1388 of yacc.c  */
-#line 1946 "src/parse-gram.c"
+#line 2000 "src/parse-gram.c"
     break;
 
   case 16:
 /* Line 1388 of yacc.c  */
-#line 257 "src/parse-gram.y"
+#line 294 "src/parse-gram.y"
     {
       nondeterministic_parser = true;
       glr_parser = true;
     }
 /* Line 1388 of yacc.c  */
-#line 1957 "src/parse-gram.c"
+#line 2011 "src/parse-gram.c"
     break;
 
   case 17:
 /* Line 1388 of yacc.c  */
-#line 262 "src/parse-gram.y"
+#line 299 "src/parse-gram.y"
     {
       code_props action;
       code_props_symbol_action_init (&action, (yyvsp[0].code), (yylsp[0]));
@@ -1968,92 +2022,84 @@ yyreduce:
       code_scanner_last_string_free ();
     }
 /* Line 1388 of yacc.c  */
-#line 1972 "src/parse-gram.c"
+#line 2026 "src/parse-gram.c"
     break;
 
   case 18:
 /* Line 1388 of yacc.c  */
-#line 270 "src/parse-gram.y"
+#line 307 "src/parse-gram.y"
     { language_argmatch ((yyvsp[0].chars), grammar_prio, (yylsp[-1])); }
 /* Line 1388 of yacc.c  */
-#line 1980 "src/parse-gram.c"
+#line 2034 "src/parse-gram.c"
     break;
 
   case 19:
 /* Line 1388 of yacc.c  */
-#line 271 "src/parse-gram.y"
-    { add_param ("lex_param", (yyvsp[0].code), (yylsp[0])); }
+#line 308 "src/parse-gram.y"
+    { spec_name_prefix = (yyvsp[0].chars); }
 /* Line 1388 of yacc.c  */
-#line 1988 "src/parse-gram.c"
+#line 2042 "src/parse-gram.c"
     break;
 
   case 20:
 /* Line 1388 of yacc.c  */
-#line 272 "src/parse-gram.y"
+#line 309 "src/parse-gram.y"
     { spec_name_prefix = (yyvsp[0].chars); }
 /* Line 1388 of yacc.c  */
-#line 1996 "src/parse-gram.c"
+#line 2050 "src/parse-gram.c"
     break;
 
   case 21:
 /* Line 1388 of yacc.c  */
-#line 273 "src/parse-gram.y"
-    { spec_name_prefix = (yyvsp[0].chars); }
+#line 310 "src/parse-gram.y"
+    { no_lines_flag = true; }
 /* Line 1388 of yacc.c  */
-#line 2004 "src/parse-gram.c"
+#line 2058 "src/parse-gram.c"
     break;
 
   case 22:
 /* Line 1388 of yacc.c  */
-#line 274 "src/parse-gram.y"
-    { no_lines_flag = true; }
+#line 311 "src/parse-gram.y"
+    { nondeterministic_parser = true; }
 /* Line 1388 of yacc.c  */
-#line 2012 "src/parse-gram.c"
+#line 2066 "src/parse-gram.c"
     break;
 
   case 23:
 /* Line 1388 of yacc.c  */
-#line 275 "src/parse-gram.y"
-    { nondeterministic_parser = true; }
+#line 312 "src/parse-gram.y"
+    { spec_outfile = (yyvsp[0].chars); }
 /* Line 1388 of yacc.c  */
-#line 2020 "src/parse-gram.c"
+#line 2074 "src/parse-gram.c"
     break;
 
   case 24:
 /* Line 1388 of yacc.c  */
-#line 276 "src/parse-gram.y"
+#line 313 "src/parse-gram.y"
     { spec_outfile = (yyvsp[0].chars); }
 /* Line 1388 of yacc.c  */
-#line 2028 "src/parse-gram.c"
+#line 2082 "src/parse-gram.c"
     break;
 
   case 25:
 /* Line 1388 of yacc.c  */
-#line 277 "src/parse-gram.y"
-    { spec_outfile = (yyvsp[0].chars); }
+#line 314 "src/parse-gram.y"
+    { add_param ((yyvsp[-1].param), (yyvsp[0].code), (yylsp[0])); }
 /* Line 1388 of yacc.c  */
-#line 2036 "src/parse-gram.c"
+#line 2090 "src/parse-gram.c"
     break;
 
   case 26:
 /* Line 1388 of yacc.c  */
-#line 278 "src/parse-gram.y"
-    { add_param ("parse_param", (yyvsp[0].code), (yylsp[0])); }
-/* Line 1388 of yacc.c  */
-#line 2044 "src/parse-gram.c"
-    break;
-
-  case 27:
-/* Line 1388 of yacc.c  */
-#line 279 "src/parse-gram.y"
+#line 315 "src/parse-gram.y"
     { version_check (&(yylsp[0]), (yyvsp[0].chars)); }
 /* Line 1388 of yacc.c  */
-#line 2052 "src/parse-gram.c"
+#line 2098 "src/parse-gram.c"
     break;
 
-  case 28:
+  case 27:
 /* Line 1388 of yacc.c  */
-#line 281 "src/parse-gram.y"
+#line 317 "src/parse-gram.y"
     {
       char const *skeleton_user = (yyvsp[0].chars);
       if (strchr (skeleton_user, '/'))
@@ -2078,46 +2124,46 @@ yyreduce:
       skeleton_arg (skeleton_user, grammar_prio, (yylsp[-1]));
     }
 /* Line 1388 of yacc.c  */
-#line 2082 "src/parse-gram.c"
+#line 2128 "src/parse-gram.c"
     break;
 
-  case 29:
+  case 28:
 /* Line 1388 of yacc.c  */
-#line 304 "src/parse-gram.y"
+#line 340 "src/parse-gram.y"
     { token_table_flag = true; }
 /* Line 1388 of yacc.c  */
-#line 2090 "src/parse-gram.c"
+#line 2136 "src/parse-gram.c"
     break;
 
-  case 30:
+  case 29:
 /* Line 1388 of yacc.c  */
-#line 305 "src/parse-gram.y"
+#line 341 "src/parse-gram.y"
     { report_flag |= report_states; }
 /* Line 1388 of yacc.c  */
-#line 2098 "src/parse-gram.c"
+#line 2144 "src/parse-gram.c"
     break;
 
-  case 31:
+  case 30:
 /* Line 1388 of yacc.c  */
-#line 306 "src/parse-gram.y"
+#line 342 "src/parse-gram.y"
     { yacc_flag = true; }
 /* Line 1388 of yacc.c  */
-#line 2106 "src/parse-gram.c"
+#line 2152 "src/parse-gram.c"
     break;
 
-  case 35:
+  case 34:
 /* Line 1388 of yacc.c  */
-#line 314 "src/parse-gram.y"
+#line 355 "src/parse-gram.y"
     {
       grammar_start_symbol_set ((yyvsp[0].symbol), (yylsp[0]));
     }
 /* Line 1388 of yacc.c  */
-#line 2116 "src/parse-gram.c"
+#line 2162 "src/parse-gram.c"
     break;
 
-  case 36:
+  case 35:
 /* Line 1388 of yacc.c  */
-#line 318 "src/parse-gram.y"
+#line 359 "src/parse-gram.y"
     {
       symbol_list *list;
       for (list = (yyvsp[0].list); list; list = list->next)
@@ -2125,12 +2171,12 @@ yyreduce:
       symbol_list_free ((yyvsp[0].list));
     }
 /* Line 1388 of yacc.c  */
-#line 2129 "src/parse-gram.c"
+#line 2175 "src/parse-gram.c"
     break;
 
-  case 37:
+  case 36:
 /* Line 1388 of yacc.c  */
-#line 325 "src/parse-gram.y"
+#line 366 "src/parse-gram.y"
     {
       symbol_list *list;
       for (list = (yyvsp[0].list); list; list = list->next)
@@ -2138,32 +2184,32 @@ yyreduce:
       symbol_list_free ((yyvsp[0].list));
     }
 /* Line 1388 of yacc.c  */
-#line 2142 "src/parse-gram.c"
+#line 2188 "src/parse-gram.c"
     break;
 
-  case 38:
+  case 37:
 /* Line 1388 of yacc.c  */
-#line 332 "src/parse-gram.y"
+#line 373 "src/parse-gram.y"
     {
       default_prec = true;
     }
 /* Line 1388 of yacc.c  */
-#line 2152 "src/parse-gram.c"
+#line 2198 "src/parse-gram.c"
     break;
 
-  case 39:
+  case 38:
 /* Line 1388 of yacc.c  */
-#line 336 "src/parse-gram.y"
+#line 377 "src/parse-gram.y"
     {
       default_prec = false;
     }
 /* Line 1388 of yacc.c  */
-#line 2162 "src/parse-gram.c"
+#line 2208 "src/parse-gram.c"
     break;
 
-  case 40:
+  case 39:
 /* Line 1388 of yacc.c  */
-#line 340 "src/parse-gram.y"
+#line 381 "src/parse-gram.y"
     {
       /* Do not invoke muscle_percent_code_grow here since it invokes
          muscle_user_name_list_grow.  */
@@ -2171,89 +2217,89 @@ yyreduce:
       code_scanner_last_string_free ();
     }
 /* Line 1388 of yacc.c  */
-#line 2175 "src/parse-gram.c"
+#line 2221 "src/parse-gram.c"
     break;
 
-  case 41:
+  case 40:
 /* Line 1388 of yacc.c  */
-#line 347 "src/parse-gram.y"
+#line 388 "src/parse-gram.y"
     {
       muscle_percent_code_grow ((yyvsp[-1].uniqstr), (yylsp[-1]), (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
 /* Line 1388 of yacc.c  */
-#line 2186 "src/parse-gram.c"
+#line 2232 "src/parse-gram.c"
     break;
 
-  case 42:
+  case 41:
 /* Line 1388 of yacc.c  */
-#line 361 "src/parse-gram.y"
+#line 402 "src/parse-gram.y"
     {}
 /* Line 1388 of yacc.c  */
-#line 2194 "src/parse-gram.c"
+#line 2240 "src/parse-gram.c"
     break;
 
-  case 43:
+  case 42:
 /* Line 1388 of yacc.c  */
-#line 362 "src/parse-gram.y"
+#line 403 "src/parse-gram.y"
     { muscle_code_grow ("union_name", (yyvsp[0].uniqstr), (yylsp[0])); }
 /* Line 1388 of yacc.c  */
-#line 2202 "src/parse-gram.c"
+#line 2248 "src/parse-gram.c"
     break;
 
-  case 44:
+  case 43:
 /* Line 1388 of yacc.c  */
-#line 367 "src/parse-gram.y"
+#line 408 "src/parse-gram.y"
     {
       union_seen = true;
       muscle_code_grow ("stype", (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
 /* Line 1388 of yacc.c  */
-#line 2214 "src/parse-gram.c"
+#line 2260 "src/parse-gram.c"
     break;
 
-  case 45:
+  case 44:
 /* Line 1388 of yacc.c  */
-#line 378 "src/parse-gram.y"
+#line 419 "src/parse-gram.y"
     { current_class = nterm_sym; }
 /* Line 1388 of yacc.c  */
-#line 2222 "src/parse-gram.c"
+#line 2268 "src/parse-gram.c"
     break;
 
-  case 46:
+  case 45:
 /* Line 1388 of yacc.c  */
-#line 379 "src/parse-gram.y"
+#line 420 "src/parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
 /* Line 1388 of yacc.c  */
-#line 2233 "src/parse-gram.c"
+#line 2279 "src/parse-gram.c"
     break;
 
-  case 47:
+  case 46:
 /* Line 1388 of yacc.c  */
-#line 383 "src/parse-gram.y"
+#line 424 "src/parse-gram.y"
     { current_class = token_sym; }
 /* Line 1388 of yacc.c  */
-#line 2241 "src/parse-gram.c"
+#line 2287 "src/parse-gram.c"
     break;
 
-  case 48:
+  case 47:
 /* Line 1388 of yacc.c  */
-#line 384 "src/parse-gram.y"
+#line 425 "src/parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
 /* Line 1388 of yacc.c  */
-#line 2252 "src/parse-gram.c"
+#line 2298 "src/parse-gram.c"
     break;
 
-  case 49:
+  case 48:
 /* Line 1388 of yacc.c  */
-#line 389 "src/parse-gram.y"
+#line 430 "src/parse-gram.y"
     {
       symbol_list *list;
       tag_seen = true;
@@ -2262,12 +2308,12 @@ yyreduce:
       symbol_list_free ((yyvsp[0].list));
     }
 /* Line 1388 of yacc.c  */
-#line 2266 "src/parse-gram.c"
+#line 2312 "src/parse-gram.c"
     break;
 
-  case 50:
+  case 49:
 /* Line 1388 of yacc.c  */
-#line 400 "src/parse-gram.y"
+#line 441 "src/parse-gram.y"
     {
       symbol_list *list;
       ++current_prec;
@@ -2280,202 +2326,202 @@ yyreduce:
       current_type = NULL;
     }
 /* Line 1388 of yacc.c  */
-#line 2284 "src/parse-gram.c"
+#line 2330 "src/parse-gram.c"
     break;
 
-  case 51:
+  case 50:
 /* Line 1388 of yacc.c  */
-#line 414 "src/parse-gram.y"
+#line 455 "src/parse-gram.y"
     { (yyval.assoc) = left_assoc; }
 /* Line 1388 of yacc.c  */
-#line 2292 "src/parse-gram.c"
+#line 2338 "src/parse-gram.c"
     break;
 
-  case 52:
+  case 51:
 /* Line 1388 of yacc.c  */
-#line 415 "src/parse-gram.y"
+#line 456 "src/parse-gram.y"
     { (yyval.assoc) = right_assoc; }
 /* Line 1388 of yacc.c  */
-#line 2300 "src/parse-gram.c"
+#line 2346 "src/parse-gram.c"
     break;
 
-  case 53:
+  case 52:
 /* Line 1388 of yacc.c  */
-#line 416 "src/parse-gram.y"
+#line 457 "src/parse-gram.y"
     { (yyval.assoc) = non_assoc; }
 /* Line 1388 of yacc.c  */
-#line 2308 "src/parse-gram.c"
+#line 2354 "src/parse-gram.c"
     break;
 
-  case 54:
+  case 53:
 /* Line 1388 of yacc.c  */
-#line 417 "src/parse-gram.y"
+#line 458 "src/parse-gram.y"
     { (yyval.assoc) = precedence_assoc; }
 /* Line 1388 of yacc.c  */
-#line 2316 "src/parse-gram.c"
+#line 2362 "src/parse-gram.c"
     break;
 
-  case 55:
+  case 54:
 /* Line 1388 of yacc.c  */
-#line 421 "src/parse-gram.y"
+#line 462 "src/parse-gram.y"
     { current_type = NULL; }
 /* Line 1388 of yacc.c  */
-#line 2324 "src/parse-gram.c"
+#line 2370 "src/parse-gram.c"
     break;
 
-  case 56:
+  case 55:
 /* Line 1388 of yacc.c  */
-#line 422 "src/parse-gram.y"
+#line 463 "src/parse-gram.y"
     { current_type = (yyvsp[0].uniqstr); tag_seen = true; }
 /* Line 1388 of yacc.c  */
-#line 2332 "src/parse-gram.c"
+#line 2378 "src/parse-gram.c"
     break;
 
-  case 57:
+  case 56:
 /* Line 1388 of yacc.c  */
-#line 428 "src/parse-gram.y"
+#line 469 "src/parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
 /* Line 1388 of yacc.c  */
-#line 2340 "src/parse-gram.c"
+#line 2386 "src/parse-gram.c"
     break;
 
-  case 58:
+  case 57:
 /* Line 1388 of yacc.c  */
-#line 430 "src/parse-gram.y"
+#line 471 "src/parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
 /* Line 1388 of yacc.c  */
-#line 2348 "src/parse-gram.c"
+#line 2394 "src/parse-gram.c"
     break;
 
-  case 59:
+  case 58:
 /* Line 1388 of yacc.c  */
-#line 434 "src/parse-gram.y"
+#line 475 "src/parse-gram.y"
     { (yyval.symbol) = (yyvsp[0].symbol); }
 /* Line 1388 of yacc.c  */
-#line 2356 "src/parse-gram.c"
+#line 2402 "src/parse-gram.c"
     break;
 
-  case 60:
+  case 59:
 /* Line 1388 of yacc.c  */
-#line 435 "src/parse-gram.y"
+#line 476 "src/parse-gram.y"
     { (yyval.symbol) = (yyvsp[-1].symbol); symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0])); }
 /* Line 1388 of yacc.c  */
-#line 2364 "src/parse-gram.c"
+#line 2410 "src/parse-gram.c"
     break;
 
-  case 61:
+  case 60:
 /* Line 1388 of yacc.c  */
-#line 441 "src/parse-gram.y"
+#line 482 "src/parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
 /* Line 1388 of yacc.c  */
-#line 2372 "src/parse-gram.c"
+#line 2418 "src/parse-gram.c"
     break;
 
-  case 62:
+  case 61:
 /* Line 1388 of yacc.c  */
-#line 443 "src/parse-gram.y"
+#line 484 "src/parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
 /* Line 1388 of yacc.c  */
-#line 2380 "src/parse-gram.c"
+#line 2426 "src/parse-gram.c"
     break;
 
-  case 63:
+  case 62:
 /* Line 1388 of yacc.c  */
-#line 447 "src/parse-gram.y"
+#line 488 "src/parse-gram.y"
     { (yyval.list) = (yyvsp[0].list); }
 /* Line 1388 of yacc.c  */
-#line 2388 "src/parse-gram.c"
+#line 2434 "src/parse-gram.c"
     break;
 
-  case 64:
+  case 63:
 /* Line 1388 of yacc.c  */
-#line 448 "src/parse-gram.y"
+#line 489 "src/parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), (yyvsp[0].list)); }
 /* Line 1388 of yacc.c  */
-#line 2396 "src/parse-gram.c"
+#line 2442 "src/parse-gram.c"
     break;
 
-  case 65:
+  case 64:
 /* Line 1388 of yacc.c  */
-#line 452 "src/parse-gram.y"
+#line 493 "src/parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
 /* Line 1388 of yacc.c  */
-#line 2404 "src/parse-gram.c"
+#line 2450 "src/parse-gram.c"
     break;
 
-  case 66:
+  case 65:
 /* Line 1388 of yacc.c  */
-#line 453 "src/parse-gram.y"
+#line 494 "src/parse-gram.y"
     { (yyval.list) = symbol_list_type_new ((yyvsp[0].uniqstr), (yylsp[0])); }
 /* Line 1388 of yacc.c  */
-#line 2412 "src/parse-gram.c"
+#line 2458 "src/parse-gram.c"
     break;
 
-  case 67:
+  case 66:
 /* Line 1388 of yacc.c  */
-#line 454 "src/parse-gram.y"
+#line 495 "src/parse-gram.y"
     { (yyval.list) = symbol_list_default_tagged_new ((yylsp[0])); }
 /* Line 1388 of yacc.c  */
-#line 2420 "src/parse-gram.c"
+#line 2466 "src/parse-gram.c"
     break;
 
-  case 68:
+  case 67:
 /* Line 1388 of yacc.c  */
-#line 455 "src/parse-gram.y"
+#line 496 "src/parse-gram.y"
     { (yyval.list) = symbol_list_default_tagless_new ((yylsp[0])); }
 /* Line 1388 of yacc.c  */
-#line 2428 "src/parse-gram.c"
+#line 2474 "src/parse-gram.c"
     break;
 
-  case 69:
+  case 68:
 /* Line 1388 of yacc.c  */
-#line 461 "src/parse-gram.y"
+#line 502 "src/parse-gram.y"
     {
        current_type = (yyvsp[0].uniqstr);
        tag_seen = true;
      }
 /* Line 1388 of yacc.c  */
-#line 2439 "src/parse-gram.c"
+#line 2485 "src/parse-gram.c"
     break;
 
-  case 70:
+  case 69:
 /* Line 1388 of yacc.c  */
-#line 466 "src/parse-gram.y"
+#line 507 "src/parse-gram.y"
     {
        symbol_class_set ((yyvsp[0].symbol), current_class, (yylsp[0]), true);
        symbol_type_set ((yyvsp[0].symbol), current_type, (yylsp[0]));
      }
 /* Line 1388 of yacc.c  */
-#line 2450 "src/parse-gram.c"
+#line 2496 "src/parse-gram.c"
     break;
 
-  case 71:
+  case 70:
 /* Line 1388 of yacc.c  */
-#line 471 "src/parse-gram.y"
+#line 512 "src/parse-gram.y"
     {
       symbol_class_set ((yyvsp[-1].symbol), current_class, (yylsp[-1]), true);
       symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
       symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0]));
     }
 /* Line 1388 of yacc.c  */
-#line 2462 "src/parse-gram.c"
+#line 2508 "src/parse-gram.c"
     break;
 
-  case 72:
+  case 71:
 /* Line 1388 of yacc.c  */
-#line 477 "src/parse-gram.y"
+#line 518 "src/parse-gram.y"
     {
       symbol_class_set ((yyvsp[-1].symbol), current_class, (yylsp[-1]), true);
       symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
       symbol_make_alias ((yyvsp[-1].symbol), (yyvsp[0].symbol), (yyloc));
     }
 /* Line 1388 of yacc.c  */
-#line 2474 "src/parse-gram.c"
+#line 2520 "src/parse-gram.c"
     break;
 
-  case 73:
+  case 72:
 /* Line 1388 of yacc.c  */
-#line 483 "src/parse-gram.y"
+#line 524 "src/parse-gram.y"
     {
       symbol_class_set ((yyvsp[-2].symbol), current_class, (yylsp[-2]), true);
       symbol_type_set ((yyvsp[-2].symbol), current_type, (yylsp[-2]));
@@ -2483,136 +2529,136 @@ yyreduce:
       symbol_make_alias ((yyvsp[-2].symbol), (yyvsp[0].symbol), (yyloc));
     }
 /* Line 1388 of yacc.c  */
-#line 2487 "src/parse-gram.c"
+#line 2533 "src/parse-gram.c"
     break;
 
-  case 80:
+  case 79:
 /* Line 1388 of yacc.c  */
-#line 513 "src/parse-gram.y"
+#line 554 "src/parse-gram.y"
     {
       yyerrok;
     }
 /* Line 1388 of yacc.c  */
-#line 2497 "src/parse-gram.c"
+#line 2543 "src/parse-gram.c"
     break;
 
-  case 81:
+  case 80:
 /* Line 1388 of yacc.c  */
-#line 519 "src/parse-gram.y"
+#line 560 "src/parse-gram.y"
     { current_lhs = (yyvsp[-1].symbol); current_lhs_location = (yylsp[-1]);
     current_lhs_named_ref = (yyvsp[0].named_ref); }
 /* Line 1388 of yacc.c  */
-#line 2506 "src/parse-gram.c"
+#line 2552 "src/parse-gram.c"
     break;
 
-  case 83:
+  case 82:
 /* Line 1388 of yacc.c  */
-#line 524 "src/parse-gram.y"
+#line 565 "src/parse-gram.y"
     { grammar_current_rule_end ((yylsp[0])); }
 /* Line 1388 of yacc.c  */
-#line 2514 "src/parse-gram.c"
+#line 2560 "src/parse-gram.c"
     break;
 
-  case 84:
+  case 83:
 /* Line 1388 of yacc.c  */
-#line 525 "src/parse-gram.y"
+#line 566 "src/parse-gram.y"
     { grammar_current_rule_end ((yylsp[0])); }
 /* Line 1388 of yacc.c  */
-#line 2522 "src/parse-gram.c"
+#line 2568 "src/parse-gram.c"
     break;
 
-  case 86:
+  case 85:
 /* Line 1388 of yacc.c  */
-#line 531 "src/parse-gram.y"
+#line 572 "src/parse-gram.y"
     { grammar_current_rule_begin (current_lhs, current_lhs_location,
 				  current_lhs_named_ref); }
 /* Line 1388 of yacc.c  */
-#line 2531 "src/parse-gram.c"
+#line 2577 "src/parse-gram.c"
     break;
 
-  case 87:
+  case 86:
 /* Line 1388 of yacc.c  */
-#line 534 "src/parse-gram.y"
+#line 575 "src/parse-gram.y"
     { grammar_current_rule_symbol_append ((yyvsp[-1].symbol), (yylsp[-1]), (yyvsp[0].named_ref)); }
 /* Line 1388 of yacc.c  */
-#line 2539 "src/parse-gram.c"
+#line 2585 "src/parse-gram.c"
     break;
 
-  case 88:
+  case 87:
 /* Line 1388 of yacc.c  */
-#line 536 "src/parse-gram.y"
+#line 577 "src/parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[-1].code), (yylsp[-1]), (yyvsp[0].named_ref)); }
 /* Line 1388 of yacc.c  */
-#line 2547 "src/parse-gram.c"
+#line 2593 "src/parse-gram.c"
     break;
 
-  case 89:
+  case 88:
 /* Line 1388 of yacc.c  */
-#line 538 "src/parse-gram.y"
+#line 579 "src/parse-gram.y"
     { grammar_current_rule_prec_set ((yyvsp[0].symbol), (yylsp[0])); }
 /* Line 1388 of yacc.c  */
-#line 2555 "src/parse-gram.c"
+#line 2601 "src/parse-gram.c"
     break;
 
-  case 90:
+  case 89:
 /* Line 1388 of yacc.c  */
-#line 540 "src/parse-gram.y"
+#line 581 "src/parse-gram.y"
     { grammar_current_rule_dprec_set ((yyvsp[0].integer), (yylsp[0])); }
 /* Line 1388 of yacc.c  */
-#line 2563 "src/parse-gram.c"
+#line 2609 "src/parse-gram.c"
     break;
 
-  case 91:
+  case 90:
 /* Line 1388 of yacc.c  */
-#line 542 "src/parse-gram.y"
+#line 583 "src/parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[0].uniqstr), (yylsp[0])); }
 /* Line 1388 of yacc.c  */
-#line 2571 "src/parse-gram.c"
+#line 2617 "src/parse-gram.c"
     break;
 
-  case 92:
+  case 91:
 /* Line 1388 of yacc.c  */
-#line 546 "src/parse-gram.y"
+#line 587 "src/parse-gram.y"
     { (yyval.named_ref) = 0; }
 /* Line 1388 of yacc.c  */
-#line 2579 "src/parse-gram.c"
+#line 2625 "src/parse-gram.c"
     break;
 
-  case 93:
+  case 92:
 /* Line 1388 of yacc.c  */
-#line 548 "src/parse-gram.y"
+#line 589 "src/parse-gram.y"
     { (yyval.named_ref) = named_ref_new((yyvsp[0].uniqstr), (yylsp[0])); }
 /* Line 1388 of yacc.c  */
-#line 2587 "src/parse-gram.c"
+#line 2633 "src/parse-gram.c"
     break;
 
-  case 95:
+  case 94:
 /* Line 1388 of yacc.c  */
-#line 560 "src/parse-gram.y"
+#line 601 "src/parse-gram.y"
     { (yyval.uniqstr) = uniqstr_new ((yyvsp[0].chars)); }
 /* Line 1388 of yacc.c  */
-#line 2595 "src/parse-gram.c"
+#line 2641 "src/parse-gram.c"
     break;
 
-  case 96:
+  case 95:
 /* Line 1388 of yacc.c  */
-#line 565 "src/parse-gram.y"
+#line 606 "src/parse-gram.y"
     { (yyval.chars) = ""; }
 /* Line 1388 of yacc.c  */
-#line 2603 "src/parse-gram.c"
+#line 2649 "src/parse-gram.c"
     break;
 
-  case 97:
+  case 96:
 /* Line 1388 of yacc.c  */
-#line 566 "src/parse-gram.y"
+#line 607 "src/parse-gram.y"
     { (yyval.chars) = (yyvsp[0].uniqstr); }
 /* Line 1388 of yacc.c  */
-#line 2611 "src/parse-gram.c"
+#line 2657 "src/parse-gram.c"
     break;
 
-  case 99:
+  case 98:
 /* Line 1388 of yacc.c  */
-#line 577 "src/parse-gram.y"
+#line 618 "src/parse-gram.y"
     {
       code_props plain_code;
       (yyvsp[0].code)[strlen ((yyvsp[0].code)) - 1] = '\n';
@@ -2622,51 +2668,51 @@ yyreduce:
       (yyval.chars) = plain_code.code;
     }
 /* Line 1388 of yacc.c  */
-#line 2626 "src/parse-gram.c"
+#line 2672 "src/parse-gram.c"
     break;
 
-  case 100:
+  case 99:
 /* Line 1388 of yacc.c  */
-#line 597 "src/parse-gram.y"
+#line 638 "src/parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
 /* Line 1388 of yacc.c  */
-#line 2634 "src/parse-gram.c"
+#line 2680 "src/parse-gram.c"
     break;
 
-  case 101:
+  case 100:
 /* Line 1388 of yacc.c  */
-#line 599 "src/parse-gram.y"
+#line 640 "src/parse-gram.y"
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[0].character)), (yylsp[0]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
       symbol_user_token_number_set ((yyval.symbol), (yyvsp[0].character), (yylsp[0]));
     }
 /* Line 1388 of yacc.c  */
-#line 2646 "src/parse-gram.c"
+#line 2692 "src/parse-gram.c"
     break;
 
-  case 102:
+  case 101:
 /* Line 1388 of yacc.c  */
-#line 607 "src/parse-gram.y"
+#line 648 "src/parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
 /* Line 1388 of yacc.c  */
-#line 2654 "src/parse-gram.c"
+#line 2700 "src/parse-gram.c"
     break;
 
-  case 105:
+  case 104:
 /* Line 1388 of yacc.c  */
-#line 619 "src/parse-gram.y"
+#line 660 "src/parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[0].chars)), (yylsp[0]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
     }
 /* Line 1388 of yacc.c  */
-#line 2665 "src/parse-gram.c"
+#line 2711 "src/parse-gram.c"
     break;
 
-  case 107:
+  case 106:
 /* Line 1388 of yacc.c  */
-#line 628 "src/parse-gram.y"
+#line 669 "src/parse-gram.y"
     {
       code_props plain_code;
       code_props_plain_init (&plain_code, (yyvsp[0].chars), (yylsp[0]));
@@ -2676,12 +2722,12 @@ yyreduce:
       code_scanner_last_string_free ();
     }
 /* Line 1388 of yacc.c  */
-#line 2680 "src/parse-gram.c"
+#line 2726 "src/parse-gram.c"
     break;
 
 
 /* Line 1388 of yacc.c  */
-#line 2685 "src/parse-gram.c"
+#line 2731 "src/parse-gram.c"
       default: break;
     }
   YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);
@@ -2898,7 +2944,7 @@ yyreturn:
 }
 
 /* Line 1607 of yacc.c  */
-#line 638 "src/parse-gram.y"
+#line 679 "src/parse-gram.y"
 
 
 
@@ -2932,11 +2978,8 @@ lloc_default (YYLTYPE const *rhs, int n)
 }
 
 
-/* Add a lex-param or a parse-param (depending on TYPE) with
-   declaration DECL and location LOC.  */
-
 static void
-add_param (char const *type, char *decl, location loc)
+add_param (param_type type, char *decl, location loc)
 {
   static char const alphanum[26 + 26 + 1 + 10] =
     "abcdefghijklmnopqrstuvwxyz"
@@ -2976,7 +3019,10 @@ add_param (char const *type, char *decl, location loc)
       name = xmalloc (name_len + 1);
       memcpy (name, name_start, name_len);
       name[name_len] = '\0';
-      muscle_pair_list_grow (type, decl, name);
+      if (type & param_lex)
+        muscle_pair_list_grow ("lex_param", decl, name);
+      if (type & param_parse)
+        muscle_pair_list_grow ("parse_param", decl, name);
       free (name);
     }
 
