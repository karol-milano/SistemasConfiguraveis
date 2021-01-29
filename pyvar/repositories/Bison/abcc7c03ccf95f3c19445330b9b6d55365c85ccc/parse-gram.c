@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 2.4.1.171-692d.  */
+/* A Bison parser, made by GNU Bison 2.4.1.173-62efdd.  */
 
 /* Skeleton implementation for Bison's Yacc-like parsers in C
    
@@ -45,7 +45,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "2.4.1.171-692d"
+#define YYBISON_VERSION "2.4.1.173-62efdd"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -927,7 +927,6 @@ do								\
     {								\
       yychar = (Token);						\
       yylval = (Value);						\
-      yytoken = YYTRANSLATE (yychar);				\
       YYPOPSTACK (1);						\
       goto yybackup;						\
     }								\
@@ -1050,165 +1049,165 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
     {
       case 3: /* "\"string\"" */
 
-/* Line 799 of yacc.c  */
+/* Line 798 of yacc.c  */
 #line 184 "parse-gram.y"
 	{ fputs (quotearg_style (c_quoting_style, (yyvaluep->chars)), stderr); };
 
-/* Line 799 of yacc.c  */
-#line 1059 "parse-gram.c"
+/* Line 798 of yacc.c  */
+#line 1058 "parse-gram.c"
 	break;
       case 4: /* "\"integer\"" */
 
-/* Line 799 of yacc.c  */
+/* Line 798 of yacc.c  */
 #line 196 "parse-gram.y"
 	{ fprintf (stderr, "%d", (yyvaluep->integer)); };
 
-/* Line 799 of yacc.c  */
-#line 1068 "parse-gram.c"
+/* Line 798 of yacc.c  */
+#line 1067 "parse-gram.c"
 	break;
       case 43: /* "\"{...}\"" */
 
-/* Line 799 of yacc.c  */
+/* Line 798 of yacc.c  */
 #line 186 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->code)); };
 
-/* Line 799 of yacc.c  */
-#line 1077 "parse-gram.c"
+/* Line 798 of yacc.c  */
+#line 1076 "parse-gram.c"
 	break;
       case 44: /* "\"[identifier]\"" */
 
-/* Line 799 of yacc.c  */
+/* Line 798 of yacc.c  */
 #line 191 "parse-gram.y"
 	{ fprintf (stderr, "[%s]", (yyvaluep->uniqstr)); };
 
-/* Line 799 of yacc.c  */
-#line 1086 "parse-gram.c"
+/* Line 798 of yacc.c  */
+#line 1085 "parse-gram.c"
 	break;
       case 45: /* "\"char\"" */
 
-/* Line 799 of yacc.c  */
+/* Line 798 of yacc.c  */
 #line 178 "parse-gram.y"
 	{ fputs (char_name ((yyvaluep->character)), stderr); };
 
-/* Line 799 of yacc.c  */
-#line 1095 "parse-gram.c"
+/* Line 798 of yacc.c  */
+#line 1094 "parse-gram.c"
 	break;
       case 46: /* "\"epilogue\"" */
 
-/* Line 799 of yacc.c  */
+/* Line 798 of yacc.c  */
 #line 186 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
-/* Line 799 of yacc.c  */
-#line 1104 "parse-gram.c"
+/* Line 798 of yacc.c  */
+#line 1103 "parse-gram.c"
 	break;
       case 48: /* "\"identifier\"" */
 
-/* Line 799 of yacc.c  */
+/* Line 798 of yacc.c  */
 #line 190 "parse-gram.y"
 	{ fputs ((yyvaluep->uniqstr), stderr); };
 
-/* Line 799 of yacc.c  */
-#line 1113 "parse-gram.c"
+/* Line 798 of yacc.c  */
+#line 1112 "parse-gram.c"
 	break;
       case 49: /* "\"identifier:\"" */
 
-/* Line 799 of yacc.c  */
+/* Line 798 of yacc.c  */
 #line 192 "parse-gram.y"
 	{ fprintf (stderr, "%s:", (yyvaluep->uniqstr)); };
 
-/* Line 799 of yacc.c  */
-#line 1122 "parse-gram.c"
+/* Line 798 of yacc.c  */
+#line 1121 "parse-gram.c"
 	break;
       case 52: /* "\"%{...%}\"" */
 
-/* Line 799 of yacc.c  */
+/* Line 798 of yacc.c  */
 #line 186 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
-/* Line 799 of yacc.c  */
-#line 1131 "parse-gram.c"
+/* Line 798 of yacc.c  */
+#line 1130 "parse-gram.c"
 	break;
       case 54: /* "\"type\"" */
 
-/* Line 799 of yacc.c  */
+/* Line 798 of yacc.c  */
 #line 193 "parse-gram.y"
 	{ fprintf (stderr, "<%s>", (yyvaluep->uniqstr)); };
 
-/* Line 799 of yacc.c  */
-#line 1140 "parse-gram.c"
+/* Line 798 of yacc.c  */
+#line 1139 "parse-gram.c"
 	break;
       case 71: /* "symbol.prec" */
 
-/* Line 799 of yacc.c  */
+/* Line 798 of yacc.c  */
 #line 199 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
-/* Line 799 of yacc.c  */
-#line 1149 "parse-gram.c"
+/* Line 798 of yacc.c  */
+#line 1148 "parse-gram.c"
 	break;
       case 84: /* "variable" */
 
-/* Line 799 of yacc.c  */
+/* Line 798 of yacc.c  */
 #line 190 "parse-gram.y"
 	{ fputs ((yyvaluep->uniqstr), stderr); };
 
-/* Line 799 of yacc.c  */
-#line 1158 "parse-gram.c"
+/* Line 798 of yacc.c  */
+#line 1157 "parse-gram.c"
 	break;
       case 85: /* "content.opt" */
 
-/* Line 799 of yacc.c  */
+/* Line 798 of yacc.c  */
 #line 186 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
-/* Line 799 of yacc.c  */
-#line 1167 "parse-gram.c"
+/* Line 798 of yacc.c  */
+#line 1166 "parse-gram.c"
 	break;
       case 86: /* "braceless" */
 
-/* Line 799 of yacc.c  */
+/* Line 798 of yacc.c  */
 #line 186 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
-/* Line 799 of yacc.c  */
-#line 1176 "parse-gram.c"
+/* Line 798 of yacc.c  */
+#line 1175 "parse-gram.c"
 	break;
       case 87: /* "id" */
 
-/* Line 799 of yacc.c  */
+/* Line 798 of yacc.c  */
 #line 199 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
-/* Line 799 of yacc.c  */
-#line 1185 "parse-gram.c"
+/* Line 798 of yacc.c  */
+#line 1184 "parse-gram.c"
 	break;
       case 88: /* "id_colon" */
 
-/* Line 799 of yacc.c  */
+/* Line 798 of yacc.c  */
 #line 200 "parse-gram.y"
 	{ fprintf (stderr, "%s:", (yyvaluep->symbol)->tag); };
 
-/* Line 799 of yacc.c  */
-#line 1194 "parse-gram.c"
+/* Line 798 of yacc.c  */
+#line 1193 "parse-gram.c"
 	break;
       case 89: /* "symbol" */
 
-/* Line 799 of yacc.c  */
+/* Line 798 of yacc.c  */
 #line 199 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
-/* Line 799 of yacc.c  */
-#line 1203 "parse-gram.c"
+/* Line 798 of yacc.c  */
+#line 1202 "parse-gram.c"
 	break;
       case 90: /* "string_as_id" */
 
-/* Line 799 of yacc.c  */
+/* Line 798 of yacc.c  */
 #line 199 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
-/* Line 799 of yacc.c  */
-#line 1212 "parse-gram.c"
+/* Line 798 of yacc.c  */
+#line 1211 "parse-gram.c"
 	break;
       default:
 	break;
@@ -1735,7 +1734,7 @@ YYLTYPE yylloc;
 
 /* User initialization code.  */
 
-/* Line 1282 of yacc.c  */
+/* Line 1281 of yacc.c  */
 #line 86 "parse-gram.y"
 {
   /* Bison's grammar can initial empty locations, hence a default
@@ -1744,8 +1743,8 @@ YYLTYPE yylloc;
   boundary_set (&yylloc.end, current_file, 1, 1);
 }
 
-/* Line 1282 of yacc.c  */
-#line 1749 "parse-gram.c"
+/* Line 1281 of yacc.c  */
+#line 1748 "parse-gram.c"
   yylsp[0] = yylloc;
 
   goto yysetstate;
@@ -1932,7 +1931,7 @@ yyreduce:
     {
         case 6:
 
-/* Line 1495 of yacc.c  */
+/* Line 1494 of yacc.c  */
 #line 225 "parse-gram.y"
     {
       code_props plain_code;
@@ -1947,14 +1946,14 @@ yyreduce:
 
   case 7:
 
-/* Line 1495 of yacc.c  */
+/* Line 1494 of yacc.c  */
 #line 234 "parse-gram.y"
     { debug_flag = true; }
     break;
 
   case 8:
 
-/* Line 1495 of yacc.c  */
+/* Line 1494 of yacc.c  */
 #line 236 "parse-gram.y"
     {
       muscle_percent_define_insert ((yyvsp[(2) - (3)].uniqstr), (yylsp[(2) - (3)]), (yyvsp[(3) - (3)].chars),
@@ -1964,14 +1963,14 @@ yyreduce:
 
   case 9:
 
-/* Line 1495 of yacc.c  */
+/* Line 1494 of yacc.c  */
 #line 240 "parse-gram.y"
     { defines_flag = true; }
     break;
 
   case 10:
 
-/* Line 1495 of yacc.c  */
+/* Line 1494 of yacc.c  */
 #line 242 "parse-gram.y"
     {
       defines_flag = true;
@@ -1981,42 +1980,42 @@ yyreduce:
 
   case 11:
 
-/* Line 1495 of yacc.c  */
+/* Line 1494 of yacc.c  */
 #line 246 "parse-gram.y"
     { error_verbose = true; }
     break;
 
   case 12:
 
-/* Line 1495 of yacc.c  */
+/* Line 1494 of yacc.c  */
 #line 247 "parse-gram.y"
     { expected_sr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 13:
 
-/* Line 1495 of yacc.c  */
+/* Line 1494 of yacc.c  */
 #line 248 "parse-gram.y"
     { expected_rr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 14:
 
-/* Line 1495 of yacc.c  */
+/* Line 1494 of yacc.c  */
 #line 249 "parse-gram.y"
     { spec_file_prefix = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 15:
 
-/* Line 1495 of yacc.c  */
+/* Line 1494 of yacc.c  */
 #line 250 "parse-gram.y"
     { spec_file_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 16:
 
-/* Line 1495 of yacc.c  */
+/* Line 1494 of yacc.c  */
 #line 252 "parse-gram.y"
     {
       nondeterministic_parser = true;
@@ -2026,7 +2025,7 @@ yyreduce:
 
   case 17:
 
-/* Line 1495 of yacc.c  */
+/* Line 1494 of yacc.c  */
 #line 257 "parse-gram.y"
     {
       code_props action;
@@ -2040,77 +2039,77 @@ yyreduce:
 
   case 18:
 
-/* Line 1495 of yacc.c  */
+/* Line 1494 of yacc.c  */
 #line 265 "parse-gram.y"
     { language_argmatch ((yyvsp[(2) - (2)].chars), grammar_prio, (yylsp[(1) - (2)])); }
     break;
 
   case 19:
 
-/* Line 1495 of yacc.c  */
+/* Line 1494 of yacc.c  */
 #line 266 "parse-gram.y"
     { add_param ("lex_param", (yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
     break;
 
   case 20:
 
-/* Line 1495 of yacc.c  */
+/* Line 1494 of yacc.c  */
 #line 267 "parse-gram.y"
     { locations_flag = true; }
     break;
 
   case 21:
 
-/* Line 1495 of yacc.c  */
+/* Line 1494 of yacc.c  */
 #line 268 "parse-gram.y"
     { spec_name_prefix = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 22:
 
-/* Line 1495 of yacc.c  */
+/* Line 1494 of yacc.c  */
 #line 269 "parse-gram.y"
     { spec_name_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 23:
 
-/* Line 1495 of yacc.c  */
+/* Line 1494 of yacc.c  */
 #line 270 "parse-gram.y"
     { no_lines_flag = true; }
     break;
 
   case 24:
 
-/* Line 1495 of yacc.c  */
+/* Line 1494 of yacc.c  */
 #line 271 "parse-gram.y"
     { nondeterministic_parser = true; }
     break;
 
   case 25:
 
-/* Line 1495 of yacc.c  */
+/* Line 1494 of yacc.c  */
 #line 272 "parse-gram.y"
     { spec_outfile = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 26:
 
-/* Line 1495 of yacc.c  */
+/* Line 1494 of yacc.c  */
 #line 273 "parse-gram.y"
     { spec_outfile = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 27:
 
-/* Line 1495 of yacc.c  */
+/* Line 1494 of yacc.c  */
 #line 274 "parse-gram.y"
     { add_param ("parse_param", (yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
     break;
 
   case 28:
 
-/* Line 1495 of yacc.c  */
+/* Line 1494 of yacc.c  */
 #line 276 "parse-gram.y"
     {
       /* %pure-parser is deprecated in favor of `%define api.pure', so use
@@ -2130,14 +2129,14 @@ yyreduce:
 
   case 29:
 
-/* Line 1495 of yacc.c  */
+/* Line 1494 of yacc.c  */
 #line 290 "parse-gram.y"
     { version_check (&(yylsp[(2) - (2)]), (yyvsp[(2) - (2)].chars)); }
     break;
 
   case 30:
 
-/* Line 1495 of yacc.c  */
+/* Line 1494 of yacc.c  */
 #line 292 "parse-gram.y"
     {
       char const *skeleton_user = (yyvsp[(2) - (2)].chars);
@@ -2166,28 +2165,28 @@ yyreduce:
 
   case 31:
 
-/* Line 1495 of yacc.c  */
+/* Line 1494 of yacc.c  */
 #line 315 "parse-gram.y"
     { token_table_flag = true; }
     break;
 
   case 32:
 
-/* Line 1495 of yacc.c  */
+/* Line 1494 of yacc.c  */
 #line 316 "parse-gram.y"
     { report_flag |= report_states; }
     break;
 
   case 33:
 
-/* Line 1495 of yacc.c  */
+/* Line 1494 of yacc.c  */
 #line 317 "parse-gram.y"
     { yacc_flag = true; }
     break;
 
   case 37:
 
-/* Line 1495 of yacc.c  */
+/* Line 1494 of yacc.c  */
 #line 325 "parse-gram.y"
     {
       grammar_start_symbol_set ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]));
@@ -2196,7 +2195,7 @@ yyreduce:
 
   case 38:
 
-/* Line 1495 of yacc.c  */
+/* Line 1494 of yacc.c  */
 #line 329 "parse-gram.y"
     {
       symbol_list *list;
@@ -2208,7 +2207,7 @@ yyreduce:
 
   case 39:
 
-/* Line 1495 of yacc.c  */
+/* Line 1494 of yacc.c  */
 #line 336 "parse-gram.y"
     {
       symbol_list *list;
@@ -2220,7 +2219,7 @@ yyreduce:
 
   case 40:
 
-/* Line 1495 of yacc.c  */
+/* Line 1494 of yacc.c  */
 #line 343 "parse-gram.y"
     {
       default_prec = true;
@@ -2229,7 +2228,7 @@ yyreduce:
 
   case 41:
 
-/* Line 1495 of yacc.c  */
+/* Line 1494 of yacc.c  */
 #line 347 "parse-gram.y"
     {
       default_prec = false;
@@ -2238,7 +2237,7 @@ yyreduce:
 
   case 42:
 
-/* Line 1495 of yacc.c  */
+/* Line 1494 of yacc.c  */
 #line 351 "parse-gram.y"
     {
       /* Do not invoke muscle_percent_code_grow here since it invokes
@@ -2250,7 +2249,7 @@ yyreduce:
 
   case 43:
 
-/* Line 1495 of yacc.c  */
+/* Line 1494 of yacc.c  */
 #line 358 "parse-gram.y"
     {
       muscle_percent_code_grow ((yyvsp[(2) - (3)].uniqstr), (yylsp[(2) - (3)]), (yyvsp[(3) - (3)].chars), (yylsp[(3) - (3)]));
@@ -2260,21 +2259,21 @@ yyreduce:
 
   case 44:
 
-/* Line 1495 of yacc.c  */
+/* Line 1494 of yacc.c  */
 #line 372 "parse-gram.y"
     {}
     break;
 
   case 45:
 
-/* Line 1495 of yacc.c  */
+/* Line 1494 of yacc.c  */
 #line 373 "parse-gram.y"
     { muscle_code_grow ("union_name", (yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 46:
 
-/* Line 1495 of yacc.c  */
+/* Line 1494 of yacc.c  */
 #line 378 "parse-gram.y"
     {
       union_seen = true;
@@ -2285,14 +2284,14 @@ yyreduce:
 
   case 47:
 
-/* Line 1495 of yacc.c  */
+/* Line 1494 of yacc.c  */
 #line 389 "parse-gram.y"
     { current_class = nterm_sym; }
     break;
 
   case 48:
 
-/* Line 1495 of yacc.c  */
+/* Line 1494 of yacc.c  */
 #line 390 "parse-gram.y"
     {
       current_class = unknown_sym;
@@ -2302,14 +2301,14 @@ yyreduce:
 
   case 49:
 
-/* Line 1495 of yacc.c  */
+/* Line 1494 of yacc.c  */
 #line 394 "parse-gram.y"
     { current_class = token_sym; }
     break;
 
   case 50:
 
-/* Line 1495 of yacc.c  */
+/* Line 1494 of yacc.c  */
 #line 395 "parse-gram.y"
     {
       current_class = unknown_sym;
@@ -2319,7 +2318,7 @@ yyreduce:
 
   case 51:
 
-/* Line 1495 of yacc.c  */
+/* Line 1494 of yacc.c  */
 #line 400 "parse-gram.y"
     {
       symbol_list *list;
@@ -2332,7 +2331,7 @@ yyreduce:
 
   case 52:
 
-/* Line 1495 of yacc.c  */
+/* Line 1494 of yacc.c  */
 #line 411 "parse-gram.y"
     {
       symbol_list *list;
@@ -2349,126 +2348,126 @@ yyreduce:
 
   case 53:
 
-/* Line 1495 of yacc.c  */
+/* Line 1494 of yacc.c  */
 #line 425 "parse-gram.y"
     { (yyval.assoc) = left_assoc; }
     break;
 
   case 54:
 
-/* Line 1495 of yacc.c  */
+/* Line 1494 of yacc.c  */
 #line 426 "parse-gram.y"
     { (yyval.assoc) = right_assoc; }
     break;
 
   case 55:
 
-/* Line 1495 of yacc.c  */
+/* Line 1494 of yacc.c  */
 #line 427 "parse-gram.y"
     { (yyval.assoc) = non_assoc; }
     break;
 
   case 56:
 
-/* Line 1495 of yacc.c  */
+/* Line 1494 of yacc.c  */
 #line 431 "parse-gram.y"
     { current_type = NULL; }
     break;
 
   case 57:
 
-/* Line 1495 of yacc.c  */
+/* Line 1494 of yacc.c  */
 #line 432 "parse-gram.y"
     { current_type = (yyvsp[(1) - (1)].uniqstr); tag_seen = true; }
     break;
 
   case 58:
 
-/* Line 1495 of yacc.c  */
+/* Line 1494 of yacc.c  */
 #line 438 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 59:
 
-/* Line 1495 of yacc.c  */
+/* Line 1494 of yacc.c  */
 #line 440 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), symbol_list_sym_new ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]))); }
     break;
 
   case 60:
 
-/* Line 1495 of yacc.c  */
+/* Line 1494 of yacc.c  */
 #line 444 "parse-gram.y"
     { (yyval.symbol) = (yyvsp[(1) - (1)].symbol); }
     break;
 
   case 61:
 
-/* Line 1495 of yacc.c  */
+/* Line 1494 of yacc.c  */
 #line 445 "parse-gram.y"
     { (yyval.symbol) = (yyvsp[(1) - (2)].symbol); symbol_user_token_number_set ((yyvsp[(1) - (2)].symbol), (yyvsp[(2) - (2)].integer), (yylsp[(2) - (2)])); }
     break;
 
   case 62:
 
-/* Line 1495 of yacc.c  */
+/* Line 1494 of yacc.c  */
 #line 451 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 63:
 
-/* Line 1495 of yacc.c  */
+/* Line 1494 of yacc.c  */
 #line 453 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), symbol_list_sym_new ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]))); }
     break;
 
   case 64:
 
-/* Line 1495 of yacc.c  */
+/* Line 1494 of yacc.c  */
 #line 457 "parse-gram.y"
     { (yyval.list) = (yyvsp[(1) - (1)].list); }
     break;
 
   case 65:
 
-/* Line 1495 of yacc.c  */
+/* Line 1494 of yacc.c  */
 #line 458 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), (yyvsp[(2) - (2)].list)); }
     break;
 
   case 66:
 
-/* Line 1495 of yacc.c  */
+/* Line 1494 of yacc.c  */
 #line 462 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 67:
 
-/* Line 1495 of yacc.c  */
+/* Line 1494 of yacc.c  */
 #line 463 "parse-gram.y"
     { (yyval.list) = symbol_list_type_new ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 68:
 
-/* Line 1495 of yacc.c  */
+/* Line 1494 of yacc.c  */
 #line 464 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagged_new ((yylsp[(1) - (1)])); }
     break;
 
   case 69:
 
-/* Line 1495 of yacc.c  */
+/* Line 1494 of yacc.c  */
 #line 465 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagless_new ((yylsp[(1) - (1)])); }
     break;
 
   case 70:
 
-/* Line 1495 of yacc.c  */
+/* Line 1494 of yacc.c  */
 #line 471 "parse-gram.y"
     {
        current_type = (yyvsp[(1) - (1)].uniqstr);
@@ -2478,7 +2477,7 @@ yyreduce:
 
   case 71:
 
-/* Line 1495 of yacc.c  */
+/* Line 1494 of yacc.c  */
 #line 476 "parse-gram.y"
     {
        symbol_class_set ((yyvsp[(1) - (1)].symbol), current_class, (yylsp[(1) - (1)]), true);
@@ -2488,7 +2487,7 @@ yyreduce:
 
   case 72:
 
-/* Line 1495 of yacc.c  */
+/* Line 1494 of yacc.c  */
 #line 481 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
@@ -2499,7 +2498,7 @@ yyreduce:
 
   case 73:
 
-/* Line 1495 of yacc.c  */
+/* Line 1494 of yacc.c  */
 #line 487 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
@@ -2510,7 +2509,7 @@ yyreduce:
 
   case 74:
 
-/* Line 1495 of yacc.c  */
+/* Line 1494 of yacc.c  */
 #line 493 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (3)].symbol), current_class, (yylsp[(1) - (3)]), true);
@@ -2522,7 +2521,7 @@ yyreduce:
 
   case 81:
 
-/* Line 1495 of yacc.c  */
+/* Line 1494 of yacc.c  */
 #line 523 "parse-gram.y"
     {
       yyerrok;
@@ -2531,7 +2530,7 @@ yyreduce:
 
   case 82:
 
-/* Line 1495 of yacc.c  */
+/* Line 1494 of yacc.c  */
 #line 529 "parse-gram.y"
     { current_lhs = (yyvsp[(1) - (2)].symbol); current_lhs_location = (yylsp[(1) - (2)]);
     current_lhs_named_ref = (yyvsp[(2) - (2)].named_ref); }
@@ -2539,21 +2538,21 @@ yyreduce:
 
   case 84:
 
-/* Line 1495 of yacc.c  */
+/* Line 1494 of yacc.c  */
 #line 534 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(1) - (1)])); }
     break;
 
   case 85:
 
-/* Line 1495 of yacc.c  */
+/* Line 1494 of yacc.c  */
 #line 535 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(3) - (3)])); }
     break;
 
   case 87:
 
-/* Line 1495 of yacc.c  */
+/* Line 1494 of yacc.c  */
 #line 541 "parse-gram.y"
     { grammar_current_rule_begin (current_lhs, current_lhs_location,
 				  current_lhs_named_ref); }
@@ -2561,77 +2560,77 @@ yyreduce:
 
   case 88:
 
-/* Line 1495 of yacc.c  */
+/* Line 1494 of yacc.c  */
 #line 544 "parse-gram.y"
     { grammar_current_rule_symbol_append ((yyvsp[(2) - (3)].symbol), (yylsp[(2) - (3)]), (yyvsp[(3) - (3)].named_ref)); }
     break;
 
   case 89:
 
-/* Line 1495 of yacc.c  */
+/* Line 1494 of yacc.c  */
 #line 546 "parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[(2) - (3)].code), (yylsp[(2) - (3)]), (yyvsp[(3) - (3)].named_ref)); }
     break;
 
   case 90:
 
-/* Line 1495 of yacc.c  */
+/* Line 1494 of yacc.c  */
 #line 548 "parse-gram.y"
     { grammar_current_rule_prec_set ((yyvsp[(3) - (3)].symbol), (yylsp[(3) - (3)])); }
     break;
 
   case 91:
 
-/* Line 1495 of yacc.c  */
+/* Line 1494 of yacc.c  */
 #line 550 "parse-gram.y"
     { grammar_current_rule_dprec_set ((yyvsp[(3) - (3)].integer), (yylsp[(3) - (3)])); }
     break;
 
   case 92:
 
-/* Line 1495 of yacc.c  */
+/* Line 1494 of yacc.c  */
 #line 552 "parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[(3) - (3)].uniqstr), (yylsp[(3) - (3)])); }
     break;
 
   case 93:
 
-/* Line 1495 of yacc.c  */
+/* Line 1494 of yacc.c  */
 #line 556 "parse-gram.y"
     { (yyval.named_ref) = 0; }
     break;
 
   case 94:
 
-/* Line 1495 of yacc.c  */
+/* Line 1494 of yacc.c  */
 #line 558 "parse-gram.y"
     { (yyval.named_ref) = named_ref_new((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 96:
 
-/* Line 1495 of yacc.c  */
+/* Line 1494 of yacc.c  */
 #line 570 "parse-gram.y"
     { (yyval.uniqstr) = uniqstr_new ((yyvsp[(1) - (1)].chars)); }
     break;
 
   case 97:
 
-/* Line 1495 of yacc.c  */
+/* Line 1494 of yacc.c  */
 #line 575 "parse-gram.y"
     { (yyval.chars) = ""; }
     break;
 
   case 98:
 
-/* Line 1495 of yacc.c  */
+/* Line 1494 of yacc.c  */
 #line 576 "parse-gram.y"
     { (yyval.chars) = (yyvsp[(1) - (1)].uniqstr); }
     break;
 
   case 100:
 
-/* Line 1495 of yacc.c  */
+/* Line 1494 of yacc.c  */
 #line 587 "parse-gram.y"
     {
       code_props plain_code;
@@ -2645,14 +2644,14 @@ yyreduce:
 
   case 101:
 
-/* Line 1495 of yacc.c  */
+/* Line 1494 of yacc.c  */
 #line 607 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 102:
 
-/* Line 1495 of yacc.c  */
+/* Line 1494 of yacc.c  */
 #line 609 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[(1) - (1)].character)), (yylsp[(1) - (1)]));
@@ -2663,14 +2662,14 @@ yyreduce:
 
   case 103:
 
-/* Line 1495 of yacc.c  */
+/* Line 1494 of yacc.c  */
 #line 617 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 106:
 
-/* Line 1495 of yacc.c  */
+/* Line 1494 of yacc.c  */
 #line 629 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[(1) - (1)].chars)), (yylsp[(1) - (1)]));
@@ -2680,7 +2679,7 @@ yyreduce:
 
   case 108:
 
-/* Line 1495 of yacc.c  */
+/* Line 1494 of yacc.c  */
 #line 638 "parse-gram.y"
     {
       code_props plain_code;
@@ -2694,10 +2693,21 @@ yyreduce:
 
 
 
-/* Line 1495 of yacc.c  */
-#line 2699 "parse-gram.c"
+/* Line 1494 of yacc.c  */
+#line 2698 "parse-gram.c"
       default: break;
     }
+  /* User semantic actions sometimes alter yychar, and that requires
+     that yytoken be updated with the new translation.  We take the
+     approach of translating immediately before every use of yytoken.
+     One alternative is translating here after every semantic action,
+     but that translation would be missed if the semantic action invokes
+     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
+     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
+     incorrect destructor might then be invoked immediately.  In the
+     case of YYERROR or YYBACKUP, subsequent parser actions might lead
+     to an incorrect destructor call or verbose syntax error message
+     before the lookahead is translated.  */
   YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);
 
   YYPOPSTACK (yylen);
@@ -2726,6 +2736,10 @@ yyreduce:
 | yyerrlab -- here on detecting error |
 `------------------------------------*/
 yyerrlab:
+  /* Make sure we have latest lookahead translation.  See comments at
+     user semantic actions for why this is necessary.  */
+  yytoken = YYTRANSLATE (yychar);
+
   /* If not already recovering from an error, report this error.  */
   if (!yyerrstatus)
     {
@@ -2878,8 +2892,13 @@ yyexhaustedlab:
 
 yyreturn:
   if (yychar != YYEMPTY)
-     yydestruct ("Cleanup: discarding lookahead",
-		 yytoken, &yylval, &yylloc);
+    {
+      /* Make sure we have latest lookahead translation.  See comments at
+         user semantic actions for why this is necessary.  */
+      yytoken = YYTRANSLATE (yychar);
+      yydestruct ("Cleanup: discarding lookahead",
+                  yytoken, &yylval, &yylloc);
+    }
   /* Do not reclaim the symbols of the rule which action triggered
      this YYABORT or YYACCEPT.  */
   YYPOPSTACK (yylen);
@@ -2904,7 +2923,7 @@ yyreturn:
 
 
 
-/* Line 1706 of yacc.c  */
+/* Line 1725 of yacc.c  */
 #line 648 "parse-gram.y"
 
 
