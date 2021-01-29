@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 2.4.1.302-e8fa.  */
+/* A Bison parser, made by GNU Bison 2.5.53-c925.  */
 
 /* Bison implementation for Yacc-like parsers in C
    
@@ -44,7 +44,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "2.4.1.302-e8fa"
+#define YYBISON_VERSION "2.5.53-c925"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -169,7 +169,7 @@ current_lhs(symbol *sym, location loc, named_ref *ref)
 
 
 /* Line 268 of yacc.c  */
-#line 173 "parse-gram.c"
+#line 173 "../../../src/parse-gram.c"
 
 /* Enabling traces.  */
 #ifndef YYDEBUG
@@ -335,7 +335,7 @@ typedef union YYSTYPE
 
 
 /* Line 293 of yacc.c  */
-#line 339 "parse-gram.c"
+#line 339 "../../../src/parse-gram.c"
 } YYSTYPE;
 # define YYSTYPE_IS_TRIVIAL 1
 # define yystype YYSTYPE /* obsolescent; will be withdrawn */
@@ -360,7 +360,7 @@ typedef struct YYLTYPE
 
 
 /* Line 343 of yacc.c  */
-#line 364 "parse-gram.c"
+#line 364 "../../../src/parse-gram.c"
 
 #ifdef short
 # undef short
@@ -919,18 +919,19 @@ static const yytype_uint8 yystos[] =
 
 #define YYRECOVERING()  (!!yyerrstatus)
 
-#define YYBACKUP(Token, Value)					\
-do								\
-  if (yychar == YYEMPTY && yylen == 1)				\
-    {								\
-      yychar = (Token);						\
-      yylval = (Value);						\
-      YYPOPSTACK (1);						\
-      YY_LAC_DISCARD ("YYBACKUP");				\
-      goto yybackup;						\
-    }								\
-  else								\
-    {								\
+#define YYBACKUP(Token, Value)                                  \
+do                                                              \
+  if (yychar == YYEMPTY)                                        \
+    {                                                           \
+      yychar = (Token);                                         \
+      yylval = (Value);                                         \
+      YYPOPSTACK (yylen);                                       \
+      yystate = *yyssp;                                         \
+      YY_LAC_DISCARD ("YYBACKUP");                              \
+      goto yybackup;                                            \
+    }                                                           \
+  else                                                          \
+    {                                                           \
       yyerror (YY_("syntax error: cannot back up")); \
       YYERROR;							\
     }								\
@@ -1048,165 +1049,165 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
     {
       case 3: /* "\"string\"" */
 
-/* Line 819 of yacc.c  */
+/* Line 820 of yacc.c  */
 #line 203 "parse-gram.y"
 	{ fputs (quotearg_style (c_quoting_style, (yyvaluep->chars)), stderr); };
 
-/* Line 819 of yacc.c  */
-#line 1057 "parse-gram.c"
+/* Line 820 of yacc.c  */
+#line 1058 "../../../src/parse-gram.c"
 	break;
       case 4: /* "\"integer\"" */
 
-/* Line 819 of yacc.c  */
+/* Line 820 of yacc.c  */
 #line 215 "parse-gram.y"
 	{ fprintf (stderr, "%d", (yyvaluep->integer)); };
 
-/* Line 819 of yacc.c  */
-#line 1066 "parse-gram.c"
+/* Line 820 of yacc.c  */
+#line 1067 "../../../src/parse-gram.c"
 	break;
       case 43: /* "\"{...}\"" */
 
-/* Line 819 of yacc.c  */
+/* Line 820 of yacc.c  */
 #line 205 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->code)); };
 
-/* Line 819 of yacc.c  */
-#line 1075 "parse-gram.c"
+/* Line 820 of yacc.c  */
+#line 1076 "../../../src/parse-gram.c"
 	break;
       case 44: /* "\"[identifier]\"" */
 
-/* Line 819 of yacc.c  */
+/* Line 820 of yacc.c  */
 #line 210 "parse-gram.y"
 	{ fprintf (stderr, "[%s]", (yyvaluep->uniqstr)); };
 
-/* Line 819 of yacc.c  */
-#line 1084 "parse-gram.c"
+/* Line 820 of yacc.c  */
+#line 1085 "../../../src/parse-gram.c"
 	break;
       case 45: /* "\"char\"" */
 
-/* Line 819 of yacc.c  */
+/* Line 820 of yacc.c  */
 #line 197 "parse-gram.y"
 	{ fputs (char_name ((yyvaluep->character)), stderr); };
 
-/* Line 819 of yacc.c  */
-#line 1093 "parse-gram.c"
+/* Line 820 of yacc.c  */
+#line 1094 "../../../src/parse-gram.c"
 	break;
       case 46: /* "\"epilogue\"" */
 
-/* Line 819 of yacc.c  */
+/* Line 820 of yacc.c  */
 #line 205 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
-/* Line 819 of yacc.c  */
-#line 1102 "parse-gram.c"
+/* Line 820 of yacc.c  */
+#line 1103 "../../../src/parse-gram.c"
 	break;
       case 48: /* "\"identifier\"" */
 
-/* Line 819 of yacc.c  */
+/* Line 820 of yacc.c  */
 #line 209 "parse-gram.y"
 	{ fputs ((yyvaluep->uniqstr), stderr); };
 
-/* Line 819 of yacc.c  */
-#line 1111 "parse-gram.c"
+/* Line 820 of yacc.c  */
+#line 1112 "../../../src/parse-gram.c"
 	break;
       case 49: /* "\"identifier:\"" */
 
-/* Line 819 of yacc.c  */
+/* Line 820 of yacc.c  */
 #line 211 "parse-gram.y"
 	{ fprintf (stderr, "%s:", (yyvaluep->uniqstr)); };
 
-/* Line 819 of yacc.c  */
-#line 1120 "parse-gram.c"
+/* Line 820 of yacc.c  */
+#line 1121 "../../../src/parse-gram.c"
 	break;
       case 52: /* "\"%{...%}\"" */
 
-/* Line 819 of yacc.c  */
+/* Line 820 of yacc.c  */
 #line 205 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
-/* Line 819 of yacc.c  */
-#line 1129 "parse-gram.c"
+/* Line 820 of yacc.c  */
+#line 1130 "../../../src/parse-gram.c"
 	break;
       case 54: /* "\"type\"" */
 
-/* Line 819 of yacc.c  */
+/* Line 820 of yacc.c  */
 #line 212 "parse-gram.y"
 	{ fprintf (stderr, "<%s>", (yyvaluep->uniqstr)); };
 
-/* Line 819 of yacc.c  */
-#line 1138 "parse-gram.c"
+/* Line 820 of yacc.c  */
+#line 1139 "../../../src/parse-gram.c"
 	break;
       case 71: /* "symbol.prec" */
 
-/* Line 819 of yacc.c  */
+/* Line 820 of yacc.c  */
 #line 218 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
-/* Line 819 of yacc.c  */
-#line 1147 "parse-gram.c"
+/* Line 820 of yacc.c  */
+#line 1148 "../../../src/parse-gram.c"
 	break;
       case 84: /* "variable" */
 
-/* Line 819 of yacc.c  */
+/* Line 820 of yacc.c  */
 #line 209 "parse-gram.y"
 	{ fputs ((yyvaluep->uniqstr), stderr); };
 
-/* Line 819 of yacc.c  */
-#line 1156 "parse-gram.c"
+/* Line 820 of yacc.c  */
+#line 1157 "../../../src/parse-gram.c"
 	break;
       case 85: /* "content.opt" */
 
-/* Line 819 of yacc.c  */
+/* Line 820 of yacc.c  */
 #line 205 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
-/* Line 819 of yacc.c  */
-#line 1165 "parse-gram.c"
+/* Line 820 of yacc.c  */
+#line 1166 "../../../src/parse-gram.c"
 	break;
       case 86: /* "braceless" */
 
-/* Line 819 of yacc.c  */
+/* Line 820 of yacc.c  */
 #line 205 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
-/* Line 819 of yacc.c  */
-#line 1174 "parse-gram.c"
+/* Line 820 of yacc.c  */
+#line 1175 "../../../src/parse-gram.c"
 	break;
       case 87: /* "id" */
 
-/* Line 819 of yacc.c  */
+/* Line 820 of yacc.c  */
 #line 218 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
-/* Line 819 of yacc.c  */
-#line 1183 "parse-gram.c"
+/* Line 820 of yacc.c  */
+#line 1184 "../../../src/parse-gram.c"
 	break;
       case 88: /* "id_colon" */
 
-/* Line 819 of yacc.c  */
+/* Line 820 of yacc.c  */
 #line 219 "parse-gram.y"
 	{ fprintf (stderr, "%s:", (yyvaluep->symbol)->tag); };
 
-/* Line 819 of yacc.c  */
-#line 1192 "parse-gram.c"
+/* Line 820 of yacc.c  */
+#line 1193 "../../../src/parse-gram.c"
 	break;
       case 89: /* "symbol" */
 
-/* Line 819 of yacc.c  */
+/* Line 820 of yacc.c  */
 #line 218 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
-/* Line 819 of yacc.c  */
-#line 1201 "parse-gram.c"
+/* Line 820 of yacc.c  */
+#line 1202 "../../../src/parse-gram.c"
 	break;
       case 90: /* "string_as_id" */
 
-/* Line 819 of yacc.c  */
+/* Line 820 of yacc.c  */
 #line 218 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
-/* Line 819 of yacc.c  */
-#line 1210 "parse-gram.c"
+/* Line 820 of yacc.c  */
+#line 1211 "../../../src/parse-gram.c"
 	break;
       default:
 	break;
@@ -1997,7 +1998,7 @@ YYLTYPE yylloc;
 
 /* User initialization code.  */
 
-/* Line 1590 of yacc.c  */
+/* Line 1591 of yacc.c  */
 #line 105 "parse-gram.y"
 {
   /* Bison's grammar can initial empty locations, hence a default
@@ -2006,8 +2007,8 @@ YYLTYPE yylloc;
   boundary_set (&yylloc.end, current_file, 1, 1);
 }
 
-/* Line 1590 of yacc.c  */
-#line 2011 "parse-gram.c"
+/* Line 1591 of yacc.c  */
+#line 2012 "../../../src/parse-gram.c"
   yylsp[0] = yylloc;
 
   goto yysetstate;
@@ -2201,7 +2202,7 @@ yyreduce:
       {
           case 6:
 
-/* Line 1806 of yacc.c  */
+/* Line 1807 of yacc.c  */
 #line 244 "parse-gram.y"
     {
       code_props plain_code;
@@ -2216,14 +2217,14 @@ yyreduce:
 
   case 7:
 
-/* Line 1806 of yacc.c  */
+/* Line 1807 of yacc.c  */
 #line 253 "parse-gram.y"
     { debug_flag = true; }
     break;
 
   case 8:
 
-/* Line 1806 of yacc.c  */
+/* Line 1807 of yacc.c  */
 #line 255 "parse-gram.y"
     {
       muscle_percent_define_insert ((yyvsp[(2) - (3)].uniqstr), (yylsp[(2) - (3)]), (yyvsp[(3) - (3)].chars),
@@ -2233,14 +2234,14 @@ yyreduce:
 
   case 9:
 
-/* Line 1806 of yacc.c  */
+/* Line 1807 of yacc.c  */
 #line 259 "parse-gram.y"
     { defines_flag = true; }
     break;
 
   case 10:
 
-/* Line 1806 of yacc.c  */
+/* Line 1807 of yacc.c  */
 #line 261 "parse-gram.y"
     {
       defines_flag = true;
@@ -2250,42 +2251,42 @@ yyreduce:
 
   case 11:
 
-/* Line 1806 of yacc.c  */
+/* Line 1807 of yacc.c  */
 #line 265 "parse-gram.y"
     { error_verbose = true; }
     break;
 
   case 12:
 
-/* Line 1806 of yacc.c  */
+/* Line 1807 of yacc.c  */
 #line 266 "parse-gram.y"
     { expected_sr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 13:
 
-/* Line 1806 of yacc.c  */
+/* Line 1807 of yacc.c  */
 #line 267 "parse-gram.y"
     { expected_rr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 14:
 
-/* Line 1806 of yacc.c  */
+/* Line 1807 of yacc.c  */
 #line 268 "parse-gram.y"
     { spec_file_prefix = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 15:
 
-/* Line 1806 of yacc.c  */
+/* Line 1807 of yacc.c  */
 #line 269 "parse-gram.y"
     { spec_file_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 16:
 
-/* Line 1806 of yacc.c  */
+/* Line 1807 of yacc.c  */
 #line 271 "parse-gram.y"
     {
       nondeterministic_parser = true;
@@ -2295,7 +2296,7 @@ yyreduce:
 
   case 17:
 
-/* Line 1806 of yacc.c  */
+/* Line 1807 of yacc.c  */
 #line 276 "parse-gram.y"
     {
       code_props action;
@@ -2309,77 +2310,77 @@ yyreduce:
 
   case 18:
 
-/* Line 1806 of yacc.c  */
+/* Line 1807 of yacc.c  */
 #line 284 "parse-gram.y"
     { language_argmatch ((yyvsp[(2) - (2)].chars), grammar_prio, (yylsp[(1) - (2)])); }
     break;
 
   case 19:
 
-/* Line 1806 of yacc.c  */
+/* Line 1807 of yacc.c  */
 #line 285 "parse-gram.y"
     { add_param ("lex_param", (yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
     break;
 
   case 20:
 
-/* Line 1806 of yacc.c  */
+/* Line 1807 of yacc.c  */
 #line 286 "parse-gram.y"
     { locations_flag = true; }
     break;
 
   case 21:
 
-/* Line 1806 of yacc.c  */
+/* Line 1807 of yacc.c  */
 #line 287 "parse-gram.y"
     { spec_name_prefix = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 22:
 
-/* Line 1806 of yacc.c  */
+/* Line 1807 of yacc.c  */
 #line 288 "parse-gram.y"
     { spec_name_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 23:
 
-/* Line 1806 of yacc.c  */
+/* Line 1807 of yacc.c  */
 #line 289 "parse-gram.y"
     { no_lines_flag = true; }
     break;
 
   case 24:
 
-/* Line 1806 of yacc.c  */
+/* Line 1807 of yacc.c  */
 #line 290 "parse-gram.y"
     { nondeterministic_parser = true; }
     break;
 
   case 25:
 
-/* Line 1806 of yacc.c  */
+/* Line 1807 of yacc.c  */
 #line 291 "parse-gram.y"
     { spec_outfile = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 26:
 
-/* Line 1806 of yacc.c  */
+/* Line 1807 of yacc.c  */
 #line 292 "parse-gram.y"
     { spec_outfile = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 27:
 
-/* Line 1806 of yacc.c  */
+/* Line 1807 of yacc.c  */
 #line 293 "parse-gram.y"
     { add_param ("parse_param", (yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
     break;
 
   case 28:
 
-/* Line 1806 of yacc.c  */
+/* Line 1807 of yacc.c  */
 #line 295 "parse-gram.y"
     {
       /* %pure-parser is deprecated in favor of `%define api.pure', so use
@@ -2399,14 +2400,14 @@ yyreduce:
 
   case 29:
 
-/* Line 1806 of yacc.c  */
+/* Line 1807 of yacc.c  */
 #line 309 "parse-gram.y"
     { version_check (&(yylsp[(2) - (2)]), (yyvsp[(2) - (2)].chars)); }
     break;
 
   case 30:
 
-/* Line 1806 of yacc.c  */
+/* Line 1807 of yacc.c  */
 #line 311 "parse-gram.y"
     {
       char const *skeleton_user = (yyvsp[(2) - (2)].chars);
@@ -2435,28 +2436,28 @@ yyreduce:
 
   case 31:
 
-/* Line 1806 of yacc.c  */
+/* Line 1807 of yacc.c  */
 #line 334 "parse-gram.y"
     { token_table_flag = true; }
     break;
 
   case 32:
 
-/* Line 1806 of yacc.c  */
+/* Line 1807 of yacc.c  */
 #line 335 "parse-gram.y"
     { report_flag |= report_states; }
     break;
 
   case 33:
 
-/* Line 1806 of yacc.c  */
+/* Line 1807 of yacc.c  */
 #line 336 "parse-gram.y"
     { yacc_flag = true; }
     break;
 
   case 37:
 
-/* Line 1806 of yacc.c  */
+/* Line 1807 of yacc.c  */
 #line 344 "parse-gram.y"
     {
       grammar_start_symbol_set ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]));
@@ -2465,7 +2466,7 @@ yyreduce:
 
   case 38:
 
-/* Line 1806 of yacc.c  */
+/* Line 1807 of yacc.c  */
 #line 348 "parse-gram.y"
     {
       symbol_list *list;
@@ -2477,7 +2478,7 @@ yyreduce:
 
   case 39:
 
-/* Line 1806 of yacc.c  */
+/* Line 1807 of yacc.c  */
 #line 355 "parse-gram.y"
     {
       symbol_list *list;
@@ -2489,7 +2490,7 @@ yyreduce:
 
   case 40:
 
-/* Line 1806 of yacc.c  */
+/* Line 1807 of yacc.c  */
 #line 362 "parse-gram.y"
     {
       default_prec = true;
@@ -2498,7 +2499,7 @@ yyreduce:
 
   case 41:
 
-/* Line 1806 of yacc.c  */
+/* Line 1807 of yacc.c  */
 #line 366 "parse-gram.y"
     {
       default_prec = false;
@@ -2507,7 +2508,7 @@ yyreduce:
 
   case 42:
 
-/* Line 1806 of yacc.c  */
+/* Line 1807 of yacc.c  */
 #line 370 "parse-gram.y"
     {
       /* Do not invoke muscle_percent_code_grow here since it invokes
@@ -2519,7 +2520,7 @@ yyreduce:
 
   case 43:
 
-/* Line 1806 of yacc.c  */
+/* Line 1807 of yacc.c  */
 #line 377 "parse-gram.y"
     {
       muscle_percent_code_grow ((yyvsp[(2) - (3)].uniqstr), (yylsp[(2) - (3)]), (yyvsp[(3) - (3)].chars), (yylsp[(3) - (3)]));
@@ -2529,21 +2530,21 @@ yyreduce:
 
   case 44:
 
-/* Line 1806 of yacc.c  */
+/* Line 1807 of yacc.c  */
 #line 391 "parse-gram.y"
     {}
     break;
 
   case 45:
 
-/* Line 1806 of yacc.c  */
+/* Line 1807 of yacc.c  */
 #line 392 "parse-gram.y"
     { muscle_code_grow ("union_name", (yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 46:
 
-/* Line 1806 of yacc.c  */
+/* Line 1807 of yacc.c  */
 #line 397 "parse-gram.y"
     {
       union_seen = true;
@@ -2554,14 +2555,14 @@ yyreduce:
 
   case 47:
 
-/* Line 1806 of yacc.c  */
+/* Line 1807 of yacc.c  */
 #line 408 "parse-gram.y"
     { current_class = nterm_sym; }
     break;
 
   case 48:
 
-/* Line 1806 of yacc.c  */
+/* Line 1807 of yacc.c  */
 #line 409 "parse-gram.y"
     {
       current_class = unknown_sym;
@@ -2571,14 +2572,14 @@ yyreduce:
 
   case 49:
 
-/* Line 1806 of yacc.c  */
+/* Line 1807 of yacc.c  */
 #line 413 "parse-gram.y"
     { current_class = token_sym; }
     break;
 
   case 50:
 
-/* Line 1806 of yacc.c  */
+/* Line 1807 of yacc.c  */
 #line 414 "parse-gram.y"
     {
       current_class = unknown_sym;
@@ -2588,7 +2589,7 @@ yyreduce:
 
   case 51:
 
-/* Line 1806 of yacc.c  */
+/* Line 1807 of yacc.c  */
 #line 419 "parse-gram.y"
     {
       symbol_list *list;
@@ -2601,7 +2602,7 @@ yyreduce:
 
   case 52:
 
-/* Line 1806 of yacc.c  */
+/* Line 1807 of yacc.c  */
 #line 430 "parse-gram.y"
     {
       symbol_list *list;
@@ -2618,126 +2619,126 @@ yyreduce:
 
   case 53:
 
-/* Line 1806 of yacc.c  */
+/* Line 1807 of yacc.c  */
 #line 444 "parse-gram.y"
     { (yyval.assoc) = left_assoc; }
     break;
 
   case 54:
 
-/* Line 1806 of yacc.c  */
+/* Line 1807 of yacc.c  */
 #line 445 "parse-gram.y"
     { (yyval.assoc) = right_assoc; }
     break;
 
   case 55:
 
-/* Line 1806 of yacc.c  */
+/* Line 1807 of yacc.c  */
 #line 446 "parse-gram.y"
     { (yyval.assoc) = non_assoc; }
     break;
 
   case 56:
 
-/* Line 1806 of yacc.c  */
+/* Line 1807 of yacc.c  */
 #line 450 "parse-gram.y"
     { current_type = NULL; }
     break;
 
   case 57:
 
-/* Line 1806 of yacc.c  */
+/* Line 1807 of yacc.c  */
 #line 451 "parse-gram.y"
     { current_type = (yyvsp[(1) - (1)].uniqstr); tag_seen = true; }
     break;
 
   case 58:
 
-/* Line 1806 of yacc.c  */
+/* Line 1807 of yacc.c  */
 #line 457 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 59:
 
-/* Line 1806 of yacc.c  */
+/* Line 1807 of yacc.c  */
 #line 459 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), symbol_list_sym_new ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]))); }
     break;
 
   case 60:
 
-/* Line 1806 of yacc.c  */
+/* Line 1807 of yacc.c  */
 #line 463 "parse-gram.y"
     { (yyval.symbol) = (yyvsp[(1) - (1)].symbol); }
     break;
 
   case 61:
 
-/* Line 1806 of yacc.c  */
+/* Line 1807 of yacc.c  */
 #line 464 "parse-gram.y"
     { (yyval.symbol) = (yyvsp[(1) - (2)].symbol); symbol_user_token_number_set ((yyvsp[(1) - (2)].symbol), (yyvsp[(2) - (2)].integer), (yylsp[(2) - (2)])); }
     break;
 
   case 62:
 
-/* Line 1806 of yacc.c  */
+/* Line 1807 of yacc.c  */
 #line 470 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 63:
 
-/* Line 1806 of yacc.c  */
+/* Line 1807 of yacc.c  */
 #line 472 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), symbol_list_sym_new ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]))); }
     break;
 
   case 64:
 
-/* Line 1806 of yacc.c  */
+/* Line 1807 of yacc.c  */
 #line 476 "parse-gram.y"
     { (yyval.list) = (yyvsp[(1) - (1)].list); }
     break;
 
   case 65:
 
-/* Line 1806 of yacc.c  */
+/* Line 1807 of yacc.c  */
 #line 477 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), (yyvsp[(2) - (2)].list)); }
     break;
 
   case 66:
 
-/* Line 1806 of yacc.c  */
+/* Line 1807 of yacc.c  */
 #line 481 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 67:
 
-/* Line 1806 of yacc.c  */
+/* Line 1807 of yacc.c  */
 #line 482 "parse-gram.y"
     { (yyval.list) = symbol_list_type_new ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 68:
 
-/* Line 1806 of yacc.c  */
+/* Line 1807 of yacc.c  */
 #line 483 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagged_new ((yylsp[(1) - (1)])); }
     break;
 
   case 69:
 
-/* Line 1806 of yacc.c  */
+/* Line 1807 of yacc.c  */
 #line 484 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagless_new ((yylsp[(1) - (1)])); }
     break;
 
   case 70:
 
-/* Line 1806 of yacc.c  */
+/* Line 1807 of yacc.c  */
 #line 490 "parse-gram.y"
     {
        current_type = (yyvsp[(1) - (1)].uniqstr);
@@ -2747,7 +2748,7 @@ yyreduce:
 
   case 71:
 
-/* Line 1806 of yacc.c  */
+/* Line 1807 of yacc.c  */
 #line 495 "parse-gram.y"
     {
        symbol_class_set ((yyvsp[(1) - (1)].symbol), current_class, (yylsp[(1) - (1)]), true);
@@ -2757,7 +2758,7 @@ yyreduce:
 
   case 72:
 
-/* Line 1806 of yacc.c  */
+/* Line 1807 of yacc.c  */
 #line 500 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
@@ -2768,7 +2769,7 @@ yyreduce:
 
   case 73:
 
-/* Line 1806 of yacc.c  */
+/* Line 1807 of yacc.c  */
 #line 506 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
@@ -2779,7 +2780,7 @@ yyreduce:
 
   case 74:
 
-/* Line 1806 of yacc.c  */
+/* Line 1807 of yacc.c  */
 #line 512 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (3)].symbol), current_class, (yylsp[(1) - (3)]), true);
@@ -2791,7 +2792,7 @@ yyreduce:
 
   case 81:
 
-/* Line 1806 of yacc.c  */
+/* Line 1807 of yacc.c  */
 #line 542 "parse-gram.y"
     {
       yyerrok;
@@ -2800,14 +2801,14 @@ yyreduce:
 
   case 82:
 
-/* Line 1806 of yacc.c  */
+/* Line 1807 of yacc.c  */
 #line 548 "parse-gram.y"
     { current_lhs ((yyvsp[(1) - (2)].symbol), (yylsp[(1) - (2)]), (yyvsp[(2) - (2)].named_ref)); }
     break;
 
   case 83:
 
-/* Line 1806 of yacc.c  */
+/* Line 1807 of yacc.c  */
 #line 549 "parse-gram.y"
     {
     /* Free the current lhs. */
@@ -2817,21 +2818,21 @@ yyreduce:
 
   case 84:
 
-/* Line 1806 of yacc.c  */
+/* Line 1807 of yacc.c  */
 #line 556 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(1) - (1)])); }
     break;
 
   case 85:
 
-/* Line 1806 of yacc.c  */
+/* Line 1807 of yacc.c  */
 #line 557 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(3) - (3)])); }
     break;
 
   case 87:
 
-/* Line 1806 of yacc.c  */
+/* Line 1807 of yacc.c  */
 #line 563 "parse-gram.y"
     { grammar_current_rule_begin (current_lhs_symbol, current_lhs_location,
 				  current_lhs_named_ref); }
@@ -2839,77 +2840,77 @@ yyreduce:
 
   case 88:
 
-/* Line 1806 of yacc.c  */
+/* Line 1807 of yacc.c  */
 #line 566 "parse-gram.y"
     { grammar_current_rule_symbol_append ((yyvsp[(2) - (3)].symbol), (yylsp[(2) - (3)]), (yyvsp[(3) - (3)].named_ref)); }
     break;
 
   case 89:
 
-/* Line 1806 of yacc.c  */
+/* Line 1807 of yacc.c  */
 #line 568 "parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[(2) - (3)].code), (yylsp[(2) - (3)]), (yyvsp[(3) - (3)].named_ref)); }
     break;
 
   case 90:
 
-/* Line 1806 of yacc.c  */
+/* Line 1807 of yacc.c  */
 #line 570 "parse-gram.y"
     { grammar_current_rule_prec_set ((yyvsp[(3) - (3)].symbol), (yylsp[(3) - (3)])); }
     break;
 
   case 91:
 
-/* Line 1806 of yacc.c  */
+/* Line 1807 of yacc.c  */
 #line 572 "parse-gram.y"
     { grammar_current_rule_dprec_set ((yyvsp[(3) - (3)].integer), (yylsp[(3) - (3)])); }
     break;
 
   case 92:
 
-/* Line 1806 of yacc.c  */
+/* Line 1807 of yacc.c  */
 #line 574 "parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[(3) - (3)].uniqstr), (yylsp[(3) - (3)])); }
     break;
 
   case 93:
 
-/* Line 1806 of yacc.c  */
+/* Line 1807 of yacc.c  */
 #line 578 "parse-gram.y"
     { (yyval.named_ref) = 0; }
     break;
 
   case 94:
 
-/* Line 1806 of yacc.c  */
+/* Line 1807 of yacc.c  */
 #line 580 "parse-gram.y"
     { (yyval.named_ref) = named_ref_new((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 96:
 
-/* Line 1806 of yacc.c  */
+/* Line 1807 of yacc.c  */
 #line 592 "parse-gram.y"
     { (yyval.uniqstr) = uniqstr_new ((yyvsp[(1) - (1)].chars)); }
     break;
 
   case 97:
 
-/* Line 1806 of yacc.c  */
+/* Line 1807 of yacc.c  */
 #line 597 "parse-gram.y"
     { (yyval.chars) = ""; }
     break;
 
   case 98:
 
-/* Line 1806 of yacc.c  */
+/* Line 1807 of yacc.c  */
 #line 598 "parse-gram.y"
     { (yyval.chars) = (yyvsp[(1) - (1)].uniqstr); }
     break;
 
   case 100:
 
-/* Line 1806 of yacc.c  */
+/* Line 1807 of yacc.c  */
 #line 609 "parse-gram.y"
     {
       code_props plain_code;
@@ -2923,14 +2924,14 @@ yyreduce:
 
   case 101:
 
-/* Line 1806 of yacc.c  */
+/* Line 1807 of yacc.c  */
 #line 629 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 102:
 
-/* Line 1806 of yacc.c  */
+/* Line 1807 of yacc.c  */
 #line 631 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[(1) - (1)].character)), (yylsp[(1) - (1)]));
@@ -2941,14 +2942,14 @@ yyreduce:
 
   case 103:
 
-/* Line 1806 of yacc.c  */
+/* Line 1807 of yacc.c  */
 #line 639 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 106:
 
-/* Line 1806 of yacc.c  */
+/* Line 1807 of yacc.c  */
 #line 651 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[(1) - (1)].chars)), (yylsp[(1) - (1)]));
@@ -2958,7 +2959,7 @@ yyreduce:
 
   case 108:
 
-/* Line 1806 of yacc.c  */
+/* Line 1807 of yacc.c  */
 #line 660 "parse-gram.y"
     {
       code_props plain_code;
@@ -2972,8 +2973,8 @@ yyreduce:
 
 
 
-/* Line 1806 of yacc.c  */
-#line 2977 "parse-gram.c"
+/* Line 1807 of yacc.c  */
+#line 2978 "../../../src/parse-gram.c"
         default: break;
       }
     if (yychar_backup != yychar)
@@ -3222,7 +3223,7 @@ yyreturn:
 
 
 
-/* Line 2067 of yacc.c  */
+/* Line 2068 of yacc.c  */
 #line 670 "parse-gram.y"
 
 
@@ -3315,8 +3316,8 @@ version_check (location const *loc, char const *version)
   if (strverscmp (version, PACKAGE_VERSION) > 0)
     {
       complain_at (*loc, "require bison %s, but have %s",
-		   version, PACKAGE_VERSION);
-      exit (63);
+                   version, PACKAGE_VERSION);
+      exit (EX_CONFIG);
     }
 }
 
