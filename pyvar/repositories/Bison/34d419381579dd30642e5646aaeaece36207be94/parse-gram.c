@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 2.4.1.57-1d0f-dirty.  */
+/* A Bison parser, made by GNU Bison 2.4.1.71-377d.  */
 
 /* Skeleton implementation for Bison's Yacc-like parsers in C
    
@@ -45,7 +45,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "2.4.1.57-1d0f-dirty"
+#define YYBISON_VERSION "2.4.1.71-377d"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -663,17 +663,17 @@ static const yytype_int8 yyrhs[] =
 /* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
 static const yytype_uint16 yyrline[] =
 {
-       0,   202,   202,   210,   212,   216,   217,   227,   228,   232,
-     233,   238,   239,   240,   241,   242,   243,   248,   257,   258,
-     259,   260,   261,   262,   263,   264,   265,   266,   267,   280,
-     281,   305,   306,   307,   308,   312,   313,   314,   318,   325,
-     332,   336,   340,   347,   362,   363,   367,   379,   379,   384,
-     384,   389,   400,   415,   416,   417,   421,   422,   427,   429,
-     434,   435,   440,   442,   447,   448,   452,   453,   454,   455,
-     460,   465,   470,   476,   482,   493,   494,   503,   504,   510,
-     511,   512,   519,   519,   523,   524,   525,   530,   531,   533,
-     535,   537,   539,   551,   552,   557,   558,   567,   587,   589,
-     598,   603,   604,   609,   616,   618
+       0,   202,   202,   210,   212,   216,   217,   227,   228,   233,
+     234,   239,   240,   241,   242,   243,   244,   249,   258,   259,
+     260,   261,   262,   263,   264,   265,   266,   267,   268,   283,
+     284,   308,   309,   310,   311,   315,   316,   317,   321,   328,
+     335,   339,   343,   350,   365,   366,   370,   382,   382,   387,
+     387,   392,   403,   418,   419,   420,   424,   425,   430,   432,
+     437,   438,   443,   445,   450,   451,   455,   456,   457,   458,
+     463,   468,   473,   479,   485,   496,   497,   506,   507,   513,
+     514,   515,   522,   522,   526,   527,   528,   533,   534,   536,
+     538,   540,   542,   554,   555,   560,   561,   570,   590,   592,
+     601,   606,   607,   612,   619,   621
 };
 #endif
 
@@ -1909,21 +1909,22 @@ yyreduce:
 /* Line 1456 of yacc.c  */
 #line 229 "parse-gram.y"
     {
-      muscle_percent_define_insert ((yyvsp[(2) - (3)].uniqstr), (yylsp[(2) - (3)]), (yyvsp[(3) - (3)].chars));
+      muscle_percent_define_insert ((yyvsp[(2) - (3)].uniqstr), (yylsp[(2) - (3)]), (yyvsp[(3) - (3)].chars),
+                                    MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
     }
     break;
 
   case 9:
 
 /* Line 1456 of yacc.c  */
-#line 232 "parse-gram.y"
+#line 233 "parse-gram.y"
     { defines_flag = true; }
     break;
 
   case 10:
 
 /* Line 1456 of yacc.c  */
-#line 234 "parse-gram.y"
+#line 235 "parse-gram.y"
     {
       defines_flag = true;
       spec_defines_file = xstrdup ((yyvsp[(2) - (2)].chars));
@@ -1933,42 +1934,42 @@ yyreduce:
   case 11:
 
 /* Line 1456 of yacc.c  */
-#line 238 "parse-gram.y"
+#line 239 "parse-gram.y"
     { error_verbose = true; }
     break;
 
   case 12:
 
 /* Line 1456 of yacc.c  */
-#line 239 "parse-gram.y"
+#line 240 "parse-gram.y"
     { expected_sr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 13:
 
 /* Line 1456 of yacc.c  */
-#line 240 "parse-gram.y"
+#line 241 "parse-gram.y"
     { expected_rr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 14:
 
 /* Line 1456 of yacc.c  */
-#line 241 "parse-gram.y"
+#line 242 "parse-gram.y"
     { spec_file_prefix = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 15:
 
 /* Line 1456 of yacc.c  */
-#line 242 "parse-gram.y"
+#line 243 "parse-gram.y"
     { spec_file_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 16:
 
 /* Line 1456 of yacc.c  */
-#line 244 "parse-gram.y"
+#line 245 "parse-gram.y"
     {
       nondeterministic_parser = true;
       glr_parser = true;
@@ -1978,7 +1979,7 @@ yyreduce:
   case 17:
 
 /* Line 1456 of yacc.c  */
-#line 249 "parse-gram.y"
+#line 250 "parse-gram.y"
     {
       code_props action;
       code_props_symbol_action_init (&action, (yyvsp[(2) - (2)].code), (yylsp[(2) - (2)]));
@@ -1992,102 +1993,104 @@ yyreduce:
   case 18:
 
 /* Line 1456 of yacc.c  */
-#line 257 "parse-gram.y"
+#line 258 "parse-gram.y"
     { language_argmatch ((yyvsp[(2) - (2)].chars), grammar_prio, (yylsp[(1) - (2)])); }
     break;
 
   case 19:
 
 /* Line 1456 of yacc.c  */
-#line 258 "parse-gram.y"
+#line 259 "parse-gram.y"
     { add_param ("lex_param", (yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
     break;
 
   case 20:
 
 /* Line 1456 of yacc.c  */
-#line 259 "parse-gram.y"
+#line 260 "parse-gram.y"
     { locations_flag = true; }
     break;
 
   case 21:
 
 /* Line 1456 of yacc.c  */
-#line 260 "parse-gram.y"
+#line 261 "parse-gram.y"
     { spec_name_prefix = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 22:
 
 /* Line 1456 of yacc.c  */
-#line 261 "parse-gram.y"
+#line 262 "parse-gram.y"
     { spec_name_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 23:
 
 /* Line 1456 of yacc.c  */
-#line 262 "parse-gram.y"
+#line 263 "parse-gram.y"
     { no_lines_flag = true; }
     break;
 
   case 24:
 
 /* Line 1456 of yacc.c  */
-#line 263 "parse-gram.y"
+#line 264 "parse-gram.y"
     { nondeterministic_parser = true; }
     break;
 
   case 25:
 
 /* Line 1456 of yacc.c  */
-#line 264 "parse-gram.y"
+#line 265 "parse-gram.y"
     { spec_outfile = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 26:
 
 /* Line 1456 of yacc.c  */
-#line 265 "parse-gram.y"
+#line 266 "parse-gram.y"
     { spec_outfile = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 27:
 
 /* Line 1456 of yacc.c  */
-#line 266 "parse-gram.y"
+#line 267 "parse-gram.y"
     { add_param ("parse_param", (yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
     break;
 
   case 28:
 
 /* Line 1456 of yacc.c  */
-#line 268 "parse-gram.y"
+#line 269 "parse-gram.y"
     {
       /* %pure-parser is deprecated in favor of `%define api.pure', so use
          `%define api.pure' in a backward-compatible manner here.  First, don't
          complain if %pure-parser is specified multiple times.  */
       if (!muscle_find_const ("percent_define(api.pure)"))
-        muscle_percent_define_insert ("api.pure", (yylsp[(1) - (1)]), "");
+        muscle_percent_define_insert ("api.pure", (yylsp[(1) - (1)]), "",
+                                      MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
       /* In all cases, use api.pure now so that the backend doesn't complain if
          the skeleton ignores api.pure, but do warn now if there's a previous
          conflicting definition from an actual %define.  */
       if (!muscle_percent_define_flag_if ("api.pure"))
-        muscle_percent_define_insert ("api.pure", (yylsp[(1) - (1)]), "");
+        muscle_percent_define_insert ("api.pure", (yylsp[(1) - (1)]), "",
+                                      MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
     }
     break;
 
   case 29:
 
 /* Line 1456 of yacc.c  */
-#line 280 "parse-gram.y"
+#line 283 "parse-gram.y"
     { version_check (&(yylsp[(2) - (2)]), (yyvsp[(2) - (2)].chars)); }
     break;
 
   case 30:
 
 /* Line 1456 of yacc.c  */
-#line 282 "parse-gram.y"
+#line 285 "parse-gram.y"
     {
       char const *skeleton_user = (yyvsp[(2) - (2)].chars);
       if (strchr (skeleton_user, '/'))
@@ -2116,28 +2119,28 @@ yyreduce:
   case 31:
 
 /* Line 1456 of yacc.c  */
-#line 305 "parse-gram.y"
+#line 308 "parse-gram.y"
     { token_table_flag = true; }
     break;
 
   case 32:
 
 /* Line 1456 of yacc.c  */
-#line 306 "parse-gram.y"
+#line 309 "parse-gram.y"
     { report_flag |= report_states; }
     break;
 
   case 33:
 
 /* Line 1456 of yacc.c  */
-#line 307 "parse-gram.y"
+#line 310 "parse-gram.y"
     { yacc_flag = true; }
     break;
 
   case 37:
 
 /* Line 1456 of yacc.c  */
-#line 315 "parse-gram.y"
+#line 318 "parse-gram.y"
     {
       grammar_start_symbol_set ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]));
     }
@@ -2146,7 +2149,7 @@ yyreduce:
   case 38:
 
 /* Line 1456 of yacc.c  */
-#line 319 "parse-gram.y"
+#line 322 "parse-gram.y"
     {
       symbol_list *list;
       for (list = (yyvsp[(3) - (3)].list); list; list = list->next)
@@ -2158,7 +2161,7 @@ yyreduce:
   case 39:
 
 /* Line 1456 of yacc.c  */
-#line 326 "parse-gram.y"
+#line 329 "parse-gram.y"
     {
       symbol_list *list;
       for (list = (yyvsp[(3) - (3)].list); list; list = list->next)
@@ -2170,7 +2173,7 @@ yyreduce:
   case 40:
 
 /* Line 1456 of yacc.c  */
-#line 333 "parse-gram.y"
+#line 336 "parse-gram.y"
     {
       default_prec = true;
     }
@@ -2179,7 +2182,7 @@ yyreduce:
   case 41:
 
 /* Line 1456 of yacc.c  */
-#line 337 "parse-gram.y"
+#line 340 "parse-gram.y"
     {
       default_prec = false;
     }
@@ -2188,7 +2191,7 @@ yyreduce:
   case 42:
 
 /* Line 1456 of yacc.c  */
-#line 341 "parse-gram.y"
+#line 344 "parse-gram.y"
     {
       /* Do not invoke muscle_percent_code_grow here since it invokes
          muscle_user_name_list_grow.  */
@@ -2200,7 +2203,7 @@ yyreduce:
   case 43:
 
 /* Line 1456 of yacc.c  */
-#line 348 "parse-gram.y"
+#line 351 "parse-gram.y"
     {
       muscle_percent_code_grow ((yyvsp[(2) - (3)].uniqstr), (yylsp[(2) - (3)]), (yyvsp[(3) - (3)].chars), (yylsp[(3) - (3)]));
       code_scanner_last_string_free ();
@@ -2210,21 +2213,21 @@ yyreduce:
   case 44:
 
 /* Line 1456 of yacc.c  */
-#line 362 "parse-gram.y"
+#line 365 "parse-gram.y"
     {}
     break;
 
   case 45:
 
 /* Line 1456 of yacc.c  */
-#line 363 "parse-gram.y"
+#line 366 "parse-gram.y"
     { muscle_code_grow ("union_name", (yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 46:
 
 /* Line 1456 of yacc.c  */
-#line 368 "parse-gram.y"
+#line 371 "parse-gram.y"
     {
       union_seen = true;
       muscle_code_grow ("stype", (yyvsp[(3) - (3)].chars), (yylsp[(3) - (3)]));
@@ -2235,14 +2238,14 @@ yyreduce:
   case 47:
 
 /* Line 1456 of yacc.c  */
-#line 379 "parse-gram.y"
+#line 382 "parse-gram.y"
     { current_class = nterm_sym; }
     break;
 
   case 48:
 
 /* Line 1456 of yacc.c  */
-#line 380 "parse-gram.y"
+#line 383 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
@@ -2252,14 +2255,14 @@ yyreduce:
   case 49:
 
 /* Line 1456 of yacc.c  */
-#line 384 "parse-gram.y"
+#line 387 "parse-gram.y"
     { current_class = token_sym; }
     break;
 
   case 50:
 
 /* Line 1456 of yacc.c  */
-#line 385 "parse-gram.y"
+#line 388 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
@@ -2269,7 +2272,7 @@ yyreduce:
   case 51:
 
 /* Line 1456 of yacc.c  */
-#line 390 "parse-gram.y"
+#line 393 "parse-gram.y"
     {
       symbol_list *list;
       tag_seen = true;
@@ -2282,7 +2285,7 @@ yyreduce:
   case 52:
 
 /* Line 1456 of yacc.c  */
-#line 401 "parse-gram.y"
+#line 404 "parse-gram.y"
     {
       symbol_list *list;
       ++current_prec;
@@ -2299,126 +2302,126 @@ yyreduce:
   case 53:
 
 /* Line 1456 of yacc.c  */
-#line 415 "parse-gram.y"
+#line 418 "parse-gram.y"
     { (yyval.assoc) = left_assoc; }
     break;
 
   case 54:
 
 /* Line 1456 of yacc.c  */
-#line 416 "parse-gram.y"
+#line 419 "parse-gram.y"
     { (yyval.assoc) = right_assoc; }
     break;
 
   case 55:
 
 /* Line 1456 of yacc.c  */
-#line 417 "parse-gram.y"
+#line 420 "parse-gram.y"
     { (yyval.assoc) = non_assoc; }
     break;
 
   case 56:
 
 /* Line 1456 of yacc.c  */
-#line 421 "parse-gram.y"
+#line 424 "parse-gram.y"
     { current_type = NULL; }
     break;
 
   case 57:
 
 /* Line 1456 of yacc.c  */
-#line 422 "parse-gram.y"
+#line 425 "parse-gram.y"
     { current_type = (yyvsp[(1) - (1)].uniqstr); tag_seen = true; }
     break;
 
   case 58:
 
 /* Line 1456 of yacc.c  */
-#line 428 "parse-gram.y"
+#line 431 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 59:
 
 /* Line 1456 of yacc.c  */
-#line 430 "parse-gram.y"
+#line 433 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), symbol_list_sym_new ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]))); }
     break;
 
   case 60:
 
 /* Line 1456 of yacc.c  */
-#line 434 "parse-gram.y"
+#line 437 "parse-gram.y"
     { (yyval.symbol) = (yyvsp[(1) - (1)].symbol); }
     break;
 
   case 61:
 
 /* Line 1456 of yacc.c  */
-#line 435 "parse-gram.y"
+#line 438 "parse-gram.y"
     { (yyval.symbol) = (yyvsp[(1) - (2)].symbol); symbol_user_token_number_set ((yyvsp[(1) - (2)].symbol), (yyvsp[(2) - (2)].integer), (yylsp[(2) - (2)])); }
     break;
 
   case 62:
 
 /* Line 1456 of yacc.c  */
-#line 441 "parse-gram.y"
+#line 444 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 63:
 
 /* Line 1456 of yacc.c  */
-#line 443 "parse-gram.y"
+#line 446 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), symbol_list_sym_new ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]))); }
     break;
 
   case 64:
 
 /* Line 1456 of yacc.c  */
-#line 447 "parse-gram.y"
+#line 450 "parse-gram.y"
     { (yyval.list) = (yyvsp[(1) - (1)].list); }
     break;
 
   case 65:
 
 /* Line 1456 of yacc.c  */
-#line 448 "parse-gram.y"
+#line 451 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), (yyvsp[(2) - (2)].list)); }
     break;
 
   case 66:
 
 /* Line 1456 of yacc.c  */
-#line 452 "parse-gram.y"
+#line 455 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 67:
 
 /* Line 1456 of yacc.c  */
-#line 453 "parse-gram.y"
+#line 456 "parse-gram.y"
     { (yyval.list) = symbol_list_type_new ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 68:
 
 /* Line 1456 of yacc.c  */
-#line 454 "parse-gram.y"
+#line 457 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagged_new ((yylsp[(1) - (1)])); }
     break;
 
   case 69:
 
 /* Line 1456 of yacc.c  */
-#line 455 "parse-gram.y"
+#line 458 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagless_new ((yylsp[(1) - (1)])); }
     break;
 
   case 70:
 
 /* Line 1456 of yacc.c  */
-#line 461 "parse-gram.y"
+#line 464 "parse-gram.y"
     {
        current_type = (yyvsp[(1) - (1)].uniqstr);
        tag_seen = true;
@@ -2428,7 +2431,7 @@ yyreduce:
   case 71:
 
 /* Line 1456 of yacc.c  */
-#line 466 "parse-gram.y"
+#line 469 "parse-gram.y"
     {
        symbol_class_set ((yyvsp[(1) - (1)].symbol), current_class, (yylsp[(1) - (1)]), true);
        symbol_type_set ((yyvsp[(1) - (1)].symbol), current_type, (yylsp[(1) - (1)]));
@@ -2438,7 +2441,7 @@ yyreduce:
   case 72:
 
 /* Line 1456 of yacc.c  */
-#line 471 "parse-gram.y"
+#line 474 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
       symbol_type_set ((yyvsp[(1) - (2)].symbol), current_type, (yylsp[(1) - (2)]));
@@ -2449,7 +2452,7 @@ yyreduce:
   case 73:
 
 /* Line 1456 of yacc.c  */
-#line 477 "parse-gram.y"
+#line 480 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
       symbol_type_set ((yyvsp[(1) - (2)].symbol), current_type, (yylsp[(1) - (2)]));
@@ -2460,7 +2463,7 @@ yyreduce:
   case 74:
 
 /* Line 1456 of yacc.c  */
-#line 483 "parse-gram.y"
+#line 486 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (3)].symbol), current_class, (yylsp[(1) - (3)]), true);
       symbol_type_set ((yyvsp[(1) - (3)].symbol), current_type, (yylsp[(1) - (3)]));
@@ -2472,7 +2475,7 @@ yyreduce:
   case 81:
 
 /* Line 1456 of yacc.c  */
-#line 513 "parse-gram.y"
+#line 516 "parse-gram.y"
     {
       yyerrok;
     }
@@ -2481,84 +2484,84 @@ yyreduce:
   case 82:
 
 /* Line 1456 of yacc.c  */
-#line 519 "parse-gram.y"
+#line 522 "parse-gram.y"
     { current_lhs = (yyvsp[(1) - (1)].symbol); current_lhs_location = (yylsp[(1) - (1)]); }
     break;
 
   case 84:
 
 /* Line 1456 of yacc.c  */
-#line 523 "parse-gram.y"
+#line 526 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(1) - (1)])); }
     break;
 
   case 85:
 
 /* Line 1456 of yacc.c  */
-#line 524 "parse-gram.y"
+#line 527 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(3) - (3)])); }
     break;
 
   case 87:
 
 /* Line 1456 of yacc.c  */
-#line 530 "parse-gram.y"
+#line 533 "parse-gram.y"
     { grammar_current_rule_begin (current_lhs, current_lhs_location); }
     break;
 
   case 88:
 
 /* Line 1456 of yacc.c  */
-#line 532 "parse-gram.y"
+#line 535 "parse-gram.y"
     { grammar_current_rule_symbol_append ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)])); }
     break;
 
   case 89:
 
 /* Line 1456 of yacc.c  */
-#line 534 "parse-gram.y"
+#line 537 "parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
     break;
 
   case 90:
 
 /* Line 1456 of yacc.c  */
-#line 536 "parse-gram.y"
+#line 539 "parse-gram.y"
     { grammar_current_rule_prec_set ((yyvsp[(3) - (3)].symbol), (yylsp[(3) - (3)])); }
     break;
 
   case 91:
 
 /* Line 1456 of yacc.c  */
-#line 538 "parse-gram.y"
+#line 541 "parse-gram.y"
     { grammar_current_rule_dprec_set ((yyvsp[(3) - (3)].integer), (yylsp[(3) - (3)])); }
     break;
 
   case 92:
 
 /* Line 1456 of yacc.c  */
-#line 540 "parse-gram.y"
+#line 543 "parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[(3) - (3)].uniqstr), (yylsp[(3) - (3)])); }
     break;
 
   case 94:
 
 /* Line 1456 of yacc.c  */
-#line 552 "parse-gram.y"
+#line 555 "parse-gram.y"
     { (yyval.uniqstr) = uniqstr_new ((yyvsp[(1) - (1)].chars)); }
     break;
 
   case 95:
 
 /* Line 1456 of yacc.c  */
-#line 557 "parse-gram.y"
+#line 560 "parse-gram.y"
     { (yyval.chars) = ""; }
     break;
 
   case 97:
 
 /* Line 1456 of yacc.c  */
-#line 568 "parse-gram.y"
+#line 571 "parse-gram.y"
     {
       code_props plain_code;
       (yyvsp[(1) - (1)].code)[strlen ((yyvsp[(1) - (1)].code)) - 1] = '\n';
@@ -2572,14 +2575,14 @@ yyreduce:
   case 98:
 
 /* Line 1456 of yacc.c  */
-#line 588 "parse-gram.y"
+#line 591 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 99:
 
 /* Line 1456 of yacc.c  */
-#line 590 "parse-gram.y"
+#line 593 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[(1) - (1)].character)), (yylsp[(1) - (1)]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[(1) - (1)]), false);
@@ -2590,14 +2593,14 @@ yyreduce:
   case 100:
 
 /* Line 1456 of yacc.c  */
-#line 598 "parse-gram.y"
+#line 601 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 103:
 
 /* Line 1456 of yacc.c  */
-#line 610 "parse-gram.y"
+#line 613 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[(1) - (1)].chars)), (yylsp[(1) - (1)]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[(1) - (1)]), false);
@@ -2607,7 +2610,7 @@ yyreduce:
   case 105:
 
 /* Line 1456 of yacc.c  */
-#line 619 "parse-gram.y"
+#line 622 "parse-gram.y"
     {
       code_props plain_code;
       code_props_plain_init (&plain_code, (yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)]));
@@ -2621,7 +2624,7 @@ yyreduce:
 
 
 /* Line 1456 of yacc.c  */
-#line 2625 "parse-gram.c"
+#line 2628 "parse-gram.c"
       default: break;
     }
   YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);
@@ -2840,7 +2843,7 @@ yyreturn:
 
 
 /* Line 1676 of yacc.c  */
-#line 629 "parse-gram.y"
+#line 632 "parse-gram.y"
 
 
 
