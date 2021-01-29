@@ -1,9 +1,8 @@
-/* A Bison parser, made by GNU Bison 2.4.1.173-62efdd.  */
+/* A Bison parser, made by GNU Bison 2.4.1.184-510df.  */
 
 /* Skeleton implementation for Bison's Yacc-like parsers in C
    
-      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006,
-   2007, 2008, 2009 Free Software Foundation, Inc.
+      Copyright (C) 1984, 1989-1990, 2000-2010 Free Software Foundation, Inc.
    
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
@@ -45,7 +44,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "2.4.1.173-62efdd"
+#define YYBISON_VERSION "2.4.1.184-510df"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -74,12 +73,11 @@
 
 /* Copy the first part of user declarations.  */
 
-/* Line 252 of yacc.c  */
+/* Line 251 of yacc.c  */
 #line 1 "parse-gram.y"
 /* Bison Grammar Parser                             -*- C -*-
 
-   Copyright (C) 2002, 2003, 2004, 2005, 2006, 2007, 2008, 2009 Free
-   Software Foundation, Inc.
+   Copyright (C) 2002-2010 Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -151,8 +149,8 @@ static int current_prec = 0;
 #define YYTYPE_UINT8 uint_fast8_t
 
 
-/* Line 252 of yacc.c  */
-#line 156 "parse-gram.c"
+/* Line 251 of yacc.c  */
+#line 154 "parse-gram.c"
 
 /* Enabling traces.  */
 #ifndef YYDEBUG
@@ -302,8 +300,8 @@ static int current_prec = 0;
 typedef union YYSTYPE
 {
 
-/* Line 277 of yacc.c  */
-#line 94 "parse-gram.y"
+/* Line 276 of yacc.c  */
+#line 93 "parse-gram.y"
 
   symbol *symbol;
   symbol_list *list;
@@ -317,8 +315,8 @@ typedef union YYSTYPE
 
 
 
-/* Line 277 of yacc.c  */
-#line 322 "parse-gram.c"
+/* Line 276 of yacc.c  */
+#line 320 "parse-gram.c"
 } YYSTYPE;
 # define YYSTYPE_IS_TRIVIAL 1
 # define yystype YYSTYPE /* obsolescent; will be withdrawn */
@@ -342,8 +340,8 @@ typedef struct YYLTYPE
 /* Copy the second part of user declarations.  */
 
 
-/* Line 327 of yacc.c  */
-#line 347 "parse-gram.c"
+/* Line 326 of yacc.c  */
+#line 345 "parse-gram.c"
 
 #ifdef short
 # undef short
@@ -669,17 +667,17 @@ static const yytype_int8 yyrhs[] =
 /* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
 static const yytype_uint16 yyrline[] =
 {
-       0,   209,   209,   217,   219,   223,   224,   234,   235,   240,
-     241,   246,   247,   248,   249,   250,   251,   256,   265,   266,
-     267,   268,   269,   270,   271,   272,   273,   274,   275,   290,
-     291,   315,   316,   317,   318,   322,   323,   324,   328,   335,
-     342,   346,   350,   357,   372,   373,   377,   389,   389,   394,
-     394,   399,   410,   425,   426,   427,   431,   432,   437,   439,
-     444,   445,   450,   452,   457,   458,   462,   463,   464,   465,
-     470,   475,   480,   486,   492,   503,   504,   513,   514,   520,
-     521,   522,   529,   529,   534,   535,   536,   541,   543,   545,
-     547,   549,   551,   556,   558,   569,   570,   575,   576,   577,
-     586,   606,   608,   617,   622,   623,   628,   635,   637
+       0,   208,   208,   216,   218,   222,   223,   233,   234,   239,
+     240,   245,   246,   247,   248,   249,   250,   255,   264,   265,
+     266,   267,   268,   269,   270,   271,   272,   273,   274,   289,
+     290,   314,   315,   316,   317,   321,   322,   323,   327,   334,
+     341,   345,   349,   356,   371,   372,   376,   388,   388,   393,
+     393,   398,   409,   424,   425,   426,   430,   431,   436,   438,
+     443,   444,   449,   451,   456,   457,   461,   462,   463,   464,
+     469,   474,   479,   485,   491,   502,   503,   512,   513,   519,
+     520,   521,   528,   528,   533,   534,   535,   540,   542,   544,
+     546,   548,   550,   555,   557,   568,   569,   574,   575,   576,
+     585,   605,   607,   616,   621,   622,   627,   634,   636
 };
 #endif
 
@@ -1049,165 +1047,165 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
     {
       case 3: /* "\"string\"" */
 
-/* Line 798 of yacc.c  */
-#line 184 "parse-gram.y"
+/* Line 797 of yacc.c  */
+#line 183 "parse-gram.y"
 	{ fputs (quotearg_style (c_quoting_style, (yyvaluep->chars)), stderr); };
 
-/* Line 798 of yacc.c  */
-#line 1058 "parse-gram.c"
+/* Line 797 of yacc.c  */
+#line 1056 "parse-gram.c"
 	break;
       case 4: /* "\"integer\"" */
 
-/* Line 798 of yacc.c  */
-#line 196 "parse-gram.y"
+/* Line 797 of yacc.c  */
+#line 195 "parse-gram.y"
 	{ fprintf (stderr, "%d", (yyvaluep->integer)); };
 
-/* Line 798 of yacc.c  */
-#line 1067 "parse-gram.c"
+/* Line 797 of yacc.c  */
+#line 1065 "parse-gram.c"
 	break;
       case 43: /* "\"{...}\"" */
 
-/* Line 798 of yacc.c  */
-#line 186 "parse-gram.y"
+/* Line 797 of yacc.c  */
+#line 185 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->code)); };
 
-/* Line 798 of yacc.c  */
-#line 1076 "parse-gram.c"
+/* Line 797 of yacc.c  */
+#line 1074 "parse-gram.c"
 	break;
       case 44: /* "\"[identifier]\"" */
 
-/* Line 798 of yacc.c  */
-#line 191 "parse-gram.y"
+/* Line 797 of yacc.c  */
+#line 190 "parse-gram.y"
 	{ fprintf (stderr, "[%s]", (yyvaluep->uniqstr)); };
 
-/* Line 798 of yacc.c  */
-#line 1085 "parse-gram.c"
+/* Line 797 of yacc.c  */
+#line 1083 "parse-gram.c"
 	break;
       case 45: /* "\"char\"" */
 
-/* Line 798 of yacc.c  */
-#line 178 "parse-gram.y"
+/* Line 797 of yacc.c  */
+#line 177 "parse-gram.y"
 	{ fputs (char_name ((yyvaluep->character)), stderr); };
 
-/* Line 798 of yacc.c  */
-#line 1094 "parse-gram.c"
+/* Line 797 of yacc.c  */
+#line 1092 "parse-gram.c"
 	break;
       case 46: /* "\"epilogue\"" */
 
-/* Line 798 of yacc.c  */
-#line 186 "parse-gram.y"
+/* Line 797 of yacc.c  */
+#line 185 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
-/* Line 798 of yacc.c  */
-#line 1103 "parse-gram.c"
+/* Line 797 of yacc.c  */
+#line 1101 "parse-gram.c"
 	break;
       case 48: /* "\"identifier\"" */
 
-/* Line 798 of yacc.c  */
-#line 190 "parse-gram.y"
+/* Line 797 of yacc.c  */
+#line 189 "parse-gram.y"
 	{ fputs ((yyvaluep->uniqstr), stderr); };
 
-/* Line 798 of yacc.c  */
-#line 1112 "parse-gram.c"
+/* Line 797 of yacc.c  */
+#line 1110 "parse-gram.c"
 	break;
       case 49: /* "\"identifier:\"" */
 
-/* Line 798 of yacc.c  */
-#line 192 "parse-gram.y"
+/* Line 797 of yacc.c  */
+#line 191 "parse-gram.y"
 	{ fprintf (stderr, "%s:", (yyvaluep->uniqstr)); };
 
-/* Line 798 of yacc.c  */
-#line 1121 "parse-gram.c"
+/* Line 797 of yacc.c  */
+#line 1119 "parse-gram.c"
 	break;
       case 52: /* "\"%{...%}\"" */
 
-/* Line 798 of yacc.c  */
-#line 186 "parse-gram.y"
+/* Line 797 of yacc.c  */
+#line 185 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
-/* Line 798 of yacc.c  */
-#line 1130 "parse-gram.c"
+/* Line 797 of yacc.c  */
+#line 1128 "parse-gram.c"
 	break;
       case 54: /* "\"type\"" */
 
-/* Line 798 of yacc.c  */
-#line 193 "parse-gram.y"
+/* Line 797 of yacc.c  */
+#line 192 "parse-gram.y"
 	{ fprintf (stderr, "<%s>", (yyvaluep->uniqstr)); };
 
-/* Line 798 of yacc.c  */
-#line 1139 "parse-gram.c"
+/* Line 797 of yacc.c  */
+#line 1137 "parse-gram.c"
 	break;
       case 71: /* "symbol.prec" */
 
-/* Line 798 of yacc.c  */
-#line 199 "parse-gram.y"
+/* Line 797 of yacc.c  */
+#line 198 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
-/* Line 798 of yacc.c  */
-#line 1148 "parse-gram.c"
+/* Line 797 of yacc.c  */
+#line 1146 "parse-gram.c"
 	break;
       case 84: /* "variable" */
 
-/* Line 798 of yacc.c  */
-#line 190 "parse-gram.y"
+/* Line 797 of yacc.c  */
+#line 189 "parse-gram.y"
 	{ fputs ((yyvaluep->uniqstr), stderr); };
 
-/* Line 798 of yacc.c  */
-#line 1157 "parse-gram.c"
+/* Line 797 of yacc.c  */
+#line 1155 "parse-gram.c"
 	break;
       case 85: /* "content.opt" */
 
-/* Line 798 of yacc.c  */
-#line 186 "parse-gram.y"
+/* Line 797 of yacc.c  */
+#line 185 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
-/* Line 798 of yacc.c  */
-#line 1166 "parse-gram.c"
+/* Line 797 of yacc.c  */
+#line 1164 "parse-gram.c"
 	break;
       case 86: /* "braceless" */
 
-/* Line 798 of yacc.c  */
-#line 186 "parse-gram.y"
+/* Line 797 of yacc.c  */
+#line 185 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
-/* Line 798 of yacc.c  */
-#line 1175 "parse-gram.c"
+/* Line 797 of yacc.c  */
+#line 1173 "parse-gram.c"
 	break;
       case 87: /* "id" */
 
-/* Line 798 of yacc.c  */
-#line 199 "parse-gram.y"
+/* Line 797 of yacc.c  */
+#line 198 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
-/* Line 798 of yacc.c  */
-#line 1184 "parse-gram.c"
+/* Line 797 of yacc.c  */
+#line 1182 "parse-gram.c"
 	break;
       case 88: /* "id_colon" */
 
-/* Line 798 of yacc.c  */
-#line 200 "parse-gram.y"
+/* Line 797 of yacc.c  */
+#line 199 "parse-gram.y"
 	{ fprintf (stderr, "%s:", (yyvaluep->symbol)->tag); };
 
-/* Line 798 of yacc.c  */
-#line 1193 "parse-gram.c"
+/* Line 797 of yacc.c  */
+#line 1191 "parse-gram.c"
 	break;
       case 89: /* "symbol" */
 
-/* Line 798 of yacc.c  */
-#line 199 "parse-gram.y"
+/* Line 797 of yacc.c  */
+#line 198 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
-/* Line 798 of yacc.c  */
-#line 1202 "parse-gram.c"
+/* Line 797 of yacc.c  */
+#line 1200 "parse-gram.c"
 	break;
       case 90: /* "string_as_id" */
 
-/* Line 798 of yacc.c  */
-#line 199 "parse-gram.y"
+/* Line 797 of yacc.c  */
+#line 198 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
-/* Line 798 of yacc.c  */
-#line 1211 "parse-gram.c"
+/* Line 797 of yacc.c  */
+#line 1209 "parse-gram.c"
 	break;
       default:
 	break;
@@ -1734,8 +1732,8 @@ YYLTYPE yylloc;
 
 /* User initialization code.  */
 
-/* Line 1281 of yacc.c  */
-#line 86 "parse-gram.y"
+/* Line 1280 of yacc.c  */
+#line 85 "parse-gram.y"
 {
   /* Bison's grammar can initial empty locations, hence a default
      location is needed. */
@@ -1743,8 +1741,8 @@ YYLTYPE yylloc;
   boundary_set (&yylloc.end, current_file, 1, 1);
 }
 
-/* Line 1281 of yacc.c  */
-#line 1748 "parse-gram.c"
+/* Line 1280 of yacc.c  */
+#line 1746 "parse-gram.c"
   yylsp[0] = yylloc;
 
   goto yysetstate;
@@ -1931,8 +1929,8 @@ yyreduce:
     {
         case 6:
 
-/* Line 1494 of yacc.c  */
-#line 225 "parse-gram.y"
+/* Line 1493 of yacc.c  */
+#line 224 "parse-gram.y"
     {
       code_props plain_code;
       code_props_plain_init (&plain_code, (yyvsp[(1) - (1)].chars), (yylsp[(1) - (1)]));
@@ -1946,15 +1944,15 @@ yyreduce:
 
   case 7:
 
-/* Line 1494 of yacc.c  */
-#line 234 "parse-gram.y"
+/* Line 1493 of yacc.c  */
+#line 233 "parse-gram.y"
     { debug_flag = true; }
     break;
 
   case 8:
 
-/* Line 1494 of yacc.c  */
-#line 236 "parse-gram.y"
+/* Line 1493 of yacc.c  */
+#line 235 "parse-gram.y"
     {
       muscle_percent_define_insert ((yyvsp[(2) - (3)].uniqstr), (yylsp[(2) - (3)]), (yyvsp[(3) - (3)].chars),
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
@@ -1963,15 +1961,15 @@ yyreduce:
 
   case 9:
 
-/* Line 1494 of yacc.c  */
-#line 240 "parse-gram.y"
+/* Line 1493 of yacc.c  */
+#line 239 "parse-gram.y"
     { defines_flag = true; }
     break;
 
   case 10:
 
-/* Line 1494 of yacc.c  */
-#line 242 "parse-gram.y"
+/* Line 1493 of yacc.c  */
+#line 241 "parse-gram.y"
     {
       defines_flag = true;
       spec_defines_file = xstrdup ((yyvsp[(2) - (2)].chars));
@@ -1980,43 +1978,43 @@ yyreduce:
 
   case 11:
 
-/* Line 1494 of yacc.c  */
-#line 246 "parse-gram.y"
+/* Line 1493 of yacc.c  */
+#line 245 "parse-gram.y"
     { error_verbose = true; }
     break;
 
   case 12:
 
-/* Line 1494 of yacc.c  */
-#line 247 "parse-gram.y"
+/* Line 1493 of yacc.c  */
+#line 246 "parse-gram.y"
     { expected_sr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 13:
 
-/* Line 1494 of yacc.c  */
-#line 248 "parse-gram.y"
+/* Line 1493 of yacc.c  */
+#line 247 "parse-gram.y"
     { expected_rr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 14:
 
-/* Line 1494 of yacc.c  */
-#line 249 "parse-gram.y"
+/* Line 1493 of yacc.c  */
+#line 248 "parse-gram.y"
     { spec_file_prefix = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 15:
 
-/* Line 1494 of yacc.c  */
-#line 250 "parse-gram.y"
+/* Line 1493 of yacc.c  */
+#line 249 "parse-gram.y"
     { spec_file_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 16:
 
-/* Line 1494 of yacc.c  */
-#line 252 "parse-gram.y"
+/* Line 1493 of yacc.c  */
+#line 251 "parse-gram.y"
     {
       nondeterministic_parser = true;
       glr_parser = true;
@@ -2025,8 +2023,8 @@ yyreduce:
 
   case 17:
 
-/* Line 1494 of yacc.c  */
-#line 257 "parse-gram.y"
+/* Line 1493 of yacc.c  */
+#line 256 "parse-gram.y"
     {
       code_props action;
       code_props_symbol_action_init (&action, (yyvsp[(2) - (2)].code), (yylsp[(2) - (2)]));
@@ -2039,78 +2037,78 @@ yyreduce:
 
   case 18:
 
-/* Line 1494 of yacc.c  */
-#line 265 "parse-gram.y"
+/* Line 1493 of yacc.c  */
+#line 264 "parse-gram.y"
     { language_argmatch ((yyvsp[(2) - (2)].chars), grammar_prio, (yylsp[(1) - (2)])); }
     break;
 
   case 19:
 
-/* Line 1494 of yacc.c  */
-#line 266 "parse-gram.y"
+/* Line 1493 of yacc.c  */
+#line 265 "parse-gram.y"
     { add_param ("lex_param", (yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
     break;
 
   case 20:
 
-/* Line 1494 of yacc.c  */
-#line 267 "parse-gram.y"
+/* Line 1493 of yacc.c  */
+#line 266 "parse-gram.y"
     { locations_flag = true; }
     break;
 
   case 21:
 
-/* Line 1494 of yacc.c  */
-#line 268 "parse-gram.y"
+/* Line 1493 of yacc.c  */
+#line 267 "parse-gram.y"
     { spec_name_prefix = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 22:
 
-/* Line 1494 of yacc.c  */
-#line 269 "parse-gram.y"
+/* Line 1493 of yacc.c  */
+#line 268 "parse-gram.y"
     { spec_name_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 23:
 
-/* Line 1494 of yacc.c  */
-#line 270 "parse-gram.y"
+/* Line 1493 of yacc.c  */
+#line 269 "parse-gram.y"
     { no_lines_flag = true; }
     break;
 
   case 24:
 
-/* Line 1494 of yacc.c  */
-#line 271 "parse-gram.y"
+/* Line 1493 of yacc.c  */
+#line 270 "parse-gram.y"
     { nondeterministic_parser = true; }
     break;
 
   case 25:
 
-/* Line 1494 of yacc.c  */
-#line 272 "parse-gram.y"
+/* Line 1493 of yacc.c  */
+#line 271 "parse-gram.y"
     { spec_outfile = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 26:
 
-/* Line 1494 of yacc.c  */
-#line 273 "parse-gram.y"
+/* Line 1493 of yacc.c  */
+#line 272 "parse-gram.y"
     { spec_outfile = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 27:
 
-/* Line 1494 of yacc.c  */
-#line 274 "parse-gram.y"
+/* Line 1493 of yacc.c  */
+#line 273 "parse-gram.y"
     { add_param ("parse_param", (yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
     break;
 
   case 28:
 
-/* Line 1494 of yacc.c  */
-#line 276 "parse-gram.y"
+/* Line 1493 of yacc.c  */
+#line 275 "parse-gram.y"
     {
       /* %pure-parser is deprecated in favor of `%define api.pure', so use
          `%define api.pure' in a backward-compatible manner here.  First, don't
@@ -2129,15 +2127,15 @@ yyreduce:
 
   case 29:
 
-/* Line 1494 of yacc.c  */
-#line 290 "parse-gram.y"
+/* Line 1493 of yacc.c  */
+#line 289 "parse-gram.y"
     { version_check (&(yylsp[(2) - (2)]), (yyvsp[(2) - (2)].chars)); }
     break;
 
   case 30:
 
-/* Line 1494 of yacc.c  */
-#line 292 "parse-gram.y"
+/* Line 1493 of yacc.c  */
+#line 291 "parse-gram.y"
     {
       char const *skeleton_user = (yyvsp[(2) - (2)].chars);
       if (strchr (skeleton_user, '/'))
@@ -2165,29 +2163,29 @@ yyreduce:
 
   case 31:
 
-/* Line 1494 of yacc.c  */
-#line 315 "parse-gram.y"
+/* Line 1493 of yacc.c  */
+#line 314 "parse-gram.y"
     { token_table_flag = true; }
     break;
 
   case 32:
 
-/* Line 1494 of yacc.c  */
-#line 316 "parse-gram.y"
+/* Line 1493 of yacc.c  */
+#line 315 "parse-gram.y"
     { report_flag |= report_states; }
     break;
 
   case 33:
 
-/* Line 1494 of yacc.c  */
-#line 317 "parse-gram.y"
+/* Line 1493 of yacc.c  */
+#line 316 "parse-gram.y"
     { yacc_flag = true; }
     break;
 
   case 37:
 
-/* Line 1494 of yacc.c  */
-#line 325 "parse-gram.y"
+/* Line 1493 of yacc.c  */
+#line 324 "parse-gram.y"
     {
       grammar_start_symbol_set ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]));
     }
@@ -2195,8 +2193,8 @@ yyreduce:
 
   case 38:
 
-/* Line 1494 of yacc.c  */
-#line 329 "parse-gram.y"
+/* Line 1493 of yacc.c  */
+#line 328 "parse-gram.y"
     {
       symbol_list *list;
       for (list = (yyvsp[(3) - (3)].list); list; list = list->next)
@@ -2207,8 +2205,8 @@ yyreduce:
 
   case 39:
 
-/* Line 1494 of yacc.c  */
-#line 336 "parse-gram.y"
+/* Line 1493 of yacc.c  */
+#line 335 "parse-gram.y"
     {
       symbol_list *list;
       for (list = (yyvsp[(3) - (3)].list); list; list = list->next)
@@ -2219,8 +2217,8 @@ yyreduce:
 
   case 40:
 
-/* Line 1494 of yacc.c  */
-#line 343 "parse-gram.y"
+/* Line 1493 of yacc.c  */
+#line 342 "parse-gram.y"
     {
       default_prec = true;
     }
@@ -2228,8 +2226,8 @@ yyreduce:
 
   case 41:
 
-/* Line 1494 of yacc.c  */
-#line 347 "parse-gram.y"
+/* Line 1493 of yacc.c  */
+#line 346 "parse-gram.y"
     {
       default_prec = false;
     }
@@ -2237,8 +2235,8 @@ yyreduce:
 
   case 42:
 
-/* Line 1494 of yacc.c  */
-#line 351 "parse-gram.y"
+/* Line 1493 of yacc.c  */
+#line 350 "parse-gram.y"
     {
       /* Do not invoke muscle_percent_code_grow here since it invokes
          muscle_user_name_list_grow.  */
@@ -2249,8 +2247,8 @@ yyreduce:
 
   case 43:
 
-/* Line 1494 of yacc.c  */
-#line 358 "parse-gram.y"
+/* Line 1493 of yacc.c  */
+#line 357 "parse-gram.y"
     {
       muscle_percent_code_grow ((yyvsp[(2) - (3)].uniqstr), (yylsp[(2) - (3)]), (yyvsp[(3) - (3)].chars), (yylsp[(3) - (3)]));
       code_scanner_last_string_free ();
@@ -2259,22 +2257,22 @@ yyreduce:
 
   case 44:
 
-/* Line 1494 of yacc.c  */
-#line 372 "parse-gram.y"
+/* Line 1493 of yacc.c  */
+#line 371 "parse-gram.y"
     {}
     break;
 
   case 45:
 
-/* Line 1494 of yacc.c  */
-#line 373 "parse-gram.y"
+/* Line 1493 of yacc.c  */
+#line 372 "parse-gram.y"
     { muscle_code_grow ("union_name", (yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 46:
 
-/* Line 1494 of yacc.c  */
-#line 378 "parse-gram.y"
+/* Line 1493 of yacc.c  */
+#line 377 "parse-gram.y"
     {
       union_seen = true;
       muscle_code_grow ("stype", (yyvsp[(3) - (3)].chars), (yylsp[(3) - (3)]));
@@ -2284,15 +2282,15 @@ yyreduce:
 
   case 47:
 
-/* Line 1494 of yacc.c  */
-#line 389 "parse-gram.y"
+/* Line 1493 of yacc.c  */
+#line 388 "parse-gram.y"
     { current_class = nterm_sym; }
     break;
 
   case 48:
 
-/* Line 1494 of yacc.c  */
-#line 390 "parse-gram.y"
+/* Line 1493 of yacc.c  */
+#line 389 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
@@ -2301,15 +2299,15 @@ yyreduce:
 
   case 49:
 
-/* Line 1494 of yacc.c  */
-#line 394 "parse-gram.y"
+/* Line 1493 of yacc.c  */
+#line 393 "parse-gram.y"
     { current_class = token_sym; }
     break;
 
   case 50:
 
-/* Line 1494 of yacc.c  */
-#line 395 "parse-gram.y"
+/* Line 1493 of yacc.c  */
+#line 394 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
@@ -2318,8 +2316,8 @@ yyreduce:
 
   case 51:
 
-/* Line 1494 of yacc.c  */
-#line 400 "parse-gram.y"
+/* Line 1493 of yacc.c  */
+#line 399 "parse-gram.y"
     {
       symbol_list *list;
       tag_seen = true;
@@ -2331,8 +2329,8 @@ yyreduce:
 
   case 52:
 
-/* Line 1494 of yacc.c  */
-#line 411 "parse-gram.y"
+/* Line 1493 of yacc.c  */
+#line 410 "parse-gram.y"
     {
       symbol_list *list;
       ++current_prec;
@@ -2348,127 +2346,127 @@ yyreduce:
 
   case 53:
 
-/* Line 1494 of yacc.c  */
-#line 425 "parse-gram.y"
+/* Line 1493 of yacc.c  */
+#line 424 "parse-gram.y"
     { (yyval.assoc) = left_assoc; }
     break;
 
   case 54:
 
-/* Line 1494 of yacc.c  */
-#line 426 "parse-gram.y"
+/* Line 1493 of yacc.c  */
+#line 425 "parse-gram.y"
     { (yyval.assoc) = right_assoc; }
     break;
 
   case 55:
 
-/* Line 1494 of yacc.c  */
-#line 427 "parse-gram.y"
+/* Line 1493 of yacc.c  */
+#line 426 "parse-gram.y"
     { (yyval.assoc) = non_assoc; }
     break;
 
   case 56:
 
-/* Line 1494 of yacc.c  */
-#line 431 "parse-gram.y"
+/* Line 1493 of yacc.c  */
+#line 430 "parse-gram.y"
     { current_type = NULL; }
     break;
 
   case 57:
 
-/* Line 1494 of yacc.c  */
-#line 432 "parse-gram.y"
+/* Line 1493 of yacc.c  */
+#line 431 "parse-gram.y"
     { current_type = (yyvsp[(1) - (1)].uniqstr); tag_seen = true; }
     break;
 
   case 58:
 
-/* Line 1494 of yacc.c  */
-#line 438 "parse-gram.y"
+/* Line 1493 of yacc.c  */
+#line 437 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 59:
 
-/* Line 1494 of yacc.c  */
-#line 440 "parse-gram.y"
+/* Line 1493 of yacc.c  */
+#line 439 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), symbol_list_sym_new ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]))); }
     break;
 
   case 60:
 
-/* Line 1494 of yacc.c  */
-#line 444 "parse-gram.y"
+/* Line 1493 of yacc.c  */
+#line 443 "parse-gram.y"
     { (yyval.symbol) = (yyvsp[(1) - (1)].symbol); }
     break;
 
   case 61:
 
-/* Line 1494 of yacc.c  */
-#line 445 "parse-gram.y"
+/* Line 1493 of yacc.c  */
+#line 444 "parse-gram.y"
     { (yyval.symbol) = (yyvsp[(1) - (2)].symbol); symbol_user_token_number_set ((yyvsp[(1) - (2)].symbol), (yyvsp[(2) - (2)].integer), (yylsp[(2) - (2)])); }
     break;
 
   case 62:
 
-/* Line 1494 of yacc.c  */
-#line 451 "parse-gram.y"
+/* Line 1493 of yacc.c  */
+#line 450 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 63:
 
-/* Line 1494 of yacc.c  */
-#line 453 "parse-gram.y"
+/* Line 1493 of yacc.c  */
+#line 452 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), symbol_list_sym_new ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]))); }
     break;
 
   case 64:
 
-/* Line 1494 of yacc.c  */
-#line 457 "parse-gram.y"
+/* Line 1493 of yacc.c  */
+#line 456 "parse-gram.y"
     { (yyval.list) = (yyvsp[(1) - (1)].list); }
     break;
 
   case 65:
 
-/* Line 1494 of yacc.c  */
-#line 458 "parse-gram.y"
+/* Line 1493 of yacc.c  */
+#line 457 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), (yyvsp[(2) - (2)].list)); }
     break;
 
   case 66:
 
-/* Line 1494 of yacc.c  */
-#line 462 "parse-gram.y"
+/* Line 1493 of yacc.c  */
+#line 461 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 67:
 
-/* Line 1494 of yacc.c  */
-#line 463 "parse-gram.y"
+/* Line 1493 of yacc.c  */
+#line 462 "parse-gram.y"
     { (yyval.list) = symbol_list_type_new ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 68:
 
-/* Line 1494 of yacc.c  */
-#line 464 "parse-gram.y"
+/* Line 1493 of yacc.c  */
+#line 463 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagged_new ((yylsp[(1) - (1)])); }
     break;
 
   case 69:
 
-/* Line 1494 of yacc.c  */
-#line 465 "parse-gram.y"
+/* Line 1493 of yacc.c  */
+#line 464 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagless_new ((yylsp[(1) - (1)])); }
     break;
 
   case 70:
 
-/* Line 1494 of yacc.c  */
-#line 471 "parse-gram.y"
+/* Line 1493 of yacc.c  */
+#line 470 "parse-gram.y"
     {
        current_type = (yyvsp[(1) - (1)].uniqstr);
        tag_seen = true;
@@ -2477,8 +2475,8 @@ yyreduce:
 
   case 71:
 
-/* Line 1494 of yacc.c  */
-#line 476 "parse-gram.y"
+/* Line 1493 of yacc.c  */
+#line 475 "parse-gram.y"
     {
        symbol_class_set ((yyvsp[(1) - (1)].symbol), current_class, (yylsp[(1) - (1)]), true);
        symbol_type_set ((yyvsp[(1) - (1)].symbol), current_type, (yylsp[(1) - (1)]));
@@ -2487,8 +2485,8 @@ yyreduce:
 
   case 72:
 
-/* Line 1494 of yacc.c  */
-#line 481 "parse-gram.y"
+/* Line 1493 of yacc.c  */
+#line 480 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
       symbol_type_set ((yyvsp[(1) - (2)].symbol), current_type, (yylsp[(1) - (2)]));
@@ -2498,8 +2496,8 @@ yyreduce:
 
   case 73:
 
-/* Line 1494 of yacc.c  */
-#line 487 "parse-gram.y"
+/* Line 1493 of yacc.c  */
+#line 486 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
       symbol_type_set ((yyvsp[(1) - (2)].symbol), current_type, (yylsp[(1) - (2)]));
@@ -2509,8 +2507,8 @@ yyreduce:
 
   case 74:
 
-/* Line 1494 of yacc.c  */
-#line 493 "parse-gram.y"
+/* Line 1493 of yacc.c  */
+#line 492 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (3)].symbol), current_class, (yylsp[(1) - (3)]), true);
       symbol_type_set ((yyvsp[(1) - (3)].symbol), current_type, (yylsp[(1) - (3)]));
@@ -2521,8 +2519,8 @@ yyreduce:
 
   case 81:
 
-/* Line 1494 of yacc.c  */
-#line 523 "parse-gram.y"
+/* Line 1493 of yacc.c  */
+#line 522 "parse-gram.y"
     {
       yyerrok;
     }
@@ -2530,108 +2528,108 @@ yyreduce:
 
   case 82:
 
-/* Line 1494 of yacc.c  */
-#line 529 "parse-gram.y"
+/* Line 1493 of yacc.c  */
+#line 528 "parse-gram.y"
     { current_lhs = (yyvsp[(1) - (2)].symbol); current_lhs_location = (yylsp[(1) - (2)]);
     current_lhs_named_ref = (yyvsp[(2) - (2)].named_ref); }
     break;
 
   case 84:
 
-/* Line 1494 of yacc.c  */
-#line 534 "parse-gram.y"
+/* Line 1493 of yacc.c  */
+#line 533 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(1) - (1)])); }
     break;
 
   case 85:
 
-/* Line 1494 of yacc.c  */
-#line 535 "parse-gram.y"
+/* Line 1493 of yacc.c  */
+#line 534 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(3) - (3)])); }
     break;
 
   case 87:
 
-/* Line 1494 of yacc.c  */
-#line 541 "parse-gram.y"
+/* Line 1493 of yacc.c  */
+#line 540 "parse-gram.y"
     { grammar_current_rule_begin (current_lhs, current_lhs_location,
 				  current_lhs_named_ref); }
     break;
 
   case 88:
 
-/* Line 1494 of yacc.c  */
-#line 544 "parse-gram.y"
+/* Line 1493 of yacc.c  */
+#line 543 "parse-gram.y"
     { grammar_current_rule_symbol_append ((yyvsp[(2) - (3)].symbol), (yylsp[(2) - (3)]), (yyvsp[(3) - (3)].named_ref)); }
     break;
 
   case 89:
 
-/* Line 1494 of yacc.c  */
-#line 546 "parse-gram.y"
+/* Line 1493 of yacc.c  */
+#line 545 "parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[(2) - (3)].code), (yylsp[(2) - (3)]), (yyvsp[(3) - (3)].named_ref)); }
     break;
 
   case 90:
 
-/* Line 1494 of yacc.c  */
-#line 548 "parse-gram.y"
+/* Line 1493 of yacc.c  */
+#line 547 "parse-gram.y"
     { grammar_current_rule_prec_set ((yyvsp[(3) - (3)].symbol), (yylsp[(3) - (3)])); }
     break;
 
   case 91:
 
-/* Line 1494 of yacc.c  */
-#line 550 "parse-gram.y"
+/* Line 1493 of yacc.c  */
+#line 549 "parse-gram.y"
     { grammar_current_rule_dprec_set ((yyvsp[(3) - (3)].integer), (yylsp[(3) - (3)])); }
     break;
 
   case 92:
 
-/* Line 1494 of yacc.c  */
-#line 552 "parse-gram.y"
+/* Line 1493 of yacc.c  */
+#line 551 "parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[(3) - (3)].uniqstr), (yylsp[(3) - (3)])); }
     break;
 
   case 93:
 
-/* Line 1494 of yacc.c  */
-#line 556 "parse-gram.y"
+/* Line 1493 of yacc.c  */
+#line 555 "parse-gram.y"
     { (yyval.named_ref) = 0; }
     break;
 
   case 94:
 
-/* Line 1494 of yacc.c  */
-#line 558 "parse-gram.y"
+/* Line 1493 of yacc.c  */
+#line 557 "parse-gram.y"
     { (yyval.named_ref) = named_ref_new((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 96:
 
-/* Line 1494 of yacc.c  */
-#line 570 "parse-gram.y"
+/* Line 1493 of yacc.c  */
+#line 569 "parse-gram.y"
     { (yyval.uniqstr) = uniqstr_new ((yyvsp[(1) - (1)].chars)); }
     break;
 
   case 97:
 
-/* Line 1494 of yacc.c  */
-#line 575 "parse-gram.y"
+/* Line 1493 of yacc.c  */
+#line 574 "parse-gram.y"
     { (yyval.chars) = ""; }
     break;
 
   case 98:
 
-/* Line 1494 of yacc.c  */
-#line 576 "parse-gram.y"
+/* Line 1493 of yacc.c  */
+#line 575 "parse-gram.y"
     { (yyval.chars) = (yyvsp[(1) - (1)].uniqstr); }
     break;
 
   case 100:
 
-/* Line 1494 of yacc.c  */
-#line 587 "parse-gram.y"
+/* Line 1493 of yacc.c  */
+#line 586 "parse-gram.y"
     {
       code_props plain_code;
       (yyvsp[(1) - (1)].code)[strlen ((yyvsp[(1) - (1)].code)) - 1] = '\n';
@@ -2644,15 +2642,15 @@ yyreduce:
 
   case 101:
 
-/* Line 1494 of yacc.c  */
-#line 607 "parse-gram.y"
+/* Line 1493 of yacc.c  */
+#line 606 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 102:
 
-/* Line 1494 of yacc.c  */
-#line 609 "parse-gram.y"
+/* Line 1493 of yacc.c  */
+#line 608 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[(1) - (1)].character)), (yylsp[(1) - (1)]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[(1) - (1)]), false);
@@ -2662,15 +2660,15 @@ yyreduce:
 
   case 103:
 
-/* Line 1494 of yacc.c  */
-#line 617 "parse-gram.y"
+/* Line 1493 of yacc.c  */
+#line 616 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 106:
 
-/* Line 1494 of yacc.c  */
-#line 629 "parse-gram.y"
+/* Line 1493 of yacc.c  */
+#line 628 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[(1) - (1)].chars)), (yylsp[(1) - (1)]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[(1) - (1)]), false);
@@ -2679,8 +2677,8 @@ yyreduce:
 
   case 108:
 
-/* Line 1494 of yacc.c  */
-#line 638 "parse-gram.y"
+/* Line 1493 of yacc.c  */
+#line 637 "parse-gram.y"
     {
       code_props plain_code;
       code_props_plain_init (&plain_code, (yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)]));
@@ -2693,8 +2691,8 @@ yyreduce:
 
 
 
-/* Line 1494 of yacc.c  */
-#line 2698 "parse-gram.c"
+/* Line 1493 of yacc.c  */
+#line 2696 "parse-gram.c"
       default: break;
     }
   /* User semantic actions sometimes alter yychar, and that requires
@@ -2923,8 +2921,8 @@ yyreturn:
 
 
 
-/* Line 1725 of yacc.c  */
-#line 648 "parse-gram.y"
+/* Line 1724 of yacc.c  */
+#line 647 "parse-gram.y"
 
 
 
