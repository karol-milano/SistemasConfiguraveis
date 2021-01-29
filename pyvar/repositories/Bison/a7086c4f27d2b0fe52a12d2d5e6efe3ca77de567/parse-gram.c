@@ -522,11 +522,11 @@ union yyalloc
 /* YYNTOKENS -- Number of terminals.  */
 #define YYNTOKENS  52
 /* YYNNTS -- Number of nonterminals.  */
-#define YYNNTS  25
+#define YYNNTS  26
 /* YYNRULES -- Number of rules.  */
-#define YYNRULES  81
+#define YYNRULES  82
 /* YYNRULES -- Number of states.  */
-#define YYNSTATES  110
+#define YYNSTATES  111
 
 /* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
 #define YYUNDEFTOK  2
@@ -583,48 +583,48 @@ static const yytype_uint8 yyprhs[] =
       97,   101,   102,   106,   110,   114,   116,   118,   120,   121,
      123,   125,   128,   130,   132,   135,   138,   142,   144,   147,
      149,   152,   154,   157,   160,   161,   165,   167,   171,   174,
-     175,   178,   181,   185,   189,   193,   195,   197,   199,   201,
-     203,   204
+     175,   178,   181,   185,   189,   193,   195,   197,   198,   201,
+     203,   205,   206
 };
 
 /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
 static const yytype_int8 yyrhs[] =
 {
-      53,     0,    -1,    54,    48,    66,    76,    -1,    -1,    54,
-      55,    -1,    56,    -1,    49,    -1,    17,    -1,    19,    75,
-      -1,    19,    75,    75,    -1,    20,    -1,    21,    -1,    22,
-       4,    -1,    23,     4,    -1,    24,    43,    75,    -1,    25,
-      -1,    26,    -1,    27,    -1,    28,    -1,    29,    43,    75,
-      -1,    31,    -1,    32,    -1,    33,    43,    75,    -1,    34,
-      -1,    35,    -1,    36,    75,    -1,    37,    75,    -1,    39,
+      53,     0,    -1,    54,    48,    66,    77,    -1,    -1,    54,
+      55,    -1,    56,    -1,    49,    -1,    17,    -1,    19,    76,
+      -1,    19,    76,    76,    -1,    20,    -1,    21,    -1,    22,
+       4,    -1,    23,     4,    -1,    24,    43,    76,    -1,    25,
+      -1,    26,    -1,    27,    -1,    28,    -1,    29,    43,    76,
+      -1,    31,    -1,    32,    -1,    33,    43,    76,    -1,    34,
+      -1,    35,    -1,    36,    76,    -1,    37,    76,    -1,    39,
       -1,    40,    -1,    41,    -1,    44,    -1,    60,    -1,    57,
       -1,    38,    72,    -1,    10,    -1,     8,    63,    -1,     9,
       63,    -1,    18,    -1,    30,    -1,    -1,     6,    58,    65,
       -1,    -1,     5,    59,    65,    -1,     7,    42,    63,    -1,
       61,    62,    63,    -1,    11,    -1,    12,    -1,    13,    -1,
       -1,    42,    -1,    72,    -1,    63,    72,    -1,    42,    -1,
-      46,    -1,    46,     4,    -1,    46,    74,    -1,    46,     4,
-      74,    -1,    64,    -1,    65,    64,    -1,    67,    -1,    66,
+      46,    -1,    46,     4,    -1,    46,    75,    -1,    46,     4,
+      75,    -1,    64,    -1,    65,    64,    -1,    67,    -1,    66,
       67,    -1,    68,    -1,    56,    44,    -1,     1,    44,    -1,
       -1,    47,    69,    70,    -1,    71,    -1,    70,    45,    71,
       -1,    70,    44,    -1,    -1,    71,    72,    -1,    71,    73,
       -1,    71,    14,    72,    -1,    71,    15,     4,    -1,    71,
-      16,    42,    -1,    46,    -1,    74,    -1,    51,    -1,     3,
-      -1,     3,    -1,    -1,    48,    50,    -1
+      16,    42,    -1,    46,    -1,    75,    -1,    -1,    74,    51,
+      -1,     3,    -1,     3,    -1,    -1,    48,    50,    -1
 };
 
 /* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
 static const yytype_uint16 yyrline[] =
 {
-       0,   205,   205,   213,   215,   219,   220,   221,   222,   227,
-     228,   229,   230,   231,   232,   233,   238,   242,   243,   244,
-     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
-     255,   259,   260,   261,   265,   281,   288,   295,   299,   306,
-     306,   311,   311,   316,   326,   341,   342,   343,   347,   348,
-     354,   355,   360,   364,   369,   375,   381,   392,   393,   402,
-     403,   409,   410,   411,   418,   418,   422,   423,   424,   429,
-     430,   432,   434,   436,   438,   443,   444,   448,   454,   463,
-     468,   470
+       0,   203,   203,   211,   213,   217,   218,   219,   220,   225,
+     226,   227,   228,   229,   230,   231,   236,   240,   241,   242,
+     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
+     253,   257,   258,   259,   263,   279,   286,   293,   297,   304,
+     304,   309,   309,   314,   324,   339,   340,   341,   345,   346,
+     352,   353,   358,   362,   367,   373,   379,   390,   391,   400,
+     401,   407,   408,   409,   416,   416,   420,   421,   422,   427,
+     428,   430,   431,   433,   435,   440,   441,   457,   457,   463,
+     472,   477,   479
 };
 #endif
 
@@ -650,7 +650,7 @@ static const char *const yytname[] =
   "symbol_declaration", "@1", "@2", "precedence_declaration",
   "precedence_declarator", "type.opt", "symbols.1", "symbol_def",
   "symbol_defs.1", "grammar", "rules_or_grammar_declaration", "rules",
-  "@3", "rhses.1", "rhs", "symbol", "action", "string_as_id",
+  "@3", "rhses.1", "rhs", "symbol", "action", "@4", "string_as_id",
   "string_content", "epilogue.opt", 0
 };
 #endif
@@ -679,8 +679,8 @@ static const yytype_uint8 yyr1[] =
       57,    59,    57,    57,    60,    61,    61,    61,    62,    62,
       63,    63,    64,    64,    64,    64,    64,    65,    65,    66,
       66,    67,    67,    67,    69,    68,    70,    70,    70,    71,
-      71,    71,    71,    71,    71,    72,    72,    73,    74,    75,
-      76,    76
+      71,    71,    71,    71,    71,    72,    72,    74,    73,    75,
+      76,    77,    77
 };
 
 /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
@@ -693,8 +693,8 @@ static const yytype_uint8 yyr2[] =
        3,     0,     3,     3,     3,     1,     1,     1,     0,     1,
        1,     2,     1,     1,     2,     2,     3,     1,     2,     1,
        2,     1,     2,     2,     0,     3,     1,     3,     2,     0,
-       2,     2,     3,     3,     3,     1,     1,     1,     1,     1,
-       0,     2
+       2,     2,     3,     3,     3,     1,     1,     0,     2,     1,
+       1,     0,     2
 };
 
 /* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
@@ -706,13 +706,14 @@ static const yytype_uint8 yydefact[] =
       45,    46,    47,     7,    37,     0,    10,    11,     0,     0,
        0,    15,    16,    17,    18,     0,    38,    20,    21,     0,
       23,    24,     0,     0,     0,    27,    28,    29,    30,     0,
-       6,     4,     5,    32,    31,    48,     0,     0,     0,    78,
-      75,    35,    50,    76,    36,    79,     8,    12,    13,     0,
+       6,     4,     5,    32,    31,    48,     0,     0,     0,    79,
+      75,    35,    50,    76,    36,    80,     8,    12,    13,     0,
        0,     0,    25,    26,    33,     0,    64,     0,     0,    59,
       61,    49,     0,    52,    53,    57,    42,    40,    43,    51,
        9,    14,    19,    22,    63,    69,    62,     0,    60,     2,
-      44,    54,    55,    58,    65,    66,    81,    56,    68,    69,
-       0,     0,     0,    77,    70,    71,    67,    72,    73,    74
+      44,    54,    55,    58,    65,    66,    82,    56,    68,    69,
+       0,     0,     0,    70,    71,     0,    67,    72,    73,    74,
+      78
 };
 
 /* YYDEFGOTO[NTERM-NUM].  */
@@ -720,7 +721,7 @@ static const yytype_int8 yydefgoto[] =
 {
       -1,     1,     2,    41,    67,    43,    47,    46,    44,    45,
       72,    51,    75,    76,    68,    69,    70,    85,    94,    95,
-      52,   105,    53,    56,    89
+      52,   104,   105,    53,    56,    89
 };
 
 /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
@@ -738,32 +739,33 @@ static const yytype_int8 yypact[] =
      -69,   -69,     0,   -69,     6,   -69,   -38,   -38,     0,   -69,
      -69,   -69,   -69,   -69,   -69,   -69,   -69,     2,   -69,   -69,
        0,    39,   -69,   -69,   -33,    -1,   -69,   -69,   -69,   -69,
-       0,    44,     1,   -69,   -69,   -69,    -1,   -69,   -69,   -69
+       0,    44,     1,   -69,   -69,     4,    -1,   -69,   -69,   -69,
+     -69
 };
 
 /* YYPGOTO[NTERM-NUM].  */
 static const yytype_int8 yypgoto[] =
 {
      -69,   -69,   -69,   -69,    47,   -69,   -69,   -69,   -69,   -69,
-     -69,    -7,   -58,     7,   -69,   -15,   -69,   -69,   -69,   -44,
-     -34,   -69,   -68,    30,   -69
+     -69,    -7,   -58,     7,   -69,   -15,   -69,   -69,   -69,   -42,
+     -34,   -69,   -69,   -68,    30,   -69
 };
 
 /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
    positive, shift that token.  If negative, reduce the rule which
    number is the opposite.  If zero, do what YYDEFACT says.
    If YYTABLE_NINF, syntax error.  */
-#define YYTABLE_NINF -81
+#define YYTABLE_NINF -82
 static const yytype_int8 yytable[] =
 {
       64,    54,    49,    49,    73,     3,    92,    48,    74,    49,
       91,    98,    99,   100,   101,   102,    55,    79,    93,    93,
-      79,   -80,    65,    97,    57,    59,     4,     5,     6,     7,
+      79,   -81,    65,    97,    57,    59,     4,     5,     6,     7,
        8,     9,    10,    11,    12,    58,    84,    60,    61,    14,
       71,    78,    49,   109,    79,    50,    50,    86,   108,    42,
-     103,    26,    96,    88,    77,   106,    79,     0,     0,    34,
-       0,   104,    62,    63,     0,    90,   107,     0,    66,    87,
-      65,     0,   104,     0,     4,     5,     6,     7,     8,     9,
+     -77,    26,    96,    88,    77,   110,    79,   106,     0,    34,
+       0,   103,    62,    63,     0,    90,   107,     0,    66,    87,
+      65,     0,   103,     0,     4,     5,     6,     7,     8,     9,
       10,    11,    12,     0,     0,     0,    80,    14,     0,    81,
       82,    83,     0,     0,     0,     0,     0,     0,     0,    26,
        0,     0,     0,     0,     0,     0,     0,    34,     0,     0,
@@ -782,7 +784,7 @@ static const yytype_int8 yycheck[] =
       54,     0,     1,    91,     4,    43,     5,     6,     7,     8,
        9,    10,    11,    12,    13,     4,    44,    43,    43,    18,
       42,    48,     3,    42,    78,    46,    46,    44,     4,     2,
-      51,    30,    50,    68,    47,    99,    90,    -1,    -1,    38,
+      51,    30,    50,    68,    47,    51,    90,    99,    -1,    38,
       -1,    95,    32,    33,    -1,    72,   100,    -1,    47,    48,
        1,    -1,   106,    -1,     5,     6,     7,     8,     9,    10,
       11,    12,    13,    -1,    -1,    -1,    56,    18,    -1,    59,
@@ -805,12 +807,13 @@ static const yytype_uint8 yystos[] =
       24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
       34,    35,    36,    37,    38,    39,    40,    41,    44,    48,
       49,    55,    56,    57,    60,    61,    59,    58,    42,     3,
-      46,    63,    72,    74,    63,     3,    75,     4,     4,    43,
-      43,    43,    75,    75,    72,     1,    47,    56,    66,    67,
+      46,    63,    72,    75,    63,     3,    76,     4,     4,    43,
+      43,    43,    76,    76,    72,     1,    47,    56,    66,    67,
       68,    42,    62,    42,    46,    64,    65,    65,    63,    72,
-      75,    75,    75,    75,    44,    69,    44,    48,    67,    76,
-      63,     4,    74,    64,    70,    71,    50,    74,    44,    45,
-      14,    15,    16,    51,    72,    73,    71,    72,     4,    42
+      76,    76,    76,    76,    44,    69,    44,    48,    67,    77,
+      63,     4,    75,    64,    70,    71,    50,    75,    44,    45,
+      14,    15,    16,    72,    73,    74,    71,    72,     4,    42,
+      51
 };
 
 #define yyerrok		(yyerrstatus = 0)
@@ -959,94 +962,84 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
   switch (yytype)
     {
       case 3: /* "\"string\"" */
-#line 182 "parse-gram.y"
+#line 181 "parse-gram.y"
 	{ fprintf (stderr, "\"%s\"", (yyvaluep->chars)); };
-#line 965 "parse-gram.c"
+#line 968 "parse-gram.c"
 	break;
       case 4: /* "\"integer\"" */
-#line 195 "parse-gram.y"
+#line 193 "parse-gram.y"
 	{ fprintf (stderr, "%d", (yyvaluep->integer)); };
-#line 970 "parse-gram.c"
+#line 973 "parse-gram.c"
 	break;
       case 8: /* "\"%destructor {...}\"" */
-#line 184 "parse-gram.y"
+#line 183 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 975 "parse-gram.c"
+#line 978 "parse-gram.c"
 	break;
       case 9: /* "\"%printer {...}\"" */
-#line 188 "parse-gram.y"
+#line 187 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 980 "parse-gram.c"
+#line 983 "parse-gram.c"
 	break;
       case 10: /* "\"%union {...}\"" */
-#line 189 "parse-gram.y"
+#line 188 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 985 "parse-gram.c"
+#line 988 "parse-gram.c"
 	break;
       case 26: /* "\"%initial-action {...}\"" */
-#line 185 "parse-gram.y"
+#line 184 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 990 "parse-gram.c"
+#line 993 "parse-gram.c"
 	break;
       case 27: /* "\"%lex-param {...}\"" */
-#line 186 "parse-gram.y"
+#line 185 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 995 "parse-gram.c"
+#line 998 "parse-gram.c"
 	break;
       case 34: /* "\"%parse-param {...}\"" */
-#line 187 "parse-gram.y"
+#line 186 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1000 "parse-gram.c"
+#line 1003 "parse-gram.c"
 	break;
       case 42: /* "\"type\"" */
-#line 193 "parse-gram.y"
+#line 191 "parse-gram.y"
 	{ fprintf (stderr, "<%s>", (yyvaluep->uniqstr)); };
-#line 1005 "parse-gram.c"
+#line 1008 "parse-gram.c"
 	break;
       case 46: /* "\"identifier\"" */
-#line 197 "parse-gram.y"
+#line 195 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
-#line 1010 "parse-gram.c"
+#line 1013 "parse-gram.c"
 	break;
       case 47: /* "\"identifier:\"" */
-#line 199 "parse-gram.y"
+#line 197 "parse-gram.y"
 	{ fprintf (stderr, "%s:", (yyvaluep->symbol)->tag); };
-#line 1015 "parse-gram.c"
+#line 1018 "parse-gram.c"
 	break;
       case 49: /* "\"%{...%}\"" */
-#line 191 "parse-gram.y"
+#line 189 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1020 "parse-gram.c"
+#line 1023 "parse-gram.c"
 	break;
       case 50: /* "\"epilogue\"" */
-#line 191 "parse-gram.y"
-	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1025 "parse-gram.c"
-	break;
-      case 51: /* "\"{...}\"" */
-#line 190 "parse-gram.y"
+#line 189 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1030 "parse-gram.c"
+#line 1028 "parse-gram.c"
 	break;
       case 72: /* "symbol" */
-#line 197 "parse-gram.y"
+#line 195 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
-#line 1035 "parse-gram.c"
+#line 1033 "parse-gram.c"
 	break;
-      case 73: /* "action" */
-#line 190 "parse-gram.y"
-	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1040 "parse-gram.c"
-	break;
-      case 74: /* "string_as_id" */
-#line 197 "parse-gram.y"
+      case 75: /* "string_as_id" */
+#line 195 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
-#line 1045 "parse-gram.c"
+#line 1038 "parse-gram.c"
 	break;
-      case 75: /* "string_content" */
-#line 182 "parse-gram.y"
+      case 76: /* "string_content" */
+#line 181 "parse-gram.y"
 	{ fprintf (stderr, "\"%s\"", (yyvaluep->chars)); };
-#line 1050 "parse-gram.c"
+#line 1043 "parse-gram.c"
 	break;
       default:
 	break;
@@ -1566,7 +1559,7 @@ YYLTYPE yylloc;
   yylloc.start.column = yylloc.end.column = 0;
 }
 /* Line 1081 of yacc.c.  */
-#line 1570 "parse-gram.c"
+#line 1563 "parse-gram.c"
   yylsp[0] = yylloc;
   goto yysetstate;
 
@@ -1751,17 +1744,17 @@ yyreduce:
   switch (yyn)
     {
         case 6:
-#line 220 "parse-gram.y"
+#line 218 "parse-gram.y"
     { prologue_augment ((yyvsp[(1) - (1)].chars), (yylsp[(1) - (1)])); }
     break;
 
   case 7:
-#line 221 "parse-gram.y"
+#line 219 "parse-gram.y"
     { debug_flag = true; }
     break;
 
   case 8:
-#line 223 "parse-gram.y"
+#line 221 "parse-gram.y"
     {
       static char one[] = "1";
       muscle_insert ((yyvsp[(2) - (2)].chars), one);
@@ -1769,37 +1762,37 @@ yyreduce:
     break;
 
   case 9:
-#line 227 "parse-gram.y"
+#line 225 "parse-gram.y"
     { muscle_insert ((yyvsp[(2) - (3)].chars), (yyvsp[(3) - (3)].chars)); }
     break;
 
   case 10:
-#line 228 "parse-gram.y"
+#line 226 "parse-gram.y"
     { defines_flag = true; }
     break;
 
   case 11:
-#line 229 "parse-gram.y"
+#line 227 "parse-gram.y"
     { error_verbose = true; }
     break;
 
   case 12:
-#line 230 "parse-gram.y"
+#line 228 "parse-gram.y"
     { expected_sr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 13:
-#line 231 "parse-gram.y"
+#line 229 "parse-gram.y"
     { expected_rr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 14:
-#line 232 "parse-gram.y"
+#line 230 "parse-gram.y"
     { spec_file_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 15:
-#line 234 "parse-gram.y"
+#line 232 "parse-gram.y"
     {
       nondeterministic_parser = true;
       glr_parser = true;
@@ -1807,86 +1800,86 @@ yyreduce:
     break;
 
   case 16:
-#line 239 "parse-gram.y"
+#line 237 "parse-gram.y"
     {
       muscle_code_grow ("initial_action", (yyvsp[(1) - (1)].chars), (yylsp[(1) - (1)]));
     }
     break;
 
   case 17:
-#line 242 "parse-gram.y"
+#line 240 "parse-gram.y"
     { add_param ("lex_param", (yyvsp[(1) - (1)].chars), (yylsp[(1) - (1)])); }
     break;
 
   case 18:
-#line 243 "parse-gram.y"
+#line 241 "parse-gram.y"
     { locations_flag = true; }
     break;
 
   case 19:
-#line 244 "parse-gram.y"
+#line 242 "parse-gram.y"
     { spec_name_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 20:
-#line 245 "parse-gram.y"
+#line 243 "parse-gram.y"
     { no_lines_flag = true; }
     break;
 
   case 21:
-#line 246 "parse-gram.y"
+#line 244 "parse-gram.y"
     { nondeterministic_parser = true; }
     break;
 
   case 22:
-#line 247 "parse-gram.y"
+#line 245 "parse-gram.y"
     { spec_outfile = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 23:
-#line 248 "parse-gram.y"
+#line 246 "parse-gram.y"
     { add_param ("parse_param", (yyvsp[(1) - (1)].chars), (yylsp[(1) - (1)])); }
     break;
 
   case 24:
-#line 249 "parse-gram.y"
+#line 247 "parse-gram.y"
     { pure_parser = true; }
     break;
 
   case 25:
-#line 250 "parse-gram.y"
+#line 248 "parse-gram.y"
     { version_check (&(yylsp[(2) - (2)]), (yyvsp[(2) - (2)].chars)); }
     break;
 
   case 26:
-#line 251 "parse-gram.y"
+#line 249 "parse-gram.y"
     { skeleton = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 27:
-#line 252 "parse-gram.y"
+#line 250 "parse-gram.y"
     { token_table_flag = true; }
     break;
 
   case 28:
-#line 253 "parse-gram.y"
+#line 251 "parse-gram.y"
     { report_flag = report_states; }
     break;
 
   case 29:
-#line 254 "parse-gram.y"
+#line 252 "parse-gram.y"
     { yacc_flag = true; }
     break;
 
   case 33:
-#line 262 "parse-gram.y"
+#line 260 "parse-gram.y"
     {
       grammar_start_symbol_set ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]));
     }
     break;
 
   case 34:
-#line 266 "parse-gram.y"
+#line 264 "parse-gram.y"
     {
       char const *body = (yyvsp[(1) - (1)].chars);
 
@@ -1905,7 +1898,7 @@ yyreduce:
     break;
 
   case 35:
-#line 282 "parse-gram.y"
+#line 280 "parse-gram.y"
     {
       symbol_list *list;
       for (list = (yyvsp[(2) - (2)].list); list; list = list->next)
@@ -1915,7 +1908,7 @@ yyreduce:
     break;
 
   case 36:
-#line 289 "parse-gram.y"
+#line 287 "parse-gram.y"
     {
       symbol_list *list;
       for (list = (yyvsp[(2) - (2)].list); list; list = list->next)
@@ -1925,26 +1918,26 @@ yyreduce:
     break;
 
   case 37:
-#line 296 "parse-gram.y"
+#line 294 "parse-gram.y"
     {
       default_prec = true;
     }
     break;
 
   case 38:
-#line 300 "parse-gram.y"
+#line 298 "parse-gram.y"
     {
       default_prec = false;
     }
     break;
 
   case 39:
-#line 306 "parse-gram.y"
+#line 304 "parse-gram.y"
     { current_class = nterm_sym; }
     break;
 
   case 40:
-#line 307 "parse-gram.y"
+#line 305 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
@@ -1952,12 +1945,12 @@ yyreduce:
     break;
 
   case 41:
-#line 311 "parse-gram.y"
+#line 309 "parse-gram.y"
     { current_class = token_sym; }
     break;
 
   case 42:
-#line 312 "parse-gram.y"
+#line 310 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
@@ -1965,7 +1958,7 @@ yyreduce:
     break;
 
   case 43:
-#line 317 "parse-gram.y"
+#line 315 "parse-gram.y"
     {
       symbol_list *list;
       for (list = (yyvsp[(3) - (3)].list); list; list = list->next)
@@ -1975,7 +1968,7 @@ yyreduce:
     break;
 
   case 44:
-#line 327 "parse-gram.y"
+#line 325 "parse-gram.y"
     {
       symbol_list *list;
       ++current_prec;
@@ -1990,49 +1983,49 @@ yyreduce:
     break;
 
   case 45:
-#line 341 "parse-gram.y"
+#line 339 "parse-gram.y"
     { (yyval.assoc) = left_assoc; }
     break;
 
   case 46:
-#line 342 "parse-gram.y"
+#line 340 "parse-gram.y"
     { (yyval.assoc) = right_assoc; }
     break;
 
   case 47:
-#line 343 "parse-gram.y"
+#line 341 "parse-gram.y"
     { (yyval.assoc) = non_assoc; }
     break;
 
   case 48:
-#line 347 "parse-gram.y"
+#line 345 "parse-gram.y"
     { current_type = NULL; }
     break;
 
   case 49:
-#line 348 "parse-gram.y"
+#line 346 "parse-gram.y"
     { current_type = (yyvsp[(1) - (1)].uniqstr); }
     break;
 
   case 50:
-#line 354 "parse-gram.y"
+#line 352 "parse-gram.y"
     { (yyval.list) = symbol_list_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 51:
-#line 355 "parse-gram.y"
+#line 353 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), (yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)])); }
     break;
 
   case 52:
-#line 361 "parse-gram.y"
+#line 359 "parse-gram.y"
     {
        current_type = (yyvsp[(1) - (1)].uniqstr);
      }
     break;
 
   case 53:
-#line 365 "parse-gram.y"
+#line 363 "parse-gram.y"
     {
        symbol_class_set ((yyvsp[(1) - (1)].symbol), current_class, (yylsp[(1) - (1)]), true);
        symbol_type_set ((yyvsp[(1) - (1)].symbol), current_type, (yylsp[(1) - (1)]));
@@ -2040,7 +2033,7 @@ yyreduce:
     break;
 
   case 54:
-#line 370 "parse-gram.y"
+#line 368 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
       symbol_type_set ((yyvsp[(1) - (2)].symbol), current_type, (yylsp[(1) - (2)]));
@@ -2049,7 +2042,7 @@ yyreduce:
     break;
 
   case 55:
-#line 376 "parse-gram.y"
+#line 374 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
       symbol_type_set ((yyvsp[(1) - (2)].symbol), current_type, (yylsp[(1) - (2)]));
@@ -2058,7 +2051,7 @@ yyreduce:
     break;
 
   case 56:
-#line 382 "parse-gram.y"
+#line 380 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (3)].symbol), current_class, (yylsp[(1) - (3)]), true);
       symbol_type_set ((yyvsp[(1) - (3)].symbol), current_type, (yylsp[(1) - (3)]));
@@ -2068,87 +2061,82 @@ yyreduce:
     break;
 
   case 63:
-#line 412 "parse-gram.y"
+#line 410 "parse-gram.y"
     {
       yyerrok;
     }
     break;
 
   case 64:
-#line 418 "parse-gram.y"
+#line 416 "parse-gram.y"
     { current_lhs = (yyvsp[(1) - (1)].symbol); current_lhs_location = (yylsp[(1) - (1)]); }
     break;
 
   case 66:
-#line 422 "parse-gram.y"
+#line 420 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(1) - (1)])); }
     break;
 
   case 67:
-#line 423 "parse-gram.y"
+#line 421 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(3) - (3)])); }
     break;
 
   case 69:
-#line 429 "parse-gram.y"
+#line 427 "parse-gram.y"
     { grammar_current_rule_begin (current_lhs, current_lhs_location); }
     break;
 
   case 70:
-#line 431 "parse-gram.y"
+#line 429 "parse-gram.y"
     { grammar_current_rule_symbol_append ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)])); }
     break;
 
-  case 71:
-#line 433 "parse-gram.y"
-    { grammar_current_rule_action_append ((yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])); }
-    break;
-
   case 72:
-#line 435 "parse-gram.y"
+#line 432 "parse-gram.y"
     { grammar_current_rule_prec_set ((yyvsp[(3) - (3)].symbol), (yylsp[(3) - (3)])); }
     break;
 
   case 73:
-#line 437 "parse-gram.y"
+#line 434 "parse-gram.y"
     { grammar_current_rule_dprec_set ((yyvsp[(3) - (3)].integer), (yylsp[(3) - (3)])); }
     break;
 
   case 74:
-#line 439 "parse-gram.y"
+#line 436 "parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[(3) - (3)].uniqstr), (yylsp[(3) - (3)])); }
     break;
 
   case 75:
-#line 443 "parse-gram.y"
+#line 440 "parse-gram.y"
     { (yyval.symbol) = (yyvsp[(1) - (1)].symbol); }
     break;
 
   case 76:
-#line 444 "parse-gram.y"
+#line 441 "parse-gram.y"
     { (yyval.symbol) = (yyvsp[(1) - (1)].symbol); }
     break;
 
   case 77:
-#line 449 "parse-gram.y"
-    { (yyval.chars) = (yyvsp[(1) - (1)].chars); }
+#line 457 "parse-gram.y"
+    { grammar_current_rule_action_append (last_string, last_braced_code_loc); }
     break;
 
-  case 78:
-#line 455 "parse-gram.y"
+  case 79:
+#line 464 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[(1) - (1)].chars)), (yylsp[(1) - (1)]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[(1) - (1)]), false);
     }
     break;
 
-  case 79:
-#line 464 "parse-gram.y"
+  case 80:
+#line 473 "parse-gram.y"
     { (yyval.chars) = (yyvsp[(1) - (1)].chars); }
     break;
 
-  case 81:
-#line 471 "parse-gram.y"
+  case 82:
+#line 480 "parse-gram.y"
     {
       muscle_code_grow ("epilogue", (yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)]));
       scanner_last_string_free ();
@@ -2157,7 +2145,7 @@ yyreduce:
 
 
 /* Line 1270 of yacc.c.  */
-#line 2161 "parse-gram.c"
+#line 2149 "parse-gram.c"
       default: break;
     }
   YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);
@@ -2376,7 +2364,7 @@ yyreturn:
 }
 
 
-#line 477 "parse-gram.y"
+#line 486 "parse-gram.y"
 
 
 
