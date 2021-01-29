@@ -124,7 +124,7 @@ extern int gram_debug;
 
   #include "symlist.h"
   #include "symtab.h"
-#line 215 "src/parse-gram.y" /* yacc.c:353  */
+#line 214 "src/parse-gram.y" /* yacc.c:353  */
 
   typedef enum
   {
@@ -133,7 +133,7 @@ extern int gram_debug;
     param_parse  = 1 << 1,
     param_both   = param_lex | param_parse
   } param_type;
-#line 634 "src/parse-gram.y" /* yacc.c:353  */
+#line 627 "src/parse-gram.y" /* yacc.c:353  */
 
   #include "muscle-tab.h"
   typedef struct
@@ -167,44 +167,43 @@ extern int gram_debug;
     PERCENT_DEFAULT_PREC = 272,
     PERCENT_DEFINE = 273,
     PERCENT_DEFINES = 274,
-    PERCENT_ERROR_VERBOSE = 275,
-    PERCENT_EXPECT = 276,
-    PERCENT_EXPECT_RR = 277,
-    PERCENT_FLAG = 278,
-    PERCENT_FILE_PREFIX = 279,
-    PERCENT_GLR_PARSER = 280,
-    PERCENT_INITIAL_ACTION = 281,
-    PERCENT_LANGUAGE = 282,
-    PERCENT_NAME_PREFIX = 283,
-    PERCENT_NO_DEFAULT_PREC = 284,
-    PERCENT_NO_LINES = 285,
-    PERCENT_NONDETERMINISTIC_PARSER = 286,
-    PERCENT_OUTPUT = 287,
-    PERCENT_REQUIRE = 288,
-    PERCENT_SKELETON = 289,
-    PERCENT_START = 290,
-    PERCENT_TOKEN_TABLE = 291,
-    PERCENT_VERBOSE = 292,
-    PERCENT_YACC = 293,
-    BRACED_CODE = 294,
-    BRACED_PREDICATE = 295,
-    BRACKETED_ID = 296,
-    CHAR = 297,
-    EPILOGUE = 298,
-    EQUAL = 299,
-    ID = 300,
-    ID_COLON = 301,
-    PERCENT_PERCENT = 302,
-    PIPE = 303,
-    PROLOGUE = 304,
-    SEMICOLON = 305,
-    TAG = 306,
-    TAG_ANY = 307,
-    TAG_NONE = 308,
-    INT = 309,
-    PERCENT_PARAM = 310,
-    PERCENT_UNION = 311,
-    PERCENT_EMPTY = 312
+    PERCENT_EXPECT = 275,
+    PERCENT_EXPECT_RR = 276,
+    PERCENT_FLAG = 277,
+    PERCENT_FILE_PREFIX = 278,
+    PERCENT_GLR_PARSER = 279,
+    PERCENT_INITIAL_ACTION = 280,
+    PERCENT_LANGUAGE = 281,
+    PERCENT_NAME_PREFIX = 282,
+    PERCENT_NO_DEFAULT_PREC = 283,
+    PERCENT_NO_LINES = 284,
+    PERCENT_NONDETERMINISTIC_PARSER = 285,
+    PERCENT_OUTPUT = 286,
+    PERCENT_REQUIRE = 287,
+    PERCENT_SKELETON = 288,
+    PERCENT_START = 289,
+    PERCENT_TOKEN_TABLE = 290,
+    PERCENT_VERBOSE = 291,
+    PERCENT_YACC = 292,
+    BRACED_CODE = 293,
+    BRACED_PREDICATE = 294,
+    BRACKETED_ID = 295,
+    CHAR = 296,
+    EPILOGUE = 297,
+    EQUAL = 298,
+    ID = 299,
+    ID_COLON = 300,
+    PERCENT_PERCENT = 301,
+    PIPE = 302,
+    PROLOGUE = 303,
+    SEMICOLON = 304,
+    TAG = 305,
+    TAG_ANY = 306,
+    TAG_NONE = 307,
+    INT = 308,
+    PERCENT_PARAM = 309,
+    PERCENT_UNION = 310,
+    PERCENT_EMPTY = 311
   };
 #endif
 
@@ -231,11 +230,11 @@ union GRAM_STYPE
   /* "integer"  */
   int INT;
   /* named_ref.opt  */
-  named_ref* yytype_87;
+  named_ref* yytype_86;
   /* "%param"  */
   param_type PERCENT_PARAM;
   /* symbol.prec  */
-  symbol* yytype_74;
+  symbol* yytype_73;
   /* id  */
   symbol* id;
   /* id_colon  */
@@ -245,9 +244,9 @@ union GRAM_STYPE
   /* string_as_id  */
   symbol* string_as_id;
   /* symbols.prec  */
-  symbol_list* yytype_73;
+  symbol_list* yytype_72;
   /* symbols.1  */
-  symbol_list* yytype_75;
+  symbol_list* yytype_74;
   /* generic_symlist  */
   symbol_list* generic_symlist;
   /* generic_symlist_item  */
@@ -270,7 +269,7 @@ union GRAM_STYPE
   unsigned char CHAR;
   /* value  */
   value_type value;
-#line 274 "src/parse-gram.c" /* yacc.c:353  */
+#line 273 "src/parse-gram.c" /* yacc.c:353  */
 };
 
 typedef union GRAM_STYPE GRAM_STYPE;
@@ -364,7 +363,7 @@ int gram_parse (void);
   #define YYTYPE_INT8 int_fast8_t
   #define YYTYPE_UINT16 uint_fast16_t
   #define YYTYPE_UINT8 uint_fast8_t
-#line 225 "src/parse-gram.y" /* yacc.c:356  */
+#line 224 "src/parse-gram.y" /* yacc.c:356  */
 
   /** Add a lex-param and/or a parse-param.
    *
@@ -375,7 +374,7 @@ int gram_parse (void);
   static void add_param (param_type type, char *decl, location loc);
   static param_type current_param = param_none;
 
-#line 379 "src/parse-gram.c" /* yacc.c:356  */
+#line 378 "src/parse-gram.c" /* yacc.c:356  */
 
 #ifdef short
 # undef short
@@ -587,27 +586,27 @@ union yyalloc
 /* YYFINAL -- State number of the termination state.  */
 #define YYFINAL  3
 /* YYLAST -- Last index in YYTABLE.  */
-#define YYLAST   158
+#define YYLAST   180
 
 /* YYNTOKENS -- Number of terminals.  */
-#define YYNTOKENS  58
+#define YYNTOKENS  57
 /* YYNNTS -- Number of nonterminals.  */
 #define YYNNTS  37
 /* YYNRULES -- Number of rules.  */
-#define YYNRULES  109
+#define YYNRULES  108
 /* YYNSTATES -- Number of states.  */
-#define YYNSTATES  144
+#define YYNSTATES  143
 
-/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
-   by yylex, with out-of-bounds checking.  */
 #define YYUNDEFTOK  2
-#define YYMAXUTOK   312
+#define YYMAXUTOK   311
 
+/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
+   as returned by yylex, with out-of-bounds checking.  */
 #define YYTRANSLATE(YYX)                                                \
   ((unsigned) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)
 
 /* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
-   as returned by yylex, without out-of-bounds checking.  */
+   as returned by yylex.  */
 static const yytype_uint8 yytranslate[] =
 {
        0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
@@ -641,24 +640,24 @@ static const yytype_uint8 yytranslate[] =
       25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
       35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
       45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
-      55,    56,    57
+      55,    56
 };
 
 #if GRAM_DEBUG
   /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
 static const yytype_uint16 yyrline[] =
 {
-       0,   257,   257,   266,   267,   271,   272,   278,   282,   287,
-     288,   293,   299,   300,   301,   302,   307,   312,   313,   314,
-     315,   316,   317,   317,   318,   319,   343,   344,   345,   346,
-     350,   351,   360,   361,   362,   366,   377,   381,   385,   393,
-     403,   404,   414,   415,   421,   433,   433,   438,   438,   443,
-     453,   467,   468,   469,   470,   474,   475,   480,   482,   487,
-     492,   502,   504,   509,   510,   514,   515,   519,   520,   521,
-     526,   531,   536,   542,   548,   559,   560,   569,   570,   576,
-     577,   578,   585,   585,   593,   594,   595,   600,   603,   605,
-     607,   609,   611,   613,   615,   620,   621,   630,   654,   655,
-     656,   657,   669,   671,   680,   685,   686,   691,   699,   700
+       0,   256,   256,   265,   266,   270,   271,   277,   281,   286,
+     287,   292,   293,   294,   295,   300,   305,   306,   307,   308,
+     309,   310,   310,   311,   312,   336,   337,   338,   339,   343,
+     344,   353,   354,   355,   359,   370,   374,   378,   386,   396,
+     397,   407,   408,   414,   426,   426,   431,   431,   436,   446,
+     460,   461,   462,   463,   467,   468,   473,   475,   480,   485,
+     495,   497,   502,   503,   507,   508,   512,   513,   514,   519,
+     524,   529,   535,   541,   552,   553,   562,   563,   569,   570,
+     571,   578,   578,   586,   587,   588,   593,   596,   598,   600,
+     602,   604,   606,   608,   613,   614,   623,   647,   648,   649,
+     650,   662,   664,   673,   678,   679,   684,   692,   693
 };
 #endif
 
@@ -671,24 +670,24 @@ static const char *const yytname[] =
   "\"%nterm\"", "\"%type\"", "\"%destructor\"", "\"%printer\"",
   "\"%left\"", "\"%right\"", "\"%nonassoc\"", "\"%precedence\"",
   "\"%prec\"", "\"%dprec\"", "\"%merge\"", "\"%code\"",
-  "\"%default-prec\"", "\"%define\"", "\"%defines\"", "\"%error-verbose\"",
-  "\"%expect\"", "\"%expect-rr\"", "\"%<flag>\"", "\"%file-prefix\"",
-  "\"%glr-parser\"", "\"%initial-action\"", "\"%language\"",
-  "\"%name-prefix\"", "\"%no-default-prec\"", "\"%no-lines\"",
-  "\"%nondeterministic-parser\"", "\"%output\"", "\"%require\"",
-  "\"%skeleton\"", "\"%start\"", "\"%token-table\"", "\"%verbose\"",
-  "\"%yacc\"", "\"{...}\"", "\"%?{...}\"", "\"[identifier]\"", "\"char\"",
-  "\"epilogue\"", "\"=\"", "\"identifier\"", "\"identifier:\"", "\"%%\"",
-  "\"|\"", "\"%{...%}\"", "\";\"", "\"<tag>\"", "\"<*>\"", "\"<>\"",
-  "\"integer\"", "\"%param\"", "\"%union\"", "\"%empty\"", "$accept",
-  "input", "prologue_declarations", "prologue_declaration", "$@1",
-  "params", "grammar_declaration", "code_props_type", "union_name",
-  "symbol_declaration", "$@2", "$@3", "precedence_declaration",
-  "precedence_declarator", "tag.opt", "symbols.prec", "symbol.prec",
-  "symbols.1", "generic_symlist", "generic_symlist_item", "tag",
-  "symbol_def", "symbol_defs.1", "grammar", "rules_or_grammar_declaration",
-  "rules", "$@4", "rhses.1", "rhs", "named_ref.opt", "variable", "value",
-  "id", "id_colon", "symbol", "string_as_id", "epilogue.opt", YY_NULLPTR
+  "\"%default-prec\"", "\"%define\"", "\"%defines\"", "\"%expect\"",
+  "\"%expect-rr\"", "\"%<flag>\"", "\"%file-prefix\"", "\"%glr-parser\"",
+  "\"%initial-action\"", "\"%language\"", "\"%name-prefix\"",
+  "\"%no-default-prec\"", "\"%no-lines\"", "\"%nondeterministic-parser\"",
+  "\"%output\"", "\"%require\"", "\"%skeleton\"", "\"%start\"",
+  "\"%token-table\"", "\"%verbose\"", "\"%yacc\"", "\"{...}\"",
+  "\"%?{...}\"", "\"[identifier]\"", "\"char\"", "\"epilogue\"", "\"=\"",
+  "\"identifier\"", "\"identifier:\"", "\"%%\"", "\"|\"", "\"%{...%}\"",
+  "\";\"", "\"<tag>\"", "\"<*>\"", "\"<>\"", "\"integer\"", "\"%param\"",
+  "\"%union\"", "\"%empty\"", "$accept", "input", "prologue_declarations",
+  "prologue_declaration", "$@1", "params", "grammar_declaration",
+  "code_props_type", "union_name", "symbol_declaration", "$@2", "$@3",
+  "precedence_declaration", "precedence_declarator", "tag.opt",
+  "symbols.prec", "symbol.prec", "symbols.1", "generic_symlist",
+  "generic_symlist_item", "tag", "symbol_def", "symbol_defs.1", "grammar",
+  "rules_or_grammar_declaration", "rules", "$@4", "rhses.1", "rhs",
+  "named_ref.opt", "variable", "value", "id", "id_colon", "symbol",
+  "string_as_id", "epilogue.opt", YY_NULLPTR
 };
 #endif
 
@@ -702,16 +701,16 @@ static const yytype_uint16 yytoknum[] =
      275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
      285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
      295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
-     305,   306,   307,   308,   309,   310,   311,   312
+     305,   306,   307,   308,   309,   310,   311
 };
 # endif
 
-#define YYPACT_NINF -116
+#define YYPACT_NINF -114
 
 #define yypact_value_is_default(Yystate) \
-  (!!((Yystate) == (-116)))
+  (!!((Yystate) == (-114)))
 
-#define YYTABLE_NINF -109
+#define YYTABLE_NINF -108
 
 #define yytable_value_is_error(Yytable_value) \
   0
@@ -720,21 +719,21 @@ static const yytype_uint16 yytoknum[] =
      STATE-NUM.  */
 static const yytype_int8 yypact[] =
 {
-    -116,     5,   102,  -116,  -116,  -116,   -50,  -116,  -116,  -116,
-    -116,  -116,  -116,   -23,  -116,   -25,    29,  -116,    -1,    15,
-    -116,    73,  -116,    40,    79,    80,  -116,  -116,  -116,    82,
-      83,    84,    12,  -116,  -116,  -116,    35,  -116,  -116,  -116,
-      43,  -116,  -116,    50,  -116,  -116,    39,    33,    33,    12,
-    -116,    53,  -116,    22,  -116,  -116,  -116,  -116,  -116,  -116,
-    -116,  -116,  -116,  -116,  -116,  -116,  -116,  -116,  -116,  -116,
-      44,  -116,    46,     2,  -116,  -116,    52,    58,  -116,    60,
-      21,  -116,    12,  -116,  -116,    33,     1,    33,    12,  -116,
-    -116,  -116,  -116,  -116,  -116,  -116,  -116,    57,  -116,  -116,
-    -116,  -116,  -116,    62,  -116,  -116,  -116,  -116,    21,  -116,
-    -116,  -116,    12,  -116,    48,  -116,   112,  -116,  -116,  -116,
-    -116,  -116,  -116,  -116,  -116,  -116,   -21,    20,  -116,  -116,
-      12,    63,    65,  -116,  -116,   103,    52,    20,  -116,  -116,
-    -116,    52,  -116,  -116
+    -114,     5,   125,  -114,  -114,  -114,   -25,  -114,  -114,  -114,
+    -114,  -114,  -114,   -23,  -114,    -7,    25,   -15,   -14,  -114,
+      37,  -114,     3,    41,    46,  -114,  -114,  -114,    49,    50,
+      51,     1,  -114,  -114,  -114,    54,  -114,  -114,  -114,    24,
+    -114,  -114,    31,  -114,  -114,    26,   -21,   -21,     1,  -114,
+      39,  -114,    29,  -114,  -114,  -114,  -114,  -114,  -114,  -114,
+    -114,  -114,  -114,  -114,  -114,  -114,  -114,  -114,  -114,    30,
+    -114,    34,     2,  -114,  -114,    38,    55,  -114,    56,    40,
+    -114,     1,  -114,  -114,   -21,    -2,   -21,     1,  -114,  -114,
+    -114,  -114,  -114,  -114,  -114,  -114,    47,  -114,  -114,  -114,
+    -114,  -114,    58,  -114,  -114,  -114,  -114,    40,  -114,  -114,
+    -114,     1,  -114,    44,  -114,    97,  -114,  -114,  -114,  -114,
+    -114,  -114,  -114,  -114,  -114,   -16,    72,  -114,  -114,     1,
+      48,    52,  -114,  -114,    65,    38,    72,  -114,  -114,  -114,
+      38,  -114,  -114
 };
 
   /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
@@ -742,39 +741,39 @@ static const yytype_int8 yypact[] =
      means the default is an error.  */
 static const yytype_uint8 yydefact[] =
 {
-       3,     0,     0,     1,    47,    45,     0,    40,    41,    51,
-      52,    53,    54,     0,    36,     0,     9,    11,     0,     0,
-       7,     0,    15,     0,     0,     0,    37,    19,    20,     0,
-       0,     0,     0,    26,    27,    28,     0,     6,    29,    22,
-      42,     4,     5,     0,    33,    32,    55,     0,     0,     0,
-      38,     0,    97,    98,    10,    12,    13,    14,    16,    17,
-      18,    21,    24,    25,   107,   103,   102,   105,    34,   106,
-       0,   104,     0,     0,    77,    79,    95,     0,    43,     0,
-       0,    56,     0,    70,    75,    48,    71,    46,    49,    61,
-      39,   100,   101,    99,     8,    81,    80,     0,    78,     2,
-      96,    82,    31,    23,    44,    67,    68,    69,    35,    63,
-      66,    65,    50,    57,    59,    76,    72,    73,    62,   109,
-      87,    30,    64,    58,    60,    74,    83,    84,    87,    86,
-       0,     0,     0,    90,    91,     0,    95,    85,    92,    93,
-      94,    95,    88,    89
+       3,     0,     0,     1,    46,    44,     0,    39,    40,    50,
+      51,    52,    53,     0,    35,     0,     9,     0,     0,     7,
+       0,    14,     0,     0,     0,    36,    18,    19,     0,     0,
+       0,     0,    25,    26,    27,     0,     6,    28,    21,    41,
+       4,     5,     0,    32,    31,    54,     0,     0,     0,    37,
+       0,    96,    97,    10,    11,    12,    13,    15,    16,    17,
+      20,    23,    24,   106,   102,   101,   104,    33,   105,     0,
+     103,     0,     0,    76,    78,    94,     0,    42,     0,     0,
+      55,     0,    69,    74,    47,    70,    45,    48,    60,    38,
+      99,   100,    98,     8,    80,    79,     0,    77,     2,    95,
+      81,    30,    22,    43,    66,    67,    68,    34,    62,    65,
+      64,    49,    56,    58,    75,    71,    72,    61,   108,    86,
+      29,    63,    57,    59,    73,    82,    83,    86,    85,     0,
+       0,     0,    89,    90,     0,    94,    84,    91,    92,    93,
+      94,    87,    88
 };
 
   /* YYPGOTO[NTERM-NUM].  */
-static const yytype_int16 yypgoto[] =
+static const yytype_int8 yypgoto[] =
 {
-    -116,  -116,  -116,  -116,  -116,  -116,   142,  -116,  -116,  -116,
-    -116,  -116,  -116,  -116,    99,  -116,    34,  -116,  -116,    42,
-    -116,   -57,   100,  -116,    74,  -116,  -116,  -116,    25,  -115,
-    -116,  -116,    56,  -116,   -32,   -48,  -116
+    -114,  -114,  -114,  -114,  -114,  -114,   102,  -114,  -114,  -114,
+    -114,  -114,  -114,  -114,    61,  -114,    -4,  -114,  -114,     7,
+    -114,   -60,    68,  -114,    36,  -114,  -114,  -114,   -10,  -113,
+    -114,  -114,   -12,  -114,   -31,   -69,  -114
 };
 
   /* YYDEFGOTO[NTERM-NUM].  */
 static const yytype_int16 yydefgoto[] =
 {
-      -1,     1,     2,    41,    77,   103,    72,    43,    79,    44,
-      48,    47,    45,    46,   135,   112,   113,    88,   108,   109,
-     110,    84,    85,    73,    74,    75,   120,   126,   127,   101,
-      53,    94,    67,    76,   111,    69,    99
+      -1,     1,     2,    40,    76,   102,    71,    42,    78,    43,
+      47,    46,    44,    45,   134,   111,   112,    87,   107,   108,
+     109,    83,    84,    72,    73,    74,   119,   125,   126,   100,
+      52,    93,    66,    75,   110,    68,    98
 };
 
   /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
@@ -782,95 +781,101 @@ static const yytype_int16 yydefgoto[] =
      number is the opposite.  If YYTABLE_NINF, syntax error.  */
 static const yytype_int16 yytable[] =
 {
-      68,    49,  -108,    70,    64,     3,     4,     5,     6,     7,
-       8,     9,    10,    11,    12,    64,    50,    89,    13,    14,
-      52,   142,    51,    64,    64,    91,   143,   128,   115,   129,
-     115,    26,    54,   130,   131,   132,    70,    32,   117,     4,
-       5,     6,     7,     8,     9,    10,    11,    12,    71,    97,
-     114,    13,    14,    55,    65,   116,   118,    66,    40,   -55,
-     133,    92,    65,    65,    26,    66,    66,    93,   125,    56,
-      32,    81,   105,   106,   107,    65,    57,   134,    66,    58,
-     114,    71,    59,    60,    83,    61,    62,    63,    78,    80,
-      81,    40,    90,   100,    95,   136,    96,   102,   138,   104,
-     119,   121,   124,    86,    86,   136,     4,     5,     6,     7,
-       8,     9,    10,    11,    12,    64,   140,   139,    13,    14,
-      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
-      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
-      35,    86,   141,    86,    42,    82,   123,    98,    87,    36,
-     122,    37,    38,   137,     0,     0,     0,    39,    40
+      67,    63,  -107,    69,    63,     3,     4,     5,     6,     7,
+       8,     9,    10,    11,    12,    49,   116,    88,    13,    14,
+      64,    50,   141,    65,   114,    48,   114,   142,    53,    82,
+      25,   127,    90,   128,    85,    85,    31,    51,    54,    55,
+      56,    57,    64,    63,    58,    65,   124,    70,    96,    59,
+     113,   115,    60,    61,    62,    69,   117,    39,     4,     5,
+       6,     7,     8,     9,    10,    11,    12,    91,    77,    79,
+      13,    14,    85,    92,    85,    63,    80,    89,    99,    94,
+     113,    64,    25,    95,    65,   129,   130,   131,    31,   118,
+     104,   105,   106,   101,   103,   135,   120,   123,   137,    70,
+      63,   138,   139,   140,    41,   135,    81,   122,    97,    39,
+     -54,   132,     0,    64,   121,    86,    65,   136,     0,     0,
+       0,     0,    80,     0,     0,     0,     0,     0,   133,     4,
+       5,     6,     7,     8,     9,    10,    11,    12,     0,     0,
+       0,    13,    14,    15,    16,    17,    18,    19,    20,    21,
+      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
+      32,    33,    34,     0,     0,     0,     0,     0,     0,     0,
+       0,    35,     0,    36,    37,     0,     0,     0,     0,    38,
+      39
 };
 
 static const yytype_int16 yycheck[] =
 {
-      32,    51,     0,     1,     3,     0,     4,     5,     6,     7,
-       8,     9,    10,    11,    12,     3,    39,    49,    16,    17,
-      45,   136,    45,     3,     3,     3,   141,    48,    85,    50,
-      87,    29,     3,    13,    14,    15,     1,    35,    86,     4,
-       5,     6,     7,     8,     9,    10,    11,    12,    46,    47,
-      82,    16,    17,    54,    42,    54,    88,    45,    56,    39,
-      40,    39,    42,    42,    29,    45,    45,    45,   116,    54,
-      35,    51,    51,    52,    53,    42,     3,    57,    45,    39,
-     112,    46,     3,     3,    51,     3,     3,     3,    45,    39,
-      51,    56,    39,    41,    50,   127,    50,    39,   130,    39,
-      43,    39,    54,    47,    48,   137,     4,     5,     6,     7,
-       8,     9,    10,    11,    12,     3,    51,    54,    16,    17,
-      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
-      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
-      38,    85,    39,    87,     2,    46,   112,    73,    48,    47,
-     108,    49,    50,   128,    -1,    -1,    -1,    55,    56
+      31,     3,     0,     1,     3,     0,     4,     5,     6,     7,
+       8,     9,    10,    11,    12,    38,    85,    48,    16,    17,
+      41,    44,   135,    44,    84,    50,    86,   140,     3,    50,
+      28,    47,     3,    49,    46,    47,    34,    44,    53,    53,
+       3,    38,    41,     3,     3,    44,   115,    45,    46,     3,
+      81,    53,     3,     3,     3,     1,    87,    55,     4,     5,
+       6,     7,     8,     9,    10,    11,    12,    38,    44,    38,
+      16,    17,    84,    44,    86,     3,    50,    38,    40,    49,
+     111,    41,    28,    49,    44,    13,    14,    15,    34,    42,
+      50,    51,    52,    38,    38,   126,    38,    53,   129,    45,
+       3,    53,    50,    38,     2,   136,    45,   111,    72,    55,
+      38,    39,    -1,    41,   107,    47,    44,   127,    -1,    -1,
+      -1,    -1,    50,    -1,    -1,    -1,    -1,    -1,    56,     4,
+       5,     6,     7,     8,     9,    10,    11,    12,    -1,    -1,
+      -1,    16,    17,    18,    19,    20,    21,    22,    23,    24,
+      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
+      35,    36,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
+      -1,    46,    -1,    48,    49,    -1,    -1,    -1,    -1,    54,
+      55
 };
 
   /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
      symbol of state STATE-NUM.  */
 static const yytype_uint8 yystos[] =
 {
-       0,    59,    60,     0,     4,     5,     6,     7,     8,     9,
+       0,    58,    59,     0,     4,     5,     6,     7,     8,     9,
       10,    11,    12,    16,    17,    18,    19,    20,    21,    22,
       23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
-      33,    34,    35,    36,    37,    38,    47,    49,    50,    55,
-      56,    61,    64,    65,    67,    70,    71,    69,    68,    51,
-      39,    45,    45,    88,     3,    54,    54,     3,    39,     3,
-       3,     3,     3,     3,     3,    42,    45,    90,    92,    93,
-       1,    46,    64,    81,    82,    83,    91,    62,    45,    66,
-      39,    51,    72,    51,    79,    80,    90,    80,    75,    92,
-      39,     3,    39,    45,    89,    50,    50,    47,    82,    94,
-      41,    87,    39,    63,    39,    51,    52,    53,    76,    77,
-      78,    92,    73,    74,    92,    79,    54,    93,    92,    43,
-      84,    39,    77,    74,    54,    93,    85,    86,    48,    50,
-      13,    14,    15,    40,    57,    72,    92,    86,    92,    54,
-      51,    39,    87,    87
+      33,    34,    35,    36,    37,    46,    48,    49,    54,    55,
+      60,    63,    64,    66,    69,    70,    68,    67,    50,    38,
+      44,    44,    87,     3,    53,    53,     3,    38,     3,     3,
+       3,     3,     3,     3,    41,    44,    89,    91,    92,     1,
+      45,    63,    80,    81,    82,    90,    61,    44,    65,    38,
+      50,    71,    50,    78,    79,    89,    79,    74,    91,    38,
+       3,    38,    44,    88,    49,    49,    46,    81,    93,    40,
+      86,    38,    62,    38,    50,    51,    52,    75,    76,    77,
+      91,    72,    73,    91,    78,    53,    92,    91,    42,    83,
+      38,    76,    73,    53,    92,    84,    85,    47,    49,    13,
+      14,    15,    39,    56,    71,    91,    85,    91,    53,    50,
+      38,    86,    86
 };
 
   /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
 static const yytype_uint8 yyr1[] =
 {
-       0,    58,    59,    60,    60,    61,    61,    61,    61,    61,
-      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
-      61,    61,    62,    61,    61,    61,    61,    61,    61,    61,
-      63,    63,    64,    64,    64,    64,    64,    64,    64,    64,
-      65,    65,    66,    66,    64,    68,    67,    69,    67,    67,
-      70,    71,    71,    71,    71,    72,    72,    73,    73,    74,
-      74,    75,    75,    76,    76,    77,    77,    78,    78,    78,
-      79,    79,    79,    79,    79,    80,    80,    81,    81,    82,
-      82,    82,    84,    83,    85,    85,    85,    86,    86,    86,
-      86,    86,    86,    86,    86,    87,    87,    88,    89,    89,
-      89,    89,    90,    90,    91,    92,    92,    93,    94,    94
+       0,    57,    58,    59,    59,    60,    60,    60,    60,    60,
+      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
+      60,    61,    60,    60,    60,    60,    60,    60,    60,    62,
+      62,    63,    63,    63,    63,    63,    63,    63,    63,    64,
+      64,    65,    65,    63,    67,    66,    68,    66,    66,    69,
+      70,    70,    70,    70,    71,    71,    72,    72,    73,    73,
+      74,    74,    75,    75,    76,    76,    77,    77,    77,    78,
+      78,    78,    78,    78,    79,    79,    80,    80,    81,    81,
+      81,    83,    82,    84,    84,    84,    85,    85,    85,    85,
+      85,    85,    85,    85,    86,    86,    87,    88,    88,    88,
+      88,    89,    89,    90,    91,    91,    92,    93,    93
 };
 
   /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
 static const yytype_uint8 yyr2[] =
 {
        0,     2,     4,     0,     2,     1,     1,     1,     3,     1,
-       2,     1,     2,     2,     2,     1,     2,     2,     2,     1,
-       1,     2,     0,     3,     2,     2,     1,     1,     1,     1,
-       2,     1,     1,     1,     2,     3,     1,     1,     2,     3,
-       1,     1,     0,     1,     3,     0,     3,     0,     3,     3,
-       3,     1,     1,     1,     1,     0,     1,     1,     2,     1,
-       2,     1,     2,     1,     2,     1,     1,     1,     1,     1,
-       1,     1,     2,     2,     3,     1,     2,     1,     2,     1,
-       2,     2,     0,     4,     1,     3,     2,     0,     3,     4,
-       2,     2,     3,     3,     3,     0,     1,     1,     0,     1,
-       1,     1,     1,     1,     1,     1,     1,     1,     0,     2
+       2,     2,     2,     2,     1,     2,     2,     2,     1,     1,
+       2,     0,     3,     2,     2,     1,     1,     1,     1,     2,
+       1,     1,     1,     2,     3,     1,     1,     2,     3,     1,
+       1,     0,     1,     3,     0,     3,     0,     3,     3,     3,
+       1,     1,     1,     1,     0,     1,     1,     2,     1,     2,
+       1,     2,     1,     2,     1,     1,     1,     1,     1,     1,
+       1,     2,     2,     3,     1,     2,     1,     2,     1,     2,
+       2,     0,     4,     1,     3,     2,     0,     3,     4,     2,
+       2,     3,     3,     3,     0,     1,     1,     0,     1,     1,
+       1,     1,     1,     1,     1,     1,     1,     0,     2
 };
 
 
@@ -1026,79 +1031,79 @@ yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YY
   switch (yytype)
     {
           case 3: /* "string"  */
-#line 188 "src/parse-gram.y" /* yacc.c:681  */
+#line 187 "src/parse-gram.y" /* yacc.c:681  */
       { fputs (quotearg_style (c_quoting_style, (*(char**)(&(*yyvaluep)))), yyo); }
-#line 1032 "src/parse-gram.c" /* yacc.c:681  */
+#line 1037 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
-    case 23: /* "%<flag>"  */
-#line 195 "src/parse-gram.y" /* yacc.c:681  */
+    case 22: /* "%<flag>"  */
+#line 194 "src/parse-gram.y" /* yacc.c:681  */
       { fprintf (yyo, "%%%s", (*(uniqstr*)(&(*yyvaluep)))); }
-#line 1038 "src/parse-gram.c" /* yacc.c:681  */
+#line 1043 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
-    case 39: /* "{...}"  */
-#line 189 "src/parse-gram.y" /* yacc.c:681  */
+    case 38: /* "{...}"  */
+#line 188 "src/parse-gram.y" /* yacc.c:681  */
       { fprintf (yyo, "{\n%s\n}", (*(char**)(&(*yyvaluep)))); }
-#line 1044 "src/parse-gram.c" /* yacc.c:681  */
+#line 1049 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
-    case 40: /* "%?{...}"  */
-#line 189 "src/parse-gram.y" /* yacc.c:681  */
+    case 39: /* "%?{...}"  */
+#line 188 "src/parse-gram.y" /* yacc.c:681  */
       { fprintf (yyo, "{\n%s\n}", (*(char**)(&(*yyvaluep)))); }
-#line 1050 "src/parse-gram.c" /* yacc.c:681  */
+#line 1055 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
-    case 41: /* "[identifier]"  */
-#line 193 "src/parse-gram.y" /* yacc.c:681  */
+    case 40: /* "[identifier]"  */
+#line 192 "src/parse-gram.y" /* yacc.c:681  */
       { fprintf (yyo, "[%s]", (*(uniqstr*)(&(*yyvaluep)))); }
-#line 1056 "src/parse-gram.c" /* yacc.c:681  */
+#line 1061 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
-    case 42: /* "char"  */
-#line 185 "src/parse-gram.y" /* yacc.c:681  */
+    case 41: /* "char"  */
+#line 184 "src/parse-gram.y" /* yacc.c:681  */
       { fputs (char_name ((*(unsigned char*)(&(*yyvaluep)))), yyo); }
-#line 1062 "src/parse-gram.c" /* yacc.c:681  */
+#line 1067 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
-    case 43: /* "epilogue"  */
-#line 189 "src/parse-gram.y" /* yacc.c:681  */
+    case 42: /* "epilogue"  */
+#line 188 "src/parse-gram.y" /* yacc.c:681  */
       { fprintf (yyo, "{\n%s\n}", (*(char**)(&(*yyvaluep)))); }
-#line 1068 "src/parse-gram.c" /* yacc.c:681  */
+#line 1073 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
-    case 45: /* "identifier"  */
-#line 192 "src/parse-gram.y" /* yacc.c:681  */
+    case 44: /* "identifier"  */
+#line 191 "src/parse-gram.y" /* yacc.c:681  */
       { fputs ((*(uniqstr*)(&(*yyvaluep))), yyo); }
-#line 1074 "src/parse-gram.c" /* yacc.c:681  */
+#line 1079 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
-    case 46: /* "identifier:"  */
-#line 194 "src/parse-gram.y" /* yacc.c:681  */
+    case 45: /* "identifier:"  */
+#line 193 "src/parse-gram.y" /* yacc.c:681  */
       { fprintf (yyo, "%s:", (*(uniqstr*)(&(*yyvaluep)))); }
-#line 1080 "src/parse-gram.c" /* yacc.c:681  */
+#line 1085 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
-    case 49: /* "%{...%}"  */
-#line 189 "src/parse-gram.y" /* yacc.c:681  */
+    case 48: /* "%{...%}"  */
+#line 188 "src/parse-gram.y" /* yacc.c:681  */
       { fprintf (yyo, "{\n%s\n}", (*(char**)(&(*yyvaluep)))); }
-#line 1086 "src/parse-gram.c" /* yacc.c:681  */
+#line 1091 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
-    case 51: /* "<tag>"  */
-#line 196 "src/parse-gram.y" /* yacc.c:681  */
+    case 50: /* "<tag>"  */
+#line 195 "src/parse-gram.y" /* yacc.c:681  */
       { fprintf (yyo, "<%s>", (*(uniqstr*)(&(*yyvaluep)))); }
-#line 1092 "src/parse-gram.c" /* yacc.c:681  */
+#line 1097 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
-    case 54: /* "integer"  */
-#line 199 "src/parse-gram.y" /* yacc.c:681  */
+    case 53: /* "integer"  */
+#line 198 "src/parse-gram.y" /* yacc.c:681  */
       { fprintf (yyo, "%d", (*(int*)(&(*yyvaluep)))); }
-#line 1098 "src/parse-gram.c" /* yacc.c:681  */
+#line 1103 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
-    case 55: /* "%param"  */
-#line 237 "src/parse-gram.y" /* yacc.c:681  */
+    case 54: /* "%param"  */
+#line 236 "src/parse-gram.y" /* yacc.c:681  */
       {
   switch ((*(param_type*)(&(*yyvaluep))))
     {
@@ -1111,35 +1116,35 @@ yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YY
       case param_none: aver (false); break;
     }
 }
-#line 1115 "src/parse-gram.c" /* yacc.c:681  */
+#line 1120 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
-    case 65: /* code_props_type  */
-#line 401 "src/parse-gram.y" /* yacc.c:681  */
+    case 64: /* code_props_type  */
+#line 394 "src/parse-gram.y" /* yacc.c:681  */
       { fprintf (yyo, "%s", code_props_type_string ((*(code_props_type*)(&(*yyvaluep))))); }
-#line 1121 "src/parse-gram.c" /* yacc.c:681  */
+#line 1126 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
-    case 74: /* symbol.prec  */
-#line 202 "src/parse-gram.y" /* yacc.c:681  */
+    case 73: /* symbol.prec  */
+#line 201 "src/parse-gram.y" /* yacc.c:681  */
       { fprintf (yyo, "%s", (*(symbol**)(&(*yyvaluep)))->tag); }
-#line 1127 "src/parse-gram.c" /* yacc.c:681  */
+#line 1132 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
-    case 78: /* tag  */
-#line 196 "src/parse-gram.y" /* yacc.c:681  */
+    case 77: /* tag  */
+#line 195 "src/parse-gram.y" /* yacc.c:681  */
       { fprintf (yyo, "<%s>", (*(uniqstr*)(&(*yyvaluep)))); }
-#line 1133 "src/parse-gram.c" /* yacc.c:681  */
+#line 1138 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
-    case 88: /* variable  */
-#line 192 "src/parse-gram.y" /* yacc.c:681  */
+    case 87: /* variable  */
+#line 191 "src/parse-gram.y" /* yacc.c:681  */
       { fputs ((*(uniqstr*)(&(*yyvaluep))), yyo); }
-#line 1139 "src/parse-gram.c" /* yacc.c:681  */
+#line 1144 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
-    case 89: /* value  */
-#line 644 "src/parse-gram.y" /* yacc.c:681  */
+    case 88: /* value  */
+#line 637 "src/parse-gram.y" /* yacc.c:681  */
       {
   switch ((*(value_type*)(&(*yyvaluep))).kind)
     {
@@ -1148,31 +1153,31 @@ yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YY
     case muscle_string:  fprintf (yyo, "\"%s\"", (*(value_type*)(&(*yyvaluep))).chars); break;
     }
 }
-#line 1152 "src/parse-gram.c" /* yacc.c:681  */
+#line 1157 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
-    case 90: /* id  */
-#line 202 "src/parse-gram.y" /* yacc.c:681  */
+    case 89: /* id  */
+#line 201 "src/parse-gram.y" /* yacc.c:681  */
       { fprintf (yyo, "%s", (*(symbol**)(&(*yyvaluep)))->tag); }
-#line 1158 "src/parse-gram.c" /* yacc.c:681  */
+#line 1163 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
-    case 91: /* id_colon  */
-#line 203 "src/parse-gram.y" /* yacc.c:681  */
+    case 90: /* id_colon  */
+#line 202 "src/parse-gram.y" /* yacc.c:681  */
       { fprintf (yyo, "%s:", (*(symbol**)(&(*yyvaluep)))->tag); }
-#line 1164 "src/parse-gram.c" /* yacc.c:681  */
+#line 1169 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
-    case 92: /* symbol  */
-#line 202 "src/parse-gram.y" /* yacc.c:681  */
+    case 91: /* symbol  */
+#line 201 "src/parse-gram.y" /* yacc.c:681  */
       { fprintf (yyo, "%s", (*(symbol**)(&(*yyvaluep)))->tag); }
-#line 1170 "src/parse-gram.c" /* yacc.c:681  */
+#line 1175 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
-    case 93: /* string_as_id  */
-#line 202 "src/parse-gram.y" /* yacc.c:681  */
+    case 92: /* string_as_id  */
+#line 201 "src/parse-gram.y" /* yacc.c:681  */
       { fprintf (yyo, "%s", (*(symbol**)(&(*yyvaluep)))->tag); }
-#line 1176 "src/parse-gram.c" /* yacc.c:681  */
+#line 1181 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
 
@@ -1866,7 +1871,7 @@ YYLTYPE yylloc = yyloc_default;
   yychar = YYEMPTY; /* Cause a token to be read.  */
 
 /* User initialization code.  */
-#line 110 "src/parse-gram.y" /* yacc.c:1429  */
+#line 110 "src/parse-gram.y" /* yacc.c:1428  */
 {
   /* Bison's grammar can initial empty locations, hence a default
      location is needed. */
@@ -1874,7 +1879,7 @@ YYLTYPE yylloc = yyloc_default;
   boundary_set (&yylloc.end, current_file, 1, 1);
 }
 
-#line 1878 "src/parse-gram.c" /* yacc.c:1429  */
+#line 1883 "src/parse-gram.c" /* yacc.c:1428  */
   yylsp[0] = yylloc;
   goto yysetstate;
 
@@ -2068,143 +2073,133 @@ yyreduce:
     switch (yyn)
       {
   case 6:
-#line 273 "src/parse-gram.y" /* yacc.c:1645  */
+#line 272 "src/parse-gram.y" /* yacc.c:1644  */
     {
       muscle_code_grow (union_seen ? "post_prologue" : "pre_prologue",
                         translate_code ((*(char**)(&yyvsp[0])), (yylsp[0]), true), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2078 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2083 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
   case 7:
-#line 279 "src/parse-gram.y" /* yacc.c:1645  */
+#line 278 "src/parse-gram.y" /* yacc.c:1644  */
     {
       muscle_percent_define_ensure ((*(uniqstr*)(&yyvsp[0])), (yylsp[0]), true);
     }
-#line 2086 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2091 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
   case 8:
-#line 283 "src/parse-gram.y" /* yacc.c:1645  */
+#line 282 "src/parse-gram.y" /* yacc.c:1644  */
     {
       muscle_percent_define_insert ((*(uniqstr*)(&yyvsp[-1])), (yylsp[-1]), (*(value_type*)(&yyvsp[0])).kind, (*(value_type*)(&yyvsp[0])).chars,
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
     }
-#line 2095 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2100 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
   case 9:
-#line 287 "src/parse-gram.y" /* yacc.c:1645  */
+#line 286 "src/parse-gram.y" /* yacc.c:1644  */
     { defines_flag = true; }
-#line 2101 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2106 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
   case 10:
-#line 289 "src/parse-gram.y" /* yacc.c:1645  */
+#line 288 "src/parse-gram.y" /* yacc.c:1644  */
     {
       defines_flag = true;
       spec_defines_file = xstrdup ((*(char**)(&yyvsp[0])));
     }
-#line 2110 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2115 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
   case 11:
-#line 294 "src/parse-gram.y" /* yacc.c:1645  */
-    {
-      muscle_percent_define_insert ("parse.error", (yylsp[0]), muscle_keyword,
-                                    "verbose",
-                                    MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
-    }
-#line 2120 "src/parse-gram.c" /* yacc.c:1645  */
-    break;
-
-  case 12:
-#line 299 "src/parse-gram.y" /* yacc.c:1645  */
+#line 292 "src/parse-gram.y" /* yacc.c:1644  */
     { expected_sr_conflicts = (*(int*)(&yyvsp[0])); }
-#line 2126 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2121 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
-  case 13:
-#line 300 "src/parse-gram.y" /* yacc.c:1645  */
+  case 12:
+#line 293 "src/parse-gram.y" /* yacc.c:1644  */
     { expected_rr_conflicts = (*(int*)(&yyvsp[0])); }
-#line 2132 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2127 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
-  case 14:
-#line 301 "src/parse-gram.y" /* yacc.c:1645  */
+  case 13:
+#line 294 "src/parse-gram.y" /* yacc.c:1644  */
     { spec_file_prefix = (*(char**)(&yyvsp[0])); }
-#line 2138 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2133 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
-  case 15:
-#line 303 "src/parse-gram.y" /* yacc.c:1645  */
+  case 14:
+#line 296 "src/parse-gram.y" /* yacc.c:1644  */
     {
       nondeterministic_parser = true;
       glr_parser = true;
     }
-#line 2147 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2142 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
-  case 16:
-#line 308 "src/parse-gram.y" /* yacc.c:1645  */
+  case 15:
+#line 301 "src/parse-gram.y" /* yacc.c:1644  */
     {
       muscle_code_grow ("initial_action", translate_code ((*(char**)(&yyvsp[0])), (yylsp[0]), false), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2156 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2151 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
-  case 17:
-#line 312 "src/parse-gram.y" /* yacc.c:1645  */
+  case 16:
+#line 305 "src/parse-gram.y" /* yacc.c:1644  */
     { language_argmatch ((*(char**)(&yyvsp[0])), grammar_prio, (yylsp[-1])); }
-#line 2162 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2157 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
-  case 18:
-#line 313 "src/parse-gram.y" /* yacc.c:1645  */
+  case 17:
+#line 306 "src/parse-gram.y" /* yacc.c:1644  */
     { spec_name_prefix = (*(char**)(&yyvsp[0])); }
-#line 2168 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2163 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
-  case 19:
-#line 314 "src/parse-gram.y" /* yacc.c:1645  */
+  case 18:
+#line 307 "src/parse-gram.y" /* yacc.c:1644  */
     { no_lines_flag = true; }
-#line 2174 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2169 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
-  case 20:
-#line 315 "src/parse-gram.y" /* yacc.c:1645  */
+  case 19:
+#line 308 "src/parse-gram.y" /* yacc.c:1644  */
     { nondeterministic_parser = true; }
-#line 2180 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2175 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
-  case 21:
-#line 316 "src/parse-gram.y" /* yacc.c:1645  */
+  case 20:
+#line 309 "src/parse-gram.y" /* yacc.c:1644  */
     { spec_outfile = (*(char**)(&yyvsp[0])); }
-#line 2186 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2181 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
-  case 22:
-#line 317 "src/parse-gram.y" /* yacc.c:1645  */
+  case 21:
+#line 310 "src/parse-gram.y" /* yacc.c:1644  */
     { current_param = (*(param_type*)(&yyvsp[0])); }
-#line 2192 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2187 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
-  case 23:
-#line 317 "src/parse-gram.y" /* yacc.c:1645  */
+  case 22:
+#line 310 "src/parse-gram.y" /* yacc.c:1644  */
     { current_param = param_none; }
-#line 2198 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2193 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
-  case 24:
-#line 318 "src/parse-gram.y" /* yacc.c:1645  */
+  case 23:
+#line 311 "src/parse-gram.y" /* yacc.c:1644  */
     { version_check (&(yylsp[0]), (*(char**)(&yyvsp[0]))); }
-#line 2204 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2199 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
-  case 25:
-#line 320 "src/parse-gram.y" /* yacc.c:1645  */
+  case 24:
+#line 313 "src/parse-gram.y" /* yacc.c:1644  */
     {
       char const *skeleton_user = (*(char**)(&yyvsp[0]));
       if (strchr (skeleton_user, '/'))
@@ -2228,49 +2223,49 @@ yyreduce:
         }
       skeleton_arg (skeleton_user, grammar_prio, (yylsp[-1]));
     }
-#line 2232 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2227 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
-  case 26:
-#line 343 "src/parse-gram.y" /* yacc.c:1645  */
+  case 25:
+#line 336 "src/parse-gram.y" /* yacc.c:1644  */
     { token_table_flag = true; }
-#line 2238 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2233 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
-  case 27:
-#line 344 "src/parse-gram.y" /* yacc.c:1645  */
+  case 26:
+#line 337 "src/parse-gram.y" /* yacc.c:1644  */
     { report_flag |= report_states; }
-#line 2244 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2239 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
-  case 28:
-#line 345 "src/parse-gram.y" /* yacc.c:1645  */
+  case 27:
+#line 338 "src/parse-gram.y" /* yacc.c:1644  */
     { yacc_flag = true; }
-#line 2250 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2245 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
-  case 30:
-#line 350 "src/parse-gram.y" /* yacc.c:1645  */
+  case 29:
+#line 343 "src/parse-gram.y" /* yacc.c:1644  */
     { add_param (current_param, (*(char**)(&yyvsp[0])), (yylsp[0])); }
-#line 2256 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2251 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
-  case 31:
-#line 351 "src/parse-gram.y" /* yacc.c:1645  */
+  case 30:
+#line 344 "src/parse-gram.y" /* yacc.c:1644  */
     { add_param (current_param, (*(char**)(&yyvsp[0])), (yylsp[0])); }
-#line 2262 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2257 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
-  case 34:
-#line 363 "src/parse-gram.y" /* yacc.c:1645  */
+  case 33:
+#line 356 "src/parse-gram.y" /* yacc.c:1644  */
     {
       grammar_start_symbol_set ((*(symbol**)(&yyvsp[0])), (yylsp[0]));
     }
-#line 2270 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2265 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
-  case 35:
-#line 367 "src/parse-gram.y" /* yacc.c:1645  */
+  case 34:
+#line 360 "src/parse-gram.y" /* yacc.c:1644  */
     {
       code_props code;
       code_props_symbol_action_init (&code, (*(char**)(&yyvsp[-1])), (yylsp[-1]));
@@ -2281,27 +2276,27 @@ yyreduce:
         symbol_list_free ((*(symbol_list**)(&yyvsp[0])));
       }
     }
-#line 2285 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2280 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
-  case 36:
-#line 378 "src/parse-gram.y" /* yacc.c:1645  */
+  case 35:
+#line 371 "src/parse-gram.y" /* yacc.c:1644  */
     {
       default_prec = true;
     }
-#line 2293 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2288 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
-  case 37:
-#line 382 "src/parse-gram.y" /* yacc.c:1645  */
+  case 36:
+#line 375 "src/parse-gram.y" /* yacc.c:1644  */
     {
       default_prec = false;
     }
-#line 2301 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2296 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
-  case 38:
-#line 386 "src/parse-gram.y" /* yacc.c:1645  */
+  case 37:
+#line 379 "src/parse-gram.y" /* yacc.c:1644  */
     {
       /* Do not invoke muscle_percent_code_grow here since it invokes
          muscle_user_name_list_grow.  */
@@ -2309,97 +2304,97 @@ yyreduce:
                         translate_code_braceless ((*(char**)(&yyvsp[0])), (yylsp[0])), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2313 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2308 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
-  case 39:
-#line 394 "src/parse-gram.y" /* yacc.c:1645  */
+  case 38:
+#line 387 "src/parse-gram.y" /* yacc.c:1644  */
     {
       muscle_percent_code_grow ((*(uniqstr*)(&yyvsp[-1])), (yylsp[-1]), translate_code_braceless ((*(char**)(&yyvsp[0])), (yylsp[0])), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2322 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2317 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
-  case 40:
-#line 403 "src/parse-gram.y" /* yacc.c:1645  */
+  case 39:
+#line 396 "src/parse-gram.y" /* yacc.c:1644  */
     { (*(code_props_type*)(&yyval)) = destructor; }
-#line 2328 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2323 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
-  case 41:
-#line 404 "src/parse-gram.y" /* yacc.c:1645  */
+  case 40:
+#line 397 "src/parse-gram.y" /* yacc.c:1644  */
     { (*(code_props_type*)(&yyval)) = printer; }
-#line 2334 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2329 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
-  case 42:
-#line 414 "src/parse-gram.y" /* yacc.c:1645  */
+  case 41:
+#line 407 "src/parse-gram.y" /* yacc.c:1644  */
     {}
-#line 2340 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2335 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
-  case 43:
-#line 415 "src/parse-gram.y" /* yacc.c:1645  */
+  case 42:
+#line 408 "src/parse-gram.y" /* yacc.c:1644  */
     { muscle_percent_define_insert ("api.value.union.name",
                                          (yylsp[0]), muscle_keyword, (*(uniqstr*)(&yyvsp[0])),
                                          MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE); }
-#line 2348 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2343 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
-  case 44:
-#line 422 "src/parse-gram.y" /* yacc.c:1645  */
+  case 43:
+#line 415 "src/parse-gram.y" /* yacc.c:1644  */
     {
       union_seen = true;
       muscle_code_grow ("union_members", translate_code_braceless ((*(char**)(&yyvsp[0])), (yylsp[0])), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2358 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2353 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
-  case 45:
-#line 433 "src/parse-gram.y" /* yacc.c:1645  */
+  case 44:
+#line 426 "src/parse-gram.y" /* yacc.c:1644  */
     { current_class = nterm_sym; }
-#line 2364 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2359 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
-  case 46:
-#line 434 "src/parse-gram.y" /* yacc.c:1645  */
+  case 45:
+#line 427 "src/parse-gram.y" /* yacc.c:1644  */
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
-#line 2373 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2368 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
-  case 47:
-#line 438 "src/parse-gram.y" /* yacc.c:1645  */
+  case 46:
+#line 431 "src/parse-gram.y" /* yacc.c:1644  */
     { current_class = token_sym; }
-#line 2379 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2374 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
-  case 48:
-#line 439 "src/parse-gram.y" /* yacc.c:1645  */
+  case 47:
+#line 432 "src/parse-gram.y" /* yacc.c:1644  */
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
-#line 2388 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2383 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
-  case 49:
-#line 444 "src/parse-gram.y" /* yacc.c:1645  */
+  case 48:
+#line 437 "src/parse-gram.y" /* yacc.c:1644  */
     {
       tag_seen = true;
       for (symbol_list *list = (*(symbol_list**)(&yyvsp[0])); list; list = list->next)
         symbol_type_set (list->content.sym, (*(uniqstr*)(&yyvsp[-1])), (yylsp[-1]));
       symbol_list_free ((*(symbol_list**)(&yyvsp[0])));
     }
-#line 2399 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2394 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
-  case 50:
-#line 454 "src/parse-gram.y" /* yacc.c:1645  */
+  case 49:
+#line 447 "src/parse-gram.y" /* yacc.c:1644  */
     {
       ++current_prec;
       for (symbol_list *list = (*(symbol_list**)(&yyvsp[0])); list; list = list->next)
@@ -2410,335 +2405,335 @@ yyreduce:
       symbol_list_free ((*(symbol_list**)(&yyvsp[0])));
       current_type = NULL;
     }
-#line 2414 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2409 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
-  case 51:
-#line 467 "src/parse-gram.y" /* yacc.c:1645  */
+  case 50:
+#line 460 "src/parse-gram.y" /* yacc.c:1644  */
     { (*(assoc*)(&yyval)) = left_assoc; }
-#line 2420 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2415 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
-  case 52:
-#line 468 "src/parse-gram.y" /* yacc.c:1645  */
+  case 51:
+#line 461 "src/parse-gram.y" /* yacc.c:1644  */
     { (*(assoc*)(&yyval)) = right_assoc; }
-#line 2426 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2421 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
-  case 53:
-#line 469 "src/parse-gram.y" /* yacc.c:1645  */
+  case 52:
+#line 462 "src/parse-gram.y" /* yacc.c:1644  */
     { (*(assoc*)(&yyval)) = non_assoc; }
-#line 2432 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2427 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
-  case 54:
-#line 470 "src/parse-gram.y" /* yacc.c:1645  */
+  case 53:
+#line 463 "src/parse-gram.y" /* yacc.c:1644  */
     { (*(assoc*)(&yyval)) = precedence_assoc; }
-#line 2438 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2433 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
-  case 55:
-#line 474 "src/parse-gram.y" /* yacc.c:1645  */
+  case 54:
+#line 467 "src/parse-gram.y" /* yacc.c:1644  */
     { current_type = NULL; }
-#line 2444 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2439 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
-  case 56:
-#line 475 "src/parse-gram.y" /* yacc.c:1645  */
+  case 55:
+#line 468 "src/parse-gram.y" /* yacc.c:1644  */
     { current_type = (*(uniqstr*)(&yyvsp[0])); tag_seen = true; }
-#line 2450 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2445 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
-  case 57:
-#line 481 "src/parse-gram.y" /* yacc.c:1645  */
+  case 56:
+#line 474 "src/parse-gram.y" /* yacc.c:1644  */
     { (*(symbol_list**)(&yyval)) = symbol_list_sym_new ((*(symbol**)(&yyvsp[0])), (yylsp[0])); }
-#line 2456 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2451 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
-  case 58:
-#line 483 "src/parse-gram.y" /* yacc.c:1645  */
+  case 57:
+#line 476 "src/parse-gram.y" /* yacc.c:1644  */
     { (*(symbol_list**)(&yyval)) = symbol_list_append ((*(symbol_list**)(&yyvsp[-1])), symbol_list_sym_new ((*(symbol**)(&yyvsp[0])), (yylsp[0]))); }
-#line 2462 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2457 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
-  case 59:
-#line 488 "src/parse-gram.y" /* yacc.c:1645  */
+  case 58:
+#line 481 "src/parse-gram.y" /* yacc.c:1644  */
     {
       (*(symbol**)(&yyval)) = (*(symbol**)(&yyvsp[0]));
       symbol_class_set ((*(symbol**)(&yyvsp[0])), token_sym, (yylsp[0]), false);
     }
-#line 2471 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2466 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
-  case 60:
-#line 493 "src/parse-gram.y" /* yacc.c:1645  */
+  case 59:
+#line 486 "src/parse-gram.y" /* yacc.c:1644  */
     {
       (*(symbol**)(&yyval)) = (*(symbol**)(&yyvsp[-1]));
       symbol_user_token_number_set ((*(symbol**)(&yyvsp[-1])), (*(int*)(&yyvsp[0])), (yylsp[0]));
       symbol_class_set ((*(symbol**)(&yyvsp[-1])), token_sym, (yylsp[-1]), false);
     }
-#line 2481 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2476 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
-  case 61:
-#line 503 "src/parse-gram.y" /* yacc.c:1645  */
+  case 60:
+#line 496 "src/parse-gram.y" /* yacc.c:1644  */
     { (*(symbol_list**)(&yyval)) = symbol_list_sym_new ((*(symbol**)(&yyvsp[0])), (yylsp[0])); }
-#line 2487 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2482 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
-  case 62:
-#line 505 "src/parse-gram.y" /* yacc.c:1645  */
+  case 61:
+#line 498 "src/parse-gram.y" /* yacc.c:1644  */
     { (*(symbol_list**)(&yyval)) = symbol_list_append ((*(symbol_list**)(&yyvsp[-1])), symbol_list_sym_new ((*(symbol**)(&yyvsp[0])), (yylsp[0]))); }
-#line 2493 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2488 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
-  case 63:
-#line 509 "src/parse-gram.y" /* yacc.c:1645  */
+  case 62:
+#line 502 "src/parse-gram.y" /* yacc.c:1644  */
     { (*(symbol_list**)(&yyval)) = (*(symbol_list**)(&yyvsp[0])); }
-#line 2499 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2494 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
-  case 64:
-#line 510 "src/parse-gram.y" /* yacc.c:1645  */
+  case 63:
+#line 503 "src/parse-gram.y" /* yacc.c:1644  */
     { (*(symbol_list**)(&yyval)) = symbol_list_append ((*(symbol_list**)(&yyvsp[-1])), (*(symbol_list**)(&yyvsp[0]))); }
-#line 2505 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2500 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
-  case 65:
-#line 514 "src/parse-gram.y" /* yacc.c:1645  */
+  case 64:
+#line 507 "src/parse-gram.y" /* yacc.c:1644  */
     { (*(symbol_list**)(&yyval)) = symbol_list_sym_new ((*(symbol**)(&yyvsp[0])), (yylsp[0])); }
-#line 2511 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2506 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
-  case 66:
-#line 515 "src/parse-gram.y" /* yacc.c:1645  */
+  case 65:
+#line 508 "src/parse-gram.y" /* yacc.c:1644  */
     { (*(symbol_list**)(&yyval)) = symbol_list_type_new ((*(uniqstr*)(&yyvsp[0])), (yylsp[0])); }
-#line 2517 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2512 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
-  case 68:
-#line 520 "src/parse-gram.y" /* yacc.c:1645  */
+  case 67:
+#line 513 "src/parse-gram.y" /* yacc.c:1644  */
     { (*(uniqstr*)(&yyval)) = uniqstr_new ("*"); }
-#line 2523 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2518 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
-  case 69:
-#line 521 "src/parse-gram.y" /* yacc.c:1645  */
+  case 68:
+#line 514 "src/parse-gram.y" /* yacc.c:1644  */
     { (*(uniqstr*)(&yyval)) = uniqstr_new (""); }
-#line 2529 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2524 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
-  case 70:
-#line 527 "src/parse-gram.y" /* yacc.c:1645  */
+  case 69:
+#line 520 "src/parse-gram.y" /* yacc.c:1644  */
     {
       current_type = (*(uniqstr*)(&yyvsp[0]));
       tag_seen = true;
     }
-#line 2538 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2533 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
-  case 71:
-#line 532 "src/parse-gram.y" /* yacc.c:1645  */
+  case 70:
+#line 525 "src/parse-gram.y" /* yacc.c:1644  */
     {
       symbol_class_set ((*(symbol**)(&yyvsp[0])), current_class, (yylsp[0]), true);
       symbol_type_set ((*(symbol**)(&yyvsp[0])), current_type, (yylsp[0]));
     }
-#line 2547 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2542 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
-  case 72:
-#line 537 "src/parse-gram.y" /* yacc.c:1645  */
+  case 71:
+#line 530 "src/parse-gram.y" /* yacc.c:1644  */
     {
       symbol_class_set ((*(symbol**)(&yyvsp[-1])), current_class, (yylsp[-1]), true);
       symbol_type_set ((*(symbol**)(&yyvsp[-1])), current_type, (yylsp[-1]));
       symbol_user_token_number_set ((*(symbol**)(&yyvsp[-1])), (*(int*)(&yyvsp[0])), (yylsp[0]));
     }
-#line 2557 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2552 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
-  case 73:
-#line 543 "src/parse-gram.y" /* yacc.c:1645  */
+  case 72:
+#line 536 "src/parse-gram.y" /* yacc.c:1644  */
     {
       symbol_class_set ((*(symbol**)(&yyvsp[-1])), current_class, (yylsp[-1]), true);
       symbol_type_set ((*(symbol**)(&yyvsp[-1])), current_type, (yylsp[-1]));
       symbol_make_alias ((*(symbol**)(&yyvsp[-1])), (*(symbol**)(&yyvsp[0])), (yyloc));
     }
-#line 2567 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2562 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
-  case 74:
-#line 549 "src/parse-gram.y" /* yacc.c:1645  */
+  case 73:
+#line 542 "src/parse-gram.y" /* yacc.c:1644  */
     {
       symbol_class_set ((*(symbol**)(&yyvsp[-2])), current_class, (yylsp[-2]), true);
       symbol_type_set ((*(symbol**)(&yyvsp[-2])), current_type, (yylsp[-2]));
       symbol_user_token_number_set ((*(symbol**)(&yyvsp[-2])), (*(int*)(&yyvsp[-1])), (yylsp[-1]));
       symbol_make_alias ((*(symbol**)(&yyvsp[-2])), (*(symbol**)(&yyvsp[0])), (yyloc));
     }
-#line 2578 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2573 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
-  case 81:
-#line 579 "src/parse-gram.y" /* yacc.c:1645  */
+  case 80:
+#line 572 "src/parse-gram.y" /* yacc.c:1644  */
     {
       yyerrok;
     }
-#line 2586 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2581 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
-  case 82:
-#line 585 "src/parse-gram.y" /* yacc.c:1645  */
+  case 81:
+#line 578 "src/parse-gram.y" /* yacc.c:1644  */
     { current_lhs ((*(symbol**)(&yyvsp[-1])), (yylsp[-1]), (*(named_ref**)(&yyvsp[0]))); }
-#line 2592 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2587 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
-  case 83:
-#line 586 "src/parse-gram.y" /* yacc.c:1645  */
+  case 82:
+#line 579 "src/parse-gram.y" /* yacc.c:1644  */
     {
       /* Free the current lhs. */
       current_lhs (0, (yylsp[-3]), 0);
     }
-#line 2601 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2596 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
-  case 84:
-#line 593 "src/parse-gram.y" /* yacc.c:1645  */
+  case 83:
+#line 586 "src/parse-gram.y" /* yacc.c:1644  */
     { grammar_current_rule_end ((yylsp[0])); }
-#line 2607 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2602 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
-  case 85:
-#line 594 "src/parse-gram.y" /* yacc.c:1645  */
+  case 84:
+#line 587 "src/parse-gram.y" /* yacc.c:1644  */
     { grammar_current_rule_end ((yylsp[0])); }
-#line 2613 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2608 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
-  case 87:
-#line 601 "src/parse-gram.y" /* yacc.c:1645  */
+  case 86:
+#line 594 "src/parse-gram.y" /* yacc.c:1644  */
     { grammar_current_rule_begin (current_lhs_symbol, current_lhs_location,
                                   current_lhs_named_ref); }
-#line 2620 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2615 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
-  case 88:
-#line 604 "src/parse-gram.y" /* yacc.c:1645  */
+  case 87:
+#line 597 "src/parse-gram.y" /* yacc.c:1644  */
     { grammar_current_rule_symbol_append ((*(symbol**)(&yyvsp[-1])), (yylsp[-1]), (*(named_ref**)(&yyvsp[0]))); }
-#line 2626 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2621 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
-  case 89:
-#line 606 "src/parse-gram.y" /* yacc.c:1645  */
+  case 88:
+#line 599 "src/parse-gram.y" /* yacc.c:1644  */
     { grammar_current_rule_action_append ((*(char**)(&yyvsp[-1])), (yylsp[-1]), (*(named_ref**)(&yyvsp[0])), current_type); }
-#line 2632 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2627 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
-  case 90:
-#line 608 "src/parse-gram.y" /* yacc.c:1645  */
+  case 89:
+#line 601 "src/parse-gram.y" /* yacc.c:1644  */
     { grammar_current_rule_predicate_append ((*(char**)(&yyvsp[0])), (yylsp[0])); }
-#line 2638 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2633 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
-  case 91:
-#line 610 "src/parse-gram.y" /* yacc.c:1645  */
+  case 90:
+#line 603 "src/parse-gram.y" /* yacc.c:1644  */
     { grammar_current_rule_empty_set ((yylsp[0])); }
-#line 2644 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2639 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
-  case 92:
-#line 612 "src/parse-gram.y" /* yacc.c:1645  */
+  case 91:
+#line 605 "src/parse-gram.y" /* yacc.c:1644  */
     { grammar_current_rule_prec_set ((*(symbol**)(&yyvsp[0])), (yylsp[0])); }
-#line 2650 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2645 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
-  case 93:
-#line 614 "src/parse-gram.y" /* yacc.c:1645  */
+  case 92:
+#line 607 "src/parse-gram.y" /* yacc.c:1644  */
     { grammar_current_rule_dprec_set ((*(int*)(&yyvsp[0])), (yylsp[0])); }
-#line 2656 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2651 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
-  case 94:
-#line 616 "src/parse-gram.y" /* yacc.c:1645  */
+  case 93:
+#line 609 "src/parse-gram.y" /* yacc.c:1644  */
     { grammar_current_rule_merge_set ((*(uniqstr*)(&yyvsp[0])), (yylsp[0])); }
-#line 2662 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2657 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
-  case 95:
-#line 620 "src/parse-gram.y" /* yacc.c:1645  */
+  case 94:
+#line 613 "src/parse-gram.y" /* yacc.c:1644  */
     { (*(named_ref**)(&yyval)) = 0; }
-#line 2668 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2663 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
-  case 96:
-#line 621 "src/parse-gram.y" /* yacc.c:1645  */
+  case 95:
+#line 614 "src/parse-gram.y" /* yacc.c:1644  */
     { (*(named_ref**)(&yyval)) = named_ref_new ((*(uniqstr*)(&yyvsp[0])), (yylsp[0])); }
-#line 2674 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2669 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
-  case 98:
-#line 654 "src/parse-gram.y" /* yacc.c:1645  */
+  case 97:
+#line 647 "src/parse-gram.y" /* yacc.c:1644  */
     { (*(value_type*)(&yyval)).kind = muscle_keyword; (*(value_type*)(&yyval)).chars = ""; }
-#line 2680 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2675 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
-  case 99:
-#line 655 "src/parse-gram.y" /* yacc.c:1645  */
+  case 98:
+#line 648 "src/parse-gram.y" /* yacc.c:1644  */
     { (*(value_type*)(&yyval)).kind = muscle_keyword; (*(value_type*)(&yyval)).chars = (*(uniqstr*)(&yyvsp[0])); }
-#line 2686 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2681 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
-  case 100:
-#line 656 "src/parse-gram.y" /* yacc.c:1645  */
+  case 99:
+#line 649 "src/parse-gram.y" /* yacc.c:1644  */
     { (*(value_type*)(&yyval)).kind = muscle_string;  (*(value_type*)(&yyval)).chars = (*(char**)(&yyvsp[0])); }
-#line 2692 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2687 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
-  case 101:
-#line 657 "src/parse-gram.y" /* yacc.c:1645  */
+  case 100:
+#line 650 "src/parse-gram.y" /* yacc.c:1644  */
     { (*(value_type*)(&yyval)).kind = muscle_code;    (*(value_type*)(&yyval)).chars = strip_braces ((*(char**)(&yyvsp[0]))); }
-#line 2698 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2693 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
-  case 102:
-#line 670 "src/parse-gram.y" /* yacc.c:1645  */
+  case 101:
+#line 663 "src/parse-gram.y" /* yacc.c:1644  */
     { (*(symbol**)(&yyval)) = symbol_from_uniqstr ((*(uniqstr*)(&yyvsp[0])), (yylsp[0])); }
-#line 2704 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2699 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
-  case 103:
-#line 672 "src/parse-gram.y" /* yacc.c:1645  */
+  case 102:
+#line 665 "src/parse-gram.y" /* yacc.c:1644  */
     {
       (*(symbol**)(&yyval)) = symbol_get (char_name ((*(unsigned char*)(&yyvsp[0]))), (yylsp[0]));
       symbol_class_set ((*(symbol**)(&yyval)), token_sym, (yylsp[0]), false);
       symbol_user_token_number_set ((*(symbol**)(&yyval)), (*(unsigned char*)(&yyvsp[0])), (yylsp[0]));
     }
-#line 2714 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2709 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
-  case 104:
-#line 680 "src/parse-gram.y" /* yacc.c:1645  */
+  case 103:
+#line 673 "src/parse-gram.y" /* yacc.c:1644  */
     { (*(symbol**)(&yyval)) = symbol_from_uniqstr ((*(uniqstr*)(&yyvsp[0])), (yylsp[0])); }
-#line 2720 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2715 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
-  case 107:
-#line 692 "src/parse-gram.y" /* yacc.c:1645  */
+  case 106:
+#line 685 "src/parse-gram.y" /* yacc.c:1644  */
     {
       (*(symbol**)(&yyval)) = symbol_get (quotearg_style (c_quoting_style, (*(char**)(&yyvsp[0]))), (yylsp[0]));
       symbol_class_set ((*(symbol**)(&yyval)), token_sym, (yylsp[0]), false);
     }
-#line 2729 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2724 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
-  case 109:
-#line 701 "src/parse-gram.y" /* yacc.c:1645  */
+  case 108:
+#line 694 "src/parse-gram.y" /* yacc.c:1644  */
     {
       muscle_code_grow ("epilogue", translate_code ((*(char**)(&yyvsp[0])), (yylsp[0]), true), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2738 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2733 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
 
-#line 2742 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2737 "src/parse-gram.c" /* yacc.c:1644  */
         default: break;
       }
     if (yychar_backup != yychar)
@@ -2983,7 +2978,7 @@ yyreturn:
 #endif
   return yyresult;
 }
-#line 707 "src/parse-gram.y" /* yacc.c:1903  */
+#line 700 "src/parse-gram.y" /* yacc.c:1902  */
 
 
 /* Return the location of the left-hand side of a rule whose
