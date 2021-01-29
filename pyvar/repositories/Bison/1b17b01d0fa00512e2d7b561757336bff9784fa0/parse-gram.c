@@ -75,7 +75,7 @@
 
 /* Copy the first part of user declarations.  */
 
-/* Line 22 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 1 "parse-gram.y"
 /* Bison Grammar Parser                             -*- C -*-
 
@@ -152,7 +152,7 @@ static int current_prec = 0;
 #define YYTYPE_UINT8 uint_fast8_t
 
 
-/* Line 22 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 157 "parse-gram.c"
 
 /* Enabling traces.  */
@@ -305,7 +305,7 @@ static int current_prec = 0;
 typedef union YYSTYPE
 {
 
-/* Line 22 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 94 "parse-gram.y"
 
   symbol *symbol;
@@ -319,7 +319,7 @@ typedef union YYSTYPE
 
 
 
-/* Line 22 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 324 "parse-gram.c"
 } YYSTYPE;
 # define YYSTYPE_IS_TRIVIAL 1
@@ -344,7 +344,7 @@ typedef struct YYLTYPE
 /* Copy the second part of user declarations.  */
 
 
-/* Line 22 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 349 "parse-gram.c"
 
 #ifdef short
@@ -1035,146 +1035,146 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
     {
       case 3: /* "\"string\"" */
 
-/* Line 22 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 185 "parse-gram.y"
 	{ fputs (quotearg_style (c_quoting_style, (yyvaluep->chars)), stderr); };
 
-/* Line 22 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 1044 "parse-gram.c"
 	break;
       case 4: /* "\"integer\"" */
 
-/* Line 22 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 196 "parse-gram.y"
 	{ fprintf (stderr, "%d", (yyvaluep->integer)); };
 
-/* Line 22 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 1053 "parse-gram.c"
 	break;
       case 45: /* "\"{...}\"" */
 
-/* Line 22 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 187 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->code)); };
 
-/* Line 22 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 1062 "parse-gram.c"
 	break;
       case 46: /* "\"char\"" */
 
-/* Line 22 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 179 "parse-gram.y"
 	{ fputs (char_name ((yyvaluep->character)), stderr); };
 
-/* Line 22 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 1071 "parse-gram.c"
 	break;
       case 47: /* "\"epilogue\"" */
 
-/* Line 22 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 187 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
-/* Line 22 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 1080 "parse-gram.c"
 	break;
       case 49: /* "\"identifier\"" */
 
-/* Line 22 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 192 "parse-gram.y"
 	{ fputs ((yyvaluep->uniqstr), stderr); };
 
-/* Line 22 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 1089 "parse-gram.c"
 	break;
       case 50: /* "\"identifier:\"" */
 
-/* Line 22 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 193 "parse-gram.y"
 	{ fprintf (stderr, "%s:", (yyvaluep->uniqstr)); };
 
-/* Line 22 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 1098 "parse-gram.c"
 	break;
       case 53: /* "\"%{...%}\"" */
 
-/* Line 22 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 187 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
-/* Line 22 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 1107 "parse-gram.c"
 	break;
       case 55: /* "\"type\"" */
 
-/* Line 22 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 191 "parse-gram.y"
 	{ fprintf (stderr, "<%s>", (yyvaluep->uniqstr)); };
 
-/* Line 22 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 1116 "parse-gram.c"
 	break;
       case 82: /* "variable" */
 
-/* Line 22 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 192 "parse-gram.y"
 	{ fputs ((yyvaluep->uniqstr), stderr); };
 
-/* Line 22 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 1125 "parse-gram.c"
 	break;
       case 83: /* "content.opt" */
 
-/* Line 22 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 187 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
-/* Line 22 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 1134 "parse-gram.c"
 	break;
       case 84: /* "braceless" */
 
-/* Line 22 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 187 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
-/* Line 22 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 1143 "parse-gram.c"
 	break;
       case 85: /* "id" */
 
-/* Line 22 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 199 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
-/* Line 22 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 1152 "parse-gram.c"
 	break;
       case 86: /* "id_colon" */
 
-/* Line 22 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 200 "parse-gram.y"
 	{ fprintf (stderr, "%s:", (yyvaluep->symbol)->tag); };
 
-/* Line 22 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 1161 "parse-gram.c"
 	break;
       case 87: /* "symbol" */
 
-/* Line 22 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 199 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
-/* Line 22 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 1170 "parse-gram.c"
 	break;
       case 88: /* "string_as_id" */
 
-/* Line 22 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 199 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
-/* Line 22 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 1179 "parse-gram.c"
 	break;
       default:
@@ -1689,7 +1689,7 @@ YYLTYPE yylloc;
 
   /* User initialization code.  */
   
-/* Line 22 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 86 "parse-gram.y"
 {
   /* Bison's grammar can initial empty locations, hence a default
@@ -1698,7 +1698,7 @@ YYLTYPE yylloc;
   boundary_set (&yylloc.end, current_file, 1, 1);
 }
 
-/* Line 22 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 1703 "parse-gram.c"
   yylsp[0] = yylloc;
   goto yysetstate;
@@ -1884,7 +1884,7 @@ yyreduce:
     {
         case 6:
 
-/* Line 22 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 223 "parse-gram.y"
     {
       code_props plain_code;
@@ -1899,14 +1899,14 @@ yyreduce:
 
   case 7:
 
-/* Line 22 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 232 "parse-gram.y"
     { debug_flag = true; }
     break;
 
   case 8:
 
-/* Line 22 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 234 "parse-gram.y"
     {
       muscle_percent_define_insert ((yyvsp[(2) - (3)].uniqstr), (yylsp[(2) - (3)]), (yyvsp[(3) - (3)].chars));
@@ -1915,14 +1915,14 @@ yyreduce:
 
   case 9:
 
-/* Line 22 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 237 "parse-gram.y"
     { defines_flag = true; }
     break;
 
   case 10:
 
-/* Line 22 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 239 "parse-gram.y"
     {
       defines_flag = true;
@@ -1932,42 +1932,42 @@ yyreduce:
 
   case 11:
 
-/* Line 22 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 243 "parse-gram.y"
     { error_verbose = true; }
     break;
 
   case 12:
 
-/* Line 22 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 244 "parse-gram.y"
     { expected_sr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 13:
 
-/* Line 22 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 245 "parse-gram.y"
     { expected_rr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 14:
 
-/* Line 22 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 246 "parse-gram.y"
     { spec_file_prefix = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 15:
 
-/* Line 22 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 247 "parse-gram.y"
     { spec_file_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 16:
 
-/* Line 22 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 249 "parse-gram.y"
     {
       nondeterministic_parser = true;
@@ -1977,7 +1977,7 @@ yyreduce:
 
   case 17:
 
-/* Line 22 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 254 "parse-gram.y"
     {
       code_props action;
@@ -1991,105 +1991,105 @@ yyreduce:
 
   case 18:
 
-/* Line 22 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 262 "parse-gram.y"
     { language_argmatch ((yyvsp[(2) - (2)].chars), 1, &(yylsp[(1) - (2)])); }
     break;
 
   case 19:
 
-/* Line 22 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 263 "parse-gram.y"
     { add_param ("lex_param", (yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
     break;
 
   case 20:
 
-/* Line 22 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 264 "parse-gram.y"
     { locations_flag = true; }
     break;
 
   case 21:
 
-/* Line 22 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 265 "parse-gram.y"
     { spec_name_prefix = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 22:
 
-/* Line 22 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 266 "parse-gram.y"
     { spec_name_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 23:
 
-/* Line 22 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 267 "parse-gram.y"
     { no_lines_flag = true; }
     break;
 
   case 24:
 
-/* Line 22 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 268 "parse-gram.y"
     { nondeterministic_parser = true; }
     break;
 
   case 25:
 
-/* Line 22 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 269 "parse-gram.y"
     { spec_outfile = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 26:
 
-/* Line 22 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 270 "parse-gram.y"
     { spec_outfile = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 27:
 
-/* Line 22 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 271 "parse-gram.y"
     { add_param ("parse_param", (yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
     break;
 
   case 28:
 
-/* Line 22 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 272 "parse-gram.y"
     { pure_parser = true; }
     break;
 
   case 29:
 
-/* Line 22 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 273 "parse-gram.y"
     { push_parser = true; pull_parser = false; }
     break;
 
   case 30:
 
-/* Line 22 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 274 "parse-gram.y"
     { push_parser = true; pull_parser = true; }
     break;
 
   case 31:
 
-/* Line 22 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 275 "parse-gram.y"
     { version_check (&(yylsp[(2) - (2)]), (yyvsp[(2) - (2)].chars)); }
     break;
 
   case 32:
 
-/* Line 22 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 277 "parse-gram.y"
     {
       char const *skeleton_user = (yyvsp[(2) - (2)].chars);
@@ -2118,28 +2118,28 @@ yyreduce:
 
   case 33:
 
-/* Line 22 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 300 "parse-gram.y"
     { token_table_flag = true; }
     break;
 
   case 34:
 
-/* Line 22 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 301 "parse-gram.y"
     { report_flag = report_states; }
     break;
 
   case 35:
 
-/* Line 22 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 302 "parse-gram.y"
     { yacc_flag = true; }
     break;
 
   case 39:
 
-/* Line 22 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 310 "parse-gram.y"
     {
       grammar_start_symbol_set ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]));
@@ -2148,7 +2148,7 @@ yyreduce:
 
   case 40:
 
-/* Line 22 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 314 "parse-gram.y"
     {
       symbol_list *list;
@@ -2160,7 +2160,7 @@ yyreduce:
 
   case 41:
 
-/* Line 22 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 321 "parse-gram.y"
     {
       symbol_list *list;
@@ -2172,7 +2172,7 @@ yyreduce:
 
   case 42:
 
-/* Line 22 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 328 "parse-gram.y"
     {
       default_prec = true;
@@ -2181,7 +2181,7 @@ yyreduce:
 
   case 43:
 
-/* Line 22 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 332 "parse-gram.y"
     {
       default_prec = false;
@@ -2190,7 +2190,7 @@ yyreduce:
 
   case 44:
 
-/* Line 22 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 336 "parse-gram.y"
     {
       /* Do not invoke muscle_percent_code_grow here since it invokes
@@ -2202,7 +2202,7 @@ yyreduce:
 
   case 45:
 
-/* Line 22 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 343 "parse-gram.y"
     {
       muscle_percent_code_grow ((yyvsp[(2) - (3)].uniqstr), (yylsp[(2) - (3)]), (yyvsp[(3) - (3)].chars), (yylsp[(3) - (3)]));
@@ -2212,21 +2212,21 @@ yyreduce:
 
   case 46:
 
-/* Line 22 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 357 "parse-gram.y"
     {}
     break;
 
   case 47:
 
-/* Line 22 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 358 "parse-gram.y"
     { muscle_code_grow ("union_name", (yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 48:
 
-/* Line 22 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 363 "parse-gram.y"
     {
       union_seen = true;
@@ -2237,14 +2237,14 @@ yyreduce:
 
   case 49:
 
-/* Line 22 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 374 "parse-gram.y"
     { current_class = nterm_sym; }
     break;
 
   case 50:
 
-/* Line 22 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 375 "parse-gram.y"
     {
       current_class = unknown_sym;
@@ -2254,14 +2254,14 @@ yyreduce:
 
   case 51:
 
-/* Line 22 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 379 "parse-gram.y"
     { current_class = token_sym; }
     break;
 
   case 52:
 
-/* Line 22 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 380 "parse-gram.y"
     {
       current_class = unknown_sym;
@@ -2271,7 +2271,7 @@ yyreduce:
 
   case 53:
 
-/* Line 22 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 385 "parse-gram.y"
     {
       symbol_list *list;
@@ -2284,7 +2284,7 @@ yyreduce:
 
   case 54:
 
-/* Line 22 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 396 "parse-gram.y"
     {
       symbol_list *list;
@@ -2301,98 +2301,98 @@ yyreduce:
 
   case 55:
 
-/* Line 22 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 410 "parse-gram.y"
     { (yyval.assoc) = left_assoc; }
     break;
 
   case 56:
 
-/* Line 22 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 411 "parse-gram.y"
     { (yyval.assoc) = right_assoc; }
     break;
 
   case 57:
 
-/* Line 22 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 412 "parse-gram.y"
     { (yyval.assoc) = non_assoc; }
     break;
 
   case 58:
 
-/* Line 22 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 416 "parse-gram.y"
     { current_type = NULL; }
     break;
 
   case 59:
 
-/* Line 22 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 417 "parse-gram.y"
     { current_type = (yyvsp[(1) - (1)].uniqstr); tag_seen = true; }
     break;
 
   case 60:
 
-/* Line 22 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 423 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 61:
 
-/* Line 22 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 425 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), symbol_list_sym_new ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]))); }
     break;
 
   case 62:
 
-/* Line 22 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 429 "parse-gram.y"
     { (yyval.list) = (yyvsp[(1) - (1)].list); }
     break;
 
   case 63:
 
-/* Line 22 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 430 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), (yyvsp[(2) - (2)].list)); }
     break;
 
   case 64:
 
-/* Line 22 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 434 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 65:
 
-/* Line 22 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 435 "parse-gram.y"
     { (yyval.list) = symbol_list_type_new ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 66:
 
-/* Line 22 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 436 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagged_new ((yylsp[(1) - (1)])); }
     break;
 
   case 67:
 
-/* Line 22 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 437 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagless_new ((yylsp[(1) - (1)])); }
     break;
 
   case 68:
 
-/* Line 22 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 443 "parse-gram.y"
     {
        current_type = (yyvsp[(1) - (1)].uniqstr);
@@ -2402,7 +2402,7 @@ yyreduce:
 
   case 69:
 
-/* Line 22 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 448 "parse-gram.y"
     {
        symbol_class_set ((yyvsp[(1) - (1)].symbol), current_class, (yylsp[(1) - (1)]), true);
@@ -2412,7 +2412,7 @@ yyreduce:
 
   case 70:
 
-/* Line 22 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 453 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
@@ -2423,7 +2423,7 @@ yyreduce:
 
   case 71:
 
-/* Line 22 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 459 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
@@ -2434,7 +2434,7 @@ yyreduce:
 
   case 72:
 
-/* Line 22 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 465 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (3)].symbol), current_class, (yylsp[(1) - (3)]), true);
@@ -2446,7 +2446,7 @@ yyreduce:
 
   case 79:
 
-/* Line 22 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 495 "parse-gram.y"
     {
       yyerrok;
@@ -2455,77 +2455,77 @@ yyreduce:
 
   case 80:
 
-/* Line 22 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 501 "parse-gram.y"
     { current_lhs = (yyvsp[(1) - (1)].symbol); current_lhs_location = (yylsp[(1) - (1)]); }
     break;
 
   case 82:
 
-/* Line 22 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 505 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(1) - (1)])); }
     break;
 
   case 83:
 
-/* Line 22 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 506 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(3) - (3)])); }
     break;
 
   case 85:
 
-/* Line 22 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 512 "parse-gram.y"
     { grammar_current_rule_begin (current_lhs, current_lhs_location); }
     break;
 
   case 86:
 
-/* Line 22 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 514 "parse-gram.y"
     { grammar_current_rule_symbol_append ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)])); }
     break;
 
   case 87:
 
-/* Line 22 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 516 "parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
     break;
 
   case 88:
 
-/* Line 22 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 518 "parse-gram.y"
     { grammar_current_rule_prec_set ((yyvsp[(3) - (3)].symbol), (yylsp[(3) - (3)])); }
     break;
 
   case 89:
 
-/* Line 22 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 520 "parse-gram.y"
     { grammar_current_rule_dprec_set ((yyvsp[(3) - (3)].integer), (yylsp[(3) - (3)])); }
     break;
 
   case 90:
 
-/* Line 22 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 522 "parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[(3) - (3)].uniqstr), (yylsp[(3) - (3)])); }
     break;
 
   case 92:
 
-/* Line 22 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 532 "parse-gram.y"
     { (yyval.uniqstr) = uniqstr_new ((yyvsp[(1) - (1)].chars)); }
     break;
 
   case 93:
 
-/* Line 22 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 538 "parse-gram.y"
     {
       (yyval.chars) = "";
@@ -2534,7 +2534,7 @@ yyreduce:
 
   case 95:
 
-/* Line 22 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 551 "parse-gram.y"
     {
       code_props plain_code;
@@ -2548,14 +2548,14 @@ yyreduce:
 
   case 96:
 
-/* Line 22 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 571 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 97:
 
-/* Line 22 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 573 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[(1) - (1)].character)), (yylsp[(1) - (1)]));
@@ -2566,14 +2566,14 @@ yyreduce:
 
   case 98:
 
-/* Line 22 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 581 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 101:
 
-/* Line 22 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 593 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[(1) - (1)].chars)), (yylsp[(1) - (1)]));
@@ -2583,7 +2583,7 @@ yyreduce:
 
   case 103:
 
-/* Line 22 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 602 "parse-gram.y"
     {
       code_props plain_code;
@@ -2597,7 +2597,7 @@ yyreduce:
 
 
 
-/* Line 22 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 2602 "parse-gram.c"
       default: break;
     }
@@ -2816,7 +2816,7 @@ yyreturn:
 
 
 
-/* Line 22 of yacc.c  */
+/* Line 1535 of yacc.c  */
 #line 612 "parse-gram.y"
 
 
