@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 2.4.311-ba5c-dirty.  */
+/* A Bison parser, made by GNU Bison 2.4.323-f8e7-dirty.  */
 
 /* Implementation for Bison's Yacc-like parsers in C
 
@@ -45,7 +45,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "2.4.311-ba5c-dirty"
+#define YYBISON_VERSION "2.4.323-f8e7-dirty"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -606,17 +606,17 @@ static const yytype_uint8 yytranslate[] =
   /* YYRLINEYYN -- Source line where rule number YYN was defined.    */
 static const yytype_uint16 yyrline[] =
 {
-       0,   201,   201,   209,   211,   215,   216,   226,   230,   234,
-     235,   240,   241,   242,   243,   244,   249,   258,   259,   260,
-     261,   262,   263,   264,   265,   266,   267,   268,   292,   293,
-     294,   295,   299,   300,   301,   305,   312,   319,   323,   327,
-     334,   349,   350,   354,   366,   366,   371,   371,   376,   387,
-     402,   403,   404,   405,   409,   410,   415,   417,   422,   423,
-     428,   430,   435,   436,   440,   441,   442,   443,   448,   453,
-     458,   464,   470,   481,   482,   491,   492,   498,   499,   500,
-     507,   507,   511,   512,   513,   518,   519,   521,   523,   525,
-     527,   539,   540,   545,   546,   555,   575,   577,   586,   591,
-     592,   597,   604,   606
+       0,   201,   201,   209,   211,   215,   216,   226,   230,   235,
+     236,   241,   242,   243,   244,   245,   250,   259,   260,   261,
+     262,   263,   264,   265,   266,   267,   268,   269,   293,   294,
+     295,   296,   300,   301,   302,   306,   313,   320,   324,   328,
+     335,   350,   351,   355,   367,   367,   372,   372,   377,   388,
+     403,   404,   405,   406,   410,   411,   416,   418,   423,   424,
+     429,   431,   436,   437,   441,   442,   443,   444,   449,   454,
+     459,   465,   471,   482,   483,   492,   493,   499,   500,   501,
+     508,   508,   512,   513,   514,   519,   520,   522,   524,   526,
+     528,   540,   541,   546,   547,   556,   576,   578,   587,   592,
+     593,   598,   605,   607
 };
 #endif
 
@@ -1864,77 +1864,78 @@ yyreduce:
 /* Line 1380 of yacc.c  */
 #line 231 "parse-gram.y"
     {
-      muscle_percent_define_insert ((yyvsp[-1].uniqstr), (yylsp[-1]), (yyvsp[0].chars));
+      muscle_percent_define_insert ((yyvsp[-1].uniqstr), (yylsp[-1]), (yyvsp[0].chars),
+                                    MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
     }
 /* Line 1380 of yacc.c  */
-#line 1871 "src/parse-gram.c"
+#line 1872 "src/parse-gram.c"
     break;
 
   case 9:
 /* Line 1380 of yacc.c  */
-#line 234 "parse-gram.y"
+#line 235 "parse-gram.y"
     { defines_flag = true; }
 /* Line 1380 of yacc.c  */
-#line 1879 "src/parse-gram.c"
+#line 1880 "src/parse-gram.c"
     break;
 
   case 10:
 /* Line 1380 of yacc.c  */
-#line 236 "parse-gram.y"
+#line 237 "parse-gram.y"
     {
       defines_flag = true;
       spec_defines_file = xstrdup ((yyvsp[0].chars));
     }
 /* Line 1380 of yacc.c  */
-#line 1890 "src/parse-gram.c"
+#line 1891 "src/parse-gram.c"
     break;
 
   case 11:
 /* Line 1380 of yacc.c  */
-#line 240 "parse-gram.y"
+#line 241 "parse-gram.y"
     { expected_sr_conflicts = (yyvsp[0].integer); }
 /* Line 1380 of yacc.c  */
-#line 1898 "src/parse-gram.c"
+#line 1899 "src/parse-gram.c"
     break;
 
   case 12:
 /* Line 1380 of yacc.c  */
-#line 241 "parse-gram.y"
+#line 242 "parse-gram.y"
     { expected_rr_conflicts = (yyvsp[0].integer); }
 /* Line 1380 of yacc.c  */
-#line 1906 "src/parse-gram.c"
+#line 1907 "src/parse-gram.c"
     break;
 
   case 13:
 /* Line 1380 of yacc.c  */
-#line 242 "parse-gram.y"
+#line 243 "parse-gram.y"
     { spec_file_prefix = (yyvsp[0].chars); }
 /* Line 1380 of yacc.c  */
-#line 1914 "src/parse-gram.c"
+#line 1915 "src/parse-gram.c"
     break;
 
   case 14:
 /* Line 1380 of yacc.c  */
-#line 243 "parse-gram.y"
+#line 244 "parse-gram.y"
     { spec_file_prefix = (yyvsp[0].chars); }
 /* Line 1380 of yacc.c  */
-#line 1922 "src/parse-gram.c"
+#line 1923 "src/parse-gram.c"
     break;
 
   case 15:
 /* Line 1380 of yacc.c  */
-#line 245 "parse-gram.y"
+#line 246 "parse-gram.y"
     {
       nondeterministic_parser = true;
       glr_parser = true;
     }
 /* Line 1380 of yacc.c  */
-#line 1933 "src/parse-gram.c"
+#line 1934 "src/parse-gram.c"
     break;
 
   case 16:
 /* Line 1380 of yacc.c  */
-#line 250 "parse-gram.y"
+#line 251 "parse-gram.y"
     {
       code_props action;
       code_props_symbol_action_init (&action, (yyvsp[0].code), (yylsp[0]));
@@ -1944,92 +1945,92 @@ yyreduce:
       code_scanner_last_string_free ();
     }
 /* Line 1380 of yacc.c  */
-#line 1948 "src/parse-gram.c"
+#line 1949 "src/parse-gram.c"
     break;
 
   case 17:
 /* Line 1380 of yacc.c  */
-#line 258 "parse-gram.y"
+#line 259 "parse-gram.y"
     { language_argmatch ((yyvsp[0].chars), grammar_prio, (yylsp[-1])); }
 /* Line 1380 of yacc.c  */
-#line 1956 "src/parse-gram.c"
+#line 1957 "src/parse-gram.c"
     break;
 
   case 18:
 /* Line 1380 of yacc.c  */
-#line 259 "parse-gram.y"
+#line 260 "parse-gram.y"
     { add_param ("lex_param", (yyvsp[0].code), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 1964 "src/parse-gram.c"
+#line 1965 "src/parse-gram.c"
     break;
 
   case 19:
 /* Line 1380 of yacc.c  */
-#line 260 "parse-gram.y"
+#line 261 "parse-gram.y"
     { spec_name_prefix = (yyvsp[0].chars); }
 /* Line 1380 of yacc.c  */
-#line 1972 "src/parse-gram.c"
+#line 1973 "src/parse-gram.c"
     break;
 
   case 20:
 /* Line 1380 of yacc.c  */
-#line 261 "parse-gram.y"
+#line 262 "parse-gram.y"
     { spec_name_prefix = (yyvsp[0].chars); }
 /* Line 1380 of yacc.c  */
-#line 1980 "src/parse-gram.c"
+#line 1981 "src/parse-gram.c"
     break;
 
   case 21:
 /* Line 1380 of yacc.c  */
-#line 262 "parse-gram.y"
+#line 263 "parse-gram.y"
     { no_lines_flag = true; }
 /* Line 1380 of yacc.c  */
-#line 1988 "src/parse-gram.c"
+#line 1989 "src/parse-gram.c"
     break;
 
   case 22:
 /* Line 1380 of yacc.c  */
-#line 263 "parse-gram.y"
+#line 264 "parse-gram.y"
     { nondeterministic_parser = true; }
 /* Line 1380 of yacc.c  */
-#line 1996 "src/parse-gram.c"
+#line 1997 "src/parse-gram.c"
     break;
 
   case 23:
 /* Line 1380 of yacc.c  */
-#line 264 "parse-gram.y"
+#line 265 "parse-gram.y"
     { spec_outfile = (yyvsp[0].chars); }
 /* Line 1380 of yacc.c  */
-#line 2004 "src/parse-gram.c"
+#line 2005 "src/parse-gram.c"
     break;
 
   case 24:
 /* Line 1380 of yacc.c  */
-#line 265 "parse-gram.y"
+#line 266 "parse-gram.y"
     { spec_outfile = (yyvsp[0].chars); }
 /* Line 1380 of yacc.c  */
-#line 2012 "src/parse-gram.c"
+#line 2013 "src/parse-gram.c"
     break;
 
   case 25:
 /* Line 1380 of yacc.c  */
-#line 266 "parse-gram.y"
+#line 267 "parse-gram.y"
     { add_param ("parse_param", (yyvsp[0].code), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2020 "src/parse-gram.c"
+#line 2021 "src/parse-gram.c"
     break;
 
   case 26:
 /* Line 1380 of yacc.c  */
-#line 267 "parse-gram.y"
+#line 268 "parse-gram.y"
     { version_check (&(yylsp[0]), (yyvsp[0].chars)); }
 /* Line 1380 of yacc.c  */
-#line 2028 "src/parse-gram.c"
+#line 2029 "src/parse-gram.c"
     break;
 
   case 27:
 /* Line 1380 of yacc.c  */
-#line 269 "parse-gram.y"
+#line 270 "parse-gram.y"
     {
       char const *skeleton_user = (yyvsp[0].chars);
       if (strchr (skeleton_user, '/'))
@@ -2054,46 +2055,46 @@ yyreduce:
       skeleton_arg (skeleton_user, grammar_prio, (yylsp[-1]));
     }
 /* Line 1380 of yacc.c  */
-#line 2058 "src/parse-gram.c"
+#line 2059 "src/parse-gram.c"
     break;
 
   case 28:
 /* Line 1380 of yacc.c  */
-#line 292 "parse-gram.y"
+#line 293 "parse-gram.y"
     { token_table_flag = true; }
 /* Line 1380 of yacc.c  */
-#line 2066 "src/parse-gram.c"
+#line 2067 "src/parse-gram.c"
     break;
 
   case 29:
 /* Line 1380 of yacc.c  */
-#line 293 "parse-gram.y"
+#line 294 "parse-gram.y"
     { report_flag |= report_states; }
 /* Line 1380 of yacc.c  */
-#line 2074 "src/parse-gram.c"
+#line 2075 "src/parse-gram.c"
     break;
 
   case 30:
 /* Line 1380 of yacc.c  */
-#line 294 "parse-gram.y"
+#line 295 "parse-gram.y"
     { yacc_flag = true; }
 /* Line 1380 of yacc.c  */
-#line 2082 "src/parse-gram.c"
+#line 2083 "src/parse-gram.c"
     break;
 
   case 34:
 /* Line 1380 of yacc.c  */
-#line 302 "parse-gram.y"
+#line 303 "parse-gram.y"
     {
       grammar_start_symbol_set ((yyvsp[0].symbol), (yylsp[0]));
     }
 /* Line 1380 of yacc.c  */
-#line 2092 "src/parse-gram.c"
+#line 2093 "src/parse-gram.c"
     break;
 
   case 35:
 /* Line 1380 of yacc.c  */
-#line 306 "parse-gram.y"
+#line 307 "parse-gram.y"
     {
       symbol_list *list;
       for (list = (yyvsp[0].list); list; list = list->next)
@@ -2101,12 +2102,12 @@ yyreduce:
       symbol_list_free ((yyvsp[0].list));
     }
 /* Line 1380 of yacc.c  */
-#line 2105 "src/parse-gram.c"
+#line 2106 "src/parse-gram.c"
     break;
 
   case 36:
 /* Line 1380 of yacc.c  */
-#line 313 "parse-gram.y"
+#line 314 "parse-gram.y"
     {
       symbol_list *list;
       for (list = (yyvsp[0].list); list; list = list->next)
@@ -2114,32 +2115,32 @@ yyreduce:
       symbol_list_free ((yyvsp[0].list));
     }
 /* Line 1380 of yacc.c  */
-#line 2118 "src/parse-gram.c"
+#line 2119 "src/parse-gram.c"
     break;
 
   case 37:
 /* Line 1380 of yacc.c  */
-#line 320 "parse-gram.y"
+#line 321 "parse-gram.y"
     {
       default_prec = true;
     }
 /* Line 1380 of yacc.c  */
-#line 2128 "src/parse-gram.c"
+#line 2129 "src/parse-gram.c"
     break;
 
   case 38:
 /* Line 1380 of yacc.c  */
-#line 324 "parse-gram.y"
+#line 325 "parse-gram.y"
     {
       default_prec = false;
     }
 /* Line 1380 of yacc.c  */
-#line 2138 "src/parse-gram.c"
+#line 2139 "src/parse-gram.c"
     break;
 
   case 39:
 /* Line 1380 of yacc.c  */
-#line 328 "parse-gram.y"
+#line 329 "parse-gram.y"
     {
       /* Do not invoke muscle_percent_code_grow here since it invokes
          muscle_user_name_list_grow.  */
@@ -2147,89 +2148,89 @@ yyreduce:
       code_scanner_last_string_free ();
     }
 /* Line 1380 of yacc.c  */
-#line 2151 "src/parse-gram.c"
+#line 2152 "src/parse-gram.c"
     break;
 
   case 40:
 /* Line 1380 of yacc.c  */
-#line 335 "parse-gram.y"
+#line 336 "parse-gram.y"
     {
       muscle_percent_code_grow ((yyvsp[-1].uniqstr), (yylsp[-1]), (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
 /* Line 1380 of yacc.c  */
-#line 2162 "src/parse-gram.c"
+#line 2163 "src/parse-gram.c"
     break;
 
   case 41:
 /* Line 1380 of yacc.c  */
-#line 349 "parse-gram.y"
+#line 350 "parse-gram.y"
     {}
 /* Line 1380 of yacc.c  */
-#line 2170 "src/parse-gram.c"
+#line 2171 "src/parse-gram.c"
     break;
 
   case 42:
 /* Line 1380 of yacc.c  */
-#line 350 "parse-gram.y"
+#line 351 "parse-gram.y"
     { muscle_code_grow ("union_name", (yyvsp[0].uniqstr), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2178 "src/parse-gram.c"
+#line 2179 "src/parse-gram.c"
     break;
 
   case 43:
 /* Line 1380 of yacc.c  */
-#line 355 "parse-gram.y"
+#line 356 "parse-gram.y"
     {
       union_seen = true;
       muscle_code_grow ("stype", (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
 /* Line 1380 of yacc.c  */
-#line 2190 "src/parse-gram.c"
+#line 2191 "src/parse-gram.c"
     break;
 
   case 44:
 /* Line 1380 of yacc.c  */
-#line 366 "parse-gram.y"
+#line 367 "parse-gram.y"
     { current_class = nterm_sym; }
 /* Line 1380 of yacc.c  */
-#line 2198 "src/parse-gram.c"
+#line 2199 "src/parse-gram.c"
     break;
 
   case 45:
 /* Line 1380 of yacc.c  */
-#line 367 "parse-gram.y"
+#line 368 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
 /* Line 1380 of yacc.c  */
-#line 2209 "src/parse-gram.c"
+#line 2210 "src/parse-gram.c"
     break;
 
   case 46:
 /* Line 1380 of yacc.c  */
-#line 371 "parse-gram.y"
+#line 372 "parse-gram.y"
     { current_class = token_sym; }
 /* Line 1380 of yacc.c  */
-#line 2217 "src/parse-gram.c"
+#line 2218 "src/parse-gram.c"
     break;
 
   case 47:
 /* Line 1380 of yacc.c  */
-#line 372 "parse-gram.y"
+#line 373 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
 /* Line 1380 of yacc.c  */
-#line 2228 "src/parse-gram.c"
+#line 2229 "src/parse-gram.c"
     break;
 
   case 48:
 /* Line 1380 of yacc.c  */
-#line 377 "parse-gram.y"
+#line 378 "parse-gram.y"
     {
       symbol_list *list;
       tag_seen = true;
@@ -2238,12 +2239,12 @@ yyreduce:
       symbol_list_free ((yyvsp[0].list));
     }
 /* Line 1380 of yacc.c  */
-#line 2242 "src/parse-gram.c"
+#line 2243 "src/parse-gram.c"
     break;
 
   case 49:
 /* Line 1380 of yacc.c  */
-#line 388 "parse-gram.y"
+#line 389 "parse-gram.y"
     {
       symbol_list *list;
       ++current_prec;
@@ -2256,202 +2257,202 @@ yyreduce:
       current_type = NULL;
     }
 /* Line 1380 of yacc.c  */
-#line 2260 "src/parse-gram.c"
+#line 2261 "src/parse-gram.c"
     break;
 
   case 50:
 /* Line 1380 of yacc.c  */
-#line 402 "parse-gram.y"
+#line 403 "parse-gram.y"
     { (yyval.assoc) = left_assoc; }
 /* Line 1380 of yacc.c  */
-#line 2268 "src/parse-gram.c"
+#line 2269 "src/parse-gram.c"
     break;
 
   case 51:
 /* Line 1380 of yacc.c  */
-#line 403 "parse-gram.y"
+#line 404 "parse-gram.y"
     { (yyval.assoc) = right_assoc; }
 /* Line 1380 of yacc.c  */
-#line 2276 "src/parse-gram.c"
+#line 2277 "src/parse-gram.c"
     break;
 
   case 52:
 /* Line 1380 of yacc.c  */
-#line 404 "parse-gram.y"
+#line 405 "parse-gram.y"
     { (yyval.assoc) = non_assoc; }
 /* Line 1380 of yacc.c  */
-#line 2284 "src/parse-gram.c"
+#line 2285 "src/parse-gram.c"
     break;
 
   case 53:
 /* Line 1380 of yacc.c  */
-#line 405 "parse-gram.y"
+#line 406 "parse-gram.y"
     { (yyval.assoc) = precedence_assoc; }
 /* Line 1380 of yacc.c  */
-#line 2292 "src/parse-gram.c"
+#line 2293 "src/parse-gram.c"
     break;
 
   case 54:
 /* Line 1380 of yacc.c  */
-#line 409 "parse-gram.y"
+#line 410 "parse-gram.y"
     { current_type = NULL; }
 /* Line 1380 of yacc.c  */
-#line 2300 "src/parse-gram.c"
+#line 2301 "src/parse-gram.c"
     break;
 
   case 55:
 /* Line 1380 of yacc.c  */
-#line 410 "parse-gram.y"
+#line 411 "parse-gram.y"
     { current_type = (yyvsp[0].uniqstr); tag_seen = true; }
 /* Line 1380 of yacc.c  */
-#line 2308 "src/parse-gram.c"
+#line 2309 "src/parse-gram.c"
     break;
 
   case 56:
 /* Line 1380 of yacc.c  */
-#line 416 "parse-gram.y"
+#line 417 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2316 "src/parse-gram.c"
+#line 2317 "src/parse-gram.c"
     break;
 
   case 57:
 /* Line 1380 of yacc.c  */
-#line 418 "parse-gram.y"
+#line 419 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
 /* Line 1380 of yacc.c  */
-#line 2324 "src/parse-gram.c"
+#line 2325 "src/parse-gram.c"
     break;
 
   case 58:
 /* Line 1380 of yacc.c  */
-#line 422 "parse-gram.y"
+#line 423 "parse-gram.y"
     { (yyval.symbol) = (yyvsp[0].symbol); }
 /* Line 1380 of yacc.c  */
-#line 2332 "src/parse-gram.c"
+#line 2333 "src/parse-gram.c"
     break;
 
   case 59:
 /* Line 1380 of yacc.c  */
-#line 423 "parse-gram.y"
+#line 424 "parse-gram.y"
     { (yyval.symbol) = (yyvsp[-1].symbol); symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2340 "src/parse-gram.c"
+#line 2341 "src/parse-gram.c"
     break;
 
   case 60:
 /* Line 1380 of yacc.c  */
-#line 429 "parse-gram.y"
+#line 430 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2348 "src/parse-gram.c"
+#line 2349 "src/parse-gram.c"
     break;
 
   case 61:
 /* Line 1380 of yacc.c  */
-#line 431 "parse-gram.y"
+#line 432 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
 /* Line 1380 of yacc.c  */
-#line 2356 "src/parse-gram.c"
+#line 2357 "src/parse-gram.c"
     break;
 
   case 62:
 /* Line 1380 of yacc.c  */
-#line 435 "parse-gram.y"
+#line 436 "parse-gram.y"
     { (yyval.list) = (yyvsp[0].list); }
 /* Line 1380 of yacc.c  */
-#line 2364 "src/parse-gram.c"
+#line 2365 "src/parse-gram.c"
     break;
 
   case 63:
 /* Line 1380 of yacc.c  */
-#line 436 "parse-gram.y"
+#line 437 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), (yyvsp[0].list)); }
 /* Line 1380 of yacc.c  */
-#line 2372 "src/parse-gram.c"
+#line 2373 "src/parse-gram.c"
     break;
 
   case 64:
 /* Line 1380 of yacc.c  */
-#line 440 "parse-gram.y"
+#line 441 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2380 "src/parse-gram.c"
+#line 2381 "src/parse-gram.c"
     break;
 
   case 65:
 /* Line 1380 of yacc.c  */
-#line 441 "parse-gram.y"
+#line 442 "parse-gram.y"
     { (yyval.list) = symbol_list_type_new ((yyvsp[0].uniqstr), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2388 "src/parse-gram.c"
+#line 2389 "src/parse-gram.c"
     break;
 
   case 66:
 /* Line 1380 of yacc.c  */
-#line 442 "parse-gram.y"
+#line 443 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagged_new ((yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2396 "src/parse-gram.c"
+#line 2397 "src/parse-gram.c"
     break;
 
   case 67:
 /* Line 1380 of yacc.c  */
-#line 443 "parse-gram.y"
+#line 444 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagless_new ((yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2404 "src/parse-gram.c"
+#line 2405 "src/parse-gram.c"
     break;
 
   case 68:
 /* Line 1380 of yacc.c  */
-#line 449 "parse-gram.y"
+#line 450 "parse-gram.y"
     {
        current_type = (yyvsp[0].uniqstr);
        tag_seen = true;
      }
 /* Line 1380 of yacc.c  */
-#line 2415 "src/parse-gram.c"
+#line 2416 "src/parse-gram.c"
     break;
 
   case 69:
 /* Line 1380 of yacc.c  */
-#line 454 "parse-gram.y"
+#line 455 "parse-gram.y"
     {
        symbol_class_set ((yyvsp[0].symbol), current_class, (yylsp[0]), true);
        symbol_type_set ((yyvsp[0].symbol), current_type, (yylsp[0]));
      }
 /* Line 1380 of yacc.c  */
-#line 2426 "src/parse-gram.c"
+#line 2427 "src/parse-gram.c"
     break;
 
   case 70:
 /* Line 1380 of yacc.c  */
-#line 459 "parse-gram.y"
+#line 460 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[-1].symbol), current_class, (yylsp[-1]), true);
       symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
       symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0]));
     }
 /* Line 1380 of yacc.c  */
-#line 2438 "src/parse-gram.c"
+#line 2439 "src/parse-gram.c"
     break;
 
   case 71:
 /* Line 1380 of yacc.c  */
-#line 465 "parse-gram.y"
+#line 466 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[-1].symbol), current_class, (yylsp[-1]), true);
       symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
       symbol_make_alias ((yyvsp[-1].symbol), (yyvsp[0].symbol), (yyloc));
     }
 /* Line 1380 of yacc.c  */
-#line 2450 "src/parse-gram.c"
+#line 2451 "src/parse-gram.c"
     break;
 
   case 72:
 /* Line 1380 of yacc.c  */
-#line 471 "parse-gram.y"
+#line 472 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[-2].symbol), current_class, (yylsp[-2]), true);
       symbol_type_set ((yyvsp[-2].symbol), current_type, (yylsp[-2]));
@@ -2459,110 +2460,110 @@ yyreduce:
       symbol_make_alias ((yyvsp[-2].symbol), (yyvsp[0].symbol), (yyloc));
     }
 /* Line 1380 of yacc.c  */
-#line 2463 "src/parse-gram.c"
+#line 2464 "src/parse-gram.c"
     break;
 
   case 79:
 /* Line 1380 of yacc.c  */
-#line 501 "parse-gram.y"
+#line 502 "parse-gram.y"
     {
       yyerrok;
     }
 /* Line 1380 of yacc.c  */
-#line 2473 "src/parse-gram.c"
+#line 2474 "src/parse-gram.c"
     break;
 
   case 80:
 /* Line 1380 of yacc.c  */
-#line 507 "parse-gram.y"
+#line 508 "parse-gram.y"
     { current_lhs = (yyvsp[0].symbol); current_lhs_location = (yylsp[0]); }
 /* Line 1380 of yacc.c  */
-#line 2481 "src/parse-gram.c"
+#line 2482 "src/parse-gram.c"
     break;
 
   case 82:
 /* Line 1380 of yacc.c  */
-#line 511 "parse-gram.y"
+#line 512 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2489 "src/parse-gram.c"
+#line 2490 "src/parse-gram.c"
     break;
 
   case 83:
 /* Line 1380 of yacc.c  */
-#line 512 "parse-gram.y"
+#line 513 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2497 "src/parse-gram.c"
+#line 2498 "src/parse-gram.c"
     break;
 
   case 85:
 /* Line 1380 of yacc.c  */
-#line 518 "parse-gram.y"
+#line 519 "parse-gram.y"
     { grammar_current_rule_begin (current_lhs, current_lhs_location); }
 /* Line 1380 of yacc.c  */
-#line 2505 "src/parse-gram.c"
+#line 2506 "src/parse-gram.c"
     break;
 
   case 86:
 /* Line 1380 of yacc.c  */
-#line 520 "parse-gram.y"
+#line 521 "parse-gram.y"
     { grammar_current_rule_symbol_append ((yyvsp[0].symbol), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2513 "src/parse-gram.c"
+#line 2514 "src/parse-gram.c"
     break;
 
   case 87:
 /* Line 1380 of yacc.c  */
-#line 522 "parse-gram.y"
+#line 523 "parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[0].code), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2521 "src/parse-gram.c"
+#line 2522 "src/parse-gram.c"
     break;
 
   case 88:
 /* Line 1380 of yacc.c  */
-#line 524 "parse-gram.y"
+#line 525 "parse-gram.y"
     { grammar_current_rule_prec_set ((yyvsp[0].symbol), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2529 "src/parse-gram.c"
+#line 2530 "src/parse-gram.c"
     break;
 
   case 89:
 /* Line 1380 of yacc.c  */
-#line 526 "parse-gram.y"
+#line 527 "parse-gram.y"
     { grammar_current_rule_dprec_set ((yyvsp[0].integer), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2537 "src/parse-gram.c"
+#line 2538 "src/parse-gram.c"
     break;
 
   case 90:
 /* Line 1380 of yacc.c  */
-#line 528 "parse-gram.y"
+#line 529 "parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[0].uniqstr), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2545 "src/parse-gram.c"
+#line 2546 "src/parse-gram.c"
     break;
 
   case 92:
 /* Line 1380 of yacc.c  */
-#line 540 "parse-gram.y"
+#line 541 "parse-gram.y"
     { (yyval.uniqstr) = uniqstr_new ((yyvsp[0].chars)); }
 /* Line 1380 of yacc.c  */
-#line 2553 "src/parse-gram.c"
+#line 2554 "src/parse-gram.c"
     break;
 
   case 93:
 /* Line 1380 of yacc.c  */
-#line 545 "parse-gram.y"
+#line 546 "parse-gram.y"
     { (yyval.chars) = ""; }
 /* Line 1380 of yacc.c  */
-#line 2561 "src/parse-gram.c"
+#line 2562 "src/parse-gram.c"
     break;
 
   case 95:
 /* Line 1380 of yacc.c  */
-#line 556 "parse-gram.y"
+#line 557 "parse-gram.y"
     {
       code_props plain_code;
       (yyvsp[0].code)[strlen ((yyvsp[0].code)) - 1] = '\n';
@@ -2572,51 +2573,51 @@ yyreduce:
       (yyval.chars) = plain_code.code;
     }
 /* Line 1380 of yacc.c  */
-#line 2576 "src/parse-gram.c"
+#line 2577 "src/parse-gram.c"
     break;
 
   case 96:
 /* Line 1380 of yacc.c  */
-#line 576 "parse-gram.y"
+#line 577 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2584 "src/parse-gram.c"
+#line 2585 "src/parse-gram.c"
     break;
 
   case 97:
 /* Line 1380 of yacc.c  */
-#line 578 "parse-gram.y"
+#line 579 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[0].character)), (yylsp[0]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
       symbol_user_token_number_set ((yyval.symbol), (yyvsp[0].character), (yylsp[0]));
     }
 /* Line 1380 of yacc.c  */
-#line 2596 "src/parse-gram.c"
+#line 2597 "src/parse-gram.c"
     break;
 
   case 98:
 /* Line 1380 of yacc.c  */
-#line 586 "parse-gram.y"
+#line 587 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2604 "src/parse-gram.c"
+#line 2605 "src/parse-gram.c"
     break;
 
   case 101:
 /* Line 1380 of yacc.c  */
-#line 598 "parse-gram.y"
+#line 599 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[0].chars)), (yylsp[0]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
     }
 /* Line 1380 of yacc.c  */
-#line 2615 "src/parse-gram.c"
+#line 2616 "src/parse-gram.c"
     break;
 
   case 103:
 /* Line 1380 of yacc.c  */
-#line 607 "parse-gram.y"
+#line 608 "parse-gram.y"
     {
       code_props plain_code;
       code_props_plain_init (&plain_code, (yyvsp[0].chars), (yylsp[0]));
@@ -2626,12 +2627,12 @@ yyreduce:
       code_scanner_last_string_free ();
     }
 /* Line 1380 of yacc.c  */
-#line 2630 "src/parse-gram.c"
+#line 2631 "src/parse-gram.c"
     break;
 
 
 /* Line 1380 of yacc.c  */
-#line 2635 "src/parse-gram.c"
+#line 2636 "src/parse-gram.c"
       default: break;
     }
   YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);
@@ -2848,7 +2849,7 @@ yyreturn:
 }
 
 /* Line 1599 of yacc.c  */
-#line 617 "parse-gram.y"
+#line 618 "parse-gram.y"
 
 
 
