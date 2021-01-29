@@ -78,7 +78,7 @@
 /* Copy the first part of user declarations.  */
 
 /* Line 1537 of yacc.c  */
-#line 1 "../../src/parse-gram.y"
+#line 1 "parse-gram.y"
 /* Bison Grammar Parser                             -*- C -*-
 
    Copyright (C) 2002, 2003, 2004, 2005, 2006, 2007 Free Software Foundation,
@@ -158,7 +158,7 @@ static int current_prec = 0;
 
 
 /* Line 1537 of yacc.c  */
-#line 162 "../../src/parse-gram.c"
+#line 162 "parse-gram.c"
 
 /* Enabling traces.  */
 #ifndef YYDEBUG
@@ -311,7 +311,7 @@ typedef union YYSTYPE
 {
 
 /* Line 1537 of yacc.c  */
-#line 97 "../../src/parse-gram.y"
+#line 97 "parse-gram.y"
 
   symbol *symbol;
   symbol_list *list;
@@ -325,7 +325,7 @@ typedef union YYSTYPE
 
 
 /* Line 1537 of yacc.c  */
-#line 329 "../../src/parse-gram.c"
+#line 329 "parse-gram.c"
 } YYSTYPE;
 # define YYSTYPE_IS_TRIVIAL 1
 # define yystype YYSTYPE /* obsolescent; will be withdrawn */
@@ -350,7 +350,7 @@ typedef struct YYLTYPE
 
 
 /* Line 1537 of yacc.c  */
-#line 354 "../../src/parse-gram.c"
+#line 354 "parse-gram.c"
 
 #ifdef short
 # undef short
@@ -1041,146 +1041,146 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
       case 3: /* "\"string\"" */
 
 /* Line 1537 of yacc.c  */
-#line 188 "../../src/parse-gram.y"
+#line 188 "parse-gram.y"
 	{ fputs (quotearg_style (c_quoting_style, (yyvaluep->chars)), stderr); };
 
 /* Line 1537 of yacc.c  */
-#line 1049 "../../src/parse-gram.c"
+#line 1049 "parse-gram.c"
 	break;
       case 4: /* "\"integer\"" */
 
 /* Line 1537 of yacc.c  */
-#line 199 "../../src/parse-gram.y"
+#line 199 "parse-gram.y"
 	{ fprintf (stderr, "%d", (yyvaluep->integer)); };
 
 /* Line 1537 of yacc.c  */
-#line 1058 "../../src/parse-gram.c"
+#line 1058 "parse-gram.c"
 	break;
       case 45: /* "\"{...}\"" */
 
 /* Line 1537 of yacc.c  */
-#line 190 "../../src/parse-gram.y"
+#line 190 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->code)); };
 
 /* Line 1537 of yacc.c  */
-#line 1067 "../../src/parse-gram.c"
+#line 1067 "parse-gram.c"
 	break;
       case 46: /* "\"char\"" */
 
 /* Line 1537 of yacc.c  */
-#line 182 "../../src/parse-gram.y"
+#line 182 "parse-gram.y"
 	{ fputs (char_name ((yyvaluep->character)), stderr); };
 
 /* Line 1537 of yacc.c  */
-#line 1076 "../../src/parse-gram.c"
+#line 1076 "parse-gram.c"
 	break;
       case 47: /* "\"epilogue\"" */
 
 /* Line 1537 of yacc.c  */
-#line 190 "../../src/parse-gram.y"
+#line 190 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
 /* Line 1537 of yacc.c  */
-#line 1085 "../../src/parse-gram.c"
+#line 1085 "parse-gram.c"
 	break;
       case 49: /* "\"identifier\"" */
 
 /* Line 1537 of yacc.c  */
-#line 195 "../../src/parse-gram.y"
+#line 195 "parse-gram.y"
 	{ fputs ((yyvaluep->uniqstr), stderr); };
 
 /* Line 1537 of yacc.c  */
-#line 1094 "../../src/parse-gram.c"
+#line 1094 "parse-gram.c"
 	break;
       case 50: /* "\"identifier:\"" */
 
 /* Line 1537 of yacc.c  */
-#line 196 "../../src/parse-gram.y"
+#line 196 "parse-gram.y"
 	{ fprintf (stderr, "%s:", (yyvaluep->uniqstr)); };
 
 /* Line 1537 of yacc.c  */
-#line 1103 "../../src/parse-gram.c"
+#line 1103 "parse-gram.c"
 	break;
       case 53: /* "\"%{...%}\"" */
 
 /* Line 1537 of yacc.c  */
-#line 190 "../../src/parse-gram.y"
+#line 190 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
 /* Line 1537 of yacc.c  */
-#line 1112 "../../src/parse-gram.c"
+#line 1112 "parse-gram.c"
 	break;
       case 55: /* "\"type\"" */
 
 /* Line 1537 of yacc.c  */
-#line 194 "../../src/parse-gram.y"
+#line 194 "parse-gram.y"
 	{ fprintf (stderr, "<%s>", (yyvaluep->uniqstr)); };
 
 /* Line 1537 of yacc.c  */
-#line 1121 "../../src/parse-gram.c"
+#line 1121 "parse-gram.c"
 	break;
       case 82: /* "variable" */
 
 /* Line 1537 of yacc.c  */
-#line 195 "../../src/parse-gram.y"
+#line 195 "parse-gram.y"
 	{ fputs ((yyvaluep->uniqstr), stderr); };
 
 /* Line 1537 of yacc.c  */
-#line 1130 "../../src/parse-gram.c"
+#line 1130 "parse-gram.c"
 	break;
       case 83: /* "content.opt" */
 
 /* Line 1537 of yacc.c  */
-#line 190 "../../src/parse-gram.y"
+#line 190 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
 /* Line 1537 of yacc.c  */
-#line 1139 "../../src/parse-gram.c"
+#line 1139 "parse-gram.c"
 	break;
       case 84: /* "braceless" */
 
 /* Line 1537 of yacc.c  */
-#line 190 "../../src/parse-gram.y"
+#line 190 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
 /* Line 1537 of yacc.c  */
-#line 1148 "../../src/parse-gram.c"
+#line 1148 "parse-gram.c"
 	break;
       case 85: /* "id" */
 
 /* Line 1537 of yacc.c  */
-#line 202 "../../src/parse-gram.y"
+#line 202 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
 /* Line 1537 of yacc.c  */
-#line 1157 "../../src/parse-gram.c"
+#line 1157 "parse-gram.c"
 	break;
       case 86: /* "id_colon" */
 
 /* Line 1537 of yacc.c  */
-#line 203 "../../src/parse-gram.y"
+#line 203 "parse-gram.y"
 	{ fprintf (stderr, "%s:", (yyvaluep->symbol)->tag); };
 
 /* Line 1537 of yacc.c  */
-#line 1166 "../../src/parse-gram.c"
+#line 1166 "parse-gram.c"
 	break;
       case 87: /* "symbol" */
 
 /* Line 1537 of yacc.c  */
-#line 202 "../../src/parse-gram.y"
+#line 202 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
 /* Line 1537 of yacc.c  */
-#line 1175 "../../src/parse-gram.c"
+#line 1175 "parse-gram.c"
 	break;
       case 88: /* "string_as_id" */
 
 /* Line 1537 of yacc.c  */
-#line 202 "../../src/parse-gram.y"
+#line 202 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
 /* Line 1537 of yacc.c  */
-#line 1184 "../../src/parse-gram.c"
+#line 1184 "parse-gram.c"
 	break;
       default:
 	break;
@@ -1272,11 +1272,11 @@ yy_reduce_print (yyvsp, yylsp, yyrule)
   /* The symbols being reduced.  */
   for (yyi = 0; yyi < yynrhs; yyi++)
     {
-      fprintf (stderr, "   $%d = ", yyi + 1);
+      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
       yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
 		       &(yyvsp[(yyi + 1) - (yynrhs)])
 		       , &(yylsp[(yyi + 1) - (yynrhs)])		       );
-      fprintf (stderr, "\n");
+      YYFPRINTF (stderr, "\n");
     }
 }
 
@@ -1695,7 +1695,7 @@ YYLTYPE yylloc;
   /* User initialization code.  */
   
 /* Line 1537 of yacc.c  */
-#line 89 "../../src/parse-gram.y"
+#line 89 "parse-gram.y"
 {
   /* Bison's grammar can initial empty locations, hence a default
      location is needed. */
@@ -1704,7 +1704,7 @@ YYLTYPE yylloc;
 }
 
 /* Line 1537 of yacc.c  */
-#line 1708 "../../src/parse-gram.c"
+#line 1708 "parse-gram.c"
   yylsp[0] = yylloc;
   goto yysetstate;
 
@@ -1890,7 +1890,7 @@ yyreduce:
         case 6:
 
 /* Line 1537 of yacc.c  */
-#line 226 "../../src/parse-gram.y"
+#line 226 "parse-gram.y"
     {
       code_props plain_code;
       code_props_plain_init (&plain_code, (yyvsp[(1) - (1)].chars), (yylsp[(1) - (1)]));
@@ -1905,14 +1905,14 @@ yyreduce:
   case 7:
 
 /* Line 1537 of yacc.c  */
-#line 235 "../../src/parse-gram.y"
+#line 235 "parse-gram.y"
     { debug_flag = true; }
     break;
 
   case 8:
 
 /* Line 1537 of yacc.c  */
-#line 237 "../../src/parse-gram.y"
+#line 237 "parse-gram.y"
     {
       char const name_prefix[] = "percent_define(";
       size_t length = strlen ((yyvsp[(2) - (3)].uniqstr));
@@ -1931,14 +1931,14 @@ yyreduce:
   case 9:
 
 /* Line 1537 of yacc.c  */
-#line 250 "../../src/parse-gram.y"
+#line 250 "parse-gram.y"
     { defines_flag = true; }
     break;
 
   case 10:
 
 /* Line 1537 of yacc.c  */
-#line 252 "../../src/parse-gram.y"
+#line 252 "parse-gram.y"
     {
       defines_flag = true;
       spec_defines_file = xstrdup ((yyvsp[(2) - (2)].chars));
@@ -1948,42 +1948,42 @@ yyreduce:
   case 11:
 
 /* Line 1537 of yacc.c  */
-#line 256 "../../src/parse-gram.y"
+#line 256 "parse-gram.y"
     { error_verbose = true; }
     break;
 
   case 12:
 
 /* Line 1537 of yacc.c  */
-#line 257 "../../src/parse-gram.y"
+#line 257 "parse-gram.y"
     { expected_sr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 13:
 
 /* Line 1537 of yacc.c  */
-#line 258 "../../src/parse-gram.y"
+#line 258 "parse-gram.y"
     { expected_rr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 14:
 
 /* Line 1537 of yacc.c  */
-#line 259 "../../src/parse-gram.y"
+#line 259 "parse-gram.y"
     { spec_file_prefix = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 15:
 
 /* Line 1537 of yacc.c  */
-#line 260 "../../src/parse-gram.y"
+#line 260 "parse-gram.y"
     { spec_file_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 16:
 
 /* Line 1537 of yacc.c  */
-#line 262 "../../src/parse-gram.y"
+#line 262 "parse-gram.y"
     {
       nondeterministic_parser = true;
       glr_parser = true;
@@ -1993,7 +1993,7 @@ yyreduce:
   case 17:
 
 /* Line 1537 of yacc.c  */
-#line 267 "../../src/parse-gram.y"
+#line 267 "parse-gram.y"
     {
       code_props action;
       code_props_symbol_action_init (&action, (yyvsp[(2) - (2)].code), (yylsp[(2) - (2)]));
@@ -2007,105 +2007,105 @@ yyreduce:
   case 18:
 
 /* Line 1537 of yacc.c  */
-#line 275 "../../src/parse-gram.y"
+#line 275 "parse-gram.y"
     { language_argmatch ((yyvsp[(2) - (2)].chars), 1, &(yylsp[(1) - (2)])); }
     break;
 
   case 19:
 
 /* Line 1537 of yacc.c  */
-#line 276 "../../src/parse-gram.y"
+#line 276 "parse-gram.y"
     { add_param ("lex_param", (yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
     break;
 
   case 20:
 
 /* Line 1537 of yacc.c  */
-#line 277 "../../src/parse-gram.y"
+#line 277 "parse-gram.y"
     { locations_flag = true; }
     break;
 
   case 21:
 
 /* Line 1537 of yacc.c  */
-#line 278 "../../src/parse-gram.y"
+#line 278 "parse-gram.y"
     { spec_name_prefix = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 22:
 
 /* Line 1537 of yacc.c  */
-#line 279 "../../src/parse-gram.y"
+#line 279 "parse-gram.y"
     { spec_name_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 23:
 
 /* Line 1537 of yacc.c  */
-#line 280 "../../src/parse-gram.y"
+#line 280 "parse-gram.y"
     { no_lines_flag = true; }
     break;
 
   case 24:
 
 /* Line 1537 of yacc.c  */
-#line 281 "../../src/parse-gram.y"
+#line 281 "parse-gram.y"
     { nondeterministic_parser = true; }
     break;
 
   case 25:
 
 /* Line 1537 of yacc.c  */
-#line 282 "../../src/parse-gram.y"
+#line 282 "parse-gram.y"
     { spec_outfile = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 26:
 
 /* Line 1537 of yacc.c  */
-#line 283 "../../src/parse-gram.y"
+#line 283 "parse-gram.y"
     { spec_outfile = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 27:
 
 /* Line 1537 of yacc.c  */
-#line 284 "../../src/parse-gram.y"
+#line 284 "parse-gram.y"
     { add_param ("parse_param", (yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
     break;
 
   case 28:
 
 /* Line 1537 of yacc.c  */
-#line 285 "../../src/parse-gram.y"
+#line 285 "parse-gram.y"
     { pure_parser = true; }
     break;
 
   case 29:
 
 /* Line 1537 of yacc.c  */
-#line 286 "../../src/parse-gram.y"
+#line 286 "parse-gram.y"
     { push_parser = true; pull_parser = false; }
     break;
 
   case 30:
 
 /* Line 1537 of yacc.c  */
-#line 287 "../../src/parse-gram.y"
+#line 287 "parse-gram.y"
     { push_parser = true; pull_parser = true; }
     break;
 
   case 31:
 
 /* Line 1537 of yacc.c  */
-#line 288 "../../src/parse-gram.y"
+#line 288 "parse-gram.y"
     { version_check (&(yylsp[(2) - (2)]), (yyvsp[(2) - (2)].chars)); }
     break;
 
   case 32:
 
 /* Line 1537 of yacc.c  */
-#line 290 "../../src/parse-gram.y"
+#line 290 "parse-gram.y"
     {
       char const *skeleton_user = (yyvsp[(2) - (2)].chars);
       if (strchr (skeleton_user, '/'))
@@ -2134,28 +2134,28 @@ yyreduce:
   case 33:
 
 /* Line 1537 of yacc.c  */
-#line 313 "../../src/parse-gram.y"
+#line 313 "parse-gram.y"
     { token_table_flag = true; }
     break;
 
   case 34:
 
 /* Line 1537 of yacc.c  */
-#line 314 "../../src/parse-gram.y"
+#line 314 "parse-gram.y"
     { report_flag = report_states; }
     break;
 
   case 35:
 
 /* Line 1537 of yacc.c  */
-#line 315 "../../src/parse-gram.y"
+#line 315 "parse-gram.y"
     { yacc_flag = true; }
     break;
 
   case 39:
 
 /* Line 1537 of yacc.c  */
-#line 323 "../../src/parse-gram.y"
+#line 323 "parse-gram.y"
     {
       grammar_start_symbol_set ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]));
     }
@@ -2164,7 +2164,7 @@ yyreduce:
   case 40:
 
 /* Line 1537 of yacc.c  */
-#line 327 "../../src/parse-gram.y"
+#line 327 "parse-gram.y"
     {
       symbol_list *list;
       for (list = (yyvsp[(3) - (3)].list); list; list = list->next)
@@ -2176,7 +2176,7 @@ yyreduce:
   case 41:
 
 /* Line 1537 of yacc.c  */
-#line 334 "../../src/parse-gram.y"
+#line 334 "parse-gram.y"
     {
       symbol_list *list;
       for (list = (yyvsp[(3) - (3)].list); list; list = list->next)
@@ -2188,7 +2188,7 @@ yyreduce:
   case 42:
 
 /* Line 1537 of yacc.c  */
-#line 341 "../../src/parse-gram.y"
+#line 341 "parse-gram.y"
     {
       default_prec = true;
     }
@@ -2197,7 +2197,7 @@ yyreduce:
   case 43:
 
 /* Line 1537 of yacc.c  */
-#line 345 "../../src/parse-gram.y"
+#line 345 "parse-gram.y"
     {
       default_prec = false;
     }
@@ -2206,7 +2206,7 @@ yyreduce:
   case 44:
 
 /* Line 1537 of yacc.c  */
-#line 349 "../../src/parse-gram.y"
+#line 349 "parse-gram.y"
     {
       muscle_code_grow ("percent_code()", (yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)]));
       code_scanner_last_string_free ();
@@ -2216,7 +2216,7 @@ yyreduce:
   case 45:
 
 /* Line 1537 of yacc.c  */
-#line 354 "../../src/parse-gram.y"
+#line 354 "parse-gram.y"
     {
       char const name_prefix[] = "percent_code(";
       size_t length = strlen ((yyvsp[(2) - (3)].uniqstr));
@@ -2234,21 +2234,21 @@ yyreduce:
   case 46:
 
 /* Line 1537 of yacc.c  */
-#line 376 "../../src/parse-gram.y"
+#line 376 "parse-gram.y"
     {}
     break;
 
   case 47:
 
 /* Line 1537 of yacc.c  */
-#line 377 "../../src/parse-gram.y"
+#line 377 "parse-gram.y"
     { muscle_code_grow ("union_name", (yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 48:
 
 /* Line 1537 of yacc.c  */
-#line 382 "../../src/parse-gram.y"
+#line 382 "parse-gram.y"
     {
       union_seen = true;
       muscle_code_grow ("stype", (yyvsp[(3) - (3)].chars), (yylsp[(3) - (3)]));
@@ -2259,14 +2259,14 @@ yyreduce:
   case 49:
 
 /* Line 1537 of yacc.c  */
-#line 393 "../../src/parse-gram.y"
+#line 393 "parse-gram.y"
     { current_class = nterm_sym; }
     break;
 
   case 50:
 
 /* Line 1537 of yacc.c  */
-#line 394 "../../src/parse-gram.y"
+#line 394 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
@@ -2276,14 +2276,14 @@ yyreduce:
   case 51:
 
 /* Line 1537 of yacc.c  */
-#line 398 "../../src/parse-gram.y"
+#line 398 "parse-gram.y"
     { current_class = token_sym; }
     break;
 
   case 52:
 
 /* Line 1537 of yacc.c  */
-#line 399 "../../src/parse-gram.y"
+#line 399 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
@@ -2293,7 +2293,7 @@ yyreduce:
   case 53:
 
 /* Line 1537 of yacc.c  */
-#line 404 "../../src/parse-gram.y"
+#line 404 "parse-gram.y"
     {
       symbol_list *list;
       tag_seen = true;
@@ -2306,7 +2306,7 @@ yyreduce:
   case 54:
 
 /* Line 1537 of yacc.c  */
-#line 415 "../../src/parse-gram.y"
+#line 415 "parse-gram.y"
     {
       symbol_list *list;
       ++current_prec;
@@ -2323,98 +2323,98 @@ yyreduce:
   case 55:
 
 /* Line 1537 of yacc.c  */
-#line 429 "../../src/parse-gram.y"
+#line 429 "parse-gram.y"
     { (yyval.assoc) = left_assoc; }
     break;
 
   case 56:
 
 /* Line 1537 of yacc.c  */
-#line 430 "../../src/parse-gram.y"
+#line 430 "parse-gram.y"
     { (yyval.assoc) = right_assoc; }
     break;
 
   case 57:
 
 /* Line 1537 of yacc.c  */
-#line 431 "../../src/parse-gram.y"
+#line 431 "parse-gram.y"
     { (yyval.assoc) = non_assoc; }
     break;
 
   case 58:
 
 /* Line 1537 of yacc.c  */
-#line 435 "../../src/parse-gram.y"
+#line 435 "parse-gram.y"
     { current_type = NULL; }
     break;
 
   case 59:
 
 /* Line 1537 of yacc.c  */
-#line 436 "../../src/parse-gram.y"
+#line 436 "parse-gram.y"
     { current_type = (yyvsp[(1) - (1)].uniqstr); tag_seen = true; }
     break;
 
   case 60:
 
 /* Line 1537 of yacc.c  */
-#line 442 "../../src/parse-gram.y"
+#line 442 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 61:
 
 /* Line 1537 of yacc.c  */
-#line 444 "../../src/parse-gram.y"
+#line 444 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), symbol_list_sym_new ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]))); }
     break;
 
   case 62:
 
 /* Line 1537 of yacc.c  */
-#line 448 "../../src/parse-gram.y"
+#line 448 "parse-gram.y"
     { (yyval.list) = (yyvsp[(1) - (1)].list); }
     break;
 
   case 63:
 
 /* Line 1537 of yacc.c  */
-#line 449 "../../src/parse-gram.y"
+#line 449 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), (yyvsp[(2) - (2)].list)); }
     break;
 
   case 64:
 
 /* Line 1537 of yacc.c  */
-#line 453 "../../src/parse-gram.y"
+#line 453 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 65:
 
 /* Line 1537 of yacc.c  */
-#line 454 "../../src/parse-gram.y"
+#line 454 "parse-gram.y"
     { (yyval.list) = symbol_list_type_new ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 66:
 
 /* Line 1537 of yacc.c  */
-#line 455 "../../src/parse-gram.y"
+#line 455 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagged_new ((yylsp[(1) - (1)])); }
     break;
 
   case 67:
 
 /* Line 1537 of yacc.c  */
-#line 456 "../../src/parse-gram.y"
+#line 456 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagless_new ((yylsp[(1) - (1)])); }
     break;
 
   case 68:
 
 /* Line 1537 of yacc.c  */
-#line 462 "../../src/parse-gram.y"
+#line 462 "parse-gram.y"
     {
        current_type = (yyvsp[(1) - (1)].uniqstr);
        tag_seen = true;
@@ -2424,7 +2424,7 @@ yyreduce:
   case 69:
 
 /* Line 1537 of yacc.c  */
-#line 467 "../../src/parse-gram.y"
+#line 467 "parse-gram.y"
     {
        symbol_class_set ((yyvsp[(1) - (1)].symbol), current_class, (yylsp[(1) - (1)]), true);
        symbol_type_set ((yyvsp[(1) - (1)].symbol), current_type, (yylsp[(1) - (1)]));
@@ -2434,7 +2434,7 @@ yyreduce:
   case 70:
 
 /* Line 1537 of yacc.c  */
-#line 472 "../../src/parse-gram.y"
+#line 472 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
       symbol_type_set ((yyvsp[(1) - (2)].symbol), current_type, (yylsp[(1) - (2)]));
@@ -2445,7 +2445,7 @@ yyreduce:
   case 71:
 
 /* Line 1537 of yacc.c  */
-#line 478 "../../src/parse-gram.y"
+#line 478 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
       symbol_type_set ((yyvsp[(1) - (2)].symbol), current_type, (yylsp[(1) - (2)]));
@@ -2456,7 +2456,7 @@ yyreduce:
   case 72:
 
 /* Line 1537 of yacc.c  */
-#line 484 "../../src/parse-gram.y"
+#line 484 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (3)].symbol), current_class, (yylsp[(1) - (3)]), true);
       symbol_type_set ((yyvsp[(1) - (3)].symbol), current_type, (yylsp[(1) - (3)]));
@@ -2468,7 +2468,7 @@ yyreduce:
   case 79:
 
 /* Line 1537 of yacc.c  */
-#line 514 "../../src/parse-gram.y"
+#line 514 "parse-gram.y"
     {
       yyerrok;
     }
@@ -2477,77 +2477,77 @@ yyreduce:
   case 80:
 
 /* Line 1537 of yacc.c  */
-#line 520 "../../src/parse-gram.y"
+#line 520 "parse-gram.y"
     { current_lhs = (yyvsp[(1) - (1)].symbol); current_lhs_location = (yylsp[(1) - (1)]); }
     break;
 
   case 82:
 
 /* Line 1537 of yacc.c  */
-#line 524 "../../src/parse-gram.y"
+#line 524 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(1) - (1)])); }
     break;
 
   case 83:
 
 /* Line 1537 of yacc.c  */
-#line 525 "../../src/parse-gram.y"
+#line 525 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(3) - (3)])); }
     break;
 
   case 85:
 
 /* Line 1537 of yacc.c  */
-#line 531 "../../src/parse-gram.y"
+#line 531 "parse-gram.y"
     { grammar_current_rule_begin (current_lhs, current_lhs_location); }
     break;
 
   case 86:
 
 /* Line 1537 of yacc.c  */
-#line 533 "../../src/parse-gram.y"
+#line 533 "parse-gram.y"
     { grammar_current_rule_symbol_append ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)])); }
     break;
 
   case 87:
 
 /* Line 1537 of yacc.c  */
-#line 535 "../../src/parse-gram.y"
+#line 535 "parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
     break;
 
   case 88:
 
 /* Line 1537 of yacc.c  */
-#line 537 "../../src/parse-gram.y"
+#line 537 "parse-gram.y"
     { grammar_current_rule_prec_set ((yyvsp[(3) - (3)].symbol), (yylsp[(3) - (3)])); }
     break;
 
   case 89:
 
 /* Line 1537 of yacc.c  */
-#line 539 "../../src/parse-gram.y"
+#line 539 "parse-gram.y"
     { grammar_current_rule_dprec_set ((yyvsp[(3) - (3)].integer), (yylsp[(3) - (3)])); }
     break;
 
   case 90:
 
 /* Line 1537 of yacc.c  */
-#line 541 "../../src/parse-gram.y"
+#line 541 "parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[(3) - (3)].uniqstr), (yylsp[(3) - (3)])); }
     break;
 
   case 92:
 
 /* Line 1537 of yacc.c  */
-#line 551 "../../src/parse-gram.y"
+#line 551 "parse-gram.y"
     { (yyval.uniqstr) = uniqstr_new ((yyvsp[(1) - (1)].chars)); }
     break;
 
   case 93:
 
 /* Line 1537 of yacc.c  */
-#line 557 "../../src/parse-gram.y"
+#line 557 "parse-gram.y"
     {
       (yyval.chars) = "";
     }
@@ -2556,7 +2556,7 @@ yyreduce:
   case 95:
 
 /* Line 1537 of yacc.c  */
-#line 570 "../../src/parse-gram.y"
+#line 570 "parse-gram.y"
     {
       code_props plain_code;
       (yyvsp[(1) - (1)].code)[strlen ((yyvsp[(1) - (1)].code)) - 1] = '\n';
@@ -2570,14 +2570,14 @@ yyreduce:
   case 96:
 
 /* Line 1537 of yacc.c  */
-#line 590 "../../src/parse-gram.y"
+#line 590 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 97:
 
 /* Line 1537 of yacc.c  */
-#line 592 "../../src/parse-gram.y"
+#line 592 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[(1) - (1)].character)), (yylsp[(1) - (1)]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[(1) - (1)]), false);
@@ -2588,14 +2588,14 @@ yyreduce:
   case 98:
 
 /* Line 1537 of yacc.c  */
-#line 600 "../../src/parse-gram.y"
+#line 600 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 101:
 
 /* Line 1537 of yacc.c  */
-#line 612 "../../src/parse-gram.y"
+#line 612 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[(1) - (1)].chars)), (yylsp[(1) - (1)]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[(1) - (1)]), false);
@@ -2605,7 +2605,7 @@ yyreduce:
   case 103:
 
 /* Line 1537 of yacc.c  */
-#line 621 "../../src/parse-gram.y"
+#line 621 "parse-gram.y"
     {
       code_props plain_code;
       code_props_plain_init (&plain_code, (yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)]));
@@ -2619,7 +2619,7 @@ yyreduce:
 
 
 /* Line 1537 of yacc.c  */
-#line 2623 "../../src/parse-gram.c"
+#line 2623 "parse-gram.c"
       default: break;
     }
   YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);
@@ -2838,7 +2838,7 @@ yyreturn:
 
 
 /* Line 1537 of yacc.c  */
-#line 631 "../../src/parse-gram.y"
+#line 631 "parse-gram.y"
 
 
 
