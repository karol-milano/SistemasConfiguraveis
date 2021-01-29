@@ -675,17 +675,17 @@ static const yytype_int8 yyrhs[] =
 /* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
 static const yytype_uint16 yyrline[] =
 {
-       0,   210,   210,   218,   220,   224,   225,   235,   236,   248,
-     249,   254,   255,   256,   257,   258,   259,   264,   273,   274,
-     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
-     285,   286,   287,   288,   289,   290,   291,   295,   296,   297,
-     301,   308,   315,   319,   323,   328,   349,   350,   354,   366,
-     366,   371,   371,   376,   387,   402,   403,   404,   408,   409,
-     414,   416,   421,   422,   426,   427,   428,   429,   434,   439,
-     444,   450,   456,   467,   468,   477,   478,   484,   485,   486,
-     493,   493,   497,   498,   499,   504,   505,   507,   509,   511,
-     513,   523,   524,   530,   534,   543,   563,   565,   574,   579,
-     580,   585,   592,   594
+       0,   210,   210,   218,   220,   224,   225,   235,   236,   250,
+     251,   256,   257,   258,   259,   260,   261,   266,   275,   276,
+     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
+     287,   288,   289,   290,   291,   292,   293,   297,   298,   299,
+     303,   310,   317,   321,   325,   330,   353,   354,   358,   370,
+     370,   375,   375,   380,   391,   406,   407,   408,   412,   413,
+     418,   420,   425,   426,   430,   431,   432,   433,   438,   443,
+     448,   454,   460,   471,   472,   481,   482,   488,   489,   490,
+     497,   497,   501,   502,   503,   508,   509,   511,   513,   515,
+     517,   527,   528,   534,   538,   547,   567,   569,   578,   583,
+     584,   589,   596,   598
 };
 #endif
 
@@ -1914,29 +1914,31 @@ yyreduce:
 /* Line 1537 of yacc.c  */
 #line 237 "parse-gram.y"
     {
-      char const name_prefix[] = "percent_define_";
-      char *name = xmalloc (sizeof name_prefix + strlen ((yyvsp[(2) - (3)].uniqstr)));
+      char const name_prefix[] = "percent_define(";
+      size_t length = strlen ((yyvsp[(2) - (3)].uniqstr));
+      char *name = xmalloc (sizeof name_prefix + length + 1);
       strcpy (name, name_prefix);
       strcpy (name + sizeof name_prefix - 1, (yyvsp[(2) - (3)].uniqstr));
+      strcpy (name + sizeof name_prefix - 1 + length, ")");
       if (muscle_find_const (name))
         warn_at ((yylsp[(2) - (3)]), _("%s `%s' redefined"), "%define variable", (yyvsp[(2) - (3)].uniqstr));
       MUSCLE_INSERT_STRING (uniqstr_new (name), (yyvsp[(3) - (3)].chars));
       free (name);
-      muscle_grow_user_name_list ("user_percent_define_variables", (yyvsp[(2) - (3)].uniqstr), (yylsp[(2) - (3)]));
+      muscle_grow_user_name_list ("percent_define_user_variables", (yyvsp[(2) - (3)].uniqstr), (yylsp[(2) - (3)]));
     }
     break;
 
   case 9:
 
 /* Line 1537 of yacc.c  */
-#line 248 "parse-gram.y"
+#line 250 "parse-gram.y"
     { defines_flag = true; }
     break;
 
   case 10:
 
 /* Line 1537 of yacc.c  */
-#line 250 "parse-gram.y"
+#line 252 "parse-gram.y"
     {
       defines_flag = true;
       spec_defines_file = xstrdup ((yyvsp[(2) - (2)].chars));
@@ -1946,42 +1948,42 @@ yyreduce:
   case 11:
 
 /* Line 1537 of yacc.c  */
-#line 254 "parse-gram.y"
+#line 256 "parse-gram.y"
     { error_verbose = true; }
     break;
 
   case 12:
 
 /* Line 1537 of yacc.c  */
-#line 255 "parse-gram.y"
+#line 257 "parse-gram.y"
     { expected_sr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 13:
 
 /* Line 1537 of yacc.c  */
-#line 256 "parse-gram.y"
+#line 258 "parse-gram.y"
     { expected_rr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 14:
 
 /* Line 1537 of yacc.c  */
-#line 257 "parse-gram.y"
+#line 259 "parse-gram.y"
     { spec_file_prefix = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 15:
 
 /* Line 1537 of yacc.c  */
-#line 258 "parse-gram.y"
+#line 260 "parse-gram.y"
     { spec_file_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 16:
 
 /* Line 1537 of yacc.c  */
-#line 260 "parse-gram.y"
+#line 262 "parse-gram.y"
     {
       nondeterministic_parser = true;
       glr_parser = true;
@@ -1991,7 +1993,7 @@ yyreduce:
   case 17:
 
 /* Line 1537 of yacc.c  */
-#line 265 "parse-gram.y"
+#line 267 "parse-gram.y"
     {
       code_props action;
       code_props_symbol_action_init (&action, (yyvsp[(2) - (2)].code), (yylsp[(2) - (2)]));
@@ -2005,133 +2007,133 @@ yyreduce:
   case 18:
 
 /* Line 1537 of yacc.c  */
-#line 273 "parse-gram.y"
+#line 275 "parse-gram.y"
     { language_argmatch ((yyvsp[(2) - (2)].chars), 1, &(yylsp[(1) - (2)])); }
     break;
 
   case 19:
 
 /* Line 1537 of yacc.c  */
-#line 274 "parse-gram.y"
+#line 276 "parse-gram.y"
     { add_param ("lex_param", (yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
     break;
 
   case 20:
 
 /* Line 1537 of yacc.c  */
-#line 275 "parse-gram.y"
+#line 277 "parse-gram.y"
     { locations_flag = true; }
     break;
 
   case 21:
 
 /* Line 1537 of yacc.c  */
-#line 276 "parse-gram.y"
+#line 278 "parse-gram.y"
     { spec_name_prefix = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 22:
 
 /* Line 1537 of yacc.c  */
-#line 277 "parse-gram.y"
+#line 279 "parse-gram.y"
     { spec_name_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 23:
 
 /* Line 1537 of yacc.c  */
-#line 278 "parse-gram.y"
+#line 280 "parse-gram.y"
     { no_lines_flag = true; }
     break;
 
   case 24:
 
 /* Line 1537 of yacc.c  */
-#line 279 "parse-gram.y"
+#line 281 "parse-gram.y"
     { nondeterministic_parser = true; }
     break;
 
   case 25:
 
 /* Line 1537 of yacc.c  */
-#line 280 "parse-gram.y"
+#line 282 "parse-gram.y"
     { spec_outfile = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 26:
 
 /* Line 1537 of yacc.c  */
-#line 281 "parse-gram.y"
+#line 283 "parse-gram.y"
     { spec_outfile = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 27:
 
 /* Line 1537 of yacc.c  */
-#line 282 "parse-gram.y"
+#line 284 "parse-gram.y"
     { add_param ("parse_param", (yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
     break;
 
   case 28:
 
 /* Line 1537 of yacc.c  */
-#line 283 "parse-gram.y"
+#line 285 "parse-gram.y"
     { pure_parser = true; }
     break;
 
   case 29:
 
 /* Line 1537 of yacc.c  */
-#line 284 "parse-gram.y"
+#line 286 "parse-gram.y"
     { push_parser = true; pull_parser = false; }
     break;
 
   case 30:
 
 /* Line 1537 of yacc.c  */
-#line 285 "parse-gram.y"
+#line 287 "parse-gram.y"
     { push_parser = true; pull_parser = true; }
     break;
 
   case 31:
 
 /* Line 1537 of yacc.c  */
-#line 286 "parse-gram.y"
+#line 288 "parse-gram.y"
     { version_check (&(yylsp[(2) - (2)]), (yyvsp[(2) - (2)].chars)); }
     break;
 
   case 32:
 
 /* Line 1537 of yacc.c  */
-#line 287 "parse-gram.y"
+#line 289 "parse-gram.y"
     { skeleton_arg ((yyvsp[(2) - (2)].chars), 1, &(yylsp[(1) - (2)])); }
     break;
 
   case 33:
 
 /* Line 1537 of yacc.c  */
-#line 288 "parse-gram.y"
+#line 290 "parse-gram.y"
     { token_table_flag = true; }
     break;
 
   case 34:
 
 /* Line 1537 of yacc.c  */
-#line 289 "parse-gram.y"
+#line 291 "parse-gram.y"
     { report_flag = report_states; }
     break;
 
   case 35:
 
 /* Line 1537 of yacc.c  */
-#line 290 "parse-gram.y"
+#line 292 "parse-gram.y"
     { yacc_flag = true; }
     break;
 
   case 39:
 
 /* Line 1537 of yacc.c  */
-#line 298 "parse-gram.y"
+#line 300 "parse-gram.y"
     {
       grammar_start_symbol_set ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]));
     }
@@ -2140,7 +2142,7 @@ yyreduce:
   case 40:
 
 /* Line 1537 of yacc.c  */
-#line 302 "parse-gram.y"
+#line 304 "parse-gram.y"
     {
       symbol_list *list;
       for (list = (yyvsp[(3) - (3)].list); list; list = list->next)
@@ -2152,7 +2154,7 @@ yyreduce:
   case 41:
 
 /* Line 1537 of yacc.c  */
-#line 309 "parse-gram.y"
+#line 311 "parse-gram.y"
     {
       symbol_list *list;
       for (list = (yyvsp[(3) - (3)].list); list; list = list->next)
@@ -2164,7 +2166,7 @@ yyreduce:
   case 42:
 
 /* Line 1537 of yacc.c  */
-#line 316 "parse-gram.y"
+#line 318 "parse-gram.y"
     {
       default_prec = true;
     }
@@ -2173,7 +2175,7 @@ yyreduce:
   case 43:
 
 /* Line 1537 of yacc.c  */
-#line 320 "parse-gram.y"
+#line 322 "parse-gram.y"
     {
       default_prec = false;
     }
@@ -2182,9 +2184,9 @@ yyreduce:
   case 44:
 
 /* Line 1537 of yacc.c  */
-#line 324 "parse-gram.y"
+#line 326 "parse-gram.y"
     {
-      muscle_code_grow ("percent_code", (yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)]));
+      muscle_code_grow ("percent_code_unqualified", (yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)]));
       code_scanner_last_string_free ();
     }
     break;
@@ -2192,37 +2194,39 @@ yyreduce:
   case 45:
 
 /* Line 1537 of yacc.c  */
-#line 329 "parse-gram.y"
+#line 331 "parse-gram.y"
     {
-      char const name_prefix[] = "percent_code_";
-      char *name = xmalloc (sizeof name_prefix + strlen ((yyvsp[(2) - (3)].uniqstr)));
+      char const name_prefix[] = "percent_code(";
+      size_t length = strlen ((yyvsp[(2) - (3)].uniqstr));
+      char *name = xmalloc (sizeof name_prefix + length + 1);
       strcpy (name, name_prefix);
       strcpy (name + sizeof name_prefix - 1, (yyvsp[(2) - (3)].uniqstr));
+      strcpy (name + sizeof name_prefix - 1 + length, ")");
       muscle_code_grow (uniqstr_new (name), (yyvsp[(3) - (3)].chars), (yylsp[(3) - (3)]));
       free (name);
       code_scanner_last_string_free ();
-      muscle_grow_user_name_list ("user_percent_code_qualifiers", (yyvsp[(2) - (3)].uniqstr), (yylsp[(2) - (3)]));
+      muscle_grow_user_name_list ("percent_code_user_qualifiers", (yyvsp[(2) - (3)].uniqstr), (yylsp[(2) - (3)]));
     }
     break;
 
   case 46:
 
 /* Line 1537 of yacc.c  */
-#line 349 "parse-gram.y"
+#line 353 "parse-gram.y"
     {}
     break;
 
   case 47:
 
 /* Line 1537 of yacc.c  */
-#line 350 "parse-gram.y"
+#line 354 "parse-gram.y"
     { muscle_code_grow ("union_name", (yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 48:
 
 /* Line 1537 of yacc.c  */
-#line 355 "parse-gram.y"
+#line 359 "parse-gram.y"
     {
       union_seen = true;
       muscle_code_grow ("stype", (yyvsp[(3) - (3)].chars), (yylsp[(3) - (3)]));
@@ -2233,14 +2237,14 @@ yyreduce:
   case 49:
 
 /* Line 1537 of yacc.c  */
-#line 366 "parse-gram.y"
+#line 370 "parse-gram.y"
     { current_class = nterm_sym; }
     break;
 
   case 50:
 
 /* Line 1537 of yacc.c  */
-#line 367 "parse-gram.y"
+#line 371 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
@@ -2250,14 +2254,14 @@ yyreduce:
   case 51:
 
 /* Line 1537 of yacc.c  */
-#line 371 "parse-gram.y"
+#line 375 "parse-gram.y"
     { current_class = token_sym; }
     break;
 
   case 52:
 
 /* Line 1537 of yacc.c  */
-#line 372 "parse-gram.y"
+#line 376 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
@@ -2267,7 +2271,7 @@ yyreduce:
   case 53:
 
 /* Line 1537 of yacc.c  */
-#line 377 "parse-gram.y"
+#line 381 "parse-gram.y"
     {
       symbol_list *list;
       tag_seen = true;
@@ -2280,7 +2284,7 @@ yyreduce:
   case 54:
 
 /* Line 1537 of yacc.c  */
-#line 388 "parse-gram.y"
+#line 392 "parse-gram.y"
     {
       symbol_list *list;
       ++current_prec;
@@ -2297,98 +2301,98 @@ yyreduce:
   case 55:
 
 /* Line 1537 of yacc.c  */
-#line 402 "parse-gram.y"
+#line 406 "parse-gram.y"
     { (yyval.assoc) = left_assoc; }
     break;
 
   case 56:
 
 /* Line 1537 of yacc.c  */
-#line 403 "parse-gram.y"
+#line 407 "parse-gram.y"
     { (yyval.assoc) = right_assoc; }
     break;
 
   case 57:
 
 /* Line 1537 of yacc.c  */
-#line 404 "parse-gram.y"
+#line 408 "parse-gram.y"
     { (yyval.assoc) = non_assoc; }
     break;
 
   case 58:
 
 /* Line 1537 of yacc.c  */
-#line 408 "parse-gram.y"
+#line 412 "parse-gram.y"
     { current_type = NULL; }
     break;
 
   case 59:
 
 /* Line 1537 of yacc.c  */
-#line 409 "parse-gram.y"
+#line 413 "parse-gram.y"
     { current_type = (yyvsp[(1) - (1)].uniqstr); tag_seen = true; }
     break;
 
   case 60:
 
 /* Line 1537 of yacc.c  */
-#line 415 "parse-gram.y"
+#line 419 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 61:
 
 /* Line 1537 of yacc.c  */
-#line 417 "parse-gram.y"
+#line 421 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), symbol_list_sym_new ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]))); }
     break;
 
   case 62:
 
 /* Line 1537 of yacc.c  */
-#line 421 "parse-gram.y"
+#line 425 "parse-gram.y"
     { (yyval.list) = (yyvsp[(1) - (1)].list); }
     break;
 
   case 63:
 
 /* Line 1537 of yacc.c  */
-#line 422 "parse-gram.y"
+#line 426 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), (yyvsp[(2) - (2)].list)); }
     break;
 
   case 64:
 
 /* Line 1537 of yacc.c  */
-#line 426 "parse-gram.y"
+#line 430 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 65:
 
 /* Line 1537 of yacc.c  */
-#line 427 "parse-gram.y"
+#line 431 "parse-gram.y"
     { (yyval.list) = symbol_list_type_new ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 66:
 
 /* Line 1537 of yacc.c  */
-#line 428 "parse-gram.y"
+#line 432 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagged_new ((yylsp[(1) - (1)])); }
     break;
 
   case 67:
 
 /* Line 1537 of yacc.c  */
-#line 429 "parse-gram.y"
+#line 433 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagless_new ((yylsp[(1) - (1)])); }
     break;
 
   case 68:
 
 /* Line 1537 of yacc.c  */
-#line 435 "parse-gram.y"
+#line 439 "parse-gram.y"
     {
        current_type = (yyvsp[(1) - (1)].uniqstr);
        tag_seen = true;
@@ -2398,7 +2402,7 @@ yyreduce:
   case 69:
 
 /* Line 1537 of yacc.c  */
-#line 440 "parse-gram.y"
+#line 444 "parse-gram.y"
     {
        symbol_class_set ((yyvsp[(1) - (1)].symbol), current_class, (yylsp[(1) - (1)]), true);
        symbol_type_set ((yyvsp[(1) - (1)].symbol), current_type, (yylsp[(1) - (1)]));
@@ -2408,7 +2412,7 @@ yyreduce:
   case 70:
 
 /* Line 1537 of yacc.c  */
-#line 445 "parse-gram.y"
+#line 449 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
       symbol_type_set ((yyvsp[(1) - (2)].symbol), current_type, (yylsp[(1) - (2)]));
@@ -2419,7 +2423,7 @@ yyreduce:
   case 71:
 
 /* Line 1537 of yacc.c  */
-#line 451 "parse-gram.y"
+#line 455 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
       symbol_type_set ((yyvsp[(1) - (2)].symbol), current_type, (yylsp[(1) - (2)]));
@@ -2430,7 +2434,7 @@ yyreduce:
   case 72:
 
 /* Line 1537 of yacc.c  */
-#line 457 "parse-gram.y"
+#line 461 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (3)].symbol), current_class, (yylsp[(1) - (3)]), true);
       symbol_type_set ((yyvsp[(1) - (3)].symbol), current_type, (yylsp[(1) - (3)]));
@@ -2442,7 +2446,7 @@ yyreduce:
   case 79:
 
 /* Line 1537 of yacc.c  */
-#line 487 "parse-gram.y"
+#line 491 "parse-gram.y"
     {
       yyerrok;
     }
@@ -2451,77 +2455,77 @@ yyreduce:
   case 80:
 
 /* Line 1537 of yacc.c  */
-#line 493 "parse-gram.y"
+#line 497 "parse-gram.y"
     { current_lhs = (yyvsp[(1) - (1)].symbol); current_lhs_location = (yylsp[(1) - (1)]); }
     break;
 
   case 82:
 
 /* Line 1537 of yacc.c  */
-#line 497 "parse-gram.y"
+#line 501 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(1) - (1)])); }
     break;
 
   case 83:
 
 /* Line 1537 of yacc.c  */
-#line 498 "parse-gram.y"
+#line 502 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(3) - (3)])); }
     break;
 
   case 85:
 
 /* Line 1537 of yacc.c  */
-#line 504 "parse-gram.y"
+#line 508 "parse-gram.y"
     { grammar_current_rule_begin (current_lhs, current_lhs_location); }
     break;
 
   case 86:
 
 /* Line 1537 of yacc.c  */
-#line 506 "parse-gram.y"
+#line 510 "parse-gram.y"
     { grammar_current_rule_symbol_append ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)])); }
     break;
 
   case 87:
 
 /* Line 1537 of yacc.c  */
-#line 508 "parse-gram.y"
+#line 512 "parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
     break;
 
   case 88:
 
 /* Line 1537 of yacc.c  */
-#line 510 "parse-gram.y"
+#line 514 "parse-gram.y"
     { grammar_current_rule_prec_set ((yyvsp[(3) - (3)].symbol), (yylsp[(3) - (3)])); }
     break;
 
   case 89:
 
 /* Line 1537 of yacc.c  */
-#line 512 "parse-gram.y"
+#line 516 "parse-gram.y"
     { grammar_current_rule_dprec_set ((yyvsp[(3) - (3)].integer), (yylsp[(3) - (3)])); }
     break;
 
   case 90:
 
 /* Line 1537 of yacc.c  */
-#line 514 "parse-gram.y"
+#line 518 "parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[(3) - (3)].uniqstr), (yylsp[(3) - (3)])); }
     break;
 
   case 92:
 
 /* Line 1537 of yacc.c  */
-#line 524 "parse-gram.y"
+#line 528 "parse-gram.y"
     { (yyval.uniqstr) = uniqstr_new ((yyvsp[(1) - (1)].chars)); }
     break;
 
   case 93:
 
 /* Line 1537 of yacc.c  */
-#line 530 "parse-gram.y"
+#line 534 "parse-gram.y"
     {
       static char one[] = "1";
       (yyval.chars) = one;
@@ -2531,7 +2535,7 @@ yyreduce:
   case 95:
 
 /* Line 1537 of yacc.c  */
-#line 544 "parse-gram.y"
+#line 548 "parse-gram.y"
     {
       code_props plain_code;
       (yyvsp[(1) - (1)].code)[strlen ((yyvsp[(1) - (1)].code)) - 1] = '\n';
@@ -2545,14 +2549,14 @@ yyreduce:
   case 96:
 
 /* Line 1537 of yacc.c  */
-#line 564 "parse-gram.y"
+#line 568 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 97:
 
 /* Line 1537 of yacc.c  */
-#line 566 "parse-gram.y"
+#line 570 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[(1) - (1)].character)), (yylsp[(1) - (1)]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[(1) - (1)]), false);
@@ -2563,14 +2567,14 @@ yyreduce:
   case 98:
 
 /* Line 1537 of yacc.c  */
-#line 574 "parse-gram.y"
+#line 578 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 101:
 
 /* Line 1537 of yacc.c  */
-#line 586 "parse-gram.y"
+#line 590 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[(1) - (1)].chars)), (yylsp[(1) - (1)]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[(1) - (1)]), false);
@@ -2580,7 +2584,7 @@ yyreduce:
   case 103:
 
 /* Line 1537 of yacc.c  */
-#line 595 "parse-gram.y"
+#line 599 "parse-gram.y"
     {
       code_props plain_code;
       code_props_plain_init (&plain_code, (yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)]));
@@ -2594,7 +2598,7 @@ yyreduce:
 
 
 /* Line 1537 of yacc.c  */
-#line 2598 "parse-gram.c"
+#line 2602 "parse-gram.c"
       default: break;
     }
   YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);
@@ -2813,7 +2817,7 @@ yyreturn:
 
 
 /* Line 1537 of yacc.c  */
-#line 605 "parse-gram.y"
+#line 609 "parse-gram.y"
 
 
 
