@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 2.6.1.12-3153-dirty.  */
+/* A Bison parser, made by GNU Bison 2.6.2.13-429e.  */
 
 /* Bison implementation for Yacc-like parsers in C
    
@@ -44,7 +44,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "2.6.1.12-3153-dirty"
+#define YYBISON_VERSION "2.6.2.13-429e"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -167,7 +167,7 @@ current_lhs(symbol *sym, location loc, named_ref *ref)
 #define YYTYPE_UINT8 uint_fast8_t
 
 /* Line 336 of yacc.c  */
-#line 170 "parse-gram.c"
+#line 171 "parse-gram.c"
 
 # ifndef YY_NULL
 #  if defined __cplusplus && 201103L <= __cplusplus
@@ -324,8 +324,8 @@ extern int gram_debug;
 #if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
 typedef union YYSTYPE
 {
-/* Line 350 of yacc.c  */
-#line 114 "parse-gram.y"
+/* Line 352 of yacc.c  */
+#line 115 "parse-gram.y"
 
   symbol *symbol;
   symbol_list *list;
@@ -338,8 +338,8 @@ typedef union YYSTYPE
   named_ref *named_ref;
 
 
-/* Line 350 of yacc.c  */
-#line 342 "parse-gram.c"
+/* Line 352 of yacc.c  */
+#line 343 "parse-gram.c"
 } YYSTYPE;
 # define YYSTYPE_IS_TRIVIAL 1
 # define yystype YYSTYPE /* obsolescent; will be withdrawn */
@@ -378,8 +378,8 @@ int gram_parse ();
 
 /* Copy the second part of user declarations.  */
 
-/* Line 353 of yacc.c  */
-#line 382 "parse-gram.c"
+/* Line 355 of yacc.c  */
+#line 383 "parse-gram.c"
 
 #ifdef short
 # undef short
@@ -686,17 +686,17 @@ static const yytype_int8 yyrhs[] =
 /* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
 static const yytype_uint16 yyrline[] =
 {
-       0,   229,   229,   237,   239,   243,   244,   254,   255,   260,
-     261,   266,   267,   268,   269,   270,   271,   276,   285,   286,
-     287,   288,   289,   290,   291,   292,   293,   294,   295,   310,
-     311,   335,   336,   337,   338,   342,   343,   344,   348,   360,
-     372,   376,   380,   387,   402,   403,   407,   419,   419,   424,
-     424,   429,   440,   455,   456,   457,   461,   462,   467,   469,
-     474,   475,   480,   482,   487,   488,   492,   493,   494,   495,
-     500,   505,   510,   516,   522,   533,   534,   543,   544,   550,
-     551,   552,   559,   559,   567,   568,   569,   574,   576,   578,
-     580,   582,   584,   589,   591,   602,   603,   608,   609,   610,
-     619,   639,   641,   650,   655,   656,   661,   668,   670
+       0,   230,   230,   238,   240,   244,   245,   255,   256,   261,
+     262,   267,   268,   269,   270,   271,   272,   277,   286,   287,
+     288,   289,   290,   291,   292,   293,   294,   295,   296,   311,
+     312,   336,   337,   338,   339,   343,   344,   345,   349,   361,
+     373,   377,   381,   388,   403,   404,   408,   420,   420,   425,
+     425,   430,   441,   456,   457,   458,   462,   463,   468,   470,
+     475,   476,   481,   483,   488,   489,   493,   494,   495,   496,
+     501,   506,   511,   517,   523,   534,   535,   544,   545,   551,
+     552,   553,   560,   560,   568,   569,   570,   575,   577,   579,
+     581,   583,   585,   590,   592,   603,   604,   609,   610,   611,
+     620,   640,   642,   651,   656,   657,   662,   669,   671
 };
 #endif
 
@@ -1070,130 +1070,130 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
   switch (yytype)
     {
       case 3: /* "string" */
-/* Line 809 of yacc.c  */
-#line 204 "parse-gram.y"
+/* Line 811 of yacc.c  */
+#line 205 "parse-gram.y"
 	{ fputs (quotearg_style (c_quoting_style, ((*yyvaluep).chars)), stderr); };
-/* Line 809 of yacc.c  */
-#line 1077 "parse-gram.c"
+/* Line 811 of yacc.c  */
+#line 1078 "parse-gram.c"
 	break;
       case 4: /* "integer" */
-/* Line 809 of yacc.c  */
-#line 216 "parse-gram.y"
+/* Line 811 of yacc.c  */
+#line 217 "parse-gram.y"
 	{ fprintf (stderr, "%d", ((*yyvaluep).integer)); };
-/* Line 809 of yacc.c  */
-#line 1084 "parse-gram.c"
+/* Line 811 of yacc.c  */
+#line 1085 "parse-gram.c"
 	break;
       case 43: /* "{...}" */
-/* Line 809 of yacc.c  */
-#line 206 "parse-gram.y"
+/* Line 811 of yacc.c  */
+#line 207 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", ((*yyvaluep).code)); };
-/* Line 809 of yacc.c  */
-#line 1091 "parse-gram.c"
+/* Line 811 of yacc.c  */
+#line 1092 "parse-gram.c"
 	break;
       case 44: /* "[identifier]" */
-/* Line 809 of yacc.c  */
-#line 211 "parse-gram.y"
+/* Line 811 of yacc.c  */
+#line 212 "parse-gram.y"
 	{ fprintf (stderr, "[%s]", ((*yyvaluep).uniqstr)); };
-/* Line 809 of yacc.c  */
-#line 1098 "parse-gram.c"
+/* Line 811 of yacc.c  */
+#line 1099 "parse-gram.c"
 	break;
       case 45: /* "char" */
-/* Line 809 of yacc.c  */
-#line 198 "parse-gram.y"
+/* Line 811 of yacc.c  */
+#line 199 "parse-gram.y"
 	{ fputs (char_name (((*yyvaluep).character)), stderr); };
-/* Line 809 of yacc.c  */
-#line 1105 "parse-gram.c"
+/* Line 811 of yacc.c  */
+#line 1106 "parse-gram.c"
 	break;
       case 46: /* "epilogue" */
-/* Line 809 of yacc.c  */
-#line 206 "parse-gram.y"
+/* Line 811 of yacc.c  */
+#line 207 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); };
-/* Line 809 of yacc.c  */
-#line 1112 "parse-gram.c"
+/* Line 811 of yacc.c  */
+#line 1113 "parse-gram.c"
 	break;
       case 48: /* "identifier" */
-/* Line 809 of yacc.c  */
-#line 210 "parse-gram.y"
+/* Line 811 of yacc.c  */
+#line 211 "parse-gram.y"
 	{ fputs (((*yyvaluep).uniqstr), stderr); };
-/* Line 809 of yacc.c  */
-#line 1119 "parse-gram.c"
+/* Line 811 of yacc.c  */
+#line 1120 "parse-gram.c"
 	break;
       case 49: /* "identifier:" */
-/* Line 809 of yacc.c  */
-#line 212 "parse-gram.y"
+/* Line 811 of yacc.c  */
+#line 213 "parse-gram.y"
 	{ fprintf (stderr, "%s:", ((*yyvaluep).uniqstr)); };
-/* Line 809 of yacc.c  */
-#line 1126 "parse-gram.c"
+/* Line 811 of yacc.c  */
+#line 1127 "parse-gram.c"
 	break;
       case 52: /* "%{...%}" */
-/* Line 809 of yacc.c  */
-#line 206 "parse-gram.y"
+/* Line 811 of yacc.c  */
+#line 207 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); };
-/* Line 809 of yacc.c  */
-#line 1133 "parse-gram.c"
+/* Line 811 of yacc.c  */
+#line 1134 "parse-gram.c"
 	break;
       case 54: /* "type" */
-/* Line 809 of yacc.c  */
-#line 213 "parse-gram.y"
+/* Line 811 of yacc.c  */
+#line 214 "parse-gram.y"
 	{ fprintf (stderr, "<%s>", ((*yyvaluep).uniqstr)); };
-/* Line 809 of yacc.c  */
-#line 1140 "parse-gram.c"
+/* Line 811 of yacc.c  */
+#line 1141 "parse-gram.c"
 	break;
       case 71: /* symbol.prec */
-/* Line 809 of yacc.c  */
-#line 219 "parse-gram.y"
+/* Line 811 of yacc.c  */
+#line 220 "parse-gram.y"
 	{ fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); };
-/* Line 809 of yacc.c  */
-#line 1147 "parse-gram.c"
+/* Line 811 of yacc.c  */
+#line 1148 "parse-gram.c"
 	break;
       case 84: /* variable */
-/* Line 809 of yacc.c  */
-#line 210 "parse-gram.y"
+/* Line 811 of yacc.c  */
+#line 211 "parse-gram.y"
 	{ fputs (((*yyvaluep).uniqstr), stderr); };
-/* Line 809 of yacc.c  */
-#line 1154 "parse-gram.c"
+/* Line 811 of yacc.c  */
+#line 1155 "parse-gram.c"
 	break;
       case 85: /* content.opt */
-/* Line 809 of yacc.c  */
-#line 206 "parse-gram.y"
+/* Line 811 of yacc.c  */
+#line 207 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); };
-/* Line 809 of yacc.c  */
-#line 1161 "parse-gram.c"
+/* Line 811 of yacc.c  */
+#line 1162 "parse-gram.c"
 	break;
       case 86: /* braceless */
-/* Line 809 of yacc.c  */
-#line 206 "parse-gram.y"
+/* Line 811 of yacc.c  */
+#line 207 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); };
-/* Line 809 of yacc.c  */
-#line 1168 "parse-gram.c"
+/* Line 811 of yacc.c  */
+#line 1169 "parse-gram.c"
 	break;
       case 87: /* id */
-/* Line 809 of yacc.c  */
-#line 219 "parse-gram.y"
+/* Line 811 of yacc.c  */
+#line 220 "parse-gram.y"
 	{ fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); };
-/* Line 809 of yacc.c  */
-#line 1175 "parse-gram.c"
+/* Line 811 of yacc.c  */
+#line 1176 "parse-gram.c"
 	break;
       case 88: /* id_colon */
-/* Line 809 of yacc.c  */
-#line 220 "parse-gram.y"
+/* Line 811 of yacc.c  */
+#line 221 "parse-gram.y"
 	{ fprintf (stderr, "%s:", ((*yyvaluep).symbol)->tag); };
-/* Line 809 of yacc.c  */
-#line 1182 "parse-gram.c"
+/* Line 811 of yacc.c  */
+#line 1183 "parse-gram.c"
 	break;
       case 89: /* symbol */
-/* Line 809 of yacc.c  */
-#line 219 "parse-gram.y"
+/* Line 811 of yacc.c  */
+#line 220 "parse-gram.y"
 	{ fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); };
-/* Line 809 of yacc.c  */
-#line 1189 "parse-gram.c"
+/* Line 811 of yacc.c  */
+#line 1190 "parse-gram.c"
 	break;
       case 90: /* string_as_id */
-/* Line 809 of yacc.c  */
-#line 219 "parse-gram.y"
+/* Line 811 of yacc.c  */
+#line 220 "parse-gram.y"
 	{ fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); };
-/* Line 809 of yacc.c  */
-#line 1196 "parse-gram.c"
+/* Line 811 of yacc.c  */
+#line 1197 "parse-gram.c"
 	break;
       default:
 	break;
@@ -1917,7 +1917,7 @@ YYLTYPE yylloc;
   int yyn;
   int yyresult;
   /* Lookahead token as an internal (translated) token number.  */
-  int yytoken;
+  int yytoken = 0;
   /* The variables used to return semantic value and location from the
      action routines.  */
   YYSTYPE yyval;
@@ -1936,7 +1936,6 @@ YYLTYPE yylloc;
      Keep to zero when no symbol should be popped.  */
   int yylen = 0;
 
-  yytoken = 0;
   yyss = yyssa;
   yyvs = yyvsa;
   yyls = yylsa;
@@ -1969,15 +1968,15 @@ YYLTYPE yylloc;
 #endif
 
 /* User initialization code.  */
-/* Line 1572 of yacc.c  */
-#line 106 "parse-gram.y"
+/* Line 1573 of yacc.c  */
+#line 107 "parse-gram.y"
 {
   /* Bison's grammar can initial empty locations, hence a default
      location is needed. */
   boundary_set (&yylloc.start, current_file, 1, 1);
   boundary_set (&yylloc.end, current_file, 1, 1);
 }
-/* Line 1572 of yacc.c  */
+/* Line 1573 of yacc.c  */
 #line 1981 "parse-gram.c"
   yylsp[0] = yylloc;
   goto yysetstate;
@@ -2170,8 +2169,8 @@ yyreduce:
     switch (yyn)
       {
           case 6:
-/* Line 1787 of yacc.c  */
-#line 245 "parse-gram.y"
+/* Line 1788 of yacc.c  */
+#line 246 "parse-gram.y"
     {
       code_props plain_code;
       code_props_plain_init (&plain_code, (yyvsp[(1) - (1)].chars), (yylsp[(1) - (1)]));
@@ -2184,14 +2183,14 @@ yyreduce:
     break;
 
   case 7:
-/* Line 1787 of yacc.c  */
-#line 254 "parse-gram.y"
+/* Line 1788 of yacc.c  */
+#line 255 "parse-gram.y"
     { debug_flag = true; }
     break;
 
   case 8:
-/* Line 1787 of yacc.c  */
-#line 256 "parse-gram.y"
+/* Line 1788 of yacc.c  */
+#line 257 "parse-gram.y"
     {
       muscle_percent_define_insert ((yyvsp[(2) - (3)].uniqstr), (yylsp[(2) - (3)]), (yyvsp[(3) - (3)].chars),
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
@@ -2199,14 +2198,14 @@ yyreduce:
     break;
 
   case 9:
-/* Line 1787 of yacc.c  */
-#line 260 "parse-gram.y"
+/* Line 1788 of yacc.c  */
+#line 261 "parse-gram.y"
     { defines_flag = true; }
     break;
 
   case 10:
-/* Line 1787 of yacc.c  */
-#line 262 "parse-gram.y"
+/* Line 1788 of yacc.c  */
+#line 263 "parse-gram.y"
     {
       defines_flag = true;
       spec_defines_file = xstrdup ((yyvsp[(2) - (2)].chars));
@@ -2214,38 +2213,38 @@ yyreduce:
     break;
 
   case 11:
-/* Line 1787 of yacc.c  */
-#line 266 "parse-gram.y"
+/* Line 1788 of yacc.c  */
+#line 267 "parse-gram.y"
     { error_verbose = true; }
     break;
 
   case 12:
-/* Line 1787 of yacc.c  */
-#line 267 "parse-gram.y"
+/* Line 1788 of yacc.c  */
+#line 268 "parse-gram.y"
     { expected_sr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 13:
-/* Line 1787 of yacc.c  */
-#line 268 "parse-gram.y"
+/* Line 1788 of yacc.c  */
+#line 269 "parse-gram.y"
     { expected_rr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 14:
-/* Line 1787 of yacc.c  */
-#line 269 "parse-gram.y"
+/* Line 1788 of yacc.c  */
+#line 270 "parse-gram.y"
     { spec_file_prefix = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 15:
-/* Line 1787 of yacc.c  */
-#line 270 "parse-gram.y"
+/* Line 1788 of yacc.c  */
+#line 271 "parse-gram.y"
     { spec_file_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 16:
-/* Line 1787 of yacc.c  */
-#line 272 "parse-gram.y"
+/* Line 1788 of yacc.c  */
+#line 273 "parse-gram.y"
     {
       nondeterministic_parser = true;
       glr_parser = true;
@@ -2253,8 +2252,8 @@ yyreduce:
     break;
 
   case 17:
-/* Line 1787 of yacc.c  */
-#line 277 "parse-gram.y"
+/* Line 1788 of yacc.c  */
+#line 278 "parse-gram.y"
     {
       code_props action;
       code_props_symbol_action_init (&action, (yyvsp[(2) - (2)].code), (yylsp[(2) - (2)]));
@@ -2266,68 +2265,68 @@ yyreduce:
     break;
 
   case 18:
-/* Line 1787 of yacc.c  */
-#line 285 "parse-gram.y"
+/* Line 1788 of yacc.c  */
+#line 286 "parse-gram.y"
     { language_argmatch ((yyvsp[(2) - (2)].chars), grammar_prio, (yylsp[(1) - (2)])); }
     break;
 
   case 19:
-/* Line 1787 of yacc.c  */
-#line 286 "parse-gram.y"
+/* Line 1788 of yacc.c  */
+#line 287 "parse-gram.y"
     { add_param ("lex_param", (yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
     break;
 
   case 20:
-/* Line 1787 of yacc.c  */
-#line 287 "parse-gram.y"
+/* Line 1788 of yacc.c  */
+#line 288 "parse-gram.y"
     { locations_flag = true; }
     break;
 
   case 21:
-/* Line 1787 of yacc.c  */
-#line 288 "parse-gram.y"
+/* Line 1788 of yacc.c  */
+#line 289 "parse-gram.y"
     { spec_name_prefix = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 22:
-/* Line 1787 of yacc.c  */
-#line 289 "parse-gram.y"
+/* Line 1788 of yacc.c  */
+#line 290 "parse-gram.y"
     { spec_name_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 23:
-/* Line 1787 of yacc.c  */
-#line 290 "parse-gram.y"
+/* Line 1788 of yacc.c  */
+#line 291 "parse-gram.y"
     { no_lines_flag = true; }
     break;
 
   case 24:
-/* Line 1787 of yacc.c  */
-#line 291 "parse-gram.y"
+/* Line 1788 of yacc.c  */
+#line 292 "parse-gram.y"
     { nondeterministic_parser = true; }
     break;
 
   case 25:
-/* Line 1787 of yacc.c  */
-#line 292 "parse-gram.y"
+/* Line 1788 of yacc.c  */
+#line 293 "parse-gram.y"
     { spec_outfile = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 26:
-/* Line 1787 of yacc.c  */
-#line 293 "parse-gram.y"
+/* Line 1788 of yacc.c  */
+#line 294 "parse-gram.y"
     { spec_outfile = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 27:
-/* Line 1787 of yacc.c  */
-#line 294 "parse-gram.y"
+/* Line 1788 of yacc.c  */
+#line 295 "parse-gram.y"
     { add_param ("parse_param", (yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
     break;
 
   case 28:
-/* Line 1787 of yacc.c  */
-#line 296 "parse-gram.y"
+/* Line 1788 of yacc.c  */
+#line 297 "parse-gram.y"
     {
       /* %pure-parser is deprecated in favor of `%define api.pure', so use
          `%define api.pure' in a backward-compatible manner here.  First, don't
@@ -2345,14 +2344,14 @@ yyreduce:
     break;
 
   case 29:
-/* Line 1787 of yacc.c  */
-#line 310 "parse-gram.y"
+/* Line 1788 of yacc.c  */
+#line 311 "parse-gram.y"
     { version_check (&(yylsp[(2) - (2)]), (yyvsp[(2) - (2)].chars)); }
     break;
 
   case 30:
-/* Line 1787 of yacc.c  */
-#line 312 "parse-gram.y"
+/* Line 1788 of yacc.c  */
+#line 313 "parse-gram.y"
     {
       char const *skeleton_user = (yyvsp[(2) - (2)].chars);
       if (mbschr (skeleton_user, '/'))
@@ -2379,34 +2378,34 @@ yyreduce:
     break;
 
   case 31:
-/* Line 1787 of yacc.c  */
-#line 335 "parse-gram.y"
+/* Line 1788 of yacc.c  */
+#line 336 "parse-gram.y"
     { token_table_flag = true; }
     break;
 
   case 32:
-/* Line 1787 of yacc.c  */
-#line 336 "parse-gram.y"
+/* Line 1788 of yacc.c  */
+#line 337 "parse-gram.y"
     { report_flag |= report_states; }
     break;
 
   case 33:
-/* Line 1787 of yacc.c  */
-#line 337 "parse-gram.y"
+/* Line 1788 of yacc.c  */
+#line 338 "parse-gram.y"
     { yacc_flag = true; }
     break;
 
   case 37:
-/* Line 1787 of yacc.c  */
-#line 345 "parse-gram.y"
+/* Line 1788 of yacc.c  */
+#line 346 "parse-gram.y"
     {
       grammar_start_symbol_set ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]));
     }
     break;
 
   case 38:
-/* Line 1787 of yacc.c  */
-#line 349 "parse-gram.y"
+/* Line 1788 of yacc.c  */
+#line 350 "parse-gram.y"
     {
       code_props code;
       code_props_symbol_action_init (&code, (yyvsp[(2) - (3)].code), (yylsp[(2) - (3)]));
@@ -2421,8 +2420,8 @@ yyreduce:
     break;
 
   case 39:
-/* Line 1787 of yacc.c  */
-#line 361 "parse-gram.y"
+/* Line 1788 of yacc.c  */
+#line 362 "parse-gram.y"
     {
       code_props code;
       code_props_symbol_action_init (&code, (yyvsp[(2) - (3)].code), (yylsp[(2) - (3)]));
@@ -2437,24 +2436,24 @@ yyreduce:
     break;
 
   case 40:
-/* Line 1787 of yacc.c  */
-#line 373 "parse-gram.y"
+/* Line 1788 of yacc.c  */
+#line 374 "parse-gram.y"
     {
       default_prec = true;
     }
     break;
 
   case 41:
-/* Line 1787 of yacc.c  */
-#line 377 "parse-gram.y"
+/* Line 1788 of yacc.c  */
+#line 378 "parse-gram.y"
     {
       default_prec = false;
     }
     break;
 
   case 42:
-/* Line 1787 of yacc.c  */
-#line 381 "parse-gram.y"
+/* Line 1788 of yacc.c  */
+#line 382 "parse-gram.y"
     {
       /* Do not invoke muscle_percent_code_grow here since it invokes
          muscle_user_name_list_grow.  */
@@ -2464,8 +2463,8 @@ yyreduce:
     break;
 
   case 43:
-/* Line 1787 of yacc.c  */
-#line 388 "parse-gram.y"
+/* Line 1788 of yacc.c  */
+#line 389 "parse-gram.y"
     {
       muscle_percent_code_grow ((yyvsp[(2) - (3)].uniqstr), (yylsp[(2) - (3)]), (yyvsp[(3) - (3)].chars), (yylsp[(3) - (3)]));
       code_scanner_last_string_free ();
@@ -2473,20 +2472,20 @@ yyreduce:
     break;
 
   case 44:
-/* Line 1787 of yacc.c  */
-#line 402 "parse-gram.y"
+/* Line 1788 of yacc.c  */
+#line 403 "parse-gram.y"
     {}
     break;
 
   case 45:
-/* Line 1787 of yacc.c  */
-#line 403 "parse-gram.y"
+/* Line 1788 of yacc.c  */
+#line 404 "parse-gram.y"
     { muscle_code_grow ("union_name", (yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 46:
-/* Line 1787 of yacc.c  */
-#line 408 "parse-gram.y"
+/* Line 1788 of yacc.c  */
+#line 409 "parse-gram.y"
     {
       union_seen = true;
       muscle_code_grow ("stype", (yyvsp[(3) - (3)].chars), (yylsp[(3) - (3)]));
@@ -2495,14 +2494,14 @@ yyreduce:
     break;
 
   case 47:
-/* Line 1787 of yacc.c  */
-#line 419 "parse-gram.y"
+/* Line 1788 of yacc.c  */
+#line 420 "parse-gram.y"
     { current_class = nterm_sym; }
     break;
 
   case 48:
-/* Line 1787 of yacc.c  */
-#line 420 "parse-gram.y"
+/* Line 1788 of yacc.c  */
+#line 421 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
@@ -2510,14 +2509,14 @@ yyreduce:
     break;
 
   case 49:
-/* Line 1787 of yacc.c  */
-#line 424 "parse-gram.y"
+/* Line 1788 of yacc.c  */
+#line 425 "parse-gram.y"
     { current_class = token_sym; }
     break;
 
   case 50:
-/* Line 1787 of yacc.c  */
-#line 425 "parse-gram.y"
+/* Line 1788 of yacc.c  */
+#line 426 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
@@ -2525,8 +2524,8 @@ yyreduce:
     break;
 
   case 51:
-/* Line 1787 of yacc.c  */
-#line 430 "parse-gram.y"
+/* Line 1788 of yacc.c  */
+#line 431 "parse-gram.y"
     {
       symbol_list *list;
       tag_seen = true;
@@ -2537,8 +2536,8 @@ yyreduce:
     break;
 
   case 52:
-/* Line 1787 of yacc.c  */
-#line 441 "parse-gram.y"
+/* Line 1788 of yacc.c  */
+#line 442 "parse-gram.y"
     {
       symbol_list *list;
       ++current_prec;
@@ -2553,110 +2552,110 @@ yyreduce:
     break;
 
   case 53:
-/* Line 1787 of yacc.c  */
-#line 455 "parse-gram.y"
+/* Line 1788 of yacc.c  */
+#line 456 "parse-gram.y"
     { (yyval.assoc) = left_assoc; }
     break;
 
   case 54:
-/* Line 1787 of yacc.c  */
-#line 456 "parse-gram.y"
+/* Line 1788 of yacc.c  */
+#line 457 "parse-gram.y"
     { (yyval.assoc) = right_assoc; }
     break;
 
   case 55:
-/* Line 1787 of yacc.c  */
-#line 457 "parse-gram.y"
+/* Line 1788 of yacc.c  */
+#line 458 "parse-gram.y"
     { (yyval.assoc) = non_assoc; }
     break;
 
   case 56:
-/* Line 1787 of yacc.c  */
-#line 461 "parse-gram.y"
+/* Line 1788 of yacc.c  */
+#line 462 "parse-gram.y"
     { current_type = NULL; }
     break;
 
   case 57:
-/* Line 1787 of yacc.c  */
-#line 462 "parse-gram.y"
+/* Line 1788 of yacc.c  */
+#line 463 "parse-gram.y"
     { current_type = (yyvsp[(1) - (1)].uniqstr); tag_seen = true; }
     break;
 
   case 58:
-/* Line 1787 of yacc.c  */
-#line 468 "parse-gram.y"
+/* Line 1788 of yacc.c  */
+#line 469 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 59:
-/* Line 1787 of yacc.c  */
-#line 470 "parse-gram.y"
+/* Line 1788 of yacc.c  */
+#line 471 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), symbol_list_sym_new ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]))); }
     break;
 
   case 60:
-/* Line 1787 of yacc.c  */
-#line 474 "parse-gram.y"
+/* Line 1788 of yacc.c  */
+#line 475 "parse-gram.y"
     { (yyval.symbol) = (yyvsp[(1) - (1)].symbol); }
     break;
 
   case 61:
-/* Line 1787 of yacc.c  */
-#line 475 "parse-gram.y"
+/* Line 1788 of yacc.c  */
+#line 476 "parse-gram.y"
     { (yyval.symbol) = (yyvsp[(1) - (2)].symbol); symbol_user_token_number_set ((yyvsp[(1) - (2)].symbol), (yyvsp[(2) - (2)].integer), (yylsp[(2) - (2)])); }
     break;
 
   case 62:
-/* Line 1787 of yacc.c  */
-#line 481 "parse-gram.y"
+/* Line 1788 of yacc.c  */
+#line 482 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 63:
-/* Line 1787 of yacc.c  */
-#line 483 "parse-gram.y"
+/* Line 1788 of yacc.c  */
+#line 484 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), symbol_list_sym_new ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]))); }
     break;
 
   case 64:
-/* Line 1787 of yacc.c  */
-#line 487 "parse-gram.y"
+/* Line 1788 of yacc.c  */
+#line 488 "parse-gram.y"
     { (yyval.list) = (yyvsp[(1) - (1)].list); }
     break;
 
   case 65:
-/* Line 1787 of yacc.c  */
-#line 488 "parse-gram.y"
+/* Line 1788 of yacc.c  */
+#line 489 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), (yyvsp[(2) - (2)].list)); }
     break;
 
   case 66:
-/* Line 1787 of yacc.c  */
-#line 492 "parse-gram.y"
+/* Line 1788 of yacc.c  */
+#line 493 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 67:
-/* Line 1787 of yacc.c  */
-#line 493 "parse-gram.y"
+/* Line 1788 of yacc.c  */
+#line 494 "parse-gram.y"
     { (yyval.list) = symbol_list_type_new ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 68:
-/* Line 1787 of yacc.c  */
-#line 494 "parse-gram.y"
+/* Line 1788 of yacc.c  */
+#line 495 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagged_new ((yylsp[(1) - (1)])); }
     break;
 
   case 69:
-/* Line 1787 of yacc.c  */
-#line 495 "parse-gram.y"
+/* Line 1788 of yacc.c  */
+#line 496 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagless_new ((yylsp[(1) - (1)])); }
     break;
 
   case 70:
-/* Line 1787 of yacc.c  */
-#line 501 "parse-gram.y"
+/* Line 1788 of yacc.c  */
+#line 502 "parse-gram.y"
     {
        current_type = (yyvsp[(1) - (1)].uniqstr);
        tag_seen = true;
@@ -2664,8 +2663,8 @@ yyreduce:
     break;
 
   case 71:
-/* Line 1787 of yacc.c  */
-#line 506 "parse-gram.y"
+/* Line 1788 of yacc.c  */
+#line 507 "parse-gram.y"
     {
        symbol_class_set ((yyvsp[(1) - (1)].symbol), current_class, (yylsp[(1) - (1)]), true);
        symbol_type_set ((yyvsp[(1) - (1)].symbol), current_type, (yylsp[(1) - (1)]));
@@ -2673,8 +2672,8 @@ yyreduce:
     break;
 
   case 72:
-/* Line 1787 of yacc.c  */
-#line 511 "parse-gram.y"
+/* Line 1788 of yacc.c  */
+#line 512 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
       symbol_type_set ((yyvsp[(1) - (2)].symbol), current_type, (yylsp[(1) - (2)]));
@@ -2683,8 +2682,8 @@ yyreduce:
     break;
 
   case 73:
-/* Line 1787 of yacc.c  */
-#line 517 "parse-gram.y"
+/* Line 1788 of yacc.c  */
+#line 518 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
       symbol_type_set ((yyvsp[(1) - (2)].symbol), current_type, (yylsp[(1) - (2)]));
@@ -2693,8 +2692,8 @@ yyreduce:
     break;
 
   case 74:
-/* Line 1787 of yacc.c  */
-#line 523 "parse-gram.y"
+/* Line 1788 of yacc.c  */
+#line 524 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (3)].symbol), current_class, (yylsp[(1) - (3)]), true);
       symbol_type_set ((yyvsp[(1) - (3)].symbol), current_type, (yylsp[(1) - (3)]));
@@ -2704,22 +2703,22 @@ yyreduce:
     break;
 
   case 81:
-/* Line 1787 of yacc.c  */
-#line 553 "parse-gram.y"
+/* Line 1788 of yacc.c  */
+#line 554 "parse-gram.y"
     {
       yyerrok;
     }
     break;
 
   case 82:
-/* Line 1787 of yacc.c  */
-#line 559 "parse-gram.y"
+/* Line 1788 of yacc.c  */
+#line 560 "parse-gram.y"
     { current_lhs ((yyvsp[(1) - (2)].symbol), (yylsp[(1) - (2)]), (yyvsp[(2) - (2)].named_ref)); }
     break;
 
   case 83:
-/* Line 1787 of yacc.c  */
-#line 560 "parse-gram.y"
+/* Line 1788 of yacc.c  */
+#line 561 "parse-gram.y"
     {
     /* Free the current lhs. */
     current_lhs (0, (yylsp[(1) - (4)]), 0);
@@ -2727,87 +2726,87 @@ yyreduce:
     break;
 
   case 84:
-/* Line 1787 of yacc.c  */
-#line 567 "parse-gram.y"
+/* Line 1788 of yacc.c  */
+#line 568 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(1) - (1)])); }
     break;
 
   case 85:
-/* Line 1787 of yacc.c  */
-#line 568 "parse-gram.y"
+/* Line 1788 of yacc.c  */
+#line 569 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(3) - (3)])); }
     break;
 
   case 87:
-/* Line 1787 of yacc.c  */
-#line 574 "parse-gram.y"
+/* Line 1788 of yacc.c  */
+#line 575 "parse-gram.y"
     { grammar_current_rule_begin (current_lhs_symbol, current_lhs_location,
 				  current_lhs_named_ref); }
     break;
 
   case 88:
-/* Line 1787 of yacc.c  */
-#line 577 "parse-gram.y"
+/* Line 1788 of yacc.c  */
+#line 578 "parse-gram.y"
     { grammar_current_rule_symbol_append ((yyvsp[(2) - (3)].symbol), (yylsp[(2) - (3)]), (yyvsp[(3) - (3)].named_ref)); }
     break;
 
   case 89:
-/* Line 1787 of yacc.c  */
-#line 579 "parse-gram.y"
+/* Line 1788 of yacc.c  */
+#line 580 "parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[(2) - (3)].code), (yylsp[(2) - (3)]), (yyvsp[(3) - (3)].named_ref)); }
     break;
 
   case 90:
-/* Line 1787 of yacc.c  */
-#line 581 "parse-gram.y"
+/* Line 1788 of yacc.c  */
+#line 582 "parse-gram.y"
     { grammar_current_rule_prec_set ((yyvsp[(3) - (3)].symbol), (yylsp[(3) - (3)])); }
     break;
 
   case 91:
-/* Line 1787 of yacc.c  */
-#line 583 "parse-gram.y"
+/* Line 1788 of yacc.c  */
+#line 584 "parse-gram.y"
     { grammar_current_rule_dprec_set ((yyvsp[(3) - (3)].integer), (yylsp[(3) - (3)])); }
     break;
 
   case 92:
-/* Line 1787 of yacc.c  */
-#line 585 "parse-gram.y"
+/* Line 1788 of yacc.c  */
+#line 586 "parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[(3) - (3)].uniqstr), (yylsp[(3) - (3)])); }
     break;
 
   case 93:
-/* Line 1787 of yacc.c  */
-#line 589 "parse-gram.y"
+/* Line 1788 of yacc.c  */
+#line 590 "parse-gram.y"
     { (yyval.named_ref) = 0; }
     break;
 
   case 94:
-/* Line 1787 of yacc.c  */
-#line 591 "parse-gram.y"
+/* Line 1788 of yacc.c  */
+#line 592 "parse-gram.y"
     { (yyval.named_ref) = named_ref_new((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 96:
-/* Line 1787 of yacc.c  */
-#line 603 "parse-gram.y"
+/* Line 1788 of yacc.c  */
+#line 604 "parse-gram.y"
     { (yyval.uniqstr) = uniqstr_new ((yyvsp[(1) - (1)].chars)); }
     break;
 
   case 97:
-/* Line 1787 of yacc.c  */
-#line 608 "parse-gram.y"
+/* Line 1788 of yacc.c  */
+#line 609 "parse-gram.y"
     { (yyval.chars) = ""; }
     break;
 
   case 98:
-/* Line 1787 of yacc.c  */
-#line 609 "parse-gram.y"
+/* Line 1788 of yacc.c  */
+#line 610 "parse-gram.y"
     { (yyval.chars) = (yyvsp[(1) - (1)].uniqstr); }
     break;
 
   case 100:
-/* Line 1787 of yacc.c  */
-#line 620 "parse-gram.y"
+/* Line 1788 of yacc.c  */
+#line 621 "parse-gram.y"
     {
       code_props plain_code;
       (yyvsp[(1) - (1)].code)[strlen ((yyvsp[(1) - (1)].code)) - 1] = '\n';
@@ -2819,14 +2818,14 @@ yyreduce:
     break;
 
   case 101:
-/* Line 1787 of yacc.c  */
-#line 640 "parse-gram.y"
+/* Line 1788 of yacc.c  */
+#line 641 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 102:
-/* Line 1787 of yacc.c  */
-#line 642 "parse-gram.y"
+/* Line 1788 of yacc.c  */
+#line 643 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[(1) - (1)].character)), (yylsp[(1) - (1)]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[(1) - (1)]), false);
@@ -2835,14 +2834,14 @@ yyreduce:
     break;
 
   case 103:
-/* Line 1787 of yacc.c  */
-#line 650 "parse-gram.y"
+/* Line 1788 of yacc.c  */
+#line 651 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 106:
-/* Line 1787 of yacc.c  */
-#line 662 "parse-gram.y"
+/* Line 1788 of yacc.c  */
+#line 663 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[(1) - (1)].chars)), (yylsp[(1) - (1)]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[(1) - (1)]), false);
@@ -2850,8 +2849,8 @@ yyreduce:
     break;
 
   case 108:
-/* Line 1787 of yacc.c  */
-#line 671 "parse-gram.y"
+/* Line 1788 of yacc.c  */
+#line 672 "parse-gram.y"
     {
       code_props plain_code;
       code_props_plain_init (&plain_code, (yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)]));
@@ -2863,7 +2862,7 @@ yyreduce:
     break;
 
 
-/* Line 1787 of yacc.c  */
+/* Line 1788 of yacc.c  */
 #line 2867 "parse-gram.c"
         default: break;
       }
@@ -3112,8 +3111,8 @@ yyreturn:
 }
 
 
-/* Line 2048 of yacc.c  */
-#line 681 "parse-gram.y"
+/* Line 2049 of yacc.c  */
+#line 682 "parse-gram.y"
 
 
 
