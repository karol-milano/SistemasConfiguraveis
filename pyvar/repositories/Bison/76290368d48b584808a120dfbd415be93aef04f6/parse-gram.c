@@ -668,16 +668,16 @@ static const yytype_int8 yyrhs[] =
 /* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
 static const yytype_uint16 yyrline[] =
 {
-       0,   210,   210,   218,   220,   224,   225,   226,   227,   228,
-     229,   230,   231,   232,   233,   238,   242,   243,   244,   245,
-     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
-     256,   260,   261,   262,   266,   274,   282,   286,   290,   291,
-     292,   293,   304,   305,   309,   337,   337,   342,   342,   347,
-     358,   373,   374,   375,   379,   380,   385,   387,   392,   393,
-     397,   398,   399,   400,   405,   410,   415,   421,   427,   438,
-     439,   448,   449,   455,   456,   457,   464,   464,   468,   469,
-     470,   475,   476,   478,   480,   482,   484,   494,   495,   501,
-     505,   510,   526,   528,   537,   542,   543,   548,   555,   557
+       0,   210,   210,   218,   220,   224,   225,   233,   234,   235,
+     236,   237,   238,   239,   240,   245,   254,   255,   256,   257,
+     258,   259,   260,   261,   262,   263,   264,   265,   266,   267,
+     268,   272,   273,   274,   278,   285,   292,   296,   300,   301,
+     302,   303,   314,   315,   319,   348,   348,   353,   353,   358,
+     369,   384,   385,   386,   390,   391,   396,   398,   403,   404,
+     408,   409,   410,   411,   416,   421,   426,   432,   438,   449,
+     450,   459,   460,   466,   467,   468,   475,   475,   479,   480,
+     481,   486,   487,   489,   491,   493,   495,   505,   506,   512,
+     516,   521,   541,   543,   552,   557,   558,   563,   570,   572
 };
 #endif
 
@@ -1887,62 +1887,69 @@ yyreduce:
 
 /* Line 1269 of yacc.c  */
 #line 225 "parse-gram.y"
-    { prologue_augment (translate_code ((yyvsp[(1) - (1)].chars), (yylsp[(1) - (1)])), (yylsp[(1) - (1)]), union_seen); }
+    {
+   code_props plain_code;
+   code_props_plain_init (&plain_code, (yyvsp[(1) - (1)].chars), (yylsp[(1) - (1)]));
+   code_props_translate_code (&plain_code);
+   gram_scanner_last_string_free ();
+   prologue_augment (code_props_code_get (plain_code), (yylsp[(1) - (1)]), union_seen);
+   code_scanner_last_string_free ();
+}
     break;
 
   case 7:
 
 /* Line 1269 of yacc.c  */
-#line 226 "parse-gram.y"
+#line 233 "parse-gram.y"
     { debug_flag = true; }
     break;
 
   case 8:
 
 /* Line 1269 of yacc.c  */
-#line 227 "parse-gram.y"
+#line 234 "parse-gram.y"
     { muscle_insert ((yyvsp[(2) - (3)].chars), (yyvsp[(3) - (3)].chars)); }
     break;
 
   case 9:
 
 /* Line 1269 of yacc.c  */
-#line 228 "parse-gram.y"
+#line 235 "parse-gram.y"
     { defines_flag = true; }
     break;
 
   case 10:
 
 /* Line 1269 of yacc.c  */
-#line 229 "parse-gram.y"
+#line 236 "parse-gram.y"
     { error_verbose = true; }
     break;
 
   case 11:
 
 /* Line 1269 of yacc.c  */
-#line 230 "parse-gram.y"
+#line 237 "parse-gram.y"
     { expected_sr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 12:
 
 /* Line 1269 of yacc.c  */
-#line 231 "parse-gram.y"
+#line 238 "parse-gram.y"
     { expected_rr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 13:
 
 /* Line 1269 of yacc.c  */
-#line 232 "parse-gram.y"
+#line 239 "parse-gram.y"
     { spec_file_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 14:
 
 /* Line 1269 of yacc.c  */
-#line 234 "parse-gram.y"
+#line 241 "parse-gram.y"
     {
       nondeterministic_parser = true;
       glr_parser = true;
@@ -1952,114 +1959,119 @@ yyreduce:
   case 15:
 
 /* Line 1269 of yacc.c  */
-#line 239 "parse-gram.y"
+#line 246 "parse-gram.y"
     {
-      muscle_code_grow ("initial_action", translate_symbol_action ((yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])), (yylsp[(2) - (2)]));
+      code_props action;
+      code_props_symbol_action_init (&action, (yyvsp[(2) - (2)].code), (yylsp[(2) - (2)]));
+      code_props_translate_code (&action);
+      gram_scanner_last_string_free ();
+      muscle_code_grow ("initial_action", code_props_code_get (action), (yylsp[(2) - (2)]));
+      code_scanner_last_string_free ();
     }
     break;
 
   case 16:
 
 /* Line 1269 of yacc.c  */
-#line 242 "parse-gram.y"
+#line 254 "parse-gram.y"
     { add_param ("lex_param", (yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
     break;
 
   case 17:
 
 /* Line 1269 of yacc.c  */
-#line 243 "parse-gram.y"
+#line 255 "parse-gram.y"
     { locations_flag = true; }
     break;
 
   case 18:
 
 /* Line 1269 of yacc.c  */
-#line 244 "parse-gram.y"
+#line 256 "parse-gram.y"
     { spec_name_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 19:
 
 /* Line 1269 of yacc.c  */
-#line 245 "parse-gram.y"
+#line 257 "parse-gram.y"
     { no_lines_flag = true; }
     break;
 
   case 20:
 
 /* Line 1269 of yacc.c  */
-#line 246 "parse-gram.y"
+#line 258 "parse-gram.y"
     { nondeterministic_parser = true; }
     break;
 
   case 21:
 
 /* Line 1269 of yacc.c  */
-#line 247 "parse-gram.y"
+#line 259 "parse-gram.y"
     { spec_outfile = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 22:
 
 /* Line 1269 of yacc.c  */
-#line 248 "parse-gram.y"
+#line 260 "parse-gram.y"
     { add_param ("parse_param", (yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
     break;
 
   case 23:
 
 /* Line 1269 of yacc.c  */
-#line 249 "parse-gram.y"
+#line 261 "parse-gram.y"
     { pure_parser = true; }
     break;
 
   case 24:
 
 /* Line 1269 of yacc.c  */
-#line 250 "parse-gram.y"
+#line 262 "parse-gram.y"
     { push_parser = true; }
     break;
 
   case 25:
 
 /* Line 1269 of yacc.c  */
-#line 251 "parse-gram.y"
+#line 263 "parse-gram.y"
     { version_check (&(yylsp[(2) - (2)]), (yyvsp[(2) - (2)].chars)); }
     break;
 
   case 26:
 
 /* Line 1269 of yacc.c  */
-#line 252 "parse-gram.y"
+#line 264 "parse-gram.y"
     { skeleton = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 27:
 
 /* Line 1269 of yacc.c  */
-#line 253 "parse-gram.y"
+#line 265 "parse-gram.y"
     { token_table_flag = true; }
     break;
 
   case 28:
 
 /* Line 1269 of yacc.c  */
-#line 254 "parse-gram.y"
+#line 266 "parse-gram.y"
     { report_flag = report_states; }
     break;
 
   case 29:
 
 /* Line 1269 of yacc.c  */
-#line 255 "parse-gram.y"
+#line 267 "parse-gram.y"
     { yacc_flag = true; }
     break;
 
   case 33:
 
 /* Line 1269 of yacc.c  */
-#line 263 "parse-gram.y"
+#line 275 "parse-gram.y"
     {
       grammar_start_symbol_set ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]));
     }
@@ -2068,12 +2080,11 @@ yyreduce:
   case 34:
 
 /* Line 1269 of yacc.c  */
-#line 267 "parse-gram.y"
+#line 279 "parse-gram.y"
     {
       symbol_list *list;
-      const char *action = translate_symbol_action ((yyvsp[(2) - (3)].code), (yylsp[(2) - (3)]));
       for (list = (yyvsp[(3) - (3)].list); list; list = list->next)
-	symbol_list_destructor_set (list, action, (yylsp[(2) - (3)]));
+	symbol_list_destructor_set (list, (yyvsp[(2) - (3)].code), (yylsp[(2) - (3)]));
       symbol_list_free ((yyvsp[(3) - (3)].list));
     }
     break;
@@ -2081,12 +2092,11 @@ yyreduce:
   case 35:
 
 /* Line 1269 of yacc.c  */
-#line 275 "parse-gram.y"
+#line 286 "parse-gram.y"
     {
       symbol_list *list;
-      const char *action = translate_symbol_action ((yyvsp[(2) - (3)].code), (yylsp[(2) - (3)]));
       for (list = (yyvsp[(3) - (3)].list); list; list = list->next)
-	symbol_list_printer_set (list, action, (yylsp[(2) - (3)]));
+	symbol_list_printer_set (list, (yyvsp[(2) - (3)].code), (yylsp[(2) - (3)]));
       symbol_list_free ((yyvsp[(3) - (3)].list));
     }
     break;
@@ -2094,7 +2104,7 @@ yyreduce:
   case 36:
 
 /* Line 1269 of yacc.c  */
-#line 283 "parse-gram.y"
+#line 293 "parse-gram.y"
     {
       default_prec = true;
     }
@@ -2103,7 +2113,7 @@ yyreduce:
   case 37:
 
 /* Line 1269 of yacc.c  */
-#line 287 "parse-gram.y"
+#line 297 "parse-gram.y"
     {
       default_prec = false;
     }
@@ -2112,49 +2122,49 @@ yyreduce:
   case 38:
 
 /* Line 1269 of yacc.c  */
-#line 290 "parse-gram.y"
+#line 300 "parse-gram.y"
     { prologue_augment ((yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)]), true); }
     break;
 
   case 39:
 
 /* Line 1269 of yacc.c  */
-#line 291 "parse-gram.y"
+#line 301 "parse-gram.y"
     { prologue_augment ((yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)]), false); }
     break;
 
   case 40:
 
 /* Line 1269 of yacc.c  */
-#line 292 "parse-gram.y"
+#line 302 "parse-gram.y"
     { muscle_code_grow ("provides", (yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])); }
     break;
 
   case 41:
 
 /* Line 1269 of yacc.c  */
-#line 293 "parse-gram.y"
+#line 303 "parse-gram.y"
     { muscle_code_grow ("requires", (yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])); }
     break;
 
   case 42:
 
 /* Line 1269 of yacc.c  */
-#line 304 "parse-gram.y"
+#line 314 "parse-gram.y"
     {}
     break;
 
   case 43:
 
 /* Line 1269 of yacc.c  */
-#line 305 "parse-gram.y"
+#line 315 "parse-gram.y"
     { muscle_code_grow ("union_name", (yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 44:
 
 /* Line 1269 of yacc.c  */
-#line 310 "parse-gram.y"
+#line 320 "parse-gram.y"
     {
       char const *body = (yyvsp[(3) - (3)].code);
 
@@ -2175,20 +2185,21 @@ yyreduce:
 
       union_seen = true;
       muscle_code_grow ("stype", body, (yylsp[(3) - (3)]));
+      gram_scanner_last_string_free ();
     }
     break;
 
   case 45:
 
 /* Line 1269 of yacc.c  */
-#line 337 "parse-gram.y"
+#line 348 "parse-gram.y"
     { current_class = nterm_sym; }
     break;
 
   case 46:
 
 /* Line 1269 of yacc.c  */
-#line 338 "parse-gram.y"
+#line 349 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
@@ -2198,14 +2209,14 @@ yyreduce:
   case 47:
 
 /* Line 1269 of yacc.c  */
-#line 342 "parse-gram.y"
+#line 353 "parse-gram.y"
     { current_class = token_sym; }
     break;
 
   case 48:
 
 /* Line 1269 of yacc.c  */
-#line 343 "parse-gram.y"
+#line 354 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
@@ -2215,7 +2226,7 @@ yyreduce:
   case 49:
 
 /* Line 1269 of yacc.c  */
-#line 348 "parse-gram.y"
+#line 359 "parse-gram.y"
     {
       symbol_list *list;
       tag_seen = true;
@@ -2228,7 +2239,7 @@ yyreduce:
   case 50:
 
 /* Line 1269 of yacc.c  */
-#line 359 "parse-gram.y"
+#line 370 "parse-gram.y"
     {
       symbol_list *list;
       ++current_prec;
@@ -2245,98 +2256,98 @@ yyreduce:
   case 51:
 
 /* Line 1269 of yacc.c  */
-#line 373 "parse-gram.y"
+#line 384 "parse-gram.y"
     { (yyval.assoc) = left_assoc; }
     break;
 
   case 52:
 
 /* Line 1269 of yacc.c  */
-#line 374 "parse-gram.y"
+#line 385 "parse-gram.y"
     { (yyval.assoc) = right_assoc; }
     break;
 
   case 53:
 
 /* Line 1269 of yacc.c  */
-#line 375 "parse-gram.y"
+#line 386 "parse-gram.y"
     { (yyval.assoc) = non_assoc; }
     break;
 
   case 54:
 
 /* Line 1269 of yacc.c  */
-#line 379 "parse-gram.y"
+#line 390 "parse-gram.y"
     { current_type = NULL; }
     break;
 
   case 55:
 
 /* Line 1269 of yacc.c  */
-#line 380 "parse-gram.y"
+#line 391 "parse-gram.y"
     { current_type = (yyvsp[(1) - (1)].uniqstr); tag_seen = true; }
     break;
 
   case 56:
 
 /* Line 1269 of yacc.c  */
-#line 386 "parse-gram.y"
+#line 397 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 57:
 
 /* Line 1269 of yacc.c  */
-#line 388 "parse-gram.y"
+#line 399 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), symbol_list_sym_new ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]))); }
     break;
 
   case 58:
 
 /* Line 1269 of yacc.c  */
-#line 392 "parse-gram.y"
+#line 403 "parse-gram.y"
     { (yyval.list) = (yyvsp[(1) - (1)].list); }
     break;
 
   case 59:
 
 /* Line 1269 of yacc.c  */
-#line 393 "parse-gram.y"
+#line 404 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), (yyvsp[(2) - (2)].list)); }
     break;
 
   case 60:
 
 /* Line 1269 of yacc.c  */
-#line 397 "parse-gram.y"
+#line 408 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 61:
 
 /* Line 1269 of yacc.c  */
-#line 398 "parse-gram.y"
+#line 409 "parse-gram.y"
     { (yyval.list) = symbol_list_type_new ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 62:
 
 /* Line 1269 of yacc.c  */
-#line 399 "parse-gram.y"
+#line 410 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagged_new ((yylsp[(1) - (1)])); }
     break;
 
   case 63:
 
 /* Line 1269 of yacc.c  */
-#line 400 "parse-gram.y"
+#line 411 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagless_new ((yylsp[(1) - (1)])); }
     break;
 
   case 64:
 
 /* Line 1269 of yacc.c  */
-#line 406 "parse-gram.y"
+#line 417 "parse-gram.y"
     {
        current_type = (yyvsp[(1) - (1)].uniqstr);
        tag_seen = true;
@@ -2346,7 +2357,7 @@ yyreduce:
   case 65:
 
 /* Line 1269 of yacc.c  */
-#line 411 "parse-gram.y"
+#line 422 "parse-gram.y"
     {
        symbol_class_set ((yyvsp[(1) - (1)].symbol), current_class, (yylsp[(1) - (1)]), true);
        symbol_type_set ((yyvsp[(1) - (1)].symbol), current_type, (yylsp[(1) - (1)]));
@@ -2356,7 +2367,7 @@ yyreduce:
   case 66:
 
 /* Line 1269 of yacc.c  */
-#line 416 "parse-gram.y"
+#line 427 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
       symbol_type_set ((yyvsp[(1) - (2)].symbol), current_type, (yylsp[(1) - (2)]));
@@ -2367,7 +2378,7 @@ yyreduce:
   case 67:
 
 /* Line 1269 of yacc.c  */
-#line 422 "parse-gram.y"
+#line 433 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
       symbol_type_set ((yyvsp[(1) - (2)].symbol), current_type, (yylsp[(1) - (2)]));
@@ -2378,7 +2389,7 @@ yyreduce:
   case 68:
 
 /* Line 1269 of yacc.c  */
-#line 428 "parse-gram.y"
+#line 439 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (3)].symbol), current_class, (yylsp[(1) - (3)]), true);
       symbol_type_set ((yyvsp[(1) - (3)].symbol), current_type, (yylsp[(1) - (3)]));
@@ -2390,7 +2401,7 @@ yyreduce:
   case 75:
 
 /* Line 1269 of yacc.c  */
-#line 458 "parse-gram.y"
+#line 469 "parse-gram.y"
     {
       yyerrok;
     }
@@ -2399,70 +2410,70 @@ yyreduce:
   case 76:
 
 /* Line 1269 of yacc.c  */
-#line 464 "parse-gram.y"
+#line 475 "parse-gram.y"
     { current_lhs = (yyvsp[(1) - (1)].symbol); current_lhs_location = (yylsp[(1) - (1)]); }
     break;
 
   case 78:
 
 /* Line 1269 of yacc.c  */
-#line 468 "parse-gram.y"
+#line 479 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(1) - (1)])); }
     break;
 
   case 79:
 
 /* Line 1269 of yacc.c  */
-#line 469 "parse-gram.y"
+#line 480 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(3) - (3)])); }
     break;
 
   case 81:
 
 /* Line 1269 of yacc.c  */
-#line 475 "parse-gram.y"
+#line 486 "parse-gram.y"
     { grammar_current_rule_begin (current_lhs, current_lhs_location); }
     break;
 
   case 82:
 
 /* Line 1269 of yacc.c  */
-#line 477 "parse-gram.y"
+#line 488 "parse-gram.y"
     { grammar_current_rule_symbol_append ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)])); }
     break;
 
   case 83:
 
 /* Line 1269 of yacc.c  */
-#line 479 "parse-gram.y"
+#line 490 "parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
     break;
 
   case 84:
 
 /* Line 1269 of yacc.c  */
-#line 481 "parse-gram.y"
+#line 492 "parse-gram.y"
     { grammar_current_rule_prec_set ((yyvsp[(3) - (3)].symbol), (yylsp[(3) - (3)])); }
     break;
 
   case 85:
 
 /* Line 1269 of yacc.c  */
-#line 483 "parse-gram.y"
+#line 494 "parse-gram.y"
     { grammar_current_rule_dprec_set ((yyvsp[(3) - (3)].integer), (yylsp[(3) - (3)])); }
     break;
 
   case 86:
 
 /* Line 1269 of yacc.c  */
-#line 485 "parse-gram.y"
+#line 496 "parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[(3) - (3)].uniqstr), (yylsp[(3) - (3)])); }
     break;
 
   case 89:
 
 /* Line 1269 of yacc.c  */
-#line 501 "parse-gram.y"
+#line 512 "parse-gram.y"
     {
       static char one[] = "1";
       (yyval.chars) = one;
@@ -2472,24 +2483,28 @@ yyreduce:
   case 91:
 
 /* Line 1269 of yacc.c  */
-#line 511 "parse-gram.y"
+#line 522 "parse-gram.y"
     {
+      code_props plain_code;
       (yyvsp[(1) - (1)].code)[strlen ((yyvsp[(1) - (1)].code)) - 1] = '\n';
-      (yyval.chars) = translate_code ((yyvsp[(1) - (1)].code) + 1, (yylsp[(1) - (1)]));
+      code_props_plain_init (&plain_code, (yyvsp[(1) - (1)].code)+1, (yylsp[(1) - (1)]));
+      code_props_translate_code (&plain_code);
+      gram_scanner_last_string_free ();
+      (yyval.chars) = code_props_code_get (plain_code);
     }
     break;
 
   case 92:
 
 /* Line 1269 of yacc.c  */
-#line 527 "parse-gram.y"
+#line 542 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 93:
 
 /* Line 1269 of yacc.c  */
-#line 529 "parse-gram.y"
+#line 544 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[(1) - (1)].character)), (yylsp[(1) - (1)]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[(1) - (1)]), false);
@@ -2500,14 +2515,14 @@ yyreduce:
   case 94:
 
 /* Line 1269 of yacc.c  */
-#line 537 "parse-gram.y"
+#line 552 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 97:
 
 /* Line 1269 of yacc.c  */
-#line 549 "parse-gram.y"
+#line 564 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[(1) - (1)].chars)), (yylsp[(1) - (1)]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[(1) - (1)]), false);
@@ -2517,17 +2532,21 @@ yyreduce:
   case 99:
 
 /* Line 1269 of yacc.c  */
-#line 558 "parse-gram.y"
+#line 573 "parse-gram.y"
     {
-      muscle_code_grow ("epilogue", translate_code ((yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])), (yylsp[(2) - (2)]));
+      code_props plain_code;
+      code_props_plain_init (&plain_code, (yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)]));
+      code_props_translate_code (&plain_code);
       gram_scanner_last_string_free ();
+      muscle_code_grow ("epilogue", code_props_code_get (plain_code), (yylsp[(2) - (2)]));
+      code_scanner_last_string_free ();
     }
     break;
 
 
 
 /* Line 1269 of yacc.c  */
-#line 2531 "parse-gram.c"
+#line 2550 "parse-gram.c"
       default: break;
     }
   YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);
@@ -2746,7 +2765,7 @@ yyreturn:
 
 
 /* Line 1486 of yacc.c  */
-#line 564 "parse-gram.y"
+#line 583 "parse-gram.y"
 
 
 
