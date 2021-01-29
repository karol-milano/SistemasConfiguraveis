@@ -677,13 +677,13 @@ static const yytype_uint16 yyrline[] =
      238,   243,   244,   245,   246,   247,   248,   253,   262,   263,
      264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
      274,   275,   276,   277,   278,   279,   280,   284,   285,   286,
-     290,   297,   304,   308,   312,   317,   340,   341,   345,   374,
-     374,   379,   379,   384,   395,   410,   411,   412,   416,   417,
-     422,   424,   429,   430,   434,   435,   436,   437,   442,   447,
-     452,   458,   464,   475,   476,   485,   486,   492,   493,   494,
-     501,   501,   505,   506,   507,   512,   513,   515,   517,   519,
-     521,   531,   532,   538,   542,   547,   567,   569,   578,   583,
-     584,   589,   596,   598
+     290,   297,   304,   308,   312,   317,   344,   345,   349,   378,
+     378,   383,   383,   388,   399,   414,   415,   416,   420,   421,
+     426,   428,   433,   434,   438,   439,   440,   441,   446,   451,
+     456,   462,   468,   479,   480,   489,   490,   496,   497,   498,
+     505,   505,   509,   510,   511,   516,   517,   519,   521,   523,
+     525,   535,   536,   542,   546,   551,   571,   573,   582,   587,
+     588,   593,   600,   602
 };
 #endif
 
@@ -2194,30 +2194,34 @@ yyreduce:
       muscle_code_grow (uniqstr_new (name), (yyvsp[(3) - (3)].chars), (yylsp[(3) - (3)]));
       free (name);
       code_scanner_last_string_free ();
-      muscle_grow ("used_percent_code_qualifiers", "[[", ",");
+      muscle_grow ("used_percent_code_qualifiers", "[[[[", ",");
       muscle_grow ("used_percent_code_qualifiers", (yyvsp[(2) - (3)].chars), "");
-      muscle_grow ("used_percent_code_qualifiers", "]]", "");
+      muscle_grow ("used_percent_code_qualifiers", "]], [[", "");
+      muscle_boundary_grow ("used_percent_code_qualifiers", (yylsp[(2) - (3)]).start);
+      muscle_grow ("used_percent_code_qualifiers", "]], [[", "");
+      muscle_boundary_grow ("used_percent_code_qualifiers", (yylsp[(2) - (3)]).end);
+      muscle_grow ("used_percent_code_qualifiers", "]]]]", "");
     }
     break;
 
   case 46:
 
 /* Line 1280 of yacc.c  */
-#line 340 "parse-gram.y"
+#line 344 "parse-gram.y"
     {}
     break;
 
   case 47:
 
 /* Line 1280 of yacc.c  */
-#line 341 "parse-gram.y"
+#line 345 "parse-gram.y"
     { muscle_code_grow ("union_name", (yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 48:
 
 /* Line 1280 of yacc.c  */
-#line 346 "parse-gram.y"
+#line 350 "parse-gram.y"
     {
       char const *body = (yyvsp[(3) - (3)].code);
 
@@ -2245,14 +2249,14 @@ yyreduce:
   case 49:
 
 /* Line 1280 of yacc.c  */
-#line 374 "parse-gram.y"
+#line 378 "parse-gram.y"
     { current_class = nterm_sym; }
     break;
 
   case 50:
 
 /* Line 1280 of yacc.c  */
-#line 375 "parse-gram.y"
+#line 379 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
@@ -2262,14 +2266,14 @@ yyreduce:
   case 51:
 
 /* Line 1280 of yacc.c  */
-#line 379 "parse-gram.y"
+#line 383 "parse-gram.y"
     { current_class = token_sym; }
     break;
 
   case 52:
 
 /* Line 1280 of yacc.c  */
-#line 380 "parse-gram.y"
+#line 384 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
@@ -2279,7 +2283,7 @@ yyreduce:
   case 53:
 
 /* Line 1280 of yacc.c  */
-#line 385 "parse-gram.y"
+#line 389 "parse-gram.y"
     {
       symbol_list *list;
       tag_seen = true;
@@ -2292,7 +2296,7 @@ yyreduce:
   case 54:
 
 /* Line 1280 of yacc.c  */
-#line 396 "parse-gram.y"
+#line 400 "parse-gram.y"
     {
       symbol_list *list;
       ++current_prec;
@@ -2309,98 +2313,98 @@ yyreduce:
   case 55:
 
 /* Line 1280 of yacc.c  */
-#line 410 "parse-gram.y"
+#line 414 "parse-gram.y"
     { (yyval.assoc) = left_assoc; }
     break;
 
   case 56:
 
 /* Line 1280 of yacc.c  */
-#line 411 "parse-gram.y"
+#line 415 "parse-gram.y"
     { (yyval.assoc) = right_assoc; }
     break;
 
   case 57:
 
 /* Line 1280 of yacc.c  */
-#line 412 "parse-gram.y"
+#line 416 "parse-gram.y"
     { (yyval.assoc) = non_assoc; }
     break;
 
   case 58:
 
 /* Line 1280 of yacc.c  */
-#line 416 "parse-gram.y"
+#line 420 "parse-gram.y"
     { current_type = NULL; }
     break;
 
   case 59:
 
 /* Line 1280 of yacc.c  */
-#line 417 "parse-gram.y"
+#line 421 "parse-gram.y"
     { current_type = (yyvsp[(1) - (1)].uniqstr); tag_seen = true; }
     break;
 
   case 60:
 
 /* Line 1280 of yacc.c  */
-#line 423 "parse-gram.y"
+#line 427 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 61:
 
 /* Line 1280 of yacc.c  */
-#line 425 "parse-gram.y"
+#line 429 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), symbol_list_sym_new ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]))); }
     break;
 
   case 62:
 
 /* Line 1280 of yacc.c  */
-#line 429 "parse-gram.y"
+#line 433 "parse-gram.y"
     { (yyval.list) = (yyvsp[(1) - (1)].list); }
     break;
 
   case 63:
 
 /* Line 1280 of yacc.c  */
-#line 430 "parse-gram.y"
+#line 434 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), (yyvsp[(2) - (2)].list)); }
     break;
 
   case 64:
 
 /* Line 1280 of yacc.c  */
-#line 434 "parse-gram.y"
+#line 438 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 65:
 
 /* Line 1280 of yacc.c  */
-#line 435 "parse-gram.y"
+#line 439 "parse-gram.y"
     { (yyval.list) = symbol_list_type_new ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 66:
 
 /* Line 1280 of yacc.c  */
-#line 436 "parse-gram.y"
+#line 440 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagged_new ((yylsp[(1) - (1)])); }
     break;
 
   case 67:
 
 /* Line 1280 of yacc.c  */
-#line 437 "parse-gram.y"
+#line 441 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagless_new ((yylsp[(1) - (1)])); }
     break;
 
   case 68:
 
 /* Line 1280 of yacc.c  */
-#line 443 "parse-gram.y"
+#line 447 "parse-gram.y"
     {
        current_type = (yyvsp[(1) - (1)].uniqstr);
        tag_seen = true;
@@ -2410,7 +2414,7 @@ yyreduce:
   case 69:
 
 /* Line 1280 of yacc.c  */
-#line 448 "parse-gram.y"
+#line 452 "parse-gram.y"
     {
        symbol_class_set ((yyvsp[(1) - (1)].symbol), current_class, (yylsp[(1) - (1)]), true);
        symbol_type_set ((yyvsp[(1) - (1)].symbol), current_type, (yylsp[(1) - (1)]));
@@ -2420,7 +2424,7 @@ yyreduce:
   case 70:
 
 /* Line 1280 of yacc.c  */
-#line 453 "parse-gram.y"
+#line 457 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
       symbol_type_set ((yyvsp[(1) - (2)].symbol), current_type, (yylsp[(1) - (2)]));
@@ -2431,7 +2435,7 @@ yyreduce:
   case 71:
 
 /* Line 1280 of yacc.c  */
-#line 459 "parse-gram.y"
+#line 463 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
       symbol_type_set ((yyvsp[(1) - (2)].symbol), current_type, (yylsp[(1) - (2)]));
@@ -2442,7 +2446,7 @@ yyreduce:
   case 72:
 
 /* Line 1280 of yacc.c  */
-#line 465 "parse-gram.y"
+#line 469 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (3)].symbol), current_class, (yylsp[(1) - (3)]), true);
       symbol_type_set ((yyvsp[(1) - (3)].symbol), current_type, (yylsp[(1) - (3)]));
@@ -2454,7 +2458,7 @@ yyreduce:
   case 79:
 
 /* Line 1280 of yacc.c  */
-#line 495 "parse-gram.y"
+#line 499 "parse-gram.y"
     {
       yyerrok;
     }
@@ -2463,70 +2467,70 @@ yyreduce:
   case 80:
 
 /* Line 1280 of yacc.c  */
-#line 501 "parse-gram.y"
+#line 505 "parse-gram.y"
     { current_lhs = (yyvsp[(1) - (1)].symbol); current_lhs_location = (yylsp[(1) - (1)]); }
     break;
 
   case 82:
 
 /* Line 1280 of yacc.c  */
-#line 505 "parse-gram.y"
+#line 509 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(1) - (1)])); }
     break;
 
   case 83:
 
 /* Line 1280 of yacc.c  */
-#line 506 "parse-gram.y"
+#line 510 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(3) - (3)])); }
     break;
 
   case 85:
 
 /* Line 1280 of yacc.c  */
-#line 512 "parse-gram.y"
+#line 516 "parse-gram.y"
     { grammar_current_rule_begin (current_lhs, current_lhs_location); }
     break;
 
   case 86:
 
 /* Line 1280 of yacc.c  */
-#line 514 "parse-gram.y"
+#line 518 "parse-gram.y"
     { grammar_current_rule_symbol_append ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)])); }
     break;
 
   case 87:
 
 /* Line 1280 of yacc.c  */
-#line 516 "parse-gram.y"
+#line 520 "parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
     break;
 
   case 88:
 
 /* Line 1280 of yacc.c  */
-#line 518 "parse-gram.y"
+#line 522 "parse-gram.y"
     { grammar_current_rule_prec_set ((yyvsp[(3) - (3)].symbol), (yylsp[(3) - (3)])); }
     break;
 
   case 89:
 
 /* Line 1280 of yacc.c  */
-#line 520 "parse-gram.y"
+#line 524 "parse-gram.y"
     { grammar_current_rule_dprec_set ((yyvsp[(3) - (3)].integer), (yylsp[(3) - (3)])); }
     break;
 
   case 90:
 
 /* Line 1280 of yacc.c  */
-#line 522 "parse-gram.y"
+#line 526 "parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[(3) - (3)].uniqstr), (yylsp[(3) - (3)])); }
     break;
 
   case 93:
 
 /* Line 1280 of yacc.c  */
-#line 538 "parse-gram.y"
+#line 542 "parse-gram.y"
     {
       static char one[] = "1";
       (yyval.chars) = one;
@@ -2536,7 +2540,7 @@ yyreduce:
   case 95:
 
 /* Line 1280 of yacc.c  */
-#line 548 "parse-gram.y"
+#line 552 "parse-gram.y"
     {
       code_props plain_code;
       (yyvsp[(1) - (1)].code)[strlen ((yyvsp[(1) - (1)].code)) - 1] = '\n';
@@ -2550,14 +2554,14 @@ yyreduce:
   case 96:
 
 /* Line 1280 of yacc.c  */
-#line 568 "parse-gram.y"
+#line 572 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 97:
 
 /* Line 1280 of yacc.c  */
-#line 570 "parse-gram.y"
+#line 574 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[(1) - (1)].character)), (yylsp[(1) - (1)]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[(1) - (1)]), false);
@@ -2568,14 +2572,14 @@ yyreduce:
   case 98:
 
 /* Line 1280 of yacc.c  */
-#line 578 "parse-gram.y"
+#line 582 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 101:
 
 /* Line 1280 of yacc.c  */
-#line 590 "parse-gram.y"
+#line 594 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[(1) - (1)].chars)), (yylsp[(1) - (1)]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[(1) - (1)]), false);
@@ -2585,7 +2589,7 @@ yyreduce:
   case 103:
 
 /* Line 1280 of yacc.c  */
-#line 599 "parse-gram.y"
+#line 603 "parse-gram.y"
     {
       code_props plain_code;
       code_props_plain_init (&plain_code, (yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)]));
@@ -2599,7 +2603,7 @@ yyreduce:
 
 
 /* Line 1280 of yacc.c  */
-#line 2603 "parse-gram.c"
+#line 2607 "parse-gram.c"
       default: break;
     }
   YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);
@@ -2818,7 +2822,7 @@ yyreturn:
 
 
 /* Line 1497 of yacc.c  */
-#line 609 "parse-gram.y"
+#line 613 "parse-gram.y"
 
 
 
