@@ -170,7 +170,7 @@
 
 
 /* Copy the first part of user declarations.  */
-#line 1 "parse-gram.y"
+#line 1 "../../src/parse-gram.y"
 /* Bison Grammar Parser                             -*- C -*-
 
    Copyright (C) 2002, 2003, 2004, 2005 Free Software Foundation, Inc.
@@ -248,7 +248,7 @@ static int current_prec = 0;
 #endif
 
 #if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
-#line 79 "parse-gram.y"
+#line 79 "../../src/parse-gram.y"
 typedef union YYSTYPE {
   symbol *symbol;
   symbol_list *list;
@@ -258,7 +258,7 @@ typedef union YYSTYPE {
   uniqstr uniqstr;
 } YYSTYPE;
 /* Line 196 of yacc.c.  */
-#line 262 "parse-gram.c"
+#line 262 "../../src/parse-gram.c"
 # define yystype YYSTYPE /* obsolescent; will be withdrawn */
 # define YYSTYPE_IS_DECLARED 1
 # define YYSTYPE_IS_TRIVIAL 1
@@ -282,7 +282,7 @@ typedef struct YYLTYPE
 
 
 /* Line 219 of yacc.c.  */
-#line 286 "parse-gram.c"
+#line 286 "../../src/parse-gram.c"
 
 #ifndef YYSIZE_T
 # if defined (__SIZE_TYPE__)
@@ -453,7 +453,7 @@ union yyalloc
 /* YYNNTS -- Number of nonterminals. */
 #define YYNNTS  25
 /* YYNRULES -- Number of rules. */
-#define YYNRULES  79
+#define YYNRULES  80
 /* YYNRULES -- Number of states. */
 #define YYNSTATES  108
 
@@ -505,14 +505,15 @@ static const unsigned char yytranslate[] =
    YYRHS.  */
 static const unsigned char yyprhs[] =
 {
-       0,     0,     3,     8,     9,    12,    14,    16,    18,    22,
-      24,    26,    29,    32,    36,    38,    40,    42,    44,    48,
-      50,    52,    56,    58,    60,    63,    65,    67,    69,    71,
-      73,    75,    78,    80,    83,    86,    88,    90,    91,    95,
-      96,   100,   104,   108,   110,   112,   114,   115,   117,   119,
-     122,   124,   126,   129,   132,   136,   138,   141,   143,   146,
-     148,   151,   154,   155,   159,   161,   165,   168,   169,   172,
-     175,   179,   183,   187,   189,   191,   193,   195,   197,   198
+       0,     0,     3,     8,     9,    12,    14,    16,    18,    21,
+      25,    27,    29,    32,    35,    39,    41,    43,    45,    47,
+      51,    53,    55,    59,    61,    63,    66,    68,    70,    72,
+      74,    76,    78,    81,    83,    86,    89,    91,    93,    94,
+      98,    99,   103,   107,   111,   113,   115,   117,   118,   120,
+     122,   125,   127,   129,   132,   135,   139,   141,   144,   146,
+     149,   151,   154,   157,   158,   162,   164,   168,   171,   172,
+     175,   178,   182,   186,   190,   192,   194,   196,   198,   200,
+     201
 };
 
 /* YYRHS -- A `-1'-separated list of the rules' RHS. */
@@ -520,38 +521,39 @@ static const yysigned_char yyrhs[] =
 {
       52,     0,    -1,    53,    47,    65,    75,    -1,    -1,    53,
       54,    -1,    55,    -1,    48,    -1,    17,    -1,    19,    74,
-      74,    -1,    20,    -1,    21,    -1,    22,     4,    -1,    23,
-       4,    -1,    24,    42,    74,    -1,    25,    -1,    26,    -1,
-      27,    -1,    28,    -1,    29,    42,    74,    -1,    31,    -1,
-      32,    -1,    33,    42,    74,    -1,    34,    -1,    35,    -1,
-      36,    74,    -1,    38,    -1,    39,    -1,    40,    -1,    43,
-      -1,    59,    -1,    56,    -1,    37,    71,    -1,    10,    -1,
-       8,    62,    -1,     9,    62,    -1,    18,    -1,    30,    -1,
-      -1,     6,    57,    64,    -1,    -1,     5,    58,    64,    -1,
-       7,    41,    62,    -1,    60,    61,    62,    -1,    11,    -1,
-      12,    -1,    13,    -1,    -1,    41,    -1,    71,    -1,    62,
-      71,    -1,    41,    -1,    45,    -1,    45,     4,    -1,    45,
-      73,    -1,    45,     4,    73,    -1,    63,    -1,    64,    63,
-      -1,    66,    -1,    65,    66,    -1,    67,    -1,    55,    43,
-      -1,     1,    43,    -1,    -1,    46,    68,    69,    -1,    70,
-      -1,    69,    44,    70,    -1,    69,    43,    -1,    -1,    70,
-      71,    -1,    70,    72,    -1,    70,    14,    71,    -1,    70,
-      15,     4,    -1,    70,    16,    41,    -1,    45,    -1,    73,
-      -1,    50,    -1,     3,    -1,     3,    -1,    -1,    47,    49,
-      -1
+      -1,    19,    74,    74,    -1,    20,    -1,    21,    -1,    22,
+       4,    -1,    23,     4,    -1,    24,    42,    74,    -1,    25,
+      -1,    26,    -1,    27,    -1,    28,    -1,    29,    42,    74,
+      -1,    31,    -1,    32,    -1,    33,    42,    74,    -1,    34,
+      -1,    35,    -1,    36,    74,    -1,    38,    -1,    39,    -1,
+      40,    -1,    43,    -1,    59,    -1,    56,    -1,    37,    71,
+      -1,    10,    -1,     8,    62,    -1,     9,    62,    -1,    18,
+      -1,    30,    -1,    -1,     6,    57,    64,    -1,    -1,     5,
+      58,    64,    -1,     7,    41,    62,    -1,    60,    61,    62,
+      -1,    11,    -1,    12,    -1,    13,    -1,    -1,    41,    -1,
+      71,    -1,    62,    71,    -1,    41,    -1,    45,    -1,    45,
+       4,    -1,    45,    73,    -1,    45,     4,    73,    -1,    63,
+      -1,    64,    63,    -1,    66,    -1,    65,    66,    -1,    67,
+      -1,    55,    43,    -1,     1,    43,    -1,    -1,    46,    68,
+      69,    -1,    70,    -1,    69,    44,    70,    -1,    69,    43,
+      -1,    -1,    70,    71,    -1,    70,    72,    -1,    70,    14,
+      71,    -1,    70,    15,     4,    -1,    70,    16,    41,    -1,
+      45,    -1,    73,    -1,    50,    -1,     3,    -1,     3,    -1,
+      -1,    47,    49,    -1
 };
 
 /* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
 static const unsigned short int yyrline[] =
 {
        0,   188,   188,   196,   198,   202,   203,   204,   205,   206,
-     207,   208,   209,   210,   211,   216,   220,   221,   222,   223,
-     224,   225,   226,   227,   228,   229,   230,   231,   232,   236,
-     237,   238,   242,   248,   255,   262,   266,   273,   273,   278,
-     278,   283,   293,   308,   309,   310,   314,   315,   321,   322,
-     327,   331,   336,   342,   348,   359,   360,   369,   370,   376,
-     377,   382,   389,   389,   393,   394,   395,   400,   401,   403,
-     405,   407,   409,   414,   415,   419,   425,   434,   439,   441
+     207,   208,   209,   210,   211,   212,   217,   221,   222,   223,
+     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
+     237,   238,   239,   243,   249,   256,   263,   267,   274,   274,
+     279,   279,   284,   294,   309,   310,   311,   315,   316,   322,
+     323,   328,   332,   337,   343,   349,   360,   361,   370,   371,
+     377,   378,   383,   390,   390,   394,   395,   396,   401,   402,
+     404,   406,   408,   410,   415,   416,   420,   426,   435,   440,
+     442
 };
 #endif
 
@@ -600,25 +602,27 @@ static const unsigned char yyr1[] =
 {
        0,    51,    52,    53,    53,    54,    54,    54,    54,    54,
       54,    54,    54,    54,    54,    54,    54,    54,    54,    54,
-      54,    54,    54,    54,    54,    54,    54,    54,    54,    55,
-      55,    55,    55,    55,    55,    55,    55,    57,    56,    58,
-      56,    56,    59,    60,    60,    60,    61,    61,    62,    62,
-      63,    63,    63,    63,    63,    64,    64,    65,    65,    66,
-      66,    66,    68,    67,    69,    69,    69,    70,    70,    70,
-      70,    70,    70,    71,    71,    72,    73,    74,    75,    75
+      54,    54,    54,    54,    54,    54,    54,    54,    54,    54,
+      55,    55,    55,    55,    55,    55,    55,    55,    57,    56,
+      58,    56,    56,    59,    60,    60,    60,    61,    61,    62,
+      62,    63,    63,    63,    63,    63,    64,    64,    65,    65,
+      66,    66,    66,    68,    67,    69,    69,    69,    70,    70,
+      70,    70,    70,    70,    71,    71,    72,    73,    74,    75,
+      75
 };
 
 /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
 static const unsigned char yyr2[] =
 {
-       0,     2,     4,     0,     2,     1,     1,     1,     3,     1,
-       1,     2,     2,     3,     1,     1,     1,     1,     3,     1,
-       1,     3,     1,     1,     2,     1,     1,     1,     1,     1,
-       1,     2,     1,     2,     2,     1,     1,     0,     3,     0,
-       3,     3,     3,     1,     1,     1,     0,     1,     1,     2,
-       1,     1,     2,     2,     3,     1,     2,     1,     2,     1,
-       2,     2,     0,     3,     1,     3,     2,     0,     2,     2,
-       3,     3,     3,     1,     1,     1,     1,     1,     0,     2
+       0,     2,     4,     0,     2,     1,     1,     1,     2,     3,
+       1,     1,     2,     2,     3,     1,     1,     1,     1,     3,
+       1,     1,     3,     1,     1,     2,     1,     1,     1,     1,
+       1,     1,     2,     1,     2,     2,     1,     1,     0,     3,
+       0,     3,     3,     3,     1,     1,     1,     0,     1,     1,
+       2,     1,     1,     2,     2,     3,     1,     2,     1,     2,
+       1,     2,     2,     0,     3,     1,     3,     2,     0,     2,
+       2,     3,     3,     3,     1,     1,     1,     1,     1,     0,
+       2
 };
 
 /* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
@@ -626,17 +630,17 @@ static const unsigned char yyr2[] =
    means the default is an error.  */
 static const unsigned char yydefact[] =
 {
-       3,     0,     0,     1,    39,    37,     0,     0,     0,    32,
-      43,    44,    45,     7,    35,     0,     9,    10,     0,     0,
-       0,    14,    15,    16,    17,     0,    36,    19,    20,     0,
-      22,    23,     0,     0,    25,    26,    27,    28,     0,     6,
-       4,     5,    30,    29,    46,     0,     0,     0,    76,    73,
-      33,    48,    74,    34,    77,     0,    11,    12,     0,     0,
-       0,    24,    31,     0,    62,     0,     0,    57,    59,    47,
-       0,    50,    51,    55,    40,    38,    41,    49,     8,    13,
-      18,    21,    61,    67,    60,     0,    58,     2,    42,    52,
-      53,    56,    63,    64,    79,    54,    66,    67,     0,     0,
-       0,    75,    68,    69,    65,    70,    71,    72
+       3,     0,     0,     1,    40,    38,     0,     0,     0,    33,
+      44,    45,    46,     7,    36,     0,    10,    11,     0,     0,
+       0,    15,    16,    17,    18,     0,    37,    20,    21,     0,
+      23,    24,     0,     0,    26,    27,    28,    29,     0,     6,
+       4,     5,    31,    30,    47,     0,     0,     0,    77,    74,
+      34,    49,    75,    35,    78,     8,    12,    13,     0,     0,
+       0,    25,    32,     0,    63,     0,     0,    58,    60,    48,
+       0,    51,    52,    56,    41,    39,    42,    50,     9,    14,
+      19,    22,    62,    68,    61,     0,    59,     2,    43,    53,
+      54,    57,    64,    65,    80,    55,    67,    68,     0,     0,
+       0,    76,    69,    70,    66,    71,    72,    73
 };
 
 /* YYDEFGOTO[NTERM-NUM]. */
@@ -677,12 +681,12 @@ static const yysigned_char yypgoto[] =
    positive, shift that token.  If negative, reduce the rule which
    number is the opposite.  If zero, do what YYDEFACT says.
    If YYTABLE_NINF, syntax error.  */
-#define YYTABLE_NINF -79
+#define YYTABLE_NINF -80
 static const yysigned_char yytable[] =
 {
       62,    53,    48,    48,    71,     3,    90,    47,    72,    48,
       89,    96,    97,    98,    99,   100,    54,    77,    91,    91,
-      77,   -78,    63,    95,    56,    58,     4,     5,     6,     7,
+      77,   -79,    63,    95,    56,    58,     4,     5,     6,     7,
        8,     9,    10,    11,    12,    57,    59,    60,    69,    14,
       76,    82,    48,    77,    49,    49,    84,   106,   107,   101,
       94,    26,    41,    86,    75,    77,   104,     0,    33,     0,
@@ -1181,94 +1185,94 @@ yysymprint (yyoutput, yytype, yyvaluep, yylocationp)
   switch (yytype)
     {
       case 3: /* "\"string\"" */
-#line 165 "parse-gram.y"
+#line 165 "../../src/parse-gram.y"
         { fprintf (stderr, "\"%s\"", (yyvaluep->chars)); };
-#line 1187 "parse-gram.c"
+#line 1191 "../../src/parse-gram.c"
         break;
       case 4: /* "\"integer\"" */
-#line 178 "parse-gram.y"
+#line 178 "../../src/parse-gram.y"
         { fprintf (stderr, "%d", (yyvaluep->integer)); };
-#line 1192 "parse-gram.c"
+#line 1196 "../../src/parse-gram.c"
         break;
       case 8: /* "\"%destructor {...}\"" */
-#line 167 "parse-gram.y"
+#line 167 "../../src/parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1197 "parse-gram.c"
+#line 1201 "../../src/parse-gram.c"
         break;
       case 9: /* "\"%printer {...}\"" */
-#line 171 "parse-gram.y"
+#line 171 "../../src/parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1202 "parse-gram.c"
+#line 1206 "../../src/parse-gram.c"
         break;
       case 10: /* "\"%union {...}\"" */
-#line 172 "parse-gram.y"
+#line 172 "../../src/parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1207 "parse-gram.c"
+#line 1211 "../../src/parse-gram.c"
         break;
       case 26: /* "\"%initial-action {...}\"" */
-#line 168 "parse-gram.y"
+#line 168 "../../src/parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1212 "parse-gram.c"
+#line 1216 "../../src/parse-gram.c"
         break;
       case 27: /* "\"%lex-param {...}\"" */
-#line 169 "parse-gram.y"
+#line 169 "../../src/parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1217 "parse-gram.c"
+#line 1221 "../../src/parse-gram.c"
         break;
       case 34: /* "\"%parse-param {...}\"" */
-#line 170 "parse-gram.y"
+#line 170 "../../src/parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1222 "parse-gram.c"
+#line 1226 "../../src/parse-gram.c"
         break;
       case 41: /* "\"type\"" */
-#line 176 "parse-gram.y"
+#line 176 "../../src/parse-gram.y"
         { fprintf (stderr, "<%s>", (yyvaluep->uniqstr)); };
-#line 1227 "parse-gram.c"
+#line 1231 "../../src/parse-gram.c"
         break;
       case 45: /* "\"identifier\"" */
-#line 180 "parse-gram.y"
+#line 180 "../../src/parse-gram.y"
         { fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
-#line 1232 "parse-gram.c"
+#line 1236 "../../src/parse-gram.c"
         break;
       case 46: /* "\"identifier:\"" */
-#line 182 "parse-gram.y"
+#line 182 "../../src/parse-gram.y"
         { fprintf (stderr, "%s:", (yyvaluep->symbol)->tag); };
-#line 1237 "parse-gram.c"
+#line 1241 "../../src/parse-gram.c"
         break;
       case 48: /* "\"%{...%}\"" */
-#line 174 "parse-gram.y"
+#line 174 "../../src/parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1242 "parse-gram.c"
+#line 1246 "../../src/parse-gram.c"
         break;
       case 49: /* "\"epilogue\"" */
-#line 174 "parse-gram.y"
+#line 174 "../../src/parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1247 "parse-gram.c"
+#line 1251 "../../src/parse-gram.c"
         break;
       case 50: /* "\"{...}\"" */
-#line 173 "parse-gram.y"
+#line 173 "../../src/parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1252 "parse-gram.c"
+#line 1256 "../../src/parse-gram.c"
         break;
       case 71: /* "symbol" */
-#line 180 "parse-gram.y"
+#line 180 "../../src/parse-gram.y"
         { fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
-#line 1257 "parse-gram.c"
+#line 1261 "../../src/parse-gram.c"
         break;
       case 72: /* "action" */
-#line 173 "parse-gram.y"
+#line 173 "../../src/parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1262 "parse-gram.c"
+#line 1266 "../../src/parse-gram.c"
         break;
       case 73: /* "string_as_id" */
-#line 180 "parse-gram.y"
+#line 180 "../../src/parse-gram.y"
         { fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
-#line 1267 "parse-gram.c"
+#line 1271 "../../src/parse-gram.c"
         break;
       case 74: /* "string_content" */
-#line 165 "parse-gram.y"
+#line 165 "../../src/parse-gram.y"
         { fprintf (stderr, "\"%s\"", (yyvaluep->chars)); };
-#line 1272 "parse-gram.c"
+#line 1276 "../../src/parse-gram.c"
         break;
       default:
         break;
@@ -1439,7 +1443,7 @@ YYLTYPE yylloc;
 
 
   /* User initialization code. */
-#line 69 "parse-gram.y"
+#line 69 "../../src/parse-gram.y"
 {
   /* Bison's grammar can initial empty locations, hence a default
      location is needed. */
@@ -1448,7 +1452,7 @@ YYLTYPE yylloc;
   yylloc.start.column = yylloc.end.column = 0;
 }
 /* Line 1053 of yacc.c.  */
-#line 1452 "parse-gram.c"
+#line 1456 "../../src/parse-gram.c"
   yylsp[0] = yylloc;
   goto yysetstate;
 
@@ -1637,129 +1641,134 @@ yyreduce:
   switch (yyn)
     {
         case 6:
-#line 203 "parse-gram.y"
+#line 203 "../../src/parse-gram.y"
     { prologue_augment ((yyvsp[0].chars), (yylsp[0])); }
     break;
 
   case 7:
-#line 204 "parse-gram.y"
+#line 204 "../../src/parse-gram.y"
     { debug_flag = true; }
     break;
 
   case 8:
-#line 205 "parse-gram.y"
-    { muscle_insert ((yyvsp[-1].chars), (yyvsp[0].chars)); }
+#line 205 "../../src/parse-gram.y"
+    { muscle_insert ((yyvsp[0].chars), "1"); }
     break;
 
   case 9:
-#line 206 "parse-gram.y"
-    { defines_flag = true; }
+#line 206 "../../src/parse-gram.y"
+    { muscle_insert ((yyvsp[-1].chars), (yyvsp[0].chars)); }
     break;
 
   case 10:
-#line 207 "parse-gram.y"
-    { error_verbose = true; }
+#line 207 "../../src/parse-gram.y"
+    { defines_flag = true; }
     break;
 
   case 11:
-#line 208 "parse-gram.y"
-    { expected_sr_conflicts = (yyvsp[0].integer); }
+#line 208 "../../src/parse-gram.y"
+    { error_verbose = true; }
     break;
 
   case 12:
-#line 209 "parse-gram.y"
-    { expected_rr_conflicts = (yyvsp[0].integer); }
+#line 209 "../../src/parse-gram.y"
+    { expected_sr_conflicts = (yyvsp[0].integer); }
     break;
 
   case 13:
-#line 210 "parse-gram.y"
-    { spec_file_prefix = (yyvsp[0].chars); }
+#line 210 "../../src/parse-gram.y"
+    { expected_rr_conflicts = (yyvsp[0].integer); }
     break;
 
   case 14:
-#line 212 "parse-gram.y"
+#line 211 "../../src/parse-gram.y"
+    { spec_file_prefix = (yyvsp[0].chars); }
+    break;
+
+  case 15:
+#line 213 "../../src/parse-gram.y"
     {
     nondeterministic_parser = true;
     glr_parser = true;
   }
     break;
 
-  case 15:
-#line 217 "parse-gram.y"
+  case 16:
+#line 218 "../../src/parse-gram.y"
     {
     muscle_code_grow ("initial_action", (yyvsp[0].chars), (yylsp[0]));
   }
     break;
 
-  case 16:
-#line 220 "parse-gram.y"
+  case 17:
+#line 221 "../../src/parse-gram.y"
     { add_param ("lex_param", (yyvsp[0].chars), (yylsp[0])); }
     break;
 
-  case 17:
-#line 221 "parse-gram.y"
+  case 18:
+#line 222 "../../src/parse-gram.y"
     { locations_flag = true; }
     break;
 
-  case 18:
-#line 222 "parse-gram.y"
+  case 19:
+#line 223 "../../src/parse-gram.y"
     { spec_name_prefix = (yyvsp[0].chars); }
     break;
 
-  case 19:
-#line 223 "parse-gram.y"
+  case 20:
+#line 224 "../../src/parse-gram.y"
     { no_lines_flag = true; }
     break;
 
-  case 20:
-#line 224 "parse-gram.y"
+  case 21:
+#line 225 "../../src/parse-gram.y"
     { nondeterministic_parser = true; }
     break;
 
-  case 21:
-#line 225 "parse-gram.y"
+  case 22:
+#line 226 "../../src/parse-gram.y"
     { spec_outfile = (yyvsp[0].chars); }
     break;
 
-  case 22:
-#line 226 "parse-gram.y"
+  case 23:
+#line 227 "../../src/parse-gram.y"
     { add_param ("parse_param", (yyvsp[0].chars), (yylsp[0])); }
     break;
 
-  case 23:
-#line 227 "parse-gram.y"
+  case 24:
+#line 228 "../../src/parse-gram.y"
     { pure_parser = true; }
     break;
 
-  case 24:
-#line 228 "parse-gram.y"
+  case 25:
+#line 229 "../../src/parse-gram.y"
     { skeleton = (yyvsp[0].chars); }
     break;
 
-  case 25:
-#line 229 "parse-gram.y"
+  case 26:
+#line 230 "../../src/parse-gram.y"
     { token_table_flag = true; }
     break;
 
-  case 26:
-#line 230 "parse-gram.y"
+  case 27:
+#line 231 "../../src/parse-gram.y"
     { report_flag = report_states; }
     break;
 
-  case 27:
-#line 231 "parse-gram.y"
+  case 28:
+#line 232 "../../src/parse-gram.y"
     { yacc_flag = true; }
     break;
 
-  case 31:
-#line 239 "parse-gram.y"
+  case 32:
+#line 240 "../../src/parse-gram.y"
     {
       grammar_start_symbol_set ((yyvsp[0].symbol), (yylsp[0]));
     }
     break;
 
-  case 32:
-#line 243 "parse-gram.y"
+  case 33:
+#line 244 "../../src/parse-gram.y"
     {
       typed = true;
       MUSCLE_INSERT_INT ("stype_line", (yylsp[0]).start.line);
@@ -1767,8 +1776,8 @@ yyreduce:
     }
     break;
 
-  case 33:
-#line 249 "parse-gram.y"
+  case 34:
+#line 250 "../../src/parse-gram.y"
     {
       symbol_list *list;
       for (list = (yyvsp[0].list); list; list = list->next)
@@ -1777,8 +1786,8 @@ yyreduce:
     }
     break;
 
-  case 34:
-#line 256 "parse-gram.y"
+  case 35:
+#line 257 "../../src/parse-gram.y"
     {
       symbol_list *list;
       for (list = (yyvsp[0].list); list; list = list->next)
@@ -1787,48 +1796,48 @@ yyreduce:
     }
     break;
 
-  case 35:
-#line 263 "parse-gram.y"
+  case 36:
+#line 264 "../../src/parse-gram.y"
     {
       default_prec = true;
     }
     break;
 
-  case 36:
-#line 267 "parse-gram.y"
+  case 37:
+#line 268 "../../src/parse-gram.y"
     {
       default_prec = false;
     }
     break;
 
-  case 37:
-#line 273 "parse-gram.y"
+  case 38:
+#line 274 "../../src/parse-gram.y"
     { current_class = nterm_sym; }
     break;
 
-  case 38:
-#line 274 "parse-gram.y"
+  case 39:
+#line 275 "../../src/parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
     break;
 
-  case 39:
-#line 278 "parse-gram.y"
+  case 40:
+#line 279 "../../src/parse-gram.y"
     { current_class = token_sym; }
     break;
 
-  case 40:
-#line 279 "parse-gram.y"
+  case 41:
+#line 280 "../../src/parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
     break;
 
-  case 41:
-#line 284 "parse-gram.y"
+  case 42:
+#line 285 "../../src/parse-gram.y"
     {
       symbol_list *list;
       for (list = (yyvsp[0].list); list; list = list->next)
@@ -1837,8 +1846,8 @@ yyreduce:
     }
     break;
 
-  case 42:
-#line 294 "parse-gram.y"
+  case 43:
+#line 295 "../../src/parse-gram.y"
     {
       symbol_list *list;
       ++current_prec;
@@ -1852,58 +1861,58 @@ yyreduce:
     }
     break;
 
-  case 43:
-#line 308 "parse-gram.y"
+  case 44:
+#line 309 "../../src/parse-gram.y"
     { (yyval.assoc) = left_assoc; }
     break;
 
-  case 44:
-#line 309 "parse-gram.y"
+  case 45:
+#line 310 "../../src/parse-gram.y"
     { (yyval.assoc) = right_assoc; }
     break;
 
-  case 45:
-#line 310 "parse-gram.y"
+  case 46:
+#line 311 "../../src/parse-gram.y"
     { (yyval.assoc) = non_assoc; }
     break;
 
-  case 46:
-#line 314 "parse-gram.y"
+  case 47:
+#line 315 "../../src/parse-gram.y"
     { current_type = NULL; }
     break;
 
-  case 47:
-#line 315 "parse-gram.y"
+  case 48:
+#line 316 "../../src/parse-gram.y"
     { current_type = (yyvsp[0].uniqstr); }
     break;
 
-  case 48:
-#line 321 "parse-gram.y"
+  case 49:
+#line 322 "../../src/parse-gram.y"
     { (yyval.list) = symbol_list_new ((yyvsp[0].symbol), (yylsp[0])); }
     break;
 
-  case 49:
-#line 322 "parse-gram.y"
+  case 50:
+#line 323 "../../src/parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), (yyvsp[0].symbol), (yylsp[0])); }
     break;
 
-  case 50:
-#line 328 "parse-gram.y"
+  case 51:
+#line 329 "../../src/parse-gram.y"
     {
        current_type = (yyvsp[0].uniqstr);
      }
     break;
 
-  case 51:
-#line 332 "parse-gram.y"
+  case 52:
+#line 333 "../../src/parse-gram.y"
     {
        symbol_class_set ((yyvsp[0].symbol), current_class, (yylsp[0]));
        symbol_type_set ((yyvsp[0].symbol), current_type, (yylsp[0]));
      }
     break;
 
-  case 52:
-#line 337 "parse-gram.y"
+  case 53:
+#line 338 "../../src/parse-gram.y"
     {
       symbol_class_set ((yyvsp[-1].symbol), current_class, (yylsp[-1]));
       symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
@@ -1911,8 +1920,8 @@ yyreduce:
     }
     break;
 
-  case 53:
-#line 343 "parse-gram.y"
+  case 54:
+#line 344 "../../src/parse-gram.y"
     {
       symbol_class_set ((yyvsp[-1].symbol), current_class, (yylsp[-1]));
       symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
@@ -1920,8 +1929,8 @@ yyreduce:
     }
     break;
 
-  case 54:
-#line 349 "parse-gram.y"
+  case 55:
+#line 350 "../../src/parse-gram.y"
     {
       symbol_class_set ((yyvsp[-2].symbol), current_class, (yylsp[-2]));
       symbol_type_set ((yyvsp[-2].symbol), current_type, (yylsp[-2]));
@@ -1930,96 +1939,96 @@ yyreduce:
     }
     break;
 
-  case 60:
-#line 378 "parse-gram.y"
+  case 61:
+#line 379 "../../src/parse-gram.y"
     {
       if (yacc_flag)
 	complain_at ((yyloc), _("POSIX forbids declarations in the grammar"));
     }
     break;
 
-  case 61:
-#line 383 "parse-gram.y"
+  case 62:
+#line 384 "../../src/parse-gram.y"
     {
       yyerrok;
     }
     break;
 
-  case 62:
-#line 389 "parse-gram.y"
+  case 63:
+#line 390 "../../src/parse-gram.y"
     { current_lhs = (yyvsp[0].symbol); current_lhs_location = (yylsp[0]); }
     break;
 
-  case 64:
-#line 393 "parse-gram.y"
+  case 65:
+#line 394 "../../src/parse-gram.y"
     { grammar_rule_end ((yylsp[0])); }
     break;
 
-  case 65:
-#line 394 "parse-gram.y"
+  case 66:
+#line 395 "../../src/parse-gram.y"
     { grammar_rule_end ((yylsp[0])); }
     break;
 
-  case 67:
-#line 400 "parse-gram.y"
+  case 68:
+#line 401 "../../src/parse-gram.y"
     { grammar_rule_begin (current_lhs, current_lhs_location); }
     break;
 
-  case 68:
-#line 402 "parse-gram.y"
+  case 69:
+#line 403 "../../src/parse-gram.y"
     { grammar_current_rule_symbol_append ((yyvsp[0].symbol), (yylsp[0])); }
     break;
 
-  case 69:
-#line 404 "parse-gram.y"
+  case 70:
+#line 405 "../../src/parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[0].chars), (yylsp[0])); }
     break;
 
-  case 70:
-#line 406 "parse-gram.y"
+  case 71:
+#line 407 "../../src/parse-gram.y"
     { grammar_current_rule_prec_set ((yyvsp[0].symbol), (yylsp[0])); }
     break;
 
-  case 71:
-#line 408 "parse-gram.y"
+  case 72:
+#line 409 "../../src/parse-gram.y"
     { grammar_current_rule_dprec_set ((yyvsp[0].integer), (yylsp[0])); }
     break;
 
-  case 72:
-#line 410 "parse-gram.y"
+  case 73:
+#line 411 "../../src/parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[0].uniqstr), (yylsp[0])); }
     break;
 
-  case 73:
-#line 414 "parse-gram.y"
+  case 74:
+#line 415 "../../src/parse-gram.y"
     { (yyval.symbol) = (yyvsp[0].symbol); }
     break;
 
-  case 74:
-#line 415 "parse-gram.y"
+  case 75:
+#line 416 "../../src/parse-gram.y"
     { (yyval.symbol) = (yyvsp[0].symbol); }
     break;
 
-  case 75:
-#line 420 "parse-gram.y"
+  case 76:
+#line 421 "../../src/parse-gram.y"
     { (yyval.chars) = (yyvsp[0].chars); }
     break;
 
-  case 76:
-#line 426 "parse-gram.y"
+  case 77:
+#line 427 "../../src/parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[0].chars)), (yylsp[0]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]));
     }
     break;
 
-  case 77:
-#line 435 "parse-gram.y"
+  case 78:
+#line 436 "../../src/parse-gram.y"
     { (yyval.chars) = (yyvsp[0].chars); }
     break;
 
-  case 79:
-#line 442 "parse-gram.y"
+  case 80:
+#line 443 "../../src/parse-gram.y"
     {
       muscle_code_grow ("epilogue", (yyvsp[0].chars), (yylsp[0]));
       scanner_last_string_free ();
@@ -2031,7 +2040,7 @@ yyreduce:
     }
 
 /* Line 1249 of yacc.c.  */
-#line 2035 "parse-gram.c"
+#line 2044 "../../src/parse-gram.c"
 
   yyvsp -= yylen;
   yyssp -= yylen;
@@ -2241,7 +2250,7 @@ yyreturn:
 }
 
 
-#line 448 "parse-gram.y"
+#line 449 "../../src/parse-gram.y"
 
 
 
