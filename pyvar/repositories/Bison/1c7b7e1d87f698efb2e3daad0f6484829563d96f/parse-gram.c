@@ -1,3 +1,4 @@
+
 /* A Bison parser, made by GNU Bison 2.3a+.  */
 
 /* Skeleton implementation for Bison's Yacc-like parsers in C
@@ -157,7 +158,7 @@ static int current_prec = 0;
 
 
 /* Line 171 of yacc.c  */
-#line 161 "parse-gram.c"
+#line 162 "parse-gram.c"
 
 /* Enabling traces.  */
 #ifndef YYDEBUG
@@ -322,7 +323,7 @@ typedef union YYSTYPE
 }
 
 /* Line 205 of yacc.c  */
-#line 326 "parse-gram.c"
+#line 327 "parse-gram.c"
 	YYSTYPE;
 # define YYSTYPE_IS_TRIVIAL 1
 # define yystype YYSTYPE /* obsolescent; will be withdrawn */
@@ -347,7 +348,7 @@ typedef struct YYLTYPE
 
 
 /* Line 228 of yacc.c  */
-#line 351 "parse-gram.c"
+#line 352 "parse-gram.c"
 
 #ifdef short
 # undef short
@@ -676,13 +677,13 @@ static const yytype_uint16 yyrline[] =
      238,   243,   244,   245,   246,   247,   248,   253,   262,   263,
      264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
      274,   275,   276,   277,   278,   279,   280,   284,   285,   286,
-     290,   297,   304,   308,   312,   317,   338,   339,   343,   372,
-     372,   377,   377,   382,   393,   408,   409,   410,   414,   415,
-     420,   422,   427,   428,   432,   433,   434,   435,   440,   445,
-     450,   456,   462,   473,   474,   483,   484,   490,   491,   492,
-     499,   499,   503,   504,   505,   510,   511,   513,   515,   517,
-     519,   529,   530,   536,   540,   545,   565,   567,   576,   581,
-     582,   587,   594,   596
+     290,   297,   304,   308,   312,   317,   340,   341,   345,   374,
+     374,   379,   379,   384,   395,   410,   411,   412,   416,   417,
+     422,   424,   429,   430,   434,   435,   436,   437,   442,   447,
+     452,   458,   464,   475,   476,   485,   486,   492,   493,   494,
+     501,   501,   505,   506,   507,   512,   513,   515,   517,   519,
+     521,   531,   532,   538,   542,   547,   567,   569,   578,   583,
+     584,   589,   596,   598
 };
 #endif
 
@@ -1048,7 +1049,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 	{ fputs (quotearg_style (c_quoting_style, (yyvaluep->chars)), stderr); };
 
 /* Line 681 of yacc.c  */
-#line 1052 "parse-gram.c"
+#line 1053 "parse-gram.c"
 	break;
       case 4: /* "\"integer\"" */
 
@@ -1057,7 +1058,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 	{ fprintf (stderr, "%d", (yyvaluep->integer)); };
 
 /* Line 681 of yacc.c  */
-#line 1061 "parse-gram.c"
+#line 1062 "parse-gram.c"
 	break;
       case 45: /* "\"{...}\"" */
 
@@ -1066,7 +1067,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->code)); };
 
 /* Line 681 of yacc.c  */
-#line 1070 "parse-gram.c"
+#line 1071 "parse-gram.c"
 	break;
       case 46: /* "\"char\"" */
 
@@ -1075,7 +1076,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 	{ fputs (char_name ((yyvaluep->character)), stderr); };
 
 /* Line 681 of yacc.c  */
-#line 1079 "parse-gram.c"
+#line 1080 "parse-gram.c"
 	break;
       case 47: /* "\"epilogue\"" */
 
@@ -1084,7 +1085,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
 /* Line 681 of yacc.c  */
-#line 1088 "parse-gram.c"
+#line 1089 "parse-gram.c"
 	break;
       case 49: /* "\"identifier\"" */
 
@@ -1093,7 +1094,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 	{ fputs ((yyvaluep->uniqstr), stderr); };
 
 /* Line 681 of yacc.c  */
-#line 1097 "parse-gram.c"
+#line 1098 "parse-gram.c"
 	break;
       case 50: /* "\"identifier:\"" */
 
@@ -1102,7 +1103,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 	{ fprintf (stderr, "%s:", (yyvaluep->uniqstr)); };
 
 /* Line 681 of yacc.c  */
-#line 1106 "parse-gram.c"
+#line 1107 "parse-gram.c"
 	break;
       case 53: /* "\"%{...%}\"" */
 
@@ -1111,7 +1112,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
 /* Line 681 of yacc.c  */
-#line 1115 "parse-gram.c"
+#line 1116 "parse-gram.c"
 	break;
       case 55: /* "\"type\"" */
 
@@ -1120,7 +1121,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 	{ fprintf (stderr, "<%s>", (yyvaluep->uniqstr)); };
 
 /* Line 681 of yacc.c  */
-#line 1124 "parse-gram.c"
+#line 1125 "parse-gram.c"
 	break;
       case 82: /* "content" */
 
@@ -1129,7 +1130,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
 /* Line 681 of yacc.c  */
-#line 1133 "parse-gram.c"
+#line 1134 "parse-gram.c"
 	break;
       case 83: /* "content.opt" */
 
@@ -1138,7 +1139,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
 /* Line 681 of yacc.c  */
-#line 1142 "parse-gram.c"
+#line 1143 "parse-gram.c"
 	break;
       case 84: /* "braceless" */
 
@@ -1147,7 +1148,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
 /* Line 681 of yacc.c  */
-#line 1151 "parse-gram.c"
+#line 1152 "parse-gram.c"
 	break;
       case 85: /* "id" */
 
@@ -1156,7 +1157,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
 /* Line 681 of yacc.c  */
-#line 1160 "parse-gram.c"
+#line 1161 "parse-gram.c"
 	break;
       case 86: /* "id_colon" */
 
@@ -1165,7 +1166,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 	{ fprintf (stderr, "%s:", (yyvaluep->symbol)->tag); };
 
 /* Line 681 of yacc.c  */
-#line 1169 "parse-gram.c"
+#line 1170 "parse-gram.c"
 	break;
       case 87: /* "symbol" */
 
@@ -1174,7 +1175,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
 /* Line 681 of yacc.c  */
-#line 1178 "parse-gram.c"
+#line 1179 "parse-gram.c"
 	break;
       case 88: /* "string_as_id" */
 
@@ -1183,7 +1184,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
 /* Line 681 of yacc.c  */
-#line 1187 "parse-gram.c"
+#line 1188 "parse-gram.c"
 	break;
       default:
 	break;
@@ -1707,7 +1708,7 @@ YYLTYPE yylloc;
 }
 
 /* Line 1093 of yacc.c  */
-#line 1711 "parse-gram.c"
+#line 1712 "parse-gram.c"
   yylsp[0] = yylloc;
   goto yysetstate;
 
@@ -2193,28 +2194,30 @@ yyreduce:
       muscle_code_grow (uniqstr_new (name), (yyvsp[(3) - (3)].chars), (yylsp[(3) - (3)]));
       free (name);
       code_scanner_last_string_free ();
-      muscle_grow ("used_percent_code_qualifiers", (yyvsp[(2) - (3)].chars), ",");
+      muscle_grow ("used_percent_code_qualifiers", "[[", ",");
+      muscle_grow ("used_percent_code_qualifiers", (yyvsp[(2) - (3)].chars), "");
+      muscle_grow ("used_percent_code_qualifiers", "]]", "");
     }
     break;
 
   case 46:
 
 /* Line 1280 of yacc.c  */
-#line 338 "parse-gram.y"
+#line 340 "parse-gram.y"
     {}
     break;
 
   case 47:
 
 /* Line 1280 of yacc.c  */
-#line 339 "parse-gram.y"
+#line 341 "parse-gram.y"
     { muscle_code_grow ("union_name", (yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 48:
 
 /* Line 1280 of yacc.c  */
-#line 344 "parse-gram.y"
+#line 346 "parse-gram.y"
     {
       char const *body = (yyvsp[(3) - (3)].code);
 
@@ -2242,14 +2245,14 @@ yyreduce:
   case 49:
 
 /* Line 1280 of yacc.c  */
-#line 372 "parse-gram.y"
+#line 374 "parse-gram.y"
     { current_class = nterm_sym; }
     break;
 
   case 50:
 
 /* Line 1280 of yacc.c  */
-#line 373 "parse-gram.y"
+#line 375 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
@@ -2259,14 +2262,14 @@ yyreduce:
   case 51:
 
 /* Line 1280 of yacc.c  */
-#line 377 "parse-gram.y"
+#line 379 "parse-gram.y"
     { current_class = token_sym; }
     break;
 
   case 52:
 
 /* Line 1280 of yacc.c  */
-#line 378 "parse-gram.y"
+#line 380 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
@@ -2276,7 +2279,7 @@ yyreduce:
   case 53:
 
 /* Line 1280 of yacc.c  */
-#line 383 "parse-gram.y"
+#line 385 "parse-gram.y"
     {
       symbol_list *list;
       tag_seen = true;
@@ -2289,7 +2292,7 @@ yyreduce:
   case 54:
 
 /* Line 1280 of yacc.c  */
-#line 394 "parse-gram.y"
+#line 396 "parse-gram.y"
     {
       symbol_list *list;
       ++current_prec;
@@ -2306,98 +2309,98 @@ yyreduce:
   case 55:
 
 /* Line 1280 of yacc.c  */
-#line 408 "parse-gram.y"
+#line 410 "parse-gram.y"
     { (yyval.assoc) = left_assoc; }
     break;
 
   case 56:
 
 /* Line 1280 of yacc.c  */
-#line 409 "parse-gram.y"
+#line 411 "parse-gram.y"
     { (yyval.assoc) = right_assoc; }
     break;
 
   case 57:
 
 /* Line 1280 of yacc.c  */
-#line 410 "parse-gram.y"
+#line 412 "parse-gram.y"
     { (yyval.assoc) = non_assoc; }
     break;
 
   case 58:
 
 /* Line 1280 of yacc.c  */
-#line 414 "parse-gram.y"
+#line 416 "parse-gram.y"
     { current_type = NULL; }
     break;
 
   case 59:
 
 /* Line 1280 of yacc.c  */
-#line 415 "parse-gram.y"
+#line 417 "parse-gram.y"
     { current_type = (yyvsp[(1) - (1)].uniqstr); tag_seen = true; }
     break;
 
   case 60:
 
 /* Line 1280 of yacc.c  */
-#line 421 "parse-gram.y"
+#line 423 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 61:
 
 /* Line 1280 of yacc.c  */
-#line 423 "parse-gram.y"
+#line 425 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), symbol_list_sym_new ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]))); }
     break;
 
   case 62:
 
 /* Line 1280 of yacc.c  */
-#line 427 "parse-gram.y"
+#line 429 "parse-gram.y"
     { (yyval.list) = (yyvsp[(1) - (1)].list); }
     break;
 
   case 63:
 
 /* Line 1280 of yacc.c  */
-#line 428 "parse-gram.y"
+#line 430 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), (yyvsp[(2) - (2)].list)); }
     break;
 
   case 64:
 
 /* Line 1280 of yacc.c  */
-#line 432 "parse-gram.y"
+#line 434 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 65:
 
 /* Line 1280 of yacc.c  */
-#line 433 "parse-gram.y"
+#line 435 "parse-gram.y"
     { (yyval.list) = symbol_list_type_new ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 66:
 
 /* Line 1280 of yacc.c  */
-#line 434 "parse-gram.y"
+#line 436 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagged_new ((yylsp[(1) - (1)])); }
     break;
 
   case 67:
 
 /* Line 1280 of yacc.c  */
-#line 435 "parse-gram.y"
+#line 437 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagless_new ((yylsp[(1) - (1)])); }
     break;
 
   case 68:
 
 /* Line 1280 of yacc.c  */
-#line 441 "parse-gram.y"
+#line 443 "parse-gram.y"
     {
        current_type = (yyvsp[(1) - (1)].uniqstr);
        tag_seen = true;
@@ -2407,7 +2410,7 @@ yyreduce:
   case 69:
 
 /* Line 1280 of yacc.c  */
-#line 446 "parse-gram.y"
+#line 448 "parse-gram.y"
     {
        symbol_class_set ((yyvsp[(1) - (1)].symbol), current_class, (yylsp[(1) - (1)]), true);
        symbol_type_set ((yyvsp[(1) - (1)].symbol), current_type, (yylsp[(1) - (1)]));
@@ -2417,7 +2420,7 @@ yyreduce:
   case 70:
 
 /* Line 1280 of yacc.c  */
-#line 451 "parse-gram.y"
+#line 453 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
       symbol_type_set ((yyvsp[(1) - (2)].symbol), current_type, (yylsp[(1) - (2)]));
@@ -2428,7 +2431,7 @@ yyreduce:
   case 71:
 
 /* Line 1280 of yacc.c  */
-#line 457 "parse-gram.y"
+#line 459 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
       symbol_type_set ((yyvsp[(1) - (2)].symbol), current_type, (yylsp[(1) - (2)]));
@@ -2439,7 +2442,7 @@ yyreduce:
   case 72:
 
 /* Line 1280 of yacc.c  */
-#line 463 "parse-gram.y"
+#line 465 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (3)].symbol), current_class, (yylsp[(1) - (3)]), true);
       symbol_type_set ((yyvsp[(1) - (3)].symbol), current_type, (yylsp[(1) - (3)]));
@@ -2451,7 +2454,7 @@ yyreduce:
   case 79:
 
 /* Line 1280 of yacc.c  */
-#line 493 "parse-gram.y"
+#line 495 "parse-gram.y"
     {
       yyerrok;
     }
@@ -2460,70 +2463,70 @@ yyreduce:
   case 80:
 
 /* Line 1280 of yacc.c  */
-#line 499 "parse-gram.y"
+#line 501 "parse-gram.y"
     { current_lhs = (yyvsp[(1) - (1)].symbol); current_lhs_location = (yylsp[(1) - (1)]); }
     break;
 
   case 82:
 
 /* Line 1280 of yacc.c  */
-#line 503 "parse-gram.y"
+#line 505 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(1) - (1)])); }
     break;
 
   case 83:
 
 /* Line 1280 of yacc.c  */
-#line 504 "parse-gram.y"
+#line 506 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(3) - (3)])); }
     break;
 
   case 85:
 
 /* Line 1280 of yacc.c  */
-#line 510 "parse-gram.y"
+#line 512 "parse-gram.y"
     { grammar_current_rule_begin (current_lhs, current_lhs_location); }
     break;
 
   case 86:
 
 /* Line 1280 of yacc.c  */
-#line 512 "parse-gram.y"
+#line 514 "parse-gram.y"
     { grammar_current_rule_symbol_append ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)])); }
     break;
 
   case 87:
 
 /* Line 1280 of yacc.c  */
-#line 514 "parse-gram.y"
+#line 516 "parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
     break;
 
   case 88:
 
 /* Line 1280 of yacc.c  */
-#line 516 "parse-gram.y"
+#line 518 "parse-gram.y"
     { grammar_current_rule_prec_set ((yyvsp[(3) - (3)].symbol), (yylsp[(3) - (3)])); }
     break;
 
   case 89:
 
 /* Line 1280 of yacc.c  */
-#line 518 "parse-gram.y"
+#line 520 "parse-gram.y"
     { grammar_current_rule_dprec_set ((yyvsp[(3) - (3)].integer), (yylsp[(3) - (3)])); }
     break;
 
   case 90:
 
 /* Line 1280 of yacc.c  */
-#line 520 "parse-gram.y"
+#line 522 "parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[(3) - (3)].uniqstr), (yylsp[(3) - (3)])); }
     break;
 
   case 93:
 
 /* Line 1280 of yacc.c  */
-#line 536 "parse-gram.y"
+#line 538 "parse-gram.y"
     {
       static char one[] = "1";
       (yyval.chars) = one;
@@ -2533,7 +2536,7 @@ yyreduce:
   case 95:
 
 /* Line 1280 of yacc.c  */
-#line 546 "parse-gram.y"
+#line 548 "parse-gram.y"
     {
       code_props plain_code;
       (yyvsp[(1) - (1)].code)[strlen ((yyvsp[(1) - (1)].code)) - 1] = '\n';
@@ -2547,14 +2550,14 @@ yyreduce:
   case 96:
 
 /* Line 1280 of yacc.c  */
-#line 566 "parse-gram.y"
+#line 568 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 97:
 
 /* Line 1280 of yacc.c  */
-#line 568 "parse-gram.y"
+#line 570 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[(1) - (1)].character)), (yylsp[(1) - (1)]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[(1) - (1)]), false);
@@ -2565,14 +2568,14 @@ yyreduce:
   case 98:
 
 /* Line 1280 of yacc.c  */
-#line 576 "parse-gram.y"
+#line 578 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 101:
 
 /* Line 1280 of yacc.c  */
-#line 588 "parse-gram.y"
+#line 590 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[(1) - (1)].chars)), (yylsp[(1) - (1)]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[(1) - (1)]), false);
@@ -2582,7 +2585,7 @@ yyreduce:
   case 103:
 
 /* Line 1280 of yacc.c  */
-#line 597 "parse-gram.y"
+#line 599 "parse-gram.y"
     {
       code_props plain_code;
       code_props_plain_init (&plain_code, (yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)]));
@@ -2596,7 +2599,7 @@ yyreduce:
 
 
 /* Line 1280 of yacc.c  */
-#line 2600 "parse-gram.c"
+#line 2603 "parse-gram.c"
       default: break;
     }
   YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);
@@ -2815,7 +2818,7 @@ yyreturn:
 
 
 /* Line 1497 of yacc.c  */
-#line 607 "parse-gram.y"
+#line 609 "parse-gram.y"
 
 
 
