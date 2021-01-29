@@ -3,7 +3,7 @@
 /* Implementation for Bison's Yacc-like parsers in C
 
    Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006,
-   2007, 2008 Free Software Foundation, Inc.
+   2007, 2008, 2009 Free Software Foundation, Inc.
 
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
@@ -613,17 +613,17 @@ static const yytype_uint8 yytranslate[] =
   /* YYRLINEYYN -- Source line where rule number YYN was defined.    */
 static const yytype_uint16 yyrline[] =
 {
-       0,   203,   203,   211,   213,   217,   218,   228,   229,   233,
-     234,   239,   243,   244,   245,   246,   247,   252,   261,   262,
-     263,   264,   265,   266,   267,   268,   269,   270,   271,   284,
-     285,   309,   310,   311,   312,   316,   317,   318,   322,   329,
-     336,   340,   344,   351,   366,   367,   371,   383,   383,   388,
-     388,   393,   404,   419,   420,   421,   422,   426,   427,   432,
-     434,   439,   440,   445,   447,   452,   453,   457,   458,   459,
-     460,   465,   470,   475,   481,   487,   498,   499,   508,   509,
-     515,   516,   517,   524,   524,   528,   529,   530,   535,   536,
-     538,   540,   542,   544,   554,   555,   561,   564,   573,   593,
-     595,   604,   609,   610,   615,   622,   624
+       0,   203,   203,   211,   213,   217,   218,   228,   232,   236,
+     237,   242,   246,   247,   248,   249,   250,   255,   264,   265,
+     266,   267,   268,   269,   270,   271,   272,   273,   274,   287,
+     288,   312,   313,   314,   315,   319,   320,   321,   325,   332,
+     339,   343,   347,   354,   369,   370,   374,   386,   386,   391,
+     391,   396,   407,   422,   423,   424,   425,   429,   430,   435,
+     437,   442,   443,   448,   450,   455,   456,   460,   461,   462,
+     463,   468,   473,   478,   484,   490,   501,   502,   511,   512,
+     518,   519,   520,   527,   527,   531,   532,   533,   538,   539,
+     541,   543,   545,   547,   557,   558,   564,   567,   576,   596,
+     598,   607,   612,   613,   618,   625,   627
 };
 #endif
 
@@ -1855,97 +1855,99 @@ yyreduce:
 
   case 7:
 /* Line 1380 of yacc.c  */
-#line 228 "parse-gram.y"
-    { debug_flag = true; }
+#line 229 "parse-gram.y"
+    {
+      muscle_percent_define_insert ("debug", (yyloc), "");
+    }
 /* Line 1380 of yacc.c  */
-#line 1862 "../../src/parse-gram.c"
+#line 1864 "../../src/parse-gram.c"
     break;
 
   case 8:
 /* Line 1380 of yacc.c  */
-#line 230 "parse-gram.y"
+#line 233 "parse-gram.y"
     {
       muscle_percent_define_insert ((yyvsp[-1].uniqstr), (yylsp[-1]), (yyvsp[0].chars));
     }
 /* Line 1380 of yacc.c  */
-#line 1872 "../../src/parse-gram.c"
+#line 1874 "../../src/parse-gram.c"
     break;
 
   case 9:
 /* Line 1380 of yacc.c  */
-#line 233 "parse-gram.y"
+#line 236 "parse-gram.y"
     { defines_flag = true; }
 /* Line 1380 of yacc.c  */
-#line 1880 "../../src/parse-gram.c"
+#line 1882 "../../src/parse-gram.c"
     break;
 
   case 10:
 /* Line 1380 of yacc.c  */
-#line 235 "parse-gram.y"
+#line 238 "parse-gram.y"
     {
       defines_flag = true;
       spec_defines_file = xstrdup ((yyvsp[0].chars));
     }
 /* Line 1380 of yacc.c  */
-#line 1891 "../../src/parse-gram.c"
+#line 1893 "../../src/parse-gram.c"
     break;
 
   case 11:
 /* Line 1380 of yacc.c  */
-#line 240 "parse-gram.y"
+#line 243 "parse-gram.y"
     {
       muscle_percent_define_insert ("error_verbose", (yyloc), "");
     }
 /* Line 1380 of yacc.c  */
-#line 1901 "../../src/parse-gram.c"
+#line 1903 "../../src/parse-gram.c"
     break;
 
   case 12:
 /* Line 1380 of yacc.c  */
-#line 243 "parse-gram.y"
+#line 246 "parse-gram.y"
     { expected_sr_conflicts = (yyvsp[0].integer); }
 /* Line 1380 of yacc.c  */
-#line 1909 "../../src/parse-gram.c"
+#line 1911 "../../src/parse-gram.c"
     break;
 
   case 13:
 /* Line 1380 of yacc.c  */
-#line 244 "parse-gram.y"
+#line 247 "parse-gram.y"
     { expected_rr_conflicts = (yyvsp[0].integer); }
 /* Line 1380 of yacc.c  */
-#line 1917 "../../src/parse-gram.c"
+#line 1919 "../../src/parse-gram.c"
     break;
 
   case 14:
 /* Line 1380 of yacc.c  */
-#line 245 "parse-gram.y"
+#line 248 "parse-gram.y"
     { spec_file_prefix = (yyvsp[0].chars); }
 /* Line 1380 of yacc.c  */
-#line 1925 "../../src/parse-gram.c"
+#line 1927 "../../src/parse-gram.c"
     break;
 
   case 15:
 /* Line 1380 of yacc.c  */
-#line 246 "parse-gram.y"
+#line 249 "parse-gram.y"
     { spec_file_prefix = (yyvsp[0].chars); }
 /* Line 1380 of yacc.c  */
-#line 1933 "../../src/parse-gram.c"
+#line 1935 "../../src/parse-gram.c"
     break;
 
   case 16:
 /* Line 1380 of yacc.c  */
-#line 248 "parse-gram.y"
+#line 251 "parse-gram.y"
     {
       nondeterministic_parser = true;
       glr_parser = true;
     }
 /* Line 1380 of yacc.c  */
-#line 1944 "../../src/parse-gram.c"
+#line 1946 "../../src/parse-gram.c"
     break;
 
   case 17:
 /* Line 1380 of yacc.c  */
-#line 253 "parse-gram.y"
+#line 256 "parse-gram.y"
     {
       code_props action;
       code_props_symbol_action_init (&action, (yyvsp[0].code), (yylsp[0]));
@@ -1955,92 +1957,92 @@ yyreduce:
       code_scanner_last_string_free ();
     }
 /* Line 1380 of yacc.c  */
-#line 1959 "../../src/parse-gram.c"
+#line 1961 "../../src/parse-gram.c"
     break;
 
   case 18:
 /* Line 1380 of yacc.c  */
-#line 261 "parse-gram.y"
+#line 264 "parse-gram.y"
     { language_argmatch ((yyvsp[0].chars), grammar_prio, (yylsp[-1])); }
 /* Line 1380 of yacc.c  */
-#line 1967 "../../src/parse-gram.c"
+#line 1969 "../../src/parse-gram.c"
     break;
 
   case 19:
 /* Line 1380 of yacc.c  */
-#line 262 "parse-gram.y"
+#line 265 "parse-gram.y"
     { add_param ("lex_param", (yyvsp[0].code), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 1975 "../../src/parse-gram.c"
+#line 1977 "../../src/parse-gram.c"
     break;
 
   case 20:
 /* Line 1380 of yacc.c  */
-#line 263 "parse-gram.y"
+#line 266 "parse-gram.y"
     { locations_flag = true; }
 /* Line 1380 of yacc.c  */
-#line 1983 "../../src/parse-gram.c"
+#line 1985 "../../src/parse-gram.c"
     break;
 
   case 21:
 /* Line 1380 of yacc.c  */
-#line 264 "parse-gram.y"
+#line 267 "parse-gram.y"
     { spec_name_prefix = (yyvsp[0].chars); }
 /* Line 1380 of yacc.c  */
-#line 1991 "../../src/parse-gram.c"
+#line 1993 "../../src/parse-gram.c"
     break;
 
   case 22:
 /* Line 1380 of yacc.c  */
-#line 265 "parse-gram.y"
+#line 268 "parse-gram.y"
     { spec_name_prefix = (yyvsp[0].chars); }
 /* Line 1380 of yacc.c  */
-#line 1999 "../../src/parse-gram.c"
+#line 2001 "../../src/parse-gram.c"
     break;
 
   case 23:
 /* Line 1380 of yacc.c  */
-#line 266 "parse-gram.y"
+#line 269 "parse-gram.y"
     { no_lines_flag = true; }
 /* Line 1380 of yacc.c  */
-#line 2007 "../../src/parse-gram.c"
+#line 2009 "../../src/parse-gram.c"
     break;
 
   case 24:
 /* Line 1380 of yacc.c  */
-#line 267 "parse-gram.y"
+#line 270 "parse-gram.y"
     { nondeterministic_parser = true; }
 /* Line 1380 of yacc.c  */
-#line 2015 "../../src/parse-gram.c"
+#line 2017 "../../src/parse-gram.c"
     break;
 
   case 25:
 /* Line 1380 of yacc.c  */
-#line 268 "parse-gram.y"
+#line 271 "parse-gram.y"
     { spec_outfile = (yyvsp[0].chars); }
 /* Line 1380 of yacc.c  */
-#line 2023 "../../src/parse-gram.c"
+#line 2025 "../../src/parse-gram.c"
     break;
 
   case 26:
 /* Line 1380 of yacc.c  */
-#line 269 "parse-gram.y"
+#line 272 "parse-gram.y"
     { spec_outfile = (yyvsp[0].chars); }
 /* Line 1380 of yacc.c  */
-#line 2031 "../../src/parse-gram.c"
+#line 2033 "../../src/parse-gram.c"
     break;
 
   case 27:
 /* Line 1380 of yacc.c  */
-#line 270 "parse-gram.y"
+#line 273 "parse-gram.y"
     { add_param ("parse_param", (yyvsp[0].code), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2039 "../../src/parse-gram.c"
+#line 2041 "../../src/parse-gram.c"
     break;
 
   case 28:
 /* Line 1380 of yacc.c  */
-#line 272 "parse-gram.y"
+#line 275 "parse-gram.y"
     {
       /* %pure-parser is deprecated in favor of `%define api.pure', so use
          `%define api.pure' in a backward-compatible manner here.  First, don't
@@ -2054,20 +2056,20 @@ yyreduce:
         muscle_percent_define_insert ("api.pure", (yylsp[0]), "");
     }
 /* Line 1380 of yacc.c  */
-#line 2058 "../../src/parse-gram.c"
+#line 2060 "../../src/parse-gram.c"
     break;
 
   case 29:
 /* Line 1380 of yacc.c  */
-#line 284 "parse-gram.y"
+#line 287 "parse-gram.y"
     { version_check (&(yylsp[0]), (yyvsp[0].chars)); }
 /* Line 1380 of yacc.c  */
-#line 2066 "../../src/parse-gram.c"
+#line 2068 "../../src/parse-gram.c"
     break;
 
   case 30:
 /* Line 1380 of yacc.c  */
-#line 286 "parse-gram.y"
+#line 289 "parse-gram.y"
     {
       char const *skeleton_user = (yyvsp[0].chars);
       if (strchr (skeleton_user, '/'))
@@ -2092,46 +2094,46 @@ yyreduce:
       skeleton_arg (skeleton_user, grammar_prio, (yylsp[-1]));
     }
 /* Line 1380 of yacc.c  */
-#line 2096 "../../src/parse-gram.c"
+#line 2098 "../../src/parse-gram.c"
     break;
 
   case 31:
 /* Line 1380 of yacc.c  */
-#line 309 "parse-gram.y"
+#line 312 "parse-gram.y"
     { token_table_flag = true; }
 /* Line 1380 of yacc.c  */
-#line 2104 "../../src/parse-gram.c"
+#line 2106 "../../src/parse-gram.c"
     break;
 
   case 32:
 /* Line 1380 of yacc.c  */
-#line 310 "parse-gram.y"
+#line 313 "parse-gram.y"
     { report_flag |= report_states; }
 /* Line 1380 of yacc.c  */
-#line 2112 "../../src/parse-gram.c"
+#line 2114 "../../src/parse-gram.c"
     break;
 
   case 33:
 /* Line 1380 of yacc.c  */
-#line 311 "parse-gram.y"
+#line 314 "parse-gram.y"
     { yacc_flag = true; }
 /* Line 1380 of yacc.c  */
-#line 2120 "../../src/parse-gram.c"
+#line 2122 "../../src/parse-gram.c"
     break;
 
   case 37:
 /* Line 1380 of yacc.c  */
-#line 319 "parse-gram.y"
+#line 322 "parse-gram.y"
     {
       grammar_start_symbol_set ((yyvsp[0].symbol), (yylsp[0]));
     }
 /* Line 1380 of yacc.c  */
-#line 2130 "../../src/parse-gram.c"
+#line 2132 "../../src/parse-gram.c"
     break;
 
   case 38:
 /* Line 1380 of yacc.c  */
-#line 323 "parse-gram.y"
+#line 326 "parse-gram.y"
     {
       symbol_list *list;
       for (list = (yyvsp[0].list); list; list = list->next)
@@ -2139,12 +2141,12 @@ yyreduce:
       symbol_list_free ((yyvsp[0].list));
     }
 /* Line 1380 of yacc.c  */
-#line 2143 "../../src/parse-gram.c"
+#line 2145 "../../src/parse-gram.c"
     break;
 
   case 39:
 /* Line 1380 of yacc.c  */
-#line 330 "parse-gram.y"
+#line 333 "parse-gram.y"
     {
       symbol_list *list;
       for (list = (yyvsp[0].list); list; list = list->next)
@@ -2152,32 +2154,32 @@ yyreduce:
       symbol_list_free ((yyvsp[0].list));
     }
 /* Line 1380 of yacc.c  */
-#line 2156 "../../src/parse-gram.c"
+#line 2158 "../../src/parse-gram.c"
     break;
 
   case 40:
 /* Line 1380 of yacc.c  */
-#line 337 "parse-gram.y"
+#line 340 "parse-gram.y"
     {
       default_prec = true;
     }
 /* Line 1380 of yacc.c  */
-#line 2166 "../../src/parse-gram.c"
+#line 2168 "../../src/parse-gram.c"
     break;
 
   case 41:
 /* Line 1380 of yacc.c  */
-#line 341 "parse-gram.y"
+#line 344 "parse-gram.y"
     {
       default_prec = false;
     }
 /* Line 1380 of yacc.c  */
-#line 2176 "../../src/parse-gram.c"
+#line 2178 "../../src/parse-gram.c"
     break;
 
   case 42:
 /* Line 1380 of yacc.c  */
-#line 345 "parse-gram.y"
+#line 348 "parse-gram.y"
     {
       /* Do not invoke muscle_percent_code_grow here since it invokes
          muscle_user_name_list_grow.  */
@@ -2185,89 +2187,89 @@ yyreduce:
       code_scanner_last_string_free ();
     }
 /* Line 1380 of yacc.c  */
-#line 2189 "../../src/parse-gram.c"
+#line 2191 "../../src/parse-gram.c"
     break;
 
   case 43:
 /* Line 1380 of yacc.c  */
-#line 352 "parse-gram.y"
+#line 355 "parse-gram.y"
     {
       muscle_percent_code_grow ((yyvsp[-1].uniqstr), (yylsp[-1]), (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
 /* Line 1380 of yacc.c  */
-#line 2200 "../../src/parse-gram.c"
+#line 2202 "../../src/parse-gram.c"
     break;
 
   case 44:
 /* Line 1380 of yacc.c  */
-#line 366 "parse-gram.y"
+#line 369 "parse-gram.y"
     {}
 /* Line 1380 of yacc.c  */
-#line 2208 "../../src/parse-gram.c"
+#line 2210 "../../src/parse-gram.c"
     break;
 
   case 45:
 /* Line 1380 of yacc.c  */
-#line 367 "parse-gram.y"
+#line 370 "parse-gram.y"
     { muscle_code_grow ("union_name", (yyvsp[0].uniqstr), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2216 "../../src/parse-gram.c"
+#line 2218 "../../src/parse-gram.c"
     break;
 
   case 46:
 /* Line 1380 of yacc.c  */
-#line 372 "parse-gram.y"
+#line 375 "parse-gram.y"
     {
       union_seen = true;
       muscle_code_grow ("stype", (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
 /* Line 1380 of yacc.c  */
-#line 2228 "../../src/parse-gram.c"
+#line 2230 "../../src/parse-gram.c"
     break;
 
   case 47:
 /* Line 1380 of yacc.c  */
-#line 383 "parse-gram.y"
+#line 386 "parse-gram.y"
     { current_class = nterm_sym; }
 /* Line 1380 of yacc.c  */
-#line 2236 "../../src/parse-gram.c"
+#line 2238 "../../src/parse-gram.c"
     break;
 
   case 48:
 /* Line 1380 of yacc.c  */
-#line 384 "parse-gram.y"
+#line 387 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
 /* Line 1380 of yacc.c  */
-#line 2247 "../../src/parse-gram.c"
+#line 2249 "../../src/parse-gram.c"
     break;
 
   case 49:
 /* Line 1380 of yacc.c  */
-#line 388 "parse-gram.y"
+#line 391 "parse-gram.y"
     { current_class = token_sym; }
 /* Line 1380 of yacc.c  */
-#line 2255 "../../src/parse-gram.c"
+#line 2257 "../../src/parse-gram.c"
     break;
 
   case 50:
 /* Line 1380 of yacc.c  */
-#line 389 "parse-gram.y"
+#line 392 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
 /* Line 1380 of yacc.c  */
-#line 2266 "../../src/parse-gram.c"
+#line 2268 "../../src/parse-gram.c"
     break;
 
   case 51:
 /* Line 1380 of yacc.c  */
-#line 394 "parse-gram.y"
+#line 397 "parse-gram.y"
     {
       symbol_list *list;
       tag_seen = true;
@@ -2276,12 +2278,12 @@ yyreduce:
       symbol_list_free ((yyvsp[0].list));
     }
 /* Line 1380 of yacc.c  */
-#line 2280 "../../src/parse-gram.c"
+#line 2282 "../../src/parse-gram.c"
     break;
 
   case 52:
 /* Line 1380 of yacc.c  */
-#line 405 "parse-gram.y"
+#line 408 "parse-gram.y"
     {
       symbol_list *list;
       ++current_prec;
@@ -2294,202 +2296,202 @@ yyreduce:
       current_type = NULL;
     }
 /* Line 1380 of yacc.c  */
-#line 2298 "../../src/parse-gram.c"
+#line 2300 "../../src/parse-gram.c"
     break;
 
   case 53:
 /* Line 1380 of yacc.c  */
-#line 419 "parse-gram.y"
+#line 422 "parse-gram.y"
     { (yyval.assoc) = left_assoc; }
 /* Line 1380 of yacc.c  */
-#line 2306 "../../src/parse-gram.c"
+#line 2308 "../../src/parse-gram.c"
     break;
 
   case 54:
 /* Line 1380 of yacc.c  */
-#line 420 "parse-gram.y"
+#line 423 "parse-gram.y"
     { (yyval.assoc) = right_assoc; }
 /* Line 1380 of yacc.c  */
-#line 2314 "../../src/parse-gram.c"
+#line 2316 "../../src/parse-gram.c"
     break;
 
   case 55:
 /* Line 1380 of yacc.c  */
-#line 421 "parse-gram.y"
+#line 424 "parse-gram.y"
     { (yyval.assoc) = non_assoc; }
 /* Line 1380 of yacc.c  */
-#line 2322 "../../src/parse-gram.c"
+#line 2324 "../../src/parse-gram.c"
     break;
 
   case 56:
 /* Line 1380 of yacc.c  */
-#line 422 "parse-gram.y"
+#line 425 "parse-gram.y"
     { (yyval.assoc) = precedence_assoc; }
 /* Line 1380 of yacc.c  */
-#line 2330 "../../src/parse-gram.c"
+#line 2332 "../../src/parse-gram.c"
     break;
 
   case 57:
 /* Line 1380 of yacc.c  */
-#line 426 "parse-gram.y"
+#line 429 "parse-gram.y"
     { current_type = NULL; }
 /* Line 1380 of yacc.c  */
-#line 2338 "../../src/parse-gram.c"
+#line 2340 "../../src/parse-gram.c"
     break;
 
   case 58:
 /* Line 1380 of yacc.c  */
-#line 427 "parse-gram.y"
+#line 430 "parse-gram.y"
     { current_type = (yyvsp[0].uniqstr); tag_seen = true; }
 /* Line 1380 of yacc.c  */
-#line 2346 "../../src/parse-gram.c"
+#line 2348 "../../src/parse-gram.c"
     break;
 
   case 59:
 /* Line 1380 of yacc.c  */
-#line 433 "parse-gram.y"
+#line 436 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2354 "../../src/parse-gram.c"
+#line 2356 "../../src/parse-gram.c"
     break;
 
   case 60:
 /* Line 1380 of yacc.c  */
-#line 435 "parse-gram.y"
+#line 438 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
 /* Line 1380 of yacc.c  */
-#line 2362 "../../src/parse-gram.c"
+#line 2364 "../../src/parse-gram.c"
     break;
 
   case 61:
 /* Line 1380 of yacc.c  */
-#line 439 "parse-gram.y"
+#line 442 "parse-gram.y"
     { (yyval.symbol) = (yyvsp[0].symbol); }
 /* Line 1380 of yacc.c  */
-#line 2370 "../../src/parse-gram.c"
+#line 2372 "../../src/parse-gram.c"
     break;
 
   case 62:
 /* Line 1380 of yacc.c  */
-#line 440 "parse-gram.y"
+#line 443 "parse-gram.y"
     { (yyval.symbol) = (yyvsp[-1].symbol); symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2378 "../../src/parse-gram.c"
+#line 2380 "../../src/parse-gram.c"
     break;
 
   case 63:
 /* Line 1380 of yacc.c  */
-#line 446 "parse-gram.y"
+#line 449 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2386 "../../src/parse-gram.c"
+#line 2388 "../../src/parse-gram.c"
     break;
 
   case 64:
 /* Line 1380 of yacc.c  */
-#line 448 "parse-gram.y"
+#line 451 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
 /* Line 1380 of yacc.c  */
-#line 2394 "../../src/parse-gram.c"
+#line 2396 "../../src/parse-gram.c"
     break;
 
   case 65:
 /* Line 1380 of yacc.c  */
-#line 452 "parse-gram.y"
+#line 455 "parse-gram.y"
     { (yyval.list) = (yyvsp[0].list); }
 /* Line 1380 of yacc.c  */
-#line 2402 "../../src/parse-gram.c"
+#line 2404 "../../src/parse-gram.c"
     break;
 
   case 66:
 /* Line 1380 of yacc.c  */
-#line 453 "parse-gram.y"
+#line 456 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), (yyvsp[0].list)); }
 /* Line 1380 of yacc.c  */
-#line 2410 "../../src/parse-gram.c"
+#line 2412 "../../src/parse-gram.c"
     break;
 
   case 67:
 /* Line 1380 of yacc.c  */
-#line 457 "parse-gram.y"
+#line 460 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2418 "../../src/parse-gram.c"
+#line 2420 "../../src/parse-gram.c"
     break;
 
   case 68:
 /* Line 1380 of yacc.c  */
-#line 458 "parse-gram.y"
+#line 461 "parse-gram.y"
     { (yyval.list) = symbol_list_type_new ((yyvsp[0].uniqstr), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2426 "../../src/parse-gram.c"
+#line 2428 "../../src/parse-gram.c"
     break;
 
   case 69:
 /* Line 1380 of yacc.c  */
-#line 459 "parse-gram.y"
+#line 462 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagged_new ((yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2434 "../../src/parse-gram.c"
+#line 2436 "../../src/parse-gram.c"
     break;
 
   case 70:
 /* Line 1380 of yacc.c  */
-#line 460 "parse-gram.y"
+#line 463 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagless_new ((yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2442 "../../src/parse-gram.c"
+#line 2444 "../../src/parse-gram.c"
     break;
 
   case 71:
 /* Line 1380 of yacc.c  */
-#line 466 "parse-gram.y"
+#line 469 "parse-gram.y"
     {
        current_type = (yyvsp[0].uniqstr);
        tag_seen = true;
      }
 /* Line 1380 of yacc.c  */
-#line 2453 "../../src/parse-gram.c"
+#line 2455 "../../src/parse-gram.c"
     break;
 
   case 72:
 /* Line 1380 of yacc.c  */
-#line 471 "parse-gram.y"
+#line 474 "parse-gram.y"
     {
        symbol_class_set ((yyvsp[0].symbol), current_class, (yylsp[0]), true);
        symbol_type_set ((yyvsp[0].symbol), current_type, (yylsp[0]));
      }
 /* Line 1380 of yacc.c  */
-#line 2464 "../../src/parse-gram.c"
+#line 2466 "../../src/parse-gram.c"
     break;
 
   case 73:
 /* Line 1380 of yacc.c  */
-#line 476 "parse-gram.y"
+#line 479 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[-1].symbol), current_class, (yylsp[-1]), true);
       symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
       symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0]));
     }
 /* Line 1380 of yacc.c  */
-#line 2476 "../../src/parse-gram.c"
+#line 2478 "../../src/parse-gram.c"
     break;
 
   case 74:
 /* Line 1380 of yacc.c  */
-#line 482 "parse-gram.y"
+#line 485 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[-1].symbol), current_class, (yylsp[-1]), true);
       symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
       symbol_make_alias ((yyvsp[-1].symbol), (yyvsp[0].symbol), (yyloc));
     }
 /* Line 1380 of yacc.c  */
-#line 2488 "../../src/parse-gram.c"
+#line 2490 "../../src/parse-gram.c"
     break;
 
   case 75:
 /* Line 1380 of yacc.c  */
-#line 488 "parse-gram.y"
+#line 491 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[-2].symbol), current_class, (yylsp[-2]), true);
       symbol_type_set ((yyvsp[-2].symbol), current_type, (yylsp[-2]));
@@ -2497,112 +2499,112 @@ yyreduce:
       symbol_make_alias ((yyvsp[-2].symbol), (yyvsp[0].symbol), (yyloc));
     }
 /* Line 1380 of yacc.c  */
-#line 2501 "../../src/parse-gram.c"
+#line 2503 "../../src/parse-gram.c"
     break;
 
   case 82:
 /* Line 1380 of yacc.c  */
-#line 518 "parse-gram.y"
+#line 521 "parse-gram.y"
     {
       yyerrok;
     }
 /* Line 1380 of yacc.c  */
-#line 2511 "../../src/parse-gram.c"
+#line 2513 "../../src/parse-gram.c"
     break;
 
   case 83:
 /* Line 1380 of yacc.c  */
-#line 524 "parse-gram.y"
+#line 527 "parse-gram.y"
     { current_lhs = (yyvsp[0].symbol); current_lhs_location = (yylsp[0]); }
 /* Line 1380 of yacc.c  */
-#line 2519 "../../src/parse-gram.c"
+#line 2521 "../../src/parse-gram.c"
     break;
 
   case 85:
 /* Line 1380 of yacc.c  */
-#line 528 "parse-gram.y"
+#line 531 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2527 "../../src/parse-gram.c"
+#line 2529 "../../src/parse-gram.c"
     break;
 
   case 86:
 /* Line 1380 of yacc.c  */
-#line 529 "parse-gram.y"
+#line 532 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2535 "../../src/parse-gram.c"
+#line 2537 "../../src/parse-gram.c"
     break;
 
   case 88:
 /* Line 1380 of yacc.c  */
-#line 535 "parse-gram.y"
+#line 538 "parse-gram.y"
     { grammar_current_rule_begin (current_lhs, current_lhs_location); }
 /* Line 1380 of yacc.c  */
-#line 2543 "../../src/parse-gram.c"
+#line 2545 "../../src/parse-gram.c"
     break;
 
   case 89:
 /* Line 1380 of yacc.c  */
-#line 537 "parse-gram.y"
+#line 540 "parse-gram.y"
     { grammar_current_rule_symbol_append ((yyvsp[0].symbol), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2551 "../../src/parse-gram.c"
+#line 2553 "../../src/parse-gram.c"
     break;
 
   case 90:
 /* Line 1380 of yacc.c  */
-#line 539 "parse-gram.y"
+#line 542 "parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[0].code), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2559 "../../src/parse-gram.c"
+#line 2561 "../../src/parse-gram.c"
     break;
 
   case 91:
 /* Line 1380 of yacc.c  */
-#line 541 "parse-gram.y"
+#line 544 "parse-gram.y"
     { grammar_current_rule_prec_set ((yyvsp[0].symbol), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2567 "../../src/parse-gram.c"
+#line 2569 "../../src/parse-gram.c"
     break;
 
   case 92:
 /* Line 1380 of yacc.c  */
-#line 543 "parse-gram.y"
+#line 546 "parse-gram.y"
     { grammar_current_rule_dprec_set ((yyvsp[0].integer), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2575 "../../src/parse-gram.c"
+#line 2577 "../../src/parse-gram.c"
     break;
 
   case 93:
 /* Line 1380 of yacc.c  */
-#line 545 "parse-gram.y"
+#line 548 "parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[0].uniqstr), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2583 "../../src/parse-gram.c"
+#line 2585 "../../src/parse-gram.c"
     break;
 
   case 95:
 /* Line 1380 of yacc.c  */
-#line 555 "parse-gram.y"
+#line 558 "parse-gram.y"
     { (yyval.uniqstr) = uniqstr_new ((yyvsp[0].chars)); }
 /* Line 1380 of yacc.c  */
-#line 2591 "../../src/parse-gram.c"
+#line 2593 "../../src/parse-gram.c"
     break;
 
   case 96:
 /* Line 1380 of yacc.c  */
-#line 561 "parse-gram.y"
+#line 564 "parse-gram.y"
     {
       (yyval.chars) = "";
     }
 /* Line 1380 of yacc.c  */
-#line 2601 "../../src/parse-gram.c"
+#line 2603 "../../src/parse-gram.c"
     break;
 
   case 98:
 /* Line 1380 of yacc.c  */
-#line 574 "parse-gram.y"
+#line 577 "parse-gram.y"
     {
       code_props plain_code;
       (yyvsp[0].code)[strlen ((yyvsp[0].code)) - 1] = '\n';
@@ -2612,51 +2614,51 @@ yyreduce:
       (yyval.chars) = plain_code.code;
     }
 /* Line 1380 of yacc.c  */
-#line 2616 "../../src/parse-gram.c"
+#line 2618 "../../src/parse-gram.c"
     break;
 
   case 99:
 /* Line 1380 of yacc.c  */
-#line 594 "parse-gram.y"
+#line 597 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2624 "../../src/parse-gram.c"
+#line 2626 "../../src/parse-gram.c"
     break;
 
   case 100:
 /* Line 1380 of yacc.c  */
-#line 596 "parse-gram.y"
+#line 599 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[0].character)), (yylsp[0]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
       symbol_user_token_number_set ((yyval.symbol), (yyvsp[0].character), (yylsp[0]));
     }
 /* Line 1380 of yacc.c  */
-#line 2636 "../../src/parse-gram.c"
+#line 2638 "../../src/parse-gram.c"
     break;
 
   case 101:
 /* Line 1380 of yacc.c  */
-#line 604 "parse-gram.y"
+#line 607 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2644 "../../src/parse-gram.c"
+#line 2646 "../../src/parse-gram.c"
     break;
 
   case 104:
 /* Line 1380 of yacc.c  */
-#line 616 "parse-gram.y"
+#line 619 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[0].chars)), (yylsp[0]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
     }
 /* Line 1380 of yacc.c  */
-#line 2655 "../../src/parse-gram.c"
+#line 2657 "../../src/parse-gram.c"
     break;
 
   case 106:
 /* Line 1380 of yacc.c  */
-#line 625 "parse-gram.y"
+#line 628 "parse-gram.y"
     {
       code_props plain_code;
       code_props_plain_init (&plain_code, (yyvsp[0].chars), (yylsp[0]));
@@ -2666,12 +2668,12 @@ yyreduce:
       code_scanner_last_string_free ();
     }
 /* Line 1380 of yacc.c  */
-#line 2670 "../../src/parse-gram.c"
+#line 2672 "../../src/parse-gram.c"
     break;
 
 
 /* Line 1380 of yacc.c  */
-#line 2675 "../../src/parse-gram.c"
+#line 2677 "../../src/parse-gram.c"
       default: break;
     }
   YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);
@@ -2888,7 +2890,7 @@ yyreturn:
 }
 
 /* Line 1599 of yacc.c  */
-#line 635 "parse-gram.y"
+#line 638 "parse-gram.y"
 
 
 
