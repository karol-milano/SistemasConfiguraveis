@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 2.5.1.899-d02b0-dirty.  */
+/* A Bison parser, made by GNU Bison 2.5.1.899-007c5.  */
 
 /* Bison implementation for Yacc-like parsers in C
 
@@ -44,7 +44,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "2.5.1.899-d02b0-dirty"
+#define YYBISON_VERSION "2.5.1.899-007c5"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -325,7 +325,6 @@ code_props_type code_type;
 #line 326 "src/parse-gram.c"
 } YYSTYPE;
 # define YYSTYPE_IS_TRIVIAL 1
-# define yystype YYSTYPE /* obsolescent; will be withdrawn */
 # define YYSTYPE_IS_DECLARED 1
 #endif
 
@@ -337,7 +336,6 @@ typedef struct YYLTYPE
   int last_line;
   int last_column;
 } YYLTYPE;
-# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
 # define YYLTYPE_IS_DECLARED 1
 # define YYLTYPE_IS_TRIVIAL 1
 #endif
@@ -364,7 +362,7 @@ int gram_parse ();
 /* Copy the second part of user declarations.  */
 
 /* Line 354 of yacc.c  */
-#line 368 "src/parse-gram.c"
+#line 366 "src/parse-gram.c"
 /* Unqualified %code blocks.  */
 /* Line 355 of yacc.c  */
 #line 57 "src/parse-gram.y"
@@ -413,7 +411,7 @@ int gram_parse ();
 
 
 /* Line 355 of yacc.c  */
-#line 417 "src/parse-gram.c"
+#line 415 "src/parse-gram.c"
 
 #ifdef short
 # undef short
@@ -1048,7 +1046,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 #line 195 "src/parse-gram.y"
         { fputs (quotearg_style (c_quoting_style, ((*yyvaluep).chars)), yyo); }
 /* Line 725 of yacc.c  */
-#line 1052 "src/parse-gram.c"
+#line 1050 "src/parse-gram.c"
         break;
 
             case 4: // "integer"
@@ -1056,7 +1054,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 #line 208 "src/parse-gram.y"
         { fprintf (yyo, "%d", ((*yyvaluep).integer)); }
 /* Line 725 of yacc.c  */
-#line 1060 "src/parse-gram.c"
+#line 1058 "src/parse-gram.c"
         break;
 
             case 24: // "%<flag>"
@@ -1064,7 +1062,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 #line 204 "src/parse-gram.y"
         { fprintf (yyo, "%%%s", ((*yyvaluep).uniqstr)); }
 /* Line 725 of yacc.c  */
-#line 1068 "src/parse-gram.c"
+#line 1066 "src/parse-gram.c"
         break;
 
             case 40: // "{...}"
@@ -1072,7 +1070,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 #line 197 "src/parse-gram.y"
         { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).code)); }
 /* Line 725 of yacc.c  */
-#line 1076 "src/parse-gram.c"
+#line 1074 "src/parse-gram.c"
         break;
 
             case 42: // "[identifier]"
@@ -1080,7 +1078,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 #line 202 "src/parse-gram.y"
         { fprintf (yyo, "[%s]", ((*yyvaluep).uniqstr)); }
 /* Line 725 of yacc.c  */
-#line 1084 "src/parse-gram.c"
+#line 1082 "src/parse-gram.c"
         break;
 
             case 43: // "char"
@@ -1088,7 +1086,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 #line 189 "src/parse-gram.y"
         { fputs (char_name (((*yyvaluep).character)), yyo); }
 /* Line 725 of yacc.c  */
-#line 1092 "src/parse-gram.c"
+#line 1090 "src/parse-gram.c"
         break;
 
             case 44: // "epilogue"
@@ -1096,7 +1094,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 #line 197 "src/parse-gram.y"
         { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).chars)); }
 /* Line 725 of yacc.c  */
-#line 1100 "src/parse-gram.c"
+#line 1098 "src/parse-gram.c"
         break;
 
             case 46: // "identifier"
@@ -1104,7 +1102,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 #line 201 "src/parse-gram.y"
         { fputs (((*yyvaluep).uniqstr), yyo); }
 /* Line 725 of yacc.c  */
-#line 1108 "src/parse-gram.c"
+#line 1106 "src/parse-gram.c"
         break;
 
             case 47: // "identifier:"
@@ -1112,7 +1110,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 #line 203 "src/parse-gram.y"
         { fprintf (yyo, "%s:", ((*yyvaluep).uniqstr)); }
 /* Line 725 of yacc.c  */
-#line 1116 "src/parse-gram.c"
+#line 1114 "src/parse-gram.c"
         break;
 
             case 50: // "%{...%}"
@@ -1120,7 +1118,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 #line 197 "src/parse-gram.y"
         { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).chars)); }
 /* Line 725 of yacc.c  */
-#line 1124 "src/parse-gram.c"
+#line 1122 "src/parse-gram.c"
         break;
 
             case 52: // "<tag>"
@@ -1128,7 +1126,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 #line 205 "src/parse-gram.y"
         { fprintf (yyo, "<%s>", ((*yyvaluep).uniqstr)); }
 /* Line 725 of yacc.c  */
-#line 1132 "src/parse-gram.c"
+#line 1130 "src/parse-gram.c"
         break;
 
             case 55: // "%param"
@@ -1147,7 +1145,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
     }
 }
 /* Line 725 of yacc.c  */
-#line 1151 "src/parse-gram.c"
+#line 1149 "src/parse-gram.c"
         break;
 
             case 64: // code_props_type
@@ -1155,7 +1153,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 #line 421 "src/parse-gram.y"
         { fprintf (yyo, "%s", code_props_type_string (((*yyvaluep).code_type))); }
 /* Line 725 of yacc.c  */
-#line 1159 "src/parse-gram.c"
+#line 1157 "src/parse-gram.c"
         break;
 
             case 73: // symbol.prec
@@ -1163,7 +1161,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 #line 211 "src/parse-gram.y"
         { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
 /* Line 725 of yacc.c  */
-#line 1167 "src/parse-gram.c"
+#line 1165 "src/parse-gram.c"
         break;
 
             case 77: // tag
@@ -1171,7 +1169,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 #line 205 "src/parse-gram.y"
         { fprintf (yyo, "<%s>", ((*yyvaluep).uniqstr)); }
 /* Line 725 of yacc.c  */
-#line 1175 "src/parse-gram.c"
+#line 1173 "src/parse-gram.c"
         break;
 
             case 87: // variable
@@ -1179,7 +1177,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 #line 201 "src/parse-gram.y"
         { fputs (((*yyvaluep).uniqstr), yyo); }
 /* Line 725 of yacc.c  */
-#line 1183 "src/parse-gram.c"
+#line 1181 "src/parse-gram.c"
         break;
 
             case 88: // content.opt
@@ -1187,7 +1185,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 #line 197 "src/parse-gram.y"
         { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).chars)); }
 /* Line 725 of yacc.c  */
-#line 1191 "src/parse-gram.c"
+#line 1189 "src/parse-gram.c"
         break;
 
             case 89: // braceless
@@ -1195,7 +1193,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 #line 197 "src/parse-gram.y"
         { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).chars)); }
 /* Line 725 of yacc.c  */
-#line 1199 "src/parse-gram.c"
+#line 1197 "src/parse-gram.c"
         break;
 
             case 90: // id
@@ -1203,7 +1201,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 #line 211 "src/parse-gram.y"
         { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
 /* Line 725 of yacc.c  */
-#line 1207 "src/parse-gram.c"
+#line 1205 "src/parse-gram.c"
         break;
 
             case 91: // id_colon
@@ -1211,7 +1209,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 #line 212 "src/parse-gram.y"
         { fprintf (yyo, "%s:", ((*yyvaluep).symbol)->tag); }
 /* Line 725 of yacc.c  */
-#line 1215 "src/parse-gram.c"
+#line 1213 "src/parse-gram.c"
         break;
 
             case 92: // symbol
@@ -1219,7 +1217,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 #line 211 "src/parse-gram.y"
         { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
 /* Line 725 of yacc.c  */
-#line 1223 "src/parse-gram.c"
+#line 1221 "src/parse-gram.c"
         break;
 
             case 93: // string_as_id
@@ -1227,7 +1225,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 #line 211 "src/parse-gram.y"
         { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
 /* Line 725 of yacc.c  */
-#line 1231 "src/parse-gram.c"
+#line 1229 "src/parse-gram.c"
         break;
 
       default:
@@ -2009,7 +2007,7 @@ YYLTYPE yylloc;
   boundary_set (&yylloc.end, current_file, 1, 1);
 }
 /* Line 1486 of yacc.c  */
-#line 2013 "src/parse-gram.c"
+#line 2011 "src/parse-gram.c"
   yylsp[0] = yylloc;
 
   goto yysetstate;
@@ -2214,7 +2212,7 @@ yyreduce:
       code_scanner_last_string_free ();
     }
 /* Line 1702 of yacc.c  */
-#line 2218 "src/parse-gram.c"
+#line 2216 "src/parse-gram.c"
     break;
 
   case 7:
@@ -2224,7 +2222,7 @@ yyreduce:
       muscle_percent_define_ensure ((yyvsp[0].uniqstr), (yylsp[0]), true);
     }
 /* Line 1702 of yacc.c  */
-#line 2228 "src/parse-gram.c"
+#line 2226 "src/parse-gram.c"
     break;
 
   case 8:
@@ -2235,7 +2233,7 @@ yyreduce:
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
     }
 /* Line 1702 of yacc.c  */
-#line 2239 "src/parse-gram.c"
+#line 2237 "src/parse-gram.c"
     break;
 
   case 9:
@@ -2243,7 +2241,7 @@ yyreduce:
 #line 305 "src/parse-gram.y"
     { defines_flag = true; }
 /* Line 1702 of yacc.c  */
-#line 2247 "src/parse-gram.c"
+#line 2245 "src/parse-gram.c"
     break;
 
   case 10:
@@ -2254,7 +2252,7 @@ yyreduce:
       spec_defines_file = xstrdup ((yyvsp[0].chars));
     }
 /* Line 1702 of yacc.c  */
-#line 2258 "src/parse-gram.c"
+#line 2256 "src/parse-gram.c"
     break;
 
   case 11:
@@ -2265,7 +2263,7 @@ yyreduce:
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
     }
 /* Line 1702 of yacc.c  */
-#line 2269 "src/parse-gram.c"
+#line 2267 "src/parse-gram.c"
     break;
 
   case 12:
@@ -2273,7 +2271,7 @@ yyreduce:
 #line 316 "src/parse-gram.y"
     { expected_sr_conflicts = (yyvsp[0].integer); }
 /* Line 1702 of yacc.c  */
-#line 2277 "src/parse-gram.c"
+#line 2275 "src/parse-gram.c"
     break;
 
   case 13:
@@ -2281,7 +2279,7 @@ yyreduce:
 #line 317 "src/parse-gram.y"
     { expected_rr_conflicts = (yyvsp[0].integer); }
 /* Line 1702 of yacc.c  */
-#line 2285 "src/parse-gram.c"
+#line 2283 "src/parse-gram.c"
     break;
 
   case 14:
@@ -2289,7 +2287,7 @@ yyreduce:
 #line 318 "src/parse-gram.y"
     { spec_file_prefix = (yyvsp[0].chars); }
 /* Line 1702 of yacc.c  */
-#line 2293 "src/parse-gram.c"
+#line 2291 "src/parse-gram.c"
     break;
 
   case 15:
@@ -2297,7 +2295,7 @@ yyreduce:
 #line 319 "src/parse-gram.y"
     { spec_file_prefix = (yyvsp[0].chars); }
 /* Line 1702 of yacc.c  */
-#line 2301 "src/parse-gram.c"
+#line 2299 "src/parse-gram.c"
     break;
 
   case 16:
@@ -2308,7 +2306,7 @@ yyreduce:
       glr_parser = true;
     }
 /* Line 1702 of yacc.c  */
-#line 2312 "src/parse-gram.c"
+#line 2310 "src/parse-gram.c"
     break;
 
   case 17:
@@ -2323,7 +2321,7 @@ yyreduce:
       code_scanner_last_string_free ();
     }
 /* Line 1702 of yacc.c  */
-#line 2327 "src/parse-gram.c"
+#line 2325 "src/parse-gram.c"
     break;
 
   case 18:
@@ -2331,7 +2329,7 @@ yyreduce:
 #line 334 "src/parse-gram.y"
     { language_argmatch ((yyvsp[0].chars), grammar_prio, (yylsp[-1])); }
 /* Line 1702 of yacc.c  */
-#line 2335 "src/parse-gram.c"
+#line 2333 "src/parse-gram.c"
     break;
 
   case 19:
@@ -2339,7 +2337,7 @@ yyreduce:
 #line 335 "src/parse-gram.y"
     { spec_name_prefix = (yyvsp[0].chars); }
 /* Line 1702 of yacc.c  */
-#line 2343 "src/parse-gram.c"
+#line 2341 "src/parse-gram.c"
     break;
 
   case 20:
@@ -2347,7 +2345,7 @@ yyreduce:
 #line 336 "src/parse-gram.y"
     { spec_name_prefix = (yyvsp[0].chars); }
 /* Line 1702 of yacc.c  */
-#line 2351 "src/parse-gram.c"
+#line 2349 "src/parse-gram.c"
     break;
 
   case 21:
@@ -2355,7 +2353,7 @@ yyreduce:
 #line 337 "src/parse-gram.y"
     { no_lines_flag = true; }
 /* Line 1702 of yacc.c  */
-#line 2359 "src/parse-gram.c"
+#line 2357 "src/parse-gram.c"
     break;
 
   case 22:
@@ -2363,7 +2361,7 @@ yyreduce:
 #line 338 "src/parse-gram.y"
     { nondeterministic_parser = true; }
 /* Line 1702 of yacc.c  */
-#line 2367 "src/parse-gram.c"
+#line 2365 "src/parse-gram.c"
     break;
 
   case 23:
@@ -2371,7 +2369,7 @@ yyreduce:
 #line 339 "src/parse-gram.y"
     { spec_outfile = (yyvsp[0].chars); }
 /* Line 1702 of yacc.c  */
-#line 2375 "src/parse-gram.c"
+#line 2373 "src/parse-gram.c"
     break;
 
   case 24:
@@ -2379,7 +2377,7 @@ yyreduce:
 #line 340 "src/parse-gram.y"
     { spec_outfile = (yyvsp[0].chars); }
 /* Line 1702 of yacc.c  */
-#line 2383 "src/parse-gram.c"
+#line 2381 "src/parse-gram.c"
     break;
 
   case 25:
@@ -2387,7 +2385,7 @@ yyreduce:
 #line 341 "src/parse-gram.y"
     { current_param = (yyvsp[0].param); }
 /* Line 1702 of yacc.c  */
-#line 2391 "src/parse-gram.c"
+#line 2389 "src/parse-gram.c"
     break;
 
   case 26:
@@ -2395,7 +2393,7 @@ yyreduce:
 #line 341 "src/parse-gram.y"
     { current_param = param_none; }
 /* Line 1702 of yacc.c  */
-#line 2399 "src/parse-gram.c"
+#line 2397 "src/parse-gram.c"
     break;
 
   case 27:
@@ -2403,7 +2401,7 @@ yyreduce:
 #line 342 "src/parse-gram.y"
     { version_check (&(yylsp[0]), (yyvsp[0].chars)); }
 /* Line 1702 of yacc.c  */
-#line 2407 "src/parse-gram.c"
+#line 2405 "src/parse-gram.c"
     break;
 
   case 28:
@@ -2433,7 +2431,7 @@ yyreduce:
       skeleton_arg (skeleton_user, grammar_prio, (yylsp[-1]));
     }
 /* Line 1702 of yacc.c  */
-#line 2437 "src/parse-gram.c"
+#line 2435 "src/parse-gram.c"
     break;
 
   case 29:
@@ -2441,7 +2439,7 @@ yyreduce:
 #line 367 "src/parse-gram.y"
     { token_table_flag = true; }
 /* Line 1702 of yacc.c  */
-#line 2445 "src/parse-gram.c"
+#line 2443 "src/parse-gram.c"
     break;
 
   case 30:
@@ -2449,7 +2447,7 @@ yyreduce:
 #line 368 "src/parse-gram.y"
     { report_flag |= report_states; }
 /* Line 1702 of yacc.c  */
-#line 2453 "src/parse-gram.c"
+#line 2451 "src/parse-gram.c"
     break;
 
   case 31:
@@ -2457,7 +2455,7 @@ yyreduce:
 #line 369 "src/parse-gram.y"
     { yacc_flag = true; }
 /* Line 1702 of yacc.c  */
-#line 2461 "src/parse-gram.c"
+#line 2459 "src/parse-gram.c"
     break;
 
   case 33:
@@ -2465,7 +2463,7 @@ yyreduce:
 #line 374 "src/parse-gram.y"
     { add_param (current_param, (yyvsp[0].code), (yylsp[0])); }
 /* Line 1702 of yacc.c  */
-#line 2469 "src/parse-gram.c"
+#line 2467 "src/parse-gram.c"
     break;
 
   case 34:
@@ -2473,7 +2471,7 @@ yyreduce:
 #line 375 "src/parse-gram.y"
     { add_param (current_param, (yyvsp[0].code), (yylsp[0])); }
 /* Line 1702 of yacc.c  */
-#line 2477 "src/parse-gram.c"
+#line 2475 "src/parse-gram.c"
     break;
 
   case 37:
@@ -2483,7 +2481,7 @@ yyreduce:
       grammar_start_symbol_set ((yyvsp[0].symbol), (yylsp[0]));
     }
 /* Line 1702 of yacc.c  */
-#line 2487 "src/parse-gram.c"
+#line 2485 "src/parse-gram.c"
     break;
 
   case 38:
@@ -2496,7 +2494,7 @@ yyreduce:
       symbol_list_free ((yyvsp[0].list));
     }
 /* Line 1702 of yacc.c  */
-#line 2500 "src/parse-gram.c"
+#line 2498 "src/parse-gram.c"
     break;
 
   case 39:
@@ -2506,7 +2504,7 @@ yyreduce:
       default_prec = true;
     }
 /* Line 1702 of yacc.c  */
-#line 2510 "src/parse-gram.c"
+#line 2508 "src/parse-gram.c"
     break;
 
   case 40:
@@ -2516,7 +2514,7 @@ yyreduce:
       default_prec = false;
     }
 /* Line 1702 of yacc.c  */
-#line 2520 "src/parse-gram.c"
+#line 2518 "src/parse-gram.c"
     break;
 
   case 41:
@@ -2529,7 +2527,7 @@ yyreduce:
       code_scanner_last_string_free ();
     }
 /* Line 1702 of yacc.c  */
-#line 2533 "src/parse-gram.c"
+#line 2531 "src/parse-gram.c"
     break;
 
   case 42:
@@ -2540,7 +2538,7 @@ yyreduce:
       code_scanner_last_string_free ();
     }
 /* Line 1702 of yacc.c  */
-#line 2544 "src/parse-gram.c"
+#line 2542 "src/parse-gram.c"
     break;
 
   case 43:
@@ -2548,7 +2546,7 @@ yyreduce:
 #line 423 "src/parse-gram.y"
     { (yyval.code_type) = destructor; }
 /* Line 1702 of yacc.c  */
-#line 2552 "src/parse-gram.c"
+#line 2550 "src/parse-gram.c"
     break;
 
   case 44:
@@ -2556,7 +2554,7 @@ yyreduce:
 #line 424 "src/parse-gram.y"
     { (yyval.code_type) = printer; }
 /* Line 1702 of yacc.c  */
-#line 2560 "src/parse-gram.c"
+#line 2558 "src/parse-gram.c"
     break;
 
   case 45:
@@ -2564,7 +2562,7 @@ yyreduce:
 #line 434 "src/parse-gram.y"
     {}
 /* Line 1702 of yacc.c  */
-#line 2568 "src/parse-gram.c"
+#line 2566 "src/parse-gram.c"
     break;
 
   case 46:
@@ -2572,7 +2570,7 @@ yyreduce:
 #line 435 "src/parse-gram.y"
     { muscle_code_grow ("union_name", (yyvsp[0].uniqstr), (yylsp[0])); }
 /* Line 1702 of yacc.c  */
-#line 2576 "src/parse-gram.c"
+#line 2574 "src/parse-gram.c"
     break;
 
   case 47:
@@ -2584,7 +2582,7 @@ yyreduce:
       code_scanner_last_string_free ();
     }
 /* Line 1702 of yacc.c  */
-#line 2588 "src/parse-gram.c"
+#line 2586 "src/parse-gram.c"
     break;
 
   case 48:
@@ -2592,7 +2590,7 @@ yyreduce:
 #line 451 "src/parse-gram.y"
     { current_class = nterm_sym; }
 /* Line 1702 of yacc.c  */
-#line 2596 "src/parse-gram.c"
+#line 2594 "src/parse-gram.c"
     break;
 
   case 49:
@@ -2603,7 +2601,7 @@ yyreduce:
       current_type = NULL;
     }
 /* Line 1702 of yacc.c  */
-#line 2607 "src/parse-gram.c"
+#line 2605 "src/parse-gram.c"
     break;
 
   case 50:
@@ -2611,7 +2609,7 @@ yyreduce:
 #line 456 "src/parse-gram.y"
     { current_class = token_sym; }
 /* Line 1702 of yacc.c  */
-#line 2615 "src/parse-gram.c"
+#line 2613 "src/parse-gram.c"
     break;
 
   case 51:
@@ -2622,7 +2620,7 @@ yyreduce:
       current_type = NULL;
     }
 /* Line 1702 of yacc.c  */
-#line 2626 "src/parse-gram.c"
+#line 2624 "src/parse-gram.c"
     break;
 
   case 52:
@@ -2636,7 +2634,7 @@ yyreduce:
       symbol_list_free ((yyvsp[0].list));
     }
 /* Line 1702 of yacc.c  */
-#line 2640 "src/parse-gram.c"
+#line 2638 "src/parse-gram.c"
     break;
 
   case 53:
@@ -2654,7 +2652,7 @@ yyreduce:
       current_type = NULL;
     }
 /* Line 1702 of yacc.c  */
-#line 2658 "src/parse-gram.c"
+#line 2656 "src/parse-gram.c"
     break;
 
   case 54:
@@ -2662,7 +2660,7 @@ yyreduce:
 #line 487 "src/parse-gram.y"
     { (yyval.assoc) = left_assoc; }
 /* Line 1702 of yacc.c  */
-#line 2666 "src/parse-gram.c"
+#line 2664 "src/parse-gram.c"
     break;
 
   case 55:
@@ -2670,7 +2668,7 @@ yyreduce:
 #line 488 "src/parse-gram.y"
     { (yyval.assoc) = right_assoc; }
 /* Line 1702 of yacc.c  */
-#line 2674 "src/parse-gram.c"
+#line 2672 "src/parse-gram.c"
     break;
 
   case 56:
@@ -2678,7 +2676,7 @@ yyreduce:
 #line 489 "src/parse-gram.y"
     { (yyval.assoc) = non_assoc; }
 /* Line 1702 of yacc.c  */
-#line 2682 "src/parse-gram.c"
+#line 2680 "src/parse-gram.c"
     break;
 
   case 57:
@@ -2686,7 +2684,7 @@ yyreduce:
 #line 490 "src/parse-gram.y"
     { (yyval.assoc) = precedence_assoc; }
 /* Line 1702 of yacc.c  */
-#line 2690 "src/parse-gram.c"
+#line 2688 "src/parse-gram.c"
     break;
 
   case 58:
@@ -2694,7 +2692,7 @@ yyreduce:
 #line 494 "src/parse-gram.y"
     { current_type = NULL; }
 /* Line 1702 of yacc.c  */
-#line 2698 "src/parse-gram.c"
+#line 2696 "src/parse-gram.c"
     break;
 
   case 59:
@@ -2702,7 +2700,7 @@ yyreduce:
 #line 495 "src/parse-gram.y"
     { current_type = (yyvsp[0].uniqstr); tag_seen = true; }
 /* Line 1702 of yacc.c  */
-#line 2706 "src/parse-gram.c"
+#line 2704 "src/parse-gram.c"
     break;
 
   case 60:
@@ -2710,7 +2708,7 @@ yyreduce:
 #line 501 "src/parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
 /* Line 1702 of yacc.c  */
-#line 2714 "src/parse-gram.c"
+#line 2712 "src/parse-gram.c"
     break;
 
   case 61:
@@ -2718,7 +2716,7 @@ yyreduce:
 #line 503 "src/parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
 /* Line 1702 of yacc.c  */
-#line 2722 "src/parse-gram.c"
+#line 2720 "src/parse-gram.c"
     break;
 
   case 62:
@@ -2726,7 +2724,7 @@ yyreduce:
 #line 507 "src/parse-gram.y"
     { (yyval.symbol) = (yyvsp[0].symbol); }
 /* Line 1702 of yacc.c  */
-#line 2730 "src/parse-gram.c"
+#line 2728 "src/parse-gram.c"
     break;
 
   case 63:
@@ -2734,7 +2732,7 @@ yyreduce:
 #line 508 "src/parse-gram.y"
     { (yyval.symbol) = (yyvsp[-1].symbol); symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0])); }
 /* Line 1702 of yacc.c  */
-#line 2738 "src/parse-gram.c"
+#line 2736 "src/parse-gram.c"
     break;
 
   case 64:
@@ -2742,7 +2740,7 @@ yyreduce:
 #line 514 "src/parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
 /* Line 1702 of yacc.c  */
-#line 2746 "src/parse-gram.c"
+#line 2744 "src/parse-gram.c"
     break;
 
   case 65:
@@ -2750,7 +2748,7 @@ yyreduce:
 #line 516 "src/parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
 /* Line 1702 of yacc.c  */
-#line 2754 "src/parse-gram.c"
+#line 2752 "src/parse-gram.c"
     break;
 
   case 66:
@@ -2758,7 +2756,7 @@ yyreduce:
 #line 520 "src/parse-gram.y"
     { (yyval.list) = (yyvsp[0].list); }
 /* Line 1702 of yacc.c  */
-#line 2762 "src/parse-gram.c"
+#line 2760 "src/parse-gram.c"
     break;
 
   case 67:
@@ -2766,7 +2764,7 @@ yyreduce:
 #line 521 "src/parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), (yyvsp[0].list)); }
 /* Line 1702 of yacc.c  */
-#line 2770 "src/parse-gram.c"
+#line 2768 "src/parse-gram.c"
     break;
 
   case 68:
@@ -2774,7 +2772,7 @@ yyreduce:
 #line 525 "src/parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
 /* Line 1702 of yacc.c  */
-#line 2778 "src/parse-gram.c"
+#line 2776 "src/parse-gram.c"
     break;
 
   case 69:
@@ -2782,7 +2780,7 @@ yyreduce:
 #line 526 "src/parse-gram.y"
     { (yyval.list) = symbol_list_type_new ((yyvsp[0].uniqstr), (yylsp[0])); }
 /* Line 1702 of yacc.c  */
-#line 2786 "src/parse-gram.c"
+#line 2784 "src/parse-gram.c"
     break;
 
   case 71:
@@ -2790,7 +2788,7 @@ yyreduce:
 #line 531 "src/parse-gram.y"
     { (yyval.uniqstr) = uniqstr_new ("*"); }
 /* Line 1702 of yacc.c  */
-#line 2794 "src/parse-gram.c"
+#line 2792 "src/parse-gram.c"
     break;
 
   case 72:
@@ -2798,7 +2796,7 @@ yyreduce:
 #line 532 "src/parse-gram.y"
     { (yyval.uniqstr) = uniqstr_new (""); }
 /* Line 1702 of yacc.c  */
-#line 2802 "src/parse-gram.c"
+#line 2800 "src/parse-gram.c"
     break;
 
   case 73:
@@ -2809,7 +2807,7 @@ yyreduce:
        tag_seen = true;
      }
 /* Line 1702 of yacc.c  */
-#line 2813 "src/parse-gram.c"
+#line 2811 "src/parse-gram.c"
     break;
 
   case 74:
@@ -2820,7 +2818,7 @@ yyreduce:
        symbol_type_set ((yyvsp[0].symbol), current_type, (yylsp[0]));
      }
 /* Line 1702 of yacc.c  */
-#line 2824 "src/parse-gram.c"
+#line 2822 "src/parse-gram.c"
     break;
 
   case 75:
@@ -2832,7 +2830,7 @@ yyreduce:
       symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0]));
     }
 /* Line 1702 of yacc.c  */
-#line 2836 "src/parse-gram.c"
+#line 2834 "src/parse-gram.c"
     break;
 
   case 76:
@@ -2844,7 +2842,7 @@ yyreduce:
       symbol_make_alias ((yyvsp[-1].symbol), (yyvsp[0].symbol), (yyloc));
     }
 /* Line 1702 of yacc.c  */
-#line 2848 "src/parse-gram.c"
+#line 2846 "src/parse-gram.c"
     break;
 
   case 77:
@@ -2857,7 +2855,7 @@ yyreduce:
       symbol_make_alias ((yyvsp[-2].symbol), (yyvsp[0].symbol), (yyloc));
     }
 /* Line 1702 of yacc.c  */
-#line 2861 "src/parse-gram.c"
+#line 2859 "src/parse-gram.c"
     break;
 
   case 84:
@@ -2867,7 +2865,7 @@ yyreduce:
       yyerrok;
     }
 /* Line 1702 of yacc.c  */
-#line 2871 "src/parse-gram.c"
+#line 2869 "src/parse-gram.c"
     break;
 
   case 85:
@@ -2875,7 +2873,7 @@ yyreduce:
 #line 596 "src/parse-gram.y"
     { current_lhs ((yyvsp[-1].symbol), (yylsp[-1]), (yyvsp[0].named_ref)); }
 /* Line 1702 of yacc.c  */
-#line 2879 "src/parse-gram.c"
+#line 2877 "src/parse-gram.c"
     break;
 
   case 86:
@@ -2886,7 +2884,7 @@ yyreduce:
     current_lhs (0, (yylsp[-3]), 0);
   }
 /* Line 1702 of yacc.c  */
-#line 2890 "src/parse-gram.c"
+#line 2888 "src/parse-gram.c"
     break;
 
   case 87:
@@ -2894,7 +2892,7 @@ yyreduce:
 #line 604 "src/parse-gram.y"
     { grammar_current_rule_end ((yylsp[0])); }
 /* Line 1702 of yacc.c  */
-#line 2898 "src/parse-gram.c"
+#line 2896 "src/parse-gram.c"
     break;
 
   case 88:
@@ -2902,7 +2900,7 @@ yyreduce:
 #line 605 "src/parse-gram.y"
     { grammar_current_rule_end ((yylsp[0])); }
 /* Line 1702 of yacc.c  */
-#line 2906 "src/parse-gram.c"
+#line 2904 "src/parse-gram.c"
     break;
 
   case 90:
@@ -2911,7 +2909,7 @@ yyreduce:
     { grammar_current_rule_begin (current_lhs_symbol, current_lhs_location,
                                   current_lhs_named_ref); }
 /* Line 1702 of yacc.c  */
-#line 2915 "src/parse-gram.c"
+#line 2913 "src/parse-gram.c"
     break;
 
   case 91:
@@ -2919,7 +2917,7 @@ yyreduce:
 #line 614 "src/parse-gram.y"
     { grammar_current_rule_symbol_append ((yyvsp[-1].symbol), (yylsp[-1]), (yyvsp[0].named_ref)); }
 /* Line 1702 of yacc.c  */
-#line 2923 "src/parse-gram.c"
+#line 2921 "src/parse-gram.c"
     break;
 
   case 92:
@@ -2927,7 +2925,7 @@ yyreduce:
 #line 616 "src/parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[-1].code), (yylsp[-1]), (yyvsp[0].named_ref), false); }
 /* Line 1702 of yacc.c  */
-#line 2931 "src/parse-gram.c"
+#line 2929 "src/parse-gram.c"
     break;
 
   case 93:
@@ -2935,7 +2933,7 @@ yyreduce:
 #line 618 "src/parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[0].code), (yylsp[0]), NULL, true); }
 /* Line 1702 of yacc.c  */
-#line 2939 "src/parse-gram.c"
+#line 2937 "src/parse-gram.c"
     break;
 
   case 94:
@@ -2943,7 +2941,7 @@ yyreduce:
 #line 620 "src/parse-gram.y"
     { grammar_current_rule_prec_set ((yyvsp[0].symbol), (yylsp[0])); }
 /* Line 1702 of yacc.c  */
-#line 2947 "src/parse-gram.c"
+#line 2945 "src/parse-gram.c"
     break;
 
   case 95:
@@ -2951,7 +2949,7 @@ yyreduce:
 #line 622 "src/parse-gram.y"
     { grammar_current_rule_dprec_set ((yyvsp[0].integer), (yylsp[0])); }
 /* Line 1702 of yacc.c  */
-#line 2955 "src/parse-gram.c"
+#line 2953 "src/parse-gram.c"
     break;
 
   case 96:
@@ -2959,7 +2957,7 @@ yyreduce:
 #line 624 "src/parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[0].uniqstr), (yylsp[0])); }
 /* Line 1702 of yacc.c  */
-#line 2963 "src/parse-gram.c"
+#line 2961 "src/parse-gram.c"
     break;
 
   case 97:
@@ -2967,7 +2965,7 @@ yyreduce:
 #line 628 "src/parse-gram.y"
     { (yyval.named_ref) = 0; }
 /* Line 1702 of yacc.c  */
-#line 2971 "src/parse-gram.c"
+#line 2969 "src/parse-gram.c"
     break;
 
   case 98:
@@ -2975,7 +2973,7 @@ yyreduce:
 #line 630 "src/parse-gram.y"
     { (yyval.named_ref) = named_ref_new((yyvsp[0].uniqstr), (yylsp[0])); }
 /* Line 1702 of yacc.c  */
-#line 2979 "src/parse-gram.c"
+#line 2977 "src/parse-gram.c"
     break;
 
   case 100:
@@ -2983,7 +2981,7 @@ yyreduce:
 #line 641 "src/parse-gram.y"
     { (yyval.uniqstr) = uniqstr_new ((yyvsp[0].chars)); }
 /* Line 1702 of yacc.c  */
-#line 2987 "src/parse-gram.c"
+#line 2985 "src/parse-gram.c"
     break;
 
   case 101:
@@ -2991,7 +2989,7 @@ yyreduce:
 #line 646 "src/parse-gram.y"
     { (yyval.chars) = ""; }
 /* Line 1702 of yacc.c  */
-#line 2995 "src/parse-gram.c"
+#line 2993 "src/parse-gram.c"
     break;
 
   case 102:
@@ -2999,7 +2997,7 @@ yyreduce:
 #line 647 "src/parse-gram.y"
     { (yyval.chars) = (yyvsp[0].uniqstr); }
 /* Line 1702 of yacc.c  */
-#line 3003 "src/parse-gram.c"
+#line 3001 "src/parse-gram.c"
     break;
 
   case 104:
@@ -3014,7 +3012,7 @@ yyreduce:
       (yyval.chars) = plain_code.code;
     }
 /* Line 1702 of yacc.c  */
-#line 3018 "src/parse-gram.c"
+#line 3016 "src/parse-gram.c"
     break;
 
   case 105:
@@ -3022,7 +3020,7 @@ yyreduce:
 #line 678 "src/parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
 /* Line 1702 of yacc.c  */
-#line 3026 "src/parse-gram.c"
+#line 3024 "src/parse-gram.c"
     break;
 
   case 106:
@@ -3034,7 +3032,7 @@ yyreduce:
       symbol_user_token_number_set ((yyval.symbol), (yyvsp[0].character), (yylsp[0]));
     }
 /* Line 1702 of yacc.c  */
-#line 3038 "src/parse-gram.c"
+#line 3036 "src/parse-gram.c"
     break;
 
   case 107:
@@ -3042,7 +3040,7 @@ yyreduce:
 #line 688 "src/parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
 /* Line 1702 of yacc.c  */
-#line 3046 "src/parse-gram.c"
+#line 3044 "src/parse-gram.c"
     break;
 
   case 110:
@@ -3053,7 +3051,7 @@ yyreduce:
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
     }
 /* Line 1702 of yacc.c  */
-#line 3057 "src/parse-gram.c"
+#line 3055 "src/parse-gram.c"
     break;
 
   case 112:
@@ -3068,12 +3066,12 @@ yyreduce:
       code_scanner_last_string_free ();
     }
 /* Line 1702 of yacc.c  */
-#line 3072 "src/parse-gram.c"
+#line 3070 "src/parse-gram.c"
     break;
 
 
 /* Line 1702 of yacc.c  */
-#line 3077 "src/parse-gram.c"
+#line 3075 "src/parse-gram.c"
         default: break;
       }
     if (yychar_backup != yychar)
