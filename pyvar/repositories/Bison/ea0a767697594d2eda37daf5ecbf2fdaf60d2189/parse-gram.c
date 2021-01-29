@@ -1,9 +1,8 @@
-/* A Bison parser, made by GNU Bison 2.4.1.252-dcd39.  */
+/* A Bison parser, made by GNU Bison 2.4.1.259-f52e1.  */
 
 /* Skeleton implementation for Bison's Yacc-like parsers in C
    
-      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006,
-   2007, 2008, 2009, 2010 Free Software Foundation, Inc.
+      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
    
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
@@ -45,7 +44,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "2.4.1.252-dcd39"
+#define YYBISON_VERSION "2.4.1.259-f52e1"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -78,8 +77,7 @@
 #line 1 "parse-gram.y"
 /* Bison Grammar Parser                             -*- C -*-
 
-   Copyright (C) 2002, 2003, 2004, 2005, 2006, 2007, 2008, 2009, 2010
-   Free Software Foundation, Inc.
+   Copyright (C) 2002-2011 Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -152,7 +150,7 @@ static int current_prec = 0;
 
 
 /* Line 268 of yacc.c  */
-#line 156 "parse-gram.c"
+#line 154 "parse-gram.c"
 
 /* Enabling traces.  */
 #ifndef YYDEBUG
@@ -303,7 +301,7 @@ typedef union YYSTYPE
 {
 
 /* Line 293 of yacc.c  */
-#line 95 "parse-gram.y"
+#line 94 "parse-gram.y"
 
   symbol *symbol;
   symbol_list *list;
@@ -318,7 +316,7 @@ typedef union YYSTYPE
 
 
 /* Line 293 of yacc.c  */
-#line 322 "parse-gram.c"
+#line 320 "parse-gram.c"
 } YYSTYPE;
 # define YYSTYPE_IS_TRIVIAL 1
 # define yystype YYSTYPE /* obsolescent; will be withdrawn */
@@ -343,7 +341,7 @@ typedef struct YYLTYPE
 
 
 /* Line 343 of yacc.c  */
-#line 347 "parse-gram.c"
+#line 345 "parse-gram.c"
 
 #ifdef short
 # undef short
@@ -650,17 +648,17 @@ static const yytype_int8 yyrhs[] =
 /* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
 static const yytype_uint16 yyrline[] =
 {
-       0,   210,   210,   218,   220,   224,   225,   235,   236,   241,
-     242,   247,   248,   249,   250,   251,   252,   257,   266,   267,
-     268,   269,   270,   271,   272,   273,   274,   275,   276,   291,
-     292,   316,   317,   318,   319,   323,   324,   325,   329,   336,
-     343,   347,   351,   358,   373,   374,   378,   390,   390,   395,
-     395,   400,   411,   426,   427,   428,   432,   433,   438,   440,
-     445,   446,   451,   453,   458,   459,   463,   464,   465,   466,
-     471,   476,   481,   487,   493,   504,   505,   514,   515,   521,
-     522,   523,   530,   530,   535,   536,   537,   542,   544,   546,
-     548,   550,   552,   557,   559,   570,   571,   576,   577,   578,
-     587,   607,   609,   618,   623,   624,   629,   636,   638
+       0,   209,   209,   217,   219,   223,   224,   234,   235,   240,
+     241,   246,   247,   248,   249,   250,   251,   256,   265,   266,
+     267,   268,   269,   270,   271,   272,   273,   274,   275,   290,
+     291,   315,   316,   317,   318,   322,   323,   324,   328,   335,
+     342,   346,   350,   357,   372,   373,   377,   389,   389,   394,
+     394,   399,   410,   425,   426,   427,   431,   432,   437,   439,
+     444,   445,   450,   452,   457,   458,   462,   463,   464,   465,
+     470,   475,   480,   486,   492,   503,   504,   513,   514,   520,
+     521,   522,   529,   529,   534,   535,   536,   541,   543,   545,
+     547,   549,   551,   556,   558,   569,   570,   575,   576,   577,
+     586,   606,   608,   617,   622,   623,   628,   635,   637
 };
 #endif
 
@@ -1032,164 +1030,164 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
       case 3: /* "\"string\"" */
 
 /* Line 819 of yacc.c  */
-#line 185 "parse-gram.y"
+#line 184 "parse-gram.y"
 	{ fputs (quotearg_style (c_quoting_style, (yyvaluep->chars)), stderr); };
 
 /* Line 819 of yacc.c  */
-#line 1040 "parse-gram.c"
+#line 1038 "parse-gram.c"
 	break;
       case 4: /* "\"integer\"" */
 
 /* Line 819 of yacc.c  */
-#line 197 "parse-gram.y"
+#line 196 "parse-gram.y"
 	{ fprintf (stderr, "%d", (yyvaluep->integer)); };
 
 /* Line 819 of yacc.c  */
-#line 1049 "parse-gram.c"
+#line 1047 "parse-gram.c"
 	break;
       case 43: /* "\"{...}\"" */
 
 /* Line 819 of yacc.c  */
-#line 187 "parse-gram.y"
+#line 186 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->code)); };
 
 /* Line 819 of yacc.c  */
-#line 1058 "parse-gram.c"
+#line 1056 "parse-gram.c"
 	break;
       case 44: /* "\"[identifier]\"" */
 
 /* Line 819 of yacc.c  */
-#line 192 "parse-gram.y"
+#line 191 "parse-gram.y"
 	{ fprintf (stderr, "[%s]", (yyvaluep->uniqstr)); };
 
 /* Line 819 of yacc.c  */
-#line 1067 "parse-gram.c"
+#line 1065 "parse-gram.c"
 	break;
       case 45: /* "\"char\"" */
 
 /* Line 819 of yacc.c  */
-#line 179 "parse-gram.y"
+#line 178 "parse-gram.y"
 	{ fputs (char_name ((yyvaluep->character)), stderr); };
 
 /* Line 819 of yacc.c  */
-#line 1076 "parse-gram.c"
+#line 1074 "parse-gram.c"
 	break;
       case 46: /* "\"epilogue\"" */
 
 /* Line 819 of yacc.c  */
-#line 187 "parse-gram.y"
+#line 186 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
 /* Line 819 of yacc.c  */
-#line 1085 "parse-gram.c"
+#line 1083 "parse-gram.c"
 	break;
       case 48: /* "\"identifier\"" */
 
 /* Line 819 of yacc.c  */
-#line 191 "parse-gram.y"
+#line 190 "parse-gram.y"
 	{ fputs ((yyvaluep->uniqstr), stderr); };
 
 /* Line 819 of yacc.c  */
-#line 1094 "parse-gram.c"
+#line 1092 "parse-gram.c"
 	break;
       case 49: /* "\"identifier:\"" */
 
 /* Line 819 of yacc.c  */
-#line 193 "parse-gram.y"
+#line 192 "parse-gram.y"
 	{ fprintf (stderr, "%s:", (yyvaluep->uniqstr)); };
 
 /* Line 819 of yacc.c  */
-#line 1103 "parse-gram.c"
+#line 1101 "parse-gram.c"
 	break;
       case 52: /* "\"%{...%}\"" */
 
 /* Line 819 of yacc.c  */
-#line 187 "parse-gram.y"
+#line 186 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
 /* Line 819 of yacc.c  */
-#line 1112 "parse-gram.c"
+#line 1110 "parse-gram.c"
 	break;
       case 54: /* "\"type\"" */
 
 /* Line 819 of yacc.c  */
-#line 194 "parse-gram.y"
+#line 193 "parse-gram.y"
 	{ fprintf (stderr, "<%s>", (yyvaluep->uniqstr)); };
 
 /* Line 819 of yacc.c  */
-#line 1121 "parse-gram.c"
+#line 1119 "parse-gram.c"
 	break;
       case 71: /* "symbol.prec" */
 
 /* Line 819 of yacc.c  */
-#line 200 "parse-gram.y"
+#line 199 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
 /* Line 819 of yacc.c  */
-#line 1130 "parse-gram.c"
+#line 1128 "parse-gram.c"
 	break;
       case 84: /* "variable" */
 
 /* Line 819 of yacc.c  */
-#line 191 "parse-gram.y"
+#line 190 "parse-gram.y"
 	{ fputs ((yyvaluep->uniqstr), stderr); };
 
 /* Line 819 of yacc.c  */
-#line 1139 "parse-gram.c"
+#line 1137 "parse-gram.c"
 	break;
       case 85: /* "content.opt" */
 
 /* Line 819 of yacc.c  */
-#line 187 "parse-gram.y"
+#line 186 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
 /* Line 819 of yacc.c  */
-#line 1148 "parse-gram.c"
+#line 1146 "parse-gram.c"
 	break;
       case 86: /* "braceless" */
 
 /* Line 819 of yacc.c  */
-#line 187 "parse-gram.y"
+#line 186 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
 /* Line 819 of yacc.c  */
-#line 1157 "parse-gram.c"
+#line 1155 "parse-gram.c"
 	break;
       case 87: /* "id" */
 
 /* Line 819 of yacc.c  */
-#line 200 "parse-gram.y"
+#line 199 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
 /* Line 819 of yacc.c  */
-#line 1166 "parse-gram.c"
+#line 1164 "parse-gram.c"
 	break;
       case 88: /* "id_colon" */
 
 /* Line 819 of yacc.c  */
-#line 201 "parse-gram.y"
+#line 200 "parse-gram.y"
 	{ fprintf (stderr, "%s:", (yyvaluep->symbol)->tag); };
 
 /* Line 819 of yacc.c  */
-#line 1175 "parse-gram.c"
+#line 1173 "parse-gram.c"
 	break;
       case 89: /* "symbol" */
 
 /* Line 819 of yacc.c  */
-#line 200 "parse-gram.y"
+#line 199 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
 /* Line 819 of yacc.c  */
-#line 1184 "parse-gram.c"
+#line 1182 "parse-gram.c"
 	break;
       case 90: /* "string_as_id" */
 
 /* Line 819 of yacc.c  */
-#line 200 "parse-gram.y"
+#line 199 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
 /* Line 819 of yacc.c  */
-#line 1193 "parse-gram.c"
+#line 1191 "parse-gram.c"
 	break;
       default:
 	break;
@@ -1981,7 +1979,7 @@ YYLTYPE yylloc;
 /* User initialization code.  */
 
 /* Line 1590 of yacc.c  */
-#line 87 "parse-gram.y"
+#line 86 "parse-gram.y"
 {
   /* Bison's grammar can initial empty locations, hence a default
      location is needed. */
@@ -1990,7 +1988,7 @@ YYLTYPE yylloc;
 }
 
 /* Line 1590 of yacc.c  */
-#line 1994 "parse-gram.c"
+#line 1992 "parse-gram.c"
   yylsp[0] = yylloc;
 
   goto yysetstate;
@@ -2185,7 +2183,7 @@ yyreduce:
           case 6:
 
 /* Line 1806 of yacc.c  */
-#line 226 "parse-gram.y"
+#line 225 "parse-gram.y"
     {
       code_props plain_code;
       code_props_plain_init (&plain_code, (yyvsp[(1) - (1)].chars), (yylsp[(1) - (1)]));
@@ -2200,14 +2198,14 @@ yyreduce:
   case 7:
 
 /* Line 1806 of yacc.c  */
-#line 235 "parse-gram.y"
+#line 234 "parse-gram.y"
     { debug_flag = true; }
     break;
 
   case 8:
 
 /* Line 1806 of yacc.c  */
-#line 237 "parse-gram.y"
+#line 236 "parse-gram.y"
     {
       muscle_percent_define_insert ((yyvsp[(2) - (3)].uniqstr), (yylsp[(2) - (3)]), (yyvsp[(3) - (3)].chars),
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
@@ -2217,14 +2215,14 @@ yyreduce:
   case 9:
 
 /* Line 1806 of yacc.c  */
-#line 241 "parse-gram.y"
+#line 240 "parse-gram.y"
     { defines_flag = true; }
     break;
 
   case 10:
 
 /* Line 1806 of yacc.c  */
-#line 243 "parse-gram.y"
+#line 242 "parse-gram.y"
     {
       defines_flag = true;
       spec_defines_file = xstrdup ((yyvsp[(2) - (2)].chars));
@@ -2234,42 +2232,42 @@ yyreduce:
   case 11:
 
 /* Line 1806 of yacc.c  */
-#line 247 "parse-gram.y"
+#line 246 "parse-gram.y"
     { error_verbose = true; }
     break;
 
   case 12:
 
 /* Line 1806 of yacc.c  */
-#line 248 "parse-gram.y"
+#line 247 "parse-gram.y"
     { expected_sr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 13:
 
 /* Line 1806 of yacc.c  */
-#line 249 "parse-gram.y"
+#line 248 "parse-gram.y"
     { expected_rr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 14:
 
 /* Line 1806 of yacc.c  */
-#line 250 "parse-gram.y"
+#line 249 "parse-gram.y"
     { spec_file_prefix = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 15:
 
 /* Line 1806 of yacc.c  */
-#line 251 "parse-gram.y"
+#line 250 "parse-gram.y"
     { spec_file_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 16:
 
 /* Line 1806 of yacc.c  */
-#line 253 "parse-gram.y"
+#line 252 "parse-gram.y"
     {
       nondeterministic_parser = true;
       glr_parser = true;
@@ -2279,7 +2277,7 @@ yyreduce:
   case 17:
 
 /* Line 1806 of yacc.c  */
-#line 258 "parse-gram.y"
+#line 257 "parse-gram.y"
     {
       code_props action;
       code_props_symbol_action_init (&action, (yyvsp[(2) - (2)].code), (yylsp[(2) - (2)]));
@@ -2293,77 +2291,77 @@ yyreduce:
   case 18:
 
 /* Line 1806 of yacc.c  */
-#line 266 "parse-gram.y"
+#line 265 "parse-gram.y"
     { language_argmatch ((yyvsp[(2) - (2)].chars), grammar_prio, (yylsp[(1) - (2)])); }
     break;
 
   case 19:
 
 /* Line 1806 of yacc.c  */
-#line 267 "parse-gram.y"
+#line 266 "parse-gram.y"
     { add_param ("lex_param", (yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
     break;
 
   case 20:
 
 /* Line 1806 of yacc.c  */
-#line 268 "parse-gram.y"
+#line 267 "parse-gram.y"
     { locations_flag = true; }
     break;
 
   case 21:
 
 /* Line 1806 of yacc.c  */
-#line 269 "parse-gram.y"
+#line 268 "parse-gram.y"
     { spec_name_prefix = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 22:
 
 /* Line 1806 of yacc.c  */
-#line 270 "parse-gram.y"
+#line 269 "parse-gram.y"
     { spec_name_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 23:
 
 /* Line 1806 of yacc.c  */
-#line 271 "parse-gram.y"
+#line 270 "parse-gram.y"
     { no_lines_flag = true; }
     break;
 
   case 24:
 
 /* Line 1806 of yacc.c  */
-#line 272 "parse-gram.y"
+#line 271 "parse-gram.y"
     { nondeterministic_parser = true; }
     break;
 
   case 25:
 
 /* Line 1806 of yacc.c  */
-#line 273 "parse-gram.y"
+#line 272 "parse-gram.y"
     { spec_outfile = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 26:
 
 /* Line 1806 of yacc.c  */
-#line 274 "parse-gram.y"
+#line 273 "parse-gram.y"
     { spec_outfile = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 27:
 
 /* Line 1806 of yacc.c  */
-#line 275 "parse-gram.y"
+#line 274 "parse-gram.y"
     { add_param ("parse_param", (yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
     break;
 
   case 28:
 
 /* Line 1806 of yacc.c  */
-#line 277 "parse-gram.y"
+#line 276 "parse-gram.y"
     {
       /* %pure-parser is deprecated in favor of `%define api.pure', so use
          `%define api.pure' in a backward-compatible manner here.  First, don't
@@ -2383,14 +2381,14 @@ yyreduce:
   case 29:
 
 /* Line 1806 of yacc.c  */
-#line 291 "parse-gram.y"
+#line 290 "parse-gram.y"
     { version_check (&(yylsp[(2) - (2)]), (yyvsp[(2) - (2)].chars)); }
     break;
 
   case 30:
 
 /* Line 1806 of yacc.c  */
-#line 293 "parse-gram.y"
+#line 292 "parse-gram.y"
     {
       char const *skeleton_user = (yyvsp[(2) - (2)].chars);
       if (strchr (skeleton_user, '/'))
@@ -2419,28 +2417,28 @@ yyreduce:
   case 31:
 
 /* Line 1806 of yacc.c  */
-#line 316 "parse-gram.y"
+#line 315 "parse-gram.y"
     { token_table_flag = true; }
     break;
 
   case 32:
 
 /* Line 1806 of yacc.c  */
-#line 317 "parse-gram.y"
+#line 316 "parse-gram.y"
     { report_flag |= report_states; }
     break;
 
   case 33:
 
 /* Line 1806 of yacc.c  */
-#line 318 "parse-gram.y"
+#line 317 "parse-gram.y"
     { yacc_flag = true; }
     break;
 
   case 37:
 
 /* Line 1806 of yacc.c  */
-#line 326 "parse-gram.y"
+#line 325 "parse-gram.y"
     {
       grammar_start_symbol_set ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]));
     }
@@ -2449,7 +2447,7 @@ yyreduce:
   case 38:
 
 /* Line 1806 of yacc.c  */
-#line 330 "parse-gram.y"
+#line 329 "parse-gram.y"
     {
       symbol_list *list;
       for (list = (yyvsp[(3) - (3)].list); list; list = list->next)
@@ -2461,7 +2459,7 @@ yyreduce:
   case 39:
 
 /* Line 1806 of yacc.c  */
-#line 337 "parse-gram.y"
+#line 336 "parse-gram.y"
     {
       symbol_list *list;
       for (list = (yyvsp[(3) - (3)].list); list; list = list->next)
@@ -2473,7 +2471,7 @@ yyreduce:
   case 40:
 
 /* Line 1806 of yacc.c  */
-#line 344 "parse-gram.y"
+#line 343 "parse-gram.y"
     {
       default_prec = true;
     }
@@ -2482,7 +2480,7 @@ yyreduce:
   case 41:
 
 /* Line 1806 of yacc.c  */
-#line 348 "parse-gram.y"
+#line 347 "parse-gram.y"
     {
       default_prec = false;
     }
@@ -2491,7 +2489,7 @@ yyreduce:
   case 42:
 
 /* Line 1806 of yacc.c  */
-#line 352 "parse-gram.y"
+#line 351 "parse-gram.y"
     {
       /* Do not invoke muscle_percent_code_grow here since it invokes
          muscle_user_name_list_grow.  */
@@ -2503,7 +2501,7 @@ yyreduce:
   case 43:
 
 /* Line 1806 of yacc.c  */
-#line 359 "parse-gram.y"
+#line 358 "parse-gram.y"
     {
       muscle_percent_code_grow ((yyvsp[(2) - (3)].uniqstr), (yylsp[(2) - (3)]), (yyvsp[(3) - (3)].chars), (yylsp[(3) - (3)]));
       code_scanner_last_string_free ();
@@ -2513,21 +2511,21 @@ yyreduce:
   case 44:
 
 /* Line 1806 of yacc.c  */
-#line 373 "parse-gram.y"
+#line 372 "parse-gram.y"
     {}
     break;
 
   case 45:
 
 /* Line 1806 of yacc.c  */
-#line 374 "parse-gram.y"
+#line 373 "parse-gram.y"
     { muscle_code_grow ("union_name", (yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 46:
 
 /* Line 1806 of yacc.c  */
-#line 379 "parse-gram.y"
+#line 378 "parse-gram.y"
     {
       union_seen = true;
       muscle_code_grow ("stype", (yyvsp[(3) - (3)].chars), (yylsp[(3) - (3)]));
@@ -2538,14 +2536,14 @@ yyreduce:
   case 47:
 
 /* Line 1806 of yacc.c  */
-#line 390 "parse-gram.y"
+#line 389 "parse-gram.y"
     { current_class = nterm_sym; }
     break;
 
   case 48:
 
 /* Line 1806 of yacc.c  */
-#line 391 "parse-gram.y"
+#line 390 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
@@ -2555,14 +2553,14 @@ yyreduce:
   case 49:
 
 /* Line 1806 of yacc.c  */
-#line 395 "parse-gram.y"
+#line 394 "parse-gram.y"
     { current_class = token_sym; }
     break;
 
   case 50:
 
 /* Line 1806 of yacc.c  */
-#line 396 "parse-gram.y"
+#line 395 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
@@ -2572,7 +2570,7 @@ yyreduce:
   case 51:
 
 /* Line 1806 of yacc.c  */
-#line 401 "parse-gram.y"
+#line 400 "parse-gram.y"
     {
       symbol_list *list;
       tag_seen = true;
@@ -2585,7 +2583,7 @@ yyreduce:
   case 52:
 
 /* Line 1806 of yacc.c  */
-#line 412 "parse-gram.y"
+#line 411 "parse-gram.y"
     {
       symbol_list *list;
       ++current_prec;
@@ -2602,126 +2600,126 @@ yyreduce:
   case 53:
 
 /* Line 1806 of yacc.c  */
-#line 426 "parse-gram.y"
+#line 425 "parse-gram.y"
     { (yyval.assoc) = left_assoc; }
     break;
 
   case 54:
 
 /* Line 1806 of yacc.c  */
-#line 427 "parse-gram.y"
+#line 426 "parse-gram.y"
     { (yyval.assoc) = right_assoc; }
     break;
 
   case 55:
 
 /* Line 1806 of yacc.c  */
-#line 428 "parse-gram.y"
+#line 427 "parse-gram.y"
     { (yyval.assoc) = non_assoc; }
     break;
 
   case 56:
 
 /* Line 1806 of yacc.c  */
-#line 432 "parse-gram.y"
+#line 431 "parse-gram.y"
     { current_type = NULL; }
     break;
 
   case 57:
 
 /* Line 1806 of yacc.c  */
-#line 433 "parse-gram.y"
+#line 432 "parse-gram.y"
     { current_type = (yyvsp[(1) - (1)].uniqstr); tag_seen = true; }
     break;
 
   case 58:
 
 /* Line 1806 of yacc.c  */
-#line 439 "parse-gram.y"
+#line 438 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 59:
 
 /* Line 1806 of yacc.c  */
-#line 441 "parse-gram.y"
+#line 440 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), symbol_list_sym_new ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]))); }
     break;
 
   case 60:
 
 /* Line 1806 of yacc.c  */
-#line 445 "parse-gram.y"
+#line 444 "parse-gram.y"
     { (yyval.symbol) = (yyvsp[(1) - (1)].symbol); }
     break;
 
   case 61:
 
 /* Line 1806 of yacc.c  */
-#line 446 "parse-gram.y"
+#line 445 "parse-gram.y"
     { (yyval.symbol) = (yyvsp[(1) - (2)].symbol); symbol_user_token_number_set ((yyvsp[(1) - (2)].symbol), (yyvsp[(2) - (2)].integer), (yylsp[(2) - (2)])); }
     break;
 
   case 62:
 
 /* Line 1806 of yacc.c  */
-#line 452 "parse-gram.y"
+#line 451 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 63:
 
 /* Line 1806 of yacc.c  */
-#line 454 "parse-gram.y"
+#line 453 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), symbol_list_sym_new ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]))); }
     break;
 
   case 64:
 
 /* Line 1806 of yacc.c  */
-#line 458 "parse-gram.y"
+#line 457 "parse-gram.y"
     { (yyval.list) = (yyvsp[(1) - (1)].list); }
     break;
 
   case 65:
 
 /* Line 1806 of yacc.c  */
-#line 459 "parse-gram.y"
+#line 458 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), (yyvsp[(2) - (2)].list)); }
     break;
 
   case 66:
 
 /* Line 1806 of yacc.c  */
-#line 463 "parse-gram.y"
+#line 462 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 67:
 
 /* Line 1806 of yacc.c  */
-#line 464 "parse-gram.y"
+#line 463 "parse-gram.y"
     { (yyval.list) = symbol_list_type_new ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 68:
 
 /* Line 1806 of yacc.c  */
-#line 465 "parse-gram.y"
+#line 464 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagged_new ((yylsp[(1) - (1)])); }
     break;
 
   case 69:
 
 /* Line 1806 of yacc.c  */
-#line 466 "parse-gram.y"
+#line 465 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagless_new ((yylsp[(1) - (1)])); }
     break;
 
   case 70:
 
 /* Line 1806 of yacc.c  */
-#line 472 "parse-gram.y"
+#line 471 "parse-gram.y"
     {
        current_type = (yyvsp[(1) - (1)].uniqstr);
        tag_seen = true;
@@ -2731,7 +2729,7 @@ yyreduce:
   case 71:
 
 /* Line 1806 of yacc.c  */
-#line 477 "parse-gram.y"
+#line 476 "parse-gram.y"
     {
        symbol_class_set ((yyvsp[(1) - (1)].symbol), current_class, (yylsp[(1) - (1)]), true);
        symbol_type_set ((yyvsp[(1) - (1)].symbol), current_type, (yylsp[(1) - (1)]));
@@ -2741,7 +2739,7 @@ yyreduce:
   case 72:
 
 /* Line 1806 of yacc.c  */
-#line 482 "parse-gram.y"
+#line 481 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
       symbol_type_set ((yyvsp[(1) - (2)].symbol), current_type, (yylsp[(1) - (2)]));
@@ -2752,7 +2750,7 @@ yyreduce:
   case 73:
 
 /* Line 1806 of yacc.c  */
-#line 488 "parse-gram.y"
+#line 487 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
       symbol_type_set ((yyvsp[(1) - (2)].symbol), current_type, (yylsp[(1) - (2)]));
@@ -2763,7 +2761,7 @@ yyreduce:
   case 74:
 
 /* Line 1806 of yacc.c  */
-#line 494 "parse-gram.y"
+#line 493 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (3)].symbol), current_class, (yylsp[(1) - (3)]), true);
       symbol_type_set ((yyvsp[(1) - (3)].symbol), current_type, (yylsp[(1) - (3)]));
@@ -2775,7 +2773,7 @@ yyreduce:
   case 81:
 
 /* Line 1806 of yacc.c  */
-#line 524 "parse-gram.y"
+#line 523 "parse-gram.y"
     {
       yyerrok;
     }
@@ -2784,7 +2782,7 @@ yyreduce:
   case 82:
 
 /* Line 1806 of yacc.c  */
-#line 530 "parse-gram.y"
+#line 529 "parse-gram.y"
     { current_lhs = (yyvsp[(1) - (2)].symbol); current_lhs_location = (yylsp[(1) - (2)]);
     current_lhs_named_ref = (yyvsp[(2) - (2)].named_ref); }
     break;
@@ -2792,21 +2790,21 @@ yyreduce:
   case 84:
 
 /* Line 1806 of yacc.c  */
-#line 535 "parse-gram.y"
+#line 534 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(1) - (1)])); }
     break;
 
   case 85:
 
 /* Line 1806 of yacc.c  */
-#line 536 "parse-gram.y"
+#line 535 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(3) - (3)])); }
     break;
 
   case 87:
 
 /* Line 1806 of yacc.c  */
-#line 542 "parse-gram.y"
+#line 541 "parse-gram.y"
     { grammar_current_rule_begin (current_lhs, current_lhs_location,
 				  current_lhs_named_ref); }
     break;
@@ -2814,77 +2812,77 @@ yyreduce:
   case 88:
 
 /* Line 1806 of yacc.c  */
-#line 545 "parse-gram.y"
+#line 544 "parse-gram.y"
     { grammar_current_rule_symbol_append ((yyvsp[(2) - (3)].symbol), (yylsp[(2) - (3)]), (yyvsp[(3) - (3)].named_ref)); }
     break;
 
   case 89:
 
 /* Line 1806 of yacc.c  */
-#line 547 "parse-gram.y"
+#line 546 "parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[(2) - (3)].code), (yylsp[(2) - (3)]), (yyvsp[(3) - (3)].named_ref)); }
     break;
 
   case 90:
 
 /* Line 1806 of yacc.c  */
-#line 549 "parse-gram.y"
+#line 548 "parse-gram.y"
     { grammar_current_rule_prec_set ((yyvsp[(3) - (3)].symbol), (yylsp[(3) - (3)])); }
     break;
 
   case 91:
 
 /* Line 1806 of yacc.c  */
-#line 551 "parse-gram.y"
+#line 550 "parse-gram.y"
     { grammar_current_rule_dprec_set ((yyvsp[(3) - (3)].integer), (yylsp[(3) - (3)])); }
     break;
 
   case 92:
 
 /* Line 1806 of yacc.c  */
-#line 553 "parse-gram.y"
+#line 552 "parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[(3) - (3)].uniqstr), (yylsp[(3) - (3)])); }
     break;
 
   case 93:
 
 /* Line 1806 of yacc.c  */
-#line 557 "parse-gram.y"
+#line 556 "parse-gram.y"
     { (yyval.named_ref) = 0; }
     break;
 
   case 94:
 
 /* Line 1806 of yacc.c  */
-#line 559 "parse-gram.y"
+#line 558 "parse-gram.y"
     { (yyval.named_ref) = named_ref_new((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 96:
 
 /* Line 1806 of yacc.c  */
-#line 571 "parse-gram.y"
+#line 570 "parse-gram.y"
     { (yyval.uniqstr) = uniqstr_new ((yyvsp[(1) - (1)].chars)); }
     break;
 
   case 97:
 
 /* Line 1806 of yacc.c  */
-#line 576 "parse-gram.y"
+#line 575 "parse-gram.y"
     { (yyval.chars) = ""; }
     break;
 
   case 98:
 
 /* Line 1806 of yacc.c  */
-#line 577 "parse-gram.y"
+#line 576 "parse-gram.y"
     { (yyval.chars) = (yyvsp[(1) - (1)].uniqstr); }
     break;
 
   case 100:
 
 /* Line 1806 of yacc.c  */
-#line 588 "parse-gram.y"
+#line 587 "parse-gram.y"
     {
       code_props plain_code;
       (yyvsp[(1) - (1)].code)[strlen ((yyvsp[(1) - (1)].code)) - 1] = '\n';
@@ -2898,14 +2896,14 @@ yyreduce:
   case 101:
 
 /* Line 1806 of yacc.c  */
-#line 608 "parse-gram.y"
+#line 607 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 102:
 
 /* Line 1806 of yacc.c  */
-#line 610 "parse-gram.y"
+#line 609 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[(1) - (1)].character)), (yylsp[(1) - (1)]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[(1) - (1)]), false);
@@ -2916,14 +2914,14 @@ yyreduce:
   case 103:
 
 /* Line 1806 of yacc.c  */
-#line 618 "parse-gram.y"
+#line 617 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 106:
 
 /* Line 1806 of yacc.c  */
-#line 630 "parse-gram.y"
+#line 629 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[(1) - (1)].chars)), (yylsp[(1) - (1)]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[(1) - (1)]), false);
@@ -2933,7 +2931,7 @@ yyreduce:
   case 108:
 
 /* Line 1806 of yacc.c  */
-#line 639 "parse-gram.y"
+#line 638 "parse-gram.y"
     {
       code_props plain_code;
       code_props_plain_init (&plain_code, (yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)]));
@@ -2947,7 +2945,7 @@ yyreduce:
 
 
 /* Line 1806 of yacc.c  */
-#line 2951 "parse-gram.c"
+#line 2949 "parse-gram.c"
         default: break;
       }
     if (yychar_backup != yychar)
@@ -3197,7 +3195,7 @@ yyreturn:
 
 
 /* Line 2067 of yacc.c  */
-#line 649 "parse-gram.y"
+#line 648 "parse-gram.y"
 
 
 
