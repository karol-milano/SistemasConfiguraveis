@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 2.6.26-54c4-dirty.  */
+/* A Bison parser, made by GNU Bison 2.6.29-cd73-dirty.  */
 
 /* Bison implementation for Yacc-like parsers in C
    
@@ -44,7 +44,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "2.6.26-54c4-dirty"
+#define YYBISON_VERSION "2.6.29-cd73-dirty"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -70,7 +70,6 @@
 #define yylloc          gram_lloc
 
 /* Copy the first part of user declarations.  */
-
 /* Line 336 of yacc.c  */
 #line 1 "parse-gram.y"
 /* Bison Grammar Parser                             -*- C -*-
@@ -166,9 +165,8 @@ current_lhs(symbol *sym, location loc, named_ref *ref)
 #define YYTYPE_UINT16 uint_fast16_t
 #define YYTYPE_UINT8 uint_fast8_t
 
-
 /* Line 336 of yacc.c  */
-#line 172 "parse-gram.c"
+#line 170 "parse-gram.c"
 
 # ifndef YY_NULL
 #  if defined __cplusplus && 201103L <= __cplusplus
@@ -325,7 +323,6 @@ extern int gram_debug;
 #if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
 typedef union YYSTYPE
 {
-
 /* Line 350 of yacc.c  */
 #line 114 "parse-gram.y"
 
@@ -340,9 +337,8 @@ typedef union YYSTYPE
   named_ref *named_ref;
 
 
-
 /* Line 350 of yacc.c  */
-#line 346 "parse-gram.c"
+#line 342 "parse-gram.c"
 } YYSTYPE;
 # define YYSTYPE_IS_TRIVIAL 1
 # define yystype YYSTYPE /* obsolescent; will be withdrawn */
@@ -381,9 +377,8 @@ int gram_parse ();
 
 /* Copy the second part of user declarations.  */
 
-
 /* Line 353 of yacc.c  */
-#line 387 "parse-gram.c"
+#line 382 "parse-gram.c"
 
 #ifdef short
 # undef short
@@ -1074,166 +1069,130 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
   switch (yytype)
     {
       case 3: /* "string" */
-
 /* Line 809 of yacc.c  */
 #line 204 "parse-gram.y"
-	{ fputs (quotearg_style (c_quoting_style, (yyvaluep->chars)), stderr); };
-
+	{ fputs (quotearg_style (c_quoting_style, ((*yyvaluep).chars)), stderr); };
 /* Line 809 of yacc.c  */
-#line 1084 "parse-gram.c"
+#line 1077 "parse-gram.c"
 	break;
       case 4: /* "integer" */
-
 /* Line 809 of yacc.c  */
 #line 216 "parse-gram.y"
-	{ fprintf (stderr, "%d", (yyvaluep->integer)); };
-
+	{ fprintf (stderr, "%d", ((*yyvaluep).integer)); };
 /* Line 809 of yacc.c  */
-#line 1093 "parse-gram.c"
+#line 1084 "parse-gram.c"
 	break;
       case 43: /* "{...}" */
-
 /* Line 809 of yacc.c  */
 #line 206 "parse-gram.y"
-	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->code)); };
-
+	{ fprintf (stderr, "{\n%s\n}", ((*yyvaluep).code)); };
 /* Line 809 of yacc.c  */
-#line 1102 "parse-gram.c"
+#line 1091 "parse-gram.c"
 	break;
       case 44: /* "[identifier]" */
-
 /* Line 809 of yacc.c  */
 #line 211 "parse-gram.y"
-	{ fprintf (stderr, "[%s]", (yyvaluep->uniqstr)); };
-
+	{ fprintf (stderr, "[%s]", ((*yyvaluep).uniqstr)); };
 /* Line 809 of yacc.c  */
-#line 1111 "parse-gram.c"
+#line 1098 "parse-gram.c"
 	break;
       case 45: /* "char" */
-
 /* Line 809 of yacc.c  */
 #line 198 "parse-gram.y"
-	{ fputs (char_name ((yyvaluep->character)), stderr); };
-
+	{ fputs (char_name (((*yyvaluep).character)), stderr); };
 /* Line 809 of yacc.c  */
-#line 1120 "parse-gram.c"
+#line 1105 "parse-gram.c"
 	break;
       case 46: /* "epilogue" */
-
 /* Line 809 of yacc.c  */
 #line 206 "parse-gram.y"
-	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-
+	{ fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); };
 /* Line 809 of yacc.c  */
-#line 1129 "parse-gram.c"
+#line 1112 "parse-gram.c"
 	break;
       case 48: /* "identifier" */
-
 /* Line 809 of yacc.c  */
 #line 210 "parse-gram.y"
-	{ fputs ((yyvaluep->uniqstr), stderr); };
-
+	{ fputs (((*yyvaluep).uniqstr), stderr); };
 /* Line 809 of yacc.c  */
-#line 1138 "parse-gram.c"
+#line 1119 "parse-gram.c"
 	break;
       case 49: /* "identifier:" */
-
 /* Line 809 of yacc.c  */
 #line 212 "parse-gram.y"
-	{ fprintf (stderr, "%s:", (yyvaluep->uniqstr)); };
-
+	{ fprintf (stderr, "%s:", ((*yyvaluep).uniqstr)); };
 /* Line 809 of yacc.c  */
-#line 1147 "parse-gram.c"
+#line 1126 "parse-gram.c"
 	break;
       case 52: /* "%{...%}" */
-
 /* Line 809 of yacc.c  */
 #line 206 "parse-gram.y"
-	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-
+	{ fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); };
 /* Line 809 of yacc.c  */
-#line 1156 "parse-gram.c"
+#line 1133 "parse-gram.c"
 	break;
       case 54: /* "type" */
-
 /* Line 809 of yacc.c  */
 #line 213 "parse-gram.y"
-	{ fprintf (stderr, "<%s>", (yyvaluep->uniqstr)); };
-
+	{ fprintf (stderr, "<%s>", ((*yyvaluep).uniqstr)); };
 /* Line 809 of yacc.c  */
-#line 1165 "parse-gram.c"
+#line 1140 "parse-gram.c"
 	break;
       case 71: /* symbol.prec */
-
 /* Line 809 of yacc.c  */
 #line 219 "parse-gram.y"
-	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
-
+	{ fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); };
 /* Line 809 of yacc.c  */
-#line 1174 "parse-gram.c"
+#line 1147 "parse-gram.c"
 	break;
       case 84: /* variable */
-
 /* Line 809 of yacc.c  */
 #line 210 "parse-gram.y"
-	{ fputs ((yyvaluep->uniqstr), stderr); };
-
+	{ fputs (((*yyvaluep).uniqstr), stderr); };
 /* Line 809 of yacc.c  */
-#line 1183 "parse-gram.c"
+#line 1154 "parse-gram.c"
 	break;
       case 85: /* content.opt */
-
 /* Line 809 of yacc.c  */
 #line 206 "parse-gram.y"
-	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-
+	{ fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); };
 /* Line 809 of yacc.c  */
-#line 1192 "parse-gram.c"
+#line 1161 "parse-gram.c"
 	break;
       case 86: /* braceless */
-
 /* Line 809 of yacc.c  */
 #line 206 "parse-gram.y"
-	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-
+	{ fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); };
 /* Line 809 of yacc.c  */
-#line 1201 "parse-gram.c"
+#line 1168 "parse-gram.c"
 	break;
       case 87: /* id */
-
 /* Line 809 of yacc.c  */
 #line 219 "parse-gram.y"
-	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
-
+	{ fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); };
 /* Line 809 of yacc.c  */
-#line 1210 "parse-gram.c"
+#line 1175 "parse-gram.c"
 	break;
       case 88: /* id_colon */
-
 /* Line 809 of yacc.c  */
 #line 220 "parse-gram.y"
-	{ fprintf (stderr, "%s:", (yyvaluep->symbol)->tag); };
-
+	{ fprintf (stderr, "%s:", ((*yyvaluep).symbol)->tag); };
 /* Line 809 of yacc.c  */
-#line 1219 "parse-gram.c"
+#line 1182 "parse-gram.c"
 	break;
       case 89: /* symbol */
-
 /* Line 809 of yacc.c  */
 #line 219 "parse-gram.y"
-	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
-
+	{ fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); };
 /* Line 809 of yacc.c  */
-#line 1228 "parse-gram.c"
+#line 1189 "parse-gram.c"
 	break;
       case 90: /* string_as_id */
-
 /* Line 809 of yacc.c  */
 #line 219 "parse-gram.y"
-	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
-
+	{ fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); };
 /* Line 809 of yacc.c  */
-#line 1237 "parse-gram.c"
+#line 1196 "parse-gram.c"
 	break;
       default:
 	break;
@@ -2009,7 +1968,6 @@ YYLTYPE yylloc;
 #endif
 
 /* User initialization code.  */
-
 /* Line 1572 of yacc.c  */
 #line 106 "parse-gram.y"
 {
@@ -2018,11 +1976,9 @@ YYLTYPE yylloc;
   boundary_set (&yylloc.start, current_file, 1, 1);
   boundary_set (&yylloc.end, current_file, 1, 1);
 }
-
 /* Line 1572 of yacc.c  */
-#line 2024 "parse-gram.c"
+#line 1981 "parse-gram.c"
   yylsp[0] = yylloc;
-
   goto yysetstate;
 
 /*------------------------------------------------------------.
@@ -2213,8 +2169,7 @@ yyreduce:
     switch (yyn)
       {
           case 6:
-
-/* Line 1788 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 245 "parse-gram.y"
     {
       code_props plain_code;
@@ -2228,15 +2183,13 @@ yyreduce:
     break;
 
   case 7:
-
-/* Line 1788 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 254 "parse-gram.y"
     { debug_flag = true; }
     break;
 
   case 8:
-
-/* Line 1788 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 256 "parse-gram.y"
     {
       muscle_percent_define_insert ((yyvsp[(2) - (3)].uniqstr), (yylsp[(2) - (3)]), (yyvsp[(3) - (3)].chars),
@@ -2245,15 +2198,13 @@ yyreduce:
     break;
 
   case 9:
-
-/* Line 1788 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 260 "parse-gram.y"
     { defines_flag = true; }
     break;
 
   case 10:
-
-/* Line 1788 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 262 "parse-gram.y"
     {
       defines_flag = true;
@@ -2262,43 +2213,37 @@ yyreduce:
     break;
 
   case 11:
-
-/* Line 1788 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 266 "parse-gram.y"
     { error_verbose = true; }
     break;
 
   case 12:
-
-/* Line 1788 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 267 "parse-gram.y"
     { expected_sr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 13:
-
-/* Line 1788 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 268 "parse-gram.y"
     { expected_rr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 14:
-
-/* Line 1788 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 269 "parse-gram.y"
     { spec_file_prefix = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 15:
-
-/* Line 1788 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 270 "parse-gram.y"
     { spec_file_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 16:
-
-/* Line 1788 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 272 "parse-gram.y"
     {
       nondeterministic_parser = true;
@@ -2307,8 +2252,7 @@ yyreduce:
     break;
 
   case 17:
-
-/* Line 1788 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 277 "parse-gram.y"
     {
       code_props action;
@@ -2321,78 +2265,67 @@ yyreduce:
     break;
 
   case 18:
-
-/* Line 1788 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 285 "parse-gram.y"
     { language_argmatch ((yyvsp[(2) - (2)].chars), grammar_prio, (yylsp[(1) - (2)])); }
     break;
 
   case 19:
-
-/* Line 1788 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 286 "parse-gram.y"
     { add_param ("lex_param", (yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
     break;
 
   case 20:
-
-/* Line 1788 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 287 "parse-gram.y"
     { locations_flag = true; }
     break;
 
   case 21:
-
-/* Line 1788 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 288 "parse-gram.y"
     { spec_name_prefix = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 22:
-
-/* Line 1788 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 289 "parse-gram.y"
     { spec_name_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 23:
-
-/* Line 1788 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 290 "parse-gram.y"
     { no_lines_flag = true; }
     break;
 
   case 24:
-
-/* Line 1788 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 291 "parse-gram.y"
     { nondeterministic_parser = true; }
     break;
 
   case 25:
-
-/* Line 1788 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 292 "parse-gram.y"
     { spec_outfile = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 26:
-
-/* Line 1788 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 293 "parse-gram.y"
     { spec_outfile = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 27:
-
-/* Line 1788 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 294 "parse-gram.y"
     { add_param ("parse_param", (yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
     break;
 
   case 28:
-
-/* Line 1788 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 296 "parse-gram.y"
     {
       /* %pure-parser is deprecated in favor of `%define api.pure', so use
@@ -2411,15 +2344,13 @@ yyreduce:
     break;
 
   case 29:
-
-/* Line 1788 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 310 "parse-gram.y"
     { version_check (&(yylsp[(2) - (2)]), (yyvsp[(2) - (2)].chars)); }
     break;
 
   case 30:
-
-/* Line 1788 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 312 "parse-gram.y"
     {
       char const *skeleton_user = (yyvsp[(2) - (2)].chars);
@@ -2447,29 +2378,25 @@ yyreduce:
     break;
 
   case 31:
-
-/* Line 1788 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 335 "parse-gram.y"
     { token_table_flag = true; }
     break;
 
   case 32:
-
-/* Line 1788 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 336 "parse-gram.y"
     { report_flag |= report_states; }
     break;
 
   case 33:
-
-/* Line 1788 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 337 "parse-gram.y"
     { yacc_flag = true; }
     break;
 
   case 37:
-
-/* Line 1788 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 345 "parse-gram.y"
     {
       grammar_start_symbol_set ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]));
@@ -2477,8 +2404,7 @@ yyreduce:
     break;
 
   case 38:
-
-/* Line 1788 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 349 "parse-gram.y"
     {
       code_props code;
@@ -2494,8 +2420,7 @@ yyreduce:
     break;
 
   case 39:
-
-/* Line 1788 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 361 "parse-gram.y"
     {
       code_props code;
@@ -2511,8 +2436,7 @@ yyreduce:
     break;
 
   case 40:
-
-/* Line 1788 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 373 "parse-gram.y"
     {
       default_prec = true;
@@ -2520,8 +2444,7 @@ yyreduce:
     break;
 
   case 41:
-
-/* Line 1788 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 377 "parse-gram.y"
     {
       default_prec = false;
@@ -2529,8 +2452,7 @@ yyreduce:
     break;
 
   case 42:
-
-/* Line 1788 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 381 "parse-gram.y"
     {
       /* Do not invoke muscle_percent_code_grow here since it invokes
@@ -2541,8 +2463,7 @@ yyreduce:
     break;
 
   case 43:
-
-/* Line 1788 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 388 "parse-gram.y"
     {
       muscle_percent_code_grow ((yyvsp[(2) - (3)].uniqstr), (yylsp[(2) - (3)]), (yyvsp[(3) - (3)].chars), (yylsp[(3) - (3)]));
@@ -2551,22 +2472,19 @@ yyreduce:
     break;
 
   case 44:
-
-/* Line 1788 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 402 "parse-gram.y"
     {}
     break;
 
   case 45:
-
-/* Line 1788 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 403 "parse-gram.y"
     { muscle_code_grow ("union_name", (yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 46:
-
-/* Line 1788 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 408 "parse-gram.y"
     {
       union_seen = true;
@@ -2576,15 +2494,13 @@ yyreduce:
     break;
 
   case 47:
-
-/* Line 1788 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 419 "parse-gram.y"
     { current_class = nterm_sym; }
     break;
 
   case 48:
-
-/* Line 1788 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 420 "parse-gram.y"
     {
       current_class = unknown_sym;
@@ -2593,15 +2509,13 @@ yyreduce:
     break;
 
   case 49:
-
-/* Line 1788 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 424 "parse-gram.y"
     { current_class = token_sym; }
     break;
 
   case 50:
-
-/* Line 1788 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 425 "parse-gram.y"
     {
       current_class = unknown_sym;
@@ -2610,8 +2524,7 @@ yyreduce:
     break;
 
   case 51:
-
-/* Line 1788 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 430 "parse-gram.y"
     {
       symbol_list *list;
@@ -2623,8 +2536,7 @@ yyreduce:
     break;
 
   case 52:
-
-/* Line 1788 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 441 "parse-gram.y"
     {
       symbol_list *list;
@@ -2640,127 +2552,109 @@ yyreduce:
     break;
 
   case 53:
-
-/* Line 1788 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 455 "parse-gram.y"
     { (yyval.assoc) = left_assoc; }
     break;
 
   case 54:
-
-/* Line 1788 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 456 "parse-gram.y"
     { (yyval.assoc) = right_assoc; }
     break;
 
   case 55:
-
-/* Line 1788 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 457 "parse-gram.y"
     { (yyval.assoc) = non_assoc; }
     break;
 
   case 56:
-
-/* Line 1788 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 461 "parse-gram.y"
     { current_type = NULL; }
     break;
 
   case 57:
-
-/* Line 1788 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 462 "parse-gram.y"
     { current_type = (yyvsp[(1) - (1)].uniqstr); tag_seen = true; }
     break;
 
   case 58:
-
-/* Line 1788 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 468 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 59:
-
-/* Line 1788 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 470 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), symbol_list_sym_new ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]))); }
     break;
 
   case 60:
-
-/* Line 1788 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 474 "parse-gram.y"
     { (yyval.symbol) = (yyvsp[(1) - (1)].symbol); }
     break;
 
   case 61:
-
-/* Line 1788 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 475 "parse-gram.y"
     { (yyval.symbol) = (yyvsp[(1) - (2)].symbol); symbol_user_token_number_set ((yyvsp[(1) - (2)].symbol), (yyvsp[(2) - (2)].integer), (yylsp[(2) - (2)])); }
     break;
 
   case 62:
-
-/* Line 1788 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 481 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 63:
-
-/* Line 1788 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 483 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), symbol_list_sym_new ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]))); }
     break;
 
   case 64:
-
-/* Line 1788 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 487 "parse-gram.y"
     { (yyval.list) = (yyvsp[(1) - (1)].list); }
     break;
 
   case 65:
-
-/* Line 1788 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 488 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), (yyvsp[(2) - (2)].list)); }
     break;
 
   case 66:
-
-/* Line 1788 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 492 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 67:
-
-/* Line 1788 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 493 "parse-gram.y"
     { (yyval.list) = symbol_list_type_new ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 68:
-
-/* Line 1788 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 494 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagged_new ((yylsp[(1) - (1)])); }
     break;
 
   case 69:
-
-/* Line 1788 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 495 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagless_new ((yylsp[(1) - (1)])); }
     break;
 
   case 70:
-
-/* Line 1788 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 501 "parse-gram.y"
     {
        current_type = (yyvsp[(1) - (1)].uniqstr);
@@ -2769,8 +2663,7 @@ yyreduce:
     break;
 
   case 71:
-
-/* Line 1788 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 506 "parse-gram.y"
     {
        symbol_class_set ((yyvsp[(1) - (1)].symbol), current_class, (yylsp[(1) - (1)]), true);
@@ -2779,8 +2672,7 @@ yyreduce:
     break;
 
   case 72:
-
-/* Line 1788 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 511 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
@@ -2790,8 +2682,7 @@ yyreduce:
     break;
 
   case 73:
-
-/* Line 1788 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 517 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
@@ -2801,8 +2692,7 @@ yyreduce:
     break;
 
   case 74:
-
-/* Line 1788 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 523 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (3)].symbol), current_class, (yylsp[(1) - (3)]), true);
@@ -2813,8 +2703,7 @@ yyreduce:
     break;
 
   case 81:
-
-/* Line 1788 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 553 "parse-gram.y"
     {
       yyerrok;
@@ -2822,15 +2711,13 @@ yyreduce:
     break;
 
   case 82:
-
-/* Line 1788 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 559 "parse-gram.y"
     { current_lhs ((yyvsp[(1) - (2)].symbol), (yylsp[(1) - (2)]), (yyvsp[(2) - (2)].named_ref)); }
     break;
 
   case 83:
-
-/* Line 1788 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 560 "parse-gram.y"
     {
     /* Free the current lhs. */
@@ -2839,100 +2726,86 @@ yyreduce:
     break;
 
   case 84:
-
-/* Line 1788 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 567 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(1) - (1)])); }
     break;
 
   case 85:
-
-/* Line 1788 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 568 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(3) - (3)])); }
     break;
 
   case 87:
-
-/* Line 1788 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 574 "parse-gram.y"
     { grammar_current_rule_begin (current_lhs_symbol, current_lhs_location,
 				  current_lhs_named_ref); }
     break;
 
   case 88:
-
-/* Line 1788 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 577 "parse-gram.y"
     { grammar_current_rule_symbol_append ((yyvsp[(2) - (3)].symbol), (yylsp[(2) - (3)]), (yyvsp[(3) - (3)].named_ref)); }
     break;
 
   case 89:
-
-/* Line 1788 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 579 "parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[(2) - (3)].code), (yylsp[(2) - (3)]), (yyvsp[(3) - (3)].named_ref)); }
     break;
 
   case 90:
-
-/* Line 1788 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 581 "parse-gram.y"
     { grammar_current_rule_prec_set ((yyvsp[(3) - (3)].symbol), (yylsp[(3) - (3)])); }
     break;
 
   case 91:
-
-/* Line 1788 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 583 "parse-gram.y"
     { grammar_current_rule_dprec_set ((yyvsp[(3) - (3)].integer), (yylsp[(3) - (3)])); }
     break;
 
   case 92:
-
-/* Line 1788 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 585 "parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[(3) - (3)].uniqstr), (yylsp[(3) - (3)])); }
     break;
 
   case 93:
-
-/* Line 1788 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 589 "parse-gram.y"
     { (yyval.named_ref) = 0; }
     break;
 
   case 94:
-
-/* Line 1788 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 591 "parse-gram.y"
     { (yyval.named_ref) = named_ref_new((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 96:
-
-/* Line 1788 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 603 "parse-gram.y"
     { (yyval.uniqstr) = uniqstr_new ((yyvsp[(1) - (1)].chars)); }
     break;
 
   case 97:
-
-/* Line 1788 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 608 "parse-gram.y"
     { (yyval.chars) = ""; }
     break;
 
   case 98:
-
-/* Line 1788 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 609 "parse-gram.y"
     { (yyval.chars) = (yyvsp[(1) - (1)].uniqstr); }
     break;
 
   case 100:
-
-/* Line 1788 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 620 "parse-gram.y"
     {
       code_props plain_code;
@@ -2945,15 +2818,13 @@ yyreduce:
     break;
 
   case 101:
-
-/* Line 1788 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 640 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 102:
-
-/* Line 1788 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 642 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[(1) - (1)].character)), (yylsp[(1) - (1)]));
@@ -2963,15 +2834,13 @@ yyreduce:
     break;
 
   case 103:
-
-/* Line 1788 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 650 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 106:
-
-/* Line 1788 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 662 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[(1) - (1)].chars)), (yylsp[(1) - (1)]));
@@ -2980,8 +2849,7 @@ yyreduce:
     break;
 
   case 108:
-
-/* Line 1788 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 671 "parse-gram.y"
     {
       code_props plain_code;
@@ -2994,9 +2862,8 @@ yyreduce:
     break;
 
 
-
-/* Line 1788 of yacc.c  */
-#line 3000 "parse-gram.c"
+/* Line 1787 of yacc.c  */
+#line 2867 "parse-gram.c"
         default: break;
       }
     if (yychar_backup != yychar)
@@ -3244,8 +3111,7 @@ yyreturn:
 }
 
 
-
-/* Line 2049 of yacc.c  */
+/* Line 2048 of yacc.c  */
 #line 681 "parse-gram.y"
 
 
