@@ -182,7 +182,7 @@
 
 
 /* Copy the first part of user declarations.  */
-#line 1 "parse-gram.y"
+#line 1 "../../src/parse-gram.y"
 /* Bison Grammar Parser                             -*- C -*-
 
    Copyright (C) 2002, 2003, 2004, 2005, 2006 Free Software Foundation, Inc.
@@ -214,7 +214,6 @@
 #include "getargs.h"
 #include "gram.h"
 #include "muscle_tab.h"
-#include "output.h"
 #include "quotearg.h"
 #include "reader.h"
 #include "symlist.h"
@@ -277,7 +276,7 @@ static int current_prec = 0;
 
 #if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
 typedef union YYSTYPE
-#line 95 "parse-gram.y"
+#line 94 "../../src/parse-gram.y"
 {
   symbol *symbol;
   symbol_list *list;
@@ -287,7 +286,7 @@ typedef union YYSTYPE
   uniqstr uniqstr;
 }
 /* Line 193 of yacc.c.  */
-#line 291 "parse-gram.c"
+#line 290 "../../src/parse-gram.c"
 	YYSTYPE;
 # define yystype YYSTYPE /* obsolescent; will be withdrawn */
 # define YYSTYPE_IS_DECLARED 1
@@ -312,7 +311,7 @@ typedef struct YYLTYPE
 
 
 /* Line 216 of yacc.c.  */
-#line 316 "parse-gram.c"
+#line 315 "../../src/parse-gram.c"
 
 #ifdef short
 # undef short
@@ -628,15 +627,15 @@ static const yytype_int8 yyrhs[] =
 /* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
 static const yytype_uint16 yyrline[] =
 {
-       0,   203,   203,   211,   213,   217,   218,   219,   220,   225,
-     226,   227,   228,   229,   230,   231,   236,   240,   241,   242,
-     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
-     253,   257,   258,   259,   263,   279,   286,   293,   297,   304,
-     304,   309,   309,   314,   324,   339,   340,   341,   345,   346,
-     352,   353,   358,   362,   367,   373,   379,   390,   391,   400,
-     401,   407,   408,   409,   416,   416,   420,   421,   422,   427,
-     428,   430,   431,   433,   435,   440,   441,   457,   457,   463,
-     472,   477,   479
+       0,   202,   202,   210,   212,   216,   217,   218,   219,   224,
+     225,   226,   227,   228,   229,   230,   235,   239,   240,   241,
+     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
+     252,   256,   257,   258,   262,   278,   285,   292,   296,   303,
+     303,   308,   308,   313,   323,   338,   339,   340,   344,   345,
+     351,   352,   357,   361,   366,   372,   378,   389,   390,   399,
+     400,   406,   407,   408,   415,   415,   419,   420,   421,   426,
+     427,   429,   430,   432,   434,   439,   440,   456,   456,   462,
+     471,   476,   478
 };
 #endif
 
@@ -974,84 +973,84 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
   switch (yytype)
     {
       case 3: /* "\"string\"" */
-#line 180 "parse-gram.y"
+#line 179 "../../src/parse-gram.y"
 	{ fprintf (stderr, "\"%s\"", (yyvaluep->chars)); };
-#line 980 "parse-gram.c"
+#line 979 "../../src/parse-gram.c"
 	break;
       case 4: /* "\"integer\"" */
-#line 193 "parse-gram.y"
+#line 192 "../../src/parse-gram.y"
 	{ fprintf (stderr, "%d", (yyvaluep->integer)); };
-#line 985 "parse-gram.c"
+#line 984 "../../src/parse-gram.c"
 	break;
       case 8: /* "\"%destructor {...}\"" */
-#line 182 "parse-gram.y"
+#line 181 "../../src/parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 990 "parse-gram.c"
+#line 989 "../../src/parse-gram.c"
 	break;
       case 9: /* "\"%printer {...}\"" */
-#line 182 "parse-gram.y"
+#line 181 "../../src/parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 995 "parse-gram.c"
+#line 994 "../../src/parse-gram.c"
 	break;
       case 10: /* "\"%union {...}\"" */
-#line 182 "parse-gram.y"
+#line 181 "../../src/parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1000 "parse-gram.c"
+#line 999 "../../src/parse-gram.c"
 	break;
       case 26: /* "\"%initial-action {...}\"" */
-#line 182 "parse-gram.y"
+#line 181 "../../src/parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1005 "parse-gram.c"
+#line 1004 "../../src/parse-gram.c"
 	break;
       case 27: /* "\"%lex-param {...}\"" */
-#line 182 "parse-gram.y"
+#line 181 "../../src/parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1010 "parse-gram.c"
+#line 1009 "../../src/parse-gram.c"
 	break;
       case 34: /* "\"%parse-param {...}\"" */
-#line 182 "parse-gram.y"
+#line 181 "../../src/parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1015 "parse-gram.c"
+#line 1014 "../../src/parse-gram.c"
 	break;
       case 42: /* "\"type\"" */
-#line 191 "parse-gram.y"
+#line 190 "../../src/parse-gram.y"
 	{ fprintf (stderr, "<%s>", (yyvaluep->uniqstr)); };
-#line 1020 "parse-gram.c"
+#line 1019 "../../src/parse-gram.c"
 	break;
       case 46: /* "\"identifier\"" */
-#line 195 "parse-gram.y"
+#line 194 "../../src/parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
-#line 1025 "parse-gram.c"
+#line 1024 "../../src/parse-gram.c"
 	break;
       case 47: /* "\"identifier:\"" */
-#line 197 "parse-gram.y"
+#line 196 "../../src/parse-gram.y"
 	{ fprintf (stderr, "%s:", (yyvaluep->symbol)->tag); };
-#line 1030 "parse-gram.c"
+#line 1029 "../../src/parse-gram.c"
 	break;
       case 49: /* "\"%{...%}\"" */
-#line 182 "parse-gram.y"
+#line 181 "../../src/parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1035 "parse-gram.c"
+#line 1034 "../../src/parse-gram.c"
 	break;
       case 50: /* "\"epilogue\"" */
-#line 182 "parse-gram.y"
+#line 181 "../../src/parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1040 "parse-gram.c"
+#line 1039 "../../src/parse-gram.c"
 	break;
       case 72: /* "symbol" */
-#line 195 "parse-gram.y"
+#line 194 "../../src/parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
-#line 1045 "parse-gram.c"
+#line 1044 "../../src/parse-gram.c"
 	break;
       case 75: /* "string_as_id" */
-#line 195 "parse-gram.y"
+#line 194 "../../src/parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
-#line 1050 "parse-gram.c"
+#line 1049 "../../src/parse-gram.c"
 	break;
       case 76: /* "string_content" */
-#line 180 "parse-gram.y"
+#line 179 "../../src/parse-gram.y"
 	{ fprintf (stderr, "\"%s\"", (yyvaluep->chars)); };
-#line 1055 "parse-gram.c"
+#line 1054 "../../src/parse-gram.c"
 	break;
       default:
 	break;
@@ -1562,7 +1561,7 @@ YYLTYPE yylloc;
 
 
   /* User initialization code.  */
-#line 85 "parse-gram.y"
+#line 84 "../../src/parse-gram.y"
 {
   /* Bison's grammar can initial empty locations, hence a default
      location is needed. */
@@ -1571,7 +1570,7 @@ YYLTYPE yylloc;
   yylloc.start.column = yylloc.end.column = 0;
 }
 /* Line 1078 of yacc.c.  */
-#line 1575 "parse-gram.c"
+#line 1574 "../../src/parse-gram.c"
   yylsp[0] = yylloc;
   goto yysetstate;
 
@@ -1756,17 +1755,17 @@ yyreduce:
   switch (yyn)
     {
         case 6:
-#line 218 "parse-gram.y"
+#line 217 "../../src/parse-gram.y"
     { prologue_augment ((yyvsp[(1) - (1)].chars), (yylsp[(1) - (1)])); }
     break;
 
   case 7:
-#line 219 "parse-gram.y"
+#line 218 "../../src/parse-gram.y"
     { debug_flag = true; }
     break;
 
   case 8:
-#line 221 "parse-gram.y"
+#line 220 "../../src/parse-gram.y"
     {
       static char one[] = "1";
       muscle_insert ((yyvsp[(2) - (2)].chars), one);
@@ -1774,37 +1773,37 @@ yyreduce:
     break;
 
   case 9:
-#line 225 "parse-gram.y"
+#line 224 "../../src/parse-gram.y"
     { muscle_insert ((yyvsp[(2) - (3)].chars), (yyvsp[(3) - (3)].chars)); }
     break;
 
   case 10:
-#line 226 "parse-gram.y"
+#line 225 "../../src/parse-gram.y"
     { defines_flag = true; }
     break;
 
   case 11:
-#line 227 "parse-gram.y"
+#line 226 "../../src/parse-gram.y"
     { error_verbose = true; }
     break;
 
   case 12:
-#line 228 "parse-gram.y"
+#line 227 "../../src/parse-gram.y"
     { expected_sr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 13:
-#line 229 "parse-gram.y"
+#line 228 "../../src/parse-gram.y"
     { expected_rr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 14:
-#line 230 "parse-gram.y"
+#line 229 "../../src/parse-gram.y"
     { spec_file_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 15:
-#line 232 "parse-gram.y"
+#line 231 "../../src/parse-gram.y"
     {
       nondeterministic_parser = true;
       glr_parser = true;
@@ -1812,86 +1811,86 @@ yyreduce:
     break;
 
   case 16:
-#line 237 "parse-gram.y"
+#line 236 "../../src/parse-gram.y"
     {
       muscle_code_grow ("initial_action", (yyvsp[(1) - (1)].chars), (yylsp[(1) - (1)]));
     }
     break;
 
   case 17:
-#line 240 "parse-gram.y"
+#line 239 "../../src/parse-gram.y"
     { add_param ("lex_param", (yyvsp[(1) - (1)].chars), (yylsp[(1) - (1)])); }
     break;
 
   case 18:
-#line 241 "parse-gram.y"
+#line 240 "../../src/parse-gram.y"
     { locations_flag = true; }
     break;
 
   case 19:
-#line 242 "parse-gram.y"
+#line 241 "../../src/parse-gram.y"
     { spec_name_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 20:
-#line 243 "parse-gram.y"
+#line 242 "../../src/parse-gram.y"
     { no_lines_flag = true; }
     break;
 
   case 21:
-#line 244 "parse-gram.y"
+#line 243 "../../src/parse-gram.y"
     { nondeterministic_parser = true; }
     break;
 
   case 22:
-#line 245 "parse-gram.y"
+#line 244 "../../src/parse-gram.y"
     { spec_outfile = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 23:
-#line 246 "parse-gram.y"
+#line 245 "../../src/parse-gram.y"
     { add_param ("parse_param", (yyvsp[(1) - (1)].chars), (yylsp[(1) - (1)])); }
     break;
 
   case 24:
-#line 247 "parse-gram.y"
+#line 246 "../../src/parse-gram.y"
     { pure_parser = true; }
     break;
 
   case 25:
-#line 248 "parse-gram.y"
+#line 247 "../../src/parse-gram.y"
     { version_check (&(yylsp[(2) - (2)]), (yyvsp[(2) - (2)].chars)); }
     break;
 
   case 26:
-#line 249 "parse-gram.y"
+#line 248 "../../src/parse-gram.y"
     { skeleton = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 27:
-#line 250 "parse-gram.y"
+#line 249 "../../src/parse-gram.y"
     { token_table_flag = true; }
     break;
 
   case 28:
-#line 251 "parse-gram.y"
+#line 250 "../../src/parse-gram.y"
     { report_flag = report_states; }
     break;
 
   case 29:
-#line 252 "parse-gram.y"
+#line 251 "../../src/parse-gram.y"
     { yacc_flag = true; }
     break;
 
   case 33:
-#line 260 "parse-gram.y"
+#line 259 "../../src/parse-gram.y"
     {
       grammar_start_symbol_set ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]));
     }
     break;
 
   case 34:
-#line 264 "parse-gram.y"
+#line 263 "../../src/parse-gram.y"
     {
       char const *body = (yyvsp[(1) - (1)].chars);
 
@@ -1910,7 +1909,7 @@ yyreduce:
     break;
 
   case 35:
-#line 280 "parse-gram.y"
+#line 279 "../../src/parse-gram.y"
     {
       symbol_list *list;
       for (list = (yyvsp[(2) - (2)].list); list; list = list->next)
@@ -1920,7 +1919,7 @@ yyreduce:
     break;
 
   case 36:
-#line 287 "parse-gram.y"
+#line 286 "../../src/parse-gram.y"
     {
       symbol_list *list;
       for (list = (yyvsp[(2) - (2)].list); list; list = list->next)
@@ -1930,26 +1929,26 @@ yyreduce:
     break;
 
   case 37:
-#line 294 "parse-gram.y"
+#line 293 "../../src/parse-gram.y"
     {
       default_prec = true;
     }
     break;
 
   case 38:
-#line 298 "parse-gram.y"
+#line 297 "../../src/parse-gram.y"
     {
       default_prec = false;
     }
     break;
 
   case 39:
-#line 304 "parse-gram.y"
+#line 303 "../../src/parse-gram.y"
     { current_class = nterm_sym; }
     break;
 
   case 40:
-#line 305 "parse-gram.y"
+#line 304 "../../src/parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
@@ -1957,12 +1956,12 @@ yyreduce:
     break;
 
   case 41:
-#line 309 "parse-gram.y"
+#line 308 "../../src/parse-gram.y"
     { current_class = token_sym; }
     break;
 
   case 42:
-#line 310 "parse-gram.y"
+#line 309 "../../src/parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
@@ -1970,7 +1969,7 @@ yyreduce:
     break;
 
   case 43:
-#line 315 "parse-gram.y"
+#line 314 "../../src/parse-gram.y"
     {
       symbol_list *list;
       for (list = (yyvsp[(3) - (3)].list); list; list = list->next)
@@ -1980,7 +1979,7 @@ yyreduce:
     break;
 
   case 44:
-#line 325 "parse-gram.y"
+#line 324 "../../src/parse-gram.y"
     {
       symbol_list *list;
       ++current_prec;
@@ -1995,49 +1994,49 @@ yyreduce:
     break;
 
   case 45:
-#line 339 "parse-gram.y"
+#line 338 "../../src/parse-gram.y"
     { (yyval.assoc) = left_assoc; }
     break;
 
   case 46:
-#line 340 "parse-gram.y"
+#line 339 "../../src/parse-gram.y"
     { (yyval.assoc) = right_assoc; }
     break;
 
   case 47:
-#line 341 "parse-gram.y"
+#line 340 "../../src/parse-gram.y"
     { (yyval.assoc) = non_assoc; }
     break;
 
   case 48:
-#line 345 "parse-gram.y"
+#line 344 "../../src/parse-gram.y"
     { current_type = NULL; }
     break;
 
   case 49:
-#line 346 "parse-gram.y"
+#line 345 "../../src/parse-gram.y"
     { current_type = (yyvsp[(1) - (1)].uniqstr); }
     break;
 
   case 50:
-#line 352 "parse-gram.y"
+#line 351 "../../src/parse-gram.y"
     { (yyval.list) = symbol_list_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 51:
-#line 353 "parse-gram.y"
+#line 352 "../../src/parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), (yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)])); }
     break;
 
   case 52:
-#line 359 "parse-gram.y"
+#line 358 "../../src/parse-gram.y"
     {
        current_type = (yyvsp[(1) - (1)].uniqstr);
      }
     break;
 
   case 53:
-#line 363 "parse-gram.y"
+#line 362 "../../src/parse-gram.y"
     {
        symbol_class_set ((yyvsp[(1) - (1)].symbol), current_class, (yylsp[(1) - (1)]), true);
        symbol_type_set ((yyvsp[(1) - (1)].symbol), current_type, (yylsp[(1) - (1)]));
@@ -2045,7 +2044,7 @@ yyreduce:
     break;
 
   case 54:
-#line 368 "parse-gram.y"
+#line 367 "../../src/parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
       symbol_type_set ((yyvsp[(1) - (2)].symbol), current_type, (yylsp[(1) - (2)]));
@@ -2054,7 +2053,7 @@ yyreduce:
     break;
 
   case 55:
-#line 374 "parse-gram.y"
+#line 373 "../../src/parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
       symbol_type_set ((yyvsp[(1) - (2)].symbol), current_type, (yylsp[(1) - (2)]));
@@ -2063,7 +2062,7 @@ yyreduce:
     break;
 
   case 56:
-#line 380 "parse-gram.y"
+#line 379 "../../src/parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (3)].symbol), current_class, (yylsp[(1) - (3)]), true);
       symbol_type_set ((yyvsp[(1) - (3)].symbol), current_type, (yylsp[(1) - (3)]));
@@ -2073,69 +2072,69 @@ yyreduce:
     break;
 
   case 63:
-#line 410 "parse-gram.y"
+#line 409 "../../src/parse-gram.y"
     {
       yyerrok;
     }
     break;
 
   case 64:
-#line 416 "parse-gram.y"
+#line 415 "../../src/parse-gram.y"
     { current_lhs = (yyvsp[(1) - (1)].symbol); current_lhs_location = (yylsp[(1) - (1)]); }
     break;
 
   case 66:
-#line 420 "parse-gram.y"
+#line 419 "../../src/parse-gram.y"
     { grammar_current_rule_end ((yylsp[(1) - (1)])); }
     break;
 
   case 67:
-#line 421 "parse-gram.y"
+#line 420 "../../src/parse-gram.y"
     { grammar_current_rule_end ((yylsp[(3) - (3)])); }
     break;
 
   case 69:
-#line 427 "parse-gram.y"
+#line 426 "../../src/parse-gram.y"
     { grammar_current_rule_begin (current_lhs, current_lhs_location); }
     break;
 
   case 70:
-#line 429 "parse-gram.y"
+#line 428 "../../src/parse-gram.y"
     { grammar_current_rule_symbol_append ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)])); }
     break;
 
   case 72:
-#line 432 "parse-gram.y"
+#line 431 "../../src/parse-gram.y"
     { grammar_current_rule_prec_set ((yyvsp[(3) - (3)].symbol), (yylsp[(3) - (3)])); }
     break;
 
   case 73:
-#line 434 "parse-gram.y"
+#line 433 "../../src/parse-gram.y"
     { grammar_current_rule_dprec_set ((yyvsp[(3) - (3)].integer), (yylsp[(3) - (3)])); }
     break;
 
   case 74:
-#line 436 "parse-gram.y"
+#line 435 "../../src/parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[(3) - (3)].uniqstr), (yylsp[(3) - (3)])); }
     break;
 
   case 75:
-#line 440 "parse-gram.y"
+#line 439 "../../src/parse-gram.y"
     { (yyval.symbol) = (yyvsp[(1) - (1)].symbol); }
     break;
 
   case 76:
-#line 441 "parse-gram.y"
+#line 440 "../../src/parse-gram.y"
     { (yyval.symbol) = (yyvsp[(1) - (1)].symbol); }
     break;
 
   case 77:
-#line 457 "parse-gram.y"
+#line 456 "../../src/parse-gram.y"
     { grammar_current_rule_action_append (last_string, last_braced_code_loc); }
     break;
 
   case 79:
-#line 464 "parse-gram.y"
+#line 463 "../../src/parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[(1) - (1)].chars)), (yylsp[(1) - (1)]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[(1) - (1)]), false);
@@ -2143,12 +2142,12 @@ yyreduce:
     break;
 
   case 80:
-#line 473 "parse-gram.y"
+#line 472 "../../src/parse-gram.y"
     { (yyval.chars) = (yyvsp[(1) - (1)].chars); }
     break;
 
   case 82:
-#line 480 "parse-gram.y"
+#line 479 "../../src/parse-gram.y"
     {
       muscle_code_grow ("epilogue", (yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)]));
       scanner_last_string_free ();
@@ -2157,7 +2156,7 @@ yyreduce:
 
 
 /* Line 1267 of yacc.c.  */
-#line 2161 "parse-gram.c"
+#line 2160 "../../src/parse-gram.c"
       default: break;
     }
   YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);
@@ -2376,7 +2375,7 @@ yyreturn:
 }
 
 
-#line 486 "parse-gram.y"
+#line 485 "../../src/parse-gram.y"
 
 
 
