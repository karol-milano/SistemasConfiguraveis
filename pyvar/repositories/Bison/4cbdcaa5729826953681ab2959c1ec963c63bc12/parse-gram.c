@@ -133,7 +133,7 @@ extern int gram_debug;
     param_parse  = 1 << 1,
     param_both   = param_lex | param_parse
   } param_type;
-#line 606 "src/parse-gram.y" /* yacc.c:352  */
+#line 602 "src/parse-gram.y" /* yacc.c:352  */
 
   #include "muscle-tab.h"
   typedef struct
@@ -603,7 +603,7 @@ union yyalloc
 /* YYNNTS -- Number of nonterminals.  */
 #define YYNNTS  39
 /* YYNRULES -- Number of rules.  */
-#define YYNRULES  112
+#define YYNRULES  111
 /* YYNSTATES -- Number of states.  */
 #define YYNSTATES  150
 
@@ -663,12 +663,12 @@ static const yytype_uint16 yyrline[] =
      325,   326,   335,   336,   337,   341,   352,   356,   360,   368,
      378,   379,   389,   390,   396,   408,   408,   413,   413,   418,
      428,   441,   442,   443,   444,   448,   449,   454,   456,   461,
-     466,   476,   478,   483,   484,   488,   489,   493,   494,   495,
-     500,   505,   518,   519,   524,   525,   537,   538,   544,   545,
-     546,   553,   553,   561,   562,   563,   568,   571,   573,   575,
-     577,   579,   581,   583,   585,   587,   592,   593,   602,   626,
-     627,   628,   629,   641,   643,   658,   663,   664,   669,   678,
-     679,   683,   684
+     472,   474,   479,   480,   484,   485,   489,   490,   491,   496,
+     501,   514,   515,   520,   521,   533,   534,   540,   541,   542,
+     549,   549,   557,   558,   559,   564,   567,   569,   571,   573,
+     575,   577,   579,   581,   583,   588,   589,   598,   622,   623,
+     624,   625,   637,   639,   654,   659,   660,   665,   674,   675,
+     679,   680
 };
 #endif
 
@@ -721,7 +721,7 @@ static const yytype_uint16 yytoknum[] =
 #define yypact_value_is_default(Yystate) \
   (!!((Yystate) == (-119)))
 
-#define YYTABLE_NINF -112
+#define YYTABLE_NINF -111
 
 #define yytable_value_is_error(Yytable_value) \
   0
@@ -741,9 +741,9 @@ static const yytype_int16 yypact[] =
       46,     2,  -119,    20,  -119,  -119,     6,    32,     6,    20,
     -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,    44,  -119,
     -119,  -119,  -119,  -119,    49,  -119,  -119,  -119,  -119,     2,
-    -119,  -119,  -119,    20,  -119,    35,  -119,  -119,    86,  -119,
+    -119,  -119,  -119,    20,  -119,    32,  -119,  -119,    85,  -119,
     -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,    -9,    21,
-    -119,  -119,    20,    38,    42,    43,    48,  -119,  -119,    55,
+    -119,  -119,    20,    38,    42,    43,    48,  -119,  -119,    51,
       39,    21,  -119,  -119,  -119,  -119,  -119,    39,  -119,  -119
 };
 
@@ -757,25 +757,25 @@ static const yytype_uint8 yydefact[] =
        7,     0,    14,     0,     0,     0,    37,    18,    19,     0,
        0,     0,     0,    25,    26,    27,     0,     6,    29,    21,
       42,     4,     5,     0,    33,    32,    55,    28,     0,     0,
-       0,    38,     0,    98,    99,    10,    11,    12,    13,    15,
-      16,    17,    20,    23,    24,   108,   104,   103,   106,    34,
-     107,     0,   105,     0,     0,    76,    78,    96,     0,    43,
-       0,     0,    56,     0,    70,    74,    48,    72,    46,    49,
-      61,    39,   101,   102,   100,     8,    80,    79,     0,    77,
-       2,    97,    81,    31,    22,    44,    67,    68,    69,    35,
-      63,    66,    65,    50,    57,    59,    75,    73,   109,    62,
-     112,    86,    30,    64,    58,    60,   110,    71,    82,    83,
-      86,    85,     0,     0,     0,     0,     0,    89,    90,     0,
-      96,    84,    91,    92,    93,    94,    95,    96,    87,    88
+       0,    38,     0,    97,    98,    10,    11,    12,    13,    15,
+      16,    17,    20,    23,    24,   107,   103,   102,   105,    34,
+     106,     0,   104,     0,     0,    75,    77,    95,     0,    43,
+       0,     0,    56,     0,    69,    73,    48,    71,    46,    49,
+      60,    39,   100,   101,    99,     8,    79,    78,     0,    76,
+       2,    96,    80,    31,    22,    44,    66,    67,    68,    35,
+      62,    65,    64,    50,    57,    71,    74,    72,   108,    61,
+     111,    85,    30,    63,    58,    59,   109,    70,    81,    82,
+      85,    84,     0,     0,     0,     0,     0,    88,    89,     0,
+      95,    83,    90,    91,    92,    93,    94,    95,    86,    87
 };
 
   /* YYPGOTO[NTERM-NUM].  */
 static const yytype_int8 yypgoto[] =
 {
     -119,  -119,  -119,  -119,  -119,  -119,    88,  -119,  -119,  -119,
-    -119,  -119,  -119,  -119,    53,  -119,   -19,  -119,  -119,   -14,
-    -119,   -20,  -119,    54,  -119,    24,  -119,  -119,  -119,   -26,
-    -118,  -119,  -119,   -16,  -119,   -32,   -13,  -119,  -119
+    -119,  -119,  -119,  -119,    47,  -119,   -19,  -119,  -119,   -14,
+    -119,   -20,   -13,    50,  -119,    24,  -119,  -119,  -119,   -26,
+    -118,  -119,  -119,   -16,  -119,   -32,   -15,  -119,  -119
 };
 
   /* YYDEFGOTO[NTERM-NUM].  */
@@ -792,7 +792,7 @@ static const yytype_int16 yydefgoto[] =
      number is the opposite.  If YYTABLE_NINF, syntax error.  */
 static const yytype_int16 yytable[] =
 {
-      69,     3,    47,  -111,    71,    65,    50,     5,     6,     7,
+      69,     3,    47,  -110,    71,    65,    50,     5,     6,     7,
        8,     9,    10,    11,    12,    13,    53,    55,    90,    14,
       15,    51,   148,    65,    65,    58,    56,    52,    92,   149,
       57,    26,    87,    87,   132,   133,   134,    32,   130,    60,
@@ -800,9 +800,9 @@ static const yytype_int16 yytable[] =
       67,   115,   106,   107,   108,    62,    84,   119,    40,   -55,
      137,    66,    66,    93,    67,    67,   116,    63,   116,    94,
       87,    82,    87,    64,    79,    81,    82,   138,    91,   101,
-      96,   115,    97,   103,   105,   117,   120,   122,   125,    65,
-      42,   143,   144,   147,   124,   123,   145,   140,    99,    83,
-     142,   146,     0,    88,   141,   126,     0,     4,     0,   140,
+      96,   115,    97,   103,   105,   117,   120,   122,    65,   147,
+      42,   143,   144,    83,   124,   123,   145,   140,    99,    88,
+     142,   146,   125,   126,   141,     0,     0,     4,     0,   140,
        5,     6,     7,     8,     9,    10,    11,    12,    13,     0,
        0,     0,    14,    15,    16,    17,    18,    19,    20,    21,
       22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
@@ -826,9 +826,9 @@ static const yytype_int16 yycheck[] =
       44,    83,    50,    51,    52,     3,    50,    89,    55,    38,
       39,    41,    41,    38,    44,    44,    86,     3,    88,    44,
       86,    50,    88,     3,    44,    38,    50,    56,    38,    40,
-      49,   113,    49,    38,    38,    53,    42,    38,    53,     3,
-       2,    53,    50,    38,   113,   109,    53,   129,    74,    46,
-     132,    53,    -1,    49,   130,   118,    -1,     1,    -1,   141,
+      49,   113,    49,    38,    38,    53,    42,    38,     3,    38,
+       2,    53,    50,    46,   113,   109,    53,   129,    74,    49,
+     132,    53,   115,   118,   130,    -1,    -1,     1,    -1,   141,
        4,     5,     6,     7,     8,     9,    10,    11,    12,    -1,
       -1,    -1,    16,    17,    18,    19,    20,    21,    22,    23,
       24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
@@ -858,7 +858,7 @@ static const yytype_uint8 yystos[] =
       92,    38,     3,    38,    44,    89,    49,    49,    46,    82,
       95,    40,    87,    38,    62,    38,    50,    51,    52,    75,
       76,    77,    92,    72,    73,    92,    78,    53,    79,    92,
-      42,    84,    38,    76,    73,    53,    93,    94,    85,    86,
+      42,    84,    38,    76,    73,    79,    93,    94,    85,    86,
       47,    49,    13,    14,    15,    20,    21,    39,    56,    71,
       92,    86,    92,    53,    50,    53,    53,    38,    87,    87
 };
@@ -872,12 +872,12 @@ static const yytype_uint8 yyr1[] =
       62,    62,    63,    63,    63,    63,    63,    63,    63,    63,
       64,    64,    65,    65,    63,    67,    66,    68,    66,    66,
       69,    70,    70,    70,    70,    71,    71,    72,    72,    73,
-      73,    74,    74,    75,    75,    76,    76,    77,    77,    77,
-      78,    78,    79,    79,    80,    80,    81,    81,    82,    82,
-      82,    84,    83,    85,    85,    85,    86,    86,    86,    86,
-      86,    86,    86,    86,    86,    86,    87,    87,    88,    89,
-      89,    89,    89,    90,    90,    91,    92,    92,    93,    94,
-      94,    95,    95
+      74,    74,    75,    75,    76,    76,    77,    77,    77,    78,
+      78,    79,    79,    80,    80,    81,    81,    82,    82,    82,
+      84,    83,    85,    85,    85,    86,    86,    86,    86,    86,
+      86,    86,    86,    86,    86,    87,    87,    88,    89,    89,
+      89,    89,    90,    90,    91,    92,    92,    93,    94,    94,
+      95,    95
 };
 
   /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
@@ -888,13 +888,13 @@ static const yytype_uint8 yyr2[] =
        2,     0,     3,     2,     2,     1,     1,     1,     2,     1,
        2,     1,     1,     1,     2,     3,     1,     1,     2,     3,
        1,     1,     0,     1,     3,     0,     3,     0,     3,     3,
-       3,     1,     1,     1,     1,     0,     1,     1,     2,     1,
-       2,     1,     2,     1,     2,     1,     1,     1,     1,     1,
-       1,     3,     0,     1,     1,     2,     1,     2,     1,     2,
-       2,     0,     4,     1,     3,     2,     0,     3,     4,     2,
-       2,     3,     3,     3,     3,     3,     0,     1,     1,     0,
-       1,     1,     1,     1,     1,     1,     1,     1,     1,     0,
-       1,     0,     2
+       3,     1,     1,     1,     1,     0,     1,     1,     2,     2,
+       1,     2,     1,     2,     1,     1,     1,     1,     1,     1,
+       3,     0,     1,     1,     2,     1,     2,     1,     2,     2,
+       0,     4,     1,     3,     2,     0,     3,     4,     2,     2,
+       3,     3,     3,     3,     3,     0,     1,     1,     0,     1,
+       1,     1,     1,     1,     1,     1,     1,     1,     0,     1,
+       0,     2
 };
 
 
@@ -1175,7 +1175,7 @@ yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YY
         break;
 
     case 89: /* value  */
-#line 616 "src/parse-gram.y" /* yacc.c:680  */
+#line 612 "src/parse-gram.y" /* yacc.c:680  */
       {
   switch (((*yyvaluep).value).kind)
     {
@@ -2482,76 +2482,68 @@ yyreduce:
 
   case 59:
 #line 462 "src/parse-gram.y" /* yacc.c:1648  */
-    {
-      (yyval.yytype_73) = (yyvsp[0].symbol);
-      symbol_class_set ((yyvsp[0].symbol), token_sym, (yylsp[0]), false);
-    }
-#line 2490 "src/parse-gram.c" /* yacc.c:1648  */
-    break;
-
-  case 60:
-#line 467 "src/parse-gram.y" /* yacc.c:1648  */
     {
       (yyval.yytype_73) = (yyvsp[-1].symbol);
       symbol_class_set ((yyvsp[-1].symbol), token_sym, (yylsp[-1]), false);
-      symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].INT), (yylsp[0]));
+      if (0 <= (yyvsp[0].yytype_79))
+        symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].yytype_79), (yylsp[0]));
     }
-#line 2500 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2492 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
-  case 61:
-#line 477 "src/parse-gram.y" /* yacc.c:1648  */
+  case 60:
+#line 473 "src/parse-gram.y" /* yacc.c:1648  */
     { (yyval.yytype_74) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-#line 2506 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2498 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
-  case 62:
-#line 479 "src/parse-gram.y" /* yacc.c:1648  */
+  case 61:
+#line 475 "src/parse-gram.y" /* yacc.c:1648  */
     { (yyval.yytype_74) = symbol_list_append ((yyvsp[-1].yytype_74), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
-#line 2512 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2504 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
-  case 64:
-#line 484 "src/parse-gram.y" /* yacc.c:1648  */
+  case 63:
+#line 480 "src/parse-gram.y" /* yacc.c:1648  */
     { (yyval.generic_symlist) = symbol_list_append ((yyvsp[-1].generic_symlist), (yyvsp[0].generic_symlist_item)); }
-#line 2518 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2510 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
-  case 65:
-#line 488 "src/parse-gram.y" /* yacc.c:1648  */
+  case 64:
+#line 484 "src/parse-gram.y" /* yacc.c:1648  */
     { (yyval.generic_symlist_item) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-#line 2524 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2516 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
-  case 66:
-#line 489 "src/parse-gram.y" /* yacc.c:1648  */
+  case 65:
+#line 485 "src/parse-gram.y" /* yacc.c:1648  */
     { (yyval.generic_symlist_item) = symbol_list_type_new ((yyvsp[0].tag), (yylsp[0])); }
-#line 2530 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2522 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
-  case 68:
-#line 494 "src/parse-gram.y" /* yacc.c:1648  */
+  case 67:
+#line 490 "src/parse-gram.y" /* yacc.c:1648  */
     { (yyval.tag) = uniqstr_new ("*"); }
-#line 2536 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2528 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
-  case 69:
-#line 495 "src/parse-gram.y" /* yacc.c:1648  */
+  case 68:
+#line 491 "src/parse-gram.y" /* yacc.c:1648  */
     { (yyval.tag) = uniqstr_new (""); }
-#line 2542 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2534 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
-  case 70:
-#line 501 "src/parse-gram.y" /* yacc.c:1648  */
+  case 69:
+#line 497 "src/parse-gram.y" /* yacc.c:1648  */
     {
       current_type = (yyvsp[0].TAG);
       tag_seen = true;
     }
-#line 2551 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2543 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
-  case 71:
-#line 506 "src/parse-gram.y" /* yacc.c:1648  */
+  case 70:
+#line 502 "src/parse-gram.y" /* yacc.c:1648  */
     {
       symbol_class_set ((yyvsp[-2].id), current_class, (yylsp[-2]), true);
       symbol_type_set ((yyvsp[-2].id), current_type, (yylsp[-2]));
@@ -2560,155 +2552,155 @@ yyreduce:
       if ((yyvsp[0].yytype_94))
         symbol_make_alias ((yyvsp[-2].id), (yyvsp[0].yytype_94), (yylsp[0]));
     }
-#line 2564 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2556 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
-  case 72:
-#line 518 "src/parse-gram.y" /* yacc.c:1648  */
+  case 71:
+#line 514 "src/parse-gram.y" /* yacc.c:1648  */
     { (yyval.yytype_79) = -1; }
-#line 2570 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2562 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
-  case 80:
-#line 547 "src/parse-gram.y" /* yacc.c:1648  */
+  case 79:
+#line 543 "src/parse-gram.y" /* yacc.c:1648  */
     {
       yyerrok;
     }
-#line 2578 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2570 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
-  case 81:
-#line 553 "src/parse-gram.y" /* yacc.c:1648  */
+  case 80:
+#line 549 "src/parse-gram.y" /* yacc.c:1648  */
     { current_lhs ((yyvsp[-1].id_colon), (yylsp[-1]), (yyvsp[0].yytype_87)); }
-#line 2584 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2576 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
-  case 82:
-#line 554 "src/parse-gram.y" /* yacc.c:1648  */
+  case 81:
+#line 550 "src/parse-gram.y" /* yacc.c:1648  */
     {
       /* Free the current lhs. */
       current_lhs (0, (yylsp[-3]), 0);
     }
-#line 2593 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2585 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
-  case 83:
-#line 561 "src/parse-gram.y" /* yacc.c:1648  */
+  case 82:
+#line 557 "src/parse-gram.y" /* yacc.c:1648  */
     { grammar_current_rule_end ((yylsp[0])); }
-#line 2599 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2591 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
-  case 84:
-#line 562 "src/parse-gram.y" /* yacc.c:1648  */
+  case 83:
+#line 558 "src/parse-gram.y" /* yacc.c:1648  */
     { grammar_current_rule_end ((yylsp[0])); }
-#line 2605 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2597 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
-  case 86:
-#line 569 "src/parse-gram.y" /* yacc.c:1648  */
+  case 85:
+#line 565 "src/parse-gram.y" /* yacc.c:1648  */
     { grammar_current_rule_begin (current_lhs_symbol, current_lhs_location,
                                   current_lhs_named_ref); }
-#line 2612 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2604 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
-  case 87:
-#line 572 "src/parse-gram.y" /* yacc.c:1648  */
+  case 86:
+#line 568 "src/parse-gram.y" /* yacc.c:1648  */
     { grammar_current_rule_symbol_append ((yyvsp[-1].symbol), (yylsp[-1]), (yyvsp[0].yytype_87)); }
-#line 2618 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2610 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
-  case 88:
-#line 574 "src/parse-gram.y" /* yacc.c:1648  */
+  case 87:
+#line 570 "src/parse-gram.y" /* yacc.c:1648  */
     { grammar_current_rule_action_append ((yyvsp[-1].BRACED_CODE), (yylsp[-1]), (yyvsp[0].yytype_87), (yyvsp[-2].yytype_71)); }
-#line 2624 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2616 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
-  case 89:
-#line 576 "src/parse-gram.y" /* yacc.c:1648  */
+  case 88:
+#line 572 "src/parse-gram.y" /* yacc.c:1648  */
     { grammar_current_rule_predicate_append ((yyvsp[0].BRACED_PREDICATE), (yylsp[0])); }
-#line 2630 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2622 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
-  case 90:
-#line 578 "src/parse-gram.y" /* yacc.c:1648  */
+  case 89:
+#line 574 "src/parse-gram.y" /* yacc.c:1648  */
     { grammar_current_rule_empty_set ((yylsp[0])); }
-#line 2636 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2628 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
-  case 91:
-#line 580 "src/parse-gram.y" /* yacc.c:1648  */
+  case 90:
+#line 576 "src/parse-gram.y" /* yacc.c:1648  */
     { grammar_current_rule_prec_set ((yyvsp[0].symbol), (yylsp[0])); }
-#line 2642 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2634 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
-  case 92:
-#line 582 "src/parse-gram.y" /* yacc.c:1648  */
+  case 91:
+#line 578 "src/parse-gram.y" /* yacc.c:1648  */
     { grammar_current_rule_dprec_set ((yyvsp[0].INT), (yylsp[0])); }
-#line 2648 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2640 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
-  case 93:
-#line 584 "src/parse-gram.y" /* yacc.c:1648  */
+  case 92:
+#line 580 "src/parse-gram.y" /* yacc.c:1648  */
     { grammar_current_rule_merge_set ((yyvsp[0].TAG), (yylsp[0])); }
-#line 2654 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2646 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
-  case 94:
-#line 586 "src/parse-gram.y" /* yacc.c:1648  */
+  case 93:
+#line 582 "src/parse-gram.y" /* yacc.c:1648  */
     { grammar_current_rule_expect_sr ((yyvsp[0].INT), (yylsp[0])); }
-#line 2660 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2652 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
-  case 95:
-#line 588 "src/parse-gram.y" /* yacc.c:1648  */
+  case 94:
+#line 584 "src/parse-gram.y" /* yacc.c:1648  */
     { grammar_current_rule_expect_rr ((yyvsp[0].INT), (yylsp[0])); }
-#line 2666 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2658 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
-  case 96:
-#line 592 "src/parse-gram.y" /* yacc.c:1648  */
+  case 95:
+#line 588 "src/parse-gram.y" /* yacc.c:1648  */
     { (yyval.yytype_87) = 0; }
-#line 2672 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2664 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
-  case 97:
-#line 593 "src/parse-gram.y" /* yacc.c:1648  */
+  case 96:
+#line 589 "src/parse-gram.y" /* yacc.c:1648  */
     { (yyval.yytype_87) = named_ref_new ((yyvsp[0].BRACKETED_ID), (yylsp[0])); }
-#line 2678 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2670 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
-  case 99:
-#line 626 "src/parse-gram.y" /* yacc.c:1648  */
+  case 98:
+#line 622 "src/parse-gram.y" /* yacc.c:1648  */
     { (yyval.value).kind = muscle_keyword; (yyval.value).chars = ""; }
-#line 2684 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2676 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
-  case 100:
-#line 627 "src/parse-gram.y" /* yacc.c:1648  */
+  case 99:
+#line 623 "src/parse-gram.y" /* yacc.c:1648  */
     { (yyval.value).kind = muscle_keyword; (yyval.value).chars = (yyvsp[0].ID); }
-#line 2690 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2682 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
-  case 101:
-#line 628 "src/parse-gram.y" /* yacc.c:1648  */
+  case 100:
+#line 624 "src/parse-gram.y" /* yacc.c:1648  */
     { (yyval.value).kind = muscle_string;  (yyval.value).chars = (yyvsp[0].STRING); }
-#line 2696 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2688 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
-  case 102:
-#line 629 "src/parse-gram.y" /* yacc.c:1648  */
+  case 101:
+#line 625 "src/parse-gram.y" /* yacc.c:1648  */
     { (yyval.value).kind = muscle_code;    (yyval.value).chars = strip_braces ((yyvsp[0].BRACED_CODE)); }
-#line 2702 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2694 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
-  case 103:
-#line 642 "src/parse-gram.y" /* yacc.c:1648  */
+  case 102:
+#line 638 "src/parse-gram.y" /* yacc.c:1648  */
     { (yyval.id) = symbol_from_uniqstr ((yyvsp[0].ID), (yylsp[0])); }
-#line 2708 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2700 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
-  case 104:
-#line 644 "src/parse-gram.y" /* yacc.c:1648  */
+  case 103:
+#line 640 "src/parse-gram.y" /* yacc.c:1648  */
     {
       if (current_class == nterm_sym)
         {
@@ -2720,41 +2712,41 @@ yyreduce:
       symbol_class_set ((yyval.id), token_sym, (yylsp[0]), false);
       symbol_user_token_number_set ((yyval.id), (yyvsp[0].CHAR), (yylsp[0]));
     }
-#line 2724 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2716 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
-  case 105:
-#line 658 "src/parse-gram.y" /* yacc.c:1648  */
+  case 104:
+#line 654 "src/parse-gram.y" /* yacc.c:1648  */
     { (yyval.id_colon) = symbol_from_uniqstr ((yyvsp[0].ID_COLON), (yylsp[0])); }
-#line 2730 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2722 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
-  case 108:
-#line 670 "src/parse-gram.y" /* yacc.c:1648  */
+  case 107:
+#line 666 "src/parse-gram.y" /* yacc.c:1648  */
     {
       (yyval.string_as_id) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[0].STRING)), (yylsp[0]));
       symbol_class_set ((yyval.string_as_id), token_sym, (yylsp[0]), false);
     }
-#line 2739 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2731 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
-  case 109:
-#line 678 "src/parse-gram.y" /* yacc.c:1648  */
+  case 108:
+#line 674 "src/parse-gram.y" /* yacc.c:1648  */
     { (yyval.yytype_94) = NULL; }
-#line 2745 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2737 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
-  case 112:
-#line 685 "src/parse-gram.y" /* yacc.c:1648  */
+  case 111:
+#line 681 "src/parse-gram.y" /* yacc.c:1648  */
     {
       muscle_code_grow ("epilogue", translate_code ((yyvsp[0].EPILOGUE), (yylsp[0]), true), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2754 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2746 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
 
-#line 2758 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2750 "src/parse-gram.c" /* yacc.c:1648  */
         default: break;
       }
     if (yychar_backup != yychar)
@@ -3003,7 +2995,7 @@ yyreturn:
 #endif
   return yyresult;
 }
-#line 691 "src/parse-gram.y" /* yacc.c:1914  */
+#line 687 "src/parse-gram.y" /* yacc.c:1914  */
 
 
 /* Return the location of the left-hand side of a rule whose
