@@ -821,9 +821,6 @@ static const yytype_int16 yypgoto[] =
      -60,   -35,   -59,   -60
 };
 
-#define yyis_pact_ninf(yystate) \
-  ((yystate) == (-60))
-
 /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
    positive, shift that token.  If negative, reduce the rule which
    number is the opposite.  If zero, do what YYDEFACT says.
@@ -849,6 +846,12 @@ static const yytype_int16 yytable[] =
       44,    39,   129,    40,    41,    95,   104,   114,   141,    42
 };
 
+#define yyis_pact_ninf(yystate) \
+  ((yystate) == (-60))
+
+#define yyis_table_ninf(yytable_value) \
+  YYID (0)
+
 static const yytype_uint8 yycheck[] =
 {
       35,     0,     1,     3,     0,     3,     5,     6,     7,     8,
@@ -869,9 +872,6 @@ static const yytype_uint8 yycheck[] =
        2,    49,   119,    51,    52,    49,    52,    83,   134,    57
 };
 
-#define yyis_table_ninf(yytable_value) \
-  YYID (0)
-
 /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
    symbol of state STATE-NUM.  */
 static const yytype_uint8 yystos[] =
@@ -1475,7 +1475,8 @@ yysyntax_error (char *yyresult, int yystate, int yychar)
       yyfmt = yystpcpy (yyformat, yyunexpected);
 
       for (yyx = yyxbegin; yyx < yyxend; ++yyx)
-	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
+	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
+	    && !yyis_table_ninf (yytable[yyx + yyn]))
 	  {
 	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
 	      {
@@ -1700,7 +1701,7 @@ YYLTYPE yylloc;
 
 /* User initialization code.  */
 
-/* Line 1250 of yacc.c  */
+/* Line 1251 of yacc.c  */
 #line 86 "parse-gram.y"
 {
   /* Bison's grammar can initial empty locations, hence a default
@@ -1709,8 +1710,8 @@ YYLTYPE yylloc;
   boundary_set (&yylloc.end, current_file, 1, 1);
 }
 
-/* Line 1250 of yacc.c  */
-#line 1714 "parse-gram.c"
+/* Line 1251 of yacc.c  */
+#line 1715 "parse-gram.c"
   yylsp[0] = yylloc;
 
   goto yysetstate;
@@ -1897,7 +1898,7 @@ yyreduce:
     {
         case 6:
 
-/* Line 1463 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 223 "parse-gram.y"
     {
       code_props plain_code;
@@ -1912,14 +1913,14 @@ yyreduce:
 
   case 7:
 
-/* Line 1463 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 232 "parse-gram.y"
     { debug_flag = true; }
     break;
 
   case 8:
 
-/* Line 1463 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 234 "parse-gram.y"
     {
       muscle_percent_define_insert ((yyvsp[(2) - (3)].uniqstr), (yylsp[(2) - (3)]), (yyvsp[(3) - (3)].chars),
@@ -1929,14 +1930,14 @@ yyreduce:
 
   case 9:
 
-/* Line 1463 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 238 "parse-gram.y"
     { defines_flag = true; }
     break;
 
   case 10:
 
-/* Line 1463 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 240 "parse-gram.y"
     {
       defines_flag = true;
@@ -1946,42 +1947,42 @@ yyreduce:
 
   case 11:
 
-/* Line 1463 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 244 "parse-gram.y"
     { error_verbose = true; }
     break;
 
   case 12:
 
-/* Line 1463 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 245 "parse-gram.y"
     { expected_sr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 13:
 
-/* Line 1463 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 246 "parse-gram.y"
     { expected_rr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 14:
 
-/* Line 1463 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 247 "parse-gram.y"
     { spec_file_prefix = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 15:
 
-/* Line 1463 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 248 "parse-gram.y"
     { spec_file_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 16:
 
-/* Line 1463 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 250 "parse-gram.y"
     {
       nondeterministic_parser = true;
@@ -1991,7 +1992,7 @@ yyreduce:
 
   case 17:
 
-/* Line 1463 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 255 "parse-gram.y"
     {
       code_props action;
@@ -2005,77 +2006,77 @@ yyreduce:
 
   case 18:
 
-/* Line 1463 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 263 "parse-gram.y"
     { language_argmatch ((yyvsp[(2) - (2)].chars), grammar_prio, (yylsp[(1) - (2)])); }
     break;
 
   case 19:
 
-/* Line 1463 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 264 "parse-gram.y"
     { add_param ("lex_param", (yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
     break;
 
   case 20:
 
-/* Line 1463 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 265 "parse-gram.y"
     { locations_flag = true; }
     break;
 
   case 21:
 
-/* Line 1463 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 266 "parse-gram.y"
     { spec_name_prefix = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 22:
 
-/* Line 1463 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 267 "parse-gram.y"
     { spec_name_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 23:
 
-/* Line 1463 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 268 "parse-gram.y"
     { no_lines_flag = true; }
     break;
 
   case 24:
 
-/* Line 1463 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 269 "parse-gram.y"
     { nondeterministic_parser = true; }
     break;
 
   case 25:
 
-/* Line 1463 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 270 "parse-gram.y"
     { spec_outfile = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 26:
 
-/* Line 1463 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 271 "parse-gram.y"
     { spec_outfile = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 27:
 
-/* Line 1463 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 272 "parse-gram.y"
     { add_param ("parse_param", (yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
     break;
 
   case 28:
 
-/* Line 1463 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 274 "parse-gram.y"
     {
       /* %pure-parser is deprecated in favor of `%define api.pure', so use
@@ -2095,14 +2096,14 @@ yyreduce:
 
   case 29:
 
-/* Line 1463 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 288 "parse-gram.y"
     { version_check (&(yylsp[(2) - (2)]), (yyvsp[(2) - (2)].chars)); }
     break;
 
   case 30:
 
-/* Line 1463 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 290 "parse-gram.y"
     {
       char const *skeleton_user = (yyvsp[(2) - (2)].chars);
@@ -2131,28 +2132,28 @@ yyreduce:
 
   case 31:
 
-/* Line 1463 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 313 "parse-gram.y"
     { token_table_flag = true; }
     break;
 
   case 32:
 
-/* Line 1463 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 314 "parse-gram.y"
     { report_flag |= report_states; }
     break;
 
   case 33:
 
-/* Line 1463 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 315 "parse-gram.y"
     { yacc_flag = true; }
     break;
 
   case 37:
 
-/* Line 1463 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 323 "parse-gram.y"
     {
       grammar_start_symbol_set ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]));
@@ -2161,7 +2162,7 @@ yyreduce:
 
   case 38:
 
-/* Line 1463 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 327 "parse-gram.y"
     {
       symbol_list *list;
@@ -2173,7 +2174,7 @@ yyreduce:
 
   case 39:
 
-/* Line 1463 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 334 "parse-gram.y"
     {
       symbol_list *list;
@@ -2185,7 +2186,7 @@ yyreduce:
 
   case 40:
 
-/* Line 1463 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 341 "parse-gram.y"
     {
       default_prec = true;
@@ -2194,7 +2195,7 @@ yyreduce:
 
   case 41:
 
-/* Line 1463 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 345 "parse-gram.y"
     {
       default_prec = false;
@@ -2203,7 +2204,7 @@ yyreduce:
 
   case 42:
 
-/* Line 1463 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 349 "parse-gram.y"
     {
       /* Do not invoke muscle_percent_code_grow here since it invokes
@@ -2215,7 +2216,7 @@ yyreduce:
 
   case 43:
 
-/* Line 1463 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 356 "parse-gram.y"
     {
       muscle_percent_code_grow ((yyvsp[(2) - (3)].uniqstr), (yylsp[(2) - (3)]), (yyvsp[(3) - (3)].chars), (yylsp[(3) - (3)]));
@@ -2225,21 +2226,21 @@ yyreduce:
 
   case 44:
 
-/* Line 1463 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 370 "parse-gram.y"
     {}
     break;
 
   case 45:
 
-/* Line 1463 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 371 "parse-gram.y"
     { muscle_code_grow ("union_name", (yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 46:
 
-/* Line 1463 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 376 "parse-gram.y"
     {
       union_seen = true;
@@ -2250,14 +2251,14 @@ yyreduce:
 
   case 47:
 
-/* Line 1463 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 387 "parse-gram.y"
     { current_class = nterm_sym; }
     break;
 
   case 48:
 
-/* Line 1463 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 388 "parse-gram.y"
     {
       current_class = unknown_sym;
@@ -2267,14 +2268,14 @@ yyreduce:
 
   case 49:
 
-/* Line 1463 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 392 "parse-gram.y"
     { current_class = token_sym; }
     break;
 
   case 50:
 
-/* Line 1463 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 393 "parse-gram.y"
     {
       current_class = unknown_sym;
@@ -2284,7 +2285,7 @@ yyreduce:
 
   case 51:
 
-/* Line 1463 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 398 "parse-gram.y"
     {
       symbol_list *list;
@@ -2297,7 +2298,7 @@ yyreduce:
 
   case 52:
 
-/* Line 1463 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 409 "parse-gram.y"
     {
       symbol_list *list;
@@ -2314,126 +2315,126 @@ yyreduce:
 
   case 53:
 
-/* Line 1463 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 423 "parse-gram.y"
     { (yyval.assoc) = left_assoc; }
     break;
 
   case 54:
 
-/* Line 1463 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 424 "parse-gram.y"
     { (yyval.assoc) = right_assoc; }
     break;
 
   case 55:
 
-/* Line 1463 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 425 "parse-gram.y"
     { (yyval.assoc) = non_assoc; }
     break;
 
   case 56:
 
-/* Line 1463 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 429 "parse-gram.y"
     { current_type = NULL; }
     break;
 
   case 57:
 
-/* Line 1463 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 430 "parse-gram.y"
     { current_type = (yyvsp[(1) - (1)].uniqstr); tag_seen = true; }
     break;
 
   case 58:
 
-/* Line 1463 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 436 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 59:
 
-/* Line 1463 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 438 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), symbol_list_sym_new ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]))); }
     break;
 
   case 60:
 
-/* Line 1463 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 442 "parse-gram.y"
     { (yyval.symbol) = (yyvsp[(1) - (1)].symbol); }
     break;
 
   case 61:
 
-/* Line 1463 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 443 "parse-gram.y"
     { (yyval.symbol) = (yyvsp[(1) - (2)].symbol); symbol_user_token_number_set ((yyvsp[(1) - (2)].symbol), (yyvsp[(2) - (2)].integer), (yylsp[(2) - (2)])); }
     break;
 
   case 62:
 
-/* Line 1463 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 449 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 63:
 
-/* Line 1463 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 451 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), symbol_list_sym_new ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]))); }
     break;
 
   case 64:
 
-/* Line 1463 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 455 "parse-gram.y"
     { (yyval.list) = (yyvsp[(1) - (1)].list); }
     break;
 
   case 65:
 
-/* Line 1463 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 456 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), (yyvsp[(2) - (2)].list)); }
     break;
 
   case 66:
 
-/* Line 1463 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 460 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 67:
 
-/* Line 1463 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 461 "parse-gram.y"
     { (yyval.list) = symbol_list_type_new ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 68:
 
-/* Line 1463 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 462 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagged_new ((yylsp[(1) - (1)])); }
     break;
 
   case 69:
 
-/* Line 1463 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 463 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagless_new ((yylsp[(1) - (1)])); }
     break;
 
   case 70:
 
-/* Line 1463 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 469 "parse-gram.y"
     {
        current_type = (yyvsp[(1) - (1)].uniqstr);
@@ -2443,7 +2444,7 @@ yyreduce:
 
   case 71:
 
-/* Line 1463 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 474 "parse-gram.y"
     {
        symbol_class_set ((yyvsp[(1) - (1)].symbol), current_class, (yylsp[(1) - (1)]), true);
@@ -2453,7 +2454,7 @@ yyreduce:
 
   case 72:
 
-/* Line 1463 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 479 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
@@ -2464,7 +2465,7 @@ yyreduce:
 
   case 73:
 
-/* Line 1463 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 485 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
@@ -2475,7 +2476,7 @@ yyreduce:
 
   case 74:
 
-/* Line 1463 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 491 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (3)].symbol), current_class, (yylsp[(1) - (3)]), true);
@@ -2487,7 +2488,7 @@ yyreduce:
 
   case 81:
 
-/* Line 1463 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 521 "parse-gram.y"
     {
       yyerrok;
@@ -2496,7 +2497,7 @@ yyreduce:
 
   case 82:
 
-/* Line 1463 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 527 "parse-gram.y"
     { current_lhs = (yyvsp[(1) - (2)].symbol); current_lhs_location = (yylsp[(1) - (2)]);
     current_lhs_named_ref = (yyvsp[(2) - (2)].named_ref); }
@@ -2504,21 +2505,21 @@ yyreduce:
 
   case 84:
 
-/* Line 1463 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 532 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(1) - (1)])); }
     break;
 
   case 85:
 
-/* Line 1463 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 533 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(3) - (3)])); }
     break;
 
   case 87:
 
-/* Line 1463 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 539 "parse-gram.y"
     { grammar_current_rule_begin (current_lhs, current_lhs_location,
 				  current_lhs_named_ref); }
@@ -2526,70 +2527,70 @@ yyreduce:
 
   case 88:
 
-/* Line 1463 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 542 "parse-gram.y"
     { grammar_current_rule_symbol_append ((yyvsp[(2) - (3)].symbol), (yylsp[(2) - (3)]), (yyvsp[(3) - (3)].named_ref)); }
     break;
 
   case 89:
 
-/* Line 1463 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 544 "parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[(2) - (3)].code), (yylsp[(2) - (3)]), (yyvsp[(3) - (3)].named_ref)); }
     break;
 
   case 90:
 
-/* Line 1463 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 546 "parse-gram.y"
     { grammar_current_rule_prec_set ((yyvsp[(3) - (3)].symbol), (yylsp[(3) - (3)])); }
     break;
 
   case 91:
 
-/* Line 1463 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 548 "parse-gram.y"
     { grammar_current_rule_dprec_set ((yyvsp[(3) - (3)].integer), (yylsp[(3) - (3)])); }
     break;
 
   case 92:
 
-/* Line 1463 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 550 "parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[(3) - (3)].uniqstr), (yylsp[(3) - (3)])); }
     break;
 
   case 93:
 
-/* Line 1463 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 554 "parse-gram.y"
     { (yyval.named_ref) = 0; }
     break;
 
   case 94:
 
-/* Line 1463 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 556 "parse-gram.y"
     { (yyval.named_ref) = named_ref_new((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 96:
 
-/* Line 1463 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 568 "parse-gram.y"
     { (yyval.uniqstr) = uniqstr_new ((yyvsp[(1) - (1)].chars)); }
     break;
 
   case 97:
 
-/* Line 1463 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 573 "parse-gram.y"
     { (yyval.chars) = ""; }
     break;
 
   case 99:
 
-/* Line 1463 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 584 "parse-gram.y"
     {
       code_props plain_code;
@@ -2603,14 +2604,14 @@ yyreduce:
 
   case 100:
 
-/* Line 1463 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 604 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 101:
 
-/* Line 1463 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 606 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[(1) - (1)].character)), (yylsp[(1) - (1)]));
@@ -2621,14 +2622,14 @@ yyreduce:
 
   case 102:
 
-/* Line 1463 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 614 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 105:
 
-/* Line 1463 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 626 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[(1) - (1)].chars)), (yylsp[(1) - (1)]));
@@ -2638,7 +2639,7 @@ yyreduce:
 
   case 107:
 
-/* Line 1463 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 635 "parse-gram.y"
     {
       code_props plain_code;
@@ -2652,8 +2653,8 @@ yyreduce:
 
 
 
-/* Line 1463 of yacc.c  */
-#line 2657 "parse-gram.c"
+/* Line 1464 of yacc.c  */
+#line 2658 "parse-gram.c"
       default: break;
     }
   YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);
@@ -2871,7 +2872,7 @@ yyreturn:
 
 
 
-/* Line 1683 of yacc.c  */
+/* Line 1684 of yacc.c  */
 #line 645 "parse-gram.y"
 
 
