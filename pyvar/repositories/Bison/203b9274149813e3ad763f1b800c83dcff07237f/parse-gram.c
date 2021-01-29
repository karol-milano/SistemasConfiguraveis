@@ -184,7 +184,7 @@
 
 
 /* Copy the first part of user declarations.  */
-#line 1 "parse-gram.y"
+#line 1 "../../src/parse-gram.y"
 /* Bison Grammar Parser                             -*- C -*-
 
    Copyright (C) 2002, 2003, 2004, 2005, 2006 Free Software Foundation, Inc.
@@ -282,7 +282,7 @@ static int current_prec = 0;
 
 #if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
 typedef union YYSTYPE
-#line 97 "parse-gram.y"
+#line 97 "../../src/parse-gram.y"
 {
   symbol *symbol;
   symbol_list *list;
@@ -293,7 +293,7 @@ typedef union YYSTYPE
   unsigned char character;
 }
 /* Line 193 of yacc.c.  */
-#line 297 "parse-gram.c"
+#line 297 "../../src/parse-gram.c"
 	YYSTYPE;
 # define yystype YYSTYPE /* obsolescent; will be withdrawn */
 # define YYSTYPE_IS_DECLARED 1
@@ -318,7 +318,7 @@ typedef struct YYLTYPE
 
 
 /* Line 216 of yacc.c.  */
-#line 322 "parse-gram.c"
+#line 322 "../../src/parse-gram.c"
 
 #ifdef short
 # undef short
@@ -976,74 +976,74 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
   switch (yytype)
     {
       case 3: /* "\"string\"" */
-#line 177 "parse-gram.y"
+#line 177 "../../src/parse-gram.y"
 	{ fputs (quotearg_style (c_quoting_style, (yyvaluep->chars)), stderr); };
-#line 982 "parse-gram.c"
+#line 982 "../../src/parse-gram.c"
 	break;
       case 4: /* "\"integer\"" */
-#line 187 "parse-gram.y"
+#line 187 "../../src/parse-gram.y"
 	{ fprintf (stderr, "%d", (yyvaluep->integer)); };
-#line 987 "parse-gram.c"
+#line 987 "../../src/parse-gram.c"
 	break;
       case 41: /* "\"{...}\"" */
-#line 179 "parse-gram.y"
+#line 179 "../../src/parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 992 "parse-gram.c"
+#line 992 "../../src/parse-gram.c"
 	break;
       case 42: /* "\"char\"" */
-#line 174 "parse-gram.y"
+#line 174 "../../src/parse-gram.y"
 	{ fputs (char_name ((yyvaluep->character)), stderr); };
-#line 997 "parse-gram.c"
+#line 997 "../../src/parse-gram.c"
 	break;
       case 43: /* "\"epilogue\"" */
-#line 179 "parse-gram.y"
+#line 179 "../../src/parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1002 "parse-gram.c"
+#line 1002 "../../src/parse-gram.c"
 	break;
       case 45: /* "\"identifier\"" */
-#line 183 "parse-gram.y"
+#line 183 "../../src/parse-gram.y"
 	{ fputs ((yyvaluep->uniqstr), stderr); };
-#line 1007 "parse-gram.c"
+#line 1007 "../../src/parse-gram.c"
 	break;
       case 46: /* "\"identifier:\"" */
-#line 184 "parse-gram.y"
+#line 184 "../../src/parse-gram.y"
 	{ fprintf (stderr, "%s:", (yyvaluep->uniqstr)); };
-#line 1012 "parse-gram.c"
+#line 1012 "../../src/parse-gram.c"
 	break;
       case 49: /* "\"%{...%}\"" */
-#line 179 "parse-gram.y"
+#line 179 "../../src/parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1017 "parse-gram.c"
+#line 1017 "../../src/parse-gram.c"
 	break;
       case 51: /* "\"type\"" */
-#line 182 "parse-gram.y"
+#line 182 "../../src/parse-gram.y"
 	{ fprintf (stderr, "<%s>", (yyvaluep->uniqstr)); };
-#line 1022 "parse-gram.c"
+#line 1022 "../../src/parse-gram.c"
 	break;
       case 74: /* "id" */
-#line 190 "parse-gram.y"
+#line 190 "../../src/parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
-#line 1027 "parse-gram.c"
+#line 1027 "../../src/parse-gram.c"
 	break;
       case 75: /* "id_colon" */
-#line 191 "parse-gram.y"
+#line 191 "../../src/parse-gram.y"
 	{ fprintf (stderr, "%s:", (yyvaluep->symbol)->tag); };
-#line 1032 "parse-gram.c"
+#line 1032 "../../src/parse-gram.c"
 	break;
       case 76: /* "symbol" */
-#line 190 "parse-gram.y"
+#line 190 "../../src/parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
-#line 1037 "parse-gram.c"
+#line 1037 "../../src/parse-gram.c"
 	break;
       case 77: /* "string_as_id" */
-#line 190 "parse-gram.y"
+#line 190 "../../src/parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
-#line 1042 "parse-gram.c"
+#line 1042 "../../src/parse-gram.c"
 	break;
       case 78: /* "string_content" */
-#line 177 "parse-gram.y"
+#line 177 "../../src/parse-gram.y"
 	{ fputs (quotearg_style (c_quoting_style, (yyvaluep->chars)), stderr); };
-#line 1047 "parse-gram.c"
+#line 1047 "../../src/parse-gram.c"
 	break;
       default:
 	break;
@@ -1467,15 +1467,15 @@ yyparse ()
 #endif
 #endif
 {
-  /* The lookahead symbol.  */
+  /* The look-ahead symbol.  */
 int yychar;
 
-/* The semantic value of the lookahead symbol.  */
+/* The semantic value of the look-ahead symbol.  */
 YYSTYPE yylval;
 
 /* Number of syntax errors so far.  */
 int yynerrs;
-/* Location data for the lookahead symbol.  */
+/* Location data for the look-ahead symbol.  */
 YYLTYPE yylloc;
 
   int yystate;
@@ -1483,7 +1483,7 @@ YYLTYPE yylloc;
   int yyresult;
   /* Number of tokens to shift before error messages enabled.  */
   int yyerrstatus;
-  /* Lookahead token as an internal (translated) token number.  */
+  /* Look-ahead token as an internal (translated) token number.  */
   int yytoken = 0;
 #if YYERROR_VERBOSE
   /* Buffer for error messages, and its allocated size.  */
@@ -1553,7 +1553,7 @@ YYLTYPE yylloc;
 
 
   /* User initialization code.  */
-#line 88 "parse-gram.y"
+#line 88 "../../src/parse-gram.y"
 {
   /* Bison's grammar can initial empty locations, hence a default
      location is needed. */
@@ -1561,7 +1561,7 @@ YYLTYPE yylloc;
   boundary_set (&yylloc.end, current_file, 1, 0);
 }
 /* Line 1078 of yacc.c.  */
-#line 1565 "parse-gram.c"
+#line 1565 "../../src/parse-gram.c"
   yylsp[0] = yylloc;
   goto yysetstate;
 
@@ -1651,16 +1651,16 @@ YYLTYPE yylloc;
 yybackup:
 
   /* Do appropriate processing given the current state.  Read a
-     lookahead token if we need one and don't already have one.  */
+     look-ahead token if we need one and don't already have one.  */
 
-  /* First try to decide what to do without reference to lookahead token.  */
+  /* First try to decide what to do without reference to look-ahead token.  */
   yyn = yypact[yystate];
   if (yyn == YYPACT_NINF)
     goto yydefault;
 
-  /* Not known => get a lookahead token if don't already have one.  */
+  /* Not known => get a look-ahead token if don't already have one.  */
 
-  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
+  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
   if (yychar == YYEMPTY)
     {
       YYDPRINTF ((stderr, "Reading a token: "));
@@ -1700,7 +1700,7 @@ yybackup:
   if (yyerrstatus)
     yyerrstatus--;
 
-  /* Shift the lookahead token.  */
+  /* Shift the look-ahead token.  */
   YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
 
   /* Discard the shifted token unless it is eof.  */
@@ -1746,18 +1746,18 @@ yyreduce:
   switch (yyn)
     {
         case 6:
-#line 213 "parse-gram.y"
+#line 213 "../../src/parse-gram.y"
     { prologue_augment (translate_code ((yyvsp[(1) - (1)].chars), (yylsp[(1) - (1)])),
 						       (yylsp[(1) - (1)])); }
     break;
 
   case 7:
-#line 215 "parse-gram.y"
+#line 215 "../../src/parse-gram.y"
     { debug_flag = true; }
     break;
 
   case 8:
-#line 217 "parse-gram.y"
+#line 217 "../../src/parse-gram.y"
     {
       static char one[] = "1";
       muscle_insert ((yyvsp[(2) - (2)].chars), one);
@@ -1765,37 +1765,37 @@ yyreduce:
     break;
 
   case 9:
-#line 221 "parse-gram.y"
+#line 221 "../../src/parse-gram.y"
     { muscle_insert ((yyvsp[(2) - (3)].chars), (yyvsp[(3) - (3)].chars)); }
     break;
 
   case 10:
-#line 222 "parse-gram.y"
+#line 222 "../../src/parse-gram.y"
     { defines_flag = true; }
     break;
 
   case 11:
-#line 223 "parse-gram.y"
+#line 223 "../../src/parse-gram.y"
     { error_verbose = true; }
     break;
 
   case 12:
-#line 224 "parse-gram.y"
+#line 224 "../../src/parse-gram.y"
     { expected_sr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 13:
-#line 225 "parse-gram.y"
+#line 225 "../../src/parse-gram.y"
     { expected_rr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 14:
-#line 226 "parse-gram.y"
+#line 226 "../../src/parse-gram.y"
     { spec_file_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 15:
-#line 228 "parse-gram.y"
+#line 228 "../../src/parse-gram.y"
     {
       nondeterministic_parser = true;
       glr_parser = true;
@@ -1803,86 +1803,86 @@ yyreduce:
     break;
 
   case 16:
-#line 233 "parse-gram.y"
+#line 233 "../../src/parse-gram.y"
     {
       muscle_code_grow ("initial_action", translate_symbol_action ((yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])), (yylsp[(2) - (2)]));
     }
     break;
 
   case 17:
-#line 236 "parse-gram.y"
+#line 236 "../../src/parse-gram.y"
     { add_param ("lex_param", (yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])); }
     break;
 
   case 18:
-#line 237 "parse-gram.y"
+#line 237 "../../src/parse-gram.y"
     { locations_flag = true; }
     break;
 
   case 19:
-#line 238 "parse-gram.y"
+#line 238 "../../src/parse-gram.y"
     { spec_name_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 20:
-#line 239 "parse-gram.y"
+#line 239 "../../src/parse-gram.y"
     { no_lines_flag = true; }
     break;
 
   case 21:
-#line 240 "parse-gram.y"
+#line 240 "../../src/parse-gram.y"
     { nondeterministic_parser = true; }
     break;
 
   case 22:
-#line 241 "parse-gram.y"
+#line 241 "../../src/parse-gram.y"
     { spec_outfile = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 23:
-#line 242 "parse-gram.y"
+#line 242 "../../src/parse-gram.y"
     { add_param ("parse_param", (yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])); }
     break;
 
   case 24:
-#line 243 "parse-gram.y"
+#line 243 "../../src/parse-gram.y"
     { pure_parser = true; }
     break;
 
   case 25:
-#line 244 "parse-gram.y"
+#line 244 "../../src/parse-gram.y"
     { version_check (&(yylsp[(2) - (2)]), (yyvsp[(2) - (2)].chars)); }
     break;
 
   case 26:
-#line 245 "parse-gram.y"
+#line 245 "../../src/parse-gram.y"
     { skeleton = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 27:
-#line 246 "parse-gram.y"
+#line 246 "../../src/parse-gram.y"
     { token_table_flag = true; }
     break;
 
   case 28:
-#line 247 "parse-gram.y"
+#line 247 "../../src/parse-gram.y"
     { report_flag = report_states; }
     break;
 
   case 29:
-#line 248 "parse-gram.y"
+#line 248 "../../src/parse-gram.y"
     { yacc_flag = true; }
     break;
 
   case 33:
-#line 256 "parse-gram.y"
+#line 256 "../../src/parse-gram.y"
     {
       grammar_start_symbol_set ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]));
     }
     break;
 
   case 34:
-#line 260 "parse-gram.y"
+#line 260 "../../src/parse-gram.y"
     {
       symbol_list *list;
       const char *action = translate_symbol_action ((yyvsp[(2) - (3)].chars), (yylsp[(2) - (3)]));
@@ -1893,7 +1893,7 @@ yyreduce:
     break;
 
   case 35:
-#line 268 "parse-gram.y"
+#line 268 "../../src/parse-gram.y"
     {
       symbol_list *list;
       const char *action = translate_symbol_action ((yyvsp[(2) - (3)].chars), (yylsp[(2) - (3)]));
@@ -1904,31 +1904,31 @@ yyreduce:
     break;
 
   case 36:
-#line 276 "parse-gram.y"
+#line 276 "../../src/parse-gram.y"
     {
       default_prec = true;
     }
     break;
 
   case 37:
-#line 280 "parse-gram.y"
+#line 280 "../../src/parse-gram.y"
     {
       default_prec = false;
     }
     break;
 
   case 38:
-#line 293 "parse-gram.y"
+#line 293 "../../src/parse-gram.y"
     {}
     break;
 
   case 39:
-#line 294 "parse-gram.y"
+#line 294 "../../src/parse-gram.y"
     { muscle_code_grow ("union_name", (yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 40:
-#line 299 "parse-gram.y"
+#line 299 "../../src/parse-gram.y"
     {
       char const *body = (yyvsp[(3) - (3)].chars);
 
@@ -1947,12 +1947,12 @@ yyreduce:
     break;
 
   case 41:
-#line 320 "parse-gram.y"
+#line 320 "../../src/parse-gram.y"
     { current_class = nterm_sym; }
     break;
 
   case 42:
-#line 321 "parse-gram.y"
+#line 321 "../../src/parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
@@ -1960,12 +1960,12 @@ yyreduce:
     break;
 
   case 43:
-#line 325 "parse-gram.y"
+#line 325 "../../src/parse-gram.y"
     { current_class = token_sym; }
     break;
 
   case 44:
-#line 326 "parse-gram.y"
+#line 326 "../../src/parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
@@ -1973,7 +1973,7 @@ yyreduce:
     break;
 
   case 45:
-#line 331 "parse-gram.y"
+#line 331 "../../src/parse-gram.y"
     {
       symbol_list *list;
       for (list = (yyvsp[(3) - (3)].list); list; list = list->next)
@@ -1983,7 +1983,7 @@ yyreduce:
     break;
 
   case 46:
-#line 341 "parse-gram.y"
+#line 341 "../../src/parse-gram.y"
     {
       symbol_list *list;
       ++current_prec;
@@ -1998,49 +1998,49 @@ yyreduce:
     break;
 
   case 47:
-#line 355 "parse-gram.y"
+#line 355 "../../src/parse-gram.y"
     { (yyval.assoc) = left_assoc; }
     break;
 
   case 48:
-#line 356 "parse-gram.y"
+#line 356 "../../src/parse-gram.y"
     { (yyval.assoc) = right_assoc; }
     break;
 
   case 49:
-#line 357 "parse-gram.y"
+#line 357 "../../src/parse-gram.y"
     { (yyval.assoc) = non_assoc; }
     break;
 
   case 50:
-#line 361 "parse-gram.y"
+#line 361 "../../src/parse-gram.y"
     { current_type = NULL; }
     break;
 
   case 51:
-#line 362 "parse-gram.y"
+#line 362 "../../src/parse-gram.y"
     { current_type = (yyvsp[(1) - (1)].uniqstr); }
     break;
 
   case 52:
-#line 367 "parse-gram.y"
+#line 367 "../../src/parse-gram.y"
     { (yyval.list) = symbol_list_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 53:
-#line 368 "parse-gram.y"
+#line 368 "../../src/parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), (yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)])); }
     break;
 
   case 54:
-#line 374 "parse-gram.y"
+#line 374 "../../src/parse-gram.y"
     {
        current_type = (yyvsp[(1) - (1)].uniqstr);
      }
     break;
 
   case 55:
-#line 378 "parse-gram.y"
+#line 378 "../../src/parse-gram.y"
     {
        symbol_class_set ((yyvsp[(1) - (1)].symbol), current_class, (yylsp[(1) - (1)]), true);
        symbol_type_set ((yyvsp[(1) - (1)].symbol), current_type, (yylsp[(1) - (1)]));
@@ -2048,7 +2048,7 @@ yyreduce:
     break;
 
   case 56:
-#line 383 "parse-gram.y"
+#line 383 "../../src/parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
       symbol_type_set ((yyvsp[(1) - (2)].symbol), current_type, (yylsp[(1) - (2)]));
@@ -2057,7 +2057,7 @@ yyreduce:
     break;
 
   case 57:
-#line 389 "parse-gram.y"
+#line 389 "../../src/parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
       symbol_type_set ((yyvsp[(1) - (2)].symbol), current_type, (yylsp[(1) - (2)]));
@@ -2066,7 +2066,7 @@ yyreduce:
     break;
 
   case 58:
-#line 395 "parse-gram.y"
+#line 395 "../../src/parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (3)].symbol), current_class, (yylsp[(1) - (3)]), true);
       symbol_type_set ((yyvsp[(1) - (3)].symbol), current_type, (yylsp[(1) - (3)]));
@@ -2076,65 +2076,65 @@ yyreduce:
     break;
 
   case 65:
-#line 425 "parse-gram.y"
+#line 425 "../../src/parse-gram.y"
     {
       yyerrok;
     }
     break;
 
   case 66:
-#line 431 "parse-gram.y"
+#line 431 "../../src/parse-gram.y"
     { current_lhs = (yyvsp[(1) - (1)].symbol); current_lhs_location = (yylsp[(1) - (1)]); }
     break;
 
   case 68:
-#line 435 "parse-gram.y"
+#line 435 "../../src/parse-gram.y"
     { grammar_current_rule_end ((yylsp[(1) - (1)])); }
     break;
 
   case 69:
-#line 436 "parse-gram.y"
+#line 436 "../../src/parse-gram.y"
     { grammar_current_rule_end ((yylsp[(3) - (3)])); }
     break;
 
   case 71:
-#line 442 "parse-gram.y"
+#line 442 "../../src/parse-gram.y"
     { grammar_current_rule_begin (current_lhs, current_lhs_location); }
     break;
 
   case 72:
-#line 444 "parse-gram.y"
+#line 444 "../../src/parse-gram.y"
     { grammar_current_rule_symbol_append ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)])); }
     break;
 
   case 73:
-#line 446 "parse-gram.y"
+#line 446 "../../src/parse-gram.y"
     { grammar_current_rule_action_append (gram_last_string,
 					  gram_last_braced_code_loc); }
     break;
 
   case 74:
-#line 449 "parse-gram.y"
+#line 449 "../../src/parse-gram.y"
     { grammar_current_rule_prec_set ((yyvsp[(3) - (3)].symbol), (yylsp[(3) - (3)])); }
     break;
 
   case 75:
-#line 451 "parse-gram.y"
+#line 451 "../../src/parse-gram.y"
     { grammar_current_rule_dprec_set ((yyvsp[(3) - (3)].integer), (yylsp[(3) - (3)])); }
     break;
 
   case 76:
-#line 453 "parse-gram.y"
+#line 453 "../../src/parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[(3) - (3)].uniqstr), (yylsp[(3) - (3)])); }
     break;
 
   case 77:
-#line 466 "parse-gram.y"
-    { (yyval.symbol) = symbol_get ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
+#line 466 "../../src/parse-gram.y"
+    { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 78:
-#line 468 "parse-gram.y"
+#line 468 "../../src/parse-gram.y"
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[(1) - (1)].character)), (yylsp[(1) - (1)]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[(1) - (1)]), false);
@@ -2143,12 +2143,12 @@ yyreduce:
     break;
 
   case 79:
-#line 476 "parse-gram.y"
-    { (yyval.symbol) = symbol_get ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
+#line 476 "../../src/parse-gram.y"
+    { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 82:
-#line 488 "parse-gram.y"
+#line 488 "../../src/parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[(1) - (1)].chars)), (yylsp[(1) - (1)]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[(1) - (1)]), false);
@@ -2156,12 +2156,12 @@ yyreduce:
     break;
 
   case 83:
-#line 497 "parse-gram.y"
+#line 497 "../../src/parse-gram.y"
     { (yyval.chars) = (yyvsp[(1) - (1)].chars); }
     break;
 
   case 85:
-#line 504 "parse-gram.y"
+#line 504 "../../src/parse-gram.y"
     {
       muscle_code_grow ("epilogue", translate_code ((yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])), (yylsp[(2) - (2)]));
       gram_scanner_last_string_free ();
@@ -2170,7 +2170,7 @@ yyreduce:
 
 
 /* Line 1267 of yacc.c.  */
-#line 2174 "parse-gram.c"
+#line 2174 "../../src/parse-gram.c"
       default: break;
     }
   YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);
@@ -2246,7 +2246,7 @@ yyerrlab:
 
   if (yyerrstatus == 3)
     {
-      /* If just tried and failed to reuse lookahead token after an
+      /* If just tried and failed to reuse look-ahead token after an
 	 error, discard it.  */
 
       if (yychar <= YYEOF)
@@ -2263,7 +2263,7 @@ yyerrlab:
 	}
     }
 
-  /* Else will try to reuse lookahead token after shifting the error
+  /* Else will try to reuse look-ahead token after shifting the error
      token.  */
   goto yyerrlab1;
 
@@ -2328,7 +2328,7 @@ yyerrlab1:
 
   yyerror_range[1] = yylloc;
   /* Using YYLLOC is tempting, but would change the location of
-     the lookahead.  YYLOC is available though.  */
+     the look-ahead.  YYLOC is available though.  */
   YYLLOC_DEFAULT (yyloc, (yyerror_range - 1), 2);
   *++yylsp = yyloc;
 
@@ -2390,7 +2390,7 @@ yyreturn:
 }
 
 
-#line 510 "parse-gram.y"
+#line 510 "../../src/parse-gram.y"
 
 
 
