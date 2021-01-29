@@ -675,17 +675,17 @@ static const yytype_int8 yyrhs[] =
 /* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
 static const yytype_uint16 yyrline[] =
 {
-       0,   210,   210,   218,   220,   224,   225,   235,   236,   250,
-     251,   256,   257,   258,   259,   260,   261,   266,   275,   276,
-     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
-     287,   288,   289,   313,   314,   315,   316,   320,   321,   322,
-     326,   333,   340,   344,   348,   353,   376,   377,   381,   393,
-     393,   398,   398,   403,   414,   429,   430,   431,   435,   436,
-     441,   443,   448,   449,   453,   454,   455,   456,   461,   466,
-     471,   477,   483,   494,   495,   504,   505,   511,   512,   513,
-     520,   520,   524,   525,   526,   531,   532,   534,   536,   538,
-     540,   550,   551,   557,   560,   569,   589,   591,   600,   605,
-     606,   611,   618,   620
+       0,   210,   210,   218,   220,   224,   225,   235,   236,   240,
+     241,   246,   247,   248,   249,   250,   251,   256,   265,   266,
+     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
+     277,   278,   279,   303,   304,   305,   306,   310,   311,   312,
+     316,   323,   330,   334,   338,   345,   360,   361,   365,   377,
+     377,   382,   382,   387,   398,   413,   414,   415,   419,   420,
+     425,   427,   432,   433,   437,   438,   439,   440,   445,   450,
+     455,   461,   467,   478,   479,   488,   489,   495,   496,   497,
+     504,   504,   508,   509,   510,   515,   516,   518,   520,   522,
+     524,   534,   535,   541,   544,   553,   573,   575,   584,   589,
+     590,   595,   602,   604
 };
 #endif
 
@@ -1914,31 +1914,21 @@ yyreduce:
 /* Line 1537 of yacc.c  */
 #line 237 "parse-gram.y"
     {
-      char const name_prefix[] = "percent_define(";
-      size_t length = strlen ((yyvsp[(2) - (3)].uniqstr));
-      char *name = xmalloc (sizeof name_prefix + length + 1);
-      strcpy (name, name_prefix);
-      strcpy (name + sizeof name_prefix - 1, (yyvsp[(2) - (3)].uniqstr));
-      strcpy (name + sizeof name_prefix - 1 + length, ")");
-      if (muscle_find_const (name))
-        warn_at ((yylsp[(2) - (3)]), _("%s `%s' redefined"), "%define variable", (yyvsp[(2) - (3)].uniqstr));
-      MUSCLE_INSERT_STRING (uniqstr_new (name), (yyvsp[(3) - (3)].chars));
-      free (name);
-      muscle_grow_user_name_list ("percent_define_user_variables", (yyvsp[(2) - (3)].uniqstr), (yylsp[(2) - (3)]));
+      muscle_percent_define_insert ((yyvsp[(2) - (3)].uniqstr), (yylsp[(2) - (3)]), (yyvsp[(3) - (3)].chars));
     }
     break;
 
   case 9:
 
 /* Line 1537 of yacc.c  */
-#line 250 "parse-gram.y"
+#line 240 "parse-gram.y"
     { defines_flag = true; }
     break;
 
   case 10:
 
 /* Line 1537 of yacc.c  */
-#line 252 "parse-gram.y"
+#line 242 "parse-gram.y"
     {
       defines_flag = true;
       spec_defines_file = xstrdup ((yyvsp[(2) - (2)].chars));
@@ -1948,42 +1938,42 @@ yyreduce:
   case 11:
 
 /* Line 1537 of yacc.c  */
-#line 256 "parse-gram.y"
+#line 246 "parse-gram.y"
     { error_verbose = true; }
     break;
 
   case 12:
 
 /* Line 1537 of yacc.c  */
-#line 257 "parse-gram.y"
+#line 247 "parse-gram.y"
     { expected_sr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 13:
 
 /* Line 1537 of yacc.c  */
-#line 258 "parse-gram.y"
+#line 248 "parse-gram.y"
     { expected_rr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 14:
 
 /* Line 1537 of yacc.c  */
-#line 259 "parse-gram.y"
+#line 249 "parse-gram.y"
     { spec_file_prefix = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 15:
 
 /* Line 1537 of yacc.c  */
-#line 260 "parse-gram.y"
+#line 250 "parse-gram.y"
     { spec_file_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 16:
 
 /* Line 1537 of yacc.c  */
-#line 262 "parse-gram.y"
+#line 252 "parse-gram.y"
     {
       nondeterministic_parser = true;
       glr_parser = true;
@@ -1993,7 +1983,7 @@ yyreduce:
   case 17:
 
 /* Line 1537 of yacc.c  */
-#line 267 "parse-gram.y"
+#line 257 "parse-gram.y"
     {
       code_props action;
       code_props_symbol_action_init (&action, (yyvsp[(2) - (2)].code), (yylsp[(2) - (2)]));
@@ -2007,105 +1997,105 @@ yyreduce:
   case 18:
 
 /* Line 1537 of yacc.c  */
-#line 275 "parse-gram.y"
+#line 265 "parse-gram.y"
     { language_argmatch ((yyvsp[(2) - (2)].chars), 1, &(yylsp[(1) - (2)])); }
     break;
 
   case 19:
 
 /* Line 1537 of yacc.c  */
-#line 276 "parse-gram.y"
+#line 266 "parse-gram.y"
     { add_param ("lex_param", (yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
     break;
 
   case 20:
 
 /* Line 1537 of yacc.c  */
-#line 277 "parse-gram.y"
+#line 267 "parse-gram.y"
     { locations_flag = true; }
     break;
 
   case 21:
 
 /* Line 1537 of yacc.c  */
-#line 278 "parse-gram.y"
+#line 268 "parse-gram.y"
     { spec_name_prefix = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 22:
 
 /* Line 1537 of yacc.c  */
-#line 279 "parse-gram.y"
+#line 269 "parse-gram.y"
     { spec_name_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 23:
 
 /* Line 1537 of yacc.c  */
-#line 280 "parse-gram.y"
+#line 270 "parse-gram.y"
     { no_lines_flag = true; }
     break;
 
   case 24:
 
 /* Line 1537 of yacc.c  */
-#line 281 "parse-gram.y"
+#line 271 "parse-gram.y"
     { nondeterministic_parser = true; }
     break;
 
   case 25:
 
 /* Line 1537 of yacc.c  */
-#line 282 "parse-gram.y"
+#line 272 "parse-gram.y"
     { spec_outfile = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 26:
 
 /* Line 1537 of yacc.c  */
-#line 283 "parse-gram.y"
+#line 273 "parse-gram.y"
     { spec_outfile = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 27:
 
 /* Line 1537 of yacc.c  */
-#line 284 "parse-gram.y"
+#line 274 "parse-gram.y"
     { add_param ("parse_param", (yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
     break;
 
   case 28:
 
 /* Line 1537 of yacc.c  */
-#line 285 "parse-gram.y"
+#line 275 "parse-gram.y"
     { pure_parser = true; }
     break;
 
   case 29:
 
 /* Line 1537 of yacc.c  */
-#line 286 "parse-gram.y"
+#line 276 "parse-gram.y"
     { push_parser = true; pull_parser = false; }
     break;
 
   case 30:
 
 /* Line 1537 of yacc.c  */
-#line 287 "parse-gram.y"
+#line 277 "parse-gram.y"
     { push_parser = true; pull_parser = true; }
     break;
 
   case 31:
 
 /* Line 1537 of yacc.c  */
-#line 288 "parse-gram.y"
+#line 278 "parse-gram.y"
     { version_check (&(yylsp[(2) - (2)]), (yyvsp[(2) - (2)].chars)); }
     break;
 
   case 32:
 
 /* Line 1537 of yacc.c  */
-#line 290 "parse-gram.y"
+#line 280 "parse-gram.y"
     {
       char const *skeleton_user = (yyvsp[(2) - (2)].chars);
       if (strchr (skeleton_user, '/'))
@@ -2134,28 +2124,28 @@ yyreduce:
   case 33:
 
 /* Line 1537 of yacc.c  */
-#line 313 "parse-gram.y"
+#line 303 "parse-gram.y"
     { token_table_flag = true; }
     break;
 
   case 34:
 
 /* Line 1537 of yacc.c  */
-#line 314 "parse-gram.y"
+#line 304 "parse-gram.y"
     { report_flag = report_states; }
     break;
 
   case 35:
 
 /* Line 1537 of yacc.c  */
-#line 315 "parse-gram.y"
+#line 305 "parse-gram.y"
     { yacc_flag = true; }
     break;
 
   case 39:
 
 /* Line 1537 of yacc.c  */
-#line 323 "parse-gram.y"
+#line 313 "parse-gram.y"
     {
       grammar_start_symbol_set ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]));
     }
@@ -2164,7 +2154,7 @@ yyreduce:
   case 40:
 
 /* Line 1537 of yacc.c  */
-#line 327 "parse-gram.y"
+#line 317 "parse-gram.y"
     {
       symbol_list *list;
       for (list = (yyvsp[(3) - (3)].list); list; list = list->next)
@@ -2176,7 +2166,7 @@ yyreduce:
   case 41:
 
 /* Line 1537 of yacc.c  */
-#line 334 "parse-gram.y"
+#line 324 "parse-gram.y"
     {
       symbol_list *list;
       for (list = (yyvsp[(3) - (3)].list); list; list = list->next)
@@ -2188,7 +2178,7 @@ yyreduce:
   case 42:
 
 /* Line 1537 of yacc.c  */
-#line 341 "parse-gram.y"
+#line 331 "parse-gram.y"
     {
       default_prec = true;
     }
@@ -2197,7 +2187,7 @@ yyreduce:
   case 43:
 
 /* Line 1537 of yacc.c  */
-#line 345 "parse-gram.y"
+#line 335 "parse-gram.y"
     {
       default_prec = false;
     }
@@ -2206,8 +2196,10 @@ yyreduce:
   case 44:
 
 /* Line 1537 of yacc.c  */
-#line 349 "parse-gram.y"
+#line 339 "parse-gram.y"
     {
+      /* Do not invoke muscle_percent_code_grow here since it invokes
+         muscle_user_name_list_grow.  */
       muscle_code_grow ("percent_code()", (yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)]));
       code_scanner_last_string_free ();
     }
@@ -2216,39 +2208,31 @@ yyreduce:
   case 45:
 
 /* Line 1537 of yacc.c  */
-#line 354 "parse-gram.y"
+#line 346 "parse-gram.y"
     {
-      char const name_prefix[] = "percent_code(";
-      size_t length = strlen ((yyvsp[(2) - (3)].uniqstr));
-      char *name = xmalloc (sizeof name_prefix + length + 1);
-      strcpy (name, name_prefix);
-      strcpy (name + sizeof name_prefix - 1, (yyvsp[(2) - (3)].uniqstr));
-      strcpy (name + sizeof name_prefix - 1 + length, ")");
-      muscle_code_grow (uniqstr_new (name), (yyvsp[(3) - (3)].chars), (yylsp[(3) - (3)]));
-      free (name);
+      muscle_percent_code_grow ((yyvsp[(2) - (3)].uniqstr), (yylsp[(2) - (3)]), (yyvsp[(3) - (3)].chars), (yylsp[(3) - (3)]));
       code_scanner_last_string_free ();
-      muscle_grow_user_name_list ("percent_code_user_qualifiers", (yyvsp[(2) - (3)].uniqstr), (yylsp[(2) - (3)]));
     }
     break;
 
   case 46:
 
 /* Line 1537 of yacc.c  */
-#line 376 "parse-gram.y"
+#line 360 "parse-gram.y"
     {}
     break;
 
   case 47:
 
 /* Line 1537 of yacc.c  */
-#line 377 "parse-gram.y"
+#line 361 "parse-gram.y"
     { muscle_code_grow ("union_name", (yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 48:
 
 /* Line 1537 of yacc.c  */
-#line 382 "parse-gram.y"
+#line 366 "parse-gram.y"
     {
       union_seen = true;
       muscle_code_grow ("stype", (yyvsp[(3) - (3)].chars), (yylsp[(3) - (3)]));
@@ -2259,14 +2243,14 @@ yyreduce:
   case 49:
 
 /* Line 1537 of yacc.c  */
-#line 393 "parse-gram.y"
+#line 377 "parse-gram.y"
     { current_class = nterm_sym; }
     break;
 
   case 50:
 
 /* Line 1537 of yacc.c  */
-#line 394 "parse-gram.y"
+#line 378 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
@@ -2276,14 +2260,14 @@ yyreduce:
   case 51:
 
 /* Line 1537 of yacc.c  */
-#line 398 "parse-gram.y"
+#line 382 "parse-gram.y"
     { current_class = token_sym; }
     break;
 
   case 52:
 
 /* Line 1537 of yacc.c  */
-#line 399 "parse-gram.y"
+#line 383 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
@@ -2293,7 +2277,7 @@ yyreduce:
   case 53:
 
 /* Line 1537 of yacc.c  */
-#line 404 "parse-gram.y"
+#line 388 "parse-gram.y"
     {
       symbol_list *list;
       tag_seen = true;
@@ -2306,7 +2290,7 @@ yyreduce:
   case 54:
 
 /* Line 1537 of yacc.c  */
-#line 415 "parse-gram.y"
+#line 399 "parse-gram.y"
     {
       symbol_list *list;
       ++current_prec;
@@ -2323,98 +2307,98 @@ yyreduce:
   case 55:
 
 /* Line 1537 of yacc.c  */
-#line 429 "parse-gram.y"
+#line 413 "parse-gram.y"
     { (yyval.assoc) = left_assoc; }
     break;
 
   case 56:
 
 /* Line 1537 of yacc.c  */
-#line 430 "parse-gram.y"
+#line 414 "parse-gram.y"
     { (yyval.assoc) = right_assoc; }
     break;
 
   case 57:
 
 /* Line 1537 of yacc.c  */
-#line 431 "parse-gram.y"
+#line 415 "parse-gram.y"
     { (yyval.assoc) = non_assoc; }
     break;
 
   case 58:
 
 /* Line 1537 of yacc.c  */
-#line 435 "parse-gram.y"
+#line 419 "parse-gram.y"
     { current_type = NULL; }
     break;
 
   case 59:
 
 /* Line 1537 of yacc.c  */
-#line 436 "parse-gram.y"
+#line 420 "parse-gram.y"
     { current_type = (yyvsp[(1) - (1)].uniqstr); tag_seen = true; }
     break;
 
   case 60:
 
 /* Line 1537 of yacc.c  */
-#line 442 "parse-gram.y"
+#line 426 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 61:
 
 /* Line 1537 of yacc.c  */
-#line 444 "parse-gram.y"
+#line 428 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), symbol_list_sym_new ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]))); }
     break;
 
   case 62:
 
 /* Line 1537 of yacc.c  */
-#line 448 "parse-gram.y"
+#line 432 "parse-gram.y"
     { (yyval.list) = (yyvsp[(1) - (1)].list); }
     break;
 
   case 63:
 
 /* Line 1537 of yacc.c  */
-#line 449 "parse-gram.y"
+#line 433 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), (yyvsp[(2) - (2)].list)); }
     break;
 
   case 64:
 
 /* Line 1537 of yacc.c  */
-#line 453 "parse-gram.y"
+#line 437 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 65:
 
 /* Line 1537 of yacc.c  */
-#line 454 "parse-gram.y"
+#line 438 "parse-gram.y"
     { (yyval.list) = symbol_list_type_new ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 66:
 
 /* Line 1537 of yacc.c  */
-#line 455 "parse-gram.y"
+#line 439 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagged_new ((yylsp[(1) - (1)])); }
     break;
 
   case 67:
 
 /* Line 1537 of yacc.c  */
-#line 456 "parse-gram.y"
+#line 440 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagless_new ((yylsp[(1) - (1)])); }
     break;
 
   case 68:
 
 /* Line 1537 of yacc.c  */
-#line 462 "parse-gram.y"
+#line 446 "parse-gram.y"
     {
        current_type = (yyvsp[(1) - (1)].uniqstr);
        tag_seen = true;
@@ -2424,7 +2408,7 @@ yyreduce:
   case 69:
 
 /* Line 1537 of yacc.c  */
-#line 467 "parse-gram.y"
+#line 451 "parse-gram.y"
     {
        symbol_class_set ((yyvsp[(1) - (1)].symbol), current_class, (yylsp[(1) - (1)]), true);
        symbol_type_set ((yyvsp[(1) - (1)].symbol), current_type, (yylsp[(1) - (1)]));
@@ -2434,7 +2418,7 @@ yyreduce:
   case 70:
 
 /* Line 1537 of yacc.c  */
-#line 472 "parse-gram.y"
+#line 456 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
       symbol_type_set ((yyvsp[(1) - (2)].symbol), current_type, (yylsp[(1) - (2)]));
@@ -2445,7 +2429,7 @@ yyreduce:
   case 71:
 
 /* Line 1537 of yacc.c  */
-#line 478 "parse-gram.y"
+#line 462 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
       symbol_type_set ((yyvsp[(1) - (2)].symbol), current_type, (yylsp[(1) - (2)]));
@@ -2456,7 +2440,7 @@ yyreduce:
   case 72:
 
 /* Line 1537 of yacc.c  */
-#line 484 "parse-gram.y"
+#line 468 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (3)].symbol), current_class, (yylsp[(1) - (3)]), true);
       symbol_type_set ((yyvsp[(1) - (3)].symbol), current_type, (yylsp[(1) - (3)]));
@@ -2468,7 +2452,7 @@ yyreduce:
   case 79:
 
 /* Line 1537 of yacc.c  */
-#line 514 "parse-gram.y"
+#line 498 "parse-gram.y"
     {
       yyerrok;
     }
@@ -2477,77 +2461,77 @@ yyreduce:
   case 80:
 
 /* Line 1537 of yacc.c  */
-#line 520 "parse-gram.y"
+#line 504 "parse-gram.y"
     { current_lhs = (yyvsp[(1) - (1)].symbol); current_lhs_location = (yylsp[(1) - (1)]); }
     break;
 
   case 82:
 
 /* Line 1537 of yacc.c  */
-#line 524 "parse-gram.y"
+#line 508 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(1) - (1)])); }
     break;
 
   case 83:
 
 /* Line 1537 of yacc.c  */
-#line 525 "parse-gram.y"
+#line 509 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(3) - (3)])); }
     break;
 
   case 85:
 
 /* Line 1537 of yacc.c  */
-#line 531 "parse-gram.y"
+#line 515 "parse-gram.y"
     { grammar_current_rule_begin (current_lhs, current_lhs_location); }
     break;
 
   case 86:
 
 /* Line 1537 of yacc.c  */
-#line 533 "parse-gram.y"
+#line 517 "parse-gram.y"
     { grammar_current_rule_symbol_append ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)])); }
     break;
 
   case 87:
 
 /* Line 1537 of yacc.c  */
-#line 535 "parse-gram.y"
+#line 519 "parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
     break;
 
   case 88:
 
 /* Line 1537 of yacc.c  */
-#line 537 "parse-gram.y"
+#line 521 "parse-gram.y"
     { grammar_current_rule_prec_set ((yyvsp[(3) - (3)].symbol), (yylsp[(3) - (3)])); }
     break;
 
   case 89:
 
 /* Line 1537 of yacc.c  */
-#line 539 "parse-gram.y"
+#line 523 "parse-gram.y"
     { grammar_current_rule_dprec_set ((yyvsp[(3) - (3)].integer), (yylsp[(3) - (3)])); }
     break;
 
   case 90:
 
 /* Line 1537 of yacc.c  */
-#line 541 "parse-gram.y"
+#line 525 "parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[(3) - (3)].uniqstr), (yylsp[(3) - (3)])); }
     break;
 
   case 92:
 
 /* Line 1537 of yacc.c  */
-#line 551 "parse-gram.y"
+#line 535 "parse-gram.y"
     { (yyval.uniqstr) = uniqstr_new ((yyvsp[(1) - (1)].chars)); }
     break;
 
   case 93:
 
 /* Line 1537 of yacc.c  */
-#line 557 "parse-gram.y"
+#line 541 "parse-gram.y"
     {
       (yyval.chars) = "";
     }
@@ -2556,7 +2540,7 @@ yyreduce:
   case 95:
 
 /* Line 1537 of yacc.c  */
-#line 570 "parse-gram.y"
+#line 554 "parse-gram.y"
     {
       code_props plain_code;
       (yyvsp[(1) - (1)].code)[strlen ((yyvsp[(1) - (1)].code)) - 1] = '\n';
@@ -2570,14 +2554,14 @@ yyreduce:
   case 96:
 
 /* Line 1537 of yacc.c  */
-#line 590 "parse-gram.y"
+#line 574 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 97:
 
 /* Line 1537 of yacc.c  */
-#line 592 "parse-gram.y"
+#line 576 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[(1) - (1)].character)), (yylsp[(1) - (1)]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[(1) - (1)]), false);
@@ -2588,14 +2572,14 @@ yyreduce:
   case 98:
 
 /* Line 1537 of yacc.c  */
-#line 600 "parse-gram.y"
+#line 584 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 101:
 
 /* Line 1537 of yacc.c  */
-#line 612 "parse-gram.y"
+#line 596 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[(1) - (1)].chars)), (yylsp[(1) - (1)]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[(1) - (1)]), false);
@@ -2605,7 +2589,7 @@ yyreduce:
   case 103:
 
 /* Line 1537 of yacc.c  */
-#line 621 "parse-gram.y"
+#line 605 "parse-gram.y"
     {
       code_props plain_code;
       code_props_plain_init (&plain_code, (yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)]));
@@ -2619,7 +2603,7 @@ yyreduce:
 
 
 /* Line 1537 of yacc.c  */
-#line 2623 "parse-gram.c"
+#line 2607 "parse-gram.c"
       default: break;
     }
   YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);
@@ -2838,7 +2822,7 @@ yyreturn:
 
 
 /* Line 1537 of yacc.c  */
-#line 631 "parse-gram.y"
+#line 615 "parse-gram.y"
 
 
 
