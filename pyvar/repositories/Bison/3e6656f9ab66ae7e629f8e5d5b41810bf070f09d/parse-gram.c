@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 1.75b.  */
+/* A Bison parser, made from parse-gram.y, by GNU bison 1.75b.  */
 
 /* Skeleton parser for Yacc-like parsing with Bison,
    Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002 Free Software Foundation, Inc.
@@ -236,9 +236,10 @@ typedef union {
   int integer;
   char *string;
   assoc_t assoc;
+  struniq_t struniq;
 } yystype;
-/* Line 212 of /tmp/prefix/share/bison/yacc.c.  */
-#line 241 "parse-gram.c"
+/* Line 237 of /usr/local/share/bison/yacc.c.  */
+#line 243 "parse-gram.c"
 # define YYSTYPE yystype
 # define YYSTYPE_IS_TRIVIAL 1
 #endif
@@ -258,8 +259,8 @@ typedef struct yyltype
 /* Copy the second part of user declarations.  */
 
 
-/* Line 232 of /tmp/prefix/share/bison/yacc.c.  */
-#line 262 "parse-gram.c"
+/* Line 257 of /usr/local/share/bison/yacc.c.  */
+#line 264 "parse-gram.c"
 
 #if ! defined (yyoverflow) || YYERROR_VERBOSE
 
@@ -457,14 +458,14 @@ static const yysigned_char yyrhs[] =
 /* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
 static const unsigned short yyrline[] =
 {
-       0,   167,   167,   180,   182,   185,   187,   188,   189,   190,
-     191,   192,   193,   194,   195,   197,   198,   199,   200,   201,
-     203,   204,   205,   206,   207,   210,   212,   213,   217,   224,
-     223,   234,   233,   246,   245,   251,   251,   256,   265,   280,
-     282,   283,   286,   288,   293,   295,   299,   304,   309,   315,
-     321,   331,   334,   343,   345,   351,   353,   358,   365,   364,
-     369,   371,   374,   377,   379,   381,   383,   385,   389,   391,
-     394,   400,   409,   417,   422,   428,   430
+       0,   168,   168,   181,   183,   186,   188,   189,   190,   191,
+     192,   193,   194,   195,   196,   198,   199,   200,   201,   202,
+     204,   205,   206,   207,   208,   211,   213,   214,   218,   225,
+     224,   235,   234,   247,   246,   252,   252,   257,   266,   281,
+     283,   284,   287,   289,   294,   296,   300,   305,   310,   316,
+     322,   332,   335,   344,   346,   352,   354,   359,   366,   365,
+     370,   372,   375,   378,   380,   382,   384,   386,   390,   392,
+     395,   401,   410,   418,   423,   429,   431
 };
 #endif
 
@@ -1215,7 +1216,7 @@ yyreduce:
   switch (yyn)
     {
         case 2:
-#line 169 "parse-gram.y"
+#line 170 "parse-gram.y"
     {
       yycontrol->errcode = 0;
       epilogue_set (yyvsp[0].string, yylsp[0]);
@@ -1223,109 +1224,109 @@ yyreduce:
     break;
 
   case 6:
-#line 187 "parse-gram.y"
+#line 188 "parse-gram.y"
     { prologue_augment (yyvsp[0].string, yylsp[0]); }
     break;
 
   case 7:
-#line 188 "parse-gram.y"
+#line 189 "parse-gram.y"
     { debug_flag = 1; }
     break;
 
   case 8:
-#line 189 "parse-gram.y"
+#line 190 "parse-gram.y"
     { muscle_insert (yyvsp[-1].string, yyvsp[0].string); }
     break;
 
   case 9:
-#line 190 "parse-gram.y"
+#line 191 "parse-gram.y"
     { defines_flag = 1; }
     break;
 
   case 10:
-#line 191 "parse-gram.y"
+#line 192 "parse-gram.y"
     { error_verbose = 1; }
     break;
 
   case 11:
-#line 192 "parse-gram.y"
+#line 193 "parse-gram.y"
     { expected_conflicts = yyvsp[0].integer; }
     break;
 
   case 12:
-#line 193 "parse-gram.y"
+#line 194 "parse-gram.y"
     { spec_file_prefix = yyvsp[0].string; }
     break;
 
   case 13:
-#line 194 "parse-gram.y"
+#line 195 "parse-gram.y"
     { glr_parser = 1; }
     break;
 
   case 14:
-#line 196 "parse-gram.y"
+#line 197 "parse-gram.y"
     { muscle_pair_list_grow ("lex_param", yyvsp[-2].string, yyvsp[0].string); }
     break;
 
   case 15:
-#line 197 "parse-gram.y"
+#line 198 "parse-gram.y"
     { locations_flag = 1; }
     break;
 
   case 16:
-#line 198 "parse-gram.y"
+#line 199 "parse-gram.y"
     { spec_name_prefix = yyvsp[0].string; }
     break;
 
   case 17:
-#line 199 "parse-gram.y"
+#line 200 "parse-gram.y"
     { no_lines_flag = 1; }
     break;
 
   case 18:
-#line 200 "parse-gram.y"
+#line 201 "parse-gram.y"
     { spec_outfile = yyvsp[0].string; }
     break;
 
   case 19:
-#line 202 "parse-gram.y"
+#line 203 "parse-gram.y"
     { muscle_pair_list_grow ("parse_param", yyvsp[-2].string, yyvsp[0].string); }
     break;
 
   case 20:
-#line 203 "parse-gram.y"
+#line 204 "parse-gram.y"
     { pure_parser = 1; }
     break;
 
   case 21:
-#line 204 "parse-gram.y"
+#line 205 "parse-gram.y"
     { skeleton = yyvsp[0].string; }
     break;
 
   case 22:
-#line 205 "parse-gram.y"
+#line 206 "parse-gram.y"
     { token_table_flag = 1; }
     break;
 
   case 23:
-#line 206 "parse-gram.y"
+#line 207 "parse-gram.y"
     { report_flag = 1; }
     break;
 
   case 24:
-#line 207 "parse-gram.y"
+#line 208 "parse-gram.y"
     { yacc_flag = 1; }
     break;
 
   case 27:
-#line 214 "parse-gram.y"
+#line 215 "parse-gram.y"
     {
       grammar_start_symbol_set (yyvsp[0].symbol, yylsp[0]);
     }
     break;
 
   case 28:
-#line 218 "parse-gram.y"
+#line 219 "parse-gram.y"
     {
       typed = 1;
       MUSCLE_INSERT_INT ("stype_line", yylsp[0].first_line);
@@ -1334,12 +1335,12 @@ yyreduce:
     break;
 
   case 29:
-#line 224 "parse-gram.y"
+#line 225 "parse-gram.y"
     { current_braced_code = destructor_braced_code; }
     break;
 
   case 30:
-#line 226 "parse-gram.y"
+#line 227 "parse-gram.y"
     {
       symbol_list_t *list;
       for (list = yyvsp[0].list; list; list = list->next)
@@ -1350,12 +1351,12 @@ yyreduce:
     break;
 
   case 31:
-#line 234 "parse-gram.y"
+#line 235 "parse-gram.y"
     { current_braced_code = printer_braced_code; }
     break;
 
   case 32:
-#line 236 "parse-gram.y"
+#line 237 "parse-gram.y"
     {
       symbol_list_t *list;
       for (list = yyvsp[0].list; list; list = list->next)
@@ -1366,12 +1367,12 @@ yyreduce:
     break;
 
   case 33:
-#line 246 "parse-gram.y"
+#line 247 "parse-gram.y"
     { current_class = nterm_sym; }
     break;
 
   case 34:
-#line 247 "parse-gram.y"
+#line 248 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
@@ -1379,12 +1380,12 @@ yyreduce:
     break;
 
   case 35:
-#line 251 "parse-gram.y"
+#line 252 "parse-gram.y"
     { current_class = token_sym; }
     break;
 
   case 36:
-#line 252 "parse-gram.y"
+#line 253 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
@@ -1392,7 +1393,7 @@ yyreduce:
     break;
 
   case 37:
-#line 257 "parse-gram.y"
+#line 258 "parse-gram.y"
     {
       symbol_list_t *list;
       for (list = yyvsp[0].list; list; list = list->next)
@@ -1402,7 +1403,7 @@ yyreduce:
     break;
 
   case 38:
-#line 267 "parse-gram.y"
+#line 268 "parse-gram.y"
     {
       symbol_list_t *list;
       ++current_prec;
@@ -1417,49 +1418,49 @@ yyreduce:
     break;
 
   case 39:
-#line 281 "parse-gram.y"
+#line 282 "parse-gram.y"
     { yyval.assoc = left_assoc; }
     break;
 
   case 40:
-#line 282 "parse-gram.y"
+#line 283 "parse-gram.y"
     { yyval.assoc = right_assoc; }
     break;
 
   case 41:
-#line 283 "parse-gram.y"
+#line 284 "parse-gram.y"
     { yyval.assoc = non_assoc; }
     break;
 
   case 42:
-#line 287 "parse-gram.y"
+#line 288 "parse-gram.y"
     { current_type = NULL; }
     break;
 
   case 43:
-#line 288 "parse-gram.y"
+#line 289 "parse-gram.y"
     { current_type = yyvsp[0].string; }
     break;
 
   case 44:
-#line 294 "parse-gram.y"
+#line 295 "parse-gram.y"
     { yyval.list = symbol_list_new (yyvsp[0].symbol, yylsp[0]); }
     break;
 
   case 45:
-#line 295 "parse-gram.y"
+#line 296 "parse-gram.y"
     { yyval.list = symbol_list_prepend (yyvsp[-1].list, yyvsp[0].symbol, yylsp[0]); }
     break;
 
   case 46:
-#line 301 "parse-gram.y"
+#line 302 "parse-gram.y"
     {
        current_type = yyvsp[0].string;
      }
     break;
 
   case 47:
-#line 305 "parse-gram.y"
+#line 306 "parse-gram.y"
     {
        symbol_class_set (yyvsp[0].symbol, current_class, yylsp[0]);
        symbol_type_set (yyvsp[0].symbol, current_type, yylsp[0]);
@@ -1467,7 +1468,7 @@ yyreduce:
     break;
 
   case 48:
-#line 310 "parse-gram.y"
+#line 311 "parse-gram.y"
     {
       symbol_class_set (yyvsp[-1].symbol, current_class, yylsp[-1]);
       symbol_type_set (yyvsp[-1].symbol, current_type, yylsp[-1]);
@@ -1476,7 +1477,7 @@ yyreduce:
     break;
 
   case 49:
-#line 316 "parse-gram.y"
+#line 317 "parse-gram.y"
     {
       symbol_class_set (yyvsp[-1].symbol, current_class, yylsp[-1]);
       symbol_type_set (yyvsp[-1].symbol, current_type, yylsp[-1]);
@@ -1485,7 +1486,7 @@ yyreduce:
     break;
 
   case 50:
-#line 322 "parse-gram.y"
+#line 323 "parse-gram.y"
     {
       symbol_class_set (yyvsp[-2].symbol, current_class, yylsp[-2]);
       symbol_type_set (yyvsp[-2].symbol, current_type, yylsp[-2]);
@@ -1495,17 +1496,17 @@ yyreduce:
     break;
 
   case 51:
-#line 333 "parse-gram.y"
+#line 334 "parse-gram.y"
     {;}
     break;
 
   case 52:
-#line 335 "parse-gram.y"
+#line 336 "parse-gram.y"
     {;}
     break;
 
   case 56:
-#line 354 "parse-gram.y"
+#line 355 "parse-gram.y"
     {
       if (yacc_flag)
 	complain_at (yyloc, _("POSIX forbids declarations in the grammar"));
@@ -1513,79 +1514,79 @@ yyreduce:
     break;
 
   case 57:
-#line 359 "parse-gram.y"
+#line 360 "parse-gram.y"
     {
       yyerrok;
     }
     break;
 
   case 58:
-#line 365 "parse-gram.y"
+#line 366 "parse-gram.y"
     { current_lhs = yyvsp[-1].symbol; current_lhs_location = yylsp[-1]; }
     break;
 
   case 59:
-#line 366 "parse-gram.y"
+#line 367 "parse-gram.y"
     {;}
     break;
 
   case 60:
-#line 370 "parse-gram.y"
+#line 371 "parse-gram.y"
     { grammar_rule_end (yylsp[0]); }
     break;
 
   case 61:
-#line 371 "parse-gram.y"
+#line 372 "parse-gram.y"
     { grammar_rule_end (yylsp[0]); }
     break;
 
   case 62:
-#line 376 "parse-gram.y"
+#line 377 "parse-gram.y"
     { grammar_rule_begin (current_lhs, current_lhs_location); }
     break;
 
   case 63:
-#line 378 "parse-gram.y"
+#line 379 "parse-gram.y"
     { grammar_current_rule_symbol_append (yyvsp[0].symbol, yylsp[0]); }
     break;
 
   case 64:
-#line 380 "parse-gram.y"
+#line 381 "parse-gram.y"
     { grammar_current_rule_action_append (yyvsp[0].string, yylsp[0]); }
     break;
 
   case 65:
-#line 382 "parse-gram.y"
+#line 383 "parse-gram.y"
     { grammar_current_rule_prec_set (yyvsp[0].symbol, yylsp[0]); }
     break;
 
   case 66:
-#line 384 "parse-gram.y"
+#line 385 "parse-gram.y"
     { grammar_current_rule_dprec_set (yyvsp[0].integer, yylsp[0]); }
     break;
 
   case 67:
-#line 386 "parse-gram.y"
+#line 387 "parse-gram.y"
     { grammar_current_rule_merge_set (yyvsp[0].string, yylsp[0]); }
     break;
 
   case 68:
-#line 390 "parse-gram.y"
+#line 391 "parse-gram.y"
     { yyval.symbol = yyvsp[0].symbol; }
     break;
 
   case 69:
-#line 391 "parse-gram.y"
+#line 392 "parse-gram.y"
     { yyval.symbol = yyvsp[0].symbol; }
     break;
 
   case 70:
-#line 396 "parse-gram.y"
+#line 397 "parse-gram.y"
     { yyval.string = yyvsp[0].string; }
     break;
 
   case 71:
-#line 402 "parse-gram.y"
+#line 403 "parse-gram.y"
     {
       yyval.symbol = symbol_get (yyvsp[0].string, yylsp[0]);
       symbol_class_set (yyval.symbol, token_sym, yylsp[0]);
@@ -1593,7 +1594,7 @@ yyreduce:
     break;
 
   case 72:
-#line 411 "parse-gram.y"
+#line 412 "parse-gram.y"
     {
       yyval.string = yyvsp[0].string + 1;
       yyval.string[strlen (yyval.string) - 1] = '\0';
@@ -1601,14 +1602,14 @@ yyreduce:
     break;
 
   case 73:
-#line 419 "parse-gram.y"
+#line 420 "parse-gram.y"
     {
       yyval.string = xstrdup ("");
     }
     break;
 
   case 74:
-#line 423 "parse-gram.y"
+#line 424 "parse-gram.y"
     {
       yyval.string = yyvsp[0].string;
     }
@@ -1617,8 +1618,8 @@ yyreduce:
 
     }
 
-/* Line 1031 of /tmp/prefix/share/bison/yacc.c.  */
-#line 1621 "parse-gram.c"
+/* Line 1056 of /usr/local/share/bison/yacc.c.  */
+#line 1623 "parse-gram.c"
 
   yyvsp -= yylen;
   yyssp -= yylen;
@@ -1837,7 +1838,7 @@ yyreturn:
 }
 
 
-#line 432 "parse-gram.y"
+#line 433 "parse-gram.y"
 
 /*------------------------------------------------------------------.
 | When debugging the parser, display tokens' locations and values.  |
@@ -1863,7 +1864,7 @@ yyprint (FILE *file,
       break;
 
     case TYPE:
-      fprintf (file, " = <%s>", value->string);
+      fprintf (file, " = <%s>", value->struniq);
       break;
 
     case BRACED_CODE:
