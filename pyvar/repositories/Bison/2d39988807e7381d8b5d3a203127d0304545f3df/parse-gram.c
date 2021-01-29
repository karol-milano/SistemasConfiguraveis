@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 2.4.403-43f2.  */
+/* A Bison parser, made by GNU Bison 2.4.404-c6ab.  */
 
 /* Implementation for Bison's Yacc-like parsers in C
 
@@ -45,7 +45,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "2.4.403-43f2"
+#define YYBISON_VERSION "2.4.404-c6ab"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -645,17 +645,17 @@ static const yytype_uint8 yytranslate[] =
   /* YYRLINEYYN -- Source line where rule number YYN was defined.    */
 static const yytype_uint16 yyrline[] =
 {
-       0,   249,   249,   257,   259,   263,   264,   274,   278,   283,
-     284,   289,   294,   295,   296,   297,   298,   303,   312,   313,
-     314,   315,   316,   317,   318,   319,   319,   320,   321,   345,
-     346,   347,   348,   352,   353,   362,   363,   364,   368,   375,
-     382,   386,   390,   397,   412,   413,   417,   429,   429,   434,
-     434,   439,   450,   465,   466,   467,   468,   472,   473,   478,
-     480,   485,   486,   491,   493,   498,   499,   503,   504,   505,
-     506,   511,   516,   521,   527,   533,   544,   545,   554,   555,
-     561,   562,   563,   570,   570,   575,   576,   577,   582,   584,
-     586,   588,   590,   592,   597,   599,   610,   611,   616,   617,
-     618,   627,   647,   649,   658,   663,   664,   669,   676,   678
+       0,   250,   250,   258,   260,   264,   265,   275,   279,   284,
+     285,   290,   295,   296,   297,   298,   299,   304,   313,   314,
+     315,   316,   317,   318,   319,   320,   320,   321,   322,   346,
+     347,   348,   349,   353,   354,   363,   364,   365,   369,   376,
+     383,   387,   391,   398,   413,   414,   418,   430,   430,   435,
+     435,   440,   451,   466,   467,   468,   469,   473,   474,   479,
+     481,   486,   487,   492,   494,   499,   500,   504,   505,   506,
+     507,   512,   517,   522,   528,   534,   545,   546,   555,   556,
+     562,   563,   564,   571,   571,   576,   577,   578,   583,   585,
+     587,   589,   591,   593,   598,   600,   611,   612,   617,   618,
+     619,   628,   648,   650,   659,   664,   665,   670,   677,   679
 };
 #endif
 
@@ -1127,10 +1127,11 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
       CASE(parse, parse-param);
       CASE(both,  param);
 #undef CASE
+      case param_none: aver (false); break;
     }
 }
 /* Line 653 of yacc.c  */
-#line 1134 "src/parse-gram.c"
+#line 1135 "src/parse-gram.c"
         break;
 
             case 84: // variable
@@ -1139,7 +1140,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 #line 182 "src/parse-gram.y"
         { fputs (((*yyvaluep).uniqstr), stderr); }
 /* Line 653 of yacc.c  */
-#line 1143 "src/parse-gram.c"
+#line 1144 "src/parse-gram.c"
         break;
 
             case 85: // content.opt
@@ -1148,7 +1149,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 #line 177 "src/parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); }
 /* Line 653 of yacc.c  */
-#line 1152 "src/parse-gram.c"
+#line 1153 "src/parse-gram.c"
         break;
 
             case 86: // braceless
@@ -1157,7 +1158,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 #line 177 "src/parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); }
 /* Line 653 of yacc.c  */
-#line 1161 "src/parse-gram.c"
+#line 1162 "src/parse-gram.c"
         break;
 
             case 87: // id
@@ -1166,7 +1167,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 #line 191 "src/parse-gram.y"
         { fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); }
 /* Line 653 of yacc.c  */
-#line 1170 "src/parse-gram.c"
+#line 1171 "src/parse-gram.c"
         break;
 
             case 88: // id_colon
@@ -1175,7 +1176,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 #line 192 "src/parse-gram.y"
         { fprintf (stderr, "%s:", ((*yyvaluep).symbol)->tag); }
 /* Line 653 of yacc.c  */
-#line 1179 "src/parse-gram.c"
+#line 1180 "src/parse-gram.c"
         break;
 
             case 89: // symbol
@@ -1184,7 +1185,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 #line 191 "src/parse-gram.y"
         { fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); }
 /* Line 653 of yacc.c  */
-#line 1188 "src/parse-gram.c"
+#line 1189 "src/parse-gram.c"
         break;
 
             case 90: // string_as_id
@@ -1193,7 +1194,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 #line 191 "src/parse-gram.y"
         { fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); }
 /* Line 653 of yacc.c  */
-#line 1197 "src/parse-gram.c"
+#line 1198 "src/parse-gram.c"
         break;
 
       default:
@@ -1717,7 +1718,7 @@ YYLTYPE yylloc;
   boundary_set (&yylloc.end, current_file, 1, 1);
 }
 /* Line 1175 of yacc.c  */
-#line 1721 "src/parse-gram.c"
+#line 1722 "src/parse-gram.c"
   yylsp[0] = yylloc;
 
   goto yysetstate;
@@ -1904,7 +1905,7 @@ yyreduce:
     {
         case 6:
 /* Line 1388 of yacc.c  */
-#line 265 "src/parse-gram.y"
+#line 266 "src/parse-gram.y"
     {
       code_props plain_code;
       code_props_plain_init (&plain_code, (yyvsp[0].chars), (yylsp[0]));
@@ -1915,106 +1916,106 @@ yyreduce:
       code_scanner_last_string_free ();
     }
 /* Line 1388 of yacc.c  */
-#line 1919 "src/parse-gram.c"
+#line 1920 "src/parse-gram.c"
     break;
 
   case 7:
 /* Line 1388 of yacc.c  */
-#line 275 "src/parse-gram.y"
+#line 276 "src/parse-gram.y"
     {
       muscle_percent_define_ensure ((yyvsp[0].uniqstr), (yylsp[0]), true);
     }
 /* Line 1388 of yacc.c  */
-#line 1929 "src/parse-gram.c"
+#line 1930 "src/parse-gram.c"
     break;
 
   case 8:
 /* Line 1388 of yacc.c  */
-#line 279 "src/parse-gram.y"
+#line 280 "src/parse-gram.y"
     {
       muscle_percent_define_insert ((yyvsp[-1].uniqstr), (yylsp[-1]), (yyvsp[0].chars),
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
     }
 /* Line 1388 of yacc.c  */
-#line 1940 "src/parse-gram.c"
+#line 1941 "src/parse-gram.c"
     break;
 
   case 9:
 /* Line 1388 of yacc.c  */
-#line 283 "src/parse-gram.y"
+#line 284 "src/parse-gram.y"
     { defines_flag = true; }
 /* Line 1388 of yacc.c  */
-#line 1948 "src/parse-gram.c"
+#line 1949 "src/parse-gram.c"
     break;
 
   case 10:
 /* Line 1388 of yacc.c  */
-#line 285 "src/parse-gram.y"
+#line 286 "src/parse-gram.y"
     {
       defines_flag = true;
       spec_defines_file = xstrdup ((yyvsp[0].chars));
     }
 /* Line 1388 of yacc.c  */
-#line 1959 "src/parse-gram.c"
+#line 1960 "src/parse-gram.c"
     break;
 
   case 11:
 /* Line 1388 of yacc.c  */
-#line 290 "src/parse-gram.y"
+#line 291 "src/parse-gram.y"
     {
       muscle_percent_define_insert ("parse.error", (yylsp[0]), "verbose",
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
     }
 /* Line 1388 of yacc.c  */
-#line 1970 "src/parse-gram.c"
+#line 1971 "src/parse-gram.c"
     break;
 
   case 12:
 /* Line 1388 of yacc.c  */
-#line 294 "src/parse-gram.y"
+#line 295 "src/parse-gram.y"
     { expected_sr_conflicts = (yyvsp[0].integer); }
 /* Line 1388 of yacc.c  */
-#line 1978 "src/parse-gram.c"
+#line 1979 "src/parse-gram.c"
     break;
 
   case 13:
 /* Line 1388 of yacc.c  */
-#line 295 "src/parse-gram.y"
+#line 296 "src/parse-gram.y"
     { expected_rr_conflicts = (yyvsp[0].integer); }
 /* Line 1388 of yacc.c  */
-#line 1986 "src/parse-gram.c"
+#line 1987 "src/parse-gram.c"
     break;
 
   case 14:
 /* Line 1388 of yacc.c  */
-#line 296 "src/parse-gram.y"
+#line 297 "src/parse-gram.y"
     { spec_file_prefix = (yyvsp[0].chars); }
 /* Line 1388 of yacc.c  */
-#line 1994 "src/parse-gram.c"
+#line 1995 "src/parse-gram.c"
     break;
 
   case 15:
 /* Line 1388 of yacc.c  */
-#line 297 "src/parse-gram.y"
+#line 298 "src/parse-gram.y"
     { spec_file_prefix = (yyvsp[0].chars); }
 /* Line 1388 of yacc.c  */
-#line 2002 "src/parse-gram.c"
+#line 2003 "src/parse-gram.c"
     break;
 
   case 16:
 /* Line 1388 of yacc.c  */
-#line 299 "src/parse-gram.y"
+#line 300 "src/parse-gram.y"
     {
       nondeterministic_parser = true;
       glr_parser = true;
     }
 /* Line 1388 of yacc.c  */
-#line 2013 "src/parse-gram.c"
+#line 2014 "src/parse-gram.c"
     break;
 
   case 17:
 /* Line 1388 of yacc.c  */
-#line 304 "src/parse-gram.y"
+#line 305 "src/parse-gram.y"
     {
       code_props action;
       code_props_symbol_action_init (&action, (yyvsp[0].code), (yylsp[0]));
@@ -2024,92 +2025,92 @@ yyreduce:
       code_scanner_last_string_free ();
     }
 /* Line 1388 of yacc.c  */
-#line 2028 "src/parse-gram.c"
+#line 2029 "src/parse-gram.c"
     break;
 
   case 18:
 /* Line 1388 of yacc.c  */
-#line 312 "src/parse-gram.y"
+#line 313 "src/parse-gram.y"
     { language_argmatch ((yyvsp[0].chars), grammar_prio, (yylsp[-1])); }
 /* Line 1388 of yacc.c  */
-#line 2036 "src/parse-gram.c"
+#line 2037 "src/parse-gram.c"
     break;
 
   case 19:
 /* Line 1388 of yacc.c  */
-#line 313 "src/parse-gram.y"
+#line 314 "src/parse-gram.y"
     { spec_name_prefix = (yyvsp[0].chars); }
 /* Line 1388 of yacc.c  */
-#line 2044 "src/parse-gram.c"
+#line 2045 "src/parse-gram.c"
     break;
 
   case 20:
 /* Line 1388 of yacc.c  */
-#line 314 "src/parse-gram.y"
+#line 315 "src/parse-gram.y"
     { spec_name_prefix = (yyvsp[0].chars); }
 /* Line 1388 of yacc.c  */
-#line 2052 "src/parse-gram.c"
+#line 2053 "src/parse-gram.c"
     break;
 
   case 21:
 /* Line 1388 of yacc.c  */
-#line 315 "src/parse-gram.y"
+#line 316 "src/parse-gram.y"
     { no_lines_flag = true; }
 /* Line 1388 of yacc.c  */
-#line 2060 "src/parse-gram.c"
+#line 2061 "src/parse-gram.c"
     break;
 
   case 22:
 /* Line 1388 of yacc.c  */
-#line 316 "src/parse-gram.y"
+#line 317 "src/parse-gram.y"
     { nondeterministic_parser = true; }
 /* Line 1388 of yacc.c  */
-#line 2068 "src/parse-gram.c"
+#line 2069 "src/parse-gram.c"
     break;
 
   case 23:
 /* Line 1388 of yacc.c  */
-#line 317 "src/parse-gram.y"
+#line 318 "src/parse-gram.y"
     { spec_outfile = (yyvsp[0].chars); }
 /* Line 1388 of yacc.c  */
-#line 2076 "src/parse-gram.c"
+#line 2077 "src/parse-gram.c"
     break;
 
   case 24:
 /* Line 1388 of yacc.c  */
-#line 318 "src/parse-gram.y"
+#line 319 "src/parse-gram.y"
     { spec_outfile = (yyvsp[0].chars); }
 /* Line 1388 of yacc.c  */
-#line 2084 "src/parse-gram.c"
+#line 2085 "src/parse-gram.c"
     break;
 
   case 25:
 /* Line 1388 of yacc.c  */
-#line 319 "src/parse-gram.y"
+#line 320 "src/parse-gram.y"
     { current_param = (yyvsp[0].param); }
 /* Line 1388 of yacc.c  */
-#line 2092 "src/parse-gram.c"
+#line 2093 "src/parse-gram.c"
     break;
 
   case 26:
 /* Line 1388 of yacc.c  */
-#line 319 "src/parse-gram.y"
+#line 320 "src/parse-gram.y"
     { current_param = param_none; }
 /* Line 1388 of yacc.c  */
-#line 2100 "src/parse-gram.c"
+#line 2101 "src/parse-gram.c"
     break;
 
   case 27:
 /* Line 1388 of yacc.c  */
-#line 320 "src/parse-gram.y"
+#line 321 "src/parse-gram.y"
     { version_check (&(yylsp[0]), (yyvsp[0].chars)); }
 /* Line 1388 of yacc.c  */
-#line 2108 "src/parse-gram.c"
+#line 2109 "src/parse-gram.c"
     break;
 
   case 28:
 /* Line 1388 of yacc.c  */
-#line 322 "src/parse-gram.y"
+#line 323 "src/parse-gram.y"
     {
       char const *skeleton_user = (yyvsp[0].chars);
       if (strchr (skeleton_user, '/'))
@@ -2134,62 +2135,62 @@ yyreduce:
       skeleton_arg (skeleton_user, grammar_prio, (yylsp[-1]));
     }
 /* Line 1388 of yacc.c  */
-#line 2138 "src/parse-gram.c"
+#line 2139 "src/parse-gram.c"
     break;
 
   case 29:
 /* Line 1388 of yacc.c  */
-#line 345 "src/parse-gram.y"
+#line 346 "src/parse-gram.y"
     { token_table_flag = true; }
 /* Line 1388 of yacc.c  */
-#line 2146 "src/parse-gram.c"
+#line 2147 "src/parse-gram.c"
     break;
 
   case 30:
 /* Line 1388 of yacc.c  */
-#line 346 "src/parse-gram.y"
+#line 347 "src/parse-gram.y"
     { report_flag |= report_states; }
 /* Line 1388 of yacc.c  */
-#line 2154 "src/parse-gram.c"
+#line 2155 "src/parse-gram.c"
     break;
 
   case 31:
 /* Line 1388 of yacc.c  */
-#line 347 "src/parse-gram.y"
+#line 348 "src/parse-gram.y"
     { yacc_flag = true; }
 /* Line 1388 of yacc.c  */
-#line 2162 "src/parse-gram.c"
+#line 2163 "src/parse-gram.c"
     break;
 
   case 33:
 /* Line 1388 of yacc.c  */
-#line 352 "src/parse-gram.y"
+#line 353 "src/parse-gram.y"
     { add_param (current_param, (yyvsp[0].code), (yylsp[0])); }
 /* Line 1388 of yacc.c  */
-#line 2170 "src/parse-gram.c"
+#line 2171 "src/parse-gram.c"
     break;
 
   case 34:
 /* Line 1388 of yacc.c  */
-#line 353 "src/parse-gram.y"
+#line 354 "src/parse-gram.y"
     { add_param (current_param, (yyvsp[0].code), (yylsp[0])); }
 /* Line 1388 of yacc.c  */
-#line 2178 "src/parse-gram.c"
+#line 2179 "src/parse-gram.c"
     break;
 
   case 37:
 /* Line 1388 of yacc.c  */
-#line 365 "src/parse-gram.y"
+#line 366 "src/parse-gram.y"
     {
       grammar_start_symbol_set ((yyvsp[0].symbol), (yylsp[0]));
     }
 /* Line 1388 of yacc.c  */
-#line 2188 "src/parse-gram.c"
+#line 2189 "src/parse-gram.c"
     break;
 
   case 38:
 /* Line 1388 of yacc.c  */
-#line 369 "src/parse-gram.y"
+#line 370 "src/parse-gram.y"
     {
       symbol_list *list;
       for (list = (yyvsp[0].list); list; list = list->next)
@@ -2197,12 +2198,12 @@ yyreduce:
       symbol_list_free ((yyvsp[0].list));
     }
 /* Line 1388 of yacc.c  */
-#line 2201 "src/parse-gram.c"
+#line 2202 "src/parse-gram.c"
     break;
 
   case 39:
 /* Line 1388 of yacc.c  */
-#line 376 "src/parse-gram.y"
+#line 377 "src/parse-gram.y"
     {
       symbol_list *list;
       for (list = (yyvsp[0].list); list; list = list->next)
@@ -2210,32 +2211,32 @@ yyreduce:
       symbol_list_free ((yyvsp[0].list));
     }
 /* Line 1388 of yacc.c  */
-#line 2214 "src/parse-gram.c"
+#line 2215 "src/parse-gram.c"
     break;
 
   case 40:
 /* Line 1388 of yacc.c  */
-#line 383 "src/parse-gram.y"
+#line 384 "src/parse-gram.y"
     {
       default_prec = true;
     }
 /* Line 1388 of yacc.c  */
-#line 2224 "src/parse-gram.c"
+#line 2225 "src/parse-gram.c"
     break;
 
   case 41:
 /* Line 1388 of yacc.c  */
-#line 387 "src/parse-gram.y"
+#line 388 "src/parse-gram.y"
     {
       default_prec = false;
     }
 /* Line 1388 of yacc.c  */
-#line 2234 "src/parse-gram.c"
+#line 2235 "src/parse-gram.c"
     break;
 
   case 42:
 /* Line 1388 of yacc.c  */
-#line 391 "src/parse-gram.y"
+#line 392 "src/parse-gram.y"
     {
       /* Do not invoke muscle_percent_code_grow here since it invokes
          muscle_user_name_list_grow.  */
@@ -2243,89 +2244,89 @@ yyreduce:
       code_scanner_last_string_free ();
     }
 /* Line 1388 of yacc.c  */
-#line 2247 "src/parse-gram.c"
+#line 2248 "src/parse-gram.c"
     break;
 
   case 43:
 /* Line 1388 of yacc.c  */
-#line 398 "src/parse-gram.y"
+#line 399 "src/parse-gram.y"
     {
       muscle_percent_code_grow ((yyvsp[-1].uniqstr), (yylsp[-1]), (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
 /* Line 1388 of yacc.c  */
-#line 2258 "src/parse-gram.c"
+#line 2259 "src/parse-gram.c"
     break;
 
   case 44:
 /* Line 1388 of yacc.c  */
-#line 412 "src/parse-gram.y"
+#line 413 "src/parse-gram.y"
     {}
 /* Line 1388 of yacc.c  */
-#line 2266 "src/parse-gram.c"
+#line 2267 "src/parse-gram.c"
     break;
 
   case 45:
 /* Line 1388 of yacc.c  */
-#line 413 "src/parse-gram.y"
+#line 414 "src/parse-gram.y"
     { muscle_code_grow ("union_name", (yyvsp[0].uniqstr), (yylsp[0])); }
 /* Line 1388 of yacc.c  */
-#line 2274 "src/parse-gram.c"
+#line 2275 "src/parse-gram.c"
     break;
 
   case 46:
 /* Line 1388 of yacc.c  */
-#line 418 "src/parse-gram.y"
+#line 419 "src/parse-gram.y"
     {
       union_seen = true;
       muscle_code_grow ("stype", (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
 /* Line 1388 of yacc.c  */
-#line 2286 "src/parse-gram.c"
+#line 2287 "src/parse-gram.c"
     break;
 
   case 47:
 /* Line 1388 of yacc.c  */
-#line 429 "src/parse-gram.y"
+#line 430 "src/parse-gram.y"
     { current_class = nterm_sym; }
 /* Line 1388 of yacc.c  */
-#line 2294 "src/parse-gram.c"
+#line 2295 "src/parse-gram.c"
     break;
 
   case 48:
 /* Line 1388 of yacc.c  */
-#line 430 "src/parse-gram.y"
+#line 431 "src/parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
 /* Line 1388 of yacc.c  */
-#line 2305 "src/parse-gram.c"
+#line 2306 "src/parse-gram.c"
     break;
 
   case 49:
 /* Line 1388 of yacc.c  */
-#line 434 "src/parse-gram.y"
+#line 435 "src/parse-gram.y"
     { current_class = token_sym; }
 /* Line 1388 of yacc.c  */
-#line 2313 "src/parse-gram.c"
+#line 2314 "src/parse-gram.c"
     break;
 
   case 50:
 /* Line 1388 of yacc.c  */
-#line 435 "src/parse-gram.y"
+#line 436 "src/parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
 /* Line 1388 of yacc.c  */
-#line 2324 "src/parse-gram.c"
+#line 2325 "src/parse-gram.c"
     break;
 
   case 51:
 /* Line 1388 of yacc.c  */
-#line 440 "src/parse-gram.y"
+#line 441 "src/parse-gram.y"
     {
       symbol_list *list;
       tag_seen = true;
@@ -2334,12 +2335,12 @@ yyreduce:
       symbol_list_free ((yyvsp[0].list));
     }
 /* Line 1388 of yacc.c  */
-#line 2338 "src/parse-gram.c"
+#line 2339 "src/parse-gram.c"
     break;
 
   case 52:
 /* Line 1388 of yacc.c  */
-#line 451 "src/parse-gram.y"
+#line 452 "src/parse-gram.y"
     {
       symbol_list *list;
       ++current_prec;
@@ -2352,202 +2353,202 @@ yyreduce:
       current_type = NULL;
     }
 /* Line 1388 of yacc.c  */
-#line 2356 "src/parse-gram.c"
+#line 2357 "src/parse-gram.c"
     break;
 
   case 53:
 /* Line 1388 of yacc.c  */
-#line 465 "src/parse-gram.y"
+#line 466 "src/parse-gram.y"
     { (yyval.assoc) = left_assoc; }
 /* Line 1388 of yacc.c  */
-#line 2364 "src/parse-gram.c"
+#line 2365 "src/parse-gram.c"
     break;
 
   case 54:
 /* Line 1388 of yacc.c  */
-#line 466 "src/parse-gram.y"
+#line 467 "src/parse-gram.y"
     { (yyval.assoc) = right_assoc; }
 /* Line 1388 of yacc.c  */
-#line 2372 "src/parse-gram.c"
+#line 2373 "src/parse-gram.c"
     break;
 
   case 55:
 /* Line 1388 of yacc.c  */
-#line 467 "src/parse-gram.y"
+#line 468 "src/parse-gram.y"
     { (yyval.assoc) = non_assoc; }
 /* Line 1388 of yacc.c  */
-#line 2380 "src/parse-gram.c"
+#line 2381 "src/parse-gram.c"
     break;
 
   case 56:
 /* Line 1388 of yacc.c  */
-#line 468 "src/parse-gram.y"
+#line 469 "src/parse-gram.y"
     { (yyval.assoc) = precedence_assoc; }
 /* Line 1388 of yacc.c  */
-#line 2388 "src/parse-gram.c"
+#line 2389 "src/parse-gram.c"
     break;
 
   case 57:
 /* Line 1388 of yacc.c  */
-#line 472 "src/parse-gram.y"
+#line 473 "src/parse-gram.y"
     { current_type = NULL; }
 /* Line 1388 of yacc.c  */
-#line 2396 "src/parse-gram.c"
+#line 2397 "src/parse-gram.c"
     break;
 
   case 58:
 /* Line 1388 of yacc.c  */
-#line 473 "src/parse-gram.y"
+#line 474 "src/parse-gram.y"
     { current_type = (yyvsp[0].uniqstr); tag_seen = true; }
 /* Line 1388 of yacc.c  */
-#line 2404 "src/parse-gram.c"
+#line 2405 "src/parse-gram.c"
     break;
 
   case 59:
 /* Line 1388 of yacc.c  */
-#line 479 "src/parse-gram.y"
+#line 480 "src/parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
 /* Line 1388 of yacc.c  */
-#line 2412 "src/parse-gram.c"
+#line 2413 "src/parse-gram.c"
     break;
 
   case 60:
 /* Line 1388 of yacc.c  */
-#line 481 "src/parse-gram.y"
+#line 482 "src/parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
 /* Line 1388 of yacc.c  */
-#line 2420 "src/parse-gram.c"
+#line 2421 "src/parse-gram.c"
     break;
 
   case 61:
 /* Line 1388 of yacc.c  */
-#line 485 "src/parse-gram.y"
+#line 486 "src/parse-gram.y"
     { (yyval.symbol) = (yyvsp[0].symbol); }
 /* Line 1388 of yacc.c  */
-#line 2428 "src/parse-gram.c"
+#line 2429 "src/parse-gram.c"
     break;
 
   case 62:
 /* Line 1388 of yacc.c  */
-#line 486 "src/parse-gram.y"
+#line 487 "src/parse-gram.y"
     { (yyval.symbol) = (yyvsp[-1].symbol); symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0])); }
 /* Line 1388 of yacc.c  */
-#line 2436 "src/parse-gram.c"
+#line 2437 "src/parse-gram.c"
     break;
 
   case 63:
 /* Line 1388 of yacc.c  */
-#line 492 "src/parse-gram.y"
+#line 493 "src/parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
 /* Line 1388 of yacc.c  */
-#line 2444 "src/parse-gram.c"
+#line 2445 "src/parse-gram.c"
     break;
 
   case 64:
 /* Line 1388 of yacc.c  */
-#line 494 "src/parse-gram.y"
+#line 495 "src/parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
 /* Line 1388 of yacc.c  */
-#line 2452 "src/parse-gram.c"
+#line 2453 "src/parse-gram.c"
     break;
 
   case 65:
 /* Line 1388 of yacc.c  */
-#line 498 "src/parse-gram.y"
+#line 499 "src/parse-gram.y"
     { (yyval.list) = (yyvsp[0].list); }
 /* Line 1388 of yacc.c  */
-#line 2460 "src/parse-gram.c"
+#line 2461 "src/parse-gram.c"
     break;
 
   case 66:
 /* Line 1388 of yacc.c  */
-#line 499 "src/parse-gram.y"
+#line 500 "src/parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), (yyvsp[0].list)); }
 /* Line 1388 of yacc.c  */
-#line 2468 "src/parse-gram.c"
+#line 2469 "src/parse-gram.c"
     break;
 
   case 67:
 /* Line 1388 of yacc.c  */
-#line 503 "src/parse-gram.y"
+#line 504 "src/parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
 /* Line 1388 of yacc.c  */
-#line 2476 "src/parse-gram.c"
+#line 2477 "src/parse-gram.c"
     break;
 
   case 68:
 /* Line 1388 of yacc.c  */
-#line 504 "src/parse-gram.y"
+#line 505 "src/parse-gram.y"
     { (yyval.list) = symbol_list_type_new ((yyvsp[0].uniqstr), (yylsp[0])); }
 /* Line 1388 of yacc.c  */
-#line 2484 "src/parse-gram.c"
+#line 2485 "src/parse-gram.c"
     break;
 
   case 69:
 /* Line 1388 of yacc.c  */
-#line 505 "src/parse-gram.y"
+#line 506 "src/parse-gram.y"
     { (yyval.list) = symbol_list_default_tagged_new ((yylsp[0])); }
 /* Line 1388 of yacc.c  */
-#line 2492 "src/parse-gram.c"
+#line 2493 "src/parse-gram.c"
     break;
 
   case 70:
 /* Line 1388 of yacc.c  */
-#line 506 "src/parse-gram.y"
+#line 507 "src/parse-gram.y"
     { (yyval.list) = symbol_list_default_tagless_new ((yylsp[0])); }
 /* Line 1388 of yacc.c  */
-#line 2500 "src/parse-gram.c"
+#line 2501 "src/parse-gram.c"
     break;
 
   case 71:
 /* Line 1388 of yacc.c  */
-#line 512 "src/parse-gram.y"
+#line 513 "src/parse-gram.y"
     {
        current_type = (yyvsp[0].uniqstr);
        tag_seen = true;
      }
 /* Line 1388 of yacc.c  */
-#line 2511 "src/parse-gram.c"
+#line 2512 "src/parse-gram.c"
     break;
 
   case 72:
 /* Line 1388 of yacc.c  */
-#line 517 "src/parse-gram.y"
+#line 518 "src/parse-gram.y"
     {
        symbol_class_set ((yyvsp[0].symbol), current_class, (yylsp[0]), true);
        symbol_type_set ((yyvsp[0].symbol), current_type, (yylsp[0]));
      }
 /* Line 1388 of yacc.c  */
-#line 2522 "src/parse-gram.c"
+#line 2523 "src/parse-gram.c"
     break;
 
   case 73:
 /* Line 1388 of yacc.c  */
-#line 522 "src/parse-gram.y"
+#line 523 "src/parse-gram.y"
     {
       symbol_class_set ((yyvsp[-1].symbol), current_class, (yylsp[-1]), true);
       symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
       symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0]));
     }
 /* Line 1388 of yacc.c  */
-#line 2534 "src/parse-gram.c"
+#line 2535 "src/parse-gram.c"
     break;
 
   case 74:
 /* Line 1388 of yacc.c  */
-#line 528 "src/parse-gram.y"
+#line 529 "src/parse-gram.y"
     {
       symbol_class_set ((yyvsp[-1].symbol), current_class, (yylsp[-1]), true);
       symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
       symbol_make_alias ((yyvsp[-1].symbol), (yyvsp[0].symbol), (yyloc));
     }
 /* Line 1388 of yacc.c  */
-#line 2546 "src/parse-gram.c"
+#line 2547 "src/parse-gram.c"
     break;
 
   case 75:
 /* Line 1388 of yacc.c  */
-#line 534 "src/parse-gram.y"
+#line 535 "src/parse-gram.y"
     {
       symbol_class_set ((yyvsp[-2].symbol), current_class, (yylsp[-2]), true);
       symbol_type_set ((yyvsp[-2].symbol), current_type, (yylsp[-2]));
@@ -2555,136 +2556,136 @@ yyreduce:
       symbol_make_alias ((yyvsp[-2].symbol), (yyvsp[0].symbol), (yyloc));
     }
 /* Line 1388 of yacc.c  */
-#line 2559 "src/parse-gram.c"
+#line 2560 "src/parse-gram.c"
     break;
 
   case 82:
 /* Line 1388 of yacc.c  */
-#line 564 "src/parse-gram.y"
+#line 565 "src/parse-gram.y"
     {
       yyerrok;
     }
 /* Line 1388 of yacc.c  */
-#line 2569 "src/parse-gram.c"
+#line 2570 "src/parse-gram.c"
     break;
 
   case 83:
 /* Line 1388 of yacc.c  */
-#line 570 "src/parse-gram.y"
+#line 571 "src/parse-gram.y"
     { current_lhs = (yyvsp[-1].symbol); current_lhs_location = (yylsp[-1]);
     current_lhs_named_ref = (yyvsp[0].named_ref); }
 /* Line 1388 of yacc.c  */
-#line 2578 "src/parse-gram.c"
+#line 2579 "src/parse-gram.c"
     break;
 
   case 85:
 /* Line 1388 of yacc.c  */
-#line 575 "src/parse-gram.y"
+#line 576 "src/parse-gram.y"
     { grammar_current_rule_end ((yylsp[0])); }
 /* Line 1388 of yacc.c  */
-#line 2586 "src/parse-gram.c"
+#line 2587 "src/parse-gram.c"
     break;
 
   case 86:
 /* Line 1388 of yacc.c  */
-#line 576 "src/parse-gram.y"
+#line 577 "src/parse-gram.y"
     { grammar_current_rule_end ((yylsp[0])); }
 /* Line 1388 of yacc.c  */
-#line 2594 "src/parse-gram.c"
+#line 2595 "src/parse-gram.c"
     break;
 
   case 88:
 /* Line 1388 of yacc.c  */
-#line 582 "src/parse-gram.y"
+#line 583 "src/parse-gram.y"
     { grammar_current_rule_begin (current_lhs, current_lhs_location,
 				  current_lhs_named_ref); }
 /* Line 1388 of yacc.c  */
-#line 2603 "src/parse-gram.c"
+#line 2604 "src/parse-gram.c"
     break;
 
   case 89:
 /* Line 1388 of yacc.c  */
-#line 585 "src/parse-gram.y"
+#line 586 "src/parse-gram.y"
     { grammar_current_rule_symbol_append ((yyvsp[-1].symbol), (yylsp[-1]), (yyvsp[0].named_ref)); }
 /* Line 1388 of yacc.c  */
-#line 2611 "src/parse-gram.c"
+#line 2612 "src/parse-gram.c"
     break;
 
   case 90:
 /* Line 1388 of yacc.c  */
-#line 587 "src/parse-gram.y"
+#line 588 "src/parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[-1].code), (yylsp[-1]), (yyvsp[0].named_ref)); }
 /* Line 1388 of yacc.c  */
-#line 2619 "src/parse-gram.c"
+#line 2620 "src/parse-gram.c"
     break;
 
   case 91:
 /* Line 1388 of yacc.c  */
-#line 589 "src/parse-gram.y"
+#line 590 "src/parse-gram.y"
     { grammar_current_rule_prec_set ((yyvsp[0].symbol), (yylsp[0])); }
 /* Line 1388 of yacc.c  */
-#line 2627 "src/parse-gram.c"
+#line 2628 "src/parse-gram.c"
     break;
 
   case 92:
 /* Line 1388 of yacc.c  */
-#line 591 "src/parse-gram.y"
+#line 592 "src/parse-gram.y"
     { grammar_current_rule_dprec_set ((yyvsp[0].integer), (yylsp[0])); }
 /* Line 1388 of yacc.c  */
-#line 2635 "src/parse-gram.c"
+#line 2636 "src/parse-gram.c"
     break;
 
   case 93:
 /* Line 1388 of yacc.c  */
-#line 593 "src/parse-gram.y"
+#line 594 "src/parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[0].uniqstr), (yylsp[0])); }
 /* Line 1388 of yacc.c  */
-#line 2643 "src/parse-gram.c"
+#line 2644 "src/parse-gram.c"
     break;
 
   case 94:
 /* Line 1388 of yacc.c  */
-#line 597 "src/parse-gram.y"
+#line 598 "src/parse-gram.y"
     { (yyval.named_ref) = 0; }
 /* Line 1388 of yacc.c  */
-#line 2651 "src/parse-gram.c"
+#line 2652 "src/parse-gram.c"
     break;
 
   case 95:
 /* Line 1388 of yacc.c  */
-#line 599 "src/parse-gram.y"
+#line 600 "src/parse-gram.y"
     { (yyval.named_ref) = named_ref_new((yyvsp[0].uniqstr), (yylsp[0])); }
 /* Line 1388 of yacc.c  */
-#line 2659 "src/parse-gram.c"
+#line 2660 "src/parse-gram.c"
     break;
 
   case 97:
 /* Line 1388 of yacc.c  */
-#line 611 "src/parse-gram.y"
+#line 612 "src/parse-gram.y"
     { (yyval.uniqstr) = uniqstr_new ((yyvsp[0].chars)); }
 /* Line 1388 of yacc.c  */
-#line 2667 "src/parse-gram.c"
+#line 2668 "src/parse-gram.c"
     break;
 
   case 98:
 /* Line 1388 of yacc.c  */
-#line 616 "src/parse-gram.y"
+#line 617 "src/parse-gram.y"
     { (yyval.chars) = ""; }
 /* Line 1388 of yacc.c  */
-#line 2675 "src/parse-gram.c"
+#line 2676 "src/parse-gram.c"
     break;
 
   case 99:
 /* Line 1388 of yacc.c  */
-#line 617 "src/parse-gram.y"
+#line 618 "src/parse-gram.y"
     { (yyval.chars) = (yyvsp[0].uniqstr); }
 /* Line 1388 of yacc.c  */
-#line 2683 "src/parse-gram.c"
+#line 2684 "src/parse-gram.c"
     break;
 
   case 101:
 /* Line 1388 of yacc.c  */
-#line 628 "src/parse-gram.y"
+#line 629 "src/parse-gram.y"
     {
       code_props plain_code;
       (yyvsp[0].code)[strlen ((yyvsp[0].code)) - 1] = '\n';
@@ -2694,51 +2695,51 @@ yyreduce:
       (yyval.chars) = plain_code.code;
     }
 /* Line 1388 of yacc.c  */
-#line 2698 "src/parse-gram.c"
+#line 2699 "src/parse-gram.c"
     break;
 
   case 102:
 /* Line 1388 of yacc.c  */
-#line 648 "src/parse-gram.y"
+#line 649 "src/parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
 /* Line 1388 of yacc.c  */
-#line 2706 "src/parse-gram.c"
+#line 2707 "src/parse-gram.c"
     break;
 
   case 103:
 /* Line 1388 of yacc.c  */
-#line 650 "src/parse-gram.y"
+#line 651 "src/parse-gram.y"
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[0].character)), (yylsp[0]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
       symbol_user_token_number_set ((yyval.symbol), (yyvsp[0].character), (yylsp[0]));
     }
 /* Line 1388 of yacc.c  */
-#line 2718 "src/parse-gram.c"
+#line 2719 "src/parse-gram.c"
     break;
 
   case 104:
 /* Line 1388 of yacc.c  */
-#line 658 "src/parse-gram.y"
+#line 659 "src/parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
 /* Line 1388 of yacc.c  */
-#line 2726 "src/parse-gram.c"
+#line 2727 "src/parse-gram.c"
     break;
 
   case 107:
 /* Line 1388 of yacc.c  */
-#line 670 "src/parse-gram.y"
+#line 671 "src/parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[0].chars)), (yylsp[0]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
     }
 /* Line 1388 of yacc.c  */
-#line 2737 "src/parse-gram.c"
+#line 2738 "src/parse-gram.c"
     break;
 
   case 109:
 /* Line 1388 of yacc.c  */
-#line 679 "src/parse-gram.y"
+#line 680 "src/parse-gram.y"
     {
       code_props plain_code;
       code_props_plain_init (&plain_code, (yyvsp[0].chars), (yylsp[0]));
@@ -2748,12 +2749,12 @@ yyreduce:
       code_scanner_last_string_free ();
     }
 /* Line 1388 of yacc.c  */
-#line 2752 "src/parse-gram.c"
+#line 2753 "src/parse-gram.c"
     break;
 
 
 /* Line 1388 of yacc.c  */
-#line 2757 "src/parse-gram.c"
+#line 2758 "src/parse-gram.c"
       default: break;
     }
   YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);
@@ -2970,7 +2971,7 @@ yyreturn:
 }
 
 /* Line 1607 of yacc.c  */
-#line 689 "src/parse-gram.y"
+#line 690 "src/parse-gram.y"
 
 
 
