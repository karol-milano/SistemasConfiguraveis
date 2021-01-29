@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 2.4.170-dd704.  */
+/* A Bison parser, made by GNU Bison 2.4.194-c20a1-dirty.  */
 
 /* Implementation for Bison's Yacc-like parsers in C
 
@@ -45,7 +45,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "2.4.170-dd704"
+#define YYBISON_VERSION "2.4.194-c20a1-dirty"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -615,56 +615,6 @@ static const yytype_uint8 yytranslate[] =
 };
 
 #if YYDEBUG
-/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
-   YYRHS.  */
-static const yytype_uint16 yyprhs[] =
-{
-       0,     0,     3,     8,     9,    12,    14,    16,    18,    22,
-      24,    27,    29,    32,    35,    38,    42,    44,    47,    50,
-      53,    55,    58,    62,    64,    66,    69,    73,    76,    78,
-      81,    84,    86,    88,    90,    92,    94,    96,    99,   103,
-     107,   109,   111,   114,   118,   119,   121,   125,   126,   130,
-     131,   135,   139,   143,   145,   147,   149,   151,   152,   154,
-     156,   159,   161,   164,   166,   169,   171,   174,   176,   178,
-     180,   182,   184,   186,   189,   192,   196,   198,   201,   203,
-     206,   208,   211,   214,   215,   219,   221,   225,   228,   229,
-     232,   235,   239,   243,   247,   249,   251,   252,   254,   256,
-     258,   260,   262,   264,   266,   268,   269
-};
-
-/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
-static const yytype_int8 yyrhs[] =
-{
-      59,     0,    -1,    60,    50,    77,    90,    -1,    -1,    60,
-      61,    -1,    62,    -1,    52,    -1,    18,    -1,    20,    83,
-      84,    -1,    21,    -1,    21,     3,    -1,    22,    -1,    23,
-       4,    -1,    24,     4,    -1,    25,     3,    -1,    25,    47,
-       3,    -1,    26,    -1,    27,    44,    -1,    28,     3,    -1,
-      29,    44,    -1,    30,    -1,    31,     3,    -1,    31,    47,
-       3,    -1,    33,    -1,    34,    -1,    35,     3,    -1,    35,
-      47,     3,    -1,    36,    44,    -1,    37,    -1,    38,     3,
-      -1,    39,     3,    -1,    41,    -1,    42,    -1,    43,    -1,
-      53,    -1,    67,    -1,    64,    -1,    40,    88,    -1,     8,
-      44,    73,    -1,     9,    44,    73,    -1,    19,    -1,    32,
-      -1,    17,    85,    -1,    17,    48,    85,    -1,    -1,    48,
-      -1,    57,    63,    85,    -1,    -1,     6,    65,    76,    -1,
-      -1,     5,    66,    76,    -1,     7,    54,    72,    -1,    68,
-      69,    70,    -1,    10,    -1,    11,    -1,    12,    -1,    13,
-      -1,    -1,    54,    -1,    71,    -1,    70,    71,    -1,    88,
-      -1,    88,     4,    -1,    88,    -1,    72,    88,    -1,    74,
-      -1,    73,    74,    -1,    88,    -1,    54,    -1,    55,    -1,
-      56,    -1,    54,    -1,    86,    -1,    86,     4,    -1,    86,
-      89,    -1,    86,     4,    89,    -1,    75,    -1,    76,    75,
-      -1,    78,    -1,    77,    78,    -1,    79,    -1,    62,    53,
-      -1,     1,    53,    -1,    -1,    87,    80,    81,    -1,    82,
-      -1,    81,    51,    82,    -1,    81,    53,    -1,    -1,    82,
-      88,    -1,    82,    44,    -1,    82,    14,    88,    -1,    82,
-      15,     4,    -1,    82,    16,    54,    -1,    48,    -1,     3,
-      -1,    -1,     3,    -1,    44,    -1,    48,    -1,    45,    -1,
-      49,    -1,    86,    -1,    89,    -1,     3,    -1,    -1,    50,
-      46,    -1
-};
-
 /* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
 static const yytype_uint16 yyrline[] =
 {
@@ -726,41 +676,34 @@ static const yytype_uint16 yytoknum[] =
 };
 # endif
 
-/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
-static const yytype_uint8 yyr1[] =
-{
-       0,    58,    59,    60,    60,    61,    61,    61,    61,    61,
-      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
-      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
-      61,    61,    61,    61,    61,    62,    62,    62,    62,    62,
-      62,    62,    62,    62,    63,    63,    62,    65,    64,    66,
-      64,    64,    67,    68,    68,    68,    68,    69,    69,    70,
-      70,    71,    71,    72,    72,    73,    73,    74,    74,    74,
-      74,    75,    75,    75,    75,    75,    76,    76,    77,    77,
-      78,    78,    78,    80,    79,    81,    81,    81,    82,    82,
-      82,    82,    82,    82,    83,    83,    84,    84,    85,    86,
-      86,    87,    88,    88,    89,    90,    90
-};
+#define YYPACT_NINF -81
 
-/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
-static const yytype_uint8 yyr2[] =
+#define YYTABLE_NINF -106
+
+  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
+     STATE-NUM.    */
+static const yytype_int16 yypact[] =
 {
-       0,     2,     4,     0,     2,     1,     1,     1,     3,     1,
-       2,     1,     2,     2,     2,     3,     1,     2,     2,     2,
-       1,     2,     3,     1,     1,     2,     3,     2,     1,     2,
-       2,     1,     1,     1,     1,     1,     1,     2,     3,     3,
-       1,     1,     2,     3,     0,     1,     3,     0,     3,     0,
-       3,     3,     3,     1,     1,     1,     1,     0,     1,     1,
-       2,     1,     2,     1,     2,     1,     2,     1,     1,     1,
-       1,     1,     1,     2,     2,     3,     1,     2,     1,     2,
-       1,     2,     2,     0,     3,     1,     3,     2,     0,     2,
-       2,     3,     3,     3,     1,     1,     0,     1,     1,     1,
-       1,     1,     1,     1,     1,     0,     2
+     -81,    23,   111,   -81,   -81,   -81,   -28,   -12,    -8,   -81,
+     -81,   -81,   -81,   -13,   -81,   -81,    14,    43,   -81,    48,
+      49,     2,   -81,    10,    53,    34,   -81,    13,   -81,   -81,
+     -81,    26,    36,   -81,    54,    78,     0,   -81,   -81,   -81,
+      58,   -81,   -81,    41,   -81,   -81,   -81,   -81,    28,   -24,
+     -24,     0,    31,    31,   -81,    44,   -81,   -81,   -81,    81,
+     -81,   -81,   -81,   -81,    88,   -81,   -81,   -81,   -81,    89,
+     -81,    91,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,
+     -81,    42,   -81,    47,     1,   -81,   -81,   -81,   -81,    44,
+     -81,     0,   -81,   -81,   -24,    40,   -24,     0,   -81,   -81,
+     -81,   -81,    31,   -81,   -81,    31,   -81,   -81,   -81,   -81,
+     -81,   -81,   -81,   -81,    50,   -81,   -81,   -81,   -81,     0,
+     -81,    93,   -81,    98,   -81,   -81,   -81,   -81,   -14,   155,
+     -81,   -81,   -81,   -81,   -81,     0,    99,    51,   -81,   -81,
+     155,   -81,   -81,   -81
 };
 
-/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
-   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
-   means the default is an error.  */
+  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
+     does not specify something else to do.  Zero means the default is an
+     error.    */
 static const yytype_uint8 yydefact[] =
 {
        3,     0,     0,     1,    49,    47,     0,     0,     0,    53,
@@ -780,38 +723,7 @@ static const yytype_uint8 yydefact[] =
       86,    91,    92,    93
 };
 
-/* YYDEFGOTO[NTERM-NUM].  */
-static const yytype_int16 yydefgoto[] =
-{
-      -1,     1,     2,    44,    83,    89,    46,    50,    49,    47,
-      48,    91,   119,   120,    97,   102,   103,    93,    94,    84,
-      85,    86,   117,   128,   129,    59,   108,    56,    78,    87,
-     104,    80,   116
-};
-
-/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
-   STATE-NUM.  */
-#define YYPACT_NINF -81
-static const yytype_int16 yypact[] =
-{
-     -81,    23,   111,   -81,   -81,   -81,   -28,   -12,    -8,   -81,
-     -81,   -81,   -81,   -13,   -81,   -81,    14,    43,   -81,    48,
-      49,     2,   -81,    10,    53,    34,   -81,    13,   -81,   -81,
-     -81,    26,    36,   -81,    54,    78,     0,   -81,   -81,   -81,
-      58,   -81,   -81,    41,   -81,   -81,   -81,   -81,    28,   -24,
-     -24,     0,    31,    31,   -81,    44,   -81,   -81,   -81,    81,
-     -81,   -81,   -81,   -81,    88,   -81,   -81,   -81,   -81,    89,
-     -81,    91,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,
-     -81,    42,   -81,    47,     1,   -81,   -81,   -81,   -81,    44,
-     -81,     0,   -81,   -81,   -24,    40,   -24,     0,   -81,   -81,
-     -81,   -81,    31,   -81,   -81,    31,   -81,   -81,   -81,   -81,
-     -81,   -81,   -81,   -81,    50,   -81,   -81,   -81,   -81,     0,
-     -81,    93,   -81,    98,   -81,   -81,   -81,   -81,   -14,   155,
-     -81,   -81,   -81,   -81,   -81,     0,    99,    51,   -81,   -81,
-     155,   -81,   -81,   -81
-};
-
-/* YYPGOTO[NTERM-NUM].  */
+  /* YYPGOTO[NTERM-NUM].    */
 static const yytype_int8 yypgoto[] =
 {
      -81,   -81,   -81,   -81,   100,   -81,   -81,   -81,   -81,   -81,
@@ -820,11 +732,19 @@ static const yytype_int8 yypgoto[] =
      -36,   -76,   -81
 };
 
-/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
-   positive, shift that token.  If negative, reduce the rule which
-   number is the opposite.  If zero, do what YYDEFACT says.
-   If YYTABLE_NINF, syntax error.  */
-#define YYTABLE_NINF -106
+  /* YYDEFGOTO[NTERM-NUM].    */
+static const yytype_int16 yydefgoto[] =
+{
+      -1,     1,     2,    44,    83,    89,    46,    50,    49,    47,
+      48,    91,   119,   120,    97,   102,   103,    93,    94,    84,
+      85,    86,   117,   128,   129,    59,   108,    56,    78,    87,
+     104,    80,   116
+};
+
+  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
+     positive, shift that token.  If negative, reduce the rule which
+     number is the opposite.  If zero, do what YYDEFACT says.
+     If YYTABLE_NINF, syntax error.    */
 static const yytype_int16 yytable[] =
 {
       79,  -105,    81,    75,   106,    63,     4,     5,     6,     7,
@@ -875,8 +795,8 @@ static const yytype_int16 yycheck[] =
       45,    -1,    -1,    48
 };
 
-/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
-   symbol of state STATE-NUM.  */
+  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
+     symbol of state STATE-NUM.    */
 static const yytype_uint8 yystos[] =
 {
        0,    59,    60,     0,     5,     6,     7,     8,     9,    10,
@@ -896,6 +816,39 @@ static const yytype_uint8 yystos[] =
       82,    88,     4,    54
 };
 
+  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.    */
+static const yytype_uint8 yyr1[] =
+{
+       0,    58,    59,    60,    60,    61,    61,    61,    61,    61,
+      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
+      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
+      61,    61,    61,    61,    61,    62,    62,    62,    62,    62,
+      62,    62,    62,    62,    63,    63,    62,    65,    64,    66,
+      64,    64,    67,    68,    68,    68,    68,    69,    69,    70,
+      70,    71,    71,    72,    72,    73,    73,    74,    74,    74,
+      74,    75,    75,    75,    75,    75,    76,    76,    77,    77,
+      78,    78,    78,    80,    79,    81,    81,    81,    82,    82,
+      82,    82,    82,    82,    83,    83,    84,    84,    85,    86,
+      86,    87,    88,    88,    89,    90,    90
+};
+
+  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.    */
+static const yytype_uint8 yyr2[] =
+{
+       0,     2,     4,     0,     2,     1,     1,     1,     3,     1,
+       2,     1,     2,     2,     2,     3,     1,     2,     2,     2,
+       1,     2,     3,     1,     1,     2,     3,     2,     1,     2,
+       2,     1,     1,     1,     1,     1,     1,     2,     3,     3,
+       1,     1,     2,     3,     0,     1,     3,     0,     3,     0,
+       3,     3,     3,     1,     1,     1,     1,     0,     1,     1,
+       2,     1,     2,     1,     2,     1,     2,     1,     1,     1,
+       1,     1,     1,     2,     2,     3,     1,     2,     1,     2,
+       1,     2,     2,     0,     3,     1,     3,     2,     0,     2,
+       2,     3,     3,     3,     1,     1,     0,     1,     1,     1,
+       1,     1,     1,     1,     1,     0,     2
+};
+
+
 #define yyerrok		(yyerrstatus = 0)
 #define yyclearin	(yychar = YYEMPTY)
 #define YYEMPTY		(-2)
@@ -1043,147 +996,147 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
     {
       case 3: /* "\"string\"" */
 
-/* Line 719 of yacc.c  */
+/* Line 650 of yacc.c  */
 #line 181 "parse-gram.y"
 	{ fputs (quotearg_style (c_quoting_style, ((*yyvaluep).chars)), stderr); };
 
-/* Line 719 of yacc.c  */
-#line 1052 "../../src/parse-gram.c"
+/* Line 650 of yacc.c  */
+#line 1005 "../../src/parse-gram.c"
 	break;
       case 4: /* "\"integer\"" */
 
-/* Line 719 of yacc.c  */
+/* Line 650 of yacc.c  */
 #line 192 "parse-gram.y"
 	{ fprintf (stderr, "%d", ((*yyvaluep).integer)); };
 
-/* Line 719 of yacc.c  */
-#line 1061 "../../src/parse-gram.c"
+/* Line 650 of yacc.c  */
+#line 1014 "../../src/parse-gram.c"
 	break;
       case 44: /* "\"{...}\"" */
 
-/* Line 719 of yacc.c  */
+/* Line 650 of yacc.c  */
 #line 183 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", ((*yyvaluep).code)); };
 
-/* Line 719 of yacc.c  */
-#line 1070 "../../src/parse-gram.c"
+/* Line 650 of yacc.c  */
+#line 1023 "../../src/parse-gram.c"
 	break;
       case 45: /* "\"char\"" */
 
-/* Line 719 of yacc.c  */
+/* Line 650 of yacc.c  */
 #line 175 "parse-gram.y"
 	{ fputs (char_name (((*yyvaluep).character)), stderr); };
 
-/* Line 719 of yacc.c  */
-#line 1079 "../../src/parse-gram.c"
+/* Line 650 of yacc.c  */
+#line 1032 "../../src/parse-gram.c"
 	break;
       case 46: /* "\"epilogue\"" */
 
-/* Line 719 of yacc.c  */
+/* Line 650 of yacc.c  */
 #line 183 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); };
 
-/* Line 719 of yacc.c  */
-#line 1088 "../../src/parse-gram.c"
+/* Line 650 of yacc.c  */
+#line 1041 "../../src/parse-gram.c"
 	break;
       case 48: /* "\"identifier\"" */
 
-/* Line 719 of yacc.c  */
+/* Line 650 of yacc.c  */
 #line 188 "parse-gram.y"
 	{ fputs (((*yyvaluep).uniqstr), stderr); };
 
-/* Line 719 of yacc.c  */
-#line 1097 "../../src/parse-gram.c"
+/* Line 650 of yacc.c  */
+#line 1050 "../../src/parse-gram.c"
 	break;
       case 49: /* "\"identifier:\"" */
 
-/* Line 719 of yacc.c  */
+/* Line 650 of yacc.c  */
 #line 189 "parse-gram.y"
 	{ fprintf (stderr, "%s:", ((*yyvaluep).uniqstr)); };
 
-/* Line 719 of yacc.c  */
-#line 1106 "../../src/parse-gram.c"
+/* Line 650 of yacc.c  */
+#line 1059 "../../src/parse-gram.c"
 	break;
       case 52: /* "\"%{...%}\"" */
 
-/* Line 719 of yacc.c  */
+/* Line 650 of yacc.c  */
 #line 183 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); };
 
-/* Line 719 of yacc.c  */
-#line 1115 "../../src/parse-gram.c"
+/* Line 650 of yacc.c  */
+#line 1068 "../../src/parse-gram.c"
 	break;
       case 54: /* "\"<tag>\"" */
 
-/* Line 719 of yacc.c  */
+/* Line 650 of yacc.c  */
 #line 187 "parse-gram.y"
 	{ fprintf (stderr, "<%s>", ((*yyvaluep).uniqstr)); };
 
-/* Line 719 of yacc.c  */
-#line 1124 "../../src/parse-gram.c"
+/* Line 650 of yacc.c  */
+#line 1077 "../../src/parse-gram.c"
 	break;
       case 83: /* "variable" */
 
-/* Line 719 of yacc.c  */
+/* Line 650 of yacc.c  */
 #line 188 "parse-gram.y"
 	{ fputs (((*yyvaluep).uniqstr), stderr); };
 
-/* Line 719 of yacc.c  */
-#line 1133 "../../src/parse-gram.c"
+/* Line 650 of yacc.c  */
+#line 1086 "../../src/parse-gram.c"
 	break;
       case 84: /* "content.opt" */
 
-/* Line 719 of yacc.c  */
+/* Line 650 of yacc.c  */
 #line 183 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); };
 
-/* Line 719 of yacc.c  */
-#line 1142 "../../src/parse-gram.c"
+/* Line 650 of yacc.c  */
+#line 1095 "../../src/parse-gram.c"
 	break;
       case 85: /* "braceless" */
 
-/* Line 719 of yacc.c  */
+/* Line 650 of yacc.c  */
 #line 183 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); };
 
-/* Line 719 of yacc.c  */
-#line 1151 "../../src/parse-gram.c"
+/* Line 650 of yacc.c  */
+#line 1104 "../../src/parse-gram.c"
 	break;
       case 86: /* "id" */
 
-/* Line 719 of yacc.c  */
+/* Line 650 of yacc.c  */
 #line 195 "parse-gram.y"
 	{ fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); };
 
-/* Line 719 of yacc.c  */
-#line 1160 "../../src/parse-gram.c"
+/* Line 650 of yacc.c  */
+#line 1113 "../../src/parse-gram.c"
 	break;
       case 87: /* "id_colon" */
 
-/* Line 719 of yacc.c  */
+/* Line 650 of yacc.c  */
 #line 196 "parse-gram.y"
 	{ fprintf (stderr, "%s:", ((*yyvaluep).symbol)->tag); };
 
-/* Line 719 of yacc.c  */
-#line 1169 "../../src/parse-gram.c"
+/* Line 650 of yacc.c  */
+#line 1122 "../../src/parse-gram.c"
 	break;
       case 88: /* "symbol" */
 
-/* Line 719 of yacc.c  */
+/* Line 650 of yacc.c  */
 #line 195 "parse-gram.y"
 	{ fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); };
 
-/* Line 719 of yacc.c  */
-#line 1178 "../../src/parse-gram.c"
+/* Line 650 of yacc.c  */
+#line 1131 "../../src/parse-gram.c"
 	break;
       case 89: /* "string_as_id" */
 
-/* Line 719 of yacc.c  */
+/* Line 650 of yacc.c  */
 #line 195 "parse-gram.y"
 	{ fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); };
 
-/* Line 719 of yacc.c  */
-#line 1187 "../../src/parse-gram.c"
+/* Line 650 of yacc.c  */
+#line 1140 "../../src/parse-gram.c"
 	break;
       default:
 	break;
@@ -1258,27 +1211,29 @@ do {								\
 #if (defined __STDC__ || defined __C99__FUNC__ \
      || defined __cplusplus || defined _MSC_VER)
 static void
-yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
+yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
 #else
 static void
-yy_reduce_print (yyvsp, yylsp, yyrule)
+yy_reduce_print (yyssp, yyvsp, yylsp, yyrule)
+    yytype_int16 *yyssp;
     YYSTYPE *yyvsp;
     YYLTYPE *yylsp;
     int yyrule;
 #endif
 {
+  unsigned long int yylno = yyrline[yyrule];
   int yynrhs = yyr2[yyrule];
   int yyi;
-  unsigned long int yylno = yyrline[yyrule];
   YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
-	     yyrule - 1, yylno);
+             yyrule - 1, yylno);
   /* The symbols being reduced.  */
   for (yyi = 0; yyi < yynrhs; yyi++)
     {
       YYFPRINTF (stderr, "   $%d = ", yyi + 1);
-      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
-		       &(yyvsp[(yyi + 1) - (yynrhs)])
-		       , &(yylsp[(yyi + 1) - (yynrhs)])		       );
+      yy_symbol_print (stderr,
+                       yystos[yyssp[yyi + 1 - yynrhs]],
+                       &(yyvsp[(yyi + 1) - (yynrhs)])
+                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
       YYFPRINTF (stderr, "\n");
     }
 }
@@ -1286,7 +1241,7 @@ yy_reduce_print (yyvsp, yylsp, yyrule)
 # define YY_REDUCE_PRINT(Rule)		\
 do {					\
   if (yydebug)				\
-    yy_reduce_print (yyvsp, yylsp, Rule); \
+    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
 } while (YYID (0))
 
 /* Nonzero means print parse trace.  It is left uninitialized so that
@@ -1702,7 +1657,7 @@ YYLTYPE yylloc;
 
 /* User initialization code.  */
 
-/* Line 1246 of yacc.c  */
+/* Line 1179 of yacc.c  */
 #line 84 "parse-gram.y"
 {
   /* Bison's grammar can initial empty locations, hence a default
@@ -1711,8 +1666,8 @@ YYLTYPE yylloc;
   boundary_set (&yylloc.end, current_file, 1, 1);
 }
 
-/* Line 1246 of yacc.c  */
-#line 1716 "../../src/parse-gram.c"
+/* Line 1179 of yacc.c  */
+#line 1671 "../../src/parse-gram.c"
   yylsp[0] = yylloc;
 
   goto yysetstate;
@@ -1899,7 +1854,7 @@ yyreduce:
     {
         case 6:
 
-/* Line 1459 of yacc.c  */
+/* Line 1392 of yacc.c  */
 #line 219 "parse-gram.y"
     {
       code_props plain_code;
@@ -1911,121 +1866,121 @@ yyreduce:
       code_scanner_last_string_free ();
     }
 
-/* Line 1459 of yacc.c  */
-#line 1916 "../../src/parse-gram.c"
+/* Line 1392 of yacc.c  */
+#line 1871 "../../src/parse-gram.c"
     break;
 
   case 7:
 
-/* Line 1459 of yacc.c  */
+/* Line 1392 of yacc.c  */
 #line 228 "parse-gram.y"
     { debug_flag = true; }
 
-/* Line 1459 of yacc.c  */
-#line 1926 "../../src/parse-gram.c"
+/* Line 1392 of yacc.c  */
+#line 1881 "../../src/parse-gram.c"
     break;
 
   case 8:
 
-/* Line 1459 of yacc.c  */
+/* Line 1392 of yacc.c  */
 #line 230 "parse-gram.y"
     {
       muscle_percent_define_insert ((yyvsp[-1].uniqstr), (yylsp[-1]), (yyvsp[0].chars));
     }
 
-/* Line 1459 of yacc.c  */
-#line 1938 "../../src/parse-gram.c"
+/* Line 1392 of yacc.c  */
+#line 1893 "../../src/parse-gram.c"
     break;
 
   case 9:
 
-/* Line 1459 of yacc.c  */
+/* Line 1392 of yacc.c  */
 #line 233 "parse-gram.y"
     { defines_flag = true; }
 
-/* Line 1459 of yacc.c  */
-#line 1948 "../../src/parse-gram.c"
+/* Line 1392 of yacc.c  */
+#line 1903 "../../src/parse-gram.c"
     break;
 
   case 10:
 
-/* Line 1459 of yacc.c  */
+/* Line 1392 of yacc.c  */
 #line 235 "parse-gram.y"
     {
       defines_flag = true;
       spec_defines_file = xstrdup ((yyvsp[0].chars));
     }
 
-/* Line 1459 of yacc.c  */
-#line 1961 "../../src/parse-gram.c"
+/* Line 1392 of yacc.c  */
+#line 1916 "../../src/parse-gram.c"
     break;
 
   case 11:
 
-/* Line 1459 of yacc.c  */
+/* Line 1392 of yacc.c  */
 #line 239 "parse-gram.y"
     { error_verbose = true; }
 
-/* Line 1459 of yacc.c  */
-#line 1971 "../../src/parse-gram.c"
+/* Line 1392 of yacc.c  */
+#line 1926 "../../src/parse-gram.c"
     break;
 
   case 12:
 
-/* Line 1459 of yacc.c  */
+/* Line 1392 of yacc.c  */
 #line 240 "parse-gram.y"
     { expected_sr_conflicts = (yyvsp[0].integer); }
 
-/* Line 1459 of yacc.c  */
-#line 1981 "../../src/parse-gram.c"
+/* Line 1392 of yacc.c  */
+#line 1936 "../../src/parse-gram.c"
     break;
 
   case 13:
 
-/* Line 1459 of yacc.c  */
+/* Line 1392 of yacc.c  */
 #line 241 "parse-gram.y"
     { expected_rr_conflicts = (yyvsp[0].integer); }
 
-/* Line 1459 of yacc.c  */
-#line 1991 "../../src/parse-gram.c"
+/* Line 1392 of yacc.c  */
+#line 1946 "../../src/parse-gram.c"
     break;
 
   case 14:
 
-/* Line 1459 of yacc.c  */
+/* Line 1392 of yacc.c  */
 #line 242 "parse-gram.y"
     { spec_file_prefix = (yyvsp[0].chars); }
 
-/* Line 1459 of yacc.c  */
-#line 2001 "../../src/parse-gram.c"
+/* Line 1392 of yacc.c  */
+#line 1956 "../../src/parse-gram.c"
     break;
 
   case 15:
 
-/* Line 1459 of yacc.c  */
+/* Line 1392 of yacc.c  */
 #line 243 "parse-gram.y"
     { spec_file_prefix = (yyvsp[0].chars); }
 
-/* Line 1459 of yacc.c  */
-#line 2011 "../../src/parse-gram.c"
+/* Line 1392 of yacc.c  */
+#line 1966 "../../src/parse-gram.c"
     break;
 
   case 16:
 
-/* Line 1459 of yacc.c  */
+/* Line 1392 of yacc.c  */
 #line 245 "parse-gram.y"
     {
       nondeterministic_parser = true;
       glr_parser = true;
     }
 
-/* Line 1459 of yacc.c  */
-#line 2024 "../../src/parse-gram.c"
+/* Line 1392 of yacc.c  */
+#line 1979 "../../src/parse-gram.c"
     break;
 
   case 17:
 
-/* Line 1459 of yacc.c  */
+/* Line 1392 of yacc.c  */
 #line 250 "parse-gram.y"
     {
       code_props action;
@@ -2036,113 +1991,113 @@ yyreduce:
       code_scanner_last_string_free ();
     }
 
-/* Line 1459 of yacc.c  */
-#line 2041 "../../src/parse-gram.c"
+/* Line 1392 of yacc.c  */
+#line 1996 "../../src/parse-gram.c"
     break;
 
   case 18:
 
-/* Line 1459 of yacc.c  */
+/* Line 1392 of yacc.c  */
 #line 258 "parse-gram.y"
     { language_argmatch ((yyvsp[0].chars), grammar_prio, (yylsp[-1])); }
 
-/* Line 1459 of yacc.c  */
-#line 2051 "../../src/parse-gram.c"
+/* Line 1392 of yacc.c  */
+#line 2006 "../../src/parse-gram.c"
     break;
 
   case 19:
 
-/* Line 1459 of yacc.c  */
+/* Line 1392 of yacc.c  */
 #line 259 "parse-gram.y"
     { add_param ("lex_param", (yyvsp[0].code), (yylsp[0])); }
 
-/* Line 1459 of yacc.c  */
-#line 2061 "../../src/parse-gram.c"
+/* Line 1392 of yacc.c  */
+#line 2016 "../../src/parse-gram.c"
     break;
 
   case 20:
 
-/* Line 1459 of yacc.c  */
+/* Line 1392 of yacc.c  */
 #line 260 "parse-gram.y"
     { locations_flag = true; }
 
-/* Line 1459 of yacc.c  */
-#line 2071 "../../src/parse-gram.c"
+/* Line 1392 of yacc.c  */
+#line 2026 "../../src/parse-gram.c"
     break;
 
   case 21:
 
-/* Line 1459 of yacc.c  */
+/* Line 1392 of yacc.c  */
 #line 261 "parse-gram.y"
     { spec_name_prefix = (yyvsp[0].chars); }
 
-/* Line 1459 of yacc.c  */
-#line 2081 "../../src/parse-gram.c"
+/* Line 1392 of yacc.c  */
+#line 2036 "../../src/parse-gram.c"
     break;
 
   case 22:
 
-/* Line 1459 of yacc.c  */
+/* Line 1392 of yacc.c  */
 #line 262 "parse-gram.y"
     { spec_name_prefix = (yyvsp[0].chars); }
 
-/* Line 1459 of yacc.c  */
-#line 2091 "../../src/parse-gram.c"
+/* Line 1392 of yacc.c  */
+#line 2046 "../../src/parse-gram.c"
     break;
 
   case 23:
 
-/* Line 1459 of yacc.c  */
+/* Line 1392 of yacc.c  */
 #line 263 "parse-gram.y"
     { no_lines_flag = true; }
 
-/* Line 1459 of yacc.c  */
-#line 2101 "../../src/parse-gram.c"
+/* Line 1392 of yacc.c  */
+#line 2056 "../../src/parse-gram.c"
     break;
 
   case 24:
 
-/* Line 1459 of yacc.c  */
+/* Line 1392 of yacc.c  */
 #line 264 "parse-gram.y"
     { nondeterministic_parser = true; }
 
-/* Line 1459 of yacc.c  */
-#line 2111 "../../src/parse-gram.c"
+/* Line 1392 of yacc.c  */
+#line 2066 "../../src/parse-gram.c"
     break;
 
   case 25:
 
-/* Line 1459 of yacc.c  */
+/* Line 1392 of yacc.c  */
 #line 265 "parse-gram.y"
     { spec_outfile = (yyvsp[0].chars); }
 
-/* Line 1459 of yacc.c  */
-#line 2121 "../../src/parse-gram.c"
+/* Line 1392 of yacc.c  */
+#line 2076 "../../src/parse-gram.c"
     break;
 
   case 26:
 
-/* Line 1459 of yacc.c  */
+/* Line 1392 of yacc.c  */
 #line 266 "parse-gram.y"
     { spec_outfile = (yyvsp[0].chars); }
 
-/* Line 1459 of yacc.c  */
-#line 2131 "../../src/parse-gram.c"
+/* Line 1392 of yacc.c  */
+#line 2086 "../../src/parse-gram.c"
     break;
 
   case 27:
 
-/* Line 1459 of yacc.c  */
+/* Line 1392 of yacc.c  */
 #line 267 "parse-gram.y"
     { add_param ("parse_param", (yyvsp[0].code), (yylsp[0])); }
 
-/* Line 1459 of yacc.c  */
-#line 2141 "../../src/parse-gram.c"
+/* Line 1392 of yacc.c  */
+#line 2096 "../../src/parse-gram.c"
     break;
 
   case 28:
 
-/* Line 1459 of yacc.c  */
+/* Line 1392 of yacc.c  */
 #line 269 "parse-gram.y"
     {
       /* %pure-parser is deprecated in favor of `%define api.pure', so use
@@ -2157,23 +2112,23 @@ yyreduce:
         muscle_percent_define_insert ("api.pure", (yylsp[0]), "");
     }
 
-/* Line 1459 of yacc.c  */
-#line 2162 "../../src/parse-gram.c"
+/* Line 1392 of yacc.c  */
+#line 2117 "../../src/parse-gram.c"
     break;
 
   case 29:
 
-/* Line 1459 of yacc.c  */
+/* Line 1392 of yacc.c  */
 #line 281 "parse-gram.y"
     { version_check (&(yylsp[0]), (yyvsp[0].chars)); }
 
-/* Line 1459 of yacc.c  */
-#line 2172 "../../src/parse-gram.c"
+/* Line 1392 of yacc.c  */
+#line 2127 "../../src/parse-gram.c"
     break;
 
   case 30:
 
-/* Line 1459 of yacc.c  */
+/* Line 1392 of yacc.c  */
 #line 283 "parse-gram.y"
     {
       char const *skeleton_user = (yyvsp[0].chars);
@@ -2199,55 +2154,55 @@ yyreduce:
       skeleton_arg (skeleton_user, grammar_prio, (yylsp[-1]));
     }
 
-/* Line 1459 of yacc.c  */
-#line 2204 "../../src/parse-gram.c"
+/* Line 1392 of yacc.c  */
+#line 2159 "../../src/parse-gram.c"
     break;
 
   case 31:
 
-/* Line 1459 of yacc.c  */
+/* Line 1392 of yacc.c  */
 #line 306 "parse-gram.y"
     { token_table_flag = true; }
 
-/* Line 1459 of yacc.c  */
-#line 2214 "../../src/parse-gram.c"
+/* Line 1392 of yacc.c  */
+#line 2169 "../../src/parse-gram.c"
     break;
 
   case 32:
 
-/* Line 1459 of yacc.c  */
+/* Line 1392 of yacc.c  */
 #line 307 "parse-gram.y"
     { report_flag |= report_states; }
 
-/* Line 1459 of yacc.c  */
-#line 2224 "../../src/parse-gram.c"
+/* Line 1392 of yacc.c  */
+#line 2179 "../../src/parse-gram.c"
     break;
 
   case 33:
 
-/* Line 1459 of yacc.c  */
+/* Line 1392 of yacc.c  */
 #line 308 "parse-gram.y"
     { yacc_flag = true; }
 
-/* Line 1459 of yacc.c  */
-#line 2234 "../../src/parse-gram.c"
+/* Line 1392 of yacc.c  */
+#line 2189 "../../src/parse-gram.c"
     break;
 
   case 37:
 
-/* Line 1459 of yacc.c  */
+/* Line 1392 of yacc.c  */
 #line 316 "parse-gram.y"
     {
       grammar_start_symbol_set ((yyvsp[0].symbol), (yylsp[0]));
     }
 
-/* Line 1459 of yacc.c  */
-#line 2246 "../../src/parse-gram.c"
+/* Line 1392 of yacc.c  */
+#line 2201 "../../src/parse-gram.c"
     break;
 
   case 38:
 
-/* Line 1459 of yacc.c  */
+/* Line 1392 of yacc.c  */
 #line 320 "parse-gram.y"
     {
       symbol_list *list;
@@ -2256,13 +2211,13 @@ yyreduce:
       symbol_list_free ((yyvsp[0].list));
     }
 
-/* Line 1459 of yacc.c  */
-#line 2261 "../../src/parse-gram.c"
+/* Line 1392 of yacc.c  */
+#line 2216 "../../src/parse-gram.c"
     break;
 
   case 39:
 
-/* Line 1459 of yacc.c  */
+/* Line 1392 of yacc.c  */
 #line 327 "parse-gram.y"
     {
       symbol_list *list;
@@ -2271,37 +2226,37 @@ yyreduce:
       symbol_list_free ((yyvsp[0].list));
     }
 
-/* Line 1459 of yacc.c  */
-#line 2276 "../../src/parse-gram.c"
+/* Line 1392 of yacc.c  */
+#line 2231 "../../src/parse-gram.c"
     break;
 
   case 40:
 
-/* Line 1459 of yacc.c  */
+/* Line 1392 of yacc.c  */
 #line 334 "parse-gram.y"
     {
       default_prec = true;
     }
 
-/* Line 1459 of yacc.c  */
-#line 2288 "../../src/parse-gram.c"
+/* Line 1392 of yacc.c  */
+#line 2243 "../../src/parse-gram.c"
     break;
 
   case 41:
 
-/* Line 1459 of yacc.c  */
+/* Line 1392 of yacc.c  */
 #line 338 "parse-gram.y"
     {
       default_prec = false;
     }
 
-/* Line 1459 of yacc.c  */
-#line 2300 "../../src/parse-gram.c"
+/* Line 1392 of yacc.c  */
+#line 2255 "../../src/parse-gram.c"
     break;
 
   case 42:
 
-/* Line 1459 of yacc.c  */
+/* Line 1392 of yacc.c  */
 #line 342 "parse-gram.y"
     {
       /* Do not invoke muscle_percent_code_grow here since it invokes
@@ -2310,46 +2265,46 @@ yyreduce:
       code_scanner_last_string_free ();
     }
 
-/* Line 1459 of yacc.c  */
-#line 2315 "../../src/parse-gram.c"
+/* Line 1392 of yacc.c  */
+#line 2270 "../../src/parse-gram.c"
     break;
 
   case 43:
 
-/* Line 1459 of yacc.c  */
+/* Line 1392 of yacc.c  */
 #line 349 "parse-gram.y"
     {
       muscle_percent_code_grow ((yyvsp[-1].uniqstr), (yylsp[-1]), (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
 
-/* Line 1459 of yacc.c  */
-#line 2328 "../../src/parse-gram.c"
+/* Line 1392 of yacc.c  */
+#line 2283 "../../src/parse-gram.c"
     break;
 
   case 44:
 
-/* Line 1459 of yacc.c  */
+/* Line 1392 of yacc.c  */
 #line 363 "parse-gram.y"
     {}
 
-/* Line 1459 of yacc.c  */
-#line 2338 "../../src/parse-gram.c"
+/* Line 1392 of yacc.c  */
+#line 2293 "../../src/parse-gram.c"
     break;
 
   case 45:
 
-/* Line 1459 of yacc.c  */
+/* Line 1392 of yacc.c  */
 #line 364 "parse-gram.y"
     { muscle_code_grow ("union_name", (yyvsp[0].uniqstr), (yylsp[0])); }
 
-/* Line 1459 of yacc.c  */
-#line 2348 "../../src/parse-gram.c"
+/* Line 1392 of yacc.c  */
+#line 2303 "../../src/parse-gram.c"
     break;
 
   case 46:
 
-/* Line 1459 of yacc.c  */
+/* Line 1392 of yacc.c  */
 #line 369 "parse-gram.y"
     {
       union_seen = true;
@@ -2357,59 +2312,59 @@ yyreduce:
       code_scanner_last_string_free ();
     }
 
-/* Line 1459 of yacc.c  */
-#line 2362 "../../src/parse-gram.c"
+/* Line 1392 of yacc.c  */
+#line 2317 "../../src/parse-gram.c"
     break;
 
   case 47:
 
-/* Line 1459 of yacc.c  */
+/* Line 1392 of yacc.c  */
 #line 380 "parse-gram.y"
     { current_class = nterm_sym; }
 
-/* Line 1459 of yacc.c  */
-#line 2372 "../../src/parse-gram.c"
+/* Line 1392 of yacc.c  */
+#line 2327 "../../src/parse-gram.c"
     break;
 
   case 48:
 
-/* Line 1459 of yacc.c  */
+/* Line 1392 of yacc.c  */
 #line 381 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
 
-/* Line 1459 of yacc.c  */
-#line 2385 "../../src/parse-gram.c"
+/* Line 1392 of yacc.c  */
+#line 2340 "../../src/parse-gram.c"
     break;
 
   case 49:
 
-/* Line 1459 of yacc.c  */
+/* Line 1392 of yacc.c  */
 #line 385 "parse-gram.y"
     { current_class = token_sym; }
 
-/* Line 1459 of yacc.c  */
-#line 2395 "../../src/parse-gram.c"
+/* Line 1392 of yacc.c  */
+#line 2350 "../../src/parse-gram.c"
     break;
 
   case 50:
 
-/* Line 1459 of yacc.c  */
+/* Line 1392 of yacc.c  */
 #line 386 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
 
-/* Line 1459 of yacc.c  */
-#line 2408 "../../src/parse-gram.c"
+/* Line 1392 of yacc.c  */
+#line 2363 "../../src/parse-gram.c"
     break;
 
   case 51:
 
-/* Line 1459 of yacc.c  */
+/* Line 1392 of yacc.c  */
 #line 391 "parse-gram.y"
     {
       symbol_list *list;
@@ -2419,13 +2374,13 @@ yyreduce:
       symbol_list_free ((yyvsp[0].list));
     }
 
-/* Line 1459 of yacc.c  */
-#line 2424 "../../src/parse-gram.c"
+/* Line 1392 of yacc.c  */
+#line 2379 "../../src/parse-gram.c"
     break;
 
   case 52:
 
-/* Line 1459 of yacc.c  */
+/* Line 1392 of yacc.c  */
 #line 402 "parse-gram.y"
     {
       symbol_list *list;
@@ -2439,219 +2394,219 @@ yyreduce:
       current_type = NULL;
     }
 
-/* Line 1459 of yacc.c  */
-#line 2444 "../../src/parse-gram.c"
+/* Line 1392 of yacc.c  */
+#line 2399 "../../src/parse-gram.c"
     break;
 
   case 53:
 
-/* Line 1459 of yacc.c  */
+/* Line 1392 of yacc.c  */
 #line 416 "parse-gram.y"
     { (yyval.assoc) = left_assoc; }
 
-/* Line 1459 of yacc.c  */
-#line 2454 "../../src/parse-gram.c"
+/* Line 1392 of yacc.c  */
+#line 2409 "../../src/parse-gram.c"
     break;
 
   case 54:
 
-/* Line 1459 of yacc.c  */
+/* Line 1392 of yacc.c  */
 #line 417 "parse-gram.y"
     { (yyval.assoc) = right_assoc; }
 
-/* Line 1459 of yacc.c  */
-#line 2464 "../../src/parse-gram.c"
+/* Line 1392 of yacc.c  */
+#line 2419 "../../src/parse-gram.c"
     break;
 
   case 55:
 
-/* Line 1459 of yacc.c  */
+/* Line 1392 of yacc.c  */
 #line 418 "parse-gram.y"
     { (yyval.assoc) = non_assoc; }
 
-/* Line 1459 of yacc.c  */
-#line 2474 "../../src/parse-gram.c"
+/* Line 1392 of yacc.c  */
+#line 2429 "../../src/parse-gram.c"
     break;
 
   case 56:
 
-/* Line 1459 of yacc.c  */
+/* Line 1392 of yacc.c  */
 #line 419 "parse-gram.y"
     { (yyval.assoc) = precedence_assoc; }
 
-/* Line 1459 of yacc.c  */
-#line 2484 "../../src/parse-gram.c"
+/* Line 1392 of yacc.c  */
+#line 2439 "../../src/parse-gram.c"
     break;
 
   case 57:
 
-/* Line 1459 of yacc.c  */
+/* Line 1392 of yacc.c  */
 #line 423 "parse-gram.y"
     { current_type = NULL; }
 
-/* Line 1459 of yacc.c  */
-#line 2494 "../../src/parse-gram.c"
+/* Line 1392 of yacc.c  */
+#line 2449 "../../src/parse-gram.c"
     break;
 
   case 58:
 
-/* Line 1459 of yacc.c  */
+/* Line 1392 of yacc.c  */
 #line 424 "parse-gram.y"
     { current_type = (yyvsp[0].uniqstr); tag_seen = true; }
 
-/* Line 1459 of yacc.c  */
-#line 2504 "../../src/parse-gram.c"
+/* Line 1392 of yacc.c  */
+#line 2459 "../../src/parse-gram.c"
     break;
 
   case 59:
 
-/* Line 1459 of yacc.c  */
+/* Line 1392 of yacc.c  */
 #line 430 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
 
-/* Line 1459 of yacc.c  */
-#line 2514 "../../src/parse-gram.c"
+/* Line 1392 of yacc.c  */
+#line 2469 "../../src/parse-gram.c"
     break;
 
   case 60:
 
-/* Line 1459 of yacc.c  */
+/* Line 1392 of yacc.c  */
 #line 432 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
 
-/* Line 1459 of yacc.c  */
-#line 2524 "../../src/parse-gram.c"
+/* Line 1392 of yacc.c  */
+#line 2479 "../../src/parse-gram.c"
     break;
 
   case 61:
 
-/* Line 1459 of yacc.c  */
+/* Line 1392 of yacc.c  */
 #line 436 "parse-gram.y"
     { (yyval.symbol) = (yyvsp[0].symbol); }
 
-/* Line 1459 of yacc.c  */
-#line 2534 "../../src/parse-gram.c"
+/* Line 1392 of yacc.c  */
+#line 2489 "../../src/parse-gram.c"
     break;
 
   case 62:
 
-/* Line 1459 of yacc.c  */
+/* Line 1392 of yacc.c  */
 #line 437 "parse-gram.y"
     { (yyval.symbol) = (yyvsp[-1].symbol); symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0])); }
 
-/* Line 1459 of yacc.c  */
-#line 2544 "../../src/parse-gram.c"
+/* Line 1392 of yacc.c  */
+#line 2499 "../../src/parse-gram.c"
     break;
 
   case 63:
 
-/* Line 1459 of yacc.c  */
+/* Line 1392 of yacc.c  */
 #line 443 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
 
-/* Line 1459 of yacc.c  */
-#line 2554 "../../src/parse-gram.c"
+/* Line 1392 of yacc.c  */
+#line 2509 "../../src/parse-gram.c"
     break;
 
   case 64:
 
-/* Line 1459 of yacc.c  */
+/* Line 1392 of yacc.c  */
 #line 445 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
 
-/* Line 1459 of yacc.c  */
-#line 2564 "../../src/parse-gram.c"
+/* Line 1392 of yacc.c  */
+#line 2519 "../../src/parse-gram.c"
     break;
 
   case 65:
 
-/* Line 1459 of yacc.c  */
+/* Line 1392 of yacc.c  */
 #line 449 "parse-gram.y"
     { (yyval.list) = (yyvsp[0].list); }
 
-/* Line 1459 of yacc.c  */
-#line 2574 "../../src/parse-gram.c"
+/* Line 1392 of yacc.c  */
+#line 2529 "../../src/parse-gram.c"
     break;
 
   case 66:
 
-/* Line 1459 of yacc.c  */
+/* Line 1392 of yacc.c  */
 #line 450 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), (yyvsp[0].list)); }
 
-/* Line 1459 of yacc.c  */
-#line 2584 "../../src/parse-gram.c"
+/* Line 1392 of yacc.c  */
+#line 2539 "../../src/parse-gram.c"
     break;
 
   case 67:
 
-/* Line 1459 of yacc.c  */
+/* Line 1392 of yacc.c  */
 #line 454 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
 
-/* Line 1459 of yacc.c  */
-#line 2594 "../../src/parse-gram.c"
+/* Line 1392 of yacc.c  */
+#line 2549 "../../src/parse-gram.c"
     break;
 
   case 68:
 
-/* Line 1459 of yacc.c  */
+/* Line 1392 of yacc.c  */
 #line 455 "parse-gram.y"
     { (yyval.list) = symbol_list_type_new ((yyvsp[0].uniqstr), (yylsp[0])); }
 
-/* Line 1459 of yacc.c  */
-#line 2604 "../../src/parse-gram.c"
+/* Line 1392 of yacc.c  */
+#line 2559 "../../src/parse-gram.c"
     break;
 
   case 69:
 
-/* Line 1459 of yacc.c  */
+/* Line 1392 of yacc.c  */
 #line 456 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagged_new ((yylsp[0])); }
 
-/* Line 1459 of yacc.c  */
-#line 2614 "../../src/parse-gram.c"
+/* Line 1392 of yacc.c  */
+#line 2569 "../../src/parse-gram.c"
     break;
 
   case 70:
 
-/* Line 1459 of yacc.c  */
+/* Line 1392 of yacc.c  */
 #line 457 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagless_new ((yylsp[0])); }
 
-/* Line 1459 of yacc.c  */
-#line 2624 "../../src/parse-gram.c"
+/* Line 1392 of yacc.c  */
+#line 2579 "../../src/parse-gram.c"
     break;
 
   case 71:
 
-/* Line 1459 of yacc.c  */
+/* Line 1392 of yacc.c  */
 #line 463 "parse-gram.y"
     {
        current_type = (yyvsp[0].uniqstr);
        tag_seen = true;
      }
 
-/* Line 1459 of yacc.c  */
-#line 2637 "../../src/parse-gram.c"
+/* Line 1392 of yacc.c  */
+#line 2592 "../../src/parse-gram.c"
     break;
 
   case 72:
 
-/* Line 1459 of yacc.c  */
+/* Line 1392 of yacc.c  */
 #line 468 "parse-gram.y"
     {
        symbol_class_set ((yyvsp[0].symbol), current_class, (yylsp[0]), true);
        symbol_type_set ((yyvsp[0].symbol), current_type, (yylsp[0]));
      }
 
-/* Line 1459 of yacc.c  */
-#line 2650 "../../src/parse-gram.c"
+/* Line 1392 of yacc.c  */
+#line 2605 "../../src/parse-gram.c"
     break;
 
   case 73:
 
-/* Line 1459 of yacc.c  */
+/* Line 1392 of yacc.c  */
 #line 473 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[-1].symbol), current_class, (yylsp[-1]), true);
@@ -2659,13 +2614,13 @@ yyreduce:
       symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0]));
     }
 
-/* Line 1459 of yacc.c  */
-#line 2664 "../../src/parse-gram.c"
+/* Line 1392 of yacc.c  */
+#line 2619 "../../src/parse-gram.c"
     break;
 
   case 74:
 
-/* Line 1459 of yacc.c  */
+/* Line 1392 of yacc.c  */
 #line 479 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[-1].symbol), current_class, (yylsp[-1]), true);
@@ -2673,13 +2628,13 @@ yyreduce:
       symbol_make_alias ((yyvsp[-1].symbol), (yyvsp[0].symbol), (yyloc));
     }
 
-/* Line 1459 of yacc.c  */
-#line 2678 "../../src/parse-gram.c"
+/* Line 1392 of yacc.c  */
+#line 2633 "../../src/parse-gram.c"
     break;
 
   case 75:
 
-/* Line 1459 of yacc.c  */
+/* Line 1392 of yacc.c  */
 #line 485 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[-2].symbol), current_class, (yylsp[-2]), true);
@@ -2688,137 +2643,137 @@ yyreduce:
       symbol_make_alias ((yyvsp[-2].symbol), (yyvsp[0].symbol), (yyloc));
     }
 
-/* Line 1459 of yacc.c  */
-#line 2693 "../../src/parse-gram.c"
+/* Line 1392 of yacc.c  */
+#line 2648 "../../src/parse-gram.c"
     break;
 
   case 82:
 
-/* Line 1459 of yacc.c  */
+/* Line 1392 of yacc.c  */
 #line 515 "parse-gram.y"
     {
       yyerrok;
     }
 
-/* Line 1459 of yacc.c  */
-#line 2705 "../../src/parse-gram.c"
+/* Line 1392 of yacc.c  */
+#line 2660 "../../src/parse-gram.c"
     break;
 
   case 83:
 
-/* Line 1459 of yacc.c  */
+/* Line 1392 of yacc.c  */
 #line 521 "parse-gram.y"
     { current_lhs = (yyvsp[0].symbol); current_lhs_location = (yylsp[0]); }
 
-/* Line 1459 of yacc.c  */
-#line 2715 "../../src/parse-gram.c"
+/* Line 1392 of yacc.c  */
+#line 2670 "../../src/parse-gram.c"
     break;
 
   case 85:
 
-/* Line 1459 of yacc.c  */
+/* Line 1392 of yacc.c  */
 #line 525 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[0])); }
 
-/* Line 1459 of yacc.c  */
-#line 2725 "../../src/parse-gram.c"
+/* Line 1392 of yacc.c  */
+#line 2680 "../../src/parse-gram.c"
     break;
 
   case 86:
 
-/* Line 1459 of yacc.c  */
+/* Line 1392 of yacc.c  */
 #line 526 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[0])); }
 
-/* Line 1459 of yacc.c  */
-#line 2735 "../../src/parse-gram.c"
+/* Line 1392 of yacc.c  */
+#line 2690 "../../src/parse-gram.c"
     break;
 
   case 88:
 
-/* Line 1459 of yacc.c  */
+/* Line 1392 of yacc.c  */
 #line 532 "parse-gram.y"
     { grammar_current_rule_begin (current_lhs, current_lhs_location); }
 
-/* Line 1459 of yacc.c  */
-#line 2745 "../../src/parse-gram.c"
+/* Line 1392 of yacc.c  */
+#line 2700 "../../src/parse-gram.c"
     break;
 
   case 89:
 
-/* Line 1459 of yacc.c  */
+/* Line 1392 of yacc.c  */
 #line 534 "parse-gram.y"
     { grammar_current_rule_symbol_append ((yyvsp[0].symbol), (yylsp[0])); }
 
-/* Line 1459 of yacc.c  */
-#line 2755 "../../src/parse-gram.c"
+/* Line 1392 of yacc.c  */
+#line 2710 "../../src/parse-gram.c"
     break;
 
   case 90:
 
-/* Line 1459 of yacc.c  */
+/* Line 1392 of yacc.c  */
 #line 536 "parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[0].code), (yylsp[0])); }
 
-/* Line 1459 of yacc.c  */
-#line 2765 "../../src/parse-gram.c"
+/* Line 1392 of yacc.c  */
+#line 2720 "../../src/parse-gram.c"
     break;
 
   case 91:
 
-/* Line 1459 of yacc.c  */
+/* Line 1392 of yacc.c  */
 #line 538 "parse-gram.y"
     { grammar_current_rule_prec_set ((yyvsp[0].symbol), (yylsp[0])); }
 
-/* Line 1459 of yacc.c  */
-#line 2775 "../../src/parse-gram.c"
+/* Line 1392 of yacc.c  */
+#line 2730 "../../src/parse-gram.c"
     break;
 
   case 92:
 
-/* Line 1459 of yacc.c  */
+/* Line 1392 of yacc.c  */
 #line 540 "parse-gram.y"
     { grammar_current_rule_dprec_set ((yyvsp[0].integer), (yylsp[0])); }
 
-/* Line 1459 of yacc.c  */
-#line 2785 "../../src/parse-gram.c"
+/* Line 1392 of yacc.c  */
+#line 2740 "../../src/parse-gram.c"
     break;
 
   case 93:
 
-/* Line 1459 of yacc.c  */
+/* Line 1392 of yacc.c  */
 #line 542 "parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[0].uniqstr), (yylsp[0])); }
 
-/* Line 1459 of yacc.c  */
-#line 2795 "../../src/parse-gram.c"
+/* Line 1392 of yacc.c  */
+#line 2750 "../../src/parse-gram.c"
     break;
 
   case 95:
 
-/* Line 1459 of yacc.c  */
+/* Line 1392 of yacc.c  */
 #line 552 "parse-gram.y"
     { (yyval.uniqstr) = uniqstr_new ((yyvsp[0].chars)); }
 
-/* Line 1459 of yacc.c  */
-#line 2805 "../../src/parse-gram.c"
+/* Line 1392 of yacc.c  */
+#line 2760 "../../src/parse-gram.c"
     break;
 
   case 96:
 
-/* Line 1459 of yacc.c  */
+/* Line 1392 of yacc.c  */
 #line 558 "parse-gram.y"
     {
       (yyval.chars) = "";
     }
 
-/* Line 1459 of yacc.c  */
-#line 2817 "../../src/parse-gram.c"
+/* Line 1392 of yacc.c  */
+#line 2772 "../../src/parse-gram.c"
     break;
 
   case 98:
 
-/* Line 1459 of yacc.c  */
+/* Line 1392 of yacc.c  */
 #line 571 "parse-gram.y"
     {
       code_props plain_code;
@@ -2829,23 +2784,23 @@ yyreduce:
       (yyval.chars) = plain_code.code;
     }
 
-/* Line 1459 of yacc.c  */
-#line 2834 "../../src/parse-gram.c"
+/* Line 1392 of yacc.c  */
+#line 2789 "../../src/parse-gram.c"
     break;
 
   case 99:
 
-/* Line 1459 of yacc.c  */
+/* Line 1392 of yacc.c  */
 #line 591 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
 
-/* Line 1459 of yacc.c  */
-#line 2844 "../../src/parse-gram.c"
+/* Line 1392 of yacc.c  */
+#line 2799 "../../src/parse-gram.c"
     break;
 
   case 100:
 
-/* Line 1459 of yacc.c  */
+/* Line 1392 of yacc.c  */
 #line 593 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[0].character)), (yylsp[0]));
@@ -2853,36 +2808,36 @@ yyreduce:
       symbol_user_token_number_set ((yyval.symbol), (yyvsp[0].character), (yylsp[0]));
     }
 
-/* Line 1459 of yacc.c  */
-#line 2858 "../../src/parse-gram.c"
+/* Line 1392 of yacc.c  */
+#line 2813 "../../src/parse-gram.c"
     break;
 
   case 101:
 
-/* Line 1459 of yacc.c  */
+/* Line 1392 of yacc.c  */
 #line 601 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
 
-/* Line 1459 of yacc.c  */
-#line 2868 "../../src/parse-gram.c"
+/* Line 1392 of yacc.c  */
+#line 2823 "../../src/parse-gram.c"
     break;
 
   case 104:
 
-/* Line 1459 of yacc.c  */
+/* Line 1392 of yacc.c  */
 #line 613 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[0].chars)), (yylsp[0]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
     }
 
-/* Line 1459 of yacc.c  */
-#line 2881 "../../src/parse-gram.c"
+/* Line 1392 of yacc.c  */
+#line 2836 "../../src/parse-gram.c"
     break;
 
   case 106:
 
-/* Line 1459 of yacc.c  */
+/* Line 1392 of yacc.c  */
 #line 622 "parse-gram.y"
     {
       code_props plain_code;
@@ -2893,14 +2848,14 @@ yyreduce:
       code_scanner_last_string_free ();
     }
 
-/* Line 1459 of yacc.c  */
-#line 2898 "../../src/parse-gram.c"
+/* Line 1392 of yacc.c  */
+#line 2853 "../../src/parse-gram.c"
     break;
 
 
 
-/* Line 1459 of yacc.c  */
-#line 2904 "../../src/parse-gram.c"
+/* Line 1392 of yacc.c  */
+#line 2859 "../../src/parse-gram.c"
       default: break;
     }
   YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);
@@ -3118,7 +3073,7 @@ yyreturn:
 
 
 
-/* Line 1679 of yacc.c  */
+/* Line 1612 of yacc.c  */
 #line 632 "parse-gram.y"
 
 
