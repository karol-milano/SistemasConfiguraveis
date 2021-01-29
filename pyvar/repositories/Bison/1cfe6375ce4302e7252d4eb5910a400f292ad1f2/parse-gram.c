@@ -1691,7 +1691,7 @@ YYLTYPE yylloc;
 
 /* User initialization code.  */
 
-/* Line 1247 of yacc.c  */
+/* Line 1243 of yacc.c  */
 #line 86 "parse-gram.y"
 {
   /* Bison's grammar can initial empty locations, hence a default
@@ -1700,7 +1700,7 @@ YYLTYPE yylloc;
   boundary_set (&yylloc.end, current_file, 1, 1);
 }
 
-/* Line 1247 of yacc.c  */
+/* Line 1243 of yacc.c  */
 #line 1705 "parse-gram.c"
   yylsp[0] = yylloc;
 
@@ -1888,7 +1888,7 @@ yyreduce:
     {
         case 6:
 
-/* Line 1464 of yacc.c  */
+/* Line 1460 of yacc.c  */
 #line 220 "parse-gram.y"
     {
       code_props plain_code;
@@ -1903,14 +1903,14 @@ yyreduce:
 
   case 7:
 
-/* Line 1464 of yacc.c  */
+/* Line 1460 of yacc.c  */
 #line 229 "parse-gram.y"
     { debug_flag = true; }
     break;
 
   case 8:
 
-/* Line 1464 of yacc.c  */
+/* Line 1460 of yacc.c  */
 #line 231 "parse-gram.y"
     {
       muscle_percent_define_insert ((yyvsp[(2) - (3)].uniqstr), (yylsp[(2) - (3)]), (yyvsp[(3) - (3)].chars));
@@ -1919,14 +1919,14 @@ yyreduce:
 
   case 9:
 
-/* Line 1464 of yacc.c  */
+/* Line 1460 of yacc.c  */
 #line 234 "parse-gram.y"
     { defines_flag = true; }
     break;
 
   case 10:
 
-/* Line 1464 of yacc.c  */
+/* Line 1460 of yacc.c  */
 #line 236 "parse-gram.y"
     {
       defines_flag = true;
@@ -1936,42 +1936,42 @@ yyreduce:
 
   case 11:
 
-/* Line 1464 of yacc.c  */
+/* Line 1460 of yacc.c  */
 #line 240 "parse-gram.y"
     { error_verbose = true; }
     break;
 
   case 12:
 
-/* Line 1464 of yacc.c  */
+/* Line 1460 of yacc.c  */
 #line 241 "parse-gram.y"
     { expected_sr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 13:
 
-/* Line 1464 of yacc.c  */
+/* Line 1460 of yacc.c  */
 #line 242 "parse-gram.y"
     { expected_rr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 14:
 
-/* Line 1464 of yacc.c  */
+/* Line 1460 of yacc.c  */
 #line 243 "parse-gram.y"
     { spec_file_prefix = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 15:
 
-/* Line 1464 of yacc.c  */
+/* Line 1460 of yacc.c  */
 #line 244 "parse-gram.y"
     { spec_file_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 16:
 
-/* Line 1464 of yacc.c  */
+/* Line 1460 of yacc.c  */
 #line 246 "parse-gram.y"
     {
       nondeterministic_parser = true;
@@ -1981,7 +1981,7 @@ yyreduce:
 
   case 17:
 
-/* Line 1464 of yacc.c  */
+/* Line 1460 of yacc.c  */
 #line 251 "parse-gram.y"
     {
       code_props action;
@@ -1995,77 +1995,77 @@ yyreduce:
 
   case 18:
 
-/* Line 1464 of yacc.c  */
+/* Line 1460 of yacc.c  */
 #line 259 "parse-gram.y"
     { language_argmatch ((yyvsp[(2) - (2)].chars), 1, &(yylsp[(1) - (2)])); }
     break;
 
   case 19:
 
-/* Line 1464 of yacc.c  */
+/* Line 1460 of yacc.c  */
 #line 260 "parse-gram.y"
     { add_param ("lex_param", (yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
     break;
 
   case 20:
 
-/* Line 1464 of yacc.c  */
+/* Line 1460 of yacc.c  */
 #line 261 "parse-gram.y"
     { locations_flag = true; }
     break;
 
   case 21:
 
-/* Line 1464 of yacc.c  */
+/* Line 1460 of yacc.c  */
 #line 262 "parse-gram.y"
     { spec_name_prefix = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 22:
 
-/* Line 1464 of yacc.c  */
+/* Line 1460 of yacc.c  */
 #line 263 "parse-gram.y"
     { spec_name_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 23:
 
-/* Line 1464 of yacc.c  */
+/* Line 1460 of yacc.c  */
 #line 264 "parse-gram.y"
     { no_lines_flag = true; }
     break;
 
   case 24:
 
-/* Line 1464 of yacc.c  */
+/* Line 1460 of yacc.c  */
 #line 265 "parse-gram.y"
     { nondeterministic_parser = true; }
     break;
 
   case 25:
 
-/* Line 1464 of yacc.c  */
+/* Line 1460 of yacc.c  */
 #line 266 "parse-gram.y"
     { spec_outfile = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 26:
 
-/* Line 1464 of yacc.c  */
+/* Line 1460 of yacc.c  */
 #line 267 "parse-gram.y"
     { spec_outfile = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 27:
 
-/* Line 1464 of yacc.c  */
+/* Line 1460 of yacc.c  */
 #line 268 "parse-gram.y"
     { add_param ("parse_param", (yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
     break;
 
   case 28:
 
-/* Line 1464 of yacc.c  */
+/* Line 1460 of yacc.c  */
 #line 270 "parse-gram.y"
     {
       /* %pure-parser is deprecated in favor of `%define api.pure', so use
@@ -2083,14 +2083,14 @@ yyreduce:
 
   case 29:
 
-/* Line 1464 of yacc.c  */
+/* Line 1460 of yacc.c  */
 #line 282 "parse-gram.y"
     { version_check (&(yylsp[(2) - (2)]), (yyvsp[(2) - (2)].chars)); }
     break;
 
   case 30:
 
-/* Line 1464 of yacc.c  */
+/* Line 1460 of yacc.c  */
 #line 284 "parse-gram.y"
     {
       char const *skeleton_user = (yyvsp[(2) - (2)].chars);
@@ -2119,28 +2119,28 @@ yyreduce:
 
   case 31:
 
-/* Line 1464 of yacc.c  */
+/* Line 1460 of yacc.c  */
 #line 307 "parse-gram.y"
     { token_table_flag = true; }
     break;
 
   case 32:
 
-/* Line 1464 of yacc.c  */
+/* Line 1460 of yacc.c  */
 #line 308 "parse-gram.y"
     { report_flag |= report_states; }
     break;
 
   case 33:
 
-/* Line 1464 of yacc.c  */
+/* Line 1460 of yacc.c  */
 #line 309 "parse-gram.y"
     { yacc_flag = true; }
     break;
 
   case 37:
 
-/* Line 1464 of yacc.c  */
+/* Line 1460 of yacc.c  */
 #line 317 "parse-gram.y"
     {
       grammar_start_symbol_set ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]));
@@ -2149,7 +2149,7 @@ yyreduce:
 
   case 38:
 
-/* Line 1464 of yacc.c  */
+/* Line 1460 of yacc.c  */
 #line 321 "parse-gram.y"
     {
       symbol_list *list;
@@ -2161,7 +2161,7 @@ yyreduce:
 
   case 39:
 
-/* Line 1464 of yacc.c  */
+/* Line 1460 of yacc.c  */
 #line 328 "parse-gram.y"
     {
       symbol_list *list;
@@ -2173,7 +2173,7 @@ yyreduce:
 
   case 40:
 
-/* Line 1464 of yacc.c  */
+/* Line 1460 of yacc.c  */
 #line 335 "parse-gram.y"
     {
       default_prec = true;
@@ -2182,7 +2182,7 @@ yyreduce:
 
   case 41:
 
-/* Line 1464 of yacc.c  */
+/* Line 1460 of yacc.c  */
 #line 339 "parse-gram.y"
     {
       default_prec = false;
@@ -2191,7 +2191,7 @@ yyreduce:
 
   case 42:
 
-/* Line 1464 of yacc.c  */
+/* Line 1460 of yacc.c  */
 #line 343 "parse-gram.y"
     {
       /* Do not invoke muscle_percent_code_grow here since it invokes
@@ -2203,7 +2203,7 @@ yyreduce:
 
   case 43:
 
-/* Line 1464 of yacc.c  */
+/* Line 1460 of yacc.c  */
 #line 350 "parse-gram.y"
     {
       muscle_percent_code_grow ((yyvsp[(2) - (3)].uniqstr), (yylsp[(2) - (3)]), (yyvsp[(3) - (3)].chars), (yylsp[(3) - (3)]));
@@ -2213,21 +2213,21 @@ yyreduce:
 
   case 44:
 
-/* Line 1464 of yacc.c  */
+/* Line 1460 of yacc.c  */
 #line 364 "parse-gram.y"
     {}
     break;
 
   case 45:
 
-/* Line 1464 of yacc.c  */
+/* Line 1460 of yacc.c  */
 #line 365 "parse-gram.y"
     { muscle_code_grow ("union_name", (yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 46:
 
-/* Line 1464 of yacc.c  */
+/* Line 1460 of yacc.c  */
 #line 370 "parse-gram.y"
     {
       union_seen = true;
@@ -2238,14 +2238,14 @@ yyreduce:
 
   case 47:
 
-/* Line 1464 of yacc.c  */
+/* Line 1460 of yacc.c  */
 #line 381 "parse-gram.y"
     { current_class = nterm_sym; }
     break;
 
   case 48:
 
-/* Line 1464 of yacc.c  */
+/* Line 1460 of yacc.c  */
 #line 382 "parse-gram.y"
     {
       current_class = unknown_sym;
@@ -2255,14 +2255,14 @@ yyreduce:
 
   case 49:
 
-/* Line 1464 of yacc.c  */
+/* Line 1460 of yacc.c  */
 #line 386 "parse-gram.y"
     { current_class = token_sym; }
     break;
 
   case 50:
 
-/* Line 1464 of yacc.c  */
+/* Line 1460 of yacc.c  */
 #line 387 "parse-gram.y"
     {
       current_class = unknown_sym;
@@ -2272,7 +2272,7 @@ yyreduce:
 
   case 51:
 
-/* Line 1464 of yacc.c  */
+/* Line 1460 of yacc.c  */
 #line 392 "parse-gram.y"
     {
       symbol_list *list;
@@ -2285,7 +2285,7 @@ yyreduce:
 
   case 52:
 
-/* Line 1464 of yacc.c  */
+/* Line 1460 of yacc.c  */
 #line 403 "parse-gram.y"
     {
       symbol_list *list;
@@ -2302,126 +2302,126 @@ yyreduce:
 
   case 53:
 
-/* Line 1464 of yacc.c  */
+/* Line 1460 of yacc.c  */
 #line 417 "parse-gram.y"
     { (yyval.assoc) = left_assoc; }
     break;
 
   case 54:
 
-/* Line 1464 of yacc.c  */
+/* Line 1460 of yacc.c  */
 #line 418 "parse-gram.y"
     { (yyval.assoc) = right_assoc; }
     break;
 
   case 55:
 
-/* Line 1464 of yacc.c  */
+/* Line 1460 of yacc.c  */
 #line 419 "parse-gram.y"
     { (yyval.assoc) = non_assoc; }
     break;
 
   case 56:
 
-/* Line 1464 of yacc.c  */
+/* Line 1460 of yacc.c  */
 #line 423 "parse-gram.y"
     { current_type = NULL; }
     break;
 
   case 57:
 
-/* Line 1464 of yacc.c  */
+/* Line 1460 of yacc.c  */
 #line 424 "parse-gram.y"
     { current_type = (yyvsp[(1) - (1)].uniqstr); tag_seen = true; }
     break;
 
   case 58:
 
-/* Line 1464 of yacc.c  */
+/* Line 1460 of yacc.c  */
 #line 430 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 59:
 
-/* Line 1464 of yacc.c  */
+/* Line 1460 of yacc.c  */
 #line 432 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), symbol_list_sym_new ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]))); }
     break;
 
   case 60:
 
-/* Line 1464 of yacc.c  */
+/* Line 1460 of yacc.c  */
 #line 436 "parse-gram.y"
     { (yyval.symbol) = (yyvsp[(1) - (1)].symbol); }
     break;
 
   case 61:
 
-/* Line 1464 of yacc.c  */
+/* Line 1460 of yacc.c  */
 #line 437 "parse-gram.y"
     { (yyval.symbol) = (yyvsp[(1) - (2)].symbol); symbol_user_token_number_set ((yyvsp[(1) - (2)].symbol), (yyvsp[(2) - (2)].integer), (yylsp[(2) - (2)])); }
     break;
 
   case 62:
 
-/* Line 1464 of yacc.c  */
+/* Line 1460 of yacc.c  */
 #line 443 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 63:
 
-/* Line 1464 of yacc.c  */
+/* Line 1460 of yacc.c  */
 #line 445 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), symbol_list_sym_new ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]))); }
     break;
 
   case 64:
 
-/* Line 1464 of yacc.c  */
+/* Line 1460 of yacc.c  */
 #line 449 "parse-gram.y"
     { (yyval.list) = (yyvsp[(1) - (1)].list); }
     break;
 
   case 65:
 
-/* Line 1464 of yacc.c  */
+/* Line 1460 of yacc.c  */
 #line 450 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), (yyvsp[(2) - (2)].list)); }
     break;
 
   case 66:
 
-/* Line 1464 of yacc.c  */
+/* Line 1460 of yacc.c  */
 #line 454 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 67:
 
-/* Line 1464 of yacc.c  */
+/* Line 1460 of yacc.c  */
 #line 455 "parse-gram.y"
     { (yyval.list) = symbol_list_type_new ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 68:
 
-/* Line 1464 of yacc.c  */
+/* Line 1460 of yacc.c  */
 #line 456 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagged_new ((yylsp[(1) - (1)])); }
     break;
 
   case 69:
 
-/* Line 1464 of yacc.c  */
+/* Line 1460 of yacc.c  */
 #line 457 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagless_new ((yylsp[(1) - (1)])); }
     break;
 
   case 70:
 
-/* Line 1464 of yacc.c  */
+/* Line 1460 of yacc.c  */
 #line 463 "parse-gram.y"
     {
        current_type = (yyvsp[(1) - (1)].uniqstr);
@@ -2431,7 +2431,7 @@ yyreduce:
 
   case 71:
 
-/* Line 1464 of yacc.c  */
+/* Line 1460 of yacc.c  */
 #line 468 "parse-gram.y"
     {
        symbol_class_set ((yyvsp[(1) - (1)].symbol), current_class, (yylsp[(1) - (1)]), true);
@@ -2441,7 +2441,7 @@ yyreduce:
 
   case 72:
 
-/* Line 1464 of yacc.c  */
+/* Line 1460 of yacc.c  */
 #line 473 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
@@ -2452,7 +2452,7 @@ yyreduce:
 
   case 73:
 
-/* Line 1464 of yacc.c  */
+/* Line 1460 of yacc.c  */
 #line 479 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
@@ -2463,7 +2463,7 @@ yyreduce:
 
   case 74:
 
-/* Line 1464 of yacc.c  */
+/* Line 1460 of yacc.c  */
 #line 485 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (3)].symbol), current_class, (yylsp[(1) - (3)]), true);
@@ -2475,7 +2475,7 @@ yyreduce:
 
   case 81:
 
-/* Line 1464 of yacc.c  */
+/* Line 1460 of yacc.c  */
 #line 515 "parse-gram.y"
     {
       yyerrok;
@@ -2484,77 +2484,77 @@ yyreduce:
 
   case 82:
 
-/* Line 1464 of yacc.c  */
+/* Line 1460 of yacc.c  */
 #line 521 "parse-gram.y"
     { current_lhs = (yyvsp[(1) - (1)].symbol); current_lhs_location = (yylsp[(1) - (1)]); }
     break;
 
   case 84:
 
-/* Line 1464 of yacc.c  */
+/* Line 1460 of yacc.c  */
 #line 525 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(1) - (1)])); }
     break;
 
   case 85:
 
-/* Line 1464 of yacc.c  */
+/* Line 1460 of yacc.c  */
 #line 526 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(3) - (3)])); }
     break;
 
   case 87:
 
-/* Line 1464 of yacc.c  */
+/* Line 1460 of yacc.c  */
 #line 532 "parse-gram.y"
     { grammar_current_rule_begin (current_lhs, current_lhs_location); }
     break;
 
   case 88:
 
-/* Line 1464 of yacc.c  */
+/* Line 1460 of yacc.c  */
 #line 534 "parse-gram.y"
     { grammar_current_rule_symbol_append ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)])); }
     break;
 
   case 89:
 
-/* Line 1464 of yacc.c  */
+/* Line 1460 of yacc.c  */
 #line 536 "parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
     break;
 
   case 90:
 
-/* Line 1464 of yacc.c  */
+/* Line 1460 of yacc.c  */
 #line 538 "parse-gram.y"
     { grammar_current_rule_prec_set ((yyvsp[(3) - (3)].symbol), (yylsp[(3) - (3)])); }
     break;
 
   case 91:
 
-/* Line 1464 of yacc.c  */
+/* Line 1460 of yacc.c  */
 #line 540 "parse-gram.y"
     { grammar_current_rule_dprec_set ((yyvsp[(3) - (3)].integer), (yylsp[(3) - (3)])); }
     break;
 
   case 92:
 
-/* Line 1464 of yacc.c  */
+/* Line 1460 of yacc.c  */
 #line 542 "parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[(3) - (3)].uniqstr), (yylsp[(3) - (3)])); }
     break;
 
   case 94:
 
-/* Line 1464 of yacc.c  */
+/* Line 1460 of yacc.c  */
 #line 552 "parse-gram.y"
     { (yyval.uniqstr) = uniqstr_new ((yyvsp[(1) - (1)].chars)); }
     break;
 
   case 95:
 
-/* Line 1464 of yacc.c  */
+/* Line 1460 of yacc.c  */
 #line 558 "parse-gram.y"
     {
       (yyval.chars) = "";
@@ -2563,7 +2563,7 @@ yyreduce:
 
   case 97:
 
-/* Line 1464 of yacc.c  */
+/* Line 1460 of yacc.c  */
 #line 571 "parse-gram.y"
     {
       code_props plain_code;
@@ -2577,14 +2577,14 @@ yyreduce:
 
   case 98:
 
-/* Line 1464 of yacc.c  */
+/* Line 1460 of yacc.c  */
 #line 591 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 99:
 
-/* Line 1464 of yacc.c  */
+/* Line 1460 of yacc.c  */
 #line 593 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[(1) - (1)].character)), (yylsp[(1) - (1)]));
@@ -2595,14 +2595,14 @@ yyreduce:
 
   case 100:
 
-/* Line 1464 of yacc.c  */
+/* Line 1460 of yacc.c  */
 #line 601 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 103:
 
-/* Line 1464 of yacc.c  */
+/* Line 1460 of yacc.c  */
 #line 613 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[(1) - (1)].chars)), (yylsp[(1) - (1)]));
@@ -2612,7 +2612,7 @@ yyreduce:
 
   case 105:
 
-/* Line 1464 of yacc.c  */
+/* Line 1460 of yacc.c  */
 #line 622 "parse-gram.y"
     {
       code_props plain_code;
@@ -2626,7 +2626,7 @@ yyreduce:
 
 
 
-/* Line 1464 of yacc.c  */
+/* Line 1460 of yacc.c  */
 #line 2631 "parse-gram.c"
       default: break;
     }
@@ -2845,7 +2845,7 @@ yyreturn:
 
 
 
-/* Line 1684 of yacc.c  */
+/* Line 1680 of yacc.c  */
 #line 632 "parse-gram.y"
 
 
