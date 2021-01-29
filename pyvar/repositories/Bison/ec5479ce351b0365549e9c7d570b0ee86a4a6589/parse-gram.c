@@ -552,7 +552,7 @@ union yyalloc
 /* YYNNTS -- Number of nonterminals.  */
 #define YYNNTS  29
 /* YYNRULES -- Number of rules.  */
-#define YYNRULES  92
+#define YYNRULES  94
 /* YYNRULES -- Number of states.  */
 #define YYNSTATES  131
 
@@ -608,13 +608,13 @@ static const yytype_uint8 yyprhs[] =
        0,     0,     3,     8,     9,    12,    14,    16,    19,    22,
       24,    28,    30,    33,    35,    38,    41,    45,    47,    50,
       53,    55,    59,    61,    63,    67,    70,    72,    75,    78,
-      81,    83,    85,    87,    89,    91,    93,    96,   100,   104,
-     106,   108,   109,   111,   115,   116,   120,   121,   125,   129,
-     133,   135,   137,   139,   140,   142,   144,   147,   149,   151,
-     154,   157,   161,   163,   166,   168,   171,   173,   176,   179,
-     180,   184,   186,   190,   193,   194,   197,   200,   204,   208,
-     212,   214,   216,   217,   219,   221,   223,   225,   227,   229,
-     231,   233,   234
+      81,    83,    85,    87,    89,    91,    93,    96,    99,   103,
+     107,   110,   112,   114,   115,   117,   121,   122,   126,   127,
+     131,   135,   139,   141,   143,   145,   146,   148,   150,   153,
+     155,   157,   160,   163,   167,   169,   172,   174,   177,   179,
+     182,   185,   186,   190,   192,   196,   199,   200,   203,   206,
+     210,   214,   218,   220,   222,   223,   225,   227,   229,   231,
+     233,   235,   237,   239,   240
 };
 
 /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
@@ -629,21 +629,22 @@ static const yytype_int8 yyrhs[] =
       -1,    34,    -1,    35,    48,     3,    -1,    36,    45,    -1,
       37,    -1,    38,     3,    -1,    39,     3,    -1,    41,    80,
       -1,    42,    -1,    43,    -1,    44,    -1,    54,    -1,    66,
-      -1,    63,    -1,    40,    83,    -1,     8,    45,    69,    -1,
-       9,    45,    69,    -1,    19,    -1,    32,    -1,    -1,    49,
-      -1,    56,    62,    45,    -1,    -1,     6,    64,    71,    -1,
-      -1,     5,    65,    71,    -1,     7,    55,    69,    -1,    67,
-      68,    69,    -1,    10,    -1,    11,    -1,    12,    -1,    -1,
-      55,    -1,    83,    -1,    69,    83,    -1,    55,    -1,    81,
-      -1,    81,     4,    -1,    81,    84,    -1,    81,     4,    84,
-      -1,    70,    -1,    71,    70,    -1,    73,    -1,    72,    73,
-      -1,    74,    -1,    61,    54,    -1,     1,    54,    -1,    -1,
-      82,    75,    76,    -1,    77,    -1,    76,    52,    77,    -1,
-      76,    54,    -1,    -1,    77,    83,    -1,    77,    45,    -1,
-      77,    13,    83,    -1,    77,    14,     4,    -1,    77,    15,
-      55,    -1,     3,    -1,    80,    -1,    -1,    78,    -1,    45,
-      -1,    49,    -1,    46,    -1,    50,    -1,    81,    -1,    84,
-      -1,     3,    -1,    -1,    51,    47,    -1
+      -1,    63,    -1,    40,    83,    -1,     8,    45,    -1,     8,
+      45,    69,    -1,     9,    45,    69,    -1,     9,    45,    -1,
+      19,    -1,    32,    -1,    -1,    49,    -1,    56,    62,    45,
+      -1,    -1,     6,    64,    71,    -1,    -1,     5,    65,    71,
+      -1,     7,    55,    69,    -1,    67,    68,    69,    -1,    10,
+      -1,    11,    -1,    12,    -1,    -1,    55,    -1,    83,    -1,
+      69,    83,    -1,    55,    -1,    81,    -1,    81,     4,    -1,
+      81,    84,    -1,    81,     4,    84,    -1,    70,    -1,    71,
+      70,    -1,    73,    -1,    72,    73,    -1,    74,    -1,    61,
+      54,    -1,     1,    54,    -1,    -1,    82,    75,    76,    -1,
+      77,    -1,    76,    52,    77,    -1,    76,    54,    -1,    -1,
+      77,    83,    -1,    77,    45,    -1,    77,    13,    83,    -1,
+      77,    14,     4,    -1,    77,    15,    55,    -1,     3,    -1,
+      80,    -1,    -1,    78,    -1,    45,    -1,    49,    -1,    46,
+      -1,    50,    -1,    81,    -1,    84,    -1,     3,    -1,    -1,
+      51,    47,    -1
 };
 
 /* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
@@ -652,13 +653,13 @@ static const yytype_uint16 yyrline[] =
        0,   205,   205,   213,   215,   219,   220,   221,   222,   223,
      224,   225,   226,   227,   228,   229,   230,   231,   236,   240,
      241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
-     251,   252,   253,   254,   258,   259,   260,   264,   272,   280,
-     284,   298,   299,   303,   331,   331,   336,   336,   341,   352,
-     367,   368,   369,   373,   374,   379,   380,   385,   390,   395,
-     401,   407,   418,   419,   428,   429,   435,   436,   437,   444,
-     444,   448,   449,   450,   455,   456,   458,   460,   462,   464,
-     474,   475,   481,   485,   490,   506,   508,   517,   522,   523,
-     528,   535,   537
+     251,   252,   253,   254,   258,   259,   260,   264,   268,   276,
+     284,   288,   292,   306,   307,   311,   339,   339,   344,   344,
+     349,   360,   375,   376,   377,   381,   382,   387,   388,   393,
+     398,   403,   409,   415,   426,   427,   436,   437,   443,   444,
+     445,   452,   452,   456,   457,   458,   463,   464,   466,   468,
+     470,   472,   482,   483,   489,   493,   498,   514,   516,   525,
+     530,   531,   536,   543,   545
 };
 #endif
 
@@ -711,12 +712,12 @@ static const yytype_uint8 yyr1[] =
       60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
       60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
       60,    60,    60,    60,    61,    61,    61,    61,    61,    61,
-      61,    62,    62,    61,    64,    63,    65,    63,    63,    66,
-      67,    67,    67,    68,    68,    69,    69,    70,    70,    70,
-      70,    70,    71,    71,    72,    72,    73,    73,    73,    75,
-      74,    76,    76,    76,    77,    77,    77,    77,    77,    77,
-      78,    78,    79,    79,    80,    81,    81,    82,    83,    83,
-      84,    85,    85
+      61,    61,    61,    62,    62,    61,    64,    63,    65,    63,
+      63,    66,    67,    67,    67,    68,    68,    69,    69,    70,
+      70,    70,    70,    70,    71,    71,    72,    72,    73,    73,
+      73,    75,    74,    76,    76,    76,    77,    77,    77,    77,
+      77,    77,    78,    78,    79,    79,    80,    81,    81,    82,
+      83,    83,    84,    85,    85
 };
 
 /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
@@ -725,13 +726,13 @@ static const yytype_uint8 yyr2[] =
        0,     2,     4,     0,     2,     1,     1,     2,     2,     1,
        3,     1,     2,     1,     2,     2,     3,     1,     2,     2,
        1,     3,     1,     1,     3,     2,     1,     2,     2,     2,
-       1,     1,     1,     1,     1,     1,     2,     3,     3,     1,
-       1,     0,     1,     3,     0,     3,     0,     3,     3,     3,
-       1,     1,     1,     0,     1,     1,     2,     1,     1,     2,
-       2,     3,     1,     2,     1,     2,     1,     2,     2,     0,
-       3,     1,     3,     2,     0,     2,     2,     3,     3,     3,
-       1,     1,     0,     1,     1,     1,     1,     1,     1,     1,
-       1,     0,     2
+       1,     1,     1,     1,     1,     1,     2,     2,     3,     3,
+       2,     1,     1,     0,     1,     3,     0,     3,     0,     3,
+       3,     3,     1,     1,     1,     0,     1,     1,     2,     1,
+       1,     2,     2,     3,     1,     2,     1,     2,     1,     2,
+       2,     0,     3,     1,     3,     2,     0,     2,     2,     3,
+       3,     3,     1,     1,     0,     1,     1,     1,     1,     1,
+       1,     1,     1,     0,     2
 };
 
 /* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
@@ -739,20 +740,20 @@ static const yytype_uint8 yyr2[] =
    means the default is an error.  */
 static const yytype_uint8 yydefact[] =
 {
-       3,     0,     0,     1,    46,    44,     0,     0,     0,    50,
-      51,    52,     0,     0,     9,    39,     0,    11,     0,    13,
-       0,     0,     0,    17,     0,     0,    20,     0,    40,    22,
+       3,     0,     0,     1,    48,    46,     0,     0,     0,    52,
+      53,    54,     0,     0,     9,    41,     0,    11,     0,    13,
+       0,     0,     0,    17,     0,     0,    20,     0,    42,    22,
       23,     0,     0,    26,     0,     0,     0,     0,    30,    31,
-      32,     0,     6,    33,    41,     4,     5,    35,    34,    53,
-       0,     0,     0,     0,     0,    84,     7,     8,    82,    12,
+      32,     0,     6,    33,    43,     4,     5,    35,    34,    55,
+       0,     0,     0,    37,    40,    86,     7,     8,    84,    12,
       14,    15,     0,    18,    19,     0,     0,    25,    27,    28,
-      90,    86,    85,    88,    36,    89,    29,     0,    87,     0,
-       0,    64,    66,    69,    42,     0,    54,     0,    57,    62,
-      47,    58,    45,    48,    55,    37,    38,    80,    83,    10,
-      81,    16,    21,    24,    68,    67,     0,    65,     2,    74,
-      43,    49,    63,    59,    60,    56,    92,    70,    71,    61,
-      74,    73,     0,     0,     0,    76,    75,    72,    77,    78,
-      79
+      92,    88,    87,    90,    36,    91,    29,     0,    89,     0,
+       0,    66,    68,    71,    44,     0,    56,     0,    59,    64,
+      49,    60,    47,    50,    57,    38,    39,    82,    85,    10,
+      83,    16,    21,    24,    70,    69,     0,    67,     2,    76,
+      45,    51,    65,    61,    62,    58,    94,    72,    73,    63,
+      76,    75,     0,     0,     0,    78,    77,    74,    79,    80,
+      81
 };
 
 /* YYDEFGOTO[NTERM-NUM].  */
@@ -796,10 +797,10 @@ static const yytype_int8 yypgoto[] =
    positive, shift that token.  If negative, reduce the rule which
    number is the opposite.  If zero, do what YYDEFACT says.
    If YYTABLE_NINF, syntax error.  */
-#define YYTABLE_NINF -92
+#define YYTABLE_NINF -94
 static const yytype_int16 yytable[] =
 {
-      74,   114,   -91,    77,    95,    96,    97,     4,     5,     6,
+      74,   114,   -93,    77,    95,    96,    97,     4,     5,     6,
        7,     8,     9,    10,    11,    71,    52,    57,    72,    70,
      113,    15,    59,   119,    88,   120,   112,   121,   112,     3,
       70,    53,    54,    55,    28,    70,    58,    62,   111,    60,
@@ -1009,112 +1010,112 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 #line 183 "parse-gram.y"
 	{ fputs (quotearg_style (c_quoting_style, (yyvaluep->chars)), stderr); };
 /* Line 670 of yacc.c.  */
-#line 1013 "parse-gram.c"
+#line 1014 "parse-gram.c"
 	break;
       case 4: /* "\"integer\"" */
 /* Line 670 of yacc.c.  */
 #line 194 "parse-gram.y"
 	{ fprintf (stderr, "%d", (yyvaluep->integer)); };
 /* Line 670 of yacc.c.  */
-#line 1020 "parse-gram.c"
+#line 1021 "parse-gram.c"
 	break;
       case 45: /* "\"{...}\"" */
 /* Line 670 of yacc.c.  */
 #line 185 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 /* Line 670 of yacc.c.  */
-#line 1027 "parse-gram.c"
+#line 1028 "parse-gram.c"
 	break;
       case 46: /* "\"char\"" */
 /* Line 670 of yacc.c.  */
 #line 178 "parse-gram.y"
 	{ fputs (char_name ((yyvaluep->character)), stderr); };
 /* Line 670 of yacc.c.  */
-#line 1034 "parse-gram.c"
+#line 1035 "parse-gram.c"
 	break;
       case 47: /* "\"epilogue\"" */
 /* Line 670 of yacc.c.  */
 #line 185 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 /* Line 670 of yacc.c.  */
-#line 1041 "parse-gram.c"
+#line 1042 "parse-gram.c"
 	break;
       case 49: /* "\"identifier\"" */
 /* Line 670 of yacc.c.  */
 #line 190 "parse-gram.y"
 	{ fputs ((yyvaluep->uniqstr), stderr); };
 /* Line 670 of yacc.c.  */
-#line 1048 "parse-gram.c"
+#line 1049 "parse-gram.c"
 	break;
       case 50: /* "\"identifier:\"" */
 /* Line 670 of yacc.c.  */
 #line 191 "parse-gram.y"
 	{ fprintf (stderr, "%s:", (yyvaluep->uniqstr)); };
 /* Line 670 of yacc.c.  */
-#line 1055 "parse-gram.c"
+#line 1056 "parse-gram.c"
 	break;
       case 53: /* "\"%{...%}\"" */
 /* Line 670 of yacc.c.  */
 #line 185 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 /* Line 670 of yacc.c.  */
-#line 1062 "parse-gram.c"
+#line 1063 "parse-gram.c"
 	break;
       case 55: /* "\"type\"" */
 /* Line 670 of yacc.c.  */
 #line 189 "parse-gram.y"
 	{ fprintf (stderr, "<%s>", (yyvaluep->uniqstr)); };
 /* Line 670 of yacc.c.  */
-#line 1069 "parse-gram.c"
+#line 1070 "parse-gram.c"
 	break;
       case 78: /* "content" */
 /* Line 670 of yacc.c.  */
 #line 185 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 /* Line 670 of yacc.c.  */
-#line 1076 "parse-gram.c"
+#line 1077 "parse-gram.c"
 	break;
       case 79: /* "content.opt" */
 /* Line 670 of yacc.c.  */
 #line 185 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 /* Line 670 of yacc.c.  */
-#line 1083 "parse-gram.c"
+#line 1084 "parse-gram.c"
 	break;
       case 80: /* "braceless" */
 /* Line 670 of yacc.c.  */
 #line 185 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 /* Line 670 of yacc.c.  */
-#line 1090 "parse-gram.c"
+#line 1091 "parse-gram.c"
 	break;
       case 81: /* "id" */
 /* Line 670 of yacc.c.  */
 #line 197 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 /* Line 670 of yacc.c.  */
-#line 1097 "parse-gram.c"
+#line 1098 "parse-gram.c"
 	break;
       case 82: /* "id_colon" */
 /* Line 670 of yacc.c.  */
 #line 198 "parse-gram.y"
 	{ fprintf (stderr, "%s:", (yyvaluep->symbol)->tag); };
 /* Line 670 of yacc.c.  */
-#line 1104 "parse-gram.c"
+#line 1105 "parse-gram.c"
 	break;
       case 83: /* "symbol" */
 /* Line 670 of yacc.c.  */
 #line 197 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 /* Line 670 of yacc.c.  */
-#line 1111 "parse-gram.c"
+#line 1112 "parse-gram.c"
 	break;
       case 84: /* "string_as_id" */
 /* Line 670 of yacc.c.  */
 #line 197 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 /* Line 670 of yacc.c.  */
-#line 1118 "parse-gram.c"
+#line 1119 "parse-gram.c"
 	break;
       default:
 	break;
@@ -1636,7 +1637,7 @@ YYLTYPE yylloc;
   boundary_set (&yylloc.end, current_file, 1, 1);
 }
 /* Line 1082 of yacc.c.  */
-#line 1640 "parse-gram.c"
+#line 1641 "parse-gram.c"
   yylsp[0] = yylloc;
   goto yysetstate;
 
@@ -1718,6 +1719,9 @@ YYLTYPE yylloc;
 
   YYDPRINTF ((stderr, "Entering state %d\n", yystate));
 
+  if (yystate == YYFINAL)
+    YYACCEPT;
+
   goto yybackup;
 
 /*-----------.
@@ -1767,9 +1771,6 @@ yybackup:
       goto yyreduce;
     }
 
-  if (yyn == YYFINAL)
-    YYACCEPT;
-
   /* Count tokens shifted since error; after three, turn off error
      status.  */
   if (yyerrstatus)
@@ -1778,9 +1779,8 @@ yybackup:
   /* Shift the lookahead token.  */
   YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
 
-  /* Discard the shifted token unless it is eof.  */
-  if (yychar != YYEOF)
-    yychar = YYEMPTY;
+  /* Discard the shifted token.  */
+  yychar = YYEMPTY;
 
   yystate = yyn;
   *++yyvsp = yylval;
@@ -1821,73 +1821,73 @@ yyreduce:
   switch (yyn)
     {
         case 6:
-/* Line 1270 of yacc.c.  */
+/* Line 1269 of yacc.c.  */
 #line 220 "parse-gram.y"
     { prologue_augment (translate_code ((yyvsp[(1) - (1)].chars), (yylsp[(1) - (1)])), (yylsp[(1) - (1)]), union_seen); }
     break;
 
   case 7:
-/* Line 1270 of yacc.c.  */
+/* Line 1269 of yacc.c.  */
 #line 221 "parse-gram.y"
     { prologue_augment ((yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)]), true); }
     break;
 
   case 8:
-/* Line 1270 of yacc.c.  */
+/* Line 1269 of yacc.c.  */
 #line 222 "parse-gram.y"
     { prologue_augment ((yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)]), false); }
     break;
 
   case 9:
-/* Line 1270 of yacc.c.  */
+/* Line 1269 of yacc.c.  */
 #line 223 "parse-gram.y"
     { debug_flag = true; }
     break;
 
   case 10:
-/* Line 1270 of yacc.c.  */
+/* Line 1269 of yacc.c.  */
 #line 224 "parse-gram.y"
     { muscle_insert ((yyvsp[(2) - (3)].chars), (yyvsp[(3) - (3)].chars)); }
     break;
 
   case 11:
-/* Line 1270 of yacc.c.  */
+/* Line 1269 of yacc.c.  */
 #line 225 "parse-gram.y"
     { defines_flag = true; }
     break;
 
   case 12:
-/* Line 1270 of yacc.c.  */
+/* Line 1269 of yacc.c.  */
 #line 226 "parse-gram.y"
     { muscle_code_grow ("end_header", (yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])); }
     break;
 
   case 13:
-/* Line 1270 of yacc.c.  */
+/* Line 1269 of yacc.c.  */
 #line 227 "parse-gram.y"
     { error_verbose = true; }
     break;
 
   case 14:
-/* Line 1270 of yacc.c.  */
+/* Line 1269 of yacc.c.  */
 #line 228 "parse-gram.y"
     { expected_sr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 15:
-/* Line 1270 of yacc.c.  */
+/* Line 1269 of yacc.c.  */
 #line 229 "parse-gram.y"
     { expected_rr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 16:
-/* Line 1270 of yacc.c.  */
+/* Line 1269 of yacc.c.  */
 #line 230 "parse-gram.y"
     { spec_file_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 17:
-/* Line 1270 of yacc.c.  */
+/* Line 1269 of yacc.c.  */
 #line 232 "parse-gram.y"
     {
       nondeterministic_parser = true;
@@ -1896,7 +1896,7 @@ yyreduce:
     break;
 
   case 18:
-/* Line 1270 of yacc.c.  */
+/* Line 1269 of yacc.c.  */
 #line 237 "parse-gram.y"
     {
       muscle_code_grow ("initial_action", translate_symbol_action ((yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])), (yylsp[(2) - (2)]));
@@ -1904,91 +1904,91 @@ yyreduce:
     break;
 
   case 19:
-/* Line 1270 of yacc.c.  */
+/* Line 1269 of yacc.c.  */
 #line 240 "parse-gram.y"
     { add_param ("lex_param", (yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])); }
     break;
 
   case 20:
-/* Line 1270 of yacc.c.  */
+/* Line 1269 of yacc.c.  */
 #line 241 "parse-gram.y"
     { locations_flag = true; }
     break;
 
   case 21:
-/* Line 1270 of yacc.c.  */
+/* Line 1269 of yacc.c.  */
 #line 242 "parse-gram.y"
     { spec_name_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 22:
-/* Line 1270 of yacc.c.  */
+/* Line 1269 of yacc.c.  */
 #line 243 "parse-gram.y"
     { no_lines_flag = true; }
     break;
 
   case 23:
-/* Line 1270 of yacc.c.  */
+/* Line 1269 of yacc.c.  */
 #line 244 "parse-gram.y"
     { nondeterministic_parser = true; }
     break;
 
   case 24:
-/* Line 1270 of yacc.c.  */
+/* Line 1269 of yacc.c.  */
 #line 245 "parse-gram.y"
     { spec_outfile = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 25:
-/* Line 1270 of yacc.c.  */
+/* Line 1269 of yacc.c.  */
 #line 246 "parse-gram.y"
     { add_param ("parse_param", (yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])); }
     break;
 
   case 26:
-/* Line 1270 of yacc.c.  */
+/* Line 1269 of yacc.c.  */
 #line 247 "parse-gram.y"
     { pure_parser = true; }
     break;
 
   case 27:
-/* Line 1270 of yacc.c.  */
+/* Line 1269 of yacc.c.  */
 #line 248 "parse-gram.y"
     { version_check (&(yylsp[(2) - (2)]), (yyvsp[(2) - (2)].chars)); }
     break;
 
   case 28:
-/* Line 1270 of yacc.c.  */
+/* Line 1269 of yacc.c.  */
 #line 249 "parse-gram.y"
     { skeleton = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 29:
-/* Line 1270 of yacc.c.  */
+/* Line 1269 of yacc.c.  */
 #line 250 "parse-gram.y"
     { muscle_code_grow ("start_header", (yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])); }
     break;
 
   case 30:
-/* Line 1270 of yacc.c.  */
+/* Line 1269 of yacc.c.  */
 #line 251 "parse-gram.y"
     { token_table_flag = true; }
     break;
 
   case 31:
-/* Line 1270 of yacc.c.  */
+/* Line 1269 of yacc.c.  */
 #line 252 "parse-gram.y"
     { report_flag = report_states; }
     break;
 
   case 32:
-/* Line 1270 of yacc.c.  */
+/* Line 1269 of yacc.c.  */
 #line 253 "parse-gram.y"
     { yacc_flag = true; }
     break;
 
   case 36:
-/* Line 1270 of yacc.c.  */
+/* Line 1269 of yacc.c.  */
 #line 261 "parse-gram.y"
     {
       grammar_start_symbol_set ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]));
@@ -1996,8 +1996,16 @@ yyreduce:
     break;
 
   case 37:
-/* Line 1270 of yacc.c.  */
+/* Line 1269 of yacc.c.  */
 #line 265 "parse-gram.y"
+    {
+      default_destructor_set (translate_symbol_action ((yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])), (yylsp[(2) - (2)]));
+    }
+    break;
+
+  case 38:
+/* Line 1269 of yacc.c.  */
+#line 269 "parse-gram.y"
     {
       symbol_list *list;
       const char *action = translate_symbol_action ((yyvsp[(2) - (3)].chars), (yylsp[(2) - (3)]));
@@ -2007,9 +2015,9 @@ yyreduce:
     }
     break;
 
-  case 38:
-/* Line 1270 of yacc.c.  */
-#line 273 "parse-gram.y"
+  case 39:
+/* Line 1269 of yacc.c.  */
+#line 277 "parse-gram.y"
     {
       symbol_list *list;
       const char *action = translate_symbol_action ((yyvsp[(2) - (3)].chars), (yylsp[(2) - (3)]));
@@ -2019,37 +2027,45 @@ yyreduce:
     }
     break;
 
-  case 39:
-/* Line 1270 of yacc.c.  */
-#line 281 "parse-gram.y"
+  case 40:
+/* Line 1269 of yacc.c.  */
+#line 285 "parse-gram.y"
+    {
+      default_printer_set (translate_symbol_action ((yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])), (yylsp[(2) - (2)]));
+    }
+    break;
+
+  case 41:
+/* Line 1269 of yacc.c.  */
+#line 289 "parse-gram.y"
     {
       default_prec = true;
     }
     break;
 
-  case 40:
-/* Line 1270 of yacc.c.  */
-#line 285 "parse-gram.y"
+  case 42:
+/* Line 1269 of yacc.c.  */
+#line 293 "parse-gram.y"
     {
       default_prec = false;
     }
     break;
 
-  case 41:
-/* Line 1270 of yacc.c.  */
-#line 298 "parse-gram.y"
+  case 43:
+/* Line 1269 of yacc.c.  */
+#line 306 "parse-gram.y"
     {}
     break;
 
-  case 42:
-/* Line 1270 of yacc.c.  */
-#line 299 "parse-gram.y"
+  case 44:
+/* Line 1269 of yacc.c.  */
+#line 307 "parse-gram.y"
     { muscle_code_grow ("union_name", (yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
-  case 43:
-/* Line 1270 of yacc.c.  */
-#line 304 "parse-gram.y"
+  case 45:
+/* Line 1269 of yacc.c.  */
+#line 312 "parse-gram.y"
     {
       char const *body = (yyvsp[(3) - (3)].chars);
 
@@ -2073,39 +2089,39 @@ yyreduce:
     }
     break;
 
-  case 44:
-/* Line 1270 of yacc.c.  */
-#line 331 "parse-gram.y"
+  case 46:
+/* Line 1269 of yacc.c.  */
+#line 339 "parse-gram.y"
     { current_class = nterm_sym; }
     break;
 
-  case 45:
-/* Line 1270 of yacc.c.  */
-#line 332 "parse-gram.y"
+  case 47:
+/* Line 1269 of yacc.c.  */
+#line 340 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
     break;
 
-  case 46:
-/* Line 1270 of yacc.c.  */
-#line 336 "parse-gram.y"
+  case 48:
+/* Line 1269 of yacc.c.  */
+#line 344 "parse-gram.y"
     { current_class = token_sym; }
     break;
 
-  case 47:
-/* Line 1270 of yacc.c.  */
-#line 337 "parse-gram.y"
+  case 49:
+/* Line 1269 of yacc.c.  */
+#line 345 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
     break;
 
-  case 48:
-/* Line 1270 of yacc.c.  */
-#line 342 "parse-gram.y"
+  case 50:
+/* Line 1269 of yacc.c.  */
+#line 350 "parse-gram.y"
     {
       tag_seen = true;
       symbol_list *list;
@@ -2115,9 +2131,9 @@ yyreduce:
     }
     break;
 
-  case 49:
-/* Line 1270 of yacc.c.  */
-#line 353 "parse-gram.y"
+  case 51:
+/* Line 1269 of yacc.c.  */
+#line 361 "parse-gram.y"
     {
       symbol_list *list;
       ++current_prec;
@@ -2131,69 +2147,69 @@ yyreduce:
     }
     break;
 
-  case 50:
-/* Line 1270 of yacc.c.  */
-#line 367 "parse-gram.y"
+  case 52:
+/* Line 1269 of yacc.c.  */
+#line 375 "parse-gram.y"
     { (yyval.assoc) = left_assoc; }
     break;
 
-  case 51:
-/* Line 1270 of yacc.c.  */
-#line 368 "parse-gram.y"
+  case 53:
+/* Line 1269 of yacc.c.  */
+#line 376 "parse-gram.y"
     { (yyval.assoc) = right_assoc; }
     break;
 
-  case 52:
-/* Line 1270 of yacc.c.  */
-#line 369 "parse-gram.y"
+  case 54:
+/* Line 1269 of yacc.c.  */
+#line 377 "parse-gram.y"
     { (yyval.assoc) = non_assoc; }
     break;
 
-  case 53:
-/* Line 1270 of yacc.c.  */
-#line 373 "parse-gram.y"
+  case 55:
+/* Line 1269 of yacc.c.  */
+#line 381 "parse-gram.y"
     { current_type = NULL; }
     break;
 
-  case 54:
-/* Line 1270 of yacc.c.  */
-#line 374 "parse-gram.y"
+  case 56:
+/* Line 1269 of yacc.c.  */
+#line 382 "parse-gram.y"
     { current_type = (yyvsp[(1) - (1)].uniqstr); tag_seen = true; }
     break;
 
-  case 55:
-/* Line 1270 of yacc.c.  */
-#line 379 "parse-gram.y"
+  case 57:
+/* Line 1269 of yacc.c.  */
+#line 387 "parse-gram.y"
     { (yyval.list) = symbol_list_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
-  case 56:
-/* Line 1270 of yacc.c.  */
-#line 380 "parse-gram.y"
+  case 58:
+/* Line 1269 of yacc.c.  */
+#line 388 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), (yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)])); }
     break;
 
-  case 57:
-/* Line 1270 of yacc.c.  */
-#line 386 "parse-gram.y"
+  case 59:
+/* Line 1269 of yacc.c.  */
+#line 394 "parse-gram.y"
     {
        current_type = (yyvsp[(1) - (1)].uniqstr);
        tag_seen = true;
      }
     break;
 
-  case 58:
-/* Line 1270 of yacc.c.  */
-#line 391 "parse-gram.y"
+  case 60:
+/* Line 1269 of yacc.c.  */
+#line 399 "parse-gram.y"
     {
        symbol_class_set ((yyvsp[(1) - (1)].symbol), current_class, (yylsp[(1) - (1)]), true);
        symbol_type_set ((yyvsp[(1) - (1)].symbol), current_type, (yylsp[(1) - (1)]));
      }
     break;
 
-  case 59:
-/* Line 1270 of yacc.c.  */
-#line 396 "parse-gram.y"
+  case 61:
+/* Line 1269 of yacc.c.  */
+#line 404 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
       symbol_type_set ((yyvsp[(1) - (2)].symbol), current_type, (yylsp[(1) - (2)]));
@@ -2201,9 +2217,9 @@ yyreduce:
     }
     break;
 
-  case 60:
-/* Line 1270 of yacc.c.  */
-#line 402 "parse-gram.y"
+  case 62:
+/* Line 1269 of yacc.c.  */
+#line 410 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
       symbol_type_set ((yyvsp[(1) - (2)].symbol), current_type, (yylsp[(1) - (2)]));
@@ -2211,9 +2227,9 @@ yyreduce:
     }
     break;
 
-  case 61:
-/* Line 1270 of yacc.c.  */
-#line 408 "parse-gram.y"
+  case 63:
+/* Line 1269 of yacc.c.  */
+#line 416 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (3)].symbol), current_class, (yylsp[(1) - (3)]), true);
       symbol_type_set ((yyvsp[(1) - (3)].symbol), current_type, (yylsp[(1) - (3)]));
@@ -2222,95 +2238,95 @@ yyreduce:
     }
     break;
 
-  case 68:
-/* Line 1270 of yacc.c.  */
-#line 438 "parse-gram.y"
+  case 70:
+/* Line 1269 of yacc.c.  */
+#line 446 "parse-gram.y"
     {
       yyerrok;
     }
     break;
 
-  case 69:
-/* Line 1270 of yacc.c.  */
-#line 444 "parse-gram.y"
+  case 71:
+/* Line 1269 of yacc.c.  */
+#line 452 "parse-gram.y"
     { current_lhs = (yyvsp[(1) - (1)].symbol); current_lhs_location = (yylsp[(1) - (1)]); }
     break;
 
-  case 71:
-/* Line 1270 of yacc.c.  */
-#line 448 "parse-gram.y"
+  case 73:
+/* Line 1269 of yacc.c.  */
+#line 456 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(1) - (1)])); }
     break;
 
-  case 72:
-/* Line 1270 of yacc.c.  */
-#line 449 "parse-gram.y"
+  case 74:
+/* Line 1269 of yacc.c.  */
+#line 457 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(3) - (3)])); }
     break;
 
-  case 74:
-/* Line 1270 of yacc.c.  */
-#line 455 "parse-gram.y"
+  case 76:
+/* Line 1269 of yacc.c.  */
+#line 463 "parse-gram.y"
     { grammar_current_rule_begin (current_lhs, current_lhs_location); }
     break;
 
-  case 75:
-/* Line 1270 of yacc.c.  */
-#line 457 "parse-gram.y"
+  case 77:
+/* Line 1269 of yacc.c.  */
+#line 465 "parse-gram.y"
     { grammar_current_rule_symbol_append ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)])); }
     break;
 
-  case 76:
-/* Line 1270 of yacc.c.  */
-#line 459 "parse-gram.y"
+  case 78:
+/* Line 1269 of yacc.c.  */
+#line 467 "parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])); }
     break;
 
-  case 77:
-/* Line 1270 of yacc.c.  */
-#line 461 "parse-gram.y"
+  case 79:
+/* Line 1269 of yacc.c.  */
+#line 469 "parse-gram.y"
     { grammar_current_rule_prec_set ((yyvsp[(3) - (3)].symbol), (yylsp[(3) - (3)])); }
     break;
 
-  case 78:
-/* Line 1270 of yacc.c.  */
-#line 463 "parse-gram.y"
+  case 80:
+/* Line 1269 of yacc.c.  */
+#line 471 "parse-gram.y"
     { grammar_current_rule_dprec_set ((yyvsp[(3) - (3)].integer), (yylsp[(3) - (3)])); }
     break;
 
-  case 79:
-/* Line 1270 of yacc.c.  */
-#line 465 "parse-gram.y"
+  case 81:
+/* Line 1269 of yacc.c.  */
+#line 473 "parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[(3) - (3)].uniqstr), (yylsp[(3) - (3)])); }
     break;
 
-  case 82:
-/* Line 1270 of yacc.c.  */
-#line 481 "parse-gram.y"
+  case 84:
+/* Line 1269 of yacc.c.  */
+#line 489 "parse-gram.y"
     {
       static char one[] = "1";
       (yyval.chars) = one;
     }
     break;
 
-  case 84:
-/* Line 1270 of yacc.c.  */
-#line 491 "parse-gram.y"
+  case 86:
+/* Line 1269 of yacc.c.  */
+#line 499 "parse-gram.y"
     {
       (yyvsp[(1) - (1)].chars)[strlen ((yyvsp[(1) - (1)].chars)) - 1] = '\n';
       (yyval.chars) = translate_code ((yyvsp[(1) - (1)].chars) + 1, (yylsp[(1) - (1)]));
     }
     break;
 
-  case 85:
-/* Line 1270 of yacc.c.  */
-#line 507 "parse-gram.y"
+  case 87:
+/* Line 1269 of yacc.c.  */
+#line 515 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
-  case 86:
-/* Line 1270 of yacc.c.  */
-#line 509 "parse-gram.y"
+  case 88:
+/* Line 1269 of yacc.c.  */
+#line 517 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[(1) - (1)].character)), (yylsp[(1) - (1)]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[(1) - (1)]), false);
@@ -2318,24 +2334,24 @@ yyreduce:
     }
     break;
 
-  case 87:
-/* Line 1270 of yacc.c.  */
-#line 517 "parse-gram.y"
+  case 89:
+/* Line 1269 of yacc.c.  */
+#line 525 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
-  case 90:
-/* Line 1270 of yacc.c.  */
-#line 529 "parse-gram.y"
+  case 92:
+/* Line 1269 of yacc.c.  */
+#line 537 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[(1) - (1)].chars)), (yylsp[(1) - (1)]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[(1) - (1)]), false);
     }
     break;
 
-  case 92:
-/* Line 1270 of yacc.c.  */
-#line 538 "parse-gram.y"
+  case 94:
+/* Line 1269 of yacc.c.  */
+#line 546 "parse-gram.y"
     {
       muscle_code_grow ("epilogue", translate_code ((yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])), (yylsp[(2) - (2)]));
       gram_scanner_last_string_free ();
@@ -2343,8 +2359,8 @@ yyreduce:
     break;
 
 
-/* Line 1270 of yacc.c.  */
-#line 2348 "parse-gram.c"
+/* Line 1269 of yacc.c.  */
+#line 2364 "parse-gram.c"
       default: break;
     }
   YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);
@@ -2495,9 +2511,6 @@ yyerrlab1:
       YY_STACK_PRINT (yyss, yyssp);
     }
 
-  if (yyn == YYFINAL)
-    YYACCEPT;
-
   *++yyvsp = yylval;
 
   yyerror_range[1] = yylloc;
@@ -2538,7 +2551,7 @@ yyexhaustedlab:
 #endif
 
 yyreturn:
-  if (yychar != YYEOF && yychar != YYEMPTY)
+  if (yychar != YYEMPTY)
      yydestruct ("Cleanup: discarding lookahead",
 		 yytoken, &yylval, &yylloc);
   /* Do not reclaim the symbols of the rule which action triggered
@@ -2564,8 +2577,8 @@ yyreturn:
 }
 
 
-/* Line 1490 of yacc.c.  */
-#line 544 "parse-gram.y"
+/* Line 1486 of yacc.c.  */
+#line 552 "parse-gram.y"
 
 
 
