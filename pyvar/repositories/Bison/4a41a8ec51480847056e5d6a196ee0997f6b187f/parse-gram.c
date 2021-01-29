@@ -125,7 +125,7 @@ extern int gram_debug;
 
   #include "symlist.h"
   #include "symtab.h"
-#line 225 "src/parse-gram.y" /* yacc.c:352  */
+#line 230 "src/parse-gram.y" /* yacc.c:352  */
 
   typedef enum
   {
@@ -134,7 +134,7 @@ extern int gram_debug;
     param_parse  = 1 << 1,
     param_both   = param_lex | param_parse
   } param_type;
-#line 667 "src/parse-gram.y" /* yacc.c:352  */
+#line 673 "src/parse-gram.y" /* yacc.c:352  */
 
   #include "muscle-tab.h"
   typedef struct
@@ -168,43 +168,44 @@ extern int gram_debug;
     PERCENT_DEFAULT_PREC = 272,
     PERCENT_DEFINE = 273,
     PERCENT_DEFINES = 274,
-    PERCENT_EXPECT = 275,
-    PERCENT_EXPECT_RR = 276,
-    PERCENT_FLAG = 277,
-    PERCENT_FILE_PREFIX = 278,
-    PERCENT_GLR_PARSER = 279,
-    PERCENT_INITIAL_ACTION = 280,
-    PERCENT_LANGUAGE = 281,
-    PERCENT_NAME_PREFIX = 282,
-    PERCENT_NO_DEFAULT_PREC = 283,
-    PERCENT_NO_LINES = 284,
-    PERCENT_NONDETERMINISTIC_PARSER = 285,
-    PERCENT_OUTPUT = 286,
-    PERCENT_REQUIRE = 287,
-    PERCENT_SKELETON = 288,
-    PERCENT_START = 289,
-    PERCENT_TOKEN_TABLE = 290,
-    PERCENT_VERBOSE = 291,
-    PERCENT_YACC = 292,
-    BRACED_CODE = 293,
-    BRACED_PREDICATE = 294,
-    BRACKETED_ID = 295,
-    CHAR = 296,
-    EPILOGUE = 297,
-    EQUAL = 298,
-    ID = 299,
-    ID_COLON = 300,
-    PERCENT_PERCENT = 301,
-    PIPE = 302,
-    PROLOGUE = 303,
-    SEMICOLON = 304,
-    TAG = 305,
-    TAG_ANY = 306,
-    TAG_NONE = 307,
-    INT = 308,
-    PERCENT_PARAM = 309,
-    PERCENT_UNION = 310,
-    PERCENT_EMPTY = 311
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
+    PERCENT_PARAM = 310,
+    PERCENT_UNION = 311,
+    PERCENT_EMPTY = 312
   };
 #endif
 
@@ -231,9 +232,9 @@ union GRAM_STYPE
   /* "integer"  */
   int INT;
   /* int.opt  */
-  int yytype_78;
+  int yytype_79;
   /* named_ref.opt  */
-  named_ref* yytype_90;
+  named_ref* yytype_91;
   /* "%param"  */
   param_type PERCENT_PARAM;
   /* token_decl  */
@@ -249,7 +250,7 @@ union GRAM_STYPE
   /* string_as_id  */
   symbol* string_as_id;
   /* string_as_id.opt  */
-  symbol* yytype_97;
+  symbol* yytype_98;
   /* generic_symlist  */
   symbol_list* generic_symlist;
   /* generic_symlist_item  */
@@ -259,15 +260,17 @@ union GRAM_STYPE
   /* token_decls  */
   symbol_list* token_decls;
   /* token_decl.1  */
-  symbol_list* yytype_76;
+  symbol_list* yytype_77;
   /* token_decls_for_prec  */
   symbol_list* token_decls_for_prec;
   /* token_decl_for_prec.1  */
-  symbol_list* yytype_80;
+  symbol_list* yytype_81;
   /* symbol_decls  */
   symbol_list* symbol_decls;
   /* symbol_decl.1  */
-  symbol_list* yytype_83;
+  symbol_list* yytype_84;
+  /* "%error-verbose"  */
+  uniqstr PERCENT_ERROR_VERBOSE;
   /* "%<flag>"  */
   uniqstr PERCENT_FLAG;
   /* "%name-prefix"  */
@@ -281,7 +284,7 @@ union GRAM_STYPE
   /* "<tag>"  */
   uniqstr TAG;
   /* tag.opt  */
-  uniqstr yytype_70;
+  uniqstr yytype_71;
   /* tag  */
   uniqstr tag;
   /* variable  */
@@ -290,7 +293,7 @@ union GRAM_STYPE
   unsigned char CHAR;
   /* value  */
   value_type value;
-#line 294 "src/parse-gram.c" /* yacc.c:352  */
+#line 297 "src/parse-gram.c" /* yacc.c:352  */
 };
 
 typedef union GRAM_STYPE GRAM_STYPE;
@@ -373,6 +376,9 @@ int gram_parse (void);
      string from the scanner (should be CODE). */
   static char const *translate_code_braceless (char *code, location loc);
 
+  /* Handle a %error-verbose directive.  */
+  static void do_error_verbose (location const *loc, char const *directive);
+
   /* Handle a %name-prefix directive.  */
   static void do_name_prefix (location const *loc,
                               char const *directive, char const *value);
@@ -392,7 +398,7 @@ int gram_parse (void);
   #define YYTYPE_INT8 int_fast8_t
   #define YYTYPE_UINT16 uint_fast16_t
   #define YYTYPE_UINT8 uint_fast8_t
-#line 235 "src/parse-gram.y" /* yacc.c:355  */
+#line 240 "src/parse-gram.y" /* yacc.c:355  */
 
   /** Add a lex-param and/or a parse-param.
    *
@@ -403,7 +409,7 @@ int gram_parse (void);
   static void add_param (param_type type, char *decl, location loc);
   static param_type current_param = param_none;
 
-#line 407 "src/parse-gram.c" /* yacc.c:355  */
+#line 413 "src/parse-gram.c" /* yacc.c:355  */
 
 #ifdef short
 # undef short
@@ -615,19 +621,19 @@ union yyalloc
 /* YYFINAL -- State number of the termination state.  */
 #define YYFINAL  3
 /* YYLAST -- Last index in YYTABLE.  */
-#define YYLAST   227
+#define YYLAST   229
 
 /* YYNTOKENS -- Number of terminals.  */
-#define YYNTOKENS  57
+#define YYNTOKENS  58
 /* YYNNTS -- Number of nonterminals.  */
 #define YYNNTS  42
 /* YYNRULES -- Number of rules.  */
-#define YYNRULES  120
+#define YYNRULES  121
 /* YYNSTATES -- Number of states.  */
-#define YYNSTATES  163
+#define YYNSTATES  164
 
 #define YYUNDEFTOK  2
-#define YYMAXUTOK   311
+#define YYMAXUTOK   312
 
 /* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
    as returned by yylex, with out-of-bounds checking.  */
@@ -669,26 +675,26 @@ static const yytype_uint8 yytranslate[] =
       25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
       35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
       45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
-      55,    56
+      55,    56,    57
 };
 
 #if GRAM_DEBUG
   /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
 static const yytype_uint16 yyrline[] =
 {
-       0,   267,   267,   276,   277,   281,   282,   288,   292,   297,
-     298,   303,   304,   305,   306,   311,   316,   317,   318,   319,
-     320,   321,   321,   322,   323,   324,   325,   326,   327,   328,
-     332,   333,   342,   343,   347,   358,   362,   366,   374,   384,
-     385,   395,   396,   402,   415,   415,   420,   420,   425,   429,
-     439,   440,   441,   442,   446,   447,   452,   453,   457,   458,
-     462,   463,   464,   477,   486,   490,   494,   502,   503,   507,
-     520,   521,   533,   537,   541,   549,   551,   556,   563,   573,
-     577,   581,   589,   590,   598,   599,   605,   606,   607,   614,
-     614,   622,   623,   624,   629,   632,   634,   636,   638,   640,
-     642,   644,   646,   648,   653,   654,   663,   687,   688,   689,
-     690,   702,   704,   719,   724,   725,   730,   739,   740,   744,
-     745
+       0,   272,   272,   281,   282,   286,   287,   293,   297,   302,
+     303,   308,   309,   310,   311,   312,   317,   322,   323,   324,
+     325,   326,   327,   327,   328,   329,   330,   331,   332,   333,
+     334,   338,   339,   348,   349,   353,   364,   368,   372,   380,
+     390,   391,   401,   402,   408,   421,   421,   426,   426,   431,
+     435,   445,   446,   447,   448,   452,   453,   458,   459,   463,
+     464,   468,   469,   470,   483,   492,   496,   500,   508,   509,
+     513,   526,   527,   539,   543,   547,   555,   557,   562,   569,
+     579,   583,   587,   595,   596,   604,   605,   611,   612,   613,
+     620,   620,   628,   629,   630,   635,   638,   640,   642,   644,
+     646,   648,   650,   652,   654,   659,   660,   669,   693,   694,
+     695,   696,   708,   710,   725,   730,   731,   736,   745,   746,
+     750,   751
 };
 #endif
 
@@ -701,25 +707,26 @@ static const char *const yytname[] =
   "\"%nterm\"", "\"%type\"", "\"%destructor\"", "\"%printer\"",
   "\"%left\"", "\"%right\"", "\"%nonassoc\"", "\"%precedence\"",
   "\"%prec\"", "\"%dprec\"", "\"%merge\"", "\"%code\"",
-  "\"%default-prec\"", "\"%define\"", "\"%defines\"", "\"%expect\"",
-  "\"%expect-rr\"", "\"%<flag>\"", "\"%file-prefix\"", "\"%glr-parser\"",
-  "\"%initial-action\"", "\"%language\"", "\"%name-prefix\"",
-  "\"%no-default-prec\"", "\"%no-lines\"", "\"%nondeterministic-parser\"",
-  "\"%output\"", "\"%require\"", "\"%skeleton\"", "\"%start\"",
-  "\"%token-table\"", "\"%verbose\"", "\"%yacc\"", "\"{...}\"",
-  "\"%?{...}\"", "\"[identifier]\"", "\"char\"", "\"epilogue\"", "\"=\"",
-  "\"identifier\"", "\"identifier:\"", "\"%%\"", "\"|\"", "\"%{...%}\"",
-  "\";\"", "\"<tag>\"", "\"<*>\"", "\"<>\"", "\"integer\"", "\"%param\"",
-  "\"%union\"", "\"%empty\"", "$accept", "input", "prologue_declarations",
-  "prologue_declaration", "$@1", "params", "grammar_declaration",
-  "code_props_type", "union_name", "symbol_declaration", "$@2", "$@3",
-  "precedence_declarator", "tag.opt", "generic_symlist",
-  "generic_symlist_item", "tag", "nterm_decls", "token_decls",
-  "token_decl.1", "token_decl", "int.opt", "token_decls_for_prec",
-  "token_decl_for_prec.1", "token_decl_for_prec", "symbol_decls",
-  "symbol_decl.1", "grammar", "rules_or_grammar_declaration", "rules",
-  "$@4", "rhses.1", "rhs", "named_ref.opt", "variable", "value", "id",
-  "id_colon", "symbol", "string_as_id", "string_as_id.opt", "epilogue.opt", YY_NULLPTR
+  "\"%default-prec\"", "\"%define\"", "\"%defines\"", "\"%error-verbose\"",
+  "\"%expect\"", "\"%expect-rr\"", "\"%<flag>\"", "\"%file-prefix\"",
+  "\"%glr-parser\"", "\"%initial-action\"", "\"%language\"",
+  "\"%name-prefix\"", "\"%no-default-prec\"", "\"%no-lines\"",
+  "\"%nondeterministic-parser\"", "\"%output\"", "\"%require\"",
+  "\"%skeleton\"", "\"%start\"", "\"%token-table\"", "\"%verbose\"",
+  "\"%yacc\"", "\"{...}\"", "\"%?{...}\"", "\"[identifier]\"", "\"char\"",
+  "\"epilogue\"", "\"=\"", "\"identifier\"", "\"identifier:\"", "\"%%\"",
+  "\"|\"", "\"%{...%}\"", "\";\"", "\"<tag>\"", "\"<*>\"", "\"<>\"",
+  "\"integer\"", "\"%param\"", "\"%union\"", "\"%empty\"", "$accept",
+  "input", "prologue_declarations", "prologue_declaration", "$@1",
+  "params", "grammar_declaration", "code_props_type", "union_name",
+  "symbol_declaration", "$@2", "$@3", "precedence_declarator", "tag.opt",
+  "generic_symlist", "generic_symlist_item", "tag", "nterm_decls",
+  "token_decls", "token_decl.1", "token_decl", "int.opt",
+  "token_decls_for_prec", "token_decl_for_prec.1", "token_decl_for_prec",
+  "symbol_decls", "symbol_decl.1", "grammar",
+  "rules_or_grammar_declaration", "rules", "$@4", "rhses.1", "rhs",
+  "named_ref.opt", "variable", "value", "id", "id_colon", "symbol",
+  "string_as_id", "string_as_id.opt", "epilogue.opt", YY_NULLPTR
 };
 #endif
 
@@ -733,16 +740,16 @@ static const yytype_uint16 yytoknum[] =
      275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
      285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
      295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
-     305,   306,   307,   308,   309,   310,   311
+     305,   306,   307,   308,   309,   310,   311,   312
 };
 # endif
 
-#define YYPACT_NINF -131
+#define YYPACT_NINF -123
 
 #define yypact_value_is_default(Yystate) \
-  (!!((Yystate) == (-131)))
+  (!!((Yystate) == (-123)))
 
-#define YYTABLE_NINF -120
+#define YYTABLE_NINF -121
 
 #define yytable_value_is_error(Yytable_value) \
   0
@@ -751,23 +758,23 @@ static const yytype_uint16 yytoknum[] =
      STATE-NUM.  */
 static const yytype_int16 yypact[] =
 {
-    -131,     5,   109,  -131,   -43,  -131,  -131,    30,  -131,  -131,
-    -131,  -131,  -131,  -131,    23,  -131,    -9,    33,   -14,     3,
-    -131,    56,  -131,    22,    60,    69,  -131,  -131,  -131,    70,
-      78,    79,    46,  -131,  -131,  -131,   161,  -131,  -131,  -131,
-      41,  -131,  -131,    63,  -131,    50,  -131,   -12,   -12,  -131,
-    -131,  -131,    46,    53,    46,  -131,  -131,  -131,  -131,    66,
-    -131,    24,  -131,  -131,  -131,  -131,  -131,  -131,  -131,  -131,
-    -131,  -131,  -131,    49,  -131,    57,     9,  -131,  -131,    65,
-      73,  -131,    85,    25,    46,    58,    46,  -131,    54,  -131,
-     -10,    74,   -10,  -131,    54,  -131,    74,    46,    46,  -131,
-    -131,  -131,  -131,  -131,  -131,  -131,  -131,   105,  -131,  -131,
-    -131,  -131,  -131,   110,  -131,  -131,  -131,  -131,    25,  -131,
-    -131,  -131,    46,    46,  -131,  -131,  -131,   -10,   -10,  -131,
-     146,    46,  -131,  -131,  -131,  -131,    46,   -10,  -131,  -131,
-      48,   171,  -131,  -131,    46,    97,   101,    99,   100,  -131,
-    -131,  -131,   116,    65,   171,  -131,  -131,  -131,  -131,  -131,
-      65,  -131,  -131
+    -123,     6,   109,  -123,   -21,  -123,  -123,     2,  -123,  -123,
+    -123,  -123,  -123,  -123,   -11,  -123,    -7,    46,  -123,     3,
+      13,  -123,    77,  -123,    43,    87,    88,  -123,  -123,  -123,
+      91,    92,    94,    32,  -123,  -123,  -123,   162,  -123,  -123,
+    -123,    53,  -123,  -123,    61,  -123,    30,  -123,   -15,   -15,
+    -123,  -123,  -123,    32,    50,    32,  -123,  -123,  -123,  -123,
+      64,  -123,    23,  -123,  -123,  -123,  -123,  -123,  -123,  -123,
+    -123,  -123,  -123,  -123,    54,  -123,    55,     8,  -123,  -123,
+      65,    68,  -123,    69,    18,    32,    60,    32,  -123,    70,
+    -123,    16,    72,    16,  -123,    70,  -123,    72,    32,    32,
+    -123,  -123,  -123,  -123,  -123,  -123,  -123,  -123,   105,  -123,
+    -123,  -123,  -123,  -123,   110,  -123,  -123,  -123,  -123,    18,
+    -123,  -123,  -123,    32,    32,  -123,  -123,  -123,    16,    16,
+    -123,   147,    32,  -123,  -123,  -123,  -123,    32,    16,  -123,
+    -123,    37,   172,  -123,  -123,    32,    97,   101,    99,   100,
+    -123,  -123,  -123,   116,    65,   172,  -123,  -123,  -123,  -123,
+    -123,    65,  -123,  -123
 };
 
   /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
@@ -775,43 +782,43 @@ static const yytype_int16 yypact[] =
      means the default is an error.  */
 static const yytype_uint8 yydefact[] =
 {
-       3,     0,     0,     1,     0,    46,    44,     0,    39,    40,
-      50,    51,    52,    53,     0,    35,     0,     9,     0,     0,
-       7,     0,    14,     0,     0,     0,    36,    18,    19,     0,
-       0,     0,     0,    25,    26,    27,     0,     6,    29,    21,
-      41,     4,     5,     0,    32,     0,    28,     0,     0,   116,
-     112,   111,     0,    48,    79,   114,    82,   115,    37,     0,
-     106,   107,    10,    11,    12,    13,    15,    16,    17,    20,
-      23,    24,    33,     0,   113,     0,     0,    84,    86,   104,
-       0,    42,     0,     0,     0,    49,    72,    75,    70,    78,
-       0,    47,    64,    67,    70,    45,    63,    80,     0,    83,
-      38,   109,   110,   108,     8,    88,    87,     0,    85,     2,
-     105,    89,    31,    22,    43,    60,    61,    62,    34,    56,
-      59,    58,    73,     0,    76,    71,    77,    65,     0,    68,
-     117,    81,   120,    94,    30,    57,    74,    66,   118,    69,
-      90,    91,    94,    93,     0,     0,     0,     0,     0,    97,
-      55,    98,     0,   104,    92,    99,   100,   101,   102,   103,
-     104,    95,    96
+       3,     0,     0,     1,     0,    47,    45,     0,    40,    41,
+      51,    52,    53,    54,     0,    36,     0,     9,    11,     0,
+       0,     7,     0,    15,     0,     0,     0,    37,    19,    20,
+       0,     0,     0,     0,    26,    27,    28,     0,     6,    30,
+      22,    42,     4,     5,     0,    33,     0,    29,     0,     0,
+     117,   113,   112,     0,    49,    80,   115,    83,   116,    38,
+       0,   107,   108,    10,    12,    13,    14,    16,    17,    18,
+      21,    24,    25,    34,     0,   114,     0,     0,    85,    87,
+     105,     0,    43,     0,     0,     0,    50,    73,    76,    71,
+      79,     0,    48,    65,    68,    71,    46,    64,    81,     0,
+      84,    39,   110,   111,   109,     8,    89,    88,     0,    86,
+       2,   106,    90,    32,    23,    44,    61,    62,    63,    35,
+      57,    60,    59,    74,     0,    77,    72,    78,    66,     0,
+      69,   118,    82,   121,    95,    31,    58,    75,    67,   119,
+      70,    91,    92,    95,    94,     0,     0,     0,     0,     0,
+      98,    56,    99,     0,   105,    93,   100,   101,   102,   103,
+     104,   105,    96,    97
 };
 
   /* YYPGOTO[NTERM-NUM].  */
 static const yytype_int16 yypgoto[] =
 {
-    -131,  -131,  -131,  -131,  -131,  -131,   154,  -131,  -131,  -131,
-    -131,  -131,  -131,  -131,  -131,    42,  -131,  -131,   111,   -83,
-     -80,    67,  -131,   -82,   -78,  -131,   -28,  -131,   103,  -131,
-    -131,  -131,    34,  -130,  -131,  -131,   -44,  -131,   -32,   -34,
-    -131,  -131
+    -123,  -123,  -123,  -123,  -123,  -123,   155,  -123,  -123,  -123,
+    -123,  -123,  -123,  -123,  -123,    41,  -123,  -123,   112,   -84,
+     -62,    67,  -123,   -83,   -64,  -123,   -43,  -123,   103,  -123,
+    -123,  -123,    33,  -122,  -123,  -123,   -45,  -123,   -33,   -35,
+    -123,  -123
 };
 
   /* YYDEFGOTO[NTERM-NUM].  */
 static const yytype_int16 yydefgoto[] =
 {
-      -1,     1,     2,    41,    80,   113,    75,    43,    82,    44,
-      48,    47,    45,   152,   118,   119,   120,    95,    91,    92,
-      93,   126,    85,    86,    87,    53,    54,    76,    77,    78,
-     133,   140,   141,   111,    61,   104,    55,    79,    56,    57,
-     139,   109
+      -1,     1,     2,    42,    81,   114,    76,    44,    83,    45,
+      49,    48,    46,   153,   119,   120,   121,    96,    92,    93,
+      94,   127,    86,    87,    88,    54,    55,    77,    78,    79,
+     134,   141,   142,   112,    62,   105,    56,    80,    57,    58,
+     140,   110
 };
 
   /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
@@ -819,115 +826,115 @@ static const yytype_int16 yydefgoto[] =
      number is the opposite.  If YYTABLE_NINF, syntax error.  */
 static const yytype_int16 yytable[] =
 {
-      72,    88,   122,    94,    94,     3,    46,   127,   124,  -119,
-      73,    89,   129,     5,     6,     7,     8,     9,    10,    11,
-      12,    13,    99,   161,    97,    14,    15,   101,    49,    50,
-     162,    50,    51,    49,    51,    60,    62,    26,    90,    63,
-      88,   136,    88,    32,   124,   137,    94,   129,    94,    49,
-      89,   121,    89,    49,    74,   107,    64,   129,   124,    65,
-      66,    58,   102,    67,    40,    99,    50,    59,   103,    51,
-     131,    50,    68,    69,    51,   115,   116,   117,    88,    88,
-      52,    70,    71,    94,    94,    81,   121,    50,    89,    89,
-      51,    50,    88,    94,    51,   142,   138,   143,   105,    99,
-      84,    83,    89,    98,   100,   110,   106,   125,   123,   153,
-       4,   112,   155,     5,     6,     7,     8,     9,    10,    11,
-      12,    13,   153,   114,   128,    14,    15,    16,    17,    18,
+      73,    89,   123,    95,    95,    50,     3,   128,  -120,    74,
+      98,    90,     5,     6,     7,     8,     9,    10,    11,    12,
+      13,    50,   100,   125,    14,    15,   102,    51,    59,    47,
+      52,   130,   162,    50,    60,    50,    91,    27,    61,   163,
+      89,   137,    89,    33,    51,   138,    95,    52,    95,    63,
+      90,   122,    90,    53,    75,   108,   132,    64,    51,   125,
+      51,    52,   103,    52,    41,   100,   130,    65,   104,   116,
+     117,   118,    51,   125,    51,    52,   130,    52,    89,    89,
+      66,    85,    67,    95,    95,   143,   122,   144,    90,    90,
+      68,    69,    89,    95,    70,    71,   139,    72,    82,   100,
+      84,    99,    90,   101,   106,   107,   111,   113,   115,   154,
+       4,   124,   156,     5,     6,     7,     8,     9,    10,    11,
+      12,    13,   154,   129,   126,    14,    15,    16,    17,    18,
       19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
-      29,    30,    31,    32,    33,    34,    35,   132,   134,    49,
-     156,   157,   158,   159,   160,    36,    42,    37,    38,    96,
-     135,   130,    73,    39,    40,     5,     6,     7,     8,     9,
-      10,    11,    12,    13,    49,     0,   154,    14,    15,   108,
-       0,     0,     0,     0,   144,   145,   146,     0,     0,    26,
-       0,   147,   148,     0,     0,    32,     0,     0,     0,     0,
-       0,     0,     0,     0,     0,     0,    74,     0,     0,   -54,
-     149,     0,    50,     0,     0,    51,    40,     0,     0,     0,
-       0,   150,     0,     0,     0,     0,     0,   151
+      29,    30,    31,    32,    33,    34,    35,    36,   133,   135,
+      50,   157,   158,   159,   160,   161,    37,    43,    38,    39,
+     136,    97,   131,    74,    40,    41,     5,     6,     7,     8,
+       9,    10,    11,    12,    13,    50,   155,     0,    14,    15,
+     109,     0,     0,     0,     0,   145,   146,   147,     0,     0,
+       0,    27,     0,   148,   149,     0,     0,    33,     0,     0,
+       0,     0,     0,     0,     0,     0,     0,     0,    75,     0,
+       0,   -55,   150,     0,    51,     0,     0,    52,    41,     0,
+       0,     0,     0,   151,     0,     0,     0,     0,     0,   152
 };
 
 static const yytype_int16 yycheck[] =
 {
-      32,    45,    84,    47,    48,     0,    49,    90,    86,     0,
-       1,    45,    92,     4,     5,     6,     7,     8,     9,    10,
-      11,    12,    54,   153,    52,    16,    17,     3,     3,    41,
-     160,    41,    44,     3,    44,    44,     3,    28,    50,    53,
-      84,   123,    86,    34,   122,   128,    90,   127,    92,     3,
-      84,    83,    86,     3,    45,    46,    53,   137,   136,     3,
-      38,    38,    38,     3,    55,    97,    41,    44,    44,    44,
-      98,    41,     3,     3,    44,    50,    51,    52,   122,   123,
-      50,     3,     3,   127,   128,    44,   118,    41,   122,   123,
-      44,    41,   136,   137,    44,    47,   130,    49,    49,   131,
-      50,    38,   136,    50,    38,    40,    49,    53,    50,   141,
-       1,    38,   144,     4,     5,     6,     7,     8,     9,    10,
-      11,    12,   154,    38,    50,    16,    17,    18,    19,    20,
+      33,    46,    85,    48,    49,     3,     0,    91,     0,     1,
+      53,    46,     4,     5,     6,     7,     8,     9,    10,    11,
+      12,     3,    55,    87,    16,    17,     3,    42,    39,    50,
+      45,    93,   154,     3,    45,     3,    51,    29,    45,   161,
+      85,   124,    87,    35,    42,   129,    91,    45,    93,     3,
+      85,    84,    87,    51,    46,    47,    99,    54,    42,   123,
+      42,    45,    39,    45,    56,    98,   128,    54,    45,    51,
+      52,    53,    42,   137,    42,    45,   138,    45,   123,   124,
+       3,    51,    39,   128,   129,    48,   119,    50,   123,   124,
+       3,     3,   137,   138,     3,     3,   131,     3,    45,   132,
+      39,    51,   137,    39,    50,    50,    41,    39,    39,   142,
+       1,    51,   145,     4,     5,     6,     7,     8,     9,    10,
+      11,    12,   155,    51,    54,    16,    17,    18,    19,    20,
       21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
-      31,    32,    33,    34,    35,    36,    37,    42,    38,     3,
-      53,    50,    53,    53,    38,    46,     2,    48,    49,    48,
-     118,    94,     1,    54,    55,     4,     5,     6,     7,     8,
-       9,    10,    11,    12,     3,    -1,   142,    16,    17,    76,
-      -1,    -1,    -1,    -1,    13,    14,    15,    -1,    -1,    28,
-      -1,    20,    21,    -1,    -1,    34,    -1,    -1,    -1,    -1,
-      -1,    -1,    -1,    -1,    -1,    -1,    45,    -1,    -1,    38,
-      39,    -1,    41,    -1,    -1,    44,    55,    -1,    -1,    -1,
-      -1,    50,    -1,    -1,    -1,    -1,    -1,    56
+      31,    32,    33,    34,    35,    36,    37,    38,    43,    39,
+       3,    54,    51,    54,    54,    39,    47,     2,    49,    50,
+     119,    49,    95,     1,    55,    56,     4,     5,     6,     7,
+       8,     9,    10,    11,    12,     3,   143,    -1,    16,    17,
+      77,    -1,    -1,    -1,    -1,    13,    14,    15,    -1,    -1,
+      -1,    29,    -1,    21,    22,    -1,    -1,    35,    -1,    -1,
+      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,    -1,
+      -1,    39,    40,    -1,    42,    -1,    -1,    45,    56,    -1,
+      -1,    -1,    -1,    51,    -1,    -1,    -1,    -1,    -1,    57
 };
 
   /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
      symbol of state STATE-NUM.  */
 static const yytype_uint8 yystos[] =
 {
-       0,    58,    59,     0,     1,     4,     5,     6,     7,     8,
+       0,    59,    60,     0,     1,     4,     5,     6,     7,     8,
        9,    10,    11,    12,    16,    17,    18,    19,    20,    21,
       22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
-      32,    33,    34,    35,    36,    37,    46,    48,    49,    54,
-      55,    60,    63,    64,    66,    69,    49,    68,    67,     3,
-      41,    44,    50,    82,    83,    93,    95,    96,    38,    44,
-      44,    91,     3,    53,    53,     3,    38,     3,     3,     3,
-       3,     3,    95,     1,    45,    63,    84,    85,    86,    94,
-      61,    44,    65,    38,    50,    79,    80,    81,    93,    96,
-      50,    75,    76,    77,    93,    74,    75,    83,    50,    95,
-      38,     3,    38,    44,    92,    49,    49,    46,    85,    98,
-      40,    90,    38,    62,    38,    50,    51,    52,    71,    72,
-      73,    95,    80,    50,    81,    53,    78,    76,    50,    77,
-      78,    83,    42,    87,    38,    72,    80,    76,    96,    97,
-      88,    89,    47,    49,    13,    14,    15,    20,    21,    39,
-      50,    56,    70,    95,    89,    95,    53,    50,    53,    53,
-      38,    90,    90
+      32,    33,    34,    35,    36,    37,    38,    47,    49,    50,
+      55,    56,    61,    64,    65,    67,    70,    50,    69,    68,
+       3,    42,    45,    51,    83,    84,    94,    96,    97,    39,
+      45,    45,    92,     3,    54,    54,     3,    39,     3,     3,
+       3,     3,     3,    96,     1,    46,    64,    85,    86,    87,
+      95,    62,    45,    66,    39,    51,    80,    81,    82,    94,
+      97,    51,    76,    77,    78,    94,    75,    76,    84,    51,
+      96,    39,     3,    39,    45,    93,    50,    50,    47,    86,
+      99,    41,    91,    39,    63,    39,    51,    52,    53,    72,
+      73,    74,    96,    81,    51,    82,    54,    79,    77,    51,
+      78,    79,    84,    43,    88,    39,    73,    81,    77,    97,
+      98,    89,    90,    48,    50,    13,    14,    15,    21,    22,
+      40,    51,    57,    71,    96,    90,    96,    54,    51,    54,
+      54,    39,    91,    91
 };
 
   /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
 static const yytype_uint8 yyr1[] =
 {
-       0,    57,    58,    59,    59,    60,    60,    60,    60,    60,
-      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
-      60,    61,    60,    60,    60,    60,    60,    60,    60,    60,
-      62,    62,    63,    63,    63,    63,    63,    63,    63,    64,
-      64,    65,    65,    63,    67,    66,    68,    66,    66,    66,
-      69,    69,    69,    69,    70,    70,    71,    71,    72,    72,
-      73,    73,    73,    74,    75,    75,    75,    76,    76,    77,
-      78,    78,    79,    79,    79,    80,    80,    81,    81,    82,
-      82,    82,    83,    83,    84,    84,    85,    85,    85,    87,
-      86,    88,    88,    88,    89,    89,    89,    89,    89,    89,
-      89,    89,    89,    89,    90,    90,    91,    92,    92,    92,
-      92,    93,    93,    94,    95,    95,    96,    97,    97,    98,
-      98
+       0,    58,    59,    60,    60,    61,    61,    61,    61,    61,
+      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
+      61,    61,    62,    61,    61,    61,    61,    61,    61,    61,
+      61,    63,    63,    64,    64,    64,    64,    64,    64,    64,
+      65,    65,    66,    66,    64,    68,    67,    69,    67,    67,
+      67,    70,    70,    70,    70,    71,    71,    72,    72,    73,
+      73,    74,    74,    74,    75,    76,    76,    76,    77,    77,
+      78,    79,    79,    80,    80,    80,    81,    81,    82,    82,
+      83,    83,    83,    84,    84,    85,    85,    86,    86,    86,
+      88,    87,    89,    89,    89,    90,    90,    90,    90,    90,
+      90,    90,    90,    90,    90,    91,    91,    92,    93,    93,
+      93,    93,    94,    94,    95,    96,    96,    97,    98,    98,
+      99,    99
 };
 
   /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
 static const yytype_uint8 yyr2[] =
 {
        0,     2,     4,     0,     2,     1,     1,     1,     3,     1,
-       2,     2,     2,     2,     1,     2,     2,     2,     1,     1,
-       2,     0,     3,     2,     2,     1,     1,     1,     2,     1,
-       2,     1,     1,     2,     3,     1,     1,     2,     3,     1,
-       1,     0,     1,     3,     0,     3,     0,     3,     2,     2,
-       1,     1,     1,     1,     0,     1,     1,     2,     1,     1,
-       1,     1,     1,     1,     1,     2,     3,     1,     2,     3,
-       0,     1,     1,     2,     3,     1,     2,     2,     1,     1,
-       2,     3,     1,     2,     1,     2,     1,     2,     2,     0,
-       4,     1,     3,     2,     0,     3,     4,     2,     2,     3,
-       3,     3,     3,     3,     0,     1,     1,     0,     1,     1,
-       1,     1,     1,     1,     1,     1,     1,     0,     1,     0,
-       2
+       2,     1,     2,     2,     2,     1,     2,     2,     2,     1,
+       1,     2,     0,     3,     2,     2,     1,     1,     1,     2,
+       1,     2,     1,     1,     2,     3,     1,     1,     2,     3,
+       1,     1,     0,     1,     3,     0,     3,     0,     3,     2,
+       2,     1,     1,     1,     1,     0,     1,     1,     2,     1,
+       1,     1,     1,     1,     1,     1,     2,     3,     1,     2,
+       3,     0,     1,     1,     2,     3,     1,     2,     2,     1,
+       1,     2,     3,     1,     2,     1,     2,     1,     2,     2,
+       0,     4,     1,     3,     2,     0,     3,     4,     2,     2,
+       3,     3,     3,     3,     3,     0,     1,     1,     0,     1,
+       1,     1,     1,     1,     1,     1,     1,     1,     0,     1,
+       0,     2
 };
 
 
@@ -1083,85 +1090,91 @@ yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YY
   switch (yytype)
     {
     case 3: /* "string"  */
-#line 195 "src/parse-gram.y" /* yacc.c:680  */
+#line 199 "src/parse-gram.y" /* yacc.c:680  */
       { fputs (quotearg_style (c_quoting_style, ((*yyvaluep).STRING)), yyo); }
-#line 1089 "src/parse-gram.c" /* yacc.c:680  */
+#line 1096 "src/parse-gram.c" /* yacc.c:680  */
+        break;
+
+    case 20: /* "%error-verbose"  */
+#line 206 "src/parse-gram.y" /* yacc.c:680  */
+      { fputs (((*yyvaluep).PERCENT_ERROR_VERBOSE), yyo); }
+#line 1102 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
-    case 22: /* "%<flag>"  */
-#line 204 "src/parse-gram.y" /* yacc.c:680  */
+    case 23: /* "%<flag>"  */
+#line 209 "src/parse-gram.y" /* yacc.c:680  */
       { fprintf (yyo, "%%%s", ((*yyvaluep).PERCENT_FLAG)); }
-#line 1095 "src/parse-gram.c" /* yacc.c:680  */
+#line 1108 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
-    case 27: /* "%name-prefix"  */
-#line 201 "src/parse-gram.y" /* yacc.c:680  */
+    case 28: /* "%name-prefix"  */
+#line 206 "src/parse-gram.y" /* yacc.c:680  */
       { fputs (((*yyvaluep).PERCENT_NAME_PREFIX), yyo); }
-#line 1101 "src/parse-gram.c" /* yacc.c:680  */
+#line 1114 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
-    case 38: /* "{...}"  */
-#line 196 "src/parse-gram.y" /* yacc.c:680  */
+    case 39: /* "{...}"  */
+#line 200 "src/parse-gram.y" /* yacc.c:680  */
       { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).BRACED_CODE)); }
-#line 1107 "src/parse-gram.c" /* yacc.c:680  */
+#line 1120 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
-    case 39: /* "%?{...}"  */
-#line 196 "src/parse-gram.y" /* yacc.c:680  */
+    case 40: /* "%?{...}"  */
+#line 200 "src/parse-gram.y" /* yacc.c:680  */
       { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).BRACED_PREDICATE)); }
-#line 1113 "src/parse-gram.c" /* yacc.c:680  */
+#line 1126 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
-    case 40: /* "[identifier]"  */
-#line 202 "src/parse-gram.y" /* yacc.c:680  */
+    case 41: /* "[identifier]"  */
+#line 207 "src/parse-gram.y" /* yacc.c:680  */
       { fprintf (yyo, "[%s]", ((*yyvaluep).BRACKETED_ID)); }
-#line 1119 "src/parse-gram.c" /* yacc.c:680  */
+#line 1132 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
-    case 41: /* "char"  */
-#line 192 "src/parse-gram.y" /* yacc.c:680  */
+    case 42: /* "char"  */
+#line 196 "src/parse-gram.y" /* yacc.c:680  */
       { fputs (char_name (((*yyvaluep).CHAR)), yyo); }
-#line 1125 "src/parse-gram.c" /* yacc.c:680  */
+#line 1138 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
-    case 42: /* "epilogue"  */
-#line 196 "src/parse-gram.y" /* yacc.c:680  */
+    case 43: /* "epilogue"  */
+#line 200 "src/parse-gram.y" /* yacc.c:680  */
       { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).EPILOGUE)); }
-#line 1131 "src/parse-gram.c" /* yacc.c:680  */
+#line 1144 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
-    case 44: /* "identifier"  */
-#line 201 "src/parse-gram.y" /* yacc.c:680  */
+    case 45: /* "identifier"  */
+#line 206 "src/parse-gram.y" /* yacc.c:680  */
       { fputs (((*yyvaluep).ID), yyo); }
-#line 1137 "src/parse-gram.c" /* yacc.c:680  */
+#line 1150 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
-    case 45: /* "identifier:"  */
-#line 203 "src/parse-gram.y" /* yacc.c:680  */
+    case 46: /* "identifier:"  */
+#line 208 "src/parse-gram.y" /* yacc.c:680  */
       { fprintf (yyo, "%s:", ((*yyvaluep).ID_COLON)); }
-#line 1143 "src/parse-gram.c" /* yacc.c:680  */
+#line 1156 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
-    case 48: /* "%{...%}"  */
-#line 196 "src/parse-gram.y" /* yacc.c:680  */
+    case 49: /* "%{...%}"  */
+#line 200 "src/parse-gram.y" /* yacc.c:680  */
       { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).PROLOGUE)); }
-#line 1149 "src/parse-gram.c" /* yacc.c:680  */
+#line 1162 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
-    case 50: /* "<tag>"  */
-#line 205 "src/parse-gram.y" /* yacc.c:680  */
+    case 51: /* "<tag>"  */
+#line 210 "src/parse-gram.y" /* yacc.c:680  */
       { fprintf (yyo, "<%s>", ((*yyvaluep).TAG)); }
-#line 1155 "src/parse-gram.c" /* yacc.c:680  */
+#line 1168 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
-    case 53: /* "integer"  */
-#line 208 "src/parse-gram.y" /* yacc.c:680  */
+    case 54: /* "integer"  */
+#line 213 "src/parse-gram.y" /* yacc.c:680  */
       { fprintf (yyo, "%d", ((*yyvaluep).INT)); }
-#line 1161 "src/parse-gram.c" /* yacc.c:680  */
+#line 1174 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
-    case 54: /* "%param"  */
-#line 247 "src/parse-gram.y" /* yacc.c:680  */
+    case 55: /* "%param"  */
+#line 252 "src/parse-gram.y" /* yacc.c:680  */
       {
   switch (((*yyvaluep).PERCENT_PARAM))
     {
@@ -1174,107 +1187,107 @@ yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YY
       case param_none: aver (false); break;
     }
 }
-#line 1178 "src/parse-gram.c" /* yacc.c:680  */
+#line 1191 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
-    case 64: /* code_props_type  */
-#line 382 "src/parse-gram.y" /* yacc.c:680  */
+    case 65: /* code_props_type  */
+#line 388 "src/parse-gram.y" /* yacc.c:680  */
       { fprintf (yyo, "%s", code_props_type_string (((*yyvaluep).code_props_type))); }
-#line 1184 "src/parse-gram.c" /* yacc.c:680  */
+#line 1197 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
-    case 70: /* tag.opt  */
-#line 201 "src/parse-gram.y" /* yacc.c:680  */
-      { fputs (((*yyvaluep).yytype_70), yyo); }
-#line 1190 "src/parse-gram.c" /* yacc.c:680  */
+    case 71: /* tag.opt  */
+#line 206 "src/parse-gram.y" /* yacc.c:680  */
+      { fputs (((*yyvaluep).yytype_71), yyo); }
+#line 1203 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
-    case 71: /* generic_symlist  */
-#line 217 "src/parse-gram.y" /* yacc.c:680  */
+    case 72: /* generic_symlist  */
+#line 222 "src/parse-gram.y" /* yacc.c:680  */
       { symbol_list_syms_print (((*yyvaluep).generic_symlist), yyo); }
-#line 1196 "src/parse-gram.c" /* yacc.c:680  */
+#line 1209 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
-    case 72: /* generic_symlist_item  */
-#line 217 "src/parse-gram.y" /* yacc.c:680  */
+    case 73: /* generic_symlist_item  */
+#line 222 "src/parse-gram.y" /* yacc.c:680  */
       { symbol_list_syms_print (((*yyvaluep).generic_symlist_item), yyo); }
-#line 1202 "src/parse-gram.c" /* yacc.c:680  */
+#line 1215 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
-    case 73: /* tag  */
-#line 205 "src/parse-gram.y" /* yacc.c:680  */
+    case 74: /* tag  */
+#line 210 "src/parse-gram.y" /* yacc.c:680  */
       { fprintf (yyo, "<%s>", ((*yyvaluep).tag)); }
-#line 1208 "src/parse-gram.c" /* yacc.c:680  */
+#line 1221 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
-    case 74: /* nterm_decls  */
-#line 217 "src/parse-gram.y" /* yacc.c:680  */
+    case 75: /* nterm_decls  */
+#line 222 "src/parse-gram.y" /* yacc.c:680  */
       { symbol_list_syms_print (((*yyvaluep).nterm_decls), yyo); }
-#line 1214 "src/parse-gram.c" /* yacc.c:680  */
+#line 1227 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
-    case 75: /* token_decls  */
-#line 217 "src/parse-gram.y" /* yacc.c:680  */
+    case 76: /* token_decls  */
+#line 222 "src/parse-gram.y" /* yacc.c:680  */
       { symbol_list_syms_print (((*yyvaluep).token_decls), yyo); }
-#line 1220 "src/parse-gram.c" /* yacc.c:680  */
+#line 1233 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
-    case 76: /* token_decl.1  */
-#line 217 "src/parse-gram.y" /* yacc.c:680  */
-      { symbol_list_syms_print (((*yyvaluep).yytype_76), yyo); }
-#line 1226 "src/parse-gram.c" /* yacc.c:680  */
+    case 77: /* token_decl.1  */
+#line 222 "src/parse-gram.y" /* yacc.c:680  */
+      { symbol_list_syms_print (((*yyvaluep).yytype_77), yyo); }
+#line 1239 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
-    case 77: /* token_decl  */
-#line 211 "src/parse-gram.y" /* yacc.c:680  */
+    case 78: /* token_decl  */
+#line 216 "src/parse-gram.y" /* yacc.c:680  */
       { fprintf (yyo, "%s", ((*yyvaluep).token_decl) ? ((*yyvaluep).token_decl)->tag : "<NULL>"); }
-#line 1232 "src/parse-gram.c" /* yacc.c:680  */
+#line 1245 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
-    case 78: /* int.opt  */
-#line 208 "src/parse-gram.y" /* yacc.c:680  */
-      { fprintf (yyo, "%d", ((*yyvaluep).yytype_78)); }
-#line 1238 "src/parse-gram.c" /* yacc.c:680  */
+    case 79: /* int.opt  */
+#line 213 "src/parse-gram.y" /* yacc.c:680  */
+      { fprintf (yyo, "%d", ((*yyvaluep).yytype_79)); }
+#line 1251 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
-    case 79: /* token_decls_for_prec  */
-#line 217 "src/parse-gram.y" /* yacc.c:680  */
+    case 80: /* token_decls_for_prec  */
+#line 222 "src/parse-gram.y" /* yacc.c:680  */
       { symbol_list_syms_print (((*yyvaluep).token_decls_for_prec), yyo); }
-#line 1244 "src/parse-gram.c" /* yacc.c:680  */
+#line 1257 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
-    case 80: /* token_decl_for_prec.1  */
-#line 217 "src/parse-gram.y" /* yacc.c:680  */
-      { symbol_list_syms_print (((*yyvaluep).yytype_80), yyo); }
-#line 1250 "src/parse-gram.c" /* yacc.c:680  */
+    case 81: /* token_decl_for_prec.1  */
+#line 222 "src/parse-gram.y" /* yacc.c:680  */
+      { symbol_list_syms_print (((*yyvaluep).yytype_81), yyo); }
+#line 1263 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
-    case 81: /* token_decl_for_prec  */
-#line 211 "src/parse-gram.y" /* yacc.c:680  */
+    case 82: /* token_decl_for_prec  */
+#line 216 "src/parse-gram.y" /* yacc.c:680  */
       { fprintf (yyo, "%s", ((*yyvaluep).token_decl_for_prec) ? ((*yyvaluep).token_decl_for_prec)->tag : "<NULL>"); }
-#line 1256 "src/parse-gram.c" /* yacc.c:680  */
+#line 1269 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
-    case 82: /* symbol_decls  */
-#line 217 "src/parse-gram.y" /* yacc.c:680  */
+    case 83: /* symbol_decls  */
+#line 222 "src/parse-gram.y" /* yacc.c:680  */
       { symbol_list_syms_print (((*yyvaluep).symbol_decls), yyo); }
-#line 1262 "src/parse-gram.c" /* yacc.c:680  */
+#line 1275 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
-    case 83: /* symbol_decl.1  */
-#line 217 "src/parse-gram.y" /* yacc.c:680  */
-      { symbol_list_syms_print (((*yyvaluep).yytype_83), yyo); }
-#line 1268 "src/parse-gram.c" /* yacc.c:680  */
+    case 84: /* symbol_decl.1  */
+#line 222 "src/parse-gram.y" /* yacc.c:680  */
+      { symbol_list_syms_print (((*yyvaluep).yytype_84), yyo); }
+#line 1281 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
-    case 91: /* variable  */
-#line 201 "src/parse-gram.y" /* yacc.c:680  */
+    case 92: /* variable  */
+#line 206 "src/parse-gram.y" /* yacc.c:680  */
       { fputs (((*yyvaluep).variable), yyo); }
-#line 1274 "src/parse-gram.c" /* yacc.c:680  */
+#line 1287 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
-    case 92: /* value  */
-#line 677 "src/parse-gram.y" /* yacc.c:680  */
+    case 93: /* value  */
+#line 683 "src/parse-gram.y" /* yacc.c:680  */
       {
   switch (((*yyvaluep).value).kind)
     {
@@ -1283,37 +1296,37 @@ yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YY
     case muscle_string:  fprintf (yyo, "\"%s\"", ((*yyvaluep).value).chars); break;
     }
 }
-#line 1287 "src/parse-gram.c" /* yacc.c:680  */
+#line 1300 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
-    case 93: /* id  */
-#line 211 "src/parse-gram.y" /* yacc.c:680  */
+    case 94: /* id  */
+#line 216 "src/parse-gram.y" /* yacc.c:680  */
       { fprintf (yyo, "%s", ((*yyvaluep).id) ? ((*yyvaluep).id)->tag : "<NULL>"); }
-#line 1293 "src/parse-gram.c" /* yacc.c:680  */
+#line 1306 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
-    case 94: /* id_colon  */
-#line 212 "src/parse-gram.y" /* yacc.c:680  */
+    case 95: /* id_colon  */
+#line 217 "src/parse-gram.y" /* yacc.c:680  */
       { fprintf (yyo, "%s:", ((*yyvaluep).id_colon)->tag); }
-#line 1299 "src/parse-gram.c" /* yacc.c:680  */
+#line 1312 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
-    case 95: /* symbol  */
-#line 211 "src/parse-gram.y" /* yacc.c:680  */
+    case 96: /* symbol  */
+#line 216 "src/parse-gram.y" /* yacc.c:680  */
       { fprintf (yyo, "%s", ((*yyvaluep).symbol) ? ((*yyvaluep).symbol)->tag : "<NULL>"); }
-#line 1305 "src/parse-gram.c" /* yacc.c:680  */
+#line 1318 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
-    case 96: /* string_as_id  */
-#line 211 "src/parse-gram.y" /* yacc.c:680  */
+    case 97: /* string_as_id  */
+#line 216 "src/parse-gram.y" /* yacc.c:680  */
       { fprintf (yyo, "%s", ((*yyvaluep).string_as_id) ? ((*yyvaluep).string_as_id)->tag : "<NULL>"); }
-#line 1311 "src/parse-gram.c" /* yacc.c:680  */
+#line 1324 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
-    case 97: /* string_as_id.opt  */
-#line 211 "src/parse-gram.y" /* yacc.c:680  */
-      { fprintf (yyo, "%s", ((*yyvaluep).yytype_97) ? ((*yyvaluep).yytype_97)->tag : "<NULL>"); }
-#line 1317 "src/parse-gram.c" /* yacc.c:680  */
+    case 98: /* string_as_id.opt  */
+#line 216 "src/parse-gram.y" /* yacc.c:680  */
+      { fprintf (yyo, "%s", ((*yyvaluep).yytype_98) ? ((*yyvaluep).yytype_98)->tag : "<NULL>"); }
+#line 1330 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
       default:
@@ -1897,58 +1910,58 @@ yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocatio
   YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
   switch (yytype)
     {
-    case 71: /* generic_symlist  */
-#line 216 "src/parse-gram.y" /* yacc.c:1254  */
+    case 72: /* generic_symlist  */
+#line 221 "src/parse-gram.y" /* yacc.c:1254  */
       { symbol_list_free (((*yyvaluep).generic_symlist)); }
-#line 1904 "src/parse-gram.c" /* yacc.c:1254  */
+#line 1917 "src/parse-gram.c" /* yacc.c:1254  */
         break;
 
-    case 72: /* generic_symlist_item  */
-#line 216 "src/parse-gram.y" /* yacc.c:1254  */
+    case 73: /* generic_symlist_item  */
+#line 221 "src/parse-gram.y" /* yacc.c:1254  */
       { symbol_list_free (((*yyvaluep).generic_symlist_item)); }
-#line 1910 "src/parse-gram.c" /* yacc.c:1254  */
+#line 1923 "src/parse-gram.c" /* yacc.c:1254  */
         break;
 
-    case 74: /* nterm_decls  */
-#line 216 "src/parse-gram.y" /* yacc.c:1254  */
+    case 75: /* nterm_decls  */
+#line 221 "src/parse-gram.y" /* yacc.c:1254  */
       { symbol_list_free (((*yyvaluep).nterm_decls)); }
-#line 1916 "src/parse-gram.c" /* yacc.c:1254  */
+#line 1929 "src/parse-gram.c" /* yacc.c:1254  */
         break;
 
-    case 75: /* token_decls  */
-#line 216 "src/parse-gram.y" /* yacc.c:1254  */
+    case 76: /* token_decls  */
+#line 221 "src/parse-gram.y" /* yacc.c:1254  */
       { symbol_list_free (((*yyvaluep).token_decls)); }
-#line 1922 "src/parse-gram.c" /* yacc.c:1254  */
+#line 1935 "src/parse-gram.c" /* yacc.c:1254  */
         break;
 
-    case 76: /* token_decl.1  */
-#line 216 "src/parse-gram.y" /* yacc.c:1254  */
-      { symbol_list_free (((*yyvaluep).yytype_76)); }
-#line 1928 "src/parse-gram.c" /* yacc.c:1254  */
+    case 77: /* token_decl.1  */
+#line 221 "src/parse-gram.y" /* yacc.c:1254  */
+      { symbol_list_free (((*yyvaluep).yytype_77)); }
+#line 1941 "src/parse-gram.c" /* yacc.c:1254  */
         break;
 
-    case 79: /* token_decls_for_prec  */
-#line 216 "src/parse-gram.y" /* yacc.c:1254  */
+    case 80: /* token_decls_for_prec  */
+#line 221 "src/parse-gram.y" /* yacc.c:1254  */
       { symbol_list_free (((*yyvaluep).token_decls_for_prec)); }
-#line 1934 "src/parse-gram.c" /* yacc.c:1254  */
+#line 1947 "src/parse-gram.c" /* yacc.c:1254  */
         break;
 
-    case 80: /* token_decl_for_prec.1  */
-#line 216 "src/parse-gram.y" /* yacc.c:1254  */
-      { symbol_list_free (((*yyvaluep).yytype_80)); }
-#line 1940 "src/parse-gram.c" /* yacc.c:1254  */
+    case 81: /* token_decl_for_prec.1  */
+#line 221 "src/parse-gram.y" /* yacc.c:1254  */
+      { symbol_list_free (((*yyvaluep).yytype_81)); }
+#line 1953 "src/parse-gram.c" /* yacc.c:1254  */
         break;
 
-    case 82: /* symbol_decls  */
-#line 216 "src/parse-gram.y" /* yacc.c:1254  */
+    case 83: /* symbol_decls  */
+#line 221 "src/parse-gram.y" /* yacc.c:1254  */
       { symbol_list_free (((*yyvaluep).symbol_decls)); }
-#line 1946 "src/parse-gram.c" /* yacc.c:1254  */
+#line 1959 "src/parse-gram.c" /* yacc.c:1254  */
         break;
 
-    case 83: /* symbol_decl.1  */
-#line 216 "src/parse-gram.y" /* yacc.c:1254  */
-      { symbol_list_free (((*yyvaluep).yytype_83)); }
-#line 1952 "src/parse-gram.c" /* yacc.c:1254  */
+    case 84: /* symbol_decl.1  */
+#line 221 "src/parse-gram.y" /* yacc.c:1254  */
+      { symbol_list_free (((*yyvaluep).yytype_84)); }
+#line 1965 "src/parse-gram.c" /* yacc.c:1254  */
         break;
 
       default:
@@ -2065,7 +2078,7 @@ YYLTYPE yylloc = yyloc_default;
   yychar = YYEMPTY; /* Cause a token to be read.  */
 
 /* User initialization code.  */
-#line 118 "src/parse-gram.y" /* yacc.c:1428  */
+#line 121 "src/parse-gram.y" /* yacc.c:1428  */
 {
   /* Bison's grammar can initial empty locations, hence a default
      location is needed. */
@@ -2073,7 +2086,7 @@ YYLTYPE yylloc = yyloc_default;
   boundary_set (&yylloc.end, current_file, 1, 1);
 }
 
-#line 2077 "src/parse-gram.c" /* yacc.c:1428  */
+#line 2090 "src/parse-gram.c" /* yacc.c:1428  */
   yylsp[0] = yylloc;
   goto yysetstate;
 
@@ -2272,183 +2285,189 @@ yyreduce:
     switch (yyn)
       {
   case 6:
-#line 283 "src/parse-gram.y" /* yacc.c:1649  */
+#line 288 "src/parse-gram.y" /* yacc.c:1649  */
     {
       muscle_code_grow (union_seen ? "post_prologue" : "pre_prologue",
                         translate_code ((yyvsp[0].PROLOGUE), (yylsp[0]), true), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2282 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2295 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 7:
-#line 289 "src/parse-gram.y" /* yacc.c:1649  */
+#line 294 "src/parse-gram.y" /* yacc.c:1649  */
     {
       muscle_percent_define_ensure ((yyvsp[0].PERCENT_FLAG), (yylsp[0]), true);
     }
-#line 2290 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2303 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 8:
-#line 293 "src/parse-gram.y" /* yacc.c:1649  */
+#line 298 "src/parse-gram.y" /* yacc.c:1649  */
     {
       muscle_percent_define_insert ((yyvsp[-1].variable), (yyloc), (yyvsp[0].value).kind, (yyvsp[0].value).chars,
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
     }
-#line 2299 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2312 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 9:
-#line 297 "src/parse-gram.y" /* yacc.c:1649  */
+#line 302 "src/parse-gram.y" /* yacc.c:1649  */
     { defines_flag = true; }
-#line 2305 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2318 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 10:
-#line 299 "src/parse-gram.y" /* yacc.c:1649  */
+#line 304 "src/parse-gram.y" /* yacc.c:1649  */
     {
       defines_flag = true;
       spec_defines_file = xstrdup ((yyvsp[0].STRING));
     }
-#line 2314 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2327 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 11:
-#line 303 "src/parse-gram.y" /* yacc.c:1649  */
-    { expected_sr_conflicts = (yyvsp[0].INT); }
-#line 2320 "src/parse-gram.c" /* yacc.c:1649  */
+#line 308 "src/parse-gram.y" /* yacc.c:1649  */
+    { do_error_verbose (&(yyloc), (yyvsp[0].PERCENT_ERROR_VERBOSE)); }
+#line 2333 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 12:
-#line 304 "src/parse-gram.y" /* yacc.c:1649  */
-    { expected_rr_conflicts = (yyvsp[0].INT); }
-#line 2326 "src/parse-gram.c" /* yacc.c:1649  */
+#line 309 "src/parse-gram.y" /* yacc.c:1649  */
+    { expected_sr_conflicts = (yyvsp[0].INT); }
+#line 2339 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 13:
-#line 305 "src/parse-gram.y" /* yacc.c:1649  */
-    { spec_file_prefix = (yyvsp[0].STRING); }
-#line 2332 "src/parse-gram.c" /* yacc.c:1649  */
+#line 310 "src/parse-gram.y" /* yacc.c:1649  */
+    { expected_rr_conflicts = (yyvsp[0].INT); }
+#line 2345 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 14:
-#line 307 "src/parse-gram.y" /* yacc.c:1649  */
+#line 311 "src/parse-gram.y" /* yacc.c:1649  */
+    { spec_file_prefix = (yyvsp[0].STRING); }
+#line 2351 "src/parse-gram.c" /* yacc.c:1649  */
+    break;
+
+  case 15:
+#line 313 "src/parse-gram.y" /* yacc.c:1649  */
     {
       nondeterministic_parser = true;
       glr_parser = true;
     }
-#line 2341 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2360 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
-  case 15:
-#line 312 "src/parse-gram.y" /* yacc.c:1649  */
+  case 16:
+#line 318 "src/parse-gram.y" /* yacc.c:1649  */
     {
       muscle_code_grow ("initial_action", translate_code ((yyvsp[0].BRACED_CODE), (yylsp[0]), false), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2350 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2369 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
-  case 16:
-#line 316 "src/parse-gram.y" /* yacc.c:1649  */
+  case 17:
+#line 322 "src/parse-gram.y" /* yacc.c:1649  */
     { language_argmatch ((yyvsp[0].STRING), grammar_prio, (yylsp[-1])); }
-#line 2356 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2375 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
-  case 17:
-#line 317 "src/parse-gram.y" /* yacc.c:1649  */
+  case 18:
+#line 323 "src/parse-gram.y" /* yacc.c:1649  */
     { do_name_prefix (&(yyloc), (yyvsp[-1].PERCENT_NAME_PREFIX), (yyvsp[0].STRING)); }
-#line 2362 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2381 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
-  case 18:
-#line 318 "src/parse-gram.y" /* yacc.c:1649  */
+  case 19:
+#line 324 "src/parse-gram.y" /* yacc.c:1649  */
     { no_lines_flag = true; }
-#line 2368 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2387 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
-  case 19:
-#line 319 "src/parse-gram.y" /* yacc.c:1649  */
+  case 20:
+#line 325 "src/parse-gram.y" /* yacc.c:1649  */
     { nondeterministic_parser = true; }
-#line 2374 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2393 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
-  case 20:
-#line 320 "src/parse-gram.y" /* yacc.c:1649  */
+  case 21:
+#line 326 "src/parse-gram.y" /* yacc.c:1649  */
     { spec_outfile = (yyvsp[0].STRING); }
-#line 2380 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2399 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
-  case 21:
-#line 321 "src/parse-gram.y" /* yacc.c:1649  */
+  case 22:
+#line 327 "src/parse-gram.y" /* yacc.c:1649  */
     { current_param = (yyvsp[0].PERCENT_PARAM); }
-#line 2386 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2405 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
-  case 22:
-#line 321 "src/parse-gram.y" /* yacc.c:1649  */
+  case 23:
+#line 327 "src/parse-gram.y" /* yacc.c:1649  */
     { current_param = param_none; }
-#line 2392 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2411 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
-  case 23:
-#line 322 "src/parse-gram.y" /* yacc.c:1649  */
+  case 24:
+#line 328 "src/parse-gram.y" /* yacc.c:1649  */
     { do_require (&(yylsp[0]), (yyvsp[0].STRING)); }
-#line 2398 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2417 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
-  case 24:
-#line 323 "src/parse-gram.y" /* yacc.c:1649  */
+  case 25:
+#line 329 "src/parse-gram.y" /* yacc.c:1649  */
     { do_skeleton (&(yylsp[0]), (yyvsp[0].STRING)); }
-#line 2404 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2423 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
-  case 25:
-#line 324 "src/parse-gram.y" /* yacc.c:1649  */
+  case 26:
+#line 330 "src/parse-gram.y" /* yacc.c:1649  */
     { token_table_flag = true; }
-#line 2410 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2429 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
-  case 26:
-#line 325 "src/parse-gram.y" /* yacc.c:1649  */
+  case 27:
+#line 331 "src/parse-gram.y" /* yacc.c:1649  */
     { report_flag |= report_states; }
-#line 2416 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2435 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
-  case 27:
-#line 326 "src/parse-gram.y" /* yacc.c:1649  */
+  case 28:
+#line 332 "src/parse-gram.y" /* yacc.c:1649  */
     { yacc_flag = true; }
-#line 2422 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2441 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
-  case 28:
-#line 327 "src/parse-gram.y" /* yacc.c:1649  */
+  case 29:
+#line 333 "src/parse-gram.y" /* yacc.c:1649  */
     { current_class = unknown_sym; yyerrok; }
-#line 2428 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2447 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
-  case 30:
-#line 332 "src/parse-gram.y" /* yacc.c:1649  */
+  case 31:
+#line 338 "src/parse-gram.y" /* yacc.c:1649  */
     { add_param (current_param, (yyvsp[0].BRACED_CODE), (yylsp[0])); }
-#line 2434 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2453 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
-  case 31:
-#line 333 "src/parse-gram.y" /* yacc.c:1649  */
+  case 32:
+#line 339 "src/parse-gram.y" /* yacc.c:1649  */
     { add_param (current_param, (yyvsp[0].BRACED_CODE), (yylsp[0])); }
-#line 2440 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2459 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
-  case 33:
-#line 344 "src/parse-gram.y" /* yacc.c:1649  */
+  case 34:
+#line 350 "src/parse-gram.y" /* yacc.c:1649  */
     {
       grammar_start_symbol_set ((yyvsp[0].symbol), (yylsp[0]));
     }
-#line 2448 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2467 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
-  case 34:
-#line 348 "src/parse-gram.y" /* yacc.c:1649  */
+  case 35:
+#line 354 "src/parse-gram.y" /* yacc.c:1649  */
     {
       code_props code;
       code_props_symbol_action_init (&code, (yyvsp[-1].BRACED_CODE), (yylsp[-1]));
@@ -2459,27 +2478,27 @@ yyreduce:
         symbol_list_free ((yyvsp[0].generic_symlist));
       }
     }
-#line 2463 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2482 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
-  case 35:
-#line 359 "src/parse-gram.y" /* yacc.c:1649  */
+  case 36:
+#line 365 "src/parse-gram.y" /* yacc.c:1649  */
     {
       default_prec = true;
     }
-#line 2471 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2490 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
-  case 36:
-#line 363 "src/parse-gram.y" /* yacc.c:1649  */
+  case 37:
+#line 369 "src/parse-gram.y" /* yacc.c:1649  */
     {
       default_prec = false;
     }
-#line 2479 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2498 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
-  case 37:
-#line 367 "src/parse-gram.y" /* yacc.c:1649  */
+  case 38:
+#line 373 "src/parse-gram.y" /* yacc.c:1649  */
     {
       /* Do not invoke muscle_percent_code_grow here since it invokes
          muscle_user_name_list_grow.  */
@@ -2487,447 +2506,447 @@ yyreduce:
                         translate_code_braceless ((yyvsp[0].BRACED_CODE), (yylsp[0])), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2491 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2510 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
-  case 38:
-#line 375 "src/parse-gram.y" /* yacc.c:1649  */
+  case 39:
+#line 381 "src/parse-gram.y" /* yacc.c:1649  */
     {
       muscle_percent_code_grow ((yyvsp[-1].ID), (yylsp[-1]), translate_code_braceless ((yyvsp[0].BRACED_CODE), (yylsp[0])), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2500 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2519 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
-  case 39:
-#line 384 "src/parse-gram.y" /* yacc.c:1649  */
+  case 40:
+#line 390 "src/parse-gram.y" /* yacc.c:1649  */
     { (yyval.code_props_type) = destructor; }
-#line 2506 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2525 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
-  case 40:
-#line 385 "src/parse-gram.y" /* yacc.c:1649  */
+  case 41:
+#line 391 "src/parse-gram.y" /* yacc.c:1649  */
     { (yyval.code_props_type) = printer; }
-#line 2512 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2531 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
-  case 41:
-#line 395 "src/parse-gram.y" /* yacc.c:1649  */
+  case 42:
+#line 401 "src/parse-gram.y" /* yacc.c:1649  */
     {}
-#line 2518 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2537 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
-  case 42:
-#line 396 "src/parse-gram.y" /* yacc.c:1649  */
+  case 43:
+#line 402 "src/parse-gram.y" /* yacc.c:1649  */
     { muscle_percent_define_insert ("api.value.union.name",
                                          (yylsp[0]), muscle_keyword, (yyvsp[0].ID),
                                          MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE); }
-#line 2526 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2545 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
-  case 43:
-#line 403 "src/parse-gram.y" /* yacc.c:1649  */
+  case 44:
+#line 409 "src/parse-gram.y" /* yacc.c:1649  */
     {
       union_seen = true;
       muscle_code_grow ("union_members", translate_code_braceless ((yyvsp[0].BRACED_CODE), (yylsp[0])), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2536 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2555 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
-  case 44:
-#line 415 "src/parse-gram.y" /* yacc.c:1649  */
+  case 45:
+#line 421 "src/parse-gram.y" /* yacc.c:1649  */
     { current_class = nterm_sym; }
-#line 2542 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2561 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
-  case 45:
-#line 416 "src/parse-gram.y" /* yacc.c:1649  */
+  case 46:
+#line 422 "src/parse-gram.y" /* yacc.c:1649  */
     {
       current_class = unknown_sym;
       symbol_list_free ((yyvsp[0].nterm_decls));
     }
-#line 2551 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2570 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
-  case 46:
-#line 420 "src/parse-gram.y" /* yacc.c:1649  */
+  case 47:
+#line 426 "src/parse-gram.y" /* yacc.c:1649  */
     { current_class = token_sym; }
-#line 2557 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2576 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
-  case 47:
-#line 421 "src/parse-gram.y" /* yacc.c:1649  */
+  case 48:
+#line 427 "src/parse-gram.y" /* yacc.c:1649  */
     {
       current_class = unknown_sym;
       symbol_list_free ((yyvsp[0].token_decls));
     }
-#line 2566 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2585 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
-  case 48:
-#line 426 "src/parse-gram.y" /* yacc.c:1649  */
+  case 49:
+#line 432 "src/parse-gram.y" /* yacc.c:1649  */
     {
       symbol_list_free ((yyvsp[0].symbol_decls));
     }
-#line 2574 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2593 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
-  case 49:
-#line 430 "src/parse-gram.y" /* yacc.c:1649  */
+  case 50:
+#line 436 "src/parse-gram.y" /* yacc.c:1649  */
     {
       ++current_prec;
       for (symbol_list *list = (yyvsp[0].token_decls_for_prec); list; list = list->next)
         symbol_precedence_set (list->content.sym, current_prec, (yyvsp[-1].precedence_declarator), (yylsp[-1]));
       symbol_list_free ((yyvsp[0].token_decls_for_prec));
     }
-#line 2585 "src/parse-gram.c" /* yacc.c:1649  */
-    break;
-
-  case 50:
-#line 439 "src/parse-gram.y" /* yacc.c:1649  */
-    { (yyval.precedence_declarator) = left_assoc; }
-#line 2591 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2604 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 51:
-#line 440 "src/parse-gram.y" /* yacc.c:1649  */
-    { (yyval.precedence_declarator) = right_assoc; }
-#line 2597 "src/parse-gram.c" /* yacc.c:1649  */
+#line 445 "src/parse-gram.y" /* yacc.c:1649  */
+    { (yyval.precedence_declarator) = left_assoc; }
+#line 2610 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 52:
-#line 441 "src/parse-gram.y" /* yacc.c:1649  */
-    { (yyval.precedence_declarator) = non_assoc; }
-#line 2603 "src/parse-gram.c" /* yacc.c:1649  */
+#line 446 "src/parse-gram.y" /* yacc.c:1649  */
+    { (yyval.precedence_declarator) = right_assoc; }
+#line 2616 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 53:
-#line 442 "src/parse-gram.y" /* yacc.c:1649  */
-    { (yyval.precedence_declarator) = precedence_assoc; }
-#line 2609 "src/parse-gram.c" /* yacc.c:1649  */
+#line 447 "src/parse-gram.y" /* yacc.c:1649  */
+    { (yyval.precedence_declarator) = non_assoc; }
+#line 2622 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 54:
-#line 446 "src/parse-gram.y" /* yacc.c:1649  */
-    { (yyval.yytype_70) = NULL; }
-#line 2615 "src/parse-gram.c" /* yacc.c:1649  */
+#line 448 "src/parse-gram.y" /* yacc.c:1649  */
+    { (yyval.precedence_declarator) = precedence_assoc; }
+#line 2628 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 55:
-#line 447 "src/parse-gram.y" /* yacc.c:1649  */
-    { (yyval.yytype_70) = (yyvsp[0].TAG); }
-#line 2621 "src/parse-gram.c" /* yacc.c:1649  */
+#line 452 "src/parse-gram.y" /* yacc.c:1649  */
+    { (yyval.yytype_71) = NULL; }
+#line 2634 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
-  case 57:
+  case 56:
 #line 453 "src/parse-gram.y" /* yacc.c:1649  */
-    { (yyval.generic_symlist) = symbol_list_append ((yyvsp[-1].generic_symlist), (yyvsp[0].generic_symlist_item)); }
-#line 2627 "src/parse-gram.c" /* yacc.c:1649  */
+    { (yyval.yytype_71) = (yyvsp[0].TAG); }
+#line 2640 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 58:
-#line 457 "src/parse-gram.y" /* yacc.c:1649  */
-    { (yyval.generic_symlist_item) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-#line 2633 "src/parse-gram.c" /* yacc.c:1649  */
+#line 459 "src/parse-gram.y" /* yacc.c:1649  */
+    { (yyval.generic_symlist) = symbol_list_append ((yyvsp[-1].generic_symlist), (yyvsp[0].generic_symlist_item)); }
+#line 2646 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 59:
-#line 458 "src/parse-gram.y" /* yacc.c:1649  */
-    { (yyval.generic_symlist_item) = symbol_list_type_new ((yyvsp[0].tag), (yylsp[0])); }
-#line 2639 "src/parse-gram.c" /* yacc.c:1649  */
+#line 463 "src/parse-gram.y" /* yacc.c:1649  */
+    { (yyval.generic_symlist_item) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
+#line 2652 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
-  case 61:
-#line 463 "src/parse-gram.y" /* yacc.c:1649  */
-    { (yyval.tag) = uniqstr_new ("*"); }
-#line 2645 "src/parse-gram.c" /* yacc.c:1649  */
+  case 60:
+#line 464 "src/parse-gram.y" /* yacc.c:1649  */
+    { (yyval.generic_symlist_item) = symbol_list_type_new ((yyvsp[0].tag), (yylsp[0])); }
+#line 2658 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 62:
-#line 464 "src/parse-gram.y" /* yacc.c:1649  */
-    { (yyval.tag) = uniqstr_new (""); }
-#line 2651 "src/parse-gram.c" /* yacc.c:1649  */
+#line 469 "src/parse-gram.y" /* yacc.c:1649  */
+    { (yyval.tag) = uniqstr_new ("*"); }
+#line 2664 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
-  case 64:
-#line 487 "src/parse-gram.y" /* yacc.c:1649  */
-    {
-      (yyval.token_decls) = (yyvsp[0].yytype_76);
-    }
-#line 2659 "src/parse-gram.c" /* yacc.c:1649  */
+  case 63:
+#line 470 "src/parse-gram.y" /* yacc.c:1649  */
+    { (yyval.tag) = uniqstr_new (""); }
+#line 2670 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 65:
-#line 491 "src/parse-gram.y" /* yacc.c:1649  */
+#line 493 "src/parse-gram.y" /* yacc.c:1649  */
     {
-      (yyval.token_decls) = symbol_list_type_set ((yyvsp[0].yytype_76), (yyvsp[-1].TAG), (yylsp[-1]));
+      (yyval.token_decls) = (yyvsp[0].yytype_77);
     }
-#line 2667 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2678 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 66:
-#line 495 "src/parse-gram.y" /* yacc.c:1649  */
+#line 497 "src/parse-gram.y" /* yacc.c:1649  */
     {
-      (yyval.token_decls) = symbol_list_append ((yyvsp[-2].token_decls), symbol_list_type_set ((yyvsp[0].yytype_76), (yyvsp[-1].TAG), (yylsp[-1])));
+      (yyval.token_decls) = symbol_list_type_set ((yyvsp[0].yytype_77), (yyvsp[-1].TAG), (yylsp[-1]));
     }
-#line 2675 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2686 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 67:
-#line 502 "src/parse-gram.y" /* yacc.c:1649  */
-    { (yyval.yytype_76) = symbol_list_sym_new ((yyvsp[0].token_decl), (yylsp[0])); }
-#line 2681 "src/parse-gram.c" /* yacc.c:1649  */
+#line 501 "src/parse-gram.y" /* yacc.c:1649  */
+    {
+      (yyval.token_decls) = symbol_list_append ((yyvsp[-2].token_decls), symbol_list_type_set ((yyvsp[0].yytype_77), (yyvsp[-1].TAG), (yylsp[-1])));
+    }
+#line 2694 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 68:
-#line 503 "src/parse-gram.y" /* yacc.c:1649  */
-    { (yyval.yytype_76) = symbol_list_append ((yyvsp[-1].yytype_76), symbol_list_sym_new ((yyvsp[0].token_decl), (yylsp[0]))); }
-#line 2687 "src/parse-gram.c" /* yacc.c:1649  */
-    break;
-
-  case 69:
 #line 508 "src/parse-gram.y" /* yacc.c:1649  */
-    {
-      (yyval.token_decl) = (yyvsp[-2].id);
-      symbol_class_set ((yyvsp[-2].id), current_class, (yylsp[-2]), true);
-      if (0 <= (yyvsp[-1].yytype_78))
-        symbol_user_token_number_set ((yyvsp[-2].id), (yyvsp[-1].yytype_78), (yylsp[-1]));
-      if ((yyvsp[0].yytype_97))
-        symbol_make_alias ((yyvsp[-2].id), (yyvsp[0].yytype_97), (yylsp[0]));
-    }
+    { (yyval.yytype_77) = symbol_list_sym_new ((yyvsp[0].token_decl), (yylsp[0])); }
 #line 2700 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
-  case 70:
-#line 520 "src/parse-gram.y" /* yacc.c:1649  */
-    { (yyval.yytype_78) = -1; }
+  case 69:
+#line 509 "src/parse-gram.y" /* yacc.c:1649  */
+    { (yyval.yytype_77) = symbol_list_append ((yyvsp[-1].yytype_77), symbol_list_sym_new ((yyvsp[0].token_decl), (yylsp[0]))); }
 #line 2706 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
-  case 72:
-#line 534 "src/parse-gram.y" /* yacc.c:1649  */
+  case 70:
+#line 514 "src/parse-gram.y" /* yacc.c:1649  */
     {
-      (yyval.token_decls_for_prec) = (yyvsp[0].yytype_80);
+      (yyval.token_decl) = (yyvsp[-2].id);
+      symbol_class_set ((yyvsp[-2].id), current_class, (yylsp[-2]), true);
+      if (0 <= (yyvsp[-1].yytype_79))
+        symbol_user_token_number_set ((yyvsp[-2].id), (yyvsp[-1].yytype_79), (yylsp[-1]));
+      if ((yyvsp[0].yytype_98))
+        symbol_make_alias ((yyvsp[-2].id), (yyvsp[0].yytype_98), (yylsp[0]));
     }
-#line 2714 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2719 "src/parse-gram.c" /* yacc.c:1649  */
+    break;
+
+  case 71:
+#line 526 "src/parse-gram.y" /* yacc.c:1649  */
+    { (yyval.yytype_79) = -1; }
+#line 2725 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 73:
-#line 538 "src/parse-gram.y" /* yacc.c:1649  */
+#line 540 "src/parse-gram.y" /* yacc.c:1649  */
     {
-      (yyval.token_decls_for_prec) = symbol_list_type_set ((yyvsp[0].yytype_80), (yyvsp[-1].TAG), (yylsp[-1]));
+      (yyval.token_decls_for_prec) = (yyvsp[0].yytype_81);
     }
-#line 2722 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2733 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 74:
-#line 542 "src/parse-gram.y" /* yacc.c:1649  */
+#line 544 "src/parse-gram.y" /* yacc.c:1649  */
     {
-      (yyval.token_decls_for_prec) = symbol_list_append ((yyvsp[-2].token_decls_for_prec), symbol_list_type_set ((yyvsp[0].yytype_80), (yyvsp[-1].TAG), (yylsp[-1])));
+      (yyval.token_decls_for_prec) = symbol_list_type_set ((yyvsp[0].yytype_81), (yyvsp[-1].TAG), (yylsp[-1]));
     }
-#line 2730 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2741 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 75:
-#line 550 "src/parse-gram.y" /* yacc.c:1649  */
-    { (yyval.yytype_80) = symbol_list_sym_new ((yyvsp[0].token_decl_for_prec), (yylsp[0])); }
-#line 2736 "src/parse-gram.c" /* yacc.c:1649  */
+#line 548 "src/parse-gram.y" /* yacc.c:1649  */
+    {
+      (yyval.token_decls_for_prec) = symbol_list_append ((yyvsp[-2].token_decls_for_prec), symbol_list_type_set ((yyvsp[0].yytype_81), (yyvsp[-1].TAG), (yylsp[-1])));
+    }
+#line 2749 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 76:
-#line 552 "src/parse-gram.y" /* yacc.c:1649  */
-    { (yyval.yytype_80) = symbol_list_append ((yyvsp[-1].yytype_80), symbol_list_sym_new ((yyvsp[0].token_decl_for_prec), (yylsp[0]))); }
-#line 2742 "src/parse-gram.c" /* yacc.c:1649  */
+#line 556 "src/parse-gram.y" /* yacc.c:1649  */
+    { (yyval.yytype_81) = symbol_list_sym_new ((yyvsp[0].token_decl_for_prec), (yylsp[0])); }
+#line 2755 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 77:
-#line 557 "src/parse-gram.y" /* yacc.c:1649  */
-    {
-      (yyval.token_decl_for_prec) = (yyvsp[-1].id);
-      symbol_class_set ((yyvsp[-1].id), token_sym, (yylsp[-1]), false);
-      if (0 <= (yyvsp[0].yytype_78))
-        symbol_user_token_number_set ((yyvsp[-1].id), (yyvsp[0].yytype_78), (yylsp[0]));
-    }
-#line 2753 "src/parse-gram.c" /* yacc.c:1649  */
+#line 558 "src/parse-gram.y" /* yacc.c:1649  */
+    { (yyval.yytype_81) = symbol_list_append ((yyvsp[-1].yytype_81), symbol_list_sym_new ((yyvsp[0].token_decl_for_prec), (yylsp[0]))); }
+#line 2761 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
-  case 79:
-#line 574 "src/parse-gram.y" /* yacc.c:1649  */
+  case 78:
+#line 563 "src/parse-gram.y" /* yacc.c:1649  */
     {
-      (yyval.symbol_decls) = (yyvsp[0].yytype_83);
+      (yyval.token_decl_for_prec) = (yyvsp[-1].id);
+      symbol_class_set ((yyvsp[-1].id), token_sym, (yylsp[-1]), false);
+      if (0 <= (yyvsp[0].yytype_79))
+        symbol_user_token_number_set ((yyvsp[-1].id), (yyvsp[0].yytype_79), (yylsp[0]));
     }
-#line 2761 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2772 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 80:
-#line 578 "src/parse-gram.y" /* yacc.c:1649  */
+#line 580 "src/parse-gram.y" /* yacc.c:1649  */
     {
-      (yyval.symbol_decls) = symbol_list_type_set ((yyvsp[0].yytype_83), (yyvsp[-1].TAG), (yylsp[-1]));
+      (yyval.symbol_decls) = (yyvsp[0].yytype_84);
     }
-#line 2769 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2780 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 81:
-#line 582 "src/parse-gram.y" /* yacc.c:1649  */
+#line 584 "src/parse-gram.y" /* yacc.c:1649  */
     {
-      (yyval.symbol_decls) = symbol_list_append ((yyvsp[-2].symbol_decls), symbol_list_type_set ((yyvsp[0].yytype_83), (yyvsp[-1].TAG), (yylsp[-1])));
+      (yyval.symbol_decls) = symbol_list_type_set ((yyvsp[0].yytype_84), (yyvsp[-1].TAG), (yylsp[-1]));
     }
-#line 2777 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2788 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 82:
-#line 589 "src/parse-gram.y" /* yacc.c:1649  */
-    { (yyval.yytype_83) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-#line 2783 "src/parse-gram.c" /* yacc.c:1649  */
+#line 588 "src/parse-gram.y" /* yacc.c:1649  */
+    {
+      (yyval.symbol_decls) = symbol_list_append ((yyvsp[-2].symbol_decls), symbol_list_type_set ((yyvsp[0].yytype_84), (yyvsp[-1].TAG), (yylsp[-1])));
+    }
+#line 2796 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 83:
-#line 590 "src/parse-gram.y" /* yacc.c:1649  */
-    { (yyval.yytype_83) = symbol_list_append ((yyvsp[-1].yytype_83), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
-#line 2789 "src/parse-gram.c" /* yacc.c:1649  */
+#line 595 "src/parse-gram.y" /* yacc.c:1649  */
+    { (yyval.yytype_84) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
+#line 2802 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
-  case 88:
-#line 608 "src/parse-gram.y" /* yacc.c:1649  */
-    {
-      yyerrok;
-    }
-#line 2797 "src/parse-gram.c" /* yacc.c:1649  */
+  case 84:
+#line 596 "src/parse-gram.y" /* yacc.c:1649  */
+    { (yyval.yytype_84) = symbol_list_append ((yyvsp[-1].yytype_84), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
+#line 2808 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 89:
 #line 614 "src/parse-gram.y" /* yacc.c:1649  */
-    { current_lhs ((yyvsp[-1].id_colon), (yylsp[-1]), (yyvsp[0].yytype_90)); }
-#line 2803 "src/parse-gram.c" /* yacc.c:1649  */
+    {
+      yyerrok;
+    }
+#line 2816 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 90:
-#line 615 "src/parse-gram.y" /* yacc.c:1649  */
+#line 620 "src/parse-gram.y" /* yacc.c:1649  */
+    { current_lhs ((yyvsp[-1].id_colon), (yylsp[-1]), (yyvsp[0].yytype_91)); }
+#line 2822 "src/parse-gram.c" /* yacc.c:1649  */
+    break;
+
+  case 91:
+#line 621 "src/parse-gram.y" /* yacc.c:1649  */
     {
       /* Free the current lhs. */
       current_lhs (0, (yylsp[-3]), 0);
     }
-#line 2812 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2831 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
-  case 91:
-#line 622 "src/parse-gram.y" /* yacc.c:1649  */
+  case 92:
+#line 628 "src/parse-gram.y" /* yacc.c:1649  */
     { grammar_current_rule_end ((yylsp[0])); }
-#line 2818 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2837 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
-  case 92:
-#line 623 "src/parse-gram.y" /* yacc.c:1649  */
+  case 93:
+#line 629 "src/parse-gram.y" /* yacc.c:1649  */
     { grammar_current_rule_end ((yylsp[0])); }
-#line 2824 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2843 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
-  case 94:
-#line 630 "src/parse-gram.y" /* yacc.c:1649  */
+  case 95:
+#line 636 "src/parse-gram.y" /* yacc.c:1649  */
     { grammar_current_rule_begin (current_lhs_symbol, current_lhs_location,
                                   current_lhs_named_ref); }
-#line 2831 "src/parse-gram.c" /* yacc.c:1649  */
-    break;
-
-  case 95:
-#line 633 "src/parse-gram.y" /* yacc.c:1649  */
-    { grammar_current_rule_symbol_append ((yyvsp[-1].symbol), (yylsp[-1]), (yyvsp[0].yytype_90)); }
-#line 2837 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2850 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 96:
-#line 635 "src/parse-gram.y" /* yacc.c:1649  */
-    { grammar_current_rule_action_append ((yyvsp[-1].BRACED_CODE), (yylsp[-1]), (yyvsp[0].yytype_90), (yyvsp[-2].yytype_70)); }
-#line 2843 "src/parse-gram.c" /* yacc.c:1649  */
+#line 639 "src/parse-gram.y" /* yacc.c:1649  */
+    { grammar_current_rule_symbol_append ((yyvsp[-1].symbol), (yylsp[-1]), (yyvsp[0].yytype_91)); }
+#line 2856 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 97:
-#line 637 "src/parse-gram.y" /* yacc.c:1649  */
-    { grammar_current_rule_predicate_append ((yyvsp[0].BRACED_PREDICATE), (yylsp[0])); }
-#line 2849 "src/parse-gram.c" /* yacc.c:1649  */
+#line 641 "src/parse-gram.y" /* yacc.c:1649  */
+    { grammar_current_rule_action_append ((yyvsp[-1].BRACED_CODE), (yylsp[-1]), (yyvsp[0].yytype_91), (yyvsp[-2].yytype_71)); }
+#line 2862 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 98:
-#line 639 "src/parse-gram.y" /* yacc.c:1649  */
-    { grammar_current_rule_empty_set ((yylsp[0])); }
-#line 2855 "src/parse-gram.c" /* yacc.c:1649  */
+#line 643 "src/parse-gram.y" /* yacc.c:1649  */
+    { grammar_current_rule_predicate_append ((yyvsp[0].BRACED_PREDICATE), (yylsp[0])); }
+#line 2868 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 99:
-#line 641 "src/parse-gram.y" /* yacc.c:1649  */
-    { grammar_current_rule_prec_set ((yyvsp[0].symbol), (yylsp[0])); }
-#line 2861 "src/parse-gram.c" /* yacc.c:1649  */
+#line 645 "src/parse-gram.y" /* yacc.c:1649  */
+    { grammar_current_rule_empty_set ((yylsp[0])); }
+#line 2874 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 100:
-#line 643 "src/parse-gram.y" /* yacc.c:1649  */
-    { grammar_current_rule_dprec_set ((yyvsp[0].INT), (yylsp[0])); }
-#line 2867 "src/parse-gram.c" /* yacc.c:1649  */
+#line 647 "src/parse-gram.y" /* yacc.c:1649  */
+    { grammar_current_rule_prec_set ((yyvsp[0].symbol), (yylsp[0])); }
+#line 2880 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 101:
-#line 645 "src/parse-gram.y" /* yacc.c:1649  */
-    { grammar_current_rule_merge_set ((yyvsp[0].TAG), (yylsp[0])); }
-#line 2873 "src/parse-gram.c" /* yacc.c:1649  */
+#line 649 "src/parse-gram.y" /* yacc.c:1649  */
+    { grammar_current_rule_dprec_set ((yyvsp[0].INT), (yylsp[0])); }
+#line 2886 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 102:
-#line 647 "src/parse-gram.y" /* yacc.c:1649  */
-    { grammar_current_rule_expect_sr ((yyvsp[0].INT), (yylsp[0])); }
-#line 2879 "src/parse-gram.c" /* yacc.c:1649  */
+#line 651 "src/parse-gram.y" /* yacc.c:1649  */
+    { grammar_current_rule_merge_set ((yyvsp[0].TAG), (yylsp[0])); }
+#line 2892 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 103:
-#line 649 "src/parse-gram.y" /* yacc.c:1649  */
-    { grammar_current_rule_expect_rr ((yyvsp[0].INT), (yylsp[0])); }
-#line 2885 "src/parse-gram.c" /* yacc.c:1649  */
+#line 653 "src/parse-gram.y" /* yacc.c:1649  */
+    { grammar_current_rule_expect_sr ((yyvsp[0].INT), (yylsp[0])); }
+#line 2898 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 104:
-#line 653 "src/parse-gram.y" /* yacc.c:1649  */
-    { (yyval.yytype_90) = 0; }
-#line 2891 "src/parse-gram.c" /* yacc.c:1649  */
+#line 655 "src/parse-gram.y" /* yacc.c:1649  */
+    { grammar_current_rule_expect_rr ((yyvsp[0].INT), (yylsp[0])); }
+#line 2904 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 105:
-#line 654 "src/parse-gram.y" /* yacc.c:1649  */
-    { (yyval.yytype_90) = named_ref_new ((yyvsp[0].BRACKETED_ID), (yylsp[0])); }
-#line 2897 "src/parse-gram.c" /* yacc.c:1649  */
+#line 659 "src/parse-gram.y" /* yacc.c:1649  */
+    { (yyval.yytype_91) = 0; }
+#line 2910 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
-  case 107:
-#line 687 "src/parse-gram.y" /* yacc.c:1649  */
-    { (yyval.value).kind = muscle_keyword; (yyval.value).chars = ""; }
-#line 2903 "src/parse-gram.c" /* yacc.c:1649  */
+  case 106:
+#line 660 "src/parse-gram.y" /* yacc.c:1649  */
+    { (yyval.yytype_91) = named_ref_new ((yyvsp[0].BRACKETED_ID), (yylsp[0])); }
+#line 2916 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 108:
-#line 688 "src/parse-gram.y" /* yacc.c:1649  */
-    { (yyval.value).kind = muscle_keyword; (yyval.value).chars = (yyvsp[0].ID); }
-#line 2909 "src/parse-gram.c" /* yacc.c:1649  */
+#line 693 "src/parse-gram.y" /* yacc.c:1649  */
+    { (yyval.value).kind = muscle_keyword; (yyval.value).chars = ""; }
+#line 2922 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 109:
-#line 689 "src/parse-gram.y" /* yacc.c:1649  */
-    { (yyval.value).kind = muscle_string;  (yyval.value).chars = (yyvsp[0].STRING); }
-#line 2915 "src/parse-gram.c" /* yacc.c:1649  */
+#line 694 "src/parse-gram.y" /* yacc.c:1649  */
+    { (yyval.value).kind = muscle_keyword; (yyval.value).chars = (yyvsp[0].ID); }
+#line 2928 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 110:
-#line 690 "src/parse-gram.y" /* yacc.c:1649  */
-    { (yyval.value).kind = muscle_code;    (yyval.value).chars = strip_braces ((yyvsp[0].BRACED_CODE)); }
-#line 2921 "src/parse-gram.c" /* yacc.c:1649  */
+#line 695 "src/parse-gram.y" /* yacc.c:1649  */
+    { (yyval.value).kind = muscle_string;  (yyval.value).chars = (yyvsp[0].STRING); }
+#line 2934 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 111:
-#line 703 "src/parse-gram.y" /* yacc.c:1649  */
-    { (yyval.id) = symbol_from_uniqstr ((yyvsp[0].ID), (yylsp[0])); }
-#line 2927 "src/parse-gram.c" /* yacc.c:1649  */
+#line 696 "src/parse-gram.y" /* yacc.c:1649  */
+    { (yyval.value).kind = muscle_code;    (yyval.value).chars = strip_braces ((yyvsp[0].BRACED_CODE)); }
+#line 2940 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 112:
-#line 705 "src/parse-gram.y" /* yacc.c:1649  */
+#line 709 "src/parse-gram.y" /* yacc.c:1649  */
+    { (yyval.id) = symbol_from_uniqstr ((yyvsp[0].ID), (yylsp[0])); }
+#line 2946 "src/parse-gram.c" /* yacc.c:1649  */
+    break;
+
+  case 113:
+#line 711 "src/parse-gram.y" /* yacc.c:1649  */
     {
       if (current_class == nterm_sym)
         {
@@ -2939,41 +2958,41 @@ yyreduce:
       symbol_class_set ((yyval.id), token_sym, (yylsp[0]), false);
       symbol_user_token_number_set ((yyval.id), (yyvsp[0].CHAR), (yylsp[0]));
     }
-#line 2943 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2962 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
-  case 113:
-#line 719 "src/parse-gram.y" /* yacc.c:1649  */
+  case 114:
+#line 725 "src/parse-gram.y" /* yacc.c:1649  */
     { (yyval.id_colon) = symbol_from_uniqstr ((yyvsp[0].ID_COLON), (yylsp[0])); }
-#line 2949 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2968 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
-  case 116:
-#line 731 "src/parse-gram.y" /* yacc.c:1649  */
+  case 117:
+#line 737 "src/parse-gram.y" /* yacc.c:1649  */
     {
       (yyval.string_as_id) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[0].STRING)), (yylsp[0]));
       symbol_class_set ((yyval.string_as_id), token_sym, (yylsp[0]), false);
     }
-#line 2958 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2977 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
-  case 117:
-#line 739 "src/parse-gram.y" /* yacc.c:1649  */
-    { (yyval.yytype_97) = NULL; }
-#line 2964 "src/parse-gram.c" /* yacc.c:1649  */
+  case 118:
+#line 745 "src/parse-gram.y" /* yacc.c:1649  */
+    { (yyval.yytype_98) = NULL; }
+#line 2983 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
-  case 120:
-#line 746 "src/parse-gram.y" /* yacc.c:1649  */
+  case 121:
+#line 752 "src/parse-gram.y" /* yacc.c:1649  */
     {
       muscle_code_grow ("epilogue", translate_code ((yyvsp[0].EPILOGUE), (yylsp[0]), true), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2973 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2992 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
 
-#line 2977 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2996 "src/parse-gram.c" /* yacc.c:1649  */
         default: break;
       }
     if (yychar_backup != yychar)
@@ -3222,7 +3241,7 @@ yyreturn:
 #endif
   return yyresult;
 }
-#line 752 "src/parse-gram.y" /* yacc.c:1915  */
+#line 758 "src/parse-gram.y" /* yacc.c:1915  */
 
 
 /* Return the location of the left-hand side of a rule whose
@@ -3327,6 +3346,15 @@ add_param (param_type type, char *decl, location loc)
 }
 
 
+static void
+do_error_verbose (location const *loc, char const *directive)
+{
+  bison_directive (loc, directive);
+  muscle_percent_define_insert (directive, *loc, muscle_keyword, "",
+                                MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
+}
+
+
 static void
 do_name_prefix (location const *loc,
                 char const *directive, char const *value)
