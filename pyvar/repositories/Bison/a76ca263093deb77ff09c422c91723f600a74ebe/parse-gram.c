@@ -167,7 +167,28 @@
 
 
 /* Copy the first part of user declarations.  */
-#line 32 "parse-gram.y"
+#line 1 "parse-gram.y"
+/* Bison Grammar Parser                             -*- C -*-
+
+   Copyright (C) 2002, 2003, 2004 Free Software Foundation, Inc.
+
+   This file is part of Bison, the GNU Compiler Compiler.
+
+   This program is free software; you can redistribute it and/or modify
+   it under the terms of the GNU General Public License as published by
+   the Free Software Foundation; either version 2 of the License, or
+   (at your option) any later version.
+
+   This program is distributed in the hope that it will be useful,
+   but WITHOUT ANY WARRANTY; without even the implied warranty of
+   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
+   GNU General Public License for more details.
+
+   You should have received a copy of the GNU General Public License
+   along with this program; if not, write to the Free Software
+   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
+   02111-1307  USA
+*/
 
 #include "system.h"
 
@@ -219,7 +240,7 @@ int current_prec = 0;
 #endif
 
 #if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
-#line 80 "parse-gram.y"
+#line 78 "parse-gram.y"
 typedef union YYSTYPE {
   symbol *symbol;
   symbol_list *list;
@@ -229,7 +250,7 @@ typedef union YYSTYPE {
   uniqstr uniqstr;
 } YYSTYPE;
 /* Line 191 of yacc.c.  */
-#line 233 "parse-gram.c"
+#line 254 "parse-gram.c"
 # define yystype YYSTYPE /* obsolescent; will be withdrawn */
 # define YYSTYPE_IS_DECLARED 1
 # define YYSTYPE_IS_TRIVIAL 1
@@ -253,7 +274,7 @@ typedef struct YYLTYPE
 
 
 /* Line 214 of yacc.c.  */
-#line 257 "parse-gram.c"
+#line 278 "parse-gram.c"
 
 #if ! defined (yyoverflow) || YYERROR_VERBOSE
 
@@ -459,14 +480,14 @@ static const yysigned_char yyrhs[] =
 /* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
 static const unsigned short int yyrline[] =
 {
-       0,   173,   173,   181,   183,   187,   188,   189,   190,   191,
-     192,   193,   194,   195,   196,   201,   205,   206,   207,   208,
-     209,   210,   211,   212,   213,   214,   215,   216,   217,   221,
-     222,   223,   227,   233,   240,   247,   251,   258,   258,   263,
-     263,   268,   278,   293,   294,   295,   299,   300,   306,   307,
-     312,   316,   321,   327,   333,   344,   345,   354,   355,   361,
-     362,   367,   374,   374,   378,   379,   380,   385,   386,   388,
-     390,   392,   394,   399,   400,   404,   410,   419,   426,   428
+       0,   171,   171,   179,   181,   185,   186,   187,   188,   189,
+     190,   191,   192,   193,   194,   199,   203,   204,   205,   206,
+     207,   208,   209,   210,   211,   212,   213,   214,   215,   219,
+     220,   221,   225,   231,   238,   245,   249,   256,   256,   261,
+     261,   266,   276,   291,   292,   293,   297,   298,   304,   305,
+     310,   314,   319,   325,   331,   342,   343,   352,   353,   359,
+     360,   365,   372,   372,   376,   377,   378,   383,   384,   386,
+     388,   390,   392,   397,   398,   402,   408,   417,   424,   426
 };
 #endif
 
@@ -1084,7 +1105,7 @@ YYLTYPE yylloc;
   yylsp = yyls;
 
   /* User initialization code. */
-  #line 70 "parse-gram.y"
+  #line 68 "parse-gram.y"
 {
   /* Bison's grammar can initial empty locations, hence a default
      location is needed. */
@@ -1093,7 +1114,7 @@ YYLTYPE yylloc;
   (*yylsp).start.column = (*yylsp).end.column = 0;
 }
 /* Line 818 of yacc.c.  */
-#line 1097 "parse-gram.c"
+#line 1118 "parse-gram.c"
   goto yysetstate;
 
 /*------------------------------------------------------------.
@@ -1281,47 +1302,47 @@ yyreduce:
   switch (yyn)
     {
         case 6:
-#line 188 "parse-gram.y"
+#line 186 "parse-gram.y"
     { prologue_augment (yyvsp[0].chars, yylsp[0]); }
     break;
 
   case 7:
-#line 189 "parse-gram.y"
+#line 187 "parse-gram.y"
     { debug_flag = true; }
     break;
 
   case 8:
-#line 190 "parse-gram.y"
+#line 188 "parse-gram.y"
     { muscle_insert (yyvsp[-1].chars, yyvsp[0].chars); }
     break;
 
   case 9:
-#line 191 "parse-gram.y"
+#line 189 "parse-gram.y"
     { defines_flag = true; }
     break;
 
   case 10:
-#line 192 "parse-gram.y"
+#line 190 "parse-gram.y"
     { error_verbose = true; }
     break;
 
   case 11:
-#line 193 "parse-gram.y"
+#line 191 "parse-gram.y"
     { expected_sr_conflicts = yyvsp[0].integer; }
     break;
 
   case 12:
-#line 194 "parse-gram.y"
+#line 192 "parse-gram.y"
     { expected_rr_conflicts = yyvsp[0].integer; }
     break;
 
   case 13:
-#line 195 "parse-gram.y"
+#line 193 "parse-gram.y"
     { spec_file_prefix = yyvsp[0].chars; }
     break;
 
   case 14:
-#line 197 "parse-gram.y"
+#line 195 "parse-gram.y"
     {
     nondeterministic_parser = true;
     glr_parser = true;
@@ -1329,81 +1350,81 @@ yyreduce:
     break;
 
   case 15:
-#line 202 "parse-gram.y"
+#line 200 "parse-gram.y"
     {
     muscle_code_grow ("initial_action", yyvsp[0].chars, yylsp[0]);
   }
     break;
 
   case 16:
-#line 205 "parse-gram.y"
+#line 203 "parse-gram.y"
     { add_param ("lex_param", yyvsp[0].chars, yylsp[0]); }
     break;
 
   case 17:
-#line 206 "parse-gram.y"
+#line 204 "parse-gram.y"
     { locations_flag = true; }
     break;
 
   case 18:
-#line 207 "parse-gram.y"
+#line 205 "parse-gram.y"
     { spec_name_prefix = yyvsp[0].chars; }
     break;
 
   case 19:
-#line 208 "parse-gram.y"
+#line 206 "parse-gram.y"
     { no_lines_flag = true; }
     break;
 
   case 20:
-#line 209 "parse-gram.y"
+#line 207 "parse-gram.y"
     { nondeterministic_parser = true; }
     break;
 
   case 21:
-#line 210 "parse-gram.y"
+#line 208 "parse-gram.y"
     { spec_outfile = yyvsp[0].chars; }
     break;
 
   case 22:
-#line 211 "parse-gram.y"
+#line 209 "parse-gram.y"
     { add_param ("parse_param", yyvsp[0].chars, yylsp[0]); }
     break;
 
   case 23:
-#line 212 "parse-gram.y"
+#line 210 "parse-gram.y"
     { pure_parser = true; }
     break;
 
   case 24:
-#line 213 "parse-gram.y"
+#line 211 "parse-gram.y"
     { skeleton = yyvsp[0].chars; }
     break;
 
   case 25:
-#line 214 "parse-gram.y"
+#line 212 "parse-gram.y"
     { token_table_flag = true; }
     break;
 
   case 26:
-#line 215 "parse-gram.y"
+#line 213 "parse-gram.y"
     { report_flag = report_states; }
     break;
 
   case 27:
-#line 216 "parse-gram.y"
+#line 214 "parse-gram.y"
     { yacc_flag = true; }
     break;
 
   case 31:
-#line 224 "parse-gram.y"
+#line 222 "parse-gram.y"
     {
       grammar_start_symbol_set (yyvsp[0].symbol, yylsp[0]);
     }
     break;
 
   case 32:
-#line 228 "parse-gram.y"
+#line 226 "parse-gram.y"
     {
       typed = true;
       MUSCLE_INSERT_INT ("stype_line", yylsp[0].start.line);
@@ -1412,7 +1433,7 @@ yyreduce:
     break;
 
   case 33:
-#line 234 "parse-gram.y"
+#line 232 "parse-gram.y"
     {
       symbol_list *list;
       for (list = yyvsp[0].list; list; list = list->next)
@@ -1422,7 +1443,7 @@ yyreduce:
     break;
 
   case 34:
-#line 241 "parse-gram.y"
+#line 239 "parse-gram.y"
     {
       symbol_list *list;
       for (list = yyvsp[0].list; list; list = list->next)
@@ -1432,26 +1453,26 @@ yyreduce:
     break;
 
   case 35:
-#line 248 "parse-gram.y"
+#line 246 "parse-gram.y"
     {
       default_prec = true;
     }
     break;
 
   case 36:
-#line 252 "parse-gram.y"
+#line 250 "parse-gram.y"
     {
       default_prec = false;
     }
     break;
 
   case 37:
-#line 258 "parse-gram.y"
+#line 256 "parse-gram.y"
     { current_class = nterm_sym; }
     break;
 
   case 38:
-#line 259 "parse-gram.y"
+#line 257 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
@@ -1459,12 +1480,12 @@ yyreduce:
     break;
 
   case 39:
-#line 263 "parse-gram.y"
+#line 261 "parse-gram.y"
     { current_class = token_sym; }
     break;
 
   case 40:
-#line 264 "parse-gram.y"
+#line 262 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
@@ -1472,7 +1493,7 @@ yyreduce:
     break;
 
   case 41:
-#line 269 "parse-gram.y"
+#line 267 "parse-gram.y"
     {
       symbol_list *list;
       for (list = yyvsp[0].list; list; list = list->next)
@@ -1482,7 +1503,7 @@ yyreduce:
     break;
 
   case 42:
-#line 279 "parse-gram.y"
+#line 277 "parse-gram.y"
     {
       symbol_list *list;
       ++current_prec;
@@ -1497,49 +1518,49 @@ yyreduce:
     break;
 
   case 43:
-#line 293 "parse-gram.y"
+#line 291 "parse-gram.y"
     { yyval.assoc = left_assoc; }
     break;
 
   case 44:
-#line 294 "parse-gram.y"
+#line 292 "parse-gram.y"
     { yyval.assoc = right_assoc; }
     break;
 
   case 45:
-#line 295 "parse-gram.y"
+#line 293 "parse-gram.y"
     { yyval.assoc = non_assoc; }
     break;
 
   case 46:
-#line 299 "parse-gram.y"
+#line 297 "parse-gram.y"
     { current_type = NULL; }
     break;
 
   case 47:
-#line 300 "parse-gram.y"
+#line 298 "parse-gram.y"
     { current_type = yyvsp[0].uniqstr; }
     break;
 
   case 48:
-#line 306 "parse-gram.y"
+#line 304 "parse-gram.y"
     { yyval.list = symbol_list_new (yyvsp[0].symbol, yylsp[0]); }
     break;
 
   case 49:
-#line 307 "parse-gram.y"
+#line 305 "parse-gram.y"
     { yyval.list = symbol_list_prepend (yyvsp[-1].list, yyvsp[0].symbol, yylsp[0]); }
     break;
 
   case 50:
-#line 313 "parse-gram.y"
+#line 311 "parse-gram.y"
     {
        current_type = yyvsp[0].uniqstr;
      }
     break;
 
   case 51:
-#line 317 "parse-gram.y"
+#line 315 "parse-gram.y"
     {
        symbol_class_set (yyvsp[0].symbol, current_class, yylsp[0]);
        symbol_type_set (yyvsp[0].symbol, current_type, yylsp[0]);
@@ -1547,7 +1568,7 @@ yyreduce:
     break;
 
   case 52:
-#line 322 "parse-gram.y"
+#line 320 "parse-gram.y"
     {
       symbol_class_set (yyvsp[-1].symbol, current_class, yylsp[-1]);
       symbol_type_set (yyvsp[-1].symbol, current_type, yylsp[-1]);
@@ -1556,7 +1577,7 @@ yyreduce:
     break;
 
   case 53:
-#line 328 "parse-gram.y"
+#line 326 "parse-gram.y"
     {
       symbol_class_set (yyvsp[-1].symbol, current_class, yylsp[-1]);
       symbol_type_set (yyvsp[-1].symbol, current_type, yylsp[-1]);
@@ -1565,7 +1586,7 @@ yyreduce:
     break;
 
   case 54:
-#line 334 "parse-gram.y"
+#line 332 "parse-gram.y"
     {
       symbol_class_set (yyvsp[-2].symbol, current_class, yylsp[-2]);
       symbol_type_set (yyvsp[-2].symbol, current_type, yylsp[-2]);
@@ -1575,7 +1596,7 @@ yyreduce:
     break;
 
   case 60:
-#line 363 "parse-gram.y"
+#line 361 "parse-gram.y"
     {
       if (yacc_flag)
 	complain_at (yyloc, _("POSIX forbids declarations in the grammar"));
@@ -1583,74 +1604,74 @@ yyreduce:
     break;
 
   case 61:
-#line 368 "parse-gram.y"
+#line 366 "parse-gram.y"
     {
       yyerrok;
     }
     break;
 
   case 62:
-#line 374 "parse-gram.y"
+#line 372 "parse-gram.y"
     { current_lhs = yyvsp[0].symbol; current_lhs_location = yylsp[0]; }
     break;
 
   case 64:
-#line 378 "parse-gram.y"
+#line 376 "parse-gram.y"
     { grammar_rule_end (yylsp[0]); }
     break;
 
   case 65:
-#line 379 "parse-gram.y"
+#line 377 "parse-gram.y"
     { grammar_rule_end (yylsp[0]); }
     break;
 
   case 67:
-#line 385 "parse-gram.y"
+#line 383 "parse-gram.y"
     { grammar_rule_begin (current_lhs, current_lhs_location); }
     break;
 
   case 68:
-#line 387 "parse-gram.y"
+#line 385 "parse-gram.y"
     { grammar_current_rule_symbol_append (yyvsp[0].symbol, yylsp[0]); }
     break;
 
   case 69:
-#line 389 "parse-gram.y"
+#line 387 "parse-gram.y"
     { grammar_current_rule_action_append (yyvsp[0].chars, yylsp[0]); }
     break;
 
   case 70:
-#line 391 "parse-gram.y"
+#line 389 "parse-gram.y"
     { grammar_current_rule_prec_set (yyvsp[0].symbol, yylsp[0]); }
     break;
 
   case 71:
-#line 393 "parse-gram.y"
+#line 391 "parse-gram.y"
     { grammar_current_rule_dprec_set (yyvsp[0].integer, yylsp[0]); }
     break;
 
   case 72:
-#line 395 "parse-gram.y"
+#line 393 "parse-gram.y"
     { grammar_current_rule_merge_set (yyvsp[0].uniqstr, yylsp[0]); }
     break;
 
   case 73:
-#line 399 "parse-gram.y"
+#line 397 "parse-gram.y"
     { yyval.symbol = yyvsp[0].symbol; }
     break;
 
   case 74:
-#line 400 "parse-gram.y"
+#line 398 "parse-gram.y"
     { yyval.symbol = yyvsp[0].symbol; }
     break;
 
   case 75:
-#line 405 "parse-gram.y"
+#line 403 "parse-gram.y"
     { yyval.chars = yyvsp[0].chars; }
     break;
 
   case 76:
-#line 411 "parse-gram.y"
+#line 409 "parse-gram.y"
     {
       yyval.symbol = symbol_get (yyvsp[0].chars, yylsp[0]);
       symbol_class_set (yyval.symbol, token_sym, yylsp[0]);
@@ -1658,7 +1679,7 @@ yyreduce:
     break;
 
   case 77:
-#line 420 "parse-gram.y"
+#line 418 "parse-gram.y"
     {
       yyval.chars = yyvsp[0].chars + 1;
       yyval.chars[strlen (yyval.chars) - 1] = '\0';
@@ -1666,7 +1687,7 @@ yyreduce:
     break;
 
   case 79:
-#line 429 "parse-gram.y"
+#line 427 "parse-gram.y"
     {
       muscle_code_grow ("epilogue", yyvsp[0].chars, yylsp[0]);
       scanner_last_string_free ();
@@ -1677,7 +1698,7 @@ yyreduce:
     }
 
 /* Line 1010 of yacc.c.  */
-#line 1681 "parse-gram.c"
+#line 1702 "parse-gram.c"
 
   yyvsp -= yylen;
   yyssp -= yylen;
@@ -1906,7 +1927,7 @@ yyreturn:
 }
 
 
-#line 435 "parse-gram.y"
+#line 433 "parse-gram.y"
 
 
 
