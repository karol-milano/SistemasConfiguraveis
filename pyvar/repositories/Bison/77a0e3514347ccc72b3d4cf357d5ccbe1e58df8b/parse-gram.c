@@ -1,9 +1,8 @@
-/* A Bison parser, made by GNU Bison 3.0.2.13-975bb-dirty.  */
+/* A Bison parser, made by GNU Bison 3.0.4.26-d132-dirty.  */
 
 /* Bison implementation for Yacc-like parsers in C
 
-   Copyright (C) 1984, 1989-1990, 2000-2015, 2018 Free Software
-   Foundation, Inc.
+   Copyright (C) 1984, 1989-1990, 2000-2015, 2018 Free Software Foundation, Inc.
 
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
@@ -45,7 +44,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "3.0.2.13-975bb-dirty"
+#define YYBISON_VERSION "3.0.4.26-d132-dirty"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -1670,6 +1669,7 @@ yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
       case N:                               \
         yyformat = S;                       \
       break
+    default: /* Avoid compiler warnings. */
       YYCASE_(0, YY_("syntax error"));
       YYCASE_(1, YY_("syntax error, unexpected %s"));
       YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
@@ -1843,7 +1843,7 @@ YYLTYPE yylloc = yyloc_default;
   yychar = YYEMPTY; /* Cause a token to be read.  */
 
 /* User initialization code.  */
-#line 108 "src/parse-gram.y" /* yacc.c:1429  */
+#line 108 "src/parse-gram.y" /* yacc.c:1430  */
 {
   /* Bison's grammar can initial empty locations, hence a default
      location is needed. */
@@ -1851,7 +1851,7 @@ YYLTYPE yylloc = yyloc_default;
   boundary_set (&yylloc.end, current_file, 1, 1);
 }
 
-#line 1854 "src/parse-gram.c" /* yacc.c:1429  */
+#line 1855 "src/parse-gram.c" /* yacc.c:1430  */
   yylsp[0] = yylloc;
   goto yysetstate;
 
@@ -2037,151 +2037,152 @@ yyreduce:
      GCC warning that YYVAL may be used uninitialized.  */
   yyval = yyvsp[1-yylen];
 
-  /* Default location.  */
+  /* Default location. */
   YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
+  yyerror_range[1] = yyloc;
   YY_REDUCE_PRINT (yyn);
   {
     int yychar_backup = yychar;
     switch (yyn)
       {
           case 6:
-#line 280 "src/parse-gram.y" /* yacc.c:1646  */
+#line 280 "src/parse-gram.y" /* yacc.c:1648  */
     {
       muscle_code_grow (union_seen ? "post_prologue" : "pre_prologue",
                         translate_code ((yyvsp[0].code), (yylsp[0]), true), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2054 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2056 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 7:
-#line 286 "src/parse-gram.y" /* yacc.c:1646  */
+#line 286 "src/parse-gram.y" /* yacc.c:1648  */
     {
       muscle_percent_define_ensure ((yyvsp[0].uniqstr), (yylsp[0]), true);
     }
-#line 2062 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2064 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 8:
-#line 290 "src/parse-gram.y" /* yacc.c:1646  */
+#line 290 "src/parse-gram.y" /* yacc.c:1648  */
     {
       muscle_percent_define_insert ((yyvsp[-1].uniqstr), (yylsp[-1]), (yyvsp[0].value).kind, (yyvsp[0].value).chars,
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
     }
-#line 2071 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2073 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 9:
-#line 294 "src/parse-gram.y" /* yacc.c:1646  */
+#line 294 "src/parse-gram.y" /* yacc.c:1648  */
     { defines_flag = true; }
-#line 2077 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2079 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 10:
-#line 296 "src/parse-gram.y" /* yacc.c:1646  */
+#line 296 "src/parse-gram.y" /* yacc.c:1648  */
     {
       defines_flag = true;
       spec_defines_file = xstrdup ((yyvsp[0].code));
     }
-#line 2086 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2088 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 11:
-#line 301 "src/parse-gram.y" /* yacc.c:1646  */
+#line 301 "src/parse-gram.y" /* yacc.c:1648  */
     {
       muscle_percent_define_insert ("parse.error", (yylsp[0]), muscle_keyword,
                                     "verbose",
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
     }
-#line 2096 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2098 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 12:
-#line 306 "src/parse-gram.y" /* yacc.c:1646  */
+#line 306 "src/parse-gram.y" /* yacc.c:1648  */
     { expected_sr_conflicts = (yyvsp[0].integer); }
-#line 2102 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2104 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 13:
-#line 307 "src/parse-gram.y" /* yacc.c:1646  */
+#line 307 "src/parse-gram.y" /* yacc.c:1648  */
     { expected_rr_conflicts = (yyvsp[0].integer); }
-#line 2108 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2110 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 14:
-#line 308 "src/parse-gram.y" /* yacc.c:1646  */
+#line 308 "src/parse-gram.y" /* yacc.c:1648  */
     { spec_file_prefix = (yyvsp[0].code); }
-#line 2114 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2116 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 15:
-#line 310 "src/parse-gram.y" /* yacc.c:1646  */
+#line 310 "src/parse-gram.y" /* yacc.c:1648  */
     {
       nondeterministic_parser = true;
       glr_parser = true;
     }
-#line 2123 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2125 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 16:
-#line 315 "src/parse-gram.y" /* yacc.c:1646  */
+#line 315 "src/parse-gram.y" /* yacc.c:1648  */
     {
       muscle_code_grow ("initial_action", translate_code ((yyvsp[0].code), (yylsp[0]), false), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2132 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2134 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 17:
-#line 319 "src/parse-gram.y" /* yacc.c:1646  */
+#line 319 "src/parse-gram.y" /* yacc.c:1648  */
     { language_argmatch ((yyvsp[0].code), grammar_prio, (yylsp[-1])); }
-#line 2138 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2140 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 18:
-#line 320 "src/parse-gram.y" /* yacc.c:1646  */
+#line 320 "src/parse-gram.y" /* yacc.c:1648  */
     { spec_name_prefix = (yyvsp[0].code); }
-#line 2144 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2146 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 19:
-#line 321 "src/parse-gram.y" /* yacc.c:1646  */
+#line 321 "src/parse-gram.y" /* yacc.c:1648  */
     { no_lines_flag = true; }
-#line 2150 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2152 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 20:
-#line 322 "src/parse-gram.y" /* yacc.c:1646  */
+#line 322 "src/parse-gram.y" /* yacc.c:1648  */
     { nondeterministic_parser = true; }
-#line 2156 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2158 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 21:
-#line 323 "src/parse-gram.y" /* yacc.c:1646  */
+#line 323 "src/parse-gram.y" /* yacc.c:1648  */
     { spec_outfile = (yyvsp[0].code); }
-#line 2162 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2164 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 22:
-#line 324 "src/parse-gram.y" /* yacc.c:1646  */
+#line 324 "src/parse-gram.y" /* yacc.c:1648  */
     { current_param = (yyvsp[0].param); }
-#line 2168 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2170 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 23:
-#line 324 "src/parse-gram.y" /* yacc.c:1646  */
+#line 324 "src/parse-gram.y" /* yacc.c:1648  */
     { current_param = param_none; }
-#line 2174 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2176 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 24:
-#line 325 "src/parse-gram.y" /* yacc.c:1646  */
+#line 325 "src/parse-gram.y" /* yacc.c:1648  */
     { version_check (&(yylsp[0]), (yyvsp[0].code)); }
-#line 2180 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2182 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 25:
-#line 327 "src/parse-gram.y" /* yacc.c:1646  */
+#line 327 "src/parse-gram.y" /* yacc.c:1648  */
     {
       char const *skeleton_user = (yyvsp[0].code);
       if (strchr (skeleton_user, '/'))
@@ -2205,49 +2206,49 @@ yyreduce:
         }
       skeleton_arg (skeleton_user, grammar_prio, (yylsp[-1]));
     }
-#line 2208 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2210 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 26:
-#line 350 "src/parse-gram.y" /* yacc.c:1646  */
+#line 350 "src/parse-gram.y" /* yacc.c:1648  */
     { token_table_flag = true; }
-#line 2214 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2216 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 27:
-#line 351 "src/parse-gram.y" /* yacc.c:1646  */
+#line 351 "src/parse-gram.y" /* yacc.c:1648  */
     { report_flag |= report_states; }
-#line 2220 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2222 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 28:
-#line 352 "src/parse-gram.y" /* yacc.c:1646  */
+#line 352 "src/parse-gram.y" /* yacc.c:1648  */
     { yacc_flag = true; }
-#line 2226 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2228 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 30:
-#line 357 "src/parse-gram.y" /* yacc.c:1646  */
+#line 357 "src/parse-gram.y" /* yacc.c:1648  */
     { add_param (current_param, (yyvsp[0].code), (yylsp[0])); }
-#line 2232 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2234 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 31:
-#line 358 "src/parse-gram.y" /* yacc.c:1646  */
+#line 358 "src/parse-gram.y" /* yacc.c:1648  */
     { add_param (current_param, (yyvsp[0].code), (yylsp[0])); }
-#line 2238 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2240 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 34:
-#line 370 "src/parse-gram.y" /* yacc.c:1646  */
+#line 370 "src/parse-gram.y" /* yacc.c:1648  */
     {
       grammar_start_symbol_set ((yyvsp[0].symbol), (yylsp[0]));
     }
-#line 2246 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2248 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 35:
-#line 374 "src/parse-gram.y" /* yacc.c:1646  */
+#line 374 "src/parse-gram.y" /* yacc.c:1648  */
     {
       code_props code;
       code_props_symbol_action_init (&code, (yyvsp[-1].code), (yylsp[-1]));
@@ -2259,27 +2260,27 @@ yyreduce:
         symbol_list_free ((yyvsp[0].list));
       }
     }
-#line 2262 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2264 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 36:
-#line 386 "src/parse-gram.y" /* yacc.c:1646  */
+#line 386 "src/parse-gram.y" /* yacc.c:1648  */
     {
       default_prec = true;
     }
-#line 2270 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2272 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 37:
-#line 390 "src/parse-gram.y" /* yacc.c:1646  */
+#line 390 "src/parse-gram.y" /* yacc.c:1648  */
     {
       default_prec = false;
     }
-#line 2278 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2280 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 38:
-#line 394 "src/parse-gram.y" /* yacc.c:1646  */
+#line 394 "src/parse-gram.y" /* yacc.c:1648  */
     {
       /* Do not invoke muscle_percent_code_grow here since it invokes
          muscle_user_name_list_grow.  */
@@ -2287,86 +2288,86 @@ yyreduce:
                         translate_code_braceless ((yyvsp[0].code), (yylsp[0])), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2290 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2292 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 39:
-#line 402 "src/parse-gram.y" /* yacc.c:1646  */
+#line 402 "src/parse-gram.y" /* yacc.c:1648  */
     {
       muscle_percent_code_grow ((yyvsp[-1].uniqstr), (yylsp[-1]), translate_code_braceless ((yyvsp[0].code), (yylsp[0])), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2299 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2301 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 40:
-#line 412 "src/parse-gram.y" /* yacc.c:1646  */
+#line 412 "src/parse-gram.y" /* yacc.c:1648  */
     { (yyval.code_type) = destructor; }
-#line 2305 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2307 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 41:
-#line 413 "src/parse-gram.y" /* yacc.c:1646  */
+#line 413 "src/parse-gram.y" /* yacc.c:1648  */
     { (yyval.code_type) = printer; }
-#line 2311 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2313 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 42:
-#line 423 "src/parse-gram.y" /* yacc.c:1646  */
+#line 423 "src/parse-gram.y" /* yacc.c:1648  */
     {}
-#line 2317 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2319 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 43:
-#line 424 "src/parse-gram.y" /* yacc.c:1646  */
+#line 424 "src/parse-gram.y" /* yacc.c:1648  */
     { muscle_percent_define_insert ("api.value.union.name",
                                          (yylsp[0]), muscle_keyword, (yyvsp[0].uniqstr),
                                          MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE); }
-#line 2325 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2327 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 44:
-#line 431 "src/parse-gram.y" /* yacc.c:1646  */
+#line 431 "src/parse-gram.y" /* yacc.c:1648  */
     {
       union_seen = true;
       muscle_code_grow ("union_members", translate_code_braceless ((yyvsp[0].code), (yylsp[0])), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2335 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2337 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 45:
-#line 442 "src/parse-gram.y" /* yacc.c:1646  */
+#line 442 "src/parse-gram.y" /* yacc.c:1648  */
     { current_class = nterm_sym; }
-#line 2341 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2343 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 46:
-#line 443 "src/parse-gram.y" /* yacc.c:1646  */
+#line 443 "src/parse-gram.y" /* yacc.c:1648  */
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
-#line 2350 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2352 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 47:
-#line 447 "src/parse-gram.y" /* yacc.c:1646  */
+#line 447 "src/parse-gram.y" /* yacc.c:1648  */
     { current_class = token_sym; }
-#line 2356 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2358 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 48:
-#line 448 "src/parse-gram.y" /* yacc.c:1646  */
+#line 448 "src/parse-gram.y" /* yacc.c:1648  */
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
-#line 2365 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2367 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 49:
-#line 453 "src/parse-gram.y" /* yacc.c:1646  */
+#line 453 "src/parse-gram.y" /* yacc.c:1648  */
     {
       symbol_list *list;
       tag_seen = true;
@@ -2374,11 +2375,11 @@ yyreduce:
         symbol_type_set (list->content.sym, (yyvsp[-1].uniqstr), (yylsp[-1]));
       symbol_list_free ((yyvsp[0].list));
     }
-#line 2377 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2379 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 50:
-#line 464 "src/parse-gram.y" /* yacc.c:1646  */
+#line 464 "src/parse-gram.y" /* yacc.c:1648  */
     {
       symbol_list *list;
       ++current_prec;
@@ -2390,341 +2391,341 @@ yyreduce:
       symbol_list_free ((yyvsp[0].list));
       current_type = NULL;
     }
-#line 2393 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2395 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 51:
-#line 478 "src/parse-gram.y" /* yacc.c:1646  */
+#line 478 "src/parse-gram.y" /* yacc.c:1648  */
     { (yyval.assoc) = left_assoc; }
-#line 2399 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2401 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 52:
-#line 479 "src/parse-gram.y" /* yacc.c:1646  */
+#line 479 "src/parse-gram.y" /* yacc.c:1648  */
     { (yyval.assoc) = right_assoc; }
-#line 2405 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2407 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 53:
-#line 480 "src/parse-gram.y" /* yacc.c:1646  */
+#line 480 "src/parse-gram.y" /* yacc.c:1648  */
     { (yyval.assoc) = non_assoc; }
-#line 2411 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2413 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 54:
-#line 481 "src/parse-gram.y" /* yacc.c:1646  */
+#line 481 "src/parse-gram.y" /* yacc.c:1648  */
     { (yyval.assoc) = precedence_assoc; }
-#line 2417 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2419 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 55:
-#line 485 "src/parse-gram.y" /* yacc.c:1646  */
+#line 485 "src/parse-gram.y" /* yacc.c:1648  */
     { current_type = NULL; }
-#line 2423 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2425 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 56:
-#line 486 "src/parse-gram.y" /* yacc.c:1646  */
+#line 486 "src/parse-gram.y" /* yacc.c:1648  */
     { current_type = (yyvsp[0].uniqstr); tag_seen = true; }
-#line 2429 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2431 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 57:
-#line 492 "src/parse-gram.y" /* yacc.c:1646  */
+#line 492 "src/parse-gram.y" /* yacc.c:1648  */
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-#line 2435 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2437 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 58:
-#line 494 "src/parse-gram.y" /* yacc.c:1646  */
+#line 494 "src/parse-gram.y" /* yacc.c:1648  */
     { (yyval.list) = symbol_list_append ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
-#line 2441 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2443 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 59:
-#line 499 "src/parse-gram.y" /* yacc.c:1646  */
+#line 499 "src/parse-gram.y" /* yacc.c:1648  */
     {
       (yyval.symbol) = (yyvsp[0].symbol);
       symbol_class_set ((yyvsp[0].symbol), token_sym, (yylsp[0]), false);
     }
-#line 2450 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2452 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 60:
-#line 504 "src/parse-gram.y" /* yacc.c:1646  */
+#line 504 "src/parse-gram.y" /* yacc.c:1648  */
     {
       (yyval.symbol) = (yyvsp[-1].symbol);
       symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0]));
       symbol_class_set ((yyvsp[-1].symbol), token_sym, (yylsp[-1]), false);
     }
-#line 2460 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2462 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 61:
-#line 514 "src/parse-gram.y" /* yacc.c:1646  */
+#line 514 "src/parse-gram.y" /* yacc.c:1648  */
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-#line 2466 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2468 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 62:
-#line 516 "src/parse-gram.y" /* yacc.c:1646  */
+#line 516 "src/parse-gram.y" /* yacc.c:1648  */
     { (yyval.list) = symbol_list_append ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
-#line 2472 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2474 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 63:
-#line 520 "src/parse-gram.y" /* yacc.c:1646  */
+#line 520 "src/parse-gram.y" /* yacc.c:1648  */
     { (yyval.list) = (yyvsp[0].list); }
-#line 2478 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2480 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 64:
-#line 521 "src/parse-gram.y" /* yacc.c:1646  */
+#line 521 "src/parse-gram.y" /* yacc.c:1648  */
     { (yyval.list) = symbol_list_append ((yyvsp[-1].list), (yyvsp[0].list)); }
-#line 2484 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2486 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 65:
-#line 525 "src/parse-gram.y" /* yacc.c:1646  */
+#line 525 "src/parse-gram.y" /* yacc.c:1648  */
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-#line 2490 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2492 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 66:
-#line 526 "src/parse-gram.y" /* yacc.c:1646  */
+#line 526 "src/parse-gram.y" /* yacc.c:1648  */
     { (yyval.list) = symbol_list_type_new ((yyvsp[0].uniqstr), (yylsp[0])); }
-#line 2496 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2498 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 68:
-#line 531 "src/parse-gram.y" /* yacc.c:1646  */
+#line 531 "src/parse-gram.y" /* yacc.c:1648  */
     { (yyval.uniqstr) = uniqstr_new ("*"); }
-#line 2502 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2504 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 69:
-#line 532 "src/parse-gram.y" /* yacc.c:1646  */
+#line 532 "src/parse-gram.y" /* yacc.c:1648  */
     { (yyval.uniqstr) = uniqstr_new (""); }
-#line 2508 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2510 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 70:
-#line 538 "src/parse-gram.y" /* yacc.c:1646  */
+#line 538 "src/parse-gram.y" /* yacc.c:1648  */
     {
       current_type = (yyvsp[0].uniqstr);
       tag_seen = true;
     }
-#line 2517 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2519 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 71:
-#line 543 "src/parse-gram.y" /* yacc.c:1646  */
+#line 543 "src/parse-gram.y" /* yacc.c:1648  */
     {
       symbol_class_set ((yyvsp[0].symbol), current_class, (yylsp[0]), true);
       symbol_type_set ((yyvsp[0].symbol), current_type, (yylsp[0]));
     }
-#line 2526 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2528 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 72:
-#line 548 "src/parse-gram.y" /* yacc.c:1646  */
+#line 548 "src/parse-gram.y" /* yacc.c:1648  */
     {
       symbol_class_set ((yyvsp[-1].symbol), current_class, (yylsp[-1]), true);
       symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
       symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0]));
     }
-#line 2536 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2538 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 73:
-#line 554 "src/parse-gram.y" /* yacc.c:1646  */
+#line 554 "src/parse-gram.y" /* yacc.c:1648  */
     {
       symbol_class_set ((yyvsp[-1].symbol), current_class, (yylsp[-1]), true);
       symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
       symbol_make_alias ((yyvsp[-1].symbol), (yyvsp[0].symbol), (yyloc));
     }
-#line 2546 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2548 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 74:
-#line 560 "src/parse-gram.y" /* yacc.c:1646  */
+#line 560 "src/parse-gram.y" /* yacc.c:1648  */
     {
       symbol_class_set ((yyvsp[-2].symbol), current_class, (yylsp[-2]), true);
       symbol_type_set ((yyvsp[-2].symbol), current_type, (yylsp[-2]));
       symbol_user_token_number_set ((yyvsp[-2].symbol), (yyvsp[-1].integer), (yylsp[-1]));
       symbol_make_alias ((yyvsp[-2].symbol), (yyvsp[0].symbol), (yyloc));
     }
-#line 2557 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2559 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 81:
-#line 590 "src/parse-gram.y" /* yacc.c:1646  */
+#line 590 "src/parse-gram.y" /* yacc.c:1648  */
     {
       yyerrok;
     }
-#line 2565 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2567 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 82:
-#line 596 "src/parse-gram.y" /* yacc.c:1646  */
+#line 596 "src/parse-gram.y" /* yacc.c:1648  */
     { current_lhs ((yyvsp[-1].symbol), (yylsp[-1]), (yyvsp[0].named_ref)); }
-#line 2571 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2573 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 83:
-#line 597 "src/parse-gram.y" /* yacc.c:1646  */
+#line 597 "src/parse-gram.y" /* yacc.c:1648  */
     {
     /* Free the current lhs. */
     current_lhs (0, (yylsp[-3]), 0);
   }
-#line 2580 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2582 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 84:
-#line 604 "src/parse-gram.y" /* yacc.c:1646  */
+#line 604 "src/parse-gram.y" /* yacc.c:1648  */
     { grammar_current_rule_end ((yylsp[0])); }
-#line 2586 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2588 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 85:
-#line 605 "src/parse-gram.y" /* yacc.c:1646  */
+#line 605 "src/parse-gram.y" /* yacc.c:1648  */
     { grammar_current_rule_end ((yylsp[0])); }
-#line 2592 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2594 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 87:
-#line 612 "src/parse-gram.y" /* yacc.c:1646  */
+#line 612 "src/parse-gram.y" /* yacc.c:1648  */
     { grammar_current_rule_begin (current_lhs_symbol, current_lhs_location,
                                   current_lhs_named_ref); }
-#line 2599 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2601 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 88:
-#line 615 "src/parse-gram.y" /* yacc.c:1646  */
+#line 615 "src/parse-gram.y" /* yacc.c:1648  */
     { grammar_current_rule_symbol_append ((yyvsp[-1].symbol), (yylsp[-1]), (yyvsp[0].named_ref)); }
-#line 2605 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2607 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 89:
-#line 617 "src/parse-gram.y" /* yacc.c:1646  */
+#line 617 "src/parse-gram.y" /* yacc.c:1648  */
     { grammar_current_rule_action_append ((yyvsp[-1].code), (yylsp[-1]), (yyvsp[0].named_ref), false); }
-#line 2611 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2613 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 90:
-#line 619 "src/parse-gram.y" /* yacc.c:1646  */
+#line 619 "src/parse-gram.y" /* yacc.c:1648  */
     { grammar_current_rule_action_append ((yyvsp[0].code), (yylsp[0]), NULL, true); }
-#line 2617 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2619 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 91:
-#line 621 "src/parse-gram.y" /* yacc.c:1646  */
+#line 621 "src/parse-gram.y" /* yacc.c:1648  */
     { grammar_current_rule_empty_set ((yylsp[0])); }
-#line 2623 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2625 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 92:
-#line 623 "src/parse-gram.y" /* yacc.c:1646  */
+#line 623 "src/parse-gram.y" /* yacc.c:1648  */
     { grammar_current_rule_prec_set ((yyvsp[0].symbol), (yylsp[0])); }
-#line 2629 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2631 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 93:
-#line 625 "src/parse-gram.y" /* yacc.c:1646  */
+#line 625 "src/parse-gram.y" /* yacc.c:1648  */
     { grammar_current_rule_dprec_set ((yyvsp[0].integer), (yylsp[0])); }
-#line 2635 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2637 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 94:
-#line 627 "src/parse-gram.y" /* yacc.c:1646  */
+#line 627 "src/parse-gram.y" /* yacc.c:1648  */
     { grammar_current_rule_merge_set ((yyvsp[0].uniqstr), (yylsp[0])); }
-#line 2641 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2643 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 95:
-#line 631 "src/parse-gram.y" /* yacc.c:1646  */
+#line 631 "src/parse-gram.y" /* yacc.c:1648  */
     { (yyval.named_ref) = 0; }
-#line 2647 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2649 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 96:
-#line 632 "src/parse-gram.y" /* yacc.c:1646  */
+#line 632 "src/parse-gram.y" /* yacc.c:1648  */
     { (yyval.named_ref) = named_ref_new ((yyvsp[0].uniqstr), (yylsp[0])); }
-#line 2653 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2655 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 98:
-#line 643 "src/parse-gram.y" /* yacc.c:1646  */
+#line 643 "src/parse-gram.y" /* yacc.c:1648  */
     { (yyval.uniqstr) = uniqstr_new ((yyvsp[0].code)); }
-#line 2659 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2661 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 99:
-#line 668 "src/parse-gram.y" /* yacc.c:1646  */
+#line 668 "src/parse-gram.y" /* yacc.c:1648  */
     { (yyval.value).kind = muscle_keyword; (yyval.value).chars = ""; }
-#line 2665 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2667 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 100:
-#line 669 "src/parse-gram.y" /* yacc.c:1646  */
+#line 669 "src/parse-gram.y" /* yacc.c:1648  */
     { (yyval.value).kind = muscle_keyword; (yyval.value).chars = (yyvsp[0].uniqstr); }
-#line 2671 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2673 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 101:
-#line 670 "src/parse-gram.y" /* yacc.c:1646  */
+#line 670 "src/parse-gram.y" /* yacc.c:1648  */
     { (yyval.value).kind = muscle_string;  (yyval.value).chars = (yyvsp[0].code); }
-#line 2677 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2679 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 102:
-#line 671 "src/parse-gram.y" /* yacc.c:1646  */
+#line 671 "src/parse-gram.y" /* yacc.c:1648  */
     { (yyval.value).kind = muscle_code;    (yyval.value).chars = strip_braces ((yyvsp[0].code)); }
-#line 2683 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2685 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 103:
-#line 684 "src/parse-gram.y" /* yacc.c:1646  */
+#line 684 "src/parse-gram.y" /* yacc.c:1648  */
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
-#line 2689 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2691 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 104:
-#line 686 "src/parse-gram.y" /* yacc.c:1646  */
+#line 686 "src/parse-gram.y" /* yacc.c:1648  */
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[0].character)), (yylsp[0]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
       symbol_user_token_number_set ((yyval.symbol), (yyvsp[0].character), (yylsp[0]));
     }
-#line 2699 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2701 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 105:
-#line 694 "src/parse-gram.y" /* yacc.c:1646  */
+#line 694 "src/parse-gram.y" /* yacc.c:1648  */
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
-#line 2705 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2707 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 108:
-#line 706 "src/parse-gram.y" /* yacc.c:1646  */
+#line 706 "src/parse-gram.y" /* yacc.c:1648  */
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[0].code)), (yylsp[0]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
     }
-#line 2714 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2716 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 110:
-#line 715 "src/parse-gram.y" /* yacc.c:1646  */
+#line 715 "src/parse-gram.y" /* yacc.c:1648  */
     {
       muscle_code_grow ("epilogue", translate_code ((yyvsp[0].code), (yylsp[0]), true), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2723 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2725 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
 
-#line 2727 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2729 "src/parse-gram.c" /* yacc.c:1648  */
         default: break;
       }
     if (yychar_backup != yychar)
@@ -2853,7 +2854,6 @@ yyerrorlab:
   if (/*CONSTCOND*/ 0)
      goto yyerrorlab;
 
-  yyerror_range[1] = yylsp[1-yylen];
   /* Do not reclaim the symbols of the rule whose action triggered
      this YYERROR.  */
   YYPOPSTACK (yylen);
@@ -2971,7 +2971,7 @@ yyreturn:
 #endif
   return yyresult;
 }
-#line 721 "src/parse-gram.y" /* yacc.c:1906  */
+#line 721 "src/parse-gram.y" /* yacc.c:1907  */
 
 
 /* Return the location of the left-hand side of a rule whose
