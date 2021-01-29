@@ -207,7 +207,7 @@ do {							\
 static void yyprint (FILE *file, int type, const yystype *value);
 
 symbol_class current_class = unknown_sym;
-char *current_type = 0;
+struniq_t current_type = 0;
 symbol_t *current_lhs;
 location_t current_lhs_location;
 assoc_t current_assoc;
@@ -458,14 +458,14 @@ static const yysigned_char yyrhs[] =
 /* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
 static const unsigned short yyrline[] =
 {
-       0,   168,   168,   181,   183,   186,   188,   189,   190,   191,
-     192,   193,   194,   195,   196,   198,   199,   200,   201,   202,
-     204,   205,   206,   207,   208,   211,   213,   214,   218,   225,
-     224,   235,   234,   247,   246,   252,   252,   257,   266,   281,
-     283,   284,   287,   289,   294,   296,   300,   305,   310,   316,
-     322,   332,   335,   344,   346,   352,   354,   359,   366,   365,
-     370,   372,   375,   378,   380,   382,   384,   386,   390,   392,
-     395,   401,   410,   418,   423,   429,   431
+       0,   169,   169,   182,   184,   187,   189,   190,   191,   192,
+     193,   194,   195,   196,   197,   199,   200,   201,   202,   203,
+     205,   206,   207,   208,   209,   212,   214,   215,   219,   226,
+     225,   236,   235,   248,   247,   253,   253,   258,   267,   282,
+     284,   285,   288,   290,   295,   297,   301,   306,   311,   317,
+     323,   333,   336,   345,   347,   353,   355,   360,   367,   366,
+     371,   373,   376,   379,   381,   383,   385,   387,   391,   393,
+     396,   402,   411,   419,   424,   430,   432
 };
 #endif
 
@@ -1216,7 +1216,7 @@ yyreduce:
   switch (yyn)
     {
         case 2:
-#line 170 "parse-gram.y"
+#line 171 "parse-gram.y"
     {
       yycontrol->errcode = 0;
       epilogue_set (yyvsp[0].string, yylsp[0]);
@@ -1224,109 +1224,109 @@ yyreduce:
     break;
 
   case 6:
-#line 188 "parse-gram.y"
+#line 189 "parse-gram.y"
     { prologue_augment (yyvsp[0].string, yylsp[0]); }
     break;
 
   case 7:
-#line 189 "parse-gram.y"
+#line 190 "parse-gram.y"
     { debug_flag = 1; }
     break;
 
   case 8:
-#line 190 "parse-gram.y"
+#line 191 "parse-gram.y"
     { muscle_insert (yyvsp[-1].string, yyvsp[0].string); }
     break;
 
   case 9:
-#line 191 "parse-gram.y"
+#line 192 "parse-gram.y"
     { defines_flag = 1; }
     break;
 
   case 10:
-#line 192 "parse-gram.y"
+#line 193 "parse-gram.y"
     { error_verbose = 1; }
     break;
 
   case 11:
-#line 193 "parse-gram.y"
+#line 194 "parse-gram.y"
     { expected_conflicts = yyvsp[0].integer; }
     break;
 
   case 12:
-#line 194 "parse-gram.y"
+#line 195 "parse-gram.y"
     { spec_file_prefix = yyvsp[0].string; }
     break;
 
   case 13:
-#line 195 "parse-gram.y"
+#line 196 "parse-gram.y"
     { glr_parser = 1; }
     break;
 
   case 14:
-#line 197 "parse-gram.y"
+#line 198 "parse-gram.y"
     { muscle_pair_list_grow ("lex_param", yyvsp[-2].string, yyvsp[0].string); }
     break;
 
   case 15:
-#line 198 "parse-gram.y"
+#line 199 "parse-gram.y"
     { locations_flag = 1; }
     break;
 
   case 16:
-#line 199 "parse-gram.y"
+#line 200 "parse-gram.y"
     { spec_name_prefix = yyvsp[0].string; }
     break;
 
   case 17:
-#line 200 "parse-gram.y"
+#line 201 "parse-gram.y"
     { no_lines_flag = 1; }
     break;
 
   case 18:
-#line 201 "parse-gram.y"
+#line 202 "parse-gram.y"
     { spec_outfile = yyvsp[0].string; }
     break;
 
   case 19:
-#line 203 "parse-gram.y"
+#line 204 "parse-gram.y"
     { muscle_pair_list_grow ("parse_param", yyvsp[-2].string, yyvsp[0].string); }
     break;
 
   case 20:
-#line 204 "parse-gram.y"
+#line 205 "parse-gram.y"
     { pure_parser = 1; }
     break;
 
   case 21:
-#line 205 "parse-gram.y"
+#line 206 "parse-gram.y"
     { skeleton = yyvsp[0].string; }
     break;
 
   case 22:
-#line 206 "parse-gram.y"
+#line 207 "parse-gram.y"
     { token_table_flag = 1; }
     break;
 
   case 23:
-#line 207 "parse-gram.y"
+#line 208 "parse-gram.y"
     { report_flag = 1; }
     break;
 
   case 24:
-#line 208 "parse-gram.y"
+#line 209 "parse-gram.y"
     { yacc_flag = 1; }
     break;
 
   case 27:
-#line 215 "parse-gram.y"
+#line 216 "parse-gram.y"
     {
       grammar_start_symbol_set (yyvsp[0].symbol, yylsp[0]);
     }
     break;
 
   case 28:
-#line 219 "parse-gram.y"
+#line 220 "parse-gram.y"
     {
       typed = 1;
       MUSCLE_INSERT_INT ("stype_line", yylsp[0].first_line);
@@ -1335,12 +1335,12 @@ yyreduce:
     break;
 
   case 29:
-#line 225 "parse-gram.y"
+#line 226 "parse-gram.y"
     { current_braced_code = destructor_braced_code; }
     break;
 
   case 30:
-#line 227 "parse-gram.y"
+#line 228 "parse-gram.y"
     {
       symbol_list_t *list;
       for (list = yyvsp[0].list; list; list = list->next)
@@ -1351,12 +1351,12 @@ yyreduce:
     break;
 
   case 31:
-#line 235 "parse-gram.y"
+#line 236 "parse-gram.y"
     { current_braced_code = printer_braced_code; }
     break;
 
   case 32:
-#line 237 "parse-gram.y"
+#line 238 "parse-gram.y"
     {
       symbol_list_t *list;
       for (list = yyvsp[0].list; list; list = list->next)
@@ -1367,12 +1367,12 @@ yyreduce:
     break;
 
   case 33:
-#line 247 "parse-gram.y"
+#line 248 "parse-gram.y"
     { current_class = nterm_sym; }
     break;
 
   case 34:
-#line 248 "parse-gram.y"
+#line 249 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
@@ -1380,12 +1380,12 @@ yyreduce:
     break;
 
   case 35:
-#line 252 "parse-gram.y"
+#line 253 "parse-gram.y"
     { current_class = token_sym; }
     break;
 
   case 36:
-#line 253 "parse-gram.y"
+#line 254 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
@@ -1393,17 +1393,17 @@ yyreduce:
     break;
 
   case 37:
-#line 258 "parse-gram.y"
+#line 259 "parse-gram.y"
     {
       symbol_list_t *list;
       for (list = yyvsp[0].list; list; list = list->next)
-	symbol_type_set (list->sym, yyvsp[-1].string, yylsp[-1]);
+	symbol_type_set (list->sym, yyvsp[-1].struniq, yylsp[-1]);
       symbol_list_free (yyvsp[0].list);
     }
     break;
 
   case 38:
-#line 268 "parse-gram.y"
+#line 269 "parse-gram.y"
     {
       symbol_list_t *list;
       ++current_prec;
@@ -1418,49 +1418,49 @@ yyreduce:
     break;
 
   case 39:
-#line 282 "parse-gram.y"
+#line 283 "parse-gram.y"
     { yyval.assoc = left_assoc; }
     break;
 
   case 40:
-#line 283 "parse-gram.y"
+#line 284 "parse-gram.y"
     { yyval.assoc = right_assoc; }
     break;
 
   case 41:
-#line 284 "parse-gram.y"
+#line 285 "parse-gram.y"
     { yyval.assoc = non_assoc; }
     break;
 
   case 42:
-#line 288 "parse-gram.y"
+#line 289 "parse-gram.y"
     { current_type = NULL; }
     break;
 
   case 43:
-#line 289 "parse-gram.y"
-    { current_type = yyvsp[0].string; }
+#line 290 "parse-gram.y"
+    { current_type = yyvsp[0].struniq; }
     break;
 
   case 44:
-#line 295 "parse-gram.y"
+#line 296 "parse-gram.y"
     { yyval.list = symbol_list_new (yyvsp[0].symbol, yylsp[0]); }
     break;
 
   case 45:
-#line 296 "parse-gram.y"
+#line 297 "parse-gram.y"
     { yyval.list = symbol_list_prepend (yyvsp[-1].list, yyvsp[0].symbol, yylsp[0]); }
     break;
 
   case 46:
-#line 302 "parse-gram.y"
+#line 303 "parse-gram.y"
     {
-       current_type = yyvsp[0].string;
+       current_type = yyvsp[0].struniq;
      }
     break;
 
   case 47:
-#line 306 "parse-gram.y"
+#line 307 "parse-gram.y"
     {
        symbol_class_set (yyvsp[0].symbol, current_class, yylsp[0]);
        symbol_type_set (yyvsp[0].symbol, current_type, yylsp[0]);
@@ -1468,7 +1468,7 @@ yyreduce:
     break;
 
   case 48:
-#line 311 "parse-gram.y"
+#line 312 "parse-gram.y"
     {
       symbol_class_set (yyvsp[-1].symbol, current_class, yylsp[-1]);
       symbol_type_set (yyvsp[-1].symbol, current_type, yylsp[-1]);
@@ -1477,7 +1477,7 @@ yyreduce:
     break;
 
   case 49:
-#line 317 "parse-gram.y"
+#line 318 "parse-gram.y"
     {
       symbol_class_set (yyvsp[-1].symbol, current_class, yylsp[-1]);
       symbol_type_set (yyvsp[-1].symbol, current_type, yylsp[-1]);
@@ -1486,7 +1486,7 @@ yyreduce:
     break;
 
   case 50:
-#line 323 "parse-gram.y"
+#line 324 "parse-gram.y"
     {
       symbol_class_set (yyvsp[-2].symbol, current_class, yylsp[-2]);
       symbol_type_set (yyvsp[-2].symbol, current_type, yylsp[-2]);
@@ -1496,17 +1496,17 @@ yyreduce:
     break;
 
   case 51:
-#line 334 "parse-gram.y"
+#line 335 "parse-gram.y"
     {;}
     break;
 
   case 52:
-#line 336 "parse-gram.y"
+#line 337 "parse-gram.y"
     {;}
     break;
 
   case 56:
-#line 355 "parse-gram.y"
+#line 356 "parse-gram.y"
     {
       if (yacc_flag)
 	complain_at (yyloc, _("POSIX forbids declarations in the grammar"));
@@ -1514,79 +1514,79 @@ yyreduce:
     break;
 
   case 57:
-#line 360 "parse-gram.y"
+#line 361 "parse-gram.y"
     {
       yyerrok;
     }
     break;
 
   case 58:
-#line 366 "parse-gram.y"
+#line 367 "parse-gram.y"
     { current_lhs = yyvsp[-1].symbol; current_lhs_location = yylsp[-1]; }
     break;
 
   case 59:
-#line 367 "parse-gram.y"
+#line 368 "parse-gram.y"
     {;}
     break;
 
   case 60:
-#line 371 "parse-gram.y"
+#line 372 "parse-gram.y"
     { grammar_rule_end (yylsp[0]); }
     break;
 
   case 61:
-#line 372 "parse-gram.y"
+#line 373 "parse-gram.y"
     { grammar_rule_end (yylsp[0]); }
     break;
 
   case 62:
-#line 377 "parse-gram.y"
+#line 378 "parse-gram.y"
     { grammar_rule_begin (current_lhs, current_lhs_location); }
     break;
 
   case 63:
-#line 379 "parse-gram.y"
+#line 380 "parse-gram.y"
     { grammar_current_rule_symbol_append (yyvsp[0].symbol, yylsp[0]); }
     break;
 
   case 64:
-#line 381 "parse-gram.y"
+#line 382 "parse-gram.y"
     { grammar_current_rule_action_append (yyvsp[0].string, yylsp[0]); }
     break;
 
   case 65:
-#line 383 "parse-gram.y"
+#line 384 "parse-gram.y"
     { grammar_current_rule_prec_set (yyvsp[0].symbol, yylsp[0]); }
     break;
 
   case 66:
-#line 385 "parse-gram.y"
+#line 386 "parse-gram.y"
     { grammar_current_rule_dprec_set (yyvsp[0].integer, yylsp[0]); }
     break;
 
   case 67:
-#line 387 "parse-gram.y"
-    { grammar_current_rule_merge_set (yyvsp[0].string, yylsp[0]); }
+#line 388 "parse-gram.y"
+    { grammar_current_rule_merge_set (yyvsp[0].struniq, yylsp[0]); }
     break;
 
   case 68:
-#line 391 "parse-gram.y"
+#line 392 "parse-gram.y"
     { yyval.symbol = yyvsp[0].symbol; }
     break;
 
   case 69:
-#line 392 "parse-gram.y"
+#line 393 "parse-gram.y"
     { yyval.symbol = yyvsp[0].symbol; }
     break;
 
   case 70:
-#line 397 "parse-gram.y"
+#line 398 "parse-gram.y"
     { yyval.string = yyvsp[0].string; }
     break;
 
   case 71:
-#line 403 "parse-gram.y"
+#line 404 "parse-gram.y"
     {
       yyval.symbol = symbol_get (yyvsp[0].string, yylsp[0]);
       symbol_class_set (yyval.symbol, token_sym, yylsp[0]);
@@ -1594,7 +1594,7 @@ yyreduce:
     break;
 
   case 72:
-#line 412 "parse-gram.y"
+#line 413 "parse-gram.y"
     {
       yyval.string = yyvsp[0].string + 1;
       yyval.string[strlen (yyval.string) - 1] = '\0';
@@ -1602,14 +1602,14 @@ yyreduce:
     break;
 
   case 73:
-#line 420 "parse-gram.y"
+#line 421 "parse-gram.y"
     {
       yyval.string = xstrdup ("");
     }
     break;
 
   case 74:
-#line 424 "parse-gram.y"
+#line 425 "parse-gram.y"
     {
       yyval.string = yyvsp[0].string;
     }
@@ -1838,7 +1838,7 @@ yyreturn:
 }
 
 
-#line 433 "parse-gram.y"
+#line 434 "parse-gram.y"
 
 /*------------------------------------------------------------------.
 | When debugging the parser, display tokens' locations and values.  |
