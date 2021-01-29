@@ -69,7 +69,7 @@
 #define yylloc gram_lloc
 
 /* Copy the first part of user declarations.  */
-/* Line 164 of yacc.c.  */
+/* Line 173 of yacc.c.  */
 #line 1 "parse-gram.y"
 /* Bison Grammar Parser                             -*- C -*-
 
@@ -292,7 +292,7 @@ static int current_prec = 0;
 
 #if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
 typedef union YYSTYPE
-{/* Line 198 of yacc.c.  */
+{/* Line 207 of yacc.c.  */
 #line 97 "parse-gram.y"
 
   symbol *symbol;
@@ -303,7 +303,7 @@ typedef union YYSTYPE
   uniqstr uniqstr;
   unsigned char character;
 }
-/* Line 198 of yacc.c.  */
+/* Line 207 of yacc.c.  */
 #line 308 "parse-gram.c"
 	YYSTYPE;
 # define YYSTYPE_IS_TRIVIAL 1
@@ -327,7 +327,7 @@ typedef struct YYLTYPE
 
 /* Copy the second part of user declarations.  */
 
-/* Line 221 of yacc.c.  */
+/* Line 230 of yacc.c.  */
 #line 332 "parse-gram.c"
 
 #ifdef short
@@ -1006,115 +1006,115 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
   switch (yytype)
     {
       case 3: /* "\"string\"" */
-/* Line 670 of yacc.c.  */
+/* Line 679 of yacc.c.  */
 #line 183 "parse-gram.y"
 	{ fputs (quotearg_style (c_quoting_style, (yyvaluep->chars)), stderr); };
-/* Line 670 of yacc.c.  */
+/* Line 679 of yacc.c.  */
 #line 1014 "parse-gram.c"
 	break;
       case 4: /* "\"integer\"" */
-/* Line 670 of yacc.c.  */
+/* Line 679 of yacc.c.  */
 #line 194 "parse-gram.y"
 	{ fprintf (stderr, "%d", (yyvaluep->integer)); };
-/* Line 670 of yacc.c.  */
+/* Line 679 of yacc.c.  */
 #line 1021 "parse-gram.c"
 	break;
       case 45: /* "\"{...}\"" */
-/* Line 670 of yacc.c.  */
+/* Line 679 of yacc.c.  */
 #line 185 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-/* Line 670 of yacc.c.  */
+/* Line 679 of yacc.c.  */
 #line 1028 "parse-gram.c"
 	break;
       case 46: /* "\"char\"" */
-/* Line 670 of yacc.c.  */
+/* Line 679 of yacc.c.  */
 #line 178 "parse-gram.y"
 	{ fputs (char_name ((yyvaluep->character)), stderr); };
-/* Line 670 of yacc.c.  */
+/* Line 679 of yacc.c.  */
 #line 1035 "parse-gram.c"
 	break;
       case 47: /* "\"epilogue\"" */
-/* Line 670 of yacc.c.  */
+/* Line 679 of yacc.c.  */
 #line 185 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-/* Line 670 of yacc.c.  */
+/* Line 679 of yacc.c.  */
 #line 1042 "parse-gram.c"
 	break;
       case 49: /* "\"identifier\"" */
-/* Line 670 of yacc.c.  */
+/* Line 679 of yacc.c.  */
 #line 190 "parse-gram.y"
 	{ fputs ((yyvaluep->uniqstr), stderr); };
-/* Line 670 of yacc.c.  */
+/* Line 679 of yacc.c.  */
 #line 1049 "parse-gram.c"
 	break;
       case 50: /* "\"identifier:\"" */
-/* Line 670 of yacc.c.  */
+/* Line 679 of yacc.c.  */
 #line 191 "parse-gram.y"
 	{ fprintf (stderr, "%s:", (yyvaluep->uniqstr)); };
-/* Line 670 of yacc.c.  */
+/* Line 679 of yacc.c.  */
 #line 1056 "parse-gram.c"
 	break;
       case 53: /* "\"%{...%}\"" */
-/* Line 670 of yacc.c.  */
+/* Line 679 of yacc.c.  */
 #line 185 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-/* Line 670 of yacc.c.  */
+/* Line 679 of yacc.c.  */
 #line 1063 "parse-gram.c"
 	break;
       case 55: /* "\"type\"" */
-/* Line 670 of yacc.c.  */
+/* Line 679 of yacc.c.  */
 #line 189 "parse-gram.y"
 	{ fprintf (stderr, "<%s>", (yyvaluep->uniqstr)); };
-/* Line 670 of yacc.c.  */
+/* Line 679 of yacc.c.  */
 #line 1070 "parse-gram.c"
 	break;
       case 78: /* "content" */
-/* Line 670 of yacc.c.  */
+/* Line 679 of yacc.c.  */
 #line 185 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-/* Line 670 of yacc.c.  */
+/* Line 679 of yacc.c.  */
 #line 1077 "parse-gram.c"
 	break;
       case 79: /* "content.opt" */
-/* Line 670 of yacc.c.  */
+/* Line 679 of yacc.c.  */
 #line 185 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-/* Line 670 of yacc.c.  */
+/* Line 679 of yacc.c.  */
 #line 1084 "parse-gram.c"
 	break;
       case 80: /* "braceless" */
-/* Line 670 of yacc.c.  */
+/* Line 679 of yacc.c.  */
 #line 185 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-/* Line 670 of yacc.c.  */
+/* Line 679 of yacc.c.  */
 #line 1091 "parse-gram.c"
 	break;
       case 81: /* "id" */
-/* Line 670 of yacc.c.  */
+/* Line 679 of yacc.c.  */
 #line 197 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
-/* Line 670 of yacc.c.  */
+/* Line 679 of yacc.c.  */
 #line 1098 "parse-gram.c"
 	break;
       case 82: /* "id_colon" */
-/* Line 670 of yacc.c.  */
+/* Line 679 of yacc.c.  */
 #line 198 "parse-gram.y"
 	{ fprintf (stderr, "%s:", (yyvaluep->symbol)->tag); };
-/* Line 670 of yacc.c.  */
+/* Line 679 of yacc.c.  */
 #line 1105 "parse-gram.c"
 	break;
       case 83: /* "symbol" */
-/* Line 670 of yacc.c.  */
+/* Line 679 of yacc.c.  */
 #line 197 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
-/* Line 670 of yacc.c.  */
+/* Line 679 of yacc.c.  */
 #line 1112 "parse-gram.c"
 	break;
       case 84: /* "string_as_id" */
-/* Line 670 of yacc.c.  */
+/* Line 679 of yacc.c.  */
 #line 197 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
-/* Line 670 of yacc.c.  */
+/* Line 679 of yacc.c.  */
 #line 1119 "parse-gram.c"
 	break;
       default:
@@ -1409,7 +1409,7 @@ yysyntax_error (char *yyresult, int yystate, int yychar)
       yyfmt = yystpcpy (yyformat, yyunexpected);
 
       for (yyx = yyxbegin; yyx < yyxend; ++yyx)
-	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
+	if ((int)yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
 	  {
 	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
 	      {
@@ -1628,7 +1628,7 @@ YYLTYPE yylloc;
 
 
   /* User initialization code.  */
-  /* Line 1082 of yacc.c.  */
+  /* Line 1091 of yacc.c.  */
 #line 88 "parse-gram.y"
 {
   /* Bison's grammar can initial empty locations, hence a default
@@ -1636,7 +1636,7 @@ YYLTYPE yylloc;
   boundary_set (&yylloc.start, current_file, 1, 1);
   boundary_set (&yylloc.end, current_file, 1, 1);
 }
-/* Line 1082 of yacc.c.  */
+/* Line 1091 of yacc.c.  */
 #line 1641 "parse-gram.c"
   yylsp[0] = yylloc;
   goto yysetstate;
@@ -1760,7 +1760,7 @@ yybackup:
   /* If the proper action on seeing token YYTOKEN is to reduce or to
      detect an error, take that action.  */
   yyn += yytoken;
-  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
+  if (yyn < 0 || YYLAST < yyn || (int)yycheck[yyn] != yytoken)
     goto yydefault;
   yyn = yytable[yyn];
   if (yyn <= 0)
@@ -1821,73 +1821,73 @@ yyreduce:
   switch (yyn)
     {
         case 6:
-/* Line 1269 of yacc.c.  */
+/* Line 1278 of yacc.c.  */
 #line 220 "parse-gram.y"
     { prologue_augment (translate_code ((yyvsp[(1) - (1)].chars), (yylsp[(1) - (1)])), (yylsp[(1) - (1)]), union_seen); }
     break;
 
   case 7:
-/* Line 1269 of yacc.c.  */
+/* Line 1278 of yacc.c.  */
 #line 221 "parse-gram.y"
     { prologue_augment ((yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)]), true); }
     break;
 
   case 8:
-/* Line 1269 of yacc.c.  */
+/* Line 1278 of yacc.c.  */
 #line 222 "parse-gram.y"
     { prologue_augment ((yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)]), false); }
     break;
 
   case 9:
-/* Line 1269 of yacc.c.  */
+/* Line 1278 of yacc.c.  */
 #line 223 "parse-gram.y"
     { debug_flag = true; }
     break;
 
   case 10:
-/* Line 1269 of yacc.c.  */
+/* Line 1278 of yacc.c.  */
 #line 224 "parse-gram.y"
     { muscle_insert ((yyvsp[(2) - (3)].chars), (yyvsp[(3) - (3)].chars)); }
     break;
 
   case 11:
-/* Line 1269 of yacc.c.  */
+/* Line 1278 of yacc.c.  */
 #line 225 "parse-gram.y"
     { defines_flag = true; }
     break;
 
   case 12:
-/* Line 1269 of yacc.c.  */
+/* Line 1278 of yacc.c.  */
 #line 226 "parse-gram.y"
     { muscle_code_grow ("end_header", (yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])); }
     break;
 
   case 13:
-/* Line 1269 of yacc.c.  */
+/* Line 1278 of yacc.c.  */
 #line 227 "parse-gram.y"
     { error_verbose = true; }
     break;
 
   case 14:
-/* Line 1269 of yacc.c.  */
+/* Line 1278 of yacc.c.  */
 #line 228 "parse-gram.y"
     { expected_sr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 15:
-/* Line 1269 of yacc.c.  */
+/* Line 1278 of yacc.c.  */
 #line 229 "parse-gram.y"
     { expected_rr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 16:
-/* Line 1269 of yacc.c.  */
+/* Line 1278 of yacc.c.  */
 #line 230 "parse-gram.y"
     { spec_file_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 17:
-/* Line 1269 of yacc.c.  */
+/* Line 1278 of yacc.c.  */
 #line 232 "parse-gram.y"
     {
       nondeterministic_parser = true;
@@ -1896,7 +1896,7 @@ yyreduce:
     break;
 
   case 18:
-/* Line 1269 of yacc.c.  */
+/* Line 1278 of yacc.c.  */
 #line 237 "parse-gram.y"
     {
       muscle_code_grow ("initial_action", translate_symbol_action ((yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])), (yylsp[(2) - (2)]));
@@ -1904,91 +1904,91 @@ yyreduce:
     break;
 
   case 19:
-/* Line 1269 of yacc.c.  */
+/* Line 1278 of yacc.c.  */
 #line 240 "parse-gram.y"
     { add_param ("lex_param", (yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])); }
     break;
 
   case 20:
-/* Line 1269 of yacc.c.  */
+/* Line 1278 of yacc.c.  */
 #line 241 "parse-gram.y"
     { locations_flag = true; }
     break;
 
   case 21:
-/* Line 1269 of yacc.c.  */
+/* Line 1278 of yacc.c.  */
 #line 242 "parse-gram.y"
     { spec_name_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 22:
-/* Line 1269 of yacc.c.  */
+/* Line 1278 of yacc.c.  */
 #line 243 "parse-gram.y"
     { no_lines_flag = true; }
     break;
 
   case 23:
-/* Line 1269 of yacc.c.  */
+/* Line 1278 of yacc.c.  */
 #line 244 "parse-gram.y"
     { nondeterministic_parser = true; }
     break;
 
   case 24:
-/* Line 1269 of yacc.c.  */
+/* Line 1278 of yacc.c.  */
 #line 245 "parse-gram.y"
     { spec_outfile = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 25:
-/* Line 1269 of yacc.c.  */
+/* Line 1278 of yacc.c.  */
 #line 246 "parse-gram.y"
     { add_param ("parse_param", (yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])); }
     break;
 
   case 26:
-/* Line 1269 of yacc.c.  */
+/* Line 1278 of yacc.c.  */
 #line 247 "parse-gram.y"
     { pure_parser = true; }
     break;
 
   case 27:
-/* Line 1269 of yacc.c.  */
+/* Line 1278 of yacc.c.  */
 #line 248 "parse-gram.y"
     { version_check (&(yylsp[(2) - (2)]), (yyvsp[(2) - (2)].chars)); }
     break;
 
   case 28:
-/* Line 1269 of yacc.c.  */
+/* Line 1278 of yacc.c.  */
 #line 249 "parse-gram.y"
     { skeleton = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 29:
-/* Line 1269 of yacc.c.  */
+/* Line 1278 of yacc.c.  */
 #line 250 "parse-gram.y"
     { muscle_code_grow ("start_header", (yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])); }
     break;
 
   case 30:
-/* Line 1269 of yacc.c.  */
+/* Line 1278 of yacc.c.  */
 #line 251 "parse-gram.y"
     { token_table_flag = true; }
     break;
 
   case 31:
-/* Line 1269 of yacc.c.  */
+/* Line 1278 of yacc.c.  */
 #line 252 "parse-gram.y"
     { report_flag = report_states; }
     break;
 
   case 32:
-/* Line 1269 of yacc.c.  */
+/* Line 1278 of yacc.c.  */
 #line 253 "parse-gram.y"
     { yacc_flag = true; }
     break;
 
   case 36:
-/* Line 1269 of yacc.c.  */
+/* Line 1278 of yacc.c.  */
 #line 261 "parse-gram.y"
     {
       grammar_start_symbol_set ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]));
@@ -1996,7 +1996,7 @@ yyreduce:
     break;
 
   case 37:
-/* Line 1269 of yacc.c.  */
+/* Line 1278 of yacc.c.  */
 #line 265 "parse-gram.y"
     {
       default_destructor_set (translate_symbol_action ((yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])), (yylsp[(2) - (2)]));
@@ -2004,7 +2004,7 @@ yyreduce:
     break;
 
   case 38:
-/* Line 1269 of yacc.c.  */
+/* Line 1278 of yacc.c.  */
 #line 269 "parse-gram.y"
     {
       symbol_list *list;
@@ -2016,7 +2016,7 @@ yyreduce:
     break;
 
   case 39:
-/* Line 1269 of yacc.c.  */
+/* Line 1278 of yacc.c.  */
 #line 277 "parse-gram.y"
     {
       symbol_list *list;
@@ -2028,7 +2028,7 @@ yyreduce:
     break;
 
   case 40:
-/* Line 1269 of yacc.c.  */
+/* Line 1278 of yacc.c.  */
 #line 285 "parse-gram.y"
     {
       default_printer_set (translate_symbol_action ((yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])), (yylsp[(2) - (2)]));
@@ -2036,7 +2036,7 @@ yyreduce:
     break;
 
   case 41:
-/* Line 1269 of yacc.c.  */
+/* Line 1278 of yacc.c.  */
 #line 289 "parse-gram.y"
     {
       default_prec = true;
@@ -2044,7 +2044,7 @@ yyreduce:
     break;
 
   case 42:
-/* Line 1269 of yacc.c.  */
+/* Line 1278 of yacc.c.  */
 #line 293 "parse-gram.y"
     {
       default_prec = false;
@@ -2052,19 +2052,19 @@ yyreduce:
     break;
 
   case 43:
-/* Line 1269 of yacc.c.  */
+/* Line 1278 of yacc.c.  */
 #line 306 "parse-gram.y"
     {}
     break;
 
   case 44:
-/* Line 1269 of yacc.c.  */
+/* Line 1278 of yacc.c.  */
 #line 307 "parse-gram.y"
     { muscle_code_grow ("union_name", (yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 45:
-/* Line 1269 of yacc.c.  */
+/* Line 1278 of yacc.c.  */
 #line 312 "parse-gram.y"
     {
       char const *body = (yyvsp[(3) - (3)].chars);
@@ -2090,13 +2090,13 @@ yyreduce:
     break;
 
   case 46:
-/* Line 1269 of yacc.c.  */
+/* Line 1278 of yacc.c.  */
 #line 339 "parse-gram.y"
     { current_class = nterm_sym; }
     break;
 
   case 47:
-/* Line 1269 of yacc.c.  */
+/* Line 1278 of yacc.c.  */
 #line 340 "parse-gram.y"
     {
       current_class = unknown_sym;
@@ -2105,13 +2105,13 @@ yyreduce:
     break;
 
   case 48:
-/* Line 1269 of yacc.c.  */
+/* Line 1278 of yacc.c.  */
 #line 344 "parse-gram.y"
     { current_class = token_sym; }
     break;
 
   case 49:
-/* Line 1269 of yacc.c.  */
+/* Line 1278 of yacc.c.  */
 #line 345 "parse-gram.y"
     {
       current_class = unknown_sym;
@@ -2120,7 +2120,7 @@ yyreduce:
     break;
 
   case 50:
-/* Line 1269 of yacc.c.  */
+/* Line 1278 of yacc.c.  */
 #line 350 "parse-gram.y"
     {
       tag_seen = true;
@@ -2132,7 +2132,7 @@ yyreduce:
     break;
 
   case 51:
-/* Line 1269 of yacc.c.  */
+/* Line 1278 of yacc.c.  */
 #line 361 "parse-gram.y"
     {
       symbol_list *list;
@@ -2148,49 +2148,49 @@ yyreduce:
     break;
 
   case 52:
-/* Line 1269 of yacc.c.  */
+/* Line 1278 of yacc.c.  */
 #line 375 "parse-gram.y"
     { (yyval.assoc) = left_assoc; }
     break;
 
   case 53:
-/* Line 1269 of yacc.c.  */
+/* Line 1278 of yacc.c.  */
 #line 376 "parse-gram.y"
     { (yyval.assoc) = right_assoc; }
     break;
 
   case 54:
-/* Line 1269 of yacc.c.  */
+/* Line 1278 of yacc.c.  */
 #line 377 "parse-gram.y"
     { (yyval.assoc) = non_assoc; }
     break;
 
   case 55:
-/* Line 1269 of yacc.c.  */
+/* Line 1278 of yacc.c.  */
 #line 381 "parse-gram.y"
     { current_type = NULL; }
     break;
 
   case 56:
-/* Line 1269 of yacc.c.  */
+/* Line 1278 of yacc.c.  */
 #line 382 "parse-gram.y"
     { current_type = (yyvsp[(1) - (1)].uniqstr); tag_seen = true; }
     break;
 
   case 57:
-/* Line 1269 of yacc.c.  */
+/* Line 1278 of yacc.c.  */
 #line 387 "parse-gram.y"
     { (yyval.list) = symbol_list_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 58:
-/* Line 1269 of yacc.c.  */
+/* Line 1278 of yacc.c.  */
 #line 388 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), (yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)])); }
     break;
 
   case 59:
-/* Line 1269 of yacc.c.  */
+/* Line 1278 of yacc.c.  */
 #line 394 "parse-gram.y"
     {
        current_type = (yyvsp[(1) - (1)].uniqstr);
@@ -2199,7 +2199,7 @@ yyreduce:
     break;
 
   case 60:
-/* Line 1269 of yacc.c.  */
+/* Line 1278 of yacc.c.  */
 #line 399 "parse-gram.y"
     {
        symbol_class_set ((yyvsp[(1) - (1)].symbol), current_class, (yylsp[(1) - (1)]), true);
@@ -2208,7 +2208,7 @@ yyreduce:
     break;
 
   case 61:
-/* Line 1269 of yacc.c.  */
+/* Line 1278 of yacc.c.  */
 #line 404 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
@@ -2218,7 +2218,7 @@ yyreduce:
     break;
 
   case 62:
-/* Line 1269 of yacc.c.  */
+/* Line 1278 of yacc.c.  */
 #line 410 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
@@ -2228,7 +2228,7 @@ yyreduce:
     break;
 
   case 63:
-/* Line 1269 of yacc.c.  */
+/* Line 1278 of yacc.c.  */
 #line 416 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (3)].symbol), current_class, (yylsp[(1) - (3)]), true);
@@ -2239,7 +2239,7 @@ yyreduce:
     break;
 
   case 70:
-/* Line 1269 of yacc.c.  */
+/* Line 1278 of yacc.c.  */
 #line 446 "parse-gram.y"
     {
       yyerrok;
@@ -2247,61 +2247,61 @@ yyreduce:
     break;
 
   case 71:
-/* Line 1269 of yacc.c.  */
+/* Line 1278 of yacc.c.  */
 #line 452 "parse-gram.y"
     { current_lhs = (yyvsp[(1) - (1)].symbol); current_lhs_location = (yylsp[(1) - (1)]); }
     break;
 
   case 73:
-/* Line 1269 of yacc.c.  */
+/* Line 1278 of yacc.c.  */
 #line 456 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(1) - (1)])); }
     break;
 
   case 74:
-/* Line 1269 of yacc.c.  */
+/* Line 1278 of yacc.c.  */
 #line 457 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(3) - (3)])); }
     break;
 
   case 76:
-/* Line 1269 of yacc.c.  */
+/* Line 1278 of yacc.c.  */
 #line 463 "parse-gram.y"
     { grammar_current_rule_begin (current_lhs, current_lhs_location); }
     break;
 
   case 77:
-/* Line 1269 of yacc.c.  */
+/* Line 1278 of yacc.c.  */
 #line 465 "parse-gram.y"
     { grammar_current_rule_symbol_append ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)])); }
     break;
 
   case 78:
-/* Line 1269 of yacc.c.  */
+/* Line 1278 of yacc.c.  */
 #line 467 "parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])); }
     break;
 
   case 79:
-/* Line 1269 of yacc.c.  */
+/* Line 1278 of yacc.c.  */
 #line 469 "parse-gram.y"
     { grammar_current_rule_prec_set ((yyvsp[(3) - (3)].symbol), (yylsp[(3) - (3)])); }
     break;
 
   case 80:
-/* Line 1269 of yacc.c.  */
+/* Line 1278 of yacc.c.  */
 #line 471 "parse-gram.y"
     { grammar_current_rule_dprec_set ((yyvsp[(3) - (3)].integer), (yylsp[(3) - (3)])); }
     break;
 
   case 81:
-/* Line 1269 of yacc.c.  */
+/* Line 1278 of yacc.c.  */
 #line 473 "parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[(3) - (3)].uniqstr), (yylsp[(3) - (3)])); }
     break;
 
   case 84:
-/* Line 1269 of yacc.c.  */
+/* Line 1278 of yacc.c.  */
 #line 489 "parse-gram.y"
     {
       static char one[] = "1";
@@ -2310,7 +2310,7 @@ yyreduce:
     break;
 
   case 86:
-/* Line 1269 of yacc.c.  */
+/* Line 1278 of yacc.c.  */
 #line 499 "parse-gram.y"
     {
       (yyvsp[(1) - (1)].chars)[strlen ((yyvsp[(1) - (1)].chars)) - 1] = '\n';
@@ -2319,13 +2319,13 @@ yyreduce:
     break;
 
   case 87:
-/* Line 1269 of yacc.c.  */
+/* Line 1278 of yacc.c.  */
 #line 515 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 88:
-/* Line 1269 of yacc.c.  */
+/* Line 1278 of yacc.c.  */
 #line 517 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[(1) - (1)].character)), (yylsp[(1) - (1)]));
@@ -2335,13 +2335,13 @@ yyreduce:
     break;
 
   case 89:
-/* Line 1269 of yacc.c.  */
+/* Line 1278 of yacc.c.  */
 #line 525 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 92:
-/* Line 1269 of yacc.c.  */
+/* Line 1278 of yacc.c.  */
 #line 537 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[(1) - (1)].chars)), (yylsp[(1) - (1)]));
@@ -2350,7 +2350,7 @@ yyreduce:
     break;
 
   case 94:
-/* Line 1269 of yacc.c.  */
+/* Line 1278 of yacc.c.  */
 #line 546 "parse-gram.y"
     {
       muscle_code_grow ("epilogue", translate_code ((yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])), (yylsp[(2) - (2)]));
@@ -2359,7 +2359,7 @@ yyreduce:
     break;
 
 
-/* Line 1269 of yacc.c.  */
+/* Line 1278 of yacc.c.  */
 #line 2364 "parse-gram.c"
       default: break;
     }
@@ -2379,7 +2379,8 @@ yyreduce:
   yyn = yyr1[yyn];
 
   yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
-  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
+  if (0 <= yystate && yystate <= YYLAST
+      && (int)yycheck[yystate] == *yyssp)
     yystate = yytable[yystate];
   else
     yystate = yydefgoto[yyn - YYNTOKENS];
@@ -2577,7 +2578,7 @@ yyreturn:
 }
 
 
-/* Line 1486 of yacc.c.  */
+/* Line 1496 of yacc.c.  */
 #line 552 "parse-gram.y"
 
 
