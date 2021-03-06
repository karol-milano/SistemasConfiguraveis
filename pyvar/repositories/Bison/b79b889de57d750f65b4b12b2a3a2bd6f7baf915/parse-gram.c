@@ -567,7 +567,7 @@ union yyalloc
 /* YYNRULES -- Number of rules.  */
 #define YYNRULES  110
 /* YYNSTATES -- Number of states.  */
-#define YYNSTATES  144
+#define YYNSTATES  145
 
 /* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
    by yylex, with out-of-bounds checking.  */
@@ -678,10 +678,10 @@ static const yytype_uint16 yytoknum[] =
 };
 # endif
 
-#define YYPACT_NINF -113
+#define YYPACT_NINF -116
 
 #define yypact_value_is_default(Yystate) \
-  (!!((Yystate) == (-113)))
+  (!!((Yystate) == (-116)))
 
 #define YYTABLE_NINF -110
 
@@ -692,21 +692,21 @@ static const yytype_uint16 yytoknum[] =
      STATE-NUM.  */
 static const yytype_int8 yypact[] =
 {
-    -113,    16,   108,  -113,  -113,  -113,   -27,  -113,  -113,  -113,
-    -113,  -113,  -113,   -24,  -113,    23,    24,  -113,   -21,   -15,
-    -113,    29,  -113,     3,    38,    42,  -113,  -113,  -113,    44,
-      47,    71,    31,  -113,  -113,  -113,    55,  -113,  -113,  -113,
-      30,  -113,  -113,    39,  -113,  -113,    26,   -22,   -22,    31,
-    -113,    48,  -113,  -113,     1,  -113,  -113,  -113,  -113,  -113,
-    -113,  -113,  -113,  -113,  -113,  -113,  -113,  -113,  -113,  -113,
-    -113,    45,  -113,    50,     2,  -113,  -113,    57,    49,  -113,
-      52,    41,  -113,    31,  -113,  -113,   -22,    -2,   -22,    31,
-    -113,  -113,  -113,  -113,  -113,  -113,  -113,  -113,    46,  -113,
-    -113,  -113,  -113,  -113,    63,  -113,  -113,  -113,  -113,    41,
-    -113,  -113,  -113,    31,  -113,    51,  -113,   100,  -113,  -113,
-    -113,  -113,  -113,  -113,  -113,  -113,  -113,   -20,    40,  -113,
-    -113,    31,    53,    58,    57,  -113,  -113,    57,    40,  -113,
-    -113,  -113,  -113,  -113
+    -116,    16,   108,  -116,  -116,  -116,   -27,  -116,  -116,  -116,
+    -116,  -116,  -116,   -24,  -116,    23,    29,  -116,   -29,   -21,
+    -116,    36,  -116,     3,    38,    42,  -116,  -116,  -116,    44,
+      47,    71,    31,  -116,  -116,  -116,    55,  -116,  -116,  -116,
+      30,  -116,  -116,    39,  -116,  -116,    26,   -22,   -22,    31,
+    -116,    48,  -116,  -116,     1,  -116,  -116,  -116,  -116,  -116,
+    -116,  -116,  -116,  -116,  -116,  -116,  -116,  -116,  -116,  -116,
+    -116,    45,  -116,    50,     2,  -116,  -116,    57,    49,  -116,
+      63,    41,  -116,    31,  -116,  -116,   -22,    -2,   -22,    31,
+    -116,  -116,  -116,  -116,  -116,  -116,  -116,  -116,    46,  -116,
+    -116,  -116,  -116,  -116,    64,  -116,  -116,  -116,  -116,    41,
+    -116,  -116,  -116,    31,  -116,    51,  -116,   101,  -116,  -116,
+    -116,  -116,  -116,  -116,  -116,  -116,  -116,   -20,    40,  -116,
+    -116,    31,    53,    58,  -116,  -116,    82,    57,    40,  -116,
+    -116,  -116,    57,  -116,  -116
 };
 
   /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
@@ -727,24 +727,24 @@ static const yytype_uint8 yydefact[] =
        2,    96,    82,    31,    23,    44,    67,    68,    69,    35,
       63,    66,    65,    50,    57,    59,    76,    72,    73,    62,
      110,    87,    30,    64,    58,    60,    74,    83,    84,    87,
-      86,     0,     0,     0,    95,    90,    91,    95,    85,    92,
-      93,    94,    89,    88
+      86,     0,     0,     0,    90,    91,     0,    95,    85,    92,
+      93,    94,    95,    88,    89
 };
 
   /* YYPGOTO[NTERM-NUM].  */
 static const yytype_int8 yypgoto[] =
 {
-    -113,  -113,  -113,  -113,  -113,  -113,   102,  -113,  -113,  -113,
-    -113,  -113,  -113,  -113,  -113,  -113,     8,  -113,  -113,    13,
-    -113,   -50,    75,  -113,    73,  -113,  -113,  -113,    19,  -112,
-    -113,  -113,    22,  -113,   -32,   -82,  -113
+    -116,  -116,  -116,  -116,  -116,  -116,   120,  -116,  -116,  -116,
+    -116,  -116,  -116,  -116,    77,  -116,    34,  -116,  -116,    43,
+    -116,   -50,   100,  -116,    75,  -116,  -116,  -116,    21,  -115,
+    -116,  -116,    22,  -116,   -32,   -82,  -116
 };
 
   /* YYDEFGOTO[NTERM-NUM].  */
 static const yytype_int16 yydefgoto[] =
 {
       -1,     1,     2,    41,    78,   104,    73,    43,    80,    44,
-      48,    47,    45,    46,    83,   113,   114,    89,   109,   110,
+      48,    47,    45,    46,   136,   113,   114,    89,   109,   110,
      111,    85,    86,    74,    75,    76,   121,   127,   128,   102,
       54,    95,    68,    77,   112,    70,   100
 };
@@ -756,20 +756,20 @@ static const yytype_int16 yytable[] =
 {
       69,    65,  -109,    71,    92,   118,     4,     5,     6,     7,
        8,     9,    10,    11,    12,    50,     3,    90,    13,    14,
-      66,    51,   142,    67,    49,   143,    52,    55,   129,    84,
-     130,    26,    58,    56,    65,   126,   116,    32,   116,    57,
+      66,    51,   143,    67,    49,    56,    52,   144,   129,    84,
+     130,    26,    55,    57,    65,   126,   116,    32,   116,    58,
       93,    60,    59,    65,    65,    61,    94,    62,    72,    98,
       63,   115,   117,   131,   132,   133,    71,   119,    40,     4,
        5,     6,     7,     8,     9,    10,    11,    12,    53,    87,
-      87,    13,    14,    66,    64,    79,    67,    82,    81,   134,
-     135,   115,    66,    66,    26,    67,    67,    91,   103,   120,
-      32,   105,   106,   107,   108,    96,   137,   136,   101,   139,
-      97,    72,   122,    65,    42,   125,   137,   140,    87,   141,
+      87,    13,    14,    66,    64,    79,    67,    82,    81,   -55,
+     134,   115,    66,    66,    26,    67,    67,    91,   103,   120,
+      32,    82,   106,   107,   108,    96,   137,   135,   101,   139,
+      97,    72,   105,   122,    65,   125,   137,   140,    87,   141,
       87,    40,     4,     5,     6,     7,     8,     9,    10,    11,
-      12,   124,   123,    88,    13,    14,    15,    16,    17,    18,
+      12,   142,    42,    83,    13,    14,    15,    16,    17,    18,
       19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
-      29,    30,    31,    32,    33,    34,    35,    99,   138,     0,
-       0,     0,     0,     0,     0,    36,     0,    37,    38,     0,
+      29,    30,    31,    32,    33,    34,    35,   124,    88,    99,
+     138,     0,   123,     0,     0,    36,     0,    37,    38,     0,
        0,     0,     0,    39,    40
 };
 
@@ -777,20 +777,20 @@ static const yytype_int16 yycheck[] =
 {
       32,     3,     0,     1,     3,    87,     4,     5,     6,     7,
        8,     9,    10,    11,    12,    39,     0,    49,    16,    17,
-      42,    45,   134,    45,    51,   137,     3,     3,    48,    51,
-      50,    29,     3,    54,     3,   117,    86,    35,    88,    54,
+      42,    45,   137,    45,    51,    54,     3,   142,    48,    51,
+      50,    29,     3,    54,     3,   117,    86,    35,    88,     3,
       39,     3,    39,     3,     3,     3,    45,     3,    46,    47,
        3,    83,    54,    13,    14,    15,     1,    89,    56,     4,
        5,     6,     7,     8,     9,    10,    11,    12,    45,    47,
       48,    16,    17,    42,     3,    45,    45,    51,    39,    39,
       40,   113,    42,    42,    29,    45,    45,    39,    39,    43,
-      35,    39,    51,    52,    53,    50,   128,    57,    41,   131,
-      50,    46,    39,     3,     2,    54,   138,    54,    86,    51,
+      35,    51,    51,    52,    53,    50,   128,    57,    41,   131,
+      50,    46,    39,    39,     3,    54,   138,    54,    86,    51,
       88,    56,     4,     5,     6,     7,     8,     9,    10,    11,
-      12,   113,   109,    48,    16,    17,    18,    19,    20,    21,
+      12,    39,     2,    46,    16,    17,    18,    19,    20,    21,
       22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
-      32,    33,    34,    35,    36,    37,    38,    74,   129,    -1,
-      -1,    -1,    -1,    -1,    -1,    47,    -1,    49,    50,    -1,
+      32,    33,    34,    35,    36,    37,    38,   113,    48,    74,
+     129,    -1,   109,    -1,    -1,    47,    -1,    49,    50,    -1,
       -1,    -1,    -1,    55,    56
 };
 
@@ -811,8 +811,8 @@ static const yytype_uint8 yystos[] =
       94,    41,    87,    39,    63,    39,    51,    52,    53,    76,
       77,    78,    92,    73,    74,    92,    79,    54,    93,    92,
       43,    84,    39,    77,    74,    54,    93,    85,    86,    48,
-      50,    13,    14,    15,    39,    40,    57,    92,    86,    92,
-      54,    51,    87,    87
+      50,    13,    14,    15,    40,    57,    72,    92,    86,    92,
+      54,    51,    39,    87,    87
 };
 
   /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
@@ -843,7 +843,7 @@ static const yytype_uint8 yyr2[] =
        3,     1,     1,     1,     1,     0,     1,     1,     2,     1,
        2,     1,     2,     1,     2,     1,     1,     1,     1,     1,
        1,     1,     2,     2,     3,     1,     2,     1,     2,     1,
-       2,     2,     0,     4,     1,     3,     2,     0,     3,     3,
+       2,     2,     0,     4,     1,     3,     2,     0,     3,     4,
        2,     2,     3,     3,     3,     0,     1,     1,     1,     0,
        1,     1,     1,     1,     1,     1,     1,     1,     1,     0,
        2
@@ -2608,7 +2608,7 @@ yyreduce:
 
   case 89:
 #line 617 "src/parse-gram.y" /* yacc.c:1648  */
-    { grammar_current_rule_action_append ((yyvsp[-1].code), (yylsp[-1]), (yyvsp[0].named_ref)); }
+    { grammar_current_rule_action_append ((yyvsp[-1].code), (yylsp[-1]), (yyvsp[0].named_ref), current_type); }
 #line 2613 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
