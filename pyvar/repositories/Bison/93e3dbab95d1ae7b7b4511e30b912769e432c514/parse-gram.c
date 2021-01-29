@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 2.6.22-9f3f1.  */
+/* A Bison parser, made by GNU Bison 2.6.26-54c4-dirty.  */
 
 /* Bison implementation for Yacc-like parsers in C
    
@@ -44,7 +44,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "2.6.22-9f3f1"
+#define YYBISON_VERSION "2.6.26-54c4-dirty"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -693,14 +693,14 @@ static const yytype_uint16 yyrline[] =
        0,   229,   229,   237,   239,   243,   244,   254,   255,   260,
      261,   266,   267,   268,   269,   270,   271,   276,   285,   286,
      287,   288,   289,   290,   291,   292,   293,   294,   295,   310,
-     311,   335,   336,   337,   338,   342,   343,   344,   348,   355,
-     362,   366,   370,   377,   392,   393,   397,   409,   409,   414,
-     414,   419,   430,   445,   446,   447,   451,   452,   457,   459,
-     464,   465,   470,   472,   477,   478,   482,   483,   484,   485,
-     490,   495,   500,   506,   512,   523,   524,   533,   534,   540,
-     541,   542,   549,   549,   557,   558,   559,   564,   566,   568,
-     570,   572,   574,   579,   581,   592,   593,   598,   599,   600,
-     609,   629,   631,   640,   645,   646,   651,   658,   660
+     311,   335,   336,   337,   338,   342,   343,   344,   348,   360,
+     372,   376,   380,   387,   402,   403,   407,   419,   419,   424,
+     424,   429,   440,   455,   456,   457,   461,   462,   467,   469,
+     474,   475,   480,   482,   487,   488,   492,   493,   494,   495,
+     500,   505,   510,   516,   522,   533,   534,   543,   544,   550,
+     551,   552,   559,   559,   567,   568,   569,   574,   576,   578,
+     580,   582,   584,   589,   591,   602,   603,   608,   609,   610,
+     619,   639,   641,   650,   655,   656,   661,   668,   670
 };
 #endif
 
@@ -2481,29 +2481,39 @@ yyreduce:
 /* Line 1788 of yacc.c  */
 #line 349 "parse-gram.y"
     {
-      symbol_list *list;
-      for (list = (yyvsp[(3) - (3)].list); list; list = list->next)
-	symbol_list_destructor_set (list, (yyvsp[(2) - (3)].code), (yylsp[(2) - (3)]));
-      symbol_list_free ((yyvsp[(3) - (3)].list));
+      code_props code;
+      code_props_symbol_action_init (&code, (yyvsp[(2) - (3)].code), (yylsp[(2) - (3)]));
+      code_props_translate_code (&code);
+      {
+        symbol_list *list;
+        for (list = (yyvsp[(3) - (3)].list); list; list = list->next)
+          symbol_list_destructor_set (list, &code);
+        symbol_list_free ((yyvsp[(3) - (3)].list));
+      }
     }
     break;
 
   case 39:
 
 /* Line 1788 of yacc.c  */
-#line 356 "parse-gram.y"
+#line 361 "parse-gram.y"
     {
-      symbol_list *list;
-      for (list = (yyvsp[(3) - (3)].list); list; list = list->next)
-	symbol_list_printer_set (list, (yyvsp[(2) - (3)].code), (yylsp[(2) - (3)]));
-      symbol_list_free ((yyvsp[(3) - (3)].list));
+      code_props code;
+      code_props_symbol_action_init (&code, (yyvsp[(2) - (3)].code), (yylsp[(2) - (3)]));
+      code_props_translate_code (&code);
+      {
+        symbol_list *list;
+        for (list = (yyvsp[(3) - (3)].list); list; list = list->next)
+          symbol_list_printer_set (list, &code);
+        symbol_list_free ((yyvsp[(3) - (3)].list));
+      }
     }
     break;
 
   case 40:
 
 /* Line 1788 of yacc.c  */
-#line 363 "parse-gram.y"
+#line 373 "parse-gram.y"
     {
       default_prec = true;
     }
@@ -2512,7 +2522,7 @@ yyreduce:
   case 41:
 
 /* Line 1788 of yacc.c  */
-#line 367 "parse-gram.y"
+#line 377 "parse-gram.y"
     {
       default_prec = false;
     }
@@ -2521,7 +2531,7 @@ yyreduce:
   case 42:
 
 /* Line 1788 of yacc.c  */
-#line 371 "parse-gram.y"
+#line 381 "parse-gram.y"
     {
       /* Do not invoke muscle_percent_code_grow here since it invokes
          muscle_user_name_list_grow.  */
@@ -2533,7 +2543,7 @@ yyreduce:
   case 43:
 
 /* Line 1788 of yacc.c  */
-#line 378 "parse-gram.y"
+#line 388 "parse-gram.y"
     {
       muscle_percent_code_grow ((yyvsp[(2) - (3)].uniqstr), (yylsp[(2) - (3)]), (yyvsp[(3) - (3)].chars), (yylsp[(3) - (3)]));
       code_scanner_last_string_free ();
@@ -2543,21 +2553,21 @@ yyreduce:
   case 44:
 
 /* Line 1788 of yacc.c  */
-#line 392 "parse-gram.y"
+#line 402 "parse-gram.y"
     {}
     break;
 
   case 45:
 
 /* Line 1788 of yacc.c  */
-#line 393 "parse-gram.y"
+#line 403 "parse-gram.y"
     { muscle_code_grow ("union_name", (yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 46:
 
 /* Line 1788 of yacc.c  */
-#line 398 "parse-gram.y"
+#line 408 "parse-gram.y"
     {
       union_seen = true;
       muscle_code_grow ("stype", (yyvsp[(3) - (3)].chars), (yylsp[(3) - (3)]));
@@ -2568,14 +2578,14 @@ yyreduce:
   case 47:
 
 /* Line 1788 of yacc.c  */
-#line 409 "parse-gram.y"
+#line 419 "parse-gram.y"
     { current_class = nterm_sym; }
     break;
 
   case 48:
 
 /* Line 1788 of yacc.c  */
-#line 410 "parse-gram.y"
+#line 420 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
@@ -2585,14 +2595,14 @@ yyreduce:
   case 49:
 
 /* Line 1788 of yacc.c  */
-#line 414 "parse-gram.y"
+#line 424 "parse-gram.y"
     { current_class = token_sym; }
     break;
 
   case 50:
 
 /* Line 1788 of yacc.c  */
-#line 415 "parse-gram.y"
+#line 425 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
@@ -2602,7 +2612,7 @@ yyreduce:
   case 51:
 
 /* Line 1788 of yacc.c  */
-#line 420 "parse-gram.y"
+#line 430 "parse-gram.y"
     {
       symbol_list *list;
       tag_seen = true;
@@ -2615,7 +2625,7 @@ yyreduce:
   case 52:
 
 /* Line 1788 of yacc.c  */
-#line 431 "parse-gram.y"
+#line 441 "parse-gram.y"
     {
       symbol_list *list;
       ++current_prec;
@@ -2632,126 +2642,126 @@ yyreduce:
   case 53:
 
 /* Line 1788 of yacc.c  */
-#line 445 "parse-gram.y"
+#line 455 "parse-gram.y"
     { (yyval.assoc) = left_assoc; }
     break;
 
   case 54:
 
 /* Line 1788 of yacc.c  */
-#line 446 "parse-gram.y"
+#line 456 "parse-gram.y"
     { (yyval.assoc) = right_assoc; }
     break;
 
   case 55:
 
 /* Line 1788 of yacc.c  */
-#line 447 "parse-gram.y"
+#line 457 "parse-gram.y"
     { (yyval.assoc) = non_assoc; }
     break;
 
   case 56:
 
 /* Line 1788 of yacc.c  */
-#line 451 "parse-gram.y"
+#line 461 "parse-gram.y"
     { current_type = NULL; }
     break;
 
   case 57:
 
 /* Line 1788 of yacc.c  */
-#line 452 "parse-gram.y"
+#line 462 "parse-gram.y"
     { current_type = (yyvsp[(1) - (1)].uniqstr); tag_seen = true; }
     break;
 
   case 58:
 
 /* Line 1788 of yacc.c  */
-#line 458 "parse-gram.y"
+#line 468 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 59:
 
 /* Line 1788 of yacc.c  */
-#line 460 "parse-gram.y"
+#line 470 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), symbol_list_sym_new ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]))); }
     break;
 
   case 60:
 
 /* Line 1788 of yacc.c  */
-#line 464 "parse-gram.y"
+#line 474 "parse-gram.y"
     { (yyval.symbol) = (yyvsp[(1) - (1)].symbol); }
     break;
 
   case 61:
 
 /* Line 1788 of yacc.c  */
-#line 465 "parse-gram.y"
+#line 475 "parse-gram.y"
     { (yyval.symbol) = (yyvsp[(1) - (2)].symbol); symbol_user_token_number_set ((yyvsp[(1) - (2)].symbol), (yyvsp[(2) - (2)].integer), (yylsp[(2) - (2)])); }
     break;
 
   case 62:
 
 /* Line 1788 of yacc.c  */
-#line 471 "parse-gram.y"
+#line 481 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 63:
 
 /* Line 1788 of yacc.c  */
-#line 473 "parse-gram.y"
+#line 483 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), symbol_list_sym_new ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]))); }
     break;
 
   case 64:
 
 /* Line 1788 of yacc.c  */
-#line 477 "parse-gram.y"
+#line 487 "parse-gram.y"
     { (yyval.list) = (yyvsp[(1) - (1)].list); }
     break;
 
   case 65:
 
 /* Line 1788 of yacc.c  */
-#line 478 "parse-gram.y"
+#line 488 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), (yyvsp[(2) - (2)].list)); }
     break;
 
   case 66:
 
 /* Line 1788 of yacc.c  */
-#line 482 "parse-gram.y"
+#line 492 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 67:
 
 /* Line 1788 of yacc.c  */
-#line 483 "parse-gram.y"
+#line 493 "parse-gram.y"
     { (yyval.list) = symbol_list_type_new ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 68:
 
 /* Line 1788 of yacc.c  */
-#line 484 "parse-gram.y"
+#line 494 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagged_new ((yylsp[(1) - (1)])); }
     break;
 
   case 69:
 
 /* Line 1788 of yacc.c  */
-#line 485 "parse-gram.y"
+#line 495 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagless_new ((yylsp[(1) - (1)])); }
     break;
 
   case 70:
 
 /* Line 1788 of yacc.c  */
-#line 491 "parse-gram.y"
+#line 501 "parse-gram.y"
     {
        current_type = (yyvsp[(1) - (1)].uniqstr);
        tag_seen = true;
@@ -2761,7 +2771,7 @@ yyreduce:
   case 71:
 
 /* Line 1788 of yacc.c  */
-#line 496 "parse-gram.y"
+#line 506 "parse-gram.y"
     {
        symbol_class_set ((yyvsp[(1) - (1)].symbol), current_class, (yylsp[(1) - (1)]), true);
        symbol_type_set ((yyvsp[(1) - (1)].symbol), current_type, (yylsp[(1) - (1)]));
@@ -2771,7 +2781,7 @@ yyreduce:
   case 72:
 
 /* Line 1788 of yacc.c  */
-#line 501 "parse-gram.y"
+#line 511 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
       symbol_type_set ((yyvsp[(1) - (2)].symbol), current_type, (yylsp[(1) - (2)]));
@@ -2782,7 +2792,7 @@ yyreduce:
   case 73:
 
 /* Line 1788 of yacc.c  */
-#line 507 "parse-gram.y"
+#line 517 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
       symbol_type_set ((yyvsp[(1) - (2)].symbol), current_type, (yylsp[(1) - (2)]));
@@ -2793,7 +2803,7 @@ yyreduce:
   case 74:
 
 /* Line 1788 of yacc.c  */
-#line 513 "parse-gram.y"
+#line 523 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (3)].symbol), current_class, (yylsp[(1) - (3)]), true);
       symbol_type_set ((yyvsp[(1) - (3)].symbol), current_type, (yylsp[(1) - (3)]));
@@ -2805,7 +2815,7 @@ yyreduce:
   case 81:
 
 /* Line 1788 of yacc.c  */
-#line 543 "parse-gram.y"
+#line 553 "parse-gram.y"
     {
       yyerrok;
     }
@@ -2814,14 +2824,14 @@ yyreduce:
   case 82:
 
 /* Line 1788 of yacc.c  */
-#line 549 "parse-gram.y"
+#line 559 "parse-gram.y"
     { current_lhs ((yyvsp[(1) - (2)].symbol), (yylsp[(1) - (2)]), (yyvsp[(2) - (2)].named_ref)); }
     break;
 
   case 83:
 
 /* Line 1788 of yacc.c  */
-#line 550 "parse-gram.y"
+#line 560 "parse-gram.y"
     {
     /* Free the current lhs. */
     current_lhs (0, (yylsp[(1) - (4)]), 0);
@@ -2831,21 +2841,21 @@ yyreduce:
   case 84:
 
 /* Line 1788 of yacc.c  */
-#line 557 "parse-gram.y"
+#line 567 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(1) - (1)])); }
     break;
 
   case 85:
 
 /* Line 1788 of yacc.c  */
-#line 558 "parse-gram.y"
+#line 568 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(3) - (3)])); }
     break;
 
   case 87:
 
 /* Line 1788 of yacc.c  */
-#line 564 "parse-gram.y"
+#line 574 "parse-gram.y"
     { grammar_current_rule_begin (current_lhs_symbol, current_lhs_location,
 				  current_lhs_named_ref); }
     break;
@@ -2853,77 +2863,77 @@ yyreduce:
   case 88:
 
 /* Line 1788 of yacc.c  */
-#line 567 "parse-gram.y"
+#line 577 "parse-gram.y"
     { grammar_current_rule_symbol_append ((yyvsp[(2) - (3)].symbol), (yylsp[(2) - (3)]), (yyvsp[(3) - (3)].named_ref)); }
     break;
 
   case 89:
 
 /* Line 1788 of yacc.c  */
-#line 569 "parse-gram.y"
+#line 579 "parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[(2) - (3)].code), (yylsp[(2) - (3)]), (yyvsp[(3) - (3)].named_ref)); }
     break;
 
   case 90:
 
 /* Line 1788 of yacc.c  */
-#line 571 "parse-gram.y"
+#line 581 "parse-gram.y"
     { grammar_current_rule_prec_set ((yyvsp[(3) - (3)].symbol), (yylsp[(3) - (3)])); }
     break;
 
   case 91:
 
 /* Line 1788 of yacc.c  */
-#line 573 "parse-gram.y"
+#line 583 "parse-gram.y"
     { grammar_current_rule_dprec_set ((yyvsp[(3) - (3)].integer), (yylsp[(3) - (3)])); }
     break;
 
   case 92:
 
 /* Line 1788 of yacc.c  */
-#line 575 "parse-gram.y"
+#line 585 "parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[(3) - (3)].uniqstr), (yylsp[(3) - (3)])); }
     break;
 
   case 93:
 
 /* Line 1788 of yacc.c  */
-#line 579 "parse-gram.y"
+#line 589 "parse-gram.y"
     { (yyval.named_ref) = 0; }
     break;
 
   case 94:
 
 /* Line 1788 of yacc.c  */
-#line 581 "parse-gram.y"
+#line 591 "parse-gram.y"
     { (yyval.named_ref) = named_ref_new((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 96:
 
 /* Line 1788 of yacc.c  */
-#line 593 "parse-gram.y"
+#line 603 "parse-gram.y"
     { (yyval.uniqstr) = uniqstr_new ((yyvsp[(1) - (1)].chars)); }
     break;
 
   case 97:
 
 /* Line 1788 of yacc.c  */
-#line 598 "parse-gram.y"
+#line 608 "parse-gram.y"
     { (yyval.chars) = ""; }
     break;
 
   case 98:
 
 /* Line 1788 of yacc.c  */
-#line 599 "parse-gram.y"
+#line 609 "parse-gram.y"
     { (yyval.chars) = (yyvsp[(1) - (1)].uniqstr); }
     break;
 
   case 100:
 
 /* Line 1788 of yacc.c  */
-#line 610 "parse-gram.y"
+#line 620 "parse-gram.y"
     {
       code_props plain_code;
       (yyvsp[(1) - (1)].code)[strlen ((yyvsp[(1) - (1)].code)) - 1] = '\n';
@@ -2937,14 +2947,14 @@ yyreduce:
   case 101:
 
 /* Line 1788 of yacc.c  */
-#line 630 "parse-gram.y"
+#line 640 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 102:
 
 /* Line 1788 of yacc.c  */
-#line 632 "parse-gram.y"
+#line 642 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[(1) - (1)].character)), (yylsp[(1) - (1)]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[(1) - (1)]), false);
@@ -2955,14 +2965,14 @@ yyreduce:
   case 103:
 
 /* Line 1788 of yacc.c  */
-#line 640 "parse-gram.y"
+#line 650 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 106:
 
 /* Line 1788 of yacc.c  */
-#line 652 "parse-gram.y"
+#line 662 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[(1) - (1)].chars)), (yylsp[(1) - (1)]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[(1) - (1)]), false);
@@ -2972,7 +2982,7 @@ yyreduce:
   case 108:
 
 /* Line 1788 of yacc.c  */
-#line 661 "parse-gram.y"
+#line 671 "parse-gram.y"
     {
       code_props plain_code;
       code_props_plain_init (&plain_code, (yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)]));
@@ -2986,7 +2996,7 @@ yyreduce:
 
 
 /* Line 1788 of yacc.c  */
-#line 2990 "parse-gram.c"
+#line 3000 "parse-gram.c"
         default: break;
       }
     if (yychar_backup != yychar)
@@ -3236,7 +3246,7 @@ yyreturn:
 
 
 /* Line 2049 of yacc.c  */
-#line 671 "parse-gram.y"
+#line 681 "parse-gram.y"
 
 
 
