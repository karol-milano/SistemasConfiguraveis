@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 3.7.14-eb26-dirty.  */
+/* A Bison parser, made by GNU Bison 3.7.2.43-1ae84.  */
 
 /* Bison implementation for Yacc-like parsers in C
 
@@ -49,7 +49,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "3.7.14-eb26-dirty"
+#define YYBISON_VERSION "3.7.2.43-1ae84"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -125,13 +125,13 @@ enum yysymbol_kind_t
   YYSYMBOL_PERCENT_CODE = 17,              /* "%code"  */
   YYSYMBOL_PERCENT_DEFAULT_PREC = 18,      /* "%default-prec"  */
   YYSYMBOL_PERCENT_DEFINE = 19,            /* "%define"  */
-  YYSYMBOL_PERCENT_DEFINES = 20,           /* "%defines"  */
-  YYSYMBOL_PERCENT_ERROR_VERBOSE = 21,     /* "%error-verbose"  */
-  YYSYMBOL_PERCENT_EXPECT = 22,            /* "%expect"  */
-  YYSYMBOL_PERCENT_EXPECT_RR = 23,         /* "%expect-rr"  */
+  YYSYMBOL_PERCENT_ERROR_VERBOSE = 20,     /* "%error-verbose"  */
+  YYSYMBOL_PERCENT_EXPECT = 21,            /* "%expect"  */
+  YYSYMBOL_PERCENT_EXPECT_RR = 22,         /* "%expect-rr"  */
+  YYSYMBOL_PERCENT_FILE_PREFIX = 23,       /* "%file-prefix"  */
   YYSYMBOL_PERCENT_FLAG = 24,              /* "%<flag>"  */
-  YYSYMBOL_PERCENT_FILE_PREFIX = 25,       /* "%file-prefix"  */
-  YYSYMBOL_PERCENT_GLR_PARSER = 26,        /* "%glr-parser"  */
+  YYSYMBOL_PERCENT_GLR_PARSER = 25,        /* "%glr-parser"  */
+  YYSYMBOL_PERCENT_HEADER = 26,            /* "%header"  */
   YYSYMBOL_PERCENT_INITIAL_ACTION = 27,    /* "%initial-action"  */
   YYSYMBOL_PERCENT_LANGUAGE = 28,          /* "%language"  */
   YYSYMBOL_PERCENT_NAME_PREFIX = 29,       /* "%name-prefix"  */
@@ -179,35 +179,36 @@ enum yysymbol_kind_t
   YYSYMBOL_71_2 = 71,                      /* $@2  */
   YYSYMBOL_72_3 = 72,                      /* $@3  */
   YYSYMBOL_precedence_declarator = 73,     /* precedence_declarator  */
-  YYSYMBOL_74_tag_opt = 74,                /* tag.opt  */
-  YYSYMBOL_generic_symlist = 75,           /* generic_symlist  */
-  YYSYMBOL_generic_symlist_item = 76,      /* generic_symlist_item  */
-  YYSYMBOL_tag = 77,                       /* tag  */
-  YYSYMBOL_nterm_decls = 78,               /* nterm_decls  */
-  YYSYMBOL_token_decls = 79,               /* token_decls  */
-  YYSYMBOL_80_token_decl_1 = 80,           /* token_decl.1  */
-  YYSYMBOL_token_decl = 81,                /* token_decl  */
-  YYSYMBOL_82_int_opt = 82,                /* int.opt  */
-  YYSYMBOL_alias = 83,                     /* alias  */
-  YYSYMBOL_token_decls_for_prec = 84,      /* token_decls_for_prec  */
-  YYSYMBOL_85_token_decl_for_prec_1 = 85,  /* token_decl_for_prec.1  */
-  YYSYMBOL_token_decl_for_prec = 86,       /* token_decl_for_prec  */
-  YYSYMBOL_symbol_decls = 87,              /* symbol_decls  */
-  YYSYMBOL_88_symbol_decl_1 = 88,          /* symbol_decl.1  */
-  YYSYMBOL_grammar = 89,                   /* grammar  */
-  YYSYMBOL_rules_or_grammar_declaration = 90, /* rules_or_grammar_declaration  */
-  YYSYMBOL_rules = 91,                     /* rules  */
-  YYSYMBOL_92_4 = 92,                      /* $@4  */
-  YYSYMBOL_93_rhses_1 = 93,                /* rhses.1  */
-  YYSYMBOL_rhs = 94,                       /* rhs  */
-  YYSYMBOL_95_named_ref_opt = 95,          /* named_ref.opt  */
-  YYSYMBOL_variable = 96,                  /* variable  */
-  YYSYMBOL_value = 97,                     /* value  */
-  YYSYMBOL_id = 98,                        /* id  */
-  YYSYMBOL_id_colon = 99,                  /* id_colon  */
-  YYSYMBOL_symbol = 100,                   /* symbol  */
-  YYSYMBOL_string_as_id = 101,             /* string_as_id  */
-  YYSYMBOL_102_epilogue_opt = 102          /* epilogue.opt  */
+  YYSYMBOL_74_string_opt = 74,             /* string.opt  */
+  YYSYMBOL_75_tag_opt = 75,                /* tag.opt  */
+  YYSYMBOL_generic_symlist = 76,           /* generic_symlist  */
+  YYSYMBOL_generic_symlist_item = 77,      /* generic_symlist_item  */
+  YYSYMBOL_tag = 78,                       /* tag  */
+  YYSYMBOL_nterm_decls = 79,               /* nterm_decls  */
+  YYSYMBOL_token_decls = 80,               /* token_decls  */
+  YYSYMBOL_81_token_decl_1 = 81,           /* token_decl.1  */
+  YYSYMBOL_token_decl = 82,                /* token_decl  */
+  YYSYMBOL_83_int_opt = 83,                /* int.opt  */
+  YYSYMBOL_alias = 84,                     /* alias  */
+  YYSYMBOL_token_decls_for_prec = 85,      /* token_decls_for_prec  */
+  YYSYMBOL_86_token_decl_for_prec_1 = 86,  /* token_decl_for_prec.1  */
+  YYSYMBOL_token_decl_for_prec = 87,       /* token_decl_for_prec  */
+  YYSYMBOL_symbol_decls = 88,              /* symbol_decls  */
+  YYSYMBOL_89_symbol_decl_1 = 89,          /* symbol_decl.1  */
+  YYSYMBOL_grammar = 90,                   /* grammar  */
+  YYSYMBOL_rules_or_grammar_declaration = 91, /* rules_or_grammar_declaration  */
+  YYSYMBOL_rules = 92,                     /* rules  */
+  YYSYMBOL_93_4 = 93,                      /* $@4  */
+  YYSYMBOL_94_rhses_1 = 94,                /* rhses.1  */
+  YYSYMBOL_rhs = 95,                       /* rhs  */
+  YYSYMBOL_96_named_ref_opt = 96,          /* named_ref.opt  */
+  YYSYMBOL_variable = 97,                  /* variable  */
+  YYSYMBOL_value = 98,                     /* value  */
+  YYSYMBOL_id = 99,                        /* id  */
+  YYSYMBOL_id_colon = 100,                 /* id_colon  */
+  YYSYMBOL_symbol = 101,                   /* symbol  */
+  YYSYMBOL_string_as_id = 102,             /* string_as_id  */
+  YYSYMBOL_103_epilogue_opt = 103          /* epilogue.opt  */
 };
 typedef enum yysymbol_kind_t yysymbol_kind_t;
 
@@ -272,8 +273,8 @@ typedef enum yysymbol_kind_t yysymbol_kind_t;
      string from the scanner (should be CODE). */
   static char const *translate_code_braceless (char *code, location loc);
 
-  /* Handle a %defines directive.  */
-  static void handle_defines (char const *value);
+  /* Handle a %header directive.  */
+  static void handle_header (char const *value);
 
   /* Handle a %error-verbose directive.  */
   static void handle_error_verbose (location const *loc, char const *directive);
@@ -472,12 +473,18 @@ typedef int yy_state_fast_t;
 # define YYUSE(E) /* empty */
 #endif
 
-#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
 /* Suppress an incorrect diagnostic about yylval being uninitialized.  */
-# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
+#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
+# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
+#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
+    _Pragma ("GCC diagnostic push")                                     \
+    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
+# else
+#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
     _Pragma ("GCC diagnostic push")                                     \
     _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
     _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
+# endif
 # define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
     _Pragma ("GCC diagnostic pop")
 #else
@@ -616,16 +623,16 @@ union yyalloc
 /* YYFINAL -- State number of the termination state.  */
 #define YYFINAL  3
 /* YYLAST -- Last index in YYTABLE.  */
-#define YYLAST   234
+#define YYLAST   235
 
 /* YYNTOKENS -- Number of terminals.  */
 #define YYNTOKENS  61
 /* YYNNTS -- Number of nonterminals.  */
-#define YYNNTS  42
+#define YYNNTS  43
 /* YYNRULES -- Number of rules.  */
-#define YYNRULES  123
+#define YYNRULES  124
 /* YYNSTATES -- Number of states.  */
-#define YYNSTATES  167
+#define YYNSTATES  168
 
 /* YYMAXUTOK -- Last valid token kind.  */
 #define YYMAXUTOK   315
@@ -639,19 +646,19 @@ union yyalloc
   /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
 static const yytype_int16 yyrline[] =
 {
-       0,   312,   312,   321,   322,   326,   327,   333,   337,   342,
-     343,   344,   345,   346,   347,   348,   353,   358,   359,   360,
-     361,   362,   363,   363,   364,   365,   366,   367,   368,   369,
-     370,   371,   375,   376,   385,   386,   390,   401,   405,   409,
-     417,   427,   428,   438,   439,   445,   458,   458,   463,   463,
-     468,   472,   482,   483,   484,   485,   489,   490,   495,   496,
-     500,   501,   505,   506,   507,   520,   529,   533,   537,   545,
-     546,   550,   563,   564,   569,   570,   571,   589,   593,   597,
-     605,   607,   612,   619,   629,   633,   637,   645,   650,   662,
-     663,   669,   670,   671,   678,   678,   686,   687,   688,   693,
-     696,   698,   700,   702,   704,   706,   708,   710,   712,   717,
-     718,   727,   751,   752,   753,   754,   766,   768,   792,   797,
-     798,   803,   811,   812
+       0,   311,   311,   320,   321,   325,   326,   332,   336,   341,
+     342,   343,   344,   345,   346,   351,   356,   357,   358,   359,
+     360,   361,   361,   362,   363,   364,   365,   366,   367,   368,
+     369,   373,   374,   383,   384,   388,   399,   403,   407,   415,
+     425,   426,   436,   437,   443,   456,   456,   461,   461,   466,
+     470,   480,   481,   482,   483,   488,   489,   493,   494,   499,
+     500,   504,   505,   509,   510,   511,   524,   533,   537,   541,
+     549,   550,   554,   567,   568,   573,   574,   575,   593,   597,
+     601,   609,   611,   616,   623,   633,   637,   641,   649,   654,
+     666,   667,   673,   674,   675,   682,   682,   690,   691,   692,
+     697,   700,   702,   704,   706,   708,   710,   712,   714,   716,
+     721,   722,   731,   755,   756,   757,   758,   770,   772,   796,
+     801,   802,   807,   815,   816
 };
 #endif
 
@@ -671,9 +678,9 @@ yysymbol_name (yysymbol_kind_t yysymbol)
   N_("end of file"), N_("error"), N_("invalid token"), N_("string"),
   N_("translatable string"), "%token", "%nterm", "%type", "%destructor",
   "%printer", "%left", "%right", "%nonassoc", "%precedence", "%prec",
-  "%dprec", "%merge", "%code", "%default-prec", "%define", "%defines",
-  "%error-verbose", "%expect", "%expect-rr", "%<flag>", "%file-prefix",
-  "%glr-parser", "%initial-action", "%language", "%name-prefix",
+  "%dprec", "%merge", "%code", "%default-prec", "%define",
+  "%error-verbose", "%expect", "%expect-rr", "%file-prefix", "%<flag>",
+  "%glr-parser", "%header", "%initial-action", "%language", "%name-prefix",
   "%no-default-prec", "%no-lines", "%nondeterministic-parser", "%output",
   "%pure-parser", "%require", "%skeleton", "%start", "%token-table",
   "%verbose", "%yacc", "{...}", "%?{...}", N_("[identifier]"),
@@ -682,11 +689,11 @@ yysymbol_name (yysymbol_kind_t yysymbol)
   N_("integer literal"), "%param", "%union", "%empty", "$accept", "input",
   "prologue_declarations", "prologue_declaration", "$@1", "params",
   "grammar_declaration", "code_props_type", "union_name",
-  "symbol_declaration", "$@2", "$@3", "precedence_declarator", "tag.opt",
-  "generic_symlist", "generic_symlist_item", "tag", "nterm_decls",
-  "token_decls", "token_decl.1", "token_decl", "int.opt", "alias",
-  "token_decls_for_prec", "token_decl_for_prec.1", "token_decl_for_prec",
-  "symbol_decls", "symbol_decl.1", "grammar",
+  "symbol_declaration", "$@2", "$@3", "precedence_declarator",
+  "string.opt", "tag.opt", "generic_symlist", "generic_symlist_item",
+  "tag", "nterm_decls", "token_decls", "token_decl.1", "token_decl",
+  "int.opt", "alias", "token_decls_for_prec", "token_decl_for_prec.1",
+  "token_decl_for_prec", "symbol_decls", "symbol_decl.1", "grammar",
   "rules_or_grammar_declaration", "rules", "$@4", "rhses.1", "rhs",
   "named_ref.opt", "variable", "value", "id", "id_colon", "symbol",
   "string_as_id", "epilogue.opt", YY_NULLPTR
@@ -724,12 +731,12 @@ static const yytype_int16 yytoknum[] =
 };
 #endif
 
-#define YYPACT_NINF (-80)
+#define YYPACT_NINF (-129)
 
 #define yypact_value_is_default(Yyn) \
   ((Yyn) == YYPACT_NINF)
 
-#define YYTABLE_NINF (-123)
+#define YYTABLE_NINF (-124)
 
 #define yytable_value_is_error(Yyn) \
   0
@@ -738,23 +745,23 @@ static const yytype_int16 yytoknum[] =
      STATE-NUM.  */
 static const yytype_int16 yypact[] =
 {
-     -80,     5,   120,   -80,   -17,   -80,   -80,    23,   -80,   -80,
-     -80,   -80,   -80,   -80,    -7,   -80,    10,    58,   -80,     6,
-      34,   -80,    82,   -80,    54,    95,   101,   -80,   -80,   -80,
-     103,   -80,   105,   107,    24,   -80,   -80,   -80,   175,   -80,
-     -80,   -80,    64,   -80,   -80,    75,   -80,    61,   -80,   -15,
-     -15,   -80,   -80,   -80,    24,    63,    24,   -80,   -80,   -80,
-     -80,    77,   -80,    46,   -80,   -80,   -80,   -80,   -80,   -80,
-     -80,   -80,   -80,   -80,   -80,    67,   -80,    69,     7,   -80,
-     -80,    80,    93,   -80,    94,    -1,    24,   108,    24,   -80,
-      79,   -80,   -38,   109,   -38,   -80,    79,   -80,   109,    24,
-      24,   -80,   -80,   -80,   -80,   -80,   -80,   -80,   -80,   115,
-     -80,   -80,   -80,   -80,   -80,   123,   -80,   -80,   -80,   -80,
-      -1,   -80,   -80,   -80,    24,    24,   -80,   -80,   -80,   -38,
-     -38,   -80,    28,    24,   -80,   121,   -80,   -80,    24,   -38,
-     -80,   -80,   -80,   -80,   -23,    59,   -80,   -80,    24,   110,
-     111,   112,   114,   -80,   -80,   -80,   127,    80,    59,   -80,
-     -80,   -80,   -80,   -80,    80,   -80,   -80
+    -129,     7,   121,  -129,   -17,  -129,  -129,     2,  -129,  -129,
+    -129,  -129,  -129,  -129,   -13,  -129,    11,  -129,    -2,     3,
+      58,  -129,  -129,    61,    36,    80,    83,  -129,  -129,  -129,
+      85,  -129,    88,    89,    21,  -129,  -129,  -129,   176,  -129,
+    -129,  -129,    48,  -129,  -129,    57,  -129,    24,  -129,   -15,
+     -15,  -129,  -129,  -129,    21,    56,    21,  -129,  -129,  -129,
+    -129,    70,  -129,    68,  -129,  -129,  -129,  -129,  -129,  -129,
+    -129,  -129,  -129,  -129,  -129,  -129,    64,  -129,    65,     8,
+    -129,  -129,    76,    72,  -129,    82,    51,    21,    81,    21,
+    -129,    79,  -129,   -38,   109,   -38,  -129,    79,  -129,   109,
+      21,    21,  -129,  -129,  -129,  -129,  -129,  -129,  -129,  -129,
+      75,  -129,  -129,  -129,  -129,  -129,    96,  -129,  -129,  -129,
+    -129,    51,  -129,  -129,  -129,    21,    21,  -129,  -129,  -129,
+     -38,   -38,  -129,    28,    21,  -129,   119,  -129,  -129,    21,
+     -38,  -129,  -129,  -129,  -129,    -9,    60,  -129,  -129,    21,
+     108,   112,   110,   111,  -129,  -129,  -129,   128,    76,    60,
+    -129,  -129,  -129,  -129,  -129,    76,  -129,  -129
 };
 
   /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
@@ -762,43 +769,43 @@ static const yytype_int16 yypact[] =
      means the default is an error.  */
 static const yytype_int8 yydefact[] =
 {
-       3,     0,     0,     1,     0,    48,    46,     0,    41,    42,
-      52,    53,    54,    55,     0,    37,     0,     9,    11,     0,
-       0,     7,     0,    15,     0,     0,     0,    38,    19,    20,
-       0,    24,     0,     0,     0,    27,    28,    29,     0,     6,
-      31,    22,    43,     4,     5,     0,    34,     0,    30,     0,
-       0,   121,   117,   116,     0,    50,    84,   119,    87,   120,
-      39,     0,   111,   112,    10,    12,    13,    14,    16,    17,
-      18,    21,    25,    26,    35,     0,   118,     0,     0,    89,
-      91,   109,     0,    44,     0,     0,     0,    51,    77,    80,
-      72,    83,     0,    49,    66,    69,    72,    47,    65,    85,
-       0,    88,    40,   114,   115,   113,     8,    93,    92,     0,
-      90,     2,   110,    94,    33,    23,    45,    62,    63,    64,
-      36,    58,    61,    60,    78,     0,    81,    73,    82,    67,
-       0,    70,    74,    86,   123,     0,    32,    59,    79,    68,
-      76,    71,    75,    99,    95,    96,    99,    98,     0,     0,
-       0,     0,     0,   102,    57,   103,     0,   109,    97,   104,
-     105,   106,   107,   108,   109,   100,   101
+       3,     0,     0,     1,     0,    47,    45,     0,    40,    41,
+      51,    52,    53,    54,     0,    36,     0,    10,     0,     0,
+       0,     7,    14,    55,     0,     0,     0,    37,    18,    19,
+       0,    23,     0,     0,     0,    26,    27,    28,     0,     6,
+      30,    21,    42,     4,     5,     0,    33,     0,    29,     0,
+       0,   122,   118,   117,     0,    49,    85,   120,    88,   121,
+      38,     0,   112,   113,    11,    12,    13,    56,     9,    15,
+      16,    17,    20,    24,    25,    34,     0,   119,     0,     0,
+      90,    92,   110,     0,    43,     0,     0,     0,    50,    78,
+      81,    73,    84,     0,    48,    67,    70,    73,    46,    66,
+      86,     0,    89,    39,   115,   116,   114,     8,    94,    93,
+       0,    91,     2,   111,    95,    32,    22,    44,    63,    64,
+      65,    35,    59,    62,    61,    79,     0,    82,    74,    83,
+      68,     0,    71,    75,    87,   124,     0,    31,    60,    80,
+      69,    77,    72,    76,   100,    96,    97,   100,    99,     0,
+       0,     0,     0,     0,   103,    58,   104,     0,   110,    98,
+     105,   106,   107,   108,   109,   110,   101,   102
 };
 
   /* YYPGOTO[NTERM-NUM].  */
 static const yytype_int16 yypgoto[] =
 {
-     -80,   -80,   -80,   -80,   -80,   -80,   172,   -80,   -80,   -80,
-     -80,   -80,   -80,   -80,   -80,    55,   -80,   -80,   139,   -54,
-     -59,    81,   -80,   -80,   -65,   -79,   -80,   -31,   -80,   113,
-     -80,   -80,   -80,    44,   -67,   -80,   -80,   -46,   -80,   -34,
-     -36,   -80
+    -129,  -129,  -129,  -129,  -129,  -129,   122,  -129,  -129,  -129,
+    -129,  -129,  -129,  -129,  -129,  -129,    49,  -129,  -129,   125,
+     -91,    67,    93,  -129,  -129,   -53,   -77,  -129,   -31,  -129,
+      97,  -129,  -129,  -129,    25,  -128,  -129,  -129,   -46,  -129,
+     -34,   -36,  -129
 };
 
   /* YYDEFGOTO[NTERM-NUM].  */
 static const yytype_int16 yydefgoto[] =
 {
-      -1,     1,     2,    43,    82,   115,    77,    45,    84,    46,
-      50,    49,    47,   156,   120,   121,   122,    97,    93,    94,
-      95,   128,   141,    87,    88,    89,    55,    56,    78,    79,
-      80,   135,   144,   145,   113,    63,   106,    57,    81,    58,
-      59,   111
+      -1,     1,     2,    43,    83,   116,    78,    45,    85,    46,
+      50,    49,    47,    68,   157,   121,   122,   123,    98,    94,
+      95,    96,   129,   142,    88,    89,    90,    55,    56,    79,
+      80,    81,   136,   145,   146,   114,    63,   107,    57,    82,
+      58,    59,   112
 };
 
   /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
@@ -806,58 +813,58 @@ static const yytype_int16 yydefgoto[] =
      number is the opposite.  If YYTABLE_NINF, syntax error.  */
 static const yytype_int16 yytable[] =
 {
-      74,    90,    51,    96,    96,     3,    52,  -122,    75,   126,
-      53,    91,     5,     6,     7,     8,     9,    10,    11,    12,
-      13,   124,   101,    99,    14,    15,    51,    51,   146,    52,
-     147,    51,   140,    53,    60,   131,    48,    27,   129,    92,
-      90,    61,    90,    52,    34,   126,    96,    53,    96,   103,
-      91,   123,    91,   117,   118,   119,    76,   109,    62,   126,
-     138,    64,    51,    65,    51,   101,    42,    52,    52,   133,
-     131,    53,    53,   148,   149,   150,   139,    54,    90,    90,
-     131,   151,   152,    96,    96,    67,   123,   104,    91,    91,
-     165,    66,    90,    96,   105,    68,   142,   166,    69,   101,
-     -56,   153,    91,    52,    70,    52,    71,    53,    72,    53,
-      73,   157,    83,   154,   159,    86,    85,   100,   102,   155,
-     107,     4,   108,   112,   157,     5,     6,     7,     8,     9,
-      10,    11,    12,    13,   114,   116,   127,    14,    15,    16,
-      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
-      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
-      37,   134,   125,   130,   136,   161,   143,   160,   164,   162,
-      38,   163,    39,    40,    44,   137,    75,   132,    41,    42,
-       5,     6,     7,     8,     9,    10,    11,    12,    13,    98,
-     158,   110,    14,    15,     0,     0,     0,     0,     0,     0,
-       0,     0,     0,     0,     0,    27,     0,     0,     0,     0,
-       0,     0,    34,     0,     0,     0,     0,     0,     0,     0,
-       0,     0,     0,     0,    76,     0,     0,     0,     0,     0,
-       0,     0,     0,     0,    42
+      75,    91,   130,    97,    97,    51,    52,     3,  -123,    76,
+      53,    92,   127,     5,     6,     7,     8,     9,    10,    11,
+      12,    13,   102,   100,    51,    14,    15,    51,    60,    52,
+     166,    51,   141,    53,   125,    61,    48,   167,    27,    93,
+     140,    91,   147,    91,   148,    34,    52,    97,   127,    97,
+      53,    92,   124,    92,    51,    64,    54,    77,   110,    62,
+      65,    66,   127,    51,    67,    52,   102,    42,    52,    53,
+     134,   104,    53,   139,   149,   150,   151,    69,    87,    91,
+      91,   152,   153,    70,    97,    97,    71,   124,    72,    92,
+      92,    73,    74,    91,    97,    52,    84,   143,    86,    53,
+     102,   -57,   154,    92,    52,   118,   119,   120,    53,   105,
+     101,   103,   158,   115,   155,   160,   106,   108,   109,   113,
+     156,   135,     4,   117,    44,   158,     5,     6,     7,     8,
+       9,    10,    11,    12,    13,   126,   128,   137,    14,    15,
+      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
+      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
+      36,    37,   132,   131,   144,   161,   162,   163,   164,   165,
+     138,    38,   159,    39,    40,    99,   111,    76,     0,    41,
+      42,     5,     6,     7,     8,     9,    10,    11,    12,    13,
+     133,     0,     0,    14,    15,     0,     0,   132,     0,     0,
+       0,     0,     0,     0,     0,     0,    27,   132,     0,     0,
+       0,     0,     0,    34,     0,     0,     0,     0,     0,     0,
+       0,     0,     0,     0,     0,    77,     0,     0,     0,     0,
+       0,     0,     0,     0,     0,    42
 };
 
 static const yytype_int16 yycheck[] =
 {
-      34,    47,     3,    49,    50,     0,    44,     0,     1,    88,
-      48,    47,     5,     6,     7,     8,     9,    10,    11,    12,
-      13,    86,    56,    54,    17,    18,     3,     3,    51,    44,
-      53,     3,     4,    48,    41,    94,    53,    30,    92,    54,
-      86,    48,    88,    44,    37,   124,    92,    48,    94,     3,
-      86,    85,    88,    54,    55,    56,    49,    50,    48,   138,
-     125,     3,     3,    57,     3,    99,    59,    44,    44,   100,
-     129,    48,    48,    14,    15,    16,   130,    54,   124,   125,
-     139,    22,    23,   129,   130,     3,   120,    41,   124,   125,
-     157,    57,   138,   139,    48,    41,   132,   164,     3,   133,
-      41,    42,   138,    44,     3,    44,     3,    48,     3,    48,
-       3,   145,    48,    54,   148,    54,    41,    54,    41,    60,
-      53,     1,    53,    43,   158,     5,     6,     7,     8,     9,
-      10,    11,    12,    13,    41,    41,    57,    17,    18,    19,
-      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
-      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
-      40,    46,    54,    54,    41,    54,    45,    57,    41,    57,
-      50,    57,    52,    53,     2,   120,     1,    96,    58,    59,
-       5,     6,     7,     8,     9,    10,    11,    12,    13,    50,
-     146,    78,    17,    18,    -1,    -1,    -1,    -1,    -1,    -1,
-      -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,
-      -1,    -1,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
-      -1,    -1,    -1,    -1,    49,    -1,    -1,    -1,    -1,    -1,
-      -1,    -1,    -1,    -1,    59
+      34,    47,    93,    49,    50,     3,    44,     0,     0,     1,
+      48,    47,    89,     5,     6,     7,     8,     9,    10,    11,
+      12,    13,    56,    54,     3,    17,    18,     3,    41,    44,
+     158,     3,     4,    48,    87,    48,    53,   165,    30,    54,
+     131,    87,    51,    89,    53,    37,    44,    93,   125,    95,
+      48,    87,    86,    89,     3,    57,    54,    49,    50,    48,
+      57,     3,   139,     3,     3,    44,   100,    59,    44,    48,
+     101,     3,    48,   126,    14,    15,    16,    41,    54,   125,
+     126,    21,    22,     3,   130,   131,     3,   121,     3,   125,
+     126,     3,     3,   139,   140,    44,    48,   133,    41,    48,
+     134,    41,    42,   139,    44,    54,    55,    56,    48,    41,
+      54,    41,   146,    41,    54,   149,    48,    53,    53,    43,
+      60,    46,     1,    41,     2,   159,     5,     6,     7,     8,
+       9,    10,    11,    12,    13,    54,    57,    41,    17,    18,
+      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
+      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
+      39,    40,    95,    54,    45,    57,    54,    57,    57,    41,
+     121,    50,   147,    52,    53,    50,    79,     1,    -1,    58,
+      59,     5,     6,     7,     8,     9,    10,    11,    12,    13,
+      97,    -1,    -1,    17,    18,    -1,    -1,   130,    -1,    -1,
+      -1,    -1,    -1,    -1,    -1,    -1,    30,   140,    -1,    -1,
+      -1,    -1,    -1,    37,    -1,    -1,    -1,    -1,    -1,    -1,
+      -1,    -1,    -1,    -1,    -1,    49,    -1,    -1,    -1,    -1,
+      -1,    -1,    -1,    -1,    -1,    59
 };
 
   /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
@@ -869,18 +876,18 @@ static const yytype_int8 yystos[] =
       23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
       33,    34,    35,    36,    37,    38,    39,    40,    50,    52,
       53,    58,    59,    64,    67,    68,    70,    73,    53,    72,
-      71,     3,    44,    48,    54,    87,    88,    98,   100,   101,
-      41,    48,    48,    96,     3,    57,    57,     3,    41,     3,
-       3,     3,     3,     3,   100,     1,    49,    67,    89,    90,
-      91,    99,    65,    48,    69,    41,    54,    84,    85,    86,
-      98,   101,    54,    79,    80,    81,    98,    78,    79,    88,
-      54,   100,    41,     3,    41,    48,    97,    53,    53,    50,
-      90,   102,    43,    95,    41,    66,    41,    54,    55,    56,
-      75,    76,    77,   100,    85,    54,    86,    57,    82,    80,
-      54,    81,    82,    88,    46,    92,    41,    76,    85,    80,
-       4,    83,   101,    45,    93,    94,    51,    53,    14,    15,
-      16,    22,    23,    42,    54,    60,    74,   100,    94,   100,
-      57,    54,    57,    57,    41,    95,    95
+      71,     3,    44,    48,    54,    88,    89,    99,   101,   102,
+      41,    48,    48,    97,    57,    57,     3,     3,    74,    41,
+       3,     3,     3,     3,     3,   101,     1,    49,    67,    90,
+      91,    92,   100,    65,    48,    69,    41,    54,    85,    86,
+      87,    99,   102,    54,    80,    81,    82,    99,    79,    80,
+      89,    54,   101,    41,     3,    41,    48,    98,    53,    53,
+      50,    91,   103,    43,    96,    41,    66,    41,    54,    55,
+      56,    76,    77,    78,   101,    86,    54,    87,    57,    83,
+      81,    54,    82,    83,    89,    46,    93,    41,    77,    86,
+      81,     4,    84,   102,    45,    94,    95,    51,    53,    14,
+      15,    16,    21,    22,    42,    54,    60,    75,   101,    95,
+     101,    57,    54,    57,    57,    41,    96,    96
 };
 
   /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
@@ -888,35 +895,35 @@ static const yytype_int8 yyr1[] =
 {
        0,    61,    62,    63,    63,    64,    64,    64,    64,    64,
       64,    64,    64,    64,    64,    64,    64,    64,    64,    64,
-      64,    64,    65,    64,    64,    64,    64,    64,    64,    64,
-      64,    64,    66,    66,    67,    67,    67,    67,    67,    67,
-      67,    68,    68,    69,    69,    67,    71,    70,    72,    70,
-      70,    70,    73,    73,    73,    73,    74,    74,    75,    75,
-      76,    76,    77,    77,    77,    78,    79,    79,    79,    80,
-      80,    81,    82,    82,    83,    83,    83,    84,    84,    84,
-      85,    85,    86,    86,    87,    87,    87,    88,    88,    89,
-      89,    90,    90,    90,    92,    91,    93,    93,    93,    94,
-      94,    94,    94,    94,    94,    94,    94,    94,    94,    95,
-      95,    96,    97,    97,    97,    97,    98,    98,    99,   100,
-     100,   101,   102,   102
+      64,    65,    64,    64,    64,    64,    64,    64,    64,    64,
+      64,    66,    66,    67,    67,    67,    67,    67,    67,    67,
+      68,    68,    69,    69,    67,    71,    70,    72,    70,    70,
+      70,    73,    73,    73,    73,    74,    74,    75,    75,    76,
+      76,    77,    77,    78,    78,    78,    79,    80,    80,    80,
+      81,    81,    82,    83,    83,    84,    84,    84,    85,    85,
+      85,    86,    86,    87,    87,    88,    88,    88,    89,    89,
+      90,    90,    91,    91,    91,    93,    92,    94,    94,    94,
+      95,    95,    95,    95,    95,    95,    95,    95,    95,    95,
+      96,    96,    97,    98,    98,    98,    98,    99,    99,   100,
+     101,   101,   102,   103,   103
 };
 
   /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
 static const yytype_int8 yyr2[] =
 {
-       0,     2,     4,     0,     2,     1,     1,     1,     3,     1,
-       2,     1,     2,     2,     2,     1,     2,     2,     2,     1,
-       1,     2,     0,     3,     1,     2,     2,     1,     1,     1,
-       2,     1,     2,     1,     1,     2,     3,     1,     1,     2,
-       3,     1,     1,     0,     1,     3,     0,     3,     0,     3,
-       2,     2,     1,     1,     1,     1,     0,     1,     1,     2,
-       1,     1,     1,     1,     1,     1,     1,     2,     3,     1,
-       2,     3,     0,     1,     0,     1,     1,     1,     2,     3,
-       1,     2,     2,     1,     1,     2,     3,     1,     2,     1,
-       2,     1,     2,     2,     0,     5,     1,     3,     2,     0,
-       3,     4,     2,     2,     3,     3,     3,     3,     3,     0,
-       1,     1,     0,     1,     1,     1,     1,     1,     1,     1,
-       1,     1,     0,     2
+       0,     2,     4,     0,     2,     1,     1,     1,     3,     2,
+       1,     2,     2,     2,     1,     2,     2,     2,     1,     1,
+       2,     0,     3,     1,     2,     2,     1,     1,     1,     2,
+       1,     2,     1,     1,     2,     3,     1,     1,     2,     3,
+       1,     1,     0,     1,     3,     0,     3,     0,     3,     2,
+       2,     1,     1,     1,     1,     0,     1,     0,     1,     1,
+       2,     1,     1,     1,     1,     1,     1,     1,     2,     3,
+       1,     2,     3,     0,     1,     0,     1,     1,     1,     2,
+       3,     1,     2,     2,     1,     1,     2,     3,     1,     2,
+       1,     2,     1,     2,     2,     0,     5,     1,     3,     2,
+       0,     3,     4,     2,     2,     3,     3,     3,     3,     3,
+       0,     1,     1,     0,     1,     1,     1,     1,     1,     1,
+       1,     1,     1,     0,     2
 };
 
 
@@ -1087,14 +1094,14 @@ tron (yyo);
          { fputs (((*yyvaluep).PERCENT_ERROR_VERBOSE), yyo); }
         break;
 
-    case YYSYMBOL_PERCENT_FLAG: /* "%<flag>"  */
-         { fprintf (yyo, "%%%s", ((*yyvaluep).PERCENT_FLAG)); }
-        break;
-
     case YYSYMBOL_PERCENT_FILE_PREFIX: /* "%file-prefix"  */
          { fputs (((*yyvaluep).PERCENT_FILE_PREFIX), yyo); }
         break;
 
+    case YYSYMBOL_PERCENT_FLAG: /* "%<flag>"  */
+         { fprintf (yyo, "%%%s", ((*yyvaluep).PERCENT_FLAG)); }
+        break;
+
     case YYSYMBOL_PERCENT_NAME_PREFIX: /* "%name-prefix"  */
          { fputs (((*yyvaluep).PERCENT_NAME_PREFIX), yyo); }
         break;
@@ -1162,10 +1169,14 @@ tron (yyo);
          { fprintf (yyo, "%s", code_props_type_string (((*yyvaluep).code_props_type))); }
         break;
 
-    case YYSYMBOL_74_tag_opt: /* tag.opt  */
+    case YYSYMBOL_74_string_opt: /* string.opt  */
          { fputs (((*yyvaluep).yykind_74), yyo); }
         break;
 
+    case YYSYMBOL_75_tag_opt: /* tag.opt  */
+         { fputs (((*yyvaluep).yykind_75), yyo); }
+        break;
+
     case YYSYMBOL_generic_symlist: /* generic_symlist  */
          { symbol_list_syms_print (((*yyvaluep).generic_symlist), yyo); }
         break;
@@ -1186,16 +1197,16 @@ tron (yyo);
          { symbol_list_syms_print (((*yyvaluep).token_decls), yyo); }
         break;
 
-    case YYSYMBOL_80_token_decl_1: /* token_decl.1  */
-         { symbol_list_syms_print (((*yyvaluep).yykind_80), yyo); }
+    case YYSYMBOL_81_token_decl_1: /* token_decl.1  */
+         { symbol_list_syms_print (((*yyvaluep).yykind_81), yyo); }
         break;
 
     case YYSYMBOL_token_decl: /* token_decl  */
          { fprintf (yyo, "%s", ((*yyvaluep).token_decl) ? ((*yyvaluep).token_decl)->tag : "<NULL>"); }
         break;
 
-    case YYSYMBOL_82_int_opt: /* int.opt  */
-         { fprintf (yyo, "%d", ((*yyvaluep).yykind_82)); }
+    case YYSYMBOL_83_int_opt: /* int.opt  */
+         { fprintf (yyo, "%d", ((*yyvaluep).yykind_83)); }
         break;
 
     case YYSYMBOL_alias: /* alias  */
@@ -1206,8 +1217,8 @@ tron (yyo);
          { symbol_list_syms_print (((*yyvaluep).token_decls_for_prec), yyo); }
         break;
 
-    case YYSYMBOL_85_token_decl_for_prec_1: /* token_decl_for_prec.1  */
-         { symbol_list_syms_print (((*yyvaluep).yykind_85), yyo); }
+    case YYSYMBOL_86_token_decl_for_prec_1: /* token_decl_for_prec.1  */
+         { symbol_list_syms_print (((*yyvaluep).yykind_86), yyo); }
         break;
 
     case YYSYMBOL_token_decl_for_prec: /* token_decl_for_prec  */
@@ -1218,8 +1229,8 @@ tron (yyo);
          { symbol_list_syms_print (((*yyvaluep).symbol_decls), yyo); }
         break;
 
-    case YYSYMBOL_88_symbol_decl_1: /* symbol_decl.1  */
-         { symbol_list_syms_print (((*yyvaluep).yykind_88), yyo); }
+    case YYSYMBOL_89_symbol_decl_1: /* symbol_decl.1  */
+         { symbol_list_syms_print (((*yyvaluep).yykind_89), yyo); }
         break;
 
     case YYSYMBOL_variable: /* variable  */
@@ -1715,24 +1726,24 @@ yydestruct (const char *yymsg,
             { symbol_list_free (((*yyvaluep).token_decls)); }
         break;
 
-    case YYSYMBOL_80_token_decl_1: /* token_decl.1  */
-            { symbol_list_free (((*yyvaluep).yykind_80)); }
+    case YYSYMBOL_81_token_decl_1: /* token_decl.1  */
+            { symbol_list_free (((*yyvaluep).yykind_81)); }
         break;
 
     case YYSYMBOL_token_decls_for_prec: /* token_decls_for_prec  */
             { symbol_list_free (((*yyvaluep).token_decls_for_prec)); }
         break;
 
-    case YYSYMBOL_85_token_decl_for_prec_1: /* token_decl_for_prec.1  */
-            { symbol_list_free (((*yyvaluep).yykind_85)); }
+    case YYSYMBOL_86_token_decl_for_prec_1: /* token_decl_for_prec.1  */
+            { symbol_list_free (((*yyvaluep).yykind_86)); }
         break;
 
     case YYSYMBOL_symbol_decls: /* symbol_decls  */
             { symbol_list_free (((*yyvaluep).symbol_decls)); }
         break;
 
-    case YYSYMBOL_88_symbol_decl_1: /* symbol_decl.1  */
-            { symbol_list_free (((*yyvaluep).yykind_88)); }
+    case YYSYMBOL_89_symbol_decl_1: /* symbol_decl.1  */
+            { symbol_list_free (((*yyvaluep).yykind_89)); }
         break;
 
       default:
@@ -2074,115 +2085,111 @@ yyreduce:
     }
     break;
 
-  case 9: /* prologue_declaration: "%defines"  */
-                                   { header_flag = true; }
-    break;
-
-  case 10: /* prologue_declaration: "%defines" "string"  */
-                                   { handle_defines ((yyvsp[0].STRING)); }
+  case 9: /* prologue_declaration: "%header" string.opt  */
+                                   { handle_header ((yyvsp[0].yykind_74)); }
     break;
 
-  case 11: /* prologue_declaration: "%error-verbose"  */
+  case 10: /* prologue_declaration: "%error-verbose"  */
                                    { handle_error_verbose (&(yyloc), (yyvsp[0].PERCENT_ERROR_VERBOSE)); }
     break;
 
-  case 12: /* prologue_declaration: "%expect" "integer literal"  */
+  case 11: /* prologue_declaration: "%expect" "integer literal"  */
                                    { expected_sr_conflicts = (yyvsp[0].INT_LITERAL); }
     break;
 
-  case 13: /* prologue_declaration: "%expect-rr" "integer literal"  */
+  case 12: /* prologue_declaration: "%expect-rr" "integer literal"  */
                                    { expected_rr_conflicts = (yyvsp[0].INT_LITERAL); }
     break;
 
-  case 14: /* prologue_declaration: "%file-prefix" "string"  */
+  case 13: /* prologue_declaration: "%file-prefix" "string"  */
                                    { handle_file_prefix (&(yyloc), &(yylsp[-1]), (yyvsp[-1].PERCENT_FILE_PREFIX), (yyvsp[0].STRING)); }
     break;
 
-  case 15: /* prologue_declaration: "%glr-parser"  */
+  case 14: /* prologue_declaration: "%glr-parser"  */
     {
       nondeterministic_parser = true;
       glr_parser = true;
     }
     break;
 
-  case 16: /* prologue_declaration: "%initial-action" "{...}"  */
+  case 15: /* prologue_declaration: "%initial-action" "{...}"  */
     {
       muscle_code_grow ("initial_action", translate_code ((yyvsp[0].BRACED_CODE), (yylsp[0]), false), (yylsp[0]));
       code_scanner_last_string_free ();
     }
     break;
 
-  case 17: /* prologue_declaration: "%language" "string"  */
+  case 16: /* prologue_declaration: "%language" "string"  */
                                 { handle_language (&(yylsp[-1]), (yyvsp[0].STRING)); }
     break;
 
-  case 18: /* prologue_declaration: "%name-prefix" "string"  */
+  case 17: /* prologue_declaration: "%name-prefix" "string"  */
                                 { handle_name_prefix (&(yyloc), (yyvsp[-1].PERCENT_NAME_PREFIX), (yyvsp[0].STRING)); }
     break;
 
-  case 19: /* prologue_declaration: "%no-lines"  */
+  case 18: /* prologue_declaration: "%no-lines"  */
                                 { no_lines_flag = true; }
     break;
 
-  case 20: /* prologue_declaration: "%nondeterministic-parser"  */
+  case 19: /* prologue_declaration: "%nondeterministic-parser"  */
                                 { nondeterministic_parser = true; }
     break;
 
-  case 21: /* prologue_declaration: "%output" "string"  */
+  case 20: /* prologue_declaration: "%output" "string"  */
                                 { spec_outfile = unquote ((yyvsp[0].STRING)); gram_scanner_last_string_free (); }
     break;
 
-  case 22: /* $@1: %empty  */
+  case 21: /* $@1: %empty  */
            { current_param = (yyvsp[0].PERCENT_PARAM); }
     break;
 
-  case 23: /* prologue_declaration: "%param" $@1 params  */
+  case 22: /* prologue_declaration: "%param" $@1 params  */
                                           { current_param = param_none; }
     break;
 
-  case 24: /* prologue_declaration: "%pure-parser"  */
+  case 23: /* prologue_declaration: "%pure-parser"  */
                                 { handle_pure_parser (&(yyloc), (yyvsp[0].PERCENT_PURE_PARSER)); }
     break;
 
-  case 25: /* prologue_declaration: "%require" "string"  */
+  case 24: /* prologue_declaration: "%require" "string"  */
                                 { handle_require (&(yylsp[0]), (yyvsp[0].STRING)); }
     break;
 
-  case 26: /* prologue_declaration: "%skeleton" "string"  */
+  case 25: /* prologue_declaration: "%skeleton" "string"  */
                                 { handle_skeleton (&(yylsp[0]), (yyvsp[0].STRING)); }
     break;
 
-  case 27: /* prologue_declaration: "%token-table"  */
+  case 26: /* prologue_declaration: "%token-table"  */
                                 { token_table_flag = true; }
     break;
 
-  case 28: /* prologue_declaration: "%verbose"  */
+  case 27: /* prologue_declaration: "%verbose"  */
                                 { report_flag |= report_states; }
     break;
 
-  case 29: /* prologue_declaration: "%yacc"  */
+  case 28: /* prologue_declaration: "%yacc"  */
                                 { handle_yacc (&(yyloc)); }
     break;
 
-  case 30: /* prologue_declaration: error ";"  */
+  case 29: /* prologue_declaration: error ";"  */
                                 { current_class = unknown_sym; yyerrok; }
     break;
 
-  case 32: /* params: params "{...}"  */
+  case 31: /* params: params "{...}"  */
                    { add_param (current_param, (yyvsp[0].BRACED_CODE), (yylsp[0])); }
     break;
 
-  case 33: /* params: "{...}"  */
+  case 32: /* params: "{...}"  */
                    { add_param (current_param, (yyvsp[0].BRACED_CODE), (yylsp[0])); }
     break;
 
-  case 35: /* grammar_declaration: "%start" symbol  */
+  case 34: /* grammar_declaration: "%start" symbol  */
     {
       grammar_start_symbol_set ((yyvsp[0].symbol), (yylsp[0]));
     }
     break;
 
-  case 36: /* grammar_declaration: code_props_type "{...}" generic_symlist  */
+  case 35: /* grammar_declaration: code_props_type "{...}" generic_symlist  */
     {
       code_props code;
       code_props_symbol_action_init (&code, (yyvsp[-1].BRACED_CODE), (yylsp[-1]));
@@ -2195,19 +2202,19 @@ yyreduce:
     }
     break;
 
-  case 37: /* grammar_declaration: "%default-prec"  */
+  case 36: /* grammar_declaration: "%default-prec"  */
     {
       default_prec = true;
     }
     break;
 
-  case 38: /* grammar_declaration: "%no-default-prec"  */
+  case 37: /* grammar_declaration: "%no-default-prec"  */
     {
       default_prec = false;
     }
     break;
 
-  case 39: /* grammar_declaration: "%code" "{...}"  */
+  case 38: /* grammar_declaration: "%code" "{...}"  */
     {
       /* Do not invoke muscle_percent_code_grow here since it invokes
          muscle_user_name_list_grow.  */
@@ -2217,32 +2224,32 @@ yyreduce:
     }
     break;
 
-  case 40: /* grammar_declaration: "%code" "identifier" "{...}"  */
+  case 39: /* grammar_declaration: "%code" "identifier" "{...}"  */
     {
       muscle_percent_code_grow ((yyvsp[-1].ID), (yylsp[-1]), translate_code_braceless ((yyvsp[0].BRACED_CODE), (yylsp[0])), (yylsp[0]));
       code_scanner_last_string_free ();
     }
     break;
 
-  case 41: /* code_props_type: "%destructor"  */
+  case 40: /* code_props_type: "%destructor"  */
                  { (yyval.code_props_type) = destructor; }
     break;
 
-  case 42: /* code_props_type: "%printer"  */
+  case 41: /* code_props_type: "%printer"  */
                  { (yyval.code_props_type) = printer; }
     break;
 
-  case 43: /* union_name: %empty  */
+  case 42: /* union_name: %empty  */
          {}
     break;
 
-  case 44: /* union_name: "identifier"  */
+  case 43: /* union_name: "identifier"  */
          { muscle_percent_define_insert ("api.value.union.name",
                                          (yylsp[0]), muscle_keyword, (yyvsp[0].ID),
                                          MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE); }
     break;
 
-  case 45: /* grammar_declaration: "%union" union_name "{...}"  */
+  case 44: /* grammar_declaration: "%union" union_name "{...}"  */
     {
       union_seen = true;
       muscle_code_grow ("union_members", translate_code_braceless ((yyvsp[0].BRACED_CODE), (yylsp[0])), (yylsp[0]));
@@ -2250,35 +2257,35 @@ yyreduce:
     }
     break;
 
-  case 46: /* $@2: %empty  */
+  case 45: /* $@2: %empty  */
            { current_class = nterm_sym; }
     break;
 
-  case 47: /* symbol_declaration: "%nterm" $@2 nterm_decls  */
+  case 46: /* symbol_declaration: "%nterm" $@2 nterm_decls  */
     {
       current_class = unknown_sym;
       symbol_list_free ((yyvsp[0].nterm_decls));
     }
     break;
 
-  case 48: /* $@3: %empty  */
+  case 47: /* $@3: %empty  */
            { current_class = token_sym; }
     break;
 
-  case 49: /* symbol_declaration: "%token" $@3 token_decls  */
+  case 48: /* symbol_declaration: "%token" $@3 token_decls  */
     {
       current_class = unknown_sym;
       symbol_list_free ((yyvsp[0].token_decls));
     }
     break;
 
-  case 50: /* symbol_declaration: "%type" symbol_decls  */
+  case 49: /* symbol_declaration: "%type" symbol_decls  */
     {
       symbol_list_free ((yyvsp[0].symbol_decls));
     }
     break;
 
-  case 51: /* symbol_declaration: precedence_declarator token_decls_for_prec  */
+  case 50: /* symbol_declaration: precedence_declarator token_decls_for_prec  */
     {
       ++current_prec;
       for (symbol_list *list = (yyvsp[0].token_decls_for_prec); list; list = list->next)
@@ -2287,100 +2294,108 @@ yyreduce:
     }
     break;
 
-  case 52: /* precedence_declarator: "%left"  */
+  case 51: /* precedence_declarator: "%left"  */
                 { (yyval.precedence_declarator) = left_assoc; }
     break;
 
-  case 53: /* precedence_declarator: "%right"  */
+  case 52: /* precedence_declarator: "%right"  */
                 { (yyval.precedence_declarator) = right_assoc; }
     break;
 
-  case 54: /* precedence_declarator: "%nonassoc"  */
+  case 53: /* precedence_declarator: "%nonassoc"  */
                 { (yyval.precedence_declarator) = non_assoc; }
     break;
 
-  case 55: /* precedence_declarator: "%precedence"  */
+  case 54: /* precedence_declarator: "%precedence"  */
                 { (yyval.precedence_declarator) = precedence_assoc; }
     break;
 
-  case 56: /* tag.opt: %empty  */
-         { (yyval.yykind_74) = NULL; }
+  case 55: /* string.opt: %empty  */
+          { (yyval.yykind_74) = NULL; }
+    break;
+
+  case 56: /* string.opt: "string"  */
+          { (yyval.yykind_74) = (yyvsp[0].STRING); }
     break;
 
-  case 57: /* tag.opt: "<tag>"  */
-         { (yyval.yykind_74) = (yyvsp[0].TAG); }
+  case 57: /* tag.opt: %empty  */
+         { (yyval.yykind_75) = NULL; }
     break;
 
-  case 59: /* generic_symlist: generic_symlist generic_symlist_item  */
+  case 58: /* tag.opt: "<tag>"  */
+         { (yyval.yykind_75) = (yyvsp[0].TAG); }
+    break;
+
+  case 60: /* generic_symlist: generic_symlist generic_symlist_item  */
                                          { (yyval.generic_symlist) = symbol_list_append ((yyvsp[-1].generic_symlist), (yyvsp[0].generic_symlist_item)); }
     break;
 
-  case 60: /* generic_symlist_item: symbol  */
+  case 61: /* generic_symlist_item: symbol  */
             { (yyval.generic_symlist_item) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
     break;
 
-  case 61: /* generic_symlist_item: tag  */
+  case 62: /* generic_symlist_item: tag  */
             { (yyval.generic_symlist_item) = symbol_list_type_new ((yyvsp[0].tag), (yylsp[0])); }
     break;
 
-  case 63: /* tag: "<*>"  */
+  case 64: /* tag: "<*>"  */
         { (yyval.tag) = uniqstr_new ("*"); }
     break;
 
-  case 64: /* tag: "<>"  */
+  case 65: /* tag: "<>"  */
         { (yyval.tag) = uniqstr_new (""); }
     break;
 
-  case 66: /* token_decls: token_decl.1  */
+  case 67: /* token_decls: token_decl.1  */
     {
-      (yyval.token_decls) = (yyvsp[0].yykind_80);
+      (yyval.token_decls) = (yyvsp[0].yykind_81);
     }
     break;
 
-  case 67: /* token_decls: "<tag>" token_decl.1  */
+  case 68: /* token_decls: "<tag>" token_decl.1  */
     {
-      (yyval.token_decls) = symbol_list_type_set ((yyvsp[0].yykind_80), (yyvsp[-1].TAG));
+      (yyval.token_decls) = symbol_list_type_set ((yyvsp[0].yykind_81), (yyvsp[-1].TAG));
     }
     break;
 
-  case 68: /* token_decls: token_decls "<tag>" token_decl.1  */
+  case 69: /* token_decls: token_decls "<tag>" token_decl.1  */
     {
-      (yyval.token_decls) = symbol_list_append ((yyvsp[-2].token_decls), symbol_list_type_set ((yyvsp[0].yykind_80), (yyvsp[-1].TAG)));
+      (yyval.token_decls) = symbol_list_append ((yyvsp[-2].token_decls), symbol_list_type_set ((yyvsp[0].yykind_81), (yyvsp[-1].TAG)));
     }
     break;
 
-  case 69: /* token_decl.1: token_decl  */
-                            { (yyval.yykind_80) = symbol_list_sym_new ((yyvsp[0].token_decl), (yylsp[0])); }
+  case 70: /* token_decl.1: token_decl  */
+                            { (yyval.yykind_81) = symbol_list_sym_new ((yyvsp[0].token_decl), (yylsp[0])); }
     break;
 
-  case 70: /* token_decl.1: token_decl.1 token_decl  */
-                            { (yyval.yykind_80) = symbol_list_append ((yyvsp[-1].yykind_80), symbol_list_sym_new ((yyvsp[0].token_decl), (yylsp[0]))); }
+  case 71: /* token_decl.1: token_decl.1 token_decl  */
+                            { (yyval.yykind_81) = symbol_list_append ((yyvsp[-1].yykind_81), symbol_list_sym_new ((yyvsp[0].token_decl), (yylsp[0]))); }
     break;
 
-  case 71: /* token_decl: id int.opt alias  */
+  case 72: /* token_decl: id int.opt alias  */
     {
       (yyval.token_decl) = (yyvsp[-2].id);
       symbol_class_set ((yyvsp[-2].id), current_class, (yylsp[-2]), true);
-      if (0 <= (yyvsp[-1].yykind_82))
-        symbol_code_set ((yyvsp[-2].id), (yyvsp[-1].yykind_82), (yylsp[-1]));
+      if (0 <= (yyvsp[-1].yykind_83))
+        symbol_code_set ((yyvsp[-2].id), (yyvsp[-1].yykind_83), (yylsp[-1]));
       if ((yyvsp[0].alias))
         symbol_make_alias ((yyvsp[-2].id), (yyvsp[0].alias), (yylsp[0]));
     }
     break;
 
-  case 72: /* int.opt: %empty  */
-          { (yyval.yykind_82) = -1; }
+  case 73: /* int.opt: %empty  */
+          { (yyval.yykind_83) = -1; }
     break;
 
-  case 74: /* alias: %empty  */
+  case 75: /* alias: %empty  */
                  { (yyval.alias) = NULL; }
     break;
 
-  case 75: /* alias: string_as_id  */
+  case 76: /* alias: string_as_id  */
                  { (yyval.alias) = (yyvsp[0].string_as_id); }
     break;
 
-  case 76: /* alias: "translatable string"  */
+  case 77: /* alias: "translatable string"  */
     {
       (yyval.alias) = symbol_get ((yyvsp[0].TSTRING), (yylsp[0]));
       symbol_class_set ((yyval.alias), token_sym, (yylsp[0]), false);
@@ -2388,168 +2403,168 @@ yyreduce:
     }
     break;
 
-  case 77: /* token_decls_for_prec: token_decl_for_prec.1  */
+  case 78: /* token_decls_for_prec: token_decl_for_prec.1  */
     {
-      (yyval.token_decls_for_prec) = (yyvsp[0].yykind_85);
+      (yyval.token_decls_for_prec) = (yyvsp[0].yykind_86);
     }
     break;
 
-  case 78: /* token_decls_for_prec: "<tag>" token_decl_for_prec.1  */
+  case 79: /* token_decls_for_prec: "<tag>" token_decl_for_prec.1  */
     {
-      (yyval.token_decls_for_prec) = symbol_list_type_set ((yyvsp[0].yykind_85), (yyvsp[-1].TAG));
+      (yyval.token_decls_for_prec) = symbol_list_type_set ((yyvsp[0].yykind_86), (yyvsp[-1].TAG));
     }
     break;
 
-  case 79: /* token_decls_for_prec: token_decls_for_prec "<tag>" token_decl_for_prec.1  */
+  case 80: /* token_decls_for_prec: token_decls_for_prec "<tag>" token_decl_for_prec.1  */
     {
-      (yyval.token_decls_for_prec) = symbol_list_append ((yyvsp[-2].token_decls_for_prec), symbol_list_type_set ((yyvsp[0].yykind_85), (yyvsp[-1].TAG)));
+      (yyval.token_decls_for_prec) = symbol_list_append ((yyvsp[-2].token_decls_for_prec), symbol_list_type_set ((yyvsp[0].yykind_86), (yyvsp[-1].TAG)));
     }
     break;
 
-  case 80: /* token_decl_for_prec.1: token_decl_for_prec  */
-    { (yyval.yykind_85) = symbol_list_sym_new ((yyvsp[0].token_decl_for_prec), (yylsp[0])); }
+  case 81: /* token_decl_for_prec.1: token_decl_for_prec  */
+    { (yyval.yykind_86) = symbol_list_sym_new ((yyvsp[0].token_decl_for_prec), (yylsp[0])); }
     break;
 
-  case 81: /* token_decl_for_prec.1: token_decl_for_prec.1 token_decl_for_prec  */
-    { (yyval.yykind_85) = symbol_list_append ((yyvsp[-1].yykind_85), symbol_list_sym_new ((yyvsp[0].token_decl_for_prec), (yylsp[0]))); }
+  case 82: /* token_decl_for_prec.1: token_decl_for_prec.1 token_decl_for_prec  */
+    { (yyval.yykind_86) = symbol_list_append ((yyvsp[-1].yykind_86), symbol_list_sym_new ((yyvsp[0].token_decl_for_prec), (yylsp[0]))); }
     break;
 
-  case 82: /* token_decl_for_prec: id int.opt  */
+  case 83: /* token_decl_for_prec: id int.opt  */
     {
       (yyval.token_decl_for_prec) = (yyvsp[-1].id);
       symbol_class_set ((yyvsp[-1].id), token_sym, (yylsp[-1]), false);
-      if (0 <= (yyvsp[0].yykind_82))
-        symbol_code_set ((yyvsp[-1].id), (yyvsp[0].yykind_82), (yylsp[0]));
+      if (0 <= (yyvsp[0].yykind_83))
+        symbol_code_set ((yyvsp[-1].id), (yyvsp[0].yykind_83), (yylsp[0]));
     }
     break;
 
-  case 84: /* symbol_decls: symbol_decl.1  */
+  case 85: /* symbol_decls: symbol_decl.1  */
     {
-      (yyval.symbol_decls) = (yyvsp[0].yykind_88);
+      (yyval.symbol_decls) = (yyvsp[0].yykind_89);
     }
     break;
 
-  case 85: /* symbol_decls: "<tag>" symbol_decl.1  */
+  case 86: /* symbol_decls: "<tag>" symbol_decl.1  */
     {
-      (yyval.symbol_decls) = symbol_list_type_set ((yyvsp[0].yykind_88), (yyvsp[-1].TAG));
+      (yyval.symbol_decls) = symbol_list_type_set ((yyvsp[0].yykind_89), (yyvsp[-1].TAG));
     }
     break;
 
-  case 86: /* symbol_decls: symbol_decls "<tag>" symbol_decl.1  */
+  case 87: /* symbol_decls: symbol_decls "<tag>" symbol_decl.1  */
     {
-      (yyval.symbol_decls) = symbol_list_append ((yyvsp[-2].symbol_decls), symbol_list_type_set ((yyvsp[0].yykind_88), (yyvsp[-1].TAG)));
+      (yyval.symbol_decls) = symbol_list_append ((yyvsp[-2].symbol_decls), symbol_list_type_set ((yyvsp[0].yykind_89), (yyvsp[-1].TAG)));
     }
     break;
 
-  case 87: /* symbol_decl.1: symbol  */
+  case 88: /* symbol_decl.1: symbol  */
     {
       symbol_class_set ((yyvsp[0].symbol), pct_type_sym, (yylsp[0]), false);
-      (yyval.yykind_88) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]));
+      (yyval.yykind_89) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]));
     }
     break;
 
-  case 88: /* symbol_decl.1: symbol_decl.1 symbol  */
+  case 89: /* symbol_decl.1: symbol_decl.1 symbol  */
     {
       symbol_class_set ((yyvsp[0].symbol), pct_type_sym, (yylsp[0]), false);
-      (yyval.yykind_88) = symbol_list_append ((yyvsp[-1].yykind_88), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])));
+      (yyval.yykind_89) = symbol_list_append ((yyvsp[-1].yykind_89), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])));
     }
     break;
 
-  case 93: /* rules_or_grammar_declaration: error ";"  */
+  case 94: /* rules_or_grammar_declaration: error ";"  */
     {
       yyerrok;
     }
     break;
 
-  case 94: /* $@4: %empty  */
-                         { current_lhs ((yyvsp[-1].id_colon), (yylsp[-1]), (yyvsp[0].yykind_95)); }
+  case 95: /* $@4: %empty  */
+                         { current_lhs ((yyvsp[-1].id_colon), (yylsp[-1]), (yyvsp[0].yykind_96)); }
     break;
 
-  case 95: /* rules: id_colon named_ref.opt $@4 ":" rhses.1  */
+  case 96: /* rules: id_colon named_ref.opt $@4 ":" rhses.1  */
     {
       /* Free the current lhs. */
       current_lhs (0, (yylsp[-4]), 0);
     }
     break;
 
-  case 96: /* rhses.1: rhs  */
+  case 97: /* rhses.1: rhs  */
                      { grammar_current_rule_end ((yylsp[0])); }
     break;
 
-  case 97: /* rhses.1: rhses.1 "|" rhs  */
+  case 98: /* rhses.1: rhses.1 "|" rhs  */
                      { grammar_current_rule_end ((yylsp[0])); }
     break;
 
-  case 99: /* rhs: %empty  */
+  case 100: /* rhs: %empty  */
     { grammar_current_rule_begin (current_lhs_symbol, current_lhs_loc,
                                   current_lhs_named_ref); }
     break;
 
-  case 100: /* rhs: rhs symbol named_ref.opt  */
-    { grammar_current_rule_symbol_append ((yyvsp[-1].symbol), (yylsp[-1]), (yyvsp[0].yykind_95)); }
+  case 101: /* rhs: rhs symbol named_ref.opt  */
+    { grammar_current_rule_symbol_append ((yyvsp[-1].symbol), (yylsp[-1]), (yyvsp[0].yykind_96)); }
     break;
 
-  case 101: /* rhs: rhs tag.opt "{...}" named_ref.opt  */
-    { grammar_current_rule_action_append ((yyvsp[-1].BRACED_CODE), (yylsp[-1]), (yyvsp[0].yykind_95), (yyvsp[-2].yykind_74)); }
+  case 102: /* rhs: rhs tag.opt "{...}" named_ref.opt  */
+    { grammar_current_rule_action_append ((yyvsp[-1].BRACED_CODE), (yylsp[-1]), (yyvsp[0].yykind_96), (yyvsp[-2].yykind_75)); }
     break;
 
-  case 102: /* rhs: rhs "%?{...}"  */
+  case 103: /* rhs: rhs "%?{...}"  */
     { grammar_current_rule_predicate_append ((yyvsp[0].BRACED_PREDICATE), (yylsp[0])); }
     break;
 
-  case 103: /* rhs: rhs "%empty"  */
+  case 104: /* rhs: rhs "%empty"  */
     { grammar_current_rule_empty_set ((yylsp[0])); }
     break;
 
-  case 104: /* rhs: rhs "%prec" symbol  */
+  case 105: /* rhs: rhs "%prec" symbol  */
     { grammar_current_rule_prec_set ((yyvsp[0].symbol), (yylsp[0])); }
     break;
 
-  case 105: /* rhs: rhs "%dprec" "integer literal"  */
+  case 106: /* rhs: rhs "%dprec" "integer literal"  */
     { grammar_current_rule_dprec_set ((yyvsp[0].INT_LITERAL), (yylsp[0])); }
     break;
 
-  case 106: /* rhs: rhs "%merge" "<tag>"  */
+  case 107: /* rhs: rhs "%merge" "<tag>"  */
     { grammar_current_rule_merge_set ((yyvsp[0].TAG), (yylsp[0])); }
     break;
 
-  case 107: /* rhs: rhs "%expect" "integer literal"  */
+  case 108: /* rhs: rhs "%expect" "integer literal"  */
     { grammar_current_rule_expect_sr ((yyvsp[0].INT_LITERAL), (yylsp[0])); }
     break;
 
-  case 108: /* rhs: rhs "%expect-rr" "integer literal"  */
+  case 109: /* rhs: rhs "%expect-rr" "integer literal"  */
     { grammar_current_rule_expect_rr ((yyvsp[0].INT_LITERAL), (yylsp[0])); }
     break;
 
-  case 109: /* named_ref.opt: %empty  */
-                 { (yyval.yykind_95) = NULL; }
+  case 110: /* named_ref.opt: %empty  */
+                 { (yyval.yykind_96) = NULL; }
     break;
 
-  case 110: /* named_ref.opt: "[identifier]"  */
-                 { (yyval.yykind_95) = named_ref_new ((yyvsp[0].BRACKETED_ID), (yylsp[0])); }
+  case 111: /* named_ref.opt: "[identifier]"  */
+                 { (yyval.yykind_96) = named_ref_new ((yyvsp[0].BRACKETED_ID), (yylsp[0])); }
     break;
 
-  case 112: /* value: %empty  */
+  case 113: /* value: %empty  */
           { (yyval.value).kind = muscle_keyword; (yyval.value).chars = ""; }
     break;
 
-  case 113: /* value: "identifier"  */
+  case 114: /* value: "identifier"  */
           { (yyval.value).kind = muscle_keyword; (yyval.value).chars = (yyvsp[0].ID); }
     break;
 
-  case 114: /* value: "string"  */
+  case 115: /* value: "string"  */
           { (yyval.value).kind = muscle_string;  (yyval.value).chars = unquote ((yyvsp[0].STRING)); gram_scanner_last_string_free ();}
     break;
 
-  case 115: /* value: "{...}"  */
+  case 116: /* value: "{...}"  */
           { (yyval.value).kind = muscle_code;    (yyval.value).chars = strip_braces ((yyvsp[0].BRACED_CODE)); gram_scanner_last_string_free (); }
     break;
 
-  case 116: /* id: "identifier"  */
+  case 117: /* id: "identifier"  */
     { (yyval.id) = symbol_from_uniqstr ((yyvsp[0].ID), (yylsp[0])); }
     break;
 
-  case 117: /* id: "character literal"  */
+  case 118: /* id: "character literal"  */
     {
       const char *var = "api.token.raw";
       if (current_class == nterm_sym)
@@ -2572,18 +2587,18 @@ yyreduce:
     }
     break;
 
-  case 118: /* id_colon: "identifier:"  */
+  case 119: /* id_colon: "identifier:"  */
            { (yyval.id_colon) = symbol_from_uniqstr ((yyvsp[0].ID_COLON), (yylsp[0])); }
     break;
 
-  case 121: /* string_as_id: "string"  */
+  case 122: /* string_as_id: "string"  */
     {
       (yyval.string_as_id) = symbol_get ((yyvsp[0].STRING), (yylsp[0]));
       symbol_class_set ((yyval.string_as_id), token_sym, (yylsp[0]), false);
     }
     break;
 
-  case 123: /* epilogue.opt: "%%" "epilogue"  */
+  case 124: /* epilogue.opt: "%%" "epilogue"  */
     {
       muscle_code_grow ("epilogue", translate_code ((yyvsp[0].EPILOGUE), (yylsp[0]), true), (yylsp[0]));
       code_scanner_last_string_free ();
@@ -2936,13 +2951,16 @@ add_param (param_type type, char *decl, location loc)
 
 
 static void
-handle_defines (char const *value)
+handle_header (char const *value)
 {
   header_flag = true;
-  char *file = unquote (value);
-  spec_header_file = xstrdup (file);
-  gram_scanner_last_string_free ();
-  unquote_free (file);
+  if (value)
+    {
+      char *file = unquote (value);
+      spec_header_file = xstrdup (file);
+      gram_scanner_last_string_free ();
+      unquote_free (file);
+    }
 }
 
 
