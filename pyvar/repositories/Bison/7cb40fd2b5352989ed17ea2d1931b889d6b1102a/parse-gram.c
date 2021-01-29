@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 2.5.1.899-007c5.  */
+/* A Bison parser, made by GNU Bison 2.5.1.931-4323e-dirty.  */
 
 /* Bison implementation for Yacc-like parsers in C
 
@@ -44,7 +44,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "2.5.1.899-007c5"
+#define YYBISON_VERSION "2.5.1.931-4323e-dirty"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -318,7 +318,7 @@ typedef union YYSTYPE
   param_type param;
 
 /* Line 351 of yacc.c  */
-#line 420 "src/parse-gram.y"
+#line 425 "src/parse-gram.y"
 code_props_type code_type;
 
 /* Line 351 of yacc.c  */
@@ -673,15 +673,15 @@ static const yytype_uint16 yyrline[] =
        0,   271,   271,   279,   281,   285,   286,   296,   300,   305,
      306,   311,   316,   317,   318,   319,   320,   325,   334,   335,
      336,   337,   338,   339,   340,   341,   341,   342,   343,   367,
-     368,   369,   370,   374,   375,   384,   385,   386,   390,   397,
-     401,   405,   412,   423,   424,   434,   435,   439,   451,   451,
-     456,   456,   461,   472,   487,   488,   489,   490,   494,   495,
-     500,   502,   507,   508,   513,   515,   520,   521,   525,   526,
-     530,   531,   532,   537,   542,   547,   553,   559,   570,   571,
-     580,   581,   587,   588,   589,   596,   596,   604,   605,   606,
-     611,   613,   615,   617,   619,   621,   623,   628,   630,   640,
-     641,   646,   647,   648,   657,   677,   679,   688,   693,   694,
-     699,   706,   708
+     368,   369,   370,   374,   375,   384,   385,   386,   390,   402,
+     406,   410,   417,   428,   429,   439,   440,   444,   456,   456,
+     461,   461,   466,   477,   492,   493,   494,   495,   499,   500,
+     505,   507,   512,   513,   518,   520,   525,   526,   530,   531,
+     535,   536,   537,   542,   547,   552,   558,   564,   575,   576,
+     585,   586,   592,   593,   594,   601,   601,   609,   610,   611,
+     616,   618,   620,   622,   624,   626,   628,   633,   635,   645,
+     646,   651,   652,   653,   662,   682,   684,   693,   698,   699,
+     704,   711,   713
 };
 #endif
 
@@ -1150,7 +1150,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 
             case 64: // code_props_type
 /* Line 725 of yacc.c  */
-#line 421 "src/parse-gram.y"
+#line 426 "src/parse-gram.y"
         { fprintf (yyo, "%s", code_props_type_string (((*yyvaluep).code_type))); }
 /* Line 725 of yacc.c  */
 #line 1157 "src/parse-gram.c"
@@ -2009,7 +2009,6 @@ YYLTYPE yylloc;
 /* Line 1486 of yacc.c  */
 #line 2011 "src/parse-gram.c"
   yylsp[0] = yylloc;
-
   goto yysetstate;
 
 /*------------------------------------------------------------.
@@ -2200,7 +2199,7 @@ yyreduce:
     switch (yyn)
       {
           case 6:
-/* Line 1702 of yacc.c  */
+/* Line 1701 of yacc.c  */
 #line 287 "src/parse-gram.y"
     {
       code_props plain_code;
@@ -2211,106 +2210,106 @@ yyreduce:
                         plain_code.code, (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1702 of yacc.c  */
-#line 2216 "src/parse-gram.c"
+/* Line 1701 of yacc.c  */
+#line 2215 "src/parse-gram.c"
     break;
 
   case 7:
-/* Line 1702 of yacc.c  */
+/* Line 1701 of yacc.c  */
 #line 297 "src/parse-gram.y"
     {
       muscle_percent_define_ensure ((yyvsp[0].uniqstr), (yylsp[0]), true);
     }
-/* Line 1702 of yacc.c  */
-#line 2226 "src/parse-gram.c"
+/* Line 1701 of yacc.c  */
+#line 2225 "src/parse-gram.c"
     break;
 
   case 8:
-/* Line 1702 of yacc.c  */
+/* Line 1701 of yacc.c  */
 #line 301 "src/parse-gram.y"
     {
       muscle_percent_define_insert ((yyvsp[-1].uniqstr), (yylsp[-1]), (yyvsp[0].chars),
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
     }
-/* Line 1702 of yacc.c  */
-#line 2237 "src/parse-gram.c"
+/* Line 1701 of yacc.c  */
+#line 2236 "src/parse-gram.c"
     break;
 
   case 9:
-/* Line 1702 of yacc.c  */
+/* Line 1701 of yacc.c  */
 #line 305 "src/parse-gram.y"
     { defines_flag = true; }
-/* Line 1702 of yacc.c  */
-#line 2245 "src/parse-gram.c"
+/* Line 1701 of yacc.c  */
+#line 2244 "src/parse-gram.c"
     break;
 
   case 10:
-/* Line 1702 of yacc.c  */
+/* Line 1701 of yacc.c  */
 #line 307 "src/parse-gram.y"
     {
       defines_flag = true;
       spec_defines_file = xstrdup ((yyvsp[0].chars));
     }
-/* Line 1702 of yacc.c  */
-#line 2256 "src/parse-gram.c"
+/* Line 1701 of yacc.c  */
+#line 2255 "src/parse-gram.c"
     break;
 
   case 11:
-/* Line 1702 of yacc.c  */
+/* Line 1701 of yacc.c  */
 #line 312 "src/parse-gram.y"
     {
       muscle_percent_define_insert ("parse.error", (yylsp[0]), "verbose",
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
     }
-/* Line 1702 of yacc.c  */
-#line 2267 "src/parse-gram.c"
+/* Line 1701 of yacc.c  */
+#line 2266 "src/parse-gram.c"
     break;
 
   case 12:
-/* Line 1702 of yacc.c  */
+/* Line 1701 of yacc.c  */
 #line 316 "src/parse-gram.y"
     { expected_sr_conflicts = (yyvsp[0].integer); }
-/* Line 1702 of yacc.c  */
-#line 2275 "src/parse-gram.c"
+/* Line 1701 of yacc.c  */
+#line 2274 "src/parse-gram.c"
     break;
 
   case 13:
-/* Line 1702 of yacc.c  */
+/* Line 1701 of yacc.c  */
 #line 317 "src/parse-gram.y"
     { expected_rr_conflicts = (yyvsp[0].integer); }
-/* Line 1702 of yacc.c  */
-#line 2283 "src/parse-gram.c"
+/* Line 1701 of yacc.c  */
+#line 2282 "src/parse-gram.c"
     break;
 
   case 14:
-/* Line 1702 of yacc.c  */
+/* Line 1701 of yacc.c  */
 #line 318 "src/parse-gram.y"
     { spec_file_prefix = (yyvsp[0].chars); }
-/* Line 1702 of yacc.c  */
-#line 2291 "src/parse-gram.c"
+/* Line 1701 of yacc.c  */
+#line 2290 "src/parse-gram.c"
     break;
 
   case 15:
-/* Line 1702 of yacc.c  */
+/* Line 1701 of yacc.c  */
 #line 319 "src/parse-gram.y"
     { spec_file_prefix = (yyvsp[0].chars); }
-/* Line 1702 of yacc.c  */
-#line 2299 "src/parse-gram.c"
+/* Line 1701 of yacc.c  */
+#line 2298 "src/parse-gram.c"
     break;
 
   case 16:
-/* Line 1702 of yacc.c  */
+/* Line 1701 of yacc.c  */
 #line 321 "src/parse-gram.y"
     {
       nondeterministic_parser = true;
       glr_parser = true;
     }
-/* Line 1702 of yacc.c  */
-#line 2310 "src/parse-gram.c"
+/* Line 1701 of yacc.c  */
+#line 2309 "src/parse-gram.c"
     break;
 
   case 17:
-/* Line 1702 of yacc.c  */
+/* Line 1701 of yacc.c  */
 #line 326 "src/parse-gram.y"
     {
       code_props action;
@@ -2320,92 +2319,92 @@ yyreduce:
       muscle_code_grow ("initial_action", action.code, (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1702 of yacc.c  */
-#line 2325 "src/parse-gram.c"
+/* Line 1701 of yacc.c  */
+#line 2324 "src/parse-gram.c"
     break;
 
   case 18:
-/* Line 1702 of yacc.c  */
+/* Line 1701 of yacc.c  */
 #line 334 "src/parse-gram.y"
     { language_argmatch ((yyvsp[0].chars), grammar_prio, (yylsp[-1])); }
-/* Line 1702 of yacc.c  */
-#line 2333 "src/parse-gram.c"
+/* Line 1701 of yacc.c  */
+#line 2332 "src/parse-gram.c"
     break;
 
   case 19:
-/* Line 1702 of yacc.c  */
+/* Line 1701 of yacc.c  */
 #line 335 "src/parse-gram.y"
     { spec_name_prefix = (yyvsp[0].chars); }
-/* Line 1702 of yacc.c  */
-#line 2341 "src/parse-gram.c"
+/* Line 1701 of yacc.c  */
+#line 2340 "src/parse-gram.c"
     break;
 
   case 20:
-/* Line 1702 of yacc.c  */
+/* Line 1701 of yacc.c  */
 #line 336 "src/parse-gram.y"
     { spec_name_prefix = (yyvsp[0].chars); }
-/* Line 1702 of yacc.c  */
-#line 2349 "src/parse-gram.c"
+/* Line 1701 of yacc.c  */
+#line 2348 "src/parse-gram.c"
     break;
 
   case 21:
-/* Line 1702 of yacc.c  */
+/* Line 1701 of yacc.c  */
 #line 337 "src/parse-gram.y"
     { no_lines_flag = true; }
-/* Line 1702 of yacc.c  */
-#line 2357 "src/parse-gram.c"
+/* Line 1701 of yacc.c  */
+#line 2356 "src/parse-gram.c"
     break;
 
   case 22:
-/* Line 1702 of yacc.c  */
+/* Line 1701 of yacc.c  */
 #line 338 "src/parse-gram.y"
     { nondeterministic_parser = true; }
-/* Line 1702 of yacc.c  */
-#line 2365 "src/parse-gram.c"
+/* Line 1701 of yacc.c  */
+#line 2364 "src/parse-gram.c"
     break;
 
   case 23:
-/* Line 1702 of yacc.c  */
+/* Line 1701 of yacc.c  */
 #line 339 "src/parse-gram.y"
     { spec_outfile = (yyvsp[0].chars); }
-/* Line 1702 of yacc.c  */
-#line 2373 "src/parse-gram.c"
+/* Line 1701 of yacc.c  */
+#line 2372 "src/parse-gram.c"
     break;
 
   case 24:
-/* Line 1702 of yacc.c  */
+/* Line 1701 of yacc.c  */
 #line 340 "src/parse-gram.y"
     { spec_outfile = (yyvsp[0].chars); }
-/* Line 1702 of yacc.c  */
-#line 2381 "src/parse-gram.c"
+/* Line 1701 of yacc.c  */
+#line 2380 "src/parse-gram.c"
     break;
 
   case 25:
-/* Line 1702 of yacc.c  */
+/* Line 1701 of yacc.c  */
 #line 341 "src/parse-gram.y"
     { current_param = (yyvsp[0].param); }
-/* Line 1702 of yacc.c  */
-#line 2389 "src/parse-gram.c"
+/* Line 1701 of yacc.c  */
+#line 2388 "src/parse-gram.c"
     break;
 
   case 26:
-/* Line 1702 of yacc.c  */
+/* Line 1701 of yacc.c  */
 #line 341 "src/parse-gram.y"
     { current_param = param_none; }
-/* Line 1702 of yacc.c  */
-#line 2397 "src/parse-gram.c"
+/* Line 1701 of yacc.c  */
+#line 2396 "src/parse-gram.c"
     break;
 
   case 27:
-/* Line 1702 of yacc.c  */
+/* Line 1701 of yacc.c  */
 #line 342 "src/parse-gram.y"
     { version_check (&(yylsp[0]), (yyvsp[0].chars)); }
-/* Line 1702 of yacc.c  */
-#line 2405 "src/parse-gram.c"
+/* Line 1701 of yacc.c  */
+#line 2404 "src/parse-gram.c"
     break;
 
   case 28:
-/* Line 1702 of yacc.c  */
+/* Line 1701 of yacc.c  */
 #line 344 "src/parse-gram.y"
     {
       char const *skeleton_user = (yyvsp[0].chars);
@@ -2430,202 +2429,207 @@ yyreduce:
         }
       skeleton_arg (skeleton_user, grammar_prio, (yylsp[-1]));
     }
-/* Line 1702 of yacc.c  */
-#line 2435 "src/parse-gram.c"
+/* Line 1701 of yacc.c  */
+#line 2434 "src/parse-gram.c"
     break;
 
   case 29:
-/* Line 1702 of yacc.c  */
+/* Line 1701 of yacc.c  */
 #line 367 "src/parse-gram.y"
     { token_table_flag = true; }
-/* Line 1702 of yacc.c  */
-#line 2443 "src/parse-gram.c"
+/* Line 1701 of yacc.c  */
+#line 2442 "src/parse-gram.c"
     break;
 
   case 30:
-/* Line 1702 of yacc.c  */
+/* Line 1701 of yacc.c  */
 #line 368 "src/parse-gram.y"
     { report_flag |= report_states; }
-/* Line 1702 of yacc.c  */
-#line 2451 "src/parse-gram.c"
+/* Line 1701 of yacc.c  */
+#line 2450 "src/parse-gram.c"
     break;
 
   case 31:
-/* Line 1702 of yacc.c  */
+/* Line 1701 of yacc.c  */
 #line 369 "src/parse-gram.y"
     { yacc_flag = true; }
-/* Line 1702 of yacc.c  */
-#line 2459 "src/parse-gram.c"
+/* Line 1701 of yacc.c  */
+#line 2458 "src/parse-gram.c"
     break;
 
   case 33:
-/* Line 1702 of yacc.c  */
+/* Line 1701 of yacc.c  */
 #line 374 "src/parse-gram.y"
     { add_param (current_param, (yyvsp[0].code), (yylsp[0])); }
-/* Line 1702 of yacc.c  */
-#line 2467 "src/parse-gram.c"
+/* Line 1701 of yacc.c  */
+#line 2466 "src/parse-gram.c"
     break;
 
   case 34:
-/* Line 1702 of yacc.c  */
+/* Line 1701 of yacc.c  */
 #line 375 "src/parse-gram.y"
     { add_param (current_param, (yyvsp[0].code), (yylsp[0])); }
-/* Line 1702 of yacc.c  */
-#line 2475 "src/parse-gram.c"
+/* Line 1701 of yacc.c  */
+#line 2474 "src/parse-gram.c"
     break;
 
   case 37:
-/* Line 1702 of yacc.c  */
+/* Line 1701 of yacc.c  */
 #line 387 "src/parse-gram.y"
     {
       grammar_start_symbol_set ((yyvsp[0].symbol), (yylsp[0]));
     }
-/* Line 1702 of yacc.c  */
-#line 2485 "src/parse-gram.c"
+/* Line 1701 of yacc.c  */
+#line 2484 "src/parse-gram.c"
     break;
 
   case 38:
-/* Line 1702 of yacc.c  */
+/* Line 1701 of yacc.c  */
 #line 391 "src/parse-gram.y"
     {
-      symbol_list *list;
-      for (list = (yyvsp[0].list); list; list = list->next)
-        symbol_list_code_props_set (list, (yyvsp[-2].code_type), (yylsp[-1]), (yyvsp[-1].code));
-      symbol_list_free ((yyvsp[0].list));
+      code_props code;
+      code_props_symbol_action_init (&code, (yyvsp[-1].code), (yylsp[-1]));
+      code_props_translate_code (&code);
+      {
+        symbol_list *list;
+        for (list = (yyvsp[0].list); list; list = list->next)
+          symbol_list_code_props_set (list, (yyvsp[-2].code_type), &code);
+        symbol_list_free ((yyvsp[0].list));
+      }
     }
-/* Line 1702 of yacc.c  */
-#line 2498 "src/parse-gram.c"
+/* Line 1701 of yacc.c  */
+#line 2502 "src/parse-gram.c"
     break;
 
   case 39:
-/* Line 1702 of yacc.c  */
-#line 398 "src/parse-gram.y"
+/* Line 1701 of yacc.c  */
+#line 403 "src/parse-gram.y"
     {
       default_prec = true;
     }
-/* Line 1702 of yacc.c  */
-#line 2508 "src/parse-gram.c"
+/* Line 1701 of yacc.c  */
+#line 2512 "src/parse-gram.c"
     break;
 
   case 40:
-/* Line 1702 of yacc.c  */
-#line 402 "src/parse-gram.y"
+/* Line 1701 of yacc.c  */
+#line 407 "src/parse-gram.y"
     {
       default_prec = false;
     }
-/* Line 1702 of yacc.c  */
-#line 2518 "src/parse-gram.c"
+/* Line 1701 of yacc.c  */
+#line 2522 "src/parse-gram.c"
     break;
 
   case 41:
-/* Line 1702 of yacc.c  */
-#line 406 "src/parse-gram.y"
+/* Line 1701 of yacc.c  */
+#line 411 "src/parse-gram.y"
     {
       /* Do not invoke muscle_percent_code_grow here since it invokes
          muscle_user_name_list_grow.  */
       muscle_code_grow ("percent_code()", (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1702 of yacc.c  */
-#line 2531 "src/parse-gram.c"
+/* Line 1701 of yacc.c  */
+#line 2535 "src/parse-gram.c"
     break;
 
   case 42:
-/* Line 1702 of yacc.c  */
-#line 413 "src/parse-gram.y"
+/* Line 1701 of yacc.c  */
+#line 418 "src/parse-gram.y"
     {
       muscle_percent_code_grow ((yyvsp[-1].uniqstr), (yylsp[-1]), (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1702 of yacc.c  */
-#line 2542 "src/parse-gram.c"
+/* Line 1701 of yacc.c  */
+#line 2546 "src/parse-gram.c"
     break;
 
   case 43:
-/* Line 1702 of yacc.c  */
-#line 423 "src/parse-gram.y"
+/* Line 1701 of yacc.c  */
+#line 428 "src/parse-gram.y"
     { (yyval.code_type) = destructor; }
-/* Line 1702 of yacc.c  */
-#line 2550 "src/parse-gram.c"
+/* Line 1701 of yacc.c  */
+#line 2554 "src/parse-gram.c"
     break;
 
   case 44:
-/* Line 1702 of yacc.c  */
-#line 424 "src/parse-gram.y"
+/* Line 1701 of yacc.c  */
+#line 429 "src/parse-gram.y"
     { (yyval.code_type) = printer; }
-/* Line 1702 of yacc.c  */
-#line 2558 "src/parse-gram.c"
+/* Line 1701 of yacc.c  */
+#line 2562 "src/parse-gram.c"
     break;
 
   case 45:
-/* Line 1702 of yacc.c  */
-#line 434 "src/parse-gram.y"
+/* Line 1701 of yacc.c  */
+#line 439 "src/parse-gram.y"
     {}
-/* Line 1702 of yacc.c  */
-#line 2566 "src/parse-gram.c"
+/* Line 1701 of yacc.c  */
+#line 2570 "src/parse-gram.c"
     break;
 
   case 46:
-/* Line 1702 of yacc.c  */
-#line 435 "src/parse-gram.y"
+/* Line 1701 of yacc.c  */
+#line 440 "src/parse-gram.y"
     { muscle_code_grow ("union_name", (yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1702 of yacc.c  */
-#line 2574 "src/parse-gram.c"
+/* Line 1701 of yacc.c  */
+#line 2578 "src/parse-gram.c"
     break;
 
   case 47:
-/* Line 1702 of yacc.c  */
-#line 440 "src/parse-gram.y"
+/* Line 1701 of yacc.c  */
+#line 445 "src/parse-gram.y"
     {
       union_seen = true;
       muscle_code_grow ("stype", (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1702 of yacc.c  */
-#line 2586 "src/parse-gram.c"
+/* Line 1701 of yacc.c  */
+#line 2590 "src/parse-gram.c"
     break;
 
   case 48:
-/* Line 1702 of yacc.c  */
-#line 451 "src/parse-gram.y"
+/* Line 1701 of yacc.c  */
+#line 456 "src/parse-gram.y"
     { current_class = nterm_sym; }
-/* Line 1702 of yacc.c  */
-#line 2594 "src/parse-gram.c"
+/* Line 1701 of yacc.c  */
+#line 2598 "src/parse-gram.c"
     break;
 
   case 49:
-/* Line 1702 of yacc.c  */
-#line 452 "src/parse-gram.y"
+/* Line 1701 of yacc.c  */
+#line 457 "src/parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
-/* Line 1702 of yacc.c  */
-#line 2605 "src/parse-gram.c"
+/* Line 1701 of yacc.c  */
+#line 2609 "src/parse-gram.c"
     break;
 
   case 50:
-/* Line 1702 of yacc.c  */
-#line 456 "src/parse-gram.y"
+/* Line 1701 of yacc.c  */
+#line 461 "src/parse-gram.y"
     { current_class = token_sym; }
-/* Line 1702 of yacc.c  */
-#line 2613 "src/parse-gram.c"
+/* Line 1701 of yacc.c  */
+#line 2617 "src/parse-gram.c"
     break;
 
   case 51:
-/* Line 1702 of yacc.c  */
-#line 457 "src/parse-gram.y"
+/* Line 1701 of yacc.c  */
+#line 462 "src/parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
-/* Line 1702 of yacc.c  */
-#line 2624 "src/parse-gram.c"
+/* Line 1701 of yacc.c  */
+#line 2628 "src/parse-gram.c"
     break;
 
   case 52:
-/* Line 1702 of yacc.c  */
-#line 462 "src/parse-gram.y"
+/* Line 1701 of yacc.c  */
+#line 467 "src/parse-gram.y"
     {
       symbol_list *list;
       tag_seen = true;
@@ -2633,13 +2637,13 @@ yyreduce:
         symbol_type_set (list->content.sym, (yyvsp[-1].uniqstr), (yylsp[-1]));
       symbol_list_free ((yyvsp[0].list));
     }
-/* Line 1702 of yacc.c  */
-#line 2638 "src/parse-gram.c"
+/* Line 1701 of yacc.c  */
+#line 2642 "src/parse-gram.c"
     break;
 
   case 53:
-/* Line 1702 of yacc.c  */
-#line 473 "src/parse-gram.y"
+/* Line 1701 of yacc.c  */
+#line 478 "src/parse-gram.y"
     {
       symbol_list *list;
       ++current_prec;
@@ -2651,358 +2655,358 @@ yyreduce:
       symbol_list_free ((yyvsp[0].list));
       current_type = NULL;
     }
-/* Line 1702 of yacc.c  */
-#line 2656 "src/parse-gram.c"
+/* Line 1701 of yacc.c  */
+#line 2660 "src/parse-gram.c"
     break;
 
   case 54:
-/* Line 1702 of yacc.c  */
-#line 487 "src/parse-gram.y"
+/* Line 1701 of yacc.c  */
+#line 492 "src/parse-gram.y"
     { (yyval.assoc) = left_assoc; }
-/* Line 1702 of yacc.c  */
-#line 2664 "src/parse-gram.c"
+/* Line 1701 of yacc.c  */
+#line 2668 "src/parse-gram.c"
     break;
 
   case 55:
-/* Line 1702 of yacc.c  */
-#line 488 "src/parse-gram.y"
+/* Line 1701 of yacc.c  */
+#line 493 "src/parse-gram.y"
     { (yyval.assoc) = right_assoc; }
-/* Line 1702 of yacc.c  */
-#line 2672 "src/parse-gram.c"
+/* Line 1701 of yacc.c  */
+#line 2676 "src/parse-gram.c"
     break;
 
   case 56:
-/* Line 1702 of yacc.c  */
-#line 489 "src/parse-gram.y"
+/* Line 1701 of yacc.c  */
+#line 494 "src/parse-gram.y"
     { (yyval.assoc) = non_assoc; }
-/* Line 1702 of yacc.c  */
-#line 2680 "src/parse-gram.c"
+/* Line 1701 of yacc.c  */
+#line 2684 "src/parse-gram.c"
     break;
 
   case 57:
-/* Line 1702 of yacc.c  */
-#line 490 "src/parse-gram.y"
+/* Line 1701 of yacc.c  */
+#line 495 "src/parse-gram.y"
     { (yyval.assoc) = precedence_assoc; }
-/* Line 1702 of yacc.c  */
-#line 2688 "src/parse-gram.c"
+/* Line 1701 of yacc.c  */
+#line 2692 "src/parse-gram.c"
     break;
 
   case 58:
-/* Line 1702 of yacc.c  */
-#line 494 "src/parse-gram.y"
+/* Line 1701 of yacc.c  */
+#line 499 "src/parse-gram.y"
     { current_type = NULL; }
-/* Line 1702 of yacc.c  */
-#line 2696 "src/parse-gram.c"
+/* Line 1701 of yacc.c  */
+#line 2700 "src/parse-gram.c"
     break;
 
   case 59:
-/* Line 1702 of yacc.c  */
-#line 495 "src/parse-gram.y"
+/* Line 1701 of yacc.c  */
+#line 500 "src/parse-gram.y"
     { current_type = (yyvsp[0].uniqstr); tag_seen = true; }
-/* Line 1702 of yacc.c  */
-#line 2704 "src/parse-gram.c"
+/* Line 1701 of yacc.c  */
+#line 2708 "src/parse-gram.c"
     break;
 
   case 60:
-/* Line 1702 of yacc.c  */
-#line 501 "src/parse-gram.y"
+/* Line 1701 of yacc.c  */
+#line 506 "src/parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-/* Line 1702 of yacc.c  */
-#line 2712 "src/parse-gram.c"
+/* Line 1701 of yacc.c  */
+#line 2716 "src/parse-gram.c"
     break;
 
   case 61:
-/* Line 1702 of yacc.c  */
-#line 503 "src/parse-gram.y"
+/* Line 1701 of yacc.c  */
+#line 508 "src/parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
-/* Line 1702 of yacc.c  */
-#line 2720 "src/parse-gram.c"
+/* Line 1701 of yacc.c  */
+#line 2724 "src/parse-gram.c"
     break;
 
   case 62:
-/* Line 1702 of yacc.c  */
-#line 507 "src/parse-gram.y"
+/* Line 1701 of yacc.c  */
+#line 512 "src/parse-gram.y"
     { (yyval.symbol) = (yyvsp[0].symbol); }
-/* Line 1702 of yacc.c  */
-#line 2728 "src/parse-gram.c"
+/* Line 1701 of yacc.c  */
+#line 2732 "src/parse-gram.c"
     break;
 
   case 63:
-/* Line 1702 of yacc.c  */
-#line 508 "src/parse-gram.y"
+/* Line 1701 of yacc.c  */
+#line 513 "src/parse-gram.y"
     { (yyval.symbol) = (yyvsp[-1].symbol); symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0])); }
-/* Line 1702 of yacc.c  */
-#line 2736 "src/parse-gram.c"
+/* Line 1701 of yacc.c  */
+#line 2740 "src/parse-gram.c"
     break;
 
   case 64:
-/* Line 1702 of yacc.c  */
-#line 514 "src/parse-gram.y"
+/* Line 1701 of yacc.c  */
+#line 519 "src/parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-/* Line 1702 of yacc.c  */
-#line 2744 "src/parse-gram.c"
+/* Line 1701 of yacc.c  */
+#line 2748 "src/parse-gram.c"
     break;
 
   case 65:
-/* Line 1702 of yacc.c  */
-#line 516 "src/parse-gram.y"
+/* Line 1701 of yacc.c  */
+#line 521 "src/parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
-/* Line 1702 of yacc.c  */
-#line 2752 "src/parse-gram.c"
+/* Line 1701 of yacc.c  */
+#line 2756 "src/parse-gram.c"
     break;
 
   case 66:
-/* Line 1702 of yacc.c  */
-#line 520 "src/parse-gram.y"
+/* Line 1701 of yacc.c  */
+#line 525 "src/parse-gram.y"
     { (yyval.list) = (yyvsp[0].list); }
-/* Line 1702 of yacc.c  */
-#line 2760 "src/parse-gram.c"
+/* Line 1701 of yacc.c  */
+#line 2764 "src/parse-gram.c"
     break;
 
   case 67:
-/* Line 1702 of yacc.c  */
-#line 521 "src/parse-gram.y"
+/* Line 1701 of yacc.c  */
+#line 526 "src/parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), (yyvsp[0].list)); }
-/* Line 1702 of yacc.c  */
-#line 2768 "src/parse-gram.c"
+/* Line 1701 of yacc.c  */
+#line 2772 "src/parse-gram.c"
     break;
 
   case 68:
-/* Line 1702 of yacc.c  */
-#line 525 "src/parse-gram.y"
+/* Line 1701 of yacc.c  */
+#line 530 "src/parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-/* Line 1702 of yacc.c  */
-#line 2776 "src/parse-gram.c"
+/* Line 1701 of yacc.c  */
+#line 2780 "src/parse-gram.c"
     break;
 
   case 69:
-/* Line 1702 of yacc.c  */
-#line 526 "src/parse-gram.y"
+/* Line 1701 of yacc.c  */
+#line 531 "src/parse-gram.y"
     { (yyval.list) = symbol_list_type_new ((yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1702 of yacc.c  */
-#line 2784 "src/parse-gram.c"
+/* Line 1701 of yacc.c  */
+#line 2788 "src/parse-gram.c"
     break;
 
   case 71:
-/* Line 1702 of yacc.c  */
-#line 531 "src/parse-gram.y"
+/* Line 1701 of yacc.c  */
+#line 536 "src/parse-gram.y"
     { (yyval.uniqstr) = uniqstr_new ("*"); }
-/* Line 1702 of yacc.c  */
-#line 2792 "src/parse-gram.c"
+/* Line 1701 of yacc.c  */
+#line 2796 "src/parse-gram.c"
     break;
 
   case 72:
-/* Line 1702 of yacc.c  */
-#line 532 "src/parse-gram.y"
+/* Line 1701 of yacc.c  */
+#line 537 "src/parse-gram.y"
     { (yyval.uniqstr) = uniqstr_new (""); }
-/* Line 1702 of yacc.c  */
-#line 2800 "src/parse-gram.c"
+/* Line 1701 of yacc.c  */
+#line 2804 "src/parse-gram.c"
     break;
 
   case 73:
-/* Line 1702 of yacc.c  */
-#line 538 "src/parse-gram.y"
+/* Line 1701 of yacc.c  */
+#line 543 "src/parse-gram.y"
     {
        current_type = (yyvsp[0].uniqstr);
        tag_seen = true;
      }
-/* Line 1702 of yacc.c  */
-#line 2811 "src/parse-gram.c"
+/* Line 1701 of yacc.c  */
+#line 2815 "src/parse-gram.c"
     break;
 
   case 74:
-/* Line 1702 of yacc.c  */
-#line 543 "src/parse-gram.y"
+/* Line 1701 of yacc.c  */
+#line 548 "src/parse-gram.y"
     {
        symbol_class_set ((yyvsp[0].symbol), current_class, (yylsp[0]), true);
        symbol_type_set ((yyvsp[0].symbol), current_type, (yylsp[0]));
      }
-/* Line 1702 of yacc.c  */
-#line 2822 "src/parse-gram.c"
+/* Line 1701 of yacc.c  */
+#line 2826 "src/parse-gram.c"
     break;
 
   case 75:
-/* Line 1702 of yacc.c  */
-#line 548 "src/parse-gram.y"
+/* Line 1701 of yacc.c  */
+#line 553 "src/parse-gram.y"
     {
       symbol_class_set ((yyvsp[-1].symbol), current_class, (yylsp[-1]), true);
       symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
       symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0]));
     }
-/* Line 1702 of yacc.c  */
-#line 2834 "src/parse-gram.c"
+/* Line 1701 of yacc.c  */
+#line 2838 "src/parse-gram.c"
     break;
 
   case 76:
-/* Line 1702 of yacc.c  */
-#line 554 "src/parse-gram.y"
+/* Line 1701 of yacc.c  */
+#line 559 "src/parse-gram.y"
     {
       symbol_class_set ((yyvsp[-1].symbol), current_class, (yylsp[-1]), true);
       symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
       symbol_make_alias ((yyvsp[-1].symbol), (yyvsp[0].symbol), (yyloc));
     }
-/* Line 1702 of yacc.c  */
-#line 2846 "src/parse-gram.c"
+/* Line 1701 of yacc.c  */
+#line 2850 "src/parse-gram.c"
     break;
 
   case 77:
-/* Line 1702 of yacc.c  */
-#line 560 "src/parse-gram.y"
+/* Line 1701 of yacc.c  */
+#line 565 "src/parse-gram.y"
     {
       symbol_class_set ((yyvsp[-2].symbol), current_class, (yylsp[-2]), true);
       symbol_type_set ((yyvsp[-2].symbol), current_type, (yylsp[-2]));
       symbol_user_token_number_set ((yyvsp[-2].symbol), (yyvsp[-1].integer), (yylsp[-1]));
       symbol_make_alias ((yyvsp[-2].symbol), (yyvsp[0].symbol), (yyloc));
     }
-/* Line 1702 of yacc.c  */
-#line 2859 "src/parse-gram.c"
+/* Line 1701 of yacc.c  */
+#line 2863 "src/parse-gram.c"
     break;
 
   case 84:
-/* Line 1702 of yacc.c  */
-#line 590 "src/parse-gram.y"
+/* Line 1701 of yacc.c  */
+#line 595 "src/parse-gram.y"
     {
       yyerrok;
     }
-/* Line 1702 of yacc.c  */
-#line 2869 "src/parse-gram.c"
+/* Line 1701 of yacc.c  */
+#line 2873 "src/parse-gram.c"
     break;
 
   case 85:
-/* Line 1702 of yacc.c  */
-#line 596 "src/parse-gram.y"
+/* Line 1701 of yacc.c  */
+#line 601 "src/parse-gram.y"
     { current_lhs ((yyvsp[-1].symbol), (yylsp[-1]), (yyvsp[0].named_ref)); }
-/* Line 1702 of yacc.c  */
-#line 2877 "src/parse-gram.c"
+/* Line 1701 of yacc.c  */
+#line 2881 "src/parse-gram.c"
     break;
 
   case 86:
-/* Line 1702 of yacc.c  */
-#line 597 "src/parse-gram.y"
+/* Line 1701 of yacc.c  */
+#line 602 "src/parse-gram.y"
     {
     /* Free the current lhs. */
     current_lhs (0, (yylsp[-3]), 0);
   }
-/* Line 1702 of yacc.c  */
-#line 2888 "src/parse-gram.c"
+/* Line 1701 of yacc.c  */
+#line 2892 "src/parse-gram.c"
     break;
 
   case 87:
-/* Line 1702 of yacc.c  */
-#line 604 "src/parse-gram.y"
+/* Line 1701 of yacc.c  */
+#line 609 "src/parse-gram.y"
     { grammar_current_rule_end ((yylsp[0])); }
-/* Line 1702 of yacc.c  */
-#line 2896 "src/parse-gram.c"
+/* Line 1701 of yacc.c  */
+#line 2900 "src/parse-gram.c"
     break;
 
   case 88:
-/* Line 1702 of yacc.c  */
-#line 605 "src/parse-gram.y"
+/* Line 1701 of yacc.c  */
+#line 610 "src/parse-gram.y"
     { grammar_current_rule_end ((yylsp[0])); }
-/* Line 1702 of yacc.c  */
-#line 2904 "src/parse-gram.c"
+/* Line 1701 of yacc.c  */
+#line 2908 "src/parse-gram.c"
     break;
 
   case 90:
-/* Line 1702 of yacc.c  */
-#line 611 "src/parse-gram.y"
+/* Line 1701 of yacc.c  */
+#line 616 "src/parse-gram.y"
     { grammar_current_rule_begin (current_lhs_symbol, current_lhs_location,
                                   current_lhs_named_ref); }
-/* Line 1702 of yacc.c  */
-#line 2913 "src/parse-gram.c"
+/* Line 1701 of yacc.c  */
+#line 2917 "src/parse-gram.c"
     break;
 
   case 91:
-/* Line 1702 of yacc.c  */
-#line 614 "src/parse-gram.y"
+/* Line 1701 of yacc.c  */
+#line 619 "src/parse-gram.y"
     { grammar_current_rule_symbol_append ((yyvsp[-1].symbol), (yylsp[-1]), (yyvsp[0].named_ref)); }
-/* Line 1702 of yacc.c  */
-#line 2921 "src/parse-gram.c"
+/* Line 1701 of yacc.c  */
+#line 2925 "src/parse-gram.c"
     break;
 
   case 92:
-/* Line 1702 of yacc.c  */
-#line 616 "src/parse-gram.y"
+/* Line 1701 of yacc.c  */
+#line 621 "src/parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[-1].code), (yylsp[-1]), (yyvsp[0].named_ref), false); }
-/* Line 1702 of yacc.c  */
-#line 2929 "src/parse-gram.c"
+/* Line 1701 of yacc.c  */
+#line 2933 "src/parse-gram.c"
     break;
 
   case 93:
-/* Line 1702 of yacc.c  */
-#line 618 "src/parse-gram.y"
+/* Line 1701 of yacc.c  */
+#line 623 "src/parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[0].code), (yylsp[0]), NULL, true); }
-/* Line 1702 of yacc.c  */
-#line 2937 "src/parse-gram.c"
+/* Line 1701 of yacc.c  */
+#line 2941 "src/parse-gram.c"
     break;
 
   case 94:
-/* Line 1702 of yacc.c  */
-#line 620 "src/parse-gram.y"
+/* Line 1701 of yacc.c  */
+#line 625 "src/parse-gram.y"
     { grammar_current_rule_prec_set ((yyvsp[0].symbol), (yylsp[0])); }
-/* Line 1702 of yacc.c  */
-#line 2945 "src/parse-gram.c"
+/* Line 1701 of yacc.c  */
+#line 2949 "src/parse-gram.c"
     break;
 
   case 95:
-/* Line 1702 of yacc.c  */
-#line 622 "src/parse-gram.y"
+/* Line 1701 of yacc.c  */
+#line 627 "src/parse-gram.y"
     { grammar_current_rule_dprec_set ((yyvsp[0].integer), (yylsp[0])); }
-/* Line 1702 of yacc.c  */
-#line 2953 "src/parse-gram.c"
+/* Line 1701 of yacc.c  */
+#line 2957 "src/parse-gram.c"
     break;
 
   case 96:
-/* Line 1702 of yacc.c  */
-#line 624 "src/parse-gram.y"
+/* Line 1701 of yacc.c  */
+#line 629 "src/parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1702 of yacc.c  */
-#line 2961 "src/parse-gram.c"
+/* Line 1701 of yacc.c  */
+#line 2965 "src/parse-gram.c"
     break;
 
   case 97:
-/* Line 1702 of yacc.c  */
-#line 628 "src/parse-gram.y"
+/* Line 1701 of yacc.c  */
+#line 633 "src/parse-gram.y"
     { (yyval.named_ref) = 0; }
-/* Line 1702 of yacc.c  */
-#line 2969 "src/parse-gram.c"
+/* Line 1701 of yacc.c  */
+#line 2973 "src/parse-gram.c"
     break;
 
   case 98:
-/* Line 1702 of yacc.c  */
-#line 630 "src/parse-gram.y"
+/* Line 1701 of yacc.c  */
+#line 635 "src/parse-gram.y"
     { (yyval.named_ref) = named_ref_new((yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1702 of yacc.c  */
-#line 2977 "src/parse-gram.c"
+/* Line 1701 of yacc.c  */
+#line 2981 "src/parse-gram.c"
     break;
 
   case 100:
-/* Line 1702 of yacc.c  */
-#line 641 "src/parse-gram.y"
+/* Line 1701 of yacc.c  */
+#line 646 "src/parse-gram.y"
     { (yyval.uniqstr) = uniqstr_new ((yyvsp[0].chars)); }
-/* Line 1702 of yacc.c  */
-#line 2985 "src/parse-gram.c"
+/* Line 1701 of yacc.c  */
+#line 2989 "src/parse-gram.c"
     break;
 
   case 101:
-/* Line 1702 of yacc.c  */
-#line 646 "src/parse-gram.y"
+/* Line 1701 of yacc.c  */
+#line 651 "src/parse-gram.y"
     { (yyval.chars) = ""; }
-/* Line 1702 of yacc.c  */
-#line 2993 "src/parse-gram.c"
+/* Line 1701 of yacc.c  */
+#line 2997 "src/parse-gram.c"
     break;
 
   case 102:
-/* Line 1702 of yacc.c  */
-#line 647 "src/parse-gram.y"
+/* Line 1701 of yacc.c  */
+#line 652 "src/parse-gram.y"
     { (yyval.chars) = (yyvsp[0].uniqstr); }
-/* Line 1702 of yacc.c  */
-#line 3001 "src/parse-gram.c"
+/* Line 1701 of yacc.c  */
+#line 3005 "src/parse-gram.c"
     break;
 
   case 104:
-/* Line 1702 of yacc.c  */
-#line 658 "src/parse-gram.y"
+/* Line 1701 of yacc.c  */
+#line 663 "src/parse-gram.y"
     {
       code_props plain_code;
       (yyvsp[0].code)[strlen ((yyvsp[0].code)) - 1] = '\n';
@@ -3011,52 +3015,52 @@ yyreduce:
       gram_scanner_last_string_free ();
       (yyval.chars) = plain_code.code;
     }
-/* Line 1702 of yacc.c  */
-#line 3016 "src/parse-gram.c"
+/* Line 1701 of yacc.c  */
+#line 3020 "src/parse-gram.c"
     break;
 
   case 105:
-/* Line 1702 of yacc.c  */
-#line 678 "src/parse-gram.y"
+/* Line 1701 of yacc.c  */
+#line 683 "src/parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1702 of yacc.c  */
-#line 3024 "src/parse-gram.c"
+/* Line 1701 of yacc.c  */
+#line 3028 "src/parse-gram.c"
     break;
 
   case 106:
-/* Line 1702 of yacc.c  */
-#line 680 "src/parse-gram.y"
+/* Line 1701 of yacc.c  */
+#line 685 "src/parse-gram.y"
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[0].character)), (yylsp[0]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
       symbol_user_token_number_set ((yyval.symbol), (yyvsp[0].character), (yylsp[0]));
     }
-/* Line 1702 of yacc.c  */
-#line 3036 "src/parse-gram.c"
+/* Line 1701 of yacc.c  */
+#line 3040 "src/parse-gram.c"
     break;
 
   case 107:
-/* Line 1702 of yacc.c  */
-#line 688 "src/parse-gram.y"
+/* Line 1701 of yacc.c  */
+#line 693 "src/parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1702 of yacc.c  */
-#line 3044 "src/parse-gram.c"
+/* Line 1701 of yacc.c  */
+#line 3048 "src/parse-gram.c"
     break;
 
   case 110:
-/* Line 1702 of yacc.c  */
-#line 700 "src/parse-gram.y"
+/* Line 1701 of yacc.c  */
+#line 705 "src/parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[0].chars)), (yylsp[0]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
     }
-/* Line 1702 of yacc.c  */
-#line 3055 "src/parse-gram.c"
+/* Line 1701 of yacc.c  */
+#line 3059 "src/parse-gram.c"
     break;
 
   case 112:
-/* Line 1702 of yacc.c  */
-#line 709 "src/parse-gram.y"
+/* Line 1701 of yacc.c  */
+#line 714 "src/parse-gram.y"
     {
       code_props plain_code;
       code_props_plain_init (&plain_code, (yyvsp[0].chars), (yylsp[0]));
@@ -3065,13 +3069,13 @@ yyreduce:
       muscle_code_grow ("epilogue", plain_code.code, (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1702 of yacc.c  */
-#line 3070 "src/parse-gram.c"
+/* Line 1701 of yacc.c  */
+#line 3074 "src/parse-gram.c"
     break;
 
 
-/* Line 1702 of yacc.c  */
-#line 3075 "src/parse-gram.c"
+/* Line 1701 of yacc.c  */
+#line 3079 "src/parse-gram.c"
         default: break;
       }
     if (yychar_backup != yychar)
@@ -3318,8 +3322,8 @@ yyreturn:
   return YYID (yyresult);
 }
 
-/* Line 1962 of yacc.c  */
-#line 719 "src/parse-gram.y"
+/* Line 1961 of yacc.c  */
+#line 724 "src/parse-gram.y"
 
 
 
