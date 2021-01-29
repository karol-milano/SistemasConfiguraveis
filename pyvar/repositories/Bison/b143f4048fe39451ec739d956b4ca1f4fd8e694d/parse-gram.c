@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 2.4.425-305c-dirty.  */
+/* A Bison parser, made by GNU Bison 2.4.434-7439c.  */
 
 /* Implementation for Bison's Yacc-like parsers in C
 
@@ -45,7 +45,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "2.4.425-305c-dirty"
+#define YYBISON_VERSION "2.4.434-7439c"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -151,7 +151,7 @@ static char const *char_name (char);
 
 /* "%code requires" blocks.  */
 /* Line 273 of yacc.c  */
-#line 201 "src/parse-gram.y"
+#line 202 "src/parse-gram.y"
 
 # ifndef PARAM_TYPE
 #  define PARAM_TYPE
@@ -213,19 +213,19 @@ static char const *char_name (char);
      PERCENT_VERBOSE = 293,
      PERCENT_YACC = 294,
      BRACED_CODE = 295,
-     CHAR = 296,
-     EPILOGUE = 297,
-     EQUAL = 298,
-     ID = 299,
-     ID_COLON = 300,
-     PERCENT_PERCENT = 301,
-     PIPE = 302,
-     PROLOGUE = 303,
-     SEMICOLON = 304,
-     TAG = 305,
-     TAG_ANY = 306,
-     TAG_NONE = 307,
-     BRACKETED_ID = 308,
+     BRACKETED_ID = 296,
+     CHAR = 297,
+     EPILOGUE = 298,
+     EQUAL = 299,
+     ID = 300,
+     ID_COLON = 301,
+     PERCENT_PERCENT = 302,
+     PIPE = 303,
+     PROLOGUE = 304,
+     SEMICOLON = 305,
+     TAG = 306,
+     TAG_ANY = 307,
+     TAG_NONE = 308,
      PERCENT_PARAM = 309,
      PERCENT_UNION = 310
    };
@@ -270,19 +270,19 @@ static char const *char_name (char);
 #define PERCENT_VERBOSE 293
 #define PERCENT_YACC 294
 #define BRACED_CODE 295
-#define CHAR 296
-#define EPILOGUE 297
-#define EQUAL 298
-#define ID 299
-#define ID_COLON 300
-#define PERCENT_PERCENT 301
-#define PIPE 302
-#define PROLOGUE 303
-#define SEMICOLON 304
-#define TAG 305
-#define TAG_ANY 306
-#define TAG_NONE 307
-#define BRACKETED_ID 308
+#define BRACKETED_ID 296
+#define CHAR 297
+#define EPILOGUE 298
+#define EQUAL 299
+#define ID 300
+#define ID_COLON 301
+#define PERCENT_PERCENT 302
+#define PIPE 303
+#define PROLOGUE 304
+#define SEMICOLON 305
+#define TAG 306
+#define TAG_ANY 307
+#define TAG_NONE 308
 #define PERCENT_PARAM 309
 #define PERCENT_UNION 310
 
@@ -306,7 +306,7 @@ typedef union YYSTYPE
   unsigned char character;
 
 /* Line 278 of yacc.c  */
-#line 225 "src/parse-gram.y"
+#line 226 "src/parse-gram.y"
 
   param_type param;
 
@@ -354,7 +354,7 @@ typedef struct YYLTYPE
   #define YYTYPE_UINT8 uint_fast8_t
 
 /* Line 329 of yacc.c  */
-#line 214 "src/parse-gram.y"
+#line 215 "src/parse-gram.y"
 
   /** Add a lex-param and/or a parse-param.
    *
@@ -584,7 +584,7 @@ union yyalloc
 /* YYFINAL -- State number of the termination state.  */
 #define YYFINAL  3
 /* YYLAST -- Last index in YYTABLE.  */
-#define YYLAST   190
+#define YYLAST   162
 
 /* YYNTOKENS -- Number of terminals.  */
 #define YYNTOKENS  56
@@ -645,17 +645,17 @@ static const yytype_uint8 yytranslate[] =
   /* YYRLINEYYN -- Source line where rule number YYN was defined.    */
 static const yytype_uint16 yyrline[] =
 {
-       0,   250,   250,   258,   260,   264,   265,   275,   279,   284,
-     285,   290,   295,   296,   297,   298,   299,   304,   313,   314,
-     315,   316,   317,   318,   319,   320,   320,   321,   322,   346,
-     347,   348,   349,   353,   354,   363,   364,   365,   369,   376,
-     383,   387,   391,   398,   413,   414,   418,   430,   430,   435,
-     435,   440,   451,   466,   467,   468,   469,   473,   474,   479,
-     481,   486,   487,   492,   494,   499,   500,   504,   505,   506,
-     507,   512,   517,   522,   528,   534,   545,   546,   555,   556,
-     562,   563,   564,   571,   571,   576,   577,   578,   583,   585,
-     587,   589,   591,   593,   598,   600,   611,   612,   617,   618,
-     619,   628,   648,   650,   659,   664,   665,   670,   677,   679
+       0,   251,   251,   259,   261,   265,   266,   276,   280,   285,
+     286,   291,   296,   297,   298,   299,   300,   305,   314,   315,
+     316,   317,   318,   319,   320,   321,   321,   322,   323,   347,
+     348,   349,   350,   354,   355,   364,   365,   366,   370,   377,
+     384,   388,   392,   399,   414,   415,   419,   431,   431,   436,
+     436,   441,   452,   467,   468,   469,   470,   474,   475,   480,
+     482,   487,   488,   493,   495,   500,   501,   505,   506,   507,
+     508,   513,   518,   523,   529,   535,   546,   547,   556,   557,
+     563,   564,   565,   572,   572,   577,   578,   579,   584,   586,
+     588,   590,   592,   594,   599,   601,   612,   613,   618,   619,
+     620,   629,   649,   651,   660,   665,   666,   671,   678,   680
 };
 #endif
 
@@ -674,10 +674,10 @@ static const char *const yytname[] =
   "\"%name-prefix\"", "\"%no-default-prec\"", "\"%no-lines\"",
   "\"%nondeterministic-parser\"", "\"%output\"", "\"%require\"",
   "\"%skeleton\"", "\"%start\"", "\"%token-table\"", "\"%verbose\"",
-  "\"%yacc\"", "\"{...}\"", "\"char\"", "\"epilogue\"", "\"=\"",
-  "\"identifier\"", "\"identifier:\"", "\"%%\"", "\"|\"", "\"%{...%}\"",
-  "\";\"", "\"<tag>\"", "\"<*>\"", "\"<>\"", "\"[identifier]\"",
-  "\"%param\"", "\"%union\"", "$accept", "input", "prologue_declarations",
+  "\"%yacc\"", "\"{...}\"", "\"[identifier]\"", "\"char\"", "\"epilogue\"",
+  "\"=\"", "\"identifier\"", "\"identifier:\"", "\"%%\"", "\"|\"",
+  "\"%{...%}\"", "\";\"", "\"<tag>\"", "\"<*>\"", "\"<>\"", "\"%param\"",
+  "\"%union\"", "$accept", "input", "prologue_declarations",
   "prologue_declaration", "$@1", "params", "grammar_declaration",
   "union_name", "symbol_declaration", "$@2", "$@3",
   "precedence_declaration", "precedence_declarator", "tag.opt",
@@ -703,10 +703,10 @@ static const yytype_uint16 yytoknum[] =
 };
 # endif
 
-#define YYPACT_NINF -88
+#define YYPACT_NINF -137
 
 #define yypact_value_is_default(yystate) \
-  ((yystate) == (-88))
+  ((yystate) == (-137))
 
 #define YYTABLE_NINF -109
 
@@ -717,21 +717,21 @@ static const yytype_uint16 yytoknum[] =
      STATE-NUM.    */
 static const yytype_int16 yypact[] =
 {
-     -88,    38,   109,   -88,   -88,   -88,    -8,    13,    41,   -88,
-     -88,   -88,   -88,   -17,   -88,    14,    51,   -88,    53,    78,
-     -88,     2,   -88,    43,    81,    17,   -88,   -88,   -88,    30,
-      82,    83,    36,   -88,   -88,   -88,    58,   -88,   -88,   -88,
-      45,   -88,   -88,   -88,   -88,    40,    -1,    -1,    36,     0,
-       0,   -88,    52,   -88,   -88,   -88,    18,   -88,   -88,   -88,
-     -88,    88,   -88,   -88,   -88,    90,   -88,    92,   -88,   -88,
-     -88,   -88,   -88,   -88,   -88,   -88,    47,   -88,    48,     1,
-     -88,   -88,    46,    60,   -88,    52,   -88,    36,   -88,   -88,
-      -1,    31,    -1,    36,   -88,   -88,   -88,   -88,     0,   -88,
-     -88,     0,   -88,   -88,   -88,   -88,   -88,   -88,   -88,   -88,
-     -88,    56,   -88,   -88,   -88,   -88,   -88,    61,   -88,    36,
-     -88,   100,   -88,   103,   -88,   -88,   -88,   -88,   -88,   -88,
-     -88,   -88,   -88,   -23,   146,   -88,   -88,    36,   104,    57,
-      46,    46,   146,   -88,   -88,   -88,   -88,   -88
+    -137,    20,   106,  -137,  -137,  -137,    19,    -1,    36,  -137,
+    -137,  -137,  -137,    13,  -137,     0,    79,  -137,    89,    90,
+    -137,    41,  -137,    55,    93,    46,  -137,  -137,  -137,    47,
+      94,    95,    35,  -137,  -137,  -137,    16,  -137,  -137,  -137,
+      54,  -137,  -137,  -137,  -137,    49,    33,    33,    35,    12,
+      12,  -137,    61,  -137,  -137,  -137,    29,  -137,  -137,  -137,
+    -137,   100,  -137,  -137,  -137,   101,  -137,   103,  -137,  -137,
+    -137,  -137,  -137,  -137,  -137,  -137,    57,  -137,    58,     1,
+    -137,  -137,    68,    80,  -137,    61,  -137,    35,  -137,  -137,
+      33,    56,    33,    35,  -137,  -137,  -137,  -137,    12,  -137,
+    -137,    12,  -137,  -137,  -137,  -137,  -137,  -137,  -137,  -137,
+    -137,    78,  -137,  -137,  -137,  -137,  -137,    82,  -137,    35,
+    -137,   142,  -137,   144,  -137,  -137,  -137,  -137,  -137,  -137,
+    -137,  -137,  -137,    18,    27,  -137,  -137,    35,   145,    97,
+      68,    68,    27,  -137,  -137,  -137,  -137,  -137
 };
 
   /* YYDEFACT[S] -- default reduction number in state S.  Performed when
@@ -757,12 +757,12 @@ static const yytype_uint8 yydefact[] =
 };
 
   /* YYPGOTO[NTERM-NUM].    */
-static const yytype_int8 yypgoto[] =
+static const yytype_int16 yypgoto[] =
 {
-     -88,   -88,   -88,   -88,   -88,   -88,   107,   -88,   -88,   -88,
-     -88,   -88,   -88,   -88,   -88,    -7,   -88,    73,   -76,   -60,
-      64,   -88,    71,   -88,   -88,   -88,   -11,   -62,   -88,   -88,
-     -37,   -18,   -88,   -32,   -87,   -88
+    -137,  -137,  -137,  -137,  -137,  -137,   148,  -137,  -137,  -137,
+    -137,  -137,  -137,  -137,  -137,    32,  -137,   102,    -9,    -4,
+     107,  -137,    83,  -137,  -137,  -137,    22,  -136,  -137,  -137,
+     -12,   -11,  -137,   -32,   -40,  -137
 };
 
   /* YYDEFGOTO[NTERM-NUM].    */
@@ -779,50 +779,44 @@ static const yytype_int16 yydefgoto[] =
      number is the opposite.  If YYTABLE_NINF, syntax error.    */
 static const yytype_int16 yytable[] =
 {
-      74,  -108,    76,    70,   124,    60,     4,     5,     6,     7,
-       8,     9,    10,    11,    12,   102,    94,    54,    13,    14,
-      64,   103,   126,    51,   135,   126,   136,    52,    91,    91,
-     122,    26,   122,    66,    70,   123,   132,    32,     3,    70,
-      71,    71,    48,    72,    72,    61,    77,   111,   118,    88,
-      95,    96,    97,    49,    57,   121,    40,    58,    55,    76,
-      65,   125,   104,     4,     5,     6,     7,     8,     9,    10,
-      11,    12,    91,    67,    91,    13,    14,    71,   146,   147,
-      72,    50,    59,    62,    63,    68,    69,   121,    26,    84,
-      86,   106,    51,   107,    32,   108,   109,   110,   127,   114,
-     116,   129,   141,    77,   131,   143,    70,   145,   144,    42,
-     141,    92,   130,    40,     4,     5,     6,     7,     8,     9,
-      10,    11,    12,   101,   142,     0,    13,    14,    15,    16,
-      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
-      27,    28,    29,    30,    31,    32,    33,    34,    35,    70,
-     112,     0,     0,     0,     0,    36,     0,    37,    38,     0,
-     137,   138,   139,    39,    40,     0,     0,     0,     0,     0,
-       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
-       0,     0,     0,     0,     0,     0,   140,    71,     0,     0,
-      72
+      74,  -108,    76,    54,   146,   147,     4,     5,     6,     7,
+       8,     9,    10,    11,    12,    70,    94,    76,    13,    14,
+       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
+      70,    26,   103,    13,    14,    91,    91,    32,    70,    49,
+     102,   137,   138,   139,    60,    55,    26,    77,   111,    64,
+      66,   124,    32,    51,    71,   121,    40,    72,    52,    70,
+     123,   125,    77,    95,    96,    97,   135,   140,   136,    71,
+      48,    40,    72,   118,   104,    71,    50,    71,    72,    91,
+      72,    91,    57,   132,    88,    61,   122,   121,   122,   126,
+      65,    67,   126,    58,    59,    62,    63,    68,    69,    84,
+      86,    51,   141,   106,   107,   143,   108,   109,   110,   114,
+     141,     4,     5,     6,     7,     8,     9,    10,    11,    12,
+     116,   127,   129,    13,    14,    15,    16,    17,    18,    19,
+      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
+      30,    31,    32,    33,    34,    35,   131,    70,   145,   144,
+      42,   130,   101,    36,    92,    37,    38,   142,     0,     0,
+      39,    40,   112
 };
 
 static const yytype_int16 yycheck[] =
 {
-      32,     0,     1,     3,    91,     3,     5,     6,     7,     8,
-       9,    10,    11,    12,    13,    52,    48,     3,    17,    18,
-       3,     3,    98,    40,    47,   101,    49,    44,    46,    47,
-      90,    30,    92,     3,     3,     4,   123,    36,     0,     3,
-      41,    41,    50,    44,    44,    43,    45,    46,    85,    50,
-      50,    51,    52,    40,     3,    87,    55,     4,    44,     1,
-      43,    93,    44,     5,     6,     7,     8,     9,    10,    11,
-      12,    13,    90,    43,    92,    17,    18,    41,   140,   141,
-      44,    40,     4,    40,     3,     3,     3,   119,    30,    44,
-      50,     3,    40,     3,    36,     3,    49,    49,    42,    53,
-      40,    40,   134,    45,     4,   137,     3,    50,     4,     2,
-     142,    47,   119,    55,     5,     6,     7,     8,     9,    10,
-      11,    12,    13,    50,   135,    -1,    17,    18,    19,    20,
-      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
-      31,    32,    33,    34,    35,    36,    37,    38,    39,     3,
-      79,    -1,    -1,    -1,    -1,    46,    -1,    48,    49,    -1,
-      14,    15,    16,    54,    55,    -1,    -1,    -1,    -1,    -1,
-      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
-      -1,    -1,    -1,    -1,    -1,    -1,    40,    41,    -1,    -1,
-      44
+      32,     0,     1,     3,   140,   141,     5,     6,     7,     8,
+       9,    10,    11,    12,    13,     3,    48,     1,    17,    18,
+       0,     5,     6,     7,     8,     9,    10,    11,    12,    13,
+       3,    30,     3,    17,    18,    46,    47,    36,     3,    40,
+      52,    14,    15,    16,     3,    45,    30,    46,    47,     3,
+       3,    91,    36,    40,    42,    87,    55,    45,    45,     3,
+       4,    93,    46,    51,    52,    53,    48,    40,    50,    42,
+      51,    55,    45,    85,    45,    42,    40,    42,    45,    90,
+      45,    92,     3,   123,    51,    44,    90,   119,    92,    98,
+      44,    44,   101,     4,     4,    40,     3,     3,     3,    45,
+      51,    40,   134,     3,     3,   137,     3,    50,    50,    41,
+     142,     5,     6,     7,     8,     9,    10,    11,    12,    13,
+      40,    43,    40,    17,    18,    19,    20,    21,    22,    23,
+      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
+      34,    35,    36,    37,    38,    39,     4,     3,    51,     4,
+       2,   119,    50,    47,    47,    49,    50,   135,    -1,    -1,
+      54,    55,    79
 };
 
   /* STOS_[STATE-NUM] -- The (internal number of the) accessing
@@ -832,18 +826,18 @@ static const yytype_uint8 yystos[] =
        0,    57,    58,     0,     5,     6,     7,     8,     9,    10,
       11,    12,    13,    17,    18,    19,    20,    21,    22,    23,
       24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
-      34,    35,    36,    37,    38,    39,    46,    48,    49,    54,
-      55,    59,    62,    64,    67,    68,    66,    65,    50,    40,
-      40,    40,    44,    86,     3,    44,    84,     3,     4,     4,
-       3,    43,    40,     3,     3,    43,     3,    43,     3,     3,
-       3,    41,    44,    87,    89,    90,     1,    45,    62,    77,
-      78,    79,    88,    60,    44,    63,    50,    69,    50,    75,
-      76,    87,    76,    72,    89,    50,    51,    52,    73,    74,
-      89,    73,    86,     3,    44,    85,     3,     3,     3,    49,
-      49,    46,    78,    91,    53,    83,    40,    61,    86,    70,
-      71,    89,    75,     4,    90,    89,    74,    42,    80,    40,
-      71,     4,    90,    81,    82,    47,    49,    14,    15,    16,
-      40,    89,    82,    89,     4,    50,    83,    83
+      34,    35,    36,    37,    38,    39,    47,    49,    50,    54,
+      55,    59,    62,    64,    67,    68,    66,    65,    51,    40,
+      40,    40,    45,    86,     3,    45,    84,     3,     4,     4,
+       3,    44,    40,     3,     3,    44,     3,    44,     3,     3,
+       3,    42,    45,    87,    89,    90,     1,    46,    62,    77,
+      78,    79,    88,    60,    45,    63,    51,    69,    51,    75,
+      76,    87,    76,    72,    89,    51,    52,    53,    73,    74,
+      89,    73,    86,     3,    45,    85,     3,     3,     3,    50,
+      50,    47,    78,    91,    41,    83,    40,    61,    86,    70,
+      71,    89,    75,     4,    90,    89,    74,    43,    80,    40,
+      71,     4,    90,    81,    82,    48,    50,    14,    15,    16,
+      40,    89,    82,    89,     4,    51,    83,    83
 };
 
   /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.    */
@@ -1030,7 +1024,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 #line 175 "src/parse-gram.y"
         { fputs (quotearg_style (c_quoting_style, ((*yyvaluep).chars)), stderr); }
 /* Line 715 of yacc.c  */
-#line 1034 "src/parse-gram.c"
+#line 1028 "src/parse-gram.c"
         break;
 
             case 4: // "integer"
@@ -1039,7 +1033,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 #line 188 "src/parse-gram.y"
         { fprintf (stderr, "%d", ((*yyvaluep).integer)); }
 /* Line 715 of yacc.c  */
-#line 1043 "src/parse-gram.c"
+#line 1037 "src/parse-gram.c"
         break;
 
             case 24: // "%<flag>"
@@ -1048,7 +1042,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 #line 184 "src/parse-gram.y"
         { fprintf (stderr, "%%%s", ((*yyvaluep).uniqstr)); }
 /* Line 715 of yacc.c  */
-#line 1052 "src/parse-gram.c"
+#line 1046 "src/parse-gram.c"
         break;
 
             case 40: // "{...}"
@@ -1057,67 +1051,76 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 #line 177 "src/parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).code)); }
 /* Line 715 of yacc.c  */
-#line 1061 "src/parse-gram.c"
+#line 1055 "src/parse-gram.c"
         break;
 
-            case 41: // "char"
+            case 41: // "[identifier]"
+
+/* Line 715 of yacc.c  */
+#line 182 "src/parse-gram.y"
+        { fprintf (stderr, "[%s]", ((*yyvaluep).uniqstr)); }
+/* Line 715 of yacc.c  */
+#line 1064 "src/parse-gram.c"
+        break;
+
+            case 42: // "char"
 
 /* Line 715 of yacc.c  */
 #line 169 "src/parse-gram.y"
         { fputs (char_name (((*yyvaluep).character)), stderr); }
 /* Line 715 of yacc.c  */
-#line 1070 "src/parse-gram.c"
+#line 1073 "src/parse-gram.c"
         break;
 
-            case 42: // "epilogue"
+            case 43: // "epilogue"
 
 /* Line 715 of yacc.c  */
 #line 177 "src/parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); }
 /* Line 715 of yacc.c  */
-#line 1079 "src/parse-gram.c"
+#line 1082 "src/parse-gram.c"
         break;
 
-            case 44: // "identifier"
+            case 45: // "identifier"
 
 /* Line 715 of yacc.c  */
-#line 182 "src/parse-gram.y"
+#line 181 "src/parse-gram.y"
         { fputs (((*yyvaluep).uniqstr), stderr); }
 /* Line 715 of yacc.c  */
-#line 1088 "src/parse-gram.c"
+#line 1091 "src/parse-gram.c"
         break;
 
-            case 45: // "identifier:"
+            case 46: // "identifier:"
 
 /* Line 715 of yacc.c  */
 #line 183 "src/parse-gram.y"
         { fprintf (stderr, "%s:", ((*yyvaluep).uniqstr)); }
 /* Line 715 of yacc.c  */
-#line 1097 "src/parse-gram.c"
+#line 1100 "src/parse-gram.c"
         break;
 
-            case 48: // "%{...%}"
+            case 49: // "%{...%}"
 
 /* Line 715 of yacc.c  */
 #line 177 "src/parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); }
 /* Line 715 of yacc.c  */
-#line 1106 "src/parse-gram.c"
+#line 1109 "src/parse-gram.c"
         break;
 
-            case 50: // "<tag>"
+            case 51: // "<tag>"
 
 /* Line 715 of yacc.c  */
 #line 185 "src/parse-gram.y"
         { fprintf (stderr, "<%s>", ((*yyvaluep).uniqstr)); }
 /* Line 715 of yacc.c  */
-#line 1115 "src/parse-gram.c"
+#line 1118 "src/parse-gram.c"
         break;
 
             case 54: // "%param"
 
 /* Line 715 of yacc.c  */
-#line 230 "src/parse-gram.y"
+#line 231 "src/parse-gram.y"
         {
   switch (((*yyvaluep).param))
     {
@@ -1131,16 +1134,25 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
     }
 }
 /* Line 715 of yacc.c  */
-#line 1135 "src/parse-gram.c"
+#line 1138 "src/parse-gram.c"
+        break;
+
+            case 71: // symbol.prec
+
+/* Line 715 of yacc.c  */
+#line 191 "src/parse-gram.y"
+        { fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); }
+/* Line 715 of yacc.c  */
+#line 1147 "src/parse-gram.c"
         break;
 
             case 84: // variable
 
 /* Line 715 of yacc.c  */
-#line 182 "src/parse-gram.y"
+#line 181 "src/parse-gram.y"
         { fputs (((*yyvaluep).uniqstr), stderr); }
 /* Line 715 of yacc.c  */
-#line 1144 "src/parse-gram.c"
+#line 1156 "src/parse-gram.c"
         break;
 
             case 85: // content.opt
@@ -1149,7 +1161,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 #line 177 "src/parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); }
 /* Line 715 of yacc.c  */
-#line 1153 "src/parse-gram.c"
+#line 1165 "src/parse-gram.c"
         break;
 
             case 86: // braceless
@@ -1158,7 +1170,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 #line 177 "src/parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); }
 /* Line 715 of yacc.c  */
-#line 1162 "src/parse-gram.c"
+#line 1174 "src/parse-gram.c"
         break;
 
             case 87: // id
@@ -1167,7 +1179,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 #line 191 "src/parse-gram.y"
         { fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); }
 /* Line 715 of yacc.c  */
-#line 1171 "src/parse-gram.c"
+#line 1183 "src/parse-gram.c"
         break;
 
             case 88: // id_colon
@@ -1176,7 +1188,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 #line 192 "src/parse-gram.y"
         { fprintf (stderr, "%s:", ((*yyvaluep).symbol)->tag); }
 /* Line 715 of yacc.c  */
-#line 1180 "src/parse-gram.c"
+#line 1192 "src/parse-gram.c"
         break;
 
             case 89: // symbol
@@ -1185,7 +1197,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 #line 191 "src/parse-gram.y"
         { fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); }
 /* Line 715 of yacc.c  */
-#line 1189 "src/parse-gram.c"
+#line 1201 "src/parse-gram.c"
         break;
 
             case 90: // string_as_id
@@ -1194,7 +1206,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 #line 191 "src/parse-gram.y"
         { fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); }
 /* Line 715 of yacc.c  */
-#line 1198 "src/parse-gram.c"
+#line 1210 "src/parse-gram.c"
         break;
 
       default:
@@ -1733,7 +1745,7 @@ YYLTYPE yylloc;
   boundary_set (&yylloc.end, current_file, 1, 1);
 }
 /* Line 1200 of yacc.c  */
-#line 1737 "src/parse-gram.c"
+#line 1749 "src/parse-gram.c"
   yylsp[0] = yylloc;
 
   goto yysetstate;
@@ -1920,7 +1932,7 @@ yyreduce:
     {
         case 6:
 /* Line 1413 of yacc.c  */
-#line 266 "src/parse-gram.y"
+#line 267 "src/parse-gram.y"
     {
       code_props plain_code;
       code_props_plain_init (&plain_code, (yyvsp[0].chars), (yylsp[0]));
@@ -1931,106 +1943,106 @@ yyreduce:
       code_scanner_last_string_free ();
     }
 /* Line 1413 of yacc.c  */
-#line 1935 "src/parse-gram.c"
+#line 1947 "src/parse-gram.c"
     break;
 
   case 7:
 /* Line 1413 of yacc.c  */
-#line 276 "src/parse-gram.y"
+#line 277 "src/parse-gram.y"
     {
       muscle_percent_define_ensure ((yyvsp[0].uniqstr), (yylsp[0]), true);
     }
 /* Line 1413 of yacc.c  */
-#line 1945 "src/parse-gram.c"
+#line 1957 "src/parse-gram.c"
     break;
 
   case 8:
 /* Line 1413 of yacc.c  */
-#line 280 "src/parse-gram.y"
+#line 281 "src/parse-gram.y"
     {
       muscle_percent_define_insert ((yyvsp[-1].uniqstr), (yylsp[-1]), (yyvsp[0].chars),
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
     }
 /* Line 1413 of yacc.c  */
-#line 1956 "src/parse-gram.c"
+#line 1968 "src/parse-gram.c"
     break;
 
   case 9:
 /* Line 1413 of yacc.c  */
-#line 284 "src/parse-gram.y"
+#line 285 "src/parse-gram.y"
     { defines_flag = true; }
 /* Line 1413 of yacc.c  */
-#line 1964 "src/parse-gram.c"
+#line 1976 "src/parse-gram.c"
     break;
 
   case 10:
 /* Line 1413 of yacc.c  */
-#line 286 "src/parse-gram.y"
+#line 287 "src/parse-gram.y"
     {
       defines_flag = true;
       spec_defines_file = xstrdup ((yyvsp[0].chars));
     }
 /* Line 1413 of yacc.c  */
-#line 1975 "src/parse-gram.c"
+#line 1987 "src/parse-gram.c"
     break;
 
   case 11:
 /* Line 1413 of yacc.c  */
-#line 291 "src/parse-gram.y"
+#line 292 "src/parse-gram.y"
     {
       muscle_percent_define_insert ("parse.error", (yylsp[0]), "verbose",
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
     }
 /* Line 1413 of yacc.c  */
-#line 1986 "src/parse-gram.c"
+#line 1998 "src/parse-gram.c"
     break;
 
   case 12:
 /* Line 1413 of yacc.c  */
-#line 295 "src/parse-gram.y"
+#line 296 "src/parse-gram.y"
     { expected_sr_conflicts = (yyvsp[0].integer); }
 /* Line 1413 of yacc.c  */
-#line 1994 "src/parse-gram.c"
+#line 2006 "src/parse-gram.c"
     break;
 
   case 13:
 /* Line 1413 of yacc.c  */
-#line 296 "src/parse-gram.y"
+#line 297 "src/parse-gram.y"
     { expected_rr_conflicts = (yyvsp[0].integer); }
 /* Line 1413 of yacc.c  */
-#line 2002 "src/parse-gram.c"
+#line 2014 "src/parse-gram.c"
     break;
 
   case 14:
 /* Line 1413 of yacc.c  */
-#line 297 "src/parse-gram.y"
+#line 298 "src/parse-gram.y"
     { spec_file_prefix = (yyvsp[0].chars); }
 /* Line 1413 of yacc.c  */
-#line 2010 "src/parse-gram.c"
+#line 2022 "src/parse-gram.c"
     break;
 
   case 15:
 /* Line 1413 of yacc.c  */
-#line 298 "src/parse-gram.y"
+#line 299 "src/parse-gram.y"
     { spec_file_prefix = (yyvsp[0].chars); }
 /* Line 1413 of yacc.c  */
-#line 2018 "src/parse-gram.c"
+#line 2030 "src/parse-gram.c"
     break;
 
   case 16:
 /* Line 1413 of yacc.c  */
-#line 300 "src/parse-gram.y"
+#line 301 "src/parse-gram.y"
     {
       nondeterministic_parser = true;
       glr_parser = true;
     }
 /* Line 1413 of yacc.c  */
-#line 2029 "src/parse-gram.c"
+#line 2041 "src/parse-gram.c"
     break;
 
   case 17:
 /* Line 1413 of yacc.c  */
-#line 305 "src/parse-gram.y"
+#line 306 "src/parse-gram.y"
     {
       code_props action;
       code_props_symbol_action_init (&action, (yyvsp[0].code), (yylsp[0]));
@@ -2040,92 +2052,92 @@ yyreduce:
       code_scanner_last_string_free ();
     }
 /* Line 1413 of yacc.c  */
-#line 2044 "src/parse-gram.c"
+#line 2056 "src/parse-gram.c"
     break;
 
   case 18:
 /* Line 1413 of yacc.c  */
-#line 313 "src/parse-gram.y"
+#line 314 "src/parse-gram.y"
     { language_argmatch ((yyvsp[0].chars), grammar_prio, (yylsp[-1])); }
 /* Line 1413 of yacc.c  */
-#line 2052 "src/parse-gram.c"
+#line 2064 "src/parse-gram.c"
     break;
 
   case 19:
 /* Line 1413 of yacc.c  */
-#line 314 "src/parse-gram.y"
+#line 315 "src/parse-gram.y"
     { spec_name_prefix = (yyvsp[0].chars); }
 /* Line 1413 of yacc.c  */
-#line 2060 "src/parse-gram.c"
+#line 2072 "src/parse-gram.c"
     break;
 
   case 20:
 /* Line 1413 of yacc.c  */
-#line 315 "src/parse-gram.y"
+#line 316 "src/parse-gram.y"
     { spec_name_prefix = (yyvsp[0].chars); }
 /* Line 1413 of yacc.c  */
-#line 2068 "src/parse-gram.c"
+#line 2080 "src/parse-gram.c"
     break;
 
   case 21:
 /* Line 1413 of yacc.c  */
-#line 316 "src/parse-gram.y"
+#line 317 "src/parse-gram.y"
     { no_lines_flag = true; }
 /* Line 1413 of yacc.c  */
-#line 2076 "src/parse-gram.c"
+#line 2088 "src/parse-gram.c"
     break;
 
   case 22:
 /* Line 1413 of yacc.c  */
-#line 317 "src/parse-gram.y"
+#line 318 "src/parse-gram.y"
     { nondeterministic_parser = true; }
 /* Line 1413 of yacc.c  */
-#line 2084 "src/parse-gram.c"
+#line 2096 "src/parse-gram.c"
     break;
 
   case 23:
 /* Line 1413 of yacc.c  */
-#line 318 "src/parse-gram.y"
+#line 319 "src/parse-gram.y"
     { spec_outfile = (yyvsp[0].chars); }
 /* Line 1413 of yacc.c  */
-#line 2092 "src/parse-gram.c"
+#line 2104 "src/parse-gram.c"
     break;
 
   case 24:
 /* Line 1413 of yacc.c  */
-#line 319 "src/parse-gram.y"
+#line 320 "src/parse-gram.y"
     { spec_outfile = (yyvsp[0].chars); }
 /* Line 1413 of yacc.c  */
-#line 2100 "src/parse-gram.c"
+#line 2112 "src/parse-gram.c"
     break;
 
   case 25:
 /* Line 1413 of yacc.c  */
-#line 320 "src/parse-gram.y"
+#line 321 "src/parse-gram.y"
     { current_param = (yyvsp[0].param); }
 /* Line 1413 of yacc.c  */
-#line 2108 "src/parse-gram.c"
+#line 2120 "src/parse-gram.c"
     break;
 
   case 26:
 /* Line 1413 of yacc.c  */
-#line 320 "src/parse-gram.y"
+#line 321 "src/parse-gram.y"
     { current_param = param_none; }
 /* Line 1413 of yacc.c  */
-#line 2116 "src/parse-gram.c"
+#line 2128 "src/parse-gram.c"
     break;
 
   case 27:
 /* Line 1413 of yacc.c  */
-#line 321 "src/parse-gram.y"
+#line 322 "src/parse-gram.y"
     { version_check (&(yylsp[0]), (yyvsp[0].chars)); }
 /* Line 1413 of yacc.c  */
-#line 2124 "src/parse-gram.c"
+#line 2136 "src/parse-gram.c"
     break;
 
   case 28:
 /* Line 1413 of yacc.c  */
-#line 323 "src/parse-gram.y"
+#line 324 "src/parse-gram.y"
     {
       char const *skeleton_user = (yyvsp[0].chars);
       if (strchr (skeleton_user, '/'))
@@ -2150,62 +2162,62 @@ yyreduce:
       skeleton_arg (skeleton_user, grammar_prio, (yylsp[-1]));
     }
 /* Line 1413 of yacc.c  */
-#line 2154 "src/parse-gram.c"
+#line 2166 "src/parse-gram.c"
     break;
 
   case 29:
 /* Line 1413 of yacc.c  */
-#line 346 "src/parse-gram.y"
+#line 347 "src/parse-gram.y"
     { token_table_flag = true; }
 /* Line 1413 of yacc.c  */
-#line 2162 "src/parse-gram.c"
+#line 2174 "src/parse-gram.c"
     break;
 
   case 30:
 /* Line 1413 of yacc.c  */
-#line 347 "src/parse-gram.y"
+#line 348 "src/parse-gram.y"
     { report_flag |= report_states; }
 /* Line 1413 of yacc.c  */
-#line 2170 "src/parse-gram.c"
+#line 2182 "src/parse-gram.c"
     break;
 
   case 31:
 /* Line 1413 of yacc.c  */
-#line 348 "src/parse-gram.y"
+#line 349 "src/parse-gram.y"
     { yacc_flag = true; }
 /* Line 1413 of yacc.c  */
-#line 2178 "src/parse-gram.c"
+#line 2190 "src/parse-gram.c"
     break;
 
   case 33:
 /* Line 1413 of yacc.c  */
-#line 353 "src/parse-gram.y"
+#line 354 "src/parse-gram.y"
     { add_param (current_param, (yyvsp[0].code), (yylsp[0])); }
 /* Line 1413 of yacc.c  */
-#line 2186 "src/parse-gram.c"
+#line 2198 "src/parse-gram.c"
     break;
 
   case 34:
 /* Line 1413 of yacc.c  */
-#line 354 "src/parse-gram.y"
+#line 355 "src/parse-gram.y"
     { add_param (current_param, (yyvsp[0].code), (yylsp[0])); }
 /* Line 1413 of yacc.c  */
-#line 2194 "src/parse-gram.c"
+#line 2206 "src/parse-gram.c"
     break;
 
   case 37:
 /* Line 1413 of yacc.c  */
-#line 366 "src/parse-gram.y"
+#line 367 "src/parse-gram.y"
     {
       grammar_start_symbol_set ((yyvsp[0].symbol), (yylsp[0]));
     }
 /* Line 1413 of yacc.c  */
-#line 2204 "src/parse-gram.c"
+#line 2216 "src/parse-gram.c"
     break;
 
   case 38:
 /* Line 1413 of yacc.c  */
-#line 370 "src/parse-gram.y"
+#line 371 "src/parse-gram.y"
     {
       symbol_list *list;
       for (list = (yyvsp[0].list); list; list = list->next)
@@ -2213,12 +2225,12 @@ yyreduce:
       symbol_list_free ((yyvsp[0].list));
     }
 /* Line 1413 of yacc.c  */
-#line 2217 "src/parse-gram.c"
+#line 2229 "src/parse-gram.c"
     break;
 
   case 39:
 /* Line 1413 of yacc.c  */
-#line 377 "src/parse-gram.y"
+#line 378 "src/parse-gram.y"
     {
       symbol_list *list;
       for (list = (yyvsp[0].list); list; list = list->next)
@@ -2226,32 +2238,32 @@ yyreduce:
       symbol_list_free ((yyvsp[0].list));
     }
 /* Line 1413 of yacc.c  */
-#line 2230 "src/parse-gram.c"
+#line 2242 "src/parse-gram.c"
     break;
 
   case 40:
 /* Line 1413 of yacc.c  */
-#line 384 "src/parse-gram.y"
+#line 385 "src/parse-gram.y"
     {
       default_prec = true;
     }
 /* Line 1413 of yacc.c  */
-#line 2240 "src/parse-gram.c"
+#line 2252 "src/parse-gram.c"
     break;
 
   case 41:
 /* Line 1413 of yacc.c  */
-#line 388 "src/parse-gram.y"
+#line 389 "src/parse-gram.y"
     {
       default_prec = false;
     }
 /* Line 1413 of yacc.c  */
-#line 2250 "src/parse-gram.c"
+#line 2262 "src/parse-gram.c"
     break;
 
   case 42:
 /* Line 1413 of yacc.c  */
-#line 392 "src/parse-gram.y"
+#line 393 "src/parse-gram.y"
     {
       /* Do not invoke muscle_percent_code_grow here since it invokes
          muscle_user_name_list_grow.  */
@@ -2259,89 +2271,89 @@ yyreduce:
       code_scanner_last_string_free ();
     }
 /* Line 1413 of yacc.c  */
-#line 2263 "src/parse-gram.c"
+#line 2275 "src/parse-gram.c"
     break;
 
   case 43:
 /* Line 1413 of yacc.c  */
-#line 399 "src/parse-gram.y"
+#line 400 "src/parse-gram.y"
     {
       muscle_percent_code_grow ((yyvsp[-1].uniqstr), (yylsp[-1]), (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
 /* Line 1413 of yacc.c  */
-#line 2274 "src/parse-gram.c"
+#line 2286 "src/parse-gram.c"
     break;
 
   case 44:
 /* Line 1413 of yacc.c  */
-#line 413 "src/parse-gram.y"
+#line 414 "src/parse-gram.y"
     {}
 /* Line 1413 of yacc.c  */
-#line 2282 "src/parse-gram.c"
+#line 2294 "src/parse-gram.c"
     break;
 
   case 45:
 /* Line 1413 of yacc.c  */
-#line 414 "src/parse-gram.y"
+#line 415 "src/parse-gram.y"
     { muscle_code_grow ("union_name", (yyvsp[0].uniqstr), (yylsp[0])); }
 /* Line 1413 of yacc.c  */
-#line 2290 "src/parse-gram.c"
+#line 2302 "src/parse-gram.c"
     break;
 
   case 46:
 /* Line 1413 of yacc.c  */
-#line 419 "src/parse-gram.y"
+#line 420 "src/parse-gram.y"
     {
       union_seen = true;
       muscle_code_grow ("stype", (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
 /* Line 1413 of yacc.c  */
-#line 2302 "src/parse-gram.c"
+#line 2314 "src/parse-gram.c"
     break;
 
   case 47:
 /* Line 1413 of yacc.c  */
-#line 430 "src/parse-gram.y"
+#line 431 "src/parse-gram.y"
     { current_class = nterm_sym; }
 /* Line 1413 of yacc.c  */
-#line 2310 "src/parse-gram.c"
+#line 2322 "src/parse-gram.c"
     break;
 
   case 48:
 /* Line 1413 of yacc.c  */
-#line 431 "src/parse-gram.y"
+#line 432 "src/parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
 /* Line 1413 of yacc.c  */
-#line 2321 "src/parse-gram.c"
+#line 2333 "src/parse-gram.c"
     break;
 
   case 49:
 /* Line 1413 of yacc.c  */
-#line 435 "src/parse-gram.y"
+#line 436 "src/parse-gram.y"
     { current_class = token_sym; }
 /* Line 1413 of yacc.c  */
-#line 2329 "src/parse-gram.c"
+#line 2341 "src/parse-gram.c"
     break;
 
   case 50:
 /* Line 1413 of yacc.c  */
-#line 436 "src/parse-gram.y"
+#line 437 "src/parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
 /* Line 1413 of yacc.c  */
-#line 2340 "src/parse-gram.c"
+#line 2352 "src/parse-gram.c"
     break;
 
   case 51:
 /* Line 1413 of yacc.c  */
-#line 441 "src/parse-gram.y"
+#line 442 "src/parse-gram.y"
     {
       symbol_list *list;
       tag_seen = true;
@@ -2350,12 +2362,12 @@ yyreduce:
       symbol_list_free ((yyvsp[0].list));
     }
 /* Line 1413 of yacc.c  */
-#line 2354 "src/parse-gram.c"
+#line 2366 "src/parse-gram.c"
     break;
 
   case 52:
 /* Line 1413 of yacc.c  */
-#line 452 "src/parse-gram.y"
+#line 453 "src/parse-gram.y"
     {
       symbol_list *list;
       ++current_prec;
@@ -2368,202 +2380,202 @@ yyreduce:
       current_type = NULL;
     }
 /* Line 1413 of yacc.c  */
-#line 2372 "src/parse-gram.c"
+#line 2384 "src/parse-gram.c"
     break;
 
   case 53:
 /* Line 1413 of yacc.c  */
-#line 466 "src/parse-gram.y"
+#line 467 "src/parse-gram.y"
     { (yyval.assoc) = left_assoc; }
 /* Line 1413 of yacc.c  */
-#line 2380 "src/parse-gram.c"
+#line 2392 "src/parse-gram.c"
     break;
 
   case 54:
 /* Line 1413 of yacc.c  */
-#line 467 "src/parse-gram.y"
+#line 468 "src/parse-gram.y"
     { (yyval.assoc) = right_assoc; }
 /* Line 1413 of yacc.c  */
-#line 2388 "src/parse-gram.c"
+#line 2400 "src/parse-gram.c"
     break;
 
   case 55:
 /* Line 1413 of yacc.c  */
-#line 468 "src/parse-gram.y"
+#line 469 "src/parse-gram.y"
     { (yyval.assoc) = non_assoc; }
 /* Line 1413 of yacc.c  */
-#line 2396 "src/parse-gram.c"
+#line 2408 "src/parse-gram.c"
     break;
 
   case 56:
 /* Line 1413 of yacc.c  */
-#line 469 "src/parse-gram.y"
+#line 470 "src/parse-gram.y"
     { (yyval.assoc) = precedence_assoc; }
 /* Line 1413 of yacc.c  */
-#line 2404 "src/parse-gram.c"
+#line 2416 "src/parse-gram.c"
     break;
 
   case 57:
 /* Line 1413 of yacc.c  */
-#line 473 "src/parse-gram.y"
+#line 474 "src/parse-gram.y"
     { current_type = NULL; }
 /* Line 1413 of yacc.c  */
-#line 2412 "src/parse-gram.c"
+#line 2424 "src/parse-gram.c"
     break;
 
   case 58:
 /* Line 1413 of yacc.c  */
-#line 474 "src/parse-gram.y"
+#line 475 "src/parse-gram.y"
     { current_type = (yyvsp[0].uniqstr); tag_seen = true; }
 /* Line 1413 of yacc.c  */
-#line 2420 "src/parse-gram.c"
+#line 2432 "src/parse-gram.c"
     break;
 
   case 59:
 /* Line 1413 of yacc.c  */
-#line 480 "src/parse-gram.y"
+#line 481 "src/parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
 /* Line 1413 of yacc.c  */
-#line 2428 "src/parse-gram.c"
+#line 2440 "src/parse-gram.c"
     break;
 
   case 60:
 /* Line 1413 of yacc.c  */
-#line 482 "src/parse-gram.y"
+#line 483 "src/parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
 /* Line 1413 of yacc.c  */
-#line 2436 "src/parse-gram.c"
+#line 2448 "src/parse-gram.c"
     break;
 
   case 61:
 /* Line 1413 of yacc.c  */
-#line 486 "src/parse-gram.y"
+#line 487 "src/parse-gram.y"
     { (yyval.symbol) = (yyvsp[0].symbol); }
 /* Line 1413 of yacc.c  */
-#line 2444 "src/parse-gram.c"
+#line 2456 "src/parse-gram.c"
     break;
 
   case 62:
 /* Line 1413 of yacc.c  */
-#line 487 "src/parse-gram.y"
+#line 488 "src/parse-gram.y"
     { (yyval.symbol) = (yyvsp[-1].symbol); symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0])); }
 /* Line 1413 of yacc.c  */
-#line 2452 "src/parse-gram.c"
+#line 2464 "src/parse-gram.c"
     break;
 
   case 63:
 /* Line 1413 of yacc.c  */
-#line 493 "src/parse-gram.y"
+#line 494 "src/parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
 /* Line 1413 of yacc.c  */
-#line 2460 "src/parse-gram.c"
+#line 2472 "src/parse-gram.c"
     break;
 
   case 64:
 /* Line 1413 of yacc.c  */
-#line 495 "src/parse-gram.y"
+#line 496 "src/parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
 /* Line 1413 of yacc.c  */
-#line 2468 "src/parse-gram.c"
+#line 2480 "src/parse-gram.c"
     break;
 
   case 65:
 /* Line 1413 of yacc.c  */
-#line 499 "src/parse-gram.y"
+#line 500 "src/parse-gram.y"
     { (yyval.list) = (yyvsp[0].list); }
 /* Line 1413 of yacc.c  */
-#line 2476 "src/parse-gram.c"
+#line 2488 "src/parse-gram.c"
     break;
 
   case 66:
 /* Line 1413 of yacc.c  */
-#line 500 "src/parse-gram.y"
+#line 501 "src/parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), (yyvsp[0].list)); }
 /* Line 1413 of yacc.c  */
-#line 2484 "src/parse-gram.c"
+#line 2496 "src/parse-gram.c"
     break;
 
   case 67:
 /* Line 1413 of yacc.c  */
-#line 504 "src/parse-gram.y"
+#line 505 "src/parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
 /* Line 1413 of yacc.c  */
-#line 2492 "src/parse-gram.c"
+#line 2504 "src/parse-gram.c"
     break;
 
   case 68:
 /* Line 1413 of yacc.c  */
-#line 505 "src/parse-gram.y"
+#line 506 "src/parse-gram.y"
     { (yyval.list) = symbol_list_type_new ((yyvsp[0].uniqstr), (yylsp[0])); }
 /* Line 1413 of yacc.c  */
-#line 2500 "src/parse-gram.c"
+#line 2512 "src/parse-gram.c"
     break;
 
   case 69:
 /* Line 1413 of yacc.c  */
-#line 506 "src/parse-gram.y"
+#line 507 "src/parse-gram.y"
     { (yyval.list) = symbol_list_default_tagged_new ((yylsp[0])); }
 /* Line 1413 of yacc.c  */
-#line 2508 "src/parse-gram.c"
+#line 2520 "src/parse-gram.c"
     break;
 
   case 70:
 /* Line 1413 of yacc.c  */
-#line 507 "src/parse-gram.y"
+#line 508 "src/parse-gram.y"
     { (yyval.list) = symbol_list_default_tagless_new ((yylsp[0])); }
 /* Line 1413 of yacc.c  */
-#line 2516 "src/parse-gram.c"
+#line 2528 "src/parse-gram.c"
     break;
 
   case 71:
 /* Line 1413 of yacc.c  */
-#line 513 "src/parse-gram.y"
+#line 514 "src/parse-gram.y"
     {
        current_type = (yyvsp[0].uniqstr);
        tag_seen = true;
      }
 /* Line 1413 of yacc.c  */
-#line 2527 "src/parse-gram.c"
+#line 2539 "src/parse-gram.c"
     break;
 
   case 72:
 /* Line 1413 of yacc.c  */
-#line 518 "src/parse-gram.y"
+#line 519 "src/parse-gram.y"
     {
        symbol_class_set ((yyvsp[0].symbol), current_class, (yylsp[0]), true);
        symbol_type_set ((yyvsp[0].symbol), current_type, (yylsp[0]));
      }
 /* Line 1413 of yacc.c  */
-#line 2538 "src/parse-gram.c"
+#line 2550 "src/parse-gram.c"
     break;
 
   case 73:
 /* Line 1413 of yacc.c  */
-#line 523 "src/parse-gram.y"
+#line 524 "src/parse-gram.y"
     {
       symbol_class_set ((yyvsp[-1].symbol), current_class, (yylsp[-1]), true);
       symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
       symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0]));
     }
 /* Line 1413 of yacc.c  */
-#line 2550 "src/parse-gram.c"
+#line 2562 "src/parse-gram.c"
     break;
 
   case 74:
 /* Line 1413 of yacc.c  */
-#line 529 "src/parse-gram.y"
+#line 530 "src/parse-gram.y"
     {
       symbol_class_set ((yyvsp[-1].symbol), current_class, (yylsp[-1]), true);
       symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
       symbol_make_alias ((yyvsp[-1].symbol), (yyvsp[0].symbol), (yyloc));
     }
 /* Line 1413 of yacc.c  */
-#line 2562 "src/parse-gram.c"
+#line 2574 "src/parse-gram.c"
     break;
 
   case 75:
 /* Line 1413 of yacc.c  */
-#line 535 "src/parse-gram.y"
+#line 536 "src/parse-gram.y"
     {
       symbol_class_set ((yyvsp[-2].symbol), current_class, (yylsp[-2]), true);
       symbol_type_set ((yyvsp[-2].symbol), current_type, (yylsp[-2]));
@@ -2571,136 +2583,136 @@ yyreduce:
       symbol_make_alias ((yyvsp[-2].symbol), (yyvsp[0].symbol), (yyloc));
     }
 /* Line 1413 of yacc.c  */
-#line 2575 "src/parse-gram.c"
+#line 2587 "src/parse-gram.c"
     break;
 
   case 82:
 /* Line 1413 of yacc.c  */
-#line 565 "src/parse-gram.y"
+#line 566 "src/parse-gram.y"
     {
       yyerrok;
     }
 /* Line 1413 of yacc.c  */
-#line 2585 "src/parse-gram.c"
+#line 2597 "src/parse-gram.c"
     break;
 
   case 83:
 /* Line 1413 of yacc.c  */
-#line 571 "src/parse-gram.y"
+#line 572 "src/parse-gram.y"
     { current_lhs = (yyvsp[-1].symbol); current_lhs_location = (yylsp[-1]);
     current_lhs_named_ref = (yyvsp[0].named_ref); }
 /* Line 1413 of yacc.c  */
-#line 2594 "src/parse-gram.c"
+#line 2606 "src/parse-gram.c"
     break;
 
   case 85:
 /* Line 1413 of yacc.c  */
-#line 576 "src/parse-gram.y"
+#line 577 "src/parse-gram.y"
     { grammar_current_rule_end ((yylsp[0])); }
 /* Line 1413 of yacc.c  */
-#line 2602 "src/parse-gram.c"
+#line 2614 "src/parse-gram.c"
     break;
 
   case 86:
 /* Line 1413 of yacc.c  */
-#line 577 "src/parse-gram.y"
+#line 578 "src/parse-gram.y"
     { grammar_current_rule_end ((yylsp[0])); }
 /* Line 1413 of yacc.c  */
-#line 2610 "src/parse-gram.c"
+#line 2622 "src/parse-gram.c"
     break;
 
   case 88:
 /* Line 1413 of yacc.c  */
-#line 583 "src/parse-gram.y"
+#line 584 "src/parse-gram.y"
     { grammar_current_rule_begin (current_lhs, current_lhs_location,
 				  current_lhs_named_ref); }
 /* Line 1413 of yacc.c  */
-#line 2619 "src/parse-gram.c"
+#line 2631 "src/parse-gram.c"
     break;
 
   case 89:
 /* Line 1413 of yacc.c  */
-#line 586 "src/parse-gram.y"
+#line 587 "src/parse-gram.y"
     { grammar_current_rule_symbol_append ((yyvsp[-1].symbol), (yylsp[-1]), (yyvsp[0].named_ref)); }
 /* Line 1413 of yacc.c  */
-#line 2627 "src/parse-gram.c"
+#line 2639 "src/parse-gram.c"
     break;
 
   case 90:
 /* Line 1413 of yacc.c  */
-#line 588 "src/parse-gram.y"
+#line 589 "src/parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[-1].code), (yylsp[-1]), (yyvsp[0].named_ref)); }
 /* Line 1413 of yacc.c  */
-#line 2635 "src/parse-gram.c"
+#line 2647 "src/parse-gram.c"
     break;
 
   case 91:
 /* Line 1413 of yacc.c  */
-#line 590 "src/parse-gram.y"
+#line 591 "src/parse-gram.y"
     { grammar_current_rule_prec_set ((yyvsp[0].symbol), (yylsp[0])); }
 /* Line 1413 of yacc.c  */
-#line 2643 "src/parse-gram.c"
+#line 2655 "src/parse-gram.c"
     break;
 
   case 92:
 /* Line 1413 of yacc.c  */
-#line 592 "src/parse-gram.y"
+#line 593 "src/parse-gram.y"
     { grammar_current_rule_dprec_set ((yyvsp[0].integer), (yylsp[0])); }
 /* Line 1413 of yacc.c  */
-#line 2651 "src/parse-gram.c"
+#line 2663 "src/parse-gram.c"
     break;
 
   case 93:
 /* Line 1413 of yacc.c  */
-#line 594 "src/parse-gram.y"
+#line 595 "src/parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[0].uniqstr), (yylsp[0])); }
 /* Line 1413 of yacc.c  */
-#line 2659 "src/parse-gram.c"
+#line 2671 "src/parse-gram.c"
     break;
 
   case 94:
 /* Line 1413 of yacc.c  */
-#line 598 "src/parse-gram.y"
+#line 599 "src/parse-gram.y"
     { (yyval.named_ref) = 0; }
 /* Line 1413 of yacc.c  */
-#line 2667 "src/parse-gram.c"
+#line 2679 "src/parse-gram.c"
     break;
 
   case 95:
 /* Line 1413 of yacc.c  */
-#line 600 "src/parse-gram.y"
+#line 601 "src/parse-gram.y"
     { (yyval.named_ref) = named_ref_new((yyvsp[0].uniqstr), (yylsp[0])); }
 /* Line 1413 of yacc.c  */
-#line 2675 "src/parse-gram.c"
+#line 2687 "src/parse-gram.c"
     break;
 
   case 97:
 /* Line 1413 of yacc.c  */
-#line 612 "src/parse-gram.y"
+#line 613 "src/parse-gram.y"
     { (yyval.uniqstr) = uniqstr_new ((yyvsp[0].chars)); }
 /* Line 1413 of yacc.c  */
-#line 2683 "src/parse-gram.c"
+#line 2695 "src/parse-gram.c"
     break;
 
   case 98:
 /* Line 1413 of yacc.c  */
-#line 617 "src/parse-gram.y"
+#line 618 "src/parse-gram.y"
     { (yyval.chars) = ""; }
 /* Line 1413 of yacc.c  */
-#line 2691 "src/parse-gram.c"
+#line 2703 "src/parse-gram.c"
     break;
 
   case 99:
 /* Line 1413 of yacc.c  */
-#line 618 "src/parse-gram.y"
+#line 619 "src/parse-gram.y"
     { (yyval.chars) = (yyvsp[0].uniqstr); }
 /* Line 1413 of yacc.c  */
-#line 2699 "src/parse-gram.c"
+#line 2711 "src/parse-gram.c"
     break;
 
   case 101:
 /* Line 1413 of yacc.c  */
-#line 629 "src/parse-gram.y"
+#line 630 "src/parse-gram.y"
     {
       code_props plain_code;
       (yyvsp[0].code)[strlen ((yyvsp[0].code)) - 1] = '\n';
@@ -2710,51 +2722,51 @@ yyreduce:
       (yyval.chars) = plain_code.code;
     }
 /* Line 1413 of yacc.c  */
-#line 2714 "src/parse-gram.c"
+#line 2726 "src/parse-gram.c"
     break;
 
   case 102:
 /* Line 1413 of yacc.c  */
-#line 649 "src/parse-gram.y"
+#line 650 "src/parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
 /* Line 1413 of yacc.c  */
-#line 2722 "src/parse-gram.c"
+#line 2734 "src/parse-gram.c"
     break;
 
   case 103:
 /* Line 1413 of yacc.c  */
-#line 651 "src/parse-gram.y"
+#line 652 "src/parse-gram.y"
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[0].character)), (yylsp[0]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
       symbol_user_token_number_set ((yyval.symbol), (yyvsp[0].character), (yylsp[0]));
     }
 /* Line 1413 of yacc.c  */
-#line 2734 "src/parse-gram.c"
+#line 2746 "src/parse-gram.c"
     break;
 
   case 104:
 /* Line 1413 of yacc.c  */
-#line 659 "src/parse-gram.y"
+#line 660 "src/parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
 /* Line 1413 of yacc.c  */
-#line 2742 "src/parse-gram.c"
+#line 2754 "src/parse-gram.c"
     break;
 
   case 107:
 /* Line 1413 of yacc.c  */
-#line 671 "src/parse-gram.y"
+#line 672 "src/parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[0].chars)), (yylsp[0]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
     }
 /* Line 1413 of yacc.c  */
-#line 2753 "src/parse-gram.c"
+#line 2765 "src/parse-gram.c"
     break;
 
   case 109:
 /* Line 1413 of yacc.c  */
-#line 680 "src/parse-gram.y"
+#line 681 "src/parse-gram.y"
     {
       code_props plain_code;
       code_props_plain_init (&plain_code, (yyvsp[0].chars), (yylsp[0]));
@@ -2764,12 +2776,12 @@ yyreduce:
       code_scanner_last_string_free ();
     }
 /* Line 1413 of yacc.c  */
-#line 2768 "src/parse-gram.c"
+#line 2780 "src/parse-gram.c"
     break;
 
 
 /* Line 1413 of yacc.c  */
-#line 2773 "src/parse-gram.c"
+#line 2785 "src/parse-gram.c"
       default: break;
     }
   YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);
@@ -2977,7 +2989,7 @@ yyreturn:
 }
 
 /* Line 1623 of yacc.c  */
-#line 690 "src/parse-gram.y"
+#line 691 "src/parse-gram.y"
 
 
 
