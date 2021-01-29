@@ -131,36 +131,36 @@ int current_prec = 0;
      PERCENT_NTERM = 262,
      PERCENT_TYPE = 263,
      PERCENT_UNION = 264,
-     PERCENT_EXPECT = 265,
-     PERCENT_START = 266,
-     PERCENT_PREC = 267,
-     PERCENT_VERBOSE = 268,
-     PERCENT_ERROR_VERBOSE = 269,
-     PERCENT_OUTPUT = 270,
-     PERCENT_FILE_PREFIX = 271,
-     PERCENT_NAME_PREFIX = 272,
-     PERCENT_DEFINE = 273,
-     PERCENT_PURE_PARSER = 274,
-     PERCENT_DEFINES = 275,
-     PERCENT_YACC = 276,
-     PERCENT_DEBUG = 277,
-     PERCENT_LOCATIONS = 278,
-     PERCENT_NO_LINES = 279,
-     PERCENT_SKELETON = 280,
-     PERCENT_TOKEN_TABLE = 281,
-     TYPE = 282,
-     EQUAL = 283,
-     SEMICOLON = 284,
-     COLON = 285,
-     PIPE = 286,
-     ID = 287,
-     PERCENT_PERCENT = 288,
-     PROLOGUE = 289,
-     EPILOGUE = 290,
-     BRACED_CODE = 291,
-     PERCENT_LEFT = 292,
-     PERCENT_RIGHT = 293,
-     PERCENT_NONASSOC = 294
+     PERCENT_LEFT = 265,
+     PERCENT_RIGHT = 266,
+     PERCENT_NONASSOC = 267,
+     PERCENT_EXPECT = 268,
+     PERCENT_START = 269,
+     PERCENT_PREC = 270,
+     PERCENT_VERBOSE = 271,
+     PERCENT_ERROR_VERBOSE = 272,
+     PERCENT_OUTPUT = 273,
+     PERCENT_FILE_PREFIX = 274,
+     PERCENT_NAME_PREFIX = 275,
+     PERCENT_DEFINE = 276,
+     PERCENT_PURE_PARSER = 277,
+     PERCENT_DEFINES = 278,
+     PERCENT_YACC = 279,
+     PERCENT_DEBUG = 280,
+     PERCENT_LOCATIONS = 281,
+     PERCENT_NO_LINES = 282,
+     PERCENT_SKELETON = 283,
+     PERCENT_TOKEN_TABLE = 284,
+     TYPE = 285,
+     EQUAL = 286,
+     SEMICOLON = 287,
+     COLON = 288,
+     PIPE = 289,
+     ID = 290,
+     PERCENT_PERCENT = 291,
+     PROLOGUE = 292,
+     EPILOGUE = 293,
+     BRACED_CODE = 294
    };
 # endif
   /* POSIX requires `int' for tokens in interfaces.  */
@@ -174,36 +174,36 @@ int current_prec = 0;
 #define PERCENT_NTERM 262
 #define PERCENT_TYPE 263
 #define PERCENT_UNION 264
-#define PERCENT_EXPECT 265
-#define PERCENT_START 266
-#define PERCENT_PREC 267
-#define PERCENT_VERBOSE 268
-#define PERCENT_ERROR_VERBOSE 269
-#define PERCENT_OUTPUT 270
-#define PERCENT_FILE_PREFIX 271
-#define PERCENT_NAME_PREFIX 272
-#define PERCENT_DEFINE 273
-#define PERCENT_PURE_PARSER 274
-#define PERCENT_DEFINES 275
-#define PERCENT_YACC 276
-#define PERCENT_DEBUG 277
-#define PERCENT_LOCATIONS 278
-#define PERCENT_NO_LINES 279
-#define PERCENT_SKELETON 280
-#define PERCENT_TOKEN_TABLE 281
-#define TYPE 282
-#define EQUAL 283
-#define SEMICOLON 284
-#define COLON 285
-#define PIPE 286
-#define ID 287
-#define PERCENT_PERCENT 288
-#define PROLOGUE 289
-#define EPILOGUE 290
-#define BRACED_CODE 291
-#define PERCENT_LEFT 292
-#define PERCENT_RIGHT 293
-#define PERCENT_NONASSOC 294
+#define PERCENT_LEFT 265
+#define PERCENT_RIGHT 266
+#define PERCENT_NONASSOC 267
+#define PERCENT_EXPECT 268
+#define PERCENT_START 269
+#define PERCENT_PREC 270
+#define PERCENT_VERBOSE 271
+#define PERCENT_ERROR_VERBOSE 272
+#define PERCENT_OUTPUT 273
+#define PERCENT_FILE_PREFIX 274
+#define PERCENT_NAME_PREFIX 275
+#define PERCENT_DEFINE 276
+#define PERCENT_PURE_PARSER 277
+#define PERCENT_DEFINES 278
+#define PERCENT_YACC 279
+#define PERCENT_DEBUG 280
+#define PERCENT_LOCATIONS 281
+#define PERCENT_NO_LINES 282
+#define PERCENT_SKELETON 283
+#define PERCENT_TOKEN_TABLE 284
+#define TYPE 285
+#define EQUAL 286
+#define SEMICOLON 287
+#define COLON 288
+#define PIPE 289
+#define ID 290
+#define PERCENT_PERCENT 291
+#define PROLOGUE 292
+#define EPILOGUE 293
+#define BRACED_CODE 294
 
 
 
@@ -353,7 +353,7 @@ union yyalloc
 /* YYFINAL -- State number of the termination state. */
 #define YYFINAL  3
 #define YYFLAG	 -32768
-#define YYLAST   90
+#define YYLAST   102
 
 /* YYNTOKENS -- Number of terminals. */
 #define YYNTOKENS  40
@@ -424,37 +424,37 @@ static const unsigned char yyprhs[] =
 /* YYRHS -- A `-1'-separated list of the rules' RHS. */
 static const signed char yyrhs[] =
 {
-      41,     0,    -1,    42,    33,    57,    67,    -1,    -1,    42,
-      43,    68,    -1,    44,    -1,    34,    -1,    22,    -1,    18,
-      66,    66,    -1,    20,    -1,    14,    -1,    10,     5,    -1,
-      16,    28,    66,    -1,    23,    -1,    17,    28,    66,    -1,
-      24,    -1,    15,    28,    66,    -1,    19,    -1,    25,    66,
-      -1,    26,    -1,    13,    -1,    21,    -1,    49,    -1,    45,
-      -1,    11,    63,    -1,     9,    36,    -1,    -1,     7,    46,
-      56,    -1,    -1,     6,    47,    56,    -1,    -1,     8,    27,
-      48,    53,    -1,    -1,    51,    52,    50,    54,    -1,    37,
-      -1,    38,    -1,    39,    -1,    -1,    27,    -1,    32,    -1,
-      53,    32,    -1,    63,    -1,    54,    63,    -1,    27,    -1,
-      32,    -1,    32,     5,    -1,    32,    65,    -1,    32,     5,
+      41,     0,    -1,    42,    36,    57,    67,    -1,    -1,    42,
+      43,    68,    -1,    44,    -1,    37,    -1,    25,    -1,    21,
+      66,    66,    -1,    23,    -1,    17,    -1,    13,     5,    -1,
+      19,    31,    66,    -1,    26,    -1,    20,    31,    66,    -1,
+      27,    -1,    18,    31,    66,    -1,    22,    -1,    28,    66,
+      -1,    29,    -1,    16,    -1,    24,    -1,    49,    -1,    45,
+      -1,    14,    63,    -1,     9,    39,    -1,    -1,     7,    46,
+      56,    -1,    -1,     6,    47,    56,    -1,    -1,     8,    30,
+      48,    53,    -1,    -1,    51,    52,    50,    54,    -1,    10,
+      -1,    11,    -1,    12,    -1,    -1,    30,    -1,    35,    -1,
+      53,    35,    -1,    63,    -1,    54,    63,    -1,    30,    -1,
+      35,    -1,    35,     5,    -1,    35,    65,    -1,    35,     5,
       65,    -1,    55,    -1,    56,    55,    -1,    58,    -1,    57,
-      58,    -1,    59,    -1,    44,    29,    -1,    -1,    32,    30,
-      60,    61,    29,    -1,    62,    -1,    61,    31,    62,    -1,
-      -1,    62,    63,    -1,    62,    64,    -1,    62,    12,    63,
-      -1,    32,    -1,    65,    -1,     4,    -1,    36,    -1,     3,
-      -1,     3,    -1,    -1,    33,    35,    -1,    -1,    29,    -1
+      58,    -1,    59,    -1,    44,    32,    -1,    -1,    35,    33,
+      60,    61,    32,    -1,    62,    -1,    61,    34,    62,    -1,
+      -1,    62,    63,    -1,    62,    64,    -1,    62,    15,    63,
+      -1,    35,    -1,    65,    -1,     4,    -1,    39,    -1,     3,
+      -1,     3,    -1,    -1,    36,    38,    -1,    -1,    32,    -1
 };
 
 /* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
 static const unsigned short yyrline[] =
 {
-       0,   146,   146,   159,   161,   164,   166,   167,   168,   169,
-     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
-     180,   181,   184,   186,   187,   191,   199,   199,   205,   205,
-     210,   210,   216,   216,   226,   228,   229,   232,   234,   238,
-     240,   244,   250,   258,   263,   268,   274,   280,   290,   293,
-     302,   304,   310,   312,   315,   315,   320,   322,   325,   328,
-     330,   332,   336,   338,   339,   342,   348,   357,   365,   370,
-     376,   378
+       0,   150,   150,   163,   165,   168,   170,   171,   172,   173,
+     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
+     184,   185,   188,   190,   191,   195,   203,   203,   209,   209,
+     214,   214,   220,   220,   227,   229,   230,   233,   235,   239,
+     241,   245,   251,   259,   264,   269,   275,   281,   291,   294,
+     303,   305,   311,   313,   316,   316,   321,   323,   326,   329,
+     331,   333,   337,   339,   340,   343,   349,   358,   366,   371,
+     377,   379
 };
 #endif
 
@@ -464,14 +464,14 @@ static const unsigned short yyrline[] =
 static const char *const yytname[] =
 {
   "\"end of string\"", "error", "$undefined.", "STRING", "CHARACTER", "INT", 
-  "\"%token\"", "\"%nterm\"", "\"%type\"", "\"%union\"", "\"%expect\"", 
-  "\"%start\"", "\"%prec\"", "\"%verbose\"", "\"%error-verbose\"", 
-  "\"%output\"", "\"%file-prefix\"", "\"%name-prefix\"", "\"%define\"", 
-  "\"%pure-parser\"", "\"%defines\"", "\"%yacc\"", "\"%debug\"", 
-  "\"%locations\"", "\"%no-lines\"", "\"%skeleton\"", "\"%token-table\"", 
-  "TYPE", "\"=\"", "\";\"", "\":\"", "\"|\"", "\"identifier\"", "\"%%\"", 
-  "PROLOGUE", "EPILOGUE", "BRACED_CODE", "\"%left\"", "\"%right\"", 
-  "\"%nonassoc\"", "$axiom", "input", "declarations", "declaration", 
+  "\"%token\"", "\"%nterm\"", "\"%type\"", "\"%union\"", "\"%left\"", 
+  "\"%right\"", "\"%nonassoc\"", "\"%expect\"", "\"%start\"", "\"%prec\"", 
+  "\"%verbose\"", "\"%error-verbose\"", "\"%output\"", "\"%file-prefix\"", 
+  "\"%name-prefix\"", "\"%define\"", "\"%pure-parser\"", "\"%defines\"", 
+  "\"%yacc\"", "\"%debug\"", "\"%locations\"", "\"%no-lines\"", 
+  "\"%skeleton\"", "\"%token-table\"", "TYPE", "\"=\"", "\";\"", "\":\"", 
+  "\"|\"", "\"identifier\"", "\"%%\"", "PROLOGUE", "EPILOGUE", 
+  "BRACED_CODE", "$axiom", "input", "declarations", "declaration", 
   "grammar_declaration", "symbol_declaration", "@1", "@2", "@3", 
   "precedence_declaration", "@4", "precedence_declarator", "type.opt", 
   "nterms_to_type.1", "terms_to_prec.1", "symbol_def", "symbol_defs.1", 
@@ -523,9 +523,9 @@ static const unsigned char yyr2[] =
    means the default is an error.  */
 static const short yydefact[] =
 {
-       3,     0,     0,     0,    28,    26,     0,     0,     0,     0,
-      20,    10,     0,     0,     0,     0,    17,     9,    21,     7,
-      13,    15,     0,    19,     0,     6,    34,    35,    36,    70,
+       3,     0,     0,     0,    28,    26,     0,     0,    34,    35,
+      36,     0,     0,    20,    10,     0,     0,     0,     0,    17,
+       9,    21,     7,    13,    15,     0,    19,     0,     6,    70,
        5,    23,    22,    37,     0,     0,    30,    25,    11,    66,
       64,    62,    24,    63,     0,     0,     0,    67,     0,    18,
        0,     0,    68,    50,    52,    71,     4,    38,    32,    43,
@@ -547,24 +547,24 @@ static const short yydefgoto[] =
    STATE-NUM.  */
 static const short yypact[] =
 {
-  -32768,     7,    -5,-32768,-32768,-32768,    -1,    11,    46,    38,
-  -32768,-32768,    36,    43,    44,    66,-32768,-32768,-32768,-32768,
-  -32768,-32768,    66,-32768,    29,-32768,-32768,-32768,-32768,    48,
-  -32768,-32768,-32768,    52,    18,    18,-32768,-32768,-32768,-32768,
-  -32768,-32768,-32768,-32768,    66,    66,    66,-32768,    66,-32768,
-      50,    54,    16,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-      41,-32768,    18,    18,    49,-32768,-32768,-32768,-32768,-32768,
-  -32768,    51,-32768,-32768,    38,    81,-32768,-32768,-32768,    53,
-  -32768,-32768,    38,-32768,-32768,-32768,    31,    27,-32768,-32768,
-  -32768,    38,-32768,-32768,-32768,    27,-32768
+  -32768,     9,    32,-32768,-32768,-32768,   -13,    -9,-32768,-32768,
+  -32768,    27,     0,-32768,-32768,     3,     5,    33,    60,-32768,
+  -32768,-32768,-32768,-32768,-32768,    60,-32768,    12,-32768,    34,
+  -32768,-32768,-32768,    35,   -24,   -24,-32768,-32768,-32768,-32768,
+  -32768,-32768,-32768,-32768,    60,    60,    60,-32768,    60,-32768,
+      38,    49,    66,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
+       2,-32768,   -24,   -24,    47,-32768,-32768,-32768,-32768,-32768,
+  -32768,    29,-32768,-32768,     0,    80,-32768,-32768,-32768,    50,
+  -32768,-32768,     0,-32768,-32768,-32768,   -20,    -2,-32768,-32768,
+  -32768,     0,-32768,-32768,-32768,    -2,-32768
 };
 
 /* YYPGOTO[NTERM-NUM].  */
 static const short yypgoto[] =
 {
-  -32768,-32768,-32768,-32768,    85,-32768,-32768,-32768,-32768,-32768,
-  -32768,-32768,-32768,-32768,-32768,    -6,    55,-32768,    37,-32768,
-  -32768,-32768,    -2,    -9,-32768,   -17,    30,-32768,-32768
+  -32768,-32768,-32768,-32768,    82,-32768,-32768,-32768,-32768,-32768,
+  -32768,-32768,-32768,-32768,-32768,   -47,    51,-32768,    36,-32768,
+  -32768,-32768,    -3,   -12,-32768,   -50,   -17,-32768,-32768
 };
 
 /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
@@ -572,30 +572,32 @@ static const short yypgoto[] =
    number is the opposite.  If zero, do what YYDEFACT says.  */
 static const short yytable[] =
 {
-      42,     4,     5,     6,     7,     8,     9,     3,    10,    11,
-      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
-      22,    23,     4,     5,     6,     7,    36,     9,    24,    25,
-      39,    40,    26,    27,    28,     4,     5,     6,     7,    91,
-       9,    39,    40,    76,    39,    59,    75,    37,    50,    71,
-      60,    38,    49,    26,    27,    28,    77,    77,    84,    41,
-      89,    50,    90,    92,    44,    83,    26,    27,    28,    47,
-      41,    45,    46,    88,    65,    66,    67,    55,    68,    57,
-      69,    78,    96,    70,    39,    85,    81,    30,    95,    72,
-      63
+      42,    39,    40,    39,    40,    39,    59,    75,    49,     3,
+      76,    60,    89,    91,    90,    77,    77,    36,     4,     5,
+       6,     7,     8,     9,    10,    84,    12,    65,    66,    67,
+      37,    68,    38,    41,    44,    41,    45,    92,     4,     5,
+       6,     7,     8,     9,    10,    11,    12,    50,    13,    14,
+      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
+      25,    26,    83,    47,    46,    57,    55,    81,    27,    28,
+      88,    69,     4,     5,     6,     7,     8,     9,    10,    96,
+      12,    70,    78,    39,    30,    85,    63,    95,    72,     0,
+       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
+       0,    50,    71
 };
 
 static const short yycheck[] =
 {
-       9,     6,     7,     8,     9,    10,    11,     0,    13,    14,
-      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
-      25,    26,     6,     7,     8,     9,    27,    11,    33,    34,
-       3,     4,    37,    38,    39,     6,     7,     8,     9,    12,
-      11,     3,     4,    60,     3,    27,     5,    36,    32,    33,
-      32,     5,    22,    37,    38,    39,    62,    63,    75,    32,
-      29,    32,    31,    36,    28,    74,    37,    38,    39,     3,
-      32,    28,    28,    82,    44,    45,    46,    29,    48,    27,
-      30,    32,    91,    29,     3,    32,    35,     2,    90,    52,
-      35
+      12,     3,     4,     3,     4,     3,    30,     5,    25,     0,
+      60,    35,    32,    15,    34,    62,    63,    30,     6,     7,
+       8,     9,    10,    11,    12,    75,    14,    44,    45,    46,
+      39,    48,     5,    35,    31,    35,    31,    39,     6,     7,
+       8,     9,    10,    11,    12,    13,    14,    35,    16,    17,
+      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
+      28,    29,    74,     3,    31,    30,    32,    38,    36,    37,
+      82,    33,     6,     7,     8,     9,    10,    11,    12,    91,
+      14,    32,    35,     3,     2,    35,    35,    90,    52,    -1,
+      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
+      -1,    35,    36
 };
 
 #if YYDEBUG
@@ -604,15 +606,15 @@ static const short yycheck[] =
 static const unsigned char yystos[] =
 {
        0,    41,    42,     0,     6,     7,     8,     9,    10,    11,
-      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
-      23,    24,    25,    26,    33,    34,    37,    38,    39,    43,
-      44,    45,    49,    51,    47,    46,    27,    36,     5,     3,
-       4,    32,    63,    65,    28,    28,    28,     3,    66,    66,
-      32,    44,    57,    58,    59,    29,    68,    27,    52,    27,
-      32,    55,    56,    56,    48,    66,    66,    66,    66,    30,
-      29,    33,    58,    67,    50,     5,    65,    55,    32,    53,
-      60,    35,    54,    63,    65,    32,    61,    62,    63,    29,
-      31,    12,    36,    63,    64,    62,    63
+      12,    13,    14,    16,    17,    18,    19,    20,    21,    22,
+      23,    24,    25,    26,    27,    28,    29,    36,    37,    43,
+      44,    45,    49,    51,    47,    46,    30,    39,     5,     3,
+       4,    35,    63,    65,    31,    31,    31,     3,    66,    66,
+      35,    44,    57,    58,    59,    32,    68,    30,    52,    30,
+      35,    55,    56,    56,    48,    66,    66,    66,    66,    33,
+      32,    36,    58,    67,    50,     5,    65,    55,    35,    53,
+      60,    38,    54,    63,    65,    35,    61,    62,    63,    32,
+      34,    15,    39,    63,    64,    62,    63
 };
 #endif
 
@@ -1182,7 +1184,7 @@ yyreduce:
   switch (yyn)
     {
         case 2:
-#line 148 "parse-gram.y"
+#line 152 "parse-gram.y"
     {
       yycontrol->errcode = 0;
       epilogue_set (yyvsp[0].string, yylsp[0]);
@@ -1190,94 +1192,94 @@ yyreduce:
     break;
 
   case 6:
-#line 166 "parse-gram.y"
+#line 170 "parse-gram.y"
     { prologue_augment (yyvsp[0].string, yylsp[0]); }
     break;
 
   case 7:
-#line 167 "parse-gram.y"
+#line 171 "parse-gram.y"
     { debug_flag = 1; }
     break;
 
   case 8:
-#line 168 "parse-gram.y"
+#line 172 "parse-gram.y"
     { muscle_insert (yyvsp[-1].string, yyvsp[0].string); }
     break;
 
   case 9:
-#line 169 "parse-gram.y"
+#line 173 "parse-gram.y"
     { defines_flag = 1; }
     break;
 
   case 10:
-#line 170 "parse-gram.y"
+#line 174 "parse-gram.y"
     { error_verbose = 1; }
     break;
 
   case 11:
-#line 171 "parse-gram.y"
+#line 175 "parse-gram.y"
     { expected_conflicts = yyvsp[0].integer; }
     break;
 
   case 12:
-#line 172 "parse-gram.y"
+#line 176 "parse-gram.y"
     { spec_file_prefix = yyvsp[0].string; }
     break;
 
   case 13:
-#line 173 "parse-gram.y"
+#line 177 "parse-gram.y"
     { locations_flag = 1; }
     break;
 
   case 14:
-#line 174 "parse-gram.y"
+#line 178 "parse-gram.y"
     { spec_name_prefix = yyvsp[0].string; }
     break;
 
   case 15:
-#line 175 "parse-gram.y"
+#line 179 "parse-gram.y"
     { no_lines_flag = 1; }
     break;
 
   case 16:
-#line 176 "parse-gram.y"
+#line 180 "parse-gram.y"
     { spec_outfile = yyvsp[0].string; }
     break;
 
   case 17:
-#line 177 "parse-gram.y"
+#line 181 "parse-gram.y"
     { pure_parser = 1; }
     break;
 
   case 18:
-#line 178 "parse-gram.y"
+#line 182 "parse-gram.y"
     { skeleton = yyvsp[0].string; }
     break;
 
   case 19:
-#line 179 "parse-gram.y"
+#line 183 "parse-gram.y"
     { token_table_flag = 1; }
     break;
 
   case 20:
-#line 180 "parse-gram.y"
+#line 184 "parse-gram.y"
     { report_flag = 1; }
     break;
 
   case 21:
-#line 181 "parse-gram.y"
+#line 185 "parse-gram.y"
     { yacc_flag = 1; }
     break;
 
   case 24:
-#line 188 "parse-gram.y"
+#line 192 "parse-gram.y"
     {
       grammar_start_symbol_set (yyvsp[0].symbol, yylsp[0]);
     }
     break;
 
   case 25:
-#line 192 "parse-gram.y"
+#line 196 "parse-gram.y"
     {
       typed = 1;
       MUSCLE_INSERT_INT ("stype_line", yylsp[0].first_line);
@@ -1286,12 +1288,12 @@ yyreduce:
     break;
 
   case 26:
-#line 200 "parse-gram.y"
+#line 204 "parse-gram.y"
     { current_class = nterm_sym; }
     break;
 
   case 27:
-#line 201 "parse-gram.y"
+#line 205 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
@@ -1299,12 +1301,12 @@ yyreduce:
     break;
 
   case 28:
-#line 205 "parse-gram.y"
+#line 209 "parse-gram.y"
     { current_class = token_sym; }
     break;
 
   case 29:
-#line 206 "parse-gram.y"
+#line 210 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
@@ -1312,64 +1314,64 @@ yyreduce:
     break;
 
   case 30:
-#line 210 "parse-gram.y"
+#line 214 "parse-gram.y"
     {current_type = yyvsp[0].string; }
     break;
 
   case 31:
-#line 211 "parse-gram.y"
+#line 215 "parse-gram.y"
     {
       current_type = NULL;
     }
     break;
 
   case 32:
-#line 218 "parse-gram.y"
+#line 222 "parse-gram.y"
     { current_assoc = yyvsp[-1].assoc; ++current_prec; }
     break;
 
   case 33:
-#line 220 "parse-gram.y"
+#line 224 "parse-gram.y"
     { current_assoc = non_assoc; current_type = NULL; }
     break;
 
   case 34:
-#line 227 "parse-gram.y"
+#line 228 "parse-gram.y"
     { yyval.assoc = left_assoc; }
     break;
 
   case 35:
-#line 228 "parse-gram.y"
+#line 229 "parse-gram.y"
     { yyval.assoc = right_assoc; }
     break;
 
   case 36:
-#line 229 "parse-gram.y"
+#line 230 "parse-gram.y"
     { yyval.assoc = non_assoc; }
     break;
 
   case 37:
-#line 233 "parse-gram.y"
+#line 234 "parse-gram.y"
     { current_type = NULL;}
     break;
 
   case 38:
-#line 234 "parse-gram.y"
+#line 235 "parse-gram.y"
     { current_type = yyvsp[0].string; }
     break;
 
   case 39:
-#line 239 "parse-gram.y"
+#line 240 "parse-gram.y"
     { symbol_type_set (yyvsp[0].symbol, current_type); }
     break;
 
   case 40:
-#line 240 "parse-gram.y"
+#line 241 "parse-gram.y"
     { symbol_type_set (yyvsp[0].symbol, current_type); }
     break;
 
   case 41:
-#line 246 "parse-gram.y"
+#line 247 "parse-gram.y"
     {
       symbol_type_set (yyvsp[0].symbol, current_type);
       symbol_precedence_set (yyvsp[0].symbol, current_prec, current_assoc);
@@ -1377,7 +1379,7 @@ yyreduce:
     break;
 
   case 42:
-#line 251 "parse-gram.y"
+#line 252 "parse-gram.y"
     {
       symbol_type_set (yyvsp[0].symbol, current_type);
       symbol_precedence_set (yyvsp[0].symbol, current_prec, current_assoc);
@@ -1385,14 +1387,14 @@ yyreduce:
     break;
 
   case 43:
-#line 260 "parse-gram.y"
+#line 261 "parse-gram.y"
     {
        current_type = yyvsp[0].string;
      }
     break;
 
   case 44:
-#line 264 "parse-gram.y"
+#line 265 "parse-gram.y"
     {
        symbol_class_set (yyvsp[0].symbol, current_class);
        symbol_type_set (yyvsp[0].symbol, current_type);
@@ -1400,7 +1402,7 @@ yyreduce:
     break;
 
   case 45:
-#line 269 "parse-gram.y"
+#line 270 "parse-gram.y"
     {
       symbol_class_set (yyvsp[-1].symbol, current_class);
       symbol_type_set (yyvsp[-1].symbol, current_type);
@@ -1409,7 +1411,7 @@ yyreduce:
     break;
 
   case 46:
-#line 275 "parse-gram.y"
+#line 276 "parse-gram.y"
     {
       symbol_class_set (yyvsp[-1].symbol, current_class);
       symbol_type_set (yyvsp[-1].symbol, current_type);
@@ -1418,7 +1420,7 @@ yyreduce:
     break;
 
   case 47:
-#line 281 "parse-gram.y"
+#line 282 "parse-gram.y"
     {
       symbol_class_set (yyvsp[-2].symbol, current_class);
       symbol_type_set (yyvsp[-2].symbol, current_type);
@@ -1428,77 +1430,77 @@ yyreduce:
     break;
 
   case 48:
-#line 292 "parse-gram.y"
+#line 293 "parse-gram.y"
     {;}
     break;
 
   case 49:
-#line 294 "parse-gram.y"
+#line 295 "parse-gram.y"
     {;}
     break;
 
   case 54:
-#line 316 "parse-gram.y"
+#line 317 "parse-gram.y"
     { current_lhs = yyvsp[-1].symbol; current_lhs_location = yylsp[-1]; }
     break;
 
   case 55:
-#line 317 "parse-gram.y"
+#line 318 "parse-gram.y"
     {;}
     break;
 
   case 56:
-#line 321 "parse-gram.y"
+#line 322 "parse-gram.y"
     { grammar_rule_end (yylsp[0]); }
     break;
 
   case 57:
-#line 322 "parse-gram.y"
+#line 323 "parse-gram.y"
     { grammar_rule_end (yylsp[0]); }
     break;
 
   case 58:
-#line 327 "parse-gram.y"
+#line 328 "parse-gram.y"
     { grammar_rule_begin (current_lhs, current_lhs_location); }
     break;
 
   case 59:
-#line 329 "parse-gram.y"
+#line 330 "parse-gram.y"
     { grammar_current_rule_symbol_append (yyvsp[0].symbol, yylsp[0]); }
     break;
 
   case 60:
-#line 331 "parse-gram.y"
+#line 332 "parse-gram.y"
     { grammar_current_rule_action_append (yyvsp[0].string, yylsp[0]); }
     break;
 
   case 61:
-#line 333 "parse-gram.y"
+#line 334 "parse-gram.y"
     { grammar_current_rule_prec_set (yyvsp[0].symbol); }
     break;
 
   case 62:
-#line 337 "parse-gram.y"
+#line 338 "parse-gram.y"
     { yyval.symbol = yyvsp[0].symbol; }
     break;
 
   case 63:
-#line 338 "parse-gram.y"
+#line 339 "parse-gram.y"
     { yyval.symbol = yyvsp[0].symbol; }
     break;
 
   case 64:
-#line 339 "parse-gram.y"
+#line 340 "parse-gram.y"
     { yyval.symbol = getsym (yyvsp[0].string, yylsp[0]); }
     break;
 
   case 65:
-#line 344 "parse-gram.y"
+#line 345 "parse-gram.y"
     { yyval.string = yyvsp[0].string; }
     break;
 
   case 66:
-#line 350 "parse-gram.y"
+#line 351 "parse-gram.y"
     {
       yyval.symbol = getsym (yyvsp[0].string, yylsp[0]);
       symbol_class_set (yyval.symbol, token_sym);
@@ -1506,7 +1508,7 @@ yyreduce:
     break;
 
   case 67:
-#line 359 "parse-gram.y"
+#line 360 "parse-gram.y"
     {
       yyval.string = yyvsp[0].string + 1;
       yyval.string[strlen (yyval.string) - 1] = '\0';
@@ -1514,14 +1516,14 @@ yyreduce:
     break;
 
   case 68:
-#line 367 "parse-gram.y"
+#line 368 "parse-gram.y"
     {
       yyval.string = xstrdup ("");
     }
     break;
 
   case 69:
-#line 371 "parse-gram.y"
+#line 372 "parse-gram.y"
     {
       yyval.string = yyvsp[0].string;
     }
@@ -1531,7 +1533,7 @@ yyreduce:
     }
 
 /* Line 1012 of /usr/local/share/bison/bison.simple.  */
-#line 1535 "parse-gram.c"
+#line 1537 "parse-gram.c"
 
   yyvsp -= yylen;
   yyssp -= yylen;
@@ -1752,7 +1754,7 @@ yyreturn:
   return yyresult;
 }
 
-#line 380 "parse-gram.y"
+#line 381 "parse-gram.y"
 
 /*------------------------------------------------------------------.
 | When debugging the parser, display tokens' locations and values.  |
