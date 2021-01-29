@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 2.4.1.128-4bb9.  */
+/* A Bison parser, made by GNU Bison 2.4.1.137-628b-dirty.  */
 
 /* Skeleton implementation for Bison's Yacc-like parsers in C
    
@@ -45,7 +45,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "2.4.1.128-4bb9"
+#define YYBISON_VERSION "2.4.1.137-628b-dirty"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -74,7 +74,7 @@
 
 /* Copy the first part of user declarations.  */
 
-/* Line 190 of yacc.c  */
+/* Line 252 of yacc.c  */
 #line 1 "parse-gram.y"
 /* Bison Grammar Parser                             -*- C -*-
 
@@ -151,7 +151,7 @@ static int current_prec = 0;
 #define YYTYPE_UINT8 uint_fast8_t
 
 
-/* Line 190 of yacc.c  */
+/* Line 252 of yacc.c  */
 #line 156 "parse-gram.c"
 
 /* Enabling traces.  */
@@ -302,7 +302,7 @@ static int current_prec = 0;
 typedef union YYSTYPE
 {
 
-/* Line 215 of yacc.c  */
+/* Line 277 of yacc.c  */
 #line 94 "parse-gram.y"
 
   symbol *symbol;
@@ -317,7 +317,7 @@ typedef union YYSTYPE
 
 
 
-/* Line 215 of yacc.c  */
+/* Line 277 of yacc.c  */
 #line 322 "parse-gram.c"
 } YYSTYPE;
 # define YYSTYPE_IS_TRIVIAL 1
@@ -342,7 +342,7 @@ typedef struct YYLTYPE
 /* Copy the second part of user declarations.  */
 
 
-/* Line 265 of yacc.c  */
+/* Line 327 of yacc.c  */
 #line 347 "parse-gram.c"
 
 #ifdef short
@@ -1041,146 +1041,146 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
     {
       case 3: /* "\"string\"" */
 
-/* Line 721 of yacc.c  */
+/* Line 783 of yacc.c  */
 #line 184 "parse-gram.y"
 	{ fputs (quotearg_style (c_quoting_style, (yyvaluep->chars)), stderr); };
 
-/* Line 721 of yacc.c  */
+/* Line 783 of yacc.c  */
 #line 1050 "parse-gram.c"
 	break;
       case 4: /* "\"integer\"" */
 
-/* Line 721 of yacc.c  */
+/* Line 783 of yacc.c  */
 #line 196 "parse-gram.y"
 	{ fprintf (stderr, "%d", (yyvaluep->integer)); };
 
-/* Line 721 of yacc.c  */
+/* Line 783 of yacc.c  */
 #line 1059 "parse-gram.c"
 	break;
       case 43: /* "\"{...}\"" */
 
-/* Line 721 of yacc.c  */
+/* Line 783 of yacc.c  */
 #line 186 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->code)); };
 
-/* Line 721 of yacc.c  */
+/* Line 783 of yacc.c  */
 #line 1068 "parse-gram.c"
 	break;
       case 44: /* "\"char\"" */
 
-/* Line 721 of yacc.c  */
+/* Line 783 of yacc.c  */
 #line 178 "parse-gram.y"
 	{ fputs (char_name ((yyvaluep->character)), stderr); };
 
-/* Line 721 of yacc.c  */
+/* Line 783 of yacc.c  */
 #line 1077 "parse-gram.c"
 	break;
       case 45: /* "\"epilogue\"" */
 
-/* Line 721 of yacc.c  */
+/* Line 783 of yacc.c  */
 #line 186 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
-/* Line 721 of yacc.c  */
+/* Line 783 of yacc.c  */
 #line 1086 "parse-gram.c"
 	break;
       case 47: /* "\"identifier\"" */
 
-/* Line 721 of yacc.c  */
+/* Line 783 of yacc.c  */
 #line 192 "parse-gram.y"
 	{ fputs ((yyvaluep->uniqstr), stderr); };
 
-/* Line 721 of yacc.c  */
+/* Line 783 of yacc.c  */
 #line 1095 "parse-gram.c"
 	break;
       case 48: /* "\"identifier:\"" */
 
-/* Line 721 of yacc.c  */
+/* Line 783 of yacc.c  */
 #line 193 "parse-gram.y"
 	{ fprintf (stderr, "%s:", (yyvaluep->uniqstr)); };
 
-/* Line 721 of yacc.c  */
+/* Line 783 of yacc.c  */
 #line 1104 "parse-gram.c"
 	break;
       case 51: /* "\"%{...%}\"" */
 
-/* Line 721 of yacc.c  */
+/* Line 783 of yacc.c  */
 #line 186 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
-/* Line 721 of yacc.c  */
+/* Line 783 of yacc.c  */
 #line 1113 "parse-gram.c"
 	break;
       case 53: /* "\"type\"" */
 
-/* Line 721 of yacc.c  */
+/* Line 783 of yacc.c  */
 #line 191 "parse-gram.y"
 	{ fprintf (stderr, "<%s>", (yyvaluep->uniqstr)); };
 
-/* Line 721 of yacc.c  */
+/* Line 783 of yacc.c  */
 #line 1122 "parse-gram.c"
 	break;
       case 84: /* "variable" */
 
-/* Line 721 of yacc.c  */
+/* Line 783 of yacc.c  */
 #line 192 "parse-gram.y"
 	{ fputs ((yyvaluep->uniqstr), stderr); };
 
-/* Line 721 of yacc.c  */
+/* Line 783 of yacc.c  */
 #line 1131 "parse-gram.c"
 	break;
       case 85: /* "content.opt" */
 
-/* Line 721 of yacc.c  */
+/* Line 783 of yacc.c  */
 #line 186 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
-/* Line 721 of yacc.c  */
+/* Line 783 of yacc.c  */
 #line 1140 "parse-gram.c"
 	break;
       case 86: /* "braceless" */
 
-/* Line 721 of yacc.c  */
+/* Line 783 of yacc.c  */
 #line 186 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
-/* Line 721 of yacc.c  */
+/* Line 783 of yacc.c  */
 #line 1149 "parse-gram.c"
 	break;
       case 87: /* "id" */
 
-/* Line 721 of yacc.c  */
+/* Line 783 of yacc.c  */
 #line 199 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
-/* Line 721 of yacc.c  */
+/* Line 783 of yacc.c  */
 #line 1158 "parse-gram.c"
 	break;
       case 88: /* "id_colon" */
 
-/* Line 721 of yacc.c  */
+/* Line 783 of yacc.c  */
 #line 200 "parse-gram.y"
 	{ fprintf (stderr, "%s:", (yyvaluep->symbol)->tag); };
 
-/* Line 721 of yacc.c  */
+/* Line 783 of yacc.c  */
 #line 1167 "parse-gram.c"
 	break;
       case 89: /* "symbol" */
 
-/* Line 721 of yacc.c  */
+/* Line 783 of yacc.c  */
 #line 199 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
-/* Line 721 of yacc.c  */
+/* Line 783 of yacc.c  */
 #line 1176 "parse-gram.c"
 	break;
       case 90: /* "string_as_id" */
 
-/* Line 721 of yacc.c  */
+/* Line 783 of yacc.c  */
 #line 199 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
-/* Line 721 of yacc.c  */
+/* Line 783 of yacc.c  */
 #line 1185 "parse-gram.c"
 	break;
       default:
@@ -1562,6 +1562,7 @@ yydestruct (yymsg, yytype, yyvaluep, yylocationp)
     }
 }
 
+
 /* Prevent warnings from -Wmissing-prototypes.  */
 #ifdef YYPARSE_PARAM
 #if defined __STDC__ || defined __cplusplus
@@ -1578,12 +1579,9 @@ int yyparse ();
 #endif /* ! YYPARSE_PARAM */
 
 
-
-
-
-/*-------------------------.
-| yyparse or yypush_parse.  |
-`-------------------------*/
+/*----------.
+| yyparse.  |
+`----------*/
 
 #ifdef YYPARSE_PARAM
 #if (defined __STDC__ || defined __C99__FUNC__ \
@@ -1702,7 +1700,7 @@ YYLTYPE yylloc;
 
 /* User initialization code.  */
 
-/* Line 1250 of yacc.c  */
+/* Line 1258 of yacc.c  */
 #line 86 "parse-gram.y"
 {
   /* Bison's grammar can initial empty locations, hence a default
@@ -1711,8 +1709,8 @@ YYLTYPE yylloc;
   boundary_set (&yylloc.end, current_file, 1, 1);
 }
 
-/* Line 1250 of yacc.c  */
-#line 1716 "parse-gram.c"
+/* Line 1258 of yacc.c  */
+#line 1714 "parse-gram.c"
   yylsp[0] = yylloc;
 
   goto yysetstate;
@@ -1899,7 +1897,7 @@ yyreduce:
     {
         case 6:
 
-/* Line 1463 of yacc.c  */
+/* Line 1471 of yacc.c  */
 #line 223 "parse-gram.y"
     {
       code_props plain_code;
@@ -1914,14 +1912,14 @@ yyreduce:
 
   case 7:
 
-/* Line 1463 of yacc.c  */
+/* Line 1471 of yacc.c  */
 #line 232 "parse-gram.y"
     { debug_flag = true; }
     break;
 
   case 8:
 
-/* Line 1463 of yacc.c  */
+/* Line 1471 of yacc.c  */
 #line 234 "parse-gram.y"
     {
       muscle_percent_define_insert ((yyvsp[(2) - (3)].uniqstr), (yylsp[(2) - (3)]), (yyvsp[(3) - (3)].chars),
@@ -1931,14 +1929,14 @@ yyreduce:
 
   case 9:
 
-/* Line 1463 of yacc.c  */
+/* Line 1471 of yacc.c  */
 #line 238 "parse-gram.y"
     { defines_flag = true; }
     break;
 
   case 10:
 
-/* Line 1463 of yacc.c  */
+/* Line 1471 of yacc.c  */
 #line 240 "parse-gram.y"
     {
       defines_flag = true;
@@ -1948,42 +1946,42 @@ yyreduce:
 
   case 11:
 
-/* Line 1463 of yacc.c  */
+/* Line 1471 of yacc.c  */
 #line 244 "parse-gram.y"
     { error_verbose = true; }
     break;
 
   case 12:
 
-/* Line 1463 of yacc.c  */
+/* Line 1471 of yacc.c  */
 #line 245 "parse-gram.y"
     { expected_sr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 13:
 
-/* Line 1463 of yacc.c  */
+/* Line 1471 of yacc.c  */
 #line 246 "parse-gram.y"
     { expected_rr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 14:
 
-/* Line 1463 of yacc.c  */
+/* Line 1471 of yacc.c  */
 #line 247 "parse-gram.y"
     { spec_file_prefix = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 15:
 
-/* Line 1463 of yacc.c  */
+/* Line 1471 of yacc.c  */
 #line 248 "parse-gram.y"
     { spec_file_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 16:
 
-/* Line 1463 of yacc.c  */
+/* Line 1471 of yacc.c  */
 #line 250 "parse-gram.y"
     {
       nondeterministic_parser = true;
@@ -1993,7 +1991,7 @@ yyreduce:
 
   case 17:
 
-/* Line 1463 of yacc.c  */
+/* Line 1471 of yacc.c  */
 #line 255 "parse-gram.y"
     {
       code_props action;
@@ -2007,77 +2005,77 @@ yyreduce:
 
   case 18:
 
-/* Line 1463 of yacc.c  */
+/* Line 1471 of yacc.c  */
 #line 263 "parse-gram.y"
     { language_argmatch ((yyvsp[(2) - (2)].chars), grammar_prio, (yylsp[(1) - (2)])); }
     break;
 
   case 19:
 
-/* Line 1463 of yacc.c  */
+/* Line 1471 of yacc.c  */
 #line 264 "parse-gram.y"
     { add_param ("lex_param", (yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
     break;
 
   case 20:
 
-/* Line 1463 of yacc.c  */
+/* Line 1471 of yacc.c  */
 #line 265 "parse-gram.y"
     { locations_flag = true; }
     break;
 
   case 21:
 
-/* Line 1463 of yacc.c  */
+/* Line 1471 of yacc.c  */
 #line 266 "parse-gram.y"
     { spec_name_prefix = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 22:
 
-/* Line 1463 of yacc.c  */
+/* Line 1471 of yacc.c  */
 #line 267 "parse-gram.y"
     { spec_name_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 23:
 
-/* Line 1463 of yacc.c  */
+/* Line 1471 of yacc.c  */
 #line 268 "parse-gram.y"
     { no_lines_flag = true; }
     break;
 
   case 24:
 
-/* Line 1463 of yacc.c  */
+/* Line 1471 of yacc.c  */
 #line 269 "parse-gram.y"
     { nondeterministic_parser = true; }
     break;
 
   case 25:
 
-/* Line 1463 of yacc.c  */
+/* Line 1471 of yacc.c  */
 #line 270 "parse-gram.y"
     { spec_outfile = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 26:
 
-/* Line 1463 of yacc.c  */
+/* Line 1471 of yacc.c  */
 #line 271 "parse-gram.y"
     { spec_outfile = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 27:
 
-/* Line 1463 of yacc.c  */
+/* Line 1471 of yacc.c  */
 #line 272 "parse-gram.y"
     { add_param ("parse_param", (yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
     break;
 
   case 28:
 
-/* Line 1463 of yacc.c  */
+/* Line 1471 of yacc.c  */
 #line 274 "parse-gram.y"
     {
       /* %pure-parser is deprecated in favor of `%define api.pure', so use
@@ -2097,14 +2095,14 @@ yyreduce:
 
   case 29:
 
-/* Line 1463 of yacc.c  */
+/* Line 1471 of yacc.c  */
 #line 288 "parse-gram.y"
     { version_check (&(yylsp[(2) - (2)]), (yyvsp[(2) - (2)].chars)); }
     break;
 
   case 30:
 
-/* Line 1463 of yacc.c  */
+/* Line 1471 of yacc.c  */
 #line 290 "parse-gram.y"
     {
       char const *skeleton_user = (yyvsp[(2) - (2)].chars);
@@ -2133,28 +2131,28 @@ yyreduce:
 
   case 31:
 
-/* Line 1463 of yacc.c  */
+/* Line 1471 of yacc.c  */
 #line 313 "parse-gram.y"
     { token_table_flag = true; }
     break;
 
   case 32:
 
-/* Line 1463 of yacc.c  */
+/* Line 1471 of yacc.c  */
 #line 314 "parse-gram.y"
     { report_flag |= report_states; }
     break;
 
   case 33:
 
-/* Line 1463 of yacc.c  */
+/* Line 1471 of yacc.c  */
 #line 315 "parse-gram.y"
     { yacc_flag = true; }
     break;
 
   case 37:
 
-/* Line 1463 of yacc.c  */
+/* Line 1471 of yacc.c  */
 #line 323 "parse-gram.y"
     {
       grammar_start_symbol_set ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]));
@@ -2163,7 +2161,7 @@ yyreduce:
 
   case 38:
 
-/* Line 1463 of yacc.c  */
+/* Line 1471 of yacc.c  */
 #line 327 "parse-gram.y"
     {
       symbol_list *list;
@@ -2175,7 +2173,7 @@ yyreduce:
 
   case 39:
 
-/* Line 1463 of yacc.c  */
+/* Line 1471 of yacc.c  */
 #line 334 "parse-gram.y"
     {
       symbol_list *list;
@@ -2187,7 +2185,7 @@ yyreduce:
 
   case 40:
 
-/* Line 1463 of yacc.c  */
+/* Line 1471 of yacc.c  */
 #line 341 "parse-gram.y"
     {
       default_prec = true;
@@ -2196,7 +2194,7 @@ yyreduce:
 
   case 41:
 
-/* Line 1463 of yacc.c  */
+/* Line 1471 of yacc.c  */
 #line 345 "parse-gram.y"
     {
       default_prec = false;
@@ -2205,7 +2203,7 @@ yyreduce:
 
   case 42:
 
-/* Line 1463 of yacc.c  */
+/* Line 1471 of yacc.c  */
 #line 349 "parse-gram.y"
     {
       /* Do not invoke muscle_percent_code_grow here since it invokes
@@ -2217,7 +2215,7 @@ yyreduce:
 
   case 43:
 
-/* Line 1463 of yacc.c  */
+/* Line 1471 of yacc.c  */
 #line 356 "parse-gram.y"
     {
       muscle_percent_code_grow ((yyvsp[(2) - (3)].uniqstr), (yylsp[(2) - (3)]), (yyvsp[(3) - (3)].chars), (yylsp[(3) - (3)]));
@@ -2227,21 +2225,21 @@ yyreduce:
 
   case 44:
 
-/* Line 1463 of yacc.c  */
+/* Line 1471 of yacc.c  */
 #line 370 "parse-gram.y"
     {}
     break;
 
   case 45:
 
-/* Line 1463 of yacc.c  */
+/* Line 1471 of yacc.c  */
 #line 371 "parse-gram.y"
     { muscle_code_grow ("union_name", (yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 46:
 
-/* Line 1463 of yacc.c  */
+/* Line 1471 of yacc.c  */
 #line 376 "parse-gram.y"
     {
       union_seen = true;
@@ -2252,14 +2250,14 @@ yyreduce:
 
   case 47:
 
-/* Line 1463 of yacc.c  */
+/* Line 1471 of yacc.c  */
 #line 387 "parse-gram.y"
     { current_class = nterm_sym; }
     break;
 
   case 48:
 
-/* Line 1463 of yacc.c  */
+/* Line 1471 of yacc.c  */
 #line 388 "parse-gram.y"
     {
       current_class = unknown_sym;
@@ -2269,14 +2267,14 @@ yyreduce:
 
   case 49:
 
-/* Line 1463 of yacc.c  */
+/* Line 1471 of yacc.c  */
 #line 392 "parse-gram.y"
     { current_class = token_sym; }
     break;
 
   case 50:
 
-/* Line 1463 of yacc.c  */
+/* Line 1471 of yacc.c  */
 #line 393 "parse-gram.y"
     {
       current_class = unknown_sym;
@@ -2286,7 +2284,7 @@ yyreduce:
 
   case 51:
 
-/* Line 1463 of yacc.c  */
+/* Line 1471 of yacc.c  */
 #line 398 "parse-gram.y"
     {
       symbol_list *list;
@@ -2299,7 +2297,7 @@ yyreduce:
 
   case 52:
 
-/* Line 1463 of yacc.c  */
+/* Line 1471 of yacc.c  */
 #line 409 "parse-gram.y"
     {
       symbol_list *list;
@@ -2316,126 +2314,126 @@ yyreduce:
 
   case 53:
 
-/* Line 1463 of yacc.c  */
+/* Line 1471 of yacc.c  */
 #line 423 "parse-gram.y"
     { (yyval.assoc) = left_assoc; }
     break;
 
   case 54:
 
-/* Line 1463 of yacc.c  */
+/* Line 1471 of yacc.c  */
 #line 424 "parse-gram.y"
     { (yyval.assoc) = right_assoc; }
     break;
 
   case 55:
 
-/* Line 1463 of yacc.c  */
+/* Line 1471 of yacc.c  */
 #line 425 "parse-gram.y"
     { (yyval.assoc) = non_assoc; }
     break;
 
   case 56:
 
-/* Line 1463 of yacc.c  */
+/* Line 1471 of yacc.c  */
 #line 429 "parse-gram.y"
     { current_type = NULL; }
     break;
 
   case 57:
 
-/* Line 1463 of yacc.c  */
+/* Line 1471 of yacc.c  */
 #line 430 "parse-gram.y"
     { current_type = (yyvsp[(1) - (1)].uniqstr); tag_seen = true; }
     break;
 
   case 58:
 
-/* Line 1463 of yacc.c  */
+/* Line 1471 of yacc.c  */
 #line 436 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 59:
 
-/* Line 1463 of yacc.c  */
+/* Line 1471 of yacc.c  */
 #line 438 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), symbol_list_sym_new ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]))); }
     break;
 
   case 60:
 
-/* Line 1463 of yacc.c  */
+/* Line 1471 of yacc.c  */
 #line 442 "parse-gram.y"
     { (yyval.symbol) = (yyvsp[(1) - (1)].symbol); }
     break;
 
   case 61:
 
-/* Line 1463 of yacc.c  */
+/* Line 1471 of yacc.c  */
 #line 443 "parse-gram.y"
     { (yyval.symbol) = (yyvsp[(1) - (2)].symbol); symbol_user_token_number_set ((yyvsp[(1) - (2)].symbol), (yyvsp[(2) - (2)].integer), (yylsp[(2) - (2)])); }
     break;
 
   case 62:
 
-/* Line 1463 of yacc.c  */
+/* Line 1471 of yacc.c  */
 #line 449 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 63:
 
-/* Line 1463 of yacc.c  */
+/* Line 1471 of yacc.c  */
 #line 451 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), symbol_list_sym_new ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]))); }
     break;
 
   case 64:
 
-/* Line 1463 of yacc.c  */
+/* Line 1471 of yacc.c  */
 #line 455 "parse-gram.y"
     { (yyval.list) = (yyvsp[(1) - (1)].list); }
     break;
 
   case 65:
 
-/* Line 1463 of yacc.c  */
+/* Line 1471 of yacc.c  */
 #line 456 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), (yyvsp[(2) - (2)].list)); }
     break;
 
   case 66:
 
-/* Line 1463 of yacc.c  */
+/* Line 1471 of yacc.c  */
 #line 460 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 67:
 
-/* Line 1463 of yacc.c  */
+/* Line 1471 of yacc.c  */
 #line 461 "parse-gram.y"
     { (yyval.list) = symbol_list_type_new ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 68:
 
-/* Line 1463 of yacc.c  */
+/* Line 1471 of yacc.c  */
 #line 462 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagged_new ((yylsp[(1) - (1)])); }
     break;
 
   case 69:
 
-/* Line 1463 of yacc.c  */
+/* Line 1471 of yacc.c  */
 #line 463 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagless_new ((yylsp[(1) - (1)])); }
     break;
 
   case 70:
 
-/* Line 1463 of yacc.c  */
+/* Line 1471 of yacc.c  */
 #line 469 "parse-gram.y"
     {
        current_type = (yyvsp[(1) - (1)].uniqstr);
@@ -2445,7 +2443,7 @@ yyreduce:
 
   case 71:
 
-/* Line 1463 of yacc.c  */
+/* Line 1471 of yacc.c  */
 #line 474 "parse-gram.y"
     {
        symbol_class_set ((yyvsp[(1) - (1)].symbol), current_class, (yylsp[(1) - (1)]), true);
@@ -2455,7 +2453,7 @@ yyreduce:
 
   case 72:
 
-/* Line 1463 of yacc.c  */
+/* Line 1471 of yacc.c  */
 #line 479 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
@@ -2466,7 +2464,7 @@ yyreduce:
 
   case 73:
 
-/* Line 1463 of yacc.c  */
+/* Line 1471 of yacc.c  */
 #line 485 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
@@ -2477,7 +2475,7 @@ yyreduce:
 
   case 74:
 
-/* Line 1463 of yacc.c  */
+/* Line 1471 of yacc.c  */
 #line 491 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (3)].symbol), current_class, (yylsp[(1) - (3)]), true);
@@ -2489,7 +2487,7 @@ yyreduce:
 
   case 81:
 
-/* Line 1463 of yacc.c  */
+/* Line 1471 of yacc.c  */
 #line 521 "parse-gram.y"
     {
       yyerrok;
@@ -2498,7 +2496,7 @@ yyreduce:
 
   case 82:
 
-/* Line 1463 of yacc.c  */
+/* Line 1471 of yacc.c  */
 #line 527 "parse-gram.y"
     { current_lhs = (yyvsp[(1) - (2)].symbol); current_lhs_location = (yylsp[(1) - (2)]);
     current_lhs_named_ref = (yyvsp[(2) - (2)].named_ref); }
@@ -2506,21 +2504,21 @@ yyreduce:
 
   case 84:
 
-/* Line 1463 of yacc.c  */
+/* Line 1471 of yacc.c  */
 #line 532 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(1) - (1)])); }
     break;
 
   case 85:
 
-/* Line 1463 of yacc.c  */
+/* Line 1471 of yacc.c  */
 #line 533 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(3) - (3)])); }
     break;
 
   case 87:
 
-/* Line 1463 of yacc.c  */
+/* Line 1471 of yacc.c  */
 #line 539 "parse-gram.y"
     { grammar_current_rule_begin (current_lhs, current_lhs_location,
 				  current_lhs_named_ref); }
@@ -2528,77 +2526,77 @@ yyreduce:
 
   case 88:
 
-/* Line 1463 of yacc.c  */
+/* Line 1471 of yacc.c  */
 #line 542 "parse-gram.y"
     { grammar_current_rule_symbol_append ((yyvsp[(2) - (3)].symbol), (yylsp[(2) - (3)]), (yyvsp[(3) - (3)].named_ref)); }
     break;
 
   case 89:
 
-/* Line 1463 of yacc.c  */
+/* Line 1471 of yacc.c  */
 #line 544 "parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[(2) - (3)].code), (yylsp[(2) - (3)]), (yyvsp[(3) - (3)].named_ref)); }
     break;
 
   case 90:
 
-/* Line 1463 of yacc.c  */
+/* Line 1471 of yacc.c  */
 #line 546 "parse-gram.y"
     { grammar_current_rule_prec_set ((yyvsp[(3) - (3)].symbol), (yylsp[(3) - (3)])); }
     break;
 
   case 91:
 
-/* Line 1463 of yacc.c  */
+/* Line 1471 of yacc.c  */
 #line 548 "parse-gram.y"
     { grammar_current_rule_dprec_set ((yyvsp[(3) - (3)].integer), (yylsp[(3) - (3)])); }
     break;
 
   case 92:
 
-/* Line 1463 of yacc.c  */
+/* Line 1471 of yacc.c  */
 #line 550 "parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[(3) - (3)].uniqstr), (yylsp[(3) - (3)])); }
     break;
 
   case 93:
 
-/* Line 1463 of yacc.c  */
+/* Line 1471 of yacc.c  */
 #line 554 "parse-gram.y"
     { (yyval.named_ref) = 0; }
     break;
 
   case 94:
 
-/* Line 1463 of yacc.c  */
+/* Line 1471 of yacc.c  */
 #line 556 "parse-gram.y"
     { (yyval.named_ref) = named_ref_new((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 96:
 
-/* Line 1463 of yacc.c  */
+/* Line 1471 of yacc.c  */
 #line 568 "parse-gram.y"
     { (yyval.uniqstr) = uniqstr_new ((yyvsp[(1) - (1)].chars)); }
     break;
 
   case 97:
 
-/* Line 1463 of yacc.c  */
+/* Line 1471 of yacc.c  */
 #line 573 "parse-gram.y"
     { (yyval.chars) = ""; }
     break;
 
   case 98:
 
-/* Line 1463 of yacc.c  */
+/* Line 1471 of yacc.c  */
 #line 574 "parse-gram.y"
     { (yyval.chars) = (yyvsp[(1) - (1)].uniqstr); }
     break;
 
   case 100:
 
-/* Line 1463 of yacc.c  */
+/* Line 1471 of yacc.c  */
 #line 585 "parse-gram.y"
     {
       code_props plain_code;
@@ -2612,14 +2610,14 @@ yyreduce:
 
   case 101:
 
-/* Line 1463 of yacc.c  */
+/* Line 1471 of yacc.c  */
 #line 605 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 102:
 
-/* Line 1463 of yacc.c  */
+/* Line 1471 of yacc.c  */
 #line 607 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[(1) - (1)].character)), (yylsp[(1) - (1)]));
@@ -2630,14 +2628,14 @@ yyreduce:
 
   case 103:
 
-/* Line 1463 of yacc.c  */
+/* Line 1471 of yacc.c  */
 #line 615 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 106:
 
-/* Line 1463 of yacc.c  */
+/* Line 1471 of yacc.c  */
 #line 627 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[(1) - (1)].chars)), (yylsp[(1) - (1)]));
@@ -2647,7 +2645,7 @@ yyreduce:
 
   case 108:
 
-/* Line 1463 of yacc.c  */
+/* Line 1471 of yacc.c  */
 #line 636 "parse-gram.y"
     {
       code_props plain_code;
@@ -2661,8 +2659,8 @@ yyreduce:
 
 
 
-/* Line 1463 of yacc.c  */
-#line 2666 "parse-gram.c"
+/* Line 1471 of yacc.c  */
+#line 2664 "parse-gram.c"
       default: break;
     }
   YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);
@@ -2880,7 +2878,7 @@ yyreturn:
 
 
 
-/* Line 1683 of yacc.c  */
+/* Line 1691 of yacc.c  */
 #line 646 "parse-gram.y"
 
 
