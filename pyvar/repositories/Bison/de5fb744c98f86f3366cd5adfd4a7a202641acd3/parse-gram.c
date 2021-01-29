@@ -99,7 +99,6 @@
 #include "files.h"
 #include "getargs.h"
 #include "gram.h"
-#include "muscle-tab.h"
 #include "named-ref.h"
 #include "quotearg.h"
 #include "reader.h"
@@ -122,7 +121,7 @@ static void gram_error (location const *, char const *);
 /* A string that describes a char (e.g., 'a' -> "'a'").  */
 static char const *char_name (char);
 
-#line 126 "src/parse-gram.c" /* yacc.c:356  */
+#line 125 "src/parse-gram.c" /* yacc.c:356  */
 
 # ifndef YY_NULL
 #  if defined __cplusplus && 201103L <= __cplusplus
@@ -160,7 +159,7 @@ static char const *char_name (char);
 extern int gram_debug;
 #endif
 /* "%code requires" blocks.  */
-#line 219 "src/parse-gram.y" /* yacc.c:372  */
+#line 218 "src/parse-gram.y" /* yacc.c:372  */
 
   typedef enum
   {
@@ -170,8 +169,10 @@ extern int gram_debug;
     param_both   = param_lex | param_parse
   } param_type;
 
+#line 649 "src/parse-gram.y" /* yacc.c:372  */
+#include "muscle-tab.h"
 
-#line 175 "src/parse-gram.c" /* yacc.c:372  */
+#line 176 "src/parse-gram.c" /* yacc.c:372  */
 
 /* Token type.  */
 #ifndef GRAM_TOKENTYPE
@@ -242,31 +243,39 @@ extern int gram_debug;
 typedef union GRAM_STYPE GRAM_STYPE;
 union GRAM_STYPE
 {
-#line 171 "src/parse-gram.y" /* yacc.c:372  */
+#line 170 "src/parse-gram.y" /* yacc.c:372  */
 unsigned char character;
-#line 178 "src/parse-gram.y" /* yacc.c:372  */
+#line 177 "src/parse-gram.y" /* yacc.c:372  */
 
   char *code;
   char const *chars;
 
-#line 189 "src/parse-gram.y" /* yacc.c:372  */
+#line 188 "src/parse-gram.y" /* yacc.c:372  */
 uniqstr uniqstr;
-#line 197 "src/parse-gram.y" /* yacc.c:372  */
+#line 196 "src/parse-gram.y" /* yacc.c:372  */
 int integer;
-#line 201 "src/parse-gram.y" /* yacc.c:372  */
+#line 200 "src/parse-gram.y" /* yacc.c:372  */
 symbol *symbol;
-#line 206 "src/parse-gram.y" /* yacc.c:372  */
+#line 205 "src/parse-gram.y" /* yacc.c:372  */
 assoc assoc;
-#line 209 "src/parse-gram.y" /* yacc.c:372  */
+#line 208 "src/parse-gram.y" /* yacc.c:372  */
 symbol_list *list;
-#line 212 "src/parse-gram.y" /* yacc.c:372  */
+#line 211 "src/parse-gram.y" /* yacc.c:372  */
 named_ref *named_ref;
-#line 239 "src/parse-gram.y" /* yacc.c:372  */
+#line 238 "src/parse-gram.y" /* yacc.c:372  */
 param_type param;
 #line 413 "src/parse-gram.y" /* yacc.c:372  */
 code_props_type code_type;
+#line 651 "src/parse-gram.y" /* yacc.c:372  */
+
+  struct
+  {
+    char const *chars;
+    muscle_kind kind;
+  } value;
+
 
-#line 270 "src/parse-gram.c" /* yacc.c:372  */
+#line 279 "src/parse-gram.c" /* yacc.c:372  */
 };
 # define GRAM_STYPE_IS_TRIVIAL 1
 # define GRAM_STYPE_IS_DECLARED 1
@@ -294,9 +303,9 @@ int gram_parse (void);
 
 /* Copy the second part of user declarations.  */
 
-#line 298 "src/parse-gram.c" /* yacc.c:375  */
+#line 307 "src/parse-gram.c" /* yacc.c:375  */
 /* Unqualified %code blocks.  */
-#line 54 "src/parse-gram.y" /* yacc.c:376  */
+#line 53 "src/parse-gram.y" /* yacc.c:376  */
 
   static int current_prec = 0;
   static location current_lhs_location;
@@ -328,7 +337,7 @@ int gram_parse (void);
   #define YYTYPE_UINT16 uint_fast16_t
   #define YYTYPE_UINT8 uint_fast8_t
 
-#line 229 "src/parse-gram.y" /* yacc.c:376  */
+#line 228 "src/parse-gram.y" /* yacc.c:376  */
 
   /** Add a lex-param and/or a parse-param.
    *
@@ -340,7 +349,7 @@ int gram_parse (void);
   static param_type current_param = param_none;
 
 
-#line 344 "src/parse-gram.c" /* yacc.c:376  */
+#line 353 "src/parse-gram.c" /* yacc.c:376  */
 
 #ifdef short
 # undef short
@@ -514,16 +523,16 @@ union yyalloc
 /* YYFINAL -- State number of the termination state.  */
 #define YYFINAL  3
 /* YYLAST -- Last index in YYTABLE.  */
-#define YYLAST   172
+#define YYLAST   165
 
 /* YYNTOKENS -- Number of terminals.  */
 #define YYNTOKENS  58
 /* YYNNTS -- Number of nonterminals.  */
 #define YYNNTS  38
 /* YYNRULES -- Number of rules.  */
-#define YYNRULES  110
+#define YYNRULES  111
 /* YYNSTATES -- Number of states.  */
-#define YYNSTATES  144
+#define YYNSTATES  145
 
 /* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
    by yylex, with out-of-bounds checking.  */
@@ -575,8 +584,8 @@ static const yytype_uint8 yytranslate[] =
   /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
 static const yytype_uint16 yyrline[] =
 {
-       0,   262,   262,   271,   272,   276,   277,   287,   291,   296,
-     297,   302,   307,   308,   309,   310,   315,   324,   325,   326,
+       0,   261,   261,   270,   271,   275,   276,   286,   290,   295,
+     296,   301,   307,   308,   309,   310,   315,   324,   325,   326,
      327,   328,   329,   329,   330,   331,   355,   356,   357,   358,
      362,   363,   372,   373,   374,   378,   390,   394,   398,   405,
      416,   417,   427,   428,   432,   444,   444,   449,   449,   454,
@@ -584,9 +593,9 @@ static const yytype_uint16 yyrline[] =
      505,   515,   517,   522,   523,   527,   528,   532,   533,   534,
      539,   544,   549,   555,   561,   572,   573,   582,   583,   589,
      590,   591,   598,   598,   606,   607,   608,   613,   616,   618,
-     620,   622,   624,   626,   628,   633,   634,   644,   645,   650,
-     651,   652,   661,   681,   683,   692,   697,   698,   703,   711,
-     712
+     620,   622,   624,   626,   628,   633,   634,   644,   645,   670,
+     671,   672,   673,   682,   702,   704,   713,   718,   719,   724,
+     732,   733
 };
 #endif
 
@@ -615,9 +624,8 @@ static const char *const yytname[] =
   "precedence_declarator", "tag.opt", "symbols.prec", "symbol.prec",
   "symbols.1", "generic_symlist", "generic_symlist_item", "tag",
   "symbol_def", "symbol_defs.1", "grammar", "rules_or_grammar_declaration",
-  "rules", "$@4", "rhses.1", "rhs", "named_ref.opt", "variable",
-  "content.opt", "braceless", "id", "id_colon", "symbol", "string_as_id",
-  "epilogue.opt", YY_NULL
+  "rules", "$@4", "rhses.1", "rhs", "named_ref.opt", "variable", "value",
+  "braceless", "id", "id_colon", "symbol", "string_as_id", "epilogue.opt", YY_NULL
 };
 #endif
 
@@ -635,12 +643,12 @@ static const yytype_uint16 yytoknum[] =
 };
 # endif
 
-#define YYPACT_NINF -104
+#define YYPACT_NINF -115
 
 #define yypact_value_is_default(Yystate) \
-  (!!((Yystate) == (-104)))
+  (!!((Yystate) == (-115)))
 
-#define YYTABLE_NINF -110
+#define YYTABLE_NINF -111
 
 #define yytable_value_is_error(Yytable_value) \
   0
@@ -649,21 +657,21 @@ static const yytype_uint16 yytoknum[] =
      STATE-NUM.  */
 static const yytype_int8 yypact[] =
 {
-    -104,    18,   116,  -104,  -104,  -104,   -26,  -104,  -104,  -104,
-    -104,  -104,  -104,   -16,  -104,    24,    23,  -104,   -18,   -13,
-    -104,    39,  -104,     9,    51,    52,  -104,  -104,  -104,    53,
-      68,    71,    -2,  -104,  -104,  -104,    56,  -104,  -104,  -104,
-      30,  -104,  -104,    37,  -104,  -104,    27,   -21,   -21,    -2,
-    -104,    40,  -104,  -104,  -104,    25,  -104,  -104,  -104,  -104,
-    -104,  -104,  -104,  -104,  -104,  -104,  -104,  -104,  -104,  -104,
-    -104,  -104,    32,  -104,    34,     3,  -104,  -104,    49,    58,
-    -104,    40,    41,  -104,    -2,  -104,  -104,   -21,    -1,   -21,
-      -2,  -104,  -104,  -104,  -104,  -104,  -104,  -104,    55,  -104,
-    -104,  -104,  -104,  -104,    61,  -104,  -104,  -104,  -104,    41,
-    -104,  -104,  -104,    -2,  -104,    26,  -104,    92,  -104,  -104,
-    -104,  -104,  -104,  -104,  -104,  -104,  -104,   -15,    74,  -104,
-    -104,    -2,    47,    54,    49,  -104,  -104,    49,    74,  -104,
-    -104,  -104,  -104,  -104
+    -115,    16,   109,  -115,  -115,  -115,   -28,  -115,  -115,  -115,
+    -115,  -115,  -115,   -14,  -115,    25,    23,  -115,   -27,   -20,
+    -115,    39,  -115,     7,    48,    71,  -115,  -115,  -115,    72,
+      73,    74,    -2,  -115,  -115,  -115,    56,  -115,  -115,  -115,
+      33,  -115,  -115,    40,  -115,  -115,    37,    54,    54,    -2,
+    -115,    50,  -115,  -115,  -115,     2,  -115,  -115,  -115,  -115,
+    -115,  -115,  -115,  -115,  -115,  -115,  -115,  -115,  -115,  -115,
+    -115,  -115,    51,  -115,    53,     3,  -115,  -115,    49,    65,
+    -115,    50,    42,  -115,    -2,  -115,  -115,    54,    -1,    54,
+      -2,  -115,  -115,  -115,  -115,  -115,  -115,  -115,  -115,    63,
+    -115,  -115,  -115,  -115,  -115,    69,  -115,  -115,  -115,  -115,
+      42,  -115,  -115,  -115,    -2,  -115,    38,  -115,   106,  -115,
+    -115,  -115,  -115,  -115,  -115,  -115,  -115,  -115,   -15,    41,
+    -115,  -115,    -2,    57,    59,    49,  -115,  -115,    49,    41,
+    -115,  -115,  -115,  -115,  -115
 };
 
   /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
@@ -676,34 +684,34 @@ static const yytype_uint8 yydefact[] =
        7,     0,    15,     0,     0,     0,    37,    19,    20,     0,
        0,     0,     0,    26,    27,    28,     0,     6,    29,    22,
       42,     4,     5,     0,    33,    32,    55,     0,     0,     0,
-     102,     0,    38,    98,    97,    99,    10,    12,    13,    14,
-      16,    17,    18,    21,    24,    25,   108,   104,   103,   106,
-      34,   107,     0,   105,     0,     0,    77,    79,    95,     0,
+     103,     0,    38,    98,    97,    99,    10,    12,    13,    14,
+      16,    17,    18,    21,    24,    25,   109,   105,   104,   107,
+      34,   108,     0,   106,     0,     0,    77,    79,    95,     0,
       43,     0,     0,    56,     0,    70,    75,    48,    71,    46,
-      49,    61,    39,   101,   100,     8,    81,    80,     0,    78,
-       2,    96,    82,    31,    23,    44,    67,    68,    69,    35,
-      63,    66,    65,    50,    57,    59,    76,    72,    73,    62,
-     110,    87,    30,    64,    58,    60,    74,    83,    84,    87,
-      86,     0,     0,     0,    95,    90,    91,    95,    85,    92,
-      93,    94,    89,    88
+      49,    61,    39,   101,   100,     8,   102,    81,    80,     0,
+      78,     2,    96,    82,    31,    23,    44,    67,    68,    69,
+      35,    63,    66,    65,    50,    57,    59,    76,    72,    73,
+      62,   111,    87,    30,    64,    58,    60,    74,    83,    84,
+      87,    86,     0,     0,     0,    95,    90,    91,    95,    85,
+      92,    93,    94,    89,    88
 };
 
   /* YYPGOTO[NTERM-NUM].  */
 static const yytype_int8 yypgoto[] =
 {
-    -104,  -104,  -104,  -104,  -104,  -104,   101,  -104,  -104,  -104,
-    -104,  -104,  -104,  -104,  -104,  -104,    -9,  -104,  -104,     0,
-    -104,   -50,    59,  -104,    33,  -104,  -104,  -104,   -19,  -103,
-    -104,  -104,   -35,   -42,  -104,   -32,   -66,  -104
+    -115,  -115,  -115,  -115,  -115,  -115,   120,  -115,  -115,  -115,
+    -115,  -115,  -115,  -115,  -115,  -115,     9,  -115,  -115,    14,
+    -115,   -50,   100,  -115,    75,  -115,  -115,  -115,    19,  -114,
+    -115,  -115,   -33,   -18,  -115,   -32,   -82,  -115
 };
 
   /* YYDEFGOTO[NTERM-NUM].  */
 static const yytype_int16 yydefgoto[] =
 {
-      -1,     1,     2,    41,    79,   104,    74,    43,    81,    44,
-      48,    47,    45,    46,    84,   113,   114,    90,   109,   110,
-     111,    86,    87,    75,    76,    77,   121,   127,   128,   102,
-      55,    95,    52,    69,    78,   112,    71,   100
+      -1,     1,     2,    41,    79,   105,    74,    43,    81,    44,
+      48,    47,    45,    46,    84,   114,   115,    90,   110,   111,
+     112,    86,    87,    75,    76,    77,   122,   128,   129,   103,
+      55,    95,    52,    69,    78,   113,    71,   101
 };
 
   /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
@@ -711,46 +719,44 @@ static const yytype_int16 yydefgoto[] =
      number is the opposite.  If YYTABLE_NINF, syntax error.  */
 static const yytype_int16 yytable[] =
 {
-      70,    66,    66,  -109,    72,    88,    88,     4,     5,     6,
-       7,     8,     9,    10,    11,    12,    92,    91,     3,    13,
-      14,    67,   118,    50,    68,    49,    56,    53,    93,    51,
-      85,   142,    26,   129,   143,   130,    57,   116,    32,   116,
-      67,    58,    59,    68,    66,    88,   105,    88,    60,    73,
-      98,   126,   115,   117,    61,    62,    63,    72,   119,    40,
-       4,     5,     6,     7,     8,     9,    10,    11,    12,    54,
-      94,    64,    13,    14,    65,    80,    82,    66,    83,    50,
-     125,   115,    96,    67,    97,    26,    68,   131,   132,   133,
-     101,    32,   106,   107,   108,    66,   137,   103,   120,   139,
-     122,   140,    73,    42,   124,   141,   137,    89,    99,   123,
-     138,     0,    40,   134,   135,     0,    67,     0,     0,    68,
-       4,     5,     6,     7,     8,     9,    10,    11,    12,     0,
-       0,   136,    13,    14,    15,    16,    17,    18,    19,    20,
-      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
-      31,    32,    33,    34,    35,     0,     0,     0,     0,     0,
-       0,     0,     0,    36,     0,    37,    38,     0,     0,     0,
-       0,    39,    40
+      70,    66,    66,  -110,    72,    93,   119,     4,     5,     6,
+       7,     8,     9,    10,    11,    12,     3,    91,    92,    13,
+      14,   143,    96,    49,   144,    50,    56,    57,    53,    88,
+      88,    51,    26,   130,    58,   131,   127,   117,    32,   117,
+      67,    50,    59,    68,    66,    66,    60,    94,   106,    73,
+      99,    61,   116,   118,   132,   133,   134,    72,   120,    40,
+       4,     5,     6,     7,     8,     9,    10,    11,    12,    88,
+      54,    88,    13,    14,    62,    63,    64,    65,    80,    82,
+     135,   136,   116,    67,    67,    26,    68,    68,    83,    50,
+     102,    32,   126,   107,   108,   109,    67,   138,   137,    68,
+     140,    97,    73,    98,   104,    85,   121,   138,   123,    66,
+     142,   141,    40,     4,     5,     6,     7,     8,     9,    10,
+      11,    12,    42,   125,   124,    13,    14,    15,    16,    17,
+      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
+      28,    29,    30,    31,    32,    33,    34,    35,    89,   139,
+     100,     0,     0,     0,     0,     0,    36,     0,    37,    38,
+       0,     0,     0,     0,    39,    40
 };
 
 static const yytype_int16 yycheck[] =
 {
-      32,     3,     3,     0,     1,    47,    48,     4,     5,     6,
-       7,     8,     9,    10,    11,    12,    51,    49,     0,    16,
-      17,    42,    88,    39,    45,    51,     3,     3,     3,    45,
-      51,   134,    29,    48,   137,    50,    54,    87,    35,    89,
-      42,    54,     3,    45,     3,    87,    81,    89,    39,    46,
-      47,   117,    84,    54,     3,     3,     3,     1,    90,    56,
-       4,     5,     6,     7,     8,     9,    10,    11,    12,    45,
-      45,     3,    16,    17,     3,    45,    39,     3,    51,    39,
-      54,   113,    50,    42,    50,    29,    45,    13,    14,    15,
-      41,    35,    51,    52,    53,     3,   128,    39,    43,   131,
-      39,    54,    46,     2,   113,    51,   138,    48,    75,   109,
-     129,    -1,    56,    39,    40,    -1,    42,    -1,    -1,    45,
-       4,     5,     6,     7,     8,     9,    10,    11,    12,    -1,
-      -1,    57,    16,    17,    18,    19,    20,    21,    22,    23,
-      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
-      34,    35,    36,    37,    38,    -1,    -1,    -1,    -1,    -1,
-      -1,    -1,    -1,    47,    -1,    49,    50,    -1,    -1,    -1,
-      -1,    55,    56
+      32,     3,     3,     0,     1,     3,    88,     4,     5,     6,
+       7,     8,     9,    10,    11,    12,     0,    49,    51,    16,
+      17,   135,    55,    51,   138,    39,     3,    54,     3,    47,
+      48,    45,    29,    48,    54,    50,   118,    87,    35,    89,
+      42,    39,     3,    45,     3,     3,    39,    45,    81,    46,
+      47,     3,    84,    54,    13,    14,    15,     1,    90,    56,
+       4,     5,     6,     7,     8,     9,    10,    11,    12,    87,
+      45,    89,    16,    17,     3,     3,     3,     3,    45,    39,
+      39,    40,   114,    42,    42,    29,    45,    45,    51,    39,
+      41,    35,    54,    51,    52,    53,    42,   129,    57,    45,
+     132,    50,    46,    50,    39,    51,    43,   139,    39,     3,
+      51,    54,    56,     4,     5,     6,     7,     8,     9,    10,
+      11,    12,     2,   114,   110,    16,    17,    18,    19,    20,
+      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
+      31,    32,    33,    34,    35,    36,    37,    38,    48,   130,
+      75,    -1,    -1,    -1,    -1,    -1,    47,    -1,    49,    50,
+      -1,    -1,    -1,    -1,    55,    56
 };
 
   /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
@@ -766,12 +772,12 @@ static const yytype_uint8 yystos[] =
       39,     3,     3,     3,     3,     3,     3,    42,    45,    91,
       93,    94,     1,    46,    64,    81,    82,    83,    92,    62,
       45,    66,    39,    51,    72,    51,    79,    80,    91,    80,
-      75,    93,    90,     3,    45,    89,    50,    50,    47,    82,
-      95,    41,    87,    39,    63,    90,    51,    52,    53,    76,
-      77,    78,    93,    73,    74,    93,    79,    54,    94,    93,
-      43,    84,    39,    77,    74,    54,    94,    85,    86,    48,
-      50,    13,    14,    15,    39,    40,    57,    93,    86,    93,
-      54,    51,    87,    87
+      75,    93,    90,     3,    45,    89,    90,    50,    50,    47,
+      82,    95,    41,    87,    39,    63,    90,    51,    52,    53,
+      76,    77,    78,    93,    73,    74,    93,    79,    54,    94,
+      93,    43,    84,    39,    77,    74,    54,    94,    85,    86,
+      48,    50,    13,    14,    15,    39,    40,    57,    93,    86,
+      93,    54,    51,    87,    87
 };
 
   /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
@@ -787,8 +793,8 @@ static const yytype_uint8 yyr1[] =
       79,    79,    79,    79,    79,    80,    80,    81,    81,    82,
       82,    82,    84,    83,    85,    85,    85,    86,    86,    86,
       86,    86,    86,    86,    86,    87,    87,    88,    88,    89,
-      89,    89,    90,    91,    91,    92,    93,    93,    94,    95,
-      95
+      89,    89,    89,    90,    91,    91,    92,    93,    93,    94,
+      95,    95
 };
 
   /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
@@ -804,8 +810,8 @@ static const yytype_uint8 yyr2[] =
        1,     1,     2,     2,     3,     1,     2,     1,     2,     1,
        2,     2,     0,     4,     1,     3,     2,     0,     3,     3,
        2,     2,     3,     3,     3,     0,     1,     1,     1,     0,
-       1,     1,     1,     1,     1,     1,     1,     1,     1,     0,
-       2
+       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
+       0,     2
 };
 
 
@@ -961,73 +967,73 @@ yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvalue
   switch (yytype)
     {
     case 3: /* "string"  */
-#line 184 "src/parse-gram.y" /* yacc.c:706  */
+#line 183 "src/parse-gram.y" /* yacc.c:706  */
       { fputs (quotearg_style (c_quoting_style, ((*yyvaluep).chars)), yyo); }
-#line 967 "src/parse-gram.c" /* yacc.c:706  */
+#line 973 "src/parse-gram.c" /* yacc.c:706  */
         break;
 
     case 23: /* "%<flag>"  */
-#line 194 "src/parse-gram.y" /* yacc.c:706  */
+#line 193 "src/parse-gram.y" /* yacc.c:706  */
       { fprintf (yyo, "%%%s", ((*yyvaluep).uniqstr)); }
-#line 973 "src/parse-gram.c" /* yacc.c:706  */
+#line 979 "src/parse-gram.c" /* yacc.c:706  */
         break;
 
     case 39: /* "{...}"  */
-#line 186 "src/parse-gram.y" /* yacc.c:706  */
+#line 185 "src/parse-gram.y" /* yacc.c:706  */
       { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).code)); }
-#line 979 "src/parse-gram.c" /* yacc.c:706  */
+#line 985 "src/parse-gram.c" /* yacc.c:706  */
         break;
 
     case 41: /* "[identifier]"  */
-#line 192 "src/parse-gram.y" /* yacc.c:706  */
+#line 191 "src/parse-gram.y" /* yacc.c:706  */
       { fprintf (yyo, "[%s]", ((*yyvaluep).uniqstr)); }
-#line 985 "src/parse-gram.c" /* yacc.c:706  */
+#line 991 "src/parse-gram.c" /* yacc.c:706  */
         break;
 
     case 42: /* "char"  */
-#line 173 "src/parse-gram.y" /* yacc.c:706  */
+#line 172 "src/parse-gram.y" /* yacc.c:706  */
       { fputs (char_name (((*yyvaluep).character)), yyo); }
-#line 991 "src/parse-gram.c" /* yacc.c:706  */
+#line 997 "src/parse-gram.c" /* yacc.c:706  */
         break;
 
     case 43: /* "epilogue"  */
-#line 186 "src/parse-gram.y" /* yacc.c:706  */
+#line 185 "src/parse-gram.y" /* yacc.c:706  */
       { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).chars)); }
-#line 997 "src/parse-gram.c" /* yacc.c:706  */
+#line 1003 "src/parse-gram.c" /* yacc.c:706  */
         break;
 
     case 45: /* "identifier"  */
-#line 191 "src/parse-gram.y" /* yacc.c:706  */
+#line 190 "src/parse-gram.y" /* yacc.c:706  */
       { fputs (((*yyvaluep).uniqstr), yyo); }
-#line 1003 "src/parse-gram.c" /* yacc.c:706  */
+#line 1009 "src/parse-gram.c" /* yacc.c:706  */
         break;
 
     case 46: /* "identifier:"  */
-#line 193 "src/parse-gram.y" /* yacc.c:706  */
+#line 192 "src/parse-gram.y" /* yacc.c:706  */
       { fprintf (yyo, "%s:", ((*yyvaluep).uniqstr)); }
-#line 1009 "src/parse-gram.c" /* yacc.c:706  */
+#line 1015 "src/parse-gram.c" /* yacc.c:706  */
         break;
 
     case 49: /* "%{...%}"  */
-#line 186 "src/parse-gram.y" /* yacc.c:706  */
+#line 185 "src/parse-gram.y" /* yacc.c:706  */
       { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).chars)); }
-#line 1015 "src/parse-gram.c" /* yacc.c:706  */
+#line 1021 "src/parse-gram.c" /* yacc.c:706  */
         break;
 
     case 51: /* "<tag>"  */
-#line 195 "src/parse-gram.y" /* yacc.c:706  */
+#line 194 "src/parse-gram.y" /* yacc.c:706  */
       { fprintf (yyo, "<%s>", ((*yyvaluep).uniqstr)); }
-#line 1021 "src/parse-gram.c" /* yacc.c:706  */
+#line 1027 "src/parse-gram.c" /* yacc.c:706  */
         break;
 
     case 54: /* "integer"  */
-#line 199 "src/parse-gram.y" /* yacc.c:706  */
+#line 198 "src/parse-gram.y" /* yacc.c:706  */
       { fprintf (yyo, "%d", ((*yyvaluep).integer)); }
-#line 1027 "src/parse-gram.c" /* yacc.c:706  */
+#line 1033 "src/parse-gram.c" /* yacc.c:706  */
         break;
 
     case 55: /* "%param"  */
-#line 242 "src/parse-gram.y" /* yacc.c:706  */
+#line 241 "src/parse-gram.y" /* yacc.c:706  */
       {
   switch (((*yyvaluep).param))
     {
@@ -1040,67 +1046,74 @@ yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvalue
       case param_none: aver (false); break;
     }
 }
-#line 1044 "src/parse-gram.c" /* yacc.c:706  */
+#line 1050 "src/parse-gram.c" /* yacc.c:706  */
         break;
 
     case 65: /* code_props_type  */
 #line 414 "src/parse-gram.y" /* yacc.c:706  */
       { fprintf (yyo, "%s", code_props_type_string (((*yyvaluep).code_type))); }
-#line 1050 "src/parse-gram.c" /* yacc.c:706  */
+#line 1056 "src/parse-gram.c" /* yacc.c:706  */
         break;
 
     case 74: /* symbol.prec  */
-#line 203 "src/parse-gram.y" /* yacc.c:706  */
+#line 202 "src/parse-gram.y" /* yacc.c:706  */
       { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
-#line 1056 "src/parse-gram.c" /* yacc.c:706  */
+#line 1062 "src/parse-gram.c" /* yacc.c:706  */
         break;
 
     case 78: /* tag  */
-#line 195 "src/parse-gram.y" /* yacc.c:706  */
+#line 194 "src/parse-gram.y" /* yacc.c:706  */
       { fprintf (yyo, "<%s>", ((*yyvaluep).uniqstr)); }
-#line 1062 "src/parse-gram.c" /* yacc.c:706  */
+#line 1068 "src/parse-gram.c" /* yacc.c:706  */
         break;
 
     case 88: /* variable  */
-#line 191 "src/parse-gram.y" /* yacc.c:706  */
+#line 190 "src/parse-gram.y" /* yacc.c:706  */
       { fputs (((*yyvaluep).uniqstr), yyo); }
-#line 1068 "src/parse-gram.c" /* yacc.c:706  */
+#line 1074 "src/parse-gram.c" /* yacc.c:706  */
         break;
 
-    case 89: /* content.opt  */
-#line 186 "src/parse-gram.y" /* yacc.c:706  */
-      { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).chars)); }
-#line 1074 "src/parse-gram.c" /* yacc.c:706  */
+    case 89: /* value  */
+#line 660 "src/parse-gram.y" /* yacc.c:706  */
+      {
+  switch (((*yyvaluep).value).kind)
+    {
+    case muscle_code:    fprintf (yyo,  "{%s}",  ((*yyvaluep).value).chars); break;
+    case muscle_keyword: fprintf (yyo,   "%s",   ((*yyvaluep).value).chars); break;
+    case muscle_string:  fprintf (yyo, "\"%s\"", ((*yyvaluep).value).chars); break;
+    }
+}
+#line 1087 "src/parse-gram.c" /* yacc.c:706  */
         break;
 
     case 90: /* braceless  */
-#line 186 "src/parse-gram.y" /* yacc.c:706  */
+#line 185 "src/parse-gram.y" /* yacc.c:706  */
       { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).chars)); }
-#line 1080 "src/parse-gram.c" /* yacc.c:706  */
+#line 1093 "src/parse-gram.c" /* yacc.c:706  */
         break;
 
     case 91: /* id  */
-#line 203 "src/parse-gram.y" /* yacc.c:706  */
+#line 202 "src/parse-gram.y" /* yacc.c:706  */
       { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
-#line 1086 "src/parse-gram.c" /* yacc.c:706  */
+#line 1099 "src/parse-gram.c" /* yacc.c:706  */
         break;
 
     case 92: /* id_colon  */
-#line 204 "src/parse-gram.y" /* yacc.c:706  */
+#line 203 "src/parse-gram.y" /* yacc.c:706  */
       { fprintf (yyo, "%s:", ((*yyvaluep).symbol)->tag); }
-#line 1092 "src/parse-gram.c" /* yacc.c:706  */
+#line 1105 "src/parse-gram.c" /* yacc.c:706  */
         break;
 
     case 93: /* symbol  */
-#line 203 "src/parse-gram.y" /* yacc.c:706  */
+#line 202 "src/parse-gram.y" /* yacc.c:706  */
       { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
-#line 1098 "src/parse-gram.c" /* yacc.c:706  */
+#line 1111 "src/parse-gram.c" /* yacc.c:706  */
         break;
 
     case 94: /* string_as_id  */
-#line 203 "src/parse-gram.y" /* yacc.c:706  */
+#line 202 "src/parse-gram.y" /* yacc.c:706  */
       { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
-#line 1104 "src/parse-gram.c" /* yacc.c:706  */
+#line 1117 "src/parse-gram.c" /* yacc.c:706  */
         break;
 
       default:
@@ -1815,14 +1828,14 @@ YYLTYPE yylloc = yyloc_default;
   yychar = YYEMPTY; /* Cause a token to be read.  */
 
 /* User initialization code.  */
-#line 97 "src/parse-gram.y" /* yacc.c:1451  */
+#line 96 "src/parse-gram.y" /* yacc.c:1451  */
 {
   /* Bison's grammar can initial empty locations, hence a default
      location is needed. */
   boundary_set (&yylloc.start, current_file, 1, 1);
   boundary_set (&yylloc.end, current_file, 1, 1);
 }
-#line 1826 "src/parse-gram.c" /* yacc.c:1451  */
+#line 1839 "src/parse-gram.c" /* yacc.c:1451  */
   yylsp[0] = yylloc;
   goto yysetstate;
 
@@ -2016,7 +2029,7 @@ yyreduce:
     switch (yyn)
       {
           case 6:
-#line 278 "src/parse-gram.y" /* yacc.c:1668  */
+#line 277 "src/parse-gram.y" /* yacc.c:1668  */
     {
       code_props plain_code;
       code_props_plain_init (&plain_code, (yyvsp[0].chars), (yylsp[0]));
@@ -2026,66 +2039,67 @@ yyreduce:
                         plain_code.code, (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2030 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2043 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 7:
-#line 288 "src/parse-gram.y" /* yacc.c:1668  */
+#line 287 "src/parse-gram.y" /* yacc.c:1668  */
     {
       muscle_percent_define_ensure ((yyvsp[0].uniqstr), (yylsp[0]), true);
     }
-#line 2038 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2051 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 8:
-#line 292 "src/parse-gram.y" /* yacc.c:1668  */
+#line 291 "src/parse-gram.y" /* yacc.c:1668  */
     {
-      muscle_percent_define_insert ((yyvsp[-1].uniqstr), (yylsp[-1]), (yyvsp[0].chars),
+      muscle_percent_define_insert ((yyvsp[-1].uniqstr), (yylsp[-1]), (yyvsp[0].value).kind, (yyvsp[0].value).chars,
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
     }
-#line 2047 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2060 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 9:
-#line 296 "src/parse-gram.y" /* yacc.c:1668  */
+#line 295 "src/parse-gram.y" /* yacc.c:1668  */
     { defines_flag = true; }
-#line 2053 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2066 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 10:
-#line 298 "src/parse-gram.y" /* yacc.c:1668  */
+#line 297 "src/parse-gram.y" /* yacc.c:1668  */
     {
       defines_flag = true;
       spec_defines_file = xstrdup ((yyvsp[0].chars));
     }
-#line 2062 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2075 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 11:
-#line 303 "src/parse-gram.y" /* yacc.c:1668  */
+#line 302 "src/parse-gram.y" /* yacc.c:1668  */
     {
-      muscle_percent_define_insert ("parse.error", (yylsp[0]), "verbose",
+      muscle_percent_define_insert ("parse.error", (yylsp[0]), muscle_keyword,
+                                    "verbose",
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
     }
-#line 2071 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2085 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 12:
 #line 307 "src/parse-gram.y" /* yacc.c:1668  */
     { expected_sr_conflicts = (yyvsp[0].integer); }
-#line 2077 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2091 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 13:
 #line 308 "src/parse-gram.y" /* yacc.c:1668  */
     { expected_rr_conflicts = (yyvsp[0].integer); }
-#line 2083 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2097 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 14:
 #line 309 "src/parse-gram.y" /* yacc.c:1668  */
     { spec_file_prefix = (yyvsp[0].chars); }
-#line 2089 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2103 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 15:
@@ -2094,7 +2108,7 @@ yyreduce:
       nondeterministic_parser = true;
       glr_parser = true;
     }
-#line 2098 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2112 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 16:
@@ -2107,55 +2121,55 @@ yyreduce:
       muscle_code_grow ("initial_action", action.code, (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2111 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2125 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 17:
 #line 324 "src/parse-gram.y" /* yacc.c:1668  */
     { language_argmatch ((yyvsp[0].chars), grammar_prio, (yylsp[-1])); }
-#line 2117 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2131 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 18:
 #line 325 "src/parse-gram.y" /* yacc.c:1668  */
     { spec_name_prefix = (yyvsp[0].chars); }
-#line 2123 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2137 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 19:
 #line 326 "src/parse-gram.y" /* yacc.c:1668  */
     { no_lines_flag = true; }
-#line 2129 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2143 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 20:
 #line 327 "src/parse-gram.y" /* yacc.c:1668  */
     { nondeterministic_parser = true; }
-#line 2135 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2149 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 21:
 #line 328 "src/parse-gram.y" /* yacc.c:1668  */
     { spec_outfile = (yyvsp[0].chars); }
-#line 2141 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2155 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 22:
 #line 329 "src/parse-gram.y" /* yacc.c:1668  */
     { current_param = (yyvsp[0].param); }
-#line 2147 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2161 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 23:
 #line 329 "src/parse-gram.y" /* yacc.c:1668  */
     { current_param = param_none; }
-#line 2153 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2167 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 24:
 #line 330 "src/parse-gram.y" /* yacc.c:1668  */
     { version_check (&(yylsp[0]), (yyvsp[0].chars)); }
-#line 2159 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2173 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 25:
@@ -2183,37 +2197,37 @@ yyreduce:
         }
       skeleton_arg (skeleton_user, grammar_prio, (yylsp[-1]));
     }
-#line 2187 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2201 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 26:
 #line 355 "src/parse-gram.y" /* yacc.c:1668  */
     { token_table_flag = true; }
-#line 2193 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2207 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 27:
 #line 356 "src/parse-gram.y" /* yacc.c:1668  */
     { report_flag |= report_states; }
-#line 2199 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2213 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 28:
 #line 357 "src/parse-gram.y" /* yacc.c:1668  */
     { yacc_flag = true; }
-#line 2205 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2219 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 30:
 #line 362 "src/parse-gram.y" /* yacc.c:1668  */
     { add_param (current_param, (yyvsp[0].code), (yylsp[0])); }
-#line 2211 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2225 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 31:
 #line 363 "src/parse-gram.y" /* yacc.c:1668  */
     { add_param (current_param, (yyvsp[0].code), (yylsp[0])); }
-#line 2217 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2231 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 34:
@@ -2221,7 +2235,7 @@ yyreduce:
     {
       grammar_start_symbol_set ((yyvsp[0].symbol), (yylsp[0]));
     }
-#line 2225 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2239 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 35:
@@ -2237,7 +2251,7 @@ yyreduce:
         symbol_list_free ((yyvsp[0].list));
       }
     }
-#line 2241 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2255 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 36:
@@ -2245,7 +2259,7 @@ yyreduce:
     {
       default_prec = true;
     }
-#line 2249 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2263 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 37:
@@ -2253,7 +2267,7 @@ yyreduce:
     {
       default_prec = false;
     }
-#line 2257 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2271 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 38:
@@ -2264,7 +2278,7 @@ yyreduce:
       muscle_code_grow ("percent_code()", (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2268 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2282 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 39:
@@ -2273,31 +2287,31 @@ yyreduce:
       muscle_percent_code_grow ((yyvsp[-1].uniqstr), (yylsp[-1]), (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2277 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2291 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 40:
 #line 416 "src/parse-gram.y" /* yacc.c:1668  */
     { (yyval.code_type) = destructor; }
-#line 2283 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2297 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 41:
 #line 417 "src/parse-gram.y" /* yacc.c:1668  */
     { (yyval.code_type) = printer; }
-#line 2289 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2303 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 42:
 #line 427 "src/parse-gram.y" /* yacc.c:1668  */
     {}
-#line 2295 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2309 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 43:
 #line 428 "src/parse-gram.y" /* yacc.c:1668  */
     { muscle_code_grow ("union_name", (yyvsp[0].uniqstr), (yylsp[0])); }
-#line 2301 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2315 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 44:
@@ -2307,13 +2321,13 @@ yyreduce:
       muscle_code_grow ("union_members", (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2311 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2325 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 45:
 #line 444 "src/parse-gram.y" /* yacc.c:1668  */
     { current_class = nterm_sym; }
-#line 2317 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2331 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 46:
@@ -2322,13 +2336,13 @@ yyreduce:
       current_class = unknown_sym;
       current_type = NULL;
     }
-#line 2326 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2340 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 47:
 #line 449 "src/parse-gram.y" /* yacc.c:1668  */
     { current_class = token_sym; }
-#line 2332 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2346 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 48:
@@ -2337,7 +2351,7 @@ yyreduce:
       current_class = unknown_sym;
       current_type = NULL;
     }
-#line 2341 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2355 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 49:
@@ -2349,7 +2363,7 @@ yyreduce:
         symbol_type_set (list->content.sym, (yyvsp[-1].uniqstr), (yylsp[-1]));
       symbol_list_free ((yyvsp[0].list));
     }
-#line 2353 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2367 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 50:
@@ -2365,55 +2379,55 @@ yyreduce:
       symbol_list_free ((yyvsp[0].list));
       current_type = NULL;
     }
-#line 2369 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2383 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 51:
 #line 480 "src/parse-gram.y" /* yacc.c:1668  */
     { (yyval.assoc) = left_assoc; }
-#line 2375 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2389 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 52:
 #line 481 "src/parse-gram.y" /* yacc.c:1668  */
     { (yyval.assoc) = right_assoc; }
-#line 2381 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2395 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 53:
 #line 482 "src/parse-gram.y" /* yacc.c:1668  */
     { (yyval.assoc) = non_assoc; }
-#line 2387 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2401 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 54:
 #line 483 "src/parse-gram.y" /* yacc.c:1668  */
     { (yyval.assoc) = precedence_assoc; }
-#line 2393 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2407 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 55:
 #line 487 "src/parse-gram.y" /* yacc.c:1668  */
     { current_type = NULL; }
-#line 2399 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2413 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 56:
 #line 488 "src/parse-gram.y" /* yacc.c:1668  */
     { current_type = (yyvsp[0].uniqstr); tag_seen = true; }
-#line 2405 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2419 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 57:
 #line 494 "src/parse-gram.y" /* yacc.c:1668  */
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-#line 2411 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2425 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 58:
 #line 496 "src/parse-gram.y" /* yacc.c:1668  */
     { (yyval.list) = symbol_list_append ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
-#line 2417 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2431 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 59:
@@ -2422,7 +2436,7 @@ yyreduce:
       (yyval.symbol) = (yyvsp[0].symbol);
       symbol_class_set ((yyvsp[0].symbol), token_sym, (yylsp[0]), false);
     }
-#line 2426 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2440 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 60:
@@ -2432,55 +2446,55 @@ yyreduce:
       symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0]));
       symbol_class_set ((yyvsp[-1].symbol), token_sym, (yylsp[-1]), false);
     }
-#line 2436 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2450 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 61:
 #line 516 "src/parse-gram.y" /* yacc.c:1668  */
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-#line 2442 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2456 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 62:
 #line 518 "src/parse-gram.y" /* yacc.c:1668  */
     { (yyval.list) = symbol_list_append ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
-#line 2448 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2462 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 63:
 #line 522 "src/parse-gram.y" /* yacc.c:1668  */
     { (yyval.list) = (yyvsp[0].list); }
-#line 2454 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2468 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 64:
 #line 523 "src/parse-gram.y" /* yacc.c:1668  */
     { (yyval.list) = symbol_list_append ((yyvsp[-1].list), (yyvsp[0].list)); }
-#line 2460 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2474 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 65:
 #line 527 "src/parse-gram.y" /* yacc.c:1668  */
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-#line 2466 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2480 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 66:
 #line 528 "src/parse-gram.y" /* yacc.c:1668  */
     { (yyval.list) = symbol_list_type_new ((yyvsp[0].uniqstr), (yylsp[0])); }
-#line 2472 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2486 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 68:
 #line 533 "src/parse-gram.y" /* yacc.c:1668  */
     { (yyval.uniqstr) = uniqstr_new ("*"); }
-#line 2478 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2492 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 69:
 #line 534 "src/parse-gram.y" /* yacc.c:1668  */
     { (yyval.uniqstr) = uniqstr_new (""); }
-#line 2484 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2498 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 70:
@@ -2489,7 +2503,7 @@ yyreduce:
       current_type = (yyvsp[0].uniqstr);
       tag_seen = true;
     }
-#line 2493 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2507 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 71:
@@ -2498,7 +2512,7 @@ yyreduce:
       symbol_class_set ((yyvsp[0].symbol), current_class, (yylsp[0]), true);
       symbol_type_set ((yyvsp[0].symbol), current_type, (yylsp[0]));
     }
-#line 2502 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2516 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 72:
@@ -2508,7 +2522,7 @@ yyreduce:
       symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
       symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0]));
     }
-#line 2512 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2526 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 73:
@@ -2518,7 +2532,7 @@ yyreduce:
       symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
       symbol_make_alias ((yyvsp[-1].symbol), (yyvsp[0].symbol), (yyloc));
     }
-#line 2522 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2536 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 74:
@@ -2529,7 +2543,7 @@ yyreduce:
       symbol_user_token_number_set ((yyvsp[-2].symbol), (yyvsp[-1].integer), (yylsp[-1]));
       symbol_make_alias ((yyvsp[-2].symbol), (yyvsp[0].symbol), (yyloc));
     }
-#line 2533 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2547 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 81:
@@ -2537,13 +2551,13 @@ yyreduce:
     {
       yyerrok;
     }
-#line 2541 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2555 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 82:
 #line 598 "src/parse-gram.y" /* yacc.c:1668  */
     { current_lhs ((yyvsp[-1].symbol), (yylsp[-1]), (yyvsp[0].named_ref)); }
-#line 2547 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2561 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 83:
@@ -2552,108 +2566,114 @@ yyreduce:
     /* Free the current lhs. */
     current_lhs (0, (yylsp[-3]), 0);
   }
-#line 2556 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2570 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 84:
 #line 606 "src/parse-gram.y" /* yacc.c:1668  */
     { grammar_current_rule_end ((yylsp[0])); }
-#line 2562 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2576 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 85:
 #line 607 "src/parse-gram.y" /* yacc.c:1668  */
     { grammar_current_rule_end ((yylsp[0])); }
-#line 2568 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2582 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 87:
 #line 614 "src/parse-gram.y" /* yacc.c:1668  */
     { grammar_current_rule_begin (current_lhs_symbol, current_lhs_location,
                                   current_lhs_named_ref); }
-#line 2575 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2589 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 88:
 #line 617 "src/parse-gram.y" /* yacc.c:1668  */
     { grammar_current_rule_symbol_append ((yyvsp[-1].symbol), (yylsp[-1]), (yyvsp[0].named_ref)); }
-#line 2581 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2595 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 89:
 #line 619 "src/parse-gram.y" /* yacc.c:1668  */
     { grammar_current_rule_action_append ((yyvsp[-1].code), (yylsp[-1]), (yyvsp[0].named_ref), false); }
-#line 2587 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2601 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 90:
 #line 621 "src/parse-gram.y" /* yacc.c:1668  */
     { grammar_current_rule_action_append ((yyvsp[0].code), (yylsp[0]), NULL, true); }
-#line 2593 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2607 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 91:
 #line 623 "src/parse-gram.y" /* yacc.c:1668  */
     { grammar_current_rule_empty_set ((yylsp[0])); }
-#line 2599 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2613 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 92:
 #line 625 "src/parse-gram.y" /* yacc.c:1668  */
     { grammar_current_rule_prec_set ((yyvsp[0].symbol), (yylsp[0])); }
-#line 2605 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2619 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 93:
 #line 627 "src/parse-gram.y" /* yacc.c:1668  */
     { grammar_current_rule_dprec_set ((yyvsp[0].integer), (yylsp[0])); }
-#line 2611 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2625 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 94:
 #line 629 "src/parse-gram.y" /* yacc.c:1668  */
     { grammar_current_rule_merge_set ((yyvsp[0].uniqstr), (yylsp[0])); }
-#line 2617 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2631 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 95:
 #line 633 "src/parse-gram.y" /* yacc.c:1668  */
     { (yyval.named_ref) = 0; }
-#line 2623 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2637 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 96:
 #line 634 "src/parse-gram.y" /* yacc.c:1668  */
     { (yyval.named_ref) = named_ref_new((yyvsp[0].uniqstr), (yylsp[0])); }
-#line 2629 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2643 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 98:
 #line 645 "src/parse-gram.y" /* yacc.c:1668  */
     { (yyval.uniqstr) = uniqstr_new ((yyvsp[0].chars)); }
-#line 2635 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2649 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 99:
-#line 650 "src/parse-gram.y" /* yacc.c:1668  */
-    { (yyval.chars) = ""; }
-#line 2641 "src/parse-gram.c" /* yacc.c:1668  */
+#line 670 "src/parse-gram.y" /* yacc.c:1668  */
+    { (yyval.value).kind = muscle_keyword; (yyval.value).chars = ""; }
+#line 2655 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 100:
-#line 651 "src/parse-gram.y" /* yacc.c:1668  */
-    { (yyval.chars) = (yyvsp[0].uniqstr); }
-#line 2647 "src/parse-gram.c" /* yacc.c:1668  */
+#line 671 "src/parse-gram.y" /* yacc.c:1668  */
+    { (yyval.value).kind = muscle_keyword; (yyval.value).chars = (yyvsp[0].uniqstr); }
+#line 2661 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 101:
-#line 652 "src/parse-gram.y" /* yacc.c:1668  */
-    { (yyval.chars) = (yyvsp[0].chars); }
-#line 2653 "src/parse-gram.c" /* yacc.c:1668  */
+#line 672 "src/parse-gram.y" /* yacc.c:1668  */
+    { (yyval.value).kind = muscle_string;  (yyval.value).chars = (yyvsp[0].chars); }
+#line 2667 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 102:
-#line 662 "src/parse-gram.y" /* yacc.c:1668  */
+#line 673 "src/parse-gram.y" /* yacc.c:1668  */
+    { (yyval.value).kind = muscle_code;    (yyval.value).chars = (yyvsp[0].chars); }
+#line 2673 "src/parse-gram.c" /* yacc.c:1668  */
+    break;
+
+  case 103:
+#line 683 "src/parse-gram.y" /* yacc.c:1668  */
     {
       code_props plain_code;
       (yyvsp[0].code)[strlen ((yyvsp[0].code)) - 1] = '\n';
@@ -2662,42 +2682,42 @@ yyreduce:
       gram_scanner_last_string_free ();
       (yyval.chars) = plain_code.code;
     }
-#line 2666 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2686 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
-  case 103:
-#line 682 "src/parse-gram.y" /* yacc.c:1668  */
+  case 104:
+#line 703 "src/parse-gram.y" /* yacc.c:1668  */
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
-#line 2672 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2692 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
-  case 104:
-#line 684 "src/parse-gram.y" /* yacc.c:1668  */
+  case 105:
+#line 705 "src/parse-gram.y" /* yacc.c:1668  */
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[0].character)), (yylsp[0]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
       symbol_user_token_number_set ((yyval.symbol), (yyvsp[0].character), (yylsp[0]));
     }
-#line 2682 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2702 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
-  case 105:
-#line 692 "src/parse-gram.y" /* yacc.c:1668  */
+  case 106:
+#line 713 "src/parse-gram.y" /* yacc.c:1668  */
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
-#line 2688 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2708 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
-  case 108:
-#line 704 "src/parse-gram.y" /* yacc.c:1668  */
+  case 109:
+#line 725 "src/parse-gram.y" /* yacc.c:1668  */
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[0].chars)), (yylsp[0]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
     }
-#line 2697 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2717 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
-  case 110:
-#line 713 "src/parse-gram.y" /* yacc.c:1668  */
+  case 111:
+#line 734 "src/parse-gram.y" /* yacc.c:1668  */
     {
       code_props plain_code;
       code_props_plain_init (&plain_code, (yyvsp[0].chars), (yylsp[0]));
@@ -2706,11 +2726,11 @@ yyreduce:
       muscle_code_grow ("epilogue", plain_code.code, (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2710 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2730 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
 
-#line 2714 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2734 "src/parse-gram.c" /* yacc.c:1668  */
         default: break;
       }
     if (yychar_backup != yychar)
@@ -2957,7 +2977,7 @@ yyreturn:
 #endif
   return yyresult;
 }
-#line 723 "src/parse-gram.y" /* yacc.c:1928  */
+#line 744 "src/parse-gram.y" /* yacc.c:1928  */
 
 
 /* Return the location of the left-hand side of a rule whose
