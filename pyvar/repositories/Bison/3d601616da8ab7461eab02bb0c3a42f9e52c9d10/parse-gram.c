@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 3.1.91.31-00793.  */
+/* A Bison parser, made by GNU Bison 3.2.1.  */
 
 /* Bison implementation for Yacc-like parsers in C
 
@@ -47,7 +47,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "3.1.91.31-00793"
+#define YYBISON_VERSION "3.2.1"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -124,7 +124,7 @@ extern int gram_debug;
 
   #include "symlist.h"
   #include "symtab.h"
-#line 222 "src/parse-gram.y" /* yacc.c:353  */
+#line 215 "src/parse-gram.y" /* yacc.c:353  */
 
   typedef enum
   {
@@ -133,10 +133,16 @@ extern int gram_debug;
     param_parse  = 1 << 1,
     param_both   = param_lex | param_parse
   } param_type;
-#line 645 "src/parse-gram.y" /* yacc.c:353  */
-#include "muscle-tab.h"
+#line 634 "src/parse-gram.y" /* yacc.c:353  */
+
+  #include "muscle-tab.h"
+  typedef struct
+  {
+    char const *chars;
+    muscle_kind kind;
+  } value_type;
 
-#line 140 "src/parse-gram.c" /* yacc.c:353  */
+#line 146 "src/parse-gram.c" /* yacc.c:353  */
 
 /* Token type.  */
 #ifndef GRAM_TOKENTYPE
@@ -207,35 +213,64 @@ extern int gram_debug;
 
 union GRAM_STYPE
 {
-#line 183 "src/parse-gram.y" /* yacc.c:353  */
-unsigned char character;
-#line 187 "src/parse-gram.y" /* yacc.c:353  */
-char *code;
-#line 192 "src/parse-gram.y" /* yacc.c:353  */
-uniqstr uniqstr;
-#line 200 "src/parse-gram.y" /* yacc.c:353  */
-int integer;
-#line 204 "src/parse-gram.y" /* yacc.c:353  */
-symbol *symbol;
-#line 209 "src/parse-gram.y" /* yacc.c:353  */
-assoc assoc;
-#line 212 "src/parse-gram.y" /* yacc.c:353  */
-symbol_list *list;
-#line 215 "src/parse-gram.y" /* yacc.c:353  */
-named_ref *named_ref;
-#line 242 "src/parse-gram.y" /* yacc.c:353  */
-param_type param;
-#line 409 "src/parse-gram.y" /* yacc.c:353  */
-code_props_type code_type;
-#line 647 "src/parse-gram.y" /* yacc.c:353  */
-
-  struct
-  {
-    char const *chars;
-    muscle_kind kind;
-  } value;
 
-#line 239 "src/parse-gram.c" /* yacc.c:353  */
+  /* precedence_declarator  */
+  assoc precedence_declarator;
+  /* "string"  */
+  char* STRING;
+  /* "{...}"  */
+  char* BRACED_CODE;
+  /* "%?{...}"  */
+  char* BRACED_PREDICATE;
+  /* "epilogue"  */
+  char* EPILOGUE;
+  /* "%{...%}"  */
+  char* PROLOGUE;
+  /* code_props_type  */
+  code_props_type code_props_type;
+  /* "integer"  */
+  int INT;
+  /* named_ref.opt  */
+  named_ref* yytype_87;
+  /* "%param"  */
+  param_type PERCENT_PARAM;
+  /* symbol.prec  */
+  symbol* yytype_74;
+  /* id  */
+  symbol* id;
+  /* id_colon  */
+  symbol* id_colon;
+  /* symbol  */
+  symbol* symbol;
+  /* string_as_id  */
+  symbol* string_as_id;
+  /* symbols.prec  */
+  symbol_list* yytype_73;
+  /* symbols.1  */
+  symbol_list* yytype_75;
+  /* generic_symlist  */
+  symbol_list* generic_symlist;
+  /* generic_symlist_item  */
+  symbol_list* generic_symlist_item;
+  /* "%<flag>"  */
+  uniqstr PERCENT_FLAG;
+  /* "[identifier]"  */
+  uniqstr BRACKETED_ID;
+  /* "identifier"  */
+  uniqstr ID;
+  /* "identifier:"  */
+  uniqstr ID_COLON;
+  /* "<tag>"  */
+  uniqstr TAG;
+  /* tag  */
+  uniqstr tag;
+  /* variable  */
+  uniqstr variable;
+  /* "char"  */
+  unsigned char CHAR;
+  /* value  */
+  value_type value;
+#line 274 "src/parse-gram.c" /* yacc.c:353  */
 };
 
 typedef union GRAM_STYPE GRAM_STYPE;
@@ -329,7 +364,7 @@ int gram_parse (void);
   #define YYTYPE_INT8 int_fast8_t
   #define YYTYPE_UINT16 uint_fast16_t
   #define YYTYPE_UINT8 uint_fast8_t
-#line 232 "src/parse-gram.y" /* yacc.c:356  */
+#line 225 "src/parse-gram.y" /* yacc.c:356  */
 
   /** Add a lex-param and/or a parse-param.
    *
@@ -340,7 +375,7 @@ int gram_parse (void);
   static void add_param (param_type type, char *decl, location loc);
   static param_type current_param = param_none;
 
-#line 344 "src/parse-gram.c" /* yacc.c:356  */
+#line 379 "src/parse-gram.c" /* yacc.c:356  */
 
 #ifdef short
 # undef short
@@ -552,16 +587,16 @@ union yyalloc
 /* YYFINAL -- State number of the termination state.  */
 #define YYFINAL  3
 /* YYLAST -- Last index in YYTABLE.  */
-#define YYLAST   164
+#define YYLAST   158
 
 /* YYNTOKENS -- Number of terminals.  */
 #define YYNTOKENS  58
 /* YYNNTS -- Number of nonterminals.  */
 #define YYNNTS  37
 /* YYNRULES -- Number of rules.  */
-#define YYNRULES  110
+#define YYNRULES  109
 /* YYNSTATES -- Number of states.  */
-#define YYNSTATES  145
+#define YYNSTATES  144
 
 /* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
    by yylex, with out-of-bounds checking.  */
@@ -613,18 +648,17 @@ static const yytype_uint8 yytranslate[] =
   /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
 static const yytype_uint16 yyrline[] =
 {
-       0,   265,   265,   274,   275,   279,   280,   286,   290,   295,
-     296,   301,   307,   308,   309,   310,   315,   320,   321,   322,
-     323,   324,   325,   325,   326,   327,   351,   352,   353,   354,
-     358,   359,   368,   369,   370,   374,   385,   389,   393,   401,
-     412,   413,   423,   424,   430,   442,   442,   447,   447,   452,
-     462,   476,   477,   478,   479,   483,   484,   489,   491,   496,
-     501,   511,   513,   518,   519,   523,   524,   528,   529,   530,
-     535,   540,   545,   551,   557,   568,   569,   578,   579,   585,
-     586,   587,   594,   594,   602,   603,   604,   609,   612,   614,
-     616,   618,   620,   622,   624,   629,   630,   640,   641,   666,
-     667,   668,   669,   681,   683,   692,   697,   698,   703,   711,
-     712
+       0,   257,   257,   266,   267,   271,   272,   278,   282,   287,
+     288,   293,   299,   300,   301,   302,   307,   312,   313,   314,
+     315,   316,   317,   317,   318,   319,   343,   344,   345,   346,
+     350,   351,   360,   361,   362,   366,   377,   381,   385,   393,
+     403,   404,   414,   415,   421,   433,   433,   438,   438,   443,
+     453,   467,   468,   469,   470,   474,   475,   480,   482,   487,
+     492,   502,   504,   509,   510,   514,   515,   519,   520,   521,
+     526,   531,   536,   542,   548,   559,   560,   569,   570,   576,
+     577,   578,   585,   585,   593,   594,   595,   600,   603,   605,
+     607,   609,   611,   613,   615,   620,   621,   630,   654,   655,
+     656,   657,   669,   671,   680,   685,   686,   691,   699,   700
 };
 #endif
 
@@ -677,7 +711,7 @@ static const yytype_uint16 yytoknum[] =
 #define yypact_value_is_default(Yystate) \
   (!!((Yystate) == (-116)))
 
-#define YYTABLE_NINF -110
+#define YYTABLE_NINF -109
 
 #define yytable_value_is_error(Yytable_value) \
   0
@@ -686,21 +720,21 @@ static const yytype_uint16 yytoknum[] =
      STATE-NUM.  */
 static const yytype_int8 yypact[] =
 {
-    -116,    16,   108,  -116,  -116,  -116,   -27,  -116,  -116,  -116,
-    -116,  -116,  -116,   -24,  -116,    23,    29,  -116,   -29,   -21,
-    -116,    36,  -116,     3,    38,    42,  -116,  -116,  -116,    44,
-      47,    71,    31,  -116,  -116,  -116,    55,  -116,  -116,  -116,
-      30,  -116,  -116,    39,  -116,  -116,    26,   -22,   -22,    31,
-    -116,    48,  -116,  -116,     1,  -116,  -116,  -116,  -116,  -116,
+    -116,     5,   102,  -116,  -116,  -116,   -50,  -116,  -116,  -116,
+    -116,  -116,  -116,   -23,  -116,   -25,    29,  -116,    -1,    15,
+    -116,    73,  -116,    40,    79,    80,  -116,  -116,  -116,    82,
+      83,    84,    12,  -116,  -116,  -116,    35,  -116,  -116,  -116,
+      43,  -116,  -116,    50,  -116,  -116,    39,    33,    33,    12,
+    -116,    53,  -116,    22,  -116,  -116,  -116,  -116,  -116,  -116,
     -116,  -116,  -116,  -116,  -116,  -116,  -116,  -116,  -116,  -116,
-    -116,    45,  -116,    50,     2,  -116,  -116,    57,    49,  -116,
-      63,    41,  -116,    31,  -116,  -116,   -22,    -2,   -22,    31,
-    -116,  -116,  -116,  -116,  -116,  -116,  -116,  -116,    46,  -116,
-    -116,  -116,  -116,  -116,    64,  -116,  -116,  -116,  -116,    41,
-    -116,  -116,  -116,    31,  -116,    51,  -116,   101,  -116,  -116,
-    -116,  -116,  -116,  -116,  -116,  -116,  -116,   -20,    40,  -116,
-    -116,    31,    53,    58,  -116,  -116,    82,    57,    40,  -116,
-    -116,  -116,    57,  -116,  -116
+      44,  -116,    46,     2,  -116,  -116,    52,    58,  -116,    60,
+      21,  -116,    12,  -116,  -116,    33,     1,    33,    12,  -116,
+    -116,  -116,  -116,  -116,  -116,  -116,  -116,    57,  -116,  -116,
+    -116,  -116,  -116,    62,  -116,  -116,  -116,  -116,    21,  -116,
+    -116,  -116,    12,  -116,    48,  -116,   112,  -116,  -116,  -116,
+    -116,  -116,  -116,  -116,  -116,  -116,   -21,    20,  -116,  -116,
+      12,    63,    65,  -116,  -116,   103,    52,    20,  -116,  -116,
+    -116,    52,  -116,  -116
 };
 
   /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
@@ -713,34 +747,34 @@ static const yytype_uint8 yydefact[] =
        7,     0,    15,     0,     0,     0,    37,    19,    20,     0,
        0,     0,     0,    26,    27,    28,     0,     6,    29,    22,
       42,     4,     5,     0,    33,    32,    55,     0,     0,     0,
-      38,     0,    98,    97,    99,    10,    12,    13,    14,    16,
-      17,    18,    21,    24,    25,   108,   104,   103,   106,    34,
-     107,     0,   105,     0,     0,    77,    79,    95,     0,    43,
-       0,     0,    56,     0,    70,    75,    48,    71,    46,    49,
-      61,    39,   101,   102,   100,     8,    81,    80,     0,    78,
-       2,    96,    82,    31,    23,    44,    67,    68,    69,    35,
-      63,    66,    65,    50,    57,    59,    76,    72,    73,    62,
-     110,    87,    30,    64,    58,    60,    74,    83,    84,    87,
-      86,     0,     0,     0,    90,    91,     0,    95,    85,    92,
-      93,    94,    95,    88,    89
+      38,     0,    97,    98,    10,    12,    13,    14,    16,    17,
+      18,    21,    24,    25,   107,   103,   102,   105,    34,   106,
+       0,   104,     0,     0,    77,    79,    95,     0,    43,     0,
+       0,    56,     0,    70,    75,    48,    71,    46,    49,    61,
+      39,   100,   101,    99,     8,    81,    80,     0,    78,     2,
+      96,    82,    31,    23,    44,    67,    68,    69,    35,    63,
+      66,    65,    50,    57,    59,    76,    72,    73,    62,   109,
+      87,    30,    64,    58,    60,    74,    83,    84,    87,    86,
+       0,     0,     0,    90,    91,     0,    95,    85,    92,    93,
+      94,    95,    88,    89
 };
 
   /* YYPGOTO[NTERM-NUM].  */
-static const yytype_int8 yypgoto[] =
+static const yytype_int16 yypgoto[] =
 {
-    -116,  -116,  -116,  -116,  -116,  -116,   120,  -116,  -116,  -116,
-    -116,  -116,  -116,  -116,    77,  -116,    34,  -116,  -116,    43,
-    -116,   -50,   100,  -116,    75,  -116,  -116,  -116,    21,  -115,
-    -116,  -116,    22,  -116,   -32,   -82,  -116
+    -116,  -116,  -116,  -116,  -116,  -116,   142,  -116,  -116,  -116,
+    -116,  -116,  -116,  -116,    99,  -116,    34,  -116,  -116,    42,
+    -116,   -57,   100,  -116,    74,  -116,  -116,  -116,    25,  -115,
+    -116,  -116,    56,  -116,   -32,   -48,  -116
 };
 
   /* YYDEFGOTO[NTERM-NUM].  */
 static const yytype_int16 yydefgoto[] =
 {
-      -1,     1,     2,    41,    78,   104,    73,    43,    80,    44,
-      48,    47,    45,    46,   136,   113,   114,    89,   109,   110,
-     111,    85,    86,    74,    75,    76,   121,   127,   128,   102,
-      54,    95,    68,    77,   112,    70,   100
+      -1,     1,     2,    41,    77,   103,    72,    43,    79,    44,
+      48,    47,    45,    46,   135,   112,   113,    88,   108,   109,
+     110,    84,    85,    73,    74,    75,   120,   126,   127,   101,
+      53,    94,    67,    76,   111,    69,    99
 };
 
   /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
@@ -748,44 +782,42 @@ static const yytype_int16 yydefgoto[] =
      number is the opposite.  If YYTABLE_NINF, syntax error.  */
 static const yytype_int16 yytable[] =
 {
-      69,    65,  -109,    71,    92,   118,     4,     5,     6,     7,
-       8,     9,    10,    11,    12,    50,     3,    90,    13,    14,
-      66,    51,   143,    67,    49,    56,    52,   144,   129,    84,
-     130,    26,    55,    57,    65,   126,   116,    32,   116,    58,
-      93,    60,    59,    65,    65,    61,    94,    62,    72,    98,
-      63,   115,   117,   131,   132,   133,    71,   119,    40,     4,
-       5,     6,     7,     8,     9,    10,    11,    12,    53,    87,
-      87,    13,    14,    66,    64,    79,    67,    82,    81,   -55,
-     134,   115,    66,    66,    26,    67,    67,    91,   103,   120,
-      32,    82,   106,   107,   108,    96,   137,   135,   101,   139,
-      97,    72,   105,   122,    65,   125,   137,   140,    87,   141,
-      87,    40,     4,     5,     6,     7,     8,     9,    10,    11,
-      12,   142,    42,    83,    13,    14,    15,    16,    17,    18,
-      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
-      29,    30,    31,    32,    33,    34,    35,   124,    88,    99,
-     138,     0,   123,     0,     0,    36,     0,    37,    38,     0,
-       0,     0,     0,    39,    40
+      68,    49,  -108,    70,    64,     3,     4,     5,     6,     7,
+       8,     9,    10,    11,    12,    64,    50,    89,    13,    14,
+      52,   142,    51,    64,    64,    91,   143,   128,   115,   129,
+     115,    26,    54,   130,   131,   132,    70,    32,   117,     4,
+       5,     6,     7,     8,     9,    10,    11,    12,    71,    97,
+     114,    13,    14,    55,    65,   116,   118,    66,    40,   -55,
+     133,    92,    65,    65,    26,    66,    66,    93,   125,    56,
+      32,    81,   105,   106,   107,    65,    57,   134,    66,    58,
+     114,    71,    59,    60,    83,    61,    62,    63,    78,    80,
+      81,    40,    90,   100,    95,   136,    96,   102,   138,   104,
+     119,   121,   124,    86,    86,   136,     4,     5,     6,     7,
+       8,     9,    10,    11,    12,    64,   140,   139,    13,    14,
+      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
+      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
+      35,    86,   141,    86,    42,    82,   123,    98,    87,    36,
+     122,    37,    38,   137,     0,     0,     0,    39,    40
 };
 
 static const yytype_int16 yycheck[] =
 {
-      32,     3,     0,     1,     3,    87,     4,     5,     6,     7,
-       8,     9,    10,    11,    12,    39,     0,    49,    16,    17,
-      42,    45,   137,    45,    51,    54,     3,   142,    48,    51,
-      50,    29,     3,    54,     3,   117,    86,    35,    88,     3,
-      39,     3,    39,     3,     3,     3,    45,     3,    46,    47,
-       3,    83,    54,    13,    14,    15,     1,    89,    56,     4,
-       5,     6,     7,     8,     9,    10,    11,    12,    45,    47,
-      48,    16,    17,    42,     3,    45,    45,    51,    39,    39,
-      40,   113,    42,    42,    29,    45,    45,    39,    39,    43,
-      35,    51,    51,    52,    53,    50,   128,    57,    41,   131,
-      50,    46,    39,    39,     3,    54,   138,    54,    86,    51,
-      88,    56,     4,     5,     6,     7,     8,     9,    10,    11,
-      12,    39,     2,    46,    16,    17,    18,    19,    20,    21,
-      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
-      32,    33,    34,    35,    36,    37,    38,   113,    48,    74,
-     129,    -1,   109,    -1,    -1,    47,    -1,    49,    50,    -1,
-      -1,    -1,    -1,    55,    56
+      32,    51,     0,     1,     3,     0,     4,     5,     6,     7,
+       8,     9,    10,    11,    12,     3,    39,    49,    16,    17,
+      45,   136,    45,     3,     3,     3,   141,    48,    85,    50,
+      87,    29,     3,    13,    14,    15,     1,    35,    86,     4,
+       5,     6,     7,     8,     9,    10,    11,    12,    46,    47,
+      82,    16,    17,    54,    42,    54,    88,    45,    56,    39,
+      40,    39,    42,    42,    29,    45,    45,    45,   116,    54,
+      35,    51,    51,    52,    53,    42,     3,    57,    45,    39,
+     112,    46,     3,     3,    51,     3,     3,     3,    45,    39,
+      51,    56,    39,    41,    50,   127,    50,    39,   130,    39,
+      43,    39,    54,    47,    48,   137,     4,     5,     6,     7,
+       8,     9,    10,    11,    12,     3,    51,    54,    16,    17,
+      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
+      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
+      38,    85,    39,    87,     2,    46,   112,    73,    48,    47,
+     108,    49,    50,   128,    -1,    -1,    -1,    55,    56
 };
 
   /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
@@ -797,16 +829,16 @@ static const yytype_uint8 yystos[] =
       23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
       33,    34,    35,    36,    37,    38,    47,    49,    50,    55,
       56,    61,    64,    65,    67,    70,    71,    69,    68,    51,
-      39,    45,     3,    45,    88,     3,    54,    54,     3,    39,
-       3,     3,     3,     3,     3,     3,    42,    45,    90,    92,
-      93,     1,    46,    64,    81,    82,    83,    91,    62,    45,
-      66,    39,    51,    72,    51,    79,    80,    90,    80,    75,
-      92,    39,     3,    39,    45,    89,    50,    50,    47,    82,
-      94,    41,    87,    39,    63,    39,    51,    52,    53,    76,
-      77,    78,    92,    73,    74,    92,    79,    54,    93,    92,
-      43,    84,    39,    77,    74,    54,    93,    85,    86,    48,
-      50,    13,    14,    15,    40,    57,    72,    92,    86,    92,
-      54,    51,    39,    87,    87
+      39,    45,    45,    88,     3,    54,    54,     3,    39,     3,
+       3,     3,     3,     3,     3,    42,    45,    90,    92,    93,
+       1,    46,    64,    81,    82,    83,    91,    62,    45,    66,
+      39,    51,    72,    51,    79,    80,    90,    80,    75,    92,
+      39,     3,    39,    45,    89,    50,    50,    47,    82,    94,
+      41,    87,    39,    63,    39,    51,    52,    53,    76,    77,
+      78,    92,    73,    74,    92,    79,    54,    93,    92,    43,
+      84,    39,    77,    74,    54,    93,    85,    86,    48,    50,
+      13,    14,    15,    40,    57,    72,    92,    86,    92,    54,
+      51,    39,    87,    87
 };
 
   /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
@@ -821,9 +853,8 @@ static const yytype_uint8 yyr1[] =
       74,    75,    75,    76,    76,    77,    77,    78,    78,    78,
       79,    79,    79,    79,    79,    80,    80,    81,    81,    82,
       82,    82,    84,    83,    85,    85,    85,    86,    86,    86,
-      86,    86,    86,    86,    86,    87,    87,    88,    88,    89,
-      89,    89,    89,    90,    90,    91,    92,    92,    93,    94,
-      94
+      86,    86,    86,    86,    86,    87,    87,    88,    89,    89,
+      89,    89,    90,    90,    91,    92,    92,    93,    94,    94
 };
 
   /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
@@ -838,9 +869,8 @@ static const yytype_uint8 yyr2[] =
        2,     1,     2,     1,     2,     1,     1,     1,     1,     1,
        1,     1,     2,     2,     3,     1,     2,     1,     2,     1,
        2,     2,     0,     4,     1,     3,     2,     0,     3,     4,
-       2,     2,     3,     3,     3,     0,     1,     1,     1,     0,
-       1,     1,     1,     1,     1,     1,     1,     1,     1,     0,
-       2
+       2,     2,     3,     3,     3,     0,     1,     1,     0,     1,
+       1,     1,     1,     1,     1,     1,     1,     1,     0,     2
 };
 
 
@@ -996,81 +1026,81 @@ yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YY
   switch (yytype)
     {
           case 3: /* "string"  */
-#line 189 "src/parse-gram.y" /* yacc.c:681  */
-      { fputs (quotearg_style (c_quoting_style, ((*yyvaluep).code)), yyo); }
-#line 1002 "src/parse-gram.c" /* yacc.c:681  */
+#line 188 "src/parse-gram.y" /* yacc.c:681  */
+      { fputs (quotearg_style (c_quoting_style, (*(char**)(&(*yyvaluep)))), yyo); }
+#line 1032 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 23: /* "%<flag>"  */
-#line 197 "src/parse-gram.y" /* yacc.c:681  */
-      { fprintf (yyo, "%%%s", ((*yyvaluep).uniqstr)); }
-#line 1008 "src/parse-gram.c" /* yacc.c:681  */
+#line 195 "src/parse-gram.y" /* yacc.c:681  */
+      { fprintf (yyo, "%%%s", (*(uniqstr*)(&(*yyvaluep)))); }
+#line 1038 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 39: /* "{...}"  */
-#line 190 "src/parse-gram.y" /* yacc.c:681  */
-      { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).code)); }
-#line 1014 "src/parse-gram.c" /* yacc.c:681  */
+#line 189 "src/parse-gram.y" /* yacc.c:681  */
+      { fprintf (yyo, "{\n%s\n}", (*(char**)(&(*yyvaluep)))); }
+#line 1044 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 40: /* "%?{...}"  */
-#line 190 "src/parse-gram.y" /* yacc.c:681  */
-      { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).code)); }
-#line 1020 "src/parse-gram.c" /* yacc.c:681  */
+#line 189 "src/parse-gram.y" /* yacc.c:681  */
+      { fprintf (yyo, "{\n%s\n}", (*(char**)(&(*yyvaluep)))); }
+#line 1050 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 41: /* "[identifier]"  */
-#line 195 "src/parse-gram.y" /* yacc.c:681  */
-      { fprintf (yyo, "[%s]", ((*yyvaluep).uniqstr)); }
-#line 1026 "src/parse-gram.c" /* yacc.c:681  */
+#line 193 "src/parse-gram.y" /* yacc.c:681  */
+      { fprintf (yyo, "[%s]", (*(uniqstr*)(&(*yyvaluep)))); }
+#line 1056 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 42: /* "char"  */
 #line 185 "src/parse-gram.y" /* yacc.c:681  */
-      { fputs (char_name (((*yyvaluep).character)), yyo); }
-#line 1032 "src/parse-gram.c" /* yacc.c:681  */
+      { fputs (char_name ((*(unsigned char*)(&(*yyvaluep)))), yyo); }
+#line 1062 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 43: /* "epilogue"  */
-#line 190 "src/parse-gram.y" /* yacc.c:681  */
-      { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).code)); }
-#line 1038 "src/parse-gram.c" /* yacc.c:681  */
+#line 189 "src/parse-gram.y" /* yacc.c:681  */
+      { fprintf (yyo, "{\n%s\n}", (*(char**)(&(*yyvaluep)))); }
+#line 1068 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 45: /* "identifier"  */
-#line 194 "src/parse-gram.y" /* yacc.c:681  */
-      { fputs (((*yyvaluep).uniqstr), yyo); }
-#line 1044 "src/parse-gram.c" /* yacc.c:681  */
+#line 192 "src/parse-gram.y" /* yacc.c:681  */
+      { fputs ((*(uniqstr*)(&(*yyvaluep))), yyo); }
+#line 1074 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 46: /* "identifier:"  */
-#line 196 "src/parse-gram.y" /* yacc.c:681  */
-      { fprintf (yyo, "%s:", ((*yyvaluep).uniqstr)); }
-#line 1050 "src/parse-gram.c" /* yacc.c:681  */
+#line 194 "src/parse-gram.y" /* yacc.c:681  */
+      { fprintf (yyo, "%s:", (*(uniqstr*)(&(*yyvaluep)))); }
+#line 1080 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 49: /* "%{...%}"  */
-#line 190 "src/parse-gram.y" /* yacc.c:681  */
-      { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).code)); }
-#line 1056 "src/parse-gram.c" /* yacc.c:681  */
+#line 189 "src/parse-gram.y" /* yacc.c:681  */
+      { fprintf (yyo, "{\n%s\n}", (*(char**)(&(*yyvaluep)))); }
+#line 1086 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 51: /* "<tag>"  */
-#line 198 "src/parse-gram.y" /* yacc.c:681  */
-      { fprintf (yyo, "<%s>", ((*yyvaluep).uniqstr)); }
-#line 1062 "src/parse-gram.c" /* yacc.c:681  */
+#line 196 "src/parse-gram.y" /* yacc.c:681  */
+      { fprintf (yyo, "<%s>", (*(uniqstr*)(&(*yyvaluep)))); }
+#line 1092 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 54: /* "integer"  */
-#line 202 "src/parse-gram.y" /* yacc.c:681  */
-      { fprintf (yyo, "%d", ((*yyvaluep).integer)); }
-#line 1068 "src/parse-gram.c" /* yacc.c:681  */
+#line 199 "src/parse-gram.y" /* yacc.c:681  */
+      { fprintf (yyo, "%d", (*(int*)(&(*yyvaluep)))); }
+#line 1098 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 55: /* "%param"  */
-#line 245 "src/parse-gram.y" /* yacc.c:681  */
+#line 237 "src/parse-gram.y" /* yacc.c:681  */
       {
-  switch (((*yyvaluep).param))
+  switch ((*(param_type*)(&(*yyvaluep))))
     {
 #define CASE(In, Out)                                           \
       case param_ ## In: fputs ("%" #Out, yyo); break
@@ -1081,68 +1111,68 @@ yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YY
       case param_none: aver (false); break;
     }
 }
-#line 1085 "src/parse-gram.c" /* yacc.c:681  */
+#line 1115 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 65: /* code_props_type  */
-#line 410 "src/parse-gram.y" /* yacc.c:681  */
-      { fprintf (yyo, "%s", code_props_type_string (((*yyvaluep).code_type))); }
-#line 1091 "src/parse-gram.c" /* yacc.c:681  */
+#line 401 "src/parse-gram.y" /* yacc.c:681  */
+      { fprintf (yyo, "%s", code_props_type_string ((*(code_props_type*)(&(*yyvaluep))))); }
+#line 1121 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 74: /* symbol.prec  */
-#line 206 "src/parse-gram.y" /* yacc.c:681  */
-      { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
-#line 1097 "src/parse-gram.c" /* yacc.c:681  */
+#line 202 "src/parse-gram.y" /* yacc.c:681  */
+      { fprintf (yyo, "%s", (*(symbol**)(&(*yyvaluep)))->tag); }
+#line 1127 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 78: /* tag  */
-#line 198 "src/parse-gram.y" /* yacc.c:681  */
-      { fprintf (yyo, "<%s>", ((*yyvaluep).uniqstr)); }
-#line 1103 "src/parse-gram.c" /* yacc.c:681  */
+#line 196 "src/parse-gram.y" /* yacc.c:681  */
+      { fprintf (yyo, "<%s>", (*(uniqstr*)(&(*yyvaluep)))); }
+#line 1133 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 88: /* variable  */
-#line 194 "src/parse-gram.y" /* yacc.c:681  */
-      { fputs (((*yyvaluep).uniqstr), yyo); }
-#line 1109 "src/parse-gram.c" /* yacc.c:681  */
+#line 192 "src/parse-gram.y" /* yacc.c:681  */
+      { fputs ((*(uniqstr*)(&(*yyvaluep))), yyo); }
+#line 1139 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 89: /* value  */
-#line 656 "src/parse-gram.y" /* yacc.c:681  */
+#line 644 "src/parse-gram.y" /* yacc.c:681  */
       {
-  switch (((*yyvaluep).value).kind)
+  switch ((*(value_type*)(&(*yyvaluep))).kind)
     {
-    case muscle_code:    fprintf (yyo,  "{%s}",  ((*yyvaluep).value).chars); break;
-    case muscle_keyword: fprintf (yyo,   "%s",   ((*yyvaluep).value).chars); break;
-    case muscle_string:  fprintf (yyo, "\"%s\"", ((*yyvaluep).value).chars); break;
+    case muscle_code:    fprintf (yyo,  "{%s}",  (*(value_type*)(&(*yyvaluep))).chars); break;
+    case muscle_keyword: fprintf (yyo,   "%s",   (*(value_type*)(&(*yyvaluep))).chars); break;
+    case muscle_string:  fprintf (yyo, "\"%s\"", (*(value_type*)(&(*yyvaluep))).chars); break;
     }
 }
-#line 1122 "src/parse-gram.c" /* yacc.c:681  */
+#line 1152 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 90: /* id  */
-#line 206 "src/parse-gram.y" /* yacc.c:681  */
-      { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
-#line 1128 "src/parse-gram.c" /* yacc.c:681  */
+#line 202 "src/parse-gram.y" /* yacc.c:681  */
+      { fprintf (yyo, "%s", (*(symbol**)(&(*yyvaluep)))->tag); }
+#line 1158 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 91: /* id_colon  */
-#line 207 "src/parse-gram.y" /* yacc.c:681  */
-      { fprintf (yyo, "%s:", ((*yyvaluep).symbol)->tag); }
-#line 1134 "src/parse-gram.c" /* yacc.c:681  */
+#line 203 "src/parse-gram.y" /* yacc.c:681  */
+      { fprintf (yyo, "%s:", (*(symbol**)(&(*yyvaluep)))->tag); }
+#line 1164 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 92: /* symbol  */
-#line 206 "src/parse-gram.y" /* yacc.c:681  */
-      { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
-#line 1140 "src/parse-gram.c" /* yacc.c:681  */
+#line 202 "src/parse-gram.y" /* yacc.c:681  */
+      { fprintf (yyo, "%s", (*(symbol**)(&(*yyvaluep)))->tag); }
+#line 1170 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 93: /* string_as_id  */
-#line 206 "src/parse-gram.y" /* yacc.c:681  */
-      { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
-#line 1146 "src/parse-gram.c" /* yacc.c:681  */
+#line 202 "src/parse-gram.y" /* yacc.c:681  */
+      { fprintf (yyo, "%s", (*(symbol**)(&(*yyvaluep)))->tag); }
+#line 1176 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
 
@@ -1210,7 +1240,7 @@ yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule
       YYFPRINTF (stderr, "   $%d = ", yyi + 1);
       yy_symbol_print (stderr,
                        yystos[yyssp[yyi + 1 - yynrhs]],
-                       &(yyvsp[(yyi + 1) - (yynrhs)])
+                       &yyvsp[(yyi + 1) - (yynrhs)]
                        , &(yylsp[(yyi + 1) - (yynrhs)])                       );
       YYFPRINTF (stderr, "\n");
     }
@@ -1836,7 +1866,7 @@ YYLTYPE yylloc = yyloc_default;
   yychar = YYEMPTY; /* Cause a token to be read.  */
 
 /* User initialization code.  */
-#line 109 "src/parse-gram.y" /* yacc.c:1429  */
+#line 110 "src/parse-gram.y" /* yacc.c:1429  */
 {
   /* Bison's grammar can initial empty locations, hence a default
      location is needed. */
@@ -1844,7 +1874,7 @@ YYLTYPE yylloc = yyloc_default;
   boundary_set (&yylloc.end, current_file, 1, 1);
 }
 
-#line 1848 "src/parse-gram.c" /* yacc.c:1429  */
+#line 1878 "src/parse-gram.c" /* yacc.c:1429  */
   yylsp[0] = yylloc;
   goto yysetstate;
 
@@ -2038,145 +2068,145 @@ yyreduce:
     switch (yyn)
       {
   case 6:
-#line 281 "src/parse-gram.y" /* yacc.c:1645  */
+#line 273 "src/parse-gram.y" /* yacc.c:1645  */
     {
       muscle_code_grow (union_seen ? "post_prologue" : "pre_prologue",
-                        translate_code ((yyvsp[0].code), (yylsp[0]), true), (yylsp[0]));
+                        translate_code ((*(char**)(&yyvsp[0])), (yylsp[0]), true), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2048 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2078 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 7:
-#line 287 "src/parse-gram.y" /* yacc.c:1645  */
+#line 279 "src/parse-gram.y" /* yacc.c:1645  */
     {
-      muscle_percent_define_ensure ((yyvsp[0].uniqstr), (yylsp[0]), true);
+      muscle_percent_define_ensure ((*(uniqstr*)(&yyvsp[0])), (yylsp[0]), true);
     }
-#line 2056 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2086 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 8:
-#line 291 "src/parse-gram.y" /* yacc.c:1645  */
+#line 283 "src/parse-gram.y" /* yacc.c:1645  */
     {
-      muscle_percent_define_insert ((yyvsp[-1].uniqstr), (yylsp[-1]), (yyvsp[0].value).kind, (yyvsp[0].value).chars,
+      muscle_percent_define_insert ((*(uniqstr*)(&yyvsp[-1])), (yylsp[-1]), (*(value_type*)(&yyvsp[0])).kind, (*(value_type*)(&yyvsp[0])).chars,
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
     }
-#line 2065 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2095 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 9:
-#line 295 "src/parse-gram.y" /* yacc.c:1645  */
+#line 287 "src/parse-gram.y" /* yacc.c:1645  */
     { defines_flag = true; }
-#line 2071 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2101 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 10:
-#line 297 "src/parse-gram.y" /* yacc.c:1645  */
+#line 289 "src/parse-gram.y" /* yacc.c:1645  */
     {
       defines_flag = true;
-      spec_defines_file = xstrdup ((yyvsp[0].code));
+      spec_defines_file = xstrdup ((*(char**)(&yyvsp[0])));
     }
-#line 2080 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2110 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 11:
-#line 302 "src/parse-gram.y" /* yacc.c:1645  */
+#line 294 "src/parse-gram.y" /* yacc.c:1645  */
     {
       muscle_percent_define_insert ("parse.error", (yylsp[0]), muscle_keyword,
                                     "verbose",
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
     }
-#line 2090 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2120 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 12:
-#line 307 "src/parse-gram.y" /* yacc.c:1645  */
-    { expected_sr_conflicts = (yyvsp[0].integer); }
-#line 2096 "src/parse-gram.c" /* yacc.c:1645  */
+#line 299 "src/parse-gram.y" /* yacc.c:1645  */
+    { expected_sr_conflicts = (*(int*)(&yyvsp[0])); }
+#line 2126 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 13:
-#line 308 "src/parse-gram.y" /* yacc.c:1645  */
-    { expected_rr_conflicts = (yyvsp[0].integer); }
-#line 2102 "src/parse-gram.c" /* yacc.c:1645  */
+#line 300 "src/parse-gram.y" /* yacc.c:1645  */
+    { expected_rr_conflicts = (*(int*)(&yyvsp[0])); }
+#line 2132 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 14:
-#line 309 "src/parse-gram.y" /* yacc.c:1645  */
-    { spec_file_prefix = (yyvsp[0].code); }
-#line 2108 "src/parse-gram.c" /* yacc.c:1645  */
+#line 301 "src/parse-gram.y" /* yacc.c:1645  */
+    { spec_file_prefix = (*(char**)(&yyvsp[0])); }
+#line 2138 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 15:
-#line 311 "src/parse-gram.y" /* yacc.c:1645  */
+#line 303 "src/parse-gram.y" /* yacc.c:1645  */
     {
       nondeterministic_parser = true;
       glr_parser = true;
     }
-#line 2117 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2147 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 16:
-#line 316 "src/parse-gram.y" /* yacc.c:1645  */
+#line 308 "src/parse-gram.y" /* yacc.c:1645  */
     {
-      muscle_code_grow ("initial_action", translate_code ((yyvsp[0].code), (yylsp[0]), false), (yylsp[0]));
+      muscle_code_grow ("initial_action", translate_code ((*(char**)(&yyvsp[0])), (yylsp[0]), false), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2126 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2156 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 17:
-#line 320 "src/parse-gram.y" /* yacc.c:1645  */
-    { language_argmatch ((yyvsp[0].code), grammar_prio, (yylsp[-1])); }
-#line 2132 "src/parse-gram.c" /* yacc.c:1645  */
+#line 312 "src/parse-gram.y" /* yacc.c:1645  */
+    { language_argmatch ((*(char**)(&yyvsp[0])), grammar_prio, (yylsp[-1])); }
+#line 2162 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 18:
-#line 321 "src/parse-gram.y" /* yacc.c:1645  */
-    { spec_name_prefix = (yyvsp[0].code); }
-#line 2138 "src/parse-gram.c" /* yacc.c:1645  */
+#line 313 "src/parse-gram.y" /* yacc.c:1645  */
+    { spec_name_prefix = (*(char**)(&yyvsp[0])); }
+#line 2168 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 19:
-#line 322 "src/parse-gram.y" /* yacc.c:1645  */
+#line 314 "src/parse-gram.y" /* yacc.c:1645  */
     { no_lines_flag = true; }
-#line 2144 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2174 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 20:
-#line 323 "src/parse-gram.y" /* yacc.c:1645  */
+#line 315 "src/parse-gram.y" /* yacc.c:1645  */
     { nondeterministic_parser = true; }
-#line 2150 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2180 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 21:
-#line 324 "src/parse-gram.y" /* yacc.c:1645  */
-    { spec_outfile = (yyvsp[0].code); }
-#line 2156 "src/parse-gram.c" /* yacc.c:1645  */
+#line 316 "src/parse-gram.y" /* yacc.c:1645  */
+    { spec_outfile = (*(char**)(&yyvsp[0])); }
+#line 2186 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 22:
-#line 325 "src/parse-gram.y" /* yacc.c:1645  */
-    { current_param = (yyvsp[0].param); }
-#line 2162 "src/parse-gram.c" /* yacc.c:1645  */
+#line 317 "src/parse-gram.y" /* yacc.c:1645  */
+    { current_param = (*(param_type*)(&yyvsp[0])); }
+#line 2192 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 23:
-#line 325 "src/parse-gram.y" /* yacc.c:1645  */
+#line 317 "src/parse-gram.y" /* yacc.c:1645  */
     { current_param = param_none; }
-#line 2168 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2198 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 24:
-#line 326 "src/parse-gram.y" /* yacc.c:1645  */
-    { version_check (&(yylsp[0]), (yyvsp[0].code)); }
-#line 2174 "src/parse-gram.c" /* yacc.c:1645  */
+#line 318 "src/parse-gram.y" /* yacc.c:1645  */
+    { version_check (&(yylsp[0]), (*(char**)(&yyvsp[0]))); }
+#line 2204 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 25:
-#line 328 "src/parse-gram.y" /* yacc.c:1645  */
+#line 320 "src/parse-gram.y" /* yacc.c:1645  */
     {
-      char const *skeleton_user = (yyvsp[0].code);
+      char const *skeleton_user = (*(char**)(&yyvsp[0]));
       if (strchr (skeleton_user, '/'))
         {
           size_t dir_length = strlen (current_file);
@@ -2198,523 +2228,517 @@ yyreduce:
         }
       skeleton_arg (skeleton_user, grammar_prio, (yylsp[-1]));
     }
-#line 2202 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2232 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 26:
-#line 351 "src/parse-gram.y" /* yacc.c:1645  */
+#line 343 "src/parse-gram.y" /* yacc.c:1645  */
     { token_table_flag = true; }
-#line 2208 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2238 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 27:
-#line 352 "src/parse-gram.y" /* yacc.c:1645  */
+#line 344 "src/parse-gram.y" /* yacc.c:1645  */
     { report_flag |= report_states; }
-#line 2214 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2244 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 28:
-#line 353 "src/parse-gram.y" /* yacc.c:1645  */
+#line 345 "src/parse-gram.y" /* yacc.c:1645  */
     { yacc_flag = true; }
-#line 2220 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2250 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 30:
-#line 358 "src/parse-gram.y" /* yacc.c:1645  */
-    { add_param (current_param, (yyvsp[0].code), (yylsp[0])); }
-#line 2226 "src/parse-gram.c" /* yacc.c:1645  */
+#line 350 "src/parse-gram.y" /* yacc.c:1645  */
+    { add_param (current_param, (*(char**)(&yyvsp[0])), (yylsp[0])); }
+#line 2256 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 31:
-#line 359 "src/parse-gram.y" /* yacc.c:1645  */
-    { add_param (current_param, (yyvsp[0].code), (yylsp[0])); }
-#line 2232 "src/parse-gram.c" /* yacc.c:1645  */
+#line 351 "src/parse-gram.y" /* yacc.c:1645  */
+    { add_param (current_param, (*(char**)(&yyvsp[0])), (yylsp[0])); }
+#line 2262 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 34:
-#line 371 "src/parse-gram.y" /* yacc.c:1645  */
+#line 363 "src/parse-gram.y" /* yacc.c:1645  */
     {
-      grammar_start_symbol_set ((yyvsp[0].symbol), (yylsp[0]));
+      grammar_start_symbol_set ((*(symbol**)(&yyvsp[0])), (yylsp[0]));
     }
-#line 2240 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2270 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 35:
-#line 375 "src/parse-gram.y" /* yacc.c:1645  */
+#line 367 "src/parse-gram.y" /* yacc.c:1645  */
     {
       code_props code;
-      code_props_symbol_action_init (&code, (yyvsp[-1].code), (yylsp[-1]));
+      code_props_symbol_action_init (&code, (*(char**)(&yyvsp[-1])), (yylsp[-1]));
       code_props_translate_code (&code);
       {
-        for (symbol_list *list = (yyvsp[0].list); list; list = list->next)
-          symbol_list_code_props_set (list, (yyvsp[-2].code_type), &code);
-        symbol_list_free ((yyvsp[0].list));
+        for (symbol_list *list = (*(symbol_list**)(&yyvsp[0])); list; list = list->next)
+          symbol_list_code_props_set (list, (*(code_props_type*)(&yyvsp[-2])), &code);
+        symbol_list_free ((*(symbol_list**)(&yyvsp[0])));
       }
     }
-#line 2255 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2285 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 36:
-#line 386 "src/parse-gram.y" /* yacc.c:1645  */
+#line 378 "src/parse-gram.y" /* yacc.c:1645  */
     {
       default_prec = true;
     }
-#line 2263 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2293 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 37:
-#line 390 "src/parse-gram.y" /* yacc.c:1645  */
+#line 382 "src/parse-gram.y" /* yacc.c:1645  */
     {
       default_prec = false;
     }
-#line 2271 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2301 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 38:
-#line 394 "src/parse-gram.y" /* yacc.c:1645  */
+#line 386 "src/parse-gram.y" /* yacc.c:1645  */
     {
       /* Do not invoke muscle_percent_code_grow here since it invokes
          muscle_user_name_list_grow.  */
       muscle_code_grow ("percent_code()",
-                        translate_code_braceless ((yyvsp[0].code), (yylsp[0])), (yylsp[0]));
+                        translate_code_braceless ((*(char**)(&yyvsp[0])), (yylsp[0])), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2283 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2313 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 39:
-#line 402 "src/parse-gram.y" /* yacc.c:1645  */
+#line 394 "src/parse-gram.y" /* yacc.c:1645  */
     {
-      muscle_percent_code_grow ((yyvsp[-1].uniqstr), (yylsp[-1]), translate_code_braceless ((yyvsp[0].code), (yylsp[0])), (yylsp[0]));
+      muscle_percent_code_grow ((*(uniqstr*)(&yyvsp[-1])), (yylsp[-1]), translate_code_braceless ((*(char**)(&yyvsp[0])), (yylsp[0])), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2292 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2322 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 40:
-#line 412 "src/parse-gram.y" /* yacc.c:1645  */
-    { (yyval.code_type) = destructor; }
-#line 2298 "src/parse-gram.c" /* yacc.c:1645  */
+#line 403 "src/parse-gram.y" /* yacc.c:1645  */
+    { (*(code_props_type*)(&yyval)) = destructor; }
+#line 2328 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 41:
-#line 413 "src/parse-gram.y" /* yacc.c:1645  */
-    { (yyval.code_type) = printer; }
-#line 2304 "src/parse-gram.c" /* yacc.c:1645  */
+#line 404 "src/parse-gram.y" /* yacc.c:1645  */
+    { (*(code_props_type*)(&yyval)) = printer; }
+#line 2334 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 42:
-#line 423 "src/parse-gram.y" /* yacc.c:1645  */
+#line 414 "src/parse-gram.y" /* yacc.c:1645  */
     {}
-#line 2310 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2340 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 43:
-#line 424 "src/parse-gram.y" /* yacc.c:1645  */
+#line 415 "src/parse-gram.y" /* yacc.c:1645  */
     { muscle_percent_define_insert ("api.value.union.name",
-                                         (yylsp[0]), muscle_keyword, (yyvsp[0].uniqstr),
+                                         (yylsp[0]), muscle_keyword, (*(uniqstr*)(&yyvsp[0])),
                                          MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE); }
-#line 2318 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2348 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 44:
-#line 431 "src/parse-gram.y" /* yacc.c:1645  */
+#line 422 "src/parse-gram.y" /* yacc.c:1645  */
     {
       union_seen = true;
-      muscle_code_grow ("union_members", translate_code_braceless ((yyvsp[0].code), (yylsp[0])), (yylsp[0]));
+      muscle_code_grow ("union_members", translate_code_braceless ((*(char**)(&yyvsp[0])), (yylsp[0])), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2328 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2358 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 45:
-#line 442 "src/parse-gram.y" /* yacc.c:1645  */
+#line 433 "src/parse-gram.y" /* yacc.c:1645  */
     { current_class = nterm_sym; }
-#line 2334 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2364 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 46:
-#line 443 "src/parse-gram.y" /* yacc.c:1645  */
+#line 434 "src/parse-gram.y" /* yacc.c:1645  */
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
-#line 2343 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2373 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 47:
-#line 447 "src/parse-gram.y" /* yacc.c:1645  */
+#line 438 "src/parse-gram.y" /* yacc.c:1645  */
     { current_class = token_sym; }
-#line 2349 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2379 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 48:
-#line 448 "src/parse-gram.y" /* yacc.c:1645  */
+#line 439 "src/parse-gram.y" /* yacc.c:1645  */
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
-#line 2358 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2388 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 49:
-#line 453 "src/parse-gram.y" /* yacc.c:1645  */
+#line 444 "src/parse-gram.y" /* yacc.c:1645  */
     {
       tag_seen = true;
-      for (symbol_list *list = (yyvsp[0].list); list; list = list->next)
-        symbol_type_set (list->content.sym, (yyvsp[-1].uniqstr), (yylsp[-1]));
-      symbol_list_free ((yyvsp[0].list));
+      for (symbol_list *list = (*(symbol_list**)(&yyvsp[0])); list; list = list->next)
+        symbol_type_set (list->content.sym, (*(uniqstr*)(&yyvsp[-1])), (yylsp[-1]));
+      symbol_list_free ((*(symbol_list**)(&yyvsp[0])));
     }
-#line 2369 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2399 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 50:
-#line 463 "src/parse-gram.y" /* yacc.c:1645  */
+#line 454 "src/parse-gram.y" /* yacc.c:1645  */
     {
       ++current_prec;
-      for (symbol_list *list = (yyvsp[0].list); list; list = list->next)
+      for (symbol_list *list = (*(symbol_list**)(&yyvsp[0])); list; list = list->next)
         {
           symbol_type_set (list->content.sym, current_type, (yylsp[-1]));
-          symbol_precedence_set (list->content.sym, current_prec, (yyvsp[-2].assoc), (yylsp[-2]));
+          symbol_precedence_set (list->content.sym, current_prec, (*(assoc*)(&yyvsp[-2])), (yylsp[-2]));
         }
-      symbol_list_free ((yyvsp[0].list));
+      symbol_list_free ((*(symbol_list**)(&yyvsp[0])));
       current_type = NULL;
     }
-#line 2384 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2414 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 51:
-#line 476 "src/parse-gram.y" /* yacc.c:1645  */
-    { (yyval.assoc) = left_assoc; }
-#line 2390 "src/parse-gram.c" /* yacc.c:1645  */
+#line 467 "src/parse-gram.y" /* yacc.c:1645  */
+    { (*(assoc*)(&yyval)) = left_assoc; }
+#line 2420 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 52:
-#line 477 "src/parse-gram.y" /* yacc.c:1645  */
-    { (yyval.assoc) = right_assoc; }
-#line 2396 "src/parse-gram.c" /* yacc.c:1645  */
+#line 468 "src/parse-gram.y" /* yacc.c:1645  */
+    { (*(assoc*)(&yyval)) = right_assoc; }
+#line 2426 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 53:
-#line 478 "src/parse-gram.y" /* yacc.c:1645  */
-    { (yyval.assoc) = non_assoc; }
-#line 2402 "src/parse-gram.c" /* yacc.c:1645  */
+#line 469 "src/parse-gram.y" /* yacc.c:1645  */
+    { (*(assoc*)(&yyval)) = non_assoc; }
+#line 2432 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 54:
-#line 479 "src/parse-gram.y" /* yacc.c:1645  */
-    { (yyval.assoc) = precedence_assoc; }
-#line 2408 "src/parse-gram.c" /* yacc.c:1645  */
+#line 470 "src/parse-gram.y" /* yacc.c:1645  */
+    { (*(assoc*)(&yyval)) = precedence_assoc; }
+#line 2438 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 55:
-#line 483 "src/parse-gram.y" /* yacc.c:1645  */
+#line 474 "src/parse-gram.y" /* yacc.c:1645  */
     { current_type = NULL; }
-#line 2414 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2444 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 56:
-#line 484 "src/parse-gram.y" /* yacc.c:1645  */
-    { current_type = (yyvsp[0].uniqstr); tag_seen = true; }
-#line 2420 "src/parse-gram.c" /* yacc.c:1645  */
+#line 475 "src/parse-gram.y" /* yacc.c:1645  */
+    { current_type = (*(uniqstr*)(&yyvsp[0])); tag_seen = true; }
+#line 2450 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 57:
-#line 490 "src/parse-gram.y" /* yacc.c:1645  */
-    { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-#line 2426 "src/parse-gram.c" /* yacc.c:1645  */
+#line 481 "src/parse-gram.y" /* yacc.c:1645  */
+    { (*(symbol_list**)(&yyval)) = symbol_list_sym_new ((*(symbol**)(&yyvsp[0])), (yylsp[0])); }
+#line 2456 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 58:
-#line 492 "src/parse-gram.y" /* yacc.c:1645  */
-    { (yyval.list) = symbol_list_append ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
-#line 2432 "src/parse-gram.c" /* yacc.c:1645  */
+#line 483 "src/parse-gram.y" /* yacc.c:1645  */
+    { (*(symbol_list**)(&yyval)) = symbol_list_append ((*(symbol_list**)(&yyvsp[-1])), symbol_list_sym_new ((*(symbol**)(&yyvsp[0])), (yylsp[0]))); }
+#line 2462 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 59:
-#line 497 "src/parse-gram.y" /* yacc.c:1645  */
+#line 488 "src/parse-gram.y" /* yacc.c:1645  */
     {
-      (yyval.symbol) = (yyvsp[0].symbol);
-      symbol_class_set ((yyvsp[0].symbol), token_sym, (yylsp[0]), false);
+      (*(symbol**)(&yyval)) = (*(symbol**)(&yyvsp[0]));
+      symbol_class_set ((*(symbol**)(&yyvsp[0])), token_sym, (yylsp[0]), false);
     }
-#line 2441 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2471 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 60:
-#line 502 "src/parse-gram.y" /* yacc.c:1645  */
+#line 493 "src/parse-gram.y" /* yacc.c:1645  */
     {
-      (yyval.symbol) = (yyvsp[-1].symbol);
-      symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0]));
-      symbol_class_set ((yyvsp[-1].symbol), token_sym, (yylsp[-1]), false);
+      (*(symbol**)(&yyval)) = (*(symbol**)(&yyvsp[-1]));
+      symbol_user_token_number_set ((*(symbol**)(&yyvsp[-1])), (*(int*)(&yyvsp[0])), (yylsp[0]));
+      symbol_class_set ((*(symbol**)(&yyvsp[-1])), token_sym, (yylsp[-1]), false);
     }
-#line 2451 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2481 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 61:
-#line 512 "src/parse-gram.y" /* yacc.c:1645  */
-    { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-#line 2457 "src/parse-gram.c" /* yacc.c:1645  */
+#line 503 "src/parse-gram.y" /* yacc.c:1645  */
+    { (*(symbol_list**)(&yyval)) = symbol_list_sym_new ((*(symbol**)(&yyvsp[0])), (yylsp[0])); }
+#line 2487 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 62:
-#line 514 "src/parse-gram.y" /* yacc.c:1645  */
-    { (yyval.list) = symbol_list_append ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
-#line 2463 "src/parse-gram.c" /* yacc.c:1645  */
+#line 505 "src/parse-gram.y" /* yacc.c:1645  */
+    { (*(symbol_list**)(&yyval)) = symbol_list_append ((*(symbol_list**)(&yyvsp[-1])), symbol_list_sym_new ((*(symbol**)(&yyvsp[0])), (yylsp[0]))); }
+#line 2493 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 63:
-#line 518 "src/parse-gram.y" /* yacc.c:1645  */
-    { (yyval.list) = (yyvsp[0].list); }
-#line 2469 "src/parse-gram.c" /* yacc.c:1645  */
+#line 509 "src/parse-gram.y" /* yacc.c:1645  */
+    { (*(symbol_list**)(&yyval)) = (*(symbol_list**)(&yyvsp[0])); }
+#line 2499 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 64:
-#line 519 "src/parse-gram.y" /* yacc.c:1645  */
-    { (yyval.list) = symbol_list_append ((yyvsp[-1].list), (yyvsp[0].list)); }
-#line 2475 "src/parse-gram.c" /* yacc.c:1645  */
+#line 510 "src/parse-gram.y" /* yacc.c:1645  */
+    { (*(symbol_list**)(&yyval)) = symbol_list_append ((*(symbol_list**)(&yyvsp[-1])), (*(symbol_list**)(&yyvsp[0]))); }
+#line 2505 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 65:
-#line 523 "src/parse-gram.y" /* yacc.c:1645  */
-    { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-#line 2481 "src/parse-gram.c" /* yacc.c:1645  */
+#line 514 "src/parse-gram.y" /* yacc.c:1645  */
+    { (*(symbol_list**)(&yyval)) = symbol_list_sym_new ((*(symbol**)(&yyvsp[0])), (yylsp[0])); }
+#line 2511 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 66:
-#line 524 "src/parse-gram.y" /* yacc.c:1645  */
-    { (yyval.list) = symbol_list_type_new ((yyvsp[0].uniqstr), (yylsp[0])); }
-#line 2487 "src/parse-gram.c" /* yacc.c:1645  */
+#line 515 "src/parse-gram.y" /* yacc.c:1645  */
+    { (*(symbol_list**)(&yyval)) = symbol_list_type_new ((*(uniqstr*)(&yyvsp[0])), (yylsp[0])); }
+#line 2517 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 68:
-#line 529 "src/parse-gram.y" /* yacc.c:1645  */
-    { (yyval.uniqstr) = uniqstr_new ("*"); }
-#line 2493 "src/parse-gram.c" /* yacc.c:1645  */
+#line 520 "src/parse-gram.y" /* yacc.c:1645  */
+    { (*(uniqstr*)(&yyval)) = uniqstr_new ("*"); }
+#line 2523 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 69:
-#line 530 "src/parse-gram.y" /* yacc.c:1645  */
-    { (yyval.uniqstr) = uniqstr_new (""); }
-#line 2499 "src/parse-gram.c" /* yacc.c:1645  */
+#line 521 "src/parse-gram.y" /* yacc.c:1645  */
+    { (*(uniqstr*)(&yyval)) = uniqstr_new (""); }
+#line 2529 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 70:
-#line 536 "src/parse-gram.y" /* yacc.c:1645  */
+#line 527 "src/parse-gram.y" /* yacc.c:1645  */
     {
-      current_type = (yyvsp[0].uniqstr);
+      current_type = (*(uniqstr*)(&yyvsp[0]));
       tag_seen = true;
     }
-#line 2508 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2538 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 71:
-#line 541 "src/parse-gram.y" /* yacc.c:1645  */
+#line 532 "src/parse-gram.y" /* yacc.c:1645  */
     {
-      symbol_class_set ((yyvsp[0].symbol), current_class, (yylsp[0]), true);
-      symbol_type_set ((yyvsp[0].symbol), current_type, (yylsp[0]));
+      symbol_class_set ((*(symbol**)(&yyvsp[0])), current_class, (yylsp[0]), true);
+      symbol_type_set ((*(symbol**)(&yyvsp[0])), current_type, (yylsp[0]));
     }
-#line 2517 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2547 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 72:
-#line 546 "src/parse-gram.y" /* yacc.c:1645  */
+#line 537 "src/parse-gram.y" /* yacc.c:1645  */
     {
-      symbol_class_set ((yyvsp[-1].symbol), current_class, (yylsp[-1]), true);
-      symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
-      symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0]));
+      symbol_class_set ((*(symbol**)(&yyvsp[-1])), current_class, (yylsp[-1]), true);
+      symbol_type_set ((*(symbol**)(&yyvsp[-1])), current_type, (yylsp[-1]));
+      symbol_user_token_number_set ((*(symbol**)(&yyvsp[-1])), (*(int*)(&yyvsp[0])), (yylsp[0]));
     }
-#line 2527 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2557 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 73:
-#line 552 "src/parse-gram.y" /* yacc.c:1645  */
+#line 543 "src/parse-gram.y" /* yacc.c:1645  */
     {
-      symbol_class_set ((yyvsp[-1].symbol), current_class, (yylsp[-1]), true);
-      symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
-      symbol_make_alias ((yyvsp[-1].symbol), (yyvsp[0].symbol), (yyloc));
+      symbol_class_set ((*(symbol**)(&yyvsp[-1])), current_class, (yylsp[-1]), true);
+      symbol_type_set ((*(symbol**)(&yyvsp[-1])), current_type, (yylsp[-1]));
+      symbol_make_alias ((*(symbol**)(&yyvsp[-1])), (*(symbol**)(&yyvsp[0])), (yyloc));
     }
-#line 2537 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2567 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 74:
-#line 558 "src/parse-gram.y" /* yacc.c:1645  */
+#line 549 "src/parse-gram.y" /* yacc.c:1645  */
     {
-      symbol_class_set ((yyvsp[-2].symbol), current_class, (yylsp[-2]), true);
-      symbol_type_set ((yyvsp[-2].symbol), current_type, (yylsp[-2]));
-      symbol_user_token_number_set ((yyvsp[-2].symbol), (yyvsp[-1].integer), (yylsp[-1]));
-      symbol_make_alias ((yyvsp[-2].symbol), (yyvsp[0].symbol), (yyloc));
+      symbol_class_set ((*(symbol**)(&yyvsp[-2])), current_class, (yylsp[-2]), true);
+      symbol_type_set ((*(symbol**)(&yyvsp[-2])), current_type, (yylsp[-2]));
+      symbol_user_token_number_set ((*(symbol**)(&yyvsp[-2])), (*(int*)(&yyvsp[-1])), (yylsp[-1]));
+      symbol_make_alias ((*(symbol**)(&yyvsp[-2])), (*(symbol**)(&yyvsp[0])), (yyloc));
     }
-#line 2548 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2578 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 81:
-#line 588 "src/parse-gram.y" /* yacc.c:1645  */
+#line 579 "src/parse-gram.y" /* yacc.c:1645  */
     {
       yyerrok;
     }
-#line 2556 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2586 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 82:
-#line 594 "src/parse-gram.y" /* yacc.c:1645  */
-    { current_lhs ((yyvsp[-1].symbol), (yylsp[-1]), (yyvsp[0].named_ref)); }
-#line 2562 "src/parse-gram.c" /* yacc.c:1645  */
+#line 585 "src/parse-gram.y" /* yacc.c:1645  */
+    { current_lhs ((*(symbol**)(&yyvsp[-1])), (yylsp[-1]), (*(named_ref**)(&yyvsp[0]))); }
+#line 2592 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 83:
-#line 595 "src/parse-gram.y" /* yacc.c:1645  */
+#line 586 "src/parse-gram.y" /* yacc.c:1645  */
     {
-    /* Free the current lhs. */
-    current_lhs (0, (yylsp[-3]), 0);
-  }
-#line 2571 "src/parse-gram.c" /* yacc.c:1645  */
+      /* Free the current lhs. */
+      current_lhs (0, (yylsp[-3]), 0);
+    }
+#line 2601 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 84:
-#line 602 "src/parse-gram.y" /* yacc.c:1645  */
+#line 593 "src/parse-gram.y" /* yacc.c:1645  */
     { grammar_current_rule_end ((yylsp[0])); }
-#line 2577 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2607 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 85:
-#line 603 "src/parse-gram.y" /* yacc.c:1645  */
+#line 594 "src/parse-gram.y" /* yacc.c:1645  */
     { grammar_current_rule_end ((yylsp[0])); }
-#line 2583 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2613 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 87:
-#line 610 "src/parse-gram.y" /* yacc.c:1645  */
+#line 601 "src/parse-gram.y" /* yacc.c:1645  */
     { grammar_current_rule_begin (current_lhs_symbol, current_lhs_location,
                                   current_lhs_named_ref); }
-#line 2590 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2620 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 88:
-#line 613 "src/parse-gram.y" /* yacc.c:1645  */
-    { grammar_current_rule_symbol_append ((yyvsp[-1].symbol), (yylsp[-1]), (yyvsp[0].named_ref)); }
-#line 2596 "src/parse-gram.c" /* yacc.c:1645  */
+#line 604 "src/parse-gram.y" /* yacc.c:1645  */
+    { grammar_current_rule_symbol_append ((*(symbol**)(&yyvsp[-1])), (yylsp[-1]), (*(named_ref**)(&yyvsp[0]))); }
+#line 2626 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 89:
-#line 615 "src/parse-gram.y" /* yacc.c:1645  */
-    { grammar_current_rule_action_append ((yyvsp[-1].code), (yylsp[-1]), (yyvsp[0].named_ref), current_type); }
-#line 2602 "src/parse-gram.c" /* yacc.c:1645  */
+#line 606 "src/parse-gram.y" /* yacc.c:1645  */
+    { grammar_current_rule_action_append ((*(char**)(&yyvsp[-1])), (yylsp[-1]), (*(named_ref**)(&yyvsp[0])), current_type); }
+#line 2632 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 90:
-#line 617 "src/parse-gram.y" /* yacc.c:1645  */
-    { grammar_current_rule_predicate_append ((yyvsp[0].code), (yylsp[0])); }
-#line 2608 "src/parse-gram.c" /* yacc.c:1645  */
+#line 608 "src/parse-gram.y" /* yacc.c:1645  */
+    { grammar_current_rule_predicate_append ((*(char**)(&yyvsp[0])), (yylsp[0])); }
+#line 2638 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 91:
-#line 619 "src/parse-gram.y" /* yacc.c:1645  */
+#line 610 "src/parse-gram.y" /* yacc.c:1645  */
     { grammar_current_rule_empty_set ((yylsp[0])); }
-#line 2614 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2644 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 92:
-#line 621 "src/parse-gram.y" /* yacc.c:1645  */
-    { grammar_current_rule_prec_set ((yyvsp[0].symbol), (yylsp[0])); }
-#line 2620 "src/parse-gram.c" /* yacc.c:1645  */
+#line 612 "src/parse-gram.y" /* yacc.c:1645  */
+    { grammar_current_rule_prec_set ((*(symbol**)(&yyvsp[0])), (yylsp[0])); }
+#line 2650 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 93:
-#line 623 "src/parse-gram.y" /* yacc.c:1645  */
-    { grammar_current_rule_dprec_set ((yyvsp[0].integer), (yylsp[0])); }
-#line 2626 "src/parse-gram.c" /* yacc.c:1645  */
+#line 614 "src/parse-gram.y" /* yacc.c:1645  */
+    { grammar_current_rule_dprec_set ((*(int*)(&yyvsp[0])), (yylsp[0])); }
+#line 2656 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 94:
-#line 625 "src/parse-gram.y" /* yacc.c:1645  */
-    { grammar_current_rule_merge_set ((yyvsp[0].uniqstr), (yylsp[0])); }
-#line 2632 "src/parse-gram.c" /* yacc.c:1645  */
+#line 616 "src/parse-gram.y" /* yacc.c:1645  */
+    { grammar_current_rule_merge_set ((*(uniqstr*)(&yyvsp[0])), (yylsp[0])); }
+#line 2662 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 95:
-#line 629 "src/parse-gram.y" /* yacc.c:1645  */
-    { (yyval.named_ref) = 0; }
-#line 2638 "src/parse-gram.c" /* yacc.c:1645  */
+#line 620 "src/parse-gram.y" /* yacc.c:1645  */
+    { (*(named_ref**)(&yyval)) = 0; }
+#line 2668 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 96:
-#line 630 "src/parse-gram.y" /* yacc.c:1645  */
-    { (yyval.named_ref) = named_ref_new ((yyvsp[0].uniqstr), (yylsp[0])); }
-#line 2644 "src/parse-gram.c" /* yacc.c:1645  */
+#line 621 "src/parse-gram.y" /* yacc.c:1645  */
+    { (*(named_ref**)(&yyval)) = named_ref_new ((*(uniqstr*)(&yyvsp[0])), (yylsp[0])); }
+#line 2674 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 98:
-#line 641 "src/parse-gram.y" /* yacc.c:1645  */
-    { (yyval.uniqstr) = uniqstr_new ((yyvsp[0].code)); }
-#line 2650 "src/parse-gram.c" /* yacc.c:1645  */
+#line 654 "src/parse-gram.y" /* yacc.c:1645  */
+    { (*(value_type*)(&yyval)).kind = muscle_keyword; (*(value_type*)(&yyval)).chars = ""; }
+#line 2680 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 99:
-#line 666 "src/parse-gram.y" /* yacc.c:1645  */
-    { (yyval.value).kind = muscle_keyword; (yyval.value).chars = ""; }
-#line 2656 "src/parse-gram.c" /* yacc.c:1645  */
+#line 655 "src/parse-gram.y" /* yacc.c:1645  */
+    { (*(value_type*)(&yyval)).kind = muscle_keyword; (*(value_type*)(&yyval)).chars = (*(uniqstr*)(&yyvsp[0])); }
+#line 2686 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 100:
-#line 667 "src/parse-gram.y" /* yacc.c:1645  */
-    { (yyval.value).kind = muscle_keyword; (yyval.value).chars = (yyvsp[0].uniqstr); }
-#line 2662 "src/parse-gram.c" /* yacc.c:1645  */
+#line 656 "src/parse-gram.y" /* yacc.c:1645  */
+    { (*(value_type*)(&yyval)).kind = muscle_string;  (*(value_type*)(&yyval)).chars = (*(char**)(&yyvsp[0])); }
+#line 2692 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 101:
-#line 668 "src/parse-gram.y" /* yacc.c:1645  */
-    { (yyval.value).kind = muscle_string;  (yyval.value).chars = (yyvsp[0].code); }
-#line 2668 "src/parse-gram.c" /* yacc.c:1645  */
+#line 657 "src/parse-gram.y" /* yacc.c:1645  */
+    { (*(value_type*)(&yyval)).kind = muscle_code;    (*(value_type*)(&yyval)).chars = strip_braces ((*(char**)(&yyvsp[0]))); }
+#line 2698 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 102:
-#line 669 "src/parse-gram.y" /* yacc.c:1645  */
-    { (yyval.value).kind = muscle_code;    (yyval.value).chars = strip_braces ((yyvsp[0].code)); }
-#line 2674 "src/parse-gram.c" /* yacc.c:1645  */
+#line 670 "src/parse-gram.y" /* yacc.c:1645  */
+    { (*(symbol**)(&yyval)) = symbol_from_uniqstr ((*(uniqstr*)(&yyvsp[0])), (yylsp[0])); }
+#line 2704 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 103:
-#line 682 "src/parse-gram.y" /* yacc.c:1645  */
-    { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
-#line 2680 "src/parse-gram.c" /* yacc.c:1645  */
-    break;
-
-  case 104:
-#line 684 "src/parse-gram.y" /* yacc.c:1645  */
+#line 672 "src/parse-gram.y" /* yacc.c:1645  */
     {
-      (yyval.symbol) = symbol_get (char_name ((yyvsp[0].character)), (yylsp[0]));
-      symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
-      symbol_user_token_number_set ((yyval.symbol), (yyvsp[0].character), (yylsp[0]));
+      (*(symbol**)(&yyval)) = symbol_get (char_name ((*(unsigned char*)(&yyvsp[0]))), (yylsp[0]));
+      symbol_class_set ((*(symbol**)(&yyval)), token_sym, (yylsp[0]), false);
+      symbol_user_token_number_set ((*(symbol**)(&yyval)), (*(unsigned char*)(&yyvsp[0])), (yylsp[0]));
     }
-#line 2690 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2714 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
-  case 105:
-#line 692 "src/parse-gram.y" /* yacc.c:1645  */
-    { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
-#line 2696 "src/parse-gram.c" /* yacc.c:1645  */
+  case 104:
+#line 680 "src/parse-gram.y" /* yacc.c:1645  */
+    { (*(symbol**)(&yyval)) = symbol_from_uniqstr ((*(uniqstr*)(&yyvsp[0])), (yylsp[0])); }
+#line 2720 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
-  case 108:
-#line 704 "src/parse-gram.y" /* yacc.c:1645  */
+  case 107:
+#line 692 "src/parse-gram.y" /* yacc.c:1645  */
     {
-      (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[0].code)), (yylsp[0]));
-      symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
+      (*(symbol**)(&yyval)) = symbol_get (quotearg_style (c_quoting_style, (*(char**)(&yyvsp[0]))), (yylsp[0]));
+      symbol_class_set ((*(symbol**)(&yyval)), token_sym, (yylsp[0]), false);
     }
-#line 2705 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2729 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
-  case 110:
-#line 713 "src/parse-gram.y" /* yacc.c:1645  */
+  case 109:
+#line 701 "src/parse-gram.y" /* yacc.c:1645  */
     {
-      muscle_code_grow ("epilogue", translate_code ((yyvsp[0].code), (yylsp[0]), true), (yylsp[0]));
+      muscle_code_grow ("epilogue", translate_code ((*(char**)(&yyvsp[0])), (yylsp[0]), true), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2714 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2738 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
 
-#line 2718 "src/parse-gram.c" /* yacc.c:1645  */
+#line 2742 "src/parse-gram.c" /* yacc.c:1645  */
         default: break;
       }
     if (yychar_backup != yychar)
@@ -2959,7 +2983,7 @@ yyreturn:
 #endif
   return yyresult;
 }
-#line 719 "src/parse-gram.y" /* yacc.c:1903  */
+#line 707 "src/parse-gram.y" /* yacc.c:1903  */
 
 
 /* Return the location of the left-hand side of a rule whose
