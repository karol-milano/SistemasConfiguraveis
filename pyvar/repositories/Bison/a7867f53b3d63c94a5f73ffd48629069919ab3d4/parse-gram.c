@@ -678,14 +678,14 @@ static const yytype_uint16 yyrline[] =
        0,   210,   210,   218,   220,   224,   225,   235,   236,   250,
      251,   256,   257,   258,   259,   260,   261,   266,   275,   276,
      277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
-     287,   288,   289,   290,   291,   292,   293,   297,   298,   299,
-     303,   310,   317,   321,   325,   330,   353,   354,   358,   370,
-     370,   375,   375,   380,   391,   406,   407,   408,   412,   413,
-     418,   420,   425,   426,   430,   431,   432,   433,   438,   443,
-     448,   454,   460,   471,   472,   481,   482,   488,   489,   490,
-     497,   497,   501,   502,   503,   508,   509,   511,   513,   515,
-     517,   527,   528,   534,   538,   547,   567,   569,   578,   583,
-     584,   589,   596,   598
+     287,   288,   289,   313,   314,   315,   316,   320,   321,   322,
+     326,   333,   340,   344,   348,   353,   376,   377,   381,   393,
+     393,   398,   398,   403,   414,   429,   430,   431,   435,   436,
+     441,   443,   448,   449,   453,   454,   455,   456,   461,   466,
+     471,   477,   483,   494,   495,   504,   505,   511,   512,   513,
+     520,   520,   524,   525,   526,   531,   532,   534,   536,   538,
+     540,   550,   551,   557,   561,   570,   590,   592,   601,   606,
+     607,   612,   619,   621
 };
 #endif
 
@@ -2105,35 +2105,57 @@ yyreduce:
   case 32:
 
 /* Line 1537 of yacc.c  */
-#line 289 "parse-gram.y"
-    { skeleton_arg ((yyvsp[(2) - (2)].chars), 1, &(yylsp[(1) - (2)])); }
+#line 290 "parse-gram.y"
+    {
+      char const *skeleton_user = (yyvsp[(2) - (2)].chars);
+      if (strchr (skeleton_user, '/'))
+        {
+          size_t dir_length = strlen (current_file);
+          char *skeleton_build;
+          while (dir_length && current_file[dir_length - 1] != '/')
+            --dir_length;
+          while (dir_length && current_file[dir_length - 1] == '/')
+            --dir_length;
+          skeleton_build =
+            xmalloc (dir_length + 1 + strlen (skeleton_user) + 1);
+          if (dir_length > 0)
+            {
+              strncpy (skeleton_build, current_file, dir_length);
+              skeleton_build[dir_length++] = '/';
+            }
+          strcpy (skeleton_build + dir_length, skeleton_user);
+          skeleton_user = uniqstr_new (skeleton_build);
+          free (skeleton_build);
+        }
+      skeleton_arg (skeleton_user, 1, &(yylsp[(1) - (2)]));
+    }
     break;
 
   case 33:
 
 /* Line 1537 of yacc.c  */
-#line 290 "parse-gram.y"
+#line 313 "parse-gram.y"
     { token_table_flag = true; }
     break;
 
   case 34:
 
 /* Line 1537 of yacc.c  */
-#line 291 "parse-gram.y"
+#line 314 "parse-gram.y"
     { report_flag = report_states; }
     break;
 
   case 35:
 
 /* Line 1537 of yacc.c  */
-#line 292 "parse-gram.y"
+#line 315 "parse-gram.y"
     { yacc_flag = true; }
     break;
 
   case 39:
 
 /* Line 1537 of yacc.c  */
-#line 300 "parse-gram.y"
+#line 323 "parse-gram.y"
     {
       grammar_start_symbol_set ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]));
     }
@@ -2142,7 +2164,7 @@ yyreduce:
   case 40:
 
 /* Line 1537 of yacc.c  */
-#line 304 "parse-gram.y"
+#line 327 "parse-gram.y"
     {
       symbol_list *list;
       for (list = (yyvsp[(3) - (3)].list); list; list = list->next)
@@ -2154,7 +2176,7 @@ yyreduce:
   case 41:
 
 /* Line 1537 of yacc.c  */
-#line 311 "parse-gram.y"
+#line 334 "parse-gram.y"
     {
       symbol_list *list;
       for (list = (yyvsp[(3) - (3)].list); list; list = list->next)
@@ -2166,7 +2188,7 @@ yyreduce:
   case 42:
 
 /* Line 1537 of yacc.c  */
-#line 318 "parse-gram.y"
+#line 341 "parse-gram.y"
     {
       default_prec = true;
     }
@@ -2175,7 +2197,7 @@ yyreduce:
   case 43:
 
 /* Line 1537 of yacc.c  */
-#line 322 "parse-gram.y"
+#line 345 "parse-gram.y"
     {
       default_prec = false;
     }
@@ -2184,7 +2206,7 @@ yyreduce:
   case 44:
 
 /* Line 1537 of yacc.c  */
-#line 326 "parse-gram.y"
+#line 349 "parse-gram.y"
     {
       muscle_code_grow ("percent_code_unqualified", (yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)]));
       code_scanner_last_string_free ();
@@ -2194,7 +2216,7 @@ yyreduce:
   case 45:
 
 /* Line 1537 of yacc.c  */
-#line 331 "parse-gram.y"
+#line 354 "parse-gram.y"
     {
       char const name_prefix[] = "percent_code(";
       size_t length = strlen ((yyvsp[(2) - (3)].uniqstr));
@@ -2212,21 +2234,21 @@ yyreduce:
   case 46:
 
 /* Line 1537 of yacc.c  */
-#line 353 "parse-gram.y"
+#line 376 "parse-gram.y"
     {}
     break;
 
   case 47:
 
 /* Line 1537 of yacc.c  */
-#line 354 "parse-gram.y"
+#line 377 "parse-gram.y"
     { muscle_code_grow ("union_name", (yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 48:
 
 /* Line 1537 of yacc.c  */
-#line 359 "parse-gram.y"
+#line 382 "parse-gram.y"
     {
       union_seen = true;
       muscle_code_grow ("stype", (yyvsp[(3) - (3)].chars), (yylsp[(3) - (3)]));
@@ -2237,14 +2259,14 @@ yyreduce:
   case 49:
 
 /* Line 1537 of yacc.c  */
-#line 370 "parse-gram.y"
+#line 393 "parse-gram.y"
     { current_class = nterm_sym; }
     break;
 
   case 50:
 
 /* Line 1537 of yacc.c  */
-#line 371 "parse-gram.y"
+#line 394 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
@@ -2254,14 +2276,14 @@ yyreduce:
   case 51:
 
 /* Line 1537 of yacc.c  */
-#line 375 "parse-gram.y"
+#line 398 "parse-gram.y"
     { current_class = token_sym; }
     break;
 
   case 52:
 
 /* Line 1537 of yacc.c  */
-#line 376 "parse-gram.y"
+#line 399 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
@@ -2271,7 +2293,7 @@ yyreduce:
   case 53:
 
 /* Line 1537 of yacc.c  */
-#line 381 "parse-gram.y"
+#line 404 "parse-gram.y"
     {
       symbol_list *list;
       tag_seen = true;
@@ -2284,7 +2306,7 @@ yyreduce:
   case 54:
 
 /* Line 1537 of yacc.c  */
-#line 392 "parse-gram.y"
+#line 415 "parse-gram.y"
     {
       symbol_list *list;
       ++current_prec;
@@ -2301,98 +2323,98 @@ yyreduce:
   case 55:
 
 /* Line 1537 of yacc.c  */
-#line 406 "parse-gram.y"
+#line 429 "parse-gram.y"
     { (yyval.assoc) = left_assoc; }
     break;
 
   case 56:
 
 /* Line 1537 of yacc.c  */
-#line 407 "parse-gram.y"
+#line 430 "parse-gram.y"
     { (yyval.assoc) = right_assoc; }
     break;
 
   case 57:
 
 /* Line 1537 of yacc.c  */
-#line 408 "parse-gram.y"
+#line 431 "parse-gram.y"
     { (yyval.assoc) = non_assoc; }
     break;
 
   case 58:
 
 /* Line 1537 of yacc.c  */
-#line 412 "parse-gram.y"
+#line 435 "parse-gram.y"
     { current_type = NULL; }
     break;
 
   case 59:
 
 /* Line 1537 of yacc.c  */
-#line 413 "parse-gram.y"
+#line 436 "parse-gram.y"
     { current_type = (yyvsp[(1) - (1)].uniqstr); tag_seen = true; }
     break;
 
   case 60:
 
 /* Line 1537 of yacc.c  */
-#line 419 "parse-gram.y"
+#line 442 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 61:
 
 /* Line 1537 of yacc.c  */
-#line 421 "parse-gram.y"
+#line 444 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), symbol_list_sym_new ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]))); }
     break;
 
   case 62:
 
 /* Line 1537 of yacc.c  */
-#line 425 "parse-gram.y"
+#line 448 "parse-gram.y"
     { (yyval.list) = (yyvsp[(1) - (1)].list); }
     break;
 
   case 63:
 
 /* Line 1537 of yacc.c  */
-#line 426 "parse-gram.y"
+#line 449 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), (yyvsp[(2) - (2)].list)); }
     break;
 
   case 64:
 
 /* Line 1537 of yacc.c  */
-#line 430 "parse-gram.y"
+#line 453 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 65:
 
 /* Line 1537 of yacc.c  */
-#line 431 "parse-gram.y"
+#line 454 "parse-gram.y"
     { (yyval.list) = symbol_list_type_new ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 66:
 
 /* Line 1537 of yacc.c  */
-#line 432 "parse-gram.y"
+#line 455 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagged_new ((yylsp[(1) - (1)])); }
     break;
 
   case 67:
 
 /* Line 1537 of yacc.c  */
-#line 433 "parse-gram.y"
+#line 456 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagless_new ((yylsp[(1) - (1)])); }
     break;
 
   case 68:
 
 /* Line 1537 of yacc.c  */
-#line 439 "parse-gram.y"
+#line 462 "parse-gram.y"
     {
        current_type = (yyvsp[(1) - (1)].uniqstr);
        tag_seen = true;
@@ -2402,7 +2424,7 @@ yyreduce:
   case 69:
 
 /* Line 1537 of yacc.c  */
-#line 444 "parse-gram.y"
+#line 467 "parse-gram.y"
     {
        symbol_class_set ((yyvsp[(1) - (1)].symbol), current_class, (yylsp[(1) - (1)]), true);
        symbol_type_set ((yyvsp[(1) - (1)].symbol), current_type, (yylsp[(1) - (1)]));
@@ -2412,7 +2434,7 @@ yyreduce:
   case 70:
 
 /* Line 1537 of yacc.c  */
-#line 449 "parse-gram.y"
+#line 472 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
       symbol_type_set ((yyvsp[(1) - (2)].symbol), current_type, (yylsp[(1) - (2)]));
@@ -2423,7 +2445,7 @@ yyreduce:
   case 71:
 
 /* Line 1537 of yacc.c  */
-#line 455 "parse-gram.y"
+#line 478 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
       symbol_type_set ((yyvsp[(1) - (2)].symbol), current_type, (yylsp[(1) - (2)]));
@@ -2434,7 +2456,7 @@ yyreduce:
   case 72:
 
 /* Line 1537 of yacc.c  */
-#line 461 "parse-gram.y"
+#line 484 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (3)].symbol), current_class, (yylsp[(1) - (3)]), true);
       symbol_type_set ((yyvsp[(1) - (3)].symbol), current_type, (yylsp[(1) - (3)]));
@@ -2446,7 +2468,7 @@ yyreduce:
   case 79:
 
 /* Line 1537 of yacc.c  */
-#line 491 "parse-gram.y"
+#line 514 "parse-gram.y"
     {
       yyerrok;
     }
@@ -2455,77 +2477,77 @@ yyreduce:
   case 80:
 
 /* Line 1537 of yacc.c  */
-#line 497 "parse-gram.y"
+#line 520 "parse-gram.y"
     { current_lhs = (yyvsp[(1) - (1)].symbol); current_lhs_location = (yylsp[(1) - (1)]); }
     break;
 
   case 82:
 
 /* Line 1537 of yacc.c  */
-#line 501 "parse-gram.y"
+#line 524 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(1) - (1)])); }
     break;
 
   case 83:
 
 /* Line 1537 of yacc.c  */
-#line 502 "parse-gram.y"
+#line 525 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(3) - (3)])); }
     break;
 
   case 85:
 
 /* Line 1537 of yacc.c  */
-#line 508 "parse-gram.y"
+#line 531 "parse-gram.y"
     { grammar_current_rule_begin (current_lhs, current_lhs_location); }
     break;
 
   case 86:
 
 /* Line 1537 of yacc.c  */
-#line 510 "parse-gram.y"
+#line 533 "parse-gram.y"
     { grammar_current_rule_symbol_append ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)])); }
     break;
 
   case 87:
 
 /* Line 1537 of yacc.c  */
-#line 512 "parse-gram.y"
+#line 535 "parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
     break;
 
   case 88:
 
 /* Line 1537 of yacc.c  */
-#line 514 "parse-gram.y"
+#line 537 "parse-gram.y"
     { grammar_current_rule_prec_set ((yyvsp[(3) - (3)].symbol), (yylsp[(3) - (3)])); }
     break;
 
   case 89:
 
 /* Line 1537 of yacc.c  */
-#line 516 "parse-gram.y"
+#line 539 "parse-gram.y"
     { grammar_current_rule_dprec_set ((yyvsp[(3) - (3)].integer), (yylsp[(3) - (3)])); }
     break;
 
   case 90:
 
 /* Line 1537 of yacc.c  */
-#line 518 "parse-gram.y"
+#line 541 "parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[(3) - (3)].uniqstr), (yylsp[(3) - (3)])); }
     break;
 
   case 92:
 
 /* Line 1537 of yacc.c  */
-#line 528 "parse-gram.y"
+#line 551 "parse-gram.y"
     { (yyval.uniqstr) = uniqstr_new ((yyvsp[(1) - (1)].chars)); }
     break;
 
   case 93:
 
 /* Line 1537 of yacc.c  */
-#line 534 "parse-gram.y"
+#line 557 "parse-gram.y"
     {
       static char one[] = "1";
       (yyval.chars) = one;
@@ -2535,7 +2557,7 @@ yyreduce:
   case 95:
 
 /* Line 1537 of yacc.c  */
-#line 548 "parse-gram.y"
+#line 571 "parse-gram.y"
     {
       code_props plain_code;
       (yyvsp[(1) - (1)].code)[strlen ((yyvsp[(1) - (1)].code)) - 1] = '\n';
@@ -2549,14 +2571,14 @@ yyreduce:
   case 96:
 
 /* Line 1537 of yacc.c  */
-#line 568 "parse-gram.y"
+#line 591 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 97:
 
 /* Line 1537 of yacc.c  */
-#line 570 "parse-gram.y"
+#line 593 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[(1) - (1)].character)), (yylsp[(1) - (1)]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[(1) - (1)]), false);
@@ -2567,14 +2589,14 @@ yyreduce:
   case 98:
 
 /* Line 1537 of yacc.c  */
-#line 578 "parse-gram.y"
+#line 601 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 101:
 
 /* Line 1537 of yacc.c  */
-#line 590 "parse-gram.y"
+#line 613 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[(1) - (1)].chars)), (yylsp[(1) - (1)]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[(1) - (1)]), false);
@@ -2584,7 +2606,7 @@ yyreduce:
   case 103:
 
 /* Line 1537 of yacc.c  */
-#line 599 "parse-gram.y"
+#line 622 "parse-gram.y"
     {
       code_props plain_code;
       code_props_plain_init (&plain_code, (yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)]));
@@ -2598,7 +2620,7 @@ yyreduce:
 
 
 /* Line 1537 of yacc.c  */
-#line 2602 "parse-gram.c"
+#line 2624 "parse-gram.c"
       default: break;
     }
   YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);
@@ -2817,7 +2839,7 @@ yyreturn:
 
 
 /* Line 1537 of yacc.c  */
-#line 609 "parse-gram.y"
+#line 632 "parse-gram.y"
 
 
 
