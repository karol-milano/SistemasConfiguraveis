@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 2.1b.  */
+/* A Bison parser, made by GNU Bison 2.2.  */
 
 /* Skeleton implementation for Bison's Yacc-like parsers in C
 
@@ -47,7 +47,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "2.1b"
+#define YYBISON_VERSION "2.2"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -182,7 +182,7 @@
 
 
 /* Copy the first part of user declarations.  */
-#line 1 "../../src/parse-gram.y"
+#line 1 "parse-gram.y"
 /* Bison Grammar Parser                             -*- C -*-
 
    Copyright (C) 2002, 2003, 2004, 2005, 2006 Free Software Foundation, Inc.
@@ -276,7 +276,7 @@ static int current_prec = 0;
 
 #if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
 typedef union YYSTYPE
-#line 94 "../../src/parse-gram.y"
+#line 94 "parse-gram.y"
 {
   symbol *symbol;
   symbol_list *list;
@@ -286,7 +286,7 @@ typedef union YYSTYPE
   uniqstr uniqstr;
 }
 /* Line 193 of yacc.c.  */
-#line 290 "../../src/parse-gram.c"
+#line 290 "parse-gram.c"
 	YYSTYPE;
 # define yystype YYSTYPE /* obsolescent; will be withdrawn */
 # define YYSTYPE_IS_DECLARED 1
@@ -311,7 +311,7 @@ typedef struct YYLTYPE
 
 
 /* Line 216 of yacc.c.  */
-#line 315 "../../src/parse-gram.c"
+#line 315 "parse-gram.c"
 
 #ifdef short
 # undef short
@@ -973,84 +973,84 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
   switch (yytype)
     {
       case 3: /* "\"string\"" */
-#line 179 "../../src/parse-gram.y"
+#line 179 "parse-gram.y"
 	{ fprintf (stderr, "\"%s\"", (yyvaluep->chars)); };
-#line 979 "../../src/parse-gram.c"
+#line 979 "parse-gram.c"
 	break;
       case 4: /* "\"integer\"" */
-#line 192 "../../src/parse-gram.y"
+#line 192 "parse-gram.y"
 	{ fprintf (stderr, "%d", (yyvaluep->integer)); };
-#line 984 "../../src/parse-gram.c"
+#line 984 "parse-gram.c"
 	break;
       case 8: /* "\"%destructor {...}\"" */
-#line 181 "../../src/parse-gram.y"
+#line 181 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 989 "../../src/parse-gram.c"
+#line 989 "parse-gram.c"
 	break;
       case 9: /* "\"%printer {...}\"" */
-#line 181 "../../src/parse-gram.y"
+#line 181 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 994 "../../src/parse-gram.c"
+#line 994 "parse-gram.c"
 	break;
       case 10: /* "\"%union {...}\"" */
-#line 181 "../../src/parse-gram.y"
+#line 181 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 999 "../../src/parse-gram.c"
+#line 999 "parse-gram.c"
 	break;
       case 26: /* "\"%initial-action {...}\"" */
-#line 181 "../../src/parse-gram.y"
+#line 181 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1004 "../../src/parse-gram.c"
+#line 1004 "parse-gram.c"
 	break;
       case 27: /* "\"%lex-param {...}\"" */
-#line 181 "../../src/parse-gram.y"
+#line 181 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1009 "../../src/parse-gram.c"
+#line 1009 "parse-gram.c"
 	break;
       case 34: /* "\"%parse-param {...}\"" */
-#line 181 "../../src/parse-gram.y"
+#line 181 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1014 "../../src/parse-gram.c"
+#line 1014 "parse-gram.c"
 	break;
       case 42: /* "\"type\"" */
-#line 190 "../../src/parse-gram.y"
+#line 190 "parse-gram.y"
 	{ fprintf (stderr, "<%s>", (yyvaluep->uniqstr)); };
-#line 1019 "../../src/parse-gram.c"
+#line 1019 "parse-gram.c"
 	break;
       case 46: /* "\"identifier\"" */
-#line 194 "../../src/parse-gram.y"
+#line 194 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
-#line 1024 "../../src/parse-gram.c"
+#line 1024 "parse-gram.c"
 	break;
       case 47: /* "\"identifier:\"" */
-#line 196 "../../src/parse-gram.y"
+#line 196 "parse-gram.y"
 	{ fprintf (stderr, "%s:", (yyvaluep->symbol)->tag); };
-#line 1029 "../../src/parse-gram.c"
+#line 1029 "parse-gram.c"
 	break;
       case 49: /* "\"%{...%}\"" */
-#line 181 "../../src/parse-gram.y"
+#line 181 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1034 "../../src/parse-gram.c"
+#line 1034 "parse-gram.c"
 	break;
       case 50: /* "\"epilogue\"" */
-#line 181 "../../src/parse-gram.y"
+#line 181 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1039 "../../src/parse-gram.c"
+#line 1039 "parse-gram.c"
 	break;
       case 72: /* "symbol" */
-#line 194 "../../src/parse-gram.y"
+#line 194 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
-#line 1044 "../../src/parse-gram.c"
+#line 1044 "parse-gram.c"
 	break;
       case 75: /* "string_as_id" */
-#line 194 "../../src/parse-gram.y"
+#line 194 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
-#line 1049 "../../src/parse-gram.c"
+#line 1049 "parse-gram.c"
 	break;
       case 76: /* "string_content" */
-#line 179 "../../src/parse-gram.y"
+#line 179 "parse-gram.y"
 	{ fprintf (stderr, "\"%s\"", (yyvaluep->chars)); };
-#line 1054 "../../src/parse-gram.c"
+#line 1054 "parse-gram.c"
 	break;
       default:
 	break;
@@ -1249,7 +1249,7 @@ yytnamerr (char *yyres, const char *yystr)
 {
   if (*yystr == '"')
     {
-      size_t yyn = 0;
+      YYSIZE_T yyn = 0;
       char const *yyp = yystr;
 
       for (;;)
@@ -1296,7 +1296,7 @@ yysyntax_error (char *yyresult, int yystate, int yychar)
 {
   int yyn = yypact[yystate];
 
-  if (! (YYPACT_NINF < yyn && yyn < YYLAST))
+  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
     return 0;
   else
     {
@@ -1334,7 +1334,7 @@ yysyntax_error (char *yyresult, int yystate, int yychar)
       int yyxbegin = yyn < 0 ? -yyn : 0;
 
       /* Stay within bounds of both yycheck and yytname.  */
-      int yychecklim = YYLAST - yyn;
+      int yychecklim = YYLAST - yyn + 1;
       int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
       int yycount = 1;
 
@@ -1561,7 +1561,7 @@ YYLTYPE yylloc;
 
 
   /* User initialization code.  */
-#line 84 "../../src/parse-gram.y"
+#line 84 "parse-gram.y"
 {
   /* Bison's grammar can initial empty locations, hence a default
      location is needed. */
@@ -1570,7 +1570,7 @@ YYLTYPE yylloc;
   yylloc.start.column = yylloc.end.column = 0;
 }
 /* Line 1078 of yacc.c.  */
-#line 1574 "../../src/parse-gram.c"
+#line 1574 "parse-gram.c"
   yylsp[0] = yylloc;
   goto yysetstate;
 
@@ -1755,17 +1755,17 @@ yyreduce:
   switch (yyn)
     {
         case 6:
-#line 217 "../../src/parse-gram.y"
+#line 217 "parse-gram.y"
     { prologue_augment ((yyvsp[(1) - (1)].chars), (yylsp[(1) - (1)])); }
     break;
 
   case 7:
-#line 218 "../../src/parse-gram.y"
+#line 218 "parse-gram.y"
     { debug_flag = true; }
     break;
 
   case 8:
-#line 220 "../../src/parse-gram.y"
+#line 220 "parse-gram.y"
     {
       static char one[] = "1";
       muscle_insert ((yyvsp[(2) - (2)].chars), one);
@@ -1773,37 +1773,37 @@ yyreduce:
     break;
 
   case 9:
-#line 224 "../../src/parse-gram.y"
+#line 224 "parse-gram.y"
     { muscle_insert ((yyvsp[(2) - (3)].chars), (yyvsp[(3) - (3)].chars)); }
     break;
 
   case 10:
-#line 225 "../../src/parse-gram.y"
+#line 225 "parse-gram.y"
     { defines_flag = true; }
     break;
 
   case 11:
-#line 226 "../../src/parse-gram.y"
+#line 226 "parse-gram.y"
     { error_verbose = true; }
     break;
 
   case 12:
-#line 227 "../../src/parse-gram.y"
+#line 227 "parse-gram.y"
     { expected_sr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 13:
-#line 228 "../../src/parse-gram.y"
+#line 228 "parse-gram.y"
     { expected_rr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 14:
-#line 229 "../../src/parse-gram.y"
+#line 229 "parse-gram.y"
     { spec_file_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 15:
-#line 231 "../../src/parse-gram.y"
+#line 231 "parse-gram.y"
     {
       nondeterministic_parser = true;
       glr_parser = true;
@@ -1811,86 +1811,86 @@ yyreduce:
     break;
 
   case 16:
-#line 236 "../../src/parse-gram.y"
+#line 236 "parse-gram.y"
     {
       muscle_code_grow ("initial_action", (yyvsp[(1) - (1)].chars), (yylsp[(1) - (1)]));
     }
     break;
 
   case 17:
-#line 239 "../../src/parse-gram.y"
+#line 239 "parse-gram.y"
     { add_param ("lex_param", (yyvsp[(1) - (1)].chars), (yylsp[(1) - (1)])); }
     break;
 
   case 18:
-#line 240 "../../src/parse-gram.y"
+#line 240 "parse-gram.y"
     { locations_flag = true; }
     break;
 
   case 19:
-#line 241 "../../src/parse-gram.y"
+#line 241 "parse-gram.y"
     { spec_name_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 20:
-#line 242 "../../src/parse-gram.y"
+#line 242 "parse-gram.y"
     { no_lines_flag = true; }
     break;
 
   case 21:
-#line 243 "../../src/parse-gram.y"
+#line 243 "parse-gram.y"
     { nondeterministic_parser = true; }
     break;
 
   case 22:
-#line 244 "../../src/parse-gram.y"
+#line 244 "parse-gram.y"
     { spec_outfile = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 23:
-#line 245 "../../src/parse-gram.y"
+#line 245 "parse-gram.y"
     { add_param ("parse_param", (yyvsp[(1) - (1)].chars), (yylsp[(1) - (1)])); }
     break;
 
   case 24:
-#line 246 "../../src/parse-gram.y"
+#line 246 "parse-gram.y"
     { pure_parser = true; }
     break;
 
   case 25:
-#line 247 "../../src/parse-gram.y"
+#line 247 "parse-gram.y"
     { version_check (&(yylsp[(2) - (2)]), (yyvsp[(2) - (2)].chars)); }
     break;
 
   case 26:
-#line 248 "../../src/parse-gram.y"
+#line 248 "parse-gram.y"
     { skeleton = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 27:
-#line 249 "../../src/parse-gram.y"
+#line 249 "parse-gram.y"
     { token_table_flag = true; }
     break;
 
   case 28:
-#line 250 "../../src/parse-gram.y"
+#line 250 "parse-gram.y"
     { report_flag = report_states; }
     break;
 
   case 29:
-#line 251 "../../src/parse-gram.y"
+#line 251 "parse-gram.y"
     { yacc_flag = true; }
     break;
 
   case 33:
-#line 259 "../../src/parse-gram.y"
+#line 259 "parse-gram.y"
     {
       grammar_start_symbol_set ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]));
     }
     break;
 
   case 34:
-#line 263 "../../src/parse-gram.y"
+#line 263 "parse-gram.y"
     {
       char const *body = (yyvsp[(1) - (1)].chars);
 
@@ -1909,7 +1909,7 @@ yyreduce:
     break;
 
   case 35:
-#line 279 "../../src/parse-gram.y"
+#line 279 "parse-gram.y"
     {
       symbol_list *list;
       for (list = (yyvsp[(2) - (2)].list); list; list = list->next)
@@ -1919,7 +1919,7 @@ yyreduce:
     break;
 
   case 36:
-#line 286 "../../src/parse-gram.y"
+#line 286 "parse-gram.y"
     {
       symbol_list *list;
       for (list = (yyvsp[(2) - (2)].list); list; list = list->next)
@@ -1929,26 +1929,26 @@ yyreduce:
     break;
 
   case 37:
-#line 293 "../../src/parse-gram.y"
+#line 293 "parse-gram.y"
     {
       default_prec = true;
     }
     break;
 
   case 38:
-#line 297 "../../src/parse-gram.y"
+#line 297 "parse-gram.y"
     {
       default_prec = false;
     }
     break;
 
   case 39:
-#line 303 "../../src/parse-gram.y"
+#line 303 "parse-gram.y"
     { current_class = nterm_sym; }
     break;
 
   case 40:
-#line 304 "../../src/parse-gram.y"
+#line 304 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
@@ -1956,12 +1956,12 @@ yyreduce:
     break;
 
   case 41:
-#line 308 "../../src/parse-gram.y"
+#line 308 "parse-gram.y"
     { current_class = token_sym; }
     break;
 
   case 42:
-#line 309 "../../src/parse-gram.y"
+#line 309 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
@@ -1969,7 +1969,7 @@ yyreduce:
     break;
 
   case 43:
-#line 314 "../../src/parse-gram.y"
+#line 314 "parse-gram.y"
     {
       symbol_list *list;
       for (list = (yyvsp[(3) - (3)].list); list; list = list->next)
@@ -1979,7 +1979,7 @@ yyreduce:
     break;
 
   case 44:
-#line 324 "../../src/parse-gram.y"
+#line 324 "parse-gram.y"
     {
       symbol_list *list;
       ++current_prec;
@@ -1994,49 +1994,49 @@ yyreduce:
     break;
 
   case 45:
-#line 338 "../../src/parse-gram.y"
+#line 338 "parse-gram.y"
     { (yyval.assoc) = left_assoc; }
     break;
 
   case 46:
-#line 339 "../../src/parse-gram.y"
+#line 339 "parse-gram.y"
     { (yyval.assoc) = right_assoc; }
     break;
 
   case 47:
-#line 340 "../../src/parse-gram.y"
+#line 340 "parse-gram.y"
     { (yyval.assoc) = non_assoc; }
     break;
 
   case 48:
-#line 344 "../../src/parse-gram.y"
+#line 344 "parse-gram.y"
     { current_type = NULL; }
     break;
 
   case 49:
-#line 345 "../../src/parse-gram.y"
+#line 345 "parse-gram.y"
     { current_type = (yyvsp[(1) - (1)].uniqstr); }
     break;
 
   case 50:
-#line 351 "../../src/parse-gram.y"
+#line 351 "parse-gram.y"
     { (yyval.list) = symbol_list_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 51:
-#line 352 "../../src/parse-gram.y"
+#line 352 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), (yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)])); }
     break;
 
   case 52:
-#line 358 "../../src/parse-gram.y"
+#line 358 "parse-gram.y"
     {
        current_type = (yyvsp[(1) - (1)].uniqstr);
      }
     break;
 
   case 53:
-#line 362 "../../src/parse-gram.y"
+#line 362 "parse-gram.y"
     {
        symbol_class_set ((yyvsp[(1) - (1)].symbol), current_class, (yylsp[(1) - (1)]), true);
        symbol_type_set ((yyvsp[(1) - (1)].symbol), current_type, (yylsp[(1) - (1)]));
@@ -2044,7 +2044,7 @@ yyreduce:
     break;
 
   case 54:
-#line 367 "../../src/parse-gram.y"
+#line 367 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
       symbol_type_set ((yyvsp[(1) - (2)].symbol), current_type, (yylsp[(1) - (2)]));
@@ -2053,7 +2053,7 @@ yyreduce:
     break;
 
   case 55:
-#line 373 "../../src/parse-gram.y"
+#line 373 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
       symbol_type_set ((yyvsp[(1) - (2)].symbol), current_type, (yylsp[(1) - (2)]));
@@ -2062,7 +2062,7 @@ yyreduce:
     break;
 
   case 56:
-#line 379 "../../src/parse-gram.y"
+#line 379 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (3)].symbol), current_class, (yylsp[(1) - (3)]), true);
       symbol_type_set ((yyvsp[(1) - (3)].symbol), current_type, (yylsp[(1) - (3)]));
@@ -2072,69 +2072,69 @@ yyreduce:
     break;
 
   case 63:
-#line 409 "../../src/parse-gram.y"
+#line 409 "parse-gram.y"
     {
       yyerrok;
     }
     break;
 
   case 64:
-#line 415 "../../src/parse-gram.y"
+#line 415 "parse-gram.y"
     { current_lhs = (yyvsp[(1) - (1)].symbol); current_lhs_location = (yylsp[(1) - (1)]); }
     break;
 
   case 66:
-#line 419 "../../src/parse-gram.y"
+#line 419 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(1) - (1)])); }
     break;
 
   case 67:
-#line 420 "../../src/parse-gram.y"
+#line 420 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(3) - (3)])); }
     break;
 
   case 69:
-#line 426 "../../src/parse-gram.y"
+#line 426 "parse-gram.y"
     { grammar_current_rule_begin (current_lhs, current_lhs_location); }
     break;
 
   case 70:
-#line 428 "../../src/parse-gram.y"
+#line 428 "parse-gram.y"
     { grammar_current_rule_symbol_append ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)])); }
     break;
 
   case 72:
-#line 431 "../../src/parse-gram.y"
+#line 431 "parse-gram.y"
     { grammar_current_rule_prec_set ((yyvsp[(3) - (3)].symbol), (yylsp[(3) - (3)])); }
     break;
 
   case 73:
-#line 433 "../../src/parse-gram.y"
+#line 433 "parse-gram.y"
     { grammar_current_rule_dprec_set ((yyvsp[(3) - (3)].integer), (yylsp[(3) - (3)])); }
     break;
 
   case 74:
-#line 435 "../../src/parse-gram.y"
+#line 435 "parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[(3) - (3)].uniqstr), (yylsp[(3) - (3)])); }
     break;
 
   case 75:
-#line 439 "../../src/parse-gram.y"
+#line 439 "parse-gram.y"
     { (yyval.symbol) = (yyvsp[(1) - (1)].symbol); }
     break;
 
   case 76:
-#line 440 "../../src/parse-gram.y"
+#line 440 "parse-gram.y"
     { (yyval.symbol) = (yyvsp[(1) - (1)].symbol); }
     break;
 
   case 77:
-#line 456 "../../src/parse-gram.y"
+#line 456 "parse-gram.y"
     { grammar_current_rule_action_append (last_string, last_braced_code_loc); }
     break;
 
   case 79:
-#line 463 "../../src/parse-gram.y"
+#line 463 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[(1) - (1)].chars)), (yylsp[(1) - (1)]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[(1) - (1)]), false);
@@ -2142,12 +2142,12 @@ yyreduce:
     break;
 
   case 80:
-#line 472 "../../src/parse-gram.y"
+#line 472 "parse-gram.y"
     { (yyval.chars) = (yyvsp[(1) - (1)].chars); }
     break;
 
   case 82:
-#line 479 "../../src/parse-gram.y"
+#line 479 "parse-gram.y"
     {
       muscle_code_grow ("epilogue", (yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)]));
       scanner_last_string_free ();
@@ -2156,7 +2156,7 @@ yyreduce:
 
 
 /* Line 1267 of yacc.c.  */
-#line 2160 "../../src/parse-gram.c"
+#line 2160 "parse-gram.c"
       default: break;
     }
   YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);
@@ -2375,7 +2375,7 @@ yyreturn:
 }
 
 
-#line 485 "../../src/parse-gram.y"
+#line 485 "parse-gram.y"
 
 
 
