@@ -124,12 +124,12 @@ typedef struct yyltype
 
 
 
-#define	YYFINAL		94
+#define	YYFINAL		95
 #define	YYFLAG		-32768
 #define	YYNTBASE	41
 
 /* YYTRANSLATE(YYLEX) -- Bison token number corresponding to YYLEX. */
-#define YYTRANSLATE(x) ((unsigned)(x) <= 293 ? yytranslate[x] : 68)
+#define YYTRANSLATE(x) ((unsigned)(x) <= 293 ? yytranslate[x] : 69)
 
 /* YYTRANSLATE[YYLEX] -- Bison token number corresponding to YYLEX. */
 static const char yytranslate[] =
@@ -171,32 +171,32 @@ static const short yyprhs[] =
 {
        0,     0,     1,     7,     8,    11,    13,    15,    17,    21,
       23,    25,    28,    32,    34,    38,    40,    44,    46,    49,
-      51,    53,    55,    57,    58,    62,    65,    66,    70,    71,
-      76,    80,    81,    86,    88,    90,    92,    93,    95,    97,
-     100,   102,   105,   107,   109,   112,   115,   119,   121,   124,
-     126,   129,   130,   136,   138,   142,   143,   146,   149,   153,
-     155,   157,   159,   161,   163,   165,   166,   169,   170
+      51,    53,    55,    57,    59,    62,    66,    67,    71,    72,
+      76,    77,    82,    83,    88,    90,    92,    94,    95,    97,
+      99,   102,   104,   107,   109,   111,   114,   117,   121,   123,
+     126,   128,   131,   132,   138,   140,   144,   145,   148,   151,
+     155,   157,   159,   161,   163,   165,   167,   168,   171,   172
 };
 static const short yyrhs[] =
 {
-      -1,    42,    43,    37,    57,    66,     0,     0,    43,    44,
-       0,    45,     0,    38,     0,    26,     0,    22,    65,    65,
+      -1,    42,    43,    37,    58,    67,     0,     0,    43,    44,
+       0,    45,     0,    38,     0,    26,     0,    22,    66,    66,
        0,    24,     0,    18,     0,    11,     6,     0,    20,    32,
-      65,     0,    27,     0,    21,    32,    65,     0,    28,     0,
-      19,    32,    65,     0,    23,     0,    29,    65,     0,    30,
-       0,    17,     0,    25,     0,    49,     0,     0,     8,    46,
-      56,     0,    12,    62,     0,     0,     7,    47,    56,     0,
-       0,     9,    31,    48,    53,     0,    10,    40,    67,     0,
-       0,    51,    52,    50,    54,     0,    13,     0,    14,     0,
-      15,     0,     0,    31,     0,    36,     0,    53,    36,     0,
-      62,     0,    54,    62,     0,    31,     0,    36,     0,    36,
-       6,     0,    36,    64,     0,    36,     6,    64,     0,    55,
-       0,    56,    55,     0,    58,     0,    57,    58,     0,     0,
-      36,    34,    59,    60,    33,     0,    61,     0,    60,    35,
-      61,     0,     0,    61,    62,     0,    61,    63,     0,    61,
-      16,    62,     0,    36,     0,    64,     0,     5,     0,    40,
-       0,     4,     0,     4,     0,     0,    37,    39,     0,     0,
-      33,     0
+      66,     0,    27,     0,    21,    32,    66,     0,    28,     0,
+      19,    32,    66,     0,    23,     0,    29,    66,     0,    30,
+       0,    17,     0,    25,     0,    50,     0,    46,     0,    12,
+      63,     0,    10,    40,    68,     0,     0,     8,    47,    57,
+       0,     0,     7,    48,    57,     0,     0,     9,    31,    49,
+      54,     0,     0,    52,    53,    51,    55,     0,    13,     0,
+      14,     0,    15,     0,     0,    31,     0,    36,     0,    54,
+      36,     0,    63,     0,    55,    63,     0,    31,     0,    36,
+       0,    36,     6,     0,    36,    65,     0,    36,     6,    65,
+       0,    56,     0,    57,    56,     0,    59,     0,    58,    59,
+       0,     0,    36,    34,    60,    61,    33,     0,    62,     0,
+      61,    35,    62,     0,     0,    62,    63,     0,    62,    64,
+       0,    62,    16,    63,     0,    36,     0,    65,     0,     5,
+       0,    40,     0,     4,     0,     4,     0,     0,    37,    39,
+       0,     0,    33,     0
 };
 
 #endif
@@ -205,13 +205,13 @@ static const short yyrhs[] =
 /* YYRLINE[YYN] -- source line where rule number YYN was defined. */
 static const short yyrline[] =
 {
-       0,   132,   132,   140,   142,   145,   147,   151,   152,   153,
-     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
-     164,   165,   168,   170,   170,   175,   179,   179,   184,   184,
-     188,   196,   196,   203,   205,   206,   209,   211,   215,   217,
-     221,   227,   236,   241,   246,   252,   258,   268,   271,   275,
-     277,   280,   280,   285,   287,   290,   293,   295,   297,   301,
-     303,   304,   307,   313,   322,   330,   335,   341,   343
+       0,   134,   134,   147,   149,   152,   154,   155,   156,   157,
+     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
+     168,   169,   172,   174,   175,   179,   187,   187,   193,   193,
+     198,   198,   204,   204,   211,   213,   214,   217,   219,   223,
+     225,   229,   235,   243,   248,   253,   259,   265,   275,   278,
+     287,   289,   292,   292,   297,   299,   302,   305,   307,   309,
+     313,   315,   316,   319,   325,   334,   342,   347,   353,   355
 };
 #endif
 
@@ -229,12 +229,13 @@ static const char *const yytname[] =
   "\"%pure-parser\"", "\"%defines\"", "\"%yacc\"", "\"%debug\"", 
   "\"%locations\"", "\"%no-lines\"", "\"%skeleton\"", "\"%token-table\"", 
   "TYPE", "\"=\"", "\";\"", "\":\"", "\"|\"", "\"identifier\"", "\"%%\"", 
-  "PROLOGUE", "EPILOGUE", "BRACED_CODE", "input", "@1", "directives", 
-  "directive", "grammar_directives", "@2", "@3", "@4", 
-  "precedence_directives", "@5", "precedence_directive", "type.opt", 
-  "nterms_to_type.1", "terms_to_prec.1", "symbol_def", "symbol_defs.1", 
-  "gram", "rules", "@6", "rhses.1", "rhs", "symbol", "action", 
-  "string_as_id", "string_content", "epilogue.opt", "semi_colon_opt", 0
+  "PROLOGUE", "EPILOGUE", "BRACED_CODE", "input", "@1", "declarations", 
+  "declaration", "grammar_declaration", "symbol_declaration", "@2", "@3", 
+  "@4", "precedence_declaration", "@5", "precedence_declarator", 
+  "type.opt", "nterms_to_type.1", "terms_to_prec.1", "symbol_def", 
+  "symbol_defs.1", "grammar", "rules", "@6", "rhses.1", "rhs", "symbol", 
+  "action", "string_as_id", "string_content", "epilogue.opt", 
+  "semi_colon_opt", 0
 };
 #endif
 
@@ -243,11 +244,11 @@ static const short yyr1[] =
 {
        0,    42,    41,    43,    43,    44,    44,    44,    44,    44,
       44,    44,    44,    44,    44,    44,    44,    44,    44,    44,
-      44,    44,    45,    46,    45,    45,    47,    45,    48,    45,
-      45,    50,    49,    51,    51,    51,    52,    52,    53,    53,
-      54,    54,    55,    55,    55,    55,    55,    56,    56,    57,
-      57,    59,    58,    60,    60,    61,    61,    61,    61,    62,
-      62,    62,    63,    64,    65,    66,    66,    67,    67
+      44,    44,    45,    45,    45,    45,    47,    46,    48,    46,
+      49,    46,    51,    50,    52,    52,    52,    53,    53,    54,
+      54,    55,    55,    56,    56,    56,    56,    56,    57,    57,
+      58,    58,    60,    59,    61,    61,    62,    62,    62,    62,
+      63,    63,    63,    64,    65,    66,    67,    67,    68,    68
 };
 
 /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN. */
@@ -255,11 +256,11 @@ static const short yyr2[] =
 {
        0,     0,     5,     0,     2,     1,     1,     1,     3,     1,
        1,     2,     3,     1,     3,     1,     3,     1,     2,     1,
-       1,     1,     1,     0,     3,     2,     0,     3,     0,     4,
-       3,     0,     4,     1,     1,     1,     0,     1,     1,     2,
-       1,     2,     1,     1,     2,     2,     3,     1,     2,     1,
-       2,     0,     5,     1,     3,     0,     2,     2,     3,     1,
-       1,     1,     1,     1,     1,     0,     2,     0,     1
+       1,     1,     1,     1,     2,     3,     0,     3,     0,     3,
+       0,     4,     0,     4,     1,     1,     1,     0,     1,     1,
+       2,     1,     2,     1,     1,     2,     2,     3,     1,     2,
+       1,     2,     0,     5,     1,     3,     0,     2,     2,     3,
+       1,     1,     1,     1,     1,     1,     0,     2,     0,     1
 };
 
 /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
@@ -267,80 +268,72 @@ static const short yyr2[] =
    error. */
 static const short yydefact[] =
 {
-       1,     3,     0,    26,    23,     0,     0,     0,     0,    33,
-      34,    35,    20,    10,     0,     0,     0,     0,    17,     9,
+       1,     3,     0,    28,    26,     0,     0,     0,     0,    34,
+      35,    36,    20,    10,     0,     0,     0,     0,    17,     9,
       21,     7,    13,    15,     0,    19,     0,     6,     4,     5,
-      22,    36,     0,     0,    28,    67,    11,    63,    61,    59,
-      25,    60,     0,     0,     0,    64,     0,    18,     0,    65,
-      49,    37,    31,    42,    43,    47,    27,    24,     0,    68,
-      30,    16,    12,    14,     8,    51,     0,    50,     2,     0,
-      44,    45,    48,    38,    29,    55,    66,    32,    40,    46,
-      39,     0,    53,    41,    52,    55,     0,    62,    56,    57,
-      54,    58,     0,     0,     0
+      23,    22,    37,     0,     0,    30,    68,    11,    64,    62,
+      60,    24,    61,     0,     0,     0,    65,     0,    18,     0,
+      66,    50,    38,    32,    43,    44,    48,    29,    27,     0,
+      69,    25,    16,    12,    14,     8,    52,     0,    51,     2,
+       0,    45,    46,    49,    39,    31,    56,    67,    33,    41,
+      47,    40,     0,    54,    42,    53,    56,     0,    63,    57,
+      58,    55,    59,     0,     0,     0
 };
 
 static const short yydefgoto[] =
 {
-      92,     1,     2,    28,    29,    33,    32,    58,    30,    69,
-      31,    52,    74,    77,    55,    56,    49,    50,    75,    81,
-      82,    88,    89,    41,    46,    68,    60
+      93,     1,     2,    28,    29,    30,    34,    33,    59,    31,
+      70,    32,    53,    75,    78,    56,    57,    50,    51,    76,
+      82,    83,    89,    90,    42,    47,    69,    61
 };
 
 static const short yypact[] =
 {
-  -32768,-32768,    72,-32768,-32768,   -22,   -29,     8,    -1,-32768,
-  -32768,-32768,-32768,-32768,   -16,   -14,   -11,    22,-32768,-32768,
-  -32768,-32768,-32768,-32768,    22,-32768,    -6,-32768,-32768,-32768,
-  -32768,     0,   -24,   -24,-32768,     1,-32768,-32768,-32768,-32768,
-  -32768,-32768,    22,    22,    22,-32768,    22,-32768,    -2,   -17,
-  -32768,-32768,-32768,-32768,     4,-32768,   -24,   -24,     2,-32768,
-  -32768,-32768,-32768,-32768,-32768,-32768,     3,-32768,-32768,    -1,
-      32,-32768,-32768,-32768,     5,-32768,-32768,    -1,-32768,-32768,
-  -32768,   -18,    -3,-32768,-32768,-32768,    -1,-32768,-32768,-32768,
-      -3,-32768,    39,    40,-32768
+  -32768,-32768,    31,-32768,-32768,   -22,   -29,     8,    -1,-32768,
+  -32768,-32768,-32768,-32768,   -16,   -14,   -11,    19,-32768,-32768,
+  -32768,-32768,-32768,-32768,    19,-32768,    -9,-32768,-32768,-32768,
+  -32768,-32768,     0,   -24,   -24,-32768,     1,-32768,-32768,-32768,
+  -32768,-32768,-32768,    19,    19,    19,-32768,    19,-32768,    -2,
+     -17,-32768,-32768,-32768,-32768,     4,-32768,   -24,   -24,    11,
+  -32768,-32768,-32768,-32768,-32768,-32768,-32768,    24,-32768,-32768,
+      -1,    32,-32768,-32768,-32768,    28,-32768,-32768,    -1,-32768,
+  -32768,-32768,   -18,    -3,-32768,-32768,-32768,    -1,-32768,-32768,
+  -32768,    -3,-32768,    65,    66,-32768
 };
 
 static const short yypgoto[] =
 {
   -32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-  -32768,-32768,-32768,-32768,   -28,    10,-32768,    -5,-32768,-32768,
-     -40,    -8,-32768,   -48,   -19,-32768,-32768
+  -32768,-32768,-32768,-32768,-32768,   -28,    33,-32768,    21,-32768,
+  -32768,   -13,    -8,-32768,   -49,   -19,-32768,-32768
 };
 
 
-#define	YYLAST		110
+#define	YYLAST		79
 
 
 static const short yytable[] =
 {
-      40,    37,    38,    37,    38,    47,    71,    53,    37,    34,
-      70,    35,    54,    86,    36,    84,    42,    85,    43,    48,
-      66,    44,    79,    61,    62,    63,    45,    64,    72,    72,
-      48,    51,    65,    39,    59,    39,    37,    87,    73,    93,
-      94,    80,    76,    57,    67,    90,     0,     0,     0,     0,
-       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
-       0,    78,     0,     0,     0,     0,     0,     0,     0,    83,
-       0,     0,     0,     0,     0,     0,     0,     0,    91,     3,
-       4,     5,     6,     7,     8,     9,    10,    11,     0,    12,
-      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
-      23,    24,    25,     0,     0,     0,     0,     0,     0,    26,
-      27
+      41,    38,    39,    38,    39,    48,    72,    54,    38,    35,
+      71,    36,    55,    87,    37,    85,    43,    86,    44,    49,
+      67,    45,    80,    46,    62,    63,    64,    49,    65,    73,
+      73,    52,    66,    40,    60,    40,    38,    88,     3,     4,
+       5,     6,     7,     8,     9,    10,    11,    74,    12,    13,
+      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
+      24,    25,    79,    77,    81,    94,    95,    58,    26,    27,
+      84,    68,     0,    91,     0,     0,     0,     0,     0,    92
 };
 
 static const short yycheck[] =
 {
-       8,     4,     5,     4,     5,    24,    54,    31,     4,    31,
+       8,     4,     5,     4,     5,    24,    55,    31,     4,    31,
        6,    40,    36,    16,     6,    33,    32,    35,    32,    36,
-      37,    32,    70,    42,    43,    44,     4,    46,    56,    57,
-      36,    31,    34,    36,    33,    36,     4,    40,    36,     0,
-       0,    36,    39,    33,    49,    85,    -1,    -1,    -1,    -1,
-      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
-      -1,    69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,
-      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    86,     7,
-       8,     9,    10,    11,    12,    13,    14,    15,    -1,    17,
-      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
-      28,    29,    30,    -1,    -1,    -1,    -1,    -1,    -1,    37,
-      38
+      37,    32,    71,     4,    43,    44,    45,    36,    47,    57,
+      58,    31,    34,    36,    33,    36,     4,    40,     7,     8,
+       9,    10,    11,    12,    13,    14,    15,    36,    17,    18,
+      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
+      29,    30,    70,    39,    36,     0,     0,    34,    37,    38,
+      78,    50,    -1,    86,    -1,    -1,    -1,    -1,    -1,    87
 };
 #define YYPURE 1
 
@@ -1052,209 +1045,207 @@ yyreduce:
   switch (yyn) {
 
 case 1:
-#line 132 "parse-gram.y"
+#line 134 "parse-gram.y"
 { LOCATION_RESET (yylloc); }
     break;
 case 2:
-#line 134 "parse-gram.y"
+#line 136 "parse-gram.y"
 {
       yycontrol->errcode = 0;
       epilogue_set (yyvsp[0].string, yylsp[0]);
     }
     break;
 case 6:
-#line 148 "parse-gram.y"
-{
-     prologue_augment (yyvsp[0].string, yylsp[0]);
-   }
+#line 154 "parse-gram.y"
+{ prologue_augment (yyvsp[0].string, yylsp[0]); }
     break;
 case 7:
-#line 151 "parse-gram.y"
+#line 155 "parse-gram.y"
 { debug_flag = 1; }
     break;
 case 8:
-#line 152 "parse-gram.y"
+#line 156 "parse-gram.y"
 { muscle_insert (yyvsp[-1].string, yyvsp[0].string); }
     break;
 case 9:
-#line 153 "parse-gram.y"
+#line 157 "parse-gram.y"
 { defines_flag = 1; }
     break;
 case 10:
-#line 154 "parse-gram.y"
+#line 158 "parse-gram.y"
 { error_verbose = 1; }
     break;
 case 11:
-#line 155 "parse-gram.y"
+#line 159 "parse-gram.y"
 { expected_conflicts = yyvsp[0].integer; }
     break;
 case 12:
-#line 156 "parse-gram.y"
+#line 160 "parse-gram.y"
 { spec_file_prefix = yyvsp[0].string; }
     break;
 case 13:
-#line 157 "parse-gram.y"
+#line 161 "parse-gram.y"
 { locations_flag = 1; }
     break;
 case 14:
-#line 158 "parse-gram.y"
+#line 162 "parse-gram.y"
 { spec_name_prefix = yyvsp[0].string; }
     break;
 case 15:
-#line 159 "parse-gram.y"
+#line 163 "parse-gram.y"
 { no_lines_flag = 1; }
     break;
 case 16:
-#line 160 "parse-gram.y"
+#line 164 "parse-gram.y"
 { spec_outfile = yyvsp[0].string; }
     break;
 case 17:
-#line 161 "parse-gram.y"
+#line 165 "parse-gram.y"
 { pure_parser = 1; }
     break;
 case 18:
-#line 162 "parse-gram.y"
+#line 166 "parse-gram.y"
 { skeleton = yyvsp[0].string; }
     break;
 case 19:
-#line 163 "parse-gram.y"
+#line 167 "parse-gram.y"
 { token_table_flag = 1; }
     break;
 case 20:
-#line 164 "parse-gram.y"
+#line 168 "parse-gram.y"
 { report_flag = 1; }
     break;
 case 21:
-#line 165 "parse-gram.y"
+#line 169 "parse-gram.y"
 { yacc_flag = 1; }
     break;
-case 23:
-#line 170 "parse-gram.y"
-{ current_class = nterm_sym; }
-    break;
 case 24:
-#line 171 "parse-gram.y"
+#line 176 "parse-gram.y"
 {
-      current_class = unknown_sym;
-      current_type = NULL;
+      grammar_start_symbol_set (yyvsp[0].symbol);
     }
     break;
 case 25:
-#line 176 "parse-gram.y"
+#line 180 "parse-gram.y"
 {
-      grammar_start_symbol_set (yyvsp[0].symbol);
+      typed = 1;
+      MUSCLE_INSERT_INT ("stype_line", yylsp[-1].first_line);
+      muscle_insert ("stype", yyvsp[-1].string);
     }
     break;
 case 26:
-#line 179 "parse-gram.y"
-{ current_class = token_sym; }
+#line 188 "parse-gram.y"
+{ current_class = nterm_sym; }
     break;
 case 27:
-#line 180 "parse-gram.y"
+#line 189 "parse-gram.y"
 {
       current_class = unknown_sym;
       current_type = NULL;
     }
     break;
 case 28:
-#line 184 "parse-gram.y"
-{current_type = yyvsp[0].string; }
+#line 193 "parse-gram.y"
+{ current_class = token_sym; }
     break;
 case 29:
-#line 185 "parse-gram.y"
+#line 194 "parse-gram.y"
 {
+      current_class = unknown_sym;
       current_type = NULL;
     }
     break;
 case 30:
-#line 189 "parse-gram.y"
-{
-      typed = 1;
-      MUSCLE_INSERT_INT ("stype_line", yylsp[-1].first_line);
-      muscle_insert ("stype", yyvsp[-1].string);
-    }
+#line 198 "parse-gram.y"
+{current_type = yyvsp[0].string; }
     break;
 case 31:
-#line 198 "parse-gram.y"
-{ current_assoc = yyvsp[-1].assoc; ++current_prec; }
+#line 199 "parse-gram.y"
+{
+      current_type = NULL;
+    }
     break;
 case 32:
-#line 200 "parse-gram.y"
-{ current_assoc = non_assoc; current_type = NULL; }
+#line 206 "parse-gram.y"
+{ current_assoc = yyvsp[-1].assoc; ++current_prec; }
     break;
 case 33:
-#line 204 "parse-gram.y"
-{ yyval.assoc = left_assoc; }
+#line 208 "parse-gram.y"
+{ current_assoc = non_assoc; current_type = NULL; }
     break;
 case 34:
-#line 205 "parse-gram.y"
-{ yyval.assoc = right_assoc; }
+#line 212 "parse-gram.y"
+{ yyval.assoc = left_assoc; }
     break;
 case 35:
-#line 206 "parse-gram.y"
-{ yyval.assoc = non_assoc; }
+#line 213 "parse-gram.y"
+{ yyval.assoc = right_assoc; }
     break;
 case 36:
-#line 210 "parse-gram.y"
-{ current_type = NULL;}
+#line 214 "parse-gram.y"
+{ yyval.assoc = non_assoc; }
     break;
 case 37:
-#line 211 "parse-gram.y"
-{ current_type = yyvsp[0].string; }
+#line 218 "parse-gram.y"
+{ current_type = NULL;}
     break;
 case 38:
-#line 216 "parse-gram.y"
-{ symbol_type_set (yyvsp[0].symbol, current_type); }
+#line 219 "parse-gram.y"
+{ current_type = yyvsp[0].string; }
     break;
 case 39:
-#line 217 "parse-gram.y"
+#line 224 "parse-gram.y"
 { symbol_type_set (yyvsp[0].symbol, current_type); }
     break;
 case 40:
-#line 223 "parse-gram.y"
+#line 225 "parse-gram.y"
+{ symbol_type_set (yyvsp[0].symbol, current_type); }
+    break;
+case 41:
+#line 231 "parse-gram.y"
 {
       symbol_type_set (yyvsp[0].symbol, current_type);
       symbol_precedence_set (yyvsp[0].symbol, current_prec, current_assoc);
     }
     break;
-case 41:
-#line 228 "parse-gram.y"
+case 42:
+#line 236 "parse-gram.y"
 {
       symbol_type_set (yyvsp[0].symbol, current_type);
       symbol_precedence_set (yyvsp[0].symbol, current_prec, current_assoc);
     }
     break;
-case 42:
-#line 238 "parse-gram.y"
+case 43:
+#line 245 "parse-gram.y"
 {
        current_type = yyvsp[0].string;
      }
     break;
-case 43:
-#line 242 "parse-gram.y"
+case 44:
+#line 249 "parse-gram.y"
 {
        symbol_class_set (yyvsp[0].symbol, current_class);
        symbol_type_set (yyvsp[0].symbol, current_type);
      }
     break;
-case 44:
-#line 247 "parse-gram.y"
+case 45:
+#line 254 "parse-gram.y"
 {
       symbol_class_set (yyvsp[-1].symbol, current_class);
       symbol_type_set (yyvsp[-1].symbol, current_type);
       symbol_user_token_number_set (yyvsp[-1].symbol, yyvsp[0].integer);
     }
     break;
-case 45:
-#line 253 "parse-gram.y"
+case 46:
+#line 260 "parse-gram.y"
 {
       symbol_class_set (yyvsp[-1].symbol, current_class);
       symbol_type_set (yyvsp[-1].symbol, current_type);
       symbol_make_alias (yyvsp[-1].symbol, yyvsp[0].symbol);
     }
     break;
-case 46:
-#line 259 "parse-gram.y"
+case 47:
+#line 266 "parse-gram.y"
 {
       symbol_class_set (yyvsp[-2].symbol, current_class);
       symbol_type_set (yyvsp[-2].symbol, current_type);
@@ -1262,84 +1253,84 @@ case 46:
       symbol_make_alias (yyvsp[-2].symbol, yyvsp[0].symbol);
     }
     break;
-case 47:
-#line 270 "parse-gram.y"
-{;}
-    break;
 case 48:
-#line 272 "parse-gram.y"
+#line 277 "parse-gram.y"
 {;}
     break;
-case 51:
-#line 281 "parse-gram.y"
-{ current_lhs = yyvsp[-1].symbol; }
+case 49:
+#line 279 "parse-gram.y"
+{;}
     break;
 case 52:
-#line 282 "parse-gram.y"
-{;}
+#line 293 "parse-gram.y"
+{ current_lhs = yyvsp[-1].symbol; }
     break;
 case 53:
-#line 286 "parse-gram.y"
-{ grammar_rule_end (); }
+#line 294 "parse-gram.y"
+{;}
     break;
 case 54:
-#line 287 "parse-gram.y"
+#line 298 "parse-gram.y"
 { grammar_rule_end (); }
     break;
 case 55:
-#line 292 "parse-gram.y"
-{ grammar_rule_begin (current_lhs); }
+#line 299 "parse-gram.y"
+{ grammar_rule_end (); }
     break;
 case 56:
-#line 294 "parse-gram.y"
-{ grammar_current_rule_symbol_append (yyvsp[0].symbol); }
+#line 304 "parse-gram.y"
+{ grammar_rule_begin (current_lhs); }
     break;
 case 57:
-#line 296 "parse-gram.y"
-{ grammar_current_rule_action_append (yyvsp[0].string, yylsp[0].first_line); }
+#line 306 "parse-gram.y"
+{ grammar_current_rule_symbol_append (yyvsp[0].symbol); }
     break;
 case 58:
-#line 298 "parse-gram.y"
-{ grammar_current_rule_prec_set (yyvsp[0].symbol); }
+#line 308 "parse-gram.y"
+{ grammar_current_rule_action_append (yyvsp[0].string, yylsp[0].first_line); }
     break;
 case 59:
-#line 302 "parse-gram.y"
-{ yyval.symbol = yyvsp[0].symbol; }
+#line 310 "parse-gram.y"
+{ grammar_current_rule_prec_set (yyvsp[0].symbol); }
     break;
 case 60:
-#line 303 "parse-gram.y"
+#line 314 "parse-gram.y"
 { yyval.symbol = yyvsp[0].symbol; }
     break;
 case 61:
-#line 304 "parse-gram.y"
-{ yyval.symbol = getsym (yyvsp[0].string); }
+#line 315 "parse-gram.y"
+{ yyval.symbol = yyvsp[0].symbol; }
     break;
 case 62:
-#line 309 "parse-gram.y"
-{ yyval.string = yyvsp[0].string; }
+#line 316 "parse-gram.y"
+{ yyval.symbol = getsym (yyvsp[0].string); }
     break;
 case 63:
-#line 315 "parse-gram.y"
+#line 321 "parse-gram.y"
+{ yyval.string = yyvsp[0].string; }
+    break;
+case 64:
+#line 327 "parse-gram.y"
 {
       yyval.symbol = getsym (yyvsp[0].string);
       symbol_class_set (yyval.symbol, token_sym);
     }
     break;
-case 64:
-#line 324 "parse-gram.y"
+case 65:
+#line 336 "parse-gram.y"
 {
       yyval.string = yyvsp[0].string + 1;
       yyval.string[strlen (yyval.string) - 1] = '\0';
     }
     break;
-case 65:
-#line 332 "parse-gram.y"
+case 66:
+#line 344 "parse-gram.y"
 {
       yyval.string = xstrdup ("");
     }
     break;
-case 66:
-#line 336 "parse-gram.y"
+case 67:
+#line 348 "parse-gram.y"
 {
       yyval.string = yyvsp[0].string;
     }
@@ -1577,7 +1568,7 @@ yyreturn:
 #endif
   return yyresult;
 }
-#line 345 "parse-gram.y"
+#line 357 "parse-gram.y"
 
 /*------------------------------------------------------------------.
 | When debugging the parser, display tokens' locations and values.  |
