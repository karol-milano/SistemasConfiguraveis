@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 3.2.1.9-1e55d.  */
+/* A Bison parser, made by GNU Bison 3.2.2.  */
 
 /* Bison implementation for Yacc-like parsers in C
 
@@ -47,7 +47,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "3.2.1.9-1e55d"
+#define YYBISON_VERSION "3.2.2"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -133,7 +133,7 @@ extern int gram_debug;
     param_parse  = 1 << 1,
     param_both   = param_lex | param_parse
   } param_type;
-#line 608 "src/parse-gram.y" /* yacc.c:353  */
+#line 612 "src/parse-gram.y" /* yacc.c:353  */
 
   #include "muscle-tab.h"
   typedef struct
@@ -590,16 +590,16 @@ union yyalloc
 /* YYFINAL -- State number of the termination state.  */
 #define YYFINAL  3
 /* YYLAST -- Last index in YYTABLE.  */
-#define YYLAST   180
+#define YYLAST   172
 
 /* YYNTOKENS -- Number of terminals.  */
 #define YYNTOKENS  57
 /* YYNNTS -- Number of nonterminals.  */
 #define YYNNTS  37
 /* YYNRULES -- Number of rules.  */
-#define YYNRULES  108
+#define YYNRULES  110
 /* YYNSTATES -- Number of states.  */
-#define YYNSTATES  143
+#define YYNSTATES  147
 
 #define YYUNDEFTOK  2
 #define YYMAXUTOK   311
@@ -660,8 +660,9 @@ static const yytype_uint16 yyrline[] =
      476,   478,   483,   484,   488,   489,   493,   494,   495,   500,
      505,   510,   516,   522,   533,   534,   543,   544,   550,   551,
      552,   559,   559,   567,   568,   569,   574,   577,   579,   581,
-     583,   585,   587,   589,   594,   595,   604,   628,   629,   630,
-     631,   643,   645,   654,   659,   660,   665,   673,   674
+     583,   585,   587,   589,   591,   593,   598,   599,   608,   632,
+     633,   634,   635,   647,   649,   658,   663,   664,   669,   677,
+     678
 };
 #endif
 
@@ -709,12 +710,12 @@ static const yytype_uint16 yytoknum[] =
 };
 # endif
 
-#define YYPACT_NINF -114
+#define YYPACT_NINF -123
 
 #define yypact_value_is_default(Yystate) \
-  (!!((Yystate) == (-114)))
+  (!!((Yystate) == (-123)))
 
-#define YYTABLE_NINF -108
+#define YYTABLE_NINF -110
 
 #define yytable_value_is_error(Yytable_value) \
   0
@@ -723,21 +724,21 @@ static const yytype_uint16 yytoknum[] =
      STATE-NUM.  */
 static const yytype_int8 yypact[] =
 {
-    -114,     5,   125,  -114,  -114,  -114,   -25,  -114,  -114,  -114,
-    -114,  -114,  -114,   -23,  -114,    -7,    25,   -15,   -14,  -114,
-      37,  -114,     3,    41,    46,  -114,  -114,  -114,    49,    50,
-      51,     1,  -114,  -114,  -114,    54,  -114,  -114,  -114,    24,
-    -114,  -114,    31,  -114,  -114,    26,   -21,   -21,     1,  -114,
-      39,  -114,    29,  -114,  -114,  -114,  -114,  -114,  -114,  -114,
-    -114,  -114,  -114,  -114,  -114,  -114,  -114,  -114,  -114,    30,
-    -114,    34,     2,  -114,  -114,    38,    55,  -114,    56,    40,
-    -114,     1,  -114,  -114,   -21,    -2,   -21,     1,  -114,  -114,
-    -114,  -114,  -114,  -114,  -114,  -114,    47,  -114,  -114,  -114,
-    -114,  -114,    58,  -114,  -114,  -114,  -114,    40,  -114,  -114,
-    -114,     1,  -114,    44,  -114,    97,  -114,  -114,  -114,  -114,
-    -114,  -114,  -114,  -114,  -114,   -16,    72,  -114,  -114,     1,
-      48,    52,  -114,  -114,    65,    38,    72,  -114,  -114,  -114,
-      38,  -114,  -114
+    -123,    25,   117,  -123,  -123,  -123,   -22,  -123,  -123,  -123,
+    -123,  -123,  -123,   -17,  -123,    -9,    34,   -15,   -14,  -123,
+      37,  -123,     3,    40,    46,  -123,  -123,  -123,    49,    50,
+      51,    28,  -123,  -123,  -123,    54,  -123,  -123,  -123,    29,
+    -123,  -123,    38,  -123,  -123,    31,   -21,   -21,    28,  -123,
+      52,  -123,    30,  -123,  -123,  -123,  -123,  -123,  -123,  -123,
+    -123,  -123,  -123,  -123,  -123,  -123,  -123,  -123,  -123,    26,
+    -123,    47,     2,  -123,  -123,    57,    53,  -123,    62,    42,
+    -123,    28,  -123,  -123,   -21,    -2,   -21,    28,  -123,  -123,
+    -123,  -123,  -123,  -123,  -123,  -123,    45,  -123,  -123,  -123,
+    -123,  -123,    63,  -123,  -123,  -123,  -123,    42,  -123,  -123,
+    -123,    28,  -123,    36,  -123,   101,  -123,  -123,  -123,  -123,
+    -123,  -123,  -123,  -123,  -123,   -23,    64,  -123,  -123,    28,
+      58,    56,    59,    60,  -123,  -123,    72,    57,    64,  -123,
+    -123,  -123,  -123,  -123,    57,  -123,  -123
 };
 
   /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
@@ -750,32 +751,32 @@ static const yytype_uint8 yydefact[] =
        0,    14,     0,     0,     0,    36,    18,    19,     0,     0,
        0,     0,    25,    26,    27,     0,     6,    28,    21,    41,
        4,     5,     0,    32,    31,    54,     0,     0,     0,    37,
-       0,    96,    97,    10,    11,    12,    13,    15,    16,    17,
-      20,    23,    24,   106,   102,   101,   104,    33,   105,     0,
-     103,     0,     0,    76,    78,    94,     0,    42,     0,     0,
+       0,    98,    99,    10,    11,    12,    13,    15,    16,    17,
+      20,    23,    24,   108,   104,   103,   106,    33,   107,     0,
+     105,     0,     0,    76,    78,    96,     0,    42,     0,     0,
       55,     0,    69,    74,    47,    70,    45,    48,    60,    38,
-      99,   100,    98,     8,    80,    79,     0,    77,     2,    95,
+     101,   102,   100,     8,    80,    79,     0,    77,     2,    97,
       81,    30,    22,    43,    66,    67,    68,    34,    62,    65,
-      64,    49,    56,    58,    75,    71,    72,    61,   108,    86,
+      64,    49,    56,    58,    75,    71,    72,    61,   110,    86,
       29,    63,    57,    59,    73,    82,    83,    86,    85,     0,
-       0,     0,    89,    90,     0,    94,    84,    91,    92,    93,
-      94,    87,    88
+       0,     0,     0,     0,    89,    90,     0,    96,    84,    91,
+      92,    93,    94,    95,    96,    87,    88
 };
 
   /* YYPGOTO[NTERM-NUM].  */
 static const yytype_int8 yypgoto[] =
 {
-    -114,  -114,  -114,  -114,  -114,  -114,   102,  -114,  -114,  -114,
-    -114,  -114,  -114,  -114,    61,  -114,    -4,  -114,  -114,     7,
-    -114,   -60,    68,  -114,    36,  -114,  -114,  -114,   -10,  -113,
-    -114,  -114,   -12,  -114,   -31,   -69,  -114
+    -123,  -123,  -123,  -123,  -123,  -123,   113,  -123,  -123,  -123,
+    -123,  -123,  -123,  -123,    71,  -123,     6,  -123,  -123,    11,
+    -123,   -52,    83,  -123,    84,  -123,  -123,  -123,    -8,  -122,
+    -123,  -123,   -42,  -123,   -31,   -69,  -123
 };
 
   /* YYDEFGOTO[NTERM-NUM].  */
 static const yytype_int16 yydefgoto[] =
 {
       -1,     1,     2,    40,    76,   102,    71,    42,    78,    43,
-      47,    46,    44,    45,   134,   111,   112,    87,   107,   108,
+      47,    46,    44,    45,   136,   111,   112,    87,   107,   108,
      109,    83,    84,    72,    73,    74,   119,   125,   126,   100,
       52,    93,    66,    75,   110,    68,    98
 };
@@ -785,48 +786,46 @@ static const yytype_int16 yydefgoto[] =
      number is the opposite.  If YYTABLE_NINF, syntax error.  */
 static const yytype_int16 yytable[] =
 {
-      67,    63,  -107,    69,    63,     3,     4,     5,     6,     7,
-       8,     9,    10,    11,    12,    49,   116,    88,    13,    14,
-      64,    50,   141,    65,   114,    48,   114,   142,    53,    82,
-      25,   127,    90,   128,    85,    85,    31,    51,    54,    55,
-      56,    57,    64,    63,    58,    65,   124,    70,    96,    59,
+      67,    63,  -109,    69,    85,    85,     4,     5,     6,     7,
+       8,     9,    10,    11,    12,   145,   116,    88,    13,    14,
+      64,    49,   146,    65,   127,     3,   128,    50,    48,    82,
+      25,    63,   114,    90,   114,    51,    31,    53,    54,    55,
+      56,    57,    85,    58,    85,    63,   124,    70,    96,    59,
      113,   115,    60,    61,    62,    69,   117,    39,     4,     5,
-       6,     7,     8,     9,    10,    11,    12,    91,    77,    79,
-      13,    14,    85,    92,    85,    63,    80,    89,    99,    94,
-     113,    64,    25,    95,    65,   129,   130,   131,    31,   118,
-     104,   105,   106,   101,   103,   135,   120,   123,   137,    70,
-      63,   138,   139,   140,    41,   135,    81,   122,    97,    39,
-     -54,   132,     0,    64,   121,    86,    65,   136,     0,     0,
-       0,     0,    80,     0,     0,     0,     0,     0,   133,     4,
-       5,     6,     7,     8,     9,    10,    11,    12,     0,     0,
-       0,    13,    14,    15,    16,    17,    18,    19,    20,    21,
-      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
-      32,    33,    34,     0,     0,     0,     0,     0,     0,     0,
-       0,    35,     0,    36,    37,     0,     0,     0,     0,    38,
-      39
+       6,     7,     8,     9,    10,    11,    12,    63,    91,    64,
+      13,    14,    65,    77,    92,    94,    79,   129,   130,   131,
+     113,    80,    25,    64,   132,   133,    65,   118,    31,   123,
+      89,   101,   104,   105,   106,   137,    95,    99,   139,    70,
+     103,   120,   -54,   134,    63,    64,   141,   137,    65,    39,
+     144,   140,   142,   143,    80,    41,    81,   122,   121,   138,
+     135,     4,     5,     6,     7,     8,     9,    10,    11,    12,
+      86,     0,     0,    13,    14,    15,    16,    17,    18,    19,
+      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
+      30,    31,    32,    33,    34,     0,    97,     0,     0,     0,
+       0,     0,     0,    35,     0,    36,    37,     0,     0,     0,
+       0,    38,    39
 };
 
 static const yytype_int16 yycheck[] =
 {
-      31,     3,     0,     1,     3,     0,     4,     5,     6,     7,
-       8,     9,    10,    11,    12,    38,    85,    48,    16,    17,
-      41,    44,   135,    44,    84,    50,    86,   140,     3,    50,
-      28,    47,     3,    49,    46,    47,    34,    44,    53,    53,
-       3,    38,    41,     3,     3,    44,   115,    45,    46,     3,
+      31,     3,     0,     1,    46,    47,     4,     5,     6,     7,
+       8,     9,    10,    11,    12,   137,    85,    48,    16,    17,
+      41,    38,   144,    44,    47,     0,    49,    44,    50,    50,
+      28,     3,    84,     3,    86,    44,    34,     3,    53,    53,
+       3,    38,    84,     3,    86,     3,   115,    45,    46,     3,
       81,    53,     3,     3,     3,     1,    87,    55,     4,     5,
-       6,     7,     8,     9,    10,    11,    12,    38,    44,    38,
-      16,    17,    84,    44,    86,     3,    50,    38,    40,    49,
-     111,    41,    28,    49,    44,    13,    14,    15,    34,    42,
-      50,    51,    52,    38,    38,   126,    38,    53,   129,    45,
-       3,    53,    50,    38,     2,   136,    45,   111,    72,    55,
-      38,    39,    -1,    41,   107,    47,    44,   127,    -1,    -1,
-      -1,    -1,    50,    -1,    -1,    -1,    -1,    -1,    56,     4,
-       5,     6,     7,     8,     9,    10,    11,    12,    -1,    -1,
-      -1,    16,    17,    18,    19,    20,    21,    22,    23,    24,
-      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
-      35,    36,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
-      -1,    46,    -1,    48,    49,    -1,    -1,    -1,    -1,    54,
-      55
+       6,     7,     8,     9,    10,    11,    12,     3,    38,    41,
+      16,    17,    44,    44,    44,    49,    38,    13,    14,    15,
+     111,    50,    28,    41,    20,    21,    44,    42,    34,    53,
+      38,    38,    50,    51,    52,   126,    49,    40,   129,    45,
+      38,    38,    38,    39,     3,    41,    50,   138,    44,    55,
+      38,    53,    53,    53,    50,     2,    45,   111,   107,   127,
+      56,     4,     5,     6,     7,     8,     9,    10,    11,    12,
+      47,    -1,    -1,    16,    17,    18,    19,    20,    21,    22,
+      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
+      33,    34,    35,    36,    37,    -1,    72,    -1,    -1,    -1,
+      -1,    -1,    -1,    46,    -1,    48,    49,    -1,    -1,    -1,
+      -1,    54,    55
 };
 
   /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
@@ -846,8 +845,8 @@ static const yytype_uint8 yystos[] =
       86,    38,    62,    38,    50,    51,    52,    75,    76,    77,
       91,    72,    73,    91,    78,    53,    92,    91,    42,    83,
       38,    76,    73,    53,    92,    84,    85,    47,    49,    13,
-      14,    15,    39,    56,    71,    91,    85,    91,    53,    50,
-      38,    86,    86
+      14,    15,    20,    21,    39,    56,    71,    91,    85,    91,
+      53,    50,    53,    53,    38,    86,    86
 };
 
   /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
@@ -862,8 +861,9 @@ static const yytype_uint8 yyr1[] =
       74,    74,    75,    75,    76,    76,    77,    77,    77,    78,
       78,    78,    78,    78,    79,    79,    80,    80,    81,    81,
       81,    83,    82,    84,    84,    84,    85,    85,    85,    85,
-      85,    85,    85,    85,    86,    86,    87,    88,    88,    88,
-      88,    89,    89,    90,    91,    91,    92,    93,    93
+      85,    85,    85,    85,    85,    85,    86,    86,    87,    88,
+      88,    88,    88,    89,    89,    90,    91,    91,    92,    93,
+      93
 };
 
   /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
@@ -878,8 +878,9 @@ static const yytype_uint8 yyr2[] =
        1,     2,     1,     2,     1,     1,     1,     1,     1,     1,
        1,     2,     2,     3,     1,     2,     1,     2,     1,     2,
        2,     0,     4,     1,     3,     2,     0,     3,     4,     2,
-       2,     3,     3,     3,     0,     1,     1,     0,     1,     1,
-       1,     1,     1,     1,     1,     1,     1,     0,     2
+       2,     3,     3,     3,     3,     3,     0,     1,     1,     0,
+       1,     1,     1,     1,     1,     1,     1,     1,     1,     0,
+       2
 };
 
 
@@ -895,23 +896,23 @@ static const yytype_uint8 yyr2[] =
 
 #define YYRECOVERING()  (!!yyerrstatus)
 
-#define YYBACKUP(Token, Value)                                  \
-do                                                              \
-  if (yychar == YYEMPTY)                                        \
-    {                                                           \
-      yychar = (Token);                                         \
-      yylval = (Value);                                         \
-      YYPOPSTACK (yylen);                                       \
-      yystate = *yyssp;                                         \
-      YY_LAC_DISCARD ("YYBACKUP");                              \
-      goto yybackup;                                            \
-    }                                                           \
-  else                                                          \
-    {                                                           \
-      yyerror (&yylloc, YY_("syntax error: cannot back up")); \
-      YYERROR;                                                  \
-    }                                                           \
-while (0)
+#define YYBACKUP(Token, Value)                                    \
+  do                                                              \
+    if (yychar == YYEMPTY)                                        \
+      {                                                           \
+        yychar = (Token);                                         \
+        yylval = (Value);                                         \
+        YYPOPSTACK (yylen);                                       \
+        yystate = *yyssp;                                         \
+        YY_LAC_DISCARD ("YYBACKUP");                              \
+        goto yybackup;                                            \
+      }                                                           \
+    else                                                          \
+      {                                                           \
+        yyerror (&yylloc, YY_("syntax error: cannot back up")); \
+        YYERROR;                                                  \
+      }                                                           \
+  while (0)
 
 /* Error token number */
 #define YYTERROR        1
@@ -1037,73 +1038,73 @@ yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YY
           case 3: /* "string"  */
 #line 191 "src/parse-gram.y" /* yacc.c:681  */
       { fputs (quotearg_style (c_quoting_style, (*(char**)(&(*yyvaluep)))), yyo); }
-#line 1041 "src/parse-gram.c" /* yacc.c:681  */
+#line 1042 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 22: /* "%<flag>"  */
 #line 198 "src/parse-gram.y" /* yacc.c:681  */
       { fprintf (yyo, "%%%s", (*(uniqstr*)(&(*yyvaluep)))); }
-#line 1047 "src/parse-gram.c" /* yacc.c:681  */
+#line 1048 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 38: /* "{...}"  */
 #line 192 "src/parse-gram.y" /* yacc.c:681  */
       { fprintf (yyo, "{\n%s\n}", (*(char**)(&(*yyvaluep)))); }
-#line 1053 "src/parse-gram.c" /* yacc.c:681  */
+#line 1054 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 39: /* "%?{...}"  */
 #line 192 "src/parse-gram.y" /* yacc.c:681  */
       { fprintf (yyo, "{\n%s\n}", (*(char**)(&(*yyvaluep)))); }
-#line 1059 "src/parse-gram.c" /* yacc.c:681  */
+#line 1060 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 40: /* "[identifier]"  */
 #line 196 "src/parse-gram.y" /* yacc.c:681  */
       { fprintf (yyo, "[%s]", (*(uniqstr*)(&(*yyvaluep)))); }
-#line 1065 "src/parse-gram.c" /* yacc.c:681  */
+#line 1066 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 41: /* "char"  */
 #line 188 "src/parse-gram.y" /* yacc.c:681  */
       { fputs (char_name ((*(unsigned char*)(&(*yyvaluep)))), yyo); }
-#line 1071 "src/parse-gram.c" /* yacc.c:681  */
+#line 1072 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 42: /* "epilogue"  */
 #line 192 "src/parse-gram.y" /* yacc.c:681  */
       { fprintf (yyo, "{\n%s\n}", (*(char**)(&(*yyvaluep)))); }
-#line 1077 "src/parse-gram.c" /* yacc.c:681  */
+#line 1078 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 44: /* "identifier"  */
 #line 195 "src/parse-gram.y" /* yacc.c:681  */
       { fputs ((*(uniqstr*)(&(*yyvaluep))), yyo); }
-#line 1083 "src/parse-gram.c" /* yacc.c:681  */
+#line 1084 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 45: /* "identifier:"  */
 #line 197 "src/parse-gram.y" /* yacc.c:681  */
       { fprintf (yyo, "%s:", (*(uniqstr*)(&(*yyvaluep)))); }
-#line 1089 "src/parse-gram.c" /* yacc.c:681  */
+#line 1090 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 48: /* "%{...%}"  */
 #line 192 "src/parse-gram.y" /* yacc.c:681  */
       { fprintf (yyo, "{\n%s\n}", (*(char**)(&(*yyvaluep)))); }
-#line 1095 "src/parse-gram.c" /* yacc.c:681  */
+#line 1096 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 50: /* "<tag>"  */
 #line 199 "src/parse-gram.y" /* yacc.c:681  */
       { fprintf (yyo, "<%s>", (*(uniqstr*)(&(*yyvaluep)))); }
-#line 1101 "src/parse-gram.c" /* yacc.c:681  */
+#line 1102 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 53: /* "integer"  */
 #line 202 "src/parse-gram.y" /* yacc.c:681  */
       { fprintf (yyo, "%d", (*(int*)(&(*yyvaluep)))); }
-#line 1107 "src/parse-gram.c" /* yacc.c:681  */
+#line 1108 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 54: /* "%param"  */
@@ -1120,35 +1121,35 @@ yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YY
       case param_none: aver (false); break;
     }
 }
-#line 1124 "src/parse-gram.c" /* yacc.c:681  */
+#line 1125 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 64: /* code_props_type  */
 #line 375 "src/parse-gram.y" /* yacc.c:681  */
       { fprintf (yyo, "%s", code_props_type_string ((*(code_props_type*)(&(*yyvaluep))))); }
-#line 1130 "src/parse-gram.c" /* yacc.c:681  */
+#line 1131 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 73: /* symbol.prec  */
 #line 205 "src/parse-gram.y" /* yacc.c:681  */
       { fprintf (yyo, "%s", (*(symbol**)(&(*yyvaluep)))->tag); }
-#line 1136 "src/parse-gram.c" /* yacc.c:681  */
+#line 1137 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 77: /* tag  */
 #line 199 "src/parse-gram.y" /* yacc.c:681  */
       { fprintf (yyo, "<%s>", (*(uniqstr*)(&(*yyvaluep)))); }
-#line 1142 "src/parse-gram.c" /* yacc.c:681  */
+#line 1143 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 87: /* variable  */
 #line 195 "src/parse-gram.y" /* yacc.c:681  */
       { fputs ((*(uniqstr*)(&(*yyvaluep))), yyo); }
-#line 1148 "src/parse-gram.c" /* yacc.c:681  */
+#line 1149 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 88: /* value  */
-#line 618 "src/parse-gram.y" /* yacc.c:681  */
+#line 622 "src/parse-gram.y" /* yacc.c:681  */
       {
   switch ((*(value_type*)(&(*yyvaluep))).kind)
     {
@@ -1157,31 +1158,31 @@ yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YY
     case muscle_string:  fprintf (yyo, "\"%s\"", (*(value_type*)(&(*yyvaluep))).chars); break;
     }
 }
-#line 1161 "src/parse-gram.c" /* yacc.c:681  */
+#line 1162 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 89: /* id  */
 #line 205 "src/parse-gram.y" /* yacc.c:681  */
       { fprintf (yyo, "%s", (*(symbol**)(&(*yyvaluep)))->tag); }
-#line 1167 "src/parse-gram.c" /* yacc.c:681  */
+#line 1168 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 90: /* id_colon  */
 #line 206 "src/parse-gram.y" /* yacc.c:681  */
       { fprintf (yyo, "%s:", (*(symbol**)(&(*yyvaluep)))->tag); }
-#line 1173 "src/parse-gram.c" /* yacc.c:681  */
+#line 1174 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 91: /* symbol  */
 #line 205 "src/parse-gram.y" /* yacc.c:681  */
       { fprintf (yyo, "%s", (*(symbol**)(&(*yyvaluep)))->tag); }
-#line 1179 "src/parse-gram.c" /* yacc.c:681  */
+#line 1180 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 92: /* string_as_id  */
 #line 205 "src/parse-gram.y" /* yacc.c:681  */
       { fprintf (yyo, "%s", (*(symbol**)(&(*yyvaluep)))->tag); }
-#line 1185 "src/parse-gram.c" /* yacc.c:681  */
+#line 1186 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
 
@@ -1883,19 +1884,24 @@ YYLTYPE yylloc = yyloc_default;
   boundary_set (&yylloc.end, current_file, 1, 1);
 }
 
-#line 1887 "src/parse-gram.c" /* yacc.c:1428  */
+#line 1888 "src/parse-gram.c" /* yacc.c:1428  */
   yylsp[0] = yylloc;
   goto yysetstate;
 
+
 /*------------------------------------------------------------.
-| yynewstate -- Push a new state, which is found in yystate.  |
+| yynewstate -- push a new state, which is found in yystate.  |
 `------------------------------------------------------------*/
- yynewstate:
+yynewstate:
   /* In all cases, when you get here, the value and location stacks
      have just been pushed.  So pushing a state here evens the stacks.  */
   yyssp++;
 
- yysetstate:
+
+/*--------------------------------------------------------------------.
+| yynewstate -- set current state (the top of the stack) to yystate.  |
+`--------------------------------------------------------------------*/
+yysetstate:
   *yyssp = (yytype_int16) yystate;
 
   if (yyss + yystacksize - 1 <= yyssp)
@@ -1970,11 +1976,11 @@ YYLTYPE yylloc = yyloc_default;
 
   goto yybackup;
 
+
 /*-----------.
 | yybackup.  |
 `-----------*/
 yybackup:
-
   /* Do appropriate processing given the current state.  Read a
      lookahead token if we need one and don't already have one.  */
 
@@ -2052,7 +2058,7 @@ yydefault:
 
 
 /*-----------------------------.
-| yyreduce -- Do a reduction.  |
+| yyreduce -- do a reduction.  |
 `-----------------------------*/
 yyreduce:
   /* yyn is the number of a rule to reduce with.  */
@@ -2077,177 +2083,177 @@ yyreduce:
     switch (yyn)
       {
   case 6:
-#line 276 "src/parse-gram.y" /* yacc.c:1644  */
+#line 276 "src/parse-gram.y" /* yacc.c:1649  */
     {
       muscle_code_grow (union_seen ? "post_prologue" : "pre_prologue",
                         translate_code ((*(char**)(&yyvsp[0])), (yylsp[0]), true), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2087 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2093 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 7:
-#line 282 "src/parse-gram.y" /* yacc.c:1644  */
+#line 282 "src/parse-gram.y" /* yacc.c:1649  */
     {
       muscle_percent_define_ensure ((*(uniqstr*)(&yyvsp[0])), (yylsp[0]), true);
     }
-#line 2095 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2101 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 8:
-#line 286 "src/parse-gram.y" /* yacc.c:1644  */
+#line 286 "src/parse-gram.y" /* yacc.c:1649  */
     {
       muscle_percent_define_insert ((*(uniqstr*)(&yyvsp[-1])), (yylsp[-1]), (*(value_type*)(&yyvsp[0])).kind, (*(value_type*)(&yyvsp[0])).chars,
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
     }
-#line 2104 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2110 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 9:
-#line 290 "src/parse-gram.y" /* yacc.c:1644  */
+#line 290 "src/parse-gram.y" /* yacc.c:1649  */
     { defines_flag = true; }
-#line 2110 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2116 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 10:
-#line 292 "src/parse-gram.y" /* yacc.c:1644  */
+#line 292 "src/parse-gram.y" /* yacc.c:1649  */
     {
       defines_flag = true;
       spec_defines_file = xstrdup ((*(char**)(&yyvsp[0])));
     }
-#line 2119 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2125 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 11:
-#line 296 "src/parse-gram.y" /* yacc.c:1644  */
+#line 296 "src/parse-gram.y" /* yacc.c:1649  */
     { expected_sr_conflicts = (*(int*)(&yyvsp[0])); }
-#line 2125 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2131 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 12:
-#line 297 "src/parse-gram.y" /* yacc.c:1644  */
+#line 297 "src/parse-gram.y" /* yacc.c:1649  */
     { expected_rr_conflicts = (*(int*)(&yyvsp[0])); }
-#line 2131 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2137 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 13:
-#line 298 "src/parse-gram.y" /* yacc.c:1644  */
+#line 298 "src/parse-gram.y" /* yacc.c:1649  */
     { spec_file_prefix = (*(char**)(&yyvsp[0])); }
-#line 2137 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2143 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 14:
-#line 300 "src/parse-gram.y" /* yacc.c:1644  */
+#line 300 "src/parse-gram.y" /* yacc.c:1649  */
     {
       nondeterministic_parser = true;
       glr_parser = true;
     }
-#line 2146 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2152 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 15:
-#line 305 "src/parse-gram.y" /* yacc.c:1644  */
+#line 305 "src/parse-gram.y" /* yacc.c:1649  */
     {
       muscle_code_grow ("initial_action", translate_code ((*(char**)(&yyvsp[0])), (yylsp[0]), false), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2155 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2161 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 16:
-#line 309 "src/parse-gram.y" /* yacc.c:1644  */
+#line 309 "src/parse-gram.y" /* yacc.c:1649  */
     { language_argmatch ((*(char**)(&yyvsp[0])), grammar_prio, (yylsp[-1])); }
-#line 2161 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2167 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 17:
-#line 310 "src/parse-gram.y" /* yacc.c:1644  */
+#line 310 "src/parse-gram.y" /* yacc.c:1649  */
     { spec_name_prefix = (*(char**)(&yyvsp[0])); }
-#line 2167 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2173 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 18:
-#line 311 "src/parse-gram.y" /* yacc.c:1644  */
+#line 311 "src/parse-gram.y" /* yacc.c:1649  */
     { no_lines_flag = true; }
-#line 2173 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2179 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 19:
-#line 312 "src/parse-gram.y" /* yacc.c:1644  */
+#line 312 "src/parse-gram.y" /* yacc.c:1649  */
     { nondeterministic_parser = true; }
-#line 2179 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2185 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 20:
-#line 313 "src/parse-gram.y" /* yacc.c:1644  */
+#line 313 "src/parse-gram.y" /* yacc.c:1649  */
     { spec_outfile = (*(char**)(&yyvsp[0])); }
-#line 2185 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2191 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 21:
-#line 314 "src/parse-gram.y" /* yacc.c:1644  */
+#line 314 "src/parse-gram.y" /* yacc.c:1649  */
     { current_param = (*(param_type*)(&yyvsp[0])); }
-#line 2191 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2197 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 22:
-#line 314 "src/parse-gram.y" /* yacc.c:1644  */
+#line 314 "src/parse-gram.y" /* yacc.c:1649  */
     { current_param = param_none; }
-#line 2197 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2203 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 23:
-#line 315 "src/parse-gram.y" /* yacc.c:1644  */
+#line 315 "src/parse-gram.y" /* yacc.c:1649  */
     { do_require (&(yylsp[0]), (*(char**)(&yyvsp[0]))); }
-#line 2203 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2209 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 24:
-#line 316 "src/parse-gram.y" /* yacc.c:1644  */
+#line 316 "src/parse-gram.y" /* yacc.c:1649  */
     { do_skeleton (&(yylsp[0]), (*(char**)(&yyvsp[0]))); }
-#line 2209 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2215 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 25:
-#line 317 "src/parse-gram.y" /* yacc.c:1644  */
+#line 317 "src/parse-gram.y" /* yacc.c:1649  */
     { token_table_flag = true; }
-#line 2215 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2221 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 26:
-#line 318 "src/parse-gram.y" /* yacc.c:1644  */
+#line 318 "src/parse-gram.y" /* yacc.c:1649  */
     { report_flag |= report_states; }
-#line 2221 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2227 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 27:
-#line 319 "src/parse-gram.y" /* yacc.c:1644  */
+#line 319 "src/parse-gram.y" /* yacc.c:1649  */
     { yacc_flag = true; }
-#line 2227 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2233 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 29:
-#line 324 "src/parse-gram.y" /* yacc.c:1644  */
+#line 324 "src/parse-gram.y" /* yacc.c:1649  */
     { add_param (current_param, (*(char**)(&yyvsp[0])), (yylsp[0])); }
-#line 2233 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2239 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 30:
-#line 325 "src/parse-gram.y" /* yacc.c:1644  */
+#line 325 "src/parse-gram.y" /* yacc.c:1649  */
     { add_param (current_param, (*(char**)(&yyvsp[0])), (yylsp[0])); }
-#line 2239 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2245 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 33:
-#line 337 "src/parse-gram.y" /* yacc.c:1644  */
+#line 337 "src/parse-gram.y" /* yacc.c:1649  */
     {
       grammar_start_symbol_set ((*(symbol**)(&yyvsp[0])), (yylsp[0]));
     }
-#line 2247 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2253 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 34:
-#line 341 "src/parse-gram.y" /* yacc.c:1644  */
+#line 341 "src/parse-gram.y" /* yacc.c:1649  */
     {
       code_props code;
       code_props_symbol_action_init (&code, (*(char**)(&yyvsp[-1])), (yylsp[-1]));
@@ -2258,27 +2264,27 @@ yyreduce:
         symbol_list_free ((*(symbol_list**)(&yyvsp[0])));
       }
     }
-#line 2262 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2268 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 35:
-#line 352 "src/parse-gram.y" /* yacc.c:1644  */
+#line 352 "src/parse-gram.y" /* yacc.c:1649  */
     {
       default_prec = true;
     }
-#line 2270 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2276 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 36:
-#line 356 "src/parse-gram.y" /* yacc.c:1644  */
+#line 356 "src/parse-gram.y" /* yacc.c:1649  */
     {
       default_prec = false;
     }
-#line 2278 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2284 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 37:
-#line 360 "src/parse-gram.y" /* yacc.c:1644  */
+#line 360 "src/parse-gram.y" /* yacc.c:1649  */
     {
       /* Do not invoke muscle_percent_code_grow here since it invokes
          muscle_user_name_list_grow.  */
@@ -2286,97 +2292,97 @@ yyreduce:
                         translate_code_braceless ((*(char**)(&yyvsp[0])), (yylsp[0])), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2290 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2296 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 38:
-#line 368 "src/parse-gram.y" /* yacc.c:1644  */
+#line 368 "src/parse-gram.y" /* yacc.c:1649  */
     {
       muscle_percent_code_grow ((*(uniqstr*)(&yyvsp[-1])), (yylsp[-1]), translate_code_braceless ((*(char**)(&yyvsp[0])), (yylsp[0])), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2299 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2305 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 39:
-#line 377 "src/parse-gram.y" /* yacc.c:1644  */
+#line 377 "src/parse-gram.y" /* yacc.c:1649  */
     { (*(code_props_type*)(&yyval)) = destructor; }
-#line 2305 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2311 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 40:
-#line 378 "src/parse-gram.y" /* yacc.c:1644  */
+#line 378 "src/parse-gram.y" /* yacc.c:1649  */
     { (*(code_props_type*)(&yyval)) = printer; }
-#line 2311 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2317 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 41:
-#line 388 "src/parse-gram.y" /* yacc.c:1644  */
+#line 388 "src/parse-gram.y" /* yacc.c:1649  */
     {}
-#line 2317 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2323 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 42:
-#line 389 "src/parse-gram.y" /* yacc.c:1644  */
+#line 389 "src/parse-gram.y" /* yacc.c:1649  */
     { muscle_percent_define_insert ("api.value.union.name",
                                          (yylsp[0]), muscle_keyword, (*(uniqstr*)(&yyvsp[0])),
                                          MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE); }
-#line 2325 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2331 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 43:
-#line 396 "src/parse-gram.y" /* yacc.c:1644  */
+#line 396 "src/parse-gram.y" /* yacc.c:1649  */
     {
       union_seen = true;
       muscle_code_grow ("union_members", translate_code_braceless ((*(char**)(&yyvsp[0])), (yylsp[0])), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2335 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2341 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 44:
-#line 407 "src/parse-gram.y" /* yacc.c:1644  */
+#line 407 "src/parse-gram.y" /* yacc.c:1649  */
     { current_class = nterm_sym; }
-#line 2341 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2347 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 45:
-#line 408 "src/parse-gram.y" /* yacc.c:1644  */
+#line 408 "src/parse-gram.y" /* yacc.c:1649  */
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
-#line 2350 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2356 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 46:
-#line 412 "src/parse-gram.y" /* yacc.c:1644  */
+#line 412 "src/parse-gram.y" /* yacc.c:1649  */
     { current_class = token_sym; }
-#line 2356 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2362 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 47:
-#line 413 "src/parse-gram.y" /* yacc.c:1644  */
+#line 413 "src/parse-gram.y" /* yacc.c:1649  */
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
-#line 2365 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2371 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 48:
-#line 418 "src/parse-gram.y" /* yacc.c:1644  */
+#line 418 "src/parse-gram.y" /* yacc.c:1649  */
     {
       tag_seen = true;
       for (symbol_list *list = (*(symbol_list**)(&yyvsp[0])); list; list = list->next)
         symbol_type_set (list->content.sym, (*(uniqstr*)(&yyvsp[-1])), (yylsp[-1]));
       symbol_list_free ((*(symbol_list**)(&yyvsp[0])));
     }
-#line 2376 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2382 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 49:
-#line 428 "src/parse-gram.y" /* yacc.c:1644  */
+#line 428 "src/parse-gram.y" /* yacc.c:1649  */
     {
       ++current_prec;
       for (symbol_list *list = (*(symbol_list**)(&yyvsp[0])); list; list = list->next)
@@ -2387,335 +2393,347 @@ yyreduce:
       symbol_list_free ((*(symbol_list**)(&yyvsp[0])));
       current_type = NULL;
     }
-#line 2391 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2397 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 50:
-#line 441 "src/parse-gram.y" /* yacc.c:1644  */
+#line 441 "src/parse-gram.y" /* yacc.c:1649  */
     { (*(assoc*)(&yyval)) = left_assoc; }
-#line 2397 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2403 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 51:
-#line 442 "src/parse-gram.y" /* yacc.c:1644  */
+#line 442 "src/parse-gram.y" /* yacc.c:1649  */
     { (*(assoc*)(&yyval)) = right_assoc; }
-#line 2403 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2409 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 52:
-#line 443 "src/parse-gram.y" /* yacc.c:1644  */
+#line 443 "src/parse-gram.y" /* yacc.c:1649  */
     { (*(assoc*)(&yyval)) = non_assoc; }
-#line 2409 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2415 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 53:
-#line 444 "src/parse-gram.y" /* yacc.c:1644  */
+#line 444 "src/parse-gram.y" /* yacc.c:1649  */
     { (*(assoc*)(&yyval)) = precedence_assoc; }
-#line 2415 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2421 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 54:
-#line 448 "src/parse-gram.y" /* yacc.c:1644  */
+#line 448 "src/parse-gram.y" /* yacc.c:1649  */
     { current_type = NULL; }
-#line 2421 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2427 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 55:
-#line 449 "src/parse-gram.y" /* yacc.c:1644  */
+#line 449 "src/parse-gram.y" /* yacc.c:1649  */
     { current_type = (*(uniqstr*)(&yyvsp[0])); tag_seen = true; }
-#line 2427 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2433 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 56:
-#line 455 "src/parse-gram.y" /* yacc.c:1644  */
+#line 455 "src/parse-gram.y" /* yacc.c:1649  */
     { (*(symbol_list**)(&yyval)) = symbol_list_sym_new ((*(symbol**)(&yyvsp[0])), (yylsp[0])); }
-#line 2433 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2439 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 57:
-#line 457 "src/parse-gram.y" /* yacc.c:1644  */
+#line 457 "src/parse-gram.y" /* yacc.c:1649  */
     { (*(symbol_list**)(&yyval)) = symbol_list_append ((*(symbol_list**)(&yyvsp[-1])), symbol_list_sym_new ((*(symbol**)(&yyvsp[0])), (yylsp[0]))); }
-#line 2439 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2445 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 58:
-#line 462 "src/parse-gram.y" /* yacc.c:1644  */
+#line 462 "src/parse-gram.y" /* yacc.c:1649  */
     {
       (*(symbol**)(&yyval)) = (*(symbol**)(&yyvsp[0]));
       symbol_class_set ((*(symbol**)(&yyvsp[0])), token_sym, (yylsp[0]), false);
     }
-#line 2448 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2454 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 59:
-#line 467 "src/parse-gram.y" /* yacc.c:1644  */
+#line 467 "src/parse-gram.y" /* yacc.c:1649  */
     {
       (*(symbol**)(&yyval)) = (*(symbol**)(&yyvsp[-1]));
       symbol_user_token_number_set ((*(symbol**)(&yyvsp[-1])), (*(int*)(&yyvsp[0])), (yylsp[0]));
       symbol_class_set ((*(symbol**)(&yyvsp[-1])), token_sym, (yylsp[-1]), false);
     }
-#line 2458 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2464 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 60:
-#line 477 "src/parse-gram.y" /* yacc.c:1644  */
+#line 477 "src/parse-gram.y" /* yacc.c:1649  */
     { (*(symbol_list**)(&yyval)) = symbol_list_sym_new ((*(symbol**)(&yyvsp[0])), (yylsp[0])); }
-#line 2464 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2470 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 61:
-#line 479 "src/parse-gram.y" /* yacc.c:1644  */
+#line 479 "src/parse-gram.y" /* yacc.c:1649  */
     { (*(symbol_list**)(&yyval)) = symbol_list_append ((*(symbol_list**)(&yyvsp[-1])), symbol_list_sym_new ((*(symbol**)(&yyvsp[0])), (yylsp[0]))); }
-#line 2470 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2476 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 62:
-#line 483 "src/parse-gram.y" /* yacc.c:1644  */
+#line 483 "src/parse-gram.y" /* yacc.c:1649  */
     { (*(symbol_list**)(&yyval)) = (*(symbol_list**)(&yyvsp[0])); }
-#line 2476 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2482 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 63:
-#line 484 "src/parse-gram.y" /* yacc.c:1644  */
+#line 484 "src/parse-gram.y" /* yacc.c:1649  */
     { (*(symbol_list**)(&yyval)) = symbol_list_append ((*(symbol_list**)(&yyvsp[-1])), (*(symbol_list**)(&yyvsp[0]))); }
-#line 2482 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2488 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 64:
-#line 488 "src/parse-gram.y" /* yacc.c:1644  */
+#line 488 "src/parse-gram.y" /* yacc.c:1649  */
     { (*(symbol_list**)(&yyval)) = symbol_list_sym_new ((*(symbol**)(&yyvsp[0])), (yylsp[0])); }
-#line 2488 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2494 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 65:
-#line 489 "src/parse-gram.y" /* yacc.c:1644  */
+#line 489 "src/parse-gram.y" /* yacc.c:1649  */
     { (*(symbol_list**)(&yyval)) = symbol_list_type_new ((*(uniqstr*)(&yyvsp[0])), (yylsp[0])); }
-#line 2494 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2500 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 67:
-#line 494 "src/parse-gram.y" /* yacc.c:1644  */
+#line 494 "src/parse-gram.y" /* yacc.c:1649  */
     { (*(uniqstr*)(&yyval)) = uniqstr_new ("*"); }
-#line 2500 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2506 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 68:
-#line 495 "src/parse-gram.y" /* yacc.c:1644  */
+#line 495 "src/parse-gram.y" /* yacc.c:1649  */
     { (*(uniqstr*)(&yyval)) = uniqstr_new (""); }
-#line 2506 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2512 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 69:
-#line 501 "src/parse-gram.y" /* yacc.c:1644  */
+#line 501 "src/parse-gram.y" /* yacc.c:1649  */
     {
       current_type = (*(uniqstr*)(&yyvsp[0]));
       tag_seen = true;
     }
-#line 2515 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2521 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 70:
-#line 506 "src/parse-gram.y" /* yacc.c:1644  */
+#line 506 "src/parse-gram.y" /* yacc.c:1649  */
     {
       symbol_class_set ((*(symbol**)(&yyvsp[0])), current_class, (yylsp[0]), true);
       symbol_type_set ((*(symbol**)(&yyvsp[0])), current_type, (yylsp[0]));
     }
-#line 2524 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2530 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 71:
-#line 511 "src/parse-gram.y" /* yacc.c:1644  */
+#line 511 "src/parse-gram.y" /* yacc.c:1649  */
     {
       symbol_class_set ((*(symbol**)(&yyvsp[-1])), current_class, (yylsp[-1]), true);
       symbol_type_set ((*(symbol**)(&yyvsp[-1])), current_type, (yylsp[-1]));
       symbol_user_token_number_set ((*(symbol**)(&yyvsp[-1])), (*(int*)(&yyvsp[0])), (yylsp[0]));
     }
-#line 2534 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2540 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 72:
-#line 517 "src/parse-gram.y" /* yacc.c:1644  */
+#line 517 "src/parse-gram.y" /* yacc.c:1649  */
     {
       symbol_class_set ((*(symbol**)(&yyvsp[-1])), current_class, (yylsp[-1]), true);
       symbol_type_set ((*(symbol**)(&yyvsp[-1])), current_type, (yylsp[-1]));
       symbol_make_alias ((*(symbol**)(&yyvsp[-1])), (*(symbol**)(&yyvsp[0])), (yyloc));
     }
-#line 2544 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2550 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 73:
-#line 523 "src/parse-gram.y" /* yacc.c:1644  */
+#line 523 "src/parse-gram.y" /* yacc.c:1649  */
     {
       symbol_class_set ((*(symbol**)(&yyvsp[-2])), current_class, (yylsp[-2]), true);
       symbol_type_set ((*(symbol**)(&yyvsp[-2])), current_type, (yylsp[-2]));
       symbol_user_token_number_set ((*(symbol**)(&yyvsp[-2])), (*(int*)(&yyvsp[-1])), (yylsp[-1]));
       symbol_make_alias ((*(symbol**)(&yyvsp[-2])), (*(symbol**)(&yyvsp[0])), (yyloc));
     }
-#line 2555 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2561 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 80:
-#line 553 "src/parse-gram.y" /* yacc.c:1644  */
+#line 553 "src/parse-gram.y" /* yacc.c:1649  */
     {
       yyerrok;
     }
-#line 2563 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2569 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 81:
-#line 559 "src/parse-gram.y" /* yacc.c:1644  */
+#line 559 "src/parse-gram.y" /* yacc.c:1649  */
     { current_lhs ((*(symbol**)(&yyvsp[-1])), (yylsp[-1]), (*(named_ref**)(&yyvsp[0]))); }
-#line 2569 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2575 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 82:
-#line 560 "src/parse-gram.y" /* yacc.c:1644  */
+#line 560 "src/parse-gram.y" /* yacc.c:1649  */
     {
       /* Free the current lhs. */
       current_lhs (0, (yylsp[-3]), 0);
     }
-#line 2578 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2584 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 83:
-#line 567 "src/parse-gram.y" /* yacc.c:1644  */
+#line 567 "src/parse-gram.y" /* yacc.c:1649  */
     { grammar_current_rule_end ((yylsp[0])); }
-#line 2584 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2590 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 84:
-#line 568 "src/parse-gram.y" /* yacc.c:1644  */
+#line 568 "src/parse-gram.y" /* yacc.c:1649  */
     { grammar_current_rule_end ((yylsp[0])); }
-#line 2590 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2596 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 86:
-#line 575 "src/parse-gram.y" /* yacc.c:1644  */
+#line 575 "src/parse-gram.y" /* yacc.c:1649  */
     { grammar_current_rule_begin (current_lhs_symbol, current_lhs_location,
                                   current_lhs_named_ref); }
-#line 2597 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2603 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 87:
-#line 578 "src/parse-gram.y" /* yacc.c:1644  */
+#line 578 "src/parse-gram.y" /* yacc.c:1649  */
     { grammar_current_rule_symbol_append ((*(symbol**)(&yyvsp[-1])), (yylsp[-1]), (*(named_ref**)(&yyvsp[0]))); }
-#line 2603 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2609 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 88:
-#line 580 "src/parse-gram.y" /* yacc.c:1644  */
+#line 580 "src/parse-gram.y" /* yacc.c:1649  */
     { grammar_current_rule_action_append ((*(char**)(&yyvsp[-1])), (yylsp[-1]), (*(named_ref**)(&yyvsp[0])), current_type); }
-#line 2609 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2615 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 89:
-#line 582 "src/parse-gram.y" /* yacc.c:1644  */
+#line 582 "src/parse-gram.y" /* yacc.c:1649  */
     { grammar_current_rule_predicate_append ((*(char**)(&yyvsp[0])), (yylsp[0])); }
-#line 2615 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2621 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 90:
-#line 584 "src/parse-gram.y" /* yacc.c:1644  */
+#line 584 "src/parse-gram.y" /* yacc.c:1649  */
     { grammar_current_rule_empty_set ((yylsp[0])); }
-#line 2621 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2627 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 91:
-#line 586 "src/parse-gram.y" /* yacc.c:1644  */
+#line 586 "src/parse-gram.y" /* yacc.c:1649  */
     { grammar_current_rule_prec_set ((*(symbol**)(&yyvsp[0])), (yylsp[0])); }
-#line 2627 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2633 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 92:
-#line 588 "src/parse-gram.y" /* yacc.c:1644  */
+#line 588 "src/parse-gram.y" /* yacc.c:1649  */
     { grammar_current_rule_dprec_set ((*(int*)(&yyvsp[0])), (yylsp[0])); }
-#line 2633 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2639 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 93:
-#line 590 "src/parse-gram.y" /* yacc.c:1644  */
+#line 590 "src/parse-gram.y" /* yacc.c:1649  */
     { grammar_current_rule_merge_set ((*(uniqstr*)(&yyvsp[0])), (yylsp[0])); }
-#line 2639 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2645 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 94:
-#line 594 "src/parse-gram.y" /* yacc.c:1644  */
-    { (*(named_ref**)(&yyval)) = 0; }
-#line 2645 "src/parse-gram.c" /* yacc.c:1644  */
+#line 592 "src/parse-gram.y" /* yacc.c:1649  */
+    { grammar_current_rule_expect_sr ((*(int*)(&yyvsp[0])), (yylsp[0])); }
+#line 2651 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 95:
-#line 595 "src/parse-gram.y" /* yacc.c:1644  */
-    { (*(named_ref**)(&yyval)) = named_ref_new ((*(uniqstr*)(&yyvsp[0])), (yylsp[0])); }
-#line 2651 "src/parse-gram.c" /* yacc.c:1644  */
+#line 594 "src/parse-gram.y" /* yacc.c:1649  */
+    { grammar_current_rule_expect_rr ((*(int*)(&yyvsp[0])), (yylsp[0])); }
+#line 2657 "src/parse-gram.c" /* yacc.c:1649  */
+    break;
+
+  case 96:
+#line 598 "src/parse-gram.y" /* yacc.c:1649  */
+    { (*(named_ref**)(&yyval)) = 0; }
+#line 2663 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 97:
-#line 628 "src/parse-gram.y" /* yacc.c:1644  */
+#line 599 "src/parse-gram.y" /* yacc.c:1649  */
+    { (*(named_ref**)(&yyval)) = named_ref_new ((*(uniqstr*)(&yyvsp[0])), (yylsp[0])); }
+#line 2669 "src/parse-gram.c" /* yacc.c:1649  */
+    break;
+
+  case 99:
+#line 632 "src/parse-gram.y" /* yacc.c:1649  */
     { (*(value_type*)(&yyval)).kind = muscle_keyword; (*(value_type*)(&yyval)).chars = ""; }
-#line 2657 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2675 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
-  case 98:
-#line 629 "src/parse-gram.y" /* yacc.c:1644  */
+  case 100:
+#line 633 "src/parse-gram.y" /* yacc.c:1649  */
     { (*(value_type*)(&yyval)).kind = muscle_keyword; (*(value_type*)(&yyval)).chars = (*(uniqstr*)(&yyvsp[0])); }
-#line 2663 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2681 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
-  case 99:
-#line 630 "src/parse-gram.y" /* yacc.c:1644  */
+  case 101:
+#line 634 "src/parse-gram.y" /* yacc.c:1649  */
     { (*(value_type*)(&yyval)).kind = muscle_string;  (*(value_type*)(&yyval)).chars = (*(char**)(&yyvsp[0])); }
-#line 2669 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2687 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
-  case 100:
-#line 631 "src/parse-gram.y" /* yacc.c:1644  */
+  case 102:
+#line 635 "src/parse-gram.y" /* yacc.c:1649  */
     { (*(value_type*)(&yyval)).kind = muscle_code;    (*(value_type*)(&yyval)).chars = strip_braces ((*(char**)(&yyvsp[0]))); }
-#line 2675 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2693 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
-  case 101:
-#line 644 "src/parse-gram.y" /* yacc.c:1644  */
+  case 103:
+#line 648 "src/parse-gram.y" /* yacc.c:1649  */
     { (*(symbol**)(&yyval)) = symbol_from_uniqstr ((*(uniqstr*)(&yyvsp[0])), (yylsp[0])); }
-#line 2681 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2699 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
-  case 102:
-#line 646 "src/parse-gram.y" /* yacc.c:1644  */
+  case 104:
+#line 650 "src/parse-gram.y" /* yacc.c:1649  */
     {
       (*(symbol**)(&yyval)) = symbol_get (char_name ((*(unsigned char*)(&yyvsp[0]))), (yylsp[0]));
       symbol_class_set ((*(symbol**)(&yyval)), token_sym, (yylsp[0]), false);
       symbol_user_token_number_set ((*(symbol**)(&yyval)), (*(unsigned char*)(&yyvsp[0])), (yylsp[0]));
     }
-#line 2691 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2709 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
-  case 103:
-#line 654 "src/parse-gram.y" /* yacc.c:1644  */
+  case 105:
+#line 658 "src/parse-gram.y" /* yacc.c:1649  */
     { (*(symbol**)(&yyval)) = symbol_from_uniqstr ((*(uniqstr*)(&yyvsp[0])), (yylsp[0])); }
-#line 2697 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2715 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
-  case 106:
-#line 666 "src/parse-gram.y" /* yacc.c:1644  */
+  case 108:
+#line 670 "src/parse-gram.y" /* yacc.c:1649  */
     {
       (*(symbol**)(&yyval)) = symbol_get (quotearg_style (c_quoting_style, (*(char**)(&yyvsp[0]))), (yylsp[0]));
       symbol_class_set ((*(symbol**)(&yyval)), token_sym, (yylsp[0]), false);
     }
-#line 2706 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2724 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
-  case 108:
-#line 675 "src/parse-gram.y" /* yacc.c:1644  */
+  case 110:
+#line 679 "src/parse-gram.y" /* yacc.c:1649  */
     {
       muscle_code_grow ("epilogue", translate_code ((*(char**)(&yyvsp[0])), (yylsp[0]), true), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2715 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2733 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
 
-#line 2719 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2737 "src/parse-gram.c" /* yacc.c:1649  */
         default: break;
       }
     if (yychar_backup != yychar)
@@ -2836,12 +2854,11 @@ yyerrlab:
 | yyerrorlab -- error raised explicitly by YYERROR.  |
 `---------------------------------------------------*/
 yyerrorlab:
-
   /* Pacify compilers like GCC when the user code never invokes
      YYERROR and the label yyerrorlab therefore never appears in user
      code.  */
-  if (/*CONSTCOND*/ 0)
-     goto yyerrorlab;
+  if (0)
+    goto yyerrorlab;
 
   /* Do not reclaim the symbols of the rule whose action triggered
      this YYERROR.  */
@@ -2912,6 +2929,7 @@ yyacceptlab:
   yyresult = 0;
   goto yyreturn;
 
+
 /*-----------------------------------.
 | yyabortlab -- YYABORT comes here.  |
 `-----------------------------------*/
@@ -2919,6 +2937,7 @@ yyabortlab:
   yyresult = 1;
   goto yyreturn;
 
+
 #if 1
 /*-------------------------------------------------.
 | yyexhaustedlab -- memory exhaustion comes here.  |
@@ -2929,6 +2948,10 @@ yyexhaustedlab:
   /* Fall through.  */
 #endif
 
+
+/*-----------------------------------------------------.
+| yyreturn -- parsing is finished, return the result.  |
+`-----------------------------------------------------*/
 yyreturn:
   if (yychar != YYEMPTY)
     {
@@ -2960,7 +2983,7 @@ yyreturn:
 #endif
   return yyresult;
 }
-#line 681 "src/parse-gram.y" /* yacc.c:1902  */
+#line 685 "src/parse-gram.y" /* yacc.c:1916  */
 
 
 /* Return the location of the left-hand side of a rule whose
