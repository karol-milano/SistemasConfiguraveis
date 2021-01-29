@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 2.3b.153-3d8d7.  */
+/* A Bison parser, made by GNU Bison 2.4.58-9380c.  */
 
 /* Implementation for Bison's Yacc-like parsers in C
    
@@ -45,7 +45,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "2.3b.153-3d8d7"
+#define YYBISON_VERSION "2.4.58-9380c"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -150,7 +150,7 @@ static int current_prec = 0;
 
 
 /* Line 191 of yacc.c  */
-#line 154 "../../../src/parse-gram.c"
+#line 154 "parse-gram.c"
 
 /* Enabling traces.  */
 #ifndef YYDEBUG
@@ -298,7 +298,7 @@ static int current_prec = 0;
 typedef union YYSTYPE
 {
 
-/* Line 216 of yacc.c  */
+/* Line 224 of yacc.c  */
 #line 92 "parse-gram.y"
 
   symbol *symbol;
@@ -312,8 +312,8 @@ typedef union YYSTYPE
 
 
 
-/* Line 216 of yacc.c  */
-#line 317 "../../../src/parse-gram.c"
+/* Line 224 of yacc.c  */
+#line 317 "parse-gram.c"
 } YYSTYPE;
 # define YYSTYPE_IS_TRIVIAL 1
 # define yystype YYSTYPE /* obsolescent; will be withdrawn */
@@ -338,7 +338,7 @@ typedef struct YYLTYPE
 
 
 /* Line 266 of yacc.c  */
-#line 342 "../../../src/parse-gram.c"
+#line 342 "parse-gram.c"
 
 #ifdef short
 # undef short
@@ -1033,7 +1033,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 	{ fputs (quotearg_style (c_quoting_style, ((*yyvaluep).chars)), stderr); };
 
 /* Line 717 of yacc.c  */
-#line 1037 "../../../src/parse-gram.c"
+#line 1037 "parse-gram.c"
 	break;
       case 4: /* "\"integer\"" */
 
@@ -1042,7 +1042,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 	{ fprintf (stderr, "%d", ((*yyvaluep).integer)); };
 
 /* Line 717 of yacc.c  */
-#line 1046 "../../../src/parse-gram.c"
+#line 1046 "parse-gram.c"
 	break;
       case 43: /* "\"{...}\"" */
 
@@ -1051,7 +1051,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 	{ fprintf (stderr, "{\n%s\n}", ((*yyvaluep).code)); };
 
 /* Line 717 of yacc.c  */
-#line 1055 "../../../src/parse-gram.c"
+#line 1055 "parse-gram.c"
 	break;
       case 44: /* "\"char\"" */
 
@@ -1060,7 +1060,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 	{ fputs (char_name (((*yyvaluep).character)), stderr); };
 
 /* Line 717 of yacc.c  */
-#line 1064 "../../../src/parse-gram.c"
+#line 1064 "parse-gram.c"
 	break;
       case 45: /* "\"epilogue\"" */
 
@@ -1069,7 +1069,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 	{ fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); };
 
 /* Line 717 of yacc.c  */
-#line 1073 "../../../src/parse-gram.c"
+#line 1073 "parse-gram.c"
 	break;
       case 47: /* "\"identifier\"" */
 
@@ -1078,7 +1078,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 	{ fputs (((*yyvaluep).uniqstr), stderr); };
 
 /* Line 717 of yacc.c  */
-#line 1082 "../../../src/parse-gram.c"
+#line 1082 "parse-gram.c"
 	break;
       case 48: /* "\"identifier:\"" */
 
@@ -1087,7 +1087,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 	{ fprintf (stderr, "%s:", ((*yyvaluep).uniqstr)); };
 
 /* Line 717 of yacc.c  */
-#line 1091 "../../../src/parse-gram.c"
+#line 1091 "parse-gram.c"
 	break;
       case 51: /* "\"%{...%}\"" */
 
@@ -1096,7 +1096,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 	{ fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); };
 
 /* Line 717 of yacc.c  */
-#line 1100 "../../../src/parse-gram.c"
+#line 1100 "parse-gram.c"
 	break;
       case 53: /* "\"type\"" */
 
@@ -1105,7 +1105,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 	{ fprintf (stderr, "<%s>", ((*yyvaluep).uniqstr)); };
 
 /* Line 717 of yacc.c  */
-#line 1109 "../../../src/parse-gram.c"
+#line 1109 "parse-gram.c"
 	break;
       case 82: /* "variable" */
 
@@ -1114,7 +1114,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 	{ fputs (((*yyvaluep).uniqstr), stderr); };
 
 /* Line 717 of yacc.c  */
-#line 1118 "../../../src/parse-gram.c"
+#line 1118 "parse-gram.c"
 	break;
       case 83: /* "content.opt" */
 
@@ -1123,7 +1123,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 	{ fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); };
 
 /* Line 717 of yacc.c  */
-#line 1127 "../../../src/parse-gram.c"
+#line 1127 "parse-gram.c"
 	break;
       case 84: /* "braceless" */
 
@@ -1132,7 +1132,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 	{ fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); };
 
 /* Line 717 of yacc.c  */
-#line 1136 "../../../src/parse-gram.c"
+#line 1136 "parse-gram.c"
 	break;
       case 85: /* "id" */
 
@@ -1141,7 +1141,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 	{ fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); };
 
 /* Line 717 of yacc.c  */
-#line 1145 "../../../src/parse-gram.c"
+#line 1145 "parse-gram.c"
 	break;
       case 86: /* "id_colon" */
 
@@ -1150,7 +1150,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 	{ fprintf (stderr, "%s:", ((*yyvaluep).symbol)->tag); };
 
 /* Line 717 of yacc.c  */
-#line 1154 "../../../src/parse-gram.c"
+#line 1154 "parse-gram.c"
 	break;
       case 87: /* "symbol" */
 
@@ -1159,7 +1159,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 	{ fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); };
 
 /* Line 717 of yacc.c  */
-#line 1163 "../../../src/parse-gram.c"
+#line 1163 "parse-gram.c"
 	break;
       case 88: /* "string_as_id" */
 
@@ -1168,7 +1168,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 	{ fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); };
 
 /* Line 717 of yacc.c  */
-#line 1172 "../../../src/parse-gram.c"
+#line 1172 "parse-gram.c"
 	break;
       default:
 	break;
@@ -1687,7 +1687,7 @@ YYLTYPE yylloc;
 
 /* User initialization code.  */
 
-/* Line 1244 of yacc.c  */
+/* Line 1250 of yacc.c  */
 #line 84 "parse-gram.y"
 {
   /* Bison's grammar can initial empty locations, hence a default
@@ -1696,8 +1696,8 @@ YYLTYPE yylloc;
   boundary_set (&yylloc.end, current_file, 1, 1);
 }
 
-/* Line 1244 of yacc.c  */
-#line 1701 "../../../src/parse-gram.c"
+/* Line 1250 of yacc.c  */
+#line 1701 "parse-gram.c"
   yylsp[0] = yylloc;
 
   goto yysetstate;
@@ -1897,7 +1897,7 @@ yyreduce:
     }
 
 /* Line 1457 of yacc.c  */
-#line 1901 "../../../src/parse-gram.c"
+#line 1901 "parse-gram.c"
     break;
 
   case 7:
@@ -1907,7 +1907,7 @@ yyreduce:
     { debug_flag = true; }
 
 /* Line 1457 of yacc.c  */
-#line 1911 "../../../src/parse-gram.c"
+#line 1911 "parse-gram.c"
     break;
 
   case 8:
@@ -1919,7 +1919,7 @@ yyreduce:
     }
 
 /* Line 1457 of yacc.c  */
-#line 1923 "../../../src/parse-gram.c"
+#line 1923 "parse-gram.c"
     break;
 
   case 9:
@@ -1929,7 +1929,7 @@ yyreduce:
     { defines_flag = true; }
 
 /* Line 1457 of yacc.c  */
-#line 1933 "../../../src/parse-gram.c"
+#line 1933 "parse-gram.c"
     break;
 
   case 10:
@@ -1942,7 +1942,7 @@ yyreduce:
     }
 
 /* Line 1457 of yacc.c  */
-#line 1946 "../../../src/parse-gram.c"
+#line 1946 "parse-gram.c"
     break;
 
   case 11:
@@ -1952,7 +1952,7 @@ yyreduce:
     { error_verbose = true; }
 
 /* Line 1457 of yacc.c  */
-#line 1956 "../../../src/parse-gram.c"
+#line 1956 "parse-gram.c"
     break;
 
   case 12:
@@ -1962,7 +1962,7 @@ yyreduce:
     { expected_sr_conflicts = (yyvsp[(2) - (2)].integer); }
 
 /* Line 1457 of yacc.c  */
-#line 1966 "../../../src/parse-gram.c"
+#line 1966 "parse-gram.c"
     break;
 
   case 13:
@@ -1972,7 +1972,7 @@ yyreduce:
     { expected_rr_conflicts = (yyvsp[(2) - (2)].integer); }
 
 /* Line 1457 of yacc.c  */
-#line 1976 "../../../src/parse-gram.c"
+#line 1976 "parse-gram.c"
     break;
 
   case 14:
@@ -1982,7 +1982,7 @@ yyreduce:
     { spec_file_prefix = (yyvsp[(2) - (2)].chars); }
 
 /* Line 1457 of yacc.c  */
-#line 1986 "../../../src/parse-gram.c"
+#line 1986 "parse-gram.c"
     break;
 
   case 15:
@@ -1992,7 +1992,7 @@ yyreduce:
     { spec_file_prefix = (yyvsp[(3) - (3)].chars); }
 
 /* Line 1457 of yacc.c  */
-#line 1996 "../../../src/parse-gram.c"
+#line 1996 "parse-gram.c"
     break;
 
   case 16:
@@ -2005,7 +2005,7 @@ yyreduce:
     }
 
 /* Line 1457 of yacc.c  */
-#line 2009 "../../../src/parse-gram.c"
+#line 2009 "parse-gram.c"
     break;
 
   case 17:
@@ -2022,17 +2022,17 @@ yyreduce:
     }
 
 /* Line 1457 of yacc.c  */
-#line 2026 "../../../src/parse-gram.c"
+#line 2026 "parse-gram.c"
     break;
 
   case 18:
 
 /* Line 1457 of yacc.c  */
 #line 257 "parse-gram.y"
-    { language_argmatch ((yyvsp[(2) - (2)].chars), 1, (yylsp[(1) - (2)])); }
+    { language_argmatch ((yyvsp[(2) - (2)].chars), grammar_prio, (yylsp[(1) - (2)])); }
 
 /* Line 1457 of yacc.c  */
-#line 2036 "../../../src/parse-gram.c"
+#line 2036 "parse-gram.c"
     break;
 
   case 19:
@@ -2042,7 +2042,7 @@ yyreduce:
     { add_param ("lex_param", (yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
 
 /* Line 1457 of yacc.c  */
-#line 2046 "../../../src/parse-gram.c"
+#line 2046 "parse-gram.c"
     break;
 
   case 20:
@@ -2052,7 +2052,7 @@ yyreduce:
     { locations_flag = true; }
 
 /* Line 1457 of yacc.c  */
-#line 2056 "../../../src/parse-gram.c"
+#line 2056 "parse-gram.c"
     break;
 
   case 21:
@@ -2062,7 +2062,7 @@ yyreduce:
     { spec_name_prefix = (yyvsp[(2) - (2)].chars); }
 
 /* Line 1457 of yacc.c  */
-#line 2066 "../../../src/parse-gram.c"
+#line 2066 "parse-gram.c"
     break;
 
   case 22:
@@ -2072,7 +2072,7 @@ yyreduce:
     { spec_name_prefix = (yyvsp[(3) - (3)].chars); }
 
 /* Line 1457 of yacc.c  */
-#line 2076 "../../../src/parse-gram.c"
+#line 2076 "parse-gram.c"
     break;
 
   case 23:
@@ -2082,7 +2082,7 @@ yyreduce:
     { no_lines_flag = true; }
 
 /* Line 1457 of yacc.c  */
-#line 2086 "../../../src/parse-gram.c"
+#line 2086 "parse-gram.c"
     break;
 
   case 24:
@@ -2092,7 +2092,7 @@ yyreduce:
     { nondeterministic_parser = true; }
 
 /* Line 1457 of yacc.c  */
-#line 2096 "../../../src/parse-gram.c"
+#line 2096 "parse-gram.c"
     break;
 
   case 25:
@@ -2102,7 +2102,7 @@ yyreduce:
     { spec_outfile = (yyvsp[(2) - (2)].chars); }
 
 /* Line 1457 of yacc.c  */
-#line 2106 "../../../src/parse-gram.c"
+#line 2106 "parse-gram.c"
     break;
 
   case 26:
@@ -2112,7 +2112,7 @@ yyreduce:
     { spec_outfile = (yyvsp[(3) - (3)].chars); }
 
 /* Line 1457 of yacc.c  */
-#line 2116 "../../../src/parse-gram.c"
+#line 2116 "parse-gram.c"
     break;
 
   case 27:
@@ -2122,7 +2122,7 @@ yyreduce:
     { add_param ("parse_param", (yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
 
 /* Line 1457 of yacc.c  */
-#line 2126 "../../../src/parse-gram.c"
+#line 2126 "parse-gram.c"
     break;
 
   case 28:
@@ -2143,7 +2143,7 @@ yyreduce:
     }
 
 /* Line 1457 of yacc.c  */
-#line 2147 "../../../src/parse-gram.c"
+#line 2147 "parse-gram.c"
     break;
 
   case 29:
@@ -2153,7 +2153,7 @@ yyreduce:
     { version_check (&(yylsp[(2) - (2)]), (yyvsp[(2) - (2)].chars)); }
 
 /* Line 1457 of yacc.c  */
-#line 2157 "../../../src/parse-gram.c"
+#line 2157 "parse-gram.c"
     break;
 
   case 30:
@@ -2181,11 +2181,11 @@ yyreduce:
           skeleton_user = uniqstr_new (skeleton_build);
           free (skeleton_build);
         }
-      skeleton_arg (skeleton_user, 1, (yylsp[(1) - (2)]));
+      skeleton_arg (skeleton_user, grammar_prio, (yylsp[(1) - (2)]));
     }
 
 /* Line 1457 of yacc.c  */
-#line 2189 "../../../src/parse-gram.c"
+#line 2189 "parse-gram.c"
     break;
 
   case 31:
@@ -2195,7 +2195,7 @@ yyreduce:
     { token_table_flag = true; }
 
 /* Line 1457 of yacc.c  */
-#line 2199 "../../../src/parse-gram.c"
+#line 2199 "parse-gram.c"
     break;
 
   case 32:
@@ -2205,7 +2205,7 @@ yyreduce:
     { report_flag |= report_states; }
 
 /* Line 1457 of yacc.c  */
-#line 2209 "../../../src/parse-gram.c"
+#line 2209 "parse-gram.c"
     break;
 
   case 33:
@@ -2215,7 +2215,7 @@ yyreduce:
     { yacc_flag = true; }
 
 /* Line 1457 of yacc.c  */
-#line 2219 "../../../src/parse-gram.c"
+#line 2219 "parse-gram.c"
     break;
 
   case 37:
@@ -2227,7 +2227,7 @@ yyreduce:
     }
 
 /* Line 1457 of yacc.c  */
-#line 2231 "../../../src/parse-gram.c"
+#line 2231 "parse-gram.c"
     break;
 
   case 38:
@@ -2242,7 +2242,7 @@ yyreduce:
     }
 
 /* Line 1457 of yacc.c  */
-#line 2246 "../../../src/parse-gram.c"
+#line 2246 "parse-gram.c"
     break;
 
   case 39:
@@ -2257,7 +2257,7 @@ yyreduce:
     }
 
 /* Line 1457 of yacc.c  */
-#line 2261 "../../../src/parse-gram.c"
+#line 2261 "parse-gram.c"
     break;
 
   case 40:
@@ -2269,7 +2269,7 @@ yyreduce:
     }
 
 /* Line 1457 of yacc.c  */
-#line 2273 "../../../src/parse-gram.c"
+#line 2273 "parse-gram.c"
     break;
 
   case 41:
@@ -2281,7 +2281,7 @@ yyreduce:
     }
 
 /* Line 1457 of yacc.c  */
-#line 2285 "../../../src/parse-gram.c"
+#line 2285 "parse-gram.c"
     break;
 
   case 42:
@@ -2296,7 +2296,7 @@ yyreduce:
     }
 
 /* Line 1457 of yacc.c  */
-#line 2300 "../../../src/parse-gram.c"
+#line 2300 "parse-gram.c"
     break;
 
   case 43:
@@ -2309,7 +2309,7 @@ yyreduce:
     }
 
 /* Line 1457 of yacc.c  */
-#line 2313 "../../../src/parse-gram.c"
+#line 2313 "parse-gram.c"
     break;
 
   case 44:
@@ -2319,7 +2319,7 @@ yyreduce:
     {}
 
 /* Line 1457 of yacc.c  */
-#line 2323 "../../../src/parse-gram.c"
+#line 2323 "parse-gram.c"
     break;
 
   case 45:
@@ -2329,7 +2329,7 @@ yyreduce:
     { muscle_code_grow ("union_name", (yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
 
 /* Line 1457 of yacc.c  */
-#line 2333 "../../../src/parse-gram.c"
+#line 2333 "parse-gram.c"
     break;
 
   case 46:
@@ -2343,7 +2343,7 @@ yyreduce:
     }
 
 /* Line 1457 of yacc.c  */
-#line 2347 "../../../src/parse-gram.c"
+#line 2347 "parse-gram.c"
     break;
 
   case 47:
@@ -2353,7 +2353,7 @@ yyreduce:
     { current_class = nterm_sym; }
 
 /* Line 1457 of yacc.c  */
-#line 2357 "../../../src/parse-gram.c"
+#line 2357 "parse-gram.c"
     break;
 
   case 48:
@@ -2366,7 +2366,7 @@ yyreduce:
     }
 
 /* Line 1457 of yacc.c  */
-#line 2370 "../../../src/parse-gram.c"
+#line 2370 "parse-gram.c"
     break;
 
   case 49:
@@ -2376,7 +2376,7 @@ yyreduce:
     { current_class = token_sym; }
 
 /* Line 1457 of yacc.c  */
-#line 2380 "../../../src/parse-gram.c"
+#line 2380 "parse-gram.c"
     break;
 
   case 50:
@@ -2389,7 +2389,7 @@ yyreduce:
     }
 
 /* Line 1457 of yacc.c  */
-#line 2393 "../../../src/parse-gram.c"
+#line 2393 "parse-gram.c"
     break;
 
   case 51:
@@ -2405,7 +2405,7 @@ yyreduce:
     }
 
 /* Line 1457 of yacc.c  */
-#line 2409 "../../../src/parse-gram.c"
+#line 2409 "parse-gram.c"
     break;
 
   case 52:
@@ -2425,7 +2425,7 @@ yyreduce:
     }
 
 /* Line 1457 of yacc.c  */
-#line 2429 "../../../src/parse-gram.c"
+#line 2429 "parse-gram.c"
     break;
 
   case 53:
@@ -2435,7 +2435,7 @@ yyreduce:
     { (yyval.assoc) = left_assoc; }
 
 /* Line 1457 of yacc.c  */
-#line 2439 "../../../src/parse-gram.c"
+#line 2439 "parse-gram.c"
     break;
 
   case 54:
@@ -2445,7 +2445,7 @@ yyreduce:
     { (yyval.assoc) = right_assoc; }
 
 /* Line 1457 of yacc.c  */
-#line 2449 "../../../src/parse-gram.c"
+#line 2449 "parse-gram.c"
     break;
 
   case 55:
@@ -2455,7 +2455,7 @@ yyreduce:
     { (yyval.assoc) = non_assoc; }
 
 /* Line 1457 of yacc.c  */
-#line 2459 "../../../src/parse-gram.c"
+#line 2459 "parse-gram.c"
     break;
 
   case 56:
@@ -2465,7 +2465,7 @@ yyreduce:
     { current_type = NULL; }
 
 /* Line 1457 of yacc.c  */
-#line 2469 "../../../src/parse-gram.c"
+#line 2469 "parse-gram.c"
     break;
 
   case 57:
@@ -2475,7 +2475,7 @@ yyreduce:
     { current_type = (yyvsp[(1) - (1)].uniqstr); tag_seen = true; }
 
 /* Line 1457 of yacc.c  */
-#line 2479 "../../../src/parse-gram.c"
+#line 2479 "parse-gram.c"
     break;
 
   case 58:
@@ -2485,7 +2485,7 @@ yyreduce:
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
 
 /* Line 1457 of yacc.c  */
-#line 2489 "../../../src/parse-gram.c"
+#line 2489 "parse-gram.c"
     break;
 
   case 59:
@@ -2495,7 +2495,7 @@ yyreduce:
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), symbol_list_sym_new ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]))); }
 
 /* Line 1457 of yacc.c  */
-#line 2499 "../../../src/parse-gram.c"
+#line 2499 "parse-gram.c"
     break;
 
   case 60:
@@ -2505,7 +2505,7 @@ yyreduce:
     { (yyval.symbol) = (yyvsp[(1) - (1)].symbol); }
 
 /* Line 1457 of yacc.c  */
-#line 2509 "../../../src/parse-gram.c"
+#line 2509 "parse-gram.c"
     break;
 
   case 61:
@@ -2515,7 +2515,7 @@ yyreduce:
     { (yyval.symbol) = (yyvsp[(1) - (2)].symbol); symbol_user_token_number_set ((yyvsp[(1) - (2)].symbol), (yyvsp[(2) - (2)].integer), (yylsp[(2) - (2)])); }
 
 /* Line 1457 of yacc.c  */
-#line 2519 "../../../src/parse-gram.c"
+#line 2519 "parse-gram.c"
     break;
 
   case 62:
@@ -2525,7 +2525,7 @@ yyreduce:
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
 
 /* Line 1457 of yacc.c  */
-#line 2529 "../../../src/parse-gram.c"
+#line 2529 "parse-gram.c"
     break;
 
   case 63:
@@ -2535,7 +2535,7 @@ yyreduce:
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), symbol_list_sym_new ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]))); }
 
 /* Line 1457 of yacc.c  */
-#line 2539 "../../../src/parse-gram.c"
+#line 2539 "parse-gram.c"
     break;
 
   case 64:
@@ -2545,7 +2545,7 @@ yyreduce:
     { (yyval.list) = (yyvsp[(1) - (1)].list); }
 
 /* Line 1457 of yacc.c  */
-#line 2549 "../../../src/parse-gram.c"
+#line 2549 "parse-gram.c"
     break;
 
   case 65:
@@ -2555,7 +2555,7 @@ yyreduce:
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), (yyvsp[(2) - (2)].list)); }
 
 /* Line 1457 of yacc.c  */
-#line 2559 "../../../src/parse-gram.c"
+#line 2559 "parse-gram.c"
     break;
 
   case 66:
@@ -2565,7 +2565,7 @@ yyreduce:
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
 
 /* Line 1457 of yacc.c  */
-#line 2569 "../../../src/parse-gram.c"
+#line 2569 "parse-gram.c"
     break;
 
   case 67:
@@ -2575,7 +2575,7 @@ yyreduce:
     { (yyval.list) = symbol_list_type_new ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
 
 /* Line 1457 of yacc.c  */
-#line 2579 "../../../src/parse-gram.c"
+#line 2579 "parse-gram.c"
     break;
 
   case 68:
@@ -2585,7 +2585,7 @@ yyreduce:
     { (yyval.list) = symbol_list_default_tagged_new ((yylsp[(1) - (1)])); }
 
 /* Line 1457 of yacc.c  */
-#line 2589 "../../../src/parse-gram.c"
+#line 2589 "parse-gram.c"
     break;
 
   case 69:
@@ -2595,7 +2595,7 @@ yyreduce:
     { (yyval.list) = symbol_list_default_tagless_new ((yylsp[(1) - (1)])); }
 
 /* Line 1457 of yacc.c  */
-#line 2599 "../../../src/parse-gram.c"
+#line 2599 "parse-gram.c"
     break;
 
   case 70:
@@ -2608,7 +2608,7 @@ yyreduce:
      }
 
 /* Line 1457 of yacc.c  */
-#line 2612 "../../../src/parse-gram.c"
+#line 2612 "parse-gram.c"
     break;
 
   case 71:
@@ -2621,7 +2621,7 @@ yyreduce:
      }
 
 /* Line 1457 of yacc.c  */
-#line 2625 "../../../src/parse-gram.c"
+#line 2625 "parse-gram.c"
     break;
 
   case 72:
@@ -2635,7 +2635,7 @@ yyreduce:
     }
 
 /* Line 1457 of yacc.c  */
-#line 2639 "../../../src/parse-gram.c"
+#line 2639 "parse-gram.c"
     break;
 
   case 73:
@@ -2649,7 +2649,7 @@ yyreduce:
     }
 
 /* Line 1457 of yacc.c  */
-#line 2653 "../../../src/parse-gram.c"
+#line 2653 "parse-gram.c"
     break;
 
   case 74:
@@ -2664,7 +2664,7 @@ yyreduce:
     }
 
 /* Line 1457 of yacc.c  */
-#line 2668 "../../../src/parse-gram.c"
+#line 2668 "parse-gram.c"
     break;
 
   case 81:
@@ -2676,7 +2676,7 @@ yyreduce:
     }
 
 /* Line 1457 of yacc.c  */
-#line 2680 "../../../src/parse-gram.c"
+#line 2680 "parse-gram.c"
     break;
 
   case 82:
@@ -2686,7 +2686,7 @@ yyreduce:
     { current_lhs = (yyvsp[(1) - (1)].symbol); current_lhs_location = (yylsp[(1) - (1)]); }
 
 /* Line 1457 of yacc.c  */
-#line 2690 "../../../src/parse-gram.c"
+#line 2690 "parse-gram.c"
     break;
 
   case 84:
@@ -2696,7 +2696,7 @@ yyreduce:
     { grammar_current_rule_end ((yylsp[(1) - (1)])); }
 
 /* Line 1457 of yacc.c  */
-#line 2700 "../../../src/parse-gram.c"
+#line 2700 "parse-gram.c"
     break;
 
   case 85:
@@ -2706,7 +2706,7 @@ yyreduce:
     { grammar_current_rule_end ((yylsp[(3) - (3)])); }
 
 /* Line 1457 of yacc.c  */
-#line 2710 "../../../src/parse-gram.c"
+#line 2710 "parse-gram.c"
     break;
 
   case 87:
@@ -2716,7 +2716,7 @@ yyreduce:
     { grammar_current_rule_begin (current_lhs, current_lhs_location); }
 
 /* Line 1457 of yacc.c  */
-#line 2720 "../../../src/parse-gram.c"
+#line 2720 "parse-gram.c"
     break;
 
   case 88:
@@ -2726,7 +2726,7 @@ yyreduce:
     { grammar_current_rule_symbol_append ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)])); }
 
 /* Line 1457 of yacc.c  */
-#line 2730 "../../../src/parse-gram.c"
+#line 2730 "parse-gram.c"
     break;
 
   case 89:
@@ -2736,7 +2736,7 @@ yyreduce:
     { grammar_current_rule_action_append ((yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
 
 /* Line 1457 of yacc.c  */
-#line 2740 "../../../src/parse-gram.c"
+#line 2740 "parse-gram.c"
     break;
 
   case 90:
@@ -2746,7 +2746,7 @@ yyreduce:
     { grammar_current_rule_prec_set ((yyvsp[(3) - (3)].symbol), (yylsp[(3) - (3)])); }
 
 /* Line 1457 of yacc.c  */
-#line 2750 "../../../src/parse-gram.c"
+#line 2750 "parse-gram.c"
     break;
 
   case 91:
@@ -2756,7 +2756,7 @@ yyreduce:
     { grammar_current_rule_dprec_set ((yyvsp[(3) - (3)].integer), (yylsp[(3) - (3)])); }
 
 /* Line 1457 of yacc.c  */
-#line 2760 "../../../src/parse-gram.c"
+#line 2760 "parse-gram.c"
     break;
 
   case 92:
@@ -2766,7 +2766,7 @@ yyreduce:
     { grammar_current_rule_merge_set ((yyvsp[(3) - (3)].uniqstr), (yylsp[(3) - (3)])); }
 
 /* Line 1457 of yacc.c  */
-#line 2770 "../../../src/parse-gram.c"
+#line 2770 "parse-gram.c"
     break;
 
   case 94:
@@ -2776,7 +2776,7 @@ yyreduce:
     { (yyval.uniqstr) = uniqstr_new ((yyvsp[(1) - (1)].chars)); }
 
 /* Line 1457 of yacc.c  */
-#line 2780 "../../../src/parse-gram.c"
+#line 2780 "parse-gram.c"
     break;
 
   case 95:
@@ -2788,7 +2788,7 @@ yyreduce:
     }
 
 /* Line 1457 of yacc.c  */
-#line 2792 "../../../src/parse-gram.c"
+#line 2792 "parse-gram.c"
     break;
 
   case 97:
@@ -2805,7 +2805,7 @@ yyreduce:
     }
 
 /* Line 1457 of yacc.c  */
-#line 2809 "../../../src/parse-gram.c"
+#line 2809 "parse-gram.c"
     break;
 
   case 98:
@@ -2815,7 +2815,7 @@ yyreduce:
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
 
 /* Line 1457 of yacc.c  */
-#line 2819 "../../../src/parse-gram.c"
+#line 2819 "parse-gram.c"
     break;
 
   case 99:
@@ -2829,7 +2829,7 @@ yyreduce:
     }
 
 /* Line 1457 of yacc.c  */
-#line 2833 "../../../src/parse-gram.c"
+#line 2833 "parse-gram.c"
     break;
 
   case 100:
@@ -2839,7 +2839,7 @@ yyreduce:
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
 
 /* Line 1457 of yacc.c  */
-#line 2843 "../../../src/parse-gram.c"
+#line 2843 "parse-gram.c"
     break;
 
   case 103:
@@ -2852,7 +2852,7 @@ yyreduce:
     }
 
 /* Line 1457 of yacc.c  */
-#line 2856 "../../../src/parse-gram.c"
+#line 2856 "parse-gram.c"
     break;
 
   case 105:
@@ -2869,13 +2869,13 @@ yyreduce:
     }
 
 /* Line 1457 of yacc.c  */
-#line 2873 "../../../src/parse-gram.c"
+#line 2873 "parse-gram.c"
     break;
 
 
 
 /* Line 1457 of yacc.c  */
-#line 2879 "../../../src/parse-gram.c"
+#line 2879 "parse-gram.c"
       default: break;
     }
   YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);
