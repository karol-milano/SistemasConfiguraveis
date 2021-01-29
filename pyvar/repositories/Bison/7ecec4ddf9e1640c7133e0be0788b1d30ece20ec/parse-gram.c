@@ -77,7 +77,7 @@
 
 /* Copy the first part of user declarations.  */
 
-/* Line 1535 of yacc.c  */
+/* Line 1537 of yacc.c  */
 #line 1 "parse-gram.y"
 /* Bison Grammar Parser                             -*- C -*-
 
@@ -157,7 +157,7 @@ static int current_prec = 0;
 #define YYTYPE_UINT8 uint_fast8_t
 
 
-/* Line 1535 of yacc.c  */
+/* Line 1537 of yacc.c  */
 #line 162 "parse-gram.c"
 
 /* Enabling traces.  */
@@ -244,72 +244,14 @@ static int current_prec = 0;
      PERCENT_UNION = 313
    };
 #endif
-/* Tokens.  */
-#define GRAM_EOF 0
-#define STRING 258
-#define INT 259
-#define PERCENT_TOKEN 260
-#define PERCENT_NTERM 261
-#define PERCENT_TYPE 262
-#define PERCENT_DESTRUCTOR 263
-#define PERCENT_PRINTER 264
-#define PERCENT_LEFT 265
-#define PERCENT_RIGHT 266
-#define PERCENT_NONASSOC 267
-#define PERCENT_PREC 268
-#define PERCENT_DPREC 269
-#define PERCENT_MERGE 270
-#define PERCENT_CODE 271
-#define PERCENT_DEBUG 272
-#define PERCENT_DEFAULT_PREC 273
-#define PERCENT_DEFINE 274
-#define PERCENT_DEFINES 275
-#define PERCENT_ERROR_VERBOSE 276
-#define PERCENT_EXPECT 277
-#define PERCENT_EXPECT_RR 278
-#define PERCENT_FILE_PREFIX 279
-#define PERCENT_GLR_PARSER 280
-#define PERCENT_INITIAL_ACTION 281
-#define PERCENT_LANGUAGE 282
-#define PERCENT_LEX_PARAM 283
-#define PERCENT_LOCATIONS 284
-#define PERCENT_NAME_PREFIX 285
-#define PERCENT_NO_DEFAULT_PREC 286
-#define PERCENT_NO_LINES 287
-#define PERCENT_NONDETERMINISTIC_PARSER 288
-#define PERCENT_OUTPUT 289
-#define PERCENT_PARSE_PARAM 290
-#define PERCENT_PURE_PARSER 291
-#define PERCENT_PUSH_PARSER 292
-#define PERCENT_PUSH_PULL_PARSER 293
-#define PERCENT_REQUIRE 294
-#define PERCENT_SKELETON 295
-#define PERCENT_START 296
-#define PERCENT_TOKEN_TABLE 297
-#define PERCENT_VERBOSE 298
-#define PERCENT_YACC 299
-#define BRACED_CODE 300
-#define CHAR 301
-#define EPILOGUE 302
-#define EQUAL 303
-#define ID 304
-#define ID_COLON 305
-#define PERCENT_PERCENT 306
-#define PIPE 307
-#define PROLOGUE 308
-#define SEMICOLON 309
-#define TYPE 310
-#define TYPE_TAG_ANY 311
-#define TYPE_TAG_NONE 312
-#define PERCENT_UNION 313
-
 
 
 
 #if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
 typedef union YYSTYPE
 {
-/* Line 1535 of yacc.c  */
+
+/* Line 1537 of yacc.c  */
 #line 97 "parse-gram.y"
 
   symbol *symbol;
@@ -320,11 +262,12 @@ typedef union YYSTYPE
   assoc assoc;
   uniqstr uniqstr;
   unsigned char character;
-}
 
-/* Line 1535 of yacc.c  */
-#line 327 "parse-gram.c"
-	YYSTYPE;
+
+
+/* Line 1537 of yacc.c  */
+#line 270 "parse-gram.c"
+} YYSTYPE;
 # define YYSTYPE_IS_TRIVIAL 1
 # define yystype YYSTYPE /* obsolescent; will be withdrawn */
 # define YYSTYPE_IS_DECLARED 1
@@ -347,8 +290,8 @@ typedef struct YYLTYPE
 /* Copy the second part of user declarations.  */
 
 
-/* Line 1535 of yacc.c  */
-#line 352 "parse-gram.c"
+/* Line 1537 of yacc.c  */
+#line 295 "parse-gram.c"
 
 #ifdef short
 # undef short
@@ -653,7 +596,7 @@ static const yytype_int8 yyrhs[] =
       43,    -1,    44,    -1,    54,    -1,    68,    -1,    65,    -1,
       41,    87,    -1,     8,    45,    72,    -1,     9,    45,    72,
       -1,    18,    -1,    31,    -1,    16,    84,    -1,    16,    49,
-      84,    -1,    -1,    49,    -1,    58,    64,    45,    -1,    -1,
+      84,    -1,    -1,    49,    -1,    58,    64,    84,    -1,    -1,
        6,    66,    75,    -1,    -1,     5,    67,    75,    -1,     7,
       55,    71,    -1,    69,    70,    71,    -1,    10,    -1,    11,
       -1,    12,    -1,    -1,    55,    -1,    87,    -1,    71,    87,
@@ -673,17 +616,17 @@ static const yytype_int8 yyrhs[] =
 /* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
 static const yytype_uint16 yyrline[] =
 {
-       0,   210,   210,   218,   220,   224,   225,   234,   235,   247,
-     248,   253,   254,   255,   256,   257,   258,   263,   272,   273,
-     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
-     284,   285,   286,   287,   288,   289,   290,   294,   295,   296,
-     300,   307,   314,   318,   322,   327,   348,   349,   353,   382,
-     382,   387,   387,   392,   403,   418,   419,   420,   424,   425,
-     430,   432,   437,   438,   442,   443,   444,   445,   450,   455,
-     460,   466,   472,   483,   484,   493,   494,   500,   501,   502,
-     509,   509,   513,   514,   515,   520,   521,   523,   525,   527,
-     529,   539,   540,   546,   550,   559,   579,   581,   590,   595,
-     596,   601,   608,   610
+       0,   210,   210,   218,   220,   224,   225,   235,   236,   248,
+     249,   254,   255,   256,   257,   258,   259,   264,   273,   274,
+     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
+     285,   286,   287,   288,   289,   290,   291,   295,   296,   297,
+     301,   308,   315,   319,   323,   328,   349,   350,   354,   366,
+     366,   371,   371,   376,   387,   402,   403,   404,   408,   409,
+     414,   416,   421,   422,   426,   427,   428,   429,   434,   439,
+     444,   450,   456,   467,   468,   477,   478,   484,   485,   486,
+     493,   493,   497,   498,   499,   504,   505,   507,   509,   511,
+     513,   523,   524,   530,   534,   543,   563,   565,   574,   579,
+     580,   585,   592,   594
 };
 #endif
 
@@ -799,29 +742,29 @@ static const yytype_int16 yydefgoto[] =
 #define YYPACT_NINF -79
 static const yytype_int16 yypact[] =
 {
-     -79,     5,    96,   -79,   -79,   -79,     3,    17,    18,   -79,
-     -79,   -79,    -8,   -79,   -79,    27,    61,   -79,    65,    73,
-      31,   -79,    41,    75,    43,   -79,    32,   -79,   -79,   -79,
-      33,    44,   -79,   -79,   -79,    87,    89,    26,   -79,   -79,
-     -79,    15,   -79,   -79,    45,   -79,   -79,   -79,   -79,    42,
-      38,    38,    26,    11,    11,   -79,    51,   -79,   -79,   -79,
-      95,   -79,   -79,   -79,   -79,   106,   -79,   -79,   -79,   -79,
-     107,   -79,   108,   -79,   -79,   -79,   -79,   -79,   -79,   -79,
-     -79,   -79,    88,   -79,    90,     1,   -79,   -79,   -79,   -79,
-      54,   -79,    26,   -79,   -79,    38,    50,    38,    26,   -79,
+     -79,     5,    96,   -79,   -79,   -79,    -6,    13,    18,   -79,
+     -79,   -79,    -8,   -79,   -79,    27,    66,   -79,    74,    82,
+      31,   -79,    43,    86,    45,   -79,    32,   -79,   -79,   -79,
+      33,    47,   -79,   -79,   -79,    91,    93,    26,   -79,   -79,
+     -79,    15,   -79,   -79,    48,   -79,   -79,   -79,   -79,    44,
+      38,    38,    26,    11,    11,   -79,    53,   -79,   -79,   -79,
+     106,   -79,   -79,   -79,   -79,   107,   -79,   -79,   -79,   -79,
+     108,   -79,   138,   -79,   -79,   -79,   -79,   -79,   -79,   -79,
+     -79,   -79,    88,   -79,    89,     1,   -79,   -79,   -79,   -79,
+      53,   -79,    26,   -79,   -79,    38,    50,    38,    26,   -79,
      -79,   -79,   -79,    11,   -79,   -79,    11,   -79,   -79,   -79,
-     -79,   -79,   -79,   -79,   -79,    94,   -79,   -79,   -79,   -79,
-      26,   -79,   140,   -79,   -79,   -79,   -79,    -9,    25,   -79,
-     -79,   -79,    26,   141,    91,   -79,   -79,    25,   -79,   -79,
+     -79,   -79,   -79,   -79,   -79,    97,   -79,   -79,   -79,   -79,
+      26,   -79,   142,   -79,   -79,   -79,   -79,    -7,    25,   -79,
+     -79,   -79,    26,   144,    98,   -79,   -79,    25,   -79,   -79,
      -79
 };
 
 /* YYPGOTO[NTERM-NUM].  */
 static const yytype_int16 yypgoto[] =
 {
-     -79,   -79,   -79,   -79,   146,   -79,   -79,   -79,   -79,   -79,
-     -79,   -79,    59,    98,   -21,   -48,   102,   -79,    70,   -79,
-     -79,   -79,    28,   -79,   -79,   100,   -47,   -79,   -37,   -78,
+     -79,   -79,   -79,   -79,   149,   -79,   -79,   -79,   -79,   -79,
+     -79,   -79,    54,   101,   -21,   -33,   105,   -79,    67,   -79,
+     -79,   -79,    28,   -79,   -79,   -13,   -47,   -79,   -37,   -78,
      -79
 };
 
@@ -836,18 +779,18 @@ static const yytype_int16 yytable[] =
        8,     9,    10,    11,    76,    99,    82,    12,   123,    14,
        4,     5,     6,     7,     8,     9,    10,    11,    76,    76,
       58,    12,    27,    14,    64,    69,    71,    55,   132,   133,
-     134,    56,    37,   130,   129,   131,    27,   121,    96,   121,
-      96,    83,   115,    76,   122,    99,    37,    77,    52,    44,
-      78,   124,    53,    54,    61,    83,   100,   101,   102,    62,
-     135,    77,    77,    44,    78,    78,    59,    63,    67,    65,
-      70,    72,   125,   124,    77,   125,    66,    78,    68,    73,
-      74,   136,    75,    93,    89,   138,    55,    91,   108,   119,
-     136,     4,     5,     6,     7,     8,     9,    10,    11,   110,
-     111,   112,    12,    13,    14,    15,    16,    17,    18,    19,
+     134,    56,    37,   107,   129,   130,    27,   131,    96,    52,
+      96,    83,   115,    76,   122,    99,    37,    77,    53,    44,
+      78,   124,   121,    54,   121,    83,   100,   101,   102,    61,
+     135,    77,    77,    44,    78,    78,    59,   119,    62,    65,
+      70,    72,   125,   124,    77,   125,    63,    78,    66,    67,
+      68,   136,    73,    93,    74,   138,    75,    89,    55,    91,
+     136,     4,     5,     6,     7,     8,     9,    10,    11,   108,
+     110,   111,    12,    13,    14,    15,    16,    17,    18,    19,
       20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
       30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
-      40,   126,   113,    76,   114,   139,   140,    41,    46,    42,
-      43,   120,   106,    97,    44,   116,   107,     0,   137
+      40,   112,   113,   114,   126,    76,   120,    41,   139,    42,
+      43,    46,   116,   140,    44,   106,    97,     0,   137
 };
 
 static const yytype_int16 yycheck[] =
@@ -856,18 +799,18 @@ static const yytype_int16 yycheck[] =
        9,    10,    11,    12,     3,    52,     1,    16,    96,    18,
        5,     6,     7,     8,     9,    10,    11,    12,     3,     3,
        3,    16,    31,    18,     3,     3,     3,    45,    13,    14,
-      15,    49,    41,    52,   122,    54,    31,    95,    95,    97,
-      97,    50,    51,     3,     4,    92,    41,    46,    55,    58,
-      49,    98,    45,    45,     3,    50,    55,    56,    57,     4,
-      45,    46,    46,    58,    49,    49,    49,     4,     3,    48,
-      48,    48,   103,   120,    46,   106,    45,    49,    45,    45,
-       3,   128,     3,    55,    49,   132,    45,    55,     3,    45,
+      15,    49,    41,    56,   122,    52,    31,    54,    95,    55,
+      97,    50,    51,     3,     4,    92,    41,    46,    45,    58,
+      49,    98,    95,    45,    97,    50,    55,    56,    57,     3,
+      45,    46,    46,    58,    49,    49,    49,    90,     4,    48,
+      48,    48,   103,   120,    46,   106,     4,    49,    45,     3,
+      45,   128,    45,    55,     3,   132,     3,    49,    45,    55,
      137,     5,     6,     7,     8,     9,    10,    11,    12,     3,
        3,     3,    16,    17,    18,    19,    20,    21,    22,    23,
       24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
       34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
-      44,    47,    54,     3,    54,     4,    55,    51,     2,    53,
-      54,    92,    54,    51,    58,    85,    56,    -1,   130
+      44,     3,    54,    54,    47,     3,    92,    51,     4,    53,
+      54,     2,    85,    55,    58,    54,    51,    -1,   130
 };
 
 /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
@@ -885,7 +828,7 @@ static const yytype_uint8 yystos[] =
       87,    88,     1,    50,    63,    76,    77,    78,    86,    49,
       64,    55,    70,    55,    74,    75,    85,    75,    71,    87,
       55,    56,    57,    72,    73,    87,    72,    84,     3,    83,
-       3,     3,     3,    54,    54,    51,    77,    89,    79,    45,
+       3,     3,     3,    54,    54,    51,    77,    89,    79,    84,
       71,    74,     4,    88,    87,    73,    47,    80,    81,    88,
       52,    54,    13,    14,    15,    45,    87,    81,    87,     4,
       55
@@ -1038,147 +981,147 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
     {
       case 3: /* "\"string\"" */
 
-/* Line 1535 of yacc.c  */
+/* Line 1537 of yacc.c  */
 #line 188 "parse-gram.y"
 	{ fputs (quotearg_style (c_quoting_style, (yyvaluep->chars)), stderr); };
 
-/* Line 1535 of yacc.c  */
-#line 1047 "parse-gram.c"
+/* Line 1537 of yacc.c  */
+#line 990 "parse-gram.c"
 	break;
       case 4: /* "\"integer\"" */
 
-/* Line 1535 of yacc.c  */
+/* Line 1537 of yacc.c  */
 #line 199 "parse-gram.y"
 	{ fprintf (stderr, "%d", (yyvaluep->integer)); };
 
-/* Line 1535 of yacc.c  */
-#line 1056 "parse-gram.c"
+/* Line 1537 of yacc.c  */
+#line 999 "parse-gram.c"
 	break;
       case 45: /* "\"{...}\"" */
 
-/* Line 1535 of yacc.c  */
+/* Line 1537 of yacc.c  */
 #line 190 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->code)); };
 
-/* Line 1535 of yacc.c  */
-#line 1065 "parse-gram.c"
+/* Line 1537 of yacc.c  */
+#line 1008 "parse-gram.c"
 	break;
       case 46: /* "\"char\"" */
 
-/* Line 1535 of yacc.c  */
+/* Line 1537 of yacc.c  */
 #line 182 "parse-gram.y"
 	{ fputs (char_name ((yyvaluep->character)), stderr); };
 
-/* Line 1535 of yacc.c  */
-#line 1074 "parse-gram.c"
+/* Line 1537 of yacc.c  */
+#line 1017 "parse-gram.c"
 	break;
       case 47: /* "\"epilogue\"" */
 
-/* Line 1535 of yacc.c  */
+/* Line 1537 of yacc.c  */
 #line 190 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
-/* Line 1535 of yacc.c  */
-#line 1083 "parse-gram.c"
+/* Line 1537 of yacc.c  */
+#line 1026 "parse-gram.c"
 	break;
       case 49: /* "\"identifier\"" */
 
-/* Line 1535 of yacc.c  */
+/* Line 1537 of yacc.c  */
 #line 195 "parse-gram.y"
 	{ fputs ((yyvaluep->uniqstr), stderr); };
 
-/* Line 1535 of yacc.c  */
-#line 1092 "parse-gram.c"
+/* Line 1537 of yacc.c  */
+#line 1035 "parse-gram.c"
 	break;
       case 50: /* "\"identifier:\"" */
 
-/* Line 1535 of yacc.c  */
+/* Line 1537 of yacc.c  */
 #line 196 "parse-gram.y"
 	{ fprintf (stderr, "%s:", (yyvaluep->uniqstr)); };
 
-/* Line 1535 of yacc.c  */
-#line 1101 "parse-gram.c"
+/* Line 1537 of yacc.c  */
+#line 1044 "parse-gram.c"
 	break;
       case 53: /* "\"%{...%}\"" */
 
-/* Line 1535 of yacc.c  */
+/* Line 1537 of yacc.c  */
 #line 190 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
-/* Line 1535 of yacc.c  */
-#line 1110 "parse-gram.c"
+/* Line 1537 of yacc.c  */
+#line 1053 "parse-gram.c"
 	break;
       case 55: /* "\"type\"" */
 
-/* Line 1535 of yacc.c  */
+/* Line 1537 of yacc.c  */
 #line 194 "parse-gram.y"
 	{ fprintf (stderr, "<%s>", (yyvaluep->uniqstr)); };
 
-/* Line 1535 of yacc.c  */
-#line 1119 "parse-gram.c"
+/* Line 1537 of yacc.c  */
+#line 1062 "parse-gram.c"
 	break;
       case 82: /* "variable" */
 
-/* Line 1535 of yacc.c  */
+/* Line 1537 of yacc.c  */
 #line 195 "parse-gram.y"
 	{ fputs ((yyvaluep->uniqstr), stderr); };
 
-/* Line 1535 of yacc.c  */
-#line 1128 "parse-gram.c"
+/* Line 1537 of yacc.c  */
+#line 1071 "parse-gram.c"
 	break;
       case 83: /* "content.opt" */
 
-/* Line 1535 of yacc.c  */
+/* Line 1537 of yacc.c  */
 #line 190 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
-/* Line 1535 of yacc.c  */
-#line 1137 "parse-gram.c"
+/* Line 1537 of yacc.c  */
+#line 1080 "parse-gram.c"
 	break;
       case 84: /* "braceless" */
 
-/* Line 1535 of yacc.c  */
+/* Line 1537 of yacc.c  */
 #line 190 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
-/* Line 1535 of yacc.c  */
-#line 1146 "parse-gram.c"
+/* Line 1537 of yacc.c  */
+#line 1089 "parse-gram.c"
 	break;
       case 85: /* "id" */
 
-/* Line 1535 of yacc.c  */
+/* Line 1537 of yacc.c  */
 #line 202 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
-/* Line 1535 of yacc.c  */
-#line 1155 "parse-gram.c"
+/* Line 1537 of yacc.c  */
+#line 1098 "parse-gram.c"
 	break;
       case 86: /* "id_colon" */
 
-/* Line 1535 of yacc.c  */
+/* Line 1537 of yacc.c  */
 #line 203 "parse-gram.y"
 	{ fprintf (stderr, "%s:", (yyvaluep->symbol)->tag); };
 
-/* Line 1535 of yacc.c  */
-#line 1164 "parse-gram.c"
+/* Line 1537 of yacc.c  */
+#line 1107 "parse-gram.c"
 	break;
       case 87: /* "symbol" */
 
-/* Line 1535 of yacc.c  */
+/* Line 1537 of yacc.c  */
 #line 202 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
-/* Line 1535 of yacc.c  */
-#line 1173 "parse-gram.c"
+/* Line 1537 of yacc.c  */
+#line 1116 "parse-gram.c"
 	break;
       case 88: /* "string_as_id" */
 
-/* Line 1535 of yacc.c  */
+/* Line 1537 of yacc.c  */
 #line 202 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
-/* Line 1535 of yacc.c  */
-#line 1182 "parse-gram.c"
+/* Line 1537 of yacc.c  */
+#line 1125 "parse-gram.c"
 	break;
       default:
 	break;
@@ -1692,7 +1635,7 @@ YYLTYPE yylloc;
 
   /* User initialization code.  */
   
-/* Line 1535 of yacc.c  */
+/* Line 1537 of yacc.c  */
 #line 89 "parse-gram.y"
 {
   /* Bison's grammar can initial empty locations, hence a default
@@ -1701,8 +1644,8 @@ YYLTYPE yylloc;
   boundary_set (&yylloc.end, current_file, 1, 1);
 }
 
-/* Line 1535 of yacc.c  */
-#line 1706 "parse-gram.c"
+/* Line 1537 of yacc.c  */
+#line 1649 "parse-gram.c"
   yylsp[0] = yylloc;
   goto yysetstate;
 
@@ -1887,29 +1830,30 @@ yyreduce:
     {
         case 6:
 
-/* Line 1535 of yacc.c  */
+/* Line 1537 of yacc.c  */
 #line 226 "parse-gram.y"
     {
       code_props plain_code;
       code_props_plain_init (&plain_code, (yyvsp[(1) - (1)].chars), (yylsp[(1) - (1)]));
       code_props_translate_code (&plain_code);
       gram_scanner_last_string_free ();
-      prologue_augment (plain_code.code, (yylsp[(1) - (1)]), union_seen);
+      muscle_code_grow (union_seen ? "post_prologue" : "pre_prologue",
+                        plain_code.code, (yylsp[(1) - (1)]));
       code_scanner_last_string_free ();
     }
     break;
 
   case 7:
 
-/* Line 1535 of yacc.c  */
-#line 234 "parse-gram.y"
+/* Line 1537 of yacc.c  */
+#line 235 "parse-gram.y"
     { debug_flag = true; }
     break;
 
   case 8:
 
-/* Line 1535 of yacc.c  */
-#line 236 "parse-gram.y"
+/* Line 1537 of yacc.c  */
+#line 237 "parse-gram.y"
     {
       char const name_prefix[] = "percent_define_";
       char *name = xmalloc (sizeof name_prefix + strlen ((yyvsp[(2) - (3)].uniqstr)));
@@ -1925,15 +1869,15 @@ yyreduce:
 
   case 9:
 
-/* Line 1535 of yacc.c  */
-#line 247 "parse-gram.y"
+/* Line 1537 of yacc.c  */
+#line 248 "parse-gram.y"
     { defines_flag = true; }
     break;
 
   case 10:
 
-/* Line 1535 of yacc.c  */
-#line 249 "parse-gram.y"
+/* Line 1537 of yacc.c  */
+#line 250 "parse-gram.y"
     {
       defines_flag = true;
       spec_defines_file = xstrdup ((yyvsp[(2) - (2)].chars));
@@ -1942,43 +1886,43 @@ yyreduce:
 
   case 11:
 
-/* Line 1535 of yacc.c  */
-#line 253 "parse-gram.y"
+/* Line 1537 of yacc.c  */
+#line 254 "parse-gram.y"
     { error_verbose = true; }
     break;
 
   case 12:
 
-/* Line 1535 of yacc.c  */
-#line 254 "parse-gram.y"
+/* Line 1537 of yacc.c  */
+#line 255 "parse-gram.y"
     { expected_sr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 13:
 
-/* Line 1535 of yacc.c  */
-#line 255 "parse-gram.y"
+/* Line 1537 of yacc.c  */
+#line 256 "parse-gram.y"
     { expected_rr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 14:
 
-/* Line 1535 of yacc.c  */
-#line 256 "parse-gram.y"
+/* Line 1537 of yacc.c  */
+#line 257 "parse-gram.y"
     { spec_file_prefix = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 15:
 
-/* Line 1535 of yacc.c  */
-#line 257 "parse-gram.y"
+/* Line 1537 of yacc.c  */
+#line 258 "parse-gram.y"
     { spec_file_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 16:
 
-/* Line 1535 of yacc.c  */
-#line 259 "parse-gram.y"
+/* Line 1537 of yacc.c  */
+#line 260 "parse-gram.y"
     {
       nondeterministic_parser = true;
       glr_parser = true;
@@ -1987,8 +1931,8 @@ yyreduce:
 
   case 17:
 
-/* Line 1535 of yacc.c  */
-#line 264 "parse-gram.y"
+/* Line 1537 of yacc.c  */
+#line 265 "parse-gram.y"
     {
       code_props action;
       code_props_symbol_action_init (&action, (yyvsp[(2) - (2)].code), (yylsp[(2) - (2)]));
@@ -2001,134 +1945,134 @@ yyreduce:
 
   case 18:
 
-/* Line 1535 of yacc.c  */
-#line 272 "parse-gram.y"
+/* Line 1537 of yacc.c  */
+#line 273 "parse-gram.y"
     { language_argmatch ((yyvsp[(2) - (2)].chars), 1, &(yylsp[(1) - (2)])); }
     break;
 
   case 19:
 
-/* Line 1535 of yacc.c  */
-#line 273 "parse-gram.y"
+/* Line 1537 of yacc.c  */
+#line 274 "parse-gram.y"
     { add_param ("lex_param", (yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
     break;
 
   case 20:
 
-/* Line 1535 of yacc.c  */
-#line 274 "parse-gram.y"
+/* Line 1537 of yacc.c  */
+#line 275 "parse-gram.y"
     { locations_flag = true; }
     break;
 
   case 21:
 
-/* Line 1535 of yacc.c  */
-#line 275 "parse-gram.y"
+/* Line 1537 of yacc.c  */
+#line 276 "parse-gram.y"
     { spec_name_prefix = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 22:
 
-/* Line 1535 of yacc.c  */
-#line 276 "parse-gram.y"
+/* Line 1537 of yacc.c  */
+#line 277 "parse-gram.y"
     { spec_name_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 23:
 
-/* Line 1535 of yacc.c  */
-#line 277 "parse-gram.y"
+/* Line 1537 of yacc.c  */
+#line 278 "parse-gram.y"
     { no_lines_flag = true; }
     break;
 
   case 24:
 
-/* Line 1535 of yacc.c  */
-#line 278 "parse-gram.y"
+/* Line 1537 of yacc.c  */
+#line 279 "parse-gram.y"
     { nondeterministic_parser = true; }
     break;
 
   case 25:
 
-/* Line 1535 of yacc.c  */
-#line 279 "parse-gram.y"
+/* Line 1537 of yacc.c  */
+#line 280 "parse-gram.y"
     { spec_outfile = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 26:
 
-/* Line 1535 of yacc.c  */
-#line 280 "parse-gram.y"
+/* Line 1537 of yacc.c  */
+#line 281 "parse-gram.y"
     { spec_outfile = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 27:
 
-/* Line 1535 of yacc.c  */
-#line 281 "parse-gram.y"
+/* Line 1537 of yacc.c  */
+#line 282 "parse-gram.y"
     { add_param ("parse_param", (yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
     break;
 
   case 28:
 
-/* Line 1535 of yacc.c  */
-#line 282 "parse-gram.y"
+/* Line 1537 of yacc.c  */
+#line 283 "parse-gram.y"
     { pure_parser = true; }
     break;
 
   case 29:
 
-/* Line 1535 of yacc.c  */
-#line 283 "parse-gram.y"
+/* Line 1537 of yacc.c  */
+#line 284 "parse-gram.y"
     { push_parser = true; pull_parser = false; }
     break;
 
   case 30:
 
-/* Line 1535 of yacc.c  */
-#line 284 "parse-gram.y"
+/* Line 1537 of yacc.c  */
+#line 285 "parse-gram.y"
     { push_parser = true; pull_parser = true; }
     break;
 
   case 31:
 
-/* Line 1535 of yacc.c  */
-#line 285 "parse-gram.y"
+/* Line 1537 of yacc.c  */
+#line 286 "parse-gram.y"
     { version_check (&(yylsp[(2) - (2)]), (yyvsp[(2) - (2)].chars)); }
     break;
 
   case 32:
 
-/* Line 1535 of yacc.c  */
-#line 286 "parse-gram.y"
+/* Line 1537 of yacc.c  */
+#line 287 "parse-gram.y"
     { skeleton_arg ((yyvsp[(2) - (2)].chars), 1, &(yylsp[(1) - (2)])); }
     break;
 
   case 33:
 
-/* Line 1535 of yacc.c  */
-#line 287 "parse-gram.y"
+/* Line 1537 of yacc.c  */
+#line 288 "parse-gram.y"
     { token_table_flag = true; }
     break;
 
   case 34:
 
-/* Line 1535 of yacc.c  */
-#line 288 "parse-gram.y"
+/* Line 1537 of yacc.c  */
+#line 289 "parse-gram.y"
     { report_flag = report_states; }
     break;
 
   case 35:
 
-/* Line 1535 of yacc.c  */
-#line 289 "parse-gram.y"
+/* Line 1537 of yacc.c  */
+#line 290 "parse-gram.y"
     { yacc_flag = true; }
     break;
 
   case 39:
 
-/* Line 1535 of yacc.c  */
-#line 297 "parse-gram.y"
+/* Line 1537 of yacc.c  */
+#line 298 "parse-gram.y"
     {
       grammar_start_symbol_set ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]));
     }
@@ -2136,8 +2080,8 @@ yyreduce:
 
   case 40:
 
-/* Line 1535 of yacc.c  */
-#line 301 "parse-gram.y"
+/* Line 1537 of yacc.c  */
+#line 302 "parse-gram.y"
     {
       symbol_list *list;
       for (list = (yyvsp[(3) - (3)].list); list; list = list->next)
@@ -2148,8 +2092,8 @@ yyreduce:
 
   case 41:
 
-/* Line 1535 of yacc.c  */
-#line 308 "parse-gram.y"
+/* Line 1537 of yacc.c  */
+#line 309 "parse-gram.y"
     {
       symbol_list *list;
       for (list = (yyvsp[(3) - (3)].list); list; list = list->next)
@@ -2160,8 +2104,8 @@ yyreduce:
 
   case 42:
 
-/* Line 1535 of yacc.c  */
-#line 315 "parse-gram.y"
+/* Line 1537 of yacc.c  */
+#line 316 "parse-gram.y"
     {
       default_prec = true;
     }
@@ -2169,8 +2113,8 @@ yyreduce:
 
   case 43:
 
-/* Line 1535 of yacc.c  */
-#line 319 "parse-gram.y"
+/* Line 1537 of yacc.c  */
+#line 320 "parse-gram.y"
     {
       default_prec = false;
     }
@@ -2178,8 +2122,8 @@ yyreduce:
 
   case 44:
 
-/* Line 1535 of yacc.c  */
-#line 323 "parse-gram.y"
+/* Line 1537 of yacc.c  */
+#line 324 "parse-gram.y"
     {
       muscle_code_grow ("percent_code", (yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)]));
       code_scanner_last_string_free ();
@@ -2188,8 +2132,8 @@ yyreduce:
 
   case 45:
 
-/* Line 1535 of yacc.c  */
-#line 328 "parse-gram.y"
+/* Line 1537 of yacc.c  */
+#line 329 "parse-gram.y"
     {
       char const name_prefix[] = "percent_code_";
       char *name = xmalloc (sizeof name_prefix + strlen ((yyvsp[(2) - (3)].uniqstr)));
@@ -2204,57 +2148,40 @@ yyreduce:
 
   case 46:
 
-/* Line 1535 of yacc.c  */
-#line 348 "parse-gram.y"
+/* Line 1537 of yacc.c  */
+#line 349 "parse-gram.y"
     {}
     break;
 
   case 47:
 
-/* Line 1535 of yacc.c  */
-#line 349 "parse-gram.y"
+/* Line 1537 of yacc.c  */
+#line 350 "parse-gram.y"
     { muscle_code_grow ("union_name", (yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 48:
 
-/* Line 1535 of yacc.c  */
-#line 354 "parse-gram.y"
+/* Line 1537 of yacc.c  */
+#line 355 "parse-gram.y"
     {
-      char const *body = (yyvsp[(3) - (3)].code);
-
-      /* Concatenate the %union bodies.  If this is the first %union, make sure
-	 the synchronization line appears after the opening '{' so as not to
-	 confuse Doxygen.  Otherwise, turn the previous %union's trailing '}'
-	 into '\n', and omit the new %union's leading '{'.  */
-      if (!union_seen)
-	{
-	  muscle_grow ("stype", "{", "");
-	}
-      else
-	{
-	  char *code = muscle_find ("stype");
-	  code[strlen (code) - 1] = '\n';
-	}
-      body++;
-
       union_seen = true;
-      muscle_code_grow ("stype", body, (yylsp[(3) - (3)]));
-      gram_scanner_last_string_free ();
+      muscle_code_grow ("stype", (yyvsp[(3) - (3)].chars), (yylsp[(3) - (3)]));
+      code_scanner_last_string_free ();
     }
     break;
 
   case 49:
 
-/* Line 1535 of yacc.c  */
-#line 382 "parse-gram.y"
+/* Line 1537 of yacc.c  */
+#line 366 "parse-gram.y"
     { current_class = nterm_sym; }
     break;
 
   case 50:
 
-/* Line 1535 of yacc.c  */
-#line 383 "parse-gram.y"
+/* Line 1537 of yacc.c  */
+#line 367 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
@@ -2263,15 +2190,15 @@ yyreduce:
 
   case 51:
 
-/* Line 1535 of yacc.c  */
-#line 387 "parse-gram.y"
+/* Line 1537 of yacc.c  */
+#line 371 "parse-gram.y"
     { current_class = token_sym; }
     break;
 
   case 52:
 
-/* Line 1535 of yacc.c  */
-#line 388 "parse-gram.y"
+/* Line 1537 of yacc.c  */
+#line 372 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
@@ -2280,8 +2207,8 @@ yyreduce:
 
   case 53:
 
-/* Line 1535 of yacc.c  */
-#line 393 "parse-gram.y"
+/* Line 1537 of yacc.c  */
+#line 377 "parse-gram.y"
     {
       symbol_list *list;
       tag_seen = true;
@@ -2293,8 +2220,8 @@ yyreduce:
 
   case 54:
 
-/* Line 1535 of yacc.c  */
-#line 404 "parse-gram.y"
+/* Line 1537 of yacc.c  */
+#line 388 "parse-gram.y"
     {
       symbol_list *list;
       ++current_prec;
@@ -2310,99 +2237,99 @@ yyreduce:
 
   case 55:
 
-/* Line 1535 of yacc.c  */
-#line 418 "parse-gram.y"
+/* Line 1537 of yacc.c  */
+#line 402 "parse-gram.y"
     { (yyval.assoc) = left_assoc; }
     break;
 
   case 56:
 
-/* Line 1535 of yacc.c  */
-#line 419 "parse-gram.y"
+/* Line 1537 of yacc.c  */
+#line 403 "parse-gram.y"
     { (yyval.assoc) = right_assoc; }
     break;
 
   case 57:
 
-/* Line 1535 of yacc.c  */
-#line 420 "parse-gram.y"
+/* Line 1537 of yacc.c  */
+#line 404 "parse-gram.y"
     { (yyval.assoc) = non_assoc; }
     break;
 
   case 58:
 
-/* Line 1535 of yacc.c  */
-#line 424 "parse-gram.y"
+/* Line 1537 of yacc.c  */
+#line 408 "parse-gram.y"
     { current_type = NULL; }
     break;
 
   case 59:
 
-/* Line 1535 of yacc.c  */
-#line 425 "parse-gram.y"
+/* Line 1537 of yacc.c  */
+#line 409 "parse-gram.y"
     { current_type = (yyvsp[(1) - (1)].uniqstr); tag_seen = true; }
     break;
 
   case 60:
 
-/* Line 1535 of yacc.c  */
-#line 431 "parse-gram.y"
+/* Line 1537 of yacc.c  */
+#line 415 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 61:
 
-/* Line 1535 of yacc.c  */
-#line 433 "parse-gram.y"
+/* Line 1537 of yacc.c  */
+#line 417 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), symbol_list_sym_new ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]))); }
     break;
 
   case 62:
 
-/* Line 1535 of yacc.c  */
-#line 437 "parse-gram.y"
+/* Line 1537 of yacc.c  */
+#line 421 "parse-gram.y"
     { (yyval.list) = (yyvsp[(1) - (1)].list); }
     break;
 
   case 63:
 
-/* Line 1535 of yacc.c  */
-#line 438 "parse-gram.y"
+/* Line 1537 of yacc.c  */
+#line 422 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), (yyvsp[(2) - (2)].list)); }
     break;
 
   case 64:
 
-/* Line 1535 of yacc.c  */
-#line 442 "parse-gram.y"
+/* Line 1537 of yacc.c  */
+#line 426 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 65:
 
-/* Line 1535 of yacc.c  */
-#line 443 "parse-gram.y"
+/* Line 1537 of yacc.c  */
+#line 427 "parse-gram.y"
     { (yyval.list) = symbol_list_type_new ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 66:
 
-/* Line 1535 of yacc.c  */
-#line 444 "parse-gram.y"
+/* Line 1537 of yacc.c  */
+#line 428 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagged_new ((yylsp[(1) - (1)])); }
     break;
 
   case 67:
 
-/* Line 1535 of yacc.c  */
-#line 445 "parse-gram.y"
+/* Line 1537 of yacc.c  */
+#line 429 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagless_new ((yylsp[(1) - (1)])); }
     break;
 
   case 68:
 
-/* Line 1535 of yacc.c  */
-#line 451 "parse-gram.y"
+/* Line 1537 of yacc.c  */
+#line 435 "parse-gram.y"
     {
        current_type = (yyvsp[(1) - (1)].uniqstr);
        tag_seen = true;
@@ -2411,8 +2338,8 @@ yyreduce:
 
   case 69:
 
-/* Line 1535 of yacc.c  */
-#line 456 "parse-gram.y"
+/* Line 1537 of yacc.c  */
+#line 440 "parse-gram.y"
     {
        symbol_class_set ((yyvsp[(1) - (1)].symbol), current_class, (yylsp[(1) - (1)]), true);
        symbol_type_set ((yyvsp[(1) - (1)].symbol), current_type, (yylsp[(1) - (1)]));
@@ -2421,8 +2348,8 @@ yyreduce:
 
   case 70:
 
-/* Line 1535 of yacc.c  */
-#line 461 "parse-gram.y"
+/* Line 1537 of yacc.c  */
+#line 445 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
       symbol_type_set ((yyvsp[(1) - (2)].symbol), current_type, (yylsp[(1) - (2)]));
@@ -2432,8 +2359,8 @@ yyreduce:
 
   case 71:
 
-/* Line 1535 of yacc.c  */
-#line 467 "parse-gram.y"
+/* Line 1537 of yacc.c  */
+#line 451 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
       symbol_type_set ((yyvsp[(1) - (2)].symbol), current_type, (yylsp[(1) - (2)]));
@@ -2443,8 +2370,8 @@ yyreduce:
 
   case 72:
 
-/* Line 1535 of yacc.c  */
-#line 473 "parse-gram.y"
+/* Line 1537 of yacc.c  */
+#line 457 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (3)].symbol), current_class, (yylsp[(1) - (3)]), true);
       symbol_type_set ((yyvsp[(1) - (3)].symbol), current_type, (yylsp[(1) - (3)]));
@@ -2455,8 +2382,8 @@ yyreduce:
 
   case 79:
 
-/* Line 1535 of yacc.c  */
-#line 503 "parse-gram.y"
+/* Line 1537 of yacc.c  */
+#line 487 "parse-gram.y"
     {
       yyerrok;
     }
@@ -2464,78 +2391,78 @@ yyreduce:
 
   case 80:
 
-/* Line 1535 of yacc.c  */
-#line 509 "parse-gram.y"
+/* Line 1537 of yacc.c  */
+#line 493 "parse-gram.y"
     { current_lhs = (yyvsp[(1) - (1)].symbol); current_lhs_location = (yylsp[(1) - (1)]); }
     break;
 
   case 82:
 
-/* Line 1535 of yacc.c  */
-#line 513 "parse-gram.y"
+/* Line 1537 of yacc.c  */
+#line 497 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(1) - (1)])); }
     break;
 
   case 83:
 
-/* Line 1535 of yacc.c  */
-#line 514 "parse-gram.y"
+/* Line 1537 of yacc.c  */
+#line 498 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(3) - (3)])); }
     break;
 
   case 85:
 
-/* Line 1535 of yacc.c  */
-#line 520 "parse-gram.y"
+/* Line 1537 of yacc.c  */
+#line 504 "parse-gram.y"
     { grammar_current_rule_begin (current_lhs, current_lhs_location); }
     break;
 
   case 86:
 
-/* Line 1535 of yacc.c  */
-#line 522 "parse-gram.y"
+/* Line 1537 of yacc.c  */
+#line 506 "parse-gram.y"
     { grammar_current_rule_symbol_append ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)])); }
     break;
 
   case 87:
 
-/* Line 1535 of yacc.c  */
-#line 524 "parse-gram.y"
+/* Line 1537 of yacc.c  */
+#line 508 "parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
     break;
 
   case 88:
 
-/* Line 1535 of yacc.c  */
-#line 526 "parse-gram.y"
+/* Line 1537 of yacc.c  */
+#line 510 "parse-gram.y"
     { grammar_current_rule_prec_set ((yyvsp[(3) - (3)].symbol), (yylsp[(3) - (3)])); }
     break;
 
   case 89:
 
-/* Line 1535 of yacc.c  */
-#line 528 "parse-gram.y"
+/* Line 1537 of yacc.c  */
+#line 512 "parse-gram.y"
     { grammar_current_rule_dprec_set ((yyvsp[(3) - (3)].integer), (yylsp[(3) - (3)])); }
     break;
 
   case 90:
 
-/* Line 1535 of yacc.c  */
-#line 530 "parse-gram.y"
+/* Line 1537 of yacc.c  */
+#line 514 "parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[(3) - (3)].uniqstr), (yylsp[(3) - (3)])); }
     break;
 
   case 92:
 
-/* Line 1535 of yacc.c  */
-#line 540 "parse-gram.y"
+/* Line 1537 of yacc.c  */
+#line 524 "parse-gram.y"
     { (yyval.uniqstr) = uniqstr_new ((yyvsp[(1) - (1)].chars)); }
     break;
 
   case 93:
 
-/* Line 1535 of yacc.c  */
-#line 546 "parse-gram.y"
+/* Line 1537 of yacc.c  */
+#line 530 "parse-gram.y"
     {
       static char one[] = "1";
       (yyval.chars) = one;
@@ -2544,8 +2471,8 @@ yyreduce:
 
   case 95:
 
-/* Line 1535 of yacc.c  */
-#line 560 "parse-gram.y"
+/* Line 1537 of yacc.c  */
+#line 544 "parse-gram.y"
     {
       code_props plain_code;
       (yyvsp[(1) - (1)].code)[strlen ((yyvsp[(1) - (1)].code)) - 1] = '\n';
@@ -2558,15 +2485,15 @@ yyreduce:
 
   case 96:
 
-/* Line 1535 of yacc.c  */
-#line 580 "parse-gram.y"
+/* Line 1537 of yacc.c  */
+#line 564 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 97:
 
-/* Line 1535 of yacc.c  */
-#line 582 "parse-gram.y"
+/* Line 1537 of yacc.c  */
+#line 566 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[(1) - (1)].character)), (yylsp[(1) - (1)]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[(1) - (1)]), false);
@@ -2576,15 +2503,15 @@ yyreduce:
 
   case 98:
 
-/* Line 1535 of yacc.c  */
-#line 590 "parse-gram.y"
+/* Line 1537 of yacc.c  */
+#line 574 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 101:
 
-/* Line 1535 of yacc.c  */
-#line 602 "parse-gram.y"
+/* Line 1537 of yacc.c  */
+#line 586 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[(1) - (1)].chars)), (yylsp[(1) - (1)]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[(1) - (1)]), false);
@@ -2593,8 +2520,8 @@ yyreduce:
 
   case 103:
 
-/* Line 1535 of yacc.c  */
-#line 611 "parse-gram.y"
+/* Line 1537 of yacc.c  */
+#line 595 "parse-gram.y"
     {
       code_props plain_code;
       code_props_plain_init (&plain_code, (yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)]));
@@ -2607,8 +2534,8 @@ yyreduce:
 
 
 
-/* Line 1535 of yacc.c  */
-#line 2612 "parse-gram.c"
+/* Line 1537 of yacc.c  */
+#line 2539 "parse-gram.c"
       default: break;
     }
   YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);
@@ -2826,8 +2753,8 @@ yyreturn:
 
 
 
-/* Line 1535 of yacc.c  */
-#line 621 "parse-gram.y"
+/* Line 1537 of yacc.c  */
+#line 605 "parse-gram.y"
 
 
 
