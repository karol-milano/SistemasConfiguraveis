@@ -196,6 +196,7 @@
    02110-1301  USA
 */
 
+#include <config.h>
 #include "system.h"
 
 #include "complain.h"
@@ -253,7 +254,7 @@ static int current_prec = 0;
 #endif
 
 #if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
-#line 81 "parse-gram.y"
+#line 82 "parse-gram.y"
 typedef union YYSTYPE {
   symbol *symbol;
   symbol_list *list;
@@ -263,7 +264,7 @@ typedef union YYSTYPE {
   uniqstr uniqstr;
 } YYSTYPE;
 /* Line 197 of yacc.c.  */
-#line 267 "parse-gram.c"
+#line 268 "parse-gram.c"
 # define yystype YYSTYPE /* obsolescent; will be withdrawn */
 # define YYSTYPE_IS_DECLARED 1
 # define YYSTYPE_IS_TRIVIAL 1
@@ -287,7 +288,7 @@ typedef struct YYLTYPE
 
 
 /* Line 220 of yacc.c.  */
-#line 291 "parse-gram.c"
+#line 292 "parse-gram.c"
 
 /* Define YYMODERN_C if this compiler supports C89 or better.  If
    __STDC__ is defined, the compiler is modern.  IBM xlc 7.0 when run
@@ -584,15 +585,15 @@ static const yysigned_char yyrhs[] =
 /* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
 static const unsigned short int yyrline[] =
 {
-       0,   191,   191,   199,   201,   205,   206,   207,   208,   209,
-     210,   211,   212,   213,   214,   215,   220,   224,   225,   226,
-     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
-     237,   241,   242,   243,   247,   253,   260,   267,   271,   278,
-     278,   283,   283,   288,   298,   313,   314,   315,   319,   320,
-     326,   327,   332,   336,   341,   347,   353,   364,   365,   374,
-     375,   381,   382,   387,   394,   394,   398,   399,   400,   405,
-     406,   408,   410,   412,   414,   419,   420,   424,   430,   439,
-     444,   446
+       0,   192,   192,   200,   202,   206,   207,   208,   209,   210,
+     211,   212,   213,   214,   215,   216,   221,   225,   226,   227,
+     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
+     238,   242,   243,   244,   248,   254,   261,   268,   272,   279,
+     279,   284,   284,   289,   299,   314,   315,   316,   320,   321,
+     327,   328,   333,   337,   342,   348,   354,   365,   366,   375,
+     376,   382,   383,   388,   395,   395,   399,   400,   401,   406,
+     407,   409,   411,   413,   415,   420,   421,   425,   431,   440,
+     445,   447
 };
 #endif
 
@@ -930,94 +931,94 @@ yysymprint (yyoutput, yytype, yyvaluep, yylocationp)
   switch (yytype)
     {
       case 3: /* "\"string\"" */
-#line 168 "parse-gram.y"
+#line 169 "parse-gram.y"
         { fprintf (stderr, "\"%s\"", (yyvaluep->chars)); };
-#line 936 "parse-gram.c"
+#line 937 "parse-gram.c"
         break;
       case 4: /* "\"integer\"" */
-#line 181 "parse-gram.y"
+#line 182 "parse-gram.y"
         { fprintf (stderr, "%d", (yyvaluep->integer)); };
-#line 941 "parse-gram.c"
+#line 942 "parse-gram.c"
         break;
       case 8: /* "\"%destructor {...}\"" */
-#line 170 "parse-gram.y"
+#line 171 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 946 "parse-gram.c"
+#line 947 "parse-gram.c"
         break;
       case 9: /* "\"%printer {...}\"" */
-#line 174 "parse-gram.y"
+#line 175 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 951 "parse-gram.c"
+#line 952 "parse-gram.c"
         break;
       case 10: /* "\"%union {...}\"" */
-#line 175 "parse-gram.y"
+#line 176 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 956 "parse-gram.c"
+#line 957 "parse-gram.c"
         break;
       case 26: /* "\"%initial-action {...}\"" */
-#line 171 "parse-gram.y"
+#line 172 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 961 "parse-gram.c"
+#line 962 "parse-gram.c"
         break;
       case 27: /* "\"%lex-param {...}\"" */
-#line 172 "parse-gram.y"
+#line 173 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 966 "parse-gram.c"
+#line 967 "parse-gram.c"
         break;
       case 34: /* "\"%parse-param {...}\"" */
-#line 173 "parse-gram.y"
+#line 174 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 971 "parse-gram.c"
+#line 972 "parse-gram.c"
         break;
       case 42: /* "\"type\"" */
-#line 179 "parse-gram.y"
+#line 180 "parse-gram.y"
         { fprintf (stderr, "<%s>", (yyvaluep->uniqstr)); };
-#line 976 "parse-gram.c"
+#line 977 "parse-gram.c"
         break;
       case 46: /* "\"identifier\"" */
-#line 183 "parse-gram.y"
+#line 184 "parse-gram.y"
         { fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
-#line 981 "parse-gram.c"
+#line 982 "parse-gram.c"
         break;
       case 47: /* "\"identifier:\"" */
-#line 185 "parse-gram.y"
+#line 186 "parse-gram.y"
         { fprintf (stderr, "%s:", (yyvaluep->symbol)->tag); };
-#line 986 "parse-gram.c"
+#line 987 "parse-gram.c"
         break;
       case 49: /* "\"%{...%}\"" */
-#line 177 "parse-gram.y"
+#line 178 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 991 "parse-gram.c"
+#line 992 "parse-gram.c"
         break;
       case 50: /* "\"epilogue\"" */
-#line 177 "parse-gram.y"
+#line 178 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 996 "parse-gram.c"
+#line 997 "parse-gram.c"
         break;
       case 51: /* "\"{...}\"" */
-#line 176 "parse-gram.y"
+#line 177 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1001 "parse-gram.c"
+#line 1002 "parse-gram.c"
         break;
       case 72: /* "symbol" */
-#line 183 "parse-gram.y"
+#line 184 "parse-gram.y"
         { fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
-#line 1006 "parse-gram.c"
+#line 1007 "parse-gram.c"
         break;
       case 73: /* "action" */
-#line 176 "parse-gram.y"
+#line 177 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1011 "parse-gram.c"
+#line 1012 "parse-gram.c"
         break;
       case 74: /* "string_as_id" */
-#line 183 "parse-gram.y"
+#line 184 "parse-gram.y"
         { fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
-#line 1016 "parse-gram.c"
+#line 1017 "parse-gram.c"
         break;
       case 75: /* "string_content" */
-#line 168 "parse-gram.y"
+#line 169 "parse-gram.y"
         { fprintf (stderr, "\"%s\"", (yyvaluep->chars)); };
-#line 1021 "parse-gram.c"
+#line 1022 "parse-gram.c"
         break;
       default:
         break;
@@ -1489,7 +1490,7 @@ YYLTYPE yylloc;
 
 
   /* User initialization code. */
-#line 71 "parse-gram.y"
+#line 72 "parse-gram.y"
 {
   /* Bison's grammar can initial empty locations, hence a default
      location is needed. */
@@ -1498,7 +1499,7 @@ YYLTYPE yylloc;
   yylloc.start.column = yylloc.end.column = 0;
 }
 /* Line 1088 of yacc.c.  */
-#line 1502 "parse-gram.c"
+#line 1503 "parse-gram.c"
   yylsp[0] = yylloc;
   goto yysetstate;
 
@@ -1687,52 +1688,52 @@ yyreduce:
   switch (yyn)
     {
         case 6:
-#line 206 "parse-gram.y"
+#line 207 "parse-gram.y"
     { prologue_augment ((yyvsp[(1) - (1)].chars), (yylsp[(1) - (1)])); }
     break;
 
   case 7:
-#line 207 "parse-gram.y"
+#line 208 "parse-gram.y"
     { debug_flag = true; }
     break;
 
   case 8:
-#line 208 "parse-gram.y"
+#line 209 "parse-gram.y"
     { muscle_insert ((yyvsp[(2) - (2)].chars), "1"); }
     break;
 
   case 9:
-#line 209 "parse-gram.y"
+#line 210 "parse-gram.y"
     { muscle_insert ((yyvsp[(2) - (3)].chars), (yyvsp[(3) - (3)].chars)); }
     break;
 
   case 10:
-#line 210 "parse-gram.y"
+#line 211 "parse-gram.y"
     { defines_flag = true; }
     break;
 
   case 11:
-#line 211 "parse-gram.y"
+#line 212 "parse-gram.y"
     { error_verbose = true; }
     break;
 
   case 12:
-#line 212 "parse-gram.y"
+#line 213 "parse-gram.y"
     { expected_sr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 13:
-#line 213 "parse-gram.y"
+#line 214 "parse-gram.y"
     { expected_rr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 14:
-#line 214 "parse-gram.y"
+#line 215 "parse-gram.y"
     { spec_file_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 15:
-#line 216 "parse-gram.y"
+#line 217 "parse-gram.y"
     {
     nondeterministic_parser = true;
     glr_parser = true;
@@ -1740,86 +1741,86 @@ yyreduce:
     break;
 
   case 16:
-#line 221 "parse-gram.y"
+#line 222 "parse-gram.y"
     {
     muscle_code_grow ("initial_action", (yyvsp[(1) - (1)].chars), (yylsp[(1) - (1)]));
   }
     break;
 
   case 17:
-#line 224 "parse-gram.y"
+#line 225 "parse-gram.y"
     { add_param ("lex_param", (yyvsp[(1) - (1)].chars), (yylsp[(1) - (1)])); }
     break;
 
   case 18:
-#line 225 "parse-gram.y"
+#line 226 "parse-gram.y"
     { locations_flag = true; }
     break;
 
   case 19:
-#line 226 "parse-gram.y"
+#line 227 "parse-gram.y"
     { spec_name_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 20:
-#line 227 "parse-gram.y"
+#line 228 "parse-gram.y"
     { no_lines_flag = true; }
     break;
 
   case 21:
-#line 228 "parse-gram.y"
+#line 229 "parse-gram.y"
     { nondeterministic_parser = true; }
     break;
 
   case 22:
-#line 229 "parse-gram.y"
+#line 230 "parse-gram.y"
     { spec_outfile = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 23:
-#line 230 "parse-gram.y"
+#line 231 "parse-gram.y"
     { add_param ("parse_param", (yyvsp[(1) - (1)].chars), (yylsp[(1) - (1)])); }
     break;
 
   case 24:
-#line 231 "parse-gram.y"
+#line 232 "parse-gram.y"
     { pure_parser = true; }
     break;
 
   case 25:
-#line 232 "parse-gram.y"
+#line 233 "parse-gram.y"
     { version_check (&(yylsp[(2) - (2)]), (yyvsp[(2) - (2)].chars)); }
     break;
 
   case 26:
-#line 233 "parse-gram.y"
+#line 234 "parse-gram.y"
     { skeleton = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 27:
-#line 234 "parse-gram.y"
+#line 235 "parse-gram.y"
     { token_table_flag = true; }
     break;
 
   case 28:
-#line 235 "parse-gram.y"
+#line 236 "parse-gram.y"
     { report_flag = report_states; }
     break;
 
   case 29:
-#line 236 "parse-gram.y"
+#line 237 "parse-gram.y"
     { yacc_flag = true; }
     break;
 
   case 33:
-#line 244 "parse-gram.y"
+#line 245 "parse-gram.y"
     {
       grammar_start_symbol_set ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]));
     }
     break;
 
   case 34:
-#line 248 "parse-gram.y"
+#line 249 "parse-gram.y"
     {
       typed = true;
       MUSCLE_INSERT_INT ("stype_line", (yylsp[(1) - (1)]).start.line);
@@ -1828,7 +1829,7 @@ yyreduce:
     break;
 
   case 35:
-#line 254 "parse-gram.y"
+#line 255 "parse-gram.y"
     {
       symbol_list *list;
       for (list = (yyvsp[(2) - (2)].list); list; list = list->next)
@@ -1838,7 +1839,7 @@ yyreduce:
     break;
 
   case 36:
-#line 261 "parse-gram.y"
+#line 262 "parse-gram.y"
     {
       symbol_list *list;
       for (list = (yyvsp[(2) - (2)].list); list; list = list->next)
@@ -1848,26 +1849,26 @@ yyreduce:
     break;
 
   case 37:
-#line 268 "parse-gram.y"
+#line 269 "parse-gram.y"
     {
       default_prec = true;
     }
     break;
 
   case 38:
-#line 272 "parse-gram.y"
+#line 273 "parse-gram.y"
     {
       default_prec = false;
     }
     break;
 
   case 39:
-#line 278 "parse-gram.y"
+#line 279 "parse-gram.y"
     { current_class = nterm_sym; }
     break;
 
   case 40:
-#line 279 "parse-gram.y"
+#line 280 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
@@ -1875,12 +1876,12 @@ yyreduce:
     break;
 
   case 41:
-#line 283 "parse-gram.y"
+#line 284 "parse-gram.y"
     { current_class = token_sym; }
     break;
 
   case 42:
-#line 284 "parse-gram.y"
+#line 285 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
@@ -1888,7 +1889,7 @@ yyreduce:
     break;
 
   case 43:
-#line 289 "parse-gram.y"
+#line 290 "parse-gram.y"
     {
       symbol_list *list;
       for (list = (yyvsp[(3) - (3)].list); list; list = list->next)
@@ -1898,7 +1899,7 @@ yyreduce:
     break;
 
   case 44:
-#line 299 "parse-gram.y"
+#line 300 "parse-gram.y"
     {
       symbol_list *list;
       ++current_prec;
@@ -1913,49 +1914,49 @@ yyreduce:
     break;
 
   case 45:
-#line 313 "parse-gram.y"
+#line 314 "parse-gram.y"
     { (yyval.assoc) = left_assoc; }
     break;
 
   case 46:
-#line 314 "parse-gram.y"
+#line 315 "parse-gram.y"
     { (yyval.assoc) = right_assoc; }
     break;
 
   case 47:
-#line 315 "parse-gram.y"
+#line 316 "parse-gram.y"
     { (yyval.assoc) = non_assoc; }
     break;
 
   case 48:
-#line 319 "parse-gram.y"
+#line 320 "parse-gram.y"
     { current_type = NULL; }
     break;
 
   case 49:
-#line 320 "parse-gram.y"
+#line 321 "parse-gram.y"
     { current_type = (yyvsp[(1) - (1)].uniqstr); }
     break;
 
   case 50:
-#line 326 "parse-gram.y"
+#line 327 "parse-gram.y"
     { (yyval.list) = symbol_list_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 51:
-#line 327 "parse-gram.y"
+#line 328 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), (yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)])); }
     break;
 
   case 52:
-#line 333 "parse-gram.y"
+#line 334 "parse-gram.y"
     {
        current_type = (yyvsp[(1) - (1)].uniqstr);
      }
     break;
 
   case 53:
-#line 337 "parse-gram.y"
+#line 338 "parse-gram.y"
     {
        symbol_class_set ((yyvsp[(1) - (1)].symbol), current_class, (yylsp[(1) - (1)]));
        symbol_type_set ((yyvsp[(1) - (1)].symbol), current_type, (yylsp[(1) - (1)]));
@@ -1963,7 +1964,7 @@ yyreduce:
     break;
 
   case 54:
-#line 342 "parse-gram.y"
+#line 343 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]));
       symbol_type_set ((yyvsp[(1) - (2)].symbol), current_type, (yylsp[(1) - (2)]));
@@ -1972,7 +1973,7 @@ yyreduce:
     break;
 
   case 55:
-#line 348 "parse-gram.y"
+#line 349 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]));
       symbol_type_set ((yyvsp[(1) - (2)].symbol), current_type, (yylsp[(1) - (2)]));
@@ -1981,7 +1982,7 @@ yyreduce:
     break;
 
   case 56:
-#line 354 "parse-gram.y"
+#line 355 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (3)].symbol), current_class, (yylsp[(1) - (3)]));
       symbol_type_set ((yyvsp[(1) - (3)].symbol), current_type, (yylsp[(1) - (3)]));
@@ -1991,7 +1992,7 @@ yyreduce:
     break;
 
   case 62:
-#line 383 "parse-gram.y"
+#line 384 "parse-gram.y"
     {
       if (yacc_flag)
 	complain_at ((yyloc), _("POSIX forbids declarations in the grammar"));
@@ -1999,74 +2000,74 @@ yyreduce:
     break;
 
   case 63:
-#line 388 "parse-gram.y"
+#line 389 "parse-gram.y"
     {
       yyerrok;
     }
     break;
 
   case 64:
-#line 394 "parse-gram.y"
+#line 395 "parse-gram.y"
     { current_lhs = (yyvsp[(1) - (1)].symbol); current_lhs_location = (yylsp[(1) - (1)]); }
     break;
 
   case 66:
-#line 398 "parse-gram.y"
+#line 399 "parse-gram.y"
     { grammar_rule_end ((yylsp[(1) - (1)])); }
     break;
 
   case 67:
-#line 399 "parse-gram.y"
+#line 400 "parse-gram.y"
     { grammar_rule_end ((yylsp[(3) - (3)])); }
     break;
 
   case 69:
-#line 405 "parse-gram.y"
+#line 406 "parse-gram.y"
     { grammar_rule_begin (current_lhs, current_lhs_location); }
     break;
 
   case 70:
-#line 407 "parse-gram.y"
+#line 408 "parse-gram.y"
     { grammar_current_rule_symbol_append ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)])); }
     break;
 
   case 71:
-#line 409 "parse-gram.y"
+#line 410 "parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])); }
     break;
 
   case 72:
-#line 411 "parse-gram.y"
+#line 412 "parse-gram.y"
     { grammar_current_rule_prec_set ((yyvsp[(3) - (3)].symbol), (yylsp[(3) - (3)])); }
     break;
 
   case 73:
-#line 413 "parse-gram.y"
+#line 414 "parse-gram.y"
     { grammar_current_rule_dprec_set ((yyvsp[(3) - (3)].integer), (yylsp[(3) - (3)])); }
     break;
 
   case 74:
-#line 415 "parse-gram.y"
+#line 416 "parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[(3) - (3)].uniqstr), (yylsp[(3) - (3)])); }
     break;
 
   case 75:
-#line 419 "parse-gram.y"
+#line 420 "parse-gram.y"
     { (yyval.symbol) = (yyvsp[(1) - (1)].symbol); }
     break;
 
   case 76:
-#line 420 "parse-gram.y"
+#line 421 "parse-gram.y"
     { (yyval.symbol) = (yyvsp[(1) - (1)].symbol); }
     break;
 
   case 77:
-#line 425 "parse-gram.y"
+#line 426 "parse-gram.y"
     { (yyval.chars) = (yyvsp[(1) - (1)].chars); }
     break;
 
   case 78:
-#line 431 "parse-gram.y"
+#line 432 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[(1) - (1)].chars)), (yylsp[(1) - (1)]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[(1) - (1)]));
@@ -2074,12 +2075,12 @@ yyreduce:
     break;
 
   case 79:
-#line 440 "parse-gram.y"
+#line 441 "parse-gram.y"
     { (yyval.chars) = (yyvsp[(1) - (1)].chars); }
     break;
 
   case 81:
-#line 447 "parse-gram.y"
+#line 448 "parse-gram.y"
     {
       muscle_code_grow ("epilogue", (yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)]));
       scanner_last_string_free ();
@@ -2092,7 +2093,7 @@ yyreduce:
   YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);
 
 /* Line __line__ of yacc.c.  */
-#line 2096 "parse-gram.c"
+#line 2097 "parse-gram.c"
 
   yyvsp -= yylen;
   yyssp -= yylen;
@@ -2304,7 +2305,7 @@ yyreturn:
 }
 
 
-#line 453 "parse-gram.y"
+#line 454 "parse-gram.y"
 
 
 
