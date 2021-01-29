@@ -167,7 +167,7 @@
 
 
 /* Copy the first part of user declarations.  */
-#line 1 "../../src/parse-gram.y"
+#line 1 "parse-gram.y"
 /* Bison Grammar Parser                             -*- C -*-
 
    Copyright (C) 2002, 2003, 2004 Free Software Foundation, Inc.
@@ -243,7 +243,7 @@ int current_prec = 0;
 #endif
 
 #if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
-#line 81 "../../src/parse-gram.y"
+#line 81 "parse-gram.y"
 typedef union YYSTYPE {
   symbol *symbol;
   symbol_list *list;
@@ -253,7 +253,7 @@ typedef union YYSTYPE {
   uniqstr uniqstr;
 } YYSTYPE;
 /* Line 191 of yacc.c.  */
-#line 257 "../../src/parse-gram.c"
+#line 257 "parse-gram.c"
 # define yystype YYSTYPE /* obsolescent; will be withdrawn */
 # define YYSTYPE_IS_DECLARED 1
 # define YYSTYPE_IS_TRIVIAL 1
@@ -277,7 +277,7 @@ typedef struct YYLTYPE
 
 
 /* Line 214 of yacc.c.  */
-#line 281 "../../src/parse-gram.c"
+#line 281 "parse-gram.c"
 
 #if ! defined (yyoverflow) || YYERROR_VERBOSE
 
@@ -1145,7 +1145,7 @@ YYLTYPE yylloc;
 
 
   /* User initialization code. */
-  #line 71 "../../src/parse-gram.y"
+  #line 71 "parse-gram.y"
 {
   /* Bison's grammar can initial empty locations, hence a default
      location is needed. */
@@ -1154,7 +1154,7 @@ YYLTYPE yylloc;
   yylloc.start.column = yylloc.end.column = 0;
 }
 /* Line 848 of yacc.c.  */
-#line 1158 "../../src/parse-gram.c"
+#line 1158 "parse-gram.c"
   yyvsp[0] = yylval;
     yylsp[0] = yylloc;
 
@@ -1345,47 +1345,47 @@ yyreduce:
   switch (yyn)
     {
         case 6:
-#line 189 "../../src/parse-gram.y"
+#line 189 "parse-gram.y"
     { prologue_augment (yyvsp[0].chars, yylsp[0]); }
     break;
 
   case 7:
-#line 190 "../../src/parse-gram.y"
+#line 190 "parse-gram.y"
     { debug_flag = true; }
     break;
 
   case 8:
-#line 191 "../../src/parse-gram.y"
+#line 191 "parse-gram.y"
     { muscle_insert (yyvsp[-1].chars, yyvsp[0].chars); }
     break;
 
   case 9:
-#line 192 "../../src/parse-gram.y"
+#line 192 "parse-gram.y"
     { defines_flag = true; }
     break;
 
   case 10:
-#line 193 "../../src/parse-gram.y"
+#line 193 "parse-gram.y"
     { error_verbose = true; }
     break;
 
   case 11:
-#line 194 "../../src/parse-gram.y"
+#line 194 "parse-gram.y"
     { expected_sr_conflicts = yyvsp[0].integer; }
     break;
 
   case 12:
-#line 195 "../../src/parse-gram.y"
+#line 195 "parse-gram.y"
     { expected_rr_conflicts = yyvsp[0].integer; }
     break;
 
   case 13:
-#line 196 "../../src/parse-gram.y"
+#line 196 "parse-gram.y"
     { spec_file_prefix = yyvsp[0].chars; }
     break;
 
   case 14:
-#line 198 "../../src/parse-gram.y"
+#line 198 "parse-gram.y"
     {
     nondeterministic_parser = true;
     glr_parser = true;
@@ -1393,81 +1393,81 @@ yyreduce:
     break;
 
   case 15:
-#line 203 "../../src/parse-gram.y"
+#line 203 "parse-gram.y"
     {
     muscle_code_grow ("initial_action", yyvsp[0].chars, yylsp[0]);
   }
     break;
 
   case 16:
-#line 206 "../../src/parse-gram.y"
+#line 206 "parse-gram.y"
     { add_param ("lex_param", yyvsp[0].chars, yylsp[0]); }
     break;
 
   case 17:
-#line 207 "../../src/parse-gram.y"
+#line 207 "parse-gram.y"
     { locations_flag = true; }
     break;
 
   case 18:
-#line 208 "../../src/parse-gram.y"
+#line 208 "parse-gram.y"
     { spec_name_prefix = yyvsp[0].chars; }
     break;
 
   case 19:
-#line 209 "../../src/parse-gram.y"
+#line 209 "parse-gram.y"
     { no_lines_flag = true; }
     break;
 
   case 20:
-#line 210 "../../src/parse-gram.y"
+#line 210 "parse-gram.y"
     { nondeterministic_parser = true; }
     break;
 
   case 21:
-#line 211 "../../src/parse-gram.y"
+#line 211 "parse-gram.y"
     { spec_outfile = yyvsp[0].chars; }
     break;
 
   case 22:
-#line 212 "../../src/parse-gram.y"
+#line 212 "parse-gram.y"
     { add_param ("parse_param", yyvsp[0].chars, yylsp[0]); }
     break;
 
   case 23:
-#line 213 "../../src/parse-gram.y"
+#line 213 "parse-gram.y"
     { pure_parser = true; }
     break;
 
   case 24:
-#line 214 "../../src/parse-gram.y"
+#line 214 "parse-gram.y"
     { skeleton = yyvsp[0].chars; }
     break;
 
   case 25:
-#line 215 "../../src/parse-gram.y"
+#line 215 "parse-gram.y"
     { token_table_flag = true; }
     break;
 
   case 26:
-#line 216 "../../src/parse-gram.y"
+#line 216 "parse-gram.y"
     { report_flag = report_states; }
     break;
 
   case 27:
-#line 217 "../../src/parse-gram.y"
+#line 217 "parse-gram.y"
     { yacc_flag = true; }
     break;
 
   case 31:
-#line 225 "../../src/parse-gram.y"
+#line 225 "parse-gram.y"
     {
       grammar_start_symbol_set (yyvsp[0].symbol, yylsp[0]);
     }
     break;
 
   case 32:
-#line 229 "../../src/parse-gram.y"
+#line 229 "parse-gram.y"
     {
       typed = true;
       MUSCLE_INSERT_INT ("stype_line", yylsp[0].start.line);
@@ -1476,7 +1476,7 @@ yyreduce:
     break;
 
   case 33:
-#line 235 "../../src/parse-gram.y"
+#line 235 "parse-gram.y"
     {
       symbol_list *list;
       for (list = yyvsp[0].list; list; list = list->next)
@@ -1486,7 +1486,7 @@ yyreduce:
     break;
 
   case 34:
-#line 242 "../../src/parse-gram.y"
+#line 242 "parse-gram.y"
     {
       symbol_list *list;
       for (list = yyvsp[0].list; list; list = list->next)
@@ -1496,26 +1496,26 @@ yyreduce:
     break;
 
   case 35:
-#line 249 "../../src/parse-gram.y"
+#line 249 "parse-gram.y"
     {
       default_prec = true;
     }
     break;
 
   case 36:
-#line 253 "../../src/parse-gram.y"
+#line 253 "parse-gram.y"
     {
       default_prec = false;
     }
     break;
 
   case 37:
-#line 259 "../../src/parse-gram.y"
+#line 259 "parse-gram.y"
     { current_class = nterm_sym; }
     break;
 
   case 38:
-#line 260 "../../src/parse-gram.y"
+#line 260 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
@@ -1523,12 +1523,12 @@ yyreduce:
     break;
 
   case 39:
-#line 264 "../../src/parse-gram.y"
+#line 264 "parse-gram.y"
     { current_class = token_sym; }
     break;
 
   case 40:
-#line 265 "../../src/parse-gram.y"
+#line 265 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
@@ -1536,7 +1536,7 @@ yyreduce:
     break;
 
   case 41:
-#line 270 "../../src/parse-gram.y"
+#line 270 "parse-gram.y"
     {
       symbol_list *list;
       for (list = yyvsp[0].list; list; list = list->next)
@@ -1546,7 +1546,7 @@ yyreduce:
     break;
 
   case 42:
-#line 280 "../../src/parse-gram.y"
+#line 280 "parse-gram.y"
     {
       symbol_list *list;
       ++current_prec;
@@ -1561,49 +1561,49 @@ yyreduce:
     break;
 
   case 43:
-#line 294 "../../src/parse-gram.y"
+#line 294 "parse-gram.y"
     { yyval.assoc = left_assoc; }
     break;
 
   case 44:
-#line 295 "../../src/parse-gram.y"
+#line 295 "parse-gram.y"
     { yyval.assoc = right_assoc; }
     break;
 
   case 45:
-#line 296 "../../src/parse-gram.y"
+#line 296 "parse-gram.y"
     { yyval.assoc = non_assoc; }
     break;
 
   case 46:
-#line 300 "../../src/parse-gram.y"
+#line 300 "parse-gram.y"
     { current_type = NULL; }
     break;
 
   case 47:
-#line 301 "../../src/parse-gram.y"
+#line 301 "parse-gram.y"
     { current_type = yyvsp[0].uniqstr; }
     break;
 
   case 48:
-#line 307 "../../src/parse-gram.y"
+#line 307 "parse-gram.y"
     { yyval.list = symbol_list_new (yyvsp[0].symbol, yylsp[0]); }
     break;
 
   case 49:
-#line 308 "../../src/parse-gram.y"
+#line 308 "parse-gram.y"
     { yyval.list = symbol_list_prepend (yyvsp[-1].list, yyvsp[0].symbol, yylsp[0]); }
     break;
 
   case 50:
-#line 314 "../../src/parse-gram.y"
+#line 314 "parse-gram.y"
     {
        current_type = yyvsp[0].uniqstr;
      }
     break;
 
   case 51:
-#line 318 "../../src/parse-gram.y"
+#line 318 "parse-gram.y"
     {
        symbol_class_set (yyvsp[0].symbol, current_class, yylsp[0]);
        symbol_type_set (yyvsp[0].symbol, current_type, yylsp[0]);
@@ -1611,7 +1611,7 @@ yyreduce:
     break;
 
   case 52:
-#line 323 "../../src/parse-gram.y"
+#line 323 "parse-gram.y"
     {
       symbol_class_set (yyvsp[-1].symbol, current_class, yylsp[-1]);
       symbol_type_set (yyvsp[-1].symbol, current_type, yylsp[-1]);
@@ -1620,7 +1620,7 @@ yyreduce:
     break;
 
   case 53:
-#line 329 "../../src/parse-gram.y"
+#line 329 "parse-gram.y"
     {
       symbol_class_set (yyvsp[-1].symbol, current_class, yylsp[-1]);
       symbol_type_set (yyvsp[-1].symbol, current_type, yylsp[-1]);
@@ -1629,7 +1629,7 @@ yyreduce:
     break;
 
   case 54:
-#line 335 "../../src/parse-gram.y"
+#line 335 "parse-gram.y"
     {
       symbol_class_set (yyvsp[-2].symbol, current_class, yylsp[-2]);
       symbol_type_set (yyvsp[-2].symbol, current_type, yylsp[-2]);
@@ -1639,7 +1639,7 @@ yyreduce:
     break;
 
   case 60:
-#line 364 "../../src/parse-gram.y"
+#line 364 "parse-gram.y"
     {
       if (yacc_flag)
 	complain_at (yyloc, _("POSIX forbids declarations in the grammar"));
@@ -1647,74 +1647,74 @@ yyreduce:
     break;
 
   case 61:
-#line 369 "../../src/parse-gram.y"
+#line 369 "parse-gram.y"
     {
       yyerrok;
     }
     break;
 
   case 62:
-#line 375 "../../src/parse-gram.y"
+#line 375 "parse-gram.y"
     { current_lhs = yyvsp[0].symbol; current_lhs_location = yylsp[0]; }
     break;
 
   case 64:
-#line 379 "../../src/parse-gram.y"
+#line 379 "parse-gram.y"
     { grammar_rule_end (yylsp[0]); }
     break;
 
   case 65:
-#line 380 "../../src/parse-gram.y"
+#line 380 "parse-gram.y"
     { grammar_rule_end (yylsp[0]); }
     break;
 
   case 67:
-#line 386 "../../src/parse-gram.y"
+#line 386 "parse-gram.y"
     { grammar_rule_begin (current_lhs, current_lhs_location); }
     break;
 
   case 68:
-#line 388 "../../src/parse-gram.y"
+#line 388 "parse-gram.y"
     { grammar_current_rule_symbol_append (yyvsp[0].symbol, yylsp[0]); }
     break;
 
   case 69:
-#line 390 "../../src/parse-gram.y"
+#line 390 "parse-gram.y"
     { grammar_current_rule_action_append (yyvsp[0].chars, yylsp[0]); }
     break;
 
   case 70:
-#line 392 "../../src/parse-gram.y"
+#line 392 "parse-gram.y"
     { grammar_current_rule_prec_set (yyvsp[0].symbol, yylsp[0]); }
     break;
 
   case 71:
-#line 394 "../../src/parse-gram.y"
+#line 394 "parse-gram.y"
     { grammar_current_rule_dprec_set (yyvsp[0].integer, yylsp[0]); }
     break;
 
   case 72:
-#line 396 "../../src/parse-gram.y"
+#line 396 "parse-gram.y"
     { grammar_current_rule_merge_set (yyvsp[0].uniqstr, yylsp[0]); }
     break;
 
   case 73:
-#line 400 "../../src/parse-gram.y"
+#line 400 "parse-gram.y"
     { yyval.symbol = yyvsp[0].symbol; }
     break;
 
   case 74:
-#line 401 "../../src/parse-gram.y"
+#line 401 "parse-gram.y"
     { yyval.symbol = yyvsp[0].symbol; }
     break;
 
   case 75:
-#line 406 "../../src/parse-gram.y"
+#line 406 "parse-gram.y"
     { yyval.chars = yyvsp[0].chars; }
     break;
 
   case 76:
-#line 412 "../../src/parse-gram.y"
+#line 412 "parse-gram.y"
     {
       yyval.symbol = symbol_get (yyvsp[0].chars, yylsp[0]);
       symbol_class_set (yyval.symbol, token_sym, yylsp[0]);
@@ -1722,7 +1722,7 @@ yyreduce:
     break;
 
   case 77:
-#line 421 "../../src/parse-gram.y"
+#line 421 "parse-gram.y"
     {
       yyval.chars = yyvsp[0].chars + 1;
       yyval.chars[strlen (yyval.chars) - 1] = '\0';
@@ -1730,7 +1730,7 @@ yyreduce:
     break;
 
   case 79:
-#line 430 "../../src/parse-gram.y"
+#line 430 "parse-gram.y"
     {
       muscle_code_grow ("epilogue", yyvsp[0].chars, yylsp[0]);
       scanner_last_string_free ();
@@ -1741,7 +1741,7 @@ yyreduce:
     }
 
 /* Line 1043 of yacc.c.  */
-#line 1745 "../../src/parse-gram.c"
+#line 1745 "parse-gram.c"
 
   yyvsp -= yylen;
   yyssp -= yylen;
@@ -1976,7 +1976,7 @@ yyreturn:
 }
 
 
-#line 436 "../../src/parse-gram.y"
+#line 436 "parse-gram.y"
 
 
 
@@ -2024,18 +2024,18 @@ add_param (char const *type, char *decl, location loc)
   char const *name_start = NULL;
   char *p;
 
+  /* Stop on last actual character.  */
   for (p = decl; p[1]; p++)
     if ((p == decl
 	 || ! memchr (alphanum, p[-1], sizeof alphanum))
 	&& memchr (alphanum, p[0], sizeof alphanum - 10))
       name_start = p;
-  fprintf (stderr, "DECLI: {%s}(%c)\n", decl, *p);
+
   /* Strip the surrounding '{' and '}', and any blanks just inside
      the braces.  */
   while (*--p == ' ' || *p == '\t')
     continue;
   p[1] = '\0';
-  fprintf (stderr, "DECLO: {%s}\n", decl);
   while (*++decl == ' ' || *decl == '\t')
     continue;
 
