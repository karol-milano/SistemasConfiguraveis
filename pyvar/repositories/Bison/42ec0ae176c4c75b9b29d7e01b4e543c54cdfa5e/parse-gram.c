@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 2.4.1.144-419e.  */
+/* A Bison parser, made by GNU Bison 2.4.1.153-9637-dirty.  */
 
 /* Skeleton implementation for Bison's Yacc-like parsers in C
    
@@ -45,7 +45,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "2.4.1.144-419e"
+#define YYBISON_VERSION "2.4.1.153-9637-dirty"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -221,19 +221,19 @@ static int current_prec = 0;
      PERCENT_VERBOSE = 296,
      PERCENT_YACC = 297,
      BRACED_CODE = 298,
-     CHAR = 299,
-     EPILOGUE = 300,
-     EQUAL = 301,
-     ID = 302,
-     ID_COLON = 303,
-     PERCENT_PERCENT = 304,
-     PIPE = 305,
-     PROLOGUE = 306,
-     SEMICOLON = 307,
-     TYPE = 308,
-     TYPE_TAG_ANY = 309,
-     TYPE_TAG_NONE = 310,
-     BRACKETED_ID = 311,
+     BRACKETED_ID = 299,
+     CHAR = 300,
+     EPILOGUE = 301,
+     EQUAL = 302,
+     ID = 303,
+     ID_COLON = 304,
+     PERCENT_PERCENT = 305,
+     PIPE = 306,
+     PROLOGUE = 307,
+     SEMICOLON = 308,
+     TYPE = 309,
+     TYPE_TAG_ANY = 310,
+     TYPE_TAG_NONE = 311,
      PERCENT_UNION = 312
    };
 #endif
@@ -280,19 +280,19 @@ static int current_prec = 0;
 #define PERCENT_VERBOSE 296
 #define PERCENT_YACC 297
 #define BRACED_CODE 298
-#define CHAR 299
-#define EPILOGUE 300
-#define EQUAL 301
-#define ID 302
-#define ID_COLON 303
-#define PERCENT_PERCENT 304
-#define PIPE 305
-#define PROLOGUE 306
-#define SEMICOLON 307
-#define TYPE 308
-#define TYPE_TAG_ANY 309
-#define TYPE_TAG_NONE 310
-#define BRACKETED_ID 311
+#define BRACKETED_ID 299
+#define CHAR 300
+#define EPILOGUE 301
+#define EQUAL 302
+#define ID 303
+#define ID_COLON 304
+#define PERCENT_PERCENT 305
+#define PIPE 306
+#define PROLOGUE 307
+#define SEMICOLON 308
+#define TYPE 309
+#define TYPE_TAG_ANY 310
+#define TYPE_TAG_NONE 311
 #define PERCENT_UNION 312
 
 
@@ -636,50 +636,50 @@ static const yytype_uint16 yyprhs[] =
 /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
 static const yytype_int8 yyrhs[] =
 {
-      59,     0,    -1,    60,    49,    77,    91,    -1,    -1,    60,
-      61,    -1,    62,    -1,    51,    -1,    17,    -1,    19,    84,
+      59,     0,    -1,    60,    50,    77,    91,    -1,    -1,    60,
+      61,    -1,    62,    -1,    52,    -1,    17,    -1,    19,    84,
       85,    -1,    20,    -1,    20,     3,    -1,    21,    -1,    22,
-       4,    -1,    23,     4,    -1,    24,     3,    -1,    24,    46,
+       4,    -1,    23,     4,    -1,    24,     3,    -1,    24,    47,
        3,    -1,    25,    -1,    26,    43,    -1,    27,     3,    -1,
-      28,    43,    -1,    29,    -1,    30,     3,    -1,    30,    46,
+      28,    43,    -1,    29,    -1,    30,     3,    -1,    30,    47,
        3,    -1,    32,    -1,    33,    -1,    34,     3,    -1,    34,
-      46,     3,    -1,    35,    43,    -1,    36,    -1,    37,     3,
+      47,     3,    -1,    35,    43,    -1,    36,    -1,    37,     3,
       -1,    38,     3,    -1,    40,    -1,    41,    -1,    42,    -1,
-      52,    -1,    67,    -1,    64,    -1,    39,    89,    -1,     8,
+      53,    -1,    67,    -1,    64,    -1,    39,    89,    -1,     8,
       43,    73,    -1,     9,    43,    73,    -1,    18,    -1,    31,
-      -1,    16,    86,    -1,    16,    47,    86,    -1,    -1,    47,
+      -1,    16,    86,    -1,    16,    48,    86,    -1,    -1,    48,
       -1,    57,    63,    86,    -1,    -1,     6,    65,    76,    -1,
-      -1,     5,    66,    76,    -1,     7,    53,    72,    -1,    68,
+      -1,     5,    66,    76,    -1,     7,    54,    72,    -1,    68,
       69,    70,    -1,    10,    -1,    11,    -1,    12,    -1,    -1,
-      53,    -1,    71,    -1,    70,    71,    -1,    89,    -1,    89,
+      54,    -1,    71,    -1,    70,    71,    -1,    89,    -1,    89,
        4,    -1,    89,    -1,    72,    89,    -1,    74,    -1,    73,
-      74,    -1,    89,    -1,    53,    -1,    54,    -1,    55,    -1,
-      53,    -1,    87,    -1,    87,     4,    -1,    87,    90,    -1,
+      74,    -1,    89,    -1,    54,    -1,    55,    -1,    56,    -1,
+      54,    -1,    87,    -1,    87,     4,    -1,    87,    90,    -1,
       87,     4,    90,    -1,    75,    -1,    76,    75,    -1,    78,
-      -1,    77,    78,    -1,    79,    -1,    62,    52,    -1,     1,
-      52,    -1,    -1,    88,    83,    80,    81,    -1,    82,    -1,
-      81,    50,    82,    -1,    81,    52,    -1,    -1,    82,    89,
+      -1,    77,    78,    -1,    79,    -1,    62,    53,    -1,     1,
+      53,    -1,    -1,    88,    83,    80,    81,    -1,    82,    -1,
+      81,    51,    82,    -1,    81,    53,    -1,    -1,    82,    89,
       83,    -1,    82,    43,    83,    -1,    82,    13,    89,    -1,
-      82,    14,     4,    -1,    82,    15,    53,    -1,    -1,    56,
-      -1,    47,    -1,     3,    -1,    -1,    47,    -1,     3,    -1,
-      43,    -1,    47,    -1,    44,    -1,    48,    -1,    87,    -1,
-      90,    -1,     3,    -1,    -1,    49,    45,    -1
+      82,    14,     4,    -1,    82,    15,    54,    -1,    -1,    44,
+      -1,    48,    -1,     3,    -1,    -1,    48,    -1,     3,    -1,
+      43,    -1,    48,    -1,    45,    -1,    49,    -1,    87,    -1,
+      90,    -1,     3,    -1,    -1,    50,    46,    -1
 };
 
 /* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
 static const yytype_uint16 yyrline[] =
 {
-       0,   207,   207,   215,   217,   221,   222,   232,   233,   238,
-     239,   244,   245,   246,   247,   248,   249,   254,   263,   264,
-     265,   266,   267,   268,   269,   270,   271,   272,   273,   288,
-     289,   313,   314,   315,   316,   320,   321,   322,   326,   333,
-     340,   344,   348,   355,   370,   371,   375,   387,   387,   392,
-     392,   397,   408,   423,   424,   425,   429,   430,   435,   437,
-     442,   443,   448,   450,   455,   456,   460,   461,   462,   463,
-     468,   473,   478,   484,   490,   501,   502,   511,   512,   518,
-     519,   520,   527,   527,   532,   533,   534,   539,   541,   543,
-     545,   547,   549,   554,   556,   567,   568,   573,   574,   575,
-     584,   604,   606,   615,   620,   621,   626,   633,   635
+       0,   209,   209,   217,   219,   223,   224,   234,   235,   240,
+     241,   246,   247,   248,   249,   250,   251,   256,   265,   266,
+     267,   268,   269,   270,   271,   272,   273,   274,   275,   290,
+     291,   315,   316,   317,   318,   322,   323,   324,   328,   335,
+     342,   346,   350,   357,   372,   373,   377,   389,   389,   394,
+     394,   399,   410,   425,   426,   427,   431,   432,   437,   439,
+     444,   445,   450,   452,   457,   458,   462,   463,   464,   465,
+     470,   475,   480,   486,   492,   503,   504,   513,   514,   520,
+     521,   522,   529,   529,   534,   535,   536,   541,   543,   545,
+     547,   549,   551,   556,   558,   569,   570,   575,   576,   577,
+     586,   606,   608,   617,   622,   623,   628,   635,   637
 };
 #endif
 
@@ -699,9 +699,9 @@ static const char *const yytname[] =
   "\"%no-lines\"", "\"%nondeterministic-parser\"", "\"%output\"",
   "\"%parse-param\"", "\"%pure-parser\"", "\"%require\"", "\"%skeleton\"",
   "\"%start\"", "\"%token-table\"", "\"%verbose\"", "\"%yacc\"",
-  "\"{...}\"", "\"char\"", "\"epilogue\"", "\"=\"", "\"identifier\"",
-  "\"identifier:\"", "\"%%\"", "\"|\"", "\"%{...%}\"", "\";\"", "\"type\"",
-  "\"<*>\"", "\"<>\"", "\"[identifier]\"", "\"%union\"", "$accept",
+  "\"{...}\"", "\"[identifier]\"", "\"char\"", "\"epilogue\"", "\"=\"",
+  "\"identifier\"", "\"identifier:\"", "\"%%\"", "\"|\"", "\"%{...%}\"",
+  "\";\"", "\"type\"", "\"<*>\"", "\"<>\"", "\"%union\"", "$accept",
   "input", "prologue_declarations", "prologue_declaration",
   "grammar_declaration", "union_name", "symbol_declaration", "$@1", "$@2",
   "precedence_declaration", "precedence_declarator", "type.opt",
@@ -792,33 +792,33 @@ static const yytype_int16 yydefgoto[] =
 
 /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
    STATE-NUM.  */
-#define YYPACT_NINF -60
+#define YYPACT_NINF -91
 static const yytype_int16 yypact[] =
 {
-     -60,     4,   103,   -60,   -60,   -60,    -2,    -1,    10,   -60,
-     -60,   -60,    17,   -60,   -60,    27,    66,   -60,    72,    79,
-       2,   -60,    47,    88,    49,   -60,    11,   -60,   -60,   -60,
-      25,    50,   -60,    91,    92,     0,   -60,   -60,   -60,    15,
-     -60,   -60,    51,   -60,   -60,   -60,   -60,    48,    -8,    -8,
-       0,    26,    26,   -60,    60,   -60,   -60,   -60,    31,   -60,
-     -60,   -60,   -60,   101,   -60,   -60,   -60,   -60,   102,   -60,
-     113,   -60,   -60,   -60,   -60,   -60,   -60,   -60,   -60,   -60,
-      54,   -60,    65,     1,   -60,   -60,    62,   -60,    60,   -60,
-       0,   -60,   -60,    -8,    83,    -8,     0,   -60,   -60,   -60,
-     -60,    26,   -60,   -60,    26,   -60,   -60,   -60,   -60,   -60,
-     -60,   -60,   -60,   -60,   104,   -60,   -60,   -60,   -60,   -60,
-       0,   -60,   142,   -60,   144,   -60,   -60,   -60,   -60,   -60,
-     -60,   -60,   -60,    -9,    53,   -60,   -60,     0,   146,    95,
-      62,    62,    53,   -60,   -60,   -60,   -60,   -60
+     -91,     3,   103,   -91,   -91,   -91,   -36,     2,    10,   -91,
+     -91,   -91,     9,   -91,   -91,    32,    60,   -91,    65,    67,
+      27,   -91,    41,    73,    51,   -91,    39,   -91,   -91,   -91,
+      40,    52,   -91,    93,    95,    33,   -91,   -91,   -91,    15,
+     -91,   -91,    53,   -91,   -91,   -91,   -91,    46,    43,    43,
+      33,    11,    11,   -91,    61,   -91,   -91,   -91,    35,   -91,
+     -91,   -91,   -91,   100,   -91,   -91,   -91,   -91,   102,   -91,
+     113,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,
+      64,   -91,    94,     1,   -91,   -91,    62,   -91,    61,   -91,
+      33,   -91,   -91,    43,    86,    43,    33,   -91,   -91,   -91,
+     -91,    11,   -91,   -91,    11,   -91,   -91,   -91,   -91,   -91,
+     -91,   -91,   -91,   -91,    72,   -91,   -91,   -91,   -91,   -91,
+      33,   -91,   142,   -91,   145,   -91,   -91,   -91,   -91,   -91,
+     -91,   -91,   -91,    17,    34,   -91,   -91,    33,   146,    97,
+      62,    62,    34,   -91,   -91,   -91,   -91,   -91
 };
 
 /* YYPGOTO[NTERM-NUM].  */
 static const yytype_int16 yypgoto[] =
 {
-     -60,   -60,   -60,   -60,   149,   -60,   -60,   -60,   -60,   -60,
-     -60,   -60,   -60,    33,   -60,   105,   -42,   -18,   107,   -60,
-      75,   -60,   -60,   -60,    24,   -52,   -60,   -60,   -36,   -11,
-     -60,   -35,   -59,   -60
+     -91,   -91,   -91,   -91,   147,   -91,   -91,   -91,   -91,   -91,
+     -91,   -91,   -91,    37,   -91,   106,   -60,   -33,   105,   -91,
+      69,   -91,   -91,   -91,    24,   -48,   -91,   -91,   -49,   -20,
+     -91,   -35,   -90,   -91
 };
 
 /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
@@ -827,49 +827,49 @@ static const yytype_int16 yypgoto[] =
 #define YYTABLE_NINF -108
 static const yytype_int16 yytable[] =
 {
-      78,  -107,    80,    74,     3,    62,     4,     5,     6,     7,
-       8,     9,    10,    11,    67,    97,    80,    12,   105,    14,
-       4,     5,     6,     7,     8,     9,    10,    11,    69,    74,
-      56,    12,    27,    14,   106,   125,    75,    94,    94,    76,
-      35,   135,    51,   136,    75,    91,    27,    76,    63,    81,
-     114,    50,   119,    52,    35,   122,    74,    68,    42,   127,
-      53,   126,   127,    81,    54,   132,   137,   138,   139,    59,
-      75,    70,    42,    76,    57,   123,    60,   123,   107,    98,
-      99,   100,    94,    61,    94,   122,    74,   124,   146,   147,
-      64,    65,    66,    71,    72,    73,   140,    75,    87,   141,
-      76,    89,   143,    53,   109,   110,   112,   141,     4,     5,
-       6,     7,     8,     9,    10,    11,   111,   113,   117,    12,
+      78,  -107,    80,     3,   125,   105,     4,     5,     6,     7,
+       8,     9,    10,    11,    74,    97,    80,    12,    50,    14,
+       4,     5,     6,     7,     8,     9,    10,    11,    94,    94,
+      62,    12,    27,    14,   132,    56,    74,    74,   106,   119,
+      35,   127,    67,    69,   127,    51,    27,   137,   138,   139,
+      81,   114,    53,    52,    35,   122,    75,    54,    42,    76,
+     123,   126,   123,    59,    81,    98,    99,   100,   135,    60,
+     136,    61,    42,    94,    63,    94,    65,   140,    75,    75,
+      57,    76,    76,   107,    64,   122,    68,    70,    75,    74,
+     124,    76,   146,   147,    66,    71,    72,    91,    73,   141,
+      89,    87,   143,   109,    53,   110,   117,   141,     4,     5,
+       6,     7,     8,     9,    10,    11,   111,   112,   128,    12,
       13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
       23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
-      33,    34,    35,    36,    37,    38,   131,    74,   145,   128,
-     144,    44,    39,   130,    40,    41,    95,   104,   115,   142,
+      33,    34,    35,    36,    37,    38,   131,   113,    74,    44,
+     144,   145,   115,    39,    95,    40,    41,   130,   104,   142,
       42
 };
 
 #define yypact_value_is_default(yystate) \
-  ((yystate) == (-60))
+  ((yystate) == (-91))
 
 #define yytable_value_is_error(yytable_value) \
   YYID (0)
 
 static const yytype_uint8 yycheck[] =
 {
-      35,     0,     1,     3,     0,     3,     5,     6,     7,     8,
+      35,     0,     1,     0,    94,    54,     5,     6,     7,     8,
        9,    10,    11,    12,     3,    50,     1,    16,    54,    18,
-       5,     6,     7,     8,     9,    10,    11,    12,     3,     3,
-       3,    16,    31,    18,     3,    94,    44,    48,    49,    47,
-      39,    50,    43,    52,    44,    53,    31,    47,    46,    48,
-      49,    53,    88,    43,    39,    90,     3,    46,    57,   101,
-      43,    96,   104,    48,    47,   124,    13,    14,    15,     3,
-      44,    46,    57,    47,    47,    93,     4,    95,    47,    53,
-      54,    55,    93,     4,    95,   120,     3,     4,   140,   141,
-      43,     3,    43,    43,     3,     3,    43,    44,    47,   134,
-      47,    53,   137,    43,     3,     3,    52,   142,     5,     6,
-       7,     8,     9,    10,    11,    12,     3,    52,    56,    16,
+       5,     6,     7,     8,     9,    10,    11,    12,    48,    49,
+       3,    16,    31,    18,   124,     3,     3,     3,     3,    88,
+      39,   101,     3,     3,   104,    43,    31,    13,    14,    15,
+      49,    50,    43,    43,    39,    90,    45,    48,    57,    48,
+      93,    96,    95,     3,    49,    54,    55,    56,    51,     4,
+      53,     4,    57,    93,    47,    95,     3,    43,    45,    45,
+      48,    48,    48,    48,    43,   120,    47,    47,    45,     3,
+       4,    48,   140,   141,    43,    43,     3,    54,     3,   134,
+      54,    48,   137,     3,    43,     3,    44,   142,     5,     6,
+       7,     8,     9,    10,    11,    12,     3,    53,    46,    16,
       17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
       27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
-      37,    38,    39,    40,    41,    42,     4,     3,    53,    45,
-       4,     2,    49,   120,    51,    52,    49,    52,    83,   135,
+      37,    38,    39,    40,    41,    42,     4,    53,     3,     2,
+       4,    54,    83,    50,    49,    52,    53,   120,    52,   135,
       57
 };
 
@@ -880,18 +880,18 @@ static const yytype_uint8 yystos[] =
        0,    59,    60,     0,     5,     6,     7,     8,     9,    10,
       11,    12,    16,    17,    18,    19,    20,    21,    22,    23,
       24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
-      34,    35,    36,    37,    38,    39,    40,    41,    42,    49,
-      51,    52,    57,    61,    62,    64,    67,    68,    66,    65,
-      53,    43,    43,    43,    47,    86,     3,    47,    84,     3,
-       4,     4,     3,    46,    43,     3,    43,     3,    46,     3,
-      46,    43,     3,     3,     3,    44,    47,    87,    89,    90,
-       1,    48,    62,    77,    78,    79,    88,    47,    63,    53,
-      69,    53,    75,    76,    87,    76,    72,    89,    53,    54,
-      55,    73,    74,    89,    73,    86,     3,    47,    85,     3,
-       3,     3,    52,    52,    49,    78,    91,    56,    83,    86,
-      70,    71,    89,    75,     4,    90,    89,    74,    45,    80,
-      71,     4,    90,    81,    82,    50,    52,    13,    14,    15,
-      43,    89,    82,    89,     4,    53,    83,    83
+      34,    35,    36,    37,    38,    39,    40,    41,    42,    50,
+      52,    53,    57,    61,    62,    64,    67,    68,    66,    65,
+      54,    43,    43,    43,    48,    86,     3,    48,    84,     3,
+       4,     4,     3,    47,    43,     3,    43,     3,    47,     3,
+      47,    43,     3,     3,     3,    45,    48,    87,    89,    90,
+       1,    49,    62,    77,    78,    79,    88,    48,    63,    54,
+      69,    54,    75,    76,    87,    76,    72,    89,    54,    55,
+      56,    73,    74,    89,    73,    86,     3,    48,    85,     3,
+       3,     3,    53,    53,    50,    78,    91,    44,    83,    86,
+      70,    71,    89,    75,     4,    90,    89,    74,    46,    80,
+      71,     4,    90,    81,    82,    51,    53,    13,    14,    15,
+      43,    89,    82,    89,     4,    54,    83,    83
 };
 
 #define yyerrok		(yyerrstatus = 0)
@@ -1066,68 +1066,86 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 /* Line 783 of yacc.c  */
 #line 1068 "parse-gram.c"
 	break;
-      case 44: /* "\"char\"" */
+      case 44: /* "\"[identifier]\"" */
+
+/* Line 783 of yacc.c  */
+#line 191 "parse-gram.y"
+	{ fprintf (stderr, "[%s]", (yyvaluep->uniqstr)); };
+
+/* Line 783 of yacc.c  */
+#line 1077 "parse-gram.c"
+	break;
+      case 45: /* "\"char\"" */
 
 /* Line 783 of yacc.c  */
 #line 178 "parse-gram.y"
 	{ fputs (char_name ((yyvaluep->character)), stderr); };
 
 /* Line 783 of yacc.c  */
-#line 1077 "parse-gram.c"
+#line 1086 "parse-gram.c"
 	break;
-      case 45: /* "\"epilogue\"" */
+      case 46: /* "\"epilogue\"" */
 
 /* Line 783 of yacc.c  */
 #line 186 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
 /* Line 783 of yacc.c  */
-#line 1086 "parse-gram.c"
+#line 1095 "parse-gram.c"
 	break;
-      case 47: /* "\"identifier\"" */
+      case 48: /* "\"identifier\"" */
 
 /* Line 783 of yacc.c  */
-#line 192 "parse-gram.y"
+#line 190 "parse-gram.y"
 	{ fputs ((yyvaluep->uniqstr), stderr); };
 
 /* Line 783 of yacc.c  */
-#line 1095 "parse-gram.c"
+#line 1104 "parse-gram.c"
 	break;
-      case 48: /* "\"identifier:\"" */
+      case 49: /* "\"identifier:\"" */
 
 /* Line 783 of yacc.c  */
-#line 193 "parse-gram.y"
+#line 192 "parse-gram.y"
 	{ fprintf (stderr, "%s:", (yyvaluep->uniqstr)); };
 
 /* Line 783 of yacc.c  */
-#line 1104 "parse-gram.c"
+#line 1113 "parse-gram.c"
 	break;
-      case 51: /* "\"%{...%}\"" */
+      case 52: /* "\"%{...%}\"" */
 
 /* Line 783 of yacc.c  */
 #line 186 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
 /* Line 783 of yacc.c  */
-#line 1113 "parse-gram.c"
+#line 1122 "parse-gram.c"
 	break;
-      case 53: /* "\"type\"" */
+      case 54: /* "\"type\"" */
 
 /* Line 783 of yacc.c  */
-#line 191 "parse-gram.y"
+#line 193 "parse-gram.y"
 	{ fprintf (stderr, "<%s>", (yyvaluep->uniqstr)); };
 
 /* Line 783 of yacc.c  */
-#line 1122 "parse-gram.c"
+#line 1131 "parse-gram.c"
+	break;
+      case 71: /* "symbol.prec" */
+
+/* Line 783 of yacc.c  */
+#line 199 "parse-gram.y"
+	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
+
+/* Line 783 of yacc.c  */
+#line 1140 "parse-gram.c"
 	break;
       case 84: /* "variable" */
 
 /* Line 783 of yacc.c  */
-#line 192 "parse-gram.y"
+#line 190 "parse-gram.y"
 	{ fputs ((yyvaluep->uniqstr), stderr); };
 
 /* Line 783 of yacc.c  */
-#line 1131 "parse-gram.c"
+#line 1149 "parse-gram.c"
 	break;
       case 85: /* "content.opt" */
 
@@ -1136,7 +1154,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
 /* Line 783 of yacc.c  */
-#line 1140 "parse-gram.c"
+#line 1158 "parse-gram.c"
 	break;
       case 86: /* "braceless" */
 
@@ -1145,7 +1163,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
 /* Line 783 of yacc.c  */
-#line 1149 "parse-gram.c"
+#line 1167 "parse-gram.c"
 	break;
       case 87: /* "id" */
 
@@ -1154,7 +1172,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
 /* Line 783 of yacc.c  */
-#line 1158 "parse-gram.c"
+#line 1176 "parse-gram.c"
 	break;
       case 88: /* "id_colon" */
 
@@ -1163,7 +1181,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 	{ fprintf (stderr, "%s:", (yyvaluep->symbol)->tag); };
 
 /* Line 783 of yacc.c  */
-#line 1167 "parse-gram.c"
+#line 1185 "parse-gram.c"
 	break;
       case 89: /* "symbol" */
 
@@ -1172,7 +1190,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
 /* Line 783 of yacc.c  */
-#line 1176 "parse-gram.c"
+#line 1194 "parse-gram.c"
 	break;
       case 90: /* "string_as_id" */
 
@@ -1181,7 +1199,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
 /* Line 783 of yacc.c  */
-#line 1185 "parse-gram.c"
+#line 1203 "parse-gram.c"
 	break;
       default:
 	break;
@@ -1718,7 +1736,7 @@ YYLTYPE yylloc;
 }
 
 /* Line 1266 of yacc.c  */
-#line 1722 "parse-gram.c"
+#line 1740 "parse-gram.c"
   yylsp[0] = yylloc;
 
   goto yysetstate;
@@ -1906,7 +1924,7 @@ yyreduce:
         case 6:
 
 /* Line 1479 of yacc.c  */
-#line 223 "parse-gram.y"
+#line 225 "parse-gram.y"
     {
       code_props plain_code;
       code_props_plain_init (&plain_code, (yyvsp[(1) - (1)].chars), (yylsp[(1) - (1)]));
@@ -1921,14 +1939,14 @@ yyreduce:
   case 7:
 
 /* Line 1479 of yacc.c  */
-#line 232 "parse-gram.y"
+#line 234 "parse-gram.y"
     { debug_flag = true; }
     break;
 
   case 8:
 
 /* Line 1479 of yacc.c  */
-#line 234 "parse-gram.y"
+#line 236 "parse-gram.y"
     {
       muscle_percent_define_insert ((yyvsp[(2) - (3)].uniqstr), (yylsp[(2) - (3)]), (yyvsp[(3) - (3)].chars),
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
@@ -1938,14 +1956,14 @@ yyreduce:
   case 9:
 
 /* Line 1479 of yacc.c  */
-#line 238 "parse-gram.y"
+#line 240 "parse-gram.y"
     { defines_flag = true; }
     break;
 
   case 10:
 
 /* Line 1479 of yacc.c  */
-#line 240 "parse-gram.y"
+#line 242 "parse-gram.y"
     {
       defines_flag = true;
       spec_defines_file = xstrdup ((yyvsp[(2) - (2)].chars));
@@ -1955,42 +1973,42 @@ yyreduce:
   case 11:
 
 /* Line 1479 of yacc.c  */
-#line 244 "parse-gram.y"
+#line 246 "parse-gram.y"
     { error_verbose = true; }
     break;
 
   case 12:
 
 /* Line 1479 of yacc.c  */
-#line 245 "parse-gram.y"
+#line 247 "parse-gram.y"
     { expected_sr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 13:
 
 /* Line 1479 of yacc.c  */
-#line 246 "parse-gram.y"
+#line 248 "parse-gram.y"
     { expected_rr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 14:
 
 /* Line 1479 of yacc.c  */
-#line 247 "parse-gram.y"
+#line 249 "parse-gram.y"
     { spec_file_prefix = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 15:
 
 /* Line 1479 of yacc.c  */
-#line 248 "parse-gram.y"
+#line 250 "parse-gram.y"
     { spec_file_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 16:
 
 /* Line 1479 of yacc.c  */
-#line 250 "parse-gram.y"
+#line 252 "parse-gram.y"
     {
       nondeterministic_parser = true;
       glr_parser = true;
@@ -2000,7 +2018,7 @@ yyreduce:
   case 17:
 
 /* Line 1479 of yacc.c  */
-#line 255 "parse-gram.y"
+#line 257 "parse-gram.y"
     {
       code_props action;
       code_props_symbol_action_init (&action, (yyvsp[(2) - (2)].code), (yylsp[(2) - (2)]));
@@ -2014,77 +2032,77 @@ yyreduce:
   case 18:
 
 /* Line 1479 of yacc.c  */
-#line 263 "parse-gram.y"
+#line 265 "parse-gram.y"
     { language_argmatch ((yyvsp[(2) - (2)].chars), grammar_prio, (yylsp[(1) - (2)])); }
     break;
 
   case 19:
 
 /* Line 1479 of yacc.c  */
-#line 264 "parse-gram.y"
+#line 266 "parse-gram.y"
     { add_param ("lex_param", (yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
     break;
 
   case 20:
 
 /* Line 1479 of yacc.c  */
-#line 265 "parse-gram.y"
+#line 267 "parse-gram.y"
     { locations_flag = true; }
     break;
 
   case 21:
 
 /* Line 1479 of yacc.c  */
-#line 266 "parse-gram.y"
+#line 268 "parse-gram.y"
     { spec_name_prefix = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 22:
 
 /* Line 1479 of yacc.c  */
-#line 267 "parse-gram.y"
+#line 269 "parse-gram.y"
     { spec_name_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 23:
 
 /* Line 1479 of yacc.c  */
-#line 268 "parse-gram.y"
+#line 270 "parse-gram.y"
     { no_lines_flag = true; }
     break;
 
   case 24:
 
 /* Line 1479 of yacc.c  */
-#line 269 "parse-gram.y"
+#line 271 "parse-gram.y"
     { nondeterministic_parser = true; }
     break;
 
   case 25:
 
 /* Line 1479 of yacc.c  */
-#line 270 "parse-gram.y"
+#line 272 "parse-gram.y"
     { spec_outfile = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 26:
 
 /* Line 1479 of yacc.c  */
-#line 271 "parse-gram.y"
+#line 273 "parse-gram.y"
     { spec_outfile = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 27:
 
 /* Line 1479 of yacc.c  */
-#line 272 "parse-gram.y"
+#line 274 "parse-gram.y"
     { add_param ("parse_param", (yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
     break;
 
   case 28:
 
 /* Line 1479 of yacc.c  */
-#line 274 "parse-gram.y"
+#line 276 "parse-gram.y"
     {
       /* %pure-parser is deprecated in favor of `%define api.pure', so use
          `%define api.pure' in a backward-compatible manner here.  First, don't
@@ -2104,14 +2122,14 @@ yyreduce:
   case 29:
 
 /* Line 1479 of yacc.c  */
-#line 288 "parse-gram.y"
+#line 290 "parse-gram.y"
     { version_check (&(yylsp[(2) - (2)]), (yyvsp[(2) - (2)].chars)); }
     break;
 
   case 30:
 
 /* Line 1479 of yacc.c  */
-#line 290 "parse-gram.y"
+#line 292 "parse-gram.y"
     {
       char const *skeleton_user = (yyvsp[(2) - (2)].chars);
       if (strchr (skeleton_user, '/'))
@@ -2140,28 +2158,28 @@ yyreduce:
   case 31:
 
 /* Line 1479 of yacc.c  */
-#line 313 "parse-gram.y"
+#line 315 "parse-gram.y"
     { token_table_flag = true; }
     break;
 
   case 32:
 
 /* Line 1479 of yacc.c  */
-#line 314 "parse-gram.y"
+#line 316 "parse-gram.y"
     { report_flag |= report_states; }
     break;
 
   case 33:
 
 /* Line 1479 of yacc.c  */
-#line 315 "parse-gram.y"
+#line 317 "parse-gram.y"
     { yacc_flag = true; }
     break;
 
   case 37:
 
 /* Line 1479 of yacc.c  */
-#line 323 "parse-gram.y"
+#line 325 "parse-gram.y"
     {
       grammar_start_symbol_set ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]));
     }
@@ -2170,7 +2188,7 @@ yyreduce:
   case 38:
 
 /* Line 1479 of yacc.c  */
-#line 327 "parse-gram.y"
+#line 329 "parse-gram.y"
     {
       symbol_list *list;
       for (list = (yyvsp[(3) - (3)].list); list; list = list->next)
@@ -2182,7 +2200,7 @@ yyreduce:
   case 39:
 
 /* Line 1479 of yacc.c  */
-#line 334 "parse-gram.y"
+#line 336 "parse-gram.y"
     {
       symbol_list *list;
       for (list = (yyvsp[(3) - (3)].list); list; list = list->next)
@@ -2194,7 +2212,7 @@ yyreduce:
   case 40:
 
 /* Line 1479 of yacc.c  */
-#line 341 "parse-gram.y"
+#line 343 "parse-gram.y"
     {
       default_prec = true;
     }
@@ -2203,7 +2221,7 @@ yyreduce:
   case 41:
 
 /* Line 1479 of yacc.c  */
-#line 345 "parse-gram.y"
+#line 347 "parse-gram.y"
     {
       default_prec = false;
     }
@@ -2212,7 +2230,7 @@ yyreduce:
   case 42:
 
 /* Line 1479 of yacc.c  */
-#line 349 "parse-gram.y"
+#line 351 "parse-gram.y"
     {
       /* Do not invoke muscle_percent_code_grow here since it invokes
          muscle_user_name_list_grow.  */
@@ -2224,7 +2242,7 @@ yyreduce:
   case 43:
 
 /* Line 1479 of yacc.c  */
-#line 356 "parse-gram.y"
+#line 358 "parse-gram.y"
     {
       muscle_percent_code_grow ((yyvsp[(2) - (3)].uniqstr), (yylsp[(2) - (3)]), (yyvsp[(3) - (3)].chars), (yylsp[(3) - (3)]));
       code_scanner_last_string_free ();
@@ -2234,21 +2252,21 @@ yyreduce:
   case 44:
 
 /* Line 1479 of yacc.c  */
-#line 370 "parse-gram.y"
+#line 372 "parse-gram.y"
     {}
     break;
 
   case 45:
 
 /* Line 1479 of yacc.c  */
-#line 371 "parse-gram.y"
+#line 373 "parse-gram.y"
     { muscle_code_grow ("union_name", (yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 46:
 
 /* Line 1479 of yacc.c  */
-#line 376 "parse-gram.y"
+#line 378 "parse-gram.y"
     {
       union_seen = true;
       muscle_code_grow ("stype", (yyvsp[(3) - (3)].chars), (yylsp[(3) - (3)]));
@@ -2259,14 +2277,14 @@ yyreduce:
   case 47:
 
 /* Line 1479 of yacc.c  */
-#line 387 "parse-gram.y"
+#line 389 "parse-gram.y"
     { current_class = nterm_sym; }
     break;
 
   case 48:
 
 /* Line 1479 of yacc.c  */
-#line 388 "parse-gram.y"
+#line 390 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
@@ -2276,14 +2294,14 @@ yyreduce:
   case 49:
 
 /* Line 1479 of yacc.c  */
-#line 392 "parse-gram.y"
+#line 394 "parse-gram.y"
     { current_class = token_sym; }
     break;
 
   case 50:
 
 /* Line 1479 of yacc.c  */
-#line 393 "parse-gram.y"
+#line 395 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
@@ -2293,7 +2311,7 @@ yyreduce:
   case 51:
 
 /* Line 1479 of yacc.c  */
-#line 398 "parse-gram.y"
+#line 400 "parse-gram.y"
     {
       symbol_list *list;
       tag_seen = true;
@@ -2306,7 +2324,7 @@ yyreduce:
   case 52:
 
 /* Line 1479 of yacc.c  */
-#line 409 "parse-gram.y"
+#line 411 "parse-gram.y"
     {
       symbol_list *list;
       ++current_prec;
@@ -2323,126 +2341,126 @@ yyreduce:
   case 53:
 
 /* Line 1479 of yacc.c  */
-#line 423 "parse-gram.y"
+#line 425 "parse-gram.y"
     { (yyval.assoc) = left_assoc; }
     break;
 
   case 54:
 
 /* Line 1479 of yacc.c  */
-#line 424 "parse-gram.y"
+#line 426 "parse-gram.y"
     { (yyval.assoc) = right_assoc; }
     break;
 
   case 55:
 
 /* Line 1479 of yacc.c  */
-#line 425 "parse-gram.y"
+#line 427 "parse-gram.y"
     { (yyval.assoc) = non_assoc; }
     break;
 
   case 56:
 
 /* Line 1479 of yacc.c  */
-#line 429 "parse-gram.y"
+#line 431 "parse-gram.y"
     { current_type = NULL; }
     break;
 
   case 57:
 
 /* Line 1479 of yacc.c  */
-#line 430 "parse-gram.y"
+#line 432 "parse-gram.y"
     { current_type = (yyvsp[(1) - (1)].uniqstr); tag_seen = true; }
     break;
 
   case 58:
 
 /* Line 1479 of yacc.c  */
-#line 436 "parse-gram.y"
+#line 438 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 59:
 
 /* Line 1479 of yacc.c  */
-#line 438 "parse-gram.y"
+#line 440 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), symbol_list_sym_new ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]))); }
     break;
 
   case 60:
 
 /* Line 1479 of yacc.c  */
-#line 442 "parse-gram.y"
+#line 444 "parse-gram.y"
     { (yyval.symbol) = (yyvsp[(1) - (1)].symbol); }
     break;
 
   case 61:
 
 /* Line 1479 of yacc.c  */
-#line 443 "parse-gram.y"
+#line 445 "parse-gram.y"
     { (yyval.symbol) = (yyvsp[(1) - (2)].symbol); symbol_user_token_number_set ((yyvsp[(1) - (2)].symbol), (yyvsp[(2) - (2)].integer), (yylsp[(2) - (2)])); }
     break;
 
   case 62:
 
 /* Line 1479 of yacc.c  */
-#line 449 "parse-gram.y"
+#line 451 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 63:
 
 /* Line 1479 of yacc.c  */
-#line 451 "parse-gram.y"
+#line 453 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), symbol_list_sym_new ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]))); }
     break;
 
   case 64:
 
 /* Line 1479 of yacc.c  */
-#line 455 "parse-gram.y"
+#line 457 "parse-gram.y"
     { (yyval.list) = (yyvsp[(1) - (1)].list); }
     break;
 
   case 65:
 
 /* Line 1479 of yacc.c  */
-#line 456 "parse-gram.y"
+#line 458 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), (yyvsp[(2) - (2)].list)); }
     break;
 
   case 66:
 
 /* Line 1479 of yacc.c  */
-#line 460 "parse-gram.y"
+#line 462 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 67:
 
 /* Line 1479 of yacc.c  */
-#line 461 "parse-gram.y"
+#line 463 "parse-gram.y"
     { (yyval.list) = symbol_list_type_new ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 68:
 
 /* Line 1479 of yacc.c  */
-#line 462 "parse-gram.y"
+#line 464 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagged_new ((yylsp[(1) - (1)])); }
     break;
 
   case 69:
 
 /* Line 1479 of yacc.c  */
-#line 463 "parse-gram.y"
+#line 465 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagless_new ((yylsp[(1) - (1)])); }
     break;
 
   case 70:
 
 /* Line 1479 of yacc.c  */
-#line 469 "parse-gram.y"
+#line 471 "parse-gram.y"
     {
        current_type = (yyvsp[(1) - (1)].uniqstr);
        tag_seen = true;
@@ -2452,7 +2470,7 @@ yyreduce:
   case 71:
 
 /* Line 1479 of yacc.c  */
-#line 474 "parse-gram.y"
+#line 476 "parse-gram.y"
     {
        symbol_class_set ((yyvsp[(1) - (1)].symbol), current_class, (yylsp[(1) - (1)]), true);
        symbol_type_set ((yyvsp[(1) - (1)].symbol), current_type, (yylsp[(1) - (1)]));
@@ -2462,7 +2480,7 @@ yyreduce:
   case 72:
 
 /* Line 1479 of yacc.c  */
-#line 479 "parse-gram.y"
+#line 481 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
       symbol_type_set ((yyvsp[(1) - (2)].symbol), current_type, (yylsp[(1) - (2)]));
@@ -2473,7 +2491,7 @@ yyreduce:
   case 73:
 
 /* Line 1479 of yacc.c  */
-#line 485 "parse-gram.y"
+#line 487 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
       symbol_type_set ((yyvsp[(1) - (2)].symbol), current_type, (yylsp[(1) - (2)]));
@@ -2484,7 +2502,7 @@ yyreduce:
   case 74:
 
 /* Line 1479 of yacc.c  */
-#line 491 "parse-gram.y"
+#line 493 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (3)].symbol), current_class, (yylsp[(1) - (3)]), true);
       symbol_type_set ((yyvsp[(1) - (3)].symbol), current_type, (yylsp[(1) - (3)]));
@@ -2496,7 +2514,7 @@ yyreduce:
   case 81:
 
 /* Line 1479 of yacc.c  */
-#line 521 "parse-gram.y"
+#line 523 "parse-gram.y"
     {
       yyerrok;
     }
@@ -2505,7 +2523,7 @@ yyreduce:
   case 82:
 
 /* Line 1479 of yacc.c  */
-#line 527 "parse-gram.y"
+#line 529 "parse-gram.y"
     { current_lhs = (yyvsp[(1) - (2)].symbol); current_lhs_location = (yylsp[(1) - (2)]);
     current_lhs_named_ref = (yyvsp[(2) - (2)].named_ref); }
     break;
@@ -2513,21 +2531,21 @@ yyreduce:
   case 84:
 
 /* Line 1479 of yacc.c  */
-#line 532 "parse-gram.y"
+#line 534 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(1) - (1)])); }
     break;
 
   case 85:
 
 /* Line 1479 of yacc.c  */
-#line 533 "parse-gram.y"
+#line 535 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(3) - (3)])); }
     break;
 
   case 87:
 
 /* Line 1479 of yacc.c  */
-#line 539 "parse-gram.y"
+#line 541 "parse-gram.y"
     { grammar_current_rule_begin (current_lhs, current_lhs_location,
 				  current_lhs_named_ref); }
     break;
@@ -2535,77 +2553,77 @@ yyreduce:
   case 88:
 
 /* Line 1479 of yacc.c  */
-#line 542 "parse-gram.y"
+#line 544 "parse-gram.y"
     { grammar_current_rule_symbol_append ((yyvsp[(2) - (3)].symbol), (yylsp[(2) - (3)]), (yyvsp[(3) - (3)].named_ref)); }
     break;
 
   case 89:
 
 /* Line 1479 of yacc.c  */
-#line 544 "parse-gram.y"
+#line 546 "parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[(2) - (3)].code), (yylsp[(2) - (3)]), (yyvsp[(3) - (3)].named_ref)); }
     break;
 
   case 90:
 
 /* Line 1479 of yacc.c  */
-#line 546 "parse-gram.y"
+#line 548 "parse-gram.y"
     { grammar_current_rule_prec_set ((yyvsp[(3) - (3)].symbol), (yylsp[(3) - (3)])); }
     break;
 
   case 91:
 
 /* Line 1479 of yacc.c  */
-#line 548 "parse-gram.y"
+#line 550 "parse-gram.y"
     { grammar_current_rule_dprec_set ((yyvsp[(3) - (3)].integer), (yylsp[(3) - (3)])); }
     break;
 
   case 92:
 
 /* Line 1479 of yacc.c  */
-#line 550 "parse-gram.y"
+#line 552 "parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[(3) - (3)].uniqstr), (yylsp[(3) - (3)])); }
     break;
 
   case 93:
 
 /* Line 1479 of yacc.c  */
-#line 554 "parse-gram.y"
+#line 556 "parse-gram.y"
     { (yyval.named_ref) = 0; }
     break;
 
   case 94:
 
 /* Line 1479 of yacc.c  */
-#line 556 "parse-gram.y"
+#line 558 "parse-gram.y"
     { (yyval.named_ref) = named_ref_new((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 96:
 
 /* Line 1479 of yacc.c  */
-#line 568 "parse-gram.y"
+#line 570 "parse-gram.y"
     { (yyval.uniqstr) = uniqstr_new ((yyvsp[(1) - (1)].chars)); }
     break;
 
   case 97:
 
 /* Line 1479 of yacc.c  */
-#line 573 "parse-gram.y"
+#line 575 "parse-gram.y"
     { (yyval.chars) = ""; }
     break;
 
   case 98:
 
 /* Line 1479 of yacc.c  */
-#line 574 "parse-gram.y"
+#line 576 "parse-gram.y"
     { (yyval.chars) = (yyvsp[(1) - (1)].uniqstr); }
     break;
 
   case 100:
 
 /* Line 1479 of yacc.c  */
-#line 585 "parse-gram.y"
+#line 587 "parse-gram.y"
     {
       code_props plain_code;
       (yyvsp[(1) - (1)].code)[strlen ((yyvsp[(1) - (1)].code)) - 1] = '\n';
@@ -2619,14 +2637,14 @@ yyreduce:
   case 101:
 
 /* Line 1479 of yacc.c  */
-#line 605 "parse-gram.y"
+#line 607 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 102:
 
 /* Line 1479 of yacc.c  */
-#line 607 "parse-gram.y"
+#line 609 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[(1) - (1)].character)), (yylsp[(1) - (1)]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[(1) - (1)]), false);
@@ -2637,14 +2655,14 @@ yyreduce:
   case 103:
 
 /* Line 1479 of yacc.c  */
-#line 615 "parse-gram.y"
+#line 617 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 106:
 
 /* Line 1479 of yacc.c  */
-#line 627 "parse-gram.y"
+#line 629 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[(1) - (1)].chars)), (yylsp[(1) - (1)]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[(1) - (1)]), false);
@@ -2654,7 +2672,7 @@ yyreduce:
   case 108:
 
 /* Line 1479 of yacc.c  */
-#line 636 "parse-gram.y"
+#line 638 "parse-gram.y"
     {
       code_props plain_code;
       code_props_plain_init (&plain_code, (yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)]));
@@ -2668,7 +2686,7 @@ yyreduce:
 
 
 /* Line 1479 of yacc.c  */
-#line 2672 "parse-gram.c"
+#line 2690 "parse-gram.c"
       default: break;
     }
   YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);
@@ -2878,7 +2896,7 @@ yyreturn:
 
 
 /* Line 1690 of yacc.c  */
-#line 646 "parse-gram.y"
+#line 648 "parse-gram.y"
 
 
 
