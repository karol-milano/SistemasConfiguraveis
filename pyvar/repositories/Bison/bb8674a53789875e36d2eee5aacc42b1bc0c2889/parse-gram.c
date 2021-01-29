@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 2.6.4.4-8c79c-dirty.  */
+/* A Bison parser, made by GNU Bison 2.6.4.11-d01f-dirty.  */
 
 /* Bison implementation for Yacc-like parsers in C
    
@@ -44,7 +44,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "2.6.4.4-8c79c-dirty"
+#define YYBISON_VERSION "2.6.4.11-d01f-dirty"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -970,6 +970,7 @@ while (YYID (0))
 #define YYTERROR	1
 #define YYERRCODE	256
 
+
 /* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
    If N is 0, then set CURRENT to the empty location which ends
    the previous symbol: RHS[0] (always defined).  */
@@ -996,8 +997,6 @@ while (YYID (0))
 
 #define YYRHSLOC(Rhs, K) ((Rhs)[K])
 
-
-
 /* YY_LOCATION_PRINT -- Print the location on the stream.
    This macro was not mandated originally: define only if we know
    we won't break user code: when these are the locations we know.  */
@@ -1015,7 +1014,6 @@ while (YYID (0))
 
 
 /* YYLEX -- calling `yylex' with the right arguments.  */
-
 #ifdef YYLEX_PARAM
 # define YYLEX yylex (&yylval, &yylloc, YYLEX_PARAM)
 #else
@@ -1080,130 +1078,130 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
   switch (yytype)
     {
       case 3: /* "string" */
-/* Line 833 of yacc.c  */
+/* Line 828 of yacc.c  */
 #line 205 "parse-gram.y"
 	{ fputs (quotearg_style (c_quoting_style, ((*yyvaluep).chars)), stderr); };
-/* Line 833 of yacc.c  */
-#line 1088 "parse-gram.c"
+/* Line 828 of yacc.c  */
+#line 1086 "parse-gram.c"
 	break;
       case 4: /* "integer" */
-/* Line 833 of yacc.c  */
+/* Line 828 of yacc.c  */
 #line 217 "parse-gram.y"
 	{ fprintf (stderr, "%d", ((*yyvaluep).integer)); };
-/* Line 833 of yacc.c  */
-#line 1095 "parse-gram.c"
+/* Line 828 of yacc.c  */
+#line 1093 "parse-gram.c"
 	break;
       case 43: /* "{...}" */
-/* Line 833 of yacc.c  */
+/* Line 828 of yacc.c  */
 #line 207 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", ((*yyvaluep).code)); };
-/* Line 833 of yacc.c  */
-#line 1102 "parse-gram.c"
+/* Line 828 of yacc.c  */
+#line 1100 "parse-gram.c"
 	break;
       case 44: /* "[identifier]" */
-/* Line 833 of yacc.c  */
+/* Line 828 of yacc.c  */
 #line 212 "parse-gram.y"
 	{ fprintf (stderr, "[%s]", ((*yyvaluep).uniqstr)); };
-/* Line 833 of yacc.c  */
-#line 1109 "parse-gram.c"
+/* Line 828 of yacc.c  */
+#line 1107 "parse-gram.c"
 	break;
       case 45: /* "char" */
-/* Line 833 of yacc.c  */
+/* Line 828 of yacc.c  */
 #line 199 "parse-gram.y"
 	{ fputs (char_name (((*yyvaluep).character)), stderr); };
-/* Line 833 of yacc.c  */
-#line 1116 "parse-gram.c"
+/* Line 828 of yacc.c  */
+#line 1114 "parse-gram.c"
 	break;
       case 46: /* "epilogue" */
-/* Line 833 of yacc.c  */
+/* Line 828 of yacc.c  */
 #line 207 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); };
-/* Line 833 of yacc.c  */
-#line 1123 "parse-gram.c"
+/* Line 828 of yacc.c  */
+#line 1121 "parse-gram.c"
 	break;
       case 48: /* "identifier" */
-/* Line 833 of yacc.c  */
+/* Line 828 of yacc.c  */
 #line 211 "parse-gram.y"
 	{ fputs (((*yyvaluep).uniqstr), stderr); };
-/* Line 833 of yacc.c  */
-#line 1130 "parse-gram.c"
+/* Line 828 of yacc.c  */
+#line 1128 "parse-gram.c"
 	break;
       case 49: /* "identifier:" */
-/* Line 833 of yacc.c  */
+/* Line 828 of yacc.c  */
 #line 213 "parse-gram.y"
 	{ fprintf (stderr, "%s:", ((*yyvaluep).uniqstr)); };
-/* Line 833 of yacc.c  */
-#line 1137 "parse-gram.c"
+/* Line 828 of yacc.c  */
+#line 1135 "parse-gram.c"
 	break;
       case 52: /* "%{...%}" */
-/* Line 833 of yacc.c  */
+/* Line 828 of yacc.c  */
 #line 207 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); };
-/* Line 833 of yacc.c  */
-#line 1144 "parse-gram.c"
+/* Line 828 of yacc.c  */
+#line 1142 "parse-gram.c"
 	break;
       case 54: /* "type" */
-/* Line 833 of yacc.c  */
+/* Line 828 of yacc.c  */
 #line 214 "parse-gram.y"
 	{ fprintf (stderr, "<%s>", ((*yyvaluep).uniqstr)); };
-/* Line 833 of yacc.c  */
-#line 1151 "parse-gram.c"
+/* Line 828 of yacc.c  */
+#line 1149 "parse-gram.c"
 	break;
       case 71: /* symbol.prec */
-/* Line 833 of yacc.c  */
+/* Line 828 of yacc.c  */
 #line 220 "parse-gram.y"
 	{ fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); };
-/* Line 833 of yacc.c  */
-#line 1158 "parse-gram.c"
+/* Line 828 of yacc.c  */
+#line 1156 "parse-gram.c"
 	break;
       case 84: /* variable */
-/* Line 833 of yacc.c  */
+/* Line 828 of yacc.c  */
 #line 211 "parse-gram.y"
 	{ fputs (((*yyvaluep).uniqstr), stderr); };
-/* Line 833 of yacc.c  */
-#line 1165 "parse-gram.c"
+/* Line 828 of yacc.c  */
+#line 1163 "parse-gram.c"
 	break;
       case 85: /* content.opt */
-/* Line 833 of yacc.c  */
+/* Line 828 of yacc.c  */
 #line 207 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); };
-/* Line 833 of yacc.c  */
-#line 1172 "parse-gram.c"
+/* Line 828 of yacc.c  */
+#line 1170 "parse-gram.c"
 	break;
       case 86: /* braceless */
-/* Line 833 of yacc.c  */
+/* Line 828 of yacc.c  */
 #line 207 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); };
-/* Line 833 of yacc.c  */
-#line 1179 "parse-gram.c"
+/* Line 828 of yacc.c  */
+#line 1177 "parse-gram.c"
 	break;
       case 87: /* id */
-/* Line 833 of yacc.c  */
+/* Line 828 of yacc.c  */
 #line 220 "parse-gram.y"
 	{ fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); };
-/* Line 833 of yacc.c  */
-#line 1186 "parse-gram.c"
+/* Line 828 of yacc.c  */
+#line 1184 "parse-gram.c"
 	break;
       case 88: /* id_colon */
-/* Line 833 of yacc.c  */
+/* Line 828 of yacc.c  */
 #line 221 "parse-gram.y"
 	{ fprintf (stderr, "%s:", ((*yyvaluep).symbol)->tag); };
-/* Line 833 of yacc.c  */
-#line 1193 "parse-gram.c"
+/* Line 828 of yacc.c  */
+#line 1191 "parse-gram.c"
 	break;
       case 89: /* symbol */
-/* Line 833 of yacc.c  */
+/* Line 828 of yacc.c  */
 #line 220 "parse-gram.y"
 	{ fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); };
-/* Line 833 of yacc.c  */
-#line 1200 "parse-gram.c"
+/* Line 828 of yacc.c  */
+#line 1198 "parse-gram.c"
 	break;
       case 90: /* string_as_id */
-/* Line 833 of yacc.c  */
+/* Line 828 of yacc.c  */
 #line 220 "parse-gram.y"
 	{ fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); };
-/* Line 833 of yacc.c  */
-#line 1207 "parse-gram.c"
+/* Line 828 of yacc.c  */
+#line 1205 "parse-gram.c"
 	break;
       default:
 	break;
@@ -2001,7 +1999,7 @@ YYLTYPE yylloc;
 #endif
 
 /* User initialization code.  */
-/* Line 1596 of yacc.c  */
+/* Line 1591 of yacc.c  */
 #line 107 "parse-gram.y"
 {
   /* Bison's grammar can initial empty locations, hence a default
@@ -2009,8 +2007,8 @@ YYLTYPE yylloc;
   boundary_set (&yylloc.start, current_file, 1, 1);
   boundary_set (&yylloc.end, current_file, 1, 1);
 }
-/* Line 1596 of yacc.c  */
-#line 2014 "parse-gram.c"
+/* Line 1591 of yacc.c  */
+#line 2012 "parse-gram.c"
   yylsp[0] = yylloc;
   goto yysetstate;
 
@@ -2204,7 +2202,7 @@ yyreduce:
     switch (yyn)
       {
           case 6:
-/* Line 1813 of yacc.c  */
+/* Line 1808 of yacc.c  */
 #line 246 "parse-gram.y"
     {
       code_props plain_code;
@@ -2218,13 +2216,13 @@ yyreduce:
     break;
 
   case 7:
-/* Line 1813 of yacc.c  */
+/* Line 1808 of yacc.c  */
 #line 255 "parse-gram.y"
-    { debug_flag = true; }
+    { debug = true; }
     break;
 
   case 8:
-/* Line 1813 of yacc.c  */
+/* Line 1808 of yacc.c  */
 #line 257 "parse-gram.y"
     {
       muscle_percent_define_insert ((yyvsp[(2) - (3)].uniqstr), (yylsp[(2) - (3)]), (yyvsp[(3) - (3)].chars),
@@ -2233,13 +2231,13 @@ yyreduce:
     break;
 
   case 9:
-/* Line 1813 of yacc.c  */
+/* Line 1808 of yacc.c  */
 #line 261 "parse-gram.y"
     { defines_flag = true; }
     break;
 
   case 10:
-/* Line 1813 of yacc.c  */
+/* Line 1808 of yacc.c  */
 #line 263 "parse-gram.y"
     {
       defines_flag = true;
@@ -2248,37 +2246,37 @@ yyreduce:
     break;
 
   case 11:
-/* Line 1813 of yacc.c  */
+/* Line 1808 of yacc.c  */
 #line 267 "parse-gram.y"
     { error_verbose = true; }
     break;
 
   case 12:
-/* Line 1813 of yacc.c  */
+/* Line 1808 of yacc.c  */
 #line 268 "parse-gram.y"
     { expected_sr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 13:
-/* Line 1813 of yacc.c  */
+/* Line 1808 of yacc.c  */
 #line 269 "parse-gram.y"
     { expected_rr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 14:
-/* Line 1813 of yacc.c  */
+/* Line 1808 of yacc.c  */
 #line 270 "parse-gram.y"
     { spec_file_prefix = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 15:
-/* Line 1813 of yacc.c  */
+/* Line 1808 of yacc.c  */
 #line 271 "parse-gram.y"
     { spec_file_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 16:
-/* Line 1813 of yacc.c  */
+/* Line 1808 of yacc.c  */
 #line 273 "parse-gram.y"
     {
       nondeterministic_parser = true;
@@ -2287,7 +2285,7 @@ yyreduce:
     break;
 
   case 17:
-/* Line 1813 of yacc.c  */
+/* Line 1808 of yacc.c  */
 #line 278 "parse-gram.y"
     {
       code_props action;
@@ -2300,67 +2298,67 @@ yyreduce:
     break;
 
   case 18:
-/* Line 1813 of yacc.c  */
+/* Line 1808 of yacc.c  */
 #line 286 "parse-gram.y"
     { language_argmatch ((yyvsp[(2) - (2)].chars), grammar_prio, (yylsp[(1) - (2)])); }
     break;
 
   case 19:
-/* Line 1813 of yacc.c  */
+/* Line 1808 of yacc.c  */
 #line 287 "parse-gram.y"
     { add_param ("lex_param", (yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
     break;
 
   case 20:
-/* Line 1813 of yacc.c  */
+/* Line 1808 of yacc.c  */
 #line 288 "parse-gram.y"
     { locations_flag = true; }
     break;
 
   case 21:
-/* Line 1813 of yacc.c  */
+/* Line 1808 of yacc.c  */
 #line 289 "parse-gram.y"
     { spec_name_prefix = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 22:
-/* Line 1813 of yacc.c  */
+/* Line 1808 of yacc.c  */
 #line 290 "parse-gram.y"
     { spec_name_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 23:
-/* Line 1813 of yacc.c  */
+/* Line 1808 of yacc.c  */
 #line 291 "parse-gram.y"
     { no_lines_flag = true; }
     break;
 
   case 24:
-/* Line 1813 of yacc.c  */
+/* Line 1808 of yacc.c  */
 #line 292 "parse-gram.y"
     { nondeterministic_parser = true; }
     break;
 
   case 25:
-/* Line 1813 of yacc.c  */
+/* Line 1808 of yacc.c  */
 #line 293 "parse-gram.y"
     { spec_outfile = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 26:
-/* Line 1813 of yacc.c  */
+/* Line 1808 of yacc.c  */
 #line 294 "parse-gram.y"
     { spec_outfile = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 27:
-/* Line 1813 of yacc.c  */
+/* Line 1808 of yacc.c  */
 #line 295 "parse-gram.y"
     { add_param ("parse_param", (yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
     break;
 
   case 28:
-/* Line 1813 of yacc.c  */
+/* Line 1808 of yacc.c  */
 #line 297 "parse-gram.y"
     {
       /* %pure-parser is deprecated in favor of `%define api.pure', so use
@@ -2379,13 +2377,13 @@ yyreduce:
     break;
 
   case 29:
-/* Line 1813 of yacc.c  */
+/* Line 1808 of yacc.c  */
 #line 311 "parse-gram.y"
     { version_check (&(yylsp[(2) - (2)]), (yyvsp[(2) - (2)].chars)); }
     break;
 
   case 30:
-/* Line 1813 of yacc.c  */
+/* Line 1808 of yacc.c  */
 #line 313 "parse-gram.y"
     {
       char const *skeleton_user = (yyvsp[(2) - (2)].chars);
@@ -2413,25 +2411,25 @@ yyreduce:
     break;
 
   case 31:
-/* Line 1813 of yacc.c  */
+/* Line 1808 of yacc.c  */
 #line 336 "parse-gram.y"
     { token_table_flag = true; }
     break;
 
   case 32:
-/* Line 1813 of yacc.c  */
+/* Line 1808 of yacc.c  */
 #line 337 "parse-gram.y"
     { report_flag |= report_states; }
     break;
 
   case 33:
-/* Line 1813 of yacc.c  */
+/* Line 1808 of yacc.c  */
 #line 338 "parse-gram.y"
     { yacc_flag = true; }
     break;
 
   case 37:
-/* Line 1813 of yacc.c  */
+/* Line 1808 of yacc.c  */
 #line 346 "parse-gram.y"
     {
       grammar_start_symbol_set ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]));
@@ -2439,7 +2437,7 @@ yyreduce:
     break;
 
   case 38:
-/* Line 1813 of yacc.c  */
+/* Line 1808 of yacc.c  */
 #line 350 "parse-gram.y"
     {
       code_props code;
@@ -2455,7 +2453,7 @@ yyreduce:
     break;
 
   case 39:
-/* Line 1813 of yacc.c  */
+/* Line 1808 of yacc.c  */
 #line 362 "parse-gram.y"
     {
       code_props code;
@@ -2471,7 +2469,7 @@ yyreduce:
     break;
 
   case 40:
-/* Line 1813 of yacc.c  */
+/* Line 1808 of yacc.c  */
 #line 374 "parse-gram.y"
     {
       default_prec = true;
@@ -2479,7 +2477,7 @@ yyreduce:
     break;
 
   case 41:
-/* Line 1813 of yacc.c  */
+/* Line 1808 of yacc.c  */
 #line 378 "parse-gram.y"
     {
       default_prec = false;
@@ -2487,7 +2485,7 @@ yyreduce:
     break;
 
   case 42:
-/* Line 1813 of yacc.c  */
+/* Line 1808 of yacc.c  */
 #line 382 "parse-gram.y"
     {
       /* Do not invoke muscle_percent_code_grow here since it invokes
@@ -2498,7 +2496,7 @@ yyreduce:
     break;
 
   case 43:
-/* Line 1813 of yacc.c  */
+/* Line 1808 of yacc.c  */
 #line 389 "parse-gram.y"
     {
       muscle_percent_code_grow ((yyvsp[(2) - (3)].uniqstr), (yylsp[(2) - (3)]), (yyvsp[(3) - (3)].chars), (yylsp[(3) - (3)]));
@@ -2507,19 +2505,19 @@ yyreduce:
     break;
 
   case 44:
-/* Line 1813 of yacc.c  */
+/* Line 1808 of yacc.c  */
 #line 403 "parse-gram.y"
     {}
     break;
 
   case 45:
-/* Line 1813 of yacc.c  */
+/* Line 1808 of yacc.c  */
 #line 404 "parse-gram.y"
     { muscle_code_grow ("union_name", (yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 46:
-/* Line 1813 of yacc.c  */
+/* Line 1808 of yacc.c  */
 #line 409 "parse-gram.y"
     {
       union_seen = true;
@@ -2529,13 +2527,13 @@ yyreduce:
     break;
 
   case 47:
-/* Line 1813 of yacc.c  */
+/* Line 1808 of yacc.c  */
 #line 420 "parse-gram.y"
     { current_class = nterm_sym; }
     break;
 
   case 48:
-/* Line 1813 of yacc.c  */
+/* Line 1808 of yacc.c  */
 #line 421 "parse-gram.y"
     {
       current_class = unknown_sym;
@@ -2544,13 +2542,13 @@ yyreduce:
     break;
 
   case 49:
-/* Line 1813 of yacc.c  */
+/* Line 1808 of yacc.c  */
 #line 425 "parse-gram.y"
     { current_class = token_sym; }
     break;
 
   case 50:
-/* Line 1813 of yacc.c  */
+/* Line 1808 of yacc.c  */
 #line 426 "parse-gram.y"
     {
       current_class = unknown_sym;
@@ -2559,7 +2557,7 @@ yyreduce:
     break;
 
   case 51:
-/* Line 1813 of yacc.c  */
+/* Line 1808 of yacc.c  */
 #line 431 "parse-gram.y"
     {
       symbol_list *list;
@@ -2571,7 +2569,7 @@ yyreduce:
     break;
 
   case 52:
-/* Line 1813 of yacc.c  */
+/* Line 1808 of yacc.c  */
 #line 442 "parse-gram.y"
     {
       symbol_list *list;
@@ -2587,109 +2585,109 @@ yyreduce:
     break;
 
   case 53:
-/* Line 1813 of yacc.c  */
+/* Line 1808 of yacc.c  */
 #line 456 "parse-gram.y"
     { (yyval.assoc) = left_assoc; }
     break;
 
   case 54:
-/* Line 1813 of yacc.c  */
+/* Line 1808 of yacc.c  */
 #line 457 "parse-gram.y"
     { (yyval.assoc) = right_assoc; }
     break;
 
   case 55:
-/* Line 1813 of yacc.c  */
+/* Line 1808 of yacc.c  */
 #line 458 "parse-gram.y"
     { (yyval.assoc) = non_assoc; }
     break;
 
   case 56:
-/* Line 1813 of yacc.c  */
+/* Line 1808 of yacc.c  */
 #line 462 "parse-gram.y"
     { current_type = NULL; }
     break;
 
   case 57:
-/* Line 1813 of yacc.c  */
+/* Line 1808 of yacc.c  */
 #line 463 "parse-gram.y"
     { current_type = (yyvsp[(1) - (1)].uniqstr); tag_seen = true; }
     break;
 
   case 58:
-/* Line 1813 of yacc.c  */
+/* Line 1808 of yacc.c  */
 #line 469 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 59:
-/* Line 1813 of yacc.c  */
+/* Line 1808 of yacc.c  */
 #line 471 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), symbol_list_sym_new ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]))); }
     break;
 
   case 60:
-/* Line 1813 of yacc.c  */
+/* Line 1808 of yacc.c  */
 #line 475 "parse-gram.y"
     { (yyval.symbol) = (yyvsp[(1) - (1)].symbol); }
     break;
 
   case 61:
-/* Line 1813 of yacc.c  */
+/* Line 1808 of yacc.c  */
 #line 476 "parse-gram.y"
     { (yyval.symbol) = (yyvsp[(1) - (2)].symbol); symbol_user_token_number_set ((yyvsp[(1) - (2)].symbol), (yyvsp[(2) - (2)].integer), (yylsp[(2) - (2)])); }
     break;
 
   case 62:
-/* Line 1813 of yacc.c  */
+/* Line 1808 of yacc.c  */
 #line 482 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 63:
-/* Line 1813 of yacc.c  */
+/* Line 1808 of yacc.c  */
 #line 484 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), symbol_list_sym_new ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]))); }
     break;
 
   case 64:
-/* Line 1813 of yacc.c  */
+/* Line 1808 of yacc.c  */
 #line 488 "parse-gram.y"
     { (yyval.list) = (yyvsp[(1) - (1)].list); }
     break;
 
   case 65:
-/* Line 1813 of yacc.c  */
+/* Line 1808 of yacc.c  */
 #line 489 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), (yyvsp[(2) - (2)].list)); }
     break;
 
   case 66:
-/* Line 1813 of yacc.c  */
+/* Line 1808 of yacc.c  */
 #line 493 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 67:
-/* Line 1813 of yacc.c  */
+/* Line 1808 of yacc.c  */
 #line 494 "parse-gram.y"
     { (yyval.list) = symbol_list_type_new ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 68:
-/* Line 1813 of yacc.c  */
+/* Line 1808 of yacc.c  */
 #line 495 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagged_new ((yylsp[(1) - (1)])); }
     break;
 
   case 69:
-/* Line 1813 of yacc.c  */
+/* Line 1808 of yacc.c  */
 #line 496 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagless_new ((yylsp[(1) - (1)])); }
     break;
 
   case 70:
-/* Line 1813 of yacc.c  */
+/* Line 1808 of yacc.c  */
 #line 502 "parse-gram.y"
     {
        current_type = (yyvsp[(1) - (1)].uniqstr);
@@ -2698,7 +2696,7 @@ yyreduce:
     break;
 
   case 71:
-/* Line 1813 of yacc.c  */
+/* Line 1808 of yacc.c  */
 #line 507 "parse-gram.y"
     {
        symbol_class_set ((yyvsp[(1) - (1)].symbol), current_class, (yylsp[(1) - (1)]), true);
@@ -2707,7 +2705,7 @@ yyreduce:
     break;
 
   case 72:
-/* Line 1813 of yacc.c  */
+/* Line 1808 of yacc.c  */
 #line 512 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
@@ -2717,7 +2715,7 @@ yyreduce:
     break;
 
   case 73:
-/* Line 1813 of yacc.c  */
+/* Line 1808 of yacc.c  */
 #line 518 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
@@ -2727,7 +2725,7 @@ yyreduce:
     break;
 
   case 74:
-/* Line 1813 of yacc.c  */
+/* Line 1808 of yacc.c  */
 #line 524 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (3)].symbol), current_class, (yylsp[(1) - (3)]), true);
@@ -2738,7 +2736,7 @@ yyreduce:
     break;
 
   case 81:
-/* Line 1813 of yacc.c  */
+/* Line 1808 of yacc.c  */
 #line 554 "parse-gram.y"
     {
       yyerrok;
@@ -2746,13 +2744,13 @@ yyreduce:
     break;
 
   case 82:
-/* Line 1813 of yacc.c  */
+/* Line 1808 of yacc.c  */
 #line 560 "parse-gram.y"
     { current_lhs ((yyvsp[(1) - (2)].symbol), (yylsp[(1) - (2)]), (yyvsp[(2) - (2)].named_ref)); }
     break;
 
   case 83:
-/* Line 1813 of yacc.c  */
+/* Line 1808 of yacc.c  */
 #line 561 "parse-gram.y"
     {
     /* Free the current lhs. */
@@ -2761,86 +2759,86 @@ yyreduce:
     break;
 
   case 84:
-/* Line 1813 of yacc.c  */
+/* Line 1808 of yacc.c  */
 #line 568 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(1) - (1)])); }
     break;
 
   case 85:
-/* Line 1813 of yacc.c  */
+/* Line 1808 of yacc.c  */
 #line 569 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(3) - (3)])); }
     break;
 
   case 87:
-/* Line 1813 of yacc.c  */
+/* Line 1808 of yacc.c  */
 #line 575 "parse-gram.y"
     { grammar_current_rule_begin (current_lhs_symbol, current_lhs_location,
 				  current_lhs_named_ref); }
     break;
 
   case 88:
-/* Line 1813 of yacc.c  */
+/* Line 1808 of yacc.c  */
 #line 578 "parse-gram.y"
     { grammar_current_rule_symbol_append ((yyvsp[(2) - (3)].symbol), (yylsp[(2) - (3)]), (yyvsp[(3) - (3)].named_ref)); }
     break;
 
   case 89:
-/* Line 1813 of yacc.c  */
+/* Line 1808 of yacc.c  */
 #line 580 "parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[(2) - (3)].code), (yylsp[(2) - (3)]), (yyvsp[(3) - (3)].named_ref)); }
     break;
 
   case 90:
-/* Line 1813 of yacc.c  */
+/* Line 1808 of yacc.c  */
 #line 582 "parse-gram.y"
     { grammar_current_rule_prec_set ((yyvsp[(3) - (3)].symbol), (yylsp[(3) - (3)])); }
     break;
 
   case 91:
-/* Line 1813 of yacc.c  */
+/* Line 1808 of yacc.c  */
 #line 584 "parse-gram.y"
     { grammar_current_rule_dprec_set ((yyvsp[(3) - (3)].integer), (yylsp[(3) - (3)])); }
     break;
 
   case 92:
-/* Line 1813 of yacc.c  */
+/* Line 1808 of yacc.c  */
 #line 586 "parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[(3) - (3)].uniqstr), (yylsp[(3) - (3)])); }
     break;
 
   case 93:
-/* Line 1813 of yacc.c  */
+/* Line 1808 of yacc.c  */
 #line 590 "parse-gram.y"
     { (yyval.named_ref) = 0; }
     break;
 
   case 94:
-/* Line 1813 of yacc.c  */
+/* Line 1808 of yacc.c  */
 #line 592 "parse-gram.y"
     { (yyval.named_ref) = named_ref_new((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 96:
-/* Line 1813 of yacc.c  */
+/* Line 1808 of yacc.c  */
 #line 604 "parse-gram.y"
     { (yyval.uniqstr) = uniqstr_new ((yyvsp[(1) - (1)].chars)); }
     break;
 
   case 97:
-/* Line 1813 of yacc.c  */
+/* Line 1808 of yacc.c  */
 #line 609 "parse-gram.y"
     { (yyval.chars) = ""; }
     break;
 
   case 98:
-/* Line 1813 of yacc.c  */
+/* Line 1808 of yacc.c  */
 #line 610 "parse-gram.y"
     { (yyval.chars) = (yyvsp[(1) - (1)].uniqstr); }
     break;
 
   case 100:
-/* Line 1813 of yacc.c  */
+/* Line 1808 of yacc.c  */
 #line 621 "parse-gram.y"
     {
       code_props plain_code;
@@ -2853,13 +2851,13 @@ yyreduce:
     break;
 
   case 101:
-/* Line 1813 of yacc.c  */
+/* Line 1808 of yacc.c  */
 #line 641 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 102:
-/* Line 1813 of yacc.c  */
+/* Line 1808 of yacc.c  */
 #line 643 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[(1) - (1)].character)), (yylsp[(1) - (1)]));
@@ -2869,13 +2867,13 @@ yyreduce:
     break;
 
   case 103:
-/* Line 1813 of yacc.c  */
+/* Line 1808 of yacc.c  */
 #line 651 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 106:
-/* Line 1813 of yacc.c  */
+/* Line 1808 of yacc.c  */
 #line 663 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[(1) - (1)].chars)), (yylsp[(1) - (1)]));
@@ -2884,7 +2882,7 @@ yyreduce:
     break;
 
   case 108:
-/* Line 1813 of yacc.c  */
+/* Line 1808 of yacc.c  */
 #line 672 "parse-gram.y"
     {
       code_props plain_code;
@@ -2897,8 +2895,8 @@ yyreduce:
     break;
 
 
-/* Line 1813 of yacc.c  */
-#line 2902 "parse-gram.c"
+/* Line 1808 of yacc.c  */
+#line 2900 "parse-gram.c"
         default: break;
       }
     if (yychar_backup != yychar)
@@ -3148,7 +3146,7 @@ yyreturn:
 }
 
 
-/* Line 2076 of yacc.c  */
+/* Line 2071 of yacc.c  */
 #line 682 "parse-gram.y"
 
 
