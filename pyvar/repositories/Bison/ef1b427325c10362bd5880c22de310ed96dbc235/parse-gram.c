@@ -69,7 +69,7 @@
 
 /* Copy the first part of user declarations.  */
 
-/* Line 1542 of yacc.c  */
+/* Line 22 of yacc.c  */
 #line 1 "parse-gram.y"
 /* Bison Grammar Parser                             -*- C -*-
 
@@ -146,7 +146,7 @@ static int current_prec = 0;
 #define YYTYPE_UINT8 uint_fast8_t
 
 
-/* Line 1542 of yacc.c  */
+/* Line 22 of yacc.c  */
 #line 151 "parse-gram.c"
 
 /* Enabling traces.  */
@@ -295,7 +295,7 @@ static int current_prec = 0;
 typedef union YYSTYPE
 {
 
-/* Line 1542 of yacc.c  */
+/* Line 22 of yacc.c  */
 #line 94 "parse-gram.y"
 
   symbol *symbol;
@@ -309,7 +309,7 @@ typedef union YYSTYPE
 
 
 
-/* Line 1542 of yacc.c  */
+/* Line 22 of yacc.c  */
 #line 314 "parse-gram.c"
 } YYSTYPE;
 # define YYSTYPE_IS_TRIVIAL 1
@@ -334,7 +334,7 @@ typedef struct YYLTYPE
 /* Copy the second part of user declarations.  */
 
 
-/* Line 1542 of yacc.c  */
+/* Line 22 of yacc.c  */
 #line 339 "parse-gram.c"
 
 #ifdef short
@@ -1020,146 +1020,146 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
     {
       case 3: /* "\"string\"" */
 
-/* Line 1542 of yacc.c  */
+/* Line 22 of yacc.c  */
 #line 182 "parse-gram.y"
 	{ fputs (quotearg_style (c_quoting_style, (yyvaluep->chars)), stderr); };
 
-/* Line 1542 of yacc.c  */
+/* Line 22 of yacc.c  */
 #line 1029 "parse-gram.c"
 	break;
       case 4: /* "\"integer\"" */
 
-/* Line 1542 of yacc.c  */
+/* Line 22 of yacc.c  */
 #line 193 "parse-gram.y"
 	{ fprintf (stderr, "%d", (yyvaluep->integer)); };
 
-/* Line 1542 of yacc.c  */
+/* Line 22 of yacc.c  */
 #line 1038 "parse-gram.c"
 	break;
       case 43: /* "\"{...}\"" */
 
-/* Line 1542 of yacc.c  */
+/* Line 22 of yacc.c  */
 #line 184 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->code)); };
 
-/* Line 1542 of yacc.c  */
+/* Line 22 of yacc.c  */
 #line 1047 "parse-gram.c"
 	break;
       case 44: /* "\"char\"" */
 
-/* Line 1542 of yacc.c  */
+/* Line 22 of yacc.c  */
 #line 176 "parse-gram.y"
 	{ fputs (char_name ((yyvaluep->character)), stderr); };
 
-/* Line 1542 of yacc.c  */
+/* Line 22 of yacc.c  */
 #line 1056 "parse-gram.c"
 	break;
       case 45: /* "\"epilogue\"" */
 
-/* Line 1542 of yacc.c  */
+/* Line 22 of yacc.c  */
 #line 184 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
-/* Line 1542 of yacc.c  */
+/* Line 22 of yacc.c  */
 #line 1065 "parse-gram.c"
 	break;
       case 47: /* "\"identifier\"" */
 
-/* Line 1542 of yacc.c  */
+/* Line 22 of yacc.c  */
 #line 189 "parse-gram.y"
 	{ fputs ((yyvaluep->uniqstr), stderr); };
 
-/* Line 1542 of yacc.c  */
+/* Line 22 of yacc.c  */
 #line 1074 "parse-gram.c"
 	break;
       case 48: /* "\"identifier:\"" */
 
-/* Line 1542 of yacc.c  */
+/* Line 22 of yacc.c  */
 #line 190 "parse-gram.y"
 	{ fprintf (stderr, "%s:", (yyvaluep->uniqstr)); };
 
-/* Line 1542 of yacc.c  */
+/* Line 22 of yacc.c  */
 #line 1083 "parse-gram.c"
 	break;
       case 51: /* "\"%{...%}\"" */
 
-/* Line 1542 of yacc.c  */
+/* Line 22 of yacc.c  */
 #line 184 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
-/* Line 1542 of yacc.c  */
+/* Line 22 of yacc.c  */
 #line 1092 "parse-gram.c"
 	break;
       case 53: /* "\"type\"" */
 
-/* Line 1542 of yacc.c  */
+/* Line 22 of yacc.c  */
 #line 188 "parse-gram.y"
 	{ fprintf (stderr, "<%s>", (yyvaluep->uniqstr)); };
 
-/* Line 1542 of yacc.c  */
+/* Line 22 of yacc.c  */
 #line 1101 "parse-gram.c"
 	break;
       case 80: /* "variable" */
 
-/* Line 1542 of yacc.c  */
+/* Line 22 of yacc.c  */
 #line 189 "parse-gram.y"
 	{ fputs ((yyvaluep->uniqstr), stderr); };
 
-/* Line 1542 of yacc.c  */
+/* Line 22 of yacc.c  */
 #line 1110 "parse-gram.c"
 	break;
       case 81: /* "content.opt" */
 
-/* Line 1542 of yacc.c  */
+/* Line 22 of yacc.c  */
 #line 184 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
-/* Line 1542 of yacc.c  */
+/* Line 22 of yacc.c  */
 #line 1119 "parse-gram.c"
 	break;
       case 82: /* "braceless" */
 
-/* Line 1542 of yacc.c  */
+/* Line 22 of yacc.c  */
 #line 184 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
-/* Line 1542 of yacc.c  */
+/* Line 22 of yacc.c  */
 #line 1128 "parse-gram.c"
 	break;
       case 83: /* "id" */
 
-/* Line 1542 of yacc.c  */
+/* Line 22 of yacc.c  */
 #line 196 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
-/* Line 1542 of yacc.c  */
+/* Line 22 of yacc.c  */
 #line 1137 "parse-gram.c"
 	break;
       case 84: /* "id_colon" */
 
-/* Line 1542 of yacc.c  */
+/* Line 22 of yacc.c  */
 #line 197 "parse-gram.y"
 	{ fprintf (stderr, "%s:", (yyvaluep->symbol)->tag); };
 
-/* Line 1542 of yacc.c  */
+/* Line 22 of yacc.c  */
 #line 1146 "parse-gram.c"
 	break;
       case 85: /* "symbol" */
 
-/* Line 1542 of yacc.c  */
+/* Line 22 of yacc.c  */
 #line 196 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
-/* Line 1542 of yacc.c  */
+/* Line 22 of yacc.c  */
 #line 1155 "parse-gram.c"
 	break;
       case 86: /* "string_as_id" */
 
-/* Line 1542 of yacc.c  */
+/* Line 22 of yacc.c  */
 #line 196 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
-/* Line 1542 of yacc.c  */
+/* Line 22 of yacc.c  */
 #line 1164 "parse-gram.c"
 	break;
       default:
@@ -1674,7 +1674,7 @@ YYLTYPE yylloc;
 
   /* User initialization code.  */
   
-/* Line 1542 of yacc.c  */
+/* Line 22 of yacc.c  */
 #line 86 "parse-gram.y"
 {
   /* Bison's grammar can initial empty locations, hence a default
@@ -1683,7 +1683,7 @@ YYLTYPE yylloc;
   boundary_set (&yylloc.end, current_file, 1, 1);
 }
 
-/* Line 1542 of yacc.c  */
+/* Line 22 of yacc.c  */
 #line 1688 "parse-gram.c"
   yylsp[0] = yylloc;
   goto yysetstate;
@@ -1869,7 +1869,7 @@ yyreduce:
     {
         case 6:
 
-/* Line 1542 of yacc.c  */
+/* Line 22 of yacc.c  */
 #line 220 "parse-gram.y"
     {
       code_props plain_code;
@@ -1884,14 +1884,14 @@ yyreduce:
 
   case 7:
 
-/* Line 1542 of yacc.c  */
+/* Line 22 of yacc.c  */
 #line 229 "parse-gram.y"
     { debug_flag = true; }
     break;
 
   case 8:
 
-/* Line 1542 of yacc.c  */
+/* Line 22 of yacc.c  */
 #line 231 "parse-gram.y"
     {
       muscle_percent_define_insert ((yyvsp[(2) - (3)].uniqstr), (yylsp[(2) - (3)]), (yyvsp[(3) - (3)].chars));
@@ -1900,14 +1900,14 @@ yyreduce:
 
   case 9:
 
-/* Line 1542 of yacc.c  */
+/* Line 22 of yacc.c  */
 #line 234 "parse-gram.y"
     { defines_flag = true; }
     break;
 
   case 10:
 
-/* Line 1542 of yacc.c  */
+/* Line 22 of yacc.c  */
 #line 236 "parse-gram.y"
     {
       defines_flag = true;
@@ -1917,42 +1917,42 @@ yyreduce:
 
   case 11:
 
-/* Line 1542 of yacc.c  */
+/* Line 22 of yacc.c  */
 #line 240 "parse-gram.y"
     { error_verbose = true; }
     break;
 
   case 12:
 
-/* Line 1542 of yacc.c  */
+/* Line 22 of yacc.c  */
 #line 241 "parse-gram.y"
     { expected_sr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 13:
 
-/* Line 1542 of yacc.c  */
+/* Line 22 of yacc.c  */
 #line 242 "parse-gram.y"
     { expected_rr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 14:
 
-/* Line 1542 of yacc.c  */
+/* Line 22 of yacc.c  */
 #line 243 "parse-gram.y"
     { spec_file_prefix = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 15:
 
-/* Line 1542 of yacc.c  */
+/* Line 22 of yacc.c  */
 #line 244 "parse-gram.y"
     { spec_file_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 16:
 
-/* Line 1542 of yacc.c  */
+/* Line 22 of yacc.c  */
 #line 246 "parse-gram.y"
     {
       nondeterministic_parser = true;
@@ -1962,7 +1962,7 @@ yyreduce:
 
   case 17:
 
-/* Line 1542 of yacc.c  */
+/* Line 22 of yacc.c  */
 #line 251 "parse-gram.y"
     {
       code_props action;
@@ -1976,77 +1976,77 @@ yyreduce:
 
   case 18:
 
-/* Line 1542 of yacc.c  */
+/* Line 22 of yacc.c  */
 #line 259 "parse-gram.y"
     { language_argmatch ((yyvsp[(2) - (2)].chars), 1, &(yylsp[(1) - (2)])); }
     break;
 
   case 19:
 
-/* Line 1542 of yacc.c  */
+/* Line 22 of yacc.c  */
 #line 260 "parse-gram.y"
     { add_param ("lex_param", (yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
     break;
 
   case 20:
 
-/* Line 1542 of yacc.c  */
+/* Line 22 of yacc.c  */
 #line 261 "parse-gram.y"
     { locations_flag = true; }
     break;
 
   case 21:
 
-/* Line 1542 of yacc.c  */
+/* Line 22 of yacc.c  */
 #line 262 "parse-gram.y"
     { spec_name_prefix = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 22:
 
-/* Line 1542 of yacc.c  */
+/* Line 22 of yacc.c  */
 #line 263 "parse-gram.y"
     { spec_name_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 23:
 
-/* Line 1542 of yacc.c  */
+/* Line 22 of yacc.c  */
 #line 264 "parse-gram.y"
     { no_lines_flag = true; }
     break;
 
   case 24:
 
-/* Line 1542 of yacc.c  */
+/* Line 22 of yacc.c  */
 #line 265 "parse-gram.y"
     { nondeterministic_parser = true; }
     break;
 
   case 25:
 
-/* Line 1542 of yacc.c  */
+/* Line 22 of yacc.c  */
 #line 266 "parse-gram.y"
     { spec_outfile = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 26:
 
-/* Line 1542 of yacc.c  */
+/* Line 22 of yacc.c  */
 #line 267 "parse-gram.y"
     { spec_outfile = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 27:
 
-/* Line 1542 of yacc.c  */
+/* Line 22 of yacc.c  */
 #line 268 "parse-gram.y"
     { add_param ("parse_param", (yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
     break;
 
   case 28:
 
-/* Line 1542 of yacc.c  */
+/* Line 22 of yacc.c  */
 #line 270 "parse-gram.y"
     {
       /* %pure-parser is deprecated in favor of `%define api.pure', so use
@@ -2064,14 +2064,14 @@ yyreduce:
 
   case 29:
 
-/* Line 1542 of yacc.c  */
+/* Line 22 of yacc.c  */
 #line 282 "parse-gram.y"
     { version_check (&(yylsp[(2) - (2)]), (yyvsp[(2) - (2)].chars)); }
     break;
 
   case 30:
 
-/* Line 1542 of yacc.c  */
+/* Line 22 of yacc.c  */
 #line 284 "parse-gram.y"
     {
       char const *skeleton_user = (yyvsp[(2) - (2)].chars);
@@ -2100,28 +2100,28 @@ yyreduce:
 
   case 31:
 
-/* Line 1542 of yacc.c  */
+/* Line 22 of yacc.c  */
 #line 307 "parse-gram.y"
     { token_table_flag = true; }
     break;
 
   case 32:
 
-/* Line 1542 of yacc.c  */
+/* Line 22 of yacc.c  */
 #line 308 "parse-gram.y"
-    { report_flag = report_states; }
+    { report_flag |= report_states; }
     break;
 
   case 33:
 
-/* Line 1542 of yacc.c  */
+/* Line 22 of yacc.c  */
 #line 309 "parse-gram.y"
     { yacc_flag = true; }
     break;
 
   case 37:
 
-/* Line 1542 of yacc.c  */
+/* Line 22 of yacc.c  */
 #line 317 "parse-gram.y"
     {
       grammar_start_symbol_set ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]));
@@ -2130,7 +2130,7 @@ yyreduce:
 
   case 38:
 
-/* Line 1542 of yacc.c  */
+/* Line 22 of yacc.c  */
 #line 321 "parse-gram.y"
     {
       symbol_list *list;
@@ -2142,7 +2142,7 @@ yyreduce:
 
   case 39:
 
-/* Line 1542 of yacc.c  */
+/* Line 22 of yacc.c  */
 #line 328 "parse-gram.y"
     {
       symbol_list *list;
@@ -2154,7 +2154,7 @@ yyreduce:
 
   case 40:
 
-/* Line 1542 of yacc.c  */
+/* Line 22 of yacc.c  */
 #line 335 "parse-gram.y"
     {
       default_prec = true;
@@ -2163,7 +2163,7 @@ yyreduce:
 
   case 41:
 
-/* Line 1542 of yacc.c  */
+/* Line 22 of yacc.c  */
 #line 339 "parse-gram.y"
     {
       default_prec = false;
@@ -2172,7 +2172,7 @@ yyreduce:
 
   case 42:
 
-/* Line 1542 of yacc.c  */
+/* Line 22 of yacc.c  */
 #line 343 "parse-gram.y"
     {
       /* Do not invoke muscle_percent_code_grow here since it invokes
@@ -2184,7 +2184,7 @@ yyreduce:
 
   case 43:
 
-/* Line 1542 of yacc.c  */
+/* Line 22 of yacc.c  */
 #line 350 "parse-gram.y"
     {
       muscle_percent_code_grow ((yyvsp[(2) - (3)].uniqstr), (yylsp[(2) - (3)]), (yyvsp[(3) - (3)].chars), (yylsp[(3) - (3)]));
@@ -2194,21 +2194,21 @@ yyreduce:
 
   case 44:
 
-/* Line 1542 of yacc.c  */
+/* Line 22 of yacc.c  */
 #line 364 "parse-gram.y"
     {}
     break;
 
   case 45:
 
-/* Line 1542 of yacc.c  */
+/* Line 22 of yacc.c  */
 #line 365 "parse-gram.y"
     { muscle_code_grow ("union_name", (yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 46:
 
-/* Line 1542 of yacc.c  */
+/* Line 22 of yacc.c  */
 #line 370 "parse-gram.y"
     {
       union_seen = true;
@@ -2219,14 +2219,14 @@ yyreduce:
 
   case 47:
 
-/* Line 1542 of yacc.c  */
+/* Line 22 of yacc.c  */
 #line 381 "parse-gram.y"
     { current_class = nterm_sym; }
     break;
 
   case 48:
 
-/* Line 1542 of yacc.c  */
+/* Line 22 of yacc.c  */
 #line 382 "parse-gram.y"
     {
       current_class = unknown_sym;
@@ -2236,14 +2236,14 @@ yyreduce:
 
   case 49:
 
-/* Line 1542 of yacc.c  */
+/* Line 22 of yacc.c  */
 #line 386 "parse-gram.y"
     { current_class = token_sym; }
     break;
 
   case 50:
 
-/* Line 1542 of yacc.c  */
+/* Line 22 of yacc.c  */
 #line 387 "parse-gram.y"
     {
       current_class = unknown_sym;
@@ -2253,7 +2253,7 @@ yyreduce:
 
   case 51:
 
-/* Line 1542 of yacc.c  */
+/* Line 22 of yacc.c  */
 #line 392 "parse-gram.y"
     {
       symbol_list *list;
@@ -2266,7 +2266,7 @@ yyreduce:
 
   case 52:
 
-/* Line 1542 of yacc.c  */
+/* Line 22 of yacc.c  */
 #line 403 "parse-gram.y"
     {
       symbol_list *list;
@@ -2283,98 +2283,98 @@ yyreduce:
 
   case 53:
 
-/* Line 1542 of yacc.c  */
+/* Line 22 of yacc.c  */
 #line 417 "parse-gram.y"
     { (yyval.assoc) = left_assoc; }
     break;
 
   case 54:
 
-/* Line 1542 of yacc.c  */
+/* Line 22 of yacc.c  */
 #line 418 "parse-gram.y"
     { (yyval.assoc) = right_assoc; }
     break;
 
   case 55:
 
-/* Line 1542 of yacc.c  */
+/* Line 22 of yacc.c  */
 #line 419 "parse-gram.y"
     { (yyval.assoc) = non_assoc; }
     break;
 
   case 56:
 
-/* Line 1542 of yacc.c  */
+/* Line 22 of yacc.c  */
 #line 423 "parse-gram.y"
     { current_type = NULL; }
     break;
 
   case 57:
 
-/* Line 1542 of yacc.c  */
+/* Line 22 of yacc.c  */
 #line 424 "parse-gram.y"
     { current_type = (yyvsp[(1) - (1)].uniqstr); tag_seen = true; }
     break;
 
   case 58:
 
-/* Line 1542 of yacc.c  */
+/* Line 22 of yacc.c  */
 #line 430 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 59:
 
-/* Line 1542 of yacc.c  */
+/* Line 22 of yacc.c  */
 #line 432 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), symbol_list_sym_new ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]))); }
     break;
 
   case 60:
 
-/* Line 1542 of yacc.c  */
+/* Line 22 of yacc.c  */
 #line 436 "parse-gram.y"
     { (yyval.list) = (yyvsp[(1) - (1)].list); }
     break;
 
   case 61:
 
-/* Line 1542 of yacc.c  */
+/* Line 22 of yacc.c  */
 #line 437 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), (yyvsp[(2) - (2)].list)); }
     break;
 
   case 62:
 
-/* Line 1542 of yacc.c  */
+/* Line 22 of yacc.c  */
 #line 441 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 63:
 
-/* Line 1542 of yacc.c  */
+/* Line 22 of yacc.c  */
 #line 442 "parse-gram.y"
     { (yyval.list) = symbol_list_type_new ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 64:
 
-/* Line 1542 of yacc.c  */
+/* Line 22 of yacc.c  */
 #line 443 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagged_new ((yylsp[(1) - (1)])); }
     break;
 
   case 65:
 
-/* Line 1542 of yacc.c  */
+/* Line 22 of yacc.c  */
 #line 444 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagless_new ((yylsp[(1) - (1)])); }
     break;
 
   case 66:
 
-/* Line 1542 of yacc.c  */
+/* Line 22 of yacc.c  */
 #line 450 "parse-gram.y"
     {
        current_type = (yyvsp[(1) - (1)].uniqstr);
@@ -2384,7 +2384,7 @@ yyreduce:
 
   case 67:
 
-/* Line 1542 of yacc.c  */
+/* Line 22 of yacc.c  */
 #line 455 "parse-gram.y"
     {
        symbol_class_set ((yyvsp[(1) - (1)].symbol), current_class, (yylsp[(1) - (1)]), true);
@@ -2394,7 +2394,7 @@ yyreduce:
 
   case 68:
 
-/* Line 1542 of yacc.c  */
+/* Line 22 of yacc.c  */
 #line 460 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
@@ -2405,7 +2405,7 @@ yyreduce:
 
   case 69:
 
-/* Line 1542 of yacc.c  */
+/* Line 22 of yacc.c  */
 #line 466 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
@@ -2416,7 +2416,7 @@ yyreduce:
 
   case 70:
 
-/* Line 1542 of yacc.c  */
+/* Line 22 of yacc.c  */
 #line 472 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (3)].symbol), current_class, (yylsp[(1) - (3)]), true);
@@ -2428,7 +2428,7 @@ yyreduce:
 
   case 77:
 
-/* Line 1542 of yacc.c  */
+/* Line 22 of yacc.c  */
 #line 502 "parse-gram.y"
     {
       yyerrok;
@@ -2437,77 +2437,77 @@ yyreduce:
 
   case 78:
 
-/* Line 1542 of yacc.c  */
+/* Line 22 of yacc.c  */
 #line 508 "parse-gram.y"
     { current_lhs = (yyvsp[(1) - (1)].symbol); current_lhs_location = (yylsp[(1) - (1)]); }
     break;
 
   case 80:
 
-/* Line 1542 of yacc.c  */
+/* Line 22 of yacc.c  */
 #line 512 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(1) - (1)])); }
     break;
 
   case 81:
 
-/* Line 1542 of yacc.c  */
+/* Line 22 of yacc.c  */
 #line 513 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(3) - (3)])); }
     break;
 
   case 83:
 
-/* Line 1542 of yacc.c  */
+/* Line 22 of yacc.c  */
 #line 519 "parse-gram.y"
     { grammar_current_rule_begin (current_lhs, current_lhs_location); }
     break;
 
   case 84:
 
-/* Line 1542 of yacc.c  */
+/* Line 22 of yacc.c  */
 #line 521 "parse-gram.y"
     { grammar_current_rule_symbol_append ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)])); }
     break;
 
   case 85:
 
-/* Line 1542 of yacc.c  */
+/* Line 22 of yacc.c  */
 #line 523 "parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
     break;
 
   case 86:
 
-/* Line 1542 of yacc.c  */
+/* Line 22 of yacc.c  */
 #line 525 "parse-gram.y"
     { grammar_current_rule_prec_set ((yyvsp[(3) - (3)].symbol), (yylsp[(3) - (3)])); }
     break;
 
   case 87:
 
-/* Line 1542 of yacc.c  */
+/* Line 22 of yacc.c  */
 #line 527 "parse-gram.y"
     { grammar_current_rule_dprec_set ((yyvsp[(3) - (3)].integer), (yylsp[(3) - (3)])); }
     break;
 
   case 88:
 
-/* Line 1542 of yacc.c  */
+/* Line 22 of yacc.c  */
 #line 529 "parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[(3) - (3)].uniqstr), (yylsp[(3) - (3)])); }
     break;
 
   case 90:
 
-/* Line 1542 of yacc.c  */
+/* Line 22 of yacc.c  */
 #line 539 "parse-gram.y"
     { (yyval.uniqstr) = uniqstr_new ((yyvsp[(1) - (1)].chars)); }
     break;
 
   case 91:
 
-/* Line 1542 of yacc.c  */
+/* Line 22 of yacc.c  */
 #line 545 "parse-gram.y"
     {
       (yyval.chars) = "";
@@ -2516,7 +2516,7 @@ yyreduce:
 
   case 93:
 
-/* Line 1542 of yacc.c  */
+/* Line 22 of yacc.c  */
 #line 558 "parse-gram.y"
     {
       code_props plain_code;
@@ -2530,14 +2530,14 @@ yyreduce:
 
   case 94:
 
-/* Line 1542 of yacc.c  */
+/* Line 22 of yacc.c  */
 #line 578 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 95:
 
-/* Line 1542 of yacc.c  */
+/* Line 22 of yacc.c  */
 #line 580 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[(1) - (1)].character)), (yylsp[(1) - (1)]));
@@ -2548,14 +2548,14 @@ yyreduce:
 
   case 96:
 
-/* Line 1542 of yacc.c  */
+/* Line 22 of yacc.c  */
 #line 588 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 99:
 
-/* Line 1542 of yacc.c  */
+/* Line 22 of yacc.c  */
 #line 600 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[(1) - (1)].chars)), (yylsp[(1) - (1)]));
@@ -2565,7 +2565,7 @@ yyreduce:
 
   case 101:
 
-/* Line 1542 of yacc.c  */
+/* Line 22 of yacc.c  */
 #line 609 "parse-gram.y"
     {
       code_props plain_code;
@@ -2579,7 +2579,7 @@ yyreduce:
 
 
 
-/* Line 1542 of yacc.c  */
+/* Line 22 of yacc.c  */
 #line 2584 "parse-gram.c"
       default: break;
     }
@@ -2798,7 +2798,7 @@ yyreturn:
 
 
 
-/* Line 1542 of yacc.c  */
+/* Line 22 of yacc.c  */
 #line 619 "parse-gram.y"
 
 
