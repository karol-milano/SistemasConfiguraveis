@@ -69,7 +69,8 @@
 #define yylloc gram_lloc
 
 /* Copy the first part of user declarations.  */
-#line 1 "parse-gram.y"
+/* Line 164 of yacc.c.  */
+#line 1 "../../src/parse-gram.y"
 /* Bison Grammar Parser                             -*- C -*-
 
    Copyright (C) 2002, 2003, 2004, 2005, 2006 Free Software Foundation, Inc.
@@ -291,7 +292,8 @@ static int current_prec = 0;
 
 #if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
 typedef union YYSTYPE
-#line 97 "parse-gram.y"
+/* Line 195 of yacc.c.  */
+#line 97 "../../src/parse-gram.y"
 {
   symbol *symbol;
   symbol_list *list;
@@ -301,8 +303,8 @@ typedef union YYSTYPE
   uniqstr uniqstr;
   unsigned char character;
 }
-/* Line 197 of yacc.c.  */
-#line 306 "parse-gram.c"
+/* Line 195 of yacc.c.  */
+#line 308 "../../src/parse-gram.c"
 	YYSTYPE;
 # define yystype YYSTYPE /* obsolescent; will be withdrawn */
 # define YYSTYPE_IS_DECLARED 1
@@ -325,9 +327,8 @@ typedef struct YYLTYPE
 
 /* Copy the second part of user declarations.  */
 
-
-/* Line __line__ of yacc.c.  */
-#line 331 "parse-gram.c"
+/* Line 219 of yacc.c.  */
+#line 332 "../../src/parse-gram.c"
 
 #ifdef short
 # undef short
@@ -1003,74 +1004,102 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
   switch (yytype)
     {
       case 3: /* "\"string\"" */
-#line 181 "parse-gram.y"
+/* Line 668 of yacc.c.  */
+#line 181 "../../src/parse-gram.y"
 	{ fputs (quotearg_style (c_quoting_style, (yyvaluep->chars)), stderr); };
-#line 1009 "parse-gram.c"
+/* Line 668 of yacc.c.  */
+#line 1012 "../../src/parse-gram.c"
 	break;
       case 4: /* "\"integer\"" */
-#line 191 "parse-gram.y"
+/* Line 668 of yacc.c.  */
+#line 191 "../../src/parse-gram.y"
 	{ fprintf (stderr, "%d", (yyvaluep->integer)); };
-#line 1014 "parse-gram.c"
+/* Line 668 of yacc.c.  */
+#line 1019 "../../src/parse-gram.c"
 	break;
       case 45: /* "\"{...}\"" */
-#line 183 "parse-gram.y"
+/* Line 668 of yacc.c.  */
+#line 183 "../../src/parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1019 "parse-gram.c"
+/* Line 668 of yacc.c.  */
+#line 1026 "../../src/parse-gram.c"
 	break;
       case 46: /* "\"char\"" */
-#line 178 "parse-gram.y"
+/* Line 668 of yacc.c.  */
+#line 178 "../../src/parse-gram.y"
 	{ fputs (char_name ((yyvaluep->character)), stderr); };
-#line 1024 "parse-gram.c"
+/* Line 668 of yacc.c.  */
+#line 1033 "../../src/parse-gram.c"
 	break;
       case 47: /* "\"epilogue\"" */
-#line 183 "parse-gram.y"
+/* Line 668 of yacc.c.  */
+#line 183 "../../src/parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1029 "parse-gram.c"
+/* Line 668 of yacc.c.  */
+#line 1040 "../../src/parse-gram.c"
 	break;
       case 49: /* "\"identifier\"" */
-#line 187 "parse-gram.y"
+/* Line 668 of yacc.c.  */
+#line 187 "../../src/parse-gram.y"
 	{ fputs ((yyvaluep->uniqstr), stderr); };
-#line 1034 "parse-gram.c"
+/* Line 668 of yacc.c.  */
+#line 1047 "../../src/parse-gram.c"
 	break;
       case 50: /* "\"identifier:\"" */
-#line 188 "parse-gram.y"
+/* Line 668 of yacc.c.  */
+#line 188 "../../src/parse-gram.y"
 	{ fprintf (stderr, "%s:", (yyvaluep->uniqstr)); };
-#line 1039 "parse-gram.c"
+/* Line 668 of yacc.c.  */
+#line 1054 "../../src/parse-gram.c"
 	break;
       case 53: /* "\"%{...%}\"" */
-#line 183 "parse-gram.y"
+/* Line 668 of yacc.c.  */
+#line 183 "../../src/parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1044 "parse-gram.c"
+/* Line 668 of yacc.c.  */
+#line 1061 "../../src/parse-gram.c"
 	break;
       case 55: /* "\"type\"" */
-#line 186 "parse-gram.y"
+/* Line 668 of yacc.c.  */
+#line 186 "../../src/parse-gram.y"
 	{ fprintf (stderr, "<%s>", (yyvaluep->uniqstr)); };
-#line 1049 "parse-gram.c"
+/* Line 668 of yacc.c.  */
+#line 1068 "../../src/parse-gram.c"
 	break;
       case 78: /* "id" */
-#line 194 "parse-gram.y"
+/* Line 668 of yacc.c.  */
+#line 194 "../../src/parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
-#line 1054 "parse-gram.c"
+/* Line 668 of yacc.c.  */
+#line 1075 "../../src/parse-gram.c"
 	break;
       case 79: /* "id_colon" */
-#line 195 "parse-gram.y"
+/* Line 668 of yacc.c.  */
+#line 195 "../../src/parse-gram.y"
 	{ fprintf (stderr, "%s:", (yyvaluep->symbol)->tag); };
-#line 1059 "parse-gram.c"
+/* Line 668 of yacc.c.  */
+#line 1082 "../../src/parse-gram.c"
 	break;
       case 80: /* "symbol" */
-#line 194 "parse-gram.y"
+/* Line 668 of yacc.c.  */
+#line 194 "../../src/parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
-#line 1064 "parse-gram.c"
+/* Line 668 of yacc.c.  */
+#line 1089 "../../src/parse-gram.c"
 	break;
       case 81: /* "string_as_id" */
-#line 194 "parse-gram.y"
+/* Line 668 of yacc.c.  */
+#line 194 "../../src/parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
-#line 1069 "parse-gram.c"
+/* Line 668 of yacc.c.  */
+#line 1096 "../../src/parse-gram.c"
 	break;
       case 82: /* "string_content" */
-#line 181 "parse-gram.y"
+/* Line 668 of yacc.c.  */
+#line 181 "../../src/parse-gram.y"
 	{ fputs (quotearg_style (c_quoting_style, (yyvaluep->chars)), stderr); };
-#line 1074 "parse-gram.c"
+/* Line 668 of yacc.c.  */
+#line 1103 "../../src/parse-gram.c"
 	break;
       default:
 	break;
@@ -1580,15 +1609,16 @@ YYLTYPE yylloc;
 
 
   /* User initialization code.  */
-#line 88 "parse-gram.y"
+  /* Line 1077 of yacc.c.  */
+#line 88 "../../src/parse-gram.y"
 {
   /* Bison's grammar can initial empty locations, hence a default
      location is needed. */
   boundary_set (&yylloc.start, current_file, 1, 1);
   boundary_set (&yylloc.end, current_file, 1, 1);
 }
-/* Line 1085 of yacc.c.  */
-#line 1592 "parse-gram.c"
+/* Line 1077 of yacc.c.  */
+#line 1622 "../../src/parse-gram.c"
   yylsp[0] = yylloc;
   goto yysetstate;
 
@@ -1773,14 +1803,16 @@ yyreduce:
   switch (yyn)
     {
         case 6:
-#line 218 "parse-gram.y"
+/* Line 1265 of yacc.c.  */
+#line 218 "../../src/parse-gram.y"
     {
       prologue_augment (translate_code ((yyvsp[(1) - (1)].chars), (yylsp[(1) - (1)])), (yylsp[(1) - (1)]), typed);
     }
     break;
 
   case 7:
-#line 222 "parse-gram.y"
+/* Line 1265 of yacc.c.  */
+#line 222 "../../src/parse-gram.y"
     {
       /* Remove the '{', and replace the '}' with '\n'.  */
       (yyvsp[(2) - (2)].chars)[strlen ((yyvsp[(2) - (2)].chars)) - 1] = '\n';
@@ -1789,7 +1821,8 @@ yyreduce:
     break;
 
   case 8:
-#line 228 "parse-gram.y"
+/* Line 1265 of yacc.c.  */
+#line 228 "../../src/parse-gram.y"
     {
       /* Remove the '{', and replace the '}' with '\n'.  */
       (yyvsp[(2) - (2)].chars)[strlen ((yyvsp[(2) - (2)].chars)) - 1] = '\n';
@@ -1798,12 +1831,14 @@ yyreduce:
     break;
 
   case 9:
-#line 233 "parse-gram.y"
+/* Line 1265 of yacc.c.  */
+#line 233 "../../src/parse-gram.y"
     { debug_flag = true; }
     break;
 
   case 10:
-#line 235 "parse-gram.y"
+/* Line 1265 of yacc.c.  */
+#line 235 "../../src/parse-gram.y"
     {
       static char one[] = "1";
       muscle_insert ((yyvsp[(2) - (2)].chars), one);
@@ -1811,17 +1846,20 @@ yyreduce:
     break;
 
   case 11:
-#line 239 "parse-gram.y"
+/* Line 1265 of yacc.c.  */
+#line 239 "../../src/parse-gram.y"
     { muscle_insert ((yyvsp[(2) - (3)].chars), (yyvsp[(3) - (3)].chars)); }
     break;
 
   case 12:
-#line 240 "parse-gram.y"
+/* Line 1265 of yacc.c.  */
+#line 240 "../../src/parse-gram.y"
     { defines_flag = true; }
     break;
 
   case 13:
-#line 242 "parse-gram.y"
+/* Line 1265 of yacc.c.  */
+#line 242 "../../src/parse-gram.y"
     {
       /* Remove the '{', and replace the '}' with '\n'.  */
       (yyvsp[(2) - (2)].chars)[strlen ((yyvsp[(2) - (2)].chars)) - 1] = '\n';
@@ -1830,27 +1868,32 @@ yyreduce:
     break;
 
   case 14:
-#line 247 "parse-gram.y"
+/* Line 1265 of yacc.c.  */
+#line 247 "../../src/parse-gram.y"
     { error_verbose = true; }
     break;
 
   case 15:
-#line 248 "parse-gram.y"
+/* Line 1265 of yacc.c.  */
+#line 248 "../../src/parse-gram.y"
     { expected_sr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 16:
-#line 249 "parse-gram.y"
+/* Line 1265 of yacc.c.  */
+#line 249 "../../src/parse-gram.y"
     { expected_rr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 17:
-#line 250 "parse-gram.y"
+/* Line 1265 of yacc.c.  */
+#line 250 "../../src/parse-gram.y"
     { spec_file_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 18:
-#line 252 "parse-gram.y"
+/* Line 1265 of yacc.c.  */
+#line 252 "../../src/parse-gram.y"
     {
       nondeterministic_parser = true;
       glr_parser = true;
@@ -1858,64 +1901,76 @@ yyreduce:
     break;
 
   case 19:
-#line 257 "parse-gram.y"
+/* Line 1265 of yacc.c.  */
+#line 257 "../../src/parse-gram.y"
     {
       muscle_code_grow ("initial_action", translate_symbol_action ((yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])), (yylsp[(2) - (2)]));
     }
     break;
 
   case 20:
-#line 260 "parse-gram.y"
+/* Line 1265 of yacc.c.  */
+#line 260 "../../src/parse-gram.y"
     { add_param ("lex_param", (yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])); }
     break;
 
   case 21:
-#line 261 "parse-gram.y"
+/* Line 1265 of yacc.c.  */
+#line 261 "../../src/parse-gram.y"
     { locations_flag = true; }
     break;
 
   case 22:
-#line 262 "parse-gram.y"
+/* Line 1265 of yacc.c.  */
+#line 262 "../../src/parse-gram.y"
     { spec_name_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 23:
-#line 263 "parse-gram.y"
+/* Line 1265 of yacc.c.  */
+#line 263 "../../src/parse-gram.y"
     { no_lines_flag = true; }
     break;
 
   case 24:
-#line 264 "parse-gram.y"
+/* Line 1265 of yacc.c.  */
+#line 264 "../../src/parse-gram.y"
     { nondeterministic_parser = true; }
     break;
 
   case 25:
-#line 265 "parse-gram.y"
+/* Line 1265 of yacc.c.  */
+#line 265 "../../src/parse-gram.y"
     { spec_outfile = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 26:
-#line 266 "parse-gram.y"
+/* Line 1265 of yacc.c.  */
+#line 266 "../../src/parse-gram.y"
     { add_param ("parse_param", (yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])); }
     break;
 
   case 27:
-#line 267 "parse-gram.y"
+/* Line 1265 of yacc.c.  */
+#line 267 "../../src/parse-gram.y"
     { pure_parser = true; }
     break;
 
   case 28:
-#line 268 "parse-gram.y"
+/* Line 1265 of yacc.c.  */
+#line 268 "../../src/parse-gram.y"
     { version_check (&(yylsp[(2) - (2)]), (yyvsp[(2) - (2)].chars)); }
     break;
 
   case 29:
-#line 269 "parse-gram.y"
+/* Line 1265 of yacc.c.  */
+#line 269 "../../src/parse-gram.y"
     { skeleton = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 30:
-#line 271 "parse-gram.y"
+/* Line 1265 of yacc.c.  */
+#line 271 "../../src/parse-gram.y"
     {
       /* Remove the '{', and replace the '}' with '\n'.  */
       (yyvsp[(2) - (2)].chars)[strlen ((yyvsp[(2) - (2)].chars)) - 1] = '\n';
@@ -1924,29 +1979,34 @@ yyreduce:
     break;
 
   case 31:
-#line 276 "parse-gram.y"
+/* Line 1265 of yacc.c.  */
+#line 276 "../../src/parse-gram.y"
     { token_table_flag = true; }
     break;
 
   case 32:
-#line 277 "parse-gram.y"
+/* Line 1265 of yacc.c.  */
+#line 277 "../../src/parse-gram.y"
     { report_flag = report_states; }
     break;
 
   case 33:
-#line 278 "parse-gram.y"
+/* Line 1265 of yacc.c.  */
+#line 278 "../../src/parse-gram.y"
     { yacc_flag = true; }
     break;
 
   case 37:
-#line 286 "parse-gram.y"
+/* Line 1265 of yacc.c.  */
+#line 286 "../../src/parse-gram.y"
     {
       grammar_start_symbol_set ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]));
     }
     break;
 
   case 38:
-#line 290 "parse-gram.y"
+/* Line 1265 of yacc.c.  */
+#line 290 "../../src/parse-gram.y"
     {
       symbol_list *list;
       const char *action = translate_symbol_action ((yyvsp[(2) - (3)].chars), (yylsp[(2) - (3)]));
@@ -1957,7 +2017,8 @@ yyreduce:
     break;
 
   case 39:
-#line 298 "parse-gram.y"
+/* Line 1265 of yacc.c.  */
+#line 298 "../../src/parse-gram.y"
     {
       symbol_list *list;
       const char *action = translate_symbol_action ((yyvsp[(2) - (3)].chars), (yylsp[(2) - (3)]));
@@ -1968,31 +2029,36 @@ yyreduce:
     break;
 
   case 40:
-#line 306 "parse-gram.y"
+/* Line 1265 of yacc.c.  */
+#line 306 "../../src/parse-gram.y"
     {
       default_prec = true;
     }
     break;
 
   case 41:
-#line 310 "parse-gram.y"
+/* Line 1265 of yacc.c.  */
+#line 310 "../../src/parse-gram.y"
     {
       default_prec = false;
     }
     break;
 
   case 42:
-#line 323 "parse-gram.y"
+/* Line 1265 of yacc.c.  */
+#line 323 "../../src/parse-gram.y"
     {}
     break;
 
   case 43:
-#line 324 "parse-gram.y"
+/* Line 1265 of yacc.c.  */
+#line 324 "../../src/parse-gram.y"
     { muscle_code_grow ("union_name", (yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 44:
-#line 329 "parse-gram.y"
+/* Line 1265 of yacc.c.  */
+#line 329 "../../src/parse-gram.y"
     {
       char const *body = (yyvsp[(3) - (3)].chars);
 
@@ -2011,12 +2077,14 @@ yyreduce:
     break;
 
   case 45:
-#line 350 "parse-gram.y"
+/* Line 1265 of yacc.c.  */
+#line 350 "../../src/parse-gram.y"
     { current_class = nterm_sym; }
     break;
 
   case 46:
-#line 351 "parse-gram.y"
+/* Line 1265 of yacc.c.  */
+#line 351 "../../src/parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
@@ -2024,12 +2092,14 @@ yyreduce:
     break;
 
   case 47:
-#line 355 "parse-gram.y"
+/* Line 1265 of yacc.c.  */
+#line 355 "../../src/parse-gram.y"
     { current_class = token_sym; }
     break;
 
   case 48:
-#line 356 "parse-gram.y"
+/* Line 1265 of yacc.c.  */
+#line 356 "../../src/parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
@@ -2037,7 +2107,8 @@ yyreduce:
     break;
 
   case 49:
-#line 361 "parse-gram.y"
+/* Line 1265 of yacc.c.  */
+#line 361 "../../src/parse-gram.y"
     {
       symbol_list *list;
       for (list = (yyvsp[(3) - (3)].list); list; list = list->next)
@@ -2047,7 +2118,8 @@ yyreduce:
     break;
 
   case 50:
-#line 371 "parse-gram.y"
+/* Line 1265 of yacc.c.  */
+#line 371 "../../src/parse-gram.y"
     {
       symbol_list *list;
       ++current_prec;
@@ -2062,49 +2134,58 @@ yyreduce:
     break;
 
   case 51:
-#line 385 "parse-gram.y"
+/* Line 1265 of yacc.c.  */
+#line 385 "../../src/parse-gram.y"
     { (yyval.assoc) = left_assoc; }
     break;
 
   case 52:
-#line 386 "parse-gram.y"
+/* Line 1265 of yacc.c.  */
+#line 386 "../../src/parse-gram.y"
     { (yyval.assoc) = right_assoc; }
     break;
 
   case 53:
-#line 387 "parse-gram.y"
+/* Line 1265 of yacc.c.  */
+#line 387 "../../src/parse-gram.y"
     { (yyval.assoc) = non_assoc; }
     break;
 
   case 54:
-#line 391 "parse-gram.y"
+/* Line 1265 of yacc.c.  */
+#line 391 "../../src/parse-gram.y"
     { current_type = NULL; }
     break;
 
   case 55:
-#line 392 "parse-gram.y"
+/* Line 1265 of yacc.c.  */
+#line 392 "../../src/parse-gram.y"
     { current_type = (yyvsp[(1) - (1)].uniqstr); }
     break;
 
   case 56:
-#line 397 "parse-gram.y"
+/* Line 1265 of yacc.c.  */
+#line 397 "../../src/parse-gram.y"
     { (yyval.list) = symbol_list_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 57:
-#line 398 "parse-gram.y"
+/* Line 1265 of yacc.c.  */
+#line 398 "../../src/parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), (yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)])); }
     break;
 
   case 58:
-#line 404 "parse-gram.y"
+/* Line 1265 of yacc.c.  */
+#line 404 "../../src/parse-gram.y"
     {
        current_type = (yyvsp[(1) - (1)].uniqstr);
      }
     break;
 
   case 59:
-#line 408 "parse-gram.y"
+/* Line 1265 of yacc.c.  */
+#line 408 "../../src/parse-gram.y"
     {
        symbol_class_set ((yyvsp[(1) - (1)].symbol), current_class, (yylsp[(1) - (1)]), true);
        symbol_type_set ((yyvsp[(1) - (1)].symbol), current_type, (yylsp[(1) - (1)]));
@@ -2112,7 +2193,8 @@ yyreduce:
     break;
 
   case 60:
-#line 413 "parse-gram.y"
+/* Line 1265 of yacc.c.  */
+#line 413 "../../src/parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
       symbol_type_set ((yyvsp[(1) - (2)].symbol), current_type, (yylsp[(1) - (2)]));
@@ -2121,7 +2203,8 @@ yyreduce:
     break;
 
   case 61:
-#line 419 "parse-gram.y"
+/* Line 1265 of yacc.c.  */
+#line 419 "../../src/parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
       symbol_type_set ((yyvsp[(1) - (2)].symbol), current_type, (yylsp[(1) - (2)]));
@@ -2130,7 +2213,8 @@ yyreduce:
     break;
 
   case 62:
-#line 425 "parse-gram.y"
+/* Line 1265 of yacc.c.  */
+#line 425 "../../src/parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (3)].symbol), current_class, (yylsp[(1) - (3)]), true);
       symbol_type_set ((yyvsp[(1) - (3)].symbol), current_type, (yylsp[(1) - (3)]));
@@ -2140,64 +2224,76 @@ yyreduce:
     break;
 
   case 69:
-#line 455 "parse-gram.y"
+/* Line 1265 of yacc.c.  */
+#line 455 "../../src/parse-gram.y"
     {
       yyerrok;
     }
     break;
 
   case 70:
-#line 461 "parse-gram.y"
+/* Line 1265 of yacc.c.  */
+#line 461 "../../src/parse-gram.y"
     { current_lhs = (yyvsp[(1) - (1)].symbol); current_lhs_location = (yylsp[(1) - (1)]); }
     break;
 
   case 72:
-#line 465 "parse-gram.y"
+/* Line 1265 of yacc.c.  */
+#line 465 "../../src/parse-gram.y"
     { grammar_current_rule_end ((yylsp[(1) - (1)])); }
     break;
 
   case 73:
-#line 466 "parse-gram.y"
+/* Line 1265 of yacc.c.  */
+#line 466 "../../src/parse-gram.y"
     { grammar_current_rule_end ((yylsp[(3) - (3)])); }
     break;
 
   case 75:
-#line 472 "parse-gram.y"
+/* Line 1265 of yacc.c.  */
+#line 472 "../../src/parse-gram.y"
     { grammar_current_rule_begin (current_lhs, current_lhs_location); }
     break;
 
   case 76:
-#line 474 "parse-gram.y"
+/* Line 1265 of yacc.c.  */
+#line 474 "../../src/parse-gram.y"
     { grammar_current_rule_symbol_append ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)])); }
     break;
 
   case 77:
-#line 476 "parse-gram.y"
+/* Line 1265 of yacc.c.  */
+#line 476 "../../src/parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])); }
     break;
 
   case 78:
-#line 478 "parse-gram.y"
+/* Line 1265 of yacc.c.  */
+#line 478 "../../src/parse-gram.y"
     { grammar_current_rule_prec_set ((yyvsp[(3) - (3)].symbol), (yylsp[(3) - (3)])); }
     break;
 
   case 79:
-#line 480 "parse-gram.y"
+/* Line 1265 of yacc.c.  */
+#line 480 "../../src/parse-gram.y"
     { grammar_current_rule_dprec_set ((yyvsp[(3) - (3)].integer), (yylsp[(3) - (3)])); }
     break;
 
   case 80:
-#line 482 "parse-gram.y"
+/* Line 1265 of yacc.c.  */
+#line 482 "../../src/parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[(3) - (3)].uniqstr), (yylsp[(3) - (3)])); }
     break;
 
   case 81:
-#line 495 "parse-gram.y"
+/* Line 1265 of yacc.c.  */
+#line 495 "../../src/parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 82:
-#line 497 "parse-gram.y"
+/* Line 1265 of yacc.c.  */
+#line 497 "../../src/parse-gram.y"
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[(1) - (1)].character)), (yylsp[(1) - (1)]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[(1) - (1)]), false);
@@ -2206,12 +2302,14 @@ yyreduce:
     break;
 
   case 83:
-#line 505 "parse-gram.y"
+/* Line 1265 of yacc.c.  */
+#line 505 "../../src/parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 86:
-#line 517 "parse-gram.y"
+/* Line 1265 of yacc.c.  */
+#line 517 "../../src/parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[(1) - (1)].chars)), (yylsp[(1) - (1)]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[(1) - (1)]), false);
@@ -2219,12 +2317,14 @@ yyreduce:
     break;
 
   case 87:
-#line 526 "parse-gram.y"
+/* Line 1265 of yacc.c.  */
+#line 526 "../../src/parse-gram.y"
     { (yyval.chars) = (yyvsp[(1) - (1)].chars); }
     break;
 
   case 89:
-#line 533 "parse-gram.y"
+/* Line 1265 of yacc.c.  */
+#line 533 "../../src/parse-gram.y"
     {
       muscle_code_grow ("epilogue", translate_code ((yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])), (yylsp[(2) - (2)]));
       gram_scanner_last_string_free ();
@@ -2232,8 +2332,8 @@ yyreduce:
     break;
 
 
-/* Line 1274 of yacc.c.  */
-#line 2237 "parse-gram.c"
+/* Line 1265 of yacc.c.  */
+#line 2337 "../../src/parse-gram.c"
       default: break;
     }
   YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);
@@ -2453,7 +2553,8 @@ yyreturn:
 }
 
 
-#line 539 "parse-gram.y"
+/* Line 1485 of yacc.c.  */
+#line 539 "../../src/parse-gram.y"
 
 
 
